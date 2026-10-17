// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern char lbl_8055F8B0;
extern int lbl_8055F8B8;
extern char lbl_804BD5D8[];
extern void fn_802A81EC(void);
void fn_802A81A0(void) {
    fn_8000D838(&lbl_8055F8B0);
    lbl_8055F8B8 = 0x7F000000;
    fn_8002F53C(&lbl_804BD5D8, fn_802A81EC, 0, 0x1C, 8);
}
