// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma opt_tail_call on

extern void fn_8017A57C(void) __attribute__((noreturn));
extern void fn_801AC240(void *);
extern void fn_801AC254(void *);
extern void fn_801ABFF8(int **);
extern int lbl_80335940;
extern float lbl_805624D0;

extern void fn_8017B0B0(void *);
extern int lbl_8033585C[64];
extern float lbl_8055E3C8;
extern void fn_80179EE8(void *, unsigned int);
extern void fn_80128668(void *);
extern void *fn_801792F8(void);
extern void *fn_801284F8(int, ...);
extern int lbl_8055E5E4;
extern int lbl_8055E5EC;
extern int lbl_8055E5F0;
extern char lbl_80335718[];
extern char lbl_80335744[];
extern char lbl_80335808[];
extern void *lbl_80435628[];
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

extern void fn_8017A580(void *, int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
void fn_801AC184(void *arg0) {
    int t4;
    int t5;
    int t6;
    int t7;
    int t8;
    int t9;
    int t10;

    fn_801AC240(arg0);
    *(int *)((char *)arg0 + 0x3C) = *(int *)((char *)arg0 + 0x1EC);
    *(int *)((char *)arg0 + 0x40) = *(int *)((char *)arg0 + 0x1F0);
    *(int *)((char *)arg0 + 0x44) = *(int *)((char *)arg0 + 0x1F4);
    *(int *)((char *)arg0 + 0x48) = *(int *)((char *)arg0 + 0x1F8);
    t4 = *(int *)((char *)arg0 + 0x1FC);
    t5 = *(int *)((char *)arg0 + 0x200);
    t6 = *(int *)((char *)arg0 + 0x204);
    t7 = *(int *)((char *)arg0 + 0x208);
    t8 = *(int *)((char *)arg0 + 0x20C);
    t9 = *(int *)((char *)arg0 + 0x210);
    t10 = *(int *)((char *)arg0 + 0x214);
    *(int *)((char *)arg0 + 0x4C) = t4;
    *(int *)((char *)arg0 + 0x50) = t5;
    *(int *)((char *)arg0 + 0x54) = t6;
    *(int *)((char *)arg0 + 0x58) = t7;
    *(int *)((char *)arg0 + 0x5C) = t8;
    *(int *)((char *)arg0 + 0x60) = t9;
    *(int *)((char *)arg0 + 0x64) = t10;
    *(int *)((char *)arg0 + 0x68) = *(int *)((char *)arg0 + 0x218);

    fn_8017A580(arg0, t10, t9, t8, t7, t6, t5, t4);
    fn_8017B164(arg0);
    *(unsigned char *)((char *)arg0 + 0x223) = 1;
    *(unsigned char *)((char *)arg0 + 0x234) = *(unsigned char *)((char *)arg0 + 0x235);
}

#pragma dont_inline on
void fn_801AC240(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x220) = 1;
    *(float *)((char *)arg0 + 0x21C) = lbl_8055E3C8;
}
#pragma dont_inline off

void fn_801AC254(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x220) != 0) {
        *(unsigned char *)((char *)arg0 + 0x220) = 0;
    }
}

void *fn_801AC26C(void) {
    void *obj = fn_801284F8(0x244, &lbl_80335718);
    if (obj != 0) {
        fn_801A9700(obj);
        *(void **)obj = &lbl_80335744;
        *(void **)((char *)obj + 0x23C) = (char *)&lbl_80335744 + 0x54;
    }
    return obj;
}

void *fn_801AC330(void *arg0) {
    fn_801A9700(arg0);
    *(void **)arg0 = &lbl_80335808;
    if (lbl_8055E5EC == 0) {
        lbl_8055E5F0 = 0;
    }
    *(int *)((char *)arg0 + 0x250) = lbl_8055E5EC;
    lbl_8055E5EC = lbl_8055E5EC + 1;
    lbl_80435628[*(int *)((char *)arg0 + 0x250)] = arg0;
    *(int *)((char *)arg0 + 0x254) = -1;
    return arg0;
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

short fn_801ADA84(void *arg0) {
    return *(short *)((char *)arg0 + 0x6C);
}

long fn_801ADA8C(long arg0) { return arg0 + 0x118; }

long fn_801ADA94(long arg0) {
    return arg0 + 0x60;
}

extern float lbl_8055E3C8;
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

