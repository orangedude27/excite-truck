// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern s32 lbl_80498810[];
extern s32 lbl_8055F1E8;
extern s32 lbl_8055F1F0;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80243410(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F1E8);
    p = lbl_80498810 + 1;
    lbl_80498810[0] = 0;
    v = 0x7B;
    lbl_80498810[1] = v;
    lbl_80498810[2] = 0;
    lbl_80498810[3] = 0;
    lbl_80498810[4] = 0;
    lbl_8055F1F0 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED418 = fn_80243410;
