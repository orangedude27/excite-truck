// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

extern f64 fn_8002F234(f32, ...);
extern void *fn_801284E8(void *, s32);
extern char lbl_8032C108[];
extern f32 lbl_80562C78;
extern f32 lbl_80562C7C;

extern void *lbl_8055EA10;

extern void NWC24Data_Init_801E1028(void *);
extern void fn_801E07E8(void);
extern void fn_8002F53C(void *, void *, void *, s32, s32);
void fn_801E0864(void *arg0) {
    *(int *)arg0 = -1;
    *((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(float *)((char *)arg0 + 8) = lbl_80562C78;
    *(float *)((char *)arg0 + 0xC) = lbl_80562C7C;
}

int fn_801E0ED4(int arg0, int arg1) {
    return arg1 > arg0 ? arg1 : arg0;
}

float fn_801E0EE4(void *arg0, void *arg1) {
    float dx;
    float dy;
    dx = *(float *)((char *)arg0 + 4) - *(float *)((char *)arg1 + 4);
    dy = *(float *)arg0 - *(float *)arg1;
    return (float)fn_8002F234(dx * dx + dy * dy, dx, dy);
}

void fn_801E0F34(int arg0) {
    void *ptr;
    ptr = fn_801284E8(lbl_8032C108, arg0 * 8 + 8);
    *(int *)((char *)ptr + 4) = arg0;
    *(int *)ptr = arg0;
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

void fn_801E1868(void) {

}

