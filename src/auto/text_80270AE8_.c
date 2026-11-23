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

extern void fn_80271624(int, void *);
extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
#define sCamTypeNames lbl_80346B54

enum CamType {
    CAM_TYPE_FIXED = 0,
    CAM_TYPE_PAN = 1,
    CAM_TYPE_ZOOM = 2,
    CAM_TYPE_CLOSEUP = 3,
    CAM_TYPE_CHASE = 4,
    CAM_TYPE_IN_CAR = 5,
    CAM_TYPE_TWIRL = 6,
    CAM_TYPE_WHEEL = 7,
    CAM_TYPE_REV_WHEEL = 8,
    CAM_TYPE_BUTT = 9,
    CAM_TYPE_HELI = 10,
    CAM_TYPE_MAX = 11,
    CAM_TYPE_R_FIXED = 12,
    CAM_TYPE_S_PAN = 13,
    CAM_TYPE_S_ZOOM = 14,
    CAM_TYPE_S_CLOSEUP = 15,
    CAM_TYPE_HOOD = 16,
    CAM_TYPE_FLYCAM = 17,
    CAM_TYPE_COUNT = 18
};
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
/* Zero all four components of vec (a 4-float vector). lbl_80563E78 is 0.0f. */
void fn_80270AE8(void *vec) {
    float zero = lbl_80563E78;
    ((float *)vec)[0] = zero;
    ((float *)vec)[1] = zero;
    ((float *)vec)[3] = zero;
    ((float *)vec)[2] = zero;
}

/* Debug printf stub (no-op). */
void DBPrintf_80270B00(const char *format, ...) {
#pragma unused(format)
}

