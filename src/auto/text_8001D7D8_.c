// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int __AXGetStackHead(int index) {
    extern int lbl_802ED82C[];
    return lbl_802ED82C[index];
}

int fn_8001D7EC(char *name) {
    extern char *lbl_802ED818[];
    int i;
    for (i = 0; i < 5; i++) {
        if (lbl_802ED818[i] != 0 && strcmp(lbl_802ED818[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

void fn_8001D868(int *values) {
    values[0] = -1;
    values[1] = -1;
    values[2] = -1;
    values[3] = -1;
    values[4] = -1;
}

