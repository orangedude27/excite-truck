// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8029EFF0(int);
extern int fn_802CAC54(int);
extern int fn_802CAC28(const char *, int);
extern int fn_802E30C8(const char *, ...);
extern int lbl_8055CAE0;
extern char lbl_803497D8[];
extern char lbl_803497E8[];
#pragma scheduling invalid_target
void fn_8029EF70(void) {
    /* Load the line-effect texture handle; log an error if the handle is invalid. */
    lbl_8055CAE0 = fn_802CAC28(lbl_803497D8, 0);
    if (fn_8029EFF0(lbl_8055CAE0) == 0) {
        fn_802E30C8(lbl_803497E8);
    }
}
#pragma scheduling on

void fn_8029EFBC(void) {
    /* Release the line-effect texture, if its handle is still valid. */
    if (fn_8029EFF0(lbl_8055CAE0) != 0) {
        fn_802CAC54(lbl_8055CAE0);
    }
}

int fn_8029EFF0(int handle) {
    /* Return 0 for the invalid resource-handle sentinels -1/-2, 1 otherwise. */
    if (handle == -1)
        goto invalid;
    if (handle != -2)
        goto valid;
invalid:
    return 0;
valid:
    return 1;
}
