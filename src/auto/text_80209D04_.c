// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern char lbl_8055EDB0;
extern int lbl_804892A8[];
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80209D04(void) {
    int v;
    fn_8000D838(&lbl_8055EDB0);
    lbl_804892A8[0] = 0;
    v = 123;
    lbl_804892A8[1] = v;
    lbl_804892A8[2] = 0;
    lbl_804892A8[3] = 0;
    lbl_804892A8[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") static funcptr_t D_802ED384 = fn_80209D04;
