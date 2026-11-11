// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

/* --- Named overlay quads -------------------------------------------
 * A list of 0xB4-byte textured quads hangs off lbl_8055F014: fn_8022F638
 * creates one from a texture name, fn_8022F2FC finds it by name,
 * fn_8022F364/fn_8022F77C add and remove list nodes, and fn_8022F8CC draws
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

typedef struct OverlayQuad {
    QuadMtx mtx;      /* 0x00: transform, composed with the current one on draw */
    s32 texIndex;     /* 0x30: texture table entry (fn_802CAC28), -1 if unknown */
    u32 color;        /* 0x34: RGBA color; fn_8022FF90 starts it at white */
    s32 colorIndex;   /* 0x38: palette entry fn_80230B9C turns into a color */
    char name[0x40];  /* 0x3C: texture name, compared case-insensitively */
    f32 z;            /* 0x7C: depth the corners are drawn at */
    s32 texScale;     /* 0x80: S/T of the far corner; the near one is (0, 0) */
    s32 width;        /* 0x84: corners span -width..width (0x2D0 = 720 on NTSC) */
    s32 height;       /* 0x88: corners span -height..height (0x1E0 = 480) */
    /* 0x8C..0xB0: scroll/drift state, walked every frame by fn_8022FB6C and
     * applied by fn_8022FD9C; the defaults come from .sdata2 in fn_8022F638. */
    f32 scrollOffset; /* 0x8C: random-walk offset, kept inside +-scrollLimit */
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

/* The 24-byte GX FIFO vertex fn_802D68C4 pushes: position, RGBA8 color and one
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
void fn_80015EB0(float);
void fn_80015E30(void *, float);
void fn_80015B20(void *, void *, void *);
void fn_80015AA0(void *, float);
char *stricmp(const char *, const char *);
void fn_802E317C();
extern char lbl_80340350[];
extern char lbl_80497E3C[];
extern char lbl_8055B988;
#pragma scheduling invalid_target
void fn_8022F248(void) {
    if (lbl_8055F014 != 0) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80340350);
    }
    strcpy(lbl_80497E3C + 0x3c, &lbl_8055B988);
}

void fn_8022F294(void) {
    void *var_r0;
    void *var_r31;
    if (fn_80230020() != 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_80340394);
        var_r0 = lbl_8055F014;
        var_r31 = var_r0;
        while (var_r0 != 0) {
            fn_8022F824(*(void **)var_r31);
            var_r31 = *(void **)((char *)var_r31 + 8);
            var_r0 = 0;
            lbl_8055F014 = var_r31;
        }
    }
}

#pragma scheduling on

void *fn_8022F2FC(char *arg0) {
    void *node = lbl_8055F014;
    while (node != 0) {
        if (stricmp((char *)*(void **)node + 0x3c, arg0) == 0) return node;
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
void fn_8022F364(void *arg0) {
    void *node;
    if (arg0 == 0) return;
    node = lbl_8055F014;
    if (node == 0) {
        node = fn_801284F8(0xc, lbl_803403CC);
        lbl_8055F014 = node;
        *(void **)node = arg0;
        *(int *)((char *)lbl_8055F014 + 4) = 1;
        *(void **)((char *)lbl_8055F014 + 8) = 0;
    } else {
        while (*(void **)((char *)node + 8) != 0) node = *(void **)((char *)node + 8);
        *(void **)((char *)node + 8) = fn_801284F8(0xc, lbl_803403CC);
        node = *(void **)((char *)node + 8);
        *(void **)node = arg0;
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

extern char lbl_803403DC[];
extern char lbl_8055B98C;
extern float lbl_805635E8, lbl_805635EC, lbl_805635F0, lbl_805635F4, lbl_805635F8;
extern int fn_8012C33C(void *);
extern int fn_802CAC28(void *, int);
void fn_8022FF90(void *);
#pragma push
#pragma processor 750
#pragma scheduling on
#pragma use_lmw_stmw off
#pragma dont_inline fn_8022F2FC
void *fn_8022F638(char *arg0, unsigned char arg1, unsigned char arg2, int arg3, float farg0) {
    void *node;
    int width, height;
    float f8, f4, f0, ec, e8;

    if (arg0 == 0) return 0;
    ((void *(*)(void))fn_8022F2FC)();
    node = fn_801284F8(0xb4, &lbl_8055B98C);
    if (fn_8012C33C(arg0) != 0) {
        *(int *)((char *)node + 0x30) = fn_802CAC28(arg0, 0);
        *(int *)((char *)node + 0x80) = arg3;
    } else {
        *(int *)((char *)node + 0x30) = -1;
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_803403DC, arg0);
        *(int *)((char *)node + 0x80) = 0;
    }
    strcpy((char *)node + 0x3c, arg0);
    if (strcmp(arg0, lbl_80497E3C + 0x3c) != 0) {
        fn_8022FF90(node);
        *((unsigned char *)node + 0x9d) = arg2;
        width = 0x2d0;
        e8 = lbl_805635E8;
        height = 0x1e0;
        *((unsigned char *)node + 0x9c) = arg1;
        ec = lbl_805635EC;
        *(float *)((char *)node + 0xa0) = e8;
        f0 = lbl_805635F0;
        *(float *)((char *)node + 0x7c) = farg0;
        f4 = lbl_805635F4;
        *(float *)((char *)node + 0xac) = ec;
        f8 = lbl_805635F8;
        *(float *)((char *)node + 0xb0) = f0;
        *(float *)((char *)node + 0xa4) = f4;
        *(float *)((char *)node + 0xa8) = f8;
        *(int *)((char *)node + 0x84) = width;
        *(int *)((char *)node + 0x88) = height;
    } else {
        fn_8022F548(node);
    }
    fn_8022F364(node);
    return node;
}
#pragma use_lmw_stmw reset
#pragma scheduling on
#pragma pop
void fn_8022F77C(OverlayQuad *arg0) {
    struct Node { void *payload; int unk; struct Node *next; };
    struct Node *prev = 0;
    struct Node *node = lbl_8055F014;
    while (node->payload != arg0) {
        if (node == 0) ((void (*)(const char *, ...))fn_802E317C)(lbl_80340408, arg0->name);
        prev = node;
        node = node->next;
    }
    if (prev == 0) lbl_8055F014 = node->next;
    else prev->next = node->next;
    node->unk = 0;
    node->next = 0;
    node->payload = 0;
    fn_80128668(node);
}

void fn_8022F824(void *arg0) {
    fn_8022F418();
    fn_802CAC54(*(int *)((char *)arg0 + 0x30));
    fn_8022F77C(arg0);
    fn_80128668(arg0);
}

void fn_8022F868(void *arg0, void *arg1) {
    int temp = fn_8022EDC4();
    fn_801BFD34((char *)arg0 + 0x24, (char *)arg1 + 0x24, temp);
    fn_80015B20(arg0, arg1, (void *)temp);
}

#pragma push
#pragma processor 750
#pragma dont_inline on
/* Draws one overlay quad.  Builds its four corners at the quad's z, half-width
 * and half-height, all with the color fn_80230B9C reads from the quad's palette
 * entry and texture coordinates running from (0, 0) to (texScale, texScale),
 * points the texture matrix at the quad's transform composed with the current
 * one, then pushes the quad as two triangles through the GX FIFO. */
