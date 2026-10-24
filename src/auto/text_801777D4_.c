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
    fn_8000D838(&lbl_8055E3B0);
    lbl_8055E3B8 = 0xFFFF0000;
    fn_801312EC(lbl_80430448, lbl_803318E8);
}
#pragma scheduling on
