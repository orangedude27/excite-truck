// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
typedef int M2C_UNK;
extern void *fn_801284F8(unsigned int, void *);
extern void *fn_8012850C(s32, void *);
extern void fn_801312EC(void *, void *);
__declspec(section ".sdata") extern char lbl_8055C0E0[];
extern char lbl_80344378[], lbl_80344384[], lbl_80344690[];
extern unsigned char lbl_8055C0E8;
extern unsigned int lbl_8055E044;
extern unsigned char *fn_80019098(unsigned char *);
extern int fn_80131318(void *);
extern u8 *fn_80131234(void *);
extern unsigned char lbl_8034287C[];
extern char *strncpy(char *, const char *, unsigned int);
#define M2C_FIELD(p,T,o) (*(T*)((u8*)(p)+(o)))
#define M2C_STRUCT_COPY(d,s,n) memcpy((d),(s),(n))
extern void *memcpy(void *, const void *, unsigned int);
static inline void CleanupEntries(void *table) {
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128670(s32);
    extern s32 fn_80128668(void *);
    s32 offset, i;
    u8 *entry;
    if (table != 0) {
        i = 0;
        offset = 0;
        for (; i < *(s32 *)((u8 *)table + 4); offset += 0x38, i++) {
            entry = *(u8 **)table + offset;
            fn_802CAC54(*(s32 *)(entry + 0x20));
            fn_802CAC54(*(s32 *)(entry + 0x24));
        }
        fn_80128670(*(s32 *)table);
        fn_80128668(table);
    }
}
extern double lbl_80563958;
extern unsigned char lbl_80498C48[];
s32 fn_8001668C(s32, s32);
s32 *fn_80016BC8(s32);
extern unsigned char lbl_803444D8[];
extern unsigned char lbl_8055C0C0;
extern void fn_801345D8(void *, s32, void *, ...);
extern void *lbl_8055F2E4;
extern s32 lbl_8055F2E8;
extern unsigned int lbl_8055F2EC;
extern void *fn_80018A8C(void *, void *);
extern s32 fn_80019258(void *, s32 *, s32 *);
extern void *fn_8001EFC0(s32, void *);
extern void fn_80130FCC(void *, s32, void *);
extern void fn_801345D8(void *, s32, void *, ...);
extern void fn_80255918(void *, s32);
extern void fn_8024739C(void);
#pragma push
#pragma use_lmw_stmw off
/* No-op hook wrapper: forwards to the stub fn_8024739C (which just returns 0); emitted as a tail call. */
void fn_8024DAD8(void) {
    fn_8024739C();
}

#pragma opt_tail_call on
/* No-op hook wrapper: forwards to the stub fn_8024739C (which just returns 0), emitted as a tail call. */
void fn_8024DADC(void) {
    fn_8024739C();
}

extern void *memset(void *, int, unsigned int);
extern void *fn_8024F17C(void *arg0, void **arg1, s32 *arg2, s32 *arg3, void *arg4, void *arg5);
extern void fn_8024EA1C(s32 arg0);
extern s32 fn_8024EB94(void *object);
extern s32 fn_8024EB9C(void *obj, s32 index);
extern void fn_8024EBAC(void *arg0, s32 arg1, s32 arg2);
extern s32 fn_8024EBE4(s32 self);
extern s32 fn_8024EC3C(void);
extern s32 fn_8024ECD4(void);
extern void *fn_8025007C(s32 count);
unsigned int fn_8024DAE0(s32 *out, s32 arg1, s32 idx, void **obj, s32 sel) {
    typedef struct { s32 w[3]; } Tbl3;
    typedef struct { const void *label; void *items; s32 a, b, c; } Dlg;
    typedef struct { const void *label; s32 type; void *value; s32 lo; s32 hi; } Item;
    extern int fn_8000DA10(void);
    extern unsigned char lbl_80498C30[];
    extern unsigned char lbl_80344170[];
    extern unsigned char lbl_80344410[];
    extern unsigned char lbl_80344474[];
    extern unsigned char lbl_8034453C[];
    extern Tbl3 lbl_802FA560;
    extern Dlg lbl_802FA56C;
    extern Dlg lbl_802FA580;
    extern unsigned char lbl_8055FC8C;
    extern char lbl_8055C0B0;
    extern char lbl_8055C0B8;
    extern char lbl_8055B860;
    extern void fn_8013C804(void);
    extern void fn_8001880C(void);
    extern void fn_802556BC(void *, s32);
    extern s32 fn_802E4A10(void);
    extern void fn_8002F53C(void *, void *, void *, s32, s32);
    extern void __array_delete(void *, void *, s32, s32);
    extern void fn_80255758(void *, s32);
    extern void fn_80018B24(void);
    extern void fn_8013C8B8(void);
    extern s32 fn_802146BC(s32 *, s32, s32, s32);
    extern s32 fn_80128314(s32);
    extern s32 fn_80265D58(void);
    extern void fn_80257C10(void *);
    extern s32 fn_80128670(s32);
    extern s32 fn_80235380(s32);
    extern s32 fn_802CAC54(s32);
    extern s32 MRollStatLabel_init(void);
    extern s32 fn_80240928(void);
    struct {
        s32 pad0;
        Tbl3 tbl2;
        Tbl3 tbl1;
        s32 pad;
        s32 info2[4];
        s32 info1[4];
        Dlg dlg2;
        Dlg dlg1;
        u8 screen[0xd4];
        Item items2[13];
        u8 sub[0x1e0];
        Item items1[24];
        u8 work[0x124];
        u8 opts[0x2c];
        u8 res[0xc8];
        char names[5][0x64];
    } m;
    register u8 *g = lbl_80498C30;
    u8 *slots;
    s32 *p;
    const void *label;
    s32 result;
    s32 r;
    s32 v;
    s32 i;
    s32 off;
    u8 *rec;
    void **list;
    void **owned;
    u8 *e;
    s32 *pA, *pB;

    v = fn_8000DA10();
    if (*(s32 *)(g + 0x18) != v) {
        *(s32 *)(g + 0x18) = v;
        p = (s32 *)(g + 0x18);
        p[4] = 0; p[2] = 0; p[5] = 2; p[3] = 2;
        p[8] = 0; p[6] = 0; p[9] = 2; p[7] = 2;
        p[12] = 0; p[10] = 0; p[13] = 2; p[11] = 2;
        p[16] = 0; p[14] = 0; p[17] = 2; p[15] = 2;
    }
    slots = g + 0x18;
    slots[4] = ((s32 (*)(void *))(*(void ***)obj)[5])(obj) == 1;
    fn_8013C804();
    fn_8001880C();
    result = -1;
    fn_802556BC(m.work, 0);
    *(s32 *)(m.work + 0xd8) = fn_802E4A10();
    fn_8002F53C(m.res, MRollStatLabel_init, fn_80240928, 0x28, 5);
    memset(m.opts, 0, 0x2c);
    m.names[0][0] = 0;
    m.names[1][0] = 0;
    m.names[2][0] = 0;
    m.names[3][0] = 0;
    m.names[4][0] = 0;
    pA = slots[4] ? (s32 *)(slots + idx * 16 + 0x14) : (s32 *)(slots + idx * 16 + 0xc);
    pB = slots[4] ? (s32 *)(slots + idx * 16 + 0x10) : (s32 *)(slots + idx * 16 + 0x8);
    fn_8024F17C(m.screen, obj, pA, pB, m.opts, m.work);
    *(void **)m.screen = lbl_80344474;
    lbl_8055F2EC = (unsigned int)m.screen;

    for (;;) {
        if (slots[4] == 0) {
            m.tbl1 = lbl_802FA560;
            m.items1[0].label = &lbl_80344170[0x40]; m.items1[0].type = 0x13; m.items1[0].value = m.work; m.items1[0].lo = 0; m.items1[0].hi = 0;
            m.items1[1].label = &lbl_80344170[0x40]; m.items1[1].type = 3; m.items1[1].value = m.screen + 0x60; m.items1[1].lo = 0; m.items1[1].hi = 0;
            m.items1[2].label = &lbl_80344170[0x4c]; m.items1[2].type = 3; m.items1[2].value = m.screen + 0x80; m.items1[2].lo = 0; m.items1[2].hi = 0;
            m.items1[3].label = &lbl_80344170[0x58]; m.items1[3].type = 5; m.items1[3].value = m.work + 0xfc; m.items1[3].lo = 0; m.items1[3].hi = 0;
            m.items1[4].label = &lbl_80344170[0x68]; m.items1[4].type = 3; m.items1[4].value = m.names[0]; m.items1[4].lo = 0; m.items1[4].hi = 0;
            m.items1[5].label = &lbl_80344170[0x78]; m.items1[5].type = 2; m.items1[5].value = m.opts + 0x8; m.items1[5].lo = 0; m.items1[5].hi = 0;
            m.items1[6].label = &lbl_80344170[0x84]; m.items1[6].type = 3; m.items1[6].value = m.names[1]; m.items1[6].lo = 0; m.items1[6].hi = 0;
            m.items1[7].label = &lbl_80344170[0x94]; m.items1[7].type = 2; m.items1[7].value = m.opts + 0x10; m.items1[7].lo = 0; m.items1[7].hi = 0;
            m.items1[8].label = &lbl_80344170[0xa0]; m.items1[8].type = 3; m.items1[8].value = m.names[2]; m.items1[8].lo = 0; m.items1[8].hi = 0;
            m.items1[9].label = &lbl_80344170[0xb0]; m.items1[9].type = 2; m.items1[9].value = m.opts + 0x18; m.items1[9].lo = 0; m.items1[9].hi = 0;
            m.items1[10].label = &lbl_80344170[0xbc]; m.items1[10].type = 3; m.items1[10].value = m.names[3]; m.items1[10].lo = 0; m.items1[10].hi = 0;
            m.items1[11].label = &lbl_80344170[0xcc]; m.items1[11].type = 5; m.items1[11].value = m.res + 0x78; m.items1[11].lo = 0; m.items1[11].hi = 0;
            m.items1[12].label = &lbl_80344170[0xdc]; m.items1[12].type = 3; m.items1[12].value = m.names[4]; m.items1[12].lo = 0; m.items1[12].hi = 0;
            m.items1[13].label = &lbl_80344170[0xec]; m.items1[13].type = 2; m.items1[13].value = m.opts + 0x28; m.items1[13].lo = 0; m.items1[13].hi = 0;
            m.items1[14].label = &lbl_80344170[0xf8]; m.items1[14].type = 3; m.items1[14].value = g + 0x60; m.items1[14].lo = 0; m.items1[14].hi = 0;
            m.items1[15].label = &lbl_8055C0B0; m.items1[15].type = 2; m.items1[15].value = m.screen + 0xc0; m.items1[15].lo = 0; m.items1[15].hi = 0;
            m.items1[16].label = &lbl_80344170[0x104]; m.items1[16].type = 3; m.items1[16].value = (void *)m.tbl1.w[sel]; m.items1[16].lo = 0; m.items1[16].hi = 0;
            m.items1[17].label = &lbl_80344170[0x114]; m.items1[17].type = 3; m.items1[17].value = m.screen + 0x3c; m.items1[17].lo = 0; m.items1[17].hi = 0;
            m.items1[18].label = &lbl_8055C0B8; m.items1[18].type = 3; m.items1[18].value = m.screen + 0x50; m.items1[18].lo = 0; m.items1[18].hi = 0;
            m.items1[19].label = 0; m.items1[19].type = 5; m.items1[19].value = m.screen; m.items1[19].lo = 0; m.items1[19].hi = 0;
            m.items1[20].label = &lbl_8055B860; m.items1[20].type = 6; m.items1[20].value = (void *)fn_8024ECD4; m.items1[20].lo = 0; m.items1[20].hi = 0x72;
            m.items1[21].label = &lbl_8055B860; m.items1[21].type = 6; m.items1[21].value = 0; m.items1[21].lo = -1; m.items1[21].hi = 0x1b;
            m.items1[22].label = &lbl_8055B860; m.items1[22].type = 6; m.items1[22].value = (void *)fn_8024EC3C; m.items1[22].lo = -2; m.items1[22].hi = 0xd;
            m.items1[23] = *(Item *)g;
            label = &lbl_80344170[0x138];
            if (lbl_8055FC8C) {
                label = &lbl_80344170[0x120];
            }
            m.dlg1 = lbl_802FA56C;
            m.dlg1.label = label;
            m.dlg1.items = m.items1;
            m.info1[0] = (s32)&lbl_80344170[0x148];
            m.info1[1] = fn_80128314(0);
            m.info1[2] = fn_80128314(1);
            m.info1[3] = fn_80265D58();
            result = fn_802146BC((s32 *)&m.dlg1, -999, -999, 1);
        }
        if (slots[4] != 0 || result == -2) {
            m.info2[0] = (s32)&lbl_80344170[0x158];
            m.info2[1] = fn_80128314(0);
            m.info2[2] = fn_80128314(1);
            m.info2[3] = fn_80265D58();
            rec = (u8 *)fn_8001668C((s32)(m.screen + 0x60), 0);
            list = (void **)fn_8025007C(*(s32 *)(rec + 0x98));
            for (i = 0; i < *(s32 *)(rec + 0x98); i++) {
                ((void (*)(void *, void *, s32, s32))(*(void ***)list)[3])(list, m.screen + 0x60, 1, 0);
            }
            fn_8024F17C(m.sub, list, pA, pB, m.opts, m.work);
            *(void **)m.sub = lbl_80344410;
            *(void **)(m.sub + 0xd8) = m.work;
            *(void ***)(m.sub + 0xd4) = list;
            *(s32 *)(m.sub + 0xdc) = arg1;
            fn_8024EBAC(m.sub, fn_8024EBE4((s32)m.sub), 1);
            fn_8024EB9C(m.sub, 0);
            for (i = 0, off = 0; i < fn_8024EB94(m.sub); i++, off += 4) {
                e = (u8 *)fn_8024EB9C(m.sub, i);
                *(s32 *)(e + 0x10) = *(s32 *)(*(u8 **)(e + 8) + off + 0x64);
            }
            fn_8024EA1C((s32)m.sub);
            m.tbl2 = lbl_802FA560;
            m.dlg2 = lbl_802FA580;
            m.items2[0].label = 0; m.items2[0].type = 5; m.items2[0].value = m.sub; m.items2[0].lo = 0; m.items2[0].hi = 0;
            m.items2[1].label = &lbl_80344170[0x40]; m.items2[1].type = 0x13; m.items2[1].value = m.work; m.items2[1].lo = 0; m.items2[1].hi = 0;
            m.items2[2].label = &lbl_80344170[0x40]; m.items2[2].type = 3; m.items2[2].value = m.screen + 0x60; m.items2[2].lo = 0; m.items2[2].hi = 0;
            m.items2[3].label = &lbl_80344170[0x4c]; m.items2[3].type = 3; m.items2[3].value = m.screen + 0x80; m.items2[3].lo = 0; m.items2[3].hi = 0;
            m.items2[4].label = &lbl_80344170[0x168]; m.items2[4].type = 3; m.items2[4].value = m.sub + 0xe0; m.items2[4].lo = 0; m.items2[4].hi = 0;
            m.items2[5].label = &lbl_80344170[0x58]; m.items2[5].type = 5; m.items2[5].value = m.work + 0xfc; m.items2[5].lo = 0; m.items2[5].hi = 0;
            m.items2[6].label = &lbl_8055C0B0; m.items2[6].type = 2; m.items2[6].value = m.screen + 0xc0; m.items2[6].lo = 0; m.items2[6].hi = 0;
            m.items2[7].label = &lbl_80344170[0x104]; m.items2[7].type = 3; m.items2[7].value = (void *)m.tbl2.w[sel]; m.items2[7].lo = 0; m.items2[7].hi = 0;
            m.items2[8].label = &lbl_80344170[0x114]; m.items2[8].type = 3; m.items2[8].value = m.screen + 0x3c; m.items2[8].lo = 0; m.items2[8].hi = 0;
            m.items2[9].label = &lbl_8055C0B8; m.items2[9].type = 3; m.items2[9].value = m.screen + 0x50; m.items2[9].lo = 0; m.items2[9].hi = 0;
            m.items2[10].label = &lbl_8055B860; m.items2[10].type = 6; m.items2[10].value = 0; m.items2[10].lo = -1; m.items2[10].hi = 0x1b;
            m.items2[11].label = &lbl_8055B860; m.items2[11].type = 6; m.items2[11].value = 0; m.items2[11].lo = -2; m.items2[11].hi = 0xd;
            m.items2[12] = *(Item *)g;
            m.dlg2.items = m.items2;
            r = fn_802146BC((s32 *)&m.dlg2, -999, -999, 1);
            if (r == -2 && slots[4] != 0) {
                result = r;
            } else if (r == -1 && slots[4] == 0) {
                owned = *(void ***)(m.sub + 0xd4);
                *(void **)m.sub = lbl_80344410;
                if (owned != 0) {
                    ((void (*)(void *, s32))(*(void ***)owned)[2])(owned, 1);
                }
                *(void **)m.sub = lbl_803444D8;
                fn_80128670(*(s32 *)(m.sub + 0xcc));
                if (--lbl_8055F2E8 == 0) {
                    CleanupEntries(lbl_8055F2E4);
                    lbl_8055F2E4 = 0;
                }
                *(void **)m.sub = lbl_8034453C;
                fn_80128670(*(s32 *)(m.sub + 0x18));
                fn_80235380(*(s32 *)(m.sub + 0x24));
                fn_802CAC54(*(s32 *)(m.sub + 0x20));
                continue;
            }
            owned = *(void ***)(m.sub + 0xd4);
            *(void **)m.sub = lbl_80344410;
            if (owned != 0) {
                ((void (*)(void *, s32))(*(void ***)owned)[2])(owned, 1);
            }
            *(void **)m.sub = lbl_803444D8;
            fn_80128670(*(s32 *)(m.sub + 0xcc));
            if (--lbl_8055F2E8 == 0) {
                CleanupEntries(lbl_8055F2E4);
                lbl_8055F2E4 = 0;
            }
            *(void **)m.sub = lbl_8034453C;
            fn_80128670(*(s32 *)(m.sub + 0x18));
            fn_80235380(*(s32 *)(m.sub + 0x24));
            fn_802CAC54(*(s32 *)(m.sub + 0x20));
        }
        if (result != 3) {
            break;
        }
        fn_80257C10(m.screen + 0x60);
    }

    lbl_8055F2EC = 0;
    *(void **)m.screen = lbl_803444D8;
    fn_80128670(*(s32 *)(m.screen + 0xcc));
    if (--lbl_8055F2E8 == 0) {
        CleanupEntries(lbl_8055F2E4);
        lbl_8055F2E4 = 0;
    }
    *(void **)m.screen = lbl_8034453C;
    fn_80128670(*(s32 *)(m.screen + 0x18));
    fn_80235380(*(s32 *)(m.screen + 0x24));
    fn_802CAC54(*(s32 *)(m.screen + 0x20));
    __array_delete(m.res, fn_80240928, 0x28, 5);
    fn_80255758(m.work, -1);
    fn_80018B24();
    fn_8013C8B8();
    *out = *pB;
    return result != -1;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_8024E6E4(void *self, s32 shouldDelete) {
    extern unsigned char lbl_80344410[];
    extern unsigned char lbl_8034453C[];
    extern s32 fn_80128670(s32);
    extern s32 fn_80235380(s32);
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128668(void *);
    class V { public: virtual void f2(int); };
    V *ownedObject;
    /* Destroy this object: tear down owned subobjects/resources across its base vtables, release shared state when refcount hits zero, and optionally free it. */
    if (self != 0) {
        ownedObject = *(V **)((u8 *)self + 0xD4);
        *(void **)self = lbl_80344410;
        if (ownedObject != 0) ownedObject->f2(1);
        if (self != 0) {
            *(void **)self = lbl_803444D8;
            fn_80128670(*(s32 *)((u8 *)self + 0xCC));
            if (--lbl_8055F2E8 == 0) { CleanupEntries(lbl_8055F2E4); lbl_8055F2E4 = 0; }
            if (self != 0) {
                *(void **)self = lbl_8034453C;
                fn_80128670(*(s32 *)((u8 *)self + 0x18));
                fn_80235380(*(s32 *)((u8 *)self + 0x24));
                fn_802CAC54(*(s32 *)((u8 *)self + 0x20));
            }
        }
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}
#pragma scheduling on
#pragma pop
void *fn_8024E818(void *object, s32 destroyFlag) {
    /* Destructor-like teardown: clear a global state word, optionally run two vtable-staged
       cleanup sequences releasing associated resources/refcounts, and conditionally perform a
       final delete/free step based on destroyFlag. */
    extern unsigned int lbl_8055F2EC;
    extern unsigned char lbl_8034453C[];
    extern s32 fn_80128670(s32);
    extern s32 fn_80235380(s32);
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128668(void *);
    if (object != 0) {
        lbl_8055F2EC = 0;
        if (object != 0) {
            *(void **)object = lbl_803444D8;
            fn_80128670(*(s32 *)((u8 *)object + 0xCC));
            if (--lbl_8055F2E8 == 0) {
                CleanupEntries(lbl_8055F2E4);
                lbl_8055F2E4 = 0;
            }
            if (object != 0) {
                *(void **)object = lbl_8034453C;
                fn_80128670(*(s32 *)((u8 *)object + 0x18));
                fn_80235380(*(s32 *)((u8 *)object + 0x24));
                fn_802CAC54(*(s32 *)((u8 *)object + 0x20));
            }
        }
        if (destroyFlag > 0) fn_80128668(object);
    }
    return object;
}

void *fn_8024E920(void *self, s32 shouldDelete) {
    extern unsigned char lbl_8034453C[];
    extern s32 fn_80128670(s32);
    extern s32 fn_80235380(s32);
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128668(void *);
    /* Destructor-like teardown: set the first vtable, release the resource at +0xCC, drop the
       shared refcount and clean up its table on zero, then run the base vtable stage releasing
       +0x18/+0x24/+0x20; conditionally delete the object and return it. */
    if (self != 0) {
        *(void **)self = lbl_803444D8;
        fn_80128670(*(s32 *)((u8 *)self + 0xCC));
        if (--lbl_8055F2E8 == 0) {
            CleanupEntries(lbl_8055F2E4);
            lbl_8055F2E4 = 0;
        }
        if (self != 0) {
            *(void **)self = lbl_8034453C;
            fn_80128670(*(s32 *)((u8 *)self + 0x18));
            fn_80235380(*(s32 *)((u8 *)self + 0x24));
            fn_802CAC54(*(s32 *)((u8 *)self + 0x20));
        }
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

#pragma push
#pragma opt_common_subs off
#pragma scheduling invalid_target
/* Update selection-dependent value and label text for a UI/menu entry. */
void fn_8024EA1C(s32 arg0) {
    s32 base = fn_8001668C(arg0 + 0x60, 0);
    s32 *secondary;
    s32 choiceBase;
    s32 selectedIndex;
    register u8 *src;
    register u8 c;
    register s32 count;
    register u8 *dst;

    if (lbl_80498C48[4] != 0) {
        ((s32 *(*)(s32, s32))fn_80016BC8)(base, 0)[0] =
            *(s32 *)((u8 *)arg0 + 0x2C);
    } else {
        ((s32 *(*)(s32, s32))fn_80016BC8)(base, 0)[1] =
            *(s32 *)((u8 *)arg0 + 0x2C);
    }

    *(s32 *)*(s32 **)((u8 *)arg0 + 0xDC) =
        *(s32 *)((u8 *)base +
                 *(s32 *)((u8 *)arg0 + 0x2C) * 4 + 0x64);

    secondary = (s32 *)fn_8001668C(arg0 + 0x60, 0);
    choiceBase = fn_8001668C(arg0 + 0x60, 0);
    if (lbl_80498C48[4] != 0) {
        selectedIndex = ((s32 *(*)(s32, s32))fn_80016BC8)(choiceBase, 0)[0];
    } else {
        selectedIndex = ((s32 *(*)(s32, s32))fn_80016BC8)(choiceBase, 0)[1];
    }

    {
        void *targetObject = *(void **)((u8 *)arg0 + 0x4C);
        s32 value = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0xCC) +
                             *(s32 *)((u8 *)arg0 + 0x2C) * 0x14 + 0x10);
        switch (value) {
        case 0:
            value = *(s32 *)((u8 *)secondary + selectedIndex * 4 + 0x64);
            break;
        default:
            break;
        }
        fn_80255918(targetObject, value);
    }

    fn_801345D8((u8 *)arg0 + 0xE0, 0x100, lbl_8034287C,
                *(s32 *)((u8 *)arg0 + 0x2C) + 1);
    src = fn_80131234((u8 *)arg0 + 0xE0);
    dst = (u8 *)arg0 + 0xE0;
    count = 0x100;
    goto copy_loop;
copy_count:
    count--;
    if (count <= 0) {
        dst[-1] = 0;
        return;
    }
copy_loop:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0) {
        goto copy_count;
    }
}

#pragma pop
/* Return the 32-bit field at offset 0x1C of `object` (used as a count/limit in menu comparisons). */
s32 fn_8024EB94(void *object) { return *(s32 *)((char *)object + 0x1C); }

/* Address of the 20-byte (0x14) record at `index` in the table whose base
   pointer is stored at `obj` + 0xCC. */
s32 fn_8024EB9C(void *obj, s32 index) { return *(s32 *)((char *)obj + 0xCC) + index * 0x14; }

void fn_8024EBAC(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((char *)arg0 + 0x2C) = arg1;
    if (arg2 != 0) {
        *(f32 *)((char *)arg0 + 0x28) = (f32)arg1;
    }
}

#pragma scheduling invalid_target
s32 fn_8024EBE4(s32 self) {
    /* Look up a paired entry for this object and return one of its two values based on a global mode flag. */
    s32 value = fn_8001668C(self + 0x60, 0);
    if (lbl_80498C48[4] != 0) {
        return ((s32 *(*)(s32, s32))fn_80016BC8)(value, 0)[0];
    }
    return ((s32 *(*)(s32, s32))fn_80016BC8)(value, 0)[1];
}

#pragma cplusplus on
class Dummy_8024EC3C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual int f5(int);
};
#pragma cplusplus on
/* Gate check: returns 1 when required mode flags are set or the current object's
 * callback accepts; otherwise performs the fallback transition and returns 0. */
