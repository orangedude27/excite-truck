// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_802BE30C(void);
#pragma push
#pragma small_data off
extern int lbl_804C00C8[];
#pragma pop
extern int lbl_804C00D4[];
extern unsigned char lbl_8055FAA0;
# pragma scheduling invalid_target
# pragma opt_propagation off
# pragma opt_dead_assignments off
void fn_802BE2B4(void) {
    fn_8000D838(&lbl_8055FAA0);
    lbl_804C00D4[0] = (int)((char *)lbl_804C00D4 + 12);
    lbl_804C00D4[2] = 0x10;
    lbl_804C00D4[1] = 0;
    __register_global_object((void *)lbl_804C00D4, (void *)fn_802BE30C, (void *)&lbl_804C00C8[0]);
}
# pragma opt_dead_assignments reset
# pragma opt_propagation reset
# pragma scheduling reset

#include <types.h>
DECL_SECTION(".ctors") funcptr_t D_802ED574 = fn_802BE2B4;
