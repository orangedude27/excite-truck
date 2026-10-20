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
 volatile int sp6c,sp68,sp64,sp60,sp5c;
 volatile int sp58=13,sp54=-2,sp50=0,sp4c=6;
 int * volatile sp48=&lbl_8055B860;
 volatile int sp44=0,sp40=0,sp3c=arg1,sp38=3;
 int * volatile sp34=&lbl_803480A8;
 volatile int sp30=0,sp2c=0,sp28=arg0,sp24=3;
 int * volatile sp20=&lbl_8055C7C8;
 volatile int sp18,sp14,sp10,sp0c,sp08;
 sp5c=((int*)&lbl_804B2FF8)[0]; sp60=((int*)&lbl_804B2FF8)[1]; sp64=((int*)&lbl_804B2FF8)[2]; sp68=((int*)&lbl_804B2FF8)[3]; sp6c=((int*)&lbl_804B2FF8)[4];
 sp08=lbl_802FA848; sp10=((int*)&lbl_802FA848)[2]; sp14=((int*)&lbl_802FA848)[3]; sp18=((int*)&lbl_802FA848)[4];
 fn_802146BC((int*)&sp08,-999,-999,1,sp18,sp14,sp10,sp08);
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
extern "C" void fn_8027F204(char *src) {
    char *dst;
    int len;
    struct Fn8027F204State *state = (struct Fn8027F204State *)lbl_8055F69C;

    if (state == 0) return;
    if (state->count + 1 <= state->max) {
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
#pragma scheduling invalid_target
#pragma scheduling reset
#pragma cplusplus off
void *fn_8027F834(void *arg0, int arg1) {
    int temp_r0, var_ctr, var_r7;
    unsigned int *var_r6;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80348798;
        if (lbl_8055F688 == (unsigned int)arg0) lbl_8055F688 = 0;
        var_r6 = (unsigned int *)lbl_804B3048.items;
        var_r7 = 0;
        var_ctr = lbl_804B3048.count;
        if (lbl_804B3048.count > 0) {
loop_4:
            if (*var_r6 == (unsigned int)arg0) {
            } else {
                var_r6 += 4;
                var_r7 += 1;
                var_ctr -= 1;
                if (var_ctr == 0) goto block_7;
                goto loop_4;
            }
        } else {
block_7:
            var_r7 = -1;
        }
        if (var_r7 != -1 && var_r7 >= 0 && var_r7 < lbl_804B3048.count) {
            temp_r0 = lbl_804B3048.count - 1;
            if (var_r7 != temp_r0)
                ((unsigned int *)lbl_804B3048.items)[var_r7] = ((unsigned int *)lbl_804B3048.items)[temp_r0];
            lbl_804B3048.count = lbl_804B3048.count - 1;
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
#pragma inline_max_size(10000)
#pragma inline_max_total_size(10000)
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
    Fn8027F958Widget widgets[5];
    Fn8027F958Menu menu;
    int textIds[3][3];
    struct Fn8027F834List *list;
    void *object, *item;
    Fn8027F958Widget *widget;
    void **items, **storage;
    char *constants = (char *)&lbl_802FA848;
    char *state = (char *)&lbl_804B2FF8;
    char *strings = lbl_80347E50;
    float defaultScale;
    float defaultValue;
    void *widgetVtable;
    char *src, *dst;
    int mode, count, reported, i, j, index, remaining, result;
    float *value;
    list = (struct Fn8027F834List *)(state + 0x50);
    object = ((GetItem)(*(void ***)collection)[4])(collection, 0);
    mode = ((GetInt)(*(void ***)object)[5])(object);
    defaultScale = lbl_805641F8;
    defaultValue = lbl_805641FC;
    widgetVtable = lbl_80348798;
    index = list->count;
    storage = list->items;
    widgets[0].unk14 = 0;
    widgets[0].unk38 = defaultScale;
    widgets[0].unk40 = 2;
    widgets[0].unk3C = defaultValue;
    widgets[0].unk18 = 0;
    widgets[0].unk50 = 0;
    widgets[0].unk5C = 0;
    widgets[0].unk24 = 2;
    widgets[0].unk20 = 0;
    widgets[0].unk44 = 0;
    widgets[0].vtable = widgetVtable;
    widgets[0].object = 0;
    widgets[0].unk64 = 0;
    widgets[0].unk70 = 0;
    widgets[0].unk74 = 0;
    list->count = index + 1;
    storage[index] = &widgets[0];
    widgets[0].unk7E = 0;
    widgets[0].unkB0 = 0;
    index = list->count;
    storage = list->items;
    widgets[1].unk14 = 0;
    widgets[1].unk38 = defaultScale;
    widgets[1].unk40 = 2;
    widgets[1].unk3C = defaultValue;
    widgets[1].unk18 = 0;
    widgets[1].unk50 = 0;
    widgets[1].unk5C = 0;
    widgets[1].unk24 = 2;
    widgets[1].unk20 = 0;
    widgets[1].unk44 = 0;
    widgets[1].vtable = widgetVtable;
    widgets[1].object = 0;
    widgets[1].unk64 = 0;
    widgets[1].unk70 = 0;
    widgets[1].unk74 = 0;
    list->count = index + 1;
    storage[index] = &widgets[1];
    widgets[1].unk7E = 0;
    widgets[1].unkB0 = 0;
    index = list->count;
    storage = list->items;
    widgets[2].unk14 = 0;
    widgets[2].unk38 = defaultScale;
    widgets[2].unk40 = 2;
    widgets[2].unk3C = defaultValue;
    widgets[2].unk18 = 0;
    widgets[2].unk50 = 0;
    widgets[2].unk5C = 0;
    widgets[2].unk24 = 2;
    widgets[2].unk20 = 0;
    widgets[2].unk44 = 0;
    widgets[2].vtable = widgetVtable;
    widgets[2].object = 0;
    widgets[2].unk64 = 0;
    widgets[2].unk70 = 0;
    widgets[2].unk74 = 0;
    list->count = index + 1;
    storage[index] = &widgets[2];
    widgets[2].unk7E = 0;
    widgets[2].unkB0 = 0;
    index = list->count;
    storage = list->items;
    widgets[3].unk14 = 0;
    widgets[3].unk38 = defaultScale;
    widgets[3].unk40 = 2;
    widgets[3].unk3C = defaultValue;
    widgets[3].unk18 = 0;
    widgets[3].unk50 = 0;
    widgets[3].unk5C = 0;
    widgets[3].unk24 = 2;
    widgets[3].unk20 = 0;
    widgets[3].unk44 = 0;
    widgets[3].vtable = widgetVtable;
    widgets[3].object = 0;
    widgets[3].unk64 = 0;
    widgets[3].unk70 = 0;
    widgets[3].unk74 = 0;
    list->count = index + 1;
    storage[index] = &widgets[3];
    widgets[3].unk7E = 0;
    widgets[3].unkB0 = 0;
    index = list->count;
    storage = list->items;
    widgets[4].unk14 = 0;
    widgets[4].unk38 = defaultScale;
    widgets[4].unk40 = 2;
    widgets[4].unk3C = defaultValue;
    widgets[4].unk18 = 0;
    widgets[4].unk50 = 0;
    widgets[4].unk5C = 0;
    widgets[4].unk24 = 2;
    widgets[4].unk20 = 0;
    widgets[4].unk44 = 0;
    widgets[4].vtable = widgetVtable;
    widgets[4].object = 0;
    widgets[4].unk64 = 0;
    widgets[4].unk70 = 0;
    widgets[4].unk74 = 0;
    list->count = index + 1;
    storage[index] = &widgets[4];
    widgets[4].unk7E = 0;
    widgets[4].unkB0 = 0;
    reported = ((GetInt)(*(void ***)collection)[3])(collection);
    count = 5;
    if (reported < 5) count = reported;
    widget = widgets;
    for (i = 0; i < count; ++i, ++widget) {
        widget->object = ((GetItem)(*(void ***)collection)[4])(collection, i);
        widget->unk64 = 0;
        value = widget->values;
        for (j = 0; j < ((GetInt)(*(void ***)widget->object)[6])(widget->object); ++j) {
            item = ((GetItem)(*(void ***)widget->object)[7])(widget->object, j);
            *value++ = ((GetInt)(*(void ***)item)[16])(item) ? lbl_805641FC : lbl_80564200;
        }
        widget->unkCC = ((GetByte)(*(void ***)widget->object)[10])(widget->object);
    }
    menu.entries[0].value = (void *)(&fn_80281138);
    menu.entries[1].label = (void *)(strings + 0x518);
    menu.entries[0].type = (int)(8);
    menu.entries[0].label = (void *)(&lbl_8055BAC0);
    menu.entries[0].flags = (int)(0);
    menu.entries[0].id = (int)(0);
    menu.entries[1].type = (int)(3);
    menu.entries[1].value = (void *)(state + 0x70);
    menu.entries[1].flags = (int)(0);
    menu.entries[1].id = (int)(0);
    menu.entries[2].type = (int)(5);
    menu.entries[2].label = (void *)(&lbl_8055C7F0);
    menu.entries[2].value = (void *)(&widgets[0].vtable);
    menu.entries[2].flags = (int)(0);
    menu.entries[2].id = (int)(0);
    menu.entries[3].type = (int)(2);
    menu.entries[3].label = (void *)(strings + 0x524);
    menu.entries[3].value = (void *)(&widgets[0].unk70);
    menu.entries[3].flags = (int)(0);
    menu.entries[3].id = (int)(0);
    object = widgets[0].object;
    menu.entries[4].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    menu.entries[4].label = (void *)(strings + 0x530);
    menu.entries[4].type = (int)(3);
    menu.entries[4].flags = (int)(0);
    menu.entries[4].id = (int)(0);
    menu.entries[5].type = (int)(3);
    menu.entries[5].label = (void *)(strings + 0x53C);
    menu.entries[5].value = (void *)(&widgets[0].unk74);
    menu.entries[5].flags = (int)(0);
    menu.entries[5].id = (int)(0);
    menu.entries[6].type = (int)(5);
    menu.entries[6].label = (void *)(&lbl_8055C7F8);
    menu.entries[6].value = (void *)(&widgets[1].vtable);
    menu.entries[6].flags = (int)(0);
    menu.entries[6].id = (int)(0);
    menu.entries[7].type = (int)(2);
    menu.entries[7].label = (void *)(strings + 0x550);
    menu.entries[7].value = (void *)(&widgets[1].unk70);
    menu.entries[7].flags = (int)(0);
    menu.entries[7].id = (int)(0);
    object = widgets[1].object;
    menu.entries[8].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    menu.entries[8].label = (void *)(strings + 0x55C);
    menu.entries[8].type = (int)(3);
    menu.entries[8].flags = (int)(0);
    menu.entries[8].id = (int)(0);
    menu.entries[9].type = (int)(3);
    menu.entries[9].label = (void *)(strings + 0x568);
    menu.entries[9].value = (void *)(&widgets[1].unk74);
    menu.entries[9].flags = (int)(0);
    menu.entries[9].id = (int)(0);
    menu.entries[10].type = (int)(5);
    menu.entries[10].label = (void *)(&lbl_8055C800);
    menu.entries[10].value = (void *)(&widgets[2].vtable);
    menu.entries[10].flags = (int)(0);
    menu.entries[10].id = (int)(0);
    menu.entries[11].type = (int)(2);
    menu.entries[11].label = (void *)(strings + 0x57C);
    menu.entries[11].value = (void *)(&widgets[2].unk70);
    menu.entries[11].flags = (int)(0);
    menu.entries[11].id = (int)(0);
    object = widgets[2].object;
    menu.entries[12].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    menu.entries[12].label = (void *)(strings + 0x588);
    menu.entries[12].type = (int)(3);
    menu.entries[12].flags = (int)(0);
    menu.entries[12].id = (int)(0);
    menu.entries[13].type = (int)(3);
    menu.entries[13].label = (void *)(strings + 0x594);
    menu.entries[13].value = (void *)(&widgets[2].unk74);
    menu.entries[13].flags = (int)(0);
    menu.entries[13].id = (int)(0);
    menu.entries[14].type = (int)(5);
    menu.entries[14].label = (void *)(&lbl_8055C808);
    menu.entries[14].value = (void *)(&widgets[3].vtable);
    menu.entries[14].flags = (int)(0);
    menu.entries[14].id = (int)(0);
    menu.entries[15].type = (int)(2);
    menu.entries[15].label = (void *)(strings + 0x5A8);
    menu.entries[15].value = (void *)(&widgets[3].unk70);
    menu.entries[15].flags = (int)(0);
    menu.entries[15].id = (int)(0);
    object = widgets[3].object;
    menu.entries[16].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    menu.entries[16].label = (void *)(strings + 0x5B4);
    menu.entries[16].type = (int)(3);
    menu.entries[16].flags = (int)(0);
    menu.entries[16].id = (int)(0);
    menu.entries[17].type = (int)(3);
    menu.entries[17].label = (void *)(strings + 0x5C0);
    menu.entries[17].value = (void *)(&widgets[3].unk74);
    menu.entries[17].flags = (int)(0);
    menu.entries[17].id = (int)(0);
    menu.entries[18].type = (int)(5);
    menu.entries[18].label = (void *)(&lbl_8055C810);
    menu.entries[18].value = (void *)(&widgets[4].vtable);
    menu.entries[18].flags = (int)(0);
    menu.entries[18].id = (int)(0);
    menu.entries[19].type = (int)(2);
    menu.entries[19].label = (void *)(strings + 0x5D4);
    menu.entries[19].value = (void *)(&widgets[4].unk70);
    menu.entries[19].flags = (int)(0);
    menu.entries[19].id = (int)(0);
    textIds[0][0] = *(int *)(constants + 0x2c);
    textIds[0][1] = *(int *)(constants + 0x30);
    textIds[0][2] = *(int *)(constants + 0x34);
    textIds[1][0] = *(int *)(constants + 0x38);
    textIds[1][1] = *(int *)(constants + 0x3c);
    textIds[1][2] = *(int *)(constants + 0x40);
    textIds[2][0] = *(int *)(constants + 0x44);
    textIds[2][1] = *(int *)(constants + 0x48);
    textIds[2][2] = *(int *)(constants + 0x4c);
    menu.entries[20].type = (int)(3);
    menu.entries[20].label = (void *)(strings + 0x5E0);
    object = widgets[4].object;
    menu.entries[20].value = object != 0 ? ((GetString)(*(void ***)object)[3])(object) : (char *)&lbl_8055C7EC;
    menu.entries[20].flags = (int)(0);
    menu.entries[20].id = (int)(0);
    menu.entries[21].type = (int)(3);
    menu.entries[21].label = (void *)(strings + 0x5EC);
    menu.entries[21].value = (void *)(&widgets[4].unk74);
    menu.entries[21].flags = (int)(0);
    menu.entries[21].id = (int)(0);
    menu.entries[22].type = (int)(3);
    menu.entries[22].label = (void *)(strings + 0x600);
    menu.entries[22].value = (void *)(textIds[2][mode]);
    menu.entries[22].flags = (int)(0);
    menu.entries[22].id = (int)(0);
    menu.entries[23].type = (int)(3);
    menu.entries[23].label = (void *)(strings + 0x610);
    menu.entries[23].value = (void *)(textIds[1][mode]);
    menu.entries[23].flags = (int)(0);
    menu.entries[23].id = (int)(0);
    menu.entries[24].value = (void *)(fn_80131234(textIds[0][mode]));
    menu.entries[24].label = (void *)(strings + 0x620);
    menu.entries[27].value = (void *)(&fn_80280C00);
    menu.entries[24].type = (int)(3);
    menu.entries[25].label = (void *)(&lbl_8055B860);
    menu.entries[26].value = (void *)(&fn_80280DC8);
    menu.entries[25].id = (int)(0x125);
    menu.entries[25].value = (void *)(&fn_80280F7C);
    menu.entries[31].flags = (int)(2);
    menu.entries[26].label = (void *)(&lbl_8055B860);
    menu.entries[27].label = (void *)(&lbl_8055B860);
    menu.entries[28].label = (void *)(&lbl_8055B860);
    menu.entries[29].label = (void *)(&lbl_8055B860);
    menu.entries[30].label = (void *)(&lbl_8055B860);
    menu.entries[29].value = (void *)(&fn_802808D0);
    menu.entries[28].value = (void *)(&fn_80280A38);
    menu.entries[24].flags = (int)(0);
    menu.entries[24].id = (int)(0);
    menu.entries[25].type = (int)(6);
    menu.entries[25].flags = (int)(0);
    menu.entries[26].type = (int)(6);
    menu.entries[26].flags = (int)(0);
    menu.entries[26].id = (int)(0x127);
    menu.entries[27].type = (int)(6);
    menu.entries[27].flags = (int)(0);
    menu.entries[27].id = (int)(0x128);
    menu.entries[28].type = (int)(6);
    menu.entries[28].flags = (int)(0);
    menu.entries[28].id = (int)(0x126);
    menu.entries[29].type = (int)(6);
    menu.entries[29].flags = (int)(-2);
    menu.entries[29].id = (int)(0xD);
    menu.entries[30].type = (int)(6);
    menu.entries[30].value = (void *)(&fn_80280898);
    menu.entries[30].flags = (int)(-1);
    menu.entries[30].id = (int)(0x1B);
    menu.entries[31].type = (int)(8);
    menu.entries[31].label = (void *)(&lbl_8055BAB8);
    menu.entries[31].value = (void *)(&fn_8027EE74);
    menu.entries[31].id = (int)(0);
    menu.header[0] = *(int *)(constants + 0x108);
    menu.footer[0] = ((int *)&lbl_804B2FF8)[0];
    menu.header[1] = *(int *)(constants + 0x10c);
    menu.footer[1] = ((int *)&lbl_804B2FF8)[1];
    menu.header[2] = *(int *)(constants + 0x110);
    menu.footer[2] = ((int *)&lbl_804B2FF8)[2];
    menu.header[3] = *(int *)(constants + 0x114);
    menu.footer[3] = ((int *)&lbl_804B2FF8)[3];
    menu.header[4] = *(int *)(constants + 0x118);
    menu.footer[4] = ((int *)&lbl_804B2FF8)[4];
    menu.header[1] = (int)menu.entries;
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
            lbl_8055F694 = &widgets[*selection];
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
    result = (((int (*)(int *, int, int, int))fn_802146BC)(menu.header, -999, -999, 1) + 2) == 0;
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
    widget = &widgets[4];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    index = 0;
    remaining = list->count;
    while (remaining > 0) {
        if (*items == widget) break;
        ++items;
        ++index;
        --remaining;
    }
    if (remaining <= 0) index = -1;
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
    widget = &widgets[3];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    index = 0;
    remaining = list->count;
    while (remaining > 0) {
        if (*items == widget) break;
        ++items;
        ++index;
        --remaining;
    }
    if (remaining <= 0) index = -1;
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
    widget = &widgets[2];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    index = 0;
    remaining = list->count;
    while (remaining > 0) {
        if (*items == widget) break;
        ++items;
        ++index;
        --remaining;
    }
    if (remaining <= 0) index = -1;
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
    widget = &widgets[1];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    index = 0;
    remaining = list->count;
    while (remaining > 0) {
        if (*items == widget) break;
        ++items;
        ++index;
        --remaining;
    }
    if (remaining <= 0) index = -1;
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
    widget = &widgets[0];
    widget->vtable = widgetVtable;
    if (lbl_8055F688 == (unsigned int)widget) lbl_8055F688 = 0;
    items = list->items;
    index = 0;
    remaining = list->count;
    while (remaining > 0) {
        if (*items == widget) break;
        ++items;
        ++index;
        --remaining;
    }
    if (remaining <= 0) index = -1;
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
#pragma pop

extern int fn_80216D28(void);
int fn_80280898(void) { extern unsigned int lbl_8055F688; if (lbl_8055F688 == 0) { fn_80216D28(); return 0; } return 1; }

extern unsigned char lbl_804B3068[];
typedef unsigned int (*GetKeyFn)(void *);
typedef char *(*GetTextFn)(void *);
int fn_80280DC8(void) {
    int index = 0;
    int count;
    unsigned int *items;
    unsigned int key;
    unsigned int result;
    unsigned int *entry;
    void *obj;
    void **vt;
    char *text;
    char *dst;
    int n;
    if (lbl_8055F688 == 0) {
        fn_80216D28();
        return 0;
    }
    key = lbl_8055F688;
    items = (unsigned int *)lbl_804B3048.items;
    count = lbl_804B3048.count;
    while (index < count && items[index] != key)
        index++;
    if (index >= count)
        index = -1;
    entry = (unsigned int *)lbl_804B3048.items;
    obj = *(void **)((char *)entry[index] + 0x60);
    if (obj == 0)
        return 0;
    vt = *(void ***)obj;
    result = ((GetKeyFn)vt[11])(obj);
    index++;
    while (index < lbl_804B3048.count) {
        entry = (unsigned int *)lbl_804B3048.items;
        obj = *(void **)((char *)entry[index] + 0x60);
        if (obj != 0) {
            vt = *(void ***)obj;
            if (result == ((GetKeyFn)vt[11])(obj))
                break;
        }
        index++;
    }
    count = lbl_804B3048.count;
    if (index < count && index >= 0) {
        lbl_804B3068[0] = 0;
        if (index >= 0 && index < count) {
            entry = (unsigned int *)lbl_804B3048.items;
            lbl_8055F688 = entry[index];
            if (lbl_8055F688 == 0) return 0;
            obj = *(void **)((char *)lbl_8055F688 + 0x60);
            if (obj == 0) return 0;
            vt = *(void ***)obj;
            text = ((GetTextFn)vt[12])(obj);
            dst = (char *)&lbl_804B3068;
            for (n = 100; n > 0; n--) {
                char c = *text++;
                *dst++ = c;
                if (c == 0) break;
            }
            if (n == 0) dst[-1] = 0;
        } else {
            lbl_8055F688 = 0;
        }
    }
    return 0;
}

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
        *(void **)arg0 = base;
        next = (char *)base + 0x50;
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
    int i = 0, count = (int)lbl_804B30D8[1];
    unsigned int *p = (unsigned int *)lbl_804B30D8[0];
    unsigned int value = (unsigned int)lbl_8055F698;
    for (; count > 0; --count) {
        if (*p == value) return 1;
        p += 4; ++i;
    }
    fn_80216D28();
    return 0;
}

int fn_80283AC8(void) {
 int i=0;
 int count=(int)lbl_804B30D8[1];
 unsigned int *p=(unsigned int*)lbl_804B30D8[0];
 unsigned int value=(unsigned int)lbl_8055F698;
 if (count > 0) {
   do {
     if (*p == value) goto found;
     p++;
     ++i;
   } while (--count != 0);
 }
 i=-1;
found:
 if (i >= 0 && *(int *)((char *)lbl_804B30D8[0] + i * 16 + 0x60)) return 1;
 fn_80216D28();
 return 0;
}

void fn_802840F4(void) {
    fn_8027E908();
}

void fn_802840F8(void) {
    fn_8027ED2C();
}

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
    extern int fn_80221EA8(void); extern void fn_801308F4(char *, int, const char *); extern void *fn_8027ED70(void); extern void *__AXGetStackHead(void); extern int stricmp(const char *);
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
#pragma cplusplus off
void fn_80286760(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    (*(void (**)(void*))(*(void***)obj + 6))(obj);
}

void fn_80286774(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    (*(void (**)(void*))(*(void***)obj + 7))(obj);
}

void fn_80286788(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    ((void (**)(void*))(*(void***)obj))[8](obj);
}

void fn_8028679C(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1c);
    void **vtable = *(void ***)obj;
    void (*fn)(void) = (void (*)(void))vtable[9];
    fn();
}

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

void fn_80286884(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    ((void (*)(void*))(*(void**)((char*)obj + 0)))(obj);
}

void fn_80286898(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    (*(void (**)(void*))((char*)*(void**)obj + 0x34))(obj);
}

void fn_802868AC(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    struct VTable { void* pad[14]; };
    ((void (*)(void*))((struct VTable*)*(void**)obj)->pad[14])(obj);
}

void fn_802868C0(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    (*(void (**)(void))((char *)*(void **)obj + 0x3C))();
}

int fn_802868D4(void *arg0) {
    int a = ((int (*)(void *))(*(void ***)arg0)[15])(arg0);
    int b = ((int (*)(void *))(*(void ***)arg0)[10])(arg0);
    return b >= a;
}

void fn_8028693C(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    void **vtable = *(void ***)obj;
    void *slot = vtable[17];
    ((void (*)(void))slot)();
}

typedef unsigned int (*GetFn)(void *);
typedef int (*CmpFn)(void *);
int fn_80286950(void **arg0) {
    unsigned int a;
    GetFn get;
    CmpFn cmp;
    get = *(GetFn *)((char *)*arg0 + 0x4C);
    a = get(arg0);
    cmp = *(CmpFn *)((char *)*arg0 + 0x28);
    return (int)a <= cmp(arg0);
}

void fn_802869B8(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    volatile void * volatile *vtable = (volatile void * volatile *)*(void ***)obj;
    ((void (*)(void *))vtable[19])(obj);
}

int fn_802869CC(void *arg0, int arg1) {
    extern double lbl_80564220;
    void *p;
    int d;
    if (arg1 == 13) {
        p = *(void **)((char *)arg0 + 0x20);
        if (p != 0 && *(unsigned char *)((char *)arg0 + 0x29) == 0) {
            d = *(int *)((char *)p + 4) - *(int *)p;
            *(float *)((char *)p + 0x10) = (float)((double)d - lbl_80564220);
            return 1;
        }
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

void fn_802874A0(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    register void** vtable = *(void***)obj;
    register void (*fn)(void*) = (void (*)(void*))vtable[11];
    fn(obj);
}

void fn_802874B4(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    void* (*vtable)[13] = (void* (*)[13])*(void***)obj;
    ((void (*)(void*))(*vtable)[12])(obj);
}
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
