// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* A model part's pose as the part draw calls take it: a 3x3 rotation and scale
 * followed by the translation, twelve floats in all.  Mirroring a part (the
 * other side of a vehicle) negates its first axis, the first three floats. */
typedef struct { float values[12]; } PartPose;
typedef struct { float rot[9]; } PartPoseRot;
typedef struct { float pos[3]; } PartPosePos;
extern void fn_802C70AC(int, void *, int, int);
extern int fn_802C7A34(int, void *, int, float);
extern float *fn_802C86DC();
extern float lbl_80562E98;
extern float lbl_80562E90;
void fn_801ECF58(void *);
void fn_801ECFE0(void *);
void fn_801ED2D0(void *);
void fn_801ED354(void *);
#pragma cplusplus on
struct Unk_801EEA64Iface {
    virtual Unk_801EEA64Iface *m8(char *);
    virtual int mC(char *);
    virtual int m10(char *);
    virtual int m14(char *);
    virtual int m18(char *);
    virtual int m1C(char *);
};
#pragma cplusplus reset
extern long lbl_80488648[]; /* up to 8 live vehicle render objects, by render slot */
extern char lbl_8033A300[];
extern char lbl_8033A0B0[];
__declspec(section ".sdata") extern char lbl_8055AFEC[];
__declspec(section ".sdata") extern char lbl_8055AFF4[];
void fn_801EE974(void *, void *);
void fn_801EEA64(void *, void *, int, int);
void *fn_801E87A8(void);
void fn_801EDD7C(void *, long);
long fn_80179CB0(void);
void fn_801EECAC(long, long);
void fn_802C6CF8(long);

#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_80128668(void*);
void fn_801E323C(void);
void fn_801ECCE0(long, long);
long fn_801E866C(long);
long fn_801E89C8(long);
float fn_802C99E8(void *, float);
void fn_801ED718(void *);
void fn_801ECC70(void *);
float fn_801F159C(long);
long fn_80201018(long, void *, long);
long fn_801ECB60();
extern unsigned int lbl_8055EBC8;
void fn_801F131C(void *, long, void *, float);
void fn_801EFC90(long, long, void *);
extern float lbl_80488668[3]; /* saved render state; [2] = draw scale */
extern unsigned int lbl_8055EBC8;
long fn_801ECB60();
extern float lbl_80558DC4[];
/* UI default light colours (packed RGB): muted blue-gray diffuse and warm
 * cream ambient, used as the saved render state for the vehicle effect pass. */
#define UI_LIGHT_DIFFUSE_MODE0 0x00555766
#define UI_LIGHT_AMBIENT 0x00FFF5D9
void fn_801EC1D4(void) {
    /* Seed the saved render state with the UI's default light colours: a muted
     * blue-gray diffuse and a warm cream ambient, applied (and later restored)
     * around the vehicle-render effect pass in fn_801ECCE0. */
    ((unsigned int *)lbl_80488668)[0] = UI_LIGHT_DIFFUSE_MODE0;
    ((unsigned int *)lbl_80488668)[1] = UI_LIGHT_AMBIENT;
}

void *fn_801EC1F8(void) {
    /* Return the base of the saved UI render-state block: [0]/[1] hold the packed diffuse/ambient light colours and [2] the draw scale. */
    return lbl_80488668;
}

/* Pointer to the saved ambient-light colour slot (lbl_80488668[1]) of the UI render state. */
void *fn_801EC204(void) {
    return &lbl_80488668[1];
}

extern double fn_8002EFB0(float,float);
extern void fn_801345D8(void *,int,const char *,...);
extern int fn_801E3004(int,const char *,int);
extern void fn_802E317C(const char *,...);
extern float lbl_80562E88;
extern char lbl_8033A060[];
__declspec(section ".sdata") extern char lbl_8055AFCC[];
__declspec(section ".sdata") extern char lbl_8055AFD4[];
extern int sscanf(const char *,...);
#pragma cplusplus on
#pragma processor 750
extern "C" void fn_801EC214(void *outp, void *obj, int arg2, char *name, int arg4, float f1, float f2) {
    struct GaugePoint {
        float pos;
        float angle;
    };
    struct Gauge {
        int handle;
        float first;
        float last;
        GaugePoint points[8];
        int count;
        int id;
    } *out = (Gauge *)outp;
    char *base = lbl_8033A060;
    float a, b, c, d;
    char buf[0x20];
    GaugePoint *entry;
    float scale;
    float zero;
    float nd;
    float t;
    out->id = arg4;
    if (!((Unk_801EEA64Iface *)obj)->mC(name)) {
        out->handle = 0;
        return;
    }
    a = lbl_80562E88;
    b = lbl_80562E88;
    if (sscanf((char *)((Unk_801EEA64Iface *)obj)->m14(name), lbl_8055AFCC, &a, &b) != 2)
        fn_802E317C(base, name);
    out->handle = fn_801E3004(arg2, name, -1);
    scale = f1 - f2;
    zero = lbl_80562E88;
    for (out->count = 0; out->count < 8; out->count++) {
        fn_801345D8(buf, 0x20, lbl_8055AFD4, name, out->count + 1);
        if (!((Unk_801EEA64Iface *)obj)->mC(buf))
            break;
        entry = &out->points[out->count];
        c = zero;
        d = zero;
        if (sscanf((char *)((Unk_801EEA64Iface *)obj)->m14(buf), base + 0x10, &entry->pos, &c, &d) != 3)
            fn_802E317C(base + 0x1C, buf);
        nd = -(d - b);
        entry->angle = (float)fn_8002EFB0(c - a, nd);
        t = entry->pos * scale;
        entry->pos = t + f2;
    }
    if (out->count < 2)
        fn_802E317C(base + 0x34, name);
    out->first = out->points[0].pos;
    out->last = out->points[out->count - 1].pos;
}
#pragma cplusplus reset

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448
/* Destructor for J3DUMtxAnmCacheTableBase: if it holds a cache object pointer,
 * free it via fn_801E323C, then delete this object when shouldDelete > 0. */
long __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448(long this_, long shouldDelete) {
    if (this_ != 0) {
        long cache = *(long *)this_;
        if (cache != 0) {
            ((void (*)(long))fn_801E323C)(cache);
        }
        if (shouldDelete > 0) fn_80128668((void *)this_);
    }
    return this_;
}
#pragma pop
void fn_801E353C(long, float);
void fn_801E34E4(void *, long);
#pragma push
#pragma scheduling invalid_target
void fn_801EC4A8(void *arg0, long arg1) {
    char *p;
    long object;
    long i, count;
    char *a, *b;
    float lower, value, upper;
    float x, y, nextY;
    object = *(long *)arg0;
    if (object != 0) {
        value = *(float *)((char *)arg0 + 8);
        upper = **(float **)((char *)arg0 + 0x50);
        lower = *(float *)((char *)arg0 + 4);
        value = value < upper ? value : upper;
        value = value > lower ? value : lower;
        p = arg0;
        i = 0;
        count = *(long *)((char *)arg0 + 0x4C) - 2;
        for (; count > 0; count--) {
            if (*(float *)(p + 0x14) > value) break;
            p += 8;
            i++;
        }
        a = (char *)arg0 + i * 8;
        b = (char *)arg0 + (i + 1) * 8;
        x = *(float *)(a + 0xC);
        y = *(float *)(a + 0x10);
        nextY = *(float *)(b + 0x10);
        fn_801E353C(object, -(y + (nextY - y) * ((value - x) / (*(float *)(b + 0xC) - x))));
        fn_801E34E4(*(void **)arg0, arg1);
    }
}

