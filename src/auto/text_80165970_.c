#pragma push
#pragma cplusplus on
struct Entry8016707C {
    int unk0;
    unsigned char unk4;
    char pad5[0x17];
    float unk1C;
    float unk20;
    char pad24[0x34];
    void *unk58;
};

struct DummySub8016707C {
    char pad[0x24];
    int unk24;
};

class Dummy8016707C {
public:
    virtual void v0();
    virtual void v1();
    virtual DummySub8016707C *v2();
    virtual void v3();
    virtual void *get();
    virtual void v5(int, int);
    virtual void v6();
    virtual void run(int, int);
};
extern "C" {
    double atof(const char *);
    char *strchr(const char *, int);
    float fn_80204CFC(const char *);
    extern char lbl_8055A170, lbl_8055A178, lbl_8055A180, lbl_8055A188;
    extern float lbl_805618A4, lbl_805618A8, lbl_805618AC, lbl_805618B0, lbl_805618B4;
    extern float lbl_805618B8, lbl_805618BC, lbl_805618C0, lbl_805618C4, lbl_805618C8, lbl_805618CC;
}
class Dummy80165B78 {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual char *getString(const char *);
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual float getFloat(const char *);
    virtual float getFloatDefault(const char *, float);
    virtual void d9();
    virtual unsigned char getFlag(const char *, int);
    virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20();
    virtual Dummy80165B78 *getObject(const char *);
};
class Dummy80165B78D {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual char *getString(const char *);
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual float getFloat(const char *);
    virtual double getFloatDefaultDouble(const char *, float);
    virtual void d9();
    virtual unsigned char getFlag(const char *, int);
    virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20();
    virtual Dummy80165B78D *getObject(const char *);
};
#pragma cplusplus off
#pragma pop
extern float fn_801660C0(void);
extern int *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(int);
extern void fn_80165FAC(void);
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern int fn_80204EA0(const char *);
extern void fn_802E30C8(char *, ...);
extern void fn_80163550(int);
extern void fn_80166754(void *);
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void (*)(void *), void *, int, int);
extern float lbl_8055E324;
extern unsigned char lbl_8055E334;
extern char lbl_8055A190;
extern char lbl_8032FCC0[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma small_data off
__declspec(section ".data") extern float lbl_80558DC4;
#pragma pop
extern void fn_80128668(void *);
extern void fn_80128670(void *);
extern void fn_80139E18();
extern void *memset(void *, int, unsigned int);
extern unsigned char lbl_8055E32C;
extern float lbl_805618F0;
extern float lbl_8055E318;
extern float fn_80129DC4(int, float, float, float);

extern unsigned char lbl_8055E32A;
extern unsigned char lbl_8055E32B;
#pragma push
#pragma small_data off
__declspec(section ".data") extern unsigned char lbl_8042FE38;
extern unsigned char lbl_8042FEB0;
#pragma pop
extern float lbl_8056189C;
extern double lbl_80561890;
extern float lbl_8055E320;
extern float fn_8013672C(int);
extern int fn_80179630(int);
extern int fn_801B2EC0();
extern int fn_80179630(int);
extern int fn_801B2EC0();
extern float fn_8013672C(int);
extern float lbl_8056189C;
extern double lbl_80561890;
extern unsigned char lbl_8042FE38;
__declspec(section ".data") extern unsigned char lbl_8042FEB0;
extern float lbl_8055E320;
#pragma push
#pragma small_data off
void *fn_80165970(void *arg0, int arg1) {
    if (arg0 == 0) goto done;
    if (arg0 == 0) goto after_clear;
    *(int *)arg0 = 0;
    *((int *)arg0 + 1) = 0;
    *((int *)arg0 + 2) = 0;
after_clear:
    if (arg1 > 0) fn_80128668(arg0);
done:
    return arg0;
}

void fn_801659C8(int arg0) {
    fn_80163550(arg0 - 0x56C);
}

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
float fn_801659D0(int arg0) {
    float temp_f31;
    temp_f31 = fn_8013672C(arg0);
    return temp_f31 * ((float)fn_800081F0(arg0) - lbl_80561890);
}
#pragma pop
extern int strcmp(const char *, const char *);
extern float lbl_80561898;
extern float lbl_805618A0;
__declspec(section ".sdata") extern char lbl_8055A150[];
__declspec(section ".sdata") extern char lbl_8055A158[];
#pragma push
#pragma small_data on
__declspec(section ".sdata") extern char lbl_8055A160[];
__declspec(section ".sdata") extern char lbl_8055A168[];
#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80165A30(void *arg0, int arg1) {
    struct List {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual void d20(); virtual void d21();
        virtual void *getAt(int);
    };
    struct Entry {
        virtual const char *getName();
        virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6();
        virtual float getValue(const char *);
    };
    Entry *item;
    int j;
    List *list;
    int count;
    void *entry;
    float x, y, z;
    int minusOne;
    *(int *)((char *)&lbl_8042FEB0 + 4) = 0;
    list = (List *)arg0;
    j = 0;
    minusOne = -1;
    goto next_item;
body:
    if (strcmp(item->getName(), lbl_8055A150) == 0) {
        count = *(int *)((char *)&lbl_8042FEB0 + 4);
        *(int *)((char *)&lbl_8042FEB0 + 4) = count + 1;
        entry = *(void * volatile *)&lbl_8042FEB0;
        entry = (char *)entry + count * 0x14;
        x = item->getValue(lbl_8055A158);
        y = item->getValue(lbl_8055A160);
        *(float *)entry = item->getValue(lbl_8055A168);
        z = x * lbl_80561898;
        *(float *)((char *)entry + 4) = y;
        *(float *)((char *)entry + 8) = z;
        *(int *)((char *)entry + 0x10) = minusOne;
        *(float *)((char *)entry + 0xC) =
            lbl_8055E318 - ((float (*)(int, float, float))fn_80129DC4)(3, lbl_8056189C, lbl_805618A0 * z);
    }
next_item:
    item = (Entry *)list->getAt(++j);
    if (item != 0) goto body;
}
#pragma cplusplus reset
#pragma pop
extern double atof(const char *);
extern char *strchr(const char *, int);
extern float fn_80204CFC(const char *);
extern float lbl_805618A4;
extern float lbl_805618A8;
extern float lbl_805618AC;
extern float lbl_805618B0;
extern float lbl_805618B4;
extern float lbl_805618B8;
extern float lbl_805618BC;
extern float lbl_805618C0;
extern float lbl_805618C4;
extern float lbl_805618C8;
extern float lbl_805618CC;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma small_data on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80165B78(void **arg0) {
    char *strings = lbl_8032FCC0;
    Dummy80165B78 *obj2;
    Dummy80165B78 *obj;
    char *match;
    char *text;
    float scale;
    float value;

    obj = ((Dummy80165B78 *)arg0)->getObject(&lbl_8055A170);
    value = obj->getFloat(strings);
    *(float *)((char *)&lbl_8042FE38 + 0x28) = value;
    value = obj->getFloat(strings + 0x10);
    *(float *)((char *)&lbl_8042FE38 + 0x2c) = value;
    value = obj->getFloatDefault(strings + 0x20, lbl_805618A4);
    *(float *)((char *)&lbl_8042FE38 + 0x3c) = value;
    value = obj->getFloat(strings + 0x30);
    *(float *)((char *)&lbl_8042FE38 + 0x34) = value;
    value = obj->getFloatDefault(strings + 0x3C, lbl_805618A8);
    *(float *)((char *)&lbl_8042FE38 + 0x38) = value;
    value = obj->getFloatDefault(strings + 0x50, *(float *)((char *)&lbl_8042FE38 + 0x2c));
    *(float *)((char *)&lbl_8042FE38 + 0x30) = value;
    value = obj->getFloatDefault(strings + 0x60, lbl_805618AC);
    *(float *)((char *)&lbl_8042FE38 + 0x44) = value;
    value = obj->getFloatDefault(strings + 0x70, lbl_805618AC);
    *(float *)((char *)&lbl_8042FE38 + 0x40) = value;
    value = obj->getFloat(strings + 0x84);
    *(float *)((char *)&lbl_8042FE38 + 0x48) = value;
    value = obj->getFloatDefault(strings + 0x98, lbl_805618B0);
    *(float *)((char *)&lbl_8042FE38 + 0x64) = value;
    value = obj->getFloatDefault(&lbl_8055A178, lbl_805618B0);
    *(float *)((char *)&lbl_8042FE38 + 0x68) = value;
    value = obj->getFloatDefault(strings + 0xA8, lbl_805618B4);
    *(float *)((char *)&lbl_8042FE38 + 0x50) = value;

    text = obj->getString(strings + 0x84);
    match = strchr(text, 0x4C);
    if (match != 0) {
        scale = fn_8013672C((int)match);
        value = (float)atof(text) * scale;
    } else {
        value = (float)atof(text);
    }
    *(float *)((char *)&lbl_8042FE38 + 0x48) = lbl_8055E324 - value;

    *((unsigned char *)&lbl_8042FE38 + 0x4C) =
        obj->getFlag(strings + 0xC0, 1);
    *((unsigned char *)&lbl_8042FE38 + 0x4D) =
        obj->getFlag(strings + 0xD8, 1);
    *((unsigned char *)&lbl_8042FE38 + 0x4E) =
        obj->getFlag(strings + 0xEC, 0);

    obj2 = obj->getObject(strings + 0x100);
    *(float *)((char *)&lbl_8042FE38 + 0x0) = obj2->getFloat(lbl_8055A168);
    *(float *)((char *)&lbl_8042FE38 + 0x8) = obj2->getFloat(&lbl_8055A180);
    *(float *)((char *)&lbl_8042FE38 + 0x4) = obj2->getFloat(lbl_8055A160);
    *(float *)((char *)&lbl_8042FE38 + 0xc) = obj2->getFloat(&lbl_8055A188);
    *(float *)((char *)&lbl_8042FE38 + 0x10) = obj2->getFloat(strings + 0x10C);
    *(float *)((char *)&lbl_8042FE38 + 0x14) = obj2->getFloat(strings + 0x118);
    *(float *)((char *)&lbl_8042FE38 + 0x18) = obj2->getFloatDefault(strings + 0x124, lbl_805618A8);
    *(float *)((char *)&lbl_8042FE38 + 0x1c) = obj2->getFloatDefault(strings + 0x134, lbl_805618B8);
    *(float *)((char *)&lbl_8042FE38 + 0x20) = obj2->getFloatDefault(strings + 0x144, lbl_805618BC);
    *(float *)((char *)&lbl_8042FE38 + 0x24) = obj2->getFloatDefault(strings + 0x154, lbl_805618C0);
    *(float *)((char *)&lbl_8042FE38 + 0x54) = fn_80204CFC(strings + 0x164);
    *(float *)((char *)&lbl_8042FE38 + 0x58) = fn_80204CFC(strings + 0x178);
    *(float *)((char *)&lbl_8042FE38 + 0x5c) = obj->getFloatDefault(strings + 0x194, lbl_805618C4);
    *(float *)((char *)&lbl_8042FE38 + 0x60) = lbl_805618CC * (float)((Dummy80165B78D *)obj)->getFloatDefaultDouble(strings + 0x1A8, lbl_805618C8);
}

