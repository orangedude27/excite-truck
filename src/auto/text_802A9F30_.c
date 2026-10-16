// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8028E240(int);
int fn_802C2C00(int);
int fn_802C990C(int);
void fn_802C2BB8(int *, int *, int *);
void fn_802C2B78(float, float, float);
extern int lbl_804BD7B0[4];
extern unsigned char lbl_8055F92D;
extern float lbl_805649FC;
extern float lbl_80564AAC;
void fn_8028E398(int);
void fn_80128668(void *);
extern void *lbl_8055F924;
void fn_8028E080(void);
void fn_802AB6D0(void) {}

void fn_802AB6D4(void) {
    extern int fn_80287B14(void);
    extern int fn_80287B24(int);
    extern int fn_802C86DC(void);
    extern void fn_802AAD5C(int, int, int);
    extern void fn_802AAF00(int, int, int);
    extern void fn_802AAF04(int, int, int);
    extern int lbl_8055F928;
    int count = fn_80287B14();
    int obj = fn_802C86DC();
    int i;
    for (i = 0; i < count; i++) {
        int item = fn_80287B24(i);
        int data = lbl_8055F928 + i * 0x108;
        fn_802AAD5C(obj, data, item);
        fn_802AAF00(obj, data, item);
        fn_802AAF04(obj, data, item);
    }
}

void fn_802AB9E0(void) { fn_8028E070(); }

void fn_802AB9E4(void) { fn_8028E080(); }

void fn_802ABC2C(void) {
    int *p = (int *)lbl_8055F924;
    if (p) {
        fn_8028E398(p[0]);
        fn_8028E398(p[1]);
        fn_80128668(p);
        lbl_8055F924 = 0;
    }
}

void fn_802ABE50(void) { fn_8028E240(0); }

void fn_802ABFF8(int arg0, float farg0) {
    lbl_8055F92D = fn_802C2C00(1);
    lbl_804BD7B0[0] = fn_802C990C(arg0);
    fn_802C2BB8(&lbl_804BD7B0[1], &lbl_804BD7B0[2], &lbl_804BD7B0[3]);
    fn_802C2B78(farg0, lbl_80564AAC + farg0, lbl_805649FC);
}

