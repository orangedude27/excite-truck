#include <revolution/MTX/mtxtypes.h>
extern char lbl_8055FC34;
extern int lbl_8055D028;
extern int lbl_8055D02C;
extern float lbl_80564F04;
extern float lbl_80564F08;
extern void fn_802C5F48(float, int, float *, float, float);
extern void fn_801332D0(int, void *, int *);
extern int fn_8013365C(int, int);
extern int fn_802C9C58(int);
extern void fn_802C974C(float, float, float);
extern float lbl_8055FC6C;
extern void fn_802D362C(int);
extern void fn_802D3304(void);
extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
extern int lbl_8055CFF4;
extern float lbl_80564F18;
extern double lbl_80564F10;
extern void fn_802D01E0(int, int, int);
extern float lbl_8055FC4C;
extern float lbl_8055FC40;
extern float lbl_8055D020;
extern int lbl_8055FC30;
extern int lbl_8055FC84;
extern void fn_802D08CC(void);
extern void fn_802CAD68(void);
extern int fn_802D31D8(int);
extern void fn_801E7888(int);
extern unsigned int lbl_804C1410[];
extern unsigned int lbl_804C13E0[];
extern char lbl_8055FC35;
extern float lbl_80564EF8, lbl_80564F00;
extern void fn_802C7758(int);
extern void fn_802C89E8(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void fn_802C8638(unsigned int *);
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);

extern char lbl_8055FC94;
extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;

extern int lbl_8055FC70;
extern void fn_802CFDE0(void);
extern void fn_802CC770(void);
extern void fn_802CC60C(void);
extern void fn_802CFCA0(void);
extern int lbl_8055FC78;
extern void fn_802CFFAC(unsigned char, unsigned char, unsigned char);
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[3];
extern unsigned char lbl_8055FC8F;
extern int fn_801E4F3C(void);
extern int fn_801E4F20(void);
extern void fn_802D68C4(void);

extern int lbl_8055FC70;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern char lbl_8055FC8C;
extern char lbl_8055FC8D;
extern float lbl_8055D024;
extern float lbl_80564EFC;
extern char lbl_8034B498[];
extern int fn_80019B9C(void);
extern int fn_802E9A0C(void);
extern void fn_80133348(int, const char *, int);
extern void *lbl_8055FC90;
void fn_802C82C0(void) {
}

#pragma cplusplus on
extern "C" int fn_80133010(void);
extern "C" void fn_802C82C4(int arg0) {
    char (*base)[0x40] = (char (*)[0x40])lbl_8034B498;
    char (&baseRef)[0x40] = *base;
    int mode;

    mode = arg0;
    if (fn_80019B9C() != 0 || fn_802E9A0C() == 1) mode = 1;
    lbl_8055FC90 = (void *)mode;
    if (fn_80133010() != 0) fn_80133348(1, baseRef, (int)lbl_8055FC90);
    lbl_8055FC8C = 0;
    lbl_8055D020 = lbl_80564EF8;
    lbl_8055D024 = lbl_80564EF8;
    lbl_8055FC8D = 0;
    switch (mode) {
    case 0: fn_802E30C8((char *)base + 0x10); break;
    case 1: fn_802E30C8((char *)base + 0x20); lbl_8055FC8C = 1; lbl_8055D020 = lbl_80564EFC; break;
    case 2: fn_802E30C8((char *)base + 0x34); lbl_8055FC8D = 1; lbl_8055D020 = lbl_80564EFC; lbl_8055D024 = lbl_80564EFC; break;
    }
}
#pragma cplusplus reset
void* fn_802C83C4(void) {
    return lbl_8055FC90;
}

void fn_802C83CC(void) {
    register int ten = 10;
    float temp_f1 = (float)ten;
    register float color0 = lbl_80564EF8;
    register float color1 = lbl_80564F00;

    ((float *)lbl_804C1410)[0] = color0;
    ((float *)lbl_804C1410)[1] = color1;
    ((float *)lbl_804C1410)[2] = color1;
    ((float *)lbl_804C1410)[3] = color1;
    ((float *)lbl_804C1410)[4] = color0;
    ((float *)lbl_804C1410)[5] = color1;
    ((float *)lbl_804C1410)[6] = color1;
    ((float *)lbl_804C1410)[7] = color1;
    ((float *)lbl_804C1410)[8] = color0;
    ((float *)lbl_804C1410)[9] = color1;
    ((float *)lbl_804C1410)[10] = color1;
    ((float *)lbl_804C1410)[11] = color1;

    lbl_8055FC5C = 0;
    lbl_8055FC60 = 0;
    lbl_8055FC64 = (void *)ten;
    lbl_8055FC68 = (void *)ten;
    lbl_8055FC6C = temp_f1 / (float)ten;

    fn_802C5F48(temp_f1, ten, (float *)lbl_804C1410,
                lbl_80564F00, lbl_80564EF8);
    lbl_8055FC34 = 0;
    fn_802C974C(lbl_80564EF8, lbl_80564F04, lbl_80564F08);
    lbl_8055FC70 = 0;
    fn_802CFFAC(0xC9, 0xC9, 0xEB);
    ((void (*)(void))fn_802C7758)();
    fn_802C82C4(0);
    fn_802C9C58(0);

    if (fn_80133010() != 0) {
        fn_801332D0(1, lbl_8034B498, (int *)&lbl_8055FC90);
        lbl_8055D028 = fn_8013365C((int)&lbl_8055D02C, (int)fn_802C82C0);
    }
}

