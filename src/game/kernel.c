// kernel.cpp — engine kernel: stack check, PlatExitProcess, video/canvas init.
// Recovered TU window 0x802E1728..0x802E3028 (see docs/attribution_analysis.md):
// assert string "kernel.cpp". Static-init thunk fn_802E3020 (+ .ctors slot
// 0x802ED5E8) remains in auto/text_802E3020_.c pending a promotion pass.

typedef struct { char data[0x20]; } GXTexObj;
extern void GXInitTexObj(GXTexObj *, void *, unsigned short, unsigned short, int, int, int, int);
extern void GXInitTexObjLOD(GXTexObj *, int, int, int, int, int, float, float, float);
extern float lbl_805650F0;
#include <revolution/GX/GXVert.h>
extern int sStackGuardInfo[];
extern void DCStoreRange(void *, int);
extern void DCFlushRange(void *, int);
extern char lbl_8034CD48[];
extern char sStackUsageFormat[];
extern void Abend_Panic(const char *, ...);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034CEE4[];
extern int sResetCallbacks[];
extern int sResetCallbackNames[];
extern int sResetCallbackCount;
extern int kernelBootTicks;
extern unsigned int lbl_8055FEFC;
extern unsigned long long __div2i(unsigned long long, unsigned long long);
typedef unsigned long long u64;
extern u64 KERNEL_GetTimeUs(void);
extern u64 OSGetTime(void);
/* The Revolution OS calendar (OSCalendarTime) OSTicksToCalendarTime() fills;
 * months count from 0 and the microsecond field is not read here. */
struct OSTimeCalendar {
    int sec;
    int min;
    int hour;
    int mday;
    int month;
    int year;
    int wday;
    int yday;
    int msec;
};
extern void OSTicksToCalendarTime(u64, struct OSTimeCalendar *);
/* Free the 32-byte-aligned texture-buffer handle stored at +0x178 of the image bank, then clear the field. */
/* Frees the 32-byte-aligned texture-buffer handle cached at +0x178 of the image bank, then clears the field. */ void freeStoredBufferHandle(void *imageBank) {
    int bufferHandle = *(int *)((char *)imageBank + 0x178);
    if (bufferHandle != 0) {
        fn_80120084(bufferHandle);
        *(int *)((char *)imageBank + 0x178) = 0;
    }
}

#pragma scheduling invalid_target
#pragma dont_inline on
/* Round up to the next power of two: 1 << bit_length(value), i.e. 1 for 0 and
 * the smallest power of two strictly greater than value otherwise. Used by
 * lookupTextureWidth to size textures to a power-of-two width. */
