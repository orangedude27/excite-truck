__declspec(section ".sdata") extern char lbl_8055B8B8[];
__declspec(section ".sdata") extern char lbl_8055B918[], lbl_8055B920[];

typedef struct { unsigned int w[22]; } Cfg58;
extern Cfg58 lbl_802F9F58;
extern char lbl_8033FBE8[];
__declspec(section ".sdata2") extern char lbl_8055B8C4[];
__declspec(section ".sdata2") extern char lbl_8055B8CC[];
__declspec(section ".sdata2") extern char lbl_8055B8D4[];
__declspec(section ".sdata2") extern char lbl_8055B8DC[];
__declspec(section ".sdata2") extern char lbl_8055B8E4[];
__declspec(section ".sdata2") extern char lbl_8055B8E8[];
__declspec(section ".sdata2") extern char lbl_8055B8F0[];
__declspec(section ".sdata2") extern char lbl_8055B8F8[];
__declspec(section ".sdata2") extern char lbl_8055B8FC[];
__declspec(section ".sdata2") extern char lbl_8055B900[];
__declspec(section ".sdata2") extern char lbl_8055B908[];
__declspec(section ".sdata2") extern char lbl_8055B910[];
extern int fn_8022CC8C(const char*);
extern void readTextEffectProps(int*, void*);
extern int stricmp(const char*, const char*);
extern void* fn_80131810(const char*, int, int);
extern void* fn_80131818(void*);
extern void fn_80131820(void*);
extern void fn_802E30C8(void*, ...);
extern void fn_8022A858(int);
typedef struct CfgObj CfgObj;
typedef struct CfgVTab {
    void* v0;
    void* v4;
    char* (*getName)(CfgObj*);
    int   (*hasProp)(CfgObj*, const char*);
    char* (*getStr)(CfgObj*, const char*);
    int   (*getIntDef)(CfgObj*, const char*, int);
    int   (*getInt)(CfgObj*, const char*);
    int   (*v20)(CfgObj*, const char*, int);
    void* v24;
    float (*getFloat)(CfgObj*, const char*, float);
    void* v2c;
    void* v30;
    void* v34;
    void* v38;
    void* v3c;
    void* v40;
    void* v44;
    void* v48;
    void* v4c;
    void* v50;
    void* v54;
    void* v58;
    int   (*v5c)(CfgObj*, const char*);
} CfgVTab;
struct CfgObj { CfgVTab* vt; };
typedef struct XmlObj2 XmlObj2;
typedef struct {
    void *v0;
    void *v4;
    void *v8;
    int (*has)(XmlObj2 *, const char *);
    void *v10;
    char *(*get)(XmlObj2 *, const char *);
} XmlVTab2;
struct XmlObj2 { XmlVTab2 *vt; };


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

__declspec(section ".sdata") extern char lbl_8055B8B0[];
extern char lbl_80490968[];
struct Record74 {
    unsigned char b0;
    unsigned char pad[3];
    unsigned int w4, w8, wC, w10, w14, w18, w1C, w20, w24, w28, w2C, w30;
    float f34;
    unsigned int w38, w3C, w40, w44, w48, w4C, w50, w54, w58;
    float f5C, f60;
    unsigned int w64, w68, w6C, w70;
};
extern char *strstr(const char *, const char *);
extern void fn_8022C9D0(void);
extern int fn_80232B70(int);
extern void fn_8022A8E4(int);
extern double lbl_80563590;
extern float lbl_80563598;
extern int stampGetHeight(int);
extern int gxGetImageHeight(int);
#define I2F(x) ((float)((double)((x) ^ 0x80000000) - lbl_80563590))
extern int stampGetWidth(int);
extern int gxGetImageWidth();
extern unsigned long strlen(const char *);
extern void stampGetOffsets(int, int *, int *);
extern int fn_801E4AB0(int, char *, int);
extern char *strchr(const char *, int);
__declspec(section ".sdata") extern char lbl_8055B8C0[];
extern int fn_801E4B00(int *);
extern int fn_801E4B48(int *);
extern int fn_80232B78(int);
extern char lbl_8033FF98[];
extern int stricmp(const char *, const char *);
extern void fn_8022CAA8();
extern float lbl_80563588;
extern char *strncpy(char *, const char *, unsigned int);
extern void fn_8023293C(void *, char *, float);
extern int fn_800241CC(int);
extern void fn_8022B390(const char *, const char *, int, int *, int *);
void fn_8022A5E4(void) {
#pragma scheduling invalid_target
    extern unsigned char lbl_80497D68[];
    extern void *memset(void *, int, unsigned int);
    extern void loadTextStyleOverrides(void);
    struct Record74 *out;
    unsigned char b0;
    volatile int s1C, s18, s14, s10, sC, s30, s2C, s28, s24, s20;
    int v4, v8, vC, v10, v14, v18, v1C, v20, v24, v28, v2C, v30;
    int v3C, v40, v44, v48, v4C, v50, v54, v58;
    int v64, v68, v6C, v70;
    float v60, v5C, v34;
    int i;

    memset(lbl_80497D68, 0, 0x74);
    b0 = lbl_80497D68[0];
    sC = *(int *)(lbl_80497D68 + 0xC); s10 = *(int *)(lbl_80497D68 + 0x10);
    s14 = *(int *)(lbl_80497D68 + 0x14); s18 = *(int *)(lbl_80497D68 + 0x18);
    s1C = *(int *)(lbl_80497D68 + 0x1C); s20 = *(int *)(lbl_80497D68 + 0x20);
    s24 = *(int *)(lbl_80497D68 + 0x24); s28 = *(int *)(lbl_80497D68 + 0x28);
    s2C = *(int *)(lbl_80497D68 + 0x2C); s30 = *(int *)(lbl_80497D68 + 0x30);
    *(int *)(lbl_80497D68 + 0x38) = 9;
    vC = *(int *)(lbl_80497D68 + 0xC); v10 = *(int *)(lbl_80497D68 + 0x10);
    v14 = *(int *)(lbl_80497D68 + 0x14); v18 = *(int *)(lbl_80497D68 + 0x18);
    v1C = *(int *)(lbl_80497D68 + 0x1C); v20 = *(int *)(lbl_80497D68 + 0x20);
    v24 = *(int *)(lbl_80497D68 + 0x24); v28 = *(int *)(lbl_80497D68 + 0x28);
    v2C = *(int *)(lbl_80497D68 + 0x2C); v30 = *(int *)(lbl_80497D68 + 0x30);
    v4 = *(int *)(lbl_80497D68 + 4); v8 = *(int *)(lbl_80497D68 + 8);
    v3C = *(int *)(lbl_80497D68 + 0x3C); v40 = *(int *)(lbl_80497D68 + 0x40);
    v44 = *(int *)(lbl_80497D68 + 0x44); v48 = *(int *)(lbl_80497D68 + 0x48);
    v4C = *(int *)(lbl_80497D68 + 0x4C); v50 = *(int *)(lbl_80497D68 + 0x50);
    v54 = *(int *)(lbl_80497D68 + 0x54); v58 = *(int *)(lbl_80497D68 + 0x58);
    v64 = *(int *)(lbl_80497D68 + 0x64); v68 = *(int *)(lbl_80497D68 + 0x68);
    v6C = *(int *)(lbl_80497D68 + 0x6C); v70 = *(int *)(lbl_80497D68 + 0x70);
    v34 = *(float *)(lbl_80497D68 + 0x34); v5C = *(float *)(lbl_80497D68 + 0x5C);
    v60 = *(float *)(lbl_80497D68 + 0x60);
    out = (struct Record74 *)lbl_80490968;
    for (i = 0; i < 0x80; i++) {
        out[0].b0 = b0;
        out[0].w4 = v4; out[0].w8 = v8; out[0].wC = vC; out[0].w10 = v10;
        out[0].w14 = v14; out[0].w18 = v18; out[0].w1C = v1C; out[0].w20 = v20;
        out[0].w24 = v24; out[0].w28 = v28; out[0].w2C = v2C; out[0].w30 = v30;
        out[0].f34 = v34; out[0].w38 = 9;
        out[0].w3C = v3C; out[0].w40 = v40; out[0].w44 = v44; out[0].w48 = v48;
        out[0].w4C = v4C; out[0].w50 = v50; out[0].w54 = v54; out[0].w58 = v58;
        out[0].f5C = v5C; out[0].f60 = v60;
        out[0].w64 = v64; out[0].w68 = v68; out[0].w6C = v6C; out[0].w70 = v70;
        out[1].b0 = b0;
        out[1].w4 = v4; out[1].w8 = v8; out[1].wC = vC; out[1].w10 = v10;
        out[1].w14 = v14; out[1].w18 = v18; out[1].w1C = v1C; out[1].w20 = v20;
        out[1].w24 = v24; out[1].w28 = v28; out[1].w2C = v2C; out[1].w30 = v30;
        out[1].f34 = v34; out[1].w38 = 9;
        out[1].w3C = v3C; out[1].w40 = v40; out[1].w44 = v44; out[1].w48 = v48;
        out[1].w4C = v4C; out[1].w50 = v50; out[1].w54 = v54; out[1].w58 = v58;
        out[1].f5C = v5C; out[1].f60 = v60;
        out[1].w64 = v64; out[1].w68 = v68; out[1].w6C = v6C; out[1].w70 = v70;
        out += 2;
    }
    loadTextStyleOverrides();
}