extern "C" s32 fn_8024EC3C(void) {
    extern unsigned int lbl_8055F2EC;
    extern s32 fn_80129800(void *, int);
    extern s32 fn_802E4A10(void);
    extern void fn_80216D28(void);
    extern s32 fn_80214D50(s32);
    s32 flagsSatisfied = 0;
    if (fn_80129800((void *)fn_802E4A10(), 5) != 0) {
        if (fn_80129800((void *)fn_802E4A10(), 6) != 0) flagsSatisfied = 1;
    }
    if (flagsSatisfied == 0) {
        u8 *stateBase = (u8 *)lbl_8055F2EC;
        void *targetObject = *(void **)(stateBase + 0xD0);
        s32 callbackArg = *(s32 *)(stateBase + 0x2C);
        if (((Dummy_8024EC3C *)targetObject)->f5(callbackArg) == 0) goto do_fallback;
    }
    return 1;
do_fallback:
    fn_80216D28();
    fn_80214D50(1);
    return 0;
}

extern "C" void *memset(void *, int, unsigned int);

extern unsigned char lbl_803442E4[];
extern "C" s32 fn_80129D18(s32, s32);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/*
 * UpdateEntryInfo (proposed name; game symbols can't be renamed yet).
 * Refreshes the info panel of the entry list (lbl_8055F2EC) for the entry the
 * cursor is on.  Asks the list (base + 0xD0) which entry that is, looks its name
 * up in the entry records, copies the name (base + 0x60, 32 bytes) and the asset
 * path or description (base + 0x80, 64 bytes) into the screen, loads the entry's
 * 0x2C-byte parameter record into the block at base + 0x38 along with the five
 * names that go with it, formats the two "value/record" strings at base + 0x3C
 * and 0x50 and finally tells the icon object (base + 0x4C) which entry to show.
 */
extern "C" s32 fn_8024ECD4(void) {
    typedef signed char s8;
    // One of the five per-entry tables of the parameter block (base + 0x38 + 0x2C).
    class EntryTable {
    public:
        virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3();
        virtual void t4(); virtual void t5(); virtual void t6(); virtual void t7();
        virtual void t8(); virtual void t9(); virtual void t10(); virtual void t11();
        virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15();
        virtual void t16(); virtual void t17(); virtual void t18(); virtual void t19();
        virtual void t20(); virtual void t21();
        virtual void fill(s32, void *, void *); // slot 0x60
    };
    // The list the screen is showing entries of (base + 0xD0).
    class EntryList {
    public:
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3();
        virtual void *getName(s32);        // slot 0x18, entry name for an index
        virtual s32 getUnknown(s32);       // slot 0x1C
        virtual void *getExtremeName(s32); // slot 0x20, name of its extreme version
        virtual s32 isExtreme(s32);        // slot 0x24, entry shown as "\\extreme_star"
    };
    void *origName;     // name the list gave before the extreme swap
    u8 *params;         // parameter block, base + 0x38
    void *name;         // entry name looked up in the records
    s32 prevRecord;
    register s32 word1;
    s32 i;
    register s32 index; // entry the cursor is on, also stored at base + 0x2C
    s32 lookup;
    s32 record1;        // record of the second value, -1 when there is none
    s32 record0;        // record of the first value, -1 when there is none
    s32 *out30;         // where the entry's 0x9C value goes, base + 0x30
    s32 value9c;
    register s32 word2;
    s32 value;
    void *object;       // icon object, base + 0x4C
    s32 nameCount;
    u8 *src;
    u8 *src2;
    s32 count;
    s32 count2;
    s32 selected;
    u8 *nameDst;
    u8 *dst;
    u8 *dst2;
    u8 *nameSrc;
    s32 c3;
    s32 c;
    s32 c2;
    u8 *secondary;
    void *paramRec;     // the entry's 0x2C-byte parameter record
    u8 *record;         // the entry's record in the entry table
    u8 *entryPtr;
    u8 *nameSlot;
    u8 *nameBase;
    u8 *values;
    u8 *table;
    u8 *base;           // the screen object, lbl_8055F2EC

    // where the cursor has animated to, kept inside the list
    index = fn_80129D18(1, M2C_FIELD(lbl_8055F2EC, s32, 0x1C) - 1);
    base = (u8 *)lbl_8055F2EC;
    M2C_FIELD(base, s32, 0x2C) = index;
    name = (*(EntryList **)(base + 0xD0))->getName(index);
    prevRecord = fn_8001668C((s32)name, 0);
    origName = name;
    // an extreme version of the entry exists and the list wants it: show that one
    if ((s32) M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(prevRecord, 0), u8, 8) != 0) {
        if ((*(EntryList **)(base + 0xD0))->isExtreme(index) != 0) {
            name = (*(EntryList **)(base + 0xD0))->getExtremeName(index);
        }
    }
    record = (u8 *)fn_8001668C((s32)name, 0);
    // strncpy(base + 0x60, record + 0x2C, 0x20): the entry's name
    src = record + 0x2C;
    dst = base + 0x60;
    count = 0x20;
    goto copy_loop_a_body;
copy_loop_a_count:
    count--;
    if (count > 0) goto copy_loop_a_body;
    M2C_FIELD(dst, s8, -1) = 0;
    goto copy_loop_a_end;
copy_loop_a_body:
    c = *src++;
    *dst++ = c;
    if ((s8)c != 0) goto copy_loop_a_count;
copy_loop_a_end:
    if ((*(EntryList **)(base + 0xD0))->isExtreme(index) != 0) {
        // "\\extreme_star %s" on the record's name (record + 0xC, without its first char)
        fn_801345D8(base + 0x80, 0x40, &lbl_803442E4, record + 0xD);
    } else {
        // strncpy(base + 0x80, record + 0xC, 0x40): its description
        src2 = record + 0xC;
        dst2 = base + 0x80;
        count2 = 0x40;
        goto copy_loop_b_body;
copy_loop_b_count:
        count2--;
        if (count2 > 0) goto copy_loop_b_body;
        M2C_FIELD(dst2, s8, -1) = 0;
        goto copy_loop_b_end;
copy_loop_b_body:
        c2 = *src2++;
        *dst2++ = c2;
        if ((s8)c2 != 0) goto copy_loop_b_count;
copy_loop_b_end: ;
    }
    M2C_FIELD(base, s32, 0xC4) = ((*(EntryList **)(base + 0xD0))->isExtreme(index) != 0) ? 5 : -1;
    *M2C_FIELD(base, s32 **, 0x34) = M2C_FIELD(record, s32 *, 4);
    value9c = *(volatile s32 *)((u8 *)record + 0x9C);
    out30 = *(s32 * volatile *)((u8 *)base + 0x30);
    *out30 = value9c;
    params = (u8 *)M2C_FIELD(base, void *, 0x38);
    paramRec = fn_80018A8C(record + 0x2C, out30);
    if (paramRec != 0) {
        entryPtr = params;
        nameBase = params;
        // the record's 11 words: the entry's parameters and the names of its five parts
        M2C_FIELD(params, s32, 0) = M2C_FIELD(paramRec, s32, 0);
        word2 = M2C_FIELD(paramRec, s32, 4);
        word1 = M2C_FIELD(paramRec, s32, 8);
        M2C_FIELD(params, s32, 4) = word2;
        M2C_FIELD(params, s32, 8) = word1;
        word1 = M2C_FIELD(paramRec, s32, 0xC);
        word2 = M2C_FIELD(paramRec, s32, 0x10);
        M2C_FIELD(params, s32, 0xC) = word1;
        M2C_FIELD(params, s32, 0x10) = word2;
        word1 = M2C_FIELD(paramRec, s32, 0x14);
        word2 = M2C_FIELD(paramRec, s32, 0x18);
        M2C_FIELD(params, s32, 0x14) = word1;
        M2C_FIELD(params, s32, 0x18) = word2;
        word1 = M2C_FIELD(paramRec, volatile s32, 0x1C);
        word2 = M2C_FIELD(paramRec, volatile s32, 0x20);
        M2C_FIELD(params, s32, 0x1C) = word1;
        M2C_FIELD(params, s32, 0x20) = word2;
        word1 = M2C_FIELD(paramRec, volatile s32, 0x24);
        word2 = M2C_FIELD(paramRec, volatile s32, 0x28);
        M2C_FIELD(params, s32, 0x24) = word1;
        M2C_FIELD(params, s32, 0x28) = word2;
        nameSlot = params + 0xF4; // five names of 0x64 bytes each
        values = params + 8;
        table = params + 0x2C;    // five entry tables of 0x28 bytes each
        i = 0;
        do {
            nameSrc = M2C_FIELD(entryPtr, u8 *, 4); // the record's name pointer
            if (nameSrc != 0) {
                nameDst = nameSlot;
                nameCount = 0x64;
                goto copy_loop_c_body;
copy_loop_c_count:
                nameCount--;
                if (nameCount > 0) goto copy_loop_c_body;
                M2C_FIELD(nameDst, s8, -1) = 0;
                goto copy_loop_c_end;
copy_loop_c_body:
                c3 = *nameSrc++;
                *nameDst++ = c3;
                if ((s8)c3 == 0) goto copy_loop_c_end;
                goto copy_loop_c_count;
copy_loop_c_end: ;
            } else {
                M2C_FIELD(nameBase, s8, 0xF4) = 0; // no name: empty slot
            }
            ((EntryTable *)table)->fill(i, values, params + 0x2E8);
            i += 1;
            entryPtr += 8;
            nameSlot += 0x64;
            nameBase += 0x64;
            values += 8;
            table += 0x28;
        } while (i < 5);
    } else {
        memset(params, 0, 0x2C);
        M2C_FIELD(params, s8, 0xF4) = 0;
        M2C_FIELD(params, s8, 0x158) = 0;
        M2C_FIELD(params, s8, 0x1BC) = 0;
        M2C_FIELD(params, s8, 0x220) = 0;
        M2C_FIELD(params, s8, 0x284) = 0;
    }
    M2C_FIELD(M2C_FIELD(base, void *, 0x4C), s8, 0xDD) = (s8) ((*(EntryList **)(base + 0xD0))->getUnknown(index) == 0);
    record0 = -1;
    record1 = -1;
    if (fn_80019258(origName, &record0, &record1) == 0) {
        record1 = -1;
        record0 = -1;
    }
    // "value/record" once records exist for the entry, plain "value" otherwise
    if ((*(EntryList **)(base + 0xD0))->isExtreme(index) == 0 && record0 >= 0 && record1 >= 0) {
        fn_801345D8(base + 0x3C, 0x10, &lbl_8055C0C0, fn_8001EFC0(0, base + 0x60), record0);
        fn_801345D8(base + 0x50, 0x10, &lbl_8055C0C0, fn_8001EFC0(1, base + 0x60), record1);
    } else {
        fn_80130FCC(base + 0x3C, 0x10, fn_8001EFC0(0, base + 0x60));
        fn_80130FCC(base + 0x50, 0x10, fn_8001EFC0(1, base + 0x60));
    }
    secondary = (u8 *)fn_8001668C((s32)(base + 0x60), 0);
    lookup = fn_8001668C((s32)(base + 0x60), 0);
    if ((s32) M2C_FIELD(&lbl_80498C48, u8, 4) != 0) {
        selected = *((s32 *(*)(s32, s32))fn_80016BC8)(lookup, 0);
    } else {
        selected = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(lookup, 0), s32, 4);
    }
    object = M2C_FIELD(base, void *, 0x4C);
    value = M2C_FIELD(((u8 *)M2C_FIELD(base, s32 *, 0xCC) + (M2C_FIELD(base, s32, 0x2C) * 0x14)), s32, 0x10);
    switch (value) {
    case 0:
        value = M2C_FIELD((secondary + (selected * 4)), s32, 0x64);
        break;
    default:
        break;
    }
    fn_80255918(object, value);
    return 0;
}
#pragma pop

