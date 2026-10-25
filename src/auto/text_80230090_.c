#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055B998;
extern f32 lbl_8055F02C;
extern f32 lbl_8055F030;
extern f32 lbl_80563610;
extern f32 lbl_80563638;
extern f32 lbl_80563640;
extern f32 lbl_80563648;
extern u32 lbl_8055FB9C;
extern u32 lbl_8055FBA0;
extern f32 lbl_80563614;
extern f32 lbl_8056365C;
extern f32 lbl_80563660;
f64 fn_8002EFB4();
extern void fn_80230AB8(u32, u8 *, u8 *, u8 *, u8 *);
extern void *fn_8022EDC4(void);
extern f64 lbl_80563650;
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern f32 lbl_80563640, lbl_80563644;
extern void fn_802C87B4(s32, s32, s32, s32);
extern void fn_802C88BC(s32);
extern void fn_802C8530(void);
extern void fn_802C8638(s32);
extern void fn_802C974C(f32, f32, f32);
void fn_80230090(void) {
    extern s32 lbl_8055F028;
    extern f32 lbl_80563610, lbl_80563614;
    extern s32 fn_80129C64(s32);
    extern void fn_8022EB90(void);
    extern s32 fn_8022EDE4(f32 *, f32);
    extern void fn_8022ED00(void);
    extern void fn_802321D8(void);
    extern void fn_8022F248(void);
    extern void fn_8023509C(void);
    extern void fn_802365D8(void);
    extern void fn_80236728(void);
    f32 values[12];
    fn_80129C64(2);
    fn_8022EB90();
    values[0]=lbl_80563610; values[1]=lbl_80563614; values[2]=lbl_80563614;
    values[3]=lbl_80563614; values[4]=lbl_80563610; values[5]=lbl_80563614;
    values[6]=lbl_80563614; values[7]=lbl_80563614; values[8]=lbl_80563610;
    values[9]=lbl_80563614; values[10]=lbl_80563614; values[11]=lbl_80563614;
    lbl_8055F028=fn_8022EDE4(values,lbl_80563610);
    fn_8022ED00(); fn_802321D8(); fn_8022F248(); fn_8023509C();
    fn_802365D8(); fn_80236728();
}

void fn_80230114(void) {
    extern s32 lbl_8055F028;
    extern void fn_8022EDB8(void);
    extern void fn_8022EB30(s32);
    extern void fn_80236774(void);
    extern void fn_802350BC(void);
    extern void fn_8022F294(void);
    extern void fn_802324D8(void);
    extern void fn_8022EBF0(void);
    fn_8022EDB8();
    fn_8022EB30(lbl_8055F028);
    fn_80236774(); fn_802350BC(); fn_8022F294();
    fn_802324D8(); fn_8022EBF0();
}

void fn_80230A68(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    u32 *p = (u32 *)arg0;
    p[0] = *(u32 *)&farg0;
    p[1] = *(u32 *)&farg1;
    p[2] = *(u32 *)&farg2;
    p[3] = arg1;
    p[4] = *(u32 *)&farg3;
    p[5] = *(u32 *)&farg4;
}

void fn_80230AB8(u32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    *arg1 = (u8)(arg0 >> 24);
    *arg2 = (u8)(arg0 >> 16);
    *arg3 = (u8)(arg0 >> 8);
    *arg4 = (u8)arg0;
}

void fn_80230AD8(s32 arg0) {
    fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802C88BC(3);
    fn_802C8530();
    fn_802C8638(arg0);
    fn_802C974C(lbl_80563610, lbl_80563640, lbl_80563644);
}

void fn_80230B38(void* alarm) {
    fn_802C2B48(fn_802C855C(alarm));
}

void fn_80230B5C(void *arg0) {
    extern f32 lbl_8056364C;
    f32 *p = (f32 *)arg0;
    f32 a = lbl_80563614;
    f32 b = lbl_80563610;
    f32 c = lbl_8056364C;
    p[0]=b; p[3]=a; p[2]=a; p[1]=a;
    p[4]=b; p[7]=a; p[6]=a; p[5]=a;
    p[8]=b; p[9]=a; p[10]=a; p[11]=c;
}

s32 fn_80230B9C(u32 arg0) {
    extern void *fn_8022EDC4(void);
    extern f64 lbl_80563650;
    u8 a=0, b=0, c=0, d=0;
    f32 scale;
    fn_80230AB8(arg0, &a, &b, &c, &d);
    scale = *(f32 *)((u8 *)fn_8022EDC4() + 0x30);
    return d | (c << 8) | (b << 16) | ((s32)(((f64)a - lbl_80563650) * scale) << 24);
}

void fn_80230C30(float *arg0, float *arg1, s32 arg2, s32 arg3) {
    *arg0 = (float)(arg2 - (s32)(((lbl_8055FB9C >> 31) + lbl_8055FB9C) >> 1));
    *arg1 = (float)((s32)(((lbl_8055FBA0 >> 31) + lbl_8055FBA0) >> 1) - arg3);
}

