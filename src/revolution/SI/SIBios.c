#include <revolution/OS.h>
#include <revolution/SI.h>
#include <revolution/VI.h>
#include <string.h>

typedef enum {
    SI_ERROR_NOREP = (1 << 3),
    SI_ERROR_BUSY = (1 << 7),
    SI_WIRELESS_LITE = (1 << 18),
    SI_WIRELESS_CONT = (1 << 19),
} SIStatus;

typedef struct SIMain {
    s32 chan;            // at 0x0
    u32 poll;            // at 0x4
    u32 inSize;          // at 0x8
    void* inAddr;        // at 0xC
    SICallback callback; // at 0x10
} SIMain;

typedef struct SIPacket {
    s32 chan;            // at 0x0
    void* outAddr;       // at 0x4
    u32 outSize;         // at 0x8
    void* inAddr;        // at 0xC
    u32 inSize;          // at 0x10
    SICallback callback; // at 0x14
    s64 fire;            // at 0x18
} SIPacket;

/* REXE01 interrupt callbacks receive the interrupted context. The public
 * header currently models the older two-argument ABI; passing the third PPC
 * argument remains compatible with existing two-argument callbacks. */
typedef void (*SIContextCallback)(s32 chan, u32 status, OSContext* context);

/* .data */
char lbl_803115E8[] =
    "<< RVL_SDK - SI \trelease build: Sep  7 2006 07:20:53 (0x4200_60422) >>";

/* SI driver main state (the SDK's `Si` context). */
static SIMain Si_80311630 = {SI_CHAN_NONE};
static u32 Type[SI_MAX_CHAN] = {SI_ERROR_NOREP, SI_ERROR_NOREP, SI_ERROR_NOREP,
                                SI_ERROR_NOREP};

/* .bss */
static SIPacket Packet[SI_MAX_CHAN] = {0};
static s64 XferTime[SI_MAX_CHAN];
static s64 TypeTime[SI_MAX_CHAN];
static OSAlarm Alarm[SI_MAX_CHAN];
static u32 InputBuffer[SI_MAX_CHAN][2];
static BOOL InputBufferValid[SI_MAX_CHAN];
static u32 InputBufferVcount[SI_MAX_CHAN];
static OSInterruptHandler RDSTHandler[SI_MAX_CHAN];
static SICallback TypeCallback[SI_MAX_CHAN][SI_MAX_TYPE];

/* .sdata */
const char* __SIVersion = lbl_803115E8;

/* .sbss */
u32 lbl_8055DB20;
u32 lbl_8055DB2C;

static void GetTypeCallback(s32 chan, u32 status);
static BOOL __SITransfer(s32 chan, void* outAddr, u32 outSize, void* inAddr,
                         u32 inSize, SICallback callback);

static BOOL SIIsChanBusy(s32 chan) {
    return Packet[chan].chan != SI_CHAN_NONE || Si_80311630.chan == chan;
}

static u32 SIGetStatus(s32 chan) {
    BOOL enabled;
    u32 status;

    enabled = OSDisableInterrupts();
    status = SI_HW_REGS[SI_SISR];
    status >>= (((SI_MAX_CHAN - 1) - chan) * 8);

    if (status & SI_ERROR_NOREP && !(Type[chan] & SI_ERROR_BUSY)) {
        Type[chan] = SI_ERROR_NOREP;
    }

    OSRestoreInterrupts(enabled);
    return status;
}

static BOOL SIGetResponseRaw(s32 chan) {
    u32 status = SIGetStatus(chan);

    if (status & 0x20) {
        InputBuffer[chan][0] = SI_HW_REGS[chan * 3 + 1];
        InputBuffer[chan][1] = SI_HW_REGS[chan * 3 + 2];
        InputBufferValid[chan] = TRUE;
        return TRUE;
    }

    return FALSE;
}

