// drawlist — draw lists (DrawListWrapper::pool, mrDrawList).
// Recovered TU window 0x802C82C0..0x802CA0A4+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CA0A4 (+ .ctors slot 0x802ED5A8) remains in
// auto/text_802CA0A4_.c pending a promotion pass.
#include <revolution/MTX/mtxtypes.h>
extern char lbl_8055FC34;
extern int lbl_8055D028;
extern int lbl_8055D02C;
extern float lbl_80564F04;
extern float lbl_80564F08;
extern void fn_802C5F48(float, int, float *, float, float);
extern void fn_801332D0(int, void *, int *);
extern int fn_8013365C(int, int);
extern int fn_802C9C58(int);
extern void fn_802C974C(float, float, float);
extern float lbl_8055FC6C;
extern void fn_802D362C(int);
extern void fn_802D3304(void);
extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
extern void fn_802C87B4(int, int, int, int);
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
 * (fn_802C90E0 asks whether the module is shut down); the other values record
 * the state the function that set them left GX in: 1 the game's normal one
 * (fn_802C8D74 puts it back), 2 the one fn_802CAD74/fn_801E4FF4 set up,
 * 3 fn_802C8C04's with the world matrix saved, 4 the alpha-only overlay pass
 * fn_802C9C8C begins, 6 the pass fn_802C8DBC begins. */
#define sRenderMode  lbl_8055FC70
#define sOverlayTint lbl_8055FC84 /* colour fn_802C9CE0 blends the screen back with */

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
extern void fn_802D08CC(void);
extern void fn_802CAD68(void);
extern int fn_802D31D8(int);
extern void fn_801E7888(int);
extern unsigned int lbl_804C1410[];
extern unsigned int lbl_804C13E0[];
extern char lbl_8055FC35;
struct DlMtx34 { unsigned int w[12]; };
extern float lbl_80564EF8, lbl_80564F00;
extern void fn_802C7758(int);
extern void fn_802C89E8(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void fn_802C8638(unsigned int *);
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);

extern char lbl_8055FC94;
__declspec(section ".sdata") extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;

extern int lbl_8055FC70;
extern void fn_802CFDE0(void);
extern void fn_802CC770(void);
extern void fn_802CC60C(void);
extern void fn_802CFCA0(void);
extern int lbl_8055FC78;
extern void fn_802CFFAC(unsigned char, unsigned char, unsigned char);
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[3];
extern unsigned char lbl_8055FC8F;
extern int fn_801E4F3C(void);
extern int fn_801E4F20(void);
extern void fn_802D68C4(void);

extern int lbl_8055FC70;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern char lbl_8055FC8C;
extern char lbl_8055FC8D;
extern float lbl_8055D024;
extern float lbl_80564EFC;
extern char lbl_8034B498[];
extern int fn_80019B9C(void);
extern int fn_802E9A0C(void);
extern void fn_80133348(int, const char *, int);
extern void *lbl_8055FC90;
void fn_802C82C0(void) {
}

#pragma cplusplus on
extern "C" int fn_80133010(void);
extern "C" void fn_802C82C4(int arg0) {
    const char *const base = lbl_8034B498;
    int mode = arg0;
    if (fn_80019B9C() != 0 || fn_802E9A0C() == 1) mode = 1;
    lbl_8055FC90 = (void *)mode;
    if (fn_80133010() != 0) fn_80133348(1, base, (int)lbl_8055FC90);
    lbl_8055FC8C = 0;
    lbl_8055D020 = lbl_80564EF8;
    lbl_8055D024 = lbl_80564EF8;
    lbl_8055FC8D = 0;
    switch (mode) {
    case 0:
        fn_802E30C8(base + 0x10);
        break;
    case 1:
        fn_802E30C8(base + 0x20);
        lbl_8055FC8C = 1;
        lbl_8055D020 = lbl_80564EFC;
        break;
    case 2:
        fn_802E30C8(base + 0x34);
        lbl_8055FC8D = 1;
        lbl_8055D020 = lbl_80564EFC;
        lbl_8055D024 = lbl_80564EFC;
        break;
    }
}
#pragma cplusplus reset
/* Get the "display_type" setting (0 normal, 1 widescreen, 2 letterbox). */
void* fn_802C83C4(void) {
    return lbl_8055FC90;
}

#pragma scheduling invalid_target
void fn_802C83CC(void) {
    register int ten = 10;
    float *dst = (float *)lbl_804C1410;
    float temp_f1 = (float)ten;
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
        fn_801332D0(1, lbl_8034B498, (int *)&lbl_8055FC90);
        lbl_8055D028 = fn_8013365C((int)&lbl_8055D02C, (int)fn_802C82C0);
    }
}
#pragma scheduling on
extern int fn_80133010(void);
extern void fn_801336E0(int, void (*)(void));
extern void fn_802C6080(void);
extern int lbl_8055D028;
extern int fn_802C9E94(void *, int, int, float, float, float, float, float);
extern int fn_801E7894(int);
/* RealName: DrawList_UnregisterCallbackAndShutdown_802C84EC */
void fn_802C84EC(void) {
    /* Unregister the drawlist debug callback if active, then shut down drawlists. */
    if (fn_80133010() != 0) {
        fn_801336E0(lbl_8055D028, fn_802C82C0);
        lbl_8055D028 = -1;
    }
    fn_802C6080();
}

/* Prepare draw lists for a render frame: enter normal GX render mode, reset the 0x40 texture draw slots (fn_802CC60C) and register the GX draw-sync callback (fn_802CFCA0); paired with the fn_802C855C teardown. */
void fn_802C8530(void) {
    sRenderMode = RENDER_MODE_NORMAL;
    fn_802CC60C();
    fn_802CFCA0();
}

