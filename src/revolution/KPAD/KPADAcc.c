#include "src/review_kpad.h"
#include "src/review___kpad.h"

extern void reset_kpad(KPADInsideStatus*);
extern u16 lbl_80560BF4, lbl_80560BF6, lbl_80560BF8;
extern u16 lbl_80560BFC, lbl_80560BFE, lbl_80560C00;
/* Reuse REXE01 shared 1.0f/2.0f constants to avoid local pool growth. */
extern f32 lbl_80560C04, lbl_80560C08, lbl_80560BE4, lbl_80560BF0;
extern f32 lbl_80558EEC, lbl_80558EF0;
extern f32 lbl_80558EA4, lbl_80558EAC, lbl_8055D994;
extern f32 lbl_80560BD8;
extern u16 lbl_80558EB0;

static void calc_acc_horizon(KPADInsideStatus* kp, f32* acc, f32 acc2) {
    f32 f1, f2;

    f2 = acc2 - *acc;

    if (f2 < 0.0f) {
        f1 = -f2;
    } else {
        f1 = f2;
    }

    if (f1 >= kp->acc_play_radius) {
        f1 = lbl_80560BE4;
    } else {
        f1 /= kp->acc_play_radius;
        f1 *= f1;
        f1 *= f1;
    }
    f1 *= kp->acc_sensitivity;
    *acc += f1 * f2;
}

static void calc_acc_vertical(KPADInsideStatus* kp) {
    f32 f1, vx, vy, ax, ay;
    f1 = fn_8002F234(kp->hard_acc.x * kp->hard_acc.x + kp->hard_acc.y * kp->hard_acc.y);
    if (f1 == 0.0f || f1 >= lbl_80560BF0) {
        return;
    }
    ax = kp->hard_acc.x / f1;
    ay = kp->hard_acc.y / f1;

    if (f1 > lbl_80560BE4) {
        f1 = lbl_80560BF0 - f1;
    }
    f1 *= f1 * lbl_80558EA4;

    vx = kp->accXY_nrm_hori.x * ax + kp->accXY_nrm_hori.y * ay;
    vy = kp->accXY_nrm_hori.y * ax - kp->accXY_nrm_hori.x * ay;
    ax = (vx - kp->acc_horizon.x) * f1 + kp->acc_horizon.x;
    ay = (vy - kp->acc_horizon.y) * f1 + kp->acc_horizon.y;

    f1 = fn_8002F234(ax * ax + ay * ay);
    if (f1 == 0.0f) {
        return;
    }
    kp->acc_horizon.x = ax / f1;
    kp->acc_horizon.y = ay / f1;

    kp->ah_circle_pos.x += (kp->acc_horizon.x - kp->ah_circle_pos.x) * lbl_80558EAC;
    kp->ah_circle_pos.y += (kp->acc_horizon.y - kp->ah_circle_pos.y) * lbl_80558EAC;

    vx = kp->acc_horizon.x - kp->ah_circle_pos.x;
    vy = kp->acc_horizon.y - kp->ah_circle_pos.y;
    if (vx * vx + vy * vy <= lbl_8055D994) {
        if (kp->ah_circle_ct) {
            --kp->ah_circle_ct;
        }
    } else {
        kp->ah_circle_ct = lbl_80558EB0;
    }
}

static void read_kpad_acc_head(KPADInsideStatus* kp) {
    KPADStatus* sp = &kp->status;
    f32 f1, f2, ax, ay;

    f2 = kp->hard_acc.x * kp->hard_acc.x + kp->hard_acc.y * kp->hard_acc.y;
    ax = fn_8002F234(f2);
    ay = -kp->hard_acc.z;
    f1 = fn_8002F234(f2 + ay * ay);
    if (f1 == 0.0f || f1 >= lbl_80560BF0) {
        return;
    }
    ax = ax / f1;
    ay /= f1;

    if (f1 > lbl_80560BE4) {
        f1 = lbl_80560BF0 - f1;
    }
    f1 *= f1 * lbl_80558EA4;

    ax = (ax - sp->acc_vertical.x) * f1 + sp->acc_vertical.x;
    ay = (ay - sp->acc_vertical.y) * f1 + sp->acc_vertical.y;

    f1 = fn_8002F234(ax * ax + ay * ay);
    if (f1 == 0.0f) {
        return;
    }
    sp->acc_vertical.x = ax / f1;
    sp->acc_vertical.y = ay / f1;
}

static f32 clamp_acc(f32 acc, f32 clamp) {
    if (acc < 0.0f) {
        if (acc < -clamp)
            return -clamp;
    } else {
        if (acc > clamp)
            return clamp;
    }
    return acc;
}

