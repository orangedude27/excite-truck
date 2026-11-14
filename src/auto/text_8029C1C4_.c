__declspec(section ".data") extern float lbl_80558DC4;
extern void *fn_802C86DC(void);
extern void fn_802C8BD0(int);
extern int fn_802C8DBC(int);
extern void fn_802C8E00(int, unsigned int, float, float, float, float, float);
extern void fn_802C8E48(void);
extern void fn_802C8D74(void);
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
extern void *fn_802CAC28(int, int);
extern float lbl_8056465C;
extern float lbl_80564628;
extern int lbl_804B5030[];
extern void fn_8029E8E0(float *, int);
extern void fn_802C7040(int);
extern void fn_8029D644(void *);
extern float fn_802C88D4(void *);
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
extern float fn_802C88E8(void *);
extern int fn_802C9640(void *);

void fn_8029C1C4(void) {
    lbl_8055F7FC = 0;
    fn_8029C570(); fn_8029C73C(); fn_8029C998(); fn_8029CBA0(); fn_8029C664();
    if (fn_802BF4F0() == 0 && lbl_8055F7F0 <= 0 && lbl_8055F7F4 <= 0) return;
    fn_80287B38(fn_8029C450);
}

void fn_8029C22C(void) {
    fn_8029CD14();
    fn_8029CB3C();
    fn_8029C934();
    fn_8029C650();
    fn_8029C3EC();
}