#pragma cplusplus on
union Vec3 {
    struct { float x, y, z; } f;
    unsigned int u[3];
};
struct Parent {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20();
    virtual void *get(int);
};
struct Property {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10();
    virtual Vec3 getVector(char *);
};
extern "C" {
static inline void *fn_801EC59C_parent_get(void *parent, int index) {
    return ((Parent *)parent)->get(index);
}
static inline void fn_801EC59C_property_get(void *out, void *property, char *label) {
    *(Vec3 *)out = ((Property *)property)->getVector(label);
}
}
#pragma cplusplus reset
void fn_801EC59C(void *out, void *parent, int index, int value, float scale, float bias) {
    extern char lbl_8055AFDC, lbl_8055AFE4;
    extern float lbl_80562E88, lbl_80562E8C;
    typedef union { struct { float x, y, z; } f; unsigned int u[3]; } Vec3;
    register void *result;
    Vec3 first, second;
    float dx, dy, slopeX, slopeY, x0, x1, y0, y1;

    *(volatile int *)out = value;
    result = fn_801EC59C_parent_get(parent, index);
    if (result != 0) {
        fn_801EC59C_property_get(&first, result, &lbl_8055AFDC);
        fn_801EC59C_property_get(&second, result, &lbl_8055AFE4);
        x0 = first.f.x * scale - bias;
        x1 = second.f.x * scale - bias;
        y0 = first.f.y * lbl_80562E8C;
        y1 = second.f.y * lbl_80562E8C;
        dx = x0 - x1;
        dy = first.f.z * lbl_80562E8C - second.f.z * lbl_80562E8C;
        slopeX = (y1 - y0) / dx;
        slopeY = dy / dx;
        *(float *)((char *)out + 4) = slopeX;
        *(float *)((char *)out + 0xC) = slopeY;
        *(float *)((char *)out + 8) = y0 - slopeX * x1;
        *(float *)((char *)out + 0x10) = first.f.z * lbl_80562E8C - slopeY * x1;
    } else {
        *(float *)((char *)out + 0x10) = lbl_80562E88;
        *(float *)((char *)out + 0xC) = lbl_80562E88;
        *(float *)((char *)out + 8) = lbl_80562E88;
        *(float *)((char *)out + 4) = lbl_80562E88;
    }
}
#pragma pop
#define EvalLinearCurve2D fn_801EC714 /* evaluate a 2D slope/intercept curve at an input value */
void fn_801EC714(void *arg0, float *outX, float *outY) {
    /* Evaluate a 2D linear curve: each output is its intercept plus the input value times its slope. */
    typedef struct {
        float *input;     /* 0x00 pointer to the input value */
        float slopeX;     /* 0x04 */
        float interceptX; /* 0x08 */
        float slopeY;     /* 0x0C */
        float interceptY; /* 0x10 */
    } LinearCurve2D;
    LinearCurve2D *curve = (LinearCurve2D *)arg0;
    *outX = curve->interceptX + (*curve->input * curve->slopeX);
    *outY = curve->interceptY + (*curve->input * curve->slopeY);
}

extern void *fn_801EAB2C(void);
extern void fn_8012E81C(char *);
extern int fn_802792E4(char *);
extern void fn_801EA59C(int, int, void *);
extern void fn_801EAB80(void *, void *);
extern void *fn_80016474(int, long *);
extern void fn_801333E8(int, void *, void *);
extern void fn_801EE0E0(void *, char *, int, int, char *);
#pragma push
#pragma dont_inline on
void *fn_801EC750(char *a0, char *a1, char *a2) {
    char sp48[0x40];
    char sp8[0x40];
    int var;
    int t;
    char c;
    char *src;
    int n;
    char *dst;
    char c2;
    char *src2;
    int n2;
    char *dst2;
    fn_801EAB2C();
    *(int *)(a0 + 0x18C) = 0;
    *(void **)a0 = lbl_8033A300;
    *(int *)(a0 + 0x1DC) = 0;
    *(int *)(a0 + 0x1E0) = 0;
    *(int *)(a0 + 0x230) = 0;
    *(int *)(a0 + 0x234) = 0;
    *(int *)(a0 + 0x284) = 0;
    *(int *)(a0 + 0x288) = 0;
    *(int *)(a0 + 0x2D8) = 0;
    *(int *)(a0 + 0x2DC) = 0;
    *(int *)(a0 + 0x32C) = 0;
    *(int *)(a0 + 0x330) = 0;
    *(int *)(a0 + 0x380) = 0;
    *(int *)(a0 + 0x384) = 0;
    *(int *)(a0 + 0x3D4) = 0;
    *(int *)(a0 + 0x3C) = 0;
    t = *(int *)(a1 + 0xE0);
    *(int *)(a0 + 0x40) = t;
    if (t == 0)
        fn_801EC1D4();
    src = a2 + 0x44;
    dst = sp48;
    n = 0x40;
    goto body1;
test1:
    if (--n > 0)
        goto body1;
    dst[-1] = 0;
    goto done1;
body1:
    c = *src++;
    *dst++ = c;
    if (c != 0)
        goto test1;
done1:
    dst2 = sp48;
    n2 = 0x40;
    src2 = lbl_8055AFEC;
    while (*dst2 != 0) {
        n2--;
        dst2++;
    }
    if (n2 > 0) {
        goto body2;
test2:
        if (--n2 > 0)
            goto body2;
        dst2[-1] = 0;
        goto done2;
body2:
        c2 = *src2++;
        *dst2++ = c2;
        if (c2 != 0)
            goto test2;
    }
done2:
    fn_8012E81C(sp48);
    *(int *)(a0 + 0x188) = fn_802792E4(a2 + 0x44);
    fn_801EA59C(*(int *)(a1 + 0xE0), 0, a2);
    {
        int idx = *(int *)(a2 + 0x68);
        *(void **)(a0 + 0x16C) = a0 + 0x84;
        *(void **)(a0 + 0x170) = a0 + 0xC8;
        *(void **)(a0 + 0x174) = a0 + 0x148;
        if (idx >= 0)
            var = *(int *)(a1 + 0xE0);
        else
            var = 0;
    }
    fn_801345D8(sp8, 0x40, lbl_8055AFF4, a2 + 0x44);
    fn_801EE0E0(a0, a2 + 0x44, *(int *)(a2 + 0x6C), var, sp8);
    fn_801EE974(a0, a1);
    fn_801EEA64(a0, a1, (int)(a2 + 0x44), (int)sp8);
    lbl_80488648[*(int *)(a0 + 0x40)] = (long)a0;
    *(int *)(a1 + 0xE4) = *(int *)(a0 + 0x48);
    t = *(int *)((char *)fn_80016474(*(int *)(a2 + 0x68), lbl_80488648) + 0x50);
    *(int *)(a0 + 0x3EC) = t;
    *(int *)(a1 + 0xE8) = t;
    fn_801EAB80(a0, a1);
    *(char *)(a0 + 0x3F4) = 1;
    if ((unsigned)(*(int *)a1 - 0x50430000) == 0x4152)
        fn_801333E8(1, lbl_8033A0B0, a0 + 0x3F4);
    if ((unsigned)(*(int *)a1 - 0x50430000) == 0x4152 &&
        (unsigned)(*(int *)((char *)fn_801E87A8() + 4) - 0x180000) == 0x304)
        lbl_8055EBC8 = (unsigned int)a0;
    return a0;
}
extern char lbl_8033A300[];
extern void fn_801EEC68(void *);
extern void fn_801EFFF8(long);
extern void fn_801EF428(long, long);
extern void fn_8020095C(long);
extern void fn_802792EC(long);
extern long __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448(long, long);
#pragma dont_inline on
void *fn_801EC9CC(void *arg0, int arg1) {
    int i;
    char *entry;
    long value;

    /* Destructor-like cleanup: release owned resources/subobjects and optionally delete storage. */
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033A300;
        fn_801EEC68(arg0);

        entry = arg0;
        for (i = 0; i < *(int *)((char *)arg0 + 0x148); i++) {
            *(int *)(entry + 0x84) = -1;
            fn_802C6CF8(*(long *)(entry + 0x44));
            entry += 4;
        }

        entry = arg0;
        for (i = 0; i < *(int *)((char *)arg0 + 0x480); i++) {
            fn_802C6CF8(*(long *)(entry + 0x400));
            entry += 8;
        }

        fn_802C6CF8(*(long *)((char *)arg0 + 0x178));
        ((void (*)(long))fn_801E323C)(*(long *)((char *)arg0 + 0x17C));
        ((void (*)(long))fn_801E323C)(*(long *)((char *)arg0 + 0x180));
        fn_8020095C(*(long *)((char *)arg0 + 0x184));

        entry = arg0;
        for (i = 0; i < 4; i++) {
            value = *(long *)(entry + 0x4D4);
            fn_801EFFF8(value);
            *(long *)(entry + 0x4D4) = 0;
            entry += 4;
        }

        lbl_80488648[*(long *)((char *)arg0 + 0x40)] = 0;
        fn_801EF428(*(long *)((char *)arg0 + 0x3F0), 1);
        fn_802792EC(*(long *)((char *)arg0 + 0x188));
        *(long *)((char *)arg0 + 0x188) = 0;
        if (lbl_8055EBC8 == (unsigned int)arg0) lbl_8055EBC8 = 0;

        __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x384), -1);
        __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x330), -1);
        __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x2DC), -1);
        __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x288), -1);
        __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x234), -1);
        __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x1E0), -1);
        __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x18C), -1);

        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

