// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F0A8;
extern int lbl_80498650[5];
extern void fn_8000D838(int *);
#include <types.h>

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80238714(void) {
    int v;
    fn_8000D838(&lbl_8055F0A8);
    lbl_80498650[0] = 0;
    v = 123;
    lbl_80498650[1] = v;
    lbl_80498650[2] = 0;
    lbl_80498650[3] = 0;
    lbl_80498650[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
