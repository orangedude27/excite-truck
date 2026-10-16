// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u8 lbl_80422180[0x200];
extern u8 lbl_804223A0[0x20];
void fn_80129690(void *arg0, s32 arg1, void *arg2);
s32 fn_802E8504(s32);

void *fn_801298E8(void *arg0, int arg1);
extern u8 lbl_804223C0[];
extern u8 lbl_8032A5B0[];
extern u8 lbl_8055DFD0;
extern void *fn_80129400;
void fn_802E7C64(void);
void fn_80127C90(void *, void *);
void fn_80129458(void);
void fn_802E830C(void *);
void fn_80127D58(void *);
void fn_802E7D0C(void);

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
    u8 *p = lbl_80422180;
    s32 i;
    for (i = 0; i < 4; i++) {
        fn_80129690(p, i, lbl_804223A0);
        p += 0x80;
    }
}

s32 fn_80129BC4(void) {
    return 1;
}

