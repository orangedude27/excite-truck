// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef long s32;
typedef unsigned long u32;
extern void** fn_801284F8(s32, void*);
extern void *lbl_8032C4F0;
extern void *lbl_8032C500;
extern long fn_80128668(void);

void fn_8013C9F4(long arg0) {
    void *temp;
    void **temp_r3;

    if (arg0 == 0) {
        temp = lbl_8032C4F0;
        temp_r3 = fn_801284F8(4, temp);
        if (temp_r3 != (void**)0) {
            *temp_r3 = lbl_8032C500;
        }
    }
}

void fn_8013CA3C(void) {

}

long fn_8013CA40(long arg0, long arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

long fn_8013CA80(void) {
    return 0;
}

long fn_8013CA88(void) {
    return 1;
}

long fn_8013CA90(void) {
    return 0;
}

long fn_8013CA98(void) {
    return 0;
}

void fn_8013CAA0(void) {

}

void fn_8013CAA4(void) {

}

void fn_8013CAA8(void) {

}

long fn_8013CAAC(void) {
    return 0;
}

