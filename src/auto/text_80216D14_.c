// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EFAC;
void fn_80216D28(void) {
    lbl_8055EFAC = 1;
}

void fn_80216D34(void) {
    lbl_8055EFAC = 0;
}

void fn_80217478(void) {

}

void fn_80217834(void *arg0) {
    if (*(void **)((char *)arg0 + 0x448) != 0) {
        ((void (**)(void *))(*(void **)(*(char **)((char *)arg0 + 0x448))))[20](*(void **)((char *)arg0 + 0x448));
    }
}

void fn_80217854(void *arg0) {
    if (*(void **)((char *)arg0 + 0x448) != 0) {
        ((void (**)(void *))(*(void **)(*(char **)((char *)arg0 + 0x448))))[21](*(void **)((char *)arg0 + 0x448));
    }
}

int fn_80217BC8(int *arg0, int *arg1) {
    return *arg0 - *arg1;
}

void *fn_80217BD8(void *arg0, int arg1, int arg2) {
    char *base = (char *)arg0;
    int count = *(int *)(base + 0x494);
    char *entry = base + count * 8;
    *(int *)(entry + 0x4A0) = arg1;
    *(int *)(entry + 0x4A4) = arg2;
    count = *(int *)(base + 0x494);
    count++;
    *(int *)(base + 0x494) = count;
    qsort(base + 0x4A0, count, 8, fn_80217BC8, base);
    *(int *)(base + 0x498) = *(int *)(base + 0x4A0);
    return base + 0x498;
}

void fn_802180B0(void *arg0) { fn_80217EC0(arg0, 1, 0); }

void fn_802180BC(void *arg0) { fn_80217EC0(arg0, 1, 1); }

extern int fn_80217EC0(void *, int, int);
void fn_802180C8(void *arg0) { fn_80217EC0(arg0, 0, 0); }

void fn_802180D4(void *arg0) { fn_80217EC0(arg0, 0, 1); }

void fn_8021818C(void *arg0) {
    *(int *)((char *)arg0 + 0x498) = -1;
}

extern int qsort(void *, int, int, int (*)(const void *, const void *), void *);
int fn_80217BC8(int *, int *);
