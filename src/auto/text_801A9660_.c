// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma opt_tail_call on

extern void fn_8017A57C(void) __attribute__((noreturn));

extern void fn_8017B0B0(void *);
extern int lbl_8033585C[64];
extern void fn_80179EE8(void *, unsigned int);
extern void fn_80128668(void *);
extern void *fn_801792F8(void);
extern void *fn_801284F8(int, ...);
extern void fn_801AC330(void);
extern void fn_801AC26C(void);
extern void fn_802E317C(const char *, ...);
extern void **fn_801A9700(void **);
extern int lbl_8055E3C4;
extern int lbl_8055A858;
extern int jumptable_80335578[];
void fn_801A9660(void) {
    unsigned int index = *(unsigned int *)((char *)fn_801792F8() + 0x50) - 6;
    if (index < 0x11) {
        ((void (*)(void))jumptable_80335578[index])();
        return;
    }
    if (fn_801284F8(0x23c, &lbl_8055A858) != 0) fn_801A9700(0);
}

#pragma scheduling off
void** fn_801A9700(void** arg0) {
    fn_8017B0B0(arg0);
    *arg0 = &lbl_8033585C;
    return arg0;
}
#pragma scheduling on
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801A973C(void *this_, int flag) {
    if (this_) {
        if (this_ != 0) fn_80179EE8(this_, 0);
        if (flag > 0) fn_80128668(this_);
    }
    return this_;
}

void fn_801ABFF4(void) {
    fn_8017A57C();
}

void fn_801AC184(void *arg0) {
    void *p = arg0;
    int a = *(int *)((char *)p + 0x1EC);
    int b = *(int *)((char *)p + 0x1F0);
    int c = *(int *)((char *)p + 0x1F4);
    int d = *(int *)((char *)p + 0x1F8);
    int e = *(int *)((char *)p + 0x1FC);
    int f = *(int *)((char *)p + 0x200);
    int g = *(int *)((char *)p + 0x204);
    int h = *(int *)((char *)p + 0x208);
    int i = *(int *)((char *)p + 0x20C);
    int j = *(int *)((char *)p + 0x210);
    int k = *(int *)((char *)p + 0x214);
    int l = *(int *)((char *)p + 0x218);
    *(int *)((char *)p + 0x3C) = a;
    *(int *)((char *)p + 0x40) = b;
    *(int *)((char *)p + 0x44) = c;
    *(int *)((char *)p + 0x48) = d;
    *(int *)((char *)p + 0x4C) = e;
    *(int *)((char *)p + 0x50) = f;
    *(int *)((char *)p + 0x54) = g;
    *(int *)((char *)p + 0x58) = h;
    *(int *)((char *)p + 0x5C) = i;
    *(int *)((char *)p + 0x60) = j;
    *(int *)((char *)p + 0x64) = k;
    *(int *)((char *)p + 0x68) = l;
    fn_8017A580(p, l, k, j, i, h, g, f, e);
    fn_8017B164(p);
    *(unsigned char *)((char *)p + 0x223) = 1;
    *(unsigned char *)((char *)p + 0x234) = *(unsigned char *)((char *)p + 0x235);
}

void fn_801AC254(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x220) != 0) {
        *(unsigned char *)((char *)arg0 + 0x220) = 0;
    }
}

void fn_801AD5EC(void) {
    fn_801AC508();
}

void fn_801AD5F0(void) {
    fn_801ACF94();
}

unsigned char fn_801AD860(void *arg0) {
    return ((unsigned char *)arg0)[0x220];
}

long fn_801AD868(void) {
    return 0;
}

void fn_801AD870(void *arg0, void *arg1, void *arg2, long *arg3, long *arg4) {
    *arg4 = 0;
    *arg3 = 0;
}

long fn_801AD880(void) {
    return 0;
}

unsigned char fn_801ADA7C(void *arg0) {
    return ((unsigned char *)arg0)[0x220];
}

long fn_801ADA8C(long arg0) { return arg0 + 0x118; }

long fn_801ADA94(long arg0) {
    return arg0 + 0x60;
}

extern void fn_801AC240(void *);
typedef void (*Fn801ADA9C)(void *, void *, void *);
extern unsigned char lbl_8055A8A0;
extern unsigned char lbl_8055A8B0;
void fn_801ADA9C(void *arg0) {
    (*(void (**)(void *, void *, void *))(*(char **)*(void **)((char *)arg0 + 0x240) + 0x18))(*(void **)((char *)arg0 + 0x240), &lbl_8055A8A0, &lbl_8055A8B0);
}

long fn_801ADAB8(void *arg0) {
    return *(long *)((char *)arg0 + 0x240);
}

void fn_801ADAC0(void *arg0, long arg1) {
    fn_801AC240((void *)arg1);
}

