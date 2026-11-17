// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_8000D838(void *);
extern s32 lbl_8042F840[];
extern s32 lbl_8055E140;
extern u32 lbl_8055E148;
extern u32 lbl_8055E14C;

#pragma scheduling invalid_target
void fn_8013A20C(void) {
    s32 zero = 0;
    s32 *p = lbl_8042F840;
    fn_8000D838(&lbl_8055E140);
    p[0] = zero;
    p[1] = 0x7B;
    lbl_8055E148 = 0xFFFF0000;
    p[2] = zero;
    p[3] = zero;
    p[4] = zero;
    lbl_8055E14C = 0x7F000000;
}
