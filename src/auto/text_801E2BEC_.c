#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8000D838(void *);
extern s32 lbl_8055EA28;
extern s32 lbl_8055EA30;
extern s32 lbl_8055EA34;
void fn_801E2BEC(void) {
    fn_8000D838(&lbl_8055EA28);
    lbl_8055EA30 = 0xFFFF0000;
    lbl_8055EA34 = 0xFFFF0000;
}