unsigned int roundUpPow2(unsigned int value) {
    return 1U << (32 - __cntlzw(value));
}
#pragma scheduling invalid_target
void fn_802E1780(void *arg0, unsigned int arg1, int arg2) {
    #pragma opt_strength_reduction off
    int xi;
    int ydiff;
    int rowoff;
    unsigned char *p;
    register unsigned int count = arg1 >> 3;
    register int x = 0;
    register int y = 0;
    int i;
    register int row;

    for (row = 0; row < 4; row++) {
        rowoff = row * arg2;
        for (i = 0; i < count; i++) {
            xi = x - i;
            p = (unsigned char *)arg0 + (i + rowoff) * 2;
            ydiff = y - row;
            p[0] = (unsigned char)(xi + 0x80);
            y++;
            p[1] = (unsigned char)(ydiff + 0x80);
            if (y == 4) {
                y = 0;
                x++;
            }
        }
    }
}
#pragma optimization_level 2
#pragma use_lmw_stmw off
#pragma dont_inline on
int fn_802E1804(void *dst, void *src, int count, int outerBytes, int stride)
{
    register unsigned int row;
    register unsigned int outer;
    register unsigned int dstOffset;
    register unsigned int outerCount;
    register unsigned int innerCount;
    register unsigned int total3;
    register unsigned int total2;
    register unsigned int total;

    total = (unsigned int)count * (unsigned int)stride;
    outerCount = (unsigned int)outerBytes >> 2;
    innerCount = total >> 3;
    total2 = total << 1;
    total3 = (total << 2) - total;
    dstOffset = 0;
    outer = 0;
    row = 0;

    for (; outer < outerCount; outer++) {
        unsigned int srcOffset = row * total;
        unsigned int i = innerCount;
        if (i != 0) {
            do {
                unsigned int *s = (unsigned int *)((char *)src + srcOffset);
                unsigned int *d = (unsigned int *)((char *)dst + dstOffset);
                d[0] = s[0];
                d[1] = s[1];
                d[2] = *(unsigned int *)((char *)s + total);
                d[3] = *(unsigned int *)((char *)s + total + 4);
                d[4] = *(unsigned int *)((char *)s + total2);
                d[5] = *(unsigned int *)((char *)s + total2 + 4);
                d[6] = *(unsigned int *)((char *)s + total3);
                d[7] = *(unsigned int *)((char *)s + total3 + 4);
                dstOffset += 0x20;
                srcOffset += 8;
            } while (--i != 0);
        }
        row += 4;
    }
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma optimization_level reset
/* Initialize a GX texture object with nearest filtering, the same wrap mode on
 * both axes, no mipmaps, and all LOD/bias values zeroed. */
int initGXTexObj(int width, int height, int texFmt, int wrapST, void *texObj, int image) {
    GXInitTexObj((GXTexObj *)texObj, (void *)image, (unsigned short)width, (unsigned short)height,
                 texFmt, wrapST, wrapST, 0);
    GXInitTexObjLOD((GXTexObj *)texObj, 0, 0, 0, 0, 0,
                    lbl_805650F0, lbl_805650F0, lbl_805650F0);
    return 1;
}
#pragma scheduling on
/* Round size up to the next multiple of 128 (128-byte texture/cache-line alignment). */
/* Round a byte count up to the next 128-byte boundary (cache-line/texture alignment). */ int align128(int size) { return (size + 0x7F) & 0xFFFFFF80; }

/* Compute the power-of-two width (pixels) of an IA8 lookup texture from its size: size/8 rounded up to a multiple of 4, then up to a power of two. */ unsigned int lookupTextureWidth(unsigned int size) {
    /* Return a power-of-two texture width: size/8 rounded up to a multiple of 4,
     * then raised to the next power of two by roundUpPow2 when needed. */
    unsigned int width = ((size >> 3) + 3) & ~3;
    if ((width & (width - 1)) != 0)
        return roundUpPow2(width);
    return width;
}

#pragma use_lmw_stmw off
/* Build a 4-row IA8 lookup texture from `size`: pick a power-of-two width, fill
 * a linear IA8 buffer, tile it into imagePtr, flush the cache, initialize texObj
 * and return the texture's 128-byte-aligned byte size.  The chosen width and the
 * fixed height of 4 are written through outWidth/outHeight. */
int buildIA8LookupTexture(int imagePtr, void *texObj, void *outWidth, void *outHeight, unsigned int size) {
    /* Build a 4-row IA8 lookup texture from size and report its power-of-two width. */
    unsigned char linearBuf[0x800];
    int width;
    int alignedBytes;

    width = lookupTextureWidth(size);
    *(int *)outWidth = width;
    *(int *)outHeight = 4;
    alignedBytes = align128(width << 3);
    fn_802E1780(linearBuf, size, width);
    fn_802E1804((void *)imagePtr, linearBuf, width, 4, 2);
    DCFlushRange((void *)imagePtr, alignedBytes);
    initGXTexObj(width, 4, 3, 1, texObj, imagePtr);
    return alignedBytes;
}
#pragma use_lmw_stmw reset
/* Build the image bank's two IA8 lookup textures into consecutive image regions, recording each texture object and its width/height at fixed offsets in obj. */
void buildLookupTextures(void *obj, int imageBase) {
    int firstTexBytes;
    firstTexBytes = buildIA8LookupTexture(imageBase, (char *)obj + 0x190, (char *)obj + 0x180, (char *)obj + 0x184, *(int *)((char *)obj + 0x104));
    buildIA8LookupTexture(imageBase + firstTexBytes, (char *)obj + 0x1b0, (char *)obj + 0x188, (char *)obj + 0x18c, *(int *)((char *)obj + 0x10c));
}

extern int align128(int);
extern unsigned int lookupTextureWidth(unsigned int);
#pragma optimization_level 2
#pragma use_lmw_stmw off
#pragma dont_inline on
/* Computes aligned layout sizes/offsets for a texture/image block descriptor.
 * Selects width/height factors from descriptor flags, rounds dimensions via
 * align128/lookupTextureWidth, and outputs combined byte spans and factor flags. */
/* Compute 128-byte-aligned width, height and byte-span layout values for a texture/image descriptor, returning them through the output pointers. */ void fn_802E1A9C(void *desc, int *outCombinedWidth, int *outCombinedPlusHeight, int *outAlignedWidthA, int *outCombinedPlusDoubleHeight, int *outTotalAlignedBytes, int *outWidthFactorMask, int *outHeightFactor, int unused) {
    int alignedWidthA, alignedWidthB, alignedHeight, alignedDimC;
    int baseWidth, baseHeight;
    int widthFactorA, widthFactorB, heightFactor;
    int combinedWidth, totalAlignedBytes;
    widthFactorA = *(int *)((char *)desc + 0x18) ? *(int *)((char *)desc + 4) : 0;
    widthFactorB = *(int *)((char *)desc + 0x3C) ? *(int *)((char *)desc + 4) : 0;
    heightFactor = *(int *)((char *)desc + 0x24) ? *(int *)((char *)desc + 0xC) : 0;
    baseWidth = *(int *)((char *)desc + 8);
    baseHeight = *(int *)((char *)desc + 0x10);
    alignedWidthA = align128(widthFactorA * baseWidth);
    alignedWidthB = align128(widthFactorB * baseWidth);
    alignedHeight = align128(heightFactor * baseHeight);
    alignedDimC = align128(lookupTextureWidth(*(int *)((char *)desc + 0xC)) << 3);
    totalAlignedBytes = align128(lookupTextureWidth(*(int *)((char *)desc + 4)) << 3);
    totalAlignedBytes += alignedDimC;
    *outTotalAlignedBytes = totalAlignedBytes;
    combinedWidth = alignedWidthA + alignedWidthB;
    *outAlignedWidthA = alignedWidthA;
    *outCombinedWidth = combinedWidth;
    *outCombinedPlusHeight = alignedHeight + combinedWidth;
    *outCombinedPlusDoubleHeight = combinedWidth + (alignedHeight << 1);
    *outWidthFactorMask = widthFactorA | widthFactorB;
    *outHeightFactor = heightFactor;
}
#pragma use_lmw_stmw reset
#pragma optimization_level reset
#pragma push
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_common_subs off
int fn_802E1BB4(void *obj, int unused) {
    /* Build an image bank's textures: ask fn_802E1A9C how the four images of one
     * slot lay out, allocate the whole run of slots as one handle, then make a
     * GX texture object for every image a slot uses and record where its data
     * went.  Free the handle again if anything fails. */
    typedef void (*Calc)(void *, int *, int *, int *, int *, int *, int *, int *);
    int combinedWidth, combinedPlusHeight, alignedWidthA, rowBytes, totalBytes, widthA, widthB;
    int bufferHandle;
    char *slot;
    char *texObjs;
    unsigned char *image;
    int i;
    (void)unused;
    ((Calc)fn_802E1A9C)((char *)obj + 0x100, &combinedWidth, &combinedPlusHeight, &alignedWidthA, &rowBytes, &totalBytes, &widthA, &widthB);
    /* one rowBytes-aligned row of image data per slot, plus the alignment slack */
    bufferHandle = fn_8011FFC4(totalBytes + rowBytes * *(int *)((char *)obj + 0x100) + 0x7F, rowBytes);
    if (bufferHandle == 0) goto fail;
    *(int *)((char *)obj + 0x178) = bufferHandle;
    image = (unsigned char *)(((unsigned int)bufferHandle + 0x7F) & ~0x7F);
    slot = (char *)obj;    /* the slot's own record starts at +0x118 */
    texObjs = (char *)obj; /* and its four GXTexObj at +0x00 */
    for (i = 0; i < *(int *)((char *)obj + 0x100); i++, image += rowBytes, slot += 0x30, texObjs += 0x80) {
        if (*(int *)(slot + 0x118) != 0) {           /* first image */
            *(int *)(slot + 0x11C) = (int)image;     /* where its data went */
            *(int *)(slot + 0x120) = widthA;         /* and its width */
            if (!initGXTexObj(widthA, *(int *)((char *)obj + 0x108), 1, 0, texObjs, (int)image)) goto fail;
        }
        if (*(int *)(slot + 0x124) != 0) {           /* second, at combinedWidth */
            *(int *)(slot + 0x128) = (int)image + combinedWidth;
            *(int *)(slot + 0x12C) = widthB;
            if (!initGXTexObj(widthB, *(int *)((char *)obj + 0x110), 1, 0, texObjs + 0x20, (int)image + combinedWidth)) goto fail;
        }
        if (*(int *)(slot + 0x130) != 0) {           /* third, at combinedPlusHeight */
            *(int *)(slot + 0x134) = (int)image + combinedPlusHeight;
            *(int *)(slot + 0x138) = widthB;
            if (!initGXTexObj(widthB, *(int *)((char *)obj + 0x110), 1, 0, texObjs + 0x40, (int)image + combinedPlusHeight)) goto fail;
        }
        if (*(int *)(slot + 0x13C) != 0) {           /* fourth, at alignedWidthA */
            *(int *)(slot + 0x140) = (int)image + alignedWidthA;
            *(int *)(slot + 0x144) = widthA;
            if (!initGXTexObj(widthA, *(int *)((char *)obj + 0x108), 1, 0, texObjs + 0x60, (int)image + alignedWidthA)) goto fail;
        }
    }
    *(int *)((char *)obj + 0x17C) = rowBytes;
    buildLookupTextures(obj, (int)image);                    /* the two lookup textures after the slots */
    return 1;
fail:
    freeStoredBufferHandle(obj);
    return 0;
}
#pragma pop

#pragma processor 750
#pragma use_lmw_stmw off
#pragma optimization_level 4
void fn_802E1DA4(void *arg0, unsigned int arg1, unsigned int arg2, float f0, float f1, float f2, float f3, float f4) {
    extern float lbl_8056510C, lbl_80565110, lbl_80565114, lbl_80565118, lbl_8056511C;
    extern int lbl_802FAE40[];
    extern float lbl_802FAE60[], lbl_804DB740[], lbl_804DB760[];
    extern unsigned short lbl_805650F8, lbl_805650FA, lbl_805650FC, lbl_805650FE;
    extern unsigned char lbl_80565100, lbl_80565101, lbl_80565102, lbl_80565103;
    extern unsigned char lbl_80565104, lbl_80565105, lbl_80565106, lbl_80565107;
    extern unsigned char lbl_80565108, lbl_80565109, lbl_8056510A, lbl_8056510B;
    extern void GXSetVtxAttrFmt(int, int, int, int, int);
    extern void GXClearVtxDesc(void);
    extern void GXLoadTexObj(void *, int);
    extern void GXSetVtxDesc(int, int);
    extern void GXSetNumChans(int);
    extern void GXSetNumTexGens(int);
    extern void GXSetNumTevStages(int);
    extern void GXSetNumIndStages(int);
    extern void GXSetIndTexOrder(int, int, int);
    extern void GXSetBlendMode(int, int, int, int);
    extern void GXSetTevIndirect(int, int, int, int, int, int, int, int, int, int);
    extern void GXSetTevOrder(int, int, int, int);
    extern void GXSetTevColorIn(int, int, int, int, int);
    extern void GXSetTevColorOp(int, int, int, int, int, int);
    extern void GXSetTevAlphaIn(int, int, int, int, int);
    extern void GXSetTevAlphaOp(int, int, int, int, int, int);
    extern void GXSetTevKColorSel(int, int);
    extern void GXSetTevKAlphaSel(int, int);
    extern void GXSetTevSwapMode(int, int, int);
    extern void GXSetTevColorS10(int, unsigned short *, unsigned short, unsigned short, unsigned short);
    extern void GXSetTevKColor(int, unsigned char *, unsigned char, unsigned char, unsigned char);
    extern void GXSetTevSwapModeTable(int, int, int, int, int);
    extern void GXSetIndTexMtx(int, int *, int);
    extern void GXSetTexCoordGen2(int, int, int, int, int, int);
    extern void GXLoadTexMtxImm(float *, int, int);
    extern void GXBegin(int, int, int);
    int r31;
    unsigned char r30;
    short p1, p2, p3, p4;
    float s0, t0, s1, t1;

    if (f4 >= lbl_8056510C) r30 = 0xFF;
    else if (f4 <= lbl_80565110) r30 = 0;
    else r30 = (unsigned char)(lbl_80565114 + lbl_80565118 * f4);
    switch (*(int *)((char *)arg0 + 0x140)) {
    default: r31 = 1; break;
    case 0: r31 = 0; break;
    }
    *(int *)((char *)arg0 + *(int *)((char *)arg0 + 0x114) * 4 + 0x1D0) = 1;
    GXSetVtxAttrFmt(0, 9, 1, 3, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xE, 1, 4, 0);
    GXClearVtxDesc();
    GXLoadTexObj((char *)arg0 + (*(int *)((char *)arg0 + 0x114) << 7), 0);
    GXLoadTexObj((char *)arg0 + 0x190, 1);
    GXLoadTexObj((char *)arg0 + 0x1B0, 2);
    GXLoadTexObj((char *)arg0 + (*(int *)((char *)arg0 + 0x114) << 7) + 0x20, 3);
    GXLoadTexObj((char *)arg0 + (*(int *)((char *)arg0 + 0x114) << 7) + 0x40, 4);
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxDesc(0xE, 1);
    if (r31) GXLoadTexObj((char *)arg0 + (*(int *)((char *)arg0 + 0x114) << 7) + 0x60, 5);
    GXSetNumChans(1);
    GXSetNumTexGens(4);
    GXSetNumTevStages(4);
    GXSetNumIndStages(3);
    GXSetIndTexOrder(0, 1, 1);
    GXSetIndTexOrder(1, 2, 2);
    if (r31) {
        GXSetBlendMode(1, 4, 5, 0);
    } else if (r30 != 0xFF) {
        GXSetBlendMode(1, 4, 5, 0);
    } else {
        GXSetBlendMode(1, 1, 0, 0);
    }
    GXSetTevIndirect(0, 1, 0, 7, 1, 0, 0, 0, 0, 0);
    GXSetTevOrder(0, 0, 4, 0xFF);
    GXSetTevColorIn(0, 0xF, 8, 0xE, 2);
    GXSetTevColorOp(0, 0, 0, 0, 0, 0);
    GXSetTevAlphaIn(0, 7, 4, 6, 1);
    GXSetTevAlphaOp(0, 1, 0, 0, 0, 0);
    GXSetTevKColorSel(0, 0xC);
    GXSetTevKAlphaSel(0, 0x1C);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevIndirect(1, 1, 0, 7, 1, 0, 0, 0, 0, 0);
    GXSetTevOrder(1, 0, 3, 0xFF);
    GXSetTevColorIn(1, 0xF, 8, 0xE, 0);
    GXSetTevColorOp(1, 0, 0, 1, 0, 0);
    GXSetTevAlphaIn(1, 7, 4, 6, 0);
    GXSetTevAlphaOp(1, 1, 0, 0, 0, 0);
    GXSetTevKColorSel(1, 0xD);
    GXSetTevKAlphaSel(1, 0x1D);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevIndirect(2, 0, 0, 7, 1, 0, 0, 0, 0, 0);
    GXSetTevOrder(2, 3, 0, 0xFF);
    GXSetTevColorIn(2, 0xF, 8, 0xC, 0);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 4, 7, 7, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetTevSwapMode(2, 0, 0);
    if (r31) {
        GXSetTevIndirect(3, 0, 0, 7, 1, 0, 0, 0, 0, 0);
        GXSetTevOrder(3, 3, 5, 4);
        GXSetTevColorIn(3, 1, 0, 0xE, 0xF);
        GXSetTevColorOp(3, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(3, 7, 4, 5, 7);
        GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
        GXSetTevSwapMode(3, 0, 0);
        GXSetTevKColorSel(3, 0xE);
    } else {
        GXSetTevOrder(3, 0xFF, 0xFF, 4);
        GXSetTevColorIn(3, 1, 0, 0xE, 0xF);
        GXSetTevColorOp(3, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(3, 7, 6, 5, 7);
        GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
        GXSetTevSwapMode(3, 0, 0);
        GXSetTevKColorSel(3, 0xE);
    }
    {
        unsigned short c[4];
        c[0] = lbl_805650F8;
        c[1] = lbl_805650FA;
        c[2] = lbl_805650FC;
        c[3] = lbl_805650FE;
        GXSetTevColorS10(1, c, lbl_805650FC, lbl_805650FA, lbl_805650F8);
    }
    {
        unsigned char c[4];
        c[0] = lbl_80565100;
        c[1] = lbl_80565101;
        c[2] = lbl_80565102;
        c[3] = lbl_80565103;
        GXSetTevKColor(0, c, lbl_80565102, lbl_80565101, lbl_80565100);
    }
    {
        unsigned char c[4];
        c[0] = lbl_80565104;
        c[1] = lbl_80565105;
        c[2] = lbl_80565106;
        c[3] = lbl_80565107;
        GXSetTevKColor(1, c, lbl_80565106, lbl_80565105, lbl_80565104);
    }
    {
        unsigned char c[4];
        c[0] = lbl_80565108;
        c[1] = lbl_80565109;
        c[2] = lbl_8056510A;
        c[3] = lbl_8056510B;
        GXSetTevKColor(2, c, lbl_8056510A, lbl_80565109, lbl_80565108);
    }
    GXSetTevSwapModeTable(0, 0, 1, 2, 3);
    GXSetIndTexMtx(1, lbl_802FAE40, 4);
    s0 = (float)(*(unsigned int *)((char *)arg0 + 0x104) >> 3) / (float)*(unsigned int *)((char *)arg0 + 0x180);
    t0 = (float)*(unsigned int *)((char *)arg0 + 0x108) / (float)*(unsigned int *)((char *)arg0 + 0x184);
    s1 = (float)(*(unsigned int *)((char *)arg0 + 0x10C) >> 3) / (float)*(unsigned int *)((char *)arg0 + 0x188);
    t1 = (float)*(unsigned int *)((char *)arg0 + 0x110) / (float)*(unsigned int *)((char *)arg0 + 0x18C);
    lbl_804DB740[0] = s0;
    lbl_804DB740[5] = t0;
    lbl_804DB760[0] = s1;
    lbl_804DB760[5] = t1;
    GXSetTexCoordGen2(0, 1, 4, 0x1E, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 4, 0x21, 0, 0x7D);
    GXSetTexCoordGen2(2, 1, 4, 0x24, 0, 0x7D);
    GXSetTexCoordGen2(3, 1, 5, 0x27, 0, 0x7D);
    GXLoadTexMtxImm(lbl_802FAE60, 0x1E, 1);
    GXLoadTexMtxImm(lbl_804DB740, 0x21, 1);
    GXLoadTexMtxImm(lbl_804DB760, 0x24, 1);
    GXLoadTexMtxImm(lbl_802FAE60, 0x27, 1);
    GXBegin(0x80, 0, 4);
    p1 = (short)f0;
    p2 = (short)f1;
    p3 = (short)(p1 + (int)((float)arg1 * f2));
    p4 = (short)(p2 + (int)((float)arg2 * f3));
    *(volatile short *)0xCC008000 = p1;
    *(volatile short *)0xCC008000 = p2;
    *(volatile short *)0xCC008000 = 0;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile float *)0xCC008000 = lbl_805650F0;
    *(volatile float *)0xCC008000 = lbl_805650F0;
    *(volatile float *)0xCC008000 = lbl_805650F0;
    *(volatile float *)0xCC008000 = lbl_805650F0;
    *(volatile short *)0xCC008000 = p3;
    *(volatile short *)0xCC008000 = p2;
    *(volatile short *)0xCC008000 = 0;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile float *)0xCC008000 = lbl_8056511C;
    *(volatile float *)0xCC008000 = lbl_805650F0;
    *(volatile float *)0xCC008000 = lbl_8056511C;
    *(volatile float *)0xCC008000 = lbl_805650F0;
    *(volatile short *)0xCC008000 = p3;
    *(volatile short *)0xCC008000 = p4;
    *(volatile short *)0xCC008000 = 0;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile float *)0xCC008000 = lbl_8056511C;
    *(volatile float *)0xCC008000 = lbl_8056511C;
    *(volatile float *)0xCC008000 = lbl_8056511C;
    *(volatile float *)0xCC008000 = lbl_8056511C;
    *(volatile short *)0xCC008000 = p1;
    *(volatile short *)0xCC008000 = p4;
    *(volatile short *)0xCC008000 = 0;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile unsigned char *)0xCC008000 = r30;
    *(volatile float *)0xCC008000 = lbl_805650F0;
    *(volatile float *)0xCC008000 = lbl_8056511C;
    *(volatile float *)0xCC008000 = lbl_805650F0;
    *(volatile float *)0xCC008000 = lbl_8056511C;
}
void videoRingFlushSlot(void *ring) {
    /* Write back the current video-ring slot's decoded payload so the GPU can read it: slot index at +0x114, slots at +0x11C (stride 0x30), byte count at +0x17C. */
    DCStoreRange(*(void **)((char *)ring + *(int *)((char *)ring + 0x114) * 0x30 + 0x11C),
                 *(int *)((char *)ring + 0x17C));
}

