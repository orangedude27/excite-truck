// Code of main that had no source file yet: decomp.wtf gave it this one.
extern char lbl_80348CF8[];
extern char lbl_80348D28[];
extern int stricmp(const char *, const char *);
extern int fn_802E317C(const char *, ...);

/* The particle types a table entry can name, in the order their codes go:
 * 0 "Simple", 1 "Animated", 2 "Rotating".  A name outside the table is logged
 * with particleTypeNotFound and comes back as PARTICLE_TYPE_UNKNOWN. */
#define particleTypeNames     ((char **)&lbl_80348CF8)
#define particleTypeNotFound  lbl_80348D28 /* "particle: could not find type '%s'" */
#define PARTICLE_TYPE_COUNT   3
#define PARTICLE_TYPE_UNKNOWN 3
extern float fn_802C9A4C(float);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern int fn_8028FA1C(int);
extern char lbl_80348FD0[];
extern int fn_8002F768(void *, int, int);
// split_file divides it into the game's real files (file_status shows its range).
typedef struct { float v[7]; unsigned char c[3]; float f0; float f1; } EfEntry;
typedef struct { float x, y, z; } EfVec;
typedef struct { EfVec a; EfVec b; } EfPair;
typedef struct { int mode; char pad4[0x34]; unsigned char en38; char pad39[0x4B]; int v84; unsigned char en88; char pad89[3]; void *buf; int head; int tail; int cap; } EfObj;
typedef struct { EfPair p; float v6; unsigned char c0, c1, c2; float f0; float f1; } EfEntry2;

/* One effect object, seen as the 0x8C-byte create-args block the effect
 * creators (fn_80289C80, fn_80289D94, ... in text_802888D8) fill in on the
 * stack: fn_8028E61C clears it, fn_8028E2F8/fn_8028F7AC build the effect from
 * it and fn_8028FD00 copies it field by field into the new object and fills in
 * the derived fields at +0xA0, +0xA8 and +0xAC.  The game's own names for the
 * parameters are not known; the fields are named for how the effect code uses
 * them (the emitter half is the EfObj above). */
typedef struct EfEffect {
    int mode;                /* 0x00: effect type; fn_8028FD00 switches on it */
    int emitterCount;        /* 0x04: emitters to allocate (fn_8028F7AC) */
    float period;            /* 0x08: 1.0f/it is cached at +0xA0 */
    float fc;                /* 0x0C */
    int f10, f14, f18;       /* 0x10: one triple, copied as words */
    int f1c, f20, f24;       /* 0x1C: the second triple */
    float f28, f2c, f30;     /* 0x28 */
    float blend;             /* 0x34: clamped to [0.0f, 1.0f] by fn_8028FD00 */
    unsigned char en38;      /* 0x38: enables the mode 0 / 2 colour byte */
    unsigned char pad39[3];
    float f3c, f40;          /* 0x3C */
    int f44;                 /* 0x44: 1, 5 or 6 */
    float f48, f4c;          /* 0x48 */
    float f50, f54, f58, f5c; /* 0x50: motion and colour parameters */
    float f60, f64, f68, f6c;
    float f70, f74, f78, f7c;
    float f80;               /* 0x80 */
    int powerOf4;            /* 0x84: a count as a power of 4 (EfObj's v84) */
    unsigned char en88;      /* 0x88: enables the mode 1 colour byte */
    unsigned char f89;       /* 0x89 */
    unsigned char pad8a[2];
    void *particles;         /* 0x8C: the 0x28-byte particle entries (EfObj's buf) */
    int playIndex;           /* 0x90: timed playback cursor (-1 = stopped) */
    int playCount;           /* 0x94 */
    int poolCount;           /* 0x98 */
    unsigned char pad9c[4];
    float invPeriod;         /* 0xA0: 1.0f / period */
    int texHandle;           /* 0xA4: texture slot, fn_802CAC28 / fn_802CAC54 */
    int sqrtCount;           /* 0xA8: sqrt of powerOf4, for effect type 1 */
    float invSqrtCount;      /* 0xAC: 1.0f / sqrtCount */
} EfEffect;

/* One of the nine emitter lists the effect sorter keeps at lbl_804B34B0
 * (0x104 bytes each): up to 64 emitter pointers with the number held at
 * +0x100.  fn_8028ED8C appends an emitter, fn_8028ED74 empties the list and
 * fn_8028EDA8 drops one by identity. */
typedef struct EfList {
    void *item[64]; /* at 0x00 */
    int count;      /* at 0x100 */
} EfList;

/* The two emitter fields the sorter below reads.  +0x44 is the emitter's
 * priority (1..9, read from its parameter block with default 5) and picks the
 * list it is filed in; +0xA4 is the texture it draws with, a handle into the
 * 512 0x4C-byte texture slots (fn_802CAC28 takes it, fn_802CAC54 releases it). */
typedef struct EfEmitter {
    char pad_0[0x44];
    int priority;   /* at 0x44 */
    char pad_48[0x5C];
    int texHandle;  /* at 0xA4 */
} EfEmitter;

/* Cache of loaded effect tables: up to 40 0x18-byte entries keyed by resource
 * name, with the number of live entries held at +0x600.  fn_8028EE34 looks an
 * entry up, fn_8028EEB4 adds one and fn_8028EF44 releases one; fn_8028EE1C and
 * fn_8028EE28 reset the count to empty the whole cache. */
typedef struct EfTableCache {
    char entries[0x600];
    int count; /* at 0x600 */
} EfTableCache;

/* fn_8028F040's "the two lists share no texture", which fn_8028F114 also takes
 * as "no group to pin to the front / back of this run". */
#define EF_NO_TEXTURE (-2)

extern char lbl_803490D4[];
extern int fn_80128668(void *);
extern int lbl_8055C8E0;
extern int lbl_804B35B4[];
extern int fn_801284F8(int, void *);
extern int fn_8028F7AC(void *, void *, int);
extern void fn_8028ED8C(void *, int);
extern void fn_8028F5A0(int, int);
extern float lbl_80564424;
extern void fn_8028FB98(void *, int, float *, float);
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028EE28(void *);
extern void fn_8028ED80(void *);
extern void fn_8028F2EC();
extern int fn_8028F0C0(int *, int, int);
extern void fn_8028F114(int *, int, int);
extern void *memcpy(void *, const void *, unsigned int);
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
extern int lbl_8055F748;
extern int lbl_804B34B0_arr[];
struct EmitterListPool {
    char list0[0x104];
    char list1[0x104];
    char list2[0x104];
};
#pragma push
#pragma small_data off
typedef int lbl_804B34B0_t;
#pragma push
#pragma small_data off
void fn_8028DFB0(void) {
    /* Commit the current emitter from the primary sort list (lbl_804B34B0_arr):
       if it has entries, finalize/sort the list and record its first item as
       the current one (lbl_8055F740), then clear the pending flag (lbl_8055F744). */
    if (*((int *)((char *)&lbl_804B34B0_arr[0] + 0x100)) > 0) {
        fn_8028F2EC();
        lbl_8055F740 = lbl_804B34B0_arr[0];
    }
    lbl_8055F744 = 0;
}
#pragma pop
extern unsigned char lbl_8055F73D;
extern float lbl_80564420;
extern int lbl_8055F748;
void fn_8028DF58(void);
void fn_8028ED74(void *);
void fn_8028EE1C(void *);
void fn_8028F8C4(int);
float fn_801E7E18(void);
void fn_8028DFFC(void) {
#define initEffectEmitters fn_8028DF58
#define gEffectsReady      lbl_8055F73D
    /* Initialise the effect emitter lists, then flag the effect system as ready. */
    initEffectEmitters();
    gEffectsReady = 1;
#undef gEffectsReady
#undef initEffectEmitters
}

/* RealName: fn_8028E024 (commit current item from primary list) */
void fn_8028E024(void) {
#define primaryList lbl_804B34B0_arr
#define currentItem lbl_8055F740
#define hasPendingItem lbl_8055F744
    /* If the primary list has items, finalize/sort it and remember its first item; clear pending flag. */
    if (*((int *)((char *)&primaryList[0] + 0x100)) > 0) {
        fn_8028F2EC();
        currentItem = primaryList[0];
    }
    hasPendingItem = 0;
#undef primaryList
#undef currentItem
#undef hasPendingItem
}

/* Set the particle system's frame time to `time` and allow particle adds. */
void fn_8028E070(float time) {
    #define gParticleTime     lbl_8055F738
    #define gAllowParticleAdd lbl_8055F73C
    gParticleTime = time;
    gAllowParticleAdd = 1;
    #undef gParticleTime
    #undef gAllowParticleAdd
}

#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_804B34B0;
#pragma scheduling invalid_target
/* End a particle update pass: advance every effect in the primary emitter list by
 * the frame time, then disallow further particle adds. */
void fn_8028E080(void) {
#define gParticleTime lbl_8055F738
#define gAllowParticleAdd lbl_8055F73C
    EfList *list;
    int *emitter;
    int i;
    emitter = (int *)&lbl_804B34B0;
    list = (EfList *)emitter;
    gAllowParticleAdd = 0;
    i = 0;
    goto test;
body:
    fn_8028F8E0(*emitter, gParticleTime);
    emitter++;
    i++;
test:
    if (i < list->count) goto body;
#undef gAllowParticleAdd
#undef gParticleTime
}
#pragma scheduling on
void fn_8028DF58(void) {
    char *base = (char *)&lbl_804B34B0;
    fn_8028ED74(base);
    do { fn_8028ED74(base + 0x104); } while (0);
    fn_8028EE1C(base + 0x208);
    lbl_8055F740 = 0;
    lbl_8055F744 = 1;
    lbl_8055F748 = 0;
}
void fn_8028E0F0(void) {
    char* base = (char*)&lbl_804B34B0;
    do { fn_8028F5A4(); } while (0);
    fn_8028EE28(base + 0x208);
    fn_8028ED80(base + 0x104);
    fn_8028ED80(base);
}
#pragma pop
extern void fn_8028ED74(void *);
extern void fn_8028EE1C(void *);
extern void fn_8028F8C4(int);
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
/* Reset the playback cursor for every effect in the primary emitter list. */
void fn_8028E138(void) {
    struct Table { int entries[64]; int count; } *list;
    int *emitter;
    int i;
    emitter = (int *)&lbl_804B34B0;
    list = (struct Table *)emitter;
    lbl_8055F738 = 0.0f;
    i = 0;
    goto test;
body:
    fn_8028F8C4(*emitter);
    emitter++;
    i++;
test:
    if (i < list->count) goto body;
}
#pragma pop

