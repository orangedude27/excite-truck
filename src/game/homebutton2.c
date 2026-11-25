// homebutton2 — home button channel 2 resources ("homeButton2/%s").
// Recovered TU window 0x802EC4BC..0x802ECCDC (see docs/attribution_analysis.md).
// Static-init thunk fn_802ECCDC (+ .ctors slot 0x802ED628) remains in
// auto/text_802ECCDC_.c pending a promotion pass.
#include "types.h"
#include "revolution/OS/OSFastCast.h"
#include "revolution/SC/scapi.h"
#include "revolution/GX/GXTypes.h"
#include "revolution/MTX/mtxtypes.h"

extern char lbl_805600E8;
extern u8 lbl_805600E9;
extern s8 lbl_805600EA;
extern u8 lbl_805600EB;
extern u8 lbl_805600ED;
/* The renderer of src/game/gx.c and src/game/drgc_surf.c, used by the handover
 * loop below to keep the screen covered while the Home Menu starts up. */
s32 soundRunPendingRequest(void);                      /* runs a pending sound request; 1 when it did work */
void HomeMenu_beginFrame(void);                     /* opens a frame: resets the GX state, sets the FIFO break point */
void HomeMenu_setFade(s32 color, s32 on);        /* fade colour (aRGB) and whether to fade with it */
void drawFifoTriangles(s32, s32, s32, s32);       /* indexed triangles straight into the GX FIFO */
void HomeMenu_drawUIAndFlush(void);                     /* draws the home-button UI, flushes the FIFO and waits for the GPU */
void HomeMenu_endFrame(void);                     /* closes the frame: clears the FIFO state */
void fn_80127464(void);
  extern s32 ConfigGetAspectRatio(void);
  extern char lbl_80558860[];
  extern char lbl_8034E9E0[];
  extern void *jumptable_8034EA80[];
  void fn_801345D8(void *, s32, void *, s32);
  s32 FileLookup(void *);
  void Abend_Panic(void *, void *);
  s32 fn_802E37C4(s32);
  void fn_801282EC(s32);
  s32 fn_8012850C(s32, void *);
  void fn_802E3804(s32, s32, s32);
  void fn_802E3734(s32 *);
