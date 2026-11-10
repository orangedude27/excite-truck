// Code of main that had no source file yet: decomp.wtf gave it this one.
extern char lbl_80348CF8[];
extern char lbl_80348D28[];
extern int stricmp(const char *, const char *);
extern int fn_802E317C(const char *, ...);
extern float fn_802C9A4C(float);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern int fn_8028FA1C(int);
extern char lbl_80348FD0[];
extern int fn_8002F768(void *, int, int);
// split_file divides it into the game's real files (file_status shows its range).
typedef struct { float v[7]; unsigned char c[3]; float f0; float f1; } EfEntry;
typedef struct { float x, y, z; } EfVec;
typedef struct { EfVec a; EfVec b; } EfPair;
typedef struct { int mode; char pad4[0x34]; unsigned char en38; char pad39[0x4B]; int v84; unsigned char en88; char pad89[3]; void *buf; int head; int tail; int cap; } EfObj;
typedef struct { EfPair p; float v6; unsigned char c0, c1, c2; float f0; float f1; } EfEntry2;

extern char lbl_803490D4[];
extern int fn_80128668(void *);
extern int lbl_8055C8E0;
extern int lbl_804B35B4[];
extern int fn_801284F8(int, void *);
extern int fn_8028F7AC(void *, void *, int);
extern void fn_8028ED8C(void *, int);
extern void fn_8028F5A0(int, int);
extern float lbl_80564424;
extern void fn_8028FB98(void *, int, float *, float);
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028EE28(void *);
extern void fn_8028ED80(void *);
extern void fn_8028F2EC();
extern int fn_8028F0C0(int *, int, int);
extern void fn_8028F114(int *, int, int);
extern void *memcpy(void *, const void *, unsigned int);
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
extern int lbl_8055F748;
extern int lbl_804B34B0_arr[];
#pragma push
#pragma small_data off
typedef int lbl_804B34B0_t;
#pragma push
#pragma small_data off
void fn_8028DFB0(void) {
    if (*((int *)((char *)&lbl_804B34B0_arr[0] + 0x100)) > 0) {
        fn_8028F2EC();
        lbl_8055F740 = lbl_804B34B0_arr[0];
    }
    lbl_8055F744 = 0;
}
#pragma pop
extern unsigned char lbl_8055F73D;
extern float lbl_80564420;
extern int lbl_8055F748;
void fn_8028DF58(void);
void fn_8028ED74(void *);
void fn_8028EE1C(void *);
void fn_8028F8C4(int);
float fn_801E7E18(void);
void fn_8028DFFC(void) {
    fn_8028DF58();
    lbl_8055F73D = 1;
}

void fn_8028E024(void) {
    if (*((int *)((char *)&lbl_804B34B0_arr[0] + 0x100)) > 0) {
        fn_8028F2EC();
        lbl_8055F740 = lbl_804B34B0_arr[0];
    }
    lbl_8055F744 = 0;
}

void fn_8028E070(float farg0) {
    lbl_8055F738 = farg0;
    lbl_8055F73C = 1;
}

#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_804B34B0;
#pragma push
#pragma small_data off
void fn_8028E080(void) {
    int i;
    int *entries = (int *)&lbl_804B34B0;
    struct Table { int entries[64]; int count; } *base = (struct Table *)&lbl_804B34B0;
    lbl_8055F73C = 0;
    i = 0;
    goto test;
body:
    fn_8028F8E0(*entries, lbl_8055F738);
    entries++;
    i++;
test:
    if (i < base->count) goto body;
}
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8028DF58(void) {
    void *base = (void *)&lbl_804B34B0;
    fn_8028ED74((char *)base + 0x0);
    fn_8028ED74((char *)base + 0x104);
    fn_8028EE1C((char *)base + 0x208);
    lbl_8055F740 = 0;
    lbl_8055F744 = 1;
    lbl_8055F748 = 0;
}
void fn_8028E0F0(void) {
    char* base = (char*)&lbl_804B34B0;
    fn_8028F5A4();
    fn_8028EE28(base + 0x208);
    fn_8028ED80(base + 0x104);
    fn_8028ED80(0 + base);
}
#pragma pop
extern void fn_8028ED74(void *);
extern void fn_8028EE1C(void *);
extern void fn_8028F8C4(int);
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8028E138(void) {
    register int i;
    int *entries = (int *)&lbl_804B34B0;
    struct Table { int entries[64]; int count; } *base = (struct Table *)&lbl_804B34B0;
    lbl_8055F738 = lbl_80564420;
    i = 0;
    goto test;
body:
    fn_8028F8C4(*entries);
    entries++;
    i++;
test:
    if (i < base->count) goto body;
}
#pragma pop
void fn_8028E1A4(void) {
    lbl_8055F738 = fn_801E7E18();
    lbl_8055F73C = 1;
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8028E240(void) {
    float temp_f31;
    int *base;
    int value;
    int *entries;
    int current;
    int i;

    if (lbl_8055F740 == 0) {
        return;
    }
    temp_f31 = fn_802C9A4C(lbl_80564420);
    current = *(int *)((char *)lbl_8055F740 + 0xa4);
    fn_802C8BD0(current);
    entries = &lbl_804B34B0;
    base = entries;
    i = 0;
    goto test;
loop:
    value = *(int *)((char *)*entries + 0xa4);
    if (value != current) {
        fn_802C8D74();
        fn_802C8BD0(value);
        current = value;
    }
    fn_8028FA1C(*entries);
    entries++;
    i++;
test:
    if (i < base[64]) {
        goto loop;
    }
    fn_802C8D74();
    fn_802C9A4C(temp_f31);
}
#pragma pop
int fn_8028E2F8(int arg0, int arg1, int arg2) {
    int result;
    result = fn_801284F8(0xB0, &lbl_8055C8E0);
    if (result != 0) {
        result = ((int (*)(int, int, int))fn_8028F7AC)(result, arg0, arg2);
    }
    fn_8028ED8C(&lbl_804B35B4[0], result);
    fn_8028ED8C(&lbl_804B34B0, result);
    fn_8028F5A0(arg1, result);
    return result;
}

extern float fn_802C9A4C(float);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern int fn_8028FA1C(int);
extern int fn_801284F8(int, void *);
extern int fn_8028F7AC(void *, void *, int);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, int, int, int);
extern int fn_802CAC28(int, int);
extern void fn_8028FD00(void *, void *, int);
extern void fn_8028F854(void);
extern char lbl_80348FC4[];
extern void fn_8028ED8C(void *, int);
extern void fn_8028F5A0(int, int);
extern int lbl_8055C8E0;
extern int lbl_804B35B4[];
extern int fn_8028F858(int, int);
#pragma push
#pragma small_data off
void fn_8028E398(int arg0) {
    if (fn_8028EDA8(&lbl_804B35B4[0], arg0) != 0) {
        fn_8028EDA8((unsigned int *)lbl_804B34B0_arr, arg0);
        fn_8028F858(arg0, 1);
    }
}

