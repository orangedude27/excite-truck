// Code of main that had no source file yet: decomp.wtf gave it this one.

#pragma cplusplus on
struct Parser {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int has(const char *);
    virtual int enumerate(int, char **, int *);
    virtual const char *getString(const char *);
    virtual void slot6();
    virtual int getCount(const char *);
    virtual int getOption(const char *, int);
    virtual float getFloat(const char *);
    virtual float getFloatDef(const char *, float);
    virtual void slot11();
    virtual int getFlag(const char *, int);
};
// Same object seen through a vtable without the two leading destructor slots.
struct Parser2 {
    virtual void m0();
    virtual int has(const char *);
    virtual void m2();
    virtual const char *getString(const char *);
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual float getFloat(const char *);
    virtual float getFloatDef(const char *, float);
    virtual void m9();
    virtual int getFlag(const char *, int);
};
struct Parser72028 {
    virtual void _00();
    virtual int has(const char *);
    virtual int enumerate(int, char **, int *);
    virtual const char *getString(const char *);
    virtual void _10();
    virtual int getCount(const char *);
    virtual int getOption(const char *, int);
    virtual float getFloat(const char *);
    virtual float getFloatDef(const char *, float);
    virtual void _24();
    virtual int getFlag(const char *, int);
};
struct Manager {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void *getCamera() = 0;
};
extern "C" static inline void *callGetCamera(void *manager) {
    return ((Manager *)manager)->getCamera();
}
#pragma cplusplus reset

// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80271624(void);
extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
void *fn_801E87A8(void);
extern void fn_80136468(void **, void *, float);
void fn_8027156C();
#pragma push
#pragma small_data off
extern unsigned char lbl_8049A258[];
#pragma pop
#pragma push
#pragma small_data off
extern char lbl_8049F9D8[];
#pragma pop
extern int lbl_8055F554;
extern int lbl_8055F54C;
extern signed char lbl_8055F558;
extern float lbl_80563E78;
extern float lbl_80563F44;
extern unsigned char lbl_8055F564;
extern float lbl_8055F568;
extern unsigned char lbl_8055F559;
extern unsigned char lbl_8055F55A;
extern const char lbl_8055C59C[4];
extern const char lbl_80346D90[];
extern const char lbl_80346DC8[];
extern char lbl_8049EDC8[];
extern int fn_801B526C(void);
extern void fn_80136414(void *, void *, int);
extern int fn_801363A0(void *, void *);
extern void fn_802E30C8(const char *, ...);
extern int fn_80272C74(void *, void *, float *, int);
extern int fn_802710A0(void *, int);
void fn_80270AE8(void *arg0) {
    float value = lbl_80563E78;
    ((float *)arg0)[0] = value;
    ((float *)arg0)[1] = value;
    ((float *)arg0)[3] = value;
    ((float *)arg0)[2] = value;
}

void DBPrintf_80270B00(const char *fmt, ...) {
#pragma unused(fmt)
}

#pragma dont_inline on
int fn_80270B50(void) {
    return *(int *)((char *)fn_801E87A8() + 4);
}
#pragma dont_inline reset

