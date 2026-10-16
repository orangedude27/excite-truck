// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F714;
extern float lbl_80558DC4;
extern float fn_801E7E24(void);
extern void fn_8028D728(void);
extern void fn_8028D4FC(void);
extern void fn_8028D4A0(void);
extern void fn_8028D25C(void);
extern int fn_8028D17C(void);
extern void fn_8028D2B4(void);
extern void fn_8028DDF0(void);
extern void fn_80287B38(void *);
void fn_8028CED8(void) {
    if (fn_8028D17C() != 0) {
        fn_8028D2B4();
        fn_80287B38(fn_8028DDF0);
        lbl_8055F714 = 1;
    }
}

void fn_8028CF18(void) {
    if (lbl_8055F714 != 0) {
        fn_8028D4A0();
        fn_8028D25C();
        lbl_8055F714 = 0;
    }
}

void fn_8028CF50(void) {
    if (lbl_8055F714 != 0) {
        fn_8028D4FC();
    }
}

void fn_8028CF64(void) {
    if (lbl_8055F714 != 0) {
        float value = __fabsf(fn_801E7E24());
        if (value >= lbl_80558DC4) {
            fn_8028D728();
        }
    }
}

extern int lbl_804B3400;
extern int lbl_8055F728;
extern void fn_802CAC54(int);
void fn_8028D25C(void) {
    int *ptr = &lbl_804B3400;
    int i = 0;
    while (i < lbl_8055F728) {
        fn_802CAC54(*ptr);
        ptr = (int *)((char *)ptr + 0x1C);
        i++;
    }
}

void fn_8028D49C(void) {
}

extern int lbl_8055F718, lbl_8055F71C, lbl_8055F720;
extern int fn_80128670(int);
void fn_8028D4A0(void) {
    fn_80128670(lbl_8055F720);
    lbl_8055F720 = 0;
    fn_80128670(lbl_8055F71C);
    lbl_8055F71C = 0;
    if (lbl_8055F718 != 0) {
        fn_80128670(lbl_8055F718 - 0x10);
    }
    lbl_8055F718 = 0;
}

