#include "math.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055A070[4];
extern int lbl_8055E29C;
extern int lbl_8055E2A0;
void fn_8015F584(int *arg0);
void fn_8015F5F4(int *arg0);
extern float lbl_805617D0;
int stricmp(const char *, const char *);
void fn_80136594(int *, void *, void *);
void fn_8015EC50(unsigned short *arg0, void *arg1) {
    int value;
    fn_80136594(&value, arg1, (char *)arg0 + 4);
    *arg0 = (value - ((int *)((void **)arg1)[11])[7]) / 60;
}

int fn_8015ECC0(void *arg0) {
    int result = 0;
    int test = 0;
    if (((int *)arg0)[8] < 1000 && ((unsigned int *)arg0)[6] == 0x54554245) test = 1;
    if (test && (float)fabs(((float *)((void **)arg0)[3])[7]) > lbl_805617D0) result = 1;
    return result;
}

#pragma push
#pragma auto_inline off
int fn_8015ED18(void **arg0) {
    void *vtbl = *arg0;
    char *(*fn)(void *) = (char *(*)(void *)) *(void **)((char *)vtbl + 8);
    return stricmp(fn(arg0), lbl_8055A070) == 0;
}
int fn_8015ED90(void **arg0) {
    int count = 0;
    int i;
    void **child;
    if (arg0 != 0) {
        for (i = 0; (child = (*(void **(**)())((char *)*arg0 + 0x60))(arg0, i)) != 0; i++) {
            if (fn_8015ED18(child)) count++;
        }
    }
    return count;
}

#pragma push
#pragma inline_depth 0
int fn_8015F148(void **arg0, int arg1) {
    int count = 0;
    int i;
    int j;
    void **child;
    for (i = 0; i < arg1; i++) {
        child = *(void ***)arg0;
        if (child != 0) {
            for (j = 0; j < ((int *)child)[0]; j++) {
                void *item = *(void **)((char *)child[1] + j * 4);
                if (fn_8015ECC0((char *)item + 0x3C)) count++;
            }
        }
        arg0++;
    }
    return count;
}
#pragma pop
int fn_8015F3EC(unsigned short *arg0, unsigned short *arg1) {
    return *arg0 - *arg1;
}

#pragma pop
void fn_8015F554(void) {
}

void fn_8015F558(void) {
    fn_8015F584(&lbl_8055E2A0);
    fn_8015F5F4(&lbl_8055E29C);
}

void fn_8015F79C(void) {
}

s32 fn_80128668(void *);
void fn_80128670(s32);
extern f32 lbl_805617D4, lbl_805617E4, lbl_805617E8, lbl_805617EC, lbl_805617F0;
f32 PSVECDotProduct(void *, void *);
s32 fn_8015F7A0(u32 arg0, void *arg1, void *arg2) {
    f32 scale = (f32)arg0 * lbl_805617E4;
    f32 t = (PSVECDotProduct(arg1, arg2) - lbl_805617EC) / lbl_805617F0;
    f32 clamp = lbl_805617E8;
    if (clamp >= t) clamp = t;
    if (clamp <= lbl_805617D4) clamp = lbl_805617D4;
    return (s32)(-scale + clamp * (scale - -scale));
}

s32 fn_8015FA44(void *arg0, s32 arg1, f32 arg2) {
    s32 result = -1;
    s32 i;
    if (((s32 *)((char *)arg0 + arg1 * 8))[1] != 1) {
        for (i = arg1 + 1; i < 0x40; i++) {
            void *p = (char *)arg0 + i * 8;
            if (*(f32 *)p > arg2) {
                result = i;
                break;
            }
            if (((s32 *)p)[1] == 1) break;
            if (((s32 *)p)[1] == 2) result = i;
        }
    }
    return result;
}

