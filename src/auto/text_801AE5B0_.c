// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E608;
extern int lbl_8055E610;
#pragma push
#pragma small_data off
extern int lbl_80435728;
#pragma pop
extern int fn_8000D838(int *);
void fn_801AE5B0(void) {
    register int color asm("r3") = 0x7F000000;
    register int *data asm("r4") = &lbl_80435728;
    fn_8000D838(&lbl_8055E608);
    lbl_8055E610 = color;
    data[0] = 0;
    data[1] = 0x7B;
    data[2] = 0;
    data[3] = 0;
    data[4] = 0;
}
