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

void *fn_801E879C(void) {
    return lbl_80487DE0;
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

extern void *lbl_8055AF08;
void* fn_801E89EC(void) {
    return lbl_8055AF08;
}

void fn_801E89F4(void *arg0) {
    lbl_8055AF08 = arg0;
}

