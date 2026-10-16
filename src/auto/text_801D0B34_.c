// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E8D8;
extern int lbl_8055E8DC;
struct Entry { int first; int second; int value; };
extern struct Entry lbl_80438758[];
extern void fn_80128668(void *);
void *fn_801D0B34(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            ((int *)arg0)[0] = 0;
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void *fn_801D0B8C(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            ((int *)arg0)[0] = 0;
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801D0BE4(void) {
    lbl_8055E8D8 = 0;
    lbl_8055E8DC = 0;
}

void fn_801D0BF4(void) {

}

int fn_801D0BF8(int arg0, int arg1) {
    struct Entry *entry = lbl_80438758;
    int i = 0;
    int count = lbl_8055E8D8;
    if (count <= 0)
        return 0;
    do {
        if (arg0 == entry->first && arg1 == entry->second)
            return lbl_80438758[i].value;
        entry++;
        i++;
    } while (--count != 0);
    return 0;
}

void fn_801D0C58(int arg0, int arg1, int arg2) {
    int count = lbl_8055E8D8;
    struct Entry *entry = &lbl_80438758[count];
    entry->second = arg2;
    lbl_8055E8D8 = count + 1;
    entry->first = arg1;
    entry->value = arg0;
}

