// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u8 lbl_80422180[0x200];
extern u8 lbl_804223A0[0x20];
void fn_80129690(void *arg0, s32 arg1, void *arg2);
s32 fn_802E8504(s32);

void *fn_801298E8(void *arg0, int arg1);

s32 fn_80129890(void) {
    s32 count = 0;
    s32 i = 0;
    do {
        if (fn_802E8504(i) != 0) {
            count++;
        }
        i++;
    } while (i < 4);
    return count;
}

void *fn_80129AE8(void *arg0, int arg1) {
    return fn_801298E8(arg0, arg1);
}

extern void *lbl_8055DFD4;
void* fn_80129AF4(void) {
    return lbl_8055DFD4;
}
void fn_80129AEC(void *arg0) {
    lbl_8055DFD4 = arg0;
}

void fn_80129AFC(void) {
    u8 *p = (u8 *)&lbl_80422180;
    s32 i = 0;
    do {
        fn_80129690(p, i, (u8 *)&lbl_804223A0);
        i++;
        p += 0x80;
    } while (i < 4);
}

s32 fn_80129BC4(void) {
    return 1;
}

