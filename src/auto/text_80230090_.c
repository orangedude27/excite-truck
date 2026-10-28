#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055B998;
extern f32 lbl_8055F02C;
extern f32 lbl_8055F030;
extern f32 lbl_80563610;
extern f64 lbl_80563638;
extern f32 lbl_80563640;
extern f32 lbl_80563648;
extern u32 lbl_8055FB9C;
extern u32 lbl_8055FBA0;
extern f32 lbl_80563614;
extern f32 lbl_8056365C;
extern f32 lbl_80563660;
f64 fn_8002EFB4();
extern f32 fn_8023659C();
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

extern f32 lbl_8056362C;
extern f32 lbl_80563630;
extern f32 fn_8023293C(s32, s32, f32);
extern void fn_80230C9C(f32 *, f32 *, f32, f32, f32);
extern void fn_80233354(s32, s32, s32, s32, f32, f32, f32, f32);
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
void fn_80230650(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                 f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                 f32 farg4, f32 farg5, f32 farg6, s32 arg_sp0) {
    f32 spC, sp8;
    f32 temp_f1, temp_f3, temp_f4;
    f32 temp_f31, temp_f28, temp_f27, temp_f26;
    f32 var_f2;
    s32 var_r0;

    (void)arg_sp0;
    temp_f31 = farg3;
    temp_f1 = fn_8023293C(arg1, arg0, lbl_80563610);
    temp_f3 = farg5 * farg4;
    temp_f28 = temp_f31 * temp_f1;
    temp_f27 = lbl_8056362C - farg6;
    temp_f1 = farg1 + temp_f3;
    temp_f26 = lbl_80563630 + farg6;
    temp_f4 = temp_f1 - temp_f28;
    spC = temp_f1;
    sp8 = temp_f4;
    fn_80230C9C(&sp8, &spC, temp_f27, temp_f26, -temp_f27 + temp_f26);
    var_r0 = 0;
    var_f2 = lbl_8056362C;
    if (sp8 < temp_f27) {
        var_r0 = 1;
        temp_f4 = sp8 + (-temp_f27 + temp_f26);
        var_f2 = temp_f4 + temp_f28;
    }
    if (spC > temp_f26) {
        var_r0 = 1;
        var_f2 = spC - (-temp_f27 + temp_f26);
    }
    if (var_r0 != 0) {
        fn_80233354(arg0, arg1, arg2, arg3, farg0, var_f2, farg3, farg2);
    }
    fn_80233354(arg0, arg1, arg2, arg3, farg0, spC, farg3, farg2);
}
#pragma processor gekko
#pragma use_lmw_stmw on
#pragma scheduling on
#pragma paired_single off
#pragma paired off
#pragma cplusplus on
extern "C" void fn_80230924(void *, f32, f32, f32, f32, f32);
extern "C" void fn_802C8B98(s32, s32);
extern "C" void fn_802C8D74(void);
extern "C" void fn_802C8DB8(void *, s32, u16 *, s32);
extern "C" void fn_80231380(void *, s32, f32, f32, f32, f32, f32);
extern "C" s32 fn_80230B9C(u32);
extern "C" f32 lbl_80563614;
extern "C" u16 lbl_802F9FD8[6];
void fn_80230924(void *arg0, f32 x, f32 y, f32 z, f32 w, f32 v) {
    struct Frame {
        u16 indices[6];
        u8 pad1[4];
        f32 sp20[6];
        f32 sp38[6];
        f32 sp50[6];
        f32 sp68[6];
    } __attribute__((aligned(16))) frame;
    s32 state;
    fn_802C8B98(-1, (s32)fn_8022EDC4());
    state = fn_80230B9C((u32)arg0);
    fn_80231380(frame.sp20, state, x, y, v, lbl_80563614, lbl_80563614);
    fn_80231380(frame.sp38, state, z, y, v, lbl_80563614, lbl_80563614);
    fn_80231380(frame.sp50, state, x, w, v, lbl_80563614, lbl_80563614);
    fn_80231380(frame.sp68, state, z, w, v, lbl_80563614, lbl_80563614);
    {
        u16 *source = lbl_802F9FD8;
        frame.indices[0] = *source++;
        frame.indices[1] = *source++;
        frame.indices[2] = *source++;
        frame.indices[3] = *source++;
        frame.indices[4] = *source++;
        frame.indices[5] = *source++;
    }
    fn_802C8DB8(frame.sp20, 4, frame.indices, 6);
    fn_802C8D74();
}
#pragma scheduling on
#pragma cplusplus reset

void fn_80230A68(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    u32 *p = (u32 *)arg0;
    p[0] = *(u32 *)&farg0;
    p[1] = *(u32 *)&farg1;
    p[2] = *(u32 *)&farg2;
    p[3] = arg1;
    p[4] = *(u32 *)&farg3;
    p[5] = *(u32 *)&farg4;
}

#pragma dont_inline on
void fn_80230AB8(u32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    *arg1 = (u8)(arg0 >> 24);
    *arg2 = (u8)(arg0 >> 16);
    *arg3 = (u8)(arg0 >> 8);
    *arg4 = (u8)arg0;
}
#pragma dont_inline reset

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

