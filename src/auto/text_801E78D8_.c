// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern long fn_800167F4(void);
extern float fn_80129DC4(long, float, float);
extern void PSVECNormalize(float *, float *);
extern float lbl_80562DBC, lbl_80562DC0, lbl_80562DD4, lbl_80562DD8;
extern float lbl_80562DDC, lbl_80562DE0;
extern float lbl_802F99F8[4];
extern long lbl_8055AF10;
extern void fn_802C6CF8(long);
extern void fn_80127464(void);
extern void fn_801E8D48(void);
extern void fn_801E8DD4(void);
extern void fn_801E8E38(void);
extern void fn_801E8F10(long);
extern int fn_802E317C(const char *, ...);
extern unsigned char lbl_80339CC0[];
extern char lbl_80339CFC[];
extern void *memset(void *, int, unsigned long);
extern float lbl_804881D8[];
extern void fn_80297984(void);
extern void fn_802889F0(void);
extern void fn_80287914(void);
extern void fn_801FA1D4(void);
extern void fn_802C1A08(void);
extern void *lbl_8055EB24;
extern float lbl_80562DBC;
extern float lbl_8055EB18;
extern float lbl_8055EB14;
extern int fn_801284F8(int, void *, void *, float, float, float, float, float, float);
extern void fn_801F19FC(void *);
extern float lbl_80562DA0, lbl_80562DF4, lbl_80562DF8, lbl_80562DFC;
extern float lbl_80562DA8, lbl_80562DB0;
extern char lbl_80339CB4[];
extern float lbl_80562E00, lbl_80562E04, lbl_80562E08;
extern unsigned char lbl_8055AF24;
extern void fn_80206464();
extern void fn_8020646C(long, long);
extern void fn_801E7984(void);
extern char lbl_8055EB11;
extern long lbl_80487CF0[];
extern unsigned char lbl_80487DE0[];
extern long lbl_8055EB34;
extern long *lbl_8055EB3C;
extern long lbl_8055EB38;
extern long *lbl_8055EB40;
void fn_801E78D8(long arg0) {
    long count;
    long i;
    long j;
    unsigned char *base;
    unsigned char *entry;
    count = fn_800167F4();
    fn_80206464();
    for (i = 0; i < count; i++) fn_8020646C(i, -1);
    base = (unsigned char *)arg0 + 0x20;
    j = 0;
    entry = base;
    for (; j < *(long *)(base + 0x3C0); entry += 0x78, j++) {
        if (*(long *)entry == 0x50) fn_8020646C(*(entry + 0x70) & 3, j);
    }
}

void fn_801E797C(void) { fn_80206464(0); }

void fn_801E7C1C(void) {
    lbl_8055EB11 = 0;
    fn_801E7984();
}

extern void fn_801E7C28(void *);
void fn_801E7DEC(void *arg0) {
    fn_801E7C28(arg0);
}

long fn_801E7DF0(long arg0) {
    return lbl_80487CF0[arg0];
}

void fn_801E7E04(long arg0, long arg1) {
    lbl_80487CF0[arg0] = arg1;
}

float fn_801E7E18(void) {
    extern float *lbl_8055EB04;
    return *lbl_8055EB04;
}

float fn_801E7E24(void) { extern float lbl_8055EB14; return lbl_8055EB14; }

long fn_801E7E2C(void) {
    return -1;
}

extern float *lbl_8055EB04;
void* fn_801E7E34(void) {
    return lbl_8055EB04;
}

long fn_801E7E3C(void) {
    return (long)lbl_8055EB04 + 0x560;
}

void fn_801E8144(void) {

}

extern void fn_80287AF0(void *);
extern void fn_801FA550(void);
#pragma cplusplus on
extern "C" void fn_801E8148(void) {
    class Dummy_801E8148 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
    };
    long index;
    long i;
    Dummy_801E8148 *obj;

    index = 0;
    i = 0;
    while (i < lbl_8055EB34) {
        obj = (Dummy_801E8148 *)*(long *)((char *)lbl_8055EB3C + index);
        obj->m2();
        index += 4;
        i++;
    }
    fn_80287AF0(0);
    fn_801FA550();
}
#pragma cplusplus off
void fn_801E837C(void) {
    extern void fn_802D6C54(long, void *, float);
    long i;
    for (i = 0; i < 0x4B; i++)
        fn_802D6C54(i, (char *)lbl_8055EB04 + i * 4,
                    *(float *)((char *)lbl_8055EB04 + i * 4 + 0xDB4));
}

