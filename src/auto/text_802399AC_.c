#include <stdarg.h>
typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
extern s32 lbl_8049870C[];
extern s32 fn_80209030(float);
extern s32 fn_802090BC(s32);
extern s32 fn_8020A5F8(float);
extern s32 fn_802C82C4(s32);
extern s32 fn_802E30C8(s32, ...);
extern s32 fn_80128668();
extern s32 fn_80128670(s32);
#pragma push
#pragma small_data off
extern char lbl_80340B58[];
#pragma pop
extern s32 fn_8027B9EC(s32);
extern s32 fn_80214CB4(void *);
extern s32 fn_80214A38(s32);
extern s32 fn_80214A9C(s32);
extern s32 fn_80214AF0(s32);
extern s32 fn_80131234(void *);
extern s32 fn_8000DA10(void);
extern s32 fn_8000DB34(void);
extern s32 fn_8021521C(s32, s32, s32);
#pragma push
#pragma small_data off
__declspec(section ".data") extern s32 lbl_8034109C;
#pragma pop
extern s32 fn_80239E5C(void *, s32);
extern s32 lbl_8055BB00;
extern s32 lbl_8055F110;
extern void *lbl_8055F10C;
extern s32 lbl_802FA040[];
extern s32 lbl_804986F8[];
extern s32 fn_802146BC(void *, s32, s32, s32);
__declspec(section ".sdata") extern char lbl_8055BAC0[];
__declspec(section ".sdata") extern char lbl_8055BABC[];
__declspec(section ".sdata") extern char lbl_8055B860[];
__declspec(section ".sdata") extern char lbl_8055BACC[];
__declspec(section ".sdata") extern char lbl_8055BAD4[];
__declspec(section ".sdata") extern char lbl_8055BADC[];
__declspec(section ".sdata") extern char lbl_8055BAE8[];
__declspec(section ".sdata") extern char lbl_8055BAF0[];
__declspec(section ".sdata") extern char lbl_8055BAF8[];
__declspec(section ".sdata") extern char lbl_8055BAB8[];
extern s32 fn_8023FCFC(void);
extern s32 fn_8023D1C0(void);
extern s32 fn_8023C958(void);
extern s32 fn_8000DA80(void);
extern s32 fn_8023C94C(void);
extern s32 fn_802E4A10(void);
extern s32 fn_8023D4B8(void);
extern s32 fn_8023C3D4(void);
extern s32 fn_80278A24(void);
extern s32 fn_802449A0(void);
extern s32 fn_8024C070(void);
extern s32 fn_8024C370(void);
extern s32 fn_80257284(void);
extern s32 fn_802399DC(s32);
extern void fn_80236914(void);
extern s32 fn_802E317C(const char *, ...);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern s32 lbl_8034127C[];
extern float lbl_80563730;
extern s32 fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, s32, float);

extern void* lbl_8055BAC8;
s32 fn_80214D04(void);
/* Return nonzero when the current player's secondary list (index 1) is valid. */
s32 fn_802399AC(void) {
    return fn_8027B9EC(1) != 0;
}

/* Menu action: capture the active window's current menu index (fn_80214D04)
   into the saved selection lbl_8055BAC8, so the companion action fn_80239AB8
   can later restore it via fn_80214CB4. */
void fn_80239A94(void) {
    lbl_8055BAC8 = (void*)fn_80214D04();
}

extern s32 fn_80214CB4(void *);
extern s32 fn_80214A38(s32);
extern s32 fn_80214A9C(s32);
extern s32 fn_80214AF0(s32);
extern s32 fn_80131234(void *);
extern s32 fn_8000DA10(void);
extern s32 fn_8000DB34(void);
extern s32 fn_8021521C(s32, s32, s32);
extern s32 fn_8027B9EC(s32);
extern s32 fn_802104D0(void);
extern s32 fn_80214B44(s32);
extern s32 fn_80214B94(s32);
extern void *lbl_8055BAC8;
#pragma push
#pragma small_data off
#pragma pop
extern char lbl_80340C44[];
extern char lbl_80340C24[];
extern s32 lbl_8049870C[];
void fn_80239AB8(void) {
#define sSavedMenuIndex lbl_8055BAC8
#define SetMenuIndex    fn_80214CB4
    /* Restore the active UI window's menu index from the value saved by fn_80239A94. */
    SetMenuIndex(sSavedMenuIndex);
#undef sSavedMenuIndex
#undef SetMenuIndex
}

#pragma push
#pragma use_lmw_stmw off
void fn_80239AC0(void)
{
    s32 args[5];
    s32 vals[80];
    char *base = lbl_80340B58;
    char *err = base + 0x60;
    s32 *tbl = lbl_802FA040;
    s32 *ext = lbl_804986F8;
    s32 done = 0;
    s32 r;
    vals[0] = (s32)&lbl_8055BAC0; vals[1] = 8; vals[2] = (s32)fn_80239AB8; vals[3] = 0; vals[4] = 0;
    vals[5] = (s32)&lbl_8055BABC; vals[6] = 8; vals[7] = (s32)fn_80239A94; vals[8] = 1; vals[9] = 0;
    vals[10] = (s32)&lbl_8055B860; vals[11] = 6; vals[12] = 0; vals[13] = -1; vals[14] = 0x1b;
    vals[15] = (s32)&lbl_8055BACC; vals[16] = 0; vals[17] = 0; vals[18] = 0; vals[19] = 0;
    vals[20] = (s32)&lbl_8055BAD4; vals[21] = 0; vals[22] = 0; vals[23] = 8; vals[24] = 0;
    vals[25] = (s32)(base + 0x2c); vals[26] = 0; vals[27] = 0; vals[28] = 3; vals[29] = 0;
    vals[30] = (s32)&lbl_8055BADC; vals[31] = 0; vals[32] = 0; vals[33] = 0xa; vals[34] = 0;
    vals[35] = (s32)(base + 0x38); vals[36] = 0; vals[37] = 0; vals[38] = 0xb; vals[39] = 0;
    vals[40] = (s32)&lbl_8055BAE8; vals[41] = 0; vals[42] = 0; vals[43] = 0x10; vals[44] = 0;
    vals[45] = (s32)(base + 0x44); vals[46] = 0; vals[47] = 0; vals[48] = 4; vals[49] = 0;
    vals[50] = (s32)(base + 0x50); vals[51] = 0; vals[52] = 0; vals[53] = 5; vals[54] = 0;
    vals[55] = (s32)err; vals[56] = 0; vals[57] = (s32)fn_802399DC; vals[58] = 6; vals[59] = 0;
    vals[60] = (s32)&lbl_8055BAF0; vals[61] = 0; vals[62] = 0; vals[63] = 0xc; vals[64] = 0;
    vals[65] = (s32)&lbl_8055BAF8; vals[66] = 0; vals[67] = 0; vals[68] = 0xd; vals[69] = 0;
    vals[70] = (s32)&lbl_8055BAB8; vals[71] = 8; vals[72] = (s32)fn_80236914; vals[73] = 2; vals[74] = 0;
    vals[75] = ext[0]; vals[76] = ext[1]; vals[77] = ext[2]; vals[78] = ext[3]; vals[79] = ext[4];
    args[0] = tbl[0]; args[1] = (s32)vals; args[2] = tbl[2]; args[3] = tbl[3]; args[4] = tbl[4];
    while (1) {
        r = fn_802146BC(args, -999, -999, 1);
        switch (r + 2) {
        case 17: fn_8000DA10(); fn_8023FCFC(); break;
        case 2: fn_8023D1C0(); break;
        case 6: fn_8023C958(); break;
        case 8: fn_8000DA80(); done = 1; break;
        case 7: fn_8023C94C(); break;
        case 5: fn_802E4A10(); fn_8023D4B8(); break;
        case 10: fn_8023C3D4(); break;
        case 18: fn_80278A24(); break;
        case 11: fn_802449A0(); break;
        case 14: fn_8024C070(); break;
        case 13: fn_8024C370(); break;
        case 15: fn_80257284(); break;
        case 0:
        case 1: done = 1; break;
        case 3:
        case 4:
        case 9:
        case 12:
        case 16: break;
        default: fn_802E317C(err + 0xc); break;
        }
        if (done) break;
    }
}
#pragma pop

