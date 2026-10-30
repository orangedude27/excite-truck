// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma cplusplus on
namespace ebi {
namespace title {
class TPlaneSub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
};

class TBlackPlane {
public:
    TBlackPlane() {}
    void* m_pad;
    TPlaneSub* m_a;
    TPlaneSub* m_b;
    void updateAfterCamera();
};

class TPlaneObj {
public:
    char pad[0x1c];
    TPlaneSub* m_sub;
};
}
}
#pragma cplusplus reset
typedef struct Fn8027F958Widget {
    void *vtable;
    char pad04[0x10];
    int unk14;
    unsigned char unk18;
    char pad19[7];
    int unk20, unk24;
    char pad28[0x10];
    float unk38, unk3C;
    int unk40;
    unsigned char unk44;
    char pad45[0xB];
    unsigned char unk50;
    char pad51[0xB];
    unsigned char unk5C;
    char pad5D[3];
    void *object;
    unsigned char unk64;
    char pad65[0xB];
    int unk70;
    unsigned char unk74;
    char pad75[9];
    unsigned char unk7E;
    char pad7F[0x31];
    int unkB0;
    float values[6];
    unsigned char unkCC;
    char padCD[3];
} Fn8027F958Widget;
typedef struct Fn8027F958Entry {
    void *label;
    int type;
    void *value;
    int flags;
    int id;
} Fn8027F958Entry;
typedef struct Fn8027F958Menu {
    int header[5];
    Fn8027F958Entry entries[32];
    int footer[5];
} Fn8027F958Menu;
typedef struct Fn8027F958Local {
    int textIds[3][3];
    Fn8027F958Menu menu;
} Fn8027F958Local;
typedef struct Fn8027F958Stack {
    int textIds[3][3];
    Fn8027F958Menu menu;
    int pad;
    Fn8027F958Widget widgets[5];
} Fn8027F958Stack;

extern int fn_80128668();
extern void fn_8027E908(void);
extern char lbl_80348798[];
extern unsigned int lbl_8055F688;
struct Fn8027F834List { void **items; int count; int pad[2]; };
extern struct Fn8027F834List lbl_804B3048;

