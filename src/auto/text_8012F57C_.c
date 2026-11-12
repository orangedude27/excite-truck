// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma processor gekko
#pragma paired off
#pragma paired_single off
extern double sin(double);
extern double fabs(double);
extern double __fabs(double);
extern double fn_8002F234(float);
extern double fn_8002EFB0(float, float);
extern float lbl_805612B8;
extern float lbl_805612BC;
extern float lbl_805612C0;
extern float lbl_80558DC4[];
#define lbl_80558DC4 lbl_80558DC4[0]

#pragma push
#pragma processor 750
void fn_8012F57C(float *out, float *a, float *b, float t) {
    float qb[4];
    float qa[4];
    float d, s, ang, inv, w, u;
    float a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
    d = a3 * b[3] + a0 * b[0] + a1 * b[1] + a2 * b[2];
    if (d < lbl_805612B8) {
        d = -d;
        a0 = a0 * lbl_805612BC;
        a1 = a1 * lbl_805612BC;
        a2 = a2 * lbl_805612BC;
        a3 = a3 * lbl_805612BC;
        a[0] = a0;
        a[1] = a1;
        a[2] = a2;
        a[3] = a3;
    }
    s = fn_8002F234(__fabs(lbl_805612C0 - d * d));
    if ((float)__fabs(s) < lbl_80558DC4) {
        out[0] = a[0];
        out[1] = a[1];
        out[2] = a[2];
        out[3] = a[3];
        return;
    }
    ang = fn_8002EFB0(s, d);
    inv = lbl_805612C0 / s;
    w = inv * sin((lbl_805612C0 - t) * ang);
    u = inv * sin(t * ang);
    qa[0] = a[0] * w;
    qa[1] = a[1] * w;
    qa[2] = a[2] * w;
    qa[3] = a[3] * w;
    qb[0] = b[0] * u;
    qb[1] = b[1] * u;
    qb[2] = b[2] * u;
    qb[3] = b[3] * u;
    out[0] = qa[0] + qb[0];
    out[1] = qa[1] + qb[1];
    out[2] = qa[2] + qb[2];
    out[3] = qa[3] + qb[3];
    s = out[3] * out[3] + out[2] * out[2] + out[1] * out[1] + out[0] * out[0];
    if ((float)__fabs(s) > lbl_80558DC4) {
        s = lbl_805612C0 / fn_8002F234(s);
        out[0] = out[0] * s;
        out[1] = out[1] * s;
        out[2] = out[2] * s;
        out[3] = out[3] * s;
    }
}
#pragma pop
