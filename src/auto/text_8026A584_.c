// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int);
extern char lbl_80499080[];
extern char lbl_803467E8[];
extern char lbl_8055F470[];
extern int lbl_8055F478;
extern float lbl_8055F47C;
extern float lbl_8055F49C;
extern float lbl_80563CF4, lbl_80563CF8, lbl_80563CFC, lbl_80563D00, lbl_80563D04;
extern void *fn_8026A600(void *);
void fn_8026A584(void) {
    fn_8000D838(&lbl_8055F470);
    lbl_8055F478 = 0xFFFF0000;
    lbl_8055F47C = lbl_80563CF4;
    fn_8002F53C(&lbl_80499080, fn_8026A600, 0, 0x228, 4);
    lbl_8055F49C = lbl_80563CF8;
    *(float *)&lbl_803467E8[0x18] = lbl_80563CFC;
    *(float *)&lbl_803467E8[0x38] = lbl_80563D00;
    *(float *)&lbl_803467E8[0x58] = lbl_80563D04;
}
