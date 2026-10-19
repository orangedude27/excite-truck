// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void *lbl_8034C4B0;
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
extern char lbl_8055D118[4];
extern void *fn_802D7600(void *queue);
void fn_802D7564(void) {
    int i;
    char *p = (char *)lbl_8055FE28;
    fn_802E30C8(lbl_8034C460);
    for (i = 0; i < 0x1C2; i++, p += 0xF4) {
        if (p[0x20]) {
            unsigned short t = GXGetTexObjWrapT(p + 0x24);
            unsigned short s = GXGetTexObjWrapS(p + 0x24);
            fn_802E30C8(lbl_8034C47C, i, p, s, t);
        }
    }
}

int fn_802D76DC(int arg0) {
    if (arg0 == 0x43) goto ret_one;
    if (arg0 < 0x43) {
        if (arg0 == 3) goto ret_one;
        if (arg0 < 3) {
            if (arg0 >= 2) goto ret_zero;
            goto call_path;
        }
        if (arg0 < 0x42) {
            if (arg0 >= 0x40) goto ret_one;
            goto call_path;
        }
        goto ret_zero;
    }
    if (arg0 >= 0x4A) {
        if (arg0 == 0x4C) goto ret_zero;
        if (arg0 < 0x4C) goto ret_one;
        goto call_path;
    }
    if (arg0 >= 0x48) goto ret_zero;
    if (arg0 >= 0x46) goto ret_one;
    goto ret_zero;
ret_one:
    return 1;
ret_zero:
    return 0;
call_path:
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
#pragma dont_inline reset

void fn_802D8DA0(void) {
    fn_80128670(lbl_8055FE28);
    lbl_8055FE28 = 0;
}

extern void fn_802D81C4(void *, int);
extern void fn_802D86BC(void *, int);
void fn_802D8DCC(void *arg0, int arg1) { unsigned int kind; unsigned char t; unsigned char *p = *(unsigned char **)((char *)arg0 + 0x2C); t=p[0]; p[0]=p[3]; p[3]=t; t=p[1]; p[1]=p[2]; p[2]=t; if (*(int *)(p+0) != 0) *(unsigned char **)(p+0) = p + *(int *)(p+0); t=p[4]; p[4]=p[7]; p[7]=t; t=p[5]; p[5]=p[6]; p[6]=t; if (*(int *)(p+4) != 0) *(unsigned char **)(p+4) = p + *(int *)(p+4); t=p[8]; p[8]=p[11]; p[11]=t; t=p[9]; p[9]=p[10]; p[10]=t; if (*(int *)(p+8) != 0) *(unsigned char **)(p+8) = p + *(int *)(p+8); kind=*(unsigned int *)arg0; if (kind == 0x40 || kind == 0) fn_802D81C4(arg0,arg1); else if (kind == 0x41 || kind == 1) fn_802D86BC(arg0,arg1); }

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
extern void fn_802D9230(void *);
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

extern void fn_802D768C(void);
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

extern void *lbl_8055FE28;
extern void *lbl_8034C5B8;
extern void *lbl_8034C4B0;
extern void *fn_8012850C(void *, void *);
void* fn_802D94DC(void) {
    return lbl_8055FE18;
}
