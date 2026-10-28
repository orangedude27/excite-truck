#include "types.h"
extern unsigned int lbl_8055FD2C;
extern void *lbl_8055FE1C;
extern void *lbl_8055FE20;
extern void fn_802CFEEC(void);
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern char lbl_8034C4B0[];
extern void fn_802E317C(const char *, ...);
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_804C5700[12];
extern void GXLoadTexObj(void *, int);
extern void fn_80128670(void *);
extern void *lbl_8055FE28;
extern void *lbl_8055FE18;
extern void fn_802D7564(void);
extern void fn_802E30C8(const char *, ...);
extern void fn_802E317C(const char *, ...);
extern char lbl_8034C460[];
extern char lbl_8034C47C[];
extern char lbl_8034C494[];
extern unsigned short GXGetTexObjWrapS(void *);
extern unsigned short GXGetTexObjWrapT(void *);
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern char lbl_8055D110[];
extern void *fn_8012850C(void *, void *);
extern char lbl_8055D118[4];
extern void *fn_802D7600(void *queue);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D7564(void) {
    int offset;
    int i;
    unsigned char *entry;
    unsigned short t;

    fn_802E30C8(lbl_8034C460);
    i = 0;
    offset = 0;
    do {
        entry = (unsigned char *)lbl_8055FE28 + offset;
        if (entry[0x20] != 0) {
            t = GXGetTexObjWrapT(entry + 0x24) & 0xFFFF;
            fn_802E30C8(lbl_8034C47C, i, entry,
                        (unsigned short)GXGetTexObjWrapS(entry + 0x24), t);
        }
        i++;
        offset += 0xF4;
    } while (i < 0x1C2);
}
#pragma pop

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802D7600(void *arg0) {
    unsigned char *entry;
    int i;

    entry = (unsigned char *)lbl_8055FE28;
    for (i = 0; i < 0x1C2; i++) {
        if (entry[0x20] == 0) {
            memset(entry, 0, 0xF4);
            entry[0x20] = 1;
            return entry;
        }
        entry += 0xF4;
    }
    fn_802D7564();
    fn_802E317C(lbl_8034C494, arg0);
    return 0;
}
#pragma pop

#pragma dont_inline on
void fn_802D768C(void *arg0) {
    extern void fn_80128658(s32);
    s32 temp_r0;

    temp_r0 = *(s32 *)((u8 *)arg0 + 0xE8);
    *(s8 *)((u8 *)arg0 + 0x20) = 0;
    if (temp_r0 != 0) {
        fn_80128658(temp_r0);
        *(s32 *)((u8 *)arg0 + 0xE8) = 0;
    }
}
#pragma dont_inline reset

int fn_802D76DC(int arg0) {
    switch (arg0) {
    case 3:
    case 0x40:
    case 0x41:
    case 0x43:
    case 0x46:
    case 0x47:
    case 0x4A:
    case 0x4B:
        return 1;
    case 2:
    case 0x42:
    case 0x44:
    case 0x45:
    case 0x48:
    case 0x49:
    case 0x4C:
        return 0;
    }
    fn_802E317C(lbl_8034C4B0, arg0);
    return 1;
}

