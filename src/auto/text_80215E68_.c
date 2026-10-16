extern void fn_8021889C(void);

#include <types.h>

extern void *lbl_8055EF88;
extern s32 lbl_8055EF78;
extern u32 lbl_8055EF7C;
extern u32 lbl_8055EF8C;
extern void (*lbl_8055EF90)(void);
extern u8 lbl_8055EF70;
extern u8 lbl_8055F024;
extern u32 lbl_804908C8[16];
extern s32 fn_802C8530(void);
extern s32 fn_80216244(void);
extern s32 fn_802160AC(void);
extern s32 fn_80211F54(void);
extern s32 fn_80019BA8(void);
extern s32 fn_80230DA0(void);
extern s32 fn_802C855C(void);
extern s32 fn_802C2B48(void);
extern s32 fn_80211F64(void);
extern s32 fn_802164D8(void);
extern s32 fn_80129AFC(void);
extern s32 fn_802161CC(s32);
extern s32 fn_80218370(void);
extern s32 fn_802E97B4(void);
extern void fn_802166B8(void);

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

extern s32 fn_802C3034(s32);
extern s32 fn_802C3424(s32, s32, s32, s32, s32);
extern s32 lbl_8055FBDC;
extern s32 fn_802E4A10(void);
extern char lbl_8033D768;
extern char lbl_8033D774;
char *fn_80215F9C(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x10) != 0) return (char *)&lbl_8033D774;
    return (char *)&lbl_8033D768;
}

void fn_80215FBC(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x10) ^= 1;
}

void fn_80215FCC(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x10) ^= 1;
}

u32 fn_80215FDC(void) { return 1; }

u32 fn_80215FE4(void) { return 1; }

u8 fn_80215FF4(u8 *arg0) { return *arg0; }

s32 fn_80215FFC(void *arg0) {
    s32 result = 0;
    if (*(u8 *)arg0 != 0 && *(s32 *)((u8 *)arg0 + 4) == fn_802E4A10()) result = 1;
    return result;
}

u32 fn_80216054(void) { return 1; }

void fn_8021605C(void *arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r3;
    fn_802C3034(arg1);
    temp_r4 = *(s32 *)((u8 *)arg0 + 8);
    temp_r3 = *(s32 *)((u8 *)arg0 + 4);
    fn_802C3424(temp_r3, temp_r4, temp_r3 + *(s32 *)((u8 *)arg0 + 0xC), temp_r4 + *(s32 *)((u8 *)arg0 + 0x10), lbl_8055FBDC);
}

void fn_802166B8(void) {
    fn_802C8530();
    fn_80216244();
    fn_802160AC();
    if (fn_80211F54() == 0) {
        fn_80019BA8();
    }
    if (lbl_8055F024 != 0) {
        fn_80230DA0();
    }
    fn_802C855C();
    fn_802C2B48();
}

extern u32 lbl_8055EF98;
u32 *fn_80216708(void) {
    return &lbl_8055EF98;
}

void fn_80216710(void) {
    lbl_8055EF88 = 0;
    lbl_804908C8[0] = 0; lbl_804908C8[1] = 0; lbl_804908C8[2] = 0; lbl_804908C8[3] = 0;
    lbl_804908C8[4] = 0; lbl_804908C8[5] = 0; lbl_804908C8[6] = 0; lbl_804908C8[7] = 0;
    lbl_804908C8[8] = 0; lbl_804908C8[9] = 0; lbl_804908C8[10] = 0; lbl_804908C8[11] = 0;
    lbl_804908C8[12] = 0; lbl_804908C8[13] = 0; lbl_804908C8[14] = 0; lbl_804908C8[15] = 0;
    lbl_8055EF7C = 0;
    lbl_8055EF8C = 0;
    lbl_8055EF90 = 0;
}

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

