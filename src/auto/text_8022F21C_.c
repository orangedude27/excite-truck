// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EFE8[4];
extern int lbl_8055EFF0;
void fn_8000D838(void *);
void fn_8022F21C(void) {
    /* Static initializer (the .ctors entry at 0x802ED3CC): hang this module's
     * static-destructor node (lbl_8055EFE8) on the runtime's global chain via
     * fn_8000D838 (tag 0x31, head at lbl_8055D450), then bring up the module's
     * other static lbl_8055EFF0 to 0x7F000000 (1.7e38 when read as a float). */
    fn_8000D838(&lbl_8055EFE8);
    lbl_8055EFF0 = 0x7F000000;
}
