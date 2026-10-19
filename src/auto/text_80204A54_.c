// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void *lbl_8055ED30;
extern int lbl_80488BB8[];
extern int lbl_8055ED38;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80204A54(void) {
    int v;
    int *p;
    fn_8000D838(&lbl_8055ED30);
    p = lbl_80488BB8 + 1;
    lbl_80488BB8[0] = 0;
    v = 0x7B;
    lbl_80488BB8[1] = v;
    lbl_80488BB8[2] = 0;
    lbl_80488BB8[3] = 0;
    lbl_80488BB8[4] = 0;
    lbl_8055ED38 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
