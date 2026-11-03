#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/MTX/vec.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80235380(void *);
extern s32 lbl_8055F8BC;
extern s32 lbl_8055F8C0;
extern void fn_802328D4(s32);
extern long fn_80232578(void *);
extern long fn_8023512C(void *);
extern long lbl_80349CF0[];
extern long lbl_80349CFC[];
void fn_802A7BE8(void) {
    lbl_8055F8BC = fn_80232578(&lbl_80349CF0);
    lbl_8055F8C0 = fn_8023512C(&lbl_80349CFC);
}

void fn_802A7C24(void) {
    fn_802328D4(lbl_8055F8BC);
    lbl_8055F8BC = 0;
    fn_80235380((void *)lbl_8055F8C0);
    lbl_8055F8C0 = 0;
}

void fn_802A7C64(void) {
}

void fn_802A7EEC(void);
void fn_802A7C68(void) {
    if ((fn_801C5B60() == 0) &&
        ((u32)(*(u32 *)((u8 *)fn_801E87A8() + 4) + 0xFFE80000) != 0x304U)) {
        fn_802A7EEC();
    }
}

extern float lbl_8042F8A8[];
extern float lbl_8042F8B8[];
extern int lbl_8055E170;
extern float lbl_80561474, lbl_80561478, lbl_8056147C;
extern void *fn_801EA9A0(void);
extern void fn_8013B7B4(void*, int);
extern void fn_8013B6C0(int*, float*, int);
extern void fn_802C8E70(float *, float *);
extern int fn_802C8FF4(float *, float);
extern void fn_80235CBC(void *, int, float, float, float, float, float);
extern float lbl_805648F0;
extern float lbl_805648F4;
extern float lbl_805648F8;
extern float lbl_805648FC;
extern float lbl_80564900;
extern float lbl_80564904;
extern float lbl_80564908;
extern float lbl_8056490C;
#pragma paired_single off
void fn_802A7CA8(void *unused, float farg0, int arg1) {
    unsigned int position[3];
    float screen[3];
    unsigned int xbits;
    void *object;
    float inverse;
    float opacity;
    float sizeFactor;
    float size;
    float scaledAlpha;
    unsigned int mask;

    object = *(void **)((char *)fn_801EA9A0() + 8);
    xbits = *(unsigned int *)((char *)object + 0x24);
    position[1] = *(unsigned int *)((char *)object + 0x28);
    inverse = *(float *)&position[1];
    position[0] = xbits;
    inverse = inverse + lbl_805648F0;
    position[2] = *(unsigned int *)((char *)object + 0x2C);
    *(float *)&position[1] = inverse;
    fn_802C8E70((float *)position, screen);

    inverse = (farg0 - lbl_805648F4) / lbl_805648F8;
    opacity = lbl_805648F4;
    opacity = (opacity < inverse) ? opacity : inverse;
    opacity = (opacity > lbl_805648FC) ? opacity : lbl_805648FC;
    opacity = lbl_805648F4 + opacity * lbl_805648F8;
    scaledAlpha = lbl_80564900 * opacity;
    mask = ((unsigned int)(int)scaledAlpha << 24) | 0x00FFFFFF;

    inverse = (farg0 - lbl_805648F4) / lbl_805648F8;
    sizeFactor = lbl_805648F4;
    sizeFactor = (sizeFactor < inverse) ? sizeFactor : inverse;
    sizeFactor = (sizeFactor > lbl_805648FC) ? sizeFactor : lbl_805648FC;
    size = lbl_80564904 + sizeFactor * lbl_80564908;
    if (fn_802C8FF4(screen, lbl_805648FC)) {
        ((void (*)(void *, int, unsigned int, float, float, float, float, float))fn_80235CBC)(
            (void *)lbl_8055F8C0, arg1, mask,
            screen[0] - lbl_8056490C * size,
            screen[1] - lbl_8056490C * size,
            lbl_805648FC, size, size);
    }
}
extern void fn_801E85B4(void);
extern void *fn_802678C0(void);
extern f32 lbl_80564910;
extern f32 lbl_80564914;
extern f32 lbl_80564918;
extern f32 lbl_8056491C;
extern f32 lbl_80564920;
extern char lbl_8055CC30[];
extern s32 fn_801CF064(void);
extern s32 fn_801EA994(void);
extern s32 fn_801E866C(s32);
extern s32 fn_8027AA48(void);
extern void *fn_8027ABF8(s32);
extern s32 fn_8027AC50(void);
extern s32 fn_8027AC64(void);
extern s32 fn_8027AC80(void);
extern s32 fn_800122B4(u32, void *);
void qsort(void *, u32, u32, s32 (*)(s32 *, s32 *));
void fn_802339A8(f32 a, s32 b, f32 c, s32 d, f32 e, f32 f, s32 g, f32 h, const char *fmt, ...);
s32 fn_802A7E08(s32 *arg0, s32 *arg1) {
    f32 a[3];
    f32 dist;
    s32 manager;
    void *obj;

    fn_801E85B4();
    manager = (s32)fn_802678C0();
    obj = *(void **)((u8 *)((s32 (*)(s32))fn_801EA9A0)(*arg0) + 8);
    *(u32 *)&a[1] = *(u32 *)((u8 *)obj + 0x28);
    a[0] = *(f32 *)((u8 *)obj + 0x24);
    a[1] = a[1] + lbl_80564910;
    *(u32 *)&a[2] = *(u32 *)((u8 *)obj + 0x2C);
    dist = PSVECSquareDistance((Vec *)a, (Vec *)((u8 *)manager + 0x24));
    obj = *(void **)((u8 *)((s32 (*)(s32))fn_801EA9A0)(*arg1) + 8);
    a[0] = *(f32 *)((u8 *)obj + 0x24);
    a[1] = *(f32 *)((u8 *)obj + 0x28);
    a[2] = *(f32 *)((u8 *)obj + 0x2C);
    a[1] = a[1] + lbl_80564910;
    if (dist > PSVECSquareDistance((Vec *)a, (Vec *)((u8 *)manager + 0x24))) {
        return -1;
    }
    return 1;
}

