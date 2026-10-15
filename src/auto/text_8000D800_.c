// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern char lbl_8055D438[4];
extern int fn_8000D838(void*);
extern u32 lbl_8055D440;
void fn_8000D800(void);

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00") funcptr_t D_802ED084 = fn_8000D800;

#pragma section ".ctors$00"
void fn_8000D800(void)
{
    fn_8000D838(&lbl_8055D438);
    lbl_8055D440 = 0x7f000000;
}