extern int fn_80133010(void);
extern void fn_801336E0(int, void (*)(void));
extern void fn_802C6080(void);
extern int lbl_8055D028;
extern int fn_802C9E94(void *, int, int, float, float, float, float, float);
extern int fn_801E7894(int);
void fn_802C84EC(void) {
    if (fn_80133010() != 0) {
        fn_801336E0(lbl_8055D028, fn_802C82C0);
        lbl_8055D028 = -1;
    }
    fn_802C6080();
}

void fn_802C8530(void) {
    lbl_8055FC70 = 1;
    fn_802CC60C();
    fn_802CFCA0();
}

void fn_802C855C(void) {
    fn_802CFDE0();
    fn_802CC770();
    lbl_8055FC70 = 0;
}

extern void fn_802C7758(int);
extern unsigned int lbl_804C13E0[];
extern char lbl_8055FC35;
extern void fn_802C89E8(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void fn_802C8638(unsigned int *);
extern float lbl_80564EF8, lbl_80564F00;
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
#pragma scheduling invalid_target
void fn_802C8588(float *arg0, float *arg1, float *arg2) {
    float x0 = arg1[0];
    float x2 = arg2[0];
    float dx = x2 - x0;
    float y0 = arg1[1];
    float y2 = arg2[1];
    float up = lbl_80564F00;
    float dy = y2 - y0;
    float right = lbl_80564EF8;
    float z0 = arg1[2];
    float z2 = arg2[2];
    float dz = z2 - z0;
    float sp[3];
    sp[0] = up;
    sp[1] = right;
    sp[2] = up;
    arg0[9] = x0;
    arg0[10] = y0;
    arg0[11] = z0;
    arg0[6] = dx;
    arg0[7] = dy;
    arg0[8] = dz;
    PSVECNormalize(arg0 + 6, arg0 + 6);
    PSVECCrossProduct(sp, arg0 + 6, arg0);
    PSVECNormalize(arg0, arg0);
    PSVECCrossProduct(arg0 + 6, arg0, arg0 + 3);
}
#pragma scheduling on
extern void fn_802D03F4(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
#pragma scheduling invalid_target
void fn_802C8638(unsigned int *arg0) {
    int *src = (int *)arg0;
    register int v2, v3, v1, v0;
    int v4, v5, v6, v7, v8, v9, v10, v11;
    volatile int *dst;
    v2 = src[2]; v3 = src[3]; v1 = src[1]; v0 = src[0];
    dst = (volatile int *)lbl_804C1410;
    v4 = src[4]; v5 = src[5]; v6 = src[6]; v7 = src[7];
    v8 = src[8]; v9 = src[9]; v10 = src[10]; v11 = src[11];
    dst[0] = v0; dst[1] = v1; dst[2] = v2; dst[3] = v3;
    dst[4] = v4; dst[5] = v5; dst[6] = v6; dst[7] = v7;
    dst[8] = v8; dst[9] = v9; dst[10] = v10; dst[11] = v11;
    fn_802D03F4((unsigned int *)dst, v10, v9, v8, v7, v6, v5, v4);
}
#pragma scheduling on
void *fn_802C86DC(void) {
    return lbl_804C1410;
}

extern void *lbl_8055D018;
void fn_802C86E8(void* hi) {
    lbl_8055D018 = hi;
}

extern void fn_802C87B4(int, int, int, int);
extern void fn_80128668(void *);
void *fn_802C8750(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802C87B4(*(int *)((unsigned char *)arg0), *(int *)((unsigned char *)arg0 + 4), *(int *)((unsigned char *)arg0 + 8), *(int *)((unsigned char *)arg0 + 0xC));
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
void fn_802C87B4(int x, int y, int w, int h) {
    int half;
    int delta;
    unsigned int rounding;
    if ((unsigned char)lbl_8055FC74 == 0 && (unsigned char)lbl_8055FC8D != 0) {
        rounding = (unsigned int)lbl_8055CFF4 >> 31;
        rounding += (unsigned int)lbl_8055CFF4;
        half = (int)rounding >> 1;
        delta = y - half;
        y = half + (int)(lbl_80564F18 + lbl_8055D024 * (float)delta);
        h = (int)(lbl_80564F18 + (float)h * lbl_8055D024);
    }
    lbl_8055FC64 = (void *)w;
    lbl_8055FC5C = (void *)x;
    lbl_8055FC60 = (void *)y;
    lbl_8055FC68 = (void *)h;
    lbl_8055FC6C = (float)w / (float)h;
    fn_802D01E0(x, y, w);
    fn_802CC518(w, lbl_8055FC44);
}
#pragma pop

void fn_802C88BC(int arg0) {
    fn_802D02F8(lbl_8055D018, arg0 & 1);
}

extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
void fn_802C88CC(unsigned int arg0) {
    fn_802D02F8(arg0, 1);
}

extern unsigned int lbl_804C1410[];
extern void PSQUATMultiply(void *, unsigned int, void *);
extern void fn_802C7734(unsigned int);
extern void fn_802C8B70(void);
#pragma scheduling invalid_target
void fn_802C88D4(unsigned int arg0) {
    PSQUATMultiply((void *)&lbl_804C1410[9], arg0, lbl_804C1410);
}

extern void PSVECSquareDistance(void *, unsigned int, void *);
void fn_802C88E8(unsigned int arg0) {
    PSVECSquareDistance((void *)&lbl_804C1410[9], arg0, lbl_804C1410);
}

#pragma scheduling reset
extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
extern double lbl_80564F10;
extern float lbl_80564F18, lbl_80564F1C;
#pragma scheduling invalid_target
void fn_802C88FC(float *arg0) {
    float x;
    float y;
    float z;
    float value;
    float fill;
    float scale;
    float divisor;

    x = (float)(unsigned int)lbl_8055FC64;
    scale = lbl_80564F18;
    divisor = lbl_8055FC44;
    value = lbl_80564EF8;
    z = value / lbl_8055D020;
    fill = lbl_80564F00;

    arg0[0] = value;
    arg0[1] = fill;
    arg0[2] = fill;
    arg0[3] = fill;
    y = (scale * x) / divisor;
    arg0[5] = fill;
    arg0[4] = lbl_80564F1C;
    arg0[6] = fill;
    arg0[7] = fill;
    arg0[8] = value;
    arg0[11] = -(y * z);
    arg0[10] = (float)(unsigned int)lbl_8055FC60 + scale * (float)(unsigned int)lbl_8055FC68;
    arg0[9] = (float)(unsigned int)lbl_8055FC5C + scale * (float)(unsigned int)lbl_8055FC64;
}

#pragma scheduling invalid_target
void fn_802C89E8(unsigned int *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5, unsigned int arg6, unsigned int arg7) {
    float var_f2;
    float var_f4;
    float fill;
    float scale;
    int height;
    int y;
    int width;
    int x;

    var_f2 = (lbl_80564F18 * (float)(int)lbl_8055FC64) / lbl_8055FC44;
    if ((unsigned char)lbl_8055FC74 == 0) {
        var_f2 *= lbl_80564EF8 / lbl_8055D020;
    }
    if ((unsigned char)lbl_8055FC74 != 0) {
        var_f4 = lbl_80564EF8;
    } else {
        var_f4 = lbl_80564EF8 / lbl_8055D020;
    }

    fill = lbl_80564F00;
    var_f2 = -var_f2;
    ((float *)arg0)[0] = var_f4;
    ((float *)arg0)[1] = fill;
    ((float *)arg0)[2] = fill;
    ((float *)arg0)[3] = fill;
    ((float *)arg0)[4] = lbl_80564F1C;
    ((float *)arg0)[5] = fill;
    ((float *)arg0)[6] = fill;
    ((float *)arg0)[7] = fill;
    ((float *)arg0)[8] = lbl_80564EF8;

    height = (int)lbl_8055FC68;
    y = (int)lbl_8055FC60;
    width = (int)lbl_8055FC64;
    x = (int)lbl_8055FC5C;
    scale = lbl_80564F18;
    ((float *)arg0)[10] = scale * (float)y + (float)height;
    ((float *)arg0)[11] = var_f2;
    ((float *)arg0)[9] = scale * (float)x + (float)width;
}
void fn_802C8B08(unsigned int *arg0) {
    struct Pair { unsigned int first; unsigned int second; };
    struct Tail { unsigned int first; struct Pair pair; unsigned int last; };
    struct Pair *dst = (struct Pair *)arg0;
    struct Pair *src = (struct Pair *)lbl_804C1410;
    struct Tail *dstTail = (struct Tail *)((char *)arg0 + 0x20);
    struct Tail *srcTail = (struct Tail *)((char *)lbl_804C1410 + 0x20);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dstTail->first = srcTail->first;
    dstTail->pair = srcTail->pair;
    dstTail->last = srcTail->last;
}

extern void fn_802CAD74(void);
void fn_802C8B70(void) {
    fn_802CAD74();
    lbl_8055FC70 = 2;
}

#pragma dont_inline on
void fn_802C8B98(int arg0, int arg1) {
    fn_802C7734(arg1);
    ((void (*)(int))fn_802C8B70)(arg0);
}
#pragma dont_inline reset
void fn_802C8BD0(int arg0) {
    fn_802C7758(arg0);
    ((void (*)(int))fn_802C8B70)(arg0);
}
#pragma dont_inline off

#pragma use_lmw_stmw off
void fn_802C8C04(int arg0) {
    unsigned int *dst = lbl_804C13E0;
    unsigned int sp8[12];
    unsigned int v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0;
    v0 = lbl_804C1410[0];
    v1 = lbl_804C1410[1]; v2 = lbl_804C1410[2]; v3 = lbl_804C1410[3];
    v4 = lbl_804C1410[4]; v5 = lbl_804C1410[5]; v6 = lbl_804C1410[6];
    v7 = lbl_804C1410[7]; v8 = lbl_804C1410[8]; v9 = lbl_804C1410[9];
    v10 = lbl_804C1410[10]; v11 = lbl_804C1410[11];
    *dst++ = v0; *dst++ = v1; *dst++ = v2; *dst++ = v3; *dst++ = v4; *dst++ = v5;
    *dst++ = v6; *dst++ = v7; *dst++ = v8; *dst++ = v9; *dst++ = v10; *dst++ = v11;
    lbl_8055FC35 = 1;
    fn_802C89E8(sp8, v11, v10, v9, v8, v7, v6, v5);
    fn_802C8638(sp8);
    ((void (*)(int))fn_802C8BD0)(arg0);
}

#pragma dont_inline on
void fn_802C8D74(void) {
    lbl_8055FC70 = 1;
    if ((unsigned char)lbl_8055FC35 != 0) {
        fn_802C8638(lbl_804C13E0);
    }
    lbl_8055FC35 = 0;
}
#pragma dont_inline reset

void fn_802C8DB8(void) {
    fn_802D68C4();
}

int fn_802C8DBC(void) {
    if (fn_801E4F20() != 0) {
        lbl_8055FC8F = 1;
        lbl_8055FC70 = 6;
        return 1;
    }
    return 0;
}

void fn_802C8E00(void) {
    unsigned char result = 0;
    if (lbl_8055FC8F != 0 && fn_801E4F3C() == 0) {
        result = 1;
    }
    lbl_8055FC8F = result;
}

extern void fn_801E4FF4(void);
void fn_802C8E48(void) {
    fn_801E4FF4();
    lbl_8055FC70 = 2;
}

void fn_802C8E70(float *arg0, float *arg1) {
    float *m = (float *)lbl_804C1410;
    float x, y, z, rx, ry, rz, limit, scale;
    x = arg0[0] - m[9]; arg1[0] = x;
    y = arg0[1] - m[10]; arg1[1] = y;
    z = arg0[2] - m[11]; arg1[2] = z;
    rx = x * m[0]; ry = y * m[1]; rx = rx + ry; rz = z * m[2]; rx = rx + rz;
    ry = x * m[3]; rz = y * m[4]; ry = ry + rz; rz = z * m[5]; ry = ry + rz;
    rz = x * m[6]; scale = y * m[7]; rz = rz + scale; scale = z * m[8]; rz = rz + scale;
    arg1[0] = rx; arg1[1] = ry; arg1[2] = rz;
    limit = lbl_8055FC38;
    if (!(limit > rz)) limit = rz;
    scale = lbl_80564EF8 / (lbl_8055FC44 * limit);
    arg1[0] = (float)(int)lbl_8055FC5C + lbl_80564F18 * (float)(int)lbl_8055FC64 * (lbl_80564EF8 + scale * arg1[0]);
    arg1[1] = (float)(int)lbl_8055FC60 + lbl_80564F18 * (float)(int)lbl_8055FC68 * (lbl_80564EF8 + lbl_8055FC6C * (scale * -arg1[1]));
}

float fn_802C8FEC(void) { return lbl_8055FC6C; }

extern char lbl_80558DC4[];
extern float lbl_8055FC38, lbl_8055FC3C;
#pragma scheduling off
int fn_802C8FF4(float *arg0, float arg1) {
    float x;
    float y;
    float z;
    int result = 0;

    z = arg0[2];
    if (z > lbl_8055FC38 + (*(float *)&lbl_80558DC4) &&
        z < lbl_8055FC3C - (*(float *)&lbl_80558DC4)) {
        x = arg0[0];
        if (x >= (float)(int)lbl_8055FC5C - arg1 &&
            x < arg1 + (float)((int)lbl_8055FC5C + (int)lbl_8055FC64)) {
            y = arg0[1];
            if (y >= (float)(int)lbl_8055FC60 - arg1 &&
                y < arg1 + (float)((int)lbl_8055FC60 + (int)lbl_8055FC68)) {
                result = 1;
            }
        }
    }
    return result;
}
#pragma scheduling on
int fn_802C90E0(void) {
    return lbl_8055FC70 == 0;
}

void fn_802C90F0(void) {
    ((void (*)(void))fn_802C8C04)();
    lbl_8055FC70 = 3;
}

#pragma scheduling invalid_target
void fn_802C9294(int arg0, int arg1) {
    int equal;
    if (arg0 != -1 && arg0 != -2) {
        equal = arg1 == 1;
        lbl_8055FC75 = equal;
        lbl_8055FC74 = 1;
    } else {
        lbl_8055FC74 = 0;
        lbl_8055FC75 = 0;
    }
    fn_802CB29C();
}
#pragma scheduling on
extern void fn_802C8C04(int);
extern void fn_802C8D74(void);
extern int lbl_8055FC70;
extern int fn_802CB29C(void);
extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern void fn_802C92DC(int, int, int, int, int);
#pragma dont_inline on
void fn_802C92D0(void) {
#pragma dont_inline off
    fn_802C8C04(-1);
}

void fn_802C92D8(void) {
    fn_802C8D74();
}

void fn_802C92DC(int x0, int y0, int x1, int y1, int screen) {
    if (((int (*)(int))fn_801E4F20)(4) != 0) {
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 0, (float)x1, (float)y0, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 0, (float)x0, (float)y0, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 1, (float)x1, (float)y1, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 1, (float)x0, (float)y1, 0.0f, 0.0f, 0.0f);
        fn_801E4FF4();
    }
}

void fn_802C9118(void) {
    lbl_8055FC70 = 2;
    fn_802C8D74();
}

#pragma processor 750
void fn_802C9124(float farg0, float farg1, float farg2, float farg3, int x0, int y0, int x1, int y1, int screen) {
    if (((int (*)(int))fn_801E4F20)(4) != 0) {
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 0, (float)x1, (float)y0, 0.0f, farg2, farg1);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 0, (float)x0, (float)y0, 0.0f, farg0, farg1);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 1, (float)x1, (float)y1, 0.0f, farg2, farg3);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 1, (float)x0, (float)y1, 0.0f, farg0, farg3);
        fn_801E4FF4();
    }
}
#pragma processor reset

