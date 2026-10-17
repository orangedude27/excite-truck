// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F6C8;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned char u8;
typedef float f32;
extern void fn_802885C0(void);
extern void fn_802887EC(void);
extern f32 lbl_80564268;
extern f32 lbl_80564248;
extern u8 lbl_804B3150[12];
extern s32 lbl_804B31E0[];
extern s32 lbl_8055F6C0;
extern f32 fn_8023659C(void);
extern s32 fn_80214AF0(s32);
void* fn_802875B8(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void* fn_80287610(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_80287668(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

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

void fn_8028775C(int arg0) { fn_802869CC(arg0 - 4); }

void fn_80287764(int arg0) { fn_80286A34(arg0 - 4); }

void fn_8028776C(int arg0) { fn_80287238(arg0 - 4); }

void fn_80287774(int arg0) { fn_80283938(arg0 - 4); }

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

void fn_80287978(void) { fn_8028E1D0(); }

void fn_8028797C(void) {
    fn_802882EC(); fn_802A8978(); fn_80298160(); fn_80288A20(); fn_802A1794();
    fn_8028A92C(); fn_8028CF64(); fn_80297980(); fn_80294CC4(); fn_8029C25C();
    fn_8029F188(); fn_80292698(); fn_802A0B50(); fn_802A4C60(); fn_801E7E24();
    fn_802AB628(); fn_802885F0(); fn_802887EC(); fn_802885C0();
}

void fn_802879E4(s32 arg0) {
    if (arg0 == 1) {
        if ((u8)lbl_8055F6BC != 0) fn_8028CFB0();
    } else {
        fn_8028CFB0(); fn_802A0B54(); fn_801B8820(); fn_80161AEC(); fn_802A8DE8(); fn_802AB6D0();
    }
}

void fn_80287A34(void) {
    void **vtable;
    fn_801E12A4(); fn_802A1548();
    vtable = *(void ***)fn_801B83A0();
    ((void (*)(void))vtable[18])();
}

void fn_80287A6C(s32 arg0) {
    if (arg0 == 1 && (u8)lbl_8055F6BC == 0) return;
    fn_80294CC8(arg0); fn_801B8834(); fn_802A1584(); fn_8029C2D4();
    fn_8028A9BC(arg0); fn_8028E240(arg0); fn_80288A1C(arg0); fn_802A17FC(arg0);
    fn_80298124(arg0); fn_8029F300(); fn_802A7C68(); fn_802AB6D4();
}

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

s32 fn_80288208(s32 arg0){return lbl_8055F6C0+arg0*0x28;}

void fn_8028829C(void) {}

void fn_802882A0(void){if(*(s32*)lbl_804B3150)fn_80128670(*(s32*)lbl_804B3150-0x10);*(s32*)lbl_804B3150=0;*(s32*)(lbl_804B3150+4)=0;lbl_804B3150[8]=0;}

void fn_802885C0(void) {}

void fn_80288868(void* hi) {
    lbl_8055F6C8 = hi;
}

