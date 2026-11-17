// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void fn_8000D838(void *);
extern u32 lbl_8055EBA8[2];
extern s32 lbl_8055EBB0, lbl_8055EBB8, lbl_8055EBC0;
extern f32 lbl_8055EBB4, lbl_8055EBBC;
extern const f32 lbl_80562ED8, lbl_80562EDC;

#pragma scheduling invalid_target
void fn_801EEF7C(void) {
    fn_8000D838(&lbl_8055EBA8);
    *(volatile s32 *)&lbl_8055EBC0 = -0x100;
    *(volatile s32 *)&lbl_8055EBB0 = 0xFFFF0000;
    *(volatile f32 *)&lbl_8055EBB4 = lbl_80562EDC;
    *(volatile s32 *)&lbl_8055EBB8 = 0x7F000000;
    *(volatile f32 *)&lbl_8055EBBC = lbl_80562ED8;
}
#pragma scheduling on
