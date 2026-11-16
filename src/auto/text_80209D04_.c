// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern char lbl_8055EDB0;
extern int lbl_804892A8[];
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Initializes the module state block (lbl_804892A8) and registers its init
 * guard with fn_8000D838. */
void fn_80209D04(void) {
#define moduleInitState lbl_8055EDB0
#define moduleState     lbl_804892A8
    int initialValue;
    fn_8000D838(&moduleInitState);
    moduleState[0] = 0;
    initialValue = 123;
    moduleState[1] = initialValue;
    moduleState[2] = 0;
    moduleState[3] = 0;
    moduleState[4] = 0;
#undef moduleInitState
#undef moduleState
}
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED384 = fn_80209D04;
