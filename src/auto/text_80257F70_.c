// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern char lbl_8055F358[4];
extern int lbl_80498E50[5];
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80257F70(void) {
    int v;
    fn_8000D838(&lbl_8055F358);
    lbl_80498E50[0] = 0;
    v = 123;
    lbl_80498E50[1] = v;
    lbl_80498E50[2] = 0;
    lbl_80498E50[3] = 0;
    lbl_80498E50[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED454 = fn_80257F70;

