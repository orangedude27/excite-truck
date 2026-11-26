extern int lbl_802FA998[];
extern char lbl_80349208[];
extern int strcmp(const char *, const char *);
extern int Abend_Panic(const char *, ...);
extern unsigned char lbl_80349294[];
extern unsigned char lbl_8034925C[];
extern void loadWoodChunkModels(void *, int, int, int);
extern char lbl_8055C988;
extern float lbl_805644D4;
extern void fn_80293374(void *, void *);
extern void *fn_802935A0(void *);
extern int fn_8012C33C(void *);
extern void fn_801345D8(void *, int, const char *, int, int);
extern int fn_802C6FC0(void *, int, int);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
extern char lbl_80349224[];
extern unsigned char lbl_80349278[];
extern float lbl_8056450C;
extern void loadTerrainChunkModels(void*, int, int, int);
extern void fn_80293EB0(void*);
extern unsigned char lbl_804B4168[];
extern void fn_80292EA8(void *);
extern void fn_80292EB4(void *);
extern int fn_80292FB4(unsigned char *, void *);
extern unsigned char lbl_804B4030[];
extern float lbl_805644D8;
extern int fn_80287B5C(int, void *, float, float, float);
extern int fn_80129D18(int, int);
extern unsigned int lbl_80488648[];
extern float lbl_805644EC;
extern double lbl_805644F0;
#pragma cplusplus on
class VTableCall_802929F8 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(const char *);
    virtual int v6(const char *);
    virtual int v7(const char *, int);
    virtual int v8(const char *, int);
};
class Dummy_80292B48 {
public:
          virtual void f0(int);
          virtual void f1(int);
    virtual void f2(int);
};
#pragma cplusplus off
// Clear the global chunk cache (lbl_804B4168) by resetting its in-use entry count to zero.
void fn_802924E8(void) {
    fn_80292EA8(lbl_804B4168);
}

extern double fn_8002F234(float);
extern float randFloatInRange(int, float, float);
extern float lbl_805644D0, lbl_805644D4, lbl_805644D8, lbl_805644DC, lbl_805644E0;
#pragma processor 750
struct Vec_802924F4 {
    float x, y, z;
};
static inline void init_all_802924F4(float one, float offset) {
    struct Vec_802924F4 v;
    unsigned char *p = lbl_804B4030;
    int i;
    for (i = 0; i < 6; i++, p += 0x34) {
        float x = randFloatInRange(0, lbl_805644D0, lbl_805644D4);
        float y = (float)fn_8002F234((one - x * x) - offset);
        float z = (float)fn_8002F234((one - x * x) - offset);
        float w = randFloatInRange(0, -z, y);
        float q = (float)fn_8002F234((one - x * x) - w * w);
        float factor = (randFloatInRange(0, lbl_805644D0, lbl_805644D4) > offset) ? lbl_805644D4 : lbl_805644D0;
        v.x = x;
        *(float *)(p + 0) = (float)(double)x;
        *(float *)(p + 4) = (float)(double)w;
        v.y = w;
        v.z = q * factor;
        *(float *)(p + 8) = v.z;
        *(float *)(p + 0xC) = randFloatInRange(0, lbl_805644DC, lbl_805644E0);
    }
}
void fn_802924F4(void) {
    struct Vec {
        float x, y, z;
    } v;
    float one = lbl_805644D4;
    float offset = lbl_805644D8;
    unsigned char *p = lbl_804B4030;
    long i;

    for (i = 0; i < 6; i++, p += 0x34) {
        register float x = randFloatInRange(0, lbl_805644D0, lbl_805644D4);
        float y = (float)fn_8002F234((one - x * x) - offset);
        float z = (float)fn_8002F234((one - x * x) - offset);
        float w = randFloatInRange(0, -z, y);
        float q = (float)fn_8002F234((one - x * x) - w * w);
        float factor = (randFloatInRange(0, lbl_805644D0, lbl_805644D4) > offset) ? lbl_805644D4 : lbl_805644D0;
        v.x = x;
        *(float *)(p + 0) = (float)(double)x;
        v.y = w;
        v.z = q * factor;
        *(float *)(p + 4) = (float)(double)w;
        *(float *)(p + 8) = v.z;
        *(float *)(p + 0xC) = randFloatInRange(0, lbl_805644DC, lbl_805644E0);
    }
}
/* Teardown counterpart to fn_802924F4 in the subsystem shutdown sequence
 * (fn_802878A8). The 6-entry rotation data at lbl_804B4030 needs no cleanup,
 * so this intentionally does nothing. */
void fn_80292618(void) {
}

/* Empty the global chunk cache. */
void fn_8029261C(void) {
#define gChunkCache lbl_804B4168
    fn_80292EB4(gChunkCache);
#undef gChunkCache
}

#pragma cplusplus on
#pragma scheduling invalid_target
/* Calls virtual method 1 on the object stored in each 0x18-byte entry of the global object list. */
extern "C" void fn_80292628(void) {
    class EntryObject {
    public:
        virtual void v0();
        virtual void v1();
    };
    register unsigned char *entry;
    register s32 index;
    entry = lbl_804B4168;
    index = 0;
    for (; index < *(s32 *)(lbl_804B4168 + 0x180); entry += 0x18, index++) {
        EntryObject *object = *(EntryObject **)(entry + 0x10);
        object->v1();
    }
}

extern "C" float fn_801E7E18(void);
extern "C" float PSVECMag(float *);
extern "C" double sin(float);
extern "C" double cos(float);
extern float lbl_805644E4;
extern "C" void fn_80292698(void) {
    class Dummy_80292698 {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
    };
    register int i;
    register unsigned char *p;
    float angle;

    angle = fn_801E7E18();
    p = lbl_804B4030;
    i = 0;
    for (; i < 6; ++i, p += 0x34) {
        float axis[3];
        float z, y, x, s, c, t, tx, ty, xx, yy, zz, magnitude;
        float scale = angle * *(float *)(p + 0xC);
        axis[0] = *(float *)(p + 0x0) * scale;
        axis[1] = *(float *)(p + 0x4) * scale;
        axis[2] = *(float *)(p + 0x8) * scale;
        magnitude = PSVECMag(axis);
        if (magnitude > 0.0001f) {
            float inverse = 1.0f / magnitude;
            z = inverse * axis[2];
            y = inverse * axis[1];
            x = inverse * axis[0];
            s = (float)sin(magnitude);
            c = (float)cos(magnitude);
            xx = x * x;
            t = 1.0f - c;
            tx = t * x;
            ty = t * y;
            yy = y * y;
            *(float *)(p + 0x10) = c + t * xx;
            *(float *)(p + 0x14) = (y * tx) + (s * z);
            *(float *)(p + 0x18) = (z * tx) - (s * y);
            *(float *)(p + 0x1C) = (y * tx) - (s * z);
            *(float *)(p + 0x20) = c + t * yy;
            *(float *)(p + 0x24) = (z * ty) + (s * x);
            *(float *)(p + 0x28) = (z * tx) + (s * y);
            *(float *)(p + 0x2C) = (z * ty) - (s * x);
            zz = z * z;
            *(float *)(p + 0x30) = c + t * zz;
        } else {
            *(float *)(p + 0x10) = 1.0f;
            *(float *)(p + 0x14) = 0.0f;
            *(float *)(p + 0x18) = 0.0f;
            *(float *)(p + 0x1C) = 0.0f;
            *(float *)(p + 0x20) = 1.0f;
            *(float *)(p + 0x24) = 0.0f;
            *(float *)(p + 0x28) = 0.0f;
            *(float *)(p + 0x2C) = 0.0f;
            *(float *)(p + 0x30) = 1.0f;
        }
    }
    {
        register unsigned char *entry = lbl_804B4168;
        register s32 j = 0;
        for (; j < *(s32 *)(lbl_804B4168 + 0x180); entry += 0x18, ++j) {
            Dummy_80292698 *obj = *(Dummy_80292698 **)(entry + 0x10);
            obj->v2();
        }
    }
}

