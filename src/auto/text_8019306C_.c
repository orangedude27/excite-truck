#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8000D838(void *);
extern s32 lbl_8055E508;
extern s32 lbl_8055E510;
extern s32 lbl_8055E514;
void fn_8019306C(void) {
    fn_8000D838(&lbl_8055E508);
    lbl_8055E510 = 0xFFFF0000;
    lbl_8055E514 = 0xFFFF0000;
}
