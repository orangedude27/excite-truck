#include "src/review_kpad.h"
#include "src/review___kpad.h"

extern f64 fn_8002F234(f32); /* MSL sqrt(): the game's shared double-precision square root */
extern void reset_kpad(KPADInsideStatus*);

extern u16 lbl_80560BF4, lbl_80560BF6, lbl_80560BF8;
extern u16 lbl_80560BFC, lbl_80560BFE, lbl_80560C00;
/* Reuse REXE01's shared constants (1.0f, 2.0f, 0.01f, 0.005f, ...) to avoid growing the literal pool. */
extern f32 lbl_80560C04, lbl_80560C08, lbl_80560BE4, lbl_80560BF0;
extern f32 lbl_80558EEC, lbl_80558EF0;
extern f32 lbl_80558EA4, lbl_80558EAC, lbl_8055D994;
extern u16 lbl_80558EB0;

#define kp_sqrt fn_8002F234

#define kp_core_gravity_x lbl_80560BF4 /* s16 256: default core 1G unit (1G == 256) */
#define kp_core_gravity_y lbl_80560BF6
#define kp_core_gravity_z lbl_80560BF8
#define kp_fs_gravity_x lbl_80560BFC /* s16 256: default FS 1G unit */
#define kp_fs_gravity_y lbl_80560BFE
#define kp_fs_gravity_z lbl_80560C00

#define kp_one_g lbl_80560BE4              /* f32 1.0: 1G scale numerator / full deflection */
#define kp_two_g lbl_80560BF0              /* f32 2.0: accelerometer magnitude cutoff */
#define kp_core_scale_default lbl_80560C04 /* f32 0.01: default core g-scale */
#define kp_fs_scale_default lbl_80560C08   /* f32 0.005: default FS g-scale */
#define kp_acc_horizon_pw lbl_80558EA4     /* f32 0.05: acc horizon filter power */
#define kp_ah_circle_pw lbl_80558EAC       /* f32 0.06: horizon circle smoothing factor */
#define kp_ah_circle_r2 lbl_8055D994       /* .sbss f32: squared "inside circle" radius */
#define kp_ah_circle_ct_init lbl_80558EB0  /* u16 100: frames the horizon may sit in the circle */
#define kp_rm_acc_max lbl_80558EEC         /* f32 3.4: core accelerometer clamp */
#define kp_fs_acc_max lbl_80558EF0         /* f32 2.1: FS accelerometer clamp */

static void calc_acc_horizon(KPADInsideStatus* kp, f32* acc, f32 acc2) {
    f32 f1, f2;

    f2 = acc2 - *acc;

    if (f2 < 0.0f) {
        f1 = -f2;
    } else {
        f1 = f2;
    }

    if (f1 >= kp->acc_play_radius) {
        f1 = kp_one_g;
    } else {
        f1 /= kp->acc_play_radius;
        f1 *= f1;
        f1 *= f1;
    }
    f1 *= kp->acc_sensitivity;
    *acc += f1 * f2;
}

static void calc_acc_vertical(KPADInsideStatus* kp) {
    /* Compute filtered vertical/horizon acceleration from horizontal hard_acc and
     * update the smoothed horizon circle position/counter. */
    f32 mag, projX, projY, dirX, dirY;

    mag = (f32)kp_sqrt(kp->hard_acc.x * kp->hard_acc.x + kp->hard_acc.y * kp->hard_acc.y);
    if (mag == 0.0f || mag >= kp_two_g) return;

    dirX = kp->hard_acc.x / mag;
    dirY = kp->hard_acc.y / mag;

    if (mag > kp_one_g) mag = kp_two_g - mag;
    mag *= mag * kp_acc_horizon_pw;

    projX = kp->accXY_nrm_hori.x * dirX + kp->accXY_nrm_hori.y * dirY;
    projY = kp->accXY_nrm_hori.y * dirX - kp->accXY_nrm_hori.x * dirY;

    dirX = (projX - kp->acc_horizon.x) * mag + kp->acc_horizon.x;
    dirY = (projY - kp->acc_horizon.y) * mag + kp->acc_horizon.y;

    mag = (f32)fn_8002F234(dirX * dirX + dirY * dirY);
    if (mag == 0.0f) return;

    kp->acc_horizon.x = dirX / mag;
    kp->acc_horizon.y = dirY / mag;

    kp->ah_circle_pos.x += (kp->acc_horizon.x - kp->ah_circle_pos.x) * lbl_80558EAC;
    kp->ah_circle_pos.y += (kp->acc_horizon.y - kp->ah_circle_pos.y) * lbl_80558EAC;

    projX = kp->acc_horizon.x - kp->ah_circle_pos.x;
    projY = kp->acc_horizon.y - kp->ah_circle_pos.y;

    if (projX * projX + projY * projY <= lbl_8055D994) {
        if (kp->ah_circle_ct) --kp->ah_circle_ct;
    } else kp->ah_circle_ct = lbl_80558EB0;
}

