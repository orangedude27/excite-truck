// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8056002C;
extern char lbl_8034DB28[];
extern void fn_802E86D4(void);
extern void fn_802E870C(void);
extern int fn_802E8744(void *);
extern void fn_80127464(void);

void fn_802E8838(void) {
    fn_80127464();
}

void fn_802E883C(void) {
    if (lbl_8056002C == 0) {
        fn_802E86D4();
    }
    lbl_8056002C += 1;
}

void fn_802E8874(void) {
    lbl_8056002C -= 1;
    if (lbl_8056002C == 0) {
        fn_802E870C();
    }
}

int fn_802E888C(int arg0) {
    int result;
    ((void (*)(void))fn_802E883C)();
    result = fn_802E8744(lbl_8034DB28 + arg0 * 0x38);
    ((void (*)(void))fn_802E8874)();
    return result;
}

void fn_802E8918(void) {
    fn_802E2E38(1);
}

extern void *lbl_80560024;
void fn_802E8D7C(void* hi) {
    lbl_80560024 = hi;
}

typedef unsigned int u32;
extern int fn_802E95E0(void *, void (*)(void), int);
extern int fn_802E2C20(void);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034E024[];
extern int lbl_80507288;
extern unsigned char lbl_80560035;
extern char lbl_8034E0BC[];
extern int fn_802ECC10(void);
extern char lbl_8034E130[];
extern void fn_802E317C(const char *, ...);
extern void fn_802E6B94(void);
extern void fn_802E6B50(void);
extern void fn_80127D58(void *);
extern void fn_80128670(int);
extern void fn_801282F4(void);
extern void fn_801282EC(int);
extern int fn_8012850C(int, const char *);
extern void fn_80127C90(void *, void *);
extern void fn_802E2E0C(void *, void *);
extern int NANDInit(void);
extern void fn_802E8838(void);
extern void fn_802E9010(void);
extern void fn_802E8C6C(int);
extern char lbl_8034DF00[];
extern char lbl_8034DED4[];
extern char lbl_8034DEF4[];
extern int lbl_80560020;
extern char lbl_8055D248;
extern char lbl_8055D250;
extern char lbl_8034DEC4[];
u32 fn_802E8D84(void) { return 1; }

int fn_802E91AC(int *arg0) { return *arg0 == 0; }

extern int fn_802E2C20(void);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034E024[];
extern int lbl_80507288;
extern unsigned char lbl_80560035;
extern char lbl_8034E0BC[];
extern int fn_802ECC10(void);
extern int fn_802E888C(int);
extern char lbl_8034E130[];
void fn_802E91D8(void *arg0, const char *arg1, int arg2, int arg3) {
    char *dst = (char *)arg0 + 0xC;
    int count = 0x100;
    *(int *)((char *)arg0 + 8) = arg2;
    *(int *)((char *)arg0 + 4) = arg3;
    while (count-- > 0) {
        char c = *arg1++;
        *dst++ = c;
        if (c == 0)
            break;
    }
    if (count == 0)
        dst[-1] = 0;
    *(void **)((char *)arg0 + 0x198) = arg0;
    *(int *)((char *)arg0 + 0x258) = 0;
    *(char *)((char *)arg0 + 0x250) = 0;
    *(int *)((char *)arg0 + 0x254) = 0;
    *(int *)arg0 = 2;
    fn_802E30C8(lbl_8034E130, arg3, arg1);
}

void fn_802E986C(void) {}

void fn_802E9870(void) {}

void fn_802E9874(void) {}

void fn_802E9878(void) {}

void fn_802E987C(void) {}

void fn_802E9880(void) {}

void fn_802E9884(void) {}

void fn_802E9888(void) {}