/* Tear down the draw-list module: reset GX, release the texture list, and mark rendering shut down. */
void fn_802C855C(void) {
#define RENDER_MODE_SHUTDOWN 0
    fn_802CFDE0();
    fn_802CC770();
    sRenderMode = RENDER_MODE_SHUTDOWN;
#undef RENDER_MODE_SHUTDOWN
}

extern void fn_802C7758(int);
extern unsigned int lbl_804C13E0[];
extern char lbl_8055FC35;
extern void fn_802C89E8(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void fn_802C8638(unsigned int *);
extern float lbl_80564EF8, lbl_80564F00;
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
void fn_802C8588(float *arg0, float *arg1, float *arg2) {
    float dx = arg2[0] - arg1[0];
    float up = lbl_80564F00;
    float dy = arg2[1] - arg1[1];
    float right = lbl_80564EF8;
    float dz = arg2[2] - arg1[2];
    float sp[3];
    sp[0] = up;
    sp[1] = right;
    sp[2] = up;
    arg0[9] = arg1[0];
    arg0[10] = arg1[1];
    arg0[11] = arg1[2];
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
void fn_802C8638(unsigned int *arg0) {
    unsigned int v3, v2, v1, v0;
    unsigned int v4, v5, v6, v7, v8, v9, v10, v11;
    volatile unsigned int *dst;
    v2 = arg0[2];
    v3 = arg0[3];
    v1 = arg0[1];
    v0 = arg0[0];
    dst = (volatile unsigned int *)lbl_804C1410;
    v4 = arg0[4]; v5 = arg0[5]; v6 = arg0[6]; v7 = arg0[7];
    v8 = arg0[8]; v9 = arg0[9]; v10 = arg0[10]; v11 = arg0[11];
    dst[0] = v0; dst[1] = v1; dst[2] = v2; dst[3] = v3;
    dst[4] = v4; dst[5] = v5; dst[6] = v6; dst[7] = v7;
    dst[8] = v8; dst[9] = v9; dst[10] = v10; dst[11] = v11;
    fn_802D03F4((unsigned int *)dst, v10, v9, v8, v7, v6, v5, v4);
}
#pragma scheduling on
/* Return the buffer holding the current camera/view matrix (a 3x4 float matrix). */
void *fn_802C86DC(void) {
#define sCurrentMatrix lbl_804C1410
    return sCurrentMatrix;
#undef sCurrentMatrix
}

extern void *lbl_8055D018;
/* Store the packed ARGB color (default 0xFF7F7F7F gray) later applied to GX state by fn_802C88BC. */
void fn_802C86E8(void* color) {
    lbl_8055D018 = color;
}

void *fn_802C86F0(void *savedViewport, int x, int y, int width, int height) {
    /* Save the current viewport rectangle, then set a new one. */
    *(int *)((unsigned char *)savedViewport) = (int)lbl_8055FC5C;
    *(int *)((unsigned char *)savedViewport + 4) = (int)lbl_8055FC60;
    *(int *)((unsigned char *)savedViewport + 8) = (int)lbl_8055FC64;
    *(int *)((unsigned char *)savedViewport + 0xC) = (int)lbl_8055FC68;
    fn_802C87B4(x, y, width, height);
    return savedViewport;
}

extern void fn_802C87B4(int, int, int, int);
extern void fn_80128668(void *);
/* Restore a saved viewport rect (x, y, width, height at +0,+4,+8,+0xC) and optionally delete it. */
void *fn_802C8750(void *savedRect, int deleteFlag) {
    if (savedRect != 0) {
        fn_802C87B4(*(int *)((unsigned char *)savedRect), *(int *)((unsigned char *)savedRect + 4), *(int *)((unsigned char *)savedRect + 8), *(int *)((unsigned char *)savedRect + 0xC));
        if (deleteFlag > 0) {
            fn_80128668(savedRect);
        }
    }
    return savedRect;
}

#pragma push
#pragma scheduling invalid_target
/* Sets the current viewport rectangle (and aspect), applying a vertical scale/offset adjustment when the relevant flags are set, then updates the projection and scissor state. */
void fn_802C87B4(int x, int y, int width, int height) {
    int half;
    int deltaY;
    unsigned int rounding;
    if ((unsigned char)lbl_8055FC74 == 0 && (unsigned char)lbl_8055FC8D != 0) {
        rounding = (unsigned int)lbl_8055CFF4 >> 31;
        rounding += (unsigned int)lbl_8055CFF4;
        half = (int)rounding >> 1;
        deltaY = y - half;
        y = half + (int)(lbl_80564F18 + lbl_8055D024 * (float)deltaY);
        height = (int)(lbl_80564F18 + (float)height * lbl_8055D024);
    }
    lbl_8055FC64 = (void *)width;
    lbl_8055FC5C = (void *)x;
    lbl_8055FC60 = (void *)y;
    lbl_8055FC68 = (void *)height;
    lbl_8055FC6C = (float)width / (float)height;
    fn_802D01E0(x, y, width);
    fn_802CC518(width, lbl_8055FC44);
}
#pragma pop

/* Apply the stored value (set by fn_802C86E8) via fn_802D02F8, passing flags' low bit as its byte argument. */
void fn_802C88BC(int flags) {
    fn_802D02F8(lbl_8055D018, flags & 1);
}

extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
void fn_802C88CC(unsigned int arg0) {
    fn_802D02F8(arg0, 1);
}

extern unsigned int lbl_804C1410[];
extern void PSQUATMultiply(void *, unsigned int, void *);
extern void fn_802C7734(unsigned int);
extern void fn_802C8B70(void);
#pragma scheduling invalid_target
void fn_802C88D4(unsigned int quat) {
    /* Tail-call PSQUATMultiply: write quat (a raw bit pointer) multiplied by the cached quaternion at lbl_804C1410 into lbl_804C1410+0x24. */
    PSQUATMultiply((void *)&lbl_804C1410[9], quat, lbl_804C1410);
}

extern void PSVECSquareDistance(void *, unsigned int, void *);
void fn_802C88E8(unsigned int point) {
    /* Tail-call PSVECSquareDistance to measure squared distance from the cached Vec at lbl_804C1410+0x24 to *point (raw bit pointer). */
    PSVECSquareDistance((void *)&lbl_804C1410[9], point, lbl_804C1410);
}

#pragma scheduling reset
extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
extern double lbl_80564F10;
extern float lbl_80564F18, lbl_80564F1C;
#pragma scheduling invalid_target
void fn_802C88FC(float *arg0) {
    float x;
    float y;
    float z;
    float value;
    float fill;
    float scale;
    float divisor;

    x = (float)(unsigned int)lbl_8055FC64;
    scale = lbl_80564F18;
    divisor = lbl_8055FC44;
    value = lbl_80564EF8;
    z = value / lbl_8055D020;
    fill = lbl_80564F00;

    arg0[0] = value;
    arg0[1] = fill;
    arg0[2] = fill;
    arg0[3] = fill;
    y = (scale * x) / divisor;
    arg0[5] = fill;
    arg0[4] = lbl_80564F1C;
    arg0[6] = fill;
    arg0[7] = fill;
    arg0[8] = value;
    arg0[11] = -(y * z);
    arg0[10] = (float)(unsigned int)lbl_8055FC60 + scale * (float)(unsigned int)lbl_8055FC68;
    arg0[9] = (float)(unsigned int)lbl_8055FC5C + scale * (float)(unsigned int)lbl_8055FC64;
}

#pragma scheduling invalid_target
void fn_802C89E8(unsigned int *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5, unsigned int arg6, unsigned int arg7) {
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
    ((float *)arg0)[0] = var_f4;
    ((float *)arg0)[1] = fill;
    ((float *)arg0)[2] = fill;
    ((float *)arg0)[3] = fill;
    ((float *)arg0)[4] = lbl_80564F1C;
    ((float *)arg0)[5] = fill;
    ((float *)arg0)[6] = fill;
    ((float *)arg0)[7] = fill;
    ((float *)arg0)[8] = lbl_80564EF8;

    height = (int)lbl_8055FC68;
    y = (int)lbl_8055FC60;
    width = (int)lbl_8055FC64;
    x = (int)lbl_8055FC5C;
    scale = lbl_80564F18;
    ((float *)arg0)[10] = scale * (float)y + (float)height;
    ((float *)arg0)[11] = var_f2;
    ((float *)arg0)[9] = scale * (float)x + (float)width;
}
void fn_802C8B08(unsigned int *dst) {
    /* Copy the current 0x30-byte block at lbl_804C1410 (as 4 pairs plus a 0x10-byte tail) to dst. */
    struct Pair { unsigned int first; unsigned int second; };
    struct Tail { unsigned int first; struct Pair pair; unsigned int last; };
    struct Pair *dstPairs = (struct Pair *)dst;
    struct Pair *srcPairs = (struct Pair *)lbl_804C1410;
    struct Tail *dstTail = (struct Tail *)((char *)dst + 0x20);
    struct Tail *srcTail = (struct Tail *)((char *)lbl_804C1410 + 0x20);
    dstPairs[0] = srcPairs[0];
    dstPairs[1] = srcPairs[1];
    dstPairs[2] = srcPairs[2];
    dstPairs[3] = srcPairs[3];
    dstTail->first = srcTail->first;
    dstTail->pair = srcTail->pair;
    dstTail->last = srcTail->last;
}

extern void fn_802CAD74(void);
/* Mode-2 draw-list setup: select the texture slot passed through in r3 (fn_802CAD74), then set the render mode to 2. */
void fn_802C8B70(void) {
    fn_802CAD74();
    sRenderMode = 2;
}

#pragma dont_inline on
/* RealName: DrawList_QueueApplyAndBeginMode2 */
void fn_802C8B98(int handle, int source) {
    /* Queue the draw record at `source`, apply it as the current GX state, then run `handle`'s mode-2 draw-list setup. */
    fn_802C7734(source);
    ((void (*)(int))fn_802C8B70)(handle);
}
#pragma dont_inline reset
/* Reset the current GX material/vertex state to its default (fn_802C7758),
 * then run the mode-2 draw-list setup: select texture slot `texSlot` and set
 * the draw mode to 2. Like fn_802C8B98, but resets to the default instead of
 * applying a queued draw record first. */
void fn_802C8BD0(int texSlot) {
    fn_802C7758(texSlot);
    ((void (*)(int))fn_802C8B70)(texSlot);
}
#pragma dont_inline off

#pragma use_lmw_stmw off
void fn_802C8C04(int arg0) {
    unsigned int *dst = lbl_804C13E0;
    unsigned int sp8[12];
    unsigned int v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0;
    v0 = lbl_804C1410[0];
    v1 = lbl_804C1410[1]; v2 = lbl_804C1410[2]; v3 = lbl_804C1410[3];
    v4 = lbl_804C1410[4]; v5 = lbl_804C1410[5]; v6 = lbl_804C1410[6];
    v7 = lbl_804C1410[7]; v8 = lbl_804C1410[8]; v9 = lbl_804C1410[9];
    v10 = lbl_804C1410[10]; v11 = lbl_804C1410[11];
    *dst++ = v0; *dst++ = v1; *dst++ = v2; *dst++ = v3; *dst++ = v4; *dst++ = v5;
    *dst++ = v6; *dst++ = v7; *dst++ = v8; *dst++ = v9; *dst++ = v10; *dst++ = v11;
    lbl_8055FC35 = 1;
    fn_802C89E8(sp8, v11, v10, v9, v8, v7, v6, v5);
    fn_802C8638(sp8);
    ((void (*)(int))fn_802C8BD0)(arg0);
}

#pragma use_lmw_stmw off
void fn_802C8CBC(int arg0) {
    struct DlMtx34 *src = (struct DlMtx34 *)lbl_804C1410;
    struct DlMtx34 *dst = (struct DlMtx34 *)lbl_804C13E0;
    unsigned int sp8[12];
    unsigned int v11, v10, v9, v8, v7, v6, v5;
    v5 = src->w[5]; v6 = src->w[6]; v7 = src->w[7]; v8 = src->w[8];
    v9 = src->w[9]; v10 = src->w[10]; v11 = src->w[11];
    *dst = *src;
    lbl_8055FC35 = 1;
    ((void (*)(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))fn_802C88FC)(sp8, v11, v10, v9, v8, v7, v6, v5);
    fn_802C8638(sp8);
    ((void (*)(int))fn_802C8BD0)(arg0);
}

#pragma dont_inline on
/* Restores normal render mode and, if a saved matrix state is active, reapplies it then clears the flag. */
/* RealName: DrawList_RestoreNormalMode */
void fn_802C8D74(void) {
    lbl_8055FC70 = 1;
    if ((unsigned char)lbl_8055FC35 != 0) {
        fn_802C8638(lbl_804C13E0);
    }
    lbl_8055FC35 = 0;
}
#pragma dont_inline reset

void fn_802C8DB8(void) {
    fn_802D68C4();
}

/* If fn_801E4F20() reports active, sets the drawlist active flag (lbl_8055FC8F),
 * switches render mode to 6, and returns 1; otherwise returns 0. */
int fn_802C8DBC(void) {
    if (fn_801E4F20() != 0) {
        lbl_8055FC8F = 1;
        lbl_8055FC70 = 6;
        return 1;
    }
    return 0;
}

/* Clear the deferred draw/command flag unless it was set and the active
 * command path reports no pending work. */
void fn_802C8E00(void) {
    unsigned char keepFlag = 0;
    if (lbl_8055FC8F != 0 && fn_801E4F3C() == 0) {
        keepFlag = 1;
    }
    lbl_8055FC8F = keepFlag;
}

extern void fn_801E4FF4(void);
/* End the pending mesh pass -- fn_801E4FF4 flushes the mesh vertex/index buffers
 * and drops the mesh mode to idle -- and put the draw lists in render mode 2,
 * the GX state that mesh pass leaves behind. */
void fn_802C8E48(void) {
    fn_801E4FF4();
    sRenderMode = 2;
}

#pragma scheduling on
void fn_802C8E70(float *arg0, float *arg1) {
    float *m = (float *)lbl_804C1410;
    float z, y, x;
    float dx, dy, dz;
    float rx, ry, rz, limit, scale;
    float sy, sx, v1, v2;

    x = arg0[0];
    y = arg0[1];
    z = arg0[2];
    dx = x - m[9];
    arg1[0] = dx;
    dy = y - m[10];
    arg1[1] = dy;
    dz = z - m[11];
    arg1[2] = dz;

    rx = dy * m[1] + dx * m[0];
    ry = dx * m[3] + dy * m[4];
    rz = dx * m[6] + dy * m[7];
    rx = dz * m[2] + rx;
    ry = dz * m[5] + ry;
    rz = dz * m[8] + rz;

    arg1[0] = rx;
    arg1[1] = ry;
    arg1[2] = rz;

    limit = (lbl_8055FC38 > rz) ? lbl_8055FC38 : rz;

    scale = lbl_80564EF8 / (lbl_8055FC44 * limit);
    sy = scale * -arg1[1];
    sx = scale * arg1[0];
    v1 = lbl_80564EF8 + sx;
    v2 = lbl_80564EF8 + lbl_8055FC6C * sy;

    arg1[0] = (float)(int)lbl_8055FC5C + (lbl_80564F18 * (float)(int)lbl_8055FC64) * v1;
    arg1[1] = (float)(int)lbl_8055FC60 + (lbl_80564F18 * (float)(int)lbl_8055FC68) * v2;
}
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
int fn_802C90E0(void) {
    /* True when no draw-list render pass is active (the render-mode flag is 0); cf. DrawList_isOutsideScene. */
    return sRenderMode == 0;
}

/* Save GX state through fn_802C8C04 and record that draw lists now run in
 * its world-matrix-saving render mode (3). */
void fn_802C90F0(void) {
    ((void (*)(void))fn_802C8C04)();
    sRenderMode = 3;
}

#pragma scheduling invalid_target
/* For a valid texture index (not -1/-2) raise the draw guard and record whether mode is 1 in the FOV flag; for an invalid index clear both. Then select the texture through fn_802CB29C. */
void fn_802C9294(int textureIndex, int mode) {
#define DRAW_GUARD lbl_8055FC74
#define FOV_FLAG   lbl_8055FC75
    int isModeOne;
    if (textureIndex != -1 && textureIndex != -2) {
        isModeOne = mode == 1;
        FOV_FLAG = isModeOne;
        DRAW_GUARD = 1;
    } else {
        DRAW_GUARD = 0;
        FOV_FLAG = 0;
    }
    fn_802CB29C(textureIndex);
}
#pragma scheduling on
extern void fn_802C8C04(int);
extern void fn_802C8D74(void);
extern int lbl_8055FC70;
extern int fn_802CB29C(void);
extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern void fn_802C92DC(int, int, int, int, int);
#pragma dont_inline on
/* Set up drawlist/GX state through fn_802C8C04 with mode -1. The surrounding
   dont_inline pragma keeps this wrapper a real call (a tail branch) rather than
   letting fn_802C8C04 be inlined. */
void fn_802C92D0(void) {
#pragma dont_inline off
    fn_802C8C04(-1);
}

void fn_802C92D8(void) {
    fn_802C8D74();
}

/* Draws an axis-aligned quad outline/strip on the given screen if fn_801E4F20(4) succeeds. */
void fn_802C92DC(int left, int top, int right, int bottom, int screen) {
    if (((int (*)(int))fn_801E4F20)(4) != 0) {
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 0, (float)right, (float)top, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 0, (float)left, (float)top, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 1, (float)right, (float)bottom, 0.0f, 0.0f, 0.0f);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 1, (float)left, (float)bottom, 0.0f, 0.0f, 0.0f);
        fn_801E4FF4();
    }
}

