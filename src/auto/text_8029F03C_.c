// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

struct Fn8029Pair { float x, y; };
struct Fn8029Vec { float x, y, z; };
extern float lbl_805646B8;
extern float lbl_805646BC;
extern float lbl_805646C0;
extern int strlen(const char *);
__declspec(section ".sdata") extern char lbl_8055CAF0[];
__declspec(section ".sdata") extern char lbl_8055CAF4[];
__declspec(section ".sdata") extern char lbl_8055CAFC[];
__declspec(section ".sdata") extern char lbl_8055CB04[];
__declspec(section ".sdata") extern char lbl_8055CB0C[];
__declspec(section ".sdata") extern char lbl_8055CB14[];
__declspec(section ".sdata") extern char lbl_8055CB18[];
__declspec(section ".sdata") extern char lbl_8055CB1C[];
__declspec(section ".sdata") extern char lbl_8055CB28[];
__declspec(section ".sdata") extern char lbl_8055CB30[];
__declspec(section ".sdata") extern char lbl_8055CB38[];
__declspec(section ".sdata") extern char lbl_8055CB40[];
__declspec(section ".sdata") extern char lbl_8055CB48[];
struct Vec3_8029FB00 { float x, y, z; };
extern void fn_801E9DC4(void *);
extern char lbl_80349890[];
__declspec(section ".sdata") extern char lbl_8055CB50[];
__declspec(section ".sdata") extern char lbl_8055CB58[];
__declspec(section ".sdata") extern char lbl_8055CB5C[];
extern int strcmp(const char *, const char *);
extern int fn_8029FE6C(const char *);
typedef struct Unk802A0794Params {
    float values[6];
    short unk_0x18;
    int unk_0x1C;
} Unk802A0794Params;
extern void fn_802A0794(void *);
extern void fn_802A042C(void *, Unk802A0794Params *);
extern void fn_802A01C8(void *, Unk802A0794Params *);
extern void fn_802A02F4(void *, Unk802A0794Params *);
extern void fn_802E30C8(const char *, ...);
extern char lbl_803498AC[];
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern void fn_8029FB00(void *);
extern char lbl_8034989C[];
__declspec(section ".sdata") extern char lbl_8055CB60[];
extern unsigned char lbl_804B5070[];
extern int lbl_8055F81C;
extern unsigned char lbl_804B6E70[];
extern int fn_800241DC(int *, void *, int, int, void *);
extern int stricmp(const char *, const char *);
  extern int fn_8029FDF0(int *, int *);
  extern void fn_8028E528(void);
  extern void fn_80292B48(void);
  extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));

extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern int fn_8028E3F4(void);
extern int fn_802929F8(void);
extern int fn_8029F3BC(unsigned char *);
extern char lbl_8034983C[];
extern char lbl_80349848[];
extern int lbl_804B9B7C[];
extern float lbl_805646B4;
extern int lbl_8055CAE8;
extern int lbl_8055F820;
extern int fn_80128670(void);
extern int fn_801EF024(void *);
extern void fn_8029FDDC(void);
extern void fn_8029FFBC(void);
extern int fn_802A0720(int *, int);
extern int fn_802A0620(Unk802A0794Params *);
extern void fn_802A002C(void);
extern int fn_801E85A4(void);
extern void fn_8029FEF8(void);
extern void fn_8029FE00(void);
extern void fn_8029FD04(void);
extern int fn_801E85AC(void);
extern int fn_8012850C(int, void *);
extern int fn_801EEFDC(void *, int);
extern char lbl_80349810[];
extern unsigned char lbl_804B7770[];
extern int lbl_8055F818;
extern void *memset(void *, int, unsigned int);
extern void fn_802029FC(void);
extern void fn_802C92D0(void);
extern void fn_802C92D8(void);
extern void fn_801E88B4(int *, int *, int *, int *, int);
extern void fn_802C92DC(int, int, int, int, int);
extern float lbl_805646B0;
extern int lbl_8055F824;
extern unsigned char lbl_8055F73C;
extern char lbl_8034981C[];
extern int fn_801769F8(void);
void fn_8029F03C(void) {
    lbl_8055F81C = 0;
    lbl_8055F818 = 0;
    memset(lbl_804B7770, 0, 0x2400);
    memset(lbl_804B6E70, 0, 0x900);
    fn_8029FEF8();
    fn_8029FE00();
    fn_8029FD04();
    fn_801EEFDC(&fn_802A0620, 10);
    fn_801EEFDC(&fn_802A0720, 11);
    lbl_8055F820 = fn_8012850C(fn_801E85AC() * 4, &lbl_80349810);
}

