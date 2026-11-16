// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_801312EC(void *, void *);
extern int lbl_8055E3B0;
extern int lbl_8055E3B8;
extern char lbl_80430448[];
extern char lbl_803318E8[];
extern void fn_8000D838(void *);
extern void fn_801312EC(void *, void *);
extern int lbl_8055E3B0;
extern int lbl_8055E3B8;
extern char lbl_80430448[];
extern char lbl_803318E8[];
#pragma scheduling invalid_target
void fn_801777D4(void) {
    /* __sinit_: hang this module's init node (lbl_8055E3B0) on the runtime's
     * global-destructor chain via fn_8000D838 (tag 0x31, linked at lbl_8055D450),
     * arm the node's state word (lbl_8055E3B8) to 0xFFFF0000, then bring up the
     * "High_Scores:DNF" lazy-lookup handle record at lbl_80430448: key = the name
     * string, cached handle = none, token = ~current generation counter. */
    fn_8000D838(&lbl_8055E3B0);
    *(volatile int *)&lbl_8055E3B8 = 0xFFFF0000;
    fn_801312EC(lbl_80430448, lbl_803318E8);
}
#pragma scheduling on