#pragma cplusplus on
extern "C" void fn_80165FAC(void) {
    class Obj {
    public:
        virtual void **method(int) = 0;
    };
    Obj *obj;
    int value;
    void **result;
    obj = (Obj *)fn_80131808(lbl_8032FCC0 + 0x1C0);
    value = fn_80204EA0(lbl_8032FCC0 + 0x1CC);
    fn_802E30C8(lbl_8032FCC0 + 0x1D8, value);
    result = obj->method(value);
    ((void (*)(void))fn_80165A30)();
    fn_80165B78(result);
    fn_80131818(obj);
}
#pragma cplusplus reset

#pragma cplusplus off
#pragma scheduling on
#pragma pop
#pragma dont_inline on
void *fn_80166040(int arg0) {
    void *base;
    void *cur;
    void *found;
    int count;
    int i;
    base = *(void **)&lbl_8042FEB0;
    count = *(int *)((char *)&lbl_8042FEB0 + 4);
    cur = base;
    found = 0;
    i = 0;
    while (count > 0) {
        if (*(int *)((char *)cur + 0x10) == -1) {
            found = (char *)base + i * 0x14;
            *(int *)((char *)found + 0x10) = arg0;
            break;
        }
        cur = (char *)cur + 0x14;
        i++;
        count--;
    }
    return found;
}
#pragma dont_inline reset
#pragma pop
void fn_80166098(void) {
    fn_80179630(-1);
    fn_801B2EC0();
}

