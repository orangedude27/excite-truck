// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F800;
extern int lbl_8055F808;
void fn_8000D838(void *);
void fn_8029F010(void) {
    /* Static initializer: register lbl_8055F800 as a static-destructor record,
       then set the adjacent float sentinel (lbl_8055F808) to 0xFFFF0000 (-1.0f). */
    fn_8000D838(&lbl_8055F800);
    lbl_8055F808 = 0xFFFF0000;
}