#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" int lbl_804B36B8[];
extern "C" int lbl_804B34B0;
extern "C" char lbl_80348D04[];
extern "C" int lbl_8055C8E0;
extern "C" int lbl_8055C8E8;
extern "C" int fn_8028EE34(void *, int, int *);
extern "C" int fn_8028E61C(void *);
extern "C" void *fn_802AE414(const char *);
extern "C" void fn_8028E654(void *, void *);
extern "C" int fn_802E317C(const char *, ...);
extern "C" int fn_801284F8(int, void *);
extern "C" int fn_8028F7AC(void *, void *, int);
extern "C" void fn_8028EEB4(void *, int, const char *);
extern "C" void fn_8028ED8C(void *, int);
extern "C" void fn_8028F5A0(int, int);
extern "C" int fn_8028E3F4(const char *tableName) {
    class TableObject {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual int GetResourceId(const char *name);
    };
    int instance;
    TableObject *tableObject;
    volatile int cachedIndex = -1;
    /* Look up a named table entry in the cache, or load and register a new instance if it is not found. */
    if (fn_8028EE34(lbl_804B36B8, (int)tableName, (int *)&cachedIndex) != 0) {
        char *entry = (char *)&lbl_804B36B8[0] + cachedIndex * 0x18;
        *(int *)(entry + 0x14) += 1;
        return *(int *)(entry + 0x10);
    }
    int loadState[35];
    fn_8028E61C(loadState);
    tableObject = (TableObject *)fn_802AE414(tableName);
    if (tableObject == 0) {
        fn_802E317C(lbl_80348D04, tableName);
    }
    fn_8028E654(loadState, tableObject);
    instance = fn_801284F8(0xB0, &lbl_8055C8E0);
    if (instance != 0) {
        int resourceId = tableObject->GetResourceId((const char *)&lbl_8055C8E8);
        instance = fn_8028F7AC((void *)instance, loadState, resourceId);
    }
    fn_8028EEB4(lbl_804B36B8, instance, tableName);
    fn_8028ED8C(&lbl_804B34B0, instance);
    fn_8028F5A0((int)tableName, instance);
    return instance;
}
#pragma cplusplus off
#pragma pop

extern int fn_8028EF44(void *, unsigned int);
extern int lbl_804B36B8[];
void fn_8028E528(int arg0) {
    if (fn_8028EF44(&lbl_804B36B8[0], arg0) != 0) {
        fn_8028EF44((unsigned int *)lbl_804B34B0_arr, arg0);
        fn_8028F858(arg0, 1);
    }
}

#pragma pop
void fn_8028E584(void *arg0, int arg1, float *arg2) {
    fn_8028FB98(arg0, arg1, arg2, lbl_80564424);
}

extern void fn_8028FAE4(void *, int, float *, float);
void fn_8028E58C(void *arg0, int arg1, float *arg2, float farg0) {
    fn_8028FAE4(arg0, arg1, arg2, farg0);
}

