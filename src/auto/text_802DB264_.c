// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055FE68;
extern short lbl_8055FE70;
extern short lbl_8055FE72;
extern short lbl_8055FE74;
static inline void fn_802DB264_set_last(short v) {
    lbl_8055FE72 = v;
}
#pragma scheduling invalid_target
void fn_802DB264(void) {
    fn_8000D838(&lbl_8055FE68);
    lbl_8055FE70 = 0x100;
    lbl_8055FE74 = 0x401;
    lbl_8055FE72 = 0x405;
}
#pragma scheduling reset
