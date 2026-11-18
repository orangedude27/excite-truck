// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055DF78;
extern char lbl_8032A4B8[];
extern void *lbl_8041E140[];
extern void *lbl_8041E160[];
#pragma scheduling invalid_target
void fn_80129290(void) {
    fn_8000D838(&lbl_8055DF78);
    lbl_8041E140[0] = lbl_8032A4B8;
    lbl_8041E160[0] = lbl_8032A4B8;
}
#pragma scheduling on
