// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

/* --- Named overlay quads -------------------------------------------
 * A list of 0xB4-byte textured quads hangs off lbl_8055F014: fn_8022F638
 * creates one from a texture name, fn_8022F2FC finds it by name,
 * fn_8022F364/fn_8022F77C add and remove list nodes, and drawOverlayQuad draws
 * one.  lbl_80497E3C holds the "current" settings a quad is copied in and
 * out of (fn_8022F418 / fn_8022F548).
 */

/* Affine transform in the row-vector convention: three basis rows followed by
 * a translation row, so a point moves as out = in * basis + translation.
 * fn_80015B20 multiplies two basis parts and fn_801BFD34 transforms a
 * translation row by a whole transform. */
typedef struct QuadMtx {
    f32 m[4][3];
} QuadMtx;

typedef struct { f32 x, y, z; } Vec3_8022FF10;

typedef struct OverlayQuad {
    QuadMtx mtx;      /* 0x00: transform, composed with the current one on draw */
    s32 texIndex;     /* 0x30: texture table entry (RegisterTextureByName), -1 if unknown */
    u32 color;        /* 0x34: RGBA color; fn_8022FF90 starts it at white */
    s32 colorIndex;   /* 0x38: palette entry fn_80230B9C turns into a color */
    char name[0x40];  /* 0x3C: texture name, compared case-insensitively */
    f32 z;            /* 0x7C: depth the corners are drawn at */
    s32 texScale;     /* 0x80: S/T of the far corner; the near one is (0, 0) */
    s32 width;        /* 0x84: corners span -width..width (0x2D0 = 720 on NTSC) */
    s32 height;       /* 0x88: corners span -height..height (0x1E0 = 480) */
    /* 0x8C..0xB0: scroll/drift state, walked every frame by fn_8022FB6C and
     * applied by fn_8022FD9C; the defaults come from .sdata2 in fn_8022F638. */
    f32 scrollOffset; /* 0x8C: random-walk offset, kept inside +-scrollLimit;
                       * fn_8022FD9C turns the quad about Z by scrollOffset * dt */
    f32 unused90;     /* 0x90: only ever copied from and to the current quad */
    f32 driftVelX;    /* 0x94: drift velocity x, kept inside +-driftLimit */
    f32 driftVelY;    /* 0x98: drift velocity y, kept inside +-driftLimit */
    u8 scrollOn;      /* 0x9C: scroll this quad (fn_8022F638's arg1) */
    u8 driftOn;       /* 0x9D: drift this quad (fn_8022F638's arg2) */
    f32 driftRange;   /* 0xA0: how far the quad may move before its drift is
                       * pushed back (0x805635E8 = 30.0f) */
    f32 scrollStep;   /* 0xA4: biggest scroll step one frame takes (0.0015f) */
    f32 scrollLimit;  /* 0xA8: scroll clamp (0x805635F8 = 0.035f) */
    f32 driftStep;    /* 0xAC: biggest drift step one frame takes (0.18f) */
    f32 driftLimit;   /* 0xB0: drift clamp (0x805635F0 = 4.5f) */
} OverlayQuad;

/* One node of the background-quad list whose head is lbl_8055F014; the allocator
 * tag lbl_803403CC names these "gBack tracker".  fn_8022F364 links a node in at
 * the end, fn_8022F77C unlinks one by payload and frees it. */
typedef struct QuadNode {
    void *payload;         /* 0x00: the OverlayQuad this node tracks */
    s32 refCount;          /* 0x04: 1 while the node is on the list */
    struct QuadNode *next; /* 0x08: next node, 0 at the end of the list */
} QuadNode;

/* The 24-byte GX FIFO vertex drawFifoTriangles pushes: position, RGBA8 color and one
 * S/T pair.  The game copies these word by word - x and y travel as a single
 * double, z as a raw word - so the fields are declared the way they travel. */
typedef struct QuadVtx {
    f64 xy;           /* 0x00: f32 x, then f32 y */
    u32 z;            /* 0x08: f32 z, copied as a word */
    u32 color;        /* 0x0C: RGBA8 */
    f32 s, t;         /* 0x10, 0x14: texture coordinates */
} QuadVtx;

#define QUAD_INDEXES lbl_802F9FB0 /* {0, 1, 3, 0, 3, 2}: the quad's two triangles */
#define FLOAT_ZERO lbl_805635FC   /* 0.0f, this unit's float zero in .sdata2 */
#define RAND_SCALE lbl_80563608   /* 1.0e7f: fixed-point scale of the random
                                    * steps fn_8022FB6C adds to a quad */
