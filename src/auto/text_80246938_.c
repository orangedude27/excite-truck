typedef signed long s32;
extern s32 fn_802E4A10(void);
extern void fn_802146BC(void *, s32, s32, s32);
extern s32 fn_80131234(s32 *);
extern s32 lbl_802FA378[5];
extern s32 lbl_804988F0[5];
extern char lbl_80343720[];
extern char lbl_80343280[];
extern char lbl_80343294[];
extern char lbl_8055BE80;
extern char lbl_8055BE88;
extern s32 lbl_8055F26C;
s32 fn_802411D4(void);
s32 fn_80214B44(s32);
s32 fn_80214B94(s32);
typedef s32 (*UnkFunc)(s32);
extern float lbl_80563898;
extern float lbl_805638A8;
extern double lbl_805638A0;
void fn_80246CAC(float);
void fn_80127464(void);
void fn_802E2D74(s32);
void fn_8020A5F8(float);
void fn_8020A634(void);
s32 fn_802E2C20(void);
void fn_80214AF0(s32);
void fn_80214A9C(s32);
extern char lbl_80343600[16];
/* Menu widget for a "cup" tile: two art models, a track image and a text label. */
typedef struct Obj_802470D4 {
    void *vtable;
    char pad[0x14];
    s32 field18;   /* "tile_cup_s.art" model (refcounted) */
    s32 field1C;   /* "tile_cup.art" model (refcounted) */
    s32 field20;   /* "e3_trks.img" image */
    char pad24[0xC];
    s32 *field30;  /* text label object (uifnt_o.gtx font); [0] = string resource */
} Obj_802470D4;
void fn_80235380(s32);
void fn_802C519C(s32);
void fn_802328D4(s32);
void fn_80128668(void *);
s32 fn_802E499C(unsigned short *, unsigned short, unsigned short, unsigned short, unsigned short);
void fn_8020C918(s32);
extern unsigned short lbl_802FA48C[6];
extern float lbl_805638B0;
s32 fn_80221EA8(void);
extern s32 lbl_8055BEF0;
extern void *lbl_8055F278;
extern void fn_80214CB4(s32);
extern s32 lbl_802FA3B4[];
extern void* lbl_8055BEAC;

typedef struct lbl_8055F278_struct {
    char pad00[0x04];
    s32 unk04;
    s32 unk08;
    char pad0C[0x38];
    unsigned char unk44;
    char pad45[0x03];
    s32 unk48;
    s32 unk4C;
    unsigned char unk50;
    char pad51[0x03];
    s32 unk54;
    s32 unk58;
    unsigned char unk5C;
} lbl_8055F278_struct;
extern float lbl_805638B0;
#pragma push
#pragma small_data off
extern float lbl_805638C8;
#pragma pop
float fn_80214D48(void);
unsigned char fn_802E8690(s32);
void fn_80221F94(void *, s32);
#pragma push
#pragma small_data off
extern float lbl_805638CC;
#pragma pop
extern float lbl_80558DC4[];


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F260;
extern unsigned char lbl_803432EC[];
extern void fn_80246CB8(void *);
extern char lbl_80343780[];
extern float lbl_8055F264;
extern unsigned char lbl_8055F268;
extern char lbl_8034333C[];
extern char lbl_80343348[];
extern char lbl_8034397C[];
extern char lbl_8055BE98;
extern float fn_8020A5F0(void);
extern void fn_8023D704(s32);
extern void fn_80129AFC(void);
extern void fn_802E47E8(void);
extern void fn_8023D7CC(void);
extern s32 fn_80246E4C(void);
extern s32 fn_80278A1C(const char *);
extern s32 fn_80012818(void);
extern void *fn_80012820(s32);
extern void fn_8020C91C(s32);
extern void fn_8023BFBC(s32, s32);
extern void fn_802483E0(void);
extern void fn_80248668(s32);
extern void fn_802E317C(const char *, ...);
#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 4
#pragma scheduling invalid_target
s32 fn_80246938(void) {
    s32 index;
    struct {
        volatile s32 args[5];
        s32 text;
        s32 pad0[4];
        s32 zero;
        s32 itemIndex;
        s32 pad1[2];
        s32 values[20];
    } frame;

    index = fn_802E4A10();
    if (index >= 0 && index < 4) {
        fn_80214A9C(0x1F);
        while (((s32 (*)(s32))fn_802E8690)(index) != 0) {
            frame.zero = 0;
            frame.text = (s32)lbl_80343720;
            frame.itemIndex = index;
            frame.values[0] = 0;
            frame.values[1] = 5;
            frame.values[2] = (s32)&frame.text;
            frame.values[3] = 0;
            frame.values[4] = 0;
            frame.values[7] = fn_80131234((s32 *)lbl_80343280);
            frame.values[6] = 3;
            frame.values[5] = (s32)&lbl_8055BE80;
            frame.values[8] = 0;
            frame.values[9] = 0;
            frame.values[12] = fn_80131234((s32 *)lbl_80343294);
            frame.values[11] = 3;
            frame.values[10] = (s32)&lbl_8055BE88;
            frame.values[13] = 0;
            frame.values[14] = 0;
            frame.values[15] = lbl_804988F0[0];
            frame.values[16] = lbl_804988F0[1];
            frame.values[17] = lbl_804988F0[2];
            frame.values[18] = lbl_804988F0[3];
            frame.values[19] = lbl_804988F0[4];
            frame.args[0] = lbl_802FA378[0];
            frame.args[1] = lbl_802FA378[1];
            frame.args[2] = lbl_802FA378[2];
            frame.args[3] = lbl_802FA378[3];
            frame.args[4] = lbl_802FA378[4];
            frame.args[1] = (s32)&frame.values[0];
            fn_802146BC((s32 *)frame.args, -0x3E7, -0x3E7, 1);
        }
        fn_80214AF0(0x1F);
    }
    return 1;
}
#pragma pop

int fn_80246AA8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

