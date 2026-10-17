// Code of main that had no source file yet: decomp.wtf gave it this one.
extern float lbl_80563490;
extern int fn_802368B4(int);
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EFAC;
int fn_80216D14(int arg0) {
    int result = 1 << arg0;
    return result & ~(arg0 >> 31);
}

void fn_80216D28(void) {
    lbl_8055EFAC = 1;
}

void fn_80216D34(void) {
    lbl_8055EFAC = 0;
}

void fn_8021734C(void *arg0) {
    int i;
    char *base = (char *)arg0;
    for (i = 0; i < *(int *)(base + 0x430); i++) {
        void *obj = *(void **)(base + i * 4 + 0x30);
        void **vtable = *(void ***)obj;
        ((void (*)(void *))vtable[3])(obj);
        if (*(int *)(base + 0x440) != 0) {
            int value = *(int *)((char *)obj + 0x23C);
            if (*(int *)((char *)obj + 0x240) != 0) value = **(int **)((char *)obj + 0x240);
            fn_802368B4(value);
        }
    }
    if (*(void **)(base + 0x438) != 0) (*(void (**)(void))((char *)base + 0x438))();
}

void fn_802173F8(void *arg0) {
    char *base = (char *)arg0;
    int i;
    if (*(void **)(base + 0x43C) != 0) (*(void (**)(void))((char *)base + 0x43C))();
    i = *(int *)(base + 0x430) - 1;
    while (i >= 0) {
        void *obj = *(void **)(base + i * 4 + 0x30);
        void **vtable = *(void ***)obj;
        ((void (*)(void *))vtable[4])(obj);
        i--;
    }
    fn_80216D28();
}

void fn_80217478(void) {

}

extern int fn_802368B4(int);
extern void fn_80216D28(void);
void fn_8021747C(void *arg0, void *arg1, void *arg2) {
    void (*callback)(void *, void *, void *) = *(void (**)(void *, void *, void *))((char *)arg0 + 0x440);
    if (callback != 0) callback(arg0, arg1, arg2);
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

void fn_802180E0(void *arg0, int arg1) {
    extern void fn_802E30C8(const char *, ...);
    extern char lbl_8033D83C[];
    if (arg1 >= 0 && arg1 < *(int *)((char *)arg0 + 0x494)) {
        *(int *)((char *)arg0 + 0x498) = *(int *)((char *)arg0 + 0x4A0 + arg1 * 8);
        return;
    }
    fn_802E30C8(lbl_8033D83C);
}

int fn_80218120(void *arg0) {
    extern void fn_802E30C8(const char *, ...);
    extern char lbl_8033D860[];
    int i;
    int count = *(int *)((char *)arg0 + 0x494);
    for (i = 0; i < count; i++) {
        if (*(int *)((char *)arg0 + 0x498) == *(int *)((char *)arg0 + 0x4A0 + i * 8)) return i;
    }
    fn_802E30C8(lbl_8033D860);
    return 0;
}

void fn_8021818C(void *arg0) {
    *(int *)((char *)arg0 + 0x498) = -1;
}

void fn_80218198(void *arg0, void **arg1) {
    void **old = *(void ***)((char *)arg0 + 0x450);
    if (arg1 != old) {
        if (old != 0) (*(void (**)(void *))(*(void ***)old + 0x38))(old);
        *(void ***)((char *)arg0 + 0x450) = arg1;
        if (arg1 != 0) (*(void (**)(void *))(*(void ***)arg1 + 0x34))(arg1);
    }
}

extern float lbl_80563490;
void fn_802184D0(void *arg0) {
    int i;
    char *base = (char *)arg0;
    float threshold = lbl_80563490;
    for (i = 0; i < *(int *)(base + 0x430); i++) {
        void *obj = *(void **)(base + 0x30 + i * 4);
        if (*(unsigned char *)((char *)obj + 0x1A) != 0 ||
            *(float *)((char *)obj + 0x20) >= threshold) {
            void **vtable = *(void ***)obj;
            ((void (*)(void *))vtable[11])(obj);
        }
    }
}

extern int qsort(void *, int, int, int (*)(const void *, const void *), void *);
int fn_80217BC8(int *, int *);
