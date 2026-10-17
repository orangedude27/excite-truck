// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_802FE850[];
void fn_80024BD4(void) {
    (*(void (**)(void))(*(unsigned int *)(lbl_802FE850 + 0x38) + 0x20))();
}

int fn_80024BEC(short *arg0, unsigned char *arg1, int arg2) {
    if (arg1 == 0) return 0;
    if (arg2 == 0) return -1;
    if (arg0 != 0) *arg0 = *arg1;
    if ((signed char)*arg1 == 0) return 0;
    return 1;
}

int fn_80024C38(signed char *arg0, signed char arg1) {
    if (arg0 == 0) return 0;
    *arg0 = arg1;
    return 1;
}

