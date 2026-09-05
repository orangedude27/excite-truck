#include "src/review_kpad.h"
extern KPADInsideStatus inside_kpads[];
extern void KPADiSamplingCallback(s32, u32);
extern s32 fn_800624A4(s32, s32, void*);
extern void WPADiSamplingCallback(void);

void KPADiSamplingCallback(s32 chan, u32 type) {
    KPADInsideStatus* kp;
    s32 format;
    BOOL irq;
    s32 result;

    if (type == WPAD_DEV_NONE) {
        return;
    }
    kp = &inside_kpads[chan];
    WPADSetAutoSamplingBuf(chan, NULL, 0);
    if (type < WPAD_DEV_FUTURE) {
        if (type < WPAD_DEV_FREESTYLE) {
            format = WPAD_FMT_CORE_BTN_ACC;
        } else if (type < WPAD_DEV_CLASSIC + 1) {
            format = type == WPAD_DEV_FREESTYLE ? WPAD_FMT_FS_BTN_ACC : WPAD_FMT_CLASSIC_BTN_ACC;
        } else {
            return;
        }
    } else {
        if (type == 255 || type < WPAD_DEV_NOT_FOUND) {
            format = WPAD_FMT_CORE_BTN_ACC;
        } else {
            return;
        }
    }
    result = WPADSetDataFormat(chan, format);
    kp->unk_0x3fc = (result == -2);
    irq = OSDisableInterrupts();
    if (!kp->unk_0x3f0 && WPADProbe(chan, NULL) != -1) {
        kp->unk_0x3f0 = TRUE;
        if (kp->dpd_ctrl_callback != NULL) {
            kp->dpd_ctrl_callback(chan, FALSE);
        }
    }
    OSRestoreInterrupts(irq);
    kp->unk_0x3f4 = TRUE;
    if (fn_800624A4(chan, 0, (void*)WPADiSamplingCallback) != 0) {
        kp->unk_0x3fc = TRUE;
    }
    WPADSetAutoSamplingBuf(chan, (u8*)kp + 0x118, 0xC);
}