void fn_801E83D4(void) { extern int fn_801B89F8(void); extern void *lbl_8055AF0C; extern void fn_801EBD18(void *); if (fn_801B89F8() == 0 || lbl_8055AF0C == 0) fn_801EBD18(lbl_8055AF0C); }

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801E8410(void) {
    extern int fn_801B89F8(void);
    extern float fn_801E8854(long);
    extern void fn_801E88B4(long *, long *, long *, long *, long);
    extern void fn_801E8148(void);
    extern void fn_801E95DC(void);
    extern void fn_801EA404(void *, long);
    extern void fn_802C87B4(long, long, long, long);
    extern void fn_802C8638(void *);
    extern void fn_802C2C64(long);
    extern void fn_80203EC0(void);
    extern void fn_802C7A44(void);
    extern void fn_802C7A50(void);
    extern void fn_802C7AD4(void);
    extern void fn_801FA618(void);
    extern void fn_802BF508(void);
    extern void fn_802C2488(void);
    extern void fn_802B0254(void);
    extern void fn_802B0218(void);
    extern void fn_80203EF4(void);
    extern void fn_80203EC4(void);
    extern void fn_80287A6C(long);
    extern void *lbl_8055AF0C;
    extern long lbl_8055CFF0, lbl_8055CFF4, lbl_8055EB34;
    extern long *lbl_8055EB3C;
    extern unsigned char lbl_80487D00[];
    extern void *lbl_80488648[];
    struct Dispatch24 {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    };
    struct Dispatch14 {
        virtual void n0(); virtual void n1(); virtual void n2(); virtual void n3();
    };
    long a, b, c, d;
    register long zero;
    register long count;
    unsigned char *base;
    ((void (*)(void))fn_801E837C)();
    if (fn_801B89F8() != 0) {
        if (*(void * volatile *)&lbl_8055AF0C != 0) return;
        zero = 0; a = zero; b = zero; c = lbl_8055CFF0; d = lbl_8055CFF4;
        count = (long)(*(void * volatile *)&lbl_8055AF0C);
        count *= 0x38;
        base = lbl_80487D00 + count;
        if (((int (*)(long, void *, void *, long))fn_801B89F8)(
                c, (void *)0, lbl_80487D00, count) == 0) {
            fn_801E88B4(&a, &b, &c, &d,
                        (long)(*(void * volatile *)&lbl_8055AF0C));
        }
        fn_802C87B4(a, b, c, d); fn_802C8638(base); fn_801E8854(-1);
        fn_802C2C64((long)(*(void * volatile *)&lbl_8055AF0C));
        fn_801EA404(base, 0);
    }
    fn_80203EC0(); fn_802C7A44(); ((void (*)(void))fn_801E8148)();
    fn_802C7A50(); fn_802C7AD4(); fn_801FA618();
    {
        long index; long i; Dispatch24 *obj;
        index = (long)lbl_80488648; i = 0;
        do {
            obj = (unsigned long)i < 8 ? *(Dispatch24 **)index : 0;
            if (obj != 0) obj->m7();
            i++; index += 4;
        } while (i < 8);
    }
    fn_802BF508(); fn_802C2488(); fn_802B0254(); fn_802B0218();
    fn_80203EF4(); fn_80203EC4(); fn_80287A6C(0); fn_801E95DC();
    {
        long i; long index; Dispatch14 *obj2;
        i = 0; index = 0;
        while (i < lbl_8055EB34) {
            obj2 = (Dispatch14 *)*(long *)((char *)lbl_8055EB3C + index);
            obj2->n3(); index += 4; i++;
        }
    }
}
#pragma cplusplus off
#pragma scheduling on
void fn_801E85A0(void) {

}

extern void *lbl_8055EB2C;
void* fn_801E85A4(void) {
    return lbl_8055EB2C;
}

extern void *lbl_8055EB30;
void* fn_801E85AC(void) {
    return lbl_8055EB30;
}

