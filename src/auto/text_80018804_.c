// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

/* Record fn_8000D838 chains onto the global static-destructor list. */
typedef struct {
    unsigned char tag;  /* 0x31, written by fn_8000D838 */
    void *next;         /* 0x4 previous head of the list (lbl_8055D450) */
} StaticDtorRecord;

extern StaticDtorRecord lbl_8055D558; /* this module's record, in .sbss */
void fn_8000D838(void *);
void fn_80018804(void);

DECL_SECTION(".ctors") funcptr_t D_802ED0A8 = fn_80018804;

/* Static constructor (its .ctors entry is D_802ED0A8): chain this module's
   static-destructor record onto the global list headed by lbl_8055D450, so the
   object it stands for is torn down when the game exits.  Registering it is all
   this module has to do at startup, so the call is a tail call. */
void fn_80018804(void) {
    fn_8000D838(&lbl_8055D558);
}