#pragma cplusplus off

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_8024F17C(void *arg0, void **arg1, s32 *arg2, s32 *arg3, void *arg4, void *arg5) {
    typedef signed char s8;
    extern f32 lbl_80563960;
    extern unsigned char lbl_80344170[];
    extern unsigned char lbl_8034453C[];
    extern unsigned char lbl_80344720[];
    extern unsigned char lbl_80344730[];
    extern unsigned char lbl_80344740[];
    extern unsigned char lbl_80344750[];
    extern unsigned char lbl_80344760[];
    extern unsigned char lbl_8055C0C0;
    extern unsigned char lbl_8055C0C8[];
    extern unsigned char lbl_8055C0D0[];
    extern unsigned char lbl_8055C0EC[];
    extern unsigned char lbl_8055C0F0[];
    extern unsigned char lbl_8055C0F4[];
    extern unsigned char lbl_8055C0F8[];
    extern unsigned char lbl_8055C0FC[];
    extern unsigned char lbl_8055C100[];
    extern unsigned char lbl_8055C108[];
    extern unsigned char lbl_8055C10C[];
    extern unsigned char lbl_8055C114[];
    extern void *fn_80016544(void *);
    extern void *fn_80018A8C(void *, void *);
    extern s32 fn_80019258(void *, s32 *, s32 *);
    extern void *fn_8001EFC0(s32, void *);
    extern void *fn_801284F8(unsigned int, void *);
    extern void *fn_8012850C(s32, void *);
    extern void fn_80130FCC(void *, s32, void *);
    extern void *fn_80131808(void *);
    extern void fn_80131818(void *);
    extern void fn_801345D8(void *, s32, void *, ...);
    extern s32 fn_8023512C(void *);
    extern void fn_80255918(void *, s32);
    extern s32 fn_802CAC28(void *, s32);
    extern void fn_802E317C(void *, void *);
    extern int strcmp(const char *, const char *);
    extern int stricmp(const char *, const char *);
    void *this_obj = arg0;
    void **v_arg1 = arg1;
    s32 *v_arg2 = arg2;
    s32 *v_arg3 = arg3;
    void *v_arg4 = arg4;
    void *v_arg5 = arg5;
    const unsigned char *base_4170 = lbl_80344170;
    const char *s; void *t7; s32 spC; s32 sp8; void *var_r3_2; void *var_r3_3; f32 temp_f31;
    void *temp_r21; s32 *temp_r4_2; void *var_r17; s32 temp_r0; s32 temp_r3; s32 temp_r5;
    s32 temp_r5_2; void *temp_r6; s32 var_r0; s32 var_r14; s32 var_r16; s32 var_r17_2;
    s32 var_r17_3; s32 var_r19; s32 var_r22; s32 var_r22_2; s32 var_r23; s32 var_r23_2;
    s32 var_r27; s32 var_r28; s32 var_r4; s32 var_r4_5; s32 var_r4_6; s32 var_r5;
    s32 var_r5_2; s32 var_r5_3; s32 var_r5_4; s32 var_r5_5; s32 var_r5_7;
    u8 *temp_r24; u8 *var_r19_2; u8 *var_r3; u8 *var_r4_2; u8 *var_r4_3; u8 *var_r4_4;
    u8 *var_r5_6; u8 *var_r6; u8 *var_r6_2; u8 *var_r6_3; u8 *var_r6_4; u8 *var_r6_5;
    u8 temp_r3_17; u8 temp_r3_19; u8 temp_r3_22; u8 temp_r3_6; u8 temp_r4; void *temp_r18;
    void **temp_r3_10; void **temp_r3_13; void **temp_r3_14; void **temp_r3_15;
    void **temp_r3_18; void **temp_r3_20; void **temp_r3_23; void **temp_r3_24;
    void **temp_r3_4; void **temp_r3_5; void **temp_r3_7; void **temp_r3_9;
    void *var_r22_3; void *temp_r14; void *temp_r14_2; void *temp_r16; void *temp_r26;
    void *temp_r3_11; void *temp_r3_12; void *temp_r3_16; void *temp_r3_21;
    void *temp_r3_2; void *temp_r3_3; void *temp_r3_8; void *var_r16_2;
    void *var_r18; void *var_r20; void *var_r21; void *var_r24;
    temp_r3 = ((s32 (*)(void *))(*(void ***)v_arg1)[5])(v_arg1);
    M2C_FIELD(this_obj, s32, 0x1C) = temp_r3;
    M2C_FIELD(this_obj, void *, 0) = lbl_8034453C;
    M2C_FIELD(this_obj, s32, 0x14) = 0;
    M2C_FIELD(this_obj, void *, 0x18) = fn_8012850C(temp_r3 * 0xC, lbl_8055C0C8);
    for (var_r4 = 0, var_r5 = 0; var_r4 < M2C_FIELD(this_obj, s32, 0x1C); var_r4++, var_r5 += 0xC) {
        temp_r0 = (s32)M2C_FIELD(this_obj, void *, 0x18);
        temp_r3_2 = (void *)(temp_r0 + var_r5);
        M2C_FIELD(temp_r3_2, s32, 4) = 0;
        *(s32 *)(var_r5 + temp_r0) = 0;
        M2C_FIELD(temp_r3_2, f32, 8) = lbl_80563960;
    }
    M2C_FIELD(this_obj, s32, 0x24) = fn_8023512C((void *)(base_4170 + 0x188));
    M2C_FIELD(this_obj, s32, 0x20) = fn_802CAC28((void *)(base_4170 + 0x198), 0);
    M2C_FIELD(this_obj, s32, 0x2C) = 0;
    M2C_FIELD(this_obj, void *, 0) = lbl_803444D8;
    M2C_FIELD(this_obj, f32, 0x28) = 0.0f;
    if (lbl_8055F2E8 == 0) {
        temp_r3_3 = fn_801284F8(8, lbl_8055C114);
        if (temp_r3_3 != 0) {
            temp_r3_4 = (void **)fn_80131808(lbl_80344760);
            M2C_FIELD(temp_r3_3, s32, 4) = 0;
            M2C_FIELD(temp_r3_3, void *, 0) = fn_8012850C(0xAF0, lbl_8055C10C);
            var_r22 = 0;
loop_27:
            temp_r3_5 = ((void **(*)(void *, s32))temp_r3_4[3])(temp_r3_4, var_r22);
            if (temp_r3_5 != 0) {
                s = ((const char *(*)(void *))temp_r3_5[2])(temp_r3_5);
                if (strcmp(s, (const char *)lbl_8055C108) == 0) {
                    var_r23 = 0;
                    do {
                        temp_r5 = M2C_FIELD(temp_r3_3, s32, 4);
                        temp_r6 = M2C_FIELD(temp_r3_3, void *, 0);
                        M2C_FIELD(temp_r3_3, s32, 4) = temp_r5 + 1;
                        temp_r24 = (u8 *)temp_r6 + (temp_r5 * 0x38);
                        var_r3 = ((u8 *(*)(void *, void *))temp_r3_5[5])(temp_r3_5, lbl_8055C100);
                        var_r6 = temp_r24; var_r5_2 = 0x20;
loop_11:
                        temp_r4 = *var_r3; var_r3 += 1; *var_r6 = temp_r4; var_r6 += 1;
                        if ((s8) temp_r4 != 0) {
                            var_r5_2 -= 1;
                            if (var_r5_2 <= 0) { *(s8 *)(var_r6 - 1) = 0; } else { goto loop_11; }
                        }
                        if (var_r23 != 0) {
                            var_r6_2 = temp_r24; var_r5_3 = 0x20;
loop_15:
                            if ((s8) *var_r6_2 != 0) { var_r5_3 -= 1; var_r6_2 += 1; goto loop_15; }
                            if (var_r5_3 > 0) {
                                var_r4_2 = lbl_8055C0FC;
loop_20:
                                temp_r3_6 = *var_r4_2; var_r4_2 += 1; *var_r6_2 = temp_r3_6; var_r6_2 += 1;
                                if ((s8) temp_r3_6 != 0) {
                                    var_r5_3 -= 1;
                                    if (var_r5_3 <= 0) { *(s8 *)(var_r6_2 - 1) = 0; } else { goto loop_20; }
                                }
                            }
                        }
                        var_r3_2 = lbl_80344740;
                        if (var_r23 != 0) { var_r3_2 = lbl_80344750; }
                        M2C_FIELD(temp_r24, s32, 0x20) = fn_802CAC28(var_r3_2, 0);
                        var_r3_3 = lbl_80344720;
                        if (var_r23 != 0) { var_r3_3 = lbl_80344730; }
                        M2C_FIELD(temp_r24, s32, 0x24) = fn_802CAC28(var_r3_3, 0);
                        M2C_FIELD(temp_r24, f32, 0x28) = ((f32 (*)(void *, void *))temp_r3_5[9])(temp_r3_5, lbl_8055C0F8);
                        M2C_FIELD(temp_r24, f32, 0x2C) = ((f32 (*)(void *, void *))temp_r3_5[9])(temp_r3_5, lbl_8055C0F4);
                        M2C_FIELD(temp_r24, f32, 0x30) = ((f32 (*)(void *, void *))temp_r3_5[9])(temp_r3_5, lbl_8055C0F0);
                        var_r23 += 1;
                        M2C_FIELD(temp_r24, f32, 0x34) = ((f32 (*)(void *, void *))temp_r3_5[9])(temp_r3_5, lbl_8055C0EC);
                    } while (var_r23 < 2);
                }
                var_r22 += 1; goto loop_27;
            }
            fn_80131818(temp_r3_4);
        }
        lbl_8055F2E4 = temp_r3_3;
    }
    temp_r5_2 = lbl_8055F2E8; lbl_8055F2E8 = temp_r5_2 + 1;
    M2C_FIELD(this_obj, void *, 0xC8) = lbl_8055F2E4;
    M2C_FIELD(this_obj, void *, 0xD0) = v_arg1;
    M2C_FIELD(this_obj, void *, 0x30) = v_arg2;
    M2C_FIELD(this_obj, void *, 0x34) = v_arg3;
    M2C_FIELD(this_obj, void *, 0x38) = v_arg4;
    M2C_FIELD(this_obj, void *, 0x4C) = v_arg5;
    M2C_FIELD(this_obj, s8, 0x80) = 0;
    M2C_FIELD(this_obj, void *, 0xCC) = fn_8012850C(M2C_FIELD(this_obj, s32, 0x1C) * 0x14, lbl_8055C0D0);
    temp_f31 = lbl_80563960;
    temp_r18 = fn_80131808((void *)(base_4170 + 0x1A8));
    var_r23_2 = 0; var_r19 = 0; var_r14 = 0; var_r16 = 0;
loop_54:
    if (var_r19 < M2C_FIELD(this_obj, s32, 0x1C)) {
        temp_r3_7 = M2C_FIELD(this_obj, void **, 0xD0);
        temp_r21 = (u8 *)M2C_FIELD(this_obj, void *, 0xCC) + var_r14;
        t7 = ((void *(*)(void *, s32))temp_r3_7[6])(temp_r3_7, var_r19);
        temp_r3_8 = (void *)fn_8001668C((s32)t7, 0);
        M2C_FIELD(temp_r21, void *, 8) = temp_r3_8;
        if (M2C_FIELD(temp_r3_8, s32, 4) == *v_arg3) { var_r23_2 = var_r19; }
        temp_r3_9 = M2C_FIELD(this_obj, void **, 0xD0);
        M2C_FIELD(temp_r21, u8, 0xC) = (u8)((s32 (*)(void *, s32))temp_r3_9[9])(temp_r3_9, var_r19);
        var_r17 = temp_r21; var_r22_2 = 0;
        do {
            temp_r3_10 = M2C_FIELD(this_obj, void **, 0xD0);
            var_r24 = ((void *(*)(void *, s32))temp_r3_10[6])(temp_r3_10, var_r19);
            if ((var_r22_2 == 1) && (M2C_FIELD(temp_r21, u8, 0xC) != 0)) {
                temp_r3_11 = fn_80016544((void *)M2C_FIELD(M2C_FIELD(temp_r21, void *, 8), s32, 8));
                if (M2C_FIELD(temp_r3_11, s32, 4) == *v_arg3) { var_r23_2 = var_r19; }
                var_r24 = (u8 *)temp_r3_11 + 0x2C;
            }
            temp_r26 = M2C_FIELD(this_obj, void *, 0xC8); var_r27 = 0; var_r28 = 0;
loop_43:
            if (var_r27 >= M2C_FIELD(temp_r26, s32, 4)) { var_r27 = -1; }
            else if (stricmp((char *)M2C_FIELD(temp_r26, void *, 0) + var_r28, (const char *)var_r24) == 0) { }
            else { var_r28 += 0x38; var_r27 += 1; goto loop_43; }
            *(s32 *)var_r17 = var_r27;
            if (var_r27 < 0) { fn_802E317C((void *)(base_4170 + 0x1B8), var_r24); }
            var_r22_2 += 1; var_r17 = (u8 *)var_r17 + 4;
        } while (var_r22_2 < 2);
        var_r17_2 = 0;
        if ((*(u8 *)((u8 *)((s32 *(*)(s32, s32))fn_80016BC8)((s32)M2C_FIELD(temp_r21, void *, 8), 0) + 8) != 0) && (M2C_FIELD(temp_r21, u8, 0xC) != 0)) { var_r17_2 = 1; }
        temp_r3_12 = (u8 *)M2C_FIELD(this_obj, void *, 0x18) + var_r16;
        if (var_r17_2 != M2C_FIELD(temp_r3_12, s32, 4)) {
            M2C_FIELD(temp_r3_12, s32, 4) = var_r17_2;
            M2C_FIELD(temp_r3_12, f32, 8) = (f32) __fabs(M2C_FIELD(temp_r3_12, f32, 8));
        }
        M2C_FIELD(temp_r3_12, s32, 0) = var_r17_2;
        var_r14 += 0x14; var_r16 += 0xC;
        M2C_FIELD(temp_r3_12, f32, 8) = temp_f31;
        var_r19 += 1;
        M2C_FIELD(temp_r21, s32, 0x10) = 0;
        goto loop_54;
    }
    fn_80131818(temp_r18);
    temp_r3_13 = M2C_FIELD(this_obj, void **, 0xD0);
    M2C_FIELD(this_obj, s32, 0x2C) = var_r23_2;
    M2C_FIELD(this_obj, f32, 0x28) = (f32) var_r23_2;
    var_r16_2 = ((void *(*)(void *, s32))temp_r3_13[6])(temp_r3_13, var_r23_2);
    fn_8001668C((s32)var_r16_2, 0);
    temp_r14 = var_r16_2;
    if (*(u8 *)((u8 *)((s32 *(*)(s32, s32))fn_80016BC8)((s32)var_r16_2, 0) + 8) != 0) {
        temp_r3_14 = M2C_FIELD(this_obj, void **, 0xD0);
        if (((s32 (*)(void *, s32))temp_r3_14[9])(temp_r3_14, var_r23_2) != 0) {
            temp_r3_15 = M2C_FIELD(this_obj, void **, 0xD0);
            var_r16_2 = ((void *(*)(void *, s32))temp_r3_15[8])(temp_r3_15, var_r23_2);
        }
    }
    temp_r3_16 = (void *)fn_8001668C((s32)var_r16_2, 0);
    var_r4_3 = (u8 *)temp_r3_16 + 0x2C;
    var_r6_3 = (u8 *)this_obj + 0x60;
    var_r5_4 = 0x20;
loop_61:
    temp_r3_17 = *var_r4_3; var_r4_3 += 1; *var_r6_3 = temp_r3_17; var_r6_3 += 1;
    if ((s8) temp_r3_17 != 0) {
        var_r5_4 -= 1;
        if (var_r5_4 <= 0) { *(s8 *)(var_r6_3 - 1) = 0; } else { goto loop_61; }
    }
    temp_r3_18 = M2C_FIELD(this_obj, void **, 0xD0);
    if (((s32 (*)(void *, s32))temp_r3_18[9])(temp_r3_18, var_r23_2) != 0) {
        fn_801345D8((u8 *)this_obj + 0x80, 0x40, (void *)(base_4170 + 0x174), (u8 *)temp_r3_16 + 0xD);
    } else {
        var_r4_4 = (u8 *)temp_r3_16 + 0xC; var_r6_4 = (u8 *)this_obj + 0x80; var_r5_5 = 0x40;
loop_67:
        temp_r3_19 = *var_r4_4; var_r4_4 += 1; *var_r6_4 = temp_r3_19; var_r6_4 += 1;
        if ((s8) temp_r3_19 != 0) {
            var_r5_5 -= 1;
            if (var_r5_5 <= 0) { *(s8 *)(var_r6_4 - 1) = 0; } else { goto loop_67; }
        }
    }
    temp_r3_20 = M2C_FIELD(this_obj, void **, 0xD0);
    var_r0 = -1;
    if (((s32 (*)(void *, s32))temp_r3_20[9])(temp_r3_20, var_r23_2) != 0) { var_r0 = 5; }
    M2C_FIELD(this_obj, s32, 0xC4) = var_r0;
    *v_arg3 = M2C_FIELD(temp_r3_16, s32, 4);
    *v_arg2 = M2C_FIELD(temp_r3_16, s32, 0x9C);
    temp_r16 = v_arg4;
    temp_r3_21 = fn_80018A8C((u8 *)temp_r3_16 + 0x2C, v_arg2);
    if (temp_r3_21 != 0) {
        var_r18 = temp_r16; var_r20 = temp_r16;
        M2C_FIELD(temp_r16, s32, 0) = M2C_FIELD(temp_r3_21, s32, 0);
        var_r19_2 = (u8 *)temp_r16 + 0xF4; var_r21 = (u8 *)temp_r16 + 8;
        var_r22_3 = (u8 *)temp_r16 + 0x2C; var_r17_3 = 0;
        M2C_FIELD(temp_r16, s32, 4) = M2C_FIELD(temp_r3_21, s32, 4);
        M2C_FIELD(temp_r16, s32, 8) = M2C_FIELD(temp_r3_21, s32, 8);
        memcpy(temp_r16, temp_r3_21, 0x20);
        do {
            var_r6_5 = M2C_FIELD(var_r18, u8 *, 4);
            if (var_r6_5 != 0) {
                var_r5_6 = var_r19_2; var_r4_5 = 0x64;
loop_76:
                temp_r3_22 = *var_r6_5; var_r6_5 += 1; *var_r5_6 = temp_r3_22; var_r5_6 += 1;
                if ((s8) temp_r3_22 == 0) { }
                else {
                    var_r4_5 -= 1;
                    if (var_r4_5 <= 0) { *(s8 *)(var_r5_6 - 1) = 0; } else { goto loop_76; }
                }
            } else { *(s8 *)((u8 *)var_r20 + 0xF4) = 0; }
            ((void (*)(void *, s32, void *, void *))(*(void ***)var_r22_3)[0x18])(var_r22_3, var_r17_3, var_r21, (u8 *)temp_r16 + 0x2E8);
            var_r17_3 += 1; var_r18 = (u8 *)var_r18 + 8; var_r19_2 += 0x64;
            var_r20 = (u8 *)var_r20 + 0x64; var_r21 = (u8 *)var_r21 + 8; var_r22_3 = (u8 *)var_r22_3 + 0x28;
        } while (var_r17_3 < 5);
    } else {
        memset(temp_r16, 0, 0x2C);
        *(s8 *)((u8 *)temp_r16 + 0xF4) = 0;
        *(s8 *)((u8 *)temp_r16 + 0x158) = 0;
        *(s8 *)((u8 *)temp_r16 + 0x1BC) = 0;
        *(s8 *)((u8 *)temp_r16 + 0x220) = 0;
        *(s8 *)((u8 *)temp_r16 + 0x284) = 0;
    }
    temp_r3_23 = M2C_FIELD(this_obj, void **, 0xD0);
    *(s8 *)((u8 *)v_arg5 + 0xDD) = (s8)(((s32 (*)(void *, s32))temp_r3_23[7])(temp_r3_23, var_r23_2) == 0);
    sp8 = -1; spC = -1;
    if (fn_80019258(temp_r14, &sp8, &spC) == 0) { spC = -1; sp8 = -1; }
    temp_r3_24 = M2C_FIELD(this_obj, void **, 0xD0);
    if ((((s32 (*)(void *, s32))temp_r3_24[9])(temp_r3_24, var_r23_2) == 0) && (sp8 >= 0) && (spC >= 0)) {
        fn_801345D8((u8 *)this_obj + 0x3C, 0x10, &lbl_8055C0C0, fn_8001EFC0(0, (u8 *)this_obj + 0x60), sp8);
        fn_801345D8((u8 *)this_obj + 0x50, 0x10, &lbl_8055C0C0, fn_8001EFC0(1, (u8 *)this_obj + 0x60), spC);
    } else {
        fn_80130FCC((u8 *)this_obj + 0x3C, 0x10, fn_8001EFC0(0, (u8 *)this_obj + 0x60));
        fn_80130FCC((u8 *)this_obj + 0x50, 0x10, fn_8001EFC0(1, (u8 *)this_obj + 0x60));
    }
    temp_r14_2 = (void *)fn_8001668C((s32)((u8 *)this_obj + 0x60), 0);
    fn_8001668C((s32)((u8 *)this_obj + 0x60), 0);
    if (lbl_80498C48[4] != 0) { var_r5_7 = *(s32 *)((s32 *(*)(s32, s32))fn_80016BC8)(0, 0); }
    else { var_r5_7 = ((s32 *)((s32 *(*)(s32, s32))fn_80016BC8)(0, 0))[1]; }
    var_r4_6 = *(s32 *)((u8 *)M2C_FIELD(this_obj, void *, 0xCC) + (M2C_FIELD(this_obj, s32, 0x2C) * 0x14) + 0x10);
    if (var_r4_6 == 0) { var_r4_6 = *(s32 *)((u8 *)temp_r14_2 + (var_r5_7 * 4) + 0x64); }
    fn_80255918(v_arg5, var_r4_6);
    M2C_FIELD(this_obj, s32, 0xC0) = 1;
    return this_obj;
}
#pragma pop
typedef unsigned int u32;
extern unsigned char lbl_8034453C[];
extern s32 fn_80128670(s32);
extern s32 fn_80235380(s32);
extern s32 fn_802CAC54(s32);
extern s32 fn_80128668(void *);
void *fn_8024FB64(void *this_, s32 shouldFree) {
    /* Destructor-like cleanup: reset vtable, release owned resources, optionally free storage. */
    if (this_ != 0) {
        *(void **)this_ = lbl_8034453C;
        fn_80128670(*(s32 *)((u8 *)this_ + 0x18));
        fn_80235380(*(s32 *)((u8 *)this_ + 0x24));
        fn_802CAC54(*(s32 *)((u8 *)this_ + 0x20));
        if (shouldFree > 0) fn_80128668(this_);
    }
    return this_;
}

