// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern long fn_800167F4(void);
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

extern void *lbl_8055AF08;
void* fn_801E89EC(void) {
    return lbl_8055AF08;
}

void fn_801E89F4(void *arg0) {
    lbl_8055AF08 = arg0;
}
extern unsigned char lbl_80487D00[];
