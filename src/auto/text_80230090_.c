#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { f32 a, b, c; s32 d; f32 e, f; } Pack6;

extern u8 lbl_8055B998;
extern f32 lbl_8055F02C;
extern f32 lbl_8055F030;
extern f32 lbl_80563610;
extern f64 lbl_80563638;
extern f32 lbl_80563640;
extern f32 lbl_80563648;
extern u32 lbl_8055FB9C;
extern u32 lbl_8055FBA0;
extern f32 lbl_80563614;
extern f32 lbl_8056365C;
extern f32 lbl_80563660;
f64 fn_8002EFB4();
extern f32 fn_8023659C();
extern void fn_80230AB8(u32, u8 *, u8 *, u8 *, u8 *);
extern void *fn_8022EDC4(void);
extern f64 lbl_80563650;
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern f32 lbl_80563640, lbl_80563644;
extern void DrawList_setViewport(s32, s32, s32, s32);
extern void fn_802C88BC(s32);
extern void fn_802C8530(void);
extern void fn_802C8638(s32);
extern void fn_802C974C(f32, f32, f32);
/* Initialize the rendering/UI subsystem: set up a default transform matrix, create its context, and run dependent init routines. */
void fn_80230090(void) {
    extern s32 lbl_8055F028;
    extern f32 lbl_80563610, lbl_80563614;
    extern s32 fn_80129C64(s32);
    extern void fn_8022EB90(void);
    extern s32 fn_8022EDE4(f32 *, f32);
    extern void fn_8022ED00(void);
    extern void fn_802321D8(void);
    extern void fn_8022F248(void);
    extern void fn_8023509C(void);
    extern void fn_802365D8(void);
    extern void fn_80236728(void);
    f32 transform[12];
    fn_80129C64(2);
    fn_8022EB90();
    transform[0]=lbl_80563610; transform[1]=lbl_80563614; transform[2]=lbl_80563614;
    transform[3]=lbl_80563614; transform[4]=lbl_80563610; transform[5]=lbl_80563614;
    transform[6]=lbl_80563614; transform[7]=lbl_80563614; transform[8]=lbl_80563610;
    transform[9]=lbl_80563614; transform[10]=lbl_80563614; transform[11]=lbl_80563614;
    lbl_8055F028=fn_8022EDE4(transform,lbl_80563610);
    fn_8022ED00(); fn_802321D8(); fn_8022F248(); fn_8023509C();
    fn_802365D8(); fn_80236728();
}

void fn_80230114(void) {
    /* Shut down the rendering/UI subsystem built by fn_80230090: drop the
       current UI node, return the UIContext to its pool, clear the uiAnime
       started flag, then flush the art, background-quad and font caches. */
#define FreeCurrentUINode   fn_8022EDB8
#define ReleaseUIContext    fn_8022EB30
#define gUIContext          lbl_8055F028
#define ClearUiAnimeStarted fn_80236774
#define FlushArtList        fn_802350BC
#define FreeBackgroundQuads fn_8022F294
#define FreeFontCache       fn_802324D8
#define FreeUINodeList      fn_8022EBF0
    extern s32 gUIContext;
    extern void FreeCurrentUINode(void);
    extern void ReleaseUIContext(s32);
    extern void ClearUiAnimeStarted(void);
    extern void FlushArtList(void);
    extern void FreeBackgroundQuads(void);
    extern void FreeFontCache(void);
    extern void FreeUINodeList(void);
    FreeCurrentUINode();
    ReleaseUIContext(gUIContext);
    ClearUiAnimeStarted(); FlushArtList(); FreeBackgroundQuads();
    FreeFontCache(); FreeUINodeList();
#undef FreeCurrentUINode
#undef ReleaseUIContext
#undef gUIContext
#undef ClearUiAnimeStarted
#undef FlushArtList
#undef FreeBackgroundQuads
#undef FreeFontCache
#undef FreeUINodeList
}

