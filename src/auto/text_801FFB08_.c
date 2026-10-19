// Code of main that had no source file yet: decomp.wtf gave it this one.
extern int fn_801E2CCC();
extern int fn_802E30C8(const char *, ...);
extern int lbl_8055ECA8;
extern char lbl_8033B938[];
extern char lbl_804888A8[];
// split_file divides it into the game's real files (file_status shows its range).

char *fn_801FFB08(int arg1) {
    int sp8;
    if (fn_801E2CCC(&sp8) == 0) {
        fn_802E30C8(lbl_8033B938, arg1, lbl_8055ECA8);
        return lbl_804888A8;
    }
    return (char *)(sp8 + 0x24);
}

void fn_801FFB6C(void) {

}

void fn_801FFB70(void) {

}

extern int fn_801E323C(int);
extern int fn_801C1C7C(int);
extern int fn_801E598C(int);
extern int fn_802C6CF8(int);
extern int fn_80128668(void *);
void fn_8020095C(int *arg0) {
    if (arg0 != 0) {
        fn_801E323C(arg0[7]);
        fn_801E323C(arg0[8]);
        fn_801E323C(arg0[9]);
        fn_801E323C(arg0[10]);
        fn_801C1C7C(arg0[0]);
        fn_801E598C(arg0[3]);
        fn_802C6CF8(arg0[2]);
        fn_80128668(arg0);
    }
}
