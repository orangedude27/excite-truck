// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80564424;
extern void fn_8028FB98(float);
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028EE28(void *);
extern void fn_8028ED80(void *);
extern void fn_8028F2EC(void);
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
void fn_8028DFB0(void) {
    int *base = &lbl_804B34B0;
    if (*(int *)((char *)base + 0x100) > 0) {
        fn_8028F2EC();
        lbl_8055F740 = *base;
    }
    lbl_8055F744 = 0;
}

extern unsigned char lbl_8055F73D;
extern float lbl_80564420;
extern int lbl_8055F748;
void fn_8028DF58(void);
void fn_8028ED74(void *);
void fn_8028EE1C(void *);
void fn_8028F8C4(int);
float fn_801E7E18(void);
void fn_8028DFFC(void) {
    fn_8028DF58();
    lbl_8055F73D = 1;
}

void fn_8028E070(float farg0) {
    lbl_8055F738 = farg0;
    lbl_8055F73C = 1;
}

void fn_8028E080(void) {
    int *entries = &lbl_804B34B0;
    int i = 0;
    lbl_8055F73C = 0;
    do {
        fn_8028F8E0(entries[i], lbl_8055F738);
        i++;
    } while (i < *(int *)((char *)&lbl_804B34B0 + 0x100));
}

void fn_8028E0F0(void) {
    fn_8028F5A4();
    fn_8028EE28((char *)&lbl_804B34B0 + 0x208);
    fn_8028ED80((char *)&lbl_804B34B0 + 0x104);
    fn_8028ED80(&lbl_804B34B0);
}

extern void fn_8028ED74(void *);
extern void fn_8028EE1C(void *);
extern void fn_8028F8C4(int);
void fn_8028E138(void) {
    int *base = &lbl_804B34B0;
    int *ptr = base;
    int count = 0;
    lbl_8055F738 = lbl_80564420;
    while (count < *(int *)((char *)base + 0x100)) {
        fn_8028F8C4(*ptr++);
        count++;
    }
}

void fn_8028E1A4(void) {
    lbl_8055F738 = fn_801E7E18();
    lbl_8055F73C = 1;
}

extern float fn_802C9A4C(float);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern int fn_8028FA1C(int);
extern int fn_801284F8(int, void *);
extern int fn_8028F7AC(int, int);
extern void fn_8028ED8C(void *, int);
extern void fn_8028F5A0(int, int);
extern int lbl_8055C8E0;
extern int lbl_804B35B4;
extern int fn_8028F858(int, int);
void fn_8028E398(int arg0) {
    if (fn_8028EDA8((unsigned int *)&lbl_804B35B4, arg0) != 0) {
        fn_8028EDA8((unsigned int *)&lbl_804B34B0, arg0);
        fn_8028F858(arg0, 1);
    }
}

void fn_8028E584(void) {
    fn_8028FB98(lbl_80564424);
}

void fn_8028ED74(void *arg0) { *(int *)((char *)arg0 + 0x100) = 0; }

void fn_8028ED80(void *arg0) { *(int *)((char *)arg0 + 0x100) = 0; }

void fn_8028ED8C(void *arg0, int arg1) {
    *(int *)((char *)arg0 + (*(int *)((char *)arg0 + 0x100) << 2)) = arg1;
    *(int *)((char *)arg0 + 0x100) = *(int *)((char *)arg0 + 0x100) + 1;
}

extern int fn_802E317C(const char *);
extern char lbl_80348F4C[];
int fn_8028EDA8(unsigned int *arg0, unsigned int arg1) {
    int i = 0;
    int count = *(int *)((char *)arg0 + 0x100);
    if (count > 0) {
        do {
            if (*arg0 == arg1) {
                arg0[i] = 0;
                return 1;
            }
            arg0 += 1;
            i += 1;
        } while (--count != 0);
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
}

void fn_8028EE1C(void *arg0) {
    *(int *)((char *)arg0 + 0x600) = 0;
}

void fn_8028EE28(void *arg0) {
    *(int *)((char *)arg0 + 0x600) = 0;
}

int fn_8028EE34(void *arg0, int arg1, int *arg2) {
    char *p = (char *)arg0;
    int i = 0;
    while (i < *(int *)((char *)arg0 + 0x600)) {
        if (fn_8002B1D8(arg1, p, 15) == 0) {
            *arg2 = i;
            return 1;
        }
        p += 0x18;
        i++;
    }
    return 0;
}

extern int fn_8002B1D8(int, void *, int);
extern char *strncpy(char *, const char *, unsigned int);
void fn_8028EEB4(void *arg0, int arg1, const char *arg2) {
    int count = *(int *)((char *)arg0 + 0x600);
    char *p = (char *)arg0 + count * 0x18;
    strncpy(p, arg2, 16);
    p = (char *)arg0 + *(int *)((char *)arg0 + 0x600) * 0x18;
    p[0xF] = 0;
    p = (char *)arg0 + *(int *)((char *)arg0 + 0x600) * 0x18;
    *(int *)(p + 0x10) = arg1;
    p = (char *)arg0 + *(int *)((char *)arg0 + 0x600) * 0x18;
    *(int *)(p + 0x14) = 1;
    (*(int *)((char *)arg0 + 0x600))++;
}

int fn_8028EF44(void *arg0, unsigned int arg1) {
    char *base = (char *)arg0;
    char *p = base;
    int i = 0;
    int count = *(int *)(base + 0x600);
    while (count > 0) {
        if (arg1 == *(unsigned int *)(p + 0x10)) {
            int *q = (int *)(base + i * 0x18 + 0x14);
            *q -= 1;
            return *q == 0;
        }
        p += 0x18;
        i++;
        count--;
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
}

extern int fn_80128668(void);
int fn_8029169C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_802916DC(void) { return 0; }

void fn_802916E4(void) {}

void fn_802916E8(void) {}

void fn_802916EC(void) {}

int fn_802916F0(void *arg0) { return ((int *)arg0)[1]; }

int fn_802916F8(void *arg0) { return *(int *)((char *)arg0 + 0x118); }

#pragma dont_inline on
void fn_80291700(void) { fn_802916E8(); }
void fn_80291704(void) { fn_802916EC(); }

void fn_80291708(void *arg0) {
    *((unsigned char *)arg0 + 0x11C) = 1;
}

void fn_80291714(void *arg0) {
    *((unsigned char *)arg0 + 0x11C) = 0;
}

unsigned char fn_80291720(void *arg0) {
    return *((unsigned char *)arg0 + 0x11C);
}

#pragma dont_inline reset
extern int lbl_8055F748;
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028F2EC(void);
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