#pragma cplusplus on
extern "C" void fn_8024FBD8(void *arg0, s32 arg1) {
    class Obj {
    public:
        virtual void destroy(int);
        virtual void m1(); virtual void m2();
        virtual int count(void * = 0, void * = 0, int = 0);
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(); virtual void m13();
        virtual void configure(void *, float);
    };
    extern void fn_8013C804(void);
    extern void fn_8001880C(void);
    extern void fn_802556BC(void *, s32);
    extern s32 fn_802E4A10(void);
    extern void fn_8002F53C(void *, void *, void *, s32, s32);
    extern void __array_delete(void *, void *, s32, s32);
    extern void fn_80018B24(void);
    extern void fn_8013C8B8(void);
    extern s32 fn_802146BC(s32 *, s32, s32, s32);
    extern void fn_80255758(void *, s32);
    extern void *fn_80258354(void);
    extern unsigned char lbl_80344170[];
    extern char lbl_803443B0[];
    extern unsigned char lbl_803446AC[];
    extern unsigned char lbl_803446B8[];
    extern unsigned char lbl_803446C8[];
    extern unsigned char lbl_80498C30[];
    extern unsigned char lbl_802FA594[];
    extern unsigned char lbl_8055C0D8;
    extern const f32 lbl_80563964;
    extern s32 MRollStatLabel_init(void);
    extern s32 fn_80240928(void);
    class Counter { public: virtual void d(int); virtual void a(); virtual void b(); virtual int count(); };
    u8 stack[0x728];
    u8 *base = lbl_80344170;
    s32 i, count;
    void *object;
    fn_8013C804();
    fn_8001880C();
    fn_802556BC(stack+0x320, 1);
    *(s32 *)(stack+0x3f8) = fn_802E4A10();
    fn_8002F53C(stack+0x470, MRollStatLabel_init, fn_80240928, 0x28, 5);
    memset(stack+0x444, 0, 0x2c);
    *(void * volatile *)(stack+0x198) = arg0;
    *(volatile u8 *)(stack+0x538) = 0;
    *(volatile u8 *)(stack+0x59c) = 0;
    *(volatile u8 *)(stack+0x600) = 0;
    *(volatile u8 *)(stack+0x664) = 0;
    *(volatile u8 *)(stack+0x6c8) = 0;
    *(s32 *)(stack+0x194) = 0;
    *(void **)(stack+0x180) = lbl_803443B0;
    *(void **)(stack+0x1a0) = stack+0x320;
    *(void **)(stack+0x1a4) = stack+0x444;
    *(s32 *)(stack+0x19c) = 0;
    if (arg1 != 0) *(s32 *)(stack+0x19c) = arg1;
    *(volatile u8 *)(stack+0x1a8) = 0;
    *(volatile u8 *)(stack+0x1c8) = 0;
    *(volatile u8 *)(stack+0x208) = 0;
    *(volatile u8 *)(stack+0x288) = 0;
    *(void **)(stack+0x308) = fn_80258354();
    object = *(void **)(stack+0x308);
    if (object != 0) {
        ((Obj *)object)->count(lbl_803446C8, lbl_803446B8, 0);
        object = *(void **)(stack+0x308);
        ((Obj *)object)->configure(lbl_803446AC, lbl_80563964);
    }
*(void * *)(stack+0x20)=stack+0x180;
    *(s32 *)(stack+0x18)=0;
*(s32 *)(stack+0x24)=0;
*(void * *)(stack+0x34)=stack+0x288;
*(s32 *)(stack+0x1c)=5;
*(s32 *)(stack+0x28)=0;
*(s32 *)(stack+0x30)=3;
*(s32 *)(stack+0x38)=0;
*(s32 *)(stack+0x3c)=0;
*(void * *)(stack+0x2c)=&lbl_8055C0D8;
*(s32 *)(stack+0x44)=0x13;
    void *descriptor = base + 0x40;
    *(void **)(stack+0x40) = descriptor;
*(void * *)(stack+0x48)=stack+0x320;
*(s32 *)(stack+0x4c)=0;
*(s32 *)(stack+0x50)=0;
*(s32 *)(stack+0x58)=3;
    *(void **)(stack+0x54) = descriptor;
*(void * *)(stack+0x5c)=stack+0x1a8;
*(s32 *)(stack+0x60)=0;
*(s32 *)(stack+0x64)=0;
*(void * *)(stack+0x6c)=base+0x58;
*(s32 *)(stack+0x68)=5;
*(void * *)(stack+0x70)=stack+0x41c;
*(s32 *)(stack+0x74)=0;
*(s32 *)(stack+0x78)=0;
*(s32 *)(stack+0x80)=3;
*(void * *)(stack+0x7c)=base+0x1f0;
*(void * *)(stack+0x84)=stack+0x208;
*(s32 *)(stack+0x88)=0;
*(s32 *)(stack+0x8c)=0;
*(s32 *)(stack+0x94)=3;
*(void * *)(stack+0x90)=base+0x1fc;
*(void * *)(stack+0x98)=stack+0x1c8;
*(s32 *)(stack+0x9c)=0;
*(s32 *)(stack+0xa0)=0;
*(s32 *)(stack+0xa8)=3;
*(void * *)(stack+0xa4)=base+0x68;
*(void * *)(stack+0xac)=stack+0x538;
*(s32 *)(stack+0xb0)=0;
*(s32 *)(stack+0xb4)=0;
*(s32 *)(stack+0xbc)=2;
*(void * *)(stack+0xb8)=base+0x78;
*(void * *)(stack+0xc0)=stack+0x44c;
*(s32 *)(stack+0xc4)=0;
*(s32 *)(stack+0xc8)=0;
*(s32 *)(stack+0xd0)=3;
*(s32 *)(stack+0xd8)=0;
*(s32 *)(stack+0xdc)=0;
*(volatile s32 *)(stack+0xec)=0;
*(volatile s32 *)(stack+0xf0)=0;
*(volatile s32 *)(stack+0x100)=0;
*(volatile s32 *)(stack+0x104)=0;
*(volatile s32 *)(stack+0x114)=0;
*(volatile s32 *)(stack+0x118)=0;
*(volatile s32 *)(stack+0x128)=0;
*(volatile s32 *)(stack+0x12c)=0;
*(volatile s32 *)(stack+0x13c)=0;
*(volatile s32 *)(stack+0x140)=0;
*(volatile s32 *)(stack+0x150)=0;
*(volatile s32 *)(stack+0x154)=0;
*(volatile s32 *)(stack+0x164)=0;
*(volatile s32 *)(stack+0x168)=0;
*(void * *)(stack+0xcc)=base+0x84;
*(void * *)(stack+0xd4)=stack+0x59c;
*(s32 *)(stack+0xe4)=2;
*(void * *)(stack+0xe0)=base+0x94;
*(void * *)(stack+0xe8)=stack+0x454;
*(s32 *)(stack+0xf8)=3;
*(void * *)(stack+0xf4)=base+0xa0;
*(void * *)(stack+0xfc)=stack+0x600;
*(s32 *)(stack+0x10c)=2;
*(void * *)(stack+0x108)=base+0xb0;
*(void * *)(stack+0x110)=stack+0x45c;
*(s32 *)(stack+0x120)=3;
*(void * *)(stack+0x11c)=base+0xbc;
*(void * *)(stack+0x124)=stack+0x664;
*(s32 *)(stack+0x134)=5;
*(void * *)(stack+0x130)=base+0xcc;
*(void * *)(stack+0x138)=stack+0x4e8;
*(s32 *)(stack+0x148)=3;
*(void * *)(stack+0x144)=base+0xdc;
*(void * *)(stack+0x14c)=stack+0x6c8;
*(s32 *)(stack+0x15c)=2;
*(void * *)(stack+0x158)=base+0xec;
*(void * *)(stack+0x160)=stack+0x46c;
    *(s32 *)(stack+0x16c) = *(s32 *)lbl_80498C30;
    *(s32 *)(stack+0x170) = *(s32 *)(lbl_80498C30+4);
    *(s32 *)(stack+0x174) = *(s32 *)(lbl_80498C30+8);
    *(s32 *)(stack+0x178) = *(s32 *)(lbl_80498C30+0xc);
    *(s32 *)(stack+0x17c) = *(s32 *)(lbl_80498C30+0x10);
    *(s32 *)(stack+0x0) = *(s32 *)lbl_802FA594;
    *(s32 *)(stack+0x8) = *(s32 *)(lbl_802FA594+8);
    *(s32 *)(stack+0xc) = *(s32 *)(lbl_802FA594+0xc);
    *(s32 *)(stack+0x10) = *(s32 *)(lbl_802FA594+0x10);
    *(void **)(stack+0x4) = stack+0x18;
    i=0;
    while (i < ((Counter *)arg0)->count()) {
        *(s32 *)(stack+0x30c)=i;
        fn_802146BC((s32 *)stack, -0x3e7, -0x3e7, 1);
        ++i;
    }
    fn_80018B24();
    fn_8013C8B8();
    *(void **)(stack+0x180)=lbl_803443B0;
    object = *(void **)(stack+0x308);
    if (object != 0) {
        if (object != 0)
            ((Obj *)object)->destroy(1);
    }
    __array_delete(stack+0x470, fn_80240928, 0x28, 5);
    fn_80255758(stack+0x320, -1);
}
#pragma cplusplus reset
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_8024FFF8(void *object, s32 deleteFlag) {
    /* Destroy the owned object at +0x188, reset this object's vtable to lbl_803443B0,
     * and optionally free this object. */
    extern char lbl_803443B0[];
    class Entry {
    public:
        virtual void destroy(s32);
    };
    void *owned;

    if (object != 0) {
        owned = *(void **)((u8 *)object + 0x188);
        *(void **)object = (void *)lbl_803443B0;
        if (owned != 0) {
            if (owned != 0)
                ((Entry *)owned)->destroy(1);
        }
        if (deleteFlag > 0)
            ((s32 (*)(void *))fn_80128668)(object);
    }
    return object;
}
#pragma pop

