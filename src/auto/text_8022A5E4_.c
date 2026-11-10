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
extern void fn_8022CDE4(int*, void*);
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


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

__declspec(section ".sdata") extern char lbl_8055B8B0[];
extern char lbl_80490968[];
extern char *strstr(const char *, const char *);
extern void fn_8022C9D0(void);
extern int fn_80232B70(int);
extern void fn_8022A8E4(int);
extern double lbl_80563590;
extern float lbl_80563598;
extern int fn_802C4EFC(int);
extern int fn_802C5220(int);
#define I2F(x) ((float)((double)((x) ^ 0x80000000) - lbl_80563590))
extern int fn_802C4EE4(int);
extern int fn_802C51C0();
extern unsigned long strlen(const char *);
extern void fn_802C4F2C(int, int *, int *);
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
    extern char lbl_80490968[];
    extern unsigned char lbl_80497D68[];
    extern void *memset(void *, int, unsigned int);
    extern void fn_8022C520(void);
    struct Record {
        unsigned char b0;
        unsigned int w4, w8, wC, w10, w14, w18, w1C, w20, w24, w28, w2C, w30;
        float f34;
        unsigned int w38, w3C, w40, w44, w48, w4C, w50, w54, w58;
        float f5C, f60;
        unsigned int w64, w68, w6C, w70;
    };
    struct Record *src;
    struct Record *out;
    unsigned char b0;
    unsigned int v4, v8, vC, v10, v14, v18, v1C, v20, v24, v28, v2C, v30;
    float v34;
    unsigned int v3C, v40, v44, v48, v4C, v50, v54, v58;
    float v5C, v60;
    unsigned int v64, v68, v6C, v70;
    unsigned int i;

    memset(lbl_80497D68, 0, 0x74);
    src = (struct Record *)lbl_80497D68;
    src->w38 = 9;
    b0 = src->b0;
    vC = src->wC;
    v10 = src->w10;
    v14 = src->w14;
    v18 = src->w18;
    v1C = src->w1C;
    v20 = src->w20;
    v24 = src->w24;
    v28 = src->w28;
    v2C = src->w2C;
    v30 = src->w30;
    v4 = src->w4;
    v8 = src->w8;
    v34 = src->f34;
    v3C = src->w3C;
    v40 = src->w40;
    v44 = src->w44;
    v48 = src->w48;
    v4C = src->w4C;
    v50 = src->w50;
    v54 = src->w54;
    v58 = src->w58;
    v5C = src->f5C;
    v60 = src->f60;
    v64 = src->w64;
    v68 = src->w68;
    v6C = src->w6C;
    v70 = src->w70;
    out = (struct Record *)lbl_80490968;
    for (i = 0; i < 0x80; ++i) {
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
    fn_8022C520();
}

void fn_8022A7D0(void) {
    fn_8022C9D0();
}

#pragma push
#pragma dont_inline on
int fn_8022A7D4(const char *arg0) {
    return strstr(arg0, lbl_8055B8B0) != 0;
}

int fn_8022A804(const char *arg0) {
    return strstr(arg0, lbl_8055B8B8) != 0;
}
#pragma pop

#pragma push
#pragma dont_inline on
extern int __rlwimi(int, int, int, int, int);
unsigned int fn_8022A834(unsigned int arg0) {
    unsigned int var_r0 = arg0 >> 24;
    if (var_r0 < 0x20 && (int)var_r0 != 0) {
        var_r0 = 0xFF;
    }
    return __rlwimi(arg0 & 0xFFFFFF, var_r0, 24, 0, 7);
}
#pragma pop

void fn_8022A858(int arg0) {
    fn_8022CAA8(lbl_80490968 + arg0 * 0x74);
}

