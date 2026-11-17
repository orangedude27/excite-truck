// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void*);
extern int lbl_8055EA70;
extern int lbl_8055EA78;
extern short lbl_8055EA7C;
extern short lbl_8055EA7E;
extern short lbl_8055EA80;
extern int lbl_8055EA84;
#pragma scheduling invalid_target
void fn_801E49E0(void) {
    register int c1 asm("r0");
    fn_8000D838(&lbl_8055EA70);
    c1 = 0x100;
    lbl_8055EA7C = c1;
    lbl_8055EA84 = 0x7F000000;
    lbl_8055EA78 = 0xFFFF0000;
    lbl_8055EA7E = 0x405;
    lbl_8055EA80 = 0x401;
}
#pragma scheduling on
