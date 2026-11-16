// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055E408;
extern int lbl_8055E410;
extern int lbl_80430850[7];
#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Initialize the global state node and reset the associated object fields. */
void fn_80179CBC(void) {
#define sStateNode lbl_8055E408
#define sStateMagic lbl_8055E410
#define sTrackedObject lbl_80430850
    register int zeroValue asm("r0");
    volatile char *objectBase;
    int flagValue;

    fn_8000D838(&sStateNode);
    zeroValue = 0xFFFF0000;
    *(volatile int *)&sStateMagic = zeroValue;

    objectBase = (volatile char *)sTrackedObject;
    zeroValue = 0;
    flagValue = 1;
    *(volatile int *)(objectBase + 0x10) = zeroValue;
    *(volatile char *)(objectBase + 0x14) = flagValue;
    *(volatile int *)(objectBase + 0x1C) = zeroValue;
    *(volatile int *)(objectBase + 0x18) = zeroValue;

#undef sTrackedObject
#undef sStateMagic
#undef sStateNode
}
#pragma pop

#include "types.h"
DECL_SECTION(".ctors") funcptr_t D_802ED204 = fn_80179CBC;
