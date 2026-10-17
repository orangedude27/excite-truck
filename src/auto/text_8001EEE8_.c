// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055D5E8;
extern s32 lbl_8055D5F0;
extern s32 lbl_80358668;
void fn_8000D838(void *);
void fn_8001EEE8(void) {
    s32 *p;
    s32 v;
    fn_8000D838(&lbl_8055D5E8);
    v = 0;
    lbl_80358668 = v;
    p = &lbl_80358668;
    p[1] = 0x7B;
    p[2] = v;
    p[3] = v;
    p[4] = v;
    lbl_8055D5F0 = 0x7F000000;
}
