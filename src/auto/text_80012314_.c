#include <types.h>
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern s32 lbl_8055D478;
extern s32 lbl_8055D48C;
extern s32 lbl_8055D484;
extern s32 lbl_8055D480;
extern s32 lbl_8055D488;
extern s32 lbl_80351738[0x54];
extern void fn_80012384(void);
extern s32 lbl_8035172C[];
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
void fn_80012314(void) {
    fn_8000D838(&lbl_8055D478);
    lbl_8055D484 = 0x64FFFFFF;
    lbl_8055D48C = 0xFFA70000 - 0x4C4D;
    lbl_8055D480 = 0x7F000000;
    lbl_8055D488 = 0x64000000;
    lbl_80351738[0x14] = 0;
    __register_global_object(&lbl_80351738[0], &fn_80012384, &lbl_8035172C[0]);
}
#pragma scheduling on
