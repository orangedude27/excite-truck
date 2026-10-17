// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E160;
extern int lbl_802F9350[3];
int fn_8013A6C4(void *arg0, void *arg1) {
    return *(int *)((char *)arg0 + 8) - *(int *)((char *)arg1 + 8);
}

void DBPrintf_8013B490(const char *fmt, ...) {
#pragma unused(fmt)
}

void fn_8013B56C(void) {
    lbl_8055E160 = 0;
}
