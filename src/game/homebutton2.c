// homebutton2 — home button channel 2 resources ("homeButton2/%s").
// Recovered TU window 0x802EC4BC..0x802ECCDC (see docs/attribution_analysis.md).
// Static-init thunk fn_802ECCDC (+ .ctors slot 0x802ED628) remains in
// auto/text_802ECCDC_.c pending a promotion pass.
#include "types.h"
#include "revolution/OS/OSFastCast.h"
#include "revolution/SC/scapi.h"

extern char lbl_805600E8;
extern u8 lbl_805600E9;
extern s8 lbl_805600EA;
extern u8 lbl_805600EB;
extern u8 lbl_805600ED;
/* The renderer of src/game/gx.c and src/game/drgc_surf.c, used by the handover
 * loop below to keep the screen covered while the Home Menu starts up. */
s32 fn_8002173C(void);                      /* runs a pending sound request; 1 when it did work */
void fn_802CFCA0(void);                     /* opens a frame: resets the GX state, sets the FIFO break point */
void fn_802D02F8(s32 color, s32 on);        /* fade colour (aRGB) and whether to fade with it */
void drawFifoTriangles(s32, s32, s32, s32);       /* indexed triangles straight into the GX FIFO */
void fn_802CFDE0(void);                     /* draws the home-button UI, flushes the FIFO and waits for the GPU */
void fn_802CFF10(void);                     /* closes the frame: clears the FIFO state */
void fn_80127464(void);
  extern s32 fn_802E9A0C(void);
  extern char lbl_80558860[];
  extern char lbl_8034E9E0[];
  extern void *jumptable_8034EA80[];
  void fn_801345D8(void *, s32, void *, s32);
  s32 fn_802E36D8(void *);
  void fn_802E317C(void *, void *);
  s32 fn_802E37C4(s32);
  void fn_801282EC(s32);
  s32 fn_8012850C(s32, void *);
  void fn_802E3804(s32, s32, s32);
  void fn_802E3734(s32 *);
/* Returns true when the console's configured aspect ratio is widescreen (16:9). */
s32 fn_802EC4BC(void) {
    return fn_802E9A0C() == SC_ASPECT_WIDE;
}
  
#pragma scheduling invalid_target
#pragma dont_inline on
s32 fn_802EC4E8(s32 arg0) {
    struct HomeStr { char s[0x40]; };
    char sp10[0x40];
    char *base = lbl_8034E9E0;
    s32 sp8;
    s32 temp_r30;
    s32 temp_r31;
    ((void (*)(void *, s32, void *, ...))fn_801345D8)(sp10, 0x40, ((struct HomeStr *)lbl_8034E9E0)->s, arg0);
    sp8 = fn_802E36D8(sp10);
    if (sp8 == -1)
        ((void (*)(void *, ...))fn_802E317C)(base + 0x10, sp10);
    temp_r30 = fn_802E37C4(sp8);
    fn_801282EC(0x20);
    temp_r31 = fn_8012850C(temp_r30, base + 0x28);
    fn_802E3804(sp8, temp_r31, temp_r30);
    fn_802E3734(&sp8);
    return temp_r31;
}
#pragma dont_inline reset
extern s32 lbl_80558898[];
extern s32 lbl_805600E0, lbl_805600E4;
extern u8 lbl_805600EC;
extern u8 lbl_8055D2F0;
extern f32 lbl_805651E0, lbl_805651E4, lbl_805651E8, lbl_805651EC;
extern u8 SCGetLanguage(void);
extern void fn_801282F4(void);
extern void fn_800C64F4(void *);
extern void *memset(void *, int, unsigned int);
#pragma scheduling on
  extern char lbl_80558860[];
  extern char lbl_8034E9E0[];
  extern void *jumptable_8034EA80[];
