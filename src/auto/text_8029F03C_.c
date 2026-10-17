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
void fn_8029F458(unsigned char *arg0, int arg1) {
    unsigned char buf[0x20];
    unsigned char *src = arg0;
    unsigned char *dst = buf;
    int id, i;
    if (*src == '$') src++;
    for (i = 0; i < 0x20; i++) {
        unsigned char c = *src++;
        *dst++ = c;
        if ((signed char)c == 0) break;
    }
    if (i == 0x20) dst[-1] = 0;
    id = fn_8029F3BC(buf);
    for (i = 0; i < lbl_804B9B7C[1]; i++) {
        if (lbl_804B9B7C[0] /* placeholder */) {}
        if (*(int *)((unsigned char *)lbl_804B9B7C + i * 0x34) == id)
            *(int *)((unsigned char *)lbl_804B9B7C + i * 0x34 + 0x30) = arg1;
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