extern void fn_8028FC40(void *, int, float *, float);
void fn_8028E590(void *arg0, int arg1, float *arg2, float farg0) {
    fn_8028FC40(arg0, arg1, arg2, farg0);
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
int fn_8028E594(const char *arg0) {
    char **list;
    int i;

    list = (char **)&lbl_80348CF8;
    i = 0;
    do {
        if (stricmp(arg0, *list) == 0) {
            return i;
        }
        i++;
        list++;
    } while (i < 3);
    fn_802E317C(lbl_80348D28, arg0);
    return 3;
}
#pragma pop
void *memset(void *, int, unsigned int);
#pragma push
#pragma small_data off
int fn_8028E61C(void *arg0) {
    memset(arg0, 0, 0x8Cu);
    return (int)arg0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8028E654(void *arg0, void *arg1) {
    class Obj {
    public:
        virtual void v0();
        virtual int vC(const char *);
        virtual void v10();
        virtual int v14(const char *);
        virtual void v18();
        virtual int v1c(const char *);
        virtual int v20(const char *, int);
        virtual float v24(const char *);
        virtual double v28(const char *, float);
        virtual void v2c();
        virtual int v30(const char *, int);
        virtual void v34();
        virtual void v38(void *, void *, const char *, void *);
    };
    extern int fn_8028E594(void);
    extern char lbl_80348CE0[];
    extern int lbl_8055C8F0, lbl_8055C8F8, lbl_8055C900, lbl_8055C908, lbl_8055C910;
    extern float lbl_80564420, lbl_80564424;

    Obj *obj = (Obj *)arg1;
    char *base = lbl_80348CE0;
    float buf[6];
    float buf2[6];
    float inA[6];
    float inB[6];
    memset(arg0, 0, 0x8C);
    obj->v14((const char *)&lbl_8055C8F0);
    *(int *)arg0 = fn_8028E594();
    *(int *)((unsigned char *)arg0 + 4) = obj->v1c(base + 0x6C);
    *(float *)((unsigned char *)arg0 + 8) = obj->v24(base + 0x7C);
    *(float *)((unsigned char *)arg0 + 12) = obj->v24(base + 0x88);
    {
        double d1 = obj->v28(base + 0x94, lbl_80564420);
        double d2 = obj->v28(base + 0xA8, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x10) = (float)d1;
        *(float *)((unsigned char *)arg0 + 0x14) = (float)d2;
        *(float *)((unsigned char *)arg0 + 0x18) = (float)d1;
    }
    {
        double d1 = obj->v28(base + 0xBC, lbl_80564420);
        double d2 = obj->v28(base + 0xD0, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x1C) = (float)d1;
        *(float *)((unsigned char *)arg0 + 0x20) = (float)d2;
        *(float *)((unsigned char *)arg0 + 0x24) = (float)d1;
    }
    *(float *)((unsigned char *)arg0 + 0x28) = (float)obj->v28(base + 0xE4, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x2C) = (float)obj->v28(base + 0xF4, lbl_80564420);
    *(int *)((unsigned char *)arg0 + 0x44) = obj->v20(base + 0x104, 5);
    *(float *)((unsigned char *)arg0 + 0x48) = (float)obj->v28((const char *)&lbl_8055C8F8, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x30) = (float)obj->v28((const char *)&lbl_8055C900, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x34) = (float)obj->v28((const char *)&lbl_8055C908, lbl_80564420);
    *(unsigned char *)((unsigned char *)arg0 + 0x38) = (unsigned char)obj->v30(base + 0x110, 1);
    *(float *)((unsigned char *)arg0 + 0x4C) = (float)obj->v28(base + 0x120, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x50) = (float)obj->v28(base + 0x134, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x54) = (float)obj->v28(base + 0x140, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x58) = (float)obj->v28(base + 0x150, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x5C) = (float)obj->v28(base + 0x15C, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x78) = (float)obj->v28(base + 0x16C, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x7C) = (float)obj->v28(base + 0x17C, lbl_80564420);
    *(float *)((unsigned char *)arg0 + 0x3C) = (float)obj->v28(base + 0x190, lbl_80564424);
    *(float *)((unsigned char *)arg0 + 0x40) = (float)obj->v28(base + 0x1A0, lbl_80564420);
    if (obj->vC(base + 0x1AC) != 0 || obj->vC(base + 0x1B8) != 0) {
        float v = (float)obj->v28(base + 0x1AC, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x70) = v;
        *(float *)((unsigned char *)arg0 + 0x68) = v;
        *(float *)((unsigned char *)arg0 + 0x60) = v;
        v = (float)obj->v28(base + 0x1B8, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x74) = v;
        *(float *)((unsigned char *)arg0 + 0x6C) = v;
        *(float *)((unsigned char *)arg0 + 0x64) = v;
    } else if (obj->vC(base + 0x1C8) != 0 || obj->vC(base + 0x1D4) != 0) {
        inA[0] = lbl_80564420;
        inA[1] = lbl_80564420;
        inA[2] = lbl_80564420;
        obj->v38(buf, obj, base + 0x1C8, inA);
        inB[0] = lbl_80564420;
        inB[1] = lbl_80564420;
        inB[2] = lbl_80564420;
        obj->v38(buf2, obj, base + 0x1D4, inB);
        *(float *)((unsigned char *)arg0 + 0x60) = buf2[0] - buf[0];
        *(float *)((unsigned char *)arg0 + 0x64) = buf[0];
        *(float *)((unsigned char *)arg0 + 0x68) = buf2[1] - buf[1];
        *(float *)((unsigned char *)arg0 + 0x6C) = buf[1];
        *(float *)((unsigned char *)arg0 + 0x70) = buf2[2] - buf[2];
        *(float *)((unsigned char *)arg0 + 0x74) = buf[2];
    } else {
        *(float *)((unsigned char *)arg0 + 0x60) = (float)obj->v28(base + 0x1E0, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x64) = (float)obj->v28(base + 0x1EC, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x68) = (float)obj->v28(base + 0x1FC, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x6C) = (float)obj->v28(base + 0x208, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x70) = (float)obj->v28(base + 0x218, lbl_80564420);
        *(float *)((unsigned char *)arg0 + 0x74) = (float)obj->v28(base + 0x224, lbl_80564420);
    }
    if (obj->vC(base + 0x234) != 0) {
        inA[0] = lbl_80564420;
        inA[1] = lbl_80564420;
        inA[2] = lbl_80564420;
        obj->v38(buf, obj, base + 0x234, inA);
        *(float *)((unsigned char *)arg0 + 0x60) = lbl_80564420;
        *(float *)((unsigned char *)arg0 + 0x64) = buf[0];
        *(float *)((unsigned char *)arg0 + 0x68) = lbl_80564420;
        *(float *)((unsigned char *)arg0 + 0x6C) = buf[1];
        *(float *)((unsigned char *)arg0 + 0x70) = lbl_80564420;
        *(float *)((unsigned char *)arg0 + 0x74) = buf[2];
    }
    *(float *)((unsigned char *)arg0 + 0x80) = (float)obj->v28(base + 0x244, lbl_80564420);
    *(int *)((unsigned char *)arg0 + 0x84) = obj->v20((const char *)&lbl_8055C910, 1);
    *(unsigned char *)((unsigned char *)arg0 + 0x88) = (unsigned char)obj->v30(base + 0x254, 0);
}
#pragma cplusplus reset
#pragma pop

extern char lbl_80348CF8[];
extern char lbl_80348D28[];
extern int stricmp(const char *, const char *);

void fn_8028ED74(void *arg0) { *(int *)((char *)arg0 + 0x100) = 0; }

void fn_8028ED80(void *arg0) { *(int *)((char *)arg0 + 0x100) = 0; }

void fn_8028ED8C(void *arg0, int arg1) {
    *(int *)((char *)arg0 + (*(int *)((char *)arg0 + 0x100) << 2)) = arg1;
    *(int *)((char *)arg0 + 0x100) = *(int *)((char *)arg0 + 0x100) + 1;
}

extern int fn_802E317C(const char *, ...);
extern char lbl_80348CF8[];
extern char lbl_80348D28[];
extern int stricmp(const char *, const char *);
extern char lbl_80348F4C[];
  #pragma push
  #pragma scheduling invalid_target
  #pragma scheduling on
int fn_8028EDA8(unsigned int *arg0, unsigned int arg1) {
    register unsigned int *base = arg0;
    register long i = 0;
    register int count = *(unsigned int *)((char *)arg0 + 0x100);
    for (; i < count; i++) {
        if (base[i] != arg1)
            continue;
        base[i] = 0;
        return 1;
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
}
#pragma pop
void fn_8028EE1C(void *arg0) {
    *(int *)((char *)arg0 + 0x600) = 0;
}

void fn_8028EE28(void *arg0) {
    *(int *)((char *)arg0 + 0x600) = 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling off
int fn_8028EE34(void *arg0, int arg1, int *arg2) {
    char *p;
    int i;
    p = (char *)arg0;
    i = 0;
    while (i < *(int *)((char *)arg0 + 0x600)) {
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
extern int fn_8002B1D8(int, void *, int);
extern char *strncpy(char *, const char *, unsigned int);
void fn_8028EEB4(void *arg0, int arg1, const char *arg2) {
    int count;
    int *countp;
    char *p;
    char *q;
    count = *(int *)((char *)arg0 + 0x600);
    p = (char *)arg0 + count * 0x18;
    strncpy(p, arg2, 0x10);
    countp = (int *)((char *)arg0 + 0x600);
    q = (char *)arg0 + *countp * 0x18;
    q[0xF] = 0;
    q = (char *)arg0 + *countp * 0x18;
    *(int *)(q + 0x10) = arg1;
    q = (char *)arg0 + *countp * 0x18;
    *(int *)(q + 0x14) = 1;
    (*countp)++;
}

int fn_8028EF44(void *arg0, unsigned int arg1) {
    char *base = (char *)arg0;
    char *p = base;
    int i = 0;
    int count = *(int *)(base + 0x600);
    while (count > 0) {
        if (arg1 == *(unsigned int *)(p + 0x10)) {
            int *q = (int *)(base + i * 0x18 + 0x14);
            *q -= 1;
            return *q == 0;
        }
        p += 0x18;
        i++;
        count--;
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
#pragma dont_inline on
void fn_8028EFC4(int arg0, int *arg1) {
    int *base;
    int *cursor;
    int i;
    int item;
    int n;
    base = arg1;
    cursor = base;
    i = 0;
    goto test;
body:
    item = *cursor;
    n = *(int *)((char *)item + 0x44);
    ((void (*)(void *, int))fn_8028ED8C)((char *)arg0 + (n - 1) * 0x104, item);
    cursor++;
    i++;
test:
    if (i < *(int *)((char *)base + 0x100)) goto body;
}
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
int fn_8028F040(int *arg0, int *arg1, int arg2) {
    int outerCount;
    int outerIndex;
    void *item;
    int innerCount;
    int i;
    int id;
    void **cursor;
    int found;
    int other;
    outerCount = arg0[64];
    for (outerIndex = 0; outerIndex < outerCount; outerIndex++) {
        id = *(int *)((char *)*arg0 + 0xA4);
        if (id != arg2) {
            innerCount = arg1[64];
            cursor = (void **)arg1;
            found = 0;
            i = 0;
            goto inner_check;
inner_body:
            item = *cursor;
            cursor++;
            i++;
            other = *(int *)((char *)item + 0xA4);
            found = (id == other);
inner_check:
            if (found == 0 && i < innerCount) goto inner_body;
            if (found != 0) return id;
        }
        arg0++;
    }
    return -2;
}
#pragma pop
int fn_8028F0C0(int *arg0, int arg1, int arg2) {
    int i;
    int *p;
    i = arg1 + 1;
    p = (int *)((char *)arg0 + i * 0x104);
    for (; i < 9; p = (int *)((char *)p + 0x104), i++) {
        if (*(int *)((char *)p + 0x100) > 0)
            return fn_8028F040((int *)((char *)arg0 + arg1 * 0x104), (int *)((char *)arg0 + i * 0x104), arg2);
    }
    return -2;
}
#pragma pop

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028F114(int *arg0, int arg1, int arg2) {
    void *tmp[64];
    register int n2 = 0;
    register int n3 = 0;
    register int n1 = 0;

    memset(tmp, 0, 0x100);
    if (arg1 != -2) {
        int *src = arg0;
        void **dst = tmp;
        int i = 0;
        goto first_test;
    first_loop:
        {
            void *item = *(void **)src;
            if (*(int *)((char *)item + 0xA4) == arg1) {
                *dst++ = item;
                n1++;
            }
        }
        src++;
        i++;
    first_test:
        if (i < *(int *)((char *)arg0 + 0x100))
            goto first_loop;
    }

    if (arg2 != -2) {
        int *src = arg0;
        int i = 0;
        goto second_test;
    second_loop:
        {
            void *item = *(void **)src;
            if (*(int *)((char *)item + 0xA4) == arg2) {
                tmp[*(int *)((char *)arg0 + 0x100) - n2 - 1] = item;
                n2++;
            }
        }
        src++;
        i++;
    second_test:
        if (i < *(int *)((char *)arg0 + 0x100))
            goto second_loop;
    }

    {
        int *src = arg0;
        int i = 0;
        goto outer_test;
    outer_loop:
        {
            void *item = *(void **)src;
            int id = *(int *)((char *)item + 0xA4);
            if (id != arg1 && id != arg2) {
                int *search = (int *)(tmp + n1);
                int j = 0;
                int equal = 0;
            search_loop:
                {
                    void *q = *(void **)search;
                    search++;
                    j++;
                    equal = (*(int *)((char *)q + 0xA4) == id);
                }
                if (equal != 0)
                    goto search_done;
                if (j < n3)
                    goto search_loop;
            search_done:
                if (equal == 0) {
                    tmp[n1 + n3] = item;
                    n3++;
                    {
                        int k = i + 1;
                        void **dst = tmp + n1 + n3;
                        int *siblings = arg0 + k;
                        goto sibling_test;
                    sibling_loop:
                        if (*(int *)((char *)*(void **)siblings + 0xA4) == id) {
                            *dst++ = *(void **)siblings;
                            n3++;
                        }
                        siblings++;
                        k++;
                    sibling_test:
                        if (k < *(int *)((char *)arg0 + 0x100))
                            goto sibling_loop;
                    }
                }
            }
        }
        src++;
        i++;
    outer_test:
        if (i < *(int *)((char *)arg0 + 0x100))
            goto outer_loop;
    }
    memcpy(arg0, tmp, *(int *)((char *)arg0 + 0x100) * 4);
}
#pragma scheduling on
#pragma use_lmw_stmw on
void fn_8028F2EC(int *arg0) {
    int records[9][65];
    char *p;
    char *end;
    int last;
    int index;
    int i;
    int size;
    int result;
    int *block;

    records[0][64] = 0;
    p = (char *)&records[1][0];
    end = (char *)&records[9][0];
    while (p < end) {
        *(volatile int *)(p + 0x100) = 0;
        p += 0x104;
    }

    fn_8028EFC4((int)records, arg0);
    block = records[0];
    last = -2;
    index = 0;
    i = 0;
    do {
        result = fn_8028F0C0(records[0], i, last);
        fn_8028F114(block, last, result);
        size = block[64];
        memcpy((char *)arg0 + index * 4, block, size * 4);
        i++;
        last = result;
        index += block[64];
        block = (int *)((char *)block + 0x104);
    } while (i < 9);
}
#pragma scheduling on
#pragma pop
extern float fn_80129DC4(int, float, float);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8028F444(float *arg0, float *arg1, float *arg2, float *arg3, float farg0, float farg1) {
    float first = arg2[0];
    float x;
    float y;
    float z;
    x = arg1[0] * arg3[0] + farg1 * fn_80129DC4(0, -first, first);
    arg0[0] = x;
    y = arg1[1] * arg3[1] + farg1 * fn_80129DC4(0, -arg2[1], arg2[1]);
    arg0[1] = y;
    z = arg1[2] * arg3[2] + farg1 * fn_80129DC4(0, -arg2[2], arg2[2]);
    arg0[1] += farg1 * farg0;
    arg0[2] = z;
}
#pragma scheduling on
#pragma pop
extern char lbl_80348F9C[];
#pragma scheduling invalid_target
int fn_8028F534(int arg0) {
    int shift;
    int index;
    index = 0;
    shift = 0;
    for (; index < 4; shift += 2, index++) {
        if (arg0 == (1 << shift)) {
            return 1 << index;
        }
    }
    fn_802E317C(lbl_80348F9C, arg0);
    return 0;
}
#pragma scheduling on
void fn_8028F5A0(int arg0, int arg1) {
}

#pragma pop
void fn_8028F5A4(void) {
}

extern void fn_802916E4(void);
void *__dt__Q34nw4r2ef6EffectFv_8028F5A8(void *arg0, int arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_803490D4;
        fn_802916E4();
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern double fn_8002EFB4(double, double);
extern float lbl_80564424, lbl_80564430, lbl_80564434, lbl_80564438;
extern double lbl_80564428;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8028F608(float *out0, float *out1, float (*matrix)[3], float angle) {
    extern double fn_8002EFB4(double, double);
    extern double lbl_80564428;
    extern float lbl_80564424, lbl_80564430, lbl_80564434, lbl_80564438;
    float d, x, d2, a, b, g, e, c, y, h;
    union { float f; unsigned int u; } bits;
    d = (float)fn_8002EFB4(angle, lbl_80564428) - lbl_80564430;
    bits.f = d;
    if (!(bits.u & 0x80000000)) {
        x = lbl_80564424 - ((lbl_80564434 * d / lbl_80564430 - lbl_80564424) * (lbl_80564434 * d / lbl_80564430 - lbl_80564424));
    } else {
        d = -d;
        x = -(lbl_80564424 - ((lbl_80564434 * d / lbl_80564430 - lbl_80564424) * (lbl_80564434 * d / lbl_80564430 - lbl_80564424)));
    }
    d2 = (float)fn_8002EFB4(lbl_80564438 + angle, lbl_80564428) - lbl_80564430;
    bits.f = d2;
    if (!(bits.u & 0x80000000)) {
        y = lbl_80564424 - ((lbl_80564434 * d2 / lbl_80564430 - lbl_80564424) * (lbl_80564434 * d2 / lbl_80564430 - lbl_80564424));
    } else {
        d2 = -d2;
        y = -(lbl_80564424 - ((lbl_80564434 * d2 / lbl_80564430 - lbl_80564424) * (lbl_80564434 * d2 / lbl_80564430 - lbl_80564424)));
    }
    a=matrix[0][0]; b=matrix[1][0]; c=matrix[0][1]; e=matrix[1][1]; g=matrix[0][2]; h=matrix[1][2];
    out0[0]=y*a+x*b; out0[1]=y*c+x*e; out0[2]=y*g+x*h;
    out1[0]=y*b-x*a; out1[1]=y*e-x*c; out1[2]=y*h-x*g;
}
#pragma scheduling on
#pragma pop
int fn_8028F7AC(void *arg0, void *arg1, int arg2) {
    int count;
    void *self;
    int *params;

    self = arg0;
    params = (int *)arg1;
    ((int (*)(void *))fn_8028E61C)(self);
    ((void (*)(void *, void *))fn_8028FD00)(self, params);
    count = params[1];
    *(void **)((char *)self + 0x8c) =
        fn_8002F37C(fn_8012850C(count * 0x28 + 0x10, lbl_80348FC4),
                    (void *)fn_8028F854, 0, 0x28, count);
    *(int *)((char *)self + 0x98) = count;
    *(void **)((char *)self + 0xa4) = (void *)fn_802CAC28(arg2, 0);
    return (int)self;
}
#pragma pop
void fn_8028F854(void) {}

int fn_8028F858(int arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        fn_802CAC54(*(int *)(arg0 + 0xA4));
        value = *(int *)(arg0 + 0x8C);
        if (value != 0) fn_80128670(value - 0x10);
        if (arg1 > 0) fn_80128668((void *)arg0);
    }
    return arg0;
}

void fn_8028F8C4(int arg0) {
    volatile int *p = (volatile int *)arg0;
    float value = lbl_80564420;
    p[36] = -1;
    p[37] = 0;
    *(volatile float *)((char *)arg0 + 0x9C) = value;
}

extern float lbl_80558DC4;
__declspec(section ".data") extern float lbl_80558DC4;
/* Advances a timed playback cursor (arg0+0x90/0x94/0x98, entries at arg0+0x8C stride 0x28) over entries whose time (entry+0x18) is below (timeNow - startOffset at arg0+8), wrapping/accumulating the phase at arg0+0x9C. */
void fn_8028F8E0(int playbackState, float timeNow) {
    char *p = (char *)playbackState;
    float *phase = (float *)(p + 0x9C);
    float threshold;
    int index, count, count2, i, j;

    if (*phase >= lbl_80564424 - lbl_80558DC4) {
        *phase = *phase - lbl_80564424;
    }
    index = *(int *)(p + 0x90);
    *phase = *phase + *(float *)(p + 0xC);
    if (index < 0) return;

    threshold = timeNow - *(float *)(p + 8);
    count = *(int *)(p + 0x94);
    i = index;
    if (i < count) {
        while (i < count && *(float *)(*(char **)(p + 0x8C) + i * 0x28 + 0x18) < threshold) {
            i++;
        }
        if (i != count) {
            *(int *)(p + 0x90) = i;
            return;
        }
        *(int *)(p + 0x90) = -1;
        *(int *)(p + 0x94) = 0;
        return;
    }

    count2 = *(int *)(p + 0x98);
    while (i < count2 && *(float *)(*(char **)(p + 0x8C) + i * 0x28 + 0x18) < threshold) {
        i++;
    }
    if (i == count2) {
        j = 0;
        while (j < count && *(float *)(*(char **)(p + 0x8C) + j * 0x28 + 0x18) < threshold) {
            j++;
        }
        if (j != count) {
            *(int *)(p + 0x90) = j;
            return;
        }
        *(int *)(p + 0x90) = -1;
        *(int *)(p + 0x94) = 0;
        return;
    }
    *(int *)(p + 0x90) = i;
}

#pragma cplusplus on
#pragma push
#pragma scheduling invalid_target
extern "C" int fn_8028FA1C(int arg0) {
    class ArrayObject {
    public:
        virtual void apply(int entries, int count) = 0;
    };
    typedef void (ArrayObject::*ApplyMethod)(int, int);
    ArrayObject *object;
    int count;
    int index;
    int count2;
    int entries;

    object = (ArrayObject *)arg0;
    index = *(int *)((char *)arg0 + 0x90);
    if (index < 0) goto done;
    count = *(int *)((char *)arg0 + 0x94);
    if (index < count) {
        entries = *(int *)((char *)arg0 + 0x8c) + index * 0x28;
        (object->*(((ApplyMethod *)lbl_80348FD0)[*(int *)arg0]))(entries, count - index);
        goto done;
    }
    count2 = *(int *)((char *)arg0 + 0x98);
    entries = *(int *)((char *)arg0 + 0x8c) + index * 0x28;
    (object->*(((ApplyMethod *)lbl_80348FD0)[*(int *)arg0]))(entries, count2 - index);
    (object->*(((ApplyMethod *)lbl_80348FD0)[*(int *)arg0]))(*(int *)((char *)arg0 + 0x8c), *(int *)((char *)arg0 + 0x94));
done:
    ;
}
#pragma pop
#pragma cplusplus reset
void fn_8028FAE4(void *arg0, int arg1, float *arg2, float farg0) {
    extern void fn_8028FEE4(void *, int, float *, float, float);
    volatile float *threshold = &lbl_80564424;
    float sp8[3];
    int result = 0;

    if (*(float *)((char *)arg0 + 0x9C) >=
            *threshold - lbl_80558DC4 &&
        *(int *)((char *)arg0 + 0x90) != *(int *)((char *)arg0 + 0x94))
        result = 1;
    if (result != 0) {
        fn_8028F444(sp8, arg2,
                    (float *)((char *)arg0 + 0x10),
                    (float *)((char *)arg0 + 0x1C),
                    *(float *)((char *)arg0 + 0x28), lbl_80564424);
        fn_8028FEE4(arg0, arg1, sp8, lbl_80564420, farg0);
    }
}
#pragma scheduling on
#pragma pop

#pragma push
#pragma dont_inline on
void fn_8028FB98(void *arg0, int arg1, float *arg2, float farg0) {
    extern void fn_8028FEE4(void *, int, float *, float, float);
    float sp8[2];
    int result = 0;

    if (*(float *)((char *)arg0 + 0x9C) >=
            lbl_80564424 - lbl_80558DC4 &&
        *(int *)((char *)arg0 + 0x90) != *(int *)((char *)arg0 + 0x94))
        result = 1;
    if (result != 0) {
        fn_8028F444(sp8, arg2,
                    (float *)((char *)arg0 + 0x10),
                    (float *)((char *)arg0 + 0x1C),
                    *(float *)((char *)arg0 + 0x28), farg0);
        fn_8028FEE4(arg0, arg1, sp8, lbl_80564420, lbl_80564424);
    }
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
extern float fn_80287BC8(float, float);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_8028FC40(void *arg0, int arg1, float *arg2, float farg0) {
    extern void fn_8028FEE4(void *, int, float *, float, float);
    float sp8[3];
    float temp_f2;
    int result = 0;
    if (*(float *)((char *)arg0 + 0x9C) >= lbl_80564424 - lbl_80558DC4 &&
        *(int *)((char *)arg0 + 0x90) != *(int *)((char *)arg0 + 0x94)) {
        result = 1;
    }
    if (result != 0) {
        fn_8028F444(sp8, arg2, (float *)((char *)arg0 + 0x10),
                    (float *)((char *)arg0 + 0x1C),
                    *(float *)((char *)arg0 + 0x28), lbl_80564424);
        temp_f2 = *(float *)((char *)arg0 + 0x2C);
        fn_8028FEE4(arg0, arg1, sp8,
                    farg0 + fn_80287BC8(-temp_f2, temp_f2),
                    lbl_80564424);
    }
}
#pragma scheduling on
#pragma pop

#pragma pop
extern int fn_8028F534(int);
extern double lbl_80564440;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028FD00(void *arg0, void *arg1, int arg2) {
    struct Data {
        int f0; int f4; float f8; float fc;
        int f10; int f14; int f18; int f1c; int f20; int f24;
        float f28; float f2c; float f30; float f34;
        unsigned char f38; unsigned char pad39[3];
        float f3c; float f40; int f44; float f48; float f4c;
        float f50; float f54; float f58; float f5c; float f60; float f64;
        float f68; float f6c; float f70; float f74; float f78; float f7c; float f80;
        int f84; unsigned char f88; unsigned char f89; unsigned char pad8a[0x16];
        float a0; int pad_a4; volatile int a8; float ac;
    };
    volatile struct Data *src = (volatile struct Data *)arg1;
    struct Data *dst = (struct Data *)arg0;
    unsigned char f89;
    unsigned char f88;
    int f84;
    float f80;
    float f7c;
    float f78;
    float f74;
    float f70;
    float f6c;
    float f68;
    float f64;
    float f60;
    float f5c;
    float f58;
    float f54;
    float f50;
    float f4c;
    float f48;
    int f44;
    float f40;
    float f3c;
    int f38;
    float f34;
    float f30;
    float f2c;
    float f28;
    int f24;
    int f20;
    int f1c;
    int f18;
    int f14;
    int f10;
    float fc;
    float f8;
    int f4;
    int f0;
    float a0;

    f8 = src->f8;
    dst = (struct Data *)arg0;
    a0 = lbl_80564424;
    f0 = src->f0;
    a0 = a0 / f8;
    f4 = src->f4;
    fc = src->fc;
    f10 = src->f10;
    f14 = src->f14;
    f18 = src->f18;
    f1c = src->f1c;
    f20 = src->f20;
    f24 = src->f24;
    f28 = src->f28;
    f2c = src->f2c;
    f30 = src->f30;
    f34 = src->f34;
    f38 = src->f38;
    f3c = src->f3c;
    f40 = src->f40;
    f44 = src->f44;
    f48 = src->f48;
    f4c = src->f4c;
    f50 = src->f50;
    f54 = src->f54;
    f58 = src->f58;
    f5c = src->f5c;
    f60 = src->f60;
    f64 = src->f64;
    f68 = src->f68;
    f6c = src->f6c;
    f70 = src->f70;
    f74 = src->f74;
    f78 = src->f78;
    f7c = src->f7c;
    f80 = src->f80;
    f84 = src->f84;
    f88 = src->f88;
    f89 = src->f89;
    dst->f0 = f0;
    dst->f4 = f4;
    dst->f8 = f8;
    dst->fc = fc;
    dst->f10 = f10;
    dst->f14 = f14;
    dst->f18 = f18;
    dst->f1c = f1c;
    dst->f20 = f20;
    dst->f24 = f24;
    dst->f28 = f28;
    dst->f2c = f2c;
    dst->f30 = f30;
    dst->f34 = f34;
    dst->f38 = f38;
    dst->f3c = f3c;
    dst->f40 = f40;
    dst->f44 = f44;
    dst->f48 = f48;
    dst->f4c = f4c;
    dst->f50 = f50;
    dst->f54 = f54;
    dst->f58 = f58;
    dst->f5c = f5c;
    dst->f60 = f60;
    dst->f64 = f64;
    dst->f68 = f68;
    dst->f6c = f6c;
    dst->f70 = f70;
    dst->f74 = f74;
    dst->f78 = f78;
    dst->f7c = f7c;
    dst->f80 = f80;
    dst->f84 = f84;
    dst->f88 = f88;
    dst->f89 = f89;
    dst->a0 = a0;
    switch (f0) {
    case 1: {
        int result = fn_8028F534(f84);
        float converted = (float)result;
        dst->a8 = result;
        dst->ac = lbl_80564424 / converted;
        break;
    }
    default:
        break;
    }
    {
        float temp = dst->f34;
        if (temp < lbl_80564424) temp = lbl_80564424;
        if (temp > lbl_80564420) temp = lbl_80564420;
        dst->f34 = temp;
    }
    fn_8028F8C4((int)arg0);
}

extern int fn_80287B5C(int);
extern int fn_802E30C8(void *, const char *, ...);
extern char lbl_8055C918[4];
extern char lbl_80349024[];
extern char lbl_80349078[];
extern unsigned char lbl_8055F74C;
void fn_8028FEE4(void *arg0, int arg1, float *arg2, float farg0, float farg1) {
    EfObj *o = (EfObj *)arg0;
    EfEntry2 *d;
    float *a = (float *)arg1;
    EfEntry2 e;
    int mode;
    int idx;
    if (lbl_8055F73C == 0 && lbl_8055F74C == 0) {
        lbl_8055F74C = 1;
        fn_802E30C8(lbl_8055C918, lbl_80349024);
    }
    mode = o->mode;
    e.p.a.x = a[0];
    e.p.a.y = a[1];
    e.p.a.z = a[2];
    e.p.b.x = arg2[0];
    e.p.b.y = arg2[1];
    e.p.b.z = arg2[2];
    e.v6 = lbl_8055F738;
    e.f1 = farg1;
    switch (mode) {
    case 0:
        e.c0 = o->en38 ? fn_80287B5C(4) : 0;
        break;
    case 1:
        e.c1 = o->en88 ? fn_80287B5C(o->v84) : 0;
        break;
    case 2:
        e.c2 = o->en38 ? fn_80287B5C(0xff) : 0;
        e.f0 = farg0;
        break;
    default:
        fn_802E317C(lbl_80349078);
        break;
    }
    if (o->head < 0) {
        d = (EfEntry2 *)o->buf;
        d->p = e.p;
        d->v6 = e.v6;
        d->c0 = e.c0;
        d->c1 = e.c1;
        d->c2 = e.c2;
        d->f0 = e.f0;
        d->f1 = e.f1;
        o->head = 0;
        o->tail = 1;
        return;
    }
    idx = o->tail;
    d = (EfEntry2 *)o->buf + idx;
    d->p = e.p;
    d->v6 = e.v6;
    d->c0 = e.c0;
    d->c1 = e.c1;
    d->c2 = e.c2;
    d->f0 = e.f0;
    d->f1 = e.f1;
    o->tail = (o->tail + 1) % o->cap;
}

#pragma pop
extern float lbl_80564424, lbl_80564448, lbl_8056444C, lbl_80564450, lbl_80564454, lbl_80564458;
extern float lbl_8056445C;
typedef struct { float x, y, z; unsigned int color; float u, v; } EfVtx;
typedef struct { float m[9]; } EfMtx3;
#pragma push
#pragma scheduling off
void fn_80290160(void *arg0, void *arg1, void *arg2, float farg0) {
    float a, b, c, d, e, f, g, h, i, j, k, l, m, n;
    float o, p, q, r, s, t, u, v, w, x, y, z;
    float aa, ab, ac, ad, ae, af, ag, ah, ai, aj, ak, al, am, an;
    volatile float spillC, spill10, spill8;

    a = *(volatile float *)&lbl_8056444C;
    b = *(volatile float *)((char *)arg0 + 0xa0);
    c = a * farg0;
    d = farg0 * b;
    e = *(volatile float *)&lbl_80564448;
    f = *(volatile float *)((char *)arg0 + 0x34);
    g = *(volatile float *)&lbl_80564454;
    h = g * f;
    i = *(volatile float *)&lbl_80564450;
    j = e * d;
    k = *(volatile float *)&lbl_80564424;
    l = f * d;
    m = h * d;
    n = *(volatile float *)((char *)arg0 + 0x30);
    o = j - i;
    p = *(volatile float *)&lbl_80564458;
    q = j - k;
    r = o * m;
    s = *(volatile float *)((char *)arg2 + 0x10);
    t = q * l;
    u = *(volatile float *)((char *)arg2 + 0xc);
    v = p * n;
    w = k + r;
    x = *(volatile float *)((char *)arg2 + 0x14);
    y = k + t;
    z = *(volatile float *)arg2;
    aa = *(volatile float *)((char *)arg2 + 4);
    ab = c * w;
    ac = *(volatile float *)((char *)arg2 + 8);
    ad = s * y;
    ae = u * y;
    af = x * y;
    ag = v * ab;
    ah = ae * farg0;
    spill8 = ae;
    ai = af * farg0;
    aj = ad - ag;
    ak = z + ah;
    al = ac + ai;
    spill10 = af;
    am = aj * farg0;
    spillC = aj;
    an = aa + am;

    *(float *)arg1 = ak;
    *(float *)((char *)arg1 + 8) = al;
    *(float *)((char *)arg1 + 4) = an;
}

extern void *fn_802C86DC(void);
extern void fn_802C8DB8(void *, int, void *, int);
extern float PSVECDotProduct(float *, float *);
void fn_80290224(void *arg0, void *arg1, int arg2) {
    struct { EfVtx v[32]; short idx[48]; } buf;
    volatile int count;
    int n;
    int i;
    EfVec pos;
    EfVec dsub;
    EfVec dadd;
    EfMtx3 mtx;
    EfVec campos;
    EfVec dir;
    EfVtx q[4];
    char *p;
    float one;
    float t, tm, k, alpha, h, nh;
    int r, g, b, a;

    {
        float *bb = (float *)fn_802C86DC();
        dsub.x = bb[3] - bb[0];
        dsub.y = bb[4] - bb[1];
        dsub.z = bb[5] - bb[2];
        one = lbl_8055F738;
        dadd.x = bb[3] + bb[0];
        dadd.y = bb[4] + bb[1];
        dadd.z = bb[5] + bb[2];
    }
    for (i = 0; i < 8; i++) {
        buf.idx[i * 6 + 0] = i * 4;
        buf.idx[i * 6 + 1] = i * 4 + 1;
        buf.idx[i * 6 + 2] = i * 4 + 2;
        buf.idx[i * 6 + 3] = i * 4;
        buf.idx[i * 6 + 4] = i * 4 + 2;
        buf.idx[i * 6 + 5] = i * 4 + 3;
    }
    count = 0;
    p = (char *)arg1;
    for (n = 0; n < arg2; n++, p += 0x28) {
        float *bb;
        float fa, fb, fc, fd;
        unsigned int col;
        t = one - *(float *)(p + 0x18);
        h = lbl_8056444C * (*(float *)((char *)arg0 + 0x54) + *(float *)((char *)arg0 + 0x50) * t
              + lbl_8056444C * *(float *)((char *)arg0 + 0x4c) * (t * t));
        k = t * *(float *)((char *)arg0 + 0xa0);
        fn_80290160(arg0, &pos, p, t);
        bb = (float *)fn_802C86DC();
        mtx = *(EfMtx3 *)bb;
        campos = *(EfVec *)(bb + 9);
        dir.x = campos.x - pos.x;
        dir.y = campos.y - pos.y;
        dir.z = campos.z - pos.z;
        {
            float c0 = *(float *)((char *)arg0 + 0x3c);
            float c1 = *(float *)((char *)arg0 + 0x40);
            tm = c1 + (PSVECDotProduct((float *)&dir, (float *)&dir) / (lbl_80564424 + c0 * c0)) * (lbl_80564424 - c1);
        }
        if (lbl_80564424 < tm) tm = lbl_80564424;
        if (!(tm > lbl_80564420)) tm = lbl_80564420;
        r = (int)(lbl_8056445C * (*(float *)((char *)arg0 + 0x74) + *(float *)((char *)arg0 + 0x70) * k));
        r = r > 0 ? r : 0; if (r > 255) r = 255;
        g = (int)(lbl_8056445C * (*(float *)((char *)arg0 + 0x6c) + *(float *)((char *)arg0 + 0x68) * k));
        g = g > 0 ? g : 0; if (g > 255) g = 255;
        b = (int)(lbl_8056445C * (*(float *)((char *)arg0 + 0x64) + *(float *)((char *)arg0 + 0x60) * k));
        b = b > 0 ? b : 0; if (b > 255) b = 255;
        alpha = lbl_8056445C * (*(float *)((char *)arg0 + 0x5c) + *(float *)((char *)arg0 + 0x58) * k);
        a = (int)(*(float *)(p + 0x24) * (tm * alpha));
        a = a > 0 ? a : 0; if (a > 255) a = 255;
        col = (a << 24) | ((b & 0xff) << 16) | ((g & 0xff) << 8) | (r & 0xff);
        {
            unsigned char fl = *(unsigned char *)(p + 0x1c);
            int ia = ((fl + 1) & 2) >> 1;
            int ib = (fl >> 1) & 1;
            fa = (float)ia; fb = (float)ib; fc = (float)(1 - ib); fd = (float)(1 - ia);
        }
        nh = -h;
        q[0].x = pos.x + dsub.x * h; q[0].y = pos.y + dsub.y * h; q[0].z = pos.z + dsub.z * h;
        q[1].x = pos.x + dadd.x * h; q[1].y = pos.y + dadd.y * h; q[1].z = pos.z + dadd.z * h;
        q[2].x = pos.x + dsub.x * nh; q[2].y = pos.y + dsub.y * nh; q[2].z = pos.z + dsub.z * nh;
        q[3].x = pos.x + dadd.x * nh; q[3].y = pos.y + dadd.y * nh; q[3].z = pos.z + dadd.z * nh;
        q[0].color = q[1].color = q[2].color = q[3].color = col;
        q[0].u = fa; q[0].v = fb;
        q[1].u = fc; q[1].v = fa;
        q[2].u = fd; q[2].v = fc;
        q[3].u = fb; q[3].v = fd;
        if (count >= 8) {
            fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
            count = 0;
        }
        buf.v[count * 4 + 0] = q[0];
        buf.v[count * 4 + 1] = q[1];
        buf.v[count * 4 + 2] = q[2];
        buf.v[count * 4 + 3] = q[3];
        count++;
    }
    if (count > 0) {
        fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
        count = 0;
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_802908CC(void *arg0, void *arg1, int arg2) {
    typedef struct { EfMtx3 m; EfVec p; } EfCam;
    struct { EfVtx v[32]; short idx[48]; } buf;
    EfVtx q[4];
    EfCam cam;
    EfVec dsub;
    EfVec dadd;
    EfVec pos;
    EfVec dir;
    int n;
    int i;
    char *p;
    float one, half, c1, c0, c255;
    float t, tm, k, alpha, h, nh;
    float u0, u1, v0, v1, cs;
    int r, g, b, a;
    int frames, fr, cols, row, col;
    volatile int count;

    {
        float *bb = (float *)fn_802C86DC();
        dsub.x = bb[3] - bb[0];
        dsub.y = bb[4] - bb[1];
        dsub.z = bb[5] - bb[2];
        one = lbl_8055F738;
        dadd.x = bb[3] + bb[0];
        dadd.y = bb[4] + bb[1];
        dadd.z = bb[5] + bb[2];
    }
    for (i = 0; i < 8; i++) {
        buf.idx[i * 6 + 0] = i * 4;
        buf.idx[i * 6 + 1] = i * 4 + 1;
        buf.idx[i * 6 + 2] = i * 4 + 2;
        buf.idx[i * 6 + 3] = i * 4;
        buf.idx[i * 6 + 4] = i * 4 + 2;
        buf.idx[i * 6 + 5] = i * 4 + 3;
    }
    count = 0;
    half = lbl_8056444C;
    c1 = lbl_80564424;
    c0 = lbl_80564420;
    c255 = lbl_8056445C;
    p = (char *)arg1;
    for (n = 0; n < arg2; n++, p += 0x28) {
        float *bb;
        unsigned int col32;
        frames = *(int *)((char *)arg0 + 0x84);
        t = one - *(float *)(p + 0x18);
        k = t * *(float *)((char *)arg0 + 0xa0);
        h = half * (*(float *)((char *)arg0 + 0x54) + *(float *)((char *)arg0 + 0x50) * t
              + half * *(float *)((char *)arg0 + 0x4c) * (t * t));
        fr = (*(unsigned char *)(p + 0x1d) + (int)(k * ((float)frames * *(float *)((char *)arg0 + 0x80)))) % frames;
        fn_80290160(arg0, &pos, p, t);
        bb = (float *)fn_802C86DC();
        cam = *(EfCam *)bb;
        dir.x = cam.p.x - pos.x;
        dir.y = cam.p.y - pos.y;
        dir.z = cam.p.z - pos.z;
        {
            float f0 = *(float *)((char *)arg0 + 0x3c);
            float f1 = *(float *)((char *)arg0 + 0x40);
            tm = f1 + (PSVECDotProduct((float *)&dir, (float *)&dir) / (c1 + f0 * f0)) * (c1 - f1);
        }
        if (c1 < tm) tm = c1;
        if (!(tm > c0)) tm = c0;
        r = (int)(c255 * (*(float *)((char *)arg0 + 0x74) + *(float *)((char *)arg0 + 0x70) * k));
        r = r > 0 ? r : 0; if (r > 255) r = 255;
        g = (int)(c255 * (*(float *)((char *)arg0 + 0x6c) + *(float *)((char *)arg0 + 0x68) * k));
        g = g > 0 ? g : 0; if (g > 255) g = 255;
        b = (int)(c255 * (*(float *)((char *)arg0 + 0x64) + *(float *)((char *)arg0 + 0x60) * k));
        b = b > 0 ? b : 0; if (b > 255) b = 255;
        alpha = c255 * (*(float *)((char *)arg0 + 0x5c) + *(float *)((char *)arg0 + 0x58) * k);
        a = (int)(*(float *)(p + 0x24) * (tm * alpha));
        a = a > 0 ? a : 0; if (a > 255) a = 255;
        col32 = (a << 24) | ((b & 0xff) << 16) | ((g & 0xff) << 8) | (r & 0xff);
        cols = *(int *)((char *)arg0 + 0xa8);
        row = fr / cols;
        col = fr % cols;
        cs = *(float *)((char *)arg0 + 0xac);
        u0 = (float)col * cs;
        u1 = (float)(col + 1) * cs;
        v0 = (float)row * cs;
        v1 = (float)(row + 1) * cs;
        nh = -h;
        q[0].x = pos.x + dsub.x * h; q[0].y = pos.y + dsub.y * h; q[0].z = pos.z + dsub.z * h;
        q[1].x = pos.x + dadd.x * h; q[1].y = pos.y + dadd.y * h; q[1].z = pos.z + dadd.z * h;
        q[2].x = pos.x + dsub.x * nh; q[2].y = pos.y + dsub.y * nh; q[2].z = pos.z + dsub.z * nh;
        q[3].x = pos.x + dadd.x * nh; q[3].y = pos.y + dadd.y * nh; q[3].z = pos.z + dadd.z * nh;
        q[0].color = q[1].color = q[2].color = q[3].color = col32;
        q[0].u = u0; q[0].v = v0;
        q[1].u = u1; q[1].v = v0;
        q[2].u = u1; q[2].v = v1;
        q[3].u = u0; q[3].v = v1;
        if (count >= 8) {
            fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
            count = 0;
        }
        buf.v[count * 4 + 0] = q[0];
        buf.v[count * 4 + 1] = q[1];
        buf.v[count * 4 + 2] = q[2];
        buf.v[count * 4 + 3] = q[3];
        count++;
    }
    if (count > 0) {
        fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
        count = 0;
    }
}
#pragma pop
extern float lbl_80564460, lbl_80564464, lbl_80564468, lbl_8056446C, lbl_80564470;
extern double lbl_80564478;
void fn_80290FC4(void *arg0, void *arg1, int arg2) {
    struct { EfVtx v[32]; short idx[48]; } buf;
    volatile int count;
    int n;
    int i;
    int j;
    EfVec pos;
    EfVec axA;
    EfVec axB;
    EfMtx3 mtx;
    EfVec campos;
    EfVec dir;
    EfVtx q[4];
    char *p;
    float *cam;
    float one, k0;
    float t, tm, k, alpha, h, nh, ang, inv, m, ts;
    int r, g, b, a;

    cam = (float *)fn_802C86DC();
    k0 = lbl_8056444C * *(float *)((char *)arg0 + 0x48);
    one = lbl_8055F738;
    for (i = 0; i < 8; i++) {
        buf.idx[i * 6 + 0] = i * 4;
        buf.idx[i * 6 + 1] = i * 4 + 1;
        buf.idx[i * 6 + 2] = i * 4 + 2;
        buf.idx[i * 6 + 3] = i * 4;
        buf.idx[i * 6 + 4] = i * 4 + 2;
        buf.idx[i * 6 + 5] = i * 4 + 3;
    }
    count = 0;
    p = (char *)arg1;
    for (n = 0; n < arg2; n++, p += 0x28) {
        float *bb;
        t = one - *(float *)(p + 0x18);
        k = t * *(float *)((char *)arg0 + 0xa0);
        h = lbl_8056444C * (*(float *)((char *)arg0 + 0x54) + *(float *)((char *)arg0 + 0x50) * t
              + lbl_8056444C * *(float *)((char *)arg0 + 0x4c) * (t * t));
        if (!(h > lbl_80564460)) h = lbl_80564460;
        inv = lbl_80564424 / (lbl_80564464 * h);
        ts = *(float *)(p + 0x20) * t;
        ang = lbl_80564468 + (float)fn_8002EFB4(
            lbl_80564468 * (float)*(unsigned char *)(p + 0x1e) * lbl_8056446C
              + ts * (*(float *)((char *)arg0 + 0x7c) + *(float *)((char *)arg0 + 0x78) * k),
            lbl_80564428);
        fn_80290160(arg0, (float *)&pos, p, t);
        fn_8028F608((float *)&axA, (float *)&axB, (float (*)[3])cam, ang);
        bb = (float *)fn_802C86DC();
        mtx = *(EfMtx3 *)bb;
        campos = *(EfVec *)(bb + 9);
        dir.x = campos.x - pos.x;
        dir.y = campos.y - pos.y;
        dir.z = campos.z - pos.z;
        {
            float c0 = *(float *)((char *)arg0 + 0x3c);
            float c1 = *(float *)((char *)arg0 + 0x40);
            tm = c1 + (PSVECDotProduct((float *)&dir, (float *)&dir) / (lbl_80564424 + c0 * c0)) * (lbl_80564424 - c1);
        }
        if (lbl_80564424 < tm) tm = lbl_80564424;
        if (!(tm > lbl_80564420)) tm = lbl_80564420;
        nh = -h;
        q[0].x = pos.x + axA.x * nh + axB.x * h;
        q[0].y = pos.y + axA.y * nh + axB.y * h;
        q[0].z = pos.z + axA.z * nh + axB.z * h;
        q[1].x = q[0].x + axA.x * (lbl_80564434 * h);
        q[1].y = q[0].y + axA.y * (lbl_80564434 * h);
        q[1].z = q[0].z + axA.z * (lbl_80564434 * h);
        q[2].x = q[1].x + axB.x * (lbl_80564470 * h);
        q[2].y = q[1].y + axB.y * (lbl_80564470 * h);
        q[2].z = q[1].z + axB.z * (lbl_80564470 * h);
        q[3].x = q[0].x + axB.x * (lbl_80564470 * h);
        q[3].y = q[0].y + axB.y * (lbl_80564470 * h);
        q[3].z = q[0].z + axB.z * (lbl_80564470 * h);
        q[0].u = lbl_80564420; q[0].v = lbl_80564420;
        q[1].u = lbl_80564424; q[1].v = lbl_80564420;
        q[2].u = lbl_80564424; q[2].v = lbl_80564424;
        q[3].u = lbl_80564420; q[3].v = lbl_80564424;
        for (j = 0; j < 4; j++) {
            m = lbl_8056445C * (one - k0 * (one - inv * (q[j].y - pos.y)));
            a = (int)(*(float *)(p + 0x24) * (tm * (lbl_8056445C * (*(float *)((char *)arg0 + 0x5c) + *(float *)((char *)arg0 + 0x58) * k))));
            a = a > 0 ? a : 0; if (a > 255) a = 255;
            b = (int)(m * (*(float *)((char *)arg0 + 0x64) + *(float *)((char *)arg0 + 0x60) * k));
            b = b > 0 ? b : 0; if (b > 255) b = 255;
            g = (int)(m * (*(float *)((char *)arg0 + 0x6c) + *(float *)((char *)arg0 + 0x68) * k));
            g = g > 0 ? g : 0; if (g > 255) g = 255;
            r = (int)(m * (*(float *)((char *)arg0 + 0x74) + *(float *)((char *)arg0 + 0x70) * k));
            r = r > 0 ? r : 0; if (r > 255) r = 255;
            q[j].color = (a << 24) | ((b & 0xff) << 16) | ((g & 0xff) << 8) | (r & 0xff);
        }
        if (count >= 8) {
            fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
            count = 0;
        }
        buf.v[count * 4 + 0] = q[0];
        buf.v[count * 4 + 1] = q[1];
        buf.v[count * 4 + 2] = q[2];
        buf.v[count * 4 + 3] = q[3];
        count++;
    }
    if (count > 0) {
        fn_802C8DB8(buf.v, count * 4, buf.idx, count * 6);
        count = 0;
    }
}

#pragma pop
extern int fn_80128668(void *);
int fn_8029169C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

int fn_802916DC(void) { return 0; }

void fn_802916E4(void) {}

void fn_802916E8(void) {}

void fn_802916EC(void) {}

int fn_802916F0(void *arg0) { return ((int *)arg0)[1]; }

int fn_802916F8(void *arg0) { return *(int *)((char *)arg0 + 0x118); }

#pragma dont_inline on
void fn_80291700(void) { fn_802916E8(); }
void fn_80291704(void) { fn_802916EC(); }

void fn_80291708(void *arg0) {
    *((unsigned char *)arg0 + 0x11C) = 1;
}

void fn_80291714(void *arg0) {
    *((unsigned char *)arg0 + 0x11C) = 0;
}

unsigned char fn_80291720(void *arg0) {
    return *((unsigned char *)arg0 + 0x11C);
}

#pragma dont_inline reset
extern int lbl_8055F748;
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028F2EC();
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
