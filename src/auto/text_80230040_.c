// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055F008;
extern s32 lbl_8055F010;
extern s32 lbl_80497E28[];
void fn_8000D838(void *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80230040(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F008);
    p = lbl_80497E28 + 1;
    lbl_80497E28[0] = 0;
    v = 0x7B;
    lbl_80497E28[1] = v;
    lbl_80497E28[2] = 0;
    lbl_80497E28[3] = 0;
    lbl_80497E28[4] = 0;
    lbl_8055F010 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED3D0 = fn_80230040;
