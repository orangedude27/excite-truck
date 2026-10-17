// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8000D838(void *);
extern int lbl_8055E290;
extern int lbl_8055E298;
extern float lbl_8055E2A4;
extern int lbl_8055E2A8;
extern float lbl_80561800;
extern float lbl_80561804;
extern float lbl_80561808;
extern float lbl_80561828;
void fn_801606BC(void) {
    fn_8000D838(&lbl_8055E290);
    lbl_8055E298 = 0xFFFF0000;
    lbl_8055E2A4 = lbl_80561800 * lbl_80561804;
    lbl_8055E2A8 = (int)(lbl_80561828 * (lbl_80561808 / lbl_80561800)) + 1;
}