/* Record render mode 2 (the state fn_802CAD74/fn_801E4FF4 leave GX in), then hand
 * off to fn_802C8D74 to restore the normal state and drop any pending overlay. */
void fn_802C9118(void) {
    sRenderMode = 2;
    fn_802C8D74();
}

#pragma processor 750
void fn_802C9124(float u0, float v0, float u1, float v1, int x0, int y0, int x1, int y1, int screen) {
    /* Submit a screen-space textured quad with the given UVs when the draw primitive can be started. */
    if (((int (*)(int))fn_801E4F20)(4) != 0) {
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 0, (float)x1, (float)y0, 0.0f, u1, v0);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 0, (float)x0, (float)y0, 0.0f, u0, v0);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 1, (float)x1, (float)y1, 0.0f, u1, v1);
        ((int (*)(int, int, float, float, float, float, float))fn_801E4F3C)(screen, 1, (float)x0, (float)y1, 0.0f, u0, v1);
        fn_801E4FF4();
    }
}
#pragma processor reset

#pragma dont_inline on
/* Draws a full-screen quad using the current screen dimensions and the given color. */
void fn_802C942C(int color) {
    fn_802C92D0();
    fn_802C92DC(0, 0, lbl_8055CFF0, lbl_8055CFF4, color);
    fn_802C92D8();
}
#pragma dont_inline reset
void fn_802C9474(void) {
    if ((unsigned char)lbl_8055FC94 != 0) return;
    lbl_8055FC94 = 1;
    fn_802E30C8((const char *)lbl_8055D030, lbl_8034B4E0);
}

