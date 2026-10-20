// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055F378;
extern s32 lbl_8055F380;
extern s32 lbl_80498E80[];
void fn_8000D838(void *);

void fn_802590F8(void);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_802590F8(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F378);
    p = lbl_80498E80 + 1;
    lbl_80498E80[0] = 0;
    v = 0x7B;
    lbl_80498E80[1] = v;
    lbl_80498E80[2] = 0;
    lbl_80498E80[3] = 0;
    lbl_80498E80[4] = 0;
    lbl_8055F380 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