/* 1 when the vehicle render object's owner data (+0x3C) still has its +0x2D4
 * float above the global threshold lbl_80558DC4 (0x34 in .sdata, so any
 * positive value passes). */
long fn_801ECB60(void *vehicleRender) {
    return *(float *)(*(char **)((char *)vehicleRender + 0x3C) + 0x2D4) > *(float *)&lbl_80558DC4;
}

#pragma pop
float fn_802C88D4(void *);
float fn_801E88F0(long);
#pragma scheduling on
/* Pick an index for a vehicle render object: scale the value derived from its +0x28
 * quaternion, find the first +0x170 threshold above it, and store the clamped index
 * at +0x3F8 (respecting the minimum at +0x3FC and the table count at +0x174). */
void fn_801ECB80(void *vehicleRender) {
    float amount;
    long *levelCount;
    long byteOffset;
    long index;
    amount = fn_802C88D4((char *)vehicleRender + 0x28);
    amount *= fn_801E88F0(-1);
    levelCount = *(long **)((char *)vehicleRender + 0x174);
    index = 0;
    byteOffset = 0;
    *(long *)((char *)vehicleRender + 0x3F8) = *levelCount - 1;
    for (; index < *levelCount; byteOffset += 8, index++) {
        if (amount < *(float *)(*(char **)((char *)vehicleRender + 0x170) + byteOffset)) {
            *(long *)((char *)vehicleRender + 0x3F8) = index;
            break;
        }
    }
    if (*(long *)((char *)vehicleRender + 0x3F8) < *(long *)((char *)vehicleRender + 0x3FC))
        *(long *)((char *)vehicleRender + 0x3F8) = *(long *)((char *)vehicleRender + 0x3FC);
    if (*(long *)((char *)vehicleRender + 0x3F8) >= **(long **)((char *)vehicleRender + 0x174))
        *(long *)((char *)vehicleRender + 0x3F8) = **(long **)((char *)vehicleRender + 0x174) - 1;
    if (*(long *)((char *)vehicleRender + 0x40) == fn_801E866C(-1)) {
        long chosen = *(long *)((char *)vehicleRender + 0x3F8);
        *(long *)((char *)vehicleRender + 0x3F8) = chosen > 1 ? 1 : chosen;
    }
}
/* Apply the vehicle owner's draw scale, scaled by the saved global draw scale,
 * through fn_802C99E8; vehicleRender+0x3C points to that owner. */
void fn_801ECC70(void *vehicleRender) {
    void *owner = *(void **)((char *)vehicleRender + 0x3C);
    fn_802C99E8(owner, lbl_80488668[2] * *(float *)((char *)owner + 0x2CC));
}
#pragma dont_inline reset

#pragma pop

#pragma scheduling invalid_target
long fn_801ECC8C(unsigned int vehicleRender) {
    /* Which update group a vehicle render object (the pointers kept in the
     * lbl_80488648[] table) belongs to: 1 for the ones that take the
     * per-player effect pass of fn_801ECCE0 (called there with key 0) - the
     * player's own car, remembered in lbl_8055EBC8 when the 'PCAR' object is
     * created, plus any vehicle whose owner data (+0x3C) still has the float
     * at +0x2D4 above the global threshold lbl_80558DC4 - and 0 for the plain
     * ones (key 1). */
    long usesEffect = 0;
    if (fn_801ECB60((void *)vehicleRender) != 0 || vehicleRender == lbl_8055EBC8)
        usesEffect = 1;
    return usesEffect;
}

