#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055D1C0;
extern u16 lbl_8055FF50;
void fn_802E4A2C(void);
void fn_802E46E4(void) {
    lbl_8055D1C0 = (void*)-1;
}

void* memset(void*, int, unsigned long);
extern u16 lbl_8055FF50;
void fn_802E4A2C(void); /* extern */
s32 fn_802E47B8(void) {
    fn_802E4A2C();
    return lbl_8055FF50 != 0;
}

void fn_802E47E8(void) {
    memset(&lbl_8055FF50, 0, 8);
}

s32 fn_802E47F8(void) {
    return 0;
}

