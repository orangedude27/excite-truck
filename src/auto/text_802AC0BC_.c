// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F918;
extern int lbl_8055F920;
extern void fn_8000D838(void *);
void fn_802AC0BC(void) {
    // Initialize a global object: register its static-destructor record (tag 0x31)
    // on the global destructor chain via fn_8000D838, then set its state word to
    // the 0xFFFF0000 sentinel (lbl_8055F920 is the object's field at +8).
    fn_8000D838(&lbl_8055F918);
    lbl_8055F920 = 0xFFFF0000;
}
