// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma dont_inline on
int fn_802B2E00(void *);
int *fn_802B320C(int *, int);
#pragma dont_inline reset
int fn_802B2E08(int);
int fn_802B3340(int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;

int fn_8012C33C(void);
int fn_802CAC28(int, int);
extern void fn_80128668(void *);
void *fn_802B1CE0(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

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
    void **vtable = (void **)*arg0;
    char *(*method)(void *) = (char *(*)(void *))vtable[2];
    return stricmp((char *)&lbl_8055CDB8, method(arg0)) == 0;
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

#pragma push
#pragma opt_common_subs off
void fn_802B2104(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            fn_802B218C(ptr);
            if ((char *)ptr + 4 != 0) {
                fn_8002F6AC(((int *)ptr)[4], (void (*)(void))fn_802B1F68);
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
#pragma pop
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
    int limit = count - 1;
    for (i = 0; i < limit; i++) {
        int j = fn_80129D90(0, i + 1, count);
        int tmp = *(int *)((char *)dst + i * 4);
        *(int *)((char *)dst + i * 4) = *(int *)((char *)dst + j * 4);
        *(int *)((char *)dst + j * 4) = tmp;
    }
}

void fn_802B2D94(int *arg0) {
    int i;
    i = 0;
    lbl_8055F9B4 = 0;
    lbl_8055F9B0 = 0;
    do {
        fn_802B2E08(*fn_802B320C(arg0, i));
        i++;
    } while (i < fn_802B2E00(arg0));
}

int fn_802B2E00(void *arg0) {
    return ((int *)arg0)[1];
}

int *fn_802B320C(int *arg0, int arg1) {
    return (int *)((char *)*arg0 + arg1 * 4);
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

void *fn_802B3DA4(void *arg0, int arg1, int arg2) {
    void *result = 0;
    if (arg2 >= 0 && arg2 < ((int *)arg0)[1]) {
        void *items = *(void **)arg0;
        void *entry = (char *)((void **)items)[arg2] + ((arg1 & 0x7F) * 4);
        void *obj = *(void **)((char *)entry + 0x208);
        if (obj != 0 && *(int *)*(void **)((char *)obj + 0xC) != 0) {
            result = (char *)obj + 0x10;
        }
    }
    return result;
}

int fn_802B3F0C(void *arg0) {
    return ((int *)arg0)[1];
}

typedef struct {
    void *m0;
    void *m4;
    void *m8;
    void *mC;
    void *m10;
    void *m14;
    void *m18;
    void *m1C;
    void *m20;
    void *m24;
    void *m28;
    void *m2C;
    void *m30;
    void *m34;
    void *m38;
    void *m3C;
    void *m40;
    void *m44;
    void *m48;
    void *m4C;
    void *m50;
    void *m54;
    void (*m58)(void);
    int (*m5C)(void);
} Unk802B2C44;

typedef struct {
    void *m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
} Unk802B2C98;
extern Unk802B2C98 lbl_804BE1FC;

extern int lbl_8055F9B8;
extern void *lbl_8055F9BC;

int fn_802B2C44(void *arg0) {
    int **vt = (int **)arg0;
    int (*fn)(void) = (int (*)(void))(*vt)[0x17];
    return fn() != 0;
}

int fn_802B2C98(char *arg0) {
    int result = 0;
    int i;
    for (i = 0; i < lbl_804BE1FC.m4; i++) {
        if (stricmp(arg0, *(char **)((char *)((void **)lbl_804BE1FC.m0)[i] + 0x24)) == 0) {
            result = (int)((void **)lbl_804BE1FC.m0)[i];
            break;
        }
    }
    return result;
}

void fn_802B2D24(void *arg0) {
    int i, j;
    for (i = 0; i < ((int *)arg0)[1]; i++) {
        void *cur = ((void **)arg0)[i];
        ((int *)lbl_8055F9BC)[2] = 0;
        for (j = 0; j < ((int *)cur)[0x103]; j++) {
            void **arr = *(void ***)((char *)cur + 0x408);
            void *entry = arr[j];
            ((int *)entry)[5] = 0;
            ((int *)entry)[4] = 0;
        }
    }
    lbl_8055F9B8 = 0;
}
