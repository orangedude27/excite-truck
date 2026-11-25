// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8034AE40[];
extern int lbl_8055FAFC;
extern void *lbl_8055FB00;
extern float lbl_80564DA8;
extern void *fn_801284F8(int, const char *);
extern int fn_802CB128(int, int, int, int);
extern char lbl_8055CF84[4];
extern int fn_801E85A4(void);
extern double atan(double), fn_8002EF30(float);
extern void fn_802BDD8C(float);
extern void fn_802BFE48(void *, void *, float), fn_802C0054(void *, const void *), fn_802C00A0(void);
extern void fn_80144DAC(void *, void *), fn_80144DC8(void *);
extern void fn_802C10C8(void), DrawModelInstance(int), DrawList_loadMatrix(void *), DrawList_saveViewport(void *, int, int, int, int), DrawList_restoreViewport(void *, int), fn_802C88BC(int), DrawList_copyCurrentMatrix(void *), fn_802C8B98(int, float *), DrawList_RestoreNormalMode(void), fn_802C8DB8(void *, int, unsigned short *, int), fn_802C9294(int, int), DrawList_saveProjection(void *, float, float, float), DrawList_restoreProjection(void *, int), Texture_BindRenderTarget(int);
extern float lbl_80564DAC, lbl_80564DB0, lbl_80564DB4, lbl_80564DB8, lbl_80564DBC, lbl_80564DC0, lbl_80564DC4, lbl_80564DC8;
extern void fn_80128668(void *);
extern int fn_802BF6AC(void);
extern int fn_802CAC28(void *, int);
extern char lbl_8034AE08[];
extern float lbl_8055FB04, lbl_80564DF0;
extern void fn_802BEDFC(void);
extern int fn_801E85AC(void);
extern int fn_802C00A4(void);
extern int fn_8012C33C();
extern int fn_802C6FC0(int, int, int);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034AD78[];
extern int lbl_8055CF68;
extern void fn_801E866C(int);
extern void *fn_801EA9A0(void);
extern float lbl_80564D80, lbl_80564D84, lbl_80564D88, lbl_80564D8C;
extern float lbl_80564D90, lbl_80564D94;
extern void fn_802CAC54(int);
extern char lbl_8034AE20[];
typedef unsigned int u32;
extern int sscanf(const char *, const char *, ...);
extern float lbl_8055FAF4;
extern float lbl_8055FAE0;
extern int lbl_8055FAE4, lbl_8055FAE8, lbl_8055FAEC, lbl_8055FAF0;
extern float lbl_80564D84;
extern char lbl_8034ACA0[];
#pragma small_data on
extern char lbl_8055CF80;
__declspec(section ".sdata") extern char lbl_8055CF78[];
#pragma small_data off
extern void *fn_80131808(void *, int, int);
extern int fn_80131818(void *);
#pragma dont_inline fn_802BECE4
extern int fn_802BECE4(const char *, int);
extern float lbl_80564D7C;
extern float lbl_80564D80;
extern float PSVECMag(void *);
extern char lbl_8034ACC0[];
extern unsigned char lbl_8055CF71;
extern int fn_801E85B4(void);
extern void fn_802BF160(void);
extern int fn_802C2C00(int);
extern void fn_802C6CF8();
extern void *lbl_804C07F0[];
extern unsigned char lbl_8055CF70;
extern int lbl_8055FADC;
extern int lbl_8055CF6C;
#pragma scheduling invalid_target
#pragma dont_inline on
/* Parses a 4-byte dotted decimal string into a packed integer, or falls back to hex parsing; returns defaultValue on failure. */
int fn_802BECE4(const char *str, int defaultValue) {
    int b0, b1, b2, b3;
    int value = defaultValue;
    b3 = b2 = b1 = b0 = 0;
    if (sscanf(str, lbl_8034ACC0, &b0, &b1, &b2, &b3) == 4) {
        value = ((b0 & 0xff) << 24) | ((b1 & 0xff) << 16) |
                 ((b2 & 0xff) << 8) | (b3 & 0xff);
    } else {
        sscanf(str, lbl_8055CF78, &value);
    }
    return value;
}
#pragma dont_inline reset
#pragma scheduling on
void fn_802BED90(float *vec) {
    /* Normalize a 3D vector to unit length, clamping very small magnitudes to avoid division by zero. */
    float mag = PSVECMag(vec);
    float scale;
    mag = lbl_80564D7C > mag ? lbl_80564D7C : mag;
    scale = lbl_80564D80 / mag;
    vec[0] *= scale;
    vec[1] *= scale;
    vec[2] *= scale;
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802BEDFC(void) {
    class Resource {
    public:
        virtual void *getStyle(const char *);
        virtual void unused1();
        virtual int hasStyle(const char *);
        virtual void unused3();
        virtual const char *setProperty(const char *, const char *);
        virtual void unused5();
        virtual void unused6();
        virtual void unused7();
        virtual float setScale(const char *, float);
    };
    char *strings = lbl_8034ACA0;
    Resource *resource;
    Resource *style;
    u32 baseE000 = 0xE0000000u;
    u32 alpha = 0xE0FFFFFF;
    lbl_8055FAE8 = alpha;
    lbl_8055FAE4 = baseE000 + 0x5030;
    lbl_8055FAEC = 0x202040;
    lbl_8055FAE0 = 0.7f;
    lbl_8055FAF0 = baseE000 + 0x1040;
    resource = (Resource *)fn_80131808(strings + 0x2C, alpha, baseE000);
    if (resource != 0) {
        if (resource->hasStyle(strings + 0x38) != 0)
            style = (Resource *)resource->getStyle(strings + 0x38);
        else
            style = 0;
        if (style != 0) {
            lbl_8055FAE0 = style->setScale(strings + 0x44, lbl_8055FAE0);
            lbl_8055FAE4 = fn_802BECE4(style->setProperty(strings + 0x54, (const char *)&lbl_8055CF80), lbl_8055FAE4);
            lbl_8055FAE8 = fn_802BECE4(style->setProperty(strings + 0x68, (const char *)&lbl_8055CF80), lbl_8055FAE8);
            lbl_8055FAEC = fn_802BECE4(style->setProperty(strings + 0x78, (const char *)&lbl_8055CF80), lbl_8055FAEC);
            lbl_8055FAF0 = fn_802BECE4(style->setProperty(strings + 0x90, (const char *)&lbl_8055CF80), lbl_8055FAF0);
            fn_802E30C8(strings + 0xA4, lbl_8055FAE4, lbl_8055FAE8, lbl_8055FAEC, lbl_8055FAF0);
        }
        fn_80131818(resource);
    }
    lbl_8055FAF4 = lbl_8055FAE0;
}
#pragma scheduling on
#pragma cplusplus reset

#pragma dont_inline on
float fn_802BEFB4(void) {
    float value;
    float limit;
    float result;
    fn_801E866C(-1);
    value = (*(float *)((char *)*(void **)((char *)fn_801EA9A0() + 8) + 0x64) - lbl_80564D88) / lbl_80564D8C;
    limit = lbl_80564D80;
    limit = limit < value ? value : limit;
    limit = lbl_80564D90 < limit ? lbl_80564D90 : limit;
    result = limit * lbl_80564D94;
    return lbl_80564D84 + result;
}
#pragma dont_inline reset

extern u32 lbl_802FABA0[];
float fn_802BF02C(float x, int unused) {
    /* Sample the fixed 7-point (x,y) curve from lbl_802FABA0 at x: find the first segment whose
       upper x exceeds x, clamp the segment fraction to [0,1], and linearly interpolate y. */
    struct Pair { float x, y; } points[7];
    register u32 *src = lbl_802FABA0;
    register u32 *dst = (u32 *)points;
    register struct Pair *p;
    register int i;
    float lowX, highX, numerator, lowY, highY, denominator;
    register float min, t;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst = *src;
    p = points + 1;
    i = 1;
    for (; i <= 6; ++p, ++i) {
        if (p->x > x) {
            min = lbl_80564D80;
            highX = points[i].x;
            lowX = points[i - 1].x;
            highY = points[i].y;
            numerator = x - lowX;
            lowY = points[i - 1].y;
            denominator = highX - lowX;
            t = numerator / denominator;
            min = (min < t) ? min : t;
            min = (min > lbl_80564D90) ? min : lbl_80564D90;
            return lowY + min * (highY - lowY);
        }
    }
    return points[6].y;
}

extern unsigned int lbl_802FABD8[], lbl_802FAC00[];
extern float lbl_8055FAF8, lbl_80564D98, lbl_80564D80, lbl_80564D90, lbl_80564DA8, lbl_80564DAC;
extern double lbl_80564DA0;
extern float fn_802BEFB4(void);
extern float fn_801E7E24(void);
extern double fn_8002EFB4(double, double);
extern double cos(double);
extern void fn_802C9648(float);
extern void gxSetTexCoordMtxFlag(void);
extern float fn_802BF02C(float, int);
extern void fn_802C9900(float);
extern void gxLoadTexMtx(void *, int);
extern void DrawModelInstance(int);
extern void fn_802C9904(void);
extern void gxClearTexCoordMtxFlag(void);
extern void DrawList_reapplyProjection(void);
#pragma scheduling invalid_target
#pragma processor 750
void fn_802BF160(void) {
    unsigned int scratch[17];
    register unsigned int *table;
    register volatile float *point;
    register unsigned int *src;
    register unsigned int i;
    register float f27, f28, f29, f30, f31;
    register float f2, f0, f1, f3, f5, f4;
    register unsigned int m3, m5, m7, m0, m1, m2, m4, m6;
    float elapsed, rate;

    if (lbl_8055CF6C == -1) return;
    elapsed = fn_802BEFB4();
    rate = fn_801E7E24();
    lbl_8055FAF8 += elapsed * rate;
    src = lbl_802FABD8;
    scratch[8] = *src++; scratch[9] = *src++; scratch[10] = *src++;
    scratch[11] = *src++; scratch[12] = *src++; scratch[13] = *src++;
    scratch[14] = *src++; scratch[15] = *src++; scratch[16] = *src;
    fn_802C9648(lbl_80564D98);
    gxSetTexCoordMtxFlag();

    f31 = lbl_80564D80;
    f30 = lbl_80564DA8;
    point = (volatile float *)(scratch + 8);
    table = lbl_802FAC00;
    f29 = lbl_80564DAC;
    f28 = lbl_80564D90;
    i = 0;
    do {
        f1 = lbl_8055FAF8;
        f0 = point[2];
        f1 = f1 + f0;
        f27 = (float)fn_8002EFB4((double)f1, lbl_80564DA0);
        f1 = f27;
        f2 = (float)cos((double)f1);
        f0 = point[0];
        f1 = f31 - f0;
        f0 = f2 - f30;
        f2 = f0 * f29;
        if (f31 < f2) f2 = f31;
        f2 = (f2 > f28) ? f2 : f28;
        f3 = point[0];
        f0 = f1 - f28;
        m3 = table[3];
        f1 = f27;
        f5 = f31 / f3;
        m5 = table[5];
        m7 = table[7];
        m0 = table[0];
        m1 = table[1];
        f2 = f2 * f0;
        m2 = table[2];
        f0 = -f5;
        m4 = table[4];
        m6 = table[6];
        f4 = f28 + f2;
        scratch[3] = m3;
        f2 = point[1];
        scratch[5] = m5;
        f3 = f4 + f3;
        f4 = f0 * f4;
        scratch[7] = m7;
        f0 = f31 - f3;
        scratch[0] = m0;
        scratch[1] = m1;
        f0 = f5 * f0;
        scratch[2] = m2;
        f0 = f31 + f0;
        scratch[4] = m4;
        f0 = f0 - f4;
        scratch[6] = m6;
        ((volatile float *)scratch)[3] = f2;
        ((volatile float *)scratch)[5] = f0;
        ((volatile float *)scratch)[7] = f4;
        fn_802C9900(fn_802BF02C(f27, (int)m6));
        gxLoadTexMtx(0, (int)scratch);
        DrawModelInstance(lbl_8055CF6C);
        ++i;
        point += 3;
    } while (i < 3);
    fn_802C9904();
    gxClearTexCoordMtxFlag();
    DrawList_reapplyProjection();
}
void fn_802BF350(void) {
    // Initializes the water system: resets state, populates per-instance handles, logs activation, and caches an asset handle.
    int i;
    fn_802BEDFC();
    lbl_8055FADC = fn_801E85AC();
    for (i = 0; i < lbl_8055FADC; i++) {
        lbl_804C07F0[i] = (void *)fn_802C00A4();
        if (i == 0 && lbl_804C07F0[i] != 0) {
            fn_802E30C8(lbl_8034AD78);
        }
    }
    if (fn_8012C33C(lbl_8055CF68) != 0) {
        lbl_8055CF6C = fn_802C6FC0(lbl_8055CF68, 0, 0);
    } else {
        lbl_8055CF6C = -1;
    }
}

#pragma cplusplus on
extern "C" void fn_802BF40C(void) {
    /* Tear down all active water instances (virtual destroy), clear the instance
     * table/count, and release the cached water asset handle if valid. */
    class Obj {
    public:
        virtual void f0(int);
    };
    int i;
    void *obj;
    int handle;
    for (i = 0; i < lbl_8055FADC; i++) {
        obj = lbl_804C07F0[i];
        if (obj != 0) {
            if (obj != 0) {
                ((Obj *)obj)->f0(1);
            }
            lbl_804C07F0[i] = 0;
        }
    }
    handle = lbl_8055CF6C;
    lbl_8055FADC = 0;
    if (handle != -1) {
        fn_802C6CF8(handle);
        lbl_8055CF6C = -1;
    }
}
#pragma cplusplus reset
int fn_802BF4B0(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

int fn_802BF4F0(void) {
    /* Return nonzero when the water/splash effect instance table is present (the splash system is active). */
    return (int)(unsigned int)lbl_804C07F0 != 0;
}

#pragma cplusplus on
extern "C" void fn_802BF508(void) {
    /* If the current slot has an object and the feature flag is set, invoke its virtual callback with a temporary context override, then run common post-processing. */
    class SlotObject {
    public:
        virtual void dtor0();
        virtual void dtor1();
        virtual void onUpdate();
    };
    int slotIndex = fn_801E85B4();
    if (lbl_804C07F0[slotIndex] != 0 && lbl_8055CF70 != 0) {
        int previousState = fn_802C2C00(0);
        SlotObject *slotObject = (SlotObject *)lbl_804C07F0[slotIndex];
        slotObject->onUpdate();
        fn_802C2C00(previousState);
    }
    fn_802BF160();
}
#pragma cplusplus reset
/* Returns the water surface height (world Y), the "gen_surf" scale loaded at
   startup (default 0.7) that callers compare against to test submersion. */
float fn_802BF590(void) { return lbl_8055FAF4; }

#pragma cplusplus on
/* Invoke virtual method 1 on the current slot's object, if one is present. */
extern "C" void fn_802BF598(int param, float value) {
    class Dummy {
    public:
        virtual void f0();
        virtual void f1(int, float);
    };
    int slotIndex = fn_801E85B4();
    Dummy *slotObject = (Dummy *)lbl_804C07F0[slotIndex];
    if (slotObject != 0) {
        slotObject->f1(param, value);
    }
}

extern float lbl_80564DA8;
extern float lbl_80564DB0;
#pragma scheduling invalid_target
extern "C" void fn_802BF600(void *arg0, void *dst, void *src)
{
  extern float lbl_80564DA8;
  extern float lbl_80564DB0;
  extern float lbl_8055FAE0;
  int t4 = *((int *) (((char *) src) + 4));
  int t1c = *((int *) (((char *) src) + 0x1C));
  int t10 = *((int *) (((char *) src) + 0x10));
  int t28 = *((int *) (((char *) src) + 0x28));
  float f10;
  float f4;
  float scale;
  float f1c;
  float f28;
  float s4;
  float s10;
  float s1c;
  float s28;
  int i2c;
  int i24;
  int i20;
  int i18;
  int i14;
  int ic;
  int i8;
  int i0;
  scale = lbl_80564DA8;
  *((int *) (4 + ((char *) dst))) = t4;
  *((int *) (((char *) dst) + 0x10)) = t10;
  *((int *) (((char *) dst) + 0x1C)) = t1c;
  *((int *) (((char *) dst) + 0x28)) = t28;
  f4 = *((float *) (((char *) dst) + 4));
  f10 = *((float *) (((char *) dst) + 0x10));
  f1c = *((float *) (((char *) dst) + 0x1C));
  f28 = *((float *) (((char *) dst) + 0x28));
  s4 = f4 * scale;
  ;
  s1c = f1c * scale;
  ;
  i0 = *((int *) (((char *) src) + 0));
  i8 = *((int *) (((char *) src) + 8));
  ic = *((int *) (((char *) src) + 0xC));
  i14 = *((int *) (((char *) src) + 0x14));
  i18 = *((int *) (((char *) src) + 0x18));
  i20 = *((int *) (((char *) src) + 0x20));
  i24 = *((int *) (((char *) src) + 0x24));
  i2c = *((int *) (((char *) src) + 0x2C));
  *((int *) (((char *) dst) + 0)) = i0;
  *((int *) (((char *) dst) + 8)) = i8;
  *((int *) (((char *) dst) + 0xC)) = ic;
  *((int *) (((char *) dst) + 0x14)) = i14;
  *((int *) (((char *) dst) + 0x18)) = i18;
  *((int *) (((char *) dst) + 0x20)) = i20;
  *((int *) (((char *) dst) + 0x24)) = i24;
  *((int *) (((char *) dst) + 0x2C)) = i2c;
  *((float *) (((char *) dst) + 4)) = s4;
  *((float *) (((char *) dst) + 0x10)) = f10 * scale;
  *((float *) (0x1C + ((char *) dst))) = s1c;
  *((float *) (((char *) dst) + 0x28)) = f28 * scale;
  *((float *) (((char *) dst) + 0x28)) += lbl_80564DB0 * lbl_8055FAE0;
}
#pragma scheduling reset
extern "C" void *fn_802BF780(void *);
#pragma dont_inline on
extern "C" int fn_802BF6AC(void) {
    /* Allocate and construct a water-env-map object; if initialization fails (f2() == 0), delete it and return NULL. */
    struct Dummy {
        virtual ~Dummy();
        virtual int f0();
        virtual int f1();
        virtual int f2();
    };
    extern void *fn_801284F8(int, const char *);
    extern const char lbl_8034AD90[];
    Dummy *obj = (Dummy *)fn_801284F8(0x18, lbl_8034AD90);
    if (obj != 0) {
        obj = (Dummy *)fn_802BF780(obj);
    }
    if (obj != 0) {
        if (obj->f2() == 0) {
            delete obj;
            obj = 0;
        }
    }
    return (int)obj;
}
#pragma dont_inline reset
#pragma scheduling on
#pragma cplusplus reset
extern void *fn_801284F8(int, const char*);
extern const char lbl_8034AD90[];
extern void* lbl_804C07F0[];
extern float lbl_80564DA8, lbl_80564DB0, lbl_8055FAE0;
int fn_802BF740(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

/* One cube face of the environment map: its model matrix. */
struct EnvFace {
    float mtx[12];
};
/* A corner of the quad drawn into a face. */
struct EnvVertex {
    float position[3];
    int color;
    float uv[2];
};
/* The cube-face table every water object shares (0x1B8 bytes, lbl_8055FB00,
   reference count lbl_8055FAFC). */
struct EnvFaces {
    int targets[6];           /* 0x00 one 256x256 render target per face */
    int sunTexture;           /* 0x18 "env_sun.tex" */
    struct EnvFace faces[6];  /* 0x1C */
    struct EnvVertex quad[4]; /* 0x13C */
    unsigned short indices[6]; /* 0x19C */
    unsigned char facesCleared; /* 0x1A8 */
};
/* The water environment-map object itself (0x18 bytes). */
struct WaterEnvMap {
    void *vtable;           /* 0x00 lbl_8034AE40 */
    struct EnvFaces *faces; /* 0x04 shared cube-face table */
    int target;             /* 0x08 this surface's own 256x256 target */
    int worldModel;         /* 0x0C "worldmodel.mod" instance */
    int envModel;           /* 0x10 "wenv_mod.mod" instance */
    float fovFactor;        /* 0x14 field-of-view widening factor */
};
#define sEnvFaces       lbl_8055FB00 /* the one shared EnvFaces, built on first use */
#define sEnvFacesRef    lbl_8055FAFC /* its reference count */

#pragma push
#pragma use_lmw_stmw off
/* WaterEnvMap constructor (fn_802BF6AC allocates the 0x18 bytes): make this
 * water surface's own 256x256 render target, load the "worldmodel.mod" and
 * "wenv_mod.mod" instances it draws, and, for the first water object only,
 * build the shared EnvFaces table (lbl_8055FB00, reference count
 * lbl_8055FAFC) -- six 256x256 cube-face render targets with identity model
 * matrices except the rotations each face needs, the "env_sun.tex" sun
 * billboard texture, a unit quad with colour and texture corners, and its
 * index list -- then hand the table to the object. */
void *fn_802BF780(void *self) {
    char *strings = lbl_8034ACA0; /* the file names this object loads */
    register float one, neg, zero;
    float zeroConst;
    float oneConst;
    char *table;
    register void *sunPath;
    register int i;
    register int *targetPtr;
    register char *mtxPtr;
    register char *tailPtr;
    void *worldPath;
    void *envPath;

    ((struct WaterEnvMap *)self)->vtable = lbl_8034AE40;
    ((struct WaterEnvMap *)self)->target = fn_802CB128(0x100, 0x100, 0, 0);
    worldPath = strings + 0xFC; /* "worldmodel.mod" */
    if (fn_8012C33C(worldPath) != 0) {
        ((struct WaterEnvMap *)self)->worldModel = fn_802C6FC0((int)worldPath, 0, 0);
    } else {
        ((struct WaterEnvMap *)self)->worldModel = -1;
    }
    envPath = strings + 0x10C; /* "wenv_mod.mod" */
    if (fn_8012C33C(envPath) != 0) {
        ((struct WaterEnvMap *)self)->envModel = fn_802C6FC0((int)envPath, 0, 0);
    } else {
        ((struct WaterEnvMap *)self)->envModel = -1;
    }
    if (sEnvFacesRef == 0) {
        table = (char *)fn_801284F8(0x1B8, lbl_8055CF84); /* "skybox" heap */
        if (table != 0) {
            sunPath = strings + 0x11C; /* "env_sun.tex" */
            if (fn_8012C33C(sunPath) != 0) {
                ((struct EnvFaces *)table)->sunTexture = fn_802CAC28(sunPath, 0);
            } else {
                ((struct EnvFaces *)table)->sunTexture = -2;
            }
            oneConst = lbl_80564D80;  /* 1.0f */
            targetPtr = (int *)table;
            zeroConst = lbl_80564D90; /* 0.0f */
            tailPtr = table;
            mtxPtr = table + 0x1C;
            i = 0;
            do { /* one render target and identity model matrix per cube face */
                *targetPtr = fn_802CB128(0x100, 0x100, 0, 0x60);
                i += 1;
                (*(float *)((char *)(mtxPtr) + (0))) = oneConst;
                targetPtr += 1;
                (*(float *)((char *)(mtxPtr) + (4))) = zeroConst;
                (*(float *)((char *)(mtxPtr) + (8))) = zeroConst;
                (*(float *)((char *)(mtxPtr) + (0xC))) = zeroConst;
                (*(float *)((char *)(mtxPtr) + (0x10))) = oneConst;
                (*(float *)((char *)(mtxPtr) + (0x14))) = zeroConst;
                (*(float *)((char *)(mtxPtr) + (0x18))) = zeroConst;
                (*(float *)((char *)(mtxPtr) + (0x1C))) = zeroConst;
                (*(float *)((char *)(mtxPtr) + (0x20))) = oneConst;
                mtxPtr += 0x30;
                (*(float *)((char *)(tailPtr) + (0x40))) = zeroConst;
                (*(float *)((char *)(tailPtr) + (0x44))) = zeroConst;
                (*(float *)((char *)(tailPtr) + (0x48))) = zeroConst;
                tailPtr += 0x30;
            } while (i < 6);
            zero = 0.0f; neg = -1.0f; one = 1.0f;
            /* the rotations that turn the camera towards each cube face */
            ((struct EnvFaces *)table)->faces[1].mtx[6] = zero;
            ((struct EnvFaces *)table)->faces[1].mtx[7] = zero;
            ((struct EnvFaces *)table)->faces[1].mtx[8] = neg;
            ((struct EnvFaces *)table)->faces[1].mtx[0] = neg;
            ((struct EnvFaces *)table)->faces[1].mtx[1] = zero;
            ((struct EnvFaces *)table)->faces[1].mtx[2] = zero;
            ((struct EnvFaces *)table)->faces[2].mtx[0] = zero;
            ((struct EnvFaces *)table)->faces[2].mtx[1] = zero;
            ((struct EnvFaces *)table)->faces[2].mtx[2] = neg;
            ((struct EnvFaces *)table)->faces[2].mtx[6] = one;
            ((struct EnvFaces *)table)->faces[2].mtx[7] = zero;
            ((struct EnvFaces *)table)->faces[2].mtx[8] = zero;
            ((struct EnvFaces *)table)->faces[3].mtx[0] = zero;
            ((struct EnvFaces *)table)->faces[3].mtx[1] = zero;
            ((struct EnvFaces *)table)->faces[3].mtx[2] = one;
            ((struct EnvFaces *)table)->faces[3].mtx[6] = neg;
            ((struct EnvFaces *)table)->faces[3].mtx[7] = zero;
            ((struct EnvFaces *)table)->faces[3].mtx[8] = zero;
            ((struct EnvFaces *)table)->faces[4].mtx[3] = zero;
            ((struct EnvFaces *)table)->faces[4].mtx[4] = zero;
            ((struct EnvFaces *)table)->faces[4].mtx[5] = neg;
            ((struct EnvFaces *)table)->faces[4].mtx[6] = zero;
            ((struct EnvFaces *)table)->faces[4].mtx[7] = one;
            ((struct EnvFaces *)table)->faces[4].mtx[8] = zero;
            ((struct EnvFaces *)table)->faces[5].mtx[3] = zero;
            ((struct EnvFaces *)table)->faces[5].mtx[4] = zero;
            ((struct EnvFaces *)table)->faces[5].mtx[5] = one;
            ((struct EnvFaces *)table)->faces[5].mtx[6] = zero;
            ((struct EnvFaces *)table)->faces[5].mtx[7] = neg;
            ((struct EnvFaces *)table)->faces[5].mtx[8] = zero;
            /* the unit quad (with texture corners) drawn into each face */
            ((struct EnvFaces *)table)->quad[0].position[0] = neg;
            ((struct EnvFaces *)table)->quad[0].position[1] = one;
            ((struct EnvFaces *)table)->quad[0].position[2] = one;
            ((struct EnvFaces *)table)->quad[0].color = -1;
            ((struct EnvFaces *)table)->quad[0].uv[0] = zero;
            ((struct EnvFaces *)table)->quad[0].uv[1] = zero;
            ((struct EnvFaces *)table)->quad[1].position[0] = one;
            ((struct EnvFaces *)table)->quad[1].position[1] = one;
            ((struct EnvFaces *)table)->quad[1].position[2] = one;
            ((struct EnvFaces *)table)->quad[1].color = -1;
            ((struct EnvFaces *)table)->quad[1].uv[0] = one;
            ((struct EnvFaces *)table)->quad[1].uv[1] = zero;
            ((struct EnvFaces *)table)->quad[2].position[0] = neg;
            ((struct EnvFaces *)table)->quad[2].position[1] = neg;
            ((struct EnvFaces *)table)->quad[2].position[2] = one;
            ((struct EnvFaces *)table)->quad[2].color = -1;
            ((struct EnvFaces *)table)->quad[2].uv[0] = zero;
            ((struct EnvFaces *)table)->quad[2].uv[1] = one;
            ((struct EnvFaces *)table)->quad[3].position[0] = one;
            ((struct EnvFaces *)table)->quad[3].position[1] = neg;
            ((struct EnvFaces *)table)->quad[3].position[2] = one;
            ((struct EnvFaces *)table)->quad[3].color = -1;
            ((struct EnvFaces *)table)->quad[3].uv[0] = one;
            ((struct EnvFaces *)table)->quad[3].uv[1] = one;
            ((struct EnvFaces *)table)->indices[0] = 0;
            ((struct EnvFaces *)table)->indices[1] = 1;
            ((struct EnvFaces *)table)->indices[2] = 2;
            ((struct EnvFaces *)table)->indices[3] = 1;
            ((struct EnvFaces *)table)->indices[4] = 2;
            ((struct EnvFaces *)table)->indices[5] = 3;
            ((struct EnvFaces *)table)->facesCleared = 0;
        }
        sEnvFaces = table;
    }
    sEnvFacesRef += 1;
    ((struct WaterEnvMap *)self)->faces = (struct EnvFaces *)sEnvFaces;
    ((struct WaterEnvMap *)self)->fovFactor = 1.0f;
    return self;
}
#pragma pop

extern void fn_802CB228(void *);
extern int lbl_8055FAFC;
extern void *lbl_8055FB00;
extern char lbl_8034AE40[];
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void *fn_802BFA58(void *object, int shouldDelete) {
    struct SharedTable {
        void *items[6];
        int value;
        void cleanup() {
            void **cur = items;
            int i = 0;
            do {
                fn_802CB228(*cur);
                cur++;
                i++;
            } while (i < 6);
            if (value != -2) {
                fn_802CAC54(value);
            }
            fn_80128668(this);
        }
    };
    int id;
    int handle;

    if (object != 0) {
        id = *(int *)((char *)object + 8);
        *(char **)object = lbl_8034AE40;
        if (id != -2) {
            fn_802CB228((void *)id);
            *(int *)((char *)object + 8) = -2;
        }
        handle = *(int *)((char *)object + 0xC);
        if (handle != -1) {
            fn_802C6CF8(handle);
            *(int *)((char *)object + 0xC) = -1;
        }
        handle = *(int *)((char *)object + 0x10);
        if (handle != -1) {
            fn_802C6CF8(handle);
            *(int *)((char *)object + 0x10) = -1;
        }
        if (*(int *)((char *)object + 4) != 0) {
            if (--lbl_8055FAFC == 0) {
                SharedTable *table = (SharedTable *)lbl_8055FB00;
                if (table != 0) {
                    table->cleanup();
                }
                lbl_8055FB00 = 0;
            }
            *(int *)((char *)object + 4) = 0;
        }
        if (shouldDelete > 0) {
            fn_80128668(object);
        }
    }
    return object;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* WaterEnvMap's virtual render method (vtable lbl_8034AE40, slot 1): draws the
 * environment that every water surface reflects.  The six 256x256 render
 * targets shared by all water objects (lbl_8055FB00) hold one cube face each
 * and are cleared the first time through; the camera is then mirrored in the
 * water plane, its field of view widened for split-screen, and a quad is
 * rendered into each face from the camera position, followed by the sun
 * billboard and the world and water-environment models. */
extern "C" void fn_802BFB70(void *arg0, float *worldMtx, float angle) {
#define kOne lbl_80564D80       /* 1.0f */
#define kZero lbl_80564D90      /* 0.0f */
#define kWideFovFactor lbl_80564DB4 /* 1.5f, two-player split screen */
#define kHalf lbl_80564DAC      /* 0.5f */
#define kTwo lbl_80564DB0       /* 2.0f */
#define kFaceFar lbl_80564DB8   /* 2000.0f */
#define kFaceFov lbl_80564DBC   /* pi/2 */
#define kViewFar lbl_80564DC0   /* 3000.0f */
#define kSunNear lbl_80564DC4   /* 0.1f */
#define kSplashRadius lbl_80564DC8 /* 300.0f */
    /* View-matrix builder, vtable slot 5 (fn_802BF600): mirrors the world matrix
       in the water plane. */
    class ViewBuilder {
    public:
        virtual void unused0();
        virtual void unused1();
        virtual void unused2();
        virtual void unused3();
        virtual void unused4();
        virtual void buildView(float *out, float *world, float *up);
    };
    float savedView[3], savedViewport[4], up[3], savedViewport0[4], savedView0[3], savedViewSun[3], sunFov;
    float viewMtx[12], savedMtx[12], savedMtx0[12], faceMtx[12];
    struct WaterEnvMap *self = (struct WaterEnvMap *)arg0;
    struct EnvFaces *faces;
    float fovAngle;
    self->fovFactor = fn_801E85A4() == 2 ? kWideFovFactor : kOne;
    faces = self->faces;
    if (!faces->facesCleared) {
        int faceIndex;
        struct EnvFace *face = faces->faces;
        int *target = faces->targets;
        for (faceIndex = 0; faceIndex < 6; faceIndex++, target++, face++) {
            Texture_BindRenderTarget(*target); fn_802C9294(*target, 0);
            DrawList_saveProjection(savedView0, kOne, kFaceFar, kFaceFov);
            DrawList_saveViewport(savedViewport0, 0, 0, 0x100, 0x100);
            DrawList_copyCurrentMatrix(savedMtx0); DrawList_loadMatrix(face); fn_802C88BC(3); fn_802C10C8();
            fn_802C9294(-2, 0); DrawList_loadMatrix(savedMtx0); DrawList_restoreViewport(savedViewport0, -1); DrawList_restoreProjection(savedView0, -1);
        }
        faces->facesCleared = 1;
    }
    Texture_BindRenderTarget(self->target); fn_802C9294(self->target, 1);
    up[0] = kZero; up[1] = kOne; up[2] = kZero;
    ((ViewBuilder *)arg0)->buildView(viewMtx, worldMtx, up);
    fovAngle = kTwo * (float)atan(self->fovFactor * (float)fn_8002EF30(kHalf * angle));
    DrawList_saveProjection(savedView, kOne, kViewFar, fovAngle);
    DrawList_saveViewport(savedViewport, 0, 0, 0x100, 0x100);
    DrawList_copyCurrentMatrix(savedMtx); DrawList_loadMatrix(viewMtx); fn_802C88BC(2);
    if (self->faces) {
        int *target;
        struct EnvFace *face;
        struct EnvFaces *faceTable;
        struct { int count; } counter;
        int &i = counter.count;
        sunFov = fovAngle; faceTable = self->faces;
        ((void (*)(float *))fn_802C00A0)(&sunFov);
        DrawList_saveProjection(savedViewSun, kSunNear, kTwo, sunFov);
        target = faceTable->targets; face = faceTable->faces;
        for (i = 0; i < 6; i++, face++, target++) {
            fn_80144DC8(faceMtx); fn_802C0054(faceMtx, face);
            fn_80144DAC(faceMtx + 9, viewMtx + 9);
            fn_802C8B98(*target, faceMtx);
            fn_802C8DB8(&faceTable->quad[0], 4, faceTable->indices, 6); DrawList_RestoreNormalMode();
        }
        fn_802BFE48(faceTable, viewMtx, kOne); DrawList_restoreProjection(savedViewSun, -1);
    }
    DrawModelInstance(self->worldModel);
    if (fn_801E85A4() == 1) fn_802BDD8C(kSplashRadius);
    if (self->envModel != -1) DrawModelInstance(self->envModel);
    fn_802C9294(-2, 0); DrawList_loadMatrix(savedMtx); DrawList_restoreViewport(savedViewport, -1); DrawList_restoreProjection(savedView, -1);
#undef kOne
#undef kZero
#undef kWideFovFactor
#undef kHalf
#undef kTwo
#undef kFaceFar
#undef kFaceFov
#undef kViewFar
#undef kSunNear
#undef kSplashRadius
}
#pragma pop

#pragma cplusplus reset
extern float lbl_80564DCC, lbl_80564DD0, lbl_80564DD4;
extern const unsigned short lbl_802FAC20[6];
extern void fn_80015A20(void *, float *);
extern void fn_80015B20(float *, void *, float *);
extern void fn_802C8B98(int, float *);
extern void fn_802C8DB8(void *, int, unsigned short *, int);
extern void DrawList_RestoreNormalMode(void);
#pragma scheduling invalid_target
void fn_802BFE48(void *arg0, void *arg1, float arg2) {
    if (*(int *)((char *)arg0 + 0x18) != -2) {
        struct V { float x, y, z; int color; float u, v; } v[4];
        float matbuf[12];
        float rot[9];
        struct Idx { unsigned short a[6]; } idx;
        float vec[3];
        float x = lbl_80564DCC * arg2;
        float *mat = matbuf;
        register int i;
        struct V *p;
        float m11, m10, m9;
        idx = *(const struct Idx *)lbl_802FAC20;
        for (p = v, i = 0; i < 4; i++, p++) {
            p->x = (i & 1) ? x : -x;
            p->y = (i & 2) ? x : -x;
            p->z = lbl_80564DD0 * arg2;
            p->u = (i & 1) ? lbl_80564D80 : lbl_80564D90;
            p->v = (i & 2) ? lbl_80564D80 : lbl_80564D90;
            p->color = -1;
        }
        m9 = ((float *)arg1)[9];
        m10 = ((float *)arg1)[10];
        m11 = ((float *)arg1)[11];
        mat[9] = m9;
        mat[10] = m10;
        mat[11] = m11;
        mat[0] = lbl_80564D80; mat[1] = lbl_80564D90; mat[2] = lbl_80564D90; mat[3] = lbl_80564D90;
        mat[4] = lbl_80564D80; mat[5] = lbl_80564D90; mat[6] = lbl_80564D90; mat[7] = lbl_80564D90;
        mat[8] = lbl_80564D80;
        vec[0] = lbl_80564DD4; vec[1] = lbl_80564D90; vec[2] = lbl_80564D90;
        fn_80015A20(rot, vec);
        fn_80015B20(mat, rot, mat);
        fn_802C8B98(*(int *)((char *)arg0 + 0x18), mat);
        fn_802C8DB8(v, 4, idx.a, 6);
        DrawList_RestoreNormalMode();
    }
}
void fn_802C0054(void *dst, const void *src) {
    /* Copy a 36-byte block (9 32-bit words) from src to dst. */
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

void fn_802C00A0(void) {
    /* Empty no-op: called as a hook to adjust the sun's view FOV (passed as a
     * float*), but this build leaves the value untouched. */
}

extern void *fn_801284F8(int, const char *);
extern void *fn_802C0138(void *);
extern char lbl_8034ADC8[];
#pragma cplusplus on
extern "C" int fn_802C00A4(void) {
    /* Creates a water quad object and initializes it if valid */
    class WaterQuad {
    public:
        virtual void SetFlag(int);
        virtual void fn_0x4();
        virtual void fn_0x8();
        virtual int GetState();
    };
    extern void *fn_801284F8(int, const char *);
    extern void *fn_802C0138(void *);
    extern char lbl_8034ADC8[];
    WaterQuad *obj = (WaterQuad *)fn_801284F8(0x2c60, lbl_8034ADC8);
    if (obj != 0) {
        obj = (WaterQuad *)fn_802C0138(obj);
    }
    if (obj != 0) {
        if (obj->GetState() == 0) {
            if (obj != 0) {
                obj->SetFlag(1);
            }
            obj = 0;
        }
    }
    return (int)obj;
}
#pragma cplusplus reset
void *fn_802C0138(void *arg0) {
    register char *resourceB;
    register char *resourceA;
    void *vtable = lbl_8034AE08;
    float initial = lbl_80564DF0;
    short *out;
    register int row;
    register int rowBase;
    int innerBase;
    int zero = 0;

    *(unsigned char *)((char *)arg0 + 0x2C5C) = zero;
    *(void **)arg0 = vtable;
    resourceA = lbl_8034ACA0 + 0x134;
    *(int *)((char *)arg0 + 0x2C50) = -2;
    resourceB = lbl_8034ACA0 + 0x144;
    *(int *)((char *)arg0 + 0x2C54) = -2;
    *(int *)((char *)arg0 + 0x2C58) = zero;
    lbl_8055FB04 = initial;
    if (fn_8012C33C(lbl_8034ACA0 + 0x154, 0, vtable, lbl_8034ACA0) == 0)
        return arg0;
    if (fn_8012C33C(resourceA) != 0)
        *(int *)((char *)arg0 + 0x2C50) = fn_802CAC28(resourceA, 0);
    *(int *)((char *)arg0 + 0x2C58) = fn_802BF6AC();
    if (fn_8012C33C(resourceB) != 0)
        *(int *)((char *)arg0 + 0x2C54) = fn_802CAC28(resourceB, 0);

    out = (short *)((char *)arg0 + 4);
    row = 0;
    rowBase = 0;
    do {
        int r7 = (row + 1) << 4;
        int r6 = r7;
        int count;
        innerBase = 0;
        for (count = 0; count < 3; count++) {
            int r4 = innerBase + rowBase;
            int r3 = r4;
            int r9;
            int r8;
            int r10;
            int r12;
            int r29;
            int r11;
            int r30;
            out[0] = r4;
            r3 = r3 + 1;
            out[1] = r3;
            r9 = innerBase + r7;
            r8 = innerBase + r7;
            out[2] = r6;
            r11 = r9;
            r30 = r9;
            out[3] = r6;
            r8 = r8 + 1;
            r10 = r4 + 2;
            out[4] = r3;
            r12 = r4 + 3;
            r29 = r4 + 4;
            out[5] = r8;
            r11 = r11 + 3;
            r30 = r30 + 4;
            out[6] = r3;
            r3 = r9;
            r9 = r9 + 2;
            out[7] = r10;
            r4 = r4 + 5;
            r3 = r3 + 5;
            out[8] = r8;
            r6 = r6 + 5;
            innerBase = innerBase + 5;
            out[9] = r8;
            out[10] = r10;
            out[11] = r9;
            out[12] = r10;
            out[13] = r12;
            out[14] = r9;
            out[15] = r9;
            out[16] = r12;
            out[17] = r11;
            out[18] = r12;
            out[19] = r29;
            out[20] = r11;
            out[21] = r11;
            out[22] = r29;
            out[23] = r30;
            out[24] = r29;
            out[25] = r4;
            out[26] = r30;
            out[27] = r30;
            out[28] = r4;
            out[29] = r3;
            out += 30;
        }
        row++;
        rowBase += 16;
    } while (row < 63);
    *(unsigned char *)((char *)arg0 + 0x2C5C) = 1;
    return arg0;
}

extern char lbl_8034AE08[];
#pragma cplusplus on
extern "C" void *fn_802C0310(void *self, int shouldFree) {
    class Obj {
    public:
        virtual void v0(int);
    };
    int resourceId;
    void *child;
    /* Destructor-like cleanup: reset vtable, release owned resources, optionally free. */
    if (self != 0) {
        resourceId = *(int *)((char *)self + 0x2c50);
        *(void **)self = lbl_8034AE08;
        if (resourceId != -2) fn_802CAC54(resourceId);
        resourceId = *(int *)((char *)self + 0x2c54);
        if (resourceId != -2) fn_802CAC54(resourceId);
        child = *(void **)((char *)self + 0x2c58);
        if (child != 0) {
            if (child != 0)
                ((Obj *)child)->v0(1);
        }
        if (shouldFree > 0) fn_80128668(self);
    }
    return self;
}
#pragma cplusplus off
#pragma cplusplus on
extern "C" void fn_802C03B4(void *self) {
    class Child {
    public:
        virtual void v0();
        virtual void v1();
    };
    /* If a child is attached and the global trigger flag is set, invoke the
     * child's vtable slot-0xC method. */
    void *child = *(void **)((char *)self + 0x2c58);
    if (child == 0)
        return;
    if (lbl_8055CF71 == 0)
        return;
    ((Child *)child)->v1();
}
#pragma cplusplus off

#pragma push
#pragma peephole off
/* Repack a packed 32-bit color word's component bytes (byte rotate used by the
   pixel-format conversion routines in this file). */
int fn_802C03E0(unsigned int color) {
    unsigned int middle = __rlwinm(color, 8, 8, 23);
    unsigned int outer = (color << 8) & 0xFF0000FF;
    return middle | outer;
}

extern float lbl_80564DF4, lbl_80564E00, lbl_80564E04, lbl_80564E08;
extern double lbl_80564DF8;
extern int fn_802DD42C(int, float);
extern void DrawList_getViewParams(float *, float *, float *, float *, float);
extern double fn_8002F234(double, double);
extern float fn_802C9C50(void);
extern float fn_802C9C40(void);
extern float fn_802C9C38(void);
extern float fn_802C9C48(void);
extern void fn_802BED90(float *);
extern int fn_80147C50(int, int, float);
extern void fn_802C8E70(void *, float *, float, float, float, float);
extern void PSVECCrossProduct(float *, float *, float *);
extern float lbl_80564E0C, lbl_80564E10, lbl_80564E14, lbl_80564E18;
extern void fn_802DBE4C(float, float, float);
extern float fn_801E7E18(int, int, int, int, int, int, int);
extern int lbl_802FAC30[], lbl_802FAC50[];
extern float lbl_8055CF74, lbl_80564DD8;
extern double lbl_80564DE0;
extern float lbl_80564E1C, lbl_80564E20, lbl_80564E24, lbl_80564E28, lbl_80564D78;
extern void fn_802C8BD0(int), fn_802DBECC(void);
extern int CpuLight_BeginIndirectPass(int, int, int, int, float, float);
extern void fn_802DD27C(void *, int, void *, int), CpuLight_EndIndirectPass(void);
extern void fn_802C03F0(void *arg0) {
    float s[0x83];
    float f0, f1, f2, f14;
    double d200;
    void **vo;
    int r27, r28, r26, r29;
    unsigned char *verts;
    float t23, t25, t8, t6, t5_2, t4, t2_2, t3_2, t1_4, t13, t6_2, t9;
    float t10, t11, t8_2, t5_3, t4_2, t30, v1;
    float t4_3, t3_3, t2_3, t1_5, t0, t0_2, t0_3, t0_4;
    int r0;
    unsigned char *r25;
    int vr, i;
    float f8, f7, f5_4, f6_4, f3_4, f4_4, f2_4, f8_3;
    unsigned short idx[6];
    float *q;
    DrawList_copyCurrentMatrix(&s[84]);
    f14 = s[94] - lbl_8055FAF4;
    DrawList_getViewParams(&s[5], &s[3], &s[4], &s[2], s[94]);
    f2 = lbl_80564DF4 * s[4];
    s[126] = f14 * s[91];
    s[127] = s[3];
    f1 = (float)fn_8002F234(lbl_80564DF8, lbl_80564DF4);
    s[5] *= f1;
    verts = (unsigned char *)(int)fn_802DD42C(0x6000, f1);
    (void)fn_802C9C50();
    (void)fn_802C9C40();
    (void)fn_802C9C38();
    vo = *(void ***)((char *)arg0 + 0x2C58);
    (void)fn_802C9C48();
    f14 = ((float (*)(void *))((void **)vo[0])[6])(vo);
    f0 = lbl_80564E00 / (f14 * lbl_80564DF4);
    s[60] = s[90]; s[61] = s[91]; s[62] = s[92];
    if ((float)fabs(s[91]) < lbl_80564E04) {
        s[60] = s[92]; s[61] = s[93]; s[62] = s[94];
    } else {
        s[60] = s[87]; s[61] = s[88]; s[62] = s[89];
    }
    s[61] = lbl_80564D90;
    f1 = PSVECMag(&s[60]);
    f2 = lbl_80564E08;
    if (f2 > f1) f2 = f1;
    f1 = lbl_80564D80 / f2;
    f0 = s[60] * f1;
    s[15] = lbl_80564D90;
    s[16] = lbl_80564D80;
    s[62] = s[62] * f1;
    s[61] = s[61] * f1;
    s[60] = f0;
    s[17] = lbl_80564D90;
    PSVECCrossProduct(&s[60], &s[15], &s[57]);
    t23 = lbl_80564DAC * lbl_80564E00;
    t25 = lbl_80564DAC * lbl_80564E14;
    d200 = (double)(f2 - s[127]);
    r27 = 0;
    r28 = 0;
    do {
        s[55] = s[94];
        s[55] = lbl_8055FAF4;
        s[54] = s[93];
        s[56] = s[95];
        if (r27 == 0x3F) s[55] = s[94];
        t8 = s[127] + ((((float)r27 / lbl_80564E0C) * ((float)r27 / lbl_80564E0C)) * (float)d200) + s[126];
        t6 = s[54] + (s[60] * t8);
        t5_2 = s[55] + (s[61] * t8);
        t4 = s[56] + (s[62] * t8);
        t2_2 = t5_2 - s[94];
        t3_2 = t6 - s[93];
        t1_4 = t4 - s[95];
        s[54] = t6;
        t13 = t2_2 * s[88];
        t6_2 = t2_2 * s[91];
        t9 = t3_2 * s[90];
        s[55] = t5_2;
        t10 = t1_4 * s[89];
        t11 = (t1_4 * s[86]) + ((t3_2 * s[84]) + (t2_2 * s[85]));
        t8_2 = (t3_2 * s[87]) + t13;
        s[56] = t4;
        t5_3 = t1_4 * s[92];
        t4_2 = t10 + t8_2;
        s[51] = t11;
        t30 = t5_3 + (t9 + t6_2);
        s[52] = t4_2;
        s[53] = t30;
        s[48] = t3_2;
        s[49] = t2_2;
        s[50] = t1_4;
        fn_802BED90(&s[48]);
        v1 = lbl_80564D80 - -s[49];
        if (lbl_80564D80 < v1) v1 = lbl_80564D80;
        if (v1 < (float)(double)lbl_80564D90) v1 = (float)(double)lbl_80564D90;
        r29 = fn_802C03E0(fn_80147C50(lbl_8055FAE4, lbl_8055FAE8, v1 * v1));
        r26 = 0;
        do {
            r0 = (r26 + r28) * 0x18;
            r25 = verts + r0;
            t4_3 = (((lbl_80564DB0 * (float)r26) / lbl_80564E10) - lbl_80564D80) * t30;
            t3_3 = s[5] * t4_3;
            t2_3 = s[54] + (s[57] * t3_3);
            t1_5 = s[55] + (s[58] * t3_3);
            t0 = s[56] + (s[59] * t3_3);
            *(float *)(verts + r0) = t2_3;
            *(float *)(r25 + 4) = t1_5;
            *(float *)(r25 + 8) = t0;
            s[45] = t2_3; s[46] = t1_5; s[47] = t0;
            *(int *)(r25 + 0xC) = r29;
            fn_802C8E70(r25, &s[42], t1_5, t2_3, t3_3, t4_3);
            r26++;
            t0_2 = ((s[42] - r29) + t23) / lbl_80564E00;
            t0_3 = lbl_80564DAC + ((t0_2 - lbl_80564DAC) * f0);
            t0_4 = lbl_80564DAC + (lbl_80564E18 * (((((s[43]) + t25) / lbl_80564E14) - lbl_80564DAC) * f0));
            *(float *)(r25 + 0x10) = t0_3;
            *(float *)(r25 + 0x14) = t0_4;
        } while (r26 < 0x10);
        r27++;
        r28 += 0x10;
    } while (r27 < 0x40);
    s[39] = s[93];
    s[7] = lbl_80564D90;
    s[11] = s[95];
    fn_802DBE4C(s[93], s[95], lbl_80564D90);
    for (i = 0; i < 8; i++) s[64 + i] = (float)lbl_802FAC30[i];
    s[67] = (float)fn_8002EFB4(lbl_80564DD8 * fn_801E7E18(lbl_802FAC30[6], lbl_802FAC30[5], lbl_802FAC30[4], lbl_802FAC30[3], lbl_802FAC30[2], lbl_802FAC30[1], lbl_802FAC30[0]), lbl_80564DE0);
    ((void (*)(int, void *))gxLoadTexMtx)(2, &s[64]);
    f1 = lbl_80564E1C * s[94];
    if (f1 > lbl_80564D80) {} else f1 = lbl_80564D80;
    r25 = (unsigned char *)(int)fn_80147C50(0, lbl_8055FAEC, lbl_80564D80 / f1);
    vo = *(void ***)((char *)arg0 + 0x2C58);
    ((void (*)(void **))((void **)vo[0])[4])(vo);
    fn_802C8BD0(-1);
    vo = *(void ***)((char *)arg0 + 0x2C58);
    vr = ((int (*)(void **))((void **)vo[0])[4])(vo);
    CpuLight_BeginIndirectPass(vr, *(int *)((char *)arg0 + 0x2C54), *(int *)((char *)arg0 + 0x2C50), (int)r25, lbl_8055CF74, lbl_80564D80 / (lbl_80564E20 * lbl_80564D78));
    fn_802DD27C(verts, 0x400, (char *)arg0 + 4, 0x1626);
    CpuLight_EndIndirectPass();
    DrawList_RestoreNormalMode();
    fn_802DBECC();
    DrawList_copyCurrentMatrix(&s[72]);
    ((void (*)(float *, float *, float *, float *))DrawList_getViewParams)(&s[0], &s[1], &s[0], &s[0]);
    f8 = lbl_80564D7C;
    s[1] = s[1] + f8;
    s[36] = s[81] + (s[78] * s[1]);
    s[37] = s[82] + (s[79] * s[1]);
    s[38] = s[83] + (s[80] * s[1]);
    if (f8 > s[76]) {} else f8 = s[76];
    s[31] = s[79];
    f8_3 = (lbl_8055FAF4 - s[37]) / f8;
    f7 = s[75] * f8_3;
    f5_4 = s[76] * f8_3;
    f6_4 = s[36] + f7;
    f3_4 = s[77] * f8_3;
    s[30] = s[75];
    f4_4 = s[37] + f5_4;
    f2_4 = s[38] + f3_4;
    s[33] = f6_4;
    s[34] = f4_4;
    s[35] = f2_4;
    s[32] = s[80];
    s[31] = lbl_80564D90;
    s[12] = lbl_80564D90;
    s[13] = lbl_80564D80;
    s[14] = lbl_80564D90;
    PSVECCrossProduct(&s[12], &s[30], &s[27]);
    {
        int ctr = 4;
        for (i = 0; i < 6; i++) idx[i] = ((unsigned short *)lbl_802FAC50)[i];
        s[24] = s[33] + (s[27] * lbl_80564E24);
        s[25] = s[34] + (s[28] * lbl_80564E24);
        s[26] = s[35] + (s[29] * lbl_80564E24);
        s[23] = s[35] + (s[29] * lbl_80564E28);
        s[21] = s[33] + (s[27] * lbl_80564E28);
        s[22] = s[34] + (s[28] * lbl_80564E28);
        q = &s[96];
        do {
            float *a = (i & 1) ? &s[21] : &s[24];
            float u = (i & 2) ? lbl_80564E24 : lbl_80564D90;
            q[0] = a[0] + (s[75] * u);
            q[4] = a[4] + (s[76] * u);
            q[8] = a[8] + (s[77] * u);
            q[0x14] = lbl_80564D90;
            q[0x10] = lbl_80564D90;
            *(int *)&q[0xC] = lbl_8055FAF0;
            i++;
            q += 6;
        } while (--ctr != 0);
    }
    fn_802C8BD0(-1);
    fn_802C8DB8(&s[96], 4, idx, 6);
    DrawList_RestoreNormalMode();
}

#pragma pop
/* Getter: returns the 32-bit field at offset 0x8 of the given object (one of the
 * tiny accessors of this module, alongside fn_802C0CA0's float field at 0x14). */
int fn_802C0C98(void *object) { return *(int *)((char *)object + 8); }

/* Getter: returns the float field at offset 0x14 of the given object. */
float fn_802C0CA0(void *object) { return *(float *)((char *)object + 0x14); }

int fn_802C0CA8(void) {
#define ALWAYS_AVAILABLE 1
    /* Predicate method on this UI object: always reports available so callers proceed. */
    int available = ALWAYS_AVAILABLE;
    return available;
}

/* Destructor-like cleanup: installs lbl_8034AE20 vtable, releases the ref-counted/owned handle at offset +4 when valid, and optionally frees the object. */
void *fn_802C0CB0(void *object, int shouldDelete) {
    int ownedHandle;
#define VTable_8034AE20 lbl_8034AE20
#define ReleaseHandle fn_802CAC54
#define FreeObject fn_80128668

    if (object != 0) {
        ownedHandle = *(int *)((char *)object + 4);
        *(char **)object = VTable_8034AE20;
        if (ownedHandle != -2) {
            ReleaseHandle(ownedHandle);
        }
        if (shouldDelete > 0) {
            FreeObject(object);
        }
    }
    return object;
#undef VTable_8034AE20
#undef ReleaseHandle
#undef FreeObject
}

/* No-op method (vtable slot +0xC of lbl_8034AE20) on the ref-counted-handle
 * object class; does nothing in this build. */
void fn_802C0D20(void) {
}

/* Getter: returns the owned handle stored at offset +4 of the given object. */
int fn_802C0D24(void *object) {
    return *(int *)((char *)object + 4);
}

/* Constant getter: returns 1.0f (the original keeps it as a .sdata2 float, lbl_80564D80). */
float fn_802C0D2C(void) {
    return 1.0f;
}

unsigned int fn_802C0D34(void) {
#define ENABLED_FLAG 1
    /* Constant-valued getter: reports the enabled flag so callers treat this object as active. */
    unsigned int enabled = ENABLED_FLAG;
    return enabled;
}

/* Return the WaterQuad object's initialization-state byte (0 = setup incomplete, 1 = initialized). */
unsigned char fn_802C0D3C(void *object) {
    return *((unsigned char *)object + 0x2C5C);
}

extern int fn_801E85AC(void);
extern int fn_802C00A4(void);
extern int fn_8012C33C();
extern int fn_802C6FC0(int, int, int);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034AD78[];
extern int lbl_8055CF68;
extern void fn_801E866C(int);
extern void *fn_801EA9A0(void);
extern float lbl_80564D80, lbl_80564D84, lbl_80564D88, lbl_80564D8C;
extern float lbl_80564D90, lbl_80564D94;