static void SIClearTCInterrupt(void) {
    u32 csr = SI_HW_REGS[SI_SICOMSCR];

    csr |= SI_SICOMCSR_TCINT;
    csr &= ~SI_SICOMCSR_TSTART;

    SI_HW_REGS[SI_SICOMSCR] = csr;
}

/* Finish the SI transfer the hardware has just completed.
 *
 * Copies the response out of the SI communication RAM into the transfer's
 * input buffer - whole words first, then the 1-3 valid bytes of the last word
 * (the hardware always returns a full word, most significant byte first) -
 * and stamps XferTime so the next transfer to this channel can be scheduled
 * from it. On a communication error the channel's flag byte in SISR is
 * reduced to a single SI error code (SI_COLL when COMERR was raised without
 * any specific flag); otherwise TypeTime is refreshed and 0 is returned.
 * The main context is left idle. Called by SIInterruptHandler on a
 * transfer-complete interrupt, which passes the result to the callback.
 */
static u32 CompleteTransfer(void) {
    u32 i;
    u32 status;
    u8* dst;
    u32 size;
    u32 word;

    status = SI_HW_REGS[SI_SISR];
    SIClearTCInterrupt();

    if (Si_80311630.chan != SI_CHAN_NONE) {
        XferTime[Si_80311630.chan] = __OSGetSystemTime();

        dst = (u8*)Si_80311630.inAddr;

        /* whole words straight out of the communication RAM */
        size = Si_80311630.inSize / sizeof(u32);
        for (i = 0; i < size; dst += sizeof(u32), i++) {
            *(u32*)dst = SI_HW_REGS[SI_RAM_BASE + i];
        }

        /* the tail: the last word's remaining bytes */
        size = Si_80311630.inSize % sizeof(u32);
        if (size > 0) {
            word = SI_HW_REGS[SI_RAM_BASE + i];

            for (i = 0; i < size; dst++, i++) {
                *dst = word >> (3 - i) * 8;
            }
        }

        if (SI_HW_REGS[SI_SICOMSCR] & SI_SICOMCSR_COMERR) {
            // SISR holds one flag byte per channel: bring ours down
            status >>= ((SI_MAX_CHAN - 1) - Si_80311630.chan) * 8;
            status &= (SI_UNRUN | SI_OVRUN | SI_COLL | SI_NOREP);

            if ((status & SI_NOREP) && (Type[Si_80311630.chan] & SI_ERROR_BUSY) == 0) {
                Type[Si_80311630.chan] = SI_ERROR_NOREP;
            }

            /* a communication error with no flag of its own is a collision */
            if (status == 0) {
                status = SI_COLL;
            }
        } else {
            TypeTime[Si_80311630.chan] = __OSGetSystemTime();
            status = 0;
        }

        Si_80311630.chan = SI_CHAN_NONE;
    }

    return status;
}

static void SITransferNext(s32 chan) {
    s32 i;

    for (i = 0; i < SI_MAX_CHAN; i++) {
        SIPacket* packet;

        ++chan;
        chan %= SI_MAX_CHAN;
        packet = &Packet[chan];

        if (packet->chan != SI_CHAN_NONE &&
            packet->fire <= __OSGetSystemTime()) {
            if (__SITransfer(packet->chan, packet->outAddr, packet->outSize,
                             packet->inAddr, packet->inSize,
                             packet->callback)) {
                OSCancelAlarm(&Alarm[chan]);
                packet->chan = SI_CHAN_NONE;
            }
            break;
        }
    }
}

/* SI interrupt handler. On a transfer-complete interrupt it finishes the
 * pending transfer, starts the next queued one, calls the completed channel's
 * callback and clears its error status; on a poll interrupt it discards stale
 * input buffers and dispatches the registered polling handlers. */
