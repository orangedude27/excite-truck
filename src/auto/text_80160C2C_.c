#include "types.h"
#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E2C0;
extern int lbl_8055E2C8;
extern int lbl_8042FD78[];
extern int lbl_8042FD84[];
extern void fn_80160C8C(void);
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *, int);

#define registerStaticDestructor fn_8000D838
#define gStaticDtorRecord lbl_8055E2C0
#define gObjectCapacitySentinel lbl_8055E2C8
#define gGlobalObject lbl_8042FD84
#define gObjectRegistry lbl_8042FD78
#define destroyGlobalObject fn_80160C8C

#pragma scheduling invalid_target
void fn_80160C2C(void) {
    /* Global constructor: register a static-destructor record, set a capacity sentinel,
     * initialize a small inline-storage object (data -> +12, count = 0, capacity = 0x14),
     * and register its destructor destroyGlobalObject via __register_global_object. */
    registerStaticDestructor(&gStaticDtorRecord);
    gObjectCapacitySentinel = 0xFFFF0000;
    *(void **)&gGlobalObject = (char *)&gGlobalObject + 12;
    *(int *)((char *)&gGlobalObject + 8) = 0x14;
    *(int *)((char *)&gGlobalObject + 4) = 0;
    ((void (*)(void *, void *, void *))__register_global_object)(&gGlobalObject, &destroyGlobalObject, &gObjectRegistry);
}