#pragma cplusplus on
float fn_801660C0(void) {
    void **object;
    int index;
    float factor;
    float value;
    object = ((void **(*)(void))fn_80166098)();
    index = *(int *)((char *)((void *(*)(void *))(*(void ***)object)[4])(object) + 0x10) - 1;
    factor = fn_8013672C(index);
    value = (float)index * factor + *(float *)((char *)((void *(*)(void *))(*(void ***)object)[6])(object) + 0x48);
    if (lbl_8056189C > value) {
        return lbl_8056189C;
    }
    return value;
}
#pragma cplusplus reset

int fn_8016616C(void) {
    return lbl_8055E320 > *(float *)((char *)&lbl_8042FE38 + 0x48);
}

#pragma processor 750
#pragma dont_inline on
float fn_8016618C(void *arg0) {
    float result;
    float a;
    float b;
    int index;
    void *other;
    other = ((void *(*)(void))fn_80166098)();
    a = *(float *)((char *)(*(void *(***)(void *))other)[6](other) + 0x48);
    b = *(float *)((char *)(*(void *(***)(void *))arg0)[6](arg0) + 0x48);
    index = *(int *)((char *)(*(void *(***)(void *))arg0)[4](arg0) + 4);
    if (*(int *)((char *)(*(void *(***)(void *))other)[4](other) + 4) < index) {
        if (a < b) a += ((float (*)(void))fn_8013672C)();
        result = b - a;
    } else {
        if (b < a) b += ((float (*)(void))fn_8013672C)();
        result = b - a;
    }
    return result + *(float *)((char *)&lbl_8042FE38 + 0x58);
}
#pragma dont_inline reset