static void SIInterruptHandler(s16 intr, OSContext* ctx) {
    u32 csr = SI_HW_REGS[SI_SICOMSCR];

    if ((csr & (SI_SICOMCSR_TCINT | SI_SICOMCSR_TCINTMSK)) ==
        (SI_SICOMCSR_TCINT | SI_SICOMCSR_TCINTMSK)) {
        s32 chan = Si_80311630.chan;
        u32 status = CompleteTransfer();
        SICallback callback = Si_80311630.callback;
        u32 sr;

        Si_80311630.callback = NULL;
        SITransferNext(chan);
        if (callback != NULL) {
            ((SIContextCallback)callback)(chan, status, ctx);
        }

        sr = SI_HW_REGS[SI_SISR];
        sr &= (SI_SISR_UNRUN0 | SI_SISR_OVRUN0 | SI_SISR_COLL0 |
               SI_SISR_NOREP0) >> (chan * 8);
        SI_HW_REGS[SI_SISR] = sr;

        if (Type[chan] == SI_ERROR_BUSY && !SIIsChanBusy(chan)) {
            static u32 cmdTypeAndStatus;
            SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3,
                       GetTypeCallback, OS_USEC_TO_TICKS(65));
        }
    }

    if ((csr & (SI_SICOMCSR_RDSTINT | SI_SICOMCSR_RDSTINTMSK)) ==
        (SI_SICOMCSR_RDSTINT | SI_SICOMCSR_RDSTINTMSK)) {
        s32 chan;
        u32 vcount = VIGetCurrentLine() + 1;
        u32 pollX = (Si_80311630.poll & SI_SIPOLL_X) >> 16;

        for (chan = 0; chan < SI_MAX_CHAN; chan++) {
            if (SIGetResponseRaw(chan)) {
                InputBufferVcount[chan] = vcount;
            }
        }

        for (chan = 0; chan < SI_MAX_CHAN; chan++) {
            u32 pollMask = 0x80000000 >> (chan + 24);
            u32 lastVcount;

            if (!(Si_80311630.poll & pollMask)) {
                continue;
            }
            lastVcount = *(volatile u32*)&InputBufferVcount[chan];
            if (lastVcount == 0 ||
                *(volatile u32*)&InputBufferVcount[chan] + pollX / 2 < vcount) {
                return;
            }
        }

        {
            u32 zero = 0;
            volatile u32* clear = (volatile u32*)(u32)InputBufferVcount;

            clear[0] = zero;
            clear[1] = zero;
            clear[2] = zero;
            clear[3] = zero;
        }

        for (chan = 0; chan < SI_MAX_CHAN; chan++) {
            if (RDSTHandler[chan] != NULL) {
                RDSTHandler[chan](intr, ctx);
            }
        }
    }
}

#pragma dont_inline on
BOOL SIEnablePollingInterrupt(BOOL enable) {
    BOOL enabled;
    BOOL old;
    u32* vcount;
    u32 csr;

    enabled = OSDisableInterrupts();
    csr = SI_HW_REGS[SI_SICOMSCR];
    old = (csr >> 27) & 1;
    if (enable) {
        vcount = InputBufferVcount;
        *vcount++ = 0;
        *vcount++ = 0;
        *vcount++ = 0;
        *vcount = 0;
        csr |= SI_SICOMCSR_RDSTINTMSK;
    } else {
        csr &= ~SI_SICOMCSR_RDSTINTMSK;
    }
    SI_HW_REGS[SI_SICOMSCR] = csr & ~(SI_SICOMCSR_TCINT | SI_SICOMCSR_TSTART);
    OSRestoreInterrupts(enabled);
    return old;
}
#pragma dont_inline off

