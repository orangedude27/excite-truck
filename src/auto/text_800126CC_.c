#include "decomp.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
/* Global table of registered resource handles: up to 32 handles followed by the count. */
typedef struct HandleTable { void *handles[32]; int count; } HandleTable;

extern void Abend_Panic(void *, ...);
extern char lbl_802FC638[];
extern char lbl_802FC69C[];
extern char lbl_80352AD0[];
extern char lbl_802FC610[];
extern char lbl_802FCB50[];
extern int lbl_8055D51C;
extern int lbl_8055D50C;
extern int lbl_8055D510;
extern int lbl_8055D514;
extern int lbl_80558AD8;
extern int lbl_8055D508;
extern void *lbl_8055D504;
extern char lbl_80351828[];
extern void qsort(void *, int, int, void *);
extern int lbl_8055D518;
extern char lbl_8055D500;
extern char lbl_803518C0[];
extern void fn_80013A34(void);
extern void fn_80013618(int);
extern void fn_8013C804(void);
extern void fn_8013C8B8(void);
extern int fn_8019B3C(void);
extern int fn_8019B54(void);
extern void fn_80013724(void);
extern int fn_80007F90(int);
extern int fn_801345D8(void *, int, const char *, ...);
void fn_80012984();
typedef void *(*Vfn_8001335C)();
struct Obj_8001335C;
typedef struct VT_8001335C {
    void *pad0, *pad1;
    char *(*name)(struct Obj_8001335C *);
    struct Obj_8001335C *(*child)(struct Obj_8001335C *, int);
    void *pad4;
    char *(*get)(struct Obj_8001335C *, char *);
    void (*set)(struct Obj_8001335C *, char *, int);
} VT_8001335C;
typedef struct Obj_8001335C { VT_8001335C *vt; } Obj_8001335C;
#define VCALL_8001335C(o, slot) ((Vfn_8001335C)((*(void ***)(o))[slot]))
#pragma scheduling invalid_target
/* Look up mode info entry by id in lbl_802FC638 (5 entries * 0x14); abort if not found. */
void *fn_800126CC(int modeId) DECOMP_DONT_INLINE {
    volatile int *table = (volatile int *)lbl_802FC638;
    int index = 0;
    if (modeId != table[0]) {
        index = 1;
        if (modeId != table[5]) {
            index = 2;
            if (modeId != table[10]) {
                index = 3;
                if (modeId != table[15]) {
                    index = 4;
                    if (modeId != table[20])
                        index = 5;
                }
            }
        }
    }
    if (index >= 5)
        Abend_Panic(lbl_802FC69C, modeId); /* "get_mode_info: can't find mode %d" */
    return lbl_802FC638 + index * 0x14;
}
#pragma scheduling on
/* Initialize/load the resource set for game mode id 0x12F (a thin wrapper over fn_80012984). */
void fn_80012778(void) { fn_80012984(0x12F); }

/* Initialize/load the resource set for game mode id 0x130 (a thin wrapper over fn_80012984). */
void fn_80012780(void) { fn_80012984(0x130); }

/* Initialize/load the resource set for game mode id 0x132 (a thin wrapper over fn_80012984). */
void fn_80012788(void) { fn_80012984(0x132); }

/* Initialize/load the resource set for the given game mode id (tail-call to fn_80012984). */
void fn_80012790(int modeId) {
    fn_80012984(modeId);
}

extern int lbl_80558AD8;
void* fn_80012810(void) {
    /* Return the current game mode id held in lbl_80558AD8 (used by callers as
     * prev/current mode and passed to fn_800126CC to look up mode info). */
    return (void*)lbl_80558AD8;
}

extern void *lbl_8055D504;
void* fn_80012818(void) {
    /* Return the number of event/menu entries currently registered in the
     * lbl_803518C0 table (global counter lbl_8055D504, capped at 0x23). */
    return lbl_8055D504;
}

extern int lbl_8055D508;
/* Return the number of registered contest/per-slot entries held in lbl_8055D508
 * (the count of 0x28-byte records in the global table lbl_80352AD0), as a void*. */
void* fn_80012854(void) {
    return (void*)lbl_8055D508;
}

