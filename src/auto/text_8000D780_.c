// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_8000D838(void *);
extern s32 lbl_8034F610[];
extern s32 lbl_8055D3F0;
extern u32 lbl_8055D3F8;
extern u32 lbl_8055D3FC;

void fn_8000D780(void) {
    fn_8000D838(&lbl_8055D3F0);
    lbl_8034F610[0] = 0;
    lbl_8034F610[1] = 0x7B;
    lbl_8055D3F8 = 0xFFFF0000;
    lbl_8034F610[2] = 0;
    lbl_8034F610[3] = 0;
    lbl_8034F610[4] = 0;
    lbl_8055D3FC = 0x7F000000;
}
