// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <stdarg.h>
typedef signed int s32;
typedef unsigned char u8;
typedef signed short s16;
extern s32 fn_80128668(s32 *);
extern s32 fn_802C4C80(s32);
extern s32 fn_802C4FF8(const char *);
extern s32 fn_802C4F2C(s32, s32 *, s32 *);
extern s32 fn_802C501C(void);
extern s32 fn_802C4EFC(s32);
extern void fn_801E4BEC(s32, s32, s32, s32, s32, const char *, ...);
/* "%s" in .sdata, the only format the counted-string drawer fn_801E4DBC needs.
 * Declared scalar so its address folds into a single sda21 load. */
extern s32 lbl_8055AEF0;
#define STR_PERCENT_S lbl_8055AEF0
extern char *strncpy(char *, const char *, unsigned long);
void fn_801E4A2C(s32 *fontObject) {
    /* RealName: BitmapFont_Destroy -- destroy a bitmap font: release the STMP
     * stamp resource held at +0x0, then free the font object itself. */
    if (fontObject != 0) {
        fn_802C4C80(*fontObject);
        fn_80128668(fontObject);
    }
}

#pragma scheduling invalid_target
/* Returns the total width of the whole null-terminated text string. If fontTable
 * is non-null, sums per-character widths from the 16-bit table at offset 0x204
 * indexed by each text byte; if null, falls back to the canvas string width. */
s32 fn_801E4A6C(s32 *fontTable, const u8 *text) {
    s32 charIndex;
    if (fontTable) {
        s32 totalWidth = 0;
        for (; *text != 0; text++) {
            charIndex = *text;
            totalWidth += *(s16 *)((u8 *)fontTable + (charIndex << 1) + 0x204);
        }
        return totalWidth;
    }
    return fn_802C4FF8((const char *)text);
}
/* RealName: Font_MeasureStringN
 * Returns the total width of up to count characters from text. If fontTable
 * is non-null, sums per-character widths from the 16-bit table at
 * fontTable[byte + 0x102]; if null, falls back to canvas string width. */
s32 fn_801E4AB0(s32 *fontTable, const u8 *text, s32 count) {
    if (fontTable != 0) {
        s32 sum = 0;
        const s16 *widthTable = (const s16 *)fontTable;
        while (*text && count > 0) {
            s16 charWidth = widthTable[*text + 0x102];
            --count;
            ++text;
            sum += charWidth;
        }
        return sum;
    }
    return fn_802C4FF8((const char *)text);
}
#pragma scheduling invalid_target
/* Return the glyph/advance width for a font object, or the default canvas char width when no object is provided. */
s32 fn_801E4B00(s32 *fontObject) {
    s32 scratch;
    s32 width;
    if (fontObject != 0) {
        width = 0;
        fn_802C4F2C(*fontObject, &scratch, &width);
        return width;
    }
    return fn_802C501C();
}
#pragma scheduling on
// Returns the object's line-height metric minus the secondary value from fn_802C4F2C, or 0 if null.
s32 fn_801E4B48(s32 *arg0) {
    s32 spC;
    s32 sp8;
    s32 result;
    if (arg0 != 0) {
        sp8 = 0;
        fn_802C4F2C(*arg0, &spC, &sp8);
        result = fn_802C4EFC(*arg0) - sp8;
    } else {
        result = 0;
    }
    return result;
}
#pragma dont_inline on
/* RealName: BitmapFont_GetLineHeight (sum of ascent/baseline metric and glyph advance width). */
s32 fn_801E4BA8(s32 *fontObject) {
    /* Returns the font's full line height by combining its baseline metric and glyph width. */
#define GetFontBaselineMetric fn_801E4B48
#define GetGlyphAdvanceWidth  fn_801E4B00
    s32 baselineMetric = GetFontBaselineMetric(fontObject);
    s32 lineHeight = GetGlyphAdvanceWidth(fontObject);
    lineHeight += baselineMetric;
#undef GetFontBaselineMetric
#undef GetGlyphAdvanceWidth
    return lineHeight;
}
extern s32 fn_802C4C90(s32, s32, s32, s32, s32);
extern void fn_802C4F58(s32, s32, const char *, s32);
extern int vsprintf(char *, const char *, va_list);
extern s32 lbl_8055FBC0;
extern s32 lbl_8055FBFC;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* Draws formatted text using a bitmap font, applying alignment flags to position it;
 * falls back to a plain shadowed string draw when no font is provided. */
void fn_801E4BEC(s32 font, s32 drawFlags, s32 align, s32 x, s32 y, const char *format, ...) {
    char text[0x1000];
    va_list args;
    s32 value;
    long half;
    u8 *p;

    va_start(args, format);
    vsprintf(text, format, args);
    va_end(args);

    value = fn_801E4A6C((s32 *)font, (u8 *)text);
    if (align & 2) {
        x -= value;
    } else if (align & 4) {
        half = (unsigned int)value >> 31;
        half += value;
        half >>= 1;
        x -= half;
    }
    if (align & 8) {
        y += fn_801E4B00((s32 *)font);
    } else if (align & 0x10) {
        value = fn_801E4B00((s32 *)font);
        half = fn_801E4B48((s32 *)font);
        half = value - half;
        half = ((unsigned int)half >> 31) + half;
        half >>= 1;
        y += half;
    } else if (align & 0x40) {
        y -= fn_801E4B48((s32 *)font);
    }
    if (font) {
        p = (u8 *)text;
        while (*p != 0) {
            register u8 *glyph;
            glyph = (u8 *)font + ((unsigned int)*p << 1);
            if (*(s16 *)(glyph + 4) >= 0) {
                fn_802C4C90(*(s32 *)font,
                    x + *(s16 *)(glyph + 0x404),
                    y,
                    *(s16 *)(glyph + 4),
                    drawFlags);
            }
            x += *(s16 *)((u8 *)font + ((unsigned int)*p << 1) + 0x204);
            ++p;
        }
    } else {
        fn_802C4F58(x + 1, y + 1, text, lbl_8055FBC0);
        fn_802C4F58(x, y, text, lbl_8055FBFC);
    }
}
extern s32 fn_801E4B00(s32 *);
extern s32 fn_801E4B48(s32 *);
extern s32 fn_802C4EFC(s32);
extern void fn_801E4BEC(s32, s32, s32, s32, s32, const char *, ...);
extern char *strncpy(char *, const char *, unsigned long);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* Draw one line of a counted string -- text is not NUL-terminated, length bytes
 * of it are copied into a local buffer and closed with a NUL -- through the
 * formatted bitmap-font drawer fn_801E4BEC, which takes it as the argument of
 * its only format, "%s".  font 0 makes that drawer fall back to drawing the
 * plain string twice (shadow and foreground) instead of with glyphs. */
void fn_801E4DBC(s32 font, s32 drawFlags, s32 align, s32 x, s32 y, const char *text, unsigned long length) {
    char buf[0x100];
    strncpy(buf, text, length);
    buf[length] = 0;
    ((void (*)(s32, s32, s32, s32, s32, const char *, ...))fn_801E4BEC)(font, drawFlags, align, x, y, (char *)&STR_PERCENT_S, buf);
}