// ---------------------------------------------------------------------------
// Textured overlay quads (the scrolling 2D banners drawn over the race).
// A quad is four vertices of six words - x, y, z, packed colour, s, t - filled
// in by fn_80231380 and submitted with the two-triangle index list below.
#define QUAD_TEX_FULL   lbl_80563610  // .sdata2: 1.0f, texture coordinate at the right/bottom edge
#define QUAD_TEX_EMPTY  lbl_80563614  // .sdata2: 0.0f, texture coordinate at the left/top edge
#define QUAD_SCREEN_L   lbl_80563618  // .sdata2: -320.0f, left edge of the 640x480 screen box
#define QUAD_SCREEN_R   lbl_8056361C  // .sdata2: 320.0f
#define QUAD_SCREEN_T   lbl_80563620  // .sdata2: -240.0f
#define QUAD_SCREEN_B   lbl_80563624  // .sdata2: 240.0f
#define QUAD_UNSET_EDGE lbl_80563628  // .sdata2: -1.0f, "this edge of the wrapped copy is unused"
#define QUAD_INDICES    lbl_802F9FCC  // .rodata: {0,3,1,0,2,3}, the quad as two triangles
#define QUAD_INDICES_WRAPPED lbl_802F9FC0  // .rodata: the same list for the wrapped copy
#define QUAD_INDICES_SOLID lbl_802F9FD8  // .rodata: {0,1,3,0,3,2}, the untextured quad as two triangles

struct QuadIndices {
    u16 index[6];
};

