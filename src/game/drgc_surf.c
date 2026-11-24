// drgc_surf — GC surface drawing ("drgc/surf:", drDrawSurface).
// Recovered TU window 0x802D3F30..0x802D755C+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802D755C (+ .ctors slot 0x802ED5C4) remains in
// auto/text_802D755C_.c pending a promotion pass.
#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/GX/GXTypes.h"
#include "revolution/OS/OSFastCast.h"
extern void fn_802E317C(const char *, ...);
extern s32 fn_802DAC64(void);
extern void fn_802D61BC(void *);
extern const char lbl_8034C2F8[];
extern const char lbl_8034C334[];
typedef struct CacheEntry {
    u32 id;
    u8 key;
    u8 unk05[3];
    s32 start;
    s32 size;
} CacheEntry;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_804CA438[];
extern s32 lbl_8055FD1C;
extern u8 lbl_8055FDE4;
extern f32 lbl_8055FDE0;
/* Vertex-format display-list cache: a table of CacheEntry at lbl_804CA438,
 * a 0x4000-byte recording buffer and the number of lists cached so far. */
extern s32 lbl_8055FDF0;  // number of cached vertex-format lists
extern s32 lbl_8055FDF4;  // start of the display-list recording buffer
extern s32 lbl_8055FDF8;  // next free byte in that buffer
extern u8 lbl_8034C3DC[];
extern void fn_801282EC(s32);
extern void *fn_8012850C(s32, void *);
extern void DCInvalidateRange(void *, u32);
extern void fn_802D6C68(void);
extern void fn_802D2614(void);
extern void fn_802D2B0C(void);
extern void GXClearVtxDesc(void);
extern void GXSetVtxDesc(int, int);
extern void GXSetVtxAttrFmt(int, int, int, int, int);
extern void GXBegin(int, int, int);
extern volatile u8 lbl_8055FD25;
extern u8 lbl_804C5700[16];

typedef struct {
    u8 unk00;
    u8 pad[3];
    u32 unk04;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 unk0B;
    u8 unk0C;
    u8 unk0D;
} UnkStruct_804C5700;
extern void GXSetArray(u32, void *, u32);
extern void GXLoadPosMtxImm(void *, u32);
extern void PSMTXRotTrig(void *, void *, f32, f32, f32);
extern f32 lbl_80565008;
extern long fn_802CFF64(long);
extern u8 lbl_804D6C44[];
extern f32 lbl_804C56F0[];
extern f32 lbl_804CA308[];
extern f32 lbl_80564FF0;
extern f64 lbl_80564FF8;
extern f64 lbl_80565000;

static inline f32 fn_fast_s16f(s16 v) {
    union { f64 d; u32 w[2]; } conv;
    conv.w[0] = 0x43300000;
    conv.w[1] = (u32)((s32)v ^ 0x8000);
    return (f32)conv.d - (f32)lbl_80565000;
}
extern u8 lbl_8055FD19;
extern u32 lbl_804C5650[];
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
/* The FIFO vertex drawFifoTriangles pushes to the graphics processor: a position, one
   RGBA8 color and one texture coordinate, 24 bytes. */
typedef struct { f32 x, y, z; } FifoVec3;
typedef struct { FifoVec3 pos; u32 color; f32 u, v; } FifoVtx;
/* Writing a value here sends it to the GX FIFO. */
#define GX_FIFO_ADDR 0xCC008000
/* The per-surface draw record every drawer in this file is handed.  Byte +0x08
 * selects the vertex layout (fn_802D5FE4 dispatches on it); +0x1C counts the
 * vertices of the layouts that rebuild an array, and +0x20..+0x28 are the three
 * vertex arrays the drawer binds -- which GX attribute each one becomes depends
 * on the layout, and each array has its own stride.  +0x2C/+0x30 are the size
 * in bytes of the prebuilt display list that indexes them, and the list. */
struct SurfDraw {
    u8 pad00[0x1C];
    /* 0x1C */ s32 vertexCount;   // vertices the rebuilding drawers transform into a fresh array
    /* 0x20 */ void *positions;   // GX_VA_POS array
    /* 0x24 */ void *normals;     // GX_VA_NRM (or GX_VA_CLR0) array
    /* 0x28 */ void *colors;      // GX_VA_CLR1 (or GX_VA_TEX0) array
    /* 0x2C */ u32 listSize;      // display list size in bytes
    /* 0x30 */ void *displayList; // prebuilt display list
};

/* One deferred vertex transform: `count` source vertices at `src`, rebuilt into the
   position array at `dst`.  The last word is left 0; the pass that walks the queue
   (fn_802D6C78) never reads it. */
struct SurfXform {
    s32 count;
    void *src;
    void *dst;
    s32 flag;
};

/* A drawer's deferred-transform queue: 0x400 entries, with the number queued in the
   word after them (+0x4000).  While there is room a draw only queues its transform,
   which fn_802D6C78 then runs in chunks out of the L2 cache at the start of the next
   frame; once the queue is full the drawer transforms its vertices itself.
   lbl_804CEC3C is the queue of the format-16 drawer fn_802D45C0. */
