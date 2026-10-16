// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F6DC;
extern int lbl_8055F6E4;
extern int fn_80289554(int);
extern int fn_80289F54(int);
void fn_802889F0(void) {
    fn_80289554(lbl_8055F6DC);
    fn_80289F54(lbl_8055F6E4);
}

int fn_802894B4(int arg0) {
    fn_802896E4();
    fn_802897E0(arg0);
    fn_80289554(arg0);
    return arg0;
}

