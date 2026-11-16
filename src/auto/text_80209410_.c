// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_801312EC(void *, void *);
extern int lbl_8055EDA0;
extern char lbl_8048929C[];
extern char lbl_8033C1B0[];
void fn_80209410(void) {
    /* __sinit_ thunk (registered in .ctors at 0x802ED380): hang this module's
     * static-destructor node (lbl_8055EDA0) on the runtime's global chain via
     * fn_8000D838 (tag 0x31, head at lbl_8055D450), then bring up the
     * "Sound:NoSound" lazy-lookup handle record at lbl_8048929C: key = the name
     * string lbl_8033C1B0, cached handle = none,
     * token = ~current generation counter (lbl_8055E044). */
    fn_8000D838(&lbl_8055EDA0);
    fn_801312EC(lbl_8048929C, lbl_8033C1B0);
}
