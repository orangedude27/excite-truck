// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

#pragma cplusplus on
    struct State_80162BA8 {
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
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
        virtual void f22();
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
        virtual void f35();
        virtual void f36();
        virtual void f37(s32, s32);
    };

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

/* __AXFXGetLfoSinTable_801769CC is one of the game's three-instruction
 * address-of stubs (src/game/game_ax_stubs.c): it hands back &lbl_804303E0, the
 * current race's state block.  Its first word is the contest being raced, an
 * index into the global contest table (its AX name is a wrong symbol guess). */
#define current_contest_index (*__AXFXGetLfoSinTable_801769CC())
/* lbl_8032F5DC: the parameter-table element "challenge". */
#define challenge_element lbl_8032F5DC
/* lbl_8032F71C / lbl_8032F760: the allocation tag "chalsubtaskmgr" and the
 * vtable of the challenge sub-task manager. */
#define chalsubtaskmgr_tag lbl_8032F71C
#define chalsubtaskmgr_vtable lbl_8032F760

/* One entry of the global contest table (lbl_80352AD0, stride 0x28, count
 * lbl_8055D508); fn_8001285C(index) answers with entry `index`. */
struct ContestEntry {
    /* 0x00 */ s32 index;    /* its index in the table */
    /* 0x04 */ s32 eventId;  /* the event the contest belongs to */
    /* 0x08 */ s32 type;     /* contest type; fn_80007FF0 turns it into a name */
    /* 0x0C */ s32 unk_0C[5];
    /* 0x20 */ void *table;  /* the contest's parameter table object */
    /* 0x24 */ s32 inUse;    /* the entry holds a contest */
};

#pragma cplusplus on
/* One element of a contest's parameter table; slot 0x08 returns its name. */
struct ContestParamElement {
    virtual const char *getName();
};

/* A contest's parameter table object (ContestEntry+0x20): a table of named
 * elements.  Slot 0x20 reads one as an int, falling back on the default it is
 * handed; slot 0x5C looks one up by name and answers 0 when the table holds no
 * such element; slot 0x60 returns element `index` (or 0 past the end). */
