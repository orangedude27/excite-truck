// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D4F8[4];
extern int lbl_80351828[5];
extern int fn_8000D838(void*);
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80013B88(void) {
    int v;
    fn_8000D838(&lbl_8055D4F8);
    lbl_80351828[0] = 0;
    v = 123;
    lbl_80351828[1] = v;
    lbl_80351828[2] = 0;
    lbl_80351828[3] = 0;
    lbl_80351828[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
