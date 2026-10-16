// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_801C1218(int);
extern void fn_801C1364(int);
extern void fn_801C1320(int);
extern int fn_801284F8(int, int *);
extern int fn_801C109C(int, int, int, int);
extern int fn_80128668(int);
extern int lbl_8055A950;
extern "C" int __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(int);
void fn_801C1B60(int arg0) {
    fn_801C1218(arg0);
    fn_801C1364(arg0);
    fn_801C1320(arg0);
}

void fn_801C1B9C(void) {
    return;
}

void fn_801C1BA0(void) {
    return;
}

int fn_801C1BA4(int arg0, int arg1, int arg2) {
    int result = fn_801284F8(0x70, &lbl_8055A950);
    if (result != 0) {
        fn_801C109C(arg0, arg1, arg2, 0);
    }
    return result;
}

int fn_801C1C1C(void *arg0) {
    int result = fn_801284F8(0x70, &lbl_8055A950);
    if (result != 0) {
        fn_801C109C(*(int *)((char *)arg0 + 0x10),
                    *(int *)((char *)arg0 + 0x14),
                    *(int *)((char *)arg0 + 0x18),
                    *(int *)((char *)arg0 + 0x1C));
    }
    return result;
}

void fn_801C1C7C(void *arg0) {
    if (arg0 != 0) {
        __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(0);
        fn_80128668((int)arg0);
    }
}

