// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E100;
extern float lbl_80558DC4;
extern float lbl_805613BC;
extern float lbl_805613B8;
void fn_80138F38(void);
int fn_80138BE4(float arg0, float arg1) {
    return (arg0 * arg1) < lbl_805613B8;
}

int fn_80138BFC(float arg0) {
    return __fabsf(arg0) <= (lbl_805613BC * lbl_80558DC4);
}

void fn_80139030(void) {
    lbl_8055E100 = -6;
    fn_80138F38();
}
