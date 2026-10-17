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
extern u32 fn_80230AB8(u8 *, u8 *, u8 *, u8 *);
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

s32 fn_80230B9C(void) {
    extern u32 fn_80230AB8(u8 *, u8 *, u8 *, u8 *);
    extern void *fn_8022EDC4(void);
    extern f64 lbl_80563650;
    u8 a=0, b=0, c=0, d=0;
    f32 scale;
    fn_80230AB8(&a, &b, &c, &d);
    scale = *(f32 *)((u8 *)fn_8022EDC4() + 0x30);
    return d | (c << 8) | (b << 16) | ((s32)(((f64)a - lbl_80563650) * scale) << 24);
}

void fn_80230C30(float *arg0, float *arg1, s32 arg2, s32 arg3) {
    *arg0 = (float)(arg2 - (s32)(((lbl_8055FB9C >> 31) + lbl_8055FB9C) >> 1));
    *arg1 = (float)((s32)(((lbl_8055FBA0 >> 31) + lbl_8055FBA0) >> 1) - arg3);
}

void fn_80230DA0(void) {}

void fn_80230DA4(float a, float b) {
    float value;
    lbl_8055F030 = a;
    value = (float)fn_8002EFB4();
    if (value < lbl_80563614) value += b;
    lbl_8055F02C = b - value;
}

float fn_80230DF4(float a, float b) {
    float value = (float)fn_8002EFB4(a + lbl_8055F02C);
    if (value < lbl_80563614) value += b;
    value /= b;
    if (value < lbl_8056365C) value = lbl_80563610 - value;
    return value;
}

void fn_80230E54(float a, float b) {}

extern f32 lbl_80563610, lbl_80563638, lbl_80563640, lbl_80563648;
extern u32 lbl_8055FB9C, lbl_8055FBA0;
s32 fn_802E2C20(void);
void fn_80230E54(float, float);
void fn_8023659C(void);
void fn_80230F6C(s32 *arg0) { *arg0 = -0x35BC; }

void fn_8023108C(u8 arg0) {
    lbl_8055B998 = arg0;
}

void fn_80231380(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    f32 *p = (f32 *)arg0;
    p[0] = farg0; p[1] = farg1; p[2] = farg2;
    *(s32 *)(p + 3) = arg1;
    p[4] = farg3; p[5] = farg4;
}

