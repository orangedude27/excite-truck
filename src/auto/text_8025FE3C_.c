// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <macros.h>

extern void *lbl_8055F3C8;
extern s32 lbl_8055F3D0;
extern s32 lbl_80498EE8[];
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8025FE3C(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F3C8);
    p = lbl_80498EE8 + 1;
    lbl_80498EE8[0] = 0;
    v = 0x7B;
    lbl_80498EE8[1] = v;
    lbl_80498EE8[2] = 0;
    lbl_80498EE8[3] = 0;
    lbl_80498EE8[4] = 0;
    lbl_8055F3D0 = 0x7F000000;
}
