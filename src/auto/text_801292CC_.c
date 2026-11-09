// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055DFA8;
extern float lbl_80561238, lbl_8056123C, lbl_80561240;
extern char lbl_8032A588[0x14], lbl_8032A59C, lbl_80559978;
extern int fn_802E765C(int,int,int);
extern int fn_802E7684(float);
extern int fn_802E30C8(const char *, ...);
extern int fn_802E75FC(int);
extern int fn_802E75E4(const char *);
extern int sprintf(char *, const char *, ...);
#pragma scheduling invalid_target
void fn_801292CC(int arg0) {
    char sp8[8];
    int sp30;
    fn_802E30C8((const char *)(void *)&lbl_8032A588, (const char *)(void *)&lbl_8032A588[0x10]);
    sprintf(sp8, (const char *)(void *)&lbl_80559978, arg0);
    lbl_8055DFA8 = fn_802E75E4(sp8);
    sp30 = 0;
    (void)sp30;
}
#pragma scheduling on

void fn_80129324(void) {
    int dummy = lbl_8032A59C;
    fn_802E30C8((const char *)(void *)&lbl_8032A59C);
    fn_802E75FC(lbl_8055DFA8);
    lbl_8055DFA8 = 0;
    (void)dummy;
}

void fn_80129360(int a, int b) { fn_802E765C(lbl_8055DFA8,a,b); }

void fn_80129374(int arg0, int arg1) {
    float v;
    if (arg0 == 1)
        v = lbl_80561238;
    else
        v = lbl_8056123C;
    if (arg1 != 0)
        fn_802E7684(v);
    else
        fn_802E7684(lbl_80561240);
}

