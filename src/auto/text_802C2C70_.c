// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055FB88;
extern short lbl_8055FB90[3];
void fn_8000D838(void*);

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802C2C70(void) {
    int v;
    fn_8000D838(&lbl_8055FB88);
    lbl_8055FB90[0] = 0x100;
    v = 0x401;
    lbl_8055FB90[2] = v;
    v = 0x405;
    lbl_8055FB90[1] = v;
}
#pragma opt_propagation reset
#pragma scheduling on