extern void fn_80128668(void *);
extern void fn_80163550(int);
extern int fn_800081F0(int);
extern int fn_801B2EC0(void);
extern void *fn_8017960C(void);
extern float lbl_805618D0;
extern float lbl_805618D4;
#pragma cplusplus on
extern "C" float fn_80166274(void) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void *get(void);
    };
    Obj *object;
    void *p;
    fn_80179630(-1);
    object = (Obj *)fn_801B2EC0();
    p = object->get();
    fn_80179630(-1);
    {
        void *r3 = fn_8017960C();
        float f0 = *(float *)((char *)*(void **)((char *)p + 4) + 0x20);
        float f1 = *(float *)((char *)r3 + 0x25CC);
        float f2 = lbl_805618D0;
        f2 = (f2 > f0) ? f2 : f0;
        f0 = f1 / f2;
        f1 = lbl_805618D4;
        f1 = (f1 > f0) ? f1 : f0;
        return f1;
    }
}
#pragma cplusplus reset
extern void fn_802E30C8(char *, ...);
extern int lbl_8055E330;
extern signed char lbl_8055E329;
extern unsigned char lbl_8055E328;
extern float lbl_8055E31C;
extern char lbl_8032FEC0[];
extern char lbl_8032FF08[];
#pragma push
void fn_801662FC(void) {
    int flag;
    int count = lbl_8055E330;
    lbl_8055E329 = flag = ((unsigned char)count == 255);
    lbl_8055E330 = count + 1;
    if (flag && lbl_8055E328) {
        if (!((float)__fabs(lbl_8055E31C - lbl_805618D0) <= lbl_80558DC4)) {
            fn_802E30C8(lbl_8032FEC0, lbl_8055E31C, lbl_8055E320, *(float *)((char *)&lbl_8042FE38 + 0x48), fn_80166274());
        } else {
            fn_802E30C8(lbl_8032FF08, lbl_8055E320, *(float *)((char *)&lbl_8042FE38 + 0x48), fn_80166274());
        }
    }
}

