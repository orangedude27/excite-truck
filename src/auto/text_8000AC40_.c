// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void*);
extern int lbl_8055D3A0;
extern s32 lbl_8034F4C8[];
extern int lbl_8055D3A8;
extern int lbl_8055D3AC;
void fn_8000D838(void*);
#pragma opt_propagation off
void fn_8000AC40(void) {
    s32 z, v;
    fn_8000D838(&lbl_8055D3A0);
    z = 0;
    ((volatile int *)lbl_8034F4C8)[0] = z;
    v = 0x7B;
    ((volatile int *)lbl_8034F4C8)[1] = v;
    *(volatile int *)&lbl_8055D3A8 = (int)0xFFFF0000;
    ((volatile int *)lbl_8034F4C8)[2] = z;
    ((volatile int *)lbl_8034F4C8)[3] = z;
    ((volatile int *)lbl_8034F4C8)[4] = z;
    *(volatile int *)&lbl_8055D3AC = (int)0x7F000000;
}
