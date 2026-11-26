// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

struct Fn8029Pair { float x, y; } __attribute__((aligned(8)));
struct Fn8029Vec { float x, y, z; };
extern float lbl_805646B8;
extern float lbl_805646BC;
extern float lbl_805646C0;
extern int strlen(const char *);
__declspec(section ".sdata") extern char lbl_8055CAF0[];
__declspec(section ".sdata") extern char lbl_8055CAF4[];
__declspec(section ".sdata") extern char lbl_8055CAFC[];
__declspec(section ".sdata") extern char lbl_8055CB04[];
__declspec(section ".sdata") extern char lbl_8055CB0C[];
__declspec(section ".sdata") extern char lbl_8055CB14[];
__declspec(section ".sdata") extern char lbl_8055CB18[];
__declspec(section ".sdata") extern char lbl_8055CB1C[];
__declspec(section ".sdata") extern char lbl_8055CB28[];
__declspec(section ".sdata") extern char lbl_8055CB30[];
__declspec(section ".sdata") extern char lbl_8055CB38[];
__declspec(section ".sdata") extern char lbl_8055CB40[];
__declspec(section ".sdata") extern char lbl_8055CB48[];
struct Vec3_8029FB00 { float x, y, z; };
extern void fn_801E9DC4(void *);
extern char lbl_80349890[];
__declspec(section ".sdata") extern char lbl_8055CB50[];
__declspec(section ".sdata") extern char lbl_8055CB58[];
__declspec(section ".sdata") extern char lbl_8055CB5C[];
extern int strcmp(const char *, const char *);
extern int fn_8029FE6C(const char *);
typedef struct Unk802A0794Params {
    float values[6];
    short unk_0x18;
    int unk_0x1C;
} Unk802A0794Params;
extern void fn_802A0794(void *);
extern void fn_802A042C(void *, Unk802A0794Params *);
extern void fn_802A01C8(void *, Unk802A0794Params *);
extern void fn_802A02F4(void *, Unk802A0794Params *);
extern void fn_802E30C8(const char *, ...);
extern char lbl_803498AC[];
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern void registerNamedObject(void *);
extern char lbl_8034989C[];
__declspec(section ".sdata") extern char lbl_8055CB60[];
extern unsigned char lbl_804B5070[];
extern int lbl_8055F81C;
extern unsigned char lbl_804B6E70[];
extern int fn_800241DC(int *, void *, int, int, void *);
extern int stricmp(const char *, const char *);
  extern int fn_8029FDF0(int *, int *);
  extern void fn_8028E528(void);
  extern void fn_80292B48(void);
  extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));

extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern int fn_8028E3F4(void);
extern int fn_802929F8(void);
extern int fn_8029F3BC(unsigned char *);
extern char lbl_8034983C[];
extern char lbl_80349848[];
extern int lbl_804B9B7C[];
extern float lbl_805646B4;
extern int lbl_8055CAE8;
extern int lbl_8055F820;
extern int fn_80128670(void);
extern int fn_801EF024(void *);
extern void fn_8029FDDC(void);
extern void fn_8029FFBC(void);
extern int fn_802A0720(int *, int);
extern int fn_802A0620(Unk802A0794Params *);
extern void fn_802A002C(void);
extern int fn_801E85A4(void);
extern void fn_8029FEF8(void);
extern void fn_8029FE00(void);
extern void fn_8029FD04(void);
extern int fn_801E85AC(void);
extern int fn_8012850C(int, void *);
extern int Event_RegisterHandler(void *, int);
extern char lbl_80349810[];
extern unsigned char lbl_804B7770[];
extern int lbl_8055F818;
extern void *memset(void *, int, unsigned int);
extern void fn_802029FC(void);
extern void fn_802C92D0(void);
extern void fn_802C92D8(void);
extern void fn_801E88B4(int *, int *, int *, int *, int);
extern void fn_802C92DC(int, int, int, int, int);
extern float lbl_805646B0;
extern int lbl_8055F824;
extern unsigned char lbl_8055F73C;
extern char lbl_8034981C[];
extern int fn_801769F8(void);
#pragma push
#pragma scheduling invalid_target
void fn_8029F03C(void) {
    /* Initialize the particle / track-effect system: clear the record counts, name tables and
     * effect records, build track effects from scene objects and emitters from the resource
     * group, register the two effect event handlers (types 10 and 11), and allocate the
     * per-view screen-rect table ("fsrecttab"). Counterpart of the shutdown fn_8029F0D0. */
#define trackEffectCount lbl_8055F81C
#define emitterNameCount lbl_8055F818
#define emitterNameTable lbl_804B7770
#define effectNameTable  lbl_804B6E70
#define initTrackEffects fn_8029FEF8
#define sortEffectRecords fn_8029FE00
#define registerEmitters fn_8029FD04
#define registerEventHandler Event_RegisterHandler
#define emitEffectBurst fn_802A0620
#define triggerEmitters fn_802A0720
#define screenRectTab lbl_8055F820
#define getViewCount fn_801E85AC
#define allocHeapBlock fn_8012850C
#define fsRectTabName lbl_80349810

    trackEffectCount = 0;
    emitterNameCount = 0;
    memset(emitterNameTable, 0, 0x2400);
    memset(effectNameTable, 0, 0x900);
    initTrackEffects();
    sortEffectRecords();
    registerEmitters();
    registerEventHandler(&emitEffectBurst, 10);
    registerEventHandler(&triggerEmitters, 11);
    screenRectTab = allocHeapBlock(getViewCount() * 4, &fsRectTabName);
#undef fsRectTabName
#undef allocHeapBlock
#undef getViewCount
#undef screenRectTab
#undef triggerEmitters
#undef emitEffectBurst
#undef registerEventHandler
#undef registerEmitters
#undef sortEffectRecords
#undef initTrackEffects
#undef effectNameTable
#undef emitterNameTable
#undef emitterNameCount
#undef trackEffectCount
}
#pragma pop
void fn_8029F0D0(void) {
    /* Shuts the particle / track-effect system down (counterpart of the init fn_8029F03C):
     * releases the per-view screen-rect table, unregisters the two effect event handlers
     * from the world/event registry, empties the emitter-record table and destroys the
     * objects every active track-effect record owns. */
#define screenRectTab lbl_8055F820 /* heap block "fsrecttab": one u32 per view */
#define freeHeapBlock fn_80128670
#define unregisterEventHandler fn_801EF024
#define triggerEmitters fn_802A0720    /* event type 11: fire emitters by id */
#define emitEffectBurst fn_802A0620    /* event type 10: emit an effect record */
#define resetEmitterTable fn_8029FDDC
#define destroyTrackEffectObjects fn_8029FFBC

    if (screenRectTab) {
        ((int (*)(int))freeHeapBlock)(screenRectTab);
    }
    screenRectTab = 0;
    unregisterEventHandler((void *)triggerEmitters);
    unregisterEventHandler((void *)emitEffectBurst);
    resetEmitterTable();
    destroyTrackEffectObjects();
#undef screenRectTab
#undef freeHeapBlock
#undef unregisterEventHandler
#undef triggerEmitters
#undef emitEffectBurst
#undef resetEmitterTable
#undef destroyTrackEffectObjects
}

