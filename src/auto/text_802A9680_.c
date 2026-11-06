#include "revolution/MTX/mtxtypes.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float PSQUATMultiply(float *, float *);
extern void PSVECNormalize(float *, float *);
extern float PSVECSquareDistance(float *, float *);
extern void fn_801E4F20(int);
extern void fn_801E4F3C(int, int, float, float, float, float, float);
extern void fn_801E4FF4(void);
extern void fn_802C8BD0(int, float, float);
extern void fn_802C8D74(void);
extern float lbl_80564998, lbl_805649B4, lbl_805649B8, lbl_805649BC;
extern float lbl_805649CC, lbl_805649D0, lbl_805649D4;
extern float lbl_805649D8, lbl_805649DC;
extern double lbl_805649E0;
#pragma scheduling invalid_target
extern void fn_802C6CF8();
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
    fn_802C8BD0(arg2, fraction, (float)deltaInt);

    fn_801E4F20(4);
    fn_801E4F3C(color, 0, ((float *)work.vecA)[0], ((float *)work.vecA)[1], ((float *)work.vecA)[2], scaleA, scaleD);
    fn_801E4F3C(color, 0, ((float *)work.vecB)[0], ((float *)work.vecB)[1], ((float *)work.vecB)[2], scaleB, scaleD);
    fn_801E4F3C(color, 1, ((float *)work.vecA)[0], ((float *)work.vecA)[1] + fraction, ((float *)work.vecA)[2], scaleA, scaleC);
    fn_801E4F3C(color, 1, ((float *)work.vecB)[0], ((float *)work.vecB)[1] + fraction, ((float *)work.vecB)[2], scaleB, scaleC);
    fn_801E4FF4();
    fn_802C8D74();
}
#pragma scheduling on