#pragma push
#pragma small_data on
void *fn_8025007C(s32 count) {
    void *list;
    void *elements;
    /* Allocate and initialize a chassis list: object storage, per-chassis entries, and event path subobject. */
    list = fn_801284F8(0x20, lbl_80344378);
    if (list != 0) {
        *(void **)list = lbl_80344384;
        elements = fn_8012850C(count * 0x48, &lbl_8055C0E0);
        *(void **)((u8 *)list + 4) = elements;
        *(s32 *)((u8 *)list + 0xC) = count;
        *(s32 *)((u8 *)list + 8) = 0;
        *(void **)((u8 *)list + 0x10) = elements;
        fn_801312EC((u8 *)list + 0x14, lbl_80344690);
    }
    return list;
}
#pragma pop
void fn_80250108(void *arg0) {
    extern f32 fn_80214D48(void);
    extern const f32 lbl_80563964, lbl_80563968, lbl_8056396C, lbl_80563970;
    f32 limit, speed, subtract, threshold;
    f32 dt = fn_80214D48();
    s32 offset;
    s32 i;
    f32 current;
    f32 coef;
    i = 0;
    offset = 0;
    speed = lbl_8056396C;
    limit = 0.0f;
    coef = lbl_80563968;
    current = *(f32 *)((u8 *)arg0 + 0x28);
    *(f32 *)((u8 *)arg0 + 0x28) = current + coef * ((f32)*(s32 *)((u8 *)arg0 + 0x2C) - current);
    subtract = lbl_80563970;
    threshold = lbl_80563964;
    for (; i < *(s32 *)((u8 *)arg0 + 0x1C); offset += 12, i++) {
        u8 *entry = *(u8 **)((u8 *)arg0 + 0x18) + offset;
        if (*(s32 *)(entry + 4) != *(s32 *)entry) {
            *(f32 *)(entry + 8) += speed * dt;
            if (*(f32 *)(entry + 8) >= threshold) {
                *(s32 *)entry = *(s32 *)(entry + 4);
                *(f32 *)(entry + 8) -= subtract;
            }
        } else {
            f32 value = *(f32 *)(entry + 8) + speed * dt;
            if (limit < value) value = limit;
            *(f32 *)(entry + 8) = value;
        }
    }
}

extern double fn_8002EFB4(double, double);
extern double fabs(double);
extern double lbl_80563978;
__declspec(section ".data") extern f32 lbl_80558DC4;
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" s32 fn_80250204(void *arg0, s32 arg1, M2C_UNK arg_sp0) {
    typedef signed char s8;
    extern f32 lbl_80558DC4;
    extern void fn_80216D28(void);
    extern s32 fn_80214D50(s32);
    class Selector { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void *get0(s32); virtual s32 get1(s32); virtual void *get2(s32); virtual s32 get3(s32); };
    class Table { public: virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3(); virtual void t4(); virtual void t5(); virtual void t6(); virtual void t7(); virtual void t8(); virtual void t9(); virtual void t10(); virtual void t11(); virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15(); virtual void t16(); virtual void t17(); virtual void t18(); virtual void t19(); virtual void t20(); virtual void t21(); virtual void fill(s32, void *, void *); };
    s32 temp_r3_end, compare_result, sp1C, sp18, sp14, sp10, spC, sp8, temp_r22, temp_r27, temp_r27_2, temp_r27_3, var_r0, var_r0_2, var_r0_3, var_r28, var_r29, var_r29_2, var_r4_11, var_r4_12, var_r4_3, var_r4_4, var_r4_7, var_r4_8, var_r5, var_r5_2, var_r5_4, var_r5_5, var_r5_6, var_r5_8, var_r5_9, var_r5_10, var_r5_12;
    f32 abs_value, remainder;
    register s32 copy_a, copy_b;
    u8 temp_r23_2, temp_r3_5, temp_r3_7, temp_r3_10, temp_r3_17, temp_r3_19, temp_r3_22, temp_r3_30, temp_r3_32, temp_r3_35, var_r3;
    u8 *var_r23, *var_r23_2, *var_r25_3, *var_r5_3, *var_r5_7, *var_r5_11, *var_r22_3, *var_r26, *var_r26_2, *temp_r21_2, *temp_r21_3, *temp_r22_2, *temp_r23, *temp_r28, *temp_r28_2, *temp_r29, *temp_r30, *temp_r30_2, *temp_r30_3, *temp_r3_4, *temp_r3_9, *temp_r3_16, *temp_r3_21, *temp_r3_25, *temp_r3_29, *temp_r3_34, *var_r21, *var_r21_2, *var_r21_3, *var_r22, *var_r22_2, *var_r23_3, *var_r24, *var_r24_2, *var_r24_3, *var_r25, *var_r25_2, *var_r26_3;
    volatile u8 *var_r4, *var_r4_2, *var_r4_5, *var_r4_6, *var_r4_9, *var_r4_10, *var_r6, *var_r6_2, *var_r6_3, *var_r6_4, *var_r6_5, *var_r6_6, *var_r6_7, *var_r6_8, *var_r6_9;
    s32 *temp_r21, *temp_r4, *temp_r4_2, *temp_r4_3;
    void **temp_r3, **temp_r3_2, **temp_r3_3, **temp_r3_6, **temp_r3_8, **temp_r3_11, **temp_r3_12, **temp_r3_13, **temp_r3_14, **temp_r3_15, **temp_r3_18, **temp_r3_20, **temp_r3_23, **temp_r3_24, **temp_r3_26, **temp_r3_27, **temp_r3_28, **temp_r3_31, **temp_r3_33, **temp_r3_36, **temp_r3_37;

    temp_r22 = M2C_FIELD(arg0, s32, 0x2C);
    temp_r23 = (u8 *)M2C_FIELD(arg0, s32 *, 0xCC) + (temp_r22 * 0x14);
    temp_r21 = ((s32 *(*)(s32, s32))fn_80016BC8)(M2C_FIELD(temp_r23, s32, 8), 0);
    switch (arg1) {
    case 0x125:
        if (temp_r22 > 0) {
            temp_r27 = temp_r22 - 1;
            temp_r3 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(arg0, s32, 0x2C) = temp_r27;
            var_r21 = (u8*)((Selector*)temp_r3)->get0(temp_r27);
            temp_r3_4 = (u8 *)fn_8001668C((s32)var_r21, 0);
            temp_r30 = var_r21;
            if ((s32) M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)((s32)temp_r3_4, 0), u8, 8) != 0) {
                temp_r3_2 = M2C_FIELD(arg0, void **, 0xD0);
                if (((Selector*)temp_r3_2)->get3(temp_r27) != 0) { temp_r3_3 = M2C_FIELD(arg0, void **, 0xD0); var_r21 = (u8*)((Selector*)temp_r3_3)->get2(temp_r27); }
            }
            temp_r3_4 = (u8*)fn_8001668C((s32)var_r21, 0);
            var_r4 = temp_r3_4 + 0x2C; var_r6 = ((u8*)arg0 + 0x60); var_r5 = 0x20;
            goto copy_125_a_body;
copy_125_a_count: var_r5 -= 1; if (var_r5 > 0) goto copy_125_a_body; M2C_FIELD(var_r6, s8, -1) = 0; goto copy_125_a_end;
copy_125_a_body: temp_r3_5 = *var_r4++; *var_r6++ = temp_r3_5; if ((s8)temp_r3_5 != 0) goto copy_125_a_count;
copy_125_a_end: ;
            temp_r3_6 = M2C_FIELD(arg0, void **, 0xD0);
            if (((Selector*)temp_r3_6)->get3(temp_r27) != 0) fn_801345D8(((u8*)arg0 + 0x80), 0x40, &lbl_803442E4, temp_r3_4 + 0xD);
            else { var_r4_2 = temp_r3_4 + 0xC; var_r6_2 = ((u8*)arg0 + 0x80); var_r5_2 = 0x40; goto copy_125_b_body;
copy_125_b_count: var_r5_2 -= 1; if (var_r5_2 > 0) goto copy_125_b_body; M2C_FIELD(var_r6_2, s8, -1) = 0; goto copy_125_b_end;
copy_125_b_body: temp_r3_7 = *var_r4_2++; *var_r6_2++ = temp_r3_7; if ((s8)temp_r3_7 != 0) goto copy_125_b_count;
copy_125_b_end: ; }
            temp_r3_8 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(arg0, s32, 0xC4) = (((Selector*)temp_r3_8)->get3(temp_r27) != 0) ? 5 : -1;
            *M2C_FIELD(arg0, s32 **, 0x34) = M2C_FIELD(temp_r3_4, s32 *, 4);
            temp_r4 = M2C_FIELD(arg0, s32 *, 0x30); *temp_r4 = M2C_FIELD(temp_r3_4, s32, 0x9C);
            temp_r29 = (u8 *)M2C_FIELD(arg0, void *, 0x38);
            temp_r3_9 = (u8 *)fn_80018A8C(temp_r3_4 + 0x2C, temp_r4);
            if (temp_r3_9 != 0) {
                M2C_FIELD(temp_r29, s32, 0) = M2C_FIELD(temp_r3_9, s32, 0);
                var_r22 = temp_r29; var_r24 = temp_r29; var_r23 = temp_r29 + 0xF4; var_r25 = temp_r29 + 8;
                copy_b = M2C_FIELD(temp_r3_9, s32, 4); var_r26 = temp_r29 + 0x2C; copy_a = M2C_FIELD(temp_r3_9, s32, 8); var_r28 = 0;
                M2C_FIELD(temp_r29, s32, 4) = copy_b; M2C_FIELD(temp_r29, s32, 8) = copy_a;
                copy_a = M2C_FIELD(temp_r3_9, s32, 0xC); copy_b = M2C_FIELD(temp_r3_9, s32, 0x10); M2C_FIELD(temp_r29, s32, 0xC) = copy_a; M2C_FIELD(temp_r29, s32, 0x10) = copy_b;
                copy_a = M2C_FIELD(temp_r3_9, s32, 0x14); copy_b = M2C_FIELD(temp_r3_9, s32, 0x18); M2C_FIELD(temp_r29, s32, 0x14) = copy_a; M2C_FIELD(temp_r29, s32, 0x18) = copy_b;
                copy_a = M2C_FIELD(temp_r3_9, s32, 0x1C); copy_b = M2C_FIELD(temp_r3_9, s32, 0x20); M2C_FIELD(temp_r29, s32, 0x1C) = copy_a; M2C_FIELD(temp_r29, s32, 0x20) = copy_b;
                M2C_FIELD(temp_r29, s32, 0x28) = M2C_FIELD(temp_r3_9, s32, 0x28); M2C_FIELD(temp_r29, s32, 0x24) = M2C_FIELD(temp_r3_9, s32, 0x24);
                do {
                    var_r6_3 = M2C_FIELD(var_r22, u8 *, 4);
                    if (var_r6_3 != 0) { var_r5_3 = var_r23; var_r4_3 = 0x64; goto copy_c125_body;
copy_c125_count: var_r4_3 -= 1; if (var_r4_3 > 0) goto copy_c125_body; M2C_FIELD(var_r5_3, s8, -1) = 0; goto copy_c125_end;
copy_c125_body: temp_r3_10 = *var_r6_3++; *var_r5_3++ = temp_r3_10; if ((s8)temp_r3_10 != 0) goto copy_c125_count; goto copy_c125_end;
copy_c125_end: ; } else M2C_FIELD(var_r24, s8, 0xF4) = 0;
                    ((Table *)var_r26)->fill(var_r28, var_r25, temp_r29 + 0x2E8);
                    var_r22 += 8; var_r23 += 0x64; var_r24 += 0x64; var_r25 += 8; var_r26 += 0x28; var_r28 += 1;
                    if (var_r28 < 5) goto copy_c125_continue;
                    break;
copy_c125_continue: ; } while (1);
            } else {
                memset(temp_r29, 0, 0x2C); M2C_FIELD(temp_r29, s8, 0xF4) = 0; M2C_FIELD(temp_r29, s8, 0x158) = 0; M2C_FIELD(temp_r29, s8, 0x1BC) = 0; M2C_FIELD(temp_r29, s8, 0x220) = 0; M2C_FIELD(temp_r29, s8, 0x284) = 0;
            }
            temp_r3_11 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8, 0xDD) = (s8) (((Selector*)temp_r3_11)->get1(temp_r27) == 0);
            sp18 = -1; sp1C = -1;
            if (fn_80019258(temp_r30, &sp18, &sp1C) == 0) { sp1C = -1; sp18 = -1; }
            temp_r3_12 = M2C_FIELD(arg0, void **, 0xD0);
            if ((((Selector*)temp_r3_12)->get3(temp_r27) == 0) && (sp18 >= 0) && (sp1C >= 0)) {
                fn_801345D8(((u8*)arg0 + 0x3C), 0x10, &lbl_8055C0C0, fn_8001EFC0(0, ((u8*)arg0 + 0x60)), sp18);
                fn_801345D8(((u8*)arg0 + 0x50), 0x10, &lbl_8055C0C0, fn_8001EFC0(1, ((u8*)arg0 + 0x60)), sp1C);
            } else {
                fn_80130FCC(((u8*)arg0 + 0x3C), 0x10, fn_8001EFC0(0, ((u8*)arg0 + 0x60)));
                fn_80130FCC(((u8*)arg0 + 0x50), 0x10, fn_8001EFC0(1, ((u8*)arg0 + 0x60)));
            }
            temp_r21_2 = (u8*)fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0); temp_r3_end = fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
            if ((s32) M2C_FIELD(&lbl_80498C48, u8, 4) != 0) var_r5_4 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 0);
            else var_r5_4 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 4);
            var_r4_4 = M2C_FIELD(((u8 *)M2C_FIELD(arg0, s32 *, 0xCC) + (M2C_FIELD(arg0, s32, 0x2C) * 0x14)), s32, 0x10);
            if (var_r4_4 == 0) var_r4_4 = M2C_FIELD((temp_r21_2 + (var_r5_4 * 4)), s32, 0x64);
            fn_80255918(M2C_FIELD(arg0, void **, 0x4C), var_r4_4);
        } else { fn_80216D28(); fn_80214D50(1); }
        return 1;
    case 0x127:
        temp_r27_2 = temp_r22 + 1;
        if (temp_r27_2 < (s32) M2C_FIELD(arg0, s32 *, 0x1C)) {
            M2C_FIELD(arg0, s32, 0x2C) = temp_r27_2;
            temp_r3_13 = M2C_FIELD(arg0, void **, 0xD0);
            var_r21_2 = (u8*)((Selector*)temp_r3_13)->get0(temp_r27_2);
            temp_r3_16 = (u8 *)fn_8001668C((s32)var_r21_2, 0); temp_r30_2 = var_r21_2;
            if ((s32) M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)((s32)temp_r3_16, 0), u8, 8) != 0) {
                temp_r3_14 = M2C_FIELD(arg0, void **, 0xD0);
                if (((Selector*)temp_r3_14)->get3(temp_r27_2) != 0) { temp_r3_15 = M2C_FIELD(arg0, void **, 0xD0); var_r21_2 = (u8*)((Selector*)temp_r3_15)->get2(temp_r27_2); }
            }
            temp_r3_16 = (u8*)fn_8001668C((s32)var_r21_2, 0);
            var_r4_5 = temp_r3_16 + 0x2C; var_r6_4 = ((u8*)arg0 + 0x60); var_r5_5 = 0x20;
            goto copy_127_a_body;
