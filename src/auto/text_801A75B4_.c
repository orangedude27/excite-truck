// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern const char *lbl_802F9588[];
struct Entry_801A75B4 { const char *name; char pad[20]; };
extern float fn_801A7F98(void);
extern float lbl_80562470;
extern int fn_801A8E38(void);

extern char lbl_8055E5C8;
const char **fn_801A75B4(const char *arg0) {
    int *entry;
    int i;
    entry = (int *)lbl_802F9588;
    i = 0;
loop:
    if (stricmp((const char *)entry[0], arg0) == 0)
        return (const char **)entry;
    i++;
    if (i < 0x15) {
        entry += 2;
        goto loop;
    }
    return 0;
}

extern signed char fn_802E47F8(int);
extern char lbl_803342D0[];
extern char lbl_8055E5D4;
void fn_801A7628(void) {
    extern const char **lbl_8055E5CC;
    extern int lbl_8055E5D0;
    const char **table;
    int count;
    if ((signed char)lbl_8055E5D4 == 0) {
        *(char *)(lbl_803342D0 + 0x6E8) = fn_802E47F8(0x1E);
        *(char *)(lbl_803342D0 + 0x700) = fn_802E47F8(0x30);
        *(char *)(lbl_803342D0 + 0x718) = fn_802E47F8(0x2E);
        *(char *)(lbl_803342D0 + 0x730) = fn_802E47F8(0x20);
        *(char *)(lbl_803342D0 + 0x748) = fn_802E47F8(0x12);
        *(char *)(lbl_803342D0 + 0x760) = fn_802E47F8(0x21);
        *(char *)(lbl_803342D0 + 0x778) = fn_802E47F8(0x22);
        *(char *)(lbl_803342D0 + 0x790) = fn_802E47F8(0x23);
        *(char *)(lbl_803342D0 + 0x7A8) = fn_802E47F8(0x17);
        *(char *)(lbl_803342D0 + 0x7C0) = fn_802E47F8(0x24);
        *(char *)(lbl_803342D0 + 0x7D8) = fn_802E47F8(0x25);
        *(char *)(lbl_803342D0 + 0x7F0) = fn_802E47F8(0x26);
        *(char *)(lbl_803342D0 + 0x808) = fn_802E47F8(0x32);
        *(char *)(lbl_803342D0 + 0x820) = fn_802E47F8(0x31);
        *(char *)(lbl_803342D0 + 0x838) = fn_802E47F8(0x18);
        *(char *)(lbl_803342D0 + 0x850) = fn_802E47F8(0x10);
        *(char *)(lbl_803342D0 + 0x868) = fn_802E47F8(0x13);
        *(char *)(lbl_803342D0 + 0x880) = fn_802E47F8(0x1F);
        *(char *)(lbl_803342D0 + 0x898) = fn_802E47F8(0x16);
        *(char *)(lbl_803342D0 + 0x8B0) = fn_802E47F8(0x2F);
        *(char *)(lbl_803342D0 + 0x8C8) = fn_802E47F8(0x11);
        *(char *)(lbl_803342D0 + 0x8E0) = fn_802E47F8(0x2D);
        *(char *)(lbl_803342D0 + 0x8F8) = fn_802E47F8(0x15);
        *(char *)(lbl_803342D0 + 0x910) = fn_802E47F8(0x2C);
        *(char *)(lbl_803342D0 + 0x928) = fn_802E47F8(7);
        *(char *)(lbl_803342D0 + 0x940) = fn_802E47F8(8);
        *(char *)(lbl_803342D0 + 0x958) = fn_802E47F8(9);
        *(char *)(lbl_803342D0 + 0x970) = fn_802E47F8(0xA);
        *(char *)(lbl_803342D0 + 0x988) = fn_802E47F8(0xB);
        *(char *)(lbl_803342D0 + 0x9A0) = fn_802E47F8(0x1A);
        *(char *)(lbl_803342D0 + 0x9B8) = fn_802E47F8(0x1B);
        *(char *)(lbl_803342D0 + 0x9D0) = fn_802E47F8(0x27);
        *(char *)(lbl_803342D0 + 0x9E8) = fn_802E47F8(0x28);
        *(char *)(lbl_803342D0 + 0xA00) = fn_802E47F8(0x33);
        *(char *)(lbl_803342D0 + 0xA18) = fn_802E47F8(0x34);
        *(char *)(lbl_803342D0 + 0xA30) = fn_802E47F8(0x35);
        *(char *)(lbl_803342D0 + 0xA48) = fn_802E47F8(0xC);
        *(char *)(lbl_803342D0 + 0xA60) = fn_802E47F8(0xD);
        lbl_8055E5D4 = 1;
    }
    table = (const char **)lbl_803342D0;
    count = 0x7A;
    lbl_8055E5CC = table;
    lbl_8055E5D0 = count;
}

