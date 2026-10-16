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
    if (*(int *)((char *)&lbl_804B34B0 + 0x100) > 0) {
        fn_8028F2EC();
        lbl_8055F740 = lbl_804B34B0;
    }
    lbl_8055F744 = 0;
}

void fn_8028E070(float farg0) {
    lbl_8055F738 = farg0;
    lbl_8055F73C = 1;
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

extern int fn_8002B1D8(int, void *, int);
extern char *strncpy(char *, const char *, unsigned int);
void fn_8028EEB4(void *arg0, int arg1, const char *arg2) {
    char *p = (char *)arg0 + *(int *)((char *)arg0 + 0x600) * 0x18;
    strncpy(p, arg2, 0x10);
    p[0xF] = 0;
    *(int *)(p + 0x10) = arg1;
    *(int *)(p + 0x14) = 1;
    (*(int *)((char *)arg0 + 0x600))++;
}

int fn_8028EF44(unsigned int *arg0, unsigned int arg1) {
    unsigned int *p = (unsigned int *)((char *)arg0 + 0x10);
    int i = 0;
    int count = *(int *)((char *)arg0 + 0x600);
    while (i < count) {
        if (*p == arg1) {
            int *q = (int *)((char *)arg0 + i * 0x18 + 0x14);
            *q -= 1;
            return *q == 0;
        }
        p = (unsigned int *)((char *)p + 0x18);
        i++;
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
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
#pragma dont_inline reset
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028F2EC(void);
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
