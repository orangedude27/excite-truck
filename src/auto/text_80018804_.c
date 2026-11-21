// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

#include <static_dtor.h>

extern StaticDtorRecord lbl_8055D558; /* this module's record, in .sbss */
void fn_8000D838(void *record);
void fn_80018804(void);

DECL_SECTION(".ctors") funcptr_t D_802ED0A8 = fn_80018804;

/* Static constructor (its .ctors entry is D_802ED0A8): chain this module's
   static-destructor record onto the global list headed by lbl_8055D450, so the
   object it stands for is torn down when the game exits.  Registering it is all
   this module has to do at startup, so the call is a tail call. */
void fn_80018804(void) {
#define RegisterStaticDtor fn_8000D838
#define sModuleDtorRecord  lbl_8055D558
    /* Static constructor: chain this module's static-destructor record onto the
       global list so this module's objects are torn down when the game exits. */
    RegisterStaticDtor(&sModuleDtorRecord);
#undef sModuleDtorRecord
#undef RegisterStaticDtor
}

