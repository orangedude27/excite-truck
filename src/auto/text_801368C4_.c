#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern s32 lbl_8055E0B8;
extern s32 lbl_8055E0C0;
extern s32 lbl_8055E0C4;
#pragma scheduling reset
void fn_801368C4(void) {
    s32 *p = &lbl_8055E0C4;
    fn_8000D838(&lbl_8055E0B8);
    p[0] = 0x7F000000;
    p[-1] = 0xFFFF0000;
}
