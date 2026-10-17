// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F520;
extern unsigned char lbl_8049A218[];
extern void fn_80270AE8(void);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern float lbl_8055F528, lbl_8055F52C, lbl_8055F530, lbl_8055F534;
extern float lbl_80563F2C, lbl_80563F30, lbl_80563F34, lbl_80563F38;
#pragma scheduling off
void fn_80270A84(void) {
    fn_8000D838(&lbl_8055F520);
    lbl_8055F528 = lbl_80563F2C;
    lbl_8055F52C = lbl_80563F30;
    lbl_8055F530 = lbl_80563F34;
    lbl_8055F534 = lbl_80563F38;
    fn_8002F53C(lbl_8049A218, fn_80270AE8, 0, 0x10, 4);
}
