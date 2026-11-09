#include "src/review_kpad.h"
#include "src/review___kpad.h"

/* KPAD's shared defaults.  The game's symbols can't be renamed yet, so alias the
   three this file reads to the names review_KPAD.c gives the same globals. */
extern Vec2 lbl_8055D988;
extern f32 lbl_8055D990;
extern u16 lbl_80558EB0;

#define kp_zero_vec2 lbl_8055D988    /* .sbss Vec2 {0.0f, 0.0f}: "no pointer motion" */
#define kp_dist_vv1 lbl_8055D990     /* .sbss f32: IR dot interval / tan(21 deg), the sensor half angle */
#define kp_ah_circle_ct lbl_80558EB0 /* .sdata u16 100: frames the acc horizon may sit in the circle */

void reset_kpad(KPADInsideStatus* kp) {
    /* Put one channel's KPAD record back to its power-on state: clears the pointer,
       stick, accelerometer and button state, re-arms the button repeat and the IR
       object slots, probes the Wii Remote and silences its rumble, and clears the
       fields of whichever extension is attached.  KPADInit calls it once per channel
       and the read path calls it whenever a device appears, goes away or changes. */
    KPADObject* kobj;
    KPADStatus* sp = &kp->status;             /* what KPADRead hands the game */
    KPADEXStatus* ep = &kp->status.ex_status; /* its per-device-type extra fields */

    sp->hold = sp->trig = sp->release = 0;
    kp->btn_repeat_time = 0;
    kp->btn_repeat_next = kp->btn_repeat_delay; /* restart the press-and-hold repeat */
    kp->status.dpd_valid_fg = 0;
    kp->dpd_valid2_ct = 0;
    sp->pos = sp->vec = kp_zero_vec2;
    sp->speed = 0.0f;
    sp->horizon.x = kp->acc_horizon.x = kp->obj_horizon.x = 1.0f;
    sp->horizon.y = kp->acc_horizon.y = kp->obj_horizon.y = 0.0f;
    sp->hori_vec = kp_zero_vec2;
    sp->hori_speed = 0.0f;
    sp->acc_vertical.x = 1.0f;
    sp->acc_vertical.y = 0.0f;
    /* Assume the sensor sits at the reference distance until two IR dots say otherwise. */
    sp->dist = kp->dist_org;
    sp->dist_vec = sp->dist_speed = 0.0f;
    kp->sec_dist = sp->dist;
    kp->sec_length = kp->trust_sec_length = kp_dist_vv1 / kp->sec_dist;
    kp->sec_nrm = kp->sec_nrm_hori;
    /* Pointing straight down at the sensor is the neutral accelerometer reading. */
    sp->acc.x = sp->acc.z = 0.0f;
    sp->acc.y = -1.0f;
    sp->acc_value = 1.0f;
    sp->acc_speed = 0.0f;
    kp->hard_acc = sp->acc;
    kp->ah_circle_pos = kp->acc_horizon;
    kp->ah_circle_ct = kp_ah_circle_ct;
    kp->valid_objs = 0;
    kobj = &kp->kobj_sample[WPAD_DPD_MAX_OBJECTS - 1];
    do { kobj->error_fg = -1; } while (--kobj >= kp->kobj_sample); /* no IR object yet */
    kobj = &kp->kobj_regular[KPAD_USE_OBJECTS - 1];
    do { kobj->error_fg = -1; } while (--kobj >= kp->kobj_regular);
    kp->last_read_index = -1; /* nothing of the ring buffer has been read */
    kp->repeat_count = 0;
    /* While no device is attached active_chan holds chan - 4, so a negative value
       still says which channel this record watches. */
    if (kp->active_chan < 0) {
        kp->status.wpad_err = WPADProbe(kp->active_chan + 4, NULL);
        WPADControlMotor(kp->active_chan + 4, WPAD_MOTOR_STOP);
        if (kp->status.wpad_err != WPAD_ERR_NO_CONTROLLER) kp->active_chan += 4; /* it answered */
    } else {
        kp->status.wpad_err = WPADProbe(kp->active_chan, NULL);
        WPADControlMotor(kp->active_chan, WPAD_MOTOR_STOP);
    }
    switch (kp->status.dev_type) {
    case WPAD_DEV_FS: /* Wii Remote + Nunchuk */
        ep->fs.stick = kp_zero_vec2;
        ep->fs.acc.z = 0.0f;
        ep->fs.acc.x = 0.0f;
        ep->fs.acc.y = -1.0f;
        ep->fs.acc_value = 1.0f;
        ep->fs.acc_speed = 0.0f;
        break;
    case WPAD_DEV_CLASSIC: /* Classic Controller */
        ep->cl.lstick = kp_zero_vec2;
        ep->cl.rstick = kp_zero_vec2;
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
