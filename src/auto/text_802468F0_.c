// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern char lbl_8055F248[4];
extern int lbl_804988D8[5];
extern int fn_8000D838(void*);
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Initialize this module's state and global init flag (constructor). */
void fn_802468F0(void) {
#define moduleInitFlag lbl_8055F248
#define moduleState    lbl_804988D8

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

DECL_SECTION(".ctors") funcptr_t D_802ED42C = fn_802468F0;