copy_127_a_count: var_r5_5 -= 1; if (var_r5_5 > 0) goto copy_127_a_body; M2C_FIELD(var_r6_4, s8, -1) = 0; goto copy_127_a_end;
copy_127_a_body: temp_r3_17 = *var_r4_5++; *var_r6_4++ = temp_r3_17; if ((s8)temp_r3_17 != 0) goto copy_127_a_count;
copy_127_a_end: ;
            temp_r3_18 = M2C_FIELD(arg0, void **, 0xD0);
            if (((Selector*)temp_r3_18)->get3(temp_r27_2) != 0) fn_801345D8(((u8*)arg0 + 0x80), 0x40, &lbl_803442E4, temp_r3_16 + 0xD);
            else { var_r4_6 = temp_r3_16 + 0xC; var_r6_5 = ((u8*)arg0 + 0x80); var_r5_6 = 0x40; goto copy_127_b_body;
copy_127_b_count: var_r5_6 -= 1; if (var_r5_6 > 0) goto copy_127_b_body; M2C_FIELD(var_r6_5, s8, -1) = 0; goto copy_127_b_end;
copy_127_b_body: temp_r3_19 = *var_r4_6++; *var_r6_5++ = temp_r3_19; if ((s8)temp_r3_19 != 0) goto copy_127_b_count;
copy_127_b_end: ; }
            temp_r3_20 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(arg0, s32, 0xC4) = (((Selector*)temp_r3_20)->get3(temp_r27_2) != 0) ? 5 : -1;
            *M2C_FIELD(arg0, s32 **, 0x34) = M2C_FIELD(temp_r3_16, s32 *, 4);
            temp_r4_2 = M2C_FIELD(arg0, s32 *, 0x30); *temp_r4_2 = M2C_FIELD(temp_r3_16, s32, 0x9C);
            temp_r28 = (u8 *)M2C_FIELD(arg0, void *, 0x38);
            temp_r3_21 = (u8 *)fn_80018A8C(temp_r3_16 + 0x2C, temp_r4_2);
            if (temp_r3_21 != 0) {
                M2C_FIELD(temp_r28, s32, 0) = M2C_FIELD(temp_r3_21, s32, 0);
                var_r22_2 = temp_r28; var_r24_2 = temp_r28; var_r23_2 = temp_r28 + 0xF4; var_r25_2 = temp_r28 + 8;
                copy_a = M2C_FIELD(temp_r3_21, s32, 4); var_r26_2 = temp_r28 + 0x2C; copy_b = M2C_FIELD(temp_r3_21, s32, 8); var_r29 = 0;
                M2C_FIELD(temp_r28, s32, 4) = copy_a; M2C_FIELD(temp_r28, s32, 8) = copy_b;
                copy_a = M2C_FIELD(temp_r3_21, s32, 0xC); copy_b = M2C_FIELD(temp_r3_21, s32, 0x10); M2C_FIELD(temp_r28, s32, 0xC) = copy_a; M2C_FIELD(temp_r28, s32, 0x10) = copy_b;
                copy_a = M2C_FIELD(temp_r3_21, s32, 0x14); copy_b = M2C_FIELD(temp_r3_21, s32, 0x18); M2C_FIELD(temp_r28, s32, 0x14) = copy_a; M2C_FIELD(temp_r28, s32, 0x18) = copy_b;
                M2C_FIELD(temp_r28, s32, 0x20) = M2C_FIELD(temp_r3_21, s32, 0x20); M2C_FIELD(temp_r28, s32, 0x1C) = M2C_FIELD(temp_r3_21, s32, 0x1C);
                copy_a = M2C_FIELD(temp_r3_21, s32, 0x24); copy_b = M2C_FIELD(temp_r3_21, s32, 0x28); M2C_FIELD(temp_r28, s32, 0x24) = copy_a; M2C_FIELD(temp_r28, s32, 0x28) = copy_b;
                do {
                    var_r6_6 = M2C_FIELD(var_r22_2, u8 *, 4);
                    if (var_r6_6 != 0) { var_r5_7 = var_r23_2; var_r4_7 = 0x64; goto copy_c127_body;
copy_c127_count: var_r4_7 -= 1; if (var_r4_7 > 0) goto copy_c127_body; M2C_FIELD(var_r5_7, s8, -1) = 0; goto copy_c127_end;
copy_c127_body: temp_r3_22 = *var_r6_6++; *var_r5_7++ = temp_r3_22; if ((s8)temp_r3_22 != 0) goto copy_c127_count; goto copy_c127_end;
copy_c127_end: ; } else M2C_FIELD(var_r24_2, s8, 0xF4) = 0;
                    ((Table *)var_r26_2)->fill(var_r29, var_r25_2, temp_r28 + 0x2E8);
                    var_r22_2 += 8; var_r23_2 += 0x64; var_r24_2 += 0x64; var_r25_2 += 8; var_r26_2 += 0x28; var_r29 += 1;
                    if (var_r29 < 5) goto copy_c127_continue;
                    break;
copy_c127_continue: ; } while (1);
            } else {
                memset(temp_r28, 0, 0x2C); M2C_FIELD(temp_r28, s8, 0xF4) = 0; M2C_FIELD(temp_r28, s8, 0x158) = 0; M2C_FIELD(temp_r28, s8, 0x1BC) = 0; M2C_FIELD(temp_r28, s8, 0x220) = 0; M2C_FIELD(temp_r28, s8, 0x284) = 0;
            }
            temp_r3_23 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8, 0xDD) = (s8) (((Selector*)temp_r3_23)->get1(temp_r27_2) == 0);
            sp10 = -1; sp14 = -1;
            if (fn_80019258(temp_r30_2, &sp10, &sp14) == 0) { sp14 = -1; sp10 = -1; }
            temp_r3_24 = M2C_FIELD(arg0, void **, 0xD0);
            if ((((Selector*)temp_r3_24)->get3(temp_r27_2) == 0) && (sp10 >= 0) && (sp14 >= 0)) {
                fn_801345D8(((u8*)arg0 + 0x3C), 0x10, &lbl_8055C0C0, fn_8001EFC0(0, ((u8*)arg0 + 0x60)), sp10);
                fn_801345D8(((u8*)arg0 + 0x50), 0x10, &lbl_8055C0C0, fn_8001EFC0(1, ((u8*)arg0 + 0x60)), sp14);
            } else {
                fn_80130FCC(((u8*)arg0 + 0x3C), 0x10, fn_8001EFC0(0, ((u8*)arg0 + 0x60)));
                fn_80130FCC(((u8*)arg0 + 0x50), 0x10, fn_8001EFC0(1, ((u8*)arg0 + 0x60)));
            }
            temp_r21_3 = (u8*)fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0); temp_r3_end = fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
            if ((s32) M2C_FIELD(&lbl_80498C48, u8, 4) != 0) var_r5_8 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 0);
            else var_r5_8 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 4);
            var_r4_8 = M2C_FIELD(((u8 *)M2C_FIELD(arg0, s32 *, 0xCC) + (M2C_FIELD(arg0, s32, 0x2C) * 0x14)), s32, 0x10);
            if (var_r4_8 == 0) var_r4_8 = M2C_FIELD((temp_r21_3 + (var_r5_8 * 4)), s32, 0x64);
            fn_80255918(M2C_FIELD(arg0, void **, 0x4C), var_r4_8);
        } else { fn_80216D28(); fn_80214D50(1); }
        return 1;
    case 0x126:
    case 0x128:
        temp_r23_2 = M2C_FIELD(temp_r23, u8, 0xC);
        if ((s32) temp_r23_2 != 0) {
            temp_r3_25 = (u8 *)M2C_FIELD(arg0, u8 *, 0x18) + (temp_r22 * 0xC);
            abs_value = __fabs(M2C_FIELD(temp_r3_25, f32, 8));
            remainder = fn_8002EFB4(abs_value, lbl_80563978);
            compare_result = __fabs(remainder) <= M2C_FIELD(&lbl_80558DC4, f32, 0);
            if (compare_result != 0) {
                var_r3 = 0;
                if (((s32) M2C_FIELD(temp_r21, u8, 8) == 0) && ((s32) temp_r23_2 != 0)) var_r3 = 1;
                M2C_FIELD(temp_r21, u8, 8) = var_r3;
                temp_r3_26 = M2C_FIELD(arg0, void **, 0xD0); temp_r27_3 = M2C_FIELD(arg0, s32, 0x2C);
                var_r21_3 = (u8*)((Selector*)temp_r3_26)->get0(temp_r27_3);
                temp_r3_29 = (u8 *)fn_8001668C((s32)var_r21_3, 0); temp_r30_3 = var_r21_3;
                if ((s32) M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)((s32)temp_r3_29, 0), u8, 8) != 0) {
                    temp_r3_27 = M2C_FIELD(arg0, void **, 0xD0);
                    if (((Selector*)temp_r3_27)->get3(temp_r27_3) != 0) { temp_r3_28 = M2C_FIELD(arg0, void **, 0xD0); var_r21_3 = (u8*)((Selector*)temp_r3_28)->get2(temp_r27_3); }
                }
                temp_r3_29 = (u8*)fn_8001668C((s32)var_r21_3, 0);
                var_r4_9 = temp_r3_29 + 0x2C; var_r6_7 = ((u8*)arg0 + 0x60); var_r5_9 = 0x20;
                goto copy_128_a_body;
copy_128_a_count: var_r5_9 -= 1; if (var_r5_9 > 0) goto copy_128_a_body; M2C_FIELD(var_r6_7, s8, -1) = 0; goto copy_128_a_end;
copy_128_a_body: temp_r3_30 = *var_r4_9++; *var_r6_7++ = temp_r3_30; if ((s8)temp_r3_30 != 0) goto copy_128_a_count;
copy_128_a_end: ;
                temp_r3_31 = M2C_FIELD(arg0, void **, 0xD0);
                if (((Selector*)temp_r3_31)->get3(temp_r27_3) != 0) fn_801345D8(((u8*)arg0 + 0x80), 0x40, &lbl_803442E4, temp_r3_29 + 0xD);
                else { var_r4_10 = temp_r3_29 + 0xC; var_r6_8 = ((u8*)arg0 + 0x80); var_r5_10 = 0x40; goto copy_128_b_body;
copy_128_b_count: var_r5_10 -= 1; if (var_r5_10 > 0) goto copy_128_b_body; M2C_FIELD(var_r6_8, s8, -1) = 0; goto copy_128_b_end;
copy_128_b_body: temp_r3_32 = *var_r4_10++; *var_r6_8++ = temp_r3_32; if ((s8)temp_r3_32 != 0) goto copy_128_b_count;
copy_128_b_end: ; }
                temp_r3_33 = M2C_FIELD(arg0, void **, 0xD0); var_r0_3 = -1;
                if (((Selector*)temp_r3_33)->get3(temp_r27_3) != 0) var_r0_3 = 5;
                M2C_FIELD(arg0, s32, 0xC4) = var_r0_3;
                *M2C_FIELD(arg0, s32 **, 0x34) = M2C_FIELD(temp_r3_29, s32 *, 4);
                temp_r4_3 = M2C_FIELD(arg0, s32 *, 0x30); *temp_r4_3 = M2C_FIELD(temp_r3_29, s32, 0x9C);
                temp_r28_2 = (u8 *)M2C_FIELD(arg0, void *, 0x38);
                temp_r3_34 = (u8 *)fn_80018A8C(temp_r3_29 + 0x2C, temp_r4_3);
                if (temp_r3_34 != 0) {
                    M2C_FIELD(temp_r28_2, s32, 0) = M2C_FIELD(temp_r3_34, s32, 0);
                    var_r26_3 = temp_r28_2; var_r24_3 = temp_r28_2; var_r25_3 = temp_r28_2 + 0xF4; var_r23_3 = temp_r28_2 + 8;
                    copy_b = M2C_FIELD(temp_r3_34, s32, 4); var_r22_3 = temp_r28_2 + 0x2C; copy_a = M2C_FIELD(temp_r3_34, s32, 8); var_r29_2 = 0;
                    M2C_FIELD(temp_r28_2, s32, 4) = copy_b; M2C_FIELD(temp_r28_2, s32, 8) = copy_a;
                    copy_a = M2C_FIELD(temp_r3_34, s32, 0xC); copy_b = M2C_FIELD(temp_r3_34, s32, 0x10); M2C_FIELD(temp_r28_2, s32, 0xC) = copy_a; M2C_FIELD(temp_r28_2, s32, 0x10) = copy_b;
                    copy_a = M2C_FIELD(temp_r3_34, s32, 0x14); copy_b = M2C_FIELD(temp_r3_34, s32, 0x18); M2C_FIELD(temp_r28_2, s32, 0x14) = copy_a; M2C_FIELD(temp_r28_2, s32, 0x18) = copy_b;
                    copy_a = M2C_FIELD(temp_r3_34, s32, 0x1C); copy_b = M2C_FIELD(temp_r3_34, s32, 0x20); M2C_FIELD(temp_r28_2, s32, 0x1C) = copy_a; M2C_FIELD(temp_r28_2, s32, 0x20) = copy_b;
                    M2C_FIELD(temp_r28_2, s32, 0x28) = M2C_FIELD(temp_r3_34, s32, 0x28); M2C_FIELD(temp_r28_2, s32, 0x24) = M2C_FIELD(temp_r3_34, s32, 0x24);
                    do {
                        var_r6_9 = M2C_FIELD(var_r26_3, u8 *, 4);
                        if (var_r6_9 != 0) { var_r5_11 = var_r25_3; var_r4_11 = 0x64; goto copy_c128_body;
copy_c128_count: var_r4_11 -= 1; if (var_r4_11 > 0) goto copy_c128_body; M2C_FIELD(var_r5_11, s8, -1) = 0; goto copy_c128_end;
copy_c128_body: temp_r3_35 = *var_r6_9++; *var_r5_11++ = temp_r3_35; if ((s8)temp_r3_35 != 0) goto copy_c128_count; goto copy_c128_end;
copy_c128_end: ; } else M2C_FIELD(var_r24_3, s8, 0xF4) = 0;
                        ((Table *)var_r22_3)->fill(var_r29_2, var_r23_3, temp_r28_2 + 0x2E8);
                        var_r26_3 += 8; var_r25_3 += 0x64; var_r24_3 += 0x64; var_r23_3 += 8; var_r22_3 += 0x28; var_r29_2 += 1;
                        if (var_r29_2 < 5) goto copy_c128_continue;
                        break;
copy_c128_continue: ; } while (1);
                } else {
                    memset(temp_r28_2, 0, 0x2C); M2C_FIELD(temp_r28_2, s8, 0xF4) = 0; M2C_FIELD(temp_r28_2, s8, 0x158) = 0; M2C_FIELD(temp_r28_2, s8, 0x1BC) = 0; M2C_FIELD(temp_r28_2, s8, 0x220) = 0; M2C_FIELD(temp_r28_2, s8, 0x284) = 0;
                }
                temp_r3_36 = M2C_FIELD(arg0, void **, 0xD0);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8, 0xDD) = (s8) (((Selector*)temp_r3_36)->get1(temp_r27_3) == 0);
                sp8 = -1; spC = -1;
                if (fn_80019258(temp_r30_3, &sp8, &spC) == 0) { spC = -1; sp8 = -1; }
                temp_r3_37 = M2C_FIELD(arg0, void **, 0xD0);
                if ((((Selector*)temp_r3_37)->get3(temp_r27_3) == 0) && (sp8 >= 0) && (spC >= 0)) {
                    fn_801345D8(((u8*)arg0 + 0x3C), 0x10, &lbl_8055C0C0, fn_8001EFC0(0, ((u8*)arg0 + 0x60)), sp8);
                    fn_801345D8(((u8*)arg0 + 0x50), 0x10, &lbl_8055C0C0, fn_8001EFC0(1, ((u8*)arg0 + 0x60)), spC);
                } else {
                    fn_80130FCC(((u8*)arg0 + 0x3C), 0x10, fn_8001EFC0(0, ((u8*)arg0 + 0x60)));
                    fn_80130FCC(((u8*)arg0 + 0x50), 0x10, fn_8001EFC0(1, ((u8*)arg0 + 0x60)));
                }
                temp_r22_2 = (u8*)fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
                fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
                if ((s32) M2C_FIELD(&lbl_80498C48, u8, 4) != 0) var_r5_12 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 0);
                else var_r5_12 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 4);
                var_r4_12 = M2C_FIELD(((u8 *)M2C_FIELD(arg0, s32 *, 0xCC) + (M2C_FIELD(arg0, s32, 0x2C) * 0x14)), s32, 0x10);
                if (var_r4_12 == 0) var_r4_12 = M2C_FIELD((temp_r22_2 + (var_r5_12 * 4)), s32, 0x64);
                fn_80255918(M2C_FIELD(arg0, void **, 0x4C), var_r4_12);
            } else fn_80216D28();
        } else { fn_80216D28(); fn_80214D50(1); }
        return 1;
    default:
        return 0;
    }
}

#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_80251078(void *arg0, s32 index, s32 selected, f32 x, f32 y, f32 w, f32 h, f32 anim) {
    extern f32 lbl_80563960;
    extern const f32 lbl_80563964, lbl_80563980, lbl_80563984, lbl_80563988;
    extern f32 fn_80216CB4(void);
    extern f32 fn_80235EF0(s32, s32);
    extern f32 fn_80235F64(s32, s32);
    extern void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
    extern void fn_80231220(s32, s32, u32, f32, f32, f32, f32, f32, f32, f32, f32);
    class Control {
    public:
        virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e();
        virtual int enabled(int);
        virtual void g();
        virtual int active(int);
    };
    char *self = (char *)arg0;
    char *entry = *(char **)(self + 0xCC) + index * 0x14;
    s32 *values = ((s32 *(*)(s32, s32))fn_80016BC8)(*(s32 *)(entry + 8), 0);
    s32 choice = lbl_80498C48[4] ? values[0] : values[1];
    s32 valid = 0;
    void *control;
    long color;
    s32 disabled, active;
    s32 flag;
    f32 time;
    if (choice >= 0 && choice < *(s32 *)(*(char **)(entry + 8) + 0x98)) valid = 1;
    if (valid) color = *(s32 *)(*(char **)(entry + 8) + 0x64 + choice * 4);
    else color = -1;
    if (*(s32 *)(entry + 0x10)) color = *(s32 *)(entry + 0x10);
    control = *(void **)(self + 0xD0);
    disabled = ((Control *)control)->enabled(index) == 0;
    active = 0;
    if (disabled == 0) {
        control = *(void **)(self + 0xD0);
        if (((Control *)control)->active(index)) active = 1;
    }
    flag = -1;
    if (disabled) flag = 0xFF808080;
    {
        f32 drawX = x, drawY = y, drawZ = lbl_80563960, drawW = w, drawH = h;
        fn_802354A0(*(s32 *)(self + 0x24), selected && active, flag, drawX, drawY, drawZ, drawW, drawH);
    }
    time = fn_80216CB4();
    if (active) {
        f32 zero = lbl_80563960, half = lbl_80563980, one = lbl_80563964;
        f32 factor = (anim - zero) / one;
        f32 alpha = lbl_80563984 * time;
        f32 center = x + half * w;
        s32 i;
        for (i = 0; i < 2; i++) {
            s32 id = 5;
            if (i == 0) id = 4;
            f32 limit = one < factor ? one : factor;
            f32 sw, sh, offset, rounded, py;
            s32 a;
            limit = limit > zero ? limit : zero;
            sw = half + limit * half;
            { f32 glyph = fn_80235EF0(*(s32 *)(self + 0x24), id); sw = glyph * sw; }
            limit = one < factor ? one : factor;
            limit = limit > zero ? limit : zero;
            sh = half + limit * half;
            { f32 glyph = fn_80235F64(*(s32 *)(self + 0x24), (unsigned)id); sh = glyph * sh; }
            rounded = alpha < zero ? alpha - half : half + alpha;
            if (a > 0x13F) a = 0x13F;
            a = rounded;
            py = i ? y - h : y + sh;
            offset = center - half * sw;
            fn_802354A0(*(s32 *)(self + 0x24), id, (a << 24) | 0xFFFFFF, offset, py, zero, sw, sh);
        }
    }
    {
        s32 positive = selected > 0 ? selected : 0;
        s32 which = 1;
        char *item;
        f32 v1, u1, v0, u0;
        register long mask;
        volatile u32 mixed;
        s32 red, green, blue, ma, mr, mg, mb;
        which = positive < 1 ? positive : 1;
        item = *(char **)(*(char **)(self + 0xC8)) + *(s32 *)(entry + which * 4) * 0x38;
        u1 = *(f32 *)(item + 0x30);
        u0 = *(f32 *)(item + 0x28);
        v0 = *(f32 *)(item + 0x2C);
        v1 = *(f32 *)(item + 0x34);
        mask = disabled ? 0xFF000000 : 0xFFFFFFFF;
        ma = 255;
        mr = ((disabled ? 0xFF000000U : 0xFFFFFFFFU) >> 16) & 0xff;
        mg = ((disabled ? 0xFF000000U : 0xFFFFFFFFU) >> 8) & 0xff;
        mb = (disabled ? 0xFF000000U : 0xFFFFFFFFU) & 0xff;
        blue = (mb * mb * (s32)(color & 0xff)) / 256 / 256;
        green = (mg * mg * (s32)((color >> 8) & 0xff)) / 256 / 256;
        red = (ma * mr * (s32)((color >> 16) & 0xff)) / 256 / 256;
        mixed = 0xFF000000 | ((red & 0xff) << 16) | ((green & 0xff) << 8) | (blue & 0xff);
        ((void (*)(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32))fn_80231220)(*(s32 *)(item + 0x24), mixed, x + lbl_80563980 * (w - lbl_80563988 * w), y - lbl_80563980 * (h - lbl_80563988 * h), lbl_80563988 * w, lbl_80563988 * h, u0, v0, u1, v1);
        ((void (*)(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32))fn_80231220)(*(s32 *)(item + 0x20), mask, x + lbl_80563980 * (w - lbl_80563988 * w), y - lbl_80563980 * (h - lbl_80563988 * h), lbl_80563988 * w, lbl_80563988 * h, u0, v0, u1, v1);
    }
}
#pragma pop

