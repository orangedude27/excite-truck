// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FB08;
extern float lbl_8055FB10;
extern float lbl_80564E4C;
int fn_8000D838(int *);
static inline void setResult(float value) { *(volatile float *)&lbl_8055FB10 = value; }
void fn_802C10E0(void) {
    volatile float *dst = (volatile float *)&lbl_8055FB10;
    fn_8000D838(&lbl_8055FB08);
    *dst = lbl_80564E4C;
}
