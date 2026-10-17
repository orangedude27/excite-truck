// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_802F9D68;
extern int lbl_8033BBA0;
extern int lbl_8055B468;
extern int lbl_8055B470;
extern int lbl_8055B478;
extern signed char lbl_8055ED58;
extern int stricmp(const char *, const char *);
extern void fn_802E317C(const char *, const char *);
extern void *fn_8001285C(void);
extern void fn_80131818(int);
extern void fn_80128668(void *);
int *fn_80204AA4(void) {
    int value = *(int *)((char *)fn_8001285C() + 8);
    switch (value) {
    case 0x180302: return &lbl_8055B468;
    case 0x180201: return &lbl_8055B470;
    case 0x180303: return &lbl_8055B478;
    default: return 0;
    }
}

void *fn_80204B18(int arg0) {
    return (char *)&lbl_802F9D68 + arg0 * 0xC;
}

void fn_80204BB4(void) {
    fn_80204B2C();
}

extern int *lbl_8055ED5C;
int fn_80204CF0(void) {
    return *lbl_8055ED5C;
}

void fn_80205208(void) {
    int *p = lbl_8055ED5C;
    lbl_8055ED58 = 0;
    if (p != 0) {
        p[4] = 0;
        p[2] = 0;
        p[3] = 0;
        fn_80131818(p[1]);
        p[1] = 0;
        fn_80128668(p);
    }
}

