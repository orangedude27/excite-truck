// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_8000D838(void *);
extern char lbl_8055E7D0;
extern s32 lbl_8055E7D8;
extern s32 lbl_8055E7DC;

void fn_801CB2A4(void) {
    fn_8000D838(&lbl_8055E7D0);
    lbl_8055E7DC = 0x7F000000;
    lbl_8055E7D8 = 0xFFFF0000;
}