void *fn_8001285C(int index) DECOMP_DONT_INLINE {
    /* Return a pointer to the 0x28-byte entry at the given index in the per-slot state table lbl_80352AD0. */
    return &lbl_80352AD0[index * 0x28];
}

extern char lbl_80352AD0[];
extern char lbl_802FC700[];
extern void fn_80131818(void *);
extern char lbl_8035183C[];
extern char lbl_8055D500;
extern int lbl_8055D514;
#pragma scheduling invalid_target
void fn_80012794(void) {
    /* Release every registered resource handle (fn_80131818 drops one reference
     * each), then empty the table, switch the game mode to 0x134 and clear the
     * resource-ready and selected-object flags. */
    HandleTable *table;
    HandleTable *slot = (HandleTable *)&lbl_8035183C;
    int index = 0;
    table = slot;
    lbl_80558AD8 = 0x134;
    while (index < table->count) {
        fn_80131818((void *)slot->handles[0]);
        slot = (HandleTable *)((char *)slot + 4);
        index++;
    }
    table->count = 0;
    lbl_8055D500 = 0;
    lbl_8055D514 = 0;
}
#pragma scheduling on
extern char lbl_803518C0[];
extern char lbl_803551E0[];
char *fn_80012820(int id) DECOMP_DONT_INLINE {
    /* Look up a record by signed id: nonnegative ids index the first table,
       negative ids index the second using -1-id. */
    if (id >= 0) {
        return &lbl_803518C0[id * 0x84];
    }
    return &lbl_803551E0[(-1 - id) * 0x88];
}
#pragma scheduling invalid_target
/* Find the nth active contest entry for an event id in the contest table. */
void *fn_80012870(int eventId, int contestIndex) {
    unsigned char *entryPtr = (unsigned char *)lbl_80352AD0;
    int matchCount = 0;
    unsigned int entryIndex = 0;
    int count = lbl_8055D508;
    for (; count > 0; count--, entryPtr += 0x28, entryIndex++) {
        if (eventId == *(int *)(entryPtr + 4) && entryPtr[0x24] != 0) {
            if (matchCount == contestIndex)
                return &lbl_80352AD0[entryIndex * 0x28];
            matchCount++;
        }
    }
    Abend_Panic(lbl_802FC700, eventId, contestIndex);
    return 0;
}
#pragma scheduling on
extern void *fn_8001285C();
extern char *fn_80012820(int);
extern const char *fn_80007FF0(int);
extern int fn_80012938(float);
extern volatile float lbl_80560358;
/* Look up the display name for the current contest record's event type
 * (field +0x8); the lookup logs a message for unknown IDs. */
void fn_80012910(void) {
    fn_80007FF0(*(int *)((char *)fn_8001285C() + 8));
}

#define kClassifyThreshold lbl_80560358

#pragma dont_inline on
/* Classifies value against the 16.0 threshold: 2 when above it, 1 otherwise. */
int fn_80012938(float value) {
    if (value > kClassifyThreshold) {
        return 2;
    }
    return 1;
}
#pragma dont_inline reset

#pragma dont_inline fn_80012938
void fn_80012954(void) {
    /* Look up the data record tied to the first contest entry's event id, then
       classify the record's float field at 0x78 against the threshold. */
    char *record = fn_80012820(*(int *)((char *)fn_8001285C() + 4));
    fn_80012938(*(float *)(record + 0x78));
}

#pragma use_lmw_stmw off
/* Initialize/load resource data for the given id, append optional extra paths,
 * snapshot counts, format per-entry strings when requested, and finalize setup. */