/* Remove a handler from the SI RDST polling table; disable polling interrupt if none remain. */
BOOL SIUnregisterPollingHandler(OSInterruptHandler handler) {
    BOOL enabled;
    s32 i;
    s32 j;

    enabled = OSDisableInterrupts();
    for (i = 0; i < SI_MAX_CHAN; i++) {
        if (RDSTHandler[i] == handler) {
            RDSTHandler[i] = NULL;
            for (j = 0; j < SI_MAX_CHAN; j++) {
                if (RDSTHandler[j] != NULL) {
                    break;
                }
            }
            if (j == SI_MAX_CHAN) {
                SIEnablePollingInterrupt(FALSE);
            }
            OSRestoreInterrupts(enabled);
            return TRUE;
        }
    }
    OSRestoreInterrupts(enabled);
    return FALSE;
}

void SIInit(void) {
    /* Initialize the serial interface once: reset state, configure interrupts, and probe device types. */
    static BOOL Initialized = FALSE;

    if (Initialized) {
        return;
    }

    OSRegisterVersion(__SIVersion);

    Packet[SI_CHAN_0].chan = Packet[SI_CHAN_1].chan = Packet[SI_CHAN_2].chan =
        Packet[SI_CHAN_3].chan = SI_CHAN_NONE;

    Si_80311630.poll = 0;
    SISetSamplingRate(0);

    while (SI_HW_REGS[SI_SICOMSCR] & SI_SICOMCSR_TSTART) {
        ;
    }

    SI_HW_REGS[SI_SICOMSCR] = SI_SICOMCSR_TCINT;

    __OSSetInterruptHandler(OS_INTR_PI_SI, SIInterruptHandler);
    __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_PI_SI));

    SIGetType(SI_CHAN_0);
    SIGetType(SI_CHAN_1);
    SIGetType(SI_CHAN_2);
    SIGetType(SI_CHAN_3);

    Initialized = TRUE;
}

/* Start a Serial Interface transfer on a channel: clear status, latch callback/buffer
 * state, copy output words to SI RAM, and program SICOMSCR to begin the transfer.
 */
static BOOL __SITransfer(s32 chan, void* outAddr, u32 outSize, void* inAddr,
                         u32 inSize, SICallback callback) {
    BOOL enabled;
    u32 sr;
    u32 alignSize;
    u32 i;

    union {
        struct {
            u32 TCINT : 1;
            u32 TCINTMSK : 1;
            u32 COMERR : 1;
            u32 RDSTINT : 1;
            u32 RDSTINTMSK : 1;
            u32 reserved2 : 4;
            u32 OUTLNGTH : 7;
            u32 reserved1 : 1;
            u32 INLNGTH : 7;
            u32 reserved0 : 5;
            u32 CHANNEL : 2;
            u32 TSTART : 1;
        };

        u32 reg;
    } comscr;

    enabled = OSDisableInterrupts();

    if (Si_80311630.chan != SI_CHAN_NONE) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    sr = SI_HW_REGS[SI_SISR];
    sr &= (SI_SISR_UNRUN0 | SI_SISR_OVRUN0 | SI_SISR_COLL0 | SI_SISR_NOREP0) >>
          (chan * 8);
    SI_HW_REGS[SI_SISR] = sr;

    Si_80311630.chan = chan;
    Si_80311630.callback = callback;
    Si_80311630.inSize = inSize;
    Si_80311630.inAddr = inAddr;

    alignSize = (outSize + 3) / 4;
    for (i = 0; i < alignSize; i++) {
        SI_HW_REGS[SI_RAM_BASE + i] = ((u32*)outAddr)[i];
    }

    comscr.reg = SI_HW_REGS[SI_SICOMSCR];

    comscr.TCINT = TRUE;
    comscr.TCINTMSK = callback != NULL;
    // Minimum transfer is 1 byte. 0x00 will transfer 128 bytes
    comscr.OUTLNGTH = outSize == 128 ? 0 : outSize;
    comscr.INLNGTH = inSize == 128 ? 0 : inSize;
    comscr.CHANNEL = chan;
    comscr.TSTART = TRUE;

    SI_HW_REGS[SI_SICOMSCR] = comscr.reg;

    OSRestoreInterrupts(enabled);
    return TRUE;
}

