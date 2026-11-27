// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void fn_802E30C8(const char *, ...);
extern "C" s32 fn_80128314(s32);
extern "C" void fn_802E0F98(void);
extern "C" void fn_8012BEF0(const char *);
extern "C" void fn_800125C4(void);
extern "C" void fn_800125D4(const char *, s32);
extern "C" void fn_8020A47C(void);
extern "C" void fn_8023889C(void);
extern "C" void fn_8022A5E4(void);
extern "C" void fn_80216710(void);
extern "C" s32 ArtSetGet(const char *);
extern "C" void *fn_8022D228(void *, s32, s32);
extern "C" void fn_8022D350(s32, const char *, s32);
extern "C" void *uiCreateTable(void *, s32, s32, s32 *);
extern "C" void UITable_WriteCell(s32, s32, s32, const char *, s32);
extern "C" void *fn_8022DB50(void *, const char *, const char *, s32, s32);
extern "C" void *fn_8022DCC4(void *, s32 *, s32, s32);
extern "C" s32 fn_80207848(const char *, s32);
extern u8 lbl_8033CAE8[];
extern "C" unsigned char lbl_80490558[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" char *lbl_8055B6B0;
extern "C" int lbl_8055EF40;
extern "C" float lbl_8055EF10;
extern "C" float lbl_80563434;
extern "C" void *lbl_8055EF38;
extern "C" void *fn_801284F8(s32, const char *);
struct S12Ptr { char *v[12]; };
struct S3Word { s32 w[3]; };
struct Ent18 { const char *name; f32 f; s32 v[4]; };
extern "C" S12Ptr lbl_802F9E68;
extern "C" S3Word lbl_802F9E98;
extern "C" s32 lbl_8055EF08;
extern "C" s32 lbl_8055EF3C;
extern "C" char lbl_8055B718;
extern "C" s32 lbl_80563430;
extern "C" f32 lbl_80563438;
extern "C" f32 lbl_8056343C;
extern "C" void *memset(void *, int, unsigned long);
extern "C" void fn_802ECC18(int);
extern "C" void fn_8022D2BC(s32, s32);
extern "C" void fn_8022D7C4(s32, s32);
extern "C" void fn_8022DB94(s32, s32);
extern "C" void fn_8022DD38(s32, s32);
extern "C" void fn_8021676C(void);
extern "C" void fn_8022A7D0(void);
extern "C" void fn_8020A550(void);
extern "C" void fn_80235380(s32);
extern "C" void fn_802C519C(s32);
extern "C" void fn_80238920(void);
extern "C" void fn_8012BF24(void *);
extern "C" void fn_802E1058(void);
extern "C" s32 lbl_80490528[];
extern "C" char lbl_8033CC10[];
extern "C" char lbl_8033CD88[];
extern "C" s32 lbl_8055EF18;
extern "C" s32 lbl_8055EF1C;
extern "C" s32 lbl_8055EF20;
extern "C" s32 lbl_8055EF24;
extern "C" s32 lbl_8055EF28;
extern "C" s32 lbl_8055EF2C;
extern "C" s32 lbl_8055EF30;
extern "C" s32 lbl_8055EF34;
extern "C" void fn_80127A24(void);
extern "C" void *fn_8022E4C0(void *);
extern "C" void *loadLayout(const void *);
extern "C" void fn_80276D3C(void *, s32);
extern "C" void DrawList_RestoreNormalMode(void);
extern "C" void DrawList_endMeshPass(void);
extern "C" s32 gxGetImageArt(char *);
extern "C" s32 gxGetImageWidth(void *);
extern "C" s32 gxGetImageHeight(void *);
extern "C" void *fn_80216770(const char *, s32, s32, s32, s32, s32);
extern "C" void *fn_80216D40(void *, const char *, s32, s32, s32, s32, s32);
extern "C" int strcmp(const char *, const char *);
extern "C" void fn_80236914(void);
extern "C" char lbl_8033D590[];
extern "C" char lbl_8055B7F8[8];
extern "C" char lbl_8055B7FC[8];
extern "C" s32 lbl_8055CFF0;
extern "C" s32 lbl_8055CFF4;
extern "C" void *lbl_8055EF44;
extern "C" void *lbl_8055EF38;
extern "C" void *fn_8022E4C0(void *);
extern "C" void *loadLayout(const void *);
extern "C" void fn_80276D3C(void *, s32);
extern "C" void DrawList_RestoreNormalMode(void);
extern "C" void DrawList_endMeshPass(void);
extern "C" s32 gxGetImageArt(char *);
extern "C" s32 gxGetImageWidth(void *);
extern "C" s32 gxGetImageHeight(void *);
extern "C" void *fn_80216770(const char *, s32, s32, s32, s32, s32);
extern "C" void *fn_80216D40(void *, const char *, s32, s32, s32, s32, s32);
extern "C" int strcmp(const char *, const char *);
extern "C" void fn_80236914(void);
extern "C" char lbl_8033D590[];
extern "C" char lbl_8055B6A8;
extern "C" char lbl_8055B7F8[8];
extern "C" char lbl_8055B7FC[8];
extern "C" s32 lbl_8055CFF0;
extern "C" s32 lbl_8055CFF4;
extern "C" void *lbl_8055EF44;
extern "C" void fn_802141A0(void **, void *, s32, s32, s32, s32);
extern "C" void fn_80218D54(void *, s32);
extern "C" void fn_80212340(void *);
extern "C" s32 fn_802168F0(void *);
extern "C" void fn_8021683C(void *);
extern "C" void fn_80236918(void *, void *, void (*)(void));
extern "C" void fn_80236950(void);
extern "C" void fn_802D08C4(s32);
extern "C" void fn_802E3D00(void);
extern "C" void fn_802E47E8(void);
extern "C" char lbl_8033D1E0[];
extern "C" u8 *lbl_8055B6BC;

extern "C" s32 fn_80218C14(s32, s32);
extern "C" s32 Abend_Panic(const char *);
extern "C" s32 fn_80214934(const void *, s32, void *, s32);
extern "C" s32 fn_80029004(const char *, s32);
extern "C" s32 fn_801345D8(void *, s32, const char *, s32, s32, const char *);
extern "C" unsigned long strlen(const char *);
#pragma small_data on
extern "C" char lbl_8055B808[8];
#define PATH_FORMAT_DIR_NAME lbl_8055B808  // "%s\\%.*s": a directory and a name cut at its '.'

extern "C" __declspec(section ".sdata") const char lbl_8055B724[], lbl_8055B728[], lbl_8055B720[], lbl_8055B730[];
extern "C" __declspec(section ".sdata") const char lbl_8055B738[], lbl_8055B73C[], lbl_8055B744[], lbl_8055B748[];
#pragma small_data off
extern "C" s32 stampGetFrameCount(s32);
extern "C" s32 gxCanvasDrawStamp(s32, s32, s32, s32, s32);
extern "C" s32 fn_8021481C(void *);
extern "C" char lbl_8033D388[];
extern "C" char lbl_8033D268[];
extern "C" char lbl_8055B810;
#define TRANSITION_DIR_IN lbl_8055B810  // "transin": directory holding the enter-transition scripts

extern "C" s32 fn_802168E4(void);
extern "C" s32 fn_802168DC(s32, s32);
extern "C" s32 fn_802168D4(s32);
extern "C" s32 fn_802168CC(s32, float);
extern "C" s32 fn_802168E0(s32, s32, s32);
extern "C" char lbl_8033D2E0[];
extern "C" char lbl_8033D328[];
extern "C" char lbl_8033D2A0[];
extern "C" char lbl_8033D274[];

extern "C" s32 fn_802180E0(s32, s32);
extern "C" char lbl_8033D3B0[];

extern "C" s32 fn_802168DC(s32, s32);
extern "C" s32 fn_802168D4(s32);
extern "C" s32 fn_802168CC(s32, float);
extern "C" s32 fn_802168E0(s32, s32, s32);
extern "C" char lbl_8033D2E0[];
extern "C" char lbl_8033D328[];
extern "C" char lbl_8033D2A0[];
extern "C" char lbl_8033D274[];

/* The widget interface the wrapper methods below forward to. CodeWarrior keeps
 * two slots at the head of the vtable (both null in lbl_8033D480 and
 * lbl_8033FA28), so vfN sits at vtable offset 0x8 + 4*N. */
class VfObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();     // vtable 0x24
    virtual void vf10();    // vtable 0x28
    virtual void vf11();    // vtable 0x2C
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
      virtual void vf16();
      virtual void vf17();
    virtual s32 vf18();     // vtable 0x50; returns a status code
    virtual void vf19();
     virtual s32 vf20();     // vtable 0x58
        virtual void vf21();    // vtable 0x5C
};

/* A widget's head, as the widget code lays it out: the vtable pointer and the
 * rectangle a move writes (fn_802191F0 keeps left, top, right and bottom
 * here).  The wrapper methods below reach it through the widget at +0x244. */
struct WidgetRect {
    void *vtable;  /* 0x00 */
    s32 left;      /* 0x04 */
    s32 top;       /* 0x08 */
    s32 right;     /* 0x0C */
    s32 bottom;    /* 0x10 */
};

extern "C" void fn_8021915C(void *, unsigned int);

extern "C" void fn_80221E7C(void);
extern "C" s32 fn_80215270(s32, s32);
extern "C" void fn_8022E4BC(s32);
extern "C" void fn_8022E960(s32);
extern "C" s32 fn_80211678(u8 *);
#pragma small_data on
extern "C" char lbl_8055B750[];
#pragma small_data off
extern "C" int sprintf(char *, const char *, ...);
extern "C" int stricmp(const char *, const char *);
extern "C" void *memcpy(void *, const void *, unsigned long);
extern u8 lbl_8033CAE8[];
extern "C" s32 fn_80214E10(s32, s32, s32);
extern "C" s32 fn_802152CC(void);
#pragma small_data on
extern "C" s32 lbl_802F9EB8[];
extern "C" s32 lbl_80490510[];
extern "C" char lbl_8033D3F8[], lbl_8033D404[];
extern "C" char lbl_8055B820, lbl_8055B824, lbl_8055B830;
extern "C" u8 lbl_8055B860;
#pragma small_data off
#pragma small_data on
extern "C" s32 lbl_802F9EB8[];
extern "C" char lbl_8033D3F8[];
extern "C" char lbl_8033D404[];
extern "C" char lbl_8055B820;
#pragma small_data off
extern "C" s32 fn_80214FE0(s32, s32, s32, s32);
extern "C" s32 fn_80206430(void);
extern "C" s32 drawTextIntArgs(s32, s32, s32, s32, s32, s32, s32, s32, s32, float);
extern "C" s32 fn_8022AC1C(s32, s32, s32, s32, s32, s32, s32, s32);
extern float lbl_80563450;
extern "C" float fn_80209028(void);
extern "C" int lbl_8055EF5C;
extern "C" unsigned char lbl_80490558[];
extern "C" char *lbl_8055B6B0;

extern "C" s32 fn_80128668(void);
extern "C" s32 (*lbl_8055EF0C)(s32 *);
extern "C" s32 fn_802168BC(s32);
extern "C" void *fn_802115AC(void *arg0, s32 arg1) {
    /* Reset the object's three 32-bit fields to 0, then free it when arg1 > 0 (deleting-destructor helper). */
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

/* Reset a three-word header and, when requested, free the object (deleting-
 * destructor helper). Returns the object pointer. */
extern "C" void *fn_80211604(void *object, s32 shouldDelete) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            ((void (*)(void *))fn_80128668)(object);
    }
    return object;
}

/* Tail-call forwarder to fn_80215270: reads a value out of gWidgetControlTable
 * (lbl_80490528) by column and row. */
extern "C" s32 fn_8021165C(s32 column, s32 row) {
    return fn_80215270(column, row);
}

extern s32 lbl_8055EF1C;
extern s32 lbl_8055EF20;
#pragma optimization_level 0
extern "C" s32 fn_80211660(s32 artIndex) {
    /* Select one of the two loaded menu-arrow art sets: index 0 returns the
     * first handle (lbl_8055EF1C), any other value the second (lbl_8055EF20). */
    if (artIndex != 0) goto selectSecond;
    return lbl_8055EF1C;
selectSecond:
    return lbl_8055EF20;
}
#pragma optimization_level reset
extern "C" s32 fn_80211678(u8 *obj) {
    /* True when the object's leading byte is the 0x24 ('$') tag; callers use it to pick a handler. */
    return ((s8) *obj - 0x24) == 0;
}

