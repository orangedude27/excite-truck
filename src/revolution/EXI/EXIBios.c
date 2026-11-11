#include <revolution/DVD.h>
#include <revolution/EXI.h>
#include <revolution/OS.h>

#include <string.h>

const char* __EXIVersion =
    "<< RVL_SDK - EXI \trelease build: Sep  7 2006 07:16:20 (0x4200_60422) >>";

// One state block per EXI channel.
static EXIData Ecb[EXI_MAX_CHAN];
// ID of the serial port 1 device, cached by EXIInit() before anything else can
// claim the channel; EXIGetID() answers channel 0's internal device with it.
static u32 IDSerialPort1;

static BOOL __EXIProbe(EXIChannel chan);

static void SetExiInterruptMask(EXIChannel chan, EXIData* exi) {
    EXIData* exi2 = &Ecb[EXI_CHAN_2];

    switch (chan) {
    case EXI_CHAN_0: {
        if (exi->exiCallback == NULL && exi2->exiCallback == NULL ||
            exi->state & EXI_STATE_LOCKED) {
            __OSMaskInterrupts(OS_INTR_MASK(OS_INTR_EXI_0_EXI) |
                               OS_INTR_MASK(OS_INTR_EXI_2_EXI));
        } else {
            __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_EXI_0_EXI) |
                                 OS_INTR_MASK(OS_INTR_EXI_2_EXI));
        }
        break;
    }

    case EXI_CHAN_1: {
        if (exi->exiCallback == NULL || exi->state & EXI_STATE_LOCKED) {
            __OSMaskInterrupts(OS_INTR_MASK(OS_INTR_EXI_1_EXI));
        } else {
            __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_EXI_1_EXI));
        }
        break;
    }

    case EXI_CHAN_2: {
        if (__OSGetInterruptHandler(OS_INTR_PI_DEBUG) == NULL ||
            exi->state & EXI_STATE_LOCKED) {
            __OSMaskInterrupts(OS_INTR_MASK(OS_INTR_PI_DEBUG));
        } else {
            __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_PI_DEBUG));
        }
        break;
    }

    default: {
        break;
    }
    }
}

static void CompleteTransfer(EXIChannel chan) {
    EXIData* exi = &Ecb[chan];
    s32 len;

    if (exi->state & EXI_STATE_BUSY) {
        if (exi->state & EXI_STATE_IMM_ACCESS && (len = exi->bytesRead) != 0) {
            u8* buf;
            u32 data;
            int i;

            buf = (u8*)exi->buffer;
            data = EXI_CHAN_PARAMS[chan].data;
            for (i = 0; i < len; i++) {
                *buf++ = data >> (3 - i) * 8;
            }
        }

        exi->state &= ~EXI_STATE_BUSY;
    }
}

/* Start one immediate (byte-wise) EXI transfer on a selected channel: up to four
 * bytes travel in the channel's data register, so a write is packed here and a
 * read is unpacked by CompleteTransfer() when the transfer completes.  With a
 * callback the transfer is asynchronous and answers through it; without one the
 * caller waits with EXISync().  FALSE means the channel was busy or not selected. */
