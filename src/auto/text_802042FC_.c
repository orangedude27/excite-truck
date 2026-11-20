// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8000D838(void *);
extern int lbl_8055ED20;
extern int lbl_8055ED28;
extern int lbl_8055ED2C;
#pragma scheduling off
void fn_802042FC(void) {
#pragma scheduling on
    fn_8000D838(&lbl_8055ED20);
#pragma scheduling off
    lbl_8055ED2C = 0x7f000000;
#pragma scheduling on
    lbl_8055ED28 = 0xffff0000;
}
