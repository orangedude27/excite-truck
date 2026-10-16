// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F6C8;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned char u8;
typedef float f32;
extern f32 lbl_80564248;
extern u8 lbl_804B3150[12];
extern s32 lbl_804B31E0[];
extern s32 lbl_8055F6C0;
extern f32 fn_8023659C(void);
extern s32 fn_80214AF0(s32);
void fn_802876A8(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x18) = fn_8023659C();
    *((u8 *)arg0 + 0x1C) = 0;
    fn_80214A9C(0x1D);
}

void fn_802876E8(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f1 = fn_8023659C();
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x18);
    if ((temp_f1 < temp_f0) || ((temp_f1 - temp_f0) > lbl_80564248)) {
        *((u8 *)arg0 + 0x1C) = 1;
    }
    if (*((u8 *)arg0 + 0x1C) != 0) {
        fn_80214AF0(0x1D);
    }
}

s32 fn_8028774C(void *arg0) {
    return *((u8 *)arg0 + 0x1C) == 0;
}

void fn_8028777C(void) {
}

void fn_80287780(s32 arg0) {
    lbl_8055F6C0 = 0;
    fn_802AE374();
    fn_8028DF58();
    fn_802924E8();
    fn_802978B8(arg0);
    fn_80297ED4();
    fn_8029605C();
    fn_802AC458();
}

void fn_802877D0(void) {
    fn_802AC49C();
    fn_802978E4();
    fn_8029261C();
    fn_8028E0F0();
    fn_802AE394();
}

extern s32 fn_801E7DF0(s32);
extern void fn_8028777C(void);
extern void fn_80288218(s32);
extern void fn_802880F4(void);
extern void fn_802A81F0(void);
extern void fn_802888D8(void);
extern void fn_802A1590(void);
extern void fn_8028A664(void);
extern void fn_8028CED8(void);
extern void fn_80294970(void);
extern void fn_80297ED8(void);
extern void fn_8029C1C4(void);
extern void fn_8029EF70(void);
extern void fn_802924F4(void);
extern void fn_802A09B0(void);
extern void fn_802A1290(void);
extern void fn_802A4ADC(void);
extern void fn_80292114(void);
extern void fn_802A7BE8(void);
extern void fn_8029F03C(void);
extern void fn_802AB21C(void);
extern void fn_8028DFB0(void);
extern void fn_80288868(void *);
extern signed char lbl_8055F6BC;
extern void fn_802AB504(void);
extern void fn_8029F0D0(void);
extern void fn_802A7C24(void);
extern void fn_802921F4(void);
extern void fn_802A4B90(void);
extern void fn_802A14F8(void);
extern void fn_802A0AFC(void);
extern void fn_80292618(void);
extern void fn_8029EFBC(void);
extern void fn_8029C22C(void);
extern void fn_80296064(void);
extern void fn_80297FA4(void);
extern void fn_80294C68(void);
extern void fn_8028CF18(void);
extern void fn_8028A784(void);
extern void fn_802A1660(void);
extern void fn_80288988(void);
extern void fn_802A85C8(void);
extern void fn_802881D4(void);
extern void fn_802882A0(void);
extern void fn_802A86A4(void);
extern void fn_8028E138(void);
extern void fn_802980A0(void);
extern void fn_8028A89C(void);
extern void fn_8028CF50(void);
extern void fn_8029222C(void);
extern void fn_80294CC0(void);
extern void fn_80296060(void);
extern void fn_8029F124(void);
extern void fn_80292628(void);
extern void fn_802A172C(void);
extern void fn_802A4C20(void);
extern void fn_802A7C64(void);
extern void fn_802AB5B8(void);
extern void fn_802A9574(void);
extern void fn_80288868(void *);
extern void fn_8028E1A4(void);
void fn_80287974(void) { fn_8028E1A4(); }

void fn_80287AF0(void* alarm) {
    fn_8028A9F4(fn_80292864(alarm));
}

s32 fn_80287B14(void) {
    return ((s32*)lbl_804B3150)[1];
}

s32 fn_80287B24(s32 arg0) {
    return ((s32*)lbl_804B3150)[0] + arg0 * 0x160;
}

void fn_80287B38(s32 arg0) {
    s32 index = lbl_8055F6C0;
    ((s32 *)lbl_804B31E0)[index] = arg0;
    lbl_8055F6C0 = index + 1;
}

extern u8 lbl_804B3150[12];
extern s32 lbl_8055F6C0;
extern s32 lbl_804B31E0[];
extern void fn_80288870(void);
void fn_80287B58(void) {
    fn_80288870();
}

void fn_80288868(void* hi) {
    lbl_8055F6C8 = hi;
}

