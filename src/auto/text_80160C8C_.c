// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

#pragma cplusplus on
struct Dummy_80161D50 {
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
    virtual int test(const char *, int);
};
struct Dummy_801616FC_A {
    virtual void v0();
    virtual void v1();
    virtual void invoke();
};
struct Dummy_801616FC_B {
    virtual void reset(int);
};
#pragma cplusplus off

extern s32 *__AXFXGetLfoSinTable_801769CC(void);
extern void fn_801796BC(unsigned char);
extern void *fn_8001285C();
extern void *fn_801284F8(s32, void *);
extern char lbl_8032F5DC[];
extern char lbl_8032F71C[];
extern char lbl_8032F760[];

#pragma cplusplus on
struct Obj_80161C94 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual s32 f6(const void *, s32); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual s32 f21(void *);
};
#pragma cplusplus off

extern s32 lbl_8055A0E0;
extern s32 lbl_8055A0E8;

extern int fn_801C5B60(void);
extern void fn_801DF074(int, int);
extern int fn_801B2F24(void);
extern void fn_80276DC8(int);
extern void fn_80176734(void);
extern s32 fn_80161C38(void);

#pragma cplusplus on
struct Obj_80164CDC {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void *, void *);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};
static inline void fn_80164CDC_call(void *arg0) {
    ((Obj_80164CDC *)*(void **)((char *)arg0 + 4))->f4(&lbl_8055A0E0, &lbl_8055A0E8);
}
#pragma cplusplus off


#pragma cplusplus on
struct Dummy_80163550 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual s32 f7(); virtual s32 f8();
};

/* One goal of a tutorial level, made from a child of its "tutorial_level"
   node (fn_80160CF4): the kind of event that meets it (-1 until the level
   script picks one), how much of that is needed, and whether it is met. */
struct TutorialGoal {
    s32 type;
    s32 target;
    u8 met;
};

/* The tutorial level object (vtable lbl_8032F858, 0x5BC bytes). */
struct TutorialLevel {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6();
    virtual s32 f7();                  // 0x24: goals done / level over
    char pad4[0x570 - 0x4];
    TutorialGoal *goals;               // 0x570: goalCount goals of 0xC bytes
    s32 goalCount;                     // 0x574
    char pad578[0x5AC - 0x578];
    s32 metCount;                      // 0x5AC: goals met so far
};

/* Vehicle type FourCC at +0x10 of the trucks in the car table lbl_804348E8
   ('CAR ', 'PCAR', 'ACAR', 'NCAR', 'TRLR' all appear in the game). */
#define CAR_TAG_PLAYER_CAR 0x50434152 /* 'PCAR' */
#pragma cplusplus off

extern s32 fn_8000DA10(void);
extern void fn_801332D0(s32, s32, s32 *);
extern void fn_80160CF4(void);
extern s32 lbl_8055A0B0;
extern s32 lbl_8055A0B4;
extern s32 lbl_8055A0B8;
extern s32 lbl_8055A0C0;
extern u8 lbl_8055E2DC;

extern s32 fn_80161E40(s32);

extern void *lbl_8055E2E0;
extern int fn_801476C4(void);
extern float lbl_8056185C;
extern float lbl_8055E3C8;
extern float lbl_80561868;
extern int fn_80161BB8(void);
extern unsigned char lbl_8032FCB0[];
extern int lbl_804348E8[];
extern float lbl_80561848;
extern unsigned char lbl_8042FDEC[0x10];
extern int lbl_8055E304;
extern s32 lbl_8055A0E0;
extern s32 lbl_8055A0E8;
extern u8 lbl_8055E2DD;

#pragma cplusplus on
struct Dummy_801619A8 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
#pragma cplusplus off

#pragma cplusplus on
struct Dummy_801638A0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s32 f7();
    virtual s32 f8();
    virtual s32 f9();
    virtual s32 f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22(s32);
    virtual void f23();
    virtual void f24(s32);
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35(void *, s32);
    virtual void f36();
    virtual void f37(void *, s32);
};
#pragma cplusplus off

#pragma cplusplus on
struct Dummy_80163F7C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual const char *f6(const char *, const char *);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual s32 f12(const char *, s32);
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual s32 f23(const char *, ...);
};
struct Dummy_80163F7C_VT1 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual const char *f4(const char *, const char *);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual s32 f10(const char *, s32);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual s32 f21(const char *);
    virtual void f22();
    virtual void f23();
};
struct Dummy_80163F7C_VT3 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual const char *f4(const char *, const char *);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual s32 f10(const char *, s32);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual s32 f21(const char *, s32, void *);
    virtual void f22();
    virtual void f23();
};
extern "C" {
static inline s32 fn_80163F7C_method_flag(void *obj, const char *key, s32 value) {
    return ((Dummy_80163F7C_VT1 *)obj)->f10(key, value);
}
static inline const char *fn_80163F7C_method_string(void *obj, const char *key, const char *fallback) {
    return ((Dummy_80163F7C_VT1 *)obj)->f4(key, fallback);
}
static inline s32 fn_80163F7C_method_has(void *obj, const char *key) {
    return ((Dummy_80163F7C_VT1 *)obj)->f21(key);
}
static inline s32 fn_80163F7C_method_read(void *obj, const char *key, s32 index, void *data) {
    return ((Dummy_80163F7C_VT3 *)obj)->f21(key, index, data);
}
}
#pragma cplusplus off

extern s32 lbl_8055E300;
extern unsigned char lbl_8032F858[];
extern int lbl_8055E2E4;
extern int lbl_8055A0F8;
extern int lbl_8055A100;
extern f32 lbl_80561860;
extern s32 fn_80131234(void *);
extern int lbl_8055E2E8;
extern int lbl_8055E2EC;
extern int lbl_8055E2F0;
extern int lbl_8055E2F4;
extern int lbl_8055E2F8;
extern int lbl_8055E2FC;
extern unsigned char lbl_8032F588[];

// Names inside the UI string pool at lbl_8032F588, as offsets into it.  The
// HUD manager (lbl_8055E2E0) looks elements up by name; fn_80131234() looks a
// message up in the game's message table by its "Group:NAME" key.
#define UI_RESULTS_ART   0x4C8 // "results_art":  banner graphic
#define UI_RESULTS_TITLE 0x4D4 // "results1":     banner title text element
#define UI_RESULTS_BODY  0x57C // "results2":     banner body text element
#define UI_CONTINUE      0x110 // "continue":     "press on" prompt
#define MSG_PASSED_HEAD  0x4E0 // "Tutorial:PASSED_HEAD"
#define MSG_PASSED_BODY  0x4F8 // "Tutorial:PASSED_BODY"
#define MSG_FAILED_HEAD  0x510 // "Tutorial:FAILED_HEAD"
#define MSG_FAILED_STUNT 0x528 // "Tutorial:FAILED_BODY_STUNT"
#define MSG_FAILED_CRASH 0x544 // "Tutorial:FAILED_BODY_CRASH"
#define MSG_FAILED_TIME  0x560 // "Tutorial:FAILED_BODY_TIME"
// How the tutorial was lost, in the HUD object's word at +8.
#define FAIL_REASON_STUNT 4
#define FAIL_REASON_CRASH 2
extern void *fn_80145E70(void *);
extern void *fn_802CAC28(void *, int);
extern void *fn_8023512C(void *);
void* fn_80160C8C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma dont_inline on
s32 fn_80160CE4(void) {
    return lbl_8055A0B8 - lbl_8055A0C0;
}

