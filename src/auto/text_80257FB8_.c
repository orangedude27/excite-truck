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
#pragma scheduling invalid_target
#pragma dont_inline fn_80257FB8
void fn_8025812C(void) {
    union Word {
        int value;
        void *pointer;
        void (*function)(void);
    };
    struct Descriptors {
        union Word word[40];
    };
    struct Param {
        int first;
        struct Descriptors *items;
        int second;
        int third;
        int fourth;
        int reserved;
        struct Descriptors descriptors;
    } data;
    int zero = 0;
    int result, previous, current;

    lbl_8055F368 = fn_80257FB8();
    current = fn_8000DA10();
    if (((int *)&lbl_8055F370)[1] != current) {
        int old = *(volatile int *)&lbl_8055F368;
        ((volatile int *)&lbl_8055F370)[1] = current;
        *(volatile int *)&lbl_8055F370 = old;
    }

    data.descriptors.word[35].value = lbl_80498E68[0];
    data.first = lbl_802FA610[0];
    data.descriptors.word[0].function = fn_80258040;
    data.descriptors.word[1].pointer = &lbl_8055BAC0;
    data.descriptors.word[2].value = 8;
    data.descriptors.word[3].value = zero;
    data.descriptors.word[4].value = zero;
    data.descriptors.word[5].pointer = &lbl_8055C238;
    data.descriptors.word[36].value = lbl_80498E68[1];
    data.descriptors.word[6].value = zero;
    data.descriptors.word[7].value = zero;
    data.descriptors.word[8].value = zero;
    data.descriptors.word[9].value = zero;
    data.descriptors.word[10].pointer = &lbl_8055C240;
    data.descriptors.word[37].value = lbl_80498E68[2];
    data.descriptors.word[11].value = zero;
    data.descriptors.word[12].value = zero;
    data.descriptors.word[13].value = 1;
    data.descriptors.word[14].value = zero;
    data.descriptors.word[15].pointer = &lbl_8055C248;
    data.descriptors.word[38].value = lbl_80498E68[3];
    data.descriptors.word[16].value = zero;
    data.descriptors.word[17].value = zero;
    data.descriptors.word[18].value = 2;
    data.descriptors.word[19].value = zero;
    data.descriptors.word[20].pointer = &lbl_8055C250;
    data.descriptors.word[39].value = lbl_80498E68[4];
    data.descriptors.word[21].value = zero;
    data.descriptors.word[22].value = zero;
    data.descriptors.word[23].value = 3;
    data.descriptors.word[24].value = zero;
    data.descriptors.word[25].pointer = &lbl_8055B860;
    data.descriptors.word[26].value = 6;
    data.descriptors.word[27].value = zero;
    data.descriptors.word[28].value = -1;
    data.descriptors.word[29].value = 0x1b;
    data.descriptors.word[30].pointer = &lbl_8055BAB8;
    data.descriptors.word[31].value = 8;
    data.descriptors.word[32].function = fn_80236914;
    data.descriptors.word[33].value = 2;
    data.descriptors.word[34].value = zero;
    data.second = lbl_802FA610[2];
    data.third = lbl_802FA610[3];
    data.fourth = lbl_802FA610[4];
    data.items = &data.descriptors;

    do {
        result = fn_802146BC(&data, -999, -999, 1);
        previous = fn_80257FB8();
        if (result != -1) {
            fn_80161F10(result);
            current = fn_80257FB8();
            if (current != previous) lbl_8055F370 = current;
        }
    } while (result != -1);
}
#pragma pop

