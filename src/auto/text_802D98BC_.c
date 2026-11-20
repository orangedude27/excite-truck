// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern char lbl_8055FE08;
extern short lbl_8055FE10;
extern short lbl_8055FE12;
extern short lbl_8055FE14;
void fn_802D98BC(void) {
    fn_8000D838(&lbl_8055FE08);
    lbl_8055FE10 = 0x100;
    {
        short *p = &lbl_8055FE14;
        *p = 0x401;
        *(p - 1) = 0x405;
    }
}
