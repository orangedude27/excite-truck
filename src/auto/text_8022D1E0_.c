// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern char lbl_8055EFD0;
extern int lbl_80497DE0[];
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_8022D1E0(void) {
    int v;
    fn_8000D838(&lbl_8055EFD0);
    lbl_80497DE0[0] = 0;
    v = 123;
    lbl_80497DE0[1] = v;
    lbl_80497DE0[2] = 0;
    lbl_80497DE0[3] = 0;
    lbl_80497DE0[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