#pragma cplusplus on
extern "C" char lbl_8032F790[];
extern "C" void fn_80158558(void *);
extern "C" int stricmp(const char *, const char *);
extern "C" char lbl_8055A0D4;
extern "C" f32 lbl_8056183C;
extern "C" char lbl_8055A0C4;
extern "C" char lbl_8055A0CC;
extern "C" f32 lbl_80561838;
extern "C" f32 lbl_80561840;
extern "C" void fn_80160CF4(void) {
    struct Node {
        virtual void s0();
        virtual void s1();
        virtual const char *name();
        virtual void s3();
        virtual void s4();
        virtual const char *attr(const char *);
        virtual void s6();
        virtual s32 attrInt(const char *);
        virtual void s8();
        virtual void s9();
        virtual f32 attrF(const char *, f32);
        virtual void s11();
        virtual s32 attrB(const char *, s32);
        virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
        virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22();
        virtual void s23();
        virtual Node *child(s32);
    };
    struct Root { s32 pad[8]; Node *node; };
    char *text = (char *)lbl_8032F588;
    Root *root;
    Node *n;
    s32 idx = 1;
    f32 f31;
    root = (Root *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    lbl_8055E300 = 0;
    {
        s32 *obj = (s32 *)fn_801284F8(0xC, text + 0x48);
        if (obj != 0) *obj = (s32)lbl_8032F790;
        *(s32 *)(*(s32 *)lbl_8042FDEC + (*(s32 *)(lbl_8042FDEC + 4))++ * 4) = (s32)obj;
    }
    f31 = lbl_8056183C;
    for (n = root->node->child(0); n != 0; n = root->node->child(idx++)) {
        const char *kind;
        if (stricmp(n->name(), text + 0x54) != 0) continue;
        kind = n->attr((const char *)&lbl_8055A0C4);
        if (stricmp(kind, (const char *)&lbl_8055A0CC) == 0) {
            char *obj = (char *)fn_801284F8(0x5BC, text + 0x60);
            if (obj != 0) {
                *(s32 *)(obj + 4) = (s32)n;
                *(f32 *)(obj + 0x84) = n->attrF(text + 0x70, lbl_80561838);
                *(f32 *)(obj + 0xCC) = f31;
                *(s32 *)obj = (s32)lbl_8032F858;
                *(s32 *)(obj + 0x574) = 0;
                *(char *)(obj + 0x5B0) = n->attrB(text + 0x7C, 0);
                {
                    s32 j = 0;
                    Node *c;
                    for (c = n->child(0); c != 0; c = n->child(++j)) {
                        if (stricmp(c->name(), (const char *)&lbl_8055A0CC) == 0) {
                            s32 *ent = (s32 *)(*(char **)(obj + 0x570) + *(s32 *)(obj + 0x574) * 0xC);
                            const char *a;
                            *(s32 *)(obj + 0x574) += 1;
                            a = c->attr((const char *)&lbl_8055A0C4);
                            ent[0] = -1;
                            ent[1] = c->attrInt((const char *)&lbl_8055A0D4);
                        }
                    }
                }
                *(f32 *)(obj + 0x5B8) = n->attrF(text + 0x88, lbl_80561840);
                fn_80158558(obj + 0x56C);
            }
            *(s32 *)(*(s32 *)lbl_8042FDEC + (*(s32 *)(lbl_8042FDEC + 4))++ * 4) = (s32)obj;
        }
    }
}

#pragma pop

void *fn_801612BC(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((u32)arg0 + 0xE0 != 0) {
            if ((u32)arg0 + 0xE0 != 0) {
                ((s32 *)arg0)[56] = 0;
                ((s32 *)arg0)[57] = 0;
                ((s32 *)arg0)[58] = 0;
            }
        }
        if (arg0 != 0) {
            if ((u32)arg0 + 0x34 != 0) {
                if ((u32)arg0 + 0x34 != 0) {
                    ((s32 *)arg0)[13] = 0;
                    ((s32 *)arg0)[14] = 0;
                    ((s32 *)arg0)[15] = 0;
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_80161340(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((u32)arg0 + 0x34 != 0) {
            if ((u32)arg0 + 0x34 != 0) {
                ((s32 *)arg0)[13] = 0;
                ((s32 *)arg0)[14] = 0;
                ((s32 *)arg0)[15] = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_801613A0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma dont_inline on
s32 fn_801613E0(s32 arg0) {
    if (fn_80161C38() != 0) {
        switch (arg0) {
        case 3:
            lbl_8055E304 = 0;
            fn_80176734();
            return 1;
        }
    }
    return 0;
}
#pragma dont_inline reset

extern int lbl_8055A0DC;
extern f32 lbl_80561844;
extern void fn_80148070(void *, s32, s32);
extern void fn_80148134(f32 *, f32 *, s32, f32, f32);
extern void fn_800103B8(s32, s32, s32 *, s32, f32, f32, f32, f32, ...);
extern void fn_801473F8(void *, const char *, ...);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80161438(s32 arg0, s32 arg1, s32 arg_sp0) {
    struct Service {
        virtual void f0();
        virtual void *find(const char *);
        virtual void f2();
        virtual void *lookup(const char *);
        virtual s32 create(const char *);
    };
    struct Settings {
        s32 unk0;
        f32 value4;
        f32 value8;
        s32 valueC;
        f32 value10;
        s32 value14;
        s32 value18;
    };
    u8 *text = lbl_8032F588;
    f32 spC;
    f32 sp8;
    void *temp_r3;
    void *temp_r3_2;
    Settings *temp_r3_3;

    if (lbl_8055E2E0 != 0) {
        temp_r3 = ((Service *)lbl_8055E2E0)->lookup((const char *)text + 0xC8);
        if (temp_r3 != 0) {
            fn_80148070(temp_r3, 0x96FFFFFF,
                (s32)((Service *)lbl_8055E2E0)->create((const char *)text + 0xD4));
        }
        temp_r3_2 = ((Service *)lbl_8055E2E0)->lookup((const char *)text + 0xE4);
        if (temp_r3_2 != 0) {
            fn_80148070(temp_r3_2, -1,
                (s32)((Service *)lbl_8055E2E0)->create((const char *)text + 0xD4));
        }
        temp_r3_3 = (Settings *)((Service *)lbl_8055E2E0)->find((const char *)text + 0xF0);
        f32 value4 = temp_r3_3->value4;
        f32 value8 = *(volatile f32 *)((u8 *)temp_r3_3 + 8);
        s32 valueC = temp_r3_3->valueC;
        fn_80148134(&spC, &sp8, valueC, value4, value8);
        f32 firstValue = *(f32 *)((u8 *)temp_r3 + 0x10);
        f32 settingValue = temp_r3_3->value10;
        f32 delta = firstValue - lbl_80561844;
        fn_800103B8(temp_r3_3->value18, temp_r3_3->value14, (s32 *)&lbl_8055A0DC, arg1,
            settingValue, spC, sp8, delta);
        fn_801473F8(lbl_8055E2E0, (const char *)text + 0xFC,
            &lbl_8055A0DC, arg0);
        ((Service *)lbl_8055E2E0)->find((const char *)text + 0x110);
        fn_801476C4();
    }
}
#pragma cplusplus off
#pragma scheduling on

s32 fn_801615B4(s32 arg0) {
    s32 total = 0;
    s32 i = 0;
    goto test;
body:
    fn_80161E40(i);
    total = total + fn_8016208C();
    i = i + 1;
test:
    if (i < arg0) goto body;
    return total;
}

void fn_80161618(void) {
    /* Initialize runtime state: read a base value via fn_8000DA10 and register
       it (value+0xC) with fn_801332D0 using lbl_8055A0B0/lbl_8055A0B8, clear
       flags, run fn_80160CF4, cache the first item/id from the list at
       lbl_8042FDEC (or clear if count <= 1), then iterate all list items and
       invoke virtual slot1() on each. */
    s32 offset;
    s32 i;
    s32 value;
    void *item;
    value = fn_8000DA10();
    lbl_8055A0B8 = 1;
    fn_801332D0(value + 0xC, lbl_8055A0B0, &lbl_8055A0B8);
    lbl_8055E2DC = 0;
    lbl_8055A0B4 = lbl_8055A0B8;
    lbl_8055E2DD = 0;
    fn_80160CF4();
    if (*(s32 *)(lbl_8042FDEC + 4) > 1) {
        lbl_8055E304 = 0;
        lbl_8055E300 = **(s32 **)lbl_8042FDEC;
    } else {
        lbl_8055E300 = 0;
        lbl_8055E304 = -1;
    }
    i = 0;
    offset = 0;
    while (i < *(s32 *)(lbl_8042FDEC + 4)) {
        item = *(void **)(*(s32 *)lbl_8042FDEC + offset);
#pragma cplusplus on
        struct Interface {
            virtual void slot0();
            virtual void slot1();
            virtual void slot2();
            virtual void slot3();
        };
        ((struct Interface *)item)->slot1();
#pragma cplusplus reset
        offset += 4;
        i++;
    }
}

extern int fn_80133348(int, int, int);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801616FC(void) {
    register s32 *count_ptr;
    register s32 offset;
    register s32 count;
    void *item;

    fn_80133348(fn_8000DA10() + 0xC, lbl_8055A0B0, lbl_8055A0B8);
    count_ptr = (s32 *)((u8 *)lbl_8042FDEC + 4);
    count = 0;
    offset = 0;
    goto test_loop;
loop:
    item = *(void **)((u8 *)*(void **)lbl_8042FDEC + offset);
#pragma cplusplus on
    ((Dummy_801616FC_A *)item)->invoke();
#pragma cplusplus off
    item = *(void **)((u8 *)*(void **)lbl_8042FDEC + offset);
    if (item != 0) {
#pragma cplusplus on
        ((Dummy_801616FC_B *)item)->reset(1);
#pragma cplusplus off
    }
    offset += 4;
    count += 1;
test_loop:
    if (count < *count_ptr) {
        goto loop;
    }
    *count_ptr = 0;
    lbl_8055E300 = 0;
}
#pragma scheduling on
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void fn_802CAC54(int);
extern "C" void fn_80235380(int);
#pragma scheduling invalid_target
/* Loads global resource handles from named configuration entries, then calls setup() on each item in the global item list. */
extern "C" void fn_801617BC(void) {
    class Item {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void setup();
    };
    s32 itemOffset;
    s32 itemIndex;
    s32 *itemCountPtr;
    void *itemPtr;

    lbl_8055E2E0 = fn_80145E70(lbl_8032F588 + 0x11C);
    lbl_8055E2E4 = (int)fn_80145E70(lbl_8032F588 + 0x12C);
    lbl_8055E2E8 = (int)fn_802CAC28(lbl_8032F588 + 0x138, 0);
    lbl_8055E2EC = (int)fn_802CAC28(lbl_8032F588 + 0x148, 0);
    lbl_8055E2F0 = (int)fn_802CAC28(lbl_8032F588 + 0x158, 0);
    lbl_8055E2F4 = (int)fn_802CAC28(lbl_8032F588 + 0x168, 0);
    lbl_8055E2F8 = (int)fn_802CAC28(lbl_8032F588 + 0x178, 0);
    lbl_8055E2FC = (int)fn_8023512C(lbl_8032F588 + 0x188);

    itemCountPtr = (s32 *)(lbl_8042FDEC + 4);
    itemIndex = 0;
    itemOffset = 0;
    while (itemIndex < *itemCountPtr) {
        itemPtr = *(void **)(*(s32 *)lbl_8042FDEC + itemOffset);
        ((Item *)itemPtr)->setup();
        itemOffset += 4;
        itemIndex++;
    }
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801618B4(void) {
    /* Teardown counterpart to fn_801617BC: release global resource handles,
     * destroy the two UI screen objects, then call teardown() on each item in
     * the global item list (lbl_8042FDEC: items pointer at +0, count at +4). */
    class UIScreen {
    public:
        virtual void destroy(s32 shouldFree);
    };
    class ManagedItem {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void setup();
        virtual void teardown();
    };
    s32 itemOffset;
    s32 itemIndex;
    s32 *itemCountPtr;
    void *itemPtr;

    fn_802CAC54(lbl_8055E2E8);
    fn_802CAC54(lbl_8055E2EC);
    fn_802CAC54(lbl_8055E2F0);
    fn_802CAC54(lbl_8055E2F4);
    fn_802CAC54(lbl_8055E2F8);
    fn_80235380(lbl_8055E2FC);

    if (lbl_8055E2E0 != 0 && lbl_8055E2E0 != 0) {
        ((UIScreen *)lbl_8055E2E0)->destroy(1);
    }
    if (lbl_8055E2E4 != 0 && lbl_8055E2E4 != 0) {
        ((UIScreen *)lbl_8055E2E4)->destroy(1);
    }

    itemCountPtr = (s32 *)(lbl_8042FDEC + 4);
    itemIndex = 0;
    itemOffset = 0;
    while (itemIndex < *itemCountPtr) {
        itemPtr = *(void **)(*(s32 *)lbl_8042FDEC + itemOffset);
        ((ManagedItem *)itemPtr)->teardown();
        itemOffset += 4;
        itemIndex++;
    }
}

#pragma scheduling on
#pragma cplusplus reset
extern s32 lbl_8055A0B0;
extern s32 lbl_8055A0B8;
#pragma cplusplus on
extern "C" void fn_801619A8(void) {
    s32 index = lbl_8055E304;
    if (index >= 0 && index < *(s32 *)(lbl_8042FDEC + 4)) {
        lbl_8055E300 = *(s32 *)(*(char **)lbl_8042FDEC + index * 4);
    }
    if (lbl_8055E300 != 0) {
        ((Dummy_801619A8 *)lbl_8055E300)->f6();
    }
    lbl_8055E2DD = 0;
}
#pragma cplusplus on
extern "C" void fn_80161A18(void) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    Dummy *p = (Dummy *)lbl_8055E300;
    if (p != 0) {
        p->v5();
    }
}
#pragma cplusplus on
extern "C" void fn_80161A38(s32 arg0, s32 arg1, s32 arg2) {
    struct Dummy {
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
        virtual void call(s32, s32, s32);
    };
    Dummy *p = (Dummy *)lbl_8055E300;
    if (p != 0) {
        p->call(arg0, arg1, arg2);
    }
}
extern "C" s32 fn_80161A70(void) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual s32 f7();
        virtual s32 f8();
        virtual s32 f9();
        virtual s32 f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual s32 f15(s32);
        virtual s32 f16(s32);
    };
    if (lbl_8055E300 != 0) {
        if (((Dummy *)lbl_8055E300)->f7() != 0) {
            return ((Dummy *)lbl_8055E300)->f16(0);
        }
        return ((Dummy *)lbl_8055E300)->f15(0);
    }
    return 0;
}
extern "C" void fn_80161AEC(void) {
    Dummy_801638A0 *p = (Dummy_801638A0 *)lbl_8055E300;
    if (p != 0) {
        p->f17();
    }
}
#pragma cplusplus on
extern "C" int fn_800121A4(void);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" s32 fn_80161B0C(void) {
    if (lbl_8055E300 != 0 &&
        ((Dummy_801638A0 *)lbl_8055E300)->f10() != 0) {
        if (lbl_8055E2DD == 0) {
            fn_800121A4();
        }
        lbl_8055E2DD = 0;
        return 1;
    }
    return 0;
}
#pragma scheduling on
#pragma cplusplus reset
extern "C" f32 fn_80161B70(void) {
    struct Dummy {
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
        virtual f32 v11();
    };
    Dummy *p = (Dummy *)lbl_8055E300;
    if (p != 0) {
        return p->v11();
    }
    return lbl_80561848;
}
#pragma cplusplus on
extern "C" s32 fn_80161B94(void) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual s32 v9();
    };
    Dummy *p = (Dummy *)lbl_8055E300;
    if (p != 0) {
        return p->v9();
    }
    return 0;
}

#pragma cplusplus on
extern "C" int fn_80161BB8(void) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual int v7();
    };
    Dummy *p = (Dummy *)lbl_8055E300;
    if (p != 0) {
        return p->v7();
    }
    return 0;
}
#pragma cplusplus on
extern "C" s32 fn_80161BDC(s32 arg0, s32 arg1, s32 arg2) {
    struct Dummy {
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
        virtual s32 call(s32, s32, s32);
    };
    Dummy *p = (Dummy *)lbl_8055E300;
    if (p != 0) {
        return p->call(arg0, arg1, arg2);
    }
    return 0;
}
#pragma cplusplus off
void fn_80161C18(void) {
    void *obj = (void *)lbl_8055E300;
    if (obj != 0) {
#pragma cplusplus on
        struct Interface {
            virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
            virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
            virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
            virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
            virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
            virtual void slot20();
        };
        ((struct Interface *)obj)->slot20();
#pragma cplusplus reset
    }
}

s32 fn_80161C38(void) {
    s32 val = lbl_8055E300;
    u32 tmp = (u32)(-val) | (u32)val;
    return (s32)(tmp >> 31);
}

#pragma cplusplus on
extern "C" s32 fn_80161C4C(void) {
    struct Dummy {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual s32 v18();
    };
    Dummy *p = (Dummy *)lbl_8055E300;
    if (p != 0) {
        return p->v18();
    }
    return 1;
}
#pragma cplusplus on
extern "C" s32 fn_80161C70(void) {
    struct Dummy2 {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual s32 v19();
    };
    Dummy2 *p = (Dummy2 *)lbl_8055E300;
    if (p != 0) {
        return p->v19();
    }
    return 1;
}
extern "C" void **fn_80161C94(void) {
    void *manager;
    Obj_80161C94 *object;
    s32 result;
    void **allocated;

    manager = fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    object = (Obj_80161C94 *)*(void **)((u8 *)manager + 0x20);
    result = object->f21(lbl_8032F5DC);
    if (((u32)(-result | result) >> 31) != 0) {
        allocated = (void **)fn_801284F8(4, lbl_8032F71C);
        if (allocated != 0) {
            *allocated = lbl_8032F760;
        }
        return allocated;
    }
    return 0;
}
#pragma cplusplus off
s32 fn_80161D14(void) {
    s32 sp8;
    s32 temp = fn_8000DA10();
    sp8 = 1;
    fn_801332D0(temp + 0xC, lbl_8055A0B0, &sp8);
    return sp8;
}

extern char lbl_8032F72C[];
#pragma use_lmw_stmw off
#pragma dont_inline on
s32 fn_80161D50(void) {
    register s32 count;
    register s32 total;
    register s32 i;
    register void *item;
    s32 matched;

    count = fn_80161ECC();
    total = 0;
    i = 0;
    goto test_loop;
loop:
    fn_80161E40(i);
    item = fn_8001285C();
#pragma cplusplus on
    matched = ((Dummy_80161D50 *)*(void **)((u8 *)item + 0x20))->test(lbl_8032F72C, 0);
#pragma cplusplus off
    if (matched != 0) {
        total += fn_8016208C(*(s32 *)item);
    }
    i += 1;
test_loop:
    if (i < count) {
        goto loop;
    }
    return total;
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset

extern s32 fn_80012854();
extern const char lbl_8032F738[];

#pragma dont_inline on
void fn_80161DE4(void) {
    s32 total;
    s32 addition;
    total = fn_801615B4(fn_80161ECC() - 1);
    fn_80161E40(fn_80161ECC() - 1);
    addition = fn_8016208C();
    total = addition + total;
    fn_80133348(fn_8000DA10() + 0xC, lbl_8055A0B0, total + 1);
}

s32 fn_80161E40(s32 arg0) {
    s32 i;
    void *item;
    for (i = 0; i < fn_80012854(); i++) {
        item = fn_8001285C(i);
#pragma cplusplus on
        if (((Obj_80161C94 *)*(void **)((char *)item + 0x20))->f6(lbl_8032F738, -999) == arg0) {
            return i;
        }
#pragma cplusplus off
    }
    return -1;
}

#pragma dont_inline off
extern s32 fn_80012854();
extern const char lbl_8032F738[];

int fn_80161ECC(void) {
    int i = 0;
    while (fn_80161E40(i) >= 0)
        i++;
    return i;
}

#pragma push
#pragma use_lmw_stmw off
extern s32 fn_8000DB34(void);
extern void *fn_8001285C(void);
extern void *fn_80016464(s32);
extern void *fn_800165DC(s32);
extern void *fn_8001668C(s32);
extern s32 fn_80016544(s32);
extern s32 fn_800169F8(s32);
extern s32 fn_80016970(s32, s32, s32, s32);
extern s32 fn_8001EFC8(void);
extern s32 fn_80137C78(s32);
extern s32 fn_80137C80(s32);
extern s32 fn_80137C84(s32);
extern s32 fn_801615B4(s32);
extern s32 fn_80161D14(void);
extern s32 fn_8023BEC4(s32, void *);
extern s32 fn_802E4A10(void);
extern s32 fn_802E7128(void);
#pragma cplusplus on
struct Obj_80161F10 {
    virtual void unused0();
    virtual s32 has(const char *);
    virtual void unused2();
    virtual void *set(const char *);
    virtual void unused4();
    virtual s32 index(const char *);
};
#pragma cplusplus off
extern char lbl_8032F744[];
extern char lbl_8032F750[];
extern s32 lbl_8055A0BC;
extern s32 lbl_8055A0C0;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_80161F10(s32 arg0, s32 arg1) {
    s32 pad[0x2e];
    register const char *label1;
    register const char *label2;
    register s32 value;
    void *obj;
    s32 *manager;
    s32 *item;
    s32 selection;
    s32 index;

    fn_80161D14();
    value = fn_80161E40(arg0);
    obj = fn_8001285C();
    fn_80137C78(1);
    label1 = lbl_8032F744;
    label2 = lbl_8032F750;
    ((void (*)(s32, s32))fn_80137C84)(fn_802E4A10(), 0);
    manager = *(s32 **)((char *)fn_80016464(0) + 4);
    item = *(s32 **)((char *)fn_800165DC((s32)manager) + 4);
    if (((Obj_80161F10 *)*(void **)((char *)obj + 0x20))->has(label1)) {
        item = *(s32 **)((char *)((void *(*)(void *, s32))fn_8001668C)(
            ((Obj_80161F10 *)*(void **)((char *)obj + 0x20))->set(label1), 0) + 4);
    }
    selection = *(s32 *)((char *)fn_80016464((s32)manager) + 0x50);
    if (((Obj_80161F10 *)*(void **)((char *)obj + 0x20))->has(label2)) {
        index = ((Obj_80161F10 *)*(void **)((char *)obj + 0x20))->index(label2);
        selection = *(s32 *)((char *)fn_80016544((s32)item) + index * 4 + 0x64);
    }
    fn_8000DA10();
    ((s32 (*)(s32, s32))fn_800169F8)(fn_8000DB34(), 0);
    fn_80016970(0, (s32)manager, (s32)item, selection);
    lbl_8055A0BC = arg0;
    lbl_8055A0C0 = fn_801615B4(arg0);
    fn_8023BEC4(value, &pad[0]);
    lbl_8055A0BC = -1;
    lbl_8055A0C0 = -1;
    fn_80137C80(0);
    fn_8001EFC8();
    fn_80161D14();
    fn_802E7128();
}
#pragma cplusplus off
#pragma dont_inline reset
#pragma pop

#pragma push
#pragma use_lmw_stmw off
int fn_8016208C(void) {
    extern void *fn_8001285C();
    extern int stricmp(const char *, const char *);
    extern char lbl_8032F5DC[];
    void *mgr = fn_8001285C();
    int count = 0;
    int index = 0;
    void *obj;
    void *iter;
loop:
    obj = *(void **)((char *)mgr + 0x20);
    {
        volatile void **vt = *(volatile void ***)obj;
        int cur = index++;
        iter = ((void *(*)(void *, int))vt[0x60 / 4])(obj, cur);
    }
    if (iter == 0)
        goto done;
    {
        const char *name = ((const char *(*)(void *))(*(void ***)iter)[2])(iter);
        if (stricmp(name, lbl_8032F5DC) == 0)
            count++;
    }
    goto loop;
done:
    return count;
}
#pragma pop
s32 fn_8016212C(s32 arg0) {
    return fn_801613E0(arg0);
}

int fn_80162130(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_80162170(void) {

}

void fn_80162174(void) {
}

void fn_801F62178_dummy(void);
#pragma cplusplus on
extern "C" void fn_80162178(void *arg0, s32 arg1) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void *f4(s32 *, s32 *);
    };
    extern float lbl_8056184C;
    extern void fn_80161438(void);
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    s32 offset;
    s32 i;

    *(s32 *)((char *)arg0 + 8) = 0;
    *(u8 *)((char *)arg0 + 0x10) = 0;
    *(float *)((char *)arg0 + 0xC) = lbl_8056184C;
    for (i = 0, offset = 0; i < *(s32 *)((char *)arg0 + 0x38); offset += 8, i++) {
        void *obj = *(void **)((char *)arg0 + 4);
        char *entries = *(char **)((char *)arg0 + 0x34);
        s32 *entry = (s32 *)(entries + offset);
        void *result = ((Dummy *)obj)->f4(&lbl_8055A0E0, &lbl_8055A0E8);
        fn_801DF380(result, entry[0], fn_80161438, entry[1]);
    }
}
#pragma cplusplus off
void fn_80162214(void) {
    if (fn_801C5B60() == 0) {
        fn_801DF074(8, 0);
    }
}

int fn_80162248(void) {
    return 0;
}

int fn_80162250(void) {
    return 0;
}

void fn_80162258(void) {

}

void fn_8016225C(void) {
}

int fn_80162260(void) {
    return 0;
}

extern f64 fn_8002F234(f32);
extern f32 PSVECSquareDistance(void *, void *);
extern s32 fn_80139B5C(void *, s32);
extern void *fn_801B83A0(void);
extern f32 lbl_80561840, lbl_80561850, lbl_80561854, lbl_80561858;
extern f32 lbl_80558DC4[];
#pragma push
#pragma processor 750
void fn_80162268(void *arg0) {
    u8 *self = arg0;
    s32 i,j,offset;
    int *cars;
    u8 *car,*entry,*flags,*ui;
    f32 velocity[2], length, scale;
    f32 one, threshold, epsilon;
    if (fn_801C5B60() == 0) fn_801DF074(8,0);
    if (((s32 (*)(void *))(*(void ***)self)[9])(self) == 0) {
        one=lbl_80561840; threshold=lbl_80561854; epsilon=lbl_80561850;
        for (i=0,cars=lbl_804348E8; i<fn_801B2F24(); i++,cars++) {
            car=(u8 *)*cars;
            if (*(u32 *)(car+0x10) != 0x50434152) continue;
            for (j=0,offset=0; j<*(s32 *)(self+0xE4); j++,offset+=0x48) {
                entry=*(u8 **)(self+0xE0)+offset;
                if (!entry[0x3C]) continue;
                if (*(s32 *)(entry+0x34)) {
                    if (fn_80139B5C(car,*(s32 *)(entry+0x34))) {
                        flags=entry+i;
                        if (!flags[0x3D]) {
                            velocity[0]=*(f32 *)(car+0x118);
                            velocity[1]=*(f32 *)(car+0x120);
                            length=velocity[0]*velocity[0]+velocity[1]*velocity[1];
                            if (length>epsilon) {
                                scale=one/(f32)fn_8002F234(length);
                                velocity[0]*=scale;
                                velocity[1]*=scale;
                                if (velocity[0]* *(f32 *)(entry+0x2C)+velocity[1]* *(f32 *)(entry+0x30)>threshold) {
                                    ++*(s32 *)(self+0x94);
                                    entry[0x3C]=0;
                                    ui=*(u8 **)(self+0xDC);
                                    ui[0x49]=1; ui[0x4B]=0; ui[0x4A]=0;
                                }
                            }
                        }
                        flags[0x3D]=1;
                        break;
                    } else if (entry[0x3C]) (entry+i)[0x3D]=0;
                } else if (PSVECSquareDistance(entry,car+0x60)<*(f32 *)(self+0xCC)* *(f32 *)(self+0xCC)) {
                    ++*(s32 *)(self+0x94);
                    entry[0x3C]=0;
                    ui=*(u8 **)(self+0xDC);
                    ui[0x49]=1; ui[0x4B]=0; ui[0x4A]=0;
                    break;
                }
            }
        }
        *(f32 *)(self+0x98)+=lbl_80561858;
        if (*(f32 *)(self+0x98)>=*(f32 *)(self+0x84))
            ((void (*)(void *,s32))(*(void ***)self)[24])(self,3);
        if (*(s32 *)(self+0x94)>=*(s32 *)(self+0x80) && self[0x9C]) {
            ((void (*)(void *,s32))(*(void ***)self)[24])(self,1);
            self[0x88]=1;
        }
    } else {
        if ((f32)__fabs(*(f32 *)(self+0x8C))<=*(f32 *)&lbl_80558DC4) {
            fn_80276DC8(0);
            for(i=0,cars=lbl_804348E8;i<fn_801B2F24();i++,cars++) {
                void *manager=fn_801B83A0();
                ((void (*)(void *,s32,s32))(*(void ***)manager)[37])(manager,*cars,i);
            }
        }
        *(f32 *)(self+0x8C)+=lbl_80561858;
        if(self[0x90]) {
            if (((s32 (*)(void *))(*(void ***)self)[10])(self) && lbl_8055E304==fn_80160CE4()) {
                lbl_8055E2DC=1;
                lbl_8055A0B4=lbl_8055A0B8++;
            } else lbl_8055E2DC=0;
            lbl_8055E304=0;
            if (*(s32 *)(lbl_8042FDEC+4)>0) fn_80176734();
        }
    }
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801625E0(void *arg0) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void *f4(s32 *, s32 *);
    };
    extern float lbl_80561848;
    extern float lbl_8056184C;
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    extern void fn_801EA140(void *);
    extern void fn_802A95A8(f32 *, f32 *, f32, f32);
    extern void fn_802A95AC(s32);
    s32 i;
    u32 offset;
    float resetValue;

    /* Match note: mirror fn_80162178's virtual initializer and update records at 0x48-byte strides. */
    resetValue = lbl_8056184C;
    *(s32 *)((char *)arg0 + 8) = 0;
    *(u8 *)((char *)arg0 + 0x10) = 0;
    *(float *)((char *)arg0 + 0xC) = resetValue;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((char *)arg0 + 0x38)) {
        void *obj = *(void **)((char *)arg0 + 4);
        char *entries = *(char **)((char *)arg0 + 0x34);
        s32 *entry = (s32 *)(entries + offset);
        void *result = ((Dummy *)obj)->f4(&lbl_8055A0E0, &lbl_8055A0E8);
        fn_801DF380(result, entry[0], (void (*)())fn_80161438, entry[1]);
        offset += 8;
        i++;
    }

    resetValue = lbl_80561848;
    *(s32 *)((char *)arg0 + 0x94) = 0;
    *(float *)((char *)arg0 + 0x98) = resetValue;
    *(u8 *)((char *)arg0 + 0x88) = 0;
    *(float *)((char *)arg0 + 0x8C) = resetValue;
    *(u8 *)((char *)arg0 + 0x90) = 0;
    *(u8 *)((char *)arg0 + 0x91) = 0;
    *(u8 *)((char *)arg0 + 0x9C) = 1;
    {
        s32 offset;
        s32 i;
        for (i = 0, offset = 0; i < *(s32 *)((char *)arg0 + 0xE4); i++, offset += 0x48) {
            char *obj = (char *)*(void **)((char *)arg0 + 0xE0) + offset;
            fn_801EA140(obj);
            *(float *)(obj + 4) += *(float *)(obj + 0x38);
            if (*(s32 *)(obj + 0x34) != 0) {
                char *child;
                u32 j;
                for (j = 0, child = obj + 0xC; j < 2; j++, child += 0xC) {
                    fn_801EA140(child);
                }
            }
            *(u8 *)(obj + 0x3C) = 1;
            if (*(s32 *)(obj + 0x34) != 0) {
                ((void (*)(void *, void *))fn_802A95A8)(obj + 0x24, obj + 0x2C);
                fn_802A95AC(1);
            }
        }
    }
}
#pragma cplusplus reset
#pragma scheduling on