#define gBackQuadList lbl_8055F014 /* head of the OverlayQuad list (QuadNode) */
#define gBackLeakMsg lbl_80340394  /* "gBack: Some backgrounds still set, deallocating now:" */


extern char lbl_80340394[];
extern char lbl_803403CC[];
extern char lbl_80340408[];
int fn_80230020(void);
void fn_8022F824(void *);
void fn_802E30C8(void *);
extern void *lbl_8055F014;
extern float lbl_805635FC;
extern float lbl_8056360C;
void fn_8022FB6C();
float fn_80214D48(void);
void fn_80015EB0();
void fn_80015E30(void *, float);
void fn_80015B20(void *, void *, void *);
void fn_80015AA0(void *, float);
char *stricmp(const char *, const char *);
void Abend_Panic();
extern char lbl_80340350[];
extern char lbl_80497E3C[];
extern char lbl_8055B988;
#pragma scheduling invalid_target
/* gBack init: warn if started twice, then reset the current quad's name to empty. */
void fn_8022F248(void) {
    if (gBackQuadList != 0) {
        ((void (*)(const char *, ...))Abend_Panic)(lbl_80340350);
    }
    strcpy(lbl_80497E3C + 0x3c, &lbl_8055B988);
}
/* Background-quad (gBack) shutdown cleanup: if the list still holds quads when
 * the overlay system is torn down, report the leak and deallocate them -
 * fn_8022F824 copies the quad in as the current one, releases its texture,
 * unlinks its node and frees the quad.  The list head is read once before the
 * loop and the loop's test variable is cleared in the body, so only the first
 * node is deallocated and the head is left on the node after it.
 * (Proposed name: DeallocateRemainingBackgrounds) */
void fn_8022F294(void) {
    QuadNode *remaining;
    QuadNode *node;
    if (fn_80230020() != 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(gBackLeakMsg);
        remaining = gBackQuadList;
        node = remaining;
        while (remaining != 0) {
            fn_8022F824(node->payload);
            node = node->next;
            remaining = 0;
            gBackQuadList = node;
        }
    }
}

#pragma scheduling on

/* Find and return the overlay-quad list node whose quad's texture name matches
   the given name (case-insensitive), or NULL if none is found.
   (Proposed name: FindOverlayQuadByName) */
void *fn_8022F2FC(char *name) {
    void *node = lbl_8055F014;
    while (node != 0) {
        if (stricmp((char *)*(void **)node + 0x3c, name) == 0) return node;
        node = *(void **)((char *)node + 8);
    }
    return 0;
}

extern char lbl_80340394[];
extern char lbl_803403CC[];
extern char lbl_80340408[];
int fn_80230020(void);
void fn_8022F824(void *);
void fn_802E30C8(void *);

void *fn_801284F8(int, const char *);
void fn_80128668(void *);
int fn_8022EDC4(void);
void fn_801BFD34(void *, void *, int);
/* Add an overlay quad to the global list (lbl_8055F014). Each 0xC-byte
 * "gBack tracker" node (lbl_803403CC) holds {payload, refCount, next}. */
void fn_8022F364(void *quad) {
    void *node;
    if (quad == 0) return;
    node = lbl_8055F014;
    if (node == 0) {
        node = fn_801284F8(0xc, lbl_803403CC);
        lbl_8055F014 = node;
        *(void **)node = quad;
        *(int *)((char *)lbl_8055F014 + 4) = 1;
        *(void **)((char *)lbl_8055F014 + 8) = 0;
    } else {
        while (*(void **)((char *)node + 8) != 0) node = *(void **)((char *)node + 8);
        *(void **)((char *)node + 8) = fn_801284F8(0xc, lbl_803403CC);
        node = *(void **)((char *)node + 8);
        *(void **)node = quad;
        *(int *)((char *)node + 4) = 1;
        *(void **)((char *)node + 8) = 0;
    }
}

