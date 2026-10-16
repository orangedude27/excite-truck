extern void fn_8021889C(void);

#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80128668(void);
s32 fn_80215E68(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80215EC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80215F1C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80215F5C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80215FBC(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x10) ^= 1;
}

u32 fn_80215FDC(void) { return 1; }

u32 fn_80215FE4(void) { return 1; }

u8 fn_80215FF4(u8 *arg0) { return *arg0; }

void fn_8021676C(void) {

}

void fn_802168CC(void) {
    fn_8021889C();
}

void fn_802168D0(void) {
    fn_80218968();
}

void fn_802168D4(void) {
    fn_8021885C();
}

void fn_802168D8(void) {
    fn_80218A34();
}

void fn_802168DC(void) {
    fn_80218ADC();
}

void fn_802168E0(void) {
    fn_80218B88();
}

extern void *lbl_8055EF88;
void* fn_802168E4(void) {
    return lbl_8055EF88;
}

void fn_802168EC(void) {
    fn_80218C98();
}

extern char lbl_8055EF99;
void fn_80216CA8(void) {
    lbl_8055EF99 = 1;
}

