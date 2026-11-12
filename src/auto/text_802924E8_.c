extern int lbl_802FA998[];
extern char lbl_80349208[];
extern int strcmp(const char *, const char *);
extern int fn_802E317C(const char *, ...);
extern unsigned char lbl_80349294[];
extern unsigned char lbl_8034925C[];
extern void fn_80294530(void *, int, int, int);
extern char lbl_8055C988;
extern float lbl_805644D4;
extern int fn_80293374(void *, void *);
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
extern void fn_80293CD0(void*, int, int, int);
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
void fn_802924E8(void) {
    fn_80292EA8(lbl_804B4168);
}

extern double fn_8002F234(float);
extern float fn_80129DC4(int, float, float);
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
        float x = fn_80129DC4(0, lbl_805644D0, lbl_805644D4);
        float y = (float)fn_8002F234((one - x * x) - offset);
        float z = (float)fn_8002F234((one - x * x) - offset);
        float w = fn_80129DC4(0, -z, y);
        float q = (float)fn_8002F234((one - x * x) - w * w);
        float factor = (fn_80129DC4(0, lbl_805644D0, lbl_805644D4) > offset) ? lbl_805644D4 : lbl_805644D0;
        v.x = x;
        *(float *)(p + 0) = (float)(double)x;
        *(float *)(p + 4) = (float)(double)w;
        v.y = w;
        v.z = q * factor;
        *(float *)(p + 8) = v.z;
        *(float *)(p + 0xC) = fn_80129DC4(0, lbl_805644DC, lbl_805644E0);
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
        register float x = fn_80129DC4(0, lbl_805644D0, lbl_805644D4);
        float y = (float)fn_8002F234((one - x * x) - offset);
        float z = (float)fn_8002F234((one - x * x) - offset);
        float w = fn_80129DC4(0, -z, y);
        float q = (float)fn_8002F234((one - x * x) - w * w);
        float factor = (fn_80129DC4(0, lbl_805644D0, lbl_805644D4) > offset) ? lbl_805644D4 : lbl_805644D0;
        v.x = x;
        *(float *)(p + 0) = (float)(double)x;
        v.y = w;
        v.z = q * factor;
        *(float *)(p + 4) = (float)(double)w;
        *(float *)(p + 8) = v.z;
        *(float *)(p + 0xC) = fn_80129DC4(0, lbl_805644DC, lbl_805644E0);
    }
}
void fn_80292618(void) {
}