extern float PSVECDotProduct(const Vec *, const Vec *);
extern float __fabsf(float);
extern float lbl_80564F20, lbl_8055FC50, lbl_8055FC54, lbl_8055FC58;
#pragma scheduling invalid_target
int fn_802C94A0(float *arg0, unsigned char *arg1, float *arg2, float tolerance) {
    float *matrix;
    volatile float delta[3];
    float temp_f0;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f1_4;
    float temp_f2;
    float temp_f3;
    float temp_f4;
    float var_f2;
    float var_f2_2;

    if (arg1 != 0) {
        *arg1 = 1;
    }

    matrix = (float *)lbl_804C1410;
    temp_f4 = arg0[0];
    temp_f3 = arg0[1];
    temp_f0 = matrix[9];
    temp_f2 = matrix[10];
    temp_f4 = temp_f4 - temp_f0;
    temp_f1 = arg0[2];
    temp_f0 = matrix[11];
    temp_f2 = temp_f3 - temp_f2;
    temp_f1 = temp_f1 - temp_f0;
    delta[0] = temp_f4;
    delta[1] = temp_f2;
    delta[2] = temp_f1;

    temp_f1_2 = PSVECDotProduct((Vec *)&delta[0], (Vec *)(matrix + 6));
    if ((temp_f1_2 < lbl_8055FC38 - tolerance) || (temp_f1_2 > lbl_8055FC3C + tolerance)) {
        return 0;
    }
    if (temp_f1_2 - tolerance > lbl_8055FC3C - lbl_80564F20 * lbl_8055FC3C) {
        return 0;
    }

    temp_f1_3 = (float)__fabs((double)PSVECDotProduct((Vec *)&delta[0], (Vec *)matrix));
    temp_f0 = temp_f1_2 * lbl_8055FC44;
    var_f2 = lbl_80564F00;
    var_f2 = (var_f2 > temp_f0) ? var_f2 : temp_f0;
    if (temp_f1_3 > var_f2 + tolerance * lbl_8055FC54) {
        return 0;
    }

    temp_f1_4 = (float)__fabs((double)PSVECDotProduct((Vec *)&delta[0], (Vec *)((float *)lbl_804C1410 + 3)));
    temp_f0 = temp_f1_2 * lbl_8055FC50;
    var_f2_2 = lbl_80564F00;
    var_f2_2 = (var_f2_2 > temp_f0) ? var_f2_2 : temp_f0;
    if (temp_f1_4 > var_f2_2 + tolerance * lbl_8055FC58) {
        return 0;
    }

    if (arg2 != 0) {
        *arg2 = temp_f1_2 - tolerance;
    }
    return 1;
}
#pragma scheduling on
/* View-volume containment test for a position: calls the full checker without
 * a distance output, still updating the caller's status byte. */
