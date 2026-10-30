__declspec(section ".sdata") extern char lbl_8055B8B8[];

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
    unsigned int i;
    unsigned char *src = lbl_80497D68;
    unsigned char *dst = (unsigned char *)lbl_80490968;
    /* Fix note: initialize the default record, then repeat its fields in the slot table. */
    memset(src, 0, 0x74);
    *(unsigned int *)(src + 0x38) = 9;
    for (i = 0; i < 0x80; i++) {
        unsigned char *out = dst + i * 0xE8;
        unsigned int j;
        for (j = 0; j < 0x74; j++) {
            out[j] = src[j];
            out[j + 0x74] = src[j];
        }
        *(unsigned int *)(out + 0x38) = 9;
        *(unsigned int *)(out + 0xAC) = 9;
    }
    fn_8022C520();
}

void fn_8022A7D0(void) {
    fn_8022C9D0();
}

int fn_8022A7D4(const char *arg0) {
    return strstr(arg0, lbl_8055B8B0) != 0;
}

int fn_8022A804(const char *arg0) {
    return strstr(arg0, lbl_8055B8B8) != 0;
}

unsigned int fn_8022A834(unsigned int arg0) {
    unsigned int byte = arg0 >> 24;
    if (byte >= 0x20 || byte == 0) {
    } else {
        arg0 = (arg0 & 0x00FFFFFF) | 0xFF000000;
    }
    return arg0;
}

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
float fn_8022AAA8(void *unused, char *arg1) {
    void *p = fn_8022CA2C();
    if (*(int *)((char *)p + 8) != 0) {
        float scale = fn_8022CA40(p);
        return scale * ((float (*)(void *, char *, float))fn_8023293C)(*(void **)((char *)p + 8), arg1, lbl_80563588);
    }
    return lbl_8056358C;
}

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
extern void fn_8022ACFC(int, int, float *, float *, float *, float *, float, float);
__declspec(section ".sdata2") extern double lbl_80563590;
void fn_8022AC1C(int unused0, int unused1, int arg2, int arg3, int *arg4, int *arg5, int *arg6, int *arg7) {
    float a, b, c, d;
    float x = (float)((double)(arg2 ^ 0x80000000) - lbl_80563590);
    float y = (float)((double)(arg3 ^ 0x80000000) - lbl_80563590);
    fn_8022ACFC(unused0, unused1, &a, &b, &c, &d, x, y);
    *arg4 = (int)a;
    *arg5 = (int)b;
    *arg6 = (int)c;
    *arg7 = (int)d;
}

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
#pragma scheduling invalid_target
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
#pragma opt_common_subs off
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

