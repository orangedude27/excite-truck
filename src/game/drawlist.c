// drawlist — draw lists (DrawListWrapper::pool, mrDrawList).
// Recovered TU window 0x802C82C0..0x802CA0A4+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CA0A4 (+ .ctors slot 0x802ED5A8) remains in
// auto/text_802CA0A4_.c pending a promotion pass.
#include <revolution/MTX/mtxtypes.h>
extern char lbl_8055FC34;
extern int sDrawlistCallbackId;
extern int lbl_8055D02C;
extern float lbl_80564F04;
extern float lbl_80564F08;
extern void fn_802C5F48(float, int, float *, float, float);
extern void LoadIntOptionValue(int, void *, int *);
extern int fn_8013365C(int, int);
extern int fn_802C9C58(int);
extern void fn_802C974C(float, float, float);
extern float lbl_8055FC6C;
extern void fn_802D362C(int);
extern void gxResetDefaultState(void);
extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
extern void DrawList_setViewport(int, int, int, int);
/* Fixed-size object pool (constructed by fn_8012A13C/fn_8012A17C, popped by
 * fn_8012A2D8, pushed back by fn_8012A364): `count` elements of `stride`
 * bytes carved out of one block and threaded into a free list at +0x10. */
struct ObjectPool {
    void *vtbl;           /* 0x00 */
    char warnWhenEmpty;   /* 0x04 warn when the pool runs dry */
    char ownsBlock;       /* 0x05 */
    const char *name;     /* 0x08 pool name, used by the out-of-memory message */
    void *block;          /* 0x0C */
    void *free;           /* 0x10 free list head */
    int stride;           /* 0x14 element size */
    int count;            /* 0x18 capacity */
    int live;             /* 0x1C elements handed out */
};                        /* 0x20 bytes */

#define DRAWLIST_POOL_CAPACITY  0x10 /* DrawListWrappers the pool holds */
#define DRAWLIST_WRAPPER_SIZE   0x18 /* bytes per DrawListWrapper */

/* DrawListWrapper: the pooled ("mrDrawList") object.  It owns the GenericDrawList
 * built by fn_801E7840 and carries the orientation fn_802C9E94 blends in from
 * frame to frame plus the number of frames blended so far. */
struct DrawListWrapper {
    void *drawList;  /* 0x00 GenericDrawList this wrapper draws through */
    float x;         /* 0x04 accumulated orientation */
    float y;         /* 0x08 */
    float z;         /* 0x0C */
    float w;         /* 0x10 */
    int count;       /* 0x14 frames blended into the orientation */
};                 /* 0x18 bytes */

#define STR_DRAWLIST_POOL   lbl_8034B514 /* "DrawListWrapper::pool" */
#define STR_MR_DRAWLIST     lbl_8034B52C /* "mrDrawList" */
#define sDrawListPool       lbl_8055FC9C /* the ObjectPool of DrawListWrappers */
#define sDrawListLiveCount  lbl_8055FC98 /* DrawListWrappers handed out */

#define NamedAlloc  fn_801284F8 /* void *(int size, const char *name) */
#define Pool_Init   fn_8012A13C /* (void *pool, const char *name, int count, int stride) */
#define Pool_Alloc  fn_8012A2D8 /* void *(void *pool): pop one element */
#define Pool_Free   fn_8012A364 /* (void *pool, void *element): push one back */

/* Which GX render state the draw lists are drawing in.  Only 0 is read back
 * (DrawList_isOutsideScene asks whether the module is shut down); the other values record
 * the state the function that set them left GX in: 1 the game's normal one
 * (DrawList_RestoreNormalMode puts it back), 2 the one texSelectSlot/endMeshPass set up,
 * 3 DrawList_BeginProjection's with the world matrix saved, 4 the alpha-only overlay pass
 * fn_802C9C8C begins, 6 the pass beginDrawListPass begins. */
#define sRenderMode  lbl_8055FC70
#define sOverlayTint lbl_8055FC84 /* colour fn_802C9CE0 blends the screen back with */
extern void fn_802C8C04(int);

#define RENDER_MODE_ALPHA_OVERLAY 4 /* GX writes alpha only, see fn_802C9C8C */
#define RENDER_MODE_NORMAL 1        /* the game's normal GX state */

extern int lbl_8055FC98;
extern void *lbl_8055FC9C;
extern char lbl_8034B514[];
extern void *fn_801284F8(int, const char *);
extern void *fn_8012A13C(void *, const char *, int, int);
extern void *fn_8012A2D8(void *);
extern int lbl_8055CFF4;
extern float lbl_80564F18;
extern double lbl_80564F10;
extern void fn_802D01E0(int, int, int);
extern float lbl_8055FC4C;
extern float lbl_8055FC40;
extern float lbl_8055D020;
extern int lbl_8055FC30;
extern int lbl_8055FC84;
extern void gxApplyCullMode(void);
extern void Texture_InvalidateLastBoundSlot(void);
extern int fn_802D31D8(int);
extern void fn_801E7888(int);
extern unsigned int lbl_804C1410[];
extern unsigned int sSavedDrawListMatrix[];
extern char sDrawListMatrixSaved;
struct DlMtx34 { unsigned int w[12]; };
extern float lbl_80564EF8, lbl_80564F00;
extern void fn_802C7758(int);
extern void fn_802C89E8(float *);
extern void DrawList_loadMatrix(unsigned int *);
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);

extern char lbl_8055FC94;
__declspec(section ".sdata") extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;

extern int lbl_8055FC70;
extern void HomeMenu_drawUIAndFlush(void);
extern void fn_802CC770(void);
extern void fn_802CC60C(void);
extern void HomeMenu_beginFrame(void);
extern int gCurrentModelColor;
extern void fn_802CFFAC(unsigned char, unsigned char, unsigned char);
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[3];
extern unsigned char gDrawListActive;
extern int fn_801E4F3C(void);
extern int beginMeshPass(void);
extern void drawFifoTriangles(void);

extern int lbl_8055FC70;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern char lbl_8055FC8C;
extern char lbl_8055FC8D;
extern float lbl_8055D024;
extern float lbl_80564EFC;
char lbl_8034B498[] = "display_type";
static char lbl_8034B4A8[] = "mr: normal mode";
static char lbl_8034B4B8[] = "mr: widescreen mode";
static char lbl_8034B4CC[] = "mr: letterbox mode";
extern int fn_80019B9C(void);
extern int ConfigGetAspectRatio(void);
extern void fn_80133348(int, const char *, int);
extern void *lbl_8055FC90;
/* No-op callback registered under the name "mr" in the drawlist callback table;
 * it does nothing when invoked and is only present to occupy that slot. */
void fn_802C82C0(void) {
}

#pragma cplusplus on
extern "C" int fn_80133010(void);
extern "C" void fn_802C82C4(int requestedMode) {
#define DISPLAY_TYPE_KEY lbl_8034B498
#define LOG_NORMAL_MODE  lbl_8034B4A8
#define LOG_WIDESCREEN_MODE lbl_8034B4B8
#define LOG_LETTERBOX_MODE  lbl_8034B4CC
#define sDisplayType    lbl_8055FC90
#define sWidescreenMode lbl_8055FC8C
#define sLetterboxMode  lbl_8055FC8D
#define sScaleX         lbl_8055D020
#define sScaleY         lbl_8055D024
#define SCALE_NORMAL    lbl_80564EF8
#define SCALE_WIDE      lbl_80564EFC
#define DISPLAY_MODE_NORMAL     0
#define DISPLAY_MODE_WIDESCREEN 1
#define DISPLAY_MODE_LETTERBOX  2
    /* Set the mr renderer display mode (0 normal, 1 widescreen, 2 letterbox),
     * forcing widescreen when the locale requires it or the console is set to
     * 16:9, store it in the "display_type" option, and update the mode flags,
     * the screen scale factors and the log message. */
    int mode = requestedMode;
    if (fn_80019B9C() != 0 || ConfigGetAspectRatio() == DISPLAY_MODE_WIDESCREEN) mode = DISPLAY_MODE_WIDESCREEN;
    sDisplayType = (void *)mode;
    if (fn_80133010() != 0) fn_80133348(1, DISPLAY_TYPE_KEY, (int)sDisplayType);
    sWidescreenMode = 0;
    sScaleX = SCALE_NORMAL;
    sScaleY = SCALE_NORMAL;
    sLetterboxMode = 0;
    switch (mode) {
    case DISPLAY_MODE_NORMAL:
        fn_802E30C8(LOG_NORMAL_MODE);
        break;
    case DISPLAY_MODE_WIDESCREEN:
        fn_802E30C8(LOG_WIDESCREEN_MODE);
        sWidescreenMode = 1;
        sScaleX = SCALE_WIDE;
        break;
    case DISPLAY_MODE_LETTERBOX:
        fn_802E30C8(LOG_LETTERBOX_MODE);
        sLetterboxMode = 1;
        sScaleX = SCALE_WIDE;
        sScaleY = SCALE_WIDE;
        break;
    }
#undef DISPLAY_MODE_LETTERBOX
#undef DISPLAY_MODE_WIDESCREEN
#undef DISPLAY_MODE_NORMAL
#undef SCALE_WIDE
#undef SCALE_NORMAL
#undef sScaleY
#undef sScaleX
#undef sLetterboxMode
#undef sWidescreenMode
#undef sDisplayType
#undef LOG_LETTERBOX_MODE
#undef LOG_WIDESCREEN_MODE
#undef LOG_NORMAL_MODE
#undef DISPLAY_TYPE_KEY
}
#pragma cplusplus reset
/* Get the "display_type" setting (0 normal, 1 widescreen, 2 letterbox). */
void* fn_802C83C4(void) {
    return lbl_8055FC90;
}

