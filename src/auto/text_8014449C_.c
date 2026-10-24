// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055E1A8;
extern volatile int lbl_8042FB28[];
extern void fn_8000D838(void *);
extern int lbl_8055E1B0;
extern int lbl_8055E1B4;
extern int lbl_8055E1B8;
extern int lbl_8055E1C4;
#pragma scheduling invalid_target
void fn_8014449C(void) {
    volatile int *p;
    fn_8000D838(&lbl_8055E1A8);
    lbl_8055E1B0 = 0xFFFF0000;
    lbl_8055E1B4 = 0xFFFF0000;
    lbl_8042FB28[0] = 0;
    p = lbl_8042FB28;
    p[1] = 0x7B;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    lbl_8055E1C4 = 0xFF2A85F0;
    lbl_8055E1B8 = 0x7F000000;
}
#pragma scheduling on
