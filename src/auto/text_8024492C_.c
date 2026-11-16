// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern s32 lbl_80498860[];
extern s32 lbl_8055F218;
extern s32 lbl_8055F220;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* RealName: InitFooState (static constructor): initializes a 5-word global state block
 * and a companion status word, then registers the state with the subsystem initializer. */
void fn_8024492C(void) {
#define InitStateSubsys fn_8000D838
#define gStateSubsysHandle lbl_8055F218
#define gStateWords lbl_80498860
#define gStateStatus lbl_8055F220
    s32 defaultCount;
    s32 *stateAfterFirst;
    InitStateSubsys(&gStateSubsysHandle);
    stateAfterFirst = gStateWords + 1;
    gStateWords[0] = 0;
    defaultCount = 0x7B;
    gStateWords[1] = defaultCount;
    gStateWords[2] = 0;
    gStateWords[3] = 0;
    gStateWords[4] = 0;
    gStateStatus = 0x7F000000;
#undef InitStateSubsys
#undef gStateSubsysHandle
#undef gStateWords
#undef gStateStatus
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED420 = fn_8024492C;

