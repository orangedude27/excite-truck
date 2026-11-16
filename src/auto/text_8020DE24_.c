// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055EE68;
extern int lbl_80489C70[5];
extern int lbl_8055EE70;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* RealName: Unknown_ctor_8020DE24
 * Initializes the global object at lbl_8055EE68 and sets up associated state:
 * clears/initializes lbl_80489C70[0..4] to {0, 0x7B, 0, 0, 0} and sets
 * lbl_8055EE70 to 0x7F000000. Registered as a static constructor. */
void fn_8020DE24(void) {
#define gStateArray lbl_80489C70
#define gStateValue lbl_8055EE70
    int v;
    int *p;
    fn_8000D838(&lbl_8055EE68);
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
#include <types.h>
DECL_SECTION(".ctors") funcptr_t D_802ED3A0 = fn_8020DE24;