extern void fn_801345D8(void *, s32, void *, s32);
extern s32 fn_802E36D8(void *);
extern void fn_802E317C(void *, void *);
extern s32 fn_802E37C4(s32);
extern void fn_801282EC(s32);
extern s32 fn_8012850C(s32, void *);
extern void fn_802E3804(s32, s32, s32);
extern void fn_802E3734(s32 *);
#pragma scheduling invalid_target
#pragma dont_inline on
/* Returns the per-language homeBtn_*.arc filename from the homebutton2 string table for the language index at lbl_80558860+0x1C, resetting out-of-range values to 0 (Japanese). */
void *fn_802EC598(void) {
#define gHomeBtn2Resources lbl_80558860
#define gHomeBtn2Strings lbl_8034E9E0
    s32 language = *(s32 *)(gHomeBtn2Resources + 0x1c);
    char *strBase = gHomeBtn2Strings;
    switch (language) {
    default:
        *(s32 *)(gHomeBtn2Resources + 0x1c) = 0;
    case 0: return strBase + 0x34; /* "homeBtn.arc" */
    case 1: return strBase + 0x40; /* "homeBtn_ENG.arc" */
    case 2: return strBase + 0x50; /* "homeBtn_GER.arc" */
    case 3: return strBase + 0x60; /* "homeBtn_FRA.arc" */
    case 4: return strBase + 0x70; /* "homeBtn_SPA.arc" */
    case 5: return strBase + 0x80; /* "homeBtn_ITA.arc" */
    case 6: return strBase + 0x90; /* "homeBtn_NED.arc" */
    }
#undef gHomeBtn2Strings
#undef gHomeBtn2Resources
}
#pragma dont_inline off

#pragma scheduling invalid_target
void fn_802EC614(void) {
    // Home-button channel 2 start-up: clear the menu mode/request flags, init the
    // fast-cast table, seed the WPAD info config, fill the HomeBtn2Resources block
    // (per-language homeBtn_*.arc + three files, a 0x80000-byte archive buffer and
    // the console language), load the 0x19000-byte home-button UI, hand the block to
    // the home-button driver and raise the ready flag.
#define gHomeBtn2Strings   lbl_8034E9E0
#define gHomeBtn2Resources lbl_80558860
#define gWpadInfo          lbl_80558898
#define gHomeBtn2UiBuffer  lbl_805600E0
#define gHomeBtn2UiRes     lbl_805600E4
#define gHomeBtn2Ready     lbl_805600EC
#define gHomeMenuMode      lbl_805600E9
#define gHomeMenuRequest   lbl_805600EA
    char *const strBase = gHomeBtn2Strings;
    s32 zero = 0;
    s32 *wpadInfo;
    char *res;
    void *buffer;
    char *p100 = strBase + 0x100;
    char *p110 = strBase + 0x110;
    char *p11C = strBase + 0x11C;
    char *p128 = strBase + 0x128;
    char *p134 = strBase + 0x134;

    gHomeMenuMode = zero;
    gHomeMenuRequest = zero;
    OSInitFastCast();

    wpadInfo = gWpadInfo;
    wpadInfo[3] = zero;
    ((f32 *)wpadInfo)[1] = lbl_805651E0;
    ((f32 *)wpadInfo)[2] = lbl_805651E0;
    ((f32 *)wpadInfo)[5] = lbl_805651E0;
    ((f32 *)wpadInfo)[6] = lbl_805651E0;
    wpadInfo[7] = zero;
    ((f32 *)wpadInfo)[9] = lbl_805651E0;
    ((f32 *)wpadInfo)[10] = lbl_805651E0;
    wpadInfo[11] = zero;
    ((f32 *)wpadInfo)[13] = lbl_805651E0;
    ((f32 *)wpadInfo)[14] = lbl_805651E0;
    wpadInfo[15] = zero;
    fn_801282EC(0x20);

    res = gHomeBtn2Resources;
    buffer = (void *)fn_8012850C(0x80000, (void *)&lbl_8055D2F0);
    *(void **)(res + 0x10) = buffer;
    memset(buffer, 0, 0x80000);
    *(s32 *)(res + 0x24) = 0x80000;
    *(s32 *)(res + 0x1C) = SCGetLanguage();
    *(s32 *)(res + 0x00) = fn_802EC4E8((s32)fn_802EC598());
    *(s32 *)(res + 0x04) = fn_802EC4E8((s32)p100);
    *(s32 *)(res + 0x08) = fn_802EC4E8((s32)p110);
    *(s32 *)(res + 0x0C) = fn_802EC4E8((s32)p11C);
    *(s32 *)(res + 0x14) = zero;
    *(s32 *)(res + 0x18) = zero;
    *(s32 *)(res + 0x20) = zero;
    ((f32 *)res)[0x2C / 4] = lbl_805651E4;
    ((f32 *)res)[0x30 / 4] = lbl_805651E8;
    ((f32 *)res)[0x28 / 4] = lbl_805651EC;
    fn_801282EC(0x20);
    fn_801282F4();

    buffer = (void *)fn_8012850C(0x19000, p128);
    gHomeBtn2UiBuffer = (s32)buffer;
    memset(buffer, zero, 0x19000);
    gHomeBtn2UiRes = fn_802EC4E8((s32)p134);
    fn_800C64F4(res);
    gHomeBtn2Ready = 1;
#undef gHomeBtn2Strings
#undef gHomeBtn2Resources
#undef gWpadInfo
#undef gHomeBtn2UiBuffer
#undef gHomeBtn2UiRes
#undef gHomeBtn2Ready
#undef gHomeMenuMode
#undef gHomeMenuRequest
}
#pragma scheduling on
extern void fn_800C657C(void);
extern void fn_80128670(s32);
extern char lbl_8034EB28[];
extern char lbl_805588D8[];
extern s32 lbl_805600E0;
extern s32 lbl_805600E4;
extern u8 lbl_805600EC;
extern s32 lbl_80558898[];
extern f32 lbl_805651E0, lbl_805651E4, lbl_805651E8, lbl_805651EC;
extern u8 SCGetLanguage(void);
extern void fn_801282F4(void);
extern void fn_800C64F4(void *);
extern void *memset(void *, int, unsigned int);

