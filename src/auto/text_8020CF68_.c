// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct Item8020D2D4Head {
    int a;
    float b;
    float c;
    int d;
} Item8020D2D4Head;

typedef struct Item8020D2D4 {
    Item8020D2D4Head h;
    float e;
    float f;
    unsigned int color;
} Item8020D2D4;

typedef struct Names8020D2D4 {
    char *s[3];
} Names8020D2D4;

#pragma cplusplus on
class Dummy_8020D2D4 {
public:
    virtual void m0(const char *);
    virtual void m1(const char *);
    virtual void m2(const char *);
    virtual Item8020D2D4 *m3(const char *);
};
#pragma cplusplus off

extern Names8020D2D4 lbl_802F9E58;
extern char lbl_8055B630[], lbl_8055B638[], lbl_8055B63C[];
extern float lbl_80563324, lbl_80563328, lbl_80563330, lbl_80563334, lbl_80563338, lbl_8056333C;
extern float lbl_80563340, lbl_80563344, lbl_80563348, lbl_8056334C, lbl_80563350, lbl_80563354, lbl_80563358, lbl_8056335C;
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(float, float, float);
extern void fn_800109E4(int, float, float, float, float);
extern char *fn_80131234(const char *);
extern void fn_801473F8(int, const char *, const char *, const char *);
extern void fn_801345D8(char *, int, const char *, ...);
extern char *fn_8000C69C(void);
extern void fn_80230F78(unsigned char *, float *, unsigned int *, int);
extern void fn_80147940(int, Item8020D2D4 *, const char *, int, ...);
extern void fn_80147230(Item8020D2D4 *, const char *, const char *);
extern void fn_801476C4(void);
extern void fn_80011A2C(void);
extern void fn_802C9904(void);
extern int lbl_8055EE74, lbl_8055EE78, lbl_8055EEA0;
extern void *lbl_8055EE7C, *lbl_8055EE80;
extern char lbl_8055EE94;
extern float lbl_8055EE84, lbl_8055EE88, lbl_8055EE8C, lbl_8055EE90, lbl_8055EE98, lbl_8055EE9C;
extern float lbl_8056331C, lbl_80563320;
extern float lbl_8056332C;
__declspec(section ".data") extern float lbl_80558DC4;
extern double lbl_80563360;
extern int fn_802E2C20(void);
extern void fn_80012158(void);
extern void fn_8020CF6C(int);
extern double fabs(double);
extern char lbl_8033C6B0[], lbl_8033C6BC[];
extern float lbl_80563318;
extern void fn_8020C908(float);
extern void fn_8000C6E4(void);
extern void fn_80209190(int, float);
extern void fn_80206454(void);
extern void fn_801769EC(void);
extern void fn_80206444(void);
extern float fn_80209028(void);
extern float fn_8020A5F0(void);
extern int fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80230E90(int);
extern void *fn_802090D4(void *);
extern void *fn_80145E70(void *);
extern void fn_80209110(void *);
#pragma cplusplus on
class Dummy_8020D1C8 {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2(int);
};
#pragma cplusplus off

int fn_8020CF68(void) {
    return fn_802104D0();
}

#pragma push
#pragma scheduling invalid_target
void fn_8020CF6C(int arg0) {
    float value;

    if (arg0 == 1)
        goto case_one;
    if (arg0 < 1) {
        if (arg0 >= 0)
            goto case_zero;
        return;
    }
    if (arg0 == 4)
        goto case_four;
    return;

case_one:
    value = lbl_80563318 + lbl_8055EE8C;
    if (value < lbl_8056331C)
        value = lbl_8056331C;
    lbl_8055EE8C = value;
    fn_8020C908(value);
    return;

case_zero:
    value = lbl_80563318 + lbl_8055EE90;
    if (value < lbl_8056331C)
        value = lbl_8056331C;
    lbl_8055EE90 = value;
    return;

case_four:
    fn_8000C6E4();
    return;
}
#pragma pop
extern float lbl_80563318;
extern void fn_8020A5F8(float);
extern void fn_8020C908(float);
extern void fn_80209030(float);
extern void fn_8013323C(int, char *, float);
extern void fn_800121F0(void);
extern void fn_8000C730(void);
extern void fn_8020D0CC(int);
extern int lbl_8055EE78;
extern float lbl_8055EE8C, lbl_8055EE90, lbl_8055EE98, lbl_8055EE9C;
extern float lbl_80563320;
extern char lbl_8033C690[], lbl_8033C6A0[];
extern void fn_8000C6E4(void);
void fn_8020CFEC(int arg0) {
    float value;
    if (arg0 == 1)
        goto case_one;
    if (arg0 >= 1)
        goto check_four;
    if (arg0 >= 0)
        goto case_zero;
    return;
check_four:
    if (arg0 == 4)
        goto call_four;
    return;
case_one:
    value = lbl_8055EE8C - lbl_80563318;
    if (value > lbl_80563320)
        lbl_8055EE8C = lbl_80563320;
    else
        lbl_8055EE8C = value;
    fn_8020C908(lbl_8055EE8C);
    return;
case_zero:
    value = lbl_8055EE90 - lbl_80563318;
    if (value > lbl_80563320)
        lbl_8055EE90 = lbl_80563320;
    else
        lbl_8055EE90 = value;
    return;
call_four:
    fn_8000C730();
}

void fn_8020D06C(void) {
    fn_8020A5F8(lbl_8055EE8C);
    fn_8020C908(lbl_8055EE8C);
    fn_80209030(lbl_8055EE90);
    fn_8013323C(4, lbl_8033C690, lbl_8055EE8C);
    fn_8013323C(4, lbl_8033C6A0, lbl_8055EE90);
    fn_800121F0();
}

