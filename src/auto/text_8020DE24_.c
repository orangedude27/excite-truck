// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055EE68;
extern int lbl_80489C70[5];
extern int lbl_8055EE70;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8020DE24(void) {
    int v;
    int *p;
    fn_8000D838(&lbl_8055EE68);
    p = lbl_80489C70 + 1;
    lbl_80489C70[0] = 0;
    v = 0x7B;
    lbl_80489C70[1] = v;
    lbl_80489C70[2] = 0;
    lbl_80489C70[3] = 0;
    lbl_80489C70[4] = 0;
    lbl_8055EE70 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
