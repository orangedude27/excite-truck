// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_801E323C(void*);
extern void fn_802C6CF8(void*);
extern void fn_80128668(void*);
extern void *fn_801284F8(int, const char *);
extern void *fn_802C6FC0(void *, int, int);
extern void *fn_801E3004(void *, const char *, int);
extern void *fn_801E31D8(void *, const char *, int);
extern void fn_801E3534(void *);
extern float fn_801EF190(void);
extern char lbl_8033A380[];
typedef struct { char s0[0x10], s10[0xC], s1C[0xC], s28[0xC], s34[0xC], s40[0xC], s4C[0xC], s58[0xC], s64[0xC]; } Lbl801EF;
extern char lbl_8055B098[4];
extern char lbl_8055B0A0[4];
extern char lbl_8055B0A8[4];
extern char lbl_8055B0B0[4];
extern float lbl_80562EE8;
extern float lbl_80562EEC;
void **fn_801EF1F0(void **arg0, void *arg1) {
    char *labels = lbl_8033A380;
    *arg0 = fn_801284F8(0x4C, labels);
    * (void **)*arg0 = fn_802C6FC0(arg1, 0, 0);
    *((float *)*arg0 + 9) = lbl_80562EE8;
    *((void **)*arg0 + 1) = fn_802C6FC0(labels + 0x10, 0, 0);
    *((void **)*arg0 + 10) = fn_802C6FC0(labels + 0x1C, 0, 0);
    *((void **)*arg0 + 2) = fn_801E3004(**(void ***)arg0, labels + 0x28, -1);
    *((void **)*arg0 + 3) = fn_801E3004(**(void ***)arg0, labels + 0x34, -1);
    *((void **)*arg0 + 6) = fn_801E31D8(*((void **)*arg0 + 3), lbl_8055B098, -1);
    *((void **)*arg0 + 4) = fn_801E31D8(*((void **)*arg0 + 3), lbl_8055B0A0, -1);
    *((void **)*arg0 + 5) = fn_801E3004(**(void ***)arg0, labels + 0x40, -1);
    *((void **)*arg0 + 7) = fn_801E3004(**(void ***)arg0, lbl_8055B0A8, -1);
    fn_801E3534(*((void **)*arg0 + 4));
    *((float *)*arg0 + 8) = fn_801EF190();
    *((float *)*arg0 + 18) = lbl_80562EEC;
    *((void **)*arg0 + 11) = fn_801E3004(**(void ***)arg0, labels + 0x4C, -1);
    *((void **)*arg0 + 12) = fn_801E3004(**(void ***)arg0, labels + 0x58, -1);
    *((void **)*arg0 + 15) = fn_801E31D8(*((void **)*arg0 + 12), lbl_8055B098, -1);
    *((void **)*arg0 + 13) = fn_801E31D8(*((void **)*arg0 + 12), lbl_8055B0A0, -1);
    *((void **)*arg0 + 14) = fn_801E3004(**(void ***)arg0, labels + 0x64, -1);
    *((void **)*arg0 + 16) = fn_801E3004(**(void ***)arg0, lbl_8055B0B0, -1);
    fn_801E3534(*((void **)*arg0 + 13));
    *((float *)*arg0 + 17) = fn_801EF190();
    return arg0;
}

int *fn_801EF428(int *arg0, int arg1) {
    if (arg0 != 0) {
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[2]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[3]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[6]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[4]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[5]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[7]);
        fn_802C6CF8((void *)((int *)(*(volatile int *)arg0))[1]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[11]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[12]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[15]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[13]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[14]);
        fn_801E323C((void *)((int *)(*(volatile int *)arg0))[16]);
        fn_802C6CF8((void *)((int *)(*(volatile int *)arg0))[10]);
        fn_802C6CF8((void *)((int *)(*(volatile int *)arg0))[0]);
        fn_80128668((void *)*(volatile int *)arg0);
        *arg0 = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
