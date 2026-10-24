// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_80021948(void);
extern int lbl_8055D620;
extern int lbl_8055D628;
extern char lbl_8035B758[];
#pragma scheduling invalid_target
void fn_800218FC(void) {
    fn_8000D838(&lbl_8055D620);
    lbl_8055D628 = 0x7F000000;
    fn_8002F53C(lbl_8035B758, fn_80021948, 0, 0x70, 8);
}
#pragma scheduling on