/* Return true when the console's configured aspect ratio is 16:9 (widescreen). */
s32 HomeMenu_isWidescreen(void) {
    return ConfigGetAspectRatio() == SC_ASPECT_WIDE;
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
    sp8 = FileLookup(sp10);
    if (sp8 == -1)
        ((void (*)(void *, ...))Abend_Panic)(base + 0x10, sp10);
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
extern s32 FileLookup(void *);
extern void Abend_Panic(void *, void *);
extern s32 fn_802E37C4(s32);
extern void fn_801282EC(s32);
extern s32 fn_8012850C(s32, void *);
extern void fn_802E3804(s32, s32, s32);
extern void fn_802E3734(s32 *);
#pragma scheduling invalid_target
#pragma dont_inline on
/* Returns the per-language homeBtn_*.arc filename from the homebutton2 string table for the language index at lbl_80558860+0x1C, resetting out-of-range values to 0 (Japanese). */
/* Return the localized homeBtn_*.arc filename for the console language, resetting out-of-range values to Japanese. */ void *getHomeBtnArchiveName(void) {
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
/* Initializes home-button channel 2: clears the menu flags, sets up fast casts and WPAD info, loads the language archive and UI resources, then marks the module ready. */ void fn_802EC614(void) {
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
    char *resources;
    void *buffer;
    char *file04Path = strBase + 0x100;
    char *file08Path = strBase + 0x110;
    char *file0CPath = strBase + 0x11C;
    char *uiBufferName = strBase + 0x128;
    char *uiResPath = strBase + 0x134;

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

    resources = gHomeBtn2Resources;
    buffer = (void *)fn_8012850C(0x80000, (void *)&lbl_8055D2F0);
    *(void **)(resources + 0x10) = buffer;
    memset(buffer, 0, 0x80000);
    *(s32 *)(resources + 0x24) = 0x80000;
    *(s32 *)(resources + 0x1C) = SCGetLanguage();
    *(s32 *)(resources + 0x00) = fn_802EC4E8((s32)getHomeBtnArchiveName());
    *(s32 *)(resources + 0x04) = fn_802EC4E8((s32)file04Path);
    *(s32 *)(resources + 0x08) = fn_802EC4E8((s32)file08Path);
    *(s32 *)(resources + 0x0C) = fn_802EC4E8((s32)file0CPath);
    *(s32 *)(resources + 0x14) = zero;
    *(s32 *)(resources + 0x18) = zero;
    *(s32 *)(resources + 0x20) = zero;
    ((f32 *)resources)[0x2C / 4] = lbl_805651E4;
    ((f32 *)resources)[0x30 / 4] = lbl_805651E8;
    ((f32 *)resources)[0x28 / 4] = lbl_805651EC;
    fn_801282EC(0x20);
    fn_801282F4();

    buffer = (void *)fn_8012850C(0x19000, uiBufferName);
    gHomeBtn2UiBuffer = (s32)buffer;
    memset(buffer, zero, 0x19000);
    gHomeBtn2UiRes = fn_802EC4E8((s32)uiResPath);
    fn_800C64F4(resources);
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
#define gHomeBtn2Resources lbl_80558860
#define gHomeBtn2Callbacks lbl_805588D8
#define gHomeBtn2UiBuffer  lbl_805600E0
#define gHomeBtn2UiRes     lbl_805600E4
#define gHomeBtn2Ready     lbl_805600EC
    s32 *callback;
    s32 i;
    struct HomeBtn2Resources *res;

    gHomeBtn2Ready = 0;
    fn_800C657C();

    callback = (s32 *)gHomeBtn2Callbacks;
    i = 0;
    do {
        if (*callback != 0)
            ((void (*)(void *, ...))Abend_Panic)(HOMEBTN2_UNREMOVED_MSG, (void *)*callback);
        ++i;
        ++callback;
    } while (i < HOMEBTN2_CALLBACK_COUNT);

    res = (struct HomeBtn2Resources *)&gHomeBtn2Resources;
    fn_80128670((s32)res->archive);
    fn_80128670(*(s32 *)gHomeBtn2Resources);
    if (*(s32 *)(gHomeBtn2Resources + 4) != 0)
        fn_80128670(*(s32 *)(gHomeBtn2Resources + 4));
    fn_80128670(*(s32 *)(gHomeBtn2Resources + 8));
    fn_80128670(*(s32 *)(gHomeBtn2Resources + 12));
    if (gHomeBtn2UiBuffer != 0)
        fn_80128670(gHomeBtn2UiBuffer);
    if (gHomeBtn2UiRes != 0)
        fn_80128670(gHomeBtn2UiRes);
#undef gHomeBtn2Resources
#undef gHomeBtn2Callbacks
#undef gHomeBtn2UiBuffer
#undef gHomeBtn2UiRes
#undef gHomeBtn2Ready
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
extern void KERNEL_GetTimeMs(void);
extern void KERNEL_Reset(s32);
extern void fn_802E30C8(const char *, ...);
extern void fn_802E5438(void);
extern void fn_802E7C40(void);
extern s32 fn_802E8668(s32);
extern void ConfigCacheWpadSettings(void);
extern s32 lbl_80558898[];
/* Drive the Home menu / Wii Remote shutdown flow. When a Home-menu request
 * arrives, stop all rumble and snapshot the menu state; then gather WPAD info
 * and, once the menu reports completion, log the result and reset the console. */
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
            HomeMenu_isWidescreen();
            fn_800C675C();
        }
    }
    KERNEL_GetTimeMs();
    if ((u8)lbl_805600E8 == 0) return;
    wpadInfoOut = lbl_80558898;
    for (i = 0; i < 4; i++) {
        *wpadInfoOut = fn_802E8668(i);
        wpadInfoOut += 4;
    }
    if (fn_800C65CC(lbl_80558898) >= 0) {
        ConfigCacheWpadSettings();
        fn_802E7C40();
        fn_802E5438();
        fn_802E30C8(menuStrings + 0x1A4);
        fn_802E30C8(menuStrings + 0x1C0, fn_800C673C());
        fn_802E30C8(menuStrings + 0x1D0, fn_800C6768());
        switch (fn_800C673C()) {
        case 1:
            fn_802E30C8(menuStrings + 0x1E0);
            fn_802E2E38(1);
            break;
        case 2:
            fn_802E30C8(menuStrings + 0x200);
            fn_802E2E38(0);
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
extern s32 HomeMenu_isWidescreen(void);
extern float lbl_805651E0, lbl_805651E8, lbl_805651F0, lbl_805651F4;
extern float lbl_805651F8, lbl_805651FC, lbl_80565200, lbl_80565204, lbl_80565208;
#pragma dont_inline on
/* When the Home menu is active, configure GX for a 2D overlay: viewport and
 * scissor from the current render dims, simple TEV/Z/blend state, and an
 * orthographic projection whose width follows the console aspect ratio (16:9
 * or 4:3); then draw the home-button UI quad and re-initialize GX state. */
void fn_802ECA48(void) {
#define gHomeMenuActive lbl_805600E8
#define gViewportOrigin lbl_805651E0
#define gViewportFar lbl_805651E8
#define gOrthoTop lbl_805651F0
#define gOrthoBottom lbl_805651F4
#define gOrthoLeftWide lbl_805651F8
#define gOrthoRightWide lbl_805651FC
#define gOrthoLeft4x3 lbl_80565204
#define gOrthoRight4x3 lbl_80565208
#define gOrthoNear lbl_805651E0
#define gOrthoFar lbl_80565200
    u8 projection[0x40];
    u16 *renderDims;
    float viewportOrigin;
    if ((u8)gHomeMenuActive != 0) {
        GXClearVtxDesc();
        GXSetVtxAttrFmt(4, 9, 0, 4, 0);
        GXSetVtxAttrFmt(4, 0xB, 0, 1, 0);
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xB, 1);
        renderDims = fn_802D2D14();
        viewportOrigin = gViewportOrigin;
        GXSetViewport(viewportOrigin, viewportOrigin, (float)renderDims[2], (float)renderDims[3], viewportOrigin, gViewportFar);
        GXSetScissor(0, 0, renderDims[2], renderDims[3]);
        GXSetNumChans(1);
        GXSetNumTexGens(0);
        GXSetNumTevStages(1);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        GXSetTevOp(0, 4);
        GXSetBlendMode(0, 0, 0, 0);
        GXSetZMode(1, 3, 1);
        GXSetCurrentMtx(3);
        if (HomeMenu_isWidescreen() != 0)
            C_MTXOrtho(projection, gOrthoTop, gOrthoBottom, gOrthoLeftWide, gOrthoRightWide, gOrthoNear, gOrthoFar);
        else
            C_MTXOrtho(projection, gOrthoTop, gOrthoBottom, gOrthoLeft4x3, gOrthoRight4x3, gOrthoNear, gOrthoFar);
        GXSetProjection(projection, 1);
        if ((u8)gHomeMenuActive != 0) fn_800C6610();
        fn_802D3360();
    }
#undef gOrthoFar
#undef gOrthoNear
#undef gOrthoRight4x3
#undef gOrthoLeft4x3
#undef gOrthoRightWide
#undef gOrthoLeftWide
#undef gOrthoBottom
#undef gOrthoTop
#undef gViewportFar
#undef gViewportOrigin
#undef gHomeMenuActive
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
/* Paint one frame of the black screen shown while the Home Menu handover runs
 * (HomeMenu_drainHandover repeats it), skipping frames spent on a pending sound
 * request: open the frame, fade the screen to opaque black, submit no triangles,
 * draw the home-button UI and flush the FIFO, then close the frame. */
void HomeMenu_drawBlackFrame(void) {
#define FADE_BLACK 0xFF000000 /* aRGB: opaque black */
    if (soundRunPendingRequest() == 0) {
        HomeMenu_beginFrame();
        HomeMenu_setFade(FADE_BLACK, 1);
        drawFifoTriangles(0, 0, 0, 0);
        HomeMenu_drawUIAndFlush();
        HomeMenu_endFrame();
    }
#undef FADE_BLACK
}
/* Drain the Home-button handover: when one was requested, paint a black frame
 * and service the periodic callback each frame while the Home Menu is active,
 * then paint one final frame and clear the request. A guard prevents reentry. */
void HomeMenu_drainHandover(void) {
#define gHomeMenuActive lbl_805600E8
#define gHandoverRequested lbl_805600EB
#define gHandoverRunning lbl_805600ED
    u8 wasRequested;

    if (gHandoverRunning != 0) {
        return;
    }
    wasRequested = gHandoverRequested;
    gHandoverRunning = 1;
    if (wasRequested != 0) {
        while ((u8)gHomeMenuActive != 0) {
            HomeMenu_drawBlackFrame();
            fn_80127464();
        }
        HomeMenu_drawBlackFrame();
        gHandoverRequested = 0;
    }
    gHandoverRunning = 0;
#undef gHandoverRunning
#undef gHandoverRequested
#undef gHomeMenuActive
}

#pragma dont_inline off
