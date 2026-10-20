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
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual f32 getHit(const char *name);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual DummyVec2 getLoc(const char *name);
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
#pragma dont_inline reset

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

