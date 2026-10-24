// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055D450;
#pragma push
#pragma scheduling invalid_target
void fn_8000D838(void *arg0) {
    memset(arg0, 0x31, 1);
    *(void **)((char *)arg0 + 4) = lbl_8055D450;
    lbl_8055D450 = arg0;
}
#pragma pop
void fn_8000D878(void) {
    return;
}