extern "C" void fn_80211690(s32 arg0) {
    const char *base = (const char *)lbl_8033CAE8;
    S12Ptr tbl;
    S3Word w3;
    char buf58[0x40];
    char buf38[0x20];
    char buf18[0x20];
    s32 sp8;
    s32 isZero;
    s32 notZero;
    s32 i, j;
    const char *r25;
    char **srow;
    s32 *drow;
    fn_802E0F98();
    lbl_8055EF40 = arg0;
    isZero = arg0 == 0;
    notZero = isZero == 0;
    lbl_8055EF18 = fn_80128314(0);
    lbl_8055EF08 = 1;
    if (isZero == 0) {
        fn_8012BEF0(base + 0x128);
        if (notZero != 0) fn_800125C4();
    }
    fn_8020A47C();
    if (isZero == 0) fn_8023889C();
    tbl = lbl_802F9E68;
    srow = tbl.v;
    drow = lbl_80490528;
    for (i = 0; i < 3; i++) {
        char **s = srow;
        s32 *d = drow;
        for (j = 0; j < 4; j++) {
            char *art = *s;
            if (isZero != 0) {
                if (i == 2 && (u32)j <= 1)
                    *d = gxGetImageArt(art);
                else
                    *d = 0;
            } else {
                *d = gxGetImageArt(art);
            }
            s++;
            d++;
        }
        srow += 4;
        drow += 4;
    }
    if (isZero == 0) {
        lbl_8055EF1C = ArtSetGet(base + 0x138);
        lbl_8055EF20 = ArtSetGet(base + 0x148);
    }
    lbl_8055EF10 = lbl_80563434;
    fn_8022A5E4();
    fn_80216710();
    if (isZero == 0) {
        void *p = fn_801284F8(0x14, base + 0x158);
        if (p != 0) p = fn_8022D228(p, 0x20, 0x40);
        lbl_8055EF24 = (s32)p;
        p = fn_801284F8(0x14, base + 0x168);
        if (p != 0) p = fn_8022D228(p, 8, 0x40);
        lbl_8055EF28 = (s32)p;
        for (i = 0; i < 0x20; i++) {
            s32 k;
            sprintf(buf58, base + 0x17C, i + 1);
            k = (i % 4) - 1;
            if (k < 0) k = 0;
            fn_8022D350(lbl_8055EF24, buf58, k);
        }
        for (i = 0; i < 8; i++) {
            sprintf(buf38, base + 0x188, i);
            fn_8022D350(lbl_8055EF28, buf38, i * 4);
        }
        sp8 = lbl_80563430;
        p = fn_801284F8(0x30, base + 0x194);
        if (p != 0) p = uiCreateTable(p, 0x14, 1, &sp8);
        lbl_8055EF2C = (s32)p;
        for (i = 0; i < *(s32 *)(lbl_8055EF2C + 0xC); i++) {
            sprintf(buf18, base + 0x1A4, i + 1);
            UITable_WriteCell(lbl_8055EF2C, i, 0, buf18, i % 3);
        }
        p = fn_801284F8(0x1C, base + 0x1B0);
        if (p != 0) p = fn_8022DB50(p, base + 0xE8, base + 0x108, 8, 0);
        lbl_8055EF30 = (s32)p;
        w3 = lbl_802F9E98;
        p = fn_801284F8(0x48, base + 0x1C4);
        if (p != 0) p = fn_8022DCC4(p, w3.w, 3, 0);
        lbl_8055EF34 = (s32)p;
    } else {
        lbl_8055EF24 = 0;
        lbl_8055EF28 = 0;
    }
    memset(lbl_80490558, 0, 0xC0);
    if (arg0 == 1) {
        Ent18 *e = (Ent18 *)lbl_80490558;
        const char *s = base + 0x1D8;
        ((Ent18 *)lbl_80490558)[0].name = base + 0x1E8; e[0].f = lbl_80563438; memset(e[0].v, 0, 0x10);
        e[2].name = s;            e[2].f = lbl_80563438; memset(e[2].v, 0, 0x10);
        e[3].name = base + 0x1F4; e[3].f = lbl_80563438; memset(e[3].v, 0, 0x10);
        e[1].name = base + 0x200; e[1].f = lbl_8056343C; memset(e[1].v, 0, 0x10);
        e[4].name = base + 0x20C; e[4].f = lbl_80563438; memset(e[4].v, 0, 0x10);
        e[5].name = base + 0x21C; e[5].f = lbl_8056343C; memset(e[5].v, 0, 0x10);
        e[6].name = s;            e[6].f = lbl_80563438; memset(e[6].v, 0, 0x10);
        e[7].name = s;            e[7].f = lbl_80563438; memset(e[7].v, 0, 0x10);
    } else {
        Ent18 *e = (Ent18 *)lbl_80490558;
        const char *s = base + 0x238;
        ((Ent18 *)lbl_80490558)[0].name = base + 0x228; e[0].f = lbl_80563438; memset(e[0].v, 0, 0x10);
        e[2].name = s;            e[2].f = lbl_80563438; memset(e[2].v, 0, 0x10);
        e[3].name = s;            e[3].f = lbl_80563438; memset(e[3].v, 0, 0x10);
        e[1].name = s;            e[1].f = lbl_80563438; memset(e[1].v, 0, 0x10);
        e[4].name = base + 0x248; e[4].f = lbl_80563438; memset(e[4].v, 0, 0x10);
        e[5].name = 0;            e[5].f = lbl_80563438; memset(e[5].v, 0, 0x10);
        e[6].name = base + 0x258; e[6].f = lbl_80563438; memset(e[6].v, 0, 0x10);
        e[7].name = base + 0x264; e[7].f = lbl_80563438; memset(e[7].v, 0, 0x10);
    }
    {
        Ent18 *e = (Ent18 *)lbl_80490558;
        for (i = 0; i < 8; i++, e++) {
            if (e->name != 0) {
                for (j = 0; j < 4; j++)
                    e->v[j] = fn_80207848(e->name, 0);
            }
        }
    }
    lbl_8055EF3C = -1;
    lbl_8055EF38 = (void *)-1;
    if (notZero != 0) fn_800125D4(base + 0x274, 0);
    {
        const char *src = lbl_8055B6B0;
        char *dst = (char *)base;
        s32 n = 0x64;
        for (;;) {
            char c = *src++;
            *dst++ = c;
            if (c != 0) {
                if (--n > 0) continue;
                dst[-1] = 0;
            }
            break;
        }
    }
    r25 = (const char *)&lbl_8055B718;
    if (isZero != 0) r25 = base + 0x280;
    fn_802E30C8(base + 0x28C, r25, (fn_80128314(0) - lbl_8055EF18) / 1024);
    fn_802ECC18(1);
}

#pragma use_lmw_stmw off
/* Shuts the UI subsystem down again; takes the same mode as the fn_80211690 bootstrap.
 * Deletes the 8x4 table of UI sound objects and clears it, frees the five tables and
 * pools that bootstrap built, and shuts the three subsystems it started back down.
 * A non-zero mode is the full teardown: it also releases the two menu-arrow art sets,
 * all twelve loaded art sets and the "uiaction.res" resource; mode 0 only drops the two
 * blinker art sets that mode had loaded. Finally logs the heap still in use when that
 * changed while the UI was up, and destroys the heap itself. */
extern "C" void shutdownUISubsystem(int mode) {
#pragma scheduling invalid_target
    struct Obj { virtual ~Obj(); };
    struct SoundSlot { char pad[8]; Obj *sounds[4]; }; /* the Ent18 fn_80211690 fills */
    int j;
    bool isMinimalShutdown;
    int i;
    int heapBytesInUse;

#define s_soundSlots      lbl_80490558 /* 8 x {name, f32, 4 sound objects} = 0xC0 bytes */
#define s_artSets         lbl_80490528 /* 3 x 4 art sets loaded by name, 0 when not loaded */
#define s_heapBytesAtInit lbl_8055EF18 /* heap in use when fn_80211690 set the UI up */

    fn_802ECC18(0); /* home-menu mode: the normal shutdown message */
    isMinimalShutdown = (mode == 0);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            Obj *sound = ((SoundSlot *)s_soundSlots)[i].sounds[j];
            if (sound != 0) delete sound;
        }
    }
    memset(s_soundSlots, 0, 0xC0);
    /* The name/id tables and pools the bootstrap allocated. */
    if (lbl_8055EF24 != 0) { fn_8022D2BC(lbl_8055EF24, 1); lbl_8055EF24 = 0; } /* 0x20 entries */
    if (lbl_8055EF28 != 0) { fn_8022D2BC(lbl_8055EF28, 1); lbl_8055EF28 = 0; } /* 8 entries */
    if (lbl_8055EF2C != 0) { fn_8022D7C4(lbl_8055EF2C, 1); lbl_8055EF2C = 0; }
    if (lbl_8055EF30 != 0) { fn_8022DB94(lbl_8055EF30, 1); lbl_8055EF30 = 0; }
    if (lbl_8055EF34 != 0) { fn_8022DD38(lbl_8055EF34, 1); lbl_8055EF34 = 0; }
    /* Back down the three subsystems fn_8020A47C, fn_8022A5E4 and fn_80216710 started. */
    fn_8021676C();
    fn_8022A7D0();
    fn_8020A550();
    if (!isMinimalShutdown) {
        if (lbl_8055EF1C != 0) fn_80235380(lbl_8055EF1C); /* the two menu-arrow art sets */
        lbl_8055EF1C = 0;
        if (lbl_8055EF20 != 0) fn_80235380(lbl_8055EF20);
        lbl_8055EF20 = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 4; j++) {
                fn_802C519C(((s32 (*)[4])s_artSets)[i][j]);
                ((s32 (*)[4])s_artSets)[i][j] = 0;
            }
        }
        fn_80238920();
        fn_8012BF24(lbl_8033CC10); /* "uiaction.res" */
    } else {
        /* Mode 0 loaded nothing but the two blinker images. */
        fn_802C519C(s_artSets[8]); /* "blinkerlt.img" */
        s_artSets[8] = 0;
        fn_802C519C(s_artSets[9]); /* "blinkerrt.img" */
        s_artSets[9] = 0;
    }
    heapBytesInUse = fn_80128314(0);
    if (heapBytesInUse != s_heapBytesAtInit) fn_802E30C8(lbl_8033CD88, heapBytesInUse, s_heapBytesAtInit); /* "UI overlap: %d K vs %d K" */
    fn_802E1058(); /* SimpleHeap_Destroy */

#undef s_soundSlots
#undef s_artSets
#undef s_heapBytesAtInit
}
#pragma use_lmw_stmw reset
extern "C" void fn_80211690(s32);
extern "C" void shutdownUISubsystem(int);
extern "C" int KERNEL_GetTimeMs(void);
extern "C" int fn_802ECC10(void);
extern "C" int lbl_8055EF14;
extern "C" float lbl_8055EF10;
extern "C" int lbl_8055EF40;
extern "C" float lbl_80563434;
extern "C" float lbl_80563440;
extern "C" float lbl_80563444;
extern "C" double lbl_80563448;
/* Bootstraps the UI subsystem (fn_80211690) in mode 1 during game-menu init. */
extern "C" void fn_80211F44(void) { fn_80211690(1); }

/* Shuts the UI subsystem down for good: the counterpart of the fn_80211F44
 * bootstrap. The non-zero argument takes shutdownUISubsystem's full-release path,
 * which also frees the two menu-arrow art sets and the 3x4 table of loaded
 * fonts (a zero argument there only drops two entries of that table). */
extern "C" void fn_80211F4C(void) { shutdownUISubsystem(1); }

extern "C" int fn_80211F54(void) {
    /* True while the UI subsystem set up by fn_80211690 has no mode active (its mode flag is still 0). */
    #define s_uiMode lbl_8055EF40
    return s_uiMode == 0;
    #undef s_uiMode
}

extern "C" void fn_80211F64(void) {
    /* Update a global delta-time value from the frame timer unless paused/disabled; always store the last tick. */
    float scaledDelta;
    float clampedDelta;
    int currentTick;
    currentTick = KERNEL_GetTimeMs();
    if (fn_802ECC10() == 0) {
        clampedDelta = lbl_80563444;
        scaledDelta = lbl_80563440 * (float)(currentTick - lbl_8055EF14);
        if (clampedDelta < scaledDelta) {
            clampedDelta = clampedDelta;
        } else {
            clampedDelta = scaledDelta;
        }
        lbl_8055EF10 = clampedDelta;
    } else {
        lbl_8055EF10 = lbl_80563434;
    }
    lbl_8055EF14 = currentTick;
}

#pragma scheduling invalid_target
extern "C" void fn_80211FF0(void) {
#define sResultCallback lbl_8055EF0C
#define RequestResult fn_802168BC
    /* Query an optional callback for a result value and, if provided, request it. */
    s32 result;
    s32 (*callback)(s32 *);
    callback = sResultCallback;
    result = -2;
    if (callback != 0) {
        if (callback(&result) != 0) {
            RequestResult(result);
        }
    }
#undef sResultCallback
#undef RequestResult
}
#pragma scheduling on
extern "C" void *fn_801284F8(s32, const char *);
extern "C" s32 fn_8012C33C(s32);
extern "C" s32 loadStamp(s32);
extern "C" s32 gxCanvasLoad(s32);
extern "C" void *fn_802228B0(void *, s32, s32, s32);
extern "C" void *fn_802226D4(s32);
#pragma use_lmw_stmw off
extern "C" void *makeImageFromPath(char *path, s32 countDivisor, s32 width, s32 height, s32 unused) {
    extern int lbl_8033D528[];
    extern char lbl_8033D504[];
    extern const char lbl_8033CDA4[];
    struct StampImage { void *vtable; void *value; };
    struct CanvasImage { void *vtable; void *value; s32 count; s32 divisor; };
    /* Allocate an image object chosen by the path's extension (the text after the
       last '.'): stp -> stamp, cvs -> canvas, img -> image, art -> art; else panic. */
    char *dot = (char *)fn_80029004(path, 0x2e);
    StampImage *stamp;
    CanvasImage *canvas;
    void *obj;
    if (stricmp(dot + 1, lbl_8055B724) == 0) {
        stamp = (StampImage *)fn_801284F8(8, lbl_8055B728);
        if (stamp) {
            stamp->vtable = lbl_8033D528;
            stamp->value = (void *)loadStamp((s32)path);
        }
        return stamp;
    }
    if (stricmp(dot + 1, lbl_8055B720) == 0) {
        canvas = (CanvasImage *)fn_801284F8(16, lbl_8055B730);
        if (canvas) {
            canvas->vtable = lbl_8033D504;
            if (fn_8012C33C((s32)path)) {
                obj = (void *)gxCanvasLoad((s32)path);
                canvas->value = obj;
                canvas->count = *(s32 *)((char *)obj + 12) / countDivisor;
            } else {
                canvas->value = 0;
                canvas->count = 0;
            }
            canvas->divisor = countDivisor;
        }
        return canvas;
    }
    if (stricmp(dot + 1, lbl_8055B738) == 0) {
        obj = fn_801284F8(16, lbl_8055B73C);
        if (obj)
            return fn_802228B0(obj, (s32)path, width, height);
        return obj;
    }
    if (stricmp(dot + 1, lbl_8055B744) == 0) {
        obj = fn_801284F8(8, lbl_8055B748);
        if (obj)
            return ((void *(*)(void *, s32))fn_802226D4)(obj, (s32)path);
        return obj;
    }
    ((s32 (*)(const char *, const char *, ...))Abend_Panic)(lbl_8033CDA4, dot + 1);
    return 0;
}

extern "C" s32 fn_80128668(void);
/* If ptr is set and count is positive, free the object (fn_80128668 receives
 * ptr in r3); always return ptr unchanged. */
extern "C" s32 fn_802121D4(s32 ptr, s32 count) {
    if (ptr != 0 && count > 0) {
        fn_80128668();
    }
    return ptr;
}

extern s32 (*lbl_8055EF0C)(s32 *);
extern "C" s32 fn_80212214(s32 bits) {
    /* Bit-preserving cast: copy the argument's 32 bits into the s32 result via memcpy. */
    s32 value;
    memcpy(&value, &bits, 4);
    return value;
}

#pragma dont_inline fn_80212248
extern "C" float fn_80212248(s32 bits) {
    /* Bit-preserving cast: reinterpret the argument's 32 bits as a float via memcpy. */
    float value;
    memcpy(&value, &bits, 4);
    return value;
}

extern "C" void fn_8022E4BC(s32);
extern "C" void fn_8022E960(s32);
extern "C" s32 fn_80211678(u8 *);
extern "C" char lbl_8055B750[4];
extern "C" int sprintf(char *, const char *, ...);
extern "C" int stricmp(const char *, const char *);
#pragma small_data on
#pragma small_data off
extern "C" void *fn_8021227C(void *arg0, char *arg1, s32 arg2) {
    char buf[0x100];
    char *tmp = arg1;
    if (tmp[0] == '#')
        tmp = tmp + 1;
    sprintf(buf, lbl_8055B750, tmp);
    register void *entry = arg0;
    register char *name = tmp;
    register s32 id = arg2;
    while (*(s32 *)((char *)entry + 4) != 0x7B) {
        if (*(s32 *)((char *)entry + 4) == id &&
            *(char **)entry != 0 &&
            (stricmp(*(char **)entry, name) == 0 ||
             stricmp(*(char **)entry, buf) == 0))
            return entry;
        entry = (char *)entry + 0x14;
    }
    return 0;
}
// Default no-op callback used by the layout builder when a node has no handler: returns 0.
extern "C" s32 fn_80212338(void) { return 0; }

#define releaseHandle  fn_8022E4BC
#define destroyLayout  fn_8022E960
#define isDollarTagged fn_80211678

