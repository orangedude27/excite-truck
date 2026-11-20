// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F960[8];
extern int fn_8000D838(void*);
struct Pair8055F968 { unsigned int a; float b; };
extern struct Pair8055F968 lbl_8055F968;
extern float lbl_80564BB4;
#pragma scheduling reset
void fn_802B05F4(void) {
    fn_8000D838(&lbl_8055F960);
    lbl_8055F968.a = 0xFFFF0000;
    lbl_8055F968.b = lbl_80564BB4;
}
