// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055ED6C;
extern void fn_802CAC54(void);
extern int fn_802CAC28(const char *, int);
extern char lbl_8033BC40[];
extern int fn_801E85A4(void);
extern unsigned char fn_802C2C00(unsigned char);
extern void fn_80205D5C(void);
extern int fn_80205964(void);
extern void fn_80205850(void);
extern void fn_80205FCC(void);
extern void fn_802059C0(void);
extern int fn_801B8570(void);
extern void fn_801E866C(int);
#pragma dont_inline fn_80205964
int fn_80205964(void) {
    int i = 0;
    while (i < fn_801E85A4()) {
        fn_801E866C(i);
        if (fn_801B8570() != 0) return 1;
        ++i;
    }
    return 0;
}

void fn_802061F8(void) {
    lbl_8055ED6C = fn_802CAC28(lbl_8033BC40, 0);
}

void fn_80206228(void) {
    if (lbl_8055ED6C != -2) {
        ((void (*)(int))fn_802CAC54)(lbl_8055ED6C);
        lbl_8055ED6C = -2;
    }
}

void fn_8020625C(void) {
    unsigned char old;
    if (fn_801E85A4() > 1) {
        old = fn_802C2C00(0);
        fn_80205D5C();
        if (fn_80205964() != 0) {
            fn_80205850();
            fn_80205FCC();
        }
        fn_802059C0();
        fn_802C2C00(old);
    }
}

extern int lbl_8055ED6C;
extern void fn_802CAC54(void);
extern int fn_802CAC28(const char *, int);
extern char lbl_8033BC40[];
extern int fn_801E85A4(void);
extern unsigned char fn_802C2C00(unsigned char);
extern void fn_80205D5C(void);
extern int fn_80205964(void);
extern void fn_80205850(void);
extern void fn_80205FCC(void);
extern void fn_802059C0(void);
extern int fn_801B8570(void);
extern void fn_801E866C(int);