struct ContestParamTable {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual s32 getInt(const void *, s32); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual s32 findElement(const void *);
    virtual struct ContestParamElement *getElement(s32);
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
extern void LoadIntOptionValue(s32, s32, s32 *);
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
extern void *ArtSetGet(void *);
void* fn_80160C8C(void* arg0, s32 arg1) {
    /* Destroy a small struct by clearing its three fields and optionally freeing it. */
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
/* The number of challenge levels unlocked so far: the goal count that ends the
 * current challenge step (challenge_step_max) minus the number of challenge
 * levels in the contests before this one (challenge_step_base).  With no
 * challenge active the base is -1, so every level is unlocked.  The challenge
 * level-select menu uses this as its highest selectable entry. */
s32 fn_80160CE4(void) {
#define challenge_step_max lbl_8055A0B8
#define challenge_step_base lbl_8055A0C0
    return challenge_step_max - challenge_step_base;
#undef challenge_step_max
#undef challenge_step_base
}

#pragma cplusplus on
#pragma processor 750
#pragma ppc_psq_save off
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" char lbl_8032F790[];
extern "C" void fn_80158558(void *);
extern "C" s32 fn_80158618(s32);
static inline void fn_80160CF4_clear(void *p) {
    (void)p;
}
extern "C" int stricmp(const char *, const char *);
extern "C" char lbl_8055A0D4;
extern "C" f32 lbl_8056183C;
extern "C" char lbl_8055A0C4;
extern "C" char lbl_8055A0CC;
extern "C" f32 lbl_80561838;
extern "C" f32 lbl_80561840;
extern "C" char lbl_8032F8D0[];
extern "C" char lbl_8032F7F0[];
extern "C" char *lbl_802F94A8[];
extern void *memset(void *, s32, u32);
extern void *memset(void *, int, unsigned int);
extern "C" void fn_80160CF4(void) {
#pragma scheduling invalid_target
    struct Node {
        virtual const char *name();
        virtual void f1(); virtual void f2();
        virtual const char *attr(const char *);
        virtual void f4(); virtual s32 attrInt(const char *);
        virtual void f6(); virtual void f7();
        virtual f32 attrF(const char *, f32);
        virtual void f9(); virtual s32 attrB(const char *, s32);
        virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
        virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18();
        virtual void f19(); virtual void f20(); virtual void f21();
        virtual Node *child(s32);
    };
    struct Root { s32 pad[8]; Node *node; };
    Root *root;
    Node *n, *c;
    s32 idx;
    f32 f31;
    s32 i;
    void *obj;
    s32 lst;
    char *text;
    text = (char *)lbl_8032F588;
    root = (Root *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    lbl_8055E300 = 0;
    obj = fn_801284F8(0xC, text + 0x48);
    if (obj != 0) *(s32 *)obj = (s32)lbl_8032F790;
    idx = 1;
    lst = *(s32 *)(lbl_8042FDEC + 4);
    *(s32 *)(lbl_8042FDEC + 4) = lst + 1;
    *(s32 *)(*(s32 *)lbl_8042FDEC + lst * 4) = (s32)obj;
    n = root->node->child(0);
    f31 = lbl_8056183C;
    for (; n != 0; n = root->node->child(idx++)) {
        const char *kind;
        if (stricmp(n->name(), text + 0x54) != 0) continue;
        kind = n->attr((const char *)&lbl_8055A0C4);
        if (stricmp(kind, (const char *)&lbl_8055A0CC) == 0) {
            char *o = (char *)fn_801284F8(0x5BC, text + 0x60);
            if (o != 0) {
                s32 cnt, j, diff, nn, mm, check, flag, hi;
                const char *names[4];
                u32 start, end;
                s32 valid;
                *(s32 *)(o + 0x34) = (s32)(o + 0x40);
                *(s32 *)(o + 0x38) = 0;
                *(s32 *)(o + 0x3C) = 8;
                start = (u32)o + 0x134; end = (u32)o + 0x56C; valid = start < end;
                *(s32 *)(o + 4) = (s32)n;
                *(s32 *)o = (s32)lbl_8032F8D0;
                *(s32 *)(o + 0xE0) = (s32)(o + 0xEC);
                *(s32 *)(o + 0xE4) = 0;
                *(s32 *)(o + 0xE8) = 0x10;
                if (valid) {
                    diff = (s32)(end - start); nn = (diff + 0x47) / 72; mm = nn + 1;
                    if (mm > 8) {
                        check = 0;
                        if (start <= end) {
                            flag = 1;
                            if ((diff & (s32)0x80000000) == 0 && ((diff + 0x47) & (s32)0x80000000) != 0) flag = 0;
                            if (flag != 0) check = 1;
                        }
                        if (check != 0) {
                            hi = nn & (s32)0x80000000;
                            if (hi == 0 && hi != (mm & (s32)0x80000000)) {
                                fn_80160CF4_clear(o + 0x134);
                            }
                        }
                    }
                }
                *(s32 *)(o + 0x80) = 0;
                *(f32 *)(o + 0x84) = n->attrF(text + 0x70, lbl_80561838);
                *(f32 *)(o + 0xCC) = f31;
                *(s32 *)o = (s32)lbl_8032F858;
                *(s32 *)(o + 0x56C) = (s32)(lbl_8032F858 + 0x68);
                *(s32 *)(o + 0x570) = (s32)(o + 0x57C);
                *(s32 *)(o + 0x578) = 4;
                *(s32 *)(o + 0x574) = 0;
                *(u8 *)(o + 0x5B0) = (u8)n->attrB(text + 0x7C, 0);
                i = 0;
                c = n->child(i);
                while (c != 0) {
                    if (stricmp(c->name(), (const char *)&lbl_8055A0CC) == 0) {
                        s32 *ent;
                        const char *a;
                        cnt = *(s32 *)(o + 0x574);
                        ent = (s32 *)(*(s32 *)(o + 0x570) + cnt * 0xC);
                        names[0] = lbl_802F94A8[0]; names[1] = lbl_802F94A8[1];
                        names[2] = lbl_802F94A8[2]; names[3] = lbl_802F94A8[3];
                        *(s32 *)(o + 0x574) = cnt + 1;
                        a = c->attr((const char *)&lbl_8055A0C4);
                        ent[0] = -1;
                        for (j = 0; j < 4; j++) if (stricmp(a, names[j]) == 0) ent[0] = j + 0x10;
                        if (ent[0] == -1) ent[0] = fn_80158618((s32)a);
                        ent[1] = c->attrInt((const char *)&lbl_8055A0D4);
                    }
                    i++;
                    c = n->child(i);
                }
                *(f32 *)(o + 0x5B8) = n->attrF(text + 0x88, lbl_80561840);
                fn_80158558(o != 0 ? o + 0x56C : o);
            }
            lst = *(s32 *)(lbl_8042FDEC + 4);
            *(s32 *)(lbl_8042FDEC + 4) = lst + 1;
            *(s32 *)(*(s32 *)lbl_8042FDEC + lst * 4) = (s32)o;
        } else if (stricmp(kind, text + 0x98) == 0) {
            char *o2 = (char *)fn_801284F8(0x578, text + 0xA4);
            if (o2 != 0) {
                s32 diff, nn, mm, check, flag, hi;
                u32 start, end;
                s32 valid;
                *(s32 *)(o2 + 0x34) = (s32)(o2 + 0x40);
                *(s32 *)(o2 + 0x38) = 0;
                *(s32 *)(o2 + 0x3C) = 8;
                start = (u32)o2 + 0x134; end = (u32)o2 + 0x56C; valid = start < end;
                *(s32 *)(o2 + 4) = (s32)n;
                *(s32 *)o2 = (s32)lbl_8032F8D0;
                *(s32 *)(o2 + 0xE0) = (s32)(o2 + 0xEC);
                *(s32 *)(o2 + 0xE4) = 0;
                *(s32 *)(o2 + 0xE8) = 0x10;
                if (valid) {
                    diff = (s32)(end - start); nn = (diff + 0x47) / 72; mm = nn + 1;
                    if (mm > 8) {
                        check = 0;
                        if (start <= end) {
                            flag = 1;
                            if ((diff & (s32)0x80000000) == 0 && ((diff + 0x47) & (s32)0x80000000) != 0) flag = 0;
                            if (flag != 0) check = 1;
                        }
                        if (check != 0) {
                            hi = nn & (s32)0x80000000;
                            if (hi == 0 && hi != (mm & (s32)0x80000000)) {
                                fn_80160CF4_clear(o2 + 0x134);
                            }
                        }
                    }
                }
                *(s32 *)(o2 + 0x80) = 0;
                *(f32 *)(o2 + 0x84) = n->attrF(text + 0x70, lbl_80561838);
                *(f32 *)(o2 + 0xCC) = f31;
                *(s32 *)o2 = (s32)lbl_8032F7F0;
                *(s32 *)(o2 + 0x570) = 0;
                for (i = 0; (c = n->child(i)) != 0; i++) {
                    if (stricmp(c->name(), (const char *)&lbl_8055A0CC) == 0) *(s32 *)(o2 + 0x570) = c->attrInt(text + 0xB8);
                }
            }
            lst = *(s32 *)(lbl_8042FDEC + 4);
            *(s32 *)(lbl_8042FDEC + 4) = lst + 1;
            *(s32 *)(*(s32 *)lbl_8042FDEC + lst * 4) = (s32)o2;
        }
    }
}

#pragma pop

void *fn_801612BC(void *object, s32 deleting) {
    /* Destroy/clear embedded subobjects at +0xE0 and +0x34, then optionally free. */
    if (object != 0) {
        if ((u32)object + 0xE0 != 0) {
            if ((u32)object + 0xE0 != 0) {
                ((s32 *)object)[56] = 0;
                ((s32 *)object)[57] = 0;
                ((s32 *)object)[58] = 0;
            }
        }
        if (object != 0) {
            if ((u32)object + 0x34 != 0) {
                if ((u32)object + 0x34 != 0) {
                    ((s32 *)object)[13] = 0;
                    ((s32 *)object)[14] = 0;
                    ((s32 *)object)[15] = 0;
                }
            }
        }
        if (deleting > 0) fn_80128668(object);
    }
    return object;
}

/* Clear three dwords at +0x34..+0x3C when present, optionally freeing the object. */
void *fn_80161340(void *obj, s32 freeFlag) {
    if (obj != 0) {
        if ((u32)obj + 0x34 != 0) {
            if ((u32)obj + 0x34 != 0) {
                ((s32 *)obj)[13] = 0;
                ((s32 *)obj)[14] = 0;
                ((s32 *)obj)[15] = 0;
            }
        }
        if (freeFlag > 0) {
            fn_80128668(obj);
        }
    }
    return obj;
}

s32 fn_801613A0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma dont_inline on
/* Handles simple system events when available; event 3 clears a flag and runs cleanup, returning success. */
s32 fn_801613E0(s32 eventId) {
    if (fn_80161C38() != 0) {
        switch (eventId) {
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
    u8 *text = lbl_8032F588;
    f32 spC;
    f32 sp8;
    void *temp_r3;
    void *temp_r3_2;
    register u8 *temp_r3_3;

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
        temp_r3_3 = (u8 *)((Service *)lbl_8055E2E0)->find((const char *)text + 0xF0);
        f32 value4 = *(f32 *)((u8 *)temp_r3_3 + 4);
        u8 *alias = temp_r3_3;
        f32 value8 = *(f32 *)((u8 *)alias + 8);
        s32 valueC = *(s32 *)((u8 *)temp_r3_3 + 0xC);
        fn_80148134(&spC, &sp8, valueC, value4, value8);
        f32 firstValue = *(f32 *)((u8 *)temp_r3 + 0x10);
        f32 settingValue = *(f32 *)((u8 *)temp_r3_3 + 0x10);
        f32 delta = firstValue - lbl_80561844;
        fn_800103B8(*(s32 *)(temp_r3_3 + 0x18),
            *(s32 *)(temp_r3_3 + 0x14), (s32 *)&lbl_8055A0DC, arg1,
            settingValue, spC, sp8, delta);
        fn_801473F8(lbl_8055E2E0, (const char *)text + 0xFC,
            &lbl_8055A0DC, arg0);
        ((Service *)lbl_8055E2E0)->find((const char *)text + 0x110);
        fn_801476C4();
    }
}
#pragma cplusplus off
#pragma scheduling on

/* Sum the number of "challenge" elements across contest entries [0, count). */
s32 fn_801615B4(s32 count) {
    s32 total = 0;
    s32 index = 0;
    goto test;
body:
    fn_80161E40(index);
    total = total + fn_8016208C();
    index = index + 1;
test:
    if (index < count) goto body;
    return total;
}

void fn_80161618(void) {
    /* Initialize runtime state: read a base value via fn_8000DA10 and register
       it (value+0xC) with LoadIntOptionValue using lbl_8055A0B0/lbl_8055A0B8, clear
       flags, run fn_80160CF4, cache the first item/id from the list at
       lbl_8042FDEC (or clear if count <= 1), then iterate all list items and
       invoke virtual slot1() on each. */
    s32 offset;
    s32 i;
    s32 value;
    void *item;
    value = fn_8000DA10();
    lbl_8055A0B8 = 1;
    LoadIntOptionValue(value + 0xC, lbl_8055A0B0, &lbl_8055A0B8);
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
    /* Apply a stored option value, invoke and reset each item in the global object list, then clear its count and current selection. */
    register s32 *itemCount;
    register s32 itemOffset;
    register s32 index;
    void *item;

    fn_80133348(fn_8000DA10() + 0xC, lbl_8055A0B0, lbl_8055A0B8);
    itemCount = (s32 *)((u8 *)lbl_8042FDEC + 4);
    index = 0;
    itemOffset = 0;
    goto test_loop;
loop:
    item = *(void **)((u8 *)*(void **)lbl_8042FDEC + itemOffset);
#pragma cplusplus on
    ((Dummy_801616FC_A *)item)->invoke();
#pragma cplusplus off
    item = *(void **)((u8 *)*(void **)lbl_8042FDEC + itemOffset);
    if (item != 0) {
#pragma cplusplus on
        ((Dummy_801616FC_B *)item)->reset(1);
#pragma cplusplus off
    }
    itemOffset += 4;
    index += 1;
test_loop:
    if (index < *itemCount) {
        goto loop;
    }
    *itemCount = 0;
    lbl_8055E300 = 0;
}

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
    lbl_8055E2FC = (int)ArtSetGet(lbl_8032F588 + 0x188);

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
    // Select entry by index from the global list, call its virtual update (vfunc6), then clear active flag.
    #define SELECTED_INDEX lbl_8055E304
    #define ENTRY_LIST_PTR *((char **)lbl_8042FDEC)
    #define ENTRY_LIST_COUNT *(s32 *)(lbl_8042FDEC + 4)
    #define CURRENT_ENTRY lbl_8055E300
    #define ACTIVE_FLAG lbl_8055E2DD

    s32 selectedIndex = SELECTED_INDEX;
    if (selectedIndex >= 0 && selectedIndex < ENTRY_LIST_COUNT) {
        CURRENT_ENTRY = *(s32 *)(ENTRY_LIST_PTR + selectedIndex * 4);
    }
    if (CURRENT_ENTRY != 0) {
        ((Dummy_801619A8 *)CURRENT_ENTRY)->f6();
    }
    ACTIVE_FLAG = 0;

    #undef SELECTED_INDEX
    #undef ENTRY_LIST_PTR
    #undef ENTRY_LIST_COUNT
    #undef CURRENT_ENTRY
    #undef ACTIVE_FLAG
}
#pragma cplusplus on
extern "C" void fn_80161A18(void) {
    /* Advance the active challenge sub-task (the level-select menu or a
     * StuntChallenge tutorial screen held in lbl_8055E300) one step via virtual
     * slot 0x1C; does nothing when no sub-task is active. */
    struct ChallengeSubTask {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void update();
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        subTask->update();
    }
}
#pragma cplusplus on
extern "C" void fn_80161A38(s32 action, s32 index, s32 value) {
    /* Forwards three arguments to the active challenge sub-task's virtual dispatch at vtable+0x40; does nothing if none is active. */
    struct ChallengeSubTask {
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
        virtual void dispatch(s32, s32, s32);
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        subTask->dispatch(action, index, value);
    }
}
#pragma cplusplus on
/* Draw the screen the challenge sub-task manager is showing.  Its current
 * sub-task (lbl_8055E300: the level-select menu at index 0 of the list at
 * lbl_8042FDEC, or one of the "StuntChallenge" tutorial screens made from that
 * configuration's "challenge" nodes) says with slot 0x24 whether its challenge
 * is over and its "finish_delay" has run out; the manager then draws the
 * results view (slot 0x48) instead of the running one (slot 0x44).  What the
 * draw method returns comes back; with no current sub-task nothing is drawn
 * and 0 comes back. */
extern "C" s32 fn_80161A70(void) {
    /* A sub-task of the manager.  The level-select menu (vtable lbl_8032F790)
     * and a tutorial screen (vtable lbl_8032F858) share this layout.  MWCC puts
     * two empty words (offset-to-top and type info, both null with RTTI off) in
     * front of the method table, so the first method declared here is the one
     * at vtable+0x08 -- the destructor fn_80162938. */
    struct ChallengeSubTask {
        virtual void m08();
        virtual void m0C();
        virtual void m10();
        virtual void m14();
        virtual void m18();
        virtual void m1C();
        virtual void m20();  /* fn_80162A14: reset */
        virtual s32 isOver();  /* fn_80162FE8: over, and its finish delay past */
        virtual void m28();
        virtual void m2C();
        virtual void m30();
        virtual void m34();
        virtual void m38();
        virtual void m3C();
        virtual void m40();  /* fn_8016306C: dispatch(action, index, ...) */
        virtual s32 draw(s32);  /* the running view: timer / level list */
        virtual s32 drawResults(s32);  /* the results banner; the menu draws nothing */
    };
#define current_subtask lbl_8055E300
    if (current_subtask != 0) {
        if (((ChallengeSubTask *)current_subtask)->isOver() != 0) {
            return ((ChallengeSubTask *)current_subtask)->drawResults(0);
        }
        return ((ChallengeSubTask *)current_subtask)->draw(0);
    }
#undef current_subtask
    return 0;
}
extern "C" void fn_80161AEC(void) {
    /* Call virtual slot 0x4C on the active challenge sub-task (lbl_8055E300), if any,
       as part of the challenge subsystem's shutdown; the slot takes no arguments. */
    struct ChallengeSubTask {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual void v6(); virtual void v7(); virtual void v8();
        virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void call();
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        subTask->call();
    }
}
#pragma cplusplus on
extern "C" int fn_800121A4(void);
#pragma cplusplus on
#pragma scheduling invalid_target
/* If the current subtask exists and reports completion (f10), clear the active flag
   (triggering fn_800121A4 once on the transition) and report that it is done. */
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
    /* Return the active challenge sub-task's float value (vtable slot 0x34), or 0.0 when none is active. */
    struct ChallengeSubTask {
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
        virtual f32 getValue();
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        return subTask->getValue();
    }
    return lbl_80561848;
}
#pragma cplusplus on
extern "C" s32 fn_80161B94(void) {
    /* Ask the active challenge sub-task for the value at vtable slot 0x2c (zero means clear/idle); default to 0 when none is active. */
    struct ChallengeSubTask {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual s32 v9();
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        return subTask->v9();
    }
    return 0;
}

#pragma cplusplus on
/* Return whether the active challenge sub-task reports its challenge over (its
 * finish delay elapsed), via virtual slot 0x24; 0 when no sub-task is active. */
extern "C" int fn_80161BB8(void) {
    struct ChallengeSubTask {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual int isOver();
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        return subTask->isOver();
    }
    return 0;
}
#pragma cplusplus on
#define ChallengeSubTask_Call fn_80161BDC /* forward a request to the active challenge sub-task */
extern "C" s32 fn_80161BDC(s32 arg0, s32 arg1, s32 arg2) {
    /* Forward three arguments to the active challenge sub-task's virtual at vtable+0x3C and return
       its result (non-zero means the sub-task handled/blocked the request); 0 if none is active. */
    struct ChallengeSubTask {
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
        virtual s32 handle(s32, s32, s32);
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        return subTask->handle(arg0, arg1, arg2);
    }
    return 0;
}
#pragma cplusplus off
void fn_80161C18(void) {
    /* Invoke virtual slot 0x58 on the active challenge sub-task (lbl_8055E300), if
       any; for the level-select menu this is fn_801657DC, which sets up a view
       and starts message 0x15. */
    void *subTask = (void *)lbl_8055E300;
    if (subTask != 0) {
#pragma cplusplus on
        struct ChallengeSubTask {
            virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
            virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
            virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
            virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
            virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
            virtual void call();
        };
        ((struct ChallengeSubTask *)subTask)->call();
#pragma cplusplus reset
    }
}

s32 fn_80161C38(void) {
    // Nonzero while a challenge sub-task is active; lbl_8055E300 holds its pointer.
    return lbl_8055E300 != 0;
}

#pragma cplusplus on
extern "C" s32 fn_80161C4C(void) {
    /* Ask the active challenge sub-task for the value at vtable slot 0x50; default to 1 when none is active. */
    struct ChallengeSubTask {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual s32 v18();
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        return subTask->v18();
    }
    return 1;
}
#pragma cplusplus on
/* Ask the active challenge sub-task for the value at vtable slot 0x54; default to 1 when none is active. */
extern "C" s32 fn_80161C70(void) {
    struct ChallengeSubTask {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual s32 v19();
    };
    ChallengeSubTask *subTask = (ChallengeSubTask *)lbl_8055E300;
    if (subTask != 0) {
        return subTask->v19();
    }
    return 1;
}
extern "C" void **fn_80161C94(void) {
    struct ContestEntry *contest;
    struct ContestParamTable *table;
    s32 result;
    void **manager;

    /* Build the challenge sub-task manager for the contest being raced: its
     * parameter table has to hold a "challenge" element for the manager -- a
     * four-byte object that is nothing but the "chalsubtaskmgr" vtable -- to be
     * allocated; without that element there is nothing to manage and 0 comes
     * back. */
    contest = (struct ContestEntry *)fn_8001285C(current_contest_index);
    table = (struct ContestParamTable *)contest->table;
    result = table->findElement(challenge_element);
    if (((u32)(-result | result) >> 31) != 0) {
        manager = (void **)fn_801284F8(4, chalsubtaskmgr_tag);
        if (manager != 0) {
            *manager = chalsubtaskmgr_vtable;
        }
        return manager;
    }
    return 0;
}
#pragma cplusplus off
/* Reads the current player's "tutorial_level" option.  The options live in the
   player's own section (OPTIONS_SECTION_PLAYER0 + the player index fn_8000DA10
   answers with), and LoadIntOptionValue writes the value it is handed back into the
   table when that option isn't in it yet, so an option that was never written
   reads back as the default 1. */
s32 fn_80161D14(void) {
#define OPT_TUTORIAL_LEVEL lbl_8055A0B0 /* points at the name "tutorial_level" */
#define OPTIONS_SECTION_PLAYER0 12      /* [PLAYER0]; + player index picks [PLAYER<n>] */
    s32 tutorialLevel;
    s32 playerIndex = fn_8000DA10();
    tutorialLevel = 1;
    LoadIntOptionValue(playerIndex + OPTIONS_SECTION_PLAYER0, OPT_TUTORIAL_LEVEL, &tutorialLevel);
    return tutorialLevel;
#undef OPT_TUTORIAL_LEVEL
#undef OPTIONS_SECTION_PLAYER0
}

extern char lbl_8032F72C[];
#pragma use_lmw_stmw off
#pragma dont_inline on
s32 fn_80161D50(void) {
    /* Sum fn_8016208C over all items whose virtual test against "mandatory"
     * (lbl_8032F72C) matches, iterating indices 0..fn_80161ECC()-1. */
    register s32 itemCount;
    register s32 total;
    register s32 index;
    register void *item;
    s32 matched;

    itemCount = fn_80161ECC();
    total = 0;
    index = 0;
    goto test_loop;
loop:
    fn_80161E40(index);
    item = fn_8001285C();
#pragma cplusplus on
    matched = ((Dummy_80161D50 *)*(void **)((u8 *)item + 0x20))->test(lbl_8032F72C, 0);
#pragma cplusplus off
    if (matched != 0) {
        total += fn_8016208C(*(s32 *)item);
    }
    index += 1;
test_loop:
    if (index < itemCount) {
        goto loop;
    }
    return total;
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset

extern s32 fn_80012854();
extern const char lbl_8032F738[];

#pragma dont_inline on
/* Compute the total data size for all valid tutorial levels and store it in the "tutorial_level" setting. */
void fn_80161DE4(void) {
    s32 dataSize;
    dataSize = fn_801615B4(fn_80161ECC() - 1);
    fn_80161E40(fn_80161ECC() - 1);
    dataSize = (s32)((char *)fn_8016208C() + dataSize);
    fn_80133348(fn_8000DA10() + 0xC, lbl_8055A0B0, dataSize + 1);
}

s32 fn_80161E40(s32 targetValue) {
    /* Return the index of the first contest whose parameter table reads the
     * "tutorial" element (default -999) as targetValue, or -1. */
    s32 index;
    struct ContestEntry *item;
    for (index = 0; index < fn_80012854(); index++) {
        item = (struct ContestEntry *)fn_8001285C(index);
#pragma cplusplus on
        if (((struct ContestParamTable *)item->table)->getInt(lbl_8032F738, -999) == targetValue) {
            return index;
        }
#pragma cplusplus off
    }
    return -1;
}

#pragma dont_inline off
extern s32 fn_80012854();
extern const char lbl_8032F738[];

int fn_80161ECC(void) {
    /* Counts how many consecutive tutorial indices are valid (stops at the first invalid index). */
#define Tutorial_GetIndex fn_80161E40
    int index = 0;

    while (Tutorial_GetIndex(index) >= 0)
        index++;

#undef Tutorial_GetIndex
    return index;
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
__declspec(section ".data") extern char lbl_8032F744[];
__declspec(section ".data") extern char lbl_8032F750[];
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
    /* Count how many "challenge" elements ("challenge", lbl_8032F5DC) appear in
     * the contest parameter table returned by fn_8001285C (taking the contest
     * index left in r3 by the preceding fn_80161E40 call). */
    extern int stricmp(const char *, const char *);
    struct ContestEntry *contest = (struct ContestEntry *)fn_8001285C();
    int challengeCount = 0;
    int index = 0;
    struct ContestParamTable *table;
    struct ContestParamElement *element;
loop:
    table = (struct ContestParamTable *)contest->table;
    {
        int cur = index++;
        element = table->getElement(cur);
    }
    if (element == 0)
        goto done;
    {
        const char *elementName = element->getName();
        if (stricmp(elementName, challenge_element) == 0)
            challengeCount++;
    }
    goto loop;
done:
    return challengeCount;
}
#pragma pop
/* Tail-call wrapper that forwards to fn_801613E0. */
s32 fn_8016212C(s32 eventId) {
    return fn_801613E0(eventId);
}

int fn_80162130(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Empty stub. */
void fn_80162170(void) {

}

/* Empty stub. */
void fn_80162174(void) {
}

void fn_801F62178_dummy(void);
#pragma cplusplus on
extern "C" void fn_80162178(void *controller, s32 arg1) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void *f4(s32 *, s32 *);
    };
    extern void fn_80161438(void);
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    s32 offset;
    s32 *entry;
    s32 i;

    /* Reset the controller's title state, then push one popup per list entry:
     * the provider object builds it from the "title" descriptor and the entry. */
    *(s32 *)((char *)controller + 8) = 0;
    *(u8 *)((char *)controller + 0x10) = 0;
    *(float *)((char *)controller + 0xC) = -1000.0f;
    for (i = 0, offset = 0; i < *(s32 *)((char *)controller + 0x38); offset += 8, i++) {
        void *provider = *(void **)((char *)controller + 4);
        char *entries = *(char **)((char *)controller + 0x34);
        entry = (s32 *)(entries + offset);
        void *result = ((Dummy *)provider)->f4(&lbl_8055A0E0, &lbl_8055A0E8);
        fn_801DF380(result, entry[0], fn_80161438, entry[1]);
    }
}
#pragma cplusplus off
/* Shows popup 8 when the DSP capability flag read by fn_801C5B60 is clear. */
void fn_80162214(void) {
    if (fn_801C5B60() == 0) {
        fn_801DF074(8, 0);
    }
}

int fn_80162248(void) {
    /* Unused stub among the popup/menu helpers: always returns zero. */
    return 0;
}

int fn_80162250(void) {
    /* Unused stub among the popup/menu helpers: always returns zero. */
    return 0;
}

/* Empty stub (no-op placeholder among the popup/menu helpers). */
void fn_80162258(void) {

}

/* Empty stub (no-op placeholder among the popup/menu helpers). */
void fn_8016225C(void) {
}

int fn_80162260(void) {
    /* Unused stub among the popup/menu helpers: always returns zero. */
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
#pragma cplusplus on
extern "C" void fn_80162268(void *challengeMgr) {
    /* Per-frame update for the gate challenge: in its scoring phase (f7()==0) it tests each
     * player truck ("PCAR") against every active gate, scoring a pass when the truck's velocity
     * aligns with the gate direction or it comes within range, and finishes once the met count
     * reaches its target. The alternate phase resets the trucks and advances the challenge step.
     * This variant omits the progress-reached flag check its sibling fn_801638A0 performs. */
    s32 carIndex,gateIndex;
    int *carTable;
    u8 *mgr=(u8 *)challengeMgr;
    u8 *gate;
    int *carTable2;
    s32 gateOffset;
    u8 *car,*gateFlags,*uiState;
    f32 velocity[2],length,scale;
    f32 minAlignment,one,minSpeedSq;
    f32 dirX,dirY;
    s32 resetCarIndex;
    if (fn_801C5B60()==0) fn_801DF074(8,0);
    if (((Dummy_801638A0 *)mgr)->f7()==0) {
        one=lbl_80561840; minAlignment=lbl_80561854; minSpeedSq=lbl_80561850;
        for (carIndex=0,carTable=lbl_804348E8;carIndex<fn_801B2F24();carTable++,carIndex++) {
            car=(u8 *)*carTable;
            if (*(u32 *)(car+0x10)!=CAR_TAG_PLAYER_CAR) continue;
            for (gateIndex=0,gateOffset=0;gateIndex<*(s32 *)(mgr+0xE4);gateOffset+=0x48,gateIndex++) {
                gate=(u8 *)*(s32 *)(mgr+0xE0)+gateOffset;
                if (!gate[0x3C]) continue;
                if (*(s32 *)(gate+0x34)) {
                    if (fn_80139B5C(car,*(s32 *)(gate+0x34))) {
                        gateFlags=gate+carIndex;
                        if (!gateFlags[0x3D]) {
                            velocity[0]=*(f32 *)(car+0x118);
                            velocity[1]=*(f32 *)(car+0x120);
                            length=velocity[0]*velocity[0]+velocity[1]*velocity[1];
                            if (length>minSpeedSq) {
                                length=(f32)fn_8002F234(length);
                                dirY=*(f32 *)(gate+0x30);
                                scale=one/length;
                                dirX=*(f32 *)(gate+0x2C);
                                velocity[0]*=scale;
                                velocity[1]*=scale;
                                if (velocity[0]*dirX+velocity[1]*dirY>minAlignment) {
                                    ++*(s32 *)(mgr+0x94);
                                    gate[0x3C]=0;
                                    uiState=*(u8 **)(mgr+0xDC);
                                    uiState[0x49]=1; uiState[0x4B]=0; uiState[0x4A]=0;
                                }
                            }
                        }
                        gateFlags[0x3D]=1;
                        break;
                    } else if (gate[0x3C]) (gate+carIndex)[0x3D]=0;
                } else if (PSVECSquareDistance(gate,car+0x60)<*(f32 *)(mgr+0xCC)**(f32 *)(mgr+0xCC)) {
                    ++*(s32 *)(mgr+0x94);
                    gate[0x3C]=0;
                    uiState=*(u8 **)(mgr+0xDC);
                    uiState[0x49]=1; uiState[0x4B]=0; uiState[0x4A]=0;
                    break;
                }
            }
        }
        *(f32 *)(mgr+0x98)+=lbl_80561858;
        if (*(f32 *)(mgr+0x98)>=*(f32 *)(mgr+0x84)) ((Dummy_801638A0 *)mgr)->f22(3);
        if (*(s32 *)(mgr+0x94)>=*(s32 *)(mgr+0x80)&&mgr[0x9C]) {
            ((Dummy_801638A0 *)mgr)->f22(1);
            mgr[0x88]=1;
        }
    } else {
        if ((f32)__fabs(*(f32 *)(mgr+0x8C))<=lbl_80558DC4[0]) {
            fn_80276DC8(0);
            for (resetCarIndex=0,carTable2=lbl_804348E8;resetCarIndex<fn_801B2F24();carTable2++,resetCarIndex++) {
                Dummy_801638A0 *manager=(Dummy_801638A0 *)fn_801B83A0();
                manager->f35((void *)*carTable2,resetCarIndex);
            }
        }
        *(f32 *)(mgr+0x8C)+=lbl_80561858;
        if (mgr[0x90]) {
            if (((Dummy_801638A0 *)mgr)->f8()&&lbl_8055E304==fn_80160CE4()) {
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
    extern void fn_80161438(void);
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    extern void fn_801EA140(void *);
    extern void fn_802A95A8(f32 *, f32 *, f32, f32);
    extern void fn_802A95AC(s32);
    s32 i;
    s32 offset;
    float resetValue;
    resetValue = lbl_8056184C;
    *(s32 *)((char *)arg0 + 8) = 0;
    i = 0;
    *(u8 *)((char *)arg0 + 0x10) = 0;
    offset = 0;
    *(float *)((char *)arg0 + 0xC) = resetValue;
    while (i < *(s32 *)((char *)arg0 + 0x38)) {
        void *obj = *(void **)((char *)arg0 + 4);
        char *entries = *(char **)((char *)arg0 + 0x34);
        s32 *entry = (s32 *)(entries + offset);
        void *result = ((Dummy *)obj)->f4(&lbl_8055A0E0, &lbl_8055A0E8);
        fn_801DF380(result, entry[0], fn_80161438, entry[1]);
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
        s32 offset2;
        s32 i2;
        i2 = 0;
        offset2 = 0;
        while (i2 < *(s32 *)((char *)arg0 + 0xE4)) {
            char *obj = (char *)*(void **)((char *)arg0 + 0xE0) + offset2;
            char *child;
            u32 j;
            fn_801EA140(obj);
            *(float *)(obj + 4) += *(float *)(obj + 0x38);
            if (*(s32 *)(obj + 0x34) != 0) {
                child = obj + 0xC;
                j = 0;
                do {
                    fn_801EA140(child);
                    j++;
                    child += 0xC;
                } while (j < 2);
            }
            *(u8 *)(obj + 0x3C) = 1;
            if (*(s32 *)(obj + 0x34) != 0) {
                ((void (*)(void *, void *))fn_802A95A8)(obj + 0x24, obj + 0x2C);
                fn_802A95AC(1);
            }
            offset2 += 0x48;
            i2++;
        }
    }
}
#pragma cplusplus reset
#pragma scheduling on

#pragma pop
#pragma cplusplus on
struct Obj8016275C {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual s32 f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(s32);
};
#pragma cplusplus off
/* Return nonzero when the object's state field at offset 8 is set. */
s32 fn_80162734(void *obj) { return *(s32 *)((u8 *)obj + 8) != 0; }

/* Return nonzero when the object's state field at offset 8 is exactly 1. */
s32 fn_80162748(void *obj) { return *(s32 *)((u8 *)obj + 8) == 1; }

#pragma cplusplus on
extern "C" void fn_8016275C(void *arg0, s32 event, s32 index) {
    /* On event 0, if not blocked by f7() and the object at lbl_804348E8[index]
     * has tag 'PCAR' (0x50434152) at +0x10, invoke f22(2) and set flag +0x91. */
    if (((Obj8016275C *)arg0)->f7() != 0) {
        goto done;
    }
    switch (event) {
    case 0:
        goto body;
    default:
        goto done;
    }
body:
    if (((s32 *)lbl_804348E8[index])[4] == (s32)0x50434152) {
        ((Obj8016275C *)arg0)->f22(2);
        *((u8 *)arg0 + 0x91) = 1;
    }
done:
    ;
}
#pragma cplusplus off

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
#pragma processor 750
/* Timer display check: when f11() drops below the threshold and f8() has not shown
 * the panel yet, show the "timer_title"/"timer_art" elements and report the elapsed
 * time (arg0+0x84 minus arg0+0x98) through the "timer"/"%s" debug message. */
extern "C" s32 fn_80162800(void *arg0) {
    struct TimerDisplay {
        virtual void v0();
        virtual void showTitle(void *title);
        virtual void *getArt(void *name);
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual s32 isShown();
        virtual void v9();
        virtual void v10();
        virtual f32 getValue();
    };
    s32 timeBuf[3];
    TimerDisplay *obj = (TimerDisplay *)arg0;
    f32 threshold = lbl_8055E3C8;
    if (threshold > obj->getValue()) {
        if (obj->isShown() == 0) {
            fn_801476D8((s32)((TimerDisplay *)lbl_8055E2E0)->getArt(lbl_8032FA38), -1, lbl_8055E2F8);
            ((TimerDisplay *)lbl_8055E2E0)->showTitle(lbl_8032FA44);
            fn_801476C4();
            fn_80130980(&timeBuf, 0x14, 3, *(f32 *)((char *)arg0 + 0x84) - *(f32 *)((char *)arg0 + 0x98));
            fn_801475D0(lbl_8055E2E0, &lbl_8055A0EC, &lbl_8055A0DC, &timeBuf);
        }
    }
    return 0;
}
#pragma cplusplus on
extern char lbl_8032F698[];
extern void *lbl_8055E2E0;
extern int fn_801476C4(void);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_801628E8(void *state) {
    /* If the timer at offset 0x8C exceeds 0.5, trigger "continue" and notify the handler. */
    struct Dummy {
        virtual void v0();
        virtual void call(char *);
    };
    if (*(f32 *)((u8 *)state + 0x8C) > 0.5f) {
        ((Dummy *)lbl_8055E2E0)->call(lbl_8032F698);
        fn_801476C4();
    }
    return 1;
}
#pragma cplusplus off
#pragma scheduling on
void *fn_80162938(void *arg0, s32 arg1) {
    register void *self = arg0;
    if (self != 0) {
        *(void **)self = (void *)lbl_8032F858;
        *((void **)self + 0x56C / 4) = (void *)(lbl_8032F858 + 0x68);
        if ((u32)self + 0x56C != 0) {
            if ((u32)self + 0x56C != 0) {
                fn_8015857C((char *)self + 0x56C);
            }
        }
        if ((u32)self + 0x570 != 0) {
            if ((u32)self + 0x570 != 0) {
                *(s32 *)((char *)self + 0x570) = 0;
                *(s32 *)((char *)self + 0x574) = 0;
                *(s32 *)((char *)self + 0x578) = 0;
            }
        }
        if (self != 0) {
            if ((u32)self + 0xE0 != 0) {
                if ((u32)self + 0xE0 != 0) {
                    *(s32 *)((char *)self + 0xE0) = 0;
                    *(s32 *)((char *)self + 0xE4) = 0;
                    *(s32 *)((char *)self + 0xE8) = 0;
                }
            }
            if (self != 0) {
                if ((u32)self + 0x34 != 0) {
                    if ((u32)self + 0x34 != 0) {
                        *(s32 *)((char *)self + 0x34) = 0;
                        *(s32 *)((char *)self + 0x38) = 0;
                        *(s32 *)((char *)self + 0x3C) = 0;
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(self);
    }
    return self;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80162A14(void *arg0) {
    struct Dummy { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void *f4(s32 *, s32 *); };
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    extern void fn_801EA140(void *);
    extern void fn_802A95A8(f32 *, f32 *, f32, f32);
    extern void fn_802A95AC(s32);
    register s32 i;
    register s32 secondOffset;
    char *self;
    unsigned int clearOffset;
    s32 clearIndex;
    float resetValue;
    register s32 firstOffset;

    resetValue = -1000.0f;
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

    resetValue = 0.0f;
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
        *(*(u8 **)(self + 0x570) + 8 + clearOffset) = 0;
        clearOffset += 0xC;
    }
    resetValue = 0.0f;
    *(s32 *)(self + 0x5AC) = 0;
    *(float *)(self + 0x5B4) = resetValue;
}

#pragma push
#pragma processor 750
/* Per-frame update for the checkpoint challenge: when every checkpoint is passed it
 * scores player trucks against each active gate (velocity alignment or proximity),
 * advances the completion timers and changes step once the goal is met; otherwise it
 * resets the trucks and advances the intro step. */
extern "C" void fn_80162BA8(void *challengeMgr) {
    s32 allCheckpointsPassed, index, carIndex, gateIndex;
    int *carTable;
    u8 *gate;
    int *carTable2;
    s32 gateOffset;
    u8 *car;
    u8 *mgr = (u8 *)challengeMgr;
    u8 *gateFlags, *uiState;
    f32 minAlignment, one, minSpeedSq;
    f32 velocity[2];
    f32 scale, length, dirX, dirY;
    index = 0;
    for (s32 checkpointsLeft = *(s32 *)(mgr + 0x574); checkpointsLeft > 0; checkpointsLeft--) {
        if (*(u8 *)(*(u8 **)(mgr + 0x570) + index + 8) == 0) {
            allCheckpointsPassed = 0;
            goto done;
        }
        index += 0xC;
    }
    allCheckpointsPassed = 1;
done:
    if (allCheckpointsPassed != 0) {
        *(f32 *)(mgr + 0x5B4) += lbl_80561858;
        mgr[0x9C] = 1;
        if (mgr[0x5B0] != 0 && *(s32 *)(mgr + 0x574) > 0) {
            ((State_80162BA8 *)mgr)->f24(1);
        }
    } else {
        mgr[0x9C] = 0;
    }
    if (fn_801C5B60() == 0) fn_801DF074(8, 0);
    if (((State_80162BA8 *)mgr)->f9() == 0) {
        one = lbl_80561840; minAlignment = lbl_80561854; minSpeedSq = lbl_80561850;
        for (carIndex = 0, carTable = lbl_804348E8; carIndex < fn_801B2F24(); carTable++, carIndex++) {
            car = (u8 *)*carTable;
            if (*(u32 *)(car + 0x10) != 0x50434152) continue;
            for (gateIndex = 0, gateOffset = 0; gateIndex < *(s32 *)(mgr + 0xE4); gateOffset += 0x48, gateIndex++) {
                gate = *(u8 **)(mgr + 0xE0) + gateOffset;
                if (!gate[0x3C]) continue;
                if (*(s32 *)(gate + 0x34)) {
                    if (fn_80139B5C(car, *(s32 *)(gate + 0x34))) {
                        gateFlags = gate + carIndex;
                        if (!gateFlags[0x3D]) {
                            velocity[0] = *(f32 *)(car + 0x118);
                            velocity[1] = *(f32 *)(car + 0x120);
                            length = velocity[0] * velocity[0] + velocity[1] * velocity[1];
                            if (length > minSpeedSq) {
                                length = (f32)fn_8002F234(length);
                                dirY = *(f32 *)(gate + 0x30);
                                scale = one / length;
                                dirX = *(f32 *)(gate + 0x2C);
                                velocity[0] *= scale;
                                velocity[1] *= scale;
                                if (velocity[0] * dirX + velocity[1] * dirY > minAlignment) {
                                    ++*(s32 *)(mgr + 0x94);
                                    gate[0x3C] = 0;
                                    uiState = *(u8 **)(mgr + 0xDC);
                                    uiState[0x49] = 1; uiState[0x4B] = 0; uiState[0x4A] = 0;
                                }
                            }
                        }
                        gateFlags[0x3D] = 1;
                        break;
                    } else if (gate[0x3C]) (gate + carIndex)[0x3D] = 0;
                } else if (PSVECSquareDistance(gate, car + 0x60) < *(f32 *)(mgr + 0xCC) * *(f32 *)(mgr + 0xCC)) {
                    ++*(s32 *)(mgr + 0x94);
                    gate[0x3C] = 0;
                    uiState = *(u8 **)(mgr + 0xDC);
                    uiState[0x49] = 1; uiState[0x4B] = 0; uiState[0x4A] = 0;
                    break;
                }
            }
        }
        *(f32 *)(mgr + 0x98) += lbl_80561858;
        if (*(f32 *)(mgr + 0x98) >= *(f32 *)(mgr + 0x84))
            ((State_80162BA8 *)mgr)->f24(3);
        if (*(s32 *)(mgr + 0x94) >= *(s32 *)(mgr + 0x80) && mgr[0x9C]) {
            ((State_80162BA8 *)mgr)->f24(1);
            mgr[0x88] = 1;
        }
    } else {
        if ((f32)__fabs(*(f32 *)(mgr + 0x8C)) <= *(f32 *)&lbl_80558DC4) {
            fn_80276DC8(0);
            for (index = 0, carTable2 = lbl_804348E8; index < fn_801B2F24(); carTable2++, index++) {
                void *manager = fn_801B83A0();
                ((State_80162BA8 *)manager)->f37(*carTable2, index);
            }
        }
        *(f32 *)(mgr + 0x8C) += lbl_80561858;
        if (mgr[0x90]) {
            if (((State_80162BA8 *)mgr)->f10() && lbl_8055E304 == fn_80160CE4()) {
                s32 tmp = lbl_8055A0B8;
                lbl_8055E2DC = 1;
                lbl_8055A0B4 = tmp;
                lbl_8055A0B8 = tmp + 1;
            } else lbl_8055E2DC = 0;
            lbl_8055E304 = 0;
            if (*(s32 *)(lbl_8042FDEC + 4) > 0) fn_80176734();
        }
    }
    if (allCheckpointsPassed == 0 && *(s32 *)(mgr + 0x94) >= *(s32 *)(mgr + 0x80)) {
        ((State_80162BA8 *)mgr)->f24(4);
    }
}
#pragma pop

#pragma cplusplus reset
#pragma scheduling on

#pragma push
#pragma processor 750
#pragma scheduling on
#pragma cplusplus on
extern "C" s32 fn_80162FE8(const void *subTask) {
    /* A cleared challenge draws results once its finish-delay timer passes:
     * isCompleted() (vtable+0x28) is the cleared flag, +0x5B4 counts up each
     * frame and is compared with the +0x5B8 delay threshold; otherwise the
     * state flag at +8 decides. */
    class ChallengeSubTask {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7();
        virtual s32 isCompleted();
    };
    ChallengeSubTask *task = (ChallengeSubTask *)subTask;
    f32 finishDelay = *(const f32 *)((const char *)subTask + 0x5B8);
    if (task->isCompleted() != 0) {
        return *(f32 *)((char *)task + 0x5B4) > finishDelay;
    }
    return *(s32 *)((char *)task + 8) != 0;
}
#pragma cplusplus off
#pragma pop
/* Return true when the object's state word at +8 equals 1. */
s32 fn_80163058(void *object) {
    struct ObjState { char pad0[8]; s32 state; } *d = (struct ObjState *)object;
    return d->state == 1;
}

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

#pragma processor 750
#pragma cplusplus on
/* Draws the countdown-timer HUD.  Once the seconds played have passed the object's own
 * show delay (vtable slot 0x34) and the run has not ended (vtable slot 0x28): it draws
 * the "timer_art" graphic with its animation resource, draws the "timer_title" caption,
 * and writes the time left -- the target time at +0x84 minus the time run at +0x98 --
 * into the "timer" text element.  Returns 0 so the HUD object stays on the draw list. */
extern "C" s32 fn_801631E0(void *arg0) {
    class HudObject {
    public:
        virtual void m08(); virtual void m0C(); virtual void m10(); virtual void m14();
        virtual void m18(); virtual void m1C(); virtual void m20(); virtual void m24();
        virtual s32 isOver();   // vtable slot 0x28: the run has already ended
        virtual void m2C(); virtual void m30();
        virtual f32 getDelay(); // vtable slot 0x34: seconds of play before the timer shows
    };
    class UiManager {
    public:
        virtual void m08();
        virtual void *getText(const char *); // vtable slot 0xC: named text element
        virtual void *getArt(const char *);  // vtable slot 0x10: named graphic element
    };
    char timeStr[0x14];
    HudObject *obj = (HudObject *)arg0;
    f32 playTime = lbl_8055E3C8; // seconds played so far
    if (playTime > obj->getDelay()) {
        if (obj->isOver() == 0) {
            fn_801476D8((s32)((UiManager *)lbl_8055E2E0)->getArt(lbl_8032FA38), -1, lbl_8055E2F8); // "timer_art" + its anim resource
            ((void (*)(void *))fn_801476C4)(((UiManager *)lbl_8055E2E0)->getText(lbl_8032FA44)); // "timer_title"
            fn_80130980(timeStr, 0x14, 3, *(f32 *)((u8 *)arg0 + 0x84) - *(f32 *)((u8 *)arg0 + 0x98)); // time left, to tenths
            fn_801475D0(lbl_8055E2E0, &lbl_8055A0EC, &lbl_8055A0DC, timeStr); // "timer": "%s"
        }
    }
    return 0;
}
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
/* Returns 1 if the object's virtual v7() reports nonzero and its enabled flag at offset 0x90 is set, otherwise 0. */
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
/* Destroys/clears two embedded subobjects at offsets 0xE0 and 0x34 and optionally finalizes. */
void *fn_80163658(void *obj, s32 freeFlag) {
    if (obj != 0) {
        if (obj != 0) {
            if ((u32)obj + 0xE0 != 0) {
                if ((u32)obj + 0xE0 != 0) {
                    ((s32 *)obj)[56] = 0;
                    ((s32 *)obj)[57] = 0;
                    ((s32 *)obj)[58] = 0;
                }
            }
            if (obj != 0) {
                if ((u32)obj + 0x34 != 0) {
                    if ((u32)obj + 0x34 != 0) {
                        ((s32 *)obj)[13] = 0;
                        ((s32 *)obj)[14] = 0;
                        ((s32 *)obj)[15] = 0;
                    }
                }
            }
        }
        if (freeFlag > 0) fn_80128668(obj);
    }
    return obj;
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
    u32 j;
    char *obj2;
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
        obj2 = (char *)*(void **)(self + 0xE0) + secondOffset;
        fn_801EA140(obj2);
        *(float *)(obj2 + 4) += *(float *)(obj2 + 0x38);
        if (*(s32 *)(obj2 + 0x34) != 0) {
            char *child;
            for (j = 0, child = obj2 + 0xC; j < 2; j++, child += 0xC)
                fn_801EA140(child);
        }
        *(u8 *)(obj2 + 0x3C) = 1;
        if (*(s32 *)(obj2 + 0x34) != 0) {
            ((void (*)(void *, void *))fn_802A95A8)(obj2 + 0x24, obj2 + 0x2C);
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

/* Return this object's +0x56C progress-reached flag. */
u8 fn_80163864(void *obj) {
    return *((u8 *)obj + 0x56C);
}

/* On event type 5, while this object's stop flag (+0x56D) is still clear: set
 * the flag at +0x56C when progressValue reaches the value at +0x570, then set
 * the stop flag. */
void fn_8016386C(void *obj, s32 eventType, s32 carIndex, s32 progressValue) {
    if (eventType == 5 && *((u8 *)obj + 0x56D) == 0) {
        if (progressValue >= *((s32 *)((char *)obj + 0x570))) {
            *((u8 *)obj + 0x56C) = 1;
        }
        *((u8 *)obj + 0x56D) = 1;
    }
}

#pragma cplusplus on
#pragma push
#pragma processor 750
// Per-frame update for the gate challenge: in its scoring phase (f7()==0) it tests each
// player truck ("PCAR") against every active gate, scoring a pass when the truck's velocity
// aligns with the gate direction or it comes within range, and finishes once the met count
// reaches its target. The alternate phase resets the trucks and advances the challenge step.
extern "C" void fn_801638A0(void *challengeMgr) {
    s32 carIndex,gateIndex;
    int *carTable;
    u8 *mgr=(u8 *)challengeMgr;
    u8 *gate;
    int *carTable2;
    s32 gateOffset;
    u8 *car,*gateFlags,*uiState;
    f32 velocity[2],length,scale;
    f32 minAlignment,one,minSpeedSq;
    f32 dirX,dirY;
    if (((*(f32 *)(mgr+0x98)>*(f32 *)(mgr+0x84))&1)!=0) mgr[0x56D]=1;
    if (fn_801C5B60()==0) fn_801DF074(8,0);
    if (((Dummy_801638A0 *)mgr)->f7()==0) {
        one=lbl_80561840; minAlignment=lbl_80561854; minSpeedSq=lbl_80561850;
        for (carIndex=0,carTable=lbl_804348E8;carIndex<fn_801B2F24();carTable++,carIndex++) {
            car=(u8 *)*carTable;
            if (*(u32 *)(car+0x10)!=CAR_TAG_PLAYER_CAR) continue;
            for (gateIndex=0,gateOffset=0;gateIndex<*(s32 *)(mgr+0xE4);gateOffset+=0x48,gateIndex++) {
                gate=(u8 *)*(s32 *)(mgr+0xE0)+gateOffset;
                if (!gate[0x3C]) continue;
                if (*(s32 *)(gate+0x34)) {
                    if (fn_80139B5C(car,*(s32 *)(gate+0x34))) {
                        gateFlags=gate+carIndex;
                        if (!gateFlags[0x3D]) {
                            velocity[0]=*(f32 *)(car+0x118);
                            velocity[1]=*(f32 *)(car+0x120);
                            length=velocity[0]*velocity[0]+velocity[1]*velocity[1];
                            if (length>minSpeedSq) {
                                length=(f32)fn_8002F234(length);
                                dirY=*(f32 *)(gate+0x30);
                                scale=one/length;
                                dirX=*(f32 *)(gate+0x2C);
                                velocity[0]*=scale;
                                velocity[1]*=scale;
                                if (velocity[0]*dirX+velocity[1]*dirY>minAlignment) {
                                    ++*(s32 *)(mgr+0x94);
                                    gate[0x3C]=0;
                                    uiState=*(u8 **)(mgr+0xDC);
                                    uiState[0x49]=1; uiState[0x4B]=0; uiState[0x4A]=0;
                                }
                            }
                        }
                        gateFlags[0x3D]=1;
                        break;
                    } else if (gate[0x3C]) (gate+carIndex)[0x3D]=0;
                } else if (PSVECSquareDistance(gate,car+0x60)<*(f32 *)(mgr+0xCC)**(f32 *)(mgr+0xCC)) {
                    ++*(s32 *)(mgr+0x94);
                    gate[0x3C]=0;
                    uiState=*(u8 **)(mgr+0xDC);
                    uiState[0x49]=1; uiState[0x4B]=0; uiState[0x4A]=0;
                    break;
                }
            }
        }
        *(f32 *)(mgr+0x98)+=lbl_80561858;
        if (*(f32 *)(mgr+0x98)>=*(f32 *)(mgr+0x84)) ((Dummy_801638A0 *)mgr)->f22(3);
        if (*(s32 *)(mgr+0x94)>=*(s32 *)(mgr+0x80)&&mgr[0x9C]) {
            ((Dummy_801638A0 *)mgr)->f22(1);
            mgr[0x88]=1;
        }
    } else {
        if ((f32)__fabs(*(f32 *)(mgr+0x8C))<=lbl_80558DC4[0]) {
            fn_80276DC8(0);
            for (carIndex=0,carTable2=lbl_804348E8;carIndex<fn_801B2F24();carTable2++,carIndex++) {
                Dummy_801638A0 *manager=(Dummy_801638A0 *)fn_801B83A0();
                manager->f35((void *)*carTable2,carIndex);
            }
        }
        *(f32 *)(mgr+0x8C)+=lbl_80561858;
        if (mgr[0x90]) {
            if (((Dummy_801638A0 *)mgr)->f8()&&lbl_8055E304==fn_80160CE4()) {
                s32 prevStep=lbl_8055A0B8;
                lbl_8055E2DC=1;
                lbl_8055A0B4=prevStep;
                lbl_8055A0B8=prevStep+1;
            } else lbl_8055E2DC=0;
            lbl_8055E304=0;
            if (*(s32 *)(lbl_8042FDEC+4)>0) fn_80176734();
        }
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma cplusplus on
// Draws the countdown-timer HUD.  While the timed run is still going (the flag at
// +0x56D clear), play time has passed the object's own delay (vtable slot 0x34)
// and the run has not ended (vtable slot 0x28): it shows the "timer_art" graphic
// and the "timer_title" caption and writes the time left -- the target time at
// +0x84 minus the time run at +0x98 -- into the "timer" text element.
// Returns 0 so the HUD object stays on the draw list.
extern "C" s32 fn_80163C38(void *arg0) {
    class HudObject {
    public:
        virtual void m08(); virtual void m0C(); virtual void m10(); virtual void m14();
        virtual void m18(); virtual void m1C(); virtual void m20(); virtual void m24();
        virtual s32 isOver();   // vtable slot 0x28: the run has already ended
        virtual void m2C(); virtual void m30();
        virtual f32 getDelay(); // vtable slot 0x34: seconds of play before the timer shows
    };
    class UiManager {
    public:
        virtual void m08();
        virtual void *getText(const char *); // vtable slot 0xC: named text element
        virtual void *getArt(const char *);  // vtable slot 0x10: named graphic element
    };
    char timeStr[0x14];
    HudObject *obj = (HudObject *)arg0;
    f32 playTime;
    if (*((u8 *)arg0 + 0x56D) == 0) { // timer not stopped
        playTime = lbl_8055E3C8; // seconds played so far
        if (playTime > obj->getDelay()) {
            if (obj->isOver() == 0) {
                fn_801476D8((s32)((UiManager *)lbl_8055E2E0)->getArt(lbl_8032FA38), -1, lbl_8055E2F8); // "timer_art"
                ((void (*)(void *))fn_801476C4)(((UiManager *)lbl_8055E2E0)->getText(lbl_8032FA44)); // "timer_title"
                fn_80130980(timeStr, 0x14, 3, *(f32 *)((u8 *)arg0 + 0x84) - *(f32 *)((u8 *)arg0 + 0x98));
                fn_801475D0(lbl_8055E2E0, &lbl_8055A0EC, &lbl_8055A0DC, timeStr); // "timer": "%s"
            }
        }
        return 0;
    }
    return 0;
}
#pragma cplusplus off

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
/* Return the timed-run/HUD object's +0x56D flag: whether its countdown timer has been stopped. */
unsigned char fn_80163F6C(void *hud) {
    return *((unsigned char *)hud + 0x56D);
}

/* Return the timed-run/HUD object's +0x56D flag: whether its countdown timer has
 * been stopped. */
unsigned char fn_80163F74(void *hud) {
    return *((unsigned char *)hud + 0x56D);
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
        *(f32 *)(self + 0xCC) = first * 0.5f;
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
            register s32 i;
            register s32 bestIndex;
            register s32 count;
            register volatile f32 *points;
            points = (f32 *)((u8 *)table + 8);
            count = *(s32 *)table;
            {
                f32 best = -999.0f;
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
                *(f32 *)(out + 0x10) = 0.0f;
                *(f32 *)(out + 0x14) = y0;
                i = bestIndex % count2;
                x1 = points[i * 2];
                y1 = points[i * 2 + 1];
                *(f32 *)(out + 0x18) = x1;
                *(f32 *)(out + 0x1C) = 0.0f;
                *(f32 *)(out + 0x20) = y1;
                *(f32 *)(out + 0x24) = (x0 + x1) * 0.5f;
                *(f32 *)(out + 0x28) = (y0 + y1) * 0.5f;
                i = (bestIndex + 1) % count2;
                work.vectors[0] = points[i * 2] - x1;
                work.vectors[1] = 0.0f;
                work.vectors[2] = points[i * 2 + 1] - y1;
                work.vectors[3] = x0 - x1;
                work.vectors[4] = 0.0f;
                work.vectors[5] = y0 - y1;
                PSVECNormalize(&work.vectors[0], &work.vectors[0]);
                PSVECNormalize(&work.vectors[3], &work.vectors[3]);
                PSVECCrossProduct(&work.vectors[0], &work.vectors[3], &work.vectors[6]);
                if (work.vectors[7] > 0.0f) {
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
int fn_801643C8(void *self) {
    /* Free each 0x48-byte entry's point table (+0x34) in the array at +0xE0
     * (count at +0xE4), destroy the sub-object at +0xDC if present, and release
     * the texture (+0xD0) and model (+0xA0) handles. */
    extern void fn_80128658(int);
    extern void fn_802CAC54(int);
    extern void fn_802C6CF8(int);
#pragma cplusplus on
    struct DeletableObject {
        virtual void destroy(int);
    };
#pragma cplusplus off
    int entryOffset = 0;
    int entryIndex = 0;
    void *obj;
    while (entryIndex < *((int *)((char *)self + 0xE4))) {
        int pointTable;
        int *entryWords;
        obj = *((void **)((char *)self + 0xE0));
        entryWords = (int *)((char *)obj + entryOffset);
        pointTable = entryWords[0x34 / 4];
        if (pointTable != 0) {
            fn_80128658(pointTable);
        }
        entryOffset += 0x48;
        entryIndex += 1;
    }
    obj = *((void **)((char *)self + 0xDC));
    if (obj != 0) {
        ((struct DeletableObject *)obj)->destroy(1);
    }
    fn_802CAC54(*((int *)((char *)self + 0xD0)));
    fn_802C6CF8(*((int *)((char *)self + 0xA0)));
}
/* True while the fade/elapsed value at +0x8C is below the halfway point (lbl_8056185C = 0.5). */
int fn_80164468(void *object) {
    return *((float *)((char *)object + 0x8C)) < lbl_8056185C;
}

#pragma cplusplus on
extern "C" void fn_80020434(int *, float *);
extern "C" void Camera_SetViewMatrix(int *, int, float);
extern "C" void fn_8000C630(int, int);
#pragma cplusplus on
extern "C" void fn_80164480(void *arg0) {
    /* If object is active, trigger event 0x15 or 0x20 based on elapsed time threshold. */
    int sp10[12];
    float sp8;

    if (((Dummy_801638A0 *)arg0)->f7() != 0) {
        if ((lbl_8055E3C8 - *((float *)((char *)arg0 + 0xC))) > lbl_80561868) {
            fn_80020434(sp10, &sp8);
            Camera_SetViewMatrix(sp10, 0, sp8);
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
/* Draw each active entry's sprite when the object is initialized and drawing is enabled. */
void fn_80164510(void *arg0, s32 arg1) {
    s32 entryOffset;
    s32 savedColorState;
    s32 savedDrawState;
    s32 i;
    void *entry;

    savedColorState = fn_802C9950(-0x100);
    savedDrawState = fn_802C9994(0);
    if (*(s32 *)((char *)arg0 + 0xA0) != -1) {
        i = 0;
        entryOffset = 0;
        while (i < *(s32 *)((char *)arg0 + 0xE4)) {
            entry = (char *)*(void **)((char *)arg0 + 0xE0) + entryOffset;
            if (*(u8 *)((char *)entry + 0x3C) != 0 && *(s32 *)((char *)entry + 0x34) != 0 && *(u8 *)((char *)arg0 + 0xD8) != 0) {
                fn_802A96E8((char *)entry + 0xC, 2, *(s32 *)((char *)arg0 + 0xD4), *(s32 *)((char *)arg0 + 0xD0), 0);
            }
            entryOffset += 0x48;
            i++;
        }
    }
    fn_802C9950(savedColorState);
    fn_802C9994(savedDrawState);
}
#pragma use_lmw_stmw reset
extern s32 lbl_8055A0E0;
extern s32 lbl_8055A0E8;
extern u8 lbl_8055E2DD;
/* Handle special key/button inputs (0x58, 0x1B) when a timer/value at +0x8C is above threshold; sets flags and returns nonzero on handled input. */
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

s32 fn_80164634(void *hud) {
    /* HUD timer: true once the elapsed value (+0x98) has passed its limit (+0x84). */
    return *(float *)((char *)hud + 0x98) > *(float *)((char *)hud + 0x84);
}

extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern void fn_801345D8(char *, s32, const char *, s32);
extern s32 fn_80146C2C(s32, s32);
extern char lbl_8032FB90[];
extern const char lbl_8055A110, lbl_8055A118;

#pragma cplusplus on
/* The scene's named parameter list: hasName (vtable slot 1) says whether a name
   is in it, getValue (slot 3) hands back the object stored under it. */
struct NameList_8016464C {
    virtual void slot0();
    virtual s32 hasName(const char *);
    virtual void slot2();
    virtual void *getValue(const char *);
};
/* The "tutcmd.val" table fn_80131810 parses.  Its first virtual turns one of
   the parameter list's value objects into the collection of items that value
   names; fn_80146C2C builds a value object out of such a collection for the
   screen that asked. */
struct ValueTable_8016464C {
    virtual void *getCollection(void *value);
};
/* fn_8016464C's object: the parameter list its names are read out of, and the
   (description, value) table it builds from them. */
struct State_8016464C {
    u8 pad0[4];
    void *list;
    u8 pad8[0x2C];
    void *entries;
    s32 entryCount;
};
/* One entry of that table: the "desc<N>" object, and the value object its
   "lyt<N>" name resolves to (0 when it has none). */
struct Entry_8016464C {
    void *object;
    s32 value;
};
#pragma cplusplus on
extern "C" void fn_8016464C(void *state) {
    /* Build this object's (description, value) table out of the scene's named
     * parameter list.  "desc1", "desc2", ... in the list are the descriptions;
     * their number is found by looking for the first "desc<N>" the list does
     * not have.  An entry that also has a "lyt<N>" parameter gets a value as
     * well: the name that "lyt<N>" holds is looked up in the "tutcmd.val"
     * value table, and the collection it resolves to is turned into a value
     * object owned by the current screen (lbl_8055E2E4) and stored next to the
     * description.  The value table is released again on the way out. */
    State_8016464C *self = (State_8016464C *)state;
    char name[0x10];
    Entry_8016464C *entry;
    s32 count;
    void *valueTable;
    s32 i;

    self->entryCount = 0;
    valueTable = fn_80131810(lbl_8032FB90); /* "tutcmd.val" */
    count = 0;
    do {
        count++;
        /* name = "desc<count>" */
        ((void (*)(char *, s32, const char *, ...))fn_801345D8)(name, 0x10, (const char *)&lbl_8055A110, count);
    } while (((NameList_8016464C *)self->list)->hasName(name) != 0);

    i = 0;
    while (i < count - 1) {
        s32 index = i + 1;
        entry = &((Entry_8016464C *)self->entries)[self->entryCount++];
        /* name = "desc<index>": the entry's description object */
        ((void (*)(char *, s32, const char *, ...))fn_801345D8)(name, 0x10, (const char *)&lbl_8055A110, index);
        entry->object = ((NameList_8016464C *)self->list)->getValue(name);
        /* name = "lyt<index>": the name of the value table entry, if any */
        ((void (*)(char *, s32, const char *, ...))fn_801345D8)(name, 0x10, (const char *)&lbl_8055A118, index);
        entry->value = 0;
        if (((NameList_8016464C *)self->list)->hasName(name) != 0) {
            void *value = ((NameList_8016464C *)self->list)->getValue(name);
            if (valueTable != 0) {
                void *collection = ((ValueTable_8016464C *)valueTable)->getCollection(value);
                if (collection != 0)
                    entry->value = fn_80146C2C(lbl_8055E2E4, (s32)collection);
            }
        }
        i++;
    }
    if (valueTable != 0)
        fn_80131818(valueTable);
}
/* Destroy all owned objects in the list and reset its count. */
extern "C" void fn_801647DC(void *list) {
    struct Object {
        virtual void method(s32);
    };
    s32 offset;
    s32 index;
    void *object;

    offset = 0;
    index = 0;
    while (index < *(s32 *)((char *)list + 0x38)) {
        object = *(void **)((char *)(*(s32 *)((char *)list + 0x34)) + offset + 4);
        if (object != 0) {
            if (object != 0) {
                ((Object *)object)->method(1);
            }
        }
        offset += 8;
        index += 1;
    }
    *(s32 *)((char *)list + 0x38) = 0;
}
#pragma cplusplus off
/* Default predicate for this path/route object: it has no state to test,
   so it always reports success (true). */
BOOL fn_80164868(void) {
    return TRUE;
}

/* Start this object's timer if it is not running yet: record the id and the
   current play time (lbl_8055E3C8, seconds played), then mark it active. */
void fn_80164870(void *timer, s32 id) {
    if (*(u8 *)((char *)timer + 0x10) == 0) {
        *(s32 *)((char *)timer + 8) = id;
        *(u8 *)((char *)timer + 0x10) = 1;
        *(float *)((char *)timer + 0xC) = lbl_8055E3C8;
    }
}

/* Reads float element 'index' from the array at offset 0x14 of 'base' into *out; returns 1 on success. */
s32 fn_80164894(s32 base, void *out, s32 index) {
    *(float *)out = *(float *)(0x14 + base + (index << 2));
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
#pragma opt_common_subs off
s32 fn_801648AC(void *arg0, void *arg1, s32 arg2)
{
  struct State
  {
    void *node;
    float frac;
    s32 id;
  };
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
  scalePtr = ((char *) self) + (arg2 * 4);
  *((float *) (((char *) scalePtr) + 0x14)) = lbl_80561848;
  if ((*((void **) (((char *) self) + 4))) != 0)
  {
    ((void (*)(char *, s32, const char *, ...)) fn_801345D8)(place, 0x10, lbl_8032FB9C, arg2);
    obj2 = ((struct ObjInner_648 *) (*((void **) (((char *) self) + 4))))->i21(place);
    if (obj2 != 0)
    {
      pos.x = lbl_80561848;
      pos.y = lbl_80561848;
      dir.x = lbl_80561848;
      dir.y = lbl_80561848;
      p = pts;
      i = 0;
      do
      {
        ((void (*)(char *, s32, const char *, ...)) fn_801345D8)(bound, 0x10, (char *) (&lbl_8055A120), i);
        ret = ((struct Obj2_648 *) obj2)->o13(bound);
        p->x = ret.x;
        p->y = ret.y;
        p++;
        i++;
      }
      while (i < 3);
      best = 2;
      e2.y = pts[2].y - pts[0].y;
      e2.x = pts[2].x - pts[0].x;
      bestLen = (e2.x * e2.x) + (e2.y * e2.y);
      e1.y = pts[0].y - pts[1].y;
      e1.x = pts[0].x - ((0, pts[1].x));
      len01 = (e1.x * e1.x) + (e1.y * e1.y);
      if (len01 > bestLen)
      {
        bestLen = len01;
        best = 0;
      }
      e1.y = pts[1].y - pts[2].y;
      e1.x = pts[1].x - pts[2].x;
      if (((e1.x * e1.x) + (e1.y * e1.y)) > bestLen)
      {
        best = 1;
      }
      mid.x = pts[best].x + (lbl_8056185C * (pts[(best + 1) % 3].x - pts[best].x));
      mid.y = pts[best].y + (lbl_8056185C * (pts[(best + 1) % 3].y - pts[best].y));
      *((double *) (&copy)) = *((double *) (&mid));
      pos.x = copy.x;
      pos.y = copy.y;
      dir.x = pts[(best + 2) % 3].x - copy.x;
      dir.y = pts[(best + 2) % 3].y - copy.y;
      len = (float) fn_8002F234((dir.x * dir.x) + (dir.y * dir.y));
      inv = lbl_80561840 / len;
      dir.x = dir.x * inv;
      dir.y = dir.y * inv;
      if (((struct Obj2_648 *) obj2)->o10(lbl_8032FBA8, 1) != 0)
      {
        fn_801352B8(obj);
        fn_80135D60(obj, ((struct Mgr_648 *) fn_80156A40())->m1(0));
        state.node = 0;
        state.id = 0x2710;
        state.frac = lbl_80561848;
        fn_801355C0(obj, &pos, 0, &state, 0);
        node = state.node;
        frac = state.frac;
        pos.x = (*((float *) node)) + (frac * ((*((float *) (*((void **) (((char *) node) + 0x14))))) - (*((float *) node))));
        pos.y = (*((float *) (((char *) node) + 4))) + (frac * ((*((float *) (((char *) (*((void **) (((char *) node) + 0x14)))) + 4))) - (*((float *) (((char *) node) + 4)))));
        dir.x = (*((float *) (((char *) node) + 8))) + (frac * ((*((float *) (((char *) (*((void **) (((char *) node) + 0x14)))) + 8))) - (*((float *) (((char *) node) + 8)))));
        dir.y = (*((float *) (((char *) node) + 0xC))) + (frac * ((*((float *) (((char *) (*((void **) (((char *) node) + 0x14)))) + 0xC))) - (*((float *) (((char *) node) + 0xC)))));
        len = (float) fn_8002F234((dir.x * dir.x) + (dir.y * dir.y));
        inv = lbl_80561840 / len;
        dir.x = dir.x * inv;
        dir.y = dir.y * inv;
        fn_8013530C(obj, -1);
      }
      fn_801B7C8C(arg1, &pos, &dir);
      speed = ((struct Obj2_648 *) obj2)->o8((char *) (&lbl_8055A128), lbl_80561848);
      scale = lbl_8056186C * speed;
      *((float *) (((char *) arg1) + 0x30)) = (*((float *) (((char *) arg1) + 0x18))) * scale;
      *((float *) (((char *) arg1) + 0x34)) = (*((float *) (((char *) arg1) + 0x1C))) * scale;
      *((float *) (((char *) arg1) + 0x38)) = (*((float *) (((char *) arg1) + 0x20))) * scale;
      *((float *) (((char *) scalePtr) + 0x14)) = scale;
      return 1;
    }
  }
  return 0;
}
#pragma opt_common_subs reset
extern f32 lbl_80561870;
extern f32 fn_80164CD4(void);
/* Returns the fixed constant 5.0f held in the read-only global lbl_80561870. */
f32 fn_80164CD4(void) {
    return lbl_80561870;
}

#pragma cplusplus on
extern "C" void fn_80164CDC(void *arg0) {
    /* Invoke virtual method f4 (vtable slot 0x18) on the interface object held at +4, passing "title" and the empty string. */
    Obj_80164CDC *obj = *(Obj_80164CDC **)((char *)arg0 + 4);
    obj->f4(&lbl_8055A0E0, &lbl_8055A0E8);
}
#pragma cplusplus off
extern int fn_80128668(void);
int fn_80164CF8(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_80164D38(void *menu) {
    /* Reset the challenge level-select menu: nothing confirmed/done, no popup
     * shown, and selection defaulted to the first entry. */
    *(int *)((char *)menu + 8) = 1;
    *(u8 *)((char *)menu + 4) = 0;
    *(u8 *)((char *)menu + 5) = 0;
    *(u8 *)((char *)menu + 6) = 0;
    *(u8 *)((char *)menu + 7) = 0;
}

/* Empty stub (no-op placeholder among the popup/menu helpers). */
void fn_80164D58(void) {

}

/* Empty stub (no-op placeholder among the popup/menu helpers). */
void fn_80164D5C(void) {
}

/* Empty stub. */
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

/* The challenge step the player is on: the goals met when it started, and the
 * number of met goals that finishes it.  fn_80161D50 counts the mandatory goals
 * met so far, so [challenge_step_min, challenge_step_max) means "still on this
 * step"; the challenge screens advance it with challenge_step_min =
 * challenge_step_max++ (fn_80162268 and friends). */
#define challenge_step_min lbl_8055A0B4
#define challenge_step_max lbl_8055A0B8
/* The car table: one pointer per vehicle of the race (each carries its FourCC
 * tag at +0x10), and how many entries are in use. */
#define car_table lbl_804348E8
#define car_count lbl_8055E4D0
/* The challenge sub-task list (data pointer, count, capacity and an inline
 * array of pointers -- see fn_80161618), and the entry the player picked, which
 * the manager makes its current sub-task (lbl_8055E300). */
#define subtask_list lbl_8042FDEC
#define selected_subtask_index lbl_8055E304

/* The challenge level-select menu sub-task (vtable lbl_8032F790): the fields
 * fn_80164D38 resets, fn_80164F50 seeds and fn_80165058 edits from menu input. */
struct LevelSelectMenu {
    /* 0x00 */ void *vtable;
    /* 0x04 */ u8 confirmed;   /* the player confirmed the selection */
    /* 0x05 */ u8 done;        /* the menu is over (slots 0x24..0x2C answer it) */
    /* 0x06 */ u8 unk06;       /* input mode; fn_80165058 takes the other branch */
    /* 0x07 */ u8 popupShown;  /* help popup 8 has been asked for */
    /* 0x08 */ s32 selection;  /* the entry picked, 1..count of the sub-task list */
};
/* The literals the compiler pooled in .sdata2 for this function. */
#define FLOAT_ONE lbl_80561840  /* 1.0f */
#define FLOAT_ZERO lbl_80561848 /* 0.0f */
#pragma scheduling invalid_target
/* One update of the challenge level-select menu (vtable lbl_8032F790 keeps this
 * at slot 0x1C).  While the mandatory goals met so far sit inside the challenge
 * step the player is on, the menu asks for help popup 8 once, its byte +7
 * recording the request.  It then parks every vehicle of the car table: the
 * three physics floats at +0x25DC/+0x25E0/+0x25E4 go to 0, 0 and 1, and the
 * vehicle's transform block (+0x3C..+0x68, a 3x3 matrix and the anchor vector
 * added to it) is handed back through fn_8017CFFC with the anchor set to
 * (0, 999 + 20 * index, 0) and the two vectors kept at +0x118 and +0x124
 * cleared, so the trucks sit out of the way, 20 apart, while the menu is up.
 * With a choice confirmed (byte +4) the menu clears that flag, marks itself
 * done, hands the picked entry to the manager (selected_subtask_index) and
 * starts the fade out: a mode-2 switch with the fade flag for an entry of the
 * sub-task list, the plain fade for the last one. */
void fn_80164D64(void *menu, s32 unused) {
    struct MtxHead { u32 word[8]; };
    /* the transform block of +0x3C..+0x68 split where the source split it: the
     * first eight words, then the ninth word and the three anchor floats */
    struct Work { f32 vec124[3]; f32 vec118[3]; struct MtxHead mtxHead; u32 mtxTail[4]; } work;
    register u32 anchorY;
    register u32 anchorX;
    register int *carSlot;
    register int carIndex;
    register void *car;
    if (challenge_step_min <= fn_80161D50()) {
        if (challenge_step_max > fn_80161D50()) {
            if (((struct LevelSelectMenu *)menu)->popupShown == 0) {
                fn_801DF074(8, 1);
                ((struct LevelSelectMenu *)menu)->popupShown = 1;
            }
        }
    }
    for (carSlot = car_table, carIndex = 0; carIndex < car_count; carSlot++, carIndex++) {
        car = (void *)*carSlot;
        fn_8018ADBC(car, FLOAT_ONE);
        fn_8018ADB4(car, FLOAT_ZERO);
        fn_8018ADA4(car, FLOAT_ZERO);
        work.mtxHead = *(struct MtxHead *)((u8 *)car + 0x3C);
        work.mtxTail[0] = *(u32 *)((u8 *)car + 0x5C);
        anchorX = *(volatile u32 *)((u8 *)car + 0x60);
        anchorY = *(volatile u32 *)((u8 *)car + 0x64);
        work.mtxTail[1] = anchorX;
        work.mtxTail[2] = anchorY;
        work.mtxTail[3] = *(volatile u32 *)((u8 *)car + 0x68);
        ((f32 *)work.mtxTail)[1] = 0.0f;
        ((f32 *)work.mtxTail)[2] = 999.0f + 20.0f * (f32)carIndex;
        ((f32 *)work.mtxTail)[3] = 0.0f;
        work.vec124[2] = work.vec124[1] = work.vec124[0] = 0.0f;
        work.vec118[2] = work.vec118[1] = work.vec118[0] = 0.0f;
        fn_8017CFFC(car, work.mtxHead.word, work.vec118, work.vec124);
    }
    if (((struct LevelSelectMenu *)menu)->confirmed) {
        register s32 choice;
        register s32 listCount;
        fn_801796BC(0);
        choice = ((struct LevelSelectMenu *)menu)->selection;
        ((struct LevelSelectMenu *)menu)->confirmed = 0;
        ((struct LevelSelectMenu *)menu)->done = 1;
        selected_subtask_index = choice;
        listCount = *(s32 *)((u8 *)subtask_list + 4);
        if (choice < listCount)
            fn_80176780(0x8002, 0);
        else
            fn_8017691C();
    }
#undef FLOAT_ONE
#undef FLOAT_ZERO
}
#pragma scheduling invalid_target
/* Seed the challenge level-select menu: raise the "menu is up" hold flag, start
 * the selection at the number of unlocked challenge levels (clamped to the
 * challenge sub-task list count), clear the menu state bytes, set the camera and
 * the popup range values, and push the level-select popup with the two message
 * keys held in the UI string pool. */
void fn_80164F50(void *arg0) {
    extern void fn_801796BC(unsigned char);
    extern s32 fn_80131234(void *);
    extern void fn_802A95A8(f32 *, f32 *, f32, f32);
    extern void fn_80276CB0(void *, s32);
    extern void fn_801DF380(void *, s32, void (*)(void), s32);
    extern u8 lbl_8055E2DC;
    extern u8 lbl_8032F588[];
    extern u8 lbl_8042FDEC[];
    extern f32 lbl_80561848;
    u8 *menu = (u8 *)arg0;
    f32 out[2];
    f32 in[2];
    s32 unlocked;
    s32 popupMessage;
    s32 popupArg;
    u8 *uiStrings = lbl_8032F588;
    f32 upper;
    f32 lower;
    f32 floorValue;
    f32 *outPtr;
    f32 *inPtr;

    fn_801796BC(1);
    unlocked = fn_80160CE4();
    if (lbl_8055E2DC != 0 && unlocked <= *(s32 *)(subtask_list + 4)) {
        *(s32 *)(menu + 8) = unlocked;
    }
    if (*(s32 *)(menu + 8) >= *(s32 *)(subtask_list + 4)) {
        *(s32 *)(menu + 8) = *(s32 *)(subtask_list + 4);
    }
    *(u8 *)(menu + 4) = 0;
    upper = 9999.0f;
    outPtr = out;
    lower = 1.0f;
    inPtr = in;
    *(u8 *)(menu + 6) = 0;
    floorValue = lbl_80561848;
    *(u8 *)(menu + 5) = 0;
    outPtr[0] = upper;
    outPtr[1] = upper;
    inPtr[0] = lower;
    inPtr[1] = floorValue;
    fn_802A95A8(outPtr, inPtr, lower, upper);
    fn_80276CB0(uiStrings + 0x630, 0);
    popupMessage = fn_80131234(uiStrings + 0x654);
    popupArg = fn_80131234(uiStrings + 0x63C);
    fn_801DF380((void *)popupArg, popupMessage, (void (*)())fn_80161438, 0);
}
extern void fn_801796BC(unsigned char);
typedef struct Work_80164D64 {
    f32 vectorA[3];
    f32 vectorB[3];
    u32 data[12];
} Work_80164D64;
/* Level-select menu vtable getter (slot 0x24): reports the `done` flag set by fn_80164D64; siblings fn_80165048/0x50 are identical. */
unsigned char fn_80165040(void *menu) {
    return ((struct LevelSelectMenu *)menu)->done;
}

/* Level-select menu vtable getter (slot 0x28): reports the `done` flag; identical to siblings fn_80165040/0x50. */
unsigned char fn_80165048(void *menu) {
    return ((struct LevelSelectMenu *)menu)->done;
}

/* Level-select menu vtable getter (slot 0x2C): reports the `done` flag; identical to siblings fn_80165040/0x48. */
unsigned char fn_80165050(void *menu) {
    return ((struct LevelSelectMenu *)menu)->done;
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
/* Default virtual: returns 0.0f, held by the original as a .sdata2 float (lbl_80561848). */
f32 fn_80165238(void) {
    return 0.0f;
}

/* Level-select menu vtable slot 0x3C: default/no-op virtual returning 0. */
int fn_80165240(void) {
    return 0;
}

/* Empty stub. */
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
extern "C" s32 fn_8016524C(void *a){
 struct M{virtual void f0();virtual void*f1(const char*);virtual void*f2(const char*);virtual void*f3(const char*);};
 struct N{virtual void g0();virtual void g1();virtual void g2();virtual void g3();virtual const char*g4(const char*,s32);};
 struct H{s32 v; s32 p[7]; N*n;};
 struct E{virtual void h0();virtual void h1();virtual void h2();virtual void h3();virtual void h4();virtual void h5();virtual void h6();virtual void h7();virtual void h8();virtual void h9();virtual void ha();virtual void hb();virtual void hc();virtual void hd();virtual void he();virtual void hf();virtual void hg();virtual void hh();virtual void hi();virtual void hj();virtual void hk();virtual s32 label();};
 struct P{s32 x; s32 y;};
 struct R{s32 a; P p; s32 d; f32 e; s32 f; u32 c; s32 h;};
 struct R7{s32 a; P p; s32 d; f32 e; f32 f; u32 c;};
#define FX(r)(*(f32*)&(r).p.x)
#define FY(r)(*(f32*)&(r).p.y)
 char*t=(char*)lbl_8032F588; H*h; void*r24,*r25,*r26,*r27; R7 c3,c2,c1; R c0; char b[10]; f32 amt; u8 al;
 if(*((u8*)a+6)!=0){s32 f=fn_80131234(t+0x680);s32 s=fn_80131234(t+0x66C);((void(*)(s32,s32))fn_80161438)(s,f);}
 else{
  if(fn_801E8838()>100)fn_80230E90(1);
  fn_801476D8((s32)((M*)lbl_8055E2E0)->f2((const char*)&lbl_8055A0F8),-1,lbl_8055E2E8);
  fn_801476D8((s32)((M*)lbl_8055E2E0)->f2((const char*)&lbl_8055A100),-1,lbl_8055E2EC);
  h=(H*)((void*(*)(s32))fn_8001285C)(*__AXFXGetLfoSinTable_801769CC());
  ((M*)lbl_8055E2E0)->f1(t+0x694); fn_801476C4();
  fn_801473F8(lbl_8055E2E0,t+0x6A0,(const char*)&lbl_8055A0DC,h->n->g4(t+0x6AC,fn_80012910(h->v)));
  ((M*)lbl_8055E2E0)->f1(t+0x110); fn_801476C4();
  r24=((M*)lbl_8055E2E0)->f1(&lbl_8055A130); r25=((M*)lbl_8055E2E0)->f1(&lbl_8055A138);
  r26=((M*)lbl_8055E2E0)->f3(&lbl_8055A140); r27=((M*)lbl_8055E2E0)->f3(t+0x6BC);
  if(r24!=0&&r25!=0){
   f32 f31,f30,f29;
   f30=lbl_8056185C; f31=lbl_80561840; f29=lbl_80561848;
   s32 i=1; s32 flag; s32 off=4;
   for(;i<=*(s32*)(lbl_8042FDEC+4);off+=4,i++){
    R*src;
    ((void(*)(char*,s32,const char*,...))fn_801345D8)(b,10,&lbl_8055A148,i);
    src=(R*)((M*)lbl_8055E2E0)->f1(b);
    if(src!=0){
     f32 dy,dx; c0=*src;
     dx=FX(c0)-*(f32*)&((R*)r24)->p.x; dy=FY(c0)-*(f32*)&((R*)r24)->p.y;
     c1=*(R7*)r26; flag=(i!=*(s32*)((u8*)a+8));
     if(i>fn_80160CE4()&&i!=*(s32*)(lbl_8042FDEC+4))c1.c=0x55FFFFFF;
     FY(c1)+=dy; FX(c1)+=dx; fn_80147940(lbl_8055E2E0,&c1,t+0x6C8,flag);
     if(i>fn_80160CE4()&&i<*(s32*)(lbl_8042FDEC+4))c0.c=((R*)r25)->c; else c0.c=((R*)r24)->c;
     al=0xFF; amt=f29;
     if(i==*(s32*)((u8*)a+8)){
      fn_80230F78(&al,&amt,&c0.c,1);
      FX(c1)-=f30*c1.e*amt; FY(c1)-=f30*c1.f*amt;
      c1.e=c1.e*(f31+amt); c1.f=c1.f*(f31+amt);
      c1.c=(c1.c&0x00FF0000)|((u32)al<<24)|(c1.c&0xFFFF);
      fn_80147940(lbl_8055E2E0,&c1,t+0x6C8,flag);
     }
     if(i!=*(s32*)(lbl_8042FDEC+4)){
      if(i<fn_80160CE4()){
       c2=*(R7*)r27; FY(c2)+=dy; FX(c2)+=dx;
       fn_80147940(lbl_8055E2E0,&c2,t+0x6D8,2);
      }else{
       s64 cur=fn_80160CE4(); c3=*(R7*)r27; FY(c3)+=dy; FX(c3)+=dx;
       if(cur!=(s64)(u32)i)c3.c=0x55FFFFFF;
       fn_80147940(lbl_8055E2E0,&c3,t+0x6D8,3);
      }
     }
     if(i<*(s32*)(lbl_8042FDEC+4)){
      E*e=*(E**)(*(s32*)lbl_8042FDEC+off);
      ((void(*)(R*,const char*,...))fn_80147230)(&c0,(const char*)&lbl_8055A0DC,e->label());
     }else ((void(*)(R*,const char*,...))fn_80147230)(&c0,(const char*)&lbl_8055A0DC,fn_80131234(t+0x66C));
    }else if(!lbl_8055E308){lbl_8055E308=1;((void(*)(const char*,const char*,...))fn_802E30C8)((const char*)&lbl_8055A0DC,t+0x6E8);}
   }
  }
 }
 return 1;
}
#pragma cplusplus off

int fn_801657D4(void) {
    /* No-op default callback among the level-select/UI handlers: always reports handled (1). */
    return 1;
}

/* Captures the current view transform and scale, applies them, then sets the state to 0x15 for all players. */
void fn_801657DC(void) {
    int viewData[12];
    float viewScale;

    fn_80020434(viewData, &viewScale);
    Camera_SetViewMatrix(viewData, 0, viewScale);
    fn_8000C630(0x15, -1);
}

/* Empty stub. */
void fn_80165820(void) {
}

/* No-op default callback returning 0, one of the placeholder handlers for the challenge-list UI (fn_80165820/0x2C/0x40). */
int fn_80165824(void) { return 0; }

/* No-op default callback returning 0, sibling of fn_80165824 in the challenge-list UI placeholder block. */
int fn_8016582C(void) { return 0; }

/* AX "get studio name" accessor stub, dispatched indirectly through a function-pointer table; this build returns the placeholder label string "Challenge List" (lbl_8032FCB0). */
void *__AXGetStudio_80165834(void) {
    #define sStudioName lbl_8032FCB0
    return sStudioName;
    #undef sStudioName
}

/* No-op default callback returning 0, sibling of fn_80165824/0x2C in the challenge-list UI placeholder block. */
int fn_80165840(void) {
    return 0;
}

#pragma dont_inline on
int fn_80165848(int arg0, int arg1, int arg2, int arg3, int arg4, int *outFlags) {
    /* Sets status flags and reports handled when fn_80161BB8 indicates active. */
    if (fn_80161BB8() != 0) {
        *outFlags |= 0x1150;
        return 1;
    }
    return 0;
}
#pragma dont_inline off

#pragma cplusplus on
extern "C" int fn_80165894(s32 unused0, s32 unused1, float *outValue, s32 index) {
    /* If the slot at index is active, writes a default value and dispatches to
     * a cached object's virtual method (slot 12). Always returns 0. */
#define cacheSlotActive lbl_804348E8
#define cacheTableBase lbl_8042FDEC
#define cacheObjectIndex lbl_8055E304
#define cacheDefaultValue lbl_80561848
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
    if (cacheSlotActive[index]) {
        *outValue = cacheDefaultValue;
        ((CacheObject **)(*(char **)cacheTableBase))[cacheObjectIndex]->invoke(outValue, index);
    }
    return 0;
#undef cacheSlotActive
#undef cacheTableBase
#undef cacheObjectIndex
#undef cacheDefaultValue
}
#pragma cplusplus off
/* Placeholder handler for the challenge-list UI: always answers "yes".  Reached only
 * through the module's callback table, and paired with fn_80165908, which always
 * answers "no". */
int fn_80165900(void) { return 1; }

/* Default stub handler: returns 0 (companion to fn_80165900, which returns 1). */
int fn_80165908(void) { return 0; }
typedef struct VtblA18 { void *pad[7]; void (*f)(void); } VtblA18;
typedef struct ObjA18 { VtblA18 *vtable; } ObjA18;
struct Vtbl_80163D34 { void *v[4]; void (*method)(void *, const char *); };
struct Obj_80163D34 { struct Vtbl_80163D34 *vt; };

