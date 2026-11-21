// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern double fn_8002F208(double);
extern int lbl_8055F708;
extern double lbl_80564418;
float lbl_8055F710;
#pragma push
#pragma scheduling invalid_target
void fn_8028DF24(void) {
    float *dst = &lbl_8055F710;
    fn_8000D838(&lbl_8055F708);
    *dst = (float)fn_8002F208(lbl_80564418);
}
#pragma pop