void fn_8022C520(void) {
    Cfg58 tmpl;
    Cfg58 work;
    int i;
    void* list;
    void* entry;
    int value;
    int flag1;
    int flag2;
    char* s;
    void** v;
    unsigned int c1;
    unsigned int c2;
    unsigned int c3;

    tmpl = *(Cfg58*)&lbl_802F9F58;
    c1 = 0xffd6003c;
    c2 = 0xff2dc82d;
    c3 = 0xff2d2dc8;
    tmpl.w[3] = c1;
    tmpl.w[4] = c1;
    tmpl.w[5] = c2;
    tmpl.w[6] = c2;
    tmpl.w[10] = c3;
    tmpl.w[11] = c3;
    tmpl.w[12] = c1;
    tmpl.w[13] = c1;
    list = fn_80131810(lbl_8033FBE8 + 0x64, 0xff2dc82d, 0xffd6003c);
    if (list != 0) {
        for (i = 0; (entry = (v = *(void***)list, ((void* (*)(void*, int))v[3])(list, i))) != 0; i++) {
            v = *(void***)entry;
            if (stricmp(((char* (*)(void*))v[2])(entry), lbl_8055B8C4) != 0) {
                continue;
            }
            v = *(void***)entry;
            if (((int (*)(void*, const char*))v[3])(entry, lbl_8033FBE8 + 0x70) != 0) {
                v = *(void***)entry;
                value = ((int (*)(void*, const char*))v[7])(entry, lbl_8033FBE8 + 0x70);
            } else {
                v = *(void***)entry;
                if (((int (*)(void*, const char*))v[3])(entry, lbl_8033FBE8 + 0x7c) == 0) {
                    fn_802E30C8(lbl_8033FBE8 + 0x88);
                    continue;
                } else {
                    v = *(void***)entry;
                    s = ((char* (*)(void*, const char*))v[5])(entry, lbl_8033FBE8 + 0x7c);
                    value = fn_8022CC8C(s);
                }
            }
            if (value < 0 || value >= 0x100) {
                v = *(void***)entry;
                fn_802E30C8(lbl_8033FBE8 + 0xb4,
                    ((int (*)(void*, const char*, int))v[6])(entry, lbl_8033FBE8 + 0x7c, (int)(lbl_8033FBE8 + 0xe4)));
                continue;
            }
            work = tmpl;
            v = *(void***)entry;
            work.w[0] = ((int (*)(void*, const char*, int))v[6])(entry, lbl_8033FBE8 + 0xf0, work.w[0]);
            v = *(void***)entry;
            *(float*)&work.w[1] = ((float (*)(void*, const char*, float))v[10])(entry, lbl_8033FBE8 + 0xfc, *(float*)&work.w[1]);
            flag1 = 1;
            v = *(void***)entry;
            if (((int (*)(void*, const char*))v[3])(entry, lbl_8033FBE8 + 0x108) != 0) {
                v = *(void***)entry;
                s = ((char* (*)(void*, const char*))v[5])(entry, lbl_8033FBE8 + 0x108);
                if (stricmp(s, lbl_8055B8CC) == 0) {
                    flag1 = 1;
                } else if (stricmp(s, lbl_8055B8D4) == 0) {
                    flag1 = 2;
                } else if (stricmp(s, lbl_8055B8DC) == 0) {
                    flag1 = 4;
                } else {
                    fn_802E30C8(lbl_8033FBE8 + 0x120, s);
                }
            }
            flag2 = 8;
            v = *(void***)entry;
            if (((int (*)(void*, const char*))v[3])(entry, lbl_8033FBE8 + 0x154) != 0) {
                v = *(void***)entry;
                s = ((char* (*)(void*, const char*))v[5])(entry, lbl_8033FBE8 + 0x154);
                if (stricmp(s, lbl_8055B8E4) == 0) {
                    flag2 = 8;
                } else if (stricmp(s, lbl_8055B8E8) == 0) {
                    flag2 = 0x10;
                } else if (stricmp(s, lbl_8033FBE8 + 0x168) == 0) {
                    flag2 = 0x20;
                } else if (stricmp(s, lbl_8055B8F0) == 0) {
                    flag2 = 0x40;
                } else {
                    fn_802E30C8(lbl_8033FBE8 + 0x174, s);
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
            *(float*)&work.w[19] = ((float (*)(void*, const char*, float))v[10])(entry, lbl_8033FBE8 + 0x1a8, *(float*)&work.w[19]);
            v = *(void***)entry;
            *(float*)&work.w[20] = ((float (*)(void*, const char*, float))v[10])(entry, lbl_8033FBE8 + 0x1b4, *(float*)&work.w[20]);
            ((void (*)(int, void*))fn_8022A858)(value, &work);
        }
        fn_80131818(list);
    }
}

void fn_8022C9D0(void) {
    unsigned char *p = (unsigned char *)lbl_80490968;
    int i = 0;
loop:
    if (*p != 0) fn_8022A8E4(i);
    i++;
    if (i < 0x100) {
        p += 0x74;
        goto loop;
    }
}

void *fn_8022CA2C(int arg0) {
    return lbl_80490968 + arg0 * 0x74;
}

float fn_8022CA40(void *arg0) {
    if (*(float *)((char *)arg0 + 0x34) < lbl_80563588)
        return lbl_80563588;
    else {
        union {
            double d;
            unsigned int w[2];
        } converted;
        int value = fn_80232B70(*(int *)((char *)arg0 + 8));
        double raw;
        double bias;
        converted.w[1] = (unsigned int)value ^ 0x80000000;
        converted.w[0] = 0x43300000;
        raw = converted.d;
        bias = lbl_80563590;
        return *(float *)((char *)arg0 + 0x34) / (float)(raw - bias);
    }
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
 char *s; void **v;
 if (!o) return;
 v=*(void ***)o;
 if (((int(*)(void*,const char*))v[3])(o,lbl_8033FBE8+0x498)) { s=((char*(*)(void*,const char*))v[5])(o,lbl_8033FBE8+0x498); d[0]=fn_8022CD0C(s); }
 v=*(void ***)o;
 if (((int(*)(void*,const char*))v[3])(o,lbl_8033FBE8+0x4A4)) { s=((char*(*)(void*,const char*))v[5])(o,lbl_8033FBE8+0x4A4); d[1]=fn_8022CD0C(s); }
 v=*(void ***)o;
 if (((int(*)(void*,const char*))v[3])(o,lbl_8033FBE8+0x4BC)) { s=((char*(*)(void*,const char*))v[5])(o,lbl_8033FBE8+0x4BC); d[2]=fn_8022CD0C(s); }
 v=*(void ***)o;
 if (((int(*)(void*,const char*))v[3])(o,lbl_8033FBE8+0x4C8)) { s=((char*(*)(void*,const char*))v[5])(o,lbl_8033FBE8+0x4C8); d[3]=fn_8022CD0C(s); }
 v=*(void ***)o;
 if (((int(*)(void*,const char*))v[3])(o,lbl_8033FBE8+0x4E0)) {
  s=((char*(*)(void*,const char*))v[5])(o,lbl_8033FBE8+0x4E0);
  if (!stricmp(s,lbl_8055B930)) d[4]=0;
  else if (!stricmp(s,lbl_8055B938)) d[4]=4;
  else if (!stricmp(s,lbl_8055B940)) d[4]=2;
  else if (!stricmp(s,lbl_8033FBE8+0x4EC)) d[4]=1;
  else if (!stricmp(s,lbl_8033FBE8+0x4F8)) d[4]=5;
  else if (!stricmp(s,lbl_8033FBE8+0x504)) d[4]=6;
  else d[4]=fn_8022CD0C(s);
 }
 v=*(void ***)o;
 if (((int(*)(void*,const char*))v[3])(o,lbl_8055B948)) { s=((char*(*)(void*,const char*))v[5])(o,lbl_8055B948); sscanf(s,lbl_8055B950,&d[5],&d[6]); }
}
#pragma dont_inline reset
