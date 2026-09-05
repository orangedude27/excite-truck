#include "src/review_kpad.h"
#include "src/review___kpad.h"

extern Vec2 lbl_8055D988;
extern f32 lbl_8055D990;
extern u16 lbl_80558EB0;

void reset_kpad(KPADInsideStatus* kp) {
    KPADObject* op;
    KPADStatus* sp = &kp->status;
    KPADEXStatus* ep = &kp->status.ex_status;

    sp->hold = sp->trig = sp->release = 0;
    kp->btn_repeat_time = 0;
    kp->btn_repeat_next = kp->btn_repeat_delay;
    kp->status.dpd_valid_fg = 0;
    kp->dpd_valid2_ct = 0;
    sp->pos = sp->vec = lbl_8055D988;
    sp->speed = 0.0f;
    sp->horizon.x = kp->acc_horizon.x = kp->obj_horizon.x = 1.0f;
    sp->horizon.y = kp->acc_horizon.y = kp->obj_horizon.y = 0.0f;
    sp->hori_vec = lbl_8055D988;
    sp->hori_speed = 0.0f;
    sp->acc_vertical.x = 1.0f;
    sp->acc_vertical.y = 0.0f;
    sp->dist = kp->dist_org;
    sp->dist_vec = sp->dist_speed = 0.0f;
    kp->sec_dist = sp->dist;
    kp->sec_length = kp->trust_sec_length = lbl_8055D990 / kp->sec_dist;
    kp->sec_nrm = kp->sec_nrm_hori;
    sp->acc.x = sp->acc.z = 0.0f;
    sp->acc.y = -1.0f;
    sp->acc_value = 1.0f;
    sp->acc_speed = 0.0f;
    kp->hard_acc = sp->acc;
    kp->ah_circle_pos = kp->acc_horizon;
    kp->ah_circle_ct = lbl_80558EB0;
    kp->valid_objs = 0;
    op = &kp->kobj_sample[WPAD_DPD_MAX_OBJECTS - 1];
    do { op->error_fg = -1; } while (--op >= kp->kobj_sample);
    op = &kp->kobj_regular[KPAD_USE_OBJECTS - 1];
    do { op->error_fg = -1; } while (--op >= kp->kobj_regular);
    kp->unk_0x116 = -1;
    kp->repeat_count = 0;
    if (kp->active_chan < 0) {
        kp->status.wpad_err = WPADProbe(kp->active_chan + 4, NULL);
        WPADControlMotor(kp->active_chan + 4, 0);
        if (kp->status.wpad_err != -1) kp->active_chan += 4;
    } else {
        kp->status.wpad_err = WPADProbe(kp->active_chan, NULL);
        WPADControlMotor(kp->active_chan, 0);
    }
    switch (kp->status.dev_type) {
    case WPAD_DEV_FS:
        ep->fs.stick = lbl_8055D988;
        ep->fs.acc.z = 0.0f;
        ep->fs.acc.x = 0.0f;
        ep->fs.acc.y = -1.0f;
        ep->fs.acc_value = 1.0f;
        ep->fs.acc_speed = 0.0f;
        break;
    case WPAD_DEV_CLASSIC:
        ep->cl.lstick = lbl_8055D988;
        ep->cl.rstick = lbl_8055D988;
        ep->cl.rtrigger = 0.0f;
        ep->cl.ltrigger = 0.0f;
        ep->cl.release = 0;
        ep->cl.trig = 0;
        ep->cl.hold = 0;
        kp->btn_cl_repeat_time = 0;
        kp->btn_cl_repeat_next = kp->btn_cl_repeat_delay;
        break;
    }
}
