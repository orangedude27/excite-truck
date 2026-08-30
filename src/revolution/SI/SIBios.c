#include <revolution/OS.h>
#include <revolution/SI.h>
#include <revolution/VI.h>

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

const char* __SIVersion =
    "<< RVL_SDK - SI \trelease build: Nov 30 2006 03:31:44 (0x4199_60831) >>";

static SIMain Si = {SI_CHAN_NONE};
static u32 Type[SI_MAX_CHAN] = {SI_ERROR_NOREP, SI_ERROR_NOREP, SI_ERROR_NOREP,
                                SI_ERROR_NOREP};

static SIPacket Packet[SI_MAX_CHAN];
static s64 XferTime[SI_MAX_CHAN];
static s64 TypeTime[SI_MAX_CHAN];
static SICallback TypeCallback[SI_MAX_TYPE][SI_MAX_CHAN];
static BOOL InputBufferValid[SI_MAX_CHAN];
static u32 InputBuffer[SI_MAX_CHAN][2];
static OSInterruptHandler RDSTHandler[SI_MAX_CHAN];
static u32 InputBufferVcount[SI_MAX_CHAN];
extern OSAlarm Alarm[SI_MAX_CHAN];
extern u32 __PADFixBits;

static void GetTypeCallback(s32 chan, u32 status);
static BOOL __SITransfer(s32 chan, void* outAddr, u32 outSize, void* inAddr,
                         u32 inSize, SICallback callback);

static BOOL SIIsChanBusy(s32 chan) {
    return Packet[chan].chan != SI_CHAN_NONE || Si.chan == chan;
}

