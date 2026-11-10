#include <revolution/KPAD/__KPAD.h>

extern s32 fn_800624A4(s32, s32, void*);
extern void WPADiSamplingCallback(void);

/* REXE01 callback ABI supplies the detected WPAD device type in r4. */
void KPADiSamplingCallback(s32 chan, u32 deviceType) {
    /* Reconfigure KPAD/WPAD sampling for a detected device type and refresh state. */
    KPADInsideStatus* padStatus;
    s32 dataFormat;
    BOOL enabled;
    s32 setResult;

    if (deviceType == 253) {
        return;
    }
    padStatus = &inside_kpads[chan];
    WPADSetAutoSamplingBuf(chan, NULL, 0);
    switch ((s32)deviceType) {
    case WPAD_DEV_CORE:
    case 251:
    case 252:
    case 255:
        dataFormat = WPAD_FMT_CORE_BTN_ACC;
        break;
    case WPAD_DEV_FREESTYLE:
        dataFormat = WPAD_FMT_FS_BTN_ACC;
        break;
    case WPAD_DEV_CLASSIC:
        dataFormat = WPAD_FMT_CLASSIC_BTN_ACC;
        break;
    default:
        return;
    }
    setResult = WPADSetDataFormat(chan, dataFormat);
    padStatus->data_format_failed = (setResult == -2);
    enabled = OSDisableInterrupts();
    if (!padStatus->sampling_pending && WPADProbe(chan, NULL) != -1) {
        padStatus->sampling_pending = TRUE;
        if (padStatus->dpd_ctrl_callback != NULL) {
            padStatus->dpd_ctrl_callback(chan, FALSE);
        }
    }
    OSRestoreInterrupts(enabled);
    padStatus->sampling_restart = TRUE;
    if (fn_800624A4(chan, 0, (void*)WPADiSamplingCallback) != 0) {
        padStatus->data_format_failed = TRUE;
    }
    WPADSetAutoSamplingBuf(chan, (u8*)padStatus + 0x118, 12);
}
