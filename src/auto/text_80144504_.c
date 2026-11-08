// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern f32 lbl_805615B8;
extern f32 lbl_805615BC;
extern f32 lbl_805615C0;
extern f32 lbl_805615C4;
extern f32 lbl_805615C8;
extern f32 lbl_805615CC;

extern double cos(double);
extern double sin(double);
extern float fn_80144514(float, float, float, float, float, float);
#define D6(a, b, c, d, e, f) fn_80144514(a, b, c, d, e, f)
#define M33CAT(a, b, ab)                                                   \
    if ((ab) == (a) || (ab) == (b)) {                                      \
        f32 t0 = D6((a)[0], (b)[0], (a)[3], (b)[1], (a)[6], (b)[2]);       \
        f32 t3 = D6((a)[0], (b)[3], (a)[3], (b)[4], (a)[6], (b)[5]);       \
        f32 t6 = D6((a)[0], (b)[6], (a)[3], (b)[7], (a)[6], (b)[8]);       \
        f32 t1 = D6((a)[1], (b)[0], (a)[4], (b)[1], (a)[7], (b)[2]);       \
        f32 t4 = D6((a)[1], (b)[3], (a)[4], (b)[4], (a)[7], (b)[5]);       \
        f32 t7 = D6((a)[1], (b)[6], (a)[4], (b)[7], (a)[7], (b)[8]);       \
        f32 t2 = D6((a)[2], (b)[0], (a)[5], (b)[1], (a)[8], (b)[2]);       \
        f32 t5 = D6((a)[2], (b)[3], (a)[5], (b)[4], (a)[8], (b)[5]);       \
        f32 t8 = D6((a)[2], (b)[6], (a)[5], (b)[7], (a)[8], (b)[8]);       \
        (ab)[0] = t0; (ab)[3] = t3; (ab)[6] = t6;                          \
        (ab)[1] = t1; (ab)[4] = t4; (ab)[7] = t7;                          \
        (ab)[2] = t2; (ab)[5] = t5; (ab)[8] = t8;                          \
    } else {                                                               \
        (ab)[0] = D6((a)[0], (b)[0], (a)[3], (b)[1], (a)[6], (b)[2]);      \
        (ab)[3] = D6((ab)[0], (b)[3], (a)[3], (b)[4], (a)[6], (b)[5]);     \
        (ab)[6] = D6((ab)[0], (b)[6], (ab)[3], (b)[7], (a)[6], (b)[8]);    \
        (ab)[1] = D6((a)[1], (b)[0], (a)[4], (b)[1], (a)[7], (b)[2]);      \
        (ab)[4] = D6((ab)[1], (b)[3], (a)[4], (b)[4], (a)[7], (b)[5]);     \
        (ab)[7] = D6((ab)[1], (b)[6], (ab)[4], (b)[7], (a)[7], (b)[8]);    \
        (ab)[2] = D6((a)[2], (b)[0], (a)[5], (b)[1], (a)[8], (b)[2]);      \
        (ab)[5] = D6((ab)[2], (b)[3], (a)[5], (b)[4], (a)[8], (b)[5]);     \
        (ab)[8] = D6((ab)[2], (b)[6], (ab)[5], (b)[7], (a)[8], (b)[8]);    \
    }

extern void lbl_80336890(void);
void fn_80144504(void **arg0) {
    *arg0 = (void *)&lbl_80336890;
}

float fn_80144514(float farg0, float farg1, float farg2, float farg3, float farg4, float farg5) {
    return (farg4 * farg5) + ((farg0 * farg1) + (farg2 * farg3));
}

void GXInitLightAttnA_80144B44(void *arg0, f32 farg0, f32 farg1, f32 farg2) {
    ((f32 *)arg0)[0] = farg0;
    ((f32 *)arg0)[1] = farg1;
    ((f32 *)arg0)[2] = farg2;
}