#pragma push
#pragma processor gekko
#pragma use_lmw_stmw off
void fn_801663C8(int count, void *records, void *config) {
    typedef struct Entry { int id; unsigned char flag; char pad[0x83]; } Entry;
    typedef struct Holder { Entry *entries; int used; int count; Entry *base; } Holder;
    typedef struct Record { int type; char pad[0x74]; } Record;
    char *strings = lbl_8032FCC0;
    void *obj;
    Holder *holder;
    void *array;
    int i;
    float value;
    lbl_8055E324 = fn_801659D0((int)config);
    fn_80165FAC();
    obj = *(void **)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
    value = (*(float (***)(void *, char *, float))obj)[10](obj, strings + 0x270, *(float *)((char *)&lbl_8042FE38 + 0xC));
    *(float *)((char *)&lbl_8042FE38 + 0xC) = value;
    fn_802E30C8(strings + 0x280, *(float *)((char *)&lbl_8042FE38 + 8), (float)(double)value, *(float *)((char *)&lbl_8042FE38 + 4), *(float *)&lbl_8042FE38);
    holder = fn_801284F8(16, strings + 0x2A0);
    if (holder) {
        array = fn_8002F37C(fn_8012850C(count * 0x88 + 16, &lbl_8055A190), fn_80166754, 0, 0x88, count);
        *(void **)holder = array;
        *(int *)((char *)holder + 8) = count;
        *(int *)((char *)holder + 4) = 0;
        *(void **)((char *)holder + 12) = array;
    }
    *(void **)&lbl_8055E32C = holder;
    *(int *)((char *)holder + 4) = 0;
    for (i = 0; i < count; i++) {
        int type = ((Record *)records)[i].type;
        Holder *h = *(Holder **)&lbl_8055E32C;
        Entry *p = &h->entries[h->used++];
        p->id = i;
        p->flag = type == 0x50;
    }
    lbl_8055E32B = 0;
    lbl_8055E32A = *(int *)((char *)config + 4) != 0x180304;
    *(int *)&lbl_8055E334 = 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_80166754(void *arg0) {
    extern float lbl_805618D8, lbl_805618DC, lbl_805618E0;
    char *base = (char *)&lbl_8042FE38;
    float zero = lbl_8056189C;
    float value44 = lbl_805618D8;
    float arg1 = lbl_805618DC;
    float arg2;
    float result;
    *(float *)((char *)arg0 + 0x18) = *(float *)(base + 0x14);
    arg2 = lbl_805618E0;
    *(float *)((char *)arg0 + 0x0C) = zero;
    *(float *)((char *)arg0 + 0x08) = zero;
    *(float *)((char *)arg0 + 0x14) = zero;
    *(float *)((char *)arg0 + 0x10) = zero;
    *(float *)((char *)arg0 + 0x44) = value44;
    *(float *)((char *)arg0 + 0x38) = zero;
    *(float *)((char *)arg0 + 0x34) = zero;
    *(float *)((char *)arg0 + 0x40) = zero;
    *(float *)((char *)arg0 + 0x3C) = zero;
    result = ((float (*)(int, float, float))fn_80129DC4)(3, arg1, arg2);
    *(float *)((char *)arg0 + 0x4C) = *(float *)(base + 0x3C);
    *(float *)((char *)arg0 + 0x48) = -*(float *)(base + 0x3C);
    *(float *)((char *)arg0 + 0x50) = result * lbl_80561898;
}
#pragma scheduling on
#pragma pop
int fn_801667F0(void) {
    int result = 0;
    if (lbl_8055E32A) {
        if (!lbl_8055E32B) result = 1;
    }
    return result;
}

void fn_80166814(void) {
    int temp_r3;
    void *temp_r31;

    if (*(void **)&lbl_8055E334 != 0) {
        fn_80139E18(*(void **)&lbl_8055E334);
        *(void **)&lbl_8055E334 = 0;
    }
    temp_r31 = *(void **)&lbl_8055E32C;
    if (temp_r31 != 0) {
        temp_r3 = *(int *)((char *)temp_r31 + 0xC);
        if (temp_r3 != 0) {
            fn_80128670((char *)(temp_r3 - 0x10));
        }
        if (temp_r31 != 0) {
            *(int *)((char *)temp_r31 + 0) = 0;
            *(int *)((char *)temp_r31 + 4) = 0;
            *(int *)((char *)temp_r31 + 8) = 0;
        }
        fn_80128668(temp_r31);
    }
    *(void **)&lbl_8055E32C = 0;
}

extern float lbl_805618A0, lbl_805618D0, lbl_805618E4, lbl_805618E8;
extern void *memset(void *, int, unsigned int);
void fn_80166898(void) {
    float zero = lbl_8056189C;
    float height = lbl_805618D0;
    float scale = lbl_805618A0;
    int zeroInt = 0;
    int i = 0;
    int offset = 0;
    lbl_8055E32B = zeroInt;
    lbl_8055E318 = zero;
    lbl_8055E320 = zero;
    lbl_8055E31C = zero;
    while (i < *(int *)(*(unsigned char **)&lbl_8055E32C + 4)) {
        unsigned char *base = *(unsigned char **)&lbl_8055E32C;
        unsigned char *p = base + offset;
        *(float *)(p + 0xC) = height;
        *(float *)(p + 8) = height;
        *(float *)(p + 0x14) = zero;
        *(float *)(p + 0x10) = zero;
        *(float *)(p + 0x1C) = lbl_8055E318 + ((float (*)(int, float, float))fn_80129DC4)(3, lbl_805618E4, lbl_805618E8);
        *(float *)(p + 0x20) = zero;
        *(float *)(p + 0x24) = height;
        *(float *)(p + 0x28) = zero;
        *(float *)(p + 0x38) = zero;
        *(float *)(p + 0x34) = zero;
        *(float *)(p + 0x40) = zero;
        *(float *)(p + 0x3C) = zero;
        *(float *)(p + 0x54) = lbl_8055E318 - ((float (*)(int, float, float))fn_80129DC4)(3, zero, scale * *(float *)(p + 0x50));
        *(int *)(p + 0x58) = zeroInt;
        p[0x5C] = zeroInt; p[0x5E] = zeroInt; p[0x5D] = zeroInt; p[5] = zeroInt; p[0x5F] = zeroInt; p[0x60] = zeroInt; p[0x2C] = zeroInt;
        *(float *)(p + 0x30) = zero;
        memset(p + 0x64, zeroInt, 0x24);
        offset += 0x88;
        i++;
    }
    {
        unsigned char *base = *(unsigned char **)&lbl_8042FEB0;
        int count = *(int *)((unsigned char *)&lbl_8042FEB0 + 4);
        int j = zeroInt;
        offset = zeroInt;
        while (j < count) {
            unsigned char *p = base + offset;
            *(int *)(p + 0x10) = -1;
            *(float *)(p + 0xC) = lbl_8055E318 - ((float (*)(int, float, float))fn_80129DC4)(3, lbl_8056189C, scale * *(float *)(p + 8));
            offset += 0x14;
            j++;
        }
    }
}

extern char lbl_8032FF6C[];
extern float lbl_8055E3C8;
extern float fn_801429D0(float, float);
extern float fn_8014C8B4(float, float, float, float, float);
extern float fn_8014C8F8(float, float);
extern void *fn_80156A40(void);
extern void fn_801662FC(void);
extern float fn_80166DD4(void *);
extern void fn_80166E54(void *);
extern void fn_80166E68(float *, float);
extern void fn_80166F3C(float *);
extern int fn_80166F78(float *);
extern float fn_80166F90(float *);
extern void fn_8016707C(void *, void **);
extern float lbl_8055E3C8, lbl_80561898, lbl_805618D0, lbl_805618E0, lbl_805618EC;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80166A24(void) {
    int wasActive;
    int var_r27;
    int var_r28;
    int var_r29;
    int var_r30;
    unsigned char *temp_r31;
    float time;
    float delta;
    float emptyValue;
    float previous;
    float firstValue;
    float amount;
    float stateValue;
    int active;

    if (!((int (*)(void))fn_801667F0)()) return;

    wasActive = ((int (*)(void))fn_8016616C)();
    lbl_8055E318 = lbl_8055E3C8;
    lbl_8055E31C = lbl_805618D0;
    if (*((unsigned char *)&lbl_8042FE38 + 0x4D) != 0) {
        lbl_8055E31C *= fn_80166274();
    }
    lbl_8055E320 = fn_801660C0();

    if (((int (*)(void))fn_8016616C)() && !wasActive) {
        if (lbl_8055E328 != 0) {
            fn_802E30C8(lbl_8032FF6C);
        }
        for (var_r28 = 0, var_r27 = 0;
             var_r28 < *(int *)((unsigned char *)(*(unsigned char * volatile *)&lbl_8055E32C) + 4);
             var_r27 += 0x88, var_r28++) {
            unsigned char *temp_r25 = *(unsigned char * volatile *)(*(unsigned char * volatile *)&lbl_8055E32C) + var_r27;
            void *object = (void *)((int (*)(int))fn_801B2EC0)(*(int *)temp_r25);
            time = fn_8016618C(object);
            temp_r25[0x2C] = 1;
            *(float *)(temp_r25 + 0x30) = time;
        }
    }

    ((void (*)(void))fn_801662FC)();
    previous = lbl_80561898;
    emptyValue = lbl_805618D0;
    var_r28 = 0;
    var_r27 = (int)&lbl_8042FE38;
    for (var_r29 = 0, var_r30 = 0;
         var_r29 < *(int *)((unsigned char *)(*(unsigned char * volatile *)&lbl_8055E32C) + 4);
         var_r30 += 0x88, var_r29++) {
        temp_r31 = *(unsigned char * volatile *)(*(unsigned char * volatile *)&lbl_8055E32C) + var_r30;
        void *object = (void *)((int (*)(int))fn_801B2EC0)(*(int *)temp_r31);
        fn_8016707C(temp_r31, (void **)object);
        if (*(void **)(temp_r31 + 0x58) != 0) {
            time = fn_8016618C(object);
            *(float *)(temp_r31 + 0x28) = time;
            stateValue = fn_80166F90(*(float **)(temp_r31 + 0x58));
            if (temp_r31[0x2C] != 0) {
                stateValue = *(float *)(temp_r31 + 0x30);
            }
            delta = time - stateValue;

            if (fn_80166F78((float *)(temp_r31 + 0x1C))) {
                firstValue = fn_801429D0(lbl_8056189C, *(float *)(((unsigned char *)var_r27) + 0x10) - previous);
                ((void (*)(float *, float, float))fn_80166F3C)((float *)(temp_r31 + 0x1C), firstValue, previous + *(float *)(((unsigned char *)var_r27) + 0x10));
                amount = fn_8014C8B4(*(float *)&lbl_8042FE38,
                                     *(float *)(((unsigned char *)var_r27) + 4),
                                     *(float *)(((unsigned char *)var_r27) + 0xC),
                                     *(float *)(((unsigned char *)var_r27) + 8), delta);
                active = time > *(float *)(((unsigned char *)var_r27) + 0x18) &&
                         time < *(float *)(((unsigned char *)var_r27) + 0x1C);
                temp_r31[5] = active;
                if (active) {
                    amount = fn_8014C8F8(*(float *)(((unsigned char *)var_r27) + 0x20),
                                         *(float *)(((unsigned char *)var_r27) + 0x24));
                }
                fn_80166E68((float *)(temp_r31 + 8),
                            *(float *)(((unsigned char *)var_r27) + 0x54) +
                            amount * lbl_8055E31C);
            }

            active = 0;
            if (((unsigned char *)var_r27)[0x4C] != 0 &&
                (delta < *(float *)&lbl_8042FE38 ||
                 delta > *(float *)(((unsigned char *)var_r27) + 4))) {
                active = 1;
            }
            if (active) {
                fn_80166E54(*(void **)(temp_r31 + 0x58));
            }

            active = delta > *(float *)(((unsigned char *)var_r27) + 0x2C);
            if (delta > *(float *)(((unsigned char *)var_r27) + 0x28) &&
                fn_80166F78((float *)(temp_r31 + 0x20))) {
                if (active) {
                    ((Dummy8016707C *)fn_80156A40())->v5(*(int *)temp_r31, 1);
                } else {
                    ((Dummy8016707C *)fn_80156A40())->v5(*(int *)temp_r31, 0);
                }
                ((void (*)(float *, float, float))fn_80166F3C)((float *)(temp_r31 + 0x20), lbl_805618EC, lbl_805618E0);
            }

            if (active) {
                fn_80166E68((float *)(temp_r31 + 0x34), lbl_805618D0);
            } else {
                fn_80166E68((float *)(temp_r31 + 0x34), lbl_8056189C);
            }
            *(float *)(temp_r31 + 0x24) = fn_80166DD4(temp_r31 + 8);
            temp_r31[0x5D] = delta > *(float *)(((unsigned char *)var_r27) + 0x34);
            temp_r31[0x5C] = delta > *(float *)(((unsigned char *)var_r27) + 0x30);
            temp_r31[0x5E] = delta < *(float *)(((unsigned char *)var_r27) + 0x38);
            temp_r31[0x5F] = delta < *(float *)(((unsigned char *)var_r27) + 0x40);
            temp_r31[0x60] = delta < *(float *)(((unsigned char *)var_r27) + 0x44);
        } else {
            temp_r31[0x5C] = var_r28;
            temp_r31[0x5E] = var_r28;
            temp_r31[0x5D] = var_r28;
            temp_r31[0x5F] = var_r28;
            temp_r31[0x60] = var_r28;
            *(float *)(temp_r31 + 0x24) = emptyValue;
            memset(temp_r31 + 0x64, var_r28, 0x24);
        }
    }
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
float fn_80166DD4(void *arg0) {
    float y0, y1, t, x0, x1;
    y1 = *(float *)((char *)arg0 + 0xC);
    y0 = *(float *)((char *)arg0 + 8);
    if (fabs(y0 - y1) <= lbl_80558DC4) return *(float *)arg0;
    t = (lbl_8055E318 - y0) / (y1 - y0);
    x1 = *(float *)((char *)arg0 + 4);
    x0 = *(float *)arg0;
    if (t < lbl_805618D0) t = lbl_805618D0;
    if (t > lbl_8056189C) t = lbl_8056189C;
    return x0 + t * (x1 - x0);
}

void fn_80166E54(void *arg0) {
    *(float *)((char *)arg0 + 0xC) += lbl_805618F0;
}

void fn_80166E68(float *arg0, float arg1) {
    float value;
    float factor;
    float start;
    float end;
    if ((float)__fabs(arg1 - arg0[1]) <= lbl_80558DC4) return;
    start = arg0[2];
    end = arg0[3];
    if ((float)__fabs(start - end) <= lbl_80558DC4) {
        value = arg0[0];
    } else {
        float oldValue = arg0[0];
        float oldTarget = ((volatile float *)arg0)[1];
        float ratio = (lbl_8055E318 - start) / (end - start);
        factor = lbl_805618D0;
        factor = factor < ratio ? factor : ratio;
        factor = factor > lbl_8056189C ? factor : lbl_8056189C;
        value = oldValue + factor * (oldTarget - oldValue);
    }
    arg0[1] = arg1;
    arg0[0] = value;
    arg0[2] = lbl_8055E318;
    {
        double target = arg1;
        double current = value;
        arg0[3] = lbl_8055E318 + (float)__fabs((float)current - (float)target) / arg0[4];
    }
}

void fn_80166F3C(float *arg0) {
    *arg0 = lbl_8055E318 + ((float (*)(int))fn_80129DC4)(3);
}

int fn_80166F78(float *arg0) {
    return lbl_8055E318 > *arg0;
}

extern double fn_8002EFB4(float, float, float);
extern float lbl_805618A0, lbl_805618F4, lbl_805618F8, lbl_805618FC;
#pragma push
#pragma optimization_level 2
#pragma scheduling on
float fn_80166F90(float *arg0) {
    register float f3 = lbl_805618A0;
    register float f2 = arg0[2];
    register float f0 = arg0[3];
    register float f1 = lbl_8055E318;
    float x;
    float value;
    float start;
    float end;
    x = (float)fn_8002EFB4(f1 - f0, f3 * f2, f3);
    if (x > arg0[2]) {
        x = lbl_805618A0 * arg0[2] - x;
    }
    x /= arg0[2];
    if (x < lbl_805618F4) {
        value = lbl_805618F4;
    } else {
        if (x > lbl_805618D0) {
            value = lbl_805618D0;
        } else if (x > lbl_8056189C) {
            value = x * (x * (lbl_805618F8 * x)) + x * (lbl_805618FC * x);
        } else {
            value = x * (x * (lbl_805618F8 * x)) - x * (lbl_805618FC * x);
        }
    }
    end = arg0[1];
    start = arg0[0];
    return start + value * (end - start);
}

#pragma push
#pragma cplusplus on
extern int fn_801B8570(void);
extern void *fn_80166040(int);
extern float lbl_805618A0, lbl_805618DC, lbl_805618E0, lbl_805618E4;
#pragma optimization_level 4
extern "C" void fn_8016707C(void *arg0, register void **arg1) {
    void *cur;
    float f1;
    float f2;
    float ret1;
    float res;
    float ret2;

    if (*(unsigned char *)((char *)arg0 + 4) != 0) {
        return;
    }

    fn_80179630(-1);
    if (fn_801B8570() == 0) {
        cur = *(void **)((char *)arg0 + 0x58);
        if (cur != 0) {
            *(int *)((char *)cur + 0x10) = -1;
        }
        *(void **)((char *)arg0 + 0x58) = 0;
        f1 = lbl_805618A0;
        ret1 = ((float (*)(int, float, float))fn_80129DC4)(3, f1, lbl_805618E4);
        f2 = lbl_805618E0;
        res = lbl_8055E318 + ret1;
        f1 = lbl_805618DC;
        *(float *)((char *)arg0 + 0x1C) = res;
        ret2 = ((float (*)(int, float, float))fn_80129DC4)(3, f1, f2);
        *(float *)((char *)arg0 + 0x20) = lbl_8055E318 + ret2;
        return;
    }

    if (*(void **)((char *)arg0 + 0x58) != 0) {
        return;
    }

    if (((Dummy8016707C *)arg1)->v2()->unk24 != 0) {
        return;
    }

    cur = fn_80166040(*(int *)arg0);
    {
        void *old = *(void **)((char *)arg0 + 0x58);
        if (old != 0) {
            *(int *)((char *)old + 0x10) = -1;
        }
    }
    *(void **)((char *)arg0 + 0x58) = cur;
    ret1 = ((float (*)(int, float, float))fn_80129DC4)(3, lbl_805618A0, lbl_805618E4);
    f2 = lbl_805618E0;
    res = lbl_8055E318 + ret1;
    f1 = lbl_805618DC;
    *(float *)((char *)arg0 + 0x1C) = res;
    ret2 = ((float (*)(int, float, float))fn_80129DC4)(3, f1, f2);
    *(float *)((char *)arg0 + 0x20) = lbl_8055E318 + ret2;
}

#pragma pop
unsigned char fn_801671AC(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5C)); }

