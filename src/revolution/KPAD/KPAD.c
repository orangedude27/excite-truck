#include <revolution/KPAD/__KPAD.h>

/* REXE01's local sqrt thunk is declared by the private KPAD header. */
/* REXE01's symbol table names this private helper KPADSetSensorHeight. */
void KPADSetSensorHeight(KPADInsideStatus* kp) {
    f32 sx;
    f32 sy;

    sx = 1.0f;
    sy = 0.75f;
    kp->dpd2pos_scale = (f32)fn_8002F234((f64)(sx * sx + sy * sy));

    if (kp->center_org.x < 0.0f) {
        sx += kp->center_org.x;
    } else {
        sx -= kp->center_org.x;
    }

    if (kp->center_org.y < 0.0f) {
        sy += kp->center_org.y;
    } else {
        sy -= kp->center_org.y;
    }

    if (sx < sy) {
        kp->dpd2pos_scale /= sx;
    } else {
        kp->dpd2pos_scale /= sy;
    }
}
