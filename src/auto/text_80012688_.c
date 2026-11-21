// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern char lbl_8055D4E0[4];
extern u32 lbl_8055D4E8;
extern void fn_8000D838(void *record);

/* Static constructor (.ctors entry D_802ED094): register this module's static-destructor
 * record so its destructor runs at exit, then seed the following word with the
 * end-of-table sentinel. */
void fn_80012688(void) {
#define RegisterStaticDtor fn_8000D838
#define StaticDtorRecord   lbl_8055D4E0
#define EndOfTableSentinel lbl_8055D4E8
#define STATIC_DTOR_LIST_END 0x7f000000
    RegisterStaticDtor(&StaticDtorRecord);
    EndOfTableSentinel = STATIC_DTOR_LIST_END;
#undef STATIC_DTOR_LIST_END
#undef EndOfTableSentinel
#undef StaticDtorRecord
#undef RegisterStaticDtor
}