#pragma dont_inline on
int fn_80270B50(void) {
    /* Return the mode/type (a CamType) at +4 of the current camera object from fn_801E87A8. */
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
void fn_80270C04(void *context, int options) {
    /* Dump the debug record list: print a header, then for each of lbl_8055F550 0x60-byte records
       at lbl_8049EDC8 store its pointer into a 0x1C-byte slot of the table at lbl_8049F9D8,
       optionally printing each record's detail via fn_80272738 when bit 8 of options is set. */
    extern char lbl_80346B00[];
    extern char lbl_8049EDC8[];
    extern char lbl_8049F9D8[];
    extern int lbl_8055F550;
    extern unsigned char lbl_8055F564;
    extern void fn_80272738(void *, void *);
    register char *table;
    register char *strings = lbl_80346B00;
    register char *record;
    register unsigned char printDetails;
    int recordCount;

    fn_80270B74();
    recordCount = lbl_8055F550;
    if (recordCount == 0)
        return;
    printDetails = (options >> 8) & 1;
    lbl_8055F564 = printDetails;
    DBPrintf_80270B00(strings + 0x1E0, recordCount);
    record = lbl_8049EDC8;
    table = lbl_8049F9D8;
    options = 0;
    while (options < lbl_8055F550) {
        char *slot;
        DBPrintf_80270B00(strings + 0x1F8, options);
        DBPrintf_80270B00(strings + 0x208);
        *(char **)(table + lbl_8055F554 * 0x1C) = record;
        slot = table + lbl_8055F554 * 0x1C;
        if (printDetails != 0)
            fn_80272738(slot, context);
        record += 0x60;
        options++;
        lbl_8055F554++;
    }
    if (lbl_8055F554 == 0) {
        DBPrintf_80270B00(strings + 0x224);
        *(int *)lbl_8049F9D8 = (int)lbl_8049EDC8;
        if (printDetails != 0)
            fn_80272738(lbl_8049F9D8, context);
        lbl_8055F554 = 1;
    }
}
#pragma pop
int fn_80270D1C(int sourceType) {
    /* Map a record's raw type (its +0x5C field) to a display category:
     * type 0 -> 1, type 1 -> 2, anything else -> 0. */
    switch (sourceType) {
    case 0: return 1;
    case 1: return 2;
    default: return 0;
    }
}

#pragma peephole on
int fn_80270D4C(void *leftEntry, const void *rightEntry) {
    /* qsort comparator: order sort entries by the float in each record selected by the entry's "special" flag at +4. */
    float *rightValue;
    float *leftValue;
    if (*((const unsigned char *)rightEntry + 4) != 0) {
        rightValue = (float *)(*(char * const *)((const char *)rightEntry) + 0xC);
    } else {
        rightValue = (float *)(*(char * const *)((const char *)rightEntry) + 4);
    }
    if (*((unsigned char *)leftEntry + 4) != 0) {
        leftValue = (float *)(*(char **)leftEntry + 0xC);
    } else {
        leftValue = (float *)(*(char **)leftEntry + 4);
    }
    return (int)(*leftValue - *rightValue);
}
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
    register int one, zero;
    register char *name = lbl_80346B00;
    register int flags = arg1;
    register int category, groupOffset, count, byteOffset, i;
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
                qsort(entries, count, 8, (int (*)(const void *, const void *))fn_80270D4C);
                last = count - 1;
                {
                    float threshold = *(float *)((char *)*(void **)((char *)arg0 + 0x2C) + groupOffset + 8);
                    for (j = 0; j < last; j++) {
                        fn_80270DB0(&entries[j], &entries[j + 1], threshold);
                    }
                    fn_80270DB0(&entries[last], &entries[0], threshold);
                }
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

#pragma cplusplus on
/*
 * find_best_region() of the "TV Set 1" camera module: pick the region the
 * subject should be judged by and return its index in the region array
 * lbl_8049EDC8 (stride 0x60), or -1 when there is no region at all.
 *
 * When the table was built with a camera (lbl_8055F564), the point the camera
 * ray hits is worked out first and left in lbl_8055F568, which is what
 * fn_80272C74 scores the regions against.  Every slot of the live table
 * lbl_8049F9D8 (stride 0x1C, lbl_8055F554 of them) is then scored once:
 *   - the highest-scoring region fn_80272C74 accepts wins outright
 *     (bestScore / bestIndex);
 *   - otherwise the highest-scoring region that is switched on (its +0x58) is
 *     kept as a fallback (fallbackScore / fallbackIndex);
 *   - with neither, and a group wanted, the search is repeated over every group
 *     (group = -1, the CG_ANY of the two debug strings) after complaining once;
 *     a second failure complains once more and gives up with -1.
 */
extern "C" int fn_802710A0(void *subject, int group) {
    struct { void *region; float t; int slot; } alongRay;
    struct { void *region; float t; int slot; } alongPath;
    float score;
    float scoreWhenUnscored;
    float bestScore;
    float fallbackScore;
    void *p; /* the camera first, then the table slot being scanned */
    int found;
    int foundFallback;
    int bestIndex;
    int fallbackIndex;
    int i;
    bestScore = lbl_80563F44;
    fallbackScore = bestScore;
    found = 0;
    foundFallback = 0;
    bestIndex = -1;
    fallbackIndex = -1;
    if (lbl_8055F564 != 0) {
        float *dest;
        p = (*(Manager **)((char *)subject + 0x270))->getCamera();
        dest = &lbl_8055F568;
        if (fn_801B526C() != 0) {
            fn_80136414(&alongRay, p, *(int *)((char *)subject + 0x2678));
            *dest = *(float *)((char *)alongRay.region + 0x1C) + *(float *)((char *)alongRay.region + 0x18) * alongRay.t;
        } else {
            int offset = fn_801363A0(p, (char *)p + 4);
            fn_80136414(&alongPath, p, offset);
            *dest = *(float *)((char *)alongPath.region + 0x1C) + *(float *)((char *)alongPath.region + 0x18) * alongPath.t;
        }
    }
    scoreWhenUnscored = lbl_80563F48;
    p = lbl_8049F9D8;
    for (i = 0; i < lbl_8055F554; p = (char *)p + 0x1C, i++) {
        score = scoreWhenUnscored;
        if (fn_80272C74(p, subject, &score, group) != 0) {
            if (found == 0 || bestScore < score) {
                bestScore = score;
                bestIndex = i;
                found = 1;
            }
        } else if (found == 0) {
            if (foundFallback == 0 || fallbackScore < score) {
                if (*(int *)(*(char **)p + 0x58) != 0) {
                    fallbackScore = score;
                    fallbackIndex = i;
                    foundFallback = 1;
                }
            }
        }
    }
    if (found == 0) {
        found = foundFallback;
        bestIndex = fallbackIndex;
    }
    if (found == 0) {
        if (group != -1) {
            if (lbl_8055F559 == 0) {
                lbl_8055F559 = 1;
                fn_802E30C8(lbl_8055C59C, lbl_80346D90);
            }
            return fn_802710A0(subject, -1);
        }
        if (lbl_8055F55A == 0) {
            lbl_8055F55A = 1;
            fn_802E30C8(lbl_8055C59C, lbl_80346DC8);
        }
        return -1;
    }
    return ((unsigned int)*(char **)((char *)lbl_8049F9D8 + bestIndex * 0x1C) - (unsigned int)lbl_8049EDC8) / 96U;
}
#pragma cplusplus reset
#pragma push
#pragma small_data on
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern const char lbl_8055C5A0[];
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
/* Load camera and region definitions from a parsed node tree into the camera/region tables. */
extern "C" void fn_802712F8(void *rootNode) {
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
    register char *cameraTable;
    register char *regionTable;
    register Iterator *iterator;
    register Item *node;
    register int index;
    register char *stringBase = lbl_80346B00;
    lbl_8055F550 = 0;
    lbl_8055F548 = 0;
    fn_80277740();
    if (fn_8012C33C(rootNode) != 0) {
        iterator = (Iterator *)fn_80131808(rootNode);
        cameraTable = lbl_8049A2C8;
        regionTable = lbl_8049EDC8;
        index = 0;
        while ((node = iterator->next(index)) != 0) {
            if (stricmp(node->getName(), lbl_8055C5A0) == 0) {
                if (fn_80272DCC(cameraTable + lbl_8055F548 * 0x60, node) != 0)
                    lbl_8055F548 += 1;
            } else if (stricmp(node->getName(), stringBase + 0x2FC) == 0) {
                if (fn_80272028(regionTable + lbl_8055F550 * 0x60, node) != 0)
                    lbl_8055F550 += 1;
            } else if (fn_80277754(node) == 0) {
                fn_802E30C8(stringBase + 0x30C, node->getName());
            }
            index += 1;
        }
        fn_80131818(iterator);
    } else if (fn_8012C33C(stringBase + 0x334) != 0) {
        register Iterator *iterator;
        register Item *node;
        register int index;
        register char *cameraTable;
        iterator = (Iterator *)fn_80131808(stringBase + 0x334);
        cameraTable = lbl_8049A2C8;
        index = 0;
        while ((node = iterator->next(index)) != 0) {
            if (stricmp(node->getName(), lbl_8055C5A0) == 0) {
                if (lbl_8055F548 < 0xC8) {
                    if (fn_80272DCC(cameraTable + lbl_8055F548 * 0x60, node) != 0)
                        lbl_8055F548 += 1;
                    else
                        fn_802E30C8(stringBase + 0x340, index);
                } else if (lbl_8055F55B == 0) {
                    lbl_8055F55B = 1;
                    fn_802E30C8(lbl_8055C59C, stringBase + 0x370);
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
/* Populate the camera and region tables by traversing the "camera3.val"
   resource (fn_802712F8 resets the tables, then collects its entries). */
void fn_8027156C(void) {
    fn_802712F8(lbl_80346E90);
}

typedef signed int s32;
typedef unsigned char u8;
void *fn_80178C9C(void);
s32 fn_80270EC4(void *, s32);
/* RealName: fn_80271578 (reinitialize current object state while preserving a field) */
void fn_80271578(void) {
#define savedField temp_r31
#define obj temp_r30
#define getCurrentObject fn_80178C9C
    /* Reinitialize the current object via fn_80270EC4/fn_80270B50, preserving its field at offset 0xC. */
    s32 savedField;
    void *obj;
    void *temp_r3;
    temp_r3 = getCurrentObject();
    savedField = *(s32 *)((u8 *)temp_r3 + 0xC);
    obj = temp_r3;
    fn_80270EC4(obj, fn_80270B50());
    *(s32 *)((u8 *)obj + 0xC) = savedField;
#undef savedField
#undef obj
#undef getCurrentObject
}

typedef float f32;
extern f32 lbl_80563F4C;
#define DEG_TO_RAD lbl_80563F4C /* pi / 180: converts degrees to radians */
#pragma opt_propagation off
/* Convert the three angles (degrees) in effect at +0xC/+0x10/+0x14 to radians
   by multiplying with lbl_80563F4C (pi/180), and store them to out[0..2]. */
void fn_802715C4(void *out, void *effect)
{
  f32 scale, degX, degY, degZ;
  f32 radZ, radY, radX;
  degZ = *((f32 *) (((u8 *) effect) + 0x14));
  scale = lbl_80563F4C;
  degY = *((f32 *) (((u8 *) effect) + 0x10));
  degX = *((f32 *) (((u8 *) effect) + 0xC));
  radZ = scale * degZ;
  radY = scale * degY;
  radX = scale * degX;
  *((f32 *) (((u8 *) out) + 8)) = radZ;
  *((f32 *) (((u8 *) out) + 0)) = radX;
  *((f32 *) (((u8 *) out) + 4)) = radY;
}
#pragma opt_propagation reset
extern f32 lbl_8055F540;
extern f32 lbl_8055F544;
f32 fn_802715F0(void *effect) {
    /* Return the effect field at +0x18 scaled by lbl_80563F4C and clamped to [lbl_8055F544, lbl_8055F540]. */
    f32 scaled;
    f32 result;
    f32 raw;
    raw = *(f32 *)((u8 *)effect + 0x18);
    scaled = lbl_80563F4C;
    result = lbl_8055F544;
    scaled *= raw;
    result = (result < scaled) ? result : scaled;
    result = (result > lbl_8055F540) ? result : lbl_8055F540;
    return result;
}

#pragma cplusplus on
extern "C" int fn_802E2C20(void);
extern "C" int lbl_8055F548;
extern "C" unsigned char lbl_8055F55C;
extern "C" unsigned char lbl_8055F480;
extern "C" float lbl_8055C598;
extern "C" float lbl_80563F40, lbl_80563F50, lbl_80563F54, lbl_80563F58, lbl_80563F5C, lbl_80563F60, lbl_80563F64, lbl_80563F68, lbl_80563F6C, lbl_80563F70, lbl_80563F74, lbl_80563F78;
extern "C" char lbl_80346E9C[], lbl_80346EC8[];
extern "C" int lbl_80499050[12];
extern "C" void *fn_801769F8(void);
extern "C" void fn_80265EC4(void *, int, void *);
extern "C" void fn_80266070(void *, void *, void *, void *);
extern "C" void fn_80266170(void *, int, void *, int, float);
extern "C" void fn_802662D8(void *, void *, void *, void *, void *);
extern "C" void fn_80266388(void *, void *, void *, void *, void *);
extern "C" void fn_801E9DC4(void *);
extern "C" int fn_801E9E30(void *, void *);
extern "C" float fn_801E9DDC(void *, float, float);
extern "C" int fn_80129D90(int, int, int);
extern "C" void fn_80274730(void *, float, float, float, float);
extern "C" void fn_802749FC(void *, float *);
extern "C" void fn_802704D4(int, void *);
extern "C" void fn_80274E94(void *);
extern "C" void fn_80274EA8(void *);
extern "C" void fn_80266A0C(void *, float *, void *, float);
extern "C" void fn_80274F74(void *, float *, float);
extern "C" void fn_802750C4(void *, float, float);
extern "C" void fn_802751AC(void *);
extern "C" void fn_80275410(void *);
extern "C" void fn_802756A4(void *);
extern "C" void fn_80275938(void *);
extern "C" void fn_80275B9C(void *, float, float, float);
extern "C" void fn_80275D0C(void *);
extern "C" void fn_802E317C(const char *, ...);
extern "C" void fn_801BFD34(void *, float *, void *);
extern "C" void fn_80015B20(void *, float *, void *);
extern "C" float PSVECDotProduct(const float *, const float *);
struct W12 { int w[12]; };
extern "C" void fn_80271624(int mode, void *arg1)
{
    struct Ent {
        float cur[3];
        float curB[3];
        float curC;
        unsigned char active;
        unsigned char flags;
        unsigned char pad1E[2];
        float from[3];
        float to[3];
        float fromB[3];
        float toB[3];
        float fromC;
        float toC;
        int mode;
        int pad5C;
    };
    struct Rec { char pad0[0x18]; int choice[16]; int count; int pad5C; };
    struct Zone { int pad0; float a0, b0, a1, b1; int pad14[2]; };
    struct Table {
        struct { int f0, f4, f8, count; } hdr;
        char pad10[0x60];
        Ent ents[200];
        Rec recs[32];
        char pad5770[0x10];
        Zone zones[1];
    };
    Table *tbl = (Table *)lbl_8049A258;
    char *cam;
    Ent *e;
    int arg;
    int changed;
    int idx;
    char *o = (char *)arg1;

    cam = (char *)(*(Manager **)(*(char **)(o + 0x140) + 0x270))->getCamera();
    switch (*(char **)(cam + 4) != 0 ? *(unsigned char *)(*(char **)(cam + 4) + 0x34) : 3) {
    case 1:
        arg = 0;
        break;
    case 2:
        arg = 1;
        break;
    default:
        if (lbl_8055F55C == 0) {
            lbl_8055F55C = 1;
            fn_802E30C8(lbl_8055C59C, lbl_80346E9C);
        }
    case 0:
        arg = tbl->hdr.count + 2;
        break;
    }
    fn_80270B50();
    if (lbl_8055F548 > 1) {
        changed = 0;
        if (mode == 11) {
            idx = fn_802710A0(*(void **)(o + 0x140), arg);
            if (idx >= 0) {
                *(int *)(o + 0x14C) = idx;
                if (idx != *(int *)(o + 0x150)) {
                    Rec *rec;
                    *(int *)(o + 0x150) = idx;
                    rec = &tbl->recs[idx];
                    changed = 1;
                    *(int *)(o + 0x148) = rec->choice[fn_80129D90(6, 0, rec->count)];
                }
            }
        } else {
            idx = -1;
        }
        if (idx >= 0) {
            e = &tbl->ents[*(int *)(o + 0x148)];
            if (e->active != 0) {
                if (lbl_8055F564 != 0) {
                    Zone *z = &tbl->zones[idx];
                    float a = z->a0;
                    float b = z->b0;
                    float t = lbl_80563F48;
                    float v = lbl_8055F568;
                    float r;
                    if (a >= b) {
                        if (v >= a)
                            b += ((float *)(*(char **)(cam + 0x2C) + 8))[*(char **)(cam + 4) != 0 ? *(unsigned char *)(*(char **)(cam + 4) + 0x34) : 3];
                        else
                            a -= ((float *)(*(char **)(cam + 0x2C) + 8))[*(char **)(cam + 4) != 0 ? *(unsigned char *)(*(char **)(cam + 4) + 0x34) : 3];
                    }
                    if (a <= v && v <= b) {
                        t = (v - a) / (b - a);
                    } else {
                        a = z->a1;
                        b = z->b1;
                        if (a >= b) {
                            if (v >= a)
                                b += ((float *)(*(char **)(cam + 0x2C) + 8))[*(char **)(cam + 4) != 0 ? *(unsigned char *)(*(char **)(cam + 4) + 0x34) : 3];
                            else
                                a -= ((float *)(*(char **)(cam + 0x2C) + 8))[*(char **)(cam + 4) != 0 ? *(unsigned char *)(*(char **)(cam + 4) + 0x34) : 3];
                        }
                        if (a <= v && v <= b)
                            t = (v - a) / (b - a);
                    }
                    if (t < lbl_80563F44) {
                        r = lbl_80563F44;
                    } else if (t > lbl_80563F50) {
                        r = lbl_80563F50;
                    } else if (t > lbl_80563F48) {
                        r = t * (lbl_80563F54 * t * t) + lbl_80563F58 * t * t;
                    } else {
                        r = t * (lbl_80563F54 * t * t) - lbl_80563F58 * t * t;
                    }
                    {
                        float p[3], q[3];
                        p[0] = e->from[0] + r * (e->to[0] - e->from[0]);
                        p[1] = e->from[1] + r * (e->to[1] - e->from[1]);
                        p[2] = e->from[2] + r * (e->to[2] - e->from[2]);
                        e->cur[0] = p[0];
                        e->cur[1] = p[1];
                        e->cur[2] = p[2];
                        q[0] = e->fromB[0] + r * (e->toB[0] - e->fromB[0]);
                        q[1] = e->fromB[1] + r * (e->toB[1] - e->fromB[1]);
                        q[2] = e->fromB[2] + r * (e->toB[2] - e->fromB[2]);
                        e->curB[0] = q[0];
                        e->curB[1] = q[1];
                        e->curB[2] = q[2];
                        e->curC = e->fromC + r * (e->toC - e->fromC);
                    }
                } else {
                    e->cur[0] = e->from[0];
                    e->cur[1] = e->from[1];
                    e->cur[2] = e->from[2];
                    e->curB[0] = e->fromB[0];
                    e->curB[1] = e->fromB[1];
                    e->curB[2] = e->fromB[2];
                    e->curC = e->fromC;
                }
            }
            {
                float zero = lbl_80563F48;
                *(float *)(o + 0x7C) = e->cur[0];
                *(float *)(o + 0x80) = e->cur[1];
                *(float *)(o + 0x84) = e->cur[2];
                *(float *)(o + 0x120) = zero;
                *(float *)(o + 0x124) = zero;
                *(float *)(o + 0x128) = zero;
            }
            if (lbl_8055F54C != e->mode)
                fn_801E9DC4(o + 0x1EC);
            if (e->flags & 2) {
                void *s = fn_801769F8();
                fn_80265EC4(o + 0x160, fn_802E2C20(), s);
                fn_80266070(o + 0x160, o + 0x4C, o + 0xE4, o + 0x12C);
            } else {
                *(float *)(o + 0x4C) = *(float *)(o + 0xE4);
                *(float *)(o + 0x50) = *(float *)(o + 0xE8);
                *(float *)(o + 0x54) = *(float *)(o + 0xEC);
            }
            if (e->flags & 1) {
                void *s = fn_801769F8();
                float v;
                fn_80266170(o + 0x178, fn_802E2C20(), s, changed, *(float *)(o + 0xBC));
                v = *(float *)(o + 0x180) + *(float *)(o + 0x184) * (*(float *)(o + 0xBC) - *(float *)(o + 0x180));
                *(float *)(o + 0x194) = v;
                *(float *)(o + 0xBC) = v;
            }
            switch (e->mode) {
            case 1:
                fn_80274730(o, lbl_80563F4C * e->curC, lbl_80563F44, lbl_80563F44, lbl_80563F48);
                break;
            case 5: {
                float vec[3];
                lbl_8055F480 = 1;
                vec[0] = lbl_80563F5C;
                vec[1] = lbl_80563F50;
                vec[2] = lbl_80563F48;
                fn_802749FC(o, vec);
                break;
            }
            case 4:
                fn_802704D4(4, o);
                break;
            case 2:
                fn_80274E94(o);
                break;
            case 3:
                fn_80274EA8(o);
                break;
            case 12: {
                float tmp[3];
                float f = fn_802715F0(e);
                fn_802715C4(tmp, e);
                fn_80266A0C(o, tmp, e, f);
                break;
            }
            case 0: {
                float tmp[3];
                float f = fn_802715F0(e);
                fn_802715C4(tmp, e);
                fn_80274F74(o, tmp, f);
                break;
            }
            case 17:
                fn_802750C4(o, e->curB[0], e->curB[1]);
                break;
            case 16:
                fn_802751AC(o);
                break;
            case 7:
                fn_80275410(o);
                break;
            case 8:
                fn_802756A4(o);
                break;
            case 9:
                fn_80275938(o);
                break;
            case 6:
                fn_80275B9C(o, lbl_80563F60, lbl_80563F64, lbl_80563F50);
                break;
            case 10:
                fn_80275D0C(o);
                break;
            default:
                fn_802E317C(lbl_80346EC8);
                break;
            }
            lbl_8055F54C = e->mode;
            if (e->flags & 1)
                fn_802662D8(o + 0x178, o + 0x7C, o + 0x7C, o + 0x70, o + 0x4C);
            if (e->flags & 4)
                fn_80266388(o + 0x188, fn_801769F8(), o + 0x58, e, *(void **)(o + 0x140));
            if (e->flags & 8) {
                float d[3];
                float dot;
                d[0] = *(float *)(o + 0xE4) - *(float *)(o + 0x7C);
                d[1] = *(float *)(o + 0xE8) - *(float *)(o + 0x80);
                d[2] = *(float *)(o + 0xEC) - *(float *)(o + 0x84);
                dot = PSVECDotProduct(d, (float *)(o + 0x70));
                dot = (lbl_8055C598 < lbl_80563F48) ? dot : lbl_8055C598;
                dot = (dot > lbl_80563F68) ? dot : lbl_80563F68;
                *(float *)(o + 0x1A0) = dot;
            }
        } else if (idx != -10) {
            float a[3];
            float m[9];
            int w;
            a[0] = lbl_80563F48;
            a[1] = lbl_80563F6C;
            a[2] = lbl_80563F48;
            m[0] = lbl_80563F50;
            m[1] = lbl_80563F48;
            m[2] = lbl_80563F48;
            m[3] = lbl_80563F48;
            m[4] = lbl_80563F48;
            m[5] = lbl_80563F50;
            m[6] = lbl_80563F48;
            m[7] = lbl_80563F44;
            m[8] = lbl_80563F48;
            fn_801BFD34(o + 0x7C, a, o + 0xC0);
            fn_80015B20(o + 0x58, m, o + 0xC0);
            for (w = 0; w < 12; w++)
                ((int *)lbl_80499050)[w] = ((int *)(o + 0x58))[w];
        }
    } else {
        float k = lbl_80563F70;
        float h = lbl_80563F74;
        float c = lbl_80563F40;
        int w;
        *(float *)(o + 0x7C) = k * ((float)(int)(c + (h + *(float *)(o + 0xE4) / k)) - h);
        *(float *)(o + 0x84) = k * ((float)(int)(c + (h + *(float *)(o + 0xEC) / k)) - h);
        fn_801E9DC4(o + 0x1EC);
        if (fn_801E9E30(o + 0x1EC, o + 0x7C) == 0)
            *(float *)(o + 0x80) = fn_801E9DDC(o + 0x1EC, *(float *)(o + 0xE4), *(float *)(o + 0xEC));
        *(float *)(o + 0x80) += lbl_80563F78;
        fn_80274E94(o);
        for (w = 0; w < 12; w++)
            ((int *)lbl_80499050)[w] = ((int *)(o + 0x58))[w];
    }
}
#pragma cplusplus reset
/* CameraType_fromName: look up a camera mode index by its name string, returning CAM_TYPE_MAX (11) if not found. */
int fn_80271FAC(const char *typeName) {
    char **nameEntry = sCamTypeNames;
    int typeIdx = 0;
    do {
        if ((typeIdx != CAM_TYPE_MAX) && (stricmp(typeName, *nameEntry) == 0)) return typeIdx;
        ++typeIdx;
        ++nameEntry;
    } while (typeIdx < CAM_TYPE_COUNT);
    return CAM_TYPE_MAX;
}
#pragma cplusplus on
extern "C" void fn_80272354(void *);
extern "C" unsigned char fn_80008050(int);
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void DBPrintf_80270B00(const char *, ...);
extern "C" char lbl_80346B00[];
 extern "C" char lbl_8055C5A4;
 extern "C" char lbl_8055C5AC;
 extern "C" char lbl_8055C5B4;
extern "C" int fn_80272028(void *arg0, Parser72028 *arg1, int arg_sp0)
{
  char *path;
  int hash;
  char buffer[0x10];
  char * const name = lbl_80346B00;
  register Parser72028 *parser;
  register void *output;
  char *p;
  int index;
  int j;
  unsigned char bit;
  output = arg0;
  parser = arg1;
  fn_80272354(arg0);
  if (parser->has(name + 0x424) == 0)
  {
    DBPrintf_80270B00(name + 0x430, name + 0x424);
    return 0;
  }
  *((float *) output) = parser->getFloat(name + 0x424);
  if (parser->has(name + 0x464) == 0)
  {
    DBPrintf_80270B00(name + 0x430, name + 0x464);
    return 0;
  }
  *((float *) (((char *) output) + 4)) = parser->getFloat(name + 0x464);
  if (parser->has(name + 0x470) == 0)
  {
    DBPrintf_80270B00(name + 0x430, name + 0x470);
    return 0;
  }
  *((float *) (((char *) output) + 8)) = parser->getFloat(name + 0x470);
  if (parser->has(&lbl_8055C5A4) == 0)
  {
    DBPrintf_80270B00(name + 0x430, &lbl_8055C5A4);
    return 0;
  }
  *((float *) (((char *) output) + 0xC)) = parser->getFloat(&lbl_8055C5A4);
  *((int *) (((char *) output) + 0x5C)) = parser->getOption(&lbl_8055C5AC, 2);
  index = 0;
  while (parser->enumerate(index, &path, &hash) != 0)
  {
    register char *s = path;
    if ((strncmp(s, &lbl_8055C5B4, 5) == 0) && (s[5] != '_'))
    {
      bit = fn_80008050(hash);
      if (((int) bit) < 0x20)
      {
        *((int *) (((char *) output) + 0x10)) |= 1 << bit;
      }
      else
      {
        *((int *) (((char *) output) + 0x14)) |= 1 << (bit - 0x20);
      }
    }
    index++;
  }
  if (parser->has(name + 0x47C) == 0)
  {
    DBPrintf_80270B00(name + 0x430, name + 0x47C);
    return 0;
  }
  *((int *) (((char *) output) + 0x58)) = parser->getCount(name + 0x47C);
  p = (char *) arg0;
  for (j = 0; j < (*((int *) (((char *) arg0) + 0x58))); j++)
  {
    sprintf(buffer, name + 0x48C, j);
    if (parser->has(buffer) == 0)
    {
      DBPrintf_80270B00(name + 0x430, buffer);
      if (((!name) && (!name)) && (!name)) {}
      return 0;
    }
    *((int *) (p + 0x18)) = parser->getCount(buffer);
    p += 4;
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
/* Initializes a camera-like object: zeros its position, sets the fourth float
 * to 10.0f, clears an 8-byte region at offset 0x10, and sets fields at 0x58/0x5C. */
void fn_80272354(void *obj) {
    float other = 10.0f;
    float value = 0.0f;
    *(float *)((char *)obj + 0x0) = value;
    *(float *)((char *)obj + 0x4) = value;
    *(float *)((char *)obj + 0x8) = value;
    *(float *)((char *)obj + 0xC) = other;
    memset((char *)obj + 0x10, 0, 8);
    *(int *)((char *)obj + 0x58) = 0;
    *(int *)((char *)obj + 0x5C) = 2;
}

#pragma processor 750
void fn_802723B4(void *arg0, void *arg1) {
    void *slot;
    void *object;
    float factor;
    float base;
float __repair_base_1;
    ((void (*)(void **, void *))fn_80136468)(&slot, arg0);
    object = slot;
    factor = *(float *)((char *)&slot + 4);
    base = *(float *)object;
    *(float *)arg1 = base + (*(float *)*(void **)((char *)object + 0x14) - base) * factor;
    __repair_base_1 = *(float *)((char *)object + 4);
    *(float *)((char *)arg1 + 4) = __repair_base_1 + (*(float *)((char *)*(void **)((char *)object + 0x14) + 4) - __repair_base_1) * factor;
}
extern float lbl_8055F560, lbl_80563F40, lbl_80563F48;
extern void fn_80136468(void **, void *, float);
#pragma ppc_psq_save off
#pragma ppc_psq_save off
float fn_80272428(void *arg0, void *arg1, float a, float b, float radius)
{
  struct Result
  {
    void *node;
    float fraction;
    s32 mode;
  };
  struct Point
  {
    float x;
    float y;
  };
  float period = *((float *) (((u8 *) (*((void **) (((u8 *) arg0) + 0x2C)))) + 8));
  struct Result resultA;
  struct Result resultB;
  volatile struct Point pointA;
  volatile struct Point pointB;
  volatile struct Point deltaA;
  volatile struct Point deltaB;
  void *new_var[2];
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
  if (argA > argB)
  {
    float span = argB - (argA - period);
    if ((span * span) < lbl_8055F560)
    {
      return argA;
    }
  }
  else
  {
    float span = argB - argA;
    if ((span * span) < lbl_8055F560)
    {
      return argA;
    }
  }
  fn_80136468((void **) (&resultA), arg0, argA);
  new_var[1] = resultA.node;
  fraction = resultA.fraction;
  new_var[0] = (0, *((void **) (((u8 *) new_var[1]) + 0x14)));
  x = (*((float *) new_var[1])) + (fraction * ((*((float *) new_var[0])) - (*((float *) new_var[1]))));
  y = *((float *) (((u8 *) new_var[1]) + 4));
  y = (*((float *) (((u8 *) new_var[1]) + 4))) + (fraction * ((*((float *) (((u8 *) new_var[0]) + 4))) - y));
  dx = x - (*((float *) arg1));
  pointA.x = x;
  dy = y - (*((float *) (((u8 *) arg1) + 4)));
  pointA.y = y;
  squareX = dx * dx;
  deltaA.x = dx;
  squareY = dy * dy;
  deltaA.y = dy;
  tmpD = __fabs((double) (argR - (squareX + squareY)));
  distA = (float) tmpD;
  if (distA < lbl_8055F560)
  {
    return argA;
  }
  fn_80136468((void **) (&resultB), arg0, argB);
  new_var[1] = resultB.node;
  fraction = resultB.fraction;
  new_var[0] = *((void **) (((u8 *) new_var[1]) + 0x14));
  x = (*((float *) new_var[1])) + (fraction * ((*((float *) new_var[0])) - (*((float *) new_var[1]))));
  y = (*((float *) (((u8 *) new_var[1]) + 4))) + (fraction * ((*((float *) (((u8 *) new_var[0]) + 4))) - (*((float *) (((u8 *) new_var[1]) + 4)))));
  dx = x - (*((float *) arg1));
  (&pointB)->x = x;
  dy = y - ((0, *((float *) (((u8 *) arg1) + 4))));
  pointB.y = y;
  squareX = dx * dx;
  deltaB.x = dx;
  squareY = dy * dy;
  deltaB.y = dy;
  tmpD = __fabs((double) (argR - (squareX + squareY)));
  distB = (float) tmpD;
 if (distB < lbl_8055F560) { return argB;
  }
  if (argA > argB)
  {
    mid = (argB + (argA - period)) * lbl_80563F40;
    if (mid < lbl_80563F48)
    {
      mid = mid + period;
    }
  }
  else
  {
    mid = (argA + argB) * lbl_80563F40;
  }
  if (distA < distB)
  {
    return fn_80272428(arg0, arg1, argA, mid, argR);
  }
  return fn_80272428(arg0, arg1, mid, argB, argR);
}
#pragma ppc_psq_save reset
#pragma ppc_psq_save reset
extern char lbl_8034705C[];
/* Log a debug sample: parameter value and the 2D point evaluated on the curve at that parameter. */
void fn_8027264C(int label, void *curve, float param) {
    float point;
    ((void (*)(void *, void *, float))fn_802723B4)(curve, &point, param);
    DBPrintf_80270B00(lbl_8034705C, label, param, point, *(float *)((char *)&point + 4));
}

#pragma dont_inline on
/* RealName: IsFloatStrictlyBetween_802726AC - 1 when value lies strictly between
   the two bounds, whichever order they are given in. fn_802726EC adds the two
   endpoints; kept out of line so that caller shares this half. */
s32 fn_802726AC(f32 value, f32 boundA, f32 boundB) {
    /* Return 1 when value lies strictly between boundA and boundB, whichever order they are given. */
    if (boundA < boundB) {
        return (boundA < value) && (value < boundB);
    }
    return (boundA > value) && (value > boundB);
}
#pragma dont_inline reset

extern int fn_802726AC(float, float, float);
/* RealName: IsFloatInRangeInclusive_802726EC - 1 when value is either bound or
   lies strictly between them (the bounds may come in either order); the strict
   middle is fn_802726AC. The curve intersection code calls it with
   0.0f..1.0f (lbl_80563F48..lbl_80563F50) so that only quadratic roots falling
   on the segment being tested are kept. */
int fn_802726EC(float value, float boundA, float boundB) {
    int inRange = 0;
    if (value == boundA || value == boundB || fn_802726AC(value, boundA, boundB) != 0) {
        inRange = 1;
    }
    return inRange;
}

extern float lbl_80558DC4[];
extern float lbl_80563F40, lbl_80563F48, lbl_80563F50, lbl_80563F8C, lbl_80563F90;
extern double fabs(double);
extern double fn_8002F234(void);
extern void fn_801355C0(void *, void *, int, void **, int);
extern void *memmove(void *, void *, int);
void fn_80272738(void *arg0, void *arg1) {
#pragma opt_common_subs off
    struct S {
        float sp8, spC, sp10, sp14;
        float sp18[2];
        float sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
        void *sp50;
        float sp54;
        int sp58;
    } s;
    float *var_r25;
    void *var_r24;
    void *var_r23;
    void *var_r22;
    int var_r21;
    int var_r20;
    int var_r19;
    int var_r18;
    int var_r29;
    void *r26;
    char *base;
    float f31, f30, f29, f28, f27, f26, f25, f24, f23;
    void *r5_2;
    float t1;
    void *r5;
    base = lbl_80346B00;
    r5 = *(void **)arg0;
    t1 = *(float *)((char *)r5 + 8);
    s.sp48 = *(float *)r5;
    s.sp4C = t1;
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
        float f7, f3, f8, f5, f6, f7_2, f9, f4, f6_2, f8_2, f3_2, f5_2, fabs25, sqrtResult;
        r3 = *(void **)((char *)var_r22 + 0x14);
        var_r19 = 0;
        f7 = *(float *)var_r22;
        f3 = *(float *)r3 - f7;
        f8 = *(float *)((char *)var_r22 + 4);
        f5 = *(float *)((char *)r3 + 4) - f8;
        f6 = f7 + f29 * f3;
        f7_2 = f7 + f30 * f3;
        f9 = f8 + f29 * f5;
        s.sp40 = f6;
        f4 = f6 - s.sp48;
        f6_2 = f7_2 - f6;
        f8_2 = f8 + f30 * f5;
        f3_2 = f9 - s.sp4C;
        s.sp38 = f7_2;
        f5_2 = f8_2 - f9;
        s.sp44 = f9;
        s.sp3C = f8_2;
        f25 = f6_2 * f6_2 + f5_2 * f5_2;
        s.sp30 = f6_2;
        fabs25 = (float)__fabs((double)f25);
        f24 = f23 * (f4 * f6_2 + f3_2 * f5_2);
        s.sp34 = f5_2;
        s.sp28 = f4;
        s.sp2C = f3_2;
        if (fabs25 != lbl_80558DC4[0] && f24 * f24 - f31 * f25 * (f4 * f4 + f3_2 * f3_2 - f26) > f29) {
            sqrtResult = (float)fn_8002F234();
            var_r19 = 2;
            s.sp20 = (-f24 - sqrtResult) / (f23 * f25);
            s.sp24 = (-f24 + sqrtResult) / (f23 * f25);
        }
        var_r24 = var_r23;
        var_r25 = &s.sp20;
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
        float temp, f1, f24b;
        DBPrintf_80270B00(base + 0x5EC);
        s.sp50 = 0;
        s.sp58 = 0x2710;
        s.sp54 = lbl_80563F48;
        fn_801355C0(arg1, &s.sp48, 0, &s.sp50, 0);
        temp = *(float *)((char *)s.sp50 + 0x1C) + *(float *)((char *)s.sp50 + 0x18) * s.sp54;
        f23 = temp;
        f1 = temp - f27;
        if (f27 > temp) f1 += f28;
        f24b = temp + f27;
        if (f27 > f28 - temp) f24b -= f28;
        *(float *)((char *)arg0 + 4) = fn_80272428(arg1, &s.sp48, f1, temp, f26);
        *(float *)((char *)arg0 + 8) = fn_80272428(arg1, &s.sp48, temp, f24b, f26);
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
        ((void (*)(void *, void *, float))fn_802723B4)(arg1, s.sp18, lbl_80563F40 * (a + d));
        s.sp14 = s.sp18[1] - s.sp4C;
        s.sp10 = s.sp18[0] - s.sp48;
        if (s.sp10 * s.sp10 + s.sp14 * s.sp14 > f26) {
            if (*(unsigned char *)((char *)arg0 + 0x14) != 0) {
                float b = *(float *)((char *)arg0 + 8);
                float c = *(float *)((char *)arg0 + 0xC);
                ((void (*)(void *, void *, float))fn_802723B4)(arg1, s.sp18, lbl_80563F40 * (b + c));
                s.spC = s.sp18[1] - s.sp4C;
                s.sp8 = s.sp18[0] - s.sp48;
                if (s.sp8 * s.sp8 + s.spC * s.spC > f26) {
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
    DBPrintf_80270B00(base + 0x634, s.sp48, s.sp4C);
    fn_8027264C((int)(base + 0x65C), arg1, *(float *)((char *)arg0 + 4));
    fn_8027264C((int)(base + 0x668), arg1, *(float *)((char *)arg0 + 8));
    if (*(unsigned char *)((char *)arg0 + 0x14) != 0) {
        fn_8027264C((int)(base + 0x674), arg1, *(float *)((char *)arg0 + 0xC));
        fn_8027264C((int)(base + 0x684), arg1, *(float *)((char *)arg0 + 0x10));
    }
}

#pragma dont_inline on
/* Returns whether a value lies within an interval, adjusting a wrapped lower/upper bound by the period. */
int fn_80272C24(float value, float lower, float upper, float period) {
    int result;
    if (lower == upper) return 1;
    if (lower > upper) {
        if (lower > value) lower -= period;
        else upper += period;
    }
    result = 0;
    if ((value >= lower) && (value <= upper)) result = 1;
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
/* Score the camera region held in 'regionSlot' for 'subject': reject disabled or
   wrong-group regions; with camera debug on, accept at once when the camera ray-hit
   value lies in either of the slot's period-wrapped ranges. Otherwise score by the
   distance from the region's point past its radius, 1.0 inside and 1/(1+dist) beyond.
   Writes the score to *outScore and returns nonzero when the region is accepted. */
extern "C" int fn_80272C74(void *regionSlot, void *subject, float *outScore, int group) {
    struct CameraManager {
        virtual void slot0() = 0;
        virtual void slot1() = 0;
        virtual void slot2() = 0;
        virtual void slot3() = 0;
        virtual void *getCamera() = 0;
    };
    float cameraHeight;
    int accepted;

    *outScore = 0.0f;
    if (*(int *)((char *)*(void **)regionSlot + 0x58) == 0) return 0;
    if (group != -1 && group != *(int *)((char *)*(void **)regionSlot + 0x5C)) return 0;
    accepted = 1;
    if (lbl_8055F564 != 0) {
        void *manager = *(void **)((char *)subject + 0x270);
        void *camera = ((CameraManager *)manager)->getCamera();
        camera = *(void **)((char *)camera + 0x2C);
        cameraHeight = *(float *)((char *)camera + 8);
        if (fn_80272C24(lbl_8055F568, *(float *)((char *)regionSlot + 4), *(float *)((char *)regionSlot + 8), cameraHeight) != 0 ||
            (*(unsigned char *)((char *)regionSlot + 0x14) != 0 &&
             fn_80272C24(lbl_8055F568, *(float *)((char *)regionSlot + 0xC), *(float *)((char *)regionSlot + 0x10), cameraHeight) != 0)) {
            *outScore = 1.0f;
            return 1;
        }
        accepted = 0;
    }
    {
        float distancePastRadius = PSQUATMultiply((char *)subject + 0x60, *(void **)regionSlot) -
                                   *(float *)((char *)*(void **)regionSlot + 0xC);
        if (distancePastRadius <= 0.0f) *outScore = 1.0f;
        else *outScore = 1.0f / (1.0f + distancePastRadius);
    }
    return accepted;
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
    int a, b, c, d;
    int flags;
    char *name;
    Parser2 *p = arg1;
    char *o = (char *)arg0;
    name = lbl_80346B00;

    if (p->has(lbl_8055C5BC) != 0 && p->has(lbl_8055C5C0) != 0 && p->has(lbl_8055C5C4) != 0
        && (p->has(lbl_8055C5C8) != 0 || p->has(lbl_8055C5D0) != 0) && p->has(lbl_8055C5D8) != 0) {
        *(float *)o = p->getFloat(lbl_8055C5BC);
        *(float *)(o + 4) = p->getFloat(lbl_8055C5C0);
        *(float *)(o + 8) = p->getFloat(lbl_8055C5C4);
        if (p->has(lbl_8055C5D0) != 0) {
            *(float *)(o + 0x18) = p->getFloat(lbl_8055C5D0);
        } else {
            *(float *)(o + 0x18) = 0.75f * p->getFloat(lbl_8055C5C8);
        }
        *(int *)(o + 0x58) = fn_80271FAC(p->getString(lbl_8055C5D8));
        *(float *)(o + 0xC) = p->getFloatDef(lbl_8055C5E0, 0.0f);
        *(float *)(o + 0x10) = p->getFloatDef(lbl_8055C5E8, 0.0f);
        *(float *)(o + 0x14) = p->getFloatDef(lbl_8055C5F0, 1.0f);
        a = p->getFlag(name + 0x690, 0);
        b = p->getFlag(lbl_8055C5F8, 0);
        c = p->getFlag(lbl_8055C600, 0);
        d = p->getFlag(name + 0x69C, 0);
        flags = (a | ((-b | b) >> 31) & 2) | (((-c | c) >> 31) & 4);
        flags |= (((-d | d) >> 31) & 8);
        *(unsigned char *)(o + 0x1D) = flags;
        switch (*(int *)(o + 0x58)) {
        case 13:
            *(unsigned char *)(o + 0x1D) = (unsigned char)flags | 2;
            *(int *)(o + 0x58) = 1;
            break;
        case 14:
            *(int *)(o + 0x58) = 2;
            *(unsigned char *)(o + 0x1D) = (unsigned char)flags | 2;
            break;
        case 15:
            *(unsigned char *)(o + 0x1D) = (unsigned char)flags | 2;
            *(int *)(o + 0x58) = 3;
            break;
        case 12:
            *(unsigned char *)(o + 0x1D) = (unsigned char)flags | 4;
            *(int *)(o + 0x58) = 0;
            break;
        }
        if (p->has(lbl_8055C608) != 0 && p->has(lbl_8055C60C) != 0 && p->has(lbl_8055C610) != 0) {
            *(unsigned char *)(o + 0x1C) = 1;
            *(float *)(o + 0x20) = *(volatile float *)o;
            *(float *)(o + 0x24) = *(float *)(o + 4);
            *(float *)(o + 0x28) = *(float *)(o + 8);
            *(float *)(o + 0x38) = *(float *)(o + 0xC);
            *(float *)(o + 0x3C) = *(float *)(o + 0x10);
            *(float *)(o + 0x40) = *(float *)(o + 0x14);
            *(float *)(o + 0x50) = *(float *)(o + 0x18);
            *(float *)(o + 0x2C) = p->getFloatDef(lbl_8055C608, *(float *)o);
            *(float *)(o + 0x30) = p->getFloatDef(lbl_8055C60C, 20.0f + *(float *)(o + 4));
            *(float *)(o + 0x34) = p->getFloatDef(lbl_8055C610, *(float *)(o + 8));
            if (p->has(name + 0x6A8) != 0) {
                *(float *)(o + 0x54) = p->getFloat(name + 0x6A8);
            } else if (p->has(lbl_8055C614) != 0) {
                *(float *)(o + 0x54) = 0.75f * p->getFloat(lbl_8055C614);
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

#pragma scheduling invalid_target
void fn_80273354(void) {
    int a = 3, b = 2, c = 1;
    unsigned char *ptr = lbl_8049A258;
    memset(ptr, 0, 0x64);
    *(int *)(ptr + 0x1C) = c;
    *(int *)(ptr + 0x18) = 0;
    *(int *)(ptr + 0x2C) = c;
    *(int *)(ptr + 0x30) = c;
    *(int *)(ptr + 0x40) = b;
    *(int *)(ptr + 0x44) = a;
    *(int *)(ptr + 0x54) = 5;
    *(int *)(ptr + 0x58) = a;
    ((void (*)(int, int, int, void *))fn_8027156C)(a, b, c, ptr);
}
extern int lbl_8055F54C;
/* The CamType the last camera update applied: fn_80271624 compares it with the camera
 * entry's mode and re-applies the camera setup when it differs, then stores it back.
 * Writing CAM_TYPE_COUNT (out of range of every real mode) invalidates the cache. */
#define sLastCamType lbl_8055F54C
/* fn_80271578: reinitialize the current object (rebuilding its camera record table)
 * while preserving the field at offset 0xC. */
#define reinitCurrentObject fn_80271578
#pragma dont_inline on
void fn_802733C8(void) {
    /* Reinitialize the current object's camera state and invalidate the cached camera
     * type, so the next update sees its mode as newly selected and re-applies it. */
    reinitCurrentObject();
    sLastCamType = CAM_TYPE_COUNT;
}
#pragma dont_inline reset
/* Empty no-op called from the sound-system shutdown fn_8026785C, just after the
   keyframe list is freed; this build has no camera/event state to tear down here. */
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

/* Tail-call wrapper: forwards the mode and object to the camera/event update fn_80271624. */
void fn_80273490(int mode, void *obj) {
    fn_80271624(mode, obj);
}

#pragma dont_inline on
/* Map an event type to its region-group index (0-4 for types 11-15), or 6 if it has no region group. */
int fn_80273494(int eventType) {
    switch (eventType) {
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
/* When objectIndex is 0 (the primary object), store `state` into the global gate byte. */
void fn_802735F4(int objectIndex, signed char state) {
    if (objectIndex == 0) {
        lbl_8055F558 = state;
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
    s32 kind;
    table = (u8 *)&lbl_8049A258 + arg1 * 0x14;
    state = lbl_80346BA0 + ((*(s32 *)(table + 4) + *(s32 *)(table + 0xC))) * 0x28;
    kind = *(s32 *)state;
    switch (kind) {
    case 0x22: {
        struct Scratch { float vec[3]; float pad; float matrix[9]; float pos[3]; } scratch;
        float mag, nx, ny, nz, sine, oneMinusCos, t0, t1, t2, t3, t4, t5, cosine;
        register float scale = 0.0174532925f;
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
        fn_802E30C8(lbl_80347310, kind);
        fn_802704D4(4, arg0);
        return;
    }
}
extern int fn_80128668(void);
int fn_80273978(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
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

