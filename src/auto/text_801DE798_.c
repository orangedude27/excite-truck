// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E9B0;
extern int lbl_80486F18[5];
extern int lbl_8055E9B8;
extern void fn_8000D838(void *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_801DE798(void) {
    int v;
    int *p;
    fn_8000D838(&lbl_8055E9B0);
    p = lbl_80486F18 + 1;
    lbl_80486F18[0] = 0;
    v = 0x7B;
    lbl_80486F18[1] = v;
    lbl_80486F18[2] = 0;
    lbl_80486F18[3] = 0;
    lbl_80486F18[4] = 0;
    lbl_8055E9B8 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