struct SurfXformQueue {
    struct SurfXform entry[0x400];
    s32 queued;
};
extern f32 lbl_804C5690[];
extern f32 lbl_804C56C0[];
extern f32 lbl_804DB068[];
extern f32 lbl_8056500C;
extern f32 PSVECSquareDistance(void *, void *);
void fn_802D3F30(void) {
    /* No-op constructor: the static-init thunk passes this as the ctor callback
       for the 7-element lbl_804CA088 array; these objects need no setup. */
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void drDrawSurfLayout11(struct SurfDraw *surface) {
    /* Draw a surface with 12-byte positions, a 2-byte color0 array and 4-byte
     * texcoords: bind the three vertex arrays, then run its display list. */
    GXSetArray(GX_VA_POS, surface->positions, 0xC);
    GXSetArray(GX_VA_CLR0, surface->normals, 2);
    GXSetArray(GX_VA_TEX0, surface->colors, 4);
    GXCallDisplayList(surface->displayList, surface->listSize);
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
/* Bind this surface object's position, normal, and color vertex arrays, then
 * submit its prebuilt display list. */
void drDrawSurfLayout28(struct SurfDraw *surface) {
    /* Draw a surface with 12-byte positions, a 4-byte color0 array and 4-byte
     * texcoords: bind the three vertex arrays, then run its display list. */
    GXSetArray(GX_VA_POS, surface->positions, 0xC);
    GXSetArray(GX_VA_CLR0, surface->normals, 4);
    GXSetArray(GX_VA_TEX0, surface->colors, 4);
    GXCallDisplayList(surface->displayList, surface->listSize);
}
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void drDrawSurfLayout12(void *arg0) {
    /* Binds this object's position, texture, and color vertex arrays, then submits its display list. */
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXSetArray(0xE, *(void **)((char *)arg0 + 0x24), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}
#pragma scheduling invalid_target
void fn_802D4060(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    extern f32 lbl_80564FF0;
    register void *object = arg0;
    register volatile u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)(u32)fn_802CFF64(count * 12);
    s32 i;
    if (base == 0) return;
    {
        f32 (*directions)[3] = (f32 (*)[3])lbl_804DB068;
        f32 factor = lbl_80564FF0;
        register volatile f32 *out = base;
        for (i = 0; i < count; i++) {
            u8 a, b, c, d;
            f32 weight1, weight2;
            f32 *direction, *direction2;
            f32 x, y, z;
            a = src[0xE];
            b = src[0xC];
            direction = (f32 *)((u8 *)directions + b * 12);
            weight1 = factor * (f32)a;
            c = src[0xD];
            d = src[0xF];
            weight2 = factor * (f32)d;
            x = *(f32 *)((u8 *)src + 0x0) + direction[0] * weight1;
            out[0] = x;
            y = *(f32 *)((u8 *)src + 0x4) + direction[1] * weight1;
            out[1] = y;
            z = *(f32 *)((u8 *)src + 0x8) + direction[2] * weight1;
            out[2] = z;
            direction = (f32 *)((u8 *)directions + c * 12);
            src += 0x10;
            out[0] = x + direction[0] * weight2;
            out[1] = y + direction[1] * weight2;
            out[2] = z + direction[2] * weight2;
            out += 3;
        }
    }
    GXSetArray(9, base, 12);
    GXSetArray(13, *(void **)((u8 *)object + 0x28), 4);
    GXSetArray(14, *(void **)((u8 *)object + 0x24), 4);
    GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
}
void fn_802D41C8(void *arg0) {
    /* Binds this object's position, normal, and color vertex arrays, then submits its display list. */
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
    GXSetArray(0xA, *(void **)((char *)arg0 + 0x24), 3);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}
#pragma pop
/* Draw of vertex layout 30 (fn_802D5FE4's case 20): a textured surface with no
 * normals and no color array.  Bind its raw 12-byte position records (three
 * floats) and its 4-byte texture coordinates, then run the surface's prebuilt
 * display list; the lighting and color state come from the display list
 * fn_802D5F88 submitted just before.
 * Proposed name: drDrawSurfPosTex. */
void fn_802D422C(struct SurfDraw *surface) {
    GXSetArray(GX_VA_POS, surface->positions, 0xC); /* stride of the position records */
    GXSetArray(GX_VA_TEX0, surface->colors, 4);     /* stride of the texture coordinates */
    GXCallDisplayList(surface->displayList, surface->listSize);
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_802D4280(void *arg0) {
    /* Bind this surface's position, normal, and color vertex arrays, then submit its display list. */
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0x10);
    GXSetArray(0xA, *(void **)((char *)arg0 + 0x24), 3);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802D42E4(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    extern f32 lbl_80564FF0;
    register void *object = arg0;
    register volatile u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)(u32)fn_802CFF64(count * 12);
    s32 i;
    if (base == 0) {
        fn_802D4280(object);
        return;
    }
    {
        f32 (*directions)[3] = (f32 (*)[3])lbl_804DB068;
        f32 factor = lbl_80564FF0;
        register volatile f32 *out = base;
        for (i = 0; i < count; i++) {
            u8 a, b, c, d;
            f32 weight1, weight2;
            f32 *direction;
            f32 x, y, z;
            a = src[0xE];
            b = src[0xC];
            direction = (f32 *)((u8 *)directions + b * 12);
            weight1 = factor * (f32)a;
            c = src[0xD];
            d = src[0xF];
            weight2 = factor * (f32)d;
            x = *(f32 *)((u8 *)src + 0x0) + direction[0] * weight1;
            out[0] = x;
            y = *(f32 *)((u8 *)src + 0x4) + direction[1] * weight1;
            out[1] = y;
            z = *(f32 *)((u8 *)src + 0x8) + direction[2] * weight1;
            out[2] = z;
            direction = (f32 *)((u8 *)directions + c * 12);
            src += 0x10;
            out[0] = x + direction[0] * weight2;
            out[1] = y + direction[1] * weight2;
            out[2] = z + direction[2] * weight2;
            out += 3;
        }
    }
    GXSetArray(9, base, 12);
    GXSetArray(0xA, *(void **)((u8 *)object + 0x24), 3);
    GXSetArray(0xD, *(void **)((u8 *)object + 0x28), 4);
    GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
}
#pragma dont_inline reset
#pragma scheduling on
#pragma pop

#pragma opt_propagation off
void fn_802D4458(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    register void *object = arg0;
    register volatile u8 *src = *(u8 **)((u8 *)object + 0x20);
    s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)(u32)fn_802CFF64(count * 12);
    unsigned int i;
    if (base == 0) return;
    {
        f32 *out = base;
        for (i = 0; i < count; i++) {
            u8 a, b, c, d;
            f32 *dir1, *dir2;
            f32 weight2, weight1;
            a = src[0xE];
            b = src[0xC];
            dir1 = (f32 *)((u8 *)lbl_804DB068 + b * 12);
            weight1 = (1.0f / 255.0f) * (f32)a;
            c = src[0xD];
            d = src[0xF];
            weight2 = (1.0f / 255.0f) * (f32)d;
            out[0] = *(f32 *)((u8 *)src + 0x0) + dir1[0] * weight1;
            out[1] = *(f32 *)((u8 *)src + 0x4) + dir1[1] * weight1;
            out[2] = *(f32 *)((u8 *)src + 0x8) + dir1[2] * weight1;
            dir2 = (f32 *)((u8 *)lbl_804DB068 + c * 12);
            src += 0x10;
            out[0] += dir2[0] * weight2;
            out[1] += dir2[1] * weight2;
            out[2] += dir2[2] * weight2;
            out += 3;
        }
    }
    GXSetArray(9, base, 12);
    GXSetArray(0xB, *(void **)((u8 *)object + 0x24), 2);
    GXSetArray(0xD, *(void **)((u8 *)object + 0x28), 4);
    GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
}
#pragma opt_propagation reset
#pragma opt_unroll_loops off
/* Format-16 surface drawer (fn_802D5FE4 case 16): build a fresh position array by
 * displacing each weighted source vertex along the shared offset direction, queue
 * that transform for the next frame's streaming pass when there is room (or do it
 * inline when the queue is full), then bind the arrays and submit the prebuilt list. */
void fn_802D45C0(void *surface) {
    /* Source vertices of this layout: a position plus how far along lbl_804C56F0
       (the renderer's shared normalized offset direction) to push it. */
    struct WeightedPos { f32 x, y, z, weight; };
    extern s32 fn_802CFF64(s32);
    extern u8 lbl_804CEC3C[];
    extern f32 lbl_804C56F0[];
    register void *object = surface;
    register struct WeightedPos *src = ((struct SurfDraw *)object)->positions;
    register s32 count = ((struct SurfDraw *)object)->vertexCount;
    /* Fresh position array for this frame's vertices, 12 bytes each. */
    f32 *newPositions = (f32 *)(u32)fn_802CFF64(count * 12);
    s32 queueIndex;
    s32 didQueue;
    f32 *dst;
    s32 i;

    if (newPositions == 0) return;
    {
        register struct SurfXformQueue *queue = (struct SurfXformQueue *)lbl_804CEC3C;
        queueIndex = queue->queued;
        if (queueIndex < 0x400) {
            /* Room in the queue: fn_802D6C78 rebuilds the array from L2 cache
               before the list is drawn, so nothing is transformed here. */
            struct SurfXform *xform;
            queue->queued = queueIndex + 1;
            xform = &queue->entry[queueIndex];
            xform->count = count;
            xform->src = src;
            xform->dst = newPositions;
            xform->flag = 0;
            didQueue = 1;
        } else {
            didQueue = 0;
        }
        if (didQueue == 0) {
            /* Queue full: rebuild the array here instead. */
            dst = newPositions;
            for (i = count; i > 0; i--) {
                f32 weight = src->weight;
                dst[0] = src->x + lbl_804C56F0[0] * weight;
                dst[1] = src->y + lbl_804C56F0[1] * weight;
                dst[2] = src->z + lbl_804C56F0[2] * weight;
                src++;
                dst += 3;
            }
        }
    }
    GXSetArray(GX_VA_POS, newPositions, 0xC);
    GXSetArray(GX_VA_CLR0, ((struct SurfDraw *)object)->normals, 2);
    GXSetArray(GX_VA_TEX0, ((struct SurfDraw *)object)->colors, 4);
    GXCallDisplayList(((struct SurfDraw *)object)->displayList,
                      ((struct SurfDraw *)object)->listSize);
}
#pragma opt_unroll_loops reset

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802D479C(void *arg0) {
    s32 count = *(s32 *)((u8 *)arg0 + 0x1C);
    u8 *src = *(u8 **)((u8 *)arg0 + 0x20);
    f32 *base = (f32 *)fn_802CFF64(count * 12);
    f32 *out;
    s32 i;
    u8 *vertex;

    if (base != 0) {
        f32 *table = lbl_804CA308;
        out = base;
        vertex = src;
        for (i = 0; i < count; i++) {
            f32 a[3], b[3];
            f32 t0 = table[vertex[0x18]];
            f32 t1 = table[vertex[0x19]];
            a[1] = 0.0039215686f * (f32)*(s16 *)(vertex + 0xE);
            a[2] = 0.0039215686f * (f32)*(s16 *)(vertex + 0x10);
            a[0] = 0.0039215686f * (f32)*(s16 *)(vertex + 0xC);
            b[0] = 0.0039215686f * (f32)*(s16 *)(vertex + 0x12);
            b[1] = 0.0039215686f * (f32)*(s16 *)(vertex + 0x14);
            b[2] = 0.0039215686f * (f32)*(s16 *)(vertex + 0x16);
            out[0] = *(f32 *)(src + 0) + a[0] * t0;
            out[1] = *(f32 *)(src + 4) + a[1] * t0;
            out[2] = *(f32 *)(src + 8) + a[2] * t0;
            out[0] += b[0] * t1;
            out[1] += b[1] * t1;
            out[2] += b[2] * t1;
            vertex += 0x1C;
            src += 0x1C;
            out += 3;
        }
        GXSetArray(9, base, 0xC);
        GXSetArray(0xB, *(void **)((u8 *)arg0 + 0x24), 2);
        GXSetArray(0xD, *(void **)((u8 *)arg0 + 0x28), 4);
        GXCallDisplayList(*(void **)((u8 *)arg0 + 0x30), *(u32 *)((u8 *)arg0 + 0x2C));
    }
}

#pragma push
#pragma processor 750
void fn_802D4988(void *arg0) {
    extern s32 lbl_8055FE00;
    extern u8 lbl_804D2C40[];
    extern void PSQUATMultiply(void *, void *);
    struct SourceVertex { f32 x; f32 y; f32 z; s16 half0; s16 half1; u8 index0; u8 index1; u16 pad; };
    struct CacheEntry { s32 count; void *src; void *dst; s32 flag; };
    register void *object = arg0;
    register struct SourceVertex *src = *(struct SourceVertex **)((u8 *)object + 0x20);
    register s32 count;
    int index;
    s32 cached;
    f32 *base;

    PSQUATMultiply(lbl_804C56C0 + 9, src);
    count = *(s32 *)((u8 *)object + 0x1C);
    lbl_8055FE00 += count;
    base = (f32 *)fn_802CFF64(count * 12);
    if (base) {
        register u8 *cache = lbl_804D2C40;
        index = *(s32 *)(cache + 0x4000);
        if (index < 0x400) {
            struct CacheEntry *entry;
            *(s32 *)(cache + 0x4000) = index + 1;
            entry = (struct CacheEntry *)cache + index;
            entry->count = count;
            entry->src = src;
            entry->dst = base;
            entry->flag = 0;
            cached = 1;
        } else {
            register cached = 0;
        }
        if (!cached) {
            f32 factor = lbl_80564FF0;
            struct SourceVertex *vertex = src;
            f32 *out = base;
            s32 i;
            for (i = count; i > 0; i--) {
                s16 h0, h1;
                f32 t0, t1, y, z, x, a, b;
                h0 = vertex->half0;
                h1 = vertex->half1;
                t0 = lbl_804CA308[vertex->index0];
                t1 = lbl_804CA308[vertex->index1];
                y = src->y;
                z = src->z;
                x = src->x;
                a = factor * (f32)h0;
                b = factor * (f32)h1;
                vertex = (struct SourceVertex *)((u8 *)vertex + 0x14);
                src = (struct SourceVertex *)((u8 *)src + 0x14);
                out[0] = x;
                out[1] = y + a * t0 + b * t1;
                out[2] = z;
                out += 3;
            }
        }
        GXSetArray(9, base, 0xC);
        GXSetArray(0xB, *(void **)((u8 *)object + 0x24), 2);
        GXSetArray(0xD, *(void **)((u8 *)object + 0x28), 4);
        GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
    }
}
#pragma pop

#pragma pop

#pragma scheduling on
#pragma pop

#pragma push
#pragma processor 750
void fn_802D4C44(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    register void *object = arg0;
    register u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)(u32)fn_802CFF64(count * 12);
    register f32 *out = base;
    s32 i;
    f32 factor = lbl_80564FF0;
    f32 d0[3], d1[3], r[3];

    if (base != 0) {
        for (i = 0; i < count; i++) {
            f32 wA = factor * (f32)src[0xE];
            f32 wB = factor * (f32)src[0xF];
            f32 *first = (f32 *)((u8 *)lbl_804DB068 + src[0xC] * 12);
            f32 *second = (f32 *)((u8 *)lbl_804DB068 + src[0xD] * 12);
            f32 *t0p, *t1p;
            r[0] = *(f32 *)(src + 0) + first[0] * wA + second[0] * wB;
            r[1] = *(f32 *)(src + 4) + first[1] * wA + second[1] * wB;
            r[2] = *(f32 *)(src + 8) + first[2] * wA + second[2] * wB;
            d0[0] = factor * (f32)*(s16 *)(src + 0x10);
            d0[1] = factor * (f32)*(s16 *)(src + 0x12);
            d0[2] = factor * (f32)*(s16 *)(src + 0x14);
            t0p = &lbl_804CA308[src[0x1C]];
            t1p = &lbl_804CA308[src[0x1D]];
            r[0] += d0[0] * *t0p;
            r[1] += d0[1] * *t0p;
            r[2] += d0[2] * *t0p;
            d1[0] = factor * (f32)*(s16 *)(src + 0x16);
            d1[1] = factor * (f32)*(s16 *)(src + 0x18);
            d1[2] = factor * (f32)*(s16 *)(src + 0x1A);
            out[0] = r[0] + d1[0] * *t1p;
            out[1] = r[1] + d1[1] * *t1p;
            out[2] = r[2] + d1[2] * *t1p;
            src += 0x20;
            out += 3;
        }
        GXSetArray(9, base, 0xC);
        GXSetArray(0xB, *(void **)((u8 *)object + 0x24), 2);
        GXSetArray(0xD, *(void **)((u8 *)object + 0x28), 4);
        GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
    }
}
#pragma push
#pragma processor 750
void fn_802D4ECC(void *arg0) {
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma opt_common_subs off
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    extern f32 lbl_804CA308[];
    extern f32 lbl_80564FF0;
    register void *object = arg0;
    register u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)(u32)fn_802CFF64(count * 12);
    s32 i;
    volatile f32 sp8, spc, sp10;

    if (base != 0) {
        f32 factor = lbl_80564FF0;
        register f32 *out = base;
        for (i = 0; i < count; i++) {
            f32 wa = (f32)src[0xE], wb = (f32)src[0xF];
            f32 *first = (f32 *)((u8 *)lbl_804DB068 + src[0xC] * 12);
            f32 weightA = factor * wa;
            f32 y = *(f32 *)(src + 4) + first[1] * weightA;
            f32 *second = (f32 *)((u8 *)lbl_804DB068 + src[0xD] * 12);
            f32 weightB = factor * wb;
            f32 x = *(f32 *)(src + 0) + first[0] * weightA;
            f32 z = *(f32 *)(src + 8) + first[2] * weightA;
            f32 y2 = y + second[1] * weightB;
            f32 halfA = (f32)*(s16 *)(src + 0x10);
            f32 halfB = (f32)*(s16 *)(src + 0x12);
            u8 tableA = src[0x14];
            u8 tableB = src[0x15];
            f32 resultY = y2 + factor * (unsigned)halfA * lbl_804CA308[tableA]
                          + factor * halfB * lbl_804CA308[tableB];
            spc = y2;
            sp8 = x;
            sp10 = z;
            out[0] = x + second[0] * weightB;
            out[1] = resultY;
            out[2] = z + second[2] * weightB;
            src += 0x18;
            out += 3;
        }
        GXSetArray(9, base, 0xC);
        GXSetArray(0xB, *(void **)((u8 *)object + 0x24), 2);
        GXSetArray(0xD, *(void **)((u8 *)object + 0x28), 4);
        GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
    }
}
#pragma pop
void fn_802D50B4(void *arg0) {
    register u8 *src = *(u8 **)((u8 *)arg0 + 0x20);
    register s32 count = *(s32 *)((u8 *)arg0 + 0x1C);
    register void *object = arg0;
    f32 *base = (f32 *)fn_802CFF64(count * 12);
    s32 index;
    s32 cached;
    register s32 i;
    register f32 *out;

    if (base != 0) {
        register u8 *cache = lbl_804D6C44;
        index = *(s32 *)(cache + 0x4000);
        if (index < 0x400) {
            *(s32 *)(cache + 0x4000) = index + 1;
            *(s32 *)(cache + index * 0x10) = count;
            *(u8 **)(cache + index * 0x10 + 4) = src;
            *(f32 **)(cache + index * 0x10 + 8) = base;
            *(s32 *)(cache + index * 0x10 + 0xC) = 0;
            cached = 1;
        } else {
            cached = 0;
        }

        if (cached == 0) {
            f32 factor = lbl_80564FF0;
            out = base;
            i = count;
            if (i > 0) {
                for (; i > 0; i--) {
                    f32 scale = *(f32 *)(src + 0xC);
                    s16 half0 = *(s16 *)(src + 0x10);
                    s16 half1 = *(s16 *)(src + 0x12);
                    u8 index0 = src[0x14];
                    u8 index1 = src[0x15];
                    f32 y;
                    f32 x;
                    f32 first;
                    f32 z;
                    f32 second;
                    y = *(f32 *)(src + 0x4) + lbl_804C56F0[1] * scale;
                    x = *(f32 *)(src + 0x0) + lbl_804C56F0[0] * scale;
                    first = factor * (f32)half0;
                    y += first * lbl_804CA308[index0];
                    z = *(f32 *)(src + 0x8) + lbl_804C56F0[2] * scale;
                    second = factor * (f32)half1;
                    y += second * lbl_804CA308[index1];
                    out[0] = x;
                    src += 0x18;
                    out[1] = y;
                    out[2] = z;
                    out += 3;
                }
            }
        }

        GXSetArray(9, base, 0xC);
        GXSetArray(0xB, *(void **)((u8 *)object + 0x24), 2);
        GXSetArray(0xD, *(void **)((u8 *)object + 0x28), 4);
        GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
    }
}
#pragma pop
void fn_802D5270(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DAC48[];
    extern f32 lbl_80564FF0;
    s32 count = *(s32 *)((u8 *)arg0 + 0x1C);
    u8 *src = *(u8 **)((u8 *)arg0 + 0x20);
    f32 *dst = (f32 *)fn_802CFF64(count * 12);

    if (dst != 0) {
        f32 *out = dst;
        if (count > 0) {
            do {
                volatile f32 sp14[3];
                volatile f32 sp8[3];
                f32 f = lbl_80564FF0 * (f32)src[0xE];
                f32 *m1 = (f32 *)((u8 *)lbl_804DAC48 + ((s32)src[0xC] >> 2) * 0x30);
                f32 g = lbl_80564FF0 * (f32)src[0xF];
                f32 *m2 = (f32 *)((u8 *)lbl_804DAC48 + ((s32)src[0xD] >> 2) * 0x30);
                f32 sx, sy, sz;
                f32 ox, oy, oz;

                if ((u8 *)sp8 == src) {
                    sx = *(f32 *)(src + 0);
                    sy = *(f32 *)(src + 4);
                    sz = *(f32 *)(src + 8);
                    sp8[0] = sz * m1[6] + (sx * m1[0] + sy * m1[3]);
                    sp8[1] = sz * m1[7] + (sx * m1[1] + sy * m1[4]);
                    sp8[2] = sz * m1[8] + (sx * m1[2] + sy * m1[5]);
                } else {
                    sp8[0] = *(f32 *)(src + 8) * m1[6] + (*(f32 *)(src + 0) * m1[0] + *(f32 *)(src + 4) * m1[3]);
                    sp8[1] = *(f32 *)(src + 8) * m1[7] + (*(f32 *)(src + 0) * m1[1] + *(f32 *)(src + 4) * m1[4]);
                    sp8[2] = *(f32 *)(src + 8) * m1[8] + (*(f32 *)(src + 0) * m1[2] + *(f32 *)(src + 4) * m1[5]);
                }
                sp8[0] += m1[9];
                sp8[1] += m1[10];
                sp8[2] += m1[11];

                if ((u8 *)sp14 == src) {
                    sx = *(f32 *)(src + 0);
                    sy = *(f32 *)(src + 4);
                    sz = *(f32 *)(src + 8);
                    sp14[0] = sz * m2[6] + (sx * m2[0] + sy * m2[3]);
                    sp14[1] = sz * m2[7] + (sx * m2[1] + sy * m2[4]);
                    sp14[2] = sz * m2[8] + (sx * m2[2] + sy * m2[5]);
                } else {
                    sp14[0] = *(f32 *)(src + 8) * m2[6] + (*(f32 *)(src + 0) * m2[0] + *(f32 *)(src + 4) * m2[3]);
                    sp14[1] = *(f32 *)(src + 8) * m2[7] + (*(f32 *)(src + 0) * m2[1] + *(f32 *)(src + 4) * m2[4]);
                    sp14[2] = *(f32 *)(src + 8) * m2[8] + (*(f32 *)(src + 0) * m2[2] + *(f32 *)(src + 4) * m2[5]);
                }
                sp14[0] += m2[9];
                sp14[1] += m2[10];
                sp14[2] += m2[11];

                ox = sp8[0] * f;
                out[0] = ox;
                oy = sp8[1] * f;
                out[1] = oy;
                oz = sp8[2] * f;
                out[2] = oz;
                out[0] = ox + sp14[0] * g;
                out[1] = oy + sp14[1] * g;
                out[2] = oz + sp14[2] * g;
                src += 0x10;
                out += 3;
            } while (--count != 0);
        }
        GXSetArray(9, dst, 12);
        GXSetArray(10, *(void **)((u8 *)arg0 + 0x24), 3);
        GXSetArray(13, *(void **)((u8 *)arg0 + 0x28), 4);
        GXCallDisplayList(*(void **)((u8 *)arg0 + 0x30), *(u32 *)((u8 *)arg0 + 0x2C));
    }
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_802D5680(struct SurfDraw *surface) {
    /* Static draw of a surface laid out as positions plus s8 normals, with no
     * color array: bind its raw 16-byte position records (three floats plus the
     * four y-morph bytes GX never reads) and its 3-byte normals, then run the
     * surface's prebuilt display list.  fn_802D56D4 is the same draw for when
     * fn_802DAC64() reports the bone-handle allocator's status byte clear: it
     * y-morphs the positions into a scratch buffer first.
     * Proposed name: drDrawSurfPosNrm. */
    GXSetArray(GX_VA_POS, surface->positions, 0x10); /* stride of the position records */
    GXSetArray(GX_VA_NRM, surface->normals, 3);      /* stride of the s8 normals */
    GXCallDisplayList(surface->displayList, surface->listSize);
}
#pragma pop

extern s32 fn_802CFF64(s32);
extern f32 lbl_804DB068[];
extern f32 lbl_80564FF0;
extern f64 lbl_80564FF8;
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802D56D4(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    extern f32 lbl_80564FF0;
    register void *object = arg0;
    register volatile u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)fn_802CFF64(count * 12);
    s32 i;
    if (base == 0) {
        fn_802D5680(object);
        return;
    }
    {
        f32 (*directions)[3] = (f32 (*)[3])lbl_804DB068;
        f32 factor = lbl_80564FF0;
        register volatile f32 *out = base;
        for (i = 0; i < count; i++) {
            u8 a, b, c, d;
            f32 weight1, weight2;
            f32 *dirA, *dirB;
            f32 x, y, z;
            a = src[0xE];
            b = src[0xC];
            dirA = (f32 *)((u8 *)directions + b * 12);
            weight1 = factor * (f32)a;
            c = src[0xD];
            d = src[0xF];
            weight2 = factor * (f32)d;
            x = *(f32 *)((u8 *)src + 0x0) + dirA[0] * weight1;
            out[0] = x;
            y = *(f32 *)((u8 *)src + 0x4) + dirA[1] * weight1;
            out[1] = y;
            z = *(f32 *)((u8 *)src + 0x8) + dirA[2] * weight1;
            out[2] = z;
            dirB = (f32 *)((u8 *)directions + c * 12);
            src += 0x10;
            out[0] = x + dirB[0] * weight2;
            out[1] = y + dirB[1] * weight2;
            out[2] = z + dirB[2] * weight2;
            out += 3;
        }
    }
    GXSetArray(9, base, 12);
    GXSetArray(10, *(void **)((u8 *)object + 0x24), 3);
    GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
}
#pragma dont_inline reset
#pragma scheduling on