int fn_802C9638(void *position, unsigned char *status, float tolerance) {
    return fn_802C94A0(position, status, 0, tolerance);
}

#pragma dont_inline on
int fn_802C9640(void *arg0, float tolerance) {
    return fn_802C9638(arg0, 0, tolerance);
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
    /* Scale the current view X/Y parameters by a factor, saving the originals in
       the view backup slot, then reapply the projection with the scaled values. */
    float f0;
    float f2;
    float f3;
    float f4;
    f3 = lbl_8055FC38;
    f4 = lbl_8055FC3C;
    f0 = f3 * scale;
    f2 = f4 * scale;
    lbl_804C144C[0] = f3;
    lbl_804C144C[1] = f4;
    lbl_8055FC38 = f0;
    lbl_8055FC3C = f2;
    fn_802C974C(f0, f2, lbl_804C144C[2]);
}
#pragma scheduling on
/* Restores the backed-up view/projection parameters by reapplying the saved
 * triple in lbl_804C144C[0..2] through fn_802C974C. */
void fn_802C967C(void) {
    fn_802C974C(lbl_804C144C[0], lbl_804C144C[1], lbl_804C144C[2]);
}

void *fn_802C9694(void *arg0) {
    /* Initialize a 3-float vector from view/projection globals (lbl_8055FC38/3C/40),
       run fn_802C974C on it, and return the object. */
#define kViewX lbl_8055FC38
#define kViewY lbl_8055FC3C
#define kViewZ lbl_8055FC40
    ((float *)arg0)[0] = kViewX;
    ((float *)arg0)[1] = kViewY;
    ((float *)arg0)[2] = kViewZ;
    ((void (*)())fn_802C974C)(arg0);
    return arg0;
#undef kViewX
#undef kViewY
#undef kViewZ
}

