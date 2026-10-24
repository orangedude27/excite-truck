// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055F5D0;
extern s32 lbl_8055F5E0;
extern volatile s16 lbl_8055F5D8;
extern volatile s16 lbl_8055F5DA;
extern volatile s16 lbl_8055F5DC;
extern s32 lbl_804A16D0[];
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_802789B4(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F5D0);
    p = lbl_804A16D0 + 1;
    lbl_804A16D0[0] = 0;
    v = 0x7B;
    lbl_804A16D0[1] = v;
    lbl_804A16D0[2] = 0;
    lbl_804A16D0[3] = 0;
    lbl_804A16D0[4] = 0;
    lbl_8055F5E0 = 0x7F000000;
    lbl_8055F5D8 = 0x100;
    lbl_8055F5DA = 0x405;
    lbl_8055F5DC = 0x401;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
