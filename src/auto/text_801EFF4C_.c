#include "revolution/MTX/mtxtypes.h"
#pragma push
#pragma cplusplus on
extern "C" void fn_801345D8(void *, int, const char *, ...);
extern "C" int fn_802C6FC0(char *, int, int);
#pragma pop
extern int lbl_8055B0C8;
extern int lbl_8055B0B8;
extern int lbl_8055B0F0;
extern int lbl_8055B0F8;
extern float lbl_80562F28;
extern float lbl_80562F1C;
extern float lbl_80562F18;
extern int __cntlzw(unsigned int);
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern int lbl_80488798[64];
extern unsigned char lbl_80488798_u8[];
extern char lbl_8033A51C[];
extern void fn_802E317C(const char *, ...);
extern char lbl_8033A578[];
int fn_801F196C(int, int);
// split_file divides it into the game's real files (file_status shows its range).

typedef struct {
    unsigned int field_00;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0C;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1C;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2C;
    short field_30;
    short padding_32;
    unsigned int field_34;
    unsigned int field_38;
    float field_3C;
    unsigned char flag;
    unsigned char padding_41[3];
} Fn801F1B1CSource;

extern void fn_801F17C8(int);
  void fn_801EFF4C(void* alarm) {
      fn_801F17C8(fn_801F0AA0(alarm));
  }

void fn_801EFF70(void* alarm) {
    fn_801F0CC4(fn_801F17DC(alarm));
}

void fn_801EFFF8(int arg0) {
    fn_801F0F18(arg0, 1);
}

int fn_801F0F18(int, int);
int fn_801F0E88(int, int);
int fn_801284F8(int, void *);
int fn_801F0DC0(int, int, int, int);
float fn_801E88F0(int);
float fn_802C88E8(int);
extern int lbl_8055B0B8;
void fn_801F0000(int arg0) {
    fn_801F0F18(arg0, -1);
}

int fn_801F0008(void) {
    return 0x4C;
}

int fn_801F0010(int arg0, int arg1) {
    int value = arg1;
    if (value != 0) {
        value = fn_801F0E88(value, arg0);
    }
    return value;
}

extern float lbl_80562F10;
extern float lbl_80562F14;
extern float lbl_80562F18;
extern char lbl_8033A400[];
extern char lbl_8033A410[];
extern int lbl_8055B0C0;
extern void *fn_802C6B44(void);
extern int fn_802C6C20(void *);
extern int fn_802C7888(void *, int);
extern int fn_802C9C24(int);
extern int memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
  #pragma push
  #pragma use_lmw_stmw off
  #pragma cplusplus on
extern "C" void fn_801F004C(int unused, int arg1, void *arg2) {
    class VTable801F004C {
    public:
        virtual void v0();
        virtual int v3(int);
        virtual void v4();
        virtual void *v5(int);
    };
    int offset; void *list; int i; int zero; char temp[0x2c];
    list = fn_802C6B44(); zero = 0; i = 0; offset = 0;
    while (i < *(int *)list) {
        int name = fn_802C9C24(*(int *)((char *)list + 4) + offset);
        if (((VTable801F004C *)arg2)->v3(name)) {
            void *object = ((VTable801F004C *)arg2)->v5(name);
            memset(temp, 0, 0x2c);
            strncpy(temp, (char *)name, 0x10); temp[0xf] = zero;
            strncpy(temp + 0x14, (char *)object, 0x10); temp[0x23] = zero;
            *(int *)(temp + 0x10) = arg1; fn_802C7888(temp, 1);
        }
        offset += 0x10; i++;
    }
    fn_802C6C20(list);
}

extern "C" int sprintf(char *, const char *, ...);
extern "C" int sscanf(const char *, const char *, ...);
extern "C" char *strchr(const char *, int);
extern int lbl_8055B0D0;
extern float lbl_80562F1C;
extern char lbl_8033A420[];

#pragma scheduling invalid_target
extern "C" void fn_801F0148(void *arg0, void *arg1) {
    class Fn801F0148VTable {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual float v7(int);
    };
    float value;
    Fn801F0148VTable *object = (Fn801F0148VTable *)arg1;
    value = object->v7((int)&lbl_8033A400) * lbl_80562F10;
    *(float *)((char *)arg0 + 0x18) = value * lbl_80562F14;
    value = object->v7((int)&lbl_8033A410) * lbl_80562F10;
    *(float *)((char *)arg0 + 0x1C) = value * lbl_80562F14;
    value = object->v7((int)&lbl_8055B0C0) * lbl_80562F10;
    *(float *)((char *)arg0 + 0x24) = lbl_80562F18;
    *(float *)((char *)arg0 + 0x20) = value;
}

/* --- wheel mod LOD table -------------------------------------------------
 * A "detached wheel" record (0x138 bytes, looked up by name in fn_801F09FC)
 * keeps up to 8 level-of-detail entries at 0x28 and how many it found at 0xE8.
 * fn_801F08AC loads a record out of a .mod resource; fn_801F0208 below reads
 * its lod0..lod7 parameters, each written "<distance> <flag>" ("12.5 y").
 * fn_801F0488 then loads the two remap models of every entry and fn_801F15A8
 * picks the entry whose squared distance the camera has not reached yet.
 * Names and formats the game keeps in .sdata/.data:
 */
#define wheelmod_lod_name_fmt lbl_8055B0C8  /* .sdata: "lod%d" */
#define wheelmod_lod_value_fmt lbl_8055B0D0 /* .sdata: "%f %s" */
#define wheelmod_bad_lod_msg lbl_8033A420   /* .data: "wheelmod: bad lod entry in %s: %s" */
#define WHEELMOD_MAX_LODS 8                 /* lod0 .. lod7 */