#pragma pop

extern f32 lbl_80563960;
extern void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern f32 fn_80216CB4(void);
extern void fn_80231220(s32, s32, u32, f32, f32, f32, f32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802514B4(void *arg0, s32 arg1, f32 x, f32 y, f32 w, f32 h) {
    /* Draw a UI element in three layers (ids 0, 3, 6) at (x,y,w,h): the middle
     * layer uses a per-entry value from arg0's table at +0xCC, indexed by arg1. */
    s32 value = *(s32 *)(*(char **)((char *)arg0 + 0xCC) + arg1 * 0x14 + 0x10);
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 0, -1, x, y, lbl_80563960, w, h);
    fn_80216CB4();
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 3, value, x, y, lbl_80563960, w, h);
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 6, -1, x, y, lbl_80563960, w, h);
}
#pragma scheduling on

#pragma cplusplus on
extern "C" void fn_80216D28(void);
extern "C" s32 fn_80214D50(s32);
extern "C" void fn_80255918(void *, s32);
extern "C" void fn_801345D8(void *, s32, void *, ...);
#pragma push
#pragma optimize_for_size off
#pragma scheduling invalid_target
/* Handles "move up" (0x125) or "move down" (0x127) in the vehicle color selector:
 * adjusts the current index, updates the vehicle slot's color index, refreshes the
 * UI color element, and formats the color resource name. Returns 1 if handled. */
extern "C" s32 fn_8025157C(u8 *arg0, s32 arg1) {
    s32 newIndex;
    switch (arg1) {
    case 0x125: {
        u8 ch;
        u8 *source;
        s32 count;
        u8 *dest;
        s32 value, index, context;

        if (*(s32 *)(arg0 + 0x2C) > 0) {
            newIndex = --*(s32 *)(arg0 + 0x2C);

            context = fn_8001668C((s32)(arg0 + 0x60), 0);
            if (lbl_80498C48[4] != 0)
                ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[0] = newIndex;
            else
                ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[1] = newIndex;

            newIndex = fn_8001668C((s32)(arg0 + 0x60), 0);
            if (lbl_80498C48[4] != 0) {
                value = *(s32 *)(arg0 + 0x2C);
                ((s32 *(*)(s32, s32))fn_80016BC8)(newIndex, 0)[0] = value;
            } else {
                value = *(s32 *)(arg0 + 0x2C);
                ((s32 *(*)(s32, s32))fn_80016BC8)(newIndex, 0)[1] = value;
            }

            index = *(s32 *)(arg0 + 0x2C);
            *(*(s32 **)(arg0 + 0xDC)) =
                *(s32 *)((u8 *)newIndex + index * 4 + 0x64);

            newIndex = fn_8001668C((s32)(arg0 + 0x60), 0);
            context = fn_8001668C((s32)(arg0 + 0x60), 0);
            if (lbl_80498C48[4] != 0)
                context = ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[0];
            else
                context = ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[1];

            index = *(s32 *)((u8 *)*(s32 **)(arg0 + 0xCC) +
                             *(s32 *)(arg0 + 0x2C) * 0x14 + 0x10);
            source = *(u8 **)(arg0 + 0x4C);
            fn_80255918(source,
                         index != 0 ? index :
                         *(s32 *)((u8 *)newIndex + context * 4 + 0x64));

            fn_801345D8(arg0 + 0xE0, 0x100, lbl_8034287C,
                        *(s32 *)(arg0 + 0x2C) + 1);
            source = fn_80131234(arg0 + 0xE0);
            dest = arg0 + 0xE0;
            count = 0x100;
            goto copy_loop_1;
        copy_count_1:
            count -= 1;
            if (count > 0)
                goto copy_loop_1;
            dest[-1] = 0;
            goto copy_done_1;
        copy_loop_1:
            ch = *source++;
            *dest++ = ch;
            if ((signed char)ch == 0)
                goto copy_done_1;
            else
                goto copy_count_1;
        copy_done_1:
            goto done_1;
        }

        fn_80216D28();
        fn_80214D50(1);
    done_1:
        return 1;
    }
    case 0x127: {
        u8 ch;
        u8 *source;
        s32 count;
        u8 *dest;
        s32 value, index, context;

        if (*(s32 *)(arg0 + 0x2C) < *(s32 *)(arg0 + 0x1C) - 1) {
            newIndex = *(s32 *)(arg0 + 0x2C) + 1;
            *(s32 *)(arg0 + 0x2C) = newIndex;

            context = fn_8001668C((s32)(arg0 + 0x60), 0);
            if (lbl_80498C48[4] != 0)
                ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[0] = newIndex;
            else
                ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[1] = newIndex;

            newIndex = fn_8001668C((s32)(arg0 + 0x60), 0);
            if (lbl_80498C48[4] != 0) {
                value = *(s32 *)(arg0 + 0x2C);
                ((s32 *(*)(s32, s32))fn_80016BC8)(newIndex, 0)[0] = value;
            } else {
                value = *(s32 *)(arg0 + 0x2C);
                ((s32 *(*)(s32, s32))fn_80016BC8)(newIndex, 0)[1] = value;
            }

            index = *(s32 *)(arg0 + 0x2C);
            *(*(s32 **)(arg0 + 0xDC)) =
                *(s32 *)((u8 *)newIndex + index * 4 + 0x64);

            newIndex = fn_8001668C((s32)(arg0 + 0x60), 0);
            context = fn_8001668C((s32)(arg0 + 0x60), 0);
            if (lbl_80498C48[4] != 0)
                context = ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[0];
            else
                context = ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[1];

            index = *(s32 *)((u8 *)*(s32 **)(arg0 + 0xCC) +
                             *(s32 *)(arg0 + 0x2C) * 0x14 + 0x10);
            source = *(u8 **)(arg0 + 0x4C);
            fn_80255918(source,
                         index != 0 ? index :
                         *(s32 *)((u8 *)newIndex + context * 4 + 0x64));

            fn_801345D8(arg0 + 0xE0, 0x100, lbl_8034287C,
                        *(s32 *)(arg0 + 0x2C) + 1);
            source = fn_80131234(arg0 + 0xE0);
            dest = arg0 + 0xE0;
            count = 0x100;
            goto copy_loop_2;
        copy_count_2:
            count -= 1;
            if (count > 0)
                goto copy_loop_2;
            dest[-1] = 0;
            goto copy_done_2;
        copy_loop_2:
            ch = *source++;
            *dest++ = ch;
            if ((signed char)ch == 0)
                goto copy_done_2;
            else
                goto copy_count_2;
        copy_done_2:
            goto done_2;
        }

        fn_80216D28();
        fn_80214D50(1);
    done_2:
        return 1;
    }
    default:
        return 0;
    }
}
#pragma pop
extern "C" void fn_80251934(void *menu) {
    /* Refresh a menu's per-item active flags from its input entries, animate each
     * item's highlight value toward its flag, smooth the selection value, then
     * enable or disable the menu through its Selector. */
    extern f32 fn_80214D48(void);
    extern const f32 lbl_80563964, lbl_80563968, lbl_8056396C, lbl_80563970;
    extern double __fabs(double);
    extern void fn_80214A9C(s32, f32);
    extern void fn_80214AF0(s32);
    #define SmoothFactor lbl_80563968
    #define AnimSpeed    lbl_8056396C
    #define AnimMax      lbl_80563964
    #define AnimWrap     lbl_80563970
    class Selector {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual s32 check(s32);
    };
    register s32 active;
    register s32 inputOffset;
    register s32 outputOffset;
    register s32 index;
    u8 *stateEntry;
    u8 *itemInfo;

    index = 0;
    *(s32 *)((u8 *)menu + 0xC0) =
        *(u8 *)(*(u8 **)((u8 *)menu + 0x4C) + 0xDC) == 0;
    inputOffset = 0;
    outputOffset = 0;
    while (index < *(s32 *)((u8 *)menu + 0x1C)) {
        active = 0;
        stateEntry = *(u8 **)((u8 *)menu + 0xCC) + inputOffset;
        itemInfo = ((u8 *(*)(s32, s32))fn_80016BC8)(*(s32 *)(stateEntry + 8), 0);
        if (itemInfo[8] != 0 && stateEntry[0xC] != 0)
            active = 1;
        stateEntry = *(u8 **)((u8 *)menu + 0x18) + outputOffset;
        if (active != *(s32 *)(stateEntry + 4)) {
            *(s32 *)(stateEntry + 4) = active;
            *(f32 *)(stateEntry + 8) =
                (f32)__fabs((double)*(f32 *)(stateEntry + 8));
        }
        inputOffset += 0x14;
        outputOffset += 0xC;
        ++index;
    }

    {
        f32 deltaTime = fn_80214D48();
        register u8 *animEntry;
        register s32 entryIndex;
        register s32 entryOffset;
        f32 current;

        entryIndex = 0;
        entryOffset = 0;
        current = *(f32 *)((u8 *)menu + 0x28);
        *(f32 *)((u8 *)menu + 0x28) =
            current + SmoothFactor * ((f32)*(s32 *)((u8 *)menu + 0x2C) - current);
        for (; entryIndex < *(s32 *)((u8 *)menu + 0x1C); entryOffset += 12, entryIndex++) {
            animEntry = *(u8 **)((u8 *)menu + 0x18) + entryOffset;
            if (*(s32 *)(animEntry + 4) != *(s32 *)animEntry) {
                *(f32 *)(animEntry + 8) += AnimSpeed * deltaTime;
                if (*(f32 *)(animEntry + 8) >= AnimMax) {
                    *(s32 *)animEntry = *(s32 *)(animEntry + 4);
                    *(f32 *)(animEntry + 8) -= AnimWrap;
                }
            } else {
                f32 value = *(f32 *)(animEntry + 8) + AnimSpeed * deltaTime;
                if (0.0f < value)
                    value = 0.0f;
                *(f32 *)(animEntry + 8) = value;
            }
        }
    }

    {
        Selector *selector = *(Selector **)((u8 *)menu + 0xD0);
        if (selector->check(*(s32 *)((u8 *)menu + 0x2C)) == 0)
            ((void (*)(s32))fn_80214A9C)(2);
        else
            fn_80214AF0(2);
    }
}

extern s32 lbl_8055CFF0;
extern u32 lbl_8055CFF4;
extern const f32 lbl_80563964, lbl_80563980, lbl_8056398C, lbl_80563990, lbl_80563994, lbl_80563998, lbl_8056399C, lbl_805639A0, lbl_805639A4, lbl_805639A8, lbl_805639AC, lbl_805639B0, lbl_805639B4, lbl_805639B8, lbl_805639BC;
extern void fn_80231220(s32, s32, u32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" s32 lbl_8055CFF0;
extern "C" u32 lbl_8055CFF4;
extern "C" const f32 lbl_80563964, lbl_80563980, lbl_8056398C, lbl_80563990, lbl_80563994, lbl_80563998, lbl_8056399C, lbl_805639A0, lbl_805639A4, lbl_805639A8, lbl_805639AC, lbl_805639B0, lbl_805639B4, lbl_805639B8, lbl_805639BC;
extern "C" double __fabs(double);
extern "C" void fn_80251B04(void *arg0) {
    extern s32 lbl_8055CFF0;
    extern u32 lbl_8055CFF4;
    extern const f32 lbl_80563964, lbl_80563980, lbl_8056398C, lbl_80563990, lbl_80563994, lbl_80563998, lbl_8056399C, lbl_805639A0, lbl_805639A4, lbl_805639A8, lbl_805639AC, lbl_805639B0, lbl_805639B4, lbl_805639B8, lbl_805639BC;
    extern double __fabs(double);
    f32 temp_f3, temp_f10, f27, f26, f23;
    s32 off, i;
    temp_f10 = (f32)((s32)(((u32)lbl_8055CFF4 >> 31) + lbl_8055CFF4) >> 1);
    temp_f3 = (lbl_80563990 * (f32)lbl_8055CFF0) / lbl_80563994;
    f27 = temp_f10 - lbl_8056398C;
    fn_80231220(*(s32 *)((char *)arg0 + 0x20), -1, lbl_8055CFF4, lbl_80563998 * temp_f3, lbl_8056399C, temp_f3, lbl_805639A0, lbl_80563960, lbl_80563960, lbl_805639A4, lbl_80563964);
    f26 = fn_80216CB4();
    f23 = lbl_80563960;
    i = 0;
    off = 0;
    for (; i < *(s32 *)((char *)arg0 + 0x1C); i++, off += 0xC) {
        register char *p = *(char **)((char *)arg0 + 0x18) + off;
        register f32 a, b, c;
        register s32 idx = i;
        a = lbl_80563964 - (f32)__fabs(*(f32 *)(p + 8));
        a = a < f26 ? a : f26;
        c = *(f32 *)((char *)arg0 + 0x28);
        b = (f32)__fabs(c - (f32)i);
        b = b < lbl_80563964 ? b : lbl_80563964;
        b = b > f23 ? b : f23;
        (*(void (**)(void *, s32, s32, f32, f32, f32, f32, f32))(*(char **)arg0 + 0x60))(arg0, i, *(s32 *)p, lbl_805639AC * ((f32)i - c) - lbl_805639B0, (f27 - lbl_80563980 * (lbl_805639A8 * (lbl_80563964 - a))) + lbl_805639B4 * a, lbl_805639AC, lbl_805639A8 * a + lbl_805639A4 * a, lbl_80563964 - b);
    }
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 2, -1, lbl_805639B8, lbl_805639B4 + f27, lbl_80563960, lbl_805639AC, lbl_805639BC);
}

#pragma scheduling on
#pragma pop

#pragma scheduling on
#pragma optimize_for_size reset
extern void fn_80255904(s32);
extern void fn_80214A9C(s32, f32);
extern void fn_80221F94(void *, s32);
extern void *fn_801284F8(u32, void *);
extern void *fn_8012850C(s32, void *);
extern void fn_801312EC(void *, void *);
extern f32 lbl_80563960, lbl_805639C0;
__declspec(section ".data") extern f32 lbl_80558DC4;
extern char lbl_8055C0E0[];
extern char lbl_80344378[], lbl_80344384[], lbl_80344690[], lbl_803443B0[];
typedef struct InitTail {
    u8 f0[0x28];
    u8 b28;
    u8 f1[0x1F];
    u8 b48;
    u8 f2[0x3F];
    u8 b88;
    u8 f3[0x7F];
    u8 b108;
    u8 f4[0x87];
    s32 w190;
    f32 f194;
    f32 f198;
    u8 b19c;
} InitTail;
#pragma scheduling off
/* Reset the tail of an object: forward its +0x20 handle through fn_80255904,
 * clear flag bytes at +0x28/+0x48/+0x88/+0x108 and +0x19C, set +0x190 to -1,
 * initialize +0x194/+0x198 to 0.0/20.0, and hide UI group 0x1F. */
