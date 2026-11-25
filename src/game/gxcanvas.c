// gxcanvas — gx canvas/stamp images ("gxCanvasGet(%s): wrong ver").
// Recovered TU window 0x802C2CAC..0x802C5028+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802C5028 (+ .ctors slot 0x802ED59C) remains in
// auto/text_802C5028_.c pending a promotion pass.
#include <types.h>
extern const char lbl_8034B078[];
extern const char lbl_8034B0E4[];
extern void gxCanvasCopy16to16(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3C68(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3D74(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3F00(s32,s32,s32,s32,s32,s32,s32,s32);

extern u8 gDefaultPixelFormat;
extern u8 lbl_8055D000;
extern void *fn_801284E8(void *, s32);
void fn_802C2CE8(void *, s32, s32, s8);
void gxCanvasResetClipRect(void *);

void fn_802C5024(s32, s32, s32, s32);

/* The built-in canvas font: a fixed-pitch bitmap face, one cell per character. */
#define CANVAS_CHAR_WIDTH   8    /* pixels a character advances */
#define CANVAS_CHAR_UNKNOWN '#'  /* drawn for anything outside printable ASCII */
#define DrawCanvasChar      fn_802C5024 /* one character at (x,y) in a colour; empty in this build */

extern void fn_8012C4D8(void);

/* One drawing canvas, the object every gxCanvas* routine in this file works
   on.  The one being drawn on is the pointer kept in lbl_8055FC00
   (gxCanvasSwitch swaps it); fn_802C2CE8 builds one from scratch. */
typedef struct GxCanvas {
    /* 0x00 pixel format: 5 keeps 4-byte pixels (rowBytes = width * 4),
     * 6 is no format this build draws, every other value 2-byte RGB565
     * ones.  Of those, 1 is the 4-bit-component one that keeps the old
     * alpha nibble when filled.  The drawing code sign-extends it before
     * comparing. */
    u8 format;
    /* 0x01 flags; fn_802C2CE8 starts a fresh canvas at 0x82.  Bit 0x4 marks
     * a canvas that must not be drawn on: the plotters return without
     * writing, and fn_802C40B8 only calls the empty fn_802DB2C8. */
    u8 flags;
    void *pixels; /* 0x04 first pixel of the first row */
    s32 width;    /* 0x08 pixels per row */
    s32 height;   /* 0x0C rows */
    s32 rowBytes; /* 0x10 bytes from one row to the next */
    s32 minX;     /* 0x14 clip rectangle the plotters test every point */
    s32 minY;     /* 0x18 against: fn_802C3130 (a point), fn_802C307C */
    s32 maxX;     /* 0x1C (a rectangle) */
    s32 maxY;     /* 0x20 */
} GxCanvas;       /* 0x24: fn_802C2D94 memsets the whole block on free */

#define CANVAS_FLAG_NO_DRAW 0x04 /* GxCanvas.flags: drawing is turned off */
#define CANVAS_FORMAT_RGBA4444 1 /* GxCanvas.format: 4-bit components; the fillers keep the destination's alpha nibble (gxCanvasFillRectRGBA4444) */
#define CANVAS_FORMAT_RGB1555 3  /* GxCanvas.format: X1R5G5B5, blue in the low 5 bits */
#define CANVAS_FORMAT_RGB565  4  /* GxCanvas.format: R5G6B5, blue in the low 5 bits */
#define CANVAS_FORMAT_RGBA  5    /* GxCanvas.format: 4-byte pixels */
#define CANVAS_FORMAT_NONE  6    /* GxCanvas.format: 4-byte sized, undrawn */

extern s32 lbl_8055FC00; /* the canvas the gxCanvas* routines below draw on:
                          * {s8 format; u8 flags; void *pixels; s32 width, height,
                           *  rowBytes; s32 minX, minY, maxX, maxY;} — format 5 keeps 4-byte pixels
 *  (rowBytes = width * 4), every other format 2-byte ones; +0x14..+0x20 is
 *  the clip rectangle fn_802C3130/fn_802C307C test against */
extern void fn_802C3754(s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_802DB2C8(void);
extern void gxCanvasFillRect16(s32, s32, s32, s32, u32);
extern void gxCanvasFillRectRGBA(s32, s32, s32, s32, u32);
extern void gxCanvasFillRectRGBA4444(s32, s32, s32, s32, u32);
#pragma scheduling invalid_target
#pragma push
#pragma peephole off
/* Expand one RGB1555 (canvas format 3) pixel into a GX RGBA word: R5/G5/B5 into the colour channels and alpha forced to 0xFF. */ s32 gxCanvasConvert1555ToRGBA(s32 rgb1555) {
    /* Convert a 16-bit packed pixel from a format-3 canvas into a 32-bit GX
       RGBA color word for blitting into a 4-byte-per-pixel canvas (fn_802C3D74). */
    unsigned int rgbaHigh = __rlwinm(rgb1555, 9, 8, 12);
    unsigned int rgbaLow;
    rgbaHigh |= 0xFF000000;
    rgbaLow = __rlwinm(rgb1555, 3, 24, 28);
    rgbaHigh = __rlwimi(rgbaHigh, rgb1555, 6, 16, 20);
    return (s32)(rgbaLow | rgbaHigh);
}
#pragma pop
#pragma push
#pragma peephole off
/* Expand one RGB565 (canvas format 4) pixel into a GX RGBA word: R5/G6/B5 scaled into the colour channels and alpha forced to 0xFF. */
s32 gxCanvasConvert565ToRGBA(s32 rgb565) {
    /* Convert a 16-bit packed pixel from a format-4 canvas into a 32-bit GX
       RGBA color word for blitting into a 4-byte-per-pixel canvas (fn_802C3D74). */
    unsigned int rgbaLow = (rgb565 << 3) & 0xF8;
    return (s32)(rgbaLow | __rlwimi(__rlwinm(rgb565, 8, 8, 12) | 0xFF000000, rgb565, 5, 16, 21));
}
#pragma pop

#define Convert565ToRGBA gxCanvasConvert565ToRGBA /* one RGB565 (format 4) pixel -> 0x00RRGGBB word */
#define Convert555ToRGBA gxCanvasConvert1555ToRGBA /* one RGB1555 (format 3) pixel -> 0x00RRGGBB word */
/* Build a canvas of the given size using the default pixel format held in gDefaultPixelFormat (3 in this build). */
void gxCanvasCreateDefault(void *canvas, s32 width, s32 height) {
    fn_802C2CE8(canvas, width, height, (s8)gDefaultPixelFormat);
}

void fn_802C2CE8(void *arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 prod;
    *(s8 *)arg0 = arg3;
    ((u8 *)arg0)[1] = 0x82;
    prod = arg1 * arg2;
    *(void **)((u8 *)arg0 + 4) = fn_801284E8(&lbl_8055D000, prod * ((arg3 == 5) ? 4 : 2));
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC) = arg2;
    *(s32 *)((u8 *)arg0 + 0x10) = arg1 * ((arg3 == 5) ? 4 : 2);
    gxCanvasResetClipRect(arg0);
}

/* Free a GxCanvas: release its pixel buffer, then zero the whole canvas block. */ void fn_802C2D94(void *canvas) {
    /* Free a canvas: release its pixel buffer (+0x4) then zero the whole GxCanvas block. */
    fn_80128658((s32)((GxCanvas *)canvas)->pixels);
    memset(canvas, 0, sizeof(GxCanvas));
}

extern void *fn_8012C370(s32,u32 *,s32 *,s32,u8 *);
extern void Abend_Panic(const char *,...);
extern const char gxCanvasWrongVerFmt[],gxCanvasLoadFailFmt[];
#pragma scheduling invalid_target
/* Load the CANV canvas image at path; for version-1 data flagged big-endian, swap the header fields in place and rotate each pixel into GX RGBA order. Panics if the lookup fails or the version is unsupported. */
void *gxCanvasLoad(s32 path) {
    u32 version;
    s32 byteSize;
    u8 needsSwap;
    u32 *pixels;
    s32 row;
    s32 col;
    u32 pixel;
    u8 temp;
    void *canvas;

    canvas = ((void *(*)(s32, s32, u32 *, s32 *, s32, u8 *))fn_8012C370)(path, 0x43414E56, &version, &byteSize, 0, &needsSwap);
    if (canvas != 0) {
        if (version == 1) {
            if (needsSwap != 0) {
                volatile u8 *bytes = (volatile u8 *)canvas;
                pixels = (u32 *)(bytes + 0x24);
                temp = bytes[4]; bytes[4] = bytes[7]; bytes[7] = temp;
                temp = bytes[5]; bytes[5] = bytes[6]; bytes[6] = temp;
                temp = bytes[8]; bytes[8] = bytes[11]; bytes[11] = temp;
                temp = bytes[9]; bytes[9] = bytes[10]; bytes[10] = temp;
                temp = bytes[12]; bytes[12] = bytes[15]; bytes[15] = temp;
                temp = bytes[13]; bytes[13] = bytes[14]; bytes[14] = temp;
                temp = bytes[16]; bytes[16] = bytes[19]; bytes[19] = temp;
                temp = bytes[17]; bytes[17] = bytes[18]; bytes[18] = temp;
                temp = bytes[20]; bytes[20] = bytes[23]; bytes[23] = temp;
                temp = bytes[21]; bytes[21] = bytes[22]; bytes[22] = temp;
                temp = bytes[24]; bytes[24] = bytes[27]; bytes[27] = temp;
                temp = bytes[25]; bytes[25] = bytes[26]; bytes[26] = temp;
                temp = bytes[28]; bytes[28] = bytes[31]; bytes[31] = temp;
                temp = bytes[29]; bytes[29] = bytes[30]; bytes[30] = temp;
                temp = bytes[32]; bytes[32] = bytes[35]; bytes[35] = temp;
                temp = bytes[33]; bytes[33] = bytes[34]; bytes[34] = temp;
                *(void **)(bytes + 4) = pixels;
                for (row = 0; row < *(volatile s32 *)(bytes + 0xC); row++) {
                    for (col = 0; col < *(volatile s32 *)(bytes + 8); col++) {
                        pixel = *pixels;
                        *pixels = (pixel << 24) | (pixel >> 8);
                        pixels++;
                    }
                }
            }
        } else {
            Abend_Panic(gxCanvasWrongVerFmt, path, version, 1);
        }
    } else {
        Abend_Panic(gxCanvasLoadFailFmt, path);
    }
    return canvas;
}
#pragma scheduling on
void fn_802C2FC4(void) {
    /* Drop one reference on a resource handle: tail-call the shared
       resource-manager release (fn_8012C4D8), leaving the handle in r3. */
    ((void (*)(void))fn_8012C4D8)();
}

#pragma push
#pragma scheduling invalid_target
/* Set a GxCanvas clip rectangle: min corner from the unsigned args (masked to the s32 range), max corner capped by the canvas width/height and the signed args. */ void gxCanvasSetClipRect(void *canvas, u32 newMinX, u32 newMinY, s32 newMaxX, s32 newMaxY)
{
  s32 clampedMaxY;
  s32 clampedMaxX;
  clampedMaxX = (0, *((s32 *) (((u8 *) canvas) + 8)));
  *((s32 *) (((u8 *) canvas) + 0x14)) = (s32) (newMinX & ((newMinX >> 31) - 1));
  *((s32 *) (((u8 *) canvas) + 0x18)) = (s32) (newMinY & ((newMinY >> 31) - 1));
  if (newMaxX < clampedMaxX)
  {
    clampedMaxX = newMaxX;
  }
  clampedMaxY = *((s32 *) (((u8 *) canvas) + 0xC));
  *((s32 *) (((u8 *) canvas) + 0x1C)) = clampedMaxX;
  if (newMaxY < clampedMaxY)
  {
    clampedMaxY = newMaxY;
  }
  *((s32 *) (((u8 *) canvas) + 0x20)) = clampedMaxY;
}
#pragma pop
/* Resets a canvas's clip rectangle to the whole surface: {0, 0, width, height}. */
/* Resets a canvas's clip rectangle to cover the whole surface: min corner (0, 0), max corner (width, height). */ /* Resets a canvas's clip rectangle to cover the whole surface: min corner (0, 0), max corner (width, height). */ void gxCanvasResetClipRect(void *arg0) {
    GxCanvas *canvas = arg0;
    canvas->minX = 0;
    canvas->minY = 0;
    canvas->maxX = canvas->width;
    canvas->maxY = canvas->height;
}

#define sCurrentCanvas lbl_8055FC00 /* the canvas the gxCanvas* routines draw on */
/* Make a canvas the current drawing target and return the canvas it replaced. */ s32 gxCanvasSwitch(s32 newCanvas) {
    s32 oldCanvas;

    // Make newCanvas the current drawing canvas and return the one it replaced.
    oldCanvas = sCurrentCanvas;
    sCurrentCanvas = newCanvas;
    return oldCanvas;
}

/* Return the address of the 16-bit pixel at (x, y): pixels + y * rowBytes + x * 2. */
s32 gxCanvasGetPixelAddr(void *canvas, s32 x, s32 y) {
    return ((GxCanvas *)canvas)->rowBytes * y + ((s32)((GxCanvas *)canvas)->pixels + x * 2);
}

/* Address of the 4-byte pixel at (x, y): rowBytes * y + (pixels + x * 4). */
s32 gxCanvasGetPixelAddr32(void *canvasPtr, s32 x, s32 y) {
    GxCanvas *canvas = canvasPtr;
    return canvas->rowBytes * y + ((s32)canvas->pixels + x * 4);
}

s32 fn_802C307C(void *arg0, s32 *left, s32 *top, s32 *right, s32 *bottom) {
    /* Clip the rectangle (*left,*top)-(*right,*bottom) to the canvas's clip
       rectangle, updating the corners in place; returns nonzero if non-empty. */
    s32 leftValue = *left;
    s32 bound;
    s32 rightBound;
    if (leftValue >= ((GxCanvas *)arg0)->maxX) return 0;
    if (*top >= ((GxCanvas *)arg0)->maxY) return 0;
    bound = ((GxCanvas *)arg0)->minX;
    if (leftValue < bound) *left = bound;
    bound = ((GxCanvas *)arg0)->minY;
    if (*top < bound) *top = bound;
    bound = ((GxCanvas *)arg0)->maxX;
    if (*right > bound) *right = bound;
    rightBound = ((GxCanvas *)arg0)->maxY;
    if (*bottom > rightBound) *bottom = rightBound;
    if (*left >= *right) return 0;
    return *top < *bottom;
}

/* Hit test: return 1 when (x, y) lies in the canvas's clip rectangle [minX,maxX) by [minY,maxY), else 0. */
/* Return 1 when point (x, y) lies in the canvas clip rect [minX,maxX) x [minY,maxY), else 0. */ s32 fn_802C3130(void *canvas, s32 x, s32 y) {
    GxCanvas *c = (GxCanvas *)canvas;
    if (x >= c->minX && y >= c->minY && x < c->maxX && y < c->maxY) return 1;
    return 0;
}

s32 gxCanvasClipBlitRect(void *bounds, s32 *x, s32 *y, s32 *srcX, s32 *srcY, s32 *w, s32 *h) {
    /* Clip a source/destination rectangle to the bounds at bounds+0x14/18/1C/20, adjusting positions and sizes; returns nonzero if anything remains. */
    s32 temp_r0, temp_r0_2, deltaX, rectY2, rectX, rectY, leftBound;
    s32 bottomBound, width, height2, topBound, topDelta, rightBound;
    rectX = *x;
    leftBound = *(s32 *)((u8 *)bounds + 0x14);
    if (rectX + *w < leftBound) return 0;
    rectY = *y;
    if (rectY + *h < *(s32 *)((u8 *)bounds + 0x18)) return 0;
    if (rectX >= *(s32 *)((u8 *)bounds + 0x1C)) return 0;
    if (rectY >= *(s32 *)((u8 *)bounds + 0x20)) return 0;
    if (rectX < leftBound) {
        deltaX = leftBound - rectX;
        *srcX += deltaX;
        *w -= deltaX;
        *x = *(s32 *)((u8 *)bounds + 0x14);
    }
    topBound = *(s32 *)((u8 *)bounds + 0x18);
    rectY2 = *y;
    if (rectY2 < topBound) {
        topDelta = topBound - rectY2;
        *srcY += topDelta;
        *h -= topDelta;
        *y = *(s32 *)((u8 *)bounds + 0x18);
    }
    temp_r0 = *x;
    width = *w;
    rightBound = *(s32 *)((u8 *)bounds + 0x1C);
    temp_r0 += width;
    if (temp_r0 > rightBound) *w = width - (temp_r0 - rightBound);
    temp_r0_2 = *y;
    height2 = *h;
    bottomBound = *(s32 *)((u8 *)bounds + 0x20);
    temp_r0_2 += height2;
    if (temp_r0_2 > bottomBound) *h = height2 - (temp_r0_2 - bottomBound);
    if (*w <= 0) return 0;
    return *h > 0;
}

extern const char lbl_8034B060[];
extern void fn_802C3320(s32 x, s32 y, u32 packedValue);
extern void fn_802C33A8(s32, s32, u32);
extern void Abend_Panic(const char *, ...);
/* Plot one pixel of the active canvas at (x, y): ignore NO_DRAW canvases, dispatch to the 16-bit or RGBA plotter by format, else panic on the unsupported format. */ void gxPoint(s32 x, s32 y, u32 color) {
    /* Plot one pixel of the active canvas at (x, y).  A canvas with the NO_DRAW
     * flag is left alone; a 16-bit one takes the colour's high half through
     * fn_802C3320, a 4-byte (format 5) one through fn_802C33A8, and format 6
     * (undrawable in this build) only triggers a bad-format panic. */
    GxCanvas *canvas = (GxCanvas *)lbl_8055FC00;
    u8 format;
    s32 is16Bit;
    if (canvas->flags & CANVAS_FLAG_NO_DRAW) return;
    format = canvas->format;
    is16Bit = 0;
    if ((s8)format != CANVAS_FORMAT_RGBA && (s8)format != CANVAS_FORMAT_NONE) is16Bit = 1;
    if (is16Bit != 0) {
        fn_802C3320(x, y, color);
        return;
    }
    if ((s8)format == CANVAS_FORMAT_RGBA) {
        fn_802C33A8(x, y, color);
        return;
    }
    Abend_Panic(lbl_8034B060, (s32)*(volatile s8 *)canvas);
}

#pragma push
#pragma inline_depth(0)
/* Plot a 16-bit pixel at (x, y) on the active canvas: inside the clip bounds, write the low half of packedValue when the canvas format is 3, otherwise its high half. */
void fn_802C3320(s32 x, s32 y, u32 packedValue) {
    u32 halfValue;
    if (fn_802C3130((void *)lbl_8055FC00, x, y) != 0) {
        halfValue = packedValue >> 16;
        if ((s8)*(u8 *)lbl_8055FC00 == 3)
            halfValue = packedValue & 0xFFFF;
        *(u16 *)gxCanvasGetPixelAddr((void *)lbl_8055FC00, x, y) = (u16)halfValue;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(0)
/* Plot one opaque RGBA pixel on the current GxCanvas at (x, y) when that point
 * lies inside the clip rectangle; the RGB565 colour is widened to 4-byte RGBA. */
/* Plot one opaque RGBA pixel on the current GxCanvas at (x, y) when the point is inside the clip rectangle; widen the RGB565 colour into a 4-byte pixel. */ void fn_802C33A8(s32 x, s32 y, u32 rgb565) {
    u32 *pixel;
    u32 rgba;
    if (fn_802C3130((void *)sCurrentCanvas, x, y) != 0) {
        pixel = (u32 *)gxCanvasGetPixelAddr32((void *)sCurrentCanvas, x, y);
        rgba = ((rgb565 >> 8) & 0x00F80000) | 0xFF000000; /* red, and the opaque alpha */
        rgba = (rgba & ~0x0000FC00) | ((rgb565 >> 11) & 0x0000FC00); /* green */
        rgba = (rgba & ~0x000000F8) | ((rgb565 >> 13) & 0x000000F8); /* blue */
        *pixel = rgba;
    }
}

/* Fill a rectangle on the active GxCanvas, dispatching by pixel format to the 16-bit, RGBA4444, or 4-byte RGBA filler. */
void gxCanvasFillRect(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    s8 format = *(s8 *)lbl_8055FC00;
    s32 is16Bit = 0;
    if (format != CANVAS_FORMAT_RGBA && format != CANVAS_FORMAT_NONE)
        is16Bit = 1;
    if (is16Bit != 0) {
        if (*(volatile s8 *)lbl_8055FC00 != CANVAS_FORMAT_RGBA4444) {
            gxCanvasFillRect16(x0, y0, x1, y1, color);
            return;
        }
        gxCanvasFillRectRGBA4444(x0, y0, x1, y1, color);
        return;
    }
    if (*(volatile s8 *)lbl_8055FC00 != CANVAS_FORMAT_RGBA)
        return;
    gxCanvasFillRectRGBA(x0, y0, x1, y1, color);
}

#pragma pop

#pragma push
#pragma processor 750
#pragma inline_depth(0)
void gxCanvasFillRect16(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    u32 pixel;
    s32 width, height, skip, n;
    u16 *p;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    pixel = color >> 16;
    width = x1 - x0;
    height = y1 - y0;
    if (*(u8 *)lbl_8055FC00 == 3) pixel = (u16)color;
    p = (u16 *)gxCanvasGetPixelAddr((void *)lbl_8055FC00, x0, y0);
    skip = (*(s32 *)((u8 *)lbl_8055FC00 + 0x10) - width * 2) / 2;
    do {
        n = width;
        do {
            --n;
            *p++ = pixel;
        } while (n > 0);
        --height;
        p += skip;
    } while (height > 0);
}
#pragma pop

#pragma push
#pragma optimize_for_size off
#pragma use_lmw_stmw off
#pragma inline_depth(0)
/* Fill a clipped x0,y0-x1,y1 rectangle on the current 4-byte canvas, widening the
 * RGB565 value packed in packedColor into opaque RGBA5551 pixels. */
void gxCanvasFillRectRGBA(s32 x0, s32 y0, s32 x1, s32 y1, u32 packedColor) {
    u32 rgba;
    s32 width, height, rowSkip, colCount;
    u32 *pixels;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    rgba = ((packedColor >> 8) & 0xF80000) | 0xFF000000;
    rgba = (rgba & ~0xFC00) | ((packedColor >> 11) & 0xFC00);
    width = x1 - x0;
    height = y1 - y0;
    rgba = (rgba & ~0xF8) | ((packedColor >> 13) & 0xF8);
    pixels = (u32 *)gxCanvasGetPixelAddr32((void *)lbl_8055FC00, x0, y0);
    rowSkip = (((GxCanvas *)lbl_8055FC00)->rowBytes - width * 4) / 4;
    do {
        colCount = width;
        do {
            --colCount;
            *pixels++ = rgba;
        } while (colCount > 0);
        --height;
        pixels += rowSkip;
    } while (height > 0);
}

#pragma push
#pragma inline_depth(0)
#pragma processor 750
#pragma use_lmw_stmw off
#pragma optimize_for_size off
void gxCanvasFillRectRGBA4444(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    u32 pixel;
    u32 packed;
    s32 low;
    s32 width, height, n;
    u32 skip;
    u16 *p;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    low = (s32)((color * 8) & 0xF8) >> 4;
    width = x1 - x0;
    packed = __rlwinm(color, 29, 20, 23);
    packed = __rlwimi(packed, color, 30, 24, 27);
    pixel = low | packed;
    height = y1 - y0;
    p = (u16 *)gxCanvasGetPixelAddr((void *)lbl_8055FC00, x0, y0);
    skip = (*(s32 *)((u8 *)lbl_8055FC00 + 0x10) - width * 2);
    skip = (u32)((u8 *)(skip >> 31) + skip) & ~1;
    do {
        n = width;
        do {
            --n;
            *p = pixel | (*p & 0xF000);
            ++p;
        } while (n > 0);
        --height;
        p = (u16 *)((u8 *)p + skip);
    } while (height > 0);
}

/* Blit the rectangle (srcLeft,srcTop)-(srcRight,srcBottom) of srcCanvas onto
 * dstCanvas at (dstLeft,dstTop), picking the routine that matches the two pixel
 * formats: 16-bit -> 16-bit, 4-byte -> 4-byte, 16-bit -> 4-byte or
 * 4-byte -> 16-bit.  A format-6 canvas takes none of them: "unsupported copy". */
void fn_802C3754(s32 srcCanvas, s32 srcLeft, s32 srcTop, s32 srcRight, s32 srcBottom,
                 s32 dstCanvas, s32 dstLeft, s32 dstTop) {
    u8 srcFormat = *(u8 *)srcCanvas;
    s32 is16Bit = 0;
    if ((s8)srcFormat != CANVAS_FORMAT_RGBA && (s8)srcFormat != CANVAS_FORMAT_NONE) is16Bit = 1;
    if (is16Bit) {
        is16Bit = 0;
        if (*(s8 *)dstCanvas != CANVAS_FORMAT_RGBA && *(s8 *)dstCanvas != CANVAS_FORMAT_NONE) is16Bit = 1;
        if (is16Bit) {
            gxCanvasCopy16to16(srcCanvas,srcLeft,srcTop,srcRight,srcBottom,dstCanvas,dstLeft,dstTop);
            return;
        }
    }
    if ((s8)srcFormat == CANVAS_FORMAT_RGBA && (s32)*(u8 *)dstCanvas == CANVAS_FORMAT_RGBA) {
        fn_802C3C68(srcCanvas,srcLeft,srcTop,srcRight,srcBottom,dstCanvas,dstLeft,dstTop); /* 4-byte -> 4-byte */
        return;
    }
    is16Bit = 0;
    if ((s8)srcFormat != CANVAS_FORMAT_RGBA && (s8)srcFormat != CANVAS_FORMAT_NONE) is16Bit = 1;
    if (is16Bit && (s32)*(u8 *)dstCanvas == CANVAS_FORMAT_RGBA) {
        fn_802C3D74(srcCanvas,srcLeft,srcTop,srcRight,srcBottom,dstCanvas,dstLeft,dstTop); /* 16-bit -> 4-byte */
        return;
    }
    if ((s8)srcFormat == CANVAS_FORMAT_RGBA) {
        is16Bit = 0;
        if (*(s8 *)dstCanvas != CANVAS_FORMAT_RGBA && *(s8 *)dstCanvas != CANVAS_FORMAT_NONE) is16Bit = 1;
        if (is16Bit) {
            fn_802C3F00(srcCanvas,srcLeft,srcTop,srcRight,srcBottom,dstCanvas,dstLeft,dstTop); /* 4-byte -> 16-bit */
            return;
        }
    }
    Abend_Panic(lbl_8034B078, (s32)*(s8 *)srcCanvas, (s32)*(s8 *)dstCanvas);
}

#pragma pop

#pragma pop
extern const char lbl_8034B094[];
extern const char lbl_8034B124[];
extern void fn_802C4108();
extern void fn_802C4610();
extern void fn_802C4388();
extern void fn_802C4108(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C4610(s32,s32,s32,s32,s32,s32,s32,s32);
/* Alpha-blit the rectangle (srcLeft,srcTop)-(srcRight,srcBottom) of srcCanvas onto
 * dstCanvas at (dstLeft,dstTop), picking the routine that matches the two pixel
 * formats: 16-bit -> 16-bit, 4-byte -> 4-byte or 4-byte -> 16-bit.  A format-6
 * canvas takes none of them: "unsupported alpha blit". */
void fn_802C3850(s32 srcCanvas, s32 srcLeft, s32 srcTop, s32 srcRight, s32 srcBottom,
                 s32 dstCanvas, s32 dstLeft, s32 dstTop) {
    u8 srcFormat = *(u8 *)srcCanvas;
    s32 is16Bit = 0;
    if ((s8)srcFormat != CANVAS_FORMAT_RGBA && (s8)srcFormat != CANVAS_FORMAT_NONE) is16Bit = 1;
    if (is16Bit) {
        is16Bit = 0;
        if (*(s8 *)dstCanvas != CANVAS_FORMAT_RGBA && *(s8 *)dstCanvas != CANVAS_FORMAT_NONE) is16Bit = 1;
        if (is16Bit) {
            fn_802C4108(srcCanvas,srcLeft,srcTop,srcRight,srcBottom,dstCanvas,dstLeft,dstTop);
            return;
        }
    }
    if ((s8)srcFormat == CANVAS_FORMAT_RGBA && (s32)*(u8 *)dstCanvas == CANVAS_FORMAT_RGBA) {
        fn_802C4610(srcCanvas,srcLeft,srcTop,srcRight,srcBottom,dstCanvas,dstLeft,dstTop);
        return;
    }
    if ((s8)srcFormat == CANVAS_FORMAT_RGBA) {
        is16Bit = 0;
        if (*(s8 *)dstCanvas != CANVAS_FORMAT_RGBA && *(s8 *)dstCanvas != CANVAS_FORMAT_NONE) is16Bit = 1;
        if (is16Bit) {
            fn_802C4388(srcCanvas,srcLeft,srcTop,srcRight,srcBottom,dstCanvas,dstLeft,dstTop);
            return;
        }
    }
    Abend_Panic(lbl_8034B094, (s32)*(s8 *)srcCanvas, (s32)*(s8 *)dstCanvas);
}

extern s32 gxCanvasClipBlitRect(void *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern const char lbl_8034B0B8[];
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma processor 750
/* copy_16_to_16 (its own error string names it this): blit the rectangle
 * (srcLeft,srcTop)-(srcRight,srcBottom) of one 2-byte-pixel canvas onto the
 * destination at (dstLeft,dstTop).  The rectangle is clipped against the
 * destination's clip rectangle first, which moves the source origin along with
 * it; every row is then copied pixel by pixel, stepping over the pixels a row
 * does not hold on both sides.  Canvases of the same format copy straight
 * through; otherwise the pixels are converted on the way: RGB565 -> RGB1555
 * drops green's low bit, RGB1555 -> RGB565 repeats green's top bit into the
 * new low bit, and RGBA4444 -> RGB565 shifts each component up into its 565
 * field and drops the alpha nibble.  Any other pair of formats only traces
 * "copy_16_to_16: can't convert from %d to %d". */
/* Blit a clipped 2-byte-pixel canvas rectangle, converting pixels when source and destination formats differ. */ void gxCanvasCopy16to16(s32 srcCanvas, s32 srcLeft, s32 srcTop, s32 srcRight,
                 s32 srcBottom, s32 dstCanvas, s32 dstLeft, s32 dstTop) {
    u16 *srcPix, *src565, *src1555, *src4444;
    u16 *dstPix, *dst1555, *dst565, *dst565From4444;
    s32 width, height, clipY, clipX, srcY, srcX;
    s32 rowsLeft, savedHeight, savedWidth;
    s32 unused, srcRowSkip, dstRowSkip, packed565, greenLowBit;
    s32 pixelsLeft, pixelsLeft2, pixelsLeft3;
    register u16 converted;
    u16 pixel565, pixel4444, pixel1555;
    s8 srcFormat, dstFormat;

    srcX = srcLeft;
    srcY = srcTop;
    clipX = dstLeft;
    clipY = dstTop;
    width = srcRight - srcLeft;
    height = srcBottom - srcTop;
    /* Clip the rectangle against the destination's clip rectangle; the source
     * origin moves by however much of the rectangle was cut off. */
    if (gxCanvasClipBlitRect((void *)dstCanvas, &clipX, &clipY, &srcX, &srcY, &width,
                    &height) != 0) {
        srcPix = (u16 *)gxCanvasGetPixelAddr((void *)srcCanvas, srcX, srcY);
        dstPix = (u16 *)gxCanvasGetPixelAddr((void *)dstCanvas, clipX, clipY);
        savedWidth = width;
        savedHeight = height;
        /* Bytes to step over the pixels a row does not hold, rounded to whole
         * 16-bit pixels. */
        srcRowSkip = (((GxCanvas *)srcCanvas)->rowBytes - savedWidth * 2) / 2 * 2;
        dstRowSkip = (((GxCanvas *)dstCanvas)->rowBytes - savedWidth * 2) / 2 * 2;
        do {
            pixelsLeft = width;
copyPixel:
            *dstPix = *srcPix;
            pixelsLeft--;
            srcPix++;
            dstPix++;
            if (pixelsLeft > 0)
                goto copyPixel;
            srcPix = (u16 *)((u8 *)srcPix + srcRowSkip);
            dstPix = (u16 *)((u8 *)dstPix + dstRowSkip);
            rowsLeft = height - 1;
            height = rowsLeft;
        } while (rowsLeft > 0);
        dstFormat = *(s8 *)dstCanvas;
        srcFormat = *(s8 *)srcCanvas;
        if (srcFormat != dstFormat) {
            if (srcFormat == CANVAS_FORMAT_RGB565 &&
                dstFormat == CANVAS_FORMAT_RGB1555) {
                src565 = (u16 *)gxCanvasGetPixelAddr((void *)srcCanvas, srcX, srcY);
                dst1555 = (u16 *)gxCanvasGetPixelAddr((void *)dstCanvas, clipX, clipY);
                width = savedWidth;
                height = savedHeight;
                srcRowSkip = (((GxCanvas *)srcCanvas)->rowBytes - savedWidth * 2) / 2 * 2;
                dstRowSkip = (((GxCanvas *)dstCanvas)->rowBytes - savedWidth * 2) / 2 * 2;
                do {
                    pixelsLeft2 = width;
conv565To555:
                    pixel565 = *src565;
                    pixelsLeft2--;
                    src565++;
                    /* ((p >> 1) & 0x7FE0) | (p & 0x1F): red and blue move down
                     * one bit slot, green loses its 6th (low) bit. */
                    converted = (u16)__rlwinm(pixel565, 31, 17, 26);
                    converted = (u16)__rlwimi(converted, pixel565, 0, 27, 31);
                    *dst1555 = converted;
                    dst1555++;
                    if (pixelsLeft2 > 0)
                        goto conv565To555;
                    src565 = (u16 *)((u8 *)src565 + srcRowSkip);
                    dst1555 = (u16 *)((u8 *)dst1555 + dstRowSkip);
                    rowsLeft = height - 1;
                    height = rowsLeft;
                } while (rowsLeft > 0);
                return;
            }
            if (srcFormat == CANVAS_FORMAT_RGB1555 &&
                dstFormat == CANVAS_FORMAT_RGB565) {
                src1555 = (u16 *)gxCanvasGetPixelAddr((void *)srcCanvas, srcX, srcY);
                dst565 = (u16 *)gxCanvasGetPixelAddr((void *)dstCanvas, clipX, clipY);
                width = savedWidth;
                height = savedHeight;
                srcRowSkip = (((GxCanvas *)srcCanvas)->rowBytes - savedWidth * 2) / 2 * 2;
                dstRowSkip = (((GxCanvas *)dstCanvas)->rowBytes - savedWidth * 2) / 2 * 2;
                do {
                    pixelsLeft3 = width;
conv555To565:
                    pixel1555 = *src1555;
                    pixelsLeft3--;
                    src1555++;
                    /* ((p << 1) & 0xFFC0) | (((p << 1) & 0x400) >> 5) |
                     * (p & 0x1F): green gains a low bit holding its own top
                     * bit, red and blue shift up one. */
                    greenLowBit = __rlwinm(pixel1555, 1, 21, 21);
                    packed565 = __rlwinm(pixel1555, 1, 16, 25);
                    packed565 = __rlwimi(packed565, pixel1555, 0, 27, 31);
                    greenLowBit = greenLowBit >> 5;
                    packed565 = greenLowBit | packed565;
                    *dst565 = (u16)packed565;
                    dst565++;
                    if (pixelsLeft3 > 0)
                        goto conv555To565;
                    src1555 = (u16 *)((u8 *)src1555 + srcRowSkip);
                    dst565 = (u16 *)((u8 *)dst565 + dstRowSkip);
                    rowsLeft = height - 1;
                    height = rowsLeft;
                } while (rowsLeft > 0);
                return;
            }
            if (srcFormat == CANVAS_FORMAT_RGBA4444 &&
                dstFormat == CANVAS_FORMAT_RGB565) {
                src4444 = (u16 *)gxCanvasGetPixelAddr((void *)srcCanvas, srcX, srcY);
                dst565From4444 = (u16 *)gxCanvasGetPixelAddr((void *)dstCanvas, clipX, clipY);
                width = savedWidth;
                height = savedHeight;
                srcRowSkip = (((GxCanvas *)srcCanvas)->rowBytes - savedWidth * 2) / 2 * 2;
                dstRowSkip = (((GxCanvas *)dstCanvas)->rowBytes - savedWidth * 2) / 2 * 2;
                do {
                    pixelsLeft = width;
conv4444To565:
                    pixel4444 = *src4444;
                    pixelsLeft--;
                    src4444++;
                    /* (p << 1) & 0xF | (p << 3) & 0x780 | (p << 4) & 0xF000:
                     * every 4-bit component moves up into its 565 field, the
                     * alpha nibble is dropped. */
                    converted = (u16)__rlwinm(pixel4444, 1, 27, 30);
                    converted = (u16)__rlwimi(converted, pixel4444, 3, 21, 24);
                    converted = (u16)__rlwimi(converted, pixel4444, 4, 16, 19);
                    *dst565From4444 = converted;
                    dst565From4444++;
                    if (pixelsLeft > 0)
                        goto conv4444To565;
                    src4444 = (u16 *)((u8 *)src4444 + srcRowSkip);
                    dst565From4444 = (u16 *)((u8 *)dst565From4444 + dstRowSkip);
                    rowsLeft = height - 1;
                    height = rowsLeft;
                } while (rowsLeft > 0);
                return;
            }
            Abend_Panic(lbl_8034B0B8, (s32)srcFormat, (s32)dstFormat);
        }
    }
}
#pragma pop

// Keep the target scheduling and helper calls: these reproduce the original copy loop.
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_802C3C68(s32 srcCanvas, s32 srcX, s32 srcY, s32 srcRight, s32 srcBottom,
                 s32 dstCanvas, s32 dstX, s32 dstY) {
    /* Blit a 32bpp rectangle from (srcX,srcY)-(srcRight,srcBottom) on srcCanvas
     * to (dstX,dstY) on dstCanvas, clipped to dstCanvas bounds. */
    s32 blitWidth, blitHeight, clipDstY, clipDstX, clipSrcY, clipSrcX;
    s32 *srcPixel, *dstPixel;
    s32 pixelsLeft, rowBytes, srcSkip, dstSkip;
    clipSrcX = srcX;
    clipSrcY = srcY;
    clipDstX = dstX;
    clipDstY = dstY;
    blitWidth = srcRight - srcX;
    blitHeight = srcBottom - srcY;
    if (gxCanvasClipBlitRect((void *)dstCanvas, &clipDstX, &clipDstY, &clipSrcX, &clipSrcY, &blitWidth, &blitHeight) != 0) {
        srcPixel = (s32 *)gxCanvasGetPixelAddr32((void *)srcCanvas, clipSrcX, clipSrcY);
        dstPixel = (s32 *)gxCanvasGetPixelAddr32((void *)dstCanvas, clipDstX, clipDstY);
        rowBytes = blitWidth * 4;
        srcSkip = (*(s32 *)((char *)srcCanvas + 0x10) - rowBytes) / 4;
        dstSkip = (*(s32 *)((char *)dstCanvas + 0x10) - rowBytes) / 4;
        do {
            pixelsLeft = blitWidth;
loop_3:
            {
                s32 pixel = *srcPixel;
                pixelsLeft--;
                srcPixel++;
                *dstPixel = pixel;
                dstPixel++;
            }
            if (pixelsLeft > 0)
                goto loop_3;
            srcPixel += srcSkip;
            dstPixel += dstSkip;
            blitHeight--;
        } while (blitHeight > 0);
    }
}

#define CANVAS_COPY_FORMAT_MSG lbl_8034B0E4 /* "Can't copy from %d to %d" */

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma processor 750
/* copy_16_to_32: blit the rectangle (srcLeft,srcTop)-(srcRight,srcBottom) of a
 * 2-byte-pixel canvas onto the 4-byte-pixel canvas dstCanvas at
 * (dstLeft,dstTop), converting every pixel to a 0x00RRGGBB word.  The
 * rectangle is clipped against the destination's clip rectangle first, which
 * moves the source origin along with it; each row then steps over the pixels
 * a row does not hold on both sides.  Only RGB565 and RGB1555 sources
 * convert; any other source format only traces "Can't copy from %d to %d". */
void fn_802C3D74(s32 srcCanvas, s32 srcLeft, s32 srcTop, s32 srcRight,
                  s32 srcBottom, s32 dstCanvas, s32 dstLeft, s32 dstTop) {
    /* Destination corner after clipping, the matching source corner, and the
       size that is left of the requested rectangle. */
    s32 width, height, clipY, clipX, srcY, srcX;
    u16 *src;
    s32 *dst;
    s32 pixelsLeft, srcSkip, dstSkip, srcAdd, dstAdd;
    srcX = srcLeft;
    srcY = srcTop;
    clipX = dstLeft;
    clipY = dstTop;
    width = srcRight - srcLeft;
    height = srcBottom - srcTop;
    if (gxCanvasClipBlitRect((void *)dstCanvas, &clipX, &clipY, &srcX, &srcY, &width, &height) != 0) {
        src = (u16 *)gxCanvasGetPixelAddr((void *)srcCanvas, srcX, srcY);
        dst = (s32 *)gxCanvasGetPixelAddr32((void *)dstCanvas, clipX, clipY);
        /* Pixels to step over the ones a row does not hold, per canvas. */
        srcSkip = (((GxCanvas *)srcCanvas)->rowBytes - width * 2) / 2;
        dstSkip = (((GxCanvas *)dstCanvas)->rowBytes - width * 4) / 4;
        if (*(s8 *)srcCanvas == CANVAS_FORMAT_RGB565) {
            /* Row pitch in bytes, for the two loops below. */
            srcAdd = srcSkip * 2;
            dstAdd = dstSkip * 4;
            do {
                pixelsLeft = width;
                do {
                    u16 pixel = *src;
                    s32 converted;
                    src++;
                    converted = Convert565ToRGBA(pixel);
                    pixelsLeft--;
                    *dst = converted;
                    dst++;
                } while (pixelsLeft > 0);
                src = (u16 *)((u8 *)src + srcAdd);
                dst = (s32 *)((u8 *)dst + dstAdd);
                height--;
            } while (height > 0);
        } else if (*(s8 *)srcCanvas == CANVAS_FORMAT_RGB1555) {
            srcAdd = srcSkip * 2;
            dstAdd = dstSkip * 4;
            do {
                pixelsLeft = width;
                do {
                    u16 pixel = *src;
                    s32 converted;
                    src++;
                    converted = Convert555ToRGBA(pixel);
                    pixelsLeft--;
                    *dst = converted;
                    dst++;
                } while (pixelsLeft > 0);
                src = (u16 *)((u8 *)src + srcAdd);
                dst = (s32 *)((u8 *)dst + dstAdd);
                height--;
            } while (height > 0);
        } else {
            Abend_Panic(CANVAS_COPY_FORMAT_MSG, (s32)*(s8 *)srcCanvas, *(s8 *)dstCanvas);
        }
    }
}
#pragma pop

extern const char lbl_8034B100[];
#pragma push
#pragma scheduling invalid_target
void fn_802C3F00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    u8 *sourceObj, *targetObj;
    u32 *src;
    s16 *dst;
    s32 format, skipSrc, skipDst, i;
    u8 formatByte;
    u32 pixel;

    sourceObj = (u8 *)arg0;
    targetObj = (u8 *)arg5;
    sp8 = arg1;
    spC = arg2;
    sp10 = arg6;
    sp14 = arg7;
    sp1C = arg3 - arg1;
    sp18 = arg4 - arg2;
    if (gxCanvasClipBlitRect(targetObj, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        src = (u32 *)gxCanvasGetPixelAddr32(sourceObj, sp8, spC);
        dst = (s16 *)gxCanvasGetPixelAddr(targetObj, sp10, sp14);
        formatByte = *(u8 *)targetObj;
        format = (s8)formatByte;
        skipSrc = (*(s32 *)(sourceObj + 0x10) - sp1C * 4) / 4;
        skipDst = (*(s32 *)(targetObj + 0x10) - sp1C * 2) / 2;
        if (format == 3) {
            do {
                i = sp1C;
                do {
                    pixel = *src += 1;
                    i--;
                    {
                        s32 part = ((pixel >> 6) & 0x3E0) |
                                   ((((s32)(u8)(pixel >> 8) >> 3) << 10) & 0x7C00);
                        *dst = (s16)(((s32)(u8)pixel >> 3) | part);
                    }
                    dst++;
                } while (i > 0);
                src += skipSrc;
                dst += skipDst;
                sp18--;
            } while (sp18 > 0);
        } else if (format == 4) {
            do {
                i = sp1C;
                do {
                    pixel = *src++;
                    i--;
                    *dst++ = (s16)((((pixel >> 8) & 0xF800 & ~0x7E0) |
                        ((pixel >> 5) & 0x7E0) & ~0x1F) |
                        ((pixel >> 3) & 0x1F));
                } while (i > 0);
                src += skipSrc;
                dst += skipDst;
                sp18 -= 1;
            } while (sp18 > 0);
        } else {
            Abend_Panic((char *)lbl_8034B100, *(s8 *)sourceObj);
        }
    }
}
#pragma scheduling on
#pragma pop
/* Blit the whole source canvas onto the global canvas at (dstX,dstY), unless the
   global canvas's no-draw flag (bit 2 at +1) suppresses drawing. */
void fn_802C40B8(GxCanvas *canvas, s32 dstX, s32 dstY) {
    if ((((GxCanvas *)lbl_8055FC00)->flags & 4) != 0) {
        fn_802DB2C8();
        return;
    }
    fn_802C3754((s32)canvas, 0, 0, canvas->width, canvas->height,
        lbl_8055FC00, dstX, dstY);
}

void gxCanvasAlphaBlitWhole(GxCanvas *canvas, s32 dstX, s32 dstY) {
    /* Alpha-blit the whole source canvas (origin 0,0, full width/height) onto the current canvas at (dstX,dstY). */
    fn_802C3850((s32)canvas, 0, 0, canvas->width, canvas->height,
        sCurrentCanvas, dstX, dstY);
}

#pragma scheduling invalid_target
void fn_802C4108(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    s32 skipSrc, skipDst, i, a, ia;
    u16 *src, *dst;
    u32 d, s, b, g, r;
    s32 st0, st1;
    sp8 = arg1;
    spC = arg2;
    sp10 = arg6;
    sp14 = arg7;
    sp1C = arg3 - arg1;
    sp18 = arg4 - arg2;
    if (gxCanvasClipBlitRect((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        u8 fmt;
        src = (u16 *)gxCanvasGetPixelAddr((void *)arg0, sp8, spC);
        dst = (u16 *)gxCanvasGetPixelAddr((void *)arg5, sp10, sp14);
        st0 = *(s32 *)((u8 *)arg0 + 0x10);
        st1 = *(s32 *)((u8 *)arg5 + 0x10);
        skipSrc = (st0 - sp1C * 2) / 2;
        skipDst = (st1 - sp1C * 2) / 2;
        fmt = *(u8 *)arg5;
        if ((s8)fmt == 3) {
            do {
                i = sp1C;
                do {
                    s = *src;
                    d = *dst;
                    src++;
                    i--;
                    a = (s32)((s >> 8) & 0xF0) >> 4;
                    ia = 15 - a;
                    b = (ia * ((d << 3) & 0xF8) + a * ((s << 4) & 0xF0)) / 15;
                    r = (ia * ((d >> 2) & 0xF8) + a * (s & 0xF0)) / 15;
                    g = (ia * ((d >> 7) & 0xF8) + a * ((s >> 4) & 0xF0)) / 15;
                    *dst = ((s32)(b & 0xFF) >> 3) | ((((g >> 3) << 5) & 0x3E0) | (((s32)(r & 0xFF) >> 3) << 10));
                    dst++;
                } while (i > 0);
                src += skipSrc;
                dst += skipDst;
                sp18--;
            } while (sp18 > 0);
            return;
        }
        if ((s8)fmt == 4) {
            do {
                i = sp1C;
                do {
                    s = *src;
                    d = *dst;
                    src++;
                    i--;
                    a = (s32)((s >> 8) & 0xF0) >> 4;
                    ia = 15 - a;
                    b = (ia * ((d << 3) & 0xF8) + a * ((s << 4) & 0xF0)) / 15;
                    r = (ia * ((d >> 3) & 0xFC) + a * (s & 0xF0)) / 15;
                    g = (ia * ((d >> 8) & 0xF8) + a * ((s >> 4) & 0xF0)) / 15;
                    *dst = ((s32)(b & 0xFF) >> 3) | (((g << 3) & 0x7E0) | ((r << 8) & 0xF800));
                    dst++;
                } while (i > 0);
                src += skipSrc;
                dst += skipDst;
                sp18--;
            } while (sp18 > 0);
            return;
        }
        Abend_Panic(lbl_8034B124);
    }
}

#pragma scheduling invalid_target
void fn_802C4388(s32 src, s32 x, s32 y, s32 x2, s32 y2, s32 dst, s32 dx, s32 dy) {
    s32 w, h, ty, tx, sy, sx;
    s32 srcskip, dstskip, n;
    u32 *sp;
    u16 *dp;
    sx = x; sy = y; tx = dx; ty = dy; w = x2 - x; h = y2 - y;
    if (!gxCanvasClipBlitRect((void *)dst, &tx, &ty, &sx, &sy, &w, &h)) return;
    sp = (u32 *)gxCanvasGetPixelAddr32((void *)src, sx, sy);
    dp = (u16 *)gxCanvasGetPixelAddr((void *)dst, tx, ty);
    srcskip = (*(s32 *)((u8 *)src + 0x10) - w * 4) / 4;
    dstskip = (*(s32 *)((u8 *)dst + 0x10) - w * 2) / 2;
    if (*(s8 *)dst == 3) {
        do {
            n = w;
            do {
                u32 pixel = *sp++;
                u16 old = *dp;
                u32 a = pixel >> 24, inv = 255 - a;
                s32 b = (u8)((inv * ((old << 3) & 0xf8) + a * (u8)pixel) / 255);
                s32 g = (u8)((inv * ((old >> 2) & 0xf8) + a * (u8)(pixel >> 8)) / 255);
                s32 r = (u8)((inv * ((old >> 7) & 0xf8) + a * (u8)(pixel >> 16)) / 255);
                *dp++ = ((r >> 3) << 10) | ((g >> 3) << 5) | (b >> 3);
            } while (--n > 0);
            sp += srcskip;
            dp += dstskip;
        } while (--h > 0);
    } else if (*(s8 *)dst == 4) {
        do {
            n = w;
            do {
                u16 old = *dp;
                u32 pixel = *sp++;
                u32 a = pixel >> 24, inv = 255 - a;
                u32 b = (inv * (u8)(((old << 3) & 0xf8) + 1) + a * (u8)pixel) * 0x10101;
                u32 g = (inv * (u8)(((old >> 3) & 0xfc) + 1) + a * (u8)(pixel >> 8)) * 0x10101;
                u32 r = (inv * (u8)(((old >> 8) & 0xf8) + 1) + a * (u8)(pixel >> 16)) * 0x10101;
                *dp++ = ((r >> 16) & 0xf800) | ((g >> 21) & 0x7e0) | (b >> 27);
            } while (--n > 0);
            sp += srcskip;
            dp += dstskip;
        } while (--h > 0);
    } else Abend_Panic(lbl_8034B124);
}
#pragma scheduling on
void fn_802C4610(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    s32 i, widthBytes, skipSrc, skipDst, var_r6;
    u32 *var_r31, *var_r3;
    u32 temp_r8, temp_r30, var_r0, var_r7;
    s32 temp_r29, temp_r10, temp_r11, temp_r12;
    u8 red, green, blue;

    sp8 = arg1;
    spC = arg2;
    sp10 = arg6;
    sp14 = arg7;
    sp1C = arg3 - arg1;
    sp18 = arg4 - arg2;
    if (gxCanvasClipBlitRect((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        var_r31 = (u32 *)gxCanvasGetPixelAddr32((void *)arg0, sp8, spC);
        var_r3 = (u32 *)gxCanvasGetPixelAddr32((void *)arg5, sp10, sp14);
        widthBytes = sp1C * 4;
        skipSrc = (*(s32 *)((u8 *)arg0 + 0x10) - widthBytes) / 4;
        skipDst = (*(s32 *)((u8 *)arg5 + 0x10) - widthBytes) / 4;
        do {
            var_r6 = sp1C;
loop_3:
            temp_r8 = *var_r31;
            var_r31++;
            var_r0 = *var_r3;
            temp_r30 = temp_r8 >> 24;
            if (temp_r30 != 0) {
                if (temp_r30 == 0xFF) {
                    var_r0 = (var_r0 & 0xFF000000) | (temp_r8 & 0x00FFFFFF);
                } else {
                    temp_r29 = 0xFF - temp_r30;
                    temp_r10 = (u8)(((temp_r29 * (u8)(var_r0 >> 16)) + (temp_r30 * (u8)(temp_r8 >> 16))) >> 8);
                    red = (u8)temp_r10;
                    temp_r10 = red + ((s32)red >> 7);
                    temp_r11 = (u8)(((temp_r29 * (u8)(var_r0 >> 8)) + (temp_r30 * (u8)(temp_r8 >> 8))) >> 8);
                    green = (u8)temp_r11;
                    temp_r11 = green + ((s32)green >> 7);
                    temp_r12 = (u8)(((temp_r29 * (u8)var_r0) + (temp_r30 * (u8)temp_r8)) >> 8);
                    blue = (u8)temp_r12;
                    temp_r12 = blue + ((s32)blue >> 7);
                    var_r7 = ((u32)temp_r10 << 16);
                    var_r7 |= (u32)temp_r11 << 8;
                    var_r0 = (var_r0 & 0xFF000000) | (temp_r12 & 0xFF);
                    var_r0 |= var_r7;
                }
            }
            var_r6--;
            *var_r3 = var_r0;
            var_r3++;
            if (var_r6 > 0) goto loop_3;
            var_r31 += skipSrc;
            var_r3 += skipDst;
            i = sp18 - 1;
            sp18 = i;
        } while (i > 0);
    }
}

extern int fn_800241CC(int); /* abs(): (v >> 31) ^ v - (v >> 31) */
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Draw a line from (x0, y0) to (x1, y1) on the current canvas in `color`,
   handing every point to gxPoint, the pixel plotter above.  An
   axis-aligned line just steps one pixel at a time along the axis it spans;
   any other line is walked by DDA: the major axis (the one spanning more,
   see fn_800241CC = abs) moves a whole pixel at a time in `dir`, while the
   minor coordinate accumulates the slope as a float and is truncated at each
   point. */
void fn_802C47B8(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    s32 dx, dy, stepPos, stepInc, stepEnd, dir, x, y;
    dx = x1 - x0;
    x = x0;
    y = y0;
    dy = y1 - y0;
    if (dx == 0) {
        if (dy != 0) {
            dir = -1;
            if (y0 < y1) dir = 1;
            stepPos = y0 * dir;
            stepInc = dir * dir;
            stepEnd = dir * y1;
            for (; stepPos < stepEnd; stepPos += stepInc, y += dir)
                gxPoint(x, y, color);
        }
        return;
    }
    if (dy == 0) {
        dir = -1;
        if (x0 < x1) dir = 1;
        stepPos = x0 * dir;
        stepInc = dir * dir;
        stepEnd = dir * x1;
        for (; stepPos < stepEnd; stepPos += stepInc, x += dir)
            gxPoint(x, y, color);
        return;
    }
    {
        s32 absDy = fn_800241CC(dy);
        if (fn_800241CC(dx) < absDy) {
            f32 slope;
            f32 fx;
            dir = -1;
            if (y < y1) dir = 1;
            slope = ((f32)dir * (f32)dx) / (f32)dy;
            fx = (f32)x;
            for (; y != y1; y += dir) {
                gxPoint((s32)fx, y, color);
                fx += slope;
            }
            return;
        }
    }
    {
        f32 slope;
        f32 fy;
        dir = -1;
        if (x < x1) dir = 1;
        slope = ((f32)dir * (f32)dy) / (f32)dx;
        fy = (f32)y;
        for (; x != x1; x += dir, fy += slope) {
            gxPoint(x, (s32)fy, color);
        }
    }
}
#pragma pop
/* The resource manager's loader (fn_8012C370), as the loaders in this file
   call it: hand back the resource named `name` whose fourcc tag is `tag`,
   report the file's version through `version`, and, through `swapFlag`,
   whether the block was only just read in and so still holds the
   little-endian data the caller has to swap.  `newFlag` may take a byte the
   loader sets on such a first load; pass 0 to ignore it. */
typedef void *(*LoadResource)(const char *name, u32 tag, u32 *version,
                              s32 *size, void *newFlag, u8 *swapFlag);

extern const char lbl_8034B144[]; /* "Wrong stamp version in \"%s\": %x (expecting %x)" */

/* --- STMP: a stamp, the game's run-length encoded sprite image ---------- */
/* loadStamp loads one by name, fn_802C4C80 releases it and fn_802C4C90
   draws one of its frames onto a canvas: it walks the frame's rows through
   the row table, decodes each row's 8-bit colour indices with one of the
   two palettes and writes them out.  The file is stored little-endian and
   its row table holds offsets into the block, so the first time a stamp is
   loaded loadStamp swaps every 32-bit field the game reads and turns
   those offsets into pointers. */
  /* A stamp's two 256-entry palettes, in the order the drawer picks them:
     [0] on a mode 3 canvas, [1] on any other.  A caller may hand the drawer a
     pair of its own in place of the stamp's. */
  typedef u16 StampPalette[2][256];

  typedef struct {
      s32 width;                    /* 0x000 pixels per row */
    s32 height;                   /* 0x004 rows per frame */
    s32 x_off;                    /* 0x008 offset a frame is drawn at */
    s32 y_off;                    /* 0x00C */
    s32 frames;                   /* 0x010 frames in the stamp */
          StampPalette palette;         /* 0x014 colours: [0] on a mode 3 canvas,
                                       [1] on any other (fn_802C4C90) */
    u32 unknown_414[256];         /* 0x414 swapped with the header; no
                                     matched code reads it */
    u32 *rows;                    /* 0x814 -> the row table below */
    u8 *pixels;                   /* 0x818 -> rows + height*frames*4 */
} Stamp;                          /* 0x81C: u32 rows[frames*height], then
                                     each row's run-length encoded pixels */

#define STAMP_TAG     0x53544D50 /* 'STMP' */
#define STAMP_VERSION 3

/* Swap the four bytes of the little-endian 32-bit field at b + off into the
   console's byte order, in place, through the caller's u8 temporary t. */
#define STAMP_SWAP_WORD(b, off)      \
    t = (b)[off];                    \
    (b)[off] = (b)[(off) + 3];       \
    (b)[(off) + 3] = t;              \
    t = (b)[(off) + 1];              \
    (b)[(off) + 1] = (b)[(off) + 2]; \
    (b)[(off) + 2] = t;

#pragma push
#pragma opt_unroll_loops off
/* Load the stamp `name` through the resource manager, and stop the game if
   the file is not version 3.  A block that was only just read in is stored
   little-endian and its row table holds offsets into the block: swap its
   words and turn those offsets into pointers before handing it back. */
/* Load a STMP stamp resource by name, stop on a wrong version, and byte-swap a freshly read block in place before returning it. */ /* Load a STMP stamp resource by name, stop on a wrong version, and byte-swap a freshly read block in place before returning it. */ void *loadStamp(const char *name) {
    s32 outSize;
    u32 version;
    u8 needsSwap;
    u8 *stampData;
    Stamp *stamp;
    u8 *p;
    u32 *rowTable;
    s32 row;
    u8 t;

    needsSwap = 0;
    outSize = 0;
    stampData = (u8 *)((LoadResource)fn_8012C370)(name, STAMP_TAG, &version, &outSize, 0, &needsSwap);
    if (stampData == 0)
        goto ret0;
    stamp = (Stamp *)stampData;
    if (version != STAMP_VERSION)
        Abend_Panic(lbl_8034B144, name, version, STAMP_VERSION);
    if (needsSwap != 0) {
        /* the header's five words and the two pointers, byte-swapped in place */
        STAMP_SWAP_WORD(stampData, 0);
        STAMP_SWAP_WORD(stampData, 4);
        STAMP_SWAP_WORD(stampData, 8);
        STAMP_SWAP_WORD(stampData, 12);
        STAMP_SWAP_WORD(stampData, 16);
        STAMP_SWAP_WORD(stampData, 0x814);
        STAMP_SWAP_WORD(stampData, 0x818);
        /* the row table follows the header, the rows' pixels follow it */
        rowTable = (u32 *)(stamp + 1);
        stamp->rows = rowTable;
        stamp->pixels = (u8 *)rowTable + stamp->height * stamp->frames * 4;
        for (row = 0; row < stamp->height * stamp->frames; row++) {
            u8 a, b;
            p = (u8 *)stamp->rows + row * 4;
            a = p[0]; p[0] = p[3]; p[3] = a;
            b = p[1]; p[1] = p[2]; p[2] = b;
            *(u32 *)((u8 *)stamp->rows + row * 4) += (u32)stamp->pixels;
        }
        p = (u8 *)stamp->unknown_414;
        for (row = 0; row < 0x100; row++) {
            t = p[0]; p[0] = p[3]; p[3] = t;
            t = p[1]; p[1] = p[2]; p[2] = t;
            p += 4;
        }
    }
    return stampData;
ret0:
    return 0;
}
#pragma pop
/* Release a loaded STMP stamp back through the resource manager; NULL is a no-op. The stamp stays in r3 and flows into the tail-called release helper, which is why no argument is written at the call site. */ void fn_802C4C80(Stamp *stamp) {
    // Release a loaded STMP stamp back through the resource manager; NULL is a no-op.
    if (stamp == NULL) {
        return;
    }
    fn_8012C4D8();
}

#pragma push
#pragma use_lmw_stmw off
/* Draw one frame of a STMP stamp onto the current canvas, offset by the stamp's
 * (x_off, y_off) from (x, y).  Each row is run-length encoded 8-bit palette
 * indices: a count byte with bit 7 clear is that many transparent pixels to
 * skip, bit 7 set starts a literal run of the low seven bits' length whose
 * bytes index the palette (the stamp's, or the caller's override pair).
 * Clipped rows and columns are stepped over; a NO_DRAW canvas, a null stamp or
 * an out-of-range frame leaves the canvas untouched. */
void fn_802C4C90(Stamp *stamp, s32 x, s32 y, s32 frame, StampPalette *override) {
    GxCanvas *canvas = (GxCanvas *)sCurrentCanvas;
    if (!(canvas->flags & CANVAS_FLAG_NO_DRAW) && stamp != 0 && frame < stamp->frames) {
        s32 endRow, endCol, left, top, firstCol;
        u16 *palette;
        s32 row;
        u8 *src;
        s32 width, delta, height;
        u16 *dst;
        top = y - stamp->y_off;
        delta = canvas->minY - top;
        endRow = canvas->maxY - top;
        height = stamp->height;
        left = x - stamp->x_off;
        row = delta & ~(delta >> 31);
        if (height < endRow) endRow = height;
        width = stamp->width;
        delta = canvas->minX - left;
        firstCol = delta & ~(delta >> 31);
        endCol = canvas->maxX - left;
        if (width < endCol) endCol = width;
        if (override != 0) {
            if ((s8)canvas->format == CANVAS_FORMAT_RGB1555) palette = (*override)[0];
            else palette = (*override)[1];
        } else if ((s8)canvas->format == CANVAS_FORMAT_RGB1555) {
            palette = stamp->palette[0];
        } else {
            palette = stamp->palette[1];
        }
        for (; row < endRow; row++) {
            s32 skip, run, literal, pos;
            src = (u8 *)stamp->rows[row + stamp->height * frame];
            dst = (u16 *)gxCanvasGetPixelAddr((void *)sCurrentCanvas, left, row + top);
            for (pos = 0; pos < endCol;) {
                run = *src++;
                if (run & 0x80) {
                    run &= ~0x80;
                    literal = 1;
                } else {
                    literal = 0;
                }
                if (endCol - pos < run) run = endCol - pos;
                if (literal != 0 && pos < firstCol) {
                    skip = firstCol - pos;
                    if (run < skip) skip = run;
                    run -= skip;
                    src += skip;
                    dst += skip;
                    pos += skip;
                }
                if (literal != 0) {
                    u8 remaining = run;
                    while (remaining != 0) {
                        *dst = palette[*src];
                        pos++;
                        src++;
                        dst++;
                        remaining--;
                    }
                } else {
                    pos += run;
                    dst += run;
                }
            }
        }
    }
}
#pragma pop
s32 stampGetWidth(Stamp *stamp) {
    /* Return a stamp's width (pixels per row), or 0 for a null stamp. */
    if (stamp != NULL) {
        return stamp->width;
    }
    return 0;
}

/* Return a stamp's height (rows per frame), or 0 for a null stamp. */
/* Null-safe getter for a stamp's height (rows per frame); returns 0 when no stamp is supplied. */ s32 stampGetHeight(Stamp *stamp) {
    if (stamp != NULL) {
        return stamp->height;
    }
    return 0;
}

s32 stampGetFrameCount(Stamp *stamp) {
    /* Return a stamp's frame count, used as the modulo when picking a frame to draw; 0 for a null stamp. */
    if (stamp != NULL) {
        return stamp->frames;
    }
    return 0;
}

void stampGetOffsets(Stamp *stamp, s32 *outX, s32 *outY) {
    /* Copy a stamp's x/y draw offsets into the outputs, or zero both for a null stamp. */
    if (stamp == 0) {
        *outY = 0;
        *outX = 0;
    } else {
        *outX = stamp->x_off;
        *outY = stamp->y_off;
    }
}

#pragma push
#pragma inline_depth(0)
/* Draw a string with the built-in fixed-pitch canvas font at (x,y) in the given
 * colour, one 8-pixel cell per character; anything outside printable ASCII is
 * drawn as '#'.  Callers draw it twice, once offset by a pixel for the shadow. */
void fn_802C4F58(s32 x, s32 y, const char *text, s32 color) {
    s32 penColor = color;
    const char *textPtr = text;
    s32 penY = y;
    s32 penX = x;
    s32 ch;
    while ((ch = (s8)*textPtr++) != 0) {
        if ((s8)ch < ' ' || (u8)ch > 0x7F)
            DrawCanvasChar(penX, penY, CANVAS_CHAR_UNKNOWN, penColor);
        else
            DrawCanvasChar(penX, penY, ch, penColor);
        penX += CANVAS_CHAR_WIDTH;
    }
}
#pragma pop
extern unsigned int strlen(const char *);
/* Width in pixels the string would occupy in the fixed-width canvas font. */
unsigned int gxCanvasStringWidth(const char *text) { return strlen(text) * CANVAS_CHAR_WIDTH; }

/* The canvas font's character height/width. */
int fn_802C501C(void) {
    /* Return the canvas font's fixed character width in pixels. */
    return CANVAS_CHAR_WIDTH;
}

/* Draw a single canvas-font glyph at (x, y) in the given colour; a no-op in this release. */
void fn_802C5024(s32 x, s32 y, s32 glyph, s32 color) {}
extern const char lbl_8034B060[];
extern void fn_802C3320();
extern void fn_802C33A8();
extern void Abend_Panic(const char *, ...);
extern void fn_802C3850();
extern const char lbl_8034B078[];
extern void gxCanvasCopy16to16(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3C68(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3D74(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3F00(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802DB2C8(void);
extern void gxCanvasFillRect16(s32, s32, s32, s32, u32);
extern void gxCanvasFillRectRGBA4444(s32, s32, s32, s32, u32);
extern void gxCanvasFillRectRGBA(s32, s32, s32, s32, u32);
