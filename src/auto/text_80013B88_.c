// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D4F8[4];
extern int lbl_80351828[5];
struct lbl80351828_t {
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
};
extern struct lbl80351828_t lbl_80351828_s;
extern int fn_8000D838(void*);
#pragma scheduling off
void fn_80013B88(void) {
    fn_8000D838(&lbl_8055D4F8);
    lbl_80351828[0] = 0;
    lbl_80351828[1] = 123;
    lbl_80351828[2] = 0;
    lbl_80351828[3] = 0;
    lbl_80351828[4] = 0;
}
#pragma scheduling on