#define WHEELMOD_SIDES 2 /* a wheel has one model per side, "L" and "R" */

typedef struct WheelModLod {
    /* 0x00 */ int slowRemap[WHEELMOD_SIDES]; /* slow_remap models, "<base><lod>L/R.mod" */
    /* 0x08 */ int fastRemap[WHEELMOD_SIDES]; /* fast_remap models, same names, fast group */
    /* 0x10 */ float distSq;          /* distance^2 at which this LOD takes over */
    /* 0x14 */ unsigned char yesFlag; /* the entry's flag word held a 'y' */
    /* 0x15 */ unsigned char pad15[3];
} WheelModLod;

typedef struct WheelMod {
    /* 0x00 */ char name[0x10];       /* the wheel's name, fn_801F09FC's key */
    /* 0x10 */ int slowRemapGroup;    /* model group of the slow_remap models */
    /* 0x14 */ int fastRemapGroup;    /* model group of the fast_remap models */
    /* 0x18 */ float tireRadius;      /* "tire_diameter" in inches, halved into metres */
    /* 0x1C */ float rimRadius;       /* "rim_diameter", likewise */
    /* 0x20 */ float width;           /* "width" in metres; 0 leaves the model unscaled */
    /* 0x24 */ float modelScale;      /* width over the first model's X extent, else 1.0 */
    /* 0x28 */ WheelModLod lods[WHEELMOD_MAX_LODS];
    /* 0xE8 */ int lodCount;          /* how many lod%d entries were found */
} WheelMod;

#pragma push
#pragma processor 750
/* Read a wheel mod's level-of-detail table: lod0..lod7 of the .mod resource each
 * hold "<distance> <flag>", stored as the squared switch distance and whether the
 * flag word said 'y'.  The record gets the number of entries it found; a malformed
 * entry is fatal (fn_802E317C reports it and exits), and the first missing lod ends
 * the table. */
extern "C" void fn_801F0208(void *arg0, void *arg1, char *modName) {
    class ModResource {
    public:
        virtual void v0();
        virtual int has(const char *name);
        virtual void v2();
        virtual const char *find(const char *name);
    };

    WheelMod *mod = (WheelMod *)arg0;
    WheelModLod *lod = mod->lods;
    int count;
    ModResource *res = (ModResource *)arg1;
    float zero = lbl_80562F1C;

    for (count = 0; count < WHEELMOD_MAX_LODS; count++, lod++) {
        char lodName[32];
        sprintf(lodName, (const char *)&wheelmod_lod_name_fmt, count);

        if (!res->has(lodName)) {
            break;
        }

        float dist = zero;
        char flagWord[32] = "n";

        if (sscanf(res->find(lodName), (const char *)&wheelmod_lod_value_fmt, &dist, flagWord) != 2) {
            fn_802E317C(wheelmod_bad_lod_msg, modName, res->find(lodName));
        }

        lod->distSq = dist * dist;
        lod->yesFlag = (strchr(flagWord, 'y') != 0);
    }

    mod->lodCount = count;
}
#pragma pop

extern "C" int sprintf(char *, const char *, ...);
extern "C" int sscanf(const char *, const char *, ...);
extern "C" char *strchr(const char *, int);
extern int lbl_8055B0D0;
extern float lbl_80562F1C;
extern char lbl_8033A420[];

extern int lbl_8055B0E0;
extern int lbl_8055B0E8;
extern int lbl_80562F20;
extern int lbl_80562F24;
__declspec(section ".data") extern float lbl_80558DC4;
extern char lbl_8033A3F0[];
/* Names fn_801F0488 reads.  The pool behind `strings` is the "detached wheel." block in
 * .data; the formats and keys below are fixed offsets into it, so they expand to exactly
 * the address arithmetic the function does (rename_symbol cannot name game symbols). */