void fn_8022F418(arg0)
void *arg0;
{
    /* Copies a 0xB4-byte configuration/state record from arg0 into the global buffer at lbl_80497E3C, including fixed fields, a string at +0x3C, and trailing float/byte values. */
    struct Pair { unsigned int a; unsigned int b; };
    struct Pair *sourcePairs = (struct Pair *)arg0;
    struct Pair *destPairs = (struct Pair *)lbl_80497E3C;
    unsigned int *sourceWords = (unsigned int *)arg0;
    float value;
    unsigned char byteValue;

    destPairs[0] = sourcePairs[0];
    destPairs[1] = sourcePairs[1];
    destPairs[2] = sourcePairs[2];
    destPairs[3] = sourcePairs[3];
    destPairs[4].a = sourceWords[8];
    *(struct Pair *)((char *)destPairs + 0x24) = *(struct Pair *)((char *)sourcePairs + 0x24);
    destPairs[5].b = sourceWords[11];
    destPairs[6].a = (unsigned int)-1;
    destPairs[6].b = sourceWords[13];
    destPairs[7].a = sourceWords[14];
    strcpy((char *)lbl_80497E3C + 0x3c, (char *)arg0 + 0x3c);
    value = *(float *)((char *)arg0 + 0x7c);
    *(float *)((char *)lbl_80497E3C + 0x7c) = value;
    *(unsigned int *)((char *)lbl_80497E3C + 0x80) = *(unsigned int *)((char *)arg0 + 0x80);
    *(unsigned int *)((char *)lbl_80497E3C + 0x84) = *(unsigned int *)((char *)arg0 + 0x84);
    *(unsigned int *)((char *)lbl_80497E3C + 0x88) = *(unsigned int *)((char *)arg0 + 0x88);
    value = *(float *)((char *)arg0 + 0x8c);
    *(float *)((char *)lbl_80497E3C + 0x8c) = value;
    value = *(float *)((char *)arg0 + 0x90);
    *(float *)((char *)lbl_80497E3C + 0x90) = value;
    value = *(float *)((char *)arg0 + 0x94);
    *(float *)((char *)lbl_80497E3C + 0x94) = value;
    value = *(float *)((char *)arg0 + 0x98);
    *(float *)((char *)lbl_80497E3C + 0x98) = value;
    byteValue = *((unsigned char *)arg0 + 0x9c);
    *((unsigned char *)lbl_80497E3C + 0x9c) = byteValue;
    byteValue = *((unsigned char *)arg0 + 0x9d);
    *((unsigned char *)lbl_80497E3C + 0x9d) = byteValue;
    value = *(float *)((char *)arg0 + 0xa0);
    *(float *)((char *)lbl_80497E3C + 0xa0) = value;
    value = *(float *)((char *)arg0 + 0xa4);
    *(float *)((char *)lbl_80497E3C + 0xa4) = value;
    value = *(float *)((char *)arg0 + 0xa8);
    *(float *)((char *)lbl_80497E3C + 0xa8) = value;
    value = *(float *)((char *)arg0 + 0xac);
    *(float *)((char *)lbl_80497E3C + 0xac) = value;
    value = *(float *)((char *)arg0 + 0xb0);
    *(float *)((char *)lbl_80497E3C + 0xb0) = value;
}

/*
 * Copies a configuration/state record from the global lbl_80497E3C buffer into dst.
 * Mirrors fn_8022F418's field layout but reads from the global buffer (omits string copy and 0x30 write).
 */
