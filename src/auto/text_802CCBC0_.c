// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FCD8;
extern int fn_802CAFC8(int);
extern int fn_802CAFF0(int);
extern int stricmp(const char *, const char *);
void fn_802CCBC0(void) {}

int fn_802CCD0C(void *arg0, void *arg1) {
    int result;
    int x = fn_802CAFC8(*(int *)((char *)arg0 + 0x10));
    int y = fn_802CAFC8(*(int *)((char *)arg1 + 0x10));
    if (x != y) return x - y;
    x = fn_802CAFF0(*(int *)((char *)arg0 + 0x10));
    y = fn_802CAFF0(*(int *)((char *)arg1 + 0x10));
    if (x != y) return x - y;
    if (*(int *)((char *)arg0 + 0x10) == -1) return 1;
    if (*(int *)((char *)arg1 + 0x10) == -1) return -1;
    result = stricmp(arg0, arg1);
    return result;
}

int fn_802CCDC4(void ***arg0, void ***arg1) {
    void **obj0 = **arg0;
    void **obj1 = *arg1[0];
    int (*method0)(void **) = (int (*)(void **))(*(void **)(*arg0[0]));
    int (*method1)(void **) = (int (*)(void **))(*(void **)(*obj1));
    return method0(obj0) - method1(obj1);
}

void fn_802CD320(void *arg0, int arg1) {
    int count = *(int *)((char *)arg0 + 0x88);
    int *items = *(int **)((char *)arg0 + 0x90);
    items[count] = arg1;
    *(int *)((char *)arg0 + 0x88) = count + 1;
}

void fn_802CD33C(void *arg0, int arg1, int arg2) {
    if (arg2 != 0) {
        unsigned short *p = (unsigned short *)(*(char **)((char *)arg0 + 0x24) + (arg1 << 5) + 0x12);
        *p &= ~0x40;
    } else {
        unsigned short *p = (unsigned short *)(*(char **)((char *)arg0 + 0x24) + (arg1 << 5) + 0x12);
        *p |= 0x40;
    }
}

void fn_802CDAA8(void) {
    lbl_8055FCD8 = 0;
}

extern unsigned char *lbl_8055DFC4;
extern int fn_802D0514(int);
void fn_802CDAFC(void *arg0, int arg1) {
    int a = *(int *)((char *)arg0 + 0x18);
    int b = *(int *)((char *)arg0 + 0x10);
    *(unsigned char *)((char *)lbl_8055DFC4 + a + arg1 + b + 1) = 0;
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

