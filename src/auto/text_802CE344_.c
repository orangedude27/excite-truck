// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8034BC00[];
extern char lbl_8034BCA8[];
extern void fn_802E317C(const char *, ...);
extern char lbl_8034BC00[];
extern char lbl_8034BCA8[];
extern void fn_802E317C(const char *, ...);
#pragma scheduling invalid_target
void *fn_802CE344(int arg0) {
    void *result;
    if (arg0 >= 0 && arg0 < 7) {
        result = lbl_8034BC00 + arg0 * 0x18;
    } else {
        fn_802E317C(lbl_8034BCA8, arg0);
        result = 0;
    }
    return result;
}
#pragma scheduling on
