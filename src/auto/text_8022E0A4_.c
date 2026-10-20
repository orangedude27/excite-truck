// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

void fn_8022E0A4(void);
DECL_SECTION(".ctors") funcptr_t D_802ED3C4 = fn_8022E0A4;
extern char lbl_8055EFD8[4];
extern int lbl_80497DF8[5];
extern int fn_8000D838(void*);
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_8022E0A4(void) {
    int v;
    fn_8000D838(&lbl_8055EFD8);
    lbl_80497DF8[0] = 0;
    v = 123;
    lbl_80497DF8[1] = v;
    lbl_80497DF8[2] = 0;
    lbl_80497DF8[3] = 0;
    lbl_80497DF8[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
