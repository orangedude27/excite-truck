// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055E498;
extern int lbl_804348C0[];
extern int lbl_8055E4A0;
extern int lbl_8055E4A4;
extern int lbl_8055E4A8;
void fn_8017EB0C(void) {
    fn_8000D838(&lbl_8055E498);
    *(int *)((char *)&lbl_804348C0 + 0) = 0;
    *(int *)((char *)&lbl_804348C0 + 8) = 0;
    *(int *)((char *)&lbl_804348C0 + 4) = 0x7B;
    *(int *)((char *)&lbl_804348C0 + 0xC) = 0;
    *(int *)((char *)&lbl_804348C0 + 0x10) = 0;
    lbl_8055E4A0 = 0xFFFF0000;
    lbl_8055E4A4 = 0xFFFF0000;
    lbl_8055E4A8 = 0x7F000000;
}
