// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma opt_tail_call on

extern void fn_8017A57C(void) __attribute__((noreturn));

extern void fn_8017B0B0(void *);
extern int lbl_8033585C[64];
extern float lbl_8055E3C8;
extern void fn_80179EE8(void *, unsigned int);
extern void fn_80128668(void *);
extern void *fn_801792F8(void);
extern void *fn_801284F8(int, ...);
extern void fn_801AC330(void);
extern void fn_801AC26C(void);
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

void fn_801AC184(void *arg0) {
    unsigned int *dst = (unsigned int *)((char *)arg0 + 0x3C);
    unsigned int *src = (unsigned int *)((char *)arg0 + 0x1EC);

    unsigned int t0 = src[0];
    unsigned int t1 = src[1];
    unsigned int t2 = src[2];
    unsigned int t3 = src[3];
    unsigned int t4 = src[4];
    unsigned int t5 = src[5];
    unsigned int t6 = src[6];
    unsigned int t7 = src[7];
    unsigned int t8 = src[8];
    unsigned int t9 = src[9];
    unsigned int t10 = src[10];
    unsigned int t11 = src[11];

    dst[0] = t0;
    dst[1] = t1;
    dst[2] = t2;
    dst[3] = t3;
    dst[4] = t4;
    dst[5] = t5;
    dst[6] = t6;
    dst[7] = t7;
    dst[8] = t8;
    dst[9] = t9;
    dst[10] = t10;
    dst[11] = t11;

    fn_8017A580((char *)arg0 + 0x3C, t11, t10, t9, t8, t7, t6, t5, t4);
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

