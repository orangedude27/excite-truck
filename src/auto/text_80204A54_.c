// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void *lbl_8055ED30;
extern int lbl_80488BB8[];
extern int lbl_8055ED38;
void fn_80204A54(void) {
    int *p;
    fn_8000D838(&lbl_8055ED30);
    p = lbl_80488BB8;
    p[0] = 0;
    p[1] = 0x7b;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    lbl_8055ED38 = 0x7f000000;
}