void fn_8029F0D0(void) {
    if (lbl_8055F820) {
        ((int (*)(int))fn_80128670)(lbl_8055F820);
    }
    lbl_8055F820 = 0;
    fn_801EF024((void *)fn_802A0720);
    fn_801EF024((void *)fn_802A0620);
    fn_8029FDDC();
    fn_8029FFBC();
}

#pragma push
#pragma scheduling invalid_target
void fn_8029F124(void) {
    int zero;
    int offset;
    int i;
    fn_802A002C();
    i = 0;
    offset = 0;
    zero = 0;
    while (i < fn_801E85A4()) {
        i++;
        *(int *)((char *)lbl_8055F820 + offset) = zero;
        offset += 4;
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8029F188(void) {
    unsigned char *entry;
    float scale;
    void *table;
    int offset;
    int i;

    if (lbl_8055F73C != 1) {
        if (lbl_8055F824 == 0) {
            fn_802E30C8(lbl_8034981C);
        }
        lbl_8055F824 = (lbl_8055F824 + 1) % 5;
    }
    scale = lbl_805646B0;
    table = lbl_804B9B7C;
    i = 0;
    offset = 0;
    for (; i < *(int *)((char *)table + 4); offset += 0x34, i++) {
        unsigned char *object;
        entry = *(unsigned char **)lbl_804B9B7C + offset;
        object = *(unsigned char **)(entry + 0x30);
        if (object != 0) {
            float dx = *(float *)(object + 0x60) - *(float *)(entry + 4);
            float dy;
            float dz;
            *(float *)(entry + 0x10) = dx;
            dy = *(float *)(object + 0x64) - *(float *)(entry + 8);
            *(float *)(entry + 0x14) = dy;
            dz = *(float *)(object + 0x68) - *(float *)(entry + 0xc);
            *(float *)(entry + 0x10) = dx * scale + *(float *)(entry + 0x1c);
            *(float *)(entry + 0x14) = dy * scale + *(float *)(entry + 0x20);
            *(float *)(entry + 0x18) = dz * scale + *(float *)(entry + 0x24);
            *(float *)(entry + 4) = *(float *)(object + 0x60);
            *(float *)(entry + 8) = *(float *)(object + 0x64);
            *(float *)(entry + 0xc) = *(float *)(object + 0x68);
        } else {
            *(float *)(entry + 0x10) = *(float *)(entry + 0x1c);
            *(float *)(entry + 0x14) = *(float *)(entry + 0x20);
            *(float *)(entry + 0x18) = *(float *)(entry + 0x24);
        }
        if (entry[0x2E] != 0 && fn_801769F8() == 0) {
            fn_802A0794(entry);
        }
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_8029F300(void) {
    int offset, i, zero;
    int a, b, c, d;
    fn_802029FC();
    i = 0;
    offset = 0;
    zero = 0;
    goto check;
loop:
    if (fn_801E85A4() == 1) {
        fn_802C92D0();
        if (((unsigned int)*(int *)((char *)lbl_8055F820 + offset) >> 24) != 0) {
            fn_801E88B4(&a, &b, &c, &d, i);
            fn_802C92DC(a, b, c, d, *(int *)((char *)lbl_8055F820 + offset));
        }
        fn_802C92D8();
    }
    i++;
    *(int *)((char *)lbl_8055F820 + offset) = zero;
    offset += 4;
check:
    if (i < fn_801E85A4()) goto loop;
}
#pragma scheduling on
#pragma pop

#pragma push
#pragma scheduling invalid_target
int fn_8029F3BC(unsigned char *arg0) {
    unsigned char *current = lbl_804B7770;
    int i = 0;
    while (i < lbl_804B9B7C[1]) {
        if (stricmp((const char *)current, (const char *)arg0) == 0)
            return *(int *)(lbl_804B7770 + i * 0x24 + 0x20);
        current += 0x24;
        i++;
    }
    return -1;
}
#pragma scheduling on
#pragma pop

#pragma scheduling invalid_target
#pragma dont_inline on
void fn_8029F458(unsigned char *arg0, int arg1) {
    unsigned char buf[0x20];
    signed char first;
    unsigned char c;
    int remaining;
    unsigned char *dst;
    int id;
    int *table;
    int i;
    int offset;
    if ((first = *(volatile signed char *)arg0) == '$')
        arg0++;
    dst = buf;
    remaining = 0x20;
    goto copy;
decrement:
    remaining--;
    if (remaining > 0)
        goto copy;
    dst[-1] = 0;
    goto lookup;
copy:
    c = *arg0++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto decrement;
lookup:
    id = fn_8029F3BC(buf);
    table = lbl_804B9B7C;
    i = 0;
    offset = 0;
    goto check;
loop:
    {
        int address = *(volatile int *)&lbl_804B9B7C[0] + offset;
        if (*(int *)address == id)
            *(int *)(address + 0x30) = arg1;
    }
    offset += 0x34;
    i++;
check:
    if (i < ((volatile int *)table)[1])
        goto loop;
}
#pragma dont_inline reset
#pragma scheduling on
unsigned char fn_8029F510(unsigned char *arg0, int arg1) {
    if (arg1 != 0) {
        *arg0 = 1;
    } else {
        *arg0 = 0;
    }
    return *arg0;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma optimization_level 2
extern "C" void fn_8029F534(void *arg0, unsigned char *arg1) {
    class Obj {
    public:
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void set(const char *) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual unsigned char getBool(const char *, int) = 0;
    };
    Obj *obj = (Obj *)arg1;
    if (((int (*)(unsigned char *, int))fn_8029F510)((unsigned char *)arg0, (int)arg1) != 0) {
        obj->set((const char *)&lbl_8034983C);
        *(int *)((char *)arg0 + 4) = fn_8028E3F4();
        *(unsigned char *)((char *)arg0 + 8) = obj->getBool((const char *)&lbl_80349848, 0);
    } else {
        *(int *)((char *)arg0 + 4) = 0;
    }
}
#pragma scheduling on
#pragma cplusplus off
#pragma pop


#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma optimization_level 2
extern "C" void fn_8029F5C8(void *arg0, unsigned char *arg1) {
    class Obj {
    public:
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void set(const char *) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual float getFloat(float, const char *) = 0;
    };
    Obj *obj = (Obj *)arg1;
    if (((int (*)(unsigned char *, int))fn_8029F510)((unsigned char *)arg0, (int)arg1) != 0) {
        obj->set((const char *)&lbl_8034983C);
        *(int *)((char *)arg0 + 4) = fn_802929F8();
        {
            float scalar = *(volatile float *)&lbl_805646B4;
            *(float *)((char *)arg0 + 8) = obj->getFloat(scalar, (const char *)&lbl_8055CAE8);
        }
    } else {
        *(int *)((char *)arg0 + 4) = 0;
    }
}

#pragma push
#pragma cplusplus on
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_8029F658(void *arg0) {
    class Obj {
    public:
        virtual const char *name();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual int getId(const char *);
        virtual int getProp(const char *, int, int);
        virtual void v7();
        virtual float getFloat(float, const char *);
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual Fn8029Vec getVec(const char *, Fn8029Vec);
        virtual void v13();
        virtual Fn8029Pair getPair(const char *, Fn8029Pair);
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual int getSub(const char *);
    };
    char *table;
    unsigned char *record;
    Obj *obj;
    Fn8029Vec defaultVec;
    Fn8029Vec defaultVec2;
    Fn8029Vec v1;
    Fn8029Vec v2;
    Fn8029Vec v3;
    Fn8029Pair pairDefault;
    Fn8029Pair out1;
    Fn8029Pair out2;
    Fn8029Pair out3;
    Fn8029Pair out4;
    Fn8029Pair out5;
    const char *str;
    unsigned char *dst;
    char *src;
    int n;
    unsigned char c;
    int packed;
    int rPart;
    int gPart;
    int bPart;

    table = lbl_80349810;
    record = lbl_804B5070 + lbl_8055F81C * 0x78;
    obj = (Obj *)arg0;
    defaultVec.x = lbl_805646B4;
    defaultVec.y = lbl_805646B4;
    defaultVec.z = lbl_805646B4;
    pairDefault.x = lbl_805646B4;
    pairDefault.y = lbl_805646B4;
    *(int *)record = obj->getId(lbl_8055CAF0);
    str = obj->name();
    src = (char *)str + strlen(&table[0x44]);
    if (*src == '_')
        src++;
    dst = lbl_804B6E70 + lbl_8055F81C * 0x24;
    *(int *)(dst + 0x20) = *(int *)record;
    n = 0x20;
    goto copy_start;
dec:
    n--;
    if (n > 0) goto copy;
    dst[-1] = 0;
    goto done;
copy_start:
copy:
    c = *(unsigned char *)src++;
    *dst++ = c;
    if ((signed char)c != 0) goto dec;
done:
    *(float *)(record + 4) = obj->getFloat(lbl_805646B4, &table[0x50]);
    *(float *)(record + 8) = obj->getFloat(lbl_805646B4, lbl_8055CAF4);
    *(float *)(record + 0xC) = obj->getFloat(lbl_805646B4, lbl_8055CAFC);
    out1 = obj->getPair(lbl_8055CB04, pairDefault);
    *(float *)(record + 0x10) = out1.x;
    *(float *)(record + 0x14) = out1.y;
    out2 = obj->getPair(lbl_8055CB0C, pairDefault);
    *(float *)(record + 0x18) = out2.x;
    *(float *)(record + 0x1C) = out2.y;
    out3 = obj->getPair(lbl_8055CB14, pairDefault);
    *(float *)(record + 0x20) = out3.x;
    *(float *)(record + 0x24) = out3.y;
    out4 = obj->getPair(lbl_8055CB18, pairDefault);
    *(float *)(record + 0x28) = out4.x;
    *(float *)(record + 0x2C) = out4.y;
    v1 = obj->getVec(lbl_8055CB1C, defaultVec);
    *(float *)(record + 0x30) = v1.x;
    *(float *)(record + 0x34) = v1.y;
    *(float *)(record + 0x38) = v1.z;
    out5 = obj->getPair(lbl_8055CB28, pairDefault);
    *(float *)(record + 0x3C) = out5.x;
    *(float *)(record + 0x40) = out5.y;
    *(float *)(record + 0x44) = obj->getFloat(lbl_805646B8, lbl_8055CB30);
    *(float *)(record + 0x48) = obj->getFloat(lbl_805646B4, &table[0x5C]);
    defaultVec2.x = lbl_805646BC;
    defaultVec2.y = lbl_805646BC;
    defaultVec2.z = lbl_805646BC;
    v2 = obj->getVec(&table[0x68], defaultVec2);
    rPart = (int)(lbl_805646C0 * v2.x);
    gPart = (int)(lbl_805646C0 * v2.y);
    bPart = (int)(lbl_805646C0 * v2.z);
    packed = (rPart << 16) | (gPart << 8) | bPart;
    packed |= 0xFF000000;
    *(int *)(record + 0x4C) = packed;
    *(int *)(record + 0x50) = obj->getProp(lbl_8055CB38, 1, packed);
    v3 = obj->getVec(lbl_8055CB40, defaultVec);
    *(float *)(record + 0x54) = v3.x;
    *(float *)(record + 0x58) = v3.y;
    *(float *)(record + 0x5C) = v3.z;
    fn_8029F534(record + 0x60, (unsigned char *)(long)obj->getSub(&table[0x74]));
    fn_8029F5C8(record + 0x6C, (unsigned char *)(long)obj->getSub(lbl_8055CB48));
    lbl_8055F81C++;
}
#pragma dont_inline reset
#pragma cplusplus off
#pragma pop

#pragma cplusplus on
extern "C" void fn_8029FB00(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual const char *name(const char *);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual unsigned char getBool(const char *, int);
        virtual Vec3_8029FB00 getVec(const char *);
    };
    Vec3_8029FB00 v, w;
    unsigned char *entry;
    char *a;
    char *b;
    int found;
    int i;
    int *t;
    Obj *obj = (Obj *)arg0;
    found = lbl_8055F818;
    a = (char *)lbl_804B7770;
    t = lbl_804B9B7C;
    entry = *(unsigned char **)t + t[1]++ * 0x34;
    b = a;
    for (i = 0; i < lbl_8055F818; i++) {
        if (strcmp(a, obj->name(lbl_8055CB50)) == 0)
            found = *(int *)(b + 0x20);
        a += 0x24;
        b += 0x24;
    }
    *(int *)entry = found;
    *(unsigned char *)(entry + 0x2e) = obj->getBool(lbl_80349890, 0);
    *(int *)(entry + 0x28) = fn_8029FE6C(obj->name(lbl_8034983C));
    v = obj->getVec(lbl_8055CB58);
    *(float *)(entry + 4) = v.x;
    *(float *)(entry + 8) = v.y;
    *(float *)(entry + 0xc) = v.z;
    w = obj->getVec(lbl_8055CB5C);
    {
        float z, y, x;
        x = w.x;
        *(float *)(entry + 0x1c) = x;
        y = w.y;
        *(float *)(entry + 0x20) = y;
        z = w.z;
        *(float *)(entry + 0x24) = z;
        *(int *)(entry + 0x30) = 0;
        *(float *)(entry + 0x10) = x;
        *(float *)(entry + 0x14) = y;
        *(float *)(entry + 0x18) = z;
    }
    fn_801E9DC4(entry + 0x2c);
    if (found == lbl_8055F818) {
        const char *s;
        int n;
        char *d;
        unsigned char c;
        *(int *)(lbl_804B7770 + lbl_8055F818 * 0x24 + 0x20) = found;
        s = obj->name(lbl_8055CB50);
        d = (char *)lbl_804B7770 + lbl_8055F818 * 0x24;
        n = 0x20;
        goto copy;
    dec:
        n--;
        if (n > 0) goto copy;
        d[-1] = 0;
        goto done;
    copy:
        c = *s++;
        *d++ = c;
        if ((signed char)c != 0) goto dec;
    done:
        lbl_8055F818++;
    }
}
#pragma cplusplus off

#pragma scheduling on
#pragma cplusplus off
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8029FD04(void) {
    class Object {
    public:
        virtual const char *name();
        virtual Object *child(int);
    };
    Object *object;
    int i;
    Object *child;
    lbl_804B9B7C[1] = 0;
    object = (Object *)fn_80131810(lbl_8034989C);
    if (object != 0) {
        i = 0;
        child = object->child(i++);
        while (child != 0) {
            if (stricmp(child->name(), lbl_8055CB60) == 0)
                fn_8029FB00(child);
            child = object->child(i++);
        }
        fn_80131818(object);
    }
}
#pragma cplusplus off
#pragma scheduling invalid_target
void fn_8029FDDC(void) {
    lbl_804B9B7C[1] = 0;
}
#pragma scheduling on

#pragma pop

int fn_8029FDF0(int *arg0, int *arg1) {
    return *arg0 - *arg1;
}

void fn_8029FE00(void) {
    int count;
    int (*compare)(const void *, const void *);
    count = lbl_8055F81C;
    compare = (int (*)(const void *, const void *))fn_8029FDF0;
    qsort(lbl_804B5070, count, 0x78, compare);
}

#pragma push
#pragma dont_inline on
int fn_8029FE1C(int arg0) {
    int sp8 = arg0;
    if (arg0 <= 0)
        return 0;
    return fn_800241DC(&sp8, lbl_804B5070, lbl_8055F81C, 0x78, fn_8029FDF0);
}

#pragma pop
int fn_8029FE6C(const char *arg0) {
    unsigned char *current = lbl_804B6E70;
    int i = 0;
    goto check;
loop:
    if (stricmp((const char *)current, arg0) == 0)
        return *(int *)(lbl_804B6E70 + i * 0x24 + 0x20);
    current += 0x24;
    i++;
check:
    if (i < lbl_8055F81C) goto loop;
    return -1;
}

  extern void *fn_802AE4C8(int);
  extern void fn_8029F658(void *);
  extern char lbl_80349854[];
  extern int strncmp(const char *, const char *, unsigned int);
  #pragma cplusplus on
      class Dummy_8029FEF8 {
  public:
      virtual const char *d0();
      virtual void *f1(int);
  };
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_8029FEF8(void) {
    Dummy_8029FEF8 *object;
    int i = 0;
    int j;
    Dummy_8029FEF8 *child;
    while ((object = (Dummy_8029FEF8 *)fn_802AE4C8(i)) != 0) {
        j = 0;
        while (object->f1(j) != 0) {
            child = (Dummy_8029FEF8 *)object->f1(j);
            if (strncmp(child->d0(), lbl_80349854, 9) == 0)
                fn_8029F658(child);
            j++;
        }
        i++;
    }
}
#pragma cplusplus off
#pragma pop
void fn_8029FFBC(void) {
    unsigned char *current = lbl_804B5070;
    int i = 0;
    int temp;
    goto check;
loop:
    temp = *(int *)(current + 0x64);
    if (temp != 0) ((void (*)(int))fn_8028E528)(temp);
    temp = *(int *)(current + 0x70);
    if (temp != 0) ((void (*)(void *))fn_80292B48)((void *)temp);
    current += 0x78;
    i++;
check:
    if (i < lbl_8055F81C) goto loop;
}

#pragma cplusplus on
extern "C" void fn_802A002C(void) {
    struct Dummy {
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
    };
    unsigned char *current = (unsigned char *)lbl_804B5070;
    int i = 0;
    goto check;
loop:
    {
        Dummy *object = (Dummy *)*(void **)(current + 0x70);
        if (object != 0) {
            object->m1();
        }
    }
    current += 0x78;
    i++;
check:
    if (i < lbl_8055F81C) {
        goto loop;
    }
}
#pragma cplusplus reset
typedef struct Result_802A0098 {
    int count;
    float data[10];
} Result_802A0098;
extern "C" float PSVECMag(const void *);
extern float lbl_805646BC;
#pragma optimization_level 2
extern "C" void fn_802A0098(Result_802A0098 *out, const float *arg0, const Unk802A0794Params *arg1) {
    register float width;
    float span = arg0[1] * PSVECMag(&arg1->values[3]);
    width = lbl_805646BC;
    if (width < span) width = span;

    out->count = (int)(arg0[2] + arg0[3] * width);
    out->data[0] = arg1->values[0] + arg0[12];
    out->data[1] = arg1->values[1] + arg0[13];
    out->data[2] = arg1->values[2] + arg0[14];
    out->data[3] = arg1->values[3] * arg0[15];
    out->data[4] = arg1->values[4] * arg0[16];
    out->data[5] = arg1->values[5] * arg0[15];
    out->data[6] = arg0[4] + arg0[6] * width;
    out->data[7] = arg0[5] + arg0[7] * width;
    out->data[8] = arg0[8] + arg0[10] * width;
    out->data[9] = arg0[9] + arg0[11] * width;
}
#pragma optimization_level reset
extern "C" float fn_80287BC8(float, float);
extern void fn_802A0098(void *, void *, Unk802A0794Params *);
extern int fn_8028E584(int, float *, float *);
extern int fn_8028E590(int, float *, float *, float);
extern float lbl_805646C4;
#pragma push
#pragma cplusplus off
extern float fn_80287BC8(float, float);
#pragma push
#pragma processor 750
#pragma cplusplus off
void fn_802A01C8(void *arg0, Unk802A0794Params *params) {
    struct Result {
        int count;
        float data[10];
    } out;
    float a[3];
    float b[3];
    float a0, a1, a2;
    float b0, b1, b2;
    unsigned char flag;
    int i;

    fn_802A0098(&out, arg0, params);
    for (i = 0; i < out.count; i++) {
        a2 = out.data[2] + fn_80287BC8(-out.data[6], out.data[6]);
        a1 = out.data[1] + fn_80287BC8(-out.data[7], out.data[7]);
        a0 = out.data[0] + fn_80287BC8(-out.data[6], out.data[6]);
        a[0] = a0;
        a[1] = a1;
        a[2] = a2;

        b2 = out.data[5] + fn_80287BC8(-out.data[8], out.data[8]);
        b1 = out.data[4] + fn_80287BC8(-out.data[9], out.data[9]);
        b0 = out.data[3] + fn_80287BC8(-out.data[8], out.data[8]);
        b[1] = b1;
        flag = *(unsigned char *)((char *)arg0 + 0x68);
        b[2] = b2;
        b[0] = b0;

        if (flag != 0) {
            fn_8028E590(*(int *)((char *)arg0 + 0x64), a, b, lbl_805646C4);
        } else {
            fn_8028E584(*(int *)((char *)arg0 + 0x64), a, b);
        }
    }
}

#pragma push
#pragma cplusplus on
#pragma processor 750
extern "C" void fn_802A02F4(void *arg0, Unk802A0794Params *params) {
    class TargetObj {
    public:
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void call(float *, float *, short, int) = 0;
    };
    Result_802A0098 out;
    float a[3];
    float b[3];
    float a0, a1, a2;
    float b0, b1, b2;
    int i;

    fn_802A0098(&out, arg0, params);
    out.data[4] += *(float *)((char *)arg0 + 0x74);

    for (i = 0; i < out.count; i++) {
        a2 = out.data[2] + fn_80287BC8(-out.data[6], out.data[6]);
        a1 = out.data[1] + fn_80287BC8(-out.data[7], out.data[7]);
        a0 = out.data[0] + fn_80287BC8(-out.data[6], out.data[6]);
        a[1] = a1;
        a[2] = a2;
        a[0] = a0;

        b2 = out.data[5] + fn_80287BC8(-out.data[8], out.data[8]);
        b1 = out.data[4] + fn_80287BC8(-out.data[9], out.data[9]);
        b0 = out.data[3] + fn_80287BC8(-out.data[8], out.data[8]);
        b[1] = b1;
        b[2] = b2;

        (*(TargetObj **)((char *)arg0 + 0x70))->call(a, (b[0] = b0, b), params->unk_0x18, -1);
    }
}
#pragma pop

#pragma pop
#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
extern float lbl_805646BC, lbl_805646C0, lbl_805646C8;
extern "C" void *fn_801E8718(int);
extern "C" float PSVECDotProduct(const float *, const float *);
extern "C" int fn_801E85A4(void);
#pragma cplusplus off
void fn_802A042C(void *arg0, Unk802A0794Params *arg1) {
    struct Entry { unsigned int words[12]; };
    struct Entry copy;
    float vec[6];
    float bias, scale, upper, lower;
    float radius2;
    void *obj;
    Unk802A0794Params *pos;
    int i;
    int offset;

    lower = lbl_805646BC;
    obj = arg0;
    upper = lbl_805646B4;
    pos = arg1;
    scale = lbl_805646C0;
    bias = lbl_805646C8;
    i = 0;
    offset = 0;
    goto test;
body:
    {
        struct Entry *entry = (struct Entry *)fn_801E8718(i);
        float pointX, pointY, pointZ, dx, dy, dz, dot;
        float radius;
        copy = *entry;
        pointX = pos->values[0] + *(float *)((char *)obj + 0x30);
        radius = *(volatile float *)((char *)obj + 0x44);
        radius2 = radius * radius;
        dx = pointX - *(float *)&copy.words[9];
        pointY = pos->values[1] + *(float *)((char *)obj + 0x34);
        dy = pointY - *(float *)&copy.words[10];
        pointZ = pos->values[2] + *(float *)((char *)obj + 0x38);
        dz = pointZ - *(float *)&copy.words[11];
        vec[3] = pointX;
        vec[4] = pointY;
        vec[5] = pointZ;
        vec[0] = dx;
        vec[1] = dy;
        vec[2] = dz;
        dot = PSVECDotProduct(vec, vec);
        if (dot < radius2) {
            float amount = dot / radius2;
            float base;
            float next;
            int alpha;
            unsigned int clamped;
            unsigned int *colors;
            unsigned int old;
            unsigned int objectColor;
            unsigned int output;
            if (amount < lower) amount = lower;
            if (amount > upper) amount = upper;
            base = scale * *(float *)((char *)obj + 0x48);
            next = base + amount * (upper - base);
            if (next < upper) next -= bias;
            else next += bias;
            colors = (unsigned int *)lbl_8055F820;
            old = colors[offset / 4];
            alpha = (int)next + (int)(old >> 24);
            alpha = alpha & ((-alpha & ~alpha) >> 31);
            clamped = 255U;
            if (alpha < 255) clamped = (unsigned int)alpha;
            objectColor = *(unsigned int *)((char *)obj + 0x4C);
            output = (objectColor & 0x00FF0000) | (clamped << 24) | (objectColor & 0x0000FFFF);
            colors[offset / 4] = output;
        }
        offset += 4;
        i++;
    }
test:
    if (i < fn_801E85A4()) goto body;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
int fn_802A0620(Unk802A0794Params *arg0) {
    int h;
    unsigned char *object;
    int i;
    short g;
    Unk802A0794Params params;
    int f,e,d,c,b,a;
    object = (unsigned char *)fn_8029FE1C(arg0->unk_0x1C);
    a = ((volatile int *)arg0)[0];
    b = ((volatile int *)arg0)[1];
    c = ((volatile int *)arg0)[2];
    d = ((volatile int *)arg0)[3];
    e = ((volatile int *)arg0)[4];
    f = ((volatile int *)arg0)[5];
    g = *(volatile short *)&arg0->unk_0x18;
    h = *(volatile int *)&arg0->unk_0x1C;
    ((int *)&params)[0] = a;
    ((int *)&params)[1] = b;
    ((int *)&params)[2] = c;
    ((int *)&params)[3] = d;
    ((int *)&params)[4] = e;
    ((int *)&params)[5] = f;
    params.unk_0x18 = (unsigned)g;
    params.unk_0x1C = h;
    if (object) {
        for (i = 0; i < *(int *)(object + 0x50); i++) {
            if (object[0x60] != 0) fn_802A01C8(object, &params);
            if (object[0x6C] != 0) fn_802A02F4(object, &params);
            params.values[0] += *(float *)(object + 0x54);
            params.values[1] += *(float *)(object + 0x58);
            params.values[2] += *(float *)(object + 0x5C);
        }
    }
    return 0x20;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
int fn_802A0720(int *arg0, int arg1) {
    int offset;
    int i;
    i = 0;
    offset = 0;
    goto check;
loop:
    {
        int *base = (int *)lbl_804B9B7C[0];
        unsigned char *entry = (unsigned char *)base + offset;
        if (*(int *)entry == *arg0)
            fn_802A0794(entry);
    }
    offset += 0x34;
    i++;
check:
    if (i < lbl_804B9B7C[1])
        goto loop;
    return 4;
}
#pragma pop

#pragma push
#pragma inline off
void fn_802A0794(void *arg0) {
    Unk802A0794Params params;
    unsigned char *object;
    params.unk_0x18 = *(short *)((char *)arg0 + 0x2C);
    params.values[0] = *(float *)((char *)arg0 + 4);
    params.values[1] = *(float *)((char *)arg0 + 8);
    params.values[2] = *(float *)((char *)arg0 + 12);
    params.values[3] = *(float *)((char *)arg0 + 16);
    params.values[4] = *(float *)((char *)arg0 + 20);
    params.values[5] = *(float *)((char *)arg0 + 24);
    params.unk_0x1C = *(int *)((char *)arg0 + 0x28);
    object = (unsigned char *)fn_8029FE1C(params.unk_0x1C);
    if (object != 0) {
        fn_802A042C(object, &params);
        if (object[0x60] != 0)
            fn_802A01C8(object, &params);
        if (object[0x6C] != 0)
            fn_802A02F4(object, &params);
    } else {
        fn_802E30C8(lbl_803498AC, params.unk_0x1C);
    }
    *(short *)((char *)arg0 + 0x2C) = params.unk_0x18;
}
#pragma pop

