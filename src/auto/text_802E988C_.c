// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>
#pragma small_data off
extern void fn_8000D838(void*);
extern int lbl_80507288[3];
extern int lbl_80560018;
void fn_802E988C(void);
DECL_SECTION(".ctors") funcptr_t D_802ED61C = fn_802E988C;
#pragma scheduling invalid_target
/* Static constructor for the rmemcard (NAND save) module: register the module's
 * static object for destruction, then reset its async state machine (state 0,
 * first async step 1). */
void fn_802E988C(void) {
#define registerStaticDtor fn_8000D838
#define gRmemcardStatic lbl_80560018
#define gRmemcardAsyncState lbl_80507288
    registerStaticDtor(&gRmemcardStatic);
    gRmemcardAsyncState[0] = 0;
    gRmemcardAsyncState[1] = 1;
#undef gRmemcardAsyncState
#undef gRmemcardStatic
#undef registerStaticDtor
}
#pragma scheduling on