#pragma dont_inline reset
/* Advances the Bink video ring's current slot index (+0x114), wrapping at the slot count (+0x100), and clears the buffer flag of the new current slot (flag array at +0x1D0, one int per slot). Called each frame by fn_802E12DC. */
void fn_802E27B8(void *ring) {
#define currentIndex ((int *)((char *)ring + 0x114))
#define slotCount ((int *)((char *)ring + 0x100))
    /* Advance the video ring's current slot (wrapping at the slot count) and clear that slot's flag. */
    int index = *currentIndex + 1;
    if (index >= *slotCount)
        index = 0;
    if (*(int *)((char *)ring + 0x1D0 + index * 4))
        *(int *)((char *)ring + 0x1D0 + index * 4) = 0;
#undef currentIndex
#undef slotCount
}

#pragma scheduling invalid_target
void fn_802E27F0(void) {
    extern char lbl_8034CD00[];
    int local[2];
    int **heap = (int **)sStackGuardInfo;
    int size;
    register int count;
    register int i;

    sStackGuardInfo[0] = 0x7400;
    heap[1] = local;
    size = sStackGuardInfo[0];
    fn_802E30C8(lbl_8034CD00, size / 1024, local);
    count = sStackGuardInfo[0] / 4;
    for (i = 0; i < count; i++) {
        (*(int **)((char *)sStackGuardInfo + 4))[-i] = 0x53FFEEDD;
    }
    *(int **)((char *)sStackGuardInfo + 8) =
        (int *)((char *)(*(int **)((char *)sStackGuardInfo + 4)) +
                (-(count - 1) * 4));
}
#pragma scheduling on
/* At shutdown, scan stack-guard words from deepest to shallowest and report
 * measured stack usage at the first guard word whose magic value was overwritten. */
