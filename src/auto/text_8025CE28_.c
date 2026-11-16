// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <macros.h>

extern void fn_8000D838(void *);
extern int lbl_8055F3A8;
extern int lbl_80498EB8[];
extern int lbl_8055F3B0;

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* RealName: InitFooState (static constructor): initializes a 5-word global state block
 * and a companion status word, then registers the state with the subsystem initializer. */
void fn_8025CE28(void) {
#define InitStateSubsys fn_8000D838
#define gStateSubsysHandle lbl_8055F3A8
#define gStateWords lbl_80498EB8
#define gStateStatus lbl_8055F3B0
    int v;
    int *p;
    InitStateSubsys(&gStateSubsysHandle);
    p = gStateWords + 1;
    gStateWords[0] = 0;
    v = 0x7B;
    gStateWords[1] = v;
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

DECL_SECTION(".ctors") funcptr_t D_802ED464 = fn_8025CE28;
