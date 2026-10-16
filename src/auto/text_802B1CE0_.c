// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_802B2E00(void *);
int fn_802B2E08(int);
int *fn_802B320C(int *, int);
int fn_802B3340(int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;

int fn_8012C33C(void);
int fn_802CAC28(int, int);
int fn_802B1D38(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

int fn_802B1DA0(void *arg0) {
    int tag = *(int *)arg0;
    switch (tag) {
    case 0x53494E44:
        return ((int *)arg0)[8];
    case 0x4E444C32:
        return ((int *)arg0)[7] - 2;
    default:
        return 0x3E8;
    }
}

extern int lbl_8055CDB8;
int stricmp(const char *, const char *);
int fn_802B1DE8(void **arg0) {
    return stricmp((char *)&lbl_8055CDB8, ((char *(**)(void *))(*(char ***)arg0))[2](arg0)) == 0;
}

void fn_802B1F64(void) {
}

void fn_802B1FC0(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_80128670(void *);
void fn_802B218C(void *);
void fn_8002F6AC(int, void (*)(void));
void fn_802B1F68(void);
void fn_80128668(void *);
void fn_802B2104(void **arg0);
void fn_802CAC54(void);
void fn_802C6C20(void);
int fn_80129D90(int, int, int);

void fn_802B2104(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            fn_802B218C(ptr);
            if ((char *)ptr + 4 != 0) {
                fn_8002F6AC(((int *)ptr)[4], fn_802B1F68);
                if ((char *)ptr + 4 != 0) {
                    ((int *)ptr)[1] = 0;
                    ((int *)ptr)[2] = 0;
                    ((int *)ptr)[3] = 0;
                }
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
}

#pragma opt_common_subs off
void fn_802B218C(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != 0) {
        if (buf != 0) {
            fn_80128670((char *)buf - 0x10);
        }
        *(void **)arg0 = 0;
    }
}

void fn_802B21D4(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            if (((int *)ptr)[2] != -2) {
                fn_802CAC54();
                ((int *)ptr)[2] = -2;
            }
            if (((int *)ptr)[0] != 0) {
                fn_802C6C20();
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
}

int fn_80129D90(int, int, int);
void fn_802B2504(int *dst, int count) {
    int i;
    for (i = 0; i < count - 1; i++) {
        int idx = fn_80129D90(0, i + 1, count) * 4;
        int tmp = dst[i / 4];
        dst[i / 4] = dst[idx / 4];
        dst[idx / 4] = tmp;
    }
}

int fn_802B2E00(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_802B2E00(void *);
int fn_802B2E08(int);
int *fn_802B320C(int *, int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;
int fn_802B3340(int);
void fn_802B32E0(int *arg0) {
    int i = 0;
    do {
        fn_802B3340(*fn_802B320C(arg0, i));
        i++;
    } while (i < fn_802B2E00(arg0));
}

