#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *); /* free(): release an allocation back to the heap */
/* Reset the object's three 32-bit fields to 0, then free it when
 * shouldDelete > 0 (deleting-destructor style helper). */
void *fn_801677DC(void *object, s32 shouldDelete) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

/* Empty stub. */
void fn_80167834(void) {
}

/* No-op teardown hook of the betarace manager.  fn_8014E9C4 calls it, together
 * with fn_8016A68C, once the manager object is released; its counterpart on the
 * create side is fn_80167834 (called by fn_8014DE50).  This build has nothing
 * to undo here. */
void fn_80167838(void) {

}

/* Empty stub. */
void fn_8016783C(void) {
}

/* Empty stub. */
void fn_80167840(void) {
}

/* Empty stub. */
void fn_80167844(void) {

}