void fn_80012984(int arg0) {
    char pathBuf[0x80];
    register char *strBase = lbl_802FC610;
    register char *entry;
    register int i;
    void *resourceInfo;
    int extraPath;

    fn_8013C804();
    resourceInfo = fn_800126CC(arg0);
    lbl_8055D514 = 0;
    lbl_80558AD8 = *(int *)resourceInfo;
    lbl_8055D508 = 0;
    lbl_8055D51C = 0;
    lbl_8055D504 = 0;
    lbl_8055D518 = 0;

    extraPath = *(int *)((char *)resourceInfo + 8);
    if (extraPath != 0) {
        fn_80013618(extraPath);
    }
    if (fn_8019B3C() != 0) {
        fn_80013618((int)(strBase + 0x128));
    }
    if (fn_8019B54() != 0) {
        fn_80013618((int)(strBase + 0x138));
    }
    fn_80013724();
    lbl_8055D50C = (int)lbl_8055D504;
    lbl_8055D510 = lbl_8055D508;

    if (*(unsigned char *)((char *)resourceInfo + 0x11) != 0) {
        entry = lbl_80352AD0;
        for (i = 0; i < lbl_8055D510; entry += 0x28, i++) {
            fn_801345D8(pathBuf, 0x80, strBase + 0x144,
                        *(int *)((char *)resourceInfo + 4),
                        lbl_803518C0 + *(int *)(entry + 4) * 0x84 + 8,
                        fn_80007F90(*(int *)(entry + 8)));
        }
    }
    fn_80013A34();
    fn_8013C8B8();
    lbl_8055D500 = 1;
}

#pragma cplusplus on
#pragma dont_inline on
extern "C" int fn_80019B3C(void);
extern int lbl_80558AFC;
extern "C" char *strstr(const char *, const char *);
extern "C" int fn_80012AB4(void *object) {
    /* Returns whether the given object matches the current mode (by "vr" string containing mode name), or 1 if forced. */
    struct Dummy {
        virtual int f0();
        virtual int f1();
        virtual int f2();
        virtual int f3();
        virtual const char *f4(const char *, int);
    };
    void *modeEntry;
    char *modeName;
    int isEnabled;
    const char *valueStr;
    if (fn_80019B3C() != 0)
        return 1;
    modeEntry = fn_800126CC(lbl_80558AD8);
    modeName = *(char **)((char *)modeEntry + 4);
    isEnabled = *(unsigned char *)((char *)modeEntry + 0x10);
    valueStr = ((Dummy *)object)->f4((const char *)&lbl_80558AFC, 0);
    if (valueStr != 0) {
        isEnabled = 0;
        if (strstr(valueStr, modeName) != 0)
            isEnabled = 1;
    }
    return isEnabled;
}
#pragma dont_inline reset
#pragma cplusplus reset

