// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void fn_80214A9C(s32);
extern void fn_80214AF0(s32);
extern void fn_80230E90(s32);
extern void fn_80236914(void);
extern u8 lbl_8055F3E9;
extern u8 lbl_8055F3EA;
extern u8 lbl_8055F3EB;
extern u8 lbl_8055F420[];
extern u8 lbl_8055BAC0;
extern u8 lbl_8055BAB8;
extern s32 lbl_802FA6A8[];
extern u8 lbl_8055B860;
void fn_802607C4(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 1;
}

void fn_802607D0(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1E) = 1;
}

void fn_802607DC(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1E) = 0;
    *(u8 *)((u8 *)arg0 + 0x1C) = 0;
}

void fn_802607EC(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 0;
}

void fn_80260814(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 0;
}

void fn_80260848(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 1;
}

extern s32 lbl_802FA6A8[];
extern u8 lbl_8055B860;
void fn_80261688(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(s32 *)((u8 *)arg0 + 8) = arg3;
    *(s32 *)((u8 *)arg0 + 4) = 6;
    *(void **)arg0 = &lbl_8055B860;
    *(s32 *)((u8 *)arg0 + 0xC) = arg2;
    *(s32 *)((u8 *)arg0 + 0x10) = arg1;
}

void fn_80261980(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 zero = 0;
    *(s32 *)((u8 *)arg0 + 0) = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 3;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0xC) = arg3;
    *(s32 *)((u8 *)arg0 + 0x10) = zero;
}

s32 fn_802619D8(s32 *arg0, s32 arg1) {
    return *arg0 + arg1 * 4;
}

void fn_802619E8(void *arg0, s32 arg1, s32 arg2) {
    s32 zero = 0;
    *(s32 *)((u8 *)arg0 + 0) = arg1;
    arg1 = 5;
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0xC) = zero;
    *(s32 *)((u8 *)arg0 + 0x10) = zero;
}

s32 fn_80261A08(s32 *arg0, s32 arg1) {
    return *arg0 + arg1 * 4;
}

void fn_80261A18(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 8;
    *(void **)((u8 *)arg0) = &lbl_8055BAB8;
    *(s32 *)((u8 *)arg0 + 0xC) = 2;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_80261A40(s32 arg0) {
    fn_80236914();
    lbl_8055F3E9 = (u32)__cntlzw(arg0 - 2) >> 5;
}

void fn_80261A7C(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 8;
    *(void **)((u8 *)arg0) = &lbl_8055BAC0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_80261AA0(void) {
    s32 i = 0;
    do {
        fn_80214A9C(i + 10);
        i++;
    } while (i < *(s32 *)(lbl_8055F420 + 0xC));
}

void fn_80261AE8(s32 *arg0, s32 arg1) { *arg0 = arg1; }

void fn_80262158(void) {
}

void fn_8026215C(void) {
}

s32 fn_80262160(void) {
    return 0;
}

void fn_80262168(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1E) && lbl_8055F3E9 && !lbl_8055F3EA) {
        fn_80230E90(0);
        *(u8 *)((u8 *)arg0 + 0x1E) = 0;
    }
    if (lbl_8055F3EB && !lbl_8055F3EA) {
        fn_80214AF0(0x1E);
        return;
    }
    fn_80214A9C(0x1E);
}

void fn_80262574(void) {
}

void fn_80262578(void) {
}

s32 fn_8026257C(void) {
    return 0;
}

void fn_80262584(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1F) && lbl_8055F3E9) {
        fn_80230E90(0);
        *(u8 *)((u8 *)arg0 + 0x1F) = 0;
    }
}

