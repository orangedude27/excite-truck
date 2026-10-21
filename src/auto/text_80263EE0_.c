// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
extern void fn_8000D838(void *);
extern u32 lbl_8055F428;
extern volatile u32 lbl_80498F40[5];
extern u32 lbl_8055F430;
void fn_80263EE0(void) {
    fn_8000D838(&lbl_8055F428);
    lbl_80498F40[0] = 0;
    lbl_80498F40[1] = 0x7b;
    lbl_80498F40[2] = 0;
    lbl_80498F40[3] = 0;
    lbl_80498F40[4] = 0;
    lbl_8055F430 = 0x7f000000;
}