#pragma push
#pragma scheduling invalid_target
void fn_8029F124(void) {
    /* Update track effects and clear all per-entry track-effect states. */
    int clearValue;
    int byteOffset;
    int entryIndex;

    fn_802A002C();
    entryIndex = 0;
    byteOffset = 0;
    clearValue = 0;
    while (entryIndex < fn_801E85A4()) {
        entryIndex++;
        *(int *)((char *)lbl_8055F820 + byteOffset) = clearValue;
        byteOffset += 4;
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Effect entry layout (0x34 bytes) and globals used by fn_8029F188. */
#define EFFECT_POS_X 0x4
#define EFFECT_POS_Y 0x8
#define EFFECT_POS_Z 0xc
#define EFFECT_VEL_X 0x10
#define EFFECT_VEL_Y 0x14
#define EFFECT_VEL_Z 0x18
#define EFFECT_BASE_X 0x1c
#define EFFECT_BASE_Y 0x20
#define EFFECT_BASE_Z 0x24
#define EFFECT_SPAWN_FLAG 0x2e
#define EFFECT_OBJECT 0x30
#define EFFECT_STRIDE 0x34
#define gAllowParticleAdd lbl_8055F73C
#define gWarnCounter lbl_8055F824
#define gWarnParticleAddFalse lbl_8034981C
#define gTimeStep lbl_805646B0
#define gEffectAllocator lbl_804B9B7C

#pragma use_lmw_stmw off
void fn_8029F188(void) {
    /* Refreshes each effect's velocity from its attached object and advances its position,
       then dispatches spawn requests for flagged effects when particle adds are enabled. */
    unsigned char *effect;
    float timeStep;
    void *allocator;
    int entryOffset;
    int index;

    if (gAllowParticleAdd != 1) {
        if (gWarnCounter == 0) {
            fn_802E30C8(gWarnParticleAddFalse);
        }
        gWarnCounter = (gWarnCounter + 1) % 5;
    }
    timeStep = gTimeStep;
    allocator = gEffectAllocator;
    index = 0;
    entryOffset = 0;
    for (; index < *(int *)((char *)allocator + 4); entryOffset += EFFECT_STRIDE, index++) {
        unsigned char *object;
        effect = *(unsigned char **)gEffectAllocator + entryOffset;
        object = *(unsigned char **)(effect + EFFECT_OBJECT);
        if (object != 0) {
            float dx = *(float *)(object + 0x60) - *(float *)(effect + EFFECT_POS_X);
            float dy;
            float dz;
            *(float *)(effect + EFFECT_VEL_X) = dx;
            dy = *(float *)(object + 0x64) - *(float *)(effect + EFFECT_POS_Y);
            *(float *)(effect + EFFECT_VEL_Y) = dy;
            dz = *(float *)(object + 0x68) - *(float *)(effect + EFFECT_POS_Z);
            *(float *)(effect + EFFECT_VEL_X) = dx * timeStep;
            *(float *)(effect + EFFECT_VEL_X) += *(float *)(effect + EFFECT_BASE_X);
            *(float *)(effect + EFFECT_VEL_Y) = dy * timeStep;
            *(float *)(effect + EFFECT_VEL_Y) += *(float *)(effect + EFFECT_BASE_Y);
            *(float *)(effect + EFFECT_VEL_Z) = dz * timeStep;
            *(float *)(effect + EFFECT_VEL_Z) += *(float *)(effect + EFFECT_BASE_Z);
            *(float *)(effect + EFFECT_POS_X) = *(float *)(object + 0x60);
            *(float *)(effect + EFFECT_POS_Y) = *(float *)(object + 0x64);
            *(float *)(effect + EFFECT_POS_Z) = *(float *)(object + 0x68);
        } else {
            *(float *)(effect + EFFECT_VEL_X) = *(float *)(effect + EFFECT_BASE_X);
            *(float *)(effect + EFFECT_VEL_Y) = *(float *)(effect + EFFECT_BASE_Y);
            *(float *)(effect + EFFECT_VEL_Z) = *(float *)(effect + EFFECT_BASE_Z);
        }
        if (effect[EFFECT_SPAWN_FLAG] != 0 && fn_801769F8() == 0) {
            fn_802A0794(effect);
        }
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
/* Per-frame: refresh HUD/effect state, then for each active view (when count is 1) draw a
   screen quad if the entry at lbl_8055F820 has a nonzero high byte; clears each entry. */
void fn_8029F300(void) {
    int byteOffset, entryIndex, clearValue;
    int left, top, right, bottom;
    fn_802029FC();
    entryIndex = 0;
    byteOffset = 0;
    clearValue = 0;
    goto check;
loop:
    if (fn_801E85A4() == 1) {
        fn_802C92D0();
        if (((unsigned int)*(int *)((char *)lbl_8055F820 + byteOffset) >> 24) != 0) {
            fn_801E88B4(&left, &top, &right, &bottom, entryIndex);
            fn_802C92DC(left, top, right, bottom, *(int *)((char *)lbl_8055F820 + byteOffset));
        }
        fn_802C92D8();
    }
    entryIndex++;
    *(int *)((char *)lbl_8055F820 + byteOffset) = clearValue;
    byteOffset += 4;
check:
    if (entryIndex < fn_801E85A4()) goto loop;
}
#pragma scheduling on
#pragma pop

#pragma push
#pragma scheduling invalid_target
/* Look up a 0x24-byte name table entry by case-insensitive string and return its id at +0x20, or -1 if not found. */
int fn_8029F3BC(unsigned char *name) {
    unsigned char *entry = lbl_804B7770;
    int index = 0;
    while (index < lbl_804B9B7C[1]) {
        if (stricmp((const char *)entry, (const char *)name) == 0)
            return *(int *)(lbl_804B7770 + index * 0x24 + 0x20);
        entry += 0x24;
        index++;
    }
    return -1;
}
#pragma scheduling on
#pragma pop

#pragma scheduling invalid_target
#pragma dont_inline on
void fn_8029F458(const char *name, int value) {
    /* Copy name (minus an optional leading '$'), look up its id, and write value to the +0x30 field of every 0x34-byte record in the table whose id matches. */
    unsigned char nameBuf[0x20];
    unsigned char c;
    int remaining;
    unsigned char *dst;
    int id;
    unsigned char *entry;
    int offset;
    int *table;
    int i;
    if (*name == '$')
        name++;
    dst = nameBuf;
    remaining = 0x20;
    goto copy;
decrement:
    remaining--;
    if (remaining > 0)
        goto copy;
    dst[-1] = 0;
    goto lookup;
copy:
    c = *name++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto decrement;
lookup:
    id = fn_8029F3BC(nameBuf);
    table = lbl_804B9B7C;
    i = 0;
    offset = 0;
    for (; i < ((volatile int *)table)[1]; i++) {
        entry = (unsigned char *)*(volatile int *)&lbl_804B9B7C[0] + offset;
        if (*(int *)entry == id)
            *(int *)(entry + 0x30) = value;
        offset += 0x34;
    }
}
#pragma dont_inline reset
#pragma scheduling on
/* Set the byte at `flag` to 1 when `value` is nonzero (0 otherwise) and
 * return the stored value — a validity gate used by config initializers. */
unsigned char fn_8029F510(unsigned char *flag, int value) {
    if (value != 0) {
        *flag = 1;
    } else {
        *flag = 0;
    }
    return *flag;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma optimization_level 2
extern "C" void fn_8029F534(void *arg0, unsigned char *arg1) {
    /* Initialize output from config object: copy name, cache id, and "rotating" flag if valid. */
    class Obj {
    public:
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void set(const char *) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual unsigned char getBool(const char *, int) = 0;
    };
    Obj *obj = (Obj *)arg1;

    if (((int (*)(unsigned char *, int))fn_8029F510)((unsigned char *)arg0, (int)arg1) != 0) {
        obj->set((const char *)&lbl_8034983C);
        *(int *)((char *)arg0 + 4) = fn_8028E3F4();
        *(unsigned char *)((char *)arg0 + 8) = obj->getBool((const char *)&lbl_80349848, 0);
    } else {
        *(int *)((char *)arg0 + 4) = 0;
    }
}
#pragma scheduling on
#pragma cplusplus off
#pragma pop


#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma optimization_level 2
extern "C" void fn_8029F5C8(void *out, unsigned char *config) {
    /* Initialize output from config object: select "sys_name", cache the loaded
       resource id at +4, and read the "upwards" float at +8 (default 0.0) if valid. */
    class Obj {
    public:
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void set(const char *) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual float getFloat(float, const char *) = 0;
    };
    Obj *configObj = (Obj *)config;
    if (((int (*)(unsigned char *, int))fn_8029F510)((unsigned char *)out, (int)config) != 0) {
        configObj->set((const char *)&lbl_8034983C);
        *(int *)((char *)out + 4) = fn_802929F8();
        *(float *)((char *)out + 8) = configObj->getFloat(0.0f, (const char *)&lbl_8055CAE8);
    } else {
        *(int *)((char *)out + 4) = 0;
    }
}

#pragma push
#pragma cplusplus on
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_8029F658(void *arg0) {
    class Obj {
    public:
        virtual const char *name();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual int getId(const char *);
        virtual int getProp(const char *, int);
        virtual void v7();
        virtual float getFloat(float, const char *);
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual Fn8029Vec getVec(const char *, const Fn8029Vec &);
        virtual void v13();
        virtual Fn8029Pair getPair(const char *, const Fn8029Pair &);
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual int getSub(const char *);
    };
    char *table;
    unsigned char *record;
    Obj *obj;
    unsigned char c;
    int n;
    unsigned char *dst;
    char *src;
    const char *str;
    Fn8029Vec defaultVec;
    Fn8029Vec v2copy;
    Fn8029Vec v1;
    Fn8029Vec vecArg1;
    Fn8029Vec v2;
    Fn8029Vec vecArg2;
    Fn8029Vec defaultVec2;
    Fn8029Vec v3;
    Fn8029Vec vecArg3;
    union PairStorage {
        Fn8029Pair pair;
        double bits;
    };
    PairStorage pairDefault;
    Fn8029Pair out1;
    PairStorage pairArg1;
    Fn8029Pair out2;
    PairStorage pairArg2;
    Fn8029Pair out3;
    PairStorage pairArg3;
    Fn8029Pair out4;
    PairStorage pairArg4;
    Fn8029Pair out5;
    PairStorage pairArg5;
    int packed;
    int rPart;
    int gPart;
    int bPart;
    int hi;
    int lo;

    table = lbl_80349810;
    record = lbl_804B5070 + lbl_8055F81C * 0x78;
    obj = (Obj *)arg0;
    defaultVec.x = 0.0f;
    defaultVec.y = 0.0f;
    defaultVec.z = 0.0f;
    pairDefault.pair.x = 0.0f;
    pairDefault.pair.y = 0.0f;
    *(int *)record = obj->getId(lbl_8055CAF0);
    str = obj->name();
    src = (char *)str + strlen(&table[0x44]);
    if (*src == '_')
        src++;
    dst = lbl_804B6E70 + lbl_8055F81C * 0x24;
    *(int *)(dst + 0x20) = *(int *)record;
    n = 0x20;
    goto copy_start;
dec:
    n--;
    if (n > 0) goto copy;
    dst[-1] = 0;
    goto done;
copy_start:
copy:
    c = *(unsigned char *)src++;
    *dst++ = c;
    if ((signed char)c != 0) goto dec;
done:
    *(float *)(record + 4) = obj->getFloat(lbl_805646B4, &table[0x50]);
    *(float *)(record + 8) = obj->getFloat(lbl_805646B4, lbl_8055CAF4);
    *(float *)(record + 0xC) = obj->getFloat(lbl_805646B4, lbl_8055CAFC);
    pairArg1.bits = pairDefault.bits;
    out1 = obj->getPair(lbl_8055CB04, pairArg1.pair);
    *(float *)(record + 0x10) = out1.x;
    *(float *)(record + 0x14) = out1.y;
    pairArg2.bits = pairDefault.bits;
    out2 = obj->getPair(lbl_8055CB0C, pairArg2.pair);
    *(float *)(record + 0x18) = out2.x;
    *(float *)(record + 0x1C) = out2.y;
    pairArg3.bits = pairDefault.bits;
    out3 = obj->getPair(lbl_8055CB14, pairArg3.pair);
    *(float *)(record + 0x20) = out3.x;
    *(float *)(record + 0x24) = out3.y;
    pairArg4.bits = pairDefault.bits;
    out4 = obj->getPair(lbl_8055CB18, pairArg4.pair);
    *(float *)(record + 0x28) = out4.x;
    *(float *)(record + 0x2C) = out4.y;
    vecArg1 = defaultVec;
    v1 = obj->getVec(lbl_8055CB1C, vecArg1);
    *(float *)(record + 0x30) = v1.x;
    *(float *)(record + 0x34) = v1.y;
    *(float *)(record + 0x38) = v1.z;
    pairArg5.bits = pairDefault.bits;
    out5 = obj->getPair(lbl_8055CB28, pairArg5.pair);
    *(float *)(record + 0x3C) = out5.x;
    *(float *)(record + 0x40) = out5.y;
    *(float *)(record + 0x44) = obj->getFloat(lbl_805646B8, lbl_8055CB30);
    *(float *)(record + 0x48) = obj->getFloat(lbl_805646B4, &table[0x5C]);
    defaultVec2.x = lbl_805646BC;
    defaultVec2.y = lbl_805646BC;
    defaultVec2.z = lbl_805646BC;
    vecArg2 = defaultVec2;
    v2 = obj->getVec(&table[0x68], vecArg2);
    v2copy = v2;
    {
        float r = lbl_805646C0 * v2copy.x;
        float g = lbl_805646C0 * v2copy.y;
        float b = lbl_805646C0 * v2copy.z;
        rPart = (int)r;
        hi = 0xFF000000 | ((rPart & 0xFF) << 16);
        gPart = (int)g;
        bPart = (int)b;
    }
    lo = (gPart & 0xFF) << 8;
    lo |= (unsigned char)bPart;
    packed = lo | hi;
    *(int *)(record + 0x4C) = packed;
    *(int *)(record + 0x50) = obj->getProp(lbl_8055CB38, 1);
    vecArg3 = defaultVec;
    v3 = obj->getVec(lbl_8055CB40, vecArg3);
    *(float *)(record + 0x54) = v3.x;
    *(float *)(record + 0x58) = v3.y;
    *(float *)(record + 0x5C) = v3.z;
    fn_8029F534(record + 0x60, (unsigned char *)obj->getSub(&table[0x74]));
    fn_8029F5C8(record + 0x6C, (unsigned char *)obj->getSub(lbl_8055CB48));
    lbl_8055F81C++;
}
#pragma dont_inline reset
#pragma cplusplus off
#pragma pop

#pragma cplusplus on
/* Look up an object's name in the 0x24-byte name table (adding it if new), then allocate and fill a 0x34-byte instance entry with its id, a bool flag, type id, position and direction vectors, and initialize the trailing subfield. */ extern "C" void registerNamedObject(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual const char *name(const char *);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual unsigned char getBool(const char *, int);
        virtual Vec3_8029FB00 getVec(const char *);
    };
    /* Looks up an object by name in a table (or registers it if new), allocates/fills a 0x34-byte entry
       with its id, a bool flag, type id, position and direction vectors, and initializes a subfield. */
    Vec3_8029FB00 pos;
    Vec3_8029FB00 dir;
    unsigned char *entry;
    char *tableCursor;
    char *idCursor;
    int foundId;
    int i;
    int *allocator;
    Obj *obj = (Obj *)arg0;

    foundId = lbl_8055F818;
    tableCursor = (char *)lbl_804B7770;
    allocator = lbl_804B9B7C;
    entry = *(unsigned char **)allocator + allocator[1]++ * 0x34;
    idCursor = tableCursor;
    for (i = 0; i < lbl_8055F818; i++) {
        if (strcmp(tableCursor, obj->name(lbl_8055CB50)) == 0)
            foundId = *(int *)(idCursor + 0x20);
        tableCursor += 0x24;
        idCursor += 0x24;
    }

    *(int *)entry = foundId;
    *(unsigned char *)(entry + 0x2e) = obj->getBool(lbl_80349890, 0);
    *(int *)(entry + 0x28) = fn_8029FE6C(obj->name(lbl_8034983C));

    pos = obj->getVec(lbl_8055CB58);
    *(float *)(entry + 4) = pos.x;
    *(float *)(entry + 8) = pos.y;
    *(float *)(entry + 0xc) = pos.z;

    dir = obj->getVec(lbl_8055CB5C);
    {
        float z, y, x;
        x = dir.x;
        *(float *)(entry + 0x1c) = x;
        y = dir.y;
        *(float *)(entry + 0x20) = y;
        z = dir.z;
        *(float *)(entry + 0x24) = z;
        *(int *)(entry + 0x30) = 0;
        *(float *)(entry + 0x10) = x;
        *(float *)(entry + 0x14) = y;
        *(float *)(entry + 0x18) = z;
    }

    fn_801E9DC4(entry + 0x2c);

    if (foundId == lbl_8055F818) {
        const char *src;
        int n;
        char *dst;
        unsigned char c;
        *(int *)(lbl_804B7770 + lbl_8055F818 * 0x24 + 0x20) = foundId;
        src = obj->name(lbl_8055CB50);
        dst = (char *)lbl_804B7770 + lbl_8055F818 * 0x24;
        n = 0x20;
        goto copy;
    dec:
        n--;
        if (n > 0) goto copy;
        dst[-1] = 0;
        goto done;
    copy:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0) goto dec;
    done:
        lbl_8055F818++;
    }
}
#pragma cplusplus off

#pragma scheduling on
#pragma cplusplus off
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
// Loads the "partemit.val" resource group (lbl_8034989C) and registers every child named
// "emitter" (lbl_8055CB60) into the emitter table via registerNamedObject. The emitter-record bump
// allocator (lbl_804B9B7C: base pointer at [0], count at [1]) is reset first; the group
// handle is released again at the end.
extern "C" void fn_8029FD04(void) {
    /* Dummy interface for a "partemit.val" resource group: name() returns a child's
       resource name, child(i) returns the i-th child (NULL past the end). */
    class PartemitGroup {
    public:
        virtual const char *name();
        virtual PartemitGroup *child(int);
    };
    PartemitGroup *group;
    int childIndex;
    PartemitGroup *child;
    lbl_804B9B7C[1] = 0;
    group = (PartemitGroup *)fn_80131810(lbl_8034989C);
    if (group != 0) {
        childIndex = 0;
        child = group->child(childIndex++);
        while (child != 0) {
            if (stricmp(child->name(), lbl_8055CB60) == 0)
                registerNamedObject(child);
            child = group->child(childIndex++);
        }
        fn_80131818(group);
    }
}
#pragma cplusplus off
#pragma scheduling invalid_target
void fn_8029FDDC(void) {
    /* Reset the effect-record allocator's live count (base ptr at [0], count at [1]) to zero. */
    gEffectAllocator[1] = 0;
}
#pragma scheduling on

#pragma pop

/* Ascending numeric comparator for qsort/bsearch over int-keyed tables. */
int fn_8029FDF0(int *a, int *b) {
    return *a - *b;
}

void fn_8029FE00(void) {
    /* Sort the effect-record table (0x78-byte entries) in place by id, using fn_8029FDF0 as the comparator. */
    int count;
    int (*compare)(const void *, const void *);
    count = lbl_8055F81C;
    compare = (int (*)(const void *, const void *))fn_8029FDF0;
    qsort(lbl_804B5070, count, 0x78, compare);
}

#pragma push
#pragma dont_inline on
/* Look up a record in the lbl_804B5070 table (element size 0x78, count lbl_8055F81C) using fn_8029FDF0 as comparator. Returns 0 for non-positive keys. */
int fn_8029FE1C(int arg0) {
#define table lbl_804B5070
#define count lbl_8055F81C
#define compare fn_8029FDF0
    int key = arg0;
    if (arg0 <= 0)
        return 0;
    return fn_800241DC(&key, table, count, 0x78, compare);
#undef table
#undef count
#undef compare
}

#pragma pop
int fn_8029FE6C(const char *name) {
    /* Look up a 0x24-byte named entry in lbl_804B6E70 (count lbl_8055F81C) by case-insensitive name; return its field at +0x20, or -1 if not found. */
    unsigned char *entry = lbl_804B6E70;
    int index = 0;
    goto check;
loop:
    if (stricmp((const char *)entry, name) == 0)
        return *(int *)(lbl_804B6E70 + index * 0x24 + 0x20);
    entry += 0x24;
    index++;
check:
    if (index < lbl_8055F81C) goto loop;
    return -1;
}

  extern void *fn_802AE4C8(int);
  extern void fn_8029F658(void *);
  extern char lbl_80349854[];
  extern int strncmp(const char *, const char *, unsigned int);
  #pragma cplusplus on
      class Dummy_8029FEF8 {
  public:
      virtual const char *d0();
      virtual void *f1(int);
  };
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Initialize track-effect entries by scanning scene objects for children named "trkeffect*". */
extern "C" void fn_8029FEF8(void) {
    Dummy_8029FEF8 *sceneObj;
    int objIndex = 0;
    int childIndex;
    Dummy_8029FEF8 *childObj;

    while ((sceneObj = (Dummy_8029FEF8 *)fn_802AE4C8(objIndex)) != 0) {
        childIndex = 0;
        while (sceneObj->f1(childIndex) != 0) {
            childObj = (Dummy_8029FEF8 *)sceneObj->f1(childIndex);
            if (strncmp(childObj->d0(), lbl_80349854, 9) == 0) {
                fn_8029F658(childObj);
            }
            childIndex++;
        }
        objIndex++;
    }
}
#pragma cplusplus off
#pragma pop
void fn_8029FFBC(void) {
    /* For each active entry in the lbl_804B5070 table, destroy the objects at
     * offsets 0x64 and 0x70 if present (0x78-byte entries). */
    unsigned char *current = lbl_804B5070;
    int i = 0;
    int temp;
    goto check;
loop:
    temp = *(int *)(current + 0x64);
    if (temp != 0) ((void (*)(int))fn_8028E528)(temp);
    temp = *(int *)(current + 0x70);
    if (temp != 0) ((void (*)(void *))fn_80292B48)((void *)temp);
    current += 0x78;
    i++;
check:
    if (i < lbl_8055F81C) goto loop;
}

#pragma cplusplus on
extern "C" void fn_802A002C(void) {
    /* Update each active track-effect entry by invoking virtual method 1 on the
     * object stored at offset 0x70 in the 0x78-byte entry table. */
#define trackEffectTable lbl_804B5070
#define trackEffectCount lbl_8055F81C
    struct TrackEffectObject {
        virtual void m0();
        virtual void Update();
        virtual void m2();
        virtual void m3();
    };
    unsigned char *entry = (unsigned char *)trackEffectTable;
    int index = 0;
    goto check;
loop:
    {
        TrackEffectObject *object = (TrackEffectObject *)*(void **)(entry + 0x70);
        if (object != 0) {
            object->Update();
        }
    }
    entry += 0x78;
    index++;
check:
    if (index < trackEffectCount) {
        goto loop;
    }
#undef trackEffectTable
#undef trackEffectCount
}
#pragma cplusplus reset
typedef struct Result_802A0098 {
    int count;
    float data[10];
} Result_802A0098;
extern "C" float PSVECMag(const void *);
extern float lbl_805646BC;
#pragma opt_lifetimes off
extern "C" void fn_802A0098(Result_802A0098 *out, const float *arg0, const Unk802A0794Params *arg1)
{
  float span = arg0[1] * PSVECMag(&arg1->values[3]);
  float width = lbl_805646BC;
  width = (width < span) ? (width) : (span);
  out->count = (int) (arg0[2] + (arg0[3] * width));
  out->data[0] = arg1->values[0] + arg0[12];
  out->data[(((1 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF] = arg1->values[1] + arg0[13];
  out->data[2] = (0, arg1->values[2] + arg0[14]);
  out->data[3] = arg1->values[3] * arg0[15];
  out->data[4] = ((0, arg1->values[4])) * arg0[16];
  out->data[5] = arg1->values[5] * arg0[15];
  out->data[6] = arg0[4] + (arg0[6] * width);
  out->data[7] = arg0[5] + (arg0[7] * width);
  out->data[8] = arg0[8] + (arg0[10] * width);
  out->data[9] = arg0[9] + (arg0[11] * width);
}
#pragma opt_lifetimes reset
extern "C" float fn_80287BC8(float, float);
extern void fn_802A0098(void *, void *, Unk802A0794Params *);
extern int fn_8028E584(int, float *, float *);
extern int fn_8028E590(int, float *, float *, float);
extern float lbl_805646C4;
#pragma push
#pragma cplusplus off
extern float fn_80287BC8(float, float);
#pragma push
#pragma processor 750
#pragma cplusplus off
void fn_802A01C8(void *arg0, Unk802A0794Params *params) {
    struct Result {
        int count;
        float data[10];
    } out;
    float a[3];
    float b[3];
    float a0, a1, a2;
    float b0, b1, b2;
    unsigned char flag;
    int i;

    fn_802A0098(&out, arg0, params);
    for (i = 0; i < out.count; i++) {
        a2 = out.data[2] + fn_80287BC8(-out.data[6], out.data[6]);
        a1 = out.data[1] + fn_80287BC8(-out.data[7], out.data[7]);
        a0 = out.data[0] + fn_80287BC8(-out.data[6], out.data[6]);
        a[0] = a0;
        a[1] = a1;
        a[2] = a2;

        b2 = out.data[5] + fn_80287BC8(-out.data[8], out.data[8]);
        b1 = out.data[4] + fn_80287BC8(-out.data[9], out.data[9]);
        b0 = out.data[3] + fn_80287BC8(-out.data[8], out.data[8]);
        b[1] = b1;
        flag = *(unsigned char *)((char *)arg0 + 0x68);
        b[2] = b2;
        b[0] = b0;

        if (flag != 0) {
            fn_8028E590(*(int *)((char *)arg0 + 0x64), a, b, lbl_805646C4);
        } else {
            fn_8028E584(*(int *)((char *)arg0 + 0x64), a, b);
        }
    }
}

#pragma push
#pragma cplusplus on
#pragma processor 750
extern "C" void fn_802A02F4(void *arg0, Unk802A0794Params *params) {
    class TargetObj {
    public:
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void call(float *, float *, short, int) = 0;
    };
    struct Arg0 { char pad[0x70]; TargetObj *obj; float f74; };
    Arg0 *a0 = (Arg0 *)arg0;
    Result_802A0098 out;
    float a[3];
    float b[3];
    float a0_, a1, a2;
    float b0, b1, b2;
    int i;

    fn_802A0098(&out, arg0, params);
    out.data[4] += a0->f74;

    for (i = 0; i < out.count; i++) {
        a2 = out.data[2] + fn_80287BC8(-out.data[6], out.data[6]);
        a1 = out.data[1] + fn_80287BC8(-out.data[7], out.data[7]);
        a0_ = out.data[0] + fn_80287BC8(-out.data[6], out.data[6]);
        a[1] = a1;
        a[2] = a2;
        a[0] = a0_;

        b2 = out.data[5] + fn_80287BC8(-out.data[8], out.data[8]);
        b1 = out.data[4] + fn_80287BC8(-out.data[9], out.data[9]);
        b0 = out.data[3] + fn_80287BC8(-out.data[8], out.data[8]);
        b[1] = b1;
        b[2] = b2;
        b[0] = b0;

        a0->obj->call(a, b, params->unk_0x18, -1);
    }
}
#pragma pop

#pragma pop
#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
extern float lbl_805646BC, lbl_805646C0, lbl_805646C8;
extern "C" void *fn_801E8718(int);
extern "C" float PSVECDotProduct(const float *, const float *);
extern "C" int fn_801E85A4(void);
#pragma push
#pragma scheduling invalid_target
void fn_802A042C(void *arg0, Unk802A0794Params *arg1)
{
  struct Entry
  {
    unsigned int words[12];
  };
  struct Entry copy;
  float bias;
  float scale;
  float upper;
  float lower;
  struct Fn8029Vec point;
  struct Fn8029Vec delta;
  void *obj;
  int i;
  float radius2;
  Unk802A0794Params *pos;
  lower = lbl_805646BC;
  obj = arg0;
  upper = lbl_805646B4;
  pos = arg1;
  scale = lbl_805646C0;
  bias = lbl_805646C8;
  i = 0;
  goto test;
  body:
  {
    float dot;
    struct Entry *entry = (struct Entry *) fn_801E8718(i);
    float radius;
    copy = *entry;
    point.x = pos->values[0] + (*((float *) (((char *) obj) + 0x30)));
    point.y = pos->values[1] + (*((float *) (((char *) obj) + 0x34)));
    point.z = pos->values[2] + (*((float *) (((char *) obj) + 0x38)));
    radius = *((float *) (((char *) obj) + 0x44));
    radius2 = radius * radius;
    delta.x = point.x - (*((float *) (&copy.words[9])));
    delta.y = point.y - (*((float *) (&copy.words[10])));
    delta.z = point.z - (*((float *) (&copy.words[11])));
    dot = PSVECDotProduct((const float *) (&delta), (const float *) (&delta));
    if (dot < radius2)
    {
      float base;
      float amount = dot / radius2;
      register float next;
      int clamped;
      int alpha;
      unsigned int *colors;
      unsigned int old;
      unsigned int objectColor;
      long output;
      if (lower < amount)
      {
        amount = lower;
      }
      amount = (amount > upper) ? (amount) : (upper);
      base = scale * (*((float *) (((char *) obj) + 0x48)));
      next = base + (amount * (upper - base));
      if (next < upper)
      {
        next = next - bias;
      }
      else
      {
        next = bias + next;
      }
      colors = (unsigned int *) lbl_8055F820;
      old = colors[i];
      alpha = ((int) (old >> 24)) + ((int) next);
      alpha = alpha & (((-alpha) & (~alpha)) >> 31);
      clamped = 255;
      if (255 > alpha)
      {
        clamped = alpha;
      }
      objectColor = *((unsigned int *) (((char *) obj) + 0x4C));
      output = ((objectColor & 0x00FF0000) | (((unsigned int) clamped) << 24)) | (objectColor & 0x0000FFFF);
      colors[i] = output;
    }
    i++;
  }

  test:
  if (i < fn_801E85A4())
  {
    goto body;
  }

}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
int fn_802A0620(Unk802A0794Params *arg0) {
    /* Emit an effect record's bursts: copy the request params, look up the 0x78-byte
       effect record by id, then for count (record+0x50) iterations optionally emit a
       particle burst (flag 0x60 -> fn_802A01C8) and/or a spawned object (flag 0x6C ->
       fn_802A02F4), advancing the copied position by the record's step vector (0x54..5C). */
    int tailInt;
    unsigned char *effectRecord;
    int step;
    short tailShort;
    Unk802A0794Params paramsCopy;
    int w5, w4, w3, w2, w1, w0;
    effectRecord = (unsigned char *)fn_8029FE1C(arg0->unk_0x1C);
    w0 = ((volatile int *)arg0)[0];
    w1 = ((volatile int *)arg0)[1];
    w2 = ((volatile int *)arg0)[2];
    w3 = ((volatile int *)arg0)[3];
    w4 = ((volatile int *)arg0)[4];
    w5 = ((volatile int *)arg0)[5];
    tailShort = *(volatile short *)&arg0->unk_0x18;
    tailInt = *(volatile int *)&arg0->unk_0x1C;
    ((int *)&paramsCopy)[0] = w0;
    ((int *)&paramsCopy)[1] = w1;
    ((int *)&paramsCopy)[2] = w2;
    ((int *)&paramsCopy)[3] = w3;
    ((int *)&paramsCopy)[4] = w4;
    ((int *)&paramsCopy)[5] = w5;
    paramsCopy.unk_0x18 = (unsigned)tailShort;
    paramsCopy.unk_0x1C = tailInt;
    if (effectRecord) {
        for (step = 0; step < *(int *)(effectRecord + 0x50); step++) {
            if (effectRecord[0x60] != 0) fn_802A01C8(effectRecord, &paramsCopy);
            if (effectRecord[0x6C] != 0) fn_802A02F4(effectRecord, &paramsCopy);
            paramsCopy.values[0] += *(float *)(effectRecord + 0x54);
            paramsCopy.values[1] += *(float *)(effectRecord + 0x58);
            paramsCopy.values[2] += *(float *)(effectRecord + 0x5C);
        }
    }
    return 0x20;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
/* For each registered 0x34-byte entry whose id matches arg0[0], dispatch fn_802A0794 on it. */
int fn_802A0720(int *requestId, int unused) {
    int offset;
    int index;
    index = 0;
    offset = 0;
    goto check;
loop:
    {
        int *base = (int *)lbl_804B9B7C[0];
        unsigned char *entry = (unsigned char *)base + offset;
        if (*(int *)entry == *requestId)
            fn_802A0794(entry);
    }
    offset += 0x34;
    index++;
check:
    if (index < lbl_804B9B7C[1])
        goto loop;
    return 4;
}
#pragma pop

#pragma push
#pragma inline off
/* Dispatch an effect request: read its id and parameters, look up the effect record, run its base update plus any enabled handlers, and log a warning if the id is unknown. */
void fn_802A0794(void *request) {
    Unk802A0794Params params;
    unsigned char *pEffect;
    params.unk_0x18 = *(short *)((char *)request + 0x2C);
    params.values[0] = *(float *)((char *)request + 4);
    params.values[1] = *(float *)((char *)request + 8);
    params.values[2] = *(float *)((char *)request + 12);
    params.values[3] = *(float *)((char *)request + 16);
    params.values[4] = *(float *)((char *)request + 20);
    params.values[5] = *(float *)((char *)request + 24);
    params.unk_0x1C = *(int *)((char *)request + 0x28);
    pEffect = (unsigned char *)fn_8029FE1C(params.unk_0x1C);
    if (pEffect != 0) {
        fn_802A042C(pEffect, &params);
        if (pEffect[0x60] != 0)
            fn_802A01C8(pEffect, &params);
        if (pEffect[0x6C] != 0)
            fn_802A02F4(pEffect, &params);
    } else {
        fn_802E30C8(lbl_803498AC, params.unk_0x1C);
    }
    *(short *)((char *)request + 0x2C) = params.unk_0x18;
}
#pragma pop