extern void fn_8022D0D8(void *arg0, int arg1);
extern void fn_8022D0E8(void *arg0, int arg1, int arg2);
extern int fn_80137C54(int arg0);
extern int fn_800080E8(void *arg0);
extern int fn_8013C9A4(void);
extern int fn_8013C8E8(int arg0);
extern void fn_800135AC(char *arg0, void *arg1, char *arg2);
extern int fn_80008050(void);
extern float lbl_8056035C;
extern char lbl_80558B04[];
extern char lbl_80558B0C[];
extern char lbl_80558B14[];
extern char lbl_80558B1C[4];
extern char lbl_80558B24[];
extern char lbl_80558B30[];
extern char lbl_80558B38[];
extern char lbl_80558B40[];
extern char lbl_80558B48[];
extern char lbl_80558B50[];
extern char lbl_80558B58[];
extern char lbl_80558B60[];
extern int sprintf(char *, char *, ...);
extern char lbl_80558B04[4];
extern char lbl_80558B0C[4];
extern char lbl_80558B14[4];
extern char lbl_80558B24[4];
extern char lbl_80558B30[4];
extern char lbl_80558B38[4];
extern char lbl_80558B40[4];
extern char lbl_80558B48[4];
extern char lbl_80558B50[4];
extern char lbl_80558B58[4];
extern char lbl_80558B60[4];
#define H2(o, k) ((int (*)(void *, char *))*(void **)((char *)*(void **)(o) + 0xC))((o), (k))
#define H3(o, k, v) ((int (*)(void *, char *, int))*(void **)((char *)*(void **)(o) + 0xC))((o), (k), (v))
void fn_80012B50(void *arg0, int arg1, void *arg2, void *arg3) {
    char *obj = (char *)arg0;
    void *a2 = arg2;
    int a1 = arg1;
    void *a3 = arg3;
    register char *base = lbl_802FC610;
    char spD0[0x100];
    char buf10[0xC0];
    int spC;
    int sp8;
    int i;
    int sel;
    char *s;
    char *d;
    int n;
    int idx;
    char *entry;
    int temp;
    int cnt;
    char c;
    memset(obj, 0, 0x84);
    *(int *)obj = a1;
    fn_8022D0D8(spD0, 0x100);
    i = 0;
    do {
        fn_8022D0E8(spD0, 0x100, fn_80137C54(i) + 8);
        i++;
    } while (i < 4);
    if (((int (*)(void *, char *))*(void **)((char *)*(void **)a2 + 0xC))(a2, lbl_80558B04) != 0) {
        sel = ((int (*)(void *, char *, char *))*(void **)((char *)*(void **)a2 + 0x54))(a2, lbl_80558B04, spD0);
    } else {
        sel = 0;
    }
    *(int *)(obj + 4) = sel;
    s = ((char *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x14))(a2, lbl_80558B0C);
    d = obj + 8;
    n = 0x20;
    goto copy_body;
copy_dec:
    if (--n > 0) goto copy_body;
    *(--d) = 0;
    goto copy_done;
copy_body:
    c = *s++;
    *d++ = c;
    if ((signed char)c != 0) goto copy_dec;
copy_done:
    if (fn_800080E8(obj + 8) == -1) {
        Abend_Panic(base + 0x168, a3, obj + 8);
    }
    *(int *)(obj + 0x6C) = 1;
    *(int *)(obj + 0x68) = 1;
    if (((int (*)(void *, char *))*(void **)((char *)*(void **)a2 + 0xC))(a2, lbl_80558B14) != 0) {
        s = ((char *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x14))(a2, lbl_80558B14);
    } else {
        s = ((char *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x14))(a2, lbl_80558B1C);
    }
    strncpy(obj + 0x28, s, 0x40);
    obj[0x67] = 0;
    if (((int (*)(void *, char *))*(void **)((char *)*(void **)a2 + 0xC))(a2, base + 0x18C) != 0) {
        ((char *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x14))(a2, base + 0x18C);
        temp = fn_8013C9A4();
        *(int *)(obj + 0x74) = temp;
        if (temp == 6) {
            Abend_Panic(base + 0x198, a3, obj + 0x28);
        }
    } else {
        *(int *)(obj + 0x74) = 1;
    }
    *(float *)(obj + 0x78) = lbl_8056035C;
    *(void **)(obj + 0x7C) = ((void *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x5C))(a2, base + 0x1C8);
    if (*(void **)(obj + 0x7C) != 0) {
        idx = 0;
        do {
            if (fn_8013C8E8(spC) == 6) {
                Abend_Panic(base + 0x1D8, obj + 0x28, spC);
            }
            idx++;
        } while (((int (*)(void *, int, int *, int *))*(void **)((char *)*(void **)(*(void **)(obj + 0x7C)) + 0x10))(*(void **)(obj + 0x7C), idx, &spC, &sp8) != 0);
        if (idx > 7) {
            Abend_Panic(base + 0x208, obj + 0x28, idx, 7);
        }
    }
    *(void **)(obj + 0x80) = a2;
    fn_800135AC(base + 0x244, a2, obj + 0x28);
    fn_800135AC(lbl_80558B24, a2, obj + 0x28);
    fn_800135AC(lbl_80558B30, a2, obj + 0x28);
    fn_800135AC(base + 0x250, a2, obj + 0x28);
    fn_800135AC(base + 0x25C, a2, obj + 0x28);
    fn_800135AC(lbl_80558B38, a2, obj + 0x28);
    if ((H2(a2, base + 0x268) != 0 || H2(a2, base + 0x278) != 0) &&
        (H2(a2, base + 0x268) == 0 || H2(a2, base + 0x278) == 0)) {
        Abend_Panic(base + 0x284, obj + 0x28);
    }
    cnt = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)a2 + 0x20))(a2, base + 0x2C8, 0);
    idx = 0;
    {
        void *ch;
        while ((ch = ((void *(*)(void *, int))*(void **)((char *)*(void **)a2 + 0x60))(a2, idx)) != 0) {
            ((void (*)(void *))*(void **)((char *)*(void **)ch + 8))(ch);
            if (stricmp(((char *(*)(void *, char *))*(void **)((char *)*(void **)ch + 0xC))(ch, lbl_80558B40), 0) == 0) {
                if (lbl_8055D508 >= 0xFA) {
                    Abend_Panic(base + 0x2D8);
                }
                if (*(int *)(obj + 0x70) >= 0x40) {
                    Abend_Panic(base + 0x31C, obj + 0x28);
                }
                entry = &lbl_80352AD0[lbl_8055D508 * 0x28];
                *(int *)entry = lbl_8055D508;
                *(int *)(entry + 4) = *(int *)obj;
                entry[0x24] = 1;
                if (((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0xC))(ch, base + 0x244, lbl_8055D508) != 0) {
                    ((char *(*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x14))(ch, base + 0x244, lbl_8055D508);
                    temp = fn_80008050();
                    *(int *)(entry + 8) = temp;
                    if (temp == 0) {
                        Abend_Panic(base + 0x360, obj + 0x28, lbl_8055D508 + 1);
                    }
                } else {
                    Abend_Panic(base + 0x388, obj + 0x28, lbl_8055D508 + 1);
                }
                sprintf(buf10, lbl_80558B48, obj + 0x28, fn_80007FF0(*(int *)(entry + 8)));
                *(int *)(entry + 0xC) = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, lbl_80558B24, 0);
                *(int *)(entry + 0x10) = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, base + 0x25C, 8);
                if (*(int *)(entry + 0x10) > 8) {
                    Abend_Panic(base + 0x3B0, buf10, *(int *)(entry + 0x10), 8);
                }
                temp = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, base + 0x2C8, -1);
                *(int *)(entry + 0x14) = temp;
                if ((unsigned int)(temp + 0x10000) == 0xffffU) {
                    int t2 = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, base + 0x250, 0);
                    if (t2 != 0) {
                        *(int *)(entry + 0x14) = 1 << (t2 - 1);
                    } else {
                        *(int *)(entry + 0x14) = 0;
                    }
                }
                *(int *)(entry + 0x14) |= cnt;
                *(int *)(entry + 0x14) &= ~((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, base + 0x3D0, 0);
                *(int *)(entry + 0x18) = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, lbl_80558B50, 1);
                *(int *)(entry + 0x1C) = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, lbl_80558B38, 0x3E8);
                *(void **)(entry + 0x20) = ch;
                fn_800135AC(lbl_80558B04, ch, buf10);
                fn_800135AC(lbl_80558B58, ch, buf10);
                fn_800135AC(lbl_80558B60, ch, buf10);
                if ((H3(ch, base + 0x268, 0) != 0 || H3(ch, base + 0x278, 0) != 0) &&
                    (H3(ch, base + 0x268, 0) == 0 || H3(ch, base + 0x278, 0) == 0)) {
                    Abend_Panic(base + 0x3E8, buf10);
                }
                if ((*(int *)(entry + 8) & 0x400) != 0 && *(int *)(entry + 0x10) * 2 > 8) {
                    Abend_Panic(base + 0x428, buf10, *(int *)(entry + 0x10), 8);
                }
                lbl_8055D508++;
                *(int *)(obj + 0x70) += 1;
            }
            idx++;
        }
    }
    if (*(int *)(obj + 0x70) <= 0) {
        Abend_Panic(base + 0x468, obj + 0x28);
    }
}

