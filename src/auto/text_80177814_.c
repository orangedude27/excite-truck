// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80179EE8(void*, unsigned int);
void fn_80128668(void*);
extern unsigned char lbl_8055E46C;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055A304;
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

void fn_80178DD0(void) {
    fn_80177990();
}

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