#pragma dont_inline on
#pragma scheduling invalid_target
int fn_8022A86C(int arg0) {
    extern int fn_802E317C(const char *, ...);
    unsigned char *p = (unsigned char *)lbl_80490968;
    int i = 0;
    int count;

    for (count = 0x100; count != 0; count--) {
        if (*p == 0) {
            fn_8022A858(i);
            return i;
        }
        p += 0x74;
        i++;
    }
    fn_802E317C(lbl_8033FBE8, arg0);
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
    register unsigned int offset;
    unsigned char *entry;
    register const unsigned char *source;
    register unsigned char *destination;
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
    entry[0] = *(const unsigned char *)lbl_80497D68;
    source = (const unsigned char *)lbl_80497D68;
    destination = (unsigned char *)lbl_80490968 + arg0 * 0x74;
    a = *(const unsigned int *)(source + 4); b = *(const unsigned int *)(source + 8);
    *(unsigned int *)(destination + 4) = a; a = *(const unsigned int *)(source + 0xc);
    *(unsigned int *)(destination + 8) = b; b = *(const unsigned int *)(source + 0x10);
    *(unsigned int *)(destination + 0xc) = a; a = *(const unsigned int *)(source + 0x14);
    *(unsigned int *)(destination + 0x10) = b; b = *(const unsigned int *)(source + 0x18);
    *(unsigned int *)(destination + 0x14) = a; a = *(const unsigned int *)(source + 0x1c);
    *(unsigned int *)(destination + 0x18) = b; b = *(const unsigned int *)(source + 0x20);
    *(unsigned int *)(destination + 0x1c) = a; a = *(const unsigned int *)(source + 0x24);
    *(unsigned int *)(destination + 0x20) = b; b = *(const unsigned int *)(source + 0x28);
    *(unsigned int *)(destination + 0x24) = a; a = *(const unsigned int *)(source + 0x2c);
    *(unsigned int *)(destination + 0x28) = b; b = *(const unsigned int *)(source + 0x30);
    *(unsigned int *)(destination + 0x2c) = a;
    f0 = *(const float *)(source + 0x34);
    *(unsigned int *)(destination + 0x30) = b;
    *(float *)(destination + 0x34) = f0;
    a = *(const unsigned int *)(source + 0x38); b = *(const unsigned int *)(source + 0x3c);
    *(unsigned int *)(destination + 0x38) = a; a = *(const unsigned int *)(source + 0x40);
    *(unsigned int *)(destination + 0x3c) = b; b = *(const unsigned int *)(source + 0x44);
    *(unsigned int *)(destination + 0x40) = a; a = *(const unsigned int *)(source + 0x48);
    *(unsigned int *)(destination + 0x44) = b; b = *(const unsigned int *)(source + 0x4c);
    *(unsigned int *)(destination + 0x48) = a; a = *(const unsigned int *)(source + 0x50);
    *(unsigned int *)(destination + 0x4c) = b; b = *(const unsigned int *)(source + 0x54);
    *(unsigned int *)(destination + 0x50) = a; a = *(const unsigned int *)(source + 0x58);
    *(unsigned int *)(destination + 0x54) = b;
    f1 = *(const float *)(source + 0x5c);
    *(unsigned int *)(destination + 0x58) = a;
    f0 = *(const float *)(source + 0x60);
    *(float *)(destination + 0x5c) = f1;
    a = *(const unsigned int *)(source + 0x64);
    *(float *)(destination + 0x60) = f0;
    b = *(const unsigned int *)(source + 0x68);
    *(unsigned int *)(destination + 0x64) = a; a = *(const unsigned int *)(source + 0x6c);
    *(unsigned int *)(destination + 0x68) = b;
    *(unsigned int *)(destination + 0x6c) = a;
    *(unsigned int *)(destination + 0x70) = *(const unsigned int *)(source + 0x70);
    entry[0] = 0;
}
#pragma scheduling reset
extern void *fn_8022CA2C();
int fn_8022AA84(void) {
    return *(int *)((char *)fn_8022CA2C() + 0x38);
}

extern float fn_8022CA40(void *);
extern float lbl_8056358C;
#pragma push
#pragma processor 750
float fn_8022AAA8(void *unused, char *arg1) {
    void *p = fn_8022CA2C();
    if (*(int *)((char *)p + 8) != 0) {
        float scale = fn_8022CA40(p);
        float result = ((float (*)(void *, char *, float))fn_8023293C)(*(void **)((char *)p + 8), arg1, lbl_80563588);
        return result * scale;
    }
    return lbl_8056358C;
}
#pragma pop
int fn_8022AB18(int unused, int arg1, int arg2) {
    void *p = fn_8022CA2C();
    if (arg1 == 0) {
        if (arg2 == 2) return *(int *)((char *)p + 0x44);
        return *(int *)((char *)p + 0x4c);
    }
    if (arg1 == 1) {
        if (arg2 == 2) return *(int *)((char *)p + 0x48);
        return *(int *)((char *)p + 0x50);
    }
    return 0;
}

#pragma push
#pragma dont_inline on
int fn_8022AB94(const char *arg0, char arg1) {
    int count = 0;
    while (*arg0 != 0) {
        if (*arg0 == arg1) count++;
        arg0++;
    }
    return count;
}
#pragma pop

