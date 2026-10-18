#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_8000D838(void *);
struct S8013 { char pad[0x240]; s32 value; };
extern struct S8013 lbl_8042F8C8;
extern s32 lbl_8055E178;
void fn_8013C714(void) {
    fn_8000D838(&lbl_8055E178);
    *(s32 *)((char *)&lbl_8042F8C8 + 0x240) = 0;
}
