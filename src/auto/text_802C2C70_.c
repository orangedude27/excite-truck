// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

struct unk_8055FB88 { unsigned int _[2]; unsigned short f8, fa, fc; };
extern struct unk_8055FB88 lbl_8055FB88;
void fn_8000D838(void*);

void fn_802C2C70(void) {
    fn_8000D838(&lbl_8055FB88);
    lbl_8055FB88.f8 = 0x100;
    lbl_8055FB88.fc = 0x401;
    lbl_8055FB88.fa = 0x405;
}