static void read_kpad_acc_head(KPADInsideStatus* kp) {
    /* Filter the reported acceleration into the status' 2D "head" (vertical) vector. */
    KPADStatus* sp = &kp->status;
    f32 f1, f2, ax, ay;

    f2 = kp->hard_acc.x * kp->hard_acc.x + kp->hard_acc.y * kp->hard_acc.y;
    ax = kp_sqrt(f2);
    ay = -kp->hard_acc.z;
    f1 = kp_sqrt(f2 + ay * ay);
    if (f1 == 0.0f || f1 >= kp_two_g) {
        return;
    }
    ax = ax / f1;
    ay /= f1;

    if (f1 > kp_one_g) {
        f1 = kp_two_g - f1;
    }
    f1 *= f1 * kp_acc_horizon_pw;

    ax = (ax - sp->acc_vertical.x) * f1 + sp->acc_vertical.x;
    ay = (ay - sp->acc_vertical.y) * f1 + sp->acc_vertical.y;

    f1 = kp_sqrt(ax * ax + ay * ay);
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
    /* Read the unified controller's accelerometer into the KPAD status. Calibrates per-axis
       g-scales from the controller's reported 1G vector (kp_one_g == 1.0), falls back to
       kp_core_scale_default (0.01) / kp_fs_scale_default (0.005), clamps hard_acc to
       kp_rm_acc_max (3.4) or kp_fs_acc_max (2.1), then filters acc, its speed/value, the
       vertical and horizon vectors, and the FS extension accelerometer. */
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
    f32 v1, v2, v3;

    acc_scale_x = kp_core_scale_default;
    acc_scale_y = kp_core_scale_default;
    acc_scale_z = kp_core_scale_default;
    acc_scale_fs_x = kp_fs_scale_default;
    acc_scale_fs_y = kp_fs_scale_default;
    acc_scale_fs_z = kp_fs_scale_default;

    probe_res = WPADProbe(chan, &probe_dev_type);
    if (probe_res == WPAD_ERR_OK) {
        WPADAccGravityUnit core1G;

        ((u16*)&core1G)[0] = kp_core_gravity_x;
        ((u16*)&core1G)[1] = kp_core_gravity_y;
        ((u16*)&core1G)[2] = kp_core_gravity_z;
        WPADGetAccGravityUnit(chan, WPAD_DEV_CORE, &core1G);
        if (core1G.x * core1G.y * core1G.z != 0) {
            acc_scale_x = kp_one_g / core1G.x;
            acc_scale_y = kp_one_g / core1G.y;
            acc_scale_z = kp_one_g / core1G.z;
        }

        if (dev_type == WPAD_DEV_FS) {
            WPADAccGravityUnit fs1G;

            ((u16*)&fs1G)[0] = kp_fs_gravity_x;
            ((u16*)&fs1G)[1] = kp_fs_gravity_y;
            ((u16*)&fs1G)[2] = kp_fs_gravity_z;
            WPADGetAccGravityUnit(chan, WPAD_DEV_FS, &fs1G);
            if (fs1G.x * fs1G.y * fs1G.z != 0) {
                acc_scale_fs_x = kp_one_g / fs1G.x;
                acc_scale_fs_y = kp_one_g / fs1G.y;
                acc_scale_fs_z = kp_one_g / fs1G.z;
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
            kp->hard_acc.x = clamp_acc((f32)(s32)-uwp->u.core.accX * acc_scale_x, kp_rm_acc_max);
            kp->hard_acc.y = clamp_acc((f32)(s32)-uwp->u.core.accZ * acc_scale_z, kp_rm_acc_max);
            kp->hard_acc.z = clamp_acc((f32)(s32)uwp->u.core.accY * acc_scale_y, kp_rm_acc_max);
        }
    } else {
        if (probe_res != WPAD_ERR_OK) {
            if (probe_res == WPAD_ERR_NO_CONTROLLER) {
                kp->active_chan -= 4;
                reset_kpad(kp);
                return;
            }
        } else {
            kp->hard_acc.x = clamp_acc(-uwp->u.core.accX * acc_scale_x, kp_rm_acc_max);
            kp->hard_acc.y = clamp_acc(-uwp->u.core.accZ * acc_scale_z, kp_rm_acc_max);
            kp->hard_acc.z = clamp_acc(uwp->u.core.accY * acc_scale_y, kp_rm_acc_max);
        }
    }

    vec = sp->acc;

    calc_acc_horizon(kp, &sp->acc.x, kp->hard_acc.x);
    calc_acc_horizon(kp, &sp->acc.y, kp->hard_acc.y);
    calc_acc_horizon(kp, &sp->acc.z, kp->hard_acc.z);
    sp->acc_value = kp_sqrt(sp->acc.x * sp->acc.x + sp->acc.y * sp->acc.y + sp->acc.z * sp->acc.z);

    vec.x -= sp->acc.x;
    vec.y -= sp->acc.y;
    vec.z -= sp->acc.z;
    sp->acc_speed = kp_sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    calc_acc_vertical(kp);
    read_kpad_acc_head(kp);

    if (dev_type == WPAD_DEV_FS) {
        vec = sp->ex_status.fs.acc;

        calc_acc_horizon(kp, &sp->ex_status.fs.acc.x, clamp_acc(-uwp->u.fs.fsAccX * acc_scale_fs_x, kp_fs_acc_max));
        calc_acc_horizon(kp, &sp->ex_status.fs.acc.y, clamp_acc(-uwp->u.fs.fsAccZ * acc_scale_fs_z, kp_fs_acc_max));
        calc_acc_horizon(kp, &sp->ex_status.fs.acc.z, clamp_acc(uwp->u.fs.fsAccY * acc_scale_fs_y, kp_fs_acc_max));

        sp->ex_status.fs.acc_value = kp_sqrt(sp->ex_status.fs.acc.x * sp->ex_status.fs.acc.x +
                                          sp->ex_status.fs.acc.y * sp->ex_status.fs.acc.y +
                                          sp->ex_status.fs.acc.z * sp->ex_status.fs.acc.z);

        vec.x -= sp->ex_status.fs.acc.x;
        vec.y -= sp->ex_status.fs.acc.y;
        vec.z -= sp->ex_status.fs.acc.z;

        sp->ex_status.fs.acc_speed = kp_sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    }
}