#pragma dont_inline on
void fn_802D78D4(void *arg0, void *arg1, unsigned int arg2, unsigned int arg3) {
    unsigned int i;
    unsigned char *pixels = (unsigned char *)arg2;
    unsigned short *rgb = (unsigned short *)arg0;
    unsigned short *alpha = (unsigned short *)arg1;
    for (i = 0; i < arg3; i++) {
        unsigned int r = pixels[i * 4 + 0];
        unsigned int g = pixels[i * 4 + 1];
        unsigned int b = pixels[i * 4 + 2];
        unsigned int a = pixels[i * 4 + 3];
        rgb[i] = (unsigned short)(((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3));
        alpha[i] = (unsigned short)(a << 8);
    }
}

void fn_802D81C4(void *arg0, int arg1) {
    int width = *(int *)((char *)arg0 + 0x24);
    int height = *(int *)((char *)arg0 + 0x28);
    unsigned char *s2 = *(unsigned char **)((char *)arg0 + 0x2C);
    unsigned char *p = *(unsigned char **)(s2 + 4);
    unsigned char *q;
    unsigned char *d;
    unsigned char *line;
    unsigned char *tmp;
    int n = (width * height) / 2;
    int i, x, y, halfw, size;

    d = p;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            *d = (unsigned char)((*d >> 4) | (*d << 4));
            d++;
        }
    }
    q = *(unsigned char **)s2;
    for (i = 0; i < 0x10; i++) {
        unsigned char t0;
        unsigned char t1;
        t0 = q[0];
        q[0] = q[3];
        q[3] = t0;
        t1 = q[1];
        q[1] = q[2];
        q[2] = t1;
        q += 4;
    }
    halfw = width / 2;
    fn_801282EC(0x20);
    size = halfw * height;
    tmp = fn_8012850C((void *)size, lbl_8055D110);
    memcpy(tmp, p, (unsigned int)size);
    for (y = 0; y < height; y++) {
        line = tmp + y * halfw;
        for (x = 0; x < halfw; x++) {
            p[((y / 8) * (halfw / 4) + x / 4) * 32 + (y % 8) * 4 + x % 4] = *line++;
        }
    }
    fn_80128670(tmp);
}

#pragma dont_inline reset

void fn_802D8DA0(void) {
    fn_80128670(lbl_8055FE28);
    lbl_8055FE28 = 0;
}

extern void fn_802D81C4(void *, int);
extern void fn_802D86BC(void *, int);
void fn_802D8DCC(void *arg0, int arg1) { unsigned int kind; unsigned char t; unsigned char *p = *(unsigned char **)((char *)arg0 + 0x2C); t=p[0]; p[0]=p[3]; p[3]=t; t=p[1]; p[1]=p[2]; p[2]=t; if (*(int *)(p+0) != 0) *(unsigned char **)(p+0) = p + *(int *)(p+0); t=p[4]; p[4]=p[7]; p[7]=t; t=p[5]; p[5]=p[6]; p[6]=t; if (*(int *)(p+4) != 0) *(unsigned char **)(p+4) = p + *(int *)(p+4); t=p[8]; p[8]=p[11]; p[11]=t; t=p[9]; p[9]=p[10]; p[10]=t; if (*(int *)(p+8) != 0) *(unsigned char **)(p+8) = p + *(int *)(p+8); kind=*(unsigned int *)arg0; if (kind == 0x40 || kind == 0) fn_802D81C4(arg0,arg1); else if (kind == 0x41 || kind == 1) fn_802D86BC(arg0,arg1); }

extern void *fn_802D7B5C(void *, void *);
extern void *fn_802D7D98(void *, void *);
extern void *fn_802D7FA0(void *, void *);
extern void *fn_802D8A84(void *, void *);
extern void *fn_802D8C00(void *, void *);
extern void fn_802D9340(void *);
extern char lbl_8034C5C8[];
void *fn_802D8E9C(void *arg0, void *arg1) {
    void *obj = 0;
    int kind = *(int *)arg0;
    void *name = arg1;

    if (kind == 0x17) goto use_a84;
    if (kind >= 0x17) goto high_range;
    if (kind == 0x10) goto use_a84;
    if (kind >= 0x10) goto low_mid;
    if (kind >= 0x02) goto low_two;
    if (kind < 0) goto report_error;
    goto use_b5c;

low_two:
    if (kind < 0x04) goto use_d98;
    goto report_error;

low_mid:
    if (kind < 0x12) goto use_c00;
    goto report_error;

high_range:
    if (kind == 0x44) goto use_c00;
    if (kind >= 0x44) goto high_tail;
    if (kind >= 0x42) goto use_a84;
    if (kind < 0x40) goto report_error;
    goto use_b5c;

high_tail:
    if (kind == 0x47) goto use_d98;
    if (kind < 0x47) goto use_fa0;
    if (kind >= 0x4C) goto report_error;

use_fa0:
    obj = fn_802D7FA0(arg0, name);
    goto finish;
use_b5c:
    obj = fn_802D7B5C(arg0, name);
    goto finish;
use_a84:
    obj = fn_802D8A84(arg0, name);
    goto finish;
use_c00:
    obj = fn_802D8C00(arg0, name);
    goto finish;
use_d98:
    obj = fn_802D7D98(arg0, name);
    goto finish;
report_error:
    fn_802E317C(lbl_8034C5C8, kind);
finish:
    fn_802D9340(obj);
    return obj;
}

