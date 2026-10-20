// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F130;
extern int lbl_80498770[5];
extern void fn_8000D838(char *);
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_8023C26C(void) {
    int v;
    fn_8000D838(&lbl_8055F130);
    lbl_80498770[0] = 0;
    v = 123;
    lbl_80498770[1] = v;
    lbl_80498770[2] = 0;
    lbl_80498770[3] = 0;
    lbl_80498770[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