#pragma cplusplus on
/* Value lookup through a virtual interface (same shape as getVirtualValue): when the
   object's +0xC predicate passes, return what its +0x1C method gives for
   `argument`; otherwise return the caller's `fallback`. */
extern "C" int fn_800132E4(void *object, int argument, int fallback) {
    struct VirtualObject {
        virtual int _08();
        virtual int isReady();
        virtual int _10();
        virtual int _14();
        virtual int _18();
        virtual int getValue(int index);
    };
    int result;
    if (((VirtualObject *)object)->isReady()) {
        result = ((VirtualObject *)object)->getValue(argument);
    } else {
        result = fallback;
    }
    return result;
}
#pragma cplusplus reset
extern char lbl_80558B1C[4];
extern char lbl_80558B68[4];
extern char lbl_80558B70[4];
extern char lbl_80558B78[4];
extern int stricmp();
extern int fn_8012C33C();
extern int fn_80012AB4();
extern void fn_80012B50();
#pragma cplusplus on
extern "C" void fn_8001335C(int a0, int arg1) {
    struct Dummy {
        virtual char *name();
        virtual void *child(int);
        virtual void *_10();
        virtual char *get(char *);
        virtual void set(char *, int);
    };
    int i;
    Dummy *obj;
    char *base = lbl_802FC610;
    int zero = 0;
    if (a0 != 0) {
        for (i = 0; (obj = (Dummy *)((Dummy *)a0)->child(i)) != 0; i++) {
            if (stricmp(obj->name(), lbl_80558B68) == 0) {
                if (fn_8012C33C(obj->get(lbl_80558B1C)) == 0)
                    Abend_Panic(base + 0x488, obj->get(lbl_80558B1C));
                obj->set(lbl_80558B1C, zero);
                ((void (*)())fn_80013618)();
            } else if (stricmp(obj->name(), lbl_80558B70) == 0) {
                if ((int)lbl_8055D504 >= 0x23)
                    Abend_Panic(base + 0x4B4, (int)lbl_8055D504 - 1);
                if (fn_80012AB4(obj) != 0) {
                    fn_80012B50(lbl_803518C0 + (int)lbl_8055D504 * 0x84, (int)lbl_8055D504, obj, arg1);
                    lbl_8055D504 = (void *)((int)lbl_8055D504 + 1);
                }
            } else if (stricmp(obj->name(), lbl_80558B78) == 0) {
                if (lbl_8055D518 >= 0x23)
                    Abend_Panic(base + 0x4E4, lbl_8055D518 - 1);
                if (fn_80012AB4(obj) != 0) {
                    fn_80012B50(lbl_803551E0 + lbl_8055D518 * 0x88, -1 - lbl_8055D518, obj, arg1);
                    *(int *)(lbl_803551E0 + lbl_8055D518 * 0x88 + 0x84) = zero;
                    lbl_8055D518 += 1;
                }
            } else if (stricmp(obj->name(), base + 0x524) == 0 && lbl_8055D514 == zero) {
                lbl_8055D514 = (int)obj;
            }
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_800135AC(char *fieldName, void *fieldChecker, char *ownerName) {
    /* Reports an error if the checker accepts fieldName: ownerName should not have that field. */
    struct FieldCheckerVTable {
        virtual int f0();
        virtual int Matches(char *);
    };
    if (((FieldCheckerVTable *)fieldChecker)->Matches(fieldName) != 0)
        Abend_Panic(lbl_802FCB50, ownerName, fieldName);
}
#pragma cplusplus reset
extern char lbl_802FCB74[];
extern int fn_8012C33C(void);
extern int getValueFile(int);
extern void fn_8001335C(int, int);
#pragma scheduling invalid_target
/* Registers an object: if enabled, stores its resolved handle in the global table and initializes it. */
void fn_80013618(int object) {
    int count;
    int handle;
    int *table;
    if (object == 0)
        return;
    if (fn_8012C33C() == 0)
        return;
    handle = getValueFile(object);
    table = (int *)lbl_8035183C;
    count = table[0x20];
    table[count] = handle;
    table[0x20] = count + 1;
    fn_8001335C(handle, object);
}

#pragma scheduling on
#pragma cplusplus on
/* qsort comparator: order records by the "display_order" attribute (default 99)
   of the child object at +0x80, read through virtual slot 6. */
extern "C" int fn_80013680(void *__restrict lhs, void *rhs) {
    struct DisplayOrderProvider {
        virtual int f0();
        virtual int f1();
        virtual int f2();
        virtual int f3();
        virtual int f4();
        virtual int f5();
        virtual int getDisplayOrder(char *, int);
    };
    void *provider = *(void **)((char *)lhs + 0x80);
    int lhsOrder = ((DisplayOrderProvider *)provider)->getDisplayOrder(lbl_802FCB74, 0x63);
    int rhsOrder = ((DisplayOrderProvider *)*(void **)((char *)rhs + 0x80))->getDisplayOrder(lbl_802FCB74, 0x63);
    return lhsOrder - rhsOrder;
}
#pragma cplusplus reset
#pragma scheduling invalid_target
/* qsort comparator: order records by the primary value at +0x68, breaking ties
 * with the secondary value at +0x6C. */
int fn_800136FC(void *lhs, void *rhs) {
    int rhsPrimary = ((int *)rhs)[0x1A];
    int lhsPrimary = ((int *)lhs)[0x1A];
    if (lhsPrimary == rhsPrimary) {
        return ((int *)lhs)[0x1B] - ((int *)rhs)[0x1B];
    }
    return lhsPrimary - rhsPrimary;
}

void fn_80013724(void) {
    char *base = lbl_80351828;
    if (lbl_80558AD8 == 0x133) {
        qsort(base + 0x98, (int)lbl_8055D504, 0x84, (void*)fn_80013680);
        qsort(base + 0x39B8, lbl_8055D518, 0x88, (void*)fn_80013680);
    } else if (lbl_80558AD8 == 0x130) {
        qsort(base + 0x98, (int)lbl_8055D504, 0x84, (void*)fn_800136FC);
        qsort(base + 0x39B8, lbl_8055D518, 0x88, (void*)fn_800136FC);
    }
    {
        int xcount = lbl_8055D508;
        char *entry = base + 0x12a8;
        int n1 = (int)lbl_8055D504;
        int n2 = lbl_8055D518;
        int x, found;
        char *p;
        int y;
        for (x = 0; x < xcount; entry += 0x28, x++) {
            found = 0;
            {
                p = base + 0x98;
                for (y = 0; y < n1; y++, p += 0x84) {
                    if (*(int *)p == *(int *)(entry + 4)) {
                        *(int *)(entry + 4) = y;
                        found = 1;
                        break;
                    }
                }
            }
            if (!found) {
                int y;
                char *p = base + 0x39b8;
                for (y = 0; y < n2; y++, p += 0x88) {
                    if (*(int *)p == *(int *)(entry + 4)) {
                        *(int *)(entry + 4) = -1 - y;
                        break;
                    }
                }
            }
        }
    }
    {
        int n = (int)lbl_8055D504;
        int i;
        char *p = base + 0x98;
        for (i = 0; i < n; i++, p += 0x84)
            *(int *)p = i;
    }
    {
        int n = lbl_8055D518;
        int i;
        for (i = 0; i < n; i++)
            *(int *)(base + 0x39b8 + i * 0x88) = -1 - i;
    }
}

extern int lbl_8055D518;
#pragma scheduling invalid_target
void fn_80013A34(void) {
    int p = (int)lbl_803551E0;
    int count = lbl_8055D518;
    int zero = 0;
    int blocks, i;
    if (count > 0) {
        blocks = (unsigned int)count >> 3;
        for (i = blocks; i != 0; i--) {
            *(int *)(p + 0x84) += *(int *)(p + 0x70); *(int *)(p + 0x70) = zero;
            *(int *)(p + 0x10C) += *(int *)(p + 0xF8); *(int *)(p + 0xF8) = zero;
            *(int *)(p + 0x194) += *(int *)(p + 0x180); *(int *)(p + 0x180) = zero;
            *(int *)(p + 0x21C) += *(int *)(p + 0x208); *(int *)(p + 0x208) = zero;
            *(int *)(p + 0x2A4) += *(int *)(p + 0x290); *(int *)(p + 0x290) = zero;
            *(int *)(p + 0x32C) += *(int *)(p + 0x318); *(int *)(p + 0x318) = zero;
            *(int *)(p + 0x3B4) += *(int *)(p + 0x3A0); *(int *)(p + 0x3A0) = zero;
            *(int *)(p + 0x43C) += *(int *)(p + 0x428); *(int *)(p + 0x428) = zero;
            p += 0x440;
        }
        i = count & 7;
        if (i != 0) {
            do {
                *(int *)(p + 0x84) += *(int *)(p + 0x70);
                *(int *)(p + 0x70) = zero;
                p += 0x88;
            } while (--i != 0);
        }
    }
    {
        char *entry = lbl_80352AD0;
        char *q;
        int x;
        for (x = 0; x < lbl_8055D508; entry += 0x28, x++) {
            int y;
            q = lbl_803551E0;
            for (y = 0; y < lbl_8055D518; y++, q += 0x88) {
                if (*(int *)(entry + 4) == *(int *)q)
                    entry[0x24] = zero;
            }
        }
    }
}
#pragma scheduling reset
extern char lbl_802FCB74[];
extern int fn_8012C33C(void);
extern int getValueFile(int);
extern void fn_8001335C(int, int);