/* The particle system's frame time (seconds; fn_801E7E18 returns the time
 * float at the head of the frame data block) and the flag the game's own
 * error strings call allow_particle_add: it is set for the duration of a
 * particle update pass, so adds made outside it can be reported
 * ("particle: added particle outside of ParticlePreUpdate() and
 * ParticlePostUpdate()"). */
#define gParticleTime     lbl_8055F738
#define gAllowParticleAdd lbl_8055F73C

void fn_8028E1A4(void) {
    /* Start a particle update pass: take this frame's time from the frame data
     * block (fn_801E7E18) and allow particle adds until the pass ends. */
    gParticleTime = fn_801E7E18();
    gAllowParticleAdd = 1;
}

#pragma scheduling invalid_target
void fn_8028E1D0(void) {
    /* End a particle update pass: advance every effect in the primary list by the frame time, then disallow further adds. */
    struct Table { int entries[64]; int count; } *list;
    int *emitter;
    int i;
    emitter = (int *)&lbl_804B34B0;
    list = (struct Table *)emitter;
    gAllowParticleAdd = 0;
    i = 0;
    goto test;
body:
    fn_8028F8E0(*emitter, gParticleTime);
    emitter++;
    i++;
test:
    if (i < list->count) goto body;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Draw all emitters in the primary list, batching by texture slot (+0xa4):
 * switch the material only when the slot changes, wrapped in a save/restore
 * of the graphics state. */
void fn_8028E240(void) {
    register float savedState;
    int *base;
    int textureSlot;
    int *entry;
    int currentSlot;
    int index;
    if (lbl_8055F740 == 0) {
        return;
    }
    savedState = fn_802C9A4C(lbl_80564420);
    currentSlot = *(int *)((char *)lbl_8055F740 + 0xa4);
    fn_802C8BD0(currentSlot);
    entry = &lbl_804B34B0;
    base = entry;
    index = (int)(base - base);
    goto test;
loop:
    textureSlot = *(int *)((char *)*entry + 0xa4);
    if (textureSlot != currentSlot) {
        fn_802C8D74();
        fn_802C8BD0(textureSlot);
        currentSlot = textureSlot;
    }
    fn_8028FA1C(*entry);
    entry++;
    index++;
test:
    if (index < base[64]) goto loop;
    fn_802C8D74();
    fn_802C9A4C(savedState);
}
#pragma pop
int fn_8028E2F8(int initData, int postArg, int resourceId) {
    /* Allocate a 0xB0-byte "partman" object, initialize it, register it in both lists, then run the post hook. */
    int object;

    object = fn_801284F8(0xB0, &lbl_8055C8E0);
    if (object != 0) {
        object = ((int (*)(int, int, int))fn_8028F7AC)(object, initData, resourceId);
    }
    fn_8028ED8C(&lbl_804B35B4[0], object);
    fn_8028ED8C(&lbl_804B34B0, object);
    fn_8028F5A0(postArg, object);
    return object;
}

extern float fn_802C9A4C(float);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern int fn_8028FA1C(int);
extern int fn_801284F8(int, void *);
extern int fn_8028F7AC(void *, void *, int);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, int, int, int);
extern int fn_802CAC28(int, int);
extern void fn_8028FD00(void *, void *, int);
extern void fn_8028F854(void);
extern char lbl_80348FC4[];
extern void fn_8028ED8C(void *, int);
extern void fn_8028F5A0(int, int);
extern int lbl_8055C8E0;
extern int lbl_804B35B4[];
extern int fn_8028F858(int, int);
#pragma push
#pragma small_data off
void fn_8028E398(int arg0) {
    /* Remove arg0 from the list at lbl_804B35B4 (fn_8028EDA8); if found, also remove it
     * from lbl_804B34B0_arr and destroy it via fn_8028F858(arg0, 1). */
    if (fn_8028EDA8(&lbl_804B35B4[0], arg0) != 0) {
        fn_8028EDA8((unsigned int *)lbl_804B34B0_arr, arg0);
        fn_8028F858(arg0, 1);
    }
}

#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" int lbl_804B36B8[];
extern "C" int lbl_804B34B0;
extern "C" char lbl_80348D04[];
extern "C" int lbl_8055C8E0;
extern "C" int lbl_8055C8E8;
extern "C" int fn_8028EE34(void *, int, int *);
extern "C" int fn_8028E61C(void *);
extern "C" void *fn_802AE414(const char *);
extern "C" void fn_8028E654(void *, void *);
extern "C" int fn_802E317C(const char *, ...);
extern "C" int fn_801284F8(int, void *);
extern "C" int fn_8028F7AC(void *, void *, int);
extern "C" void fn_8028EEB4(void *, int, const char *);
extern "C" void fn_8028ED8C(void *, int);
extern "C" void fn_8028F5A0(int, int);
extern "C" int fn_8028E3F4(const char *tableName) {
    class TableObject {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual int GetResourceId(const char *name);
    };
    int instance;
    TableObject *tableObject;
    volatile int cachedIndex = -1;
    /* Look up a named table entry in the cache, or load and register a new instance if it is not found. */
    if (fn_8028EE34(lbl_804B36B8, (int)tableName, (int *)&cachedIndex) != 0) {
        char *entry = (char *)&lbl_804B36B8[0] + cachedIndex * 0x18;
        *(int *)(entry + 0x14) += 1;
        return *(int *)(entry + 0x10);
    }
    int loadState[35];
    fn_8028E61C(loadState);
    tableObject = (TableObject *)fn_802AE414(tableName);
    if (tableObject == 0) {
        fn_802E317C(lbl_80348D04, tableName);
    }
    fn_8028E654(loadState, tableObject);
    instance = fn_801284F8(0xB0, &lbl_8055C8E0);
    if (instance != 0) {
        int resourceId = tableObject->GetResourceId((const char *)&lbl_8055C8E8);
        instance = fn_8028F7AC((void *)instance, loadState, resourceId);
    }
    fn_8028EEB4(lbl_804B36B8, instance, tableName);
    fn_8028ED8C(&lbl_804B34B0, instance);
    fn_8028F5A0((int)tableName, instance);
    return instance;
}
#pragma cplusplus off
#pragma pop

extern int fn_8028EF44(void *, unsigned int);
extern int lbl_804B36B8[];
void fn_8028E528(int emitter) {
    /* If the emitter is in the lbl_804B36B8 pool, remove it from the global emitter list and destroy it. */
    if (fn_8028EF44(&lbl_804B36B8[0], (unsigned int)emitter) != 0) {
        fn_8028EF44(&lbl_804B34B0, (unsigned int)emitter);
        fn_8028F858(emitter, 1);
    }
}

#pragma pop
/* Emit particles from `emitter` at position `pos` around `basePos`, using the
 * full spread of 1.0 (lbl_80564424). A fixed-argument wrapper for fn_8028FB98. */
void fn_8028E584(void *emitter, int pos, float *basePos) {
    fn_8028FB98(emitter, pos, basePos, lbl_80564424);
}

extern void fn_8028FAE4(void *, int, float *, float);
void fn_8028E58C(void *emitter, int posA, float *basePos, float angle) {
    /* Forward to the effect emitter (fn_8028FAE4). */
    fn_8028FAE4(emitter, posA, basePos, angle);
}

extern void fn_8028FC40(void *, int, float *, float);
/* Forwarder: emit a particle from the emitter when its index range and probability
   allow it, applying the given angle offset (fn_8028FC40). */
