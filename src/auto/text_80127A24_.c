// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055DF50;
extern int lbl_8055DF54;
extern int lbl_8055DF58;
extern int lbl_8055DF5C;
extern int lbl_8055DF60;
struct Struct80127 {
    int words[5];
};
extern struct Struct80127 lbl_8041DF58[];
extern int fn_80127AA0(void);
extern int fn_80127464(int);
extern int fn_80127AB8(void *);
void fn_80127A24(void) {
    ((int (*)(void))fn_80127464)();
    lbl_8055DF54 = 0;
    lbl_8055DF50 = 0;
}

void fn_80127A50(int arg0) {
    fn_80127464(arg0);
    fn_80127AB8((void *)arg0);
}

void fn_80127A84(int *arg0, int *arg1, int *arg2) {
    *arg0 = lbl_8055DF58;
    *arg1 = lbl_8055DF5C;
    *arg2 = lbl_8055DF60;
}

int fn_80127AA0(void) {
    return lbl_8055DF50 == lbl_8055DF54;
}

#pragma push
#pragma dont_inline on
int fn_80127AB8(void *arg0) {
    int index;
    volatile int (*table)[5];
    int (*row)[5];
    int *dst = (int *)arg0;
    if (fn_80127AA0() != 0) goto fail;
    index = lbl_8055DF50;
    table = (volatile int (*)[5])lbl_8041DF58;
    row = (int (*)[5])table + index;
    dst[0] = table[index][0];
    dst[1] = row[0][1];
    dst[2] = row[0][2];
    dst[3] = row[0][3];
    dst[4] = row[0][4];
    lbl_8055DF50 = (lbl_8055DF50 + 1) % 16;
    return 1;
fail:
    return 0;
}
#pragma pop