void KERNEL_ReportStackUsage(void) {
    int stackSizeBytes = *(int *)sStackGuardInfo;
    int *guardTop = *(int **)((char *)sStackGuardInfo + 4);
    int wordIndex;
    int guardWordCount = stackSizeBytes / 4;
    for (wordIndex = guardWordCount - 1; wordIndex >= 0; --wordIndex) {
        if (guardTop[-wordIndex] != 0x53ffeedd) {
            fn_802E30C8(sStackUsageFormat, (wordIndex * 4) / 1024, stackSizeBytes / 1024);
            return;
        }
    }
}

/* Abort with "STACK OVERRUN!" if the configured stack-guard magic word (0x53FFEEDD) has been overwritten. */ void fn_802E2A1C(void) {
#define StackGuardInfo sStackGuardInfo
#define STACK_GUARD_MAGIC 0x53ffeedd
#define LogError Abend_Panic
#define StackOverrunMsg lbl_8034CD48
    int **guard = (int **)((char *)StackGuardInfo + 8);
    /* Check the deepest stack-guard word: if one is configured and its magic
     * value has been overwritten, log "STACK OVERRUN!". */
    if (*guard == 0)
        return;
    if (**guard == STACK_GUARD_MAGIC)
        return;
    LogError(StackOverrunMsg);
#undef StackOverrunMsg
#undef LogError
#undef STACK_GUARD_MAGIC
#undef StackGuardInfo
}

