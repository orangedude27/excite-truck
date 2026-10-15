// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055E270;
extern s32 lbl_8055E278;
void fn_8000D838(void *);
void fn_8015724C(void) {
    fn_8000D838(&lbl_8055E270);
    lbl_8055E278 = 0xFFFF0000;
}
