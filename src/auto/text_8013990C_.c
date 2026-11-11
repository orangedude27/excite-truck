// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int sprintf(char *, const char *, ...);
extern int fn_802E30C8(const char *, ...);
int fn_80128668();
int fn_80131818();
int fn_80128658(int);
int fn_80139B70(int, float, float);
extern int lbl_8055E138;
extern int lbl_8055E13C;
extern unsigned char lbl_8042F7C0;
extern const char lbl_8032BFD8[];
extern const char lbl_8032C018[];
extern const char lbl_80559C40[];
extern __declspec(section ".sdata") const char lbl_80559C40[];
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma dont_inline on
extern "C" int fn_8013990C(void *arg0) {
    class Object {
    public:
        virtual char *getName(void);
        virtual int f1(void);
        virtual int f2(void);
        virtual int f3(void);
        virtual int check(char *, int);
    };
    char nameBuffer[0x0C];
    int slotIndex = 0;
    int exists;
    Object *namedObject = (Object *)arg0;

    /* Find the first unused numbered slot name on the object by formatting names
       until check() reports no match; warn if very many slots or none found. */
    do {
        sprintf(nameBuffer, lbl_80559C40, slotIndex++);
        exists = namedObject->check(nameBuffer, 0);
    } while (exists != 0 && slotIndex < 0x2710);

    if (slotIndex > 0x400) {
        char *name = namedObject->getName();
        fn_802E30C8(lbl_8032BFD8, 0x400, name, slotIndex);
    }
    if (exists != 0) {
        char *name = namedObject->getName();
        fn_802E30C8(lbl_8032C018, name);
    }
    return slotIndex;
}
#pragma dont_inline reset

extern "C" void *fn_801284E8(void *, int);
extern "C" void fn_801286A0(void *, int);
extern "C" int sscanf(const char *, const char *, ...);
extern "C" __declspec(section ".data") int lbl_8032C108;
extern "C" const char lbl_8032C064[];
extern "C" const char lbl_8032C090[];
extern "C" __declspec(section ".sdata") const char lbl_80559C48[];
extern "C" void *fn_801399FC(void *arg0) {
    class Object {
    public:
        virtual char *getName(void);
        virtual int f1(void);
        virtual int f2(void);
        virtual int f3(void);
        virtual char *check(char *, int);
    };
    char buffer[12];
    int count;
    void *table;
    int *cursor;
    char *entry;
    Object *obj = (Object *)arg0;

    count = fn_8013990C(arg0);
    table = fn_801284E8(&lbl_8032C108, count * 8 + 8);
    *(int *)((char *)table + 4) = count;
    *(int *)table = count;
    cursor = (int *)((char *)table + 8);
    count = 0;
    do {
        sprintf(buffer, lbl_80559C40, count);
        entry = obj->check(buffer, 0);
        if (entry != 0) {
            if (sscanf(entry, lbl_80559C48, cursor, cursor + 1) == 2) {
                cursor += 2;
                count++;
            } else {
                fn_802E30C8(lbl_8032C064, obj->getName(), entry);
            }
        }
    } while (entry != 0);
    if (count < 3) {
        fn_802E30C8(lbl_8032C090, obj->getName(), *(int *)table);
        count = 0;
    }
    fn_801286A0(table, (*(int *)table * 8 + 8) - (count * 8 + 8));
    *(int *)((char *)table + 4) = count;
    *(int *)table = count;
    return table;
}

#pragma cplusplus reset
#pragma scheduling on
void fn_80139B5C(void *arg0, int arg1) {
    volatile float *p = (volatile float *)((char *)arg0 + 0x60);
    float a = p[0];
    float b = p[2];
    fn_80139B70(arg1, a, b);
}