void fn_8028E590(void *emitter, int param, float *basePos, float angleOffset) {
    fn_8028FC40(emitter, param, basePos, angleOffset);
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
/* Map a particle type name read out of a table resource onto its code: the
 * table at particleTypeNames holds "Simple", "Animated" and "Rotating", whose
 * indexes are the codes.  A name none of them matches is logged with
 * particleTypeNotFound and comes back as PARTICLE_TYPE_UNKNOWN.  fn_8028E654
 * stores the result as the type of the particle entry it is parsing. */
int fn_8028E594(const char *typeName) {
    char **list;
    int i;

    list = particleTypeNames;
    i = 0;
    do {
        if (stricmp(typeName, *list) == 0) {
            return i;
        }
        i++;
        list++;
    } while (i < PARTICLE_TYPE_COUNT);
    fn_802E317C(particleTypeNotFound, typeName);
    return PARTICLE_TYPE_UNKNOWN;
}
#pragma pop
void *memset(void *, int, unsigned int);
#pragma push
#pragma small_data off
int fn_8028E61C(void *effectArgs) {
    /* Zero the 0x8C-byte nw4r::ef effect creation descriptor before its fields are filled. */
    memset(effectArgs, 0, 0x8Cu);
    return (int)effectArgs;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8028E654(void *arg0, void *arg1) {
    class Obj {
    public:
        virtual void v0();
        virtual int vC(const char *);
        virtual void v10();
        virtual int v14(const char *);
        virtual void v18();
        virtual int v1c(const char *);
        virtual int v20(const char *, int);
        virtual float v24(const char *);
        virtual double v28(const char *, float);
        virtual void v2c();
        virtual int v30(const char *, int);
        virtual void v34();
        virtual void v38(void *, void *, const char *, void *);
    };
    extern int fn_8028E594(void);
    extern char lbl_80348CE0[];
    extern int lbl_8055C8F0, lbl_8055C8F8, lbl_8055C900, lbl_8055C908, lbl_8055C910;
    extern float lbl_80564420, lbl_80564424;
    register char *base = lbl_80348CE0;
    register Obj *obj = (Obj *)arg1;
    register unsigned char *out = (unsigned char *)arg0;
    float buf[9];
    float buf2[9];
    float inA[9];
    float inB[9];
    float extra[8];
    memset(arg0, 0, 0x8C);
    obj->v14((const char *)&lbl_8055C8F0);
    *(int *)out = fn_8028E594();
    *(int *)(out + 4) = obj->v1c(base + 0x6C);
    *(float *)(out + 8) = obj->v24(base + 0x7C);
    *(float *)(out + 12) = obj->v24(base + 0x88);
    {
        double d1 = obj->v28(base + 0x94, lbl_80564420);
        double d2 = obj->v28(base + 0xA8, lbl_80564420);
        *(float *)(out + 0x10) = (float)d1;
        *(float *)(out + 0x14) = (float)d2;
        *(float *)(out + 0x18) = (float)d1;
    }
    {
        double d1 = obj->v28(base + 0xBC, lbl_80564420);
        double d2 = obj->v28(base + 0xD0, lbl_80564420);
        *(float *)(out + 0x1C) = (float)d1;
        *(float *)(out + 0x20) = (float)d2;
        *(float *)(out + 0x24) = (float)d1;
    }
    *(float *)(out + 0x28) = (float)obj->v28(base + 0xE4, lbl_80564420);
    *(float *)(out + 0x2C) = (float)obj->v28(base + 0xF4, lbl_80564420);
    *(int *)(out + 0x44) = obj->v20(base + 0x104, 5);
    *(float *)(out + 0x48) = (float)obj->v28((const char *)&lbl_8055C8F8, lbl_80564420);
    *(float *)(out + 0x30) = (float)obj->v28((const char *)&lbl_8055C900, lbl_80564420);
    *(float *)(out + 0x34) = (float)obj->v28((const char *)&lbl_8055C908, lbl_80564420);
    *(unsigned char *)(out + 0x38) = (unsigned char)obj->v30(base + 0x110, 1);
    *(float *)(out + 0x4C) = (float)obj->v28(base + 0x120, lbl_80564420);
    *(float *)(out + 0x50) = (float)obj->v28(base + 0x134, lbl_80564420);
    *(float *)(out + 0x54) = (float)obj->v28(base + 0x140, lbl_80564420);
    *(float *)(out + 0x58) = (float)obj->v28(base + 0x150, lbl_80564420);
    *(float *)(out + 0x5C) = (float)obj->v28(base + 0x15C, lbl_80564420);
    *(float *)(out + 0x78) = (float)obj->v28(base + 0x16C, lbl_80564420);
    *(float *)(out + 0x7C) = (float)obj->v28(base + 0x17C, lbl_80564420);
    *(float *)(out + 0x3C) = (float)obj->v28(base + 0x190, lbl_80564424);
    *(float *)(out + 0x40) = (float)obj->v28(base + 0x1A0, lbl_80564420);
    if (obj->vC(base + 0x1AC) != 0 || obj->vC(base + 0x1B8) != 0) {
        float v = (float)obj->v28(base + 0x1AC, lbl_80564420);
        *(float *)(out + 0x70) = v; *(float *)(out + 0x68) = v; *(float *)(out + 0x60) = v;
        v = (float)obj->v28(base + 0x1B8, lbl_80564420);
        *(float *)(out + 0x74) = v; *(float *)(out + 0x6C) = v; *(float *)(out + 0x64) = v;
    } else if (obj->vC(base + 0x1C8) != 0 || obj->vC(base + 0x1D4) != 0) {
        inA[0] = lbl_80564420; inA[1] = lbl_80564420; inA[2] = lbl_80564420;
        obj->v38(buf, obj, base + 0x1C8, inA);
        inB[0] = lbl_80564420; inB[1] = lbl_80564420; inB[2] = lbl_80564420;
        obj->v38(buf2, obj, base + 0x1D4, inB);
        *(float *)(out + 0x60) = buf2[0] - buf[0]; *(float *)(out + 0x64) = buf[0];
        *(float *)(out + 0x68) = buf2[1] - buf[1]; *(float *)(out + 0x6C) = buf[1];
        *(float *)(out + 0x70) = buf2[2] - buf[2]; *(float *)(out + 0x74) = buf[2];
    } else {
        *(float *)(out + 0x60) = (float)obj->v28(base + 0x1E0, lbl_80564420);
        *(float *)(out + 0x64) = (float)obj->v28(base + 0x1EC, lbl_80564420);
        *(float *)(out + 0x68) = (float)obj->v28(base + 0x1FC, lbl_80564420);
        *(float *)(out + 0x6C) = (float)obj->v28(base + 0x208, lbl_80564420);
        *(float *)(out + 0x70) = (float)obj->v28(base + 0x218, lbl_80564420);
        *(float *)(out + 0x74) = (float)obj->v28(base + 0x224, lbl_80564420);
    }
    if (obj->vC(base + 0x234) != 0) {
        extra[0] = lbl_80564420; extra[1] = lbl_80564420; extra[2] = lbl_80564420;
        obj->v38(extra, obj, base + 0x234, extra+4);
        *(float *)(out + 0x60) = lbl_80564420; *(float *)(out + 0x64) = extra[0];
        *(float *)(out + 0x68) = lbl_80564420; *(float *)(out + 0x6C) = extra[1];
        *(float *)(out + 0x70) = lbl_80564420; *(float *)(out + 0x74) = extra[2];
    }
    *(float *)(out + 0x80) = (float)obj->v28(base + 0x244, lbl_80564420);
    *(int *)(out + 0x84) = obj->v20((const char *)&lbl_8055C910, 1);
    *(unsigned char *)(out + 0x88) = (unsigned char)obj->v30(base + 0x254, 0);
}
#pragma cplusplus reset
#pragma pop

extern char lbl_80348CF8[];
extern char lbl_80348D28[];
extern int stricmp(const char *, const char *);

void fn_8028ED74(void *list) {
    /* Empty this emitter list by resetting its item count to zero. */
    ((EfList *)list)->count = 0;
}

void fn_8028ED80(void *list) {
    /* Empty an effect-emitter list by resetting its item count at +0x100 to zero (see EfList.count). */
    ((EfList *)list)->count = 0;
}

void fn_8028ED8C(void *list, int emitter) {
    /* Append an emitter to this effect-emitter list: store it at item[count], then advance the count at +0x100. */
    *(int *)((char *)list + (*(int *)((char *)list + 0x100) << 2)) = emitter;
    *(int *)((char *)list + 0x100) = *(int *)((char *)list + 0x100) + 1;
}

extern int fn_802E317C(const char *, ...);
extern char lbl_80348CF8[];
extern char lbl_80348D28[];
extern int stricmp(const char *, const char *);
extern char lbl_80348F4C[];
  #pragma push
  #pragma scheduling invalid_target
  #pragma scheduling on
/* Remove the given emitter from the list by clearing its slot; warn and return 0 if not found. */
int fn_8028EDA8(unsigned int *list, unsigned int emitter) {
    unsigned int *entry = list;
    int count = *(int *)((char *)list + 0x100);
    int index = 0;
    for (; index < count; entry++, index++) {
        if (*entry == emitter) {
            list[index] = 0;
            return 1;
        }
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
}
#pragma pop
void fn_8028EE1C(void *table) {
    /* Empty the effect-table cache by resetting its live entry count to zero. */
    ((EfTableCache *)table)->count = 0;
}

// Reset the entry count (at +0x600) of this 0x18-byte-entry cache table to zero.
void fn_8028EE28(void *table) {
    *(int *)((char *)table + 0x600) = 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling off
/* Search a table of 0x18-byte entries for one whose name matches (first 15 bytes) and return its index. */
int fn_8028EE34(void *table, int name, int *outIndex) {
    char *entry;
    int index;
    entry = (char *)table;
    index = 0;
    while (index < *(int *)((char *)table + 0x600)) {
        if (fn_8002B1D8(name, entry, 15) == 0) {
            *outIndex = index;
            return 1;
        }
        entry += 0x18;
        index++;
    }
    return 0;
}
#pragma pop
extern int fn_8002B1D8(int, void *, int);
extern char *strncpy(char *, const char *, unsigned int);
#pragma scheduling invalid_target
/* Append a 0x18-byte cache entry to the table: name (16 bytes), instance value at +0x10, refcount 1 at +0x14, then advance the entry count at +0x600. */
void fn_8028EEB4(void *table, int instance, const char *name) {
    strncpy((char *)table + *(int *)((char *)table + 0x600) * 0x18, name, 0x10);
    *(char *)((char *)table + *(int *)((char *)table + 0x600) * 0x18 + 0xF) = 0;
    *(int *)((char *)table + *(int *)((char *)table + 0x600) * 0x18 + 0x10) = instance;
    *(int *)((char *)table + *(int *)((char *)table + 0x600) * 0x18 + 0x14) = 1;
    ++*(int *)((char *)table + 0x600);
}
#pragma scheduling on
int fn_8028EF44(void *bucket, unsigned int systemId) {
    /* Release one reference to the particle system matching systemId in a bucket; returns 1 when its refcount reaches 0, panics if the system is absent. */
    char *base = (char *)bucket;
    char *entry = base;
    int entryIndex = 0;
    int entryCount = *(int *)(base + 0x600);
    while (entryCount > 0) {
        if (*(unsigned int *)(entry + 0x10) == systemId) {
            int *refCount = (int *)(base + entryIndex * 0x18 + 0x14);
            *refCount -= 1;
            return *refCount == 0;
        }
        entry += 0x18;
        entryIndex++;
        entryCount--;
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
#pragma dont_inline on
/* Split an emitter list into its priority buckets: every emitter of `srcList`
 * is appended to the EfList at buckets + (priority - 1) * 0x104, the emitter's
 * priority (+0x44) being 1..9.  fn_8028F2EC does this before grouping each
 * bucket by texture, so emitters sharing a texture end up drawn together. */
void fn_8028EFC4(int buckets, int *srcList) {
    int *base;
    int *cursor;
    int i;
    EfEmitter *item;
    int priority;
    base = srcList;
    cursor = base;
    i = 0;
    goto test;
body:
    item = (EfEmitter *)*cursor;
    priority = item->priority;
    fn_8028ED8C((char *)buckets + (priority - 1) * sizeof(EfList), (int)item);
    cursor++;
    i++;
test:
    if (i < ((EfList *)base)->count) goto body;
}
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
/* The first texture the two emitter lists have in common: for every emitter of
 * `listA` whose texture is not `excludeTexId` (the one the previous list
 * already carried over), look for an emitter of `listB` drawn with the same
 * texture.  fn_8028F0C0 calls it on a list and the next non-empty one, and
 * fn_8028F2EC uses the handle it returns to keep that texture together across
 * the two runs; EF_NO_TEXTURE means the lists share no texture. */
int fn_8028F040(int *listA, int *listB, int excludeTexId) {
    int outerCount;
    int outerIndex;
    EfEmitter *item;
    int innerCount;
    int i;
    int texId;
    EfEmitter **cursor;
    int found;
    int otherTexId;
    outerCount = ((EfList *)listA)->count;
    for (outerIndex = 0; outerIndex < outerCount; outerIndex++) {
        texId = ((EfEmitter *)*listA)->texHandle;
        if (texId != excludeTexId) {
            innerCount = ((EfList *)listB)->count;
            cursor = (EfEmitter **)listB;
            found = 0;
            i = 0;
            goto inner_check;
inner_body:
            item = *cursor;
            cursor++;
            i++;
            otherTexId = item->texHandle;
            found = (texId == otherTexId);
inner_check:
            if (found == 0 && i < innerCount) goto inner_body;
            if (found != 0) return texId;
        }
        listA++;
    }
    return EF_NO_TEXTURE;
}
#pragma pop
/* First texture the priority group `index` shares with the next non-empty group:
 * scans groups index+1..8 for the first that holds any emitter and asks
 * fn_8028F040 for a texture common to group `index` and that group, excluding
 * `excludeTexId` (the texture the previous group already carried over).  Returns
 * EF_NO_TEXTURE when no later group holds an emitter.  `lists` is the base of the
 * nine EfList groups (0x104 bytes each); nextList walks them for the count test
 * while the call recomputes each group's address from `lists`. */
int fn_8028F0C0(int *lists, int index, int excludeTexId) {
    int next;
    int *nextList;
    next = index + 1;
    nextList = (int *)((char *)lists + next * 0x104);
    for (; next < 9; nextList = (int *)((char *)nextList + 0x104), next++) {
        if (((EfList *)nextList)->count > 0)
            return fn_8028F040((int *)((char *)lists + index * 0x104), (int *)((char *)lists + next * 0x104), excludeTexId);
    }
    return EF_NO_TEXTURE;
}
#pragma pop

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028F114(register int *arg0, register int arg1, register int arg2)
{
  #pragma opt_lifetimes off
  register int n1 = 0;
  register int n2 = 0;
  register int n3 = 0;
  void *tmp[64];
  memset(tmp, 0, 0x100);
  if (arg1 != (-2))
  {
    int *src = arg0;
    void **dst = tmp;
    int i = 0;
    goto first_test;
    first_loop:
    {
      void *item = *((void **) src);
      if ((*((int *) (((char *) item) + 0xA4))) == arg1)
      {
        *(dst++) = item;
        n1++;
      }
    }

    src++;
    i++;
    first_test:
    if (i < (*((int *) (((char *) arg0) + 0x100))))
    {
      goto first_loop;
    }

  }
  if (arg2 != (-2))
  {
    int *src = arg0;
    int i = 0;
    goto second_test;
    second_loop:
    {
      void *item = *((void **) src);
      if ((*((int *) (((char *) item) + 0xA4))) == arg2)
      {
        tmp[((*((int *) (((char *) arg0) + 0x100))) - n2) - 1] = item;
        n2++;
      }
    }

    src++;
    i++;
    second_test:
    if (i < (*((int *) (((char *) arg0) + 0x100))))
    {
      goto second_loop;
    }

  }
  {
    int *src = arg0;
    int i = 0;
    goto outer_test;
    outer_loop:
    {
      void *item = *((void **) src);
      int id = *((int *) (((char *) item) + 0xA4));
      if ((id != arg1) && (id != arg2))
      {
        int *search = (int *) (tmp + n1);
        int equal = 0;
        int j = 0;
        while ((!equal) && (j < n3))
        {
          void *q = *((void **) search);
          search++;
          j++;
          equal = id == (*((int *) (((char *) q) + 0xA4)));
        }

        if (!equal)
        {
          tmp[n1 + n3] = item;
          n3++;
          {
            int k = i + 1;
            void **dst = (tmp + n1) + n3;
            int *siblings = arg0 + k;
            goto sibling_test;
            sibling_loop:
            if ((*((int *) (((char *) (*((void **) siblings))) + 0xA4))) == id)
            {
              *(dst++) = *((void **) siblings);
              n3++;
            }

            siblings++;
            k++;
            sibling_test:
            if (k < (*((int *) (((char *) arg0) + 0x100))))
            {
              goto sibling_loop;
            }

          }
        }
      }
    }

    src++;
    i++;
    outer_test:
    if (i < (*((int *) (((char *) arg0) + 0x100))))
    {
      goto outer_loop;
    }

  }
  memcpy(arg0, tmp, (*((int *) (((char *) arg0) + 0x100))) * 4);
}
#pragma unroll off
void fn_8028F2EC(int *arg0) {
    int records[9][65];
    char *p;
    char *end;
    int b0, b1;
    int last, index, i, size, result;
    int *block;

    records[0][64] = 0;
    p = (char *)&records[1][0];
    end = (char *)&records[9][0];
    if (p < end) {
        b0 = 0;
        b1 = 0;
        if (p <= end) {
            b1 = 1;
        }
        if (b1 != 0) {
            b0 = 1;
        }
        if (b0 != 0) {
            for (; p < end; p += 0x104) {
                *(int *)(p + 0x100) = 0;
            }
        }
    }
    fn_8028EFC4((int)records, arg0);
    block = records[0];
    last = -2;
    index = 0;
    i = 0;
    do {
        result = fn_8028F0C0(records[0], i, last);
        fn_8028F114(block, last, result);
        size = block[64];
        memcpy((char *)arg0 + index * 4, block, size * 4);
        i++;
        last = result;
        index += block[64];
        block = (int *)((char *)block + 0x104);
    } while (i < 9);
}
extern float fn_80129DC4(int, float, float);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8028F444(float *arg0, float *arg1, float *arg2, float *arg3, float farg0, float farg1) {
    float t0 = arg2[0];
    float h0 = fn_80129DC4(0, -t0, t0);
    float a0 = arg1[0];
    float c0 = arg3[0];
    float n1 = arg2[1];
    float x;
    float h1;
    float a1;
    float c1;
    float n2;
    float y;
    float h2;
    float a2;
    float c2;
    float z;
    float s0, s1, s2;
    s0 = farg1 * h0;
    x = a0 * c0 + s0;
    arg0[0] = x;
    h1 = fn_80129DC4(0, -n1, n1);
    a1 = arg1[1];
    c1 = arg3[1];
    n2 = arg2[2];
    s1 = farg1 * h1;
    y = a1 * c1 + s1;
    arg0[1] = y;
    h2 = fn_80129DC4(0, -n2, n2);
    a2 = arg1[2];
    c2 = arg3[2];
    s2 = farg1 * h2;
    z = a2 * c2 + s2;
    arg0[1] += farg1 * farg0;
    arg0[2] = z;
}
#pragma scheduling on
#pragma pop
extern char lbl_80348F9C[];
#pragma scheduling invalid_target
int fn_8028F534(int bitValue) {
    /* Map a single-bit mask at position 0,2,4,6 to the corresponding 1,2,4,8 bit. */
    int bitShift;
    int index;
    index = 0;
    bitShift = 0;
    for (; index < 4; bitShift += 2, index++) {
        if (bitValue == (1 << bitShift)) {
            return 1 << index;
        }
    }
    fn_802E317C(lbl_80348F9C, bitValue);
    return 0;
}
/* No-op post-creation hook: called with the caller's name/argument and the
 * newly created partman object, but its body is empty. */
void fn_8028F5A0(int nameOrArg, int object) {
}

#pragma pop
/* Empty stub called at the start of the effect subsystem's list/cache reset
 * (fn_8028E0F0); there is nothing for it to clear, so it does nothing. */
void fn_8028F5A4(void) {
}

extern void fn_802916E4(void);
/* Destructor for nw4r::ef::Effect: installs this class's vtable, runs the base
 * destructor, and frees the object when shouldDelete is positive. */
void *__dt__Q34nw4r2ef6EffectFv_8028F5A8(void *effect, int shouldDelete) {
    if (effect) {
        *(void **)effect = lbl_803490D4; /* nw4r::ef::Effect vtable */
        fn_802916E4();
        if (shouldDelete > 0) fn_80128668(effect);
    }
    return effect;
}

extern double fn_8002EFB4(double, double);
extern float lbl_80564424, lbl_80564430, lbl_80564434, lbl_80564438;
extern double lbl_80564428;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8028F608(float *out0, float *out1, float (*matrix)[3], float angle)
{
  extern double fn_8002EFB4(double, double);
  extern float lbl_80564424;
  extern float lbl_80564430;
  extern float lbl_80564434;
  extern float lbl_80564438;
  float d;
  float x;
  float d2;
  float a;
  float b;
  float g;
  float e;
      float c;
    c = matrix[0][1];
  float y;
  float h;
  union 
  {
    float f;
    unsigned int u;
  } bits;
  d = (bits.f = ((float) fn_8002EFB4(angle, 6.283185307179586)) - lbl_80564430);
  if (!(bits.u & 0x80000000))
  {
    if (1)
    {
 if (1) { }
      x = lbl_80564424 - ((((lbl_80564434 * d) / lbl_80564430) - lbl_80564424) * (((lbl_80564434 * d) / lbl_80564430) - lbl_80564424));
    }
  }
  else
  {
    d = -d;
    x = -(lbl_80564424 - ((((lbl_80564434 * d) / lbl_80564430) - lbl_80564424) * (((lbl_80564434 * d) / lbl_80564430) - lbl_80564424)));
  }
  d2 = (bits.f = ((float) fn_8002EFB4(lbl_80564438 + angle, 6.283185307179586)) - lbl_80564430);
  if (!(bits.u & 0x80000000))
  {
    y = lbl_80564424 - ((((lbl_80564434 * d2) / lbl_80564430) - lbl_80564424) * (((lbl_80564434 * d2) / lbl_80564430) - lbl_80564424));
  }
  else
  {
    d2 = -d2;
    y = -(lbl_80564424 - ((((lbl_80564434 * d2) / lbl_80564430) - lbl_80564424) * (((lbl_80564434 * d2) / lbl_80564430) - lbl_80564424)));
  }
  a = matrix[0][0];
  b = matrix[1][0];
  e = matrix[1][1];
  g = matrix[0][2];
  h = matrix[1][2];
  out0[0] = (y * a) + (x * b);
  out0[1] = (y * c) + (x * e);
  out0[2] = (y * g) + (x * h);
  out1[0] = (y * b) - (x * a);
  out1[1] = (y * e) - (x * c);
  out1[2] = (y * h) - (x * g);
}
#pragma pop
int fn_8028F7AC(void *arg0, void *arg1, int arg2) {
    int count;
    void *buffer;
    void *result;

    ((int (*)(void *))fn_8028E61C)(arg0);
    ((void (*)(void *, void *))fn_8028FD00)(arg0, arg1);
    count = *(int *)((char *)arg1 + 4);
    buffer = fn_8012850C(count * 0x28 + 0x10, lbl_80348FC4);
    result = fn_8002F37C(buffer, (void *)fn_8028F854, 0, 0x28, count);
    *(void **)((char *)arg0 + 0x8c) = result;
    *(int *)((char *)arg0 + 0x98) = count;
    *(void **)((char *)arg0 + 0xa4) = (void *)fn_802CAC28(arg2, 0);
    return (int)arg0;
}
#pragma pop
/* No-op element-constructor callback for fn_8002F37C: passed when fn_8028F7AC
 * builds its 0x28-byte-per-element array; elements need no initialization. */
void fn_8028F854(void) {}

/* Destroys an object: releases its subobject, frees its buffer, and optionally deletes it. */
int fn_8028F858(int object, int shouldDelete) {
    int buffer;
    if (object != 0) {
        fn_802CAC54(*(int *)(object + 0xA4));
        buffer = *(int *)(object + 0x8C);
        if (buffer != 0) fn_80128670(buffer - 0x10);
        if (shouldDelete > 0) fn_80128668((void *)object);
    }
    return object;
}

void fn_8028F8C4(int playbackState) {
    /* Reset an effect's timed playback cursor: index (-1) and count (0) at +0x90/+0x94, phase (0.0) at +0x9C. */
    volatile int *fields = (volatile int *)playbackState;
    float initialPhase = lbl_80564420;
    fields[36] = -1;
    fields[37] = 0;
    *(volatile float *)((char *)playbackState + 0x9C) = initialPhase;
}

extern float lbl_80558DC4;
__declspec(section ".data") extern float lbl_80558DC4;
/* Advances a timed playback cursor (arg0+0x90/0x94/0x98, entries at arg0+0x8C stride 0x28) over entries whose time (entry+0x18) is below (timeNow - startOffset at arg0+8), wrapping/accumulating the phase at arg0+0x9C. */
void fn_8028F8E0(int playbackState, float timeNow) {
    char *p = (char *)playbackState;
    float *phase = (float *)(p + 0x9C);
    float threshold;
    int index, count, count2, i, j;

    if (*phase >= lbl_80564424 - lbl_80558DC4) {
        *phase = *phase - lbl_80564424;
    }
    index = *(int *)(p + 0x90);
    *phase = *phase + *(float *)(p + 0xC);
    if (index < 0) return;

    threshold = timeNow - *(float *)(p + 8);
    count = *(int *)(p + 0x94);
    i = index;
    if (i < count) {
        while (i < count && *(float *)(*(char **)(p + 0x8C) + i * 0x28 + 0x18) < threshold) {
            i++;
        }
        if (i != count) {
            *(int *)(p + 0x90) = i;
            return;
        }
        *(int *)(p + 0x90) = -1;
        *(int *)(p + 0x94) = 0;
        return;
    }

    count2 = *(int *)(p + 0x98);
    while (i < count2 && *(float *)(*(char **)(p + 0x8C) + i * 0x28 + 0x18) < threshold) {
        i++;
    }
    if (i == count2) {
        j = 0;
        while (j < count && *(float *)(*(char **)(p + 0x8C) + j * 0x28 + 0x18) < threshold) {
            j++;
        }
        if (j != count) {
            *(int *)(p + 0x90) = j;
            return;
        }
        *(int *)(p + 0x90) = -1;
        *(int *)(p + 0x94) = 0;
        return;
    }
    *(int *)(p + 0x90) = i;
}

#pragma cplusplus on
#pragma push
#pragma scheduling invalid_target
extern "C" int fn_8028FA1C(int arg0) {
    /* Flushes pending array entries by invoking a method from lbl_80348FD0 based on the object type, handling wrap-around ranges. */
    class ArrayObject {
    public:
        virtual void apply(int entries, int count) = 0;
    };
    typedef void (ArrayObject::*ApplyMethod)(int, int);
    ArrayObject *object;
    int count;
    int index;
    int count2;
    int entries;

    object = (ArrayObject *)arg0;
    index = *(int *)((char *)arg0 + 0x90);
    if (index < 0) goto done;
    count = *(int *)((char *)arg0 + 0x94);
    if (index < count) {
        entries = *(int *)((char *)arg0 + 0x8c) + index * 0x28;
        (object->*(((ApplyMethod *)lbl_80348FD0)[*(int *)arg0]))(entries, count - index);
        goto done;
    }
    count2 = *(int *)((char *)arg0 + 0x98);
    entries = *(int *)((char *)arg0 + 0x8c) + index * 0x28;
    (object->*(((ApplyMethod *)lbl_80348FD0)[*(int *)arg0]))(entries, count2 - index);
    (object->*(((ApplyMethod *)lbl_80348FD0)[*(int *)arg0]))(*(int *)((char *)arg0 + 0x8c), *(int *)((char *)arg0 + 0x94));
done:
    ;
}
#pragma pop
#pragma cplusplus reset
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
/* Emit one effect entry when the emitter's wrapped phase at +0x9C has reached
 * 1.0 (1.0 - lbl_80558DC4) and its playback index at +0x90 differs from the entry
 * count at +0x94: build a random 3D value from the +0x10/+0x1C/+0x28 fields and
 * forward it with fn_8028FEE4. */
void fn_8028FAE4(void *emitter, int posA, float *basePos, float angle) {
    extern void fn_8028FEE4(void *, int, float *, float, float);
    float generatedPos[3];
    int shouldEmit = 0;

    if (*(float *)((char *)emitter + 0x9C) >=
            1.0f - lbl_80558DC4 &&
        *(int *)((char *)emitter + 0x90) != *(int *)((char *)emitter + 0x94))
        shouldEmit = 1;
    if (shouldEmit != 0) {
        fn_8028F444(generatedPos, basePos,
                    (float *)((char *)emitter + 0x10),
                    (float *)((char *)emitter + 0x1C),
                    *(float *)((char *)emitter + 0x28), lbl_80564424);
        fn_8028FEE4(emitter, posA, generatedPos, lbl_80564420, angle);
    }
}
#pragma scheduling on
#pragma pop

#pragma push
#pragma dont_inline on
/* Emit one effect entry when the emitter's wrapped phase at +0x9C has reached
 * 1.0 (1.0 - lbl_80558DC4) and its playback index at +0x90 differs from the
 * entry count at +0x94: build a random 3D value from the +0x10/+0x1C/+0x28
 * fields, scaled by `spread`, and forward it with fn_8028FEE4. */
void fn_8028FB98(void *emitter, int posA, float *basePos, float spread) {
    extern void fn_8028FEE4(void *, int, float *, float, float);
    extern float lbl_80564424;
    extern float lbl_80558DC4;
    extern float lbl_80564420;
    float generatedPos[2];
    int shouldEmit = 0;

    if (*(float *)((char *)emitter + 0x9C) >=
            1.0f - lbl_80558DC4 &&
        *(int *)((char *)emitter + 0x90) != *(int *)((char *)emitter + 0x94))
        shouldEmit = 1;
    if (shouldEmit != 0) {
        fn_8028F444(generatedPos, basePos,
                    (float *)((char *)emitter + 0x10),
                    (float *)((char *)emitter + 0x1C),
                    *(float *)((char *)emitter + 0x28), spread);
        fn_8028FEE4(emitter, posA, generatedPos, lbl_80564420, lbl_80564424);
    }
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
extern float fn_80287BC8(float, float);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
/* Emits an effect at a computed position when the emitter is active and its index has changed. */
void fn_8028FC40(void *emitter, int param, float *basePos, float angleOffset) {
    extern void fn_8028FEE4(void *, int, float *, float, float);
    float pos[3];
    float range;
    int shouldEmit = 0;
    if (*(float *)((char *)emitter + 0x9C) >= 1.0f - lbl_80558DC4 &&
        *(int *)((char *)emitter + 0x90) != *(int *)((char *)emitter + 0x94)) {
        shouldEmit = 1;
    }
    if (shouldEmit != 0) {
        fn_8028F444(pos, basePos, (float *)((char *)emitter + 0x10),
                    (float *)((char *)emitter + 0x1C),
                    *(float *)((char *)emitter + 0x28), lbl_80564424);
        range = *(float *)((char *)emitter + 0x2C);
        fn_8028FEE4(emitter, param, pos,
                    angleOffset + fn_80287BC8(-range, range),
                    lbl_80564424);
    }
}
#pragma scheduling on
#pragma pop

#pragma pop
extern int fn_8028F534(int);
extern double lbl_80564440;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* Start an effect up from its create-args block: copy the 0x8C bytes of
 * parameters the effect creators filled in (fn_8028E61C cleared them) into the
 * fresh effect object field by field, cache 1.0f / period at +0xA0, clamp the
 * blend float at +0x34 to [0.0f, 1.0f], and for effect type 1 turn the
 * power-of-4 count at +0x84 into its square root at +0xA8 with 1.0f/it at
 * +0xAC.  The timed playback cursor is reset last (fn_8028F8C4).  Called by
 * fn_8028F7AC, which allocates the particle array right afterwards. */
void fn_8028FD00(void *effectArg, void *argsArg, int arg2) {
    volatile EfEffect *args = (volatile EfEffect *)argsArg;
    EfEffect *effect = (EfEffect *)effectArg;
    unsigned char f89;
    unsigned char en88;
    int powerOf4;
    float f80;
    float f7c;
    float f78;
    float f74;
    float f70;
    float f6c;
    float f68;
    float f64;
    float f60;
    float f5c;
    float f58;
    float f54;
    float f50;
    float f4c;
    float f48;
    int f44;
    float f40;
    float f3c;
    int en38;
    float blend;
    float f30;
    float f2c;
    float f28;
    int f24;
    int f20;
    int f1c;
    int f18;
    int f14;
    int f10;
    float fc;
    float period;
    int emitterCount;
    int mode;
    float invPeriod;
    int sqrtCount;

    period = args->period;
    effect = (EfEffect *)effectArg;
    invPeriod = lbl_80564424;
    mode = args->mode;
    invPeriod = invPeriod / period;
    emitterCount = args->emitterCount;
    fc = args->fc;
    f10 = args->f10;
    f14 = args->f14;
    f18 = args->f18;
    f1c = args->f1c;
    f20 = args->f20;
    f24 = args->f24;
    f28 = args->f28;
    f2c = args->f2c;
    f30 = args->f30;
    blend = args->blend;
    en38 = args->en38;
    f3c = args->f3c;
    f40 = args->f40;
    f44 = args->f44;
    f48 = args->f48;
    f4c = args->f4c;
    f50 = args->f50;
    f54 = args->f54;
    f58 = args->f58;
    f5c = args->f5c;
    f60 = args->f60;
    f64 = args->f64;
    f68 = args->f68;
    f6c = args->f6c;
    f70 = args->f70;
    f74 = args->f74;
    f78 = args->f78;
    f7c = args->f7c;
    f80 = args->f80;
    powerOf4 = args->powerOf4;
    en88 = args->en88;
    f89 = args->f89;
    effect->mode = mode;
    effect->emitterCount = emitterCount;
    effect->period = period;
    effect->fc = fc;
    effect->f10 = f10;
    effect->f14 = f14;
    effect->f18 = f18;
    effect->f1c = f1c;
    effect->f20 = f20;
    effect->f24 = f24;
    effect->f28 = f28;
    effect->f2c = f2c;
    effect->f30 = f30;
    effect->blend = blend;
    effect->en38 = en38;
    effect->f3c = f3c;
    effect->f40 = f40;
    effect->f44 = f44;
    effect->f48 = f48;
    effect->f4c = f4c;
    effect->f50 = f50;
    effect->f54 = f54;
    effect->f58 = f58;
    effect->f5c = f5c;
    effect->f60 = f60;
    effect->f64 = f64;
    effect->f68 = f68;
    effect->f6c = f6c;
    effect->f70 = f70;
    effect->f74 = f74;
    effect->f78 = f78;
    effect->f7c = f7c;
    effect->f80 = f80;
    effect->powerOf4 = powerOf4;
    effect->en88 = en88;
    effect->f89 = f89;
    effect->invPeriod = invPeriod;
    switch (mode) {
    case 1:
        sqrtCount = fn_8028F534(powerOf4);
        effect->invSqrtCount = 1.0f / (float)sqrtCount;
        effect->sqrtCount = sqrtCount;
        break;
    default:
        break;
    }
    {
        float temp = effect->blend;
        float clamped = (lbl_80564424 < temp) ? lbl_80564424 : temp;
        clamped = (clamped > lbl_80564420) ? clamped : lbl_80564420;
        effect->blend = clamped;
    }
    fn_8028F8C4((int)effectArg);
}

extern int fn_80287B5C(int);
extern int fn_802E30C8(void *, const char *, ...);
extern char lbl_8055C918[4];
extern char lbl_80349024[];
extern char lbl_80349078[];
extern unsigned char lbl_8055F74C;
#pragma cplusplus on
void fn_8028FEE4(void *emitterPtr, int basePosAddr, float *generatedPos, float angle, float scale) {
    /* Append one particle entry to the emitter's ring buffer: pack the base/generated position pair and the mode-dependent color/rotation byte, warn once if called outside the particle update window. */
    EfEntry2 entry;
    EfEntry2 *dst;
    EfObj *emitter = (EfObj *)emitterPtr;
    float *basePos = (float *)basePosAddr;
    if (lbl_8055F73C == 0 && lbl_8055F74C == 0) {
        lbl_8055F74C = 1;
        fn_802E30C8(lbl_8055C918, lbl_80349024);
    }
    entry.p.a.x = basePos[0];
    entry.p.a.y = basePos[1];
    entry.p.a.z = basePos[2];
    entry.p.b.x = generatedPos[0];
    entry.p.b.y = generatedPos[1];
    entry.p.b.z = generatedPos[2];
    entry.v6 = lbl_8055F738;
    entry.f1 = scale;
    switch (emitter->mode) {
    case 0:
        entry.c0 = emitter->en38 ? fn_80287B5C(4) : 0;
        break;
    case 1:
        entry.c1 = emitter->en88 ? fn_80287B5C(emitter->v84) : 0;
        break;
    case 2:
        entry.c2 = emitter->en38 ? fn_80287B5C(0xff) : 0;
        entry.f0 = angle;
        break;
    default:
        fn_802E317C(lbl_80349078, emitter->mode);
        break;
    }
    if (emitter->head < 0) {
        dst = (EfEntry2 *)emitter->buf;
        dst->p = entry.p;
        dst->v6 = entry.v6;
        dst->c0 = entry.c0;
        dst->c1 = entry.c1;
        dst->c2 = entry.c2;
        dst->f0 = entry.f0;
        dst->f1 = entry.f1;
        emitter->head = 0;
        emitter->tail = 1;
        return;
    }
    dst = (EfEntry2 *)emitter->buf + emitter->tail;
    dst->p = entry.p;
    dst->v6 = entry.v6;
    dst->c0 = entry.c0;
    dst->c1 = entry.c1;
    dst->c2 = entry.c2;
    dst->f0 = entry.f0;
    dst->f1 = entry.f1;
    emitter->tail = (emitter->tail + 1) % emitter->cap;
}
#pragma cplusplus reset
extern float lbl_80564424, lbl_80564448, lbl_8056444C, lbl_80564450, lbl_80564454, lbl_80564458;
extern float lbl_8056445C;
typedef struct { float x, y, z; unsigned int color; float u, v; } EfVtx;
typedef struct { float m[9]; } EfMtx3;
#pragma scheduling off
void fn_80290160(void *arg0, void *arg1, void *arg2, float farg0)
{
  float a;
  float h;
  float n;
  float w;
  float ac;
  float al;
  float b;
  float i;
  float p;
  float v;
  float f;
  float m;
  float r;
  float aa;
  float e;
  float o;
  float t;
  float z;
  float ak;
  float new_var;
  float g;
  float l;
  float x;
  float ah;
  float j;
  float s;
  float ag;
  float aj;
  float am;
  float an;
  float d;
  float q;
  float u;
  float af;
  float ai;
  float c;
  float ad;
  float k;
  float ab;
  float ae;
  float y;
  volatile float spill10;
  volatile float spillC;
  volatile float spill8;
  a = *((volatile float *) (&lbl_8056444C));
  b = *((volatile float *) (((char *) arg0) + 0xa0));
  c = a * farg0;
  e = *((volatile float *) (&lbl_80564448));
  d = farg0 * b;
  f = *((volatile float *) (((char *) arg0) + 0x34));
  g = *((volatile float *) (&lbl_80564454));
  h = g * f;
  i = *((volatile float *) (&lbl_80564450));
  j = e * d;
  k = *((volatile float *) (&lbl_80564424));
  l = f * d;
  m = h * d;
  n = *((volatile float *) (((char *) arg0) + 0x30));
  o = j - i;
  p = *((volatile float *) (&lbl_80564458));
  q = j - k;
  r = o * m;
  s = *((volatile float *) (((char *) arg2) + 0x10));
  t = q * l;
  u = *((volatile float *) (((char *) arg2) + 0xc));
  v = p * n;
  w = k + r;
  x = *((volatile float *) (((char *) arg2) + 0x14));
  y = k + t;
  z = *((volatile float *) arg2);
  aa = *((volatile float *) (((char *) arg2) + 4));
  ab = c * w;
  ac = *((volatile float *) (((char *) arg2) + 8));
  ad = s * y;
  ae = u * y;
  af = (new_var = x * y);
  ag = v * ab;
  ah = ae * farg0;
  spill8 = ae;
  ai = af * farg0;
  aj = ad - ag;
  ak = z + ah;
  al = ac + ai;
  spill10 = af;
  am = aj * farg0;
  spillC = aj;
  an = aa + am;
  *((float *) arg1) = ak;
  *((float *) (((char *) arg1) + 8)) = al;
  *((float *) (((char *) arg1) + 4)) = an;
}
extern void *fn_802C86DC(void);
extern void fn_802C8DB8(void *, int, void *, int);
extern float PSVECDotProduct(float *, float *);
#pragma push
#pragma processor 750
void fn_80290224(void *arg0, void *arg1, int arg2) {
    struct { EfVtx v[32]; short idx[48]; } buf;
    volatile int count;
    int n;
    int i;
    EfVec pos;
    EfVec dsub;
    EfVec dadd;
    EfMtx3 mtx;
    EfVec campos;
    EfVec dir;
    EfVtx q[4];
    char *p;
    float one;
    float t, tm, k, alpha, h, nh;
    int r, g, b, a;

    {
        float *bb = (float *)fn_802C86DC();
        dsub.x = bb[3] - bb[0];
        dsub.y = bb[4] - bb[1];
        dsub.z = bb[5] - bb[2];
        one = lbl_8055F738;
        dadd.x = bb[3] + bb[0];
        dadd.y = bb[4] + bb[1];
        dadd.z = bb[5] + bb[2];
    }
    for (i = 0; i < 8; i++) {
        buf.idx[i * 6 + 0] = i * 4;
        buf.idx[i * 6 + 1] = i * 4 + 1;
        buf.idx[i * 6 + 2] = i * 4 + 2;
        buf.idx[i * 6 + 3] = i * 4;
        buf.idx[i * 6 + 4] = i * 4 + 2;
        buf.idx[i * 6 + 5] = i * 4 + 3;
    }
    count = 0;
    p = (char *)arg1;
    for (n = 0; n < arg2; n++, p += 0x28) {
        float *bb;
        float fa, fb, fc, fd;
        unsigned int col;
        t = one - *(float *)(p + 0x18);
        h = lbl_8056444C * (*(float *)((char *)arg0 + 0x54) + *(float *)((char *)arg0 + 0x50) * t
              + lbl_8056444C * *(float *)((char *)arg0 + 0x4c) * (t * t));
        k = t * *(float *)((char *)arg0 + 0xa0);
        fn_80290160(arg0, &pos, p, t);
        bb = (float *)fn_802C86DC();
        mtx = *(EfMtx3 *)bb;
        campos = *(EfVec *)(bb + 9);
        dir.x = campos.x - pos.x;
        dir.y = campos.y - pos.y;
        dir.z = campos.z - pos.z;
        {
            float c0 = *(float *)((char *)arg0 + 0x3c);
            float c1 = *(float *)((char *)arg0 + 0x40);
            tm = c1 + (PSVECDotProduct((float *)&dir, (float *)&dir) / (lbl_80564424 + c0 * c0)) * (lbl_80564424 - c1);
        }
        if (lbl_80564424 < tm) tm = lbl_80564424;
        if (!(tm > lbl_80564420)) tm = lbl_80564420;
        r = (int)(lbl_8056445C * (*(float *)((char *)arg0 + 0x74) + *(float *)((char *)arg0 + 0x70) * k));
        r = r > 0 ? r : 0; if (r > 255) r = 255;
        g = (int)(lbl_8056445C * (*(float *)((char *)arg0 + 0x6c) + *(float *)((char *)arg0 + 0x68) * k));
        g = g > 0 ? g : 0; if (g > 255) g = 255;
        b = (int)(lbl_8056445C * (*(float *)((char *)arg0 + 0x64) + *(float *)((char *)arg0 + 0x60) * k));
        b = b > 0 ? b : 0; if (b > 255) b = 255;
        alpha = lbl_8056445C * (*(float *)((char *)arg0 + 0x5c) + *(float *)((char *)arg0 + 0x58) * k);
        a = (int)(*(float *)(p + 0x24) * (tm * alpha));
        a = a > 0 ? a : 0; if (a > 255) a = 255;
        col = (a << 24) | ((b & 0xff) << 16) | ((g & 0xff) << 8) | (r & 0xff);
        {
            unsigned char fl = *(unsigned char *)(p + 0x1c);
            int ia = ((fl + 1) & 2) >> 1;
            int ib = (fl >> 1) & 1;
            fa = (float)ia; fb = (float)ib; fc = (float)(1 - ib); fd = (float)(1 - ia);
        }
        nh = -h;
        q[0].x = pos.x + dsub.x * h; q[0].y = pos.y + dsub.y * h; q[0].z = pos.z + dsub.z * h;
        q[1].x = pos.x + dadd.x * h; q[1].y = pos.y + dadd.y * h; q[1].z = pos.z + dadd.z * h;
        q[2].x = pos.x + dsub.x * nh; q[2].y = pos.y + dsub.y * nh; q[2].z = pos.z + dsub.z * nh;
        q[3].x = pos.x + dadd.x * nh; q[3].y = pos.y + dadd.y * nh; q[3].z = pos.z + dadd.z * nh;
        q[0].color = q[1].color = q[2].color = q[3].color = col;
        q[0].u = fa; q[0].v = fb;
        q[1].u = fc; q[1].v = fa;
        q[2].u = fd; q[2].v = fc;
        q[3].u = fb; q[3].v = fd;
        if (count >= 8) {
            fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
            count = 0;
        }
        buf.v[count * 4 + 0] = q[0];
        buf.v[count * 4 + 1] = q[1];
        buf.v[count * 4 + 2] = q[2];
        buf.v[count * 4 + 3] = q[3];
        count++;
    }
    if (count > 0) {
        fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
        count = 0;
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_802908CC(void *arg0, void *arg1, int arg2) {
    typedef struct { float m[9]; float p[3]; } EfCam;
    typedef struct { float x; float y; float z; } EfVec;
    typedef struct { float x; float y; float z; unsigned int color; float u; float v; } EfVtx;
    struct { EfVtx v[32]; short idx[48]; } buf;
    EfVtx q[4];
    EfCam cam;
    EfVec dsub;
    EfVec dadd;
    EfVec pos;
    EfVec dir;
    int n;
    int i;
    char *p;
    float one, half, c1, c0, c255;
    float t, tm, k, alpha, h, nh;
    float u0, u1, v0, v1, cs;
    int r, g, b, a;
    int frames, fr, cols, row, col;
    volatile int count;
    {
        float *bb = (float *)fn_802C86DC();
        dsub.x = bb[3] - bb[0];
        dsub.y = bb[4] - bb[1];
        dsub.z = bb[5] - bb[2];
        one = lbl_8055F738;
        dadd.x = bb[3] + bb[0];
        dadd.y = bb[4] + bb[1];
        dadd.z = bb[5] + bb[2];
    }
    for (i = 0; i < 8; i++) {
        buf.idx[i * 6 + 0] = i * 4;
        buf.idx[i * 6 + 1] = i * 4 + 1;
        buf.idx[i * 6 + 2] = i * 4 + 2;
        buf.idx[i * 6 + 3] = i * 4;
        buf.idx[i * 6 + 4] = i * 4 + 2;
        buf.idx[i * 6 + 5] = i * 4 + 3;
    }
    count = 0;
    half = lbl_8056444C;
    c1 = lbl_80564424;
    c0 = lbl_80564420;
    c255 = lbl_8056445C;
    p = (char *)arg1;
    for (n = 0; n < arg2; n++, p += 0x28) {
        float *bb;
        unsigned int col32;
        frames = *(int *)((char *)arg0 + 0x84);
        t = one - *(float *)(p + 0x18);
        k = t * *(float *)((char *)arg0 + 0xa0);
        h = half * (*(float *)((char *)arg0 + 0x54) + *(float *)((char *)arg0 + 0x50) * t + half * *(float *)((char *)arg0 + 0x4c) * (t * t));
        fr = (*(unsigned char *)(p + 0x1d) + (int)(k * ((float)frames * *(float *)((char *)arg0 + 0x80)))) % frames;
        fn_80290160(arg0, &pos, p, t);
        bb = (float *)fn_802C86DC();
        cam = *(EfCam *)bb;
        dir.x = cam.p[0] - pos.x;
        dir.y = cam.p[1] - pos.y;
        dir.z = cam.p[2] - pos.z;
        {
            float f0 = *(float *)((char *)arg0 + 0x3c);
            float f1 = *(float *)((char *)arg0 + 0x40);
            tm = f1 + (PSVECDotProduct((float *)&dir, (float *)&dir) / (c1 + f0 * f0)) * (c1 - f1);
        }
        if (c1 < tm) tm = c1;
        if (!(tm > c0)) tm = c0;
        r = (int)(c255 * (*(float *)((char *)arg0 + 0x74) + *(float *)((char *)arg0 + 0x70) * k));
        r = r > 0 ? r : 0; if (r > 255) r = 255;
        g = (int)(c255 * (*(float *)((char *)arg0 + 0x6c) + *(float *)((char *)arg0 + 0x68) * k));
        g = g > 0 ? g : 0; if (g > 255) g = 255;
        b = (int)(c255 * (*(float *)((char *)arg0 + 0x64) + *(float *)((char *)arg0 + 0x60) * k));
        b = b > 0 ? b : 0; if (b > 255) b = 255;
        alpha = c255 * (*(float *)((char *)arg0 + 0x5c) + *(float *)((char *)arg0 + 0x58) * k);
        a = (int)(*(float *)(p + 0x24) * (tm * alpha));
        a = a > 0 ? a : 0; if (a > 255) a = 255;
        col32 = (a << 24) | ((b & 0xff) << 16) | ((g & 0xff) << 8) | (r & 0xff);
        cols = *(int *)((char *)arg0 + 0xa8);
        row = fr / cols;
        col = fr % cols;
        cs = *(float *)((char *)arg0 + 0xac);
        u0 = (float)col * cs;
        u1 = (float)(col + 1) * cs;
        v0 = (float)row * cs;
        v1 = (float)(row + 1) * cs;
        nh = -h;
        q[0].x = pos.x + dsub.x * h; q[0].y = pos.y + dsub.y * h; q[0].z = pos.z + dsub.z * h;
        q[1].x = pos.x + dadd.x * h; q[1].y = pos.y + dadd.y * h; q[1].z = pos.z + dadd.z * h;
        q[2].x = pos.x + dsub.x * nh; q[2].y = pos.y + dsub.y * nh; q[2].z = pos.z + dsub.z * nh;
        q[3].x = pos.x + dadd.x * nh; q[3].y = pos.y + dadd.y * nh; q[3].z = pos.z + dadd.z * nh;
        q[0].color = q[1].color = q[2].color = q[3].color = col32;
        q[0].u = u0; q[0].v = v0;
        q[1].u = u1; q[1].v = v0;
        q[2].u = u1; q[2].v = v1;
        q[3].u = u0; q[3].v = v1;
        if (count >= 8) {
            fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
            count = 0;
        }
        buf.v[count * 4 + 0] = q[0];
        buf.v[count * 4 + 1] = q[1];
        buf.v[count * 4 + 2] = q[2];
        buf.v[count * 4 + 3] = q[3];
        count++;
    }
    if (count > 0) {
        fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
        count = 0;
    }
}
#pragma pop
extern float lbl_80564460, lbl_80564464, lbl_80564468, lbl_8056446C, lbl_80564470;
extern double lbl_80564478;
#pragma scheduling on
void fn_80290FC4(void *arg0, void *arg1, int arg2) {
    typedef struct { EfMtx3 m; EfVec p; } EfCam;
    struct { EfVtx v[32]; short idx[48]; } buf;
    int count;
    int n;
    int i;
    int j;
    EfVec pos;
    EfVec axA;
    EfVec axB;
    EfCam cam2;
    EfVec dir;
    EfVtx q[4];
    char *p;
    float *cam;
    float one, k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
    float t, tm, k, h, nh, ang, inv, m, ts;
    int r, g, b, a;
    float *bb;

    cam = (float *)fn_802C86DC();
    k0 = lbl_8056444C * *(float *)((char *)arg0 + 0x48);
    one = lbl_8055F738;
    for (i = 0; i < 8; i++) {
        buf.idx[i * 6 + 0] = i * 4;
        buf.idx[i * 6 + 1] = i * 4 + 1;
        buf.idx[i * 6 + 2] = i * 4 + 2;
        buf.idx[i * 6 + 3] = i * 4;
        buf.idx[i * 6 + 4] = i * 4 + 2;
        buf.idx[i * 6 + 5] = i * 4 + 3;
    }
    k2 = lbl_80564424;
    k4 = lbl_8056445C;
    k1 = lbl_8056444C;
    k5 = lbl_80564460;
    k6 = lbl_80564464;
    k7 = lbl_80564468;
    k8 = lbl_8056446C;
    k3 = lbl_80564420;
    k10 = lbl_80564434;
    k9 = lbl_80564470;
    count = 0;
    p = (char *)arg1;
    for (n = 0; n < arg2; n++, p += 0x28) {
        t = one - *(float *)(p + 0x18);
        k = t * *(float *)((char *)arg0 + 0xa0);
        h = k1 * (*(float *)((char *)arg0 + 0x54) + *(float *)((char *)arg0 + 0x50) * t
              + k1 * *(float *)((char *)arg0 + 0x4c) * (t * t));
        h = (h > k5) ? h : k5;
        inv = k2 / (k6 * h);
        ts = *(float *)(p + 0x20) * t;
        ang = k7 + (float)fn_8002EFB4(
            k7 * (float)*(unsigned char *)(p + 0x1e) * k8
              + ts * (*(float *)((char *)arg0 + 0x7c) + *(float *)((char *)arg0 + 0x78) * k),
            lbl_80564428);
        fn_80290160(arg0, (float *)&pos, p, t);
        fn_8028F608((float *)&axA, (float *)&axB, (float (*)[3])cam, ang);
        bb = (float *)fn_802C86DC();
        cam2 = *(EfCam *)bb;
        dir.x = cam2.p.x - pos.x;
        dir.y = cam2.p.y - pos.y;
        dir.z = cam2.p.z - pos.z;
        {
            float c0 = *(float *)((char *)arg0 + 0x3c);
            float c1 = *(float *)((char *)arg0 + 0x40);
            tm = c1 + (PSVECDotProduct((float *)&dir, (float *)&dir) / (k2 + c0 * c0)) * (k2 - c1);
        }
        if (k2 < tm) tm = k2;
        tm = (tm > k3) ? tm : k3;
        nh = -h;
        q[0].x = pos.x + axA.x * nh + axB.x * h;
        q[0].y = pos.y + axA.y * nh + axB.y * h;
        q[0].z = pos.z + axA.z * nh + axB.z * h;
        q[1].x = q[0].x + axA.x * (k10 * h);
        q[1].y = q[0].y + axA.y * (k10 * h);
        q[1].z = q[0].z + axA.z * (k10 * h);
        q[2].x = q[1].x + axB.x * (k9 * h);
        q[2].y = q[1].y + axB.y * (k9 * h);
        q[2].z = q[1].z + axB.z * (k9 * h);
        q[3].x = q[0].x + axB.x * (k9 * h);
        q[3].y = q[0].y + axB.y * (k9 * h);
        q[3].z = q[0].z + axB.z * (k9 * h);
        q[0].u = k3; q[0].v = k3;
        q[1].u = k2; q[1].v = k3;
        q[2].u = k2; q[2].v = k2;
        q[3].u = k3; q[3].v = k2;
        for (j = 0; j < 4; j++) {
            m = k4 * (one - k0 * (one - inv * (q[j].y - pos.y)));
            a = (int)(*(float *)(p + 0x24) * (tm * (k4 * (*(float *)((char *)arg0 + 0x5c) + *(float *)((char *)arg0 + 0x58) * k))));
            a = a > 0 ? a : 0; if (a > 255) a = 255;
            b = (int)(m * (*(float *)((char *)arg0 + 0x64) + *(float *)((char *)arg0 + 0x60) * k));
            b = b > 0 ? b : 0; if (b > 255) b = 255;
            g = (int)(m * (*(float *)((char *)arg0 + 0x6c) + *(float *)((char *)arg0 + 0x68) * k));
            g = g > 0 ? g : 0; if (g > 255) g = 255;
            r = (int)(m * (*(float *)((char *)arg0 + 0x74) + *(float *)((char *)arg0 + 0x70) * k));
            r = r > 0 ? r : 0; if (r > 255) r = 255;
            q[j].color = (a << 24) | ((b & 0xff) << 16) | ((g & 0xff) << 8) | (r & 0xff);
        }
        if (count >= 8) {
            fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
            count = 0;
        }
        buf.v[count * 4 + 0] = q[0];
        buf.v[count * 4 + 1] = q[1];
        buf.v[count * 4 + 2] = q[2];
        buf.v[count * 4 + 3] = q[3];
        count++;
    }
    if (count > 0) {
        fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
        count = 0;
    }
}
extern int fn_80128668(void *);
int fn_8029169C(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

/* Constant predicate (returns 0 / false); a no-op virtual getter reached through a dispatch table. */
int fn_802916DC(void) { return 0; }

/* Trivial base destructor for nw4r::ef::Effect: called by the derived destructor
 * before the object is optionally freed. */
void fn_802916E4(void) {}

/* No-op virtual method in the nw4r::ef dispatch table (compiles to a bare
   return); fn_80291700 is the thin derived override that forwards to it. */
void fn_802916E8(void) {}

/* No-op nw4r::ef virtual method; forwarded to by the thin wrapper fn_80291704. */
void fn_802916EC(void) {}

/* Return the 32-bit field at offset 0x4 of the given object (a virtual getter). */
int fn_802916F0(void *obj) { return ((int *)obj)[1]; }

int fn_802916F8(void *object) {
    /* Return the object's 32-bit field at offset 0x118 (paired with the +0x11C flag accessors). */
    return *(int *)((char *)object + 0x118);
}

#pragma dont_inline on
/* Thin derived nw4r::ef virtual override: tail-calls the no-op base method
   fn_802916E8. */
void fn_80291700(void) { fn_802916E8(); }
/* Derived virtual override that simply forwards to the no-op base method
   fn_802916EC (a tail call in the generated code). */
void fn_80291704(void) { fn_802916EC(); }

/* Set the object's boolean flag at offset 0x11C to true (paired with the clear fn_80291714 and getter fn_80291720). */
void fn_80291708(void *object) {
    *((unsigned char *)object + 0x11C) = 1;
}

/* Clear the object's boolean flag at offset 0x11C (paired with the set fn_80291708 and getter fn_80291720). */
void fn_80291714(void *object) {
    *((unsigned char *)object + 0x11C) = 0;
}

/* Read the object's boolean flag at offset 0x11C (set by fn_80291708, cleared by
 * fn_80291714; the value next to it at +0x118 is read by fn_802916F8). */
unsigned char fn_80291720(void *object) {
    return *((unsigned char *)object + 0x11C);
}

#pragma dont_inline reset
extern int lbl_8055F748;
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028F2EC();
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