extern void *lbl_8055AF0C;
void* fn_801E85B4(void) {
    return lbl_8055AF0C;
}

extern long fn_8026A298(long);
extern long fn_801E866C(long);
extern unsigned char *fn_801EA9A0(long);
extern long fn_8026A248(long, long);
extern long fn_8026A2C8(void);
extern unsigned long lbl_80487CE0[];
void fn_801E85BC(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    fn_8026A298(arg0);
}

extern long fn_8026A2B0(long);
void fn_801E85CC(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    fn_8026A2B0(arg0);
}

void fn_801E85DC(long arg0) {
    long var_r29;
    long var_r31;
    long temp_r30;
    long count;
    var_r29 = arg0;
    if (arg0 < 0) var_r29 = (long)lbl_8055AF0C;
    var_r31 = fn_801E866C(var_r29);
    temp_r30 = var_r31;
loop:
    var_r31 = var_r31 + 1;
    count = fn_8026A2C8();
    var_r31 = var_r31 - (var_r31 / count) * count;
    if (*fn_801EA9A0(var_r31) == 0 && var_r31 != temp_r30) goto loop;
    fn_8026A248(var_r31, var_r29);
}

long fn_801E866C(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(long *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x64);
}

#pragma scheduling invalid_target
long fn_801E868C(long arg0, unsigned long *arg1, unsigned long *arg2) {
    volatile unsigned long *entry;
    volatile unsigned long *cache;
    unsigned long id;

    entry = (volatile unsigned long *)((char *)lbl_8055EB04 + arg0 * 0xE0);
    cache = (volatile unsigned long *)lbl_80487CE0;
    id = entry[0x70 / 4];
    if (id != cache[arg0]) {
        cache[arg0] = id;
        *arg1 = entry[0x74 / 4] >> 16;
        if (arg2 != 0) {
            *arg2 = entry[0x74 / 4] & 0xFFFF;
        }
        return 1;
    }
    return 0;
}
#pragma scheduling on
void fn_801E86E8(long arg0, long arg1) {
    if (arg1 < 0) arg1 = (long)lbl_8055AF0C;
    fn_8026A248(arg0, arg1);
}

long fn_801E86F8(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(long *)((char *)lbl_8055EB04 + arg0 * 4 + 0x384);
}

extern unsigned char lbl_80487D00[];
void *fn_801E8718(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return lbl_80487D00 + arg0 * 0x38;
}

float fn_801E8738(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(float *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x34);
}

#pragma scheduling off
long fn_801E8758(long arg0) {
    long value;
    unsigned char *entry;
    long result;

    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    entry = (unsigned char *)lbl_80487D00 + arg0 * 0x38;
    value = *(long *)(entry + 0x30);
    result = 1;
    if ((value & 0x10) == 0) {
        if (((value ^ *(long *)(entry + 0x34)) & 0x20) == 0) result = 0;
    }
    return result;
}
#pragma scheduling on
void *fn_801E879C(void) {
    return lbl_80487DE0;
}

void *fn_801E87A8(void) {
    return lbl_80487DE0 + 0x3E4;
}

#pragma dont_inline on
void fn_801E87B8(long arg0) {
    lbl_8055EB3C[lbl_8055EB34] = arg0;
    lbl_8055EB34 += 1;
}
void fn_801E87D4(long arg0) {
    long value;
    long index;
    long *base;
    value = arg0;
    fn_801E87B8(value);
    index = lbl_8055EB38;
    base = lbl_8055EB40;
    base[index] = value;
    lbl_8055EB38 = index + 1;
}

extern void *lbl_8055EB24;
void fn_801E8818(void* hi) {
    lbl_8055EB24 = hi;
}

void fn_801E8820(void) {
    lbl_8055EB24 = 0;
}

extern char lbl_8055EB08;
void fn_801E882C(void) {
    lbl_8055EB08 = 1;
}

int fn_801E8838(void) {
    if (lbl_8055EB04 != 0) {
        return *(int *)((char *)lbl_8055EB04 + 0xDB0);
    }
    return 0xFF;
}

float fn_801E8854(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(float *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x54);
}

float fn_801E8874(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(float *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x4C);
}

