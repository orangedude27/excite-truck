// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F248[4];
extern int lbl_804988D8[5];
extern int fn_8000D838(void*);
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802468F0(void) {
    int v;
    fn_8000D838(&lbl_8055F248);
    lbl_804988D8[0] = 0;
    v = 123;
    lbl_804988D8[1] = v;
    lbl_804988D8[2] = 0;
    lbl_804988D8[3] = 0;
    lbl_804988D8[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