#pragma dont_inline on
void fn_802C942C(int arg0) {
    fn_802C92D0();
    fn_802C92DC(0, 0, lbl_8055CFF0, lbl_8055CFF4, arg0);
    fn_802C92D8();
}
#pragma dont_inline reset
void fn_802C9474(void) {
    if ((unsigned char)lbl_8055FC94 != 0) return;
    lbl_8055FC94 = 1;
    ((void (*)(int, ...))fn_802E30C8)((int)lbl_8055D030, lbl_8034B4E0);
}
#pragma scheduling on
int fn_802C94A0();
void fn_802C9638(int arg0, int arg1) {
    fn_802C94A0(arg0, arg1, 0);
}

#pragma dont_inline on
void fn_802C9640(int arg0) {
    fn_802C9638(arg0, 0);
}
#pragma dont_inline off
extern void fn_802C9638(int, int);
extern void fn_802C974C(float, float, float);
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[];
extern float lbl_80564F24, lbl_80564F28, lbl_8055FC88;
extern float lbl_8055FC50, lbl_8055FC54, lbl_8055FC58;
extern double fn_8002EF30(double);
extern double atan(double);
extern double sin(double);
extern double cos(double);
extern void fn_802D0368(float, float, float, float);
#pragma scheduling invalid_target
void fn_802C9648(float arg0) {
    float f0;
    float f2;
    float f3;
    float f4;
    f3 = lbl_8055FC38;
    f4 = lbl_8055FC3C;
    f0 = f3 * arg0;
    f2 = f4 * arg0;
    lbl_804C144C[0] = f3;
    lbl_804C144C[1] = f4;
    lbl_8055FC38 = f0;
    lbl_8055FC3C = f2;
    fn_802C974C(f0, f2, lbl_804C144C[2]);
}
#pragma scheduling on
void fn_802C967C(void) {
    fn_802C974C(lbl_804C144C[0], lbl_804C144C[1], lbl_804C144C[2]);
}

