// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern char lbl_8055F358[4];
extern int lbl_80498E50[5];
void fn_80257F70(void) {
    fn_8000D838(&lbl_8055F358);
    *(int *)&lbl_80498E50 = 0;
    *((int *)&lbl_80498E50 + 1) = 0x7B;
    *((int *)&lbl_80498E50 + 2) = 0;
    *((int *)&lbl_80498E50 + 3) = 0;
    *((int *)&lbl_80498E50 + 4) = 0;
}