void fn_8022F548(void *dstArg) {
    struct Pair { unsigned int a; unsigned int b; };
    unsigned int *srcWords = (unsigned int *)lbl_80497E3C;
    struct Pair *dstPairs = (struct Pair *)dstArg;
    struct Pair *srcPairs = (struct Pair *)srcWords;
    float value;
    unsigned char byteValue;

    dstPairs[0] = srcPairs[0];
    dstPairs[1] = srcPairs[1];
    dstPairs[2] = srcPairs[2];
    dstPairs[3] = srcPairs[3];
    *(unsigned int *)((char *)dstArg + 0x20) = srcWords[8];
    *(struct Pair *)((char *)dstArg + 0x24) = *(struct Pair *)((char *)srcWords + 0x24);
    *(unsigned int *)((char *)dstArg + 0x2C) = srcWords[11];
    *(unsigned int *)((char *)dstArg + 0x34) = srcWords[13];
    *(unsigned int *)((char *)dstArg + 0x38) = srcWords[14];
    value = *(float *)((char *)srcWords + 0x7C);
    *(float *)((char *)dstArg + 0x7C) = value;
    *(unsigned int *)((char *)dstArg + 0x80) = *(unsigned int *)((char *)srcWords + 0x80);
    *(unsigned int *)((char *)dstArg + 0x84) = *(unsigned int *)((char *)srcWords + 0x84);
    *(unsigned int *)((char *)dstArg + 0x88) = *(unsigned int *)((char *)srcWords + 0x88);
    value = *(float *)((char *)srcWords + 0x8C);
    *(float *)((char *)dstArg + 0x8C) = value;
    value = *(float *)((char *)srcWords + 0x90);
    *(float *)((char *)dstArg + 0x90) = value;
    value = *(float *)((char *)srcWords + 0x94);
    *(float *)((char *)dstArg + 0x94) = value;
    value = *(float *)((char *)srcWords + 0x98);
    *(float *)((char *)dstArg + 0x98) = value;
    byteValue = *((unsigned char *)srcWords + 0x9C);
    *((unsigned char *)dstArg + 0x9C) = byteValue;
    byteValue = *((unsigned char *)srcWords + 0x9D);
    *((unsigned char *)dstArg + 0x9D) = byteValue;
    value = *(float *)((char *)srcWords + 0xA0);
    *(float *)((char *)dstArg + 0xA0) = value;
    value = *(float *)((char *)srcWords + 0xA4);
    *(float *)((char *)dstArg + 0xA4) = value;
    value = *(float *)((char *)srcWords + 0xA8);
    *(float *)((char *)dstArg + 0xA8) = value;
    value = *(float *)((char *)srcWords + 0xAC);
    *(float *)((char *)dstArg + 0xAC) = value;
    value = *(float *)((char *)srcWords + 0xB0);
    *(float *)((char *)dstArg + 0xB0) = value;
}

extern char lbl_803403DC[]; /* "gBack: Texture %s not found for background." */
extern char lbl_8055B98C;
extern float lbl_805635E8, lbl_805635EC, lbl_805635F0, lbl_805635F4, lbl_805635F8; /* 30, 0.18, 4.5, 0.0015, 0.035: default overlay layout */
extern int fn_8012C33C(void *);
extern int RegisterTextureByName(void *, int);
void fn_8022FF90(void *);
#pragma push
#pragma processor 750
#pragma scheduling on
#pragma use_lmw_stmw off
#pragma dont_inline fn_8022F2FC
/* Create a named 0xB4-byte background-overlay quad: resolve the texture, record the
 * name, then either fill in a fresh 720x480 quad with the default layout or copy the
 * shared default record when the name matches it; finally register it in the gBack
 * tracker list. */
void *fn_8022F638(char *textureName, unsigned char paramA, unsigned char paramB, int intParam, float floatParam) {
    void *quad;
    int width, height;
    float fineScale, tinyScale, largeScale, mediumScale, margin;

    if (textureName == 0) return 0;
    ((void *(*)(void))fn_8022F2FC)();
    quad = fn_801284F8(0xb4, &lbl_8055B98C);
    if (fn_8012C33C(textureName) != 0) {
        *(int *)((char *)quad + 0x30) = RegisterTextureByName(textureName, 0);
        *(int *)((char *)quad + 0x80) = intParam;
    } else {
        *(int *)((char *)quad + 0x30) = -1;
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_803403DC, textureName);
        *(int *)((char *)quad + 0x80) = 0;
    }
    strcpy((char *)quad + 0x3c, textureName);
    if (strcmp(textureName, lbl_80497E3C + 0x3c) != 0) {
        fn_8022FF90(quad);
        *((unsigned char *)quad + 0x9d) = paramB;
        width = 0x2d0;
        margin = 30.0f;
        height = 0x1e0;
        *((unsigned char *)quad + 0x9c) = paramA;
        mediumScale = lbl_805635EC;
        *(float *)((char *)quad + 0xa0) = margin;
        largeScale = lbl_805635F0;
        *(float *)((char *)quad + 0x7c) = floatParam;
        tinyScale = lbl_805635F4;
        *(float *)((char *)quad + 0xac) = mediumScale;
        fineScale = lbl_805635F8;
        *(float *)((char *)quad + 0xb0) = largeScale;
        *(float *)((char *)quad + 0xa4) = tinyScale;
        *(float *)((char *)quad + 0xa8) = fineScale;
        *(int *)((char *)quad + 0x84) = width;
        *(int *)((char *)quad + 0x88) = height;
    } else {
        fn_8022F548(quad);
    }
    fn_8022F364(quad);
    return quad;
}
#pragma use_lmw_stmw reset
#pragma scheduling on
#pragma pop
/* Forget one background overlay quad: unlink the "gBack tracker" node whose
 * payload is this quad from the global list (lbl_8055F014), panicking if the
 * quad was never tracked, then clear the node and free it. */