#pragma pop
#pragma cplusplus on
struct Obj8016275C {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual s32 f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13();
    virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21();
    virtual void f22(); virtual void f23(); virtual void f24(s32);
};
#pragma cplusplus off
s32 fn_80162734(void *arg0) { return *(s32 *)((u8 *)arg0 + 8) != 0; }

s32 fn_80162748(void *arg0) { return *(s32 *)((u8 *)arg0 + 8) == 1; }

void fn_8016275C(void *arg0, s32 arg1, s32 arg2) {
    if (((s32 (*)(void))(*(void ***)arg0)[0x24 / 4])() != 0)
        goto done;
    if (arg1 == 0) {
        if (((s32 *)lbl_804348E8[arg2])[4] == (s32)0x50434152) {
            ((void (*)(void *, s32))(*(void ***)arg0)[0x60 / 4])(arg0, 2);
            *((u8 *)arg0 + 0x91) = 1;
        }
    } else {
        goto done;
    }
done:
    ;
}

#pragma push
#pragma small_data off
extern char lbl_8032FA38[];
extern char lbl_8032FA44[];
#pragma pop
#pragma cplusplus on
struct Dummy_80162800 {
    virtual void f0();
    virtual void f1(void *);
    virtual void *f2(void *);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual s32 f8();
    virtual void f9();
    virtual void f10();
    virtual f32 f11();
};
#pragma cplusplus off
extern int lbl_8055E2F8;
extern int lbl_8055A0EC;
extern int lbl_8055A0DC;
extern int fn_801476D8(int, int, int);
extern void fn_80130980(void *, int, int, float);
extern void fn_801475D0(void *, ...);
#pragma cplusplus on
extern "C" s32 fn_80162800(void *arg0) {
    s32 sp8[3];
    Dummy_80162800 *obj = (Dummy_80162800 *)arg0;
    f32 limit = lbl_8055E3C8;
    if (limit > obj->f11()) {
        if (obj->f8() == 0) {
            fn_801476D8((s32)((Dummy_80162800 *)lbl_8055E2E0)->f2(lbl_8032FA38), -1, lbl_8055E2F8);
            ((Dummy_80162800 *)lbl_8055E2E0)->f1(lbl_8032FA44);
            fn_801476C4();
            fn_80130980(&sp8, 0x14, 3, *(f32 *)((char *)arg0 + 0x84) - *(f32 *)((char *)arg0 + 0x98));
            fn_801475D0(lbl_8055E2E0, &lbl_8055A0EC, &lbl_8055A0DC, &sp8);
        }
    }
    return 0;
}
#pragma cplusplus off
extern char lbl_8032F698[];
extern void *lbl_8055E2E0;
extern int fn_801476C4(void);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_801628E8(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void call(char *);
    };
    f32 val = *(f32 *)((u8 *)arg0 + 0x8C);
    if (val > lbl_8056185C) {
        ((Dummy *)lbl_8055E2E0)->call(lbl_8032F698);
        fn_801476C4();
    }
    return 1;
}
#pragma cplusplus off
#pragma scheduling on
void *fn_80162938(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = (void *)lbl_8032F858;
        *((void **)arg0 + 0x56C / 4) = (void *)(lbl_8032F858 + 0x68);
        if ((u32)arg0 + 0x56C != 0) {
            if ((u32)arg0 + 0x56C != 0) {
                fn_8015857C((char *)arg0 + 0x56C);
            }
        }
        if ((u32)arg0 + 0x570 != 0) {
            if ((u32)arg0 + 0x570 != 0) {
                *(s32 *)((char *)arg0 + 0x570) = 0;
                *(s32 *)((char *)arg0 + 0x574) = 0;
                *(s32 *)((char *)arg0 + 0x578) = 0;
            }
        }
        if (arg0 != 0) {
            if ((u32)arg0 + 0xE0 != 0) {
                if ((u32)arg0 + 0xE0 != 0) {
                    *(s32 *)((char *)arg0 + 0xE0) = 0;
                    *(s32 *)((char *)arg0 + 0xE4) = 0;
                    *(s32 *)((char *)arg0 + 0xE8) = 0;
                }
            }
            if (arg0 != 0) {
                if ((u32)arg0 + 0x34 != 0) {
                    if ((u32)arg0 + 0x34 != 0) {
                        *(s32 *)((char *)arg0 + 0x34) = 0;
                        *(s32 *)((char *)arg0 + 0x38) = 0;
                        *(s32 *)((char *)arg0 + 0x3C) = 0;
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80162A14(void *arg0) {
    struct Dummy { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void *f4(s32 *, s32 *); };
    extern float lbl_80561848;
    extern float lbl_8056184C;
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    extern void fn_801EA140(void *);
    extern void fn_802A95A8(f32 *, f32 *, f32, f32);
    extern void fn_802A95AC(s32);
    register s32 i;
    register s32 firstOffset;
    register s32 secondOffset;
    s32 clearOffset;
    s32 clearIndex;
    float resetValue;
    char *self;

    resetValue = lbl_8056184C;
    *(s32 *)((char *)arg0 + 8) = 0;
    self = (char *)arg0;
    i = 0;
    *(u8 *)((char *)arg0 + 0x10) = 0;
    firstOffset = 0;
    *(float *)((char *)arg0 + 0xC) = resetValue;
    while (i < *(s32 *)(self + 0x38)) {
        void *obj = *(void **)(self + 4);
        s32 *entry = (s32 *)(*(char **)(self + 0x34) + firstOffset);
        void *result = ((Dummy *)obj)->f4(&lbl_8055A0E0, &lbl_8055A0E8);
        fn_801DF380(result, entry[0], (void (*)())fn_80161438, entry[1]);
        firstOffset += 8;
        i++;
    }

    resetValue = lbl_80561848;
    *(s32 *)(self + 0x94) = 0;
    i = 0;
    *(float *)(self + 0x98) = resetValue;
    secondOffset = 0;
    *(u8 *)(self + 0x88) = 0;
    *(float *)(self + 0x8C) = resetValue;
    *(u8 *)(self + 0x90) = 0;
    *(u8 *)(self + 0x91) = 0;
    *(u8 *)(self + 0x9C) = 1;
    while (i < *(s32 *)(self + 0xE4)) {
        char *obj = (char *)*(void **)(self + 0xE0) + secondOffset;
        fn_801EA140(obj);
        *(float *)(obj + 4) += *(float *)(obj + 0x38);
        if (*(s32 *)(obj + 0x34) != 0) {
            u32 j;
            char *child;
            for (j = 0, child = obj + 0xC; j < 2; j++, child += 0xC)
                fn_801EA140(child);
        }
        *(u8 *)(obj + 0x3C) = 1;
        if (*(s32 *)(obj + 0x34) != 0) {
            ((void (*)(void *, void *))fn_802A95A8)(obj + 0x24, obj + 0x2C);
            fn_802A95AC(1);
        }
        secondOffset += 0x48;
        i++;
    }

    clearIndex = 0;
    clearOffset = 0;
    while (clearIndex < *(s32 *)(self + 0x574)) {
        clearIndex++;
        *((u8 *)*(void **)(self + 0x570) + clearOffset + 8) = 0;
        clearOffset += 0xC;
    }
    resetValue = lbl_80561848;
    *(s32 *)(self + 0x5AC) = 0;
    *(float *)(self + 0x5B4) = resetValue;
}

#pragma push
#pragma processor 750
extern "C" void fn_80162BA8(void *arg0) {
    u8 *self = (u8 *)arg0;
    s32 i, j, offset;
    int *cars;
    u8 *entry, *car, *flags, *ui;
    f32 threshold, one, epsilon;
    s32 flag, off;
    off = 0;
    for (s32 remaining = *(s32 *)(self + 0x574); remaining > 0; remaining--) {
        if (*(u8 *)(*(u8 **)(self + 0x570) + off + 8) == 0) {
            flag = 0;
            goto done;
        }
        off += 0xC;
    }
    flag = 1;
done:
    if (flag != 0) {
        *(f32 *)(self + 0x5B4) += lbl_80561858;
        self[0x9C] = 1;
        if (self[0x5B0] != 0 && *(s32 *)(self + 0x574) > 0) {
            ((void (*)(void *, s32))(*(void ***)self)[24])(self, 1);
        }
    } else {
        self[0x9C] = 0;
    }
    if (fn_801C5B60() == 0) fn_801DF074(8, 0);
    if (((s32 (*)(void *))(*(void ***)self)[9])(self) == 0) {
        one = lbl_80561840; threshold = lbl_80561854; epsilon = lbl_80561850;
        for (i = 0, cars = lbl_804348E8; i < fn_801B2F24(); i++, cars++) {
            car = (u8 *)*cars;
            if (*(u32 *)(car + 0x10) != 0x50434152) continue;
            for (j = 0, offset = 0; j < *(s32 *)(self + 0xE4); j++, offset += 0x48) {
                entry = *(u8 **)(self + 0xE0) + offset;
                if (!entry[0x3C]) continue;
                if (*(s32 *)(entry + 0x34)) {
                    if (fn_80139B5C(car, *(s32 *)(entry + 0x34))) {
                        flags = entry + i;
                        if (!flags[0x3D]) {
                            f32 velocity[2], length, scale;
                            velocity[0] = *(f32 *)(car + 0x118);
                            velocity[1] = *(f32 *)(car + 0x120);
                            length = velocity[0] * velocity[0] + velocity[1] * velocity[1];
                            if (length > epsilon) {
                                scale = one / (f32)fn_8002F234(length);
                                velocity[0] *= scale;
                                velocity[1] *= scale;
                                if (velocity[0] * *(f32 *)(entry + 0x2C) + velocity[1] * *(f32 *)(entry + 0x30) > threshold) {
                                    ++*(s32 *)(self + 0x94);
                                    entry[0x3C] = 0;
                                    ui = *(u8 **)(self + 0xDC);
                                    ui[0x49] = 1; ui[0x4B] = 0; ui[0x4A] = 0;
                                }
                            }
                        }
                        flags[0x3D] = 1;
                        break;
                    } else if (entry[0x3C]) (entry + i)[0x3D] = 0;
                } else if (PSVECSquareDistance(entry, car + 0x60) < *(f32 *)(self + 0xCC) * *(f32 *)(self + 0xCC)) {
                    ++*(s32 *)(self + 0x94);
                    entry[0x3C] = 0;
                    ui = *(u8 **)(self + 0xDC);
                    ui[0x49] = 1; ui[0x4B] = 0; ui[0x4A] = 0;
                    break;
                }
            }
        }
        *(f32 *)(self + 0x98) += lbl_80561858;
        if (*(f32 *)(self + 0x98) >= *(f32 *)(self + 0x84))
            ((void (*)(void *, s32))(*(void ***)self)[24])(self, 3);
        if (*(s32 *)(self + 0x94) >= *(s32 *)(self + 0x80) && self[0x9C]) {
            ((void (*)(void *, s32))(*(void ***)self)[24])(self, 1);
            self[0x88] = 1;
        }
    } else {
        if ((f32)__fabs(*(f32 *)(self + 0x8C)) <= *(f32 *)&lbl_80558DC4) {
            fn_80276DC8(0);
            for (i = 0, cars = lbl_804348E8; i < fn_801B2F24(); i++, cars++) {
                void *manager = fn_801B83A0();
                ((void (*)(void *, s32, s32))(*(void ***)manager)[37])(manager, *cars, i);
            }
        }
        *(f32 *)(self + 0x8C) += lbl_80561858;
        if (self[0x90]) {
            if (((s32 (*)(void *))(*(void ***)self)[10])(self) && lbl_8055E304 == fn_80160CE4()) {
                s32 tmp = lbl_8055A0B8;
                lbl_8055E2DC = 1;
                lbl_8055A0B4 = tmp;
                lbl_8055A0B8 = tmp + 1;
            } else lbl_8055E2DC = 0;
            lbl_8055E304 = 0;
            if (*(s32 *)(lbl_8042FDEC + 4) > 0) fn_80176734();
        }
    }
    if (flag == 0 && *(s32 *)(self + 0x94) >= *(s32 *)(self + 0x80)) {
        ((void (*)(void *, s32))(*(void ***)self)[24])(self, 4);
    }
}
#pragma pop

#pragma cplusplus reset
#pragma scheduling on

#pragma push
#pragma processor 750
#pragma scheduling on
#pragma cplusplus on
extern "C" s32 fn_80162FE8(void *arg0) {
    class Obj {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7();
        virtual s32 check();
    };
    struct Data { char pad0[8]; s32 v8; char padC[0x5B4-0xC]; f32 f5B4; f32 f5B8; };
    Obj *obj = (Obj *)arg0;
    struct Data *d = (struct Data *)arg0;
    f32 tmp = d->f5B8;
    if (obj->check() != 0) {
        return d->f5B4 > tmp;
    }
    return d->v8 != 0;
}
#pragma cplusplus off
#pragma pop
s32 fn_80163058(void *arg0) { return *(s32 *)((u8 *)arg0 + 8) == 1; }

#pragma cplusplus on
/* Dispatches an object action based on arg1 when the object is ready; for case 0, if the indexed table entry (lbl_804348E8[arg2]) has tag 'PCAR' at +0x10 it finalizes and sets a flag at +0x91. */
extern "C" void fn_8016306C(void *object, s32 action, s32 index) {
    class Obj {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual s32 check();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void finish(s32);
        virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
        virtual void dispatch(s32, s32, s32);
    };
    Obj *obj = (Obj *)object;

    if (obj->check() == 0) {
        switch (action) {
        case 2: obj->dispatch(0x10, index, 5); break;
        case 1: obj->dispatch(0x11, index, 5); break;
        case 3: obj->dispatch(0x12, index, 5); break;
        case 4: obj->dispatch(0x13, index, 5); break;
        }
    }

    if (obj->check() != 0)
        goto done;
    switch (action) {
    case 0:
        goto check_tag;
    default:
        goto done;
    }

check_tag:
    if (*(u32 *)(lbl_804348E8[index] + 0x10) == 0x50434152) {
        obj->finish(2);
        *((u8 *)object + 0x91) = 1;
    }

done:
    return;
}
#pragma cplusplus off

#pragma push
#pragma processor 750
s32 fn_801631E0(void *arg0) {
    s32 sp8;
    f32 limit = lbl_8055E3C8;
    if (limit > ((f32 (*)(void *))(*(void ***)arg0)[0x34 / 4])(arg0)) {
        if (((s32 (*)(void *))(*(void ***)arg0)[0x28 / 4])(arg0) == 0) {
            ((s32 (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0x10 / 4])(lbl_8055E2E0, &lbl_8032FA38);
            fn_801476D8(0, -1, lbl_8055E2F8);
            ((void (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0x0C / 4])(lbl_8055E2E0, &lbl_8032FA44);
            fn_801476C4();
            fn_80130980(&sp8, 0x14, 3, *(f32 *)((char *)arg0 + 0x84) - *(f32 *)((char *)arg0 + 0x98));
            fn_801475D0(lbl_8055E2E0, &lbl_8055A0EC, &lbl_8055A0DC, &sp8);
        }
    }
    return 0;
}

#pragma scheduling invalid_target
#pragma cplusplus on
// Draws the tutorial results banner: the top and bottom bars, the
// "results_art" graphic in the pass or fail colour, the banner's title line
// ("results1") and body line ("results2", whose text comes from the message
// table and says why the tutorial was lost), and, once the banner is far
// enough in, the "continue" prompt.  Returns 1 to keep the HUD object alive.
extern "C" s32 fn_801632C8(void *banner) {
    class HudObject {
    public:
        virtual void m08(); virtual void m0C(); virtual void m10(); virtual void m14();
        virtual void m18(); virtual void m1C(); virtual void m20(); virtual void m24();
        virtual s32 isOn();     // vtable slot 0x28: banner already on screen
    };
    class UiManager {
    public:
        virtual void m08();
        virtual void *getText(const char *); // vtable slot 0xC: named text element
        virtual void *getBar(const char *);  // vtable slot 0x10: named bar element
    };
    char *names = (char *)lbl_8032F588; // pool of UI element / message names
    f32 screenX, screenY;
    void *bar;
    void *textElem;
    void *barElem;
    s32 bodyText;

    fn_801476D8((s32)(bar = ((UiManager *)lbl_8055E2E0)->getBar((const char *)&lbl_8055A0F8)), -1, lbl_8055E2E8); // "bar_top"
    fn_801476D8((s32)(bar = ((UiManager *)lbl_8055E2E0)->getBar((const char *)&lbl_8055A100)), -1, lbl_8055E2EC); // "bar_bot"
    if (((HudObject *)banner)->isOn() != 0) {
        bar = ((UiManager *)lbl_8055E2E0)->getBar(names + UI_RESULTS_ART);
        fn_801476D8((s32)bar, -1, lbl_8055E2F0); // passing artwork
        fn_801473F8(lbl_8055E2E0, names + UI_RESULTS_TITLE,
            fn_80131234(names + MSG_PASSED_HEAD));
        bodyText = fn_80131234(names + MSG_PASSED_BODY);
    } else {
        bar = ((UiManager *)lbl_8055E2E0)->getBar(names + UI_RESULTS_ART);
        fn_801476D8((s32)bar, -1, lbl_8055E2F4); // failing artwork
        fn_801473F8(lbl_8055E2E0, names + UI_RESULTS_TITLE,
            fn_80131234(names + MSG_FAILED_HEAD));
        if (*(s32 *)((u8 *)banner + 8) == FAIL_REASON_STUNT)
            bodyText = fn_80131234(names + MSG_FAILED_STUNT);
        else if (*(s32 *)((u8 *)banner + 8) == FAIL_REASON_CRASH)
            bodyText = fn_80131234(names + MSG_FAILED_CRASH);
        else
            bodyText = fn_80131234(names + MSG_FAILED_TIME);
    }
    textElem = ((UiManager *)lbl_8055E2E0)->getText(names + UI_RESULTS_BODY);
    barElem = ((UiManager *)lbl_8055E2E0)->getBar(names + UI_RESULTS_ART);
    if (textElem != 0 && barElem != 0) {
        f32 x = *(f32 *)((u8 *)textElem + 4);
        f32 y = *(volatile f32 *)((u8 *)textElem + 8);
        s32 mode = *(s32 *)((u8 *)textElem + 0xC);
        fn_80148134(&screenX, &screenY, mode, x, y); // element position -> screen
        f32 barFill = *(f32 *)((u8 *)barElem + 0x10);
        f32 textScale = *(f32 *)((u8 *)textElem + 0x10);
        f32 fill = barFill - lbl_80561860; // 100.0f = a full bar
        fn_800103B8(*(s32 *)((u8 *)textElem + 0x18),
            *(s32 *)((u8 *)textElem + 0x14), (s32 *)&lbl_8055A0DC /* "%s" */, bodyText,
            textScale, screenX, screenY, fill);
    }
    if (*(f32 *)((u8 *)banner + 0x8C) > lbl_8056185C) { // faded in past 0.5
        ((UiManager *)lbl_8055E2E0)->getText(names + UI_CONTINUE);
        fn_801476C4(); // draws it; takes the element above in r3
    }
    return 1;
}
#pragma cplusplus off
#pragma scheduling on

#pragma pop

#pragma cplusplus on
extern "C" s32 fn_801634F0(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual s32 v7();
    };
    s32 result = 0;
    if (((Obj *)arg0)->v7() != 0 && *((u8 *)arg0 + 0x90) != 0) result = 1;
    return result;
}

extern "C" void fn_80163550(TutorialLevel *level, s32 eventType, s32 carIndex, s32 progressValue) {
    /* Records tutorial goal progress for the player car when an event meets a goal's type/threshold. */
    s32 offset;
    s32 i;
    s32 type;
    TutorialGoal *goal;
    s32 met;

    if (*(u32 *)(lbl_804348E8[carIndex] + 0x10) != CAR_TAG_PLAYER_CAR)
        return;
    if (level->metCount >= level->goalCount)
        return;
    if (level->f7() != 0)
        return;

    i = 0;
    offset = 0;
    met = 1;
    goto loop_check;

loop_body:
    goal = (TutorialGoal *)((char *)level->goals + offset);
    if (goal->met == 0) {
        type = goal->type;
        if (type == eventType ||
            (type == 4 && eventType == 5) ||
            (type == 11 && eventType == 12)) {
            if (goal->target <= progressValue) {
                goal->met = met;
                level->metCount = level->metCount + 1;
            }
        }
    }
    offset += 0xC;
    i++;

loop_check:
    if (i < level->goalCount)
        goto loop_body;
}

#pragma cplusplus off
void *fn_80163658(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            if ((u32)arg0 + 0xE0 != 0) {
                if ((u32)arg0 + 0xE0 != 0) {
                    ((s32 *)arg0)[56] = 0;
                    ((s32 *)arg0)[57] = 0;
                    ((s32 *)arg0)[58] = 0;
                }
            }
            if (arg0 != 0) {
                if ((u32)arg0 + 0x34 != 0) {
                    if ((u32)arg0 + 0x34 != 0) {
                        ((s32 *)arg0)[13] = 0;
                        ((s32 *)arg0)[14] = 0;
                        ((s32 *)arg0)[15] = 0;
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma cplusplus on
#pragma scheduling on
extern "C" void fn_801636E0(void *arg0) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void *f4(s32 *, s32 *);
    };
    extern float lbl_80561848;
    extern float lbl_8056184C;
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    extern void fn_801EA140(void *);
    extern void fn_802A95A8(f32 *, f32 *, f32, f32);
    extern void fn_802A95AC(s32);
    extern s32 fn_8016D294(s32, s32, s32);
    s32 i;
    s32 firstOffset;
    s32 secondOffset;
    float resetValue;
    char *self;

    resetValue = lbl_8056184C;
    *(s32 *)((char *)arg0 + 8) = 0;
    self = (char *)arg0;
    i = 0;
    *(u8 *)((char *)arg0 + 0x10) = 0;
    firstOffset = 0;
    *(float *)((char *)arg0 + 0xC) = resetValue;
    while (i < *(s32 *)(self + 0x38)) {
        void *obj = *(void **)(self + 4);
        s32 *entry = (s32 *)(*(char **)(self + 0x34) + firstOffset);
        void *result = ((Dummy *)obj)->f4(&lbl_8055A0E0, &lbl_8055A0E8);
        fn_801DF380(result, entry[0], (void (*)())fn_80161438, entry[1]);
        firstOffset += 8;
        i++;
    }

    resetValue = lbl_80561848;
    *(s32 *)(self + 0x94) = 0;
    i = 0;
    *(float *)(self + 0x98) = resetValue;
    secondOffset = 0;
    *(u8 *)(self + 0x88) = 0;
    *(float *)(self + 0x8C) = resetValue;
    *(u8 *)(self + 0x90) = 0;
    *(u8 *)(self + 0x91) = 0;
    *(u8 *)(self + 0x9C) = 1;
    while (i < *(s32 *)(self + 0xE4)) {
        char *obj = (char *)*(void **)(self + 0xE0) + secondOffset;
        fn_801EA140(obj);
        *(float *)(obj + 4) += *(float *)(obj + 0x38);
        if (*(s32 *)(obj + 0x34) != 0) {
            u32 j;
            char *child;
            for (j = 0, child = obj + 0xC; j < 2; j++, child += 0xC)
                fn_801EA140(child);
        }
        *(u8 *)(obj + 0x3C) = 1;
        if (*(s32 *)(obj + 0x34) != 0) {
            ((void (*)(void *, void *))fn_802A95A8)(obj + 0x24, obj + 0x2C);
            fn_802A95AC(1);
        }
        secondOffset += 0x48;
        i++;
    }

    resetValue = lbl_80561848;
    *(u8 *)(self + 0x56C) = 0;
    *(u8 *)(self + 0x56D) = 0;
    *(float *)(self + 0x574) = resetValue;
    if (lbl_8055E304 > 0)
        fn_8016D294(0, 0, lbl_8055E304 - 1);
}
#pragma cplusplus reset
#pragma scheduling on

u8 fn_80163864(void *arg0) {
    return *((u8 *)arg0 + 0x56C);
}

void fn_8016386C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 == 5 && *((u8 *)arg0 + 0x56D) == 0) {
        if (arg3 >= *((s32 *)((char *)arg0 + 0x570))) {
            *((u8 *)arg0 + 0x56C) = 1;
        }
        *((u8 *)arg0 + 0x56D) = 1;
    }
}

#pragma cplusplus on
#pragma push
#pragma processor 750
extern "C" void fn_801638A0(void *arg0) {
    s32 i,j;
    int *cars;
    u8 *self=(u8 *)arg0;
    u8 *entry;
    int *cars2;
    s32 offset;
    u8 *car,*flags,*ui;
    f32 velocity[2],length,scale;
    f32 threshold,one,epsilon;
    f32 vx,vy,sqrtLen;
    if (((*(f32 *)(self+0x98)>*(f32 *)(self+0x84))&1)!=0) self[0x56D]=1;
    if (fn_801C5B60()==0) fn_801DF074(8,0);
    if (((Dummy_801638A0 *)self)->f7()==0) {
        one=lbl_80561840; threshold=lbl_80561854; epsilon=lbl_80561850;
        for (i=0,cars=lbl_804348E8;i<fn_801B2F24();cars++,i++) {
            car=(u8 *)*cars;
            if (*(u32 *)(car+0x10)!=0x50434152) continue;
            for (j=0,offset=0;j<*(s32 *)(self+0xE4);offset+=0x48,j++) {
                entry=(u8 *)*(s32 *)(self+0xE0)+offset;
                if (!entry[0x3C]) continue;
                if (*(s32 *)(entry+0x34)) {
                    if (fn_80139B5C(car,*(s32 *)(entry+0x34))) {
                        flags=entry+i;
                        if (!flags[0x3D]) {
                            velocity[0]=*(f32 *)(car+0x118);
                            velocity[1]=*(f32 *)(car+0x120);
                            length=velocity[0]*velocity[0]+velocity[1]*velocity[1];
                            if (length>epsilon) {
                                sqrtLen=(f32)fn_8002F234(length);
                                vx=velocity[0];
                                vy=velocity[1];
                                scale=one/sqrtLen;
                                velocity[0]=vx*scale;
                                velocity[1]=vy*scale;
                                if (velocity[0]**(f32 *)(entry+0x2C)+velocity[1]**(f32 *)(entry+0x30)>threshold) {
                                    ++*(s32 *)(self+0x94);
                                    entry[0x3C]=0;
                                    ui=*(u8 **)(self+0xDC);
                                    ui[0x49]=1; ui[0x4B]=0; ui[0x4A]=0;
                                }
                            }
                        }
                        flags[0x3D]=1;
                        break;
                    } else if (entry[0x3C]) (entry+i)[0x3D]=0;
                } else if (PSVECSquareDistance(entry,car+0x60)<*(f32 *)(self+0xCC)**(f32 *)(self+0xCC)) {
                    ++*(s32 *)(self+0x94);
                    entry[0x3C]=0;
                    ui=*(u8 **)(self+0xDC);
                    ui[0x49]=1; ui[0x4B]=0; ui[0x4A]=0;
                    break;
                }
            }
        }
        *(f32 *)(self+0x98)+=lbl_80561858;
        if (*(f32 *)(self+0x98)>=*(f32 *)(self+0x84)) ((Dummy_801638A0 *)self)->f22(3);
        if (*(s32 *)(self+0x94)>=*(s32 *)(self+0x80)&&self[0x9C]) {
            ((Dummy_801638A0 *)self)->f22(1);
            self[0x88]=1;
        }
    } else {
        if ((f32)__fabs(*(f32 *)(self+0x8C))<=lbl_80558DC4[0]) {
            fn_80276DC8(0);
            for (i=0,cars2=lbl_804348E8;i<fn_801B2F24();cars2++,i++) {
                Dummy_801638A0 *manager=(Dummy_801638A0 *)fn_801B83A0();
                manager->f35((void *)*cars2,i);
            }
        }
        *(f32 *)(self+0x8C)+=lbl_80561858;
        if (self[0x90]) {
            if (((Dummy_801638A0 *)self)->f8()&&lbl_8055E304==fn_80160CE4()) {
                s32 old=lbl_8055A0B8;
                lbl_8055E2DC=1;
                lbl_8055A0B4=old;
                lbl_8055A0B8=old+1;
            } else lbl_8055E2DC=0;
            lbl_8055E304=0;
            if (*(s32 *)(lbl_8042FDEC+4)>0) fn_80176734();
        }
    }
}
#pragma pop

#pragma push
#pragma processor 750
s32 fn_80163C38(void *arg0) {
    s32 sp8;
    s32 pad[4];
    f32 limit;
    void **vtable;
    pad[0] = 0;
    if (*((u8 *)arg0 + 0x56D) == 0) {
        vtable = *(void ***)arg0;
        limit = lbl_8055E3C8;
        if (limit > ((f32 (*)(void *))vtable[0x34 / 4])(arg0)) {
            vtable = *(void ***)arg0;
            if (((s32 (*)(void *))vtable[0x28 / 4])(arg0) == 0) {
                ((void (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0x10 / 4])(lbl_8055E2E0, &lbl_8032FA38);
                fn_801476D8(0, -1, lbl_8055E2F8);
                ((void (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0xC / 4])(lbl_8055E2E0, &lbl_8032FA44);
                fn_801476C4();
                fn_80130980(&sp8, 0x14, 3, *(f32 *)((u8 *)arg0 + 0x84) - *(f32 *)((u8 *)arg0 + 0x98));
                fn_801475D0(lbl_8055E2E0, &lbl_8055A0EC, &lbl_8055A0DC, &sp8);
            }
        }
        return 0;
    }
    return 0;
}

#pragma cplusplus on
// Draws the tutorial/progress HUD: the top and bottom bar graphics, a status
// text line and the bar fill, picking the message from the object's state.
extern "C" s32 fn_80163D34(void *arg0) {
    class HudObject {
    public:
        virtual void m08(); virtual void m0C(); virtual void m10(); virtual void m14();
        virtual void m18(); virtual void m1C(); virtual void m20(); virtual void m24();
        virtual s32 isOn();
    };
    class UiManager {
    public:
        virtual void m08();
        virtual void *getText(const char *); // vtable slot 0xC: named text element
        virtual void *getBar(const char *);  // vtable slot 0x10: named bar element
    };
    char *names = (char *)lbl_8032F588; // table of UI element names
    s32 text;
    f32 screenX, screenY;
    u8 *textElem;
    u8 *barElem;
    s32 overLimit;
    fn_801476D8((s32)((UiManager *)lbl_8055E2E0)->getBar((const char *)&lbl_8055A0F8), -1, lbl_8055E2E8);
    fn_801476D8((s32)((UiManager *)lbl_8055E2E0)->getBar((const char *)&lbl_8055A100), -1, lbl_8055E2EC);
    if (((HudObject *)arg0)->isOn() != 0) {
        fn_801476D8((s32)((UiManager *)lbl_8055E2E0)->getBar(names + 0x4C8), -1, lbl_8055E2F0);
        fn_801473F8(lbl_8055E2E0, names + 0x4D4, fn_80131234(names + 0x4E0));
        text = fn_80131234(names + 0x4F8);
    } else {
        fn_801476D8((s32)((UiManager *)lbl_8055E2E0)->getBar(names + 0x4C8), -1, lbl_8055E2F4);
        fn_801473F8(lbl_8055E2E0, names + 0x4D4, fn_80131234(names + 0x510));
        overLimit = *(f32 *)((u8 *)arg0 + 0x98) > *(f32 *)((u8 *)arg0 + 0x84);
        if (overLimit) {
            text = fn_80131234(names + 0x560);
        } else if (*((u8 *)arg0 + 0x91) != 0) {
            text = fn_80131234(names + 0x544);
        } else {
            text = fn_80131234(names + 0x528);
        }
    }
    textElem = (u8 *)((UiManager *)lbl_8055E2E0)->getText(names + 0x57C);
    barElem = (u8 *)((UiManager *)lbl_8055E2E0)->getBar(names + 0x4C8);
    if (textElem != 0 && barElem != 0) {
        f32 x = *(f32 *)(textElem + 4);
        f32 y = *(f32 *)(textElem + 8);
        s32 mode = *(s32 *)(textElem + 0xC);
        f32 fill;
        f32 scale;
        fn_80148134(&screenX, &screenY, mode, x, y);
        fill = *(f32 *)(barElem + 0x10) - lbl_80561860;
        scale = *(f32 *)(textElem + 0x10);
        fn_800103B8(*(s32 *)(textElem + 0x18), *(s32 *)(textElem + 0x14), (s32 *)&lbl_8055A0DC, text, scale, screenX, screenY, fill);
    }
    if (*(f32 *)((u8 *)arg0 + 0x8C) > lbl_8056185C) {
        ((UiManager *)lbl_8055E2E0)->getText(names + 0x110);
        fn_801476C4();
    }
    return 1;
}
#pragma cplusplus off
unsigned char fn_80163F6C(void *arg0) {
    return *((unsigned char *)arg0 + 0x56D);
}

unsigned char fn_80163F74(void *arg0) {
    return *((unsigned char *)arg0 + 0x56D);
}

extern void fn_802E30C8(const char *, const char *);
extern void fn_802C77F0(s32, f32 *);
extern s32 fn_80207848(void *, s32);
extern void *fn_801399FC(void);
extern void PSVECNormalize(f32 *, f32 *);
extern void PSVECCrossProduct(f32 *, f32 *, f32 *);
extern int sscanf(const char *, const char *, ...);
extern const char lbl_8055A108[4];
extern const char lbl_8055A10C[4];
extern f32 lbl_80561864;
extern s32 fn_802C6FC0(const char *, s32, s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80163F7C(void *arg0) {
    u8 *self = (u8 *)arg0;
    register const char *name = (const char *)(lbl_8032F588 + 0x588);
    register u8 *base = lbl_8032F588;
    s32 result = fn_802C6FC0(name, 0, 0);
    s32 keyResult;
    u8 *obj;
    u8 *out;
    f32 *table;
    f32 *points;
    struct {
        u8 pad0[0x18];
        f32 vectors[9];
        u8 pad1[4];
        f32 bounds[6];
    } work;

    *(s32 *)(self + 0xA0) = result;
    if (result == -1) {
        ((void (*)(const char *, ...))fn_802E30C8)((const char *)(base + 0x598), name);
    } else {
        f32 first, second;
        ((void (*)(s32, f32 *))fn_802C77F0)(result, work.bounds);
        first = work.bounds[5] - work.bounds[4];
        second = work.bounds[3] - work.bounds[2];
        first = second > first ? second : first;
        second = work.bounds[1] - work.bounds[0];
        first = second > first ? second : first;
        *(f32 *)(self + 0xCC) = first * lbl_8056185C;
    }
    *(void **)(self + 0xD0) = fn_802CAC28(base + 0x5C0, 0);
    *(s32 *)(self + 0xDC) = fn_80207848(base + 0x5D0, 1);
    obj = *(u8 **)(self + 4);
    *(u8 *)(self + 0xD8) = (u8)((Dummy_80163F7C_VT1 *)obj)->f10((const char *)(base + 0x5DC), 0);
    obj = *(u8 **)(self + 4);
    {
        const char *value = ((Dummy_80163F7C_VT1 *)obj)->f4((const char *)(base + 0x5EC), (const char *)(base + 0x5FC));
        if (sscanf(value, (const char *)lbl_8055A108, (s32 *)(self + 0xD4)) != 1) {
            *(s32 *)(self + 0xD4) = -1;
        }
    }
    obj = *(u8 **)(self + 4);
    *(s32 *)(self + 0xE4) = 0;
    if (obj != 0) {
        keyResult = ((Dummy_80163F7C_VT1 *)obj)->f21((const char *)lbl_8055A10C);
        if ((u32)(-keyResult | keyResult) >> 31) {
            s32 entryIndex = *(s32 *)(self + 0xE4);
            out = (u8 *)(*(u8 **)(self + 0xE0) + entryIndex * 0x48);
            *(s32 *)(self + 0xE4) = entryIndex + 1;
            ((Dummy_80163F7C_VT3 *)obj)->f21((const char *)lbl_8055A10C, entryIndex, *(void **)(self + 0xE0));
            table = (f32 *)fn_801399FC();
            *(f32 **)(out + 0x34) = table;
            register volatile f32 *points;
            register s32 bestIndex;
            register s32 i;
            register s32 count;
            points = (f32 *)((u8 *)table + 8);
            count = *(s32 *)table;
            {
                f32 best = lbl_80561864;
                f32 dx, dy, score;
                bestIndex = -1;
                for (i = 1; i <= count; i++) {
                        register s32 n = *(volatile s32 *)table;
                        s32 next = i % n;
                        s32 prev = (i - 1) % n;
                        dx = *((f32 *)((u8 *)points + next * 8 + 4)) - *((f32 *)((u8 *)points + prev * 8 + 4));
                        dy = *((f32 *)((u8 *)points + next * 8)) - *((f32 *)((u8 *)points + prev * 8));
                        score = dx * dx + dy * dy;
                        if (score > best) {
                            best = score;
                            bestIndex = i;
                        }
                }
            }
            register s32 count2 = *(volatile s32 *)table;
            {
                volatile f32 x0, y0, x1, y1;
                i = (bestIndex - 1) % count2;
                x0 = points[i * 2];
                y0 = points[i * 2 + 1];
                *(f32 *)(out + 0x0C) = x0;
                *(f32 *)(out + 0x10) = lbl_80561848;
                *(f32 *)(out + 0x14) = y0;
                i = bestIndex % count2;
                x1 = points[i * 2];
                y1 = points[i * 2 + 1];
                *(f32 *)(out + 0x18) = x1;
                *(f32 *)(out + 0x1C) = lbl_80561848;
                *(f32 *)(out + 0x20) = y1;
                *(f32 *)(out + 0x24) = (x0 + x1) * lbl_8056185C;
                *(f32 *)(out + 0x28) = (y0 + y1) * lbl_8056185C;
                i = (bestIndex + 1) % count2;
                work.vectors[0] = points[i * 2] - x1;
                work.vectors[1] = lbl_80561848;
                work.vectors[2] = points[i * 2 + 1] - y1;
                work.vectors[3] = x0 - x1;
                work.vectors[4] = lbl_80561848;
                work.vectors[5] = y0 - y1;
                PSVECNormalize(&work.vectors[0], &work.vectors[0]);
                PSVECNormalize(&work.vectors[3], &work.vectors[3]);
                PSVECCrossProduct(&work.vectors[0], &work.vectors[3], &work.vectors[6]);
                if (work.vectors[7] > lbl_80561848) {
                    *(f32 *)(out + 0x2C) = x0 - *(f32 *)(out + 0x24);
                    *(f32 *)(out + 0x30) = y0 - *(f32 *)(out + 0x28);
                } else {
                    *(f32 *)(out + 0x2C) = x1 - *(f32 *)(out + 0x24);
                    *(f32 *)(out + 0x30) = y1 - *(f32 *)(out + 0x28);
                }
            }
            {
                f32 dx = *(f32 *)(out + 0x2C);
                f32 dy = -*(f32 *)(out + 0x30);
                f32 scale;
                *(f32 *)(out + 0x2C) = dy;
                *(f32 *)(out + 0x30) = dx;
                scale = lbl_80561840 / (f32)fn_8002F234(dy * dy + dx * dx);
                *(f32 *)(out + 0x2C) *= scale;
                *(f32 *)(out + 0x30) *= scale;
            }
            *(u8 *)(out + 0x3D) = 0;
            *(u8 *)(out + 0x3E) = 0;
            *(u8 *)(out + 0x3F) = 0;
            *(u8 *)(out + 0x40) = 0;
            *(u8 *)(out + 0x41) = 0;
            *(u8 *)(out + 0x42) = 0;
            *(u8 *)(out + 0x43) = 0;
            *(u8 *)(out + 0x44) = 0;
            *(u8 *)(out + 0x3C) = 1;
            *(s32 *)(self + 0x80) += 1;
        }
    }
}
#pragma scheduling on
#pragma cplusplus off
int fn_801643C8(void *arg0) {
    register int var_r30 = 0;
    register int var_r31 = 0;
    void *obj;
    while (var_r31 < *((int *)((char *)arg0 + 0xE4))) {
        obj = *((void **)((char *)arg0 + 0xE0));
        if (*((int *)((char *)obj + var_r30 + 0x34)) != 0) {
            fn_80128658();
        }
        var_r30 += 0x48;
        var_r31 += 1;
    }
    obj = *((void **)((char *)arg0 + 0xDC));
    if (obj != 0) {
        ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
    }
    fn_802CAC54(*((int *)((char *)arg0 + 0xD0)));
    fn_802C6CF8(*((int *)((char *)arg0 + 0xA0)));
}

int fn_80164468(void *arg0) {
    return *((float *)((char *)arg0 + 0x8C)) < lbl_8056185C;
}

#pragma cplusplus on
extern "C" void fn_80020434(int *, float *);
extern "C" void fn_8026A2CC(int *, int, float);
extern "C" void fn_8000C630(int, int);
#pragma cplusplus on
extern "C" void fn_80164480(void *arg0) {
    int sp10[12];
    float sp8;

    if (((Dummy_801638A0 *)arg0)->f7() != 0) {
        if ((lbl_8055E3C8 - *((float *)((char *)arg0 + 0xC))) > lbl_80561868) {
            fn_80020434(sp10, &sp8);
            fn_8026A2CC(sp10, 0, sp8);
            fn_8000C630(0x15, -1);
            return;
        }
        fn_8000C630(0x20, -1);
    }
}
#pragma cplusplus off
extern s32 fn_802A96E8(void *, s32, s32, s32, s32);
extern s32 fn_802C9950(s32);
extern s32 fn_802C9994(s32);
#pragma use_lmw_stmw off
void fn_80164510(void *arg0, s32 arg1) {
    s32 offset;
    s32 temp_r30;
    s32 temp_r29;
    s32 i;
    void *p;
    temp_r30 = fn_802C9950(-0x100);
    temp_r29 = fn_802C9994(0);
    if (*(s32 *)((char *)arg0 + 0xA0) != -1) {
        i = 0;
        offset = 0;
        while (i < *(s32 *)((char *)arg0 + 0xE4)) {
            p = (char *)*(void **)((char *)arg0 + 0xE0) + offset;
            if (*(u8 *)((char *)p + 0x3C) != 0 && *(s32 *)((char *)p + 0x34) != 0 && *(u8 *)((char *)arg0 + 0xD8) != 0) {
                fn_802A96E8((char *)p + 0xC, 2, *(s32 *)((char *)arg0 + 0xD4), *(s32 *)((char *)arg0 + 0xD0), 0);
            }
            offset += 0x48;
            i++;
        }
    }
    fn_802C9950(temp_r30);
    fn_802C9994(temp_r29);
}
#pragma use_lmw_stmw reset
extern s32 lbl_8055A0E0;
extern s32 lbl_8055A0E8;
extern u8 lbl_8055E2DD;
s32 fn_801645D8(void *arg0, s32 arg1) {
    if (*(float *)((char *)arg0 + 0x8C) > lbl_8056185C) {
        if (arg1 == 0x58) {
            if (*(u8 *)((char *)arg0 + 0x90) != 0)
                lbl_8055E2DD = 1;
            *(u8 *)((char *)arg0 + 0x90) = 1;
            return 1;
        }
        if ((u32)arg1 == 0x1B)
            return (lbl_8055E2DD = 1, 1);
    }
    return 0;
}

s32 fn_80164634(void *arg0) {
    return *(float *)((char *)arg0 + 0x98) > *(float *)((char *)arg0 + 0x84);
}

extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern void fn_801345D8(char *, s32, const char *, s32);
extern s32 fn_80146C2C(s32, s32);
extern char lbl_8032FB90[];
extern const char lbl_8055A110, lbl_8055A118;

#pragma cplusplus on
struct NameList_8016464C {
    virtual void slot0();
    virtual s32 hasName(const char *);
    virtual void slot2();
    virtual void *getValue(const char *);
};
struct Iterator_8016464C {
    virtual s32 next(void *);
};
struct State_8016464C {
    u8 pad0[4];
    void *list;
    u8 pad8[0x2C];
    void *entries;
    s32 entryCount;
};
struct Entry_8016464C {
    void *object;
    s32 value;
};
#pragma cplusplus on
extern "C" void fn_8016464C(void *arg0) {
    State_8016464C *self = (State_8016464C *)arg0;
    char name[0x10];
    s32 i;
    s32 count;
    void *iterator;
    Entry_8016464C *entry;

    self->entryCount = 0;
    iterator = fn_80131810(lbl_8032FB90);
    count = 0;
    do {
        count++;
        ((void (*)(char *, s32, const char *, ...))fn_801345D8)(name, 0x10, (const char *)&lbl_8055A110, count);
    } while (((NameList_8016464C *)self->list)->hasName(name) != 0);

    i = 0;
    while (i < count - 1) {
        s32 n = self->entryCount;
        s32 index = i + 1;
        self->entryCount = n + 1;
        entry = (Entry_8016464C *)self->entries + n;
        ((void (*)(char *, s32, const char *, ...))fn_801345D8)(name, 0x10, (const char *)&lbl_8055A110, index);
        entry->object = ((NameList_8016464C *)self->list)->getValue(name);
        ((void (*)(char *, s32, const char *, ...))fn_801345D8)(name, 0x10, (const char *)&lbl_8055A118, index);
        entry->value = 0;
        if (((NameList_8016464C *)self->list)->hasName(name) != 0) {
            void *value = ((NameList_8016464C *)self->list)->getValue(name);
            if (iterator != 0) {
                s32 result = ((Iterator_8016464C *)iterator)->next(value);
                if (result != 0)
                    entry->value = fn_80146C2C(lbl_8055E2E4, result);
            }
        }
        i++;
    }
    if (iterator != 0)
        fn_80131818(iterator);
}
extern "C" void fn_801647DC(void *arg0) {
    struct Object {
        virtual void method(s32);
    };
    s32 var_r31;
    s32 var_r30;
    void *temp_r3;

    var_r31 = 0;
    var_r30 = 0;
    while (var_r30 < *(s32 *)((char *)arg0 + 0x38)) {
        temp_r3 = *(void **)((char *)(*(s32 *)((char *)arg0 + 0x34)) + var_r31 + 4);
        if (temp_r3 != 0) {
            if (temp_r3 != 0) {
                ((Object *)temp_r3)->method(1);
            }
        }
        var_r31 += 8;
        var_r30 += 1;
    }
    *(s32 *)((char *)arg0 + 0x38) = 0;
}
#pragma cplusplus off
int fn_80164868(void) {
    return 1;
}

void fn_80164870(void *arg0, s32 arg1) {
    if (*(u8 *)((char *)arg0 + 0x10) == 0) {
        *(s32 *)((char *)arg0 + 8) = arg1;
        *(u8 *)((char *)arg0 + 0x10) = 1;
        *(float *)((char *)arg0 + 0xC) = lbl_8055E3C8;
    }
}

s32 fn_80164894(s32 arg0, void *arg1, s32 arg2) {
    *(float *)arg1 = *(float *)(0x14 + arg0 + (arg2 << 2));
    return 1;
}

#pragma cplusplus on
struct Vec2_648 { float x; float y; };
struct ObjInner_648 {
    virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3();
    virtual void i4(); virtual void i5(); virtual void i6(); virtual void i7();
    virtual void i8(); virtual void i9(); virtual void i10(); virtual void i11();
    virtual void i12(); virtual void i13(); virtual void i14(); virtual void i15();
    virtual void i16(); virtual void i17(); virtual void i18(); virtual void i19();
    virtual void i20(); virtual void *i21(char *);
};
struct Obj2_648 {
    virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3();
    virtual void o4(); virtual void o5(); virtual void o6(); virtual void o7();
    virtual float o8(char *, float); virtual void o9(); virtual s32 o10(char *, s32);
    virtual void o11(); virtual void o12(); virtual Vec2_648 o13(char *);
};
struct Mgr_648 {
    virtual void m0(); virtual s32 m1(s32);
};
#pragma cplusplus off
extern void *fn_801352B8(void *);
extern void *fn_8013530C(void *, s32);
extern void fn_801355C0(void *, void *, s32, void *, s32);
extern s32 fn_80135D60(void *, s32);
extern void *fn_80156A40(void);
extern void fn_801B7C8C(void *, void *, void *);
extern char lbl_8032FB9C[];
extern char lbl_8032FBA8[];
extern char lbl_8055A120;
extern char lbl_8055A128;
extern float lbl_80561840;
extern float lbl_8056186C;
extern void *fn_801352B8(void *);
extern void *fn_8013530C(void *, s32);
extern void fn_801355C0(void *, void *, s32, void *, s32);
extern s32 fn_80135D60(void *, s32);
extern void *fn_80156A40(void);
extern void fn_801B7C8C(void *, void *, void *);
extern char lbl_8032FB9C[];
extern char lbl_8032FBA8[];
extern char lbl_8055A120;
extern char lbl_8055A128;
extern float lbl_80561840;
extern float lbl_8056186C;
s32 fn_801648AC(void *arg0, void *arg1, s32 arg2) {
    struct State { void *node; float frac; s32 id; };
    char obj[0x40];
    struct Vec2_648 pts[3];
    char place[0x10];
    struct State state;
    char bound[0x10];
    struct Vec2_648 pos;
    struct Vec2_648 dir;
    struct Vec2_648 copy;
    struct Vec2_648 ret;
    struct Vec2_648 e2;
    struct Vec2_648 e1;
    struct Vec2_648 mid;
    void *self;
    void *scalePtr;
    void *obj2;
    s32 i;
    struct Vec2_648 *p;
    s32 best;
    float bestLen;
    float len;
    float inv;
    float len01;
    void *node;
    float frac;
    float speed;
    float scale;

    self = arg0;
    scalePtr = (char *)self + arg2 * 4;
    *(float *)((char *)scalePtr + 0x14) = lbl_80561848;
    if (*(void **)((char *)self + 4) != 0) {
        ((void (*)(char *, s32, const char *, ...))fn_801345D8)(place, 0x10, lbl_8032FB9C, arg2);
        obj2 = ((struct ObjInner_648*)*(void **)((char *)self + 4))->i21(place);
        if (obj2 != 0) {
            pos.x = lbl_80561848;
            pos.y = lbl_80561848;
            dir.x = lbl_80561848;
            dir.y = lbl_80561848;
            p = pts;
            i = 0;
            do {
                ((void (*)(char *, s32, const char *, ...))fn_801345D8)(bound, 0x10, (char *)&lbl_8055A120, i);
                ret = ((struct Obj2_648*)obj2)->o13(bound);
                p->x = ret.x;
                p->y = ret.y;
                p++;
                i++;
            } while (i < 3);
            best = 2;
            e2.y = pts[2].y - pts[0].y;
            e2.x = pts[2].x - pts[0].x;
            bestLen = e2.x * e2.x + e2.y * e2.y;
            e1.y = pts[0].y - pts[1].y;
            e1.x = pts[0].x - pts[1].x;
            len01 = e1.x * e1.x + e1.y * e1.y;
            if (len01 > bestLen) {
                bestLen = len01;
                best = 0;
            }
            e1.y = pts[1].y - pts[2].y;
            e1.x = pts[1].x - pts[2].x;
            if (e1.x * e1.x + e1.y * e1.y > bestLen) {
                best = 1;
            }
            mid.y = pts[best].y + lbl_8056185C * (pts[(best + 1) % 3].y - pts[best].y);
            mid.x = pts[best].x + lbl_8056185C * (pts[(best + 1) % 3].x - pts[best].x);
            copy = mid;
            pos.x = copy.x;
            pos.y = copy.y;
            dir.x = pts[(best + 2) % 3].x - copy.x;
            dir.y = pts[(best + 2) % 3].y - copy.y;
            len = (float)fn_8002F234(dir.x * dir.x + dir.y * dir.y);
            inv = lbl_80561840 / len;
            dir.x = dir.x * inv;
            dir.y = dir.y * inv;
            if (((struct Obj2_648*)obj2)->o10(lbl_8032FBA8, 1) != 0) {
                fn_801352B8(obj);
                fn_80135D60(obj, ((struct Mgr_648*)fn_80156A40())->m1(0));
                state.node = 0;
                state.id = 0x2710;
                state.frac = lbl_80561848;
                fn_801355C0(obj, &pos, 0, &state, 0);
                node = state.node;
                frac = state.frac;
                pos.x = *(float *)node + frac * (*(float *)(*(void **)((char *)node + 0x14)) - *(float *)node);
                pos.y = *(float *)((char *)node + 4) + frac * (*(float *)((char *)(*(void **)((char *)node + 0x14)) + 4) - *(float *)((char *)node + 4));
                dir.x = *(float *)((char *)node + 8) + frac * (*(float *)((char *)(*(void **)((char *)node + 0x14)) + 8) - *(float *)((char *)node + 8));
                dir.y = *(float *)((char *)node + 0xC) + frac * (*(float *)((char *)(*(void **)((char *)node + 0x14)) + 0xC) - *(float *)((char *)node + 0xC));
                len = (float)fn_8002F234(dir.x * dir.x + dir.y * dir.y);
                inv = lbl_80561840 / len;
                dir.x = dir.x * inv;
                dir.y = dir.y * inv;
                fn_8013530C(obj, -1);
            }
            fn_801B7C8C(arg1, &pos, &dir);
            speed = ((struct Obj2_648*)obj2)->o8((char *)&lbl_8055A128, lbl_80561848);
            scale = lbl_8056186C * speed;
            *(float *)((char *)arg1 + 0x30) = *(float *)((char *)arg1 + 0x18) * scale;
            *(float *)((char *)arg1 + 0x34) = *(float *)((char *)arg1 + 0x1C) * scale;
            *(float *)((char *)arg1 + 0x38) = *(float *)((char *)arg1 + 0x20) * scale;
            *(float *)((char *)scalePtr + 0x14) = scale;
            return 1;
        }
    }
    return 0;
}

extern f32 lbl_80561870;
extern f32 fn_80164CD4(void);
f32 fn_80164CD4(void) {
    return lbl_80561870;
}

#pragma cplusplus on
extern "C" void fn_80164CDC(void *arg0) {
    Obj_80164CDC *obj = *(Obj_80164CDC **)((char *)arg0 + 4);
    obj->f4(&lbl_8055A0E0, &lbl_8055A0E8);
}
#pragma cplusplus off
extern int fn_80128668(void);
int fn_80164CF8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80164D38(void *arg0) {
    int one = 1;
    int zero = 0;
    *(unsigned char *)((char *)arg0 + 4) = zero;
    *(int *)((char *)arg0 + 8) = one;
    *(unsigned char *)((char *)arg0 + 5) = zero;
    *(unsigned char *)((char *)arg0 + 6) = zero;
    *(unsigned char *)((char *)arg0 + 7) = zero;
}

void fn_80164D58(void) {

}

void fn_80164D5C(void) {
}

void fn_80164D60(void) {

}

extern void fn_8018ADBC(void *, f32);
extern void fn_8018ADB4(void *, f32);
extern void fn_8018ADA4(void *, f32);
extern void fn_8017CFFC(void *, u32 *, f32 *, f32 *);
extern void fn_80176780(int, int);
extern void fn_8017691C(void);
extern f32 lbl_80561878;
extern f32 lbl_80561874;
extern f64 lbl_80561880;
extern s32 lbl_8055E4D0;
#pragma scheduling invalid_target
void fn_80164D64(void *arg0, s32 arg1) {
    struct Head { u32 word[8]; };
    struct Work { f32 a[3]; f32 b[3]; struct Head head; u32 tail[4]; } work;
    register u32 word64;
    register u32 word60;
    register int *cars;
    register int index;
    register void *car;
    register f32 offset;
    register f32 scale;
    register f32 zero;
    f32 factor;
    if (lbl_8055A0B4 <= fn_80161D50()) {
        if (lbl_8055A0B8 > fn_80161D50()) {
            if (*(u8 *)((u8 *)arg0 + 7) == 0) {
                fn_801DF074(8, 1);
                *(u8 *)((u8 *)arg0 + 7) = 1;
            }
        }
    }
    zero = *(volatile f32 *)&lbl_80561848;
    scale = *(volatile f32 *)&lbl_80561878;
    offset = *(volatile f32 *)&lbl_80561874;
    for (cars = lbl_804348E8, index = 0; index < lbl_8055E4D0; cars++, index++) {
        car = (void *)*cars;
        fn_8018ADBC(car, lbl_80561840);
        fn_8018ADB4(car, lbl_80561848);
        fn_8018ADA4(car, lbl_80561848);
        work.head = *(struct Head *)((u8 *)car + 0x3C);
        work.tail[0] = *(u32 *)((u8 *)car + 0x5C);
        word60 = *(volatile u32 *)((u8 *)car + 0x60);
        word64 = *(volatile u32 *)((u8 *)car + 0x64);
        work.tail[1] = word60;
        work.tail[2] = word64;
        work.tail[3] = *(volatile u32 *)((u8 *)car + 0x68);
        ((f32 *)work.tail)[1] = zero;
        factor = (f32)index;
        ((f32 *)work.tail)[2] = offset + scale * factor;
        ((f32 *)work.tail)[3] = zero;
        work.a[2] = work.a[1] = work.a[0] = zero;
        work.b[2] = work.b[1] = work.b[0] = zero;
        fn_8017CFFC(car, work.head.word, work.b, work.a);
    }
    if (*(u8 *)((u8 *)arg0 + 4)) {
        register s32 value;
        register s32 limit;
        fn_801796BC(0);
        value = *(s32 *)((u8 *)arg0 + 8);
        *(u8 *)((u8 *)arg0 + 4) = 0;
        *(u8 *)((u8 *)arg0 + 5) = 1;
        lbl_8055E304 = value;
        limit = *(s32 *)((u8 *)lbl_8042FDEC + 4);
        if (value < limit)
            fn_80176780(0x8002, 0);
        else
            fn_8017691C();
    }
}
#pragma scheduling on
void fn_80164F50(void *arg0) {
    extern void fn_801796BC(unsigned char);
    extern s32 fn_80131234(void *);
    extern void fn_802A95A8(f32 *, f32 *, f32, f32);
    extern void fn_80276CB0(void *, s32);
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    extern u8 lbl_8055E2DC;
    extern u8 lbl_8032F588[];
    extern u8 lbl_8042FDEC[];
    extern f32 lbl_80561840;
    extern f32 lbl_80561848;
    extern f32 lbl_80561888;
    void *self = arg0;
    f32 out[2];
    f32 in[2];
    s32 value;
    s32 first;
    s32 second;
    u8 *base = lbl_8032F588;
    s32 zero;
    f32 f2;
    f32 f1;
    f32 f0;
    f32 *outPtr;
    f32 *inPtr;

    fn_801796BC(1);
    value = fn_80160CE4();
    if (lbl_8055E2DC != 0 && value <= *(s32 *)(lbl_8042FDEC + 4)) {
        *(s32 *)((u8 *)self + 8) = value;
    }
    if (*(s32 *)((u8 *)self + 8) >= *(s32 *)(lbl_8042FDEC + 4)) {
        *(s32 *)((u8 *)self + 8) = *(s32 *)(lbl_8042FDEC + 4);
    }
    zero = 0;
    f2 = *(volatile f32 *)&lbl_80561888;
    *(volatile u8 *)((u8 *)self + 4) = zero;
    outPtr = out;
    f1 = *(volatile f32 *)&lbl_80561840;
    inPtr = in;
    *(volatile u8 *)((u8 *)self + 6) = zero;
    f0 = *(volatile f32 *)&lbl_80561848;
    *(volatile u8 *)((u8 *)self + 5) = zero;
    outPtr[0] = f2;
    outPtr[1] = f2;
    inPtr[0] = f1;
    inPtr[1] = f0;
    fn_802A95A8(outPtr, inPtr, f1, f2);
    fn_80276CB0(base + 0x630, 0);
    first = fn_80131234(base + 0x654);
    second = fn_80131234(base + 0x63C);
    fn_801DF380((void *)second, first, (void (*)())fn_80161438, 0);
}
#pragma scheduling on
extern void fn_801796BC(unsigned char);
typedef struct Work_80164D64 {
    f32 vectorA[3];
    f32 vectorB[3];
    u32 data[12];
} Work_80164D64;
unsigned char fn_80165040(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

unsigned char fn_80165048(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

unsigned char fn_80165050(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

s32 fn_80165058(void *arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r29;
    /* Handle menu/navigation input (up/down/select/back/cancel) when not blocked; updates selection at +8. */
    if ((s32)*(u32 *)((u8 *)fn_801E7E34() + 0xDB0) == 0) {
        if (*(u8 *)((u8 *)arg0 + 6) == 0) {
            switch (arg1) {
            case 0x126:
                temp_r30 = *(s32 *)((u8 *)arg0 + 8) - 1;
                *(s32 *)((u8 *)arg0 + 8) = temp_r30;
                if (temp_r30 < 1) {
                    *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)&lbl_8042FDEC + 4);
                } else {
                    register u8 *limits = (u8 *)&lbl_8042FDEC;
                    if (temp_r30 > *(s32 *)(limits + 4))
                        *(s32 *)((u8 *)arg0 + 8) = 1;
                    else if ((temp_r30 > fn_80160CE4()) && (temp_r30 < *(s32 *)(limits + 4)))
                        *(s32 *)((u8 *)arg0 + 8) = fn_80160CE4();
                }
                fn_80230E90(1);
                return 1;
            case 0x128:
                temp_r29 = *(s32 *)((u8 *)arg0 + 8) + 1;
                *(s32 *)((u8 *)arg0 + 8) = temp_r29;
                if (temp_r29 < 1) *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)&lbl_8042FDEC + 4);
                else if (temp_r29 > *(s32 *)((u8 *)&lbl_8042FDEC + 4)) *(s32 *)((u8 *)arg0 + 8) = 1;
                else if ((temp_r29 > fn_80160CE4()) && (temp_r29 < *(s32 *)((u8 *)&lbl_8042FDEC + 4))) *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)&lbl_8042FDEC + 4);
                fn_80230E90(1);
                return 1;
            case 0x58: *(u8 *)((u8 *)arg0 + 4) = 1; return 1;
            case 0x1B: lbl_8055E2DD = 1; return 1;
            }
        } else {
            switch (arg1) {
            case 0x58: *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)&lbl_8042FDEC + 4); *(u8 *)((u8 *)arg0 + 4) = 1; return 1;
            case 0x53: *(u8 *)((u8 *)arg0 + 6) = 0; return 1;
            }
        }
    }
    return 0;
}

extern f32 fn_80165238(void);
f32 fn_80165238(void) {
    return lbl_80561848;
}

int fn_80165240(void) {
    return 0;
}

void fn_80165248(void) {

}

extern void fn_80147940(void *, void *, const char *, s32);
extern void fn_80230F78(void *, void *, void *, s32);
extern void fn_80147230(void *, const char *, s32);
extern int fn_801E8838(void);
extern s32 fn_80012910(s32);
extern int fn_80230E90();
extern char lbl_8055A130, lbl_8055A138, lbl_8055A140, lbl_8055A148;
extern u8 lbl_8055E308;
#pragma cplusplus on
extern "C" s32 fn_8016524C(void *arg0) {
    struct Manager {
        virtual void slot0();
        virtual void *slot1(const char *);
        virtual void *slot2(const char *);
        virtual void *slot3(const char *);
    };
    struct Name {
        virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
        virtual const char *s4(const char *, s32);
    };
    struct Holder { s32 value; s32 pad[7]; Name *names; };
    struct Entry {
        virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
        virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
        virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
        virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
        virtual void s20(); virtual s32 label();
    };
    struct Rec { s32 a; s32 x; s32 y; s32 d; f32 e; s32 f; u32 color; s32 h; };
    struct Rec7 { s32 a; s32 x; s32 y; s32 d; f32 e; f32 f; u32 color; };
#define FX(r) (*(f32 *)&(r).x)
#define FY(r) (*(f32 *)&(r).y)
    char *text = (char *)lbl_8032F588;
    Manager *mgr;
    Holder *holder;
    void *r24, *r25, *r26, *r27;
    Rec7 rec3;
    Rec7 rec2;
    Rec7 rec1;
    Rec rec0;
    char buf[10];
    f32 amount;
    u8 alpha;

    if (*((u8 *)arg0 + 6) != 0) {
        s32 first = fn_80131234(text + 0x680);
        s32 second = fn_80131234(text + 0x66C);
        ((void (*)(s32, s32))fn_80161438)(second, first);
    } else {
        if (fn_801E8838() > 100) fn_80230E90(1);
        mgr = (Manager *)lbl_8055E2E0;
        fn_801476D8((s32)mgr->slot2((const char *)&lbl_8055A0F8), -1, lbl_8055E2E8);
        fn_801476D8((s32)((Manager *)lbl_8055E2E0)->slot2((const char *)&lbl_8055A100), -1, lbl_8055E2EC);
        holder = (Holder *)((void *(*)(s32))fn_8001285C)(*__AXFXGetLfoSinTable_801769CC());
        ((Manager *)lbl_8055E2E0)->slot1(text + 0x694);
        fn_801476C4();
        fn_801473F8(lbl_8055E2E0, text + 0x6A0, (const char *)&lbl_8055A0DC,
            holder->names->s4(text + 0x6AC, fn_80012910(holder->value)));
        ((Manager *)lbl_8055E2E0)->slot1(text + 0x110);
        fn_801476C4();
        r24 = ((Manager *)lbl_8055E2E0)->slot1(&lbl_8055A130);
        r25 = ((Manager *)lbl_8055E2E0)->slot1(&lbl_8055A138);
        r26 = ((Manager *)lbl_8055E2E0)->slot3(&lbl_8055A140);
        r27 = ((Manager *)lbl_8055E2E0)->slot3(text + 0x6BC);
        if (r24 != 0 && r25 != 0) {
            f32 f31 = lbl_80561840;
            f32 f30 = lbl_8056185C;
            f32 f29 = lbl_80561848;
            s32 i = 1;
            s32 off = 4;
            for (; i <= *(s32 *)(lbl_8042FDEC + 4); i++, off += 4) {
                Rec *src;
                ((void (*)(char *, s32, const char *, ...))fn_801345D8)(buf, 10, &lbl_8055A148, i);
                src = (Rec *)((Manager *)lbl_8055E2E0)->slot1(buf);
                if (src != 0) {
                    f32 dy, dx;
                    s32 flag;
                    rec0 = *src;
                    dx = FX(rec0) - *(f32 *)&((Rec *)r24)->x;
                    dy = FY(rec0) - *(f32 *)&((Rec *)r24)->y;
                    rec1 = *(Rec7 *)r26;
                    flag = (i != *(s32 *)((u8 *)arg0 + 8));
                    if (i > fn_80160CE4() && i != *(s32 *)(lbl_8042FDEC + 4)) rec1.color = 0x55FFFFFF;
                    FY(rec1) += dy;
                    FX(rec1) += dx;
                    fn_80147940(lbl_8055E2E0, &rec1, text + 0x6C8, flag);
                    if (i > fn_80160CE4() && i < *(s32 *)(lbl_8042FDEC + 4))
                        rec0.color = ((Rec *)r25)->color;
                    else
                        rec0.color = ((Rec *)r24)->color;
                    alpha = 0xFF;
                    amount = f29;
                    if (i == *(s32 *)((u8 *)arg0 + 8)) {
                        fn_80230F78(&alpha, &amount, &rec0.color, 1);
                        FX(rec1) -= f30 * rec1.e * amount;
                        FY(rec1) -= f30 * rec1.f * amount;
                        rec1.e = rec1.e * (f31 + amount);
                        rec1.f = rec1.f * (f31 + amount);
                        rec1.color = ((u32)alpha << 24) | (rec1.color & 0x00FF0000) | (rec1.color & 0xFFFF);
                        fn_80147940(lbl_8055E2E0, &rec1, text + 0x6C8, flag);
                    }
                    if (i != *(s32 *)(lbl_8042FDEC + 4)) {
                        if (i < fn_80160CE4()) {
                            rec2 = *(Rec7 *)r27;
                            FY(rec2) += dy;
                            FX(rec2) += dx;
                            fn_80147940(lbl_8055E2E0, &rec2, text + 0x6D8, 2);
                        } else {
                            s32 cur = fn_80160CE4();
                            rec3 = *(Rec7 *)r27;
                            FY(rec3) += dy;
                            FX(rec3) += dx;
                            if (i > cur) rec3.color = 0x55FFFFFF;
                            fn_80147940(lbl_8055E2E0, &rec3, text + 0x6D8, 3);
                        }
                    }
                    if (i < *(s32 *)(lbl_8042FDEC + 4)) {
                        Entry *entry = *(Entry **)(*(s32 *)lbl_8042FDEC + off);
                        ((void (*)(Rec *, const char *, ...))fn_80147230)(&rec0, (const char *)&lbl_8055A0DC, entry->label());
                    } else {
                        ((void (*)(Rec *, const char *, ...))fn_80147230)(&rec0, (const char *)&lbl_8055A0DC, fn_80131234(text + 0x66C));
                    }
                } else if (lbl_8055E308 == 0) {
                    lbl_8055E308 = 1;
                    ((void (*)(const char *, const char *, ...))fn_802E30C8)((const char *)&lbl_8055A0DC, text + 0x6E8);
                }
            }
        }
    }
    return 1;
}
#pragma cplusplus off

int fn_801657D4(void) { return 1; }

void fn_801657DC(void) {
    int sp10[12];
    float sp8;
    fn_80020434(sp10, &sp8);
    fn_8026A2CC(sp10, 0, sp8);
    fn_8000C630(0x15, -1);
}

void fn_80165820(void) {
}

int fn_80165824(void) { return 0; }

int fn_8016582C(void) { return 0; }

void *__AXGetStudio_80165834(void) {
    return lbl_8032FCB0;
}

int fn_80165840(void) {
    return 0;
}

#pragma dont_inline on
int fn_80165848(int arg0, int arg1, int arg2, int arg3, int arg4, int *arg5) {
    if (fn_80161BB8() != 0) {
        *arg5 |= 0x1150;
        return 1;
    }
    return 0;
}
#pragma dont_inline off

#pragma cplusplus on
extern "C" int fn_80165894(s32 a0, s32 a1, float *arg2, s32 arg3) {
    struct CacheObject {
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
        virtual void invoke(float *, s32);
    };
    if (lbl_804348E8[arg3]) {
        *arg2 = lbl_80561848;
        ((CacheObject **)(*(char **)lbl_8042FDEC))[lbl_8055E304]->invoke(arg2, arg3);
    }
    return 0;
}
#pragma cplusplus off
int fn_80165900(void) { return 1; }

int fn_80165908(void) { return 0; }
typedef struct VtblA18 { void *pad[7]; void (*f)(void); } VtblA18;
typedef struct ObjA18 { VtblA18 *vtable; } ObjA18;
struct Vtbl_80163D34 { void *v[4]; void (*method)(void *, const char *); };
struct Obj_80163D34 { struct Vtbl_80163D34 *vt; };