#pragma scheduling invalid_target
void fn_802C83CC(void) {
    int ten = 10;
    float temp_f1 = (float)ten;
    float *dst = (float *)lbl_804C1410;
    *dst++ = lbl_80564EF8;
    *dst++ = lbl_80564F00;
    *dst++ = lbl_80564F00;
    *dst++ = lbl_80564F00;
    *dst++ = lbl_80564EF8;
    *dst++ = lbl_80564F00;
    *dst++ = lbl_80564F00;
    *dst++ = lbl_80564F00;
    *dst++ = lbl_80564EF8;
    *dst++ = lbl_80564F00;
    *dst++ = lbl_80564F00;
    *dst++ = lbl_80564F00;
    lbl_8055FC5C = 0;
    lbl_8055FC60 = 0;
    lbl_8055FC64 = (void *)ten;
    lbl_8055FC68 = (void *)ten;
    lbl_8055FC6C = temp_f1 / (float)ten;
    fn_802C5F48(temp_f1, ten, (float *)lbl_804C1410, lbl_80564F00, lbl_80564EF8);
    lbl_8055FC34 = 0;
    fn_802C974C(lbl_80564EF8, lbl_80564F04, lbl_80564F08);
    lbl_8055FC70 = 0;
    fn_802CFFAC(0xC9, 0xC9, 0xEB);
    ((void (*)(void))fn_802C7758)();
    fn_802C82C4(0);
    fn_802C9C58(0);
    if (fn_80133010() != 0) {
        LoadIntOptionValue(1, lbl_8034B498, (int *)&lbl_8055FC90);
        sDrawlistCallbackId = fn_8013365C((int)&lbl_8055D02C, (int)fn_802C82C0);
    }
}
#pragma scheduling on
extern int fn_80133010(void);
extern void fn_801336E0(int, void (*)(void));
extern void fn_802C6080(void);
extern int sDrawlistCallbackId;
extern int fn_802C9E94(void *, int, int, float, float, float, float, float);
extern int fn_801E7894(int);
void DrawList_UnregisterCallbackAndShutdown(void) {
    /* Unregister the "mr" drawlist callback (fn_802C82C0) while the options table is active, invalidate its id, then shut down drawlists via fn_802C6080. */
    if (fn_80133010() != 0) {
        fn_801336E0(sDrawlistCallbackId, fn_802C82C0);
        sDrawlistCallbackId = -1;
    }
    fn_802C6080();
}

/* Prepare draw lists for a render frame: enter normal GX render mode, reset the 0x40 texture draw slots (fn_802CC60C) and register the GX draw-sync callback (HomeMenu_beginFrame); paired with the DrawList_shutdown teardown. */
/* Begins a draw-list frame: set the normal GX render mode, reset the texture draw slots, and register the GX draw-sync callback. */ void DrawList_beginFrame(void) {
    sRenderMode = RENDER_MODE_NORMAL;
    fn_802CC60C();
    HomeMenu_beginFrame();
}

/* Shuts down the draw-list module: flush the UI, release the texture list, and mark rendering stopped. */
void DrawList_shutdown(void) {
#define RENDER_MODE_SHUTDOWN 0
    HomeMenu_drawUIAndFlush();
    fn_802CC770();
    sRenderMode = RENDER_MODE_SHUTDOWN;
#undef RENDER_MODE_SHUTDOWN
}