#pragma push
#pragma small_data off
/* Asks the player to confirm a change of the track-music setting.
 *
 * gOptionsState[6] is the music-slot state fn_80210570() read for the settings
 * screen and [7] the copy taken with it (fn_80239F74); while they differ and at
 * least one song is available (fn_802104D0), the "confirm change" message box is
 * put up from its heading and body texts, and what it answers is returned.
 * Nothing to confirm: 1. */
s32 fn_80239DE4(void) {
#define gOptionsState lbl_8049870C /* settings screen state, see fn_80239F74 */
#define MessageLookup fn_80131234  /* message id of a "Group:NAME" text */
#define ConfirmDialog fn_8021521C  /* message box: heading, body, flag */
    s32 *state = (s32 *)gOptionsState;
    if (state[6] != state[7] && fn_802104D0()) {
        s32 bodyMsg = fn_80131234(lbl_80340C44); /* TrackMusic:CONFIRM_CHANGE_BODY */
        s32 headMsg = fn_80131234(lbl_80340C24); /* TrackMusic:CONFIRM_CHANGE_HEAD */
        return ConfirmDialog(headMsg, bodyMsg, 0);
    }

#undef ConfirmDialog
#undef MessageLookup
#undef gOptionsState
    return 1;
}
#pragma pop
#pragma dont_inline on
s32 fn_80239E5C(void *__restrict arg0, s32 arg1) {
#pragma scheduling invalid_target
    s32 *p = (s32 *)arg0;
    fn_80209030(*(float *)((char *)arg0 + 0x14));
    fn_8020A5F8(*(float *)((char *)arg0 + 0x10));
    if (arg1 != 0 || p[0] != p[1]) {
        ((s32 (*)(s32, ...))fn_802E30C8)((s32)&lbl_8055BB00, p[0]);
        fn_802C82C4(p[0]);
    }
    if (arg1 != 0 || p[2] != p[3]) fn_802090BC(p[2]);
#pragma scheduling reset
}
#pragma dont_inline reset

#pragma push
#pragma cplusplus on
/* Applies pending audio/video option changes, commits display and sound modes, and shows or hides UI group 0x1E based on the Erase Data widget state. */
extern "C" s32 fn_80239EF0(void) {
    class UIOptionsWidget {
    public:
        virtual s32 f0(s32 *);
        virtual s32 f1(s32 *);
        virtual s32 f2(s32 *);
        virtual s32 f3(s32 *);
        virtual s32 f4(s32 *);
        virtual s32 f5(s32 *);
        virtual s32 f6(s32 *);
        virtual s32 f7(s32 *);
        virtual s32 f8(s32 *);
        virtual s32 f9(s32 *);
        virtual s32 f10(s32 *);
        virtual s32 f11(s32 *);
        virtual s32 f12(s32 *);
        virtual s32 f13(s32 *);
        virtual s32 f14(s32 *);
        virtual s32 f15(s32 *);
        virtual s32 f16(s32 *);
        virtual s32 f17(s32 *);
        virtual s32 f18(s32 *);
        virtual s32 f19(s32 *);
        virtual s32 f20(s32 *);
        virtual s32 f21(s32 *);
        virtual s32 isSelected(s32 *);
    };
#define gOptionsState lbl_8049870C
#define gEraseDataWidget lbl_8055F10C
#define UIOptions_ApplyAudioVideo fn_80239E5C
#define UIShowGroup fn_80214AF0
#define UIHideGroup fn_80214A9C
    UIOptions_ApplyAudioVideo(gOptionsState, 0);
    gOptionsState[1] = gOptionsState[0];
    gOptionsState[3] = gOptionsState[2];
    if (((UIOptionsWidget *)gEraseDataWidget)->isSelected(gOptionsState) != 0) {
        UIShowGroup(0x1E);
    } else {
        UIHideGroup(0x1E);
    }
    return 0;
#undef UIHideGroup
#undef UIShowGroup
#undef UIOptions_ApplyAudioVideo
#undef gEraseDataWidget
#undef gOptionsState
}
#pragma cplusplus reset
#pragma pop
/* Return this widget's byte field at offset 0x20. */
unsigned char fn_80239F6C(void *widget) { return *(unsigned char *)((char *)widget + 0x20); }

