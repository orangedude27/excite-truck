// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F180;
extern int lbl_804987B8[];
extern int lbl_8055F188;
extern void fn_8000D838(void *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8023E558(void) {
    int v;
    int *p;
    fn_8000D838(&lbl_8055F180);
    p = lbl_804987B8 + 1;
    lbl_804987B8[0] = 0;
    v = 0x7B;
    lbl_804987B8[1] = v;
    lbl_804987B8[2] = 0;
    lbl_804987B8[3] = 0;
    lbl_804987B8[4] = 0;
    lbl_8055F188 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
