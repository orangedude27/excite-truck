// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int lbl_8055E1D0;
extern int lbl_8055E1D8;
extern int lbl_8055E1DC;
extern struct Tbl_8042FB88 {
    int f0, f4, f8, fC, f10;
} lbl_8042FB88;
extern void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma push
#pragma opt_propagation off
void fn_80144DE0(void) {
    fn_8000D838(&lbl_8055E1D0);
    lbl_8042FB88.f0 = 0;
    lbl_8042FB88.f4 = 0x7B;
    lbl_8055E1D8 = 0xFFFF0000;
    lbl_8042FB88.f8 = 0;
    lbl_8042FB88.fC = 0;
    lbl_8042FB88.f10 = 0;
    lbl_8055E1DC = 0x7F000000;
}
#pragma scheduling on