void *fn_802C96DC(void *object, int shouldDelete) {
    /* Destructor helper: apply stored projection parameters, then optionally free the object. */
    if (object != 0) {
        fn_802C974C(((float *)object)[0], ((float *)object)[1], ((float *)object)[2]);
        if (shouldDelete > 0) {
            fn_80128668(object);
        }
    }
    return object;
}

float fn_802C973C(void) { return lbl_8055FC4C; }

float fn_802C9744(void) { return lbl_8055FC40; }

extern float __fabsf(float);
extern double __fabs(double);
extern int fn_802CC518();
#pragma push
#pragma processor 750
void fn_802C974C(float f0, float f1, float f2) {
    float *view = lbl_804C144C;
    register float angle = f2;
    float f4;
    register float sine, theta, tangent;
    float cosine;
    float denom_angle, denom_sine, atan_value, ratio, depth;
    unsigned char mode = lbl_8055FC74;

    /* Updates projection/FOV-related view parameters from near/far/fov inputs and recomputes derived trig and depth values. */
    lbl_8055FC38 = f0;
    lbl_8055FC3C = f1;
    lbl_8055FC40 = f2;
    view[2] = f2;
    if (mode == 0 || (unsigned char)lbl_8055FC75 != 0) {
        float diff = lbl_8055D020 - lbl_80564EF8;
        float abs = (float)__fabs((double)diff);
        if (!(abs <= (*(float *)&lbl_80558DC4))) {
            atan_value = (float)atan((float)fn_8002EF30(lbl_80564F18 * f2) / lbl_8055D020);
            angle = lbl_80564F24 * atan_value;
        }
    }
    lbl_8055FC4C = angle;
    theta = lbl_80564F18 * angle;
    sine = (float)sin(theta);
    cosine = (float)cos(theta);
    denom_angle = lbl_80564F28 - angle * lbl_80564F18;
    lbl_8055FC48 = sine;
    tangent = sine / cosine;
    lbl_8055FC44 = tangent;
    lbl_8055FC88 = tangent;
    denom_sine = (float)sin(denom_angle);
    depth = lbl_80564EF8 / denom_sine;
    ratio = lbl_8055FC44 / lbl_8055FC6C;
    lbl_8055FC54 = depth;
    lbl_8055FC50 = ratio;
    atan_value = (float)atan(ratio);
    theta = lbl_80564F24 * atan_value;
    sine = (float)sin(lbl_80564F28 - theta * lbl_80564F18);
    f4 = lbl_80564EF8;
    lbl_8055FC58 = f4 / sine;
    switch (mode) {
    case 0: f4 = lbl_8055D020 / lbl_8055D024; break;
    }
    fn_802D0368(lbl_8055FC38, lbl_8055FC3C, angle, f4);
    fn_802CC518((int)lbl_8055FC64, lbl_8055FC44);
}
#pragma pop
/* Aliases for the view/projection parameters maintained by fn_802C974C. */
#define sTangent lbl_8055FC44
#define sViewX   lbl_8055FC38
#define sViewY   lbl_8055FC3C
#define sSine    lbl_8055FC48
void fn_802C98DC(float *outTan, float *outViewX, float *outViewY, float *outSin) {
    /* Snapshot the current view/projection parameters: projection tangent, view X/Y and the view-angle sine. */
    *outTan = sTangent;
    *outViewX = sViewX;
    *outViewY = sViewY;
    *outSin = sSine;
}

void fn_802D007C(float);
void fn_802C9900(float arg0) {
    fn_802D007C(arg0);
}