#pragma scheduling invalid_target
void fn_8022ABC8(void *arg0, const char *arg1, int arg2) {
    char buffer[0x800];
    strncpy(buffer, arg1, arg2);
    buffer[arg2] = 0;
    fn_8023293C(arg0, buffer, lbl_80563588);
}
#pragma scheduling on
extern void fn_8022ACFC(int, char *, float *, float *, float *, float *, float, float);
__declspec(section ".sdata2") extern double lbl_80563590;
void fn_8022AC1C(int unused0, char *unused1, int arg2, int arg3, int *arg4, int *arg5, int *arg6, int *arg7) {
    float a, b, c, d;
    float x = (float)((double)(arg2 ^ 0x80000000) - lbl_80563590);
    float y = (float)((double)(arg3 ^ 0x80000000) - lbl_80563590);
    fn_8022ACFC(unused0, unused1, &a, &b, &c, &d, x, y);
    *arg4 = (int)a;
    *arg5 = (int)b;
    *arg6 = (int)c;
    *arg7 = (int)d;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8022ACFC(int unused, char *str, float *outMinX, float *outMinY, float *outMaxX, float *outMaxY, float x0, float y0) {
    char *p = fn_8022CA2C();
    int n, i, g, len;
    float wid, hgt, one;
    float minX = x0, minY = y0, maxX = x0, maxY = y0;
    int h = *(int *)(p + 0x64);
    if (h != 0) {
        int a, b, hh;
        float t;
        fn_802C4F2C(h, &a, &b);
        n = fn_802C4EE4(*(int *)(p + 0x64));
        hh = fn_802C4EFC(*(int *)(p + 0x64));
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
        maxX = x0 + (float)fn_802C51C0(*(int *)(p + 0x68));
        if (x0 > maxX) maxX = x0;
        t = y0 + (float)fn_802C5220(*(int *)(p + 0x68));
        maxY = (y0 > t) ? maxY : t;
    }
    if (str != 0) {
        float w = lbl_8056358C, ax, ay;
        n = fn_8022AB94(str, 10) + 1;
        if (*(int *)(p + 4) != 0) {
            w = (float)n * (float)fn_801E4BA8(*(int **)(p + 4));
        }
        g = *(int *)(p + 8);
        if (g != 0) {
            if (*(float *)(p + 0x34) < lbl_80563588) {
                w = (float)n * (float)fn_80232B70(g);
            } else {
                float d = (float)fn_80232B70(g);
                w = (*(float *)(p + 0x34) * (float)(n * fn_80232B70(g))) / d;
            }
        }
        hgt = w;
        wid = lbl_8056358C;
        one = lbl_80563588;
        for (i = 0; i < n; i++) {
            char *nl = strchr(str, 10);
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
                    float d = (float)fn_80232B70(*(int *)(p + 8));
                    v = (*(float *)(p + 0x34) * ((float (*)(void *, char *, int))fn_8022ABC8)(*(void **)(p + 8), str, len)) / d;
                    wid = (wid > v) ? wid : v;
                }
            }
            str = strchr(str, 10);
            if (str != 0) str = str + 1;
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
        {
            int lo, hi, mn, mx;
            float t;
            wid += lbl_80563598 * (float)(fn_801E4A6C(*(int **)(p + 4), lbl_8055B8C0) + 1);
            lo = *(int *)(p + 0x44);
            hi = *(int *)(p + 0x4c);
            mn = lo; mx = lo;
            if (hi < lo) mn = hi;
            t = x0 + ax + (float)mn;
            minX = (minX < t) ? minX : t;
            t = wid + (x0 + ax);
            if (hi > lo) mx = hi;
            t = t + (float)mx;
            maxX = (maxX > t) ? maxX : t;
            lo = *(int *)(p + 0x48);
            hi = *(int *)(p + 0x50);
            mn = lo; mx = lo;
            if (hi < lo) mn = hi;
            t = y0 + ay + (float)mn;
            minY = (minY < t) ? minY : t;
            t = hgt + (y0 + ay);
            if (hi > lo) mx = hi;
            t = t + (float)mx;
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
int fn_8022B2D4(int arg0, const char *arg1, int arg2, int arg3) {
    int bestIndex = 0, best = -1, i = 0;
    goto check;
body: {
        int x, y;
        int cost;
        fn_8022B390((const char *)arg0, arg1, i, &x, &y);
        cost = fn_800241CC(x - arg2) + fn_800241CC(y - arg3);
        if (best < 0 || cost < best) {
            bestIndex = i;
            best = cost;
        }
        i = i + 1;
    }
check:
    if (i == 0) goto body;
    if ((signed char)arg1[i - 1] != 0) goto body;
    return bestIndex;
}

extern int fn_801E4A6C(int *, const char *);
extern int fn_801E4BA8(int *);
void fn_8022B390(const char *arg0, const char *arg1, int arg2, int *arg3, int *arg4) {
    union LocalChar {
        short half;
        char byte;
    } sp8;
    void *p;
    int x;
    int y;
    int i;
    p = fn_8022CA2C();
    sp8.half = 0;
    i = 0;
    x = *(int *)((char *)p + 0x44);
    y = *(int *)((char *)p + 0x48);
    while (*arg1 != 0 && i < arg2) {
        if (*arg1 != 10) {
            sp8.byte = *arg1;
            if (*(int *)((char *)p + 8) != 0) {
                x += (int)((float (*)(void *, char *, float))fn_8023293C)(*(void **)((char *)p + 8), &sp8.byte, lbl_80563588);
            } else if (*(int *)((char *)p + 4) != 0) {
                x += fn_801E4A6C(*(int **)((char *)p + 4), &sp8.byte);
            }
        } else {
            if (*(int *)((char *)p + 8) != 0) {
                y += fn_80232B70(*(int *)((char *)p + 8));
            } else if (*(int *)((char *)p + 4) != 0) {
                y += fn_801E4BA8(*(int **)((char *)p + 4));
            }
            x = *(int *)((char *)p + 0x44);
        }
        i++;
        arg1++;
    }
    *arg3 = x;
    *arg4 = y;
}

#pragma scheduling invalid_target
int fn_8022B498(int unused, const char *arg1) {
    int max;
    void *ctx;
    int value;

    ctx = fn_8022CA2C();
    value = *(int *)((char *)ctx + 0x64);
    max = 0;
    if (value != 0) {
        max = fn_802C4EE4(value);
    } else if (*(int *)((char *)ctx + 0x68) != 0) {
        max = fn_802C51C0();
    }
    if (arg1 != 0) {
        int width = 0;
        int height = 0;
        int result = 0;
        int *font = *(int **)((char *)ctx + 4);
        int flags;

        if (font != 0) {
            result = fn_801E4A6C(font, arg1);
        }
        if (*(void **)((char *)ctx + 8) != 0) {
            float scale = lbl_80563588;
            if (*(float *)((char *)ctx + 0x34) >= scale) {
                scale = *(float *)((char *)ctx + 0x34) /
                    (float)fn_80232B70(*(int *)((char *)ctx + 8));
            }
            result = (int)(scale * ((float (*)(void *, char *, float))fn_8023293C)(
                                      *(void **)((char *)ctx + 8), (char *)arg1, lbl_80563588));
        }
        flags = *(int *)((char *)ctx + 0x38);
        if (flags & 2) {
            width = -result;
        } else if (flags & 4) {
            width = (int)((-result) + (int)((unsigned int)-result >> 31)) >> 1;
        }
        if (flags & 1) {
            height = result;
        } else if (flags & 4) {
            height = (int)(result + (int)((unsigned int)result >> 31)) >> 1;
        }
        value = *(int *)((char *)ctx + 0x4C);
        if (*(int *)((char *)ctx + 0x44) > value) {
            value = *(int *)((char *)ctx + 0x44);
        }
        value = (height + value) - width;
        if (max > value) return max;
        return value;
    }
    return max;
}

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
int fn_8022B620(int styleIndex, const char *text) {
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
        max = fn_802C4EFC(value);
    } else if ((value = style->picture2) != 0) {
        max = ((int (*)(int))fn_802C5220)(value);
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
void fn_8022B91C(void *unused, int x, int y, char *text, unsigned int flagsArg) {
    extern int fn_802C4F14(int);
    extern int fn_802C4C90(int, int, int, int, int);
    extern int fn_802C51AC(void);
    extern int fn_802E317C(const char *, ...);
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
                    flagsArg % fn_802C4F14(*(int *)((char *)ctx + 0x64)), 0);
    } else if ((state = *(int *)((char *)ctx + 0x68)) != 0) {
        ((int (*)(int))fn_802C51AC)(state);
    }
    if (text == 0) return;
    if (*(int *)((char *)ctx + 8) != 0) return;
    fn_802E317C(lbl_8033FC08);
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
void fn_8022BAD0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, float farg0, unsigned char arg8) {
    fn_8022BD40(arg0, arg6, arg7, arg8,
                (float)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5, farg0);
}

extern void fn_80230C30(float *, float *, int, int);
#pragma push
#pragma processor 750
void fn_8022BB60(float *arg0, float *arg1, float farg0, float farg1) {
    fn_80230C30(arg0, arg1, (int)farg0, (int)farg1);
    *arg0 += farg0 - (float)(int)farg0;
    *arg1 -= farg1 - (float)(int)farg1;
}
#pragma pop
extern double lbl_805635A0;
unsigned int fn_8022BC30(unsigned int arg0, unsigned int arg1, float farg0) {
    float e = (float)(unsigned char)arg1;
    float a = (float)(unsigned char)arg0;
    float g = (float)(unsigned char)(arg1 >> 8);
    float f = (float)(unsigned char)(arg1 >> 16);
    float b = (float)(unsigned char)(arg0 >> 8);
    float c = (float)(unsigned char)(arg0 >> 16);
    float h = (float)(unsigned char)(arg1 >> 24);
    float d = (float)(unsigned char)(arg0 >> 24);
    int r0 = (int)(a + farg0 * (e - a));
    int r1 = (int)(b + farg0 * (f - b));
    int r2 = (int)(c + farg0 * (g - c));
    int r3 = (int)(d + farg0 * (h - d));
    return ((r3 & 0xFF) << 24) | ((r2 & 0xFF) << 16) |
           ((r1 & 0xFF) << 8) | (r0 & 0xFF);
}

extern double fn_8002EFB4(float arg0, double arg1);
extern float fn_8023659C(void);
extern float fn_80235EF0(int arg0, int arg1);
extern float fn_80235F64(int arg0, int arg1);
extern int fn_802C51AC();
extern int fn_80235FD8();
extern void fn_802C5310();
extern void fn_802354A0();
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
    void *base;
    char *i19;
    char *found;
    char *entry;
    (void)arg0;
    (void)farg5;
    f28v = farg1;
    i20 = i20_;
    i19 = (char *)i19arg;
    base = fn_8022CA2C();
    i30 = arg2_ * 4;
    sp8 = 0xFF;
    entry = (char *)base + i30;
    sp30 = lbl_8056358C;
    i26 = arg2_ & 1;
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
        ((void (*)(float *, float *, float, float))fn_8022BB60)(&sp28, &sp24, farg0, f28v);
        fn_802C5310(*(int *)((char *)base + 0x68), arg2_ % fn_802C51AC(*(int *)((char *)base + 0x68)), sp28, sp24, lbl_8056358C);
    } else if (*(int *)((char *)base + 0x6C) != 0) {
        ((void (*)(float *, float *, float, float))fn_8022BB60)(&sp20, &sp1C, farg0, f28v);
        fl = *(int *)((char *)base + 0x38);
        i30 = arg2_ % fn_80235FD8(*(int *)((char *)base + 0x6C));
        if (fl & 0x10) {
            sp1C += fn_80235F64(*(int *)((char *)base + 0x6C), i30) * lbl_80563598;
        } else if (fl & 0x40) {
            sp1C += fn_80235F64(*(int *)((char *)base + 0x6C), i30);
        }
        if (fl & 4) {
            sp20 -= (*(float *)((char *)lbl_8055E050 + 0x70) + fn_80235EF0(*(int *)((char *)base + 0x6C), i30)) * lbl_80563598;
        } else if ((fl & 2) && (i19 != 0) && (*(int *)((char *)base + 8) != 0)) {
            f29v = fn_8022CA40(base);
            sp20 -= ((float (*)(void *, char *, float))fn_8023293C)(*(void **)((char *)base + 8), i19, lbl_80563588) * f29v;
        }
        f29v = *(float *)((char *)lbl_8055E050 + 0x70) + fn_80235EF0(*(int *)((char *)base + 0x6C), i30);
        f30v = fn_80235F64(*(int *)((char *)base + 0x6C), i30);
        fn_802354A0(*(int *)((char *)base + 0x6C), i30, -1, sp20, sp1C, lbl_8056358C, f29v, f30v);
        if (i28 == 1) {
            f3v = lbl_80563598 * sp30;
            t0 = lbl_80563588 + sp30;
            mask = (sp8 << 24) | 0xFFFF;
            fn_802354A0(*(int *)((char *)base + 0x6C), i30, mask, sp20 - (f3v * f29v), sp1C + (f3v * f30v), lbl_8056358C, t0 * f29v, t0 * f30v);
        }
        if (arg2_ == 1) {
            i18 = *(int *)((char *)base + 0x54);
            if (i18 >= 0) {
                f30v = fn_80235F64(*(int *)((char *)base + 0x6C), i30);
                f29v = fn_80235EF0(*(int *)((char *)base + 0x6C), *(int *)((char *)base + 0x54));
                fn_802354A0(*(int *)((char *)base + 0x6C), i18, -1, sp20 + fn_80235EF0(*(int *)((char *)base + 0x6C), i30), sp1C, lbl_8056358C, f29v, f30v);
            }
        }
        if ((*(int *)((char *)base + 0x70) != 0) && (arg2_ == 1)) {
            i18 = *(int *)((char *)base + 0x58);
            f29v = fn_80235F64(*(int *)((char *)base + 0x70), i18);
            fn_802354A0(*(int *)((char *)base + 0x70), i18, -1, sp20 + *(float *)((char *)base + 0x5C), sp1C + *(float *)((char *)base + 0x60), lbl_8056358C, fn_80235EF0(*(int *)((char *)base + 0x70), *(int *)((char *)base + 0x58)), f29v);
        }
    } else if (i26 != 0) {
        ((void (*)(float *, float *, float, float))fn_8022BB60)(&sp18, &sp14, farg0, f28v);
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
            ((void (*)(float *, float *, float, float))fn_8022BB60)(&sp10, &spC, farg0 + (float)v2, f28v + (float)v3);
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
#pragma pop
void fn_8022C520(void) {
    register char* base;
    Cfg58 tmpl;
    Cfg58 work;
    void** v;
    void* list;
    int flag2;
    int value;
    register unsigned flag1;
    void* entry;
    char* s;
    int i;

    base = lbl_8033FBE8;
    tmpl = *(Cfg58*)&lbl_802F9F58;
    tmpl.w[3] = 0xffd6003c;
    tmpl.w[4] = 0xffd6003c;
    tmpl.w[5] = 0xff2dc82d;
    tmpl.w[6] = 0xff2dc82d;
    tmpl.w[10] = 0xff2d2dc8;
    tmpl.w[11] = 0xff2d2dc8;
    tmpl.w[12] = 0xffd6003c;
    tmpl.w[13] = 0xffd6003c;
    list = fn_80131810(base + 0x64, 0xff2dc82d, 0xffd6003c);
    if (list) {
        for (i = 0; (entry = (v = *(void***)list, ((void* (*)(void*, int))v[3])(list, i))) != 0; i++) {
            v = *(void***)entry;
            if (stricmp(((char* (*)(void*))v[2])(entry), lbl_8055B8C4) != 0) {
                continue;
            }
            v = *(void***)entry;
            if (((int (*)(void*, const char*))v[3])(entry, base + 0x70) != 0) {
                v = *(void***)entry;
                value = ((int (*)(void*, const char*))v[7])(entry, base + 0x70);
            } else {
                v = *(void***)entry;
                if (((int (*)(void*, const char*))v[3])(entry, base + 0x7c) == 0) {
                    fn_802E30C8(base + 0x88);
                    continue;
                } else {
                    v = *(void***)entry;
                    s = ((char* (*)(void*, const char*))v[5])(entry, base + 0x7c);
                    value = fn_8022CC8C(s);
                }
            }
            if (value < 0 || value >= 0x100) {
                v = *(void***)entry;
                fn_802E30C8(base + 0xb4,
                    ((int (*)(void*, const char*, int))v[6])(entry, base + 0x7c, (int)(base + 0xe4)));
                continue;
            }
            work = tmpl;
            v = *(void***)entry;
            work.w[0] = ((int (*)(void*, const char*, int))v[6])(entry, base + 0xf0, work.w[0]);
            v = *(void***)entry;
            *(float*)&work.w[1] = ((float (*)(void*, const char*, float))v[10])(entry, base + 0xfc, *(float*)&work.w[1]);
            flag1 = 1;
            v = *(void***)entry;
            if (((int (*)(void*, const char*))v[3])(entry, base + 0x108) != 0) {
                v = *(void***)entry;
                s = ((char* (*)(void*, const char*))v[5])(entry, base + 0x108);
                if (stricmp(s, lbl_8055B8CC) == 0) {
                    flag1 = 1;
                } else if (stricmp(s, lbl_8055B8D4) == 0) {
                    flag1 = 2;
                } else if (stricmp(s, lbl_8055B8DC) == 0) {
                    flag1 = 4;
                } else {
                    fn_802E30C8(base + 0x120, s);
                }
            }
            flag2 = 8;
            v = *(void***)entry;
            if (((int (*)(void*, const char*))v[3])(entry, base + 0x154) != 0) {
                v = *(void***)entry;
                s = ((char* (*)(void*, const char*))v[5])(entry, base + 0x154);
                if (stricmp(s, lbl_8055B8E4) == 0) {
                    flag2 = 8;
                } else if (stricmp(s, lbl_8055B8E8) == 0) {
                    flag2 = 0x10;
                } else if (stricmp(s, base + 0x168) == 0) {
                    flag2 = 0x20;
                } else if (stricmp(s, lbl_8055B8F0) == 0) {
                    flag2 = 0x40;
                } else {
                    fn_802E30C8(base + 0x174, s);
                }
            }
            work.w[2] = flag1 | flag2;
            v = *(void***)entry;
            fn_8022CDE4((int*)&work.w[3], ((void* (*)(void*, const char*))v[23])(entry, lbl_8055B8F8));
            v = *(void***)entry;
            fn_8022CDE4((int*)&work.w[10], ((void* (*)(void*, const char*))v[23])(entry, lbl_8055B8FC));
            v = *(void***)entry;
            if (((int (*)(void*, const char*))v[3])(entry, lbl_8055B900) != 0) {
                v = *(void***)entry;
                work.w[17] = (int)((char* (*)(void*, const char*))v[5])(entry, lbl_8055B900);
            }
            v = *(void***)entry;
            work.w[21] = ((int (*)(void*, const char*, int))v[8])(entry, lbl_8055B908, work.w[21]);
            v = *(void***)entry;
            work.w[18] = ((int (*)(void*, const char*, int))v[8])(entry, lbl_8055B910, work.w[18]);
            v = *(void***)entry;
            *(float*)&work.w[19] = ((float (*)(void*, const char*, float))v[10])(entry, base + 0x1a8, *(float*)&work.w[19]);
            v = *(void***)entry;
            *(float*)&work.w[20] = ((float (*)(void*, const char*, float))v[10])(entry, base + 0x1b4, *(float*)&work.w[20]);
            ((void (*)(int, void*))fn_8022A858)(value, &work);
        }
        fn_80131818(list);
    }
}

void fn_8022C9D0(void) {
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

void *fn_8022CA2C(int arg0) {
    return lbl_80490968 + arg0 * 0x74;
}

float fn_8022CA40(void *arg0) {
    if (*(float *)((char *)arg0 + 0x34) < lbl_80563588)
        return lbl_80563588;
    else {
        int value = fn_80232B70(*(int *)((char *)arg0 + 8));
        return *(float *)((char *)arg0 + 0x34) / (float)value;
    }
}

void fn_8022CAA8(void *arg0, void *arg1) {
    extern int fn_80232578(const char *);
    extern unsigned int fn_8022A834(unsigned int);
    extern int fn_802C5130(const char *);
    extern int fn_8023512C(const char *);
    extern int fn_802C49E8(const char *);
    extern char *strstr(const char *, const char *);
    extern char lbl_8033FC40[];
    unsigned char *src;
    unsigned char *dest;
    char *name;
    char *resource;
    int converted;
    int value48, value54, value40, value3C, value24, value20, value38, value1C, value8;
    float value4, value50, value4C;

    src = (unsigned char *)arg1;
    dest = (unsigned char *)arg0;
    dest[0] = 1;
    *(int *)(dest + 4) = 0;
    *(int *)(dest + 8) = 0;
    name = *(char **)src;
    if (strstr(name, lbl_8055B918) != 0) {
        *(int *)(dest + 8) = fn_80232578(lbl_8033FC40);
    }
    name = *(char **)src;
    if (strstr(name, lbl_8055B920) != 0) {
        *(int *)(dest + 8) = fn_80232578(name);
    }
    value4 = *(float *)(src + 4);
    converted = *(int *)(src + 0x0C);
    *(float *)(dest + 0x34) = value4;
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

    resource = *(char **)(src + 0x44);
    value8 = *(int *)(src + 8);
    value1C = *(int *)(src + 0x1C);
    value38 = *(int *)(src + 0x38);
    value20 = *(int *)(src + 0x20);
    value24 = *(int *)(src + 0x24);
    value3C = *(int *)(src + 0x3C);
    value40 = *(int *)(src + 0x40);
    value54 = *(int *)(src + 0x54);
    value48 = *(int *)(src + 0x48);
    value4C = *(float *)(src + 0x4C);
    value50 = *(float *)(src + 0x50);
    *(int *)(dest + 0x30) = converted;
    *(int *)(dest + 0x38) = value8;
    *(int *)(dest + 0x3C) = value1C;
    *(int *)(dest + 0x40) = value38;
    *(int *)(dest + 0x44) = value20;
    *(int *)(dest + 0x48) = value24;
    *(int *)(dest + 0x4C) = value3C;
    *(int *)(dest + 0x50) = value40;
    *(int *)(dest + 0x54) = value54;
    *(int *)(dest + 0x58) = value48;
    *(float *)(dest + 0x5C) = value4C;
    *(float *)(dest + 0x60) = value50;
    *(int *)(dest + 0x64) = 0;
    *(int *)(dest + 0x68) = 0;
    *(int *)(dest + 0x6C) = 0;
    *(int *)(dest + 0x70) = 0;

    if (resource != 0) {
        if (fn_8022A7D4(resource) != 0) {
            *(int *)(dest + 0x68) = fn_802C5130(resource);
        } else if (fn_8022A804(resource) != 0) {
            *(int *)(dest + 0x6C) = fn_8023512C(resource);
        } else {
            *(int *)(dest + 0x64) = fn_802C49E8(resource);
        }
    }
    *(int *)(dest + 0x58) = -1;
}

extern double lbl_80563590;
extern int fn_80232B70(int);
extern char lbl_8033FF98[];
extern int stricmp(const char *, const char *);
int fn_8022CC8C(const char *arg0) {
    char *p;
    unsigned int i;

    p = lbl_8033FF98;
    i = 0;
    for (; i < 0x1B; i++, p += 8) {
        if (stricmp(arg0, *(const char **)(p + 4)) == 0)
            return *(int *)(lbl_8033FF98 + i * 8);
    }
    return 0x1A;
}

__declspec(section ".sdata") extern char lbl_8055B928[];
extern char lbl_80340070[];
extern int sscanf(const char *, const char *, ...);
int fn_8022CD0C(char *arg0) {
    volatile int sp18;
    int sp14;
    int sp10;
    int spC;
    int sp8;
    int result;
    int high;
    int low;

    if (sscanf(arg0, lbl_8055B928, (int *)&sp18) == 1)
        return sp18;

    result = sscanf(arg0, lbl_80340070, &sp14, &sp10, &spC, &sp8);
    if (result == 3) {
        high = (sp14 & 0xFF) << 16;
        low = (sp10 & 0xFF) << 8;
        low |= spC & 0xFF;
        high |= 0xFF000000;
        result = low | high;
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

extern char lbl_8033FBE8[];
extern char lbl_8055B930[];
extern char lbl_8055B938[];
extern char lbl_8055B940[];
extern char lbl_8055B948[];
extern char lbl_8055B950[];
extern char lbl_8033FBE8[], lbl_8055B930[], lbl_8055B938[], lbl_8055B940[], lbl_8055B948[], lbl_8055B950[];
#pragma dont_inline(fn_8022CD0C)
void fn_8022CDE4(int *d, void *o) {
 char *s; const char *base = lbl_8033FBE8;
 if (o == 0) goto end;
 
 if (((int(*)(void*,const char*))(*(void ***)o)[3])(o,base+0x498)) { s=((char*(*)(void*,const char*))(*(void ***)o)[5])(o,base+0x498); d[0]=fn_8022CD0C(s); }
 
 if (((int(*)(void*,const char*))(*(void ***)o)[3])(o,base+0x4A4)) { s=((char*(*)(void*,const char*))(*(void ***)o)[5])(o,base+0x4A4); d[1]=fn_8022CD0C(s); }
 
 if (((int(*)(void*,const char*))(*(void ***)o)[3])(o,base+0x4BC)) { s=((char*(*)(void*,const char*))(*(void ***)o)[5])(o,base+0x4BC); d[2]=fn_8022CD0C(s); }
 
 if (((int(*)(void*,const char*))(*(void ***)o)[3])(o,base+0x4C8)) { s=((char*(*)(void*,const char*))(*(void ***)o)[5])(o,base+0x4C8); d[3]=fn_8022CD0C(s); }
 
 if (((int(*)(void*,const char*))(*(void ***)o)[3])(o,base+0x4E0)) {
  s=((char*(*)(void*,const char*))(*(void ***)o)[5])(o,base+0x4E0);
  if (!stricmp(s,lbl_8055B930)) d[4]=0;
  else if (!stricmp(s,lbl_8055B938)) d[4]=4;
  else if (!stricmp(s,lbl_8055B940)) d[4]=2;
  else if (!stricmp(s,base+0x4EC)) d[4]=1;
  else if (!stricmp(s,base+0x4F8)) d[4]=5;
  else if (!stricmp(s,base+0x504)) d[4]=6;
  else d[4]=fn_8022CD0C(s);
 }
 
 if (((int(*)(void*,const char*))(*(void ***)o)[3])(o,lbl_8055B948)) { s=((char*(*)(void*,const char*))(*(void ***)o)[5])(o,lbl_8055B948); sscanf(s,lbl_8055B950,&d[5],&d[6]); }
end:;
}
#pragma dont_inline reset
