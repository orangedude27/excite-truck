// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E9B0;
extern int lbl_80486F18[5];
extern int lbl_8055E9B8;
extern void fn_8000D838(void *);
void fn_801DE798(void) {
    fn_8000D838(&lbl_8055E9B0);
    *(int *)&lbl_80486F18 = 0;
    *((int *)&lbl_80486F18 + 1) = 0x7B;
    *((int *)&lbl_80486F18 + 2) = 0;
    *((int *)&lbl_80486F18 + 3) = 0;
    *((int *)&lbl_80486F18 + 4) = 0;
    lbl_8055E9B8 = 0x7F000000;
}
