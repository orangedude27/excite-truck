// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern int lbl_8055F0E0;
extern unsigned int lbl_804986C8[];
extern unsigned int lbl_8055F0E8;
extern int fn_8000D838(int *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8023990C(void) {
    int v;
    unsigned int *p;
    fn_8000D838(&lbl_8055F0E0);
    p = lbl_804986C8 + 1;
    lbl_804986C8[0] = 0;
    v = 0x7B;
    lbl_804986C8[1] = v;
    lbl_804986C8[2] = 0;
    lbl_804986C8[3] = 0;
    lbl_804986C8[4] = 0;
    lbl_8055F0E8 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED3EC = fn_8023990C;