void read_kpad_acc(KPADInsideStatus* kp, KPADUnifiedWpadStatus* uwp, u32 dev_type, s32 chan) {
    KPADStatus* sp = &kp->status;
    Vec vec;
    s32 probe_res;
    s32 probe_dev_type;
    f32 acc_scale_x;
    f32 acc_scale_y;
    f32 acc_scale_z;
    f32 acc_scale_fs_x;
    f32 acc_scale_fs_y;
    f32 acc_scale_fs_z;

    acc_scale_x = lbl_80560C04;
    acc_scale_y = lbl_80560C04;
    acc_scale_z = lbl_80560C04;
    acc_scale_fs_x = lbl_80560C08;
    acc_scale_fs_y = lbl_80560C08;
    acc_scale_fs_z = lbl_80560C08;

    probe_res = WPADProbe(chan, &probe_dev_type);
    if (probe_res == WPAD_ERR_OK) {
        WPADAccGravityUnit core1G;

        ((u16*)&core1G)[0] = lbl_80560BF4;
        ((u16*)&core1G)[1] = lbl_80560BF6;
        ((u16*)&core1G)[2] = lbl_80560BF8;
        WPADGetAccGravityUnit(chan, WPAD_DEV_CORE, &core1G);
        if (core1G.x * core1G.y * core1G.z != 0) {
            acc_scale_x = lbl_80560BE4 / core1G.x;
            acc_scale_y = lbl_80560BE4 / core1G.y;
            acc_scale_z = lbl_80560BE4 / core1G.z;
        }

        if (dev_type == WPAD_DEV_FS) {
            WPADAccGravityUnit fs1G;

            ((u16*)&fs1G)[0] = lbl_80560BFC;
            ((u16*)&fs1G)[1] = lbl_80560BFE;
            ((u16*)&fs1G)[2] = lbl_80560C00;
            WPADGetAccGravityUnit(chan, WPAD_DEV_FS, &fs1G);
            if (fs1G.x * fs1G.y * fs1G.z != 0) {
                acc_scale_fs_x = lbl_80560BE4 / fs1G.x;
                acc_scale_fs_y = lbl_80560BE4 / fs1G.y;
                acc_scale_fs_z = lbl_80560BE4 / fs1G.z;
            }
        }
    }

    if (kp->active_chan < 0) {
        return;
    }

    if (dev_type == WPAD_DEV_FS) {
        if (probe_res != WPAD_ERR_OK) {
            if (probe_res == WPAD_ERR_NO_CONTROLLER) {
                kp->active_chan -= 4;
                reset_kpad(kp);
                return;
            }
        } else {
            kp->hard_acc.x = clamp_acc((f32)(s32)-uwp->u.core.accX * acc_scale_x, lbl_80558EEC);
            kp->hard_acc.y = clamp_acc((f32)(s32)-uwp->u.core.accZ * acc_scale_z, lbl_80558EEC);
            kp->hard_acc.z = clamp_acc((f32)(s32)uwp->u.core.accY * acc_scale_y, lbl_80558EEC);
        }
    } else {
        if (probe_res != WPAD_ERR_OK) {
            if (probe_res == WPAD_ERR_NO_CONTROLLER) {
                kp->active_chan -= 4;
                reset_kpad(kp);
                return;
            }
        } else {
            kp->hard_acc.x = clamp_acc(-uwp->u.core.accX * acc_scale_x, lbl_80558EEC);
            kp->hard_acc.y = clamp_acc(-uwp->u.core.accZ * acc_scale_z, lbl_80558EEC);
            kp->hard_acc.z = clamp_acc(uwp->u.core.accY * acc_scale_y, lbl_80558EEC);
        }
    }

    vec = sp->acc;

    calc_acc_horizon(kp, &sp->acc.x, kp->hard_acc.x);
    calc_acc_horizon(kp, &sp->acc.y, kp->hard_acc.y);
    calc_acc_horizon(kp, &sp->acc.z, kp->hard_acc.z);
    sp->acc_value = fn_8002F234(sp->acc.x * sp->acc.x + sp->acc.y * sp->acc.y + sp->acc.z * sp->acc.z);

    vec.x -= sp->acc.x;
    vec.y -= sp->acc.y;
    vec.z -= sp->acc.z;
    sp->acc_speed = fn_8002F234(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    calc_acc_vertical(kp);
    read_kpad_acc_head(kp);

    if (dev_type == WPAD_DEV_FS) {
        vec = sp->ex_status.fs.acc;

        calc_acc_horizon(kp, &sp->ex_status.fs.acc.x, clamp_acc(-uwp->u.fs.fsAccX * acc_scale_fs_x, lbl_80558EF0));
        calc_acc_horizon(kp, &sp->ex_status.fs.acc.y, clamp_acc(-uwp->u.fs.fsAccZ * acc_scale_fs_z, lbl_80558EF0));
        calc_acc_horizon(kp, &sp->ex_status.fs.acc.z, clamp_acc(uwp->u.fs.fsAccY * acc_scale_fs_y, lbl_80558EF0));

        sp->ex_status.fs.acc_value = fn_8002F234(sp->ex_status.fs.acc.x * sp->ex_status.fs.acc.x +
                                          sp->ex_status.fs.acc.y * sp->ex_status.fs.acc.y +
                                          sp->ex_status.fs.acc.z * sp->ex_status.fs.acc.z);

        vec.x -= sp->ex_status.fs.acc.x;
        vec.y -= sp->ex_status.fs.acc.y;
        vec.z -= sp->ex_status.fs.acc.z;

        sp->ex_status.fs.acc_speed = fn_8002F234(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    }
}
