// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_80207848(int, int);
extern float lbl_8055C4F8;
extern void fn_8026B260(void);
extern void fn_801331C4(int, void *, float *);
extern void fn_8026B11C(void **, void *);
extern unsigned char lbl_80346988[];
extern int lbl_8055F4D0, lbl_8055F4CC, lbl_8055F4C8;
extern float lbl_80563D68;
extern unsigned char lbl_8055C4FC[], lbl_8055C500[], lbl_8049A028[];
void fn_8026B118(void) {}

extern int lbl_8055F4D0, lbl_8055F4CC;
#pragma dont_inline on
void fn_8026B11C(void **arg0, void *arg1) {
    float value = lbl_8055C4F8;
    void *obj = fn_80207848((int)arg1, 0);
    *arg0 = obj;
    if (obj != 0 && value != *(float *)((unsigned char *)obj + 8)) {
        *((unsigned char *)obj + 0x4D) = 1;
        *(float *)((unsigned char *)obj + 8) = value;
    }
}
void fn_8026B1D0(void *obj) {
    float a, b;
    void *dst = lbl_8049A028 + lbl_8055F4C8 * 0xC;
    a = ((float (*)(void *, void *))(*(void ***)obj)[0x3C/4])(obj, lbl_8055C4FC);
    b = ((float (*)(void *, void *, float, float))(*(void ***)obj)[0x28/4])(obj, lbl_8055C500, lbl_80563D68, a);
    *(float *)dst = a;
    *(float *)((unsigned char *)dst + 4) = a;
    *(float *)((unsigned char *)dst + 8) = b;
}

void fn_8026B644(void) {
    fn_8026B260();
    fn_801331C4(4, lbl_80346988 + 0xA0, &lbl_8055C4F8);
    fn_8026B11C((void **)&lbl_8055F4D0, lbl_80346988 + 0xB0);
    fn_8026B11C((void **)&lbl_8055F4CC, lbl_80346988 + 0xBC);
}

extern unsigned char lbl_8049A0E8[];
extern int lbl_8055F4C8;
extern int lbl_8055F4CC, lbl_8055F4D0;
extern void *memset(void *, int, unsigned int);
extern int fn_801B2F24(void);
extern void fn_8026B3D4(int);
extern void deleteThreads__6SystemFv_8026B178(void *);
void fn_8026B6D0(void) {
    void *p = lbl_8049A0E8;
    memset(p, 0, 0x80);
}

void fn_8026B6E4(void) {
    int i;
    if (lbl_8055F4C8 > 0) {
        i = 0;
        for (;;) {
            fn_8026B3D4(i);
            ++i;
            if (i >= fn_801B2F24()) return;
        }
    }
}

int fn_8026B734(int arg0, float *arg1) {
    if (lbl_8049A0E8[arg0 << 4]) {
        unsigned char *p = lbl_8049A0E8 + (arg0 << 4);
        *arg1 = *(float *)(p + 8);
        return 1;
    }
    return 0;
}

void fn_8026A1F0(int, int);
unsigned char fn_8026B7B4(int arg0) {
    return lbl_8049A0E8[arg0 * 0x10];
}

