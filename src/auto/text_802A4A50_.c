// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned long u32;
typedef signed long s32;
typedef float f32;
void fn_802C2C00(s32);
void *fn_801E1F44(void);
void fn_802C2C00(s32);
s32 fn_802C990C(s32);
s32 fn_802C2B78(f32, f32, f32);
f32 fn_802A4A50(void);
s32 fn_802A6A7C(void);
s32 fn_802A5CA4(void);
s32 fn_802A5A38(void);
extern s32 lbl_8055F888;
extern s32 lbl_8055F88C;
extern f32 lbl_8055F8A0;
s32 fn_802A6A44(void);
s32 fn_802A5C1C(void);
void fn_802A59E0(void);
extern s32 lbl_8055F894, lbl_8055F898, lbl_8055F89C;
extern u8 lbl_80349BF0[], lbl_8055CBC8;
s32 fn_802C6CF8(void);
s32 fn_802CAC54(s32);
s32 fn_802A597C(void);
s32 fn_8028E398(void);
s32 fn_802A5B8C(s32);
s32 fn_802A69D8(s32);
s32 fn_800167F4(void);
s32 fn_802A5384(s32);
s32 fn_802A53B0(void);
s32 fn_80287B38(void *);
s32 fn_802A5878(void);
s32 fn_802CAC28(void *, s32);
void *fn_802AE414(void *);
s32 fn_802C6FC0(void *, s32, s32);
s32 fn_800216F4(void);
f32 fn_801E7E24(void);
s32 fn_802E2C20(void);
extern s32 lbl_8055F8A4;
extern f32 lbl_80564840, lbl_80564844;
f32 fn_802A4A50(void) {
    f32 value;
    s32 now;
    s32 delta;
    if (fn_800216F4() != 0) {
        now = fn_802E2C20();
        delta = now - lbl_8055F8A4;
        value = lbl_80564844;
        lbl_8055F8A4 = now;
        if ((f32)delta / lbl_80564840 < value)
            return (f32)delta / lbl_80564840;
        return value;
    }
    return fn_801E7E24();
}

void fn_802A4ADC(void) {
    s32 temp = (s32)fn_801E1F44();
    void *var_r30;
    if (fn_800167F4() == 1) fn_802A5384(temp);
    fn_80287B38((void *)fn_802A53B0);
    fn_802A5878();
    lbl_8055F89C = fn_802CAC28(lbl_80349BF0 + 0x28, 0);
    var_r30 = lbl_80349BF0 + 0x38;
    {
       void **p = fn_802AE414(&lbl_8055CBC8);
       if (p != 0) var_r30 = ((void *(*)(void *, void *))(*(u32 *)((u8 *)*p + 0x18)))(lbl_80349BF0 + 0x48, var_r30);
    }
    lbl_8055F898 = fn_802C6FC0(var_r30, 0, 0);
}

void fn_802A4B90(void) {
    if (lbl_8055F898 != -1) { fn_802C6CF8(); lbl_8055F898 = -1; }
    fn_802CAC54(lbl_8055F89C); fn_802A597C();
    if (lbl_8055F894 != 0) { fn_8028E398(); lbl_8055F894 = 0; }
    if (lbl_8055F888 != 0) { fn_802A5B8C(1); lbl_8055F888 = 0; }
    if (lbl_8055F88C != 0) { fn_802A69D8(1); lbl_8055F88C = 0; }
}

void fn_802A4C20(void) {
    s32 flag;
    flag = lbl_8055F88C;
    if (flag != 0) fn_802A6A44();
    flag = lbl_8055F888;
    if (flag != 0) fn_802A5C1C();
    fn_802A59E0();
}

void fn_802A4C60(void) {
    lbl_8055F8A0 = fn_802A4A50();
    if (lbl_8055F88C != 0) fn_802A6A7C();
    if (lbl_8055F888 != 0) fn_802A5CA4();
    fn_802A5A38();
}

void fn_802A4CA8(void) {
    u8 *p = (u8 *)fn_801E1F44();
    if (p[0x18] != 0) {
        fn_802C2C00(1);
        fn_802C990C(*(s32 *)(p + 8));
        fn_802C2B78(*(f32 *)(p + 0xC), *(f32 *)(p + 0x10), *(f32 *)(p + 0x14));
    }
}

void fn_802A4D00(void) { fn_802C2C00(0); }

extern f32 lbl_80564858, lbl_8056485C, lbl_80564878;
extern s32 lbl_80349C94;
s32 fn_801284F8(s32, s32 *);
s32 fn_802A5AE8(s32, s32);
void fn_802A52FC(f32 arg0) {
    f32 value = lbl_8056485C;
    s32 result;
    s32 amount;
    if (value >= arg0) value = arg0;
    if (value <= lbl_80564858) value = lbl_80564858;
    amount = (s32)(lbl_80564878 * value);
    result = fn_801284F8(0xBC, &lbl_80349C94);
    if (result != 0) result = fn_802A5AE8(amount, 0);
    lbl_8055F888 = result;
}

extern s32 lbl_804BCFA8[];
extern s32 lbl_8055F890;
s32 fn_802A7680(s32);
s32 fn_802A5B8C(s32 arg0) {
    return arg0;
}

f32 fn_80129DC4(s32, f32, f32);
extern f32 lbl_80564894, lbl_80564898;
f32 fn_802A4AD4(void);
f32 fn_80287BC8(f32, f32);
extern f32 lbl_80558DC4, lbl_805648A4, lbl_805648A8;
void fn_802A6408(void *arg0) {
    if (__fabsf(fn_802A4AD4()) > lbl_80558DC4) {
        *(f32 *)((u8 *)arg0 + 0x14) = fn_80287BC8(lbl_805648A4, lbl_805648A8);
        *(f32 *)((u8 *)arg0 + 0x18) = fn_80287BC8(lbl_805648A4, lbl_805648A8);
    }
}

void fn_802A6758(void *arg0, f32 *arg1) {
    u8 *dst = *(u8 **)arg0 + (*(s32 *)((u8 *)arg0 + 4) * 0xC);
    f32 x = arg1[0];
    f32 y = arg1[1];
    f32 z = arg1[2];
    *(f32 *)dst = x;
    *(f32 *)(dst + 4) = y;
    *(f32 *)(dst + 8) = z;
    *(s32 *)((u8 *)arg0 + 4) += 1;
}

void fn_802A6790(void *arg0) {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 temp_f1;
    f32 temp_f29;
    f32 temp_f31;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    while (*(s32 *)((u8 *)arg0 + 4) < *(s32 *)((u8 *)arg0 + 8)) {
        temp_f1 = fn_80287BC8(*(f32 *)((u8 *)arg0 + 0x24), *(f32 *)((u8 *)arg0 + 0x28));
        temp_f29 = *(f32 *)((u8 *)arg0 + 0x20) * temp_f1;
        temp_f31 = fn_80287BC8(-temp_f29, temp_f29);
        sp8 = temp_f31;
        spC = fn_80287BC8(-temp_f29, temp_f29);
        sp10 = temp_f1;
        fn_802A6758(arg0, &sp8);
    }
}

extern float fn_80287BC8(float, float);
extern void fn_802A70E4(void *, float *);
extern s32 fn_802CAC54(s32);
extern s32 fn_80128670(s32);
extern s32 fn_80128668(void *);
void *fn_802A7614(void *arg0, s32 arg1) {
    s32 temp;
    if (arg0 != 0) {
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x2C));
        temp = *(s32 *)arg0;
        if (temp != 0) fn_80128670(temp - 0x10);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