/* Home-button channel 2's resource block at lbl_80558860: fn_802EC614() fills it
 * in at start-up and fn_802EC7AC() releases it at shutdown.  The handles are
 * what fn_802EC4E8() returns for the names after this file's string block. */
struct HomeBtn2Resources {
    s32 homeBtnArc;   /* 0x00: the per-language homeBtn_*.arc file */
    s32 file04;       /* 0x04: file opened from base + 0x100 */
    s32 file08;       /* 0x08: file opened from base + 0x110 */
    s32 file0C;       /* 0x0C: file opened from base + 0x11C */
    void *archive;    /* 0x10: 0x80000-byte buffer the archive loads into */
    s32 field14;      /* 0x14 */
    s32 field18;      /* 0x18 */
    s32 language;     /* 0x1C: SCGetLanguage() */
    s32 field20;      /* 0x20 */
    s32 archiveSize;  /* 0x24: 0x80000 */
};

/* The home-button callbacks registered by the game (lbl_805588D8); a slot still
 * set when the kernel shuts the module down is fatal. */
#define HOMEBTN2_CALLBACK_COUNT 8
#define HOMEBTN2_UNREMOVED_MSG (lbl_8034EB28) /* "homebtn: callback %p never removed" */

#pragma scheduling invalid_target
/* Home-button channel 2 shutdown, the mirror of fn_802EC614(): clears the
 * "ready" flag, tears down the home-button driver's heap, panics on every
 * callback the game left registered, then frees the archive buffer, the four
 * opened files and the two home-button UI resources. */
void fn_802EC7AC(void) {
    s32 *callback;
    s32 i;
    struct HomeBtn2Resources *res;

    lbl_805600EC = 0;
    fn_800C657C();

    callback = (s32 *)lbl_805588D8;
    i = 0;
    do {
        if (*callback != 0)
            ((void (*)(void *, ...))fn_802E317C)(HOMEBTN2_UNREMOVED_MSG, (void *)*callback);
        ++i;
        ++callback;
    } while (i < HOMEBTN2_CALLBACK_COUNT);

    res = (struct HomeBtn2Resources *)&lbl_80558860;
    fn_80128670((s32)res->archive);
    fn_80128670(*(s32 *)lbl_80558860);
    if (*(s32 *)(lbl_80558860 + 4) != 0)
        fn_80128670(*(s32 *)(lbl_80558860 + 4));
    fn_80128670(*(s32 *)(lbl_80558860 + 8));
    fn_80128670(*(s32 *)(lbl_80558860 + 12));
    if (lbl_805600E0 != 0)
        fn_80128670(lbl_805600E0);
    if (lbl_805600E4 != 0)
        fn_80128670(lbl_805600E4);
}
#pragma scheduling on
#pragma small_data on
extern char lbl_8055D2F8;
#pragma small_data off
extern void WPADControlMotor(s32, s32);
extern void fn_800C65C4(void);
extern s32 fn_800C65CC(void *);
extern s32 fn_800C673C(void);
extern s32 fn_800C6768(void);
extern void fn_800C675C(void);
extern void fn_800C6774(s32, s32, s32);
extern void fn_800C687C(void);
extern void fn_800C68B0(void);
extern s32 fn_802D9BF0(void);
extern void fn_802E2C20(void);
extern void KERNEL_Reset(s32);
extern void fn_802E30C8(const char *, ...);
extern void fn_802E5438(void);
extern void fn_802E7C40(void);
extern s32 fn_802E8668(s32);
extern void fn_802E99AC(void);
extern s32 lbl_80558898[];
/* Update Home Menu/WPAD shutdown flow: on a request, stop motors, initialize
 * home-button state, then poll/advance until completion and log status. */