extern s32 fn_802C83C4(void);
extern s32 fn_802090CC(void);
extern s32 fn_80210570(void);
extern s32 fn_802146BC(void *, s32, s32, s32);
extern void *fn_8023AB78(register void *arg0, register s32 arg1, register s32 arg2, ...);
extern void *fn_8023AA2C(register void *arg0, register s32 arg1, register s32 arg2, ...);
extern void *fn_8023A8D8(register void *arg0, register s32 arg1, register s32 arg2, ...);
extern s32 lbl_804986F8[];
extern void fn_801331C4(s32, void *, void *);
extern void fn_801332D0(s32, void *, void *);
extern void *fn_8023AB78(register void *, register s32, register s32, ...);
extern void *fn_8023AA2C(register void *, register s32, register s32, ...);
extern void *fn_8023A8D8(register void *, register s32, register s32, ...);
extern char lbl_80341038[];
#pragma opt_propagation off
__declspec(section ".data") extern s32 lbl_80340F78, lbl_80340F18, lbl_80340E58, lbl_80340EB8, lbl_80340DF8;
__declspec(section ".data") extern s32 lbl_802FA054[], jumptable_80340DAC[];
__declspec(section ".data") extern s32 lbl_803410D8, lbl_80341108;
void fn_80239F74(void) {
#pragma scheduling invalid_target
    typedef float f32;
    typedef unsigned char u8;
    typedef struct {
        f32 sp8, sC, s10, s14;
        s32 sp18; s32 *s1C; s32 sp20, s24, s28; s32 *s2C;
        u8 pad30[0x10];
        s32 sp40; u8 sp44; u8 pad45[3]; s32 *s48;
        u8 pad4C[0x10];
        s32 s5C, s60; u8 s64; u8 pad65[3]; s32 *s68;
        u8 pad6C[0x10];
        s32 s7C, s80; s32 *s84;
        u8 pad88[0x10];
        s32 s98, s9C;
        s32 sA0[8];
        s32 sC0[8];
        s32 sE0[8];
        s32 s100, s104, s108, s10C, s110;
        u8 pad114[4];
        s32 *s118; u8 s11C; u8 pad11D[3];
        s32 desc2[9];
        s32 buf0[11];
        s32 s170, s174; s32 *s178; s32 s17C, s180;
        s32 *s184; s32 s188; s32 *s18C; s32 s190, s194;
        s32 *s198; s32 s19C; s32 *s1A0; s32 s1A4, s1A8;
        s32 *s1AC; s32 s1B0; s32 *s1B4; s32 s1B8, s1BC;
        s32 *s1C0; s32 s1C4; s32 *s1C8; s32 s1CC, s1D0;
        s32 *s1D4; s32 s1D8; s32 *s1DC; s32 s1E0, s1E4;
        s32 *s1E8; s32 s1EC; s32 s1F0; s32 *s1F4; s32 s1F8;
        s32 *s1FC; s32 s200; s32 *s204; s32 s208, s20C;
        s32 *s210; s32 s214; s32 s218; s32 s21C, s220;
        s32 *s224; s32 s228; s32 *s22C; s32 s230, s234;
        s32 *s238; s32 s23C; s32 *s240; s32 s244, s248;
        s32 *s24C; s32 s250; s32 s254; s32 s258, s25C;
        s32 *s260; s32 s264; s32 *s268; s32 s26C; s32 *s270;
        s32 *s274; s32 s278; s32 *s27C; s32 s280, s284;
        s32 s288, s28C, s290, s294, s298;
    } Frame;
    extern s32 fn_802C83C4(void), fn_802090CC(void), fn_80210570(void);
    extern s32 fn_80131234(void *);
    extern void *fn_8023AB78(register void *, register s32, register s32, ...);
    extern void *fn_8023AA2C(register void *, register s32, register s32, ...);
    extern void *fn_8023A8D8(register void *, register s32, register s32, ...);
    extern s32 lbl_8055BB08, lbl_8055BB10, lbl_8055BB18, lbl_8055BB20, lbl_8055BB28;
    extern s32 fn_8023A8B0(void);
    extern void fn_801331C4(s32, void *, void *);
    extern void fn_801332D0(s32, void *, void *);
    extern void fn_8013323C(s32, void *, f32);
    extern void fn_80133348(s32, void *, s32);
    extern s32 fn_8027B8C0(s32), fn_802104D0(void), fn_80210514(s32);
    extern s32 fn_802E8D84(void), fn_802E6FBC(void);
    extern s32 fn_8027B77C(void), fn_8000DA80(void), fn_8027B690(void);
    extern s32 fn_8026311C(void), fn_80263F30(s32, s32, s32);
    extern s32 fn_80128670(s32), fn_802328D4(s32);
    extern s32 lbl_803410D8, lbl_80341108;
    extern f32 lbl_80563734;
    Frame s;
    s32 *p;
    char * const base = lbl_80340B58;
    s32 * const g = lbl_804986F8;
    s32 a, b, c, t, rv, r, flag;

    t = fn_802C83C4();
    p = g + 5;
    g[5] = t;
    p[1] = t;
    a = fn_80131234(base + 0x134);
    b = fn_80131234(base + 0x120);
    fn_8023AB78((void *)s.buf0, (s32)p, b, a, 0);
    t = fn_802090CC();
    p[2] = t;
    p[3] = t;
    {
        s32 d, e, f;
        d = fn_80131234(base + 0x164);
        e = fn_80131234(base + 0x154);
        f = fn_80131234(base + 0x148);
        fn_8023AA2C((void *)s.sE0, (s32)(p + 2), f, e, d, 0);
    }
    t = fn_80210570();
    p[6] = t;
    p[7] = t;
    {
        s32 d, e, f;
        d = fn_80131234(base + 0x1B0);
        e = fn_80131234(base + 0x198);
        f = fn_80131234(base + 0x180);
        fn_8023A8D8((void *)s.sC0, (s32)(p + 6), f, e, d, 0);
    }
    *(f32 *)(p + 4) = lbl_80563730;
    fn_801331C4(4, base + 0x1C8, p + 4);
    *(f32 *)(p + 5) = lbl_80563730;
    fn_801331C4(4, base + 0x1D8, p + 5);
    *(s32 *)((char *)s.desc2 + 0x14) = 0;
    *(s32 *)s.desc2 = (s32)lbl_80341038;
    *(s32 *)((char *)s.desc2 + 0x1c) = 0;
    *(u8 *)((char *)s.desc2 + 0x20) = 0;
    lbl_8055F10C = s.desc2;
    p[8] = 0;
    t = fn_8000DA10();
    fn_801332D0(t + 0xc, base + 0x1E8, p + 8);
    a = fn_80131234(base + 0x204);
    b = fn_80131234(base + 0x1F4);
    fn_8023AA2C((void *)s.sA0, (s32)(p + 8), b, a, 0);

    s.s98 = 0;
    s.s9C = 0;
    s.s7C = 0;
    s.s84 = (s32 *)&lbl_80340F78;
    s.sE0[7] = (s32)&lbl_80340E58;
    s.s80 = 0;
    s.s68 = (s32 *)&lbl_80340F18;
    s.s110 = 0;
    s.s118 = (s32 *)s.sC0;
    s.s11C = 1;
    s.s5C = 0;
    s.s60 = 0;
    s.s48 = (s32 *)&lbl_80340EB8;
    s.s64 = 0;
    s.sp40 = 0;
    s.s2C = (s32 *)&lbl_80340DF8;
    lbl_8055F110 = (s32)&s.s2C;
    rv = fn_8027B8C0(1);
    *(f32 *)&s.s10 = lbl_80563730;
    *(f32 *)&s.s14 = lbl_80563734;
    *(f32 *)&s.sp8 = lbl_80563730;
    *(f32 *)&s.sC = lbl_80563734;
    s.sp44 = (u8)rv;
    s.s178 = (s32 *)&s.s2C;
    s.s174 = 5;
    s.s170 = 0;
    s.s17C = 0;
    s.s180 = 0;
    s.s188 = 5;
    s.s184 = (s32 *)&lbl_8055BB08;
    s.s18C = (s32 *)s.buf0;
    s.s190 = 0;
    s.s194 = 0;
    s.s19C = 9;
    s.s198 = (s32 *)(base + 0x1c8);
    s.s1A0 = p + 4;
    s.s1A4 = *(s32 *)&s.s14;
    s.s1A8 = *(s32 *)&s.s10;
    s.s1B0 = 5;
    s.s1AC = (s32 *)(base + 0x218);
    s.s1B4 = (s32 *)&s.s68;
    s.s1B8 = 0;
    s.s1BC = 0;
    s.s1C4 = 9;
    s.s1C0 = (s32 *)(base + 0x224);
    s.s1C8 = p + 5;
    s.s1CC = *(s32 *)&s.sC;
    s.s1D0 = *(s32 *)&s.sp8;
    s.s1D8 = 5;
    s.s1D4 = (s32 *)(base + 0x230);
    s.s1DC = (s32 *)&s.sE0[7];
    s.s1E0 = 0;
    s.s1E4 = 0;
    s.s1EC = 0x10;
    s.s1E8 = (s32 *)&lbl_8055BB10;
    s.s1F0 = 0;
    s.s1F4 = (s32 *)s.sC0;
    s.s1F8 = 0;
    s.s200 = 5;
    s.s1FC = (s32 *)(base + 0x23c);
    s.s204 = (s32 *)&s.sE0[7];
    s.s208 = 0;
    s.s20C = 0;
    s.s214 = 0x10;
    s.s210 = (s32 *)&lbl_8055BB18;
    s.s218 = 0;
    s.s21C = rv;
    s.s220 = 0;
    s.s228 = 5;
    s.s23C = 5;
    s.s238 = (s32 *)&lbl_8055BB20;
    s.s268 = (s32 *)fn_80239DE4;
    s.s240 = (s32 *)s.desc2;
    s.s1C = (s32 *)*(s32 *)((char *)lbl_802FA054 + 4);
    s.s24C = (s32 *)&lbl_8055BB28;
    s.s26C = -1;
    s.s280 = 0x10;
    s.s258 = -2;
    s.s270 = (s32 *)0x1b;
    s.s284 = 0x121;
    s.s224 = (s32 *)(base + 0x248);
    s.s22C = (s32 *)&s.s48;
    s.s230 = 0;
    s.s234 = 0;
    s.s244 = 0;
    s.s248 = 0;
    s.s250 = 0;
    s.s254 = 0;
    s.s25C = 0;
    s.s264 = 6;
    s.s260 = (s32 *)&lbl_8055B860;
    s.s278 = 6;
    s.s274 = (s32 *)&lbl_8055B860;
    s.s27C = (s32 *)fn_8023A8B0;
    s.s288 = g[0];
    s.s28C = g[1];
    s.s290 = g[2];
    s.s294 = g[3];
    s.s298 = g[4];
    s.sp18 = *(s32 *)lbl_802FA054;
    s.sp20 = *(s32 *)((char *)lbl_802FA054 + 8);
    s.s24 = *(s32 *)((char *)lbl_802FA054 + 0xc);
    s.s28 = *(s32 *)((char *)lbl_802FA054 + 0x10);
    s.s1C = (s32 *)&s.s170;
    g[14] = p[0];
    g[15] = p[1];
    g[16] = p[2];
    g[17] = p[3];
    *(f32 *)&g[18] = *(f32 *)(p + 4);
    *(f32 *)&g[19] = *(f32 *)(p + 5);
    g[20] = p[6];
    g[21] = p[7];
    g[22] = p[8];

    flag = 1;
    while (1) {
        r = fn_802146BC((void *)&s.sp18, -999, -999, 1);
        if (r + 2 > 0x12) continue;
        switch (r + 2) {
        case 0:
        case 1:
            fn_8013323C(4, base + 0x1C8, *(f32 *)(p + 4));
            fn_8013323C(4, base + 0x1D8, *(f32 *)(p + 5));
            t = fn_8000DA10();
            fn_80133348(t + 0xc, base + 0x1E8, p[8]);
            if (fn_802104D0() != 0) {
                fn_80210514(p[6]);
                if (fn_802E8D84() != 0) fn_802E6FBC();
            }
            flag = 0;
            lbl_8055F10C = 0;
            continue;
        case 8:
            fn_8027B77C();
            fn_8000DA80();
            fn_8027B690();
            flag = 0;
            continue;
        case 6:
            *(u8 *)((char *)s.buf0 + 0x28) = 1;
            {
                s32 *q = (s32 *)*(s32 *)((char *)s.buf0 + 0x20);
                *q = (*q + 1) % *(s32 *)((char *)s.buf0 + 0x1c);
            }
            continue;
        case 7:
            {
                s32 *q = (s32 *)*(s32 *)((char *)s.sE0 + 0x18);
                *q = (*q + 1) % *(s32 *)((char *)s.sE0 + 0x14);
            }
            continue;
        case 5:
            fn_8026311C();
            continue;
        case 18:
            fn_80263F30(0, 1, 0);
            break;
        default:
            break;
        }
        break;
    }
    if (flag == 0 && &s.s2C != 0) {
        lbl_8055F110 = 0;
        s.sA0[3] = (s32)&lbl_803410D8;
        fn_80128670(s.sA0[4]);
        s.sC0[3] = (s32)&lbl_8034109C;
        fn_80128670(s.sC0[4]);
        s.sE0[3] = (s32)&lbl_803410D8;
        fn_80128670(s.sE0[4]);
        s.buf0[0] = (s32)&lbl_80341108;
        fn_80128670(s.buf0[6]);
        fn_802328D4(s.buf0[9]);
        s.buf0[9] = 0;
    }
}
#pragma opt_propagation reset
extern s32 fn_80209030(float);
extern s32 fn_802090BC(s32);
extern s32 fn_8020A5F8(float);
extern s32 fn_802C82C4(s32);
extern s32 lbl_8055BB00;
extern s32 fn_80239E5C(void *, s32);
extern void *lbl_8055F10C;
extern s32 fn_80128668();
extern s32 lbl_8055F110;
s32 fn_8023A5AC(s32 arg0, s32 arg1) {
    /* Clear the global object pointer; optionally free the object. */
    if (arg0 != 0) {
        lbl_8055F110 = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

s32 fn_8023A5F4(s32 ptr, s32 count) {
    /* Free ptr via the mode-3 pool allocator when it is non-null and count is positive; return ptr unchanged. */
    if (ptr != 0 && count > 0) {
        fn_80128668();
    }
    return ptr;
}

s32 fn_8023A634(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_8023A674(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

s32 fn_8023A6B4(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_8023A6F4(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_8023A734(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern s32 fn_80128670(s32);
__declspec(section ".data") extern s32 lbl_80341108;
extern s32 fn_802328D4(s32);
#pragma small_data off
__declspec(section ".data") extern s32 lbl_8034109C;
void *__dt__Q28PSSystem7SeqHeapFv_8023A774(void *object, s32 shouldDelete) {
    /* Destroy a SeqHeap object: reset vtable, release owned heap storage, then optionally delete the object. */
    if (object != 0) {
        *(s32 **)((char *)object + 0xC) = &lbl_8034109C;
        fn_80128670(*(s32 *)((char *)object + 0x10));
        if (shouldDelete > 0) {
            fn_80128668(object);
        }
    }
    return object;
}

__declspec(section ".data") extern s32 lbl_803410D8;
/* PSSystem::SeqHeap scalar-deleting destructor variant: install this variant's vtable, free the owned heap buffer, then delete the object when requested. */
void *__dt__Q28PSSystem7SeqHeapFv_8023A7D8(void *this_, s32 shouldDelete) {
    if (this_ != 0) {
        *(s32 **)((char *)this_ + 0xC) = &lbl_803410D8;
        fn_80128670(*(s32 *)((char *)this_ + 0x10));
        if (shouldDelete > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

#pragma push
#pragma small_data off
/* Destructor-like cleanup: installs vtable, releases owned resources, optionally deletes the object. */
void *fn_8023A83C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(s32 **)arg0 = &lbl_80341108;
        fn_80128670(*(s32 *)((char *)arg0 + 0x18));
        fn_802328D4(*(s32 *)((char *)arg0 + 0x24));
        *(s32 *)((char *)arg0 + 0x24) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop
s32 fn_8023A8B0(void) {
    /* PSSystem state query: true while the global system object exists and its
       active/ready flag (byte +0x18) is set. Cleared when the system is torn down. */
    register s32 *system = (s32 *)lbl_8055F110;
    if (system != 0 && *((unsigned char *)system + 0x18) != 0) return 1;
    return 0;
}

__declspec(section ".data") extern s32 lbl_80341290;
extern void *fn_8012850C(s32,s32 *);
#pragma push
#pragma small_data off
#pragma push
#pragma small_data off
#pragma scheduling invalid_target
void *fn_8023A8D8(register void *arg0, register s32 arg1, register s32 arg2, ...) {
    va_list ap;
    s32 offset;

    /* Initialize an object with a vtable and a variadic 0-terminated list of s32 items. */
    *(unsigned char *)arg0 = 0;
    *(s32 *)((char *)arg0 + 4) = -1;
    *(unsigned char *)((char *)arg0 + 8) = 0;
    *(s32 **)((char *)arg0 + 0xC) = &lbl_8034109C;
    va_start(ap, arg2);
    *(s32 *)((char *)arg0 + 0x14) = 0;
    do {
        (*(s32 *)((char *)arg0 + 0x14))++;
    } while (va_arg(ap, s32) != 0);
    va_end(ap);
    *(s32 **)((char *)arg0 + 0x10) = fn_8012850C(*(s32 *)((char *)arg0 + 0x14) * 4, &lbl_80341290);
    va_start(ap, arg2);
    offset = 0;
    do {
        *(s32 *)((char *)*(s32 **)((char *)arg0 + 0x10) + offset) = arg2;
        offset += 4;
        arg2 = va_arg(ap, s32);
    } while (arg2 != 0);
    va_end(ap);
    *(s32 *)((char *)arg0 + 0x1C) = arg1;
    *(s32 *)((char *)arg0 + 0x18) = *(s32 *)((char *)arg0 + 0x14);
    return arg0;
}
#pragma pop

__declspec(section ".data") extern s32 lbl_803410D8;
__declspec(section ".data") extern s32 lbl_803412A4;
extern void *fn_8012850C(s32, s32 *);
#pragma small_data off
#pragma push
#pragma scheduling invalid_target
void *fn_8023AA2C(register void *obj, register s32 value, register s32 firstItem, ...) {
  va_list ap;
  s32 offset;
  /* Initialize a variadic item-list object: set vtable, count items until 0 sentinel, allocate and copy them, and store value. */
  *(unsigned char *)obj = 0;
  *(s32 *)((char *)obj + 4) = -1;
  *(unsigned char *)((char *)obj + 8) = 0;
  *(s32 **)((char *)obj + 0xC) = &lbl_803410D8;
  va_start(ap, firstItem);
  *(s32 *)((char *)obj + 0x14) = 0;
  do {
    (*(s32 *)((char *)obj + 0x14))++;
  } while (va_arg(ap, s32) != 0);
  va_end(ap);
  *(s32 **)((char *)obj + 0x10) = fn_8012850C(*(s32 *)((char *)obj + 0x14) * 4, &lbl_803412A4);
  va_start(ap, firstItem);
  offset = 0;
  do {
    *(s32 *)((char *)*(s32 **)((char *)obj + 0x10) + offset) = firstItem;
    offset += 4;
    firstItem = va_arg(ap, s32);
  } while (firstItem != 0);
  va_end(ap);
  *(s32 *)((char *)obj + 0x18) = value;
  return obj;
}
#pragma pop
__declspec(section ".data") extern s32 lbl_803412B8;
__declspec(section ".data") extern s32 lbl_803412C8;
extern s32 fn_80232578(s32 *);
#pragma push
#pragma small_data off
extern s32 lbl_803412B8;
extern s32 lbl_803412C8;
#pragma push
#pragma small_data off
#pragma scheduling invalid_target
void *fn_8023AB78(register void *arg0, register s32 arg1, register s32 arg2, ...) {
    /* Variadic constructor: initializes fields/vtable, counts and copies trailing s32 args until 0 into an allocated array, then stores arg1 and returns arg0. */
    va_list ap;
    s32 offset;
    *(s32 *)((char *)arg0 + 0x14) = 0;
    *(s32 **)arg0 = &lbl_80341108;
    *(s32 *)((char *)arg0 + 0x24) = fn_80232578(&lbl_803412C8);
    *(unsigned char *)((char *)arg0 + 0x28) = 0;
    va_start(ap, arg2);
    *(s32 *)((char *)arg0 + 0x1C) = 0;
    do {
        (*(s32 *)((char *)arg0 + 0x1C))++;
    } while (va_arg(ap, s32) != 0);
    va_end(ap);
    *(s32 **)((char *)arg0 + 0x18) = fn_8012850C(*(s32 *)((char *)arg0 + 0x1C) * 4, &lbl_803412B8);
    va_start(ap, arg2);
    offset = 0;
    do {
        *(s32 *)((char *)*(s32 **)((char *)arg0 + 0x18) + offset) = arg2;
        offset += 4;
        arg2 = va_arg(ap, s32);
    } while (arg2 != 0);
    va_end(ap);
    *(s32 *)((char *)arg0 + 0x20) = arg1;
    return arg0;
}
#pragma pop

#pragma small_data on
void fn_8023ACCC(void) {
    /* Intentionally empty callback in the UI selector code: does no work. */
}

/* Step the selector's current index back by one with wraparound and flag it changed. */
void fn_8023ACD0(void *selector) {
    s32 count = *(s32 *)((char *)selector + 0x1C);
    s32 *index = *(s32 **)((char *)selector + 0x20);
    *(unsigned char *)((char *)selector + 0x28) = 1;
    *index = (count + *index - 1) % count;
}

/* Advance the selector's current index by one with wraparound and flag it changed. */
void fn_8023AD00(void *selector) {
    s32 *index = *(s32 **)((char *)selector + 0x20);
    *(unsigned char *)((char *)selector + 0x28) = 1;
    *index = (*index + 1) % *(s32 *)((char *)selector + 0x1C);
}

/* Return 1 when the selector's +0x20 index is above zero (it can step back). */
s32 fn_8023AD2C(void *selector) {
    return *(s32 *)*(s32 **)((char *)selector + 0x20) > 0;
}

/* Return 1 when the selector's +0x20 index can advance (is below count - 1). */
s32 fn_8023AD44(void *selector) {
    return *(s32 *)*(s32 **)((char *)selector + 0x20) < (*(s32 *)((char *)selector + 0x1C) - 1);
}

/* Return the value in the selector's +0x18 table at its current +0x20 index. */
s32 fn_8023AD6C(void *selector) {
    return ((s32 *)*(char **)((char *)selector + 0x18))[*(s32 *)*(s32 **)((char *)selector + 0x20)];
}

/* Step the selector's +0x18 cyclic index one place backward, wrapping around. */
void fn_8023AD84(void *selector) {
    s32 count = *(s32 *)((char *)selector + 0x14);
    s32 *index = *(s32 **)((char *)selector + 0x18);
    *index = (count + *index - 1) % count;
}

/* Step the selector's +0x18 cyclic index one place forward, wrapping around. */
void fn_8023ADAC(void *selector) {
    s32 *index = *(s32 **)((char *)selector + 0x18);
    s32 count = *(s32 *)((char *)selector + 0x14);
    *index = (*index + 1) % count;
}

/* Return 1 when the selector's +0x18 index is above zero (it can step back). */
s32 fn_8023ADD0(void *selector) {
    return *(s32 *)*(s32 **)((char *)selector + 0x18) > 0;
}

/* Return 1 when the selector's +0x18 index can advance (is below count - 1). */
s32 fn_8023ADE8(void *selector) {
    return *(s32 *)*(s32 **)((char *)selector + 0x18) < (*(s32 *)((char *)selector + 0x14) - 1);
}

/* Return the value in the selector's +0x10 table at its current +0x18 index. */
s32 fn_8023AE10(void *selector) {
    return ((s32 *)*(char **)((char *)selector + 0x10))[*(s32 *)(*(char **)((char *)selector + 0x18))];
}

/* Step the selector's +0x1C index back by one, wrapping to count-1 when it reaches zero. */
void fn_8023AE28(void *selector) {
    s32 count = *(s32 *)((char *)selector + 0x14);
    s32 *index = *(s32 **)((char *)selector + 0x1C);
    *index = (count + *index - 1) % count;
}

void fn_8023AE50(void *selector) {
    /* Advance the selector's +0x1C index by one, wrapping back to 0 when it reaches count (+0x14). */
    s32 *index = *(s32 **)((char *)selector + 0x1C);
    s32 count = *(s32 *)((char *)selector + 0x14);
    *index = (*index + 1) % count;
}

/* Return 1 when the selector's +0x1C index is above zero (it can step back). */
s32 fn_8023AE74(void *selector) {
    return *(s32 *)*(s32 **)((char *)selector + 0x1C) > 0;
}

/* Return whether the selector's current index (offset 0x1C) can be advanced: it is below count (offset 0x14) minus one. */
s32 fn_8023AE8C(void *selector) {
    return *(s32 *)*(s32 **)((char *)selector + 0x1C) < (*(s32 *)((char *)selector + 0x14) - 1);
}

/* Return the value in the selector's +0x10 table at its current +0x1C index. */
s32 fn_8023AEB4(void *selector) {
    return ((s32 *)*(char **)((char *)selector + 0x10))[*(s32 *)(*(char **)((char *)selector + 0x1C))];
}

/* Set the selector's item count (offset 0x14). */
void fn_8023AECC(void *selector, s32 count) {
    (*(s32 *)((char *)selector + 0x14)) = count;
}

/* Set the selector's current index (held through its +0x1C pointer) to index. */
void fn_8023AED4(void *selector, s32 index) {
    *(s32 *)(*(char **)((char *)selector + 0x1C)) = index;
}

/* Return the selector's current index (held through its +0x1C pointer). */
s32 fn_8023AEE0(void *selector) {
    return *(s32 *)(*(char **)((char *)selector + 0x1C));
}

/* Clear the selector's +0x18 table/index pointer to the invalid -1 sentinel (no selection). */
void fn_8023AEEC(void *selector) {
    *(s32 *)((char *)selector + 0x18) = -1;
}

s32 fn_80230E90(s32);
/* If the current mode (fn_80214D04) being 4 differs from the stored flag, updates the flag and sets state at offset 0x1C accordingly. */
void fn_8023AEF8(void *obj) {
    unsigned int temp_r31;

    temp_r31 = fn_80214D04() == 4;
    if (*((unsigned char *)obj + 0x20) != temp_r31) {
        fn_80230E90(0);
        if (temp_r31 != 0) {
            *(s32 *)((char *)obj + 0x1C) = 1;
        } else {
            *(s32 *)((char *)obj + 0x1C) = 0;
        }
        *((unsigned char *)obj + 0x20) = temp_r31;
    }
}

s32 fn_8023AF6C(void *context, s32 command) {
    /* Handles command 0xD by triggering an event action when context flag at
       offset 0x20 is set and fn_802399DC(0) allows it; returns 1 if handled. */
    switch (command) {
    case 0xD:
        if (*(unsigned char *)((char *)context + 0x20) == 0)
            goto zero_a;
        if (fn_802399DC(0) == 0)
            goto zero_a;
        fn_802168BC(6);
        goto success;
    default:
        goto zero_b;
    }
zero_a:
    return 0;
zero_b:
    return 0;
success:
    return 1;
}

#pragma push
#pragma scheduling invalid_target
/* Draws this options-menu row's erase-data caption: looks up the localized
 * string "UIOptions:ERASEDATA" by name and draws it with the text renderer
 * (style 0xCB) at the row's rectangle, with page index +0x1C. */
void fn_8023AFD0(void *widget) {
    s32 param5;
    s32 height;
    s32 y;
    s32 x;
    s32 labelText;
    void *row = widget;

    param5 = *(s32 *)((char *)row + 0x10);
    height = *(s32 *)((char *)row + 0xC);
    y = *(s32 *)((char *)row + 8);
    x = *(s32 *)((char *)row + 4);
    labelText = fn_80131234(&lbl_8034127C[0]);
    fn_8022BAD0(0xCB, x, y, 0, height, param5, labelText, *(s32 *)((char *)row + 0x1C), 0, 1.0f);
}
#pragma pop

/* Empty no-op handler in the options-menu UI code; intentionally does nothing. */
void fn_8023B04C(void) {}

void fn_8023B050(void) {
    /* No-op hook slot: returns immediately without touching any register. */
}

#pragma push
#pragma cplusplus on
extern "C" s32 fn_80214D04(void);
/* Updates this object's mode flag from the current device state unless the global handler reports busy. */
extern "C" void fn_8023B054(void *obj) {
    struct Dummy {
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 f4();
        virtual s32 f5();
        virtual s32 f6();
        virtual s32 f7();
        virtual s32 f8();
        virtual s32 f9();
        virtual s32 f10();
        virtual s32 f11();
        virtual s32 f12();
        virtual s32 f13();
        virtual s32 f14();
        virtual s32 f15();
        virtual s32 f16();
        virtual s32 f17();
        virtual s32 f18();
        virtual s32 f19();
        virtual s32 f20();
        virtual s32 f21();
        virtual s32 f22();
    };
    if (((Dummy *)lbl_8055F10C)->f22() == 0) {
        switch (fn_80214D04()) {
        case 1:
            *(s32 *)((char *)obj + 0x18) = 1;
            break;
        default:
            *(s32 *)((char *)obj + 0x18) = 0;
            break;
        }
    }
}
#pragma cplusplus reset
#pragma pop
extern s32 lbl_80341268[];
#pragma pop
extern float lbl_80563730;
extern s32 fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, s32, float);
#pragma push
#pragma scheduling invalid_target
/* Draws the localized "UIOptions:SFXVOLUME" option label using the widget's layout fields (+0x04..+0x10) and selection state (+0x18). */
void fn_8023B0BC(void *widget) {
    s32 param5;
    s32 height;
    s32 y;
    s32 x;
    s32 labelText;
    void *p = widget;

    param5 = *(s32 *)((char *)p + 0x10);
    height = *(s32 *)((char *)p + 0xC);
    y = *(s32 *)((char *)p + 8);
    x = *(s32 *)((char *)p + 4);
    labelText = fn_80131234(&lbl_80341268[0]);
    fn_8022BAD0(0xC9, x, y, 0, height, param5, labelText, *(s32 *)((char *)p + 0x18), 0, 1.0f);
}
#pragma pop

#pragma push
#pragma cplusplus on
extern "C" s32 fn_80214D04(void);
extern "C" void UIOptions_SetEnabledForMenuState0(void *widget) {
    /* Set this option row's enabled flag from menu state 0, unless the erase-data widget is active. */
    struct EraseDataWidget {
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 f4();
        virtual s32 f5();
        virtual s32 f6();
        virtual s32 f7();
        virtual s32 f8();
        virtual s32 f9();
        virtual s32 f10();
        virtual s32 f11();
        virtual s32 f12();
        virtual s32 f13();
        virtual s32 f14();
        virtual s32 f15();
        virtual s32 f16();
        virtual s32 f17();
        virtual s32 f18();
        virtual s32 f19();
        virtual s32 f20();
        virtual s32 f21();
        virtual s32 isActive();
    };
    if (((EraseDataWidget *)lbl_8055F10C)->isActive() == 0) {
        switch (fn_80214D04()) {
        case 0:
            *(s32 *)((char *)widget + 0x18) = 1;
            break;
        default:
            *(s32 *)((char *)widget + 0x18) = 0;
            break;
        }
    }
}
#pragma cplusplus reset
#pragma pop

#pragma push
#pragma small_data off
extern s32 lbl_80341250[];
#pragma push
#pragma scheduling invalid_target
/* Draws the localized "UIOptions:MUSICVOLUME" option label using the widget's layout fields (+0x04..+0x10) and selection state (+0x18). */
void fn_8023B1A0(void *widget) {
    s32 param5;
    s32 height;
    s32 y;
    s32 x;
    s32 labelText;
    void *p = widget;

    param5 = *(s32 *)((char *)p + 0x10);
    height = *(s32 *)((char *)p + 0xC);
    y = *(s32 *)((char *)p + 8);
    x = *(s32 *)((char *)p + 4);
    labelText = fn_80131234(&lbl_80341250[0]);
    fn_8022BAD0(0xC9, x, y, 0, height, param5, labelText, *(s32 *)((char *)p + 0x18), 0, 1.0f);
}
#pragma pop

/* Empty no-op callback in the UI options code; performs no action when invoked. */
void fn_8023B21C(void) {
}

#pragma scheduling invalid_target
#pragma dont_inline on
/* If fn_802399AC() is nonzero or this object's flag at +0x1C is set, disable UI slot 6; otherwise enable it. */
void fn_8023B220(void *object) {
    if ((fn_802399AC() != 0) || (*(unsigned char *)((char *)object + 0x1C) != 0)) {
        fn_80214B94(6);
        fn_80214AF0(6);
        return;
    }
    fn_80214B44(6);
    fn_80214A9C(6);
}
#pragma scheduling on
#pragma push
#pragma cplusplus on
/* If the global UI/controller object reports mode 22 inactive, set this widget's
   enabled flag from the current menu state (active only in state 3). */
extern "C" void fn_8023B284(void *widget) {
    struct Dummy {
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 f4();
        virtual s32 f5();
        virtual s32 f6();
        virtual s32 f7();
        virtual s32 f8();
        virtual s32 f9();
        virtual s32 f10();
        virtual s32 f11();
        virtual s32 f12();
        virtual s32 f13();
        virtual s32 f14();
        virtual s32 f15();
        virtual s32 f16();
        virtual s32 f17();
        virtual s32 f18();
        virtual s32 f19();
        virtual s32 f20();
        virtual s32 f21();
        virtual s32 f22();
    };
    if (((Dummy *)lbl_8055F10C)->f22() == 0) {
        switch (fn_80214D04()) {
        case 3:
            *(s32 *)((char *)widget + 0x18) = 1;
            break;
        default:
            *(s32 *)((char *)widget + 0x18) = 0;
            break;
        }
    }
}
#pragma cplusplus reset
#pragma pop

#pragma push
#pragma small_data off
extern s32 lbl_80341240[];
#pragma push
#pragma scheduling invalid_target
/* Draws the localized "UIOptions:ICONS" option label using the widget's layout fields (+0x04..+0x10) and selection state (+0x18). */
void fn_8023B2EC(void *widget) {
    s32 param5;
    s32 height;
    s32 y;
    s32 x;
    s32 labelText;
    void *p = widget;

    param5 = *(s32 *)((char *)p + 0x10);
    height = *(s32 *)((char *)p + 0xC);
    y = *(s32 *)((char *)p + 8);
    x = *(s32 *)((char *)p + 4);
    labelText = fn_80131234(&lbl_80341240[0]);
    fn_8022BAD0(0xC9, x, y, 0, height, param5, labelText, *(s32 *)((char *)p + 0x18), 0, 1.0f);
}
#pragma pop

/* No-op virtual method: an empty slot in the UI option widget's dispatch table. */
void fn_8023B368(void) {}

/* Constant predicate (returns 0 / false); likely a virtual getter reached through a dispatch table. */
s32 fn_8023B36C(void) { return 0; }

#pragma push
#pragma cplusplus on
extern "C" void fn_8023B374(void *widget) {
    class Base { public: char pad[0xC]; };
    class Obj : public Base {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void setA(s32);
        virtual void setB(s32);
    };
    void **widgetFields = (void **)widget;
    s32 trackMusicMode = fn_80210570();

    /* Sync the race-music option child (+0x1C) with the current track-music mode:
       select state 3 for custom track mode (2), otherwise 2, and store the mode. */
    if (trackMusicMode == 2) {
        ((Obj *)widgetFields[7])->setA(3);
    } else {
        ((Obj *)widgetFields[7])->setA(2);
    }
    ((Obj *)widgetFields[7])->setB(trackMusicMode);
}
#pragma cplusplus reset
#pragma pop

/* No-op default virtual method (compiles to a bare return), paired with the
   constant-false getter fn_8023B404 in the same dispatch table. */
void fn_8023B400(void) {}

/* Constant predicate (returns 0 / false); a default virtual getter reached
 * through a dispatch table. */
s32 fn_8023B404(void) { return 0; }

#pragma cplusplus on
/* Update the race-music option state, toggling the related UI control and syncing the selected track when availability changes. */
extern "C" void fn_8023B40C(void *widget) {
    class Base { public: char pad[0xC]; };
    class Obj : public Base {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void setA(s32);
        virtual void setB(s32);
    };
    s32 musicState;
    void *optionObject;
    s32 selectedTrack;
    musicState = fn_802104D0();
    if ((unsigned int)musicState == 1) {
        fn_80214B94(3);
    } else {
        optionObject = *(void **)((char *)widget + 0x1C);
        ((Obj *)optionObject)->setB(0);
        if (fn_80214D04() == 2) fn_80214CB4((void *)1);
        fn_80214B44(3);
    }
    if (musicState == 0) {
        *(s32 *)((char *)widget + 0x18) = 4;
    } else {
        switch (fn_80214D04()) {
        case 2:
            *(s32 *)((char *)widget + 0x18) = 1;
            break;
        default:
            *(s32 *)((char *)widget + 0x18) = 0;
            break;
        }
    }
    if (*(unsigned char *)((char *)widget + 0x20) != (unsigned int)musicState && musicState != 0) {
        selectedTrack = fn_80210570();
        optionObject = *(void **)((char *)widget + 0x1C);
        ((Obj *)optionObject)->setB(selectedTrack);
    }
    *(unsigned char *)((char *)widget + 0x20) = musicState;
}
#pragma cplusplus reset
extern s32 lbl_80341228[];
#pragma pop
#pragma push
#pragma scheduling invalid_target
/* Draws the localized "UIOptions:RACE_MUSIC" option label using the widget's layout fields (+0x04..+0x10) and selection state (+0x18). */
void fn_8023B4F8(void *widget) {
    s32 param5;
    s32 height;
    s32 y;
    s32 x;
    s32 labelText;
    void *p = widget;

    param5 = *(s32 *)((char *)p + 0x10);
    height = *(s32 *)((char *)p + 0xC);
    y = *(s32 *)((char *)p + 8);
    x = *(s32 *)((char *)p + 4);
    labelText = fn_80131234(&lbl_80341228[0]);
    fn_8022BAD0(0xC9, x, y, 0, height, param5, labelText, *(s32 *)((char *)p + 0x18), 0, 1.0f);
}
#pragma pop

void fn_8023B574(void *option) {
    /* Show or hide UI group 29 depending on this option's status byte at +0x18. */
    if (*(unsigned char *)((char *)option + 0x18) != 0) {
        fn_80214AF0(0x1D);
    } else {
        fn_80214A9C(0x1D);
    }
}

