#include "math.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void PSVECCrossProduct(void *, void *, void *);
typedef struct { float x, y, z; } FV3;
static inline void fv3_sub(const FV3 *a, const FV3 *b, FV3 *out) {
    float x = a->x - b->x, y = a->y - b->y, z = a->z - b->z;
    out->x = x; out->y = y; out->z = z;
}
extern float PSVECDotProduct(void *, void *);
extern void PSVECNormalize(void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern float lbl_805628B8, lbl_805628BC, lbl_805628CC;
extern void fn_8019EECC(void *, void *);
extern void fn_8017A580(int, int, int, int, int, int);
extern void fn_8017A57C(float, float);

void fn_801BF210(void) {

}

#pragma scheduling invalid_target
void *fn_801BF214(void) {
    extern void *fn_801284F8(int, void *);
    extern void fn_8017B0B0(void);
    extern int fn_801C1BA4(int, int, int, void *, int);
    extern int lbl_8055A948;
    extern char lbl_80336A90[];
    extern char lbl_80437D48[];
    extern int lbl_8055E7BC;
    void *p = fn_801284F8(0x278, &lbl_8055A948);
    if (p != 0) {
        int index;
        fn_8017B0B0();
        *(char **)p = lbl_80336A90;
        *(int *)((char *)p + 0x1EC) = 0;
        *(int *)((char *)p + 0x1F0) = -1;
        index = lbl_8055E7BC++;
        *(void **)(lbl_80437D48 + index * 4) = p;
        *(int *)((char *)p + 0x214) = fn_801C1BA4(4, 6, 2, lbl_80437D48, lbl_8055E7BC);
    }
    return p;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_801BF2A4(int arg0, int arg1, float *arg2, float *arg3, float *arg4, int arg5, int *arg6) {
    extern void fn_8001BA68(void *);
    extern void fn_80144B54(void *, int);
    extern void fn_80144DAC(float *, float *);
    extern void fn_80144DC8(void *);
    extern int fn_801602B4(int);
    extern void fn_8017E388(void *, int, int);
    extern int fn_8017EAFC(int);
    extern int fn_8017EB04(int);
    extern void fn_801C1CBC(int, int, void *, int, void *, int, void *);
    extern void fn_801C256C(int, int, int, int);
    extern void fn_801E9DC4(void);
    extern void GXInitLightAttnA_80144B44(void *, float, float, float);
    extern float fn_801C0178(void);
    extern int fn_801C0170(void *);
    extern int fn_801C0168(void *);
    extern void fn_801C014C(void *, float *);
    extern void fn_801C0124(float *, float *, float);
    extern long fn_801C00F8(void *, long);
    extern long fn_801C00F0(void *);
    extern void fn_801C00B8(void *, float *);
    extern void fn_801BFF64(float *, const float *);
    extern void fn_801BFECC(void *, void *);
    extern void GXInitLightAttnA_801BFEBC(void *, float, float, float);
    extern long fn_801BFEB4(long);
    extern void fn_801BFEB0(void);
    extern void fn_801BFE7C(float *, float *, float *);
    extern void fn_801BFD34(float *, float *, const float *);
    extern void fn_801BFB2C(char *, float *, FV3 *);
    extern void fn_801BF75C(float *, const float *, const float *, int);
    extern int fn_801BF754(int);
    extern float lbl_805628C0;
    extern float lbl_805628C4;
    extern float lbl_805628C8;
    extern float lbl_805628B8;
    extern char lbl_80558DC4[];
    extern char lbl_802F98D0[];
    extern char lbl_80437D48[];
    extern int lbl_8055E7BC;
    struct {
        float sp8[3];
        float sp14[3];
        float sp20[3];
        float sp2C[3];
        int sp38[6];
        float sp50[12];
        float sp80[3];
        float sp8C[3];
        float sp98[3];
        float spA4[3];
        float spB0[12];
        float spE0[20];
        int sp130[24];
    } frame;
    void *found;
    long cb;

    if ((float)fabs(arg3[0] - arg4[0]) <= *(float *)lbl_80558DC4) {
    if ((float)fabs(arg3[1] - arg4[1]) <= *(float *)lbl_80558DC4) {
    if ((float)fabs(arg3[2] - arg4[2]) <= *(float *)lbl_80558DC4) {
    found = 0;
    {
        int cnt;
        void **ptr;
        int i;
        cnt = lbl_8055E7BC;
        ptr = (void **)lbl_80437D48;
        for (i = 0; i < cnt; i++) {
            void *obj = *ptr;
            if (*(int *)((char *)obj + 0x1EC) == 0) {
                found = ((void **)lbl_80437D48)[i];
                break;
            }
            ptr++;
        }
    }
    if (found == 0) {
        float f1val = *(float *)((char *)((void **)lbl_80437D48)[0] + 0x218);
        found = ((void **)lbl_80437D48)[0];
        {
            int cnt;
            void **ptr;
            int j;
            cnt = lbl_8055E7BC;
            ptr = (void **)lbl_80437D48;
            for (j = 0; j < cnt; j++) {
                void *obj = *ptr;
                float f0val = *(float *)((char *)obj + 0x218);
                if (f0val <= f1val) {
                    f1val = f0val;
                    found = obj;
                }
                ptr++;
            }
        }
    }
    if (found != 0) {
    *(float *)((char *)found + 0x218) = fn_801C0178();
    *(int *)((char *)found + 0x1EC) = arg0;
    *(int *)((char *)found + 0x1F0) = fn_801C0170((void *)arg0);
    *(int *)((char *)found + 0x1F4) = arg1;
    *(int *)((char *)found + 0x1F8) = fn_801C0168((void *)(long)*(int *)((char *)found + 0x1EC));
    fn_801C014C(found, arg2);
    fn_8001BA68(frame.sp8);
    fn_801C0124(frame.sp8, arg2, lbl_805628C0);
    cb = fn_801C00F8(found, 0);
    if (cb != 0) {
        if ((unsigned)((int)fn_801C00F0((void *)cb) - 0x53500000) == 0x4852U) {
            fn_801C00B8((void *)cb, frame.sp8);
        }
    }
    fn_80144B54(frame.sp50, fn_8017EB04(arg0));
    fn_801BFF64(frame.sp50, frame.sp8);
    fn_801BFECC(found, frame.sp50);
    GXInitLightAttnA_801BFEBC((char *)found + 0x118, lbl_805628B8, lbl_805628B8, lbl_805628B8);
    GXInitLightAttnA_801BFEBC((char *)found + 0x124, lbl_805628B8, lbl_805628B8, lbl_805628B8);
    fn_801BFEB4((long)found);
    fn_801E9DC4();
    ((void (*)(void *))fn_801BFEB0)(frame.spE0);
    ((void (*)(void *))fn_801BFEB0)(&frame.spE0[5]);
    ((void (*)(void *))fn_801BFEB0)(&frame.spE0[10]);
    ((void (*)(void *))fn_801BFEB0)(&frame.spE0[15]);
    {
        struct Big { long long v[12]; } *dst = (struct Big *)frame.sp130;
        struct Big *src = (struct Big *)lbl_802F98D0;
        *dst = *src;
    }
    fn_8001BA68(frame.sp14);
    fn_8001BA68(frame.sp20);
    fn_801BFE7C(frame.sp14, arg3, arg2);
    fn_801BFE7C(frame.sp20, arg4, arg2);
    *(int *)((char *)found + 0x21C) = 0;
    *(int *)((char *)found + 0x220) = 0;
    *(int *)((char *)found + 0x224) = 1;
    *(int *)((char *)found + 0x228) = 0;
    *(int *)((char *)found + 0x22C) = 2;
    fn_8017E388((char *)found + 0x230, 1, 0);
    {
        int a;
        int b;
        int c;
        float cond2;
        float cond1;
        a = 1;
        b = 4;
        cond2 = frame.sp20[1] - frame.sp14[1];
        cond1 = frame.sp20[0] - frame.sp14[0];
        c = 2;
        if (cond2 > cond1) {
            b = 1;
            c = 2;
            a = 4;
        }
        {
            float f30v = lbl_805628C4;
            float f31v = lbl_805628C8;
            int idx = 0;
            float *p = frame.spE0;
            do {
                float var_f3;
                float var_f2;
                float var_f1;
                if (idx & c) var_f3 = frame.sp14[2]; else var_f3 = frame.sp20[2];
                if (idx & b) var_f2 = frame.sp14[1]; else var_f2 = frame.sp20[1];
                if (idx & a) var_f1 = frame.sp14[0]; else var_f1 = frame.sp20[0];
                GXInitLightAttnA_80144B44(frame.sp2C, var_f1, var_f2, var_f3);
                fn_801BFD34(p, frame.sp2C, frame.sp50);
                p[3] = f30v;
                idx++;
                p[4] = f31v;
                p += 5;
            } while (idx < 4);
        }
    }
    fn_8001BA68(frame.sp80);
    fn_8001BA68(frame.sp8C);
    fn_8001BA68(frame.sp98);
    fn_8001BA68(frame.spA4);
    {
        float *srcp = frame.spE0;
        float *dstp = frame.sp80;
        int idx = 0;
        do {
            fn_80144DAC(dstp, srcp);
            idx++;
            srcp += 5;
            dstp += 3;
        } while (idx < 4);
    }
    fn_80144DC8(frame.spB0);
    fn_801BFB2C(found, frame.spB0, (FV3 *)frame.sp80);
    ((void (*)(float *, float *, float *))fn_801BF75C)((float *)((char *)found + 0x230), frame.sp50, frame.spB0);
    {
        int idx = 0;
        int *dstp = frame.sp38;
        int *srcp = arg6;
        while (idx < arg5) {
            dstp[0] = *srcp;
            dstp[1] = fn_801602B4(arg0);
            srcp++;
            idx++;
            dstp[2] = 0;
            dstp += 3;
        }
    }
    fn_801C1CBC(*(int *)((char *)found + 0x214), 4, frame.spE0, 6, frame.sp130, arg5, frame.sp38);
    {
        int r26v = fn_801BF754(arg0);
        int r25v = fn_801602B4(arg0);
        fn_801C256C(*(int *)((char *)found + 0x214), fn_8017EAFC(arg0), r25v + 0x24, r26v);
    }
    return 1;
    }
    }
    }
    }
    return 0;
}
#pragma pop
int fn_801BF754(int arg0) { return arg0 + 0x124; }

extern float fn_80144514(float, float, float, float, float, float);
#pragma push
#pragma processor 750
void fn_801BF75C(float *arg0, const float *arg1, const float *arg2, int arg3) {
    union { unsigned int bits[9]; float values[9]; } local;
    register float *localPtr = local.values;
    float t3, t5, t4;
    float temp_f1;
    float temp_f24, temp_f25, temp_f26, temp_f27;
    float temp_f28, temp_f29, temp_f30, temp_f31;
    float dx, dy, dz, a0, a1, a2, b0, b1, b2, c0, c1, c2;

    ((FV3 *)local.values)[0] = ((const FV3 *)arg2)[0];
    ((FV3 *)local.values)[1] = ((const FV3 *)arg2)[1];
    ((FV3 *)local.values)[2] = ((const FV3 *)arg2)[2];
    t3 = localPtr[1];
    t5 = localPtr[2];
    t4 = localPtr[5];
    localPtr[1] = localPtr[3];
    localPtr[3] = t3;
    localPtr[2] = localPtr[6];
    localPtr[6] = t5;
    localPtr[5] = localPtr[7];
    localPtr[7] = t4;

    if (arg0 == arg1 || arg0 == local.values) {
        temp_f24 = fn_80144514(localPtr[0], arg1[0], localPtr[3], arg1[1], localPtr[6], arg1[2]);
        temp_f25 = fn_80144514(localPtr[0], arg1[3], localPtr[3], arg1[4], localPtr[6], arg1[5]);
        temp_f26 = fn_80144514(localPtr[0], arg1[6], localPtr[3], arg1[7], localPtr[6], arg1[8]);
        temp_f27 = fn_80144514(localPtr[1], arg1[0], localPtr[4], arg1[1], localPtr[7], arg1[2]);
        temp_f28 = fn_80144514(localPtr[1], arg1[3], localPtr[4], arg1[4], localPtr[7], arg1[5]);
        temp_f29 = fn_80144514(localPtr[1], arg1[6], localPtr[4], arg1[7], localPtr[7], arg1[8]);
        temp_f30 = fn_80144514(localPtr[2], arg1[0], localPtr[5], arg1[1], localPtr[8], arg1[2]);
        temp_f31 = fn_80144514(localPtr[2], arg1[3], localPtr[5], arg1[4], localPtr[8], arg1[5]);
        temp_f1 = fn_80144514(localPtr[2], arg1[6], localPtr[5], arg1[7], localPtr[8], arg1[8]);
        arg0[0] = temp_f24;
        arg0[3] = temp_f25;
        arg0[6] = temp_f26;
        arg0[1] = temp_f27;
        arg0[4] = temp_f28;
        arg0[7] = temp_f29;
        arg0[2] = temp_f30;
        arg0[5] = temp_f31;
        arg0[8] = temp_f1;
    } else {
        arg0[0] = fn_80144514(localPtr[0], arg1[0], localPtr[3], arg1[1], localPtr[6], arg1[2]);
        arg0[3] = fn_80144514(localPtr[0], arg1[3], localPtr[3], arg1[4], localPtr[6], arg1[5]);
        arg0[6] = fn_80144514(localPtr[0], arg1[6], localPtr[3], arg1[7], localPtr[6], arg1[8]);
        arg0[1] = fn_80144514(localPtr[1], arg1[0], localPtr[4], arg1[1], localPtr[7], arg1[2]);
        arg0[4] = fn_80144514(localPtr[1], arg1[3], localPtr[4], arg1[4], localPtr[7], arg1[5]);
        arg0[7] = fn_80144514(localPtr[1], arg1[6], localPtr[4], arg1[7], localPtr[7], arg1[8]);
        arg0[2] = fn_80144514(localPtr[2], arg1[0], localPtr[5], arg1[1], localPtr[8], arg1[2]);
        arg0[5] = fn_80144514(localPtr[2], arg1[3], localPtr[5], arg1[4], localPtr[8], arg1[5]);
        arg0[8] = fn_80144514(localPtr[2], arg1[6], localPtr[5], arg1[7], localPtr[8], arg1[8]);
    }
    a0 = arg1[9]; a1 = arg2[9]; b1 = arg2[10];
    dx = a0 - a1;
    arg0[9] = dx;
    a2 = arg2[0]; b0 = arg2[3]; c0 = arg2[6];
    dy = arg1[10] - b1;
    arg0[10] = dy;
    b1 = arg2[4]; a1 = arg2[1]; c1 = arg2[7];
    a0 = arg2[2]; b2 = arg2[5]; c2 = arg2[8];
    dz = arg1[11] - arg2[11];
    a0 = (dy * a1 + dx * a2) + dz * a0;
    b2 = (dy * b1 + dx * b0) + dz * b2;
    c2 = (dy * c1 + dx * c0) + dz * c2;
    arg0[9] = a0; arg0[10] = b2; arg0[11] = c2;
}
#pragma pop
void fn_801BFD34(float *, float *, const float *);
/* Builds an orthonormal basis from four indexed points in the point array:
 * origin at index *(int*)(base+0x21C), axes from (idx 0x224-0x220) and
 * (idx 0x22C-0x228). Falls back to identity axes when the cross product is
 * degenerate (dot <= lbl_805628CC), then stores the resulting transform parts
 * via fn_801BFD34/fn_80015B20. */
void fn_801BFB2C(char *base, float *out, FV3 *points) {
    float normal[3], axis1[3], axis0[3];
    float basis[12];
    FV3 *pA, *pB;
    float z, y, x;

    pA = &points[*(int *)(base + 0x21C)];
    x = pA->x; y = pA->y; z = pA->z;
    basis[9] = x; basis[10] = y; basis[11] = z;
    pA = &points[*(int *)(base + 0x220)];
    pB = &points[*(int *)(base + 0x224)];
    x = pB->x - pA->x; y = pB->y - pA->y; z = pB->z - pA->z;
    basis[0] = x; basis[1] = y; basis[2] = z;
    pA = &points[*(int *)(base + 0x228)];
    pB = &points[*(int *)(base + 0x22C)];
    x = pB->x - pA->x; y = pB->y - pA->y; z = pB->z - pA->z;
    basis[3] = x; basis[4] = y; basis[5] = z;
    PSVECCrossProduct(&basis[0], &basis[3], &basis[6]);
    if (PSVECDotProduct(&basis[6], &basis[6]) > lbl_805628CC) {
        float a0, a1, a2, b0, b1, b2;
        a2 = basis[2]; a1 = basis[1]; a0 = basis[0]; b2 = basis[8]; b1 = basis[7]; b0 = basis[6];
        axis0[0] = a0; axis0[1] = a1; axis0[2] = a2;
        normal[0] = b0; normal[1] = b1; normal[2] = b2;
        PSVECCrossProduct(normal, axis0, axis1);
        PSVECNormalize(axis0, axis0);
        PSVECNormalize(axis1, axis1);
        PSVECCrossProduct(axis0, axis1, normal);
        basis[0] = axis0[0]; basis[1] = axis0[1]; basis[2] = axis0[2];
        basis[3] = axis1[0]; basis[4] = axis1[1]; basis[5] = axis1[2];
        basis[6] = normal[0]; basis[7] = normal[1]; basis[8] = normal[2];
    } else {
        float zero = lbl_805628B8, one = lbl_805628BC;
        basis[1] = zero;
        basis[0] = one;
        basis[2] = zero;
        basis[3] = zero;
        basis[4] = one;
        basis[5] = zero;
        basis[6] = zero;
        basis[7] = zero;
        basis[8] = one;
    }
    fn_801BFD34(out + 9, (float *)(base + 0x254), basis);
    fn_80015B20(out, base + 0x230, basis);
}

#pragma dont_inline off
#pragma opt_propagation reset

void fn_801BFD34(float *out, float *in, const float *m) {
    if (out == in) {
        float y = in[1];
        float y0 = y * m[3];
        float y1 = y * m[4];
        float y2 = y * m[5];

        float x = in[0];
        float x0 = x * m[0];
        float x1 = x * m[1];
        float x2 = x * m[2];

        float z = in[2];
        float z0 = z * m[6];
        float z1 = z * m[7];
        float z2 = z * m[8];

        out[0] = (x0 + y0) + z0;
        out[1] = (x1 + y1) + z1;
        out[2] = (x2 + y2) + z2;
    } else {
        float m0 = m[0], m1 = m[1], m2 = m[2];
        float m3 = m[3], m4 = m[4], m5 = m[5];
        float m6 = m[6], m7 = m[7], m8 = m[8];

        out[0] = (m3 * in[1] + m0 * in[0]) + m6 * in[2];
        out[1] = (m4 * in[1] + m1 * in[0]) + m7 * in[2];
        out[2] = (m5 * in[1] + m2 * in[0]) + m8 * in[2];
    }
    {
        float tx = out[0] + m[9];
        float ty = out[1] + m[10];
        float tz = out[2] + m[11];
        out[0] = tx;
        out[1] = ty;
        out[2] = tz;
    }
}

void fn_801BFE7C(float *arg0, float *arg1, float *arg2) {
    float x = arg1[0] + arg2[0];
    float y = arg1[1] + arg2[1];
    float z = arg1[2] + arg2[2];
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

void fn_801BFEB0(void) {

}

long fn_801BFEB4(long arg0) { return arg0 + 0x6C; }

void GXInitLightAttnA_801BFEBC(void *arg0, float farg0, float farg1, float farg2) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
}

#pragma scheduling on
void fn_801BFECC(void *arg0, void *arg1) {
    int a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0;
    a3 = *(volatile int *)((char *)arg1 + 0x0C);
    a4 = *(volatile int *)((char *)arg1 + 0x10);
    a2 = *(volatile int *)((char *)arg1 + 0x08);
    a1 = *(volatile int *)((char *)arg1 + 0x04);
    a0 = *(volatile int *)((char *)arg1 + 0x00);
    a5 = *(volatile int *)((char *)arg1 + 0x14);
    a6 = *(volatile int *)((char *)arg1 + 0x18);
    a7 = *(volatile int *)((char *)arg1 + 0x1C);
    a8 = *(volatile int *)((char *)arg1 + 0x20);
    a9 = *(volatile int *)((char *)arg1 + 0x24);
    a10 = *(volatile int *)((char *)arg1 + 0x28);
    a11 = *(volatile int *)((char *)arg1 + 0x2C);
    *(int *)((char *)arg0 + 0x3C) = a0;
    *(int *)((char *)arg0 + 0x40) = a1;
    *(int *)((char *)arg0 + 0x44) = a2;
    *(int *)((char *)arg0 + 0x48) = a3;
    *(int *)((char *)arg0 + 0x4C) = a4;
    *(int *)((char *)arg0 + 0x50) = a5;
    *(int *)((char *)arg0 + 0x54) = a6;
    *(int *)((char *)arg0 + 0x58) = a7;
    *(int *)((char *)arg0 + 0x5C) = a8;
    *(int *)((char *)arg0 + 0x60) = a9;
    *(int *)((char *)arg0 + 0x64) = a10;
    *(int *)((char *)arg0 + 0x68) = a11;
    ((void (*)(void *, void *, int, int, int, int, int, int))fn_8017A580)(arg0, arg1, a10, a9, a8, a7, a6, a5);
}

static inline void inline_transform_vec(float *out, const float *in, const float *m) {
    if (out == in) {
        float y0 = m[3] * in[1];
        float y1 = m[4] * in[1];
        float y2 = m[5] * in[1];

        float x0 = m[0] * in[0];
        float x1 = m[1] * in[0];
        float x2 = m[2] * in[0];

        float z0 = m[6] * in[2];
        float z1 = m[7] * in[2];
        float z2 = m[8] * in[2];

        out[0] = z0 + (x0 + y0);
        out[1] = z1 + (x1 + y1);
        out[2] = z2 + (x2 + y2);
    } else {
        {
            float m3 = m[3];
            float y0 = in[1] * m3;
            float m0 = m[0];
            float x0 = in[0] * m0;
            float m6 = m[6];
            float z0 = in[2] * m6;
            out[0] = (x0 + y0) + z0;
        }
        {
            float m4 = m[4];
            float y1 = in[1] * m4;
            float m1 = m[1];
            float x1 = in[0] * m1;
            float m7 = m[7];
            float z1 = in[2] * m7;
            out[1] = (x1 + y1) + z1;
        }
        {
            float m5 = m[5];
            float y2 = in[1] * m5;
            float m2 = m[2];
            float x2 = in[0] * m2;
            float m8 = m[8];
            float z2 = in[2] * m8;
            out[2] = (x2 + y2) + z2;
        }
    }
}

void fn_801BFF64(float *m, const float *in) {
    float tmp[3];
    inline_transform_vec(tmp, in, m);
    m[9] += tmp[0];
    m[10] += tmp[1];
    m[11] += tmp[2];
}

extern void fn_8019EECC(void *, void *);
void fn_801C00B8(void *arg0, float *arg1) {
    void *callback = *(void **)((char *)arg0 + 4);
    void *self = arg0;
    float z = arg1[2];
    float y = arg1[1];
    float x = arg1[0];
    *(float *)((char *)arg0 + 0x28) = x;
    *(float *)((char *)arg0 + 0x2C) = y;
    *(float *)((char *)arg0 + 0x30) = z;
    if (callback == 0) return;
    fn_8019EECC(callback, (char *)self + 0x28);
}

long fn_801C00F0(void *arg0) { return *(long *)((char *)arg0 + 0x18); }

long fn_801C00F8(void *arg0, long arg1) {
    if (arg1 >= 0 && arg1 < *(long *)((char *)arg0 + 0x24))
        return *(long *)((char *)arg0 + arg1 * 4 + 0x14);
    return 0;
}

void fn_801C0124(float *arg0, float *arg1, float arg2) {
    float z, y, x;
    x = arg1[0];
    y = arg1[1];
    z = arg1[2];
    x *= arg2;
    y *= arg2;
    z *= arg2;
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

extern void fn_8017A580(int, int, int, int, int, int);
extern void fn_8017A57C(float, float);
void fn_801C014C(void *arg0, float *arg1) {
    float temp_f2 = arg1[0];
    float temp_f1 = arg1[1];
    float temp_f0 = arg1[2];
    *(float *)((char *)arg0 + 0x30) = temp_f2;
    *(float *)((char *)arg0 + 0x34) = temp_f1;
    *(float *)((char *)arg0 + 0x38) = temp_f0;
    fn_8017A57C(temp_f1, temp_f2);
}

int fn_801C0168(void *arg0) { return *(int *)((char *)arg0 + 0x5A4); }

int fn_801C0170(void *arg0) { return *(int *)((char *)arg0 + 0x59C); }

float fn_801C0178(void) { extern float lbl_8055E3C8; return lbl_8055E3C8; }

extern void fn_801C1C7C(void *, int);
extern void fn_80179EE8(void *, int);
extern void fn_80128668(void *);
extern int lbl_8055E7BC;
extern char lbl_80336A90[];
void *fn_801C0180(void *arg0, int arg1) {
    int temp_r4;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80336A90;
        temp_r4 = lbl_8055E7BC;
        lbl_8055E7BC = temp_r4 - 1;
        fn_801C1C7C(*(void **)((char *)arg0 + 0x214), temp_r4);
        if (arg0 != 0) fn_80179EE8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

/* Initializes an object (arg0) with setup params from arg1, sets default transform/volume fields, creates a "panelvol" subobject, attaches it, and clears a flag at 0x1E8. */
void fn_801C0204(void *obj, int *param) {
    struct Setup {
        int value;
        int size;
        float first;
        float second;
        float third;
        float fourth;
    };
    struct Frame {
        float stack0;
        float stack1;
        float stack2;
        float stack3;
        float stack4;
        float stack5;
        float stack6;
        float stack7;
        float stack8;
        float stack9;
        volatile struct Setup setup;
    };
    extern void *memset(void *, int, unsigned int);
    extern void fn_8017B0F8(void *, void *);
    extern void *fn_801284F8(int, void *);
    extern void *fn_801A25F8(void *, void *, int, void *, float);
    extern void fn_80179F94(void *, void *);
    extern float lbl_805628B8, lbl_805628D0, lbl_805628D4, lbl_805628D8;
    extern float lbl_805628DC, lbl_805628E0, lbl_805628E4;
    extern char lbl_80336AE4[];
    struct Frame frame;
    void *result;
    memset((void *)&frame.setup, 0, 0x18);
    {
        float next, first;
        int value;
        /* lbl_805628D0 = 45.45, lbl_805628D4 = 4.22799 */
        first = *(volatile float *)&lbl_805628D0;
        frame.setup.size = 0x18;
        next = *(volatile float *)&lbl_805628D4;
        value = *(volatile int *)param;
        frame.setup.value = value;
        frame.setup.first = first;
        frame.setup.second = next;
        frame.setup.third = next;
        frame.setup.fourth = next;
    }
    fn_8017B0F8(obj, (void *)&frame.setup);
    {
        float f3 = lbl_805628B8;
        float f2 = lbl_805628D8;
        float f1 = lbl_805628DC;
        float f0 = lbl_805628E0;
        *(float *)((char *)obj + 0x1FC) = f3;
        *(float *)((char *)obj + 0x200) = f3;
        *(float *)((char *)obj + 0x204) = f2;
        *(float *)((char *)obj + 0x208) = f3;
        *(float *)((char *)obj + 0x20C) = f1;
        *(float *)((char *)obj + 0x210) = f0;
        frame.stack6 = f3;
        frame.stack1 = f3;
        frame.stack5 = f3;
        result = ((void *(*)(int, const char *, float, float, float))fn_801284F8)(
            0x34, lbl_80336AE4, f1, f2, f3);
    }
    if (result != 0) {
        float value = lbl_805628E4;
        int field = *(int *)((char *)obj + 0x214);
        result = fn_801A25F8(result, (char *)obj + 0x3C, field, obj, value);
    }
    fn_80179F94(obj, result);
    *(unsigned char *)((char *)obj + 0x1E8) = 0;
}

static inline void helper_801C02F4(void *self, int flag) {
    if (flag) {
        *(int *)((char *)self + 0x1F0) = 0;
    } else {
        *(int *)((char *)self + 0x1F0) = -1;
    }
}

#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_801C02F4(void *arg0) {
    struct Mat43 {
        float m[4][3];
    };
    extern float lbl_805628B8, lbl_805628BC, lbl_805628E8, lbl_805628EC;
    extern void fn_8017B164(void *);
    struct Mat43 mat;
    float f;
    int flag;

    f = lbl_805628E8;
    *(int *)((char *)arg0 + 0x1EC) = 0;
    *(float *)((char *)arg0 + 0x218) = f;
    flag = 0;
    if (flag) {
        *(int *)((char *)arg0 + 0x1F0) = 0;
    } else {
        *(int *)((char *)arg0 + 0x1F0) = -1;
    }
    fn_8017B164(arg0);

    mat.m[0][0] = lbl_805628BC;
    mat.m[0][1] = lbl_805628B8;
    mat.m[0][2] = lbl_805628B8;
    mat.m[1][0] = lbl_805628B8;
    mat.m[1][1] = lbl_805628BC;
    mat.m[1][2] = lbl_805628B8;
    mat.m[2][0] = lbl_805628B8;
    mat.m[2][1] = lbl_805628B8;
    mat.m[2][2] = lbl_805628BC;
    mat.m[3][0] = lbl_805628B8;
    mat.m[3][2] = lbl_805628B8;
    mat.m[3][1] = lbl_805628EC;

    *(int *)((char *)arg0 + 0x1F4) = -1;
    *(int *)((char *)arg0 + 0x1F8) = 0;
    *(struct Mat43 *)((char *)arg0 + 0x3C) = mat;
    ((void (*)(void *))fn_8017A580)(arg0);

    {
        float f0, f1, f2;
        f2 = lbl_805628B8;
        f1 = lbl_805628E8;
        f0 = lbl_805628BC;
        *(float *)((char *)arg0 + 0x118) = f2;
        *(float *)((char *)arg0 + 0x11C) = f2;
        *(float *)((char *)arg0 + 0x120) = f2;
        *(float *)((char *)arg0 + 0x124) = f2;
        *(float *)((char *)arg0 + 0x128) = f2;
        *(float *)((char *)arg0 + 0x12C) = f2;
        *(float *)((char *)arg0 + 0x260) = f2;
        *(float *)((char *)arg0 + 0x264) = f1;
        *(float *)((char *)arg0 + 0x268) = f2;
        *(float *)((char *)arg0 + 0x26C) = f2;
        *(float *)((char *)arg0 + 0x270) = f0;
        *(float *)((char *)arg0 + 0x274) = f2;
    }
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
int fn_801C0440(void *arg0) {
    return *(int *)((char *)arg0 + 0x1EC) != 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_801C0454(void *arg0) {
    extern void fn_80144DAC(float *, float *);
    extern void fn_80144DC8(void *);
    extern void fn_8017C7C8(void *, void *, void *);
    extern int fn_801E9E78(void *, float *, float *, void *, int);
    extern void fn_801C2694(int, void *, int *, float *, float *, void *, void *);
    extern float fn_80144CC8(float);
    extern void fn_801C092C(void *, void *, void *, int);
    extern void fn_801C0D3C(void *);
    extern void fn_801C0D6C(void *);
    extern void fn_801C0E44(void *);
    extern void fn_801C0E4C(void *, void *, void *);
    extern void fn_801C0E60(float *, float *, float *);
    extern float lbl_805628C8;
    extern float lbl_805628F0;
    extern float lbl_805628F4;
    extern float lbl_805628F8;
    extern float lbl_805628FC;
    struct Pt { float x, y, z; };
    struct {
        float sp8;
        int spC;
        float tmp10[48];
        float spD0[3];
        float spDC[3];
        float spE8[3];
        float spF4[3];
        float sp100[12];
        float sp130[12];
        struct Pt pts[14];
    } frame;
    int i;
    int n;
    float f31;
    if (*(int *)((char *)arg0 + 0x1EC) != 0) {
        if (*(int *)((char *)arg0 + 0x214) != 0) {
            fn_8017C7C8(arg0, frame.spF4, frame.spE8);
            frame.spC = 8;
            *(int *)&frame.spDC[0] = *(int *)((char *)arg0 + 0x60);
            *(int *)&frame.spDC[1] = *(int *)((char *)arg0 + 0x64);
            *(int *)&frame.spDC[2] = *(int *)((char *)arg0 + 0x68);
            if (fn_801E9E78((char *)arg0 + 0x6C, frame.spDC, frame.spD0, &frame.sp8, *(int *)((char *)arg0 + 0x60)) != 0) {
                frame.spDC[0] = frame.spDC[0] + (frame.spD0[0] * lbl_805628C8);
                frame.spDC[1] = frame.spDC[1] + (frame.spD0[1] * lbl_805628C8);
                frame.spDC[2] = frame.spDC[2] + (frame.spD0[2] * lbl_805628C8);
                frame.spD0[0] = frame.spD0[0] * lbl_805628F0;
                frame.spD0[1] = frame.spD0[1] * lbl_805628F0;
                frame.spD0[2] = frame.spD0[2] * lbl_805628F0;
                frame.spD0[0] = frame.spD0[0] + (*(float *)((char *)arg0 + 0x26C) * lbl_805628F4);
                frame.spD0[1] = frame.spD0[1] + (*(float *)((char *)arg0 + 0x270) * lbl_805628F4);
                frame.spD0[2] = frame.spD0[2] + (*(float *)((char *)arg0 + 0x274) * lbl_805628F4);
                PSVECNormalize(frame.spD0, frame.spD0);
                *(float *)((char *)arg0 + 0x260) = frame.spDC[0];
                *(float *)((char *)arg0 + 0x264) = frame.spDC[1];
                *(float *)((char *)arg0 + 0x268) = frame.spDC[2];
                *(float *)((char *)arg0 + 0x26C) = frame.spD0[0];
                *(float *)((char *)arg0 + 0x270) = frame.spD0[1];
                *(float *)((char *)arg0 + 0x274) = frame.spD0[2];
                fn_801C2694(*(int *)((char *)arg0 + 0x214), frame.pts, &frame.spC, frame.spDC, frame.spD0, frame.spF4, frame.spE8);
                n = frame.spC;
                for (i = 0; i < n; i++) {
                    struct Pt v = frame.pts[i];
                    v.y += lbl_805628F8;
                    frame.pts[i] = v;
                }
                fn_80144DC8(&frame.sp100[0]);
                fn_80144DAC(&frame.sp100[9], &frame.pts[*(int *)((char *)arg0 + 0x21C)].x);
                fn_801C0E60(&frame.sp100[0], &frame.pts[*(int *)((char *)arg0 + 0x224)].x, &frame.pts[*(int *)((char *)arg0 + 0x220)].x);
                fn_801C0E60(&frame.sp100[3], &frame.pts[*(int *)((char *)arg0 + 0x22C)].x, &frame.pts[*(int *)((char *)arg0 + 0x228)].x);
                fn_801C0E4C(&frame.sp100[6], &frame.sp100[0], &frame.sp100[3]);
                f31 = fn_80144CC8(lbl_805628FC);
                if (((float (*)(void *))fn_801C0E44)(&frame.sp100[6]) > f31) {
                    fn_801C0D6C(&frame.sp100[0]);
                } else {
                    fn_801C0D3C(&frame.sp100[0]);
                }
                ((void (*)(void *, void *, void *))fn_801C092C)(frame.sp130, (char *)arg0 + 0x230, &frame.sp100[0]);
                {
                    struct Pt *dst = (struct Pt *)((char *)arg0 + 0x3C);
                    struct Pt *src = (struct Pt *)frame.sp130;
                    dst[0] = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                    dst[3] = src[3];
                }
                ((void (*)(void *))fn_8017A580)(arg0);
            }
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma optimization_level 3
void fn_801C092C(void *arg0, void *arg1, void *arg2, int arg3) {
    float *out = (float *)arg0;
    float *input = (float *)arg1;
    float *matrix = (float *)arg2;
    float temp_f24, temp_f25, temp_f26, temp_f27;
    float temp_f28, temp_f29, temp_f30, temp_f31;
    float temp_f1;

    if ((char *)out + 0x24 == (char *)input + 0x24) {
        float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;

        f0 = matrix[3];
        f6 = input[10];
        f2 = matrix[4];
        f4 = f6 * f0;
        f11 = matrix[5];
        f1 = matrix[0];
        f5 = input[9] * f1;
        f3 = matrix[1];
        f2 = f6 * f2;
        f0 = input[9];
        f3 = f0 * f3;
        f10 = matrix[2];
        f8 = matrix[6];
        f1 = f0 * f10;
        f0 = f6 * f11;
        f7 = input[11];
        f9 = matrix[7];
        f5 = f5 + f4;
        f6 = f7 * f8;
        f12 = matrix[8];
        f3 = f3 + f2;
        f4 = f7 * f9;
        f0 = f1 + f0;
        f2 = f7 * f12;
        f5 = f6 + f5;
        f1 = f4 + f3;
        f0 = f2 + f0;
        out[9] = f5;
        out[10] = f1;
        out[11] = f0;
    } else {
        out[9] = matrix[6] * input[11] + (matrix[0] * input[9] + matrix[3] * input[10]);
        out[10] = matrix[7] * input[11] + (matrix[1] * input[9] + matrix[4] * input[10]);
        out[11] = matrix[8] * input[11] + (matrix[2] * input[9] + matrix[5] * input[10]);
    }

    out[9] += matrix[9];
    out[10] += matrix[10];
    out[11] += matrix[11];

    if (out == input || out == matrix) {
        temp_f24 = fn_80144514(matrix[0], input[0], matrix[3], input[1], matrix[6], input[2]);
        temp_f25 = fn_80144514(matrix[0], input[3], matrix[3], input[4], matrix[6], input[5]);
        temp_f26 = fn_80144514(matrix[0], input[6], matrix[3], input[7], matrix[6], input[8]);
        temp_f27 = fn_80144514(matrix[1], input[0], matrix[4], input[1], matrix[7], input[2]);
        temp_f28 = fn_80144514(matrix[1], input[3], matrix[4], input[4], matrix[7], input[5]);
        temp_f29 = fn_80144514(matrix[1], input[6], matrix[4], input[7], matrix[7], input[8]);
        temp_f30 = fn_80144514(matrix[2], input[0], matrix[5], input[1], matrix[8], input[2]);
        temp_f31 = fn_80144514(matrix[2], input[3], matrix[5], input[4], matrix[8], input[5]);
        temp_f1 = fn_80144514(matrix[2], input[6], matrix[5], input[7], matrix[8], input[8]);
        out[0] = temp_f24;
        out[3] = temp_f25;
        out[6] = temp_f26;
        out[1] = temp_f27;
        out[4] = temp_f28;
        out[7] = temp_f29;
        out[2] = temp_f30;
        out[5] = temp_f31;
        out[8] = temp_f1;
    } else {
        out[0] = fn_80144514(matrix[0], input[0], matrix[3], input[1], matrix[6], input[2]);
        out[3] = fn_80144514(matrix[0], input[3], matrix[3], input[4], matrix[6], input[5]);
        out[6] = fn_80144514(matrix[0], input[6], matrix[3], input[7], matrix[6], input[8]);
        out[1] = fn_80144514(matrix[1], input[0], matrix[4], input[1], matrix[7], input[2]);
        out[4] = fn_80144514(matrix[1], input[3], matrix[4], input[4], matrix[7], input[5]);
        out[7] = fn_80144514(matrix[1], input[6], matrix[4], input[7], matrix[7], input[8]);
        out[2] = fn_80144514(matrix[2], input[0], matrix[5], input[1], matrix[8], input[2]);
        out[5] = fn_80144514(matrix[2], input[3], matrix[5], input[4], matrix[8], input[5]);
        out[8] = fn_80144514(matrix[2], input[6], matrix[5], input[7], matrix[8], input[8]);
    }
}

void fn_801C0D3C(void *arg0)
{
    float *o = (float *)arg0;
    float a = lbl_805628B8;
    float b = lbl_805628BC;
    o[1] = a;
    o[0] = b;
    o[2] = a;
    o[3] = a;
    o[4] = b;
    o[5] = a;
    o[6] = a;
    o[7] = a;
    o[8] = b;
}

#pragma pop
/* Reverse-ordered scalar loads keep the vector copies and final register restore matching. */
void fn_801C0D6C(void *arg0) {
    extern void PSVECNormalize(void *, void *);
    float vec1[3];
    float cross[3];
    float vec0[3];
    float *input = (float *)arg0;
    float x, y, z, a, b, c;
    z = input[2];
    y = input[1];
    x = input[0];
    vec0[0] = x;
    vec0[1] = y;
    vec0[2] = z;
    c = input[8];
    b = input[7];
    a = input[6];
    vec1[0] = a;
    vec1[1] = b;
    vec1[2] = c;
    PSVECCrossProduct(vec1, vec0, cross);
    PSVECNormalize(vec0, vec0);
    PSVECNormalize(cross, cross);
    PSVECCrossProduct(vec0, cross, vec1);
    input[0] = vec0[0];
    input[1] = vec0[1];
    input[2] = vec0[2];
    input[3] = cross[0];
    input[4] = cross[1];
    input[5] = cross[2];
    input[6] = vec1[0];
    input[7] = vec1[1];
    input[8] = vec1[2];
}
#pragma scheduling on
extern float PSVECDotProduct(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern float lbl_805628B8;
extern float lbl_805628BC;
void fn_801C0E44(void *arg0) { PSVECDotProduct(arg0, arg0); }

void fn_801C0E4C(void *arg0, void *arg1, void *arg2) {
    PSVECCrossProduct(arg1, arg2, arg0);
}

void fn_801C0E60(float *arg0, float *arg1, float *arg2) {
    float x = arg1[0] - arg2[0];
    float y = arg1[1] - arg2[1];
    float z = arg1[2] - arg2[2];
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_801C0E94(void *arg0, int arg1) {
    extern float lbl_805628BC, lbl_8055E460;
    extern char lbl_80558DC4[];
    unsigned char *src = (unsigned char *)arg0;
    unsigned char *dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    float base = lbl_805628BC;
    float top = lbl_8055E460;
    float delta = top - base;
    if ((float)fabs(delta) <= *(float *)lbl_80558DC4) {
        unsigned int v0 = *(unsigned int *)(src + 0x70);
        unsigned int v1 = *(unsigned int *)(src + 0x74);
        *(unsigned int *)(dst + 0x00) = v0;
        *(unsigned int *)(dst + 0x04) = v1;
        v0 = *(unsigned int *)(src + 0x78);
        v1 = *(unsigned int *)(src + 0x7C);
        *(unsigned int *)(dst + 0x08) = v0;
        *(unsigned int *)(dst + 0x0C) = v1;
        v0 = *(unsigned int *)(src + 0x80);
        v1 = *(unsigned int *)(src + 0x84);
        *(unsigned int *)(dst + 0x10) = v0;
        *(unsigned int *)(dst + 0x14) = v1;
        v0 = *(unsigned int *)(src + 0x88);
        v1 = *(unsigned int *)(src + 0x8C);
        *(unsigned int *)(dst + 0x18) = v0;
        *(unsigned int *)(dst + 0x1C) = v1;
        *(unsigned int *)(dst + 0x20) = *(unsigned int *)(src + 0x90);
        v0 = *(unsigned int *)(src + 0x94);
        v1 = *(unsigned int *)(src + 0x98);
        *(unsigned int *)(dst + 0x24) = v0;
        *(unsigned int *)(dst + 0x28) = v1;
        *(unsigned int *)(dst + 0x2C) = *(unsigned int *)(src + 0x9C);
    } else {
        float temp[12];
        float *a = (float *)(src + 0x70);
        float *b = (float *)(src + 0xA0);
        int i;
        for (i = 0; i < 2; i++) {
            float a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3], a4 = a[4], a5 = a[5];
            float b0 = b[0], b1 = b[1], b2 = b[2], b3 = b[3], b4 = b[4], b5 = b[5];
            temp[i * 6 + 0] = b0 + top * (a0 - b0);
            temp[i * 6 + 1] = b1 + top * (a1 - b1);
            temp[i * 6 + 2] = b2 + top * (a2 - b2);
            temp[i * 6 + 3] = b3 + top * (a3 - b3);
            temp[i * 6 + 4] = b4 + top * (a4 - b4);
            temp[i * 6 + 5] = b5 + top * (a5 - b5);
            a += 6;
            b += 6;
        }
        *(unsigned int *)(dst + 0x00) = *(unsigned int *)&temp[0];
        *(unsigned int *)(dst + 0x04) = *(unsigned int *)&temp[1];
        *(unsigned int *)(dst + 0x08) = *(unsigned int *)&temp[2];
        *(unsigned int *)(dst + 0x0C) = *(unsigned int *)&temp[3];
        *(unsigned int *)(dst + 0x10) = *(unsigned int *)&temp[4];
        *(unsigned int *)(dst + 0x14) = *(unsigned int *)&temp[5];
        *(unsigned int *)(dst + 0x18) = *(unsigned int *)&temp[6];
        *(unsigned int *)(dst + 0x1C) = *(unsigned int *)&temp[7];
        *(unsigned int *)(dst + 0x20) = *(unsigned int *)&temp[8];
        *(unsigned int *)(dst + 0x24) = *(unsigned int *)&temp[9];
        *(unsigned int *)(dst + 0x28) = *(unsigned int *)&temp[10];
        *(unsigned int *)(dst + 0x2C) = *(unsigned int *)&temp[11];
    }
    *(short *)(dst + 0x30) = *(short *)(src + 0x6C);
    dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    *(unsigned int *)(dst + 0x34) = *(unsigned int *)(src + 0x1F0);
    *(unsigned int *)(dst + 0x38) = *(unsigned int *)(src + 0x1F4);
    *(unsigned int *)(dst + 0x3C) = *(unsigned int *)(src + 0x1F8);
}
#pragma pop
