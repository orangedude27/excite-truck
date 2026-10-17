// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_804B5070[];
extern int lbl_8055F81C;
extern unsigned char lbl_804B6E70[];
extern int fn_800241DC(int *, void *, int, int, void *);
extern int stricmp(const char *, const char *);
extern int fn_8029FDF0(int *, int *);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));

extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern int fn_8028E3F4(void);
extern int fn_802929F8(void);
extern int fn_8029F3BC(unsigned char *);
extern int lbl_8034983C;
extern int lbl_80349848;
extern int lbl_804B9B7C[];
extern float lbl_805646B4;
extern int lbl_8055CAE8;
extern int lbl_8055F820;
extern int fn_80128670(void);
extern int fn_801EF024(void *);
extern void fn_8029FDDC(void);
extern void fn_8029FFBC(void);
extern void fn_802A0720(void);
extern void fn_802A0620(void);
extern void fn_802A002C(void);
extern int fn_801E85A4(void);
extern void fn_8029FEF8(void);
extern void fn_8029FE00(void);
extern void fn_8029FD04(void);
extern int fn_801E85AC(void);
extern int fn_8012850C(int, void *);
extern int fn_801EEFDC(void *, int);
extern int lbl_80349810;
extern unsigned char lbl_804B7770[];
extern int lbl_8055F818;
extern void *memset(void *, int, unsigned int);
extern void fn_802029FC(void);
extern void fn_802C92D0(void);
extern void fn_802C92D8(void);
extern void fn_801E88B4(int *, int *, int *, int *, int);
extern void fn_802C92DC(int, int, int, int, int);
void fn_8029F03C(void) {
    lbl_8055F81C = 0;
    lbl_8055F818 = 0;
    memset(lbl_804B7770, 0, 0x2400);
    memset(lbl_804B6E70, 0, 0x900);
    fn_8029FEF8();
    fn_8029FE00();
    fn_8029FD04();
    fn_801EEFDC(&fn_802A0620, 10);
    fn_801EEFDC(&fn_802A0720, 11);
    lbl_8055F820 = fn_8012850C(fn_801E85AC() * 4, &lbl_80349810);
}

void fn_8029F0D0(void) {
    if (lbl_8055F820 != 0) {
        fn_80128670();
    }
    lbl_8055F820 = 0;
    fn_801EF024(&fn_802A0720);
    fn_801EF024(&fn_802A0620);
    fn_8029FDDC();
    fn_8029FFBC();
}

void fn_8029F124(void) {
    int i = 0;
    int offset = 0;
    int zero = 0;
    fn_802A002C();
    do {
        i++;
        *(int *)((unsigned char *)lbl_8055F820 + offset) = zero;
        offset += 4;
    } while (i < fn_801E85A4());
}

void fn_8029F300(void) {
    int i = 0;
    int offset = 0;
    int zero = 0;
    int a, b, c, d;
    fn_802029FC();
    do {
        if (fn_801E85A4() == 1) {
            fn_802C92D0();
            if (((unsigned int)*(int *)((unsigned char *)lbl_8055F820 + offset) >> 24) != 0) {
                fn_801E88B4(&a, &b, &c, &d, i);
                fn_802C92DC(a, b, c, d, *(int *)((unsigned char *)lbl_8055F820 + offset));
                fn_802C92D8();
            }
        }
        i++;
        *(int *)((unsigned char *)lbl_8055F820 + offset) = zero;
        offset += 4;
    } while (i < fn_801E85A4());
}

int fn_8029F3BC(unsigned char *arg0) {
    int i = 0;
    unsigned char *current = lbl_804B6E70;
    while (i < lbl_804B9B7C[1]) {
        if (stricmp((const char *)current, (const char *)arg0) == 0)
            return *(int *)(current + 0x20);
        current += 0x24;
        i++;
    }
    return -1;
}

void fn_8029F458(unsigned char *arg0, int arg1) {
    unsigned char buf[0x20];
    unsigned char *src = arg0;
    unsigned char *dst = buf;
    int id;
    int i;
    if (*src == '$') src++;
    for (i = 0; i < 0x20; i++) {
        unsigned char c = *src++;
        *dst++ = c;
        if ((signed char)c == 0) break;
    }
    if (i == 0x20) dst[-1] = 0;
    id = fn_8029F3BC(buf);
    for (i = 0; i < lbl_804B9B7C[1]; i++) {
        unsigned char *base = (unsigned char *)lbl_804B9B7C[0];
        if (*(int *)(base + i * 0x34) == id)
            *(int *)(base + i * 0x34 + 0x30) = arg1;
    }
}

unsigned char fn_8029F510(unsigned char *arg0, int arg1) {
    if (arg1 != 0) {
        *arg0 = 1;
    } else {
        *arg0 = 0;
    }
    return *arg0;
}

void fn_8029F534(void *arg0, unsigned char *arg1) {
    if (fn_8029F510((unsigned char *)arg0, (int)arg1)) {
        void **vtable = (void **)*(void **)arg1;
        ((void (*)(unsigned char *, int *))vtable[5])(arg1, &lbl_8034983C);
        *(int *)((unsigned char *)arg0 + 4) = fn_8028E3F4();
        *(unsigned char *)((unsigned char *)arg0 + 8) =
            ((unsigned char (*)(unsigned char *, int *, int))vtable[12])(arg1, &lbl_80349848, 0);
    } else {
        *(int *)((unsigned char *)arg0 + 4) = 0;
    }
}

void fn_8029F5C8(void *arg0, unsigned char *arg1) {
    if (fn_8029F510((unsigned char *)arg0, (int)arg1)) {
        void **vtable = (void **)*(void **)arg1;
        ((void (*)(unsigned char *, int *))vtable[5])(arg1, &lbl_8034983C);
        *(int *)((unsigned char *)arg0 + 4) = fn_802929F8();
        ((float (*)(unsigned char *, int *, float))vtable[10])(arg1, &lbl_8055CAE8, lbl_805646B4);
        *(float *)((unsigned char *)arg0 + 8) = lbl_805646B4;
    } else {
        *(int *)((unsigned char *)arg0 + 4) = 0;
    }
}

int fn_8029FDF0(int *arg0, int *arg1) {
    return *arg0 - *arg1;
}

void fn_8029FE00(void) {
    int count = lbl_8055F81C;
    qsort(lbl_804B5070, count, 0x78, (int (*)(const void *, const void *))fn_8029FDF0);
}

int fn_8029FE1C(int arg0) {
    int sp8 = arg0;
    if (arg0 <= 0) return 0;
    return fn_800241DC(&sp8, lbl_804B5070, lbl_8055F81C, 0x78, fn_8029FDF0);
}

int fn_8029FE6C(const char *arg0) {
    unsigned char *current = lbl_804B6E70;
    int i = 0;
    goto check;
loop:
    if (stricmp((const char *)current, arg0) == 0)
        return *(int *)(lbl_804B6E70 + i * 0x24 + 0x20);
    current += 0x24;
    i++;
check:
    if (i < lbl_8055F81C) goto loop;
    return -1;
}