void fn_8029C25C(void) {
    int *p;
    int i;
    float v = fn_801E7E24();
    if (!((float)__fabs((double)v) <= lbl_80558DC4)) {
        p = (int *)&lbl_804B5010;
        for (i = 0; i < lbl_8055F7F0; i++) {
            fn_8029D574(*p);
            p++;
        }
    }
}

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
        fn_802C7040(lbl_8055CAA8);

    bestDifference = lbl_80564628;
    entry = lbl_804B5010;
    bestObject = 0;
    i = 0;
    while (i < *(volatile int *)&lbl_8055F7F0) {
        void *object;
        object = (void *)*entry;
        if (fn_8029D4CC(object)) {
            fn_8029D550(object, position, &spread);
            difference = fn_802C88D4(position) - spread;
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
void fn_8029C3EC(void) {
}

extern void fn_8029EF24();
void *__dt__Q34nw4r2ef6EffectFv_8029C3F0(void *arg0, int arg1) {
    if (arg0) {
        *(void **)arg0 = (void *)lbl_80349780;
        fn_8029EF24(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
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
void fn_8029C570(void) {
 extern float lbl_80564640, lbl_80564644;
 extern char lbl_80349560[];
 extern int lbl_8055CAAC;
 extern int fn_8012C33C(void *);
 extern int fn_802C6FC0(void *, int, int);
 extern void **fn_802AE414(void *);
 extern void fn_802C8230(float), fn_802C8234(float);
 float a, b;
 char *base, *p, *q;
 void **obj;
 int result;
 a=lbl_80564640; b=lbl_80564644;
 base=lbl_80349560; p=base+0x70; q=base+0x7C;
 if(fn_8012C33C(q)) result=fn_802C6FC0(q,0,0); else result=-1;
 lbl_8055CAA8=result;
 obj=fn_802AE414(p);
 if(obj) {
  a=(*(float (**)(void *, void *))((char *)*obj+0x4C))(obj,&lbl_8055CAAC);
  b=(*(float (**)(void *, void *))((char *)*obj+0x4C))(obj,base+0x18);
 }
 fn_802C8230(a); fn_802C8234(b);
}
#pragma pop

void fn_8029C650(void) {
    int value = lbl_8055CAA8;
    if (value == -1) return;
    ((void (*)(int))fn_802C6CF8)(value);
}

#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma use_lmw_stmw off
#pragma inline_depth(0)
void fn_8029C664(void) {
    extern void fn_8029D550(void *, float *, float *);
    extern float PSQUATMultiply(float *, float *);
    extern char lbl_803495E8[];
    extern void fn_802E317C(const char *, ...);
    float a[3], b[3], radiusA, radiusB;
    float margin;
    int *base, *p, *q;
    int i, j;
    margin = lbl_80564648;
    p = lbl_804B5010;
    base = p;
    i = 0;
    for (; i<lbl_8055F7F0; ++p, ++i) {
        fn_8029D550((void *)*p, a, &radiusA);
        j=i+1;
        q=base+j;
        for (; j<lbl_8055F7F0; ++q, ++j) {
            fn_8029D550((void *)*q, b, &radiusB);
            if (PSQUATMultiply(a,b)<radiusB+(margin+radiusA))
                fn_802E317C(lbl_803495E8);
        }
    }
}

#pragma cplusplus on
extern "C" void *fn_80131810(void *);
extern "C" void fn_80131818(void *);
extern "C" void *fn_801284F8(int, void *);
extern "C" void *fn_8029D148(void *, void *, float *, int);
extern "C" void fn_802E317C(const char *, ...);
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
                fn_802E317C(base + 0xB0, 8);      /* "water: exceeded pool limit (%d)" */
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
    int *p = (int *)lbl_804B5010;
    int i = 0;
    while (i < lbl_8055F7F0) {
        fn_8029D464((void *)*p, 1);
        ++p;
        ++i;
    }
    lbl_8055F7F0 = 0;
}

#pragma push
#pragma cplusplus on
void fn_8029C998(void) {
    typedef struct { float x, y, z; } Vec;
    typedef struct { float x, y; } Vec2;
    typedef struct { Vec pos; Vec2 v1; Vec2 v2; } Params;
    struct Owner { virtual void m08(); virtual void *get(int); };
    struct Item {
        virtual void m08(); virtual void m0C(); virtual void m10(); virtual int getId(void *);
        virtual void m18(); virtual void m1C(); virtual void m20(); virtual void m24();
        virtual void m28(); virtual void m2C(); virtual void m30(); virtual Vec getVec(void *);
        virtual void m38(); virtual Vec2 getVec2(void *);
    };
    extern char lbl_80349560[]; extern int lbl_804B5030[]; extern int lbl_8055F7F4;
    extern int lbl_8055CAB4, lbl_8055CABC, lbl_8055CAC4;
    extern void *fn_80131810(void *); extern void fn_80131818(void *);
    extern int fn_801284F8(int, void *, float); extern void *fn_8029E754(void *, void *, int);
    extern void fn_802E317C(const char *, ...);
    Params params; int *dest; char *base; Owner *owner; int i; int idx;
    base = lbl_80349560; lbl_8055F7F4 = 0; owner = (Owner *)fn_80131810(base + 0xEC);
    if (owner != 0) {
        dest = lbl_804B5030;
        for (i = 0; owner->get(i) != 0; i++) {
            Item *item; int id; void *res;
            if (lbl_8055F7F4 >= 16) fn_802E317C(base + 0xF8, 16);
            item = (Item *)owner->get(i); id = item->getId(base + 0xD0);
            params.pos = item->getVec(&lbl_8055CAB4);
            params.v1 = item->getVec2(&lbl_8055CABC);
            params.v2 = item->getVec2(&lbl_8055CAC4);
            res = (void *)fn_801284F8(0x44, base + 0x11C, params.v2.x);
            if (res != 0) res = fn_8029E754(res, &params, id);
            idx = lbl_8055F7F4; dest[idx] = (int)res; lbl_8055F7F4 = idx + 1;
        }
        fn_80131818(owner);
    }
}
#pragma pop
extern void *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888(void *, int);
extern int lbl_804B5030[];
void fn_8029CB3C(void) {
    int *p = (int *)lbl_804B5030;
    int i = 0;
    while (i < lbl_8055F7F4) {
        __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888((void *)*p, 1);
        ++p;
        ++i;
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
    volatile ScratchValue scratch[40];
    int *var_r31 = (int *)&lbl_8034968C;
    register float var_f31 = *(volatile float *)&lbl_80564654;
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
        zero = *(volatile float *)&lbl_80564658;
        two = 2;
        high = *(volatile float *)&lbl_80564654;
        size = 0x200;
        scale = *(volatile float *)&lbl_8056465C;
        low = *(volatile float *)&lbl_8056464C;
        five = 5;
        far = *(volatile float *)&lbl_80564660;
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
        scratch[14].f = zero;
        scratch[15].f = zero;
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
void fn_8029CD48(void *arg0) {
    extern double fn_8002F234(float);
    extern float fn_80287BC8(float, float);
    extern float fn_802BF590(void);
    extern void fn_8028E590(int, float *, float *, float);
    extern int lbl_8055F7F8;
    extern float lbl_80564628, lbl_80564634, lbl_80564640, lbl_8056464C;
    extern float lbl_80564658, lbl_8056465C, lbl_80564660, lbl_80564664;
    extern float lbl_80564668, lbl_8056466C, lbl_80564670, lbl_80564674;
    struct Vec3 { float x, y, z; } sp34, sp28, sp1C, sp10;
    volatile float sp8, spC;
    float f31 = lbl_8056464C, f30 = lbl_80564668, f29 = lbl_80564664;
    float f28 = lbl_80564634, f27 = lbl_8056465C, f26 = lbl_80564628;
    float range, f24 = lbl_80564670, f23 = lbl_80564640;
    unsigned char *obj = (unsigned char *)arg0;
    unsigned char *mat = (unsigned char *)arg0 + 0x70;
    int outer, inner;
    for (outer = 0; outer < 4; outer++, obj += 0x3c, mat += 0x3c) {
        float f0;
        if ((*(unsigned int *)(obj + 0x9c) & 8) != 0)
            continue;
        if ((unsigned char *)&sp34.x == mat) {
            register float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
            f0 = *(volatile float *)((char *)arg0 + 0x0c);
            f6 = *(volatile float *)(mat + 4);
            f2 = *(volatile float *)((char *)arg0 + 0x10);
            f4 = f6 * f0;
            f11 = *(volatile float *)((char *)arg0 + 0x14);
            f1 = *(volatile float *)arg0;
            f2 = f6 * f2;
            f0 = *(volatile float *)mat;
            f3 = *(volatile float *)((char *)arg0 + 0x04);
            f5 = f0 * f1;
            f10 = *(volatile float *)((char *)arg0 + 0x08);
            f3 = f0 * f3;
            f8 = *(volatile float *)((char *)arg0 + 0x18);
            f1 = f0 * f10;
            f0 = f6 * f11;
            f7 = *(volatile float *)(mat + 8);
            f9 = *(volatile float *)((char *)arg0 + 0x1c);
            f5 = f5 + f4;
            f6 = f7 * f8;
            f12 = *(volatile float *)((char *)arg0 + 0x20);
            f3 = f3 + f2;
            f4 = f7 * f9;
            f0 = f1 + f0;
            f2 = f7 * f12;
            f5 = f6 + f5;
            f1 = f4 + f3;
            f0 = f2 + f0;
            sp34.x = f5;
            sp34.y = f1;
            sp34.z = f0;
        } else {
            sp34.x = *(float *)((char *)arg0 + 0x0c) * *(float *)(mat + 4) +
                *(float *)arg0 * *(float *)mat +
                *(float *)((char *)arg0 + 0x18) * *(float *)(mat + 8);
            sp34.y = *(float *)((char *)arg0 + 0x10) * *(float *)(mat + 4) +
                *(float *)((char *)arg0 + 0x04) * *(float *)mat +
                *(float *)((char *)arg0 + 0x1c) * *(float *)(mat + 8);
            sp34.z = *(float *)((char *)arg0 + 0x14) * *(float *)(mat + 4) +
                *(float *)((char *)arg0 + 0x08) * *(float *)mat +
                *(float *)((char *)arg0 + 0x20) * *(float *)(mat + 8);
        }
        sp34.x += *(float *)((char *)arg0 + 0x24);
        sp34.y += *(float *)((char *)arg0 + 0x28);
        sp34.z += *(float *)((char *)arg0 + 0x2c);
        if (sp34.y > fn_802BF590())
            continue;
        sp34.y += f27;
        if (*(float *)mat > f26)
            f0 = lbl_80564658;
        else
            f0 = lbl_80564660;
        {
            float speed = *(float *)((char *)arg0 + 0x50);
            float scale = f29 + f28 * (speed * f0);
            float limit = f29 + f28 * speed;
            float x = *(float *)((char *)arg0 + 0x34);
            float z = *(float *)((char *)arg0 + 0x3c);
            sp28.x = x + *(float *)arg0 * scale;
            sp28.y = *(float *)((char *)arg0 + 0x38) + *(float *)((char *)arg0 + 0x04) * scale;
            sp28.z = z + *(float *)((char *)arg0 + 0x08) * scale;
            if (f30 < limit)
                limit = f30;
            sp28.x += *(float *)((char *)arg0 + 0x0c) * limit;
            sp28.y += *(float *)((char *)arg0 + 0x10) * limit;
            sp28.z += *(float *)((char *)arg0 + 0x14) * limit;
            {
                float squared = x * x + z * z;
                sp8 = x;
                spC = z;
                {
                    register float distance = fn_8002F234(squared);
                    {
                        float count = f31 * distance;
                        int iterations;
                        if ((int)count < 6)
                            iterations = (int)count;
                        else
                            iterations = 6;
                        range = f24 * distance;
                        for (inner = 0; inner < iterations; inner++) {
                            float step;
                            sp1C = sp34;
                            sp1C.x += fn_80287BC8(lbl_8056466C, lbl_8056465C);
                            sp1C.z += fn_80287BC8(lbl_8056466C, lbl_8056465C);
                            sp1C.y = fn_802BF590();
                            step = f23 < range ? f23 : range;
                            sp10 = sp28;
                            sp10.x += fn_80287BC8(-step, step);
                            sp10.y = f23 * fn_80287BC8(lbl_80564628, step);
                            sp10.z += fn_80287BC8(-step, step);
                            if (*(float *)mat > f26)
                                f0 = lbl_80564658;
                            else
                                f0 = lbl_80564660;
                            fn_8028E590(lbl_8055F7F8, &sp1C.x, &sp10.x,
                                -f0 * fn_80287BC8(lbl_80564628, lbl_80564674));
                        }
                    }
                }
            }
        }
    }
}
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void *fn_8029D148(void *arg0, void *arg1, float *arg2, int arg3) {
    extern double fn_8002F234(float);
    extern void *fn_8012850C(int, const char *);
    extern void *memset(void *, int, unsigned int);
    extern void fn_802E317C(const char *, ...);
    extern float PSQUATMultiply(float *, float *);
    extern void *fn_802CAC28(int, int);
    extern void fn_8014E740(float *, float, float, float, float, float, float, float, float, float, float, float, float);
    extern char lbl_80349560[];
    extern float lbl_80564628, lbl_80564658, lbl_8056465C, lbl_80564678;
    int dimX, dimY, twice, initId, data, end;
    unsigned char flag0, flag1;
    float sqX0, sqX1, sqY0, sqY1, rootX, rootY, ySquared;
    float stepX, stepY;
    float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
    float init0, init1;
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
        fn_802E317C(base + 0x148, *(int *)((char *)arg0 + 0x10));
    *(void **)arg0 = fn_8012850C(*(int *)((char *)arg0 + 0x10) * (*(int *)((char *)arg0 + 0xC) * 2) * 2, base + 0x16C);
    memset(*(void **)arg0, 0, *(int *)((char *)arg0 + 0x10) * (*(int *)((char *)arg0 + 0xC) * 4));

    stepX = lbl_80564658 / (float)(*(int *)((char *)arg0 + 0xC) - 1);
    stepY = lbl_80564658 / (float)(*(int *)((char *)arg0 + 0x10) - 1);
    data = *(int *)arg0;
    end = data + *(int *)((char *)arg0 + 0xC) * *(int *)((char *)arg0 + 0x10) * 2;
    initId = *(int *)((char *)arg1 + 0x18);
    f10 = *(float *)((char *)arg1 + 4);
    f11 = *(float *)arg2;
    f8 = *(float *)((char *)arg2 + 8);
    f7 = *(float *)((char *)arg2 + 0xC);
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
    f0 = f11 + (lbl_8056465C * (f7 + f5));
    f8 = f9 + f1;
    init0 = *(float *)arg1;
    init1 = *(float *)((char *)arg1 + 4);
    flag0 = *((unsigned char *)arg1 + 0x1C);
    flag1 = *((unsigned char *)arg1 + 0x1D);
    *(int *)((char *)arg0 + 4) = data;
    *(int *)((char *)arg0 + 8) = end;
    *(int *)((char *)arg0 + 0x2C) = initId & 0xFFFFFF;
    *(float *)((char *)arg0 + 0x14) = init0;
    *(float *)((char *)arg0 + 0x18) = init1;
    *(float *)((char *)arg0 + 0x1C) = *(float *)((char *)arg1 + 8);
    *(float *)((char *)arg0 + 0x20) = *(float *)((char *)arg1 + 0xC);
    *(float *)((char *)arg0 + 0x24) = *(float *)((char *)arg1 + 0x10);
    *(float *)((char *)arg0 + 0x28) = *(float *)((char *)arg1 + 0x14);
    *(unsigned char *)((char *)arg0 + 0x30) = flag0;
    *(unsigned char *)((char *)arg0 + 0x31) = flag1;
    *(float *)((char *)arg0 + 0x34) = lbl_80564628;
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
    *(void **)((char *)arg0 + 0x74) = fn_802CAC28(arg3, 0);

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
    fn_8014E740(scratch, *(float *)((char *)arg0 + 0x60), f1, f4, f0, f5, f6, f7, f8, f9, f10, f11, f12);
    return arg0;
}
#pragma pop
void *fn_8029D464(void *arg0,int arg1) {
 if(arg0) { fn_802CAC54(*(int *)((unsigned char *)arg0+0x74)); fn_80128670(*(int *)((unsigned char *)arg0+0x70)); fn_80128670(*(int *)arg0); if(arg1>0) fn_80128668(arg0); }
 return arg0;
}

extern float fn_801E88F0(int);
extern float fn_802C88E8(void *);
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
    temp_f2 = fn_802C88E8((char *)object + 0x54);
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
void fn_8029D550(void *arg0, float *arg1, float *arg2) {
    arg1[0] = *(float *)((char *)arg0 + 0x54);
    arg1[1] = *(float *)((char *)arg0 + 0x58);
    arg1[2] = *(float *)((char *)arg0 + 0x5C);
    *arg2 = *(float *)((char *)arg0 + 0x60);
}

extern int fn_80287B94(int, int);
extern void fn_8029DF64(void *, int, int, float);
extern void fn_8029DDB8(void *);
#pragma push
#pragma processor 750
void fn_8029D574(int arg0) {
    extern float lbl_80564658;
    extern float fn_80287BC8(float, float);
    extern void fn_8029DF64(void *, int, int, float);
    float value;
    int y;
    char *p = (char *)arg0;
    if (*(float *)(p + 0x34) >= lbl_80564658 - lbl_80558DC4) {
        float range = *(float *)(p + 0x28);
        value = fn_80287BC8(-range, range);
        y = fn_80287B94(1, *(int *)(p + 0x10) - 2);
        fn_8029DF64(p, fn_80287B94(1, *(int *)(p + 0xC) - 2), y, value);
        *(float *)(p + 0x34) += *(float *)(p + 0x24) - lbl_80564658;
    } else {
        *(float *)(p + 0x34) += *(float *)(p + 0x24);
    }
    fn_8029DDB8(p);
}
#pragma pop
void fn_8029D644(void *arg0);
void fn_8029D644(void *arg0) {
    int i;
    int offset;
    char *source;
    char *other;
    char *buffers[2];
    char **bufferTable;
    int mode;
    GridRecord_8029D644 *row;

    i = (*(int *)((char *)arg0 + 0x10) - 1) * (*(int *)((char *)arg0 + 0xC) * 2);
    {
        char *result = (char *)((void *(*)(int, int))fn_802C86DC)(
            *(int *)((char *)arg0 + 0x10) - 1, *(int *)((char *)arg0 + 0x10));
        *(float *)((char *)arg0 + 0x64) = *(float *)(result + 0x24);
        *(float *)((char *)arg0 + 0x68) = *(float *)(result + 0x28);
        *(float *)((char *)arg0 + 0x6C) = *(float *)(result + 0x2C);
    }
    fn_802C8BD0(*(int *)((char *)arg0 + 0x74));
    if (fn_802C8DBC(i) != 0) {
        buffers[0] = *(char **)((char *)arg0 + 0x70);
        buffers[1] = buffers[0] + *(int *)((char *)arg0 + 0xC) * 0x18;
        for (i = 0, offset = 0; i < *(int *)((char *)arg0 + 0xC); offset += 0x18, i++)
            fn_8029DB78(arg0, buffers[0] + offset, i, 0);

        bufferTable = buffers;
        for (mode = 1; mode < *(int *)((char *)arg0 + 0x10); mode++) {
            source = bufferTable[mode & 1];
            other = bufferTable[1 - (mode & 1)];
            for (i = 0, offset = 0; i < *(int *)((char *)arg0 + 0xC); offset += 0x18, i++) {
                fn_8029DB78(arg0, source + offset, i, mode);
                row = (GridRecord_8029D644 *)(other + offset);
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
        fn_802C8E48();
    }
    fn_802C8D74();
}

extern void fn_8029E49C(int, void *, int);
extern void fn_8029E130(void *, float *, float *, float);
void fn_8029D7D0(int arg0, void **arg1) {
    extern void fn_801EE0C8(int);
    extern void *fn_802C6C34(void);
    extern int lbl_80488648[];
    extern float lbl_80564688;
    char *o = (char *)arg0;
    char **st = (char **)arg1;
    char *info = st[0];
    float sp[3];
    float r = *(float *)(o + 0x60);
    float dz = *(float *)(info + 0x2C) - *(float *)(o + 0x5C);
    float dx = *(float *)(info + 0x24) - *(float *)(o + 0x54);
    float r2 = r * r;
    float dzSq = dz * dz;
    float dxSq = dx * dx;
    float dist = dxSq + dzSq;
    int off, i;
    unsigned idx;
    float *v;
    float *m;
    if (dist > r2)
        return;
    for (i = 0, off = 0; i < 4; i++, off += 0x3C) {
        if ((*(int *)(st[0] + off + 0x9C) & 8) == 0)
            fn_8029E49C(arg0, st[0], i);
    }
    idx = *(unsigned *)(st + 1);
    fn_801EE0C8(idx < 8 ? lbl_80488648[idx] : 0);
    v = (float *)fn_802C6C34();
    m = (float *)st[0];
    if (sp == v + 8) {
        float b = v[9];
        float a = v[8];
        float c = v[10];
        float t0 = m[3] * b + m[0] * a;
        float t1 = m[4] * b + m[1] * a;
        float t2 = m[5] * b + m[2] * a;
        t0 += m[6] * c;
        t1 += m[7] * c;
        t2 += m[8] * c;
        sp[0] = t0;
        sp[1] = t1;
        sp[2] = t2;
    } else {
        sp[0] = m[3] * v[9] + m[0] * v[8] + m[6] * v[10];
        sp[1] = m[4] * v[9] + m[1] * v[8] + m[7] * v[10];
        sp[2] = m[5] * v[9] + m[2] * v[8] + m[8] * v[10];
    }
    sp[0] += m[9];
    sp[1] += m[10];
    sp[2] += m[11];
    fn_8029E130((void *)arg0, sp, (float *)(st[0] + 0x34), lbl_80564688 * v[7]);
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
#pragma scheduling invalid_target
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
    *(int *)(out + 3) = *(int *)(p + 0x2C) | ((lo + (int)((float)(hi - lo) * (lbl_80564658 - proj[1] * proj[1]))) << 24);
}
#pragma pop
extern float lbl_8056462C, lbl_80564634, lbl_80564640, lbl_80564658, lbl_80564694, lbl_80564698;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8029DDB8(void *arg0) {
    register unsigned char *base = (unsigned char *)arg0;
    short *src;
    short *dst;
    short *cell;
    int width;
    int y;
    int x;
    int rowPlus;
    int rowMinus;
    int index;
    int indexPlus;
    int indexMinus;
    int neighbors;
    int value;
    float scale;
    float wave;
    float waveSquared;
    float center;
    float result;

    scale = lbl_80564634 * *(float *)(base + 0x20);
    center = lbl_8056462C + scale;
    wave = ((float (*)(float, float))fn_801E7E24)(scale, lbl_80564634);
    y = 1;
    wave = lbl_80564694 * (lbl_80564658 - *(float *)(base + 0x1C)) * wave;
    waveSquared = wave * wave;
    wave = lbl_80564640 - lbl_80564698 * waveSquared;

    while (y < *(volatile int *)(base + 0x10) - 1) {
        rowPlus = y + 1;
        rowMinus = y - 1;
        x = 1;
        while (x < (width = *(volatile int *)(base + 0xC)) - 1) {
            index = x + y * width;
            indexPlus = x + rowPlus * width;
            indexMinus = x + rowMinus * width;
            src = *(short **)(base + 4);
            dst = *(short **)(base + 8);
            cell = src + index;
            neighbors = cell[1] + cell[-1] +
                        src[indexPlus] + src[indexMinus];
            result = wave * (float)src[index];
            result = result + waveSquared * (float)neighbors;
            result = result - (float)dst[index];
            result = center * result;
            value = -32768;
            if ((int)result > -32768) {
                value = 32767;
                if ((int)result < 32767)
                    value = (int)result;
            }
            dst[index] = (short)value;
            ++x;
        }
        ++y;
    }
    src = *(short **)(base + 4);
    dst = *(short **)(base + 8);
    *(short **)(base + 8) = src;
    *(short **)(base + 4) = dst;
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
#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma optimization_level 4
void fn_8029DF64(void *arg0, int arg1, int arg2, float arg3) {
    short *data;
    register int low = -32768;
    int index;
    int stride;
    float val;
    int cvt;
    int out;
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
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma optimization_level 4
int fn_8029DFE0(void *arg0, void *arg1) {
    extern float lbl_805646A0, lbl_8056465C, lbl_80564634;
    struct Delta { float x, z; };
    volatile struct Delta delta;
    float x = *(float *)arg1 - *(float *)((char *)arg0 + 0x38);
    float z = *(float *)((char *)arg1 + 8) - *(float *)((char *)arg0 + 0x40);
    float u = z * *(float *)((char *)arg0 + 0x48) + x * *(float *)((char *)arg0 + 0x44);
    float v = z * *(float *)((char *)arg0 + 0x50) + x * *(float *)((char *)arg0 + 0x4C);
    float upper = (float)*(int *)((char *)arg0 + 0xC) - lbl_805646A0;
    int result = 0, inside = 0, test = 0;
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
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
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
 height = *(float *)(obj+0x3c);
 if (pos[1]-radius > height-lbl_80564634) return;
 delta[1]=pos[2]-*(float *)(obj+0x40);
 direction[1]=vel[2]; direction[0]=vel[0];
 delta[0]=pos[0]-*(float *)(obj+0x38);
 if ((float)__fabs(direction[0]*direction[0]+direction[1]*direction[1]) <= lbl_80558DC4) return;
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
 if(ix<1 || ix>=*(int *)(obj+0xc)-1 || iz<1) return;
 if(iz>=*(int *)(obj+0x10)-1) return;
 (*(short **)(obj+4))[ix+iz**(int *)(obj+0xc)]=-32768;
 origin[2]=*(float *)(obj+0x40)+hit[1];
 origin[1]=lbl_8056464C+*(float *)(obj+0x3c);
 origin[0]=*(float *)(obj+0x38)+hit[0];
 perpendicular[0]=direction[1]*inv;
 perpendicular[1]=direction[0]*inv;
 spread=lbl_80564640;
 x=lbl_80564670*length;
 if (spread < x) spread=x;
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
   scale=lbl_80564698*fn_80287BC8(-spread,spread);
   outvel[1]=x; outvel[2]=z; outvel[0]=direction[0]+perpendicular[0]*scale;
   fn_8028E584(lbl_8055F7F8,outpos,outvel);
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
    float sp1C, sp18, sp14, sp10, spC, sp8;
    float temp_f0, temp_f0_2, temp_f1, temp_f2, temp_f3, temp_f6, temp_f7;
    float var_f1, var_f31, var_f5;
    unsigned char *temp_r31, *temp_r5;
    temp_r5 = (unsigned char *)arg1 + arg2 * 0x3C;
    temp_r31 = temp_r5 + 0x70;
    if ((unsigned char *)&sp14 == temp_r31) {
        temp_f6 = *(float *)(temp_r31 + 4); temp_f0 = *(float *)(temp_r31); temp_f7 = *(float *)(temp_r31 + 8);
        sp14 = temp_f7 * *(float *)((unsigned char *)arg1 + 0x18) + (temp_f0 * *(float *)arg1 + temp_f6 * *(float *)((unsigned char *)arg1 + 0xC));
        sp18 = temp_f7 * *(float *)((unsigned char *)arg1 + 0x1C) + (temp_f0 * *(float *)((unsigned char *)arg1 + 4) + temp_f6 * *(float *)((unsigned char *)arg1 + 0x10));
        sp1C = temp_f7 * *(float *)((unsigned char *)arg1 + 0x20) + (temp_f0 * *(float *)((unsigned char *)arg1 + 8) + temp_f6 * *(float *)((unsigned char *)arg1 + 0x14));
    } else {
        sp14 = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x18) + (*(float *)temp_r31 * *(float *)arg1 + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0xC));
        sp18 = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x1C) + (*(float *)temp_r31 * *(float *)((unsigned char *)arg1 + 4) + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0x10));
        sp1C = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x20) + (*(float *)temp_r31 * *(float *)((unsigned char *)arg1 + 8) + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0x14));
    }
    temp_f2 = sp18; temp_f1 = sp1C;
    sp14 += *(float *)((unsigned char *)arg1 + 0x24);
    sp18 = temp_f2 + *(float *)((unsigned char *)arg1 + 0x28);
    sp1C = temp_f1 + *(float *)((unsigned char *)arg1 + 0x2C);
    if (fn_8029DFE0(&sp14, temp_f1, temp_f2)) {
        sp18 += lbl_8056465C;
        if (*(float *)temp_r31 > lbl_80564628) var_f1 = lbl_80564658; else var_f1 = lbl_80564660;
        var_f5 = lbl_80564668;
        temp_f3 = lbl_80564664 + lbl_80564634 * (*(float *)((unsigned char *)arg1 + 0x50) * var_f1);
        sp8 = *(float *)((unsigned char *)arg1 + 0x34) + *(float *)arg1 * temp_f3;
        spC = *(float *)((unsigned char *)arg1 + 0x38) + *(float *)((unsigned char *)arg1 + 4) * temp_f3;
        sp10 = *(float *)((unsigned char *)arg1 + 0x3C) + *(float *)((unsigned char *)arg1 + 8) * temp_f3;
        temp_f0_2 = lbl_80564664 + lbl_80564634 * *(float *)((unsigned char *)arg1 + 0x50);
        if (var_f5 < temp_f0_2) {} else var_f5 = temp_f0_2;
        sp8 += *(float *)((unsigned char *)arg1 + 0xC) * var_f5;
        spC += *(float *)((unsigned char *)arg1 + 0x10) * var_f5;
        sp10 += *(float *)((unsigned char *)arg1 + 0x14) * var_f5;
        if (*(float *)temp_r31 > lbl_80564628) var_f31 = lbl_80564658; else var_f31 = lbl_80564660;
        fn_8028E590(lbl_8055F7F8, &sp14, &sp8, -var_f31 * fn_80287BC8(lbl_80564628, lbl_80564674));
    }
}

void *fn_8029E754(void *arg0, void *arg1, int arg2) {
    float *out;
    float *in;
    float half;
    float scale;
    float x, y, z, w, xx, yy, zz;
    float a, b, c, d, e, f;
    float qx, qy, qz;
    out = (float *)arg0;
    in = (float *)arg1;
    half = lbl_80564628;
    scale = lbl_8056465C;
    w = in[3];
    x = in[0];
    xx = in[4];
    a = x + w;
    y = in[1];
    z = in[2];
    b = y + half;
    zz = in[5];
    c = z + xx;
    yy = in[6];
    d = b + half;
    e = a + zz;
    f = c + yy;
    qx = scale * (d - y);
    qy = scale * (e - x);
    qz = scale * (f - z);
    out[0] = x;
    out[1] = y;
    out[2] = z;
    out[3] = a;
    out[4] = b;
    out[5] = c;
    out[6] = x + zz;
    out[7] = b;
    out[8] = z + yy;
    out[9] = e;
    out[10] = d;
    out[11] = f;
    out[12] = x + qy;
    out[13] = y + qx;
    out[14] = z + qz;
    out[15] = PSQUATMultiply(out, out + 12);
    ((int *)arg0)[16] = (int)fn_802CAC28(arg2, 0);
    return arg0;
}
void *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802CAC54(*(int *)((char *)arg0 + 0x40));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern void *fn_802C86DC(void);
extern void fn_802C8BD0(int);
extern int fn_802C8DBC(int);
extern void fn_802C8E48(void);
extern void fn_802C8D74(void);
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
    float f30, f31, radius, norm;
    int i;
    int b, a;
    fn_802C8BD0(*(int *)((char *)arg0 + 0x40));
    if (fn_802C8DBC(4) != 0) {
        struct ReverseVec3 *view;
        view = (struct ReverseVec3 *)((char *)fn_802C86DC() + 0x24);
        center = *view;
        f30 = lbl_80564658;
        i = 0;
        f31 = lbl_8056465C;
        do {
            diff.y = arg0[1] - center.y;
            diff.x = arg0[0] - center.z;
            diff.z = arg0[2] - center.x;
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
                b = (i ^ 1) & i;
                a = (i ^ 1) >> 1;
                fn_802C8E00(-1, (unsigned int)(a - b) >> 31, arg0[0], arg0[1], arg0[2],
                    f31 + sp8.x * norm, f31 + sp8.z * norm);
            }
            i++;
            arg0 += 3;
        } while ((unsigned int)i < 4);
        fn_802C8E48();
    }
    fn_802C8D74();
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
int fn_8029EAE8(void *arg0) {
    register float temp_f31 = *(volatile float *)&lbl_805646A8;
    int result = 0;
    if (fn_802C88E8((char *)arg0 + 0x30) < temp_f31) {
        void *second_obj = (char *)arg0 + 0x18;
        float value = *(float *)((char *)arg0 + 0x3C);
        second_obj = (char *)second_obj + 0x18;
        if (((int (*)(void *, float))fn_802C9640)(second_obj, value) != 0) {
            result = 1;
        }
    }
    return result;
}
#pragma pop
int fn_8029EB54(void *arg0, void *arg1) {
    float *a=(float *)arg0, *b=(float *)arg1;
    float minX, maxX, minY, maxY, point;
    int result=0;
    int inside=0;
    minX=a[9];
    if (a[0]>minX) minX=a[0];
    maxX=a[9];
    if (a[0]<maxX) maxX=a[0];
    point=b[0];
    if (point>=minX-lbl_80558DC4 && point<=maxX+lbl_80558DC4) inside=1;
    if (inside) {
        minY=a[11];
        if (a[2]>minY) minY=a[2];
        maxY=a[11];
        if (a[2]<maxY) maxY=a[2];
        point=b[2];
        if (point>=minY-lbl_80558DC4 && point<=maxY+lbl_80558DC4) inside=1;
    }
    if (inside && b[1]<a[1]-lbl_80564634) result=1;
    return result;
}

void fn_8029EC64(void *area, void *arg1, int arg2) {
    float sp1C, sp18, sp14, sp10, spC, sp8;
    float temp_f0, temp_f0_2, temp_f1, temp_f2, temp_f3, temp_f6, temp_f7;
    float var_f1, var_f31, var_f5;
    unsigned char *temp_r31, *temp_r5;
    temp_r5 = (unsigned char *)arg1 + arg2 * 0x3C;
    temp_r31 = temp_r5 + 0x70;
    if ((unsigned char *)&sp14 == temp_r31) {
        temp_f6 = *(float *)(temp_r31 + 4); temp_f0 = *(float *)(temp_r31); temp_f7 = *(float *)(temp_r31 + 8);
        sp14 = temp_f7 * *(float *)((unsigned char *)arg1 + 0x18) + (temp_f0 * *(float *)arg1 + temp_f6 * *(float *)((unsigned char *)arg1 + 0xC));
        sp18 = temp_f7 * *(float *)((unsigned char *)arg1 + 0x1C) + (temp_f0 * *(float *)((unsigned char *)arg1 + 4) + temp_f6 * *(float *)((unsigned char *)arg1 + 0x10));
        sp1C = temp_f7 * *(float *)((unsigned char *)arg1 + 0x20) + (temp_f0 * *(float *)((unsigned char *)arg1 + 8) + temp_f6 * *(float *)((unsigned char *)arg1 + 0x14));
    } else {
        sp14 = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x18) + (*(float *)temp_r31 * *(float *)arg1 + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0xC));
        sp18 = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x1C) + (*(float *)temp_r31 * *(float *)((unsigned char *)arg1 + 4) + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0x10));
        sp1C = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x20) + (*(float *)temp_r31 * *(float *)((unsigned char *)arg1 + 8) + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0x14));
    }
    temp_f2 = sp18; temp_f1 = sp1C;
    sp14 += *(float *)((unsigned char *)arg1 + 0x24);
    sp18 = temp_f2 + *(float *)((unsigned char *)arg1 + 0x28);
    sp1C = temp_f1 + *(float *)((unsigned char *)arg1 + 0x2C);
    if (fn_8029EB54(area, &sp14)) {
        sp18 += lbl_8056465C;
        var_f1 = (*(float *)temp_r31 > lbl_80564628) ? lbl_80564658 : lbl_80564660;
        var_f5 = lbl_80564668;
        temp_f3 = lbl_80564664 + lbl_80564634 * (*(float *)((unsigned char *)arg1 + 0x50) * var_f1);
        sp8 = *(float *)((unsigned char *)arg1 + 0x34) + *(float *)arg1 * temp_f3;
        spC = *(float *)((unsigned char *)arg1 + 0x38) + *(float *)((unsigned char *)arg1 + 4) * temp_f3;
        sp10 = *(float *)((unsigned char *)arg1 + 0x3C) + *(float *)((unsigned char *)arg1 + 8) * temp_f3;
        temp_f0_2 = lbl_80564664 + lbl_80564634 * *(float *)((unsigned char *)arg1 + 0x50);
        if (var_f5 >= temp_f0_2) var_f5 = temp_f0_2;
        sp8 += *(float *)((unsigned char *)arg1 + 0xC) * var_f5;
        spC += *(float *)((unsigned char *)arg1 + 0x10) * var_f5;
        sp10 += *(float *)((unsigned char *)arg1 + 0x14) * var_f5;
        var_f31 = (*(float *)temp_r31 > lbl_80564628) ? lbl_80564658 : lbl_80564660;
        fn_8028E590(lbl_8055F7F8, &sp14, &sp8, -var_f31 * fn_80287BC8(lbl_80564628, lbl_80564674));
    }
}

int fn_8029EF1C(void) {
    return 0;
}

void fn_8029EF24(void) {
}

void fn_8029EF28(void) {
}

void fn_8029EF2C(void) {
}

int fn_8029EF30(void *arg0) {
    return ((int *)arg0)[4];
}

int fn_8029EF38(void *arg0) {
    return *(int *)((char *)arg0 + 0x64);
}

#pragma dont_inline on
void fn_8029EF40(void) {
    fn_8029EF28();
}
void fn_8029EF44(void) {
    fn_8029EF2C();
}
#pragma dont_inline reset
void fn_8029EF48(void *arg0) {
    *((unsigned char *)arg0 + 0x68) = 1;
}

void fn_8029EF54(void *arg0) {
    *((unsigned char *)arg0 + 0x68) = 0;
}

int fn_8029EF60(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x68);
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
