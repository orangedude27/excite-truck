// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern unsigned char lbl_8055E45E;
extern int lbl_80430590[];
extern int lbl_80430830[];

void fn_80179EE8(void*, unsigned int);
void fn_80128668(void*);
extern unsigned char lbl_8055E46C;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055A304;
void fn_801DCEC8(int arg0, float arg1);
void fn_801DCEDC(int arg0, float arg1);
extern float lbl_804305D4[];
extern float lbl_80430700[];
extern float lbl_80561B48;
void fn_802E8518(int arg0);
extern int lbl_8055E3C0;
extern unsigned char lbl_8055E3BD;
int fn_801CF064(void);
int fn_8018FD38(void);
extern void *lbl_804340C0[];
extern void **lbl_8055E434;
extern int lbl_8055E438;
extern int lbl_8055E468;
int fn_802E2C20(void);
extern int lbl_8055E464;
void fn_80177814(int *arg0) {
    *arg0 = (fn_802E2C20() + lbl_8055E464) % 30000;
    lbl_8055E464 += 0x9947;
    arg0[1] = (fn_802E2C20() + lbl_8055E464) % 30000;
    lbl_8055E464 += 0x2F1CD;
}

void fn_801778C0(void) {
    void **var_r31 = &lbl_804340C0[0];
    void **var_r28;
    int var_r30 = 0;
    int var_r29 = 0;

    lbl_8055E468 = 0;
    for (; var_r29 < lbl_8055E438; var_r29++, var_r30 += 4) {
        var_r28 = *(void **)(lbl_8055E434 + var_r30);
        if (((int (*)(void **))(*(void ***)*var_r28 + 0x44))(var_r28) != 0 &&
            ((int (*)(void **))(*(void ***)*var_r28 + 0x40))(var_r28) != 0) {
            var_r31[lbl_8055E468] = var_r28;
            lbl_8055E468 += 1;
        }
    }
}

long fn_80177980(void) {
    return 0;
}

long fn_80177988(void) {
    return 1;
}

void fn_80177990(void) {
    double temp_f31;
    float *var_r31;
    float *var_r30;
    int var_r29;

    temp_f31 = lbl_80561B48;
    var_r31 = &lbl_80430700[0];
    var_r30 = &lbl_804305D4[0];
    for (var_r29 = 0; var_r29 < 0x4b; var_r29++) {
        *var_r31 = (float)temp_f31;
        *var_r30 = (float)temp_f31;
        fn_801DCEC8(var_r29, (float)temp_f31);
        fn_801DCEDC(var_r29, lbl_80561B48);
        var_r31++;
        var_r30++;
    }
}

#pragma dont_inline on
void fn_80177A18(void) {
    int var_r31;

    var_r31 = 0;
    do {
        fn_802E8518(var_r31);
        var_r31 += 1;
    } while (var_r31 < 4);
}
#pragma dont_inline off

void fn_80177A54(void) {
    if (lbl_8055E3C0 == 2 && fn_801CF064() != 0 && fn_8018FD38() != 0) {
        lbl_8055E3C0 = 0;
    }
    switch (lbl_8055E3C0) {
    case 1:
        if (lbl_8055E3BD == 0) {
            fn_80177A18();
        }
        lbl_8055E3BD = 1;
        break;
    case 2:
        lbl_8055E3BD = 0;
        break;
    default:
        break;
    }
    lbl_8055E3C0 = 0;
}
#pragma dont_inline off
long fn_801781B8(void) { return 0; }

long fn_801781C0(unsigned int arg0) {
    switch (arg0) {
    case 0x13: return 1;
    case 0x14: return 1;
    case 0x15: return 1;
    case 0x16: return 1;
    case 0x17: return 1;
    case 0x18: return 1;
    case 0x19: return 1;
    case 0x1A: return 1;
    case 0x1B: return 1;
    case 0x1C: return 1;
    case 0x1D: return 1;
    case 0x1E: return 1;
    case 0x1F: return 1;
    default: return 0;
    }
}

unsigned char *fn_801781F4(long arg0) {
    volatile unsigned char *p = &lbl_8055E46C;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    *(volatile long *)p = arg0;
    a = p[0];
    c = p[3];
    b = p[1];
    p[0] = c;
    p[3] = a;
    p[1] = p[2];
    p[2] = b;
    return (unsigned char *)p;
}

void fn_80178224(void) {
    if (fn_801284F8(0x2780, &lbl_8055A304) != 0)
        fn_801A6484();
}

long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017831C(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80179EE8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_80178C88(void) {

}

void fn_80178C8C(void) {

}

extern void *lbl_8055E414;
void* fn_80178C9C(void) {
    return lbl_8055E414;
}

extern void *lbl_8055E444;
void* fn_80178CA4(void) {
    return lbl_8055E444;
}

#pragma dont_inline on
void fn_80178DD0(void) {
    fn_80177990();
}
#pragma dont_inline off

void fn_801791A4(void) {

}

void fn_801792F4(void) {
    fn_801E21B4();
}

extern void *lbl_8055E454;
void* fn_801792F8(void) {
    return lbl_8055E454;
}

extern void *lbl_8055E458;
void* fn_80179300(void) {
    return lbl_8055E458;
}

extern void *lbl_8055E448;
void* fn_80179318(void) {
    return lbl_8055E448;
}

void fn_801CEFE8(void);
void fn_801AED5C(void);
void fn_801CB464(void);
void fn_80179588(void) {
    fn_801CEFE8();
    fn_801AED5C();
    fn_801CB464();
}

void fn_801CF01C(void);
void fn_801CB4A0(void);
void fn_801AED68(void);
void fn_801795B0(void) {
    fn_801CF01C();
    fn_801CB4A0();
    fn_801AED68();
}

extern void *lbl_8055E430;
void* fn_80179650(void) {
    return lbl_8055E430;
}

extern char lbl_8055E45D;
char fn_801796B4(void) {
    return lbl_8055E45D;
}

void fn_801796BC(unsigned char arg0) {
    lbl_8055E45E = arg0;
}

extern char lbl_8055E45F;
char fn_801796C4(void) {
    return lbl_8055E45F;
}

void DBPrintf_80179758(const char *fmt, ...) {
#pragma unused(fmt)
}

void DBPrintf_801797A8(const char *fmt, ...) {
#pragma unused(fmt)
}
extern unsigned char lbl_8055E46C;
extern unsigned char lbl_8055A304;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055E45E;
extern long lbl_80430870;
extern long fn_8017873C(long *, long, long, long, long);
extern long lbl_80430850;
extern long fn_80178C1C(long *);
extern float lbl_80561B60;
extern double lbl_80561B70;
extern void *fn_80178374(void);
extern long fn_802E317C(const char *, long, ...);
extern const char lbl_80331B40[];
