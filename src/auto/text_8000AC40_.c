// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void*);
extern int lbl_8055D3A0;
extern int lbl_8034F4C8[];
extern int lbl_8055D3A8;
extern int lbl_8055D3AC;
void fn_8000AC40(void) {
    fn_8000D838(&lbl_8055D3A0);
    ((volatile int*)lbl_8034F4C8)[0] = 0;
    ((volatile int*)lbl_8034F4C8)[1] = 0x7B;
    *(volatile int*)&lbl_8055D3A8 = 0xFFFF0000;
    ((volatile int*)lbl_8034F4C8)[2] = 0;
    ((volatile int*)lbl_8034F4C8)[3] = 0;
    ((volatile int*)lbl_8034F4C8)[4] = 0;
    *(volatile int*)&lbl_8055D3AC = 0x7F000000;
}
