// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_80258354(void);
extern int lbl_80344DE0[];
extern void *lbl_8055F394;
extern int fn_802C6CF8(int);
extern int fn_802CAC54(int);
extern int fn_80128668(void *);
extern int lbl_80345158;
void fn_80259148(void) {
    int *base = lbl_80344DE0;
    void *obj = fn_80258354();
    void **vtable;
    lbl_8055F394 = obj;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, base, (char *)base + 0x10, 0);
    obj = lbl_8055F394;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, (char *)base + 0x20, (char *)base + 0x30, 0);
    obj = lbl_8055F394;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, (char *)base + 0x40, (char *)base + 0x50, 1);
}

int fn_8025921C(void) { return 0; }

void *fn_80259680(void *arg0, int arg1) {
    volatile int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 0x50);
        *(int **)arg0 = &lbl_80345158;
        if (value != -1) {
            fn_802C6CF8(value);
            *(int *)((char *)arg0 + 0x50) = -1;
        }
        fn_802CAC54(*(int *)((char *)arg0 + 0xA8));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_80259700(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

extern double sin(double);
typedef unsigned int u32;
typedef float f32;
extern f32 lbl_80563B1C;
f32 fn_8025B0A8(void *arg0) {
    f32 a = *(f32 *)((char *)arg0 + 0);
    f32 b = *(f32 *)((char *)arg0 + 4);
    return a + ((b - a) * lbl_80563B1C);
}

void fn_8025B0E8(void *dst, const void *src) {
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

void fn_8025B134(void) {
}

extern void *fn_80258354(void);
extern int fn_802C6CF8(int);
extern int fn_802CAC54(int);
extern int fn_80128668(void *);
extern int lbl_80344DE0[];
extern void *lbl_8055F394;
extern int lbl_80345158;
