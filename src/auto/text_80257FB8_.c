// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80161D14(void);
extern int fn_80161ECC(void);
extern void fn_80161E40(int);
extern int fn_8016208C(void);
int fn_80257FB8(void) {
    int total = fn_80161D14();
    int count = fn_80161ECC();
    int accum = 0;
    int i = 0;
    while (i < count) {
        fn_80161E40(i);
        accum += fn_8016208C();
        if (total <= accum) return i;
        i++;
    }
    return 0;
}

__declspec(section ".sdata") extern int lbl_8055F370;
extern void fn_80214CB4(int);
extern void fn_80214A9C(int);
extern void fn_80214B44(int);
extern void fn_80214AF0(int);
#pragma push
#pragma use_lmw_stmw off
void fn_80258040(void) {
    int total, count, accum, i, width;
    fn_80214CB4(lbl_8055F370);
    total = fn_80161D14();
    count = fn_80161ECC();
    accum = 0;
    for (i = 0; i < count; i++) {
        fn_80161E40(i);
        width = fn_8016208C();
        fn_80214A9C(i + 10);
        fn_80214A9C(i + 14);
        fn_80214A9C(i + 18);
        if (total <= accum) {
            fn_80214B44(i + 1);
            fn_80214AF0(i + 18);
        } else if (total > accum + width) {
            fn_80214AF0(i + 10);
        } else {
            fn_80214AF0(i + 14);
        }
        accum += width;
    }
}
#pragma pop
extern int fn_80214D04(void);
extern int lbl_8055F370;
int fn_80258104(void) {
    lbl_8055F370 = fn_80214D04();
    return 0;
}

extern int fn_8000DA10(void);
extern int fn_80161F10(int);
extern int fn_802146BC(void *, int, int, int);
extern int lbl_8055F368;
extern int lbl_80498E68[];
extern int lbl_802FA610[];
extern int lbl_8055B860, lbl_8055BAB8, lbl_8055BAC0;
extern int lbl_8055C238, lbl_8055C240, lbl_8055C248, lbl_8055C250;
extern void fn_80236914(void);
extern void fn_80258040(void);
#pragma dont_inline fn_80257FB8
void fn_8025812C(void) {
    int data[44];
    int *p = data + 4;
    int result, current, previous;
    int *a = lbl_80498E68;
    int *b = lbl_802FA610;
    lbl_8055F368 = fn_80257FB8();
    current = fn_8000DA10();
    if (lbl_8055F370 != current) {
        lbl_8055F370 = current;
        lbl_8055F368 = lbl_8055F368;
    }
    p[0] = lbl_8055BAC0; p[1] = 8; p[2] = 0; p[3] = 0;
    p[4] = 0; p[5] = lbl_8055C238; p[6] = 0; p[7] = 0;
    p[8] = 0; p[9] = 0; p[10] = lbl_8055C240; p[11] = 0;
    p[12] = 1; p[13] = 0; p[14] = 0; p[15] = lbl_8055C248;
    p[16] = 0; p[17] = 2; p[18] = 0; p[19] = 0;
    p[20] = lbl_8055C250; p[21] = 0; p[22] = 3; p[23] = 0;
    p[24] = lbl_8055B860; p[25] = 0; p[26] = -1; p[27] = 0x1b;
    p[28] = 8; p[29] = lbl_8055BAB8; p[30] = (int)fn_80236914;
    p[31] = 2; p[32] = 0;
    p[-6] = b[0]; p[-4] = b[2]; p[-3] = b[3]; p[-2] = b[4];
    p[35] = a[0]; p[36] = a[1]; p[37] = a[2]; p[38] = a[3]; p[39] = a[4];
    do {
        result = fn_802146BC(p - 6, -999, -999, 1);
        previous = fn_80257FB8();
        if (result != -1) fn_80161F10(result);
        current = fn_80257FB8();
        if (current != previous) lbl_8055F370 = current;
    } while (result != -1);
}