void fn_8022F77C(OverlayQuad *quad) {
    struct QuadNode { void *payload; int refCount; struct QuadNode *next; };
    struct QuadNode *prev = 0;
    struct QuadNode *node = lbl_8055F014;
    while (node->payload != quad) {
        if (node == 0) ((void (*)(const char *, ...))Abend_Panic)(lbl_80340408, quad->name);
        prev = node;
        node = node->next;
    }
    if (prev == 0) lbl_8055F014 = node->next;
    else prev->next = node->next;
    node->refCount = 0;
    node->next = 0;
    node->payload = 0;
    fn_80128668(node);
}

void fn_8022F824(void *quad) {
    /* Release one background overlay quad: copy it to the current-quad buffer,
     * release its texture, unlink its tracker node from the list, and free the
     * quad. */
    fn_8022F418();
    fn_802CAC54(*(int *)((char *)quad + 0x30));
    fn_8022F77C(quad);
    fn_80128668(quad);
}

/* Copy/configure the transform/related block at +0x24 from src to dst using the
 * current context from fn_8022EDC4, then run the follow-up step fn_80015B20. */
void fn_8022F868(void *dst, void *src) {
    int context = fn_8022EDC4();
    fn_801BFD34((char *)dst + 0x24, (char *)src + 0x24, context);
    fn_80015B20(dst, src, (void *)context);
}

#pragma push
#pragma processor 750
#pragma dont_inline on
/* Draws one overlay quad.  Builds its four corners at the quad's z, half-width
 * and half-height, all with the color fn_80230B9C reads from the quad's palette
 * entry and texture coordinates running from (0, 0) to (texScale, texScale),
 * points the texture matrix at the quad's transform composed with the current
 * one, then pushes the quad as two triangles through the GX FIFO. */
/* Draw one overlay quad: build its four textured, colored corners at the given depth and size, compose its transform with the current one, and push it to the GX FIFO as two triangles. */ void drawOverlayQuad(OverlayQuad *quad) {
    extern void fn_80230A68(QuadVtx *, int, f32, f32, f32, f32, f32);
    extern int fn_80230B9C(int);
    extern void fn_8022F868(void *, void *);
    extern void fn_802C8B98(int, QuadMtx *);
    extern void fn_802C8DB8(QuadVtx *, int, u16 *, int);
    extern void DrawList_RestoreNormalMode(void);
    extern unsigned short lbl_802F9FB0[6];
    QuadVtx __declspec(align(16)) vtx[4];
    QuadMtx world, local;
    QuadVtx v0, v1, v2, v3;
    u16 idx[6];
    f32 texScale, z, x, y;
    int color;

    texScale = quad->texScale;
    z = quad->z;
    color = fn_80230B9C(quad->colorIndex);
    x = quad->width;
    y = quad->height;

    fn_80230A68(&v0, color, -x, y, z, FLOAT_ZERO, FLOAT_ZERO);
    vtx[0].xy = v0.xy;
    vtx[0].z = v0.z;
    vtx[0].color = v0.color;
    vtx[0].s = v0.s;
    vtx[0].t = v0.t;
    fn_80230A68(&v1, color, x, y, z, texScale, FLOAT_ZERO);
    vtx[1].xy = v1.xy;
    vtx[1].z = v1.z;
    vtx[1].color = v1.color;
    vtx[1].s = v1.s;
    vtx[1].t = v1.t;
    fn_80230A68(&v2, color, -x, -y, z, FLOAT_ZERO, texScale);
    vtx[2].xy = v2.xy;
    vtx[2].z = v2.z;
    vtx[2].color = v2.color;
    vtx[2].s = v2.s;
    vtx[2].t = v2.t;
    fn_80230A68(&v3, color, x, -y, z, texScale, texScale);
    vtx[3].xy = v3.xy;
    vtx[3].z = v3.z;
    vtx[3].color = v3.color;
    vtx[3].s = v3.s;
    vtx[3].t = v3.t;
    { QuadMtx *src = &local; QuadMtx *dst = &world;
    { u16 *p = QUAD_INDEXES - 1;
      idx[0] = *++p; idx[1] = *++p; idx[2] = *++p;
      idx[3] = *++p; idx[4] = *++p; idx[5] = *++p; }
    local = quad->mtx;
    fn_8022F868(dst, src); }
    fn_802C8B98(quad->texIndex, &world);
    fn_802C8DB8(vtx, 4, idx, 6);
    DrawList_RestoreNormalMode();
}
#pragma pop
extern float lbl_80563608;
int fn_80129D90(int, int, int);
#pragma push
#pragma processor 750
/* One frame of a quad's scroll/drift wander, run by fn_8022FFE8 right before
 * the values are applied.  fn_80129D90(2, min, max) draws a random int from
 * min..max-1 out of random source 2, so dividing it by the 1.0e7f RAND_SCALE
 * gives a float step inside +-(the field it was scaled from).
 * With scrollOn, the scroll offset takes a random step of +-scrollStep and is
 * clamped to +-scrollLimit.  With driftOn, each drift velocity is first pushed
 * back by one driftStep once the quad's translation has left +-driftRange,
 * then takes a random step of +-driftStep and is clamped to +-driftLimit. */
