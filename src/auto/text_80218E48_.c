// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055EFA0;
extern int lbl_80490908[5];
extern int lbl_8055EFA8;
extern int fn_8000D838(int *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80218E48(void) {
    int v;
    int *p;
    fn_8000D838(&lbl_8055EFA0);
    p = lbl_80490908 + 1;
    lbl_80490908[0] = 0;
    v = 0x7b;
    lbl_80490908[1] = v;
    lbl_80490908[2] = 0;
    lbl_80490908[3] = 0;
    lbl_80490908[4] = 0;
    lbl_8055EFA8 = 0x7f000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
