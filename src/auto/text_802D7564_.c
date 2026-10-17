// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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

void fn_802D8DA0(void) {
    fn_80128670(lbl_8055FE28);
    lbl_8055FE28 = 0;
}

void fn_802D9154(void) {
    fn_802D7600(lbl_8055D118);
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
    register int zero;
    void *obj;
    unsigned int s, t;
    fn_802D2614();
    obj = (char *)lbl_8055FE24 + 0x24;
    s = GXGetTexObjWrapS(obj) & 0xFFFF;
    t = GXGetTexObjWrapT(obj) & 0xFFFF;
    zero = 0;
    GXSetTexCopySrc(zero, zero, s, t);
    GXSetTexCopyDst(s, t, GXGetTexObjMipMap(obj), zero);
    GXSetZMode(1, 7, 1);
    GXSetColorUpdate(1);
    GXCopyTex(GXGetTexObjFmt(obj), 1);
    lbl_8055FE24 = zero;
    fn_802CFF50();
}

extern void *lbl_8055FE28;
extern void *lbl_8034C5B8;
extern void *lbl_8034C4B0;
extern void fn_8012850C(void *, void *);
void* fn_802D94DC(void) {
    return lbl_8055FE18;
}