void fn_8020D0CC(int arg0) {
    int value;
    value = (lbl_8055EE78 + arg0 + 3) % 3;
    lbl_8055EE78 = value;
    if (value == 2 && ((int (*)(void))fn_8020CF68)() == 0)
        lbl_8055EE78 = (lbl_8055EE78 + arg0 + 3) % 3;
    fn_80230E90(1);
    lbl_8055EE9C = lbl_80563320;
    lbl_8055EE98 = lbl_80563320;
}

void fn_8020D178(void) {
    lbl_8055EE74 = (int)fn_802090D4(lbl_8033C6B0);
    fn_80209190(lbl_8055EE74, lbl_8056331C);
    lbl_8055EE7C = 0;
    lbl_8055EE80 = 0;
    lbl_8055EEA0 = (int)fn_80145E70(lbl_8033C6BC);
}

#pragma cplusplus on
extern "C" void fn_8020D1C8(void) {
    struct Dummy_8020D1C8_Local {
        virtual void d1(int);
    };
    Dummy_8020D1C8_Local *obj = (Dummy_8020D1C8_Local *)lbl_8055EEA0;
    if (obj != 0) {
        if (obj != 0) {
            obj->d1(1);
        }
        lbl_8055EEA0 = 0;
    }
    fn_80209110(&lbl_8055EE74);
    lbl_8055EE7C = 0;
    lbl_8055EE80 = 0;
}
#pragma cplusplus off
void fn_8020D224(void) {
    float value;
    lbl_8055EE94 = 1;
    value = fn_80209028();
    lbl_8055EE90 = value;
    lbl_8055EE88 = value;
    value = fn_8020A5F0();
    lbl_8055EE8C = value;
    lbl_8055EE84 = value;
    if (fn_80265D64() == 0)
        __AXDSPInitCallback_801769E0();
    fn_80206444();
    fn_80209190(lbl_8055EE74, lbl_80563320);
    lbl_8055EE78 = 0;
    lbl_8055EE9C = lbl_80563320;
    lbl_8055EE98 = lbl_80563320;
    fn_80230E90(1);
}

void fn_8020D29C(void) {
    fn_80209190((lbl_8055EE94 = 0, lbl_8055EE74), lbl_8056331C);
    fn_80206454();
    fn_801769EC();
}
#pragma dont_inline on
void fn_8020DABC(void) {
    fn_8020C908(lbl_8055EE8C);
    fn_80209030(lbl_8055EE90);
    fn_800121F0();
    if (lbl_8055EE78 == 2 && ((int (*)(void))fn_8020CF68)() == 0)
        fn_8020D0CC(-1);
}
#pragma push
#pragma processor 750
int fn_8020DB0C(int arg0) {
    int var_r31 = 1;

    switch (arg0) {
    case 0x126:
        fn_8020D0CC(-1);
        break;
    case 0x128:
        fn_8020D0CC(1);
        break;
    case 0x125:
        switch (lbl_8055EE78) {
        case 0:
            if (!(__fabsf(lbl_8055EE8C) <= lbl_80558DC4)) {
                lbl_8055EE98 = lbl_8056332C * (float)fn_802E2C20();
            } else {
                var_r31 = 0;
            }
            break;
        case 1:
            if (!(__fabsf(lbl_8055EE90) <= lbl_80558DC4)) {
                lbl_8055EE98 = lbl_8056332C * (float)fn_802E2C20();
            } else {
                var_r31 = 0;
            }
            break;
        case 4:
            lbl_8055EE98 = lbl_8056332C * (float)fn_802E2C20();
            break;
        default:
            var_r31 = 0;
            break;
        }
        fn_8020CFEC(lbl_8055EE78);
        break;
    case 0x127:
        switch (lbl_8055EE78) {
        case 0:
            if (lbl_8055EE8C < lbl_8056331C) {
                lbl_8055EE9C = lbl_8056332C * (float)fn_802E2C20();
            } else {
                var_r31 = 0;
            }
            break;
        case 1:
            if (lbl_8055EE90 < lbl_8056331C) {
                lbl_8055EE9C = lbl_8056332C * (float)fn_802E2C20();
            } else {
                var_r31 = 0;
            }
            break;
        case 4:
            lbl_8055EE9C = lbl_8056332C * (float)fn_802E2C20();
            break;
        default:
            var_r31 = 0;
            break;
        }
        fn_8020CF6C(lbl_8055EE78);
        break;
    case 0x58:
    case 0xD:
        if (lbl_8055EE7C != 0 && lbl_8055EE78 == 2) {
            ((void (*)(int, int))lbl_8055EE7C)(lbl_8055EE78, arg0);
            fn_8020D06C();
            break;
        }
        return 0;
    case 0x53:
        if (lbl_8055EE7C != 0) {
            ((void (*)(int, int))lbl_8055EE7C)(lbl_8055EE78, arg0);
            fn_8020D06C();
        }
        break;
    case 0x1B:
    case 0x113:
        var_r31 = 0;
        break;
    default:
        return 0;
    }
    if (var_r31 != 0) {
        fn_80012158();
    }
    return 1;
}
#pragma pop
extern void *lbl_8055EE7C;
extern void *lbl_8055EE80;
void AXFXSetHooks_8020DE10(void *arg0, void *arg1) {
    lbl_8055EE7C = arg0;
    lbl_8055EE80 = arg1;
}

extern char lbl_8055EE94;
char fn_8020DE1C(void) {
    return lbl_8055EE94;
}