#pragma dont_inline on
void fn_80057F2C(s32 param_0, u32 param_1) {
    SI_HW_REGS[param_0 * 3] = param_1;
}
#pragma dont_inline reset

u32 SISetXY(u32 lines, u32 times) {
    BOOL enabled;
    u32 poll;

    poll = lines << 16;
    poll |= times << 8;

    enabled = OSDisableInterrupts();

    Si_80311630.poll &= ~(SI_SIPOLL_X | SI_SIPOLL_Y);
    Si_80311630.poll |= poll;

    poll = Si_80311630.poll;
    SI_HW_REGS[SI_SIPOLL] = poll;

    OSRestoreInterrupts(enabled);
    return poll;
}

static void AlarmHandler(OSAlarm* alarm, OSContext* ctx) {
    s32 chan;
    SIPacket* packet;

    chan = alarm - Alarm;
    packet = &Packet[chan];

    if (packet->chan != SI_CHAN_NONE) {
        if (__SITransfer(packet->chan, packet->outAddr, packet->outSize,
                         packet->inAddr, packet->inSize, packet->callback)) {
            packet->chan = SI_CHAN_NONE;
        }
    }
}

/* Queue a Serial Interface transfer on a channel now or at a scheduled fire time, updating the pending packet state. */
BOOL SITransfer(s32 chan, void* outAddr, u32 outSize, void* inAddr, u32 inSize,
                SICallback callback, s64 wait) {
    BOOL interrupts;
    SIPacket* req;
    s64 now;
    s64 deadline;

    req = &Packet[chan];
    interrupts = OSDisableInterrupts();

    if (req->chan != SI_CHAN_NONE || Si_80311630.chan == chan) {
        OSRestoreInterrupts(interrupts);
        return FALSE;
    }

    now = __OSGetSystemTime();
    if (wait == 0) {
        deadline = now;
    } else {
        deadline = wait + XferTime[chan];
    }

    if (now < deadline) {
        OSSetAlarm(&Alarm[chan], deadline - now, AlarmHandler);
    } else if (__SITransfer(chan, outAddr, outSize, inAddr, inSize, callback)) {
        OSRestoreInterrupts(interrupts);
        return TRUE;
    }

    req->chan = chan;
    req->outAddr = outAddr;
    req->outSize = outSize;
    req->inAddr = inAddr;
    req->inSize = inSize;
    req->callback = callback;
    req->fire = deadline;

    OSRestoreInterrupts(interrupts);
    return TRUE;
}

/**
 * SI transfer callback for the "type and status" command that SIGetType and
 * SIGetTypeAsync queue on a channel.
 *
 * Merges the reply into the channel's cached Type[] (clearing SI_ERROR_BUSY),
 * stamps when it arrived and clears the channel's bit in the PAD driver's
 * __PADFixBits. For a usable GameCube-protocol wireless receiver it then
 * brings the ID held by the receiver and the one stored in the RTC into
 * agreement: whichever side has no ID adopts the other's, and a receiver that
 * has to be programmed gets an SI_CMD_SET_WIRELESS transfer queued, which
 * re-enters this callback. Any other device loses its stored ID. Finally the
 * callbacks SIGetTypeAsync left pending for the channel are each run once and
 * removed from the list.
 */