void fn_8022F8CC(OverlayQuad *quad) {
    extern void fn_80230A68(QuadVtx *, int, f32, f32, f32, f32, f32);
    extern int fn_80230B9C(int);
    extern void fn_8022F868(void *, void *);
    extern void fn_802C8B98(int, QuadMtx *);
    extern void fn_802C8DB8(QuadVtx *, int, u16 *, int);
    extern void fn_802C8D74(void);
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
    fn_802C8D74();
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

#pragma push
#pragma processor 750
void fn_8022FF10(void *arg0, void *arg1) {
    int temp[12];
    float angle, temp_f31, temp_f30;
    angle = *(float *)((char *)arg1 + 4);
    temp_f31 = *(float *)((char *)arg1 + 0);
    temp_f30 = *(float *)((char *)arg1 + 8);
    fn_80015EB0(angle);
    fn_80015E30(temp, temp_f31);
    fn_80015B20(arg0, arg0, temp);
    fn_80015AA0(temp, temp_f30);
    fn_80015B20(arg0, arg0, temp);
}
#pragma pop
void fn_8022FF90(void *arg0) {
    float f0 = lbl_805635FC;
    float f1 = lbl_8056360C;
    *(float *)((char *)arg0 + 4) = f0;
    *(float *)((char *)arg0 + 0) = f1;
    *(float *)((char *)arg0 + 8) = f0;
    *(float *)((char *)arg0 + 0xC) = f0;
    *(float *)((char *)arg0 + 0x10) = f1;
    *(float *)((char *)arg0 + 0x14) = f0;
    *(float *)((char *)arg0 + 0x18) = f0;
    *(float *)((char *)arg0 + 0x1C) = f0;
    *(float *)((char *)arg0 + 0x20) = f1;
    *(float *)((char *)arg0 + 0x24) = f0;
    *(float *)((char *)arg0 + 0x28) = f0;
    *(float *)((char *)arg0 + 0x2C) = f0;
    *(unsigned int *)((char *)arg0 + 0x34) = 0xFF000000;
    *(int *)((char *)arg0 + 0x38) = -1;
    *(float *)((char *)arg0 + 0x8C) = f0;
    *(float *)((char *)arg0 + 0x94) = f0;
    *(float *)((char *)arg0 + 0x98) = f0;
}

void fn_8022FFE8(int arg0) {
    float scale;
    fn_8022FB6C((void *)arg0);
    scale = fn_80214D48();
    fn_8022FD9C((void *)arg0, scale);
}

int fn_80230020(void) {
    int count = 0;
    void *p = lbl_8055F014;
    while (p != 0) {
        p = *(void **)((char *)p + 8);
        count++;
    }
    return count;
}
