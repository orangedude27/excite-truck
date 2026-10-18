#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_8000D838(void *);
extern s32 lbl_80358628;
extern s32 lbl_8055D5C0;
#pragma small_data off
__declspec(section ".data") extern s32 lbl_80358628;
void fn_8001D7A8(void) {
    fn_8000D838(&lbl_8055D5C0);
    lbl_80358628 = 0;
}