void *fn_802C9694(void *arg0) {
    ((float *)arg0)[0] = lbl_8055FC38;
    ((float *)arg0)[1] = lbl_8055FC3C;
    ((float *)arg0)[2] = lbl_8055FC40;
    ((void (*)())fn_802C974C)(arg0);
    return arg0;
}

void *fn_802C96DC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802C974C(((float *)arg0)[0], ((float *)arg0)[1], ((float *)arg0)[2]);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

float fn_802C973C(void) { return lbl_8055FC4C; }

float fn_802C9744(void) { return lbl_8055FC40; }

extern float __fabsf(float);
extern double __fabs(double);
extern int fn_802CC518();
#pragma push
#pragma processor 750
void fn_802C974C(float f0, float f1, float f2) {
    float *view = lbl_804C144C;
    register float angle = f2;
    float f4;
    register float sine, theta, tangent;
    float cosine;
    float denom_angle, denom_sine, atan_value, ratio, depth;
    unsigned char mode = lbl_8055FC74;

    lbl_8055FC38 = f0;
    lbl_8055FC3C = f1;
    lbl_8055FC40 = f2;
    view[2] = f2;
    if (mode == 0 || (unsigned char)lbl_8055FC75 != 0) {
        float diff = lbl_8055D020 - lbl_80564EF8;
        float abs = (float)__fabs((double)diff);
        if (!(abs <= (*(float *)&lbl_80558DC4))) {
            atan_value = (float)atan((float)fn_8002EF30(lbl_80564F18 * f2) / lbl_8055D020);
            angle = lbl_80564F24 * atan_value;
        }
    }
    lbl_8055FC4C = angle;
    theta = lbl_80564F18 * angle;
    sine = (float)sin(theta);
    cosine = (float)cos(theta);
    denom_angle = lbl_80564F28 - angle * lbl_80564F18;
    lbl_8055FC48 = sine;
    tangent = sine / cosine;
    lbl_8055FC44 = tangent;
    lbl_8055FC88 = tangent;
    denom_sine = (float)sin(denom_angle);
    depth = lbl_80564EF8 / denom_sine;
    ratio = lbl_8055FC44 / lbl_8055FC6C;
    lbl_8055FC54 = depth;
    lbl_8055FC50 = ratio;
    atan_value = (float)atan(ratio);
    theta = lbl_80564F24 * atan_value;
    sine = (float)sin(lbl_80564F28 - theta * lbl_80564F18);
    f4 = lbl_80564EF8;
    lbl_8055FC58 = f4 / sine;
    switch (mode) {
    case 0: f4 = lbl_8055D020 / lbl_8055D024; break;
    }
    fn_802D0368(lbl_8055FC38, lbl_8055FC3C, angle, f4);
    fn_802CC518((int)lbl_8055FC64, lbl_8055FC44);
}
#pragma pop
void fn_802C98DC(float *arg0, float *arg1, float *arg2, float *arg3) {
    *arg0 = lbl_8055FC44;
    *arg1 = lbl_8055FC38;
    *arg2 = lbl_8055FC3C;
    *arg3 = lbl_8055FC48;
}

