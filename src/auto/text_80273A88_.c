// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80272354(void);
extern void fn_8002F634(void *, void *, int, int);
extern char lbl_80347364[];
extern char lbl_8049A2C8[];
extern char lbl_8049F9D8[];
extern int fn_80273B08(int, int);
extern void fn_80273978(void);
void fn_80273A88(void) {
    fn_8002F634(lbl_8049F9D8, fn_80273978, 0x1C, 0x20);
}

void fn_80273AA4(void *arg0) {
    *(int *)arg0 = 0;
    *(char **)((char *)arg0 + 0x18) = lbl_80347364;
}

int fn_80273ABC(int arg0) {
    fn_80272354();
    return arg0;
}

void fn_80273AEC(void) {
    fn_8002F634(lbl_8049A2C8, fn_80273B08, 0x60, 0xC8);
}

int fn_80273B08(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        extern int fn_80128668(void);
        fn_80128668();
    }
    return arg0;
}

void fn_80273B48(void) {
}

void fn_80273B4C(void *arg0) {
    extern void fn_80015A20(void *, float *, float, float);
    extern void fn_80015B20(void *, void *, void *);
    extern float lbl_80563FA8;
    extern float lbl_80563FAC;
    extern float lbl_80563FB0;
    extern float lbl_80563FB4;
    void *temp_r4 = *(void **)((char *)arg0 + 0x140);
    float sp10, spC, sp8;
    char sp14[0x14];
    float var_f1;
    void *temp_r3;
    if (temp_r4 != 0) {
        if (*(unsigned char *)((char *)temp_r4 + 0x260C) != 0) {
            var_f1 = lbl_80563FA8;
        } else {
            var_f1 = lbl_80563FAC;
        }
        sp8 = lbl_80563FB0;
        sp10 = lbl_80563FB0;
        spC = lbl_80563FB0 * lbl_80563FB4 * var_f1;
        fn_80015A20(sp14, &sp8, var_f1, lbl_80563FB0);
        temp_r3 = (char *)arg0 + 0x58;
        fn_80015B20(temp_r3, sp14, temp_r3);
    }
}

void fn_8027445C(void) {
    extern void fn_80274268(void);
    fn_80274268();
}

