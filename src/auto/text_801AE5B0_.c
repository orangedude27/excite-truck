// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E608;
extern int lbl_8055E610;
extern int lbl_80435728[];
extern int fn_8000D838(int *);
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_801AE5B0(void) {
    int v;
    fn_8000D838(&lbl_8055E608);
    *(volatile int *)&lbl_8055E610 = 0x7F000000;
    ((volatile int *)lbl_80435728)[0] = 0;
    v = 0x7B;
    ((volatile int *)lbl_80435728)[1] = v;
    ((volatile int *)lbl_80435728)[2] = 0;
    ((volatile int *)lbl_80435728)[3] = 0;
    ((volatile int *)lbl_80435728)[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
