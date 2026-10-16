// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E8D8;
extern int lbl_8055E8DC;
extern int lbl_80438758[];
extern void fn_80128668(void *);
void *fn_801D0B34(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            ((int *)arg0)[0] = 0;
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801D0BE4(void) {
    lbl_8055E8D8 = 0;
    lbl_8055E8DC = 0;
}

void fn_801D0BF4(void) {

}