float fn_801E8894(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(float *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x50);
}

void fn_801E88B4(long *arg0, long *arg1, long *arg2, long *arg3, long arg4) {
    long index = arg4;
    char *base;
    if (index < 0) index = (long)lbl_8055AF0C;
    base = (char *)lbl_8055EB04 + index * 0xE0;
    *arg0 = *(long *)(base + 0x3C);
    *arg1 = *(long *)(base + 0x40);
    *arg2 = *(long *)(base + 0x44);
    *arg3 = *(long *)(base + 0x48);
}

#pragma scheduling invalid_target
float fn_801E88F0(long arg0) {
    long index = arg0;
    long params[4];
    long which;
    char *base;
    if (index < 0) index = (long)lbl_8055AF0C;
    params[0] = *(long *)lbl_802F99F8;
    params[1] = *(long *)((char *)lbl_802F99F8 + 4);
    params[2] = *(long *)((char *)lbl_802F99F8 + 8);
    params[3] = *(long *)((char *)lbl_802F99F8 + 12);
    which = (long)lbl_8055EB2C - 1;
    base = (char *)lbl_8055EB04 + index * 0xE0;
    return *(float *)(base + 0x38) * ((float *)params)[which];
}
#pragma scheduling on
long fn_801E8954(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return (*(unsigned long *)(lbl_80487D00 + arg0 * 0x38 + 0x30)) & 1;
}

long fn_801E897C(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return (*(unsigned long *)(lbl_80487D00 + arg0 * 0x38 + 0x30) >> 1) & 1;
}

long fn_801E89A4(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return (*(unsigned long *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x6C) >> 2) & 1;
}

long fn_801E89C8(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return (*(unsigned long *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x6C) >> 3) & 1;
}

extern void *lbl_8055AF08;
void* fn_801E89EC(void) {
    return lbl_8055AF08;
}

void fn_801E89F4(void *arg0) {
    lbl_8055AF08 = arg0;
}

void fn_801E89FC(void) {
    lbl_804881D8[0] = fn_80129DC4(0, lbl_80562DC0, lbl_80562DD4);
    lbl_804881D8[1] = fn_80129DC4(0, lbl_80562DD8, lbl_80562DDC);
    lbl_804881D8[2] = fn_80129DC4(0, lbl_80562DC0, lbl_80562DD4);
    PSVECNormalize(lbl_804881D8, lbl_804881D8);
    lbl_804881D8[3] = fn_80129DC4(0, lbl_80562DBC, lbl_80562DE0);
}

void fn_801E8C84(float *arg0) {
    float scale = lbl_804881D8[3];
    arg0[0] = lbl_804881D8[0] * scale;
    arg0[1] = lbl_804881D8[1] * scale;
    arg0[2] = lbl_804881D8[2] * scale;
}

void fn_801E8CB8(float *arg0, float *arg1) {
    arg0[0] = lbl_804881D8[0];
    arg0[1] = lbl_804881D8[1];
    arg0[2] = lbl_804881D8[2];
    arg1[0] = lbl_804881D8[3];
}

#pragma scheduling off
void fn_801E8CE4(void) {
    fn_80297984(); fn_802889F0();
    if (lbl_8055EB24 != 0) ((void (*)(void))lbl_8055EB24)();
    fn_80287914(); fn_801FA1D4(); fn_802C1A08();
    memset(lbl_80487CE0, 0, 0x10);
    lbl_8055EB18 = lbl_80562DBC;
    lbl_8055EB14 = lbl_80562DBC;
}
#pragma scheduling on
void fn_801E8D48(void) {
    struct Init { void *name; int size; float a,b,c,d,e,f,g,h; } init;
    int status;

    init.c = lbl_80562DFC;
    init.d = lbl_80562DFC;
    init.name = (void *)0x57484C50;
    init.a = lbl_80562DF4;
    init.b = lbl_80562DF8;
    init.size = 0x28;
    init.e = lbl_80562E00;
    init.f = lbl_80562DA0;
    init.g = lbl_80562E04;
    init.h = lbl_80562E08;
    status = ((int (*)(int, void *))fn_801284F8)(0x84, &lbl_8055AF24);
    if (status != 0) {
        ((void (*)(int, void *))fn_801F19FC)(status, &init);
    }
    ((void (*)(void))fn_801E87D4)();
}

