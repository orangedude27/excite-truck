#include "types.h"
#include "revolution/KPAD/KPAD.h"
#include "revolution/WPAD/WPAD.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The button and auto-repeat slice of one channel's KPADInsideStatus record.
   Repeat timers advance by repeat_count each sample until they hit a threshold. */
typedef struct KpadButtonStatus {
    /* 0x000 */ u32 hold;
    /* 0x004 */ u32 trig;
    /* 0x008 */ u32 release;
    u8 padC[0x60 - 0x0C];
    /* 0x060 */ u32 cl_hold;
    /* 0x064 */ u32 cl_trig;
    /* 0x068 */ u32 cl_release;
    u8 pad6C[0x112 - 0x6C];
    /* 0x112 */ u16 repeat_count;
    /* 0x114 */ s16 active_chan;
    u8 pad116[0x3DC - 0x116];
    /* 0x3DC */ u16 btn_repeat_time;
    /* 0x3DE */ u16 btn_repeat_next;
    /* 0x3E0 */ u16 btn_repeat_delay;
    /* 0x3E2 */ u16 btn_repeat_pulse;
    /* 0x3E4 */ u16 btn_cl_repeat_time;
    /* 0x3E6 */ u16 btn_cl_repeat_next;
    /* 0x3E8 */ u16 btn_cl_repeat_delay;
    /* 0x3EA */ u16 btn_cl_repeat_pulse;
} KpadButtonStatus;

/* Advance the core or classic button auto-repeat timers and flag a repeat press. */
void calc_button_repeat(KpadButtonStatus *kp, KpadButtonStatus *status, u32 dev_type) {
    u16 cls_time, core_time;
    if (dev_type == WPAD_DEV_CLASSIC) {
        if (status->cl_trig || status->cl_release) {
            kp->btn_cl_repeat_time = 0;
            kp->btn_cl_repeat_next = kp->btn_cl_repeat_delay;
            if (status->cl_trig && kp->btn_cl_repeat_pulse)
                status->cl_hold |= KPAD_BUTTON_RPT;
        } else if (status->cl_hold) {
            cls_time = kp->btn_cl_repeat_time + kp->repeat_count;
            kp->btn_cl_repeat_time = cls_time;
            if (cls_time >= KPAD_BTN_NO_RPT_DELAY)
                kp->btn_cl_repeat_time = cls_time - KPAD_BTN_NO_RPT_DELAY;
            if (kp->btn_cl_repeat_time >= kp->btn_cl_repeat_next) {
                status->cl_hold |= KPAD_BUTTON_RPT;
                kp->btn_cl_repeat_next = kp->btn_cl_repeat_next + kp->btn_cl_repeat_pulse;
                if (kp->btn_cl_repeat_time >= KPAD_BTN_RPT_TIME_MAX) {
                    kp->btn_cl_repeat_time = kp->btn_cl_repeat_time - KPAD_BTN_RPT_TIME_MAX;
                    kp->btn_cl_repeat_next = kp->btn_cl_repeat_next - KPAD_BTN_RPT_TIME_MAX;
                }
            }
        }
    } else if (status->trig || status->release) {
        kp->btn_repeat_time = 0;
        kp->btn_repeat_next = kp->btn_repeat_delay;
        if (status->trig && kp->btn_repeat_pulse)
            status->hold |= KPAD_BUTTON_RPT;
    } else if (status->hold) {
        core_time = kp->btn_repeat_time + kp->repeat_count;
        kp->btn_repeat_time = core_time;
        if (core_time >= KPAD_BTN_NO_RPT_DELAY)
            kp->btn_repeat_time = core_time - KPAD_BTN_NO_RPT_DELAY;
        if (kp->btn_repeat_time >= kp->btn_repeat_next) {
            status->hold |= KPAD_BUTTON_RPT;
            kp->btn_repeat_next = kp->btn_repeat_next + kp->btn_repeat_pulse;
            if (kp->btn_repeat_time >= KPAD_BTN_RPT_TIME_MAX) {
                kp->btn_repeat_time = kp->btn_repeat_time - KPAD_BTN_RPT_TIME_MAX;
                kp->btn_repeat_next = kp->btn_repeat_next - KPAD_BTN_RPT_TIME_MAX;
            }
        }
    }
}

extern void reset_kpad(void *);

/* Update held/pressed/released buttons (plus classic buttons) from a WPAD report,
   handling error/reset status and maintaining repeat state via calc_button_repeat. */
void calc_acc_horizon(KpadButtonStatus *kp, WPADCLStatus *report, u32 mode) {
    u32 old_buttons;
    u32 old_horizon;
    u32 current;
    u32 changed;
    u32 previous;
    s16 count;
    s8 status;

    count = kp->active_chan;
    if (count < 0)
        return;
    previous = kp->hold;
    old_buttons = previous & KPAD_BUTTON_MASK;
    if (mode == WPAD_DEV_CLASSIC) {
        previous = kp->cl_hold;
        old_horizon = previous & KPAD_BUTTON_MASK;
    }
    if (mode == WPAD_DEV_FREESTYLE) {
        status = report->err;
        if (status != 0) {
            if (status == WPAD_ERR_NO_CONTROLLER) {
                kp->active_chan -= 4;
                reset_kpad(kp);
                return;
            }
            goto process;
        }
        kp->hold = report->button;
        goto process;
    }
    if (mode == WPAD_DEV_CLASSIC) {
        status = report->err;
        if (status != 0) {
            if (status == WPAD_ERR_NO_CONTROLLER) {
                kp->active_chan -= 4;
                reset_kpad(kp);
                return;
            }
            goto process;
        }
        kp->hold = report->button;
        kp->cl_hold = report->clButton;
        goto process;
    }
    status = report->err;
    if (status != 0) {
        if (status == WPAD_ERR_NO_CONTROLLER) {
            kp->active_chan -= 4;
            reset_kpad(kp);
            return;
        }
        goto process;
    }
    kp->hold = report->button;
process:
    current = kp->hold;
    changed = current ^ old_buttons;
    kp->trig = changed & current;
    kp->release = changed & old_buttons;
    calc_button_repeat(kp, kp, WPAD_DEV_CORE);
    if (mode == WPAD_DEV_CLASSIC) {
        current = kp->cl_hold;
        changed = current ^ old_horizon;
        kp->cl_trig = changed & current;
        kp->cl_release = changed & old_horizon;
        calc_button_repeat(kp, kp, WPAD_DEV_CLASSIC);
    }
}