#pragma dont_inline on
extern "C" void fn_80212340(void *__restrict builder) {
    /* Tear down a layout builder: release its secondary handle (+0x10), then,
     * if it holds source data, either release the node handle (+0x0C) or destroy
     * the loaded layout when that data is '$'-tagged, and clear the field. */
    s32 secondaryHandle = *(s32 *)((char *)builder + 0x10);
    s32 *fields = (s32 *)builder;
    if (secondaryHandle != 0) {
        releaseHandle(secondaryHandle);
        fields[4] = 0;
    }
    if ((u8 *)fields[0] != 0) {
        if (isDollarTagged((u8 *)fields[0]) == 0) {
            releaseHandle(fields[3]);
        } else {
            destroyLayout(fields[3]);
        }
        fields[3] = 0;
    }
}
#pragma dont_inline off
extern "C" s32 fn_8021B2B0(void *, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021D044(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_802168EC(void *, void *, s32);
extern "C" char lbl_8055B758[];
extern "C" s32 fn_8021B9AC(void *, void *, s32, s32);
extern "C" s32 fn_8022435C(void *, s32, void *, s32, s32);
extern "C" s32 fn_8021A5B8(void *, char *, s32, s32, s32, f32);
extern "C" s32 fn_80129BC4(void);
extern "C" char lbl_8055B770[];
extern "C" char lbl_8055B760[];
extern "C" char lbl_8055B780[];
extern "C" char lbl_8033D54C[];
extern "C" s32 fn_8021D6A0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021B460(void *, void *, s32, s32);
extern "C" void fn_802123B8(void *, void *, void *);
extern "C" s32 fn_802224B4(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_80226630(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" char lbl_8055B778[];
extern "C" char *strstr(const char *, const char *);
extern "C" s32 fn_8021995C(void *, s32, s32, s32, s32, s32);
extern "C" s32 fn_80219A28(void *, void *, s32, s32);
extern "C" s32 fn_80219870(void *, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021A77C(void *, s32, s32, s32, s32, s32);
extern "C" char lbl_8055B788[8];
extern "C" char lbl_8055B790[];
extern "C" char lbl_8055B798[];
extern "C" s32 lbl_8055EF48;
extern "C" s32 lbl_8055EF4C;
extern "C" s32 fn_8021B0CC(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_80220778(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8022D1B4(s32);
extern "C" s32 fn_8021F678(void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern "C" s32 fn_8021AF0C(void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern "C" s32 fn_8021BD98(void *, s32, s32, s32, s32, s32, f32, f32);
extern "C" s32 fn_8021CEEC(void *, s32, s32, s32, s32, s32, f32, f32);
extern "C" s32 fn_800241CC(s32);
extern "C" char lbl_8055B7A0[];
extern "C" char lbl_8055B7A8[];
extern "C" s32 lbl_8055EF50;
extern "C" f32 lbl_80558DC4;
extern "C" f32 lbl_80563454;
extern "C" void fn_80215298(s32 *, s32 *, s32 *, s32 *, s32, s32, u32);
extern "C" s32 fn_8021D7C8(void *, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021A808(void *, s32, s32, s32, s32, s32);
extern "C" s32 lbl_8055B754;
extern "C" char lbl_8055B7B8[];
extern "C" s32 lbl_8055EF54;
extern "C" s32 fn_8021BEC0(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021CA0C(void *, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021C97C(void *, s32, s32, s32, s32, s32);
extern "C" char lbl_8055B7B0[];
extern "C" s32 fn_8021EA64(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_80218F34(void *, s32, s32, s32, s32, s32);
extern "C" s32 fn_80222BDC(void *, void *, s32);
extern "C" s32 fn_8021E0C0(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_80220E48(void *, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021B1C4(void *, s32, s32, s32, s32, s32);
extern "C" char lbl_8055B7C0[];
extern "C" char lbl_8055B7C8[8];
extern "C" char lbl_8055B7D0[];
extern "C" s32 lbl_8055EF24;
extern "C" char lbl_8033D480[];
extern void *fn_802241C8(void *, void *);
extern void *fn_80224B54(s32, void *);
extern void *fn_8022553C(s32, void *);
extern void *fn_802269A8(void *, void *);
extern void *fn_80226CBC(void *, void *);
extern void *fn_802270DC(void *, void *);
extern void *fn_80227E84(void *, s32, void *, s32);
extern void *fn_80227D00(void *, void *);
extern void *fn_80228418(void *, void *, s32);
extern void *fn_8022855C(void *, void *, s32, s32);
extern void *fn_8021F394(void *, s32, s32, s32, s32, s32);
extern void *fn_802230A4(void *, s32, s32, s32, s32);
extern void *fn_80223AB4(void *, void *, s32);
extern void *MovieWidget_construct(void *, void *, s32);
extern f32 fn_80212248(s32);
extern void *fn_8021FF34(void *, void *, s32, s32, f32, f32);
extern "C" float fn_80212248(s32);
#pragma dont_inline fn_80212248
extern "C" char lbl_8055B7E0;
extern "C" char lbl_8055B7E8;
extern "C" char lbl_8055B7F0;
extern "C" float __fabsf(float);
#pragma paired_single off
#pragma small_data on
extern "C" s32 fn_80212214(s32);
#pragma dont_inline fn_80212214
extern "C" char lbl_8055B758[8];
extern "C" char lbl_8055B760[8];
extern "C" char lbl_8055B768[8];
extern "C" char lbl_8055B770[8];
extern "C" char lbl_8055B778[8];
extern "C" char lbl_8055B780[8];
extern "C" char lbl_8055B790[8];
extern "C" char lbl_8055B798[8];
extern "C" char lbl_8055B7A0[8];
extern "C" char lbl_8055B7A8[8];
extern "C" char lbl_8055B7B0[8];
extern "C" char lbl_8055B7B8[8];
extern "C" char lbl_8055B7C0[8];
extern "C" char lbl_8055B7D0[8];
extern "C" char lbl_8055B7D8[8];
extern "C" void fn_802123B8(void *arg0, void *arg1, void *arg2) {
    extern void *lbl_8055EF38;
    extern s32 lbl_8055EF2C;
    extern s32 lbl_80490510[];
    extern s32 lbl_8055EF58;
    extern s32 lbl_8055EF24;
    void *results[4] = { 0 };
    s32 count = 0;
    s32 i;
    s32 type;
    s32 a, b, c, d;
    register const char *strings = (const char *)lbl_8033CAE8;
    register const char *data = (const char *)lbl_80490510;
    *(s32 *)&lbl_8055EF38 = *(s32 *)((char *)arg1 + 0x8C);
    type = *(s32 *)((char *)arg1 + 0);
    switch (type) {
    case 5: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        void *node;
        if (child != 0) {
            void *child2 = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
            node = fn_801284F8(0x368, strings + 0x2FC);
            if (node != 0) {
                s32 value = child2 != 0 ? *(s32 *)((char *)child2 + 8) : 0;
                node = (void *)fn_8021B2B0(node, *(s32 *)((char *)arg1 + 8),
                    *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)child + 8),
                    *(s32 *)((char *)arg1 + 4), value, 0);
            }
        } else {
            child = fn_8021227C(arg2, (char *)arg1 + 0x20, 7);
            node = fn_801284F8(0x2C4, lbl_8055B758);
            if (node != 0) node = (void *)fn_8021D044(node,
                *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
                *(s32 *)((char *)child + 8), *(s32 *)((char *)child + 0xC),
                *(s32 *)((char *)arg1 + 4), 0, 0, 0);
        }
        results[0] = node; count = 1; break;
    }
    case 28: {
        void *primary = 0;
        void *child = 0;
        void *node;
        if (*(u8 *)((char *)arg1 + 0x40) == '#') {
            primary = fn_8021227C(arg2, (char *)arg1 + 0x41, 3);
            if (primary == 0) {
                child = fn_8021227C(arg2, (char *)arg1 + 0x41, 7);
                if (child != 0) {
                    s32 v1 = fn_80212214(*(s32 *)((char *)arg1 + 0x9C));
                    s32 v2 = fn_80212214(*(s32 *)((char *)arg1 + 0xA0));
                    node = fn_801284F8(0x2C8, strings + 0x308);
                    if (node != 0) node = (void *)fn_8021D6A0(node,
                        *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
                        *(s32 *)((char *)child + 8), *(s32 *)((char *)child + 0xC),
                        (s32)((char *)arg1 + 0x20), *(s32 *)((char *)arg1 + 4), v1, v2);
                    results[0] = node; count = 1;
                    break;
                }
            }
            child = fn_8021227C(arg2, (char *)arg1 + 0x41, 2);
        }
        node = fn_801284F8(0x374, strings + 0x314);
        if (node != 0) {
            s32 v1 = child != 0 ? *(s32 *)((char *)child + 8) : 0;
            s32 v2 = primary != 0 && *(s32 *)((char *)primary + 8) != 0 ?
                *(s32 *)((char *)primary + 8) : (s32)((char *)arg1 + 0x40);
            node = (void *)fn_8021B460(node, arg1, v2, v1);
        }
        results[0] = node; count = 1;
        break;
    }
    case 31: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x40, 0xD);
        void *node = fn_801284F8(0x264, lbl_8055B770);
        if (node != 0) node = (void *)fn_8021B9AC(node, arg1,
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF2C,
            child != 0 ? *(s32 *)((char *)child + 0xC) : 0);
        results[0] = node; count = 1; break;
    }
    case 2: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 0);
        void *second = 0;
        if (*(u8 *)((char *)arg1 + 0x40) == '#')
            second = fn_8021227C(arg2, (char *)arg1 + 0x41, 3);
        s32 value1 = first != 0 ? *(s32 *)((char *)first + 0xC) : 0;
        s32 value2 = second != 0 ? *(s32 *)((char *)second + 8) : (s32)((char *)arg1 + 0x40);
        s32 value3 = first != 0 ? *(s32 *)((char *)first + 8) : (s32)fn_80212338;
        void *inner = fn_801284F8(0xC, strings + 0x32C);
        if (inner != 0) {
            *(void **)inner = lbl_8033D54C;
            *(s32 *)((char *)inner + 8) = *(s32 *)((char *)arg1 + 4);
            *(s32 *)((char *)inner + 4) = value2;
        }
        if (*(u32 *)((char *)arg1 + 0x9C) == 1 || fn_80129BC4() == 0) {
            void *node = fn_801284F8(0x260, lbl_8055B778);
            if (node != 0) node = (void *)fn_802224B4(node, value1,
                *(s32 *)((char *)arg1 + 0x9C), *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x14),
                *(s32 *)((char *)arg1 + 0x18), (s32)inner, 0,
                (*(s32 *)((char *)arg1 + 0x9C) != 0));
            results[0] = node;
        } else {
            void *node = fn_801284F8(0x268, lbl_8055B780);
            if (node != 0) node = (void *)fn_80226630(node, value1,
                *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
                *(s32 *)((char *)arg1 + 0x14), *(s32 *)((char *)arg1 + 0x18),
                (s32)inner, value3);
            results[0] = node;
        }
        count = 1;
        break;
    }
    case 42: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 0);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        s32 value1 = first != 0 ? *(s32 *)((char *)first + 0xC) : 0;
        s32 value2 = first != 0 ? *(s32 *)((char *)first + 8) : (s32)fn_80212338;
        s32 value3 = second != 0 ? *(s32 *)((char *)second + 8) : 0;
        void *node = fn_801284F8(0x28C, strings + 0x338);
        if (node != 0) node = (void *)fn_8022435C(node, value1, arg1, value2, value3);
        results[0] = node; count = 1; break;
    }
    case 3:
        fn_802E30C8(strings + 0x344);
        break;
    case 34: {
        void *node = fn_801284F8(0x258, strings + 0x388);
        if (node != 0) node = (void *)fn_8021A5B8(node, (char *)arg1 + 0x40,
            1, 1, 1, (f32)*(s32 *)((char *)arg1 + 0x10));
        results[0] = node; count = 1; break;
    }
    case 17:
        fn_802E30C8(strings + 0x394);
        break;
    case 33: {
        u32 index = *(u32 *)((char *)arg1 + 4) - 2;
        s32 enabled = index <= 3 && ((1u << index) & 0xD) != 0;
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        char *text = second != 0 ? *(char **)((char *)second + 8) : (char *)arg1 + 0x40;
        s32 extra = enabled ? (s32)((char *)arg1 + 0x20) :
            (first != 0 ? *(s32 *)((char *)first + 8) : 0);
        void *node;
        if (strstr(text, lbl_8055B788) != 0) {
            node = fn_801284F8(0x258, strings + 0x3E4);
            if (node != 0) {
                void *child = fn_801284F8(0x10, lbl_8055B790);
                if (child != 0) child = fn_802228B0(child, (s32)text,
                    *(s32 *)((char *)arg1 + 0x14), *(s32 *)((char *)arg1 + 0x18));
                node = (void *)fn_8021995C(node, *(s32 *)((char *)arg1 + 8),
                    *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x10),
                    (s32)child, extra);
            }
        } else {
            node = fn_801284F8(0x284, strings + 0x3F4);
            if (node != 0) node = (void *)fn_80219A28(node, arg1, (s32)text, extra);
        }
        results[0] = node; count = 1;
        break;
    }
    case 13: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 1);
        void *node = fn_801284F8(0x358, strings + 0x400);
        if (node != 0) node = (void *)fn_80219870(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            (s32)((char *)arg1 + 0x40),
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF48,
            *(s32 *)((char *)arg1 + 4));
        results[0] = node; count = 1;
        break;
    }
    case 14: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x25C, strings + 0x40C);
        if (node != 0) {
            void *inner = fn_801284F8(0xC, lbl_8055B798);
            s32 value = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF4C;
            if (inner != 0) {
                *(void **)inner = lbl_8033D54C;
                *(s32 *)((char *)inner + 8) = *(s32 *)((char *)arg1 + 4);
                *(s32 *)((char *)inner + 4) = (s32)((char *)arg1 + 0x40);
            }
            node = (void *)fn_8021A77C(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x9C), value,
                (s32)inner);
        }
        results[0] = node; count = 1;
        break;
    }
    case 15: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x25C, strings + 0x418);
        if (node != 0) {
            s32 value = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF4C;
            void *extra = makeImageFromPath((char *)arg1 + 0x40, 2, -1, -1, 0);
            node = (void *)fn_8021A77C(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x9C),
                value, (s32)extra);
        }
        results[0] = node; count = 1;
        break;
    }
    case 8: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        s32 text;
        s32 value;
        s32 flags;
        if (child != 0) {
            text = *(s32 *)((char *)child + 8);
            value = *(s32 *)((char *)child + 0xC);
            flags = *(s32 *)((char *)child + 0x10);
        } else {
            child = fn_8021227C(arg2, (char *)arg1 + 0x20, 7);
            if (child != 0) {
                text = *(s32 *)((char *)child + 8);
                value = 0;
                flags = fn_8022D1B4(*(s32 *)((char *)child + 0xC));
            } else {
                text = lbl_8055EF4C; value = 0; flags = 5;
            }
        }
        void *node = fn_801284F8(0x264, strings + 0x428);
        if (node != 0) {
            s32 control = ((s32 (*)(s32, s32))fn_80215270)(0, 1);
            node = (void *)fn_8021B0CC(node,
                *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC) + 1,
                text, value, flags, -1, control);
        }
        results[0] = node; count = 1;
        s32 delta = *(s32 *)((char *)arg1 + 0x14) - 0x25;
        if (delta > 10) {
            void *node2 = fn_801284F8(0x264, strings + 0x434);
            if (node2 != 0) node2 = (void *)fn_80220778(node2,
                *(s32 *)((char *)arg1 + 8) + 0x15,
                *(s32 *)((char *)arg1 + 0xC), delta,
                *(s32 *)((char *)arg1 + 0x18), text, value, flags);
            results[1] = node2; count = 2;
        }
        node = fn_801284F8(0x264, strings + 0x428);
        if (node != 0) {
            s32 control = ((s32 (*)(s32, s32))fn_80215270)(1, 1);
            node = (void *)fn_8021B0CC(node,
                *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14) - 0xE,
                *(s32 *)((char *)arg1 + 0xC) + 1,
                text, value, flags, 1, control);
        }
        results[count] = node;
        count++;
        break;
    }
    case 18: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 9);
        f32 value1 = lbl_80563434;
        f32 value2 = lbl_80563450;
        if (child != 0) {
            value1 = *(f32 *)((char *)child + 0xC);
            value2 = *(f32 *)((char *)child + 0x10);
        }
        f32 diff = __fabsf(value1 - value2);
        if (diff > lbl_80558DC4 && *(s32 *)((char *)arg1 + 0x9C) != 0) {
            s32 delta = *(s32 *)((char *)arg1 + 0x14) - 0x25;
            if (delta > 10) {
                void *node = fn_801284F8(0x27C, lbl_8055B7A0);
                if (node != 0) node = (void *)fn_8021F678(node,
                    *(s32 *)((char *)arg1 + 8) + 0x15, *(s32 *)((char *)arg1 + 0xC),
                    delta, *(s32 *)((char *)arg1 + 0x18),
                    child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF50,
                    *(s32 *)((char *)arg1 + 0x9C), value1, value2);
                results[0] = node; count = 1;
            }
            void *node0 = fn_801284F8(0x268, strings + 0x440);
            if (node0 != 0) {
                s32 text = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF50;
                s32 control = ((s32 (*)(s32, s32))fn_80215270)(0, 1);
                s32 state = fn_800241CC(*(s32 *)((char *)arg1 + 0x9C));
                node0 = (void *)fn_8021AF0C(node0,
                    *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC) + 1,
                    text, -1, control, state, value1, value2);
            }
            results[count++] = node0;
            void *node1 = fn_801284F8(0x268, strings + 0x440);
            if (node1 != 0) {
                s32 text = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF50;
                s32 control = ((s32 (*)(s32, s32))fn_80215270)(1, 1);
                s32 state = fn_800241CC(*(s32 *)((char *)arg1 + 0x9C));
                node1 = (void *)fn_8021AF0C(node1,
                    *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14) - 0xE,
                    *(s32 *)((char *)arg1 + 0xC) + 1, text, 1, control, state,
                    value1, value2);
            }
            results[count++] = node1;
        }
        break;
    }
    case 6: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 9);
        void *node = fn_801284F8(0x2B4, lbl_8055B7A8);
        if (node != 0) node = (void *)fn_8021BD98(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF50,
            (s32)((char *)arg1 + 0x40), *(s32 *)((char *)arg1 + 4),
            lbl_80563454, lbl_80563434);
        results[0] = node; count = 1;
        break;
    }
    case 7: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x2B4, strings + 0x44C);
        if (node != 0) node = (void *)fn_8021CEEC(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF4C,
            (s32)((char *)arg1 + 0x40), *(s32 *)((char *)arg1 + 4),
            lbl_80563450, lbl_80563434);
        results[0] = node; count = 1;
        break;
    }
    case 9: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xC);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) :
            *(s32 *)((char *)data + 0x160);
        s32 mode = *(s32 *)((char *)arg1 + 4);
        if (mode == 4) {
            void *node = fn_801284F8(0x25C, strings + 0x458);
            if (node != 0) node = (void *)fn_8021CA0C(node,
                *(s32 *)((char *)arg1 + 8) + 0xF,
                *(s32 *)((char *)arg1 + 0xC),
                *(s32 *)((char *)arg1 + 0x14) - 0x1E,
                *(s32 *)((char *)arg1 + 0x18), text);
            results[0] = node;
            node = fn_801284F8(0x25C, strings + 0x464);
            if (node != 0) node = (void *)fn_8021C97C(node,
                *(s32 *)((char *)arg1 + 8) + 1,
                *(s32 *)((char *)arg1 + 0xC) + 2,
                ((s32 (*)(s32, s32))fn_80215270)(0, 2), -1, text);
            results[1] = node;
            node = fn_801284F8(0x25C, strings + 0x464);
            if (node != 0) node = (void *)fn_8021C97C(node,
                *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14) - 0xF,
                *(s32 *)((char *)arg1 + 0xC) + 2,
                ((s32 (*)(s32, s32))fn_80215270)(1, 2), 1, text);
            results[2] = node; count = 3;
        } else {
            fn_80215298(&a, &b, &c, &d, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(u32 *)((char *)arg1 + 0x14));
            void *node = fn_801284F8(0x2BC, lbl_8055B7B0);
            if (node != 0) node = (void *)fn_8021BEC0(node, b,
                *(s32 *)((char *)arg1 + 0xC), text,
                mode == 1 ? 0x14 : 0xF, a, c, d);
            results[0] = node; count = 1;
        }
        break;
    }
    case 49: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0x10);
        fn_80215298(&a, &b, &c, &d, *(s32 *)((char *)arg1 + 8),
            *(s32 *)((char *)arg1 + 0xC), *(u32 *)((char *)arg1 + 0x14));
        void *node = fn_801284F8(0x26C, strings + 0x47C);
        if (node != 0) node = (void *)fn_8021D7C8(node, a, b, c, d,
            *(s32 *)((char *)arg1 + 4),
            child != 0 ? *(s32 *)((char *)child + 0xC) : *(s32 *)((char *)data + 0x18C));
        results[0] = node; count = 1;
        break;
    }
    case 10: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 7);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF4C;
        void *node;
        s32 size = *(s32 *)((char *)arg1 + 0x14);
        if (size > 0 && size - 0x25 > 10) {
            fn_80215298(&a, &b, &c, &d, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(u32 *)((char *)arg1 + 0x14));
            node = fn_801284F8(0x2C4, lbl_8055B758);
            if (node != 0) node = (void *)fn_8021D044(node, b,
                *(s32 *)((char *)arg1 + 0xC), text, 0xF, a, c, d,
                (s32)((char *)arg1 + 0x40));
        } else {
            node = fn_801284F8(0x2C4, lbl_8055B758);
            if (node != 0) node = (void *)fn_8021D044(node,
                *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
                text, 0, 0, 0, 0, 0);
        }
        results[0] = node; count = 1;
        break;
    }
    case 16: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x25C, strings + 0x48C);
        if (node != 0) {
            s32 value = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF54;
            void *inner = fn_801284F8(0xC, lbl_8055B7B8);
            if (inner != 0) {
                *(void **)inner = lbl_8033D54C;
                *(s32 *)((char *)inner + 8) = *(s32 *)((char *)arg1 + 4);
                *(void **)((char *)inner + 4) = (char *)arg1 + 0x40;
            }
            node = (void *)fn_8021A808(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x9C),
                value, (s32)inner);
        }
        results[0] = node; count = 1;
        break;
    }
    case 27: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x25C, strings + 0x498);
        if (node != 0) {
            s32 value = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF54;
            void *extra = makeImageFromPath((char *)arg1 + 0x40, 1, -1, -1, 0);
            node = (void *)fn_8021A808(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x9C),
                value, (s32)extra);
        }
        results[0] = node; count = 1;
        break;
    }
    case 11: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) :
            (s32)((char *)data + 0x1A0);
        s32 color = child != 0 ? *(s32 *)((char *)child + 0xC) : 0x40;
        void *node = fn_801284F8(0xA64, lbl_8055B7C0);
        if (node != 0) node = (void *)fn_8021EA64(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            *(s32 *)((char *)arg1 + 0x14), 0xA, text, color, 1,
            *(s32 *)((char *)arg1 + 4), 0);
        results[0] = node; count = 1;
        break;
    }
    case 26: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 5);
        s32 index = 0;
        void *node;
        s32 *ref;
        if (child != 0) {
            ref = (s32 *)*(s32 *)((char *)child + 8);
        } else {
            extern s32 lbl_8055EF58;
            index = (lbl_8055EF58 + 1) & 0xF;
            lbl_8055EF58 = index;
            ref = (s32 *)((char *)data + 0x200 + index * 0x18);
        }
        node = fn_801284F8(0x248, lbl_8055B7C8);
        if (node != 0) {
            fn_80218F34(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC),
                *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14),
                *(s32 *)((char *)arg1 + 0xC) + *(s32 *)((char *)arg1 + 0x18),
                *(s32 *)((char *)arg1 + 0x10));
            *(void **)node = lbl_8033D480;
            *(s32 *)((char *)node + 0x244) = (s32)ref;
            ref[5] = (s32)node;
            ref[1] = *(s32 *)((char *)arg1 + 8);
            ref[2] = *(s32 *)((char *)arg1 + 0xC);
            ref[3] = *(s32 *)((char *)arg1 + 0x14);
            ref[4] = *(s32 *)((char *)arg1 + 0x18);
        }
        results[0] = node; count = 1;
        break;
    }
    case 35: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xA);
        void *node = fn_801284F8(0x258, strings + 0x4A4);
        if (node != 0) node = (void *)fn_80222BDC(node, arg1,
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF24);
        results[0] = node; count = 1;
        break;
    }
    case 23: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xA);
        void *third = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xB);
        void *node = fn_801284F8(0x26C, lbl_8055B7D0);
        if (node != 0) node = (void *)fn_8021E0C0(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            *(s32 *)((char *)arg1 + 0x14), *(s32 *)((char *)arg1 + 0x18),
            third != 0 ? *(s32 *)((char *)third + 8) : (s32)((char *)lbl_8033CAE8 + 0x380),
            first != 0 ? *(s32 *)((char *)first + 8) : lbl_8055EF4C,
            second != 0 ? *(s32 *)((char *)second + 8) : lbl_8055EF24);
        results[0] = node; count = 1;
        break;
    }
    case 20: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xB);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) :
            (s32)((char *)lbl_8033CAE8 + 0x380);
        void *node = fn_801284F8(0x260, strings + 0x4B0);
        if (node != 0) node = (void *)fn_80220E48(node,
            *(s32 *)((char *)arg1 + 8) - 3,
            *(s32 *)((char *)arg1 + 0xC) + 0x15,
            *(s32 *)((char *)arg1 + 0x14),
            *(s32 *)((char *)arg1 + 0x18) - 0x28, text, 0);
        results[0] = node;
        void *second = fn_801284F8(0x25C, strings + 0x4BC);
        if (second != 0) second = (void *)fn_8021B1C4(second,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            text, -1, ((s32 (*)(s32, s32))fn_80215270)(2, 0));
        results[1] = second;
        void *third = fn_801284F8(0x25C, strings + 0x4BC);
        if (third != 0) third = (void *)fn_8021B1C4(third,
            *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x18) - 0x12,
            *(s32 *)((char *)arg1 + 0xC) + 3, text, 1,
            ((s32 (*)(s32, s32))fn_80215270)(3, 0));
        results[2] = third; count = 3;
        break;
    }
    case 21: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xB);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) :
            (s32)((char *)lbl_8033CAE8 + 0x380);
        void *node = fn_801284F8(0x260, strings + 0x4C8);
        if (node != 0) node = (void *)fn_80220E48(node,
            *(s32 *)((char *)arg1 + 8) + 0x15,
            *(s32 *)((char *)arg1 + 0xC),
            *(s32 *)((char *)arg1 + 0x14) - 0x28,
            *(s32 *)((char *)arg1 + 0x18), text, 1);
        results[0] = node;
        void *second = fn_801284F8(0x25C, strings + 0x4BC);
        if (second != 0) second = (void *)fn_8021B1C4(second,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            text, -1, ((s32 (*)(s32, s32))fn_80215270)(0, 0));
        results[1] = second;
        void *third = fn_801284F8(0x25C, strings + 0x4BC);
        if (third != 0) third = (void *)fn_8021B1C4(third,
            *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14) - 0x12,
            *(s32 *)((char *)arg1 + 0xC) + 3, text, 1,
            ((s32 (*)(s32, s32))fn_80215270)(1, 0));
        results[2] = third; count = 3;
        break;
    }
    case 12: {
        extern char lbl_8055B7D8[];
            void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 4);
        void *node = fn_801284F8(0x274, lbl_8055B7D8);
        if (node != 0) node = (void *)fn_8021F394(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            child != 0 ? *(s32 *)((char *)child + 0xC) : (s32)((char *)lbl_8033CAE8 + 0x4D4),
            child != 0 ? *(s32 *)((char *)child + 8) : (s32)((char *)data + 0x1E0), 6);
        results[0] = node; count = 1; break;
    }
    case 36: {
        extern s32 lbl_8055EF28;
        extern s32 lbl_8055EF4C;
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xA);
        void *node = fn_801284F8(0x420, strings + 0x4E8);
        if (node != 0) node = (void *)fn_8021F394(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            second != 0 ? *(s32 *)((char *)second + 0xC) : lbl_8055EF28,
            first != 0 ? *(s32 *)((char *)first + 8) : lbl_8055EF4C, 6);
        results[0] = node; count = 1; break;
    }
    case 37: {
        extern s32 lbl_8055EF28;
        extern s32 lbl_8055EF4C;
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xA);
        void *node = fn_801284F8(0x424, &lbl_8055B7E0);
        if (node != 0) node = (void *)fn_802230A4(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            second != 0 ? *(s32 *)((char *)second + 8) : lbl_8055EF28,
            first != 0 ? *(s32 *)((char *)first + 8) : lbl_8055EF4C);
        results[0] = node; count = 1; break;
    }
    case 38: {
        extern s32 lbl_8055EF30;
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xE);
        void *node = fn_801284F8(0x268, strings + 0x4F4);
        if (node != 0) node = (void *)fn_80223AB4(node, arg1,
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF30);
        results[0] = node; count = 1; break;
    }
    case 39: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        void *node;
        if (child != 0) {
            node = fn_801284F8(0x268, strings + 0x500);
            if (node != 0) node = (void *)MovieWidget_construct(node, arg1, *(s32 *)((char *)child + 8));
        } else {
            node = fn_801284F8(0x268, strings + 0x500);
            if (node != 0) node = (void *)MovieWidget_construct(node, arg1, 0);
        }
        results[0] = node; count = 1; break;
    }
    case 41: {
        void *node = fn_801284F8(0x258, strings + 0x518);
        if (node != 0) node = (void *)fn_802241C8(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 43: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        void *node = fn_801284F8(0x2A0, &lbl_8055B7E8);
        if (node != 0) node = (void *)fn_80224B54(child != 0 ? *(s32 *)((char *)child + 8) : 0, arg1);
        results[0] = node; count = 1; break;
    }
    case 44: {
        extern s32 lbl_8055EF30;
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xE);
        void *node = fn_801284F8(0x284, strings + 0x530);
        if (node != 0) node = (void *)fn_8022553C(child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF30, arg1);
        results[0] = node; count = 1; break;
    }
    case 45: {
        void *node = fn_801284F8(0x260, strings + 0x53C);
        if (node != 0) node = (void *)fn_802269A8(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 46: {
        void *node = fn_801284F8(0x264, strings + 0x548);
        if (node != 0) node = (void *)fn_80226CBC(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 47: {
        void *node = fn_801284F8(0x274, strings + 0x558);
        if (node != 0) node = (void *)fn_802270DC(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 48: {
        extern s32 lbl_8055EF34;
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xF);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        s32 value = first != 0 ? *(s32 *)((char *)first + 8) : lbl_8055EF34;
        void *node = fn_801284F8(0x25C, strings + 0x568);
        if (node != 0) node = (void *)fn_80227E84(node, value, arg1,
            second != 0 ? *(s32 *)((char *)second + 8) : 0);
        results[0] = node; count = 1; break;
    }
    case 51: {
        void *node = fn_801284F8(0x248, &lbl_8055B7F0);
        if (node != 0) node = (void *)fn_80227D00(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 50: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 9);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x268, strings + 0x578);
        if (node != 0) {
            f32 height;
            f32 width;
            if (first != 0) height = *(f32 *)((char *)first + 0x10);
            else height = lbl_80563450;
            if (first != 0) width = *(f32 *)((char *)first + 0xC);
            else width = lbl_80563434;
            s32 value = second != 0 ? **(s32 **)((char *)second + 8) : 10;
            node = (void *)fn_8021FF34(node, arg1,
                first != 0 ? *(s32 *)((char *)first + 8) : 0,
                value, width, height);
        }
        results[0] = node; count = 1; break;
    }
    case 52: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0x11);
        void *node = fn_801284F8(0x24C, strings + 0x588);
        if (node != 0) node = (void *)fn_80228418(node, arg1,
            child != 0 ? *(s32 *)((char *)child + 8) : 0);
        results[0] = node; count = 1; break;
    }
    case 53: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 0x12);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x24C, strings + 0x594);
        if (node != 0) node = (void *)fn_8022855C(node, arg1,
            first != 0 ? *(s32 *)((char *)first + 8) : 0,
            second != 0 ? *(s32 *)((char *)second + 8) : 0);
        results[0] = node; count = 1; break;
    }
    case 54:
        break;
    default:
        ((s32 (*)(const char *, ...))Abend_Panic)(strings + 0x5A4, type);
        break;
    }
    {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0x14);
        if (child == 0) child = fn_8021227C(arg2, (char *)arg1 + 0x40, 0x14);
        for (i = 0; i < count; ++i) {
            if (child != 0) *(s32 *)((char *)results[i] + 0x240) = *(s32 *)((char *)child + 8);
            fn_802168EC(arg0, results[i], *(s32 *)((char *)arg1 + 0x88));
        }
    }
    *(s32 *)&lbl_8055EF38 = -1;
}
#pragma paired_single reset
void fn_802141A0(void **arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    register void *head = *(void **)((u8 *)arg1 + 4);
    register u8 *base = lbl_8033CAE8;
    register void *node;
    register s32 v28;
    register s32 v27;
    void *top;
    u8 *it;
    s32 flag28;
    void *out;
    if (*(void **)arg1 != NULL) {
        if (fn_80211678((u8 *)*(void **)arg1) != 0) {
            fn_8022E4C0(arg1);
        }
        node = loadLayout(*(void **)arg1);
        *(void **)((u8 *)arg1 + 0xC) = node;
        lbl_8055EF44 = *(void **)arg1;
    }
    node = *(void **)((u8 *)arg1 + 0xC);
    *(void **)((u8 *)arg1 + 0x10) = NULL;
    if ((s8)((u8 *)node)[0x25] != 0) {
        if (lbl_8055EF40 == 0) {
            fn_80276D3C((u8 *)node + 0x28, 1);
        } else {
            fn_802E30C8((const char *)(base + 0x694), (const char *)((u8 *)node + 0x28));
        }
    }
    v28 = lbl_8055CFF0;
    v27 = lbl_8055CFF4;
    {
        char *msg = (char *)((u8 *)(*(void **)((u8 *)arg1 + 0xC)) + 4);
        if (msg != NULL && strstr(msg, lbl_8055B788) != NULL && fn_8012C33C((s32)msg) != 0) {
            s32 res = gxGetImageArt((char *)msg);
            if (gxGetImageWidth((void *)res) > 0) {
                if (gxGetImageHeight((void *)res) > 0) {
                    v28 = gxGetImageWidth((void *)res);
                    v27 = gxGetImageHeight((void *)res);
                }
                fn_802C519C(res);
            }
        }
    }
    if (arg2 == -999) {
        s32 diff = lbl_8055CFF0 - v28;
        arg2 = diff / 2;
    }
    if (arg3 == -999) {
        s32 diff2 = lbl_8055CFF4 - v27;
        arg3 = diff2 / 2;
    }
    if (arg5 != 0) {
        void *rec = fn_801284F8(0xDE8, (const char *)(base + 0x6c0));
        if (rec != NULL) {
            out = fn_80216D40(rec, lbl_8055B7F8, arg2, arg3, v28, v27, arg4);
        } else {
            out = fn_80216770((const char *)((u8 *)(*(void **)((u8 *)arg1 + 0xC)) + 4), arg2, arg3, v28, v27, arg4);
        }
    } else {
        out = fn_80216770((const char *)((u8 *)(*(void **)((u8 *)arg1 + 0xC)) + 4), arg2, arg3, v28, v27, arg4);
    }
    *arg0 = out;
    {
        union PU { u32 i; u8 *p; } pu;
        pu.i = (u32)*(u8 **)((u8 *)node + 0x64);
        while (*(s32 *)pu.p != 0)
            pu.i += 0x134;
    }
    if ((s8)((u8 *)node)[0x24] != 0) {
        top = loadLayout((const void *)(base + 0x6d0));
        *(void **)((u8 *)arg1 + 0x10) = top;
        {
            union PU { u32 i; u8 *p; } pu;
            pu.i = (u32)*(u8 **)((u8 *)top + 0x64);
            while (*(s32 *)pu.p != 0)
                pu.i += 0x134;
        }
    }
    {
        u8 *q = (u8 *)head;
        s32 z = 0;
        s32 ng = -1;
        register void *lbl480 = (void *)&lbl_8033D480;
        do {
            if (*(s32 *)(q + 4) == 5) {
                char *sp = *(char **)q;
                if (sp != NULL && strcmp(sp, &lbl_8055B6A8) == 0) {
                    *(s32 *)&lbl_8055EF38 = z;
                    void *rec = fn_801284F8(0x248, lbl_8055B7C8);
                    if (rec != NULL) {
                        void *in8 = *(void **)(q + 8);
                        fn_80218F34(rec, 0, 0, 0, 0, 0);
                        *(void **)rec = lbl480;
                        *(void **)((u8 *)rec + 0x244) = in8;
                        *(void **)((u8 *)in8 + 0x14) = rec;
                        *(s32 *)((u8 *)in8 + 4) = z;
                        *(s32 *)((u8 *)in8 + 8) = z;
                        *(s32 *)((u8 *)in8 + 0xC) = z;
                        *(s32 *)((u8 *)in8 + 0x10) = z;
                        fn_802168EC(out, rec, -1);
                    }
                    *(s32 *)&lbl_8055EF38 = ng;
                }
            }
            q = q + 0x14;
        } while (*(s32 *)(q + 4) != 0x7b);
    }
    if ((s8)((u8 *)node)[0x24] != 0) {
        void *top2 = *(void **)((u8 *)arg1 + 0x10);
        union PU { u32 i; u8 *p; } pu;
        pu.i = (u32)*(u8 **)((u8 *)top2 + 0x64);
        do {
            fn_802123B8(out, pu.p, head);
            pu.i += 0x134;
        } while (*(s32 *)pu.p != 0);
    }
    {
        union PU { u32 i; u8 *p; } pu;
        pu.i = (u32)*(u8 **)((u8 *)node + 0x64);
        do {
            fn_802123B8(out, pu.p, head);
            pu.i += 0x134;
        } while (*(s32 *)pu.p != 0);
    }
    {
        u8 *q = (u8 *)head;
        s32 z = 0;
        s32 ng = -1;
        register void *lbl480b = (void *)&lbl_8033D480;
        register void *lbl590 = (void *)&lbl_8033D590;
        flag28 = 0;
        do {
            s32 type = *(s32 *)(q + 4);
            switch (type) {
            case 6: {
                *(s32 *)&lbl_8055EF38 = z;
                void *rec = fn_801284F8(0x250, lbl_8055B7FC);
                if (rec != NULL) {
                    void *a8 = *(void **)(q + 8);
                    s32 aC = *(s32 *)(q + 0xC);
                    u16 a10 = (u16)*(s32 *)(q + 0x10);
                    fn_80218F34(rec, 0, 0, 0, 0, 0);
                    *(void **)rec = lbl590;
                    *(s32 *)((u8 *)rec + 0x24C) = aC;
                    *(void **)((u8 *)rec + 0x248) = a8;
                    *(u16 *)((u8 *)rec + 0x244) = a10;
                    fn_802168EC(out, rec, -1);
                }
                *(s32 *)&lbl_8055EF38 = ng;
                break;
            }
            case 8: {
                s32 v = *(s32 *)(q + 0xC);
                switch (v) {
                case 0:
                    *(void **)((u8 *)out + 0x438) = *(void **)(q + 8);
                    break;
                case 1:
                    *(void **)((u8 *)out + 0x43C) = *(void **)(q + 8);
                    break;
                case 2:
                    flag28 = 1;
                    *(void **)((u8 *)out + 0x440) = *(void **)(q + 8);
                    break;
                case 3:
                    *(void **)((u8 *)out + 0x444) = *(void **)(q + 8);
                    break;
                default:
                    Abend_Panic((const char *)(base + 0x6e0));
                    break;
                }
                break;
            }
            case 5: {
                if (*(void **)q == NULL) {
                    *(s32 *)&lbl_8055EF38 = z;
                    void *rec = fn_801284F8(0x248, lbl_8055B7C8);
                    if (rec != NULL) {
                        void *in8 = *(void **)(q + 8);
                        fn_80218F34(rec, 0, 0, 0, 0, 0);
                        *(void **)rec = lbl480b;
                        *(void **)((u8 *)rec + 0x244) = in8;
                        *(void **)((u8 *)in8 + 0x14) = rec;
                        *(s32 *)((u8 *)in8 + 4) = z;
                        *(s32 *)((u8 *)in8 + 8) = z;
                        *(s32 *)((u8 *)in8 + 0xC) = z;
                        *(s32 *)((u8 *)in8 + 0x10) = z;
                        fn_802168EC(out, rec, -1);
                    }
                    *(s32 *)&lbl_8055EF38 = ng;
                }
                break;
            }
            default:
                break;
            }
            q = q + 0x14;
        } while (*(s32 *)(q + 4) != 0x7b);
    }
    if (flag28 == 0) {
        *(void **)((u8 *)out + 0x440) = (void *)&fn_80236914;
    }
}
#pragma small_data off
#pragma dont_inline off

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
// Runs a mapped UI/dialog flow for the given descriptor: sets up runtime/context, swaps in
// the descriptor callback, executes/tears down the flow, reports overlap mismatch, then copies
// the descriptor name (or fallback) into a bounded global buffer before returning the result.
extern "C" s32 fn_802146BC(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                            s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    void *sp8;
    s32 temp_r31;
    s32 temp_r30;
    s32 temp_r3;
    u8 temp_r3_2;
    s32 var_r4;
    u8 *var_r5;
    u8 *var_r6;
    void *data;
    s32 (*savedCallback)(s32 *);

    fn_802D08C4(1);
    temp_r30 = fn_80128314(0);
    fn_802141A0(&sp8, arg0, arg1, arg2, arg3, 0);
    fn_80127A24();
    fn_802E47E8();
    savedCallback = lbl_8055EF0C;
    fn_80218D54(sp8, 0);
    lbl_8055EF0C = *(s32 (**)(s32 *))((char *)arg0 + 8);
    data = *(void **)arg0;
    {
        register void *obj = sp8;
        *(void **)((char *)obj + 0x434) = (void *)fn_80211FF0;
        fn_80236918(data, obj, fn_80211FF0);
    }
    temp_r31 = fn_802168F0(sp8);
    if (lbl_8055EF40 != 0) fn_802E3D00();
    fn_80236950();
    fn_8021683C(sp8);
    lbl_8055EF0C = savedCallback;
    fn_80212340(arg0);
    temp_r3 = fn_80128314(0);
    if (temp_r3 != temp_r30) {
        fn_802E30C8(lbl_8033D1E0, *(void **)arg0, temp_r3, temp_r30);
    }
    fn_802D08C4(0);

    var_r6 = *(u8 **)arg0;
    switch ((s32)var_r6) {
    case 0:
        var_r6 = lbl_8055B6BC;
        break;
    default:
        break;
    }
    var_r5 = lbl_8033CAE8;
    var_r4 = 0x64;
    goto copy_char;
count_check:
    var_r4--;
    if (var_r4 > 0) goto copy_char;
    var_r5[-1] = 0;
    goto copy_done;
copy_char:
    temp_r3_2 = *var_r6;
    var_r6++;
    *var_r5 = temp_r3_2;
    var_r5++;
    if ((s8)temp_r3_2 != 0) goto count_check;
copy_done:
    return temp_r31;
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma dont_inline reset
#pragma pop

#pragma scheduling on
extern "C" s32 fn_802ECEEC(void);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" s32 fn_802146BC(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" u8 lbl_8033CAE8[];
extern "C" s32 lbl_80490510[];
extern "C" s32 lbl_802F9EA4[];
extern "C" u8 lbl_8055B860;
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" s32 fn_8021481C(void *arg0) {
    struct MapS { s32 a; s32 pad; s32 b; s32 c; s32 d; };
    s32 *values;
    struct MapS *map;
    s32 args[20];
    u8 *base = lbl_8033CAE8;
    if (fn_802ECEEC() == 0) {
        s32 m0, m2, m3, m4;
        fn_802E30C8((const char *)(base + 0x72C), arg0);
        args[6] = 3;
        args[5] = (s32)(base + 0x750);
        map = (struct MapS *)lbl_802F9EA4;
        values = lbl_80490510;
        m0 = map->a;
        m2 = map->b;
        m3 = map->c;
        m4 = map->d;
        args[1] = 0;
        args[7] = (s32)arg0;
        args[8] = 0;
        args[9] = 0;
        args[11] = 6;
        args[10] = (s32)&lbl_8055B860;
        args[12] = 0;
        args[13] = -2;
        args[14] = 0xD;
        args[15] = values[0];
        args[16] = values[1];
        args[17] = values[2];
        args[18] = values[3];
        args[19] = values[4];
        args[0] = m0;
        args[2] = m2;
        args[3] = m3;
        args[4] = m4;
        args[1] = (s32)&args[5];
        fn_802146BC(args, -0x3E7, -0x3E7, 1, m4, m3, m2, m0);
        fn_802E30C8((const char *)(base + 0x760), arg0);
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset

#pragma push
#pragma small_data on
extern "C" s32 fn_80214934(const void* dir, s32 path, void* out, s32 outSize) {
    /* Write "<dir>\<name>" into out, where <name> is `path` cut at its first '.'
       (the extension is dropped); returns the number of characters written. */
    s32 nameEnd = fn_80029004((const char*)path, '.');
    if (nameEnd == 0) {
        nameEnd = (s32)((const char*)path + strlen((const char*)path));
    }
    return ((s32 (*)(void*, s32, const char*, ...))fn_801345D8)(out, outSize, PATH_FORMAT_DIR_NAME, (s32)dir, nameEnd - path, (const char*)path);
}
#pragma small_data off
#pragma pop

#pragma push
#pragma dont_inline on
extern "C" void fn_802149C4(s32 name) {
    char pathBuf[0x64];
    /* Build "transin\\<name>" (extension stripped) and hand it to the transition handler. */
    fn_80214934(&TRANSITION_DIR_IN, name, pathBuf, 0x64);
    fn_8021481C(pathBuf);
}
#pragma dont_inline reset
#pragma pop
extern "C" s32 fn_80218C14(s32, s32);
extern "C" s32 fn_80214934(const void*, s32, void*, s32);
extern "C" s32 fn_8021481C(void*);
extern "C" char lbl_8033D388[];
extern "C" char lbl_8033D268[];
#pragma push
#pragma dont_inline on
extern "C" void fn_802149FC(s32 fileName) {
#define TRANSIT_DIR_OUT lbl_8033D268
    char path[0x64];
    /* RealName: LoadTransitionOut - build "transout\<name>" from fileName
     * (dropping its extension) into path and hand it to the transition loader. */
    fn_80214934(TRANSIT_DIR_OUT, fileName, path, 0x64);
    fn_8021481C(path);
#undef TRANSIT_DIR_OUT
}
#pragma dont_inline reset
#pragma pop

#pragma scheduling invalid_target
extern "C" s32 fn_80214A38(s32 groupId) {
    /* Return whether the given UI group is visible in the active window, or 0 if there is none. */
    s32 isVisible = 0;
    s32 window = fn_802168E4();
    if (window != 0)
        isVisible = ((s32 (*)(s32, s32))fn_802168D4)(window, groupId);
    else
        ((void (*)(const char *, ...))Abend_Panic)(lbl_8033D274);
    return isVisible;
}
#pragma scheduling on
extern "C" void fn_802192AC(void);
extern "C" void fn_80219354(void);
#pragma scheduling invalid_target
/* UIHideGroup(groupId): hides one widget group of the currently active UI
 * window.  fn_802168E4 is the active-window getter and fn_802168CC the
 * window's hide-group method (it sets the group's bit in the window's
 * hidden-group mask at +0x464 and starts a fade-out on every slot the group
 * is set in, fn_802193C8).  The fade time is 0.0f, so the group vanishes at
 * once; with no active window the game prints the message below instead.
 * UIShowGroup (fn_80214AF0) is the way back. */
extern "C" void fn_80214A9C(s32 groupId) {
#define UIGetActiveWindow fn_802168E4
#define UIWindow_HideGroup fn_802168CC
#define UIPanic Abend_Panic
#define UIHideGroup_noWindowMsg lbl_8033D2A0
#define groupFadeTime lbl_80563434
    s32 window = UIGetActiveWindow();
    if (window != 0) {
        ((s32 (*)(s32, s32, float))UIWindow_HideGroup)(window, groupId, groupFadeTime);
    } else {
        ((s32 (*)(const char *, ...))UIPanic)(UIHideGroup_noWindowMsg);
    }
#undef groupFadeTime
#undef UIHideGroup_noWindowMsg
#undef UIPanic
#undef UIWindow_HideGroup
#undef UIGetActiveWindow
}
#pragma scheduling on
extern "C" s32 fn_802168D0(s32, s32, float);
extern "C" char lbl_8033D2C0[];
/* UIShowGroup(groupId): shows one widget group of the currently active UI
 * window.  fn_802168E4 is the active-window getter and fn_802168D0 the
 * window's show-group method (it clears the group's bit in the window's
 * hidden-group mask at +0x464 and starts a fade-in on every slot the group
 * is set in, fn_80219358).  The fade time is 0.0f, so the group appears at
 * once; with no active window the game panics with the message below.
 * UIHideGroup (fn_80214A9C) is the way back. */
extern "C" void fn_80214AF0(s32 groupId) {
#define UIGetActiveWindow fn_802168E4
#define UIWindow_ShowGroup fn_802168D0
#define UIPanic Abend_Panic
#define UIShowGroup_noWindowMsg lbl_8033D2C0
#define groupFadeTime lbl_80563434
    s32 window = UIGetActiveWindow();
    if (window != 0) {
        ((s32 (*)(s32, s32, float))UIWindow_ShowGroup)(window, groupId, groupFadeTime);
    } else {
        ((s32 (*)(const char *, ...))UIPanic)(UIShowGroup_noWindowMsg);
    }
#undef groupFadeTime
#undef UIShowGroup_noWindowMsg
#undef UIPanic
#undef UIWindow_ShowGroup
#undef UIGetActiveWindow
}

#pragma scheduling invalid_target
/* RealName: UIDisableGroup — disable a UI group on the active window, or warn if none is active. */
extern "C" void fn_80214B44(s32 groupId) {
#define UIGetActiveWindow       fn_802168E4
#define UIWindow_DisableGroup   fn_802168DC
#define UIPanic                 Abend_Panic
#define kNoActiveWindowMsg      lbl_8033D2E0
    s32 window = UIGetActiveWindow();
    if (window != 0) {
        ((s32 (*)(s32, s32))UIWindow_DisableGroup)(window, groupId);
    } else {
        ((s32 (*)(const char *, ...))UIPanic)(kNoActiveWindowMsg);
    }
#undef kNoActiveWindowMsg
#undef UIPanic
#undef UIWindow_DisableGroup
#undef UIGetActiveWindow
}
#pragma scheduling on
extern "C" s32 fn_802168D8(s32);
extern "C" char lbl_8033D304[];
/* Enables a UI group on the active window, or logs an error if there is none. */
extern "C" void fn_80214B94(s32 group) {
#define sNoActiveWindowMsg lbl_8033D304
    s32 window = fn_802168E4();
    if (window != 0) {
        ((s32 (*)(s32, s32))fn_802168D8)(window, group);
    } else {
        ((s32 (*)(const char *, ...))Abend_Panic)(sNoActiveWindowMsg);
    }
#undef sNoActiveWindowMsg
}

extern "C" void fn_80214BE4(s32 arg0, s32 arg1, s32 arg2) {
    /* Forwards (arg0,arg1,arg2) to the active UI window object via
     * fn_802168E0, or reports "no active window" if none is set. */
    s32 obj = fn_802168E4();
    if (obj != 0) {
        ((void (*)(s32, s32, s32, s32))fn_802168E0)(obj, arg0, arg1, arg2);
    } else {
        ((s32 (*)(const char *, ...))Abend_Panic)(lbl_8033D328);
    }
}

/* Forward update-anime-context data to the active UI window, or report if none is active. */
extern "C" void fn_80214C54(s32 updateId, s32 context) {
    s32 window = fn_802168E4();
    if (window != 0) {
        ((void (*)(s32, s32, s32))fn_80218C14)(window, updateId, context);
    } else {
        ((s32 (*)(const char *, ...))Abend_Panic)(lbl_8033D388);
    }
}

#pragma dont_inline on
extern "C" void fn_80214CB4(s32 arg0) {
    /* Set the active UI window's menu index, or report if no window is active. */
    s32 window = fn_802168E4();
    if (window != 0) {
        ((s32 (*)(s32, s32))fn_802180E0)(window, arg0);
    } else {
        ((s32 (*)(const char *, ...))Abend_Panic)(lbl_8033D3B0);
    }
}
#pragma dont_inline reset

extern "C" s32 lbl_80490528[];
extern "C" s32 fn_802168E4(void);
extern "C" s32 fn_80218120(void);
extern "C" s32 Abend_Panic(const char *);
extern "C" char lbl_8033D3D4[];
#pragma dont_inline on
extern "C" s32 fn_80214D04(void) {
    /* Return the active UI window's menu index, or 0 and log if no window is active. */
    if (fn_802168E4() != 0) {
        return fn_80218120();
    } else {
        ((s32 (*)(const char *, ...))Abend_Panic)(lbl_8033D3D4);
    }
    return 0;
}
#pragma dont_inline reset
#define DELTA_TIME lbl_8055EF10  /* .sbss: clamped per-frame delta time, updated by fn_80211F64 */
extern "C" f32 fn_80214D48(void) {
    /* Return the current frame's clamped delta time in seconds. */
    return DELTA_TIME;
}

#pragma use_lmw_stmw off
extern "C" void fn_80214D50(s32 groupIndex) {
    #pragma opt_common_subs off
    struct Entry {
        s32 unk0;
        f32 baseScale;
        void *objects[4];
    };
    s32 slotIndex;
    struct Entry *table;
    s32 entryOffset;
    void *object;
    f32 targetScale;
    /* Advance the rotating slot for the given group and apply the current
     * scaled value to that slot's object, if present. */
    if (fn_80206430() == 0)
        return;
    slotIndex = lbl_8055EF5C + 1;
    lbl_8055EF5C = slotIndex;
    if (slotIndex >= 4) {
        slotIndex = 0;
        lbl_8055EF5C = 0;
    }
    entryOffset = groupIndex * 0x18;
    table = (struct Entry *)lbl_80490558;
    object = table[groupIndex].objects[slotIndex];
    if (object == 0)
        return;
    targetScale = *(f32 *)((u8 *)table + entryOffset + 4) * fn_80209028();
    if (targetScale != *(f32 *)((char *)object + 8)) {
        *((u8 *)object + 0x4D) = 1;
        *(f32 *)((char *)object + 8) = targetScale;
    }
    *((u8 *)object + 0x49) = 1;
    *((u8 *)object + 0x4B) = 0;
    *((u8 *)object + 0x4A) = 0;
}

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma small_data on
extern "C" s32 fn_80214E10(s32 arg0, s32 arg1, s32 arg2) {
    s32 stack[47];
    s32 *ctx, *values;
    s32 state, zero;
    s32 context0, context2, context3, context4;
    s32 value0, value1, value2, value3, value4;
    s32 labelB860, labelB820, labelD404, labelB824, labelB830, labelD3F8;

    stack[0] = 2;
    labelD3F8 = (s32)lbl_8033D3F8;
    state = fn_802168E4();
    if (state != 0) {
        fn_80214A9C(0x1F);
    }

    values = lbl_80490510;
    value0 = values[0];
    value1 = values[1];
    value2 = values[2];
    value3 = values[3];
    value4 = values[4];
    ctx = lbl_802F9EB8;
    context0 = *ctx++;
    context2 = ctx[1];
    context3 = ctx[2];
    context4 = ctx[3];
    zero = 0;
    labelD404 = (s32)lbl_8033D404;
    labelB820 = (s32)&lbl_8055B820;
    labelB824 = (s32)&lbl_8055B824;
    labelB830 = (s32)&lbl_8055B830;
    labelB860 = (s32)&lbl_8055B860;

    stack[28] = labelD3F8;
    stack[6] = labelB820;
    stack[7] = 2;
    stack[8] = (s32)&stack[0];
    stack[9] = zero;
    stack[10] = zero;
    stack[11] = labelB820;
    stack[12] = zero;
    stack[13] = zero;
    stack[14] = -2;
    stack[15] = zero;
    stack[16] = labelB860;
    stack[17] = 6;
    stack[18] = zero;
    stack[19] = -1;
    stack[20] = 0x1B;
    stack[21] = labelB860;
    stack[22] = 6;
    stack[23] = zero;
    stack[24] = -2;
    stack[25] = 0xD;
    stack[26] = labelD404;
    stack[27] = 3;
    stack[29] = 4;
    stack[30] = zero;
    stack[31] = labelB824;
    stack[32] = 3;
    stack[33] = arg0;
    stack[34] = 0x20;
    stack[35] = zero;
    stack[36] = labelB830;
    stack[37] = 3;
    stack[38] = arg1;
    stack[39] = 4;
    stack[40] = zero;
    stack[41] = value0;
    stack[42] = value1;
    stack[43] = value2;
    stack[44] = value3;
    stack[45] = value4;
    stack[1] = context0;
    stack[2] = (s32)&stack[6];
    stack[3] = context2;
    stack[4] = context3;
    stack[5] = context4;
    if (arg2 == 0) {
        stack[3] = (s32)fn_802152CC;
    }

    fn_802146BC(&stack[1], -0x3E7, -0x3E7, 1,
                context2, context0, value4, value3);
    if (state != 0) {
        fn_80214AF0(0x1F);
    }
}
#pragma small_data off
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma dont_inline reset
#pragma pop

#pragma use_lmw_stmw reset
extern "C" void fn_80214FD8(s32 title, s32 message) {
    /* Open a message dialog with the given title and body text, using the default options. */
    ((s32 (*)(s32, s32, s32))fn_80214E10)(title, message, 0);
}

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma small_data on
extern "C" s32 lbl_802F9ECC[];
extern "C" char lbl_8033D420[];
extern "C" char lbl_8055B6A8;
extern "C" char lbl_8055B824;
extern "C" char lbl_8055B830;
extern "C" char lbl_8055B838;
extern "C" char lbl_8055B83C;
#pragma optimization off
extern "C" s32 fn_80214FE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct { s32 f0, f1, f2, f3, f4; } Ctx802;
    s32 stack[47];
    s32 *values;
    Ctx802 *ctx;
    s32 state, result, zero;
    s32 ctx0, ctx2, ctx3, ctx4;
    s32 value0, value1, value2, value3, value4;
    s32 label0, labelA, labelB, labelC, labelD, labelE;
    register s32 savedByte = arg3;

    state = fn_802168E4();
    if (state != 0) {
        fn_80214A9C(0x1F);
    }
    *(u8 *)((u8 *)stack + 0x2C) = (u8)savedByte;
    ctx = (Ctx802 *)lbl_802F9ECC;
    ctx2 = ctx->f2;
    stack[2] = ctx2;
    values = lbl_80490510;
    value0 = values[0];
    value1 = values[1];
    value2 = values[2];
    value3 = values[3];
    value4 = values[4];
    label0 = (s32)lbl_8033D420;
    labelA = (s32)&lbl_8055B6A8;
    labelB = (s32)&lbl_8055B824;
    labelC = (s32)&lbl_8055B830;
    labelD = (s32)&lbl_8055B838;
    labelE = (s32)&lbl_8055B83C;
    zero = 0;

    stack[5] = label0;
    stack[13] = 5;
    stack[12] = labelA;
    stack[14] = (s32)&stack[5];
    stack[10] = zero;
    stack[15] = zero;
    stack[16] = zero;
    stack[18] = 3;
    stack[17] = labelB;
    stack[19] = arg0;
    stack[20] = 4;
    stack[21] = zero;
    stack[23] = 3;
    stack[22] = labelC;
    stack[24] = arg1;
    stack[25] = 4;
    stack[26] = zero;
    stack[28] = zero;
    stack[27] = labelD;
    stack[29] = zero;
    stack[30] = -2;
    stack[31] = zero;
    stack[33] = zero;
    stack[32] = labelE;
    stack[34] = zero;
    stack[35] = -3;
    stack[36] = zero;
    stack[38] = 6;
    stack[37] = (s32)&lbl_8055B860;
    stack[39] = zero;
    stack[40] = -3;
    stack[41] = 0x1B;
    stack[42] = value0;
    stack[43] = value1;
    stack[44] = value2;
    stack[45] = value3;
    stack[46] = value4;
    ctx0 = ctx->f0;
    ctx3 = ctx->f3;
    ctx4 = ctx->f4;
    stack[0] = ctx0;
    stack[3] = ctx3;
    stack[4] = ctx4;
    stack[1] = (s32)&stack[12];
    stack[2] = arg2;

    result = (fn_802146BC((void *)stack, -0x3E7, -0x3E7, 1,
                          ctx3, ctx0, value4, value3) + 2) == 0;
    if (state != 0) {
        fn_80214AF0(0x1F);
    }
    return result;
}
#pragma optimization on

/* CodeWarrior deleting-destructor helper: free the object with MemFree when
 * deleting (flag > 0), then return the object pointer. */
extern "C" s32 fn_80215194(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_802151D4(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_80214FE0(s32, s32, s32, s32);
extern "C" void fn_80215214(s32 headingMsg, s32 bodyMsg, s32 param, s32 unused) {
    /* Tail-call the message-box display helper with its mode flag fixed to 1 (ignores the 4th argument). */
    fn_80214FE0(headingMsg, bodyMsg, param, 1);
}

extern "C" void fn_8021521C(s32 headingMsg, s32 bodyMsg, s32 flag) {
    /* Show a confirmation message box with the given heading/body message ids. */
    fn_80214FE0(headingMsg, bodyMsg, 0, flag);
}

extern "C" s32 fn_80215228(void) {
    /* Return TRUE when the stored last-layout name matches the current layout name (case-insensitive). */
    return stricmp((const char *)lbl_8033CAE8, lbl_8055B6B0) == 0;
}

extern void *lbl_8055EF38;
#define gCurrentItemIndex lbl_8055EF38 // scratch item index handed to widget constructors
extern "C" void* fn_8021525C(void) {
    /* Return the current item index that widget constructors copy into field +0x23C. */
    return gCurrentItemIndex;
}

extern u8 lbl_8033CAE8[];
// Return the base of the layout string table, whose first entry is the "__OOPS_NO_LAST_LAYOUT__" sentinel.
extern "C" void *fn_80215264(void) {
    return lbl_8033CAE8;
}

/* gWidgetControlTable: 3 rows by 4 columns of widget control values in .bss,
 * indexed [row][column]; rows >= 3 fall back to row 1. */
#define gWidgetControlTable lbl_80490528

/* Look up a widget control value by column and row in the row-major table;
 * rows 3 and above fall back to row 1. */
extern "C" s32 fn_80215270(s32 column, s32 row) {
    s32 *rowPtr;
    if (row >= 3) {
        row = 1;
    }
    rowPtr = gWidgetControlTable + (row * 4);
    return rowPtr[column];
}

/* Derive four layout coordinates from a node's x, y and unsigned width: the base x,
 * x plus half the width (rounded toward zero), x plus the width minus 0x1A, and y plus 4. */
extern "C" void fn_80215298(s32 *outX, s32 *outHalfX, s32 *outEndX, s32 *outY, s32 x, s32 y, u32 width) {
    *outX = x;
    *outEndX = x + width - 0x1A;
    *outHalfX = x + ((((s32)((u32)width >> 31)) + (s32)width) >> 1);
    *outY = y + 4;
}

#pragma dont_inline on
/* No-op hook in the sound result-callback path; kept out of line for callers such as fn_802152CC. */
extern "C" void fn_802152C8(void) {
}
#pragma dont_inline reset

extern "C" s32 baseWidgetOnMessage(void *, s32);
#pragma dont_inline on
extern "C" void fn_802152C8(void);
#pragma dont_inline reset
extern "C" s32 fn_802152CC(void) {
#define NoopHook fn_802152C8
    /* Default result callback: invoke the no-op hook, then report that no result is available (0). */
    NoopHook();
    return 0;
#undef NoopHook
}
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802152F0(void *self, int shouldDelete) {
    /* Deleting destructor for nw4hbm::snd::MemorySoundArchive: run base destructor, optionally free storage. */
    if (self != 0) {
        fn_8021915C(self, 0);
        if (shouldDelete > 0) ((s32 (*)(void *))fn_80128668)(self);
    }
    return self;
}

extern "C" s32 __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80215348(void *self, s32 shouldDelete) {
    /* nw4hbm::snd::MemorySoundArchive destructor variant: run base teardown, then
     * free the object when requested (shouldDelete > 0). */
    if (self != 0) {
        fn_8021915C(self, 0);
        if (shouldDelete > 0) {
            ((s32 (*)(void *))fn_80128668)(self);
        }
    }
    return (s32)self;
}

/* No-op hook in the nw4hbm::snd sound-archive group: an empty function used as
 * a default callback slot that does nothing when invoked. */
extern "C" void fn_802153A0(void) {
}

extern "C" s32 fn_802168BC(s32);
extern "C" void fn_8021915C(void *, unsigned int);
extern "C" s32 fn_802153A4(void) {
    /* Stub predicate in the nw4hbm::snd sound-archive group: always reports failure/zero. */
    return 0;
}

extern "C" s32 fn_802153AC(void *obj, u32 expectedId) {
    /* If the object's pending id matches expectedId, optionally invoke its callback on the stored value; on success/free path notify fn_802168BC(value) and return 1. */
    s32 (*callback)(s32);
    if (expectedId == *(u16 *)((char *)obj + 0x244)) {
        callback = *(s32 (**)(s32))((char *)obj + 0x248);
        if (callback == 0 || callback(*(s32 *)((char *)obj + 0x24C)) != 0) {
            fn_802168BC(*(s32 *)((char *)obj + 0x24C));
        }
        return 1;
    }
    return 0;
}

/* Default (empty) virtual hook in the VfWidget method group: does nothing, so a
 * subclass that doesn't override it simply gets no behaviour. */
extern "C" void fn_80215414(void) {

}

/* Default (empty) virtual hook in the VfWidget method group: does nothing, so a
 * subclass that doesn't override it simply gets no behaviour. */
extern "C" void fn_80215418(void) {

}

/* Base widget class (vtable lbl_8033FB38) default for vtable slot 0x14, the
 * third virtual (VfObj::vf3) after the destructor and the empty slots at
 * 0x0C/0x10; the layout wrapper forwards its own slot 0x14 to the object held
 * at +0x244 (fn_802158F0).  A widget that reads a live value overrides it to
 * subscribe to that value -- fn_8021D154, fn_802208EC, fn_8022071C and
 * fn_8021F7EC all register (group +0x2C, id) with fn_80217BD8, cache the entry
 * and watch it through fn_80219440.  The base widget watches nothing, so the
 * default does nothing. */
extern "C" void fn_8021541C(void *widget) {

}

/* Base widget class (vtable lbl_8033FB38) default for vtable slot 0x28, the
 * widget's draw method (VfObj::vf8; the layout wrapper forwards its own slot
 * 0x28 to the widget held at +0x244 -- fn_80215B30).  Derived widgets override
 * it to draw their content: fn_80219660 draws a text line through drawTextIntArgs,
 * fn_802299FC hands the box to a callback, and the option widget's drawOptionBlinkerArrows
 * chains to fn_80219660 before drawing its blinker arrows.  The base widget has
 * nothing of its own to draw, so the default does nothing. */
extern "C" void fn_80215420(void *widget) {

}

/* Empty default of the base widget class (vtable lbl_8033FB38) at vtable slot
 * 0x30, between the draw slot 0x28 and the pair at 0x34/0x38 that set and clear
 * the widget's flag byte at +0x19.  The layout wrapper forwards its own slot
 * 0x30 to the object at +0x244 (fn_80215B44), but no widget class gives this
 * hook a body: lbl_8033FA28, lbl_8033F4B8, lbl_8033F768, lbl_8033F880,
 * lbl_8033EBA0, lbl_8033ED44 and lbl_8033EF68 all still point here, so the
 * default is to do nothing. */
extern "C" void fn_80215424(void *widget) {

}

extern "C" void fn_80215428(void *widget) {
    /* Set this VfWidget's flag byte at +0x19 and, when its layout option
     * (+0x1A) is set, mark it dirty (+0x234) so it gets redrawn. */
    *(u8 *)((char *)widget + 0x19) = 1;
    if (*(u8 *)((char *)widget + 0x1A) != 0) {
        *(u8 *)((char *)widget + 0x234) = 1;
    }
}

extern "C" void fn_80215444(void *widget) {
    /* Clear this VfWidget's flag byte at +0x19 and, when its layout option
     * (+0x1A) is set, mark it dirty (+0x234) so it gets redrawn. */
    *(u8 *)((char *)widget + 0x19) = 0;
    if (*(u8 *)((char *)widget + 0x1A) != 0) {
        *(u8 *)((char *)widget + 0x234) = 1;
    }
}

/* Base widget class (vtable lbl_8033FB38) default for vtable slot 0x3C: the
 * "the pointer was pressed on me at (x, y)" hook, just after the pair that set
 * and clear the flag byte at +0x19.  The base widget ignores the press.
 * Widgets that react to it override it: the slider's fn_8021CD04 drags the
 * value driven through +0x248 to wherever x falls along the track (restoring
 * the saved value when the point is outside the box grown by 32 pixels), and
 * fn_80229628 raises its busy flag at +0x254 before running the widget's
 * update virtual at slot 0x84. */
extern "C" void fn_80215464(void *widget, s32 x, s32 y) {

}

/* Base widget class (vtable lbl_8033FB38) default for vtable slot 0x40 (vf14):
 * the "the pointer was released on me" hook, right after the press hook at
 * slot 0x3C.  The base widget ignores the release.  Widgets that track a press
 * override it to finish theirs, each clearing the flag its slot-0x3C press
 * handler raised: the slider's fn_8021CEAC runs its update virtual (slot 0x4C)
 * and clears its pending flag at +0x244, and fn_80229640 runs its update
 * (slot 0x84), clears its busy flag at +0x254 and notifies the value through
 * its callback at +0x258.  The layout wrapper forwards its own slot 0x48 to
 * the widget held at +0x244 (fn_802159C0). */
extern "C" void fn_80215468(void *widget) {

}

/* Empty default of the base widget class (vtable lbl_8033FB38) at vtable slot
 * 0x44 (VfObj::vf15): the base widget's no-op enable hook, dispatched by the
 * layout wrapper's enable forwarder (fn_80215A10, which sets the +0x18 flag) on
 * the wrapped widget.  A subclass that wants behaviour on enable overrides it;
 * the base widget has nothing to do, so the default does nothing. */
extern "C" void fn_8021546C(void) {

}

/* Base widget class (vtable lbl_8033FB38) default for vtable slot 0x48 (vf16):
 * the "you have just been turned off" notice, paired with slot 0x44 (vf15) on
 * the way in.  The layout wrapper dispatches it when disabling the widget held
 * at +0x244: its slot 0x5C handler fn_80215A2C clears that widget's enable
 * flag at +0x18 and then calls its slot 0x48.  No widget class gives this hook
 * a body -- lbl_8033FA28, lbl_8033F4B8, lbl_8033F768, lbl_8033F880,
 * lbl_8033EBA0, lbl_8033ED44, lbl_8033EF68 and lbl_8033ECB8 all still point
 * here -- so the default is to do nothing. */
extern "C" void fn_80215470(void *widget) {

}

/* Base widget class (vtable lbl_8033FB38) default for vtable slot 0x4C (vf17):
 * the widget's update handler, run right after its switch-on flag at +0x244 is
 * set (fn_80229FF0 raises the flag and dispatches it; the layout wrapper's
 * slot 0x34 handler fn_80215A48 sets its own flags and forwards the call to
 * the widget at +0x244).  The slider overrides it as fn_8021CE8C, which re-runs
 * its press handler vf13 while that flag is set, and its release handler
 * fn_8021CEAC runs this update before clearing the flag.  The base widget has
 * nothing to refresh, so the default does nothing. */
extern "C" void fn_80215474(void *widget) {

}

extern "C" void fn_80215478(void* widget) {
    /* Enable this VfWidget by setting its flag byte at +0x18 (paired with
     * fn_80215484, which clears the same flag to disable it). */
    *(u8*)((char*)widget + 0x18) = 1;
}

/* Disable the widget: clear its enable flag at +0x18 (the clear twin of fn_80215478). */
extern "C" void fn_80215484(void* widget) {
    *(u8*)((char*)widget + 0x18) = 0;
}

/* Default widget hook: reports a zero result (subclasses may override it). */
extern "C" s32 fn_80215490(void) {
    return 0;
}

extern "C" s32 fn_80215498(void) {
    // Default VfWidget hook reporting a zero result (subclasses may override it).
    return 0;
}

extern "C" void fn_802154A0(void *widget) {
    /* Mark this VfWidget dirty (+0x234) when its layout option (+0x1A) is set. */
    if (*(u8 *)((char *)widget + 0x1A) != 0) {
        *(u8 *)((char *)widget + 0x234) = 1;
    }
}

// Default VfWidget hook: reports 1 (true); subclasses may override it.
extern "C" u32 fn_802154B8(void) { return 1; }

extern "C" s32 fn_802154C0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Empty no-op: a default callback/virtual slot with no behaviour. */
extern "C" void fn_80215500(void) {

}

#pragma scheduling off
extern "C" void fn_80215504(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    f32 rate = lbl_80563450;
    ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, s32, f32))drawTextIntArgs)(
        *(s32 *)((u8 *)arg0 + 8), arg1, arg2, 0, arg4, arg5,
        *(s32 *)((u8 *)arg0 + 4), arg6, 0, rate);
}
#pragma scheduling on
extern "C" void fn_80215544(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    /* Forward screen-space query args using the two context handles stored at +4 and +8. */
    fn_8022AC1C(*(s32 *)((char *)arg0 + 8), *(s32 *)((char *)arg0 + 4), arg1, arg2, arg3, arg4, arg5, arg6);
}

