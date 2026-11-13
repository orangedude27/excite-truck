#include "types.h"
#include "revolution/MTX/vec.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern f32 lbl_80563E20;
extern f32 lbl_80563E24;
extern f32 lbl_80563E2C;
extern f32 lbl_80563E28;
extern double fn_8002F234(double);
extern void fn_8012F57C(float *, float *, float *, float);

static inline void mtx_to_quat(float m[3][3], float *q) {
    float sum = m[0][0] + m[1][1] + m[2][2];
    float sn, inv;
    int i, j, k;
    if (sum > lbl_80563E20) {
        sn = (float)fn_8002F234(lbl_80563E24 + sum);
        inv = lbl_80563E28 / sn;
        q[3] = lbl_80563E28 * sn;
        q[0] = inv * (m[1][2] - m[2][1]);
        q[1] = inv * (m[2][0] - m[0][2]);
        q[2] = inv * (m[0][1] - m[1][0]);
    } else {
        i = 0;
        if (m[1][1] > m[0][0]) i = 1;
        if (m[2][2] > m[0][i]) i = 2;
        j = (i + 1) % 3;
        k = (j + 1) % 3;
        sn = (float)fn_8002F234(lbl_80563E24 + (m[i][i] - (m[j][j] + m[k][k])));
        inv = lbl_80563E28 / sn;
        q[i] = lbl_80563E28 * sn;
        q[3] = inv * (m[j][k] - m[k][j]);
        q[j] = inv * (m[i][j] + m[j][i]);
        q[k] = inv * (m[i][k] + m[k][i]);
    }
}
extern float __fabsf(float);
extern double fabs(double);
extern double __fabs(double);
#pragma scheduling invalid_target
void fn_8026E688(f32* arg0, f32* arg1, f32* arg2, f32* arg3) {
    volatile f32 delta[3];
    f32 z[3];
    f32 y[3];
    f32 x[3];
    volatile f32* inputA = (volatile f32*)arg1;
    volatile f32* inputB = (volatile f32*)arg2;
    volatile f32* matrix = (volatile f32*)arg0;
    f32 px, py, pz, qx, qy, qz;
    f32 dx, dy, dz;
    f32 one, zero;
    f32 x0, x1, x2, z0, z1, z2;

    px = inputA[0];
    qx = inputB[0];
    py = inputA[1];
    dx = qx - px;
    pz = inputA[2];
    qy = inputB[1];
    qz = inputB[2];
    dy = qy - py;
    ((volatile f32*)arg0)[9] = px;
    dz = qz - pz;
    ((volatile f32*)arg0)[10] = py;
    ((volatile f32*)arg0)[11] = pz;
    delta[0] = dx;
    delta[1] = dy;
    delta[2] = dz;

    one = lbl_80563E24;
    matrix[0] = one;
    zero = lbl_80563E20;
    matrix[1] = zero;
    matrix[2] = zero;
    matrix[3] = zero;
    matrix[4] = one;
    matrix[5] = zero;
    matrix[6] = zero;
    matrix[7] = zero;
    matrix[8] = one;

    if (PSVECDotProduct((Vec*)delta, (Vec*)delta) < lbl_80563E24) {
        return;
    }
    if (lbl_80563E2C > (f32)__fabs((double)delta[0]) &&
        lbl_80563E2C > (f32)__fabs((double)delta[2])) {
        return;
    }
    matrix[6] = delta[0];
    matrix[7] = delta[1];
    matrix[8] = delta[2];
    PSVECCrossProduct((Vec*)arg3, (Vec*)&matrix[6], (Vec*)matrix);
    PSVECCrossProduct((Vec*)&matrix[6], (Vec*)matrix, (Vec*)&matrix[3]);
    x2 = matrix[2]; x1 = matrix[1]; x0 = matrix[0];
    x[0] = x0; x[1] = x1; x[2] = x2;
    z2 = matrix[8]; z1 = matrix[7]; z0 = matrix[6];
    z[0] = z0; z[1] = z1; z[2] = z2;
    PSVECCrossProduct((Vec*)z, (Vec*)x, (Vec*)y);
    PSVECNormalize((Vec*)x, (Vec*)x);
    PSVECNormalize((Vec*)y, (Vec*)y);
    PSVECCrossProduct((Vec*)x, (Vec*)y, (Vec*)z);
    matrix[0] = x[0]; matrix[1] = x[1]; matrix[2] = x[2];
    matrix[3] = y[0]; matrix[4] = y[1]; matrix[5] = y[2];
    matrix[6] = z[0]; matrix[7] = z[1]; matrix[8] = z[2];
}

void fn_8026E850(f32* arg0, f32* arg1, f32* arg2, f32* arg3) {
    fn_8026E688(arg2 + 22, arg0, arg1, arg3);
}

#pragma scheduling on
