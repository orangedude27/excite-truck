// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F0A8;
extern int lbl_80498650[5];
extern void fn_8000D838(int *);
void fn_80238714(void) {
    fn_8000D838(&lbl_8055F0A8);
    *(int *)((char *)&lbl_80498650 + 0) = 0;
    *(int *)((char *)&lbl_80498650 + 4) = 0x7B;
    *(int *)((char *)&lbl_80498650 + 8) = 0;
    *(int *)((char *)&lbl_80498650 + 12) = 0;
    *(int *)((char *)&lbl_80498650 + 16) = 0;
}
