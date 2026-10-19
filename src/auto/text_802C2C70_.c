// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern unsigned char lbl_8055FB88;
extern short lbl_8055FB90;
extern short lbl_8055FB92;
extern short lbl_8055FB94;
void fn_8000D838(void*);
void fn_802C2C70(void);

DECL_SECTION(".ctors") static funcptr_t D_802ED598 = fn_802C2C70;

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802C2C70(void) {
    short v;
    fn_8000D838(&lbl_8055FB88);
    *(volatile short *)&lbl_8055FB90 = 0x100;
    *(volatile short *)&lbl_8055FB94 = 0x401;
    v = 0x405;
    lbl_8055FB92 = v;
}
#pragma opt_propagation reset
#pragma scheduling on
