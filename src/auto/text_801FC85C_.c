// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void fn_8000D838(void *);
extern u32 lbl_8055EC28[2];
extern f32 lbl_80488898[3];
extern s32 lbl_8055EC30;
extern f32 lbl_8055EC34;
extern f32 lbl_80562FF0, lbl_80563024;

void fn_801FC85C(void) {
    fn_8000D838(&lbl_8055EC28);
    lbl_80488898[0] = lbl_80562FF0;
    lbl_80488898[1] = lbl_80562FF0;
    lbl_80488898[2] = lbl_80562FF0;
    lbl_8055EC30 = 0x7F000000;
    lbl_8055EC34 = lbl_80563024;
}
