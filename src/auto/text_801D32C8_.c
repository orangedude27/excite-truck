#include "math.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma cplusplus on
class Fn801D3610Interface {
public:
    virtual void *getValue(int);
    virtual void unused1();
    virtual int isAvailable(int);
};

/* Config object that supplies the named values of a mut_phob physics object. */
class PhobConfigSource {
public:
    virtual void dummy08();
    virtual int hasKey(const char *);
    virtual void dummy10();
    virtual const char *getString(const char *);
    virtual void dummy18();
    virtual void dummy1C();
    virtual int getInt(const char *, int);
    virtual float getFloat(const char *);
    virtual float getFloatDef(const char *, float);
    virtual void dummy2C();
    virtual char getByte(const char *, int);
};

/* The "mut_phob" keys, one block of 12-byte strings. */
struct Table80338340 {
    char max_life[12];
    char friction[12];
    char surf_type[12];
    char ground_test[12];
    char effect_id[12];
    char error[20];
};

/* Physics object configuration read by readPhobConfig from a config object. */
struct PhobConfig {
    float max_life;
    float mass;
    float mx;
    float my;
    float mz;
    float spring;
    float friction;
    int surf_type;
    char ground_test;
    char pad[3];
    int effect_id;
    int mode;            /* collision shape: 0 sphere, 1 tube, 2 hinged, 3 cube */
    float primarySize;   /* 0x2C: "rad" shape size, or "len" for a cube */
    float secondarySize; /* 0x30: "len" of a tube, "hit" length of a hinged shape */
};
#pragma cplusplus reset

extern const char lbl_80338340[]; /* block of mut_phob config keys */
extern unsigned int lbl_8055AC30; /* "mass" */
extern unsigned int lbl_8055AC38; /* "mx" */
extern unsigned int lbl_8055AC3C; /* "my" */
extern unsigned int lbl_8055AC40; /* "mz" */
extern unsigned int lbl_8055AC44; /* "spring" */
extern unsigned int lbl_8055AC4C; /* "type" */
extern unsigned int lbl_8055AC54; /* "rad" */
extern unsigned int lbl_8055AC58; /* "len" */
extern unsigned int lbl_8055AC5C; /* "hit" */
extern float lbl_80562AA0;
extern float lbl_80562AA4;
extern float lbl_80562AA8;
extern int fn_801D04D0(const char *);
extern int fn_801D37C4(const char *);

#pragma cplusplus on
extern "C" void Abend_Panic(const char *, ...);
#pragma cplusplus reset

extern int fn_80128668(void *);
extern int fn_80179EE8(int);
extern char lbl_80338400[16];
extern float lbl_80562AAC;
extern float lbl_80562AB8;
extern float lbl_80562ABC;
extern void fn_8017A57C(void *);
extern void fn_8017A580(void *);
extern void fn_8017B164(void *);

/* No-op stub. */
void fn_801D32C8(void) {
}

/* Empty stub / no-op placeholder. */
void fn_801D32CC(void) {

}

extern void *lbl_8055E940;
/* AX DSP init callback: clear the DSP init flag so the next init pass starts fresh. */
void __AXDSPInitCallback_801D32D0(void) {
#define sAXDspInitFlag lbl_8055E940
    sAXDspInitFlag = 0;
#undef sAXDspInitFlag
}

/* Empty stub / no-op placeholder. */
void fn_801D32DC(void) {

}

int fn_801D36E8(void);
void fn_801D3FA4();
#pragma use_lmw_stmw off
int fn_801D32E0(int configName, int typeId, int position, int orientation, int spawnParams, int initData) {
    int object;

    object = fn_801D36E8();
    fn_801D3FA4(object, configName, typeId, position, orientation, spawnParams, initData);
    return object;
}
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma pool_strings off
/* Reads a mut_phob physics object's configuration (mass, size, spring,
   friction, surface, effect and collision shape) from a config object. */
extern "C" void readPhobConfig(void *outConfig, void *configSource) {
    PhobConfigSource *source = (PhobConfigSource *)configSource;
    struct PhobConfig *config = (struct PhobConfig *)outConfig;
    f32 mzValue;
    f32 weight;
    int shapeType;
    config->max_life = source->getFloat("max_life");
    config->mass = source->getFloat((const char *)&lbl_8055AC30);
    config->mx = source->getFloat((const char *)&lbl_8055AC38);
    config->my = source->getFloat((const char *)&lbl_8055AC3C);
    mzValue = source->getFloat((const char *)&lbl_8055AC40);
    weight = 9.81f;
    weight *= config->mass;
    config->mz = mzValue;
    config->spring = source->getFloatDef((const char *)&lbl_8055AC44, 1.5f * (weight / 0.03f));
    config->friction = source->getFloatDef("friction", 1.0f);
    if (source->hasKey("surf_type") != 0) {
        config->surf_type = fn_801D04D0(source->getString("surf_type"));
    } else {
        config->surf_type = 100;
    }
    config->ground_test = source->getByte("ground_test", 1);
    config->effect_id = source->getInt("effect_id", -1);
    shapeType = fn_801D37C4(source->getString((const char *)&lbl_8055AC4C));
    config->mode = shapeType;
    switch (shapeType) {
    case 0:
        config->primarySize = source->getFloat((const char *)&lbl_8055AC54);
        break;
    case 1:
        config->primarySize = source->getFloat((const char *)&lbl_8055AC54);
        config->secondarySize = source->getFloat((const char *)&lbl_8055AC58);
        break;
    case 2:
        config->primarySize = source->getFloat((const char *)&lbl_8055AC54);
        config->secondarySize = source->getFloat((const char *)&lbl_8055AC5C);
        break;
    case 3:
        config->primarySize = source->getFloat((const char *)&lbl_8055AC58);
        break;
    default:
        Abend_Panic("mut_phob: invalid type %d", shapeType);
        break;
    }
}
#pragma scheduling on
#pragma cplusplus reset

