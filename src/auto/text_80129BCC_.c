// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055DFC8[4]; /* static-destructor record: tag at +0, link pointer at +4 */
extern void fn_8000D838(void *record); /* push a static-destructor record onto the global chain */
void fn_80129BCC(void) {
    /* Static initializer: enqueue this translation unit's static-destructor record (lbl_8055DFC8) on the global chain. */
    fn_8000D838(lbl_8055DFC8);
}