/* Shut down the style/config subsystem started by fn_8022A5E4: tail-call the sweep
   that destroys and clears every active 0x74-byte record in lbl_80490968. */
void fn_8022A7D0(void) {
    fn_8022C9D0();
}

#pragma push
#pragma dont_inline on
int fn_8022A7D4(const char *resourceName) {
    /* Nonzero if the resource name contains the ".img" extension (lbl_8055B8B0),
       selecting the image loader at the resource-dispatch site. */
    return strstr(resourceName, lbl_8055B8B0) != 0;
}

int fn_8022A804(const char *resourceName) {
    /* Nonzero if the resource name contains the ".art" extension (lbl_8055B8B8),
       selecting the archive loader at the resource-dispatch site. */
    return strstr(resourceName, lbl_8055B8B8) != 0;
}
#pragma pop

#pragma push
#pragma dont_inline on
extern int __rlwimi(int, int, int, int, int);
unsigned int fn_8022A834(unsigned int color) {
    /* Normalize a packed 32-bit color: a nonzero top byte below 0x20 is a palette index and becomes 0xFF (opaque); low 24 bits are kept. */
    unsigned int highByte = color >> 24;
    if (highByte < 0x20 && (int)highByte != 0) {
        highByte = 0xFF;
    }
    return __rlwimi(color & 0xFFFFFF, highByte, 24, 0, 7);
}
#pragma pop

/* Initialize the UI text style at styleIndex in the style table; the caller's
 * descriptor block (arriving in r4) is forwarded to fn_8022CAA8 unchanged. */
void fn_8022A858(int styleIndex) {
#define StyleTable lbl_80490968
    fn_8022CAA8(StyleTable + styleIndex * 0x74);
#undef StyleTable
}

#pragma dont_inline on
#pragma scheduling invalid_target
/* Allocate a UI text style.
 *
 * Walks the 0x100 style records of the style table (0x74 bytes each, see
 * struct UIStyle below; fn_8022CA2C(n) is the address of the n-th) and takes
 * the first free one -- a record whose inUse byte at +0x00 is 0 -- fills it
 * from the caller's 0x58-byte parameter block through fn_8022A858 ->
 * fn_8022CAA8 (the block travels in r4) and returns its index.  With every
 * slot taken it reports "UIStyle: too many styles" and returns -1. */
int fn_8022A86C(void *params) {
    extern int Abend_Panic(const char *, ...);
    #define StyleTable      lbl_80490968 /* the 0x100 UI text styles */
    #define UI_STYLE_COUNT  0x100
    #define TooManyStyles   lbl_8033FBE8 /* "UIStyle: too many styles" */

    unsigned char *entry = (unsigned char *)StyleTable;
    int index = 0;
    int count;

    for (count = UI_STYLE_COUNT; count != 0; count--) {
        if (*entry == 0) { /* this style is free */
            ((void (*)(int, void *))fn_8022A858)(index, params);
            return index;
        }
        entry += 0x74;
        index++;
    }
    Abend_Panic(TooManyStyles, params);
    #undef StyleTable
    #undef UI_STYLE_COUNT
    #undef TooManyStyles
    return -1;
}
#pragma scheduling invalid_target
void fn_8022A8E4(int arg0) {
    extern unsigned char lbl_80497D68[];
    extern void fn_801E4A2C(void *);
    extern void fn_802328D4(void *);
    extern void fn_802C4C80(void *);
    extern void fn_802C519C(void *);
    extern void fn_80235380(void *);
    unsigned long offset;
    register unsigned char *entry;
    register const unsigned int *source;
    register unsigned int *destination;
    register unsigned int b, a;
    float f0, f1;

    offset = arg0 * 0x74;
    entry = (unsigned char *)lbl_80490968 + offset;
    if (*(void **)(entry + 4) != 0) fn_801E4A2C(*(void **)(entry + 4));
    if (*(void **)(entry + 8) != 0) fn_802328D4(*(void **)(entry + 8));
    if (*(void **)(entry + 0x64) != 0) fn_802C4C80(*(void **)(entry + 0x64));
    if (*(void **)(entry + 0x68) != 0) fn_802C519C(*(void **)(entry + 0x68));
    if (*(void **)(entry + 0x6c) != 0) fn_80235380(*(void **)(entry + 0x6c));
    if (*(void **)(entry + 0x70) != 0) fn_80235380(*(void **)(entry + 0x70));

    entry[0] = *(unsigned char *)lbl_80497D68;
    source = (const unsigned int *)lbl_80497D68;
    destination = (unsigned int *)((unsigned char *)lbl_80490968 + arg0 * 0x74);
    a = source[1];
    b = source[2];
    destination[1] = a; a = source[3];
    destination[2] = b; b = source[4];
    destination[3] = a; a = source[5];
    destination[4] = b; b = source[6];
    destination[5] = a; a = source[7];
    destination[6] = b; b = source[8];
    destination[7] = a; a = source[9];
    destination[8] = b; b = source[10];
    destination[9] = a; a = source[11];
    destination[10] = b; b = source[12];
    destination[11] = a; a = source[13];
    destination[12] = b;
    f0 = *(const float *)((const unsigned char *)source + 0x34);
    *(float *)(destination + 13) = f0;
    a = source[14]; b = source[15];
    destination[14] = a; a = source[16];
    destination[15] = b; b = source[17];
    destination[16] = a; a = source[18];
    destination[18] = a; a = source[20];
    destination[17] = b; b = source[19];
    destination[19] = b; b = source[21];
    destination[20] = a; a = source[22];
    destination[22] = a;
    destination[21] = b; b = source[23];
    f1 = *(const float *)((const unsigned char *)source + 0x5c);
    f0 = *(const float *)((const unsigned char *)source + 0x60);
    *(float *)(destination + 23) = f1;
    *(float *)(destination + 24) = f0;
    a = source[25]; b = source[26];
    destination[25] = a; a = source[27];
    destination[27] = a;
    destination[26] = b; b = source[28];
    destination[28] = b;
    entry[0] = 0;
}
#pragma scheduling reset
extern void *fn_8022CA2C();
#define UI_STYLE_ALIGN 0x38 /* byte offset of the align field in a UIStyle record */

int fn_8022AA84(int styleIndex) {
    /* Return the alignment flags (UI_HALIGN_* | UI_VALIGN_*) of the UI text style at styleIndex. */
    return *(int *)((char *)fn_8022CA2C(styleIndex) + UI_STYLE_ALIGN);
}

extern float fn_8022CA40(void *);
extern float lbl_8056358C;
#pragma push
#pragma processor 750
float fn_8022AAA8(void *unused, char *text) {
    /* Return the measured text width for the current style, scaled by that style's size factor, or 0 if no font is set. */
    void *style = fn_8022CA2C();
    if (*(int *)((char *)style + 8) != 0) {
        float scale = fn_8022CA40(style);
        float width = ((float (*)(void *, char *, float))fn_8023293C)(*(void **)((char *)style + 8), text, lbl_80563588);
        return width * scale;
    }
    return lbl_8056358C;
}
#pragma pop
/* Return the UIStyle text-box padding (fn_8022CA2C) for the given axis (0 = horizontal: +0x44 padLeft / +0x4c padRight; 1 = vertical: +0x48 padTop / +0x50 padBottom) and side (2 = leading, other = trailing). */
int fn_8022AB18(int styleIndex, int axis, int side) {
    void *style = fn_8022CA2C();
    if (axis == 0) {
        if (side == 2) return *(int *)((char *)style + 0x44);
        return *(int *)((char *)style + 0x4c);
    }
    if (axis == 1) {
        if (side == 2) return *(int *)((char *)style + 0x48);
        return *(int *)((char *)style + 0x50);
    }
    return 0;
}

