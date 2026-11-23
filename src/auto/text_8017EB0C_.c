// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern int lbl_8055E498;
extern s32 lbl_804348C0[];
extern int lbl_8055E4A0;
extern int lbl_8055E4A4;
extern int lbl_8055E4A8;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8017EB0C(void) {
    s32 v;
    fn_8000D838(&lbl_8055E498);
    *(volatile s32 *)&lbl_804348C0[0] = 0;
    *(volatile s32 *)&lbl_804348C0[2] = 0;
    v = 0x7B;
    *(volatile s32 *)&lbl_804348C0[1] = v;
    *(volatile s32 *)&lbl_804348C0[3] = 0;
    *(volatile s32 *)&lbl_804348C0[4] = 0;
    *(volatile s32 *)&lbl_8055E4A0 = 0xFFFF0000;
    *(volatile s32 *)&lbl_8055E4A4 = 0xFFFF0000;
    *(volatile s32 *)&lbl_8055E4A8 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
