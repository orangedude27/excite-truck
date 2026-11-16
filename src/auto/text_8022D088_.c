// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern void *lbl_8055EFC0;
extern s32 lbl_8055EFC8;
extern s32 lbl_80490950[];

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* RealName: Unknown_ctor_8022D088
 * Initializes the global object at lbl_8055EFC0 and sets up associated state:
 * clears/initializes lbl_80490950[0..4] to {0, 0x7B, 0, 0, 0} and sets
 * lbl_8055EFC8 to 0x7F000000. Registered as a static constructor. */
void fn_8022D088(void) {
#define gStateArray lbl_80490950
#define gStateValue lbl_8055EFC8
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055EFC0);
    p = gStateArray + 1;
    gStateArray[0] = 0;
    v = 0x7B;
    gStateArray[1] = v;
    gStateArray[2] = 0;
    gStateArray[3] = 0;
    gStateArray[4] = 0;
    gStateValue = 0x7F000000;
#undef gStateArray
#undef gStateValue
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED3BC = fn_8022D088;
