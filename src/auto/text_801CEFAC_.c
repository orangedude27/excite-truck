// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055AB50;
extern char lbl_8055E8A0;
extern char lbl_8055E8A1;
void fn_801CEFAC(void) {
    lbl_8055AB50 = 1;
    lbl_8055E8A0 = 0;
    lbl_8055E8A1 = 1;
}

void fn_801CEFC4(void) {
    lbl_8055AB50 = 0;
    lbl_8055E8A0 = 0;
}

extern char lbl_8033807C[];
extern char lbl_80338060[];
extern void fn_802E30C8(char *, ...);
#pragma scheduling invalid_target
void fn_801CEFE8(void) {
    fn_802E30C8(lbl_80338060);
    lbl_8055E8A0 = 1;
}
#pragma scheduling on
void fn_801CF01C(void) {
    char *fmt;
    fmt = lbl_8033807C;
    fn_802E30C8(fmt);
    lbl_8055E8A0 = 0;
}

#pragma scheduling on
extern void fn_801AED68(void);
extern void fn_801AED5C(void);
int fn_801CF050(void) {
    return *(unsigned char *)&lbl_8055AB50 != 0;
}

int fn_801CF064(void) {
    return *(unsigned char *)&lbl_8055E8A0 != 0;
}

