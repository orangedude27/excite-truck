// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055F660;
extern s32 lbl_8055F668;
extern s32 lbl_804B2FC0[];
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8027E8B8(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F660);
    p = lbl_804B2FC0 + 1;
    lbl_804B2FC0[0] = 0;
    v = 0x7B;
    lbl_804B2FC0[1] = v;
    lbl_804B2FC0[2] = 0;
    lbl_804B2FC0[3] = 0;
    lbl_804B2FC0[4] = 0;
    lbl_8055F668 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
