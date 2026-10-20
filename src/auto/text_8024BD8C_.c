// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055F280;
extern s32 lbl_8055F288;
extern s32 lbl_80498998[];
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8024BD8C(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F280);
    p = lbl_80498998 + 1;
    lbl_80498998[0] = 0;
    v = 0x7B;
    lbl_80498998[1] = v;
    lbl_80498998[2] = 0;
    lbl_80498998[3] = 0;
    lbl_80498998[4] = 0;
    lbl_8055F288 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED434 = fn_8024BD8C;