void *__dt__Q28PSSystem7SeqHeapFv_80246C48(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80343780;
        ((void (*)(s32, void *))fn_80235380)(*(s32 *)((char *)arg0 + 0x18), lbl_80343780);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
void fn_80246CAC(float farg0) {
    fn_8020A5F8(farg0 * lbl_8055F264);
}
#pragma dont_inline reset

extern char lbl_803436C0[];
extern void fn_80216CA8(void);
extern void fn_802146BC(void *, s32, s32, s32);
#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 3
void fn_80246CB8(void *arg0) {
    s32 text[12];
    s32 item[10];
    s32 menu[6];
    s32 taddr = (s32)text;
    s32 a = (s32)arg0;
    text[5] = 0;
    text[0] = (s32)lbl_803436C0;
    text[8] = 2500;
    text[9] = 1;
    text[10] = 0;
    text[7] = fn_802E2C20();
    text[6] = 1;
    item[1] = 5;
    item[0] = 0;
    item[2] = taddr;
    item[3] = 0;
    item[4] = 0;
    item[5] = lbl_804988F0[0];
    item[6] = lbl_804988F0[1];
    item[7] = lbl_804988F0[2];
    item[8] = lbl_804988F0[3];
    item[9] = lbl_804988F0[4];
    menu[2] = 0;
    menu[3] = 0;
    menu[4] = 0;
    menu[0] = a;
    menu[1] = (s32)item;
    fn_80216CA8();
    fn_802146BC(menu, -999, -999, 1);
}
#pragma pop

int fn_80246DA8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

void fn_80246DE8(void) {
    fn_80246CB8(lbl_803432EC);
}

extern unsigned char lbl_803432FC[];
void fn_80246DF4(void) {
    fn_80246CB8(lbl_803432FC);
}

extern unsigned char lbl_8034330C[];
void fn_80246E00(void) {
    fn_80246CB8(lbl_8034330C);
}

int fn_80246E0C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 3
extern char lbl_80343600[];
extern char lbl_80343960[];
extern char lbl_80343950[];
extern char lbl_80343944[];
extern char lbl_80343938[];
extern char lbl_8055BEF8;
extern float lbl_8056389C;
extern s32 lbl_802FA3A0[5];
extern void fn_802ECEC4(void);
extern void fn_802ECEC0(void);
extern int fn_802C5130(const char *);
extern s32 fn_80232578(const char *);
extern void *fn_801284F8(unsigned long, void *);
extern s32 fn_8023512C();
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
s32 fn_80246E4C(void) {
    s32 text[11];
    Obj_802470D4 obj;
    s32 item[15];
    s32 menu[5];
    s32 res;
    s32 var_r25 = 0;
    s32 *p;
    float f;

    fn_802ECEC4();
    text[5] = var_r25;
    text[0] = (s32)lbl_803436C0;
    text[8] = 60000;
    text[9] = 3;
    text[10] = var_r25;
    text[7] = fn_802E2C20();
    text[10] = 3;
    text[6] = 1;
    *(s32 *)((char *)&obj + 0x14) = var_r25;
    obj.vtable = &lbl_80343600;
    obj.field18 = ((s32 (*)(void *, void *))fn_8023512C)(lbl_80343960, &lbl_80343600);
    obj.field1C = fn_8023512C(lbl_80343950);
    obj.field20 = fn_802C5130(lbl_80343944);

    p = (s32 *)fn_801284F8(0x14, &lbl_8055BEF8);
    if (p != 0) {
        p[0] = var_r25;
        p[1] = -1;
        p[2] = 9;
        f = lbl_80563898;
        ((float *)p)[3] = f;
        ((float *)p)[4] = f;
        p[0] = fn_80232578(lbl_80343938);
    }
    obj.field30 = p;
    ((float *)p)[3] = lbl_8056389C;

    obj.field30[2] = (obj.field30[2] & ~7) | 4;
    obj.field30[2] = (obj.field30[2] & ~0x58) | 0x10;

    *(s32 *)((char *)&obj + 0x24) = 2;
    *(s32 *)((char *)&obj + 0x28) = var_r25;
    *(float *)((char *)&obj + 0x2C) = (float)var_r25;

    item[1] = 5;
    item[0] = var_r25;
    item[2] = (s32)text;
    item[3] = var_r25;
    item[4] = var_r25;
    item[6] = 5;
    item[5] = var_r25;
    item[7] = (s32)&obj;
    item[8] = var_r25;
    item[9] = var_r25;

    menu[1] = lbl_802FA3A0[1];

    item[10] = lbl_804988F0[0];
    item[11] = lbl_804988F0[1];
    item[12] = lbl_804988F0[2];
    item[13] = lbl_804988F0[3];
    item[14] = lbl_804988F0[4];

    menu[0] = lbl_802FA3A0[0];
    menu[2] = lbl_802FA3A0[2];
    menu[3] = lbl_802FA3A0[3];
    menu[4] = lbl_802FA3A0[4];
    menu[1] = (s32)item;

    res = ((s32 (*)(s32 *, s32, s32, s32, s32, s32, s32, s32))fn_802146BC)(
        menu, -999, -999, 1,
        lbl_802FA3A0[4], lbl_802FA3A0[3], lbl_802FA3A0[2], lbl_802FA3A0[0]);

    if (res == -2) {
        var_r25 = *(s32 *)((char *)&obj + 0x28);
    } else if (res == -0xEA) {
        fn_802483E0();
        var_r25 = -1;
    } else {
        var_r25 = -1;
    }

    fn_802ECEC0();
    obj.vtable = &lbl_80343600;
    fn_80235380(obj.field18);
    fn_80235380(obj.field1C);
    fn_802C519C(obj.field20);
    p = obj.field30;
    if (p != 0) {
        fn_802328D4(p[0]);
        p[0] = 0;
        fn_80128668(p);
    }
    return var_r25;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
/* Destructor for the "cup" menu tile: releases its two art models, its track
   image and its text label, then deletes the object itself when deleteFlag > 0. */
Obj_802470D4 *fn_802470D4(Obj_802470D4 *self, s32 deleteFlag) {
    s32 *label;
    if (self != 0) {
        self->vtable = &lbl_80343600;
        fn_80235380(self->field18);
        fn_80235380(self->field1C);
        fn_802C519C(self->field20);
        label = self->field30;
        if (label != 0) {
            fn_802328D4(*label);
            *label = 0;
            fn_80128668(label);
        }
        if (deleteFlag > 0) fn_80128668(self);
    }
    return self;
}
#pragma pop
void fn_80247174(void) {
    s32 i = 0;
    do {
        fn_80246CAC(lbl_80563898 - (float)i / lbl_805638A8);
        fn_80127464();
        fn_802E2D74(16);
        i++;
    } while (i < 50);
    fn_8020A634();
    fn_80246CAC(lbl_80563898);
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_80247210(void) {
    /* Runs the kiosk/demo selection flow: initializes demo state, waits for a valid
       demo selection (retrying and showing "attract.avi" on -0xEA), resolves the
       selected item's resource by "demo_idx"/"song_id", then enters the game. */
    struct DemoResourceNode {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual s32 find(const char *name, s32 index) = 0;
    };
    s32 demoIndex;
    s32 selectResult;
    s32 selectedRootIndex;
    s32 selectedResource;
    s32 rootIndex;
    s32 candidateDemoIndex;
    void *root;
    void *demoSubobject;

    if (lbl_8055F268 == 0) {
        lbl_8055F264 = fn_8020A5F0();
        lbl_8055F268 = 1;
    }
    lbl_8055F260 = 1;
    fn_8023D704(0);
    fn_80129AFC();
    fn_802E47E8();
    fn_8023D7CC();

    demoIndex = 0;
    for (;;) {
        if (demoIndex != 0) {
            demoIndex = 0;
        } else {
            fn_80246DE8();
            fn_80246DF4();
            fn_80246E00();
        }
        selectResult = ((s32 (*)(void))fn_80248668)();
        if (selectResult == -0xEA) {
            if (fn_80278A1C(lbl_8034333C) == 0) {
                demoIndex = 1;
            }
            if (demoIndex == 0) {
                fn_80247174();
            }
            continue;
        }
        demoIndex = fn_80246E4C();
        if (demoIndex < 0) {
            demoIndex = 1;
            continue;
        }
        break;
    }

    fn_802E317C(lbl_8034397C);

    selectedRootIndex = -1;
    selectedResource = -1;
    rootIndex = 0;
    goto loop_check;

loop_items:
    root = fn_80012820(rootIndex);
    demoSubobject = *(void **)((char *)root + 0x80);
    candidateDemoIndex = ((DemoResourceNode *)demoSubobject)->find(lbl_80343348, -1);
    if (demoIndex == candidateDemoIndex) {
        selectedRootIndex = rootIndex;
        root = fn_80012820(rootIndex);
        demoSubobject = *(void **)((char *)root + 0x80);
        selectedResource = ((DemoResourceNode *)demoSubobject)->find(&lbl_8055BE98, -1);
        goto loop_done;
    }
    rootIndex++;

loop_check:
    if (rootIndex < fn_80012818()) {
        goto loop_items;
    }

loop_done:
    fn_8020C91C(selectedResource);
    fn_8020A634();
    fn_8023BFBC(selectedRootIndex, 0);
    fn_802483E0();
    fn_8020C91C(-1);
    lbl_8055F260 = 0;
}
#pragma cplusplus reset
#pragma pop

#pragma dont_inline fn_80246DE8
#pragma dont_inline fn_80246DF4
#pragma dont_inline fn_80246E00
#pragma dont_inline fn_80247174
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
s32 fn_8024739C(void) { return 0; }
#pragma dont_inline reset
#pragma pop

extern char lbl_8055F260, lbl_8055F269, lbl_8055F26A;
extern unsigned int lbl_8055D430, lbl_8055E044;
extern char lbl_80343270[], lbl_80498980[], lbl_8049898C[];
extern void fn_8020A600(void), fn_802ECEC4(void), fn_80019708(void);
extern void fn_80129AEC(int), fn_8024CF60(void), fn_8024CFB4(void);
extern void fn_8027DDCC(int), fn_80260954(int), fn_8023BEA8(void);
extern void fn_801312EC(void *, const char *), fn_80131318(void *);
extern void fn_80214FD8(void *, void *), fn_80239F74(void);
extern s32 fn_8000DA10(void);
extern int fn_8000DBAC(void);
extern void fn_802E6FBC(void), fn_8000DC70(int), fn_800169F8(int), fn_80137C78(int);
extern s32 fn_802E4A10(void);
extern void fn_80137C84(int, int), fn_8023BCEC(void);
extern void fn_8025812C(void), fn_8025C054(void), fn_800196FC(void), fn_80161DE4(void);
extern void fn_8027DE6C(void), fn_80263F30(int,int,int);
extern void fn_802E317C(const char *, ...);
extern s32 lbl_802FA38C[5];
extern char lbl_803432C0[];
extern char lbl_80343970[];
extern char lbl_80498908;
extern char lbl_8055BE90;
extern s32 lbl_8055F25C;
extern s32 lbl_8055B860;
extern s32 fn_8023512C(void *);
extern s32 fn_80246938(void);

#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 3
#pragma scheduling invalid_target
s32 fn_80246AE8(void) {
    s32 args[5];
    s32 text[6];
    s32 result;
    s32 values[20];

    lbl_8055F25C = fn_802E2C20();
    text[0] = (s32)lbl_80343780;
    text[5] = 0;
    result = fn_8023512C(lbl_80343970);
    args[0] = lbl_802FA38C[0];
    args[1] = lbl_802FA38C[1];
    args[2] = lbl_802FA38C[2];
    args[3] = lbl_802FA38C[3];
    args[4] = lbl_802FA38C[4];
    values[0] = (s32)lbl_803432C0;
    values[1] = 5;
    values[2] = (s32)text;
    values[3] = 0;
    values[4] = 0;
    values[5] = (s32)&lbl_8055BE90;
    values[6] = 3;
    values[7] = (s32)&lbl_80498908;
    values[8] = 0x40;
    values[9] = 0;
    values[10] = (s32)&lbl_8055B860;
    values[11] = 6;
    values[12] = (s32)fn_80246938;
    values[13] = -2;
    values[14] = 0xD;
    values[15] = lbl_804988F0[0];
    values[16] = lbl_804988F0[1];
    values[17] = lbl_804988F0[2];
    values[18] = lbl_804988F0[3];
    values[19] = lbl_804988F0[4];
    args[1] = (s32)values;
    fn_802146BC(args, -0x3E7, -0x3E7, 1);
    text[0] = (s32)lbl_80343780;
    fn_80235380(result);
    return 1;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
void fn_802473A4(void) {
    char *base = lbl_80343270;
    int again;
    int prior;
    lbl_8055F260 = 1;
    fn_8020A600(); fn_802ECEC4();
    goto check_a;
    for (;;) {
        int code, old, flag;
        fn_80019708();
        again = 1;
        do {
        fn_80129AEC(0);
        code = fn_80247C18();
        switch (code) {
        case -1: fn_8024CF60(); break;
        case 0: fn_8024CFB4(); break;
        case 1: fn_8027DDCC(0); break;
        case 2: fn_8027DDCC(1); break;
        case 3: fn_8027DDCC(2); break;
        case 4: fn_80260954(0); break;
        case 5: fn_80260954(1); break;
        case 6:
            old=lbl_8055D430; flag=old&1; lbl_8055D430=old|1; fn_8023BEA8();
            if (fn_802411D4()==0) {
                if (!lbl_8055F269) { fn_801312EC(lbl_80498980,base+0x114); lbl_8055F269=1; }
                if (!lbl_8055F26A) { fn_801312EC(lbl_8049898C,base+0x13c); lbl_8055F26A=1; }
                if (*(unsigned int *)(lbl_80498980+8)!=lbl_8055E044) fn_80131318(lbl_80498980);
                if (*(unsigned int *)(lbl_8049898C+8)!=lbl_8055E044) fn_80131318(lbl_8049898C);
                fn_80214FD8(*(void **)(lbl_80498980+4),*(void **)(lbl_8049898C+4));
            }
            lbl_8055D430=(lbl_8055D430&~1)|flag; break;
        case 7: fn_80239F74(); fn_8000DA10(); if(fn_8000DBAC()){fn_802E6FBC();again=0;} break;
        case 8: fn_802E6FBC(); break;
        case 9:
            old=lbl_8055D430; flag=old&1; lbl_8055D430=old|1;
            fn_8000DC70(0); fn_800169F8(0); fn_80137C78(1);
            prior=fn_8000DA10(); fn_80137C84(fn_802E4A10(), prior); fn_802E4A10();
            fn_80129AEC(0); fn_8023BCEC(); lbl_8055D430=(lbl_8055D430&~1)|flag; break;
        case 10: fn_8025812C(); break;
        case 11: fn_8025C054(); break;
        case 12: fn_800196FC(); break;
        case 13: fn_80161DE4(); fn_8027DE6C(); break;
        case 14: fn_80263F30(1,1,1); break;
        case 15: again=0; break;
        case 16: case 17: break;
        default: fn_802E317C(base + 0x168); break;
        }
        } while (again);
        if (fn_8024CF54()) continue;
check_a:
        if (!fn_80246AE8()) break;
    }
    lbl_8055F260=0;
}
#pragma pop
char fn_80247624(void) {
    return lbl_8055F260;
}

s32 fn_8024762C(void) {
    if (fn_802E2C20() % 1500 > 500) fn_80214AF0(1);
    else fn_80214A9C(1);
    return 0;
}

#pragma scheduling invalid_target
void fn_8024768C(void) {
    s32 i;

    fn_80214CB4((s32)lbl_8055BEAC);
    i = 1;
    goto check;
loop:
    fn_80214B44(i);
    i += 1;
check:
    if (i < *(s32 *)((char *)lbl_802FA3B4 + lbl_8055F26C * 0xC + 8))
        goto loop;
    fn_80214A9C(0x14);
}
#pragma scheduling on
s32 fn_802476FC(void) {
    register s32 flag = 0;
    UnkFunc fn;
    if (fn_802411D4() != 0 && lbl_8055F26C > 0) flag = 1;
    if (flag) fn = fn_80214B44;
    else fn = fn_80214B94;
    return (fn(4), 0);
}

extern s32 lbl_8055BEA8;
extern s32 lbl_8055BEBC;
s32 fn_80214D04(void);
void fn_80247768(void) {
    lbl_8055BEAC = (void*)fn_80214D04();
}

extern void *lbl_8055BEB0;
extern s32 lbl_8055BEB8;
extern s32 lbl_8055F26C;
#pragma push
#pragma scheduling invalid_target
void fn_8024778C(void) {
    s32 var_r31;
    s32 previous = lbl_8055BEB8;
    if (previous != lbl_8055F26C) {
        lbl_8055BEB8 = lbl_8055F26C;
        switch (lbl_8055F26C) {
        case 2:
            lbl_8055BEB0 = (void *)1;
            break;
        case 3:
            lbl_8055BEB0 = (void *)2;
            break;
        default:
            lbl_8055BEB0 = 0;
            break;
        }
    }
    fn_80214CB4((s32)lbl_8055BEB0);
    switch ((s32)lbl_8055BEB8) {
    case 1:
        fn_80214B44(2);
        fn_80214A9C(3);
        break;
    case 2:
        if (fn_8027B8C0(1) != 0) {
            fn_80214B44(3);
        } else {
            fn_80214A9C(3);
        }
        break;
    }
    var_r31 = 0;
    do {
        if (fn_8027B94C(var_r31) == 0) {
            fn_80214A9C(var_r31 + 0xB);
        }
        var_r31 += 1;
    } while (var_r31 < 3);
}
#pragma pop
extern void* lbl_8055BEB0;
extern s32 lbl_8055BEB4;
void fn_80247880(void) {
    lbl_8055BEB0 = (void*)fn_80214D04();
}

#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 3
#pragma scheduling invalid_target
void fn_802478A4(void) {
    extern s32 lbl_802FA3F0[];
    extern s32 lbl_8055BAC0, lbl_8055BABC, lbl_8055B860;
    s32 data[40];
    volatile s32 *q = (volatile s32 *)lbl_804988F0;
    volatile s32 *p = (volatile s32 *)lbl_802FA3F0;
    register s32 eight, three, four, five, six;
    s32 b0 = lbl_804988F0[0];
    s32 b1, b2, b3, b4;
    s32 a0, a2, a3, a4;
    s32 stringBase;

    eight = 8;
    three = 3;
    four = 4;
    five = 5;
    six = 6;
    b1 = q[1];
    data[6] = eight;
    b2 = q[2];
    data[11] = eight;
    a0 = *p++;
    stringBase = (s32)lbl_80343270;
    b3 = q[3];
    a2 = p[1];
    b4 = q[4];
    a3 = p[2];
    a4 = p[3];

    data[7] = (s32)fn_8024778C;
    data[12] = (s32)fn_80247880;
    data[5] = (s32)&lbl_8055BAC0;
    data[10] = (s32)&lbl_8055BABC;
    data[13] = 1;
    data[8] = 0;
    data[9] = 0;
    data[14] = 0;
    data[15] = stringBase + 0x2A0;
    data[16] = 0;
    data[17] = 0;
    data[18] = three;
    data[19] = 0;
    data[20] = stringBase + 0x2AC;
    data[21] = 0;
    data[22] = 0;
    data[23] = four;
    data[24] = 0;
    data[25] = stringBase + 0x2B8;
    data[26] = 0;
    data[27] = 0;
    data[28] = five;
    data[29] = 0;
    data[30] = (s32)&lbl_8055B860;
    data[31] = six;
    data[32] = 0;
    eight = -1;
    data[33] = eight;
    data[34] = 0x1B;
    data[35] = b0;
    data[36] = b1;
    data[37] = b2;
    data[38] = b3;
    data[39] = b4;
    data[0] = a0;
    data[2] = a2;
    data[3] = a3;
    data[4] = a4;
    data[1] = (s32)&data[5];
    ((void (*)(s32 *, s32, s32, s32, s32, s32, s32, s32))fn_802146BC)(
        data, -999, -999, 1, stringBase + 0x2A0,
        stringBase + 0x2AC, stringBase + 0x2B8, (s32)&data[5]);
}
#pragma pop


static void fn_80247A0C_init(s32 a, s32 b) {
    if (a != b) {
        lbl_8055BEBC = b;
        if (b == 5) {
            lbl_8055BEB4 = 1;
        } else {
            lbl_8055BEB4 = 0;
        }
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80247A0C(void) {
    unsigned int var_r31;
    s32 a;
    s32 b;
    b = (int)lbl_8055BEA8;
    a = lbl_8055BEBC;
    if (a != b) {
        lbl_8055BEBC = b;
        switch (b) {
        case 5:
            lbl_8055BEB4 = 1;
            break;
        default:
            lbl_8055BEB4 = 0;
            break;
        }
    }
    fn_80214CB4(lbl_8055BEB4);
    switch (lbl_8055BEBC) {
    case 4:
        fn_80214B44(2);
        break;
    default:
        break;
    }
    var_r31 = 0;
    do {
        if (fn_8027B9EC(var_r31) == 0) {
            fn_80214A9C(var_r31 + 0xB);
        }
        ++var_r31;
    } while (2 > var_r31);
}
#pragma pop
void fn_80247AAC(void) {
    lbl_8055BEB4 = (s32) (void*)fn_80214D04();
}

extern s32 lbl_802FA404[5];
extern s32 lbl_8055BAC0, lbl_8055BABC, lbl_8055B860;
extern char lbl_80343544[], lbl_80343550[];
extern void fn_80247A0C(void);
extern void fn_80247AAC(void);
extern s32 lbl_802FA404[5];
#pragma push
#pragma use_lmw_stmw off
void fn_80247AD0(void) {
    s32 args[5];
    s32 values[30];
    values[0]=(s32)&lbl_8055BAC0; values[1]=8; values[2]=0; values[3]=0;
    values[4]=(s32)&lbl_8055BABC; values[5]=(s32)fn_80247AAC;
    values[6]=1; values[7]=0; values[8]=0; values[9]=(s32)lbl_80343544;
    values[10]=0; values[11]=6; values[12]=0; values[13]=0;
    values[14]=(s32)lbl_80343550; values[15]=0; values[16]=7; values[17]=0;
    values[18]=(s32)&lbl_8055B860; values[19]=6; values[20]=0;
    values[21]=-1; values[22]=0x1b; values[23]=lbl_804988F0[0];
    values[24]=lbl_804988F0[1]; values[25]=lbl_804988F0[2];
    values[26]=lbl_804988F0[3]; values[27]=lbl_804988F0[4];
    args[0]=lbl_802FA404[0]; args[1]=(s32)values;
    args[2]=lbl_802FA404[2]; args[3]=lbl_802FA404[3]; args[4]=lbl_802FA404[4];
    fn_802146BC(args,-999,-999,1);
}

#pragma push
#pragma use_lmw_stmw off
extern s32 fn_80161D50(void), fn_80161D14(void), fn_80019714(void);
extern s32 fn_8027DE68(s32);
extern s32 lbl_8055BEC0;
extern unsigned char lbl_8055F270, lbl_8055F271;
extern char lbl_803435A0[], lbl_802FA418[], lbl_8055BEC4, lbl_8055BEA0, lbl_8055BED0, lbl_8055BED8, lbl_8055BEE0, lbl_8055BEE8;
#pragma push
#pragma use_lmw_stmw off
int fn_80247C18() {
 struct Entry { s32 id; unsigned char enabled; char pad[3]; };
 struct Frame { s32 args[5]; s32 title; s32 pad[4]; s32 zero; struct Entry *entries; s32 count; s32 capacity; struct Entry data[10]; s32 items[75]; } frame;
 s32 *table; char *base = lbl_80343270; s32 a, b, missing, v, result, flag; struct Entry *entry;
 lbl_8055F26C = 0;
 a = fn_80161D50();
 b = fn_80161D14();
 { s32 d = b ^ a; s32 half = d >> 1; if ((unsigned long)(half - (d & b)) >> 31) {
   lbl_8055F26C = 1;
   if (fn_8027DE68(0)) {
     lbl_8055F26C = 2;
     if (fn_8027DE68(1)) lbl_8055F26C = 3;
   }
 }
 }
 lbl_8055BEA8 = 4;
 if (fn_8027B9EC(0)) lbl_8055BEA8 = 5;
 if (fn_80019714()) { lbl_8055F26C = 3; lbl_8055BEA8 = 5; }
 table = lbl_802FA3B4 + lbl_8055F26C * 3;
 frame.zero = 0; frame.count = 0; frame.title = (s32)lbl_803435A0;
 frame.entries = frame.data; frame.capacity = 10;
 b = fn_8027DE68(2); missing = (b == 0);
 flag = missing && lbl_8055F26C >= 2; entry = &frame.entries[frame.count++]; entry->id = 11; entry->enabled = flag;
 flag = missing && lbl_8055F26C >= 3; entry = &frame.entries[frame.count++]; entry->id = 12; entry->enabled = flag;
 entry = &frame.entries[frame.count++]; entry->id = 13; entry->enabled = (int)b;
 b = fn_8027B9EC(1);
 flag = b == 0 && lbl_8055BEA8 >= 5; entry = &frame.entries[frame.count++]; entry->id = 14; entry->enabled = flag;
 entry = &frame.entries[frame.count++]; entry->id = 15; entry->enabled = b;
 entry = &frame.entries[frame.count++]; entry->id = 16; entry->enabled = 0;
 v = fn_8000DA10();
 if (lbl_8055BEC0 < 0 || lbl_8055BEC0 != v) lbl_8055BEAC = (void *)table[0];
 lbl_8055BEC0 = v;
 frame.items[0] = 0;
 frame.items[1] = 5;
 frame.items[2] = (s32)&frame.title;
 frame.items[3] = 0;
 frame.items[4] = 0;
 frame.items[5] = (s32)&lbl_8055BAC0;
 frame.items[6] = 8;
 frame.items[7] = (s32)fn_8024768C;
 frame.items[9] = 0;
 frame.items[8] = 0;
 frame.items[10] = (s32)&lbl_8055BABC;
 frame.items[11] = 8;
 frame.items[12] = (s32)fn_80247768;
 frame.items[13] = 1;
 frame.items[14] = 0;
 frame.items[15] = (s32)&lbl_8055B860;
 frame.items[16] = 6;
 frame.items[17] = 0;
 frame.items[18] = -1;
 frame.items[19] = 0x1b;
 frame.items[20] = (s32)(base + 0x2ec);
 frame.items[21] = 0;
 frame.items[22] = 0;
 frame.items[23] = 1;
 frame.items[24] = 0;
 frame.items[25] = (s32)&lbl_8055BEC4;
 frame.items[26] = 0;
 frame.items[27] = 0;
 frame.items[28] = 2;
 frame.items[29] = 0;
 frame.items[30] = (s32)(base + 0x2a0);
 frame.items[31] = 0;
 frame.items[32] = 0;
 frame.items[33] = 3;
 frame.items[34] = 0;
 frame.items[36] = 0;
 frame.items[35] = (s32)(base + 0x2f8);
 frame.items[37] = 0;
 frame.items[38] = 6;
 frame.items[39] = 0;
 frame.items[40] = (s32)&lbl_8055BEA0;
 frame.items[41] = 0;
 frame.items[42] = 0;
 frame.items[43] = 8;
 frame.items[44] = 0;
 frame.items[45] = (s32)(base + 0x304);
 frame.items[46] = 0;
 frame.items[47] = 0;
 frame.items[48] = 12;
 frame.items[49] = 0;
 frame.items[50] = (s32)&lbl_8055BED0;
 frame.items[51] = 0;
 frame.items[52] = 0;
 frame.items[53] = 9;
 frame.items[54] = 0;
 frame.items[55] = (s32)&lbl_8055BED8;
 frame.items[56] = 0;
 frame.items[57] = 0;
 frame.items[58] = 10;
 frame.items[59] = 0;
 frame.items[60] = (s32)&lbl_8055BEE0;
 frame.items[61] = 0;
 frame.items[62] = 0;
 frame.items[63] = 11;
 frame.items[64] = 0;
 frame.items[66] = 0;
 frame.items[65] = (s32)&lbl_8055BEE8;
 frame.items[67] = 0;
 frame.items[68] = 16;
 frame.items[69] = 0;
 frame.items[70] = lbl_804988F0[0];
 frame.items[71] = lbl_804988F0[1];
 frame.items[72] = lbl_804988F0[2];
 frame.items[73] = lbl_804988F0[3];
 frame.items[74] = lbl_804988F0[4];
 for (;;) {
   if (lbl_8055F270) result = 3;
   else if (lbl_8055F271) result = 6;
   else {
     frame.args[0] = ((s32 *)lbl_802FA418)[0];
     frame.args[1] = ((s32 *)lbl_802FA418)[1];
     frame.args[2] = ((s32 *)lbl_802FA418)[2];
     frame.args[3] = ((s32 *)lbl_802FA418)[3];
     frame.args[4] = ((s32 *)lbl_802FA418)[4];
     frame.args[0] = table[1]; frame.args[1] = (s32)frame.items;
     result = ((s32 (*)(void *, s32, s32, s32))fn_802146BC)(frame.args, -999, -999, 1);
   }
   if ((int)result == 3) {
      if (((s32 (*)(void))fn_802478A4)() != -1) { lbl_8055F270 = 1; frame.entries = 0; frame.count = 0; frame.capacity = 0; return result; }
      lbl_8055F270 = 0;
   } else if (result == 6) {
      if (((s32 (*)(void))fn_80247AD0)() != -1) { lbl_8055F271 = 1; frame.entries = 0; frame.count = 0; frame.capacity = 0; return result; }
      lbl_8055F271 = 0;
   } else break;
 }
 frame.entries = 0; frame.count = 0; frame.capacity = 0;
}
#pragma pop

#pragma pop
void *fn_80248140(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((unsigned int)arg0 + 0x18 != 0) {
            if ((unsigned int)arg0 + 0x18 != 0) {
                *(int *)((char *)arg0 + 0x18) = 0;
                *(int *)((char *)arg0 + 0x1C) = 0;
                *(int *)((char *)arg0 + 0x20) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern s32 lbl_8055F274;
extern float lbl_805638AC, lbl_805638B0, lbl_805638B4, lbl_805638B8;
extern double sin(double);
extern float lbl_802FA430[18];
extern void *memcpy(void *, const void *, unsigned long);
#pragma push
#pragma processor 750
void fn_802481A0(float *arg0, float *arg1, float farg0, float farg1) {
    typedef struct { float v[18]; } Table;
    Table tbl;
    register float x = farg0;
    register float y = farg1;
    s32 time;
    float phase;
    s32 index;
    float t;
    float a;
    float b;

    time = (fn_802E2C20() - lbl_8055F274) - 0x5DC;
    phase = (lbl_80563898 < (float)time / lbl_805638AC) ? lbl_80563898 : (float)time / lbl_805638AC;
    phase = (phase > lbl_805638B0) ? phase : lbl_805638B0;
    phase = lbl_80563898 - phase;
    *arg0 = x + lbl_805638B8 * (float)sin((double)(lbl_805638B4 * phase));

    tbl = *(Table *)lbl_802FA430;

    for (index = 1; index < 8; index++) {
        if (x < tbl.v[index * 2]) break;
    }

    t = (x - tbl.v[(index - 1) * 2]) /
        (tbl.v[index * 2] - tbl.v[(index - 1) * 2]);
    if (t < lbl_80563898) t = lbl_80563898;
    if (t > lbl_805638B0) t = lbl_805638B0;
    a = tbl.v[(index - 1) * 2 + 1];
    b = tbl.v[index * 2 + 1];
    *arg1 = y + phase * (a + t * (b - a));
}
#pragma pop
void fn_80248398(void) {
    s32 c;
    s32 a;
    s32 b;
    lbl_8055F278_struct *p;

    p = (lbl_8055F278_struct *)lbl_8055F278;
    if (p != 0) {
        a = p->unk04;
        b = p->unk08;
        c = lbl_8055BEF0 + a;
        p->unk50 = 1;
        p->unk48 = c;
        p->unk4C = b;
        p = (lbl_8055F278_struct *)lbl_8055F278;
        p->unk5C = 1;
        p->unk54 = a;
        p->unk58 = b;
        p->unk44 = 0;
    }
}

extern char lbl_803437E0[];
extern char lbl_80343590[];
extern s32 lbl_802FA478[5];
extern float lbl_8055BEF4;
extern void fn_80232B80(s32);
#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 4
#pragma scheduling invalid_target
void fn_802483E0(void) {
    struct Object {
        void *vtable;
        char pad04[0x10];
        s32 unk14;
        unsigned char unk18;
        char pad19[7];
        s32 unk20;
        s32 unk24;
        char pad28[0x10];
        float unk38;
        float unk3C;
        s32 unk40;
        unsigned char unk44;
        char pad45[0x0B];
        unsigned char unk50;
        char pad51[0x0B];
        unsigned char unk5C;
    };
    struct Frame {
        volatile s32 args[5];
        s32 text[11];
        s32 item[20];
        struct Object object;
    } frame;
    register s32 *textPtr = frame.text;
    register s32 zero = 0;
    register s32 one;
    register struct Object *objectPtr;
    s32 t1, t0, t2, t3, t4;
    textPtr[5] = zero;
    textPtr[0] = (s32)lbl_803436C0;
    textPtr[8] = 0x1388;
    textPtr[9] = zero;
    textPtr[10] = zero;
    textPtr[7] = fn_802E2C20();
    frame.object.unk14 = zero;
    frame.object.vtable = lbl_803437E0;
    one = 1;
    textPtr[6] = one;
    frame.object.unk38 = lbl_80563898 / lbl_8055BEF4;
    frame.object.unk40 = 2;
    frame.object.unk3C = lbl_80563898;
    frame.object.unk18 = 0;
    frame.object.unk50 = 0;
    frame.object.unk5C = 0;
    frame.object.unk24 = 2;
    frame.object.unk20 = zero;
    frame.object.unk44 = 0;
    frame.item[1] = 8;
    frame.item[0] = (s32)&lbl_8055BAC0;
    frame.item[2] = (s32)fn_80248398;
    frame.item[3] = zero;
    frame.item[4] = zero;
    frame.item[6] = 5;
    frame.item[5] = (s32)lbl_80343590;
    objectPtr = &frame.object;
    frame.item[7] = (s32)objectPtr;
    frame.item[8] = zero;
    frame.item[9] = zero;
    frame.item[11] = 5;
    frame.item[10] = zero;
    frame.item[12] = (s32)textPtr;
    frame.item[13] = zero;
    frame.item[14] = zero;
    frame.item[15] = lbl_804988F0[0];
    frame.item[16] = lbl_804988F0[1];
    frame.item[17] = lbl_804988F0[2];
    frame.item[18] = lbl_804988F0[3];
    frame.item[19] = lbl_804988F0[4];
    lbl_8055F274 = fn_802E2C20();
    t1 = lbl_802FA478[1];
    t0 = lbl_802FA478[0];
    frame.args[1] = t1;
    t2 = lbl_802FA478[2];
    t3 = lbl_802FA478[3];
    t4 = lbl_802FA478[4];
    lbl_8055F278 = objectPtr;
    frame.args[0] = t0;
    frame.args[2] = t2;
    frame.args[3] = t3;
    frame.args[4] = t4;
    frame.args[1] = (s32)frame.item;
    fn_80232B80((s32)fn_802481A0);
    fn_802146BC((void *)frame.args, -999, -999, 1);
    fn_80232B80(0);
    lbl_8055F278 = 0;
    frame.object.unk18 = 0;
    frame.object.unk50 = 0;
    frame.object.unk5C = 0;
    frame.object.unk24 = 1;
    frame.object.unk20 = 0;
    frame.object.unk44 = 0;
}
#pragma pop

#pragma scheduling invalid_target
void* fn_8024859C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(unsigned char *)((unsigned char *)arg0 + 0x18) = 0;
        *(unsigned char *)((unsigned char *)arg0 + 0x50) = 0;
        *(unsigned char *)((unsigned char *)arg0 + 0x5C) = 0;
        *(s32 *)((unsigned char *)arg0 + 0x24) = 1;
        *(s32 *)((unsigned char *)arg0 + 0x20) = 0;
        *(unsigned char *)((unsigned char *)arg0 + 0x44) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
s32 fn_802485FC(void) {
    unsigned short args[5];
    unsigned short *p = lbl_802FA48C;

    args[0] = *p++;
    args[1] = *p++;
    args[2] = *p++;
    args[3] = *p++;
    args[4] = *p++;
    if (fn_802E499C(args, args[3], args[2], args[1], args[0]) != 0) {
        fn_80246CAC(lbl_805638B0);
        fn_8020C918(1);
    }
    return 0;
}

extern s32 fn_8020A640(void);
extern s32 lbl_802FA498[5];
extern void fn_8020A600(void);
#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 3
#pragma scheduling invalid_target
void fn_80248668(s32 arg0) {
    s32 text[12];
    s32 item[10];
    s32 menu[6];
    s32 taddr = (s32)text;
    s32 tmp;
    if (fn_8020A640() != 0)
        return;
    fn_8020A600();
    text[5] = 0;
    text[0] = (s32)lbl_803436C0;
    text[8] = 30000;
    text[9] = 1;
    text[10] = 0;
    text[7] = ((s32 (*)(void *))fn_802E2C20)(lbl_803436C0);
    tmp = lbl_802FA498[1];
    text[6] = 1;
    item[1] = 5;
    item[0] = 0;
    item[2] = taddr;
    item[3] = 0;
    item[4] = 0;
    item[5] = lbl_804988F0[0];
    item[6] = lbl_804988F0[1];
    item[7] = lbl_804988F0[2];
    item[8] = lbl_804988F0[3];
    item[9] = lbl_804988F0[4];
    menu[1] = tmp;
    menu[0] = lbl_802FA498[0];
    menu[2] = lbl_802FA498[2];
    menu[3] = lbl_802FA498[3];
    menu[4] = lbl_802FA498[4];
    menu[1] = (s32)item;
    ((void (*)(s32 *, s32, s32, s32, s32, s32, s32, s32))fn_802146BC)(
        menu, -0x3E7, -0x3E7, 1,
        lbl_802FA498[4], lbl_802FA498[3], lbl_802FA498[2], lbl_802FA498[0]);
}
#pragma pop

void fn_80248770(void *arg0) {
    *(unsigned char*)((char*)arg0 + 0x18) = 1;
    *(s32*)((char*)arg0 + 0x1C) = fn_80221EA8();
}

void fn_802487A8(void *arg0) {
    *(unsigned char*)((char*)arg0 + 0x18) = 0;
}

#pragma push
#pragma optimization_level 3
void fn_802487B4(void *arg0) {
 extern void fn_80214BE4(s32,s32,s32);
 extern float lbl_805638B8,lbl_805638BC,lbl_805638C0,lbl_805638C4;
 float t, x1,x0,y1,y0, factor;
 s32 y,x;
 if (*(s32 *)((char *)arg0+0x20)!=*(s32 *)((char *)arg0+0x24)) {
 if (*(s32 *)((char *)arg0+0x20)==0) fn_80214AF0(*(s32 *)((char *)arg0+0x1C)); else fn_80214A9C(*(s32 *)((char *)arg0+0x1C));
 *(s32 *)((char *)arg0+0x24)=*(s32 *)((char *)arg0+0x20);
 }
 if (*(unsigned char *)((char *)arg0+0x50)) {
 x=*(s32 *)((char *)arg0+0x48); y=*(s32 *)((char *)arg0+0x4C);
 *(s32 *)((char *)arg0+0x30)=x; *(s32 *)((char *)arg0+0x28)=x; *(s32 *)((char *)arg0+0x34)=y; *(s32 *)((char *)arg0+0x2C)=y;
 fn_80214BE4(*(s32 *)((char *)arg0+0x1C),x-*(s32 *)((char *)arg0+0x4),y-*(s32 *)((char *)arg0+0x8));
 t=lbl_805638BC; *(unsigned char *)((char *)arg0+0x50)=0; *(float *)((char *)arg0+0x3C)=t;
 }
 if (*(unsigned char *)((char *)arg0+0x5C)) {
 *(s32 *)((char *)arg0+0x28)=*(s32 *)((char *)arg0+0x4); *(s32 *)((char *)arg0+0x2C)=*(s32 *)((char *)arg0+0x8); *(s32 *)((char *)arg0+0x30)=*(s32 *)((char *)arg0+0x54); *(s32 *)((char *)arg0+0x34)=*(s32 *)((char *)arg0+0x58);
 *(float *)((char *)arg0+0x3C)=lbl_805638B0; *(unsigned char *)((char *)arg0+0x5C)=0;
 }
 t=*(float *)((char *)arg0+0x3C)+*(float *)((char *)arg0+0x38)*fn_80214D48();
 *(float *)((char *)arg0+0x3C)=t;
 switch (*(s32 *)((char *)arg0+0x40)) {
 case 1:
 t=t<lbl_80563898?t:lbl_80563898;
 factor=t*t; break;
 case 2:
 t=t<lbl_80563898?t:lbl_80563898;
 factor=t<lbl_805638C0?lbl_805638C0:
 t>lbl_80563898?lbl_80563898:
 t>lbl_805638B0?t*(t*(lbl_805638C4*t))+((lbl_805638B8*t)*t):
 t*(t*(lbl_805638C4*t))-((lbl_805638B8*t)*t);
 break;
 default: factor=*(float *)((char *)arg0+0x3C); factor=factor<lbl_80563898?factor:lbl_80563898;
 }
 x1=(float)*(s32 *)((char *)arg0+0x30); x0=(float)*(s32 *)((char *)arg0+0x28); y1=(float)*(s32 *)((char *)arg0+0x34); y0=(float)*(s32 *)((char *)arg0+0x2C);
 x=(s32)(x0+factor*(x1-x0)); y=(s32)(y0+factor*(y1-y0));
 fn_80214BE4(*(s32 *)((char *)arg0+0x1C),x-*(s32 *)((char *)arg0+0x4),y-*(s32 *)((char *)arg0+0x8));
 if (*(unsigned char *)((char *)arg0+0x44)) {
 s32 done=(*(float *)((char *)arg0+0x3C)>=lbl_80563898);
 if (done) { *(unsigned char *)((char *)arg0+0x44)=0; *(s32 *)((char *)arg0+0x20)=1; }
 }
}
#pragma pop
void fn_80248A68(void *arg0) {
    *(float*)((char*)arg0 + 0x1C) = lbl_805638B0;
}

#pragma scheduling invalid_target
void fn_80248A74(void *arg0) {
    float *fp = (float *)((char *)arg0 + 0x1C);
    s32 rate;
    if (*fp > lbl_805638C8) rate = 0xC8;
    else rate = 0x32;
    *fp = *fp + (float)rate * fn_80214D48();
}
#pragma scheduling on
void fn_80230C30(float *, float *, s32, s32);
float fn_80235F64(s32, s32);
void fn_802353F4(s32, s32, float, float, float);
#pragma push
#pragma processor 750
void fn_80248AF0(void *arg0) {
    /* Position a UI element relative to layout coords, wrapping its local X
     * offset within the element width and placing it with computed Y. */
    float layoutX, layoutY;
    float width, height;
    s32 useOffset;
    fn_80230C30(&layoutX, &layoutY, *(s32*)((char*)arg0+4), *(s32*)((char*)arg0+8));
    width = (float)*(s32*)((char*)arg0+0xC);
    height = (float)*(s32*)((char*)arg0+0x10);
    if (*(float*)((char*)arg0+0x1C) > width)
        *(float*)((char*)arg0+0x1C) -= width;
    useOffset = *(float*)((char*)arg0+0x1C) > lbl_805638C8;
    fn_802353F4(*(s32*)((char*)arg0+0x18), useOffset, layoutX + *(float*)((char*)arg0+0x1C), (layoutY-height)+fn_80235F64(*(s32*)((char*)arg0+0x18), useOffset), lbl_805638B0);
}
#pragma pop

#pragma scheduling invalid_target
void fn_80248BD0(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x1C) = fn_802E8690(*(s32 *)((char *)arg0 + 0x18));
    *(float *)((char *)arg0 + 0x20) = lbl_805638CC;
}
#pragma scheduling on
void fn_80248C0C(void *obj) {
    /* Update a countdown/timer object: read a ready flag from fn_802E8690(obj+0x18) into +0x1C.
       When ready, reset timer at +0x20 to 2.0f and disable UI element 0x1E; otherwise decrement
       the timer by frame delta and enable UI element 0x1E. If the timer goes below 0, trigger
       fn_80221F94(obj, 0). */
    unsigned char ready;
    float *timer = (float *)((char *)obj + 0x20);

    ready = fn_802E8690(*(s32 *)((char *)obj + 0x18));
    *(unsigned char *)((char *)obj + 0x1C) = ready;
    if (ready != 0) {
        *timer = lbl_805638CC;
        fn_80214A9C(0x1E);
    } else {
        *timer -= fn_80214D48();
        fn_80214AF0(0x1E);
    }
    if (*timer < lbl_80558DC4[0]) {
        fn_80221F94(obj, 0);
    }
}

int fn_80248C94(void *arg0, int arg1) {
    if (*(unsigned char *)((char *)arg0 + 0x1C) == 0 && arg1 == 13) {
        fn_80221F94(arg0, 0);
        return 1;
    } else {
        return 0;
    }
}

extern float lbl_805638D0, lbl_805638D4, lbl_805638D8;
extern s32 fn_802C942C(s32);
void fn_80248CD8(void *arg0)
{
  register s32 elapsed;
  s32 limit;
  register s32 alpha;
  s32 converted;
  float factor;
  float amount;
  float value;
  float next;
  s32 now;
  now = fn_802E2C20();
  factor = lbl_805638B0;
  elapsed = now - (*((s32 *) (((char *) arg0) + 0x1C)));
  if (elapsed < 0x1F4)
  {
    if (factor <= (lbl_80563898 - (((float) elapsed) / lbl_805638D0)))
    {
      goto update_first;
    }
    goto after_first;
    update_first:
    factor = lbl_80563898 - (((float) elapsed) / lbl_805638D0);

    after_first:
    ;

    ;
  }
  limit = *((s32 *) (((char *) arg0) + 0x20));
  if ((limit != 0) || ((*((s32 *) (((char *) arg0) + 0x18))) != 1))
  {
    if (elapsed > (limit - 0x1F4))
    {
      value = lbl_80563898 - (((float) (limit - elapsed)) / lbl_805638D0);
      if (factor <= value)
      {
        goto update_second;
      }
      if (value)
      {
        goto after_second;
      }
      else
      {
        goto after_second;
      }
      update_second:
      factor = value;

      after_second:
      ;

      ;
    }
  }
  amount = lbl_805638D4 * factor;
  if (amount < lbl_805638B0)
  {
    next = amount - lbl_805638D8;
  }
  else
  {
    next = lbl_805638D8 + amount;
  }
  alpha = 0xFF;
  converted = (s32) next;
  converted = converted & (((-converted) & (~converted)) >> 31);
  if (converted < 0xFF)
  {
    alpha = converted;
  }
  fn_802C942C((alpha << 24) | 0xFFFFFF);
}

void fn_80248E30(void *arg0) {
    extern float lbl_805638DC;
    extern char lbl_803438A0[];
    extern void fn_8020A634(void);
    extern s32 fn_8020A640(void);
    extern void fn_80221F94(void *, s32);
    s32 now;
    s32 duration;
    s32 elapsed;
    s32 state;
    float factor;
    float value;

    if (*(s32 *)((char *)arg0 + 0x20) == 0 &&
        *(s32 *)((char *)arg0 + 0x18) == 1)
        return;

    now = fn_802E2C20();
    if ((*(s32 *)((char *)arg0 + 0x28) &
         *(s32 *)((char *)arg0 + 0x18)) != 0 &&
        fn_8020A640() != 0) {
        elapsed = now - *(s32 *)((char *)arg0 + 0x1C);
        duration = *(s32 *)((char *)arg0 + 0x20);
        if (elapsed > duration - 0x190) {
            factor = lbl_80563898;
            value = (float)(duration - elapsed) / lbl_805638DC;
            factor = factor < value ? value : factor;
            factor = factor > lbl_805638B0 ? lbl_805638B0 : factor;
            fn_80246CAC(factor);
        }
    }

    if (now > *(s32 *)((char *)arg0 + 0x1C) +
              *(s32 *)((char *)arg0 + 0x20)) {
        state = *(s32 *)((char *)arg0 + 0x18);
        switch (state) {
        case 1: fn_80221F94(arg0, -0xEA); break;
        case 4: fn_80221F94(arg0, -1); break;
        case 2: fn_80221F94(arg0, -2); break;
        default: fn_802E317C(lbl_803438A0); break;
        }
        if ((*(s32 *)((char *)arg0 + 0x28) &
             *(s32 *)((char *)arg0 + 0x18)) != 0 &&
            fn_8020A640() != 0) {
            fn_8020A634();
            fn_80246CAC(lbl_80563898);
        }
    }
}

#pragma scheduling off
s32 fn_80248FB0(void *arg0, s32 arg1) {
    s32 duration, start, now;
    now = fn_802E2C20();
    start = *(s32 *)((char *)arg0 + 0x1C);
    if (now < start + 750) return 0;
    duration = *(s32 *)((char *)arg0 + 0x20);
    if (duration != 0 && now - start > duration - 500) return 0;
    if (*(s32 *)((char *)arg0 + 0x18) != 1) return 0;
    switch (arg1) {
    case 27:
        if (*(s32 *)((char *)arg0 + 0x24) & 2)
            *(s32 *)((char *)arg0 + 0x18) = 4;
        else return 0;
        break;
    case 13:
        if (*(s32 *)((char *)arg0 + 0x24) & 1)
            *(s32 *)((char *)arg0 + 0x18) = 2;
        else return 0;
        break;
    default: return 0;
    }
    *(s32 *)((char *)arg0 + 0x1C) = now - *(s32 *)((char *)arg0 + 0x20) + 500;
    return 1;
}
#pragma scheduling on
void fn_802490AC(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;

    *(p + 0x1C) = 0;
    *(s32 *)((char *)arg0 + 0x18) = fn_802E2C20();
    if (fn_802C9A58() != 0) {
        fn_80214A9C(1);
    } else {
        fn_80214A9C(2);
    }
}

void fn_80249104(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;

    if (*(p + 0x1C) == 0 && fn_802E2C20() - *(s32 *)((char *)arg0 + 0x18) >= 0x3A98) {
        fn_802168BC(-2);
    }
}

s32 fn_80249154(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;

    if (*(p + 0x1C) == 0 && fn_802E2C20() - *(s32 *)((char *)arg0 + 0x18) >= 0x5DC) {
        fn_802168BC(-2);
    }
    return 1;
}

extern float lbl_805638E0, lbl_805638E4, lbl_805638E8, lbl_805638EC, lbl_805638F0, lbl_805638F4, lbl_805638F8, lbl_805638FC, lbl_80563900;
extern char lbl_8055BF00, lbl_8055BF08;
extern float fn_80235EF0(s32, s32);
extern void fn_802353F4(s32, s32, float, float, float);
extern void fn_802354A0(s32, s32, s32, float, float, float, float, float);
extern void fn_80234AFC(s32, char *, float, float);
extern int __cntlzw(unsigned int);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802491A8(void *arg0) {
    char *base = (char *)arg0;
    int i = 0;
    float scale = lbl_805638E0;
    float sub = lbl_805638E4;
    float origin = lbl_805638E8;
    float xOrigin = lbl_805638EC;
    float yOrigin = lbl_805638F8;
    for (; i < *(int *)(base + 0x24); i++) {
        float fi = (float)i;
        int selected = *(int *)(base + 0x28) == i;
        int obj;
        float offset = scale * (fi - *(float *)(base + 0x2C)) - sub;
        float x;
        if (selected)
            obj = *(int *)(base + 0x18);
        else
            obj = *(int *)(base + 0x1C);
        fn_802353F4(obj, 0, origin + offset - fn_80235EF0(obj, 0), lbl_805638E4, lbl_805638B0);
        x = xOrigin + offset;
        fn_802354A0(*(int *)(base + 0x20), i, selected ? -0x100 : (int)0xC0202020,
                    x, lbl_805638F0, lbl_805638B0,
                    lbl_805638F4, lbl_805638F4);
        *(int *)(*(int *)(base + 0x30) + 4) = selected ? -0x100 : (int)0xC0202020;
        fn_80234AFC(*(int *)(base + 0x30),
                    i == 0 ? (char *)&lbl_8055BF08 : (char *)&lbl_8055BF00,
                    sub + offset - yOrigin, lbl_805638FC);
    }
    *(float *)(base + 0x2C) += lbl_80563900 * ((float)*(int *)(base + 0x28) - *(float *)(base + 0x2C));
}
#pragma pop
/* Handle menu navigation input: adjust selected index at +0x28 within [0, count at +0x24), calling fn_80214D50(0) on move or (1) on boundary. */
s32 fn_80249334(void *menu, s32 input) {
    s32 *index = (s32 *)((char *)menu + 0x28);

    switch (input) {
    case 0x126:
        break;
    case 0x125:
        if (*index > 0) {
            fn_80214D50(0);
            *index = *index - 1;
        } else {
            fn_80214D50(1);
        }
        break;
    case 0x127:
        if (*index + 1 < *(s32 *)((char *)menu + 0x24)) {
            fn_80214D50(0);
            *index = *index + 1;
        } else {
            fn_80214D50(1);
        }
        break;
    }
    return 0;
}

/* One entry of the UI group list fn_802493E8 walks. */
typedef struct UIGroupEntry {
    s32 groupId;           /* 0x00: group handed to UIShowGroup/UIHideGroup */
    unsigned char shown;   /* 0x04: non-zero shows the group, zero hides it */
} UIGroupEntry;            /* 8 bytes */

/* Head of such a list, as kept by the menu object fn_802493E8 is called with. */
typedef struct UIGroupList {
    char pad00[0x18];
    UIGroupEntry *entries; /* 0x18 */
    s32 count;             /* 0x1C */
} UIGroupList;

#pragma push
#pragma optimization_level 3
/* Show or hide every UI group of a menu: walks the list of entries and calls
 * UIShowGroup (fn_80214AF0) for the ones flagged shown, UIHideGroup
 * (fn_80214A9C) for the rest, on the window those two pick up themselves. */
void fn_802493E8(void *arg0) {
    s32 byteOffset = 0;
    s32 i = 0;
    register UIGroupList *list = (UIGroupList *)arg0;
    while (i < list->count) {
        UIGroupEntry *entry = (UIGroupEntry *)((char *)list->entries + byteOffset);
        if (entry->shown != 0)
            fn_80214AF0(entry->groupId);
        else
            fn_80214A9C(entry->groupId);
        byteOffset += 8;
        i += 1;
    }
}
#pragma pop
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline fn_80246DE8
#pragma dont_inline fn_80246DF4
#pragma dont_inline fn_80246E00
#pragma dont_inline fn_80247174
