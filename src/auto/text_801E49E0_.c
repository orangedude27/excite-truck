// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void*);
extern int lbl_8055EA70;
extern volatile int lbl_8055EA78;
extern volatile short lbl_8055EA7C;
extern volatile short lbl_8055EA7E;
extern volatile short lbl_8055EA80;
extern volatile int lbl_8055EA84;
void fn_801E49E0(void) {
    fn_8000D838(&lbl_8055EA70);
    lbl_8055EA7C = 0x100;
    lbl_8055EA84 = 0x7F000000;
    lbl_8055EA78 = 0xFFFF0000;
    lbl_8055EA7E = 0x405;
    lbl_8055EA80 = 0x401;
}