#pragma dont_inline on
void fn_801ECCE0(long renderObj, long pass) {
    void *otherVehicles[8];
    void *selected;
    unsigned selectedIndex;
    int i, count;
    int savedState0, savedState1;
    unsigned objectGroup;
    if (*(int *)(renderObj + 0x40) != 0) return;
    for (i = 0; lbl_80488648[i] != 0 && i < 8; i++) {
        if ((unsigned)pass != fn_801ECC8C(lbl_80488648[i])) fn_801ECB80((void *)lbl_80488648[i]);
    }
    selectedIndex = fn_801E866C(-1);
    selected = selectedIndex < 8 ? (void *)lbl_80488648[selectedIndex] : 0;
    count = 0;
    for (i = 0; lbl_80488648[i] != 0 && i < 8; i++) {
        if ((void *)lbl_80488648[i] != selected) {
            otherVehicles[count] = (void *)lbl_80488648[i];
            count++;
        }
    }
    lbl_80488668[2] = ((float (*)(float))fn_802C99E8)(lbl_80562E90);
    savedState0 = fn_802C9950(((int *)lbl_80488668)[0]);
    savedState1 = fn_802C9994(((int *)lbl_80488668)[1]);
    {
        int k;
        for (k = 0; k < count; k++) {
            void *vehicle = otherVehicles[k];
            objectGroup = fn_801ECC8C((long)vehicle);
            if (objectGroup != (unsigned)pass) {
                if (objectGroup != 0) fn_802AB770(*(int *)((char *)vehicle + 0x40));
                fn_801ECF58(vehicle);
                if (objectGroup != 0) fn_802AB994();
            }
        }
    }
    {
        int k;
        for (k = 0; k < count; k++) {
            void *vehicle = otherVehicles[k];
            objectGroup = fn_801ECC8C((long)vehicle);
            if (objectGroup != (unsigned)pass) {
                if (objectGroup != 0) fn_802AB770(*(int *)((char *)vehicle + 0x40));
                fn_801ECFE0(vehicle);
                if (objectGroup != 0) fn_802AB994();
            }
        }
    }
    {
        int k;
        for (k = 0; k < count; k++) {
            void *vehicle = otherVehicles[k];
            objectGroup = fn_801ECC8C((long)vehicle);
            if (objectGroup != (unsigned)pass) {
                if (objectGroup != 0) fn_802AB770(*(int *)((char *)vehicle + 0x40));
                fn_801ED2D0(vehicle);
                if (objectGroup != 0) fn_802AB994();
            }
        }
    }
    objectGroup = fn_801ECC8C((long)selected);
    if (objectGroup != (unsigned)pass) {
        if (objectGroup != 0) fn_802AB770(*(int *)((char *)selected + 0x40));
        fn_801ED354(selected);
        if (objectGroup != 0) fn_802AB994();
    }
    ((float (*)(float))fn_802C99E8)(lbl_80488668[2]);
    fn_802C9994(savedState1);
    fn_802C9950(savedState0);
}
void fn_801ECF58(void *arg0) {
    long useAltFlag;
    char *entryBase;
    long ownerPtr;
    long entryIndex;
    char *entry;
    /* If object+0x184 is set, compute a flag from the indexed entry (+0x170/+0x3F8) and owner
       state (+0x3C, bit 0x100 at +0x2C0 clear => flag 1), run fn_801ECC70, then call fn_80201018. */
    if (*(long *)((char *)arg0 + 0x184) != 0) {
        useAltFlag = 0;
        entryIndex = *(long *)((char *)arg0 + 0x3F8);
        entryBase = *(char **)((char *)arg0 + 0x170);
        entry = entryBase + entryIndex * 8;
        if (*(unsigned char *)(entry + 5) != 0) {
            ownerPtr = *(long *)((char *)arg0 + 0x3C);
            if ((*(long *)(ownerPtr + 0x2C0) & 0x100) == 0)
                useAltFlag = 1;
        }
        fn_801ECC70(arg0);
        fn_80201018(*(long *)((char *)arg0 + 0x184), *(void **)((char *)arg0 + 0x3C), useAltFlag);
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801ECFE0(void *vehicleRender) {
    /* Draw the parts of one vehicle.  Nothing is drawn while the model this
     * object renders (vehicleRender+0x3C) is scaled below ModelDrawMin.  The
     * object keeps a list of part entries at +0x154, *(+0x150) of them, three
     * words each: the first and the last of the 12-byte names the part is built
     * from in the model's name table, and the part bits the entry covers.  For
     * each entry a part key is made from that name plus the two words of
     * keyParams, and every group of the model whose bits still meet what is to
     * be drawn is submitted with the group's own pose - mirrored, that is with
     * its first axis negated, when the render state says this vehicle is drawn
     * the other way round.  The bits a group drew come off the list as it goes,
     * and whatever is left once all the groups have had their say is submitted
     * again with the vehicle's own pose (+0x4A0) unless SkipRestOfParts is set.
     * fn_801ECC70 sets the model's draw scale for the pass and fn_801ED46C
     * submits what it leaves over. */
    extern void *fn_801E87A8(void);   /* the render state's flags block */
    extern void fn_801ED46C(void *);
    extern void fn_802DAC54(void);
    extern int fn_802C7A40(int, void *, int, int, void *, int);
    extern void fn_802C70AC(int, void *, int, int);
    extern float lbl_80562E94, lbl_80562E98;
    extern unsigned char lbl_8055E614;
    extern long lbl_8055EBC0;

    #define Model           (*(char **)(self + 0x3C)) /* the model being drawn */
    #define ModelDrawMin    lbl_80562E94    /* 0.01f: a model below this is skipped */
    #define MirrorScale     lbl_80562E98    /* -1.0f: what flips a mirrored pose */
    #define ZeroEps         *(float *)&lbl_80558DC4 /* 1.19e-7: near enough to zero */
    #define SkipRestOfParts lbl_8055E614    /* set: leave the bits no group drew */
    #define PartKeyParam    lbl_8055EBC0    /* the second word of every part key */
    #define SetDrawScale    fn_801ECC70     /* this model's scale for the pass */
    #define ResetPartKeys   fn_802DAC54     /* start the part-key arena over */
    #define NewPartKey      fn_802C7A40     /* a key: a part name and two words */
    #define DrawPart        fn_802C70AC     /* a part, with its pose and its bits */
    #define DrawLeftOver    fn_801ED46C     /* what the pass leaves over */

    struct PartName { char name[12]; };
    /* the model's part-name table, twelve-byte names from +0x2E0 on */
    struct PartNames { char pad[0x2E0]; struct PartName name[1]; };
    PartPose partPose, ownPose;
    long keyParams[2];
    float mirrorScale;
    long *entry;
    long keyParam, groupOffset, mirrored, i, mask, partKey, j;
    char *group;
    char *scan;
    char *self = vehicleRender;
    if (!(*(float *)(Model+0x22C) < ModelDrawMin)) {
        SetDrawScale(self);
        mirrored = (*(unsigned long *)((char *)fn_801E87A8()+0x10) >> 1) & 1;
        entry = (long *)(self+0x154);
        keyParam = PartKeyParam;
        mirrorScale = MirrorScale;
        for (i=0; i<*(long *)(self+0x150); entry+=3, i++) {
            mask = *(long *)(Model+0x29C) & entry[2];
            keyParams[0] = *(long *)(self+0x3EC);
            keyParams[1] = keyParam;
            if ((float)__fabs((double)*(float *)(Model+0x28C)) <= ZeroEps)
                ResetPartKeys();
            partKey = NewPartKey(1, (void *)&((struct PartNames *)Model)->name[entry[0] + 1], entry[1]-entry[0], 1, keyParams, 2);
            for (j=0, groupOffset=0; j<*(long *)(Model+0xA78); groupOffset+=0x34, j++) {
                scan = Model+groupOffset;
                group = scan+0xA7C;
                if (*(long *)(scan+0xAAC) & mask) {
                    if (mirrored) {
                        *(PartPoseRot *)&partPose = *(PartPoseRot *)group;
                        *(PartPosePos *)((char *)&partPose+0x24) = *(PartPosePos *)(group+0x24);
                        partPose.values[0] *= mirrorScale;
                        partPose.values[1] *= mirrorScale;
                        partPose.values[2] *= mirrorScale;
                        DrawPart((*(int **)(self+0x16C))[*(long *)(self+0x3F8)], &partPose, partKey, *(long *)(group+0x30));
                    } else {
                        DrawPart((*(int **)(self+0x16C))[*(long *)(self+0x3F8)], group, partKey, *(long *)(scan+0xAAC));
                    }
                    mask &= ~*(long *)(group+0x30);
                }
            }
            if (!SkipRestOfParts) {
                if (mirrored) {
                    *(PartPoseRot *)&ownPose = *(PartPoseRot *)(self+0x4A0);
                    *(PartPosePos *)((char *)&ownPose+0x24) = *(PartPosePos *)(self+0x4A0+0x24);
                    ownPose.values[0] *= mirrorScale;
                    ownPose.values[1] *= mirrorScale;
                    ownPose.values[2] *= mirrorScale;
                    DrawPart((*(int **)(self+0x16C))[*(long *)(self+0x3F8)], &ownPose, partKey, mask);
                } else {
                    DrawPart((*(int **)(self+0x16C))[*(long *)(self+0x3F8)], self+0x4A0, partKey, mask);
                }
            }
        }
        DrawLeftOver(self);
    }
    #undef Model
    #undef ModelDrawMin
    #undef MirrorScale
    #undef ZeroEps
    #undef SkipRestOfParts
    #undef PartKeyParam
    #undef SetDrawScale
    #undef ResetPartKeys
    #undef NewPartKey
    #undef DrawPart
    #undef DrawLeftOver
}
#pragma pop

/* Updates 4 per-slot records for this object when the owner's selected entry matches the current one. */
void fn_801ED2D0(void *arg0) {
    long offset;
    char *current;
    long flagIsCurrent;
    long i;
    char *recordPtr;

    ((void (*)(void))fn_801ECC70)();
    flagIsCurrent = *(long *)((char *)arg0 + 0x40) == fn_801E866C(-1);
    i = 0;
    current = (char *)arg0;
    offset = 0;
    do {
        recordPtr = (char *)*(void **)((char *)arg0 + 0x3C) + offset;
        fn_801F131C(*(void **)(current + 0x4D4), flagIsCurrent, recordPtr,
                    *(float *)(recordPtr + 0xB0));
        i++;
        offset += 0x6C;
        current += 4;
    } while (i < 4);
}

extern long fn_801E8954(long);
extern long fn_801E897C(long);
extern void fn_801F1378(void *, void *, float);
extern void fn_801EDD68(void *);
extern unsigned char lbl_8055EBC4;
#pragma push
#pragma dont_inline on
/* Draw pass of the vehicle this object renders, for the player that was picked
 * out of the four: the two player mode flags (fn_801E8954 / fn_801E897C, bits 0
 * and 1 of the player entry's flag word) decide between submitting the
 * vehicle's parts, or dropping them and rebuilding the four wheel instances.
 * In both cases the wheels are pinned to a fixed level of detail here rather
 * than having theirs chosen by distance. */
void fn_801ED354(void *vehicleRender) {
    if (fn_801E8954(-1) != 0) {
        /* The player's vehicle: hand its parts in, then submit them. */
        fn_801ECF58(vehicleRender);
        fn_801ECFE0(vehicleRender);
        /* Byte 4 of the player's 8-byte entry (table +0x170, index +0x3F8): the
         * wheels are to stay on the nearest level of detail. */
        if (*(unsigned char *)((char *)*(void **)((char *)vehicleRender + 0x170) + *(int *)((char *)vehicleRender + 0x3F8) * 8 + 4) != 0) {
            char *slotBase;
            long recordOffset;
            int wheel;
            char *record;
            slotBase = (char *)vehicleRender;
            wheel = 0;
            recordOffset = 0;
            do {
                record = (char *)*(void **)((char *)vehicleRender + 0x3C) + recordOffset;
                fn_801F131C(*(void **)(slotBase + 0x4D4), 1, record, *(float *)(record + 0xB0));
                wheel++;
                recordOffset += 0x6C;
                slotBase += 4;
            } while (wheel < 4);
        }
    } else if (fn_801E897C(-1) != 0 || lbl_8055EBC4 != 0) {
        /* The vehicle is only being shown, not driven: reset the level-of-detail
         * scale, force every wheel to its first (nearest) model, and rebuild the
         * wheel instances from the vehicle's own data. */
        fn_801ECC70(vehicleRender);
        {
            long wheel;
            char *slotBase;
            long recordOffset;
            char *record;
            slotBase = (char *)vehicleRender;
            wheel = 0;
            recordOffset = 0;
            do {
                record = (char *)*(void **)((char *)vehicleRender + 0x3C) + recordOffset;
                fn_801F1378(*(void **)(slotBase + 0x4D4), record, *(float *)(record + 0xB0));
                wheel++;
                recordOffset += 0x6C;
                slotBase += 4;
            } while (wheel < 4);
        }
        fn_801EDD68(vehicleRender);
    }
}

#pragma push
#pragma scheduling invalid_target
/* Rotate the source vector from the current draw matrix (fn_802C86DC) by this
 * object's 3x3 matrix at +0x3C, write the result and its negation into two
 * indexed vec3 slots, then dispatch a draw callback using fn_802C7A34's handle. */
void fn_801ED46C(void *self) {
    float outVec[3];
    float *currentMatrix;
    float *rot;
    char *slot;
    if (*(int *)((char *)self + 0x488) != -1 && *(int *)((char *)self + 0x3F8) <= 2) {
        rot = *(float **)((char *)self + 0x3C);
        currentMatrix = fn_802C86DC();
        if (outVec == currentMatrix) {
            float x, y, z;
            float m00, m10, m20, m01, m11, m21, m02, m12, m22;
            m10 = rot[1];
            y = currentMatrix[1];
            m11 = rot[4]; m12 = rot[7];
            m00 = rot[0];
            x = currentMatrix[0];
            m01 = rot[3]; m02 = rot[6];
            m20 = rot[2];
            z = currentMatrix[2];
            m21 = rot[5]; m22 = rot[8];
            outVec[0] = z * m20 + (x * m00 + y * m10);
            outVec[1] = z * m21 + (x * m01 + y * m11);
            outVec[2] = z * m22 + (x * m02 + y * m12);
        } else {
            float m00, m10, m20, m01, m11, m21, m02, m12, m22;
            m10 = rot[1]; m00 = rot[0]; m20 = rot[2];
            outVec[0] = currentMatrix[2] * m20 + (currentMatrix[0] * m00 + currentMatrix[1] * m10);
            m11 = rot[4]; m01 = rot[3]; m21 = rot[5];
            outVec[1] = currentMatrix[2] * m21 + (currentMatrix[0] * m01 + currentMatrix[1] * m11);
            m12 = rot[7]; m02 = rot[6]; m22 = rot[8];
            outVec[2] = currentMatrix[2] * m22 + (currentMatrix[0] * m02 + currentMatrix[1] * m12);
        }
        slot = *(char **)((char *)self + 0x3C) + *(int *)((char *)self + 0x48C) * 0xC;
        *(float *)(slot + 0xE24) = outVec[0];
        *(float *)(slot + 0xE28) = outVec[1];
        *(float *)(slot + 0xE2C) = outVec[2];
        slot = *(char **)((char *)self + 0x3C) + *(int *)((char *)self + 0x490) * 0xC;
        {
            float scale = -1.0f;
            *(float *)(slot + 0xE24) = outVec[0] * scale;
            *(float *)(slot + 0xE28) = outVec[1] * scale;
            *(float *)(slot + 0xE2C) = outVec[2] * scale;
            {
                int handle = fn_802C7A34(1, *(char **)((char *)self + 0x3C) + 0xE30, *(int *)((char *)self + 0x494), scale);
                if (*(int *)((char *)self + 0x3F8) <= 1 && !(*(unsigned short *)(*(char **)((char *)self + 0x3C) + 0x6E) & 0x20)) {
                    fn_802C70AC(*(int *)((char *)self + 0x488), (char *)self + 0x4A0, handle, *(int *)((char *)self + 0x498));
                    return;
                }
                fn_802C70AC(*(int *)((char *)self + 0x488), (char *)self + 4, handle, *(int *)((char *)self + 0x49C));
            }
        }
    }
}
#pragma pop

/* Wrapper: run the plain/class-0 vehicle render pass (fn_801ECCE0 with group key 1). */
void fn_801ED68C(long renderObj) {
    fn_801ECCE0(renderObj, 1);
}

/* Wrapper: run the effect/class-1 vehicle render pass (fn_801ECCE0 with group key 0). */
void fn_801ED694(long renderObj) {
    fn_801ECCE0(renderObj, 0);
}

/* If this vehicle is the active camera target and the interior view flag is set,
   applies the vehicle's draw scale (+0x2CC), renders the interior parts via
   fn_801ED718, and restores the previous draw scale. */
void fn_801ED69C(void *vehicleRender) {
    void *owner;
    if (*(long *)((char *)vehicleRender + 0x40) == fn_801E866C(-1) &&
        fn_801E89C8(-1) != 0) {
        owner = *(void **)((char *)vehicleRender + 0x3C);
        lbl_80488668[2] = fn_802C99E8(owner, *(float *)((char *)owner + 0x2CC));
        fn_802C99E8(((void *(*)(void *))fn_801ED718)(vehicleRender), lbl_80488668[2]);
    }
}

extern float fn_801E8738(int);
extern void fn_802C974C(float, float, float);
extern void fn_802C88BC(int);
extern int fn_801E7E2C(void);
extern void fn_802C8B98(void *, void *, void *, void *, void *);
extern void fn_802C8DB8(void *, int, void *, int);
extern void fn_802C8D74(void);
extern unsigned short lbl_802F9AD0[];
extern unsigned char lbl_8055AFC8;
extern float lbl_8055EBBC, lbl_80562E8C, lbl_80562E9C, lbl_80562EA0;
extern float lbl_80562EA4, lbl_80562EA8, lbl_80562EAC, lbl_80562EB0, lbl_80562EB4;
extern float lbl_80562EB8, lbl_80562EBC, lbl_80562EC0, lbl_80562EC4;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801ED718(void *arg0) {
    char *o = (char *)arg0;
    float v[24];
    double dv[12];
    float m[12];
    float t[3];
    float dir[3];
    unsigned short idx[6];
    float big[0x3C];
    int i;
    fn_802C974C(lbl_80562E9C, lbl_80562EA0, fn_801E8738(-1));
    fn_802C88BC(2);
    if (fn_801E7E2C() != -1) {
        v[0] = lbl_80562EA4; v[1] = lbl_80562EA8; v[2] = lbl_80562E88; *(int *)&v[3] = -1;
        v[4] = lbl_80562E88; v[5] = lbl_80562EAC;
        v[6] = lbl_80562EB0; v[7] = lbl_80562EA8; v[8] = lbl_80562E88; *(int *)&v[9] = -1;
        v[10] = lbl_80562E90; v[11] = lbl_80562EAC;
        v[12] = lbl_80562EB0; v[13] = lbl_80562EB4; v[14] = lbl_80562E88; *(int *)&v[15] = -1;
        v[16] = lbl_80562E90; v[17] = lbl_80562E88;
        v[18] = lbl_80562EA4; v[19] = lbl_80562EB4; v[20] = lbl_80562E88; *(int *)&v[21] = -1;
        v[22] = lbl_80562E88; v[23] = lbl_80562E88;
        for (i = 0; i < 12; i++) dv[i] = *(double *)&v[i * 2];
        for (i = 0; i < 6; i++) idx[i] = lbl_802F9AD0[i];
        for (i = 0; i < 12; i++) m[i] = ((float *)(o + 4))[i];
        dir[0] = lbl_80562EB8; dir[1] = lbl_80562EBC; dir[2] = lbl_80562EC0;
        t[0] = dir[0] * m[0] + dir[1] * m[3] + dir[2] * m[6];
        t[1] = dir[0] * m[1] + dir[1] * m[4] + dir[2] * m[7];
        t[2] = dir[0] * m[2] + dir[1] * m[5] + dir[2] * m[8];
        m[9] += t[0]; m[10] += t[1]; m[11] += t[2];
        fn_802C8B98(m, 0, 0, 0, 0);
        fn_802C8DB8(dv, 4, idx, 6);
        fn_802C8D74();
    }
    if (lbl_8055AFC8 == 0) {
        fn_802C70AC(*(int *)(o + 0x178), o + 4, 0, 5);
    } else {
        for (i = 0; i < 0x3C; i++) big[i] = lbl_80562E88;
        fn_802C70AC(*(int *)(o + 0x178), o + 4, 0, -1);
    }
    fn_801EC4A8(o + 0x18C, (long)(o + 4));
    fn_801EC4A8(o + 0x1E0, (long)(o + 4));
    fn_801EC4A8(o + 0x234, (long)(o + 4));
    fn_801EC4A8(o + 0x288, (long)(o + 4));
    fn_801EC4A8(o + 0x2DC, (long)(o + 4));
    fn_801EC4A8(o + 0x330, (long)(o + 4));
    fn_801EC4A8(o + 0x384, (long)(o + 4));
    if (*(unsigned short *)(*(char **)(o + 0x3C) + 0x6E) & 2) fn_801E34E4(*(void **)(o + 0x180), (long)(o + 4));
    if (*(unsigned char *)(o + 0x3F4) != 0) {
        ((void (*)(int, void *, float))fn_801E353C)(*(int *)(o + 0x17C), *(void **)(o + 0x3C), -lbl_8055EBBC * *(float *)(*(char **)(o + 0x3C) + 0x3C));
        fn_801E34E4(*(void **)(o + 0x17C), (long)(o + 4));
    }
}
#pragma pop

/* Build a vehicle effect's left/right offset transforms from its owner matrix:
   pass its effect-data list, the owner transform, and its four transform slots. */
void fn_801EDD68(void *vehicleRender) {
    fn_801EFC90(*(long *)((char *)vehicleRender + 0x3F0),
                *(long *)((char *)vehicleRender + 0x3C), (char *)vehicleRender + 0x4D4);
}

extern void fn_801EABA8(void *, void *);
extern void fn_801F0F78(long, long, void *, float);
extern float lbl_80562E90;
extern float __fabsf(float);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_801EDD7C(void *arg0, long arg1) {
    void *object = arg0;
    long offset, i;
    char *entry;
    float v3, v2, v1, v0;
    float scale;
    float v4, v5, v6, v7, v8, v10, v9, v11;

    fn_801EABA8(object, *(void **)((char *)object + 0x3C));
    scale = *(float *)((char *)arg1 + 0x2D0);
    *(float *)((char *)object + 0x4D0) = scale;
    if ((float)__fabs((double)(scale - lbl_80562E90)) <= lbl_80558DC4[0]) {
        *(unsigned int *)((char *)object + 0x4A0) = *(unsigned int *)((char *)object + 4);
        *(unsigned int *)((char *)object + 0x4A4) = *(unsigned int *)((char *)object + 8);
        *(unsigned int *)((char *)object + 0x4A8) = *(unsigned int *)((char *)object + 0xC);
        *(unsigned int *)((char *)object + 0x4AC) = *(unsigned int *)((char *)object + 0x10);
        *(unsigned int *)((char *)object + 0x4B0) = *(unsigned int *)((char *)object + 0x14);
        *(unsigned int *)((char *)object + 0x4B4) = *(unsigned int *)((char *)object + 0x18);
        *(unsigned int *)((char *)object + 0x4B8) = *(unsigned int *)((char *)object + 0x1C);
        *(unsigned int *)((char *)object + 0x4BC) = *(unsigned int *)((char *)object + 0x20);
        *(unsigned int *)((char *)object + 0x4C0) = *(unsigned int *)((char *)object + 0x24);
        *(unsigned int *)((char *)object + 0x4C4) = *(unsigned int *)((char *)object + 0x28);
        *(unsigned int *)((char *)object + 0x4C8) = *(unsigned int *)((char *)object + 0x2C);
        *(unsigned int *)((char *)object + 0x4CC) = *(unsigned int *)((char *)object + 0x30);
    } else {
        v0 = *(float *)((char *)object + 4) * scale;
        v1 = *(float *)((char *)object + 8) * scale;
        v2 = *(float *)((char *)object + 0xC) * scale;
        v3 = *(float *)((char *)object + 0x10) * scale;
        v4 = *(float *)((char *)object + 0x14) * scale;
        v5 = *(float *)((char *)object + 0x18) * scale;
        v6 = *(float *)((char *)object + 0x1C) * scale;
        v7 = *(float *)((char *)object + 0x20) * scale;
        v8 = *(float *)((char *)object + 0x24) * scale;
        v9 = *(float *)((char *)object + 0x28);
        v10 = *(float *)((char *)object + 0x2C);
        v11 = *(float *)((char *)object + 0x30);
        *(float *)((char *)object + 0x4C4) = v9;
        *(float *)((char *)object + 0x4C8) = v10;
        *(float *)((char *)object + 0x4CC) = v11;
        *(float *)((char *)object + 0x4A0) = v0;
        *(float *)((char *)object + 0x4A4) = v1;
        *(float *)((char *)object + 0x4A8) = v2;
        *(float *)((char *)object + 0x4AC) = v3;
        *(float *)((char *)object + 0x4B0) = v4;
        *(float *)((char *)object + 0x4B4) = v5;
        *(float *)((char *)object + 0x4B8) = v6;
        *(float *)((char *)object + 0x4BC) = v7;
        *(float *)((char *)object + 0x4C0) = v8;
    }
    entry = object;
    i = 0;
    offset = 0;
    do {
        fn_801F0F78(*(long *)(entry + 0x4D4),
                    offset + *(long *)((char *)object + 0x3C) + 0x7C,
                    (char *)object + 4,
                    *(float *)((char *)object + 0x4D0));
        i++;
        offset += 0x6C;
        entry += 4;
    } while (i < 4);
}
#pragma pop

extern float lbl_80562E88, lbl_80562E90, lbl_80562E9C, lbl_80562EC8;
float fn_802C88E8(void*);
long fn_801E89A4(long);
short fn_801EAC3C(void*, long);
long fn_801E9E78(void*, void*, float*, long*, float);
float PSVECDotProduct(float*, void*);
void* fn_802C9A40(void);
void fn_802C7AE0(long, void*, long, float);
void fn_801F13F4(long, float, float);
#pragma push
#pragma processor 750
#pragma optimization_level 3
#pragma scheduling invalid_target
void fn_801EDF18(void* arg0) {
    struct Settings { long first; union { long bits; float value; } second; long third; } settings;
    float temp_f31, var_f30, var_f29, limit, dot, factor;
    float vector[3];
    long index, result, firstValue, secondValue;
    short entry;
    int i;
    temp_f31 = fn_801E88F0(-1);
    temp_f31 *= temp_f31;
    factor = fn_802C88E8((void*)((long)arg0 + 0x28));
    temp_f31 = factor * temp_f31;
    index = *(long*)((char*)arg0 + 0x480) - 1;
    while (index >= 0 && temp_f31 < (*(float*)((char*)arg0 + index * 8 + 0x404) * *(float*)((char*)arg0 + index * 8 + 0x404))) index--;
    if (index < 0) return;
    if (*(long*)((char*)arg0 + 0x40) != fn_801E866C(-1)) goto process;
    if (fn_801E89A4(-1) != 0) goto process;
    return;
process:
    firstValue = *(volatile long*)((char*)arg0 + 0x28);
    secondValue = *(volatile long*)((char*)arg0 + 0x2C);
    settings.first = firstValue;
    settings.second.bits = secondValue;
    settings.third = *(volatile long*)((char*)arg0 + 0x30);
    entry = fn_801EAC3C(arg0, settings.first);
    vector[0] = lbl_80562E88;
    vector[1] = lbl_80562E90;
    vector[2] = lbl_80562E88;
    result = 0;
    if (fn_801E9E78(&entry, &settings, vector, &result, lbl_80562E88) != 0) {
        dot = -PSVECDotProduct(vector, fn_802C9A40());
        limit = lbl_80562E9C;
        var_f29 = *(float*)((char*)arg0 + 0x2C) - settings.second.value;
        limit = limit > dot ? dot : limit;
        var_f30 = lbl_80562E90 / limit;
    } else {
        var_f29 = lbl_80562E88;
        var_f30 = lbl_80562EC8;
    }
    fn_802C7AE0(*(long*)((char*)arg0 + index * 8 + 0x400),
                (char*)arg0 + 0x4A0, -1,
                var_f30 * (var_f29 + *(float*)((char*)arg0 + 0x484)));
    i = 0;
    do {
        fn_801F13F4(*(long*)((char*)arg0 + 0x4D4),
                    temp_f31, var_f29 * var_f30);
        i++;
        arg0 = (char*)arg0 + 4;
    } while (i < 4);
}
#pragma pop

/* Return the model/effect handle (long) stored at +0x48 of the given per-car object. */
long fn_801EE0C8(void *object) {
    return *(long *)((char *)object + 0x48);
}

/* Passes the object pointer held in the +0x4D4 pointer array of `table` at
   `index` to fn_801F159C (effectively reading that object's +0x18 float). */
void fn_801EE0D0(long table, long index) {
    fn_801F159C(*(long *)(table + index * 4 + 0x4D4));
}

extern void *fn_80131808(void *);
extern char lbl_8055AFFC[], lbl_8055B000[], lbl_8055B004[], lbl_8055B00C[];
void fn_801EE0E0(void *arg0, char *arg1, int arg2, int arg3, char *arg4) {
#define VC1(o,sl,t,a) (((t)(*(void ***)(o))[(sl)/4])(o,a))
    char nameBuf[0x100];
    char small[0x40];
    char *table;
    void *found = 0, *node;
    int i, v;
    (void)arg2;
    *(int *)((char *)arg0 + 8) = arg3;
    fn_801345D8(nameBuf, 0x100, lbl_8033A060 + 0x64, arg1);
    table = (char *)fn_80131808(nameBuf);
    *(void **)((char *)arg0 + 0x5A0) = table;
    for (i = 4; i >= 0; i--) {
        fn_801345D8(small, 0x40, lbl_8033A060 + 0x74, i + 1);
        found = VC1(table, 8, void *(*)(void *, void *), small);
        if (found != 0) break;
    }
    if (found == 0) {
        fn_802E317C(lbl_8033A060 + 0x80, arg1);
        return;
    }
    node = VC1(found, 0x14, void *(*)(void *, void *), lbl_8055AFFC);
    node = VC1(table, 8, void *(*)(void *, void *), node);
    *(int *)((char *)arg0 + 0x3FC) = VC1(found, 0x1C, int (*)(void *, void *), lbl_8055B000);
    VC1(found, 0x24, void (*)(void *, void *), lbl_8055B004);
    v = VC1(found, 0x1C, int (*)(void *, void *), lbl_8055B00C);
    *(int *)((char *)arg0 + 0x14C) = v;
    if (v < *(int *)((char *)arg0 + 0x3FC)) {
        *(int *)((char *)arg0 + 0x3FC) = v;
        *(int *)((char *)arg0 + 0x148) = 0;
    }
}

extern char lbl_8033A1C8[];
extern char lbl_8055B070[8];
extern char lbl_8055B078[8];
long fn_801EFF94(void *, long, long);
/* Readable aliases; the game's own symbols keep their placeholder names. */
#define CAR_WHEEL_CLASS_KEY lbl_8033A1C8 /* "wheel_class": the wheel record an axle group names */
#define CAR_GROUP_FRONT lbl_8055B070      /* "Front" */
#define CAR_GROUP_REAR lbl_8055B078       /* "Rear" */
#define CAR_PARAM_SET(car) (*(void **)(*(char **)((char *)(car) + 0x188) + 0x2134)) /* the car's parameter record */
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Attaches a wheel to each of a car's four wheel slots (+0x4D4): the front axle's
 * two wheels read their "wheel_class" out of the car's "Front" parameter group and
 * the rear axle's two out of "Rear", allocate a wheel of that class for this car,
 * and the wheel's tire radius goes to the vehicle's radius array at +0x10C. */
extern "C" void fn_801EE974(void *car, void *vehicle) {
    /* A car's parameter record: virtual 0 picks a named group ("Front"/"Rear"),
     * virtual 3 reads a key ("wheel_class") out of that group. */
    class ParamNode {
    public:
        virtual void *getGroup(void *);
        virtual void *m1(void *);
        virtual void *m2(void *);
        virtual void *getKey(void *);
    };
    char *wheelSlot;
    char *radiusOut;
    long i;
    long frontAxle;
    ParamNode *params;
    ParamNode *wheelClass;
    radiusOut = (char *)vehicle;
    wheelSlot = (char *)car;
    i = 0;
    do {
        frontAxle = 0;
        if (i == 0) goto front;
        if (i != 1) goto checked;
    front:
        frontAxle = 1;
    checked:
        if (frontAxle) {
            params = (ParamNode *)CAR_PARAM_SET(car);
            wheelClass = (ParamNode *)params->getGroup(CAR_GROUP_FRONT);
            wheelClass = (ParamNode *)wheelClass->getKey(CAR_WHEEL_CLASS_KEY);
        } else {
            params = (ParamNode *)CAR_PARAM_SET(car);
            wheelClass = (ParamNode *)params->getGroup(CAR_GROUP_REAR);
            wheelClass = (ParamNode *)wheelClass->getKey(CAR_WHEEL_CLASS_KEY);
        }
        *(long *)(wheelSlot + 0x4D4) = fn_801EFF94(wheelClass, *(long *)((char *)car + 0x40), i);
        *(float *)(radiusOut + 0x10C) = fn_801F159C(*(long *)(wheelSlot + 0x4D4));
        i++;
        wheelSlot += 4;
        radiusOut += 4;
    } while (i < 4);
}
#pragma cplusplus reset
extern void fn_801345D8(void *, int, const char *, ...);
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern int fn_802C6FC0(void *, int, int);
extern int fn_802C7830(void);
extern char lbl_8033A060[];
extern char lbl_8055B080;
#pragma cplusplus on
extern "C" void fn_801EEA64(void *arg0, void *arg1, int arg2, int arg3) {
 /* Loads UI/string configuration for the given index from a named resource and fills output fields. */
 char *base = lbl_8033A060;
 char pathBuf[0x100]; char nameBuf[0x100]; Unk_801EEA64Iface *resource; Unk_801EEA64Iface *obj; int objId; int value, shift;
 fn_801345D8(pathBuf,0x100,base+0x174,arg2);
 resource=(Unk_801EEA64Iface *)fn_80131810(pathBuf);
 if(resource != 0 && resource->m10(&lbl_8055B080) != 0) {
  obj=resource->m8(&lbl_8055B080);
  objId=obj->m14(base+0x194);
  fn_801345D8(nameBuf,0x100,base+0x188,arg2,objId);
  *(int *)((char *)arg0+0x488)=fn_802C6FC0(nameBuf,0,arg3);
  *(int *)((char *)arg0+0x48C)=obj->m1C(base+0x1A0);
  *(int *)((char *)arg0+0x490)=obj->m1C(base+0x1AC);
  *(int *)((char *)arg0+0x494)=obj->m1C(base+0x1B8);
  if(obj->mC(base+0x15C)!=0) {
   obj->m14(base+0x15C);
   *(int *)((char *)arg0+0x498)=fn_802C7830();
  } else *(int *)((char *)arg0+0x498)=-1;
  shift=obj->m1C(base+0x1C4);
  *(int *)((char *)arg0+0x49C)=1<<shift;
  value=obj->m14(base+0x1D8);
  fn_801345D8((char *)arg1+0xEC,0x20,base+0x188,arg2,value);
  fn_80131818(resource); return;
 }
 *(int *)((char *)arg0+0x488)=-1; *(int *)((char *)arg0+0x494)=0; *((char *)arg1+0xEC)=0;
}
#pragma cplusplus reset
void fn_801EDD7C(void *, long);
long fn_80179CB0(void);
void fn_801EECAC(long, long);
void fn_802C6CF8(long);
/* Release the model handle stored at offset 0x488 of the given object. */
void fn_801EEC68(void *object) {
    long modelHandle;
    modelHandle = *(long *)((char *)object + 0x488);
    if (modelHandle != -1) {
        fn_802C6CF8(modelHandle);
        *(long *)((char *)object + 0x488) = -1;
    }
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801EECAC(long arg0, long arg1) {
    extern void fn_801EAB10(int, int);
    extern char lbl_8055B088;
    extern char lbl_8055B090;
    extern float lbl_80562E90;
    extern float lbl_80562E88;
    extern float lbl_80562ECC;
    extern float lbl_80562ED0;
    extern float lbl_80562ED4;
    struct Property {
        virtual int get(int);
    };
    int value;
    void *object;
    long next;

    next = arg1 + *(long *)((char *)arg0 + 0x34);
    *(long *)((char *)arg0 + 0x3C) = next;
    fn_801EAB10(*(int *)((char *)arg0 + 0x40), next);

    object = *(void **)((char *)*(void **)((char *)arg0 + 0x188) + 0x2134);
    value = ((Property *)object)->get((int)&lbl_8055B090);

    fn_801EC214((void *)(arg0 + 0x384), (void *)value,
                *(int *)((char *)arg0 + 0x178), lbl_8033A060 + 0x1E4,
                (int)&lbl_8055B088, lbl_80562E90, lbl_80562E88);
    fn_801EC214((void *)(arg0 + 0x18C), (void *)value,
                *(int *)((char *)arg0 + 0x178), lbl_8033A060 + 0x1F0,
                *(int *)((char *)arg0 + 0x3C) + 0x4C, lbl_80562ECC, lbl_80562E88);
    fn_801EC59C((void *)(arg0 + 0x3D8), (void *)value,
                (int)(lbl_8033A060 + 0x1FC),
                *(int *)((char *)arg0 + 0x3C) + 0x4C,
                lbl_80562ECC, lbl_80562E88);
    fn_801EC214((void *)(arg0 + 0x1E0), (void *)value,
                *(int *)((char *)arg0 + 0x178), lbl_8033A060 + 0x20C,
                *(int *)((char *)arg0 + 0x3C) + 0x34, lbl_80562E90, lbl_80562E88);
    fn_801EC214((void *)(arg0 + 0x234), (void *)value,
                *(int *)((char *)arg0 + 0x178), lbl_8033A060 + 0x218,
                *(int *)((char *)arg0 + 0x3C) + 0x2B0, lbl_80562E90, lbl_80562E88);
    fn_801EC214((void *)(arg0 + 0x288), (void *)value,
                *(int *)((char *)arg0 + 0x178), lbl_8033A060 + 0x22C,
                *(int *)((char *)arg0 + 0x3C) + 0x2AC, lbl_80562ED0, lbl_80562ED4);
    fn_801EC214((void *)(arg0 + 0x2DC), (void *)value,
                *(int *)((char *)arg0 + 0x178), lbl_8033A060 + 0x23C,
                *(int *)((char *)arg0 + 0x3C) + 0x2A0, lbl_80562ED0, lbl_80562ED4);
    fn_801EC214((void *)(arg0 + 0x330), (void *)value,
                *(int *)((char *)arg0 + 0x178), lbl_8033A060 + 0x250,
                *(int *)((char *)arg0 + 0x3C) + 0x2B8, lbl_80562E90, lbl_80562E88);
}
#pragma cplusplus reset
#pragma scheduling on

#pragma scheduling on
long fn_801EEE38(void) {
    long *entries;
    long context;
    unsigned int i;
    long value;

    context = fn_80179CB0();
    entries = lbl_80488648;
    i = 0;
    goto check;

loop:
    fn_801EECAC(value, context);
    entries++;
    i++;
    if (i < 8u) {
        goto check;
    }
    return 0;

check:
    value = *entries;
    if (value != 0) {
        goto loop;
    }
    return value;
}
extern void *fn_801EC750();
extern int lbl_8033A2D4[64];
#pragma scheduling off
void **fn_801EEEB0(void **archive) {
#define SoundArchiveBaseCtor fn_801EC750
#define MemorySoundArchiveVtable lbl_8033A2D4
    /* Construct a MemorySoundArchive: initialise the SoundArchive base object,
       then install the derived vtable. */
    SoundArchiveBaseCtor(archive);
    *archive = &MemorySoundArchiveVtable;
    return archive;
#undef SoundArchiveBaseCtor
#undef MemorySoundArchiveVtable
}
#pragma scheduling on

/* Deleting destructor for nw4hbm::snd::MemorySoundArchive: run base destruction, then free storage if requested. */
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801EEEEC(long self, long shouldDelete) {
    if (self != 0) {
        fn_801EC9CC((void*)self, 0);
        if (shouldDelete > 0) {
            fn_80128668((void*)self);
        }
    }
    return self;
}

void fn_801EEF44(void *renderState, void *vehicle) {
    unsigned int slot;
    unsigned int renderObject;
    /* Look up the vehicle's render-object slot in the per-slot table, store three
       data-block pointers from that object into renderState, then finish the setup. */
    slot = *(unsigned int *)((char *)vehicle + 0xFA8);
    renderObject = *(unsigned int *)((char *)lbl_80488648 + slot * 4);
    *(unsigned int *)((char *)renderState + 0x16C) = renderObject + 0x44;
    *(unsigned int *)((char *)renderState + 0x170) = renderObject + 0xC8;
    *(unsigned int *)((char *)renderState + 0x174) = renderObject + 0x148;
    fn_801EDD7C(renderState, (long)vehicle);
}

unsigned int fn_801EEF74(void) {
#define ALWAYS_TRUE 1
    /* Constant predicate: always reports true so callers take the enabled path. */
    unsigned int enabled = ALWAYS_TRUE;
    return enabled;
}

