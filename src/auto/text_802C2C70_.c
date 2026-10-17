// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055FB88;
extern short lbl_8055FB90;
extern short lbl_8055FB92;
extern short lbl_8055FB94;
void fn_8000D838(void*);
static void set_short(volatile short *p, short v) { *p = v; }

#pragma scheduling on
void fn_802C2C70(void) {
    fn_8000D838(&lbl_8055FB88);
    *(volatile short *)&lbl_8055FB90 = 0x100;
    *(short *)&lbl_8055FB94 = 0x401;
    *(short *)&lbl_8055FB92 = 0x405;
}
#pragma scheduling on
