// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D5E0[4];
extern void fn_8000D838(void *queue);
/* Register lbl_8055D5E0 as a static-destructor record (see fn_8000D838) so
 * its destructor runs at shutdown. */
void fn_8001DA54(void) {
    fn_8000D838(lbl_8055D5E0);
}
