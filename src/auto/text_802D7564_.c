// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FE18;
extern char lbl_8055D118[4];
extern void *fn_802D7600(void *queue);
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

extern void fn_802D768C(void);
extern void fn_802D2614(void);
extern int lbl_8055FE24;
void fn_802D93E8(int arg0) {
    fn_802D2614();
    lbl_8055FE24 = arg0;
}

extern void *lbl_8055FE28;
extern void *lbl_8034C5B8;
extern void *lbl_8034C4B0;
extern void fn_8012850C(void *, void *);
void* fn_802D94DC(void) {
    return lbl_8055FE18;
}