void fn_802EC884(void) {
    register char *menuStrings = lbl_8034E9E0;
    const char *statusText;
    char *logFormat;
    register s32 *wpadInfoOut;
    register u32 isNormalBoot;
    s32 channel;
    s32 i;

    if ((u8)lbl_805600EC == 0) return;
    if ((u8)lbl_805600EA != 0) {
        lbl_805600EA = 0;
        if (fn_802D9BF0() == 0) {
            logFormat = menuStrings + 0x16C;
            statusText = &lbl_8055D2F8;
            isNormalBoot = (u32)__cntlzw((u32)lbl_805600E9);
            isNormalBoot >>= 5;
            lbl_805600EB = isNormalBoot;
            if (isNormalBoot != 0) statusText = menuStrings + 0x198;
            fn_802E30C8(logFormat, statusText);
            lbl_805600E8 = 1;
            for (channel = 0; channel < 4; channel++) WPADControlMotor(channel, 0);
            fn_800C6774(lbl_805600E4, lbl_805600E0, 0x19000);
            fn_800C65C4();
            fn_802EC4BC();
            fn_800C675C();
        }
    }
    fn_802E2C20();
    if ((u8)lbl_805600E8 == 0) return;
    wpadInfoOut = lbl_80558898;
    for (i = 0; i < 4; i++) {
        *wpadInfoOut = fn_802E8668(i);
        wpadInfoOut += 4;
    }
    if (fn_800C65CC(lbl_80558898) >= 0) {
        fn_802E99AC();
        fn_802E7C40();
        fn_802E5438();
        fn_802E30C8(menuStrings + 0x1A4);
        fn_802E30C8(menuStrings + 0x1C0, fn_800C673C());
        fn_802E30C8(menuStrings + 0x1D0, fn_800C6768());
        switch (fn_800C673C()) {
        case 1:
            fn_802E30C8(menuStrings + 0x1E0);
            KERNEL_Reset(1);
            break;
        case 2:
            fn_802E30C8(menuStrings + 0x200);
            KERNEL_Reset(0);
            break;
        }
        fn_800C687C();
        *(volatile u8 *)&lbl_805600E8 = 0;
    }
    if (*(volatile u8 *)&lbl_805600E8 != 0) fn_800C68B0();
}

extern void *fn_802D2D14(void);
extern void GXClearVtxDesc(void);
extern void GXSetVtxAttrFmt(int, int, int, int, int);
extern void GXSetVtxDesc(int, int);
extern void GXSetViewport(float, float, float, float, float, float);
extern void GXSetScissor(unsigned int, unsigned int, unsigned int, unsigned int);
extern void GXSetNumChans(int);
extern void GXSetNumTexGens(int);
extern void GXSetNumTevStages(int);
extern void GXSetTevOrder(int, int, int, int);
extern void GXSetTevOp(int, int);
extern void GXSetBlendMode(int, int, int, int);
extern void GXSetZMode(int, int, int);
extern void GXSetCurrentMtx(int);
extern void C_MTXOrtho(void *, float, float, float, float, float, float);
extern void GXSetProjection(void *, int);
extern void fn_800C6610(void);
extern void fn_802D3360(void);
extern s32 fn_802EC4BC(void);
extern float lbl_805651E0, lbl_805651E8, lbl_805651F0, lbl_805651F4;
extern float lbl_805651F8, lbl_805651FC, lbl_80565200, lbl_80565204, lbl_80565208;
#pragma dont_inline on
/* Set up GX state and orthographic projection for home-button/menu rendering
 * when active: configures viewport/scissor, TEV/Z/blend, chooses ortho bounds
 * based on layout mode, then draws/flushes the home-button UI.
 */
