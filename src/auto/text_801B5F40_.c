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

