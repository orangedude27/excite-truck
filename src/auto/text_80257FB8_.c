// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80161D14(void);
extern int fn_80161ECC(void);
extern void fn_80161E40(int);
extern int fn_8016208C(void);
#pragma dont_inline on
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
#pragma dont_inline reset

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
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline fn_80257FB8
void fn_8025812C(void) {
    int data[46];
    int result, previous, current;

    lbl_8055F368 = fn_80257FB8();
    current = fn_8000DA10();
    if (((int *)&lbl_8055F370)[1] != current) {
        int old = *(volatile int *)&lbl_8055F368;
        ((volatile int *)&lbl_8055F370)[1] = current;
        *(volatile int *)&lbl_8055F370 = old;
    }

    data[6] = (int)&lbl_8055BAC0; data[7] = 8; data[8] = (int)fn_80258040; data[9] = 0;
    data[10] = 0; data[11] = (int)&lbl_8055C238; data[12] = 0; data[13] = 0;
    data[14] = 0; data[15] = 0; data[16] = (int)&lbl_8055C240; data[17] = 0;
    data[18] = 0; data[19] = 1; data[20] = 0; data[21] = (int)&lbl_8055C248;
    data[22] = 0; data[23] = 0; data[24] = 2; data[25] = 0;
    data[26] = (int)&lbl_8055C250; data[27] = 0; data[28] = 0; data[29] = 3;
    data[30] = 0; data[31] = (int)&lbl_8055B860; data[32] = 6; data[33] = 0;
    data[34] = -1; data[35] = 0x1b; data[36] = (int)&lbl_8055BAB8; data[37] = 8;
    data[38] = (int)fn_80236914; data[39] = 2; data[40] = 0;
    data[41] = lbl_80498E68[0]; data[42] = lbl_80498E68[1]; data[43] = lbl_80498E68[2];
    data[44] = lbl_80498E68[3]; data[45] = lbl_80498E68[4];
    data[0] = lbl_802FA610[0]; data[1] = (int)&data[6]; data[2] = lbl_802FA610[2];
    data[3] = lbl_802FA610[3]; data[4] = lbl_802FA610[4];

    do {
        result = fn_802146BC(data, -999, -999, 1);
        previous = fn_80257FB8();
        if (result != -1) {
            fn_80161F10(result);
            current = fn_80257FB8();
            if (current != previous) lbl_8055F370 = current;
        }
    } while (result != -1);
}
#pragma pop

