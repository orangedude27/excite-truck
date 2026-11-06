#include "revolution/MTX/mtxtypes.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float PSQUATMultiply(float *, float *);
extern void PSVECNormalize(float *, float *);
extern float PSVECSquareDistance(float *, float *);
extern void fn_801E4F20(int);
extern void fn_801E4F3C(int, int, float, float, float, float, float);
extern void fn_801E4FF4(void);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern const float lbl_80564998, lbl_805649B4, lbl_805649B8, lbl_805649BC;
extern const float lbl_805649CC, lbl_805649D0, lbl_805649D4;
extern const float lbl_805649D8, lbl_805649DC;
extern const double lbl_805649E0;
#pragma scheduling invalid_target
extern void fn_802C6CF8(int);
extern void fn_80128668(void*);
#pragma scheduling invalid_target
void* fn_802A9680(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 handle = *(s32 *)((u8 *)arg0 + 4);
        if (handle != -1) {
            fn_802C6CF8(handle);
            *(s32 *)((u8 *)arg0 + 4) = -1;
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern void *fn_802C86DC(void);
extern s32 fn_802C8DBC(s32);
extern void fn_802C8E00(s32, s32, float, float, float, float, float);
extern void fn_802C8E48(void);
extern float fn_801E7E18(void);
extern double fn_8002EFB4(double, double);
extern const double lbl_80564990;
extern const float lbl_8056499C, lbl_805649A0, lbl_805649A4, lbl_805649A8, lbl_805649AC, lbl_805649B0, lbl_805649C0, lbl_805649C4, lbl_805649C8;
void fn_802A96E8(void *obj, s32 count, s32 colorArg, s32 arg3, s32 arg4) {
    void *camA;
    void *camB;
    void *camC;
    float e18;
    float f31v;
    float f30v;
    camA = fn_802C86DC();
    camB = fn_802C86DC();
    camC = fn_802C86DC();
    fn_802C8BD0(arg3);
    e18 = fn_801E7E18();
    f31v = lbl_80564998 - (float)fn_8002EFB4(e18, lbl_80564990);
    f30v = lbl_8056499C + f31v;
    if (fn_802C8DBC(count * 4) != 0) {
        float p[3];
        float w;
        float cA0;
        float cA4;
        float c98;
        float cA8;
        float cB0;
        float cAC;
        float cB4;
        float cB8;
        float cC0;
        float *walker;
        s32 i;
        float dist;
        s32 n;
        s32 nn;
        s32 m;
        s32 col;
        cA0 = lbl_805649A0;
        cA4 = lbl_805649A4;
        c98 = lbl_80564998;
        walker = (float *)obj;
        cA8 = lbl_805649A8;
        cB0 = lbl_805649B0;
        i = 0;
        cAC = lbl_805649AC;
        cB4 = lbl_805649B4;
        cB8 = lbl_805649B8;
        cC0 = lbl_805649C0;
        for (; i < count; i++) {
            dist = PSQUATMultiply(walker, (float *)((u8 *)camA + 0x24));
            if (dist < cA0) {
                n = 0x10;
                nn = (s32)(cA8 * (c98 - (cA4 * dist / cA0 - c98) * (cA4 * dist / cA0 - c98)));
                if (nn > 0x10)
                    n = nn;
                m = 0xC4;
                if (n < 0xC4)
                    m = n;
                w = (cAC * (dist - cB0)) / cB4;
                if (c98 > w)
                    w = c98;
                col = (s32)(((u32)m << 24) | ((u32)colorArg & 0xFFFFFF));
                p[0] = walker[0] + ((float *)camB)[0] * (cB8 * -w);
                p[1] = walker[1] + ((float *)camB)[1] * (cB8 * -w);
                p[2] = walker[2] + ((float *)camB)[2] * (cB8 * -w);
                fn_802C8E00(col, 0, p[0], p[1], p[2], lbl_805649BC, f31v);
                p[0] += ((float *)camB)[0] * w;
                p[1] += ((float *)camB)[1] * w;
                p[2] += ((float *)camB)[2] * w;
                fn_802C8E00(col, 0, p[0], p[1], p[2], lbl_80564998, f31v);
                p[0] += ((float *)camB)[0] * -w;
                p[1] = p[1] + cC0 + ((float *)camB)[1] * -w;
                p[2] += ((float *)camB)[2] * -w;
                fn_802C8E00((s32)(colorArg & 0xFFFFFF), 1, p[0], p[1], p[2], lbl_805649BC, f30v);
                p[0] += ((float *)camB)[0] * w;
                p[1] += ((float *)camB)[1] * w;
                p[2] += ((float *)camB)[2] * w;
                fn_802C8E00((s32)(colorArg & 0xFFFFFF), 1, p[0], p[1], p[2], lbl_80564998, f30v);
            }
            walker += 3;
        }
        fn_802C8E48();
    }
    fn_802C8D74();
    if (arg4 != 0) {
        float p[3];
        float w;
        float cA0b;
        float cA4b;
        float c98b;
        float cA8b;
        float cB0b;
        float cACb;
        float cB4b;
        float cC4b;
        float cC8b;
        float cC0b;
        float *walker2;
        s32 j;
        float dist;
        s32 n;
        s32 nn;
        s32 m;
        s32 col;
        fn_802C8BD0(arg4);
        fn_802C8DBC(count * 4);
        cA0b = lbl_805649A0;
        c98b = lbl_80564998;
        cA4b = lbl_805649A4;
        j = 0;
        cA8b = lbl_805649A8;
        cB0b = lbl_805649B0;
        cACb = lbl_805649AC;
        cB4b = lbl_805649B4;
        cC4b = lbl_805649C4;
        cC8b = lbl_805649C8;
        cC0b = lbl_805649C0;
        walker2 = (float *)obj;
        for (; j < count; j++) {
            dist = PSQUATMultiply(walker2, (float *)((u8 *)camA + 0x24));
            if (dist < cA0b) {
                n = 0x10;
                nn = (s32)(cA8b * (c98b - (cA4b * dist / cA0b - c98b) * (cA4b * dist / cA0b - c98b)));
                if (nn > 0x10)
                    n = nn;
                m = 0xC4;
                if (n < 0xC4)
                    m = n;
                w = (cACb * (dist - cB0b)) / cB4b;
                if (c98b > w)
                    w = c98b;
                col = (s32)(((u32)m << 24) | ((u32)colorArg & 0xFFFFFF));
                p[0] = walker2[0] + ((float *)camB)[0] * (cA4b * -w) + ((float *)camC)[6] * cC4b;
                p[1] = walker2[1] + ((float *)camB)[1] * (cA4b * -w) + ((float *)camC)[7] * cC4b;
                p[2] = walker2[2] + ((float *)camB)[2] * (cA4b * -w) + ((float *)camC)[8] * cC4b;
                fn_802C8E00(col, 0, p[0], p[1], p[2], lbl_805649BC, f31v);
                p[0] += ((float *)camB)[0] * (cC8b * w);
                p[1] += ((float *)camB)[1] * (cC8b * w);
                p[2] += ((float *)camB)[2] * (cC8b * w);
                fn_802C8E00(col, 0, p[0], p[1], p[2], lbl_80564998, f31v);
                p[0] += ((float *)camB)[0] * (cC8b * -w);
                p[1] = p[1] + cC0b + ((float *)camB)[1] * (cC8b * -w);
                p[2] += ((float *)camB)[2] * (cC8b * -w);
                fn_802C8E00((s32)(colorArg & 0xFFFFFF), 1, p[0], p[1], p[2], lbl_805649BC, f30v);
                p[0] += ((float *)camB)[0] * (cC8b * w);
                p[1] += ((float *)camB)[1] * (cC8b * w);
                p[2] += ((float *)camB)[2] * (cC8b * w);
                fn_802C8E00((s32)(colorArg & 0xFFFFFF), 1, p[0], p[1], p[2], lbl_80564998, f30v);
            }
            walker2 += 3;
        }
        fn_802C8E48();
        fn_802C8D74();
    }
}

#pragma scheduling on
void fn_802A9BFC(void *arg0, void *arg1, int arg2, int arg3, int arg4,
                 int arg5, int arg6, float farg0, int arg_sp0) {
    struct {
        float direction[3];
        int pad;
        int vecA[3];
        int vecB[3];
    } work;
    float radius;
    float weight;
    float fraction;
    float scaleA;
    float scaleB;
    float scaleC;
    float scaleD;
    int color;
    int deltaInt;
    float maxY;

    work.vecA[1] = ((int *)arg0)[1];
    work.vecB[1] = ((int *)arg1)[1];
    work.vecA[0] = ((int *)arg0)[0];
    work.vecA[2] = ((int *)arg0)[2];
    work.vecB[0] = ((int *)arg1)[0];
    work.vecB[2] = ((int *)arg1)[2];

    maxY = ((float *)work.vecA)[1] > ((float *)work.vecB)[1]
         ? ((float *)work.vecA)[1] : ((float *)work.vecB)[1];
    ((float *)work.vecA)[1] = lbl_805649CC + maxY;
    ((float *)work.vecB)[1] = ((float *)work.vecA)[1];

    radius = lbl_805649D0;
    if (PSVECSquareDistance((float *)work.vecA, (float *)work.vecB) < radius * radius) {
        radius -= PSQUATMultiply((float *)work.vecA, (float *)work.vecB);
        work.direction[0] = ((float *)work.vecA)[0] - ((float *)work.vecB)[0];
        work.direction[1] = ((float *)work.vecA)[1] - ((float *)work.vecB)[1];
        work.direction[2] = ((float *)work.vecA)[2] - ((float *)work.vecB)[2];
        PSVECNormalize(work.direction, work.direction);
        weight = radius * lbl_805649B8;
        ((float *)work.vecA)[0] += work.direction[0] * weight;
        ((float *)work.vecA)[1] += work.direction[1] * weight;
        ((float *)work.vecA)[2] += work.direction[2] * weight;
        weight = -radius * lbl_805649B8;
        ((float *)work.vecB)[0] += work.direction[0] * weight;
        ((float *)work.vecB)[1] += work.direction[1] * weight;
        ((float *)work.vecB)[2] += work.direction[2] * weight;
    }

    fraction = (farg0 - lbl_805649BC) / lbl_805649B8;
    weight = fraction > lbl_80564998 ? fraction : lbl_80564998;
    weight = weight > lbl_805649BC ? lbl_805649BC : weight;

    scaleA = (float)arg3 * lbl_805649D4;
    scaleB = (float)arg5 * lbl_805649D4;
    color = ((int)(lbl_805649BC + weight * lbl_805649B4) << 24) | 0x0FFFFFFF;
    scaleC = (float)arg4 * lbl_805649D4;
    scaleD = (float)arg6 * lbl_805649D4;

    fraction = PSQUATMultiply((float *)work.vecA, (float *)work.vecB) / lbl_805649D8;
    deltaInt = arg6 - arg4;
    fraction = ((float)deltaInt * fraction) / lbl_805649DC;
    fn_802C8BD0(arg2);

    fn_801E4F20(4);
    fn_801E4F3C(color, 0, ((float *)work.vecA)[0], ((float *)work.vecA)[1], ((float *)work.vecA)[2], scaleA, scaleD);
    fn_801E4F3C(color, 0, ((float *)work.vecB)[0], ((float *)work.vecB)[1], ((float *)work.vecB)[2], scaleB, scaleD);
    fn_801E4F3C(color, 1, ((float *)work.vecA)[0], ((float *)work.vecA)[1] + fraction, ((float *)work.vecA)[2], scaleA, scaleC);
    fn_801E4F3C(color, 1, ((float *)work.vecB)[0], ((float *)work.vecB)[1] + fraction, ((float *)work.vecB)[2], scaleB, scaleC);
    fn_801E4FF4();
    fn_802C8D74();
}
#pragma scheduling on
