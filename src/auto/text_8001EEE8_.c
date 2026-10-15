// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055D5E8;
extern s32 lbl_8055D5F0;
extern s32 lbl_80358668[6];
void fn_8000D838(void *);
void fn_8001EEE8(void) {
    fn_8000D838(&lbl_8055D5E8);
    ((s32*)&lbl_80358668)[0] = 0;
    ((s32*)&lbl_80358668)[1] = 0x7B;
    ((s32*)&lbl_80358668)[2] = 0;
    ((s32*)&lbl_80358668)[3] = 0;
    ((s32*)&lbl_80358668)[4] = 0;
    lbl_8055D5F0 = 0x7F000000;
}