static u32 SIGetStatus(s32 chan) {
    BOOL enabled;
    u32 status;

    enabled = OSDisableInterrupts();
    status = SI_HW_REGS[SI_SISR] >> (((SI_MAX_CHAN - 1) - chan) * 8);

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

static u32 CompleteTransfer(void) {
    u32 i;
    u32 sr;
    u8* dst;
    u32 size;
    u32 imm;

    sr = SI_HW_REGS[SI_SISR];
    SIClearTCInterrupt();

    if (Si.chan != SI_CHAN_NONE) {
        XferTime[Si.chan] = __OSGetSystemTime();

        dst = (u8*)Si.inAddr;

        size = Si.inSize / sizeof(u32);
        for (i = 0; i < size; dst += sizeof(u32), i++) {
            *(u32*)dst = SI_HW_REGS[SI_RAM_BASE + i];
        }

        size = Si.inSize % sizeof(u32);
        if (size > 0) {
            imm = SI_HW_REGS[SI_RAM_BASE + i];

            for (i = 0; i < size; dst++, i++) {
                *dst = imm >> (3 - i) * 8;
            }
        }

        if (SI_HW_REGS[SI_SICOMSCR] & SI_SICOMCSR_COMERR) {
            // Flags relative to channel ID
            sr >>= ((SI_MAX_CHAN - 1) - Si.chan) * 8;
            sr &= (SI_UNRUN | SI_OVRUN | SI_COLL | SI_NOREP);

            if ((sr & SI_NOREP) && (Type[Si.chan] & SI_ERROR_BUSY) == 0) {
                Type[Si.chan] = SI_ERROR_NOREP;
            }

            if (sr == 0) {
                sr = SI_COLL;
            }
        } else {
            TypeTime[Si.chan] = __OSGetSystemTime();
            sr = 0;
        }

        Si.chan = SI_CHAN_NONE;
    }

    return sr;
}

static void SITransferNext(s32 chan) {
    s32 i;

    for (i = 0; i < SI_MAX_CHAN; i++) {
        SIPacket* packet;

        chan = (chan + 1) % SI_MAX_CHAN;
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

static void SIInterruptHandler(s16 intr, OSContext* ctx) {
    u32 comcsr = SI_HW_REGS[SI_SICOMSCR];

    if ((comcsr & (SI_SICOMCSR_TCINT | SI_SICOMCSR_TCINTMSK)) ==
        (SI_SICOMCSR_TCINT | SI_SICOMCSR_TCINTMSK)) {
        s32 chan = Si.chan;
        u32 status = CompleteTransfer();
        SICallback callback = Si.callback;
        u32 sr;

        Si.callback = NULL;
        SITransferNext(chan);

        if (callback != NULL) {
            ((SIContextCallback)callback)(chan, status, ctx);
        }

        sr = SI_HW_REGS[SI_SISR];
        sr &= 0x0F000000 >> (chan * 8);
        SI_HW_REGS[SI_SISR] = sr;

        if (Type[chan] == SI_ERROR_BUSY && !SIIsChanBusy(chan)) {
            static u32 cmdTypeAndStatus;
            SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3,
                       GetTypeCallback, OS_USEC_TO_TICKS(65));
        }
    }

    if ((comcsr & (SI_SICOMCSR_RDSTINT | SI_SICOMCSR_RDSTINTMSK)) ==
        (SI_SICOMCSR_RDSTINT | SI_SICOMCSR_RDSTINTMSK)) {
        u32 vcount = VIGetCurrentLine() + 1;
        u32 x = (Si.poll & SI_SIPOLL_X) >> 16;
        s32 chan;

        for (chan = 0; chan < SI_MAX_CHAN; chan++) {
            if (SIGetResponseRaw(chan)) {
                InputBufferVcount[chan] = vcount;
            }
        }

        for (chan = 0; chan < SI_MAX_CHAN; chan++) {
            if (!(Si.poll & (0x80 >> chan))) {
                continue;
            }
            if (InputBufferVcount[chan] == 0 ||
                InputBufferVcount[chan] + x / 2 < vcount) {
                return;
            }
        }

        for (chan = 0; chan < SI_MAX_CHAN; chan++) {
            InputBufferVcount[chan] = 0;
        }

        for (chan = 0; chan < SI_MAX_CHAN; chan++) {
            if (RDSTHandler[chan] != NULL) {
                RDSTHandler[chan](intr, ctx);
            }
        }
    }
}

void SIInit(void) {
    static BOOL Initialized = FALSE;

    if (Initialized) {
        return;
    }

    OSRegisterVersion(__SIVersion);

    Packet[SI_CHAN_0].chan = Packet[SI_CHAN_1].chan = Packet[SI_CHAN_2].chan =
        Packet[SI_CHAN_3].chan = SI_CHAN_NONE;

    Si.poll = 0;
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

    if (Si.chan != SI_CHAN_NONE) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    sr = SI_HW_REGS[SI_SISR];
    sr &= (SI_SISR_UNRUN0 | SI_SISR_OVRUN0 | SI_SISR_COLL0 | SI_SISR_NOREP0) >>
          (chan * 8);
    SI_HW_REGS[SI_SISR] = sr;

    Si.chan = chan;
    Si.callback = callback;
    Si.inSize = inSize;
    Si.inAddr = inAddr;

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

u32 SISetXY(u32 lines, u32 times) {
    BOOL enabled;
    u32 poll;

    poll = lines << 16;
    poll |= times << 8;

    enabled = OSDisableInterrupts();

    Si.poll &= ~(SI_SIPOLL_X | SI_SIPOLL_Y);
    Si.poll |= poll;

    poll = Si.poll;
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

BOOL SITransfer(s32 chan, void* outAddr, u32 outSize, void* inAddr, u32 inSize,
                SICallback callback, s64 wait) {
    SIPacket* packet;
    BOOL enabled;
    s64 start;
    s64 fire;

    packet = &Packet[chan];
    enabled = OSDisableInterrupts();

    if (packet->chan != SI_CHAN_NONE || Si.chan == packet->chan) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    start = __OSGetSystemTime();
    fire = wait == 0 ? start : wait + XferTime[chan];

    if (start < fire) {
        OSSetAlarm(&Alarm[chan], fire - start, AlarmHandler);
    } else if (__SITransfer(chan, outAddr, outSize, inAddr, inSize, callback)) {
        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    packet->chan = chan;
    packet->outAddr = outAddr;
    packet->outSize = outSize;
    packet->inAddr = inAddr;
    packet->inSize = inSize;
    packet->callback = callback;
    packet->fire = fire;

    OSRestoreInterrupts(enabled);
    return TRUE;
}

static void GetTypeCallback(s32 chan, u32 status) {
    static u32 cmdFixDevice[SI_MAX_CHAN];
    u32 type;
    u32 chanBit;
    BOOL fix;
    u32 id;
    s32 i;

    Type[chan] &= ~SI_ERROR_BUSY;
    Type[chan] |= status;
    TypeTime[chan] = __OSGetSystemTime();
    type = Type[chan];
    chanBit = 0x80000000 >> chan;
    fix = __PADFixBits & chanBit;
    __PADFixBits &= ~chanBit;

    if ((status & 0xF) || (type & 0x18000000) != 0x08000000 ||
        !(type & 0x80000000) || (type & 0x04000000)) {
        OSSetWirelessID(chan, 0);
    } else {
        id = OSGetWirelessID(chan) << 8;

        if (fix && (id & 0x00100000)) {
            cmdFixDevice[chan] =
                (0x4E << 24) | (id & 0x00CFFF00) | 0x4E100000;
            Type[chan] = SI_ERROR_BUSY;
            SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3,
                       GetTypeCallback, 0);
            return;
        }

        if (type & 0x00100000) {
            if ((id & 0x00CFFF00) != (type & 0x00CFFF00)) {
                if (!(id & 0x00100000)) {
                    id = (type & 0x00CFFF00) | 0x00100000;
                    OSSetWirelessID(chan, (u16)(id >> 8));
                }

                cmdFixDevice[chan] = (0x4E << 24) | id;
                Type[chan] = SI_ERROR_BUSY;
                SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3,
                           GetTypeCallback, 0);
                return;
            }
        } else if (type & 0x40000000) {
            id = (type & 0x00CFFF00) | 0x00100000;
            OSSetWirelessID(chan, (u16)(id >> 8));
            cmdFixDevice[chan] = (0x4E << 24) | id;
            Type[chan] = SI_ERROR_BUSY;
            SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3,
                       GetTypeCallback, 0);
            return;
        } else {
            OSSetWirelessID(chan, 0);
        }
    }

    for (i = 0; i < SI_MAX_TYPE; i++) {
        SICallback callback = TypeCallback[chan][i];
        if (callback != NULL) {
            TypeCallback[chan][i] = NULL;
            callback(chan, Type[chan]);
        }
    }
}

u32 SIGetType(s32 chan) {
    static u32 cmdTypeAndStatus;
    BOOL enabled;
    u32 type;
    s64 diff;

    enabled = OSDisableInterrupts();
    type = Type[chan];
    diff = __OSGetSystemTime() - TypeTime[chan];

    if (Si.poll & (0x80 >> chan)) {
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