/* Empty placeholder in the kernel startup sequence (KERNEL_Init): the paired
 * subsystem needs no initialization in this build. Its shutdown counterpart is
 * fn_802E2A58. */
void fn_802E2A54(void) {}

/* Empty placeholder in the kernel shutdown sequence (KERNEL_Shutdown): the paired
 * subsystem needs no teardown in this build. Its startup counterpart is
 * fn_802E2A54. */
void fn_802E2A58(void) {}

extern void OSInit(void);
extern void LCEnable(void);
extern void fn_8005954C(void);
extern void fn_802E77A8(void);
extern void fn_802E3498(void);
extern void fn_801293B4(void);
extern void Abend_InitLog(void);
extern void fn_802E2A54(void);
extern void fn_8012820C(int);
extern void ConfigReadSystemSettings(void);
extern void fn_802E7318(void);
extern void fn_802E46B0(void);
extern void fn_80127C8C(void);
extern void fn_802E8CA8(void);
extern void fn_80127538(void);
extern void fn_80129790(void);
extern void Spu_Init(void);
extern void initStrmBank(void);
extern void fn_802EBE2C(void);
extern void fn_802CF600(void);
extern void fn_802EC614(void);
extern void KERNEL_ReadStartupCalendar(void *);
extern void fn_802E27F0(void);
extern void fn_80127C90(void *, void *);
extern char lbl_8034CCE0[];

