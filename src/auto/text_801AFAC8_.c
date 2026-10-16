// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E640;
extern int fn_80128670(int);
void fn_801AFBE8(void) {
    if (lbl_8055E640 != 0) {
        fn_80128670(lbl_8055E640 - 0x10);
    }
    lbl_8055E640 = 0;
}
