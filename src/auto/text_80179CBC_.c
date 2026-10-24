// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055E408;
extern int lbl_8055E410;
extern int lbl_80430850[7];
#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80179CBC(void) {
    register int zero asm("r0");
    volatile char *p;
    int one;
    fn_8000D838(&lbl_8055E408);
    zero = 0xFFFF0000;
    *(volatile int *)&lbl_8055E410 = zero;
    p = (volatile char *)lbl_80430850;
    zero = 0;
    one = 1;
    *(volatile int *)(p + 0x10) = zero;
    *(volatile char *)(p + 0x14) = one;
    *(volatile int *)(p + 0x1C) = zero;
    *(volatile int *)(p + 0x18) = zero;
}
#pragma pop

#include "types.h"
DECL_SECTION(".ctors") funcptr_t D_802ED204 = fn_80179CBC;
