// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>
#pragma small_data off
extern void fn_8000D838(void *);
extern int lbl_8055FEC8;
extern int lbl_804DB6A0[37];
void fn_802DEA90(void);
DECL_SECTION(".ctors") funcptr_t D_802ED5E0 = fn_802DEA90;
#pragma scheduling invalid_target
void fn_802DEA90(void) {
#define registerStaticDtor fn_8000D838
#define gTexCopyCacheDtorNode lbl_8055FEC8
#define gTexCopyCache lbl_804DB6A0
    /* Static initializer for the texture-copy cache: register its destructor node, then clear the active entry count. */
    registerStaticDtor(&gTexCopyCacheDtorNode);
    gTexCopyCache[36] = 0;
#undef gTexCopyCache
#undef gTexCopyCacheDtorNode
#undef registerStaticDtor
}
#pragma scheduling on
