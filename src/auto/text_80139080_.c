#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8000D838(void *);
extern s32 lbl_8055E108;
extern s32 lbl_8055E110;
extern s32 lbl_8055E114;
void fn_80139080(void) {
    /* Static constructor: register a destructor node for lbl_8055E108, then
     * initialize the record's two 0xFFFF0000 fields. */
    fn_8000D838(&lbl_8055E108);
    lbl_8055E110 = 0xFFFF0000;
    lbl_8055E114 = 0xFFFF0000;
}
DECL_SECTION(".ctors") funcptr_t D_802ED190 = fn_80139080;
