// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055D5E8;
extern s32 lbl_8055D5F0;
extern s32 lbl_80358668[];
void fn_8000D838(void *);

static void Init5(s32 *p) {
    p[0] = 0;
    p[1] = 0x7B;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}

static void Init5z(s32 z, s32 *p) {
    p[0] = z;
    p[1] = 0x7B;
    p[2] = z;
    p[3] = z;
    p[4] = z;
}

#pragma scheduling off
void fn_8001EEE8(void) {
    fn_8000D838(&lbl_8055D5E8);
    Init5(lbl_80358668);
    lbl_8055D5F0 = 0x7F000000;
}
#pragma scheduling on
