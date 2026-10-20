

extern int fn_80128668(void);
extern int lbl_8055E3C4;
void fn_801D6600(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D7F5C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}
