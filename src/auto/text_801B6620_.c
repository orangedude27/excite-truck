// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E718;
extern int lbl_8055E720;
void fn_8000D838(void *);
/* Register the static-destructor record at lbl_8055E718 and set its trailing word to 0xFFFF0000. */
void fn_801B6620(void) {
    fn_8000D838(&lbl_8055E718);
    lbl_8055E720 = 0xFFFF0000;
}