void fn_8022FB6C(OverlayQuad *quad) {
    float scale, value;
    int range;

    if (quad->scrollOn != 0) {
        scale = RAND_SCALE;
        range = (int)(quad->scrollStep * scale);
        value = quad->scrollOffset + (float)fn_80129D90(2, -range, range + 1) / scale;
        quad->scrollOffset = value;
        if (value > quad->scrollLimit) {
            quad->scrollOffset = quad->scrollLimit;
        } else if (value < -quad->scrollLimit) {
            quad->scrollOffset = -quad->scrollLimit;
        }
    }
    if (quad->driftOn != 0) {
        if (quad->mtx.m[3][0] > quad->driftRange) {
            quad->driftVelX = quad->driftVelX - quad->driftStep;
        } else if (quad->mtx.m[3][0] < -quad->driftRange) {
            quad->driftVelX = quad->driftVelX + quad->driftStep;
        }
        if (quad->mtx.m[3][1] > quad->driftRange) {
            quad->driftVelY = quad->driftVelY - quad->driftStep;
        } else if (quad->mtx.m[3][1] < -quad->driftRange) {
            quad->driftVelY = quad->driftVelY + quad->driftStep;
        }
        range = (int)(quad->driftStep * RAND_SCALE);
        scale = RAND_SCALE;
        value = quad->driftVelX + (float)fn_80129D90(2, -range, range + 1) / scale;
        quad->driftVelX = value;
        if (value > quad->driftLimit) {
            quad->driftVelX = quad->driftLimit;
        } else if (value < -quad->driftLimit) {
            quad->driftVelX = -quad->driftLimit;
        }
        range = (int)(quad->driftStep * RAND_SCALE);
        scale = RAND_SCALE;
        value = quad->driftVelY + (float)fn_80129D90(2, -range, range + 1) / scale;
        quad->driftVelY = value;
        if (value > quad->driftLimit) {
            quad->driftVelY = quad->driftLimit;
        } else if (value < -quad->driftLimit) {
            quad->driftVelY = -quad->driftLimit;
        }
    }
}

extern void PSVECCrossProduct(float *, float *, float *);
extern void PSVECNormalize(float *, float *);
extern void fn_8022FF10(void *, void *);
extern void fn_80015B20(void *, void *, void *);
/* One frame of a quad's scroll and drift, run by fn_8022FFE8 right after
 * fn_8022FB6C has wandered the two values: the scroll offset becomes a turn
 * about Z of scrollOffset * dt composed into the quad's transform, and the
 * drift velocity moves the transform's translation row by driftVel * dt.
 * Multiplying basis rows around like that lets them drift out of true, so the
 * last step re-orthonormalises them (y comes from x and z, z again from x
 * and y) and writes the three back. */
