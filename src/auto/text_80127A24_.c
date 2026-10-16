// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055DF50;
extern int lbl_8055DF54;
extern int lbl_8055DF58;
extern int lbl_8055DF5C;
extern int lbl_8055DF60;
extern unsigned char lbl_8041DF58[];
extern int fn_80127AA0(void);
extern int fn_80127464(int);
extern int fn_80127AB8(void *);
void fn_80127A84(int *arg0, int *arg1, int *arg2) {
    *arg0 = lbl_8055DF58;
    *arg1 = lbl_8055DF5C;
    *arg2 = lbl_8055DF60;
}

int fn_80127AA0(void) {
    return lbl_8055DF50 == lbl_8055DF54;
}

int fn_80127AB8(void *arg0) {
    int i;
    int *dst = (int *)arg0;
    int *src;
    if (fn_80127AA0())
        return 0;
    src = (int *)(lbl_8041DF58 + lbl_8055DF50 * 0x14);
    for (i = 0; i < 5; i++)
        dst[i] = src[i];
    lbl_8055DF50 = (lbl_8055DF50 + 1) % 16;
    return 1;
}