void fn_802D8FB4(void *arg0) {
    if (*(unsigned int *)((char *)arg0 + 0xF0) != 0 &&
        (unsigned int)(lbl_8055FD2C - *(unsigned int *)((char *)arg0 + 0xEC)) >= 0xFFFFFF00U) {
        fn_802CFEEC();
    }
    if (*(unsigned int *)((char *)arg0 + 0x70) != 0) {
        fn_80128670((void *)*(unsigned int *)((char *)arg0 + 0x70));
    }
    if (*(unsigned int *)((char *)arg0 + 0xC4) != 0) {
        fn_80128670((void *)*(unsigned int *)((char *)arg0 + 0xC4));
    }
    fn_802D768C(arg0);
    if (lbl_8055FE18 == arg0) {
        lbl_8055FE18 = 0;
    }
    if (lbl_8055FE1C == arg0) {
        lbl_8055FE1C = 0;
    }
    if (lbl_8055FE20 == arg0) {
        lbl_8055FE20 = 0;
    }
}

extern unsigned int lbl_8055FD2C;
extern void *lbl_8055FE1C;
extern void *lbl_8055FE20;
extern void fn_802CFEEC(void);

int fn_802D9068(void) {
    unsigned char *p = (unsigned char *)lbl_8055FE28;
    int i = 0;
    while (i < 450) {
        if (p[0x20] == 0) return 1;
        p += 0xF4;
        i++;
    }
    return 0;
}

void fn_802D9154(void) {
    fn_802D7600(lbl_8055D118);
}

extern void fn_802D768C(void *);
void fn_802D915C(void *arg0) {
    fn_802D768C(arg0);
}

extern void fn_802D6C68(void);
extern void fn_802CFF5C(void *);
extern void fn_802CFFA4(unsigned int);
extern void GXLoadTlut(void *, int);
extern unsigned int lbl_8055FD1C;
extern unsigned char lbl_8055FD24;
extern unsigned int lbl_8055FD30;
void fn_802D9160(void *arg0) {
    char *obj = (char *)arg0;
    fn_802D6C68();
    lbl_8055FE18 = arg0;
    fn_802CFF5C((void *)(*(unsigned int *)(obj + 0xE0) | (lbl_8055FD1C & ~0x14E)));
    fn_802CFFA4(*(unsigned int *)(obj + 0xDC));
    lbl_8055FD24 = *(unsigned char *)(obj + 0xE4);
    if (*(int *)(obj + 0x70) != 0) GXLoadTlut(obj + 0x64, 0);
    GXLoadTexObj(obj + 0x24, 0);
    if (*(unsigned char *)(obj + 0xCC) != 0) {
        if (*(int *)(obj + 0xC4) != 0) GXLoadTlut(obj + 0xB8, 1);
        GXLoadTexObj(obj + 0x78, 1);
    }
    *(volatile unsigned int *)(obj + 0xEC) = lbl_8055FD30;
    *(unsigned int *)(obj + 0xF0) += 1;
    lbl_804C5700[8] = *(volatile unsigned char *)(obj + 0xCC);
}

