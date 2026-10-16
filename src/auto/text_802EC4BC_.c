// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern char lbl_805600E8;
extern u8 lbl_805600E9;
extern s8 lbl_805600EA;
extern u8 lbl_805600EB;
extern u8 lbl_805600ED;
s32 fn_8002173C(void);
void fn_802CFCA0(void);
void fn_802D02F8(s32, s32);
void fn_802D68C4(s32, s32, s32, s32);
void fn_802CFDE0(void);
void fn_802CFF10(void);
void fn_80127464(void);
void fn_802ECBF8(void) {
    if ((u8)lbl_805600E8 == 0) {
        lbl_805600EA = 1;
    }
}

char fn_802ECC10(void) {
    return lbl_805600E8;
}

void fn_802ECC18(u8 arg0) {
    lbl_805600E9 = arg0;
}

#pragma dont_inline on
void fn_802ECC20(void) {
    if (fn_8002173C() == 0) {
        fn_802CFCA0();
        fn_802D02F8(0xFF000000, 1);
        fn_802D68C4(0, 0, 0, 0);
        fn_802CFDE0();
        fn_802CFF10();
    }
}

void fn_802ECC74(void) {
    u8 temp;

    if (lbl_805600ED != 0) {
        return;
    }
    temp = lbl_805600EB;
    lbl_805600ED = 1;
    if (temp != 0) {
        while (lbl_805600E8 != 0) {
            fn_802ECC20();
            fn_80127464();
        }
        fn_802ECC20();
        lbl_805600EB = 0;
    }
    lbl_805600ED = 0;
}

#pragma dont_inline off

