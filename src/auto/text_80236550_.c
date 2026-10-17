// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F0A0;
extern char lbl_8055BA00;
extern int lbl_8055F094;
extern int lbl_8055F09C;
extern float lbl_805636D0;
extern double lbl_805636D8;
extern char lbl_803408D8[];
int fn_802E2C20(void);
void fn_80236674(void);
void fn_802E30C8(const char *, ...);
void fn_802365D8(void);
#pragma dont_inline on
void fn_80236550(void) {
    if (lbl_8055F09C - lbl_8055F094 > 0x989680) {
        fn_802E30C8(lbl_803408D8);
        fn_802365D8();
    }
}

#pragma dont_inline off
float fn_8023659C(void) {
    return (float)(lbl_8055F09C - lbl_8055F094) / lbl_805636D0;
}

void fn_802365D8(void) {
    lbl_8055F094 = fn_802E2C20();
    fn_80236674();
}

void fn_80236600(void) {
    lbl_8055F0A0 = 1;
}

void fn_8023660C(void) {
    int temp;
    int value;

    lbl_8055BA00 = 0;
    if (lbl_8055F0A0 != 0) {
        value = 1;
        temp = fn_802E2C20() - lbl_8055F09C + lbl_8055F094 - 0x10;
        if (temp > 1) value = temp;
        lbl_8055F094 = value;
        lbl_8055F0A0 = 0;
    }
    fn_80236674();
}

int fn_802ECC10(void);
void fn_80236550(void);
extern int lbl_8055F094, lbl_8055F098, lbl_8055F09C;
void fn_80236674(void) {
    int time;

    if (lbl_8055F0A0 == 0) {
        fn_80236550();
        time = fn_802E2C20();
        if (fn_802ECC10() != 0) {
            lbl_8055F094 += time - lbl_8055F09C;
        }
        lbl_8055F098 = time;
        lbl_8055F09C = time;
    }
}