static void GetTypeCallback(s32 chan, u32 status) {
    static u32 cmdFixDevice[SI_MAX_CHAN];
    u32 type;
    u32 chanBit;
    BOOL fix;
    u32 wirelessId;
    s32 i;
    SICallback* callbacks;
    SICallback cb;

    Type[chan] &= ~SI_ERROR_BUSY;
    Type[chan] |= status;
    TypeTime[chan] = __OSGetSystemTime();
    type = Type[chan];
    chanBit = 0x80000000 >> chan;
    fix = lbl_8055DB2C & chanBit;
    lbl_8055DB2C &= ~chanBit;

    /* Error, or no device we can talk to: drop the channel's stored ID. */
    if ((status & SI_STATUS_ERROR_MASK) ||
        (type & SI_TYPE_MASK) != SI_TYPE_GC || !(type & SI_TYPE_GC_WIRELESS) ||
        (type & SI_TYPE_GC_FAULT)) {
        OSSetWirelessID(chan, 0);
        type = Type[chan];
        callbacks = TypeCallback[chan];
        for (i = 0; i < SI_MAX_TYPE; i++, callbacks++) {
            cb = *callbacks;
            if (cb != NULL) {
                *callbacks = NULL;
                cb(chan, type);
            }
        }
        return;
    } else {
        wirelessId = OSGetWirelessID(chan) << SI_WIRELESS_ID_SHIFT;
        /* The PAD driver asked for this channel to be re-activated. */
        if (fix && (wirelessId & SI_WIRELESS_SET)) {
            cmdFixDevice[chan] = (SI_CMD_SET_WIRELESS << 24) |
                                 (wirelessId & SI_WIRELESS_ID_MASK) |
                                 SI_WIRELESS_SET;
            Type[chan] = SI_ERROR_BUSY;
            SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3,
                       GetTypeCallback, 0);
            return;
        }
        if (type & SI_WIRELESS_SET) {
            /* Receiver has an ID; make it and the RTC agree on one. */
            if ((wirelessId & SI_WIRELESS_ID_MASK) !=
                (type & SI_WIRELESS_ID_MASK)) {
                if (!(wirelessId & SI_WIRELESS_SET)) {
                    wirelessId = (type & SI_WIRELESS_ID_MASK) | SI_WIRELESS_SET;
                    OSSetWirelessID(chan, (u16)(wirelessId >>
                                                SI_WIRELESS_ID_SHIFT));
                }
                cmdFixDevice[chan] = (SI_CMD_SET_WIRELESS << 24) | wirelessId;
                Type[chan] = SI_ERROR_BUSY;
                SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3,
                           GetTypeCallback, 0);
                return;
            }
        } else if (type & SI_TYPE_GC_ID_REQUEST) {
            /* Receiver has no ID: adopt the one it asked for. */
            wirelessId = type & SI_WIRELESS_ID_MASK;
            wirelessId |= SI_WIRELESS_SET;
            OSSetWirelessID(chan, (u16)(wirelessId >> SI_WIRELESS_ID_SHIFT));
            cmdFixDevice[chan] = (SI_CMD_SET_WIRELESS << 24) | wirelessId;
            Type[chan] = SI_ERROR_BUSY;
            SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3,
                       GetTypeCallback, 0);
            return;
        } else {
            OSSetWirelessID(chan, 0);
        }
    }
    type = Type[chan];
    {
        SICallback* pending = TypeCallback[chan];
        for (i = 0; i < SI_MAX_TYPE; i++, pending++) {
            cb = *pending;
            if (cb != NULL) {
                *pending = NULL;
                cb(chan, type);
            }
        }
    }
}

/* Returns the cached controller type for a channel, refreshing it over SI if the cached value is stale or polling is active. */
u32 SIGetType(s32 chan) {
    static u32 cmdTypeAndStatus;
    BOOL enabled;
    u32 type;
    s64 diff;

    enabled = OSDisableInterrupts();
    type = Type[chan];
    diff = __OSGetSystemTime() - TypeTime[chan];

    if (Si_80311630.poll & (0x80 >> chan)) {
        if (type != SI_ERROR_NOREP) {
            TypeTime[chan] = __OSGetSystemTime();
            OSRestoreInterrupts(enabled);
            return type;
        }
        type = Type[chan] = SI_ERROR_BUSY;
    } else if (diff <= OS_MSEC_TO_TICKS(50) && type != SI_ERROR_NOREP) {
        OSRestoreInterrupts(enabled);
        return type;
    } else if (diff <= OS_MSEC_TO_TICKS(75)) {
        Type[chan] = SI_ERROR_BUSY;
    } else {
        type = Type[chan] = SI_ERROR_BUSY;
    }

    TypeTime[chan] = __OSGetSystemTime();
    SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3, GetTypeCallback,
               OS_USEC_TO_TICKS(65));
    OSRestoreInterrupts(enabled);
    return type;
}

