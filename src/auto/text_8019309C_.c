// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).

                      extern void fn_801958D8();
extern void fn_8018A174(void *);
extern void fn_801961F8(void);
extern void fn_80195B28(void *, float);
extern void fn_8019416C(void);
extern void fn_801945F8(void *);
extern void fn_80196DC4(void *);
extern void fn_80195F6C(void *, void *);
extern void fn_80194624(void *);
extern void fn_80195654(void *, void *);
extern void fn_801933FC(void *, void *);
    extern double fn_8002F234(float);
    extern float lbl_8055E584, lbl_8055E588;
    extern float fn_80129DC4(int, float, float);
    extern void fn_8013530C(void *, int);
    extern int lbl_8055E550;
    extern float lbl_8055E3C8, lbl_80562144, lbl_80562140, lbl_80562148, lbl_80562204, lbl_805621E4;

      extern void fn_80194FD0(unsigned char *, float *, float);
typedef struct { void *a; float b; int c; } Samp80194FD0;
extern void *fn_8017960C();
extern int fn_80137788(void *, int, float *);
extern float lbl_805621C0, lbl_805621F0, lbl_805621F4, lbl_805621F8, lbl_805621FC, lbl_80562200, lbl_80562160, lbl_8056216C;
extern unsigned int lbl_8055D430;
extern int lbl_8055E0D0;
typedef float (*Fn931AC)(void *, void *, void *, float, float, float, float);
typedef float (*Fn948B0)(void *, int, float);
typedef float (*Fn94FC8)(void *);
extern void fn_80135B9C(void *, void *, void *, void *, void *, float);
#define F80194FD0(p, o) (*(float *)((unsigned char *)(p) + (o)))
#define P80194FD0(p, o) (*(void **)((unsigned char *)(p) + (o)))
#pragma cplusplus on
class Vt_80194C4C {
public:
    virtual void *v0();
    virtual void *v1();
    virtual void *v2();
    virtual void *v3();
    virtual void *v4();
    virtual void *v5();
    virtual void *v6();
    virtual void *v7();
    virtual void *v8();
};
class Vt_80194C4CController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(float *, float *, int *);
    virtual void v10();
    virtual void v11();
};
class Vt_80194324 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(void *);
};
#pragma cplusplus reset
typedef unsigned char u8;
extern void *lbl_804349C0[];
extern float lbl_8056223C, lbl_8055E57C;
extern int lbl_804348E8[];
extern void *lbl_804349E0[];
extern char lbl_80333390[0x10000];
  void fn_801964D0(void *);
      void fn_80128668(void *);
    void fn_80193138(void *, int);
    void fn_80193CE0(void *);

#pragma cplusplus on
class DummyVt_80193CE0 {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
};
class Vt30_801944C0 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10();
    virtual void v30(int);
};
#pragma cplusplus reset
  
  extern char lbl_8055A4B8[8]; /* "console" */
extern float lbl_80562178, lbl_8056217C, lbl_8055E558;
extern float lbl_80562264, lbl_8056224C;
extern void fn_8017B4E0(void *, float *, float *, float);
extern void fn_80193D30(void *);
extern int fn_802E30C8(const char *, ...);
extern char lbl_80333198[];

extern char lbl_80333158[];
extern float lbl_8055A488, lbl_8055A48C;
extern unsigned char lbl_8055E580;
extern unsigned int lbl_8055E540;
extern float lbl_8055E554, lbl_8055E56C, lbl_8055E568, lbl_8055E564;
extern float lbl_8055E544, lbl_8055E548, lbl_8055E54C, lbl_8055E55C;
extern float lbl_8055E560, lbl_8055E570;
extern int lbl_8055E578;
extern float lbl_80562184, lbl_80562188, lbl_8056218C, lbl_80562190;
extern float lbl_80562194, lbl_80562198, lbl_8056219C;
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_80137C54(int);
extern void fn_80134CD4(int, void *);
extern float fn_80134B58(void *, float);

#define __HI(x) *(int *)&x
extern float lbl_80562168, lbl_80562174, lbl_805621A4, lbl_805621B0, lbl_805621B4;
extern float lbl_80333308[];
extern float lbl_8056220C;
extern float lbl_8055A488, lbl_8056215C;

int fn_8019309C(void *player, int slotIndex, signed char value) {
    /* If the player registered at slotIndex is active, copy its id into that record's voice slot, store value on the player, and report success. */
    void *rec = lbl_804349C0[slotIndex];
    int applied = 0;
    if (rec != 0 && *((u8 *)rec + 0x2A4) != 0) {
        applied = 1;
        *((u8 *)rec + 0x2FC) = *((unsigned int *)((char *)player + 0x290));
        *((u8 *)player + 0x2FD) = value;
    }
    return applied;
}

u8 fn_801930DC(void *unused, int slotIndex) {
    void *entry;

    /* Read the +0x2FD marker of the racer registered at slotIndex, if active. */
    entry = lbl_804349C0[slotIndex];
    if (entry != 0 && *((u8 *)entry + 0x2A4) != 0)
        return *((u8 *)entry + 0x2FD);
    return 0;
}

/* Release the record's +0x2FC voice slot when it belongs to `playerId`: mark it 0xFF (unowned) and report success. */
int fn_80193110(void *record, int playerId) {
    u8 targetId = playerId;
    if (*((u8 *)record + 0x2FC) == targetId) {
        *((u8 *)record + 0x2FC) = 0xFF;
        return 1;
    }
    return 0;
}

/* Reset the +0x304 counter of the racer registered at slotIndex to 20, if any. */
void fn_80193138(void *unused, int slotIndex) {
    void *entry = lbl_804349C0[slotIndex];
    if (entry) *((unsigned char *)entry + 0x304) = 0x14;
}

#pragma dont_inline on
void fn_8019315C(void *unused, int slotIndex) {
    /* Increment the +0x300 counter of the racer registered at slotIndex, if any. */
    void *entry = lbl_804349C0[slotIndex];
    if (entry) ++*(int *)((char *)entry + 0x300);
}
#pragma dont_inline reset

#pragma dont_inline on


u8 fn_80193184(void *unused, int slotIndex) {
    void *entry;

    /* Read the +0x2FE byte of the racer registered at slotIndex, if one is registered. */
    entry = lbl_804349C0[slotIndex];
    if (entry != 0) return *((u8 *)entry + 0x2FE);
    return 0;
}
#pragma dont_inline reset

typedef float f32;
struct S93524 { char pad[0x54]; float dir[3]; float pos[3]; };
f32 fn_801931AC(f32 numerator, f32 from, f32 to, f32 denominator) {
#define kOne lbl_80562140
#define kZero lbl_80562144
    /* Lerp from `from` to `to` by 1 - numerator/denominator, clamped into [0,1]. */
    f32 t = kOne - numerator / denominator;
    t = (kOne < t) ? kOne : t;
    t = (t > kZero) ? t : kZero;
    return from + t * (to - from);
#undef kOne
#undef kZero
}

/* Return 1 - numerator/denominator, clamped between a minimum weight and 1. */
float fn_801931EC(float numerator, float denominator) {
#define kOne lbl_80562140
#define kMinWeight lbl_8055E558
    float t = kOne - numerator / denominator;
    float minWeight = kMinWeight;
    t = (kOne < t) ? kOne : t;
    if (t > minWeight) return t;
    return minWeight;
#undef kOne
#undef kMinWeight
}

#pragma processor 750
void fn_8019321C(void *arg0, void *arg1, void *arg2) {
    float stack[8];
    float x = *(float *)((char *)arg2 + 0x18);
    float y = *(float *)((char *)arg2 + 0x20);
    float magnitude = x * x + y * y;
    float length;
    float scale;
    float dx;
    float dy;
    double neg;
    float d;
    float c;
    float oy;
    float ox;
    stack[2] = x;
    stack[3] = y;
    length = (float)fn_8002F234(magnitude);
    length = lbl_80562148 > length ? lbl_80562148 : length;
    stack[6] = *(float *)((char *)arg2 + 0x24);
    scale = lbl_80562140 / length;
    dx = stack[2] * scale;
    dy = stack[3] * scale;
    stack[7] = *(float *)((char *)arg2 + 0x2C);
    c = *(float *)arg1;
    d = *(float *)((char *)arg1 + 4);
    neg = -(double)dx;
    stack[2] = dx;
    stack[3] = dy;
    stack[4] = dy;
    stack[5] = (float)neg;
    ox = dy * c + dx * d;
    oy = (float)neg * c + dy * d;
    ox += stack[6];
    oy += stack[7];
    *(float *)arg0 = stack[0] = ox;
    *(float *)((char *)arg0 + 4) = stack[1] = oy;
}
#pragma processor reset
extern float lbl_80562140, lbl_80562148;
#pragma dont_inline on
void fn_8019330C(void *out, void *in, int arg2) {
    volatile float work[8];
    float y = *(float *)((char *)arg2 + 0x20);
    float x = *(float *)((char *)arg2 + 0x18);
    float sq = x * x + y * y;
    float length;
    float denom;
    float scale;
    float sx, sy, dx, dy, nsx;
    length = (float)fn_8002F234(sq);
    denom = lbl_80562148 > length ? lbl_80562148 : length;
    scale = lbl_80562140 / denom;
    sy = work[3] * scale;
    sx = work[2] * scale;
    work[6] = *(float *)((char *)arg2 + 0x24);
    work[7] = *(float *)((char *)arg2 + 0x2C);
    dx = *(float *)in - work[6];
    dy = *(float *)((char *)in + 4) - work[7];
    work[0] = dx;
    work[1] = dy;
    work[2] = sx;
    work[3] = sy;
    work[4] = sy;
    nsx = -sx;
    work[5] = nsx;
    *(float *)((char *)out + 4) = dx * sx + dy * sy;
    *(float *)out = dx * sy + dy * (float)(double)nsx;
}
#pragma dont_inline reset