void fn_8022FD9C(OverlayQuad *quad, float dt) {
    float rot[9];      /* the scroll rotation fn_8022FF10 builds */
    float eulers[3];   /* x, y, z turn; only the z scroll is set here */
    float step[3];     /* this frame's drift, added to the translation row */
    float zAxis[3];
    float yAxis[3];
    float xAxis[3];
    float xx, xy, xz, zx, zy, zz;

    eulers[0] = 0.0f;
    eulers[1] = 0.0f;
    eulers[2] = quad->scrollOffset * dt;
    if (quad->scrollOn) {
        fn_8022FF10(rot, eulers);
        fn_80015B20(quad, quad, rot);
    }
    step[0] = quad->driftVelX * dt;
    step[1] = quad->driftVelY * dt;
    step[2] = 0.0f;
    if (quad->driftOn) {
        quad->mtx.m[3][0] += step[0];
        quad->mtx.m[3][1] += step[1];
        quad->mtx.m[3][2] += step[2];
    }
    xz = quad->mtx.m[0][2];
    xy = quad->mtx.m[0][1];
    xx = quad->mtx.m[0][0];
    xAxis[0] = xx;
    xAxis[1] = xy;
    xAxis[2] = xz;
    zz = quad->mtx.m[2][2];
    zy = quad->mtx.m[2][1];
    zx = quad->mtx.m[2][0];
    zAxis[0] = zx;
    zAxis[1] = zy;
    zAxis[2] = zz;
    PSVECCrossProduct(zAxis, xAxis, yAxis);
    PSVECNormalize(xAxis, xAxis);
    PSVECNormalize(yAxis, yAxis);
    PSVECCrossProduct(xAxis, yAxis, zAxis);
    quad->mtx.m[0][0] = xAxis[0];
    quad->mtx.m[0][1] = xAxis[1];
    quad->mtx.m[0][2] = xAxis[2];
    quad->mtx.m[1][0] = yAxis[0];
    quad->mtx.m[1][1] = yAxis[1];
    quad->mtx.m[1][2] = yAxis[2];
    quad->mtx.m[2][0] = zAxis[0];
    quad->mtx.m[2][1] = zAxis[1];
    quad->mtx.m[2][2] = zAxis[2];
}

#pragma use_lmw_stmw off
#pragma optimize_for_size off
#pragma scheduling on
void fn_8022FF10(void *arg0, void *arg1) {
    struct Vec3 { f32 x, y, z; };
    const struct Vec3 *angles = (const struct Vec3 *)arg1;
    f32 stepMatrix[9];
    f32 yaw = angles->y;
    f32 pitch = angles->x;
    f32 roll = angles->z;
    fn_80015EB0(arg0, yaw);
    fn_80015E30(stepMatrix, pitch);
    fn_80015B20(arg0, arg0, stepMatrix);
    fn_80015AA0(stepMatrix, roll);
    fn_80015B20(arg0, arg0, stepMatrix);
}
void fn_8022FF90(void *quad) {
    float zero = lbl_805635FC;
    float one = lbl_8056360C;
    /* Initializes an overlay quad to identity-like defaults (matrix, white/opaque colors, and zeroed scroll state). */
    *(float *)((char *)quad + 4) = zero;
    *(float *)((char *)quad + 0) = one;
    *(float *)((char *)quad + 8) = zero;
    *(float *)((char *)quad + 0xC) = zero;
    *(float *)((char *)quad + 0x10) = one;
    *(float *)((char *)quad + 0x14) = zero;
    *(float *)((char *)quad + 0x18) = zero;
    *(float *)((char *)quad + 0x1C) = zero;
    *(float *)((char *)quad + 0x20) = one;
    *(float *)((char *)quad + 0x24) = zero;
    *(float *)((char *)quad + 0x28) = zero;
    *(float *)((char *)quad + 0x2C) = zero;
    *(unsigned int *)((char *)quad + 0x34) = 0xFF000000;
    *(int *)((char *)quad + 0x38) = -1;
    *(float *)((char *)quad + 0x8C) = zero;
    *(float *)((char *)quad + 0x94) = zero;
    *(float *)((char *)quad + 0x98) = zero;
}

void fn_8022FFE8(int quad) {
#define wanderScrollDrift fn_8022FB6C
#define frameScale fn_80214D48
#define applyScrollDrift fn_8022FD9C
    /* Update one OverlayQuad for a frame: wander its scroll/drift values, then apply them with the global frame scale and re-orthonormalize its basis. */
    float scale;
    wanderScrollDrift((void *)quad);
    scale = frameScale();
    applyScrollDrift((void *)quad, scale);
#undef wanderScrollDrift
#undef frameScale
#undef applyScrollDrift
}

/* Returns the number of nodes on the background-quad list. */
int fn_80230020(void) {
    int count = 0;
    QuadNode *node = gBackQuadList;
    while (node != 0) {
        node = node->next;
        count++;
    }
    return count;
}