#pragma dont_inline off
extern float lbl_80564EF8;
extern void fn_802D007C(float);
/* Reset the TEV color to full strength: call fn_802D007C with lbl_80564EF8 (1.0f). */
void fn_802C9904(void) {
    fn_802D007C(lbl_80564EF8);
}

int fn_802C990C(int arg0) {
    /* Set the current packed draw color, forward its RGB components to
     * fn_802CFFAC, and return the previous packed color. */
    int previousColor = lbl_8055FC78;
    lbl_8055FC78 = arg0;
    fn_802CFFAC((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previousColor;
}

extern int lbl_8055FC7C;
extern void fn_802D0160(unsigned char, unsigned char, unsigned char);
/* Set the current drawlist color (RGB packed in arg0) and return the previous packed color. */
int fn_802C9950(int rgb)
{
    int previous = lbl_8055FC7C;
    lbl_8055FC7C = rgb;
    fn_802D0160((rgb >> 16) & 0xFF, (rgb >> 8) & 0xFF, rgb & 0xFF);
    return previous;
}

extern int lbl_8055FC80;
extern void fn_802D0188(unsigned char, unsigned char, unsigned char);
/* Sets the current packed RGB color (stored in lbl_8055FC80) and forwards its
 * 8-bit R/G/B components to fn_802D0188, returning the previous packed color. */
int fn_802C9994(int packedColor) {
#define s_currentPackedColor lbl_8055FC80
#define ApplyPackedRgb fn_802D0188
    int previousColor = s_currentPackedColor;
    s_currentPackedColor = packedColor;
    ApplyPackedRgb((packedColor >> 16) & 0xFF, (packedColor >> 8) & 0xFF, packedColor & 0xFF);
    return previousColor;
#undef s_currentPackedColor
#undef ApplyPackedRgb
}

extern char lbl_804C1440[];
extern float lbl_8055D01C;
void fn_802C99D8(void) {
#define s_direction lbl_804C1440
#define s_drawScalar lbl_8055D01C
#define ApplyDirection fn_802D01B0
    /* Applies the global 3-component direction vector and draw scalar to the draw state. */
    ApplyDirection(s_direction, s_drawScalar);
#undef s_direction
#undef s_drawScalar
#undef ApplyDirection
}

#pragma dont_inline on
/* Set the global draw scalar lbl_8055D01C to value, apply it through
 * fn_802C99D8, and return the previous value (float analog of fn_802C9994). */
float fn_802C99E8(float value) {
    float previous = lbl_8055D01C;
    lbl_8055D01C = value;
    fn_802C99D8();
    return previous;
}
#define globalDirection lbl_804C1440 /* global 3-component direction vector */
#pragma dont_inline on
void fn_802C9A1C(float *direction) {
    /* Store a 3-component direction in the global and reapply it to the draw list. */
    float z, y, x;
    x = direction[0];
    y = direction[1];
    z = direction[2];
    ((float *)globalDirection)[0] = x;
    ((float *)globalDirection)[1] = y;
    ((float *)globalDirection)[2] = z;
    fn_802C99D8();
}
#pragma dont_inline reset
#undef globalDirection
/* Return a pointer to the global 3-component draw direction vector (lbl_804C1440). */
void *fn_802C9A40(void) {
    #define globalDirection lbl_804C1440
    return globalDirection;
    #undef globalDirection
}

void fn_802C9A4C(void) {
    fn_802D93E0();
}

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
    int barWidth;
    int barHeight;
    int hDelta;
    int vDelta;
    lbl_8055FC74 = 1;
    if ((unsigned char)lbl_8055FC8D != 0) {
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_802C88BC(2);
        fn_802C974C(lbl_8055FC38, lbl_8055FC3C, lbl_80564F28);
    }
    if (((unsigned char)lbl_8055FC8C != 0 || (unsigned char)lbl_8055FC8D != 0) && drawBars != 0) {
        hDelta = lbl_8055CFF0 - (int)(lbl_80564F18 + ((float)lbl_8055CFF0 * lbl_8055D020));
        barWidth = hDelta / 2;
        if (barWidth > 1) {
            fn_802C92D0();
            fn_802C92DC(0, 0, barWidth, lbl_8055CFF4, 0xFF000000);
            fn_802C92DC(lbl_8055CFF0 - barWidth, 0, lbl_8055CFF0, lbl_8055CFF4, 0xFF000000);
            fn_802C92D8();
        }
    }
    if ((unsigned char)lbl_8055FC8D != 0) {
        vDelta = lbl_8055CFF4 - (int)(lbl_80564F18 + ((float)lbl_8055CFF4 * lbl_8055D024));
        barHeight = vDelta / 2;
        if (barHeight > 1) {
            fn_802C92D0();
            fn_802C92DC(0, 0, lbl_8055CFF0, barHeight, 0xFF000000);
            fn_802C92DC(0, lbl_8055CFF4 - barHeight, lbl_8055CFF0, lbl_8055CFF4, 0xFF000000);
            fn_802C92D8();
        }
    }
    lbl_8055FC74 = 0;
}
#pragma dont_inline reset
/* Returns the address of a resource entry's name string: arg0->+8 is a node,
   node->+4 points at the name holder whose first word plus 4 is the string. */
int fn_802C9C24(void *entry) {
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

int fn_802C9C58(int cullMode) {
    /* Set the cached cull mode, apply it to GX, and return the previous value. */
    int previousCullMode = lbl_8055FC30;
    lbl_8055FC30 = cullMode;
    fn_802D08CC();
    return previousCullMode;
}

/* Begin the alpha-only overlay pass that fn_802C9CE0 finishes.  The texture
 * module's "texture last bound" cache is dropped first (fn_802CAD68, the pass
 * replaces the TEV and blend state behind its back) and fn_802D31D8 then puts
 * GX into the state that writes alpha only: colour updates off, one TEV stage
 * producing a constant alpha, that alpha blended into the frame buffer.  (It
 * takes no real argument; the 1 is what the original left in r3.)  Whatever the
 * caller draws up to fn_802C9CE0 therefore only paints an alpha mask, which
 * that function copies off the frame buffer and blends back over the screen
 * tinted with `tintColor` -- a packed RGBA word, read as a colour by
 * fn_802CEA1C; fn_8029790C passes 0x50000000 for its shadow volumes, black at
 * 0x50 alpha.  The tint is kept for that second half, the module's render state
 * becomes the overlay pass, and 0 is returned when the state could not be set
 * up, so the caller skips its drawing.
 * (rename_symbol is refused here, so the suggested name
 * DrawList_BeginAlphaOverlay only lives in this comment.) */
int fn_802C9C8C(unsigned int tintColor) {
    fn_802CAD68();
    if (fn_802D31D8(1) != 0) {
        sOverlayTint = tintColor;
        sRenderMode = RENDER_MODE_ALPHA_OVERLAY;
        return 1;
    }
    return 0;
}

/* Blend the alpha mask drawn since fn_802C9C8C back over the screen with the saved tint, then restore normal GX state. */
void fn_802C9CE0(void) {
    fn_802D362C(sOverlayTint);
    fn_802D3304();
    sRenderMode = RENDER_MODE_NORMAL;
}

/* DrawListWrapper::alloc(size, name): hand out one DrawListWrapper from the
 * class's static pool, building that pool (DRAWLIST_POOL_CAPACITY elements of
 * DRAWLIST_WRAPPER_SIZE bytes, named "DrawListWrapper::pool") the first time
 * one is wanted.  The requested size and name (fn_802CA04C passes 0x18 and
 * "mrDrawList") go unused: every element of this pool is the same.  Returns 0
 * when the pool is empty; fn_802C9D88 hands elements back and tears the pool
 * down once no DrawListWrapper is live any more. */
void *fn_802C9D10(int size, const char *name) {
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
    /* Return a DrawListWrapper to its pool and, when none remain live, destroy the pool via its vtable and clear it. */
    class Obj {
    public:
        virtual void f(int);
    };
    fn_8012A364(lbl_8055FC9C, element);
    if (--lbl_8055FC98 == 0) {
        if (lbl_8055FC9C != 0)
            ((Obj *)lbl_8055FC9C)->f(1);
        lbl_8055FC9C = 0;
    }
}
#pragma cplusplus reset
#pragma pop

void *fn_802C9DE8(void *obj, int listCount) {
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
int fn_802C9E94(void *arg0, int arg1, int arg2, float farg0, float farg1, float farg2, float farg3, float farg4) {
    struct State {
        void *callback;
        float x;
        float y;
        float z;
        float w;
        int count;
    };
    struct State *state = (struct State *)arg0;
    float q[3];
    float diff[3];
    float result;
    float new_w;
    float step;
    int old_count;

    if (state->count == 0) {
        float zero = lbl_80564F00;
        state->x = farg0;
        state->y = farg1;
        state->z = farg2;
        state->w = zero;
    } else {
        q[0] = farg0;
        q[1] = farg1;
        q[2] = farg2;
        result = ((float (*)(void *, float *))PSQUATMultiply)(&state->x, q);
        if (result > state->w) {
            diff[0] = q[0] - state->x;
            diff[1] = q[1] - state->y;
            diff[2] = q[2] - state->z;
            PSVECNormalize(diff, diff);
            step = lbl_80564F18 * (result - state->w);
            new_w = lbl_80564F18 * (state->w + result);
            state->x = state->x + diff[0] * step;
            state->y = state->y + diff[1] * step;
            {
                float z_step = diff[2] * step;
                state->w = new_w;
                state->z = state->z + z_step;
            }
        }
    }

    ((void (*)(void *, int, int, float, float, float, float, float))fn_801E7890)(
        state->callback, arg1, arg2, farg0, farg1, farg2, farg3, farg4);
    old_count = state->count;
    state->count = old_count + 1;
    return old_count;
}
/* Advance the embedded timer/animation state at +4 by the delta at +0x10; if it expires, notify the owner object at +0. */
void fn_802CA008(void *owner) {
    if (((int (*)(int, float))fn_802C9640)((int)((char *)owner + 4), *(float *)((char *)owner + 0x10)) != 0) {
        fn_801E7894(*(int *)owner);
    }
}

extern void *fn_802C9DE8(void *, int);
extern char lbl_8034B52C[];
/* Creates and initializes a draw list node (size 0x18) tagged "mrDrawList". */
void fn_802CA04C(int listCount) {
    void *obj;
    obj = fn_802C9D10(0x18, lbl_8034B52C);
    if (obj != 0) {
        fn_802C9DE8(obj, listCount);
    }
}

/* Deleting-destructor thunk for J2DAnmTexPatternTIMGPointer: destroy `self`
 * and pass shouldDelete = 1 so the storage is freed too. */
void fn_802CA094(int *self) {
    __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_802C9E3C(self, 1);
}

void fn_802CA09C(void) {
    ((int (*)(void))fn_802C9E94)();
}

void fn_802CA0A0(void *arg0) { fn_802CA008(arg0); }

extern char lbl_8055FC94;
extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;
