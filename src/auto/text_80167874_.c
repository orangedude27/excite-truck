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
    virtual void v1();
    virtual void v2();
    virtual s32 v3(const char *name);
    virtual void v4();
    virtual void v5(const char *name);
    virtual void v6();
    virtual f32 getHit(const char *name);
    virtual void v8();
    virtual void v9();
    virtual f32 v10(const char *name, f32 value);
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
    virtual void v21();
    virtual void v22();
    virtual void *getObject(const char *name, ...);
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

extern "C" {
extern char lbl_8055A1C0[8];
extern char lbl_8055A1C8[4];
extern char lbl_8055A1CC[4];
extern f32 lbl_80561924;

int sscanf(const char *, const char *, ...);
void fn_801E9E30(void *, f32 *);
void fn_801EA1E0(f32 *, s32, f32, f32);
}

#pragma cplusplus reset

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
extern s32 fn_80128668(void);
extern s32 lbl_80330020;
extern char lbl_803300E0[];
extern void fn_802E317C(const char *);
#pragma dont_inline on
s32 *fn_80167874(s32 arg0) {
    s32 *entry = &lbl_80330020;
    for (;;) {
        s32 value = *entry;
        if (value == arg0)
            return entry;
        if (value == 6) {
            fn_802E317C(lbl_803300E0);
            return &lbl_80330020;
        }
        entry = (s32 *)((u8 *)entry + 0x20);
    }
}