/* The halfword-packed calendar KERNEL_ReadStartupCalendar writes (struct OSTimeCalendar above
 * compressed into the 0x18 bytes the start-up log prints from). */
struct StartupCalendar {
    unsigned short year;     /* 0x00 */
    unsigned short month;    /* 0x02, 1-12 */
    unsigned short day;      /* 0x04 */
    unsigned short hour;     /* 0x06 */
    unsigned short minute;   /* 0x08 */
    unsigned short second;   /* 0x0A */
    int msec;                /* 0x0C */
    int weekDay;             /* 0x10 */
    unsigned short pad14[2]; /* 0x14 */
};

/* The strings of this file's block at lbl_8034CCE0 that start-up logs with. */
#define KERNEL_DATE_FORMAT (base + 0x78) /* "date: %d/%d/%d (%d)" */
#define KERNEL_TIME_FORMAT (base + 0x8C) /* "time: %d:%02d:%02d" */
#define KERNEL_STACK_CHECK_NAME (base + 0xA0) /* "check_stack" */

#pragma scheduling on
/* Start-up: bring up the OS and every engine subsystem in order, log the date and time
 * the game started, then arm the stack watermark check - fn_802E27F0 fills the guard
 * area with 0x53FFEEDD and fn_802E2A1C, registered under the name "check_stack",
 * reports "STACK OVERRUN!" once that marker is gone.  Returning 1 is main()'s cue to
 * run the matching shutdown (KERNEL_Shutdown) and panic. */
int KERNEL_Init(void) {
    /* Bring up the OS and all engine subsystems in order, log the console's
     * start date/time, arm the stack guard, and return 1 so main() runs the
     * matching shutdown. */
    struct StartupCalendar startTime;
    char * const base = lbl_8034CCE0;
    OSInit();
    fn_8005954C();
    LCEnable();
    fn_802E77A8();
    fn_802E3498();
    fn_801293B4();
    Abend_InitLog();
    fn_802E2A54();
    fn_8012820C(0x02000000);
    ConfigReadSystemSettings();
    fn_802E7318();
    fn_802E46B0();
    fn_80127C8C();
    fn_802E8CA8();
    fn_80127538();
    fn_80129790();
    Spu_Init();
    initStrmBank();
    fn_802EBE2C();
    fn_802CF600();
    fn_802EC614();
    KERNEL_ReadStartupCalendar(&startTime);
    fn_802E30C8(KERNEL_DATE_FORMAT, startTime.month, startTime.day, startTime.year, startTime.weekDay);
    fn_802E30C8(KERNEL_TIME_FORMAT, startTime.hour, startTime.minute, startTime.second);
    fn_802E27F0();
    fn_80127C90(fn_802E2A1C, KERNEL_STACK_CHECK_NAME);
    return 1;
}
extern void DCStoreRange(void *, int);
extern void fn_80127D58(void *);
extern void KERNEL_ReportStackUsage(void);
extern void fn_802EC7AC(void);
extern void fn_802CFBA8(void);
extern void fn_802EC038(void);
extern void destroyStrmBankManager(void);
extern void fn_802E56F0(void);
extern void fn_80129864(void);
extern void Profiler_PrintCountersReport(void);
extern void NandSaveShutdown(void);
extern void fn_80127EF8(void);
extern void fn_802E46E4(void);
extern void StreamEnd(void);
extern void ConfigShutdown(void);
extern void fn_801282A0(void);
extern void fn_802E2A58(void);
extern void fn_802E3090(void);
extern void fn_801293C4(void);
extern void File_ShutdownSubsystem(void);
extern void fn_802E77AC(void);
extern void fn_802E2A1C(void);
extern int fn_80004D64(void *);
extern int KERNEL_Init(void);
extern void fn_80004E20(void);
extern void KERNEL_Shutdown(void);
/* Shut down every engine/kernel subsystem in reverse startup order; unregister the stack-overrun check first. */
void KERNEL_Shutdown(void) {
    fn_80127D58((void *)fn_802E2A1C); /* unregister stack check callback */
    KERNEL_ReportStackUsage();
    fn_802EC7AC();
    fn_802CFBA8();
    fn_802EC038();
    destroyStrmBankManager();
    fn_802E56F0();
    fn_80129864();
    Profiler_PrintCountersReport();
    NandSaveShutdown();
    fn_80127EF8();
    fn_802E46E4();
    StreamEnd();
    ConfigShutdown();
    fn_801282A0();
    fn_802E2A58();
    fn_802E3090();
    fn_801293C4();
    File_ShutdownSubsystem();
    fn_802E77AC();
}
extern void OSPanic(const char *, int, const char *, ...);
extern char lbl_8034CD8C[];
__declspec(section ".sdata") extern char lbl_8055D174[];
int main(void) {
    int bootArgs[0x40] = {0};

    /* Initialize from boot arguments, run the main loop, then shut down; panic if it returns. */
    if (fn_80004D64(bootArgs) != 0) {
        if (KERNEL_Init() != 0) {
            fn_80004E20();
            KERNEL_Shutdown();
        }
    }

    OSPanic(lbl_8034CD8C, 0xD2, lbl_8055D174);
    return 0;
}