extern void *lbl_8055FE1C;
extern void *lbl_8055FE20;
extern char lbl_8034C5F0[];
extern char lbl_8034C620[];
extern char lbl_8034C650[];
extern unsigned char lbl_804C5700[12];
extern void fn_802E317C(const char *, ...);
extern void GXInitTexObjWrapMode(void *, int, int);
extern void GXLoadTexObj(void *, int);
extern void DCFlushRange(void *, unsigned int);
extern unsigned int GXGetTexObjTlut(void *);
extern void fn_802D78D4(void *, void *, unsigned int, unsigned int);
extern void GXInvalidateTexAll(void);
void fn_802D92B0(void) {
    fn_802D9230(lbl_8055FE1C);
}

extern void fn_802CFEEC(void);
extern void fn_80128670(void *);
extern unsigned int lbl_8055FD2C;
void fn_802D92B8(void *arg0) {
    char *obj;
    lbl_8055FE20 = arg0;
    if (((unsigned char *)arg0)[0xCC]) fn_802E317C(lbl_8034C620, arg0);
    if (*(unsigned int *)((char *)arg0 + 0x70)) fn_802E317C(lbl_8034C650, arg0);
    obj = (char *)arg0;
    GXInitTexObjWrapMode(obj + 0x24, 0, 0);
    GXLoadTexObj(obj + 0x24, 3);
}

void fn_802D9340(void *arg0) {
    unsigned int value;
    value = *(unsigned int *)((char *)arg0 + 0xD0);
    if (value != 0 && *(unsigned int *)((char *)arg0 + 0xD4) != 0) {
        DCFlushRange((void *)value, *(unsigned int *)((char *)arg0 + 0xD4));
    }
    if (*(unsigned int *)((char *)arg0 + 0x70) != 0 &&
        *(unsigned int *)((char *)arg0 + 0x74) != 0) {
        fn_802D78D4(*(void **)((char *)arg0 + 0x70),
                    *(void **)((char *)arg0 + 0xC4),
                    *(unsigned int *)((char *)arg0 + 0xD8),
                    GXGetTexObjTlut((char *)arg0 + 0x64) & 0xFFFF);
        DCFlushRange(*(void **)((char *)arg0 + 0x70),
                     *(unsigned int *)((char *)arg0 + 0x74));
    }
    if (*(void **)((char *)arg0 + 0xC4) != 0) {
        DCFlushRange(*(void **)((char *)arg0 + 0xC4),
                     *(unsigned int *)((char *)arg0 + 0xC8));
    }
    GXInvalidateTexAll();
}

extern float lbl_80565018;
float fn_802D93E0(void) {
    return lbl_80565018;
}

extern void fn_802D2614(void);
extern int lbl_8055FE24;
void fn_802D93E8(int arg0) {
    fn_802D2614();
    lbl_8055FE24 = arg0;
}

extern int GXGetTexObjMipMap(void *);
extern void *GXGetTexObjFmt(void *);
extern void GXCopyTex(void *, int);
extern void GXSetTexCopySrc(unsigned short, unsigned short, unsigned short, unsigned short);
extern void GXSetTexCopyDst(unsigned short, unsigned short, int, unsigned char);
extern void GXSetZMode(int, int, int);
extern void GXSetColorUpdate(int);
extern void fn_802CFF50(void);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D9418(void) {
    void *obj;
    unsigned int s, t;
    fn_802D2614();
    obj = (char *)lbl_8055FE24 + 0x24;
    s = GXGetTexObjWrapS(obj) & 0xFFFF;
    t = GXGetTexObjWrapT(obj) & 0xFFFF;
    GXSetTexCopySrc(0, 0, s, t);
    GXSetTexCopyDst(s, t, GXGetTexObjMipMap(obj), 0);
    GXSetZMode(1, 7, 1);
    GXSetColorUpdate(1);
    GXCopyTex(GXGetTexObjFmt(obj), 1);
    lbl_8055FE24 = 0;
    fn_802CFF50();
}
#pragma pop
extern void *lbl_8055FE28;
extern char lbl_8034C5B8[];
extern void *fn_8012850C(void *, void *);
void* fn_802D94DC(void) {
    return lbl_8055FE18;
}