#pragma scheduling invalid_target
s32 fn_80230B9C(u32 arg0) {
    u8 spB, spA, sp9, sp8;
    void *object;
    f32 scaled;
    u32 encoded;
    spB = 0;
    spA = 0;
    sp9 = 0;
    sp8 = 0;
    fn_80230AB8(arg0, &spB, &spA, &sp9, &sp8);
    object = fn_8022EDC4();
    scaled = *(f32 *)((u8 *)object + 0x30) * (f32)spB;
    encoded = (u32)(s32)scaled;
    return (sp8 & ~0xFF00) | ((sp9 << 8) & 0xFF00) |
           (((spA << 16) & ~0xFF000000) | (encoded << 24));
}
#pragma scheduling on
void fn_80230C30(float *arg0, float *arg1, s32 arg2, s32 arg3) {
    s32 sign;
    s32 value;

    value = (s32)lbl_8055FB9C;
    sign = (s32)((u32)value >> 31);
    value = sign + value;
    value >>= 1;
    *arg0 = (float)(arg2 - value);

    value = (s32)lbl_8055FBA0;
    sign = (s32)((u32)value >> 31);
    value = sign + value;
    value >>= 1;
    *arg1 = (float)(value - arg3);
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

#pragma paired off
#pragma paired_single off
#pragma dont_inline on
void fn_80230DA4(float a, float b) {
    register float value;
    register float end;

    end = b;
    lbl_8055F030 = a;
    value = (float)fn_8002EFB4();
    if (value < lbl_80563614)
        value = value + end;
    lbl_8055F02C = end - value;
}
#pragma dont_inline reset
#pragma paired_single reset
#pragma paired reset

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

void fn_80230E90(s32 arg0) {
    if (arg0 == 1) {
        union {
            u32 word[2];
            f64 value;
        } converted;
        s32 ticks = fn_802E2C20();
        f64 bias;
        f32 normalized;

        converted.word[1] = (u32)ticks ^ 0x80000000;
        bias = lbl_80563638;
        converted.word[0] = 0x43300000;
        normalized = (f32)(converted.value - bias) / lbl_80563640;
        fn_80230DA4(normalized, lbl_80563648);
    } else {
        fn_80230DA4(fn_8023659C(), lbl_80563648);
    }
}

#pragma dont_inline on
#pragma scheduling invalid_target
float fn_80230EF4(long arg0) {
    if (!lbl_8055B998) return lbl_80563610;
    if (arg0 == 1) {
        union {
            u32 word[2];
            f64 value;
        } converted;
        s32 ticks = fn_802E2C20();
        f64 bias;
        f32 normalized;
        converted.word[1] = (u32)ticks ^ 0x80000000;
        bias = lbl_80563638;
        converted.word[0] = 0x43300000;
        normalized = (f32)(converted.value - bias) / lbl_80563640;
        return fn_80230E54(normalized, lbl_80563648);
    }
    {
        f32 a = fn_8023659C();
        f32 b = lbl_80563648;
        return fn_80230E54(a, b);
    }
}
#pragma scheduling on
#pragma dont_inline reset
extern f32 lbl_80563610, lbl_80563640, lbl_80563648;
extern u32 lbl_8055FB9C, lbl_8055FBA0;
float fn_80230E54(float, float);
void fn_80230F6C(s32 *arg0) { *arg0 = -0x35BC; }

extern float fn_80230EF4(long);
extern float lbl_80563610, lbl_80563614, lbl_80563658, lbl_80563664, lbl_80563668, lbl_8056366C;
#pragma dont_inline on
void fn_80230F78(signed char *arg0, float *arg1, long arg2, long arg3) {
    float value;
    float max;
    float min;
    long val;
    long n;
    int clipped;

    value = fn_80230EF4(arg3);

    max = lbl_80563610;
    min = (value - lbl_80563614) / lbl_80563658;
    max = (max < min) ? max : min;
    max = (max > lbl_80563614) ? max : lbl_80563614;

    n = (long)(lbl_80563664 + max * lbl_80563668);
    val = n & ((-n & ~n) >> 31);
    clipped = (val >= 0xFF) ? 0xFF : val;

    max = lbl_80563610;
    min = (value - lbl_80563614) / lbl_80563658;
    *arg0 = clipped;

    max = (max < min) ? max : min;
    max = (max > lbl_80563614) ? max : lbl_80563614;

    *arg1 = lbl_80563614 + max * lbl_8056366C;
    fn_80230F6C((s32 *)arg2);
}
#pragma dont_inline reset
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

void *fn_8023139C(void *buf, int len, u32 val) {
    int temp = len - 1;
    int n = temp - (temp - 1) / 3;
    int p = 1;
    int used = 0;
    int i;
    u32 max;
    char *dst;
    int digits;

    if (n > 0) {
        int m = n - 8;
        if (n > 8) {
            int ok = 0;
            if (n >= 0 && n <= 0x7FFFFFFE)
                ok = 1;
            if (ok) {
                u32 count = (u32)(m + 7) >> 3;
                if (m > 0) {
                    do {
                        p *= 100000000;
                        used += 8;
                    } while (--count != 0);
                }
            }
        }
        i = n - used;
        if (used < n) {
            do {
                p *= 10;
            } while (--i != 0);
        }
    }

    max = p - 1;
    if (val < max)
        max = val;

    dst = (char *)buf + len;
    dst[-1] = '\0';
    digits = 4;
    dst -= 2;
    do {
        if (--digits == 0) {
            *dst = ',';
            digits = 3;
            dst--;
        }
        *dst = (max % 10) + '0';
        max /= 10;
        dst--;
    } while (max != 0);

    return dst + 1;
}