void fn_80144B54(void *dst, void *src) {
    s32 a, b, c, d, e, f, g, h, i, j, k, l;
    d = ((s32 *)src)[3];
    c = ((s32 *)src)[2];
    b = ((s32 *)src)[1];
    a = ((s32 *)src)[0];
    e = ((s32 *)src)[4];
    f = ((s32 *)src)[5];
    g = ((s32 *)src)[6];
    h = ((s32 *)src)[7];
    i = ((s32 *)src)[8];
    j = ((s32 *)src)[9];
    k = ((s32 *)src)[10];
    l = ((s32 *)src)[11];
    ((s32 *)dst)[0] = a;
    ((s32 *)dst)[1] = b;
    ((s32 *)dst)[2] = c;
    ((s32 *)dst)[3] = d;
    ((s32 *)dst)[4] = e;
    ((s32 *)dst)[5] = f;
    ((s32 *)dst)[6] = g;
    ((s32 *)dst)[7] = h;
    ((s32 *)dst)[8] = i;
    ((s32 *)dst)[9] = j;
    ((s32 *)dst)[10] = k;
    ((s32 *)dst)[11] = l;
}

f32 fn_80144BD8(f32 farg0) {
    f32 c4, cc;
    if (farg0 < lbl_805615C8) return lbl_805615C8;
    if (farg0 > lbl_805615B8) return lbl_805615B8;
    if (farg0 > lbl_805615BC) {
        c4 = lbl_805615C4;
        cc = lbl_805615CC;
        cc *= farg0;
        c4 *= farg0;
        cc *= farg0;
        c4 *= farg0;
        farg0 *= cc;
        return farg0 + c4;
    }
    c4 = lbl_805615C4;
    cc = lbl_805615CC;
    cc *= farg0;
    c4 *= farg0;
    cc *= farg0;
    c4 *= farg0;
    farg0 *= cc;
    return farg0 - c4;
}

void fn_80144C54(void *arg0) {
    ((u8 *)arg0)[0x4A] = 1;
    ((u8 *)arg0)[0x4C] = 0;
}

unsigned int fn_80144C68(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    unsigned int y = arg1;
    unsigned int x = arg2;
    x = (x << 8) & 0xFF00;
    y = (y << 16) & 0xFF0000;
    x |= arg3;
    y |= arg0 >> 24;
    return x | y;
}
#pragma scheduling invalid_target
#pragma scheduling on
float fn_80144C80(float farg0, float farg1, float farg2) {
    return farg0 + (farg2 * (farg1 - farg0));
}

extern f32 lbl_805615C0;
#pragma push
#pragma scheduling invalid_target
s32 fn_80144C90(f32 farg0) {
    f32 x;
    f32 t = lbl_805615BC;
    if (farg0 < t) {
        x = farg0 - lbl_805615C0;
    } else {
        x = lbl_805615C0 + farg0;
    }
    return (s32)x;
}
#pragma pop
f32 fn_80144CC8(f32 farg0) {
    return farg0 * farg0;
}

#pragma push
#pragma scheduling invalid_target
void fn_80144CD0(f32 *out, f32 *vec, f32 (*m)[4]) {
    f32 x = vec[0] - m[2][1];
    f32 y = vec[1] - m[2][2];
    f32 o0 = x * m[0][0] + y * m[0][1];
    f32 o1 = x * m[0][3] + y * m[1][0];
    f32 o2 = x * m[1][2] + y * m[1][3];
    f32 z = vec[2] - m[2][3];
    o1 += z * m[1][1];
    o0 += z * m[0][2];
    o2 += z * m[2][0];
    out[1] = o1;
    out[0] = o0;
    out[2] = o2;
}
#pragma pop
void fn_80144D64(s32 *dst, s32 *src) {
 s32 c, b, a;
 volatile s32 *p = src;
 a = p[0]; b = p[1]; c = p[2];
 dst[0] = a; dst[1] = b; dst[2] = c;
}

void fn_80144D80(f32 *arg0, f32 farg0, f32 farg1, f32 farg2) {
    f32 z = lbl_805615BC;
    arg0[0] = farg0;
    arg0[1] = z;
    arg0[2] = z;
    arg0[3] = z;
    arg0[4] = farg1;
    arg0[5] = z;
    arg0[6] = z;
    arg0[7] = z;
    arg0[8] = farg2;
}

void fn_80144DAC(f32 *arg0, f32 *arg1) {
    f32 c, b, a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
}

void fn_80144DC8(void) {
}

s32 fn_80144DCC(void) {
    return 0;
}

void fn_80144DD4(void) {
}

s32 fn_80144DD8(void) {
    return 0;
}

