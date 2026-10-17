// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_802CE728(void *arg0) {
    if (*(int *)((char *)arg0 + 0x38) == 2) {
        return *(int *)((char *)arg0 + 0x34);
    }
    return -1;
}

void fn_802CE7D4(int arg0, void *arg2) {
    if (*(unsigned char *)arg2 != 0) {
        *(int *)((char *)arg2 + 0x30) = arg0;
        fn_802C61BC((char *)arg2 + 8);
        fn_802C6FA8(*(int *)((char *)arg2 + 0x30));
        *(int *)((char *)arg2 + 0x34) = fn_802C6DC4((char *)arg2 + 8, *(int *)((char *)arg2 + 0x30), 0, 0);
        *(int *)((char *)arg2 + 0x38) = 2;
    } else {
        *(int *)((char *)arg2 + 0x38) = 0;
        *(int *)((char *)arg2 + 0x2C) = -1;
    }
}

int fn_802CE850(void *arg0) {
    return *(int *)((char *)arg0 + 0x38);
}