s32 fn_8015FAB8(s32 *arg0, s32 arg1, f32 arg2) {
    s32 result = -1;
    s32 i;
    if (arg0[arg1 * 2 + 1] != 2) {
        for (i = arg1 - 1; i >= 0; i--) {
            if (*(f32 *)&arg0[i * 2] > arg2) { result = i; break; }
            if (arg0[i * 2 + 1] == 2) break;
            if (arg0[i * 2 + 1] == 1) result = i;
        }
    }
    return result;
}

extern f32 lbl_80561810;
void fn_8015FB28(void *arg0, void *arg1) {
    s32 *dst = (s32 *)arg0;
    s32 *src = (s32 *)arg1;
    dst[6] = src[6]; dst[7] = src[7]; dst[8] = src[8];
    dst[9] = src[9]; dst[10] = src[10]; dst[11] = src[11];
    *(f32 *)&dst[9] = *(f32 *)&dst[9] + (*(f32 *)&dst[6] * lbl_80561810);
    *(f32 *)&dst[10] = *(f32 *)&dst[10] + (*(f32 *)&dst[7] * lbl_80561810);
    *(f32 *)&dst[11] = *(f32 *)&dst[11] + (*(f32 *)&dst[8] * lbl_80561810);
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
    dst[3] = src[3]; dst[4] = src[4]; dst[5] = src[5];
}

extern f32 lbl_805617D4;
void fn_80160230(void *arg0, void *arg1) {
    register f32 c = *(f32 *)((u8 *)arg1 + 4);
    register f32 b = lbl_805617D4;
    register f32 a = *(f32 *)((u8 *)arg1 + 0);
    *(f32 *)((u8 *)arg0 + 0) = a;
    *(f32 *)((u8 *)arg0 + 4) = b;
    *(f32 *)((u8 *)arg0 + 8) = c;
}

s32 fn_8016024C(s32 arg0, s32 arg1) {
    if (arg1 < arg0) {
        return arg1;
    }
    return arg0;
}

void fn_8016025C(void *arg0, f32 farg0, f32 farg1) {
    *(f32 *)((u8 *)arg0 + 0) = farg0;
    *(f32 *)((u8 *)arg0 + 4) = farg1;
}

int fn_80160268(int arg0) {
    int temp_r4;
    temp_r4 = arg0 >> 31;
    return (temp_r4 ^ arg0) - temp_r4;
}

void fn_80160278(void) {
}

void fn_8016027C(void *arg0, f32 farg0, f32 farg1) {
    *(f32 *)((u8 *)arg0 + 0) = farg0;
    *(f32 *)((u8 *)arg0 + 4) = farg1;
}

void fn_80160288(void *arg0, void *arg1) {
    register u32 b = *(u32 *)((u8 *)arg1 + 4);
    register u32 a = *(u32 *)((u8 *)arg1 + 0);
    *(u32 *)((u8 *)arg0 + 0) = a;
    *(u32 *)((u8 *)arg0 + 4) = b;
}

void fn_8016029C(f32 *arg0, f32 *arg1) {
    register f32 b = arg1[2];
    register f32 a = arg1[0];

    arg0[0] = a;
    arg0[1] = b;
}

void fn_801602B0(void) {
}

s32 fn_801602B4(s32 arg0) {
    return arg0 + 0x3C;
}

s32 fn_801602BC(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x10);
}

s32 fn_801602CC(void *arg0) {
    return ((s32 *)arg0)[1];
}

f32 fn_801605C8(void *arg0, void *arg1, void *arg2) {
    f32 spC;
    f32 sp8;
    f32 temp_f2;
    f32 temp_f3;
    temp_f3 = *(f32 *)arg1 - *(f32 *)arg2;
    temp_f2 = *(f32 *)((u8 *)arg1 + 4) - *(f32 *)((u8 *)arg2 + 4);
    sp8 = temp_f3;
    spC = temp_f2;
    return (*(f32 *)((u8 *)arg0 + 4) * temp_f3) + (-*(f32 *)arg0 * temp_f2);
}

void fn_801606B8(void) {
}