extern float lbl_80561410;
int fn_80139B70(int arg0, float arg1, float arg2) {
    volatile float *p;
    int count;
    int result;
    int i;
    float th;
    float v0;
    float v1;
    float v2;
    float v3;

    count = *(int *)arg0;
    p = (volatile float *)(arg0 + 8);
    result = 0;
    th = lbl_80561410;
    for (i = 0; i < count; p += 2, i++) {
        float y0 = p[1];
        int next = i + 1;
        int index = next % count;
        volatile float *q = (volatile float *)(arg0 + index * 8);
        float y1 = q[3];
        unsigned int rising = y0 < y1;

        if (rising) {
            if (arg2 < y0 || arg2 > y1) continue;
        } else if (arg2 < y1 || arg2 > y0) continue;

        {
            float x0 = p[0];
            float x1 = q[2];
            float v[4];
            float dx = x1 - x0;
            float y0b = p[1];
            float y1b = q[3];
            float tth;
            v[0] = arg1 - x0;
            v[1] = arg2 - y0b;
            v[2] = y1b - y0b;
            v[3] = -dx;
            v0 = v[0];
            v1 = v[1];
            v2 = v[2];
            v3 = v[3];
            tth = th;
            if (rising == (v2 * v0 + v3 * v1 < tth)) result++;
        }
    }
    return result & 1;
}

extern float lbl_80561414;
unsigned long long fn_80139C5C(void *arg0) {
    int count = *(int *)arg0;
    float *point = (float *)((char *)arg0 + 0x10);
    float b0 = *(float *)((char *)arg0 + 8);
    float b1 = *(float *)((char *)arg0 + 12);
    float b2 = b0;
    float b3 = b1;
    int i;
    for (i = 0; i < count - 1; i++) {
        float px = point[0];
        float py = point[1];
        b2 = (px < b2) ? px : b2;
        b3 = (py < b3) ? py : b3;
        b0 = (px > b0) ? px : b0;
        b1 = (py > b1) ? py : b1;
        point += 2;
    }
    {
        union { float f; unsigned int u; } x, y;
        x.f = b2 + lbl_80561414 * (b0 - b2);
        y.f = b3 + lbl_80561414 * (b1 - b3);
        return ((unsigned long long)x.u << 32) | y.u;
    }
}

void *fn_80131810(void);
void *fn_801284F8(int, const char *);
void *fn_801399FC();
extern const char lbl_8032C0C8[];
#pragma scheduling invalid_target
void *fn_80139D4C(void) {
    int count;
    void *object;
    void *source;
    int n;
    void **items;
    void *item;
    const char *name;

    object = 0;
    source = fn_80131810();
    if (source != 0) {
        name = lbl_8032C0C8;
        object = fn_801284F8(0x90, name);
        if (object != 0) {
            *(void **)((char *)object + 4) = (char *)object + 0x10;
            *(int *)((char *)object + 12) = 0x20;
            *(int *)((char *)object + 8) = 0;
            *(void **)object = source;
            count = 0;
            while (count == 0 ||
                   ((int (*)(void *, int))(*(void ***)source)[3])(source, count) != 0) {
                item = fn_801399FC();
                n = *(int *)((char *)object + 8);
                count++;
                items = *(void ***)((char *)object + 4);
                *(int *)((char *)object + 8) = n + 1;
                items[n] = item;
            }
        }
    }
    return object;
}
#pragma scheduling on
void fn_80139E18(void *arg0) {
    int i;
    int offset;
    int value;
    int base;
    if (arg0 == 0)
        return;
    base = (int)arg0;
    i = 0;
    offset = 0;
    while (i < *(int *)((char *)base + 8)) {
        fn_80128658(*(int *)(*(int *)((char *)base + 4) + offset));
        offset += 4;
        i++;
    }
    value = *(int *)base;
    *(int *)((char *)base + 8) = 0;
    if (value != 0)
        fn_80131818();
    *(int *)base = 0;
    if (base + 4 != 0) {
        if (base + 4 != 0) {
            *(int *)((char *)base + 4) = 0;
            *(int *)((char *)base + 8) = 0;
            *(int *)((char *)base + 12) = 0;
        }
    }
    fn_80128668((void *)base);
}
#pragma scheduling on
int fn_80139EC4(void *arg0, float arg1, float arg2) {
    int i = 0;
    int offset = 0;
    while (i < *(int *)((char *)arg0 + 8)) {
        if (fn_80139B70(*(int *)(*(int *)((char *)arg0 + 4) + offset), arg1, arg2) != 0)
            return 1;
        offset += 4;
        i++;
    }
    return 0;
}

