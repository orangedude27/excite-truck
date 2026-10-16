// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern double fn_8002EF30(double);
extern unsigned char lbl_8055FCC8;
extern int lbl_8055FCD0;
extern float lbl_8055FCD4;
extern double lbl_80564F68;
void fn_802CE308(void) {
    fn_8000D838(&lbl_8055FCC8);
    lbl_8055FCD0 = 0xFFFF0000;
    lbl_8055FCD4 = (float)fn_8002EF30(lbl_80564F68);
}
