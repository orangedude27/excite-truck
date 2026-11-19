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
    virtual int v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17();
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
#pragma cplusplus on
struct Fn8027F288Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char *getName();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};
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
    int tail[4];
} Fn8027F958Stack;

#pragma cplusplus on
struct Fn802857A8Child {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual int v10(); virtual int v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18();
};
struct Fn802857A8Drawer {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(const char *);
};
#pragma cplusplus reset
struct Fn80283E28Vt { void *pad[3]; char *(*v3)(void *); void *pad2[3]; char *(*v7)(void *); int (*v8)(void *); int (*v9)(void *); };
struct Fn80283E28Sub { struct Fn80283E28Vt *vt; };
struct Fn80283E28Obj { char pad[0x60]; struct Fn80283E28Sub *sub; };
struct Fn80283E28List { struct Fn80283E28Obj **items; int count; };
static struct Fn80283E28Obj *fn_80283E28_get(struct Fn80283E28List *l, int i) {
    if (i >= 0 && i < l->count && l->items[i]->sub != 0) return l->items[i];
    return 0;
}
extern char lbl_8034862C[];
extern int lbl_8055C7E0;
extern int fn_80128668();
extern void fn_8027E908(void);
extern char lbl_80348798[];
extern unsigned int lbl_8055F688;
 struct Fn8027F834List { void **items; int count; int pad[2]; };
 extern struct Fn8027F834List lbl_804B3048;
struct Fn8027F958Global {
    int fields[5];
    char pad[0x4B];
    struct Fn8027F834List list;
    char pad2[0x18];
    char name[0x90];
};
 

/* One entry of the ebi UI's record list: it shows the record its +0x60 child points at
   and carries the flags the list walks to move the selection (lbl_8055F698) over it.
   Built by fn_802812B4, destroyed by fn_80283814. */
struct EbiListItem {
    void *vtable;            /* 0x00 */
    char pad04[0x10];
    int unk14;               /* 0x14 */
    unsigned char flag18;    /* 0x18 */
    char pad19[7];
    int unk20;               /* 0x20 */
    int state24;             /* 0x24 2 while alive, 1 once destroyed */
    char pad28[0x10];
    float unk38;             /* 0x38 */
    float unk3C;             /* 0x3C */
    int unk40;               /* 0x40 */
    unsigned char flag44;    /* 0x44 */
    char pad45[0xB];
    unsigned char flag50;    /* 0x50 */
    char pad51[0xB];
    unsigned char flag5C;    /* 0x5C */
    char pad5D[3];
    void *child;             /* 0x60 the record this entry lists */
    char pad64[8];
    char name[0x1E];         /* 0x6C the child's name, copied in at build */
    char text[0xA];          /* 0x8A */
    int selected;            /* 0x94 this entry is the current selection */
    unsigned char flag98;    /* 0x98 */
    unsigned char flag99;    /* 0x99 */
    char pad9A[2];
    int mode;                /* 0x9C */
};

/* The live entries of that list: the list at lbl_804B2FF8+0xE0, entry pointers at
   +0x00 and the count at +0x04. */
#define EBI_ITEMS ((void **)lbl_804B30D8[0])
#define EBI_ITEM_COUNT (lbl_804B30D8[1])

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
#pragma scheduling invalid_target
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
    const char *base = lbl_80347E50;
    const char *idName;
    lbl_8055F680 = fn_80258354();
    ((InitObj *)lbl_8055F680)->v1(base, base+0x14, 4);
    ((InitObj *)lbl_8055F680)->v1(base+0x24, base+0x14, 3);
    ((InitObj *)lbl_8055F680)->v1(base+0x30, base+0x14, 1);
    ((InitObj *)lbl_8055F680)->v1(base+0x3c, base+0x14, 2);
    ((InitObj *)lbl_8055F680)->v1(base+0x48, base+0x14, 4);
    idName = fn_80007F90(0x180201);
    ((InitObj *)lbl_8055F680)->v1(idName, base+0x58, 1);
    idName = fn_80007F90(0x180302);
    ((InitObj *)lbl_8055F680)->v1(idName, base+0x58, 2);
    ((InitObj *)lbl_8055F680)->v1(base+0x68, base+0x58, 1);
    ((InitObj *)lbl_8055F680)->v1(&lbl_8055C798, base+0x78, 0);
    ((InitObj *)lbl_8055F680)->v1(&lbl_8055C7A0, base+0x78, 1);
    ((InitObj *)lbl_8055F680)->v1(&lbl_8055C7A8, base+0x78, 2);
    ((InitObj *)lbl_8055F680)->v1(base+0x88, base+0x78, 3);
    ((InitObj *)lbl_8055F680)->v1(&lbl_8055C7B0, base+0x78, 4);
    ((InitObj *)lbl_8055F680)->v1(base+0x94, base+0x78, 5);
    ((InitObj *)lbl_8055F680)->v1(base+0xA0, base+0xB4, 1);
    ((InitObj *)lbl_8055F680)->v1(base+0xC0, base+0xB4, 0);
    ((InitObj *)lbl_8055F680)->v1(base+0xD0, base+0xE0, 0);
    ((InitObj *)lbl_8055F680)->v1(base+0xF0, base+0xE0, 1);
    ((InitObj *)lbl_8055F680)->v1(base+0x100, base+0x110, 0);
    ((InitObj *)lbl_8055F680)->v1(base+0x120, base+0x110, 1);
    ((InitObj *)lbl_8055F680)->v1(base+0x130, base+0x140, 6);
    ((InitObj *)lbl_8055F680)->v2(&lbl_8055C7B8, base+0x14C);
    ((InitObj *)lbl_8055F680)->v2(&lbl_8055C7C0, base+0x158);
    ((InitObj *)lbl_8055F680)->v3(base+0x164, base+0x174, 1);
    ((InitObj *)lbl_8055F680)->v3(base+0x180, base+0x190, 0);
    ((InitObj *)lbl_8055F680)->v3(base+0x1A0, base+0x1AC, 0);
    ((InitObj *)lbl_8055F680)->v3(base+0x1BC, base+0x1D0, 0);
    ((InitObj *)lbl_8055F680)->v3(base+0x1E0, base+0x1D0, 0);
    ((InitObj *)lbl_8055F680)->v3(base+0x1F8, base+0x204, 0);
    ((InitObj *)lbl_8055F680)->v3(base+0x214, base+0x190, 0);
    ((InitObj *)lbl_8055F680)->v3(base+0x228, base+0x238, 0);
}
#pragma scheduling reset
#pragma cplusplus reset
#pragma pop