void fn_801A7F8C(void) {
    lbl_8055E5C8 = 0;
}

int fn_801A8E38(void) {
    return fn_801A7F98() > lbl_80562470;
}

int fn_801A8E68(void *arg0) {
    int state = *(int *)arg0;
    if (state >= 7)
        return 0;
    if (state < 1)
        return 0;
    if (fn_801A8E38() == 0) {
        *(unsigned char *)((char *)arg0 + 0xC) = 0;
        return 0;
    }
    if (*(unsigned char *)((char *)arg0 + 0xC) != 0)
        return 0;
    *(unsigned char *)((char *)arg0 + 0xC) = 1;
    return 1;
}

int fn_801A8EE4(unsigned int *arg0) {
    unsigned int value = *arg0 - 1;
    int result = 0;
    if (value > 5)
        return result;
    if ((1U << value) & 0x2D)
        result = 1;
    return result;
}

int fn_801A8F10(int *arg0) {
    extern int lbl_80435050[];
    extern int jumptable_80334F04[];
    extern int lbl_80334EE0;
    extern void fn_802E317C(int *);
    int state = arg0[0];
    int *entry = &lbl_80435050[arg0[1] * 0x64];
    int a = entry[0x11];
    int b = entry[0x12];
    int c = entry[0x13];
    int d = entry[0x14];
    if (state == 4)
        return (a >> 1) & 1;
    if (state == 3) {
        int bit = (1 << arg0[2]) & b;
        return (-bit | bit) >> 31;
    }
    if (state == 2) {
        if (arg0[2] <= 0x1E) {
            switch (arg0[2]) {
            case 0: return (a >> 31) & 1;
            case 1: return (a >> 1) & 1;
            case 2: return (a >> 28) & 1;
            case 3: return (a >> 29) & 1;
            case 4: return (a >> 27) & 1;
            case 5: return (a >> 26) & 1;
            case 6: return (a >> 25) & 1;
            default: return (a >> 24) & 1;
            }
        }
        fn_802E317C(&lbl_80334EE0);
        return 0;
    }
    return (-state | state) >> 31;
}

extern void fn_801A7628(void);
extern void fn_801A9110(void *, const char *);
extern void *fn_801A9234(const char *);
extern void fn_801A91B0(void *, const void *);
extern int stricmp(const char *, const char *);
extern const char *lbl_802F9588[];
extern const char **lbl_8055E5CC;
extern int lbl_8055E5D0;
extern char *strncpy(char *, const char *, unsigned int);
int fn_801A902C(void) {
    fn_801A7628();
    return 0x15;
}

void fn_801A9050(void *arg0, int arg1) {
    int zero[8] = {0};
    fn_801A9110(arg0, lbl_802F9588[arg1]);
}

void fn_801A90A4(char *arg0, int arg1, const char *arg2) {
    const char **entry = (const char **)fn_801A9234(arg2);
    if (entry != 0)
        strncpy(arg0, *entry, arg1);
    else
        arg0[0] = 0;
    arg0[arg1 - 1] = 0;
}

void fn_801A9110(void *arg0, const char *arg1) {
    int i;
    const char **table;
    fn_801A7628();
    table = lbl_8055E5CC;
    for (i = 0; i < lbl_8055E5D0; i++) {
        if (stricmp(table[i * 3], arg1) == 0) {
            fn_801A91B0(arg0, &table[i * 3]);
            return;
        }
    }
    *(int *)arg0 = 0;
}

void fn_801A91B0(void *arg0, const void *arg1) {
    int state = *(const int *)((const char *)arg1 + 8);
    *(int *)arg0 = state;
    switch (state) {
    case 2:
    case 3:
    case 5:
    case 6:
    case 4:
        *(int *)((char *)arg0 + 8) = *(const int *)((const char *)arg1 + 0xC);
        return;
    case 1:
        *(unsigned char *)((char *)arg0 + 8) = *(const unsigned char *)((const char *)arg1 + 0xC);
        return;
    }
}