void fn_802D007C(float);
void fn_802C9900(float arg0) {
    fn_802D007C(arg0);
}

#pragma dont_inline off
extern float lbl_80564EF8;
extern void fn_802D007C(float);
void fn_802C9904(void) {
    fn_802D007C(lbl_80564EF8);
}

int fn_802C990C(int arg0) {
    int previous = lbl_8055FC78;
    lbl_8055FC78 = arg0;
    fn_802CFFAC((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern int lbl_8055FC7C;
extern void fn_802D0160(unsigned char, unsigned char, unsigned char);
int fn_802C9950(int arg0) {
    int previous = lbl_8055FC7C;
    lbl_8055FC7C = arg0;
    fn_802D0160((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern int lbl_8055FC80;
extern void fn_802D0188(unsigned char, unsigned char, unsigned char);
int fn_802C9994(int arg0) {
    int previous = lbl_8055FC80;
    lbl_8055FC80 = arg0;
    fn_802D0188((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern char lbl_804C1440[];
extern float lbl_8055D01C;
void fn_802C99D8(void) {
    fn_802D01B0(lbl_804C1440, lbl_8055D01C);
}

#pragma dont_inline on
float fn_802C99E8(float arg0) {
    float previous = lbl_8055D01C;
    lbl_8055D01C = arg0;
    fn_802C99D8();
    return previous;
}
#pragma dont_inline on
void fn_802C9A1C(float *arg0) {
    float z, y, x;
    x = arg0[0];
    y = arg0[1];
    z = arg0[2];
    ((float *)lbl_804C1440)[0] = x;
    ((float *)lbl_804C1440)[1] = y;
    ((float *)lbl_804C1440)[2] = z;
    fn_802C99D8();
}
#pragma dont_inline reset
void *fn_802C9A40(void) {
    return lbl_804C1440;
}

void fn_802C9A4C(void) {
    fn_802D93E0();
}

float fn_802C9A50(void) { return lbl_8055D020; }

#pragma dont_inline off
char fn_802C9A58(void) {
    return lbl_8055FC8C;
}

extern char lbl_8055FC8D;
char fn_802C9A60(void) {
    return lbl_8055FC8D;
}

extern char lbl_8055FC8E;
char fn_802C9A68(void) {
    return lbl_8055FC8E;
}

extern int lbl_8055CFF0, lbl_8055CFF4;
extern float lbl_80564F18, lbl_80564F28;
#pragma dont_inline on
void fn_802C9A70(int arg0) {
    int temp_r31;
    int temp_r31_2;
    int temp_r3;
    int temp_r3_2;
    lbl_8055FC74 = 1;
    if ((unsigned char)lbl_8055FC8D != 0) {
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_802C88BC(2);
        fn_802C974C(lbl_8055FC38, lbl_8055FC3C, lbl_80564F28);
    }
    if (((unsigned char)lbl_8055FC8C != 0 || (unsigned char)lbl_8055FC8D != 0) && arg0 != 0) {
        temp_r3 = lbl_8055CFF0 - (int)(lbl_80564F18 + ((float)lbl_8055CFF0 * lbl_8055D020));
        temp_r31 = temp_r3 / 2;
        if (temp_r31 > 1) {
            fn_802C92D0();
            fn_802C92DC(0, 0, temp_r31, lbl_8055CFF4, 0xFF000000);
            fn_802C92DC(lbl_8055CFF0 - temp_r31, 0, lbl_8055CFF0, lbl_8055CFF4, 0xFF000000);
            fn_802C92D8();
        }
    }
    if ((unsigned char)lbl_8055FC8D != 0) {
        temp_r3_2 = lbl_8055CFF4 - (int)(lbl_80564F18 + ((float)lbl_8055CFF4 * lbl_8055D024));
        temp_r31_2 = temp_r3_2 / 2;
        if (temp_r31_2 > 1) {
            fn_802C92D0();
            fn_802C92DC(0, 0, lbl_8055CFF0, temp_r31_2, 0xFF000000);
            fn_802C92DC(0, lbl_8055CFF4 - temp_r31_2, lbl_8055CFF0, lbl_8055CFF4, 0xFF000000);
            fn_802C92D8();
        }
    }
    lbl_8055FC74 = 0;
}
#pragma dont_inline reset
int fn_802C9C24(void *arg0) {
    void *p = *(void **)((char *)arg0 + 8);
    void *q = *(void **)((char *)p + 4);
    return *(int *)q + 4;
}

extern void *lbl_8055FC68;
void* fn_802C9C38(void) {
    return lbl_8055FC68;
}

extern void *lbl_8055FC60;
void* fn_802C9C40(void) {
    return lbl_8055FC60;
}

extern void *lbl_8055FC64;
void* fn_802C9C48(void) {
    return lbl_8055FC64;
}

extern void *lbl_8055FC5C;
void* fn_802C9C50(void) {
    return lbl_8055FC5C;
}

int fn_802C9C58(int arg0) {
    int old = lbl_8055FC30;
    lbl_8055FC30 = arg0;
    fn_802D08CC();
    return old;
}

int fn_802C9C8C(int arg0) {
    fn_802CAD68();
    if (fn_802D31D8(1) != 0) {
        lbl_8055FC84 = arg0;
        lbl_8055FC70 = 4;
        return 1;
    }
    return 0;
}

void fn_802C9CE0(void) {
    fn_802D362C(lbl_8055FC84);
    fn_802D3304();
    lbl_8055FC70 = 1;
}

extern int lbl_8055FC98;
extern void *lbl_8055FC9C;
extern int lbl_8055FC84;
extern float lbl_80564F00;
extern char lbl_8034B514[];
extern int fn_8012A364(void *, int);
extern void *fn_801E7840(int);
extern void *fn_801284F8(int, const char *);
extern void *fn_8012A13C(const char *, int, int);
extern int fn_8012A2D8(void *);
extern void fn_802D362C(int);
extern void fn_802D3304(void);
#pragma dont_inline on
#pragma push
#pragma cplusplus on
extern "C" void fn_802C9D88(int arg0) {
    class Obj {
    public:
        virtual void f(int);
    };
    fn_8012A364(lbl_8055FC9C, arg0);
    if (--lbl_8055FC98 == 0) {
        if (lbl_8055FC9C != 0)
            ((Obj *)lbl_8055FC9C)->f(1);
        lbl_8055FC9C = 0;
    }
}
#pragma cplusplus reset
#pragma pop

void *fn_802C9DE8(void *arg0, int arg1) {
    void *value = fn_801E7840(arg1);
    float zero = lbl_80564F00;
    *(void **)arg0 = value;
    *(float *)((char *)arg0 + 4) = zero;
    *(float *)((char *)arg0 + 8) = zero;
    *(float *)((char *)arg0 + 12) = zero;
    *(float *)((char *)arg0 + 16) = zero;
    *(int *)((char *)arg0 + 20) = 0;
    return arg0;
}

int *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_802C9E3C(int *arg0, int arg1) {
    if (arg0 != 0) {
        fn_801E7888(*arg0);
        if (arg1 > 0) fn_802C9D88((int)arg0);
    }
    return arg0;
}

extern void fn_801E7890(void);
int fn_802C9E94(void *arg0, int arg1, int arg2, float farg0, float farg1, float farg2, float farg3, float farg4) {
    float q[3];
    float diff[3];
    float result;
    float current;
    float step;
    int old_count;

    if (*(int *)((char *)arg0 + 0x14) == 0) {
        *(float *)((char *)arg0 + 4) = farg0;
        *(float *)((char *)arg0 + 8) = farg1;
        *(float *)((char *)arg0 + 0xC) = farg2;
        *(float *)((char *)arg0 + 0x10) = lbl_80564F00;
    } else {
        q[0] = farg0;
        q[1] = farg1;
        q[2] = farg2;
        result = ((float (*)(void *, float *))PSQUATMultiply)((char *)arg0 + 4, q);
        if (result > *(float *)((char *)arg0 + 0x10)) {
            diff[0] = q[0] - *(float *)((char *)arg0 + 4);
            diff[1] = q[1] - *(float *)((char *)arg0 + 8);
            diff[2] = q[2] - *(float *)((char *)arg0 + 0xC);
            PSVECNormalize(diff, diff);
            current = *(float *)((char *)arg0 + 0x10);
            step = lbl_80564F18 * (result - current);
            *(float *)((char *)arg0 + 4) = *(float *)((char *)arg0 + 4) + diff[0] * step;
            *(float *)((char *)arg0 + 8) = *(float *)((char *)arg0 + 8) + diff[1] * step;
            *(float *)((char *)arg0 + 0x10) = lbl_80564F18 * (current + result);
            *(float *)((char *)arg0 + 0xC) = *(float *)((char *)arg0 + 0xC) + diff[2] * step;
        }
    }

    ((void (*)(void *, int, int, float, float, float, float, float))fn_801E7890)(
        *(void **)arg0, arg1, arg2, farg0, farg1, farg2, farg3, farg4);
    old_count = *(int *)((char *)arg0 + 0x14);
    *(int *)((char *)arg0 + 0x14) = old_count + 1;
    return old_count;
}

void fn_802CA008(void *arg0) {
    if (((int (*)(int, float))fn_802C9640)((int)((char *)arg0 + 4), *(float *)((char *)arg0 + 0x10)) != 0) {
        fn_801E7894(*(int *)arg0);
    }
}

extern void *fn_802C9D10(int, void *);
extern void *fn_802C9DE8(void *, int);
extern char lbl_8034B52C[];
void fn_802CA04C(int arg0) {
    void *obj;
    obj = fn_802C9D10(0x18, lbl_8034B52C);
    if (obj != 0)
        fn_802C9DE8(obj, arg0);
}

void fn_802CA094(int *arg0) {
    __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_802C9E3C(arg0, 1);
}

void fn_802CA09C(void) {
    ((int (*)(void))fn_802C9E94)();
}

void fn_802CA0A0(void *arg0) { fn_802CA008(arg0); }

extern char lbl_8055FC94;
extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;
