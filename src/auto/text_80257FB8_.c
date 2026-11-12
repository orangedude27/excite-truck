// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80161D14(void);
extern int fn_80161ECC(void);
extern void fn_80161E40(int);
extern int fn_8016208C(void);
#pragma use_lmw_stmw off
int fn_80257FB8(void) {
    register int total asm("r30");
    register int count asm("r31");
    register int accum asm("r29");
    register int i asm("r28");
    total = fn_80161D14();
    count = fn_80161ECC();
    accum = 0;
    i = 0;
    while (i < count) {
        fn_80161E40(i);
        accum += fn_8016208C();
        if (total <= accum)
            return i;
        i++;
    }
    return 0;
}
#pragma use_lmw_stmw reset

__declspec(section ".sdata") extern int lbl_8055F370;
extern void fn_80214CB4(int);
extern void fn_80214A9C(int);
extern void fn_80214B44(int);
extern void fn_80214AF0(int);
#pragma push
#pragma use_lmw_stmw off
void fn_80258040(void) {
    /* Update per-track UI elements based on the current playback position/width progress. */
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

typedef struct {
    MenuHeader header;
    int pad;
    MenuEntry entries[7];
    MenuHeader footer;
} MenuArgs;

extern int fn_8000DA10(void);
extern int fn_80161F10(int);
extern int fn_802146BC(void *, int, int, int);
extern int lbl_8055F368;
extern MenuHeader lbl_80498E68;
extern MenuHeader lbl_802FA610;
extern int lbl_8055B860, lbl_8055BAB8, lbl_8055BAC0;
extern int lbl_8055C238, lbl_8055C240, lbl_8055C248, lbl_8055C250;
extern void fn_80236914(void);
extern void fn_80258040(void);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline fn_80257FB8
void fn_8025812C(void) {
    MenuArgs args;
    int temp_r18, temp_r31, temp_r3, temp_r3_2;

    lbl_8055F368 = fn_80257FB8();
    temp_r3 = fn_8000DA10();
    if (((int *)&lbl_8055F370)[1] != temp_r3) {
        int old = *(volatile int *)&lbl_8055F368;
        ((volatile int *)&lbl_8055F370)[1] = temp_r3;
        *(volatile int *)&lbl_8055F370 = old;
    }

    args.entries[0].label = &lbl_8055BAC0;
    args.entries[0].type = 8;
    args.entries[0].value = (void *)fn_80258040;
    args.entries[0].flags = 0;
    args.entries[0].id = 0;

    args.entries[1].label = &lbl_8055C238;
    args.entries[1].type = 0;
    args.entries[1].value = 0;
    args.entries[1].flags = 0;
    args.entries[1].id = 0;

    args.entries[2].label = &lbl_8055C240;
    args.entries[2].type = 0;
    args.entries[2].value = 0;
    args.entries[2].flags = 1;
    args.entries[2].id = 0;

    args.entries[3].label = &lbl_8055C248;
    args.entries[3].type = 0;
    args.entries[3].value = 0;
    args.entries[3].flags = 2;
    args.entries[3].id = 0;

    args.entries[4].label = &lbl_8055C250;
    args.entries[4].type = 0;
    args.entries[4].value = 0;
    args.entries[4].flags = 3;
    args.entries[4].id = 0;

    args.entries[5].label = &lbl_8055B860;
    args.entries[5].type = 6;
    args.entries[5].value = 0;
    args.entries[5].flags = -1;
    args.entries[5].id = 0x1b;

    args.entries[6].label = &lbl_8055BAB8;
    args.entries[6].type = 8;
    args.entries[6].value = (void *)fn_80236914;
    args.entries[6].flags = 2;
    args.entries[6].id = 0;

    args.footer = *(MenuHeader *)(void *)&lbl_80498E68;
    args.header = *(MenuHeader *)(void *)&lbl_802FA610;
    args.header.v[1] = (int)args.entries;

    do {
        temp_r18 = fn_802146BC(&args.header, -999, -999, 1);
        temp_r31 = fn_80257FB8();
        if (temp_r18 != -1) {
            fn_80161F10(temp_r18);
            temp_r3_2 = fn_80257FB8();
            if (temp_r3_2 != temp_r31) *(int *)&lbl_8055F370 = temp_r3_2;
        }
    } while (temp_r18 != -1);
}
#pragma scheduling on
#pragma pop

