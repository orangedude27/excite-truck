// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 lbl_8055D4D0;
extern s32 lbl_8055D4C0;
extern s32 lbl_8055D4C4;
extern s32 lbl_8055D4C8;
extern s32 fn_8023512C(void);
extern void fn_80235380(void);
extern void fn_802328D4(void);
extern s32 fn_80232578(s32);
void fn_8000F330(s32 arg1, s32 arg2) {
    lbl_8055D4C0 = fn_8023512C();
    lbl_8055D4C4 = fn_80232578(arg1);
    lbl_8055D4C8 = fn_80232578(arg2);
}

void fn_8000F384(void) {
    if (lbl_8055D4C0 != 0) {
        fn_80235380();
        lbl_8055D4C0 = 0;
    }
    if (lbl_8055D4C4 != 0) {
        fn_802328D4();
        lbl_8055D4C4 = 0;
    }
    if (lbl_8055D4C8 != 0) {
        fn_802328D4();
        lbl_8055D4C8 = 0;
    }
}

void fn_8000F3E8(void) {
    lbl_8055D4D0 = fn_8023512C();
}

void fn_8000F40C(void) {
    if (lbl_8055D4D0 != 0) {
        fn_80235380();
        lbl_8055D4D0 = 0;
    }
}

extern s32 lbl_8055D4CC;
void fn_8000F440(void) {
    lbl_8055D4CC = fn_8023512C();
}

