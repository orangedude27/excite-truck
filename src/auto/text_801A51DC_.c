#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8000D838(void *);
extern s32 lbl_8055E590;
extern s32 lbl_8055E598;
extern s32 lbl_8055E59C;
void fn_801A51DC(void) {
    fn_8000D838(&lbl_8055E590);
    lbl_8055E598 = 0xFFFF0000;
    lbl_8055E59C = 0xFFFF0000;
}