#pragma dont_inline on
u32 SIEnablePolling(u32 chan) {
    BOOL enabled;
    u32 poll;
    u32 mask;

    if (chan == 0) {
        return Si_80311630.poll;
    }
    enabled = OSDisableInterrupts();
    chan >>= 24;
    mask = (chan >> 4) & 0xF;
    chan &= mask | 0x03FFFFF0;
    Si_80311630.poll &= ~mask;
    Si_80311630.poll |= chan;
    poll = Si_80311630.poll;
    SI_HW_REGS[SI_SISR] = SI_SISR_WR;
    SI_HW_REGS[SI_SIPOLL] = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}
#pragma dont_inline reset
#pragma dont_inline on
u32 SIDisablePolling(u32 chan) {
    BOOL enabled;
    u32 poll;

    if (chan == 0) {
        return Si_80311630.poll;
    }
    enabled = OSDisableInterrupts();
    poll = Si_80311630.poll & ~((chan >> 24) & 0xF0);
    SI_HW_REGS[SI_SIPOLL] = poll;
    Si_80311630.poll = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}

BOOL SIGetResponse(s32 chan, void* data) {
    BOOL enabled;
    BOOL valid;
    u32 status;

    /* Reads a serial interface response for a channel into data when available. */
    enabled = OSDisableInterrupts();
    {
        BOOL statusEnabled = OSDisableInterrupts();
        status = SI_HW_REGS[SI_SISR];
        status >>= (((SI_MAX_CHAN - 1) - chan) * 8);
        if (status & SI_ERROR_NOREP && !(Type[chan] & SI_ERROR_BUSY)) {
            Type[chan] = SI_ERROR_NOREP;
        }
        OSRestoreInterrupts(statusEnabled);
    }
    if (status & SI_RDST) {
        InputBuffer[chan][0] = SI_HW_REGS[chan * 3 + 1];
        InputBuffer[chan][1] = SI_HW_REGS[chan * 3 + 2];
        InputBufferValid[chan] = TRUE;
    }
    valid = InputBufferValid[chan];
    InputBufferValid[chan] = FALSE;
    if (valid) {
        ((u32*)data)[0] = InputBuffer[chan][0];
        ((u32*)data)[1] = InputBuffer[chan][1];
    }
    OSRestoreInterrupts(enabled);
    return valid;
}

#pragma dont_inline reset

/**
 * Get the controller type for a SI channel asynchronously.
 *
 * If the channel's type is currently being determined (SI_ERROR_BUSY set),
 * queue the callback to be invoked when type detection completes. If there is
 * already a pending slot for this callback or a free slot is found, it is
 * stored; otherwise the callback is not queued. If the type is already known,
 * invoke the callback immediately with the current type.
 *
 * Returns the current type value for the channel.
 */
u32 SIGetTypeAsync(s32 chan, SICallback callback) {
    BOOL enabled;
    u32 type;
    s32 i;

    enabled = OSDisableInterrupts();
    type = SIGetType(chan);

    if (Type[chan] & SI_ERROR_BUSY) {
        for (i = 0; i < SI_MAX_TYPE; i++) {
            if (TypeCallback[chan][i] == callback) {
                break;
            }
            if (TypeCallback[chan][i] == NULL) {
                TypeCallback[chan][i] = callback;
                break;
            }
        }
    } else {
        callback(chan, type);
    }

    OSRestoreInterrupts(enabled);
    return type;
}
