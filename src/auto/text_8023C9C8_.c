// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 lbl_8055F138;
extern s32 lbl_80498788[];
extern s32 lbl_8055F140;
extern void fn_8000D838(void *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8023C9C8(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F138);
    p = lbl_80498788 + 1;
    lbl_80498788[0] = 0;
    v = 0x7B;
    lbl_80498788[1] = v;
    lbl_80498788[2] = 0;
    lbl_80498788[3] = 0;
    lbl_80498788[4] = 0;
    lbl_8055F140 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
