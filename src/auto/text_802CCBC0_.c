// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FCD8;
extern int fn_802CAFC8(int);
extern int fn_802CAFF0(int);
extern int stricmp(const char *, const char *);
void fn_802CCBC0(void) {}

int fn_802CCD0C(void *arg0, void *arg1) {
    int a = fn_802CAFC8(*(int *)((char *)arg0 + 0x10));
    int b = fn_802CAFC8(*(int *)((char *)arg1 + 0x10));
    if (a != b) return a - b;

    a = fn_802CAFF0(*(int *)((char *)arg0 + 0x10));
    b = fn_802CAFF0(*(int *)((char *)arg1 + 0x10));
    if (a != b) return a - b;

    if (*(int *)((char *)arg0 + 0x10) == -1) return 1;
    if (*(int *)((char *)arg1 + 0x10) == -1) return -1;
    return stricmp((const char *)arg0, (const char *)arg1);
}

int fn_802CCDC4(void ***arg0, void ***arg1) {
    void **a = *arg0;
    void **b = *arg1;
    int x = ((int (*)(void **))(*(void **)((char *)*a + 0x10)))(a);
    int y = ((int (*)(void **))(*(void **)((char *)*b + 0x10)))(b);
    return x - y;
}

void fn_802CD320(void *arg0, int arg1) {
    int count = *(int *)((char *)arg0 + 0x88);
    int *items = *(int **)((char *)arg0 + 0x90);
    items[count] = arg1;
    *(int *)((char *)arg0 + 0x88) = count + 1;
}

void fn_802CDAA8(void) {
    lbl_8055FCD8 = 0;
}

void fn_802CE260(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE278(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE290(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE2A8(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE2C0(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE2D8(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE2F0(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