#define wheelmod_string_pool lbl_8033A3F0
#define wheelmod_fmt_lod_side (strings + 0x54) /* "%s%d%s.mod" -> "wheel0L.mod" */
#define wheelmod_fmt_lod (strings + 0x60)      /* "%s%d.mod"   -> "wheel0.mod"  */
#define wheelmod_fmt_one_side (strings + 0x6C) /* "%s1%s.mod"  -> "wheel1L.mod" */
#define wheelmod_key_slow_remap (strings + 0x78) /* "slow_remap": list of models to remap */
#define wheelmod_key_fast_remap (strings + 0x84) /* "fast_remap" */
#define wheelmod_base_key lbl_8055B0E0    /* .sdata: "base", the resource's name-stem value */
#define wheelmod_fmt_one lbl_8055B0E8     /* .sdata: "%s1.mod"   -> "wheel1.mod"  */
#define wheelmod_label_left ((const char *)lbl_80562F20)  /* .sdata2: pointer to "L" */
#define wheelmod_label_right ((const char *)lbl_80562F24) /* .sdata2: pointer to "R" */
#define wheelmod_zero lbl_80558DC4        /* 0.0f */
#define WHEELMOD_LOD_SLOW_SLOT 0x28       /* &((WheelMod *)0)->lods[side].slowRemap[0] */
#define WHEELMOD_LOD_FAST_SLOT 0x30       /* ... .fastRemap[0]; the LOD table starts at 0x28 */
extern "C" int sprintf(char *, const char *, ...);
extern "C" int fn_8012C33C(char *);
extern "C" int fn_802C6FC0(char *, int, int);
extern "C" void fn_802C77F0(int, float *);
extern double fabs(double);
extern "C" double __fabs(double);
extern "C" void fn_801F0488(void *arg0, void *arg1) {
    class WheelModResource {
    public:
        virtual void unused0();
        virtual void unused1();
        virtual void unused2();
        virtual const char *find(const char *name); /* 0x14: a string value of the resource */
        virtual void unused4();
        virtual void unused5();
        virtual void unused6();
        virtual void unused7();
        virtual void unused8();
        virtual void unused9();
        virtual void unused10();
        virtual void unused11();
        virtual void unused12();
        virtual void unused13();
        virtual void unused14();
        virtual void unused15();
        virtual void unused16();
        virtual void unused17();
        virtual void unused18();
        virtual void unused19();
        virtual void unused20();
        virtual void *lookup(const char *name); /* 0x5C: a sub-resource, or 0 when absent */
    };

    const char *strings = wheelmod_string_pool;
    char *record;
    const char **pLabel;
    char *slot;
    const char *baseName;
    int borrowed;
    int lodIndex;
    int side;
    char name[0x40];
    float bbox[6]; /* the model's bounding box: min xyz, then max xyz */
    const char *labels[WHEELMOD_SIDES];

    /* every model of this wheel is named after the resource's "base" value */
    baseName = ((WheelModResource *)arg1)->find((const char *)&wheelmod_base_key);
    record = (char *)arg0;
    borrowed = 0;

    for (lodIndex = 0; lodIndex < ((WheelMod *)arg0)->lodCount; record += 0x18, lodIndex++) {
        slot = record;
        pLabel = labels;

        for (side = 0; side < WHEELMOD_SIDES; side++, pLabel++, slot += 4) {
            labels[0] = wheelmod_label_left;
            labels[1] = wheelmod_label_right;
            sprintf(name, wheelmod_fmt_lod_side, baseName, lodIndex, *pLabel);

            if (!fn_8012C33C(name)) {
                sprintf(name, wheelmod_fmt_lod, baseName, lodIndex);
            }

            /* the first LOD may fall back to the second one's models, "<base>1<L|R>.mod" */
            if (!fn_8012C33C(name) && lodIndex == 0) {
                sprintf(name, wheelmod_fmt_one_side, baseName, *pLabel);
                if (!fn_8012C33C(name)) {
                    sprintf(name, (const char *)&wheelmod_fmt_one, baseName);
                }
                borrowed = 1;
            }

            /* remap the name in place; LOD 1 must not remap what LOD 0 already remapped */
            if (lodIndex != 1 || !borrowed) {
                if (((WheelModResource *)arg1)->lookup(wheelmod_key_slow_remap)) {
                    fn_801F004C((int)name, ((WheelMod *)arg0)->slowRemapGroup, ((WheelModResource *)arg1)->lookup(wheelmod_key_slow_remap));
                }
                if (((WheelModResource *)arg1)->lookup(wheelmod_key_fast_remap)) {
                    fn_801F004C((int)name, ((WheelMod *)arg0)->fastRemapGroup, ((WheelModResource *)arg1)->lookup(wheelmod_key_fast_remap));
                }
            }

            /* slot walks this LOD's handles: the LOD table starts at 0x28 in the record,
             * its fast_remap models 8 bytes behind the slow_remap ones. */
            *(int *)(slot + WHEELMOD_LOD_SLOW_SLOT) = fn_802C6FC0(name, ((WheelMod *)arg0)->slowRemapGroup, 0);
            *(int *)(slot + WHEELMOD_LOD_FAST_SLOT) = fn_802C6FC0(name, ((WheelMod *)arg0)->fastRemapGroup, 0);
        }
    }

    /* scale the models so that the first one is as wide as the wheel's "width" */
    if (!((float)__fabs(((WheelMod *)arg0)->width) <= wheelmod_zero)) {
        fn_802C77F0(((WheelMod *)arg0)->lods[0].slowRemap[0], bbox);
        ((WheelMod *)arg0)->modelScale = ((WheelMod *)arg0)->width / (bbox[1] - bbox[0]);
    }
}

extern void fn_801345D8(void *, int, const char *, ...);
extern "C" void fn_801345D8(void *, int, const char *, ...);
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801F06DC(void *arg0, void *arg1) {
    class Fn801F06DCResource {
    public:
        virtual void pad0();
        virtual int test(const char *);
        virtual void *pad2();
        virtual int find(const char *);
        virtual void *pad4();
        virtual void pad5();
        virtual void pad6();
        virtual float getValue(const char *);
        virtual float getValueWithDefault(const char *, float);
    };

    void *output = arg0;
    char *strings = lbl_8033A3F0;
    char name[0x40];
    char valueName[0x20];
    int id;
    int current;
    int next;
    int countAfter;
    int fallbackHandle;
    int one;
    float value;
    float fallbackValue;

    if (((Fn801F06DCResource *)arg1)->test(strings + 0x90) != 0) {
        id = ((Fn801F06DCResource *)arg1)->find(strings + 0x90);
        *(volatile int *)((char *)output + 0x40) = 0;
        while ((current = *(volatile int *)((char *)output + 0x40)) < 8) {
            next = current + 1;
            fn_801345D8(name, 0x40, strings + 0x60, id, next);
            fn_801345D8(valueName, 0x20, (char *)&lbl_8055B0C8,
                        *(volatile int *)((char *)output + 0x40));
            if (fn_8012C33C(name) == 0) break;
            *(void **)((char *)output +
                (*(volatile int *)((char *)output + 0x40) << 3)) =
                    (void *)fn_802C6FC0(name, 0, 0);
            value = ((Fn801F06DCResource *)arg1)->getValue(valueName);
            *(float *)((char *)output +
                (*(volatile int *)((char *)output + 0x40) << 3) + 4) =
                    value * value;
            countAfter = *(volatile int *)((char *)output + 0x40) + 1;
            *(volatile int *)((char *)output + 0x40) = countAfter;
        }
        *(float *)((char *)output + 0x44) =
            ((Fn801F06DCResource *)arg1)->getValue(strings + 0x9C);
        fallbackValue = *(volatile float *)&lbl_80562F28;
        value = ((Fn801F06DCResource *)arg1)->getValueWithDefault(
            strings + 0xA8, fallbackValue);
        *(float *)((char *)output + 0x48) = value * value;
    } else {
        fallbackHandle = fn_802C6FC0(
            (char *)((Fn801F06DCResource *)arg1)->find((char *)&lbl_8055B0F0),
            0, 0);
        fallbackValue = lbl_80562F1C;
        one = 1;
        *(int *)output = fallbackHandle;
        *(float *)((char *)output + 4) = fallbackValue;
        *(volatile int *)((char *)output + 0x40) = one;
        *(float *)((char *)output + 0x44) =
            ((Fn801F06DCResource *)arg1)->getValue((char *)&lbl_8055B0F8);
    }
}
#pragma pop

