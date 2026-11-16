// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void *lbl_8055ED30;
extern int lbl_80488BB8[];
extern int lbl_8055ED38;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* Static initializer: set up this module's state object, clear its 5-word control block, and store the default value (0x7F000000). */
void fn_80204A54(void) {
#define stateObject lbl_8055ED30
#define controlBlock lbl_80488BB8
#define defaultValue lbl_8055ED38
    int v;
    int *p;
    fn_8000D838(&stateObject);
    p = controlBlock + 1;
    controlBlock[0] = 0;
    v = 0x7B;
    controlBlock[1] = v;
    controlBlock[2] = 0;
    controlBlock[3] = 0;
    controlBlock[4] = 0;
    defaultValue = 0x7F000000;
#undef stateObject
#undef controlBlock
#undef defaultValue
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
#include <types.h>
DECL_SECTION(".ctors") funcptr_t D_802ED36C = fn_80204A54;
