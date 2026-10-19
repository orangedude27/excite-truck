// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern int lbl_8055F088;
extern unsigned int lbl_80498638[];
extern unsigned int lbl_8055F090;
extern int fn_8000D838(int *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_802366D8(void) {
    int v;
    unsigned int *p;
    fn_8000D838(&lbl_8055F088);
    p = lbl_80498638 + 1;
    lbl_80498638[0] = 0;
    v = 0x7B;
    lbl_80498638[1] = v;
    lbl_80498638[2] = 0;
    lbl_80498638[3] = 0;
    lbl_80498638[4] = 0;
    lbl_8055F090 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED3E0 = fn_802366D8;
