// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_8000D838(void *);
extern s32 lbl_8034F610[];
extern s32 lbl_8055D3F0;
extern u32 lbl_8055D3F8;
extern u32 lbl_8055D3FC;

void fn_8000D780(void) {
    s32 *p = lbl_8034F610;
    fn_8000D838(&lbl_8055D3F0);
    *p = 0;
    p[1] = 0x7B;
    lbl_8055D3F8 = 0xFFFF0000;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    lbl_8055D3FC = 0x7F000000;
}
#pragma scheduling reset
