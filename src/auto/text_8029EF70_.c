// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8029EFF0(int);
extern int fn_802CAC54(int);
extern int fn_802CAC28(const char *, int);
extern int fn_802E30C8(const char *, ...);
extern int lbl_8055CAE0;
extern char lbl_803497D8[];
extern char lbl_803497E8[];
void fn_8029EFBC(void) {
    if (fn_8029EFF0(lbl_8055CAE0) != 0) {
        fn_802CAC54(lbl_8055CAE0);
    }
}

int fn_8029EFF0(int arg0) {
    if (arg0 == -1) {
        return 0;
    }
    if (arg0 == -2) {
        return 0;
    }
    return 1;
}
