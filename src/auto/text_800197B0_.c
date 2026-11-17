// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern s32 lbl_803582B0[];
void fn_802E6BD8(s32, s32, void*, s32, void*);
void *fn_80128668(void *);
/* Resets three 32-bit fields of an object to zero and, when shouldFree is positive, frees it via fn_80128668. */
void *fn_800197B0(void *object, s32 shouldFree) {
    void *local = object;
    if (object != (void*)0) {
        if ((object != (void*)0) && (object != (void*)0)) {
            *(s32*)object = 0;
            *(s32*)((s8*)object + 4) = 0;
            *(s32*)((s8*)object + 8) = 0;
        }
        if (shouldFree > 0) {
            fn_80128668(local);
        }
    }
    return local;
}

/* Resets the three 32-bit fields of a container to zero and, when shouldFree
 * is positive, frees the container itself. */
void *fn_8001980C(void *object, s32 shouldFree) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldFree > 0)
            fn_80128668(object);
    }
    return object;
}

#pragma scheduling on
typedef s32 (*InitFn)(s32, s32, void *, s32, s32);
#pragma scheduling invalid_target
#pragma scheduling on
void fn_80019864(void) {
    /* Register a 12-byte memcard record (cookie "Rep0" = 0x52657030, type 0)
     * backed by the zero-initialized buffer lbl_803582B0, with no callback. */
    fn_802E6BD8(0x52657030, 0, (void *)lbl_803582B0, 0xC, 0);
}
#pragma scheduling reset
void fn_80019884(void) {
    return;
}

s32 fn_80019888(void) {
    /* Return the player's Game Reputation Rating (0 = none earned yet). */
    return 0;
}