extern void *fn_80131810(int);
extern void fn_80131818(void *);
extern void readPhobConfig(void *, void *);
extern int lbl_80562AB0;
extern int lbl_80562AB4;
extern char lbl_803383BC[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801D3610(void *outConfig, int configName) {
    /* Look up a config by name in the known config stores and copy it into outConfig, logging if missing. */
    int storeIds[2];
    int *storeIdPtr;
    unsigned int storeIndex;
    Fn801D3610Interface *store;
    void *configValue;

    storeIds[0] = lbl_80562AB0;
    storeIdPtr = &storeIds[0];
    storeIds[1] = lbl_80562AB4;
    storeIndex = 0;
    do {
        store = (Fn801D3610Interface *)fn_80131810(*storeIdPtr);
        if (store != 0) {
            if (store->isAvailable(configName) != 0) {
                configValue = store->getValue(configName);
                readPhobConfig(outConfig, configValue);
                fn_80131818(store);
                return;
            }
            fn_80131818(store);
        }
        storeIndex++;
        storeIdPtr++;
    } while (storeIndex < 2U);
    Abend_Panic(lbl_803383BC, configName);
}
#pragma scheduling on
#pragma cplusplus reset
extern void fn_801D411C(void *);
extern void *lbl_804421D8[];
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma scheduling invalid_target
/* Select a phob object from the global pool: return the first slot whose vtable check reports free, otherwise reset and reuse the slot with the smallest timestamp at +0x224. */
extern "C" int fn_801D36E8(void) {
    struct PhobPoolObject {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual int isAvailable();
    };
    float bestTimestamp;
    void **entry;
    void *best;
    int index;

    bestTimestamp = 0.0f;
    entry = lbl_804421D8;
    best = 0;
    index = 0;
    goto check_loop;
loop:
    if (((struct PhobPoolObject *)*entry)->isAvailable() == 0)
        return (int)lbl_804421D8[index];
    if (best == 0 || *(float *)((char *)*entry + 0x224) < bestTimestamp) {
        best = *entry;
        bestTimestamp = *(float *)((char *)best + 0x224);
    }
    entry++;
    index++;
check_loop:
    if (index < *(int *)&lbl_8055E940)
        goto loop;
    fn_801D411C(best);
    return (int)best;
}
#pragma pop
/* Tests a mut_phob physics object's +0x1EC field: returns 1 unless it is
 * -1 (the "unset" sentinel), i.e. whether that field holds a valid value. */
unsigned int fn_801D37AC(void *phob) {
    int fieldValue;
    fieldValue = *(int *)((char *)phob + 0x1EC);
    return (unsigned int)((-1 - fieldValue) | (fieldValue + 1)) >> 31;
}

extern int lbl_802F99A8[];
extern char lbl_803383E4[];
extern int stricmp(const char *, const char *);
/* Look up a physics object ("phob") type id by name in lbl_802F99A8 (pairs of
 * name string and type id: sphere=1, tube=2, hinged=3, cube=4). Returns 0 and
 * logs lbl_803383E4 ("mut_phob: invalid type '%s'") if the name is unknown. */
int fn_801D37C4(const char *typeName) {
    int table[8];
    int *src = lbl_802F99A8;
    int *dst = table;
    int *entry = table;
    unsigned int i = 0;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst = *src;
    do {
        if (stricmp(typeName, (const char *)entry[0]) == 0) {
            return *(int *)((char *)table + 4 + (i << 3));
        }
        ++i;
        entry += 2;
    } while (i < 4);
    Abend_Panic(lbl_803383E4, typeName);
    return 0;
}

#pragma scheduling invalid_target
/* Destructor for a mut_phob physics object (vtable lbl_80338400): resets its
   child count (+0x28) and fields at +0x24/+0x2C, invokes the base destructor
   fn_80179EE8, and optionally frees the object. */
void *fn_801D3894(void *thisPtr, int shouldFree) {
    if (thisPtr != 0) {
        float zero = lbl_80562AB8;
        *(int *)((char *)thisPtr + 0x28) = 0;
        *(char **)thisPtr = (char *)lbl_80338400;
        *(int *)((char *)thisPtr + 0x24) = 0;
        *(float *)((char *)thisPtr + 0x2C) = zero;
        if (thisPtr != 0)
            ((void (*)(void *, int))fn_80179EE8)(thisPtr, 0);
        if (shouldFree > 0)
            fn_80128668(thisPtr);
    }
    return thisPtr;
}
#pragma scheduling on
extern void fn_8017B0F8(void);
extern void fn_8019EECC(void *, void *);
extern void fn_80179F94(void *, void *);
extern char lbl_80333B98[];
extern int lbl_80333B48[];
extern float lbl_80562AAC, lbl_80562AB8;
struct Obj3910 {
    void *vtable;
    void *unk4;
    int unk8;
    void *unkC;
    float unk10;
    float unk14;
    int unk18;
    int unk1C;
    int unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    char unk4C;
    char pad[3];
    float unk50;
};
#pragma scheduling invalid_target
void fn_801D3910(void *arg0) {
#pragma scheduling on
    char *p;
    int i;

    fn_8017B0F8();
    p = (char *)arg0 + 0x248;
    *(void **)((char *)arg0 + 0x244) = p;
    if (p != 0) {
        float value = lbl_80562AAC;
        float zero = lbl_80562AB8;
        volatile float temp[3];
        void *initialVtable = lbl_80333B98;

        *(volatile void **)p = initialVtable;
        temp[0] = zero;
        temp[1] = zero;
        temp[2] = zero;
        *(void **)(p + 0xC) = (char *)arg0 + 0x3C;
        *(void **)(p + 4) = arg0;
        *(int *)(p + 8) = 0;
        *(int *)(p + 0x18) = 0x53504852;
        *(float *)(p + 0x10) = value;
        *(float *)(p + 0x14) = value;
        *(int *)(p + 0x20) = 100;
        *(int *)(p + 0x1C) = 0;
        *(void **)p = lbl_80333B48;
        *(float *)(p + 0x24) = value;
        *(float *)(p + 0x34) = zero;
        *(float *)(p + 0x38) = zero;
        *(float *)(p + 0x3C) = zero;
        *(float *)(p + 0x40) = zero;
        *(float *)(p + 0x44) = zero;
        *(float *)(p + 0x48) = zero;
        *(char *)(p + 0x4C) = 0;
        *(float *)(p + 0x50) = zero;
        *(float *)(p + 0x28) = zero;
        *(float *)(p + 0x2C) = zero;
        *(float *)(p + 0x30) = zero;
        if (arg0 != 0)
            fn_8019EECC(arg0, p + 0x28);
    }
    fn_80179F94(arg0, *(void **)((char *)arg0 + 0x244));
    *(char *)((char *)arg0 + 0x1E8) = 1;
    lbl_804421D8[(i = *(int *)&lbl_8055E940)] = arg0;
    *(int *)&lbl_8055E940 = i + 1;
}

#pragma opt_propagation off
/* Reset a mut_phob physics object to its defaults: clear state fields, reinitialize its attached SPHR sphere shape, reset the local transform to identity with a -1000 z offset, copy it to the world matrix, and refresh per-frame/child state. */ void resetPhobObject(void *object) {
    struct Mtx48Copy { int w[12]; };
    register char *self = (char *)object;
    char *sphere = *(char **)(self + 0x244);
    register float one;
    register float zero;
    volatile float sp8, spC, sp10, sp14, sp18, sp1C;

    zero = 0.0f;
    *(int *)(self + 0x1EC) = -1;
    *(int *)(self + 0x1F0) = -1;
    *(volatile float *)(self + 0x224) = zero;
    *(int *)(self + 0x228) = 0;
    *(int *)(self + 0x22C) = 0;
    *(int *)(self + 0x23C) = 0;
    *(int *)(self + 0x24) = *(int *)(self + 0x28);
    if (sphere != 0) {
        *(void **)(sphere + 0xC) = self + 0x3C;
        one = 1.0f;
        *(void **)(sphere + 4) = object;
        *(int *)(sphere + 8) = 0;
        *(int *)(sphere + 0x18) = 0x53504852;
        *(volatile float *)(sphere + 0x10) = one;
        *(volatile float *)(sphere + 0x14) = one;
        *(int *)(sphere + 0x20) = 100;
        *(int *)(sphere + 0x1C) = 0;
        *(void **)sphere = lbl_80333B48;
        *(volatile float *)(sphere + 0x24) = one;
        *(volatile float *)(sphere + 0x34) = zero;
        *(volatile float *)(sphere + 0x38) = zero;
        *(volatile float *)(sphere + 0x3C) = zero;
        *(volatile float *)(sphere + 0x40) = zero;
        *(volatile float *)(sphere + 0x44) = zero;
        *(volatile float *)(sphere + 0x48) = zero;
        *(char *)(sphere + 0x4C) = 0;
        *(volatile float *)(sphere + 0x50) = zero;
        *(volatile float *)(sphere + 0x28) = zero;
        *(volatile float *)(sphere + 0x2C) = zero;
        sp10 = zero;
        spC = zero;
        sp8 = zero;
        *(volatile float *)(sphere + 0x30) = zero;
        if (object != 0)
            fn_8019EECC(object, sphere + 0x28);
    }
    {
        register float defaultZ;
        register float zero2;
        register float one2;
        zero2 = 0.0f;
        one2 = 1.0f;
        *(volatile float *)(self + 0x220) = zero2;
        defaultZ = lbl_80562ABC;
        *(volatile int *)(self + 0x24) = 0;
        *(volatile float *)(self + 0x1F4) = one2;
        *(volatile float *)(self + 0x1F8) = zero2;
        *(volatile float *)(self + 0x1FC) = zero2;
        *(volatile float *)(self + 0x200) = zero2;
        *(volatile float *)(self + 0x204) = one2;
        *(volatile float *)(self + 0x208) = zero2;
        *(volatile float *)(self + 0x20C) = zero2;
        *(volatile float *)(self + 0x210) = zero2;
        *(volatile float *)(self + 0x214) = one2;
        *(volatile float *)(self + 0x218) = zero2;
        *(volatile float *)(self + 0x21C) = defaultZ;
        *(volatile float *)(self + 0x220) = zero2;
        sp1C = zero2;
        sp18 = zero2;
        sp14 = zero2;
        *(volatile float *)(self + 0x30) = zero2;
        *(volatile float *)(self + 0x34) = zero2;
        *(volatile float *)(self + 0x38) = zero2;
    }
    fn_8017A57C(object);
    *(struct Mtx48Copy *)(self + 0x3C) = *(struct Mtx48Copy *)(self + 0x1F4);
    fn_8017A580(object);
    fn_8017B164(object);
}
#pragma opt_propagation reset
extern void fn_8017A57C(void *);
extern void fn_8017A580();
extern void fn_8017B164(void *);
extern void fn_8017B81C(void);
extern void fn_801D4598(void *, float);
extern float lbl_8055E3C8;
extern float lbl_80562AC0;
#pragma push
#pragma processor 750
#pragma cplusplus on
/*
 * Updates this object's damping/scale state based on its current mode.
 * Mode 2 applies the cached global value through fn_801D4598; otherwise, if the
 * cached value is below the threshold at +0x224/+0x234, the six scale values at
 * +0x118 are damped by lbl_80562AC0. If neither case applies, fn_801D411C
 * resets the object and clears the field at +0x1E4.
 */
extern "C" void fn_801D3BF0(void *arg0) {
    float currentValue;
    float dampingFactor;
    float firstScale;
    float *scaleValues;
    currentValue = lbl_8055E3C8;
    if (*(int *)((char *)arg0 + 0x230) == 2) {
        fn_8017B81C();
        fn_801D4598(arg0, currentValue);
        return;
    }
    if (currentValue < *(float *)((char *)arg0 + 0x224) + *(float *)((char *)arg0 + 0x234)) {
        fn_8017B81C();
        scaleValues = (float *)((char *)arg0 + 0x118);
        firstScale = scaleValues[0];
        dampingFactor = lbl_80562AC0;
        scaleValues[0] = firstScale * dampingFactor;
        scaleValues[1] *= dampingFactor;
        scaleValues[2] *= dampingFactor;
        scaleValues[3] *= dampingFactor;
        scaleValues[4] *= dampingFactor;
        scaleValues[5] *= dampingFactor;
        return;
    }
    fn_801D411C(arg0);
    *(int *)((char *)arg0 + 0x1E4) = 0;
}
#pragma cplusplus reset
#pragma pop
extern float lbl_8055E460;
extern char lbl_80558DC4[];
#pragma processor 750
#pragma scheduling on
void fn_801D3CB8(void *arg0, char *arg1) {
    struct E8 { float f[8]; };
    int off = *(int *)((char *)arg0 + 8);
    char *out = arg1 + off;
    unsigned int w8, w9a, w9b, w11;
    float g[2];
    float delta;
    g[0] = lbl_80562AAC;
    g[1] = lbl_8055E460;
    delta = g[1] - g[0];
    if ((float)fabs((double)delta) <= *(float *)lbl_80558DC4) {
        *(struct E8 *)out = *(struct E8 *)((char *)arg0 + 0x70);
        w8 = *(unsigned int *)((char *)arg0 + 0x90);
        *(unsigned int *)(out + 0x20) = w8;
        w9b = *(volatile unsigned int *)((char *)arg0 + 0x94);
        w9a = *(volatile unsigned int *)((char *)arg0 + 0x98);
        *(unsigned int *)(out + 0x24) = w9b;
        *(unsigned int *)(out + 0x28) = w9a;
        w11 = *(unsigned int *)((char *)arg0 + 0x9C);
        *(unsigned int *)(out + 0x2C) = w11;
    } else {
        float temp[12];
        float *a, *b, *p;
        int i;
        p = temp;
        b = (float *)((char *)arg0 + 0xA0);
        a = (float *)((char *)arg0 + 0x70);
        for (i = 0; i < 2; i++) {
            p[0] = b[0] + g[1] * (a[0] - b[0]);
            p[1] = b[1] + g[1] * (a[1] - b[1]);
            p[2] = b[2] + g[1] * (a[2] - b[2]);
            p[3] = b[3] + g[1] * (a[3] - b[3]);
            p[4] = b[4] + g[1] * (a[4] - b[4]);
            p[5] = b[5] + g[1] * (a[5] - b[5]);
            a += 6;
            b += 6;
            p += 6;
        }
        *(struct E8 *)out = *(struct E8 *)temp;
        w8 = *(unsigned int *)((char *)temp + 0x20);
        *(unsigned int *)(out + 0x20) = w8;
        w9a = *(volatile unsigned int *)((char *)temp + 0x24);
        w9b = *(volatile unsigned int *)((char *)temp + 0x28);
        *(unsigned int *)(out + 0x24) = w9a;
        *(unsigned int *)(out + 0x28) = w9b;
        w11 = *(volatile unsigned int *)((char *)temp + 0x2C);
        *(unsigned int *)(out + 0x2C) = w11;
    }
    *(short *)(out + 0x30) = *(short *)((char *)arg0 + 0x6C);
    *(int *)(out + 0x34) = *(int *)((char *)arg0 + 0x1EC);
    *(int *)(out + 0x38) = *(int *)((char *)arg0 + 0x1F0);
    *(int *)(out + 0x3C) = 0;
}
struct Vec3 {
    float x, y, z;
};
struct Mtx48 {
    int w[12];
};
extern void fn_801A4868(void *, int);
extern void fn_8017A57C(void *);
extern void fn_8017A580();
extern void fn_8017B2D0(void *, float, float, float, float);
extern void fn_801D4294(void *, void *);
extern void fn_8017D2C8();
extern void fn_801796CC();
#pragma processor 750
void fn_801D3E8C(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    float tmp[8];

    fn_8017D2C8(arg0, arg1, arg2);
    if (*(int *)((char *)arg0 + 0x238) > 0 && arg4 != 0) {
        float z_val;
        float y_val;
        float x_val;

        x_val = *(float *)arg2;
        y_val = *(float *)((char *)arg2 + 4);
        z_val = *(float *)((char *)arg2 + 8);
        tmp[0] = x_val;
        tmp[1] = y_val;
        tmp[2] = z_val;
        tmp[3] = *(float *)((char *)arg4 + 0x118);
        tmp[4] = *(float *)((char *)arg4 + 0x11C);
        tmp[5] = *(float *)((char *)arg4 + 0x120);
        *(short *)((char *)tmp + 0x18) = *(short *)((char *)arg4 + 0x6C);
        *(int *)((char *)tmp + 0x1C) = *(int *)((char *)arg0 + 0x238);
        fn_801796CC(10, tmp, (char *)&tmp[8] - (char *)tmp);
    }
    if (*(int *)((char *)arg0 + 0x230) == 2 && *(void **)((char *)arg0 + 0x22C) != arg4 && arg4 != 0) {
        int is_car = 0;
        unsigned int tag = *(unsigned int *)((char *)arg4 + 0x10);

        if (tag == 0x43415220 || tag == 0x50434152 || tag == 0x41434152 || tag == 0x4E434152) {
            is_car = 1;
        }
        if (is_car != 0) {
            *(void **)((char *)arg0 + 0x22C) = arg4;
            *(int *)((char *)arg0 + 0x24) = 0;
        }
    }
}
void fn_801D3FA4(void *arg0, int arg1, int arg2, void *arg3, void *arg4, void *arg5, int arg6) {
    float fa;
    float fb;
    float fc;
    float fd;
    float fe;
    int temp_r21;
    int temp_r22;
    int temp_r23;
    int temp_r24;
    int temp_r25;
    int temp_r26;
    int temp_r27;
    int temp_r12;
    int temp_r11;
    int temp_r7;
    int temp_r6;
    int temp_r4;
    int temp_r4_2;
    int temp_r5;
    int temp_r6_2;
    int r0;
    int zero;
    int t0;
    int t1;
    int t2;
    int t3;

    temp_r7 = 0;
    temp_r11 = ((int *)arg3)[0];
    temp_r27 = ((int *)arg3)[1];
    temp_r26 = ((int *)arg3)[2];
    temp_r25 = ((int *)arg3)[3];
    temp_r24 = ((int *)arg3)[4];
    temp_r23 = ((int *)arg3)[5];
    temp_r22 = ((int *)arg3)[6];
    temp_r21 = ((int *)arg3)[7];
    zero = ((int *)arg3)[8];
    r0 = ((int *)arg3)[9];
    temp_r12 = ((int *)arg3)[10];
    temp_r6 = ((int *)arg3)[11];

    *(int *)((char *)arg0 + 0x1EC) = arg1;
    temp_r4 = *(int *)((char *)arg5 + 0x28);
    *(int *)((char *)arg0 + 0x1F4) = temp_r11;
    fc = *(float *)((char *)arg5 + 0);
    *(int *)((char *)arg0 + 0x1F0) = arg2;
    t0 = *(int *)((char *)arg5 + 0x24);
    *(int *)((char *)arg0 + 0x1F8) = temp_r27;
    fb = *(float *)((char *)arg5 + 4);
    *(int *)((char *)arg0 + 0x1FC) = temp_r26;
    fa = *(float *)((char *)arg5 + 8);
    *(int *)((char *)arg0 + 0x200) = temp_r25;
    fd = *(float *)((char *)arg5 + 0xC);
    *(int *)((char *)arg0 + 0x204) = temp_r24;
    fe = *(float *)((char *)arg5 + 0x10);
    *(int *)((char *)arg0 + 0x208) = temp_r23;
    *(int *)((char *)arg0 + 0x20C) = temp_r22;
    *(int *)((char *)arg0 + 0x210) = temp_r21;
    *(int *)((char *)arg0 + 0x214) = zero;
    *(int *)((char *)arg0 + 0x218) = r0;
    *(int *)((char *)arg0 + 0x21C) = temp_r12;
    *(int *)((char *)arg0 + 0x220) = temp_r6;
    *(float *)((char *)arg0 + 0x224) = lbl_8055E3C8;
    *(int *)((char *)arg0 + 0x228) = arg6;
    *(int *)((char *)arg0 + 0x22C) = temp_r7;
    *(int *)((char *)arg0 + 0x230) = temp_r4;
    *(float *)((char *)arg0 + 0x234) = fc;
    *(int *)((char *)arg0 + 0x238) = t0;
    fn_8017B2D0(arg0, fb, fa, fd, fe);
    fn_801D4294(arg0, arg5);
    fa = *(float *)((char *)arg4 + 0);
    fb = *(float *)((char *)arg4 + 4);
    fc = *(float *)((char *)arg4 + 8);
    *(float *)((char *)arg0 + 0x30) = fa;
    *(float *)((char *)arg0 + 0x34) = fb;
    *(float *)((char *)arg0 + 0x38) = fc;
    fn_8017A57C(arg0);
    t0 = ((int *)arg3)[0];
    t1 = temp_r27;
    temp_r6_2 = ((int *)arg3)[8];
    temp_r5 = ((int *)arg3)[9];
    temp_r4_2 = ((int *)arg3)[10];
    t2 = temp_r26;
    t3 = temp_r25;
    zero = ((int *)arg3)[11];
    temp_r24 = temp_r24;
    t1 = t1;
    temp_r4 = temp_r4;
    *(int *)((char *)arg0 + 0x3C) = t0;
    *(int *)((char *)arg0 + 0x40) = t1;
    *(int *)((char *)arg0 + 0x44) = t2;
    *(int *)((char *)arg0 + 0x48) = t3;
    *(int *)((char *)arg0 + 0x4C) = temp_r24;
    *(int *)((char *)arg0 + 0x50) = temp_r23;
    *(int *)((char *)arg0 + 0x54) = temp_r22;
    *(int *)((char *)arg0 + 0x58) = temp_r21;
    *(int *)((char *)arg0 + 0x5C) = temp_r6_2;
    *(int *)((char *)arg0 + 0x60) = temp_r5;
    *(int *)((char *)arg0 + 0x64) = temp_r4_2;
    *(int *)((char *)arg0 + 0x68) = zero;
    fn_8017A580(arg0, temp_r4_2, temp_r5, temp_r6_2, temp_r21, temp_r22, temp_r23, temp_r24);
}

#pragma push
void fn_801D411C(void *actor) {
    /* Reset an actor's motion state: signal its associated object, clear the motion and
       scratch floats, build the default matrix at +0x1F4 and copy it to +0x3C, then reset
       the state/flags. */
    register char *base = (char *)actor;
    float sp8;
    float sp10;
    float spc;
    if (*(int *)(base + 0x230) == 2 && *(void **)(base + 0x228) != 0) {
        fn_801A4868(*(void **)(base + 0x228), 1);
    }
    {
        register float neg1000;
        register float one;
        register float zero;
        zero = lbl_80562AB8;
        one = lbl_80562AAC;
        *(volatile float *)(base + 0x220) = zero;
        neg1000 = lbl_80562ABC;
        *(volatile float *)(base + 0x118) = zero;
        *(volatile float *)(base + 0x11C) = zero;
        *(volatile float *)(base + 0x120) = zero;
        *(volatile float *)(base + 0x124) = zero;
        *(volatile float *)(base + 0x128) = zero;
        *(volatile float *)(base + 0x12C) = zero;
        *(volatile float *)(base + 0x130) = zero;
        *(volatile float *)(base + 0x134) = zero;
        *(volatile float *)(base + 0x138) = zero;
        *(volatile float *)(base + 0x13C) = zero;
        *(volatile float *)(base + 0x140) = zero;
        *(volatile float *)(base + 0x144) = zero;
        *(volatile float *)(base + 0x16C) = zero;
        *(volatile float *)(base + 0x170) = zero;
        *(volatile float *)(base + 0x174) = zero;
        *(volatile float *)(base + 0x178) = zero;
        *(volatile float *)(base + 0x17C) = zero;
        *(volatile float *)(base + 0x180) = zero;
        *(volatile float *)(base + 0x1F4) = one;
        *(volatile float *)(base + 0x1F8) = zero;
        *(volatile float *)(base + 0x1FC) = zero;
        *(volatile float *)(base + 0x200) = zero;
        *(volatile float *)(base + 0x204) = one;
        *(volatile float *)(base + 0x208) = zero;
        *(volatile float *)(base + 0x20C) = zero;
        *(volatile float *)(base + 0x210) = zero;
        *(volatile float *)(base + 0x214) = one;
        *(volatile float *)(base + 0x218) = zero;
        *(volatile float *)(base + 0x21C) = neg1000;
        *(volatile float *)(base + 0x220) = zero;
        *(volatile float *)&spc = zero;
        *(volatile float *)&sp10 = zero;
        *(volatile float *)&sp8 = zero;
        *(volatile float *)(base + 0x30) = zero;
        *(volatile float *)(base + 0x34) = zero;
        *(volatile float *)(base + 0x38) = zero;
        fn_8017A57C(actor);
        *(struct Mtx48 *)(base + 0x3C) = *(struct Mtx48 *)(base + 0x1F4);
        fn_8017A580(actor);
        *(int *)(base + 0x24) = 0;
        *(int *)(base + 0x1EC) = -1;
    }
}
#pragma pop

extern double fn_8002F234(float);
extern void fn_8019F564(void *, void *, float *, void *, float, float, float, float, float, float);
extern void Abend_Panic(const char *, ...);
extern float lbl_80562AAC, lbl_80562AB8, lbl_80562ABC, lbl_80562AC4;
extern char lbl_8033837C[];
extern int lbl_80333918[];
#pragma cplusplus on
extern "C" double fn_8002F234(float);
extern "C" void fn_8019EECC(void *, void *);
extern "C" void fn_8019F564(void *, void *, float *, void *, float, float, float, float, float, float);
extern "C" void Abend_Panic(const char *, ...);
extern "C" float lbl_80562AAC, lbl_80562AB8, lbl_80562AC4;
extern "C" char lbl_8033837C[];
extern "C" int lbl_80333918[];
#pragma processor 7400
extern "C" void fn_801D4294(void *arg0, void *arg1) {
    unsigned char *self = (unsigned char *)arg0;
    const unsigned char *src = (const unsigned char *)arg1;
    float size;
    register float zero = lbl_80562AB8;
    unsigned int mode = *(int *)(src + 0x28);
    volatile float sp10;
    volatile float spc;
    volatile float sp8;
    void *resource;

    sp8 = zero;
    spc = zero;
    sp10 = zero;
    switch (mode) {
    case 0: {
        size = *(float *)(src + 0x2C);
        unsigned char *p;
        register float posx;
        register float posy;
        register unsigned z = 0;
        *(unsigned int *)(self + 0x23C) = 0x53504852;
        *(float *)(self + 0x240) = size;
        resource = *(void **)(self + 0x244);
        if (!resource) break;
        p = (unsigned char *)resource;
        *(void **)(p + 0x0C) = self + 0x3C;
        posx = *(float *)(src + 0x14);
        *(unsigned int *)(p + 0x08) = z;
        *(void **)p = (void *)&lbl_80333B48;
        posy = *(float *)(src + 0x18);
        *(void **)(p + 0x04) = self;
        *(unsigned int *)(p + 0x20) = 0x64;
        *(unsigned int *)(p + 0x1C) = z;
        *(unsigned int *)(p + 0x18) = 0x53504852;
        *(float *)(p + 0x14) = posy;
        *(float *)(p + 0x10) = posx;
        *(volatile float *)(p + 0x28) = sp8;
        *(volatile float *)(p + 0x2C) = spc;
        *(volatile float *)(p + 0x30) = sp10;
        *(float *)(p + 0x24) = size;
        *(float *)(p + 0x34) = zero;
        *(float *)(p + 0x38) = zero;
        *(float *)(p + 0x3C) = zero;
        *(float *)(p + 0x40) = zero;
        *(float *)(p + 0x44) = zero;
        *(float *)(p + 0x48) = zero;
        *(unsigned char *)(p + 0x4C) = z;
        *(float *)(p + 0x50) = zero;
        *(volatile float *)(p + 0x28) = sp8;
        *(volatile float *)(p + 0x2C) = spc;
        *(volatile float *)(p + 0x30) = sp10;
        if (arg0) fn_8019EECC(arg0, p + 0x28);
        break;
    }
    case 1: {
        float x = lbl_80562AC4 * *(float *)(src + 0x30);
        float y = *(float *)(src + 0x2C);
        float xx = x * x;
        float yy = y * y;
        *(unsigned int *)(self + 0x23C) = 0x54554245;
        *(float *)(self + 0x240) = (float)fn_8002F234(yy + xx);
        resource = *(void **)(self + 0x244);
        if (resource) {
            unsigned char *p = (unsigned char *)resource;
            unsigned char *subObj;
            float posx, posy, f, h;
            subObj = self + 0x3C;
            *(void **)(p + 0x0C) = subObj;
            posy = *(float *)(src + 0x18);
            posx = *(float *)(src + 0x14);
            *(void **)(p + 0x04) = self;
            *(unsigned int *)(p + 0x08) = 0;
            *(unsigned int *)(p + 0x18) = 0x54554245;
            f = lbl_80562AC4 * *(float *)(src + 0x30);
            *(float *)(p + 0x10) = posx;
            h = *(float *)(src + 0x2C);
            *(float *)(p + 0x14) = posy;
            *(unsigned int *)(p + 0x20) = 0x64;
            *(unsigned int *)(p + 0x1C) = 0;
            *(float *)(p + 0x28) = f - h;
            *(float *)(p + 0x24) = h;
            *(void **)p = lbl_80333918;
        }
        break;
    }
    case 2: {
        float x = *(float *)(src + 0x30);
        register float y = *(float *)(src + 0x2C);
        register float xx = x * x;
        float yy = y * y;
        *(unsigned int *)(self + 0x23C) = 0x54554245;
        *(float *)(self + 0x240) = (float)fn_8002F234(yy + xx);
        resource = *(void **)(self + 0x244);
        if (resource != 0) {
            register unsigned char *p = (unsigned char *)resource;
            unsigned char *subObj;
            void *vtable;
            float posx, posy, h, f;
            *(void **)(p + 0x0C) = (self + 0x3C);
            vtable = lbl_80333918;
            posx = *(float *)(src + 0x14);
            *(unsigned int *)(p + 0x08) = 0;
            posy = *(float *)(src + 0x18);
            *(void **)(p + 0x04) = self;
            *(unsigned int *)(p + 0x18) = 0x54554245;
            h = *(float *)(src + 0x2C);
            *(unsigned int *)(p + 0x20) = 0x64;
            *(float *)(p + 0x10) = posx;
            *(float *)(p + 0x14) = posy;
            f = *(float *)(src + 0x30);
            *(unsigned int *)(p + 0x1C) = 0;
            *(float *)(p + 0x24) = h;
            *(float *)(p + 0x28) = f;
            *(void **)p = vtable;
        }
        break;
    }
    case 3: {
        float radius = lbl_80562AC4 * *(float *)(src + 0x2C);
        *(float *)(self + 0x240) = radius;
        *(unsigned int *)(self + 0x23C) = 0x53504852;
        resource = *(void **)(self + 0x244);
        if (resource) {
            fn_8019F564(resource, self + 0x3C, (float *)&sp8, self,
                        *(float *)(src + 0x14), *(float *)(src + 0x18),
                        lbl_80562AAC, radius, radius, radius);
        }
        break;
    }
    default:
        Abend_Panic(lbl_8033837C, mode);
        break;
    }

    resource = *(void **)(self + 0x244);
    {
        struct Resource {
            virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
            virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
            virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
            virtual void m12(); virtual void m13();
            virtual void update(int);
            virtual void m14(); virtual void m15();
        };
        ((Resource *)resource)->update(*(int *)(src + 0x1C));
    }
    self[0x1E9] = src[0x20];
    *(int *)(self + 0x24) = *(int *)(self + 0x28);
}
#pragma cplusplus reset
extern float PSVECDotProduct(const void *, const void *);
extern void PSVECCrossProduct(const void *, const void *, float *);
extern float PSVECSquareDistance(const void *, const void *);
extern void fn_8017A580(void *);
extern void fn_8017A57C(void *);
extern void fn_801A4868(void *, int);
extern float lbl_80562AAC, lbl_80562AB8, lbl_80562ABC, lbl_80562AC8, lbl_80562ACC, lbl_80562AD0, lbl_80562AD4;
#pragma push
#pragma processor 750
#pragma opt_common_subs off
void fn_801D4598(void *arg0, float farg0) {
    char *p = (char *)arg0;
    float sp8[3], dot, scale;
    void *other;
    dot = PSVECDotProduct(p + 0x54, p + 0x20C);
    if (farg0 < (*(float *)(p + 0x224) + *(float *)(p + 0x234)) ||
        dot < lbl_80562AC8 ||
        ((other = *(void **)(p + 0x22C)) != 0 &&
         PSVECSquareDistance((char *)other + 0x60, p + 0x218) <
         ((lbl_80562AAC + *(float *)(p + 0x240)) * (lbl_80562AAC + *(float *)(p + 0x240))))) {
        float f5, f6, f7;
        float step;
        PSVECCrossProduct(p + 0x54, p + 0x20C, sp8);
        scale = dot - lbl_80562ACC;
        {
            float zero = lbl_80562AB8;
            *(float *)(p + 0x118) = zero;
            *(float *)(p + 0x11C) = zero;
            *(float *)(p + 0x120) = zero;
            zero = (zero < scale) ? zero : scale;
            scale = lbl_80562AD0 + zero;
        }
        scale = (lbl_80562AB8 > scale) ? lbl_80562AB8 : scale;
        f7 = *(float *)(p + 0x124) * scale;
        f6 = *(float *)(p + 0x128) * scale;
        f5 = *(float *)(p + 0x12C) * scale;
        step = lbl_80562AD4;
        *(float *)(p + 0x124) = f7;
        *(float *)(p + 0x128) = f6;
        *(float *)(p + 0x12C) = f5;
        {
            float py = *(float *)(p + 0x21C);
            float px = *(float *)(p + 0x218);
            float pz = *(float *)(p + 0x220);
            *(float *)(p + 0x124) = f7 + sp8[0] * step;
            *(float *)(p + 0x128) = f6 + sp8[1] * step;
            f5 += sp8[2] * step;
            *(float *)(p + 0x64) = py;
            *(float *)(p + 0x60) = px;
            *(float *)(p + 0x68) = pz;
            *(float *)(p + 0x12C) = f5;
        }
        fn_8017A580(arg0);
    } else fn_801D411C(arg0);
}
#pragma pop

/* Default no-op handler: takes no inputs and reports 0 (nothing handled / failure). */
int fn_801D470C(void) { return 0; }

/* No-op/default handler: simply clears the two output values. */
void fn_801D4714(void *unused0, void *unused1, void *unused2, int *out0, int *out1) { *out1 = 0; *out0 = 0; }

/* Default handler: reports failure/unavailable by returning 0. */
int fn_801D4724(void) { return 0; }


