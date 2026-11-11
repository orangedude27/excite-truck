#include "types.h"
#include <string.h>

#pragma ppc_psq_save off

#pragma cplusplus on

struct DummyVec2 {
    f32 x;
    f32 y;
};

class DummyItem {
public:
    virtual void v0();
    virtual s32 v1(const char *name);
    virtual void v2();
    virtual void v3(const char *name);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual f32 getHit(const char *name);
    virtual f32 v8(const char *name, f32 value);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual DummyVec2 getLoc(const char *name);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void *getObject(const char *name, s32 x, s32 y, void *arg);
};

class DummyArg1 {
public:
    virtual const char *getName();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual DummyItem *getItem(s32 index);
};

struct DummyRecordObj {
    u8 pad[0x18];
    f32 f18;
};

struct DummyRecord {
    DummyRecordObj *obj;
    f32 x;
    f32 y;
    f32 z;
    f32 hit;
    u8 flag;
    u8 pad[3];
};

struct DummyEntry {
    s32 id;
    u8 active;
    u8 pad5[3];
    f32 f8;
    f32 fC;
    f32 f10;
    s32 recordStart;
    s32 recordCount;
    u8 byte1C;
    u8 byte1D;
    u8 pad1E[2];
};

struct DummyManager {
    DummyRecord *records;
    s32 recordCount;
    u8 pad8[0x1D4CC - 8];
    DummyEntry *entries;
    s32 entryCount;
    u8 pad1D4D4[0x1E158 - 0x1D4D4];
    u8 flag1E158;
};

/* One entry of the 16-entry spin-matrix table at lbl_8042FF60 (48 bytes each).
   fn_801678D8 fills rot[] with a Y-axis rotation; the consumer (fn_80168020)
   picks an entry by (record/12)&0xF and writes translate[] per object. */
struct SpinMatrix {
    f32 rot[9];      /* 3x3 rotation about the Y axis */
    f32 translate[3]; /* object position, filled in by the consumer */
};

extern "C" {
extern char lbl_8055A1C0[8];
extern char lbl_8055A1C8[4];
extern char lbl_8055A1CC[4];
extern f32 lbl_80561924;
extern f32 lbl_80561938;
extern f32 lbl_80561950;
extern double lbl_80561930;
extern char lbl_80330000[];
extern s32 *fn_801399FC(DummyArg1 *);
extern s32 fn_80128658(s32 *);
extern void fn_802E30C8(const char *, ...);
extern int stricmp(const char *, const char *);
extern unsigned long long fn_80139C5C(s32 *);
extern s32 fn_801698B8(s32, s32, s32, s32);
extern s32 fn_80169928(s32, s32, s32, s32);
extern double fn_8002F234(f32);

int sscanf(const char *, const char *, ...);
void fn_801E9E30(void *, f32 *);
void fn_801EA1E0(f32 *, s32, f32, f32);
}