extern "C" void fn_80292864(void) {
    /* Call virtual method 3 on the object stored in each 0x18-byte entry of the global object list. */
    class Dummy_80292864 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
    };
    register unsigned char *entry;
    register s32 i;
    entry = lbl_804B4168;
    i = 0;
    for (; i < *(s32 *)(lbl_804B4168 + 0x180); entry += 0x18, i++) {
        Dummy_80292864 *obj = *(Dummy_80292864 **)(entry + 0x10);
        obj->m3();
    }
}
#pragma scheduling on
#pragma cplusplus reset

/* The names the chunk system code hands the allocator, and the error it prints
 * for an unknown type (lbl_80349170; fn_802928D4 picks one per chunk type). */
typedef struct ChunkSysNames {
    char car[0x10];      /* "car chunk sys" */
    char ter[0x10];      /* "ter chunk sys" */
    char wood[0x10];     /* "wood chunk sys" */
    char invalid[0x20];  /* "chunk: invalid chunk type %d" */
} ChunkSysNames;

/* A chunk effect object, an nw4r::ef::Effect: the "car", "ter" and "wood" chunk
 * systems fn_802928D4 allocates.  Its chunk models -- "<model_base>1.mod" ..
 * "<model_base>8.mod" -- are loaded by fn_80293374 (car), loadTerrainChunkModels (ter) and
 * loadWoodChunkModels (wood); the chunk records start just after, at +0x2C, and their
 * count is the s32 at the end of the object (+0x2FAC car, +0x4C2C ter,
 * +0x222C wood). */
typedef struct ChunkSys {
    void *vtable;     /* +0x00 the effect's vtable (lbl_80349294/78/5C) */
    float gravity_f;  /* +0x04 gravity scale, the "grav_f" effect argument */
    s32 models[8];    /* +0x08 handle of model i, -1 when the game has none */
    s32 modelCount;   /* +0x28 how many of the eight models were found */
} ChunkSys;

/* One row of the chunk-system cache (lbl_804B4168), as fn_80292EC0 walks it,
 * fn_80292F40 fills it and fn_80292FB4 releases it. */
typedef struct ChunkCacheEntry {
    char name[0x10];  /* +0x00 the name it was requested under (fn_802929F8) */
    void *system;     /* +0x10 the ChunkSys fn_802928D4 built for it */
    s32 refCount;     /* +0x14 how many hold it; 0 frees it (fn_80292B48) */
} ChunkCacheEntry;

/* The cache: CHUNK_CACHE_SLOTS rows, then the number in use at +0x180
 * (fn_80292EA8/fn_80292EB4 clear it, fn_802924E8/fn_8029261C build and drop it). */
#define CHUNK_CACHE_SLOTS 16
typedef struct ChunkCache {
    ChunkCacheEntry entry[CHUNK_CACHE_SLOTS];  /* +0x00 */
    s32 count;                                 /* +0x180 */
} ChunkCache;

extern char lbl_80349170[];
extern void *fn_801284F8(int, const void *);
extern void *fn_80293034(void *, void *, int);
extern void *fn_80293A00(void *, void *, int, int, int);
extern void *fn_80294254(void *, void *, int, int, int);
#pragma cplusplus on
int fn_802928D4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    char *str = lbl_80349170;
    void *ptr;

    switch (arg1) {
    case 1:
        ptr = fn_801284F8(0x2FF0, str);
        if (ptr != 0) {
            return (int)fn_80293034(ptr, (void *)arg0, arg2);
        }
        break;
    case 2:
        ptr = fn_801284F8(0x4C30, str + 0x10);
        if (ptr != 0) {
            return (int)fn_80293A00(ptr, (void *)arg0, arg2, arg3, arg4);
        }
        break;
    case 3:
        ptr = fn_801284F8(0x2230, str + 0x20);
        if (ptr != 0) {
            return (int)fn_80294254(ptr, (void *)arg0, arg2, arg3, arg4);
        }
        break;
    default:
        Abend_Panic(str + 0x30);
        return 0;
    }
    return (int)ptr;
}
#pragma cplusplus reset
extern int fn_802928D4(int, int, int, int, int, int);
/* Creates a fresh chunk (no parent) of the requested type via the subsystem
 * dispatcher fn_802928D4, forwarding the data pointer and init parameters. */
void fn_802929D8(int chunkType, int chunkData, int initArg0, int initArg1) {
    fn_802928D4(0, chunkType, chunkData, initArg0, initArg1, chunkData);
}

#pragma cplusplus on
extern "C" int fn_80292EC0(void *, const char *, int *, int);
extern "C" int fn_80292DE8(const char *);
extern "C" void *fn_802AE414(void *);
extern "C" void fn_80292F40(void *, void *, const char *);
extern char lbl_8055C968;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_802929F8(const char *name, int unused) {
    class Object {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual const char *getName(const char *);
        virtual int getType(const char *, int);
        virtual void v5();
        virtual int getSize(const char *, int);
    };
    register char *strings = lbl_80349170;
    volatile int cacheIndex = -1;
    if (((int (*)(void *, const char *, int *))fn_80292EC0)(lbl_804B4168, name, (int *)&cacheIndex) != 0) {
        unsigned char *entry = lbl_804B4168 + cacheIndex * 0x18;
        int refCount = *(int *)(entry + 0x14);
        *(int *)(entry + 0x14) = refCount + 1;
        return *(int *)(entry + 0x10);
    }
    /* Looks up a named resource in the cache, or loads/registers it if missing. */
    Object *resource = (Object *)fn_802AE414((void *)name);
    if (resource == 0) {
        Abend_Panic(strings + 0x50, name);
    }
    const char *key = resource->getName(&lbl_8055C968);
    int resourceId = fn_80292DE8(key);
    int resourceType = (int)resource->getName(strings + 0x70);
    int resourceSize = resource->getSize(strings + 0x7C, 0);
    int resourceFlags = resource->getType(strings + 0x88, 0);
    int result = ((int (*)(int, int, int, int, int))fn_802928D4)((int)resource, resourceId, resourceType, resourceSize, resourceFlags);
    fn_80292F40(lbl_804B4168, (void *)result, name);
    return result;
}
#pragma cplusplus off
#pragma pop

#pragma cplusplus on
/* Release a cached resource from lbl_804B4168; when its refcount reaches zero, destroy it (vtable slot 2, arg 1). */
extern "C" void fn_80292B48(void *resource) {
    if (fn_80292FB4(lbl_804B4168, resource) != 0 && resource != 0) {
        ((Dummy_80292B48 *)resource)->f0(1);
    }
}
#pragma cplusplus off
extern float PSVECDotProduct(void *, void *);
extern float lbl_805644D8, lbl_805644E8;
extern double fabs(double);
extern double __fabs(double);
#pragma scheduling invalid_target
int fn_80292BA8(float *arg0, float *arg1, float *__restrict arg2, float *arg3) {
    float delta[3];
    float y = arg2[1];
    float x = arg2[0];
    float a0 = arg0[0];
    float t0 = a0 - x;
    float z = arg2[2];
    float t1;
    float t2;
    double absd;
    register float firstDot, secondDot;
    register float ay, az, nx, s1, k, abs2, s2;
    delta[0] = t0;
    t1 = arg0[1] - y;
    delta[1] = t1;
    t2 = arg0[2] - z;
    delta[2] = t2;
    firstDot = PSVECDotProduct(delta, arg3);
    if (firstDot < lbl_805644D8) {
        secondDot = PSVECDotProduct(arg1, arg3);
        absd = __fabs((double)secondDot);
        nx = arg3[0];
        s1 = -firstDot;
        ay = arg3[1];
        az = arg3[2];
        abs2 = (float)absd;
        k = lbl_805644E8;
        arg0[0] += nx * s1;
        arg0[1] += ay * s1;
        arg0[2] += az * s1;
        s2 = k * abs2 - secondDot;
        arg1[0] += nx * s2;
        arg1[1] += ay * s2;
        arg1[2] += az * s2;
        return 1;
    }
    return 0;
}
extern void *fn_802C6B44(void);
extern void MRModel_ReleaseResource(void *);
extern int fn_802C7888(void *, int);
extern char *ResourceEntry_GetName(int);
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
/* Enumerate the resource list and submit one 0x2C-byte record per entry: the
 * entry's name at +0, the caller's id at +0x10 and secondaryName at +0x14. */
