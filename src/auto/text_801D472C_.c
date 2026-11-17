// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E938[4];
extern void fn_8000D838(void *queue);
void fn_801D472C(void) {
    /* Register the global object lbl_8055E938 as a static-destructor record on the global chain. */
    fn_8000D838(lbl_8055E938);
}