void fn_8029261C(void) {
    fn_80292EB4(lbl_804B4168);
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80292628(void) {
    class Dummy_80292628 {
    public:
        virtual void m0();
        virtual void m1();
    };
    register unsigned char *entry;
    register s32 i;
    entry = lbl_804B4168;
    i = 0;
    for (; i < *(s32 *)(lbl_804B4168 + 0x180); entry += 0x18, i++) {
        Dummy_80292628 *obj = *(Dummy_80292628 **)(entry + 0x10);
        obj->m1();
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
    register float one;
    register float threshold;
    register float angle;
    register float zero;

    angle = fn_801E7E18();
    one = lbl_805644D4;
    p = lbl_804B4030;
    threshold = lbl_805644E4;
    zero = lbl_805644D8;
    i = 0;
    for (; i < 6; ++i, p += 0x34) {
        float axis[3];
        float magnitude;
        float x, y, z, s, c, t, tx, ty, xx, yy, zz;
        float scale = angle * *(float *)(p + 0xC);
        axis[0] = *(float *)(p + 0x0) * scale;
        axis[1] = *(float *)(p + 0x4) * scale;
        axis[2] = *(float *)(p + 0x8) * scale;
        magnitude = PSVECMag(axis);
        if (magnitude > threshold) {
            float inverse = one / magnitude;
            x = inverse * axis[0];
            y = inverse * axis[1];
            z = inverse * axis[2];
            s = (float)sin(magnitude);
            c = (float)cos(magnitude);
            xx = x * x;
            t = one - c;
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
            *(float *)(p + 0x10) = one;
            *(float *)(p + 0x14) = zero;
            *(float *)(p + 0x18) = zero;
            *(float *)(p + 0x1C) = zero;
            *(float *)(p + 0x20) = one;
            *(float *)(p + 0x24) = zero;
            *(float *)(p + 0x28) = zero;
            *(float *)(p + 0x2C) = zero;
            *(float *)(p + 0x30) = one;
        }
    }
    {
        register unsigned char *entry = lbl_804B4168;
        register int j = 0;
        for (; j < *(s32 *)(lbl_804B4168 + 0x180); entry += 0x18, ++j) {
            Dummy_80292698 *obj = *(Dummy_80292698 **)(entry + 0x10);
            obj->v2();
        }
    }
}

extern "C" void fn_80292864(void) {
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
 * "<model_base>8.mod" -- are loaded by fn_80293374 (car), fn_80293CD0 (ter) and
 * fn_80294530 (wood); the chunk records start just after, at +0x2C, and their
 * count is the s32 at the end of the object (+0x2FAC car, +0x4C2C ter,
 * +0x222C wood). */
typedef struct ChunkSys {
    void *vtable;     /* +0x00 the effect's vtable (lbl_80349294/78/5C) */
    float gravity_f;  /* +0x04 gravity scale, the "grav_f" effect argument */
    s32 models[8];    /* +0x08 handle of model i, -1 when the game has none */
    s32 modelCount;   /* +0x28 how many of the eight models were found */
} ChunkSys;

extern char lbl_80349170[];
extern void *fn_801284F8(int, const void *);
extern void *fn_80293034(void *, void *, int);
extern void *fn_80293A00(void *, void *, int, int, int);
extern void *fn_80294254(void *, void *, int, int, int);
#pragma push
#pragma scheduling invalid_target
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
        fn_802E317C(str + 0x30);
        return 0;
    }
    return (int)ptr;
}
#pragma pop
extern int fn_802928D4(int, int, int, int, int, int);
void fn_802929D8(int arg0, int arg1, int arg2, int arg3) {
    fn_802928D4(0, arg0, arg1, arg2, arg3, arg1);
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
        fn_802E317C(strings + 0x50, name);
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
extern "C" void fn_80292B48(void *arg0) {
    if (fn_80292FB4(lbl_804B4168, arg0) != 0 && arg0 != 0) {
        ((Dummy_80292B48 *)arg0)->f0(1);
    }
}
#pragma cplusplus off
extern float PSVECDotProduct(void *, void *);
extern float lbl_805644D8, lbl_805644E8;
extern double fabs(double);
extern double __fabs(double);
#pragma processor 750
int fn_80292BA8(float *arg0, float *arg1, float *arg2, float *arg3) {
    float delta[3];
    register float y = arg2[1];
    register float x = arg2[0];
    register float t0 = arg0[0] - x;
    register float z = arg2[2];
    register float t1;
    register float t2;
    register float firstDot, secondDot;
    register float s1, nx, ay, az, abs2, k;
    register float s2;
    register float a0, a1, a2;
    delta[0] = t0;
    t1 = arg0[1] - y;
    delta[1] = t1;
    t2 = arg0[2] - z;
    delta[2] = t2;
    firstDot = PSVECDotProduct(delta, arg3);
    if (firstDot < lbl_805644D8) {
        secondDot = PSVECDotProduct(arg1, arg3);
        nx = arg3[0];
        s1 = -firstDot;
        ay = arg3[1];
        az = arg3[2];
        abs2 = (float)__fabs((double)secondDot);
        k = lbl_805644E8;
        a0 = arg0[0];
        arg0[0] = a0 + nx * s1;
        a1 = arg0[1];
        arg0[1] = a1 + ay * s1;
        a2 = arg0[2];
        arg0[2] = a2 + az * s1;
        s2 = k * abs2 - secondDot;
        arg1[0] += nx * s2;
        arg1[1] += ay * s2;
        arg1[2] += az * s2;
        return 1;
    }
    return 0;
}
#pragma processor reset
extern void *fn_802C6B44(void);
extern void fn_802C6C20(void *);
extern int fn_802C7888(void *, int);
extern char *fn_802C9C24(int);
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
void fn_80292CD8(void *arg0, int arg1, unsigned char *arg2) {
    void *list;
    char temp[0x2C];
    char *src;
    char c;
    int count;
    register char *dst;
    register int count2;
    char *dst2;
    register int offset = arg1;
    register int cursor = (int)arg2;
    list = fn_802C6B44();
    memset(temp, 0, 0x2C);
    dst = temp + 0x14;
    count = 0x10;
    goto copy_second;
count_second:
    count -= 1;
    if (count > 0) goto copy_second;
    dst[-1] = 0;
    goto copied_second;
copy_second:
    c = *(char *)cursor++;
    *dst++ = c;
    if ((signed char)c != 0) goto count_second;
copied_second:
    *(int *)(temp + 0x10) = offset;
    offset = 0;
    cursor = 0;
    goto check_list;
copy_first:
    src = fn_802C9C24(*(int *)((char *)list + 4) + offset);
    dst2 = temp;
    count2 = 0x10;
    goto copy_entry;
count_entry:
    count2--;
    if (count2 > 0) goto copy_entry;
    dst2[-1] = 0;
    goto copied_entry;
copy_entry:
    c = *src++;
    *dst2++ = c;
    if ((signed char)c != 0) goto count_entry;
copied_entry:
    fn_802C7888(temp, 1);
    cursor++;
    offset += 0x10;
check_list:
    if (cursor < *(int *)list) goto copy_first;
    fn_802C6C20(list);
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
    fn_802E317C(lbl_80349208, typeName); /* "chunk: invalid type '%s'" */
    return 0;
}

typedef unsigned char u8;
typedef signed char s8;
extern int fn_8002B1D8(const char *, const char *, int);
extern int strcmp(const char *, const char *);
extern int fn_802E317C(const char *, ...);
extern int lbl_802FA998[];
extern char lbl_80349208[];
void fn_80292EA8(void *arg0) { *(s32 *)((u8 *)arg0 + 0x180) = 0; }

void fn_80292EB4(void *arg0) { *(s32 *)((u8 *)arg0 + 0x180) = 0; }

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling off
int fn_80292EC0(void *arg0, const char *arg1, s32 *arg2, s32 arg3) {
    char *p;
    int i;
    p = (char *)arg0;
    i = 0;
    while (i < *(int *)((char *)arg0 + 0x180)) {
        if (fn_8002B1D8(arg1, p, 15) == 0) {
            *arg2 = i;
            return 1;
        }
        p += 0x18;
        i++;
    }
    return 0;
}
#pragma pop
void fn_80292F40(void *arg0, void *arg1, const char *arg2) {
    volatile s32 *counter = (volatile s32 *)((u8 *)arg0 + 0x180);
    s32 count;
    s32 left;
    char *dst;
    unsigned char c;
    count = *counter;
    left = 0x10;
    dst = (char *)arg0 + count * 0x18;
    goto copy_byte;
check_limit:
    if (--left > 0) {
        goto copy_byte;
    }
    dst[-1] = 0;
    goto after_copy;
copy_byte:
    c = (unsigned char)*arg2++;
    *dst++ = (char)c;
    if ((signed char)c != 0) {
        goto check_limit;
    }
after_copy:
    count = *counter;
    *(void **)((char *)arg0 + count * 0x18 + 0x10) = arg1;
    count = *counter;
    *(s32 *)((char *)arg0 + count * 0x18 + 0x14) = 1;
    count = *counter;
    *counter = count + 1;
}

int fn_80292FB4(unsigned char *arg0, void *arg1) {
    register unsigned char *entry;
    register int i;
    int count;
    int value;
    entry = arg0;
    i = 0;
    count = *(int *)(arg0 + 0x180);
    for (; i < count; entry += 0x18, i++) {
        if (*(void **)(entry + 0x10) == arg1) {
            value = *(int *)(arg0 + i * 0x18 + 0x14) - 1;
            *(int *)(arg0 + i * 0x18 + 0x14) = value;
            return value == 0;
        }
    }
    fn_802E317C(lbl_80349224);
    return 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_80293034(void *arg0, void *arg1, int arg2) {
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
        virtual float value(const char *);
    };
    *(void **)arg0 = lbl_80349294;
    fn_80293374(arg0, (void *)arg2);
    fn_802935A0(arg0);
    *(float *)((char *)arg0 + 4) = lbl_805644D4;
    if (arg1) {
        *(float *)((char *)arg0 + 4) =
            ((EffectArg *)arg1)->value((const char *)&lbl_8055C988);
    }
    *(int *)((char *)arg0 + 0x2FAC) = 0;
    return arg0;
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
extern float fn_801E7E24(void*);
extern void fn_802936C4(void*);
extern float lbl_80558DC4;
extern int fn_802C9950(int);
extern int fn_802C9994(int);
extern int fn_802C744C(void*, void*);
extern int fn_80128668(void*);
extern void fn_80293530(void*);
extern int fn_80293374(void*, void*);
extern char lbl_80349250[];
extern void* fn_802935A0(void*);
extern float lbl_805644D4;
extern char lbl_80349224[];
extern int fn_802C6CF8(int);
extern u8 lbl_80349294[];
void* __dt__Q34nw4r2ef6EffectFv_802930BC(void* arg0, int arg1) {
    if (arg0) {
        *(void**)arg0 = lbl_80349294;
        fn_80293530(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8029311C(void* arg0) {
    *(s32*)((u8*)arg0 + 0x2fac) = 0;
}

#pragma push
#pragma small_data off
#pragma pop
__declspec(section ".data") extern float lbl_80558DC4;
void fn_80293128(void* arg0) {
    float value = fn_801E7E24(arg0);
    float abs = (float)__fabs((double)value);
    if (!(abs <= lbl_80558DC4)) fn_802936C4(arg0);
}

#pragma use_lmw_stmw off
void fn_80293178(void *arg0, int unused) {
    /* Draw each entry using per-entry state/color parameters, restoring prior state. */
    register unsigned char *entryPtr;
    int savedState9950;
    int savedState9994;
    register int index;

    savedState9950 = fn_802C9950(0);
    savedState9994 = fn_802C9994(0);
    entryPtr = (unsigned char *)arg0 + 0x2C;
    index = 0;
    for (; index < *(int *)((char *)arg0 + 0x2FAC); entryPtr += 0x4C, index++) {
        fn_802C9950(*(int *)((char *)arg0 + (*(unsigned char *)(entryPtr + 0x4A) << 3) + 0x2FB0));
        fn_802C9994(*(int *)((char *)arg0 + (*(unsigned char *)(entryPtr + 0x4A) << 3) + 0x2FB4));
        fn_802C744C(*(void **)((char *)arg0 + (*(unsigned char *)(entryPtr + 0x48) << 2) + 8), entryPtr);
    }
    fn_802C9994(savedState9994);
    fn_802C9950(savedState9950);
}

void fn_80293230(void *arg0, float *arg1, float *arg2, int arg3, int arg4) {
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
    if (*(s32 *)(object + 0x28) != 0) goto cont;
    return;
cont:
    record = object + count * 0x4C;
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
    firstWord = *(unsigned int *)(template + 0x1C);
    secondWord = *(unsigned int *)(template + 0x20);
    *(unsigned int *)(record + 0x38) = firstWord;
    *(unsigned int *)(record + 0x3C) = secondWord;
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
    *(short *)(record + 0x6C) = (short)arg3;
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

#pragma push
#pragma scheduling invalid_target
int fn_80293374(void *arg0, void *arg1) {
    char name[0x20];
    int count;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    goto check;
loop:
    ((void (*)(void *, int, const char *, ...))fn_801345D8)(
        name, 0x20, lbl_80349250, (int)arg1,
        *(s32 *)((u8 *)arg0 + 0x28) + 1);
    if (fn_8012C33C(name) == 0) goto padding;
    *(s32 *)((u8 *)arg0 + *(s32 *)((u8 *)arg0 + 0x28) * 4 + 8) =
        fn_802C6FC0(name, 0, 0);
    count = *(s32 *)((u8 *)arg0 + 0x28);
    count++;
    *(s32 *)((u8 *)arg0 + 0x28) = count;
check:
    if (*(s32 *)((u8 *)arg0 + 0x28) < 8) goto loop;
padding:
    {
        s32 *arr = (s32 *)arg0;
        count = *(s32 *)((u8 *)arg0 + 0x28);
        for (; count < 8; count++)
            arr[count + 2] = -1;
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_80293530(void* arg0) {
    u8 *cursor = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x28)) {
        fn_802C6CF8(*(s32*)(cursor + 8));
        *(s32*)(cursor + 8) = -1;
        cursor += 4;
        i++;
    }
}

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
    s32 blue;
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
    blue = ((comp & 0xFF) << 16) | 0xFF000000;
    *(unsigned int *)(out + 0x2FB0) = (unsigned int)(blue | green | red);
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

#pragma push
#pragma scheduling invalid_target
void fn_802936C4(void *arg0) {
    struct Rec {
        unsigned int copy[9];
        float x, y, z;
        float vx, vy, vz;
        float age;
        unsigned char b40;
        short idx;
        unsigned char p[2];
        int mode;
        /* 0x48 */ unsigned char flag;
        /* 0x49 */ unsigned char type;
        /* 0x4a */ unsigned char b4a;
    };
    struct Tpl {
        unsigned int pad[4];
        unsigned int copy[9];
    };
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
    float dt;
    float scale;
    float tmp_vx;
    float tmp_vy;
    float tmp_vz;
    float tmp_nx;
    float tmp_ny;
    float tmp_nz;
    float tmp_vx2;
    float tmp_vy2;
    float tmp_vz2;
    float outer;
    float two;
    float zeroF;
    float oneF;
    float gravF;
    float smallF;
    float dt2;
    struct Rec *cur;
    struct Rec *out;
    struct Tpl *src;
    int iter;
    int kept;
    int mode;
    unsigned char type;
    float ageDt;
    float tmp[13];
    short entry;
    int zeroI;
    int r0;
    dt = fn_801E7E24(arg0);
    scale = lbl_805644F8 * dt;
    fn_801E9DD4(lbl_8055C958, lbl_8055C964, scale, lbl_805644F8);
    scale = lbl_805644D4 - scale;
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
        tmp_vx = cur->vx * scale;
        tmp_vy = cur->vy * scale;
        tmp_vz = cur->vz * scale;
        tmp_vy = tmp_vy - (gravF * dt) * *(float *)((unsigned char *)arg0 + 4);
        tmp_nx = cur->x + tmp_vx * dt;
        tmp_ny = cur->y + tmp_vy * dt;
        tmp_nz = cur->z + tmp_vz * dt;
        mode = cur->mode;
        type = cur->type;
        tmp[0] = tmp_vx;
        tmp[1] = tmp_vy;
        tmp[2] = tmp_vz;
        tmp[3] = tmp_nx;
        tmp[4] = tmp_ny;
        tmp[5] = tmp_nz;
        tmp_vx2 = cur->vx * scale;
        tmp[6] = tmp_vx2;
        tmp_vy2 = cur->vy * scale;
        tmp_vy2 = tmp_vy2 - (gravF * dt) * *(float *)((unsigned char *)arg0 + 4);
        tmp[7] = tmp_vy2;
        tmp_vz2 = cur->vz * scale;
        tmp[8] = tmp_vz2;
        entry = cur->idx;
        if (mode == 2) {
            tmp[9] = tmp[0] * dt;
            tmp[10] = tmp[6] * dt;
            tmp[11] = tmp[8] * dt;
            tmp[3] = tmp[3] + tmp[9];
            tmp[4] = tmp[4] + tmp[10];
            tmp[5] = tmp[5] + tmp[11];
            tmp[10] = zeroF;
            tmp[11] = zeroF;
            zeroI = 0;
            if (fn_801E9E78(&entry, tmp + 3, tmp + 9, &zeroI, gravF * dt) != 0) {
                if (fn_80292BA8(tmp + 3, tmp + 6, tmp, tmp + 9) != 0) {
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
        if (r0 != 0)
            src = (struct Tpl *)(lbl_804B4030 + type * 0x34);
        else
            src = (struct Tpl *)cur;
        kept++;
        {
            unsigned int a, b;
            a = src->copy[0];
            b = src->copy[1];
            out->copy[0] = a;
            out->copy[1] = b;
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
        out->flag = cur->flag;
        out->type = type;
        out->b4a = cur->b4a;
        out++;
    }
next:
    iter++;
    cur++;
check_loop:
    if (iter < *(int *)((unsigned char *)arg0 + 0x2FAC)) goto body;
    *(int *)((unsigned char *)arg0 + 0x2FAC) = kept;
    fn_801E9DD8();
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_80293A00(void *arg0, void *arg1, int arg2, int arg3, int arg4) {
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
        virtual float value(const char *);
    };
    register float f1reg;
    *(void **)arg0 = lbl_80349278;
    fn_80293CD0(arg0, arg2, arg3, arg4);
    f1reg = lbl_8056450C;
    *(float *)((char *)arg0 + 4) = f1reg;
    if (arg1 != 0) {
        *(float *)((char *)arg0 + 4) =
            ((EffectArg *)arg1)->value((const char *)&lbl_8055C988);
    }
    *(int *)((char *)arg0 + 0x4C2C) = 0;
    return arg0;
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
extern unsigned char lbl_80349278[];
extern float lbl_8056450C;
extern void fn_80293CD0(void*, int, int, int);
extern void fn_80293EB0(void*);
void* __dt__Q34nw4r2ef6EffectFv_80293A88(void* arg0, int arg1) {
    if (arg0) {
        *(void**)arg0 = lbl_80349278;
        fn_80293EB0(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_80293AE8(void* arg0) { *(int*)((u8*)arg0 + 0x4c2c) = 0; }

extern void fn_80293F20(void*);
void fn_80293AF4(void* arg0) {
    float value = fn_801E7E24(arg0);
    float abs = (float)__fabs((double)value);
    if (!(abs <= lbl_80558DC4)) fn_80293F20(arg0);
}

void fn_80293B44(void *arg0) {
    u8 *record = (u8 *)arg0 + 0x2C;
    s32 i = 0;
    goto check;
body:
    fn_802C744C(*(void **)((u8 *)arg0 + (*(u8 *)(record + 0x48) * 4) + 8), record);
    record += 0x4C;
    i++;
check:
    if (i < *(s32 *)((u8 *)arg0 + 0x4C2C)) goto body;
}

#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_80293BB4(void *arg0, float *arg1, float *arg2, short arg3) {
    int count;
    int index;
    int offset;
    int flags, zero;
    u8 *record;
    u8 *template;
    u8 *object;
    float x, y, z, a, b;
    unsigned int secondWord, firstWord;
    object = (u8 *)arg0;
    count = *(s32 *)(object + 0x4C2C);
    if (count >= 0x100) return;
    record = object + count * 0x4C;
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
    flags = 2;
    secondWord = *(unsigned int *)(template + 0x14);
    zero = 0;
    *(unsigned int *)(record + 0x2C) = firstWord;
    *(unsigned int *)(record + 0x30) = secondWord;
    *(unsigned int *)(record + 0x34) = *(unsigned int *)(template + 0x18);
    firstWord = *(unsigned int *)(template + 0x1C);
    secondWord = *(unsigned int *)(template + 0x20);
    *(unsigned int *)(record + 0x38) = firstWord;
    *(unsigned int *)(record + 0x3C) = secondWord;
    *(unsigned int *)(record + 0x40) = *(unsigned int *)(template + 0x24);
    firstWord = *(unsigned int *)(template + 0x28);
    secondWord = *(unsigned int *)(template + 0x2C);
    *(unsigned int *)(record + 0x44) = firstWord;
    *(unsigned int *)(record + 0x48) = secondWord;
    *(unsigned int *)(record + 0x4C) = *(unsigned int *)(template + 0x30);
    *(float *)(record + 0x5C) = a;
    *(float *)(record + 0x60) = b;
    *(float *)(record + 0x64) = arg2[2];
    *(float *)(record + 0x68) = lbl_805644D8;
    *(short *)(record + 0x6C) = arg3;
    *(unsigned int *)(record + 0x70) = flags;
    *(u8 *)(record + 0x74) = fn_80129D18(zero, *(s32 *)(object + 0x28));
    *(u8 *)(record + 0x75) = (u8)arg1;
    count = *(s32 *)(object + 0x4C2C);
    *(s32 *)(object + 0x4C2C) = count + 1;
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
 * fn_80294530 do the same for the "car" and "wood" chunk systems.
 * modelBase and remapTexture are the profile's "model_base" and
 * "remap_texture" strings, handed over as ints by the file's prototype. */
void fn_80293CD0(void *object, int modelBase, int instance, int remapTexture) {
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
    u8 *cursor = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x28)) {
        fn_802C6CF8(*(s32*)(cursor + 8));
        *(s32*)(cursor + 8) = -1;
        cursor += 4;
        i++;
    }
}

#pragma cplusplus on
extern "C" void *fn_80294254(void *arg0, void *arg1, int arg2, int arg3, int arg4) {
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
        virtual float value(const char *);
    };
    register float initialValue;
    *(void **)arg0 = lbl_8034925C;
    fn_80294530(arg0, arg2, arg3, arg4);
    initialValue = lbl_805644D4;
    *(float *)((char *)arg0 + 4) = initialValue;
    if (arg1 != 0) {
        *(float *)((char *)arg0 + 4) =
            ((EffectArg *)arg1)->value((const char *)&lbl_8055C988);
    }
    *(int *)((char *)arg0 + 0x222C) = 0;
    return arg0;
}
#pragma cplusplus off

#pragma pop

extern unsigned char lbl_8034925C[];
extern void fn_80294710(void *);
void *__dt__Q34nw4r2ef6EffectFv_802942DC(void *arg0, int arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_8034925C;
        fn_80294710(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8029433C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x222C) = 0;
}

extern void fn_80294780(void*);
void fn_80294348(void* arg0) {
    float value = fn_801E7E24(arg0);
    float abs = (float)__fabs((double)value);
    if (!(abs <= lbl_80558DC4)) fn_80294780(arg0);
}

#pragma scheduling invalid_target
void fn_80294398(void *arg0) {
    u8 *record = (u8 *)arg0 + 0x2C;
    s32 i = 0;
    goto check;
body:
    fn_802C744C(*(void **)((u8 *)arg0 + (*(u8 *)(record + 0x40) * 4) + 8), record);
    record += 0x44;
    i++;
check:
    if (i < *(s32 *)((u8 *)arg0 + 0x222C)) goto body;
}
#pragma scheduling on
extern int fn_80287B5C(int, void *, float, float, float);
void fn_80294408(void *arg0, float *arg1, float *arg2) {
    int count;
    int index;
    int offset;
    register u8 *object;
    register float *first;
    register u8 *record;
    register float *second;
    u8 *template;
    float x, y, z, a, b, c;
    unsigned int secondWord, firstWord;
    object = (u8 *)arg0;
    first = arg1;
    second = arg2;
    count = *(s32 *)(object + 0x222C);
    if (count >= 0x80) goto done;
    if (*(s32 *)(object + 0x28) != 0) goto body;
    goto done;
body:
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
    firstWord = *(unsigned int *)(template + 0x10);
    secondWord = *(unsigned int *)(template + 0x14);
    *(unsigned int *)(record + 0x2C) = firstWord;
    *(unsigned int *)(record + 0x30) = secondWord;
    *(unsigned int *)(record + 0x34) = *(unsigned int *)(template + 0x18);
    firstWord = *(unsigned int *)(template + 0x1C);
    secondWord = *(unsigned int *)(template + 0x20);
    *(unsigned int *)(record + 0x38) = firstWord;
    *(unsigned int *)(record + 0x3C) = secondWord;
    *(unsigned int *)(record + 0x40) = *(unsigned int *)(template + 0x24);
    firstWord = *(unsigned int *)(template + 0x28);
    secondWord = *(unsigned int *)(template + 0x2C);
    *(unsigned int *)(record + 0x44) = firstWord;
    *(unsigned int *)(record + 0x48) = secondWord;
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
done:
    ;
}
#pragma scheduling on

/* Loads the chunk system's chunk models.  The profile gives a base name, and
 * its models are the MODL resources "<base>1.mod" .. "<base>8.mod": every one
 * the resource system has is instantiated for `instance` -- its textures
 * remapped first when the profile names a texture to remap -- and the handle
 * is stored in the object's model table.  The slots no model was found for are
 * left at -1.
 *
 * The chunk system object (the "wood chunk sys"; fn_80293374 and fn_80293CD0
 * do the same for the "car" and "ter" ones) keeps its models at +0x08, one
 * handle each, and the number it found at +0x28.  modelBase and remapTexture
 * are the strings the profile's "model_base" and "remap_texture" entries give,
 * handed over as ints by the file's prototype. */
void fn_80294530(void *chunkSys, int modelBase, int instance, int remapTexture) {
    char name[0x20];
    int count;
    *(s32 *)((u8 *)chunkSys + 0x28) = 0;
    goto check;
loop:
    ((void (*)(void *, int, const char *, ...))fn_801345D8)(name, 0x20, lbl_80349250, modelBase, *(s32 *)((u8 *)chunkSys + 0x28) + 1);
    if (fn_8012C33C(name) == 0)  /* no such resource: the list of models ends here */
        goto padding;
    if (remapTexture != 0 && *(s8 *)remapTexture != 0)
        fn_80292CD8(name, instance, (u8 *)remapTexture);
    *(s32 *)((u8 *)chunkSys + *(s32 *)((u8 *)chunkSys + 0x28) * 4 + 8) = fn_802C6FC0(name, instance, 0);
    count = *(s32 *)((u8 *)chunkSys + 0x28);
    count++;
    *(s32 *)((u8 *)chunkSys + 0x28) = count;
check:
    if (*(s32 *)((u8 *)chunkSys + 0x28) < 8)
        goto loop;
padding:
    {
        s32 *models = (s32 *)chunkSys;  /* models[2 + i] is model handle i */
        count = *(s32 *)((u8 *)chunkSys + 0x28);
        for (; count < 8; count++)
            models[count + 2] = -1;
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80294710(void* arg0) {
    u8 *cursor = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x28)) {
        fn_802C6CF8(*(s32*)(cursor + 8));
        *(s32*)(cursor + 8) = -1;
        cursor += 4;
        i++;
    }
}
#pragma pop
extern float lbl_80564510, lbl_805644D4, lbl_80564500, lbl_805644FC, lbl_805644D8;
extern unsigned char lbl_804B4030[];
#pragma scheduling invalid_target
void fn_80294780(void *arg0) {
    struct W3 { unsigned int a, b, c; };
    struct Particle {
        struct W3 copy[3];
        float x, y, z;
        float vx, vy, vz;
        float age;
        unsigned char flag;
        unsigned char type;
        unsigned char pad[2];
    };
    struct ParticleTemplate {
        unsigned int pad[4];
        struct W3 copy[3];
    };
    struct { float x, y, z; } v;
    register struct ParticleTemplate *src;
    register struct Particle *cur;
    register struct Particle *out;
    register int i;
    float dt = fn_801E7E24(arg0);
    float gravity = lbl_80564500;
    float maxAge = lbl_805644FC;
    float minAge = lbl_805644D8;
    float scale = lbl_805644D4 - lbl_80564510 * dt;
    cur = (struct Particle *)((unsigned char *)arg0 + 0x2C);
    out = cur;
    for (i = 0; i < *(int *)((unsigned char *)arg0 + 0x222C); ++i, ++cur) {
        if (cur->age < minAge) continue;
        if (cur->age >= maxAge) continue;
        v.x = cur->vx * scale;
        v.y = cur->vy * scale;
        v.z = cur->vz * scale;
        v.y -= (gravity * dt) * *(float *)((unsigned char *)arg0 + 4);
        out->x = cur->x + v.x * dt;
        out->y = cur->y + v.y * dt;
        out->z = cur->z + v.z * dt;
        src = (struct ParticleTemplate *)(lbl_804B4030 + cur->type * 0x34);
        out->copy[0] = src->copy[0];
        out->copy[1] = src->copy[1];
        out->copy[2] = src->copy[2];
        out->vx = v.x;
        out->vy = v.y;
        out->vz = v.z;
        out->age = cur->age + dt;
        out->flag = cur->flag;
        out->type = cur->type;
        ++out;
    }
    *(int *)((unsigned char *)arg0 + 0x222C) =
        ((int)out - ((int)arg0 + 0x2C)) / 0x44;
}

  #pragma scheduling on
