// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E7C0;
extern int lbl_8055E7C8;
void fn_8000D838(void *);
void fn_801C2F2C(void) {
    // Initialize a global object: register its static-destructor record (tag 0x31)
    // on the global destructor chain via fn_8000D838, then set its state word to
    // the 0xFFFF0000 sentinel (lbl_8055E7C8 is the object's field at +8).
    fn_8000D838(&lbl_8055E7C0);
    lbl_8055E7C8 = 0xFFFF0000;
}