#pragma push
#pragma dont_inline on
/* Counts occurrences of ch in the NUL-terminated str (callers pass '\n' to count lines). */
int fn_8022AB94(const char *str, char ch) {
    int count = 0;
    while (*str != 0) {
        if (*str == ch) count++;
        str++;
    }
    return count;
}
#pragma pop

#pragma scheduling invalid_target
void fn_8022ABC8(void *font, const char *text, int length) {
    /* Measure the width of the first `length` bytes of `text` with a UI
     * style's outline font (UIStyle.vectorFont, UIStyle+8).
     *
     * The measurer fn_8023293C only takes a NUL-terminated string, so the run
     * is copied into a 2 KiB stack buffer and closed with a NUL before it is
     * measured with no extra line spacing.  Its width is not used here but is
     * left in f1, which is how the callers read it back -- they reach this
     * function through a float (*)(void *, char *, int) cast.
     * Proposed name: MeasureTextWidthN */
    #define NO_EXTRA_SPACING lbl_80563588 /* 1.0f: the font's own line height */

    char line[0x800];

    strncpy(line, text, length);
    line[length] = 0;
    fn_8023293C(font, line, NO_EXTRA_SPACING);
    #undef NO_EXTRA_SPACING
}
#pragma scheduling on
extern void fn_8022ACFC(int, char *, float *, float *, float *, float *, float, float);
__declspec(section ".sdata2") extern double lbl_80563590;
void fn_8022AC1C(int unused0, char *unused1, int screenX, int screenY, int *outLeft, int *outTop, int *outRight, int *outBottom) {
    /* Convert screen coordinates to viewport rect (left, top, right, bottom) via fn_8022ACFC. */
    float left, top, right, bottom;
    float fx = (float)screenX;
    float fy = (float)screenY;
    fn_8022ACFC(unused0, unused1, &left, &top, &right, &bottom, fx, fy);
    *outLeft = (int)left;
    *outTop = (int)top;
    *outRight = (int)right;
    *outBottom = (int)bottom;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8022ACFC(int unused, char *str, float *outMinX, float *outMinY, float *outMaxX, float *outMaxY, float x0, float y0) {
    int n;
    float wid, hgt, one;
    char *p = fn_8022CA2C(unused);
    float minX = x0, minY = y0, maxX = x0, maxY = y0;
    int h = *(int *)(p + 0x64);
    if (h) {
        int a, b, hh;
        float t;
        stampGetOffsets(h, &a, &b);
        n = stampGetWidth(*(int *)(p + 0x64));
        hh = stampGetHeight(*(int *)(p + 0x64));
        minX = x0 - (float)a;
        if (x0 < minX) minX = x0;
        t = (float)n + (x0 - (float)a);
        maxX = (x0 > t) ? maxX : t;
        t = y0 - (float)b;
        minY = (y0 < t) ? minY : t;
        t = (float)hh + (y0 - (float)b);
        maxY = (y0 > t) ? maxY : t;
    } else if (*(int *)(p + 0x68) != 0) {
        float t;
        maxX = x0 + (float)gxGetImageWidth(*(int *)(p + 0x68));
        if (x0 > maxX) maxX = x0;
        t = y0 + (float)gxGetImageHeight(*(int *)(p + 0x68));
        maxY = (y0 > t) ? maxY : t;
    }
    if (str != 0) {
        float w = lbl_8056358C, ax, ay, dl, dw;
        int i, g;
        n = fn_8022AB94(str, 10) + 1;
        if (*(int *)(p + 4) != 0) {
            w = (float)n * (float)fn_801E4BA8(*(int **)(p + 4));
        }
        g = *(int *)((unsigned short)p + 8);
        if (g != 0) {
            if (*(float *)(p + 0x34) < lbl_80563588) {
                w = (float)n * (float)fn_80232B70(g);
            } else {
                dw = (float)fn_80232B70(g);
                w = (*(float *)(p + 0x34) * (float)(n * fn_80232B70(g))) / dw;
            }
        }
        hgt = w;
        wid = lbl_8056358C;
        one = lbl_80563588;
        for (i = 0; i < n; i++) {
            char *nl = strchr(str, 10);
            int len;
            float v;
            if (nl != 0) len = nl - str; else len = strlen(str);
            if (*(int *)(p + 4) != 0) {
                v = (float)fn_801E4AB0(*(int *)(p + 4), str, len);
                wid = (wid > v) ? wid : v;
            }
            if (*(int *)(p + 8) != 0) {
                if (*(float *)(p + 0x34) < one) {
                    v = ((float (*)(void *, char *, int))fn_8022ABC8)(*(void **)(p + 8), str, len);
                    wid = (wid > v) ? wid : v;
                } else {
                    dl = (float)fn_80232B70(*(int *)(p + 8));
                    v = (*(float *)(p + 0x34) * ((float (*)(void *, char *, int))fn_8022ABC8)(*(void **)(p + 8), str, len)) / dl;
                    wid = (wid > v) ? wid : v;
                }
            }
            str = strchr(str, 10);
            if (str) str = str + 1;
        }
        {
            int fl = *(int *)(p + 0x38);
            ax = lbl_8056358C;
            ay = ax;
            if (fl & 2) ax = -wid;
            else if (fl & 4) ax = -wid * lbl_80563598;
            if (fl & 0x40) ay = -hgt;
            else if (fl & 0x10) ay = -hgt * lbl_80563598;
            else if (fl & 0x20) {
                ay = lbl_8056358C;
                if (*(int *)(p + 4) != 0) ay = -(float)fn_801E4B00(*(int **)(p + 4));
                if (*(int *)(p + 8) != 0) ay = -(float)fn_80232B78(*(int *)(p + 8));
            }
        }
        wid += lbl_80563598 * (float)(fn_801E4A6C(*(int **)(p + 4), lbl_8055B8C0) + 1);
        {
            int hi, lo;
            float t;
            lo = *(int *)(p + 0x44);
            hi = *(int *)(p + 0x4c);
            t = x0 + ax + (float)(hi < lo ? hi : lo);
            minX = (minX < t) ? minX : t;
            t = wid + (x0 + ax) + (float)(hi > lo ? hi : lo);
            maxX = (maxX > t) ? maxX : t;
        }
        {
            int hi, lo;
            float t;
            lo = *(int *)(p + 0x48);
            hi = *(int *)(p + 0x50);
            t = y0 + ay + (float)(hi < lo ? hi : lo);
            minY = (minY < t) ? minY : t;
            t = hgt + (y0 + ay) + (float)(hi > lo ? hi : lo);
            maxY = (maxY > t) ? maxY : t;
        }
    }
    *outMinX = minX;
    *outMaxX = maxX;
    *outMinY = minY;
    *outMaxY = maxY;
}
#pragma pop
extern float lbl_80563588;
extern char *strncpy(char *, const char *, unsigned int);
extern void fn_8023293C(void *, char *, float);
extern int fn_800241CC(int);
extern void fn_8022B390(const char *, const char *, int, int *, int *);
#pragma push
#pragma use_lmw_stmw off
/* Returns the character index in `text` whose measured cursor position is closest to (`targetX`, `targetY`) in Manhattan distance. */
int fn_8022B2D4(int textContext, const char *text, int targetX, int targetY) {
    int bestIndex = 0, bestDistance = -1, charIndex = 0;
    goto check;
body: {
        int cursorX, cursorY;
        int distance;
        fn_8022B390((const char *)textContext, text, charIndex, &cursorX, &cursorY);
        distance = fn_800241CC(cursorX - targetX) + fn_800241CC(cursorY - targetY);
        if (bestDistance < 0 || distance < bestDistance) {
            bestIndex = charIndex;
            bestDistance = distance;
        }
        charIndex = charIndex + 1;
    }
check:
    if (charIndex == 0) goto body;
    if ((signed char)text[charIndex - 1] != 0) goto body;
    return bestIndex;
}
extern int fn_801E4A6C(int *, const char *);
extern int fn_801E4BA8(int *);
/* Advances a cursor position over up to maxChars of text in the current UI font context, measuring glyph advance/newline height via the vector or bitmap font. */
void fn_8022B390(const char *unusedLabel, const char *text, int maxChars, int *outX, int *outY) {
    union LocalChar {
        short half;
        char byte;
    } sp8;
    void *ctx;
    int x;
    int y;
    int i;
    ctx = fn_8022CA2C();
    sp8.half = 0;
    i = 0;
    x = *(int *)((char *)ctx + 0x44);
    y = *(int *)((char *)ctx + 0x48);
    while (*text != 0 && i < maxChars) {
        if (*text != 10) {
            sp8.byte = *text;
            if (*(int *)((char *)ctx + 8) != 0) {
                x += (int)((float (*)(void *, char *, float))fn_8023293C)(*(void **)((char *)ctx + 8), &sp8.byte, lbl_80563588);
            } else if (*(int *)((char *)ctx + 4) != 0) {
                x += fn_801E4A6C(*(int **)((char *)ctx + 4), &sp8.byte);
            }
        } else {
            if (*(int *)((char *)ctx + 8) != 0) {
                y += fn_80232B70(*(int *)((char *)ctx + 8));
            } else if (*(int *)((char *)ctx + 4) != 0) {
                y += fn_801E4BA8(*(int **)((char *)ctx + 4));
            }
            x = *(int *)((char *)ctx + 0x44);
        }
        i++;
        text++;
    }
    *outX = x;
    *outY = y;
}

#pragma push
#pragma processor 750
/* Computes the X offset for drawing text with the given style and string.
 * Measures the text width (using the font or bitmap font), applies the style's
 * horizontal alignment (left/right/center) within the canvas width, and returns
 * the pixel offset. If no string is given, returns the canvas width directly. */
int fn_8022B498(int unused, const char *arg1)
{
    struct Holder { int m; } h;
    int *max = &h.m;
    register void *ctx;
    int value;

    ctx = fn_8022CA2C();
    value = *(int *)((char *)ctx + 0x64);
    *max = 0;
    if (value != 0) {
        *max = stampGetWidth(value);
    } else {
        int sub = *(int *)((char *)ctx + 0x68);
        if (sub != 0) {
            *max = gxGetImageWidth(sub);
        }
    }

    if (arg1 != 0) {
        int width = 0;
        int flags;
        int height = 0;
        int result = 0;
        void *font = *(void **)((char *)ctx + 4);

        if (font != 0) {
            result = fn_801E4A6C(font, arg1);
        }
        if (*(void **)((char *)ctx + 8) != 0) {
            float scale;
            if (*(float *)((char *)ctx + 0x34) < lbl_80563588) {
                scale = lbl_80563588;
            } else {
                scale = *(float *)((char *)ctx + 0x34) / (float)fn_80232B70(*(int *)((char *)ctx + 8));
            }
            result = (int)(scale * ((float (*)(void *, const char *, float))fn_8023293C)(*(void **)((char *)ctx + 8), arg1, lbl_80563588));
        }

        flags = *(int *)((char *)ctx + 0x38);
        if (flags & 2) {
            width = -result;
        } else if (flags & 4) {
            width = (-result) / 2;
        }

        if (flags & 1) {
            height = result;
        } else if (flags & 4) {
            height = result / 2;
        }

        value = *(int *)((char *)ctx + 0x4C);
        if (*(int *)((char *)ctx + 0x44) > value) {
            value = *(int *)((char *)ctx + 0x44);
        }

        value = (height + value) - width;
        if (*max > value) {
            value = *max;
        }
        return value;
    }

    return *max;
}
#pragma pop
/* One of the 0x100 UI text styles of lbl_80490968, read from styles.val;
 * fn_8022CA2C(index) is the address of one.  Only the fields the text
 * measuring code uses are named here. */
struct UIStyle {
    unsigned char inUse;              /* 0x00 the style is loaded */
    unsigned char pad1[3];
    int *bitmapFont;                  /* 0x04 bitmap font, or 0 */
    int vectorFont;                   /* 0x08 outline font, or 0 */
    unsigned char padC[0x34 - 0xC];
    float fontSize;                   /* 0x34 font_size; under 1.0 the font's own height */
    int align;                        /* 0x38 UI_HALIGN_* | UI_VALIGN_* */
    unsigned char pad3C[0x44 - 0x3C];
    int padLeft;                      /* 0x44 text box padding, */
    int padTop;                       /* 0x48  the text is drawn inside */
    int padRight;                     /* 0x4C */
    int padBottom;                    /* 0x50 */
    unsigned char pad54[0x64 - 0x54];
    int picture;                      /* 0x64 texture drawn with the text, or 0 */
    int picture2;                     /* 0x68 animation drawn with it, or 0 */
};

/* UIStyle.align: the horizontal_alignment and vertical_alignment properties
 * of styles.val ("left", "right", "center" and "top", "middle", "baseline",
 * "bottom"). */
#define UI_HALIGN_LEFT     1
#define UI_HALIGN_RIGHT    2
#define UI_HALIGN_CENTER   4
#define UI_VALIGN_TOP      8
#define UI_VALIGN_MIDDLE   0x10
#define UI_VALIGN_BASELINE 0x20
#define UI_VALIGN_BOTTOM   0x40

#define UI_FONT_SIZE_MIN lbl_80563588 /* 1.0f: under it the font's own height is used */
#define UI_HALF          lbl_80563598 /* 0.5f */

#pragma push
#pragma processor 750
/* Height the text of a UI style takes up, for the style index and the text.
 *
 * The style (fn_8022CA2C) draws with a bitmap font, an outline font, or a
 * picture instead.  The height of one line is split by the style's vertical
 * alignment into the part above the baseline (top: the whole line, middle:
 * half of it, baseline: the ascent, bottom: nothing) and the part below it
 * (middle: half, baseline: the descent, bottom: the whole line); an outline
 * font of font_size under 1.0 keeps its own height, and is scaled by
 * font_size / that height otherwise.  The two parts, added to the larger of
 * the style's top and bottom padding, are the height of the text; the picture
 * the style draws is the floor of the result, and is all there is for a text
 * of 0.
 */
/* Return the pixel height of `text` drawn with UI style `styleIndex`: the larger of the style's picture height and the line height (font ascent/descent by vertical alignment plus the larger of top/bottom padding), or just the picture height when text is null. */ int UIStyle_getTextHeight(int styleIndex, const char *text) {
    struct UIStyle *style;
    int max;
    int above;
    int below;
    int value;
    int align;
    float scale;
    float size;
    float prod;

    style = fn_8022CA2C(styleIndex);
    max = 0;
    value = style->picture;
    if (value != 0) {
        max = stampGetHeight(value);
    } else if ((value = style->picture2) != 0) {
        max = ((int (*)(int))gxGetImageHeight)(value);
    }
    if (text != 0) {
        above = 0;
        if (style->bitmapFont != 0) {
            align = style->align;
            if (align & UI_VALIGN_TOP) {
                above = fn_801E4BA8(style->bitmapFont);
            } else if (align & UI_VALIGN_MIDDLE) {
                int t = fn_801E4BA8(style->bitmapFont);
                above = ((int)((unsigned int)t >> 31) + t) >> 1;
            } else {
                int t;
                if (align & UI_VALIGN_BASELINE) {
                    t = fn_801E4B48(style->bitmapFont);
                } else {
                    t = 0;
                }
                above = t;
            }
        }
        if (style->vectorFont != 0) {
            align = style->align;
            if (align & UI_VALIGN_TOP) {
                float f = style->fontSize;
                if (f < UI_FONT_SIZE_MIN) {
                    above = fn_80232B70(style->vectorFont);
                } else {
                    above = (int)f;
                }
            } else if (align & UI_VALIGN_MIDDLE) {
                float f = style->fontSize;
                if (f < UI_FONT_SIZE_MIN) {
                    int t = fn_80232B70(style->vectorFont);
                    above = ((int)((unsigned int)t >> 31) + t) >> 1;
                } else {
                    above = (int)(UI_HALF * f);
                }
            } else {
                above = 0;
            }
        }
        below = 0;
        if (style->bitmapFont != 0) {
            align = style->align;
            if (align & UI_VALIGN_MIDDLE) {
                int t = fn_801E4BA8(style->bitmapFont);
                below = ((int)((unsigned int)t >> 31) + t) >> 1;
            } else if (align & UI_VALIGN_BASELINE) {
                below = fn_801E4B00(style->bitmapFont);
            } else {
                int t;
                if (align & UI_VALIGN_BOTTOM) {
                    t = fn_801E4BA8(style->bitmapFont);
                } else {
                    t = 0;
                }
                below = t;
            }
        }
        if (style->vectorFont != 0) {
            size = style->fontSize;
            scale = UI_FONT_SIZE_MIN;
            if (size < scale) {
                scale = UI_FONT_SIZE_MIN;
            } else {
                scale = style->fontSize /
                    (float)fn_80232B70(style->vectorFont);
            }
            align = style->align;
            if (align & UI_VALIGN_MIDDLE) {
                prod = scale * (float)fn_80232B70(style->vectorFont);
                below = (int)(prod * UI_HALF);
            } else if (align & UI_VALIGN_BASELINE) {
                below = (int)(scale * (float)fn_80232B78(style->vectorFont));
            } else if (align & UI_VALIGN_BOTTOM) {
                below = (int)(scale * (float)fn_80232B70(style->vectorFont));
            } else {
                below = 0;
            }
        }
        value = style->padBottom;
        if (style->padTop > value) {
            value = style->padTop;
        }
        value = below + (value + above);
        return max > value ? max : value;
    }
    return max;
}
#pragma pop
/* Draws a UI style's picture/text at (x, y): renders the picture or animation, then draws the bitmap-font text lines with alignment and offsets unless a vector font is active. */
void fn_8022B91C(void *unused, int x, int y, char *text, unsigned int flagsArg) {
    extern int stampGetFrameCount(int);
    extern int fn_802C4C90(int, int, int, int, int);
    extern int gxGetImageFrameCount(void);
    extern int Abend_Panic(const char *, ...);
    extern void fn_801E4DBC(int, int, int, int, int, const char *, unsigned long);
    extern char *strchr(const char *, int);
    extern unsigned long strlen(const char *);
    extern const char lbl_8033FC08[];
    void *ctx;
    int width, mode, lines, row, lineLen, xoff, yoff, state;
    char *nl;

    ctx = fn_8022CA2C();
    mode = flagsArg & 1;
    if (*(int *)((char *)ctx + 0x64) != 0) {
        fn_802C4C90(*(int *)((char *)ctx + 0x64), x, y,
                    flagsArg % stampGetFrameCount(*(int *)((char *)ctx + 0x64)), 0);
    } else if ((state = *(int *)((char *)ctx + 0x68)) != 0) {
        ((int (*)(int))gxGetImageFrameCount)(state);
    }
    if (text == 0) return;
    if (*(int *)((char *)ctx + 8) != 0) return;
    Abend_Panic(lbl_8033FC08);
    width = fn_801E4BA8(*(int **)((char *)ctx + 4));
    lines = fn_8022AB94(text, 10) + 1;
    if (*(int *)((char *)ctx + 0x38) & 0x10) {
        y -= (int)((((unsigned int)(((int)lines - 1) * width) >> 31) +
                    ((lines - 1) * width))) >> 1;
    } else if (*(int *)((char *)ctx + 0x38) & 0x40) {
        y -= (lines - 1) * width;
    }
    row = 0;
    if (lines <= 0) return;
    goto check;
body:
    nl = strchr(text, 10);
    if (nl != 0) lineLen = nl - text;
    else lineLen = strlen(text);
    if (mode != 0) yoff = *(int *)((char *)ctx + 0x50);
    else yoff = *(int *)((char *)ctx + 0x48);
    if (mode != 0) xoff = *(int *)((char *)ctx + 0x4C);
    else xoff = *(int *)((char *)ctx + 0x44);
    fn_801E4DBC(*(int *)((char *)ctx + 4), 0, *(int *)((char *)ctx + 0x38),
                x + xoff, y + yoff, text, lineLen);
    y += width;
    nl = strchr(text, 10);
    text = nl;
    if (nl != 0) text = nl + 1;
    row++;
check:
    if (row < lines) goto body;
}
#pragma scheduling reset
#pragma dont_inline off
extern void fn_8022BD40(int, int, int, unsigned char, float, float, float, float, float, float);
void fn_8022BAD0(int context, int x, int y, int w, int h, int param5, int textOrSlot, int index, float scale, unsigned char flags) {
    /* Forwards integer text/layout arguments as floats to the main text draw helper. */
    fn_8022BD40(context, textOrSlot, index, flags,
                (float)x, (float)y, (float)w, (float)h, (float)param5, scale);
}

extern void fn_80230C30(float *, float *, int, int);
#pragma push
#pragma processor 750
void fn_8022BB60(float *arg0, float *arg1, float farg0, float farg1) {
    /* Converts integer screen coordinates to centered floats, then restores the fractional offsets. */
    fn_80230C30(arg0, arg1, (int)farg0, (int)farg1);
    *arg0 += farg0 - (float)(int)farg0;
    *arg1 -= farg1 - (float)(int)farg1;
}
#pragma pop
extern double lbl_805635A0;
#pragma opt_propagation off
#pragma opt_dead_assignments off
unsigned int fn_8022BC30(unsigned int arg0, unsigned int arg1, float farg0)
{
  float e = (float) ((unsigned char) arg1);
  float a = (float) ((unsigned char) arg0);
  float g = (float) ((unsigned char) ((arg1 >> 8) ^ 0));
  float c = (float) ((unsigned char) (arg0 >> ((((((16 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF)));
  float f = (float) ((unsigned char) (arg1 >> 16));
  float b = (float) ((unsigned char) (arg0 >> 8));
  float h = (float) ((unsigned char) (arg1 >> 24));
  int r2 = (int) (c + (farg0 * (g - c)));
  int r0 = (int) (a + (farg0 * ((0, e - a))));
  float d = (float) ((unsigned char) (arg0 >> 24));
  int r1 = (int) (b + (farg0 * (f - b)));
  int r3 = (int) (d + (farg0 * (h - d)));
  if (1)
  {
    return ((((r3 & 0xFF) << 24) | ((r2 & 0xFF) << 16)) | ((r1 & ((0, 0xFF))) << 8)) | (r0 & ((0, 0xFF)));
  }
}
extern double fn_8002EFB4(float arg0, double arg1);
extern float fn_8023659C(void);
extern float getPictureWidth(int arg0, int arg1);
extern float getPictureHeight(int arg0, int arg1);
extern int gxGetImageFrameCount();
extern int fn_80235FD8();
extern void gxDrawPictureAt();
extern void drawPictureScaled();
extern void fn_80232928();
extern void fn_80232930();
extern void fn_80232BA4();
extern void fn_80230924();
extern void fn_80230F78();
extern double sin();
extern void *lbl_8055E050;
extern float lbl_805635A8;
extern double lbl_805635B0;
extern float lbl_805635B8;
extern float lbl_805635BC;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8022BD40(int arg0, int i19arg, int arg2_, unsigned char i20_, float farg0, float farg1, float farg2, float farg3, float farg4, float farg5) {
    char sp38[0x400];
    float sp30;
    int sp2C;
    float sp28;
    float sp24;
    float sp20;
    float sp1C;
    float sp18;
    float sp14;
    float sp10;
    float spC;
    unsigned char sp8;
    float f0v;
    float f28v;
    float f2v;
    float f29v;
    float f30v;
    float f3v;
    float t0;
    int i18;
    int i21;
    int i22;
    int i23;
    int i24;
    int i25;
    int i28;
    int i20;
    int i26;
    int i30;
    int fl;
    int first;
    int mask;
    int v2;
    int v3;
    int lenarg;
    int tret;
    int arg2copy;
    void *base;
    char *i19;
    char *found;
    char *entry;
    (void)arg0;
    (void)farg5;
    f0v = farg0;
    f28v = farg1;
    i20 = i20_;
    i19 = (char *)i19arg;
    arg2copy = arg2_;
    base = fn_8022CA2C();
    i30 = arg2copy * 4;
    sp8 = 0xFF;
    entry = (char *)base + i30;
    sp30 = lbl_8056358C;
    i26 = arg2copy & 1;
    sp2C = *(int *)(entry + 0xC);
    if (i26 != 0) {
        first = *(int *)((char *)base + 0x40);
    } else {
        first = *(int *)((char *)base + 0x3C);
    }
    if (first == 1) {
        fn_80230F78(&sp8, &sp30, &sp2C, 0);
    }
    if (i26 != 0) {
        i28 = *(int *)((char *)base + 0x40);
    } else {
        i28 = *(int *)((char *)base + 0x3C);
    }
    i25 = -1;
    if ((unsigned int)(i28 - 5) <= 1U) {
        f2v = lbl_80563588;
        if ((float)fn_8002EFB4(lbl_805635A8 * fn_8023659C(), lbl_805635B0) < lbl_805635B8) {
            f2v = lbl_80563588 - (float)sin();
        }
        if (i26 != 0) {
            i25 = ((int (*)(unsigned int, unsigned int, float))fn_8022BC30)(*(int *)((char *)base + 0x18), *(int *)((char *)base + 0x10), f2v);
        } else {
            i25 = ((int (*)(unsigned int, unsigned int, float))fn_8022BC30)(*(int *)((char *)base + 0x14), *(int *)((char *)base + 0xC), f2v);
        }
    }
    if (*(int *)((char *)base + 0x68) != 0) {
        ((void (*)(float *, float *, float, float))fn_8022BB60)(&sp28, &sp24, f0v, f28v);
        gxDrawPictureAt(*(int *)((char *)base + 0x68), arg2copy % gxGetImageFrameCount(*(int *)((char *)base + 0x68)), sp28, sp24, lbl_8056358C);
    } else if (*(int *)((char *)base + 0x6C) != 0) {
        ((void (*)(float *, float *, float, float))fn_8022BB60)(&sp20, &sp1C, f0v, f28v);
        fl = *(int *)((char *)base + 0x38);
        i30 = arg2copy % fn_80235FD8(*(int *)((char *)base + 0x6C));
        if (fl & 0x10) {
            sp1C += getPictureHeight(*(int *)((char *)base + 0x6C), i30) * lbl_80563598;
        } else if (fl & 0x40) {
            sp1C += getPictureHeight(*(int *)((char *)base + 0x6C), i30);
        }
        if (fl & 4) {
            sp20 -= (*(float *)((char *)lbl_8055E050 + 0x70) + getPictureWidth(*(int *)((char *)base + 0x6C), i30)) * lbl_80563598;
        } else if ((fl & 2) && (i19 != 0) && (*(int *)((char *)base + 8) != 0)) {
            f29v = fn_8022CA40(base);
            sp20 -= ((float (*)(void *, char *, float))fn_8023293C)(*(void **)((char *)base + 8), i19, lbl_80563588) * f29v;
        }
        f29v = *(float *)((char *)lbl_8055E050 + 0x70) + getPictureWidth(*(int *)((char *)base + 0x6C), i30);
        f30v = getPictureHeight(*(int *)((char *)base + 0x6C), i30);
        drawPictureScaled(*(int *)((char *)base + 0x6C), i30, -1, sp20, sp1C, lbl_8056358C, f29v, f30v);
        if (i28 == 1) {
            f3v = lbl_80563598 * sp30;
            t0 = lbl_80563588 + sp30;
            mask = (sp8 << 24) | 0xFFFF;
            drawPictureScaled(*(int *)((char *)base + 0x6C), i30, mask, sp20 - (f3v * f29v), sp1C + (f3v * f30v), lbl_8056358C, t0 * f29v, t0 * f30v);
        }
        if (arg2copy == 1) {
            i18 = *(int *)((char *)base + 0x54);
            if (i18 >= 0) {
                f30v = getPictureHeight(*(int *)((char *)base + 0x6C), i30);
                f29v = getPictureWidth(*(int *)((char *)base + 0x6C), *(int *)((char *)base + 0x54));
                drawPictureScaled(*(int *)((char *)base + 0x6C), i18, -1, sp20 + getPictureWidth(*(int *)((char *)base + 0x6C), i30), sp1C, lbl_8056358C, f29v, f30v);
            }
        }
        if ((*(int *)((char *)base + 0x70) != 0) && (arg2copy == 1)) {
            i18 = *(int *)((char *)base + 0x58);
            f29v = getPictureHeight(*(int *)((char *)base + 0x70), i18);
            drawPictureScaled(*(int *)((char *)base + 0x70), i18, -1, sp20 + *(float *)((char *)base + 0x5C), sp1C + *(float *)((char *)base + 0x60), lbl_8056358C, getPictureWidth(*(int *)((char *)base + 0x70), *(int *)((char *)base + 0x58)), f29v);
        }
    } else if (i26 != 0) {
        ((void (*)(float *, float *, float, float))fn_8022BB60)(&sp18, &sp14, f0v, f28v);
        fl = *(int *)((char *)base + 0x38);
        if (fl & 0x10) {
            sp14 += farg4 * lbl_80563598;
        } else if (fl & 0x40) {
            sp14 += farg4;
        }
        if (fl & 4) {
            sp18 -= (*(float *)((char *)lbl_8055E050 + 0x70) + farg3) * lbl_80563598;
        } else if (fl & 2) {
            sp18 -= *(float *)((char *)lbl_8055E050 + 0x70) + farg3;
        }
        fn_80230924(*(int *)(entry + 0x20), sp18, sp14, sp18 + farg3, sp14 - farg4, farg2);
    }
    if ((i19 != 0) && (*(int *)((char *)base + 8) != 0)) {
        i30 = fn_80232B70(*(int *)((char *)base + 8));
        tret = fn_8022AB94(i19, 0xA);
        fl = *(int *)((char *)base + 0x38);
        i24 = tret + 1;
        if (fl & 0x10) {
            f28v -= I2F(((i24 - 1) * i30) / 2);
        } else if (fl & 0x40) {
            f28v -= I2F((i24 - 1) * i30);
        }
        i23 = 0;
        while (i23 < i24) {
            found = strchr(i19, 0xA);
            if (found != 0) {
                i21 = found - i19;
            } else {
                i21 = strlen(i19);
            }
            strncpy(sp38, i19, i21);
            sp38[i21] = 0;
            if (i26 != 0) {
                v2 = *(int *)((char *)base + 0x4C);
            } else {
                v2 = *(int *)((char *)base + 0x44);
            }
            if (i26 != 0) {
                v3 = *(int *)((char *)base + 0x50);
            } else {
                v3 = *(int *)((char *)base + 0x48);
            }
            ((void (*)(float *, float *, float, float))fn_8022BB60)(&sp10, &spC, f0v + (float)v2, f28v + (float)v3);
            fl = *(int *)((char *)base + 0x38);
            i22 = 0;
            lenarg = sp2C;
            if (fl & 1) {
                i22 = 1;
            }
            if (fl & 4) {
                i22 |= 4;
            }
            if (fl & 2) {
                i22 |= 2;
            }
            if (fl & 8) {
                i22 |= 8;
            }
            if (fl & 0x10) {
                i22 |= 0x10;
            }
            if (fl & 0x20) {
                i22 |= 0x20;
            }
            if (fl & 0x40) {
                i22 |= 0x40;
            }
            switch (i28) {
            case 2:
                i20 = 1;
                f3v = fn_8022CA40(base);
                if (i20 != 0) {
                    fn_80232BA4(sp38, *(int *)((char *)base + 8), -427819008, i22, lbl_805635BC + sp10, spC - lbl_805635BC, f3v, lbl_8056358C, lbl_80563588);
                }
                fn_80232BA4(sp38, *(int *)((char *)base + 8), i21, i22, sp10, spC, f3v, lbl_8056358C, lbl_80563588);
                break;
            case 4:
            case 1:
                fn_80232BA4(sp38, *(int *)((char *)base + 8), sp2C, i22, sp10, spC, fn_8022CA40(base), lbl_8056358C, lbl_80563588);
                break;
            case 5:
                fn_80232928(-1);
                fn_80232BA4(sp38, *(int *)((char *)base + 8), i25, i22, sp10, spC, fn_8022CA40(base), lbl_8056358C, lbl_80563588);
                if (i28 == 5) {
                    fn_80232930();
                }
                break;
            case 6:
                fn_80232BA4(sp38, *(int *)((char *)base + 8), i25, i22, sp10, spC, fn_8022CA40(base), lbl_8056358C, lbl_80563588);
                break;
            default:
                f3v = fn_8022CA40(base);
                fn_80232BA4(sp38, *(int *)((char *)base + 8), i21, i22, sp10, spC, f3v, lbl_8056358C, lbl_80563588);
                break;
            }
            f28v += (float)i30;
            found = strchr(i19, 0xA);
            i19 = found;
            if (found == 0) {
                break;
            }
            i19 = found + 1;
            i23++;
        }
    }
}
#pragma cplusplus on
/* Load UI text style overrides from the style config: for each "style" node, build a 0x58-byte descriptor from the lbl_802F9F58 defaults plus the node's properties and install it in the 0x100-entry style table. */ void loadTextStyleOverrides(void) {
    /* Load UI text style overrides from the style config: for each "style" node,
     * fill a 0x58-byte descriptor from the lbl_802F9F58 defaults plus the node's
     * properties and install it in the 0x100-entry style table via fn_8022A858. */
    struct ConfigNode {
        virtual char *getName();
        virtual int has(const char *);
        virtual void *u2();
        virtual char *getStr(const char *);
        virtual int getIntDef(const char *, int);
        virtual int getInt(const char *);
        virtual int get8(const char *, int);
        virtual void *u7();
        virtual float getFloat(const char *, float);
        virtual void *u9();  virtual void *u10(); virtual void *u11(); virtual void *u12();
        virtual void *u13(); virtual void *u14(); virtual void *u15(); virtual void *u16();
        virtual void *u17(); virtual void *u18(); virtual void *u19(); virtual void *u20();
        virtual void *getPtr(const char *);
    };
    struct ConfigNodeList {
        virtual void *l0();
        virtual void *fetch(int);
    };
    #define StyleTag     lbl_8055B8C4 /* "style" */
    #define AlignLeft    lbl_8055B8CC /* "left" */
    #define AlignRight   lbl_8055B8D4 /* "right" */
    #define AlignCenter  lbl_8055B8DC /* "center" */
    #define AlignTop     lbl_8055B8E4 /* "top" */
    #define AlignMiddle  lbl_8055B8E8 /* "middle" */
    #define AlignBottom  lbl_8055B8F0 /* "bottom" */
    #define ShadowOff    lbl_8055B8F8 /* "off" */
    #define ShadowOn     lbl_8055B8FC /* "on" */
    #define StampProp    lbl_8055B900 /* "stamp" */
    #define ExtArtProp   lbl_8055B908 /* "ext_art" */
    #define ButtonProp   lbl_8055B910 /* "button" */
    Cfg58 styleTemplate;
    Cfg58 styleDesc;
    void* nodeList;
    ConfigNode* node;
    int i;
    int styleIndex;
    unsigned hAlign;
    int vAlign;
    char* strBase;

    strBase = lbl_8033FBE8;
    styleTemplate = *(Cfg58*)&lbl_802F9F58;
    styleTemplate.w[3] = 0xffd6003c;
    styleTemplate.w[4] = 0xffd6003c;
    styleTemplate.w[5] = 0xff2dc82d;
    styleTemplate.w[6] = 0xff2dc82d;
    styleTemplate.w[10] = 0xff2d2dc8;
    styleTemplate.w[11] = 0xff2d2dc8;
    styleTemplate.w[12] = 0xffd6003c;
    styleTemplate.w[13] = 0xffd6003c;
    nodeList = fn_80131810(strBase + 0x64, 0xff2dc82d, 0xffd6003c);
    if (nodeList) {
        for (i = 0; (node = (ConfigNode*)((ConfigNodeList*)nodeList)->fetch(i)) != 0; i++) {
            if (stricmp(node->getName(), StyleTag) != 0) {
                continue;
            }
            if (node->has(strBase + 0x70) != 0) {
                styleIndex = node->getInt(strBase + 0x70);
            } else {
                if (node->has(strBase + 0x7c) == 0) {
                    fn_802E30C8(strBase + 0x88);
                    continue;
                } else {
                    char *s = node->getStr(strBase + 0x7c);
                    styleIndex = fn_8022CC8C(s);
                }
            }
            if (styleIndex < 0 || styleIndex >= 0x100) {
                fn_802E30C8(strBase + 0xb4, node->getIntDef(strBase + 0x7c, (int)(strBase + 0xe4)));
                continue;
            }
            styleDesc = styleTemplate;
            styleDesc.w[0] = node->getIntDef(strBase + 0xf0, styleDesc.w[0]);
            *(float*)&styleDesc.w[1] = node->getFloat(strBase + 0xfc, *(float*)&styleDesc.w[1]);
            hAlign = 1;
            if (node->has(strBase + 0x108) != 0) {
                char *s = node->getStr(strBase + 0x108);
                if (stricmp(s, AlignLeft) == 0) {
                    hAlign = 1;
                } else if (stricmp(s, AlignRight) == 0) {
                    hAlign = 2;
                } else if (stricmp(s, AlignCenter) == 0) {
                    hAlign = 4;
                } else {
                    fn_802E30C8(strBase + 0x120, s);
                }
            }
            vAlign = 8;
            if (node->has(strBase + 0x154) != 0) {
                char *s = node->getStr(strBase + 0x154);
                if (stricmp(s, AlignTop) == 0) {
                    vAlign = 8;
                } else if (stricmp(s, AlignMiddle) == 0) {
                    vAlign = 0x10;
                } else if (stricmp(s, strBase + 0x168) == 0) {
                    vAlign = 0x20;
                } else if (stricmp(s, AlignBottom) == 0) {
                    vAlign = 0x40;
                } else {
                    fn_802E30C8(strBase + 0x174, s);
                }
            }
            styleDesc.w[2] = hAlign | vAlign;
            readTextEffectProps((int*)&styleDesc.w[3], node->getPtr(ShadowOff));
            readTextEffectProps((int*)&styleDesc.w[10], node->getPtr(ShadowOn));
            if (node->has(StampProp) != 0) {
                styleDesc.w[17] = (int)node->getStr(StampProp);
            }
            styleDesc.w[21] = node->get8(ExtArtProp, styleDesc.w[21]);
            styleDesc.w[18] = node->get8(ButtonProp, styleDesc.w[18]);
            *(float*)&styleDesc.w[19] = node->getFloat(strBase + 0x1a8, *(float*)&styleDesc.w[19]);
            *(float*)&styleDesc.w[20] = node->getFloat(strBase + 0x1b4, *(float*)&styleDesc.w[20]);
            ((void (*)(int, void*))fn_8022A858)(styleIndex, &styleDesc);
        }
        fn_80131818(nodeList);
    }
}
#pragma cplusplus reset
void fn_8022C9D0(void) {
    /* Iterate all 0x100 style entries in lbl_80490968 (0x74 bytes each) and destroy/reset
     * any active one (byte 0 set) via fn_8022A8E4. */
    unsigned char *p = (unsigned char *)lbl_80490968;
    int i = 0;
    do {
        if (*p != 0) {
            fn_8022A8E4(i);
        }
        i++;
        p += 0x74;
    } while (i < 0x100);
}

/* Return a pointer to the 0x74-byte UI text style record at the given index in lbl_80490968. */
void *fn_8022CA2C(int styleIndex) {
    return lbl_80490968 + styleIndex * 0x74;
}

/* Returns 1.0 if the stored value is below 1.0, otherwise scales it by the byte count from the related object. */
float fn_8022CA40(void *obj) {
    if (*(float *)((char *)obj + 0x34) < 1.0f)
        return 1.0f;
    else {
        int count = fn_80232B70(*(int *)((char *)obj + 8));
        return *(float *)((char *)obj + 0x34) / (float)count;
    }
}

void fn_8022CAA8(void *arg0, void *arg1) {
    extern int loadFontTexture(const char *);
    extern unsigned int fn_8022A834(unsigned int);
    extern int gxGetImageArt(const char *);
    extern int ArtSetGet(const char *);
    extern int loadStamp(const char *);
    extern char *strstr(const char *, const char *);
    extern char lbl_8033FC40[];
    unsigned char *src;
    unsigned char *dest;
    char *name;
    char *resourceName;
    int converted;
    int src48, src54, src40, src3C, src24, src20, src38, src1C, src8;
    float src4, src50, src4C;

    /* Convert/init a UI/text record from a source descriptor: resolve font/texture ids and copy/normalize fields. */
    src = (unsigned char *)arg1;
    dest = (unsigned char *)arg0;
    dest[0] = 1;
    *(int *)(dest + 4) = 0;
    *(int *)(dest + 8) = 0;
    name = *(char **)src;
    if (strstr(name, lbl_8055B918) != 0) {
        *(int *)(dest + 8) = loadFontTexture(lbl_8033FC40);
    }
    name = *(char **)src;
    if (strstr(name, lbl_8055B920) != 0) {
        *(int *)(dest + 8) = loadFontTexture(name);
    }
    src4 = *(float *)(src + 4);
    converted = *(int *)(src + 0x0C);
    *(float *)(dest + 0x34) = src4;
    *(int *)(dest + 0x0C) = fn_8022A834(converted);
    *(int *)(dest + 0x10) = fn_8022A834(*(int *)(src + 0x28));
    *(int *)(dest + 0x14) = fn_8022A834(*(int *)(src + 0x10));
    *(int *)(dest + 0x18) = fn_8022A834(*(int *)(src + 0x2C));
    *(int *)(dest + 0x1C) = fn_8022A834(*(int *)(src + 0x1C));
    *(int *)(dest + 0x20) = fn_8022A834(*(int *)(src + 0x14));
    *(int *)(dest + 0x24) = fn_8022A834(*(int *)(src + 0x30));
    *(int *)(dest + 0x28) = fn_8022A834(*(int *)(src + 0x18));
    *(int *)(dest + 0x2C) = fn_8022A834(*(int *)(src + 0x34));
    converted = fn_8022A834(*(int *)(src + 0x14));

    resourceName = *(char **)(src + 0x44);
    src8 = *(int *)(src + 8);
    src1C = *(int *)(src + 0x1C);
    src38 = *(int *)(src + 0x38);
    src20 = *(int *)(src + 0x20);
    src24 = *(int *)(src + 0x24);
    src3C = *(int *)(src + 0x3C);
    src40 = *(int *)(src + 0x40);
    src54 = *(int *)(src + 0x54);
    src48 = *(int *)(src + 0x48);
    src4C = *(float *)(src + 0x4C);
    src50 = *(float *)(src + 0x50);
    *(int *)(dest + 0x30) = converted;
    *(int *)(dest + 0x38) = src8;
    *(int *)(dest + 0x3C) = src1C;
    *(int *)(dest + 0x40) = src38;
    *(int *)(dest + 0x44) = src20;
    *(int *)(dest + 0x48) = src24;
    *(int *)(dest + 0x4C) = src3C;
    *(int *)(dest + 0x50) = src40;
    *(int *)(dest + 0x54) = src54;
    *(int *)(dest + 0x58) = src48;
    *(float *)(dest + 0x5C) = src4C;
    *(float *)(dest + 0x60) = src50;
    *(int *)(dest + 0x64) = 0;
    *(int *)(dest + 0x68) = 0;
    *(int *)(dest + 0x6C) = 0;
    *(int *)(dest + 0x70) = 0;

    if (resourceName != 0) {
        if (fn_8022A7D4(resourceName) != 0) {
            *(int *)(dest + 0x68) = gxGetImageArt(resourceName);
        } else if (fn_8022A804(resourceName) != 0) {
            *(int *)(dest + 0x6C) = ArtSetGet(resourceName);
        } else {
            *(int *)(dest + 0x64) = loadStamp(resourceName);
        }
    }
    *(int *)(dest + 0x58) = -1;
}

extern double lbl_80563590;
extern int fn_80232B70(int);
extern char lbl_8033FF98[];
extern int stricmp(const char *, const char *);
/* Look up a UI/style name in the style table (name/id pairs) and return its id,
   or 0x1A if the name is not found. */
int fn_8022CC8C(const char *styleName) {
    char *entry;
    unsigned int index;

    entry = lbl_8033FF98;
    index = 0;
    for (; index < 0x1B; index++, entry += 8) {
        if (stricmp(styleName, *(const char **)(entry + 4)) == 0)
            return *(int *)(lbl_8033FF98 + index * 8);
    }
    return 0x1A;
}

__declspec(section ".sdata") extern char lbl_8055B928[];
extern char lbl_80340070[];
extern int sscanf(const char *, const char *, ...);
int parseStyleColor(char *arg0) {
    extern int __rlwimi(int, int, int, int, int);
    volatile int sp18;
    int sp14;
    int sp10;
    int spC;
    int sp8;
    int result;
    int high;
    unsigned low;

    if (sscanf(arg0, lbl_8055B928, (int *)&sp18) == 1)
        return sp18;

    result = sscanf(arg0, lbl_80340070, &sp14, &sp10, &spC, &sp8);
    if (result == 3) {
        high = sp14;
        low = (unsigned)sp10;
        high = (high & 0xFF) << 16;
        low = (low & 0xFF) << 8;
        low = (unsigned)__rlwimi((int)low, spC, 0, 24, 31);
        high |= 0xFF000000;
        result = (int)(low | (unsigned)high);
        sp18 = result;
        return result;
    }
    if (result == 4) {
        result = ((sp14 & 0xFF) << 24) | ((sp10 & 0xFF) << 16) |
                 ((spC & 0xFF) << 8) | (sp8 & 0xFF);
        return result;
    }
    result = 0xFFFF00FF;
    sp18 = result;
    return result;
}

__declspec(section ".sdata") extern char textEffectNormal[];
__declspec(section ".sdata") extern char lbl_8055B938[];
__declspec(section ".sdata") extern char lbl_8055B940[];
__declspec(section ".sdata") extern char lbl_8055B948[];
__declspec(section ".sdata") extern char lbl_8055B950[];
extern char lbl_8033FBE8[], textEffectNormal[], lbl_8055B938[], lbl_8055B940[], lbl_8055B948[], lbl_8055B950[];
#pragma cplusplus on
void readTextEffectProps(int *d, void *o) {
    /* Reads a record of seven int attributes out of an XML node into d[0..6]:
     * four numeric attributes (d[0..3]) via parseStyleColor, a named enum attribute
     * mapped by name (d[4]), and a "%d %d" pair (d[5..6]).  Attribute keys come
     * from the string table lbl_8033FBE8. */
    class Xml {
    public:
        virtual void v0();
        virtual int has(const char *);
        virtual void v2();
        virtual char *get(const char *);
    };
    register const char *base = lbl_8033FBE8;
    register char *s;
    Xml *xo = (Xml *)o;
    if (!o)
        return;
    if (xo->has(base + 0x498))
        d[0] = parseStyleColor(xo->get(base + 0x498));
    if (xo->has(base + 0x4A4))
        d[1] = parseStyleColor(xo->get(base + 0x4A4));
    if (xo->has(base + 0x4BC))
        d[2] = parseStyleColor(xo->get(base + 0x4BC));
    if (xo->has(base + 0x4C8))
        d[3] = parseStyleColor(xo->get(base + 0x4C8));
    if (xo->has(base + 0x4E0)) {
        s = xo->get(base + 0x4E0);
        if (stricmp(s, textEffectNormal) == 0)
            d[4] = 0;
        else if (stricmp(s, lbl_8055B938) == 0)
            d[4] = 4;
        else if (stricmp(s, lbl_8055B940) == 0)
            d[4] = 2;
        else if (stricmp(s, base + 0x4EC) == 0)
            d[4] = 1;
        else if (stricmp(s, base + 0x4F8) == 0)
            d[4] = 5;
        else if (stricmp(s, base + 0x504) == 0)
            d[4] = 6;
        else
            d[4] = parseStyleColor(s);
    }
    if (xo->has(lbl_8055B948))
        sscanf(xo->get(lbl_8055B948), lbl_8055B950, &d[5], &d[6]);
}
#pragma cplusplus off
