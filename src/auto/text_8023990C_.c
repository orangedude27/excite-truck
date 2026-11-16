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
// Initializes the global state block and resets its associated counter array.
void fn_8023990C(void) {
    int count;
    unsigned int *nextEntry;
    fn_8000D838(&lbl_8055F0E0);
    nextEntry = lbl_804986C8 + 1;
    lbl_804986C8[0] = 0;
    count = 0x7B;
    lbl_804986C8[1] = count;
    lbl_804986C8[2] = 0;
    lbl_804986C8[3] = 0;
    lbl_804986C8[4] = 0;
    lbl_8055F0E8 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED3EC = fn_8023990C;
