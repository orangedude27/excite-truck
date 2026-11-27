// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#pragma small_data off
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int lbl_8055F990;
extern int gEntryList[];
extern int lbl_804BE0F8[];
extern void fn_802B1CE0(void);
void fn_802B1C88(void);

#include <macros.h>

DECL_SECTION(".ctors") funcptr_t D_802ED550 = fn_802B1C88;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* Initializes this module's global object record and registers its static destructor. */
void fn_802B1C88(void) {
    fn_8000D838(&lbl_8055F990);
    gEntryList[0] = (int)((char *)gEntryList + 12);
    gEntryList[2] = 0x20;
    gEntryList[1] = 0;
    __register_global_object((void *)gEntryList, (void *)fn_802B1CE0, (void *)&lbl_804BE0F8[0]);
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling reset
