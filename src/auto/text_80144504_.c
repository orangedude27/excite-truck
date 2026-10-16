// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern f32 lbl_805615B8;
extern f32 lbl_805615BC;
extern f32 lbl_805615C4;
extern f32 lbl_805615C8;
extern f32 lbl_805615CC;

void GXInitLightAttnA_80144B44(void *arg0, f32 farg0, f32 farg1, f32 farg2) {
    ((f32 *)arg0)[0] = farg0;
    ((f32 *)arg0)[1] = farg1;
    ((f32 *)arg0)[2] = farg2;
}

void fn_80144B54(void *dst, void *src) {
    s32 a, b, c, d, e, f, g, h, i, j, k, l;
    a = ((s32 *)src)[0];
    b = ((s32 *)src)[1];
    c = ((s32 *)src)[2];
    d = ((s32 *)src)[3];
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
    if (farg0 < lbl_805615C8) {
        return lbl_805615C8;
    }
    if (farg0 > lbl_805615B8) {
        return lbl_805615B8;
    }
    if (farg0 > lbl_805615BC) {
        return (farg0 * farg0 * lbl_805615C4) + (farg0 * farg0 * farg0 * lbl_805615CC);
    }
    return (farg0 * farg0 * lbl_805615C4) - (farg0 * farg0 * farg0 * lbl_805615CC);
}

void fn_80144C54(void *arg0) {
    ((u8 *)arg0)[0x4A] = 1;
    ((u8 *)arg0)[0x4C] = 0;
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