BOOL EXIImm(EXIChannel chan, void* buf, s32 len, u32 type,
            EXICallback callback) {
    EXIData* exi = &Ecb[chan];
    BOOL enabled = OSDisableInterrupts();

    // busy, or no device selected to transfer with
    if (exi->state & EXI_STATE_BUSY || !(exi->state & EXI_STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    exi->tcCallback = callback;
    if (callback != NULL) {
        // the channel's transfer-complete interrupt; the OS mask holds the three
        // interrupts (EXI, TC, EXT) of a channel three bits apart
        u32 tcIntrMask = OS_INTR_MASK(OS_INTR_EXI_0_TC);
        // acknowledge any pending transfer-complete interrupt and arm it again
        EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
        __OSUnmaskInterrupts(tcIntrMask >> (chan * 3));
    }

    exi->state |= EXI_STATE_IMM_ACCESS;

    if (type != EXI_READ) {
        // pack the bytes into the data register, the first one most significant
        int i;
        u32 word = 0;
        for (i = 0; i < len; i++) {
            word |= ((u8*)buf)[i] << (3 - i) * 8;
        }

        EXI_CHAN_PARAMS[chan].data = word;
    }

    exi->buffer = buf;
    // only a read brings bytes back for CompleteTransfer() to store
    exi->bytesRead = (type != EXI_WRITE) ? len : 0;
    EXI_CHAN_PARAMS[chan].cr = EXI_CR_TSTART | type << EXI_CR_TYPE_SHIFT |
                               (len - 1) << EXI_CR_LEN_SHIFT;

    OSRestoreInterrupts(enabled);
    return TRUE;
}

BOOL EXIImmEx(EXIChannel chan, void* buf, s32 len, u32 type) {
    while (len != 0) {
        s32 immLen = (len < 4) ? len : 4;

        if (!EXIImm(chan, buf, immLen, type, NULL)) {
            return FALSE;
        }

        if (!EXISync(chan)) {
            return FALSE;
        }

        buf = (u8*)buf + immLen;
        len -= immLen;
    }

    return TRUE;
}

BOOL EXIDma(EXIChannel chan, void* buf, s32 len, u32 type,
            EXICallback callback) {
    EXIData* exi = &Ecb[chan];
    BOOL enabled = OSDisableInterrupts();

    if (exi->state & EXI_STATE_BUSY || !(exi->state & EXI_STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    exi->tcCallback = callback;
    if (callback != NULL) {
        u32 mask = OS_INTR_MASK(OS_INTR_EXI_0_TC);
        EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
        __OSUnmaskInterrupts(mask >> (chan * 3));
    }

    exi->state |= EXI_STATE_DMA_ACCESS;

    EXI_CHAN_PARAMS[chan].mar = ROUND_DOWN_PTR(buf, 32);
    EXI_CHAN_PARAMS[chan].length = len;
    EXI_CHAN_PARAMS[chan].cr = type << 2 | EXI_CR_TSTART | EXI_CR_DMA;

    OSRestoreInterrupts(enabled);
    return TRUE;
}

/* Waits for the transfer started on a selected channel to come off the bus and
 * completes it: CompleteTransfer() copies an immediate read's bytes out of the
 * channel's data register into the buffer EXIImm() was given.  FALSE tells the
 * caller not to use what it read -- either the channel got deselected while
 * waiting, or this is the one transfer the SDK does not trust: a four-byte read
 * at the fastest EXI clock whose data register holds a development peripheral's
 * ID (a USB adapter, the DOL viewer or EXI_ID_04220001) on a retail unit whose
 * DVD interface config byte still reads 0xFF and whose drive is not the 0x0200
 * one.  EXIImmEx() and EXIGetID() answer that as a failed transfer. */
BOOL EXISync(EXIChannel chan) {
    EXIData* exi = &Ecb[chan];
    BOOL ret = FALSE;

    // Spin while the channel's transfer is still running; a deselected channel
    // leaves with ret still FALSE.
    while (exi->state & EXI_STATE_SELECTED) {
        if (!(EXI_CHAN_PARAMS[chan].cr & EXI_CR_TSTART)) {
            // Take the completion itself, with no interrupt handler getting in
            // between the check above and clearing the busy state.
            BOOL enabled = OSDisableInterrupts();

            if (exi->state & EXI_STATE_SELECTED) {
                CompleteTransfer(chan);

                // Workaround: only that four-byte read of a development
                // peripheral is left unreported as complete -- any other
                // transfer, a development unit, a configured DVD interface, a
                // slowed-down clock or a 0x0200 drive reports success.
                if (__OSGetDIConfig() != 0xFF ||
                    (OSGetConsoleType() & OS_CONSOLE_MASK) ==
                        OS_CONSOLE_MASK_TDEV ||
                    exi->bytesRead != 4 ||
                    EXI_CHAN_PARAMS[chan].cpr & EXI_CPR_CLK ||
                    (EXI_CHAN_PARAMS[chan].data != EXI_ID_USB_ADAPTER &&
                     EXI_CHAN_PARAMS[chan].data != EXI_ID_IS_DOL_VIEWER &&
                     EXI_CHAN_PARAMS[chan].data != EXI_ID_04220001) ||
                    OS_DVD_DEVICE_CODE == MAKE_DVD_DEVICE_CODE(0x0200)) {
                    ret = TRUE;
                }
            }

            OSRestoreInterrupts(enabled);
            break;
        }
    }

    return ret;
}

void EXIClearInterrupts(EXIChannel chan, BOOL exi, BOOL tc, BOOL ext) {
    u32 cpr = EXI_CHAN_PARAMS[chan].cpr & 0xFFF &
              ~(EXI_CPR_EXIINT | EXI_CPR_TCINT | EXI_CPR_EXTINT);

    if (exi) {
        cpr |= EXI_CPR_EXIINT;
    }

    if (tc) {
        cpr |= EXI_CPR_TCINT;
    }

    if (ext) {
        cpr |= EXI_CPR_EXTINT;
    }

    EXI_CHAN_PARAMS[chan].cpr = cpr;
}

EXICallback EXISetExiCallback(EXIChannel chan, EXICallback callback) {
    EXIData* exi;
    EXICallback old;
    BOOL enabled;

    exi = &Ecb[chan];
    enabled = OSDisableInterrupts();

    old = exi->exiCallback;
    exi->exiCallback = callback;

    if (chan != EXI_CHAN_2) {
        SetExiInterruptMask(chan, exi);
    } else {
        SetExiInterruptMask(EXI_CHAN_0, &Ecb[EXI_CHAN_0]);
    }

    OSRestoreInterrupts(enabled);
    return old;
}

void EXIProbeReset(void) {
    OS_EXI_LAST_INSERT[0] = OS_EXI_LAST_INSERT[1] = 0;
    Ecb[EXI_CHAN_0].lastInsert = Ecb[EXI_CHAN_1].lastInsert = 0;
    __EXIProbe(EXI_CHAN_0);
    __EXIProbe(EXI_CHAN_1);
}

/* Probe whether an EXI device is present on the given channel, updating last-insert timing state. */
static BOOL __EXIProbe(EXIChannel chan) {
    EXIData* exi = &Ecb[chan];
    BOOL enabled;
    BOOL ret;
    u32 cpr;

    if (chan == EXI_CHAN_2) {
        return TRUE;
    }

    ret = TRUE;
    enabled = OSDisableInterrupts();
    cpr = EXI_CHAN_PARAMS[chan].cpr;

    if (!(exi->state & EXI_STATE_ATTACHED)) {
        if (cpr & EXI_CPR_EXTINT) {
            EXIClearInterrupts(chan, FALSE, FALSE, TRUE);
            exi->lastInsert = 0;
            OS_EXI_LAST_INSERT[chan] = 0;
        }

        if (cpr & EXI_CPR_EXT) {
            s32 time = (s32)(OS_TICKS_TO_MSEC(OSGetTime()) / 100) + 1;
            if (OS_EXI_LAST_INSERT[chan] == 0) {
                OS_EXI_LAST_INSERT[chan] = time;
            }

            if (time - OS_EXI_LAST_INSERT[chan] < 3) {
                ret = FALSE;
            }
        } else {
            exi->lastInsert = 0;
            OS_EXI_LAST_INSERT[chan] = 0;
            ret = FALSE;
        }
    } else if (!(cpr & EXI_CPR_EXT) || cpr & EXI_CPR_EXTINT) {
        exi->lastInsert = 0;
        OS_EXI_LAST_INSERT[chan] = 0;
        ret = FALSE;
    }

    OSRestoreInterrupts(enabled);
    return ret;
}

BOOL EXIProbe(EXIChannel chan) {
    EXIData* exi = &Ecb[chan];

    BOOL ret = __EXIProbe(chan);
    if (ret && exi->lastInsert == 0) {
        u32 id;
        return EXIGetID(chan, EXI_DEV_EXT, &id);
    }

    return FALSE;
}

static BOOL __EXIAttach(EXIChannel chan, EXICallback callback) {
    EXIData* exi = &Ecb[chan];
    BOOL enabled;
    u32 mask;

    enabled = OSDisableInterrupts();
    if (exi->state & EXI_STATE_ATTACHED || !__EXIProbe(chan)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    EXIClearInterrupts(chan, TRUE, FALSE, FALSE);
    exi->extCallback = callback;
    mask = OS_INTR_MASK(OS_INTR_EXI_0_EXT);
    __OSUnmaskInterrupts(mask >> (chan * 3));
    exi->state |= EXI_STATE_ATTACHED;
    OSRestoreInterrupts(enabled);
    return TRUE;
}

BOOL EXIAttach(EXIChannel chan, EXICallback callback) {
    /* Attaches to an EXI channel if a device is inserted (lastInsert != 0),
     * probing first and serializing state checks under disabled interrupts. */
    EXIData* exi = &Ecb[chan];
    BOOL enabled;
    BOOL ret;

    EXIProbe(chan);
    enabled = OSDisableInterrupts();

    if (exi->lastInsert == 0) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    ret = __EXIAttach(chan, callback);
    OSRestoreInterrupts(enabled);
    return ret;
}

BOOL EXIDetach(EXIChannel chan) {
    EXIData* exi = &Ecb[chan];
    BOOL enabled;
    u32 mask;

    enabled = OSDisableInterrupts();
    if (!(exi->state & EXI_STATE_ATTACHED)) {
        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    if (exi->state & EXI_STATE_LOCKED && exi->dev == EXI_DEV_EXT) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    exi->state &= ~EXI_STATE_ATTACHED;
    mask = OS_INTR_MASK(OS_INTR_EXI_0_EXI) | OS_INTR_MASK(OS_INTR_EXI_0_EXT);
    __OSMaskInterrupts(mask >> (chan * 3));
    OSRestoreInterrupts(enabled);
    return TRUE;
}

/* Selects a device on the given EXI channel at the requested frequency, updating channel state and CPR while masking external interrupts when attached. */
BOOL EXISelect(EXIChannel chan, u32 dev, u32 freq) {
    EXIData* exi = &Ecb[chan];
    BOOL enabled;
    u32 cpr;

    enabled = OSDisableInterrupts();

    if (exi->state & EXI_STATE_SELECTED ||
        chan != EXI_CHAN_2 &&
            (dev == EXI_DEV_EXT && !(exi->state & EXI_STATE_ATTACHED) &&
                 !__EXIProbe(chan) ||
             !(exi->state & EXI_STATE_LOCKED) || exi->dev != dev)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    exi->state |= EXI_STATE_SELECTED;

    cpr = EXI_CHAN_PARAMS[chan].cpr;
    cpr &= (EXI_CPR_EXIINTMASK | EXI_CPR_TCINTMASK | EXI_CPR_EXTINTMASK);
    cpr |= (1 << dev) << 7 | freq << 4;
    EXI_CHAN_PARAMS[chan].cpr = cpr;

    if (exi->state & EXI_STATE_ATTACHED) {
        switch (chan) {
        case EXI_CHAN_0: {
            __OSMaskInterrupts(OS_INTR_MASK(OS_INTR_EXI_0_EXT));
            break;
        }

        case EXI_CHAN_1: {
            __OSMaskInterrupts(OS_INTR_MASK(OS_INTR_EXI_1_EXT));
            break;
        }

        default: {
            break;
        }
        }
    }

    OSRestoreInterrupts(enabled);
    return TRUE;
}

BOOL EXIDeselect(EXIChannel chan) {
    EXIData* exiControl = &Ecb[chan];
    u32 savedCpr;
    BOOL interruptsEnabled;

    interruptsEnabled = OSDisableInterrupts();

    if (!(exiControl->state & EXI_STATE_SELECTED)) {
        OSRestoreInterrupts(interruptsEnabled);
        return FALSE;
    }

    exiControl->state &= ~EXI_STATE_SELECTED;
    savedCpr = EXI_CHAN_PARAMS[chan].cpr;
    EXI_CHAN_PARAMS[chan].cpr =
        savedCpr & (EXI_CPR_EXIINTMASK | EXI_CPR_TCINTMASK | EXI_CPR_EXTINTMASK);

    if (exiControl->state & EXI_STATE_ATTACHED) {
        switch (chan) {
        case EXI_CHAN_0: {
            __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_EXI_0_EXT));
            break;
        }
        case EXI_CHAN_1: {
            __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_EXI_1_EXT));
            break;
        }

        default: {
            break;
        }
        }
    }

    OSRestoreInterrupts(interruptsEnabled);

    if (chan != EXI_CHAN_2 && savedCpr & EXI_CPR_CS0B) {
        return __EXIProbe(chan) != FALSE;
    }

    return TRUE;
}

static void EXIIntrruptHandler(s16 intr, OSContext* ctx) {
    EXIData* exi;
    EXIChannel chan;
    EXICallback callback;
    OSContext temp;

    chan = (EXIChannel)((intr - OS_INTR_EXI_0_EXI) / 3);
    exi = &Ecb[chan];

    EXIClearInterrupts(chan, TRUE, FALSE, FALSE);

    callback = exi->exiCallback;
    if (callback != NULL) {
        OSClearContext(&temp);
        OSSetCurrentContext(&temp);
        callback(chan, ctx);
        OSClearContext(&temp);
        OSSetCurrentContext(ctx);
    }
}

/* Handles a transfer-complete interrupt for an EXI channel, completing the transfer
 * and invoking the channel's transfer-complete callback on a temporary context. */
static void TCIntrruptHandler(s16 intr, OSContext* ctx) {
    EXIData* exi;
    EXIChannel chan;
    EXICallback callback;
    OSContext temp;

    chan = (EXIChannel)((intr - OS_INTR_EXI_0_TC) / 3);
    exi = &Ecb[chan];

    __OSMaskInterrupts(0x80000000 >> intr);
    EXIClearInterrupts(chan, FALSE, TRUE, FALSE);

    callback = exi->tcCallback;
    if (callback != NULL) {
        exi->tcCallback = NULL;
        CompleteTransfer(chan);
        OSClearContext(&temp);
        OSSetCurrentContext(&temp);
        callback(chan, ctx);
        OSClearContext(&temp);
        OSSetCurrentContext(ctx);
    }
}

static void EXTIntrruptHandler(s16 intr, OSContext* ctx) {
    EXIChannel chan;
    EXIData* exi;
    EXICallback callback;
    OSContext temp;
    u32 mask;

    chan = (EXIChannel)((intr - OS_INTR_EXI_0_EXT) / 3);
    mask = OS_INTR_MASK(OS_INTR_EXI_0_EXI) | OS_INTR_MASK(OS_INTR_EXI_0_EXT);
    __OSMaskInterrupts(mask >> (chan * 3));

    exi = &Ecb[chan];
    callback = exi->extCallback;
    exi->state &= ~EXI_STATE_ATTACHED;

    if (callback != NULL) {
        OSClearContext(&temp);
        OSSetCurrentContext(&temp);
        exi->extCallback = NULL;
        callback(chan, ctx);
        OSClearContext(&temp);
        OSSetCurrentContext(ctx);
    }
}

// Brings the EXI interfaces up at startup: waits out any transfer the IPL left
// running, masks every EXI interrupt, resets the three channels, installs the
// channel interrupt handlers and works out which devices are attached.
void EXIInit(void) {
    u32 id;

    // Wait for a transfer started by the IPL to finish on every channel.
    do {
        do {
            ;
        } while ((EXI_CHAN_PARAMS[EXI_CHAN_0].cr & EXI_CR_TSTART) == 1);
    } while ((EXI_CHAN_PARAMS[EXI_CHAN_1].cr & EXI_CR_TSTART) == 1 ||
             (EXI_CHAN_PARAMS[EXI_CHAN_2].cr & EXI_CR_TSTART) == 1);

    // Nothing is ready to take EXI interrupts yet.
    __OSMaskInterrupts(
        OS_INTR_MASK(OS_INTR_EXI_0_EXI) | OS_INTR_MASK(OS_INTR_EXI_0_TC) |
        OS_INTR_MASK(OS_INTR_EXI_0_EXT) | OS_INTR_MASK(OS_INTR_EXI_1_EXI) |
        OS_INTR_MASK(OS_INTR_EXI_1_TC) | OS_INTR_MASK(OS_INTR_EXI_1_EXT) |
        OS_INTR_MASK(OS_INTR_EXI_2_EXI) | OS_INTR_MASK(OS_INTR_EXI_2_TC));

    // No chip select, no clock: leave the peripherals deselected.
    EXI_CHAN_PARAMS[EXI_CHAN_0].cpr = 0;
    EXI_CHAN_PARAMS[EXI_CHAN_1].cpr = 0;
    EXI_CHAN_PARAMS[EXI_CHAN_2].cpr = 0;

    // Channel 0's external ROM (the DVD drive's) stays disabled; the DVD
    // interface reaches it instead.
    EXI_CHAN_PARAMS[EXI_CHAN_0].cpr = EXI_CPR_ROMDIS;

    __OSSetInterruptHandler(OS_INTR_EXI_0_EXI, EXIIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_EXI_0_TC, TCIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_EXI_0_EXT, EXTIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_EXI_1_EXI, EXIIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_EXI_1_TC, TCIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_EXI_1_EXT, EXTIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_EXI_2_EXI, EXIIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_EXI_2_TC, TCIntrruptHandler);

    // Remember channel 0's internal (serial port 1) ID now, before anything
    // else can claim the channel and make it unreadable.
    EXIGetID(EXI_CHAN_0, EXI_DEV_NET, &IDSerialPort1);

    if (__OSInIPL) {
        // The IPL may have left devices attached: probe both channels so their
        // insertion times are set.
        EXIProbeReset();
    } else {
        // A dev board's barnacle is attached to the external port of one
        // channel and reached through the other channel's internal port.
        if ((EXIGetID(EXI_CHAN_0, EXI_DEV_EXT, &id) && id == EXI_ID_BARNACLE)) {
            __OSEnableBarnacle(EXI_CHAN_1, EXI_DEV_EXT);
        } else if (EXIGetID(EXI_CHAN_1, EXI_DEV_EXT, &id) &&
                   id == EXI_ID_BARNACLE) {
            __OSEnableBarnacle(EXI_CHAN_0, EXI_DEV_NET);
        }
    }

    OSRegisterVersion(__EXIVersion);
}

/* Locks an EXI channel for a device, or queues a callback if already locked. */
BOOL EXILock(EXIChannel chan, u32 dev, EXICallback callback) {
    EXIData* exi = &Ecb[chan];
    BOOL interrupts;
    int i;

    interrupts = OSDisableInterrupts();

    if (exi->state & EXI_STATE_LOCKED) {
        if (callback != NULL) {
            for (i = 0; i < exi->numItems; i++) {
                if (exi->items[i].dev == dev) {
                    OSRestoreInterrupts(interrupts);
                    return FALSE;
                }
            }

            exi->items[exi->numItems].callback = callback;
            exi->items[exi->numItems].dev = dev;
            exi->numItems++;
        }

        OSRestoreInterrupts(interrupts);
        return FALSE;
    } else {
        exi->state |= EXI_STATE_LOCKED;
        exi->dev = dev;
        SetExiInterruptMask(chan, exi);
        OSRestoreInterrupts(interrupts);
        return TRUE;
    }
}

BOOL EXIUnlock(EXIChannel chan) {
    EXIData* exi = &Ecb[chan];
    BOOL enabled;
    EXICallback callback;

    enabled = OSDisableInterrupts();

    if (!(exi->state & EXI_STATE_LOCKED)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    exi->state &= ~EXI_STATE_LOCKED;
    SetExiInterruptMask(chan, exi);

    if (exi->numItems > 0) {
        callback = exi->items[0].callback;

        if (--exi->numItems > 0) {
            memmove(&exi->items[0], &exi->items[1],
                    exi->numItems * sizeof(EXIItem));
        }

        callback(chan, NULL);
    }

    OSRestoreInterrupts(enabled);
    return TRUE;
}

// EXILock() callback for a freshly inserted external device: EXIGetID() reads
// its ID again now that the channel has been handed back to it.
static void UnlockedHandler(EXIChannel chan, OSContext* ctx) {
#pragma unused(ctx)
    u32 id;
    EXIGetID(chan, EXI_DEV_EXT, &id);
}

// Reads the peripheral ID of the device attached to a channel.
//
// An external device on channel 0 or 1 is answered from the channel block while
// the OS's insertion time (OS_EXI_LAST_INSERT) has not changed since the ID was
// read; otherwise the device is probed and attached, its ID is read off the bus
// and cached with that insertion time. Channel 0's internal device is answered
// with the ID EXIInit() cached in IDSerialPort1.
//
// @return the channel's insertion time for an external device (0 when there is
//         no device), 1 on success and 0 on failure for the internal ones.
s32 EXIGetID(EXIChannel chan, u32 dev, u32* id) {
    EXIData* exi = &Ecb[chan];
    u32 idCmd;
    s32 ret;
    s32 insertTime;
    BOOL enabled;

    if (chan == EXI_CHAN_0 && dev == EXI_DEV_NET && IDSerialPort1 != 0) {
        *id = IDSerialPort1;
        return 1;
    }

    if (chan < EXI_CHAN_2 && dev == EXI_DEV_EXT) {
        if (!__EXIProbe(chan)) {
            return 0;
        }

        // Same insertion as the last read: hand back the cached ID.
        if (exi->lastInsert == OS_EXI_LAST_INSERT[chan]) {
            *id = exi->id;
            return exi->lastInsert;
        }

        // Newly inserted device: attach it (with no callback of ours) so its ID
        // can be read, and remember the insertion time to cache that ID under.
        if (!__EXIAttach(chan, NULL)) {
            return 0;
        }

        insertTime = OS_EXI_LAST_INSERT[chan];
    }

    enabled = OSDisableInterrupts();
    // A newly inserted external device hands the channel back through
    // UnlockedHandler(), which reads its ID once the channel is free again.
    ret = !EXILock(chan, dev,
                   (chan < EXI_CHAN_2 && dev == EXI_DEV_EXT) ? UnlockedHandler
                                                             : NULL);
    if (ret == 0) {
        ret = !EXISelect(chan, dev, EXI_FREQ_1MHZ);
        if (ret == 0) {
            // A peripheral answers a two-byte 0x0000 command with its 4-byte ID.
            idCmd = 0x00000000;
            ret |= !EXIImm(chan, &idCmd, sizeof(u16), EXI_WRITE, NULL);
            ret |= !EXISync(chan);
            ret |= !EXIImm(chan, id, sizeof(u32), EXI_READ, NULL);
            ret |= !EXISync(chan);
            ret |= !EXIDeselect(chan);
        }
        EXIUnlock(chan);
    }

    OSRestoreInterrupts(enabled);

    if (chan < EXI_CHAN_2 && dev == EXI_DEV_EXT) {
        EXIDetach(chan);

        // Cache the ID only while the device stayed inserted throughout.
        enabled = OSDisableInterrupts();
        ret |= insertTime != OS_EXI_LAST_INSERT[chan];
        if (ret == 0) {
            exi->id = *id;
            exi->lastInsert = insertTime;
        }

        OSRestoreInterrupts(enabled);
        return ret != 0 ? 0 : exi->lastInsert;
    }

    return ret == 0;
}
