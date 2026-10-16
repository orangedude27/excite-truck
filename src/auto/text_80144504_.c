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
    s32 *d = (s32 *)dst;
    s32 *s = (s32 *)src;
    int i;
    for (i = 0; i < 12; i++) {
        d[i] = s[i];
    }
}

f32 fn_80144BD8(f32 farg0) {
    if (farg0 < lbl_805615C8) {
        return lbl_805615C8;
    }
    if (farg0 > lbl_805615B8) {
        return lbl_805615B8;
    }
    if (farg0 > lbl_805615BC) {
        return (farg0 * (lbl_805615CC * farg0 * farg0)) + (lbl_805615C4 * farg0 * farg0);
    }
    return (farg0 * (lbl_805615CC * farg0 * farg0)) - (lbl_805615C4 * farg0 * farg0);
}

void fn_80144C54(void *arg0) {
    ((u8 *)arg0)[0x4A] = 1;
    ((u8 *)arg0)[0x4C] = 0;
}

void fn_80144DC8(void) {
}

void fn_80144DD4(void) {
}

