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

int fn_80127AB8(void *arg0) {
    int index;
    unsigned char *src;
    if (fn_80127AA0() == 0) {
        index = lbl_8055DF50;
        src = lbl_8041DF58 + index * 20;
        *(int *)((unsigned char *)arg0 + 0) = *(int *)(src + 0);
        *(int *)((unsigned char *)arg0 + 4) = *(int *)(src + 4);
        *(int *)((unsigned char *)arg0 + 8) = *(int *)(src + 8);
        *(int *)((unsigned char *)arg0 + 12) = *(int *)(src + 12);
        *(int *)((unsigned char *)arg0 + 16) = *(int *)(src + 16);
        lbl_8055DF50 = (index + 1) % 16;
        return 1;
    }
    return 0;
}

