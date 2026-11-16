// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern int lbl_8055EFE0;
extern int lbl_80497E10[5];
extern void fn_8000D838(int *);
void fn_8022E998(void);

DECL_SECTION(".ctors") static funcptr_t D_802ED3C8 = fn_8022E998;
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Initialize this module's state and global init flag (constructor). */
void fn_8022E998(void) {
#define moduleInitFlag lbl_8055EFE0
#define moduleState    lbl_80497E10

    int initialValue;
    fn_8000D838(&moduleInitFlag);
    moduleState[0] = 0;
    initialValue = 123;
    moduleState[1] = initialValue;
    moduleState[2] = 0;
    moduleState[3] = 0;
    moduleState[4] = 0;

#undef moduleInitFlag
#undef moduleState
}
#pragma opt_propagation reset
#pragma scheduling on
