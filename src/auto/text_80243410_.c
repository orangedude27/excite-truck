// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern s32 lbl_80498810[];
extern s32 lbl_8055F1E8;
extern s32 lbl_8055F1F0;
void fn_80243410(void) {
    s32 *p;
    fn_8000D838(&lbl_8055F1E8);
    p = lbl_80498810;
    *p = 0;
    p[1] = 0x7B;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    lbl_8055F1F0 = 0x7F000000;
}
