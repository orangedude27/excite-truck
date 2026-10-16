// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern double fn_8002EFB0();
extern void fn_8029231C();
extern void PSVECNormalize(void *, void *);
extern void *fn_801284F8(int, void *);
extern int lbl_8033A6A0;
extern int lbl_8033A710;
void fn_801F224C(void) {
    void *p = fn_801284F8(8, &lbl_8033A6A0);
    if (p != 0) {
        *(void **)p = &lbl_8033A710;
        *(int *)((char *)p + 4) = 0;
    }
}

int fn_801F2294(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F22D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F2314(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_801F3124(unsigned int *arg0, unsigned int *arg1) {
    unsigned int a, b, c, d;
    float e, f;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    d = arg1[3];
    e = ((float *)arg1)[4];
    f = ((float *)arg1)[5];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
    ((float *)arg0)[4] = e;
    ((float *)arg0)[5] = f;
}

void fn_801F3158(float *arg0, float *arg1) {
    float c, b, a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
}

float fn_801F3174(void) {
    return fn_8002EFB0();
}

void fn_801F3198(void *arg0) {
    PSVECNormalize(arg0, arg0);
}

void *fn_801F31A0(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(int *)((char *)arg0 + 0x3C) = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void fn_801F31E8(int arg0, volatile unsigned char *arg1) {
    volatile unsigned char *p = arg1 + 0x2C;
    int i;
    for (i = 0; i < 32; i++) {
        unsigned char t;
        t = p[0]; p[0] = p[3]; p[3] = t;
        t = p[1]; p[1] = p[2]; p[2] = t;
        t = p[4]; p[4] = p[7]; p[7] = t;
        t = p[5]; p[5] = p[6]; p[6] = t;
        t = p[8]; p[8] = p[11]; p[11] = t;
        t = p[9]; p[9] = p[10]; p[10] = t;
        t = p[12]; p[12] = p[15]; p[15] = t;
        t = p[13]; p[13] = p[14]; p[14] = t;
        p += 0x10;
    }
}

void fn_801F3280(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x3C) = arg1;
}

void fn_801F371C(int arg0) {
    fn_8029231C(arg0 + 4);
}

int fn_801F3724(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern int *fn_801F1CE8(int);
extern int fn_80128668(void);
extern int *fn_801E1F44(void);
extern int fn_802C9950(int);
void fn_801F3764(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 8) = *fn_801F1CE8(arg1);
    *(char *)((char *)arg0 + 4) = 1;
}

void fn_801F37A4(void) {
    if (*fn_801E1F44() == 1) {
        fn_802C9950(0xFF646464);
        return;
    }
    fn_802C9950(0xFF909090);
}

int fn_801F37FC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_801F383C(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 8) = *fn_801F1CE8(arg1);
    *(char *)((char *)arg0 + 4) = 1;
}

void fn_801F3B00(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 8) = *fn_801F1CE8(arg1);
    *(char *)((char *)arg0 + 4) = 1;
}

void fn_801F3E60(void) {

}

void fn_801F3E64(void) {

}

void fn_801F3EA0(void) {

}

void fn_801F3F88(void) {

}

void fn_801F4280(void) {

}

void fn_801F4330(void) {

}

void fn_801F4374(void) {

}

void fn_801F447C(void) {

}

void fn_801F4550(void) {

}

void fn_801F49F4(void) {

}

int fn_801F4B04(void) { return 4; }

int fn_801F4B0C(void) { return 3; }

void fn_801F4B14(void) {

}

extern int fn_801F1CF0(int);
extern int fn_802CDAFC(int, int);
extern int fn_802CDB20(int, int);
void fn_801F4C34(void *arg0, int arg1) {
    int *p = (int *)arg0;
    if (fn_802CDB20(arg1, p[2]) != 0 && fn_801F1CF0(p[1]) == 0) {
        fn_802CDAFC(arg1, p[2]);
    }
}

int fn_801F4C98(void) { return -1; }

void fn_801F4CA0(void) {

}

