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

extern int fn_80214D04(void);
extern int lbl_8055F370;
int fn_80258104(void) {
    lbl_8055F370 = fn_80214D04();
    return 0;
}

