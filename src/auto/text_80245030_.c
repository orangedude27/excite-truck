// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern s32 lbl_80498878[];
extern s32 lbl_8055F228;
extern s32 lbl_8055F230;
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* RealName: Unknown_ctor_80245030
 * Initializes the global object at lbl_8055F228 and sets up associated state:
 * clears/initializes lbl_80498878[0..4] to {0, 0x7B, 0, 0, 0} and sets
 * lbl_8055F230 to 0x7F000000. */
void fn_80245030(void) {
#define gStateArray lbl_80498878
#define gStateValue lbl_8055F230
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F228);
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
