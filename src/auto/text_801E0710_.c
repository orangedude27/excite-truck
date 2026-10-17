// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

extern f64 fn_8002F234(f32);
extern void *fn_801284E8(void *, s32);
extern unsigned int lbl_8032C108;
extern f32 lbl_80562C78;
extern f32 lbl_80562C7C;

extern void *lbl_8055EA10;

extern void NWC24Data_Init_801E1028(void *);
extern void *fn_801E07E8(void *, s32);
extern void fn_8002F53C(void *, void *, void *, s32, s32);
void fn_801E0864(void *arg0) {
    float x;
    float y;
    y = lbl_80562C7C;
    x = lbl_80562C78;
    *(int *)arg0 = -1;
    *((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(float *)((char *)arg0 + 8) = x;
    *(float *)((char *)arg0 + 0xC) = y;
}

int fn_801E0ED4(int arg0, int arg1) {
    return arg1 > arg0 ? arg1 : arg0;
}

#pragma scheduling off
float fn_801E0EE4(void *arg0, void *arg1) {
    float delta[2];
    delta[1] = *(float *)((char *)arg0 + 4) - *(float *)((char *)arg1 + 4);
    delta[0] = *(float *)arg0 - *(float *)arg1;
    return (float)fn_8002F234(delta[0] * delta[0] + delta[1] * delta[1]);
}
#pragma scheduling on
void fn_801E0F34(int arg0) {
    void *ptr;
    int value;
    value = arg0;
    arg0 = (arg0 << 3) + 8;
    ptr = fn_801284E8((void *)&lbl_8032C108, arg0);
    *(int *)((char *)ptr + 4) = value;
    *(int *)ptr = value;
}

void fn_801E0F78(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    f32 x = arg2[0];
    f32 y = arg2[1];
    f32 a = arg1[0];
    f32 b = arg1[1];
    arg0[0] = a + x * arg3;
    arg0[1] = b + y * arg3;
}

f32 fn_801E0FA4(f32 *arg0, f32 *arg1) {
    return arg1[1] * arg0[1] + arg1[0] * arg0[0];
}

void *fn_801E0FC4(void *arg0) {
    void *temp_r6 = (u8 *)arg0 + 0xC;
    ((s32 *)arg0)[2] = 0x64;
    ((void **)arg0)[0] = temp_r6;
    ((s32 *)arg0)[1] = 0;
    fn_8002F53C(temp_r6, NWC24Data_Init_801E1028, fn_801E07E8, 0x1C, 0x64);
    return arg0;
}

void NWC24Data_Init_801E1028(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
}

extern void lbl_8032CE98(void);
void fn_801E1038(void **arg0) {
    *arg0 = (void *)&lbl_8032CE98;
}

void fn_801E1250(s32 arg0, s8 arg1) {
    u8 *p = (u8 *)lbl_8055EA10;
    if (p == 0) return;
    if (arg0 == *(s32 *)(p + 0xC)) *(p + 0x10) = arg1;
    if (arg0 == *(s32 *)(p + 0x24)) *(p + 0x28) = arg1;
    p = (u8 *)((u32)p + 0x30);
    if (arg0 == *(s32 *)(p + 0xC)) *(p + 0x10) = arg1;
    if (arg0 == *(s32 *)(p + 0x24)) *(p + 0x28) = arg1;
}

s32 fn_801E137C(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_801E1510(s32 *arg0, s32 arg1) { return *arg0 + arg1 * 0x1C; }

void fn_801E1520(void) {
    void *obj = lbl_8055EA10;
    if (obj != 0) {
        if (obj != 0)
            ((void (*)(void *, s32))(*(void ***)obj)[7])(obj, 1);
        lbl_8055EA10 = 0;
    }
}

void fn_801E1684(void) {

}

void fn_801E1688(void) {

}

void fn_801E168C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x6C) = -1;
    *(s32 *)((u8 *)arg0 + 0x0C) = -1;
    *(u8 *)((u8 *)arg0 + 0x10) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    *(s32 *)((u8 *)arg0 + 0x20) = 0;
    *(f32 *)((u8 *)arg0 + 0x14) = lbl_80562C78;
    *(f32 *)((u8 *)arg0 + 0x18) = lbl_80562C7C;
    *(s32 *)((u8 *)arg0 + 0x70) = -1;
    *(s32 *)((u8 *)arg0 + 0x24) = -1;
    *(u8 *)((u8 *)arg0 + 0x28) = 0;
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x38) = 0;
    *(f32 *)((u8 *)arg0 + 0x2C) = lbl_80562C78;
    *(f32 *)((u8 *)arg0 + 0x30) = lbl_80562C7C;
    *(s32 *)((u8 *)arg0 + 0x74) = -1;
    *(s32 *)((u8 *)arg0 + 0x3C) = -1;
    *(u8 *)((u8 *)arg0 + 0x40) = 0;
    *(s32 *)((u8 *)arg0 + 0x4C) = 0;
    *(s32 *)((u8 *)arg0 + 0x50) = 0;
    *(f32 *)((u8 *)arg0 + 0x44) = lbl_80562C78;
    *(f32 *)((u8 *)arg0 + 0x48) = lbl_80562C7C;
    *(s32 *)((u8 *)arg0 + 0x78) = -1;
    *(s32 *)((u8 *)arg0 + 0x54) = -1;
    *(u8 *)((u8 *)arg0 + 0x58) = 0;
    *(s32 *)((u8 *)arg0 + 0x64) = 0;
    *(s32 *)((u8 *)arg0 + 0x68) = 0;
    *(f32 *)((u8 *)arg0 + 0x5C) = lbl_80562C78;
    *(f32 *)((u8 *)arg0 + 0x60) = lbl_80562C7C;
}

void fn_801E1868(void) {

}