void fn_80251D0C(void *__restrict object) {
#pragma scheduling on
    float zeroValue;
    int zero;
    float maxValue;
    fn_80255904(*(s32 *)((char *)object + 0x20));
    zeroValue = lbl_80563960;
    zero = 0;
    maxValue = lbl_805639C0;
    *(s32 *)((char *)object + 0x190) = -1;
    *(u8 *)((char *)object + 0x28) = zero;
    *(u8 *)((char *)object + 0x48) = zero;
    *(u8 *)((char *)object + 0x88) = zero;
    *(u8 *)((char *)object + 0x108) = zero;
    *(f32 *)((char *)object + 0x194) = zeroValue;
    *(f32 *)((char *)object + 0x198) = maxValue;
    fn_80214A9C(0x1F, zeroValue);
    *(u8 *)((char *)object + 0x19C) = zero;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_80251D7C(void *arg0) {
    typedef signed char s8;
    class Selector {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual s32 getCount();
        virtual void *get0(s32); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void *get1(s32); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(void *);
    };
    class Table {
    public:
        virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3();
        virtual void t4(); virtual void t5(); virtual void t6(); virtual void t7();
        virtual void t8(); virtual void t9(); virtual void t10(); virtual void t11();
        virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15();
        virtual void t16(); virtual void t17(); virtual void t18(); virtual void t19();
        virtual void t20(); virtual void t21();
        virtual void fill(s32, void *, void *);
    };
    extern f32 fn_80214D48(void);
    extern void fn_80214AF0(s32);
    extern void fn_80255920(void *, s32);
    extern s32 fn_8025590C(void *);
    extern void fn_80236954(void *);
    extern double __fabs(double);
    extern f32 lbl_80563960;
    extern const f32 lbl_80563970;
    extern unsigned char lbl_803446D4[], lbl_803446E0[], lbl_803446FC[], lbl_80344714[];
    s32 idx;
    void *save31;
    void *objData;
    s32 copy_a;
    s32 copy_b;
    s32 loopCnt;
    u8 *entryPtr;
    u8 *dstPtr;
    u8 *copyDst;
    u8 *fillDst;
    u8 *tablePtr;
    s32 n;
    u8 *srcA;
    u8 *dstA;
    s32 tempA;
    u8 *srcB;
    u8 *dstB;
    s32 tempB;
    u8 *srcC;
    u8 *dstC;
    s32 tempC;
    u8 *srcD;
    u8 *dstD;
    s32 tempD;
    u8 *srcE;
    u8 *dstE;
    s32 tempE;
    u8 *srcF;
    u8 *dstF;
    s32 tempF;
    u8 *srcG;
    u8 *dstG;
    s32 tempG;
    idx = M2C_FIELD(arg0, s32, 0x18C);
    if (idx >= 0) {
        if (idx < ((Selector*)M2C_FIELD(arg0, void **, 0x18))->getCount()) {
            if (idx != M2C_FIELD(arg0, s32, 0x190)) {
                void **o188 = M2C_FIELD(arg0, void **, 0x188);
                M2C_FIELD(arg0, s32, 0x190) = idx;
                if (o188 != 0) {
                    ((Selector*)o188)->v12(&lbl_80344714);
                }
                srcA = (u8*)((Selector*)M2C_FIELD(arg0, void **, 0x18))->get0(M2C_FIELD(arg0, s32, 0x18C));
                dstA = (u8*)arg0 + 0x28;
                n = 0x20;
                goto copy1_body;
copy1_cnt:
                n--;
                if (n > 0) goto copy1_body;
                M2C_FIELD(dstA, s8, -1) = 0;
                goto copy1_end;
copy1_body:
                tempA = *srcA++;
                *dstA++ = tempA;
                if ((s8)tempA != 0) goto copy1_cnt;
copy1_end: ;
                save31 = (void *)fn_8001668C((s32)arg0 + 0x28, 0);
                srcB = (u8*)save31 + 0xC;
                dstB = (u8*)arg0 + 0x48;
                n = 0x40;
                goto copy2_body;
copy2_cnt:
                n--;
                if (n > 0) goto copy2_body;
                M2C_FIELD(dstB, s8, -1) = 0;
                goto copy2_end;
copy2_body:
                tempB = *srcB++;
                *dstB++ = tempB;
                if ((s8)tempB != 0) goto copy2_cnt;
copy2_end: ;
                if (((u32)M2C_FIELD(save31, u32, 0xA0) & 2) == 0) {
                    srcC = &lbl_803446FC[0];
                    dstC = (u8*)arg0 + 0x88;
                    n = 0x80;
                    goto copy3_body;
copy3_cnt:
                    n--;
                    if (n > 0) goto copy3_body;
                    M2C_FIELD(dstC, s8, -1) = 0;
                    goto copy3_end;
copy3_body:
                    tempC = *srcC++;
                    *dstC++ = tempC;
                    if ((s8)tempC != 0) goto copy3_cnt;
copy3_end: ;
                    fn_80255918(M2C_FIELD(arg0, void *, 0x20), M2C_FIELD((u8*)save31 + (M2C_FIELD(save31, s32, 0x94) * 4), s32, 0x64));
                } else {
                    srcD = &lbl_803446E0[0];
                    dstD = (u8*)arg0 + 0x88;
                    n = 0x80;
                    goto copy4_body;
copy4_cnt:
                    n--;
                    if (n > 0) goto copy4_body;
                    M2C_FIELD(dstD, s8, -1) = 0;
                    goto copy4_end;
copy4_body:
                    tempD = *srcD++;
                    *dstD++ = tempD;
                    if ((s8)tempD != 0) goto copy4_cnt;
copy4_end: ;
                    {
                        void *p = M2C_FIELD(arg0, void *, 0x1C);
                        if (p != 0) {
                            fn_80255918(M2C_FIELD(arg0, void *, 0x20), *(s32*)p);
                        } else {
                            fn_80255918(M2C_FIELD(arg0, void *, 0x20), M2C_FIELD((u8*)save31 + (M2C_FIELD(save31, s32, 0x94) * 4), s32, 0x64));
                        }
                    }
                }
                {
                    u8 *res = fn_80131234((u8*)((s32)arg0 + 0x88));
                    if (res != (u8*)((s32)arg0 + 0x88)) {
                        srcE = res;
                        dstE = (u8*)((s32)arg0 + 0x88);
                        n = 0x80;
                        goto copy5_body;
copy5_cnt:
                        n--;
                        if (n > 0) goto copy5_body;
                        M2C_FIELD(dstE, s8, -1) = 0;
                        goto copy5_end;
copy5_body:
                        tempE = *srcE++;
                        *dstE++ = tempE;
                        if ((s8)tempE != 0) goto copy5_cnt;
copy5_end: ;
                    }
                }
                srcF = (u8*)((Selector*)M2C_FIELD(arg0, void **, 0x18))->get1(M2C_FIELD(arg0, s32, 0x18C));
                dstF = (u8*)arg0 + 0x108;
                n = 0x80;
                goto copy6_body;
copy6_cnt:
                n--;
                if (n > 0) goto copy6_body;
                M2C_FIELD(dstF, s8, -1) = 0;
                goto copy6_end;
copy6_body:
                tempF = *srcF++;
                *dstF++ = tempF;
                if ((s8)tempF != 0) goto copy6_cnt;
copy6_end: ;
                fn_80255920(M2C_FIELD(arg0, void *, 0x20), (M2C_FIELD(save31, u32, 0xA0) >> 2) & 1);
            }
            if (fn_8025590C(M2C_FIELD(arg0, void *, 0x20)) != 0) {
                if (M2C_FIELD(arg0, u8, 0x19C) == 0) {
                    fn_80236954(&lbl_803446D4[0]);
                }
                M2C_FIELD(arg0, u8, 0x19C) = 1;
            } else {
                M2C_FIELD(arg0, f32, 0x194) = lbl_80563970;
            }
        }
    }
    save31 = M2C_FIELD(arg0, void *, 0x24);
    objData = ((void *(*)(void *))fn_80018A8C)((u8*)arg0 + 0x28);
    if (objData != 0) {
        entryPtr = (u8*)save31;
        dstPtr = (u8*)save31;
        M2C_FIELD(save31, s32, 0) = M2C_FIELD(objData, s32, 0);
        copyDst = (u8*)save31 + 0xF4;
        fillDst = (u8*)save31 + 8;
        tablePtr = (u8*)save31 + 0x2C;
        loopCnt = 0;
        copy_b = M2C_FIELD(objData, s32, 4);
        copy_a = M2C_FIELD(objData, s32, 8);
        M2C_FIELD(save31, s32, 4) = copy_b;
        M2C_FIELD(save31, s32, 8) = copy_a;
        copy_a = M2C_FIELD(objData, s32, 0xC);
        copy_b = M2C_FIELD(objData, s32, 0x10);
        M2C_FIELD(save31, s32, 0xC) = copy_a;
        M2C_FIELD(save31, s32, 0x10) = copy_b;
        copy_a = M2C_FIELD(objData, s32, 0x14);
        copy_b = M2C_FIELD(objData, s32, 0x18);
        M2C_FIELD(save31, s32, 0x14) = copy_a;
        M2C_FIELD(save31, s32, 0x18) = copy_b;
        copy_a = M2C_FIELD(objData, volatile s32, 0x1C);
        copy_b = M2C_FIELD(objData, volatile s32, 0x20);
        M2C_FIELD(save31, s32, 0x1C) = copy_a;
        M2C_FIELD(save31, s32, 0x20) = copy_b;
        copy_a = M2C_FIELD(objData, volatile s32, 0x24);
        copy_b = M2C_FIELD(objData, volatile s32, 0x28);
        M2C_FIELD(save31, s32, 0x24) = copy_a;
        M2C_FIELD(save31, s32, 0x28) = copy_b;
        do {
            u8 *fillTail = (u8 *)save31 + 0x2E8;
            srcG = M2C_FIELD(entryPtr, u8 *, 4);
            if (srcG != 0) {
                dstG = copyDst;
                n = 0x64;
                goto copy7_body;
copy7_cnt:
                n--;
                if (n > 0) goto copy7_body;
                M2C_FIELD(dstG, s8, -1) = 0;
                goto copy7_end;
copy7_body:
                tempG = *srcG++;
                *dstG++ = tempG;
                if ((s8)tempG == 0) goto copy7_end;
                goto copy7_cnt;
copy7_end: ;
            } else {
                M2C_FIELD(dstPtr, s8, 0xF4) = 0;
            }
            ((Table *)tablePtr)->fill(loopCnt, fillDst, fillTail);
            loopCnt += 1;
            entryPtr += 8;
            copyDst += 0x64;
            dstPtr += 0x64;
            fillDst += 8;
            tablePtr += 0x28;
        } while (loopCnt < 5);
    } else {
        memset(save31, 0, 0x2C);
        M2C_FIELD(save31, s8, 0xF4) = 0;
        M2C_FIELD(save31, s8, 0x158) = 0;
        M2C_FIELD(save31, s8, 0x1BC) = 0;
        M2C_FIELD(save31, s8, 0x220) = 0;
        M2C_FIELD(save31, s8, 0x284) = 0;
    }
    {
        f32 tmp = M2C_FIELD(arg0, f32, 0x194) - fn_80214D48();
        f32 lim = (tmp > lbl_80563960) ? tmp : lbl_80563960;
        M2C_FIELD(arg0, f32, 0x194) = lim;
        if ((f32)__fabs((double)lim) <= lbl_80558DC4) {
            fn_80214AF0(0x1F);
        }
    }
    {
        f32 tmp = M2C_FIELD(arg0, f32, 0x198) - fn_80214D48();
        f32 lim = (tmp > lbl_80563960) ? tmp : lbl_80563960;
        M2C_FIELD(arg0, f32, 0x198) = lim;
        if ((f32)__fabs((double)lim) <= lbl_80558DC4) {
            fn_80214AF0(0x1F);
        }
    }
}
#pragma pop

static inline f32 fn_80252238_fabs(f32 x) {
    extern double __fabs(double);
    return (f32)__fabs((double)x);
}
#pragma scheduling on
s32 fn_80252238(void *object, s32 inputCode) {
    /* On confirm input (13), close this selector with result 0 and report handled if either decaying value has settled to ~0. */
    #define valueA       (*(f32 *)((char *)object + 0x194))
    #define valueB       (*(f32 *)((char *)object + 0x198))
    #define restEpsilon  lbl_80558DC4
    #define requestClose fn_80221F94

    if (inputCode == 13 &&
        (fn_80252238_fabs(valueA) <= restEpsilon ||
         fn_80252238_fabs(valueB) <= restEpsilon)) {
        requestClose(object, 0);
        return 1;
    }
    return 0;

    #undef requestClose
    #undef restEpsilon
    #undef valueB
    #undef valueA
}

#pragma push
#pragma opt_common_subs off
// ChassisList's deleting destructor (vtable lbl_80344384 slot 0, allocation tag "ChassisList").
// Releases the chassis record array and, when deleteFlags > 0, the list object itself.
void *fn_802522A8(void *arg0, s32 deleteFlags) {
    // ChassisList, 0x20 bytes; built by fn_8025007C().
    struct ChassisList {
        void *vptr;       // +0x00 vtable lbl_80344384
        void *records;    // +0x04 chassis records, 0x48 bytes each
        s32 count;        // +0x08 records in use
        s32 capacity;     // +0x0C records allocated
        void *allocation; // +0x10 the block the records were allocated in
    } *list = arg0;

    if (arg0 != 0) {
        if (&list->records != 0) {
            fn_80128670((s32)list->allocation); // MemFree(block, "new[]")
            if (&list->records != 0) {
                list->records = 0;
                list->count = 0;
                list->capacity = 0;
            }
        }
        if (deleteFlags > 0) fn_80128668(arg0); // MemFree(object, "new")
    }
    return arg0;
}
static inline void fn_80252320_copy(char *src, s32 count, char *dst) {
    while ((signed char)(*dst++ = *src++) != 0) {
        if (--count <= 0) {
            dst[-1] = 0;
            break;
        }
    }
}

/* Append an entry (0x48 bytes) to the table at arg0: copy name `arg1` into
 * name[0x20], store `arg2`/`arg3` flags, set name2 from `arg1`'s path component
 * (or empty when `arg3` is 0), bump the table's generation at +0x14 if stale,
 * and record the current value (+0x18) at +0x44. */
void fn_80252320(void *arg0, u8 *arg1, signed char arg2, int arg3) {
    struct Entry {
        char name[0x20];
        signed char flag20;
        char name2[0x20];
        signed char flag41;
        short pad;
        s32 value;
    };
    struct Entry *record;
    char *src;
    s32 count;
    char *dst;

    record = &((struct Entry *)*(unsigned int *)((char *)arg0 + 4))[(*(s32 *)((char *)arg0 + 8))++];
    src = (char *)arg1;
    dst = record->name;
    count = 0x20;
    goto copy1;
check1:
    if (--count > 0) goto copy1;
    dst[-1] = 0;
    goto copied1;
copy1:
    if ((*dst++ = *src++) != 0) goto check1;
copied1:
    record->flag20 = arg2;
    record->flag41 = arg3;
    if (arg3 != 0) {
        src = (char *)fn_80019098(arg1);
        fn_80252320_copy(src, 0x20, record->name2);
    } else {
        char *d;
        d = record->name2;
        src = (char *)&lbl_8055C0E8;
        count = 0x20;
        goto copy3;
    check3:
        if (--count > 0) goto copy3;
        d[-1] = 0;
        goto copied3;
    copy3:
        if ((*d++ = *src++) != 0) goto check3;
    copied3:
        ;
    }
    if (*(u32 *)((char *)arg0 + 0x1C) != lbl_8055E044)
        fn_80131318((char *)arg0 + 0x14);
    record->value = *(s32 *)((char *)arg0 + 0x18);
}

#pragma pop

/* Sets the s32 field at +0x44 of the indexed 0x48-byte chassis record in the
   ChassisList's array (the complement of the fn_802524BC getter). */
void fn_80252454(void *list, s32 chassisIndex, s32 value) {
    s32 offset = chassisIndex * 0x48;
    s32 *records = *(s32 **)((char *)list + 4);
    *(s32 *)((char *)records + offset + 0x44) = value;
}

/* Return the number of chassis records in use (ChassisList.count at +8). */
s32 fn_80252468(void *list) { return *(s32 *)((char *)list + 8); }

/* Returns the base address of the indexed 0x48-byte chassis record in the
   ChassisList's array (the array pointer lives at +4 of the list). */
s32 fn_80252470(void *list, s32 chassisIndex) {
    s32 offset = chassisIndex * 0x48;
    s32 *records = *(s32 **)((char *)list + 4);
    return (s32)records + offset;
}

u8 fn_80252480(void *list, s32 chassisIndex) {
    // Read the u8 field at +0x20 of the indexed 0x48-byte chassis record.
    s32 offset = chassisIndex * 0x48;
    s32 *records = *(s32 **)((char *)list + 4);
    return *(u8 *)((char *)records + offset + 0x20);
}

char *fn_80252494(void *table, s32 recordIndex) {
    // Address of the name string (+0x21) inside the given 0x48-byte record.
    s32 byteOffset = recordIndex * 0x48;
    char *records = *(char **)((char *)table + 4);
    return records + byteOffset + 0x21;
}

/* Returns the u8 flag at +0x41 of the indexed 0x48-byte chassis record in the
   ChassisList's array (set by fn_80252320; selects the record's name source). */
u8 fn_802524A8(void *list, s32 chassisIndex) {
    s32 offset = chassisIndex * 0x48;
    s32 *records = *(s32 **)((char *)list + 4);
    return *(u8 *)((char *)records + offset + 0x41);
}

s32 fn_802524BC(void *table, s32 recordIndex) {
    // Read the s32 field at +0x44 of the given 0x48-byte record.
    s32 byteOffset = recordIndex * 0x48;
    s32 *records = *(s32 **)((char *)table + 4);
    return *(s32 *)((char *)records + byteOffset + 0x44);
}