extern double cos(float);
extern double sin(float);
extern int lbl_8055E3C4;
extern float lbl_8055E460;
extern float lbl_80561918, lbl_8056191C, lbl_80561920, lbl_80561924, lbl_80561928;
extern double lbl_80561930;
void fn_801678D8(void) {
    extern unsigned char lbl_8042FF60[];
    float *out;
    float temp_f1, temp_f25, temp_f26, temp_f28, temp_f29, temp_f30, temp_f31;
    int index;
    out = (float *)lbl_8042FF60;
    index = 0;
    temp_f28 = lbl_80561920;
    temp_f29 = lbl_8056191C;
    temp_f30 = lbl_80561924;
    temp_f31 = lbl_80561928;
    temp_f25 = lbl_80561918 * ((float)lbl_8055E3C4 + lbl_8055E460);
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
#pragma ppc_psq_save off
void fn_801679F0(void) {
    extern char lbl_80330000[];
    extern char lbl_80330234[], lbl_80330248[], lbl_8033025C[], lbl_80330270[];
    extern f32 lbl_802F9514[3];
    extern s32 lbl_8055E354;
    extern f32 lbl_80561938;
    struct Local {
        char *sp8;
        char *spC;
        char *sp10;
        char *sp14;
        s32 sp18[3];
        s32 pad24;
        f32 sp28[6];
        char **sp40[5];
    } local;
    u8 *base;
    u8 *entry;
    void *object;
    void *manager;
    void *container;
    void *item;
    void *child;
    char ***slot;
    s32 i;
    s32 value;
    s32 result;
    f32 f2;
    f32 f3;
    f32 f0;
    f32 f1;
    f32 scale;

    base = (u8 *)lbl_80330000;
    object = *(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
    local.sp14 = lbl_80330270;
    local.sp10 = lbl_8033025C;
    local.spC = lbl_80330248;
    local.sp8 = lbl_80330234;
    local.sp40[0] = &local.sp8;
    local.sp40[1] = &local.sp14;
    local.sp40[2] = &local.sp10;
    local.sp40[3] = &local.spC;
    local.sp40[4] = 0;

    manager = fn_801284F8(0x1E15C, base + 0x1D8, &local.sp10, &local.sp14);
    if (manager != 0) {
        *(void **)manager = (u8 *)manager + 0xC;
        *(s32 *)((u8 *)manager + 8) = 0x1388;
        *(s32 *)((u8 *)manager + 4) = 0;
        fn_8002F53C((u8 *)manager + 0xC, fn_80167EE0, fn_80167E98, 0x18, 0x1388);
        scale = lbl_80561938;
        *(u8 **)((u8 *)manager + 0x1D4CC) = (u8 *)manager + 0x1D4D8;
        *(s32 *)((u8 *)manager + 0x1D4D4) = 0x64;
        *(s32 *)((u8 *)manager + 0x1D4D0) = 0;
        entry = base + 0x20;
        i = 0;
        do {
            value = fn_802C6FC0(*(s32 *)(entry + 4), 0, 0);
            *(s32 *)(entry + 0x10) = value;
            *(s32 *)(entry + 0x1C) = 0;
            if (value != -1) {
                fn_802C77F0((void *)value, local.sp28);
                f2 = local.sp28[5] - local.sp28[4];
                f3 = local.sp28[3] - local.sp28[2];
                if (f3 <= f2)
                    f3 = f2;
                f0 = local.sp28[1] - local.sp28[0];
                if (f0 <= f3)
                    f0 = f3;
                *(f32 *)(entry + 0x14) = scale * f0;
                *(f32 *)(entry + 0x18) = -local.sp28[2];
            }
            i += 1;
            entry += 0x20;
        } while (i < 5);
        *((u8 *)manager + 0x1E158) = 0;
    }
    lbl_8055E354 = (s32)manager;
    if (((s32 (*)(void *, void *))(*(void ***)object)[3])(object, base + 0x1E8) != 0) {
        local.sp18[0] = ((s32 *)lbl_802F9514)[0];
        local.sp18[1] = ((s32 *)lbl_802F9514)[1];
        local.sp18[2] = ((s32 *)lbl_802F9514)[2];
        result = ((s32 (*)(void *, void *, s32, s32, void *))(*(void ***)object)[23])(
            object, base + 0x1F4, local.sp18[1], local.sp18[0], lbl_802F9514);
        if (((u32)(-result | result) >> 31) != 0) {
            child = ((void *(*)(void *, void *))(*(void ***)object)[23])(object, base + 0x1F4);
            f1 = ((f32 (*)(void *, void *, f32))(*(void ***)child)[10])(
                child, base + 0x200, *(f32 *)&local.sp18[0]);
            *(f32 *)&local.sp18[0] = f1;
            f1 = ((f32 (*)(void *, void *, f32))(*(void ***)child)[10])(
                child, base + 0x210, *(f32 *)&local.sp18[1]);
            *(f32 *)&local.sp18[1] = f1;
            f1 = ((f32 (*)(void *, void *, f32))(*(void ***)child)[10])(
                child, base + 0x220, *(f32 *)&local.sp18[2]);
            *(f32 *)&local.sp18[2] = f1;
        }
        ((void (*)(void *, void *))(*(void ***)object)[5])(object, base + 0x1E8);
        container = fn_80131810();
        if (container != 0) {
            i = 0;
            item = ((void *(*)(void *, s32))(*(void ***)container)[3])(container, i);
            while (item != 0) {
                slot = local.sp40;
                value = ((s32 (*)(void *))(*(void ***)item)[2])(item);
                while (*slot != 0) {
                    if (((s32 (*)(void *, s32))(*(void ***)*slot)[3])(*slot, value) != 0) {
                        ((void (*)(void *, void *, void *, s32 *))(*(void ***)*slot)[4])(
                            *slot, item, (void *)lbl_8055E354, local.sp18);
                        break;
                    }
                    slot++;
                }
                i += 1;
                item = ((void *(*)(void *, s32))(*(void ***)container)[3])(container, i);
            }
            fn_80131818(container);
        }
    }
    fn_80168020();
}
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

void fn_80168104(void) {
    extern void *fn_802C86DC(void);
    extern f64 fn_8002F234(f32);
    extern u32 fn_802C9994(u32);
    extern u32 fn_802C9950(u32);
    extern void fn_802C9900(f32);
    extern void fn_802C9904(void);
    extern void fn_802C744C(void *, void *);
    extern s32 lbl_8055E354;
    extern u8 lbl_8042FF60[];
    extern f32 lbl_8056193C;
    extern f32 lbl_80561940;
    extern f64 lbl_80561948;
    u8 *root = (u8 *)&lbl_8055E354;
    u8 *data = (u8 *)fn_802C86DC();
    f32 x = *(f32 *)(data + 0x24);
    f32 y = *(f32 *)(data + 0x2C);
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)(root + 0x1D4D0)) {
        u8 *entry = (u8 *)*(u32 *)(root + 0x1D4CC) + offset;
        if (entry[4] != 0 && (entry[0x1C] == 0 ||
            (f32)fn_8002F234((y - *(f32 *)(entry + 0xC)) * (y - *(f32 *)(entry + 0xC)) +
             (x - *(f32 *)(entry + 8)) * (x - *(f32 *)(entry + 8))) -
             *(f32 *)(entry + 0x10) < lbl_8056193C)) {
            s32 j = 0;
            while (j < *(s32 *)(entry + 0x18)) {
                u8 *records = (u8 *)*(u32 *)root;
                u8 *record = records + (*(s32 *)(entry + 0x14) + j) * 0x18;
                void *obj = *(void **)record;
                if (obj != 0 && *(s32 *)((u8 *)obj + 0x10) != 0 && record[0x14] == 0) {
                    u32 token = *(u32 *)((u8 *)obj + 8);
                    u32 a = fn_802C9994(token);
                    u32 b = fn_802C9950(((token >> 1) & 0x7F00) | ((token >> 1) & 0x7F) |
                        ((token >> 1) & 0x7F0000) | ((token >> 1) & 0x7F000000));
                    fn_802C9900(((f32)(token >> 24) - (f32)lbl_80561948) / lbl_80561940);
                    {
                        s32 index = ((*(s32 *)record / 12) & 0xF) * 0x30;
                        u8 *out = lbl_8042FF60 + index;
                        *(f32 *)(out + 0x24) = *(f32 *)(record + 4);
                        *(f32 *)(out + 0x28) = *(f32 *)(record + 8);
                        *(f32 *)(out + 0x2C) = *(f32 *)(record + 0xC);
                        fn_802C744C(*(void **)(*(u32 *)record + 0x10), out);
                    }
                    fn_802C9994(a);
                    fn_802C9950(b);
                    fn_802C9904();
                }
                j++;
            }
        }
        offset += 0x20;
        i++;
    }
}

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