#pragma push
#pragma small_data off
void fn_80270B74(void) {
    /* Clear all 32 slot pointers in the global table (stride 0x1C) and reset its entry count. */
    volatile int *table = (volatile int *)lbl_8049F9D8;

    *table = 0;
    *(volatile int *)((char *)table + 0x1C) = 0;
    *(volatile int *)((char *)table + 0x38) = 0;
    *(volatile int *)((char *)table + 0x54) = 0;
    *(volatile int *)((char *)table + 0x70) = 0;
    *(volatile int *)((char *)table + 0x8C) = 0;
    *(volatile int *)((char *)table + 0xA8) = 0;
    *(volatile int *)((char *)table + 0xC4) = 0;
    *(volatile int *)((char *)table + 0xE0) = 0;
    *(volatile int *)((char *)table + 0xFC) = 0;
    *(volatile int *)((char *)table + 0x118) = 0;
    *(volatile int *)((char *)table + 0x134) = 0;
    *(volatile int *)((char *)table + 0x150) = 0;
    *(volatile int *)((char *)table + 0x16C) = 0;
    *(volatile int *)((char *)table + 0x188) = 0;
    *(volatile int *)((char *)table + 0x1A4) = 0;
    *(volatile int *)((char *)table + 0x1C0) = 0;
    *(volatile int *)((char *)table + 0x1DC) = 0;
    *(volatile int *)((char *)table + 0x1F8) = 0;
    *(volatile int *)((char *)table + 0x214) = 0;
    *(volatile int *)((char *)table + 0x230) = 0;
    *(volatile int *)((char *)table + 0x24C) = 0;
    *(volatile int *)((char *)table + 0x268) = 0;
    *(volatile int *)((char *)table + 0x284) = 0;
    *(volatile int *)((char *)table + 0x2A0) = 0;
    *(volatile int *)((char *)table + 0x2BC) = 0;
    *(volatile int *)((char *)table + 0x2D8) = 0;
    *(volatile int *)((char *)table + 0x2F4) = 0;
    *(volatile int *)((char *)table + 0x310) = 0;
    *(volatile int *)((char *)table + 0x32C) = 0;
    *(volatile int *)((char *)table + 0x348) = 0;
    *(volatile int *)&lbl_8055F554 = 0;
    *(volatile int *)((char *)table + 0x364) = 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
void fn_80270C04(void *arg0, unsigned int arg1) {
    extern char lbl_80346B00[];
    extern char lbl_8049EDC8[];
    extern char lbl_8049F9D8[];
    extern int lbl_8055F550;
    extern unsigned char lbl_8055F564;
    extern void fn_80272738(void *, void *);
    register char *table;
    register char *name = lbl_80346B00;
    register char *record;
    register unsigned char flag;

    fn_80270B74();
    if (0 == lbl_8055F550)
        return;
    flag = (arg1 >> 8) & 1;
    lbl_8055F564 = flag;
    DBPrintf_80270B00(name + 0x1E0);
    record = lbl_8049EDC8;
    table = lbl_8049F9D8;
    arg1 = 0;
    while ((int)arg1 < lbl_8055F550) {
        char *slot;
        DBPrintf_80270B00(name + 0x1F8, arg1);
        DBPrintf_80270B00(name + 0x208);
        *(char **)(table + lbl_8055F554 * 0x1C) = record;
        slot = table + lbl_8055F554 * 0x1C;
        if (flag)
            fn_80272738(slot, arg0);
        record += 0x60;
        arg1++;
        lbl_8055F554++;
    }
    if (lbl_8055F554 == 0) {
        DBPrintf_80270B00(name + 0x224);
        *(int *)lbl_8049F9D8 = (int)lbl_8049EDC8;
        if (flag)
            fn_80272738(lbl_8049F9D8, arg0);
        lbl_8055F554 = 1;
    }
}
#pragma pop
int fn_80270D1C(int arg0) {
    switch (arg0) {
    case 0: return 1;
    case 1: return 2;
    default: return 0;
    }
}

#pragma peephole off
int fn_80270D4C(void *arg0, void *arg1) {
    float *right;
    float *left;
    if (*((unsigned char *)arg1 + 4) != 0) {
        right = (float *)(*(char **)arg1 + 0xC);
    } else {
        right = (float *)(*(char **)arg1 + 4);
    }
    if (*((unsigned char *)arg0 + 4) != 0) {
        left = (float *)(*(char **)arg0 + 0xC);
    } else {
        left = (float *)(*(char **)arg0 + 4);
    }
    return (int)(*left - *right);
}
#pragma peephole reset
extern float lbl_80563F40;
#pragma scheduling invalid_target
void fn_80270DB0(void *arg0, void *arg1, float delta) {
    /* Update a shared clamped value for two nodes, using alternating record offsets selected by each node's flag. */
    unsigned char flag = *(unsigned char *)((char *)arg0 + 4);
    char *record;
    float *valuePtr, *otherValuePtr;
    float value, otherValue, average;

    if (flag) {
        record = *(char **)arg0;
        valuePtr = (float *)(record + 0x10);
    } else {
        record = *(char **)arg0;
        valuePtr = (float *)(record + 8);
    }
    value = *valuePtr;

    if (*(unsigned char *)((char *)arg1 + 4)) {
        otherValuePtr = (float *)(*(char **)arg1 + 0xC);
    } else {
        otherValuePtr = (float *)(*(char **)arg1 + 4);
    }
    otherValue = *otherValuePtr;

    if (flag) {
        valuePtr = (float *)(record + 0xC);
    } else {
        valuePtr = (float *)(record + 4);
    }
    if (value < *valuePtr) {
        value += delta;
    }

    if (flag) {
        valuePtr = (float *)(record + 0xC);
    } else {
        valuePtr = (float *)(record + 4);
    }
    if (otherValue < *valuePtr) {
        otherValue += delta;
    }

    if (flag) {
        valuePtr = (float *)(record + 0xC);
    } else {
        valuePtr = (float *)(record + 4);
    }

    average = lbl_80563F40 * (value + otherValue);
    if (*valuePtr > average) {
        otherValue = *valuePtr;
    } else {
        otherValue = average;
    }

    if (otherValue >= delta) {
        otherValue -= delta;
    }

    if (flag) {
        valuePtr = (float *)(record + 0x10);
    } else {
        valuePtr = (float *)(record + 8);
    }
    *valuePtr = otherValue;

    if (*(unsigned char *)((char *)arg1 + 4)) {
        otherValuePtr = (float *)(*(char **)arg1 + 0xC);
    } else {
        otherValuePtr = (float *)(*(char **)arg1 + 4);
    }
    *otherValuePtr = otherValue;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
int fn_80270EC4(void *arg0, int arg1) {
    struct SortEntry {
        char *record;
        unsigned char special;
        unsigned char pad[3];
    };
    extern char lbl_80346B00[];
    extern char lbl_8049F9D8[];
    extern int lbl_8055F554;
    extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
    struct SortEntry entries[64];
    register char *name = lbl_80346B00;
    register int flags = arg1;
    register int category, groupOffset, one, zero, count, byteOffset, i;
    fn_80270C04(arg0, flags);
    if ((flags & 0x100) != 0) {
        category = 0;
        groupOffset = 0;
        one = 1;
        zero = 0;
        do {
            char *record = lbl_8049F9D8;
            count = 0;
            byteOffset = 0;
            i = 0;
            while (i < *(volatile int *)&lbl_8055F554) {
                if (category == fn_80270D1C(*(int *)(*(char **)record + 0x5C))) {
                    struct SortEntry *out = (struct SortEntry *)((char *)entries + byteOffset);
                    out->record = record;
                    out->special = zero;
                    if (*(unsigned char *)(record + 0x14) != 0) {
                        byteOffset += 8;
                        out = (struct SortEntry *)((char *)entries + byteOffset);
                        out->record = out[-1].record;
                        out->special = one;
                        count++;
                    }
                    count++;
                    byteOffset += 8;
                }
                record += 0x1C;
                i++;
            }
            if (count > 0) {
                int j;
                int last;
                void *basePtr;
                char *entriesPtr;
                float threshold;
                qsort(entries, count, 8, (int (*)(const void *, const void *))fn_80270D4C);
                basePtr = *(void **)((char *)arg0 + 0x2C);
                entriesPtr = (char *)entries;
                last = count - 1;
                threshold = *(float *)((char *)basePtr + groupOffset + 8);
                for (j = 0; j < last; j++) {
                    fn_80270DB0(&entries[j], &entries[j + 1], threshold);
                }
                fn_80270DB0(&entries[last], &entries[0], threshold);
                (void)entriesPtr;
            }
            category++;
            groupOffset += 4;
        } while (category < 3);
        DBPrintf_80270B00(name + 0x250, lbl_8055F554);
        {
            int j;
            char *record = lbl_8049F9D8;
            for (j = 0; j < *(volatile int *)&lbl_8055F554; j++, record += 0x1C) {
                DBPrintf_80270B00(name + 0x268, j,
                                  *(float *)(record + 4), *(float *)(record + 8));
                if (*(unsigned char *)(record + 0x14) != 0) {
                    DBPrintf_80270B00(name + 0x27C, j,
                                      *(float *)(record + 0xC), *(float *)(record + 0x10));
                }
            }
        }
    }
}

int fn_802710A0(void *arg0, int arg1) {
    struct { void *first; float second; int third; } sp18;
    struct { void *first; float second; int third; } spC;
    float sp8;
    float f31_val;
    float var_f30;
    float var_f29;
    void *p;
    int var_r29;
    int var_r28;
    int var_r27;
    int var_r26;
    int i;

    var_f30 = lbl_80563F44;
    var_f29 = var_f30;
    var_r29 = 0;
    var_r28 = 0;
    var_r27 = -1;
    var_r26 = -1;

    if (lbl_8055F564 != 0) {
        void *manager = *(void **)((char *)arg0 + 0x270);
        void **vtable = *(void ***)manager;
        float *dest;
        p = ((void *(*)(void *))vtable[6])(manager);
        dest = &lbl_8055F568;
        if (fn_801B526C() != 0) {
            fn_80136414(&sp18, p, *(int *)((char *)arg0 + 0x2678));
            *dest = *(float *)((char *)sp18.first + 0x1C) + *(float *)((char *)sp18.first + 0x18) * sp18.second;
        } else {
            int offset = fn_801363A0(p, (char *)p + 4);
            fn_80136414(&spC, p, offset);
            *dest = *(float *)((char *)spC.first + 0x1C) + *(float *)((char *)spC.first + 0x18) * spC.second;
        }
    }

    f31_val = lbl_80563F48;
    p = lbl_8049F9D8;
    for (i = 0; i < lbl_8055F554; p = (char *)p + 0x1C, i++) {
        sp8 = f31_val;
        if (fn_80272C74(p, arg0, &sp8, arg1) != 0) {
            if (var_r29 == 0 || var_f30 < sp8) {
                var_f30 = sp8;
                var_r27 = i;
                var_r29 = 1;
            }
        } else if (var_r29 == 0) {
            if (var_r28 == 0 || var_f29 < sp8) {
                if (*(int *)(*(char **)p + 0x58) != 0) {
                    var_f29 = sp8;
                    var_r26 = i;
                    var_r28 = 1;
                }
            }
        }
    }

    if (var_r29 == 0) {
        var_r29 = var_r28;
        var_r27 = var_r26;
    }

    if (var_r29 == 0) {
        if (arg1 != -1) {
            if (lbl_8055F559 == 0) {
                lbl_8055F559 = 1;
                fn_802E30C8(lbl_8055C59C, lbl_80346D90);
            }
            return fn_802710A0(arg0, -1);
        }
        if (lbl_8055F55A == 0) {
            lbl_8055F55A = 1;
            fn_802E30C8(lbl_8055C59C, lbl_80346DC8);
        }
        return -1;
    }

    return ((unsigned int)*(char **)((char *)lbl_8049F9D8 + var_r27 * 0x1C) - (unsigned int)lbl_8049EDC8) / 96U;
}

#pragma push
#pragma small_data on
extern const char lbl_8055C5A0[];
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_802712F8(void *arg0) {
    class Item { public: virtual const char *getName(); };
    class Iterator { public: virtual void unused(); virtual Item *next(int); };
    extern char lbl_80346B00[];
    extern char lbl_8049A2C8[];
    extern char lbl_8049EDC8[];
    extern const char lbl_8055C59C[4];
    extern const char lbl_8055C5A0[1];
    extern int lbl_8055F548;
    extern int lbl_8055F550;
    extern unsigned char lbl_8055F55B;
    extern int fn_8012C33C(void *);
    extern void *fn_80131808(void *);
    extern void fn_80131818(void *);
    extern int fn_80272028(void *, void *);
    extern int fn_80272DCC(void *, void *);
    extern void fn_80277740(void);
    extern int fn_80277754(void *);
    extern void fn_80277828(void);
    extern void fn_802E30C8(const char *, ...);
    extern int stricmp(const char *, const char *);
    register char *strings = lbl_80346B00;
    lbl_8055F550 = 0;
    lbl_8055F548 = 0;
    fn_80277740();
    if (fn_8012C33C(arg0) != 0) {
        register Iterator *iterator = (Iterator *)fn_80131808(arg0);
        register char *tableA = lbl_8049A2C8;
        register char *tableB = lbl_8049EDC8;
        register Item *item;
        register int index = 0;
        while ((item = iterator->next(index)) != 0) {
            if (stricmp(item->getName(), lbl_8055C5A0) == 0) {
                if (fn_80272DCC(tableA + lbl_8055F548 * 0x60, item) != 0)
                    lbl_8055F548 += 1;
            } else if (stricmp(item->getName(), strings + 0x2FC) == 0) {
                if (fn_80272028(tableB + lbl_8055F550 * 0x60, item) != 0)
                    lbl_8055F550 += 1;
            } else if (fn_80277754(item) == 0) {
                fn_802E30C8(strings + 0x30C, item->getName());
            }
            index += 1;
        }
        fn_80131818(iterator);
    } else if (fn_8012C33C(strings + 0x334) != 0) {
        register Iterator *iterator = (Iterator *)fn_80131808(strings + 0x334);
        register char *tableA = lbl_8049A2C8;
        register Item *item;
        register int index = 0;
        while ((item = iterator->next(index)) != 0) {
            if (stricmp(item->getName(), lbl_8055C5A0) == 0) {
                if (lbl_8055F548 < 0xC8) {
                    if (fn_80272DCC(tableA + lbl_8055F548 * 0x60, item) != 0)
                        lbl_8055F548 += 1;
                    else
                        fn_802E30C8(strings + 0x340, index);
                } else if (lbl_8055F55B == 0) {
                    lbl_8055F55B = 1;
                    fn_802E30C8(lbl_8055C59C, strings + 0x370);
                }
            }
            index += 1;
        }
        fn_80131818(iterator);
    }
    fn_80277828();
}
#pragma pop

#pragma dont_inline reset
#pragma pop

#pragma scheduling on
extern char lbl_80346E90[];
void fn_802712F8(void *);
void fn_8027156C(void) {
    fn_802712F8(lbl_80346E90);
}

typedef signed int s32;
typedef unsigned char u8;
void *fn_80178C9C(void);
s32 fn_80270EC4(void *, s32);
void fn_80271578(void) {
    s32 temp_r31;
    void *temp_r30;
    void *temp_r3;
    temp_r3 = fn_80178C9C();
    temp_r31 = *(s32 *)((u8 *)temp_r3 + 0xC);
    temp_r30 = temp_r3;
    fn_80270EC4(temp_r30, fn_80270B50());
    *(s32 *)((u8 *)temp_r30 + 0xC) = temp_r31;
}

typedef float f32;
extern f32 lbl_80563F4C;
void fn_802715C4(void *arg0, void *arg1)
{
  f32 a = *((f32 *) (((u8 *) arg1) + 0x14));
  f32 b = lbl_80563F4C;
  f32 c = *((f32 *) (((u8 *) arg1) + 0x10));
  f32 d = *((f32 *) (((u8 *) arg1) + 0xC));
  f32 x = b * a;
  f32 y = b * c;
  f32 z;
  *((f32 *) (((u8 *) arg0) + 8)) = x;
  z = d;
  z = b * z;
  *((f32 *) (((u8 *) arg0) + 0)) = z;
  *((f32 *) (((u8 *) arg0) + 4)) = y;
}

extern f32 lbl_8055F540;
extern f32 lbl_8055F544;
f32 fn_802715F0(void *arg0) {
    f32 b;
    f32 c;
    f32 a;
    a = *(f32 *)((u8 *)arg0 + 0x18);
    b = lbl_80563F4C;
    c = lbl_8055F544;
    c = (c < b * a) ? b * a : c;
    c = (c > lbl_8055F540) ? c : lbl_8055F540;
    return c;
}

int fn_80271FAC(const char *arg0) {
    char **entry = lbl_80346B54;
    int i = 0;
    do {
        if ((i != 11) && (stricmp(arg0, *entry) == 0)) return i;
        ++i;
        ++entry;
    } while (i < 18);
    return 11;
}

#pragma cplusplus on
extern "C" void fn_80272354(void *);
extern "C" unsigned char fn_80008050(int);
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void DBPrintf_80270B00(const char *, ...);
extern "C" char lbl_80346B00[];
extern "C" char lbl_8055C5A4[];
extern "C" char lbl_8055C5AC[];
extern "C" char lbl_8055C5B4[];
extern "C" int fn_80272028(void *arg0, Parser *arg1, int arg_sp0) {
    char *path;
    int hash;
    char buffer[0x30];
    char *name;
    Parser *parser;
    void *output;
    int index;
    int count;
    unsigned char bit;
    name = lbl_80346B00;
    parser = arg1;
    output = arg0;

    #pragma unused(arg_sp0)
    fn_80272354(arg0);

    if (parser->has(name + 0x424) == 0) {
        DBPrintf_80270B00(name + 0x430, name + 0x424);
        return 0;
    }
    *(float *)output = parser->getFloat(name + 0x424);

    if (parser->has(name + 0x464) == 0) {
        DBPrintf_80270B00(name + 0x430, name + 0x464);
        return 0;
    }
    *(float *)((char *)output + 4) = parser->getFloat(name + 0x464);

    if (parser->has(name + 0x470) == 0) {
        DBPrintf_80270B00(name + 0x430, name + 0x470);
        return 0;
    }
    *(float *)((char *)output + 8) = parser->getFloat(name + 0x470);

    if (parser->has(lbl_8055C5A4) == 0) {
        DBPrintf_80270B00(name + 0x430, lbl_8055C5A4);
        return 0;
    }
    *(float *)((char *)output + 0xC) = parser->getFloat(lbl_8055C5A4);
    *(int *)((char *)output + 0x5C) = parser->getOption(lbl_8055C5AC, 2);

    index = 0;
    for (;;) {
        if (parser->enumerate(index, &path, &hash) == 0) {
            break;
        }
        if (strncmp(path, lbl_8055C5B4, 5) == 0 &&
            path[5] != '_') {
            bit = fn_80008050(hash);
            if (bit < 0x20) {
                *(int *)((char *)output + 0x10) |= 1 << bit;
            } else {
                *(int *)((char *)output + 0x14) |= 1 << (bit - 0x20);
            }
        }
        index++;
    }

    if (parser->has(name + 0x47C) == 0) {
        DBPrintf_80270B00(name + 0x430, name + 0x47C);
        return 0;
    }
    count = parser->getCount(name + 0x47C);
    *(int *)((char *)output + 0x58) = count;

    for (index = 0; index < count; index++) {
        sprintf(buffer, name + 0x48C, index);
        if (parser->has(buffer) == 0) {
            DBPrintf_80270B00(name + 0x430, buffer);
            return 0;
        }
        *(int *)((char *)output + 0x18 + index * 4) =
            parser->getCount(buffer);
    }
    return 1;
}
#pragma cplusplus reset

extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
void fn_80272354(void *arg0) {
    float other = 10.0f;
    float value = 0.0f;
    *(float *)((char *)arg0 + 0x0) = value;
    *(float *)((char *)arg0 + 0x4) = value;
    *(float *)((char *)arg0 + 0x8) = value;
    *(float *)((char *)arg0 + 0xC) = other;
    memset((char *)arg0 + 0x10, 0, 8);
    *(int *)((char *)arg0 + 0x58) = 0;
    *(int *)((char *)arg0 + 0x5C) = 2;
}

#pragma scheduling invalid_target
void fn_802723B4(void *arg0, void *arg1) {
    void *slot;
    void *object;
    register float factor;
    register float base;
    ((void (*)(void **, void *))fn_80136468)(&slot, arg0);
    object = slot;
    factor = *(float *)((char *)&slot + 4);
    base = *(float *)object;
    *(float *)arg1 = base + (*(float *)*(void **)((char *)object + 0x14) - base) * factor;
    base = *(float *)((char *)object + 4);
    *(float *)((char *)arg1 + 4) = base + (*(float *)((char *)*(void **)((char *)object + 0x14) + 4) - base) * factor;
}
#pragma scheduling on
extern float lbl_8055F560, lbl_80563F40, lbl_80563F48;
extern void fn_80136468(void **, void *, float);
#pragma ppc_psq_save off
#pragma ppc_psq_save off
float fn_80272428(void *arg0, void *arg1, float a, float b, float radius) {
    struct Result { void *node; float fraction; s32 mode; };
    struct Point { float x; float y; };
    float period = *(float *)((u8 *)*(void **)((u8 *)arg0 + 0x2C) + 8);
    struct Result resultA;
    struct Result resultB;
    volatile struct Point pointA;
    volatile struct Point deltaA;
    volatile struct Point pointB;
    volatile struct Point deltaB;
    void *node;
    void *next;
    float fraction;
    float x;
    float y;
    float dx;
    float dy;
    float squareX;
    float squareY;
    double tmpD;
    float distA;
    float distB;
    float mid;
    register float argA = a;
    register float argB = b;
    register float argR = radius;
    if (argA > argB) {
        float span = argB - (argA - period);
        if (span * span < lbl_8055F560) return argA;
    } else {
        float span = argB - argA;
        if (span * span < lbl_8055F560) return argA;
    }
    fn_80136468((void **)&resultA, arg0, argA);
    next = *(void **)((u8 *)(node = resultA.node) + 0x14);
    fraction = resultA.fraction;
    x = *(float *)node + fraction * (*(float *)next - *(float *)node);
    y = *(float *)((u8 *)node + 4) + fraction * (*(float *)((u8 *)next + 4) - *(float *)((u8 *)node + 4));
    dx = x - *(float *)arg1;
    pointA.x = x;
    dy = y - *(float *)((u8 *)arg1 + 4);
    pointA.y = y;
    squareX = dx * dx;
    deltaA.x = dx;
    squareY = dy * dy;
    deltaA.y = dy;
    tmpD = __fabs((double)(argR - (squareX + squareY)));
    distA = (float)tmpD;
    if (distA < lbl_8055F560) return argA;
    fn_80136468((void **)&resultB, arg0, argB);
    next = *(void **)((u8 *)(node = resultB.node) + 0x14);
    fraction = resultB.fraction;
    x = *(float *)node + fraction * (*(float *)next - *(float *)node);
    y = *(float *)((u8 *)node + 4) + fraction * (*(float *)((u8 *)next + 4) - *(float *)((u8 *)node + 4));
    dx = x - *(float *)arg1;
    pointB.x = x;
    dy = y - *(float *)((u8 *)arg1 + 4);
    pointB.y = y;
    squareX = dx * dx;
    deltaB.x = dx;
    squareY = dy * dy;
    deltaB.y = dy;
    tmpD = __fabs((double)(argR - (squareX + squareY)));
    distB = (float)tmpD;
    if (distB < lbl_8055F560) return argB;
    if (argA > argB) {
        mid = (argB + (argA - period)) * lbl_80563F40;
        if (mid < lbl_80563F48) mid += period;
    } else {
        mid = (argA + argB) * lbl_80563F40;
    }
    if (distA < distB) return fn_80272428(arg0, arg1, argA, mid, argR);
    return fn_80272428(arg0, arg1, mid, argB, argR);
}
#pragma ppc_psq_save reset
#pragma ppc_psq_save reset
extern char lbl_8034705C[];
extern void fn_802723B4(void *, void *);
void fn_8027264C(int arg0, void *arg1, float farg0) {
    float value;
    fn_802723B4(arg1, &value);
    DBPrintf_80270B00(lbl_8034705C, arg0, farg0, value, *(float *)((char *)&value + 4));
}

#pragma dont_inline on
s32 fn_802726AC(f32 farg0, f32 farg1, f32 farg2) {
    if (farg1 < farg2) {
        return (farg1 < farg0) && (farg0 < farg2);
    }
    return (farg1 > farg0) && (farg0 > farg2);
}
#pragma dont_inline reset

extern int fn_802726AC(float, float, float);
int fn_802726EC(float farg0, float farg1, float farg2) {
    int result = 0;
    if (farg0 == farg1 || farg0 == farg2 || fn_802726AC(farg0, farg1, farg2) != 0) {
        result = 1;
    }
    return result;
}

extern float lbl_80558DC4[];
extern float lbl_80563F40, lbl_80563F48, lbl_80563F50, lbl_80563F8C, lbl_80563F90;
extern double fabs(double);
extern double fn_8002F234(void);
extern void fn_801355C0(void *, void *, int, void **, int);
extern void *memmove(void *, void *, int);
void fn_80272738(void *arg0, void *arg1) {
    int sp58;
    float sp54;
    void *sp50;
    float sp4C;
    float sp48;
    float sp44;
    float sp40;
    float sp3C;
    float sp38;
    float sp34;
    float sp30;
    float sp2C;
    float sp28;
    float sp24;
    float sp20;
    float sp18;
    float sp14;
    float sp10;
    float spC;
    float sp8;
    int var_r18;
    int var_r19;
    int var_r20;
    int var_r21;
    void *var_r22;
    void *var_r23;
    void *var_r24;
    float *var_r25;
    void *r26;
    char *base;
    float *dc4;
    int var_r29;
    float f23;
    float f24;
    float f25;
    float f26;
    float f27;
    float f28;
    float f29;
    float f30;
    float f31;
    void *r5;
    float t1;
    void *r5_2;
    base = lbl_80346B00;
    dc4 = lbl_80558DC4;
    r5 = *(void **)arg0;
    t1 = *(float *)((char *)r5 + 8);
    sp48 = *(float *)r5;
    sp4C = t1;
    r5_2 = *(void **)arg0;
    f27 = *(float *)((char *)r5_2 + 0xC);
    f28 = *(float *)((char *)*(void **)((char *)arg1 + 0x2C) + 8);
    f26 = f27 * f27;
    *(int *)((char *)arg1 + 0xC) = fn_80270D1C(*(int *)((char *)r5_2 + 0x5C));
    var_r23 = arg0;
    var_r21 = 0;
    f23 = lbl_80563F8C;
    r26 = *(void **)((char *)*(void **)((char *)arg1 + 0x2C) + 0x1C);
    var_r20 = 0;
    f29 = lbl_80563F48;
    f30 = lbl_80563F50;
    f31 = lbl_80563F90;
    var_r22 = r26;
    do {
        void *r3;
        float f7;
        float f3;
        float f8;
        float f5;
        float f6;
        float f7_2;
        float f9;
        float f4;
        float f6_2;
        float f8_2;
        float f3_2;
        float f5_2;
        float fabs25;
        float sqrtResult;
        r3 = *(void **)((char *)var_r22 + 0x14);
        var_r19 = 0;
        f7 = *(float *)var_r22;
        f3 = *(float *)r3 - f7;
        f8 = *(float *)((char *)var_r22 + 4);
        f5 = *(float *)((char *)r3 + 4) - f8;
        f6 = f7 + f29 * f3;
        f7_2 = f7 + f30 * f3;
        f9 = f8 + f29 * f5;
        sp40 = f6;
        f4 = f6 - sp48;
        f6_2 = f7_2 - f6;
        f8_2 = f8 + f30 * f5;
        f3_2 = f9 - sp4C;
        sp38 = f7_2;
        f5_2 = f8_2 - f9;
        sp44 = f9;
        sp3C = f8_2;
        f25 = f6_2 * f6_2 + f5_2 * f5_2;
        sp30 = f6_2;
        fabs25 = (float)fabs(f25);
        f24 = f23 * (f4 * f6_2 + f3_2 * f5_2);
        sp34 = f5_2;
        sp28 = f4;
        sp2C = f3_2;
        if (fabs25 != dc4[0] && f24 * f24 - f31 * f25 * (f4 * f4 + f3_2 * f3_2 - f26) > f29) {
            sqrtResult = (float)fn_8002F234();
            var_r19 = 2;
            sp20 = (-f24 - sqrtResult) / (f23 * f25);
            sp24 = (-f24 + sqrtResult) / (f23 * f25);
        }
        var_r24 = var_r23;
        var_r25 = &sp20;
        var_r29 = var_r21 * 4;
        var_r18 = 0;
        while (var_r18 < var_r19) {
            if (fn_802726EC(*var_r25, lbl_80563F48, lbl_80563F50) != 0) {
                if (var_r21 < 4) {
                    *(float *)((char *)arg0 + var_r29 + 4) = *(float *)((char *)var_r22 + 0x1C) + *(float *)((char *)var_r22 + 0x18) * *var_r25;
                    var_r21 += 1;
                    DBPrintf_80270B00(base + 0x578, *(float *)((char *)var_r24 + 4));
                    var_r24 = (char *)var_r24 + 4;
                    var_r29 += 4;
                    var_r23 = (char *)var_r23 + 4;
                } else {
                    DBPrintf_80270B00(base + 0x590);
                }
            }
            var_r25 += 1;
            var_r18 += 1;
        }
        {
            void *next = *(void **)((char *)var_r22 + 0x14);
            int prev10 = *(int *)((char *)var_r22 + 0x10);
            var_r22 = next;
            if (next == r26 || var_r21 >= 4 || *(int *)((char *)next + 0x10) == 0) {
                var_r20 = 1;
            } else if (*(int *)((char *)next + 0x10) < prev10) {
                DBPrintf_80270B00(base + 0x5B8);
                var_r20 = 1;
            }
        }
    } while (var_r20 == 0);
    if (var_r21 == 0) {
        float temp;
        float f1;
        float f24b;
        DBPrintf_80270B00(base + 0x5EC);
        sp50 = 0;
        sp58 = 0x2710;
        sp54 = lbl_80563F48;
        fn_801355C0(arg1, &sp48, 0, &sp50, 0);
        temp = *(float *)((char *)sp50 + 0x1C) + *(float *)((char *)sp50 + 0x18) * sp54;
        f23 = temp;
        f1 = temp - f27;
        if (f27 > temp) f1 += f28;
        f24b = temp + f27;
        if (f27 > f28 - temp) f24b -= f28;
        *(float *)((char *)arg0 + 4) = fn_80272428(arg1, &sp48, f1, temp, f26);
        *(float *)((char *)arg0 + 8) = fn_80272428(arg1, &sp48, temp, f24b, f26);
        var_r21 = 2;
    } else if (var_r21 == 1) {
        var_r21 += 1;
        *(float *)((char *)arg0 + 8) = *(float *)((char *)arg0 + 4);
    } else if (var_r21 == 3) {
        var_r21 += 1;
        *(float *)((char *)arg0 + 0x10) = *(float *)((char *)arg0 + 0xC);
    }
    if (var_r21 > 2) {
        DBPrintf_80270B00(base + 0x61C);
        *(unsigned char *)((char *)arg0 + 0x14) = 1;
    } else {
        *(unsigned char *)((char *)arg0 + 0x14) = 0;
    }
    {
        float a = *(float *)((char *)arg0 + 4);
        float d = *(float *)((char *)arg0 + 8);
        ((void (*)(void *, void *, float))fn_802723B4)(arg1, &sp18, lbl_80563F40 * (a + d));
        sp14 = *(float *)((char *)&sp18 + 4) - sp4C;
        sp10 = sp18 - sp48;
        if (sp10 * sp10 + sp14 * sp14 > f26) {
            if (*(unsigned char *)((char *)arg0 + 0x14) != 0) {
                float b = *(float *)((char *)arg0 + 8);
                float c = *(float *)((char *)arg0 + 0xC);
                ((void (*)(void *, void *, float))fn_802723B4)(arg1, &sp18, lbl_80563F40 * (b + c));
                spC = *(float *)((char *)&sp18 + 4) - sp4C;
                sp8 = sp18 - sp48;
                if (sp8 * sp8 + spC * spC > f26) {
                    *(unsigned char *)((char *)arg0 + 0x14) = 0;
                } else {
                    float old = *(float *)((char *)arg0 + 4);
                    memmove((char *)arg0 + 4, (char *)arg0 + 8, 0xC);
                    *(float *)((char *)arg0 + 0x10) = old;
                }
            }
            if (*(unsigned char *)((char *)arg0 + 0x14) == 0) {
                float old = *(float *)((char *)arg0 + 4);
                *(float *)((char *)arg0 + 4) = *(float *)((char *)arg0 + 8);
                *(float *)((char *)arg0 + 8) = old;
            }
        }
    }
    DBPrintf_80270B00(base + 0x634, sp48, sp4C);
    fn_8027264C((int)(base + 0x65C), arg1, *(float *)((char *)arg0 + 4));
    fn_8027264C((int)(base + 0x668), arg1, *(float *)((char *)arg0 + 8));
    if (*(unsigned char *)((char *)arg0 + 0x14) != 0) {
        fn_8027264C((int)(base + 0x674), arg1, *(float *)((char *)arg0 + 0xC));
        fn_8027264C((int)(base + 0x684), arg1, *(float *)((char *)arg0 + 0x10));
    }
}

#pragma dont_inline on
int fn_80272C24(float farg0, float farg1, float farg2, float farg3) {
    int result;
    if (farg1 == farg2) return 1;
    if (farg1 > farg2) {
        if (farg1 > farg0) farg1 -= farg3;
        else farg2 += farg3;
    }
    result = 0;
    if ((farg0 >= farg1) && (farg0 <= farg2)) result = 1;
    return result;
}
#pragma dont_inline reset

extern unsigned char lbl_8055F564;
extern float lbl_8055F568;
extern float lbl_80563F50;
extern float PSQUATMultiply(void *, void *);
extern int fn_80272C24(float, float, float, float);
#pragma cplusplus on
#pragma push
#pragma processor 750
#pragma scheduling on
extern "C" int fn_80272C74(void *arg0, void *arg1, float *arg2, int arg3) {
    struct Manager {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *getCamera() = 0;
    };
    float height;
    int result;

    *arg2 = lbl_80563F48;
    if (*(int *)((char *)*(void **)arg0 + 0x58) == 0) return 0;
    if (arg3 != -1 && arg3 != *(int *)((char *)*(void **)arg0 + 0x5C)) return 0;
    result = 1;
    if (lbl_8055F564 != 0) {
        void *manager = *(void **)((char *)arg1 + 0x270);
        void *camera = ((Manager *)manager)->getCamera();
        camera = *(void **)((char *)camera + 0x2C);
        height = *(float *)((char *)camera + 8);
        if (fn_80272C24(lbl_8055F568, *(float *)((char *)arg0 + 4), *(float *)((char *)arg0 + 8), height) != 0 ||
            (*(unsigned char *)((char *)arg0 + 0x14) != 0 &&
             fn_80272C24(lbl_8055F568, *(float *)((char *)arg0 + 0xC), *(float *)((char *)arg0 + 0x10), height) != 0)) {
            *arg2 = lbl_80563F50;
            return 1;
        }
        result = 0;
    }
    {
        float value = PSQUATMultiply((char *)arg1 + 0x60, *(void **)arg0) -
                      *(float *)((char *)*(void **)arg0 + 0xC);
        if (value <= lbl_80563F48) *arg2 = lbl_80563F50;
        else *arg2 = lbl_80563F50 / (lbl_80563F50 + value);
    }
    return result;
}

#pragma cplusplus on
extern "C" char lbl_8055C5BC[4];
extern "C" char lbl_8055C5C0[4];
extern "C" char lbl_8055C5C4[4];
extern "C" char lbl_8055C5C8[8];
extern "C" char lbl_8055C5D0[8];
extern "C" char lbl_8055C5D8[8];
extern "C" char lbl_8055C5E0[8];
extern "C" char lbl_8055C5E8[8];
extern "C" char lbl_8055C5F0[8];
extern "C" char lbl_8055C5F8[8];
extern "C" char lbl_8055C600[8];
extern "C" char lbl_8055C608[4];
extern "C" char lbl_8055C60C[4];
extern "C" char lbl_8055C610[4];
extern "C" char lbl_8055C614[8];
extern "C" char lbl_8055C61C[8];
extern "C" char lbl_8055C624[8];
extern "C" char lbl_8055C62C[8];
extern "C" float lbl_80563F94;
extern "C" float lbl_80563F98;
extern "C" float lbl_80563F50;
#pragma processor gekko
extern "C" int fn_80272DCC(void *arg0, Parser2 *arg1) {
    char *name = lbl_80346B00;
    Parser2 *p = arg1;
    char *o = (char *)arg0;
    int a, b, c, d;
    unsigned char flags;

    if (p->has(lbl_8055C5BC) != 0 && p->has(lbl_8055C5C0) != 0 && p->has(lbl_8055C5C4) != 0
        && (p->has(lbl_8055C5C8) != 0 || p->has(lbl_8055C5D0) != 0) && p->has(lbl_8055C5D8) != 0) {
        *(float *)o = p->getFloat(lbl_8055C5BC);
        *(float *)(o + 4) = p->getFloat(lbl_8055C5C0);
        *(float *)(o + 8) = p->getFloat(lbl_8055C5C4);
        if (p->has(lbl_8055C5D0) != 0) {
            *(float *)(o + 0x18) = p->getFloat(lbl_8055C5D0);
        } else {
            *(float *)(o + 0x18) = lbl_80563F94 * p->getFloat(lbl_8055C5C8);
        }
        *(int *)(o + 0x58) = fn_80271FAC(p->getString(lbl_8055C5D8));
        *(float *)(o + 0xC) = p->getFloatDef(lbl_8055C5E0, lbl_80563F48);
        *(float *)(o + 0x10) = p->getFloatDef(lbl_8055C5E8, lbl_80563F48);
        *(float *)(o + 0x14) = p->getFloatDef(lbl_8055C5F0, lbl_80563F50);
        a = p->getFlag(name + 0x690, 0);
        b = p->getFlag(lbl_8055C5F8, 0);
        c = p->getFlag(lbl_8055C600, 0);
        d = p->getFlag(name + 0x69C, 0);
        flags = (a | ((-b | b) >> 31) & 2) | (((-c | c) >> 31) & 4);
        flags |= (((-d | d) >> 31) & 8);
        *(unsigned char *)(o + 0x1D) = flags;
        switch (*(int *)(o + 0x58)) {
        case 13:
            *(unsigned char *)(o + 0x1D) = flags | 2;
            *(int *)(o + 0x58) = 1;
            break;
        case 14:
            *(int *)(o + 0x58) = 2;
            *(unsigned char *)(o + 0x1D) = flags | 2;
            break;
        case 15:
            *(unsigned char *)(o + 0x1D) = flags | 2;
            *(int *)(o + 0x58) = 3;
            break;
        case 12:
            *(unsigned char *)(o + 0x1D) = flags | 4;
            *(int *)(o + 0x58) = 0;
            break;
        }
        if (p->has(lbl_8055C608) != 0 && p->has(lbl_8055C60C) != 0 && p->has(lbl_8055C610) != 0) {
            *(unsigned char *)(o + 0x1C) = 1;
            *(float *)(o + 0x20) = *(float *)o;
            *(float *)(o + 0x24) = *(float *)(o + 4);
            *(float *)(o + 0x28) = *(float *)(o + 8);
            *(float *)(o + 0x38) = *(float *)(o + 0xC);
            *(float *)(o + 0x3C) = *(float *)(o + 0x10);
            *(float *)(o + 0x40) = *(float *)(o + 0x14);
            *(float *)(o + 0x50) = *(float *)(o + 0x18);
            *(float *)(o + 0x2C) = p->getFloatDef(lbl_8055C608, *(float *)o);
            *(float *)(o + 0x30) = p->getFloatDef(lbl_8055C60C, lbl_80563F98 + *(float *)(o + 4));
            *(float *)(o + 0x34) = p->getFloatDef(lbl_8055C610, *(float *)(o + 8));
            if (p->has(name + 0x6A8) != 0) {
                *(float *)(o + 0x54) = p->getFloat(name + 0x6A8);
            } else if (p->has(lbl_8055C614) != 0) {
                *(float *)(o + 0x54) = lbl_80563F94 * p->getFloat(lbl_8055C614);
            } else {
                *(float *)(o + 0x54) = *(float *)(o + 0x50);
            }
            *(float *)(o + 0x44) = p->getFloatDef(lbl_8055C61C, *(float *)(o + 0x38));
            *(float *)(o + 0x48) = p->getFloatDef(lbl_8055C624, *(float *)(o + 0x3C));
            *(float *)(o + 0x4C) = p->getFloatDef(lbl_8055C62C, *(float *)(o + 0x40));
        } else {
            *(unsigned char *)(o + 0x1C) = 0;
        }
        return 1;
    }
    return 0;
}
#pragma cplusplus reset

#pragma pop
#pragma cplusplus reset

void fn_80273354(void) {
    unsigned char *ptr = lbl_8049A258;
    memset(ptr, 0, 0x64);
    *(int *)(ptr + 0x1C) = 1;
    *(int *)(ptr + 0x18) = 0;
    *(int *)(ptr + 0x2C) = 1;
    *(int *)(ptr + 0x30) = 1;
    *(int *)(ptr + 0x40) = 2;
    *(int *)(ptr + 0x44) = 3;
    *(int *)(ptr + 0x54) = 5;
    *(int *)(ptr + 0x58) = 3;
    ((void (*)(int, int, int, unsigned char *))fn_8027156C)(3, 2, 1, ptr);
}

extern int lbl_8055F54C;
#pragma dont_inline on
void fn_802733C8(void) {
    fn_80271578();
    lbl_8055F54C = 0x12;
}
#pragma dont_inline reset
void fn_802733F0(void) {
}

void fn_802733F4(void *arg0) {
    /* Advance the region-group cursor for this event (if allowed) and mark
     * the object when the group has multiple regions; always clear the gate. */
    unsigned char *rec;
    s32 idx;
    s32 v;
    s32 lim;
    if (*(unsigned char *)((char *)arg0 + 0x138) != 0)
        goto clear;
    if (*(unsigned char *)&lbl_8055F558 == 0)
        goto clear;
    idx = fn_80273494(*(int *)((char *)arg0 + 0x10));
    if (idx == 6)
        goto clear;
    rec = lbl_8049A258 + idx * 0x14;
    v = *(int *)(rec + 0xC) + 1;
    *(int *)(rec + 0xC) = v;
    lim = *(int *)(rec + 0x8);
    if (v < lim)
        goto check;
    *(int *)(rec + 0xC) = 0;
check:
    if (*(int *)(rec + 0x8) <= 1)
        goto clear;
    *(unsigned char *)((char *)arg0 + 0x138) = 1;
clear:
    lbl_8055F558 = 0;
}

void fn_80273490(void) {
    fn_80271624();
}

#pragma dont_inline on
int fn_80273494(int arg0) {
    switch (arg0) {
    case 11: return 0;
    case 12: return 1;
    case 13: return 2;
    case 14: return 3;
    case 15: return 4;
    default: return 6;
    }
}
#pragma dont_inline reset

/* The five region groups of the event types fn_80273494 maps 11..15 onto (the table at
 * 0x8049A258).  A group is the run of region records from `start` to `start + count` in
 * the table at 0x80346BA0; `cursor` is which of them is current.  fn_80273354 fills the
 * groups in and fn_802733F4 advances a cursor, wrapping it back to 0 at `count`. */
typedef struct RegionGroup {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 start;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 cursor;
} RegionGroup;

/* One region record of the table at 0x80346BA0 (0x28 bytes): the kind of region it is --
 * fn_80273604 switches on it (0, 2, 4, 5, 7 and 0x22) --, where and how big it is, and
 * two per-record flags whose meaning the readers only show through the bit masks they
 * build (fn_802734F0 reports 0x1 when flag24 is clear and 0x4 when flag25 is). */
typedef struct RegionRecord {
    /* 0x00 */ s32 kind;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ f32 pos[3];
    /* 0x14 */ f32 dir[3];
    /* 0x20 */ f32 scale;
    /* 0x24 */ u8 flag24;
    /* 0x25 */ u8 flag25;
    /* 0x26 */ short unk26;
} RegionRecord;

#pragma push
#pragma small_data off
#pragma dont_inline on
/* A four-bit report on the region an event type is pointed at: 0x1 when that record's
 * flag24 is clear, 0x4 when its flag25 is clear, 0x2 when it is a kind-2 region and 0x8
 * when it is a kind-0 one -- or 0x8 for every type while lbl_8055F480 is set.  An event
 * type with no region group of its own (fn_80273494's 6, and 0, which type 11 shares)
 * answers from its kind alone: kind 0 gives 0x8, kind 1 nothing, kind 2 0x6 and anything
 * else 0x5 -- the same bits a record with both flags clear and another kind would give.
 * The repeated `eventType == 1` test is the original's; the target keeps the dead branch
 * it leaves, so the if-chain below stands in for its switch on the event type. */
int fn_802734F0(int eventType) {
    extern unsigned char lbl_8055F480;
    extern unsigned char lbl_80346BA0[];
    int group = fn_80273494(eventType);
    int flags = 0;
    RegionGroup *entry;
    RegionRecord *state;

    if (lbl_8055F480 != 0) {
        flags |= 8;
    } else if (group != 6 && group != 0) {
        entry = (RegionGroup *)(lbl_8049A258 + group * 0x14);
        state = (RegionRecord *)(lbl_80346BA0 + (entry->cursor + entry->start) * 0x28);
        if (state->flag24 == 0)
            flags |= 1;
        else if (state->kind == 2)
            flags |= 2;
        else if (state->kind == 0)
            flags |= 8;
        if (state->flag25 == 0)
            flags |= 4;
    } else {
        if (eventType == 1) goto done;
        if (eventType == 1) goto fallback;
        if (eventType >= 1) goto check3;
        if (eventType < 0) goto fallback;
        goto flag8;
check3:
        if (eventType >= 3) goto fallback;
        flags |= 6;
        goto done;
flag8:
        flags |= 8;
        goto done;
fallback:
        flags |= 5;
    }
done:
    return flags;
}
#pragma dont_inline reset
#pragma pop
void fn_802735F4(int arg0, signed char arg1) {
    if (arg0 == 0) {
        lbl_8055F558 = arg1;
    }
}

#pragma scheduling invalid_target
void fn_80273604(void *arg0, s32 arg1) {
    extern float PSVECMag(float *);
    extern double sin(float), cos(float);
    extern void fn_80015B20(void *, float *, void *);
    extern void fn_801BFD34(void *, float *, void *);
    extern void fn_802704D0();
    extern void fn_802704D4(s32, void *);
    extern s32 fn_80273494(s32);
    extern void fn_80273BD0(void);
    extern void fn_80274268(void);
    extern void fn_802E30C8(const char *, ...);
    extern unsigned char lbl_8049A258[];
    extern u8 lbl_80346BA0[];
    extern char lbl_80347310[];
    extern float lbl_80563F48, lbl_80563F4C, lbl_80563F50, lbl_80563F9C;
    u8 *table;
    u8 *state;
    table = (u8 *)&lbl_8049A258 + arg1 * 0x14;
    state = lbl_80346BA0 + ((*(s32 *)(table + 4) + *(s32 *)(table + 0xC))) * 0x28;
    switch (*(s32 *)state) {
    case 0x22: {
        struct Scratch { float vec[3]; float pad; float matrix[9]; float pos[3]; } scratch;
        float scale = lbl_80563F4C;
        float mag, nx, ny, nz, sine, cosine, oneMinusCos, t0, t1, t2, t3, t4, t5;
        *(s32 *)((u8 *)arg0 + 88) = *(s32 *)((u8 *)arg0 + 192); *(s32 *)((u8 *)arg0 + 92) = *(s32 *)((u8 *)arg0 + 196); *(s32 *)((u8 *)arg0 + 96) = *(s32 *)((u8 *)arg0 + 200); *(s32 *)((u8 *)arg0 + 100) = *(s32 *)((u8 *)arg0 + 204);
        *(s32 *)((u8 *)arg0 + 104) = *(s32 *)((u8 *)arg0 + 208); *(s32 *)((u8 *)arg0 + 108) = *(s32 *)((u8 *)arg0 + 212); *(s32 *)((u8 *)arg0 + 112) = *(s32 *)((u8 *)arg0 + 216); *(s32 *)((u8 *)arg0 + 116) = *(s32 *)((u8 *)arg0 + 220);
        *(s32 *)((u8 *)arg0 + 120) = *(s32 *)((u8 *)arg0 + 224); *(s32 *)((u8 *)arg0 + 124) = *(s32 *)((u8 *)arg0 + 228); *(s32 *)((u8 *)arg0 + 128) = *(s32 *)((u8 *)arg0 + 232); *(s32 *)((u8 *)arg0 + 132) = *(s32 *)((u8 *)arg0 + 236);
        scratch.pos[0] = *(float *)(state + 8);
        scratch.pos[1] = *(float *)(state + 0xC);
        scratch.pos[2] = *(float *)(state + 0x10);
        scratch.vec[0] = *(float *)(state + 0x14) * scale;
        scratch.vec[1] = *(float *)(state + 0x18) * scale;
        scratch.vec[2] = *(float *)(state + 0x1C) * scale;
        nz = PSVECMag(scratch.vec);
        if (nz > lbl_80563F9C) {
            t0 = lbl_80563F50 / nz;
            nx = t0 * scratch.vec[0]; ny = t0 * scratch.vec[1]; mag = t0 * scratch.vec[2];
            sine = (float)sin(nz);
            cosine = (float)cos(nz);
            oneMinusCos = lbl_80563F50 - cosine;
            t1 = sine * mag;
            t2 = oneMinusCos * nx;
            t3 = ny * t2;
            scratch.matrix[0] = cosine + (oneMinusCos * (nx * nx));
            t4 = mag * t2;
            t5 = sine * ny;
            scratch.matrix[1] = t3 + t1;
            t0 = mag * (oneMinusCos * ny);
            t2 = sine * nx;
            scratch.matrix[3] = t3 - t1;
            scratch.matrix[2] = t4 - t5;
            scratch.matrix[4] = cosine + (oneMinusCos * (ny * ny));
            scratch.matrix[5] = t0 + t2;
            scratch.matrix[6] = t4 + t5;
            scratch.matrix[7] = t0 - t2;
            scratch.matrix[8] = cosine + (oneMinusCos * (mag * mag));
        } else {
            scratch.matrix[1] = lbl_80563F48;
            scratch.matrix[0] = lbl_80563F50;
            scratch.matrix[2] = lbl_80563F48;
            scratch.matrix[3] = lbl_80563F48;
            scratch.matrix[4] = lbl_80563F50;
            scratch.matrix[5] = lbl_80563F48;
            scratch.matrix[6] = lbl_80563F48;
            scratch.matrix[7] = lbl_80563F48;
            scratch.matrix[8] = lbl_80563F50;
        }
        fn_801BFD34((u8 *)arg0 + 0x7C, scratch.pos, (u8 *)arg0 + 0xC0);
        fn_80015B20((u8 *)arg0 + 0x58, scratch.matrix, (u8 *)arg0 + 0xC0);
        *(float *)((u8 *)arg0 + 0xBC) = *(float *)(state + 0x20) * lbl_80563F4C;
        return;
    }
    case 0:
        fn_80273BD0();
        return;
    case 2:
        fn_80274268();
        return;
    case 4:
    case 5:
    case 7: {
        s32 other = fn_80273494(*(s32 *)((u8 *)arg0 + 4));
        if (other != 6 && other != 0 && other != arg1) {
            u8 *otherTable = (u8 *)&lbl_8049A258 + other * 0x14;
            u8 *otherState = lbl_80346BA0 + ((*(s32 *)(otherTable + 4) + *(s32 *)(otherTable + 0xC))) * 0x28;
            fn_802704D0(*(s32 *)state, *(s32 *)otherState, arg0, *(s32 *)(otherTable + 4));
        } else {
            s32 wrap = *(s32 *)(table + 8);
            s32 start2 = *(s32 *)(table + 4);
            s32 count2 = *(s32 *)(table + 0xC);
            s32 index = start2 + ((wrap + count2 - 1) % wrap);
            u8 *prevState = lbl_80346BA0 + index * 0x28;
            fn_802704D0(*(s32 *)state, *(s32 *)prevState, arg0, start2, wrap);
        }
        return;
    }
    default:
        fn_802E30C8(lbl_80347310, *(s32 *)state);
        fn_802704D4(4, arg0);
        return;
    }
}
extern int fn_80128668(void);
int fn_80273978(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma push
#pragma small_data off
extern char lbl_8049F9D8[];
#pragma pop
#pragma push
#pragma small_data off
extern unsigned char lbl_8049A258[];
#pragma pop
extern int lbl_8055F554;
extern f32 lbl_80563E78;
extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
typedef struct { void **v; } Obj;
typedef int (*Has)(Obj *, const char *);
typedef float (*Get)(Obj *, const char *);
typedef int (*Find)(Obj *, const char *, int);
typedef float (*Get3)(Obj *, const char *, float,float,float,float,float,float,float);
extern int lbl_8055F548;
extern int lbl_8055F550;
extern unsigned char lbl_8055F55B;