extern void fn_802C7758(int);
extern unsigned int sSavedDrawListMatrix[];
extern char sDrawListMatrixSaved;
extern void fn_802C89E8(float *);
extern void DrawList_loadMatrix(unsigned int *);
extern float lbl_80564EF8, lbl_80564F00;
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
#pragma scheduling reset
void fn_802C8588(float *arg0, const float *arg1, const float *arg2) {
    register float dz, dy, dx;
    float z, y, x;
    float right, up;
    float sp[3];
    x = arg1[0];
    dx = arg2[0] - x;
    y = arg1[1];
    dy = arg2[1] - y;
    z = arg1[2];
    dz = arg2[2] - z;
    up = lbl_80564F00;
    right = lbl_80564EF8;
    sp[0] = up;
    sp[1] = right;
    sp[2] = up;
    arg0[9] = x;
    arg0[10] = y;
    arg0[11] = z;
    arg0[6] = dx;
    arg0[7] = dy;
    arg0[8] = dz;
    PSVECNormalize(arg0 + 6, arg0 + 6);
    PSVECCrossProduct(sp, arg0 + 6, arg0);
    PSVECNormalize(arg0, arg0);
    PSVECCrossProduct(arg0 + 6, arg0, arg0 + 3);
}
extern void fn_802D03F4(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
#pragma scheduling invalid_target
void DrawList_loadMatrix(unsigned int *arg0) {
    register unsigned int v3 = arg0[3];
    register unsigned int v2 = arg0[2];
    register unsigned int v1 = arg0[1];
    register unsigned int v0 = arg0[0];
    register unsigned int v11 = arg0[11];
    unsigned int v4 = arg0[4];
    unsigned int v5 = arg0[5];
    unsigned int v6 = arg0[6];
    unsigned int v7 = arg0[7];
    unsigned int v8 = arg0[8];
    unsigned int v9 = arg0[9];
    unsigned int v10 = arg0[10];
    volatile unsigned int *dst = (volatile unsigned int *)lbl_804C1410;
    dst[0] = v0; dst[1] = v1; dst[2] = v2; dst[3] = v3;
    dst[4] = v4; dst[5] = v5; dst[6] = v6; dst[7] = v7;
    dst[8] = v8; dst[9] = v9; dst[10] = v10; dst[11] = v11;
    fn_802D03F4((unsigned int *)dst, v10, v9, v8, v7, v6, v5, v4);
}
#pragma scheduling on
/* Return the buffer holding the current camera/view matrix (a 3x4 float matrix). */
/* Return a pointer to the current draw-list/view matrix buffer (12-word 3x4 at lbl_804C1410). */ void *DrawList_getCurrentMatrix(void) {
#define sCurrentMatrix lbl_804C1410
    return sCurrentMatrix;
#undef sCurrentMatrix
}

extern void *gSavedFadeColor;
/* Store the packed ARGB color (default 0xFF7F7F7F gray) later applied to GX state by HomeMenu_applySavedFade. */
void fn_802C86E8(void* color) {
    gSavedFadeColor = color;
}

void *DrawList_saveViewport(void *savedViewport, int x, int y, int width, int height) {
    /* Save the current viewport rectangle, then set a new one. */
    #define gViewportX      lbl_8055FC5C
    #define gViewportY      lbl_8055FC60
    #define gViewportWidth  lbl_8055FC64
    #define gViewportHeight lbl_8055FC68
    *(int *)((unsigned char *)savedViewport) = (int)gViewportX;
    *(int *)((unsigned char *)savedViewport + 4) = (int)gViewportY;
    *(int *)((unsigned char *)savedViewport + 8) = (int)gViewportWidth;
    *(int *)((unsigned char *)savedViewport + 0xC) = (int)gViewportHeight;
    DrawList_setViewport(x, y, width, height);
    #undef gViewportHeight
    #undef gViewportWidth
    #undef gViewportY
    #undef gViewportX
    return savedViewport;
}

extern void DrawList_setViewport(int, int, int, int);
extern void fn_80128668(void *);
/* Restore the viewport rectangle saved by DrawList_saveViewport (x, y, width, height at +0,+4,+8,+0xC); when freeBuffer is positive, also free the saved buffer. */
void *DrawList_restoreViewport(void *savedViewport, int freeBuffer) {
    if (savedViewport != 0) {
        DrawList_setViewport(*(int *)((unsigned char *)savedViewport), *(int *)((unsigned char *)savedViewport + 4), *(int *)((unsigned char *)savedViewport + 8), *(int *)((unsigned char *)savedViewport + 0xC));
        if (freeBuffer > 0) {
            fn_80128668(savedViewport);
        }
    }
    return savedViewport;
}

#pragma push
#pragma scheduling invalid_target
/* Sets the current viewport rectangle (and aspect), applying a vertical scale/offset adjustment when the relevant flags are set, then updates the projection and scissor state. */
void DrawList_setViewport(int x, int y, int width, int height) {
    /* Sets the current viewport rectangle (and aspect), applying a vertical scale/offset adjustment when the relevant flags are set, then updates the projection and scissor state. */
    #define gViewMode lbl_8055FC74
    #define sLetterboxMode lbl_8055FC8D
    #define sScaleY lbl_8055D024
    #define gRadPerDeg lbl_80564F18
    #define sReferenceHeight lbl_8055CFF4
    #define gViewportWidth lbl_8055FC64
    #define gViewportX lbl_8055FC5C
    #define gViewportY lbl_8055FC60
    #define gViewportHeight lbl_8055FC68
    #define gAspect lbl_8055FC6C
    #define gRightSlope lbl_8055FC44
    int half;
    int deltaY;
    unsigned int rounding;
    if ((unsigned char)gViewMode == 0 && (unsigned char)sLetterboxMode != 0) {
        rounding = (unsigned int)sReferenceHeight >> 31;
        rounding += (unsigned int)sReferenceHeight;
        half = (int)rounding >> 1;
        deltaY = y - half;
        y = half + (int)(gRadPerDeg + sScaleY * (float)deltaY);
        height = (int)(gRadPerDeg + (float)height * sScaleY);
    }
    gViewportWidth = (void *)width;
    gViewportX = (void *)x;
    gViewportY = (void *)y;
    gViewportHeight = (void *)height;
    gAspect = (float)width / (float)height;
    fn_802D01E0(x, y, width);
    fn_802CC518(width, gRightSlope);
}
#pragma pop

/* Apply the stored value (set by fn_802C86E8) via HomeMenu_setFade, passing flags' low bit as its byte argument. */
/* Apply the saved home-menu fade colour through HomeMenu_setFade, enabling the fade when the low bit of flags is set and disabling it otherwise. */
void HomeMenu_applySavedFade(int flags) {
    HomeMenu_setFade(gSavedFadeColor, flags & 1);
}

extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
/* Wrapper around the fade-colour setter HomeMenu_setFade: set the screen fade colour
 * to the packed aRGB value `color` and switch fading on. */
void fn_802C88CC(unsigned int color) {
    HomeMenu_setFade(color, 1);
}

extern unsigned int lbl_804C1410[];
extern void PSQUATMultiply(void *, unsigned int, void *);
extern void MRModelSetTransform(unsigned int);
extern void DrawList_setupMode2(void);
#pragma scheduling invalid_target
/* Return the distance from the camera position (the view-matrix translation at lbl_804C1410+0x24) to the packed point passed in `point`. */
void DrawList_distanceToCamera(unsigned int point) {
    PSQUATMultiply((void *)&lbl_804C1410[9], point, lbl_804C1410);
}

extern void PSVECSquareDistance(void *, unsigned int, void *);
/* Tail-call PSVECSquareDistance for the squared distance from the camera position (view matrix at lbl_804C1410+0x24) to point. */ void DrawList_squaredDistanceToCamera(unsigned int point) {
    /* Tail-call PSVECSquareDistance to measure squared distance from the cached Vec at lbl_804C1410+0x24 to *point (raw bit pointer). */
    PSVECSquareDistance((void *)&lbl_804C1410[9], point, lbl_804C1410);
}

#pragma scheduling reset
extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
extern double lbl_80564F10;
extern float lbl_80564F18, lbl_80564F1C;
#pragma scheduling on
void fn_802C88FC(float *arg0) {
    float value, fill, scale, divisor;
    float x, y, z;

    scale = lbl_80564F18;
    divisor = lbl_8055FC44;
    value = lbl_80564EF8;
    fill = lbl_80564F00;
    z = value / lbl_8055D020;
    x = (float)(unsigned int)lbl_8055FC64;
    y = scale * x / divisor;

    arg0[0] = value;
    arg0[1] = fill;
    arg0[2] = fill;
    arg0[3] = fill;
    arg0[5] = fill;
    arg0[4] = lbl_80564F1C;
    arg0[6] = fill;
    arg0[7] = fill;
    arg0[8] = value;
    arg0[11] = -(y * z);
    arg0[10] = (float)(unsigned int)lbl_8055FC60 + scale * (float)(unsigned int)lbl_8055FC68;
    arg0[9] = (float)(unsigned int)lbl_8055FC5C + scale * (float)(unsigned int)lbl_8055FC64;
}
void fn_802C89E8(float *arg0) {
    float var_f2;
    float var_f4;
    float fill;
    float scale;
    int height;
    int y;
    int width;
    int x;

    var_f2 = (lbl_80564F18 * (float)(int)lbl_8055FC64) / lbl_8055FC44;
    if ((unsigned char)lbl_8055FC74 == 0) {
        var_f2 *= lbl_80564EF8 / lbl_8055D020;
    }
    if ((unsigned char)lbl_8055FC74 != 0) {
        var_f4 = lbl_80564EF8;
    } else {
        var_f4 = lbl_80564EF8 / lbl_8055D020;
    }

    fill = lbl_80564F00;
    var_f2 = -var_f2;
    arg0[0] = var_f4;
    arg0[1] = fill;
    arg0[2] = fill;
    arg0[3] = fill;
    arg0[4] = lbl_80564F1C;
    arg0[5] = fill;
    arg0[6] = fill;
    arg0[7] = fill;
    arg0[8] = lbl_80564EF8;

    height = (int)lbl_8055FC68;
    y = (int)lbl_8055FC60;
    width = (int)lbl_8055FC64;
    x = (int)lbl_8055FC5C;
    scale = lbl_80564F18;
    arg0[10] = (float)y + scale * (float)height;
    arg0[11] = var_f2;
    arg0[9] = (float)x + scale * (float)width;
}
/* Copy the current draw-list matrix (the 12-word 3x4 at lbl_804C1410) into dst.
 * The four word-pairs plus a trailing scalar/pair/scalar split reproduces the
 * compiler's paired load/store schedule for the copy. */
void DrawList_copyCurrentMatrix(unsigned int *dst) {
#define sCurrentMatrix lbl_804C1410
    struct MtxPair { unsigned int first; unsigned int second; };
    struct MtxTail { unsigned int first; struct MtxPair pair; unsigned int last; };
    struct MtxPair *outPairs = (struct MtxPair *)dst;
    struct MtxPair *curPairs = (struct MtxPair *)sCurrentMatrix;
    struct MtxTail *outTail = (struct MtxTail *)((char *)dst + 0x20);
    struct MtxTail *curTail = (struct MtxTail *)((char *)sCurrentMatrix + 0x20);
    outPairs[0] = curPairs[0];
    outPairs[1] = curPairs[1];
    outPairs[2] = curPairs[2];
    outPairs[3] = curPairs[3];
    outTail->first = curTail->first;
    outTail->pair = curTail->pair;
    outTail->last = curTail->last;
#undef sCurrentMatrix
}

extern void texSelectSlot(void);
/* Mode-2 draw-list setup: bind the incoming texture slot (r3) through texSelectSlot, then record render mode 2. */
void DrawList_setupMode2(void) {
    texSelectSlot();
    sRenderMode = 2;
}

#pragma dont_inline on
/* RealName: DrawList_QueueApplyAndBeginMode2 */
/* Queue and apply the draw record at source as the current GX state, then run handle's mode-2 draw-list setup (select texture slot, set render mode 2). */ void fn_802C8B98(int handle, int source) {
    /* Queue the draw record at `source`, apply it as the current GX state, then run `handle`'s mode-2 draw-list setup. */
    MRModelSetTransform(source);
    ((void (*)(int))DrawList_setupMode2)(handle);
}
#pragma dont_inline reset
/* Reset the current GX material/vertex state to its default (fn_802C7758),
 * then run the mode-2 draw-list setup: select texture slot `texSlot` and set
 * the draw mode to 2. Like fn_802C8B98, but resets to the default instead of
 * applying a queued draw record first. */
/* RealName: DrawList_ResetAndBeginMode2. Resets GX material/vertex state to its default (fn_802C7758), then runs mode-2 draw-list setup on texSlot (select texture slot, set render mode 2). Like fn_802C8B98, but resets to the default instead of applying a queued draw record first. */ /* RealName: DrawList_ResetAndBeginMode2. Resets GX material/vertex state to its default (fn_802C7758), then runs mode-2 draw-list setup on texSlot (select texture slot, set render mode 2). Like fn_802C8B98, but resets to the default instead of applying a queued draw record first. */ void fn_802C8BD0(int texSlot) {
    fn_802C7758(texSlot);
    ((void (*)(int))DrawList_setupMode2)(texSlot);
}
#pragma dont_inline off

#pragma use_lmw_stmw off
/* Begin a 2D draw-list pass: back up the current draw-list matrix (lbl_804C1410)
 * into sSavedDrawListMatrix and flag the save as active, build an orthographic projection
 * matrix, load it as the current GX matrix, then reset material/vertex state while
 * selecting texture slot `texSlot`. */
void fn_802C8C04(int texSlot) {
    struct DlMtx34 *currentMtx = (struct DlMtx34 *)lbl_804C1410;
    struct DlMtx34 *savedMtx = (struct DlMtx34 *)sSavedDrawListMatrix;
    float orthoMtx[12];

    *savedMtx = *currentMtx;
    sDrawListMatrixSaved = 1;
    fn_802C89E8(orthoMtx);
    DrawList_loadMatrix((unsigned int *)orthoMtx);
    ((void (*)(int))fn_802C8BD0)(texSlot);
}

#pragma use_lmw_stmw off
/* Save the current draw-list matrix (lbl_804C1410) into the backup slot (sSavedDrawListMatrix) and flag that a save is active, then build a perspective projection matrix with fn_802C88FC, load it as the current GX matrix, and reset material/vertex state while selecting texture slot `texSlot`. */
/* Save the current draw-list matrix into its backup slot and flag the save, then build a perspective projection matrix, load it as the current GX matrix, and reset material/vertex state while selecting the given texture slot. */ void fn_802C8CBC(int texSlot) {
    struct DlMtx34 *currentMtx = (struct DlMtx34 *)lbl_804C1410;
    struct DlMtx34 *savedMtx = (struct DlMtx34 *)sSavedDrawListMatrix;
    float projMtx[12];

    *savedMtx = *currentMtx;
    sDrawListMatrixSaved = 1;
    fn_802C88FC(projMtx);
    DrawList_loadMatrix((unsigned int *)projMtx);
    ((void (*)(int))fn_802C8BD0)(texSlot);
}

#pragma dont_inline on
/* Return the draw lists to the game's normal GX state: if a matrix was saved
 * before an overlay pass, reload it, then clear the saved-matrix flag. */
void DrawList_RestoreNormalMode(void) {
    sRenderMode = RENDER_MODE_NORMAL;
    if ((unsigned char)sDrawListMatrixSaved != 0) {
        DrawList_loadMatrix(sSavedDrawListMatrix);
    }
    sDrawListMatrixSaved = 0;
}
#pragma dont_inline reset

void fn_802C8DB8(void) {
#define drawIndexedTriangles drawFifoTriangles
    /* Tail-forward the caller's vertex/index arguments (still in registers) to the
     * immediate-mode indexed triangle drawer. */
    drawIndexedTriangles();
#undef drawIndexedTriangles
}

/* Begin a deferred draw-list pass when the mesh pass is available: mark lists active, enter render mode 6, and report success. */
int beginDrawListPass(void) {
    if (beginMeshPass() != 0) {
        gDrawListActive = 1;
        sRenderMode = 6;
        return 1;
    }
    return 0;
}

/* Clear the deferred draw/command flag unless it was set and the active
 * command path reports no pending work. */
/* Keep the drawlist-active flag set only if it was already set and fn_801E4F3C reports no pending work; otherwise clear it. */ void fn_802C8E00(void) {
    unsigned char keepFlag = 0;
    if (gDrawListActive != 0 && fn_801E4F3C() == 0) {
        keepFlag = 1;
    }
    gDrawListActive = keepFlag;
}

extern void endMeshPass(void);
/* End the pending mesh pass -- endMeshPass flushes the mesh vertex/index buffers
 * and drops the mesh mode to idle -- and put the draw lists in render mode 2,
 * the GX state that mesh pass leaves behind. */
/* End the pending mesh pass (flush buffers, set mesh mode idle) and record render mode 2, the GX state the pass leaves behind. */ void DrawList_endMeshPass(void) {
    endMeshPass();
    sRenderMode = 2;
}

#pragma scheduling on
void fn_802C8E70(const float *arg0, float *arg1)
{
int __repair_literal;

  float *m = (float *) lbl_804C1410;
  float rx;
  float sy;
  float sx;
  float v1;
  float v2;
  float limit;
  float scale;
  float ry;
  float rz;
  float dz;
  float dy;
  float dx;
  float z;
  float y;
  float x;
  x = arg0[0]; y = arg0[1]; z = arg0[2];
  dx = x - m[9]; arg1[0] = dx;
  dy = y - (((-arg1[1]) * 0, m))[10]; arg1[1] = dy;
  dz = (0, z - m[11]); arg1[2] = dz;
__repair_literal = 0;

  rx = (m[2] * dz) + (rx = ((((float) (((int) lbl_8055FC5C) & 0xFF)) * __repair_literal, dy * m[1])) + (dx * m[0]));
  ry = (dz * m[5]) + (ry = (dx * ((0, m[3]))) + ((0, dy * m[4])));
  rz = (dz * m[8]) + (rz = (dy * m[7]) + (dx * m[6]));
  arg1[0] = rx; arg1[1] = ry; arg1[2] = rz;
  limit = (lbl_8055FC38 > rz) ? (lbl_8055FC38) : (rz);
  sy = (scale = lbl_80564EF8 / (lbl_8055FC44 * limit)) * (-arg1[1]); sx = scale * arg1[0];
  v1 = lbl_80564EF8 + sx; v2 = lbl_80564EF8 + (lbl_8055FC6C * sy);
  arg1[0] = ((float) (((int) lbl_8055FC5C) & 0xFF)) + ((lbl_80564F18 * ((float) ((int) lbl_8055FC64))) * v1);
  arg1[1] = ((lbl_80564F18 * ((float) ((int) lbl_8055FC68))) * v2) + ((float) ((int) lbl_8055FC60));
}
/* Returns the current viewport aspect ratio (width / height), cached in lbl_8055FC6C
   by viewport setup and used to scale projected vertical coordinates. */
float fn_802C8FEC(void) { return lbl_8055FC6C; }

extern char lbl_80558DC4[];
extern float lbl_8055FC38, lbl_8055FC3C;
#pragma scheduling off
int fn_802C8FF4(float *arg0, float arg1) {
    float x;
    float y;
    float z;
    int result = 0;

    z = arg0[2];
    if (z > lbl_8055FC38 + (*(float *)&lbl_80558DC4) &&
        z < lbl_8055FC3C - (*(float *)&lbl_80558DC4)) {
        x = arg0[0];
        if (x >= (float)(int)lbl_8055FC5C - arg1 &&
            x < arg1 + (float)((int)lbl_8055FC5C + (int)lbl_8055FC64)) {
            y = arg0[1];
            if (y >= (float)(int)lbl_8055FC60 - arg1 &&
                y < arg1 + (float)((int)lbl_8055FC60 + (int)lbl_8055FC68)) {
                result = 1;
            }
        }
    }
    return result;
}
#pragma scheduling on
int DrawList_isOutsideScene(void) {
    /* True when no draw-list render pass is active (the render-mode flag is 0). */
    return sRenderMode == 0;
}

/* Begin a 2D draw-list pass through fn_802C8C04 (saving the world matrix) and record render mode 3. */
void DrawList_setupMode3(void) {
    ((void (*)(void))fn_802C8C04)();
    sRenderMode = 3;
}

#pragma scheduling invalid_target
/* For a valid texture index (not -1/-2) raise the draw guard and record whether mode is 1 in the FOV flag; for an invalid index clear both. Then select the texture through selectTexture. */
void fn_802C9294(int textureIndex, int mode) {
#define gViewMode    lbl_8055FC74
#define gForceRecalc lbl_8055FC75
    /* Select a texture and set the view flags: a valid slot marks the view active
     * and forces a recalculation when mode is 1; an invalid slot clears both. */
    int forceRecalc;
    if (textureIndex != -1 && textureIndex != -2) {
        forceRecalc = mode == 1;
        gForceRecalc = forceRecalc;
        gViewMode = 1;
    } else {
        gViewMode = 0;
        gForceRecalc = 0;
    }
    selectTexture(textureIndex);
}
#pragma scheduling on
extern void fn_802C8C04(int);
extern void DrawList_RestoreNormalMode(void);
extern int lbl_8055FC70;
extern int selectTexture(void);
extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern void fn_802C92DC(int, int, int, int, int);
#pragma dont_inline on
/* Set up drawlist/GX state through DrawList_BeginProjection with mode -1. The surrounding
   dont_inline pragma keeps this wrapper a real call (a tail branch) rather than
   letting DrawList_BeginProjection be inlined. */
void fn_802C92D0(void) {
#pragma dont_inline off
    fn_802C8C04(-1);
}

/* Tail-call wrapper for DrawList_RestoreNormalMode: restores the
 * normal GX render mode and reapplies the saved matrix state if pending. */
void fn_802C92D8(void) {
    DrawList_RestoreNormalMode();
}

/* Draws an axis-aligned quad outline/strip on the given screen if beginMeshPass(4) succeeds. */
/* Draw an axis-aligned filled rectangle from (left,top) to (right,bottom) in color, wrapped in a temporary mode-1 mesh pass: begin the pass, append four vertices with a triangle strip, then flush. */ void fn_802C92DC(int left, int top, int right, int bottom, int color) {
    if (((int (*)(int))beginMeshPass)(4) != 0) {
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(color, 0, (float)right, (float)top, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(color, 0, (float)left, (float)top, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(color, 1, (float)right, (float)bottom, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(color, 1, (float)left, (float)bottom, 0.0f, 0.0f, 0.0f);
        endMeshPass();
    }
}

/* Finish a mode-3 overlay pass: record render mode 2 (the GX state the mesh draw leaves behind), then restore the normal draw-list mode and any saved matrix. */
void DrawList_endOverlayPass(void) {
    sRenderMode = 2;
    DrawList_RestoreNormalMode();
}

#pragma processor 750
/* Draw a screen-space textured quad: begin a mesh pass, emit the four corners as two triangles with the given UVs and packed RGBA `color`, then end the pass. */ void fn_802C9124(float u0, float v0, float u1, float v1, int left, int top, int right, int bottom, int color) {
    /* Submit a screen-space textured quad with the given UVs when the draw primitive can be started. */
    if (((int (*)(int))beginMeshPass)(4) != 0) {
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(color, 0, (float)right, (float)top, 0.0f, u1, v0);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(color, 0, (float)left, (float)top, 0.0f, u0, v0);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(color, 1, (float)right, (float)bottom, 0.0f, u1, v1);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(color, 1, (float)left, (float)bottom, 0.0f, u0, v1);
        endMeshPass();
    }
}
#pragma processor reset

#pragma dont_inline on
/* Draw a full-screen quad from (0,0) to the current screen width/height in the given color. */
void fn_802C942C(int color) {
#define screenWidth lbl_8055CFF0
#define screenHeight lbl_8055CFF4
    fn_802C92D0();
    fn_802C92DC(0, 0, screenWidth, screenHeight, color);
    fn_802C92D8();
#undef screenHeight
#undef screenWidth
}
#pragma dont_inline reset
/* Log a one-shot warning through the abend logger that mrFullscreenAdd is not supported; the flag suppresses repeats. */ void DrawList_warnFullscreenAddUnsupported(void) {
#define sFullscreenWarned lbl_8055FC94
#define sFormatString lbl_8055D030
#define sUnsupportedMessage lbl_8034B4E0
#define ReportOnce fn_802E30C8
    /* Report once that mrFullscreenAdd is unavailable; the one-shot flag keeps
       the message from being printed on every call. */
    if ((unsigned char)sFullscreenWarned != 0) return;
    sFullscreenWarned = 1;
    ReportOnce((const char *)sFormatString, sUnsupportedMessage);
#undef sFullscreenWarned
#undef sFormatString
#undef sUnsupportedMessage
#undef ReportOnce
}

extern float PSVECDotProduct(const Vec *, const Vec *);
extern float __fabsf(float);
extern float lbl_80564F20, lbl_8055FC50, lbl_8055FC54, lbl_8055FC58;
#pragma scheduling invalid_target
/* Test whether a 3D point lies inside the current view volume, optionally reporting a status byte and the point's view-space depth. */
int fn_802C94A0(const float *position, unsigned char *status, float *depth, float tolerance) {
#define gViewMatrix        lbl_804C1410
#define gNearClip          lbl_8055FC38
#define gFarClip           lbl_8055FC3C
#define gRightSlope        lbl_8055FC44
#define gUpSlope           lbl_8055FC50
#define gRightSlack        lbl_8055FC54
#define gUpSlack           lbl_8055FC58
#define gFarMarginFactor   lbl_80564F20
#define gZeroFloat         lbl_80564F00
    float *matrix;
    Vec delta;
    float dx;
    float dy;
    float dz;
    float viewDepth;
    float absRight;
    float absUp;
    float scaledLimit;
    float rightLimit;
    float upLimit;

    if (status != 0) {
        *status = 1;
    }

    matrix = (float *)gViewMatrix;
    dx = position[0] - matrix[9];
    dy = position[1] - matrix[10];
    dz = position[2] - matrix[11];
    delta.x = dx;
    delta.y = dy;
    delta.z = dz;

    viewDepth = PSVECDotProduct(&delta, (Vec *)(matrix + 6));
    if ((viewDepth < gNearClip - tolerance) || (viewDepth > gFarClip + tolerance)) {
        return 0;
    }
    if (viewDepth - tolerance > gFarClip - gFarMarginFactor * gFarClip) {
        return 0;
    }

    absRight = (float)__fabs((double)PSVECDotProduct(&delta, (Vec *)matrix));
    scaledLimit = viewDepth * gRightSlope;
    rightLimit = gZeroFloat;
    rightLimit = (rightLimit > scaledLimit) ? rightLimit : scaledLimit;
    if (absRight > rightLimit + tolerance * gRightSlack) {
        return 0;
    }

    absUp = (float)__fabs((double)PSVECDotProduct(&delta, (Vec *)((float *)gViewMatrix + 3)));
    scaledLimit = viewDepth * gUpSlope;
    upLimit = gZeroFloat;
    upLimit = (upLimit > scaledLimit) ? upLimit : scaledLimit;
    if (absUp > upLimit + tolerance * gUpSlack) {
        return 0;
    }

    if (depth != 0) {
        *depth = viewDepth - tolerance;
    }
    return 1;
#undef gZeroFloat
#undef gFarMarginFactor
#undef gUpSlack
#undef gRightSlack
#undef gUpSlope
#undef gRightSlope
#undef gFarClip
#undef gNearClip
#undef gViewMatrix
}
#pragma scheduling on
/* View-volume containment test for a position: calls the full checker without
 * a distance output, still updating the caller's status byte. */
int fn_802C9638(void *position, unsigned char *status, float tolerance) {
    return fn_802C94A0(position, status, 0, tolerance);
}

#pragma dont_inline on
int fn_802C9640(void *position, float tolerance) {
    /* View-volume containment test for a position, discarding both the status
       byte and the distance output. */
    return fn_802C9638(position, 0, tolerance);
}
#pragma dont_inline off
extern int fn_802C9638(void *, unsigned char *, float);
extern void fn_802C974C(float, float, float);
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[];
extern float lbl_80564F24, lbl_80564F28, lbl_8055FC88;
extern float lbl_8055FC50, lbl_8055FC54, lbl_8055FC58;
extern double fn_8002EF30(double);
extern double atan(double);
extern double sin(double);
extern double cos(double);
extern void fn_802D0368(float, float, float, float);
#pragma scheduling invalid_target
void fn_802C9648(float scale) {
#define gViewBackup lbl_804C144C
#define gNearClip   lbl_8055FC38
#define gFarClip    lbl_8055FC3C
    /* Scale the current near/far clip planes by a factor, back up the originals
       in the view backup triple, then reapply the projection. */
    float newNear;
    float newFar;
    float oldNear;
    float oldFar;
    oldNear = gNearClip;
    oldFar = gFarClip;
    newNear = oldNear * scale;
    newFar = oldFar * scale;
    gViewBackup[0] = oldNear;
    gViewBackup[1] = oldFar;
    gNearClip = newNear;
    gFarClip = newFar;
    fn_802C974C(newNear, newFar, gViewBackup[2]);
#undef gFarClip
#undef gNearClip
#undef gViewBackup
}
#pragma scheduling on
/* Restores the backed-up view/projection parameters by reapplying the saved
 * triple in lbl_804C144C[0..2] through fn_802C974C. */
void DrawList_reapplyProjection(void) {
    /* Reapply the backed-up near/far/FOV triple to refresh the derived view/projection values. */
    fn_802C974C(lbl_804C144C[0], lbl_804C144C[1], lbl_804C144C[2]);
}

/* Save the current near/far planes and field of view into the 3-float vector
 * at out, then apply the caller's new values through fn_802C974C. */
void *DrawList_saveProjection(void *out) {
#define gNearClip lbl_8055FC38
#define gFarClip  lbl_8055FC3C
#define gFov      lbl_8055FC40
    ((float *)out)[0] = gNearClip;
    ((float *)out)[1] = gFarClip;
    ((float *)out)[2] = gFov;
    ((void (*)())fn_802C974C)(out);
    return out;
#undef gNearClip
#undef gFarClip
#undef gFov
}

/* Reapplies the saved near/far/FOV triple and returns the buffer; frees it when freeBuffer is positive. */ void *DrawList_restoreProjection(void *savedParams, int freeBuffer) {
    /* Destructor helper: apply stored projection parameters, then optionally free the object. */
    if (savedParams != 0) {
        fn_802C974C(((float *)savedParams)[0], ((float *)savedParams)[1], ((float *)savedParams)[2]);
        if (freeBuffer > 0) {
            fn_80128668(savedParams);
        }
    }
    return savedParams;
}

/* Effective view/projection angle recomputed by fn_802C974C. */
#define sViewAngle lbl_8055FC4C
/* Return the current effective view/projection angle maintained by fn_802C974C. */
float fn_802C973C(void) { return sViewAngle; }

/* Raw field-of-view input last applied through fn_802C974C. */
#define sFov lbl_8055FC40
/* Return the current field-of-view value last applied through fn_802C974C. */
float fn_802C9744(void) { return sFov; }

extern float __fabsf(float);
extern double __fabs(double);
extern int fn_802CC518();
#pragma push
#pragma processor 750
void fn_802C974C(float nearClip, float farClip, float fov) {
#define gViewBackup  lbl_804C144C
#define gNearClip    lbl_8055FC38
#define gFarClip     lbl_8055FC3C
#define gFov         lbl_8055FC40
#define gViewAngle   lbl_8055FC4C
#define gRightSlope  lbl_8055FC44
#define gViewSin     lbl_8055FC48
#define gUpSlope     lbl_8055FC50
#define gRightSlack  lbl_8055FC54
#define gUpSlack     lbl_8055FC58
#define gTangentDup  lbl_8055FC88
#define gViewMode    lbl_8055FC74
#define gForceRecalc lbl_8055FC75
#define gOne         lbl_80564EF8
#define gHalfPi      lbl_80564F28
#define gRadPerDeg   lbl_80564F18
#define gRadInv      lbl_80564F24
#define gEpsilon     lbl_80558DC4
#define gFarValue    lbl_8055D020
#define gNearValue   lbl_8055D024
#define gTanDivisor  lbl_8055FC6C
#define gDisplayObj  lbl_8055FC64
    float *view = gViewBackup;
    register float angle = fov;
    float f4;
    register float sine, theta, tangent;
    float cosine;
    float denom_angle, denom_sine, atan_value, ratio, depth;
    unsigned char mode = gViewMode;

    /* Applies the near/far/FOV inputs and recomputes the derived projection angles, slopes and depth values. */
    gNearClip = nearClip;
    gFarClip = farClip;
    gFov = fov;
    view[2] = fov;
    if (mode == 0 || (unsigned char)gForceRecalc != 0) {
        float diff = gFarValue - gOne;
        float abs = (float)__fabs((double)diff);
        if (!(abs <= (*(float *)&gEpsilon))) {
            atan_value = (float)atan((float)fn_8002EF30(gRadPerDeg * fov) / gFarValue);
            angle = gRadInv * atan_value;
        }
    }
    gViewAngle = angle;
    theta = gRadPerDeg * angle;
    sine = (float)sin(theta);
    cosine = (float)cos(theta);
    denom_angle = gHalfPi - angle * gRadPerDeg;
    gViewSin = sine;
    tangent = sine / cosine;
    gRightSlope = tangent;
    gTangentDup = tangent;
    denom_sine = (float)sin(denom_angle);
    depth = gOne / denom_sine;
    ratio = gRightSlope / gTanDivisor;
    gRightSlack = depth;
    gUpSlope = ratio;
    atan_value = (float)atan(ratio);
    theta = gRadInv * atan_value;
    sine = (float)sin(gHalfPi - theta * gRadPerDeg);
    f4 = gOne;
    gUpSlack = f4 / sine;
    switch (mode) {
    case 0: f4 = gFarValue / gNearValue; break;
    }
    fn_802D0368(gNearClip, gFarClip, angle, f4);
    fn_802CC518((int)gDisplayObj, gRightSlope);
#undef gDisplayObj
#undef gTanDivisor
#undef gNearValue
#undef gFarValue
#undef gEpsilon
#undef gRadInv
#undef gRadPerDeg
#undef gHalfPi
#undef gOne
#undef gForceRecalc
#undef gViewMode
#undef gTangentDup
#undef gUpSlack
#undef gRightSlack
#undef gUpSlope
#undef gViewSin
#undef gRightSlope
#undef gViewAngle
#undef gFov
#undef gFarClip
#undef gNearClip
#undef gViewBackup
}
#pragma pop
/* Aliases for the view/projection parameters maintained by fn_802C974C. */
#define sTangent lbl_8055FC44
#define sViewX   lbl_8055FC38
#define sViewY   lbl_8055FC3C
#define sSine    lbl_8055FC48
/* DrawList: copy the current projection tangent, view X/Y and view-angle sine into the output floats. */ void DrawList_getViewParams(float *outTan, float *outViewX, float *outViewY, float *outSin) {
    /* Snapshot the current view/projection parameters: projection tangent, view X/Y and the view-angle sine. */
    *outTan = sTangent;
    *outViewX = sViewX;
    *outViewY = sViewY;
    *outSin = sSine;
}

void fn_802D007C(float);
/* Tail-call wrapper: forward the alpha/brightness value to fn_802D007C, which sets the TEV color. */
void fn_802C9900(float value) {
    fn_802D007C(value);
}

#pragma dont_inline off
extern float lbl_80564EF8;
extern void fn_802D007C(float);
/* Reset the TEV color to full strength: call fn_802D007C with lbl_80564EF8 (1.0f). */
void fn_802C9904(void) {
    fn_802D007C(lbl_80564EF8);
}

/* Set the current packed model color, forward its RGB components to the GX color setter, and return the previous packed color. */ int setModelColor(int packedColor) {
    /* Set the current packed model color, forward its RGB components to the
     * GX color setter, and return the previous packed color. */
    int previousColor = gCurrentModelColor;
    gCurrentModelColor = packedColor;
    fn_802CFFAC((packedColor >> 16) & 0xFF, (packedColor >> 8) & 0xFF, packedColor & 0xFF);
    return previousColor;
}

extern int gCurrentDrawListColor;
extern void fn_802D0160(unsigned char, unsigned char, unsigned char);
/* Set the current packed drawlist color, forward its RGB components to
 * fn_802D0160, and return the previous packed color. */
int setDrawListColor(int packedColor)
{
    int previousColor = gCurrentDrawListColor;
    gCurrentDrawListColor = packedColor;
    fn_802D0160((packedColor >> 16) & 0xFF, (packedColor >> 8) & 0xFF, packedColor & 0xFF);
    return previousColor;
}

extern int gLightAmbientColor;
extern void fn_802D0188(unsigned char, unsigned char, unsigned char);
/* Set the current packed light-ambient RGB color, forward its R/G/B components to the GX color setter, and return the previous packed color. */
int setLightAmbientColor(int packedColor) {
    int previousColor = gLightAmbientColor;
    gLightAmbientColor = packedColor;
    fn_802D0188((packedColor >> 16) & 0xFF, (packedColor >> 8) & 0xFF, packedColor & 0xFF);
    return previousColor;
}

extern char gGlobalDrawDirection[];
extern float gGlobalDrawScalar;
void DrawList_applyGlobalDirection(void) {
    /* Reapply the global draw direction and scalar to the fallback (default) light. */
    gxSetDefaultLightDirection(gGlobalDrawDirection, gGlobalDrawScalar);
}

#pragma dont_inline on
/* Set the global draw scalar gGlobalDrawScalar to value, apply it through
 * DrawList_applyGlobalDirection, and return the previous value (float analog of setLightAmbientColor). */
/* setDrawScalar: set the global draw scalar (gGlobalDrawScalar) to value, reapply the draw direction via DrawList_applyGlobalDirection, and return the previous scalar; the float analog of setLightAmbientColor. */ /* setDrawScalar: set the global draw scalar (gGlobalDrawScalar) to value, reapply the draw direction via DrawList_applyGlobalDirection, and return the previous scalar; the float analog of setLightAmbientColor. */ float fn_802C99E8(float value) {
    float previous = gGlobalDrawScalar;
    gGlobalDrawScalar = value;
    DrawList_applyGlobalDirection();
    return previous;
}
#define globalDirection gGlobalDrawDirection /* global 3-component direction vector */
#pragma dont_inline on
/* Copy the 3-component direction into the global direction vector and reapply it to the draw state with DrawList_applyGlobalDirection. */ void DrawList_setGlobalDirection(float *direction) {
    /* Store a 3-component direction in the global and reapply it to the draw list. */
    float z, y, x;
    x = direction[0];
    y = direction[1];
    z = direction[2];
    ((float *)globalDirection)[0] = x;
    ((float *)globalDirection)[1] = y;
    ((float *)globalDirection)[2] = z;
    DrawList_applyGlobalDirection();
}
#pragma dont_inline reset
#undef globalDirection
/* Return a pointer to the global 3-component draw direction vector (gGlobalDrawDirection). */
/* Return a pointer to the global 3-component draw-direction vector (gGlobalDrawDirection). */ void *DrawList_getGlobalDrawDirection(void) {
    #define globalDirection gGlobalDrawDirection
    return globalDirection;
    #undef globalDirection
}

/* Floating-point state save/restore stub: callers pass a new value and expect the
 * old one back, but this build ignores the argument and tail-calls fn_802D93E0,
 * which simply returns a constant 0.0f. */
void fn_802C9A4C(void) {
    fn_802D93E0();
}

/* Get the horizontal display/UI scale factor (1.0 normal, 0.75 widescreen/letterbox). */
float fn_802C9A50(void) { return lbl_8055D020; }

#pragma dont_inline off
char fn_802C9A58(void) {
    /* Returns lbl_8055FC8C, the widescreen flag set by fn_802C82C4 from the
     * aspect-ratio setting; callers use it to pick widescreen layouts and
     * scissor regions instead of the standard ones. */
    return lbl_8055FC8C;
}

extern char lbl_8055FC8D;
/* Returns lbl_8055FC8D, the display/viewport mode flag set by fn_802C82C4
 * when mode 2 is selected; callers use it to apply the letterbox viewport and
 * draw the top/bottom black bars. */
char fn_802C9A60(void) {
    return lbl_8055FC8D;
}

extern char lbl_8055FC8E;
char fn_802C9A68(void) {
    /* Returns lbl_8055FC8E, a display-scaling flag sitting next to the
     * widescreen/linedouble flags; fn_80231094 tests it to choose the viewport
     * margin factor (0.9 instead of 0.85) for its scissor rectangle. */
    return lbl_8055FC8E;
}

extern int lbl_8055CFF0, lbl_8055CFF4;
extern float lbl_80564F18, lbl_80564F28;
#pragma dont_inline on
/* Draw letterbox/pillarbox bars when viewport scaling flags are set.
 * Sets a draw-guard flag, updates viewport/projection if needed, then draws
 * left/right and/or top/bottom black bars based on scaled view dimensions.
 */
void fn_802C9A70(int drawBars) {
    int sideBarWidth;
    int topBarHeight;
    int horizontalDelta;
    int verticalDelta;
    lbl_8055FC74 = 1;
    if ((unsigned char)lbl_8055FC8D != 0) {
        DrawList_setViewport(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        HomeMenu_applySavedFade(2);
        fn_802C974C(lbl_8055FC38, lbl_8055FC3C, lbl_80564F28);
    }
    if (((unsigned char)lbl_8055FC8C != 0 || (unsigned char)lbl_8055FC8D != 0) && drawBars != 0) {
        horizontalDelta = lbl_8055CFF0 - (int)(lbl_80564F18 + ((float)lbl_8055CFF0 * lbl_8055D020));
        sideBarWidth = horizontalDelta / 2;
        if (sideBarWidth > 1) {
            fn_802C92D0();
            fn_802C92DC(0, 0, sideBarWidth, lbl_8055CFF4, 0xFF000000);
            fn_802C92DC(lbl_8055CFF0 - sideBarWidth, 0, lbl_8055CFF0, lbl_8055CFF4, 0xFF000000);
            fn_802C92D8();
        }
    }
    if ((unsigned char)lbl_8055FC8D != 0) {
        verticalDelta = lbl_8055CFF4 - (int)(lbl_80564F18 + ((float)lbl_8055CFF4 * lbl_8055D024));
        topBarHeight = verticalDelta / 2;
        if (topBarHeight > 1) {
            fn_802C92D0();
            fn_802C92DC(0, 0, lbl_8055CFF0, topBarHeight, 0xFF000000);
            fn_802C92DC(0, lbl_8055CFF4 - topBarHeight, lbl_8055CFF0, lbl_8055CFF4, 0xFF000000);
            fn_802C92D8();
        }
    }
    lbl_8055FC74 = 0;
}
#pragma dont_inline reset
/* Return the name string of a resource-list entry: follow entry->node (+8), then node->nameHolder (+4), and return the string pointer at nameHolder+4. */
int ResourceEntry_GetName(void *entry) {
    void *node = *(void **)((char *)entry + 8);
    void *nameHolder = *(void **)((char *)node + 4);
    return *(int *)nameHolder + 4;
}

extern void *lbl_8055FC68;
/* Get the current viewport height (lbl_8055FC68). */
void* fn_802C9C38(void) {
    return lbl_8055FC68;
}

extern void *lbl_8055FC60;
/* Get the current viewport's top-left y coordinate (lbl_8055FC60). */
void* fn_802C9C40(void) {
    return lbl_8055FC60;
}

extern void *lbl_8055FC64;
/* Get the current viewport width (lbl_8055FC64). */
void* fn_802C9C48(void) {
    return lbl_8055FC64;
}

extern void *lbl_8055FC5C;
/* Get the current viewport's top-left x coordinate (lbl_8055FC5C). */
void* fn_802C9C50(void) {
    return lbl_8055FC5C;
}

/* setCullMode: set the cached cull mode (lbl_8055FC30), reapply it through gxApplyCullMode, and return the mode it replaced; callers save the return and restore it afterwards. */ /* setCullMode: set the cached cull mode (lbl_8055FC30), reapply it through gxApplyCullMode, and return the mode it replaced; callers save the return and restore it afterwards. */ int fn_802C9C58(int cullMode) {
    /* Set the cached cull mode, apply it to GX, and return the previous value. */
    int previousCullMode = lbl_8055FC30;
    lbl_8055FC30 = cullMode;
    gxApplyCullMode();
    return previousCullMode;
}

/* Begin the alpha-only overlay pass that fn_802C9CE0 finishes.  The texture
 * module's "texture last bound" cache is dropped first (Texture_InvalidateLastBoundSlot, the pass
 * replaces the TEV and blend state behind its back) and fn_802D31D8 then puts
 * GX into the state that writes alpha only: colour updates off, one TEV stage
 * producing a constant alpha, that alpha blended into the frame buffer.  (It
 * takes no real argument; the 1 is what the original left in r3.)  Whatever the
 * caller draws up to fn_802C9CE0 therefore only paints an alpha mask, which
 * that function copies off the frame buffer and blends back over the screen
 * tinted with `tintColor` -- a packed RGBA word, read as a colour by
 * gxArgbToRgba; fn_8029790C passes 0x50000000 for its shadow volumes, black at
 * 0x50 alpha.  The tint is kept for that second half, the module's render state
 * becomes the overlay pass, and 0 is returned when the state could not be set
 * up, so the caller skips its drawing.
 * (rename_symbol is refused here, so the suggested name
 * DrawList_BeginAlphaOverlay only lives in this comment.) */
/* Begin an alpha-only overlay pass: invalidate the texture cache, set up GX to write only alpha, save the tint and overlay render mode, and report whether setup succeeded. */ int fn_802C9C8C(unsigned int tintColor) {
    Texture_InvalidateLastBoundSlot();
    if (fn_802D31D8(1) != 0) {
        sOverlayTint = tintColor;
        sRenderMode = RENDER_MODE_ALPHA_OVERLAY;
        return 1;
    }
    return 0;
}

/* Finish an alpha-only overlay pass: blend the saved-tint alpha mask back over
   the screen, reset GX to its default state and resume normal rendering. */
void fn_802C9CE0(void) {
    fn_802D362C(sOverlayTint);
    gxResetDefaultState();
    sRenderMode = RENDER_MODE_NORMAL;
}

/* DrawListWrapper::alloc(size, name): hand out one DrawListWrapper from the
 * class's static pool, building that pool (DRAWLIST_POOL_CAPACITY elements of
 * DRAWLIST_WRAPPER_SIZE bytes, named "DrawListWrapper::pool") the first time
 * one is wanted.  The requested size and name (DrawListWrapper_create passes 0x18 and
 * "mrDrawList") go unused: every element of this pool is the same.  Returns 0
 * when the pool is empty; fn_802C9D88 hands elements back and tears the pool
 * down once no DrawListWrapper is live any more. */
/* Allocate a DrawListWrapper from the lazily built static pool, ignoring size/name, and bump the live count. */ void *DrawListWrapper_alloc(int size, const char *name) {
    struct ObjectPool *pool;
    void *element;

    (void)size;
    (void)name;
    if (sDrawListLiveCount == 0) {
        pool = NamedAlloc(sizeof(struct ObjectPool), STR_DRAWLIST_POOL);
        if (pool != 0) {
            pool = Pool_Init(pool, STR_DRAWLIST_POOL, DRAWLIST_POOL_CAPACITY, DRAWLIST_WRAPPER_SIZE);
        }
        sDrawListPool = pool;
    }
    element = Pool_Alloc(sDrawListPool);
    if (element != 0) {
        sDrawListLiveCount += 1;
    }
    return element;
}

extern int fn_8012A364(void *, int);
extern void *fn_801E7840(int);
#pragma dont_inline on
#pragma push
#pragma cplusplus on
extern "C" void fn_802C9D88(int element) {
    /* Return a DrawListWrapper to its pool and, once none remain live, destroy
     * the pool through its vtable and clear the static pool pointer. */
    class ObjectPoolView {
    public:
        virtual void release(int);
    };
    Pool_Free(sDrawListPool, element);
    if (--sDrawListLiveCount == 0) {
        if (sDrawListPool != 0)
            ((ObjectPoolView *)sDrawListPool)->release(1);
        sDrawListPool = 0;
    }
}
#pragma cplusplus reset
#pragma pop

/* Construct a DrawListWrapper: allocate its GenericDrawList, then zero the accumulated orientation and frame count. */ void *DrawListWrapper_init(void *obj, int listCount) {
#define NewGenericDrawList fn_801E7840
    /* DrawListWrapper constructor: creates the GenericDrawList of `listCount` entries
     * this wrapper draws through, then clears the orientation (x, y, z, w) that
     * fn_802C9E94 blends in frame to frame and the number of frames blended. */
    struct DrawListWrapper *list = (struct DrawListWrapper *)obj;
    void *drawList = NewGenericDrawList(listCount);
    float zero = lbl_80564F00;

    list->drawList = drawList;
    list->x = zero;
    list->y = zero;
    list->z = zero;
    list->w = zero;
    list->count = 0;
    return obj;
}

int *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_802C9E3C(int *self, int shouldDelete) {
    /* Deleting destructor for J2DAnmTexPatternTIMGPointer: release owned data, optionally free storage. */
    if (self != 0) {
        fn_801E7888(*self);
        if (shouldDelete > 0) fn_802C9D88((int)self);
    }
    return self;
}

extern void fn_801E7890(void);
#pragma scheduling invalid_target
int fn_802C9E94(void *arg0, int arg1, int arg2, float farg0, float farg1, float farg2, float farg3, float farg4)
{
  struct State
  {
    void *callback;
    float x;
    float y;
    float z;
    float w;
    int count;
  };
  struct State *state = (struct State *) arg0;
  float q[3];
  float diff[3];
  float result;
  float step;
  float new_w;
  int old_count;
  if (state->count == 0)
  {
    float zero = lbl_80564F00;
    state->x = farg0;
    state->y = farg1;
    state->z = farg2;
    state->w = zero;
  }
  else
  {
    q[0] = farg0;
    q[1] = farg1;
    q[2] = farg2;
    result = ((float (*)(void *, float *)) PSQUATMultiply)(&state->x, q);
    if (result > state->w)
    {
      diff[0] = q[0] - state->x;
      diff[1] = q[1] - state->y;
      diff[2] = q[2] - state->z;
      PSVECNormalize(diff, diff);
      step = lbl_80564F18 * (result - state->w);
      new_w = lbl_80564F18 * (state->w + result);
      state->x = state->x + (step * diff[0]);
      state->y += diff[1] * step;
      {
        float z_step = diff[2] * step;
        state->w = new_w;
        state->z = state->z + z_step;
      }
    }
  }
  ((void (*)(void *, int, int, float, float, float, float, float)) fn_801E7890)(state->callback, arg1, arg2, farg0, farg1, farg2, farg3, farg4);
  old_count = state->count;
  state->count = old_count + 1;
  return old_count;
}
/* Submit the object's draw handle at +0 only when its position at +4 is inside
 * the view volume (tolerance at +0x10). */
/* Submit the object's draw handle at +0 only when its position at +4 is inside the view volume (tolerance at +0x10). */ void drawIfVisible(void *object) {
    if (((int (*)(int, float))fn_802C9640)((int)((char *)object + 4), *(float *)((char *)object + 0x10)) != 0) {
        fn_801E7894(*(int *)object);
    }
}

extern void *DrawListWrapper_init(void *, int);
extern char lbl_8034B52C[];
/* DrawListWrapper constructor: allocate one (0x18 bytes, "mrDrawList") from the pool and initialize it. */
void DrawListWrapper_create(int listCount) {
    void *obj;
    obj = DrawListWrapper_alloc(0x18, lbl_8034B52C);
    if (obj != 0) {
        DrawListWrapper_init(obj, listCount);
    }
}

/* Deleting-destructor thunk for J2DAnmTexPatternTIMGPointer: destroy `self`
 * and pass shouldDelete = 1 so the storage is freed too. */
void fn_802CA094(int *self) {
    __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_802C9E3C(self, 1);
}

/* Tail-call thunk: forward to fn_802C9E94, the quaternion-interpolating draw-list callback. */
void fn_802CA09C(void) {
    ((int (*)(void))fn_802C9E94)();
}

/* Tail-call thunk: forward `owner` to drawIfVisible, the view-visibility draw callback. */
void fn_802CA0A0(void *owner) { drawIfVisible(owner); }

extern char lbl_8055FC94;
extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;
