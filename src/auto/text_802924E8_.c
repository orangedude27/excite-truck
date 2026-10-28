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
void fn_802924F4(void) {
    struct Vec {
        float x, y, z;
    } v;
    float one = lbl_805644D4;
    float offset = lbl_805644D8;
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
        v.y = w;
        *(float *)(p + 4) = (float)(double)w;
        v.z = q * factor;
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

typedef struct ChunkSys {
    char car[0x10];
    char ter[0x10];
    char wood[0x10];
    char invalid[0x20];
} ChunkSys;

extern char lbl_80349170[];
extern void *fn_801284F8(int, const void *);
extern void *fn_80293034(void *, void *, int);
extern void *fn_80293A00(void *, void *, int, int, int);
extern void *fn_80294254(void *, void *, int, int, int);
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
extern int fn_802928D4(int, int, int, int, int, int);
void fn_802929D8(int arg0, int arg1, int arg2, int arg3) {
    fn_802928D4(0, arg0, arg1, arg2, arg3, arg1);
}

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
    register float x = arg2[0];
    register float y = arg2[1];
    register float z;
    float firstDot, secondDot, scale;
    float nx;
    delta[0] = arg0[0] - x;
    z = arg2[2];
    delta[1] = arg0[1] - y;
    delta[2] = arg0[2] - z;
    firstDot = PSVECDotProduct(delta, arg3);
    if (firstDot < lbl_805644D8) {
        secondDot = PSVECDotProduct(arg1, arg3);
        nx = arg3[0];
        scale = -firstDot;
        arg0[0] += nx * scale;
        arg0[1] += arg3[1] * scale;
        arg0[2] += arg3[2] * scale;
        scale = lbl_805644E8 * (float)__fabs((double)secondDot) - secondDot;
        arg1[0] += nx * scale;
        arg1[1] += arg3[1] * scale;
        arg1[2] += arg3[2] * scale;
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
    char *dst;
    register int count;
    int offset = arg1;
    int cursor = (int)arg2;

    list = fn_802C6B44();
    memset(temp, 0, 0x2C);

    dst = temp + 0x14;
    count = 0x10;
    goto copy_second;
count_second:
    count--;
    if (count > 0) goto copy_second;
    dst[-1] = 0;
    goto copied_second;
copy_second:
    c = *(char *)cursor++;
    *dst++ = c;
    if ((signed char)c != 0) goto count_second;
copied_second:

    *(int *)(temp + 0x10) = offset;
    cursor = 0;
    offset = 0;
    goto check_list;
copy_first:
    src = fn_802C9C24(*(int *)((char *)list + 4) + offset);
    dst = temp;
    count = 0x10;
    goto copy_entry;
count_entry:
    count--;
    if (count > 0) goto copy_entry;
    dst[-1] = 0;
    goto copied_entry;
copy_entry:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0) goto count_entry;
copied_entry:
    fn_802C7888(temp, 1);
    offset += 0x10;
    cursor++;
check_list:
    if (cursor < *(int *)list) goto copy_first;
    fn_802C6C20(list);
}
#pragma scheduling on
int fn_80292DE8(const char *arg0) {
    int table[6];
    int *src = lbl_802FA998;
    int *dst = table;
    int *p = table;
    unsigned int i = 0;

    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst = *src;
    do {
        if (strcmp(arg0, (const char *)p[0]) == 0) {
            return *(int *)((char *)table + 4 + (i << 3));
        }
        ++i;
        p += 2;
    } while (i < 3);
    fn_802E317C(lbl_80349208, arg0);
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
#pragma scheduling invalid_target
int fn_80292EC0(void *arg0, const char *arg1, s32 *arg2, s32 arg3) {
    u8 *entry = (u8 *)arg0;
    s32 i = 0;
    do {
        if (fn_8002B1D8(arg1, (char *)entry, 0xF) == 0) {
            *arg2 = i;
            return 1;
        }
        entry += 0x18;
        i += 1;
    } while (i < *(s32 *)((u8 *)arg0 + 0x180));
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
    if (arg1 != 0) {
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
    register unsigned char *entry;
    int temp_r30;
    int temp_r29;
    register int i;

    temp_r30 = fn_802C9950(0);
    temp_r29 = fn_802C9994(0);
    entry = (unsigned char *)arg0 + 0x2C;
    i = 0;
    for (; i < *(int *)((char *)arg0 + 0x2FAC); entry += 0x4C, i++) {
        fn_802C9950(*(int *)((char *)arg0 + (*(unsigned char *)(entry + 0x4A) << 3) + 0x2FB0));
        fn_802C9994(*(int *)((char *)arg0 + (*(unsigned char *)(entry + 0x4A) << 3) + 0x2FB4));
        fn_802C744C(*(void **)((char *)arg0 + (*(unsigned char *)(entry + 0x48) << 2) + 8), entry);
    }
    fn_802C9994(temp_r29);
    fn_802C9950(temp_r30);
}
#pragma use_lmw_stmw reset

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
    register float scale = lbl_805644EC;
    register unsigned int color;
    register unsigned int checkValue;
    register unsigned int count = 0;
    register s32 temp;
    register s32 component;
    s32 packed;
    void *item;
    goto check_loop;
body:
    if (count < 8U) item = (void *)*table;
    else item = 0;
    color = *(unsigned int *)((u8 *)item + 0x3EC);
    component = 0xFF;
    temp = (s32)(scale * (float)(u8)color);
    if (temp <= 0xFF) component = temp;
    packed = component & 0xFF;
    component = 0xFF;
    temp = (s32)(scale * (float)(u8)(color >> 8));
    if (temp <= 0xFF) component = temp;
    packed |= (component & 0xFF) << 8;
    component = 0xFF;
    temp = (s32)(scale * (float)(u8)(color >> 16));
    if (temp <= 0xFF) component = temp;
    packed = (((component & 0xFF) << 16) | 0xFF000000) | packed;
    *(unsigned int *)(out + 0x2FB0) = (unsigned int)packed;
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
    *(void **)arg0 = lbl_80349278;
    fn_80293CD0(arg0, arg2, arg3, arg4);
    *(float *)((char *)arg0 + 4) = lbl_8056450C;
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
    u8 *object;
    u8 *record;
    u8 *template;
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
void fn_80293CD0(void *arg0, int arg1, int arg2, int arg3) {
    char name[0x20];
    int i;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    for (i = 0; i < 8; i++) {
        fn_801345D8(name, 0x20, lbl_80349250, arg1, i + 1);
        if (fn_8012C33C(name) != 0) {
            if (arg3 != 0 && *(s8 *)arg3 != 0) fn_80292CD8(name, arg2, (u8 *)arg3);
            i = *(s32 *)((u8 *)arg0 + 0x28);
            *(s32 *)((u8 *)arg0 + i * 4 + 8) = fn_802C6FC0(name, arg2, 0);
            i = *(s32 *)((u8 *)arg0 + 0x28);
            i++;
            *(s32 *)((u8 *)arg0 + 0x28) = i;
        }
    }
    i = *(s32 *)((u8 *)arg0 + 0x28);
    for (; i < 8; i++) *(s32 *)((u8 *)arg0 + i * 4 + 8) = -1;
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
    float initialValue;
    *(void **)arg0 = lbl_8034925C;
    initialValue = ((float (*)(void *, int, int, int))fn_80294530)(arg0, arg2, arg3, arg4);
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
    register int index;
    int offset;
    register float *second;
    register float *first;
    register u8 *object;
    register u8 *record;
    register u8 *template;
    float x, y, z, a, b, c;
    unsigned int secondWord, firstWord;
    second = arg2;
    first = arg1;
    object = (u8 *)arg0;
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
    secondWord = *(unsigned int *)(template + 0x1C);
    firstWord = *(unsigned int *)(template + 0x20);
    *(unsigned int *)(record + 0x38) = secondWord;
    *(unsigned int *)(record + 0x3C) = firstWord;
    *(unsigned int *)(record + 0x40) = *(unsigned int *)(template + 0x24);
    secondWord = *(unsigned int *)(template + 0x28);
    firstWord = *(unsigned int *)(template + 0x2C);
    *(unsigned int *)(record + 0x44) = secondWord;
    *(unsigned int *)(record + 0x48) = firstWord;
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

void fn_80294530(void *arg0, int arg1, int arg2, int arg3) {
    char name[0x20];
    int i;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    for (i = 0; i < 8; i++) {
        fn_801345D8(name, 0x20, lbl_80349250, arg1, i + 1);
        if (fn_8012C33C(name) != 0) {
            if (arg3 != 0 && *(s8 *)arg3 != 0) fn_80292CD8(name, arg2, (u8 *)arg3);
            i = *(s32 *)((u8 *)arg0 + 0x28);
            *(s32 *)((u8 *)arg0 + i * 4 + 8) = fn_802C6FC0(name, arg2, 0);
            i = *(s32 *)((u8 *)arg0 + 0x28);
            i++;
            *(s32 *)((u8 *)arg0 + 0x28) = i;
        }
    }
    i = *(s32 *)((u8 *)arg0 + 0x28);
    for (; i < 8; i++) *(s32 *)((u8 *)arg0 + i * 4 + 8) = -1;
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
void fn_80294780(void *arg0) {
    unsigned char *base = (unsigned char *)arg0, *cur = base + 0x2c, *out = cur, *src;
    int i = 0;
    float dt = fn_801E7E24(arg0), scale = lbl_805644D4 - lbl_80564510 * dt;
    float x, y, z, vy;
    goto check;
body:
    if (*(float *)(cur + 0x3c) >= lbl_805644D8 && !(*(float *)(cur + 0x3c) > lbl_805644FC)) {
        x = *(float *)(cur + 0x30) * scale;
        y = *(float *)(cur + 0x34) * scale;
        z = *(float *)(cur + 0x38) * scale;
        vy = y - (lbl_80564500 * dt) * *(float *)(base + 4);
        *(float *)(out + 0x24) = *(float *)(cur + 0x24) + x * dt;
        *(float *)(out + 0x28) = *(float *)(cur + 0x28) + vy * dt;
        *(float *)(out + 0x2c) = *(float *)(cur + 0x2c) + z * dt;
        src = lbl_804B4030 + *(cur + 0x41) * 0x34;
        *(unsigned int *)(out + 0x00) = *(unsigned int *)(src + 0x10);
        *(unsigned int *)(out + 0x04) = *(unsigned int *)(src + 0x14);
        *(unsigned int *)(out + 0x08) = *(unsigned int *)(src + 0x18);
        *(unsigned int *)(out + 0x0c) = *(unsigned int *)(src + 0x1c);
        *(unsigned int *)(out + 0x10) = *(unsigned int *)(src + 0x20);
        *(unsigned int *)(out + 0x14) = *(unsigned int *)(src + 0x24);
        *(unsigned int *)(out + 0x18) = *(unsigned int *)(src + 0x28);
        *(unsigned int *)(out + 0x1c) = *(unsigned int *)(src + 0x2c);
        *(unsigned int *)(out + 0x20) = *(unsigned int *)(src + 0x30);
        *(float *)(out + 0x30) = x;
        *(float *)(out + 0x34) = vy;
        *(float *)(out + 0x38) = z;
        *(float *)(out + 0x3c) = *(float *)(cur + 0x3c) + dt;
        out[0x40] = cur[0x40];
        out[0x41] = cur[0x41];
        out += 0x44;
    }
    i++; cur += 0x44;
check:
          if (i < *(int *)(base + 0x222c)) goto body;
      *(int *)(base + 0x222c) = (out - (base + 0x2c)) / 0x44;
  }

  #pragma scheduling on
