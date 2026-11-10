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
extern char lbl_8055CC30[4];
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
void fn_802339A8(s32 a, f32 b, s32 c, f32 d, ...);
#pragma push
#pragma processor 750
s32 fn_802A7E08(s32 *arg0, s32 *arg1) {
    unsigned int a[3];
    float dist;
    s32 manager;
    void *obj;
    float f;
    fn_801E85B4();
    manager = (s32)fn_802678C0();
    obj = *(void **)((char *)((void *(*)(int))fn_801EA9A0)(*arg0) + 8);
    a[0] = *(unsigned int *)((char *)obj + 0x24);
    a[1] = *(unsigned int *)((char *)obj + 0x28);
    f = *(float *)&a[1];
    f = f + lbl_80564910;
    a[2] = *(unsigned int *)((char *)obj + 0x2C);
    *(float *)&a[1] = f;
    dist = PSVECSquareDistance((Vec *)a, (Vec *)(manager + 0x24));
    obj = *(void **)((char *)((void *(*)(int))fn_801EA9A0)(*arg1) + 8);
    ((float *)a)[0] = *(float *)((char *)obj + 0x24);
    ((float *)a)[1] = *(float *)((char *)obj + 0x28);
    ((float *)a)[2] = *(float *)((char *)obj + 0x2C);
    ((float *)a)[1] = ((float *)a)[1] + lbl_80564910;
    if (dist > PSVECSquareDistance((Vec *)a, (Vec *)(manager + 0x24))) {
        return -1;
    }
    return 1;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802A7EEC(void) {
    char sp8[8];
    unsigned int position[3];
    float screen[3];
    int array[8];
    int j;
    void *truck;
    int *p;
    int id;
    int i;
    unsigned int xbits;
    void *obj;
    float inverse;
    float opacity;
    float scaledAlpha;
    float dist;
    register f32 c31;
    register f32 c30;
    register f32 c29;
    register f32 c28;
    register f32 c27;
    register f32 c26;
    register f32 c25;
    register f32 c24;
    register f32 c23;

    if (fn_801CF064() != 0) {
        return;
    }

    for (j = 0, p = array; j < fn_801EA994(); j++, p++) {
        *p = j;
    }

    qsort(array, fn_801EA994(), 4, fn_802A7E08);

    c24 = lbl_805648F4;
    p = array;
    c25 = lbl_805648FC;
    c31 = lbl_80564910;
    c30 = lbl_80564914;
    c29 = lbl_80564918;
    c26 = lbl_805648F8;
    c27 = lbl_80564900;
    c28 = lbl_80564920;

    for (i = 0; i < fn_801EA994(); i++, p++) {
        id = *p;
        if (id == fn_801E866C(-1)) {
            continue;
        }

        truck = ((void *(*)(int))fn_801EA9A0)(id);
        obj = *(void **)((char *)truck + 8);
        if (*(u16 *)((char *)obj + 0x6E) & 0x40) {
            continue;
        }
        if (*(int *)((char *)truck + 0x30) != 0) {
            continue;
        }

        xbits = *(unsigned int *)((char *)obj + 0x24);
        position[1] = *(unsigned int *)((char *)obj + 0x28);
        inverse = *(float *)&position[1];
        position[0] = xbits;
        inverse = inverse + c31;
        position[2] = *(unsigned int *)((char *)obj + 0x2C);
        *(float *)&position[1] = inverse;
        fn_802C8E70((float *)position, screen);

        fn_801E85B4();
        dist = PSVECSquareDistance((Vec *)position, (Vec *)((u8 *)fn_802678C0() + 0x24));

        if (fn_802C8FF4(screen, lbl_805648FC) != 0) {
            inverse = (dist - c30) / (c29 - c30);
            opacity = c24;
            opacity = (opacity < inverse) ? opacity : inverse;
            opacity = (opacity > c25) ? opacity : c25;
            opacity = c24 + opacity * c26;
            scaledAlpha = c27 * opacity;
            j = ((unsigned int)(int)scaledAlpha << 24) | 0x00FFFFFF;

            fn_802339A8(lbl_8055F8BC, screen[0], j, screen[1], lbl_805648FC, lbl_8056491C, 0x44, lbl_805648F4, lbl_8055CC30, fn_800122B4(*(u32 *)((char *)truck + 0x10), sp8));
        }

        if (fn_8027AA48() != 0) {
            inverse = (dist - c29) / (c28 * c29 - c29);
            opacity = c24;
            opacity = (opacity < inverse) ? opacity : inverse;
            opacity = (opacity > c25) ? opacity : c25;
            j = *(int *)((char *)truck + 0xAC);
            c23 = c24 + opacity * c26;
            truck = *(void **)((char *)((void *(*)(int))fn_801EA9A0)(fn_801E866C(-1)) + 0xAC);

            fn_8027ABF8((s32)truck);
            if (fn_8027AC50() != 0) {
                fn_8027ABF8((s32)truck);
                if (j == fn_8027AC64()) {
                    fn_802A7CA8((void *)id, c23, 3);
                }
            } else {
                fn_8027ABF8((s32)truck);
                if (fn_8027AC80() != 0) {
                    if (j == *(int *)((char *)fn_8027ABF8((s32)truck) + 0xE8)) {
                        fn_802A7CA8((void *)id, c23, 2);
                    }
                }
            }
        }
    }
}
#pragma pop
