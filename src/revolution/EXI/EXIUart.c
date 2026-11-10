#include <revolution/EXI.h>

static BOOL Enabled = FALSE;
static BOOL BarnacleEnabled = FALSE;
static u32 Dev = EXI_DEV_EXT;
static EXIChannel Chan = EXI_CHAN_0;

/* Probe for a Barnacle (UART) device on an EXI channel/device by reading its ID; returns TRUE if a valid ID is present. */
static BOOL ProbeBarnacle(EXIChannel channel, u32 device, u32* outId) {
    BOOL failed;
    u32 idCommand;

    if (channel != EXI_CHAN_2 && device == EXI_DEV_EXT) {
        if (!EXIAttach(channel, NULL)) {
            return FALSE;
        }
    }

    failed = !EXILock(channel, device, NULL);
    if (failed) {
        goto _detach;
    }

    failed = !EXISelect(channel, device, EXI_FREQ_1MHZ);
    if (failed) {
        goto _unlock;
    }

    idCommand = 0x20011300;
    failed = !EXIImm(channel, &idCommand, sizeof(u32), EXI_WRITE, NULL);
    failed |= !EXISync(channel);

    failed |= !EXIImm(channel, outId, sizeof(u32), EXI_READ, NULL);
    failed |= !EXISync(channel);
    failed |= !EXIDeselect(channel);

_unlock:
    EXIUnlock(channel);

_detach:
    if (channel != EXI_CHAN_2 && device == EXI_DEV_EXT) {
        EXIDetach(channel);
    }

    if (failed) {
        return FALSE;
    }

    return *outId != EXI_ID_INVALID;
}

void __OSEnableBarnacle(EXIChannel chan, u32 dev) {
    u32 deviceId;

    /* If the attached EXI device ID is not a known type, probe for barnacle debug
     * support and enable it by recording the channel/device and setting magic flags. */
    if (!EXIGetID(chan, dev, &deviceId)) {
        return;
    }

    switch (deviceId) {
    case EXI_ID_MEMCARD_59:
    case EXI_ID_MEMCARD_123:
    case EXI_ID_MEMCARD_251:
    case EXI_ID_MEMCARD_507:
    case EXI_ID_USB_ADAPTER:
    case 0x01020000:
    case 0x02020000:
    case 0x03010000:
    case 0x04020100:
    case EXI_ID_BROADBAND_ADAPTER:
    case 0x04020300:
    case 0x04040404:
    case 0x04060000:
    case 0x04120000:
    case 0x04130000:
    case 0x04220000:
    case 0x80000004:
    case 0x80000008:
    case 0x80000010:
    case 0x80000020:
    case EXI_ID_INVALID:
        break;
    default:
        if (ProbeBarnacle(chan, dev, &deviceId)) {
            Chan = chan;
            Dev = dev;
            BarnacleEnabled = 0xA5FF005A;
            Enabled = 0xA5FF005A;
        }
        break;
    }
}
