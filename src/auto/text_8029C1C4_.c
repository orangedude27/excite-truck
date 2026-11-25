__declspec(section ".data") extern float lbl_80558DC4;
extern void *DrawList_getCurrentMatrix(void);
extern void fn_802C8BD0(int);
extern int beginDrawListPass(int);
extern void fn_802C8E00(int, unsigned int, float, float, float, float, float);
extern void DrawList_endMeshPass(void);
extern void DrawList_RestoreNormalMode(void);
extern void fn_8029DB78(void *, void *, int, int);
typedef struct GridRecord_8029D644 {
    float f0;
    float f4;
    float f8;
    int fieldC;
    float f10;
    float f14;
} GridRecord_8029D644;
extern float PSQUATMultiply(float *, float *);
extern void *RegisterTextureByName(int, int);
extern float lbl_8056465C;
extern float lbl_80564628;
extern int lbl_804B5030[];
extern void fn_8029E8E0(float *, int);
extern void DrawModelInstance(int);
extern void fn_8029D644(void *);
extern float DrawList_distanceToCamera(void *);
extern void fn_8029D550(void *, float *, float *);
extern int fn_8029D4CC(void *);
extern int fn_8029EAE8(void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8029CD14(void);
extern void fn_8029CB3C(void);
extern void fn_8029C934(void);
extern void fn_8029C650(void);
extern void fn_8029C3EC(void);
extern void *fn_8029D464(void *, int);
extern int lbl_8055F7F8;
extern int lbl_8055F7F0;
extern int lbl_804B5010[];
extern int lbl_8055CAA8;
extern void fn_8028E398(void);
extern void fn_802C6CF8(void);
extern void fn_802CAC54(int);
extern void fn_80128670(int);
extern void fn_80128668(void *);
extern unsigned char lbl_80349780[];
extern float lbl_80564648;
extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450(void *, int);
extern float lbl_8056469C;
extern double lbl_80564680;
extern float fn_801E88F0(int);
extern float DrawList_squaredDistanceToCamera(void *);
extern int fn_802C9640(void *);

void fn_8029C1C4(void) {
    /* Reset per-frame water state, run water subsystem updates, and register the
       water callback if splashes or any pool/shallow-water entries are active. */
    lbl_8055F7FC = 0;
    fn_8029C570(); fn_8029C73C(); fn_8029C998(); fn_8029CBA0(); fn_8029C664();
    if (fn_802BF4F0() == 0 && lbl_8055F7F0 <= 0 && lbl_8055F7F4 <= 0) return;
    fn_80287B38(fn_8029C450);
}

/* Subsystem teardown step during game shutdown: release the cached water effect
 * (fn_8029CD14), the texture-pattern animation pointers (fn_8029CB3C), the 3D
 * water pools (fn_8029C934), then the remaining resource (fn_8029C650).
 * fn_8029C3EC is an empty placeholder. */
void fn_8029C22C(void) {
    fn_8029CD14();
    fn_8029CB3C();
    fn_8029C934();
    fn_8029C650();
    fn_8029C3EC();
}

#pragma push
#pragma scheduling invalid_target
/* Step every registered 3D water pool when the frame delta time is non-negligible (|dt| > epsilon). */ void WaterPool_StepAll(void) {
    int *poolSlot;
    int index;
    float frameTime = fn_801E7E24();
    if (!((float)__fabs((double)frameTime) <= lbl_80558DC4)) {
        poolSlot = (int *)&lbl_804B5010;
        for (index = 0; index < lbl_8055F7F0; index++) {
            fn_8029D574(*poolSlot);
            poolSlot++;
        }
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Selects the nearest valid candidate from the first object list (based on distance minus spread)
 * and notifies it, then runs an update callback on each active object in the second list. */
void fn_8029C2D4(void) {
    float position[3];
    float spread;
    float difference;
    float bestDifference;
    int *entry;
    void *bestObject;
    int i;

    if (lbl_8055CAA8 != -1)
        DrawModelInstance(lbl_8055CAA8);

    bestDifference = lbl_80564628;
    entry = lbl_804B5010;
    bestObject = 0;
    i = 0;
    while (i < *(volatile int *)&lbl_8055F7F0) {
        void *object;
        object = (void *)*entry;
        if (fn_8029D4CC(object)) {
            fn_8029D550(object, position, &spread);
            difference = DrawList_distanceToCamera(position) - spread;
            if (bestObject == 0 || difference < bestDifference) {
                bestObject = object;
                bestDifference = difference;
            }
        }
        entry++;
        i++;
    }

    if (bestObject != 0)
        fn_8029D644(bestObject);

    {
        int j;
        entry = lbl_804B5030;
        j = 0;
        while (j < *(volatile int *)&lbl_8055F7F4) {
            if (fn_8029EAE8((void *)*entry))
                ((void (*)(void *))fn_8029E8E0)((void *)*entry);
            entry++;
            j++;
        }
    }
}
#pragma pop
/* Empty teardown placeholder: called last by the game-shutdown routine
 * fn_8029C22C after the remaining effects resources are released; does nothing. */
void fn_8029C3EC(void) {
}

extern void fn_8029EF24();
/* nw4r::ef::Effect destructor: restore this class's vtable (lbl_80349780), run base cleanup, and optionally free the object. */
void *__dt__Q34nw4r2ef6EffectFv_8029C3F0(void *effect, int deleteFlags) {
    if (effect) {
        *(void **)effect = (void *)lbl_80349780;
        fn_8029EF24(effect);
        if (deleteFlags > 0) fn_80128668(effect);
    }
    return effect;
}

/* One entry of the list of objects near the players: fn_8028874C fills these
   (object, its index in the object list, its scaled squared distance to the
   nearest player and whether it is still flagged), sorts them by distance and
   fn_802887EC hands the array and its count to every callback registered with
   fn_80287B38. */
typedef struct NearObject {
    void *object;          /* the object itself (4 0x3C-byte wheel entries at +0x70...) */
    int objectIndex;       /* its index in the object list */
    float distance;        /* squared distance to the nearest player, scaled */
    unsigned char flag;    /* set while the object counts as a player's vehicle */
} NearObject;

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Per-frame water callback: fn_8029C1C4 registers it with fn_80287B38 and
   fn_802887EC runs it over the sorted list of objects near the players
   (arg0 = the NearObject array, arg1 = its count).  Every object that is
   close enough (distance < 2500.0), moving fast enough (speed at +0x50 > 2.5)
   and still flagged is reported to each 3D water pool (lbl_804B5010,
   lbl_8055F7F0 of them) and to each shallow water area (lbl_804B5030,
   lbl_8055F7F4 of them); when the splash effect system is up (fn_802BF4F0)
   splash particles are also emitted from the object (fn_8029CD48).
   Nothing happens while the frame time is zero (game standing still). */
void fn_8029C450(void *arg0, int arg1) {
    extern float fn_801E7E24(void);
    extern void fn_8029D7D0(int, void **);
    extern void fn_8029EA34(void *, void **);
    extern void fn_8029CD48(void *);
    extern int fn_802BF4F0(void);
    extern int lbl_8055F7F0, lbl_8055F7F4;
    extern int lbl_804B5010[], lbl_804B5030[];
    extern float lbl_80558DC4, lbl_80564638, lbl_8056463C;
    float minSpeed;    /* lbl_8056463C = 2.5 */
    float frameTime;
    float maxDistance; /* lbl_80564638 = 2500.0 */
    NearObject *record;
    int numObjects;
    int pool;
    int shallow;

    maxDistance = lbl_80564638;
    frameTime = fn_801E7E24();
    if (!((float)__fabs((double)frameTime) <= lbl_80558DC4)) {  /* 1.19e-7 */
        minSpeed = lbl_8056463C;
        numObjects = 0;
        record = (NearObject *)arg0;
        while (numObjects < arg1) {
            if (record->distance < maxDistance &&
                *(float *)((char *)record->object + 0x50) > minSpeed &&
                record->flag != 0) {
                pool = 0;
                while (pool < lbl_8055F7F0) {
                    fn_8029D7D0(lbl_804B5010[pool], (void **)record);
                    pool++;
                }
                shallow = 0;
                while (shallow < lbl_8055F7F4) {
                    fn_8029EA34((void *)lbl_804B5030[shallow], (void **)record);
                    shallow++;
                }
                if (fn_802BF4F0() != 0) {
                    fn_8029CD48(record->object);
                }
            }
            record++;
            numObjects++;
        }
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8029C570(void) {
    extern char lbl_80349560[];
    extern int lbl_8055CAAC;
    extern int fn_8012C33C(void *);
    extern int fn_802C6FC0(void *, int, int);
    extern void **fn_802AE414(void *);
    extern void fn_802C8230(float), fn_802C8234(float);
    struct Dummy {
        virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
        virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
        virtual void p8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16();
        virtual float get(void *);
    };
    register float a = 2.0f;
    register float b = 0.025f;
    char *base = lbl_80349560;
    char *p = base + 0x70;
    char *q = base + 0x7C;
    int result;
    void *obj;
    /* Load the water config: open the resource at base+0x7C if present, look up
     * the interface at base+0x70 to read "period" and "amplitude" parameters
     * (defaults 2.0/0.025), then apply them. */
    if (fn_8012C33C(q)) result = fn_802C6FC0(q, 0, 0); else result = -1;
    lbl_8055CAA8 = result;
    obj = fn_802AE414(p);
    if (obj) {
        a = ((Dummy *)obj)->get(&lbl_8055CAAC);
        b = ((Dummy *)obj)->get(base + 0x18);
    }
    fn_802C8230(a); fn_802C8234(b);
}
#pragma pop

void fn_8029C650(void) {
    /* Release the current model's handle; -1 means no model is loaded. */
    int modelHandle = lbl_8055CAA8;
    if (modelHandle == -1) return;
    ((void (*)(int))fn_802C6CF8)(modelHandle);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma inline_depth(0)
void fn_8029C664(void) {
    extern void fn_8029D550(void *, float *, float *);
    extern float PSQUATMultiply(float *, float *);
    extern char lbl_803495E8[];
    extern void Abend_Panic(const char *, ...);
    float positionA[3], positionB[3], radiusA, radiusB;
    float minDistance;
    int *poolBase, *poolA, *poolB;
    int i, j;
    /* Warn if any two 3D water pools are closer together than the minimum
     * separation (250 units) based on their positions and radii. */
    minDistance = lbl_80564648;
    poolA = lbl_804B5010;
    poolBase = poolA;
    for (i = 0; i < lbl_8055F7F0; ++poolA, ++i) {
        fn_8029D550((void *)*poolA, positionA, &radiusA);
        j = i + 1;
        poolB = poolBase + j;
        for (; j < lbl_8055F7F0; ++poolB, ++j) {
            fn_8029D550((void *)*poolB, positionB, &radiusB);
            if (PSQUATMultiply(positionA, positionB) < radiusB + (minDistance + radiusA))
                Abend_Panic(lbl_803495E8);
        }
    }
}

#pragma cplusplus on
extern "C" void *fn_80131810(void *);
extern "C" void fn_80131818(void *);
extern "C" void *fn_801284F8(int, void *);
extern "C" void *fn_8029D148(void *, void *, float *, int);
extern "C" void *fn_8029E754(void *, void *, int);
extern "C" void Abend_Panic(const char *, ...);
extern "C" void *memset(void *, int, unsigned int);
#pragma cplusplus off

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
/* Builds the 3D water pools ("water iface"): opens the "water3d.val" parameter
   file and makes one 0x78-byte water pool per entry -- up to the eight the
   lbl_804B5010 list holds -- from the entry's origin/right/up rectangle, its
   texture index and the default simulation values below. */
void fn_8029C73C(void) {
    typedef struct { float x, y, z; } Vec;
    typedef struct { float x, y; } Vec2;
    /* the pool's rectangle: one corner and its two edge vectors */
    typedef struct { Vec origin; Vec2 right; Vec2 up; } PoolParams;
    /* a VALT parameter file: fn_80131810 opens one by name and fn_80131818
       closes it again; its entries are asked for until one comes back NULL */
    struct ValtFile { virtual void m08(); virtual void *getEntry(int i); };
    /* one entry of it, whose values are looked up by the key they are named with */
    struct ValtEntry {
        virtual void m08(); virtual void m0C(); virtual void m10(); virtual int getInt(void *key);
        virtual void m18(); virtual void m1C(); virtual void m20(); virtual void m24();
        virtual void m28(); virtual void m2C(); virtual void m30(); virtual Vec getVec3(void *key);
        virtual void m38(); virtual Vec2 getVec2(void *key);
    };
    /* the values every new pool starts with; fn_8029D148 copies them into it */
    struct PoolDefaults {
        float f00;                    /* +0x00  0.25 */
        float f04;                    /* +0x04  0 */
        float f08;                    /* +0x08  0 */
        float f0C;                    /* +0x0C  0.9875 */
        float f10;                    /* +0x10  0.05 */
        float f14;                    /* +0x14  0.05 */
        int texture;                  /* +0x18  -1: the entry's texture_name is used */
        unsigned char byte1C;         /* +0x1C  0x20 */
        unsigned char byte1D;         /* +0x1D  0xE4 */
        unsigned char pad1E[2];
    };
    extern char lbl_80349560[];       /* the module's strings, by the offsets below */
    extern int lbl_804B5010[];        /* the water pools */
    extern int lbl_8055F7F0;          /* how many pools there are */
    extern int lbl_8055CAB4, lbl_8055CABC, lbl_8055CAC4;   /* "origin", "right", "up" */
    extern float lbl_80564628, lbl_80564630, lbl_8056464C, lbl_80564650;
    PoolDefaults init;
    PoolParams params;
    char *base;
    ValtFile *valt;
    int i;

    base = lbl_80349560;
    lbl_8055F7F0 = 0;
    valt = (ValtFile *)fn_80131810(base + 0xA4);   /* "water3d.val" */
    if (valt != 0) {
        memset(&init, 0, 0x20);
        init.f00 = lbl_8056464C;
        init.f04 = lbl_80564628;
        init.f08 = lbl_80564628;
        init.f0C = lbl_80564650;
        init.f10 = lbl_80564630;
        init.f14 = lbl_80564630;
        init.texture = -1;
        init.byte1C = 0x20;
        init.byte1D = 0xE4;
        for (i = 0; valt->getEntry(i) != 0; i++) {
            ValtEntry *entry;
            int texture;
            void *pool;
            int idx;
            if (lbl_8055F7F0 >= 8)
                Abend_Panic(base + 0xB0, 8);      /* "water: exceeded pool limit (%d)" */
            entry = (ValtEntry *)valt->getEntry(i);
            texture = entry->getInt(base + 0xD0); /* "texture_name" */
            params.origin = entry->getVec3(&lbl_8055CAB4);
            params.right = entry->getVec2(&lbl_8055CABC);
            params.up = entry->getVec2(&lbl_8055CAC4);
            pool = fn_801284F8(0x78, base + 0xE0);    /* "water pool" */
            if (pool != 0)
                pool = fn_8029D148(pool, &init, (float *)&params, texture);
            idx = lbl_8055F7F0;
            lbl_804B5010[idx] = (int)pool;
            lbl_8055F7F0 = idx + 1;
        }
        fn_80131818(valt);
    }
}
#pragma pop

#pragma pop

void fn_8029C934(void) {
    /* Destroy and free every active 3D water pool object, then reset the pool count. */
    int *poolSlot = (int *)lbl_804B5010;
    int index = 0;
    while (index < lbl_8055F7F0) {
        fn_8029D464((void *)*poolSlot, 1);
        ++poolSlot;
        ++index;
    }
    lbl_8055F7F0 = 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
void fn_8029C998(void) {
    typedef struct { float x, y, z; } Vec;
    typedef struct { float x, y; } Vec2;
    /* the area's rectangle: one corner and its two edge vectors */
    typedef struct { Vec pos; Vec2 v1; Vec2 v2; } Params;
    /* a VALT parameter file: fn_80131810 opens one by name and fn_80131818
       closes it again; its entries are asked for until one comes back NULL */
    struct ValtFile { virtual void m08(); virtual void *getEntry(int i); };
    /* one entry of it, whose values are looked up by the key they are named with */
    struct ValtEntry {
        virtual void m08(); virtual void m0C(); virtual void m10(); virtual int getInt(void *key);
        virtual void m18(); virtual void m1C(); virtual void m20(); virtual void m24();
        virtual void m28(); virtual void m2C(); virtual void m30(); virtual Vec getVec3(void *key);
        virtual void m38(); virtual Vec2 getVec2(void *key);
    };
    extern char lbl_80349560[];       /* the module's strings, by the offsets below */
    extern int lbl_804B5030[];        /* the shallow water areas */
    extern int lbl_8055F7F4;          /* how many shallow water areas there are */
    extern int lbl_8055CAB4, lbl_8055CABC, lbl_8055CAC4;   /* "origin", "right", "up" */
    extern void *fn_80131810(void *); extern void fn_80131818(void *);
    extern void *fn_8029E754(void *, void *, int);
    extern void Abend_Panic(const char *, ...);
    Params params; int *dest; char *base; ValtFile *valt; int i; int idx;

    base = lbl_80349560; lbl_8055F7F4 = 0; valt = (ValtFile *)fn_80131810(base + 0xEC);
    if (valt != 0) {
        dest = lbl_804B5030;
        for (i = 0; valt->getEntry(i) != 0; i++) {
            ValtEntry *entry; int texture; void *area;
            if (lbl_8055F7F4 >= 16)
                Abend_Panic(base + 0xF8, 16);
            entry = (ValtEntry *)valt->getEntry(i); texture = entry->getInt(base + 0xD0);
            params.pos = entry->getVec3(&lbl_8055CAB4);
            params.v1 = entry->getVec2(&lbl_8055CABC);
            params.v2 = entry->getVec2(&lbl_8055CAC4);
            area = (void *)fn_801284F8(0x44, base + 0x11C);
            if (area != 0) area = fn_8029E754(area, &params, texture);
            idx = lbl_8055F7F4; dest[idx] = (int)area; lbl_8055F7F4 = idx + 1;
        }
        fn_80131818(valt);
    }
}
#pragma pop
extern void *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888(void *, int);
extern int lbl_804B5030[];
void fn_8029CB3C(void) {
    /* Destroy all stored texture-pattern animation pointer objects and clear the count. */
    int *objectSlot = (int *)lbl_804B5030;
    int index = 0;
    while (index < lbl_8055F7F4) {
        __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888((void *)*objectSlot, 1);
        ++objectSlot;
        ++index;
    }
    lbl_8055F7F4 = 0;
}

extern int fn_8028E2F8(void *, void *, void *, float, float, float, float);
extern void fn_8028E61C(int *);
extern int lbl_8055F7F0, lbl_8055F7F4, lbl_8055F7F8;
extern int lbl_8055CAC8, lbl_8055CAD0, lbl_8055CAD8;
extern float lbl_8056464C, lbl_80564654, lbl_80564658, lbl_8056465C, lbl_80564660;
#pragma push
#pragma small_data off
extern unsigned char lbl_8034968C[], lbl_80349698[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma small_data off
extern "C" void fn_8029CBA0(void) {
    extern void **fn_802AE414(void *);
    struct Dummy {
        virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3();
        virtual int *get(void *, int *);
        virtual void pad5(); virtual void pad6(); virtual void pad7();
        virtual float get2(void *, float);
    };
    union ScratchValue { float f; int i; };
    ScratchValue scratch[40];
    register float var_f31 = 0.75f;
    register int *var_r31 = (int *)&lbl_8034968C;
    Dummy *obj;
    obj = (Dummy *)fn_802AE414(&lbl_8055CAC8);
    if (obj != 0) {
        var_r31 = obj->get((void *)&lbl_80349698, var_r31);
        var_f31 = obj->get2(&lbl_8055CAD0, var_f31);
    }
    if (fn_802BF4F0() != 0 || lbl_8055F7F0 > 0 || lbl_8055F7F4 > 0) {
        register float zero, high, scale, low, far;
        register int two, five;
        register unsigned short size;
        fn_8028E61C((int *)&scratch[6]);
        zero = 1.0f;
        two = 2;
        high = 0.75f;
        size = 0x200;
        scale = 0.5f;
        low = 0.25f;
        five = 5;
        far = -1.0f;
        scratch[6].i = two;
        scratch[7].i = size;
        scratch[8].f = high;
        scratch[9].f = high;
        scratch[3].f = zero;
        scratch[4].f = zero;
        scratch[5].f = zero;
        scratch[10].f = zero;
        scratch[11].f = zero;
        scratch[12].f = zero;
        scratch[0].f = zero;
        scratch[1].f = zero;
        scratch[2].f = zero;
        scratch[13].f = zero;
        scratch[15].f = zero;
        scratch[14].f = zero;
        scratch[16].f = scale;
        scratch[18].f = high;
        scratch[19].f = scale;
        scratch[23].i = five;
        scratch[24].f = var_f31;
        scratch[27].f = high;
        scratch[26].f = low;
        scratch[29].f = zero;
        scratch[28].f = far;
        scratch[35].f = zero;
        scratch[33].f = zero;
        scratch[31].f = zero;
        scratch[37].f = zero;
        lbl_8055F7F8 = fn_8028E2F8((void *)&scratch[6], &lbl_8055CAD8, var_r31,
            low, scale, zero, high);
        return;
    }
    lbl_8055F7F8 = 0;
}
#pragma small_data on
#pragma cplusplus reset
#pragma pop
void fn_8029CD14(void) {
    /* Water subsystem shutdown: if the cached water effect is still allocated,
       destroy its emitter (fn_8028E398) and clear the handle. */
    if (lbl_8055F7F8 != 0) {
        ((void (*)(int))fn_8028E398)(lbl_8055F7F8);
        lbl_8055F7F8 = 0;
    }
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma ppc_psq_save off
#pragma use_lmw_stmw off
/* Emit splash particles from a nearby object's four water-contact points.  Each
 * local point is transformed into world space; points above the water surface
 * are skipped, and a jittered line of particles is emitted toward an offset
 * target, with the count scaling with horizontal distance from the origin. */
void fn_8029CD48(void *object) {
    extern double fn_8002F234(float); /* sqrt */
    extern float fn_80287BC8(float, float); /* random float in [min, max] */
    extern float fn_802BF590(void); /* water surface Y */
    extern void fn_8028E590(int, float *, float *, float); /* emit a splash particle */
    extern int lbl_8055F7F8; /* splash particle emitter handle */
    struct Vec3 { float x, y, z; } emitWorld, target, startJitter, endJitter;
    struct { float x, z; } originXZ;
    int particleCount;
    float *pose = (float *)object;
    unsigned char *obj = (unsigned char *)object;
    float *localPoint = (float *)((unsigned char *)object + 0x70);
    int pointIndex, particleIndex;
    for (pointIndex = 0; pointIndex < 4; pointIndex++, obj += 0x3c, localPoint = (float *)((unsigned char *)localPoint + 0x3c)) {
        float sideSign;
        if ((*(unsigned int *)(obj + 0x9c) & 8) != 0)
            continue;
        if (&emitWorld.x == localPoint) {
            float x, y, z;
            float m00, m10, m20, m01, m11, m21, m02, m12, m22;
            m10 = pose[3]; m11 = pose[4]; m12 = pose[5];
            m00 = pose[0]; m01 = pose[1]; m02 = pose[2];
            m20 = pose[6]; m21 = pose[7]; m22 = pose[8];
            x = localPoint[0]; y = localPoint[1]; z = localPoint[2];
            emitWorld.x = z * m20 + (x * m00 + y * m10);
            emitWorld.y = z * m21 + (x * m01 + y * m11);
            emitWorld.z = z * m22 + (x * m02 + y * m12);
        } else {
            float m00, m01, m02, m10, m11, m12, m20, m21, m22;
            m10 = pose[3]; m00 = pose[0]; m20 = pose[6];
            emitWorld.x = localPoint[2] * m20 + (localPoint[0] * m00 + localPoint[1] * m10);
            m11 = pose[4]; m01 = pose[1]; m21 = pose[7];
            emitWorld.y = localPoint[2] * m21 + (localPoint[0] * m01 + localPoint[1] * m11);
            m12 = pose[5]; m02 = pose[2]; m22 = pose[8];
            emitWorld.z = localPoint[2] * m22 + (localPoint[0] * m02 + localPoint[1] * m12);
        }
        emitWorld.x += pose[9];
        emitWorld.y += pose[10];
        emitWorld.z += pose[11];
        if (emitWorld.y > fn_802BF590())
            continue;
        emitWorld.y += 0.5f;
        if (localPoint[0] > 0.0f)
            sideSign = 1.0f;
        else
            sideSign = -1.0f;
        {
            float forwardOffset;
            float distSq;
            float originZ;
            float sideOffset = 0.2f + 0.1f * (pose[20] * sideSign);
            forwardOffset = 0.2f + 0.1f * pose[20];
            target.x = pose[13] + pose[0] * sideOffset;
            target.y = pose[14] + pose[1] * sideOffset;
            target.z = pose[15] + pose[2] * sideOffset;
            if (5.0f < forwardOffset)
                forwardOffset = 5.0f;
            originZ = pose[15];
            originXZ.x = pose[13];
            target.x += pose[3] * forwardOffset;
            target.y += pose[4] * forwardOffset;
            distSq = originXZ.x * originXZ.x + originZ * originZ;
            target.z += pose[5] * forwardOffset;
            originXZ.z = originZ;
            {
                float distance = fn_8002F234(distSq);
                if ((int)(0.25f * distance) < 6)
                    particleCount = 0.25f * distance;
                else
                    particleCount = 6;
                for (particleIndex = 0; particleIndex < particleCount; particleIndex++) {
                    float jitterStep;
                    startJitter = emitWorld;
                    startJitter.x += fn_80287BC8(-0.5f, 0.5f);
                    startJitter.z += fn_80287BC8(-0.5f, 0.5f);
                    startJitter.y = fn_802BF590();
                    jitterStep = 2.0f < 0.125f * distance ? 2.0f : 0.125f * distance;
                    endJitter = target;
                    endJitter.x += fn_80287BC8(-jitterStep, jitterStep);
                    endJitter.y = 2.0f * fn_80287BC8(0.0f, jitterStep);
                    endJitter.z += fn_80287BC8(-jitterStep, jitterStep);
                    if (localPoint[0] > 0.0f)
                        sideSign = 1.0f;
                    else
                        sideSign = -1.0f;
                    fn_8028E590(lbl_8055F7F8, &startJitter.x, &endJitter.x,
                        -sideSign * fn_80287BC8(0.0f, 3.1415927f));
                }
            }
        }
    }
}
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void *fn_8029D148(void *arg0, void *arg1, float *arg2, int arg3) {
#pragma opt_common_subs off
#pragma use_lmw_stmw off
    extern double fn_8002F234(float);
    extern void *fn_8012850C(int, const char *);
    extern void *memset(void *, int, unsigned int);
    extern void Abend_Panic(const char *, ...);
    extern float PSQUATMultiply(float *, float *);
    extern void *RegisterTextureByName(int, int);
    extern void fn_8014E740(float *, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
    extern char lbl_80349560[];
    extern float lbl_80564628, lbl_80564658, lbl_8056465C, lbl_80564678;
    int dimX, dimY, twice, initId, data, end;
    unsigned char flag0, flag1;
    float sqX0, sqX1, sqY0, sqY1, rootX, rootY, ySquared;
    float stepX, stepY;
    float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
    float init0, init1, rx;
    float a08, a0c, a10, a14, c28;
    float scratch[3];
    char *base = lbl_80349560;

    memset((char *)arg0 + 0x14, 0, 0x20);
    sqX0 = arg2[4];
    sqX1 = arg2[3];
    rootX = (float)fn_8002F234(sqX1 * sqX1 + sqX0 * sqX0);
    sqY0 = arg2[5];
    sqY1 = arg2[6];
    ySquared = sqY0 * sqY0 + sqY1 * sqY1;
    dimX = (int)(lbl_80564678 * rootX);
    *(int *)((char *)arg0 + 0xC) = dimX;
    rootY = (float)fn_8002F234(ySquared);
    dimY = (int)(lbl_80564678 * rootY);
    *(int *)((char *)arg0 + 0x10) = dimY;
    if (*(int *)((char *)arg0 + 0xC) < 3 ||
        *(int *)((char *)arg0 + 0x10) < 3 ||
        *(int *)((char *)arg0 + 0xC) * *(int *)((char *)arg0 + 0x10) > 0x200)
        Abend_Panic(base + 0x148, *(int *)((char *)arg0 + 0x10));
    *(void **)arg0 = fn_8012850C(*(int *)((char *)arg0 + 0x10) * (*(int *)((char *)arg0 + 0xC) * 2) * 2, base + 0x16C);
    memset(*(void **)arg0, 0, *(int *)((char *)arg0 + 0x10) * (*(int *)((char *)arg0 + 0xC) * 4));

    stepX = lbl_80564658 / (float)(*(int *)((char *)arg0 + 0xC) - 1);
    stepY = lbl_80564658 / (float)(*(int *)((char *)arg0 + 0x10) - 1);
    data = *(int *)arg0;
    end = data + *(int *)((char *)arg0 + 0xC) * *(int *)((char *)arg0 + 0x10) * 2;
    initId = *(int *)((char *)arg1 + 0x18);
    f10 = *(float *)((char *)arg2 + 4);
    f11 = *(float *)arg2;
    f8 = *(float *)((char *)arg2 + 8);
    rx = *(float *)((char *)arg2 + 0xC);
    f7 = rx;
    f2 = *(float *)((char *)arg2 + 0x10);
    f9 = *(float *)((char *)arg2 + 8);
    f5 = *(float *)((char *)arg2 + 0x14);
    f0 = *(float *)((char *)arg2 + 0x18);
    f6 = f7 * stepX;
    f7 = f2 * stepX;
    f4 = f5 * stepY;
    f3 = f0 * stepY;
    f1 = f2 + f0;
    f1 = lbl_8056465C * f1;
    f0 = f11 + (lbl_8056465C * (rx + f5));
    f8 = f9 + f1;
    init0 = *(float *)arg1;
    init1 = *(float *)((char *)arg1 + 4);
    a08 = *(float *)((char *)arg1 + 8);
    a0c = *(float *)((char *)arg1 + 0xC);
    a10 = *(float *)((char *)arg1 + 0x10);
    a14 = *(float *)((char *)arg1 + 0x14);
    c28 = lbl_80564628;
    flag0 = *((unsigned char *)arg1 + 0x1C);
    flag1 = *((unsigned char *)arg1 + 0x1D);
    *(int *)((char *)arg0 + 4) = data;
    *(int *)((char *)arg0 + 8) = end;
    *(int *)((char *)arg0 + 0x2C) = initId;
    *(float *)((char *)arg0 + 0x14) = init0;
    *(float *)((char *)arg0 + 0x18) = init1;
    *(float *)((char *)arg0 + 0x1C) = a08;
    *(float *)((char *)arg0 + 0x20) = a0c;
    *(float *)((char *)arg0 + 0x24) = a10;
    *(float *)((char *)arg0 + 0x28) = a14;
    *(unsigned char *)((char *)arg0 + 0x30) = flag0;
    *(unsigned char *)((char *)arg0 + 0x31) = flag1;
    *(int *)((char *)arg0 + 0x2C) = initId & 0xFFFFFF;
    *(float *)((char *)arg0 + 0x34) = c28;
    *(float *)((char *)arg0 + 0x38) = f11;
    *(float *)((char *)arg0 + 0x3C) = f10;
    *(float *)((char *)arg0 + 0x40) = f9;
    *(float *)((char *)arg0 + 0x44) = f6;
    *(float *)((char *)arg0 + 0x48) = f7;
    *(float *)((char *)arg0 + 0x4C) = f4;
    *(float *)((char *)arg0 + 0x50) = f3;
    *(float *)((char *)arg0 + 0x54) = f0;
    *(float *)((char *)arg0 + 0x58) = f10;
    *(float *)((char *)arg0 + 0x5C) = f8;
    *(float *)((char *)arg0 + 0x60) = PSQUATMultiply((float *)((char *)arg0 + 0x54), (float *)((char *)arg0 + 0x38));

    twice = *(int *)((char *)arg0 + 0xC) << 1;
    *(void **)((char *)arg0 + 0x70) = fn_8012850C(twice * 0x18, base + 0x178);
    *(void **)((char *)arg0 + 0x74) = RegisterTextureByName(arg3, 0);

    f12 = *(float *)((char *)arg2 + 0xC);
    f7 = lbl_8056465C;
    f11 = lbl_80564628;
    f10 = *(float *)((char *)arg2 + 0x10);
    f2 = f12 * f7;
    f1 = *(float *)arg2;
    f9 = *(float *)((char *)arg2 + 0x14);
    f6 = f1 + f2;
    f8 = *(float *)((char *)arg2 + 0x18);
    f3 = f10 * f7;
    f0 = *(float *)((char *)arg2 + 4);
    f5 = f11 * f7;
    f4 = *(float *)((char *)arg2 + 8) + f3;
    f1 = f6 + f9 * f7;
    f0 = f0 + f5;
    scratch[0] = f1;
    scratch[1] = f0 + f5;
    scratch[2] = f4 + f8 * f7;
    fn_8014E740(scratch, *(float *)((char *)arg0 + 0x60), f1, f4, f0, f5, f6, f7, f8, f9, f10, f11, f12, f11, f12);
    return arg0;
}
#pragma pop
void *fn_8029D464(void *self, int deleteSelf) {
    /* Release owned allocations/buffers held by self (+0x74 via fn_802CAC54, +0x70 and +0x00 via fn_80128670); if deleteSelf > 0 also free self. */
    if (self) {
        fn_802CAC54(*(int *)((char *)self + 0x74));
        fn_80128670(*(int *)((char *)self + 0x70));
        fn_80128670(*(int *)self);
        if (deleteSelf > 0) fn_80128668(self);
    }
    return self;
}

extern float fn_801E88F0(int);
extern float DrawList_squaredDistanceToCamera(void *);
extern int fn_802C9640(void *);
extern float lbl_80564648;
extern unsigned char lbl_80349780[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
int fn_8029D4CC(void *arg0) {
    register void *object = arg0;
    register float temp_f31;
    register float temp_f2;
    register float temp_f0;
    register float temp_f1;
    register int result;
    temp_f31 = fn_801E88F0(-1);
    temp_f31 = temp_f31 * temp_f31;
    temp_f2 = DrawList_squaredDistanceToCamera((char *)object + 0x54);
    temp_f2 = temp_f2 * temp_f31;
    temp_f0 = lbl_80564648;
    temp_f1 = *(float *)((char *)object + 0x60);
    result = 0;
    temp_f0 = temp_f0 + temp_f1;
    temp_f0 = temp_f0 * temp_f0;
    if (temp_f2 < temp_f0 &&
        fn_802C9640((void *)((unsigned int)object + 0x54)) != 0) {
        result = 1;
    }
    return result;
}
#pragma pop
/* Read an object's bounding sphere: its center (x/y/z at +0x54/+0x58/+0x5C)
 * into center and its radius (+0x60) into radius. */
void fn_8029D550(void *object, float *center, float *radius) {
    center[0] = *(float *)((char *)object + 0x54);
    center[1] = *(float *)((char *)object + 0x58);
    center[2] = *(float *)((char *)object + 0x5C);
    *radius = *(float *)((char *)object + 0x60);
}

extern int fn_80287B94(int, int);
extern void fn_8029DF64(void *, int, int, float);
extern void fn_8029DDB8(void *);
#pragma push
#pragma processor 750
void fn_8029D574(int arg0) {
    extern float fn_80287BC8(float, float);
    extern void fn_8029DF64(void *, int, int, float);
    float disturbance;
    int y;
    char *pool = (char *)arg0;
    /* Advance the water pool's disturbance timer and, when it crosses 1.0,
     * spawn a random ripple within the grid and step the simulation. */
    if (*(float *)(pool + 0x34) >= 1.0f - lbl_80558DC4) {
        float range = *(float *)(pool + 0x28);
        disturbance = fn_80287BC8(-range, range);
        y = fn_80287B94(1, *(int *)(pool + 0x10) - 2);
        fn_8029DF64(pool, fn_80287B94(1, *(int *)(pool + 0xC) - 2), y, disturbance);
        *(float *)(pool + 0x34) += *(float *)(pool + 0x24) - 1.0f;
    } else {
        *(float *)(pool + 0x34) += *(float *)(pool + 0x24);
    }
    fn_8029DDB8(pool);
}
#pragma pop
void fn_8029D644(void *arg0);
void fn_8029D644(void *arg0) {
    char *source;
    char *other;
    int offset;
    int i;
    int count;
    char *buffers[2];
    char **bufferTable;
    int mode;
    GridRecord_8029D644 *row;

    count = (*(int *)((char *)arg0 + 0x10) - 1) * (*(int *)((char *)arg0 + 0xC) * 2);
    {
        char *result = (char *)((void *(*)(int, int))DrawList_getCurrentMatrix)(
            *(int *)((char *)arg0 + 0x10) - 1, *(int *)((char *)arg0 + 0x10));
        *(float *)((char *)arg0 + 0x64) = *(float *)(result + 0x24);
        *(float *)((char *)arg0 + 0x68) = *(float *)(result + 0x28);
        *(float *)((char *)arg0 + 0x6C) = *(float *)(result + 0x2C);
    }
    fn_802C8BD0(*(int *)((char *)arg0 + 0x74));
    if (beginDrawListPass(count) != 0) {
        other = *(char **)((char *)arg0 + 0x70);
        buffers[0] = other;
        buffers[1] = other + *(int *)((char *)arg0 + 0xC) * 0x18;
        for (i = 0, offset = 0; i < *(int *)((char *)arg0 + 0xC); offset += 0x18, i++)
            fn_8029DB78(arg0, other + offset, i, 0);

        bufferTable = buffers;
        for (mode = 1; mode < *(int *)((char *)arg0 + 0x10); mode++) {
            source = bufferTable[mode & 1];
            other = bufferTable[1 - (mode & 1)];
            for (i = 0, offset = 0; i < *(int *)((char *)arg0 + 0xC); offset += 0x18, i++) {
                fn_8029DB78(arg0, (void *)((unsigned long)source + offset), i, mode);
                row = (GridRecord_8029D644 *)(other + offset);
                {
                    float f1 = *(float *)(other + offset);
                    unsigned int flag = (unsigned int)(i > 0);
                    float f5 = row->f14;
                    float f4 = row->f10;
                    float f2 = row->f4;
                    float f3 = row->f8;
                    int field = row->fieldC;
                    fn_802C8E00(field, flag, f1, f2, f3, f4, f5);
                }
                row = (GridRecord_8029D644 *)(source + offset);
                {
                    float f1 = row->f0;
                    unsigned int flag = (unsigned int)(i > 0);
                    float f5 = row->f14;
                    float f4 = row->f10;
                    float f2 = row->f4;
                    float f3 = row->f8;
                    int field = row->fieldC;
                    fn_802C8E00(field, flag, f1, f2, f3, f4, f5);
                }
            }
        }
        DrawList_endMeshPass();
    }
    DrawList_RestoreNormalMode();
}

extern void fn_8029E49C(int, void *, int);
extern void fn_8029E130(void *, float *, float *, float);
void fn_8029D7D0(int pool, void **__restrict nearRecord) {
    extern void fn_801EE0C8(int);
    extern void *fn_802C6C34(void);
    extern int lbl_80488648[];
    extern float lbl_80564688;
    /* For a vehicle inside this 3D water pool, emit wheel splashes and place an
       effect at its transformed position. */
    char *poolObj = (char *)pool;
    char **near = (char **)nearRecord;
    char *vehicle = near[0];
    float sp[3];
    float radius = *(float *)(poolObj + 0x60);
    float offsetZ = *(float *)(vehicle + 0x2C) - *(float *)(poolObj + 0x5C);
    float offsetX = *(float *)(vehicle + 0x24) - *(float *)(poolObj + 0x54);
    float radiusSq = radius * radius;
    float offsetZSq = offsetZ * offsetZ;
    float offsetXSq = offsetX * offsetX;
    float distSq = offsetXSq + offsetZSq;
    int wheelOffset, wheelIndex;
    unsigned objectIndex;
    float *pose;
    float *matrix;
    if (distSq > radiusSq)
        return;
    for (wheelIndex = 0, wheelOffset = 0; wheelIndex < 4; wheelIndex++, wheelOffset += 0x3C) {
        if ((*(int *)(near[0] + wheelOffset + 0x9C) & 8) == 0)
            fn_8029E49C(pool, near[0], wheelIndex);
    }
    objectIndex = *(unsigned *)(near + 1);
    fn_801EE0C8(objectIndex < 8 ? lbl_80488648[objectIndex] : 0);
    pose = (float *)fn_802C6C34();
    matrix = (float *)near[0];
    if (sp == pose + 8) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = matrix[3]; m11 = matrix[4]; m12 = matrix[5];
        m00 = matrix[0]; m01 = matrix[1]; m02 = matrix[2];
        m20 = matrix[6]; m21 = matrix[7]; m22 = matrix[8];
        x = pose[8]; y = pose[9]; z = pose[10];
        sp[0] = z * m20 + (x * m00 + y * m10);
        sp[1] = z * m21 + (x * m01 + y * m11);
        sp[2] = z * m22 + (x * m02 + y * m12);
    } else {
        float m00, m01, m02, m10, m11, m12, m20, m21, m22;
        m10 = matrix[3]; m00 = matrix[0]; m20 = matrix[6];
        sp[0] = pose[10] * m20 + (pose[8] * m00 + pose[9] * m10);
        m11 = matrix[4]; m01 = matrix[1]; m21 = matrix[7];
        sp[1] = pose[10] * m21 + (pose[8] * m01 + pose[9] * m11);
        m12 = matrix[5]; m02 = matrix[2]; m22 = matrix[8];
        sp[2] = pose[10] * m22 + (pose[8] * m02 + pose[9] * m12);
    }
    sp[0] += matrix[9];
    sp[1] += matrix[10];
    sp[2] += matrix[11];
    fn_8029E130((void *)pool, sp, (float *)(near[0] + 0x34), lbl_80564688 * pose[7]);
}

#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8029DA24(void *arg0, float *arg1, int x, int z) {
    extern float lbl_80564628, lbl_80564658, lbl_8056465C, lbl_8056468C;
    extern void PSVECNormalize(float *, float *);
    int width;

    if (x == 0)
        goto border;
    width = *(int *)((char *)arg0 + 0xC);
    if (x == width - 1)
        goto border;
    if (z == 0)
        goto border;
    if (z != *(int *)((char *)arg0 + 0x10) - 1)
        goto calculate;

border:
    {
        float y = lbl_80564658;
        float x0 = lbl_80564628;
        arg1[0] = x0;
        arg1[1] = y;
        arg1[2] = x0;
    }
    goto done;

calculate:
    {
        int row;
        int base;
        volatile short *heights;
        int north, east, south, west;
        float dx, dz, nx, nz;

        row = z * width;
        heights = *(short **) ((char *)arg0 + 4);
        base = x + row;
        north = heights[x + (z - 1) * width];
        east = heights[base + 1];
        south = heights[x + (z + 1) * width];
        west = heights[base - 1];
        dx = lbl_8056465C * (float)(north - south);
        dz = lbl_8056465C * (float)(east - west);
        nx = lbl_8056468C * dx;
        nz = lbl_8056468C * dz;
        arg1[0] = nx * *(float *)((char *)arg0 + 0x44) + nz * *(float *)((char *)arg0 + 0x4C);
        arg1[1] = (lbl_80564658 - nx * nx) + (lbl_80564658 - nz * nz);
        arg1[2] = nx * *(float *)((char *)arg0 + 0x48) + nz * *(float *)((char *)arg0 + 0x50);
        PSVECNormalize(arg1, arg1);
    }
done:
    ;
}

extern float PSVECDotProduct(float *, float *);
extern float lbl_80564690;
#pragma push
#pragma scheduling on
void fn_8029DB78(void *arg0, void *arg1, int x, int z) {
    extern double fn_8002F234(float);
    extern float lbl_80564658, lbl_8056465C, lbl_8056468C;
    extern void PSVECNormalize(float *, float *);
    char *p = (char *)arg0;
    float *out = (float *)arg1;
    float normal[3];
    float diff[3];
    float proj[3];
    short *heights = *(short **)(p + 4);
    float h = lbl_8056468C * (*(float *)(p + 0x14) * (float)heights[x + z * *(int *)(p + 0xC)]);
    float len, scale, ysq;
    int lo, hi;

    out[2] = *(float *)(p + 0x40) + (float)x * *(float *)(p + 0x48) + (float)z * *(float *)(p + 0x50);
    out[1] = *(float *)(p + 0x3C) + h;
    out[0] = *(float *)(p + 0x38) + (float)x * *(float *)(p + 0x44) + (float)z * *(float *)(p + 0x4C);
    fn_8029DA24(arg0, normal, x, z);
    diff[0] = out[0] - *(float *)(p + 0x64);
    diff[1] = out[1] - *(float *)(p + 0x68);
    diff[2] = out[2] - *(float *)(p + 0x6C);
    scale = lbl_80564690 * PSVECDotProduct(normal, diff);
    proj[0] = diff[0] + normal[0] * scale;
    proj[1] = diff[1] + normal[1] * scale;
    proj[2] = diff[2] + normal[2] * scale;
    PSVECNormalize(proj, proj);
    ysq = lbl_80564658 + proj[1];
    len = (float)fn_8002F234(ysq * ysq + (proj[0] * proj[0] + proj[2] * proj[2]));
    scale = lbl_8056465C / len;
    out[4] = lbl_8056465C + proj[0] * scale;
    out[5] = lbl_8056465C + proj[2] * scale;
    lo = *(unsigned char *)(p + 0x30);
    hi = *(unsigned char *)(p + 0x31);
    *(int *)(out + 3) = *(int *)(p + 0x2C) |
        ((lo + (int)((float)(hi - lo) * (lbl_80564658 - proj[1] * proj[1]))) << 24);
}
#pragma pop
extern float lbl_8056462C, lbl_80564634, lbl_80564640, lbl_80564658, lbl_80564694, lbl_80564698;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8029DDB8(void *arg0)
{
  short *new_var2;
  unsigned char *base = (unsigned char *) arg0;
  int rowPlus;
  int rowMinus;
  short *cell;
  short *src;
  short *dst;
  int width;
  int y;
  int x;
  int index;
  int indexPlus;
  int indexMinus;
  int neighbors;
  int lowClamp;
  int clamped;
  float scale;
  float coeff;
  float amp;
  float waveSquared;
  float wave;
  unsigned char *new_var;
  float center;
  float result;
  scale = lbl_80564634 * (*((float *) (base + 0x20)));
  center = lbl_8056462C + scale;
  amp = ((float (*)(float, float)) fn_801E7E24)(scale, lbl_80564634);
  y = 1;
  coeff = lbl_80564694 * (lbl_80564658 - (*((float *) (base + 0x1C))));
  amp = coeff * amp;
  new_var = base;
  waveSquared = amp * amp;
  wave = lbl_80564640 - (lbl_80564698 * waveSquared);
  while (y < ((*((int *) (new_var + 0x10))) - 1))
  {
    rowPlus = y + 1;
    rowMinus = y - 1;
    x = 1;
    while (x < ((width = *((int *) (new_var + 0xC))) - 1))
    {
      index = x + (y * width);
      indexPlus = x + (rowPlus * width);
      indexMinus = x + (rowMinus * width);
      new_var2 = *((short **) (new_var + 8));
      src = *((short **) (new_var + 4));
      dst = new_var2;
      cell = src + index;
      neighbors = ((cell[1] + cell[-1]) + src[indexPlus]) + src[indexMinus];
      result = wave * ((float) src[index]);
      result = result + (waveSquared * ((float) neighbors));
      result = result - ((float) dst[index]);
      result = center * result;
      lowClamp = -32768;
      if (((int) result) > (-32768))
      {
        lowClamp = (int) result;
      }
      clamped = 32767;
      if (lowClamp < 32767)
      {
        clamped = lowClamp;
      }
      dst[index] = (short) clamped;
      ++x;
    }

    ++y;
  }

  src = *((short **) (new_var + 4));
  dst = new_var2;
  *((short **) (new_var + 8)) = src;
  *((short **) (new_var + 4)) = dst;
}
#pragma pop

extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450(void *, int);
extern float lbl_8056469C;
#pragma scheduling invalid_target
void fn_8029DF64(void *arg0, int arg1, int arg2, float arg3) {
    int stride;
    short *data;
    int index;
    float val;
    int cvt;
    int out;
    int low = -32768;
    stride = *(int *)((char *)arg0 + 0xC);
    data = *(short **)((char *)arg0 + 4);
    index = arg1 + arg2 * stride;
    val = lbl_8056469C * arg3 + (float)data[index];
    cvt = (int)val;
    if (cvt > -32768) low = cvt;
    out = 32767;
    if (low < 32767) out = low;
    data[index] = out;
}
int fn_8029DFE0(void *arg0, void *arg1) {
    extern float lbl_805646A0, lbl_8056465C, lbl_80564634;
    struct Delta { float x, z; };
    volatile struct Delta delta;
    float x, z, u, v, upper;
    int result, inside, test;

    result = 0;
    x = *(float *)arg1 - *(float *)((char *)arg0 + 0x38);
    z = *(float *)((char *)arg1 + 8) - *(float *)((char *)arg0 + 0x40);
    u = z * *(float *)((char *)arg0 + 0x48) + x * *(float *)((char *)arg0 + 0x44);
    inside = 0;
    v = z * *(float *)((char *)arg0 + 0x50) + x * *(float *)((char *)arg0 + 0x4C);
    test = 0;
    upper = (float)*(int *)((char *)arg0 + 0xC) - lbl_805646A0;

    delta.x = x;
    delta.z = z;
    if (u >= lbl_8056465C - lbl_80558DC4 &&
        u <= upper + lbl_80558DC4)
        test = 1;
    if (test) {
        float upper2 = (float)*(int *)((char *)arg0 + 0x10) - lbl_805646A0;
        test = 0;
        if (v >= lbl_8056465C - lbl_80558DC4 &&
            v <= upper2 + lbl_80558DC4)
            test = 1;
        if (test) inside = 1;
    }
    if (inside &&
        *(float *)((char *)arg1 + 4) <
            *(float *)((char *)arg0 + 0x3C) - lbl_80564634)
        result = 1;
    return result;
}
void fn_8029E130(void *arg0, float *pos, float *vel, float radius) {
 extern double fn_8002F234(float);
 extern float fn_80287BC8(float,float);
 extern void fn_8028E584(int,float *,float *);
 extern float lbl_80564628,lbl_80564634,lbl_80564640,lbl_8056464C,lbl_80564658,lbl_8056465C,lbl_8056466C,lbl_80564670,lbl_80564698,lbl_805646A4;
 float origin[3], outpos[3], outvel[3], delta[2], direction[2], hit[2], perpendicular[2];
 float factor, cap, lift;
 float height, reach, length, inv, scale, x, z, spread, vertical;
 int ix, iz, count, i;
 char *obj = arg0;
 float posY = pos[1];
 height = *(float *)(obj+0x3c);
 if (posY-radius > height-lbl_80564634) return;
 {
   float vx = vel[0];
   float vz = vel[2];
   float magnitude = vx * vx + vz * vz;
   delta[1] = pos[2] - *(float *)(obj + 0x40);
   delta[0] = pos[0] - *(float *)(obj + 0x38);
   direction[0] = vx;
   direction[1] = vz;
   if ((float)__fabs(magnitude) <= lbl_80558DC4) return;
 }
 x=pos[1]-height;
 reach=fn_8002F234(radius*radius-x*x);
 length=fn_8002F234(direction[0]*direction[0]+direction[1]*direction[1]);
 inv=lbl_80564658/length;
 scale=reach*inv;
 hit[0]=delta[0]+direction[0]*scale;
 hit[1]=delta[1]+direction[1]*scale;
 x=hit[0]**(float *)(obj+0x44)+hit[1]**(float *)(obj+0x48);
 ix=(int)(x<lbl_80564628 ? x-lbl_8056465C : lbl_8056465C+x);
 z=hit[0]**(float *)(obj+0x4c)+hit[1]**(float *)(obj+0x50);
 iz=(int)(z<lbl_80564628 ? z-lbl_8056465C : lbl_8056465C+z);
 if (ix < 1) return;
 if (ix >= *(int *)(obj+0xc)-1) return;
 if (iz < 1) return;
 if (iz < *(int *)(obj+0x10)-1) {
 (*(short **)(obj+4))[ix+iz**(int *)(obj+0xc)]=-32768;
 perpendicular[0]=direction[1]*inv;
 perpendicular[1]=direction[0]*inv;
 x=lbl_80564670*length;
 origin[2]=*(float *)(obj+0x40)+hit[1];
 origin[1]=lbl_8056464C+*(float *)(obj+0x3c);
 origin[0]=*(float *)(obj+0x38)+hit[0];
 spread=lbl_80564640 < x ? lbl_80564640 : x;
 count=(int)(lbl_8056464C*length)<10 ? (int)(lbl_8056464C*length):10;
 vertical=lbl_80564634*length;
 factor=lbl_80564698; cap=lbl_805646A4; lift=lbl_80564640;
 for(i=0;i<count;i++) {
   z=origin[2]+perpendicular[1]*fn_80287BC8(lbl_8056466C,lbl_8056465C);
   x=perpendicular[0]*fn_80287BC8(lbl_8056466C,lbl_8056465C);
   outpos[1]=origin[1]; outpos[2]=z; outpos[0]=origin[0]+x;
   z=direction[1]+perpendicular[1]*(factor*fn_80287BC8(-spread,spread));
   x=cap<vertical?cap:vertical;
   x=x+lift*fn_80287BC8(lbl_80564628,spread);
   scale=factor*fn_80287BC8(-spread,spread);
   outvel[1]=x; outvel[2]=z; outvel[0]=direction[0]+perpendicular[0]*scale;
   fn_8028E584(lbl_8055F7F8,outpos,outvel);
 }
 }
}
extern float fn_80287BC8(float, float);
extern void fn_8028E590(int, float *, float *, float);
extern int fn_8029DFE0();
extern float lbl_80564628;
extern float lbl_80564634;
extern float lbl_80564658;
extern float lbl_8056465C;
extern float lbl_80564660;
extern float lbl_80564664;
extern float lbl_80564668;
extern float lbl_80564674;
void fn_8029E49C(int unused, void *arg1, int arg2) {
    struct Locals { float sp8, spC, sp10, sp14, sp18, sp1C; } s;
    float *f = (float *)arg1;
    float *wheel = (float *)((char *)arg1 + arg2 * 0x3C);
    float *m = wheel + 0x1C;
    float temp_f1, temp_f2, temp_f3, temp_f0_2;
    float var_f1, var_f31, var_f5;
    if ((unsigned char *)&s.sp14 == (unsigned char *)m) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = f[3]; m11 = f[4]; m12 = f[5];
        m00 = f[0]; m01 = f[1]; m02 = f[2];
        m20 = f[6]; m21 = f[7]; m22 = f[8];
        x = m[0]; y = m[1]; z = m[2];
        s.sp14 = z * m20 + (x * m00 + y * m10);
        s.sp18 = z * m21 + (x * m01 + y * m11);
        s.sp1C = z * m22 + (x * m02 + y * m12);
    } else {
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = f[3]; m00 = f[0]; m20 = f[6];
        s.sp14 = m[2] * m20 + (m[0] * m00 + m[1] * m10);
        m11 = f[4]; m01 = f[1]; m21 = f[7];
        s.sp18 = m[2] * m21 + (m[0] * m01 + m[1] * m11);
        m12 = f[5]; m02 = f[2]; m22 = f[8];
        s.sp1C = m[2] * m22 + (m[0] * m02 + m[1] * m12);
    }
    temp_f2 = s.sp18; temp_f1 = s.sp1C;
    s.sp14 += f[9];
    s.sp18 = temp_f2 + f[10];
    s.sp1C = temp_f1 + f[11];
    if (fn_8029DFE0((void *)unused, &s.sp14)) {
        s.sp18 += lbl_8056465C;
        if (*(float *)m > lbl_80564628) var_f1 = lbl_80564658; else var_f1 = lbl_80564660;
        var_f5 = lbl_80564668;
        temp_f3 = lbl_80564664 + lbl_80564634 * (f[20] * var_f1);
        s.sp8 = f[13] + f[0] * temp_f3;
        s.spC = f[14] + f[1] * temp_f3;
        s.sp10 = f[15] + f[2] * temp_f3;
        temp_f0_2 = lbl_80564664 + lbl_80564634 * f[20];
        var_f5 = var_f5 < temp_f0_2 ? var_f5 : temp_f0_2;
        s.sp8 += f[3] * var_f5;
        s.spC += f[4] * var_f5;
        s.sp10 += f[5] * var_f5;
        if (*(float *)m > lbl_80564628) var_f31 = lbl_80564658; else var_f31 = lbl_80564660;
        fn_8028E590(lbl_8055F7F8, &s.sp14, &s.sp8, -var_f31 * fn_80287BC8(lbl_80564628, lbl_80564674));
    }
}

void *fn_8029E754(void *arg0, void *arg1, int arg2) {
    float *out;
    float *in;
    float u[3];
    float v[3];
    float q[3];
    float x, y, z;
    float a, b, c, d, e, f;
    float qx, qy, qz;
    float half;
    float scale;
    out = (float *)arg0;
    in = (float *)arg1;
    x = in[0];
    y = in[1];
    z = in[2];
    half = lbl_80564628;
    scale = lbl_8056465C;
    u[0] = in[3];
    u[1] = lbl_80564628;
    u[2] = in[4];
    v[0] = in[5];
    v[1] = lbl_80564628;
    v[2] = in[6];
    a = x + u[0];
    b = y + u[1];
    c = z + u[2];
    d = b + v[1];
    e = a + v[0];
    f = c + v[2];
    qx = scale * (d - y);
    qy = scale * (e - x);
    qz = scale * (f - z);
    out[0] = x;
    out[1] = y;
    out[2] = z;
    out[3] = a;
    out[4] = b;
    out[5] = c;
    out[6] = x + v[0];
    out[7] = y + v[1];
    out[8] = z + v[2];
    out[9] = e;
    out[10] = d;
    out[11] = f;
    q[0] = x + qy;
    q[1] = y + qx;
    q[2] = z + qz;
    out[12] = q[0];
    out[13] = q[1];
    out[14] = q[2];
    out[15] = PSQUATMultiply(out, out + 12);
    ((int *)arg0)[16] = (int)RegisterTextureByName(arg2, 0);
    return arg0;
}
void *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888(void *self, int shouldDelete) {
    /* Destroys a J2DAnmTexPatternTIMGPointer instance and optionally deletes it. */
    if (self != 0) {
        fn_802CAC54(*(int *)((char *)self + 0x40));
        if (shouldDelete > 0)
            fn_80128668(self);
    }
    return self;
}

extern void *DrawList_getCurrentMatrix(void);
extern void fn_802C8BD0(int);
extern int beginDrawListPass(int);
extern void DrawList_endMeshPass(void);
extern void DrawList_RestoreNormalMode(void);
extern void fn_802C8E00(int, unsigned int, float, float, float, float, float);
extern float lbl_80564658, lbl_8056465C;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8029E8E0(float *arg0, int arg1) {
    extern void PSVECNormalize(float *, float *);
    extern double fn_8002F234(float);
    struct Vec3 { float x, y, z; };
    struct ReverseVec3 { float z, y, x; };
    struct ReverseVec3 center;
    struct Vec3 diff;
    struct Vec3 sp8;
    float f31, f30, radius, norm;
    float cx, cy, cz;
    int i;
    int a, b;
    fn_802C8BD0(*(int *)((char *)arg0 + 0x40));
    if (beginDrawListPass(4) != 0) {
        struct ReverseVec3 *view;
        view = (struct ReverseVec3 *)((char *)DrawList_getCurrentMatrix() + 0x24);
        center = *view;
        f30 = lbl_80564658;
        i = 0;
        cz = center.z;
        cy = center.y;
        cx = center.x;
        f31 = lbl_8056465C;
        do {
            diff.y = arg0[1] - cy;
            diff.x = arg0[0] - cz;
            diff.z = arg0[2] - cx;
            sp8.x = diff.x;
            sp8.y = -diff.y;
            sp8.z = diff.z;
            PSVECNormalize((float *)&sp8, (float *)&sp8);
            {
                float z2 = sp8.z * sp8.z;
                float x2 = sp8.x * sp8.x;
                float y = f30 + sp8.y;
                float len2 = x2 + z2;
                radius = y * y + len2;
                norm = (float)fn_8002F234(radius);
                norm = f31 / norm;
                a = (i ^ 1) >> 1;
                b = (i ^ 1) & i;
                {
                    float az = f31 + sp8.z * norm;
                    float ax = f31 + sp8.x * norm;
                    fn_802C8E00(-1, (unsigned int)(a - b) >> 31, arg0[0], arg0[1], arg0[2], ax, az);
                }
            }
            i++;
            arg0 += 3;
        } while ((unsigned int)i < 4);
        DrawList_endMeshPass();
    }
    DrawList_RestoreNormalMode();
}
#pragma pop
extern void fn_8029EC64(void *, void *, int);
extern float lbl_805646A8;
#pragma scheduling on
void fn_8029EA34(void *area, void **__restrict targetRef) {
    /* If target (*targetRef) is within area's XZ radius, test each of its 4
     * 0x3C-byte entries (flag at +0x9C, bit 3 clear) against area via fn_8029EC64. */
    void *target = *targetRef;
    float radius, areaX, targetX, areaZ, targetZ, radiusSq, dz, dx, dzSq, dxSq, distSq;
    int offset, index;

    radius = *(float *)((char *)area + 0x3C);
    targetZ = *(float *)((char *)target + 0x2C);
    areaZ = *(float *)((char *)area + 0x38);
    radiusSq = radius * radius;
    targetX = *(float *)((char *)target + 0x24);
    areaX = *(float *)((char *)area + 0x30);
    dz = targetZ - areaZ;
    dx = targetX - areaX;
    dzSq = dz * dz;
    dxSq = dx * dx;
    distSq = dxSq + dzSq;
    if (!(distSq > radiusSq)) {
        index = 0;
        offset = 0;
        do {
            void *base = *targetRef;
            if (!(*(unsigned int *)((char *)base + offset + 0x9C) & 8))
                ((void (*)(void *, void *, int))fn_8029EC64)(area, base, index);
            index++;
            offset += 0x3C;
        } while (index < 4);
    }
}
#pragma scheduling on
/* Returns nonzero when this object's world position is within 150 units of the
 * reference point and passes the view-volume test at its stored tolerance. */
int fn_8029EAE8(void *object) {
    register float maxDistanceSq = 22500.0f;
    int inView = 0;

    if (DrawList_squaredDistanceToCamera((char *)object + 0x30) < maxDistanceSq) {
        void *position = (char *)object + 0x18;
        float tolerance = *(float *)((char *)object + 0x3C);
        position = (char *)position + 0x18;
        if (((int (*)(void *, float))fn_802C9640)(position, tolerance) != 0) {
            inView = 1;
        }
    }
    return inView;
}
/* Tests whether a point lies within the XZ bounds of a region and below its Y threshold.
 * The region's X range is [min(a[0],a[9]), max(a[0],a[9])] and Z range is
 * [min(a[2],a[11]), max(a[2],a[11])], each expanded by lbl_80558DC4. Returns 1 if the
 * point is inside those bounds and its Y is less than a[1] - lbl_80564634. */
int fn_8029EB54(void *arg0, void *arg1)
{
  float *region = (float *) arg0;
  float *point = (float *) arg1;
  float testCoord;
  float maxX;
  float minX;
  float maxZ;
  float minZ;
  int inXRange;
  int result = 0;
  int inXZBounds = 0;
  float bound = region[9];
  if (region[0] > bound)
  {
    maxX = region[0];
  }
  else
  {
    maxX = bound;
  }
  bound = region[9];
  if (region[0] < bound)
  {
    minX = region[0];
  }
  else
  {
    minX = bound;
  }
  testCoord = point[0];
  inXRange = 0;
  if ((testCoord >= (minX - lbl_80558DC4)) && (testCoord <= (maxX + lbl_80558DC4)))
  {
    inXRange = 1;
  }
  if (inXRange)
  {
    int inZRange;
    bound = region[11];
    if (region[2] > bound)
    {
      maxZ = region[2];
    }
    else
    {
      maxZ = bound;
    }
    bound = region[11];
    if (region[2] < bound)
    {
      minZ = region[2];
    }
    else
    {
      minZ = bound;
    }
    testCoord = point[2];
    inZRange = 0;
    if ((testCoord >= (minZ - lbl_80558DC4)) && (testCoord <= (maxZ + lbl_80558DC4)))
    {
      inZRange = 1;
    }
    if (inZRange)
    {
      inXZBounds = 1;
    }
  }
  if (inXZBounds && (point[1] < (region[1] - lbl_80564634)))
  {
    result = 1;
  }
  return result;
}

void fn_8029EC64(void *area, void *arg1, int arg2) {
    struct Locals { float sp8, spC, sp10, sp14, sp18, sp1C; } s;
    float *f = (float *)arg1;
    char *base2 = (char *)arg1 + arg2 * 0x3C;
    float *m = (float *)(base2 + 0x70);
    float temp_f1, temp_f2, temp_f3, temp_f0_2;
    float var_f1, var_f31, var_f5;
    if ((unsigned char *)&s.sp14 == (unsigned char *)m) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = f[3]; m11 = f[4]; m12 = f[5];
        m00 = f[0]; m01 = f[1]; m02 = f[2];
        m20 = f[6]; m21 = f[7]; m22 = f[8];
        x = m[0]; y = m[1]; z = m[2];
        s.sp14 = z * m20 + (x * m00 + y * m10);
        s.sp18 = z * m21 + (x * m01 + y * m11);
        s.sp1C = z * m22 + (x * m02 + y * m12);
    } else {
        float m00, m01, m02, m10, m11, m12, m20, m21, m22;
        m10 = f[3]; m00 = f[0]; m20 = f[6];
        s.sp14 = m[2] * m20 + (m[0] * m00 + m[1] * m10);
        m11 = f[4]; m01 = f[1]; m21 = f[7];
        s.sp18 = m[2] * m21 + (m[0] * m01 + m[1] * m11);
        m12 = f[5]; m02 = f[2]; m22 = f[8];
        s.sp1C = m[2] * m22 + (m[0] * m02 + m[1] * m12);
    }
    temp_f2 = s.sp18; temp_f1 = s.sp1C;
    s.sp14 += f[9];
    s.sp18 = temp_f2 + f[10];
    s.sp1C = temp_f1 + f[11];
    if (fn_8029EB54(area, &s.sp14)) {
        s.sp18 += lbl_8056465C;
        if (*(float *)m > lbl_80564628) var_f1 = lbl_80564658; else var_f1 = lbl_80564660;
        var_f5 = lbl_80564668;
        temp_f3 = lbl_80564664 + lbl_80564634 * (f[20] * var_f1);
        s.sp8 = f[13] + f[0] * temp_f3;
        s.spC = f[14] + f[1] * temp_f3;
        s.sp10 = f[15] + f[2] * temp_f3;
        temp_f0_2 = lbl_80564664 + lbl_80564634 * f[20];
        var_f5 = var_f5 < temp_f0_2 ? var_f5 : temp_f0_2;
        s.sp8 += f[3] * var_f5;
        s.spC += f[4] * var_f5;
        s.sp10 += f[5] * var_f5;
        if (*(float *)m > lbl_80564628) var_f31 = lbl_80564658; else var_f31 = lbl_80564660;
        fn_8028E590(lbl_8055F7F8, &s.sp14, &s.sp8, -var_f31 * fn_80287BC8(lbl_80564628, lbl_80564674));
    }
}

/* Default virtual-method stub in the nw4r::ef effect vtable: returns 0 (false). */
int fn_8029EF1C(void) {
    return 0;
}

/* No-op nw4r::ef::Effect virtual cleanup hook: invoked from the Effect
 * destructor (fn_8029C3F0) after restoring the vtable; this build leaves it empty. */
void fn_8029EF24(void *effect) {
}

/* Empty nw4r::ef::Effect virtual hook; reached through the fn_8029EF40 wrapper
 * and left as a no-op in this build. */
void fn_8029EF28(void) {
}

/* Empty nw4r::ef::Effect virtual hook; reached through the fn_8029EF44 wrapper
 * and left as a no-op in this build. */
void fn_8029EF2C(void) {
}

/* nw4r::ef::Effect virtual getter (vtable slot lbl_80349780+0xC): returns this
   effect's 32-bit field at offset 0x10. */
int fn_8029EF30(void *effect) {
    return ((int *)effect)[4];
}

/* nw4r::ef::Effect virtual getter: returns this effect's 32-bit field at offset 0x64. */
int fn_8029EF38(void *effect) {
    return *(int *)((char *)effect + 0x64);
}

#pragma dont_inline on
/* Thunk in the nw4r::ef::Effect vtable (slot lbl_80349780+0x18): forwards to the
 * empty virtual hook fn_8029EF28, a no-op in this build. */
void fn_8029EF40(void) {
    fn_8029EF28();
}
/* Thunk in the nw4r::ef::Effect vtable (slot lbl_80349780+0x1C): forwards to the
 * empty virtual hook fn_8029EF2C, a no-op in this build. */
void fn_8029EF44(void) {
    fn_8029EF2C();
}
#pragma dont_inline reset
/* nw4r::ef::Effect virtual setter: set this effect's flag at +0x68 to true
   (paired with fn_8029EF54, which clears it, and fn_8029EF60, which reads it). */
void fn_8029EF48(void *effect) {
    *((unsigned char *)effect + 0x68) = 1;
}

void fn_8029EF54(void *object) {
    /* Clears the boolean flag at offset 0x68 (paired with fn_8029EF48/fn_8029EF60). */
    *((unsigned char *)object + 0x68) = 0;
}

/* nw4r::ef::Effect virtual getter: returns this effect's boolean flag at +0x68
   (paired with fn_8029EF48/fn_8029EF54, which set and clear it). */
int fn_8029EF60(void *effect) {
    return *(unsigned char *)((char *)effect + 0x68);
}
extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450(void *, int);
extern float lbl_8056469C;
