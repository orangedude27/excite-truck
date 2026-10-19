// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8000D838(int *);
extern int lbl_8055F018;
extern int lbl_8055F020;
extern int lbl_80497EF0[];
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802314B4(void) {
    int v;
    fn_8000D838(&lbl_8055F018);
    *(volatile int *)&lbl_8055F020 = 0x7F000000;
    ((volatile int *)lbl_80497EF0)[0] = 0;
    v = 0x7B;
    ((volatile int *)lbl_80497EF0)[1] = v;
    ((volatile int *)lbl_80497EF0)[2] = 0;
    ((volatile int *)lbl_80497EF0)[3] = 0;
    ((volatile int *)lbl_80497EF0)[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
