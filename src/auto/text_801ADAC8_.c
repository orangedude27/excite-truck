// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E5D8;
extern int lbl_8055E5E0;
extern void fn_8000D838(void *);
/* Register the static-destructor record at lbl_8055E5D8 and set its trailing word to 0xFFFF0000. */
void fn_801ADAC8(void) {
    fn_8000D838(&lbl_8055E5D8);
    lbl_8055E5E0 = 0xFFFF0000;
}
