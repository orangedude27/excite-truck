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
/* Static initializer: registers a static-destructor record, then sets its associated word. */
void fn_8000D800(void)
{
#define s_initRecord lbl_8055D438
#define s_value lbl_8055D440
    fn_8000D838(&s_initRecord);
    s_value = 0x7f000000;
#undef s_value
#undef s_initRecord
}
