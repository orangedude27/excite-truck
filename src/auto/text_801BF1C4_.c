// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void*);
extern void fn_8002F53C(void*, void (*)(void), int, int, int);
extern void fn_801BF210(void);
extern int lbl_80436D48[4];
extern int lbl_8055E780;
extern int lbl_8055E788;
void fn_801BF1C4(void) {
    fn_8000D838(&lbl_8055E780);
    lbl_8055E788 = 0xFFFF0000;
    fn_8002F53C(&lbl_80436D48, fn_801BF210, 0, 0x10, 0x100);
}