#pragma scheduling invalid_target
void fn_801E8DD4(void) {
    long data[2];
    void *object;
    memset(data, 0, 8);
    data[0] = 0x50616E6C;
    data[1] = 8;
    object = ((void *(*)(int, void *))fn_801284F8)(0x7C, &lbl_80339CB4);
    if (object != 0) fn_801EAD6C(object, (long)data);
    ((void (*)(void))fn_801E87D4)();
}
#pragma scheduling invalid_target
void fn_801E8E38(void) {
    struct InitData { long tag; long size; float a; float b; float c; float d; } data;
    register float fill = lbl_80562DA8;
    register float main = lbl_80562DB0;
    void *object;

    data.tag = 0x4D555450;
    data.size = 0x18;
    data.a = main;
    data.b = fill;
    data.c = fill;
    data.d = fill;
    object = ((void *(*)(int, void *))fn_801284F8)(0x7C, &lbl_80339CB4);
    if (object != 0) fn_801EAD6C(object, (long)&data);
    ((void (*)(void))fn_801E87D4)();
}
#pragma scheduling invalid_target
void *fn_801E8EA4(long arg0) {
    unsigned char *entry = lbl_80339CC0;
    long sentinel;

    goto check_key;

check_key:
    if (*(long *)(entry + 4) == arg0) goto done;
    entry += 0xC;
    sentinel = *(long *)entry;
    if (sentinel != 0) goto check_key;

done:
    if (*(long *)entry == 0) {
        fn_802E317C(lbl_80339CFC, arg0);
    }
    return entry;
}
#pragma scheduling on
long fn_801E952C(long arg0) {
    memset((void *)arg0, 0, 0x3F8);
    return arg0;
}
#pragma scheduling on
void fn_801E9564(long arg0) {
    long i;
    for (i = 0; i < 5; i++) fn_801E8D48();
    fn_80127464();
    fn_801E8F10(arg0);
    for (i = 0; i < 0xC; i++) fn_801E8DD4();
    for (i = 0; i < 0x40; i++) fn_801E8E38();
}

#pragma paired_single off
void fn_801E95DC(void) {
    extern double fn_8002EFB4(double, double);
    extern float fn_80203FE0(void);
    extern void fn_802C7D54(long, float *, long, float, float, float);
    extern void *lbl_80488648[];
    extern double lbl_80562E10;
    extern float lbl_80562E18;
    float matrix[12];
    float x, y;
    float time;
    long flags;
    unsigned long index;
    char *entry;
    long mode;
    if (lbl_8055AF10 != -1) {
        matrix[1] = lbl_80562DBC;
        matrix[0] = lbl_80562DD4;
        matrix[2] = lbl_80562DBC;
        matrix[3] = lbl_80562DBC;
        matrix[4] = lbl_80562DD4;
        matrix[5] = lbl_80562DBC;
        matrix[6] = lbl_80562DBC;
        matrix[7] = lbl_80562DBC;
        matrix[8] = lbl_80562DD4;
        matrix[9] = lbl_80562DBC;
        matrix[10] = lbl_80562DBC;
        matrix[11] = lbl_80562DBC;
        time = ((float (*)(float))fn_801E7E18)(lbl_80562DD4);
        time = (float)fn_8002EFB4(time, lbl_80562E10);
        y = lbl_80562DBC;
        x = lbl_80562DD4 - time;
        index = fn_801E866C((long)lbl_8055AF0C);
        if (index < 8) entry = lbl_80488648[index];
        else entry = 0;
        matrix[10] = *(float *)(entry + 0x2c);
        y = (float)y - matrix[10] / fn_80203FE0();
        flags = *(long *)((char *)fn_801E87A8() + 0x10);
        mode = 2;
        if (flags & 2) mode = 1;
        fn_802C7D54(lbl_8055AF10, matrix, mode, x, y, lbl_80562E18);
    }
}
#pragma paired_single reset
void fn_801E9BE4(void) {
    long value = lbl_8055AF10;
    if (value != -1) fn_802C6CF8(value);
    lbl_8055AF10 = -1;
}

extern unsigned char lbl_80487D00[];