extern int fn_80007F90(int);
extern void *__AXGetStudio_8000AC2C(void);
extern int fn_80029004(char *, int);
extern int sprintf(char *, const char *, ...);
extern char *strchr(const char *, int);
extern char *strncpy(char *, const char *, unsigned int);
extern char *strcpy(char *, const char *);
extern const char lbl_80559C50[];
extern const char lbl_80559C58[];
extern const char lbl_8032C0D4[];
extern const char lbl_8032C0E4[];
extern __declspec(section ".sdata") const char lbl_80559C50[];
extern __declspec(section ".sdata") const char lbl_80559C58[];
#pragma cplusplus on
extern "C" void fn_80139F5C(void *arg0) {
    class Source {
    public:
        virtual void unused0();
        virtual void unused1();
        virtual void unused2();
        virtual void unused3();
        virtual char *getPath(const char *, char *);
    };
    char name[0x40];
    char path[0x80];
    int id = fn_80007F90(*(int *)((char *)arg0 + 8));
    char *result;
    int hasSlash;
    sprintf(name, lbl_80559C50, id);
    result = ((Source *)*(void **)((char *)arg0 + 0x20))->getPath(lbl_8032C0D4, name);
    hasSlash = strchr(result, '/') != 0;
    if (hasSlash) {
        strncpy(path, result, 0x80);
    } else {
        sprintf(path, lbl_8032C0E4, __AXGetStudio_8000AC2C(), result);
    }
    lbl_8055E138 = ((int (*)(char *))fn_80131810)(path);
    if (lbl_8055E138 == 0 && !hasSlash) {
        strcpy(((char *(*)(char *, int))fn_80029004)(path, '.'), lbl_80559C58);
        lbl_8055E138 = ((int (*)(char *))fn_80131810)(path + 1);
    }
    strcpy(*(char (*)[1])&lbl_8042F7C0, path);
    lbl_8055E13C = (int)*(void **)((char *)arg0 + 0x20);
}
#pragma cplusplus reset
extern __declspec(section ".data") unsigned char lbl_8042F7C0;
void fn_8013A074(void) {
    int state = lbl_8055E138;
    if (state != 0)
        fn_80131818(state);
    lbl_8055E13C = 0;
    lbl_8042F7C0 = 0;
}

extern int fn_802E30C8(const char *, ...);
extern __declspec(section ".sdata") int lbl_8055E138;
extern __declspec(section ".sdata") int lbl_8055E13C;
extern const char lbl_8032C0F0[];
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int *fn_8013A0B0(int *arg0, int arg1, char *arg2) {
    class Dispatch {
    public:
        virtual int f0(char *);
        virtual int f1(char *);
        virtual int f2(char *);
        virtual int f3(char *);
        virtual int f4(char *);
        virtual int f5(char *);
        virtual int f6(char *);
        virtual int f7(char *);
        virtual int f8(char *);
        virtual int f9(char *);
        virtual int f10(char *);
        virtual int f11(char *);
        virtual int f12(char *);
        virtual int f13(char *);
        virtual int f14(char *);
        virtual int f15(char *);
        virtual int f16(char *);
        virtual int f17(char *);
        virtual int f18(char *);
        virtual int f19(char *);
        virtual int f20(char *);
        virtual int f21(char *);
    };

    *arg0 = 0;
    if (lbl_8055E138 != 0 && *arg2 != 0) {
        if (((Dispatch *)lbl_8055E138)->f2(arg2) != 0) {
            *arg0 = ((Dispatch *)lbl_8055E138)->f0(arg2);
        } else {
            fn_802E30C8(lbl_8032C0F0, arg1, arg2, &lbl_8042F7C0);
        }
    }
    if (*arg0 == 0)
        *arg0 = ((Dispatch *)lbl_8055E13C)->f21(arg2);
    return arg0;
}
#pragma cplusplus reset
#pragma scheduling on
int *fn_8013A198(int *arg0, int arg1) {
    if (arg0 != 0) {
        *arg0 = 0;
        if (arg1 > 0)
            fn_80128668();
    }
    return arg0;
}
typedef struct { int (**vtable)(void *, char *); } Obj;
