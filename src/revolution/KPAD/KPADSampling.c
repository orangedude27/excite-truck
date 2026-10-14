#include <revolution/KPAD/__KPAD.h>

extern s32 fn_800624A4(s32, s32, void*);
extern void WPADiSamplingCallback(void);

/* REXE01 callback ABI supplies the detected WPAD device type in r4. */
void KPADiSamplingCallback(s32 chan, u32 type) {
    KPADInsideStatus* kp;
    s32 format;
    BOOL irq;
    s32 result;

    if (type == 253) {
        return;
    }
    kp = &inside_kpads[chan];
    WPADSetAutoSamplingBuf(chan, NULL, 0);
    switch ((s32)type) {
    case WPAD_DEV_CORE:
    case 251:
    case 252:
    case 255:
        format = WPAD_FMT_CORE_BTN_ACC;
        break;
    case WPAD_DEV_FREESTYLE:
        format = WPAD_FMT_FS_BTN_ACC;
        break;
    case WPAD_DEV_CLASSIC:
        format = WPAD_FMT_CLASSIC_BTN_ACC;
        break;
    default:
        return;
    }
    result = WPADSetDataFormat(chan, format);
    kp->data_format_failed = (result == -2);
    irq = OSDisableInterrupts();
    if (!kp->sampling_pending && WPADProbe(chan, NULL) != -1) {
        kp->sampling_pending = TRUE;
        if (kp->dpd_ctrl_callback != NULL) {
            kp->dpd_ctrl_callback(chan, FALSE);
        }
    }
    OSRestoreInterrupts(irq);
    kp->sampling_restart = TRUE;
    if (fn_800624A4(chan, 0, (void*)WPADiSamplingCallback) != 0) {
        kp->data_format_failed = TRUE;
    }
    WPADSetAutoSamplingBuf(chan, (u8*)kp + 0x118, 12);
}