extern void *lbl_8055F680;
#pragma dont_inline on
#pragma push
#pragma cplusplus on
#pragma push
#pragma cplusplus on
extern "C" void *fn_80258354(void);
extern "C" const char *fn_80007F90(unsigned int);
extern "C" void *lbl_8055F680;
extern "C" char lbl_80347E50[];
extern "C" char lbl_8055C798;
extern "C" char lbl_8055C7A0;
extern "C" char lbl_8055C7A8;
extern "C" char lbl_8055C7B0;
extern "C" char lbl_8055C7B8;
extern "C" char lbl_8055C7C0;
extern "C" void fn_8027E908(void) {
    class InitObj {
    public:
        virtual void v0();
        virtual void v1(const void *, const void *, int);
        virtual void v2(const void *, const void *);
        virtual void v3(const void *, const void *, int);
        virtual void v4();
        virtual void v5();
    };
    register const char *base = lbl_80347E50;
    register unsigned int idBase = 0x180000;
    InitObj *object;
    const char *idName;
    const void *argA, *argB;
    object = (InitObj *)fn_80258354();
    lbl_8055F680 = object;
    argA = base+0x0;
    argB = base+0x14;
    object->v1(argA, argB, 4);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x24;
    argB = base+0x14;
    object->v1(argA, argB, 3);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x30;
    argB = base+0x14;
    object->v1(argA, argB, 1);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x3c;
    argB = base+0x14;
    object->v1(argA, argB, 2);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x48;
    argB = base+0x14;
    object->v1(argA, argB, 4);
    idName = fn_80007F90(idBase + 0x201);
    object = (InitObj *)lbl_8055F680;
    argA = idName;
    argB = base+0x58;
    object->v1(argA, argB, 1);
    idName = fn_80007F90(idBase + 0x302);
    object = (InitObj *)lbl_8055F680;
    argA = idName;
    argB = base+0x58;
    object->v1(argA, argB, 2);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x68;
    argB = base+0x58;
    object->v1(argA, argB, 1);
    object = (InitObj *)lbl_8055F680;
    argA = &lbl_8055C798;
    argB = base+0x78;
    object->v1(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = &lbl_8055C7A0;
    argB = base+0x78;
    object->v1(argA, argB, 1);
    object = (InitObj *)lbl_8055F680;
    argA = &lbl_8055C7A8;
    argB = base+0x78;
    object->v1(argA, argB, 2);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x88;
    argB = base+0x78;
    object->v1(argA, argB, 3);
    object = (InitObj *)lbl_8055F680;
    argA = &lbl_8055C7B0;
    argB = base+0x78;
    object->v1(argA, argB, 4);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x94;
    argB = base+0x78;
    object->v1(argA, argB, 5);
    object = (InitObj *)lbl_8055F680;
    argA = base+0xA0;
    argB = base+0xB4;
    object->v1(argA, argB, 1);
    object = (InitObj *)lbl_8055F680;
    argA = base+0xC0;
    argB = base+0xB4;
    object->v1(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0xD0;
    argB = base+0xE0;
    object->v1(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0xF0;
    argB = base+0xE0;
    object->v1(argA, argB, 1);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x100;
    argB = base+0x110;
    object->v1(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x120;
    argB = base+0x110;
    object->v1(argA, argB, 1);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x130;
    argB = base+0x140;
    object->v1(argA, argB, 6);
    object = (InitObj *)lbl_8055F680;
    object->v2(&lbl_8055C7B8, base+0x14C);
    object = (InitObj *)lbl_8055F680;
    object->v2(&lbl_8055C7C0, base+0x158);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x164;
    argB = base+0x174;
    object->v3(argA, argB, 1);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x180;
    argB = base+0x190;
    object->v3(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x1A0;
    argB = base+0x1AC;
    object->v3(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x1BC;
    argB = base+0x1D0;
    object->v3(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x1E0;
    argB = base+0x1D0;
    object->v3(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x1F8;
    argB = base+0x204;
    object->v3(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x214;
    argB = base+0x190;
    object->v3(argA, argB, 0);
    object = (InitObj *)lbl_8055F680;
    argA = base+0x228;
    argB = base+0x238;
    object->v3(argA, argB, 0);
}
#pragma cplusplus reset
#pragma pop

extern "C" void fn_8027ED2C(void) {
    class Obj {
    public:
        virtual void destroy(int);
    };
    if (lbl_8055F680 != 0) {
        ((Obj*)lbl_8055F680)->destroy(1);
    }
    lbl_8055F680 = 0;
}
#pragma cplusplus reset
#pragma pop
#pragma dont_inline reset

void* fn_8027ED70(void) {
    return lbl_8055F680;
}

extern int fn_802146BC(int *, int, int, int, int, int, int, int);
extern int lbl_802FA848;
extern int lbl_803480A8;
extern int lbl_804B2FF8;
extern int lbl_8055B860;
extern int lbl_8055C7C8;
__declspec(section ".data") extern int lbl_802FA848;
__declspec(section ".data") extern int lbl_804B2FF8;
__declspec(section ".data") extern int lbl_803480A8;
extern int lbl_8055C7C8, lbl_8055B860;
void fn_8027ED78(int arg0, int arg1, int arg2) {
    register int a0 = ((int *)&lbl_802FA848)[0];
    register int a2 = ((int *)&lbl_802FA848)[2];
    register int a3 = ((int *)&lbl_802FA848)[3];
    register int a4 = ((int *)&lbl_802FA848)[4];
    register int b0 = ((int *)&lbl_804B2FF8)[0];
    register int b1 = ((int *)&lbl_804B2FF8)[1];
    register int b2 = ((int *)&lbl_804B2FF8)[2];
    register int b3 = ((int *)&lbl_804B2FF8)[3];
    register int b4 = ((int *)&lbl_804B2FF8)[4];
    register int ptrA8 = (int)&lbl_803480A8;
    register int ptrC7 = (int)&lbl_8055C7C8;
    register int ptrB8 = (int)&lbl_8055B860;
    register int zero = 0;
    register int three = 3;
    register int six = 6;
    register int minusTwo = -2;
    register int thirteen = 13;
    int block[26];

    block[0] = a0;
    block[1] = (int)&block[6];
    block[2] = a2;
    block[3] = a3;
    block[4] = a4;
    block[6] = ptrC7;
    block[7] = three;
    block[8] = arg0;
    block[9] = zero;
    block[10] = zero;
    block[11] = ptrA8;
    block[12] = three;
    block[13] = arg1;
    block[14] = zero;
    block[15] = zero;
    block[16] = ptrB8;
    block[17] = six;
    block[18] = zero;
    block[19] = minusTwo;
    block[20] = thirteen;
    block[21] = b0;
    block[22] = b1;
    block[23] = b2;
    block[24] = b3;
    block[25] = b4;
    ((int (*)(int *, int, int, int, int))fn_802146BC)(
        block, -999, -999, 1, block[0]);
}

void fn_8027EE74(int arg0) {
    extern unsigned char lbl_8055F684;
    extern int fn_80236914(void);
    *(signed char*)&lbl_8055F684 = (arg0 == 2);
    fn_80236914();
}

#pragma cplusplus on
struct CareerObj_8027EE88 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(const char *);
};
#pragma cplusplus off

#pragma push
#pragma cplusplus on
#pragma dont_inline on
extern "C" unsigned char lbl_8055F684, lbl_8055F685;
extern "C" const char lbl_80348078[];
extern "C" void *fn_8027ED70(void);
extern "C" int fn_8027EE88(void) {
    if (lbl_8055F685 == 0 && lbl_8055F684 != 0) {
        lbl_8055F685 = 1;
        CareerObj_8027EE88 *obj = (CareerObj_8027EE88 *)fn_8027ED70();
        obj->f12(lbl_80348078);
    }
    return 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_8027EEE4(register int arg0) {
    extern void fn_801345D8(char *, int, const char *, ...);
    extern int fn_80131234(int);
    extern int lbl_802FA85C[];
    extern int lbl_802FA898[];
    extern char lbl_803481D0[];
    extern char lbl_803481F8[];
    extern char lbl_804B3018[];
    extern int lbl_8055C7D0;
    extern int lbl_8055C7D8;
    extern int lbl_8055BAB8;
    struct Frame {
        int prefix[8];
        int objects[6][5];
        char buffer[100];
    } frame;
    register int zero = 0;
    register int zero1 = 0;
    register int zero2 = 0;
    register int three;
    register int two;
    register int q1;
    register int q2;
    register int q3;
    register int q4;
    register int b0;
    register int b1;
    register int b2;
    register int b3;
    register int b4;
    register void *func;
    register int six;
    register int minusTwo;
    register int thirteen;
    register int eight;
    register int index;
    int hash1;
    int hash2;
    volatile int *p;

    fn_801345D8(frame.buffer, 0x64, lbl_803481D0, arg0);
    frame.objects[0][0] = zero;
    frame.objects[0][1] = 5;
    frame.objects[0][2] = (int)lbl_804B3018;
    index = arg0 - 1;
    frame.objects[0][3] = zero;
    frame.objects[0][4] = zero;

    hash1 = ((int (*)(int, int))fn_80131234)(
        (int)lbl_803481F8, (int)lbl_804B3018);
    frame.objects[1][2] = hash1;
    three = 3;
    frame.objects[1][1] = three;
    frame.objects[1][0] = (int)&lbl_8055C7D0;
    frame.objects[1][3] = zero1;
    frame.objects[1][4] = zero;

    hash2 = fn_80131234((int)frame.buffer);
    p = (volatile int *)lbl_802FA85C;
    frame.prefix[0] = *p++;
    frame.prefix[1] = *p++;
    frame.prefix[2] = *p;
    q1 = lbl_802FA898[1];
    q2 = lbl_802FA898[2];
    q3 = lbl_802FA898[3];
    q4 = lbl_802FA898[4];
    b0 = ((int *)&lbl_804B2FF8)[0];
    b1 = ((int *)&lbl_804B2FF8)[1];
    b2 = ((int *)&lbl_804B2FF8)[2];
    b3 = ((int *)&lbl_804B2FF8)[3];
    b4 = ((int *)&lbl_804B2FF8)[4];

    frame.objects[2][2] = hash2;
    func = (void *)fn_8027EE74;
    six = 6;
    minusTwo = -2;
    frame.objects[2][1] = three;
    thirteen = 13;
    eight = 8;
    frame.objects[2][0] = (int)&lbl_8055C7D8;
    two = 2;
    frame.objects[2][3] = zero2;
    frame.objects[2][4] = zero;
    frame.objects[3][1] = six;
    frame.objects[3][0] = (int)&lbl_8055B860;
    frame.objects[3][2] = zero;
    frame.objects[3][3] = minusTwo;
    frame.objects[3][4] = thirteen;
    frame.objects[4][1] = eight;
    frame.objects[4][0] = (int)&lbl_8055BAB8;
    frame.objects[4][2] = (int)func;
    frame.objects[4][3] = two;
    frame.objects[4][4] = zero;
    frame.objects[5][0] = b0;
    frame.objects[5][1] = b1;
    frame.objects[5][2] = b2;
    frame.objects[5][3] = b3;
    frame.objects[5][4] = b4;

    frame.prefix[4] = q1;
    frame.prefix[5] = q2;
    frame.prefix[6] = q3;
    frame.prefix[7] = q4;
    frame.prefix[3] = frame.prefix[index];
    frame.prefix[4] = (int)frame.objects;
    lbl_8055F684 = 0;
    lbl_8055F685 = 0;
    fn_802146BC(&frame.prefix[3], -0x3E7, -0x3E7, 1,
                q3, q2, b4, b3);
}
#pragma scheduling reset
#pragma pop

extern "C" void fn_8027F09C(int arg0) {
    extern int fn_801345D8(char *, int, const char *, const char *, int);
    extern int fn_80131234(int);
    extern char lbl_802FA8AC[];
    extern char lbl_804B3018[];
    extern int lbl_8055C7D0;
    extern int lbl_8055C7D8;
    struct Local {
        int args[30];
        char buffer[0x64];
        char pad[8];
    } local;
    register int b0, b1, b2, b3, b4;
    register int a0, a2, a3, a4;
    register int c7d8, six, b860, minusTwo, thirteen;
    register const char *base = lbl_80347E50;
    int result1;
    int result2;
    int *atable;

    ((int (*)(char *, int, const char *, ...))fn_801345D8)(
        local.buffer, 0x64, base + 0x3D8, arg0);
    local.args[5] = 0;
    local.args[6] = 5;
    local.args[7] = (int)lbl_804B3018;
    local.args[8] = 0;
    local.args[9] = 0;
    result1 = ((int (*)(int, int))fn_80131234)(
        (int)(base + 0x40C), (int)lbl_804B3018);
    local.args[12] = result1;
    local.args[11] = 3;
    local.args[10] = (int)&lbl_8055C7D0;
    local.args[13] = 0;
    local.args[14] = 0;
    result2 = fn_80131234((int)local.buffer);
    local.args[17] = result2;
    local.args[16] = 3;
    local.args[18] = 0;
    local.args[19] = 0;

    c7d8 = (int)&lbl_8055C7D8;
    six = 6;
    b860 = (int)&lbl_8055B860;
    minusTwo = -2;
    thirteen = 13;
    b0 = ((int *)&lbl_804B2FF8)[0];
    b1 = ((int *)&lbl_804B2FF8)[1];
    b2 = ((int *)&lbl_804B2FF8)[2];
    b3 = ((int *)&lbl_804B2FF8)[3];
    b4 = ((int *)&lbl_804B2FF8)[4];
    atable = (int *)lbl_802FA8AC;
    a0 = *atable++;
    a2 = atable[1];
    a3 = atable[2];
    a4 = atable[3];
    local.args[15] = c7d8;
    local.args[20] = b860;
    local.args[21] = six;
    local.args[22] = 0;
    local.args[23] = minusTwo;
    local.args[24] = thirteen;
    local.args[25] = b0;
    local.args[26] = b1;
    local.args[27] = b2;
    local.args[28] = b3;
    local.args[29] = b4;
    local.args[0] = a0;
    local.args[2] = a2;
    local.args[3] = a3;
    local.args[4] = a4;
    local.args[1] = (int)&local.args[5];
#pragma cplusplus on
    class Draw {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void use(const char *);
    };
    ((Draw *)fn_8027ED70())->use(base + 0x214);
#pragma cplusplus reset
    ((int (*)(int *, int, int, int))fn_802146BC)(
        local.args, -0x3E7, -0x3E7, 1);
}

#pragma cplusplus off
#pragma dont_inline reset
#pragma pop

struct Fn8027F204State {
    char pad[0x40];
    char *buffer;
    volatile int count;
    int max;
};

#pragma cplusplus on
extern "C" void fn_802E30C8(const char *, ...);
extern "C" int lbl_8055F69C;
extern "C" const char lbl_80348270[];
#pragma scheduling invalid_target
extern "C" void fn_8027F204(char *src) {
    char *dst;
    int len;
    int count;
    struct Fn8027F204State *state = (struct Fn8027F204State *)lbl_8055F69C;

    if (state == 0) return;
    count = state->count;
    if (count + 1 <= state->max) {
        len = 0x1e;
        dst = state->buffer + state->count++ * 0x1e;
        goto enter;
        for (;;) {
            if (--len <= 0) {
                dst[-1] = 0;
                return;
            }
        enter:
            if ((*dst++ = *src++) == 0) {
                return;
            }
        }
    }
    fn_802E30C8(lbl_80348270);
}
#pragma scheduling reset
#pragma cplusplus off
void *fn_8027F834(void *arg0, int arg1) {
    int temp_r0, var_r7;
    unsigned char *var_r6;
    int count;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80348798;
        if (lbl_8055F688 == (unsigned int)arg0) lbl_8055F688 = 0;
        var_r6 = (unsigned char *)lbl_804B3048.items;
        count = lbl_804B3048.count;
        var_r7 = 0;
        for (; var_r7 < count; ++var_r7) {
            if (*(unsigned int *)var_r6 == (unsigned int)arg0) goto found_scan;
            var_r6 += 4;
        }
        var_r7 = -1;
found_scan:
        if (var_r7 != -1 && var_r7 >= 0 && var_r7 < *(volatile int *)&lbl_804B3048.count) {
            temp_r0 = *(volatile int *)&lbl_804B3048.count - 1;
            if (var_r7 != temp_r0)
                ((unsigned int *)lbl_804B3048.items)[var_r7] = ((unsigned int *)lbl_804B3048.items)[temp_r0];
            *(volatile int *)&lbl_804B3048.count = *(volatile int *)&lbl_804B3048.count - 1;
        }
        if (arg0 != 0) {
            *((unsigned char *)arg0 + 0x18) = 0;
            *((unsigned char *)arg0 + 0x50) = 0;
            *((unsigned char *)arg0 + 0x5C) = 0;
            *(int *)((char *)arg0 + 0x24) = 1;
            *(int *)((char *)arg0 + 0x20) = 0;
            *((unsigned char *)arg0 + 0x44) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
int fn_8027F958(int *selection, void *collection) {
    extern char lbl_80347E50[];
    extern int lbl_8055BAB8, lbl_8055BAC0, lbl_8055C7EC;
    extern int lbl_8055C7F0, lbl_8055C7F8, lbl_8055C800, lbl_8055C808, lbl_8055C810;
    extern int lbl_8055F68C, lbl_8055F690;
    extern void *lbl_8055F694;
    extern unsigned char lbl_8055F6A0;
    extern float lbl_805641F8, lbl_805641FC, lbl_80564200;
    extern int fn_80131234(int);
    extern int fn_802808D0(void), fn_80280A38(void), fn_80280C00(void), fn_80280F7C(void), fn_80281138(void);
    extern int fn_80280DC8(void), fn_80280898(void);
    typedef void *(*GetItem)(void *, int);
    typedef int (*GetInt)(void *);
    typedef unsigned char (*GetByte)(void *);
    typedef char *(*GetString)(void *);
    Fn8027F958Stack stack;
    struct Fn8027F834List *list;
    void *object, *item;
    Fn8027F958Widget *widget;
    void **items, **storage;
    char *constants = (char *)&lbl_802FA848;
    char *state = (char *)&lbl_804B2FF8;
    char *strings = lbl_80347E50;
    float defaultValue;
    float defaultScale;
    void *widgetVtable;
    char *src, *dst;
    int i, j, index, remaining, result, mode, count, reported;
    float *value;
    list = (struct Fn8027F834List *)(state + 0x50);
    object = ((GetItem)(*(void ***)collection)[4])(collection, 0);
    mode = ((GetInt)(*(void ***)object)[5])(object);
    defaultScale = lbl_805641F8;
    defaultValue = lbl_805641FC;
    widgetVtable = lbl_80348798;
    index = list->count;
    storage = list->items;
    stack.widgets[0].unk14 = 0;
    stack.widgets[0].unk38 = defaultScale;
    stack.widgets[0].unk40 = 2;
    stack.widgets[0].unk3C = defaultValue;
    stack.widgets[0].unk18 = 0;
    stack.widgets[0].unk50 = 0;
    stack.widgets[0].unk5C = 0;
    stack.widgets[0].unk24 = 2;
    stack.widgets[0].unk20 = 0;
    stack.widgets[0].unk44 = 0;
    stack.widgets[0].vtable = widgetVtable;
    stack.widgets[0].object = 0;
    stack.widgets[0].unk64 = 0;
    stack.widgets[0].unk70 = 0;
    stack.widgets[0].unk74 = 0;
    list->count = index + 1;
    storage[index] = &stack.widgets[0];
    stack.widgets[0].unk7E = 0;
    stack.widgets[0].unkB0 = 0;
    index = list->count;
    storage = list->items;
    stack.widgets[1].unk14 = 0;
    stack.widgets[1].unk38 = defaultScale;
    stack.widgets[1].unk40 = 2;
    stack.widgets[1].unk3C = defaultValue;
    stack.widgets[1].unk18 = 0;
    stack.widgets[1].unk50 = 0;
    stack.widgets[1].unk5C = 0;
    stack.widgets[1].unk24 = 2;
    stack.widgets[1].unk20 = 0;
    stack.widgets[1].unk44 = 0;
    stack.widgets[1].vtable = widgetVtable;
    stack.widgets[1].object = 0;
    stack.widgets[1].unk64 = 0;
    stack.widgets[1].unk70 = 0;
    stack.widgets[1].unk74 = 0;
    list->count = index + 1;
    storage[index] = &stack.widgets[1];
    stack.widgets[1].unk7E = 0;
    stack.widgets[1].unkB0 = 0;
    index = list->count;
    storage = list->items;
    stack.widgets[2].unk14 = 0;
    stack.widgets[2].unk38 = defaultScale;
    stack.widgets[2].unk40 = 2;
    stack.widgets[2].unk3C = defaultValue;
    stack.widgets[2].unk18 = 0;
    stack.widgets[2].unk50 = 0;
    stack.widgets[2].unk5C = 0;
    stack.widgets[2].unk24 = 2;
    stack.widgets[2].unk20 = 0;
    stack.widgets[2].unk44 = 0;
    stack.widgets[2].vtable = widgetVtable;
    stack.widgets[2].object = 0;
    stack.widgets[2].unk64 = 0;
    stack.widgets[2].unk70 = 0;
    stack.widgets[2].unk74 = 0;
    list->count = index + 1;
    storage[index] = &stack.widgets[2];
    stack.widgets[2].unk7E = 0;
    stack.widgets[2].unkB0 = 0;
    index = list->count;
    storage = list->items;
    stack.widgets[3].unk14 = 0;
    stack.widgets[3].unk38 = defaultScale;
    stack.widgets[3].unk40 = 2;
    stack.widgets[3].unk3C = defaultValue;
    stack.widgets[3].unk18 = 0;
    stack.widgets[3].unk50 = 0;
    stack.widgets[3].unk5C = 0;
    stack.widgets[3].unk24 = 2;
    stack.widgets[3].unk20 = 0;
    stack.widgets[3].unk44 = 0;
    stack.widgets[3].vtable = widgetVtable;
    stack.widgets[3].object = 0;
    stack.widgets[3].unk64 = 0;
    stack.widgets[3].unk70 = 0;
    stack.widgets[3].unk74 = 0;
    list->count = index + 1;
    storage[index] = &stack.widgets[3];
    stack.widgets[3].unk7E = 0;
    stack.widgets[3].unkB0 = 0;
    index = list->count;
    storage = list->items;
    stack.widgets[4].unk14 = 0;
    stack.widgets[4].unk38 = defaultScale;
    stack.widgets[4].unk40 = 2;
    stack.widgets[4].unk3C = defaultValue;
    stack.widgets[4].unk18 = 0;
    stack.widgets[4].unk50 = 0;
    stack.widgets[4].unk5C = 0;
    stack.widgets[4].unk24 = 2;
    stack.widgets[4].unk20 = 0;
    stack.widgets[4].unk44 = 0;
    stack.widgets[4].vtable = widgetVtable;
    stack.widgets[4].object = 0;
    stack.widgets[4].unk64 = 0;
    stack.widgets[4].unk70 = 0;
    stack.widgets[4].unk74 = 0;
    list->count = index + 1;
    storage[index] = &stack.widgets[4];
    stack.widgets[4].unk7E = 0;
    stack.widgets[4].unkB0 = 0;
    reported = ((GetInt)(*(void ***)collection)[3])(collection);
    count = 5;
    if (reported < 5) count = reported;
    widget = stack.widgets;
    for (i = 0; i < count; ++widget, ++i) {
        widget->object = ((GetItem)(*(void ***)collection)[4])(collection, i);
        widget->unk64 = 0;
        value = widget->values;
        for (j = 0; j < ((GetInt)(*(void ***)widget->object)[6])(widget->object); ++j) {
            item = ((GetItem)(*(void ***)widget->object)[7])(widget->object, j);
            *value++ = ((GetInt)(*(void ***)item)[16])(item) ? lbl_805641FC : lbl_80564200;
        }
        widget->unkCC = ((GetByte)(*(void ***)widget->object)[10])(widget->object);
    }
    stack.menu.entries[0].value = (void *)(&fn_80281138);
    stack.menu.entries[1].label = (void *)(strings + 0x518);
    stack.menu.entries[0].type = (int)(8);
    stack.menu.entries[0].label = (void *)(&lbl_8055BAC0);
    stack.menu.entries[0].flags = (int)(0);
    stack.menu.entries[0].id = (int)(0);
    stack.menu.entries[1].type = (int)(3);
    stack.menu.entries[1].value = (void *)(state + 0x70);
    stack.menu.entries[1].flags = (int)(0);
    stack.menu.entries[1].id = (int)(0);
    stack.menu.entries[2].type = (int)(5);
    stack.menu.entries[2].label = (void *)(&lbl_8055C7F0);
    stack.menu.entries[2].value = (void *)(&stack.widgets[0].vtable);
    stack.menu.entries[2].flags = (int)(0);
    stack.menu.entries[2].id = (int)(0);
    stack.menu.entries[3].type = (int)(2);
    stack.menu.entries[3].label = (void *)(strings + 0x524);
    stack.menu.entries[3].value = (void *)(&stack.widgets[0].unk70);
    stack.menu.entries[3].flags = (int)(0);
    stack.menu.entries[3].id = (int)(0);
    object = stack.widgets[0].object;
    stack.menu.entries[4].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    stack.menu.entries[4].label = (void *)(strings + 0x530);
    stack.menu.entries[4].type = (int)(3);
    stack.menu.entries[4].flags = (int)(0);
    stack.menu.entries[4].id = (int)(0);
    stack.menu.entries[5].type = (int)(3);
    stack.menu.entries[5].label = (void *)(strings + 0x53C);
    stack.menu.entries[5].value = (void *)(&stack.widgets[0].unk74);
    stack.menu.entries[5].flags = (int)(0);
    stack.menu.entries[5].id = (int)(0);
    stack.menu.entries[6].type = (int)(5);
    stack.menu.entries[6].label = (void *)(&lbl_8055C7F8);
    stack.menu.entries[6].value = (void *)(&stack.widgets[1].vtable);
    stack.menu.entries[6].flags = (int)(0);
    stack.menu.entries[6].id = (int)(0);
    stack.menu.entries[7].type = (int)(2);
    stack.menu.entries[7].label = (void *)(strings + 0x550);
    stack.menu.entries[7].value = (void *)(&stack.widgets[1].unk70);
    stack.menu.entries[7].flags = (int)(0);
    stack.menu.entries[7].id = (int)(0);
    object = stack.widgets[1].object;
    stack.menu.entries[8].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    stack.menu.entries[8].label = (void *)(strings + 0x55C);
    stack.menu.entries[8].type = (int)(3);
    stack.menu.entries[8].flags = (int)(0);
    stack.menu.entries[8].id = (int)(0);
    stack.menu.entries[9].type = (int)(3);
    stack.menu.entries[9].label = (void *)(strings + 0x568);
    stack.menu.entries[9].value = (void *)(&stack.widgets[1].unk74);
    stack.menu.entries[9].flags = (int)(0);
    stack.menu.entries[9].id = (int)(0);
    stack.menu.entries[10].type = (int)(5);
    stack.menu.entries[10].label = (void *)(&lbl_8055C800);
    stack.menu.entries[10].value = (void *)(&stack.widgets[2].vtable);
    stack.menu.entries[10].flags = (int)(0);
    stack.menu.entries[10].id = (int)(0);
    stack.menu.entries[11].type = (int)(2);
    stack.menu.entries[11].label = (void *)(strings + 0x57C);
    stack.menu.entries[11].value = (void *)(&stack.widgets[2].unk70);
    stack.menu.entries[11].flags = (int)(0);
    stack.menu.entries[11].id = (int)(0);
    object = stack.widgets[2].object;
    stack.menu.entries[12].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    stack.menu.entries[12].label = (void *)(strings + 0x588);
    stack.menu.entries[12].type = (int)(3);
    stack.menu.entries[12].flags = (int)(0);
    stack.menu.entries[12].id = (int)(0);
    stack.menu.entries[13].type = (int)(3);
    stack.menu.entries[13].label = (void *)(strings + 0x594);
    stack.menu.entries[13].value = (void *)(&stack.widgets[2].unk74);
    stack.menu.entries[13].flags = (int)(0);
    stack.menu.entries[13].id = (int)(0);
    stack.menu.entries[14].type = (int)(5);
    stack.menu.entries[14].label = (void *)(&lbl_8055C808);
    stack.menu.entries[14].value = (void *)(&stack.widgets[3].vtable);
    stack.menu.entries[14].flags = (int)(0);
    stack.menu.entries[14].id = (int)(0);
    stack.menu.entries[15].type = (int)(2);
    stack.menu.entries[15].label = (void *)(strings + 0x5A8);
    stack.menu.entries[15].value = (void *)(&stack.widgets[3].unk70);
    stack.menu.entries[15].flags = (int)(0);
    stack.menu.entries[15].id = (int)(0);
    object = stack.widgets[3].object;
    stack.menu.entries[16].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    stack.menu.entries[16].label = (void *)(strings + 0x5B4);
    stack.menu.entries[16].type = (int)(3);
    stack.menu.entries[16].flags = (int)(0);
    stack.menu.entries[16].id = (int)(0);
    stack.menu.entries[17].type = (int)(3);
    stack.menu.entries[17].label = (void *)(strings + 0x5C0);
    stack.menu.entries[17].value = (void *)(&stack.widgets[3].unk74);
    stack.menu.entries[17].flags = (int)(0);
    stack.menu.entries[17].id = (int)(0);
    stack.menu.entries[18].type = (int)(5);
    stack.menu.entries[18].label = (void *)(&lbl_8055C810);
    stack.menu.entries[18].value = (void *)(&stack.widgets[4].vtable);
    stack.menu.entries[18].flags = (int)(0);
    stack.menu.entries[18].id = (int)(0);
    stack.menu.entries[19].type = (int)(2);
    stack.menu.entries[19].label = (void *)(strings + 0x5D4);
    stack.menu.entries[19].value = (void *)(&stack.widgets[4].unk70);
    stack.menu.entries[19].flags = (int)(0);
    stack.menu.entries[19].id = (int)(0);
    stack.textIds[0][0] = *(int *)(constants + 0x2c);
    stack.textIds[0][1] = *(int *)(constants + 0x30);
    stack.textIds[0][2] = *(int *)(constants + 0x34);
    stack.textIds[1][0] = *(int *)(constants + 0x38);
    stack.textIds[1][1] = *(int *)(constants + 0x3c);
    stack.textIds[1][2] = *(int *)(constants + 0x40);
    stack.textIds[2][0] = *(int *)(constants + 0x44);
    stack.textIds[2][1] = *(int *)(constants + 0x48);
    stack.textIds[2][2] = *(int *)(constants + 0x4c);
    stack.menu.entries[20].type = (int)(3);
    stack.menu.entries[20].label = (void *)(strings + 0x5E0);
    object = stack.widgets[4].object;
    stack.menu.entries[20].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    stack.menu.entries[20].flags = (int)(0);
    stack.menu.entries[20].id = (int)(0);
    stack.menu.entries[21].type = (int)(3);
    stack.menu.entries[21].label = (void *)(strings + 0x5EC);
    stack.menu.entries[21].value = (void *)(&stack.widgets[4].unk74);
    stack.menu.entries[21].flags = (int)(0);
    stack.menu.entries[21].id = (int)(0);
    stack.menu.entries[22].type = (int)(3);
    stack.menu.entries[22].label = (void *)(strings + 0x600);
    stack.menu.entries[22].value = (void *)(stack.textIds[2][mode]);
    stack.menu.entries[22].flags = (int)(0);
    stack.menu.entries[22].id = (int)(0);
    stack.menu.entries[23].type = (int)(3);
    stack.menu.entries[23].label = (void *)(strings + 0x610);
    stack.menu.entries[23].value = (void *)(stack.textIds[1][mode]);
    stack.menu.entries[23].flags = (int)(0);
    stack.menu.entries[23].id = (int)(0);
    stack.menu.entries[24].value = (void *)(fn_80131234(stack.textIds[0][mode]));
    stack.menu.entries[24].label = (void *)(strings + 0x620);
    stack.menu.entries[24].type = (int)(3);
    stack.menu.entries[24].flags = (int)(0);
    stack.menu.entries[24].id = (int)(0);
    stack.menu.entries[25].label = (void *)(&lbl_8055B860);
    stack.menu.entries[25].type = (int)(6);
    stack.menu.entries[25].value = (void *)(&fn_80280F7C);
    stack.menu.entries[25].flags = (int)(0);
    stack.menu.entries[25].id = (int)(0x125);
    stack.menu.entries[26].label = (void *)(&lbl_8055B860);
    stack.menu.entries[26].type = (int)(6);
    stack.menu.entries[26].value = (void *)(&fn_80280DC8);
    stack.menu.entries[26].flags = (int)(0);
    stack.menu.entries[26].id = (int)(0x127);
    stack.menu.entries[27].label = (void *)(&lbl_8055B860);
    stack.menu.entries[27].type = (int)(6);
    stack.menu.entries[27].value = (void *)(&fn_80280C00);
    stack.menu.entries[27].flags = (int)(0);
    stack.menu.entries[27].id = (int)(0x128);
    stack.menu.entries[28].label = (void *)(&lbl_8055B860);
    stack.menu.entries[28].type = (int)(6);
    stack.menu.entries[28].value = (void *)(&fn_80280A38);
    stack.menu.entries[28].flags = (int)(0);
    stack.menu.entries[28].id = (int)(0x126);
    stack.menu.entries[29].label = (void *)(&lbl_8055B860);
    stack.menu.entries[29].type = (int)(6);
    stack.menu.entries[29].value = (void *)(&fn_802808D0);
    stack.menu.entries[29].flags = (int)(-2);
    stack.menu.entries[29].id = (int)(0xD);
    stack.menu.entries[30].label = (void *)(&lbl_8055B860);
    stack.menu.entries[30].type = (int)(6);
    stack.menu.entries[30].value = (void *)(&fn_80280898);
    stack.menu.entries[30].flags = (int)(-1);
    stack.menu.entries[30].id = (int)(0x1B);
    stack.menu.entries[31].label = (void *)(&lbl_8055BAB8);
    stack.menu.entries[31].type = (int)(8);
    stack.menu.entries[31].value = (void *)(&fn_8027EE74);
    stack.menu.entries[31].flags = (int)(2);
    stack.menu.entries[31].id = (int)(0);
    stack.menu.header[0] = *(int *)(constants + 0x108);
    stack.menu.footer[0] = ((int *)&lbl_804B2FF8)[0];
    stack.menu.header[1] = *(int *)(constants + 0x10c);
    stack.menu.footer[1] = ((int *)&lbl_804B2FF8)[1];
    stack.menu.header[2] = *(int *)(constants + 0x110);
    stack.menu.footer[2] = ((int *)&lbl_804B2FF8)[2];
    stack.menu.header[3] = *(int *)(constants + 0x114);
    stack.menu.footer[3] = ((int *)&lbl_804B2FF8)[3];
    stack.menu.header[4] = *(int *)(constants + 0x118);
    stack.menu.footer[4] = ((int *)&lbl_804B2FF8)[4];
    stack.menu.header[1] = (int)stack.menu.entries;
    if (lbl_8055F6A0 != 0) {
        lbl_8055F6A0 = 0;
    *(char *)(state + 0x70) = 0;
    index = *selection;
    if (index >= 0 && index < list->count) {
        object = list->items[index];
        lbl_8055F688 = (unsigned int)object;
        if (object != 0 && ((Fn8027F958Widget *)object)->object != 0) {
            item = ((Fn8027F958Widget *)object)->object;
            src = ((GetString)(*(void ***)item)[12])(item);
            dst = state + 0x70;
            remaining = 100;
            do {
                char c = *src++;
                *dst++ = c;
                if (c == 0) break;
                if (--remaining <= 0) { dst[-1] = 0; break; }
            } while (1);
        }
    } else lbl_8055F688 = 0;

        if (*selection < ((GetInt)(*(void ***)collection)[3])(collection) - 1) {
            ++*selection;
            lbl_8055F694 = &stack.widgets[*selection];
        }
    }
 else {
    *(char *)(state + 0x70) = 0;
    index = *selection;
    if (index >= 0 && index < list->count) {
        object = list->items[index];
        lbl_8055F688 = (unsigned int)object;
        if (object != 0 && ((Fn8027F958Widget *)object)->object != 0) {
            item = ((Fn8027F958Widget *)object)->object;
            src = ((GetString)(*(void ***)item)[12])(item);
            dst = state + 0x70;
            remaining = 100;
            do {
                char c = *src++;
                *dst++ = c;
                if (c == 0) break;
                if (--remaining <= 0) { dst[-1] = 0; break; }
            } while (1);
        }
    } else lbl_8055F688 = 0;
    }
    result = (((int (*)(int *, int, int, int))fn_802146BC)(stack.menu.header, -999, -999, 1) + 2) == 0;
    if (result) {
        for (i = 0; i < list->count; ++i)
            if ((unsigned int)list->items[i] == lbl_8055F688) break;
        *selection = i < list->count ? i : -1;
    }
    lbl_8055F688 = 0;
    list->count = 0;
    lbl_8055F68C = 0;
    lbl_8055F690 = 0;
    *(char *)(state + 0x70) = 0;
    lbl_8055F694 = 0;
    widget = &stack.widgets[4];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    count = list->count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < list->count) {
        count = list->count - 1;
        if (index != count) list->items[index] = list->items[count];
        list->count = list->count - 1;
    }
    widget->unk18 = 0;
    widget->unk50 = 0;
    widget->unk5C = 0;
    widget->unk24 = 1;
    widget->unk20 = 0;
    widget->unk44 = 0;
    widget = &stack.widgets[3];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    count = list->count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < list->count) {
        count = list->count - 1;
        if (index != count) list->items[index] = list->items[count];
        list->count = list->count - 1;
    }
    widget->unk18 = 0;
    widget->unk50 = 0;
    widget->unk5C = 0;
    widget->unk24 = 1;
    widget->unk20 = 0;
    widget->unk44 = 0;
    widget = &stack.widgets[2];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    count = list->count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < list->count) {
        count = list->count - 1;
        if (index != count) list->items[index] = list->items[count];
        list->count = list->count - 1;
    }
    widget->unk18 = 0;
    widget->unk50 = 0;
    widget->unk5C = 0;
    widget->unk24 = 1;
    widget->unk20 = 0;
    widget->unk44 = 0;
    widget = &stack.widgets[1];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    count = list->count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < list->count) {
        count = list->count - 1;
        if (index != count) list->items[index] = list->items[count];
        list->count = list->count - 1;
    }
    widget->unk18 = 0;
    widget->unk50 = 0;
    widget->unk5C = 0;
    widget->unk24 = 1;
    widget->unk20 = 0;
    widget->unk44 = 0;
    widget = &stack.widgets[0];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    count = list->count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < list->count) {
        count = list->count - 1;
        if (index != count) list->items[index] = list->items[count];
        list->count = list->count - 1;
    }
    widget->unk18 = 0;
    widget->unk50 = 0;
    widget->unk5C = 0;
    widget->unk24 = 1;
    widget->unk20 = 0;
    widget->unk44 = 0;
    return result;
}
#pragma scheduling on
#pragma pop

extern int fn_80216D28(void);
int fn_80280898(void) { extern unsigned int lbl_8055F688; if (lbl_8055F688 == 0) { fn_80216D28(); return 0; } return 1; }

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_802808D0(void) {
    class CheckObj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual int f7();
    };
    extern int fn_80019714(void);
    extern int fn_80214D50(int);
    extern void fn_801345D8();
    extern void fn_80236954(char *);
    extern char lbl_80348480[];
    char buffer[0x1E];
    void **base;
    void **p;
    void *entry;
    int count;
    int index;
    int active;

    count = lbl_804B3048.count;
    index = 0;
    base = lbl_804B3048.items;
    p = base;
    for (; index < count; index++, p++) {
        if (*p == (void *)lbl_8055F688)
            goto found_item;
    }
    index = -1;
found_item:
    if (index >= 0) {
        entry = base[index];
        active = 0;
        if (*(void **)((char *)entry + 0x60) != 0) {
            if (fn_80019714() == 0 &&
                ((CheckObj *)*(void **)((char *)entry + 0x60))->f7()) {
                active = 1;
            }
        }
        if (active != 0) {
            if (*(unsigned char *)((char *)lbl_8055F688 + 0x64) != 0) {
                index = 5;
            } else {
                count = lbl_804B3048.count;
                index = 0;
                p = lbl_804B3048.items;
                for (; index < count; index++, p++) {
                    if (*p == (void *)lbl_8055F688)
                        goto found_item_2;
                }
                index = -1;
found_item_2:
                ;
            }
            ((void (*)(char *, int, const char *, ...))fn_801345D8)(
                buffer, 0x1E, lbl_80348480, index + 1);
            fn_80236954(buffer);
            return 1;
        }
        fn_80216D28();
        fn_80214D50(1);
        return 0;
    }
    fn_80216D28();
    return 0;
}
#pragma cplusplus reset
#pragma scheduling on

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_80280A38(void) {
    class Object {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual int getKey(); virtual char *getText();
    };
    extern int lbl_8055F68C;
    extern int lbl_8055F690;
    extern unsigned char lbl_804B3068[];
    register Object *object;
    register void *candidate;
    register int offset;
    register int i;
    register int count;
    register void **p;
    register void **items;
    void *selected;
    char *src;
    char *dst;
    int n;

    if (lbl_8055F688 == 0)
        goto done;
    if (*(Object * volatile *)((char *)lbl_8055F688 + 0x60) == 0)
        goto done;
    object = *(Object **)((char *)lbl_8055F688 + 0x60);
    if (object->getKey() == 0)
        goto done;

    lbl_8055F690 = lbl_8055F688;
    if (lbl_8055F68C == 0) {
        offset = 0;
        i = 0;
        goto first_scan;
first_scan:
        candidate = *(void **)((char *)lbl_804B3048.items + offset);
        object = *(Object **)((char *)candidate + 0x60);
        if (object != 0 && object->getKey() == 0) {
            lbl_8055F68C = (int)candidate;
        } else {
            offset += 4;
            i++;
            count = *(volatile int *)((char *)&lbl_804B3048 + 4);
            if (i < count)
                goto first_scan;
        }
    }
    if (lbl_8055F68C == 0)
        goto done;

    selected = (void *)*(volatile int *)&lbl_8055F68C;
    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    i = 0;
    p = items;
    while (i < count) {
        if (*p != selected)
            goto search_next;
        goto found;
search_next:
        p++;
        i++;
    }
    i = -1;
found:
    lbl_804B3068[0] = 0;
    if (i < 0)
        goto clear;
    if (i >= lbl_804B3048.count)
        goto clear;
    selected = items[i];
    lbl_8055F688 = (unsigned int)selected;
    if (selected != 0) {
        object = *(Object **)((char *)selected + 0x60);
        if (object != 0) {
            src = object->getText();
            dst = (char *)lbl_804B3068;
            n = 100;
            do {
                char c = *src++;
                *dst++ = c;
                if ((signed char)c == 0)
                    break;
                n--;
            } while (n > 0);
            if (n == 0)
                dst[-1] = 0;
        }
    }
    goto done;
clear:
    lbl_8055F688 = 0;
done:
    return 0;
}
#pragma scheduling on
extern "C" int fn_80280C00(void) {
    class Object {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual int getKey(); virtual const char *getText();
    };
    extern int lbl_8055F68C;
    extern int lbl_8055F690;
    extern unsigned char lbl_804B3068[];
    register Object *object;
    register void *selected;
    register void *candidate;
    register int offset;
    register int i;
    register int count;
    register void **p;
    register void **items;
    const char *src;
    char *dst;
    int n;

    if (lbl_8055F688 == 0)
        goto done;
    if (*(Object * volatile *)((char *)lbl_8055F688 + 0x60) == 0)
        goto done;
    object = *(Object **)((char *)lbl_8055F688 + 0x60);
    if (object->getKey() != 0)
        goto done;

    lbl_8055F68C = lbl_8055F688;
    if (lbl_8055F690 == 0) {
        offset = 0;
        i = 0;
        goto first_scan;
first_scan:
        candidate = *(void **)((char *)lbl_804B3048.items + offset);
        object = *(Object **)((char *)candidate + 0x60);
        if (object != 0 && object->getKey() != 0) {
            lbl_8055F690 = (int)candidate;
        } else {
            offset += 4;
            i++;
            count = *(volatile int *)((char *)&lbl_804B3048 + 4);
            if (i < count)
                goto first_scan;
        }
    }
    if (lbl_8055F690 == 0)
        goto done;

    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    selected = (void *)*(volatile int *)&lbl_8055F690;
    i = 0;
    p = items;
    while (i < count) {
        if (*p != selected)
            goto search_next;
        goto found;
search_next:
        p++;
        i++;
    }
    i = -1;
found:
    lbl_804B3068[0] = 0;
    if (i < 0)
        goto clear;
    if (i >= lbl_804B3048.count)
        goto clear;
    selected = items[i];
    lbl_8055F688 = (unsigned int)selected;
    if (selected != 0) {
        object = *(Object **)((char *)selected + 0x60);
        if (object != 0) {
            src = object->getText();
            dst = (char *)lbl_804B3068;
            n = 100;
            do {
                char c = *src++;
                *dst++ = c;
                if ((signed char)c == 0)
                    break;
                n--;
            } while (n > 0);
            if (n == 0)
                dst[-1] = 0;
        }
    }
    goto done;
clear:
    lbl_8055F688 = 0;
done:
    return 0;
}
#pragma cplusplus reset
extern unsigned char lbl_804B3068[];
typedef unsigned int (*GetKeyFn)(void *);
typedef char *(*GetTextFn)(void *);
int fn_80280DC8(void) {
    register int index;
    register int count;
    register unsigned int key;
    register void *obj;
    register void *item;
    register void **p;
    register void **items;
    char *src;
    char *dst;
    int n;

    if (*(volatile unsigned int *)&lbl_8055F688 == 0)
        goto reset;
    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    key = *(volatile unsigned int *)&lbl_8055F688;
    index = 0;
    p = items;
    while (index < count) {
        if (*p != (void *)key)
            goto search_next;
        goto first_found;
search_next:
        p++;
        index++;
    }
    index = -1;
first_found:
    item = items[index];
    if (*(void * volatile *)((char *)item + 0x60) == 0)
        goto finish;
    obj = *(void **)((char *)item + 0x60);
    key = ((GetKeyFn)(*(void ***)obj)[11])(obj);
    index++;
    while (index < lbl_804B3048.count) {
        item = lbl_804B3048.items[index];
        obj = *(void **)((char *)item + 0x60);
        if (obj != 0 && ((GetKeyFn)(*(void ***)obj)[11])(obj) == key)
            break;
        index++;
    }
    count = lbl_804B3048.count;
    if (index >= count)
        goto finish;
    lbl_804B3068[0] = 0;
    if (index < 0) {
        *(volatile unsigned int *)&lbl_8055F688 = 0;
        goto finish;
    }
    item = items[index];
    lbl_8055F688 = (unsigned int)item;
    if (item == 0)
        goto finish;
    obj = *(void **)((char *)item + 0x60);
    if (obj == 0)
        goto finish;
    src = ((GetTextFn)(*(void ***)obj)[12])(obj);
    dst = (char *)lbl_804B3068;
    n = 100;
    do {
        char c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            break;
        n--;
    } while (n > 0);
    if (n == 0)
        dst[-1] = 0;
    goto finish;

reset:
    *(volatile unsigned int *)&lbl_8055F688 = 0;
finish:
    fn_80216D28();
    return 0;
}

#pragma push
#pragma cplusplus on
extern "C" int fn_80216D28(void);
#pragma push
#pragma scheduling invalid_target
extern "C" int fn_80280F7C(void) {
    class Obj { public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void *f11(); virtual const char *f12();
    };
    if (*(volatile unsigned int *)&lbl_8055F688 == 0)
        goto reset;
    void *key = (void *)*(volatile unsigned int *)&lbl_8055F688;
    int count = lbl_804B3048.count;
    long i;
    for (i = 0; i < count; ++i) {
        if (lbl_804B3048.items[i] != key)
            continue;
        goto found;
    }
    i = -1;
found:
    void *firstItem = lbl_804B3048.items[i];
    if (*(Obj * volatile *)((char *)firstItem + 0x60) != 0) {
        Obj *obj = *(Obj **)((char *)firstItem + 0x60);
        void *identity = obj->f11();
        long j = i - 1;
        while (j >= 0) {
            Obj *prev = *(Obj **)((char *)lbl_804B3048.items[j] + 0x60);
            if (prev != 0 && identity == prev->f11())
                break;
            j--;
        }
        if (j < 0)
            goto finish;
        *(volatile unsigned char *)lbl_804B3068 = 0;
        if (j >= 0) {
            int selectedCount = *(volatile int *)((char *)&lbl_804B3048 + 4);
            if (j >= selectedCount)
                goto reset;
            void *item = lbl_804B3048.items[j];
            lbl_8055F688 = (unsigned int)item;
            if (item != 0 && *(Obj * volatile *)((char *)item + 0x60) != 0) {
                Obj *selected = *(Obj **)((char *)item + 0x60);
                const char *src = selected->f12();
                int n = 100;
                char *dst = (char *)lbl_804B3068;
                goto copy_test;
                for (;;) {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
copy_test:
                    if ((*dst++ = *src++) == 0)
                        break;
                }
            }
        }
    }
    goto finish;
reset:
    *(volatile unsigned int *)&lbl_8055F688 = 0;
finish:
    fn_80216D28();
    return 0;
}
#pragma scheduling reset
#pragma pop
extern "C" int fn_80281138(void) {
    extern int fn_801345D8(char *, int, const char *, const char *, int);
    extern int fn_802368EC(void);
    extern void fn_80236954(char *);
    extern void *lbl_8055F694;
    extern char lbl_8034848C[];
    extern char lbl_8034849C[];
    unsigned int *items;
    unsigned int key;
    void *selected;
    int count;
    int index;
    char buffer1[0x1E];
    char buffer2[0x1E];

    count = lbl_804B3048.count;
    index = 0;
    key = lbl_8055F688;
    items = (unsigned int *)lbl_804B3048.items;
    for (; count > 0; --count, ++items, ++index) {
        if (*items != key)
            goto update_first;
        goto found_first;
update_first:
        ;
    }
    index = -1;
found_first:
    if (index >= 0 && fn_802368EC() != 0) {
        if (*(unsigned char *)((char *)lbl_8055F688 + 0x64) != 0) {
            index = 5;
        } else {
            count = lbl_804B3048.count;
            index = 0;
            key = lbl_8055F688;
            items = (unsigned int *)lbl_804B3048.items;
            for (; count > 0; --count, ++items, ++index) {
                if (*items != key)
                    goto update_second;
                goto found_second;
update_second:
                ;
            }
            index = -1;
found_second:
            ;
        }
        ((void (*)(char *, int, const char *, ...))fn_801345D8)(
            buffer1, 0x1E, lbl_8034848C, index + 1);
        fn_80236954(buffer1);
    }
    selected = lbl_8055F694;
    if (selected != 0) {
        lbl_8055F688 = 0;
        if (*(unsigned char *)((char *)selected + 0x64) != 0) {
            index = 5;
        } else {
            count = lbl_804B3048.count;
            index = 0;
            items = (unsigned int *)lbl_804B3048.items;
            for (; count > 0; --count, ++items, ++index) {
                if (*items != (unsigned int)selected)
                    goto update_third;
                goto found_third;
update_third:
                ;
            }
            index = -1;
found_third:
            ;
        }
        ((void (*)(char *, int, const char *, ...))fn_801345D8)(
            buffer2, 0x1E, lbl_8034849C, index + 1);
        fn_80236954(buffer2);
    }
}
#pragma scheduling on

#pragma cplusplus on
extern "C" unsigned char lbl_80348678[];
extern "C" unsigned char lbl_8055F6A0;
extern "C" int lbl_802FA848;
extern "C" int lbl_804B2FF8;
extern "C" float lbl_80564204, lbl_805641FC, lbl_80564200, lbl_80564208;
extern "C" unsigned char lbl_80348738[];
extern "C" char lbl_8055C818[];
extern "C" void *lbl_8055F698;
extern "C" void fn_801308F4(char *, int, const char *);
extern "C" void *__AXGetStackHead(void);
extern "C" void *fn_801284F8(int, const char *);
extern "C" char lbl_8055C818[], lbl_8055C820[];
extern "C" void fn_80236008(void *, int, int);
extern "C" int fn_802054EC(void *, int, int);
extern "C" int fn_802812B4(int *arg0, void *arg1, int *arg2, void *arg3) {
    struct Item { void **vtable; };
    struct List { void **vtable; };
    class Child {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual int value();
        virtual void f7(); virtual void f8(); virtual void f9(); virtual const char *text();
        virtual void f11(); virtual void f12(); virtual void f13();
        virtual int isZero();
    };
    struct Record {
        void *vtable;
        unsigned char pad04[0x10];
        int unk14;
        unsigned char unk18;
        unsigned char pad19[7];
        int unk20;
        int unk24;
        unsigned char pad28[0x10];
        float unk38;
        float unk3C;
        int unk40;
        unsigned char unk44;
        unsigned char pad45[0x1B];
        void *child;
        unsigned char pad64[8];
        char name[0x1E];
        char text[10];
        int selected;
        unsigned char flag98, flag99;
        unsigned char pad9A[2];
        int mode;
    };
    volatile unsigned char frame[0xAB0];
    volatile unsigned char *sp = frame;
    Item *item = (Item *)arg1; List *list = (List *)arg3;
    char *p24 = (char *)&lbl_802FA848, *p25 = (char *)&lbl_804B2FF8, *p26 = lbl_80347E50;
    float f30, f31;
    int selectedIndex;
    void *ret = ((void *(*)(void *))item->vtable[5])(item);
    int flag = ((volatile unsigned char *)arg2)[0xE];
    *(volatile void **)(sp + 0xAB8) = ret;
    *(volatile void **)(sp + 0x230) = lbl_80348678;
    *(volatile void **)(sp + 0x234) = lbl_80348678 + 0x50;
    *(volatile int *)(sp + 0x248) = 0;
    *(volatile void **)(sp + 0x270) = (void *)(sp + 0x27C);
    *(volatile int *)(sp + 0x278) = 10;
    *(volatile int *)(sp + 0x274) = 0;
    lbl_8055F69C = (int)(sp + 0x230);
    *(volatile int *)(sp + 0x24C) = 0;
    *(volatile int *)(sp + 0x250) = 0;
    *(volatile int *)(sp + 0x254) = -1;
    *(volatile int *)(sp + 0x3AC) = -1;
    *(volatile unsigned char *)(sp + 0x25B) = 0;
    *(volatile int *)(sp + 0x260) = 0;
    *(volatile int *)(sp + 0x25C) = 0;
    *(volatile unsigned char *)(sp + 0x264) = 0;
    *(volatile int *)(sp + 0x268) = 0;
    *(volatile unsigned char *)(sp + 0x26C) = 0;
    if (flag != 0) {
        int i = 0;
        while (i < ((int (*)(void *))list->vtable[3])(list)) {
            if (((Item *(*)(void *, int))list->vtable[4])(list, i) == item) break;
            ++i;
        }
        int n = ((int (*)(void *))list->vtable[3])(list);
        if (i < n - 1) ((Item *(*)(void *, int))list->vtable[4])(list, i + 1);
        if (i < n) {
            *(volatile void **)(sp + 0x25C) = item;
            *(volatile int *)(sp + 0x260) = 0;
            *(volatile unsigned char *)(sp + 0x25B) = 1;
            *(volatile unsigned char *)(sp + 0x26C) = 1;
            lbl_8055F6A0 = 0;
        }
    }
    if (((unsigned char *)arg2)[0x10] != 0) *(volatile unsigned char *)(sp + 0x26C) = 1;
    if (((unsigned char *)arg2)[0x11] != 0) *(volatile unsigned char *)(sp + 0x26C) = 1;
    *(volatile unsigned char *)(sp + 0x271) = (unsigned char)(p24 != p25);
    *(volatile unsigned char *)(sp + 0x272) = (unsigned char)(p26 != 0);

    {
        volatile unsigned char *o = sp + 0x798;
        volatile Record *rec = (volatile Record *)o;
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        rec->unk14 = 0;
        rec->unk40 = 1;
        rec->unk38 = lbl_80564204;
        rec->unk3C = lbl_805641FC;
        rec->unk18 = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x50) = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x5C) = 0;
        rec->unk24 = 2;
        rec->unk20 = 0;
        rec->unk44 = 0;
        rec->vtable = lbl_80348738;
        rec->child = 0;
        pool[count] = (void *)o;
        *(int *)(base + 0xE4) = count + 1;
    }

    {
        volatile unsigned char *o = sp + 0x798;
        volatile Record *rec = (volatile Record *)o;
        void *child = (void *)rec->child;
        if (child != 0) {
            void **vt = *(void ***)child;
            const char *src = ((const char *(*)(void *))vt[10])(child);
            fn_801308F4((char *)o + 0x6C, 0x1E, src);
            {
                char *d = (char *)o + 0x6C; const char *s = lbl_8055C818; int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            src = ((const char *(*)(void *))vt[15])(child);
            fn_801308F4((char *)(sp + 0xB0), 0x14, src);
            {
                char *d = (char *)o + 0x6C; const char *s = (const char *)(sp + 0xB0); int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            rec->mode = ((int (*)(void *))vt[16])(child) != 0;
            child = (void *)rec->child;
            vt = *(void ***)child;
            int mode = ((int (*)(void *))vt[11])(child);
            if (mode >= 0 && mode < 5) {
                char *s = (char *)__AXGetStackHead();
                char *d = (char *)o + 0x8A; int n = 10;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
        }
        rec->selected = (lbl_8055F698 == (void *)o);
    }


    {
        volatile unsigned char *o = sp + 0x838;
        volatile Record *rec = (volatile Record *)o;
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        rec->unk14 = 0;
        rec->unk40 = 1;
        rec->unk38 = lbl_80564204;
        rec->unk3C = lbl_805641FC;
        rec->unk18 = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x50) = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x5C) = 0;
        rec->unk24 = 2;
        rec->unk20 = 0;
        rec->unk44 = 0;
        rec->vtable = lbl_80348738;
        rec->child = 0;
        pool[count] = (void *)o;
        *(int *)(base + 0xE4) = count + 1;
    }

    {
        volatile unsigned char *o = sp + 0x838;
        volatile Record *rec = (volatile Record *)o;
        void *child = (void *)rec->child;
        if (child != 0) {
            void **vt = *(void ***)child;
            const char *src = ((const char *(*)(void *))vt[10])(child);
            fn_801308F4((char *)o + 0x6C, 0x1E, src);
            {
                char *d = (char *)o + 0x6C; const char *s = lbl_8055C818; int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            src = ((const char *(*)(void *))vt[15])(child);
            fn_801308F4((char *)(sp + 0x9C), 0x14, src);
            {
                char *d = (char *)o + 0x6C; const char *s = (const char *)(sp + 0x9C); int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            rec->mode = ((int (*)(void *))vt[16])(child) != 0;
            child = (void *)rec->child;
            vt = *(void ***)child;
            int mode = ((int (*)(void *))vt[11])(child);
            if (mode >= 0 && mode < 5) {
                char *s = (char *)__AXGetStackHead();
                char *d = (char *)o + 0x8A; int n = 10;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
        }
        rec->selected = (lbl_8055F698 == (void *)o);
    }


    {
        volatile unsigned char *o = sp + 0x8D8;
        volatile Record *rec = (volatile Record *)o;
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        rec->unk14 = 0;
        rec->unk40 = 1;
        rec->unk38 = lbl_80564204;
        rec->unk3C = lbl_805641FC;
        rec->unk18 = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x50) = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x5C) = 0;
        rec->unk24 = 2;
        rec->unk20 = 0;
        rec->unk44 = 0;
        rec->vtable = lbl_80348738;
        rec->child = 0;
        pool[count] = (void *)o;
        *(int *)(base + 0xE4) = count + 1;
    }

    {
        volatile unsigned char *o = sp + 0x8D8;
        volatile Record *rec = (volatile Record *)o;
        void *child = (void *)rec->child;
        if (child != 0) {
            void **vt = *(void ***)child;
            const char *src = ((const char *(*)(void *))vt[10])(child);
            fn_801308F4((char *)o + 0x6C, 0x1E, src);
            {
                char *d = (char *)o + 0x6C; const char *s = lbl_8055C818; int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            src = ((const char *(*)(void *))vt[15])(child);
            fn_801308F4((char *)(sp + 0x88), 0x14, src);
            {
                char *d = (char *)o + 0x6C; const char *s = (const char *)(sp + 0x88); int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            rec->mode = ((int (*)(void *))vt[16])(child) != 0;
            child = (void *)rec->child;
            vt = *(void ***)child;
            int mode = ((int (*)(void *))vt[11])(child);
            if (mode >= 0 && mode < 5) {
                char *s = (char *)__AXGetStackHead();
                char *d = (char *)o + 0x8A; int n = 10;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
        }
        rec->selected = (lbl_8055F698 == (void *)o);
    }

    {
        volatile unsigned char *o = sp + 0x978;
        volatile Record *rec = (volatile Record *)o;
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        rec->unk14 = 0;
        rec->unk40 = 1;
        rec->unk38 = lbl_80564204;
        rec->unk3C = lbl_805641FC;
        rec->unk18 = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x50) = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x5C) = 0;
        rec->unk24 = 2;
        rec->unk20 = 0;
        rec->unk44 = 0;
        rec->vtable = lbl_80348738;
        rec->child = 0;
        pool[count] = (void *)o;
        *(int *)(base + 0xE4) = count + 1;
    }

    {
        volatile unsigned char *o = sp + 0x978;
        volatile Record *rec = (volatile Record *)o;
        void *child = (void *)rec->child;
        if (child != 0) {
            void **vt = *(void ***)child;
            const char *src = ((const char *(*)(void *))vt[10])(child);
            fn_801308F4((char *)o + 0x6C, 0x1E, src);
            {
                char *d = (char *)o + 0x6C; const char *s = lbl_8055C818; int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            src = ((const char *(*)(void *))vt[15])(child);
            fn_801308F4((char *)(sp + 0x88), 0x14, src);
            {
                char *d = (char *)o + 0x6C; const char *s = (const char *)(sp + 0x88); int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            rec->mode = ((int (*)(void *))vt[16])(child) != 0;
            child = (void *)rec->child;
            vt = *(void ***)child;
            int mode = ((int (*)(void *))vt[11])(child);
            if (mode >= 0 && mode < 5) {
                char *s = (char *)__AXGetStackHead();
                char *d = (char *)o + 0x8A; int n = 10;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
        }
        rec->selected = (lbl_8055F698 == (void *)o);
    }

    {
        volatile unsigned char *o = sp + 0xA18;
        volatile Record *rec = (volatile Record *)o;
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        rec->unk14 = 0;
        rec->unk40 = 1;
        rec->unk38 = lbl_80564204;
        rec->unk3C = lbl_805641FC;
        rec->unk18 = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x50) = 0;
        *(volatile unsigned char *)((unsigned char *)o + 0x5C) = 0;
        rec->unk24 = 2;
        rec->unk20 = 0;
        rec->unk44 = 0;
        rec->vtable = lbl_80348738;
        rec->child = 0;
        pool[count] = (void *)o;
        *(int *)(base + 0xE4) = count + 1;
    }

    {
        volatile unsigned char *o = sp + 0xA18;
        volatile Record *rec = (volatile Record *)o;
        void *child = (void *)rec->child;
        if (child != 0) {
            void **vt = *(void ***)child;
            const char *src = ((const char *(*)(void *))vt[10])(child);
            fn_801308F4((char *)o + 0x6C, 0x1E, src);
            {
                char *d = (char *)o + 0x6C; const char *s = lbl_8055C818; int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            src = ((const char *(*)(void *))vt[15])(child);
            fn_801308F4((char *)(sp + 0x88), 0x14, src);
            {
                char *d = (char *)o + 0x6C; const char *s = (const char *)(sp + 0x88); int n = 0x1E;
                while (*d && --n) ++d;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
            child = (void *)rec->child;
            vt = *(void ***)child;
            rec->mode = ((int (*)(void *))vt[16])(child) != 0;
            child = (void *)rec->child;
            vt = *(void ***)child;
            int mode = ((int (*)(void *))vt[11])(child);
            if (mode >= 0 && mode < 5) {
                char *s = (char *)__AXGetStackHead();
                char *d = (char *)o + 0x8A; int n = 10;
                while (n-- > 0) { *d = *s++; if (!*d++) break; }
                if (n < 0) d[-1] = 0;
            }
        }
        rec->selected = (lbl_8055F698 == (void *)o);
    }

    int limit = ((int (*)(void *))item->vtable[6])(item);
    if (limit >= 5) limit = 5;
    fn_80236008((void *)(sp + 0xD8), limit,
        fn_802054EC(p26 + 0x658, ((int (*)(void *))item->vtable[5])(item), -1));
    selectedIndex = *arg0;
    int state = -1;
    if (((unsigned char *)arg2)[0] != 0) {
        void *current = ((void *(*)(void *, int))item->vtable[7])(item, selectedIndex);
        int advance;
        if (((int (*)(void *))item->vtable[8])(item) != 0) {
            void **cv = *(void ***)current;
            advance = ((int (*)(void *))cv[18])(current);
        } else {
            void **cv = *(void ***)current;
            advance = ((int (*)(void *))cv[16])(current);
        }
        if (advance != 0 && selectedIndex < limit - 1) ++selectedIndex;
    }
    f30 = lbl_80564208;
    f31 = lbl_80564200;
    {
        int i = 0;
        volatile Record *rec = (volatile Record *)(sp + 0x798);
        for (; i < limit; ++i, rec = (volatile Record *)((volatile unsigned char *)rec + 0xA0)) {
            void *child = ((void *(*)(void *, int))item->vtable[7])(item, i);
            void **cv = *(void ***)child;
            if (((unsigned char *)arg2)[0] != 0 &&
                arg2[2] == ((int (*)(void *))cv[8])(child)) {
                int delta = arg2[1];
                state = i;
                *(volatile void **)(sp + 0x24C) = child;
                *(volatile int *)(sp + 0x254) = i;
                if (delta > 0) {
                    int value = ((int (*)(void *))cv[10])(child);
                    void *entry = fn_801284F8(0x14, p26 + 0x664);
                    if (entry != 0) {
                        *(int *)entry = value - delta;
                        *(int *)((char *)entry + 4) = value;
                        *(unsigned char *)((char *)entry + 0xC) = 0;
                        *(float *)((char *)entry + 8) = f30;
                    }
                    *(volatile void **)(sp + 0x250) = entry;
                    *(float *)((char *)entry + 0x10) = f31;
                }
                *(volatile int *)(sp + 0x3AC) = selectedIndex;
                rec->child = (void *)(sp + 0x230);
            } else {
                rec->child = child;
            }
            void *object = (void *)rec->child;
            if (object != 0) {
                void **vt = *(void ***)object;
                const char *src = ((const char *(*)(void *))vt[10])(object);
                fn_801308F4((char *)rec + 0x6C, 0x1E, src);
                {
                    char *d = (char *)rec + 0x6C;
                    const char *s = lbl_8055C818;
                    int n = 0x1E;
                    while (*d && --n) ++d;
                    while (n-- > 0) { *d = *s++; if (!*d++) break; }
                    if (n < 0) d[-1] = 0;
                }
                object = (void *)rec->child;
                vt = *(void ***)object;
                src = ((const char *(*)(void *))vt[15])(object);
                fn_801308F4((char *)(sp + 0x4C), 0x14, src);
                {
                    char *d = (char *)rec + 0x6C;
                    const char *s = (const char *)(sp + 0x4C);
                    int n = 0x1E;
                    while (*d && --n) ++d;
                    while (n-- > 0) { *d = *s++; if (!*d++) break; }
                    if (n < 0) d[-1] = 0;
                }
                object = (void *)rec->child;
                vt = *(void ***)object;
                rec->mode = ((int (*)(void *))vt[16])(object) != 0;
                object = (void *)rec->child;
                vt = *(void ***)object;
                int mode = ((int (*)(void *))vt[11])(object);
                if (mode >= 0 && mode < 5) {
                    char *srcHead = (char *)__AXGetStackHead();
                    char *d = (char *)rec + 0x8A;
                    int n = 10;
                    while (n-- > 0) { *d = *srcHead++; if (!*d++) break; }
                    if (n < 0) d[-1] = 0;
                }
            }
            rec->selected = (lbl_8055F698 == (void *)rec);
            ((void (*)(void *))cv[8])(child);
        }
        *(volatile int *)(sp + 0x34) = state;
    }
    {
        void *object = (void *)(sp + 0xA18);
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        int i = 0;
        if (lbl_8055F698 == object) lbl_8055F698 = 0;
        for (; i < count; ++i) if (pool[i] == object) break;
        if (i < count) {
            if (i < count - 1) pool[i] = pool[count - 1];
            *(int *)(base + 0xE4) = count - 1;
        }
    }
    {
        void *object = (void *)(sp + 0x978);
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        int i = 0;
        if (lbl_8055F698 == object) lbl_8055F698 = 0;
        for (; i < count; ++i) if (pool[i] == object) break;
        if (i < count) {
            if (i < count - 1) pool[i] = pool[count - 1];
            *(int *)(base + 0xE4) = count - 1;
        }
    }
    {
        void *object = (void *)(sp + 0x8D8);
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        int i = 0;
        if (lbl_8055F698 == object) lbl_8055F698 = 0;
        for (; i < count; ++i) if (pool[i] == object) break;
        if (i < count) {
            if (i < count - 1) pool[i] = pool[count - 1];
            *(int *)(base + 0xE4) = count - 1;
        }
    }
    {
        void *object = (void *)(sp + 0x838);
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        int i = 0;
        if (lbl_8055F698 == object) lbl_8055F698 = 0;
        for (; i < count; ++i) if (pool[i] == object) break;
        if (i < count) {
            if (i < count - 1) pool[i] = pool[count - 1];
            *(int *)(base + 0xE4) = count - 1;
        }
    }
    {
        void *object = (void *)(sp + 0x798);
        char *base = (char *)&lbl_804B2FF8;
        int count = *(int *)(base + 0xE4);
        void **pool = *(void ***)(base + 0xE0);
        int i = 0;
        if (lbl_8055F698 == object) lbl_8055F698 = 0;
        for (; i < count; ++i) if (pool[i] == object) break;
        if (i < count) {
            if (i < count - 1) pool[i] = pool[count - 1];
            *(int *)(base + 0xE4) = count - 1;
        }
    }
    f30 = lbl_80564208;
    f31 = lbl_80564200;
    *(volatile unsigned char *)(sp + 0x270) = (unsigned char)(f30 != f31);
    {
        int value = *(volatile int *)(sp + 0x250);
        *(volatile void **)(sp + 0x230) = lbl_80348678;
        *(volatile void **)(sp + 0x234) = lbl_80348678 + 0x50;
        *(volatile int *)&lbl_8055F69C = 0;
        if (value != 0) fn_80128668();
        *(volatile int *)(sp + 0x270) = 0;
        *(volatile int *)(sp + 0x274) = 0;
        *(volatile int *)(sp + 0x278) = 0;
    }
    if (selectedIndex >= 0) *(volatile int *)arg0 = -1;
    return (int)arg1;
}

#pragma pop

extern int fn_80216D28();
extern int fn_8025C204(int);
extern unsigned char lbl_8055F684;
extern void *lbl_8055F698;
extern int lbl_8055F69C;
extern unsigned char lbl_80348678[];
extern unsigned int lbl_804B30D8[];
int fn_802837D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void *fn_80283938(void *arg0, int arg1) {
    void *base;
    void *next;
    void *field;
    if (arg0 != 0) {
        base = lbl_80348678;
        next = (char *)base + 0x50;
        *(void **)arg0 = base;
        *(void **)((char *)arg0 + 4) = next;
        lbl_8055F69C = 0;
        field = *(void **)((char *)arg0 + 0x20);
        if (field != 0) fn_80128668(field);
        if ((unsigned int)arg0 + 0x40 != 0) {
            if ((unsigned int)arg0 + 0x40 != 0) {
                *(int *)((char *)arg0 + 0x40) = 0;
                *(int *)((char *)arg0 + 0x44) = 0;
                *(int *)((char *)arg0 + 0x48) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma cplusplus on
extern "C" int fn_802839D0(void) {
    class Object {
    public:
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual int get(void *);
        virtual int next();
    };
    int value, result;
    if (lbl_8055F684 != 0 && lbl_8055F698 != 0) {
        Object *obj = *(Object **)((char *)lbl_8055F698 + 0x60);
        value = obj->next();
        obj = *(Object **)((char *)lbl_8055F698 + 0x60);
        result = obj->get(lbl_8055F698);
        ((int (*)(int, int))fn_8025C204)(result, value);
    } else {
        fn_80216D28();
    }
    return 0;
}
#pragma cplusplus reset
int fn_80283A50(void) {
    int i = 0;
    int count = (int)lbl_804B30D8[1];
    unsigned int *p = (unsigned int *)lbl_804B30D8[0];
    unsigned int value = (unsigned int)lbl_8055F698;
    if (count > 0) {
        do {
            if (*p == value) goto found;
            p++;
            i++;
        } while (--count != 0);
    }
    i = -1;
found:
    if (i >= 0) return 1;
    fn_80216D28();
    return 0;
}

#pragma scheduling invalid_target
int fn_80283AC8(void) {
    int i;
    int count;
    unsigned int value;
    void **p;
    void **base;
    count = (int)lbl_804B30D8[1];
    i = 0;
    value = (unsigned int)lbl_8055F698;
    base = (void **)lbl_804B30D8[0];
    p = base;
    for (; i < count; ++i) {
        if (*p != (void *)value) goto increment;
        goto found;
increment:
        ++p;
    }
    i = -1;
found:
    if (i >= 0 && *(int *)((char *)base[i] + 0x60)) {
        return 1;
    }
    fn_80216D28();
    return 0;
}
#pragma scheduling on
void fn_802840F4(void) {
    fn_8027E908();
}

void fn_802840F8(void) {
    fn_8027ED2C();
}

#pragma cplusplus on
extern "C" unsigned char lbl_8055F67C;
extern "C" int fn_8027F958(int *, void *);
extern "C" int fn_802812B4(int *, void *, int *, void *);
extern "C" void fn_8027EEE4(int);
extern "C" void *fn_8025007C(int);
extern "C" int fn_80019664(void);
extern "C" int fn_800196F0(void);
extern "C" void fn_80284580(int, int, void *, int);
extern "C" int fn_80263F30(int, int, int);
extern "C" void fn_8027F09C(int);
extern "C" void *memset(void *, int, unsigned int);
#pragma cplusplus on
extern "C" int fn_802840FC(int *arg0, void *arg1, int *arg2, void *arg3) {
    class Child {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5();
        virtual int value();
        virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12();
        virtual void f13(); virtual void f14(); virtual void f15();
        virtual int isZero();
    };
    class Node {
    public:
        virtual void f0(); virtual void f1(); virtual void f2();
        virtual int state();
        virtual int count();
        virtual Child *at(int);
        virtual int isEmpty();
    };
    class List {
    public:
        virtual void f0();
        virtual int count();
        virtual Node *at(int);
    };
    class Sequence {
    public:
        virtual void hide(int);
        virtual void setup(int, int, int);
        virtual void finish(int, int);
    };
    int options[5];
    int copy0;
    int copy1;
    int copy2;
    int copy3;
    int copy4;
    Sequence *sequence;
    Node *node2;
    Node *node;
    Child *child;
    List *list;
    int spC;
    int sp8;
    int temp_r25;
    int temp_r26;
    int var_r0;
    int var_r26;
    int var_r26_2;
    int var_r26_3;
    int var_r30;
    int var_r31;
    unsigned char *stateBytes;

    lbl_8055F67C = 0;
    copy0 = arg2[0];
    copy1 = arg2[1];
    copy2 = arg2[2];
    copy3 = arg2[3];
    copy4 = arg2[4];
    options[0] = copy0;
    options[1] = copy1;
    options[2] = copy2;
    options[3] = copy3;
    options[4] = copy4;
    spC = -1;
    temp_r25 = (*arg0 + 1) == 0;
    sp8 = -1;
    list = (List *)arg1;
    if (temp_r25 != 0) {
        var_r26 = 0;
        while (var_r26 < list->count()) {
            node = list->at(var_r26);
            if (node->isEmpty() == 0) {
                spC = var_r26;
                var_r26_2 = 0;
                while (var_r26_2 < node->count()) {
                    child = node->at(var_r26_2);
                    if (child->isZero() == 0) {
                        sp8 = var_r26_2;
                        break;
                    }
                    var_r26_2++;
                }
            } else {
                var_r26++;
                continue;
            }
            break;
        }
        if (spC < 0) {
            spC = 0;
        }
        if (sp8 < 0) {
            sp8 = 0;
        }
    } else {
        var_r26_3 = 0;
        while (var_r26_3 < list->count()) {
            node = list->at(var_r26_3);
            var_r30 = 0;
            while (var_r30 < node->count()) {
                child = node->at(var_r30);
                if (*arg0 == child->value()) {
                    spC = var_r26_3;
                    sp8 = var_r30;
                }
                var_r30++;
            }
            var_r26_3++;
        }
    }
    var_r0 = temp_r25 == 0;
    var_r31 = 0;
    var_r30 = spC;
    do {
        node2 = list->at(spC);
        if (spC != var_r30) {
            sp8 = temp_r25;
            var_r30 = spC;
            temp_r26 = fn_802812B4(&sp8, node2, options, arg1);
        }
        stateBytes = (unsigned char *)&options[4];
        if (stateBytes[1] != 0) {
            fn_8027EEE4(node2->state() + 1);
        }
        if (stateBytes[2] != 0) {
            sequence = (Sequence *)fn_8025007C(1);
            sequence->setup(fn_80019664(), 1, 0);
            sequence->finish(0, fn_800196F0());
            fn_80284580(0, 0, sequence, 0);
            if (sequence != 0) {
                sequence->hide(1);
            }
        }
        if ((stateBytes[0] != 0 && node2->state() == 1) ||
            (stateBytes[1] != 0 && node2->state() == 2)) {
            fn_80263F30(stateBytes[2] == 0, node2->state() == 2, 1);
        }
        if (stateBytes[1] != 0) {
            var_r31 = 0;
            goto exit_loop;
        }
        if (stateBytes[0] != 0 && node2->state() < 2) {
            fn_8027F09C(node2->state() + 1);
        }
        memset(options, 0, 0x14);
        if (temp_r26 != 0) {
            child = node2->at(sp8);
            *arg0 = child->value();
            var_r31 = 1;
            goto exit_loop;
        }
        var_r0 = 0;
    } while (fn_8027F958(&spC, arg1) != 0);
exit_loop:
    return var_r31;
}

#pragma cplusplus on
extern "C" int fn_80019088(void);
extern "C" void *fn_80019054(int);
extern "C" int fn_8024FBD8(void *, int);
extern "C" int stricmp(const char *, ...);
extern "C" int lbl_8055C860;
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_80284580(int arg0, int arg1, void *arg2, int arg3) {
    class Source {
    public:
        virtual void f0(); virtual void f1(); virtual void f2();
        virtual int getCount();
        virtual void *getAt(int);
        virtual void f5(); virtual void f6(); virtual void f7();
        virtual int getType(int);
    };
    class Buffer {
    public:
        virtual void destroy(int);
        virtual void set(void *, int, int);
        virtual void insert(int, int);
        virtual int getCount();
    };
    int offset;
    if (arg2 != 0)
        offset = ((Source *)arg2)->getCount();
    else
        offset = 0;
    int base = fn_80019088();
    base += offset;
    Buffer *buffer = (Buffer *)fn_8025007C(base);
    if (arg2 != 0) {
        int type;
        int i = 0;
        while (i < ((Source *)arg2)->getCount()) {
            buffer->set(((Source *)arg2)->getAt(i), 1, 0);
            type = ((Source *)arg2)->getType(i);
            buffer->insert(buffer->getCount() - 1, type);
            ++i;
        }
    }
    int i = 0;
    while (i < fn_80019088()) {
        char **entry = (char **)fn_80019054(i);
        if (((int (*)(const char *, const char *))stricmp)(entry[0], (const char *)&lbl_8055C860) == 0) {
            int boundary = *(int *)((char *)entry + 8);
            if (arg0 < boundary && arg1 >= boundary)
                buffer->set(*(void **)((char *)entry + 4), 1, 0);
        }
        ++i;
    }
    if (buffer->getCount() > 0)
        fn_8024FBD8(buffer, arg3);
    if (buffer != 0)
        buffer->destroy(1);
}
#pragma scheduling reset
#pragma pop

#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma dont_inline on
#pragma inline_depth(0)
extern "C" void fn_802854E0(void *arg0) {
    class Item { public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual int active();
    };
    class List { public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual int count(); virtual Item *get(int);
    };
    class Draw { public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void draw(void *, int, int, float, float);
        virtual void blend(void *, int, int, float, float, float);
    };
    extern void fn_80230C30(float *, float *, int, int);
    extern double cos(double), sin(double), fabs(double);
    extern float lbl_80564228, lbl_80564230, lbl_80564234, lbl_80564238;
    extern float lbl_8056423C, lbl_80564240, lbl_805641FC, lbl_80558DC4;
    extern int lbl_80347EF0, lbl_80347F10;
    float x, y, cx, cy, radius, step, angle;
    float base, one, zero, half;
    int i;
    char *q;
    char *p = (char *)arg0;
    if (*(List **)(p + 0x60) != 0) {
        if (*(unsigned char *)(p + 0xcd) == 0) return;
        fn_80230C30(&x, &y, *(int *)(p+4), *(int *)(p+8));
        cx = x + lbl_80564228 * (float)*(int *)(p+12);
        cy = y - lbl_80564228 * (float)*(int *)(p+16);
        radius = lbl_80564230 * (float)*(int *)(p+12);
        if ((*(List **)(p+0x60))->count() == 4) step = lbl_80564234;
        else step = lbl_80564238;
        base=lbl_8056423C; one=lbl_80564240; zero=lbl_805641FC; half=lbl_80564228;
        for (q=p, i=0; i<(*(List **)(p+0x60))->count(); i++, q+=4) {
            angle = base + step * ((float)i - half * (float)((*(List **)(p+0x60))->count()-1));
            x = cx + radius * (float)cos(angle);
            y = cy + radius * (float)sin(angle);
            if ((*(List **)(p+0x60))->get(i)->active()) {
                if (!((float)fabs(*(float *)(q+0xb4)-zero) <= lbl_80558DC4)) {
                    ((Draw *)fn_8027ED70())->draw(&lbl_80347EF0,20,-1,x,y);
                    ((Draw *)fn_8027ED70())->blend(&lbl_80347F10,20,-1,x,y,one-*(float *)(q+0xb4));
                } else {
                    ((Draw *)fn_8027ED70())->draw(&lbl_80347F10,20,-1,x,y);
                }
            } else {
                ((Draw *)fn_8027ED70())->draw(&lbl_80347EF0,20,-1,x,y);
            }
        }
    }
}
#pragma cplusplus reset
#pragma pop

void fn_802857A8(void *arg0) {
    extern int fn_80221EA8(void); extern void fn_801308F4(char *, int, const char *); extern void *fn_8027ED70(void); extern void *__AXGetStackHead(void); extern int stricmp(const char *, ...);
    extern int fn_801345D8(char *, int, const char *, const char *, int); extern void fn_80236954(char *); extern void fn_8027F204(char *);
    extern unsigned int lbl_804B30D8[]; extern char lbl_80347E50[]; extern char lbl_8055C818[]; extern char lbl_8055C86C[]; extern void *lbl_8055F698; extern float lbl_80564200;
    unsigned char *p=(unsigned char*)arg0; void *obj; void **vt; int mode,i,count; char tmp[0x64],other[0x14],*stack;
    p[0x18]=1; *(int*)(p+0x1c)=fn_80221EA8(); obj=*(void**)(p+0x60);
    if(!obj){*(int*)(p+0x20)=1;return;}
    *(int*)(p+0x20)=0;p[0x50]=1;*(int*)(p+0x48)=*(int*)(p+4);*(int*)(p+0x4c)=*(int*)(p+8);*(int*)(p+0x68)=*(int*)(p+4);*(float*)(p+0x64)=lbl_80564200;
    vt=*(void***)obj;p[0x98]=((int(*)(void*))vt[16])(obj);obj=*(void**)(p+0x60);vt=*(void***)obj;p[0x99]=((int(*)(void*))vt[18])(obj);
    obj=*(void**)(p+0x60);vt=*(void***)obj;fn_801308F4((char*)(p+0x6c),0x1e,((char*(*)(void*))vt[10])(obj));
    {char*d=(char*)(p+0x6c),*s=lbl_8055C818;i=0x1e;while(*d&&--i)++d;while(i-->0){*d=*s++;if(!*d++)break;}if(i<0)d[-1]=0;}
    obj=*(void**)(p+0x60);vt=*(void***)obj;fn_801308F4(other,0x14,((char*(*)(void*))vt[15])(obj));
    {char*d=(char*)(p+0x6c),*s=other;i=0x1e;while(*d&&--i)++d;while(i-->0){*d=*s++;if(!*d++)break;}if(i<0)d[-1]=0;}
    if(!p[0x98]){obj=*(void**)(p+0x60);vt=*(void***)obj;if(((int(*)(void*))vt[16])(obj)){obj=fn_8027ED70();vt=*(void***)obj;((void(*)(void*,void*))vt[14])(obj,lbl_80347E50+0x1bc);count=lbl_804B30D8[1];i=0;for(obj=(void*)lbl_804B30D8[0];count>0;count--,obj=(char*)obj+16,i++)if(*(void**)obj==arg0)break;if(!count)i=-1;fn_801345D8(tmp,0x64,lbl_8055C86C,lbl_80347E50+0xb00,i+1);fn_80236954(tmp);fn_8027F204(tmp);}}
    if(!p[0x99]){obj=*(void**)(p+0x60);vt=*(void***)obj;if(((int(*)(void*))vt[18])(obj)){obj=fn_8027ED70();vt=*(void***)obj;((void(*)(void*,void*))vt[14])(obj,lbl_80347E50+0x1e0);count=lbl_804B30D8[1];i=0;for(obj=(void*)lbl_804B30D8[0];count>0;count--,obj=(char*)obj+16,i++)if(*(void**)obj==arg0)break;if(!count)i=-1;fn_801345D8(tmp,0x64,lbl_8055C86C,lbl_80347E50+0xb10,i+1);fn_80236954(tmp);fn_8027F204(tmp);}}
    obj=*(void**)(p+0x60);vt=*(void***)obj;*(int*)(p+0x9c)=((int(*)(void*))vt[16])(obj)!=0;vt=*(void***)(p+0x60);mode=((int(*)(void*))vt[11])(*(void**)(p+0x60));
    if(mode>=0&&mode<5){stack=(char*)__AXGetStackHead();if(stricmp((char*)(p+0x8a))){obj=fn_8027ED70();vt=*(void***)obj;if(mode==0)((void(*)(void*,void*))vt[14])(obj,lbl_80347E50+0x1a0);else((void(*)(void*,void*))vt[14])(obj,lbl_80347E50+0x180);count=lbl_804B30D8[1];i=0;for(obj=(void*)lbl_804B30D8[0];count>0;count--,obj=(char*)obj+16,i++)if(*(void**)obj==arg0)break;if(!count)i=-1;fn_801345D8(tmp,0x64,lbl_8055C86C,lbl_80347E50+(mode==0?0xb24:0xb30),i+1);fn_80236954(tmp);fn_8027F204(tmp);}for(i=0;i<10;i++){p[0x8a+i]=*stack++;if(!p[0x8a+i])break;}if(i==10)p[0x93]=0;}
    *(int*)(p+0x94)=(arg0==&lbl_8055F698);
}

#pragma cplusplus on
extern "C" void fn_80286724(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v1();
}
#pragma cplusplus on
extern "C" void fn_80286738(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v2();
}
#pragma cplusplus on
extern "C" void fn_8028674C(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v3();
}
#pragma cplusplus on
extern "C" void fn_80286760(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v4();
}
#pragma cplusplus on
extern "C" void fn_80286774(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v5();
}
#pragma cplusplus on
extern "C" void fn_80286788(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v6();
}
#pragma cplusplus on
extern "C" void fn_8028679C(void *arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v7();
}
#pragma cplusplus off
int fn_802867B0(void *arg0) {
    extern double lbl_80564220;
    void * volatile p = *(void **)((char *)arg0 + 0x20);
    int value;
    if (p != 0) {
        value = (int)((float)*(int *)p + *(float *)((char *)p + 0x10));
        if (value > *(int *)((char *)p + 4))
            value = *(int *)((char *)p + 4);
        return value;
    }
    p = *(void **)((char *)arg0 + 0x1c);
    return ((int (*)(void *))(*(void **)((char *)*(void **)p + 0x28)))(p);
}

void fn_80286834(void **arg0) {
    int result;
    result = ((int (*)(void))(*(void **)((char *)*arg0 + 0x28)))();
    ((void (*)(void **, int))(*(void **)((char *)*arg0 + 0x30)))(arg0, result);
}

#pragma cplusplus on
extern "C" void fn_80286884(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v10();
}
#pragma cplusplus on
extern "C" void fn_80286898(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v11();
}
#pragma cplusplus on
extern "C" void fn_802868AC(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v12();
}
#pragma cplusplus on
extern "C" void fn_802868C0(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v13();
}
#pragma cplusplus off
int fn_802868D4(void *arg0) {
    int a = ((int (*)(void *))(*(void ***)arg0)[15])(arg0);
    int b = ((int (*)(void *))(*(void ***)arg0)[10])(arg0);
    return b >= a;
}

#pragma cplusplus on
extern "C" void fn_8028693C(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v15();
}
#pragma cplusplus off
typedef unsigned int (*GetFn)(void *);
typedef int (*CmpFn)(void *);
int fn_80286950(void **arg0) {
    unsigned int a = ((GetFn *)*arg0)[19](arg0);
    return (int)a <= ((CmpFn *)*arg0)[10](arg0);
}

#pragma cplusplus on
extern "C" void fn_802869B8(void* arg0) {
    ((ebi::title::TPlaneObj*)arg0)->m_sub->v17();
}
#pragma cplusplus off
int fn_802869CC(void *arg0, int arg1) {
    void *p;
    int d;
    switch (arg1) {
    case 13:
        p = *(void **)((char *)arg0 + 0x20);
        if (p != 0 && *(unsigned char *)((char *)arg0 + 0x29) == 0) {
            d = *(int *)((char *)p + 4) - *(int *)p;
            *(float *)((char *)p + 0x10) = (float)d;
            return 1;
        }
        break;
    }
    return 0;
}

#pragma dont_inline on
void fn_80287238(void *arg0) {
    extern float lbl_80564200, lbl_805641FC;
    extern int lbl_80347FB4;
    extern int fn_80214A9C(int);
    extern void *fn_8027ED70(void);
    void *temp_r4 = *(void **)((char *)arg0 + 0x20);
    if (temp_r4 != 0) {
        *(float *)((char *)temp_r4 + 0x10) = lbl_80564200;
        *(unsigned char *)((char *)arg0 + 0x29) = 0;
        *(unsigned char *)((char *)arg0 + 0x2A) = 0;
        *(unsigned char *)((char *)arg0 + 0x28) = ((unsigned char (*)(void))(*(void ***)arg0)[16])();
        ((void (*)(void *))(*(void ***)fn_8027ED70())[14])(&lbl_80347FB4);
        fn_80214A9C(0x1F);
        *(float *)((char *)arg0 + 0x178) = lbl_805641FC;
        return;
    }
    *(unsigned char *)((char *)arg0 + 0x29) = 1;
    *(unsigned char *)((char *)arg0 + 0x2A) = 0;
    *(float *)((char *)arg0 + 0x178) = lbl_80564200;
}
#pragma dont_inline reset
extern float lbl_80564200;
extern float lbl_805641FC;
extern int lbl_80347FB4;
extern void* fn_8027ED70(void);
extern int fn_80214A9C(int);
#pragma cplusplus on
extern "C" void fn_802872DC(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v1();
}
#pragma cplusplus on
extern "C" void fn_802872F0(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v2();
}
#pragma cplusplus on
extern "C" void fn_80287304(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v3();
}
#pragma cplusplus off
#pragma cplusplus on
extern "C" void fn_80287318(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v4();
}
#pragma cplusplus off
void* fn_8028732C(void* arg0, int arg1) {
    void* cached = *(void**)((char*)arg0 + 8);
    void* obj;
    if (cached != 0 && arg1 == *(int*)((char*)arg0 + 12))
        return cached;
    obj = *(void**)((char*)arg0 + 4);
    return (*(void* (**)(void))(*(void***)obj + 7))();
}

void fn_80287360(void) {
}

int fn_80287364(void* arg0) {
    int i;
    void* item;

    for (i = 0; i < ((int (*)(void*))(*(void***)arg0)[6])(arg0); i++) {
        item = ((void* (*)(void*, int))(*(void***)arg0)[7])(arg0, i);
        if (((int (*)(void))(*(void***)item)[16])() == 0) {
            return 0;
        }
    }
    return 1;
}

#pragma cplusplus on
extern "C" void fn_802873F8(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v7();
}
#pragma cplusplus off
int fn_8028740C(void* arg0) {
    int i;
    void* item;

    for (i = 0; i < ((int (*)(void*))(*(void***)arg0)[6])(arg0); i++) {
        item = ((void* (*)(void*, int))(*(void***)arg0)[7])(arg0, i);
        if (((int (*)(void))(*(void***)item)[18])() == 0) {
            return 0;
        }
    }
    return 1;
}

#pragma cplusplus on
extern "C" void fn_802874A0(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v9();
}
#pragma cplusplus on
extern "C" void fn_802874B4(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v10();
}
#pragma cplusplus off
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
#pragma cplusplus on
struct Fn80280F7CObj {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void *f11();
    virtual char *f12();
};
#pragma cplusplus reset
#pragma cplusplus on
class Fn80280F7CObject {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10();
    virtual void* f11(); virtual const char* f12();
};
#pragma cplusplus reset
#pragma cplusplus on
struct Fn80280A38Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual int ready(); virtual char *getName();
};
#pragma cplusplus reset
#pragma cplusplus on
struct V80280A38 {
    virtual int f0(); virtual int f1(); virtual int f2(); virtual int f3();
    virtual int f4(); virtual int f5(); virtual int f6(); virtual int f7();
    virtual int f8(); virtual int f9(); virtual int f10(); virtual int test();
    virtual const char *name();
};
#pragma cplusplus off
#pragma cplusplus on
struct Fn80284760Obj {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
 virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16();
};
#pragma cplusplus reset