/* Match note: preserve the branch-specific min/max and truncating step count; this matches the target exactly. */
void fn_80230C9C(float *arg0, float *arg1, float farg0, float farg1, float farg2) {
    float var_f0, var_f0_2, var_f4, var_f5;
    int temp_r0, temp_r0_2;
    var_f4 = *arg0;
    var_f5 = *arg1;
    if ((var_f4 < farg0) && (var_f5 < farg0)) {
        if (var_f4 > var_f5) var_f0 = var_f4;
        else var_f0 = var_f5;
        temp_r0 = (int)((farg0 - var_f0) / farg2) + 1;
        var_f4 += (float)temp_r0 * farg2;
        var_f5 += (float)temp_r0 * farg2;
    } else if ((var_f4 > farg1) && (var_f5 > farg1)) {
        if (var_f4 < var_f5) var_f0_2 = var_f4;
        else var_f0_2 = var_f5;
        temp_r0_2 = (int)((var_f0_2 - farg1) / farg2) + 1;
        var_f4 -= (float)temp_r0_2 * farg2;
        var_f5 -= (float)temp_r0_2 * farg2;
    }
    *arg0 = var_f4;
    *arg1 = var_f5;
}

void fn_80230DA0(void) {}

void fn_80230DA4(float a, float b) {
    float value;
    lbl_8055F030 = a;
    value = (float)fn_8002EFB4();
    if (value < lbl_80563614) value += b;
    lbl_8055F02C = b - value;
}

#pragma dont_inline on
float fn_80230DF4(float a, float b) {
    float value = (float)fn_8002EFB4(a + lbl_8055F02C);
    if (value < lbl_80563614) value += b;
    value /= b;
    if (value < lbl_8056365C) value = lbl_80563610 - value;
    return value;
}
#pragma dont_inline reset

float fn_80230E54(float a, float b) {
    float value;

    b = (b > lbl_80563660) ? b : lbl_80563660;
    value = (a - lbl_8055F030) / b;
    if (value < lbl_8056365C) {
        return value;
    }
    return fn_80230DF4(a, b);
}

extern f32 lbl_80563610, lbl_80563638, lbl_80563640, lbl_80563648;
extern u32 lbl_8055FB9C, lbl_8055FBA0;
s32 fn_802E2C20(void);
float fn_80230E54(float, float);
void fn_8023659C(void);
void fn_80230F6C(s32 *arg0) { *arg0 = -0x35BC; }

extern float fn_80230EF4(long);
extern float lbl_80563610, lbl_80563614, lbl_80563658, lbl_80563664, lbl_80563668, lbl_8056366C;
void fn_80230F78(signed char *arg0, float *arg1, long arg2, long arg3) {
    float value, max, min;
    long n, clipped;
    value = fn_80230EF4(arg3);
    max = lbl_80563610;
    min = (value - lbl_80563614) / lbl_80563658;
    if (max >= min) max = min;
    if (max <= lbl_80563614) max = lbl_80563614;
    n = (long)(lbl_80563664 + max * lbl_80563668);
    clipped = n & ((-n & ~n) >> 31);
    if (clipped >= 0xFF) clipped = 0xFF;
    *arg0 = (signed char)clipped;
    min = (value - lbl_80563614) / lbl_80563658;
    max = lbl_80563610;
    if (max >= min) max = min;
    if (max <= lbl_80563614) max = lbl_80563614;
    *arg1 = lbl_80563614 + max * lbl_8056366C;
    fn_80230F6C((long *)arg2);
}

void fn_8023108C(u8 arg0) {
    lbl_8055B998 = arg0;
}

extern s32 fn_802C9A58(void);
extern s32 fn_802C9A60(void);
extern s32 fn_802C9A68(void);
extern f32 lbl_8055D020, lbl_80563610, lbl_80563614, lbl_8056365C;
extern f32 lbl_80563670, lbl_80563674, lbl_80563678, lbl_8056367C;
void fn_80231094(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    f32 f0, f1, f2, f3, f4;
    s32 r5, r6;
    if (fn_802C9A68()) f2 = lbl_80563670;
    else f2 = lbl_80563674;
    f0 = lbl_80563610;
    f1 = lbl_80563678;
    f3 = f0 - f2;
    f0 = lbl_8056367C;
    f2 = lbl_8056365C;
    f1 = f1 * f3;
    f0 = f0 * f3;
    f1 = f2 * f1;
    f0 = f2 * f0;
    f1 = f2 + f1;
    f0 = f2 + f0;
    r5 = (s32)f1;
    r6 = (s32)f0;
    *arg2 = r5;
    *arg3 = r5;
    *arg0 = r6;
    *arg1 = r6;
    *arg2 = 0xF;
    *arg3 = 0xF;
    *arg0 = 0x18;
    *arg1 = 4;
    if (!fn_802C9A60() && fn_802C9A58()) {
        f4 = lbl_80563610;
        f0 = lbl_8055D020;
        f2 = lbl_80563678;
        f3 = f4 / f0;
        f1 = lbl_8056365C;
        f0 = lbl_80563614;
        f3 = f3 - f4;
        f2 = f2 * f3;
        f2 = f1 * f2;
        if (f2 < f0) f0 = f2 - f1;
        else f0 = f1 + f2;
        *arg2 -= (s32)f0;
        f3 = f4 / lbl_8055D020;
        f3 = f3 - f4;
        f2 = lbl_80563678 * f3;
        f2 = f1 * f2;
        if (f2 < lbl_80563614) f0 = f2 - f1;
        else f0 = f1 + f2;
        *arg3 -= (s32)f0;
    }
}

void fn_80231380(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    f32 *p = (f32 *)arg0;
    p[0] = farg0; p[1] = farg1; p[2] = farg2;
    *(s32 *)(p + 3) = arg1;
    p[4] = farg3; p[5] = farg4;
}

