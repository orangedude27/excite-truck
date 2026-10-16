// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80128668(void);
int fn_8024C24C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8024C28C(void *arg0) {
    int count = *(int *)((char *)arg0 + 0x1C);
    int index = (count + *(int *)((char *)arg0 + 0x10) - 1) % count;
    int *array = *(int **)((char *)arg0 + 0x14);
    int *output = *(int **)((char *)arg0 + 0x20);
    *(int *)((char *)arg0 + 0x10) = index;
    *output = array[index];
}

void fn_8024C2C4(void *arg0) {
    int index = (*(int *)((char *)arg0 + 0x10) + 1) % *(int *)((char *)arg0 + 0x1C);
    int *array = *(int **)((char *)arg0 + 0x14);
    int *output = *(int **)((char *)arg0 + 0x20);
    *(int *)((char *)arg0 + 0x10) = index;
    *output = array[index];
}

int fn_8024C2F8(void *arg0) {
    return (*(int **)((char *)arg0 + 0x18))[*(int *)((char *)arg0 + 0x10)];
}

