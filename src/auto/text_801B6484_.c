#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8000D838(void *);
extern s32 lbl_8055E6F8;
extern s32 lbl_8055E700;
extern s32 lbl_8055E704;
void fn_801B6484(void) {
    /* Register a static-destructor record at lbl_8055E6F8, then initialize the
     * two words following it (offsets +8 and +0xC) to 0xFFFF0000. */
    fn_8000D838(&lbl_8055E6F8);
    lbl_8055E700 = 0xFFFF0000;
    lbl_8055E704 = 0xFFFF0000;
}