void fn_80292CD8(void *unused, int recordId, unsigned char *secondaryName) {
    void *resourceList;
    char record[0x2C];
    char *entryName;
    char ch;
    int count;
    register char *secondaryDst;
    register int count2;
    char *nameDst;
    int indexOrId = recordId;
    int entryOffset = (int)secondaryName;
    resourceList = fn_802C6B44();
    memset(record, 0, 0x2C);
    secondaryDst = record + 0x14;
    count = 0x10;
    goto copy_secondary;
count_secondary:
    count -= 1;
    if (count > 0) goto copy_secondary;
    secondaryDst[-1] = 0;
    goto copied_secondary;
copy_secondary:
    ch = *(char *)entryOffset++;
    *secondaryDst++ = ch;
    if ((signed char)ch != 0) goto count_secondary;
copied_secondary:
    *(int *)(record + 0x10) = indexOrId;
    indexOrId = 0;
    entryOffset = 0;
    goto check_list;
copy_first:
    entryName = ResourceEntry_GetName(*(int *)((char *)resourceList + 4) + entryOffset);
    nameDst = record;
    count2 = 0x10;
    goto copy_entry;
count_entry:
    count2--;
    if (count2 > 0) goto copy_entry;
    nameDst[-1] = 0;
    goto copied_entry;
copy_entry:
    ch = *entryName++;
    *nameDst++ = ch;
    if ((signed char)ch != 0) goto count_entry;
copied_entry:
    fn_802C7888(record, 1);
    entryOffset += 0x10;
    indexOrId++;
check_list:
    if (indexOrId < *(int *)resourceList) goto copy_first;
    MRModel_ReleaseResource(resourceList);
}
#pragma scheduling on
/* One row of lbl_802FA998: a chunk type's name and the id the chunk system uses
 * for it (fn_802928D4 allocates the matching "car/ter/wood chunk sys" for it). */
struct ChunkType {
    const char *name;
    int id;
};

int fn_80292DE8(const char *typeName) {
    /* The three ChunkType rows of lbl_802FA998, copied off to our own frame. */
    int table[6];
    int *src = lbl_802FA998;
    int *dst = table;
    struct ChunkType *entry = (struct ChunkType *)table;
    unsigned int i = 0;

    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst = *src;
    do {
        if (strcmp(typeName, entry->name) == 0) {
            return *(int *)((char *)table + 4 + (i << 3)); /* table[i]'s id */
        }
        ++i;
        entry++;
    } while (i < 3);
    Abend_Panic(lbl_80349208, typeName); /* "chunk: invalid type '%s'" */
    return 0;
}

typedef unsigned char u8;
typedef signed char s8;
extern int fn_8002B1D8(const char *, const char *, int);
extern int strcmp(const char *, const char *);
extern int Abend_Panic(const char *, ...);
extern int lbl_802FA998[];
extern char lbl_80349208[];
void fn_80292EA8(void *cache) {
    /* Reset the chunk cache's in-use row count to zero. */
    ((ChunkCache *)cache)->count = 0;
}