unsigned char fn_80167544(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5D)); }

unsigned char fn_80167594(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5E)); }

unsigned char fn_801675E4(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5F)); }

unsigned char fn_80167634(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x60)); }

extern float lbl_8055E324;

extern char lbl_8032FF8C[];
extern char lbl_8032FFC4[];
void fn_80167684(float arg0) {
    float temp_f31;
    if (!lbl_8055E32B && arg0 < *(float *)((char *)&lbl_8042FE38 + 0x5C)) {
        temp_f31 = (lbl_8055E324 - fn_801660C0()) / *(float *)((char *)&lbl_8042FE38 + 0x60);
        if (temp_f31 > arg0) {
            fn_802E30C8(lbl_8032FF8C);
            fn_802E30C8(lbl_8032FFC4, arg0, temp_f31);
            lbl_8055E32B = 1;
        }
    }
}

#pragma push
#pragma scheduling invalid_target
int fn_80167728(int arg0) {
    unsigned char **entries = *(unsigned char ***)&lbl_8055E32C;
    int offset = arg0 * 0x88;
    unsigned char *base = *entries;
    return *(float *)(base + offset + 0x28) <
           *(float *)((char *)&lbl_8042FE38 + 0x68);
}
#pragma pop
unsigned char fn_80167758(void) { return *((unsigned char *)&lbl_8042FE38 + 0x4E); }
int fn_80167768(float arg0) { return arg0 > *(float *)((char *)&lbl_8042FE38 + 0x50); }
#pragma pop
extern float lbl_805618EC;
extern float lbl_805618D8;
extern float lbl_805618DC;
extern float lbl_805618E0;
extern float lbl_8055E318;

extern float fn_80129DC4(int, float, float, float);
extern void fn_80128670(void *);
extern void fn_80139E18(void);
extern unsigned char lbl_8055E32C;
extern unsigned char lbl_8055E334;