void fn_802ECA48(void) {
    u8 projection[0x40];
    u16 *dims;
    float scale;
    if ((u8)lbl_805600E8 != 0) {
        GXClearVtxDesc();
        GXSetVtxAttrFmt(4, 9, 0, 4, 0);
        GXSetVtxAttrFmt(4, 0xB, 0, 1, 0);
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xB, 1);
        dims = fn_802D2D14();
        scale = lbl_805651E0;
        GXSetViewport(scale, scale, (float)dims[2], (float)dims[3], scale, lbl_805651E8);
        GXSetScissor(0, 0, dims[2], dims[3]);
        GXSetNumChans(1);
        GXSetNumTexGens(0);
        GXSetNumTevStages(1);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        GXSetTevOp(0, 4);
        GXSetBlendMode(0, 0, 0, 0);
        GXSetZMode(1, 3, 1);
        GXSetCurrentMtx(3);
        if (fn_802EC4BC() != 0)
            C_MTXOrtho(projection, lbl_805651F0, lbl_805651F4, lbl_805651F8, lbl_805651FC, lbl_805651E0, lbl_80565200);
        else
            C_MTXOrtho(projection, lbl_805651F0, lbl_805651F4, lbl_80565204, lbl_80565208, lbl_805651E0, lbl_80565200);
        GXSetProjection(projection, 1);
        if ((u8)lbl_805600E8 != 0) fn_800C6610();
        fn_802D3360();
    }
}
#pragma dont_inline off
void fn_802ECBF8(void) {
#define gHomeMenuActive lbl_805600E8
#define gHomeMenuRequest lbl_805600EA
    /* Request the home-button menu: raise the pending-request flag only when the
     * menu isn't already active (the per-frame process loop honours it later). */
    if ((u8)gHomeMenuActive == 0) {
        gHomeMenuRequest = 1;
    }
#undef gHomeMenuRequest
#undef gHomeMenuActive
}

char fn_802ECC10(void) {
    /* Returns lbl_805600E8 (gHomeMenuActive), the flag raised by fn_802EC884
     * while the Wii Home menu is open; callers use it to suppress gameplay and
     * input handling. */
    return lbl_805600E8;
}

void fn_802ECC18(u8 mode) {
#define gHomeMenuMode lbl_805600E9
    /* Set the home-menu mode flag; zero selects the normal shutdown message. */
    gHomeMenuMode = mode;
#undef gHomeMenuMode
}

#pragma dont_inline on
/* One frame of the black screen this module paints while the home-button
 * handover runs (fn_802ECC74 repeats it until the Home Menu takes the screen
 * over), skipped on the frames fn_8002173C() spent on a pending sound request:
 * fn_802CFCA0() opens the frame, fn_802D02F8() switches on the fade colour the
 * screen is covered with -- opaque black -- drawFifoTriangles() is asked for no
 * triangles at all (only its renderer setup runs), fn_802CFDE0() draws the
 * home-button UI and flushes the FIFO to the GPU, and fn_802CFF10() closes the
 * frame again. */
void fn_802ECC20(void) {
#define FADE_BLACK 0xFF000000 /* aRGB: opaque black */
    if (fn_8002173C() == 0) {
        fn_802CFCA0();
        fn_802D02F8(FADE_BLACK, 1);
        drawFifoTriangles(0, 0, 0, 0);
        fn_802CFDE0();
        fn_802CFF10();
    }
#undef FADE_BLACK
}
void fn_802ECC74(void) {
    /* Drain home button2 work while requested: guard against reentry, then loop/process until inactive. */
    u8 wasRequested;

    if (lbl_805600ED != 0) {
        return;
    }
    wasRequested = lbl_805600EB;
    lbl_805600ED = 1;
    if (wasRequested != 0) {
        while ((u8)lbl_805600E8 != 0) {
            fn_802ECC20();
            fn_80127464();
        }
        fn_802ECC20();
        lbl_805600EB = 0;
    }
    lbl_805600ED = 0;
}

#pragma dont_inline off
