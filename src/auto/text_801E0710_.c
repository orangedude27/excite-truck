// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

extern void *lbl_8055EA10;

extern void NWC24Data_Init_801E1028(void *);
extern void fn_801E07E8(void);
extern void fn_8002F53C(void *, void *, void *, s32, s32);
void fn_801E0F78(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    arg0[0] = arg1[0] + arg2[0] * arg3;
    arg0[1] = arg1[1] + arg2[1] * arg3;
}

f32 fn_801E0FA4(f32 *arg0, f32 *arg1) {
    return arg0[1] * arg1[1] + arg0[0] * arg1[0];
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