#pragma push
#pragma dont_inline on
#pragma cplusplus on
extern int lbl_8055B100;
extern int lbl_8055B108;
extern int lbl_8055B0F0;
extern int lbl_8055B10C;
extern char lbl_8033A4A4[];
extern char lbl_8033A4C8[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" int fn_8012C33C(char *);
extern "C" void *fn_80131808(void *);
extern "C" void fn_80131818(void *);
extern "C" void fn_801F0208(void *, void *, char *);
extern "C" void fn_801F06DC(void *, void *);
extern "C" void fn_801F08AC(int, const char *);
extern "C" void fn_801F08AC(int arg0, const char *arg1) {
    class Fn801F08ACResource {
    public:
        virtual void *lookup(const char *);
        virtual void unused();
        virtual int has(const char *);
    };

    char name[0x20];
    Fn801F08ACResource *resource;
    strncpy((char *)arg0, arg1, 0x10);
    *(char *)(arg0 + 0xF) = 0;
    sprintf(name, (const char *)&lbl_8055B100, arg1);
    if (fn_8012C33C(name) == 0) {
        fn_802E317C(lbl_8033A4A4, arg1);
    }
    resource = (Fn801F08ACResource *)fn_80131808(name);
    fn_801F0148((void *)arg0, resource->lookup(lbl_8033A4C8));
    fn_801F0208((void *)arg0, resource->lookup((const char *)&lbl_8055B108), name);
    ((void (*)(void *, void *))fn_801F0488)((void *)arg0, resource->lookup((const char *)&lbl_8055B0F0));
    if (resource->has((const char *)&lbl_8055B10C) != 0) {
        fn_801F06DC((char *)arg0 + 0xEC, resource->lookup((const char *)&lbl_8055B10C));
    } else {
        *(int *)(arg0 + 0x12C) = 0;
    }
    fn_80131818(resource);
}
#pragma pop

#pragma pop
extern float lbl_80562F10;
extern float lbl_80562F14;
extern float lbl_80562F18;
extern int lbl_8055B0C0;
extern int lbl_8055EBEC;
extern int lbl_8055EBF0;
int stricmp(const char *, const char *);
void fn_801F08AC(int, const char *);
#pragma scheduling invalid_target
int fn_801F09FC(const char *arg0) {
    int offset = 0;
    int count = 0;
    while (count < lbl_8055EBF0) {
        if (stricmp((const char *)(lbl_8055EBEC + offset), arg0) == 0) {
            return lbl_8055EBEC + count * 0x138;
        }
        offset += 0x138;
        count++;
    }
    {
        int index = lbl_8055EBF0;
        int result = lbl_8055EBEC + index * 0x138;
        lbl_8055EBF0 = index + 1;
        fn_801F08AC(result, arg0);
        return result;
    }
}
#pragma scheduling on
extern int fn_8012850C(int, void *);
extern char lbl_8033A4D4[];
extern float lbl_80562F2C;
int fn_801F0AA0(void) {
    int *p;
    int offset;
    int count;
    int i;
    float value;

    lbl_8055EBEC = fn_8012850C(0x9C0, lbl_8033A4D4);
    lbl_8055EBF0 = 0;
    value = lbl_80562F2C;

    offset = 0;
    count = 0;
    for (i = 0; i < 4; i++) {
        p = (int *)(lbl_8055EBEC + offset);
        *(char *)p = 0;
        offset += 0x138;
        p[4] = count;
        p[5] = count + 1;
        count += 2;
        p[10] = -1; p[12] = -1; p[11] = -1; p[13] = -1;
        *(float *)((char *)p + 0x38) = value; *(char *)((char *)p + 0x3C) = 0;
        p[16] = -1; p[18] = -1; p[17] = -1; p[19] = -1;
        *(float *)((char *)p + 0x50) = value; *(char *)((char *)p + 0x54) = 0;
        p[22] = -1; p[24] = -1; p[23] = -1; p[25] = -1;
        *(float *)((char *)p + 0x68) = value; *(char *)((char *)p + 0x6C) = 0;
        p[28] = -1; p[30] = -1; p[29] = -1; p[31] = -1;
        *(float *)((char *)p + 0x80) = value; *(char *)((char *)p + 0x84) = 0;
        p[34] = -1; p[36] = -1; p[35] = -1; p[37] = -1;
        *(float *)((char *)p + 0x98) = value; *(char *)((char *)p + 0x9C) = 0;
        p[40] = -1; p[42] = -1; p[41] = -1; p[43] = -1;
        *(float *)((char *)p + 0xB0) = value; *(char *)((char *)p + 0xB4) = 0;
        p[46] = -1; p[48] = -1; p[47] = -1; p[49] = -1;
        *(float *)((char *)p + 0xC8) = value; *(char *)((char *)p + 0xCC) = 0;
        p[52] = -1; p[54] = -1; p[53] = -1; p[55] = -1;
        *(float *)((char *)p + 0xE0) = value; *(char *)((char *)p + 0xE4) = 0;
        p[58] = 0;
        p[75] = 0;

        p = (int *)(lbl_8055EBEC + offset);
        *(char *)p = 0;
        offset += 0x138;
        p[4] = count;
        p[5] = count + 1;
        count += 2;
        p[10] = -1; p[12] = -1; p[11] = -1; p[13] = -1;
        *(float *)((char *)p + 0x38) = value; *(char *)((char *)p + 0x3C) = 0;
        p[16] = -1; p[18] = -1; p[17] = -1; p[19] = -1;
        *(float *)((char *)p + 0x50) = value; *(char *)((char *)p + 0x54) = 0;
        p[22] = -1; p[24] = -1; p[23] = -1; p[25] = -1;
        *(float *)((char *)p + 0x68) = value; *(char *)((char *)p + 0x6C) = 0;
        p[28] = -1; p[30] = -1; p[29] = -1; p[31] = -1;
        *(float *)((char *)p + 0x80) = value; *(char *)((char *)p + 0x84) = 0;
        p[34] = -1; p[36] = -1; p[35] = -1; p[37] = -1;
        *(float *)((char *)p + 0x98) = value; *(char *)((char *)p + 0x9C) = 0;
        p[40] = -1; p[42] = -1; p[41] = -1; p[43] = -1;
        *(float *)((char *)p + 0xB0) = value; *(char *)((char *)p + 0xB4) = 0;
        p[46] = -1; p[48] = -1; p[47] = -1; p[49] = -1;
        *(float *)((char *)p + 0xC8) = value; *(char *)((char *)p + 0xCC) = 0;
        p[52] = -1; p[54] = -1; p[53] = -1; p[55] = -1;
        *(float *)((char *)p + 0xE0) = value; *(char *)((char *)p + 0xE4) = 0;
        p[58] = 0;
        p[75] = 0;
    }
    return (int)p;
}

int fn_80128670(int);
void fn_802C6CF8(int);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
int fn_801F0CC4(int unused) {
    int i, j, k;
    int offset;
    int base;
    int *entry;
    i = 0;
    offset = 0;
    while (i < lbl_8055EBF0) {
        j = 0;
        base = lbl_8055EBEC + offset;
        base += 0x28;
        while (j < *(int *)(offset + lbl_8055EBEC + 0xE8)) {
            entry = (int *)(base + j * 0x18);
            for (k = 0; k < 2; k++) {
                if (entry[k] != -1) fn_802C6CF8(entry[k]);
                if (entry[k + 2] != -1) fn_802C6CF8(entry[k + 2]);
            }
            j++;
        }
        k = 0;
        while (k < *(int *)(offset + lbl_8055EBEC + 0x12C)) {
            fn_802C6CF8(*(int *)(offset + lbl_8055EBEC + 0xEC + k * 8));
            k++;
        }
        offset += 0x138;
        i++;
    }
    fn_80128670(lbl_8055EBEC);
    lbl_8055EBEC = 0;
    lbl_8055EBF0 = 0;
}
#pragma pop
int fn_801F09FC(const char *);
void fn_801F1878(void *);
#pragma dont_inline on
int fn_801F0DC0(int arg0, int arg1, int arg2, int arg3) {
    int zero = 0;
    *(int *)(arg0 + 0) = fn_801F09FC((const char *)arg1);
    *(int *)(arg0 + 4) = zero;
    *(int *)(arg0 + 8) = arg2;
    *(int *)(arg0 + 0xC) = arg3;
    if ((arg3 == 0) || (arg3 == 2)) {
        float z = lbl_80562F1C;
        float one = lbl_80562F18;
        register unsigned int normalized = (unsigned int)__cntlzw(1) >> 5;
        *(int *)(arg0 + 0x10) = normalized;
        *(unsigned char *)(arg0 + 0x14) = zero;
        *(float *)(arg0 + 0x18) = one;
        *(float *)(arg0 + 0x1C) = z;
        *(float *)(arg0 + 0x20) = z;
        *(float *)(arg0 + 0x24) = z;
        *(float *)(arg0 + 0x28) = one;
        *(float *)(arg0 + 0x2C) = z;
        *(float *)(arg0 + 0x30) = z;
        *(float *)(arg0 + 0x34) = z;
        *(float *)(arg0 + 0x38) = one;
        *(float *)(arg0 + 0x3C) = z;
        *(float *)(arg0 + 0x40) = z;
        *(float *)(arg0 + 0x44) = z;
        fn_801F1878((void *)arg0);
    }
    return arg0;
}
extern float lbl_80562F1C;
#pragma dont_inline on
int fn_801F0E88(int arg0, int arg1) {
    int result = fn_801F09FC((const char *)arg1);
    float zero = lbl_80562F1C;
    float one = lbl_80562F18;
    *(int *)(arg0 + 0) = result;
    *(int *)(arg0 + 4) = 0;
    *(int *)(arg0 + 8) = -1;
    *(int *)(arg0 + 0xC) = -1;
    *(int *)(arg0 + 0x10) = 0;
    *(char *)(arg0 + 0x14) = 1;
    *(float *)(arg0 + 0x18) = one;
    *(float *)(arg0 + 0x1C) = zero;
    *(float *)(arg0 + 0x20) = zero;
    *(float *)(arg0 + 0x24) = zero;
    *(float *)(arg0 + 0x28) = one;
    *(float *)(arg0 + 0x2C) = zero;
    *(float *)(arg0 + 0x30) = zero;
    *(float *)(arg0 + 0x34) = zero;
    *(float *)(arg0 + 0x38) = one;
    *(float *)(arg0 + 0x3C) = zero;
    *(float *)(arg0 + 0x40) = zero;
    *(float *)(arg0 + 0x44) = zero;
    return arg0;
}
#pragma dont_inline off
int fn_801F0F18(int arg0, int arg1) {
    if (arg0 != 0) {
        if (*(unsigned char *)(arg0 + 0x14) == 0) fn_801F18F0();
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern float lbl_80562F30;
extern float lbl_80562F34;
float fn_801F159C(void **);
void fn_80015A20(void *, float *);
void fn_80015B20(void *, void *, void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801F0F78(void *arg0, void *arg1, void *arg2, float scale) {
    int flags = *(int *)((char *)arg1 + 0x60);
    float matrix[9], matrix2[9];
    Vec point, angles, angles2;
    float *m = (float *)arg2;
    Vec *out = (Vec *)((char *)arg0 + 0x3c);
    float x,y,z, a,b,c,d,e,f,g,h,i;
    unsigned int w0,w1,w2,w3,w4,w5,w6,w7,w8;
    int mode;
    if (flags & 8) {
        *(int *)((char *)arg0 + 4) = 3;
        return;
    }
    if (flags & 2) *(int *)((char *)arg0 + 4) = 2;
    else if (flags & 4) *(int *)((char *)arg0 + 4) = 1;
    else *(int *)((char *)arg0 + 4) = 0;
    if (*(float *)((char *)arg1 + 0x30) > lbl_80562F30)
        *(int *)((char *)arg0 + 4) |= 0x10;
    point.x = ((Vec *)arg1)->x; point.y = ((Vec *)arg1)->y; point.z = ((Vec *)arg1)->z;
    x = fn_801F159C((void **)arg0);
    y = point.y;
    z = *(float *)((char *)arg1 + 0x34);
    point.y = y + x;
    *(float *)((char *)arg0 + 0x48) = z;
    mode = *(int *)((char *)arg0 + 0xc);
    mode = mode == 0 || mode == 2;
    if (out == &point) {
        y = point.y; z = point.z; x = point.x;
        d=y*m[3]; e=y*m[4];
        a=x*m[0]; b=x*m[1]; c=x*m[2]; f=y*m[5];
        g=z*m[6]; h=z*m[7]; i=z*m[8];
        out->x=g+(a+d); out->y=h+(b+e); out->z=i+(c+f);
    } else {
        out->x=point.z*m[6]+(point.y*m[3]+point.x*m[0]);
        out->y=point.z*m[7]+(point.y*m[4]+point.x*m[1]);
        out->z=point.z*m[8]+(point.y*m[5]+point.x*m[2]);
    }
    x = out->x + m[9];
    y = out->y + m[10];
    w0=((unsigned int *)m)[0]; w1=((unsigned int *)m)[1]; w2=((unsigned int *)m)[2];
    w3=((unsigned int *)m)[3]; w4=((unsigned int *)m)[4]; w5=((unsigned int *)m)[5];
    w6=((unsigned int *)m)[6]; w7=((unsigned int *)m)[7]; w8=((unsigned int *)m)[8];
    out->x = x;
    z = out->z + m[11];
    out->y = y;
    ((unsigned int *)((char *)arg0 + 0x18))[0]=w0;
    out->z = z;
    ((unsigned int *)((char *)arg0 + 0x18))[1]=w1; ((unsigned int *)((char *)arg0 + 0x18))[2]=w2;
    ((unsigned int *)((char *)arg0 + 0x18))[3]=w3; ((unsigned int *)((char *)arg0 + 0x18))[4]=w4;
    ((unsigned int *)((char *)arg0 + 0x18))[5]=w5; ((unsigned int *)((char *)arg0 + 0x18))[6]=w6;
    ((unsigned int *)((char *)arg0 + 0x18))[7]=w7; ((unsigned int *)((char *)arg0 + 0x18))[8]=w8;
    angles.x = lbl_80562F1C; angles.y = lbl_80562F1C; angles.z = *(float *)((char *)arg1 + 0x2c);
    fn_80015A20(matrix, (float *)&angles);
    fn_80015B20((char *)arg0 + 0x18, matrix, (char *)arg0 + 0x18);
    y = *(float *)((char *)arg1 + 0x28) + (mode ? lbl_80562F1C : lbl_80562F34);
    angles2.x = lbl_80562F1C; angles2.y = y; angles2.z = lbl_80562F1C;
    fn_80015A20(matrix2, (float *)&angles2);
    fn_80015B20((char *)arg0 + 0x18, matrix2, (char *)arg0 + 0x18);
    if (!((float)__fabs(scale - lbl_80562F18) <= lbl_80558DC4)) {
        c=(*(float *)((char *)arg0 + 32))*scale; b=(*(float *)((char *)arg0 + 28))*scale; a=(*(float *)((char *)arg0 + 24))*scale;
        d=(*(float *)((char *)arg0 + 36))*scale; e=(*(float *)((char *)arg0 + 40))*scale; f=(*(float *)((char *)arg0 + 44))*scale;
        g=(*(float *)((char *)arg0 + 48))*scale; h=(*(float *)((char *)arg0 + 52))*scale; i=(*(float *)((char *)arg0 + 56))*scale;
        (*(float *)((char *)arg0 + 24))=a; (*(float *)((char *)arg0 + 28))=b; (*(float *)((char *)arg0 + 32))=c; (*(float *)((char *)arg0 + 36))=d; (*(float *)((char *)arg0 + 40))=e;
        (*(float *)((char *)arg0 + 44))=f; (*(float *)((char *)arg0 + 48))=g; (*(float *)((char *)arg0 + 52))=h; (*(float *)((char *)arg0 + 56))=i;
    }
}
#pragma pop
void fn_801F131C(int arg0, int arg1) {
    if (*(unsigned int *)(arg0 + 4) != 3) {
        int value;
        if (arg1 != 0) value = 0;
        else value = fn_801F15A8(arg0, arg0 + 0x3C);
        fn_801F163C(arg0, value, *(float *)(arg0 + 0x48));
    }
}

void fn_801F1378(void *arg0) {
    if (*(unsigned int *)((char *)arg0 + 4) != 3)
        fn_801F163C(arg0, 0, *(float *)((char *)arg0 + 0x48));
}

#pragma push
#pragma scheduling off
int fn_801F1394(int *arg0, int arg1) {
    int frame = fn_801F1978(0);
    int index = *(int *)((char *)arg0 + 0x10);
    int *base = *(int **)arg0;
    int *element = (int *)((char *)base + index * 4);
    int value = *(int *)((char *)element + 0x28);
    int zero;
    zero = value - value;
    fn_802C70AC(value, arg1, zero, frame);
}
#pragma pop
void fn_801F13F4(int *arg0, float arg1, float arg2) {
    char *base = (char *)*(int *)arg0 + 0xEC;
    char *entry;
    int count;
    if (arg1 > *(float *)(base + 0x48)) return;
    if (*(unsigned int *)(arg0 + 1) == 3) return;
    count = *(int *)(base + 0x40) - 1;
    entry = base + count * 8;
    while (count >= 0 && arg1 < *(float *)(entry + 4)) {
        entry -= 8;
        count--;
    }
    if (count < 0) return;
    fn_802C7AE0(*(int *)(base + count * 8), (char *)arg0 + 0x18, -1, *(float *)(base + 0x44) + arg2);
}

void fn_801F1474(int *arg0, void *arg1) {
    int base = *arg0;
    if (*(int *)(base + 0x12C) <= 0) return;
    fn_802C7AE0(*(int *)(base + 0xEC), arg1, -1);
}

#pragma push
#pragma processor 750
int fn_801F1494(int arg0, void *arg1, short arg2) {
    struct Entry {
        int id;
        float limit;
    };
    struct Table {
        struct Entry entries[8];
        int count;
        float f44;
        float f48;
    };

    short saved = arg2;
    int base = *(int *)arg0;
    struct Table *table = (struct Table *)(base + 0xEC);
    float speed = ((float (*)(int, int))fn_801E88F0)(-1, base);
    float squared = speed * speed;
    float value = ((float (*)(void *))fn_802C88E8)((char *)arg0 + 0x3C);
    struct Entry *entry;
    int count;

    value = value * squared;
    count = table->count - 1;
    entry = &table->entries[count];
    while (count >= 0 && value < entry->limit) {
        entry--;
        count--;
    }

    if (value < table->f48 && count >= 0) {
        Vec vec = *(Vec *)((char *)arg1 + 0x24);
        if (fn_801EA03C(&saved, &vec)) {
            float second = *(float *)((char *)arg1 + 0x28);
            if (second > vec.y) {
                float f = table->f44 + second - vec.y;
                fn_802C7AE0(table->entries[count].id, arg1, -1, f);
            }
        }
    }
}
#pragma pop
float fn_801F159C(void **arg0) {
    return *(float *)((char *)*arg0 + 0x18);
}

int fn_801F15A8(void **arg0, int arg1) {
    float scale;
    float threshold;
    void *base;
    int count;
    int i;
    int offset;

    scale = fn_801E88F0(-1);
    scale = scale * scale;
    threshold = fn_802C88E8(arg1);
    threshold = threshold * scale;

    base = *arg0;
    i = 0;
    count = *(int *)((char *)base + 0xE8);
    offset = 0;
    while (i < count) {
        if (threshold < *(volatile float *)((char *)base + offset + 0x38))
            return i;
        offset += 0x18;
        i++;
    }
    return count - 1;
}

void fn_801F17C8(int unused) {
    memset(lbl_80488798, 0, 0x100);
}

#pragma push
#pragma scheduling invalid_target
int fn_801F17DC(void *arg0) {
    int *entry = lbl_80488798;
    int i = 0;
    do {
        if (*entry != 0)
            fn_802E317C(lbl_8033A51C);
        i++;
        entry++;
    } while (i < 0x40);
}
#pragma pop
extern int lbl_80488798[64];
extern char lbl_8033A544[];
void fn_802E317C(const char *, ...);
int fn_801F196C(int, int);
#pragma push
#pragma small_data off
#pragma pop
int fn_801F196C();
int fn_801F1848(void) {
    return lbl_80488798[fn_801F196C()];
}
#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
void fn_801F1878(void *arg0) {
    int index = fn_801F196C(*(int *)((char *)arg0 + 8), *(int *)((char *)arg0 + 0xC));
    if (lbl_80488798[index] != 0) {
        fn_802E317C(lbl_8033A544, *(int *)((char *)arg0 + 8), *(int *)((char *)arg0 + 0xC));
    }
    lbl_80488798[index] = (int)arg0;
}

#pragma push
#pragma use_lmw_stmw off
int fn_801F18F0(void *arg0) {
    int index = fn_801F196C(*(int *)((char *)arg0 + 8),
                            *(int *)((char *)arg0 + 0xC));
    if (lbl_80488798[index] == 0) {
        fn_802E317C(lbl_8033A578,
                    *(int *)((char *)arg0 + 8),
                    *(int *)((char *)arg0 + 0xC));
        lbl_80488798[index] = 0;
    }
}
#pragma pop
int fn_801F196C(int a, int b) { return b + a * 4; }

extern char lbl_8033A5B0[];
#pragma push
#pragma scheduling invalid_target
int fn_801F1978(register int arg) {
    int result = -1;
    arg &= ~0x10;
    switch (arg) {
    case 0:
        result = 1;
        result |= 0x100;
        break;
    case 1:
        result = 2;
        result |= 0x100;
        break;
    case 2:
        result = 0x200;
        break;
    default: {
        void (*report)(const char *, ...) = fn_802E317C;
        report(lbl_8033A5B0);
        break;
    }
    }
    return result;
}
#pragma pop
short fn_801EAC3C(void);
int fn_801F1494(int, void *, short);
int fn_801EAB2C(void);
int fn_801EAB80(void *, int);
int fn_80297988(void *);
int memset(void *, int, unsigned int);
extern char lbl_8033A5E8[];
void *fn_801F19FC(void *arg0, int arg1) {
    fn_801EAB2C();
    *(int **)arg0 = (int *)lbl_8033A5E8;
    fn_801EAB80(arg0, arg1);
    memset((char *)arg0 + 0x3C, 0, 0x44);
    *(int *)((char *)arg0 + 0x80) = 0;
    fn_80297988(arg0);
    return arg0;
}
#pragma scheduling on
int fn_801F1A70(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
void fn_801F1AB0(void *arg0) {
    int *value = *(int **)((char *)arg0 + 0x80);
    if (value != 0) {
        fn_801F1394(value, (int)((char *)arg0 + 4));
    }
}

void fn_801F1AD0(void *arg0) {
    if (*(int *)((char *)arg0 + 0x80) != 0) {
        fn_801F1494(*(int *)((char *)arg0 + 0x80), (char *)arg0 + 4, fn_801EAC3C());
    }
}

void fn_801EABA8(void);
int fn_801F1848(void);
#pragma scheduling invalid_target
void fn_801F1B1C(void *arg0, void *arg1) {
    float v17;
    unsigned char flag;
    int v13, v14;
    short v16;
    int v12, v11, v10, v9, v8, v7, v6;
    register int v1, v2, v3, v4, v5;
    fn_801EABA8();
    flag = *(volatile unsigned char *)((char *)arg1 + 0x40);
    v1 = *(volatile int *)((char *)arg1 + 0x00);
    v2 = *(volatile int *)((char *)arg1 + 0x04);
    v3 = *(volatile int *)((char *)arg1 + 0x08);
    v4 = *(volatile int *)((char *)arg1 + 0x0C);
    v5 = *(volatile int *)((char *)arg1 + 0x10);
    v6 = *(volatile int *)((char *)arg1 + 0x14);
    v7 = *(volatile int *)((char *)arg1 + 0x18);
    v8 = *(volatile int *)((char *)arg1 + 0x1C);
    v9 = *(volatile int *)((char *)arg1 + 0x20);
    v10 = *(volatile int *)((char *)arg1 + 0x24);
    v11 = *(volatile int *)((char *)arg1 + 0x28);
    v12 = *(volatile int *)((char *)arg1 + 0x2C);
    v16 = *(volatile short *)((char *)arg1 + 0x30);
    v13 = *(volatile int *)((char *)arg1 + 0x34);
    v14 = *(volatile int *)((char *)arg1 + 0x38);
    v17 = *(volatile float *)((char *)arg1 + 0x3C);
    *(volatile int *)((char *)arg0 + 0x3C) = v1;
    *(volatile int *)((char *)arg0 + 0x40) = v2;
    *(volatile int *)((char *)arg0 + 0x44) = v3;
    *(volatile int *)((char *)arg0 + 0x48) = v4;
    *(volatile int *)((char *)arg0 + 0x4C) = v5;
    *(volatile int *)((char *)arg0 + 0x50) = v6;
    *(volatile int *)((char *)arg0 + 0x54) = v7;
    *(volatile int *)((char *)arg0 + 0x58) = v8;
    *(volatile int *)((char *)arg0 + 0x5C) = v9;
    *(volatile int *)((char *)arg0 + 0x60) = v10;
    *(volatile int *)((char *)arg0 + 0x64) = v11;
    *(volatile int *)((char *)arg0 + 0x68) = v12;
    *(volatile short *)((char *)arg0 + 0x6C) = v16;
    *(volatile int *)((char *)arg0 + 0x70) = v13;
    *(volatile int *)((char *)arg0 + 0x74) = v14;
    *(volatile float *)((char *)arg0 + 0x78) = v17;
    *(volatile unsigned char *)((char *)arg0 + 0x7C) = flag;
    if (flag != 0)
        *(volatile int *)((char *)arg0 + 0x80) = fn_801F1848();
    else
        *(volatile int *)((char *)arg0 + 0x80) = 0;
}
