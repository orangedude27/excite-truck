// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F960[8];
extern int fn_8000D838(void*);
extern int lbl_8055F968;
struct Pair8055F96C { float b; unsigned int c; };
extern struct Pair8055F96C lbl_8055F96C;
extern float lbl_80564BB4;
#pragma scheduling reset
void fn_802B05F4(void) {
    fn_8000D838(&lbl_8055F960);
    lbl_8055F968 = 0xFFFF0000;
    lbl_8055F96C.b = lbl_80564BB4;
}
