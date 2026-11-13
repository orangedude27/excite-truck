// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
typedef struct { char pad[8]; short a, b, c; } Lbl8055FE08;
extern Lbl8055FE08 lbl_8055FE08;
void fn_802D98BC(void) {
    fn_8000D838(&lbl_8055FE08);
    lbl_8055FE08.a = 0x100;
    lbl_8055FE08.c = 0x401;
    lbl_8055FE08.b = 0x405;
}