/* Fixed value 4 returned by this class's no-argument virtual getter. */
extern "C" s32 fn_802155AC(void) {
    return 4;
}

extern "C" void fn_802C4C80(void*);
extern "C" int lbl_8033D528[];
/* Destroys a CollisionSpace instance: installs this class's vtable, releases the
 * owned subobject at offset 4, and conditionally frees the storage. */
extern "C" void* __dt__14CollisionSpaceFv_802155B4(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_8033D528;
        fn_802C4C80(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_80029004(const char *, s32);
extern "C" s32 fn_801345D8(void *, s32, const char *, s32, s32, const char *);
extern "C" unsigned long strlen(const char *);
extern "C" s32 stampGetFrameCount(s32);
extern "C" s32 gxCanvasDrawStamp(s32, s32, s32, s32, s32);
/* Wraps a modulo by the count from stampGetFrameCount(self+4) and forwards (arg1,arg2,rem,0) to gxCanvasDrawStamp. */
extern "C" void fn_80215618(void *self, s32 arg1, s32 arg2, s32 value) {
    s32 rem = value % stampGetFrameCount(*(s32 *)((char *)self + 4));
    gxCanvasDrawStamp(*(s32 *)((char *)self + 4), arg1, arg2, rem, 0);
}

extern "C" void stampGetOffsets(s32, s32 *, s32 *);
extern "C" s32 stampGetWidth(s32);
extern "C" s32 stampGetHeight(s32);
#pragma use_lmw_stmw off
extern "C" void fn_8021568C(void *arg0, s32 x, s32 y,
                            s32 *outLeft, s32 *outTop, s32 *outRight, s32 *outBottom,
                            s32 unused) {
    /* Compute a local-space rect for the canvas/object at arg0+4 from point
     * (x,y): get its origin, output left/top relative to it in outLeft/outTop,
     * and right/bottom in outRight/outBottom by adding its width/height. */
    s32 originX = 0;
    s32 originY = 0;

    stampGetOffsets(*(s32 *)((u8 *)arg0 + 4), &originX, &originY);
    *outLeft = x - originX;
    *outTop = y - originY;
    *outRight = *outLeft + stampGetWidth(*(s32 *)((u8 *)arg0 + 4));
    *outBottom = *outTop + stampGetHeight(*(s32 *)((u8 *)arg0 + 4));
}
#pragma use_lmw_stmw reset
typedef struct CanvasHandleObj {
    void *vtable;
    s32 canvas;
} CanvasHandleObj;
extern "C" s32 fn_80215730(void *arg0) {
    /* Return the tile/cell count of the canvas handle held in this object's owned handle (+4). */
    return stampGetFrameCount(((CanvasHandleObj *)arg0)->canvas);
}

  void fn_802C2FC4(int);
  s32 fn_80128668(void *);
extern "C" void gxCanvasAlphaBlitWhole(void *, s32, s32);
void stampGetOffsets(int, int *, int *);
int stampGetWidth(int);
int stampGetHeight(int);
extern "C" char lbl_8033D504[];
extern "C" s32 fn_802C2FC4(s32);
extern "C" /* Deleting destructor: installs lbl_8033D504 vtable, releases the owned handle at +4 via fn_802C2FC4, and optionally frees the object. */
void *fn_80215738(void *object, s32 deleteFlag) {
    s32 ownedHandle;
    if (object != 0) {
        ownedHandle = *(s32 *)((char *)object + 4);
        *(char **)object = lbl_8033D504;
        if (ownedHandle != 0) fn_802C2FC4(ownedHandle);
        if (deleteFlag > 0) ((s32 (*)(void *))fn_80128668)(object);
    }
    return object;
}

extern "C" void fn_802157A8(void *layout, s32 x, s32 y, u32 index) {
    /* Grid layout: if a draw callback is set, draw item `index` at (x, y - rowStep * (index % columns)). */
    u32 columns = *(u32 *)((u8 *)layout + 0xC);
    s32 drawCallback = *(s32 *)((u8 *)layout + 4);
    u32 column = index % columns;
    if (drawCallback != 0) {
        gxCanvasAlphaBlitWhole((void *)drawCallback, x, y - *(s32 *)((u8 *)layout + 8) * column);
    }
}

extern "C" void fn_802157DC(void *pane, s32 x, s32 y, s32 *outX, s32 *outY, s32 *outXPlusParent, s32 *outYPlusOffset) {
    /* Copy (x,y) to the first two outputs; add the parent's +8 field to x and this object's +8 field to y for the last two. */
    s32 parentOffset;
    void *parent;

    *outX = x;
    *outY = y;
    parent = *(void **)((u8 *)pane + 4);
    if (parent != 0) {
        parentOffset = *(s32 *)((u8 *)parent + 8);
    } else {
        parentOffset = 0;
    }
    *outXPlusParent = *outX + parentOffset;
    *outYPlusOffset = *outY + *(s32 *)((u8 *)pane + 8);
}

extern "C" s32 fn_8021581C(void *obj) {
    // Returns the 32-bit field at offset 0xC of obj (e.g. a layout pane's parent pointer).
    return ((s32 *)obj)[0xC / 4];
}

extern "C" void fn_80215824(void) {
    /* Empty no-op: a default callback/virtual slot with no behaviour. */
}

extern "C" void fn_80215828(void *self, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5, void *arg6) {
    /* Forward to virtual slot 2 of self, passing args 1-3 and 6 (args 4 and 5 are ignored). */
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2(void *, void *, void *, void *);
    };
    ((Obj *)self)->v2(arg1, arg2, arg3, arg6);
}

extern "C" s32 fn_8021583C(void *self, s32 unused1, s32 unused2, s32 x, s32 y) {
    /* Query bounds via virtual call and return 1 if (x,y) is inside [left,right) x [top,bottom). */
    struct Local {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void call(s32, s32, s32*, s32*, s32*, s32*);
    };
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 result;
    ((Local*)self)->call(unused1, unused2, &left, &top, &right, &bottom);
    result = 0;
    if (x >= left && x < right && y >= top && y < bottom)
        result = 1;
    return result;
}

extern "C" void fn_802158C8(void *wrapper) {
    /* Forward vf1() (vtable slot 0x0C) to the widget held at +0x244 of the wrapper. */
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf1();
}

class Vf4Obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_802158DC(void *wrapper) {
    /* Forward vf2() (vtable slot 0x10) to the widget held at +0x244 of the wrapper. */
    Vf4Obj *widget = *(Vf4Obj **)((char *)wrapper + 0x244);
    widget->vf2();
}

extern "C" void fn_802158F0(void *wrapper) {
    /* Forward vf3() to the widget (VfObj) held at +0x244 of the wrapper. */
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf3();
}

extern "C" void fn_80215904(void *wrapper) {
    /* Refresh the wrapper's tracked widget slots, then call vf5 on its widget at +0x244. */
    fn_802192AC();
    ((VfObj *)*(void **)((char *)wrapper + 0x244))->vf5();
}

extern "C" void fn_80215944(void *wrapper) {
    /* Tick the shared widget state, then forward vf6 to the widget held at +0x244 of the wrapper. */
    fn_80219354();
    ((VfObj *)*(void **)((char *)wrapper + 0x244))->vf6();
}

/* Forward vf10 (vtable slot 0x28) to the widget held at +0x244 of the wrapper. */
extern "C" void fn_80215984(void *wrapper) {
    ((VfObj *)*(void **)((char *)wrapper + 0x244))->vf10();
}

/* Forwards vf11 to the widget (VfObj) stored at +0x244 of the wrapper. */
extern "C" void fn_80215998(void *wrapper) {
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf11();
}

/* Forward vf13 (vtable slot 0x3C) to the widget held at +0x244 of the wrapper. */
extern "C" void fn_802159AC(void *wrapper) {
    ((VfObj *)*(void **)((char *)wrapper + 0x244))->vf13();
}

// Forward vf14() to the VfObj subobject stored at offset 0x244 of the given container.
extern "C" void fn_802159C0(void *widget) {
    ((VfObj *)*(void **)((char *)widget + 0x244))->vf14();
}

extern "C" void fn_802159D4(void *wrapper) {
    /* Forward vf19 (vtable slot 0x54) to the widget held at +0x244 of the wrapper. */
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf19();
}

extern "C" void fn_802159E8(void *wrapper) {
    /* Forward vf4 (vtable slot 0x18) to the widget held at +0x244 of the wrapper. */
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf4();
}

extern "C" void fn_802159FC(void *wrapper) {
    /* Forward vf12 (vtable slot 0x38) to the widget held at +0x244 of the wrapper. */
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf12();
}

extern "C" void fn_80215A10(void *wrapper) {
    /* Widget wrapper: set the +0x18 flag (enable the widget) and dispatch
     * vf15 (vtable slot 0x44) on the widget held at +0x244. */
    *(u8 *)((u8 *)wrapper + 0x18) = 1;
    ((VfObj *)*(void **)((u8 *)wrapper + 0x244))->vf15();
}

extern "C" void fn_80215A2C(void *wrapper) {
    /* Widget wrapper: clear the +0x18 flag (disable the widget) and dispatch
     * vf16 (vtable slot 0x48) on the widget held at +0x244. */
    *(u8 *)((u8 *)wrapper + 0x18) = 0;
    ((VfObj *)*(void **)((u8 *)wrapper + 0x244))->vf16();
}

extern "C" void fn_80215A48(void *wrapper) {
    /* Widget wrapper: set the +0x19 flag and, when the +0x1A option is set,
     * flag +0x234, then dispatch vf17 (vtable slot 0x4C) on the widget at +0x244. */
    register u32 one = 1;
    *(u8 *)((u8 *)wrapper + 0x19) = one;
    if (*(u8 *)((u8 *)wrapper + 0x1A)) {
        *(u8 *)((u8 *)wrapper + 0x234) = one;
    }
    ((VfObj *)*(void **)((u8 *)wrapper + 0x244))->vf17();
}

#pragma dont_inline on
#pragma dont_inline reset
extern "C" s32 fn_80215AA4(void *, s32);
#pragma scheduling invalid_target
extern "C" s32 fn_80215A74(void *arg0, s32 arg1) {
    /* Widget wrapper: clear the +0x19 flag, propagate +0x1A into +0x234, then
     * tailcall vf18 (vtable slot 0x50) on the widget at +0x244 and return its status. */
    u8 *wrapper = (u8 *)arg0;
    wrapper[0x19] = 0;
    if (wrapper[0x1A] != 0) {
        wrapper[0x234] = 1;
    }
    return ((VfObj *)*(void **)(wrapper + 0x244))->vf18();
}
#pragma scheduling on
/* Vtable slot 0x64 of the widget wrapper (vtable lbl_8033D480): forward the
 * call to the wrapped widget at +0x244 through its vtable slot 0x58, and report
 * 1 when that answers nonzero; otherwise fall back on the base handler
 * baseWidgetOnMessage, which answers 0. */
extern "C" s32 fn_80215AA4(void *wrapper, s32 arg1) {
    VfObj *widget = *(VfObj **)((u8 *)wrapper + 0x244);
    if (widget->vf20() != 0) return 1;
    return baseWidgetOnMessage(wrapper, arg1);
}

/* Forward to the wrapped widget at +0x244 and invoke its vtable slot 0x5C (vf21). */
extern "C" void fn_80215B08(void *wrapper) {
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf21();
}

extern "C" void fn_80215B1C(void *wrapper) {
    /* Forward vf7() to the widget (VfObj) held at +0x244 of the wrapper. */
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf7();
}

extern "C" void fn_80215B30(void *wrapper) {
    /* Forward the vf8() virtual call to the widget wrapped at +0x244. */
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf8();
}

extern "C" void fn_80215B44(void *wrapper) {
    /* Forward the vf9() virtual call to the widget wrapped at +0x244. */
    VfObj *widget = *(VfObj **)((char *)wrapper + 0x244);
    widget->vf9();
}

extern "C" void fn_802191F0(void);
/* Vtable slot 0x1C of the widget wrapper (vtable lbl_8033D480): move to
 * (left, top).  The call below is the widget code's own move; the wrapper's
 * arguments are already in r3-r5, so it moves the wrapper and recomputes its
 * right and bottom edges.  The wrapper then hands the new position to the
 * widget it wraps at +0x244, which keeps its own left and top. */
extern "C" void fn_80215B58(void *wrapper, s32 left, s32 top) {
#define Widget_move fn_802191F0 /* move(widget, left, top) in text_80218E98.cpp */
    Widget_move();
    ((WidgetRect *)*(void **)((char *)wrapper + 0x244))->left = left;
    ((WidgetRect *)*(void **)((char *)wrapper + 0x244))->top = top;
#undef Widget_move
}

/* Widget-wrapper vtable method at slot 0x18: default implementation returns -1 as an invalid/empty sentinel. */
extern "C" s32 fn_80215BAC(void) {
    return -1;
}

/* Vtable slot 0x2C of the widget wrapper (vtable lbl_8033D480): empty default
 * handler.  Unlike the neighbouring slots 0x24/0x28/0x30 it forwards nothing to
 * the widget wrapped at +0x244. */
extern "C" void fn_80215BB4(void) {

}

extern "C" void fn_80215BB8(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

/* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
extern "C" void fn_80215BBC(void) {

}

/* Default widget-wrapper vtable method: returns 0 (false / no-error), the zero counterpart to fn_80215BAC's -1 sentinel. */
extern "C" s32 fn_80215BC0(void) {
    return 0;
}

extern "C" void fn_80214CB4(s32);
extern "C" void fn_80230E90(s32);
extern "C" s32 fn_80215BC8(WidgetRect *rect, s32 x, s32 y) {
    /* Hit test: answers 1 when the point (x, y) falls inside this widget's
     * rectangle.  The left and top edges belong to the rectangle, the right
     * and bottom ones do not. */
    s32 inside;

    inside = 0;
    if (x >= rect->left && x < rect->right && y >= rect->top && y < rect->bottom) {
        inside = 1;
    }
    return inside;
}

/* Returns the width (right minus left) of a widget's rectangle. */
extern "C" s32 fn_80215C08(void *arg0) {
    WidgetRect *rect = (WidgetRect *)arg0;
    return rect->right - rect->left;
}

/* Set the active window's menu index from this widget's flag at +0x18: 1 when the flag is clear, 0 when set. */
extern "C" void fn_80215C18(void *widget) {
    fn_80214CB4(*(u8 *)((char *)widget + 0x18) == 0);
}

extern "C" s32 fn_80215C28(s32 unused, s32 command) {
    /* Handle menu/UI command codes 0x125-0x128; returns 1 if handled, 0 otherwise. */
    switch (command) {
    case 0x125:
        fn_80214CB4(0);
        fn_80230E90(0);
        goto done;
    case 0x127:
        fn_80214CB4(1);
        fn_80230E90(0);
        goto done;
    case 0x126:
    case 0x128:
        goto done;
    default:
        return 0;
    }
done:
    return 1;
}

extern "C" void fn_80215CA0(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

extern "C" void fn_80215CA4(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

extern "C" void fn_80215CA8(void) {
	/* Widget-wrapper vtable method: forward to the helper that marks the wrapped VfWidget dirty. */
	fn_80221E7C();
}

extern "C" void fn_80215CAC(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

extern "C" void fn_80215CB0(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

extern "C" void fn_80215CB4(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

extern "C" void fn_80215CB8(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

extern "C" void fn_80215CBC(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

extern "C" void fn_80215CC0(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

extern "C" void fn_80215CC8(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

/* Empty default hook at vtable slot 0x3C of the UI-group timeout controller.
 * That class (base vtable lbl_8033D618) hides UI group 0x1D when started (its
 * slot 0xC fn_80262FCC / fn_802876A8 stores the start time at +0x18, clears
 * the expired flag at +0x1C and hides the group) and shows the group again
 * once the 1.5 s timer expires (slot 0x1C fn_8026300C / fn_802876E8; slot 0x58
 * reports whether it is still running).  The two global instances registered
 * by fn_80262EF8 and fn_802874C8 use the derived vtables lbl_80345F70 and
 * lbl_803489C0, and neither overrides this slot, so it does nothing. */
extern "C" void fn_80215CCC(void *timer) {

}

extern "C" void fn_80215CD0(void) {
    /* Empty no-op: an unoverridden default vtable method with no behaviour. */
}

extern "C" void fn_80215CD4(void) {
    /* Empty no-op: an unoverridden default vtable method with no behaviour. */
}

/* Base default for vtable slot 0x48 of the timed UI-group controller class
 * (base vtable lbl_8033D618; the instances registered by fn_80262EF8 and
 * fn_802874C8 use the derived vtables lbl_80345F70 and lbl_803489C0).  That
 * class hides UI group 0x1D when started (slot 0xC fn_80262FCC / fn_802876A8)
 * and shows it again once its 1.5 s timer expires (slot 0x1C fn_8026300C /
 * fn_802876E8), while slot 0x58 reports whether it is still running.  None of
 * the three vtables overrides this slot, so the default does nothing. */
extern "C" void fn_80215CD8(void *controller) {

}

/* Base default for vtable slot 0x4C of the timed UI-group controller class
 * (base vtable lbl_8033D618; the instances registered by fn_80262EF8 and
 * fn_802874C8 use the derived vtables lbl_80345F70 and lbl_803489C0), the
 * message right after the empty one at slot 0x48 and before the pair at
 * 0x50/0x54.  The class only implements starting its timer (slot 0xC), the
 * 1.5 s expiry tick (slot 0x1C) and the still-running test (slot 0x58), so
 * none of the three vtables overrides this slot and the default does
 * nothing. */
extern "C" void fn_80215CDC(void *controller) {

}

/* Base default for vtable slot 0x50 of the timed UI-group controller class
 * (base vtable lbl_8033D618; the instances registered by fn_80262EF8 and
 * fn_802874C8 use the derived vtables lbl_80345F70 and lbl_803489C0), the
 * first of the two message slots 0x50/0x54 that sit just before the
 * still-running test at slot 0x58.  The class implements only the timer start
 * (slot 0xC), the expiry tick (slot 0x1C) and that test, so no vtable of the
 * family overrides this slot and the default does nothing. */
extern "C" void fn_80215CE0(void *controller) {

}

// Default no-op handler among the empty stubs: returns 0 (no result available).
extern "C" s32 fn_80215CE4(void) { return 0; }

/* Widget-wrapper vtable method returning 0 (default/false), grouped with the adjacent no-op stubs. */
extern "C" s32 fn_80215CEC(void) {
    return 0;
}

extern "C" void fn_80215CC4(void) {
    /* Empty no-op: a default widget-wrapper vtable method with no behaviour. */
}

