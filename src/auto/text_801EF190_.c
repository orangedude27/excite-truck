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
extern char lbl_8055B098[];
extern char lbl_8055B0A0[];
extern char lbl_8055B0A8[];
extern char lbl_8055B0B0[];
extern float lbl_80562EE8;
extern float lbl_80562EEC;
void **fn_801EF1F0(void **arg0, void *arg1) {
    void **out = arg0;
    void *input = arg1;
    char *labels = lbl_8033A380;

    *out = fn_801284F8(0x4C, labels);
    *(void **)*out = fn_802C6FC0(input, 0, 0);
    *((float *)*out + 9) = lbl_80562EE8;
    *((void **)*out + 1) = fn_802C6FC0(labels + 0x10, 0, 0);
    *((void **)*out + 10) = fn_802C6FC0(labels + 0x1C, 0, 0);
    *((void **)*out + 2) = fn_801E3004(**(void ***)out, labels + 0x28, -1);
    *((void **)*out + 3) = fn_801E3004(**(void ***)out, labels + 0x34, -1);
    *((void **)*out + 6) = fn_801E31D8(*((void **)*out + 3), lbl_8055B098, -1);
    *((void **)*out + 4) = fn_801E31D8(*((void **)*out + 3), lbl_8055B0A0, -1);
    *((void **)*out + 5) = fn_801E3004(**(void ***)out, labels + 0x40, -1);
    *((void **)*out + 7) = fn_801E3004(**(void ***)out, lbl_8055B0A8, -1);
    fn_801E3534(*((void **)*out + 4));
    *((float *)*out + 8) = fn_801EF190();
    *((float *)*out + 18) = lbl_80562EEC;
    *((void **)*out + 11) = fn_801E3004(**(void ***)out, labels + 0x4C, -1);
    *((void **)*out + 12) = fn_801E3004(**(void ***)out, labels + 0x58, -1);
    *((void **)*out + 15) = fn_801E31D8(*((void **)*out + 12), lbl_8055B098, -1);
    *((void **)*out + 13) = fn_801E31D8(*((void **)*out + 12), lbl_8055B0A0, -1);
    *((void **)*out + 14) = fn_801E3004(**(void ***)out, labels + 0x64, -1);
    *((void **)*out + 16) = fn_801E3004(**(void ***)out, lbl_8055B0B0, -1);
    fn_801E3534(*((void **)*out + 13));
    *((float *)*out + 17) = fn_801EF190();
    return out;
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