extern "C" void fn_8027ED2C(void) {
    /* Destroy the global object at lbl_8055F680 if present, then clear it. */
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
#pragma dont_inline on
void* fn_8027ED70(void) {
#define gCareerObj lbl_8055F680
    /* Get the singleton career/UI manager object created by fn_8027E908. */
    return gCareerObj;
#undef gCareerObj
}
#pragma dont_inline reset

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
/* One line of a debug menu passed to fn_802146BC (see text_8025E034_.c). */
typedef struct CareerMenuItem {
    void *name;
    int type;
    void *data;
    int a;
    int b;
} CareerMenuItem;
typedef struct CareerMenu {
    int w0;
    CareerMenuItem *items;
    int w2;
    int w3;
    int w4;
} CareerMenu;
static inline void CareerMenuItemSet(CareerMenuItem *item, void *name, int type, void *data, int a, int b) {
    item->name = name;
    item->type = type;
    item->data = data;
    item->a = a;
    item->b = b;
}
#pragma use_lmw_stmw off
void fn_8027ED78(int arg0, int arg1, int arg2) {
#pragma scheduling invalid_target
    register int a0, a2, a3, a4;
    register int b0, b1, b2, b3, b4;
    register int ptrA8 = (int)&lbl_803480A8;
    register int ptrC7 = (int)&lbl_8055C7C8;
    register int ptrB8 = (int)&lbl_8055B860;
    register int zero = 0;
    register int three = 3;
    register int six = 6;
    register int minusTwo = -2;
    register int thirteen = 13;
    int block[26];
    int *at = (int *)lbl_802FA848;
    a0 = *at++;
    b0 = ((int *)&lbl_804B2FF8)[0];
    b1 = ((int *)&lbl_804B2FF8)[1];
    b2 = ((int *)&lbl_804B2FF8)[2];
    b3 = ((int *)&lbl_804B2FF8)[3];
    b4 = ((int *)&lbl_804B2FF8)[4];
    a2 = at[1];
    a3 = at[2];
    a4 = at[3];

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
    ((int (*)(int *, int, int, int))fn_802146BC)(block, -999, -999, 1);
}
#pragma use_lmw_stmw on
/* Set the one-shot career level-up flag when `selection` is 2, then refresh
 * the menu; the flag drives fn_8027EE88's unlock sound. */
void fn_8027EE74(int selection) {
    extern unsigned char lbl_8055F684;
    extern int fn_80236914(void);
    *(signed char*)&lbl_8055F684 = (selection == 2);
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
/* One-shot trigger to play the career level-up unlock sound. */
extern "C" int fn_8027EE88(void) {
    if (lbl_8055F685 == 0 && lbl_8055F684 != 0) {
        lbl_8055F685 = 1;
        CareerObj_8027EE88 *careerObj = (CareerObj_8027EE88 *)fn_8027ED70();
        careerObj->f12(lbl_80348078);
    }
    return 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_8027EEE4(int arg0) {
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
    register int zero1;
    register int zero2;
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
    index = arg0 - 1;
    frame.objects[0][2] = (int)lbl_804B3018;
    zero1 = 0;
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
#pragma use_lmw_stmw off
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
/* Appends a fixed-size (0x1E-byte) copy of src into the string buffer managed
 * by the global state in lbl_8055F69C, or reports overflow via fn_802E30C8. */
extern "C" void fn_8027F204(char *src) {
    char *dst;
    int remaining;
    int count;
    struct Fn8027F204State *state = (struct Fn8027F204State *)lbl_8055F69C;

    if (state == 0) return;
    count = state->count;
    if (count + 1 <= state->max) {
        remaining = 0x1e;
        dst = state->buffer + state->count++ * 0x1e;
        goto enter;
        for (;;) {
            if (--remaining <= 0) {
                dst[-1] = 0;
                return;
            }
        enter:
            if ((*dst++ = *src++) == 0) {
                return;
            }
        }
    }
    fn_802E30C8(lbl_80348270, count);
}

extern "C" void fn_8027F288(Fn8027F288Obj *arg0, Fn8027F288Obj *arg1) {
    extern void fn_801345D8(char *, int, const char *, ...);
    extern int fn_802168E4(void);
    extern int fn_80214A9C(int);
    extern int fn_80214AF0(int);
    extern char lbl_80347E50[];
    char buf[0x64];
    int frame[60];
    int r = fn_802168E4();
    if (arg1 != 0) {
        fn_801345D8(buf, 0x64, lbl_80347E50 + 0x46C, arg1->getName());
    } else {
        fn_801345D8(buf, 0x64, lbl_80347E50 + 0x4B0, arg0->getName());
    }
    if (r != 0) fn_80214A9C(0x1F);
    frame[0] = 0;
    fn_802146BC(frame, -999, -999, 1, 0, 0, 0, 0);
    if (r != 0) fn_80214AF0(0x1F);
}

#pragma scheduling reset
#pragma cplusplus off
static inline int fn_8027F834_find(void **p, void *value, int count) {
    int i = 0;
    for (; i < count; ++i) {
        if (*p != value) goto increment;
        return i;
    increment:
        ++p;
    }
    return -1;
}

#define WIDGET_VTABLE lbl_80348798
#define WIDGET_LIST lbl_804B3048
#define SELECTED_WIDGET lbl_8055F688
/* Destructor of an ebi list widget (this is slot 0 of the vtable at lbl_80348798):
   restore the plain widget vtable, drop the widget from the live-widget list, clear
   the selection when it was the selected widget, mark it destroyed (state24 = 1)
   and, when the flag is above 0, hand its memory back to the allocator. */
void *fn_8027F834(struct EbiListItem *widget, int freeMemory) {
    int index, count;
    if (widget != 0) {
        widget->vtable = WIDGET_VTABLE;
        if (SELECTED_WIDGET == (unsigned int)widget) SELECTED_WIDGET = 0;
        index = fn_8027F834_find(WIDGET_LIST.items, widget, WIDGET_LIST.count);
        if (index != -1 && index >= 0 && index < (count = *(volatile int *)&WIDGET_LIST.count)) {
            if (index != count - 1)
                WIDGET_LIST.items[index] = WIDGET_LIST.items[count - 1];
            *(volatile int *)&WIDGET_LIST.count = *(volatile int *)&WIDGET_LIST.count - 1;
        }
        if (widget != 0) {
            widget->flag18 = 0;
            widget->flag50 = 0;
            widget->flag5C = 0;
            widget->state24 = 1;
            widget->unk20 = 0;
            widget->flag44 = 0;
        }
        if (freeMemory > 0) fn_80128668((int)widget);
    }
    return widget;
}
#undef SELECTED_WIDGET
#undef WIDGET_LIST
#undef WIDGET_VTABLE

#pragma scheduling on
int fn_8027F958(int *selection, void *collection) {
    struct Fn8027F958State {
        char pad[0x50];
        struct Fn8027F834List list;
    };
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
    register void *object, *item;
    register Fn8027F958Widget *widget;
    register void **items, **storage;
    register char *constants = (char *)&lbl_802FA848;
    register char *state = (char *)&lbl_804B2FF8;
    register char *strings = lbl_80347E50;
    register float defaultValue;
    register float defaultScale;
    register void *widgetVtable;
    register char *src, *dst;
    register int i, j, index, remaining, result, mode, count, reported;
    register float *value;
    object = ((GetItem)(*(void ***)collection)[4])(collection, 0);
    mode = ((GetInt)(*(void ***)object)[5])(object);
    defaultScale = lbl_805641F8;
    defaultValue = lbl_805641FC;
    widgetVtable = lbl_80348798;
    index = lbl_804B3048.count;
    storage = lbl_804B3048.items;
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
    lbl_804B3048.count = index + 1;
    storage[index] = &stack.widgets[0];
    stack.widgets[0].unk7E = 0;
    stack.widgets[0].unkB0 = 0;
    index = lbl_804B3048.count;
    storage = lbl_804B3048.items;
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
    lbl_804B3048.count = index + 1;
    storage[index] = &stack.widgets[1];
    stack.widgets[1].unk7E = 0;
    stack.widgets[1].unkB0 = 0;
    index = lbl_804B3048.count;
    storage = lbl_804B3048.items;
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
    lbl_804B3048.count = index + 1;
    storage[index] = &stack.widgets[2];
    stack.widgets[2].unk7E = 0;
    stack.widgets[2].unkB0 = 0;
    index = lbl_804B3048.count;
    storage = lbl_804B3048.items;
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
    lbl_804B3048.count = index + 1;
    storage[index] = &stack.widgets[3];
    stack.widgets[3].unk7E = 0;
    stack.widgets[3].unkB0 = 0;
    index = lbl_804B3048.count;
    storage = lbl_804B3048.items;
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
    lbl_804B3048.count = index + 1;
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
    if (index >= 0 && index < lbl_804B3048.count) {
        object = lbl_804B3048.items[index];
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
    if (index >= 0 && index < lbl_804B3048.count) {
        object = lbl_804B3048.items[index];
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
        for (i = 0; i < lbl_804B3048.count; ++i)
            if ((unsigned int)lbl_804B3048.items[i] == lbl_8055F688) break;
        *selection = i < lbl_804B3048.count ? i : -1;
    }
    lbl_8055F688 = 0;
    lbl_804B3048.count = 0;
    lbl_8055F68C = 0;
    lbl_8055F690 = 0;
    *(char *)(state + 0x70) = 0;
    lbl_8055F694 = 0;
    widget = &stack.widgets[4];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < lbl_804B3048.count) {
        count = lbl_804B3048.count - 1;
        if (index != count) lbl_804B3048.items[index] = lbl_804B3048.items[count];
        lbl_804B3048.count = lbl_804B3048.count - 1;
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
    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < lbl_804B3048.count) {
        count = lbl_804B3048.count - 1;
        if (index != count) lbl_804B3048.items[index] = lbl_804B3048.items[count];
        lbl_804B3048.count = lbl_804B3048.count - 1;
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
    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < lbl_804B3048.count) {
        count = lbl_804B3048.count - 1;
        if (index != count) lbl_804B3048.items[index] = lbl_804B3048.items[count];
        lbl_804B3048.count = lbl_804B3048.count - 1;
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
    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < lbl_804B3048.count) {
        count = lbl_804B3048.count - 1;
        if (index != count) lbl_804B3048.items[index] = lbl_804B3048.items[count];
        lbl_804B3048.count = lbl_804B3048.count - 1;
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
    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    for (index = 0; index < count; ++items, ++index) {
        if (*items == widget) break;
    }
    if (index == count) index = -1;
    if (index != -1 && index >= 0 && index < lbl_804B3048.count) {
        count = lbl_804B3048.count - 1;
        if (index != count) lbl_804B3048.items[index] = lbl_804B3048.items[count];
        lbl_804B3048.count = lbl_804B3048.count - 1;
    }
    widget->unk18 = 0;
    widget->unk50 = 0;
    widget->unk5C = 0;
    widget->unk24 = 1;
    widget->unk20 = 0;
    widget->unk44 = 0;
    return result;
}
#undef lbl_804B3048
 #pragma scheduling invalid_target

extern int fn_80216D28(void);
/* Menu action: report 1 while a UI object is selected; with no selection, signal back and report 0. */
int fn_80280898(void) {
#define SELECTED_OBJECT lbl_8055F688
#define SignalBack fn_80216D28
    extern unsigned int lbl_8055F688;
    if (SELECTED_OBJECT == 0) {
        SignalBack();
        return 0;
    }
    return 1;
#undef SignalBack
#undef SELECTED_OBJECT
}

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
    struct Finder {
        static int find(void **items, int count, void *key) {
            int i;
            for (i = 0; i < count; i++) {
                if (items[i] == key)
                    return i;
            }
            return -1;
        }
    };
    extern int fn_80019714(void);
    extern int fn_80214D50(int);
    extern void fn_801345D8();
    extern void fn_80236954(char *);
    extern char lbl_80348480[];
    char buffer[0x1E];
    int index;

    index = Finder::find(lbl_804B3048.items, lbl_804B3048.count, (void *)lbl_8055F688);
    if (index >= 0) {
        void *entry = lbl_804B3048.items[index];
        int active = 0;
        if (*(void **)((char *)entry + 0x60) != 0 &&
            fn_80019714() == 0 &&
            ((CheckObj *)*(void **)((char *)entry + 0x60))->f7()) {
            active = 1;
        }
        if (active) {
            void *key = (void *)lbl_8055F688;
            ((void (*)(char *, int, const char *, ...))fn_801345D8)(
                buffer, 0x1E, lbl_80348480,
                ((*(unsigned char *)((char *)key + 0x64) != 0)
                    ? 5
                    : Finder::find(lbl_804B3048.items, lbl_804B3048.count, key)) + 1);
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
#pragma use_lmw_stmw off
/* Menu action: step from an entry of a page (one whose key is not 0) to the
   page-0 entry (the list) the menu keeps with it, remembering this entry so the
   list can bring it back.  The list entry is looked up once - the first entry
   whose key is 0 - and kept, as is this one; the entry then becomes the
   selection and its text is copied to the buffer the menu shows.  Doing nothing
   but returning 0 leaves the selection as it was; fn_80280C00 is the reverse. */
extern "C" int fn_80280A38(void) {
    /* What the menu keeps at +0x60 of an entry: the page the entry belongs to
       (getKey, 0 for the list itself) and the text to show for it. */
    class Object {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual int getKey(); virtual char *getText();
    };
    struct ItemFinder {
        /* Where `entry` sits in the menu's list of entries, or -1. */
        static int indexOf(void *entry) {
            void **items = lbl_804B3048.items;
            int count = lbl_804B3048.count;
            int i;
            for (i = 0; i < count; i++) {
                if (items[i] == entry)
                    return i;
            }
            return -1;
        }
    };
    extern int lbl_8055F68C;                  /* the entry of page 0, the list */
    extern int lbl_8055F690;                  /* the page entry to come back to */
    extern unsigned char lbl_804B3068[];      /* text shown for the selection */
    int i;
    int index;
    void *item;

    if (lbl_8055F688 == 0)                    /* nothing selected */
        goto done;
    if (*(Object * volatile *)((char *)lbl_8055F688 + 0x60) == 0)
        goto done;
    if ((*(Object **)((char *)lbl_8055F688 + 0x60))->getKey() == 0)
        goto done;                            /* the list entry itself: no further back */

    lbl_8055F690 = lbl_8055F688;              /* remember where to come back to */
    if (lbl_8055F68C == 0) {                  /* find the list entry once */
        for (i = 0; i < lbl_804B3048.count; i++) {
            void *entry = lbl_804B3048.items[i];
            Object *o = *(Object **)((char *)entry + 0x60);
            if (o != 0 && o->getKey() == 0) {
                lbl_8055F68C = (int)entry;
                break;
            }
        }
    }
    if (*(volatile int *)&lbl_8055F68C == 0)  /* the menu has no list entry */
        goto done;

    {
        index = ItemFinder::indexOf((void *)lbl_8055F68C);
        lbl_804B3068[0] = 0;                  /* the shown text goes with the selection */
        if (index < 0 || index >= *(volatile int *)&lbl_804B3048.count)
            goto clear;
        item = lbl_804B3048.items[index];
        lbl_8055F688 = (unsigned int)item;    /* select the list entry */
        if (item != 0 && *(Object * volatile *)((char *)item + 0x60) != 0) {
            Object *o = *(Object **)((char *)item + 0x60);
            char *src = o->getText();
            int n = 100;                      /* at most this much of it fits */
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
    goto done;
clear:
    lbl_8055F688 = 0;                         /* gone: leave nothing selected */
done:
    return 0;
}
#pragma scheduling on
extern "C" int fn_80280C00(void) {
    class Obj { public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual unsigned int getKey(); virtual const char *getText();
    };
    extern int lbl_8055F68C;
    extern int lbl_8055F690;
    extern unsigned char lbl_804B3068[];
    int i;
    void *item;
    Obj *obj;
    void *sel;
    void **p;
    void **items;
    int index;
    const char *src;
    char *dst;
    int n;
    if (lbl_8055F688 == 0)
        goto finish;
    if (*(Obj * volatile *)((char *)lbl_8055F688 + 0x60) == 0)
        goto finish;
    obj = *(Obj **)((char *)lbl_8055F688 + 0x60);
    if (obj->getKey() != 0)
        goto finish;
    lbl_8055F68C = lbl_8055F688;
    if (lbl_8055F690 == 0) {
        for (i = 0; i < lbl_804B3048.count; i++) {
            item = lbl_804B3048.items[i];
            obj = *(Obj **)((char *)item + 0x60);
            if (obj != 0 && obj->getKey() != 0) {
                lbl_8055F690 = (int)item;
                break;
            }
        }
    }
    if (*(volatile int *)&lbl_8055F690 == 0)
        goto finish;
    items = lbl_804B3048.items;
    sel = (void *)*(volatile int *)&lbl_8055F690;
    p = items;
    index = 0;
    while (index < lbl_804B3048.count) {
        if (*p != sel) {
            p++;
            index++;
            continue;
        }
        goto found;
    }
    index = -1;
found:
    lbl_804B3068[0] = 0;
    if (index < 0)
        goto clear;
    if (index >= *(volatile int *)((char *)&lbl_804B3048 + 4))
        goto clear;
    item = items[index];
    lbl_8055F688 = (unsigned int)item;
    if (item == 0)
        goto finish;
    if (*(Obj * volatile *)((char *)item + 0x60) == 0)
        goto finish;
    obj = *(Obj **)((char *)item + 0x60);
    src = obj->getText();
    dst = (char *)lbl_804B3068;
    n = 100;
    goto body;
tail:
    if (--n <= 0) {
        dst[-1] = 0;
        goto finish;
    }
    goto body;
body:
    {
        char c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto finish;
        goto tail;
    }
clear:
    lbl_8055F688 = 0;
finish:
    return 0;
}
#pragma cplusplus reset
extern unsigned char lbl_804B3068[];
typedef unsigned int (*GetKeyFn)(void *);
typedef char *(*GetTextFn)(void *);
int fn_80280DC8(void) {
    register unsigned int key;
    register void *obj;
    register void *item;
    register void **p;
    register void **items;
    register int count;
    register int index;
    char *src;
    char *dst;
    int n;
    int next;

    if (*(volatile unsigned int *)&lbl_8055F688 == 0)
        goto reset;
    items = lbl_804B3048.items;
    count = lbl_804B3048.count;
    key = *(volatile unsigned int *)&lbl_8055F688;
    index = 0;
    p = items;
    while (index < count) {
        if (*p == (void *)key)
            goto first_found;
        p++;
        index++;
    }
    index = -1;
first_found:
    item = items[index];
    if (*(void * volatile *)((char *)item + 0x60) == 0)
        goto finish;
    obj = *(void **)((char *)item + 0x60);
    next = index + 1;
    key = ((GetKeyFn)(*(void ***)obj)[11])(obj);
    index = next;
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
    if (index < 0 || index >= count) {
        *(volatile unsigned int *)&lbl_8055F688 = 0;
        goto finish;
    }
    item = items[index];
    lbl_8055F688 = (unsigned int)item;
    if (item == 0)
        goto finish;
    if (*(void * volatile *)((char *)item + 0x60) == 0)
        goto finish;
    obj = *(void **)((char *)item + 0x60);
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
    struct Finder {
        static int find(void **items, int count, void *key) {
            int i;
            for (i = 0; i < count; ++items, ++i) {
                if (*items == key)
                    return i;
            }
            return -1;
        }
    };
    if (*(volatile unsigned int *)&lbl_8055F688 == 0)
        goto reset;
    unsigned int key = *(volatile unsigned int *)&lbl_8055F688;
    int i = Finder::find(lbl_804B3048.items, lbl_804B3048.count, (void *)key);
    void *firstItem = lbl_804B3048.items[i];
    if (*(Obj * volatile *)((char *)firstItem + 0x60) != 0) {
        Obj *obj = *(Obj **)((char *)firstItem + 0x60);
        void *identity = obj->f11();
        int j = i - 1;
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
#pragma scheduling on
reset:
    *(volatile unsigned int *)&lbl_8055F688 = 0;
    goto finish;
#pragma scheduling invalid_target
finish:
    fn_80216D28();
    return 0;
}
#pragma scheduling reset
#pragma pop
static inline int fn_80281138_find(void **items, int count, void *key) {
    int i;
    for (i = 0; i < count; ++i, ++items) {
        if (*items == key)
            return i;
    }
    return -1;
}

extern "C" int fn_80281138(void) {
    extern int fn_801345D8(char *, int, const char *, const char *, int);
    extern int fn_802368EC(void);
    extern void fn_80236954(char *);
    extern void *lbl_8055F694;
    extern char lbl_8034848C[];
    extern char lbl_8034849C[];
    int index;
    void *selected;

    index = fn_80281138_find(lbl_804B3048.items, lbl_804B3048.count,
                             (void *)lbl_8055F688);
    if (index >= 0 && fn_802368EC() != 0) {
        char buffer1[0x1E];
        if (*(unsigned char *)((char *)lbl_8055F688 + 0x64) != 0) {
            index = 5;
        } else {
            index = fn_80281138_find(lbl_804B3048.items, lbl_804B3048.count, (void *)lbl_8055F688);
        }
        ((void (*)(char *, int, const char *, ...))fn_801345D8)(
            buffer1, 0x1E, lbl_8034848C, index + 1);
        fn_80236954(buffer1);
    }
    selected = lbl_8055F694;
    if (selected != 0) {
        char buffer2[0x1E];
        int idx;
        lbl_8055F688 = 0;
        if (*(unsigned char *)((char *)selected + 0x64) != 0) {
            idx = 5;
        } else {
            idx = fn_80281138_find(lbl_804B3048.items, lbl_804B3048.count, selected);
        }
        ((void (*)(char *, int, const char *, ...))fn_801345D8)(
            buffer2, 0x1E, lbl_8034849C, idx + 1);
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
extern "C" char lbl_8055C818[8];
extern "C" void *lbl_8055F698;
extern "C" void fn_801308F4(char *, int, const char *);
extern "C" void *__AXGetStackHead(void);
extern "C" void *fn_801284F8(int, const char *);
extern "C" char lbl_8055C818[8], lbl_8055C820[];
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
int fn_802837D4(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

static inline int fn_80283814_find(void **p, void *value, int count) {
    int i = 0;
    for (; i < count; ++i) {
        if (*p != value) goto increment;
        return i;
increment:
        ++p;
    }
    return -1;
}

/* Destructor of an ebi UI record entry: installs the destructor's vtable, drops the
 * list selection if it pointed here, takes the entry out of the live-entry list (the
 * last entry moves into its slot), resets the entry's flags and, when shouldFree is
 * positive, frees the entry itself. */
void *fn_80283814(struct EbiListItem *entry, int shouldFree) {
    int index;
    int count;
    if (entry != 0) {
        *(void **)entry = lbl_80348738;
        if (lbl_8055F698 == entry) lbl_8055F698 = 0;
        index = fn_80283814_find(EBI_ITEMS, entry, (int)EBI_ITEM_COUNT);
        if (index != -1 && index >= 0 && index < (count = *(volatile int *)&EBI_ITEM_COUNT)) {
            if (index != count - 1)
                EBI_ITEMS[index] = EBI_ITEMS[count - 1];
            EBI_ITEM_COUNT--;
        }
        if (entry != 0) {
            entry->flag18 = 0;
            entry->flag50 = 0;
            entry->flag5C = 0;
            entry->state24 = 1;
            entry->unk20 = 0;
            entry->flag44 = 0;
        }
        if (shouldFree > 0) fn_80128668(entry);
    }
    return entry;
}

/* Destroys this object: installs its vtable pair, clears the active state pointer, frees
 * the owned field at +0x20, resets the embedded 3-word list at +0x40, and optionally
 * frees the object itself when arg1 > 0. */
void *fn_80283938(void *self, int shouldFree) {
    void *base;
    void *next;
    void *ownedField;
    if (self != 0) {
        base = lbl_80348678;
        next = (char *)base + 0x50;
        *(void **)self = base;
        *(void **)((char *)self + 4) = next;
        lbl_8055F69C = 0;
        ownedField = *(void **)((char *)self + 0x20);
        if (ownedField != 0) fn_80128668(ownedField);
        if ((unsigned int)self + 0x40 != 0) {
            if ((unsigned int)self + 0x40 != 0) {
                *(int *)((char *)self + 0x40) = 0;
                *(int *)((char *)self + 0x44) = 0;
                *(int *)((char *)self + 0x48) = 0;
            }
        }
        if (shouldFree > 0) fn_80128668(self);
    }
    return self;
}

#pragma cplusplus on
extern "C" int fn_802839D0(void) {
    /* If the active UI/context object is valid, invoke its vtable slots at
     * +0x24 (next) and +0x20 (get, with lbl_8055F698 as arg), then pass the
     * results to fn_8025C204(result, value). Otherwise fall back to fn_80216D28. */
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
static inline int fn_80283A50_find(void **p, unsigned int value, int count) {
    int i = 0;
    for (; i < count; ++i) {
        if (*p != (void *)value) goto increment;
        return i;
increment:
        ++p;
    }
    return -1;
}
/* Return 1 if lbl_8055F698 is present in the lbl_804B30D8 entry list, otherwise run fallback and return 0. */
int fn_80283A50(void) {
    int index;
    index = fn_80283A50_find((void **)lbl_804B30D8[0], (unsigned int)lbl_8055F698, (int)lbl_804B30D8[1]);
    if (index >= 0) return 1;
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

int fn_80283B58(void) {
    char *base = (char *)&lbl_804B2FF8;
    struct Fn80283E28List *list = (struct Fn80283E28List *)(base + 0xE0);
    int count;
    int idx;
    struct Fn80283E28Obj **items;
    struct Fn80283E28Obj **p;
    unsigned int value;
    int i;
    struct Fn80283E28Obj *obj;
    idx = 0;
    count = list->count;
    items = list->items;
    value = (unsigned int)lbl_8055F698;
    p = items;
    for (; idx < count; ++idx) {
        if ((unsigned int)*p != value) goto increment;
        goto found;
increment:
        ++p;
    }
    idx = -1;
found:
    if (idx >= 0) {
        i = idx;
        do {
            i++;
            if (i >= count) i = 0;
        } while (items[i]->sub == 0 && i != idx);
        if (i >= 0 && i < list->count && items[i]->sub != 0) {
            lbl_8055F698 = (void *)items[i];
        } else {
            lbl_8055F698 = 0;
        }
        if (i >= 0 && i < list->count && items[i]->sub != 0) {
            obj = items[i];
            if (obj != 0) {
                char *s;
                char *d;
                int c;
                int a, b;
                char tmp[0x20];
                s = obj->sub->vt->v3(obj->sub);
                d = base + 0x100;
                for (c = 0x20;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                s = obj->sub->vt->v7(obj->sub);
                d = base + 0x120;
                for (c = 0x20;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                a = obj->sub->vt->v9(obj->sub);
                b = obj->sub->vt->v8(obj->sub);
                fn_8001BE94(tmp, fn_8000DA10(), 0x20507, b, a);
                if (fn_8001BCF0(tmp) != 0) {
                    fn_8001BEE8(tmp);
                    fn_80130980(base + 0x140, 0x14, 3);
                } else {
                    s = (char *)fn_80131234((int)lbl_8034862C);
                    d = base + 0x140;
                    for (c = 0x14;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                }
                lbl_8055C7E0 = obj->sub->vt->v8(obj->sub);
            } else {
                base[0x120] = 0;
                base[0x100] = 0;
                lbl_8055C7E0 = -1;
            }
        } else {
            base[0x120] = 0;
            base[0x100] = 0;
            lbl_8055C7E0 = -1;
        }
    } else {
        fn_80216D28();
    }
    return 0;
}

int fn_80283E28(void) {
    char *base = (char *)&lbl_804B2FF8;
    int i;
    int idx;
    int count;
    unsigned int value;
    struct Fn80283E28Obj **items;
    struct Fn80283E28Obj **p;
    struct Fn80283E28Obj *obj;
    idx = 0;
    count = ((struct Fn80283E28List *)(base + 0xE0))->count;
    items = ((struct Fn80283E28List *)(base + 0xE0))->items;
    value = (unsigned int)lbl_8055F698;
    p = items;
    for (; idx < count; ++idx) {
        if ((unsigned int)*p != value) goto increment;
        goto found;
increment:
        ++p;
    }
    idx = -1;
found:
    if (idx >= 0) {
        i = idx;
        do {
            i--;
            if (i < 0) i += count;
        } while (items[i]->sub == 0 && i != idx);
        if (i >= 0 && i < ((struct Fn80283E28List *)(base + 0xE0))->count && items[i]->sub != 0) {
            lbl_8055F698 = (void *)items[i];
        } else {
            lbl_8055F698 = 0;
        }
        if (i >= 0 && i < ((struct Fn80283E28List *)(base + 0xE0))->count && items[i]->sub != 0) {
            obj = items[i];
            if (obj != 0) {
                char *s;
                char *d;
                int c;
                int a, b;
                char tmp[0x20];
                s = obj->sub->vt->v3(obj->sub);
                d = base + 0x100;
                for (c = 0x20;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                s = obj->sub->vt->v7(obj->sub);
                d = base + 0x120;
                for (c = 0x20;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                a = obj->sub->vt->v9(obj->sub);
                b = obj->sub->vt->v8(obj->sub);
                fn_8001BE94(tmp, fn_8000DA10(), 0x20507, b, a);
                if (fn_8001BCF0(tmp) != 0) {
                    fn_8001BEE8(tmp);
                    fn_80130980(base + 0x140, 0x14, 3);
                } else {
                    s = (char *)fn_80131234((int)lbl_8034862C);
                    d = base + 0x140;
                    for (c = 0x14;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                }
                lbl_8055C7E0 = obj->sub->vt->v8(obj->sub);
            } else {
                base[0x120] = 0;
                base[0x100] = 0;
                lbl_8055C7E0 = -1;
            }
        } else {
            base[0x120] = 0;
            base[0x100] = 0;
            lbl_8055C7E0 = -1;
        }
    } else {
        fn_80216D28();
    }
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
extern "C" int fn_802840FC(int *a0, void *a1, int *a2, void *a3) {
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
    struct Options { int fields[5]; } options;
    int c0;
    int c1;
    int c2;
    int c3;
    int c4;
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
    c0 = a2[0];
    c1 = a2[1];
    c2 = a2[2];
    c3 = a2[3];
    c4 = a2[4];
    options.fields[0] = c0;
    options.fields[1] = c1;
    options.fields[2] = c2;
    options.fields[3] = c3;
    options.fields[4] = c4;
    spC = -1;
    temp_r25 = (*a0 + 1) == 0;
    sp8 = -1;
    list = (List *)a1;
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
                if (*a0 == child->value()) {
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
            temp_r26 = fn_802812B4(&sp8, node2, options.fields, a1);
        }
        stateBytes = (unsigned char *)&options.fields[4];
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
        memset(options.fields, 0, 0x14);
        if (temp_r26 != 0) {
            child = node2->at(sp8);
            *a0 = child->value();
            var_r31 = 1;
            goto exit_loop;
        }
        var_r0 = 0;
    } while (fn_8027F958(&spC, a1) != 0);
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
extern "C" void fn_80284580(int oldPos, int newPos, void *srcSeq, int param) {
    // Build a playback buffer from srcSeq plus "CAR" entries crossed between oldPos/newPos, play it, then free it.
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
    int srcCount;
    if (srcSeq != 0)
        srcCount = ((Source *)srcSeq)->getCount();
    else
        srcCount = 0;
    int total = fn_80019088();
    total += srcCount;
    Buffer *dst = (Buffer *)fn_8025007C(total);
    if (srcSeq != 0) {
        int itemType;
        int i = 0;
        while (i < ((Source *)srcSeq)->getCount()) {
            dst->set(((Source *)srcSeq)->getAt(i), 1, 0);
            itemType = ((Source *)srcSeq)->getType(i);
            dst->insert(dst->getCount() - 1, itemType);
            ++i;
        }
    }
    int j = 0;
    while (j < fn_80019088()) {
        char **entry = (char **)fn_80019054(j);
        if (((int (*)(const char *, const char *))stricmp)(entry[0], (const char *)&lbl_8055C860) == 0) {
            int trigger = *(int *)((char *)entry + 8);
            if (oldPos < trigger && newPos >= trigger)
                dst->set(*(void **)((char *)entry + 4), 1, 0);
        }
        ++j;
    }
    if (dst->getCount() > 0)
        fn_8024FBD8(dst, param);
    if (dst != 0)
        dst->destroy(1);
}

extern "C" int fn_80221EA8(void);
extern "C" int fn_8023695C(char *);
extern "C" char lbl_80348940[];
extern "C" char lbl_8055C864[1];
extern "C" unsigned int lbl_8055F688;
extern "C" float lbl_80564200;
extern "C" void fn_801345D8(char *, int, const char *, ...);
extern "C" void fn_80236954(char *);
extern "C" void fn_8027F204(char *);
extern "C" void fn_80284760(void *widget) {
    /* Per-frame update of the ring menu's information fields.  The widget owns
     * an item list (+0x60); this refreshes where the ring is drawn, whether it
     * may be shown, and the three readouts next to it: the "earned/total"
     * counter (+0x74), the highlighted item's name (+0x7E) and its value
     * (+0xB0), the last two looked up by item id in the message manager
     * (fn_8027ED70).  Widget fields used here:
     *   +0x04/+0x08 ring centre x/y      +0x18 shown flag   +0x1C context id
     *   +0x20 status (0 ok, 1 no list)   +0x48/+0x4C centre passed on to the
     *   drawer, +0x50 update flag, +0x60 item list, +0x64 frozen flag,
     *   +0x68 float field, +0x6C centre x, +0x70 mode for ready(),
     *   +0x74 counter text, +0x7E name text, +0xB0 item value,
     *   +0xCC trail flag, +0xCD "show info" flag. */
    class Item { public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual int active();
    };
    class Widget { public:
        virtual void v0(); virtual void v1(); virtual int getId(); virtual void v3();
        virtual int count(); virtual Item *get(int); virtual void v6();
        virtual int ready(int); virtual int isActive();
    };
    class Lookup { public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual const char *getName(int); virtual int getValue(int);
    };
    unsigned char *p = (unsigned char *)widget;
    int temp;
    if (p[0x64] == 0) { /* not frozen: ask to be shown and refresh the context */
        p[0x18] = 1;
        *(int *)(p + 0x1c) = fn_80221EA8();
    }
    if (*(Widget **)(p + 0x60) != 0) {
        int y;
        int x;
        float zero;
        x = *(volatile int *)(p + 4);
        y = *(volatile int *)(p + 8);
        zero = *(volatile float *)&lbl_80564200; /* 0.0f */
        *(volatile int *)(p + 0x20) = 0;         /* status: fine */
        p[0x50] = 1;
        *(int *)(p + 0x48) = x;   /* hand the ring's centre on to the drawer */
        *(int *)(p + 0x4c) = y;
        *(int *)(p + 0x6c) = x;
        *(float *)(p + 0x68) = zero;
        if (*(Widget **)(p + 0x60) != 0) {
            int sel;
            /* While the list is playing a trail, (re)select the "cup_perfected"
             * one and queue its name (lbl_80348940 is that name table). */
            if ((*(Widget **)(p + 0x60))->isActive() != 0 && p[0xcc] == 0) {
                fn_80236954(lbl_80348940);
                fn_8027F204(lbl_80348940);
            }
            temp = 0;
            /* -1 while this is the widget the menu points at, 0 otherwise. */
            sel = -(widget == (void *)lbl_8055F688);
            *(int *)(p + 0x70) = sel + 7;
            if ((*(Widget **)(p + 0x60))->ready(sel) != 0) {
                if ((*(Widget **)(p + 0x60))->isActive() == 0 ||
                    fn_8023695C(lbl_80348940) != 0)
                    temp = 1;
            }
            p[0xcd] = temp; /* show the readouts? */
            if (temp != 0) {
                int active, n;
                /* "earned/total" items, e.g. "3/5". */
                n = (*(Widget **)(p + 0x60))->count();
                active = 0;
                for (temp = 0; temp < n; temp++) {
                    if ((*(Widget **)(p + 0x60))->get(temp)->active() != 0)
                        active++;
                }
                fn_801345D8((char *)(p + 0x74), 10, lbl_8055C864, active, n);
            } else {
                p[0x74] = 0;
            }
        }
        {
            const char *name;
            /* The highlighted item's name, copied into the 50 bytes at +0x7E. */
            temp = (*(Widget **)(p + 0x60))->getId();
            name = ((Lookup *)((void *(*)(void))fn_8027ED70)())->getName(temp);
            if (name != 0) {
                unsigned char ch;
                int room = 0x32;
                char *dst = (char *)(p + 0x7e);
                goto copy;
            check:
                if (--room > 0) goto copy;
                dst[-1] = 0; /* truncated: keep it terminated */
                goto done;
            copy:
                ch = *(unsigned char *)name++;
                *dst++ = ch;
                if ((char)ch != 0) goto check;
            done:;
            }
            temp = (*(Widget **)(p + 0x60))->getId();
            *(int *)(p + 0xb0) =
                ((Lookup *)((void *(*)(void))fn_8027ED70)())->getValue(temp);
        }
    } else {
        *(int *)(p + 0x20) = 1; /* status: nothing to show */
    }
}

extern "C" int fn_80019714(void);
extern "C" int fn_80214AF0(int);
extern "C" int fn_80214A9C(int);
extern "C" void fn_80214BE4(int, int, int);
extern "C" float fn_80214D48(void);
extern "C" void fn_80236958(char *);
extern "C" void *lbl_8055F694;
extern "C" char lbl_8034849C[];
extern "C" float lbl_805641FC;
extern "C" float lbl_8056420C;
extern "C" float lbl_80564210;
extern "C" float lbl_80564214;
extern "C" float lbl_80564218;
extern "C" float lbl_80564228;
extern "C" float lbl_8056422C;
extern unsigned char lbl_804B3068[];
extern "C" void fn_802849E8(void *arg0) {
    typedef void (*BE4)(int, int, int, int, int);
    class Item { public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual int active();
    };
    class Widget { public:
        virtual void v0(); virtual void v1(); virtual int getId(); virtual void v3();
        virtual int count(); virtual Item *get(int); virtual void v6();
        virtual int ready(int); virtual int isActive();
    };
    class Lookup { public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual const char *getName(int); virtual int getValue(int); virtual const char *v10();
    };
    unsigned char *p = (unsigned char *)arg0;
    Widget *w;
    int t, idx, n, active, sel, v;
    float a, shape, f4, f2, f5, f3;
    const char *name;
    unsigned char ch;
    int room;
    char *dst;
    if (p[0x64] == 0) {
        if (*(int *)(p + 0x20) != *(int *)(p + 0x24)) {
            if (*(int *)(p + 0x20) == 0)
                fn_80214AF0(*(int *)(p + 0x1c));
            else
                fn_80214A9C(*(int *)(p + 0x1c));
            *(int *)(p + 0x24) = *(int *)(p + 0x20);
        }
        if (p[0x50] != 0) {
            int x48 = *(int *)(p + 0x48);
            int x4c = *(int *)(p + 0x4c);
            *(int *)(p + 0x30) = x48;
            *(int *)(p + 0x28) = x48;
            *(int *)(p + 0x34) = x4c;
            *(int *)(p + 0x2c) = x4c;
            ((BE4)fn_80214BE4)(*(int *)(p + 0x1c), x48 - *(int *)(p + 4), x4c - *(int *)(p + 8), x4c, x48);
            p[0x50] = 0;
            *(float *)(p + 0x3c) = lbl_8056420C;
        }
        if (p[0x5c] != 0) {
            *(int *)(p + 0x28) = *(int *)(p + 4);
            *(int *)(p + 0x2c) = *(int *)(p + 8);
            *(int *)(p + 0x30) = *(int *)(p + 0x54);
            *(int *)(p + 0x34) = *(int *)(p + 0x58);
            *(float *)(p + 0x3c) = lbl_80564200;
            p[0x5c] = 0;
        }
        t = *(int *)(p + 0x40);
        a = *(float *)(p + 0x3c) + *(float *)(p + 0x38) * fn_80214D48();
        *(float *)(p + 0x3c) = a;
        switch (t) {
        case 1:
            a = (a < lbl_805641FC) ? a : lbl_805641FC;
            shape = a * a;
            break;
        case 2:
            a = (a < lbl_805641FC) ? a : lbl_805641FC;
            shape = (a < lbl_80564210) ? lbl_80564210
                  : (a > lbl_805641FC) ? lbl_805641FC
                  : (a > lbl_80564200)
                        ? a * (lbl_80564214 * a * a) + lbl_80564218 * a * a
                        : a * (lbl_80564214 * a * a) - lbl_80564218 * a * a;
            break;
        default:
            shape = (*(float *)(p + 0x3c) < lbl_805641FC) ? *(float *)(p + 0x3c) : lbl_805641FC;
            break;
        }
        f4 = (float)*(int *)(p + 0x30);
        f2 = (float)*(int *)(p + 0x28);
        f5 = (float)*(int *)(p + 0x34);
        f3 = (float)*(int *)(p + 0x2c);
        ((BE4)fn_80214BE4)(*(int *)(p + 0x1c), (int)(f2 + shape * (f4 - f2)) - *(int *)(p + 4),
                    (int)(f3 + shape * (f5 - f3)) - *(int *)(p + 8),
                    (int)f2, (int)f3);
        if (p[0x44] != 0) {
            if (*(float *)(p + 0x3c) >= lbl_805641FC) {
                p[0x44] = 0;
                *(int *)(p + 0x20) = 1;
            }
        }
    }
    w = *(Widget **)(p + 0x60);
    if (w != 0) {
        if (w->isActive() != 0 && p[0xcc] == 0) {
            fn_80236954(lbl_80348940);
            fn_8027F204(lbl_80348940);
        }
        sel = -((unsigned int)arg0 == lbl_8055F688);
        *(int *)(p + 0x70) = sel + 7;
        if (w->ready(sel) != 0 && (w->isActive() == 0 || fn_8023695C(lbl_80348940) != 0))
            p[0xcd] = 1;
        else
            p[0xcd] = 0;
        if (p[0xcd] != 0) {
            n = w->count();
            active = 0;
            for (idx = 0; idx < n; idx++)
                if (w->get(idx)->active() != 0) active++;
            fn_801345D8((char *)(p + 0x74), 10, lbl_8055C864, active, n);
        } else {
            p[0x74] = 0;
        }
        v = w->getId();
        name = ((Lookup *)((void *(*)(void))fn_8027ED70)())->getName(v);
        if (name != 0) {
            room = 0x32;
            dst = (char *)(p + 0x7e);
            for (;;) {
                ch = (unsigned char)*name++;
                *dst++ = (char)ch;
                if ((char)ch == 0) break;
                if (--room <= 0) { dst[-1] = 0; break; }
            }
        }
        v = w->getId();
        *(int *)(p + 0xb0) = ((Lookup *)((void *(*)(void))fn_8027ED70)())->getValue(v);
        if (w->ready(0) != 0) fn_80214AF0(0xb);
        else fn_80214A9C(0xb);
        if (p[0xcc] != 0) fn_80214AF0(0x15);
        else fn_80214A9C(0x15);
        p[0xcc] = (unsigned char)w->isActive();
        {
            float *f = (float *)(p + 0xb4);
            float half = fn_80214D48() / lbl_80564228;
            float mn = lbl_805641FC, mx = lbl_80564200;
            for (idx = 0; idx < w->count(); idx++) {
                float delta = w->get(idx)->active() != 0 ? half : -half;
                float val = *f + delta;
                if (val < mn) val = mn;
                if (val > mx) val = mx; else val = mx;
                *f++ = val;
            }
        }
        {
            float dt = fn_80214D48() / lbl_8056422C;
            if ((unsigned int)arg0 == lbl_8055F688) {
                float val = *(float *)(p + 0x68) + dt;
                val = (lbl_805641FC < val) ? lbl_805641FC : val;
                *(float *)(p + 0x68) = val;
            } else {
                float val = *(float *)(p + 0x68) - dt;
                val = (lbl_80564200 > val) ? lbl_80564200 : val;
                *(float *)(p + 0x68) = val;
            }
        }
        if (arg0 == lbl_8055F694) {
            char buf[0x1e];
            fn_801345D8(buf, 0x1e, lbl_8034849C, 1);
            if (fn_8023695C(buf) == 2) {
                fn_80236958(buf);
                lbl_8055F694 = 0;
                lbl_804B3068[0] = 0;
                idx = -1;
                for (n = 0; n < lbl_804B3048.count; n++)
                    if ((unsigned int)lbl_804B3048.items[n] == (unsigned int)arg0) { idx = n; break; }
                if (idx >= 0 && idx < lbl_804B3048.count) {
                    void *next = lbl_804B3048.items[idx];
                    lbl_8055F688 = (unsigned int)next;
                    if (next != 0 && *(void **)((char *)next + 0x60) != 0) {
                        const char *s = ((Lookup *)((void *(*)(void))fn_8027ED70)())->v10();
                        room = 0x64;
                        dst = (char *)lbl_804B3068;
                        for (;;) {
                            ch = (unsigned char)*s++;
                            *dst++ = (char)ch;
                            if (ch == 0) break;
                            if (--room <= 0) { dst[-1] = 0; break; }
                        }
                    }
                } else {
                    lbl_8055F688 = 0;
                }
            }
        }
    } else {
        fn_80214A9C(0xb);
        fn_80214A9C(0x15);
        fn_80214A9C(1);
    }
    idx = -1;
    for (n = 0; n < lbl_804B3048.count; n++)
        if ((unsigned int)lbl_804B3048.items[n] == (unsigned int)arg0) { idx = n; break; }
    if (idx == 0) {
        if (lbl_8055F688 != 0) {
            sel = 0;
            if (*(void **)((char *)(void *)lbl_8055F688 + 0x60) != 0 &&
                (fn_80019714() != 0 || ((Widget **)((char *)(void *)lbl_8055F688 + 0x60))[0]->ready(0) != 0))
                sel = 1;
            if (sel != 0) { fn_80214AF0(0x1f); return; }
        }
        fn_80214A9C(0x1f);
    }
}

#pragma scheduling reset
#pragma pop

#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma dont_inline on
#pragma inline_depth(0)
#pragma use_lmw_stmw off
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
    extern double cos(double), sin(double), __fabs(double);
    extern float lbl_80564228, lbl_80564230, lbl_80564234, lbl_80564238;
    extern float lbl_8056423C, lbl_80564240, lbl_805641FC;
    extern float lbl_80558DC4[];
    extern int lbl_80347EF0[], lbl_80347F10[];
    float half, step, cx, cy, radius, base, one, zero, angle, x, y;
    char *q;
    int i;
    char *p = (char *)arg0;
    if (*(List **)(p + 0x60) != 0) {
        if (*(unsigned char *)(p + 0xcd) != 0) {
            fn_80230C30(&x, &y, *(int *)(p+4), *(int *)(p+8));
            cx = x + lbl_80564228 * (float)*(int *)(p+12);
            cy = y - lbl_80564228 * (float)*(int *)(p+16);
            radius = lbl_80564230 * (float)*(int *)(p+12);
            if ((*(List **)(p+0x60))->count() == 4) step = lbl_80564234;
            else step = lbl_80564238;
            base=lbl_8056423C; one=lbl_80564240; zero=lbl_805641FC;
            for (q=p, i=0; i<(*(List **)(p+0x60))->count(); q+=4, i++) {
                angle = base + step * ((float)i - lbl_80564228 * (float)((*(List **)(p+0x60))->count()-1));
                x = cx + radius * (float)cos(angle);
                y = cy + radius * (float)sin(angle);
                if ((*(List **)(p+0x60))->get(i)->active()) {
                    if (!((float)__fabs(*(float *)(q+0xb4)-zero) <= lbl_80558DC4[0])) {
                        ((Draw *)((void *(*)(void))fn_8027ED70)())->draw(lbl_80347EF0,20,-1,x,y);
                        ((Draw *)((void *(*)(void))fn_8027ED70)())->blend(lbl_80347F10,20,-1,x,y,one-*(float *)(q+0xb4));
                    } else {
                        ((Draw *)((void *(*)(void))fn_8027ED70)())->draw(lbl_80347F10,20,-1,x,y);
                    }
                } else {
                    ((Draw *)((void *(*)(void))fn_8027ED70)())->draw(lbl_80347EF0,20,-1,x,y);
                }
            }
        } else {
            return;
        }
    }
}
#pragma cplusplus reset
#pragma pop

#pragma push
#pragma cplusplus off
#pragma dont_inline fn_8027ED70
void fn_802857A8(void *arg0) {
    extern char lbl_8055C86C;
    extern unsigned int lbl_804B30D8[];
    extern char lbl_80347E50[];
    char *base = lbl_80347E50;
    unsigned char *p = (unsigned char *)arg0;
    void *obj;
    void **vt;
    int a, b;
    int mode, i, count;
    float alpha;
    char *d;
    const char *s;
    int n;
    char ch;
    char tmp0[0x64], tmp1[0x64], tmp2[0x64], tmp3[0x64], other[0x14], *stack;
    p[0x18] = 1;
    *(int *)(p + 0x1c) = fn_80221EA8();
    obj = *(void **)(p + 0x60);
    if (obj != 0) {
        b = *(int *)(p + 8);
        a = *(int *)(p + 4);
        *(int *)(p + 0x20) = 0;
        p[0x50] = 1;
        *(int *)(p + 0x48) = a;
        *(int *)(p + 0x4c) = b;
        *(int *)(p + 0x68) = a;
        alpha = lbl_80564200;
        *(float *)(p + 0x64) = alpha;
#pragma cplusplus on
        {
            class Child {
            public:
                virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
                virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
                virtual const char *v8(); virtual int v9();
                virtual int v10(); virtual int v11();
                virtual void v12(); virtual const char *v13(); virtual int v14();
                virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18();
            };
            class Drawer {
            public:
                virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
                virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
                virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
                virtual void v12(const char *); virtual void v13(); virtual void v14(const char *);
            };
            Child *c = (Child *)obj;
            p[0x98] = (unsigned char)c->v14();
            c = (Child *)*(void **)(p + 0x60);
            p[0x99] = (unsigned char)c->v16();
            c = (Child *)*(void **)(p + 0x60);
            if (c != 0) {
                fn_801308F4((char *)(p + 0x6c), 0x1e, (const char *)c->v8());
                d = (char *)(p + 0x6c);
                n = 0x1e;
                s = lbl_8055C818;
                while (*d != 0) { --n; ++d; }
                if (n > 0) {
                    goto copy1;
                dec1:
                    --n;
                    if (n <= 0) { d[-1] = 0; goto done1; }
                    goto copy1;
                copy1:
                    ch = *s++;
                    *d++ = ch;
                    if (ch != 0) goto dec1;
                done1:;
                }
                c = (Child *)*(void **)(p + 0x60);
                fn_801308F4(other, 0x14, (const char *)c->v13());
                d = (char *)(p + 0x6c);
                n = 0x1e;
                s = other + 1;
                while (*d != 0) { --n; ++d; }
                if (n > 0) {
                    goto copy2;
                dec2:
                    --n;
                    if (n <= 0) { d[-1] = 0; goto done2; }
                    goto copy2;
                copy2:
                    ch = *s++;
                    *d++ = ch;
                    if (ch != 0) goto dec2;
                done2:;
                }
                if (p[0x98] == 0) {
                    c = (Child *)*(void **)(p + 0x60);
                    if (c->v14() != 0) {
                        ((Drawer *)fn_8027ED70())->v12(base + 0x1bc);
                        {
                            void **items = (void **)lbl_804B30D8[0];
                            count = lbl_804B30D8[1];
                            i = 0;
                            for (; i < count; ++i) {
                                if (*items != arg0) goto inc_0;
                                goto found_0;
                            inc_0:;
                                ++items;
                            }
                            i = -1;
                        found_0:;
                        }
                        fn_801345D8(tmp0, 0x64, &lbl_8055C86C, base + 0xb00, i + 1);
                        fn_80236954(tmp0);
                        fn_8027F204(tmp0);
                    }
                }
                if (p[0x99] == 0) {
                    c = (Child *)*(void **)(p + 0x60);
                    if (c->v16() != 0) {
                        ((Drawer *)fn_8027ED70())->v12(base + 0x1e0);
                        {
                            void **items = (void **)lbl_804B30D8[0];
                            count = lbl_804B30D8[1];
                            i = 0;
                            for (; i < count; ++i) {
                                if (*items != arg0) goto inc_1;
                                goto found_1;
                            inc_1:;
                                ++items;
                            }
                            i = -1;
                        found_1:;
                        }
                        fn_801345D8(tmp1, 0x64, &lbl_8055C86C, base + 0xb10, i + 1);
                        fn_80236954(tmp1);
                        fn_8027F204(tmp1);
                    }
                }
                c = (Child *)*(void **)(p + 0x60);
                if (c->v14() != 0) *(int *)(p + 0x9c) = 1;
                else *(int *)(p + 0x9c) = 0;
                c = (Child *)*(void **)(p + 0x60);
                mode = c->v9();
                if (mode >= 0 && mode < 5) {
                    stack = (char *)__AXGetStackHead();
                    if (stricmp(stack, (char *)(p + 0x8a)) != 0) {
                        if (mode == 0) {
                            ((Drawer *)fn_8027ED70())->v12(base + 0x1a0);
                            {
                                void **items = (void **)lbl_804B30D8[0];
                                count = lbl_804B30D8[1];
                                i = 0;
                                for (; i < count; ++i) {
                                    if (*items != arg0) goto inc_2;
                                    goto found_2;
                                inc_2:;
                                    ++items;
                                }
                                i = -1;
                            found_2:;
                            }
                            fn_801345D8(tmp2, 0x64, &lbl_8055C86C, base + 0xb24, i + 1);
                            fn_80236954(tmp2);
                            fn_8027F204(tmp2);
                        } else {
                            ((Drawer *)fn_8027ED70())->v12(base + 0x180);
                            {
                                void **items = (void **)lbl_804B30D8[0];
                                count = lbl_804B30D8[1];
                                i = 0;
                                for (; i < count; ++i) {
                                    if (*items != arg0) goto inc_3;
                                    goto found_3;
                                inc_3:;
                                    ++items;
                                }
                                i = -1;
                            found_3:;
                            }
                            fn_801345D8(tmp3, 0x64, &lbl_8055C86C, base + 0xb30, i + 1);
                            fn_80236954(tmp3);
                            fn_8027F204(tmp3);
                        }
                    }
                    {
                        char *dst = (char *)(p + 0x8a);
                        n = 10;
                        goto copy3;
                    dec3:
                        --n;
                        if (n <= 0) { dst[-1] = 0; goto done3; }
                        goto copy3;
                    copy3:
                        ch = *stack++;
                        *dst++ = ch;
                        if (ch != 0) goto dec3;
                    done3:;
                    }
                }
                *(int *)(p + 0x94) = (arg0 == lbl_8055F698);
            } else {
                p[0x6c] = 0;
                p[0x8a] = 0;
                *(int *)(p + 0x94) = 0;
                p[0x98] = 0;
                p[0x99] = 0;
            }
        }
#pragma cplusplus reset
    } else {
        *(int *)(p + 0x20) = 1;
    }
}

#pragma cplusplus off
extern char lbl_8055C86C;
/* Formats a message naming `name` and this entry's 1-based slot in the entry list, then posts it. */
static inline void fn_80285CB8_post(void *entry, const char *name) {
    char text[0x64];
    fn_801345D8(text, 0x64, &lbl_8055C86C, name,
                fn_80283814_find((void **)lbl_804B30D8[0], entry, lbl_804B30D8[1]) + 1);
    fn_80236954(text);
    fn_8027F204(text);
}

#pragma cplusplus off
#pragma auto_inline off
void fn_80285CB8(void *arg0) {
    extern unsigned int lbl_804B30D8[];
    extern float lbl_8056420C, lbl_80564210, lbl_80564214, lbl_80564218,
                 lbl_8056422C, lbl_80564244;
    extern int fn_80214AF0(int);
    extern int fn_80214A9C(int);
    extern float fn_80214D48(void);
    extern void fn_80214BE4(int, int, int);
    extern void fn_801308F4(char *, int, const char *);
    extern void *fn_8027ED70(void);
    extern void *__AXGetStackHead(void);
    extern int stricmp(const char *, ...);
    extern void *lbl_8055F698;
    extern char lbl_8055C818[8];
    extern char lbl_80347E50[];
    char *base = lbl_80347E50;
    unsigned char *b = (unsigned char *)arg0;
    float alpha, shape;
    float f4, f2, f5, f3, dt;
    double lim;
    int v7;
    int count;
    char *d;
    const char *s;
    char other[0x14];

    if (*(int *)(b + 0x20) != *(int *)(b + 0x24)) {
        if (*(int *)(b + 0x20) == 0)
            fn_80214AF0(*(int *)(b + 0x1C));
        else
            fn_80214A9C(*(int *)(b + 0x1C));
        *(int *)(b + 0x24) = *(int *)(b + 0x20);
    }
    if (b[0x50] != 0) {
        int x4C;
        int x48 = *(int *)(b + 0x48);
        x4C = *(int *)(b + 0x4C);
        *(int *)(b + 0x30) = x48;
        *(int *)(b + 0x28) = x48;
        *(int *)(b + 0x34) = x4C;
        *(int *)(b + 0x2C) = x4C;
        fn_80214BE4(*(int *)(b + 0x1C), x48 - *(int *)(b + 0x04),
                    x4C - *(int *)(b + 0x08));
        alpha = lbl_8056420C;
        b[0x50] = 0;
        *(float *)(b + 0x3C) = alpha;
    }
    if (b[0x5C] != 0) {
        alpha = lbl_80564200;
        *(int *)(b + 0x28) = *(int *)(b + 0x04);
        *(int *)(b + 0x2C) = *(int *)(b + 0x08);
        *(int *)(b + 0x30) = *(int *)(b + 0x54);
        *(int *)(b + 0x34) = *(int *)(b + 0x58);
        *(float *)(b + 0x3C) = alpha;
        b[0x5C] = 0;
    }
    alpha = *(float *)(b + 0x3C) + *(float *)(b + 0x38) * fn_80214D48();
    *(float *)(b + 0x3C) = alpha;
    switch (*(int *)(b + 0x40)) {
    case 1:
        alpha = (alpha < lbl_805641FC) ? alpha : lbl_805641FC;
        shape = alpha * alpha;
        break;
    case 2:
        alpha = (alpha < lbl_805641FC) ? alpha : lbl_805641FC;
        shape = (alpha < lbl_80564210) ? lbl_80564210
              : (alpha > lbl_805641FC) ? lbl_805641FC
              : (alpha > lbl_80564200)
                    ? alpha * (lbl_80564214 * alpha * alpha) + lbl_80564218 * alpha * alpha
                    : alpha * (lbl_80564214 * alpha * alpha) - lbl_80564218 * alpha * alpha;
        break;
    default:
        shape = (*(float *)(b + 0x3C) < lbl_805641FC) ? *(float *)(b + 0x3C) : lbl_805641FC;
        break;
    }
    f4 = (float)*(int *)(b + 0x30);
    f2 = (float)*(int *)(b + 0x28);
    f5 = (float)*(int *)(b + 0x34);
    f3 = (float)*(int *)(b + 0x2C);
    fn_80214BE4(*(int *)(b + 0x1C), (int)(f2 + shape * (f4 - f2)) - *(int *)(b + 0x04),
                (int)(f3 + shape * (f5 - f3)) - *(int *)(b + 0x08));
    if (b[0x44] != 0) {
        int done = *(float *)(b + 0x3C) >= lbl_805641FC;
        if (done) {
            b[0x44] = 0;
            *(int *)(b + 0x20) = 1;
        }
    }

    if (*(void **)(b + 0x60) != 0) {
#pragma cplusplus on
        class Child {
        public:
            virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
            virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
            virtual const char *text(); virtual int mode();
            virtual void v10(); virtual void v11(); virtual void v12();
            virtual const char *suffix(); virtual int flagA(); virtual int v15(); virtual int flagB();
        };
        class Drawer {
        public:
            virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
            virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
            virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
            virtual void use(const char *);
        };
        int mode;
        char *stack;
        int v28;
        if (*(void **)(b + 0x60) != 0) {
            fn_801308F4((char *)(b + 0x6C), 0x1E, (*(Child **)(b + 0x60))->text());
            d = (char *)(b + 0x6C);
            count = 0x1E;
            s = lbl_8055C818;
            while (*d != 0) { count--; d++; }
            if (count > 0) {
                while ((*d++ = *s++) != 0) {
                    if (--count <= 0) { d[-1] = 0; break; }
                }
            }
            fn_801308F4(other, 0x14, (*(Child **)(b + 0x60))->suffix());
            d = (char *)(b + 0x6C);
            count = 0x1E;
            while (*d != 0) { count--; d++; }
            if (count > 0) {
                s = other + 1;
                while ((*d++ = *s++) != 0) {
                    if (--count <= 0) { d[-1] = 0; break; }
                }
            }
            if (b[0x98] == 0 && (*(Child **)(b + 0x60))->flagA() != 0) {
                ((Drawer *)((void *(*)(void))fn_8027ED70)())->use(base + 0x1BC);
                fn_80285CB8_post(b, base + 0xB00);
            }
            if (b[0x99] == 0 && (*(Child **)(b + 0x60))->flagB() != 0) {
                ((Drawer *)((void *(*)(void))fn_8027ED70)())->use(base + 0x1E0);
                fn_80285CB8_post(b, base + 0xB10);
            }
            if ((*(Child **)(b + 0x60))->flagA() != 0) *(int *)(b + 0x9C) = 1;
            else *(int *)(b + 0x9C) = 0;
            mode = (*(Child **)(b + 0x60))->mode();
            if (mode >= 0 && mode < 5) {
                stack = (char *)__AXGetStackHead();
                if (((int (*)(const char *, const char *))stricmp)(stack, (char *)(b + 0x8A)) != 0) {
                    if (mode == 0) {
                        ((Drawer *)((void *(*)(void))fn_8027ED70)())->use(base + 0x1A0);
                        fn_80285CB8_post(b, base + 0xB24);
                    } else {
                        ((Drawer *)((void *(*)(void))fn_8027ED70)())->use(base + 0x180);
                        fn_80285CB8_post(b, base + 0xB30);
                    }
                }
                d = (char *)(b + 0x8A);
                count = 10;
                while ((*d++ = *stack++) != 0) {
                    if (--count <= 0) { d[-1] = 0; break; }
                }
            }
            *(int *)(b + 0x94) = ((void *)b == lbl_8055F698);
        } else {
            b[0x6C] = 0;
            b[0x8A] = 0;
            *(int *)(b + 0x94) = 0;
            b[0x98] = 0;
            b[0x99] = 0;
        }
        v28 = (int)(lbl_80564244 * *(float *)(b + 0x64));
        dt = fn_80214D48() / lbl_8056422C;
        dt = ((void *)b == lbl_8055F698) ? dt : -dt;
        lim = *(float *)(b + 0x64) + dt;
        lim = (lbl_805641FC < lim) ? lbl_805641FC : lim;
        lim = (lim > lbl_80564200) ? lim : lbl_80564200;
        *(int *)(b + 0x4C) = *(int *)(b + 0x08);
        b[0x50] = 1;
        *(float *)(b + 0x64) = lim;
        v7 = (int)(lbl_80564244 * (float)lim);
        *(int *)(b + 0x48) = *(int *)(b + 0x68) + v7;
        v28 = v7 - v28;
        fn_80214BE4(fn_80283814_find((void **)lbl_804B30D8[0], b, lbl_804B30D8[1]) + 0x0B, v28, 0);
        fn_80214BE4(fn_80283814_find((void **)lbl_804B30D8[0], b, lbl_804B30D8[1]) + 0x15, v28, 0);
        if (b[0x98] != 0)
            fn_80214AF0(fn_80283814_find((void **)lbl_804B30D8[0], b, lbl_804B30D8[1]) + 0x0B);
        else
            fn_80214A9C(fn_80283814_find((void **)lbl_804B30D8[0], b, lbl_804B30D8[1]) + 0x0B);
        if (b[0x99] != 0)
            fn_80214AF0(fn_80283814_find((void **)lbl_804B30D8[0], b, lbl_804B30D8[1]) + 0x15);
        else
            fn_80214A9C(fn_80283814_find((void **)lbl_804B30D8[0], b, lbl_804B30D8[1]) + 0x15);
        b[0x98] = (unsigned char)(*(Child **)(b + 0x60))->flagA();
        b[0x99] = (unsigned char)(*(Child **)(b + 0x60))->flagB();
        return;
    }
    fn_80214A9C(fn_80283814_find((void **)lbl_804B30D8[0], b, lbl_804B30D8[1]) + 0x0B);
    fn_80214A9C(fn_80283814_find((void **)lbl_804B30D8[0], b, lbl_804B30D8[1]) + 0x15);
}
#pragma auto_inline reset
#pragma cplusplus on
extern "C" int fn_80214AF0(int);
extern "C" int fn_80214A9C(int);
/* Forward virtual v1() to this title plane's sub-object (m_sub at +0x1C). */
extern "C" void fn_80286724(void* plane) {
    ((ebi::title::TPlaneObj*)plane)->m_sub->v1();
}
#pragma cplusplus on
extern "C" void fn_80286738(void* plane) {
    /* Forward virtual v2() to this title plane's sub-object (m_sub at +0x1C). */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v2();
}
#pragma cplusplus on
extern "C" void fn_8028674C(void* plane) {
    /* Forward virtual v3() to this title plane's sub-object (m_sub at +0x1C). */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v3();
}
#pragma cplusplus on
extern "C" void fn_80286760(void* plane) {
    /* Forward virtual v4() to this title plane's sub-object (m_sub at +0x1C). */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v4();
}
#pragma cplusplus on
extern "C" void fn_80286774(void* plane) {
    /* Forward v5() to the sub-object of this title plane. */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v5();
}
#pragma cplusplus on
extern "C" void fn_80286788(void* plane) {
    /* Forward v6() to the sub-object of this title plane. */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v6();
}
#pragma cplusplus on
struct Fn867B0Iface {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual int v8();
};
struct Fn87238A {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual int v14();
};
struct Fn87238B {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(char *);
};
#pragma cplusplus on
extern "C" void fn_8028679C(void *plane) {
    /* Forward v7 (vtable slot 0x24) to the title plane's sub-object (m_sub at +0x1C). */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v7();
}
#pragma cplusplus off
int fn_802867B0(void *arg0) {
    register void *p = *(void **)((char *)arg0 + 0x20);
    if (p != 0) {
        int value = (int)((float)*(int *)p + *(float *)((char *)p + 0x10));
        int limit = *(int *)((char *)p + 4);
        if (value < limit)
            return value;
        return limit;
    }
    {
    void *q = *(void **)((char *)arg0 + 0x1c);
#pragma cplusplus on
    return ((struct Fn867B0Iface *)q)->v8();
#pragma cplusplus reset
    }
}

/* Refresh this object: query its value (vtable slot 8) and apply it back (vtable slot 10). */
void fn_80286834(void *arg0) {
    void *obj = arg0;
    int value;
#pragma cplusplus on
    struct Object {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual int getValue(); virtual void v9(); virtual void applyValue(int);
    };
    value = ((struct Object *)obj)->getValue();
    ((struct Object *)obj)->applyValue(value);
#pragma cplusplus reset
}

#pragma cplusplus on
/* Forward virtual method v10 to the plane's TPlaneSub sub-object. */
extern "C" void fn_80286884(void* plane) {
    ((ebi::title::TPlaneObj*)plane)->m_sub->v10();
}
#pragma cplusplus on
extern "C" void fn_80286898(void* plane) {
    /* Forward virtual method v11 to the plane's TPlaneSub sub-object. */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v11();
}
#pragma cplusplus on
/* Forward virtual method v12 to the plane's TPlaneSub sub-object. */
extern "C" void fn_802868AC(void* plane) {
    ((ebi::title::TPlaneObj*)plane)->m_sub->v12();
}
#pragma cplusplus on
extern "C" void fn_802868C0(void* plane) {
    /* Forward virtual v13() to this title plane's sub-object (m_sub at +0x1C). */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v13();
}
#pragma cplusplus on
extern "C" int fn_802868D4(void *object) {
    /* Returns nonzero if the object's virtual method at slot 13 returns a value <= the value returned by the virtual method at slot 8. */
    class Dummy {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual int v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual int v13();
    };
    Dummy *o = (Dummy *)object;
    int value13 = o->v13();
    return value13 <= o->v8();
}
#pragma cplusplus reset
extern "C" void fn_8028693C(void* plane) {
    /* Forward the v15() virtual call to the TPlaneSub (m_sub) of the TPlaneObj. */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v15();
}
#pragma cplusplus on
/* TPlaneSub predicate: reads the class's two int-returning virtuals on the same
 * plane - v17 (vtable+0x4c) first, then v8 (vtable+0x28) - and reports whether
 * the first has come down to or below the second.  fn_802868D4 is the same test
 * with v13 (vtable+0x3c) in place of v17.
 * (Proposed name: TPlaneSub_isBelowLimit) */
extern "C" int fn_80286950(ebi::title::TPlaneSub* plane) {
    int value17 = plane->v17();
    return value17 <= plane->v8();
}
extern "C" void fn_802869B8(void* plane) {
    /* Forward virtual v17() to this title plane's sub-object (m_sub at +0x1C). */
    ((ebi::title::TPlaneObj*)plane)->m_sub->v17();
}
#pragma cplusplus off
extern float lbl_80558DC4[];
extern float fn_80214D48(void);
extern void fn_802168BC(int);
extern char lbl_8055C874[];
static inline void fn_80286A34_select(int idx);
#pragma cplusplus on
class Fn86A34Draw { public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void use(char *);
};
extern "C" int fn_80214AF0(int);
extern "C" int fn_80131234(int);
#pragma cplusplus off
/* Handles control request 13 by storing the span length of the linked object as a float. */
int fn_802869CC(void *obj, int request) {
    void *span;
    int length;
    switch (request) {
    case 13:
        span = *(void **)((char *)obj + 0x20);
        if (span != 0 && *(unsigned char *)((char *)obj + 0x29) == 0) {
            length = *(int *)((char *)span + 4) - *(int *)span;
            *(float *)((char *)span + 0x10) = (float)length;
            return 1;
        }
        break;
    }
    return 0;
}

#pragma cplusplus on
extern "C" void fn_80286A34(void *arg0) {
    char *base = (char *)lbl_804B2FF8;
    char *strs = (char *)lbl_80347E50;
    char *self = (char *)arg0;
    char *st = *(char **)(self + 0x20);
    if (st != 0) {
        if (*(unsigned char *)(self + 0x29) == 0) {
            int v = (int)((float)*(int *)st + *(float *)(st + 0x10));
            int lim = *(int *)(st + 4);
            if (v < lim) lim = v;
            if (lim == *(int *)(st + 4)) {
                *(unsigned char *)(self + 0x29) = 1;
                ((Fn86A34Draw *)((void *(*)(void))fn_8027ED70)())->use(strs + 0x164);
            }
        } else if (*(unsigned char *)(self + 0x2A) == 0) {
            int i = 0, off = 0, flag;
            for (; i < *(int *)(self + 0x44); i++, off += 0x1e) {
                if (fn_8023695C((char *)(*(int *)(self + 0x40) + off)) != 0)
                    break;
            }
            if (i < *(int *)(self + 0x44)) {
                flag = 1;
                *(float *)(self + 0x178) = lbl_805641FC;
            } else {
                float t = *(float *)(self + 0x178) - fn_80214D48();
                float m = lbl_80564200;
                if (!(m > t)) m = t;
                *(float *)(self + 0x178) = m;
                flag = ((float)m > lbl_80558DC4[0]);
            }
            if (flag == 0) {
                int idx;
                fn_80214AF0(0x1F);
                idx = *(int *)(self + 0x17C);
                if (idx >= 0)
                    fn_80286A34_select(idx);
                else
                    fn_80286A34_select(*(int *)(self + 0x24));
                *(unsigned char *)(self + 0x2A) = 1;
                if (*(unsigned char *)(self + 0x2B) != 0)
                    ((void (*)(int, int))fn_8027F288)(*(int *)(self + 0x2C), *(int *)(self + 0x30));
                if (*(unsigned char *)(self + 0x34) != 0)
                    fn_8027F09C(*(int *)(self + 0x38));
                if (*(unsigned char *)(self + 0x3C) != 0)
                    fn_802168BC(-1);
            }
        }
        if (lbl_8055F684 != 0) {
            float dt = fn_80214D48();
            char *p = *(char **)(self + 0x20);
            int lo = *(int *)(p + 4);
            int hi, i;
            int v = (int)((float)*(int *)p + *(float *)(p + 0x10));
            if (v < lo) lo = v;
            if (lo < *(int *)(p + 4)) {
                float f = *(float *)(p + 0x10) + *(float *)(p + 8) * dt;
                *(float *)(p + 0x10) = f;
                hi = *(int *)(p + 4);
                v = (int)((float)*(int *)p + (float)f);
                if (v < hi) hi = v;
                if (*(unsigned char *)(p + 0xC) != 0) {
                    for (i = 0; i < fn_80019088(); i++) {
                        int *e = (int *)fn_80019054(i);
                        char name[0x14];
                        char text[0xc8];
                        if (lo < e[2] && hi >= e[2]) {
                            if (((int (*)(char *, char *))stricmp)((char *)e[0], (char *)&lbl_8055C860) == 0) {
                                char *s = (char *)fn_80131234((int)(strs + 0xB3C));
                                char *d = name; int c;
                                for (c = 0x14;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                                s = (char *)e[1]; d = text;
                                for (c = 0xc8;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                            } else if (((int (*)(char *, char *))stricmp)((char *)e[0], lbl_8055C874) == 0) {
                                char *s = (char *)fn_80131234((int)(strs + 0xB58));
                                char *d = name; int c;
                                for (c = 0x14;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                                s = (char *)e[1]; d = text;
                                for (c = 0xc8;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
                            }
                            ((void (*)(char *, char *))fn_8027ED78)(name, text);
                        }
                    }
                }
            }
        }
    }
}
#pragma cplusplus off
extern float lbl_80558DC4[];
extern float fn_80214D48(void);
extern void fn_802168BC(int);
extern char lbl_8055C874[];
static inline void fn_80286A34_select(int idx) {
    char *base = (char *)&lbl_804B2FF8;
    struct Fn80283E28Obj **items = *(struct Fn80283E28Obj ***)(base + 0xE0);
    struct Fn80283E28Obj *obj;
    if (idx >= 0 && idx < ((struct Fn80283E28List *)(base + 0xE0))->count && items[idx]->sub != 0)
        lbl_8055F698 = (void *)items[idx];
    else
        lbl_8055F698 = 0;
    if (idx >= 0 && idx < ((struct Fn80283E28List *)(base + 0xE0))->count && items[idx]->sub != 0) {
        obj = items[idx];
        if (obj != 0) {
            char *s; char *d; int c; int a, b; char tmp[0x20];
            s = obj->sub->vt->v3(obj->sub);
            d = base + 0x100;
            for (c = 0x20;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
            s = obj->sub->vt->v7(obj->sub);
            d = base + 0x120;
            for (c = 0x20;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
            a = obj->sub->vt->v9(obj->sub);
            b = obj->sub->vt->v8(obj->sub);
            fn_8001BE94(tmp, fn_8000DA10(), 0x20507, b, a);
            if (fn_8001BCF0(tmp) != 0) {
                fn_8001BEE8(tmp);
                fn_80130980(base + 0x140, 0x14, 3);
            } else {
                s = (char *)fn_80131234((int)lbl_8034862C);
                d = base + 0x140;
                for (c = 0x14;;) { char ch = *s++; *d++ = ch; if (ch == 0) break; if (--c <= 0) { d[-1] = 0; break; } }
            }
            lbl_8055C7E0 = obj->sub->vt->v8(obj->sub);
        } else {
            base[0x120] = 0; base[0x100] = 0; lbl_8055C7E0 = -1;
        }
    } else {
        base[0x120] = 0; base[0x100] = 0; lbl_8055C7E0 = -1;
    }
}

#pragma dont_inline on
// Plays the score-up tally sound effect and initializes tally state
void fn_80287238(void *arg0) {
    extern float lbl_80564200; // 0.0f
    extern float lbl_805641FC; // 1.0f
    extern char lbl_80347FB4[]; // "scoreup_tally"
    extern int fn_80214A9C(int);
    extern void *fn_8027ED70(void);
    void *sub = *(void **)((char *)arg0 + 0x20);
    if (sub != 0) {
        *(float *)((char *)sub + 0x10) = lbl_80564200;
        *(unsigned char *)((char *)arg0 + 0x29) = 0;
        *(unsigned char *)((char *)arg0 + 0x2a) = 0;
#pragma cplusplus on
        *(unsigned char *)((char *)arg0 + 0x28) = (unsigned char)((struct Fn87238A *)arg0)->v14();
        ((struct Fn87238B *)fn_8027ED70())->v12(lbl_80347FB4);
#pragma cplusplus reset
        fn_80214A9C(0x1f);
        *(float *)((char *)arg0 + 0x178) = lbl_805641FC;
        return;
    }
    {
        float zero = lbl_80564200;
        *(unsigned char *)((char *)arg0 + 0x29) = 1;
        *(unsigned char *)((char *)arg0 + 0x2a) = 0;
        *(float *)((char *)arg0 + 0x178) = zero;
    }
}
#pragma dont_inline reset
extern float lbl_80564200;
extern float lbl_805641FC;
extern void* fn_8027ED70(void);
extern int fn_80214A9C(int);
#pragma cplusplus on
extern "C" void fn_802872DC(void* plane) {
    /* Forward to virtual method v1 of the title black plane's sub-object. */
    ((ebi::title::TBlackPlane*)plane)->m_a->v1();
}
#pragma cplusplus on
extern "C" void fn_802872F0(void* plane) {
    /* Forward to virtual method v2 of the title black plane's sub-object. */
    ((ebi::title::TBlackPlane*)plane)->m_a->v2();
}
#pragma cplusplus on
extern "C" void fn_80287304(void* plane) {
    /* Forward the virtual v3() call to the TPlaneSub member (m_a) of this TBlackPlane. */
    ((ebi::title::TBlackPlane*)plane)->m_a->v3();
}
#pragma cplusplus off
#pragma cplusplus on
extern "C" void fn_80287318(void* plane) {
    /* Forward to virtual method v4 of the title black plane's sub-object. */
    ((ebi::title::TBlackPlane*)plane)->m_a->v4();
}
#pragma cplusplus on
struct Obj8732C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void *get();
};
#pragma cplusplus on
extern "C" void *fn_8028732C(void *arg0, int arg1) {
    class Obj {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void *get();
    };
    void *cached = *(void **)((char *)arg0 + 8);
    if (cached != 0 && arg1 == *(int *)((char *)arg0 + 12)) {
        return cached;
    }
    Obj *obj = *(Obj **)((char *)arg0 + 4);
    return obj->get();
}
#pragma cplusplus off
void fn_80287360(void) {
}

#pragma cplusplus on
/* Return 1 if every item in `list` passes its virtual readiness check (vtable
 * slot 0x40), or 0 on the first item that returns 0. */
extern "C" int fn_80287364(void *list) {
    class List {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual long count();
        virtual void *item(long);
    };
    class Item {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual long isReady();
    };
    long index = 0;
    while (index < ((List *)list)->count()) {
        if (((Item *)((List *)list)->item(index))->isReady() == 0)
            return 0;
        index++;
    }
    return 1;
}
extern "C" void fn_802873F8(void* plane) {
    /* Forward virtual v7() to the title plane's sub-object (m_a at +4). */
    ((ebi::title::TBlackPlane*)plane)->m_a->v7();
}
#pragma cplusplus on
/* Returns nonzero only if every item in the list reports itself valid. */
extern "C" int fn_8028740C(void *arg0) {
    class List {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual long count();
        virtual void *item(long);
    };
    class Item {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual long valid();
    };
    long index = 0;
    while (index < ((List *)arg0)->count()) {
        if (((Item *)((List *)arg0)->item(index))->valid() == 0)
            return 0;
        index++;
    }
    return 1;
}
#pragma cplusplus reset
/* Forward v9() to the sub-object m_a of this black plane. */
extern "C" void fn_802874A0(void* plane) {
    ((ebi::title::TBlackPlane*)plane)->m_a->v9();
}
#pragma cplusplus on
extern "C" void fn_802874B4(void* plane) {
    /* Forward v10() to the sub-object m_a of this black plane. */
    ((ebi::title::TBlackPlane*)plane)->m_a->v10();
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