extern float lbl_80565028;
void fn_802D94E4(void *arg0, void *arg1, void *arg2, float farg0) {
    unsigned int *dst = (unsigned int *)((char *)GXGetTexObjFmt((char *)arg0 + 0x24) - 0x40000000);
    unsigned int *src1 = (unsigned int *)((char *)GXGetTexObjFmt((char *)arg1 + 0x24) - 0x40000000);
    unsigned int *src2 = (unsigned int *)((char *)GXGetTexObjFmt((char *)arg2 + 0x24) - 0x40000000);
    unsigned int count = (GXGetTexObjWrapS((char *)arg0 + 0x24) * GXGetTexObjWrapT((char *)arg0 + 0x24) * 16) / 32;
    unsigned int blend = (unsigned int)(lbl_80565028 * farg0), inv = 256 - blend;
    while (count-- > 0) {
        unsigned int a=*src1++, b=*src2++;
        unsigned int c0=(a&255)*inv+(b&255)*blend, c1=((a>>8)&255)*inv+((b>>8)&255)*blend;
        unsigned int c2=((a>>16)&255)*inv+((b>>16)&255)*blend, c3=((a>>24)&255)*inv+((b>>24)&255)*blend;
        *dst++=(c0>>8)|(c1&0xFFFFFF00)|((c2<<8)&0xFFFF0000)|((c3<<16)&0xFF000000);
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D9628(register void *arg0, register s32 arg1, register s32 arg2, register s32 arg3) {
    int mip;
    int wrap;
    int base;
    int tile;
    unsigned int ysign;
    unsigned int yoff;
    unsigned int xsign;
    unsigned int xoff;
    int pixel;

    mip = GXGetTexObjMipMap((char *)arg0 + 0x24);
    wrap = GXGetTexObjWrapS((char *)arg0 + 0x24) & 0xFFFF;
    GXGetTexObjWrapT((char *)arg0 + 0x24);
    base = (int)GXGetTexObjFmt((char *)arg0 + 0x24) - 0x40000000;
    if (mip == 0) {
        tile = arg1 / 8 + (arg2 / 8) * (wrap / 8);
        base += tile << 5;

        ysign = (unsigned int)arg2 >> 31;
        yoff = (arg2 << 29) - ysign;
        xsign = (unsigned int)arg1 >> 31;
        xoff = (arg1 << 29) - xsign;
        pixel = (int)((((xoff << 3) | (xoff >> 29)) + xsign +
                      ((((yoff << 3) | (yoff >> 29)) + ysign) * 8)) * 4) / 8;
        {
            unsigned char value = (unsigned char)arg3;
            if (arg1 & 1) {
                unsigned char old = *(unsigned char *)(base + pixel);
                *(unsigned char *)(base + pixel) = (unsigned char)((value & 0xF0) | (old & 0x0F));
            } else {
                unsigned char old = *(unsigned char *)(base + pixel);
                *(unsigned char *)(base + pixel) = (unsigned char)(((value >> 4) & 0x0F) | (old & 0xF0));
            }
        }
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
int fn_802D972C(void *arg0, int arg1, int arg2) {
    int mip;
    int base;
    int wrap;
    unsigned int ysign, yoff, xsign, xoff, ysign2, yoff2, xsign2, xoff2;
    int tile;
    int pixel;
    unsigned int value;
    int doubled;
    mip = GXGetTexObjMipMap((char *)arg0 + 0x24);
    wrap = GXGetTexObjWrapS((char *)arg0 + 0x24);
    GXGetTexObjWrapT((char *)arg0 + 0x24);
    base = (int)GXGetTexObjFmt((char *)arg0 + 0x24) - 0x40000000;
    if (mip == 0) {
        ysign = (unsigned int)arg2 >> 31;
        yoff = (arg2 << 29) - ysign;
        xsign = (unsigned int)arg1 >> 31;
        xoff = (arg1 << 29) - xsign;
        pixel = (int)((((xoff << 3) | (xoff >> 29)) + xsign +
                       ((((yoff << 3) | (yoff >> 29)) + ysign) * 8)) * 4) / 8;
        tile = (arg1 / 8) + ((arg2 / 8) * (wrap / 8));
        base += tile << 5;
        if (!(arg1 & 1)) {
            value = (*(unsigned char *)(base + pixel) >> 4) & 0xF;
        } else {
            value = *(unsigned char *)(base + pixel) & 0xF;
        }
        doubled = value | (value * 0x10);
        return (doubled << 24) | ((doubled << 16) | doubled | (doubled << 8));
    }
    if (mip == 6) {
        ysign2 = (unsigned int)arg2 >> 31;
        yoff2 = (arg2 << 30) - ysign2;
        xsign2 = (unsigned int)arg1 >> 31;
        xoff2 = (arg1 << 30) - xsign2;
        pixel = (int)((((xoff2 << 2) | (xoff2 >> 30)) + xsign2 +
                       ((((yoff2 << 2) | (yoff2 >> 30)) + ysign2) * 4)) * 0x10) / 8;
        tile = (arg1 / 4) + ((arg2 / 4) * (wrap / 4));
        base += tile << 6;
        value = *(unsigned short *)(base + pixel);
        return (*(unsigned short *)(base + pixel + 0x20) & ~0xFFFF0000) | (value << 16);
    }
    return 0;
}
#pragma pop
extern void DCFlushRange(void *, unsigned int);
extern unsigned int GXGetTexBufferSize(unsigned short, unsigned short, int, int, int);
extern void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, unsigned int);
extern void GXInitTexObjLOD(void *, int, int, int, int, int, float, float, float);
extern float lbl_80565018;
extern float lbl_8056501C;

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802D8C00(void *arg0, void *arg1) {
    void *obj;
    int h = *(int *)((char *)arg0 + 0x28);
    int w = *(int *)((char *)arg0 + 0x24);
    unsigned char *p;
    int fmt, size, align, lod;

    obj = fn_802D8A84(arg0, arg1);
    *(unsigned char *)((char *)obj + 0xCC) = 1;
    GXGetTexBufferSize((unsigned short)w, (unsigned short)h, 0xE, 0, 1);
    size = w * h;
    p = *(unsigned char **)(*(unsigned char **)((char *)arg0 + 0x2C) + 8);
    align = ((size >> 31) + size) >> 1;
    DCFlushRange(p, (unsigned int)align);
    fmt = *(int *)((char *)arg0 + 0x20);
    lod = (((fmt ^ 2) >> 1) - ((fmt ^ 2) & fmt)) >> 31;
    GXInitTexObj((char *)obj + 0x78, p, (unsigned short)w, (unsigned short)h, 0, 1, 1, (unsigned int)lod);
    if (lod != 0) {
        GXInitTexObjLOD((char *)obj + 0x78, 5, 1, 0, 1, 0, lbl_80565018, (float)(fmt - 1), lbl_8056501C);
    }
    fn_802D7780(obj, arg0);
    return obj;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D8D1C(void) {
    int offset;
    int i;

    lbl_8055FE24 = 0;
    lbl_8055FE20 = 0;
    lbl_8055FE1C = 0;
    lbl_8055FE18 = 0;
    lbl_8055FE28 = fn_8012850C((void *)0x1ACE8, &lbl_8034C5B8);

    i = 0;
    offset = 0;
    do {
        memset((char *)lbl_8055FE28 + offset, 0, 0xF4);
        i++;
        offset += 0xF4;
    } while (i < 0x1C2);
}
#pragma pop

