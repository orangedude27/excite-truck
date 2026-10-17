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

void fn_801E7DEC(void) {
    fn_801E7C28();
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

void fn_801E837C(void) {
    extern void fn_802D6C54(long, void *, float);
    long i;
    for (i = 0; i < 0x4B; i++)
        fn_802D6C54(i, (char *)lbl_8055EB04 + i * 4,
                    *(float *)((char *)lbl_8055EB04 + i * 4 + 0xDB4));
}

void fn_801E83D4(void) { extern int fn_801B89F8(void); extern void *lbl_8055AF0C; extern void fn_801EBD18(void *); if (fn_801B89F8() == 0 || lbl_8055AF0C == 0) fn_801EBD18(lbl_8055AF0C); }

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

long fn_801E868C(long arg0, unsigned long *arg1, unsigned long *arg2) {
    char *entry = (char *)lbl_8055EB04 + arg0 * 0xE0;
    unsigned long id = *(unsigned long *)(entry + 0x70);
    if (id != lbl_80487CE0[arg0]) {
        lbl_80487CE0[arg0] = id;
        *arg1 = *(unsigned long *)(entry + 0x74) >> 16;
        if (arg2 != 0) *arg2 = *(unsigned long *)(entry + 0x74) & 0xFFFF;
        return 1;
    }
    return 0;
}

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

long fn_801E8758(long arg0) {
    long index = arg0;
    unsigned char *entry;
    long value;
    long result = 1;
    if (index < 0) index = (long)lbl_8055AF0C;
    entry = lbl_80487D00 + index * 0x38;
    value = *(long *)(entry + 0x30);
    if (value & 0x10) return result;
    if ((value ^ *(long *)(entry + 0x34)) & 0x20) return result;
    return 0;
}

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

void fn_801E8CE4(void) {
    fn_80297984();
    fn_802889F0();
    if (lbl_8055EB24 != 0) ((void (*)(void))lbl_8055EB24)();
    fn_80287914();
    fn_801FA1D4();
    fn_802C1A08();
    memset(lbl_80487CE0, 0, 0x10);
    lbl_8055EB18 = lbl_80562DBC;
    lbl_8055EB14 = lbl_80562DBC;
}

void fn_801E8D48(void) {
    struct Init { void *name; int size; float a,b,c,d,e,f,g,h; } init;
    init.name = (void *)0x57484C50;
    init.size = 0x28;
    init.a = lbl_80562DF4; init.b = lbl_80562DF8;
    init.c = lbl_80562DFC; init.d = lbl_80562DFC;
    init.e = lbl_80562E00; init.f = lbl_80562DA0;
    init.g = lbl_80562E04; init.h = lbl_80562E08;
    if (fn_801284F8(0x84, &lbl_8055AF24, &init, lbl_80562E04,
                    lbl_80562DA0, lbl_80562E00, lbl_80562DFC,
                    lbl_80562DF8, lbl_80562DF4))
        fn_801F19FC(&init);
    fn_801E87D4(0);
}

void fn_801E8DD4(void) {
    long spC;
    long sp8;
    memset(&sp8, 0, 8);
    sp8 = 0x50616E6C;
    spC = 8;
    if (((int (*)(int, void *))fn_801284F8)(0x7C, &lbl_80339CB4) != 0) fn_801EAD6C(&sp8);
    ((void (*)(void))fn_801E87D4)();
}

void fn_801E8E38(void) {
    float sp1C;
    float sp18;
    float sp14;
    float sp10;
    long spC;
    long sp8;
    sp8 = 0x4D555450;
    spC = 0x18;
    sp10 = lbl_80562DB0;
    sp1C = lbl_80562DA8;
    sp18 = lbl_80562DA8;
    sp14 = lbl_80562DA8;
    if (((int (*)(int, void *, void *, float, float, float, float, float, float))fn_801284F8)(0x7C, &lbl_80339CB4, &sp8, sp10, sp1C, sp18, sp14, sp14, sp14) != 0) fn_801EAD6C(&sp8);
    ((void (*)(void))fn_801E87D4)();
}

void *fn_801E8EA4(long arg0) {
    unsigned char *entry = lbl_80339CC0;
    do {
        if (*(long *)(entry + 4) == arg0) break;
        entry += 0xC;
    } while (*(long *)entry != 0);
    if (*(long *)entry == 0) fn_802E317C(lbl_80339CFC);
    return entry;
}

long fn_801E952C(long arg0) {
    memset((void *)arg0, 0, 0x3F8);
    return arg0;
}

void fn_801E9564(long arg0) {
    long i;
    for (i = 0; i < 5; i++) fn_801E8D48();
    fn_80127464();
    fn_801E8F10(arg0);
    for (i = 0; i < 0xC; i++) fn_801E8DD4();
    for (i = 0; i < 0x40; i++) fn_801E8E38();
}

#pragma paired_single off
#pragma paired_single off
void fn_801E95DC(void) {
    extern double fn_8002EFB4(double, double);
    extern float fn_80203FE0(void);
    extern void fn_802C7D54(long, float *, long, float, float, float);
    extern void *lbl_80488648[];
    extern double lbl_80562E10;
    extern float lbl_80562E18;
    float matrix[12];
    float y, x;
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
        x = lbl_80562DD4 - (float)fn_8002EFB4(time, lbl_80562E10);
        y = lbl_80562DBC;
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
