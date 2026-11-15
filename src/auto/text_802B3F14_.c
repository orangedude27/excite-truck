// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
/* Fixed-capacity list of pointers: `items` points at the `entries` storage that
 * follows the header, `count` is how many are in use and `capacity` how many fit
 * (fn_802B2384 appends, fn_802B2C98 looks an entry up by the name at +0x24). */
typedef struct PtrTable {
    /* 0x0 */ void **items;
    /* 0x4 */ int count;
    /* 0x8 */ int capacity;
    /* 0xC */ void *entries[16];
} PtrTable;

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_802B3F6C(void);
#pragma push
#pragma small_data off
/* 12-byte link node __register_global_object chains this object's destructor with. */
extern int lbl_804BE1F0[];
#pragma pop
/* Global list of the "umat-DLO-SetPlacer" objects fn_802B224C creates. */
extern PtrTable lbl_804BE1FC;
/* This module's static-record (tag byte at +0, next pointer at +4) that
 * fn_8000D838 pushes onto the list headed by lbl_8055D450. */
extern unsigned char lbl_8055F9A8;

# pragma scheduling invalid_target
# pragma opt_propagation off
# pragma opt_dead_assignments off
/* Constructor of the global SetPlacer list: point its item array at the inline
 * storage, set capacity 16 and count 0, register this module's static record and
 * chain the list's destructor onto the runtime's global-object list. */
void fn_802B3F14(void) {
    fn_8000D838(&lbl_8055F9A8);
    lbl_804BE1FC.items = &lbl_804BE1FC.entries[0];
    lbl_804BE1FC.capacity = 16;
    lbl_804BE1FC.count = 0;
    __register_global_object((void *)&lbl_804BE1FC, (void *)fn_802B3F6C, (void *)&lbl_804BE1F0[0]);
}
# pragma opt_dead_assignments reset
# pragma opt_propagation reset
# pragma scheduling reset

#include <types.h>
DECL_SECTION(".ctors") funcptr_t D_802ED554 = fn_802B3F14;
