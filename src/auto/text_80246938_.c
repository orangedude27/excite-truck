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
#pragma opt_propagation off
s32 fn_80246938(void) {
    register s32 z14 asm("r14");
    register s32 z18 asm("r18");
    register s32 index asm("r19");
    register s32 zero asm("r22");
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
        zero = 0;
        z14 = 0;
        z18 = 0;
        while (((s32 (*)(s32))fn_802E8690)(index) != 0) {
            frame.zero = zero;
            frame.text = (s32)lbl_80343720;
            frame.itemIndex = index;
            frame.values[0] = zero;
            frame.values[1] = 5;
            frame.values[2] = (s32)&frame.text;
            frame.values[3] = zero;
            frame.values[4] = zero;
            frame.values[7] = fn_80131234((s32 *)lbl_80343280);
            frame.values[6] = 3;
            frame.values[5] = (s32)&lbl_8055BE80;
            frame.values[8] = z14;
            frame.values[9] = zero;
            frame.values[12] = fn_80131234((s32 *)lbl_80343294);
            frame.values[11] = 3;
            frame.values[10] = (s32)&lbl_8055BE88;
            frame.values[13] = z18;
            frame.values[14] = zero;
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
#pragma opt_propagation reset

int fn_80246AA8(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668((void *)object);
    return object;
}

/* Destroys a PSSystem::SeqHeap object: installs its vtable, tears down the owned
 * resource at +0x18, and optionally frees the object storage. */
void *__dt__Q28PSSystem7SeqHeapFv_80246C48(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80343780;
        ((void (*)(s32, void *))fn_80235380)(*(s32 *)((char *)arg0 + 0x18), lbl_80343780);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
void fn_80246CAC(float volume) {
    /* Set the music master volume (fn_8020A5F8) to volume scaled by the level saved when demo mode began (lbl_8055F264); 0.0 silences playback. */
#define SAVED_DEMO_VOLUME lbl_8055F264
    fn_8020A5F8(volume * SAVED_DEMO_VOLUME);
#undef SAVED_DEMO_VOLUME
}
#pragma dont_inline reset

extern char lbl_803436C0[];
extern void fn_80216CA8(void);
extern void fn_802146BC(void *, s32, s32, s32);
#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 3
#pragma opt_propagation off
/* Build a logo-layout menu descriptor from a layout filename (e.g. "LogoNint.lyt") and open it.
   The descriptor has a text block, an item list that points to it and copies five shared globals,
   and a menu argument block; fn_80216CA8 prepares it before fn_802146BC displays it. */
void fn_80246CB8(void *layoutName) {
    s32 text[12];
    s32 item[10];
    s32 menu[6];
    s32 textAddr = (s32)text;
    s32 layoutAddr = (s32)layoutName;
    text[5] = 0;
    text[0] = (s32)lbl_803436C0;
    text[8] = 2500;
    text[9] = 1;
    text[10] = 0;
    text[7] = fn_802E2C20();
    text[6] = 1;
    item[1] = 5;
    item[0] = 0;
    item[2] = textAddr;
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
    menu[0] = layoutAddr;
    menu[1] = (s32)item;
    fn_80216CA8();
    fn_802146BC(menu, -999, -999, 1);
}
#pragma pop

int fn_80246DA8(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree
     * when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668((void *)object);
    return object;
}

void fn_80246DE8(void) {
    /* Show the Nintendo logo splash layout ("LogoNint.lyt"). */
    fn_80246CB8(lbl_803432EC);
}

extern unsigned char lbl_803432FC[];
/* Create the Monster-logo menu from the "LogoMnst.lyt" layout file. */
void fn_80246DF4(void) {
    fn_80246CB8(lbl_803432FC);
}

extern unsigned char lbl_8034330C[];
/* Create the Dolby-logo menu from the "LogoDlby.lyt" layout file. */
void fn_80246E00(void) {
    fn_80246CB8(lbl_8034330C);
}

int fn_80246E0C(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
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

    item[10] = lbl_804988F0[0];
    item[11] = lbl_804988F0[1];
    item[12] = lbl_804988F0[2];
    item[13] = lbl_804988F0[3];
    item[14] = lbl_804988F0[4];

    menu[1] = lbl_802FA3A0[1];
    menu[0] = lbl_802FA3A0[0];
    menu[2] = lbl_802FA3A0[2];
    menu[3] = lbl_802FA3A0[3];
    menu[4] = lbl_802FA3A0[4];
    menu[1] = (s32)item;

    res = ((s32 (*)(s32 *, s32, s32, s32, s32, s32, s32, s32))fn_802146BC)(
        menu, -999, -999, 1,
        menu[4], menu[3], menu[2], menu[0]);

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
#pragma push
#pragma processor 750
void fn_80247174(void) {
    register float divisor = lbl_805638A8;
    register float base = lbl_80563898;
    s32 i = 0;
    do {
        fn_80246CAC(base - (float)i / divisor);
        fn_80127464();
        fn_802E2D74(0x10);
        i++;
    } while (i < 0x32);
    fn_8020A634();
    fn_80246CAC(lbl_80563898);
}
#pragma pop

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
s32 fn_8024739C(void) {
    /* No-op hook: does nothing and returns 0. Kept out of line for its callers. */
    return 0;
}
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
extern void fn_802E6FBC(void), fn_80137C78(int);
extern char *fn_8000DC70(int);
extern void fn_800169F8(const char *, int);
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

/* The attract/demo main loop, which fn_8023B640 runs when the game comes up in
 * demo main mode: it turns the music on, puts the "uisingle" movie on screen and
 * then keeps asking fn_80247C18 -- which shows the attract menu and waits for the
 * demo's (or a waiting player's) choice -- what to do next.  Every code is one
 * entry of that menu's table: the two profile dialogs, the career and challenge
 * screens, head-to-head (with the missing-controller warning pop-up behind it), a
 * memory-card save, handing the profile to player 1, the other menus, and the
 * requests to reset or to drop back to the attract screen.  Only the profile
 * dialog leaves this stretch, and it sends the loop back to the menu at the top;
 * while it runs fn_80247624 reports the demo-mode flag this sets. */
#pragma push
#pragma use_lmw_stmw off
void fn_802473A4(void) {
#define gMessages       lbl_80343270 /* this file's strings, "pop_warn.lyt" first */
#define gDemoRunning    lbl_8055F260 /* fn_80247624 reports it */
#define gMenuFlag       lbl_8055D430 /* bit 0: the menu owns the screens */
#define gWarnLine1      lbl_80498980 /* the warning pop-up's two message entries */
#define gWarnLine2      lbl_8049898C
#define gWarnLine1Shown lbl_8055F269 /* their text has been asked for once */
#define gWarnLine2Shown lbl_8055F26A
#define gMessageStamp   lbl_8055E044 /* message-table generation stamp */
    char *messages = gMessages;
    int again;
    int priorSlot;

    gDemoRunning = 1;
    fn_8020A600();  /* let the music play */
    fn_802ECEC4();  /* and show the "uisingle" movie on its own */
    goto check_a;
    for (;;) {
        int action, saved, menuFlag;
    loop_top:
        fn_80019708(); /* forget a quit/reset an action may have asked for */
        again = 1;
        do {
            fn_80129AEC(0);
            /* the attract menu's choice, from fn_80247C18's entry table */
            action = fn_80247C18();
            switch (action) {
            case -1: fn_8024CF60(); break;   /* make a new profile */
            case 0: fn_8024CFB4(); break;    /* use an existing profile */
            case 1: fn_8027DDCC(0); break;   /* the three career screens */
            case 2: fn_8027DDCC(1); break;
            case 3: fn_8027DDCC(2); break;
            case 4: fn_80260954(0); break;   /* the two challenge screens */
            case 5: fn_80260954(1); break;
            case 6: /* head-to-head, then the warning pop-up if a pad is missing */
                saved = gMenuFlag; menuFlag = saved & 1; gMenuFlag = saved | 1;
                fn_8023BEA8();
                if (fn_802411D4() == 0) {
                    /* both lines of the pop-up are filled in lazily: ask for the
                     * text once, and re-resolve it whenever the message table has
                     * moved on since it was last read */
                    if (!gWarnLine1Shown) { fn_801312EC(gWarnLine1, messages + 0x114); gWarnLine1Shown = 1; }
                    if (!gWarnLine2Shown) { fn_801312EC(gWarnLine2, messages + 0x13c); gWarnLine2Shown = 1; }
                    if (*(unsigned int *)(gWarnLine1 + 8) != gMessageStamp) fn_80131318(gWarnLine1);
                    if (*(unsigned int *)(gWarnLine2 + 8) != gMessageStamp) fn_80131318(gWarnLine2);
                    fn_80214FD8(*(void **)(gWarnLine1 + 4), *(void **)(gWarnLine2 + 4));
                }
                gMenuFlag = (gMenuFlag & ~1) | menuFlag; break;
            case 7: /* a profile screen: save and leave the demo once the current
                     * profile slot reports itself unloaded */
                fn_80239F74(); fn_8000DA10();
                if (fn_8000DBAC()) { fn_802E6FBC(); again = 0; } break;
            case 8: fn_802E6FBC(); break;    /* write the memory-card save */
            case 9: /* hand the current profile slot over to player 1 */
                saved = gMenuFlag; menuFlag = saved & 1; gMenuFlag = saved | 1;
                fn_800169F8(fn_8000DC70(0), 0); fn_80137C78(1);
                priorSlot = fn_8000DA10(); fn_80137C84(fn_802E4A10(), priorSlot);
                fn_80129AEC(fn_802E4A10()); fn_8023BCEC(); gMenuFlag = (gMenuFlag & ~1) | menuFlag; break;
            case 10: fn_8025812C(); break;
            case 11: fn_8025C054(); break;
            case 12: fn_800196FC(); break;   /* ask for a quit/reset */
            case 13: fn_80161DE4(); fn_8027DE6C(); break;
            case 14: fn_80263F30(1,1,1); break;
            case 15: again = 0; break;       /* back out to the attract screen */
            case 16: case 17: break;         /* nothing bound to these entries */
            default: fn_802E317C(messages + 0x168); break;
            }
        } while (again);
        /* The attract screen runs until the profile dialog fn_8024CF54 reports
         * that the menu should come back; fn_80246AE8 always says it is still
         * running, so this only leaves through that goto. */
        do {
            if (fn_8024CF54()) goto loop_top;
    check_a:
            ;
        } while (fn_80246AE8());
        break;
    }
    gDemoRunning = 0;
#undef gMessages
#undef gDemoRunning
#undef gMenuFlag
#undef gWarnLine1
#undef gWarnLine2
#undef gWarnLine1Shown
#undef gWarnLine2Shown
#undef gMessageStamp
}
#pragma pop
char fn_80247624(void) {
    /* Returns lbl_8055F260, the flag raised by the attract/demo (kiosk)
     * selection flow fn_80247210 while it runs; callers test it to take
     * demo-specific paths. */
    return lbl_8055F260;
}

s32 fn_8024762C(void) {
    /* Periodically toggles a UI state flag on/off based on the millisecond timer (on for 2/3 of each 1500ms cycle). */
    if (fn_802E2C20() % 1500 > 500) fn_80214AF0(1);
    else fn_80214A9C(1);
    return 0;
}

#pragma scheduling invalid_target
/* Selects the current menu entry's default item, enables each selectable child
 * item (count from the menu config table at gMenuConfigTable[menuIndex].count),
 * then moves focus to item 0x14. */
void fn_8024768C(void) {
#define gSelectedMenuItem lbl_8055BEAC
#define gMenuConfigTable lbl_802FA3B4
#define gCurrentMenuIndex lbl_8055F26C
#define UI_SetSelectedItem fn_80214CB4
#define UI_EnableItem fn_80214B44
#define UI_FocusItem fn_80214A9C
    s32 itemIndex;

    UI_SetSelectedItem((s32)gSelectedMenuItem);
    itemIndex = 1;
    goto check;
loop:
    UI_EnableItem(itemIndex);
    itemIndex += 1;
check:
    if (itemIndex < *(s32 *)((char *)gMenuConfigTable + gCurrentMenuIndex * 0xC + 8))
        goto loop;
    UI_FocusItem(0x14);
#undef gSelectedMenuItem
#undef gMenuConfigTable
#undef gCurrentMenuIndex
#undef UI_SetSelectedItem
#undef UI_EnableItem
#undef UI_FocusItem
}
#pragma scheduling on
s32 fn_802476FC(void) {
    /* Enable menu item 4 when multiplayer is allowed and a menu is selected; otherwise disable it. */
    register s32 hasMultiplayerMenu = 0;
    UnkFunc setItemState;
    if (fn_802411D4() != 0 && lbl_8055F26C > 0) hasMultiplayerMenu = 1;
    if (hasMultiplayerMenu) setItemState = fn_80214B44;
    else setItemState = fn_80214B94;
    return (setItemState(4), 0);
}

extern s32 lbl_8055BEA8;
extern s32 lbl_8055BEBC;
s32 fn_80214D04(void);
/* Store the active UI window's menu index as the global selected menu item. */
void fn_80247768(void) {
#define gSelectedMenuItem lbl_8055BEAC
    gSelectedMenuItem = (void*)fn_80214D04();
#undef gSelectedMenuItem
}

extern void *lbl_8055BEB0;
extern s32 lbl_8055BEB8;
extern s32 lbl_8055F26C;
void fn_8024778C(void) {
    s32 current;
    s32 i;
    if (lbl_8055BEB8 != (current = lbl_8055F26C)) {
        lbl_8055BEB8 = current;
        switch (current) {
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
    switch (lbl_8055F26C) {
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
    i = 0;
    do {
        if (fn_8027B94C(i) == 0) {
            fn_80214A9C(i + 0xB);
        }
    } while (++i < 3);
}
extern void* lbl_8055BEB0;
extern s32 lbl_8055BEB4;
#define gSelectedMenuIndex lbl_8055BEB0 /* active UI window's menu index; mirrors fn_80247768 */
/* Store the active UI window's menu index as the global menu selection (mirrors fn_80247768's gSelectedMenuItem). */
void fn_80247880(void) {
    gSelectedMenuIndex = (void*)fn_80214D04();
}

#pragma optimization_level 4
void fn_802478A4(void) {
    extern s32 lbl_802FA3F0[];
    extern s32 lbl_8055BAC0, lbl_8055BABC, lbl_8055B860;
    struct Desc {
        s32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
        s32 b0, b1, b2, b3, b4, b5, b6, b7, b8, b9;
        s32 c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
        s32 d0, d1, d2, d3, d4, d5, d6, d7, d8, d9;
    } *data = (struct Desc *)((void *)0);
    struct Desc local;
    volatile s32 *q = (volatile s32 *)lbl_804988F0;
    volatile s32 *p = (volatile s32 *)lbl_802FA3F0;
    s32 b0 = lbl_804988F0[0];
    s32 b1, b2, b3, b4;
    s32 a0, a2, a3, a4;
    s32 stringBase;
    (void)data;

    b1 = q[1];
    local.a6 = 8;
    b2 = q[2];
    local.b1 = 8;
    a0 = *p++;
    stringBase = (s32)lbl_80343270;
    b3 = q[3];
    a2 = p[1];
    b4 = q[4];
    a3 = p[2];
    a4 = p[3];
    local.a7 = (s32)fn_8024778C;
    local.b2 = (s32)fn_80247880;
    local.a5 = (s32)&lbl_8055BAC0;
    local.b0 = (s32)&lbl_8055BABC;
    local.b3 = 1;
    local.a8 = 0;
    local.a9 = 0;
    local.b4 = 0;
    local.b5 = stringBase + 0x2A0;
    local.b6 = 0;
    local.b7 = 0;
    local.b8 = 3;
    local.b9 = 0;
    local.c0 = stringBase + 0x2AC;
    local.c1 = 0;
    local.c2 = 0;
    local.c3 = 4;
    local.c4 = 0;
    local.c5 = stringBase + 0x2B8;
    local.c6 = 0;
    local.c7 = 0;
    local.c8 = 5;
    local.c9 = 0;
    local.d0 = (s32)&lbl_8055B860;
    local.d1 = 6;
    local.d2 = 0;
    local.d3 = -1;
    local.d4 = 0x1B;
    local.d5 = b0;
    local.d6 = b1;
    local.d7 = b2;
    local.d8 = b3;
    local.d9 = b4;
    local.a0 = a0;
    local.a2 = a2;
    local.a3 = a3;
    local.a4 = a4;
    local.a1 = (s32)&local.a5;
    ((void (*)(s32 *, s32, s32, s32, s32, s32, s32, s32))fn_802146BC)(
        (s32 *)&local, -999, -999, 1, stringBase + 0x2A0,
        stringBase + 0x2AC, stringBase + 0x2B8, (s32)&local.a5);
}


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
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_80247A0C(void) {
    s32 var_r31;
    s32 a;
    s32 b;
    a = lbl_8055BEBC;
    b = lbl_8055BEA8;
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
        var_r31 += 1;
    } while (var_r31 < 2);
}
#pragma pop
// Caches the active UI window's current-menu index into the global menu-index state.
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
 char *base = lbl_80343270; s32 a; s32 *table; s32 b, missing, v, result, flag; struct Entry *entry;
 lbl_8055F26C = 0;
 a = fn_80161D50();
 b = fn_80161D14();
 { s32 d = b ^ a; s32 half = d >> 1; s32 masked = d & b; s32 diff = half - masked; if ((unsigned long)diff >> 31) {
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
 flag = 0; if (missing && lbl_8055F26C >= 2) flag = 1; entry = &frame.entries[frame.count++]; entry->id = 11; entry->enabled = flag;
 flag = 0; if (missing && lbl_8055F26C >= 3) flag = 1; entry = &frame.entries[frame.count++]; entry->id = 12; entry->enabled = flag;
 entry = &frame.entries[frame.count++]; entry->id = 13; entry->enabled = (int)b;
 b = fn_8027B9EC(1);
 flag = 0; if (b == 0 && lbl_8055BEA8 >= 5) flag = 1; entry = &frame.entries[frame.count++]; entry->id = 14; entry->enabled = flag;
 entry = &frame.entries[frame.count++]; entry->id = 15; entry->enabled = b;
 entry = &frame.entries[frame.count++]; entry->id = 16; entry->enabled = 0;
 v = fn_8000DA10();
 if (lbl_8055BEC0 < 0 || lbl_8055BEC0 != v) lbl_8055BEAC = (void *)table[0];
 lbl_8055BEC0 = v;
 frame.items[0] = 0; frame.items[1] = 5; frame.items[2] = (s32)&frame.title; frame.items[3] = 0; frame.items[4] = 0;
 frame.items[5] = (s32)&lbl_8055BAC0; frame.items[6] = 8; frame.items[7] = (s32)fn_8024768C; frame.items[9] = 0; frame.items[8] = 0;
 frame.items[10] = (s32)&lbl_8055BABC; frame.items[11] = 8; frame.items[12] = (s32)fn_80247768; frame.items[13] = 1; frame.items[14] = 0;
 frame.items[15] = (s32)&lbl_8055B860; frame.items[16] = 6; frame.items[17] = 0; frame.items[18] = -1; frame.items[19] = 0x1b;
 frame.items[20] = (s32)(base + 0x2ec); frame.items[21] = 0; frame.items[22] = 0; frame.items[23] = 1; frame.items[24] = 0;
 frame.items[25] = (s32)&lbl_8055BEC4; frame.items[26] = 0; frame.items[27] = 0; frame.items[28] = 2; frame.items[29] = 0;
 frame.items[30] = (s32)(base + 0x2a0); frame.items[31] = 0; frame.items[32] = 0; frame.items[33] = 3; frame.items[34] = 0;
 frame.items[36] = 0; frame.items[35] = (s32)(base + 0x2f8); frame.items[37] = 0; frame.items[38] = 6; frame.items[39] = 0;
 frame.items[40] = (s32)&lbl_8055BEA0; frame.items[41] = 0; frame.items[42] = 0; frame.items[43] = 8; frame.items[44] = 0;
 frame.items[45] = (s32)(base + 0x304); frame.items[46] = 0; frame.items[47] = 0; frame.items[48] = 12; frame.items[49] = 0;
 frame.items[50] = (s32)&lbl_8055BED0; frame.items[51] = 0; frame.items[52] = 0; frame.items[53] = 9; frame.items[54] = 0;
 frame.items[55] = (s32)&lbl_8055BED8; frame.items[56] = 0; frame.items[57] = 0; frame.items[58] = 10; frame.items[59] = 0;
 frame.items[60] = (s32)&lbl_8055BEE0; frame.items[61] = 0; frame.items[62] = 0; frame.items[63] = 11; frame.items[64] = 0;
 frame.items[66] = 0; frame.items[65] = (s32)&lbl_8055BEE8; frame.items[67] = 0; frame.items[68] = 16; frame.items[69] = 0;
 frame.items[70] = lbl_804988F0[0]; frame.items[71] = lbl_804988F0[1]; frame.items[72] = lbl_804988F0[2]; frame.items[73] = lbl_804988F0[3]; frame.items[74] = lbl_804988F0[4];
 for (;;) {
   s32 result;
   if (lbl_8055F270) result = 3;
   else if (lbl_8055F271) result = 6;
   else {
     frame.args[0] = ((s32 *)lbl_802FA418)[0]; frame.args[1] = ((s32 *)lbl_802FA418)[1]; frame.args[2] = ((s32 *)lbl_802FA418)[2]; frame.args[3] = ((s32 *)lbl_802FA418)[3]; frame.args[4] = ((s32 *)lbl_802FA418)[4];
     frame.args[0] = table[1]; frame.args[1] = (s32)frame.items;
     result = ((s32 (*)(void *, s32, s32, s32))fn_802146BC)(frame.args, -999, -999, 1);
   }
   if ((int)result == 3) {
      result = ((s32 (*)(void))fn_802478A4)();
      if (result != -1) { lbl_8055F270 = 1; frame.entries = 0; frame.count = 0; frame.capacity = 0; return result; }
      lbl_8055F270 = 0;
   } else if (result == 6) {
      result = ((s32 (*)(void))fn_80247AD0)();
      if (result != -1) { lbl_8055F271 = 1; frame.entries = 0; frame.count = 0; frame.capacity = 0; return result; }
      lbl_8055F271 = 0;
   } else break;
 }
 frame.entries = 0; frame.count = 0; frame.capacity = 0;
}
#pragma pop

#pragma pop
void *fn_80248140(void *object, int shouldDelete) {
    /* Destructor helper: clear embedded fields at offsets +0x18, +0x1C, +0x20, then optionally free the object. */
    if (object != 0) {
        if ((unsigned int)object + 0x18 != 0) {
            if ((unsigned int)object + 0x18 != 0) {
                *(int *)((char *)object + 0x18) = 0;
                *(int *)((char *)object + 0x1C) = 0;
                *(int *)((char *)object + 0x20) = 0;
            }
        }
        if (shouldDelete > 0) fn_80128668(object);
    }
    return object;
}

/* "logo_mover" (fn_802483E0): the animation of the "thankyou.lyt" text.  While
 * it runs it installs fn_802481A0 as the text drawer's position-warp hook. */
extern s32 lbl_8055F274;                /* ms stamp of when the animation started */
extern float lbl_805638AC, lbl_805638B0, lbl_805638B4, lbl_805638B8;
extern double sin(double);
/* The hook's curve: nine (screen x, vertical offset) control points, the x
 * values ascending from -200 to 200. */
typedef struct LogoCurvePoint { float x; float y; } LogoCurvePoint;
typedef struct LogoCurve { LogoCurvePoint point[9]; } LogoCurve;
extern float lbl_802FA430[18];
extern void *memcpy(void *, const void *, unsigned long);
extern float lbl_80563898, lbl_805638AC, lbl_805638B0, lbl_805638B4, lbl_805638B8;
#pragma push
#pragma processor 750
/* Position-warp hook of the "logo_mover" animation of the "thankyou.lyt" text
 * (installed by fn_802483E0 with fn_80232B80): the text drawer (fn_80231AF0)
 * runs every glyph position it places through here.  The time since the
 * animation started, less a 1500 ms delay, is turned into a 0..1 progress over
 * the following second, and `remaining` counts that back down from 1 to 0.  The
 * glyph is shaken sideways by 3.0 * sin(956 * remaining) and offset vertically
 * by the curve read off logoCurve at its x, scaled by `remaining`, so the text
 * settles onto the position it was given; outside that one-second window the
 * clamps leave `remaining` at 0 and the glyph passes through untouched. */
void fn_802481A0(float *outX, float *outY, float x, float y) {
#define startTime   lbl_8055F274 /* ms stamp fn_802483E0 took at the start */
#define one         lbl_80563898 /* 1.0f */
#define msPerSecond lbl_805638AC /* 1000.0f */
#define zero        lbl_805638B0 /* 0.0f */
#define shakeRate   lbl_805638B4 /* 956.0f radians per second */
#define shakeAmount lbl_805638B8 /* 3.0f pixels */
#define logoCurve   lbl_802FA430 /* the (x, offset) curve, copied below */

    typedef struct { float v[18]; } CurveCopy; /* nine LogoCurvePoint pairs */
    CurveCopy curve;
    float xLow, xHigh, yLow, yHigh, frac;
    float progress, remaining;
    float rawFrac;
    s32 ms, high, offHigh, offLow;

    ms = (fn_802E2C20() - startTime) - 0x5DC; /* 1500 ms before it starts */
    progress = (one < (float)ms / msPerSecond) ? one : (float)ms / msPerSecond;
    progress = (progress > zero) ? progress : zero;
    remaining = one - progress;
    *outX = x + (shakeAmount * (float)sin(shakeRate * remaining));
    curve = *(CurveCopy *)logoCurve;
    for (high = 1; high < 8; high++) {
        if (x < curve.v[high * 2]) break;
    }
    offHigh = high * 8;
    offLow = (high - 1) * 8;
    xLow = *(float *)((char *)curve.v + offLow);
    xHigh = *(float *)((char *)curve.v + offHigh);
    yHigh = *(float *)((char *)curve.v + 4 + offHigh);
    yLow = *(float *)((char *)curve.v + 4 + offLow);
    rawFrac = (x - xLow) / (xHigh - xLow);
    if (one < rawFrac) {
        frac = one;
    } else {
        frac = rawFrac;
    }
    frac = (frac > zero) ? frac : zero;
    *outY = y + (remaining * (yLow + (frac * (yHigh - yLow))));

#undef startTime
#undef one
#undef msPerSecond
#undef zero
#undef shakeRate
#undef shakeAmount
#undef logoCurve
}
#pragma pop
void fn_80248398(void) {
    /* Sync cached UI state from the global object, arming two update blocks and clearing its active flag. */
#define gStateObject lbl_8055F278
#define gBaseOffset  lbl_8055BEF0
    s32 targetOffset;
    s32 baseA;
    s32 baseB;
    lbl_8055F278_struct *state;

    state = (lbl_8055F278_struct *)gStateObject;
    if (state != 0) {
        baseA = state->unk04;
        baseB = state->unk08;
        targetOffset = gBaseOffset + baseA;
        state->unk50 = 1;
        state->unk48 = targetOffset;
        state->unk4C = baseB;
        state = (lbl_8055F278_struct *)gStateObject;
        state->unk5C = 1;
        state->unk54 = baseA;
        state->unk58 = baseB;
        state->unk44 = 0;
    }
#undef gStateObject
#undef gBaseOffset
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
void fn_802483E0(void)
{
  struct Object
  {
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
  struct Frame
  {
    volatile s32 args[5];
    s32 text[11];
    s32 item[20];
    struct Object object;
  } frame;
  register s32 *textPtr = frame.text;
  register s32 zero = 0;
  register s32 one;
  register struct Object *objectPtr;
  textPtr[5] = zero;
  textPtr[0] = (s32) lbl_803436C0;
  textPtr[8] = 0x1388;
  textPtr[9] = zero;
  textPtr[10] = zero;
  textPtr[7] = fn_802E2C20();
  one = 1;
  textPtr[6] = one;
  frame.object.unk14 = zero;
  frame.object.vtable = lbl_803437E0;
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
  frame.item[0] = (s32) (&lbl_8055BAC0);
  frame.item[2] = (s32) fn_80248398;
  frame.item[3] = zero;
  frame.item[4] = zero;
  frame.item[6] = 5;
  frame.item[5] = (s32) lbl_80343590;
  objectPtr = &frame.object;
  frame.item[7] = (s32) objectPtr;
  frame.item[8] = zero;
  frame.item[9] = zero;
  frame.item[11] = 5;
  frame.item[10] = zero;
  frame.item[12] = (s32) textPtr;
  frame.item[13] = zero;
  frame.item[14] = zero;
  frame.item[15] = lbl_804988F0[0];
  frame.item[16] = lbl_804988F0[1];
  frame.item[17] = lbl_804988F0[2];
  frame.item[18] = lbl_804988F0[3];
  frame.item[19] = lbl_804988F0[4];
  lbl_8055F274 = fn_802E2C20();
  frame.args[1] = lbl_802FA478[1];
  frame.args[2] = lbl_802FA478[2];
  frame.item[8] = zero;
  frame.args[3] = lbl_802FA478[3];
  frame.args[0] = lbl_802FA478[0];
  frame.args[4] = lbl_802FA478[4];
  lbl_8055F278 = objectPtr;
  frame.args[1] = (s32) frame.item;
  fn_80232B80((s32) fn_802481A0);
  fn_802146BC((void *) frame.args, -999, -999, 1);
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
/* Destructor-like helper: reset key fields and optionally free the object. */
void* fn_8024859C(void *object, s32 shouldDelete) {
    if (object != 0) {
        *(unsigned char *)((unsigned char *)object + 0x18) = 0;
        *(unsigned char *)((unsigned char *)object + 0x50) = 0;
        *(unsigned char *)((unsigned char *)object + 0x5C) = 0;
        *(s32 *)((unsigned char *)object + 0x24) = 1;
        *(s32 *)((unsigned char *)object + 0x20) = 0;
        *(unsigned char *)((unsigned char *)object + 0x44) = 0;
        if (shouldDelete > 0) fn_80128668(object);
    }
    return object;
}
#pragma scheduling on
/* Secret key-code check: copies the trigger sequence stored in .rodata (device 1
 * key codes 0x126, 0x128, 0x125, 0x127, then the 0 terminator) and asks the
 * debug input history (fn_802E499C, filled by fn_802E4800) whether those keys
 * were the last ones entered.  If they were, the music is silenced -
 * fn_80246CAC scales its argument by the volume saved when the demo mode
 * started, so 0.0 is silence - and the pre-race music hook is called.
 * Always returns 0. */
s32 fn_802485FC(void) {
#define keySequence lbl_802FA48C /* the key codes that trigger this */
#define silenceVolume lbl_805638B0 /* 0.0f */
    unsigned short sequence[5];
    unsigned short *next = keySequence;

    sequence[0] = *next++;
    sequence[1] = *next++;
    sequence[2] = *next++;
    sequence[3] = *next++;
    sequence[4] = *next++;
    if (fn_802E499C(sequence, sequence[3], sequence[2], sequence[1], sequence[0]) != 0) {
        fn_80246CAC(silenceVolume);
        fn_8020C918(1);
    }
#undef keySequence
#undef silenceVolume
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
    if (fn_8020A640() != 0)
        return;
    fn_8020A600();
    text[5] = 0;
    text[0] = (s32)lbl_803436C0;
    text[8] = 30000;
    text[9] = 1;
    text[10] = 0;
    text[7] = ((s32 (*)(void *))fn_802E2C20)(lbl_803436C0);
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
    menu[1] = lbl_802FA498[1];
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

void fn_80248770(void *group) {
    /* Activate a UI window group: mark it enabled and allocate a group id from
     * the free-id bitmask. The id is later passed to UIWindow_Show/HideGroup. */
    #define AllocGroupId fn_80221EA8  /* returns the index of the first free group id (first set bit) */
    #define GROUP_ACTIVE 0x18         /* u8 enabled flag */
    #define GROUP_ID     0x1C         /* s32 allocated group id */
    *(unsigned char*)((char*)group + GROUP_ACTIVE) = 1;
    *(s32*)((char*)group + GROUP_ID) = AllocGroupId();
    #undef GROUP_ID
    #undef GROUP_ACTIVE
    #undef AllocGroupId
}

// Deactivate a UI window group by clearing its enabled flag (counterpart of fn_80248770).
void fn_802487A8(void *group) {
    #define GROUP_ACTIVE 0x18  /* u8 enabled flag */
    *(unsigned char*)((char*)group + GROUP_ACTIVE) = 0;
    #undef GROUP_ACTIVE
}

#pragma push
#pragma opt_propagation off
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
 t>lbl_805638B0?t*((lbl_805638C4*t)*t)+((lbl_805638B8*t)*t):
 t*((lbl_805638C4*t)*t)-((lbl_805638B8*t)*t);
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
// Reset this element's local X scroll offset (+0x1C) to lbl_805638B0 (0.0f).
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
    /* Handle confirm input: if not ready and input is 13, trigger close. */
    #define objReady  (*(unsigned char *)((char *)arg0 + 0x1C))

    if (objReady == 0 && arg1 == 13) {
        fn_80221F94(arg0, 0);
        return 1;
    } else {
        return 0;
    }

    #undef objReady
}

#define FADE_ZERO      lbl_805638B0 /* 0.0f */
#define FADE_ONE       lbl_80563898 /* 1.0f */
#define FADE_MILLIS    lbl_805638D0 /* 500.0f: length of a fade ramp, in ms */
#define FADE_ALPHA_MAX lbl_805638D4 /* 255.0f */
#define FADE_ROUND     lbl_805638D8 /* 0.5f, added for round-to-nearest */
extern float lbl_805638D0, lbl_805638D4, lbl_805638D8;
extern s32 fn_802C942C(s32);
void fn_80248CD8(void *effect)
{
  register s32 elapsed;
  s32 duration;
  s32 alpha;
  s32 truncated;
  s32 nonNegative;
  float factor;
  float scaled;
  float endFade;
  float rounded;
  s32 now;
  /* Drive a white overlay's alpha: opaque at the start, clear through the
   * middle, opaque again at the end, then apply it as ARGB. */
  now = fn_802E2C20();
  factor = FADE_ZERO;
  elapsed = now - (*((s32 *) (((char *) effect) + 0x1C)));
  if (elapsed < 0x1F4)
  {
    factor = (factor > (FADE_ONE - (((float) elapsed) / FADE_MILLIS)))
      ? factor : (FADE_ONE - (((float) elapsed) / FADE_MILLIS));
  }
  duration = *((s32 *) (((char *) effect) + 0x20));
  if ((duration != 0) || ((*((s32 *) (((char *) effect) + 0x18))) != 1))
  {
    if (elapsed > (duration - 0x1F4))
    {
      endFade = FADE_ONE - (((float) (duration - elapsed)) / FADE_MILLIS);
      factor = (factor > endFade) ? factor : endFade;
    }
  }
  scaled = FADE_ALPHA_MAX * factor;
  if (scaled < FADE_ZERO)
  {
    rounded = scaled - FADE_ROUND;
  }
  else
  {
    rounded = FADE_ROUND + scaled;
  }
  truncated = (s32) rounded;
  nonNegative = truncated & (((-truncated) & (~truncated)) >> 31);
  alpha = (nonNegative < 0xFF) ? nonNegative : 0xFF;
  fn_802C942C((alpha << 24) | 0xFFFFFF);
}

#pragma push
#pragma scheduling invalid_target
void fn_80248E30(void *arg0) {
    extern float lbl_805638DC;
    extern char lbl_803438A0[];
    extern void fn_8020A634(void);
    extern s32 fn_8020A640(void);
    extern void fn_80221F94(void *, s32);
    register s32 now;
    s32 duration;
    register s32 elapsed;

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
            float factor = lbl_80563898;
            float value = (float)(duration - elapsed) / lbl_805638DC;
            factor = factor < value ? factor : value;
            factor = factor > lbl_805638B0 ? factor : lbl_805638B0;
            fn_80246CAC(factor);
        }
    }

    if (now > *(s32 *)((char *)arg0 + 0x1C) +
              *(s32 *)((char *)arg0 + 0x20)) {
        switch (*(s32 *)((char *)arg0 + 0x18)) {
        case 1: fn_80221F94(arg0, -0xEA); break;
        case 4: fn_80221F94(arg0, -1); break;
        case 2: fn_80221F94(arg0, -2); break;
        default: fn_802E317C(lbl_803438A0, *(s32 *)((char *)arg0 + 0x18)); break;
        }
        if ((*(s32 *)((char *)arg0 + 0x28) &
             *(s32 *)((char *)arg0 + 0x18)) != 0 &&
            fn_8020A640() != 0) {
            fn_8020A634();
            fn_80246CAC(lbl_80563898);
        }
    }
}
#pragma pop
s32 fn_80248FB0(void *stunt, s32 button) {
    s32 nowMs, startMs, durationMs;
    /* Timed input window for a stunt tracker (+0x18 state, +0x1C start ms,
     * +0x20 duration ms, +0x24 enabled-button mask): while ready (state 1)
     * and inside the window, an enabled button 13/27 press moves the state
     * to 2/4 and restarts the window. */
    nowMs = fn_802E2C20();
    startMs = *(s32 *)((char *)stunt + 0x1C);
    if (nowMs < startMs + 750) return 0;
    durationMs = *(s32 *)((char *)stunt + 0x20);
    if (durationMs != 0 && nowMs - startMs > durationMs - 500) return 0;
    if (*(s32 *)((char *)stunt + 0x18) != 1) return 0;
    switch (button) {
    case 27:
        if (*(s32 *)((char *)stunt + 0x24) & 2)
            *(s32 *)((char *)stunt + 0x18) = 4;
        else return 0;
        break;
    case 13:
        if (*(s32 *)((char *)stunt + 0x24) & 1)
            *(s32 *)((char *)stunt + 0x18) = 2;
        else return 0;
        break;
    default: return 0;
    }
    *(s32 *)((char *)stunt + 0x1C) = nowMs - *(s32 *)((char *)stunt + 0x20) + 500;
    return 1;
}
#pragma scheduling on
/* Initializes the object: clears the flag byte at +0x1C, records the current time at +0x18, and triggers action 1 or 2 depending on fn_802C9A58(). */
void fn_802490AC(void *obj) {
    unsigned char *objBytes = (unsigned char *)obj;

    *(objBytes + 0x1C) = 0;
    *(s32 *)((char *)obj + 0x18) = fn_802E2C20();
    if (fn_802C9A58() != 0) {
        fn_80214A9C(1);
    } else {
        fn_80214A9C(2);
    }
}

void fn_80249104(void *arg0) {
    /* The wait state fn_802490AC sets up in this object. */
    struct WaitTimer {
        char pad[0x18];
        s32 startTime;        /* +0x18 fn_802E2C20() millisecond stamp */
        unsigned char waited; /* +0x1C cleared on start, set to stop the timeout */
    };
    struct WaitTimer *wait = (struct WaitTimer *)arg0;

    if (wait->waited == 0 && fn_802E2C20() - wait->startTime >= 15000) {
        fn_802168BC(-2);
    }
}

/* Screen wait timeout (1.5 s): while the object's "waited" byte (+0x1C) is still clear
 * 1500 ms after the start stamp taken at +0x18, ask the screen loop to exit with code -2.
 * Returns 1 so the caller keeps the wait running. */
s32 fn_80249154(void *arg0) {
    /* The wait state fn_802490AC sets up in this object. */
    struct WaitTimer {
        char pad[0x18];
        s32 startTime;        /* +0x18 fn_802E2C20() millisecond stamp */
        unsigned char waited; /* +0x1C cleared on start, set to stop the timeout */
    };
    struct WaitTimer *wait = (struct WaitTimer *)arg0;

    if (wait->waited == 0 && fn_802E2C20() - wait->startTime >= 1500) {
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
    int obj;
    int i = 0;
    int selected;
    float scale = lbl_805638E0;
    float sub = lbl_805638E4;
    float origin = lbl_805638E8;
    float xOrigin = lbl_805638EC;
    float yOrigin = lbl_805638F8;
    for (; i < *(int *)(base + 0x24); i++) {
        float fi = (float)i;
        float offset;
        float x;
        selected = i == *(int *)(base + 0x28);
        offset = scale * (fi - *(float *)(base + 0x2C)) - sub;
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
