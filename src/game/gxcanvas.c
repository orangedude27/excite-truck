// gxcanvas — gx canvas/stamp images ("gxCanvasGet(%s): wrong ver").
// Recovered TU window 0x802C2CAC..0x802C5028+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802C5028 (+ .ctors slot 0x802ED59C) remains in
// auto/text_802C5028_.c pending a promotion pass.
#include <types.h>
extern const char lbl_8034B078[];
extern const char lbl_8034B0E4[];
extern void fn_802C3918(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3C68(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3D74(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3F00(s32,s32,s32,s32,s32,s32,s32,s32);

extern u8 lbl_8055CFF8;
extern u8 lbl_8055D000;
extern void *fn_801284E8(void *, s32);
void fn_802C2CE8(void *, s32, s32, s8);
void fn_802C3014(void *);

void fn_802C5024(s32, s32, s32, s32);

extern void fn_8012C4D8(void);

extern s32 lbl_8055FC00;
extern void fn_802C3754(s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_802DB2C8(void);
extern void fn_802C3478(s32, s32, s32, s32, u32);
extern void fn_802C356C(s32, s32, s32, s32, u32);
extern void fn_802C365C(s32, s32, s32, s32, u32);
#pragma scheduling invalid_target
#pragma push
#pragma peephole off
s32 fn_802C2CAC(s32 arg0) { unsigned int a = __rlwinm(arg0, 9, 8, 12); unsigned int b; a |= 0xFF000000; b = __rlwinm(arg0, 3, 24, 28); a = __rlwimi(a, arg0, 6, 16, 20); return (s32)(b | a); }
#pragma pop
#pragma push
#pragma peephole off
s32 fn_802C2CC4(s32 arg0) {
    unsigned int low = (arg0 << 3) & 0xF8;
    return (s32)(low | __rlwimi(__rlwinm(arg0, 8, 8, 12) | 0xFF000000, arg0, 5, 16, 21));
}
#pragma pop
void fn_802C2CDC(void *arg0, s32 arg1, s32 arg2) {
    fn_802C2CE8(arg0, arg1, arg2, (s8)lbl_8055CFF8);
}

void fn_802C2CE8(void *arg0, s32 arg1, s32 arg2, s8 arg3) {
    int prod = arg1 * arg2;
    int c82 = 0x82;
    *(s8 *)arg0 = arg3;
    ((u8 *)arg0)[1] = c82;
    *(void **)((u8 *)arg0 + 4) = fn_801284E8(&lbl_8055D000, prod * ((arg3 == 5) ? 4 : 2));
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC) = arg2;
    *(s32 *)((u8 *)arg0 + 0x10) = arg1 * ((arg3 == 5) ? 4 : 2);
    fn_802C3014(arg0);
}

void fn_802C2D94(void *arg0) {
    fn_80128658(*(s32 *)((u8 *)arg0 + 4));
    memset(arg0, 0, 0x24);
}

extern void *fn_8012C370(s32,u32 *,s32 *,s32,u8 *);
extern void fn_802E317C(const char *,...);
extern const char lbl_8034B020[],lbl_8034B048[];
#pragma scheduling invalid_target
/* Loads a CANV image resource, byte-swaps its header fields when flagged, converts pixels to RGBA order, and reports load/format errors. */
void *fn_802C2DD4(s32 resourceId) {
    u32 format;
    s32 size;
    u8 needsSwap;
    u32 *pixels;
    s32 row;
    s32 col;
    u32 pixel;
    u8 temp;
    void *resource;

    resource = ((void *(*)(s32, s32, u32 *, s32 *, s32, u8 *))fn_8012C370)(resourceId, 0x43414E56, &format, &size, 0, &needsSwap);
    if (resource != 0) {
        if (format == 1) {
            if (needsSwap != 0) {
                volatile u8 *bytes = (volatile u8 *)resource;
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
            fn_802E317C(lbl_8034B020, resourceId, format, 1);
        }
    } else {
        fn_802E317C(lbl_8034B048, resourceId);
    }
    return resource;
}
#pragma scheduling on
void fn_802C2FC4(void) {
    ((void (*)(void))fn_8012C4D8)();
}

#pragma scheduling invalid_target
#pragma peephole off
void fn_802C2FC8(void *arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    s32 var_r0;
    s32 var_r10;
    var_r10 = *(s32 *)((u8 *)arg0 + 8);
    *(s32 *)((u8 *)arg0 + 0x14) = (s32)(arg1 & ((arg1 >> 31) - 1));
    *(s32 *)((u8 *)arg0 + 0x18) = (s32)(arg2 & ((arg2 >> 31) - 1));
    if (arg3 < var_r10) {
        var_r10 = arg3;
    }
    var_r0 = *(s32 *)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)arg0 + 0x1C) = var_r10;
    if (arg4 < var_r0) {
        var_r0 = arg4;
    }
    *(s32 *)((u8 *)arg0 + 0x20) = var_r0;
}
#pragma peephole on
#pragma scheduling on
void fn_802C3014(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)((u8 *)arg0 + 8);
    *(s32 *)((u8 *)arg0 + 0x20) = *(s32 *)((u8 *)arg0 + 0xC);
}

s32 fn_802C3034(s32 value) {
    s32 old;

    old = lbl_8055FC00;
    lbl_8055FC00 = value;
    return old;
}

s32 fn_802C3044(void *arg0, s32 arg1, s32 arg2) {
    return *(s32 *)((u8 *)arg0 + 0x10) * arg2 + (*(s32 *)((u8 *)arg0 + 4) + arg1 * 2);
}

s32 fn_802C3060(void *arg0, s32 arg1, s32 arg2) {
    return *(s32 *)((u8 *)arg0 + 0x10) * arg2 + (*(s32 *)((u8 *)arg0 + 4) + arg1 * 4);
}

s32 fn_802C307C(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    s32 x0 = *arg1;
    s32 x1;
    s32 x2;
    if (x0 >= *(s32 *)((u8 *)arg0 + 0x1C)) return 0;
    if (*arg2 >= *(s32 *)((u8 *)arg0 + 0x20)) return 0;
    x1 = *(s32 *)((u8 *)arg0 + 0x14);
    if (x0 < x1) *arg1 = x1;
    x1 = *(s32 *)((u8 *)arg0 + 0x18);
    if (*arg2 < x1) *arg2 = x1;
    x1 = *(s32 *)((u8 *)arg0 + 0x1C);
    if (*arg3 > x1) *arg3 = x1;
    x2 = *(s32 *)((u8 *)arg0 + 0x20);
    if (*arg4 > x2) *arg4 = x2;
    if (*arg1 >= *arg3) return 0;
    return *arg2 < *arg4;
}

s32 fn_802C3130(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 >= *(s32 *)((u8 *)arg0 + 0x14) && arg2 >= *(s32 *)((u8 *)arg0 + 0x18) && arg1 < *(s32 *)((u8 *)arg0 + 0x1C) && arg2 < *(s32 *)((u8 *)arg0 + 0x20)) return 1;
    return 0;
}

