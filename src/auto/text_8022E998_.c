// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern int lbl_8055EFE0;
extern int lbl_80497E10[5];
extern void fn_8000D838(int *);
void fn_8022E998(void);

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00") funcptr_t D_802ED3C8 = fn_8022E998;
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_8022E998(void) {
    int v;
    fn_8000D838(&lbl_8055EFE0);
    lbl_80497E10[0] = 0;
    v = 123;
    lbl_80497E10[1] = v;
    lbl_80497E10[2] = 0;
    lbl_80497E10[3] = 0;
    lbl_80497E10[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
