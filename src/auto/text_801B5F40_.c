#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055E708;
extern s32 lbl_8055E70C;
extern s32 lbl_8055E714;
extern void fn_80128668(s32);
extern void fn_80128670(s32);
extern f32 lbl_805626B0;
extern f32 lbl_805626B4;
extern void *lbl_8055E710;
void __AXPushCallbackStack(void *arg0) {
    *((void **)arg0 + 1) = lbl_8055E710;
    lbl_8055E710 = arg0;
}

void fn_801B608C(s32 *arg0) {
    *arg0 = 0;
}

void NWC24Data_Init_801B6098(s32 *arg0) { arg0[0] = 0; arg0[1] = 0; }

void fn_801B60A8(void) {
    fn_80128668(lbl_8055E714);
    if (lbl_8055E708 != 0) fn_80128670(lbl_8055E708 - 0x10);
    if (lbl_8055E70C != 0) fn_80128670(lbl_8055E70C - 0x10);
}

s32 fn_801B60F4(f32 *arg0, f32 arg1) {
    f32 step = lbl_805626B0;
    s32 x;
    s32 y;
    if (!(arg1 <= step)) return lbl_8055E714;
    x = (s32)((arg0[0] + lbl_805626B4) / step);
    if (x < 0) x = 0;
    else if (x >= 100) x = 99;
    y = (s32)((arg0[2] + lbl_805626B4) / step);
    if (y < 0) y = 0;
    else if (y >= 100) y = 99;
    return (s32)((u32)lbl_8055E70C + ((y * 100 + x) * 4));
}

extern void *fn_801B5F40(void);
extern void __AXPushCallbackStack(void *);
extern void fn_802E317C(const char *);
extern void *lbl_80335EE0;
extern void *lbl_80335F20;
void fn_801B63E0(void **head, s32 value) {
    void *node = fn_801B5F40();
    *(s32 *)node = value;
    *(void **)((u8 *)node + 4) = *head;
    *head = node;
}