// One quad: its box plus the two vertex arrays.  The box fields are in this
// order in memory (bottom first), which the original code relies on when it
// passes &left and &right to the wrap helper.
struct Quad {
    f32 bottom, right, top, left;
    struct QuadIndices indices, wrappedIndices;
    u8 pad[8];
    f32 vertex[4][6];        // the quad itself
    f32 wrappedVertex[4][6]; // the copy drawn when the quad leaves the screen box
} __attribute__((aligned(16)));

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma opt_common_subs off
// Draws one textured quad of the scrolling 2D overlay into the current display
// list.  The quad sits at (x,y), is w*h big, at depth z with colour colorId;
// flags 1/2 scroll it down/right and 4 sinks it, all by speed*time.  Flag 8
// grows the screen box it is wrapped in by `margin`, and flags 8/0x10 also
// draw a copy one box-width/height away whenever the quad has left that box,
// so the scroll tiles seamlessly.
void fn_80230150(s32 colorId, u32 flags, f32 x, f32 y, f32 z, f32 w, f32 h, f32 speed, f32 time, f32 margin) {
    extern void fn_802C8B98(s32, s32);                            // start a draw: colour, display list
    extern s32 fn_80230B9C(u32);                                  // colour id -> packed RGBA
    extern void fn_80230C9C(f32 *, f32 *, f32, f32, f32);         // wrap a span into the screen box
    extern void fn_80231380(void *, s32, f32, f32, f32, f32, f32);// fill one vertex
    extern void fn_802C8DB8(void *, s32, u16 *, s32);             // draw indexed quads
    extern void fn_802C8D74(void);                                // flush the draw
    extern f32 lbl_80563618, lbl_8056361C, lbl_80563620, lbl_80563624, lbl_80563628;
    extern struct QuadIndices lbl_802F9FC0, lbl_802F9FCC;
    struct Quad quad;
    f32 screenLeft, screenRight, screenTop, screenBottom;
    f32 copyLeft, copyRight, copyTop, copyBottom;

    quad.left=x; quad.top=y; quad.right=(f32)(double)x+w; quad.bottom=(f32)(double)y+h;

    if (flags & 1) { quad.top=y+time*speed; quad.bottom=quad.top+h; }         // scroll down
    if (flags & 2) { quad.left=x+time*speed; quad.right=quad.left+w; }        // scroll right
    if (flags & 4) z=z+time*speed;                                            // sink away from the screen
    screenLeft=QUAD_SCREEN_L; screenRight=QUAD_SCREEN_R; screenTop=QUAD_SCREEN_T; screenBottom=QUAD_SCREEN_B;
    fn_802C8B98(-1,(s32)fn_8022EDC4());
    colorId=fn_80230B9C(colorId);
    if (flags & 8) { screenLeft-=margin; screenRight+=margin; screenTop-=margin; screenBottom+=margin; }
    if ((flags & 8) || (flags & 0x10)) {
        fn_80230C9C(&quad.left,&quad.right,screenLeft,screenRight,-screenLeft+screenRight);
        fn_80230C9C(&quad.top,&quad.bottom,screenTop,screenBottom,-screenTop+screenBottom);
        copyBottom=copyTop=copyRight=copyLeft=QUAD_UNSET_EDGE;
        if (quad.left<screenLeft) { copyTop=quad.top; copyRight=screenRight; copyBottom=quad.bottom; copyLeft=quad.left+(-screenLeft+screenRight); }
        if (quad.right>screenRight) { copyTop=quad.top; copyLeft=screenLeft; copyBottom=quad.bottom; copyRight=quad.right-(-screenLeft+screenRight); }
        if (quad.top<screenTop) { copyBottom=screenBottom; copyTop=quad.top+(-screenTop+screenBottom); if (QUAD_UNSET_EDGE==copyLeft) { copyLeft=quad.left; copyRight=quad.right; } }
        if (quad.bottom>screenBottom) { copyTop=screenTop; copyBottom=quad.bottom-(-screenTop+screenBottom); if (QUAD_UNSET_EDGE==copyLeft) { copyLeft=quad.left; copyRight=quad.right; } }
        fn_80231380(quad.wrappedVertex[0],colorId,copyLeft,copyTop,z,QUAD_TEX_EMPTY,QUAD_TEX_EMPTY);
        fn_80231380(quad.wrappedVertex[1],colorId,copyRight,copyTop,z,QUAD_TEX_FULL,QUAD_TEX_EMPTY);
        fn_80231380(quad.wrappedVertex[2],colorId,copyLeft,copyBottom,z,QUAD_TEX_EMPTY,QUAD_TEX_FULL);
        fn_80231380(quad.wrappedVertex[3],colorId,copyRight,copyBottom,z,QUAD_TEX_FULL,QUAD_TEX_FULL);
        quad.wrappedIndices=QUAD_INDICES_WRAPPED;
        fn_802C8DB8(quad.wrappedVertex,4,quad.wrappedIndices.index,6);
    }
    fn_80231380(quad.vertex[0],colorId,quad.left,quad.top,z,QUAD_TEX_EMPTY,QUAD_TEX_EMPTY);
    fn_80231380(quad.vertex[1],colorId,quad.right,quad.top,z,QUAD_TEX_FULL,QUAD_TEX_EMPTY);
    fn_80231380(quad.vertex[2],colorId,quad.left,quad.bottom,z,QUAD_TEX_EMPTY,QUAD_TEX_FULL);
    fn_80231380(quad.vertex[3],colorId,quad.right,quad.bottom,z,QUAD_TEX_FULL,QUAD_TEX_FULL);
    quad.indices=QUAD_INDICES;
    fn_802C8DB8(quad.vertex,4,quad.indices.index,6);
    fn_802C8D74();
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
/* Draws text (fn_80232BA4) with horizontal scroll/wrap: measures text, wraps X range within margin-expanded screen bounds, and draws an overflow copy when clipped. */
void fn_802304EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                 f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                 f32 farg4, f32 farg5, f32 farg6, s32 arg_sp0) {
    extern f32 fn_8023293C(s32, s32, f32);
    extern void fn_80230C9C(f32 *, f32 *, f32, f32, f32);
    extern void fn_80232BA4(s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern f32 lbl_80563610, lbl_80563618, lbl_8056361C;
    f32 spC, sp8;
    f32 temp_f1, temp_f3, temp_f4;
    f32 temp_f31, temp_f28, temp_f27, temp_f26;
    f32 var_f1;
    s32 var_r0;

    (void)arg_sp0;
    temp_f31 = farg3;
    temp_f1 = fn_8023293C(arg1, arg0, lbl_80563610);
    temp_f3 = farg5 * farg4;
    temp_f28 = temp_f31 * temp_f1;
    temp_f27 = lbl_80563618 - farg6;
    temp_f1 = farg0 + temp_f3;
    temp_f26 = lbl_8056361C + farg6;
    temp_f4 = temp_f1 + temp_f28;
    spC = temp_f1;
    sp8 = temp_f4;
    fn_80230C9C(&spC, &sp8, temp_f27, temp_f26, -temp_f27 + temp_f26);
    var_r0 = 0;
    var_f1 = lbl_80563618;
    if (spC < temp_f27) {
        var_r0 = 1;
        var_f1 = spC + (-temp_f27 + temp_f26);
    }
    if (sp8 > temp_f26) {
        var_r0 = 1;
        var_f1 = (sp8 - (-temp_f27 + temp_f26)) - temp_f28;
    }
    if (var_r0 != 0) {
        fn_80232BA4(arg0, arg1, arg2, arg3, var_f1, farg1, farg3, farg2, lbl_80563610);
    }
    fn_80232BA4(arg0, arg1, arg2, arg3, spC, farg1, farg3, farg2, lbl_80563610);
}
#pragma pop

extern f32 lbl_8056362C;
extern f32 lbl_80563630;
extern f32 fn_8023293C(s32, s32, f32);
extern void fn_80230C9C(f32 *, f32 *, f32, f32, f32);
extern void fn_80233354(s32, s32, s32, s32, f32, f32, f32, f32);
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
// Computes a wrapped/clamped Y range for drawing: derives base/extents with fn_8023293C,
// adjusts via fn_80230C9C, issues an extra fn_80233354 draw when wrapped, then the final draw.
void fn_80230650(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                 f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                 f32 farg4, f32 farg5, f32 farg6, s32 arg_sp0) {
    f32 spC, sp8;
    f32 temp_f1, temp_f3, temp_f4;
    f32 temp_f31, temp_f28, temp_f27, temp_f26;
    f32 var_f2;
    s32 var_r0;

    (void)arg_sp0;
    temp_f31 = farg3;
    temp_f1 = fn_8023293C(arg1, arg0, lbl_80563610);
    temp_f3 = farg5 * farg4;
    temp_f28 = temp_f31 * temp_f1;
    temp_f27 = lbl_8056362C - farg6;
    temp_f1 = farg1 + temp_f3;
    temp_f26 = lbl_80563630 + farg6;
    temp_f4 = temp_f1 - temp_f28;
    spC = temp_f1;
    sp8 = temp_f4;
    fn_80230C9C(&sp8, &spC, temp_f27, temp_f26, -temp_f27 + temp_f26);
    var_r0 = 0;
    var_f2 = lbl_8056362C;
    if (sp8 < temp_f27) {
        var_r0 = 1;
        temp_f4 = sp8 + (-temp_f27 + temp_f26);
        var_f2 = temp_f4 + temp_f28;
    }
    if (spC > temp_f26) {
        var_r0 = 1;
        var_f2 = spC - (-temp_f27 + temp_f26);
    }
    if (var_r0 != 0) {
        fn_80233354(arg0, arg1, arg2, arg3, farg0, var_f2, farg3, farg2);
    }
    fn_80233354(arg0, arg1, arg2, arg3, farg0, spC, farg3, farg2);
}

#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
/* Draws text with Y-axis wrapping/clamping, re-drawing at wrapped position when it crosses bounds. */
void fn_802307AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                 f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                 f32 farg4, f32 farg5, f32 farg6, s32 arg_sp0) {
    extern s32 fn_80232B70(s32);
    extern void fn_80232BA4(s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern f32 lbl_80563620, lbl_80563624;
    f32 spC, sp8;
    f32 temp_f1, temp_f3, temp_f4;
    f32 temp_f31, temp_f28, temp_f27, temp_f26;
    f32 var_f2;
    s32 var_r0;
    (void)arg_sp0;
    temp_f31 = farg3;
    temp_f1 = (f32)fn_80232B70(arg1);
    temp_f3 = farg5 * farg4;
    temp_f28 = temp_f31 * temp_f1;
    temp_f27 = lbl_80563620 - farg6;
    temp_f1 = farg1 + temp_f3;
    temp_f26 = lbl_80563624 + farg6;
    temp_f4 = temp_f1 - temp_f28;
    spC = temp_f1;
    sp8 = temp_f4;
    fn_80230C9C(&sp8, &spC, temp_f27, temp_f26, -temp_f27 + temp_f26);
    var_r0 = 0;
    var_f2 = lbl_80563620;
    if (sp8 < temp_f27) {
        var_r0 = 1;
        temp_f4 = sp8 + (-temp_f27 + temp_f26);
        var_f2 = temp_f4 + temp_f28;
    }
    if (spC > temp_f26) {
        var_r0 = 1;
        var_f2 = spC - (-temp_f27 + temp_f26);
    }
    if (var_r0 != 0) {
        fn_80232BA4(arg0, arg1, arg2, arg3, farg0, var_f2, farg3, farg2, lbl_80563610);
    }
    fn_80232BA4(arg0, arg1, arg2, arg3, farg0, spC, farg3, farg2, lbl_80563610);
}
#pragma processor gekko
#pragma use_lmw_stmw on
#pragma scheduling on
#pragma paired on
#pragma paired_single on

#pragma processor 750
#pragma use_lmw_stmw on
#pragma scheduling invalid_target
#pragma paired_single off
#pragma paired off
#pragma ppc_psq_save off
#pragma cplusplus on
extern "C" void fn_80230924(u32 color, f32 left, f32 top, f32 right, f32 bottom, f32 depth);
extern "C" void fn_802C8B98(s32, s32);      // begin a draw into a display list
extern "C" void fn_802C8D74(void);          // end the draw
extern "C" void fn_802C8DB8(void *, s32, u16 *, s32); // submit verts: verts, count, indices, index count
extern "C" void fn_80231380(void *, s32, f32, f32, f32, f32, f32); // fill one vertex: colour, x, y, z, s, t
extern "C" s32 fn_80230B9C(u32);            // RGBA colour -> packed, RGB scaled by the global brightness
extern "C" f32 lbl_80563614;                // .sdata2: 0.0f
extern "C" u16 lbl_802F9FD8[6];             // QUAD_INDICES_SOLID
// Draws one untextured quad of the 2D overlay: the box (left,top)-(right,bottom)
// at `depth`, filled with `color` (RGBA, dimmed by the current global brightness)
// and texture coordinate 0 at every vertex.
void fn_80230924(u32 color, f32 left, f32 top, f32 right, f32 bottom, f32 depth) {
    s32 packedColor;
    struct SolidQuad {
        u16 indices[6];   // the two triangles the four vertices make
        u8 pad[4];
        f32 vertex[4][6]; // x, y, z, packed colour, s, t
    } __attribute__((aligned(16))) quad;
    fn_802C8B98(-1, (s32)fn_8022EDC4());
    packedColor = fn_80230B9C(color);
    fn_80231380(quad.vertex[0], packedColor, left, top, depth, QUAD_TEX_EMPTY, QUAD_TEX_EMPTY);
    fn_80231380(quad.vertex[1], packedColor, right, top, depth, QUAD_TEX_EMPTY, QUAD_TEX_EMPTY);
    fn_80231380(quad.vertex[2], packedColor, left, bottom, depth, QUAD_TEX_EMPTY, QUAD_TEX_EMPTY);
    fn_80231380(quad.vertex[3], packedColor, right, bottom, depth, QUAD_TEX_EMPTY, QUAD_TEX_EMPTY);
    {
        u16 *indexList = QUAD_INDICES_SOLID;
        quad.indices[0] = *indexList++;
        quad.indices[1] = *indexList++;
        quad.indices[2] = *indexList++;
        quad.indices[3] = *indexList++;
        quad.indices[4] = *indexList++;
        quad.indices[5] = *indexList++;
    }
    fn_802C8DB8(quad.vertex, 4, quad.indices, 6);
    fn_802C8D74();
}
#pragma scheduling on
#pragma ppc_psq_save reset
#pragma cplusplus reset

void fn_80230A68(void *dst, s32 color, f32 x, f32 y, f32 z, f32 s, f32 t) {
    /* Pack position, color, and texture coordinates into a 24-byte vertex record. */
    Pack6 vtx;
    vtx.a = x;
    vtx.b = y;
    vtx.c = z;
    vtx.d = color;
    vtx.e = s;
    vtx.f = t;
    *(Pack6 *)dst = vtx;
}

#pragma dont_inline on
void fn_80230AB8(u32 packedColor, u8 *outRed, u8 *outGreen, u8 *outBlue, u8 *outAlpha) {
    /* Unpack a 32-bit RGBA color into its four component bytes (R in the high byte). */
    *outRed = (u8)(packedColor >> 24);
    *outGreen = (u8)(packedColor >> 16);
    *outBlue = (u8)(packedColor >> 8);
    *outAlpha = (u8)packedColor;
}
#pragma dont_inline reset

/* Configure the 2D UI/camera state for the given display list index. */
void fn_80230AD8(s32 displayListIndex) {
    DrawList_setViewport(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802C88BC(3);
    fn_802C8530();
    fn_802C8638(displayListIndex);
    fn_802C974C(lbl_80563610, lbl_80563640, lbl_80563644);
}

void fn_80230B38(void* alarm) {
#define ShutdownRenderMode fn_802C855C
#define FlushFrame         fn_802C2B48
    /* Finalize callback: shut down the current render mode, then flush the
       pending frame. The alarm argument is unused. */
    FlushFrame(ShutdownRenderMode(alarm));
#undef ShutdownRenderMode
#undef FlushFrame
}

/* RealName: InitDefaultViewMatrix
 * Fill a 12-float (3x4) camera/view matrix with identity rotation and the
 * default Z translation: out[0,4,8] = 1.0, out[11] = -365.0, the rest 0.0. */
void fn_80230B5C(void *out) {
    extern f32 lbl_8056364C;              /* .sdata2: -365.0f, default view Z translation */
    f32 *matrix = (f32 *)out;
    f32 zTranslation;
    f32 zero = lbl_80563614;             /* .sdata2: 0.0f */
    f32 one  = lbl_80563610;             /* .sdata2: 1.0f */
    zTranslation = lbl_8056364C;
    matrix[0]=one; matrix[3]=zero; matrix[2]=zero; matrix[1]=zero;
    matrix[4]=one; matrix[7]=zero; matrix[6]=zero; matrix[5]=zero;
    matrix[8]=one; matrix[9]=zero; matrix[10]=zero; matrix[11]=zTranslation;
}

#pragma scheduling invalid_target
#pragma dont_inline on
s32 fn_80230B9C(u32 arg0) {
    /* Unpack a 32-bit RGBA color, scale the top byte by the global brightness at fn_8022EDC4()->+0x30, and repack as RGBA. */
    u8 spB, spA, sp9, sp8;
    void *object;
    f32 scale;
    s32 encoded;
    spB = 0;
    spA = 0;
    sp9 = 0;
    sp8 = 0;
    fn_80230AB8(arg0, &spB, &spA, &sp9, &sp8);
    object = fn_8022EDC4();
    scale = *(f32 *)((u8 *)object + 0x30);
    encoded = (s32)((f32)spB * scale);
    return (s32)(((u32)encoded << 24) | ((u32)spA << 16) | ((u32)sp9 << 8) | sp8);
}
#pragma dont_inline reset
#pragma scheduling on
void fn_80230C30(float *outX, float *outY, s32 screenX, s32 screenY) {
    /* Convert screen-space coordinates to coordinates centered at the screen middle. */
    *outX = (float)(screenX - (s32)lbl_8055FB9C / 2);
    *outY = (float)((s32)lbl_8055FBA0 / 2 - screenY);
}

/* Shift both values by whole multiples of step so they lie within [min, max] when
   both are below min or both above max; preserves truncating step count/temps. */
void fn_80230C9C(float *valueA, float *valueB, float min, float max, float step) {
    float var_f0, var_f0_2, var_f4, var_f5;
    int temp_r0, temp_r0_2;
    var_f4 = *valueA;
    var_f5 = *valueB;
    if ((var_f4 < min) && (var_f5 < min)) {
        if (var_f4 > var_f5) var_f0 = var_f4;
        else var_f0 = var_f5;
        temp_r0 = (int)((min - var_f0) / step) + 1;
        var_f4 += (float)temp_r0 * step;
        var_f5 += (float)temp_r0 * step;
    } else if ((var_f4 > max) && (var_f5 > max)) {
        if (var_f4 < var_f5) var_f0_2 = var_f4;
        else var_f0_2 = var_f5;
        temp_r0_2 = (int)((var_f0_2 - max) / step) + 1;
        var_f4 -= (float)temp_r0_2 * step;
        var_f5 -= (float)temp_r0_2 * step;
    }
    *valueA = var_f4;
    *valueB = var_f5;
}

/* No-op UI hook: called once per UI-render frame (via fn_800057BC and fn_802166B8)
   while the gate flag lbl_8055F024 is set; empty in this build. */
void fn_80230DA0(void) {}

#pragma push
#pragma processor 750
/* RealName: UpdateTimePhase */
float fn_80230DA4(float currentTime, float period) {
    /* Store the current time base and compute the remaining time offset within the period. */
#define sTimeBase   lbl_8055F030
#define sTimeOffset lbl_8055F02C
#define kZero       lbl_80563614
    float value;
    sTimeBase = currentTime;
    value = (float)fn_8002EFB4();
    if (value < kZero) value += period;
    return sTimeOffset = period - (float)(double)value;
#undef sTimeBase
#undef sTimeOffset
#undef kZero
}
#pragma pop

#pragma dont_inline on
#pragma push
#pragma processor 750
float fn_80230DF4(float a, float b) {
    /* Compute a normalized [0,1] phase/wrap value from (a + lbl_8055F02C) over period b, mirrored around 0.5. */
    float value = (float)fn_8002EFB4(a + lbl_8055F02C);
    if (value < lbl_80563614) value += b;
    value /= b;
    if (value < lbl_8056365C) value = lbl_80563610 - value;
    return value;
}
#pragma pop
#pragma dont_inline reset

/* Compute a mirrored [0,1] time phase: clamp the period to a small minimum,
 * return the elapsed-period count directly for the first half, and delegate to
 * the wrap-around calculation for the second half. */
float fn_80230E54(float currentTime, float period) {
#define kMinPeriod lbl_80563660
#define kHalf lbl_8056365C
#define sTimeBase lbl_8055F030
#define computeWrappedPhase fn_80230DF4
    float phase;

    period = (period > kMinPeriod) ? period : kMinPeriod;
    phase = (currentTime - sTimeBase) / period;
    if (phase < kHalf) {
        return phase;
    }
    return computeWrappedPhase(currentTime, period);
#undef computeWrappedPhase
#undef sTimeBase
#undef kHalf
#undef kMinPeriod
}

#pragma dont_inline on
void fn_80230E90(s32 useTickTime) {
    /* Update timing state using the tick counter when requested, otherwise the frame timer. */
    if (useTickTime == 1) {
        s32 ticks = KERNEL_GetTimeMs();
        f32 tickSeconds = ticks;
        fn_80230DA4(tickSeconds / lbl_80563640, lbl_80563648);
    } else {
        fn_80230DA4(fn_8023659C(), lbl_80563648);
    }
}
#pragma dont_inline on
float fn_80230EF4(long mode) {
    /* Compute a time-based value using tick count (mode 1) or the current time source, clamped by fn_80230E54. */
    if (!lbl_8055B998) {
        return lbl_80563610;
    }

    if (mode == 1) {
        s32 ticks = KERNEL_GetTimeMs();
        f32 tickValue = ticks;
        return fn_80230E54(tickValue / lbl_80563640, lbl_80563648);
    }

    return fn_80230E54(fn_8023659C(), lbl_80563648);
}
#pragma dont_inline reset
extern f32 lbl_80563610, lbl_80563640, lbl_80563648;
extern u32 lbl_8055FB9C, lbl_8055FBA0;
float fn_80230E54(float, float);
/* Reset a selected-item color field to the default highlight color 0xFFFFCA44
   (called by fn_80230F78). */
void fn_80230F6C(s32 *color) { *color = -0x35BC; }

extern float fn_80230EF4(long);
extern float lbl_80563610, lbl_80563614, lbl_80563658, lbl_80563664, lbl_80563668, lbl_8056366C;
#pragma dont_inline on
/* Computes a clamped/scaled byte value and a clamped float output from fn_80230EF4(arg3) using constant factors, stores the byte in *outByte and the float in *outFloat, then calls fn_80230F6C(arg2). */
void fn_80230F78(signed char *outByte, float *outFloat, long arg2, long arg3) {
    float inputValue;
    float clamped;
    float normalized;
    long scaled;
    long nonNegative;
    int byteValue;

    inputValue = fn_80230EF4(arg3);

    clamped = lbl_80563610;
    normalized = (inputValue - lbl_80563614) / lbl_80563658;
    clamped = (clamped < normalized) ? clamped : normalized;
    clamped = (clamped > lbl_80563614) ? clamped : lbl_80563614;

    scaled = (long)(lbl_80563664 + clamped * lbl_80563668);
    nonNegative = scaled & ((-scaled & ~scaled) >> 31);
    byteValue = (nonNegative >= 0xFF) ? 0xFF : nonNegative;

    clamped = lbl_80563610;
    normalized = (inputValue - lbl_80563614) / lbl_80563658;
    *outByte = byteValue;

    clamped = (clamped < normalized) ? clamped : normalized;
    clamped = (clamped > lbl_80563614) ? clamped : lbl_80563614;

    *outFloat = lbl_80563614 + clamped * lbl_8056366C;
    fn_80230F6C((s32 *)arg2);
}
#pragma dont_inline reset
/* Set the global flag that enables time-based value computation in fn_80230EF4. */
void fn_8023108C(u8 enabled) {
    lbl_8055B998 = enabled;
}

extern s32 fn_802C9A58(void);
extern s32 fn_802C9A60(void);
extern s32 fn_802C9A68(void);
extern f32 lbl_8055D020, lbl_80563610, lbl_80563614, lbl_8056365C;
extern f32 lbl_80563670, lbl_80563674, lbl_80563678, lbl_8056367C;
void fn_80231094(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    #pragma scheduling invalid_target
    f32 f2, f0, f1, f3, f4;
    s32 r5, r6;
    f32 mode = fn_802C9A68() ? 0.9f : 0.85f;
    f0 = 1.0f;
    f2 = 640.0f;
    f3 = f0 - mode;
    f0 = 480.0f;
    f1 = 0.5f;
    f2 = f2 * f3;
    f0 = f0 * f3;
    f2 = f1 * f2;
    f0 = f1 * f0;
    f2 = f1 + f2;
    f0 = f1 + f0;
    r5 = (s32)f2;
    r6 = (s32)f0;
    *arg2 = r5;
    *arg3 = r5;
    *arg0 = r6;
    *arg1 = r6;
    *arg2 = 0xF;
    *arg3 = 0xF;
    *arg0 = 0x18;
    *arg1 = 4;
    if (!fn_802C9A60() && fn_802C9A58()) {
        f4 = 1.0f;
        f0 = lbl_8055D020;
        f2 = 640.0f;
        f3 = f4 / f0;
        f1 = 0.5f;
        f0 = 0.0f;
        f3 = f3 - f4;
        f2 = f2 * f3;
        f2 = f1 * f2;
        if (f2 < f0) f0 = f2 - f1;
        else f0 = f1 + f2;
        *arg2 -= (s32)f0;
        f4 = 1.0f;
        f2 = 640.0f;
        f1 = 0.5f;
        f0 = 0.0f;
        f3 = f4 / lbl_8055D020;
        f3 = f3 - f4;
        f2 = f2 * f3;
        f2 = f1 * f2;
        if (f2 < f0) f0 = f2 - f1;
        else f0 = f1 + f2;
        *arg3 -= (s32)f0;
    }
}

#pragma push
#pragma processor 750
// Draws a textured axis-aligned quad: builds four vertices (x/y/w/h with uv corners
// u0,v0,u1,v1 and z = 0), copies the standard quad index list, submits them, then ends draw.
void fn_80231220(void *drawCtx, s32 texParam, f32 x, f32 y, f32 w, f32 h, f32 u0, f32 v0, f32 u1, f32 v1) {
    extern void fn_802C8B98(s32, s32);
    extern void fn_802C8D74(void);
    extern void fn_802C8DB8(void *, s32, u16 *, s32);
    extern void fn_80231380(void *, s32, f32, f32, f32, f32, f32);
    extern s32 fn_80230B9C(u32);
    extern f32 lbl_80563614;
    struct IndexList {
        u16 idx[6];
    };
    extern struct IndexList lbl_802F9FE4;
    struct Frame {
        struct IndexList indices;
        u8 pad1[4];
        f32 sp20[6];
        f32 sp38[6];
        f32 sp50[6];
        f32 sp68[6];
    } __attribute__((aligned(16))) frame;
    s32 state;
    f32 zero;

    fn_802C8B98((s32)drawCtx, (s32)fn_8022EDC4());
    state = fn_80230B9C((u32)texParam);
    zero = lbl_80563614;
    fn_80231380(frame.sp20, state, x, y, zero, u0, v0);
    fn_80231380(frame.sp38, state, x + w, y, zero, u1, v0);
    fn_80231380(frame.sp50, state, x, y - h, zero, u0, v1);
    fn_80231380(frame.sp68, state, x + w, y - h, zero, u1, v1);
    frame.indices = lbl_802F9FE4;
    fn_802C8DB8(frame.sp20, 4, frame.indices.idx, 6);
    fn_802C8D74();
}
#pragma pop

/* Fill one textured quad vertex: x, y, z, packed colour, then texture s and t. */
void fn_80231380(void *arg0, s32 color, f32 x, f32 y, f32 z, f32 s, f32 t) {
    Pack6 *v = (Pack6 *)arg0;
    v->a = x; v->b = y; v->c = z;
    v->d = color;
    v->e = s; v->f = t;
}

#pragma push
#pragma ctrloop on
void *fn_8023139C(void *buf, int len, u32 val)
{
  int temp = len - 1;
  int n = temp - ((temp - 1) / 3);
  int p;
  int used;
  int i;
  u32 max;
  char *dst;
  int digits;
  p = 1;
  used = 0;
  if (n > 0)
  {
    int m = (0, n - 8);
    if (n > 8)
    {
      int ok = 0;
      if ((n >= 0) && (n <= 0x7FFFFFFE))
      {
        ok = 1;
      }
      if (ok)
      {
        u32 count = ((u32) (m + 7)) >> 3;
        if (m > 0)
        {
          do
          {
            p *= 100000000;
            used += 8;
          }
          while ((--count) != 0);
        }
      }
    }
    i = n - used;
    if (used < n)
    {
      do
      {
        p *= 10;
      }
      while ((--i) != 0);
    }
  }
  max = p - 1;
  if (val < max)
  {
    max = val;
  }
  (dst = ((char *) buf) + len)[-1] = '\0';
  digits = 4;
  dst -= 2;
  do
  {
    if ((--digits) == 0)
    {
      *dst = ',';
      digits = 3;
      dst--;
    }
    *dst = (max % 10) + '0';
    max /= 10;
    dst--;
  }
  while (max != 0);
  return dst + 1;
}
#pragma pop