#pragma scheduling invalid_target
unsigned int KERNEL_GetTimeMs(void) {
    unsigned long long now;
    unsigned long long diff;
    unsigned int baseHigh;
    unsigned int baseLow;
    unsigned int ticks;
    unsigned int factor;
    now = OSGetTime();
    if ((*(volatile int *)&kernelBootTicks | *(volatile unsigned int *)&lbl_8055FEFC) == 0) {
        *(volatile unsigned int *)&lbl_8055FEFC = (unsigned int)now;
        *(volatile int *)&kernelBootTicks = (unsigned int)(now >> 32);
    }
    baseLow = *(volatile unsigned int *)&lbl_8055FEFC;
    ticks = *(volatile unsigned int *)0x800000F8;
    factor = (ticks >> 2) / 1000;
    baseHigh = *(volatile unsigned int *)&kernelBootTicks;
    diff = now - (((unsigned long long)baseHigh << 32) | baseLow);
    return (unsigned int)__div2i(diff, factor);
}
#pragma scheduling on
extern int kernelBootTicks;
extern unsigned int lbl_8055FEFC;
extern unsigned long long __div2i(unsigned long long, unsigned long long);
#pragma scheduling invalid_target
unsigned long long KERNEL_GetTimeUs(void)
{
  /* Return microseconds elapsed since boot: convert OSGetTime ticks using the
   * bus clock and the boot tick count stored in kernelBootTicks. */
  unsigned long long now = OSGetTime();
  unsigned long long elapsed = now - (*((unsigned long long *) (&kernelBootTicks)));
  unsigned int busClock = (*((volatile unsigned int *) 0x800000F8)) & 0xFFFFFFFF;
  unsigned int scale = (busClock >> 2) / 125000;
  return __div2i(elapsed << 3, scale);
}
#pragma scheduling on
/* Store the console's real date and time (RTC ticks from OSGetTime(), broken
 * out by OSTicksToCalendarTime()) into the halfword-packed calendar struct
 * KERNEL_Init logs "date:" and "time:" from at start-up.  The month is kept
 * 1-12 here, unlike the OS calendar's 0-11. */
/* Read the console RTC and store the current date/time into the halfword-packed startup calendar, converting the month from 0-based to 1-based. */ void KERNEL_ReadStartupCalendar(void *calendarOut) {
    struct OSTimeCalendar calendar;
    struct StartupCalendar *out = (struct StartupCalendar *)calendarOut;

    OSTicksToCalendarTime(OSGetTime(), &calendar);
    out->second = (short)calendar.sec;
    out->minute = (short)calendar.min;
    out->hour = (short)calendar.hour;
    out->day = (short)calendar.mday;
    out->month = (short)(calendar.month + 1);
    out->year = (short)calendar.year;
    out->weekDay = calendar.wday;
    out->msec = calendar.msec;
}
#pragma scheduling invalid_target
/* Busy-wait until the microsecond timer from KERNEL_GetTimeUs shows that
 * `milliseconds` have elapsed, quitting early if the timer jumps backwards. */
void KERNEL_WaitMilliseconds(int milliseconds) {
    /* Busy-wait until KERNEL_GetTimeUs has advanced by milliseconds * 1000 us;
     * also stop if the microsecond counter wraps backwards. */
    long long limitUs = (long long)milliseconds * 1000;
    u64 startUs = KERNEL_GetTimeUs();
    u64 nowUs;
    for (;;) {
        nowUs = KERNEL_GetTimeUs();
        if ((long long)(nowUs - startUs) >= limitUs || (long long)nowUs < (long long)startUs) {
            break;
        }
    }
}
#pragma scheduling on
/* Append a reset callback and the name it logs under to the parallel registration tables. */ void KERNEL_AddResetCallback(int callback, int logName) {
    /* Append a reset callback and its log name to the parallel registration tables. */
    int index = sResetCallbackCount;
    sResetCallbackCount = index + 1;
    sResetCallbacks[index] = callback;
    sResetCallbackNames[index] = logName;
}
/* Reset / power-down.
 * A subsystem that has to wind down before the console leaves the game
 * registers with KERNEL_AddResetCallback(callback, name):
 *   sResetCallbacks[]  the registered callbacks
 *   sResetCallbackNames[]  the name a callback logs under when it cancels a reset
 *   sResetCallbackCount    how many are registered
 * KERNEL_Reset runs the table, then resets. */
typedef int (*ResetCallback)(int request, int mode);

/* First argument handed to a reset callback. */
#define KERNEL_RESET_ASK 0 /* may we reset?  answer 1 to cancel it */
#define KERNEL_RESET_NOTIFY 1 /* the reset is on: save, close, stop */

/* The mode KERNEL_Reset is asked for (the Home Menu hands back its own). */
#define KERNEL_MODE_RESTART 0 /* hot-reset the console */
#define KERNEL_MODE_MENU 1 /* back to the Wii Menu */
#define KERNEL_MODE_STANDBY 2 /* power the console off */

/* WPAD keeps reporting this while the controllers are still powering down. */
#define KERNEL_WPAD_SHUTTING_DOWN 4

/* The strings of this file's block at lbl_8034CCE0 that the reset path logs with. */
#define KERNEL_LOG_RESET_BEGIN (base + 0xB8) /* "resetting system..." */
#define KERNEL_LOG_CANCELLED (base + 0xCC) /* " reset cancelled by %s" */
#define KERNEL_LOG_RESET_OKAY (base + 0xE4) /* "kernel: reset is okay" */
#define KERNEL_LOG_CANCEL_DVD (base + 0xFC) /* "kernel: cancelling DVD..." */
#define KERNEL_LOG_DVD_FAIL (base + 0x118) /* "DVDCancelAll fails" */
#define KERNEL_LOG_RESET_MODE (base + 0x12C) /* "doing reset %d" */
#define KERNEL_LOG_RESTART (base + 0x13C) /* "kernel: doing restart" */
#define KERNEL_LOG_DISC_ERROR (base + 0x154) /* "kernel: restart during disk error (go to menu)" */
#define KERNEL_LOG_POWER_DOWN (base + 0x184) /* "kernel: doing power down" */
#define KERNEL_LOG_WAIT_WPAD (base + 0x1A0) /* "kernel: waiting for WPAD to shut down" */
#define KERNEL_LOG_WPAD_DOWN (base + 0x1C8) /* "kernel: WPAD has shut down" */
#define KERNEL_LOG_MENU (base + 0x1E4) /* "kernel: doing return to menu" */

