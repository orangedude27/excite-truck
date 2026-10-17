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
    int temp_r0;
    int temp_r7;
    int *temp_r5;
    int *temp_r4;
    temp_r7 = *(int *)((char *)arg0 + 0x1C);
    temp_r0 = *(int *)((char *)arg0 + 0x10);
    temp_r5 = *(int **)((char *)arg0 + 0x14);
    temp_r0 = (temp_r7 + temp_r0 - 1) % temp_r7;
    temp_r4 = *(int **)((char *)arg0 + 0x20);
    *(int *)((char *)arg0 + 0x10) = temp_r0;
    *temp_r4 = temp_r5[temp_r0];
}

void fn_8024C2C4(void *arg0) {
    int temp_r4;
    int temp_r6;
    int temp_r7;
    int *temp_r5;
    int *temp_r4p;
    temp_r4 = *(int *)((char *)arg0 + 0x10);
    temp_r6 = *(int *)((char *)arg0 + 0x1C);
    temp_r7 = temp_r4 + 1;
    temp_r5 = *(int **)((char *)arg0 + 0x14);
    temp_r4p = *(int **)((char *)arg0 + 0x20);
    temp_r7 = temp_r7 % temp_r6;
    *(int *)((char *)arg0 + 0x10) = temp_r7;
    *temp_r4p = temp_r5[temp_r7];
}

int fn_8024C2F8(void *arg0) {
    return (*(int **)((char *)arg0 + 0x18))[*(int *)((char *)arg0 + 0x10)];
}

int fn_8024C30C(void *arg0) {
    return (*(int **)((char *)arg0 + 0x14))[*(int *)((char *)arg0 + 0x10)];
}

