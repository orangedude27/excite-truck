// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>
#pragma small_data off
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int lbl_8055FB58;
extern int lbl_804C109C[];
extern int lbl_804C1090[];
extern void fn_802C2698(void);
void fn_802C2640(void);

DECL_SECTION(".ctors") funcptr_t D_802ED58C = fn_802C2640;

#pragma small_data off
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_802C2640(void) {
    fn_8000D838(&lbl_8055FB58);
    lbl_804C109C[0] = (int)((char *)lbl_804C109C + 12);
    lbl_804C109C[2] = 0x20;
    lbl_804C109C[1] = 0;
    __register_global_object((void *)lbl_804C109C, (void *)fn_802C2698, (void *)&lbl_804C1090[0]);
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling reset