#pragma scheduling off
/* Projects the 2D point (used as both input and output) into the local frame of the object's vehicle at +0x294 (+0x70). */
void fn_801933FC(void *owner, void *point) {
    fn_8019330C(point, point, (owner = *(void **)((char *)owner + 0x294), (int)((char *)owner + 0x70)));
}
#pragma scheduling reset
int fn_80193524(void *first, void *second) {
    /* Returns nonzero if the objects' directions are not nearly parallel and their positions overlap along those directions. */
    extern float PSVECDotProduct(const void *, const void *);
    extern float lbl_8056215C;
    struct S93524 *objA = first, *objB = second;
    int result = 0;
    float deltaPos[3];
    float dirDot;
    dirDot = __fabs(PSVECDotProduct(objA->dir, objB->dir));
    if (dirDot < lbl_8056215C) {
        deltaPos[0] = objB->pos[0] - objA->pos[0];
        deltaPos[1] = objB->pos[1] - objA->pos[1];
        deltaPos[2] = objB->pos[2] - objA->pos[2];
        dirDot = PSVECDotProduct(deltaPos, objA->dir);
        result = dirDot > -PSVECDotProduct(deltaPos, objB->dir);
    }
    return result;
}
#pragma processor gekko
/* Reset a sound object's timing: zero its accumulators and stamp its start time. */
void fn_801935EC(void *sound) {
    float zero = lbl_80562144;
    *(float *)((unsigned char *)sound + 0x224) = zero;
    *(float *)((unsigned char *)sound + 0x228) = zero;
    *(float *)((unsigned char *)sound + 0x22C) = lbl_8055E3C8;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80193604(void *arg0, void *arg1, void *unused, int arg2, void *arg3) {
    extern float PSVECDotProduct(const void *, const void *);
    extern float PSVECMag(const void *);
    extern float lbl_80562140, lbl_80562144, lbl_80562148, lbl_8056215C;
    extern float lbl_80562160, lbl_80562164, lbl_80562168, lbl_8056216C;
    extern float lbl_80562170, lbl_80562174;
    struct Vec { float x, y, z; };
    char *other = (char *)arg3, *obj = (char *)arg0;
    int code = arg2;
    float value, scale, delta[3];
    struct Vec normal;
    if (other != 0) {
        if (*(unsigned int *)(other + 0x10) == 0x50434152) {
            char *vehicle = *(char **)(obj + 0x294);
            delta[0] = *(float *)(other + 0x60) - *(float *)(vehicle + 0x60);
            delta[1] = *(float *)(other + 0x64) - *(float *)(vehicle + 0x64);
            delta[2] = *(float *)(other + 0x68) - *(float *)(vehicle + 0x68);
            if (PSVECDotProduct(delta, *(char **)(obj + 0x294) + 0x54) > lbl_80562144) {
                value = PSVECDotProduct(other + 0x118, other + 0x54);
                if (value > lbl_80562160 && (float)__fabs(PSVECDotProduct(other + 0x118, other + 0x3C) / value) > lbl_80562164)
                    *(float *)(obj + 0x2A8) += lbl_80562168;
            }
        }
        if ((*(unsigned int *)(other + 0x10) == 0x41434152 || *(unsigned int *)(other + 0x10) == 0x50434152) &&
            fn_80193524(*(void **)(obj + 0x294), other))
            *(float *)(obj + 0x2A8) += lbl_80562168;
    }
    if (code < 0x3E8 && PSVECDotProduct(arg1, *(char **)(obj + 0x294) + 0x88) < lbl_80562144) {
        unsigned int z; unsigned int y; unsigned int x;
        x = ((unsigned int *)arg1)[0];
        y = ((unsigned int *)arg1)[1];
        z = ((unsigned int *)arg1)[2];
        ((unsigned int *)&normal)[2] = z;
        ((unsigned int *)&normal)[1] = y;
        ((unsigned int *)&normal)[0] = x;
        value = PSVECMag(&normal);
        scale = lbl_80562148 > value ? lbl_80562148 : value;
        scale = lbl_80562140 / scale;
        normal.x *= scale; normal.y *= scale; normal.z *= scale;
        if ((float)__fabs(PSVECDotProduct(&normal, *(char **)(obj + 0x294) + 0x88)) > lbl_8056215C) {
            value = *(float *)(obj + 0x270);
            if (value < lbl_8056216C && (code != 0x6D || value < lbl_80562170) &&
                (*(int *)(obj + 0x268) != 1 || code != 0x6D))
                *(float *)(obj + 0x2A0) += lbl_80562174;
        }
    }
    if (code == 0x3EA) *(float *)(obj + 0x2A0) += lbl_80562174;
    if (code == 0x6D) *(u8 *)(obj + 0x2FE) = 0;
}
#pragma pop
void fn_8019386C(void *arg0) {
    fn_80193CE0(arg0);
}

/* Single-argument entry point (callback shape) for fn_801945F8, the routine that
 * sets up a driver's lateral direction scale once its vehicle (+0x294) and
 * sub-object (+0x288) states allow it: tail-calls it with the driver untouched
 * and the "console" name as the extra tag argument. fn_801945F8 is defined
 * taking only the driver, so the call goes through a two-argument cast. */
void fn_80193870(void *driver) {
    ((void (*)(void *, const char *))fn_801945F8)(driver, lbl_8055A4B8);
}

void fn_80193878(void *arg0) {
    float a[3], b[3], low[3];
    void *obj;
    a[0] = lbl_80562144;
    a[1] = lbl_80562144;
    a[2] = lbl_80562178;
    low[0] = lbl_8056217C;
    low[1] = lbl_80562144;
    low[2] = lbl_80562144;
    obj = *(void **)((unsigned char *)arg0 + 0x294);
    b[0] = *(float *)((unsigned char *)obj + 0x94) + low[0];
    b[1] = *(float *)((unsigned char *)obj + 0x98) + low[2];
    b[2] = *(float *)((unsigned char *)obj + 0x9C) + low[2];
    fn_8017B4E0(*(void **)((unsigned char *)arg0 + 0x294), a, b, lbl_80562140);
}

#pragma cplusplus on
class Dummy_801938F4 {
public:
    virtual void d0();
    virtual void d1(int);
    virtual void d2();
    virtual void d3(int);
};
#pragma cplusplus reset
extern void fn_801352B8(void *);
extern float lbl_80562144, lbl_80562180;
extern const char lbl_80333348[];
#pragma cplusplus on
extern "C" void *fn_801938F4(void *driver) {
    /* Construct an AI driver: install its vtable, set default state fields,
     * initialize its two embedded subobjects, and reset their controllers. */
#pragma scheduling invalid_target
    int minusOne = -1;
    int zero = 0;
    float initial = 0.0f;
    char *obj = (char *)driver + 0x168;
    *(int *)((char *)driver + 0x68) = zero;
    *(const char **)driver = lbl_80333348;
    *(int *)((char *)driver + 0x70) = 10000;
    *(float *)((char *)driver + 0x6C) = initial;
    *(int *)((char *)driver + 0x78) = zero;
    *(int *)((char *)driver + 0x90) = minusOne;
    *((char *)driver + 0x8C) = zero;
    *(int *)((char *)driver + 0xA0) = zero;
    *(int *)((char *)driver + 0xB8) = minusOne;
    *((char *)driver + 0xB4) = zero;
    fn_801352B8(obj);
    fn_801352B8(obj + 0x34);
    *(float *)(obj + 0x68) = lbl_80562180;
    ((Dummy_801938F4 *)(obj + 0x34))->d1(0);
    ((Dummy_801938F4 *)obj)->d1(0);
    *(int *)((char *)driver + 0x294) = zero;
    *(int *)((char *)driver + 0x290) = -1000;
    return driver;
#pragma scheduling on
}
#pragma cplusplus reset
extern void fn_801945F8(void *);
extern float lbl_80562140, lbl_80562144, lbl_80562178, lbl_8056217C;
extern void fn_8017B4E0(void *, float *, float *, float);
extern void fn_80193D30(void *);
extern void fn_801942F0(void *, int);
extern int fn_802E30C8(const char *, ...);
extern char lbl_80333198[];
/* Connects/activates this AI driver for its vehicle: if already connected, logs an
 * error with the car index; otherwise marks it connected, copies the vehicle's
 * initial value at +0x5B0 into +0x24C, forces the vehicle enable state, and resets
 * driver state. */
void fn_801939C8(void *driver) {
    void *vehicle;
    if (*(unsigned char *)((unsigned char *)driver + 0x2A4)) {
        fn_802E30C8(lbl_80333198, *(int *)((unsigned char *)driver + 0x290));
    } else {
        vehicle = *(void **)((unsigned char *)driver + 0x294);
        *(unsigned char *)((unsigned char *)driver + 0x2A4) = 1;
        *(float *)((unsigned char *)driver + 0x24C) = *(float *)((unsigned char *)vehicle + 0x5B0);
        fn_801942F0(driver, 1);
        fn_80193D30(driver);
    }
}

/* Disconnect this AI driver: clear its connected flag at +0x2A4 and restore the
 * vehicle's value at +0x24 from its saved value at +0x28 (inverse of fn_801939C8). */
void fn_80193A38(void *driver) {
    void *vehicle = *(void **)((unsigned char *)driver + 0x294);
    *(unsigned char *)((unsigned char *)driver + 0x2A4) = 0;
    *(int *)((unsigned char *)vehicle + 0x24) = *(int *)((unsigned char *)vehicle + 0x28);
}

void *fn_80193A50(void *player, int freeFlag) {
    /* Destructor-like cleanup for a player/track object: unregisters its slot, decrements active count, releases subobjects, and optionally frees. */
    if (player != 0) {
        int slotIndex = *(int *)((char *)player + 0x290);
        if (slotIndex != -1000) {
            ((int *)lbl_804349C0)[slotIndex] = 0;
        }
        lbl_8055E550 -= 1;
        if ((int)player + 0x168 != 0) {
            fn_8013530C((char *)player + 0x19C, -1);
            fn_8013530C((char *)player + 0x168, -1);
        }
        if (freeFlag > 0) {
            fn_80128668(player);
        }
    }
    return player;
}

#pragma cplusplus on
class DummyClass_80193AEC {
public:
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void *vfunc4();
    virtual void *vfunc5();
    virtual void *vfunc6();
};
#pragma cplusplus reset

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80193AEC(void *arg0, void *arg1) {
    /* Initialize a player/vehicle-related runtime object, register it, and one-time init shared tuning/state. */
    char *table = lbl_80333158;
    int zero = 0;
    int id;
    DummyClass_80193AEC *obj;

    *(void **)((char *)arg0 + 0x294) = arg1;
    *(int *)((char *)arg0 + 0x214) = 2;
    *(unsigned char *)((char *)arg0 + 0x2A4) = zero;
    id = *(int *)((char *)arg1 + 0x1EC);
    *(int *)((char *)arg0 + 0x290) = id;
    fn_80134CD4(id, (char *)arg0 + 0x2AC);

    *(void **)((char *)arg0 + 0x298) = (char *)*(void **)((char *)arg0 + 0x294) + 0x23AC;
    lbl_804349C0[*(int *)((char *)arg0 + 0x290)] = arg0;
    obj = *(DummyClass_80193AEC **)((char *)*(void **)((char *)arg0 + 0x294) + 0x270);
    *(DummyClass_80193AEC **)((char *)arg0 + 0x28C) = obj;
    *(void **)((char *)arg0 + 0x164) = obj->vfunc4();

    if (lbl_8055E550++ == 0) {
        lbl_8055A488 = *(float *)fn_80137C54(-1);
        lbl_8055A48C = *(float *)((char *)fn_80137C54(-1) + 4);
        lbl_8055E580 = 1;
        lbl_8055E540 = ((int *)__AXFXGetLfoSinTable_801769CC())[1] != 0x180304;
        lbl_8055E554 = *(float *)((char *)*(void **)((char *)*(void **)((char *)arg0 + 0x164) + 0x2C) + 8);
        lbl_8055E56C = fn_80134B58(table + 0x70, lbl_80562140);
        lbl_8055E568 = fn_80134B58(table + 0x80, lbl_80562140);
        lbl_8055E564 = fn_80134B58(table + 0x94, lbl_80562140);
        lbl_8055E558 = fn_80134B58(table + 0xA4, lbl_8056215C);
        fn_80134B58(table + 0xB4, lbl_80562140);
        lbl_8055E544 = lbl_80562140;
        lbl_8055E548 = fn_80134B58(table + 0xC4, lbl_80562184);
        lbl_8055E54C = fn_80134B58(table + 0xD4, lbl_80562188);
        lbl_8055E55C = fn_80134B58(table + 0xE4, lbl_8056218C);
        lbl_8055E560 = fn_80134B58(table + 0xF0, lbl_80562190);
        lbl_8055E570 = fn_80134B58(table + 0xFC, lbl_80562194);
        lbl_8055E584 = fn_80134B58(table + 0x10C, lbl_80562198);
        lbl_8055E588 = fn_80134B58(table + 0x11C, lbl_8056219C);
        lbl_8055E578 = zero;
    }
    fn_80193D30(arg0);
}
#pragma scheduling reset
#pragma cplusplus reset
void fn_80193CD4(void *driver) {
    /* Raise the driver's pending-action flag at +0x2A5 (cleared by fn_80193CE0). */
    *(signed char *)((char *)driver + 0x2A5) = 1;
}

#pragma cplusplus on
extern "C" void fn_80193CE0(void *self) {
    /* Runs the object's virtual d10() update (vtable slot +0x30), then clears
       its boolean flag at +0x2A5. */
    ((DummyVt_80193CE0 *)self)->d10();
    *(u8 *)((char *)self + 0x2A5) = 0;
}
#pragma cplusplus reset

/* Returns a random float in the configured [min, max) range using RNG slot 3. */
float fn_80193D20(void) {
#define s_randMin lbl_8055E584
#define s_randMax lbl_8055E588
    return fn_80129DC4(3, s_randMin, s_randMax);
#undef s_randMin
#undef s_randMax
}

extern void *memset(void *, int, unsigned int);
extern int fn_801769B8(void);
extern void fn_8013B6A4();
extern int fn_8013B578(int);
extern int fn_801667F0(void);
extern int fn_801B8570(int);
extern float fn_801B306C(void);
extern void fn_801B30D0(int);
extern void fn_801B30E0(int);
extern void fn_80195D80(void *, float);
extern float lbl_8055E3C8, lbl_80562140, lbl_80562144, lbl_8056215C, lbl_80562160, lbl_80562180;
extern float lbl_805621A0, lbl_805621A4, lbl_805621A8, lbl_805621AC;
extern int lbl_8055E3C4;
extern unsigned char lbl_8055E574;
extern float lbl_8055E57C;
extern char lbl_80333284[], lbl_80333294[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus off
extern int fn_801769A8(void);
void fn_80193D30(void *arg0){char*p=(char*)arg0;int temp2;int flag=0;int temp;float limit;lbl_8055E57C=lbl_80562144;limit=lbl_8055E3C8;lbl_8055E574=fn_801769B8()==2;memset(p+8,0,0x10);memset(p+0x20,0,0x54);memset(p+0x74,0,0x78);memset(p+0xEC,0,0x30);memset(p+0x11C,0,0x48);memset(p+0x1D4,0,0x34);memset(p+0x21C,0,4);memset(p+0x220,0,0x1C);memset(p+0x23C,0,0xC);memset(p+0x2D4,0,0x28);{float z=lbl_80562144;*(int*)(p+0x260)=0;*(int*)(p+0x2C4)=-1;*(float*)(p+0x2B8)=z;*(float*)(p+0x2C0)=z;*(float*)(p+0x264)=z;*(int*)(p+0x2D0)=0;*(u8*)(p+0x2A7)=0;memset(p+0x218,0,4);*(int*)(p+0x210)=0;}{float u=lbl_805621A0;int id=lbl_8055E3C4;float f=lbl_805621A4;*(int*)(p+0x2B4)=id;*(float*)(p+0x1D4)=u;*(float*)(p+0x1F0)=u;*(float*)(p+0x1E8)=u;*(float*)(p+0x1E0)=u;*(float*)(p+0x1E4)=u;*(float*)(p+0x1EC)=f;*(float*)(p+0x1F4)=u;*(float*)(p+0x1F8)=u;*(float*)(p+0x1FC)=u;*(float*)(p+0x204)=u;{float v=((float(*)(float))fn_80193D20)(u);float z=lbl_80562144;*(float*)(p+0x200)=v;*(float*)(p+0x20C)=z;}}if(fn_801769A8()&0x800){void*veh=*(void**)(p+0x294);if(*(int*)((char*)veh+0x1F0)!=0x50){flag=1;temp2=0;*(u8*)(p+0x2A5)=flag;*(u8*)(p+0x208)=temp2;memset(p+0x26C,0,0x20);}}{void*s=*(void**)(p+0x28C);*(int*)(p+0x288)=((int(**)(void*))*(void**)s)[4](s);}{float z=lbl_80562144;float mn=lbl_80562140;float sp=lbl_80562160;float sc=lbl_805621A8;*(float*)(p+0x25C)=z;*(float*)(p+0x144)=z;*(float*)(p+0x148)=z;*(float*)(p+0x14C)=mn;*(float*)(p+0x150)=z;*(int*)(p+0x140)=temp2;*(float*)(p+0x1C)=sp;*(float*)(p+0x2BC)=sc;}{void*veh=*(void**)(p+0x294);void*cb=*(void**)((char*)veh+0x2C0);if(cb!=0){((void(**)(void*,const char*))*(void**)cb)[10](cb,lbl_80333284);((void(*)(int))fn_8013B6A4)(*(int*)(p+0x290));}}*(int*)(p+0x29C)=fn_8013B578(*(int*)(p+0x290));if(fn_801667F0()!=0)fn_8013B6A4(*(int*)(p+0x290),lbl_80562140);{float z=lbl_80562144;float mx=lbl_8056215C;*(float*)(p+0x254)=z;*(float*)(p+0x258)=mx;*(float*)(p+0x2A8)=z;*(float*)(p+0x2A0)=z;}memset(p+0x2FC,0,0xC);*(u8*)(p+0x74)=0;*(u8*)(p+0x250)=0;{float z=lbl_80562144;float u=lbl_805621A0;float e=lbl_805621AC;*(float*)(p+0xE8)=z;*(float*)(p+0xE0)=z;*(float*)(p+0xF0)=z;*(float*)(p+0xF4)=z;*(int*)(p+0x118)=-1;*(int*)(p+0x114)=-1;*(float*)(p+0x248)=z;*(float*)(p+0x234)=u;*(float*)(p+0x22C)=u;*(float*)(p+0x224)=z;*(float*)(p+0x228)=z;*(float*)(p+0x220)=z;*(float*)(p+0x244)=z;*(float*)(p+0x240)=z;*(float*)(p+0x23C)=z;*(int*)(p+0x13C)=-1;*(u8*)(p+0x11C)=0;*(float*)(p+0x120)=z;*(int*)(p+0x98)=0;*(float*)(p+0x94)=u;*(int*)(p+0xC0)=0;*(float*)(p+0xBC)=e;*(u8*)(p+0x9C)=0;*(u8*)(p+0x74)=0;*(float*)(p+0xC4)=z;*(float*)(p+0xD0)=z;*(float*)(p+0xC8)=z;*(float*)(p+0xD4)=z;*(u8*)(p+0xFC)=0;*(int*)(p+0x100)=0;*(int*)((char*)*(void**)(p+0x164)+0xC)=0;}if(*(int*)((char*)*(void**)(p+0x294)+0x1F0)==0x50){int idx=*(int*)(p+0x290);fn_801B30D0(idx);temp=0;if(fn_801B8570(idx)==0){float th=lbl_8055E3C8;if(fn_801B306C()<th)temp=1;}if(temp!=0){fn_802E30C8(lbl_80333294);fn_801B30E0(idx);}}*(float*)(p+0x1D0)=lbl_80562180;{void*s=p+0x19C;((void(**)(void*,int))*(void**)s)[3](s,0);}{void*s=p+0x168;((void(**)(void*,int))*(void**)s)[3](s,0);}fn_80195D80(arg0,limit);*(int*)(p+0x268)=6;*(u8*)(p+0x2A6)=0;*(float*)(p+0x21C)=lbl_80562140;{float*s=(float*)*(void**)(p+0x2C8);*(float*)(p+0x2E0)=s[0x44/4];*(float*)(p+0x2E4)=s[0x48/4];*(float*)(p+0x2E8)=s[0x4C/4];*(float*)(p+0x2EC)=s[0x50/4];*(float*)(p+0x2F0)=s[0x54/4];*(float*)(p+0x2F4)=s[0x58/4];*(float*)(p+0x2F8)=s[0x5C/4];}*(void**)(p+0x2D4)=p+0x2E0;*(void**)(p+0x2D8)=p+0x2E0;*(float*)(p+0x2DC)=limit;*(int*)(p+4)=*(int*)(p+0x290)*4;}
#pragma pop
void fn_8019416C(void) {

}

typedef unsigned int u32;
extern float lbl_80562140, lbl_80562144;
  extern void fn_8018ADB4(int, float);
  extern void fn_8018ADBC(int, float);
  extern void fn_8018ADAC(void *, float);
#pragma scheduling invalid_target
/* Clamp the input to [0,1], store it in the controller's +0x240 slot, and pass
 * the same value to the linked vehicle's setter (fn_8018ADB4). */
void fn_80194170(void *controller, float input) {
#define MAX_LEVEL lbl_80562140
#define MIN_LEVEL lbl_80562144
    float value = MAX_LEVEL < input ? MAX_LEVEL : input;
    value = value > MIN_LEVEL ? value : MIN_LEVEL;
    *(float *)((char *)controller + 0x240) = value;
    fn_8018ADB4(*(int *)((char *)controller + 0x294), (float)(double)value);
#undef MIN_LEVEL
#undef MAX_LEVEL
}
#pragma scheduling invalid_target
void fn_801941A8(void *arg0, float arg1) {
    union FloatWord {
        float f;
        u32 u;
    } otherBits, newBits;
    float *posField = (float *)((char *)arg0 + 0x23C);
    float *velField = (float *)((char *)arg0 + 0x248);
    float change = 0.2f;
    float delta = arg1 - posField[0];
    float pos;
    float velocity;
    float product;
    double finalPos;
    float callPos;

    change = change < delta ? delta : change;
    change = change > -0.2f ? -0.2f : change;
    pos = posField[0];
    velocity = velField[0];
    pos += change;
    posField[0] = pos;
    if (velocity < 2.0f) {
        void *obj = *(void **)((char *)arg0 + 0x294);
        newBits.f = pos;
        otherBits.f = *(float *)((char *)obj + 0x25F0);
        if ((int)(otherBits.u & 0x80000000) != (int)(newBits.u & 0x80000000)) {
            velocity += 0.1f;
            velField[0] = velocity;
        }
    }
    velocity = velField[0];
    {
        float minimum = 1.0f;
        minimum = minimum < velocity ? velocity : minimum;
        minimum = minimum > 0.0f ? 0.0f : minimum;
        product = posField[0] * (1.0f - minimum);
    }
    posField[0] = product;
    product = product < 1.0f ? 1.0f : product;
    product = product > -1.0f ? -1.0f : product;
    finalPos = product;
    callPos = (float)finalPos;
    posField[0] = finalPos;
    fn_8018ADAC(*(void **)((char *)arg0 + 0x294), callPos);
}
#pragma scheduling on
void fn_801942B8(void *obj, float input) {
    /* Clamp the input to [0,1] (upper lbl_80562140=1.0, lower lbl_80562144=0.0),
       store it at +0x244 and pass it to fn_8018ADBC for the field at +0x25E4. */
    float clamped = lbl_80562140 < input ? lbl_80562140 : input;
    clamped = clamped > lbl_80562144 ? clamped : lbl_80562144;
    *(float *)((char *)obj + 0x244) = clamped;
    fn_8018ADBC(*(int *)((char *)obj + 0x294), (float)(double)clamped);
}

void fn_801942F0(void *driver, int forceOn) {
    /* Set the linked vehicle's flag at +0x267C when the driver's drive word has bit 0x20 or the caller's condition holds; otherwise clear it. */
    if ((*(int *)((unsigned char *)driver + 0x2D0) & 0x20) || forceOn != 0) {
        *(int *)((unsigned char *)*(void **)((unsigned char *)driver + 0x294) + 0x267C) = 1;
    } else {
        *(int *)((unsigned char *)*(void **)((unsigned char *)driver + 0x294) + 0x267C) = 0;
    }
}

extern int fn_801B2F24(void);
extern float lbl_80562198, lbl_805621B8, lbl_805621BC, lbl_805621C0, lbl_805621C4;
static inline float Cross2D_80194324(float ax, float ay, float bx, float by) {
    float n = -ay;
    return ax * bx + by * n;
}
#pragma cplusplus on
extern "C" int fn_800216D0(void);
extern "C" void *fn_801B83A0(void);
extern "C" void fn_80194324(void *arg0) {
    char *p = (char *)arg0;
    int flag;
    float thresh;
    float limit;
    if (fn_800216D0()) {
        *(int *)(p + 0x2D0) |= 0x10;
    }
    flag = 1;
    thresh = lbl_80562198;
    limit = lbl_805621B8;
    if (!(*(int *)(p + 0x2D0) & 0x10)) {
        flag = *(float *)(*(char **)(p + 0x294) + 0x25D4) > lbl_805621BC;
        if (flag) {
            float v;
            float t = *(float *)(p + 0x26C) - *(float *)(p + 0x1D0);
            int lt = t < lbl_805621C0;
            if (lt) {
                float k = t / lbl_805621C0;
                float a = Cross2D_80194324(*(float *)(p + 0x1B0), *(float *)(p + 0x1B4), *(float *)(p + 0x1AC), *(float *)(p + 0x1B8));
                float b = Cross2D_80194324(*(float *)(p + 0x17C), *(float *)(p + 0x180), *(float *)(p + 0x178), *(float *)(p + 0x184));
                v = (a - b) * k + b;
            } else {
                v = Cross2D_80194324(*(float *)(p + 0x1B0), *(float *)(p + 0x1B4), *(float *)(p + 0x1AC), *(float *)(p + 0x1B8));
            }
            flag = (float)__fabs(v) < thresh;
        }
        if (!flag) {
            if (*(float *)(p + 0x1D8) >= limit) {
                ((Vt_80194324 *)fn_801B83A0())->v41(*(void **)(p + 0x290));
                *(float *)(p + 0x1D8) = lbl_80562144;
            }
        }
    }
    if (!flag) {
        *(float *)(p + 0x1D8) = *(float *)(p + 0x1D8) + lbl_805621C4;
    } else {
        float x = *(float *)(p + 0x1D8) - lbl_805621C4;
        *(float *)(p + 0x1D8) = (x > lbl_80562144) ? x : lbl_80562144;
    }
}
#pragma cplusplus reset
extern void fn_8018AF04(void *);
extern void fn_80193CD4(void *);
extern unsigned int lbl_8055E540;
extern float lbl_805621A4;
extern char lbl_803332CC[];
#pragma dont_inline on
#pragma cplusplus on
/* Updates active state (+0x2A6) from the sub-object at +0x288: when active, latches
   the start timestamp (+0x1EC) from current time (+0x26C), runs the mode-dependent
   action (lbl_8055E540: reset vehicle at +0x294, trigger disabled state, or set
   flag +0x2A5), and notifies the controller at +0x28C; when inactive, resets +0x1EC to -1.0f. */
extern "C" void fn_801944C0(void *driver) {
    class Controller {
      public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void notifyState(int);
    };
    void *sub;
    sub = *(void **)((char *)driver + 0x288);
    *(u8 *)((char *)driver + 0x2A6) = *(u8 *)((char *)sub + 0x28);
    if (*(u8 *)((char *)driver + 0x2A6)) {
        if (*(float *)((char *)driver + 0x1EC) < lbl_80562144)
            *(float *)((char *)driver + 0x1EC) = *(float *)((char *)driver + 0x26C);
        switch (lbl_8055E540) {
        case 2:
            fn_8018AF04(*(void **)((char *)driver + 0x294));
            break;
        case 1:
            if ((*(int *)((char *)driver + 0x2D0) & 0x200) == 0)
                ((void (*)(void *, const char *))fn_801945F8)(driver, lbl_803332CC);
            break;
        case 0:
            fn_80193CD4(driver);
            break;
        }
        sub = *(void **)((char *)driver + 0x28C);
        ((Controller *)sub)->notifyState(-1);
    } else {
        *(float *)((char *)driver + 0x1EC) = lbl_805621A4;
    }
}
#pragma cplusplus reset
#pragma dont_inline off
/* Initializes the lateral direction scale once, using the driver type and a base offset. */
void fn_80194590(void *driver) {
    int direction;
    if (*(int *)((char *)driver + 0x260) == 0) {
        direction = 1;
        *(int *)((char *)driver + 0x260) = 1;
        if (*(int *)((char *)driver + 0x18) == 1) {
            direction = -1;
        }
        *(float *)((char *)driver + 0x264) = (float)direction * (*(float *)((char *)driver + 0x284) + lbl_8055A488 * lbl_8056215C);
    }
}

extern float lbl_8055A488;
extern float lbl_8056215C;
#pragma dont_inline on
/* Initialize the driver's lateral direction scale via fn_80194590, except in a
 * specific race state: when the object at +0x294 has kind 0x50, skip unless the
 * object at +0x288 holds 3 at +0x24. */
void fn_801945F8(void *driver) {
    if (*(int *)((unsigned char *)*(void **)((unsigned char *)driver + 0x294) + 0x1F0) == 0x50) {
        if (*(int *)((unsigned char *)*(void **)((unsigned char *)driver + 0x288) + 0x24) != 3) {
            return;
        }
        fn_80194590(driver);
        return;
    }
    fn_80194590(driver);
}

extern float *fn_8013A604(void *aiExceptionConfig, float lon); /* AI params covering lon, or the defaults */
void fn_80194624(void *arg0) {
    char *p = (char *)arg0;
    void *r = fn_8013A604((void **)(*(char **)(p + 0x2C8) + 0x40), *(float *)(p + 0x280));
    float q, b, a, c, t;
    if (r != *(void **)(p + 0x2D8)) {
        *(void **)(p + 0x2D4) = *(void **)(p + 0x2D8);
        *(void **)(p + 0x2D8) = r;
        *(float *)(p + 0x2DC) = *(float *)(p + 0x26C);
    }
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    c = 1.0f;
    b = ((float *)*(void **)(p + 0x2D8))[2];
    a = ((float *)*(void **)(p + 0x2D4))[2];
    c = (c < q) ? c : q;
    c = (c > 0.0f) ? c : 0.0f;
    t = a + c * (b - a);
    c = 1.0f;
    *(float *)(p + 0x2E8) = t;
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    b = ((float *)*(void **)(p + 0x2D8))[1];
    a = ((float *)*(void **)(p + 0x2D4))[1];
    c = (c < q) ? c : q;
    c = (c > 0.0f) ? c : 0.0f;
    t = a + c * (b - a);
    c = 1.0f;
    *(float *)(p + 0x2E4) = t;
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    b = ((float *)*(void **)(p + 0x2D8))[3];
    a = ((float *)*(void **)(p + 0x2D4))[3];
    c = (c < q) ? c : q;
    c = (c > 0.0f) ? c : 0.0f;
    t = a + c * (b - a);
    c = 1.0f;
    *(float *)(p + 0x2EC) = t;
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    b = ((float *)*(void **)(p + 0x2D8))[4];
    a = ((float *)*(void **)(p + 0x2D4))[4];
    c = (c < q) ? c : q;
    c = (c > 0.0f) ? c : 0.0f;
    t = a + c * (b - a);
    c = 1.0f;
    *(float *)(p + 0x2F0) = t;
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    b = ((float *)*(void **)(p + 0x2D8))[5];
    a = ((float *)*(void **)(p + 0x2D4))[5];
    c = (c < q) ? c : q;
    c = (c > 0.0f) ? c : 0.0f;
    *(float *)(p + 0x2F4) = a + c * (b - a);
}

/* Initializes per-run state from the linked context and resets runtime timers/flags. */
void fn_80194844(void *obj) {
    extern void fn_801958D8();
    extern void fn_80195F6C(void *, void *);
    extern void fn_80194624(void *);
    extern float lbl_8055E3C8;
    extern float lbl_80562144;
    void *context;
    float zero;

    fn_801958D8();
    context = *(void **)((char *)obj + 0x294);
    *(unsigned char *)((char *)obj + 0x250) = 0;
    *(float *)((char *)obj + 0x270) = *(float *)((char *)context + 0x25D4);
    *(float *)((char *)obj + 0x26C) = lbl_8055E3C8;
    fn_80195F6C(obj, context);
    fn_80194624(obj);
    zero = lbl_80562144;
    *(unsigned char *)((char *)obj + 0x14) = 0;
    *(float *)((char *)obj + 8) = zero;
}

extern float fn_801673A4(int, float *);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
float fn_801948B0(void *arg0, int arg1, float arg2) {
    float *f = (float *)arg0;
    float high = f[0x224/4];
    float one = lbl_80562140;
    float out = lbl_80562144;
    float lim[2];
    float t, current, value, adjust, scale, alt, weight, sample, a, b, factor;
    int mode;
    current = f[0x228/4];
    t = (f[0x26C/4] - f[0x22C/4]) / f[0x230/4];
    factor = one < t ? one : t;
    factor = factor > lbl_80562144 ? factor : lbl_80562144;
    f[0x220/4] = current + factor * (high - current);
    weight = fn_801673A4(*(int *)((char *)arg0 + 0x290), &sample);
    current = f[0x220/4];
    f[0x220/4] = current + weight * (sample - current);
    scale = lbl_8055E544 * ((lbl_80562184 * lbl_8055A488) * f[0x2E4/4]);
    alt = (lbl_805621C0 * lbl_8055A488) * lbl_8055E568;
    weight = fn_801931EC(arg2, f[0x2CC/4]);
    mode = *(int *)((char *)arg0 + 0x268);
    mode = (mode != 0 && mode != 3) ? 0 : 1;
    if (mode) weight *= scale; else weight *= alt;
    adjust = lbl_80562144;
    if (arg1 && *((unsigned char *)arg0 + 0x14)) {
        value = f[2];
        t = weight * lbl_8056215C + (float)__fabs(value) - f[0x274/4];
        t = t > adjust ? t : adjust;
        if (value > lbl_80562144) t *= lbl_80562140; else t *= -lbl_805621A4;
        adjust = t;
    }
    *(int *)&lim[0] = 0; *(int *)&lim[1] = 0;
    out += adjust + f[0x220/4] * weight;
    out += f[0x144/4] * f[0x2E8/4];
    if (arg1) {
        if ((float)__fabs(f[0x278/4]) < lbl_80562174 + f[0x284/4]) {
            a = f[0x274/4];
            b = f[2];
            lim[1] = a - b;
            lim[0] = -a - b;
            out = lim[1] < out ? lim[1] : out;
            out = out > lim[0] ? out : lim[0];
        } else {
            out = lbl_80562144;
        }
    }
    f[0x238/4] = out;
    return out;
}
#pragma pop

#pragma scheduling invalid_target
/* Linearly interpolate between 3D points a and b by t, writing result to out. 
   X/Y are copied through a volatile double pair to preserve the original store/load pattern. */
void fn_80194AF4(void *unused, float *out, float *a, float *b, float t) {
    volatile double xyPair;
    float xyTemp[2];
    float deltaY = b[1] - a[1];
    float deltaX = b[0] - a[0];
    float interpY = a[1] + t * deltaY;
    float interpX = a[0] + t * deltaX;
    xyTemp[1] = interpY;
    xyTemp[0] = interpX;
    xyPair = *(double *)xyTemp;
    out[0] = ((float *)&xyPair)[0];
    out[1] = ((float *)&xyPair)[1];
    out[2] = a[2] + t * (b[2] - a[2]);
}
#pragma scheduling on
extern double fn_8002EFB4(float, float);
extern float lbl_80562140, lbl_80562144, lbl_8056215C, lbl_805621A4, lbl_805621D0, lbl_805621D4;
#pragma processor 750
float fn_80194B60(float a, float b, float c, float d) {
    float ratio;
    float curve;
    d = (float)fn_8002EFB4(d, c);
    if (d > c * lbl_8056215C) {
        d = c - d;
    }
    ratio = d / (c * lbl_8056215C);
    if (ratio < lbl_805621A4) {
        curve = lbl_805621A4;
    } else if (ratio > lbl_80562140) {
        curve = lbl_80562140;
    } else if (ratio > lbl_80562144) {
        curve = ratio * ((lbl_805621D0 * ratio) * ratio) + ((lbl_805621D4 * ratio) * ratio);
    } else {
        curve = ratio * ((lbl_805621D0 * ratio) * ratio) - ((lbl_805621D4 * ratio) * ratio);
    }
    return a + curve * (b - a);
}

extern float fn_80134C1C(void);
extern int fn_801769A8(void);
extern float fn_801B3064(void);
extern void *fn_801B2EC0(int);
extern float fn_80139048(void);
extern float PSQUATMultiply(void *, void *);
extern void fn_80194F70(void *, float *, float *);
extern float lbl_8055A48C, lbl_80562140, lbl_80562144, lbl_80562160;
extern float lbl_80562174, lbl_80562184, lbl_805621D8, lbl_805621DC;
extern double lbl_805621C8;
extern float lbl_805621E0, lbl_805621E4, lbl_805621E8, lbl_805621EC;
#pragma dont_inline on
void fn_80194C4C(void *arg0, float *arg1) {
    void *work;
    float value;
    int i;

    ((void (*)(void *, float *))fn_80194FD0)(arg0, arg1);
    work = *(void **)((char *)arg0 + 0x288);
    value = *(float *)((char *)work + 0x34);
    arg1[0] += *(float *)((char *)arg0 + 0x58) * value;
    arg1[1] += *(float *)((char *)arg0 + 0x5C) * value;
    value = fn_80134C1C();

    if (fn_801769A8() & 0x400) {
        float endValue = lbl_8055E3C8;
        float elapsed = fn_801B3064();
        float ratio = (endValue - elapsed - lbl_80562144) / lbl_805621D8;
        float amount = lbl_80562140;
        if (amount < ratio)
            amount = ratio;
        if (amount > lbl_80562144)
            amount = lbl_80562144;
        value = lbl_80562144 + amount * (value - lbl_80562144);
    }

    if (*(int *)((char *)work + 0x30) == 0) {
        arg1[2] = value;
        i = 0;
        while (i < fn_801B2F24()) {
            void *other = fn_801B2EC0(i);
            if (i != *(int *)((char *)arg0 + 0x290)) {
                void *state = ((void *(*)(void *))(*(void ***)other)[4])(other);
                if (*(int *)((char *)state + 0x30) == 0) {
                    void *owner = *(void **)((char *)arg0 + 0x294);
                    void *track =
                        ((void *(*)(void *))(*(void ***)other)[8])(other);
                    void *ownerAgain =
                        *(void * volatile *)((char *)arg0 + 0x294);
                    float (*distance)(void *, float *, float *) =
                        (float (*)(void *, float *, float *))fn_80194F70;
                    arg1[2] += distance((char *)ownerAgain + 0x54,
                                        (float *)((char *)track + 0x60),
                                        (float *)((char *)owner + 0x60));
                    break;
                }
            }
            ++i;
        }
    } else {
        float threshold = lbl_805621DC + (lbl_8055A48C + fn_80139048());
        float dot = PSQUATMultiply(
            (char *)*(void **)((char *)work + 0x30) + 0x60,
            (char *)*(void **)((char *)arg0 + 0x294) + 0x60);
        if (dot > threshold) {
            float ratio = (dot - threshold) /
                          (lbl_80562174 * threshold - threshold);
            float amount = ratio > lbl_80562140 ? ratio : lbl_80562140;
            amount = amount > lbl_80562144 ? lbl_80562144 : amount;
            arg1[2] = value + amount * ((lbl_80562160 + value) - value);
        } else {
            float base = value - lbl_80562160;
            float ratio;
            float amount = lbl_80562140;
            base = lbl_80562144 < base ? lbl_80562144 : base;
            ratio = (dot - (lbl_805621DC + lbl_8055A48C)) /
                    (threshold - (lbl_805621DC + lbl_8055A48C));
            if (amount < ratio)
                amount = ratio;
            if (amount > lbl_80562144)
                amount = lbl_80562144;
            arg1[2] = base + amount * (value - base);
        }
    }

    {
        int index = *(int *)((char *)arg0 + 0x290);
        float frame = arg1[2] + fn_80194B60(
            lbl_805621E0, lbl_805621E4, lbl_80562184,
            *(float *)((char *)arg0 + 0x26C) +
                lbl_805621E8 * (float)index);
        arg1[3] = lbl_805621EC;
        arg1[2] = frame;
    }
    if (*(int *)((char *)*(void **)((char *)arg0 + 0x294) + 0x2610) == 0) {
        arg1[2] = lbl_80562144;
        *(int *)((char *)arg0 + 0x2D0) |= 0x10;
    }
    {
        void *controller = *(void **)((char *)arg0 + 0x28C);
        ((void (*)(void *, float *, float *, int *))(*(void ***)controller)[11])(
            controller, arg1, arg1 + 2, (int *)((char *)arg0 + 0x2D0));
    }
    *(int *)((char *)arg0 + 0x2D0) |= 0x826;
}
#pragma dont_inline reset
extern float lbl_8055A488, lbl_8056215C;
extern float PSVECDotProduct(const void *, const void *);
extern void fn_8013B744(int);
/* `axis` dotted with the vector from `origin` to `point`: the difference of the
 * two points is built on the stack and handed to PSVECDotProduct, which leaves
 * the product in f1 -- the caller reads it there, so this stays void-returning. */
void fn_80194F70(void * __restrict axis, float * __restrict point, float * __restrict origin) {
    float delta[3];
    delta[0] = point[0] - origin[0];
    delta[1] = point[1] - origin[1];
    delta[2] = point[2] - origin[2];
    PSVECDotProduct(axis, delta);
}

void fn_80194FC4(void) {

}

/* Fetch the per-car scale for this driver's car index (+0x290); the float result is left in f1 for callers, which cast this to Fn94FC8. */
void fn_80194FC8(void *driver) {
    fn_8013B744(*(int *)((unsigned char *)driver + 0x290));
}

void fn_80194FD0(unsigned char *self, float *out, float dt) {
    unsigned char *cfg = P80194FD0(self, 0x2C8);
    Samp80194FD0 b2, a2, b3, a3, s0, sc;
    float q1_2[2], q0_2[2], p1_2[2], p0_2[2];
    float q1_3[2], q0_3[2], p1_3[2], p0_3[2];
    struct V2 { float x, y; } v28;
    float r_2[2], r_3[2];
    float info[2];
    struct V2 v8;
    float f31, f30, t, ret, k;
    int ok, lt, idx;
    s0.a = 0; s0.c = 0x2710; s0.b = 0.0f;
    fn_80135B9C(P80194FD0(self, 0x164), 0, 0, 0, &s0, F80194FD0(cfg, 0x70) + F80194FD0(cfg, 0x6C) * F80194FD0(self, 0x270));
    {
        void *e1 = s0.a;
        void *e2 = s0.a;
        void *n = P80194FD0(e1, 0x14);
        float v = F80194FD0(e2, 0x24);
        void *x = P80194FD0(P80194FD0(self, 0x164), 0x2C);
        ret = ((Fn931AC)fn_801931AC)(x, e1, n, v + s0.b * (F80194FD0(n, 0x24) - v), F80194FD0(cfg, 0x60), F80194FD0(cfg, 0x64), F80194FD0(x, 0x14));
    }
    out[3] = F80194FD0(self, 0x2F0) * ret;
    t = out[3] * F80194FD0(self, 0x270);
    f30 = F80194FD0(P80194FD0(self, 0x2C8), 0x68);
    f30 = (f30 > t) ? f30 : t;
    f31 = F80194FD0(self, 0x26C);
    lt = (f31 - F80194FD0(self, 0x1D0)) < lbl_805621C0;
    if (lt) {
        a2.a = 0; a2.c = 0x2710; a2.b = 0.0f;
        b2.a = 0; b2.c = 0x2710; b2.b = 0.0f;
        fn_80135B9C(self + 0x168, p0_2, q0_2, &r_2[0], &a2, f30);
        fn_80135B9C(self + 0x19C, p1_2, q1_2, &r_2[1], &b2, f30);
        if (out + 2 != 0) {
            k = (f31 - F80194FD0(self, 0x1D0)) / lbl_805621C0;
            out[2] = r_2[0] + k * (r_2[1] - r_2[0]);
        }
        if (out != 0) {
            k = (f31 - F80194FD0(self, 0x1D0)) / lbl_805621C0;
            v8.y = p0_2[1] + k * (p1_2[1] - p0_2[1]);
            v8.x = p0_2[0] + k * (p1_2[0] - p0_2[0]);
            *(double *)&v28 = *(double *)&v8;
            out[0] = v28.x;
            out[1] = v28.y;
        }
        if (self + 8 != 0) {
            void *ea = a2.a, *eb = b2.a;
            float va, vb;
            k = (f31 - F80194FD0(self, 0x1D0)) / lbl_805621C0;
            va = F80194FD0(ea, 0x2C) + a2.b * (F80194FD0(P80194FD0(ea, 0x14), 0x2C) - F80194FD0(ea, 0x2C));
            vb = F80194FD0(eb, 0x2C) + b2.b * (F80194FD0(P80194FD0(eb, 0x14), 0x2C) - F80194FD0(eb, 0x2C));
            F80194FD0(self, 8) = va + k * (vb - va);
        }
    } else if (self + 8 != 0) {
        sc.a = 0; sc.c = 0x2710; sc.b = 0.0f;
        fn_80135B9C(self + 0x19C, out, 0, out + 2, &sc, f30);
        F80194FD0(self, 8) = F80194FD0(sc.a, 0x2C) + sc.b * (F80194FD0(P80194FD0(sc.a, 0x14), 0x2C) - F80194FD0(sc.a, 0x2C));
    } else {
        fn_80135B9C(self + 0x19C, out, 0, out + 2, 0, f30);
    }
    f31 = F80194FD0(self, 0x26C);
    F80194FD0(self, 0xC) = out[0];
    F80194FD0(self, 0x10) = out[1];
    *(unsigned char *)(self + 0x14) = 1;
    lt = (f31 - F80194FD0(self, 0x1D0)) < lbl_805621C0;
    if (lt) {
        a3.a = 0; a3.c = 0x2710; a3.b = 0.0f;
        b3.a = 0; b3.c = 0x2710; b3.b = 0.0f;
        fn_80135B9C(self + 0x168, p0_3, q0_3, &r_3[0], &a3, lbl_805621F0 * f30);
        fn_80135B9C(self + 0x19C, p1_3, q1_3, &r_3[1], &b3, lbl_805621F0 * f30);
        if (out + 2 != 0) {
            k = (f31 - F80194FD0(self, 0x1D0)) / lbl_805621C0;
            out[2] = r_3[0] + k * (r_3[1] - r_3[0]);
        }
    } else {
        fn_80135B9C(self + 0x19C, 0, 0, out + 2, 0, lbl_805621F0 * f30);
    }
    out[2] = out[2] * ((Fn94FC8)fn_80194FC8)(self);
    if (*(unsigned char *)(self + 0x2A6) != 0) {
        float top = lbl_8056217C + F80194FD0(self, 0x1EC);
        float u = (F80194FD0(self, 0x26C) - F80194FD0(self, 0x1EC)) / (top - F80194FD0(self, 0x1EC));
        float w = 1.0f;
        w = (w < u) ? w : u;
        w = (w > 0.0f) ? w : 0.0f;
        out[2] = out[2] * (1.0f + lbl_805621F4 * (0.0f + w * 1.0f));
    }
    ret = ((Fn948B0)fn_801948B0)(self, 0, dt);
    out[0] = out[0] + F80194FD0(self, 0x58) * ret;
    out[1] = out[1] + F80194FD0(self, 0x5C) * ret;
    if (*(int *)(self + 0x268) == 3) {
        float top = lbl_805621F8 + F80194FD0(self, 0x1DC);
        float u = (F80194FD0(self, 0x26C) - F80194FD0(self, 0x1DC)) / (top - F80194FD0(self, 0x1DC));
        float w = 1.0f;
        w = (w < u) ? w : u;
        w = (w > 0.0f) ? w : 0.0f;
        out[2] = out[2] * (1.0f + w * (-0.3f));
    }
    ok = 0;
    if ((lbl_8055D430 & 1) && (lbl_8055D430 & 0x20)) ok = 1;
    idx = *(int *)(self + 0x2C4);
    if (ok != 0 && idx != -1) {
        unsigned char *tbl = (unsigned char *)lbl_8055E0D0;
        void *ent = *(void **)(*(unsigned char **)(tbl + 0x10) + *(int *)(self + 0x290) * *(int *)(tbl + 0xC) + idx * 4 + 0x18);
        if (F80194FD0(ent, 0x18) < 2500.0f) {
            unsigned char *o = fn_8017960C();
            fn_80137788(ent, *(int *)(self + 0x290), info);
            if (info[1] > 0.0f) {
                out[0] = F80194FD0(o, 0x60);
                out[1] = F80194FD0(o, 0x68);
                out[2] = 22.2222f + F80194FD0(o, 0x25CC);
            } else {
                float z = F80194FD0(o, 0x25CC) - lbl_80562160;
                z = (z > lbl_80562160) ? z : lbl_80562160;
                out[2] = z;
            }
        }
    }
    {
        void ***ctl = (void ***)P80194FD0(self, 0x28C);
        ((void (*)(void *, float *, float *, void *))(*ctl)[10])(ctl, out, out + 2, self + 0x2D0);
    }
}

/* Compute a trajectory sample position and offset it by the object's local translation scaled by its current scale. */
void fn_801955F0(void *obj, float *outPos) {
    float scale;
    ((void (*)(void *, float *))fn_80194FD0)(obj, outPos);
    scale = *(float *)((unsigned char *)obj + 0x2B8);
    outPos[0] += *(float *)((unsigned char *)obj + 0x58) * scale;
    outPos[1] += *(float *)((unsigned char *)obj + 0x5C) * scale;
}

extern void fn_801971AC(void *, void *);
extern void fn_801981A0(void *, void *);
extern void fn_8019743C(void *, void *);
extern void fn_80197BD0(void *, void *);
extern void fn_8019724C(void *, float *);
extern unsigned char fn_80167544(int);
void fn_80195654(void *arg0, void *arg1) {
    struct Scratch { int word0, word1; float value0, value1; } scratch;
    float threshold = *(volatile float *)&lbl_805621C0;
    float previous = *(volatile float *)((char *)arg0 + 0x1D0);
    float current = *(volatile float *)((char *)arg0 + 0x26C);
    float difference;
    float interpolated;
    float value;
    int doInterpolate;
    void *first;
    void *second;
    void *left;
    void *right;
    int firstWord;
    int secondWord;
    int flags;

    *(volatile int *)((char *)arg0 + 0x2D0) = 0;
    difference = current - previous;
    doInterpolate = difference < threshold;
    if (doInterpolate) {
        first = *(void **)((char *)arg0 + 0x1A0);
        second = *(void **)((char *)arg0 + 0x16C);
        left = *(void **)((char *)first + 0x14);
        right = *(void **)((char *)second + 0x14);
        {
            float nextA = *(float *)((char *)left + 0x24);
            float baseA = *(float *)((char *)first + 0x24);
            float nextB = *(float *)((char *)right + 0x24);
            float baseB = *(float *)((char *)second + 0x24);
            float deltaA = nextA - baseA;
            float scaleA = *(float *)((char *)arg0 + 0x1A4);
            float deltaB = nextB - baseB;
            float scaleB = *(float *)((char *)arg0 + 0x170);
            float valueA = baseA + scaleA * deltaA;
            float valueB = baseB + scaleB * deltaB;
            float fraction = difference / threshold;
            interpolated = valueB + fraction * (valueA - valueB);
        }
    } else {
        first = *(void **)((char *)arg0 + 0x1A0);
        value = *(float *)((char *)arg0 + 0x1A4);
        left = *(void **)((char *)first + 0x14);
        {
            float base = *(float *)((char *)first + 0x24);
            float next = *(float *)((char *)left + 0x24);
            float delta = next - base;
            interpolated = base + delta * value;
        }
    }
    if (*(int *)((char *)arg0 + 0x268) == 1) {
        ((void (*)(void *, void *, float))fn_80194C4C)(arg0, arg1, interpolated);
    } else {
        ((void (*)(void *, void *, float))fn_80194FD0)(arg0, arg1, interpolated);
        if (*(float *)((char *)arg0 + 0x26C) - *(float *)((char *)arg0 + 0x1E4) <
            *(float *)((char *)arg0 + 0x2BC)) {
            firstWord = ((int *)arg1)[0];
            secondWord = ((int *)arg1)[1];
            scratch.word0 = firstWord;
            scratch.word1 = secondWord;
            scratch.value0 = ((float *)arg1)[2];
            scratch.value1 = ((float *)arg1)[3];
            ((void (*)(void *, float *, float))fn_801955F0)(arg0, (float *)&scratch, interpolated);
            {
                float from = *(float *)((char *)arg0 + 0x26C) - *(float *)((char *)arg0 + 0x1E4);
                float to = *(float *)((char *)arg0 + 0x2BC);
                float t = from / to;
                t = t * t;
                fn_80194AF4(arg0, (float *)arg1, (float *)&scratch, (float *)arg1, t);
            }
        }
    }
    fn_801971AC(arg0, arg1);
    *(float *)((char *)arg0 + 0x1C) = ((float *)arg1)[2];
    fn_801981A0(arg0, arg1);
    fn_8019743C(arg0, arg1);
    fn_80197BD0(arg0, arg1);
    fn_8019724C(arg0, arg1);
    flags = ((int (*)(int))fn_80167544)(*(int *)((char *)arg0 + 0x290));
    if (flags != 0) {
        *(int *)((char *)arg0 + 0x2D0) |= 0x50;
    }
}

/* Computes a normalized 2D output direction from the object's XY (at +0x20) with minimum length clamp. */
void fn_80195830(void *arg0) {
    struct Fields { unsigned char pad[0x20]; float x; float y; unsigned char mid[0x18]; float outX; float outY; };
    struct Fields* obj = (struct Fields*)arg0;
    float length, denominator, scale;
    ((void (*)(void*, void*))fn_80195654)(arg0, (void*)((unsigned long)arg0 + 0x20));
    fn_801933FC(obj, &obj->x);
    obj->outX = obj->x;
    obj->outY = obj->y;
    length = (float)fn_8002F234(obj->x * obj->x + obj->y * obj->y);
    denominator = lbl_80562148;
    denominator = denominator > length ? denominator : length;
    scale = lbl_80562140 / denominator;
    obj->outX *= scale;
    obj->outY *= scale;
}

extern void fn_801958D8();
extern void fn_80195F6C(void *, void *);
extern void fn_80194624(void *);
extern float lbl_8055E3C8;
extern float lbl_80562144;
extern void fn_80195654(void *, void *);
extern void fn_801933FC(void *, void *);
extern double fn_8002F234(float);
extern float lbl_80562140;
extern float lbl_80562148;
extern float lbl_80562204;
/* Damp the controller's forward velocity (+0x248) by a fixed traction factor
 * (lbl_80562204 ~= 0.9409). */
void fn_801958C4(void *controller) { *(float *)((unsigned char *)controller+0x248) *= lbl_80562204; }

extern char lbl_803332D8[];
extern float lbl_805621A0;
extern void fn_802E317C(const char *, ...);
void fn_801958D8(void *arg0) {
    void *tmp;
    int state;
    float f;
    tmp = *(void **)((char *)arg0 + 0x288);
    state = *(int *)((char *)tmp + 0x24);
    if (*(int *)((char *)arg0 + 0x268) != state) {
        switch (state) {
        case 0:
            *(float *)((char *)arg0 + 0x1E4) = *(float *)((char *)arg0 + 0x26C);
            *(float *)((char *)arg0 + 0x2B8) = *(float *)((char *)tmp + 0x34);
            *(int *)((char *)arg0 + 0x260) = 0;
            break;
        case 1:
            *(float *)((char *)arg0 + 0x1E8) = lbl_805621A0;
            break;
        case 3:
            *(float *)((char *)arg0 + 0x1DC) = *(float *)((char *)arg0 + 0x26C);
            if (*(float *)((char *)arg0 + 0x278) > lbl_80562144) {
                f = lbl_80562140;
            } else {
                f = lbl_805621A4;
            }
            *(float *)((char *)arg0 + 0x2C0) = f;
            break;
        default:
            fn_802E317C(lbl_803332D8);
            break;
        }
        *(int *)((char *)arg0 + 0x268) = state;
    }
}

/* Updates a state machine/object step, applying damage/offroad checks and idle tracking. */
void fn_801959AC(void *arg0) {
    extern double __fabs(double);
    extern char lbl_80558DC4[];
    extern float lbl_80562140, lbl_80562144, lbl_805621DC, lbl_80562208;
    extern char lbl_803332F8[];
    extern char lbl_8055A4B0;
    unsigned char *self = (unsigned char *)arg0;
    void *linkedObj;
    float delta;
    float stateDifference;
    int state;
    int idle;

    if (self[0x2A7]) {
        linkedObj = *(void **)(self + 0x294);
        if (*(int *)((char *)linkedObj + 0x2620) > 0) {
            self[0x2A7] = 0;
            fn_8018A174(linkedObj);
        }
    }

    linkedObj = *(void **)(self + 0x294);
    if (!((float)__fabs((double)*(float *)((char *)linkedObj + 0x2690)) <= *(float *)lbl_80558DC4))
        ((void (*)(void *, const char *))fn_801961F8)(arg0, lbl_803332F8);

    fn_80195B28(arg0, lbl_80562144);
    delta = *(float *)(self + 0x26C) - *(float *)(self + 0x1F4);
    fn_801942F0(arg0, delta > lbl_80562140);

    state = *(int *)(self + 0x260);
    switch (state) {
    case 1:
        stateDifference = *(float *)(self + 0x264);
        stateDifference = *(float *)(self + 0x278) - stateDifference;
        if ((float)__fabs((double)stateDifference) < lbl_805621DC)
            *(int *)(self + 0x260) = 2;
        break;
    case 2:
        if (*(float *)(self + 0x270) < lbl_80562208)
            fn_80193CD4(arg0);
        break;
    }

    if ((float)__fabs((double)*(float *)(self + 0x278)) >
            lbl_80562140 + *(float *)(self + 0x284) &&
        !(*(int *)(self + 0x2D0) & 8))
        ((void (*)(void *, const char *))fn_8019416C)(arg0, &lbl_8055A4B0);

    linkedObj = *(void **)(self + 0x294);
    idle = *(int *)((char *)linkedObj + 0x2620) == 0;
    if (idle && !self[0x208])
        *(float *)(self + 0x204) = *(float *)(self + 0x26C);
    self[0x208] = idle;
}

void fn_80195B28(void *arg0, float arg1) {
    float *p = (float *)arg0;
    float *table;
    float value;
    float scale;
    unsigned int tableValue;
    unsigned int expected = 0x180201u;
    unsigned int d1, d2;
    int index;
    unsigned int selected;

    if (p[0x234 / 4] < p[0x26C / 4] || lbl_80562144 != arg1) {
        table = (float *)__AXFXGetLfoSinTable_801769CC();
        tableValue = *(unsigned int *)((char *)table + 4);
        d1 = expected - tableValue;
        d2 = tableValue - expected;
        if ((d1 | d2) >> 31) {
            index = *(int *)((char *)arg0 + 0x268);
            selected = (unsigned int)__cntlzw(index - 1) >> 5;
            table = lbl_80333308;
            if (selected)
                table += 3;
            {
                float base = p[0x26C / 4];
                float first = table[0];
                p[0x22C / 4] = base;
                p[0x234 / 4] = fn_80129DC4(3, first, table[1]);
            }
            if (!selected)
                p[0x234 / 4] *= lbl_8055E56C;
            p[0x228 / 4] = p[0x220 / 4];
            p[0x234 / 4] += p[0x26C / 4];
            p[0x230 / 4] = table[2];
            if (selected)
                p[0x224 / 4] = fn_80129DC4(3, lbl_8056220C, lbl_8056215C);
            else
                p[0x224 / 4] = fn_80129DC4(3, lbl_805621A4, lbl_80562140);
            if (lbl_80562144 != arg1) {
                value = (float)__fabs((double)p[0x224 / 4]);
                if (arg1 > lbl_80562144)
                    scale = lbl_80562140;
                else
                    scale = lbl_805621A4;
                p[0x224 / 4] = scale * value;
            }
        } else {
            p[0x234 / 4] = p[0x26C / 4];
            p[0x228 / 4] = lbl_80562144;
            p[0x224 / 4] = lbl_80562144;
            p[0x22C / 4] = p[0x26C / 4];
            p[0x230 / 4] = p[0x26C / 4];
        }
    }
}

extern void fn_80194324();
extern void fn_801944C0(void *);
extern float lbl_805621BC, lbl_80562210, lbl_80562214, lbl_80562218;
/* Periodically refreshes an object's state, updates a timed fade/state transition
 * based on threshold checks, and advances its tick counter. */
void fn_80195CA8(void *arg0) {
    int savedMode;
    if (!(*(int *)((char *)arg0 + 4) & 0x7F)) {
        fn_80194324();
        fn_801944C0(arg0);
    }
    if (*(float *)((char *)arg0 + 0x270) < lbl_805621BC &&
        *(float *)((char *)arg0 + 0x2A0) > lbl_80562210) {
        *(float *)((char *)arg0 + 0x2A0) = lbl_80562214;
        if (*(int *)((char *)arg0 + 0x260) == 0) {
            savedMode = *(int *)((char *)arg0 + 0x210);
            if (savedMode != 1) {
                if (*(int *)((char *)arg0 + 0x214) == 2) {
                    *(int *)((char *)arg0 + 0x214) = savedMode;
                    *(int *)((char *)arg0 + 0x210) = 1;
                } else {
                    *(int *)((char *)arg0 + 0x210) = 1;
                }
                *(float *)((char *)arg0 + 0x218) = *(float *)((char *)arg0 + 0x26C);
            }
        } else {
            *(int *)((char *)arg0 + 0x260) = 2;
        }
    } else {
        *(float *)((char *)arg0 + 0x2A0) *= lbl_80562218;
    }
    ++*(int *)((char *)arg0 + 4);
}

extern int fn_801388F4(void *);
extern void fn_801353C4(void *, float *);
extern float lbl_805621C0;
struct Shape_80195D80 {
    unsigned char pad0[0x14];
    float f14;
    unsigned char pad1[0x10];
    int f28;
};
struct SnapHead_80195D80 {
    void *w0;
    unsigned int w[2];
};
struct SnapBody_80195D80 {
    unsigned int w[6];
};
struct Snap_80195D80 {
    struct SnapHead_80195D80 h;
    struct SnapBody_80195D80 body;
    unsigned char b;
    struct Shape_80195D80 *shape;
    unsigned int w2;
};
struct Obj_80195D80 {
    unsigned int pad;
    struct Snap_80195D80 snap;
};
#pragma cplusplus on
class Vt_80195D80 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4();
    virtual Obj_80195D80 *v5();
};
struct Other_80195D80 {
    unsigned char p0[0x54];
    float a54, a58, a5c;
    unsigned char p1[0x94 - 0x60];
    float a94, a98, a9c;
    unsigned char p2[0x5BC - 0xA0];
    float a5bc;
};
struct Self_80195D80 {
    unsigned char p0[0x18];
    int f18;
    unsigned char p1[0x168 - 0x1C];
    unsigned char f168[4];
    struct Snap_80195D80 prev;
    unsigned char p2[4];
    struct Snap_80195D80 cur;
    float f1d0;
    unsigned char p3[0x28C - 0x1D4];
    void *src;
    unsigned char p4[4];
    struct Other_80195D80 *other;
    unsigned char p5[0x2C8 - 0x298];
    int f2c8;
    float f2cc;
};
#pragma opt_propagation reset
extern "C" void fn_80195D80(void *arg0, float arg1) {
    Self_80195D80 *self = (Self_80195D80 *)arg0;
    Obj_80195D80 *obj = ((Vt_80195D80 *)self->src)->v5();
    Shape_80195D80 *next;
    int changed;
    int cond;
    float vec[5];
    Other_80195D80 *o;
    Shape_80195D80 *shape;
    self->f2cc = obj->snap.shape->f14;
    self->f2c8 = obj->snap.shape->f28;
    self->f18 = fn_801388F4(obj->snap.h.w0);
    changed = 0;
    shape = self->cur.shape;
    o = self->other;
    next = obj->snap.shape;
    if (shape != 0 && shape != next) {
        changed = 1;
    }
    if (changed) {
        self->prev.h.w0 = self->cur.h.w0;
        self->prev.h.w[0] = self->cur.h.w[0];
        self->prev.h.w[1] = self->cur.h.w[1];
        self->prev.body.w[0] = self->cur.body.w[0];
        self->prev.body.w[1] = self->cur.body.w[1];
        self->prev.body.w[2] = self->cur.body.w[2];
        self->prev.body.w[3] = self->cur.body.w[3];
        self->prev.body.w[4] = self->cur.body.w[4];
        self->prev.body.w[5] = self->cur.body.w[5];
        self->prev.b = self->cur.b;
        self->prev.shape = self->cur.shape;
        self->prev.w2 = self->cur.w2;
        self->f1d0 = lbl_8055E3C8;
    }
    self->cur.h = obj->snap.h;
    self->cur.body = obj->snap.body;
    self->cur.b = obj->snap.b;
    self->cur.shape = obj->snap.shape;
    self->cur.w2 = obj->snap.w2;
    cond = arg1 - self->f1d0 < 1.5f;
    if (cond) {
        float dy, dz, dx, s;
        float x, y, z;
        s = o->a5bc;
        dx = o->a54;
        dy = o->a58;
        dz = o->a5c;
        x = o->a94 + dx * s;
        y = o->a98 + dy * s;
        vec[2] = x;
        z = o->a9c + dz * s;
        vec[0] = x;
        vec[3] = y;
        vec[4] = z;
        vec[1] = z;
        fn_801353C4(self->f168, vec);
    }
}
extern "C" void fn_80135B9C(void *, void *, void *, void *, void *, float);
extern "C" int fn_802E30C8(const char *, ...);
void fn_80195F6C(void *arg0, void *arg1) {
    extern float lbl_8055A488, lbl_8055A48C, lbl_8056215C, lbl_805621DC, lbl_80562210, lbl_8056221C;
    extern double lbl_80562220;
    extern float lbl_80562228, lbl_8056222C;
    extern char lbl_8033332C[];
    struct Trio { void *p; float f; int i; };
    char *self = (char *)arg0;
    Trio sp24;
    Trio sp18;
    double u1, u2;
    float f2;
    float scale;
    float keep;
    float m, t;
    int flag;
    char *obj;

    if (*(unsigned char *)(self + 0x2A5) == 0) {
        obj = *(char **)(self + 0x164);
        sp24.p = *(void **)(obj + 4);
        sp24.f = *(float *)(obj + 8);
        sp24.i = *(int *)(obj + 0xC);
        fn_80195D80(arg0, *(float *)(self + 0x26C));
        *(int *)(*(char **)(self + 0x164) + 0xC) = 0;
        f2 = *(float *)(*(char **)(*(char **)(self + 0x164) + 4) + 0x28);
        if (!(*((unsigned char *)sp24.p + 0x35) & 1)) {
            f2 = f2 * lbl_80562210;
        }
        scale = lbl_8056215C;
        flag = 1;
        *(float *)(self + 0x284) = scale * f2;
        *(float *)(self + 0x274) = scale * (f2 - lbl_8055A488) - lbl_8056221C;
        if (*(int *)(self + 0x268) != 0 && *(int *)(self + 0x268) != 3) {
            flag = 0;
        }
        if (flag == 0) {
            *(float *)(self + 0x274) = *(float *)(self + 0x274) - lbl_805621DC;
        }
        if (*(float *)(self + 0x274) <= lbl_80562144) {
            fn_802E30C8(lbl_8033332C, u1, u2, (double)lbl_8055A488, lbl_80562220);
        }
        obj = *(char **)(self + 0x164);
        *(float *)(self + 0x278) = *(float *)(obj + 0x40);
        t = lbl_80562228 * *(float *)(self + 0x270);
        keep = lbl_8056215C;
        *(float *)(self + 0x280) = *(float *)(obj + 0x48);
        *(float *)(self + 0x27C) = *(float *)(obj + 0x44);
        *(unsigned char *)(self + 0x2FE) = 0;
        m = lbl_8055A48C;
        switch (m > t) {
        case 0: m = t; break;
        default: break;
        }
        sp18.p = 0;
        sp18.i = 0x2710;
        sp18.f = lbl_80562144;
        fn_80135B9C(*(void **)(self + 0x164), 0, 0, self + 0x50, &sp18, m);
        *(float *)(self + 0x54) = keep;
        *(void **)(self + 0x68) = sp18.p;
        *(float *)(self + 0x6C) = sp18.f;
        *(int *)(self + 0x70) = sp18.i;
        if (*((unsigned char *)sp18.p + 0x34) == 3) {
            *(float *)(self + 0x50) = lbl_8056222C;
        }
        if (sp18.p != 0) {
            char *a = (char *)sp18.p;
            char *b = *(char **)(a + 0x14);
            float v[4];
            float inv;
            v[0] = *(float *)(a + 8) + sp18.f * (*(float *)(b + 8) - *(float *)(a + 8));
            v[1] = *(float *)(a + 0xC) + sp18.f * (*(float *)(b + 0xC) - *(float *)(a + 0xC));
            v[2] = *(float *)(a + 0) + sp18.f * (*(float *)(b + 0) - *(float *)(a + 0));
            v[3] = *(float *)(a + 4) + sp18.f * (*(float *)(b + 4) - *(float *)(a + 4));
            inv = lbl_80562140 / (float)fn_8002F234(v[0] * v[0] + v[1] * v[1]);
            *(float *)(self + 0x48) = v[2];
            *(float *)(self + 0x4C) = v[3];
            v[0] = v[0] * inv;
            v[1] = v[1] * inv;
            *(float *)(self + 0x58) = v[1];
            *(float *)(self + 0x5C) = -v[0];
            *(float *)(self + 0x60) = v[0];
            *(float *)(self + 0x64) = v[1];
        }
    }
}

#pragma cplusplus reset

  void fn_801961F8(void) {

}

/* Per-frame orbit (race-director) scaling for one AI driver, run first in the
 * driver's state-0 tick (fn_80198530, from fn_801967A4 case 0).
 *
 * The car's current orbit speed factor -- the rubber-band multiplier the orbit
 * automation keeps per car (fn_801671FC; 1.0 while the automation is off, and
 * bounded by the value file's "max_sf") -- is folded into the driver's own
 * speed scalar at +0x28.  Once the game mode's timer (fn_801B841C steps it by
 * one 1/60 s frame while the mode runs) has passed 4 s, the driver also forces
 * the drive word at +0x2D0 on: 0x1150 = 0x10 | 0x40 | 0x100 | 0x1000, the same
 * word fn_80194C4C hands to the steering controller. */
void fn_801961FC(void *driver) {
    #define DRV_SPEED_SCALAR(driver) (*(float *)((char *)(driver) + 0x28))
    #define DRV_CAR_INDEX(driver) (*(int *)((char *)(driver) + 0x290))
    #define DRV_DRIVE_FLAGS(driver) (*(int *)((char *)(driver) + 0x2D0))
    #define Orbit_GetSpeedFactor fn_801671FC
    #define ModeTimerPastIntro fn_801B89F8
    extern float Orbit_GetSpeedFactor(int);
    extern int ModeTimerPastIntro(void);
    DRV_SPEED_SCALAR(driver) *= Orbit_GetSpeedFactor(DRV_CAR_INDEX(driver));
    if (ModeTimerPastIntro() != 0) {
        DRV_DRIVE_FLAGS(driver) |= 0x1150;
    }
    #undef DRV_SPEED_SCALAR
    #undef DRV_CAR_INDEX
    #undef DRV_DRIVE_FLAGS
    #undef Orbit_GetSpeedFactor
    #undef ModeTimerPastIntro
}

extern float lbl_80562140, lbl_80562144, lbl_80562168;
extern float lbl_80562208, lbl_80562230, lbl_80562234, lbl_80562238;
extern float __fabsf(float);
#pragma opt_propagation off
void fn_80196250(float *arg0, float *arg1, int *arg2, float farg0, float farg1, float farg2) {
    float temp_f5;
    double mag0;
    float abs0;
    float sp8;
    float spC;
    float value1;
    float value0;
    float out1;
    float out0;
    int var_r0;
    temp_f5 = farg0 - farg1;
    temp_f5 += lbl_80562230;
    temp_f5 /= farg2;
    mag0 = __fabs((double)farg0);
    abs0 = (float)mag0;
    if (abs0 < lbl_80562168) {
        value0 = lbl_80562140;
        value1 = lbl_80562144;
        *arg1 = value0;
        *arg0 = value1;
        *arg2 = 0;
        return;
    }
    if ((float)__fabs((double)farg1) < lbl_80562208)
        goto direct_case;
    spC = farg1;
    sp8 = temp_f5;
    if ((int)(*(unsigned int *)&spC & 0x80000000U) != (int)(*(unsigned int *)&sp8 & 0x80000000U))
        goto different_sign;
direct_case:
    out1 = lbl_80562144;
    out0 = (float)__fabs((double)temp_f5) / lbl_80562234;
    *arg0 = out0;
    *arg1 = out1;
    goto finish;
different_sign:
    out0 = lbl_80562144;
    out1 = (float)__fabs((double)temp_f5) / lbl_80562238;
    *arg0 = out0;
    *arg1 = out1;
finish:
    if (farg0 > lbl_80562144)
        var_r0 = 1;
    else
        var_r0 = -1;
    *arg2 = var_r0;
}
#pragma opt_propagation reset
  extern float fn_801671FC(int);
  extern int fn_801B89F8(void);
  extern int lbl_8055E0D0;
  extern void fn_8018ADAC(void *, float);
  extern void fn_8018AE24(int, int);
  extern void fn_80136EA4(int, int);
  extern void fn_80136E8C(int, int, int);
#pragma scheduling invalid_target
void fn_80196328(void *arg0) {
    const f32 one = lbl_80562140;
    fn_8018ADBC(*(int *)((char *)arg0 + 0x294), one);
    fn_8018ADB4(*(int *)((char *)arg0 + 0x294), lbl_80562144);
    fn_8018ADAC(*(void **)((char *)arg0 + 0x294), lbl_80562144);
    fn_8018AE24(*(int *)((char *)arg0 + 0x294), 0);
    fn_80136EA4(lbl_8055E0D0, *(int *)((char *)arg0 + 0x290));
    fn_80136E8C(lbl_8055E0D0, *(int *)((char *)arg0 + 0x290), 0);
}
      extern int fn_801B2F24(void);
    extern void fn_801B2F40(int);
          extern int fn_8019643C();
      void fn_80194844();
      void fn_8019639C(void) {
      fn_80194844();
  }

#pragma dont_inline on
void fn_801963A0(void *state) {
    /* Trigger one state step, accumulate a scaled delta, notify, then run update helpers. */
    void *obj;
    float value;
    float delta;
    ((void (*)(void *, int))fn_801961F8)(state, 0);
    obj = *(void **)((char *)state + 0x294);
    value = *(float *)((char *)obj + 0x25D4);
    delta = lbl_8056223C * value;
    lbl_8055E57C += delta;
    ((void (*)(int, int, int, float, float))fn_80136E8C)(lbl_8055E0D0, *(int *)((char *)state + 0x290), 1, delta, value);
    fn_801958C4(state);
    fn_801959AC(state);
    fn_80195CA8(state);
}
#pragma dont_inline reset
  void fn_80196414(void *arg0) {
      fn_80196DC4(arg0);
  }

#pragma dont_inline on
/* Normalize the controller's XY vector (fn_80195830), but only while its state is 0. */
void fn_80196418(void *controller) {
    int state = *(int *)((char *)controller + 0x210);
    if (state == 1) {
        goto done;
    }
    if (state >= 1) {
        goto done;
    }
    if (state >= 0) {
        goto tail;
    }
done:
    return;
tail:
    fn_80195830(controller);
}

int fn_8019643C(int carIndex) {
#define CAR_TAG_PLAYER_CAR 0x50434152 /* 'PCAR' */
    /* True when the car at carIndex in the car table carries the player-car FourCC at +0x10. */
    return *(int *)(lbl_804348E8[carIndex] + 0x10) == CAR_TAG_PLAYER_CAR;
#undef CAR_TAG_PLAYER_CAR
}

#pragma dont_inline reset
      extern int fn_801B2F24(void);
    extern void fn_801B2F40(int);
    extern int fn_8019643C();
/* Iterate entries from startIndex to end and return 1 if any checked entry matches the target type. */
int fn_80196468(int startIndex) {
      int end = fn_801B2F24();
      int i = startIndex;
      while (i <= end) {
          fn_801B2F40(i - 1);
          if (fn_8019643C() != 0) return 1;
          i++;
      }
      return 0;
  }

extern int fn_80129D18(int, int);
extern void fn_8018A174(void *);
extern void fn_8017B4AC(void *, float *, float, float);
extern float lbl_80562240;
#pragma cplusplus on
/* Conditionally applies a random directional impulse to the object's secondary controller. */
extern "C" void fn_801964D0(void *arg0) {
    float vector[3];
    float scale;
    float temp_f1;
    float temp_f2;
    float var_f3;
    Vt_80194C4C *controller;

    controller = (Vt_80194C4C *)*(void **)((char *)arg0 + 0x28C);
    if (fn_80196468(*(int *)((char *)controller->v2() + 4)) != 0) {
        *((unsigned char *)arg0 + 0x2A7) = 1;
        if (fn_80129D18(3, 10) < 5) {
            fn_8018A174(*(void **)((char *)arg0 + 0x294));
            if (fn_80129D18(3, 2) != 0)
                var_f3 = lbl_805621A4;
            else
                var_f3 = lbl_80562140;

            controller = (Vt_80194C4C *)*(void **)((char *)arg0 + 0x294);
            scale = *(float *)((char *)controller + 0xD4);
            temp_f2 = lbl_805621AC * scale;
            temp_f1 = lbl_80562240 * temp_f2;
            temp_f1 *= var_f3;
            vector[0] = *(float *)((char *)controller + 0x3C) * temp_f1;
            vector[1] = *(float *)((char *)controller + 0x40) * temp_f1;
            vector[2] = *(float *)((char *)controller + 0x44) * temp_f1;
            fn_8017B4AC(*(void **)((char *)arg0 + 0x294), vector, temp_f1, temp_f2);
        }
    }
}
#pragma cplusplus reset
extern float lbl_80562140, lbl_80562144, lbl_80562184, lbl_805621A4;
extern float lbl_805621EC, lbl_80562244, lbl_80562248;
extern void fn_801EA18C(void *, void *, int, int, void *, float);
extern void fn_8018AE2C(void *, float);
extern void fn_8018AE34(void *, float);

/* The truck's world transform in the vehicle object reached at +0x294: three
 * basis vectors followed by the translation (basis X at +0x3C, Y at +0x48, Z at
 * +0x54, translation at +0x60). Dotted with the world up vector, basis Z says how
 * far the nose is up and basis X how far the right side is up. */
typedef struct TruckXf {
    float right[3];    /* basis X */
    float up[3];       /* basis Y */
    float forward[3];  /* basis Z */
    float position[3]; /* translation */
} TruckXf;
#define TRUCK_XF(vehicle) ((TruckXf *)((char *)(vehicle) + 0x3C))

/* fn_801EA18C is handed the point to drop to the terrain as whole words (the
 * truck's position) and writes the ground point back as floats: x, the terrain
 * height there, z.  Its second argument comes back as the terrain's surface
 * normal, so it is seeded with the world up for the case where the query finds
 * nothing (fn_801EA18C -> fn_801DCE14 -> fn_801DB74C -> fn_801DB514). */
typedef union GroundPoint {
    int word[3];
    float f[3];
} GroundPoint;

/* The truck object this controller drives, reached through its +0x294 link. */
#define CTRL_TRUCK(controller) (*(void **)((char *)(controller) + 0x294))
/* Truck flag: non-zero while something else holds the body tilt still. */
#define TRUCK_TILT_FROZEN(truck) (*(int *)((char *)(truck) + 0x2620))
/* How far below the truck's origin its ground contact sits; negative. */
#define TRUCK_GROUND_DEPTH(truck) (*(float *)((char *)(truck) + 0x11C))
/* Controller's sprung air value at +0x23C (fn_801941A8 springs it towards a
 * target and hands the same value to the truck). */
#define CTRL_AIR_VALUE(controller) (*(float *)((char *)(controller) + 0x23C))

#define F_ZERO lbl_80562144 /* 0.0f */
#define F_ONE lbl_80562140 /* 1.0f */
#define TILT_SCALE lbl_80562184 /* 5.0f: turns an axis/up dot into a -1..1 tilt */
#define TILT_MIN lbl_805621A4 /* -1.0f: tilts are clamped to -1..1 */
#define GROUND_DEPTH_FLOOR lbl_80562244 /* -0.01f: keeps the ground depth off zero */
#define PITCH_CUTOFF lbl_805621EC /* 0.7f: nose-up wanted when off the ground */
#define PITCH_CUTOFF_SWEEP lbl_80562248 /* -1.1f: how far that cut-off falls */
void fn_801965AC(void *controller) {
    /* Body tilt tick for a truck controller in its grounded state (fn_801967A4
     * case 0).  The truck's position is dropped onto the terrain, which hands
     * back the ground point and the surface normal there (normal keeps the
     * world up it is seeded with if the query finds nothing).  Close enough to
     * the ground - within the truck's own ground depth - the body's pitch and
     * roll follow that normal, so it leans with the slope.  Further up, the
     * roll goes flat and the nose is aimed up, the wanted nose-up falling from
     * 0.7 to -0.4 as the controller's air value runs from 0 to 1.  Either way
     * the tilt is scaled by 5 and clamped to -1..1 before the truck's physics
     * picks it up (fn_8018AE2C pitch, fn_8018AE34 roll).  Held still while the
     * truck's +0x2620 flag is set. */
    float normal[3];
    GroundPoint ground;
    float airHeight;
    float groundDepth;
    float amount;
    float aboveGround;
    float pitch;
    float tiltScale;
    float noseUp;
    float scaled;
    int nearGround;
    int positionX;
    int positionY;
    char *truck;

    if (TRUCK_TILT_FROZEN(CTRL_TRUCK(controller)) != 0)
        return;

    normal[0] = F_ZERO;
    normal[1] = F_ONE;
    normal[2] = F_ZERO;
    truck = (char *)CTRL_TRUCK(controller);
    positionX = *(int *)(truck + 0x60);   /* the translation, as words */
    positionY = *(int *)(truck + 0x64);
    ground.word[0] = positionX;
    ground.word[1] = positionY;
    ground.word[2] = *(int *)(truck + 0x68);
    fn_801EA18C(&ground, normal, 0, ground.word[0], truck, F_ZERO);

    truck = (char *)CTRL_TRUCK(controller);
    airHeight = F_ZERO;
    aboveGround = TRUCK_XF(truck)->position[1] - ground.f[1];
    airHeight = airHeight > aboveGround ? airHeight : aboveGround;
    groundDepth = TRUCK_GROUND_DEPTH(truck);
    groundDepth = groundDepth < GROUND_DEPTH_FLOOR ? groundDepth : GROUND_DEPTH_FLOOR;
    amount = F_ONE;
    nearGround = (-airHeight / groundDepth) < amount;
    tiltScale = TILT_SCALE;
    if (nearGround) {
        float clamped;
        scaled = tiltScale * PSVECDotProduct(normal, TRUCK_XF(truck)->forward);
        clamped = F_ONE;
        clamped = clamped < scaled ? clamped : scaled;
        clamped = clamped > TILT_MIN ? clamped : TILT_MIN;
        fn_8018AE2C(CTRL_TRUCK(controller), clamped);

        scaled = tiltScale * PSVECDotProduct(normal, TRUCK_XF(CTRL_TRUCK(controller))->right);
        clamped = F_ONE;
        clamped = clamped < scaled ? clamped : scaled;
        clamped = clamped > TILT_MIN ? clamped : TILT_MIN;
        fn_8018AE34(CTRL_TRUCK(controller), clamped);
        return;
    }

    pitch = __fabs(CTRL_AIR_VALUE(controller));
    pitch = (pitch - F_ZERO) / amount;
    amount = amount < pitch ? amount : pitch;
    amount = amount > F_ZERO ? amount : F_ZERO;
    noseUp = TRUCK_XF(truck)->forward[1] - (PITCH_CUTOFF + amount * PITCH_CUTOFF_SWEEP);
    scaled = tiltScale * noseUp;
    pitch = F_ONE;
    pitch = pitch < scaled ? pitch : scaled;
    pitch = pitch > TILT_MIN ? pitch : TILT_MIN;
    fn_8018AE2C(truck, pitch);
    fn_8018AE34(CTRL_TRUCK(controller), F_ZERO);
}

extern void fn_80196AA0(void *);
extern void fn_80198530(void *);
void fn_801967A4(void *controller) {
    /* Dispatch the controller's per-tick update based on its current state. */
    int state = *(int *)((char *)controller + 0x210);
    switch (state) {
    case 0:
        fn_80198530(controller);
        fn_801965AC(controller);
        return;
    case 1:
        fn_80196AA0(controller);
        return;
    }
}

/* Resets a transient counter and updates a clamped value based on a state flag. */
void fn_801967FC(void *object) {
    float incrementedValue;
    float clampedValue;
    *(int *)((char *)object + 0x300) = 0;
    if ((int)*(u8 *)((char *)object + 0x250) != 0) {
        *(float *)((char *)object + 0x254) *= lbl_8056224C;
        return;
    }
    clampedValue = lbl_80562140;
    incrementedValue = lbl_80562148 + *(float *)((char *)object + 0x254);
    if (clampedValue < incrementedValue) {
        clampedValue = clampedValue;
    } else {
        clampedValue = incrementedValue;
    }
    *(float *)((char *)object + 0x254) = clampedValue;
}

extern int fn_801796B4(void);
extern int fn_80134A44(int);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_8019684C(void) {
    struct List { int count; void *entry[8]; };
    struct Controller {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void update();
    };
    struct Controllers { Controller *entries[8]; int count; };
    List active, inactive;
    int mode, i;
    Controllers *controllers;
    Controller **iter;
    active.count = 0;
    inactive.count = 0;
    mode = fn_801796B4();
    for (i = 0; i < 8; i++) {
        void *obj = ((void **)lbl_804349C0)[i];
        if (obj && fn_80134A44(i) && *((unsigned char *)obj + 0x2A4)) {
            if (mode || *((unsigned char *)obj + 0x2A5)) inactive.entry[inactive.count++] = obj;
            else active.entry[active.count++] = obj;
        }
    }
    for (i = 0; i < inactive.count; i++) ((void (*)(void *))fn_8019639C)(inactive.entry[i]);
    for (i = 0; i < active.count; i++) ((void (*)(void *))fn_8019639C)(active.entry[i]);
    for (i = 0; i < inactive.count; i++) fn_80196328(inactive.entry[i]);
    for (i = 0; i < active.count; i++) fn_801963A0(active.entry[i]);
    for (i = 0; i < active.count; i++) fn_80196414(active.entry[i]);
    for (i = 0; i < active.count; i++) fn_80196418(active.entry[i]);
    for (i = 0; i < active.count; i++) fn_801967A4(active.entry[i]);
    for (i = 0; i < active.count; i++) fn_801967FC(active.entry[i]);
    iter = (Controller **)lbl_804349E0;
    controllers = (Controllers *)iter;
    for (i = 0; i < controllers->count; i++) {
        (*iter)->update();
        iter++;
    }
}
#pragma cplusplus reset
#pragma pop

  void fn_80196A9C(void) {
      fn_8019684C();
  }

extern float lbl_80562160, lbl_805621A4, lbl_80562258, lbl_8056225C;
extern float lbl_80562250[2];
extern void fn_8017B3A8(void *, float *, void *, float);
extern void fn_8018ADD4(void *, int);
extern void fn_8018ADC4(int, float);
void fn_80196AA0(void *arg0) {
    float *limits = lbl_80562250;
    volatile float slots[2];
    int state = 0;
    float difference;
    float vecA[3];
    float vecB[3];

    difference = *(float *)((char *)arg0 + 0x26C) - *(float *)((char *)arg0 + 0x218);
    if (!(difference < limits[0])) {
        state = 1;
        if (!(difference < limits[1])) state = 2;
    }
    {
        void *flags = *(void **)((char *)arg0 + 0x298);
        if (*(unsigned char *)((char *)flags + 0x17C) != 0 &&
            *(unsigned char *)((char *)flags + 0x108) == 0) state = -1;
    }
    if (state == 0) goto case0;
    if (state >= 0) goto nonnegative;
    if (state < -1) goto transition;
    goto done;
nonnegative:
    if (state < 2) goto case1;
    goto transition;
case0: {
        void *object = *(void **)((char *)arg0 + 0x294);
        void *outputBase;
        void *inputBase;
        float factor = lbl_80562258;
        vecA[0] = *(float *)((char *)object + 0x88) * factor;
        vecA[1] = *(float *)((char *)object + 0x8C) * factor;
        vecA[2] = *(float *)((char *)object + 0x90) * factor;
        outputBase = (void *)*(void * volatile *)((char *)arg0 + 0x294);
        inputBase = (void *)*(void * volatile *)((char *)arg0 + 0x294);
        fn_8017B3A8(inputBase, vecA, (char *)outputBase + 0x94, factor);
    }
case1: {
        float high = lbl_80562144;
        float low = lbl_80562140;
        float value = low;
        float result = -((low * *(float *)((char *)arg0 + 0x40)) +
                         (-high * *(float *)((char *)arg0 + 0x44)));
        slots[0] = high;
        slots[1] = low;
        value = value < result ? result : value;
        value = value > lbl_805621A4 ? lbl_805621A4 : value;
        fn_8018ADAC(*(void **)((char *)arg0 + 0x294), value);
        fn_8018ADD4(*(void **)((char *)arg0 + 0x294), -1);
        fn_8018ADBC(*(int *)((char *)arg0 + 0x294), lbl_80562144);
        fn_8018ADC4(*(int *)((char *)arg0 + 0x294), lbl_80562140);
        if ((float)__fabs(*(float *)((char *)arg0 + 0x270)) < lbl_80562160)
            fn_8018ADB4(*(int *)((char *)arg0 + 0x294), lbl_80562140);
        if (*(float *)((char *)arg0 + 0x270) < lbl_80562160) {
            fn_8018ADC4(*(int *)((char *)arg0 + 0x294), lbl_80562144);
            {
                void *object = *(void **)((char *)arg0 + 0x294);
                float factor = lbl_8056225C;
                vecB[0] = *(float *)((char *)object + 0x88) * factor;
                vecB[1] = *(float *)((char *)object + 0x8C) * factor;
                vecB[2] = *(float *)((char *)object + 0x90) * factor;
                fn_8017B3A8(object, vecB, (char *)object + 0x94, factor);
            }
        }
        goto done;
    }
transition:
    *(int *)((char *)arg0 + 0x210) = *(int *)((char *)arg0 + 0x214);
    *(int *)((char *)arg0 + 0x214) = 2;
done:
    ;
}

/* MSL float.h classification results (__fpclassifyf/__fpclassifyd).  The header
   itself is not included: it defines __fpclassifyf inline, and the game calls the
   library function. */
enum MslFloatClass { FP_SNAN = 0, FP_QNAN = 1, FP_INFINITE = 2, FP_ZERO = 3, FP_NORMAL = 4, FP_SUBNORMAL = 5 };

#pragma push
#pragma use_lmw_stmw off
static inline int fn_80196C90_signbit(float x) { /* MSL float.h __signbitf() */
    return (int)(*(int *)&x & 0x80000000);
}

#pragma push
#pragma dont_inline off
/* One tick of the driver's shake value at +0x144, run before the rest of the
   driver update (fn_80196DC4) clears the two side-record flags:

     - decay it by the per-instance factor at +0x14C (drawn at random by
       fn_801981A0);
            - when a new best record was just set on either side this frame (+0x9C for
       the positive side, +0x74 for the negative one, both raised by fn_8019703C
       together with the record's signed Y at +0xCC) and that Y has the same sign
       as the shake value, damp the value further by lbl_80562260 (0.81f);
     - when the value has lost magnitude since last frame (+0x148 holds it) and
       the time the next random shake is due at +0x150 is not a usable number
       (NaN or infinite - fn_801981A0 parks -1.0f there and fires on it), re-arm
       it to now (+0x26C) plus a random offset in [lbl_8055E548, lbl_8055E54C);
     - keep the value at +0x148 for next frame's comparison. */
void fn_80196C90(void *arg0) {
    extern float lbl_80562260; /* 0.81f */
    extern int __fpclassifyf(float);
    char *obj = (char *)arg0;
    int recordUpdated = 0;
    double prevMagnitude;
    double curMagnitude;
    int timeIsUsable;
    int isNan;
    int isFinite;
    *(float *)(obj + 0x144) = *(float *)(obj + 0x144) * *(float *)(obj + 0x14C);
    if (*(unsigned char *)(obj + 0x9C) != 0 || *(unsigned char *)(obj + 0x74) != 0) {
        recordUpdated = 1;
    }
    if (recordUpdated != 0) {
        if (fn_80196C90_signbit(*(float *)(obj + 0xCC)) == fn_80196C90_signbit(*(float *)(obj + 0x144))) {
            *(float *)(obj + 0x144) = *(float *)(obj + 0x144) * lbl_80562260;
        }
    }
    prevMagnitude = __fabs(*(float *)(obj + 0x148));
    curMagnitude = __fabs(*(float *)(obj + 0x144));
    if ((float)curMagnitude < (float)prevMagnitude) {
        float nextShakeTime = *(float *)(obj + 0x150);
        timeIsUsable = 0;
        isNan = __fpclassifyf(nextShakeTime) == FP_QNAN; /* isnan() */
        if (!isNan) {
            isFinite = __fpclassifyf(nextShakeTime) > FP_INFINITE; /* isfinite() */
            if (isFinite) {
                timeIsUsable = 1;
            }
        }
        if (timeIsUsable == 0) {
            *(float *)(obj + 0x150) = *(float *)(obj + 0x26C) + fn_80129DC4(3, lbl_8055E548, lbl_8055E54C);
        }
    }
    *(float *)(obj + 0x148) = *(float *)(obj + 0x144);
}
#pragma pop
extern int fn_8019703C(void *, void *);
extern int fn_8019799C(void *, void *);
extern int fn_80197FE4(void *, void *);
extern int fn_80137788(void *, int, float *);
extern int fn_801377EC(void *, int, float *);
extern int lbl_802F9578[3];
#pragma scheduling invalid_target
void fn_80196DC4(void *arg0) {
    struct Cnt { int a, b, c; };
    struct Entry { u8 pad0[8]; u8 b8; u8 pad9[3]; int w0C; u8 b10; u8 pad11[3]; int w14; };
    struct Info { struct Entry *e; float f[4]; u8 b; int w; };
    struct Table { int count; int pad4[2]; int stride; char *base; };
    struct Local { struct Cnt cnt; struct Info info; } L;
    int c2, c1, c0, *src;
    char *obj = (char *)arg0;
    float negx, x, u, v, w;
    int s, n, i;
    float zero;
    fn_80196C90(arg0);
    x = *(float *)(obj + 0x274);
    *(u8 *)(obj + 0x74) = 0;
    negx = -x;
    u = lbl_805621A0;
    v = lbl_805621AC;
    w = lbl_80562144;
    *(u8 *)(obj + 0x9C) = 0;
    *(u8 *)(obj + 0xFC) = 0;
    *(int *)(obj + 0x100) = 0;
    *(int *)(obj + 0x98) = 0;
    *(float *)(obj + 0x94) = u;
    *(int *)(obj + 0xC0) = 0;
    *(float *)(obj + 0xBC) = v;
    *(u8 *)(obj + 0x9C) = 0;
    *(u8 *)(obj + 0x74) = 0;
    *(float *)(obj + 0xC4) = negx;
    *(float *)(obj + 0xD0) = negx;
    *(float *)(obj + 0xC8) = x;
    *(float *)(obj + 0xD4) = x;
    *(u8 *)(obj + 0x11C) = 0;
    *(float *)(obj + 0x120) = w;
    ((void (*)(int, int, float, float, float, float))fn_80136EA4)(lbl_8055E0D0, *(int *)(obj + 0x290), v, u, x, negx);
    src = (int *)lbl_802F9578;
    c0 = src[0]; c1 = src[1]; c2 = src[2];
    zero = lbl_80562144;
    L.cnt.a = c0;
    n = (*(struct Table **)&lbl_8055E0D0)->count - 1;
    L.cnt.b = c1;
    L.cnt.c = c2;
    for (i = 0; i < n; i++) {
        struct Table *t = *(struct Table **)&lbl_8055E0D0;
        struct Entry *e;
        s = *(int *)(obj + 0x290);
        e = *(struct Entry **)(((i + t->count * 2) * 4) + (t->base + s * t->stride) + 0x18);
        if (e == 0) break;
        if ((s == e->w0C ? e->b8 : e->b10) == 0) break;
        L.info.e = e;
        if (e != 0) {
            fn_80137788(e, s, &L.info.f[0]);
            fn_801377EC(e, s, &L.info.f[2]);
            L.info.b = (s == e->w0C) ? e->b8 : e->b10;
            L.info.w = (s == e->w0C) ? e->w14 : e->w0C;
        } else {
            L.info.f[0] = zero; L.info.f[1] = zero; L.info.f[2] = zero; L.info.f[3] = zero;
            L.info.b = 0; L.info.w = 0;
        }
        if (*(u8 *)L.info.e != 0) {
            if (L.cnt.a > 0 && fn_8019703C(arg0, &L.info) != 0) L.cnt.a--;
        } else {
            if (L.cnt.c > 0 && fn_80197FE4(arg0, &L.info) != 0) L.cnt.c--;
            if (L.cnt.b > 0 && fn_8019799C(arg0, &L.info) != 0) L.cnt.b--;
        }
    }
}
#pragma scheduling reset
/* Returns 1 when the racer registered at slotIndex is missing or inactive
 * (+0x2A4 clear) -- i.e. the slot has no live racer; 0 when one is active. */
int fn_8019700C(int slotIndex) {
    void *racer = lbl_804349C0[slotIndex];
    int isInactive = 1;
    if (!racer)
        goto done;
    if (*((u8 *)racer + 0x2A4) == 0)
        goto done;
    isInactive = 0;
done:
    return isInactive;
}

extern float lbl_80562144, lbl_80562170, lbl_80562194, lbl_8055A488;
#pragma scheduling on
/* Consider a sensed candidate for an AI driver's two best-target slots. A candidate
   is eligible when the driver state value (+0x270) exceeds xLimit, |candidateY| is
   within base*(1+coefficient), and driveFlags bit 0 is clear. Positive candidateY
   competes for the "ahead" slot at +0xA0 (lowest score wins); negative for the
   "behind" slot at +0x78 (highest score wins). The winner's 7-word record is copied
   in, its valid flag set, y/z/id saved at +0xCC..+0xDC, and a per-sign count bumped. */
int fn_8019703C(void *driver, void *candidate) {
    float xLimit;
    float stateValue;
    float candidateZ;
    float candidateY;
    float coefficient;
    float base;
    float absoluteY;
    float threshold;
    float score;
    unsigned int word6;
    unsigned int byte5;
    unsigned int word4, word3, word2, word1, word0;
    unsigned int candidateId;
    int recordUpdated;
    int stateValid;
    int candidateInRange;
    int driveFlags;

    stateValue = *(float *)((char *)driver + 0x270);
    recordUpdated = 0;
    xLimit = lbl_80562170;
    candidateZ = *(float *)((char *)candidate + 8);
    candidateY = *(float *)((char *)candidate + 4);
    stateValid = stateValue > xLimit;
    coefficient = lbl_80562194;
    base = lbl_8055A488;
    absoluteY = (float)__fabs((double)candidateY);
    threshold = base + coefficient * base;
    candidateInRange = absoluteY < threshold;
    driveFlags = *(unsigned int *)((char *)driver + 0x2D0);

    if ((driveFlags & 1) == 0 && stateValid != 0 && candidateInRange != 0) {
        if (candidateY > lbl_80562144) {
            score = *(float *)((char *)driver + 0x278) + candidateY;
            if (score < *(float *)((char *)driver + 0xBC)) {
                word0 = *(unsigned int *)((char *)candidate + 0);
                word1 = *(unsigned int *)((char *)candidate + 4);
                word2 = *(unsigned int *)((char *)candidate + 8);
                word3 = *(unsigned int *)((char *)candidate + 0xC);
                word4 = *(unsigned int *)((char *)candidate + 0x10);
                byte5 = *(unsigned char *)((char *)candidate + 0x14);
                word6 = *(unsigned int *)((char *)candidate + 0x18);
                *(float *)((char *)driver + 0xBC) = score;
                *(unsigned int *)((char *)driver + 0xA0) = word0;
                *(unsigned int *)((char *)driver + 0xA4) = word1;
                *(unsigned int *)((char *)driver + 0xA8) = word2;
                *(unsigned int *)((char *)driver + 0xAC) = word3;
                *(unsigned int *)((char *)driver + 0xB0) = word4;
                *(unsigned char *)((char *)driver + 0xB4) = byte5;
                *(unsigned int *)((char *)driver + 0xB8) = word6;
                *(unsigned char *)((char *)driver + 0x9C) = 1;
                recordUpdated = 1;
            }
        } else {
            score = *(float *)((char *)driver + 0x278) + candidateY;
            if (score > *(float *)((char *)driver + 0x94)) {
                word6 = *(unsigned int *)((char *)candidate + 0);
                byte5 = *(unsigned int *)((char *)candidate + 4);
                word4 = *(unsigned int *)((char *)candidate + 8);
                word3 = *(unsigned int *)((char *)candidate + 0xC);
                word2 = *(unsigned int *)((char *)candidate + 0x10);
                word1 = *(unsigned char *)((char *)candidate + 0x14);
                word0 = *(unsigned int *)((char *)candidate + 0x18);
                *(float *)((char *)driver + 0x94) = score;
                *(unsigned int *)((char *)driver + 0x78) = word6;
                *(unsigned int *)((char *)driver + 0x7C) = byte5;
                *(unsigned int *)((char *)driver + 0x80) = word4;
                *(unsigned int *)((char *)driver + 0x84) = word3;
                *(unsigned int *)((char *)driver + 0x88) = word2;
                *(unsigned char *)((char *)driver + 0x8C) = word1;
                *(unsigned int *)((char *)driver + 0x90) = word0;
                *(unsigned char *)((char *)driver + 0x74) = 1;
                recordUpdated = 1;
            }
        }
    }
    if (recordUpdated) {
        candidateId = *(unsigned int *)((char *)candidate + 0x18);
        *(float *)((char *)driver + 0xCC) = candidateY;
        *(float *)((char *)driver + 0xD8) = candidateZ;
        *(unsigned int *)((char *)driver + 0xDC) = candidateId;
    }
    if (candidateY > lbl_80562144)
        ++*(int *)((char *)driver + 0xC0);
    else
        ++*(int *)((char *)driver + 0x98);
    return 0;
}
/* Advance interpolation factor at +0x25C and lerp the 2D point in/out toward (base+0x48/0x4C + base+0x58/0x5C * speed) when enabled (0x260 != 0, 0x268 != 1). */
void fn_801971AC(void *arg0, void *arg1) {
    extern float lbl_80562264;
    float sp18[2];
    double sp10;
    float sp8[2];
    float factor;
    float speed;
    float old0;
    float old1;
    float res1;
    float res0;
    float *point;
    char *base;
    point = (float *)arg1;
    base = (char *)arg0;
    if (*(int *)(base + 0x260) == 0) return;
    if (*(int *)(base + 0x268) == 1) return;
    speed = *(float *)(base + 0x264);
    factor = *(float *)(base + 0x25C) + lbl_80562264;
    *(float *)(base + 0x25C) = factor;
    sp18[0] = *(float *)(base + 0x48) + (*(float *)(base + 0x58) * speed);
    old0 = point[0];
    sp18[1] = *(float *)(base + 0x4C) + (*(float *)(base + 0x5C) * speed);
    old1 = point[1];
    res1 = old1 + (factor * (sp18[1] - old1));
    res0 = old0 + (factor * (sp18[0] - old0));
    sp8[1] = res1;
    sp8[0] = res0;
    sp10 = *(double *)sp8;
    point[0] = *(float *)&sp10;
    point[1] = *((float *)&sp10 + 1);
}

extern int fn_801671AC(int);
extern int fn_8015FBCC(void *, float *, int, int, float, float);
extern float fn_801973FC(float *, float *, void *);
typedef struct { float x, y; } Vec2_801973FC;
extern float lbl_80562160, lbl_8056222C, lbl_80562268, lbl_8056226C;
#pragma processor 750
void fn_8019724C(void *arg0, float *arg1) {
    float projected[2];
    float direction[2];
    float norm;
    float length;
    float scale;
    float current;
    float upper;
    float lower;
    float diff;
    float weight;
    float factor;
    float flagThreshold;
    int index;
    void *obj;

    if (*(float *)((char *)arg0 + 0x270) > lbl_80562160) {
        index = fn_801671AC(*(int *)((char *)arg0 + 0x290));
        obj = *(void **)((char *)arg0 + 0x294);
        direction[0] = *(float *)((char *)obj + 0x70);
        direction[1] = *(float *)((char *)obj + 0x78);
        norm = (float)fn_8002F234(direction[0] * direction[0] + direction[1] * direction[1]);
        length = lbl_80562148;
        if (length > norm) {
            length = lbl_80562148;
        } else {
            length = norm;
        }
        scale = lbl_80562140 / length;
        direction[0] = direction[0] * scale;
        direction[1] = direction[1] * scale;
        if (((int (*)(void *, float *, int, int))fn_8015FBCC)(*(void **)((char *)arg0 + 0x294), projected, 0, index)) {
            current = *(float *)((char *)arg0 + 0x26C);
            upper = lbl_8056226C + *(float *)((char *)arg0 + 0x1F8);
            lower = current - lbl_80562268;
            current = current < upper ? current : upper;
            current = current > lower ? current : lower;
            *(float *)((char *)arg0 + 0x1F8) = current;
            *(float *)((char *)arg0 + 0x20C) = fn_801973FC(direction, projected, arg1);
            flagThreshold = *(volatile float *)&lbl_8056222C;
            arg1[0] = projected[0];
            arg1[1] = projected[1];
            if (flagThreshold < *(float *)((char *)arg0 + 0x270)) {
                *(volatile int *)((char *)arg0 + 0x2D0) |= 0x40;
                *(volatile int *)((char *)arg0 + 0x2D0) |= 0x800;
            }
        } else {
            diff = *(float *)((char *)arg0 + 0x26C) - *(float *)((char *)arg0 + 0x1F8);
            if (diff < lbl_80562268) {
                weight = lbl_80562140 - diff / lbl_80562268;
                factor = *(float *)((char *)arg0 + 0x20C) * weight;
                arg1[0] = arg1[0] + direction[0] * factor;
                arg1[1] = arg1[1] + direction[1] * factor;
            }
        }
    }
}

static inline void sub_801973FC(Vec2_801973FC *out, float *a, float *b) {
    out->x = a[0] - b[0];
    out->y = a[1] - b[1];
}
static inline float dot_801973FC(float *a, Vec2_801973FC *b) {
    return a[0] * b->x + a[1] * b->y;
}
float fn_801973FC(float *arg0, float *arg1, void *arg2) {
    Vec2_801973FC diff;
    sub_801973FC(&diff, arg1, (float *)arg2);
    return dot_801973FC(arg0, &diff);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern float lbl_80562270,lbl_80562274,lbl_80562278;
extern void fn_80198488(void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8019743C(void *p, void *arg1) {
    float *out = (float *)arg1;
    float diff=lbl_80562144, scale, limit, f, t, v;
    int decay=1, active=0, fw, sw, md;
    unsigned char *side;
    if(((u8 *)p)[0x9c] || ((u8 *)p)[0x74]) active=1;
    if(active) {
        fn_80198488(p);
        if(((u8 *)p)[0x74]) {
            { float a=*(float *)((u8 *)p+0x84); float m=lbl_8056215C*a; float pos=*(float *)((u8 *)p+0x7c)+m; float margin=lbl_805621DC+lbl_8055A488; float pp=*(float *)((u8 *)p+0x278)+pos; limit=margin+pp; }
            f=*(float *)((u8 *)p+0xc4);
            f = f>limit ? f : limit;
            *(float *)((u8 *)p+0xc4)=f;
        }
        if(((u8 *)p)[0x9c]) {
            { float a=*(float *)((u8 *)p+0xac); float m=lbl_8056215C*a; float pos=*(float *)((u8 *)p+0xa4)+m; float margin=lbl_805621DC+lbl_8055A488; float pp=*(float *)((u8 *)p+0x278)+pos; limit=pp-margin; }
            f=*(float *)((u8 *)p+0xc8);
            f = f<limit ? f : limit;
            *(float *)((u8 *)p+0xc8)=f;
        }
        t=*(float *)((u8 *)p+0xe8);
        if(t>lbl_80562144) {
            limit=*(float *)((u8 *)p+0x278)+t; f=*(float *)((u8 *)p+0xc4);
            f = f>limit ? f : limit;
            *(float *)((u8 *)p+0xc4)=f;
        } else if(t<lbl_80562144) {
            limit=*(float *)((u8 *)p+0x278)+t; f=*(float *)((u8 *)p+0xc8);
            f = f<limit ? f : limit;
            *(float *)((u8 *)p+0xc8)=f;
        }
        fw=0; side=0;
        scale=lbl_80562174;
        if(*(float *)((u8 *)p+0xc8)<*(float *)((u8 *)p+0xc4)) {
            if(((u8 *)p)[0x74] && ((u8 *)p)[0x9c]) {
                fw=*(int *)((u8 *)p+0x90);
                sw=(unsigned char)fn_80193110(p,*(int *)((u8 *)p+0xb8));
                sw|=((unsigned char)fn_80193110(p,fw))<<1;
                if(sw && sw!=3) {
                    sw=(sw>>1)&1;
                    if(sw) side=(u8 *)p+0xa0; else side=(u8 *)p+0x78;
                    fw=*(int *)(side+0x18);
                    md=((int (*)(void *, int))fn_801930DC)(p,fw);
                    fw=((int (*)(void *, int, int))fn_8019309C)(p,fw,md)==0;
                } else {
                    if((sw&2) && ((int (*)(void *, int))fn_801930DC)(p,*(int *)((u8 *)p+0x90))) { sw=1; md=1; }
                    else if((sw&1) && ((int (*)(void *, int))fn_801930DC)(p,*(int *)((u8 *)p+0xb8))) {sw=0; md=1;}
                    else {sw=1;md=0;}
                    if(sw) side=(u8 *)p+0xa0; else side=(u8 *)p+0x78;
                    fw=((int (*)(void *, int, int))fn_8019309C)(p,*(int *)(side+0x18),md)==0;
                }
            } else {
                sw=!((u8 *)p)[0x74];
                if(((u8 *)p)[0x74]) side=(u8 *)p+0x78; else side=(u8 *)p+0xa0;
                fw=((int (*)(void *, int, int))fn_8019309C)(p,*(int *)(side+0x18),1)==0;
            }
            if(sw) *(float *)((u8 *)p+0xc8)=*(float *)((u8 *)p+0xc4);
            else *(float *)((u8 *)p+0xc4)=*(float *)((u8 *)p+0xc8);
        } else {
            if(((u8 *)p)[0x74] && (unsigned char)fn_80193110(p,*(int *)((u8 *)p+0x90))) scale*=lbl_80562174;
            if(((u8 *)p)[0x9c] && fn_80193110(p,*(int *)((u8 *)p+0xb8))) scale*=lbl_80562174;
        }
        if(fw) { t=*(float *)(side+8); if(((u8 *)p)[0x2fd] || t<lbl_805621DC) *(int *)((u8 *)p+0x2d0)|=0x40; }
        t=*(float *)((u8 *)p+0x278)+lbl_8056215C**(float *)((u8 *)p+0x27c);
        f=*(float *)((u8 *)p+0xc4);
        if(t<f) diff=f-t;
        else { f=*(float *)((u8 *)p+0xc8); if(t>f) diff=f-t; }
        if((float)__fabs(diff)>lbl_80562148) {
            if(fn_8019700C(*(int *)((u8 *)p+0xdc))) {
                *(int *)((u8 *)p+0x2d0)|=0x40;
                out[2]-=lbl_80562170;
            }
            *(float *)((u8 *)p+0xe4)=*(float *)((u8 *)p+0x278)+diff;
            *(float *)((u8 *)p+0xe8)=lbl_80562144;
            t=(float)__fabs(diff)/lbl_805621DC;
            f=lbl_80562140; f=f<t?f:t;
            f=f>lbl_80562144?f:lbl_80562144;
            v=*(float *)((u8 *)p+0xe0);
            if(v<f) {t=lbl_80562140-lbl_80562148*scale; *(float *)((u8 *)p+0xe0)=f+t*t*(v-f);}
            else *(float *)((u8 *)p+0xe0)=f+lbl_80562270*(v-f);
            decay=0;
        } else *(float *)((u8 *)p+0xe8)=lbl_80562144;
    } else *(float *)((u8 *)p+0xe8)=lbl_80562144;
    if(*(float *)((u8 *)p+0xe0)>lbl_80562274) {
        float ef = *(float *)((u8 *)p+0xe4);
        float xx = *(float *)((u8 *)p+0x48)+*(float *)((u8 *)p+0x58)*ef;
        ((u8 *)p)[0x250]=1;
        {
            float yy = *(float *)((u8 *)p+0x4c)+*(float *)((u8 *)p+0x5c)*ef;
            float ee = *(float *)((u8 *)p+0xe0);
            float o0 = out[0];
            float o1 = out[1];
            float n0 = o0 + ee*(xx-o0);
            float n1 = o1 + ee*(yy-o1);
            float buf[2];
            double dd;
            volatile float va0, va1, vb0, vb1;
            va0 = xx; va1 = yy; vb0 = xx; vb1 = yy;
            buf[0]=n0; buf[1]=n1;
            dd=*(double *)buf;
            out[0]=((float *)&dd)[0];
            out[1]=((float *)&dd)[1];
        }
    }
    if(decay) *(float *)((u8 *)p+0xe0)*=lbl_80562278;
}
#pragma pop

#pragma processor reset
int fn_8019799C(void *self, void *candidate) {
    // Check whether a candidate is within angular/distance bounds of self; if so,
    // report it via fn_80197AB8 and return 1. Returns 0 when rejected/filtered out.
    int id;
    int result = 0;
    int valid;
    int allow;
    double absolute;
    float angle;
    float distance;
    float bound;
    float limit;
    extern float lbl_80562160, lbl_80562170, lbl_80562184;
    extern float fn_80137850(void *);
    extern double __fabs(double);
    extern void fn_80197AB8(void *, int, float, float, float);

    if (*(int *)((char *)self + 0x2D0) & 2) return 0;
    allow = 1;
    angle = -*(float *)((char *)candidate + 0x10);
    id = *(int *)((char *)candidate + 0x18);
    if (!(angle > lbl_80562160)) {
        valid = 0;
        if (id == *(int *)((char *)self + 0x114) && angle > lbl_80562170)
            valid = 1;
        if (!valid) allow = 0;
    }
    if (allow && id != *(int *)((char *)self + 0x2C4)) {
        angle = fn_80137850(candidate);
        absolute = __fabs((double)angle);
        bound = *(float *)((char *)self + 0x278) + *(float *)((char *)candidate + 4);
        distance = (float)absolute;
        limit = lbl_80562184 + *(float *)((char *)self + 0x274);
        distance = distance < bound ? distance : bound;
        if (distance < limit) {
            fn_80197AB8(self, id, *(float *)((char *)(*(void **)candidate) + 4), angle,
                *(float *)((char *)candidate + 0x10));
            result = 1;
        }
    }
    return result;
}

typedef struct Obj Obj;
extern void *fn_8017960C(int);
extern Obj *fn_801B2ED0(int);
extern float lbl_80562194;
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80197AB8(void *arg0, int arg1, float farg0, float farg1, float farg2) {
    class VObj {
    public:
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void *call();
    };
    unsigned char *p = (unsigned char *)arg0;
    float vals[2];
    float rate;
    float field38;
    float field3C;
    float motion;
    float term1;
    float term2;
    float height;
    float sum;
    float output;
    int update;
    void *obj;
    void *result;
    *(int *)(p + 0x100) += 1;
    update = 1;
    if (p[0xFC] != 0)
        update = *(float *)(p + 0xEC) > farg0;
    if (update) {
        *(float *)(p + 0xEC) = farg0;
        obj = fn_8017960C(arg1);
        vals[0] = *(float *)((char *)obj + 0x88);
        vals[1] = *(float *)((char *)obj + 0x90);
        obj = fn_801B2ED0(arg1);
        result = ((VObj *)obj)->call();
        if (result) {
            p[0xFC] = 1;
            rate = *(float *)(p + 0x27C);
            motion = rate * farg0;
            field3C = *(float *)((char *)result + 0x3C);
            field38 = *(float *)((char *)result + 0x38);
            term1 = field3C * vals[1];
            term2 = field38 * vals[0];
            height = *(float *)(p + 0x278) + motion;
            sum = term2 + term1;
            *(float *)(p + 0xF8) = farg1;
            *(int *)(p + 0x114) = arg1;
            output = lbl_80562194 * sum;
            *(float *)(p + 0x108) = height;
            *(float *)(p + 0x110) = farg2;
            *(float *)(p + 0x104) = output;
        }
    }
}
#pragma cplusplus reset
#pragma scheduling on
extern float lbl_8055A48C, lbl_80562194, lbl_8056227C, lbl_80562280, lbl_80562140, lbl_80562144, lbl_805621A4, lbl_8056215C, lbl_80562284, lbl_80562288, lbl_80562268, lbl_80562274, lbl_8056228C;
extern void fn_8019315C(void *, int);
extern int fn_8019309C(void *, int, signed char);
void fn_80197BD0(void *arg0, void *arg1) {
 float f31=lbl_8055A488,f30,f5,f6,f4,f3,f2,f1; int done=1, i, special; void *p;
 f30=lbl_80562194*lbl_8055A48C;
 if (*(u8*)((char*)arg0+0xfc)) {
  if (*(float*)((char*)arg0+0xec)<lbl_8056227C || *(int*)((char*)arg0+0x100)>1) {
   fn_8019315C(arg0,*(int*)((char*)arg0+0x114)); i=*(int*)((char*)arg0+0x114); p=lbl_804349C0[i];
   f5=f31+__fabsf(*(float*)((char*)arg0+0x104))*(f30-f31);
   special=p && *(int*)((char*)arg0+0x290)==*(int*)((char*)p+0x114);
   f4=*(float*)((char*)arg0+0xf8); f6=f4-*(float*)((char*)arg0+0x108);
   if ((*(unsigned int*)&f4 & 0x80000000U) != (*(unsigned int*)&f6 & 0x80000000U)&&!special) f6=f4>lbl_80562144?lbl_80562140:lbl_805621A4;
   if (*(int*)((char*)arg0+0x114)!=*(int*)((char*)arg0+0x118)||*(float*)((char*)arg0+0xec)>lbl_80562194) {
    *(float*)((char*)arg0+0x10c)=f6; f3=__fabsf(f6); f30=lbl_80562284+lbl_8056215C*(f5+f31);
    if (f3<f30) {
     if ((*(u8*)((char*)arg0+0x9c)||*(u8*)((char*)arg0+0x74))&&(*(unsigned int*)&f6 & 0x80000000U) != (*(unsigned int*)((char*)arg0+0xcc) & 0x80000000U)) fn_8019309C(arg0,*(int*)((char*)arg0+0xdc),0);
     f1=*(float*)((char*)arg0+0x10c)>lbl_80562144?lbl_80562140:lbl_805621A4;
     f2=( *(float*)((char*)arg0+0x54)-lbl_80562144)/(*(float*)((char*)arg0+0xec)-lbl_80562144); if(f2>lbl_80562140) f2=lbl_80562140; if(f2<lbl_80562144) f2=lbl_80562144;
     f3=*(float*)((char*)arg0+0x278); f4=(*(float*)((char*)arg0+0xec)-lbl_8056227C)/lbl_80562288;
     *(float*)((char*)arg0+0xf4)=f3+f2*(*(float*)((char*)arg0+0xf8)-f30*f1-f3);
     if(f4>lbl_80562140) f4=lbl_80562140; if(f4<lbl_80562144) f4=lbl_80562144;
     f2=f4*lbl_80562140; f3=*(float*)((char*)arg0+0xf0); f1=lbl_80562144+f2-f3; *(float*)((char*)arg0+0xf0)=f3+lbl_8056215C*f1;
     if(!fn_80193184(arg0,*(int*)((char*)arg0+0x114))) { f4=*(float*)((char*)arg1+8); f3=*(float*)((char*)arg0+0x270)+*(float*)((char*)arg0+0x110); *(float*)((char*)arg1+8)=f4+*(float*)((char*)arg0+0xf0)*(f3+lbl_80562268/(*(int*)((char*)arg0+0x100))*(f4-f3)-f4); }
     done=0;
    }
   }
  }
 } else { *(int*)((char*)arg0+0x114)=-1; *(int*)((char*)arg0+0x118)=-1; }
 f4=*(float*)((char*)arg0+0xf0);
 if(f4>lbl_80562274) { f5=*(float*)((char*)arg0+0xf4); *(u8*)((char*)arg0+0x250)=1; f3=*(float*)((char*)arg0+0x48)+*(float*)((char*)arg0+0x58)*f5; f2=*(float*)((char*)arg0+0x4c)+*(float*)((char*)arg0+0x5c)*f5; f1=*(float*)arg1; f6=*(float*)((char*)arg1+4); *(float*)arg1=f1+f4*(f3-f1); *(float*)((char*)arg1+4)=f6+f4*(f2-f6); }
 if(done) *(float*)((char*)arg0+0xf0)*=lbl_8056228C;
}

extern float lbl_80562184, lbl_80562290, lbl_80562294;
extern float lbl_8055A48C;
extern void fn_8019813C(void *, void *, float, float);
#pragma scheduling invalid_target
int fn_80197FE4(void *arg0, void *arg1)
{
  int special;
  int mode;
  int between;
  int x_ok;
  int in_range;
  int allowed;
  void *entry;
  int result = 0;
  int angle_ok;
  float z_limit;
  float upper;
  float speed;
  float projected_x;
  float projected_z;
  float lower;
  extern float lbl_8055A48C;
  extern float lbl_8055A488;
  extern float lbl_80562184;
  extern float lbl_8056215C;
  extern float lbl_80562140;
  extern float lbl_80562290;
  extern float lbl_80562294;
  extern void *lbl_804349C0[];
  if (!((*((int *) (((char *) arg0) + 0x2D0))) & 4))
  {
    special = 1;
    z_limit = lbl_80562290 * lbl_8055A488;
    upper = lbl_8055A48C + (lbl_80562184 * lbl_8055A48C);
    mode = *((int *) (((char *) arg0) + 0x268));
    if ((mode != 0) && (mode != 3))
    {
      special = 0;
    }
    if (special)
    {
      speed = lbl_8056215C;
    }
    else
    {
      speed = lbl_80562140;
    }
    *((float *) (((char *) arg0) + 0x134)) = speed;
    projected_x = speed * (*((float *) (((char *) arg1) + 0x10)));
    projected_x += *((float *) (((char *) arg1) + 8));
    projected_z = speed * (*((float *) (((char *) arg1) + 0x0C)));
    projected_z = projected_z + (*((float *) (((char *) arg1) + 4)));
    x_ok = (*((float *) (((char *) arg1) + 8))) > (lbl_8056215C * lbl_8055A48C);
    in_range = 0;
    between = 0;
    if (projected_x < upper)
    {
      lower = lbl_80562294 * lbl_8055A48C;
      if (projected_x > lower)
      {
        between = 1;
      }
    }
    if (between && x_ok)
    {
      in_range = 1;
    }
    angle_ok = ((float) __fabs((double) projected_z)) < z_limit;
    entry = lbl_804349C0[*((int *) (((char *) arg1) + 0x18))];
    allowed = 1;
    if (entry && (*(((unsigned char *) entry) + 0x2A5)))
    {
      allowed = 0;
    }
    if ((allowed && in_range) && angle_ok)
    {
      fn_8019813C(arg0, arg1, *((float *) (((char *) arg1) + 8)), projected_x);
      result = 1;
    }
  }
  return result;
}
#pragma scheduling on
void fn_8019813C(void *arg0, void *arg1, float arg2, float arg3) {
    int should_update = 1;
    float event_time;
    float value;
    float adjustment;
    float weight;
    int index;

    if (*((u8 *)arg0 + 0x11C) != 0 && arg2 > *((float *)((char *)arg0 + 0x124))) {
        should_update = 0;
    }
    if (should_update == 0) {
        return;
    }
    event_time = *((float *)((char *)arg1 + 0x10));
    weight = *((volatile float *)((char *)arg1 + 4));
    value = *((float *)((char *)arg0 + 0x270)) + event_time;
    adjustment = *((volatile float *)&lbl_805621E4);
    index = *((int *)((char *)arg1 + 0x18));

    *((u8 *)arg0 + 0x11C) = 1;
    *((float *)((char *)arg0 + 0x128)) = arg3;
    *((float *)((char *)arg0 + 0x124)) = arg2;
    *((float *)((char *)arg0 + 0x12C)) = weight;
    *((float *)((char *)arg0 + 0x130)) = value - adjustment;
    *((int *)((char *)arg0 + 0x138)) = index;
}

extern float lbl_80562298, lbl_8056229C, lbl_805622A0, lbl_805622A4, lbl_8056227C, lbl_8056221C;
void fn_801981A0(void *arg0, void *arg1) {
#define o ((char *)arg0)
#define p ((char *)arg1)
    float c, temp_f3, var_f4, var_f5, temp_f6, temp_f7, temp_f2, temp_f0, temp_f0_2, temp_f0_3, temp_f1, temp_f4;
    float var_f0, var_f1, var_f5_2, temp_f3b, temp_f3c;
    int temp_r5, var_r0, var_r4;

    temp_r5 = *(int *)(o + 0x140);
    if (temp_r5 > 0) {
        *(int *)(o + 0x140) = temp_r5 - 1;
    }
    if (*(u8 *)(o + 0x11C) != 0) {
        if (*(int *)(o + 0x138) != *(int *)(o + 0x13C)) {
            *(float *)(o + 0x14C) = fn_80129DC4(3, lbl_8055E55C, lbl_8055E560);
            *(int *)(o + 0x13C) = *(int *)(o + 0x138);
        }
        var_r4 = 1;
        c = lbl_8055A48C;
        temp_f6 = c + (lbl_80562298 * *(float *)(o + 0x2EC) * c);
        if (*(u8 *)(o + 0xFC) != 0 && *(int *)(o + 0x114) == *(int *)(o + 0x138)) {
            var_r4 = 0;
        }
        if (*(int *)(o + 0x138) != *(int *)(o + 0x2C4) && var_r4 != 0 &&
            (float)__fabs(*(float *)(o + 0x12C)) < lbl_8055E570 * lbl_8055A488) {
            var_f4 = lbl_80562140;
            temp_f7 = *(float *)(p + 8);
            temp_f3 = *(float *)(o + 0x130);
            temp_f0 = (*(float *)(o + 0x128) - c) / (temp_f6 - c);
            var_f4 = (var_f4 < temp_f0) ? var_f4 : temp_f0;
            var_f4 = (var_f4 > lbl_80562144) ? var_f4 : lbl_80562144;
            var_f5 = lbl_80562140;
            temp_f3c = temp_f3 + var_f4 * (temp_f7 - temp_f3);
            *(float *)(p + 8) = temp_f3c;
            *(float *)(o + 0x120) = temp_f3c;
            temp_f2 = *(float *)(o + 0x134);
            temp_f3b = *(float *)(p + 0xC);
            temp_f0_2 = (*(float *)(o + 0x128) - c) / (temp_f6 - c);
            var_f5 = (var_f5 < temp_f0_2) ? var_f5 : temp_f0_2;
            var_f5 = (var_f5 > lbl_80562144) ? var_f5 : lbl_80562144;
            *(float *)(p + 0xC) = temp_f2 + var_f5 * (temp_f3b - temp_f2);
            if (*(u8 *)(o + 0x9C) != 0) {
                *(int *)(o + 0x140) = 0x1E;
            }
            if (*(int *)(o + 0x140) == 0 && *(int *)(o + 0x268) != 3) {
                var_f5_2 = lbl_8056217C - lbl_80562140;
                temp_f0_3 = (var_f5_2 * ((temp_f7 - *(float *)(o + 0x130)) - lbl_8056229C)) / lbl_805622A0;
                temp_f4 = lbl_8056227C * lbl_8055A488 * lbl_8055E564;
                var_f5_2 = (var_f5_2 < temp_f0_3) ? var_f5_2 : temp_f0_3;
                var_f5_2 = (var_f5_2 > lbl_80562144) ? var_f5_2 : lbl_80562144;
                temp_f1 = *(float *)(o + 0x150);
                var_r0 = 0;
                if (temp_f1 < lbl_80562144 || *(float *)(o + 0x26C) > temp_f1) {
                    var_r0 = 1;
                }
                if (var_r0 != 0) {
                    *(float *)(o + 0x150) = lbl_805621A4;
                    var_f1 = (*(int *)(o + 0x18) == 1) ? lbl_805621A4 : lbl_80562140;
                    var_f0 = ((*(float *)(o + 0x12C) - (lbl_8056221C * (lbl_80562174 * var_f1))) > lbl_80562144) ? lbl_80562140 : lbl_805621A4;
                    var_f1 = *(float *)(o + 0x144) + (lbl_805622A4 * (lbl_80562140 + var_f5_2) * -var_f0);
                    var_f1 = (temp_f4 < var_f1) ? temp_f4 : var_f1;
                    temp_f0_3 = -temp_f4;
                    var_f1 = (var_f1 > temp_f0_3) ? var_f1 : temp_f0_3;
                    *(float *)(o + 0x144) = var_f1;
                }
            }
        }
    }
    *(u8 *)(o + 0x154) = 0;
#undef o
#undef p
}

#pragma scheduling on
/* If the combined slot counts exceed the limit in +0x2F4, pick a fallback index
   from the primary (+0x74/+0x90) or secondary (+0x9C/+0xB8) side and apply it. */
void fn_80198488(void *arg0) {
    int isPrimaryZero;
    int selectedIndex;
    int secondaryIndex;
    unsigned char primaryCount, secondaryCount;
    volatile unsigned char *primarySlotCount = (volatile unsigned char *)arg0 + 0x74;
    volatile unsigned char *secondarySlotCount = (volatile unsigned char *)arg0 + 0x9C;
    secondaryCount = *secondarySlotCount;
    primaryCount = *primarySlotCount;
    if ((int)(primaryCount + secondaryCount + 1) > (int)*(float *)((char *)arg0 + 0x2F4)) {
        isPrimaryZero = *(int *)((char *)arg0 + 0x18) == 0;
        if ((isPrimaryZero != 0) && ((int)primaryCount != 0)) {
            if ((int)*primarySlotCount != 0) selectedIndex = *(int *)((char *)arg0 + 0x90);
            else selectedIndex = -1;
            ((void (*)(void *, int))fn_80193138)(arg0, selectedIndex);
            return;
        }
        if ((isPrimaryZero == 0) && ((int)secondaryCount != 0)) {
            if ((int)*secondarySlotCount != 0) secondaryIndex = *(int *)((char *)arg0 + 0xB8);
            else secondaryIndex = -1;
            ((void (*)(void *, int))fn_80193138)(arg0, secondaryIndex);
        }
    }
}

void fn_80198530(void *arg0) {
    char *o = (char *)arg0;
    float sp10 = lbl_80562140;
    float spC = lbl_80562144;
    float v28 = *(float *)(o + 0x28);
    float v24 = *(float *)(o + 0x24);
    float r = sp10;
    if (v28 < spC) {
        if (v24 < lbl_805621A4) r = v24; else r = lbl_805621A4;
    } else {
        if (v24 > v28) { if (v24 < lbl_805621A4) r = v24; }
    }
    (void)sp10; (void)spC; (void)r;
    fn_801961FC(arg0);
}

#pragma dont_inline reset
void *fn_80198DD0(void *arg0, int arg1) {
    struct Table {
        void *items[8];
        int count;
    } *table;
    void **scan;
    unsigned char i;
    int loopCount;
    int count;
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80333390;
        table = (struct Table *)lbl_804349E0;
        scan = table->items;
        i = 0;
        loopCount = table->count;
        for (; loopCount > 0; loopCount--) {
            if (*scan == arg0) {
                count = table->count - 1;
                table->count = count;
                table->items[i] = table->items[count];
            } else {
                scan++;
                i++;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
/* If the racer registered at slotIndex is active, apply a random directional impulse to it. */
void fn_80198E7C(int slotIndex) {
    void *racer = lbl_804349C0[slotIndex];
    if (*((u8 *)racer + 0x2A4) != 0)
        fn_801964D0(racer);
}
#pragma dont_inline reset

  void fn_80198E7C(int index);
    void fn_80198EA0(int index) {
        fn_80198E7C(index);
    }

  
    typedef unsigned char u8;
    extern void *lbl_804349C0[];
    extern void *lbl_804349E0[];
      void fn_801964D0(void *);
      void fn_80128668(void *);
    void fn_80193138(void *, int);
      void fn_801964D0(void *);
      void fn_80128668(void *);
    void fn_80193138(void *, int);
  extern float fn_801671FC(int);
  extern int fn_801B89F8(void);
  extern int lbl_8055E0D0;
  extern void fn_8018ADBC(int, float);
  extern void fn_8018ADB4(int, float);
  extern void fn_8018AE24(int, int);
  extern void fn_80136EA4(int, int);
  extern void fn_80136E8C(int, int, int);
/* Stub: always reports 0 (no value / unsupported) for its interface. */
int fn_80198EA4(void) { return 0; }
extern void fn_801958D8();
extern void fn_80195F6C(void *, void *);
extern void fn_80194624(void *);
extern void fn_80195654(void *, void *);
extern void fn_801933FC(void *, void *);
extern double fn_8002F234(float);
extern float lbl_8055E3C8, lbl_80562144, lbl_80562140, lbl_80562148, lbl_80562204;
#pragma cplusplus on
struct Dummy_8019684C {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17();
};
#pragma cplusplus reset