extern f32 *fn_802D2D04(void);
extern f32 PSVECDotProduct(const f32 *, const f32 *);
extern void GXSetCullMode(u32);
extern void GXSetBlendMode(u32,u32,u32,u32);
extern f32 lbl_804C5690[9];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802D5838(void *arg0)
{
  f32 *dst; f32 *src; f32 *norm; s32 count; f32 new_var; f32 *base; s32 i; f32 *m; f32 v[3]; f32 *L; f32 thresh; s32 cull;
  count = *((s32 *) (((u8 *) arg0) + 0x1C));
  src = *((f32 **) (((u8 *) arg0) + 0x20));
  norm = *((f32 **) (((u8 *) arg0) + 0x24));
  base = (f32 *) fn_802CFF64(count * 12);
  if (base)
  {
    m = fn_802D2D04();
    L = lbl_804C5690;
    if (v == m)
    {
      f32 a0, a1, a2;
      f32 l0, l1, l2, l3, l4, l5, l6, l7, l8;
      f32 o0, o1, o2;
      l1 = L[1]; l4 = L[4]; l7 = L[7];
      l0 = L[0]; l3 = L[3]; l6 = L[6];
      l2 = L[2]; l5 = L[5]; l8 = L[8];
      a0 = m[0]; a1 = m[1]; a2 = m[2];
      o0 = (a2 * l2) + ((a0 * l0) + (a1 * l1));
      o1 = (a2 * l5) + ((a0 * l3) + (a1 * l4));
      o2 = (a2 * l8) + ((a0 * l6) + (a1 * l7));
      v[0] = o0;
      v[1] = o1;
      v[2] = o2;
    }
    else
    {
      f32 l0, l1, l2, l3, l4, l5, l6, l7, l8;
      l1 = L[1]; l0 = L[0]; l2 = L[2]; l4 = L[4]; l3 = L[3]; l5 = L[5]; l7 = L[7]; l6 = L[6]; l8 = L[8];
      v[0] = (m[2] * l2) + ((m[0] * l0) + (m[1] * l1));
      v[1] = (m[2] * l5) + ((m[1] * l4) + (m[0] * l3));
      new_var = m[1];
      v[2] = (m[2] * l8) + ((m[0] * l6) + (new_var * l7));
    }
    thresh = lbl_80565008;
    dst = base;
    for (i = 0; i < count; i++)
    {
      if (PSVECDotProduct(norm, v) < thresh)
      {
        f32 k = lbl_8055FDE0;
        dst[0] = src[0] + (v[0] * k);
        dst[1] = src[1] + (v[1] * k);
        dst[2] = src[2] + (v[2] * k);
      }
      else { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
      norm += 3; src += 3; dst += 3;
    }
    GXSetArray(9, base, 12);
    cull = 1; if (lbl_8055FDE4) cull = 2;
    GXSetCullMode(cull);
    GXSetBlendMode(1, 1, 1, 5);
    GXCallDisplayList(*((void **) (((u8 *) arg0) + 0x30)), *((u32 *) (((u8 *) arg0) + 0x2C)));
    cull = 2; if (lbl_8055FDE4) cull = 1;
    GXSetCullMode(cull);
    GXSetBlendMode(3, 1, 1, 5);
    GXCallDisplayList(*((void **) (((u8 *) arg0) + 0x30)), *((u32 *) (((u8 *) arg0) + 0x2C)));
  }
}
#pragma pop
void fn_802D5ACC(void *surface) {
    struct DrawData {
        u8 pad0[0x20];
        void *array0;
        void *array1;
        void *array2;
        u32 size;
        void *list;
        u32 pad34;
        f32 rot0;
        f32 rot1;
    };
    register struct DrawData *data = (struct DrawData *)surface;
    register void *array = data->array0;
    f32 matrix[3][4];

    /* Set up vertex arrays and two rotated position matrices, draw the display list, then mark draw state active. */
    GXSetArray(9, array, 0xC);
    GXSetArray(0xB, data->array1, 2);
    GXSetArray(0xD, data->array2, 4);

    PSMTXRotTrig(lbl_804C5650, matrix, data->rot0, lbl_80565008, lbl_80565008);
    GXLoadPosMtxImm(matrix, 3);
    PSMTXRotTrig(lbl_804C5650, matrix, data->rot1, lbl_80565008, lbl_80565008);
    GXLoadPosMtxImm(matrix, 6);

    GXCallDisplayList(data->list, data->size);
    lbl_8055FD19 = 1;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802D5B8C(void *arg0) {
    s32 count = *(s32 *)((char *)arg0 + 0x1C);
    u32 *colors = (u32 *)fn_802CFF64(count * 4);
    f32 *uvs = (f32 *)fn_802CFF64(count * 8);
    if (colors != 0 && uvs != 0) {
        f32 *pos = *(f32 **)((char *)arg0 + 0x20);
        u32 *srcColor = *(u32 **)((char *)arg0 + 0x24);
        f32 d0 = lbl_804C56C0[9] - lbl_804C5690[9];
        f32 d1 = lbl_804C56C0[10] - lbl_804C5690[10];
        u32 *outC = colors;
        f32 *srcUv = *(f32 **)((char *)arg0 + 0x28);
        f32 d2 = lbl_804C56C0[11] - lbl_804C5690[11];
        f32 vec[5];
        f64 uRaw = lbl_804DB068[3];
        f64 vRaw = lbl_804DB068[4];
        f32 offU = (f32)uRaw;
        f32 offV = (f32)vRaw;
        f32 *outUv = uvs;
        f32 scale = lbl_804DB068[5];
        f32 one = lbl_8056500C;
        s32 i;
        vec[0] = (f32)uRaw;
        vec[1] = (f32)vRaw;
        vec[2] = d0 * lbl_804C5690[0] + d1 * lbl_804C5690[1] + d2 * lbl_804C5690[2];
        vec[3] = d0 * lbl_804C5690[3] + d1 * lbl_804C5690[4] + d2 * lbl_804C5690[5];
        vec[4] = d0 * lbl_804C5690[6] + d1 * lbl_804C5690[7] + d2 * lbl_804C5690[8];
        for (i = 0; i < count; i++) {
            f32 factor = one - PSVECSquareDistance(pos, &vec[2]) * scale;
            u32 c = *srcColor;
            s32 a;
            if ((s32)((f32)(u8)c * factor) > 0) a = (s32)((f32)(u8)c * factor);
            else a = 0;
            if (a > 0xFF) a = 0xFF;
            *outC = (c & ~0xFF) | (a & 0xFF);
            pos += 3;
            srcColor++;
            outC++;
            outUv[0] = srcUv[0] + offU;
            outUv[1] = srcUv[1] + offV;
            srcUv += 2;
            outUv += 2;
        }
        GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
        GXSetArray(0xB, colors, 4);
        GXSetArray(0xD, uvs, 8);
        GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
    }
}
#pragma pop

/* Build and set the GX vertex descriptor list for an indexed display list from
 * the surface attribute flags: PNMTXIDX is direct, POS/NRM/CLR0/TEX0/TEX1 are
 * INDEX8 or INDEX16 per flag, terminated by GX_VA_NULL. */
void fn_802D5DE8(u32 flags) {
    int vtxDescList[54];
    int *desc;
    memset(vtxDescList, 0, 0xD8);
    desc = vtxDescList;
    if (flags & 1) { desc[0] = GX_VA_PNMTXIDX; desc[1] = GX_DIRECT; desc += 2; }
    if (flags & 2) { desc[0] = GX_VA_POS; desc[1] = GX_INDEX8; desc += 2; }
    else if (flags & 4) { desc[0] = GX_VA_POS; desc[1] = GX_INDEX16; desc += 2; }
    if (flags & 8) { desc[0] = GX_VA_NRM; desc[1] = GX_INDEX8; desc += 2; }
    else if (flags & 0x10) { desc[0] = GX_VA_NRM; desc[1] = GX_INDEX16; desc += 2; }
    if (flags & 0x20) { desc[0] = GX_VA_CLR0; desc[1] = GX_INDEX8; desc += 2; }
    else if (flags & 0x40) { desc[0] = GX_VA_CLR0; desc[1] = GX_INDEX16; desc += 2; }
    if (flags & 0x80) { desc[0] = GX_VA_TEX0; desc[1] = GX_INDEX8; desc += 2; }
    else if (flags & 0x100) { desc[0] = GX_VA_TEX0; desc[1] = GX_INDEX16; desc += 2; }
    if (flags & 0x200) { desc[0] = GX_VA_TEX1; desc[1] = GX_INDEX8; desc += 2; }
    else if (flags & 0x400) { desc[0] = GX_VA_TEX1; desc[1] = GX_INDEX16; desc += 2; }
    desc[0] = GX_VA_NULL; desc[1] = GX_NONE;
    GXClearVtxDesc();
    GXSetVtxDescv(vtxDescList);
}

#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802D5F88(s32 arg0) {
    u32 flags = *(u32 *)((u8 *)arg0 + 0xC);
    u32 normalized = flags & 0xFFCFFFFF;
    u8 mode = *(u8 *)((u8 *)arg0 + 9);
    if (normalized != lbl_8055FDE8) {
        GXCallDisplayList(*(void **)((u8 *)arg0 + 0x10), (u32)*(u8 *)((u8 *)arg0 + 0xB) << 5);
        lbl_8055FDE8 = normalized;
        lbl_8055FDEC = mode;
    }
}

#pragma push
#pragma dont_inline on
#pragma push
#pragma opt_lifetimes off
/* Dispatches surface drawing to the routine for the descriptor's vertex layout byte (+8, numbered from 10), warning on unsupported layouts. */ void fn_802D5FE4(void *arg0) {
    /* Dispatch display-list surface drawing by the surface descriptor's vertex format
       (byte at +8, numbered from 10); some formats fall back to conventional handling. */
    register void *surface = arg0;
    register int layout;
    fn_802D5F88((s32)surface);
    layout = (int)((u8 *)surface)[8];
    switch (layout - 10) {
    case 0: fn_802D41C8(surface); break;
    case 4: if (fn_802DAC64()) fn_802D4280(surface); else fn_802D42E4(surface); break;
    case 9: fn_802D4458(surface); break;
    case 16: fn_802D45C0(surface); break;
    case 17: fn_802D50B4(surface); break;
    case 5: fn_802D5270(surface); break;
    case 1: drDrawSurfLayout11(surface); break;
    case 18: drDrawSurfLayout28(surface); break;
    case 2: drDrawSurfLayout12(surface); break;
    case 3: fn_802D4060(surface); break;
    case 6:
    case 8: if (fn_802DAC64()) fn_802D5680(surface); else fn_802D56D4(surface); break;
    case 7: fn_802D5838(surface); break;
    case 10: fn_802D5ACC(surface); break;
    case 11: fn_802D479C(surface); break;
    case 14: fn_802D4988(surface); break;
    case 12: fn_802D4C44(surface); break;
    case 15: fn_802D4ECC(surface); break;
    case 13: fn_802D5B8C(surface); break;
    case 19: fn_802E317C(lbl_8034C2F8); break;
    case 20: fn_802D422C(surface); break;
    default: fn_802E317C(lbl_8034C334, layout); break;
    }
}
#pragma pop
extern void fn_802D0E48(int);
/* Draw a surface: toggle the draw state, configure its vertex format, then submit its display list. */
void fn_802D6170(struct SurfDraw *surface) {
    fn_802D0E48(0);
    fn_802D5FE4(surface);
    fn_802D0E48(1);
    GXCallDisplayList(surface->displayList, surface->listSize);
}

#pragma pop

/* Update surface state/mode flags from a command packet and apply cache-related side effects. */
/* Apply a surface state command: packet byte 8 selects the pipeline, byte 0xA carries lighting (bit 3), detail-texture (bit 4) and pipeline-class (bits 0-1) flags, and byte 0x14 is an address compared against lbl_8055FD28; then rebuild GX state. */ void fn_802D61BC(void *packet) {
    extern u8 lbl_804C5700[16];
    extern s32 lbl_8055FD20;
    extern volatile u8 lbl_8055FD25;
    extern u32 lbl_8055FD28;
    extern u8 lbl_8055FDFC;
    extern void fn_802D2614(void);
    extern void fn_802D2B0C(void);
    u8 *cmd = (u8 *)packet;
    u8 stateFlags;
    u8 detailTexMode;

    lbl_8055FD25 = (*(u8 *)(cmd + 0xA) >> 3) & 1;
    detailTexMode = (*(u8 *)(cmd + 0xA) >> 4) & 1;
    *(volatile s32 *)(lbl_804C5700 + 4) = 6;
    lbl_804C5700[9] = detailTexMode;

    switch (*(u8 *)(cmd + 8)) {
    case 16:
        *(s32 *)(lbl_804C5700 + 4) = 2;
        break;
    case 18:
        *(s32 *)(lbl_804C5700 + 4) = 1;
        break;
    default:
        stateFlags = *(u8 *)(cmd + 0xA);
        if (stateFlags & 1) {
            *(s32 *)(lbl_804C5700 + 4) = 3;
        } else if (stateFlags & 2) {
            if (lbl_8055FDFC != 0)
                *(s32 *)(lbl_804C5700 + 4) = 5;
            else
                *(s32 *)(lbl_804C5700 + 4) = 4;
        } else {
            *(s32 *)(lbl_804C5700 + 4) = 0;
        }
        break;
    }

    if (*(u8 *)(cmd + 0xA) & 4) {
        if (lbl_8055FD28 != *(u32 *)(cmd + 0x14))
            lbl_8055FD20 |= 0x20;
        lbl_8055FD28 = *(u32 *)(cmd + 0x14);
    }

    fn_802D2614();
    fn_802D2B0C();
}

#pragma scheduling on
/* Return the object pointer only if its first word is the surface magic
 * 0x4E444C32 (tested as word + 0xB1BC0000 == 0x4C32); otherwise return 0. */
s32 fn_802D62E4(void *object) {
    if ((u32)(*(u32 *)object + 0xB1BC0000) != 0x4C32U) {
        return 0;
    }
    return (s32)object;
}

#pragma scheduling on
/* Look up (or build) the cached vertex-format display list for this surface:
 * the cache is keyed by the descriptor's format byte and flag word.  A hit
 * returns the stored list offset and size; a miss records a new GX display
 * list into the shared buffer and appends it to the cache. */
void fn_802D62FC(void *__restrict surface, s32 *outOffset, s32 *outSize) {
#define vertexFormatCache   lbl_804CA438
#define vertexFormatCount   lbl_8055FDF0
#define vertexFormatDlStart lbl_8055FDF4
#define vertexFormatDlEnd   lbl_8055FDF8
#define setVtxDescFromFlags fn_802D5DE8
    extern s32 lbl_8055FDF0;
    extern s32 lbl_8055FDF4;
    extern s32 lbl_8055FDF8;
    extern void GXBeginDisplayList(void *, u32);
    extern u32 GXEndDisplayList(void);
    extern void fn_802D5DE8(u32);
    register u8 *desc = (u8 *)surface;
    register CacheEntry *scan = (CacheEntry *)vertexFormatCache;
    register u8 key = desc[9];
    register u32 id = *(u32 *)(desc + 0xC);
    s32 count = vertexFormatCount;
    s32 i;
    CacheEntry *write;
    s32 size;

    /* Cache key is the surface descriptor's format byte (key) and flag word (id). */
    for (i = 0; i < count; i++, scan++) {
        if (scan->id == id && scan->key == key) {
            *outOffset = scan->start;
            *outSize = scan->size;
            return;
        }
    }

    count = vertexFormatCount;
    write = (CacheEntry *)vertexFormatCache + count;
    write->id = id;
    vertexFormatCount = count + 1;
    write->key = key;
    GXBeginDisplayList((void *)vertexFormatDlEnd, vertexFormatDlStart + 0x4000 - vertexFormatDlEnd);
    setVtxDescFromFlags(id);
    size = GXEndDisplayList();
    write->start = vertexFormatDlEnd;
    write->size = size;
    vertexFormatDlEnd += size;
    *outOffset = write->start;
    *outSize = write->size;
#undef setVtxDescFromFlags
#undef vertexFormatDlEnd
#undef vertexFormatDlStart
#undef vertexFormatCount
#undef vertexFormatCache
}
#pragma push
#pragma use_lmw_stmw off
void fn_802D63FC(void *arg0, s32 arg1) {
    extern void fn_802D62FC(void *, s32 *, s32 *);
    extern void fn_802D657C(s32 *, s32);
    u8 *p = (u8 *)arg0;
    register u8 *p20;
    s32 sp1C, sp18, sp14, sp10, spC;
    unsigned sp8;
    u8 temp_r0, temp_r0_2, temp_r0_3, temp_r0_4, temp_r0_5;
    u8 b2B, b26, b27, b22, b23, b1E, b1F, b1B, b11, b0D, b19, b29, b25, b21, b1D, b10, b0C, b18, b28, b24, b20, b1C;
    temp_r0 = p[0x1A];
    p20 = p + 0x20;
    b19 = p[0x19];
    sp1C = temp_r0;
    temp_r0_2 = p[0x0F];
    b0C = p[0x0C];
    spC = temp_r0_2;
    temp_r0_3 = p[0x0E];
    b0D = p[0x0D];
    sp10 = temp_r0_3;
    temp_r0_4 = p[0x13];
    b10 = p[0x10];
    sp14 = temp_r0_4;
    temp_r0_5 = p[0x12];
    b11 = p[0x11];
    sp18 = temp_r0_5;
    b1C = p[0x1C];
    b1F = p[0x1F];
    b1D = p[0x1D];
    b1E = p[0x1E];
    b20 = p20[0];
    b23 = p20[3];
    b21 = p20[1];
    b22 = p20[2];
    b24 = p[0x24];
    b27 = p[0x27];
    b25 = p[0x25];
    b26 = p[0x26];
    b28 = p[0x28];
    b2B = p[0x2B];
    b29 = p[0x29];
    b18 = p[0x18];
    b1B = p[0x1B];
    p[0x19] = (u8)sp1C;
    p[0x0C] = (u8)spC;
    p[0x10] = (u8)sp14;
    p[0x0D] = (u8)sp10;
    p[0x1C] = b1F;
    p[0x1D] = b1E;
    p[0x1E] = b1D;
    p[0x20] = b23;
    p[0x1F] = b1C;
    p[0x21] = b22;
    p[0x23] = b20;
    p[0x22] = b21;
    p[0x24] = b27;
    p[0x27] = b24;
    p[0x26] = b25;
    p[0x25] = b26;
    p[0x2B] = b28;
    p[0x28] = b2B;
    p[0x29] = p[0x2A];
    p[0x2A] = b29;
    p[0x18] = b1B;
    p[0x1B] = b18;
    p[0x1A] = b19;
    p[0x0F] = b0C;
    p[0x0E] = b0D;
    p[0x13] = b10;
    p[0x11] = (u8)sp18;
    p[0x12] = b11;
    fn_802D657C((s32 *)p20, arg1);
    fn_802D657C((s32 *)(p20 + 4), arg1);
    fn_802D657C((s32 *)(p20 + 8), arg1);
    fn_802D62FC(arg0, (s32 *)(p + 0x10), (s32 *)&sp8);
    sp8 = sp8 >> 5U;
    p[0x0B] = (u8)sp8;
}
#pragma pop
void fn_802D657C(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802D6594(void *arg0) {
    /* Byte-swap the 4-byte header at +0x34..+0x37 and each 4-byte element in the
     * data block at +0x38 (count taken from the header at +0x34). */
    unsigned char *base = (unsigned char *)arg0;
    unsigned char swappedByte = base[0x34];
    unsigned char *element = base + 0x38;
    unsigned char headerByte = base[0x35];
    int elementIndex;
    unsigned char tempByte;

    base[0x34] = base[0x37];
    base[0x37] = swappedByte;
    base[0x35] = base[0x36];
    base[0x36] = headerByte;
    for (elementIndex = 0; elementIndex < *(int *)(base + 0x34); elementIndex++) {
        swappedByte = element[0];
        tempByte = element[3];
        element[0] = tempByte;
        element[3] = swappedByte;
        swappedByte = element[1];
        tempByte = element[2];
        element[1] = tempByte;
        element[2] = swappedByte;
        element += 4;
    }
}

extern const char lbl_8034C3B4[];
extern f32 lbl_80565010;
extern f32 lbl_80565014;
void fn_802D65F8(s32 arg0, s32 arg1) {
    volatile u8 *bytes=(volatile u8 *)arg0;
    u8 a,b,c,d,e,f,g,h;
    s32 i;
    u8 *entries;
    extern void fn_802D63FC(void *,s32);
    fn_802D63FC((void *)arg0,arg1);
    a=bytes[0x2C]; b=bytes[0x2F]; c=bytes[0x2D]; d=bytes[0x2E];
    e=bytes[0x30]; f=bytes[0x33]; g=bytes[0x31]; h=bytes[0x32];
    bytes[0x2C]=b; bytes[0x2F]=a; bytes[0x2D]=d; bytes[0x2E]=c;
    bytes[0x30]=f; bytes[0x33]=e; bytes[0x31]=h; bytes[0x32]=g;
    ((void (*)(s32 *, s32, u8, u8, u8, u8, u8, u8))fn_802D657C)((s32 *)((u8 *)arg0+0x30),arg1,f,d,b,a,e,c);
    if((s8)bytes[8]==0x1A) fn_802D6594((void *)bytes);
    if(bytes[8]==0x13) {
        entries=*(u8 **)(bytes+0x20);
        for(i=0;i<*(s32 *)(bytes+0x1C);i++) {
            if((entries[0xC]!=0x4C && entries[0xC]!=0x4D) || entries[0xD]!=0) goto second;
            entries+=0x10;
        }
        fn_802E317C(lbl_8034C3B4);
        bytes[8]=0x1A;
        entries=*(u8 **)(bytes+0x20);
        {
            f32 factor = lbl_80565010;
            f32 divisor = lbl_80565014;
            for(i=0;i<*(s32 *)(bytes+0x1C);++i) {
                f32 value=factor*(f32)entries[0xE]/divisor;
                if (entries[0xC]==0x4C) *(f32 *)(entries+0xC)=value;
                else *(f32 *)(entries+0xC)=-value;
                entries+=0x10;
            }
        }
    }
second:
    if(bytes[8]==0x19) {
        entries=*(u8 **)(bytes+0x20);
        for(i=0;i<*(s32 *)(bytes+0x1C);i++) {
            if((entries[0xC]!=0x4C && entries[0xC]!=0x4D) || entries[0xD]!=0) goto done;
            entries+=0x18;
        }
        bytes[8]=0x1B;
        entries=*(u8 **)(bytes+0x20);
        {
            f32 factor = lbl_80565010;
            f32 divisor = lbl_80565014;
            for(i=0;i<*(s32 *)(bytes+0x1C);++i) {
                f32 value=factor*(f32)entries[0xE]/divisor;
                if (entries[0xC]==0x4C) *(f32 *)(entries+0xC)=value;
                else *(f32 *)(entries+0xC)=-value;
                entries+=0x18;
            }
        }
    }
done: ;
}

#pragma push
#pragma small_data off
/* Allocate the 0x4000-byte vertex-format display-list buffer and reset the vertex-format state. */
void fn_802D6810(void) {
    void *displayListBuffer;

    /* Initialize the vertex-format display list buffer and reset its state. */
    lbl_8055FDF0 = 0;
    fn_801282EC(0x20);
    displayListBuffer = fn_8012850C(0x4000, lbl_8034C3DC);
    lbl_8055FDF4 = (s32)displayListBuffer;
    lbl_8055FDF8 = (s32)displayListBuffer;
    DCInvalidateRange(displayListBuffer, 0x4000);
    fn_802D6C68();
}
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern void fn_802E30C8(const char *, ...);
extern void fn_80128670(s32);
#pragma scheduling invalid_target
void fn_802D6860(void) {
    s32 savedYmorphVertCount;
    /* Finalize vertex-format display list logging/cleanup, then report total ymorph verts. */
#define vertexFormatDlStart lbl_8055FDF4
#define vertexFormatDlEnd lbl_8055FDF8
#define vertexFormatCount lbl_8055FDF0
#define totalYmorphVerts lbl_8055FE00
#define logVertexFormatDlMsg lbl_8034C3F4
#define logTotalYmorphVertsMsg lbl_8034C428

    fn_802E30C8(logVertexFormatDlMsg, vertexFormatDlEnd - vertexFormatDlStart, vertexFormatCount);
    fn_80128670(vertexFormatDlStart);
    savedYmorphVertCount = totalYmorphVerts;
    vertexFormatDlStart = 0;
    vertexFormatDlEnd = 0;
    fn_802E30C8(logTotalYmorphVertsMsg, savedYmorphVertCount);

#undef vertexFormatDlStart
#undef vertexFormatDlEnd
#undef vertexFormatCount
#undef totalYmorphVerts
#undef logVertexFormatDlMsg
#undef logTotalYmorphVertsMsg
}
#pragma scheduling on
/* Update a surface: do common work, then dispatch to the flagged or default path based on lbl_8055FD1C bit 3. */
void fn_802D6B08(void *arg0) {
    fn_802D61BC(arg0);
    if (lbl_8055FD1C & 8) {
        fn_802D6170(arg0);
        return;
    }
    fn_802D5FE4(arg0);
}

#pragma pop
extern s32 fn_802D62E4(void *);
/* Periodic callback: filter the alarm, then apply the resulting display-list update. */
void fn_802D6B54(void *alarm) {
    fn_802D5F88(((s32 (*)(void *))fn_802D62E4)(alarm));
}


extern s32 lbl_8055FD1C;
/* Default (non-CPU-lighting) surface redraw callback: forwards the surface
 * descriptor to fn_802D5FE4, which dispatches drawing by its vertex format. */
void fn_802D6B78(void *surface) {
    fn_802D5FE4(surface);
}

/* CPU-lighting callback thunk: forwards to fn_802D6170 to rebuild and draw
 * this light-map surface's display list. */
void fn_802D6B7C(void *surface) {
    fn_802D6170(surface);
}

extern void fn_802D65F8(s32, s32);
extern void fn_802E317C(const char *, ...);
extern const char lbl_8034C440[];
#pragma scheduling invalid_target
/* LoadSurface: byte-swap a surface's 4-byte type code in place; convert it if the format is known, otherwise panic reporting the bad type as a string. */ void fn_802D6B80(u8 *surface, s32 modelBase, s32 name) {
    extern s32 fn_802D62E4(void *);
    extern void fn_802D65F8(s32, s32);
    extern void fn_802E317C(const char *, ...);
    extern const char lbl_8034C440[];
#define IsKnownSurfFormat fn_802D62E4
#define ConvertSurfData   fn_802D65F8
#define Panic             fn_802E317C
#define kBadSurfTypeMsg   lbl_8034C440 /* "gx: %s has bad surf type %s" */
    /* RealName: LoadSurface. Byte-swap a model surface's 4-byte type code; if it
       is the supported format convert the surface data in place, otherwise
       panic reporting the offending type as a string. */
    union Buf { u32 word; u8 bytes[5]; } buf;
    s32 format;
    u8 tmp;
    tmp = surface[0];
    surface[0] = surface[3];
    surface[3] = tmp;
    tmp = surface[1];
    surface[1] = surface[2];
    surface[2] = tmp;
    format = IsKnownSurfFormat(surface);
    if (format != 0) {
        ((void (*)(s32, s32, s32))ConvertSurfData)(format, modelBase, name);
    } else {
        u8 *p = buf.bytes;
        u8 x, y;
        buf.word = *(u32 *)surface;
        x = p[0];
        p[0] = p[3];
        p[3] = x;
        y = p[1];
        p[1] = p[2];
        p[2] = y;
        buf.bytes[4] = 0;
        Panic(kBadSurfTypeMsg, name, &buf);
    }
#undef IsKnownSurfFormat
#undef ConvertSurfData
#undef Panic
#undef kBadSurfTypeMsg
}
#pragma scheduling on
void fn_802D6C44(void) {
    /* No-op per-group hook passed to VisitGroupIds during group-list traversal:
       the caller only needs to walk the groups, so this does nothing. */
}

/* No-op per-group hook passed to VisitGroupIds by mrModelRegisterTextures
 * (fn_802C6FA8) while it walks a model's group list: the traversal itself is
 * all the caller needs, so this does nothing. */
void fn_802D6C48(void) {
}

void fn_802D6C4C(f32 extrudeScale) {
    /* Set the global vertex-extrusion scale read by the surface drawers (fn_802D5838 offsets vertices along their normals by this amount). */
    lbl_8055FDE0 = extrudeScale;
}

extern float lbl_804CA308[];
/* Sets element @p index of the surf value table at lbl_804CA308 to @p value. */
void fn_802D6C54(int index, float value) {
    lbl_804CA308[index] = value;
}

void fn_802D6C68(void) {
    /* Invalidate the renderer's cached vertex-format descriptor and mode byte. */
#define sCachedFormat lbl_8055FDE8
#define sCachedMode   lbl_8055FDEC
    sCachedFormat = 0;
    sCachedMode = 0;
#undef sCachedMode
#undef sCachedFormat
}

#pragma inline on
#pragma dont_inline off
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802D6C78(void) {
    extern f32 lbl_804CA308[];
    extern f32 lbl_804DB068[];
    extern f32 lbl_804C56F0[];
    extern void LCLoadData(void*, const void*, unsigned long);
    extern void LCStoreData(void*, const void*, unsigned long);
    extern void LCQueueWait(unsigned long);
    unsigned char *g = (unsigned char *)lbl_804CA308;
    {
        unsigned char *base = g + 0x930;
        unsigned char *e = base;
        s32 i;
        for (i = 0; i < *(s32 *)(base + 0x4000); i++, e += 0x10) {
            s32 k;
            s32 count = *(s32 *)e;
            for (k = 0; k < count; k++) {
                unsigned char *s = *(unsigned char **)(e + 4) + k * 0x10;
                f32 *d = *(f32 **)(e + 8) + k * 3;
                f32 w1 = (1.0f / 255.0f) * (f32)s[0xE];
                f32 *db = (f32 *)((unsigned char *)lbl_804DB068 + s[0xC] * 0xC);
                f32 w2 = (1.0f / 255.0f) * (f32)s[0xF];
                unsigned char c = s[0xD];
                f32 *dc;
                f32 x, y, z;
                x = *(f32 *)(s + 0x0) + db[0] * w1;
                d[0] = x;
                y = *(f32 *)(s + 0x4) + db[1] * w1;
                d[1] = y;
                z = *(f32 *)(s + 0x8) + db[2] * w1;
                d[2] = z;
                dc = (f32 *)((unsigned char *)lbl_804DB068 + c * 0xC);
                d[0] = x + dc[0] * w2;
                d[1] = y + dc[1] * w2;
                d[2] = z + dc[2] * w2;
            }
        }
        *(s32 *)(base + 0x4000) = 0;
    }
    OSSetGQR6(7, 8);
    OSSetGQR6(7, 8);
    if (*(s32 *)(g + 0x8938 + 0x4000) != 0) {
        s32 chunkLeft;
        unsigned char *chunk;
        s32 rest;
        unsigned char *src;
        float *dst;
        s32 cur;
        void *lc;
        s32 toggle;
        s32 n;
        float *storedst;
        float *lcbuf;
        rest = *(s32 *)(g + 0x8938 + 0x0);
        chunkLeft = *(s32 *)(g + 0x8938 + 0x4000) - 1;
        src = *(unsigned char **)(g + 0x8938 + 0x4);
        chunk = g + 0x8938 + 0x10;
        dst = *(float **)(g + 0x8938 + 0x8);
        cur = rest <= 0x100 ? rest : 0x100;
        lc = (void *)0xE0000000;
        toggle = 1;
        LCLoadData((void *)0xE0000000, src, (unsigned long)(cur * 0x14));
        rest -= cur;
        src += cur * 0x14;
        n = 0;
        storedst = 0;
        lcbuf = 0;
        for (;;) {
            float *out;
            LCQueueWait(0);
            if (n > 0) LCStoreData(storedst, lcbuf, (unsigned long)(((n * 12) + 0x1F) & ~0x1F));
            storedst = dst;
            n = cur;
            lcbuf = (float *)lc;
            dst += cur * 3;
            if (rest == 0 && chunkLeft > 0) {
                rest = *(s32 *)(chunk + 0x0);
                chunkLeft--;
                src = *(unsigned char **)(chunk + 0x4);
                dst = *(float **)(chunk + 0x8);
                chunk += 0x10;
            }
            cur = rest <= 0x100 ? rest : 0x100;
            if (rest > 0) {
                void *nlc = (void *)((toggle << 13) + 0xE0000000);
                toggle = 1 - toggle;
                LCLoadData(nlc, src, (unsigned long)(((cur * 0x14) + 0x1F) & ~0x1F));
                src += cur * 0x14;
                rest -= cur;
                lc = nlc;
            }
            if (n == 0) break;
            out = (float *)((toggle << 13) + 0xE0001400);
            {
                s32 j;
                f32 *s = lcbuf;
                f32 *d = out;
                lcbuf = out;
                for (j = 0; j < n; j++) {
                    f32 z = s[2];
                    f32 y = s[1];
                    f32 x = s[0];
                    d[0] = x;
                    d[1] = y;
                    d[2] = z;
                    s += 5; d += 3;
                }
            }
        }
        LCQueueWait(0);
        *(s32 *)(g + 0x8938 + 0x4000) = 0;
    }
    OSSetGQR6(7, 8);
    if (*(s32 *)(g + 0xC93C + 0x4000) != 0) {
        s32 chunkLeft;
        unsigned char *chunk;
        s32 rest;
        unsigned char *src;
        float *dst;
        s32 cur;
        void *lc;
        s32 toggle;
        s32 n;
        float *storedst;
        float *lcbuf;
        rest = *(s32 *)(g + 0xC93C + 0x0);
        chunkLeft = *(s32 *)(g + 0xC93C + 0x4000) - 1;
        src = *(unsigned char **)(g + 0xC93C + 0x4);
        chunk = g + 0xC93C + 0x10;
        dst = *(float **)(g + 0xC93C + 0x8);
        cur = rest <= 0xE0 ? rest : 0xE0;
        lc = (void *)0xE0000000;
        toggle = 1;
        LCLoadData((void *)0xE0000000, src, (unsigned long)(cur * 0x18));
        rest -= cur;
        src += cur * 0x18;
        n = 0;
        storedst = 0;
        lcbuf = 0;
        for (;;) {
            float *out;
            LCQueueWait(0);
            if (n > 0) LCStoreData(storedst, lcbuf, (unsigned long)(((n * 12) + 0x1F) & ~0x1F));
            storedst = dst;
            n = cur;
            lcbuf = (float *)lc;
            dst += cur * 3;
            if (rest == 0 && chunkLeft > 0) {
                rest = *(s32 *)(chunk + 0x0);
                chunkLeft--;
                src = *(unsigned char **)(chunk + 0x4);
                dst = *(float **)(chunk + 0x8);
                chunk += 0x10;
            }
            cur = rest <= 0xE0 ? rest : 0xE0;
            if (rest > 0) {
                void *nlc = (void *)((toggle << 13) + 0xE0000000);
                toggle = 1 - toggle;
                LCLoadData(nlc, src, (unsigned long)(((cur * 0x18) + 0x1F) & ~0x1F));
                src += cur * 0x18;
                rest -= cur;
                lc = nlc;
            }
            if (n == 0) break;
            out = (float *)((toggle << 13) + 0xE0001500);
            {
                s32 j;
                unsigned char *s = (unsigned char *)lcbuf;
                float *d = out;
                lcbuf = out;
                for (j = 0; j < n; j++) {
                    f32 w1 = (1.0f / 255.0f) * (f32)*(s16 *)(s + 0x10);
                    f32 w2 = (1.0f / 255.0f) * (f32)*(s16 *)(s + 0x12);
                    FifoVec3 sc = *(FifoVec3 *)lbl_804C56F0;
                    f32 gg = *(f32 *)(s + 0xC);
                    FifoVec3 t;
                    t.x = *(f32 *)(s + 0x0) + sc.x * gg;
                    t.y = *(f32 *)(s + 0x4) + sc.y * gg;
                    t.z = *(f32 *)(s + 0x8) + sc.z * gg;
                    d[0] = t.x;
                    d[1] = t.y + w1 * ((f32 *)g)[s[0x14]] + w2 * ((f32 *)g)[s[0x15]];
                    d[2] = t.z;
                    s += 0x18; d += 3;
                }
            }
        }
        LCQueueWait(0);
        *(s32 *)(g + 0xC93C + 0x4000) = 0;
    }
    OSSetGQR6(7, 8);
    if (*(s32 *)(g + 0x4934 + 0x4000) != 0) {
        s32 chunkLeft;
        unsigned char *chunk;
        s32 rest;
        unsigned char *src;
        float *dst;
        s32 cur;
        void *lc;
        s32 toggle;
        s32 n;
        float *storedst;
        float *lcbuf;
        rest = *(s32 *)(g + 0x4934 + 0x0);
        chunkLeft = *(s32 *)(g + 0x4934 + 0x4000) - 1;
        src = *(unsigned char **)(g + 0x4934 + 0x4);
        chunk = g + 0x4934 + 0x10;
        dst = *(float **)(g + 0x4934 + 0x8);
        cur = rest <= 0x100 ? rest : 0x100;
        lc = (void *)0xE0000000;
        toggle = 1;
        LCLoadData((void *)0xE0000000, src, (unsigned long)(cur * 0x10));
        rest -= cur;
        src += cur * 0x10;
        n = 0;
        storedst = 0;
        lcbuf = 0;
        for (;;) {
            float *out;
            LCQueueWait(0);
            if (n > 0) LCStoreData(storedst, lcbuf, (unsigned long)(((n * 12) + 0x1F) & ~0x1F));
            storedst = dst;
            n = cur;
            lcbuf = (float *)lc;
            dst += cur * 3;
            if (rest == 0 && chunkLeft > 0) {
                rest = *(s32 *)(chunk + 0x0);
                chunkLeft--;
                src = *(unsigned char **)(chunk + 0x4);
                dst = *(float **)(chunk + 0x8);
                chunk += 0x10;
            }
            cur = rest <= 0x100 ? rest : 0x100;
            if (rest > 0) {
                void *nlc = (void *)((toggle << 13) + 0xE0000000);
                toggle = 1 - toggle;
                LCLoadData(nlc, src, (unsigned long)(((cur * 0x10) + 0x1F) & ~0x1F));
                src += cur * 0x10;
                rest -= cur;
                lc = nlc;
            }
            if (n == 0) break;
            out = (float *)((toggle << 13) + 0xE0001000);
            {
                s32 j;
                f32 *s = lcbuf;
                f32 *d = out;
                lcbuf = out;
                for (j = 0; j < n; j++) {
                    f32 z = s[2];
                    f32 y = s[1];
                    f32 x = s[0];
                    d[0] = x;
                    d[1] = y;
                    d[2] = z;
                    s += 4; d += 3;
                }
            }
        }
        LCQueueWait(0);
        *(s32 *)(g + 0x4934 + 0x4000) = 0;
    }
}
/* Set the global flag that swaps the two GX cull modes used when drawing surf surfaces. */
void fn_802D754C(u8 value) {
    lbl_8055FDE4 = value;
}

extern u8 lbl_8055FDFC;
void fn_802D7554(u8 value) {
    // Sets the global byte flag consulted by the surf packet handler (fn_802D61BC).
    lbl_8055FDFC = value;
}
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern void fn_802D5FE4(void *);
extern void fn_802E30C8(const char *, ...);
extern void fn_80128670(s32);

/* Draw an indexed triangle list by pushing its vertices straight into the GX
   FIFO.  The vertex array holds FifoVtx records and the index array says which
   of them to send, `count` of them as GX_TRIANGLES in vertex format 0, which is
   set up here to take position, color 0 and texture coordinate 0 directly from
   the FIFO.  Each color is rotated left by eight on the way out, and the
   renderer's own cached state is set to mode 0 and applied before the draw and
   cleared again after it.  The vertex count the callers pass is not used. */
/* Draw an indexed GX_TRIANGLES list by streaming FifoVtx records straight into the GX FIFO, after setting up vertex format 0 for direct position/colour0/texcoord0 and clearing the renderer's cached state around the draw. */ void drawFifoTriangles(FifoVtx *__restrict vertices, s32 vertexCount,
                 u16 *__restrict indices, s32 count) {
    register s32 i;

    lbl_8055FD25 = 0;
    lbl_804C5700[9] = 0;
    *(u32 *)(lbl_804C5700 + 4) = 0;
    fn_802D2614();
    fn_802D2B0C();
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXBegin(GX_TRIANGLES, GX_VTXFMT0, (u16)count);
    for (i = 0; i < count; i++) {
        register FifoVtx *vertex = &vertices[indices[i]];
        FifoVtx vtx;
        f32 x;
        f32 y;
        f32 z;
        vtx.pos = vertex->pos;
        vtx.color = vertex->color;
        vtx.u = vertex->u;
        vtx.v = vertex->v;
        x = vtx.pos.x;
        y = vtx.pos.y;
        z = vtx.pos.z;
        *(volatile f32 *)GX_FIFO_ADDR = x;
        *(volatile f32 *)GX_FIFO_ADDR = y;
        *(volatile f32 *)GX_FIFO_ADDR = z;
        *(volatile u32 *)GX_FIFO_ADDR = (vtx.color << 8) | (vtx.color >> 24);
        *(volatile f32 *)GX_FIFO_ADDR = vtx.u;
        *(volatile f32 *)GX_FIFO_ADDR = vtx.v;
    }
    fn_802D6C68();
}
#pragma scheduling on
