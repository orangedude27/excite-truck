// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055FB60;
extern int lbl_8055FB68;
extern volatile float lbl_8055FB74;
extern float lbl_80564EB0;
extern float lbl_80564ED4;
#pragma scheduling invalid_target
void fn_802C28D8(void) {
    fn_8000D838(&lbl_8055FB60);
    lbl_8055FB68 = 0xFFFF0000;
    lbl_8055FB74 = lbl_80564ED4 * lbl_80564EB0;
}
