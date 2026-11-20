// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern unsigned char lbl_8055F6A8;
extern volatile short lbl_8055F6B0;
extern short lbl_8055F6B2;
extern volatile short lbl_8055F6B4;
extern volatile float lbl_8055F6B8;
extern float lbl_8056426C;
#pragma scheduling invalid_target
void fn_80288894(void) {
    fn_8000D838(&lbl_8055F6A8);
    lbl_8055F6B0 = 0x100;
    {
        register short v401 asm("r0") = 0x401;
        register short v405 asm("r3") = 0x405;
        lbl_8055F6B4 = v401;
        lbl_8055F6B2 = v405;
    }
    lbl_8055F6B8 = lbl_8056426C;
}
#pragma scheduling on
