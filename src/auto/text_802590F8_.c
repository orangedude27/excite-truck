// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055F378;
extern s32 lbl_8055F380;
extern s32 lbl_80498E80[];
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* RealName: __sinit_ (C++ static initializer for one of this file's global objects) */
void fn_802590F8(void) {
    /* Static init: hang this file's init node on the runtime's global-destructor chain
       (fn_8000D838 pushes it, marking it 0x31 and linking it at lbl_8055D450), then
       clear the object's state block, leaving its fragment number 0x7B, and arm the
       node's own state word. */
#define initNode   lbl_8055F378
#define stateWord  lbl_8055F380
#define stateBlock lbl_80498E80
    s32 v;
    s32 *p;
    fn_8000D838(&initNode);
    p = stateBlock + 1;
    stateBlock[0] = 0;
    v = 0x7B;
    stateBlock[1] = v;
    stateBlock[2] = 0;
    stateBlock[3] = 0;
    stateBlock[4] = 0;
    stateWord = 0x7F000000;
#undef initNode
#undef stateWord
#undef stateBlock
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