extern s32 fn_8002B1D8(s32, s32 *, s32);
extern char lbl_803301B8[];
extern s32 lbl_8055E354;
void fn_801688B4(s32 arg0) {
    s32 i = 0;
    s32 offset = 0;
    u8 *base = (u8 *)(u32)lbl_8055E354 + 0x20000;
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
    s32 j = 0;
    while (i < *(s32 *)(&lbl_8055E354 + 0x1D4D0)) {
        s32 *p = *(s32 **)(&lbl_8055E354 + 0x1D4CC) + j;
        if (arg0 == *p) {
            *(char *)(p + 4) = 0;
        }
        j += 0x20;
        i += 1;
    }
}

s32 fn_80168944(s32 arg0, s32 arg1) {
    s32 addr = (s32)lbl_803301B8;
    s32 len = strlen((char *)addr);
    s32 r = fn_8002B1D8(arg1, (s32 *)addr, len);
    return (u32)__cntlzw(r) >> 5;
}

extern char lbl_80330364[];
s32 fn_80169108(s32 arg0, s32 arg1) {
    s32 addr = (s32)lbl_80330364;
    s32 len = strlen((char *)addr);
    s32 r = fn_8002B1D8(arg1, (s32 *)addr, len);
    return (u32)__cntlzw(r) >> 5;
}

s32 fn_801698B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r0, temp_r0_2, temp_r0_3, var_r3, var_r4, var_r5;
    var_r3 = arg0;
    var_r4 = arg1;
    temp_r0 = arg2 - var_r3;
    if (var_r3 > temp_r0) var_r3 = temp_r0;
    temp_r0_2 = arg3 - var_r4;
    if (var_r4 > temp_r0_2) var_r4 = temp_r0_2;
    var_r5 = var_r3;
    if (var_r4 < var_r3) var_r5 = var_r4;
    if (var_r4 > var_r3) var_r3 = var_r4;
    temp_r0_3 = var_r3 + ((s32)(((u32)var_r5 >> 31) + var_r5) >> 1);
    if (temp_r0_3 >= 3) {
        if (temp_r0_3 >= 5) return 1;
        return 2;
    }
    return 3;
}

s32 fn_80169928(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 a;
    s32 b;

    a = arg3 - arg1;
    if (arg1 > a) {
        a = arg1;
    }
    b = arg2 - arg0;
    if (arg0 > b) {
        b = arg0;
    }
    if (a < b) {
        b = a;
    }
    if (b > 2) {
        return 3;
    }
    return b + 1;
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