#pragma cplusplus reset

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
extern s32 lbl_8055E354;
extern s32 lbl_80430260[];
extern s32 fn_80128668(void);
extern char lbl_80330020[];
extern char lbl_803300E0[];
extern void fn_802E317C(const char *, ...);
#pragma optimization_level 2
#pragma scheduling invalid_target
s32 *fn_80167874(s32 arg0) {
    s32 *entry;
    s32 value;
    for (entry = (s32 *)lbl_80330020; (value = *entry) != 6; entry += 8) {
        if (value == arg0)
            return entry;
    }
    fn_802E317C(lbl_803300E0, arg0);
    return (s32 *)lbl_80330020;
}
#pragma scheduling on
#pragma optimization_level reset
extern double cos(float);
extern double sin(float);
extern int lbl_8055E3C4;
extern float lbl_8055E460;
extern float lbl_80561918, lbl_8056191C, lbl_80561920, lbl_80561924, lbl_80561928;
extern double lbl_80561930;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma optimize_for_size off
void fn_801678D8(void) {
    extern unsigned char lbl_8042FF60[];
    float *out;
    float temp_f1;
    float temp_f26;
    float temp_f25;
    float temp_f31;
    float temp_f30;
    float temp_f29;
    float temp_f28;
    float intpart;
    float base;
    int index;
    out = (float *)lbl_8042FF60;
    index = 0;
    base = lbl_8055E460;
    intpart = (float)lbl_8055E3C4;
    temp_f28 = lbl_80561920;
    temp_f29 = lbl_8056191C;
    temp_f30 = lbl_80561924;
    temp_f31 = lbl_80561928;
    temp_f25 = lbl_80561918 * (intpart + base);
    do {
        temp_f26 = (float)cos(temp_f29 * (temp_f25 + ((float)index * temp_f28)));
        temp_f1 = (float)sin(temp_f29 * (temp_f25 + ((float)index * temp_f28)));
        out[0] = temp_f26;
        index += 1;
        out[1] = temp_f30;
        out[2] = -temp_f1;
        out[3] = temp_f30;
        out[4] = temp_f31;
        out[5] = temp_f30;
        out[6] = temp_f1;
        out[7] = temp_f30;
        out[8] = temp_f26;
        out += 12;
    } while (index < 0x10);
}
#pragma pop
extern s32 *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(s32);
extern void *fn_801284F8(s32, void *, void *, void *);
extern void fn_8002F53C(void *, void *, void *, s32, s32);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void fn_802C77F0();
extern void *fn_80131810(void);
extern void fn_80131818(void *);
extern void fn_80168020(void);
extern void fn_80167EE0(s32 *);
extern int *fn_80167E98(int *, int);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801679F0(void) {
    class DummyShortItem {
    public:
        virtual s32 v1(const char *name);
        virtual void v0();
        virtual void v2();
        virtual void v3(const char *name);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual f32 v7(const char *name);
        virtual f32 v8(const char *name, f32 value);
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual DummyVec2 v13(const char *name);
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void *getObject(const char *name);
    };
    class DummyContainerLocal {
    public:
        virtual void v0();
        virtual DummyArg1 *getItem(s32 index);
    };
    class DummyParamLocal {
    public:
        virtual void v0();
        virtual s32 check(s32 value);
        virtual void apply(DummyArg1 *item, void *manager, s32 *coords);
    };
    extern char lbl_80330000[];
    extern char lbl_80330234[], lbl_80330248[], lbl_8033025C[], lbl_80330270[];
    extern f32 lbl_802F9514[3];
    extern s32 lbl_8055E354;
    extern f32 lbl_80561938;
    struct Local {
        DummyParamLocal *sp8;
        DummyParamLocal *spC;
        DummyParamLocal *sp14;
        DummyParamLocal *sp10;
        s32 sp18[3];
        s32 pad24;
        f32 sp28[6];
        DummyParamLocal **sp40[5];
    } local;
    register u8 *base;
    register s32 zero;
    register void *manager;
    s32 i;
    u8 *entry;
    DummyItem *object;
    DummyArg1 *item;
    DummyContainerLocal *container;
    void *child;
    DummyParamLocal ***slot;
    s32 value;
    s32 result;
    f32 f2;
    f32 f3;
    f32 f0;
    f32 f1;
    f32 scale;
    base = (u8 *)lbl_80330000;
    object = (DummyItem *)*(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
    local.sp10 = (DummyParamLocal *)lbl_8033025C;
    local.sp14 = (DummyParamLocal *)lbl_80330270;
    local.sp40[0] = &local.sp8;
    local.spC = (DummyParamLocal *)lbl_80330248;
    local.sp8 = (DummyParamLocal *)lbl_80330234;
    zero = 0;
    local.sp40[4] = (DummyParamLocal **)zero;
    local.sp40[1] = &local.sp14;
    local.sp40[2] = &local.sp10;
    local.sp40[3] = &local.spC;
    manager = fn_801284F8(0x1E15C, base + 0x1D8, &local.sp10, &local.sp14);
    if (manager) {
        *(void **)manager = (u8 *)manager + 0xC;
        *(s32 *)((u8 *)manager + 8) = 0x1388;
        *(s32 *)((u8 *)manager + 4) = zero;
        fn_8002F53C((u8 *)manager + 0xC, fn_80167EE0, fn_80167E98, 0x18, 0x1388);
        scale = lbl_80561938;
        *(u8 **)((u8 *)manager + 0x1D4CC) = (u8 *)manager + 0x1D4D8;
        *(s32 *)((u8 *)manager + 0x1D4D4) = 0x64;
        *(s32 *)((u8 *)manager + 0x1D4D0) = zero;
        entry = base + 0x20;
        i = zero;
        do {
            value = fn_802C6FC0(*(s32 *)(entry + 4), zero, zero);
            *(s32 *)(entry + 0x10) = value;
            *(s32 *)(entry + 0x1C) = zero;
            if (value != -1) {
                fn_802C77F0((void *)value, local.sp28);
                f2 = local.sp28[5] - local.sp28[4];
                f3 = local.sp28[3] - local.sp28[2];
                if (f3 > f2) {
                    f3 = f3;
                } else {
                    f3 = f2;
                }
                f0 = local.sp28[1] - local.sp28[0];
                if (f0 > f3) {
                    f0 = f0;
                } else {
                    f0 = f3;
                }
                *(f32 *)(entry + 0x14) = scale * f0;
                *(f32 *)(entry + 0x18) = -local.sp28[2];
            }
            i++;
            entry += 0x20;
        } while (5 > i);
        *((u8 *)manager + 0x1E158) = (u8)zero;
    }
    lbl_8055E354 = (s32)manager;
    if (object->v1((const char *)base + 0x1E8) != 0) {
        local.sp18[0] = ((s32 *)lbl_802F9514)[0];
        local.sp18[1] = ((s32 *)lbl_802F9514)[1];
        local.sp18[2] = ((s32 *)lbl_802F9514)[2];
        result = (s32)object->getObject((const char *)base + 0x1F4, local.sp18[1], local.sp18[0], lbl_802F9514);
        if (((u32)(-result | result) >> 31) != 0) {
            child = ((DummyShortItem *)object)->getObject((const char *)base + 0x1F4);
            f1 = ((DummyItem *)child)->v8((const char *)base + 0x200, *(f32 *)&local.sp18[0]);
            *(f32 *)&local.sp18[0] = f1;
            f1 = ((DummyItem *)child)->v8((const char *)base + 0x210, *(f32 *)&local.sp18[1]);
            *(f32 *)&local.sp18[1] = f1;
            f1 = ((DummyItem *)child)->v8((const char *)base + 0x220, *(f32 *)&local.sp18[2]);
            *(f32 *)&local.sp18[2] = f1;
        }
        ((void (*)(void *, void *))(*(void ***)object)[5])(object, base + 0x1E8);
        container = (DummyContainerLocal *)fn_80131810();
        if (container) {
            i = 0;
            goto item_check;
        item_body:
            slot = local.sp40;
            do {
                s32 value2 = (s32)((DummyArg1 *)item)->getName();
                if (((DummyParamLocal *)*slot)->check(value2) != 0) {
                    ((DummyParamLocal *)*slot)->apply(
                        item, (void *)lbl_8055E354, local.sp18);
                    break;
                }
                slot++;
            } while (*slot != 0);
            i += 1;
        item_check:
            item = container->getItem(i);
            if (item)
                goto item_body;
            fn_80131818(container);
        }
    }
    fn_80168020();
}
#pragma cplusplus reset
#pragma pop

s32 fn_80167D58(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80167D98(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80167DD8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80167E18(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80167E58(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int *fn_80167E98(int *arg0, int arg1) {
    if (arg0 != 0) {
        *arg0 = 0;
        if (arg1 > 0)
            fn_80128668();
    }
    return arg0;
}

void fn_80167EE0(s32 *arg0) {
    *arg0 = 0;
}

extern void fn_8002F634(void *, void *, s32, s32);
extern void fn_802C6CF8(s32);
#pragma cplusplus on
void fn_8002F634(void *, void *, s32, s32);
void fn_802C6CF8(s32);
extern "C" void fn_80167EEC(void) {
    u8 *entry;
    s32 *global;
    s32 i;
    u8 *manager = (u8 *)(u32)lbl_8055E354;
    if (manager == 0) {
        return;
    }
    global = (s32 *)lbl_80330020;
    global[7] = 0;
    global[15] = 0;
    global[23] = 0;
    global[31] = 0;
    global[39] = 0;
    i = *(s32 *)(manager + 4);
    while (i-- > 0) {
        *(s32 *)(*(u32 *)manager + i * 0x18) = 0;
    }
    *(s32 *)(manager + 4) = 0;
    *(s32 *)(manager + 0x1D4D0) = 0;
    *(u8 *)(manager + 0x1E158) = 0;
    entry = (u8 *)lbl_80330020;
    i = 0;
    for (; i < 5; i++, entry += 0x20) {
        if (*(s32 *)(entry + 0x10) != -1) {
            fn_802C6CF8(*(s32 *)(entry + 0x10));
            *(s32 *)(entry + 0x10) = -1;
        }
    }
    if ((manager + 0x1D4CC) != 0 && (manager + 0x1D4CC) != 0) {
        *(s32 *)(manager + 0x1D4CC) = 0;
        *(s32 *)(manager + 0x1D4D0) = 0;
        *(s32 *)(manager + 0x1D4D4) = 0;
    }
    if (manager != 0) {
        fn_8002F634(manager + 0xC, (void *)fn_80167E98, 0x18, 0x1388);
        if (manager != 0) {
            *(s32 *)(manager + 0) = 0;
            *(s32 *)(manager + 4) = 0;
            *(s32 *)(manager + 8) = 0;
        }
        ((s32 (*)(void *))fn_80128668)(manager);
    }
}
#pragma cplusplus reset
void fn_80168020(void) {
    register u8 *manager;
    register s32 i;
    register u8 *record;
    register s32 offset;
    register s32 zero;

    manager = (u8 *)(u32)lbl_8055E354;
    i = 0;
    offset = 0;
    zero = 0;
    goto first_check;
first_body:
    {
        register u8 *object;
        register f32 h;
        register f32 z;
        register f32 y;

        record = (u8 *)(u32)*(u32 *)manager + offset;
        fn_801E9E30(0, (f32 *)(record + 4));
        object = (u8 *)(u32)*(u32 *)record;
        i += 1;
        y = *(f32 *)(record + 8);
        offset += 0x18;
        h = *(f32 *)(object + 0x18);
        z = *(f32 *)(record + 0x10);
        *(f32 *)(record + 8) = y + h + z;
        *(u8 *)(record + 0x14) = zero;
    }
first_check:
    if (i < *(s32 *)(manager + 4))
        goto first_body;

    {
        register s32 count = 0;
        register s32 byteOffset = 0;
        register s32 byteValue = 0;
        goto second_check;
second_body:
        {
            register u8 *entry = (u8 *)(u32)*(u32 *)(manager + 0x1D4CC) + byteOffset;
            count += 1;
            *(u8 *)(entry + 0x1D) = byteValue;
            byteOffset += 0x20;
        }
second_check:
        if (count < *(s32 *)(manager + 0x1D4D0))
            goto second_body;
    }

    {
        register s32 value = -1;
        register s32 *table = lbl_80430260 + 1;
        *--table = value;
        table[4] = value;
        table[8] = value;
        table[12] = value;
        table[16] = value;
        table[20] = value;
        table[24] = value;
        table[28] = value;
    }
}

#pragma push
#pragma processor 750
void fn_80168104(void) {
    extern void *fn_802C86DC(void);
    extern f64 fn_8002F234(f32);
    extern u32 fn_802C9994(u32);
    extern u32 fn_802C9950(u32);
    extern void fn_802C9900(f32);
    extern void fn_802C9904(void);
    extern void fn_802C744C(void *, void *);
    extern u8 lbl_8042FF60[];
    extern f32 lbl_8056193C;
    extern f32 lbl_80561940;
    extern f64 lbl_80561948;
    struct { f32 x, y; } pos, d;
    u8 *data = (u8 *)fn_802C86DC();
    s32 i, offset;
    f32 scale = lbl_80561940;
    f32 limit = lbl_8056193C;
    pos.x = *(f32 *)(data + 0x24);
    pos.y = *(f32 *)(data + 0x2C);
    offset = 0;
    for (i = 0; i < *(s32 *)((u8 *)lbl_8055E354 + 0x1D4D0); i++, offset += 0x20) {
        u8 *entry = *(u8 **)((u8 *)lbl_8055E354 + 0x1D4CC) + offset;
        s32 j;
        if (entry[4] == 0) continue;
        if (entry[0x1C] == 0 || (d.y = pos.y - *(f32 *)(entry + 0xC), d.x = pos.x - *(f32 *)(entry + 8), (f32)fn_8002F234(d.x * d.x + d.y * d.y) - *(f32 *)(entry + 0x10) < limit)) {
            for (j = 0; j < *(s32 *)(*(u8 **)((u8 *)lbl_8055E354 + 0x1D4CC) + offset + 0x18); j++) {
                u8 *record = *(u8 **)lbl_8055E354 + (*(s32 *)(*(u8 **)((u8 *)lbl_8055E354 + 0x1D4CC) + offset + 0x14) + j) * 0x18;
                u8 *obj = *(u8 **)record;
                if (obj != 0 && *(s32 *)(obj + 0x10) != 0 && record[0x14] == 0) {
                    u32 token = obj ? *(u32 *)(obj + 8) : (u32)-1;
                    u32 a = fn_802C9994(token);
                    u32 b = fn_802C9950((((token >> 25) & 0x7F) << 24) | (((token >> 17) & 0x7F) << 16) | (((token >> 9) & 0x7F) << 8) | ((token >> 1) & 0x7F));
                    fn_802C9900(((f32)(token >> 24) - (f32)lbl_80561948) / scale);
                    {
                        u8 *out = lbl_8042FF60 + ((*(s32 *)record / 12) & 0xF) * 0x30;
                        *(f32 *)(out + 0x24) = *(f32 *)(record + 4);
                        *(f32 *)(out + 0x28) = *(f32 *)(record + 8);
                        *(f32 *)(out + 0x2C) = *(f32 *)(record + 0xC);
                        fn_802C744C(*(void **)(*(u32 *)record + 0x10), out);
                    }
                    fn_802C9994(a);
                    fn_802C9950(b);
                    fn_802C9904();
                }
            }
        }
    }
}
#pragma pop
void fn_80168328(void) {
    extern s32 lbl_8055E354;
    extern void fn_801678D8(void);
    s32 *root;
    s32 i, offset, j, count;
    s32 *records;
    u8 *entry;
    root = &lbl_8055E354;
    fn_801678D8();
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)root + 0x1D4D0)) {
        entry = (u8 *)(*(s32 **)((u8 *)root + 0x1D4CC)) + offset;
        if (entry[0x1D] == 0) {
            entry[0x1D] = 1;
            count = *(s32 *)(entry + 0x18);
            j = 0;
            while (count > 0) {
                records = *(s32 **)root;
                if (*(s32 *)((u8 *)records + (*(s32 *)(entry + 0x14) + j) * 0x18) == 0 ||
                    *((u8 *)*(s32 *)((u8 *)records + (*(s32 *)(entry + 0x14) + j) * 0x18) + 0x14) != 0) {
                    j++;
                    count--;
                    continue;
                }
                entry[0x1D] = 0;
                break;
            }
        }
        offset += 0x20;
        i++;
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801683F4(void *arg0, s32 arg1) {
    extern s32 lbl_80430260[];
    extern s32 lbl_8055E354;
    extern f32 lbl_80561924;
    extern f32 lbl_80561950;
    extern void *fn_8017960C(s32);
    extern f64 fn_8002F234(f32);

    s32 counts[7];
    s32 num;
    s32 i;
    s32 j;
    s32 offset;
    s32 index;
    s32 *indexEntry;
    void *object;
    void *bounds;
    void *resource;
    void *entry;
    void *record;
    void *recordObject;
    volatile f32 x;
    volatile f32 z;
    volatile f32 minX;
    volatile f32 maxX;
    volatile f32 minZ;
    volatile f32 maxZ;
    volatile f32 ty;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 tx;
    f32 tz;
    f32 radius;

    memset(counts, 0, 0x18);
    object = fn_8017960C(arg1);
    indexEntry = (s32 *)((u8 *)lbl_80430260 + arg1 * 0x10);

    if (indexEntry[0] == lbl_8055E3C4 - 1) {
        num = 0;
        x = *(f32 *)((u8 *)object + 0x60);
        z = *(f32 *)((u8 *)object + 0x68);
        minX = lbl_80561924;
        maxX = lbl_80561924;
        minZ = lbl_80561924;
        maxZ = lbl_80561924;
        ty = lbl_80561924;
        radius = lbl_80561924;
        bounds = *(s32 *)((u8 *)object + 0x24) > 0 ? *(void **)((u8 *)object + 0x14) : 0;
        if (bounds != 0) {
            dx = *(f32 *)((u8 *)indexEntry + 4) - x;
            dy = *(f32 *)((u8 *)indexEntry + 8) - *(f32 *)((u8 *)object + 0x64);
            dz = *(f32 *)((u8 *)indexEntry + 0xC) - z;
            tx = dz * *(f32 *)((u8 *)object + 0x44)
               + (dx * *(f32 *)((u8 *)object + 0x3C)
               + dy * *(f32 *)((u8 *)object + 0x40));
            tz = dz * *(f32 *)((u8 *)object + 0x5C)
               + (dx * *(f32 *)((u8 *)object + 0x54)
               + dy * *(f32 *)((u8 *)object + 0x58));
            ty = dz * *(f32 *)((u8 *)object + 0x50)
               + (dx * *(f32 *)((u8 *)object + 0x48)
               + dy * *(f32 *)((u8 *)object + 0x4C));
            resource = *(void **)((u8 *)bounds + 0x17C);
            minX = tx < lbl_80561924 ? lbl_80561924 : tx;
            minX -= lbl_80561950 * *(f32 *)((u8 *)resource + 0x24);
            minZ = tz < lbl_80561924 ? lbl_80561924 : tz;
            minZ -= lbl_80561950 * *(f32 *)((u8 *)resource + 0x2C);
            maxX = tx > lbl_80561924 ? lbl_80561924 : tx;
            maxX += lbl_80561950 * *(f32 *)((u8 *)resource + 0x24);
            maxZ = tz > lbl_80561924 ? lbl_80561924 : tz;
            maxZ += lbl_80561950 * *(f32 *)((u8 *)resource + 0x2C);
            radius = (f32)fn_8002F234(
                *(f32 *)((u8 *)resource + 0x24) * *(f32 *)((u8 *)resource + 0x24)
              + *(f32 *)((u8 *)resource + 0x2C) * *(f32 *)((u8 *)resource + 0x2C));
        }

        i = 0;
        offset = 0;
        while (i < *(s32 *)((u8 *)(u32)lbl_8055E354 + 0x1D4D0)) {
            entry = (u8 *)*(void **)((u8 *)(u32)lbl_8055E354 + 0x1D4CC) + offset;
            if (*(u8 *)((u8 *)entry + 0x1D) != 0) {
                num++;
            } else if (*(u8 *)((u8 *)entry + 4) != 0 &&
                (*(u8 *)((u8 *)entry + 0x1C) == 0 ||
                 (f32)fn_8002F234(
                    (z - *(f32 *)((u8 *)entry + 0xC)) * (z - *(f32 *)((u8 *)entry + 0xC))
                  + (x - *(f32 *)((u8 *)entry + 8)) * (x - *(f32 *)((u8 *)entry + 8))
                 ) < radius + *(f32 *)((u8 *)entry + 0x10))) {
                j = 0;
                while (j < *(s32 *)((u8 *)entry + 0x18)) {
                    record = (u8 *)(void *)*(void **)(u32)lbl_8055E354 +
                        (*(s32 *)((u8 *)entry + 0x14) + j) * 0x18;
                    recordObject = *(void **)record;
                    if (recordObject != 0 &&
                        *(s32 *)((u8 *)recordObject + 0x10) != 0 &&
                        *(u8 *)((u8 *)record + 0x14) == 0) {
                        dx = *(f32 *)((u8 *)record + 4) - x;
                        dy = *(f32 *)((u8 *)record + 8) - *(f32 *)((u8 *)object + 0x64);
                        dz = *(f32 *)((u8 *)record + 0xC) - z;
                        tx = dz * *(f32 *)((u8 *)object + 0x44)
                           + (dx * *(f32 *)((u8 *)object + 0x3C)
                           + dy * *(f32 *)((u8 *)object + 0x40));
                        tz = dz * *(f32 *)((u8 *)object + 0x5C)
                           + (dx * *(f32 *)((u8 *)object + 0x54)
                           + dy * *(f32 *)((u8 *)object + 0x58));
                        ty = dz * *(f32 *)((u8 *)object + 0x50)
                           + (dx * *(f32 *)((u8 *)object + 0x48)
                           + dy * *(f32 *)((u8 *)object + 0x4C));
                        radius = *(f32 *)((u8 *)recordObject + 0x14);
                        if (tx + radius > minX && tx - radius < maxX &&
                            tz + radius > minZ && tz - radius < maxZ) {
                            *(u8 *)((u8 *)record + 0x14) = 1;
                            index = *(s32 *)recordObject;
                            counts[index]++;
                        }
                    }
                    j++;
                }
            }
            offset += 0x20;
            i++;
        }
    }

    *(f32 *)((u8 *)indexEntry + 4) = *(f32 *)((u8 *)object + 0x60);
    *(f32 *)((u8 *)indexEntry + 8) = *(f32 *)((u8 *)object + 0x64);
    *(f32 *)((u8 *)indexEntry + 0xC) = *(f32 *)((u8 *)object + 0x68);
    indexEntry[0] = lbl_8055E3C4;
    ((s32 *)arg0)[0] = counts[0];
    ((s32 *)arg0)[1] = counts[1];
    ((s32 *)arg0)[2] = counts[2];
    ((s32 *)arg0)[3] = counts[3];
    ((s32 *)arg0)[4] = counts[4];
    ((s32 *)arg0)[5] = num;
}
#pragma use_lmw_stmw reset
#pragma processor reset
#pragma pop
extern s32 fn_8002B1D8(s32, s32 *, s32);
extern char lbl_803301B8[];
extern s32 lbl_8055E354;
extern s32 lbl_80430260[];
void fn_801688B4(s32 arg0) {
    u8 *base = (u8 *)lbl_8055E354 + 0x20000;
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)(base - 0x2B30)) {
        s32 *record = (s32 *)(*(s32 *)(base - 0x2B34) + offset);
        if (arg0 == *(s32 *)((u8 *)record + offset)) {
            *((u8 *)record + 4) = 1;
        }
        offset += 0x20;
        i++;
    }
}

void fn_801688FC(s32 arg0) {
    s32 i = 0;
    s32 offset = 0;
    u8 *base = (u8 *)(u32)lbl_8055E354 + 0x20000;
    while (i < *(s32 *)(base - 0x2B30)) {
        s32 table = *(s32 *)(base - 0x2B34);
        if (arg0 == *(s32 *)(table + offset)) {
            *((u8 *)(table + offset) + 4) = 0;
        }
        offset += 0x20;
        i++;
    }
}

s32 fn_80168944(s32 arg0, s32 arg1) {
    s32 addr = (s32)lbl_803301B8;
    s32 len = strlen((char *)addr);
    s32 r = fn_8002B1D8(arg1, (s32 *)addr, len);
    return (u32)__cntlzw(r) >> 5;
}

#pragma push
#pragma processor 750
#pragma cplusplus on
extern char lbl_802F94B8[];
extern "C" s32 fn_8016899C(void *arg0, DummyArg1 *arg1, DummyManager *arg2, f32 *arg3) {
    class DummyCheck {
    public:
        virtual void v0();
        virtual void v1();
        virtual s32 check(const char *name);
    };

    s32 *values;

    if (((DummyCheck *)arg0)->check(arg1->getName()) == 0) {
        fn_802E30C8(lbl_80330000 + 0x298, arg1->getName());
        return 0;
    }

    values = fn_801399FC(arg1);
    if (*values < 2) {
        fn_802E30C8(lbl_80330000 + 0x2D0, arg1->getName());
        fn_80128658(values);
        return 0;
    }

    /* TODO: reconstruct full path/record generation from target asm */
    (void)arg2;
    (void)arg3;
    (void)lbl_802F94B8;
    fn_80128658(values);
    return 1;
}
#pragma cplusplus reset
#pragma pop

extern char lbl_80330364[];
s32 fn_80169108(s32 arg0, s32 arg1) {
    s32 addr = (s32)lbl_80330364;
    s32 len = strlen((char *)addr);
    s32 r = fn_8002B1D8(arg1, (s32 *)addr, len);
    return (u32)__cntlzw(r) >> 5;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_80169160(void *arg0, DummyArg1 *arg1, DummyManager *arg2, f32 *arg3) {
    class DummyCheck {
    public:
        virtual void v0();
        virtual s32 check(const char *name);
    };

    s32 *values;
    DummyEntry *entry;
    f32 *cursor;
    f32 diffs[8];
    f32 dist[4];
    s32 off;
    f32 total;
    s32 outerCount;
    s32 (*selector)(s32, s32, s32, s32);
    f32 outerRem;
    f32 outerStart;
    DummyVec2 a;
    DummyVec2 b;
    DummyVec2 p;
    s32 i;
    s32 j;

    if (((DummyCheck *)arg0)->check(arg1->getName()) == 0) {
        fn_802E30C8(lbl_80330000 + 0x370, arg1->getName());
        return 0;
    }

    values = fn_801399FC(arg1);
    if (*values < 4 || *values > 4) {
        fn_802E30C8(lbl_80330000 + 0x3A4, arg1->getName(), *values);
        fn_80128658(values);
        return 0;
    }

    cursor = (f32 *)values;
    diffs[0] = cursor[2] - cursor[4];
    diffs[1] = cursor[3] - cursor[5];
    dist[0] = (f32)fn_8002F234(diffs[0] * diffs[0] + diffs[1] * diffs[1]);
    diffs[2] = cursor[6] - cursor[4];
    diffs[3] = cursor[7] - cursor[5];
    dist[1] = (f32)fn_8002F234(diffs[2] * diffs[2] + diffs[3] * diffs[3]);
    diffs[4] = cursor[6] - cursor[8];
    diffs[5] = cursor[7] - cursor[9];
    dist[2] = (f32)fn_8002F234(diffs[4] * diffs[4] + diffs[5] * diffs[5]);
    diffs[6] = cursor[2] - cursor[8];
    diffs[7] = cursor[3] - cursor[9];
    dist[3] = (f32)fn_8002F234(diffs[6] * diffs[6] + diffs[7] * diffs[7]);

    off = (dist[0] + dist[2] <= dist[1] + dist[3]);
    total = lbl_80561938 * (dist[off] + dist[(off + 2) % 4]);
    outerCount = 1;
    {
        s32 tmp = (s32)(total / *arg3);
        if (tmp > 1)
            outerCount = tmp;
    }
    outerRem = total - (f32)outerCount * *arg3;
    selector = fn_80169928;
    if (stricmp(arg1->getName(), lbl_80330000 + 0x3E0) == 0)
        selector = fn_801698B8;
    entry = &arg2->entries[arg2->entryCount++];
    entry->byte1C = 1;
    if (values != 0) {
        union { unsigned long long u; f32 f[2]; } center;
        center.u = fn_80139C5C(values);
        entry->f8 = center.f[0];
        entry->fC = center.f[1];
        entry->f10 = lbl_80561924;
        {
            u8 *cur = (u8 *)values;
            s32 k = 0;
            do {
                f32 dx = entry->f8 - *(f32 *)(cur + 8);
                f32 dy = entry->fC - *(f32 *)(cur + 12);
                f32 d2 = dx * dx + dy * dy;
                if (entry->f10 < d2)
                    entry->f10 = d2;
                cur += 8;
                k++;
            } while (k < *values);
        }
        entry->f10 = lbl_80561950 * (f32)fn_8002F234(entry->f10);
    } else {
        entry->byte1C = 0;
        entry->f8 = lbl_80561924;
        entry->fC = lbl_80561924;
        entry->f10 = lbl_80561924;
    }
    entry->recordStart = arg2->recordCount;
    entry->recordCount = 0;
    entry->byte1D = 0;
    entry->id = -1;
    entry->active = 1;
    arg2->flag1E158 = 1;

    outerStart = lbl_80561938 * outerRem;
    {
        f32 *pA0 = (f32 *)((u8 *)values + off * 8);
        f32 *pA1 = (f32 *)((u8 *)values + ((off + 1) % 4) * 8);
        f32 *pB0 = (f32 *)((u8 *)values + ((off + 3) % 4) * 8);
        f32 *pB1 = (f32 *)((u8 *)values + ((off + 2) % 4) * 8);

        for (i = 0; i <= outerCount; i++) {
            f32 u = (outerStart + (f32)i * *arg3) / total;
            a.x = pA0[2] + u * (pA1[2] - pA0[2]);
            a.y = pA0[3] + u * (pA1[3] - pA0[3]);
            b.x = pB0[2] + u * (pB1[2] - pB0[2]);
            b.y = pB0[3] + u * (pB1[3] - pB0[3]);
            f32 segLen = (f32)fn_8002F234((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
            s32 innerCount = 1;
            {
                s32 tmp = (s32)(segLen / *arg3);
                if (tmp > 1)
                    innerCount = tmp;
            }
            f32 innerStart = lbl_80561938 * (segLen - (f32)innerCount * *arg3);
            for (j = 0; j <= innerCount; j++) {
                f32 v = (innerStart + (f32)j * *arg3) / segLen;
                p.x = a.x + v * (b.x - a.x);
                p.y = a.y + v * (b.y - a.y);
                s32 selVal = selector(j, i, innerCount, outerCount);
                DummyRecord *rec = &arg2->records[arg2->recordCount++];
                rec->obj = 0;
                rec->obj = (DummyRecordObj *)fn_80167874(selVal);
                rec->x = p.x;
                rec->y = lbl_80561924;
                rec->z = p.y;
                rec->hit = lbl_80561924;
                fn_801E9E30(0, &rec->x);
                rec->y = rec->y + rec->obj->f18 + rec->hit;
                rec->flag = 0;
                fn_801EA1E0(&rec->y, 1, rec->x, rec->z);
                (*(s32 *)((u8 *)fn_80167874(selVal) + 0x1C))++;
                if (arg2->flag1E158 != 0) {
                    arg2->entries[arg2->entryCount - 1].recordCount++;
                } else {
                    if (arg2->entryCount == 0 || arg2->entries[arg2->entryCount - 1].byte1C != 0) {
                        DummyEntry *newEntry = &arg2->entries[arg2->entryCount++];
                        newEntry->byte1C = 0;
                        newEntry->recordStart = arg2->recordCount - 1;
                        newEntry->recordCount = 0;
                        newEntry->byte1D = 0;
                    }
                    arg2->entries[arg2->entryCount - 1].recordCount++;
                }
            }
        }
    }
    arg2->flag1E158 = 0;
    fn_80128658(values);
    return 1;
}
#pragma cplusplus reset
#pragma pop

s32 fn_801698B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r3, var_r4, var_r5;
    var_r3 = arg0;
    var_r4 = arg1;
    if (var_r3 > arg2 - var_r3)
        var_r3 = arg2 - var_r3;
    if (var_r4 > arg3 - var_r4)
        var_r4 = arg3 - var_r4;
    var_r5 = var_r3;
    if (var_r4 < var_r3)
        var_r5 = var_r4;
    if (var_r4 > var_r3)
        var_r3 = var_r4;
    if (var_r3 + var_r5 / 2 >= 3) {
        if (var_r3 + var_r5 / 2 >= 5)
            return 1;
        return 2;
    }
    return 3;
}

s32 fn_80169928(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 > arg3 - arg1)
        arg1 = arg3 - arg1;
    if (arg0 > arg2 - arg0)
        arg0 = arg2 - arg0;
    if (arg1 < arg0)
        arg0 = arg1;
    if (arg0 > 2)
        return 3;
    switch (arg0) {
    case 0:
    case 1:
        return 1;
    default:
        return 2;
    }
}

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
s32 fn_80169978(s32 arg0, s32 arg1) {
    s32 r = 0;
    if (fn_8002B1D8(arg1, &lbl_8055A198, 4) == 0 || fn_8002B1D8(arg1, &lbl_8055A1A0, 4) == 0) {
        r = 1;
    }
    return r;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 *fn_801399FC(DummyArg1 *);
extern "C" s32 fn_80128658(s32 *);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" char lbl_8055A1A8, lbl_8055A1B0;
extern "C" char lbl_803303EC[], lbl_80330420[];
extern "C" s32 fn_801699E4(void *arg0, DummyArg1 *arg1, DummyManager *arg2) {
    class DummyCheck {
    public:
        virtual void v0();
        virtual s32 checkName(const char *name);
    };

    f32 *cursor;
    s32 type;
    s32 *values;
    s32 i;
    s32 parsed;
    s32 id;
    f32 zero;
    DummyEntry *entry;

    if (((DummyCheck *)arg0)->checkName(arg1->getName()) == 0) {
        fn_802E30C8(lbl_803303EC, arg1->getName());
        return 0;
    }

    if (fn_8002B1D8((s32)&lbl_8055A198, (s32 *)arg1->getName(), 4) == 0) {
        type = 4;
    } else if (fn_8002B1D8((s32)&lbl_8055A1A0, (s32 *)arg1->getName(), 4) == 0) {
        type = 1;
    } else {
        fn_802E30C8(lbl_80330420, arg1->getName());
        return 0;
    }

    parsed = -1;
    if (type == 1) {
        sscanf(arg1->getName(), (const char *)&lbl_8055A1A8, &parsed);
    } else if (type == 4) {
        sscanf(arg1->getName(), (const char *)&lbl_8055A1B0, &parsed);
    }

    values = fn_801399FC(arg1);
    id = parsed;
    entry = &arg2->entries[arg2->entryCount];
    arg2->entryCount = arg2->entryCount + 1;
    zero = lbl_80561924;
    entry->byte1C = 0;
    entry->f8 = zero;
    entry->fC = zero;
    entry->f10 = zero;
    entry->recordStart = arg2->recordCount;
    entry->recordCount = 0;
    entry->byte1D = 0;
    entry->id = id;
    entry->active = 1;
    arg2->flag1E158 = 1;

    cursor = (f32 *)values;
    i = 0;
    for (; i < *values; i++) {
        DummyRecord *rec = &arg2->records[arg2->recordCount++];
        rec->obj = 0;
        rec->obj = (DummyRecordObj *)fn_80167874(type);
        rec->x = cursor[2];
        rec->y = zero;
        rec->z = cursor[3];
        rec->hit = zero;
        fn_801E9E30(0, &rec->x);
        rec->y = rec->hit + (rec->y + rec->obj->f18);
        rec->flag = 0;
        fn_801EA1E0(&rec->y, 1, rec->x, rec->z);
        (*(s32 *)((u8 *)fn_80167874(type) + 0x1C))++;

        if (arg2->flag1E158 != 0) {
            entry = &arg2->entries[arg2->entryCount - 1];
            entry->recordCount++;
        } else {
            if (arg2->entryCount == 0 || arg2->entries[arg2->entryCount - 1].byte1C != 0) {
                DummyEntry *newEntry = &arg2->entries[arg2->entryCount++];
                newEntry->byte1C = 0;
                newEntry->recordStart = arg2->recordCount - 1;
                newEntry->recordCount = 0;
                newEntry->byte1D = 0;
            }
            entry = &arg2->entries[arg2->entryCount - 1];
            entry->recordCount++;
        }
        cursor += 2;
    }

    arg2->flag1E158 = 0;
    fn_80128658(values);
    return 1;
}
#pragma cplusplus reset
#pragma pop

extern char lbl_8055A1B8;
s32 fn_80169D64(s32 arg0, s32 arg1) {
    s32 p = (s32)&lbl_8055A1B8;
    s32 len = strlen((char *)p);
    s32 r = fn_8002B1D8(arg1, (s32 *)p, len);
    return (u32)__cntlzw(r) >> 5;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 fn_80169DB8(void *arg0, DummyArg1 *arg1, DummyManager *arg2) {
    int sp8 = -1;
    DummyItem *item;
    s32 i;
    s32 id;

    sscanf(arg1->getName(), lbl_8055A1C0, &sp8);
    id = sp8;

    {
        DummyEntry *entry = &arg2->entries[arg2->entryCount++];
        entry->byte1C = 0;
        entry->f8 = lbl_80561924;
        entry->fC = lbl_80561924;
        entry->f10 = lbl_80561924;
        entry->recordStart = arg2->recordCount;
        entry->recordCount = 0;
        entry->byte1D = 0;
        entry->id = id;
        entry->active = 1;
        arg2->flag1E158 = 1;
    }

    for (i = 0; (item = arg1->getItem(i)) != 0; i++) {
        f32 hit = item->getHit(lbl_8055A1C8);
        DummyVec2 loc = item->getLoc(lbl_8055A1CC);
        s32 count = arg2->recordCount;
        arg2->recordCount = count + 1;
        DummyRecord *rec = &arg2->records[count];
        rec->obj = 0;
        rec->obj = (DummyRecordObj *)fn_80167874(1);
        rec->x = *(f32 *)&loc.x;
        rec->y = lbl_80561924;
        rec->z = *(f32 *)&loc.y;
        rec->hit = hit;
        fn_801E9E30(0, &rec->x);
        rec->y = rec->y + rec->obj->f18 + rec->hit;
        rec->flag = 0;
        fn_801EA1E0(&rec->y, 1, rec->x, rec->z);
        *(s32 *)((u8 *)fn_80167874(1) + 0x1C) += 1;

        if (arg2->flag1E158 != 0) {
            arg2->entries[arg2->entryCount - 1].recordCount++;
        } else {
            if (arg2->entryCount == 0 || arg2->entries[arg2->entryCount - 1].byte1C != 0) {
                DummyEntry *newEntry = &arg2->entries[arg2->entryCount++];
                newEntry->byte1C = 0;
                newEntry->recordStart = arg2->recordCount - 1;
                newEntry->recordCount = 0;
                newEntry->byte1D = 0;
            }
            arg2->entries[arg2->entryCount - 1].recordCount++;
        }
    }

    arg2->flag1E158 = 0;
    return 1;
}
#pragma pop

