// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_80498860[];
extern int lbl_8055F218;
extern int lbl_8055F220;
void fn_8024492C(void) {
    fn_8000D838(&lbl_8055F218);
    ((int *)&lbl_80498860)[0] = 0;
    ((int *)&lbl_80498860)[1] = 0x7B;
    ((int *)&lbl_80498860)[2] = 0;
    ((int *)&lbl_80498860)[3] = 0;
    ((int *)&lbl_80498860)[4] = 0;
    lbl_8055F220 = 0x7F000000;
}