extern int fn_80039840(void); /* DVDCancelAll: non-zero when the cancel failed */
extern int fn_802D9BF0(void); /* the disc/drive error state is set */
extern int fn_802D9C04(void); /* that state is 1: the reset button, not a bad disc */
extern int fn_8005EE7C(void); /* WPAD shutdown status */
extern void fn_800527CC(int); /* OSReset: hot-reset the console */
extern void fn_8005ED8C(void); /* WPADiClose: start the controllers powering down */
extern void OSReturnToMenu(void);
extern void OSShutdownSystem(void);

#pragma push
#pragma scheduling invalid_target
/* Leave the game and hand the console back, in `mode`: KERNEL_MODE_RESTART
 * hot-resets, KERNEL_MODE_STANDBY powers off and anything else returns to the
 * Wii Menu.  Every subsystem registered a reset callback with KERNEL_AddResetCallback;
 * each is first asked whether the reset may go ahead - the first one to answer
 * 1 cancels the whole thing and is named in the log - and otherwise told, last
 * registered first, that it is happening.  The DVD drive's queued requests are
 * cancelled next, and a restart falls back to the Wii Menu when the disc is
 * misbehaving rather than the reset button having been held. */
/* Leave the game and hand the console back in `mode`: ask every registered reset callback for a veto (first one answering 1 cancels and is logged), notify the rest last-registered-first, cancel queued DVD requests, then restart, power down, or return to the Wii Menu. */ void KERNEL_Reset(int mode) {
    char *base = lbl_8034CCE0;
    ResetCallback *callback;
    ResetCallback *last;
    int i;
    int n;

    /* Ask every subsystem whether the reset may go ahead. */
    fn_802E30C8(KERNEL_LOG_RESET_BEGIN);
    callback = (ResetCallback *)sResetCallbacks;
    for (i = 0; i < sResetCallbackCount; callback++, i++) {
        if ((*callback)(KERNEL_RESET_ASK, mode) == 1) {
            fn_802E30C8(KERNEL_LOG_CANCELLED, (const char *)sResetCallbackNames[i]);
            return;
        }
    }
    /* Nobody objected: tell them all, last registered first. */
    fn_802E30C8(KERNEL_LOG_RESET_OKAY);
    n = sResetCallbackCount - 1;
    last = (ResetCallback *)sResetCallbacks + n;
    for (; n >= 0; last--, n--) {
        (*last)(KERNEL_RESET_NOTIFY, mode);
    }
    fn_802E30C8(KERNEL_LOG_CANCEL_DVD);
    if (fn_80039840()) fn_802E30C8(KERNEL_LOG_DVD_FAIL);
    fn_802E30C8(KERNEL_LOG_RESET_MODE, mode);
    if (mode == KERNEL_MODE_RESTART) {
        if (fn_802D9BF0() == 0 || fn_802D9C04() != 0) {
            fn_802E30C8(KERNEL_LOG_RESTART);
            fn_800527CC(0);
        } else {
            fn_802E30C8(KERNEL_LOG_DISC_ERROR);
            OSReturnToMenu();
        }
        return;
    }
    if (mode == KERNEL_MODE_STANDBY) {
        fn_802E30C8(KERNEL_LOG_POWER_DOWN);
        fn_8005ED8C();
        fn_802E30C8(KERNEL_LOG_WAIT_WPAD);
        while (fn_8005EE7C() == KERNEL_WPAD_SHUTTING_DOWN) {}
        fn_802E30C8(KERNEL_LOG_WPAD_DOWN);
        OSShutdownSystem();
        return;
    }
    fn_802E30C8(KERNEL_LOG_MENU);
    OSReturnToMenu();
}
#pragma pop

#pragma scheduling invalid_target
void KERNEL_PlatExitProcess(int exitCode) {
    /* Log "PlatExitProcess(%d)" with the given exit code. */
#define KERNEL_LOG_PLAT_EXIT lbl_8034CEE4
    Abend_Panic(KERNEL_LOG_PLAT_EXIT, exitCode);
#undef KERNEL_LOG_PLAT_EXIT
}
#pragma scheduling on
extern unsigned int roundUpPow2(unsigned int);
extern void fn_802E1780(void *, unsigned int, int);
extern int fn_802E1804(void *, void *, int, int, int);
extern int initGXTexObj(int, int, int, int, void *, int);
extern void DCFlushRange(void *, int);

extern void DCStoreRange(void *, int);
extern void fn_80127D58(void *);
extern void KERNEL_ReportStackUsage(void);
extern void fn_802EC7AC(void);
extern void fn_802CFBA8(void);
extern void fn_802EC038(void);
extern void destroyStrmBankManager(void);
extern void fn_802E56F0(void);
extern void fn_80129864(void);
extern void Profiler_PrintCountersReport(void);
extern void NandSaveShutdown(void);
extern void fn_80127EF8(void);
extern void fn_802E46E4(void);
extern void StreamEnd(void);
extern void ConfigShutdown(void);
extern void fn_801282A0(void);
extern void fn_802E3090(void);
extern void fn_801293C4(void);
extern void File_ShutdownSubsystem(void);
extern void fn_802E77AC(void);
extern int fn_80004D64(void *);
extern int KERNEL_Init(void);
extern void fn_80004E20(void);
extern void OSPanic(const char *, int, const char *, ...);
extern char lbl_8034CD8C[];
extern char lbl_8055D174[];
extern void KERNEL_Shutdown(void);

