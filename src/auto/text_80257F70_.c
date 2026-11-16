// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern char lbl_8055F358[4];
extern int lbl_80498E50[5];
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Initialize this module's static state block and reset its runtime fields. */
void fn_80257F70(void) {
#define moduleInitState lbl_8055F358
#define moduleState     lbl_80498E50
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

DECL_SECTION(".ctors") funcptr_t D_802ED454 = fn_80257F70;