s32 fn_802C3170(void *bounds, s32 *x, s32 *y, s32 *srcX, s32 *srcY, s32 *w, s32 *h) {
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
extern void fn_802C3320();
extern void fn_802C33A8(s32, s32, u32);
extern void fn_802E317C(const char *, ...);
void fn_802C32B8(s32 arg0, s32 arg1, u32 arg2) {
    u32 state = lbl_8055FC00;
    u8 mode;
    s32 flag;
    if (((u8 *)state)[1] & 4) return;
    mode = ((u8 *)state)[0];
    flag = 0;
    if ((s8)mode != 5 && (s8)mode != 6) flag = 1;
    if (flag != 0) {
        fn_802C3320();
        return;
    }
    if ((s8)((u8 *)state)[0] == 5) {
        fn_802C33A8(arg0, arg1, arg2);
        return;
    }
    fn_802E317C(lbl_8034B060, (s32)*(volatile s8 *)lbl_8055FC00);
}

#pragma push
#pragma inline_depth(0)
void fn_802C3320(s32 arg0, s32 arg1, u32 arg2) {
    u32 value;
    if (fn_802C3130((void *)lbl_8055FC00, arg0, arg1) != 0) {
        value = arg2 >> 16;
        if ((s8)*(u8 *)lbl_8055FC00 == 3)
            value = arg2 & 0xFFFF;
        *(u16 *)fn_802C3044((void *)lbl_8055FC00, arg0, arg1) = (u16)value;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(0)
void fn_802C33A8(s32 arg0, s32 arg1, u32 arg2) {
    u32 *pixel;
    u32 value;
    if (fn_802C3130((void *)lbl_8055FC00, arg0, arg1) != 0) {
        pixel = (u32 *)fn_802C3060((void *)lbl_8055FC00, arg0, arg1);
        value = ((arg2 >> 8) & 0x00F80000) | 0xFF000000;
        value = (value & ~0x0000FC00) | ((arg2 >> 11) & 0x0000FC00);
        value = (value & ~0x000000F8) | ((arg2 >> 13) & 0x000000F8);
        *pixel = value;
    }
}

void fn_802C3424(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4) {
    s8 mode = *(s8 *)lbl_8055FC00;
    s32 flag = 0;
    if (mode != 5 && mode != 6)
        flag = 1;
    if (flag != 0) {
        if (*(volatile s8 *)lbl_8055FC00 != 1) {
            fn_802C3478(arg0, arg1, arg2, arg3, arg4);
            return;
        }
        fn_802C365C(arg0, arg1, arg2, arg3, arg4);
        return;
    }
    if (*(volatile s8 *)lbl_8055FC00 != 5)
        return;
    fn_802C356C(arg0, arg1, arg2, arg3, arg4);
}

#pragma pop

#pragma push
#pragma processor 750
#pragma inline_depth(0)
void fn_802C3478(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    u32 pixel;
    s32 width, height, skip, n;
    u8 mode;
    u16 *p;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    pixel = color >> 16;
    mode = *(u8 *)lbl_8055FC00;
    width = x1 - x0;
    height = y1 - y0;
    if (mode == 3) pixel = (u16)color;
    p = (u16 *)fn_802C3044((void *)lbl_8055FC00, x0, y0);
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
/* Fills a clipped x0,y0-x1,y1 rectangle on lbl_8055FC00 with 32-bit pixels converted from argbColor. */
void fn_802C356C(s32 x0, s32 y0, s32 x1, s32 y1, u32 argbColor) {
    u32 pixel;
    s32 width, height, rowSkip, colCount;
    u32 *pixels;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    pixel = ((argbColor >> 8) & 0xF80000) | 0xFF000000;
    pixel = (pixel & ~0xFC00) | ((argbColor >> 11) & 0xFC00);
    width = x1 - x0;
    height = y1 - y0;
    pixel = (pixel & ~0xF8) | ((argbColor >> 13) & 0xF8);
    pixels = (u32 *)fn_802C3060((void *)lbl_8055FC00, x0, y0);
    rowSkip = (*(s32 *)((u8 *)lbl_8055FC00 + 0x10) - width * 4) / 4;
    do {
        colCount = width;
        do {
            --colCount;
            *pixels++ = pixel;
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
void fn_802C365C(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    u32 pixel;
    u32 packed;
    s32 low;
    s32 width, height, n;
    u32 skip;
    u16 *p;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    low = (s32)((color * 8) & 0xF8) >> 4;
    packed = ((s32)color >> 3) & 0xF00;
    packed = (packed & ~0xF0) | (((s32)color >> 2) & 0xF0);
    width = x1 - x0;
    pixel = low | packed;
    height = y1 - y0;
    p = (u16 *)fn_802C3044((void *)lbl_8055FC00, x0, y0);
    skip = (*(s32 *)((u8 *)lbl_8055FC00 + 0x10) - width * 2);
    skip = ((skip >> 31) + skip) & ~1;
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

void fn_802C3754(s32 left, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 right, s32 arg6, s32 arg7) {
    /* Dispatches a canvas copy/blit operation based on the mode bytes (5/6 are special cases) of the left and right canvas objects, falling back to a trace when unsupported. */
    u8 leftMode = *(u8 *)left;
    s32 isOtherMode = 0;
    if ((s8)leftMode != 5 && (s8)leftMode != 6) isOtherMode = 1;
    if (isOtherMode) {
        isOtherMode = 0;
        if (*(s8 *)right != 5 && *(s8 *)right != 6) isOtherMode = 1;
        if (isOtherMode) {
            fn_802C3918(left,arg1,arg2,arg3,arg4,right,arg6,arg7);
            return;
        }
    }
    if ((s8)leftMode == 5 && (s32)*(u8 *)right == 5) {
        fn_802C3C68(left,arg1,arg2,arg3,arg4,right,arg6,arg7);
        return;
    }
    isOtherMode = 0;
    if ((s8)leftMode != 5 && (s8)leftMode != 6) isOtherMode = 1;
    if (isOtherMode && (s32)*(u8 *)right == 5) {
        fn_802C3D74(left,arg1,arg2,arg3,arg4,right,arg6,arg7);
        return;
    }
    if ((s8)leftMode == 5) {
        isOtherMode = 0;
        if (*(s8 *)right != 5 && *(s8 *)right != 6) isOtherMode = 1;
        if (isOtherMode) {
            fn_802C3F00(left,arg1,arg2,arg3,arg4,right,arg6,arg7);
            return;
        }
    }
    fn_802E317C(lbl_8034B078, (s32)*(s8 *)left, (s32)*(s8 *)right);
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
extern void fn_802C4388(s32,s32,s32,s32,s32,s32,s32,s32);
/* Dispatches a canvas copy/blit based on destination/source mode bytes (5/6 special-cased), tracing when unsupported. */
void fn_802C3850(s32 dstCanvas, s32 srcX, s32 srcY, s32 srcX2, s32 srcY2, s32 srcCanvas, s32 dstX, s32 dstY) {
    u8 dstMode = *(u8 *)dstCanvas;
    s32 isNormalMode = 0;
    if ((s8)dstMode != 5 && (s8)dstMode != 6) isNormalMode = 1;
    if (isNormalMode) {
        isNormalMode = 0;
        if (*(s8 *)srcCanvas != 5 && *(s8 *)srcCanvas != 6) isNormalMode = 1;
        if (isNormalMode) {
            fn_802C4108(dstCanvas, srcX, srcY, srcX2, srcY2, srcCanvas, dstX, dstY);
            return;
        }
    }
    if ((s8)dstMode == 5 && (s32)*(u8 *)srcCanvas == 5) {
        fn_802C4610(dstCanvas, srcX, srcY, srcX2, srcY2, srcCanvas, dstX, dstY);
        return;
    }
    if ((s8)dstMode == 5) {
        isNormalMode = 0;
        if (*(s8 *)srcCanvas != 5 && *(s8 *)srcCanvas != 6) isNormalMode = 1;
        if (isNormalMode) {
            fn_802C4388(dstCanvas, srcX, srcY, srcX2, srcY2, srcCanvas, dstX, dstY);
            return;
        }
    }
    fn_802E317C(lbl_8034B094, (s32)*(s8 *)dstCanvas, (s32)*(s8 *)srcCanvas);
}

extern s32 fn_802C3170(void *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern const char lbl_8034B0B8[];
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma processor 750
void fn_802C3918(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    s32 temp_r0, temp_r29, temp_r31;
    s32 temp_r4, temp_r5, temp_r6, temp_r0_4, temp_r4_4;
    s32 var_r4, var_r4_2, var_r7;
    u16 *var_r30, *var_r30_2, *var_r30_3, *var_r30_4;
    u16 *var_r3, *var_r3_2, *var_r3_3, *var_r3_4;
    u16 temp_r0_2, temp_r7, temp_r7_2, temp_r8;
    s8 temp_r4_2, temp_r5_2;

    sp8 = arg1;
    spC = arg2;
    sp10 = arg6;
    sp14 = arg7;
    sp1C = arg3 - arg1;
    sp18 = arg4 - arg2;
    if (fn_802C3170((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        var_r30 = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
        var_r3 = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
        temp_r31 = sp1C;
        temp_r5 = temp_r31 * 2;
        temp_r6 = *(s32 *)((u8 *)arg0 + 0x10) - temp_r5;
        temp_r29 = sp18;
        temp_r4 = *(s32 *)((u8 *)arg5 + 0x10) - temp_r5;
        temp_r5 = ((u32)temp_r6 >> 31) + temp_r6;
        temp_r0 = ((u32)temp_r4 >> 31) + temp_r4;
        temp_r5 &= ~1;
        temp_r6 = temp_r0 & ~1;
        do {
            var_r4 = sp1C;
loop_copy:
            temp_r0_2 = *var_r30;
            var_r4--;
            var_r30++;
            *var_r3 = temp_r0_2;
            var_r3++;
            if (var_r4 > 0)
                goto loop_copy;
            var_r30 = (u16 *)((u8 *)var_r30 + temp_r5);
            var_r3 = (u16 *)((u8 *)var_r3 + temp_r6);
            temp_r0 = sp18 - 1;
            sp18 = temp_r0;
        } while (temp_r0 > 0);

        temp_r5_2 = *(s8 *)arg5;
        temp_r4_2 = *(s8 *)arg0;
        if (temp_r4_2 != temp_r5_2) {
            if (temp_r4_2 == 4 && temp_r5_2 == 3) {
                var_r30_2 = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
                var_r3_2 = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
                sp1C = temp_r31;
                temp_r5 = temp_r31 * 2;
                sp18 = temp_r29;
                temp_r6 = *(s32 *)((u8 *)arg0 + 0x10) - temp_r5;
                temp_r4 = *(s32 *)((u8 *)arg5 + 0x10) - temp_r5;
                temp_r5 = ((u32)temp_r6 >> 31) + temp_r6;
                temp_r0 = ((u32)temp_r4 >> 31) + temp_r4;
                temp_r5 &= ~1;
                temp_r6 = temp_r0 & ~1;
                do {
                    var_r4_2 = sp1C;
loop_10:
                    temp_r7 = *var_r30_2;
                    var_r4_2--;
                    var_r30_2++;
                    temp_r0_2 = (temp_r7 >> 1) & 0x7FE0;
                    temp_r0_2 |= temp_r7 & 0x1F;
                    *var_r3_2 = temp_r0_2;
                    var_r3_2++;
                    if (var_r4_2 > 0)
                        goto loop_10;
                    var_r30_2 = (u16 *)((u8 *)var_r30_2 + temp_r5);
                    var_r3_2 = (u16 *)((u8 *)var_r3_2 + temp_r6);
                    temp_r0 = sp18 - 1;
                    sp18 = temp_r0;
                } while (temp_r0 > 0);
                return;
            }
            if (temp_r4_2 == 3 && temp_r5_2 == 4) {
                var_r30_3 = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
                var_r3_3 = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
                sp1C = temp_r31;
                temp_r5 = temp_r31 * 2;
                sp18 = temp_r29;
                temp_r6 = *(s32 *)((u8 *)arg0 + 0x10) - temp_r5;
                temp_r4 = *(s32 *)((u8 *)arg5 + 0x10) - temp_r5;
                temp_r5 = ((u32)temp_r6 >> 31) + temp_r6;
                temp_r0 = ((u32)temp_r4 >> 31) + temp_r4;
                temp_r5 &= ~1;
                temp_r6 = temp_r0 & ~1;
                do {
                    var_r7 = sp1C;
loop_17:
                    temp_r8 = *var_r30_3;
                    var_r7--;
                    var_r30_3++;
                    temp_r0_4 = ((s32)temp_r8 * 2) & 0x400;
                    temp_r4_4 = ((s32)temp_r8 * 2) & 0xFFC0;
                    temp_r4_4 |= temp_r8 & 0x1F;
                    temp_r0_4 = (temp_r4_4 | (temp_r0_4 >> 5));
                    *var_r3_3 = temp_r0_4;
                    var_r3_3++;
                    if (var_r7 > 0)
                        goto loop_17;
                    var_r30_3 = (u16 *)((u8 *)var_r30_3 + temp_r5);
                    var_r3_3 = (u16 *)((u8 *)var_r3_3 + temp_r6);
                    temp_r0 = sp18 - 1;
                    sp18 = temp_r0;
                } while (temp_r0 > 0);
                return;
            }
            if (temp_r4_2 == 1 && temp_r5_2 == 4) {
                var_r30_4 = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
                var_r3_4 = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
                sp1C = temp_r31;
                temp_r5 = temp_r31 * 2;
                sp18 = temp_r29;
                temp_r6 = *(s32 *)((u8 *)arg0 + 0x10) - temp_r5;
                temp_r4 = *(s32 *)((u8 *)arg5 + 0x10) - temp_r5;
                temp_r5 = ((u32)temp_r6 >> 31) + temp_r6;
                temp_r0 = ((u32)temp_r4 >> 31) + temp_r4;
                temp_r5 &= ~1;
                temp_r6 = temp_r0 & ~1;
                do {
                    var_r4 = sp1C;
loop_24:
                    temp_r7_2 = *var_r30_4;
                    var_r4--;
                    var_r30_4++;
                    temp_r0_2 = ((temp_r7_2 & 0xF) << 1);
                    temp_r0_2 |= (temp_r7_2 << 3) & 0x780;
                    temp_r0_2 |= (temp_r7_2 << 4) & 0xF000;
                    *var_r3_4 = temp_r0_2;
                    var_r3_4++;
                    if (var_r4 > 0)
                        goto loop_24;
                    var_r30_4 = (u16 *)((u8 *)var_r30_4 + temp_r5);
                    var_r3_4 = (u16 *)((u8 *)var_r3_4 + temp_r6);
                    temp_r0 = sp18 - 1;
                    sp18 = temp_r0;
                } while (temp_r0 > 0);
                return;
            }
            fn_802E317C(lbl_8034B0B8, (s32)temp_r4_2, (s32)temp_r5_2);
        }
    }
}
#pragma pop

// Keep the target scheduling and helper calls: these reproduce the original copy loop.
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_802C3C68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                 s32 arg5, s32 arg6, s32 arg7) {
    /* Blit a 32bpp rectangle from arg0 (arg1,arg2)-(arg3,arg4) to arg5 at (arg6,arg7), clipped to arg5 bounds. */
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    s32 *src, *dst;
    s32 i, widthBytes, skipSrc, skipDst;
    sp8 = arg1;
    spC = arg2;
    sp10 = arg6;
    sp14 = arg7;
    sp1C = arg3 - arg1;
    sp18 = arg4 - arg2;
    if (fn_802C3170((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        src = (s32 *)fn_802C3060((void *)arg0, sp8, spC);
        dst = (s32 *)fn_802C3060((void *)arg5, sp10, sp14);
        widthBytes = sp1C * 4;
        skipSrc = (*(s32 *)((char *)arg0 + 0x10) - widthBytes) / 4;
        skipDst = (*(s32 *)((char *)arg5 + 0x10) - widthBytes) / 4;
        do {
            i = sp1C;
loop_3:
            {
                s32 t = *src;
                i--;
                src++;
                *dst = t;
                dst++;
            }
            if (i > 0)
                goto loop_3;
            src += skipSrc;
            dst += skipDst;
            sp18--;
        } while (sp18 > 0);
    }
}

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma processor 750
void fn_802C3D74(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                  s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    u16 *src;
    s32 *dst;
    s32 srcRemain, dstRemain, srcSkip, dstSkip, i;
    u8 format;
    register s32 width;

    sp8 = arg1;
    spC = arg2;
    sp10 = arg6;
    sp14 = arg7;
    sp1C = arg3 - arg1;
    sp18 = arg4 - arg2;
    if (fn_802C3170((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        src = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
        dst = (s32 *)fn_802C3060((void *)arg5, sp10, sp14);
        width = sp1C;
        srcRemain = *(s32 *)((u8 *)arg0 + 0x10) - width * 2;
        format = *(u8 *)arg0;
        dstRemain = *(s32 *)((u8 *)arg5 + 0x10) - width * 4;
        srcSkip = (srcRemain + (s32)((u32)srcRemain >> 31)) >> 1;
        dstSkip = dstRemain / 4;
        if ((s8)format == 4) {
            srcSkip *= 2;
            dstSkip *= 4;
            do {
                i = sp1C;
                do {
                    u16 pixel = *src;
                    s32 converted;
                    src++;
                    converted = fn_802C2CC4(pixel);
                    i--;
                    *dst = converted;
                    dst++;
                } while (i > 0);
                src = (u16 *)((u8 *)src + srcSkip);
                dst = (s32 *)((u8 *)dst + dstSkip);
                sp18--;
            } while (sp18 > 0);
        } else if ((s8)format == 3) {
            srcSkip *= 2;
            dstSkip *= 4;
            do {
                i = sp1C;
                do {
                    u16 pixel = *src;
                    s32 converted;
                    src++;
                    converted = fn_802C2CAC(pixel);
                    i--;
                    *dst = converted;
                    dst++;
                } while (i > 0);
                src = (u16 *)((u8 *)src + srcSkip);
                dst = (s32 *)((u8 *)dst + dstSkip);
                sp18--;
            } while (sp18 > 0);
        } else {
            fn_802E317C(lbl_8034B0E4, (s32)(s8)format, *(s8 *)arg5);
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
    if (fn_802C3170(targetObj, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        src = (u32 *)fn_802C3060(sourceObj, sp8, spC);
        dst = (s16 *)fn_802C3044(targetObj, sp10, sp14);
        formatByte = *(u8 *)targetObj;
        format = (s8)formatByte;
        skipSrc = (*(s32 *)(sourceObj + 0x10) - sp1C * 4) / 4;
        skipDst = (*(s32 *)(targetObj + 0x10) - sp1C * 2) / 2;
        if (format == 3) {
            do {
                i = sp1C;
                do {
                    pixel = *src++;
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
                sp18--;
            } while (sp18 > 0);
        } else {
            fn_802E317C((char *)lbl_8034B100, *(s8 *)sourceObj);
        }
    }
}
#pragma scheduling on
#pragma pop
void fn_802C40B8(void *arg0, s32 arg1, s32 arg2) {
    if ((*(u8 *)((u8 *)lbl_8055FC00 + 1) & 4) != 0) {
        fn_802DB2C8();
        return;
    }
    fn_802C3754((s32)arg0, 0, 0,
        *(s32 *)((u8 *)arg0 + 8), *(s32 *)((u8 *)arg0 + 0xC),
        lbl_8055FC00, arg1, arg2);
}

void fn_802C40E8(void *arg0, s32 arg1, s32 arg2) {
    fn_802C3850((s32)arg0, 0, 0,
        *(s32 *)((u8 *)arg0 + 8), *(s32 *)((u8 *)arg0 + 0xC),
        lbl_8055FC00, arg1, arg2);
}

#pragma scheduling invalid_target
void fn_802C4108(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    s32 skipSrc, skipDst, i, a, ia;
    u16 *src, *dst;
    u32 s, d, b, g, r;
    s32 g5;

    sp8 = arg1;
    spC = arg2;
    sp10 = arg6;
    sp14 = arg7;
    sp1C = arg3 - arg1;
    sp18 = arg4 - arg2;
    if (fn_802C3170((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        u8 fmt;
        src = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
        dst = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
        skipSrc = (*(s32 *)((u8 *)arg0 + 0x10) - sp1C * 2) / 2;
        fmt = *(u8 *)arg5;
        skipDst = (*(s32 *)((u8 *)arg5 + 0x10) - sp1C * 2) / 2;
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
                    r = (ia * ((d >> 7) & 0xF8) + a * ((s >> 4) & 0xF0)) / 15;
                    g = (ia * ((d >> 2) & 0xF8) + a * (s & 0xF0)) / 15;
                    g5 = (s32)(g & 0xFF) >> 3;
                    *dst = ((s32)(b & 0xFF) >> 3) | ((g >> 1) & 0x3E0) | (((s32)(r & 0xFF) >> 3) << 10);
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
                    r = (ia * ((d >> 8) & 0xF8) + a * ((s >> 4) & 0xF0)) / 15;
                    g = (ia * ((d >> 3) & 0xFC) + a * (s & 0xF0)) / 15;
                    *dst = ((s32)(b & 0xFF) >> 3) | ((g << 3) & 0x7E0) | ((r << 8) & 0xF800);
                    dst++;
                } while (i > 0);
                src += skipSrc;
                dst += skipDst;
                sp18--;
            } while (sp18 > 0);
            return;
        }
        fn_802E317C(lbl_8034B124);
    }
}

#pragma scheduling invalid_target
void fn_802C4388(s32 src, s32 x, s32 y, s32 x2, s32 y2, s32 dst, s32 dx, s32 dy) {
    /* Blend source pixels into the two supported 16-bit destination formats. */
    s32 w, h, ty, tx, sy, sx;
    s32 srcskip, dstskip, n;
    u32 *sp;
    u16 *dp;
    sx = x; sy = y; tx = dx; ty = dy; w = x2 - x; h = y2 - y;
    if (!fn_802C3170((void *)dst, &tx, &ty, &sx, &sy, &w, &h)) return;
    sp = (u32 *)fn_802C3060((void *)src, sx, sy);
    dp = (u16 *)fn_802C3044((void *)dst, tx, ty);
    srcskip = (*(s32 *)((u8 *)src + 0x10) - w * 4) / 4;
    dstskip = (*(s32 *)((u8 *)dst + 0x10) - w * 2) / 2;
    if (*(s8 *)dst == 3) {
        do {
            n = w;
            do {
                u32 pixel = *sp++;
                u16 old = *dp;
                u32 a = pixel >> 24, inv = 255 - a;
                u8 b = (u8)((inv * ((old << 3) & 0xf8) + a * (u8)pixel) / 255);
                u8 g = (u8)((inv * ((old >> 2) & 0xf8) + a * (u8)(pixel >> 8)) / 255);
                u8 r = (u8)((inv * ((old >> 7) & 0xf8) + a * (u8)(pixel >> 16)) / 255);
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
                *dp++ = (b >> 27) | ((g >> 21) & 0x7e0) | ((r >> 16) & 0xf800);
            } while (--n > 0);
            sp += srcskip;
            dp += dstskip;
        } while (--h > 0);
    } else fn_802E317C(lbl_8034B124);
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
    if (fn_802C3170((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        var_r31 = (u32 *)fn_802C3060((void *)arg0, sp8, spC);
        var_r3 = (u32 *)fn_802C3060((void *)arg5, sp10, sp14);
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
            if (temp_r30 == 0) {
            } else if (temp_r30 == 0xFF) {
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
   handing every point to fn_802C32B8, the pixel plotter above.  An
   axis-aligned line just steps one pixel at a time along the axis it spans;
   any other line is walked by DDA: the major axis (the one spanning more,
   see fn_800241CC = abs) moves a whole pixel at a time in `dir`, while the
   minor coordinate accumulates the slope as a float and is truncated at each
   point. */
void fn_802C47B8(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    s32 dx, dy, pos, inc, end, dir, x, y;
    dx = x1 - x0;
    x = x0;
    y = y0;
    dy = y1 - y0;
    if (dx == 0) {
        if (dy != 0) {
            dir = -1;
            if (y0 < y1) dir = 1;
            pos = y0 * dir;
            inc = dir * dir;
            end = dir * y1;
            for (; pos < end; pos += inc, y += dir)
                fn_802C32B8(x, y, color);
        }
        return;
    }
    if (dy == 0) {
        dir = -1;
        if (x0 < x1) dir = 1;
        pos = x0 * dir;
        inc = dir * dir;
        end = dir * x1;
        for (; pos < end; pos += inc, x += dir)
            fn_802C32B8(x, y, color);
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
                fn_802C32B8((s32)fx, y, color);
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
            fn_802C32B8(x, (s32)fy, color);
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
/* fn_802C49E8 loads one by name, fn_802C4C80 releases it and fn_802C4C90
   draws one of its frames onto a canvas: it walks the frame's rows through
   the row table, decodes each row's 8-bit colour indices with one of the
   two palettes and writes them out.  The file is stored little-endian and
   its row table holds offsets into the block, so the first time a stamp is
   loaded fn_802C49E8 swaps every 32-bit field the game reads and turns
   those offsets into pointers. */
typedef struct {
    s32 width;                    /* 0x000 pixels per row */
    s32 height;                   /* 0x004 rows per frame */
    s32 x_off;                    /* 0x008 offset a frame is drawn at */
    s32 y_off;                    /* 0x00C */
    s32 frames;                   /* 0x010 frames in the stamp */
    u16 palette[2][256];          /* 0x014 colours: [0] on a mode 3 canvas,
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
void *fn_802C49E8(const char *name) {
    s32 unused;
    u32 version;
    u8 swap;
    u8 *obj;
    Stamp *stamp;
    u8 *p;
    u32 *rows;
    s32 row;
    u8 t;

    swap = 0;
    unused = 0;
    obj = (u8 *)((LoadResource)fn_8012C370)(name, STAMP_TAG, &version, &unused, 0, &swap);
    if (obj == 0)
        goto ret0;
    stamp = (Stamp *)obj;
    if (version != STAMP_VERSION)
        fn_802E317C(lbl_8034B144, name, version, STAMP_VERSION);
    if (swap != 0) {
        /* the header's five words and the two pointers, byte-swapped in place */
        STAMP_SWAP_WORD(obj, 0);
        STAMP_SWAP_WORD(obj, 4);
        STAMP_SWAP_WORD(obj, 8);
        STAMP_SWAP_WORD(obj, 12);
        STAMP_SWAP_WORD(obj, 16);
        STAMP_SWAP_WORD(obj, 0x814);
        STAMP_SWAP_WORD(obj, 0x818);
        /* the row table follows the header, the rows' pixels follow it */
        rows = (u32 *)(stamp + 1);
        stamp->rows = rows;
        stamp->pixels = (u8 *)rows + stamp->height * stamp->frames * 4;
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
    return obj;
ret0:
    return 0;
}
#pragma pop
void fn_802C4C80(void* arg0) {
    if (arg0 == NULL) {
        return;
    }
    fn_8012C4D8();
}

#pragma push
#pragma use_lmw_stmw off
void fn_802C4C90(void *obj, s32 arg1, s32 arg2, s32 arg3, void *tab) {
    u8 *g = (u8 *)lbl_8055FC00;
    if (!(g[1] & 4) && obj != 0 && arg3 < *(s32 *)((u8 *)obj + 0x10)) {
        s32 x, startX, col, y, startY;
        u16 *pal;
        s32 row;
        u8 *src;
        s32 w, h, t;
        u16 *d;
        y = arg2 - *(s32 *)((u8 *)obj + 0xC);
        x = *(s32 *)(g + 0x20) - y;
        h = *(s32 *)((u8 *)obj + 4);
        t = *(s32 *)(g + 0x18) - y;
        col = arg1 - *(s32 *)((u8 *)obj + 8);
        row = t & ~(t >> 31);
        if (h < x) x = h;
        w = *(s32 *)((u8 *)obj + 0);
        startX = *(s32 *)(g + 0x1C) - col;
        t = *(s32 *)(g + 0x14) - col;
        startY = t & ~(t >> 31);
        if (w < startX) startX = w;
        if (tab != 0) {
            if ((s8)*g == 3) pal = (u16 *)tab;
            else pal = (u16 *)((u8 *)tab + 0x200);
        } else if ((s8)*g == 3) {
            pal = (u16 *)((u8 *)obj + 0x14);
        } else {
            pal = (u16 *)((u8 *)obj + 0x214);
        }
        for (; row < x; row++) {
            s32 skip, len, flag, pos;
            src = *(u8 **)(*(s32 *)((u8 *)obj + 0x814) + (row + *(s32 *)((u8 *)obj + 4) * arg3) * 4);
            d = (u16 *)fn_802C3044((void *)lbl_8055FC00, col, row + y);
            for (pos = 0; pos < startX;) {
                len = *src++;
                if (len & 0x80) {
                    len &= ~0x80;
                    flag = 1;
                } else {
                    flag = 0;
                }
                if (startX - pos < len) len = startX - pos;
                if (flag != 0 && pos < startY) {
                    skip = startY - pos;
                    if (len < skip) skip = len;
                    len -= skip;
                    src += skip;
                    d += skip;
                    pos += skip;
                }
                if (flag != 0) {
                    u8 n = len;
                    while (n != 0) {
                        *d = pal[*src];
                        pos++;
                        src++;
                        d++;
                        n--;
                    }
                } else {
                    pos += len;
                    d += len;
                }
            }
        }
    }
}
#pragma pop
s32 fn_802C4EE4(s32* arg0) {
    if (arg0 != NULL) {
        return *arg0;
    }
    return 0;
}

s32 fn_802C4EFC(s32* arg0) {
    if (arg0 != NULL) {
        return arg0[1];
    }
    return 0;
}

s32 fn_802C4F14(s32* arg0) {
    if (arg0 != NULL) {
        return arg0[4];
    }
    return 0;
}

void fn_802C4F2C(void *arg0, s32 *arg1, s32 *arg2) {
    if (arg0 == 0) {
        *arg2 = 0;
        *arg1 = 0;
    } else {
        *arg1 = *(s32 *)((u8 *)arg0 + 8);
        *arg2 = *(s32 *)((u8 *)arg0 + 0xC);
    }
}

#pragma push
#pragma inline_depth(0)
void fn_802C4F58(s32 arg0, s32 arg1, const char *arg2, s32 arg3) {
    s32 var_r31 = arg3;
    const char *var_r30 = arg2;
    s32 var_r29 = arg1;
    s32 var_r28 = arg0;
    s32 ch;
    while ((ch = (s8)*var_r30++) != 0) {
        if ((s8)ch < 0x20 || (u8)ch > 0x7F)
            fn_802C5024(var_r28, var_r29, 0x23, var_r31);
        else
            fn_802C5024(var_r28, var_r29, ch, var_r31);
        var_r28 += 8;
    }
}
#pragma pop
extern unsigned int strlen(const char *);
unsigned int fn_802C4FF8(const char *s) { return strlen(s) * 8; }

int fn_802C501C(void) {
    return 8;
}

void fn_802C5024(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {}
extern const char lbl_8034B060[];
extern void fn_802C3320();
extern void fn_802C33A8();
extern void fn_802E317C(const char *, ...);
extern void fn_802C3850();
extern const char lbl_8034B078[];
extern void fn_802C3918(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3C68(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3D74(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3F00(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802DB2C8(void);
extern void fn_802C3478(s32, s32, s32, s32, u32);
extern void fn_802C365C(s32, s32, s32, s32, u32);
extern void fn_802C356C(s32, s32, s32, s32, u32);
