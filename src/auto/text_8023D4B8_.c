// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F18C;
void* fn_8023D6FC(void) {
    return lbl_8055F18C;
}

extern void fn_801333E8(long, void *, char *);
extern void fn_80133460(void);
extern long fn_80137C74(void);
extern unsigned long __AXGetStackHead_80137CFC(long);
extern long lbl_803416A8;
extern long lbl_8055BC54;
extern long lbl_804987D0;
void fn_8023D704(long arg0) {
    lbl_8055F18C = (void *)arg0;
}

void fn_8023D70C(void) {
    char sp8;
    char sp9;
    char spA;
    char spB;
    char spC;
    long i = 0;
    long len;

    do {
        len = 0x10;
        if (i < 4) {
            len = i + 0xC;
        }
        spC = 1;
        spB = 1;
        spA = 0;
        sp9 = 0;
        sp8 = 1;
        fn_801333E8(len, &lbl_803416A8 + 0x368, &spC);
        fn_801333E8(len, &lbl_803416A8 + 0x378, &spB);
        fn_801333E8(len, &lbl_803416A8 + 0x38C, &spA);
        fn_801333E8(len, &lbl_803416A8 + 0x3A0, &sp9);
        fn_801333E8(len, &lbl_803416A8 + 0x3B0, &sp8);
        i++;
    } while (i < 5);
}

void fn_8023DA2C(long arg2, long arg3) {
    char sp8;

    sp8 = arg2;
    if (arg3 != 0) {
        fn_80133460();
        return;
    }
    fn_801333E8(0, 0, &sp8);
}

void fn_8023DB68(void) {
    long i = 0;
    long *dst = &lbl_804987D0;

    lbl_8055BC54 = fn_80137C74();
    while (i < lbl_8055BC54) {
        *dst = __AXGetStackHead_80137CFC(i);
        dst++;
        i++;
    }
}

extern int lbl_80341C40[];
extern int fn_801A902C(void);
extern void fn_801A9050(void *, int);
extern void fn_8023E33C();
int fn_8023E52C(int arg0) {
    return lbl_80341C40[arg0];
}

typedef signed int s32;
extern s32 lbl_80341C40[];
extern s32 fn_801A902C(void);
extern void fn_801A9050(void *, s32);
extern void fn_8023E33C(void *, s32, s32);
s32 fn_8023E540(s32 arg0) {
    return arg0 + 0x14;
}

int fn_8023E3D8(int, int);
void fn_8023E550(int arg0) {
    fn_8023E3D8(arg0, -1);
}

