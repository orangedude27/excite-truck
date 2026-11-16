// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
extern void *lbl_8055E5A8;
extern s32 lbl_8055E5B0;
void fn_8000D838(void *);
void fn_801A6344(void) {
    // Initialize a global object: register its static-destructor record (tag 0x31)
    // on the global destructor chain via fn_8000D838, then set its state word to
    // the 0xFFFF0000 sentinel (lbl_8055E5B0 is the object's field at +8).
    fn_8000D838(&lbl_8055E5A8);
    lbl_8055E5B0 = 0xFFFF0000;
}
