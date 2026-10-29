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

typedef struct {
    int v[5];
} MenuHeader;

typedef struct {
    void *label;
    int type;
    void *value;
    int flags;
    int id;
} MenuEntry;

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
#pragma scheduling invalid_target
#pragma dont_inline fn_80257FB8
void fn_8025812C(void) {
    int data[46];
    int a0, a1, a2, a3, a4;
    int b0, b2, b3, b4;
    int zero, eight, two, one, three, six, minus_one, twenty_seven;
    int bac0, c238, c240, c248, c250, b860, bab8;
    int callback, other_callback;
    int *bp;
    int result, previous, current;

    lbl_8055F368 = fn_80257FB8();
    current = fn_8000DA10();
    if (((int *)&lbl_8055F370)[1] != current) {
        int old = *(volatile int *)&lbl_8055F368;
        ((volatile int *)&lbl_8055F370)[1] = current;
        *(volatile int *)&lbl_8055F370 = old;
    }

    a0 = lbl_80498E68[0];
    bp = lbl_802FA610;
    b0 = *bp++;
    zero = 0;
    a1 = lbl_80498E68[1];
    eight = 8;
    a2 = lbl_80498E68[2];
    two = 2;
    a3 = lbl_80498E68[3];
    a4 = lbl_80498E68[4];
    callback = (int)fn_80258040;
    other_callback = (int)fn_80236914;
    b2 = bp[1];
    b3 = bp[2];
    bac0 = (int)&lbl_8055BAC0;
    c238 = (int)&lbl_8055C238;
    c240 = (int)&lbl_8055C240;
    c248 = (int)&lbl_8055C248;
    c250 = (int)&lbl_8055C250;
    one = 1;
    three = 3;
    six = 6;
    b860 = (int)&lbl_8055B860;
    minus_one = -1;
    twenty_seven = 0x1b;
    bab8 = (int)&lbl_8055BAB8;
    b4 = bp[3];

    data[8] = callback;
    data[6] = bac0;
    data[7] = eight;
    data[9] = zero;
    data[10] = zero;
    data[11] = c238;
    data[12] = zero;
    data[13] = zero;
    data[14] = zero;
    data[15] = zero;
    data[17] = zero;
    data[16] = c240;
    data[18] = zero;
    data[19] = one;
    data[20] = zero;
    data[22] = zero;
    data[21] = c248;
    data[23] = zero;
    data[24] = two;
    data[25] = zero;
    data[27] = zero;
    data[26] = c250;
    data[28] = zero;
    data[29] = three;
    data[30] = zero;
    data[32] = six;
    data[31] = b860;
    data[33] = zero;
    data[34] = minus_one;
    data[35] = twenty_seven;
    data[37] = eight;
    data[36] = bab8;
    data[38] = other_callback;
    data[39] = two;
    data[40] = zero;
    data[41] = a0;
    data[42] = a1;
    data[43] = a2;
    data[44] = a3;
    data[45] = a4;
    data[0] = b0;
    data[2] = b2;
    data[3] = b3;
    data[4] = b4;
    data[1] = (int)&data[6];

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
#pragma scheduling on
#pragma pop