void fn_80292EB4(void *cache) {
    /* Empty the chunk cache by resetting its in-use count to zero (see ChunkCache.count). */
    ((ChunkCache *)cache)->count = 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling off
/* Finds the cache row whose name matches `name` (case-insensitive, at most the
 * 15 characters a row holds), stores its index in *outIndex and returns 1;
 * returns 0 when the cache holds no such system. */
int fn_80292EC0(void *cache, const char *name, s32 *outIndex, s32 unused) {
    ChunkCacheEntry *entry;
    int i;
    entry = ((ChunkCache *)cache)->entry;
    i = 0;
    while (i < ((ChunkCache *)cache)->count) {
        if (fn_8002B1D8(name, entry->name, 15) == 0) { /* strnicmp */
            *outIndex = i;
            return 1;
        }
        entry++;
        i++;
    }
    return 0;
}
#pragma pop
/* Adds a named entry to a table: copies up to 16 bytes of the name into the
 * next 0x18-byte slot (count at offset 0x180), stores the associated pointer
 * and sets the slot flag to 1, then increments the count. */
void fn_80292F40(void *table, void *object, const char *name) {
    volatile s32 *countPtr = (volatile s32 *)((u8 *)table + 0x180);
    s32 slotIndex;
    s32 charsLeft;
    char *dst;
    unsigned char c;
    slotIndex = *countPtr;
    charsLeft = 0x10;
    dst = (char *)table + slotIndex * 0x18;
    goto copy_byte;
check_limit:
    if (--charsLeft > 0) {
        goto copy_byte;
    }
    dst[-1] = 0;
    goto after_copy;
copy_byte:
    c = (unsigned char)*name++;
    *dst++ = (char)c;
    if ((signed char)c != 0) {
        goto check_limit;
    }
after_copy:
    slotIndex = *countPtr;
    *(void **)((char *)table + slotIndex * 0x18 + 0x10) = object;
    slotIndex = *countPtr;
    *(s32 *)((char *)table + slotIndex * 0x18 + 0x14) = 1;
    slotIndex = *countPtr;
    *countPtr = slotIndex + 1;
}

int fn_80292FB4(unsigned char *bucket, void *system) {
    register unsigned char *entry;
    register int i;
    int count;
    int refCount;
    /* Decrement the refcount for a system in the bucket; returns 1 when it reaches 0, or panics if not found. */
    entry = bucket;
    i = 0;
    count = *(int *)(bucket + 0x180);
    for (; i < count; entry += 0x18, i++) {
        if (*(void **)(entry + 0x10) == system) {
            refCount = *(int *)(bucket + i * 0x18 + 0x14) - 1;
            *(int *)(bucket + i * 0x18 + 0x14) = refCount;
            return refCount == 0;
        }
    }
    Abend_Panic(lbl_80349224);
    return 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_80293034(void *effect, void *effectArg, int modelBase) {
    class EffectArg {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float value(const char *, float);
    };
    /* Construct an Effect: set its vtable, load chunk models and per-car colors, and take gravity from "grav_f" (default 1.0). */
    *(void **)effect = lbl_80349294;
    fn_80293374(effect, (void *)modelBase);
    fn_802935A0(effect);
    float initialValue = lbl_805644D4;
    *(float *)((char *)effect + 4) = initialValue;
    if (effectArg != 0) {
        *(float *)((char *)effect + 4) =
            ((EffectArg *)effectArg)->value((const char *)&lbl_8055C988, initialValue);
    }
    *(int *)((char *)effect + 0x2FAC) = 0;
    return effect;
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
extern float fn_801E7E24(void*);
extern void fn_802936C4(void*);
extern float lbl_80558DC4;
extern int setDrawListColor(int);
extern int setLightAmbientColor(int);
extern int MRModel_SetInstanceTransform(void*, void*);
extern int fn_80128668(void*);
extern void fn_80293530(void*);
extern void fn_80293374(void*, void*);
extern char lbl_80349250[];
extern void* fn_802935A0(void*);
extern float lbl_805644D4;
extern char lbl_80349224[];
extern int fn_802C6CF8(int);
extern u8 lbl_80349294[];
void *__dt__Q34nw4r2ef6EffectFv_802930BC(void *this, int shouldDelete) {
    /* Destructor for nw4r::ef::Effect: restore vtable, release owned resources, and optionally delete. */
    if (this) {
        *(void **)this = lbl_80349294;
        fn_80293530(this);
        if (shouldDelete > 0) fn_80128668(this);
    }
    return this;
}

void fn_8029311C(void *effect) {
    /* Empty a car chunk effect's records by zeroing its count at +0x2FAC (see ChunkSys). */
    *(s32 *)((u8 *)effect + 0x2fac) = 0;
}

#pragma push
#pragma small_data off
#pragma pop
__declspec(section ".data") extern float lbl_80558DC4;
/* Update this effect when the frame delta time is non-zero (above epsilon). */
void fn_80293128(void* effect) {
#define Frame_GetDeltaTime fn_801E7E24
#define Effect_Update      fn_802936C4
#define kFloatEpsilon      lbl_80558DC4
    float dt = Frame_GetDeltaTime(effect);
    float absDt = (float)__fabs((double)dt);
    if (!(absDt <= kFloatEpsilon)) Effect_Update(effect);
#undef kFloatEpsilon
#undef Effect_Update
#undef Frame_GetDeltaTime
}

#pragma use_lmw_stmw off
void fn_80293178(void *arg0, int unused) {
    /* Draw each entry using per-entry state/color parameters, restoring prior state. */
    register unsigned char *entryPtr;
    int savedState9950;
    int savedState9994;
    register int index;

    savedState9950 = setDrawListColor(0);
    savedState9994 = setLightAmbientColor(0);
    entryPtr = (unsigned char *)arg0 + 0x2C;
    index = 0;
    for (; index < *(int *)((char *)arg0 + 0x2FAC); entryPtr += 0x4C, index++) {
        setDrawListColor(*(int *)((char *)arg0 + (*(unsigned char *)(entryPtr + 0x4A) << 3) + 0x2FB0));
        setLightAmbientColor(*(int *)((char *)arg0 + (*(unsigned char *)(entryPtr + 0x4A) << 3) + 0x2FB4));
        MRModel_SetInstanceTransform(*(void **)((char *)arg0 + (*(unsigned char *)(entryPtr + 0x48) << 2) + 8), entryPtr);
    }
    setLightAmbientColor(savedState9994);
    setDrawListColor(savedState9950);
}

#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_80293230(void *arg0, float *arg1, float *arg2, short arg3, signed char arg4) {
    int count;
    int index;
    int offset;
    int mode;
    u8 *object;
    u8 *record;
    u8 *template;
    float x, y, z, a, b, c;
    unsigned int secondWord, firstWord;
    object = (u8 *)arg0;
    count = *(s32 *)(object + 0x2FAC);
    if (count >= 0xA0) return;
    if (*(s32 *)(object + 0x28) != 0) goto process;
    return;
process:
    record = (void *)(object); record = (void *)((char *)record + (s32)(count * 0x4C));
    index = fn_80129D18(0, 6);
    offset = index * 0x34;
    x = arg1[0];
    y = arg1[1];
    *(float *)(record + 0x50) = x;
    z = arg1[2];
    *(float *)(record + 0x54) = y;
    template = lbl_804B4030 + offset;
    a = arg2[0];
    *(float *)(record + 0x58) = z;
    arg1 = (float *)index;
    b = arg2[1];
    firstWord = *(unsigned int *)(template + 0x10);
    secondWord = *(unsigned int *)(template + 0x14);
    *(unsigned int *)(record + 0x2C) = firstWord;
    *(unsigned int *)(record + 0x30) = secondWord;
    *(unsigned int *)(record + 0x34) = *(unsigned int *)(template + 0x18);
    secondWord = *(unsigned int *)(template + 0x1C);
    firstWord = *(unsigned int *)(template + 0x20);
    *(unsigned int *)(record + 0x38) = secondWord;
    *(unsigned int *)(record + 0x3C) = firstWord;
    *(unsigned int *)(record + 0x40) = *(unsigned int *)(template + 0x24);
    firstWord = *(unsigned int *)(template + 0x28);
    secondWord = *(unsigned int *)(template + 0x2C);
    *(unsigned int *)(record + 0x44) = firstWord;
    *(unsigned int *)(record + 0x48) = secondWord;
    *(unsigned int *)(record + 0x4C) = *(unsigned int *)(template + 0x30);
    *(float *)(record + 0x5C) = a;
    *(float *)(record + 0x60) = b;
    c = arg2[2];
    *(float *)(record + 0x64) = c;
    *(float *)(record + 0x68) = lbl_805644D8;
    *(short *)(record + 0x6C) = arg3;
    mode = 3;
    if (fn_80287B5C(3, (void *)firstWord, c, b, a) != 0)
        mode = 2;
    *(int *)(record + 0x70) = mode;
    *(unsigned char *)(record + 0x74) = ((int (*)(int))fn_80287B5C)(*(int *)(object + 0x28));
    *(unsigned char *)(record + 0x75) = (unsigned char)arg1;
    *(unsigned char *)(record + 0x76) = (unsigned char)arg4;
    count = *(int *)(object + 0x2FAC);
    *(int *)(object + 0x2FAC) = count + 1;
}
#pragma use_lmw_stmw reset
#pragma optimize_for_size reset
/* Loads the car chunk effect's chunk models: the MODL resources
 * "<base>1.mod" .. "<base>8.mod" (lbl_80349250 is "%s%d.mod"), stopping at the
 * first name the resource system does not have, and leaving the slots no model
 * was found for at -1.  The car one takes no instance and remaps no texture;
 * loadTerrainChunkModels and loadWoodChunkModels do the "ter" and "wood" ones. */
void fn_80293374(void *object, void *modelBase) {
    char name[0x20];
    int count;
    ChunkSys *chunkSys = (ChunkSys *)object;
    chunkSys->modelCount = 0;
    goto check;
loop:
    ((void (*)(void *, int, const char *, ...))fn_801345D8)(name, 0x20, lbl_80349250, (int)modelBase, chunkSys->modelCount + 1);
    if (fn_8012C33C(name) == 0)  /* no such resource: the list of models ends here */
        goto padding;
    chunkSys->models[chunkSys->modelCount] = fn_802C6FC0(name, 0, 0);
    count = chunkSys->modelCount;
    count++;
    chunkSys->modelCount = count;
check:
    if (chunkSys->modelCount < 8)
        goto loop;
padding:
    {
        s32 *models = (s32 *)chunkSys;  /* models[2 + i] is model handle i */
        count = chunkSys->modelCount;
        for (; count < 8; count++)
            models[count + 2] = -1;
    }
}

#pragma push
#pragma scheduling invalid_target
/* Releases each loaded model handle in the object's model array (count at +0x28, handles starting at +0x08, stepped by 4) and marks each slot as -1. */
void fn_80293530(void* arg0) {
    u8 *entry = (u8*)arg0;
    s32 index = 0;
    while (index < *(s32*)((u8*)arg0 + 0x28)) {
        fn_802C6CF8(*(s32*)(entry + 8));
        *(s32*)(entry + 8) = -1;
        entry += 4;
        index++;
    }
}

#pragma scheduling invalid_target
void *fn_802935A0(void *arg0) {
    register u8 *out = (u8 *)arg0;
    register unsigned int *table = lbl_80488648;
    float scale = lbl_805644EC;
    unsigned int color;
    unsigned int checkValue;
    unsigned int count = 0;
    s32 tmp;
    s32 comp;
    s32 red;
    s32 green;
    unsigned int packed;
    void *item;
    goto check_loop;
body:
    if (count < 8U) item = (void *)*table;
    else item = 0;
    color = *(unsigned int *)((u8 *)item + 0x3EC);
    comp = 0xFF;
    tmp = (s32)(scale * (float)(u8)color);
    if (tmp <= 0xFF) comp = tmp;
    red = comp & 0xFF;
    comp = 0xFF;
    tmp = (s32)(scale * (float)(u8)(color >> 8));
    if (tmp <= 0xFF) comp = tmp;
    green = (comp & 0xFF) << 8;
    comp = 0xFF;
    tmp = (s32)(scale * (float)(u8)(color >> 16));
    if (tmp <= 0xFF) comp = tmp;
    packed = ((comp & 0xFF) << 16) | 0xFF000000;
    packed = green | packed;
    packed = red | packed;
    *(unsigned int *)(out + 0x2FB0) = packed;
    *(unsigned int *)(out + 0x2FB4) = color;
    table++;
    count++;
    out += 8;
check_loop:
    if (count < 8U) checkValue = *table;
    else checkValue = 0;
    if (checkValue != 0) goto body;
    return out;
}
#pragma scheduling on
void fn_802936C4(void *arg0) {
    struct Rec {
        unsigned int copy[9];
        float x, y, z;
        float vx, vy, vz;
        float age;
        short idx;
        unsigned char pad0[2];
        s32 mode;
        unsigned char b48;
        unsigned char type;
        unsigned char b4a;
        unsigned char pad1;
    };
    struct Tpl { unsigned int copy[9]; };
    extern void fn_801E9DD4(void *, void *, float, float);
    extern void fn_801E9DD8(void);
    extern int fn_80292BA8(float *, float *, float *, float *);
    extern float lbl_805644D4;
    extern float lbl_805644D8;
    extern float lbl_805644F8;
    extern float lbl_80564500;
    extern float lbl_805644FC;
    extern float lbl_80564504;
    extern float lbl_80564508;
    extern void *lbl_8055C958;
    extern unsigned char lbl_804B4030[];
    extern void *lbl_8055C964;
    register float smallF;
    float two;
    register float dt2;
    float oneF;
    float gravF;
    float outer;
    float dt;
    float scale2;
    register float ageDt;
    register float zeroF;
    float scale;
    float gravTerm;
    struct Rec *cur;
    struct Rec *out;
    long iter;
    struct Tpl *src;
    unsigned kept;
    int mode;
    unsigned char type;
    float tmp[9];
    float par[3];
    short entry;
    s32 zeroI;
    unsigned r0;
    dt = fn_801E7E24(arg0);
    scale = lbl_805644F8 * dt;
    scale2 = lbl_805644D4 - scale;
    fn_801E9DD4(lbl_8055C958, lbl_8055C964, scale, lbl_805644F8);
    scale = scale2;
    zeroF = lbl_805644D8;
    oneF = lbl_805644D4;
    gravF = lbl_80564500;
    smallF = lbl_80564508;
    two = lbl_80564504;
    dt2 = lbl_805644F8;
    outer = lbl_805644FC;
    cur = (struct Rec *)((unsigned char *)arg0 + 0x2C);
    out = cur;
    iter = 0;
    kept = 0;
    goto check_loop;
body:
    {
        register float age;
        age = cur->age;
        if (age < zeroF) goto next;
        if (age >= outer) goto next;
do_work:
        ageDt = age + dt;
        mode = cur->mode;
        type = cur->type;
        entry = cur->idx;
        gravTerm = (gravF * dt) * *(float *)((unsigned char *)arg0 + 4);
        tmp[0] = cur->vx * scale;
        tmp[2] = cur->vz * scale;
        tmp[1] = cur->vy * scale;
        tmp[1] = tmp[1] - gravTerm;
        ((unsigned int *)tmp)[3] = ((unsigned int *)cur)[9];
        par[0] = zeroF;
        ((unsigned int *)tmp)[4] = ((unsigned int *)cur)[10];
        ((unsigned int *)tmp)[5] = ((unsigned int *)cur)[11];
        par[1] = oneF;
        par[2] = zeroF;
        if (mode == 2) {
            tmp[3] = tmp[3] + tmp[0] * dt;
            tmp[4] = tmp[4] + tmp[1] * dt;
            tmp[5] = tmp[5] + tmp[2] * dt;
            ((unsigned int *)tmp)[0] = ((unsigned int *)tmp)[3];
            ((unsigned int *)tmp)[1] = ((unsigned int *)tmp)[4];
            ((unsigned int *)tmp)[2] = ((unsigned int *)tmp)[5];
            zeroI = 0;
            if (fn_801E9E78(&entry, tmp, (unsigned)par, &zeroI) != 0) {
                if (fn_80292BA8(tmp + 3, tmp + 6, tmp, par) != 0) {
                    type = (unsigned char)((int (*)(int))fn_80287B5C)(6);
                    if (tmp[7] < dt2) {
                        ageDt = lbl_805644D8;
                        mode = 1;
                    }
                }
            } else {
                mode = 3;
            }
            goto write_out;
        }
        if (mode == 3) {
            tmp[3] = tmp[3] + tmp[0] * dt;
            tmp[4] = tmp[4] + tmp[1] * dt;
            tmp[5] = tmp[5] + tmp[2] * dt;
            goto write_out;
        }
        if (ageDt < two) {
            if (ageDt > zeroF) tmp[4] = tmp[4] - smallF * dt;
            tmp[6] = zeroF;
            tmp[7] = zeroF;
            tmp[8] = zeroF;
        }
write_out:
        out->x = tmp[3];
        out->y = tmp[4];
        out->z = tmp[5];
        r0 = 0;
        if ((s32)mode == 2 || mode == 3) r0 = 1;
        if (r0)
            src = (struct Tpl *)((unsigned char *)lbl_804B4030 + type * 0x34 + 0x10);
        else
            src = (struct Tpl *)cur;
        kept += 1;
        {
            unsigned int a, b;
            b = src->copy[1];
            a = src->copy[0];
            out->copy[1] = b;
            out->copy[0] = (unsigned)a;
            a = src->copy[2];
            out->copy[2] = a;
            a = src->copy[3];
            b = src->copy[4];
            out->copy[3] = a;
            out->copy[4] = b;
            a = src->copy[5];
            out->copy[5] = a;
            a = src->copy[6];
            b = src->copy[7];
            out->copy[6] = a;
            out->copy[7] = b;
            a = src->copy[8];
            out->copy[8] = a;
        }
        out->vx = tmp[6];
        out->vy = tmp[7];
        out->vz = tmp[8];
        out->age = ageDt;
        out->idx = entry;
        out->mode = mode;
        out->b48 = cur->b48;
        out->type = type;
        out->b4a = cur->b4a;
        out += 1;
    }
next:
    cur += 1;
    iter += 1;
check_loop:
    if (iter < *(int *)((unsigned char *)arg0 + 0x2FAC)) goto body;
    *(int *)((unsigned char *)arg0 + 0x2FAC) = kept;
    fn_801E9DD8();
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_80293A00(void *object, void *effectArg, int modelBase, int instance, int remapTexture) {
    class EffectArg {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float value(const char *, float);
    };
    /* Construct the "ter" chunk sys: install its vtable, load its models, then set
     * its gravity_f (+0x4) to the default lbl_8056450C (2.1f), overridden by
     * effectArg->value("grav_f", default). +0x4C2C is cleared. */
    *(void **)object = lbl_80349278;
    loadTerrainChunkModels(object, modelBase, instance, remapTexture);
    float defaultGravity = lbl_8056450C;
    *(float *)((char *)object + 4) = defaultGravity;
    if (effectArg != 0) {
        *(float *)((char *)object + 4) =
            ((EffectArg *)effectArg)->value((const char *)&lbl_8055C988, defaultGravity);
    }
    *(int *)((char *)object + 0x4C2C) = 0;
    return object;
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
extern unsigned char lbl_80349278[];
extern float lbl_8056450C;
extern void loadTerrainChunkModels(void*, int, int, int);
extern void fn_80293EB0(void*);
void *__dt__Q34nw4r2ef6EffectFv_80293A88(void *this, int shouldDelete) {
    /* Destructor for nw4r::ef::Effect: restore vtable, release owned resources, and optionally delete. */
    if (this) {
        *(void **)this = lbl_80349278;
        fn_80293EB0(this);
        if (shouldDelete > 0) fn_80128668(this);
    }
    return this;
}

void fn_80293AE8(void *effect) {
    /* Empty a "ter" chunk effect's records by zeroing its count at +0x4C2C (see ChunkSys). */
    *(s32 *)((u8 *)effect + 0x4c2c) = 0;
}

extern void fn_80293F20(void*);
/* ChunkSys_ter_calc: the "ter" chunk effect's calc virtual, slot +0x10 of its
 * vtable lbl_80349278.  Advances the terrain-debris chunks one frame, but only
 * when time actually passed: every chunk is moved by the frame time, so with
 * the frame time at zero the update would just rewrite every record in place. */
void fn_80293AF4(ChunkSys *effect) {
#define Frame_getFrameTime fn_801E7E24 /* fw::Frame::getFrameTime(): this frame's
                                        * delta time, clamped by fn_801E7E48; the
                                        * getter itself takes no argument */
#define FRAME_EPSILON lbl_80558DC4     /* 0x34000000, 2^-23: a span at or below
                                        * this is taken for no time at all */
#define ChunkSys_ter_update fn_80293F20 /* integrates every chunk record of the
                                         * "ter" system (count at +0x4C2C) */
    float frameTime = Frame_getFrameTime((void *)effect);
    float absTime = (float)__fabs((double)frameTime);
    if (!(absTime <= FRAME_EPSILON)) ChunkSys_ter_update((void *)effect);
#undef Frame_getFrameTime
#undef FRAME_EPSILON
#undef ChunkSys_ter_update
}

void fn_80293B44(void *arg0) {
    /* For each active terrain-effect record, dispatch it with MRModel_SetInstanceTransform
     * using the per-record slot byte to select the base object pointer. */
    u8 *record = (u8 *)arg0 + 0x2C;
    s32 i = 0;
    goto check;
body:
    MRModel_SetInstanceTransform(*(void **)((u8 *)arg0 + (*(u8 *)(record + 0x48) * 4) + 8), record);
    record += 0x4C;
    i++;
check:
    if (i < *(s32 *)((u8 *)arg0 + 0x4C2C)) goto body;
}

typedef struct { unsigned int first, second; } Pair_80293BB4;
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_80293BB4(void *effect, const float *position, const float *velocity, short entry) {
    /* Spawn a terrain-debris chunk in the "ter" ChunkSys effect: pick a random
     * velocity/state template from lbl_804B4030, copy it into the next free record
     * (stride 0x4C), then fill in the position, initial velocity, age, mode and
     * metadata from the arguments and advance the record count at +0x4C2C. */
    int chunkCount;
    int templateIndex;
    int templateOffset;
    int initialMode, rngSlot;
    u8 *effectBytes;
    u8 *chunk;
    u8 *tpl;
    float px, py, pz, vz, vy, vx;
    unsigned int secondWord, firstWord;
    effectBytes = (u8 *)effect;
    chunkCount = *(s32 *)(effectBytes + 0x4C2C);
    if (chunkCount >= 0x100) return;
    chunk = effectBytes + chunkCount * 0x4C;
    templateIndex = fn_80129D18(0, 6);
    templateOffset = templateIndex * 0x34;
    px = position[0];
    py = position[1];
    pz = position[2];
    *(float *)(chunk + 0x50) = px;
    *(float *)(chunk + 0x54) = py;
    tpl = (u8 *)lbl_804B4030 + templateOffset;
    vz = velocity[2];
    vy = velocity[1];
    vx = velocity[0];
    *(float *)(chunk + 0x58) = pz;
    position = (const float *)templateIndex;
    firstWord = *(unsigned int *)(tpl + 0x10);
    initialMode = 2;
    secondWord = *(unsigned int *)(tpl + 0x14);
    rngSlot = 0;
    *(Pair_80293BB4 *)(chunk + 0x2C) = *(Pair_80293BB4 *)(tpl + 0x10);
    *(unsigned int *)(chunk + 0x34) = *(unsigned int *)(tpl + 0x18);
    *(Pair_80293BB4 *)(chunk + 0x38) = *(Pair_80293BB4 *)(tpl + 0x1C);
    *(unsigned int *)(chunk + 0x40) = *(unsigned int *)(tpl + 0x24);
    *(Pair_80293BB4 *)(chunk + 0x44) = *(Pair_80293BB4 *)(tpl + 0x28);
    *(unsigned int *)(chunk + 0x4C) = *(unsigned int *)(tpl + 0x30);
    *(float *)(chunk + 0x5C) = vx;
    *(float *)(chunk + 0x60) = vy;
    *(float *)(chunk + 0x64) = vz;
    *(float *)(chunk + 0x68) = 0.0f;
    *(short *)(chunk + 0x6C) = entry;
    *(unsigned int *)(chunk + 0x70) = initialMode;
    *(u8 *)(chunk + 0x74) = fn_80129D18(rngSlot, *(s32 *)(effectBytes + 0x28));
    *(u8 *)(chunk + 0x75) = (u8)position;
    chunkCount = *(s32 *)(effectBytes + 0x4C2C);
    *(s32 *)(effectBytes + 0x4C2C) = chunkCount + 1;
}
#pragma use_lmw_stmw reset
#pragma optimize_for_size reset
extern int fn_8012C33C(void *);
extern void fn_801345D8(void *, int, const char *, int, int);
extern void fn_80292CD8(void *, int, u8 *);
extern int fn_802C6FC0(void *, int, int);
extern char lbl_80349250[];
/* Loads the terrain chunk effect's chunk models.  The profile gives a base name
 * and its models are the MODL resources "<base>1.mod" .. "<base>8.mod"
 * (lbl_80349250 is "%s%d.mod"): every one the resource system has is
 * instantiated for `instance` -- its textures remapped first when the profile
 * names a texture to remap -- and the handle is stored in the object's model
 * table, the slots no model was found for left at -1.  fn_80293374 and
 * loadWoodChunkModels do the same for the "car" and "wood" chunk systems.
 * modelBase and remapTexture are the profile's "model_base" and
 * "remap_texture" strings, handed over as ints by the file's prototype. */
/* Load the terrain chunk effect's chunk models, remapping textures when the profile requests it and leaving missing slots at -1. */ void loadTerrainChunkModels(void *object, int modelBase, int instance, int remapTexture) {
    char name[0x20];
    int count;
    ChunkSys *chunkSys = (ChunkSys *)object;
    chunkSys->modelCount = 0;
    goto check;
loop:
    ((void (*)(void *, int, const char *, ...))fn_801345D8)(name, 0x20, lbl_80349250, modelBase, chunkSys->modelCount + 1);
    if (fn_8012C33C(name) == 0)  /* no such resource: the list of models ends here */
        goto padding;
    if (remapTexture != 0 && *(s8 *)remapTexture != 0)
        fn_80292CD8(name, instance, (u8 *)remapTexture);
    chunkSys->models[chunkSys->modelCount] = fn_802C6FC0(name, instance, 0);
    count = chunkSys->modelCount;
    count++;
    chunkSys->modelCount = count;
check:
    if (chunkSys->modelCount < 8)
        goto loop;
padding:
    {
        s32 *models = (s32 *)chunkSys;  /* models[2 + i] is model handle i */
        count = chunkSys->modelCount;
        for (; count < 8; count++)
            models[count + 2] = -1;
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80293EB0(void* arg0) {
    /* Releases every loaded model handle in the object's model table,
       setting each slot back to -1. */
    u8 *cursor = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x28)) {
        fn_802C6CF8(*(s32*)(cursor + 8));
        *(s32*)(cursor + 8) = -1;
        cursor += 4;
        i++;
    }
}

void fn_80293F20(void *arg0) {
    struct Rec {
        unsigned int copy[9];
        float x, y, z;
        float vx, vy, vz;
        float age;
        short idx;
        unsigned char pad0[2];
        int mode;
        unsigned char b48;
        unsigned char type;
        unsigned char b4a;
        unsigned char pad1;
    };
    struct Tpl { unsigned int copy[9]; };
    extern void fn_801E9DD4(void *, void *, float, float);
    extern void fn_801E9DD8(void);
    extern int fn_80292BA8(float *, float *, float *, float *);
    extern float lbl_805644D4;
    extern float lbl_805644D8;
    extern float lbl_805644F8;
    extern float lbl_805644FC;
    extern float lbl_80564500;
    extern float lbl_80564504;
    extern float lbl_80564508;
    extern void *lbl_8055C958;
    extern void *lbl_8055C964;
    extern unsigned char lbl_804B4030[];
    float smallF;
    float two;
    float dt2;
    float oneF;
    float gravF;
    register float outer;
    float dt;
    float scale2;
    float ageDt;
    float zeroF;
    float scale;
    float gravTerm;
    struct Rec *cur;
    struct Rec *out;
    struct Tpl *src;
    register int iter;
    register int kept;
    long mode;
    unsigned char type;
    float par[3];
    float tmp[13];
    short entry;
    int zeroI;
    long r0;
    dt = fn_801E7E24(arg0);
    scale = lbl_805644F8 * dt;
    scale2 = lbl_805644D4 - scale;
    fn_801E9DD4(lbl_8055C958, lbl_8055C964, scale, lbl_805644F8);
    scale = scale2;
    zeroF = lbl_805644D8;
    oneF = lbl_805644D4;
    gravF = lbl_80564500;
    smallF = lbl_80564508;
    dt2 = lbl_805644F8;
    two = lbl_80564504;
    outer = lbl_805644FC;
    cur = (struct Rec *)((unsigned char *)arg0 + 0x2C);
    out = cur;
    iter = 0;
    kept = 0;
    goto check_loop;
body:
    {
        float age;
        age = cur->age;
        if (age < zeroF) goto next;
        if (age >= outer) goto next;
do_work:
        ageDt = age + dt;
        mode = cur->mode;
        type = cur->type;
        gravTerm = (gravF * dt) * *(float *)((unsigned char *)arg0 + 4);
        entry = cur->idx;
        tmp[0] = cur->vx * scale;
        tmp[2] = cur->vz * scale;
        tmp[1] = cur->vy * scale;
        tmp[1] = tmp[1] - gravTerm;
        tmp[6] = tmp[0];
        tmp[7] = tmp[1];
        tmp[8] = tmp[2];
        ((unsigned int *)tmp)[3] = ((unsigned int *)cur)[9];
        ((unsigned int *)tmp)[4] = ((unsigned int *)cur)[10];
        par[0] = zeroF;
        ((unsigned int *)tmp)[5] = ((unsigned int *)cur)[11];
        par[1] = oneF;
        par[2] = zeroF;
        if (mode == 2) {
            tmp[9] = tmp[0] * dt;
            tmp[10] = tmp[6] * dt;
            tmp[3] = tmp[3] + tmp[9];
            tmp[11] = tmp[8] * dt;
            tmp[4] = tmp[4] + tmp[10];
            tmp[5] = tmp[5] + tmp[11];
            zeroI = 0;
            if (fn_801E9E78(&entry, tmp + 3, par, &zeroI, gravF * dt) != 0) {
                if (fn_80292BA8(tmp + 3, tmp + 6, (float *)((unsigned int *)cur), par) != 0) {
                    type = (unsigned char)((int (*)(int))fn_80287B5C)(6);
                    if (tmp[7] < dt2) {
                        ageDt = zeroF;
                        mode = 1;
                    }
                }
            } else {
                mode = 3;
            }
            goto write_out;
        }
        if (mode == 3) {
            tmp[3] = tmp[3] + tmp[0] * dt;
            tmp[4] = tmp[4] + tmp[6] * dt;
            tmp[5] = tmp[5] + tmp[8] * dt;
            goto write_out;
        }
        if (ageDt < two) {
            if (ageDt > zeroF) tmp[4] = tmp[4] - smallF * dt;
            tmp[6] = zeroF;
            tmp[7] = zeroF;
            tmp[8] = zeroF;
        }
write_out:
        out->x = tmp[3];
        out->y = tmp[4];
        out->z = tmp[5];
        r0 = 0;
        if (mode == 2) r0 = 1;
        if (mode == 3) r0 = 1;
        if (r0)
            src = (struct Tpl *)((unsigned char *)lbl_804B4030 + type * 0x34 + 0x10);
        else
            src = (struct Tpl *)cur;
        kept++;
        {
            unsigned int a, b;
            a = src->copy[0];
            b = src->copy[1];
            out->copy[1] = b;
            out->copy[0] = a;
            a = src->copy[2];
            out->copy[2] = (unsigned)a;
            b = src->copy[4];
            a = src->copy[3];
            out->copy[4] = b;
            out->copy[3] = a;
            a = src->copy[5];
            out->copy[5] = a;
            a = src->copy[6];
            b = src->copy[7];
            out->copy[6] = a;
            out->copy[7] = b;
            a = src->copy[8];
            out->copy[8] = a;
        }
        out->vx = tmp[6];
        out->vy = tmp[7];
        out->vz = tmp[8];
        out->age = ageDt;
        out->idx = entry;
        out->mode = mode;
        out->b48 = cur->b48;
        out->type = type;
        ++out;
    }
next:
    ++cur;
    iter++;
check_loop:
    if (iter < *(int *)((unsigned char *)arg0 + 0x4C2C)) goto body;
    *(int *)((unsigned char *)arg0 + 0x4C2C) = kept;
    fn_801E9DD8();
}

#pragma cplusplus on
extern "C" void *fn_80294254(void *object, void *effectArg, int modelBase, int instance, int remapTexture) {
    class EffectArg {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float value(const char *, float);
    };
    /* Construct the "wood" chunk sys: install its vtable, load its models, then set
     * its gravity_f (+0x4) to the default lbl_805644D4 (1.0f), overridden by
     * effectArg->value("grav_f", default). +0x222C is cleared. */
    register float defaultGravity;
    *(void **)object = lbl_8034925C;
    loadWoodChunkModels(object, modelBase, instance, remapTexture);
    defaultGravity = lbl_805644D4;
    *(float *)((char *)object + 4) = defaultGravity;
    if (effectArg != 0) {
        *(float *)((char *)object + 4) =
            ((EffectArg *)effectArg)->value((const char *)&lbl_8055C988, defaultGravity);
    }
    *(int *)((char *)object + 0x222C) = 0;
    return object;
}
#pragma cplusplus off

#pragma pop

extern unsigned char lbl_8034925C[];
extern void fn_80294710(void *);
/* Destructor for nw4r::ef::Effect: resets vtable, tears down resources, and conditionally frees memory. */
void *__dt__Q34nw4r2ef6EffectFv_802942DC(void *arg0, int arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_8034925C;
        fn_80294710(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

/* Clear the nw4r effect's active-record count (field at offset 0x222C) to zero. */
void fn_8029433C(void *effect) {
    *(s32 *)((u8 *)effect + 0x222C) = 0;
}

extern void fn_80294780(void*);
/**
 * @brief nw4r::ef::Effect::calc(): advance this effect's particles one frame.
 *
 * Every particle is moved by the frame time, so when no time has passed - the
 * frame time sitting at zero within the game's float epsilon lbl_80558DC4
 * (0x34000000, 2^-23) - the update is skipped and the effect keeps its place.
 */
void fn_80294348(void* effect) {
    float frameTime = fn_801E7E24(effect); /* fw::Frame::getFrameTime(); the
                                            * getter takes no argument */
    float absTime = (float)__fabs((double)frameTime);
    if (!(absTime <= lbl_80558DC4)) fn_80294780(effect);
}

#pragma scheduling invalid_target
void fn_80294398(void *arg0) {
    /* For each active record, dispatch it with MRModel_SetInstanceTransform using the per-record slot byte
     * to select the base object pointer from the container. */
    u8 *record = (u8 *)arg0 + 0x2C;
    s32 index = 0;
    goto check;
body:
    MRModel_SetInstanceTransform(*(void **)((u8 *)arg0 + (*(u8 *)(record + 0x40) * 4) + 8), record);
    record += 0x44;
    index++;
check:
    if (index < *(s32 *)((u8 *)arg0 + 0x222C)) goto body;
}
#pragma scheduling on
extern int fn_80287B5C(int, void *, float, float, float);
void fn_80294408(void *arg0, const float *arg1, const float *arg2) {
    int count;
    int offset;
    register int index;
    register u8 *object;
    register float *first;
    register const float *second;
    register u8 *record;
    register u8 *template;
    float x, y, z, a, b, c;
    object = (u8 *)arg0;
    first = (float *)arg1;
    second = arg2;
    count = *(s32 *)(object + 0x222C);
    if (count >= 0x80) return;
    if (*(s32 *)(object + 0x28) != 0) {
    record = object + count * 0x44;
    index = fn_80129D18(0, 6);
    offset = index * 0x34;
    x = first[0];
    y = first[1];
    *(float *)(record + 0x50) = x;
    z = first[2];
    *(float *)(record + 0x54) = y;
    template = lbl_804B4030 + offset;
    a = second[0];
    *(float *)(record + 0x58) = z;
    first = (float *)index;
    b = second[1];
    *(Pair_80293BB4 *)(record + 0x2C) = *(Pair_80293BB4 *)(template + 0x10);
    *(unsigned int *)(record + 0x34) = *(unsigned int *)(template + 0x18);
    *(Pair_80293BB4 *)(record + 0x38) = *(Pair_80293BB4 *)(template + 0x1C);
    *(unsigned int *)(record + 0x40) = *(unsigned int *)(template + 0x24);
    *(Pair_80293BB4 *)(record + 0x44) = *(Pair_80293BB4 *)(template + 0x28);
    *(unsigned int *)(record + 0x4C) = *(unsigned int *)(template + 0x30);
    *(float *)(record + 0x5C) = a;
    *(float *)(record + 0x60) = b;
    c = second[2];
    *(float *)(record + 0x64) = c;
    *(float *)(record + 0x68) = lbl_805644D8;
    *(unsigned char *)(record + 0x6C) = fn_80287B5C(*(int *)(object + 0x28), template, c, b, a);
    *(unsigned char *)(record + 0x6D) = (unsigned char)first;
    count = *(int *)(object + 0x222C);
    *(int *)(object + 0x222C) = count + 1;
    }
}
#pragma scheduling on

/* Loads the chunk system's chunk models.  The profile gives a base name, and
 * its models are the MODL resources "<base>1.mod" .. "<base>8.mod": every one
 * the resource system has is instantiated for `instance` -- its textures
 * remapped first when the profile names a texture to remap -- and the handle
 * is stored in the object's model table.  The slots no model was found for are
 * left at -1.
 *
 * The "wood chunk sys"; fn_80293374 and loadTerrainChunkModels do the same for the "car"
 * and "ter" ones.  modelBase and remapTexture are the strings the profile's
 * "model_base" and "remap_texture" entries give, handed over as ints by the
 * file's prototype. */
void loadWoodChunkModels(void *object, int modelBase, int instance, int remapTexture) {
    char name[0x20];
    int count;
    ChunkSys *chunkSys = (ChunkSys *)object;
    chunkSys->modelCount = 0;
    goto check;
loop:
    ((void (*)(void *, int, const char *, ...))fn_801345D8)(name, 0x20, lbl_80349250, modelBase, chunkSys->modelCount + 1);
    if (fn_8012C33C(name) == 0)  /* no such resource: the list of models ends here */
        goto padding;
    if (remapTexture != 0 && *(s8 *)remapTexture != 0)
        fn_80292CD8(name, instance, (u8 *)remapTexture);
    chunkSys->models[chunkSys->modelCount] = fn_802C6FC0(name, instance, 0);
    count = chunkSys->modelCount;
    count++;
    chunkSys->modelCount = count;
check:
    if (chunkSys->modelCount < 8)
        goto loop;
padding:
    {
        s32 *models = (s32 *)chunkSys;  /* models[2 + i] is model handle i */
        count = chunkSys->modelCount;
        for (; count < 8; count++)
            models[count + 2] = -1;
    }
}

#pragma push
#pragma scheduling invalid_target
/* Releases every loaded model handle in the object's model table, setting each
 * slot back to -1. */
void fn_80294710(void *object) {
#define ModelTable_releaseHandle fn_802C6CF8
    u8 *cursor = (u8 *)object;
    s32 index = 0;

    while (index < *(s32 *)((u8 *)object + 0x28)) {
        ModelTable_releaseHandle(*(s32 *)(cursor + 8));
        *(s32 *)(cursor + 8) = -1;
        cursor += 4;
        index++;
    }
#undef ModelTable_releaseHandle
}
#pragma pop
extern float lbl_80564510, lbl_805644D4, lbl_80564500, lbl_805644FC, lbl_805644D8;
extern unsigned char lbl_804B4030[];
#pragma scheduling on
/* Steps active particles in an emitter: integrate velocity with drag and gravity, copy template data, age, and compact the live list. */
void fn_80294780(void *emitter)
{
  struct WordTriple
  {
    unsigned int x;
    unsigned int y;
    unsigned int z;
  };
  struct Particle
  {
    struct WordTriple copy[3];
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
    float age;
    unsigned char flag;
    unsigned char type;
    unsigned char pad[2];
  };
  struct ParticleTemplate
  {
    unsigned int pad[4];
    struct WordTriple copy[3];
  };
  struct 
  {
    float x;
    float y;
    float z;
  } velocity;
  register struct ParticleTemplate *templateData;
  register struct Particle *particle;
  register struct Particle *write;
  register int i;
  float dt = fn_801E7E24(emitter);
  float drag = 1.0f - (1.5f * dt);
  particle = (struct Particle *) (((unsigned char *) emitter) + 0x2C);
  write = particle;
  for (i = 0; i < (*((int *) (((unsigned char *) emitter) + 0x222C))); ++i, ++particle)
  {
    if (particle->age < 0.0f)
    {
      continue;
    }
    if (particle->age >= 5.0f)
    {
      continue;
    }
    velocity.x = particle->vx * drag;
    velocity.y = particle->vy * drag;
    velocity.z = particle->vz * drag;
    velocity.y -= (9.81f * dt) * (*((float *) (((unsigned char *) emitter) + 4)));
    write->x = particle->x + (velocity.x * dt);
    write->y = particle->y + (velocity.y * dt);
    write->z = particle->z + (velocity.z * dt);
    templateData = (struct ParticleTemplate *) (lbl_804B4030 + (particle->type * 0x34));
    write->copy[0] = templateData->copy[0];
    write->copy[1] = templateData->copy[1];
    write->copy[2] = templateData->copy[2];
    write->vx = velocity.x;
    write->vy = velocity.y;
    write->vz = velocity.z;
    write->age = particle->age + dt;
    write->flag = particle->flag;
    write->type = particle->type;
    ++write;
  }

  *((int *) (((unsigned char *) emitter) + 0x222C)) = (((int) write) - (((int) emitter) + 0x2C)) / 0x44;
}
