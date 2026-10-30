// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { char data[0x20]; } GXTexObj;
extern void GXInitTexObj(GXTexObj *, void *, unsigned short, unsigned short, int, int, int, int);
extern void GXInitTexObjLOD(GXTexObj *, int, int, int, int, int, float, float, float);
extern float lbl_805650F0;
extern int lbl_804DB780[];
extern void DCStoreRange(void *, int);
extern char lbl_8034CD48[];
extern char lbl_8034CD30[];
extern void fn_802E317C(const char *, ...);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034CEE4[];
extern int lbl_804DB790[];
extern int lbl_804DB7D0[];
extern int lbl_8055FF00;
extern int lbl_8055FEF8;
extern unsigned int lbl_8055FEFC;
extern unsigned long long __div2i(unsigned long long, unsigned long long);
typedef unsigned long long u64;
extern u64 fn_802E2C9C(void);
extern u64 OSGetTime(void);
struct OSTimeCalendar {
    int sec;
    int min;
    int hour;
    int mday;
    int month;
    int year;
    int wday;
    int yday;
    int msec;
};
extern void OSTicksToCalendarTime(u64, struct OSTimeCalendar *);
void fn_802E1728(void *arg0) {
    int value = *(int *)((char *)arg0 + 0x178);
    if (value != 0) {
        fn_80120084(value);
        *(int *)((char *)arg0 + 0x178) = 0;
    }
}

#pragma scheduling invalid_target
#pragma dont_inline on
unsigned int fn_802E176C(unsigned int arg0) {
    return 1U << (32 - __cntlzw(arg0));
}
#pragma scheduling invalid_target
void fn_802E1780(void *arg0, unsigned int arg1, int arg2) {
    unsigned int count = arg1 >> 3;
    int x = 0;
    int y = 0;
    int row;

    for (row = 0; row < 4; row++) {
        int rowOffset = row * arg2;
        int i;
        for (i = 0; i < count; i++) {
            int offset = (i + rowOffset) * 2;
            int yMinusRow = y - row;
            ((unsigned char *)arg0)[offset] = (unsigned char)(x - i + 0x80);
            y++;
            ((unsigned char *)arg0)[offset + 1] = (unsigned char)(yMinusRow + 0x80);
            if (y == 4) {
                y = 0;
                x++;
            }
        }
    }
}
#pragma optimization_level 2
#pragma use_lmw_stmw off
#pragma dont_inline on
int fn_802E1804(void *dst, void *src, int count, int outerBytes, int stride)
{
    register unsigned int row;
    register unsigned int outer;
    register unsigned int dstOffset;
    register unsigned int outerCount;
    register unsigned int innerCount;
    register unsigned int total3;
    register unsigned int total2;
    register unsigned int total;

    total = (unsigned int)count * (unsigned int)stride;
    outerCount = (unsigned int)outerBytes >> 2;
    innerCount = total >> 3;
    total2 = total << 1;
    total3 = (total << 2) - total;
    dstOffset = 0;
    outer = 0;
    row = 0;

    for (; outer < outerCount; outer++) {
        unsigned int srcOffset = row * total;
        unsigned int i = innerCount;
        if (i != 0) {
            do {
                unsigned int *s = (unsigned int *)((char *)src + srcOffset);
                unsigned int *d = (unsigned int *)((char *)dst + dstOffset);
                d[0] = s[0];
                d[1] = s[1];
                d[2] = *(unsigned int *)((char *)s + total);
                d[3] = *(unsigned int *)((char *)s + total + 4);
                d[4] = *(unsigned int *)((char *)s + total2);
                d[5] = *(unsigned int *)((char *)s + total2 + 4);
                d[6] = *(unsigned int *)((char *)s + total3);
                d[7] = *(unsigned int *)((char *)s + total3 + 4);
                dstOffset += 0x20;
                srcOffset += 8;
            } while (--i != 0);
        }
        row += 4;
    }
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma optimization_level reset
int fn_802E18D4(int arg0, int arg1, int arg2, int arg3, void *arg4, int arg5) {
    GXInitTexObj((GXTexObj *)arg4, (void *)arg5, (unsigned short)arg0, (unsigned short)arg1,
                 arg2, arg3, arg3, 0);
    GXInitTexObjLOD((GXTexObj *)arg4, 0, 0, 0, 0, 0,
                    lbl_805650F0, lbl_805650F0, lbl_805650F0);
    return 1;
}
#pragma scheduling on
int fn_802E1954(int arg0) { return (arg0 + 0x7F) & 0xFFFFFF80; }

unsigned int fn_802E1960(unsigned int arg0) {
    unsigned int result = ((arg0 >> 3) + 3) & ~3;
    if ((result & (result - 1)) != 0)
        return fn_802E176C(result);
    return result;
}

void fn_802E1A38(void *arg0, int arg1) {
    int result;
    result = fn_802E1980(arg1, (char *)arg0 + 0x190, (char *)arg0 + 0x180, (char *)arg0 + 0x184, *(int *)((char *)arg0 + 0x104));
    fn_802E1980(arg1 + result, (char *)arg0 + 0x1b0, (char *)arg0 + 0x188, (char *)arg0 + 0x18c, *(int *)((char *)arg0 + 0x10c));
}

extern int fn_802E1954(int);
extern unsigned int fn_802E1960(unsigned int);
#pragma optimization_level 2
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_802E1A9C(void *arg0, int *arg1, int *arg2, int *arg3, int *arg4, int *arg5, int *arg6, int *arg7, int arg8) {
    int d, e, f, g;
    int width, height;
    int a, b, c;
    int sum, out;
    a = *(int *)((char *)arg0 + 0x18) ? *(int *)((char *)arg0 + 4) : 0;
    b = *(int *)((char *)arg0 + 0x3C) ? *(int *)((char *)arg0 + 4) : 0;
    c = *(int *)((char *)arg0 + 0x24) ? *(int *)((char *)arg0 + 0xC) : 0;
    width = *(int *)((char *)arg0 + 8);
    height = *(int *)((char *)arg0 + 0x10);
    d = fn_802E1954(a * width);
    e = fn_802E1954(b * width);
    f = fn_802E1954(c * height);
    g = fn_802E1954(fn_802E1960(*(int *)((char *)arg0 + 0xC)) << 3);
    out = fn_802E1954(fn_802E1960(*(int *)((char *)arg0 + 4)) << 3);
    out += g;
    *arg5 = out;
    sum = d + e;
    *arg3 = d;
    *arg1 = sum;
    *arg2 = f + sum;
    *arg4 = sum + (f << 1);
    *arg6 = a | b;
    *arg7 = c;
}
#pragma use_lmw_stmw reset
#pragma optimization_level reset
#pragma push
#pragma scheduling invalid_target
int fn_802E1BB4(register void *arg0, int arg1) {
    typedef void (*Calc)(void *, int *, int *, int *, int *, int *, int *, int *);
    int sp20, sp1C, sp18, sp14, sp10, spC, sp8;
    register int temp;
    register int i;
    register char *slot;
    register char *dest;
    register unsigned char *p;
    (void)arg1;
    ((Calc)fn_802E1A9C)((char *)arg0 + 0x100, &sp20, &sp1C, &sp18, &sp14, &sp10, &spC, &sp8);
    temp = fn_8011FFC4(sp10 + sp14 * *(int *)((char *)arg0 + 0x100) + 0x7F, sp14);
    if (temp == 0) goto fail;

    *(int *)((char *)arg0 + 0x178) = temp;
    p = (unsigned char *)(((unsigned int)temp + 0x7F) & ~0x7F);
    slot = (char *)arg0;
    dest = (char *)arg0;
    for (i = 0; i < *(int *)((char *)arg0 + 0x100); i++, slot += 0x30, dest += 0x80, p += sp14) {
        if (*(int *)(slot + 0x118) != 0) {
            *(int *)(slot + 0x11C) = (int)p;
            *(int *)(slot + 0x120) = spC;
            if (!fn_802E18D4(spC, *(int *)((char *)arg0 + 0x108), 1, 0, dest, (int)p)) goto fail;
        }
        if (*(int *)(slot + 0x124) != 0) {
            *(int *)(slot + 0x128) = (int)p + sp20;
            *(int *)(slot + 0x12C) = sp8;
            if (!fn_802E18D4(sp8, *(int *)((char *)arg0 + 0x110), 1, 0, dest + 0x20, (int)p + sp20)) goto fail;
        }
        if (*(int *)(slot + 0x130) != 0) {
            *(int *)(slot + 0x134) = (int)p + sp1C;
            *(int *)(slot + 0x138) = sp8;
            if (!fn_802E18D4(sp8, *(int *)((char *)arg0 + 0x110), 1, 0, dest + 0x40, (int)p + sp1C)) goto fail;
        }
        if (*(int *)(slot + 0x13C) != 0) {
            *(int *)(slot + 0x140) = (int)p + sp18;
            *(int *)(slot + 0x144) = spC;
            if (!fn_802E18D4(spC, *(int *)((char *)arg0 + 0x108), 1, 0, dest + 0x60, (int)p + sp18)) goto fail;
        }
    }
    *(int *)((char *)arg0 + 0x17C) = sp14;
    fn_802E1A38(arg0, (int)p);
    return 1;

fail:
    fn_802E1728(arg0);
    return 0;
}
#pragma pop

void fn_802E27A0(void *arg0) {
    DCStoreRange(*(void **)((char *)arg0 + *(int *)((char *)arg0 + 0x114) * 0x30 + 0x11C),
                 *(int *)((char *)arg0 + 0x17C));
}

#pragma dont_inline reset
void fn_802E27B8(void *arg0) {
    int index = *(int *)((char *)arg0 + 0x114) + 1;
    if (index >= *(int *)((char *)arg0 + 0x100))
        index = 0;
    if (*(int *)((char *)arg0 + 0x1D0 + index * 4))
        *(int *)((char *)arg0 + 0x1D0 + index * 4) = 0;
}

#pragma scheduling invalid_target
void fn_802E27F0(void) {
    extern char lbl_8034CD00[];
    int local[2];
    int **heap = (int **)lbl_804DB780;
    int size;
    register int count;
    register int i;

    lbl_804DB780[0] = 0x7400;
    heap[1] = local;
    size = lbl_804DB780[0];
    fn_802E30C8(lbl_8034CD00, size / 1024, local);
    count = lbl_804DB780[0] / 4;
    for (i = 0; i < count; i++) {
        (*(int **)((char *)lbl_804DB780 + 4))[-i] = 0x53FFEEDD;
    }
    *(int **)((char *)lbl_804DB780 + 8) =
        (int *)((char *)(*(int **)((char *)lbl_804DB780 + 4)) +
                (-(count - 1) * 4));
}
#pragma scheduling on
void fn_802E29AC(void) {
    int count = *(int *)lbl_804DB780;
    int *array = *(int **)((char *)lbl_804DB780 + 4);
    int i;
    int n = count >> 2;
    for (i = n - 1; i >= 0; --i) {
        if (array[-i] != 0x53ffeedd) {
            fn_802E30C8(lbl_8034CD30, (i * 4) >> 10, count >> 10);
            return;
        }
    }
}

void fn_802E2A1C(void) {
    int **p = (int **)((char *)lbl_804DB780 + 8);
    if (*p == 0)
        return;
    if (**p == 0x53ffeedd)
        return;
    fn_802E317C(lbl_8034CD48);
}

void fn_802E2A54(void) {}

void fn_802E2A58(void) {}

extern void OSInit(void);
extern void LCEnable(void);
extern void fn_8005954C(void);
extern void fn_802E77A8(void);
extern void fn_802E3498(void);
extern void fn_801293B4(void);
extern void fn_802E302C(void);
extern void fn_802E2A54(void);
extern void fn_8012820C(int);
extern void fn_802E98D0(void);
extern void fn_802E7318(void);
extern void fn_802E46B0(void);
extern void fn_80127C8C(void);
extern void fn_802E8CA8(void);
extern void fn_80127538(void);
extern void fn_80129790(void);
extern void fn_802E5478(void);
extern void fn_802E7578(void);
extern void fn_802EBE2C(void);
extern void fn_802CF600(void);
extern void fn_802EC614(void);
extern void fn_802E2CFC(void *);
extern void fn_802E27F0(void);
extern void fn_80127C90(void *, void *);
extern char lbl_8034CCE0[];
#pragma scheduling invalid_target
int fn_802E2A5C(void) {
    unsigned short local[12];
    register char *base;
    base = lbl_8034CCE0;
    OSInit(); fn_8005954C(); LCEnable(); fn_802E77A8(); fn_802E3498();
    fn_801293B4(); fn_802E302C(); fn_802E2A54(); fn_8012820C(0x02000000);
    fn_802E98D0(); fn_802E7318(); fn_802E46B0(); fn_80127C8C();
    fn_802E8CA8(); fn_80127538(); fn_80129790(); fn_802E5478();
    fn_802E7578(); fn_802EBE2C(); fn_802CF600(); fn_802EC614();
    fn_802E2CFC(local);
    fn_802E30C8(base + 0x78, local[1], local[2], local[0], *(int *)((char *)local + 0x10));
    fn_802E30C8(base + 0x8C, local[3], local[4], local[5]);
    fn_802E27F0();
    fn_80127C90(fn_802E2A1C, base + 0xA0);
    return 1;
}
extern void DCStoreRange(void *, int);
extern void fn_80127D58(void *);
extern void fn_802E29AC(void);
extern void fn_802EC7AC(void);
extern void fn_802CFBA8(void);
extern void fn_802EC038(void);
extern void fn_802E759C(void);
extern void fn_802E56F0(void);
extern void fn_80129864(void);
extern void fn_801275AC(void);
extern void fn_802E8D2C(void);
extern void fn_80127EF8(void);
extern void fn_802E46E4(void);
extern void fn_802E7330(void);
extern void fn_802E99A8(void);
extern void fn_801282A0(void);
extern void fn_802E2A58(void);
extern void fn_802E3090(void);
extern void fn_801293C4(void);
extern void fn_802E34DC(void);
extern void fn_802E77AC(void);
extern void fn_802E2A1C(void);
extern int fn_80004D64(void *);
extern int fn_802E2A5C(void);
extern void fn_80004E20(void);
extern void fn_802E2B34(void);
extern void OSPanic(const char *, int, const char *, ...);
extern char lbl_8034CD8C[];
extern char lbl_8055D174[];
int main(void) {
    int local[0x41];
    int i;
    do {
        *(int *)&local[1] = 0;
        *(int *)&local[2] = 0;
        i += 2;
    } while (i != 0x40);
    if (fn_80004D64(&local[2]) != 0) {
        if (fn_802E2A5C() != 0) {
            fn_80004E20();
            fn_802E2B34();
        }
    }
    OSPanic(lbl_8034CD8C, 0xD2, lbl_8055D174);
    return 0;
}

#pragma scheduling invalid_target
unsigned int fn_802E2C20(void) {
    unsigned long long now;
    unsigned long long diff;
    register unsigned int baseHigh;
    register unsigned int baseLow;
    register unsigned int ticks;
    register unsigned int factor;
    now = OSGetTime();
    if ((*(volatile int *)&lbl_8055FEF8 | *(volatile unsigned int *)&lbl_8055FEFC) == 0) {
        *(volatile unsigned int *)&lbl_8055FEFC = (unsigned int)now;
        *(volatile int *)&lbl_8055FEF8 = (unsigned int)(now >> 32);
    }
    baseLow = *(volatile unsigned int *)&lbl_8055FEFC;
    ticks = *(volatile unsigned int *)0x800000F8;
    factor = (ticks >> 2) / 1000;
    baseHigh = *(volatile unsigned int *)&lbl_8055FEF8;
    diff = now - (((unsigned long long)baseHigh << 32) | baseLow);
    return (unsigned int)__div2i(diff, factor);
}
#pragma scheduling on
extern int lbl_8055FEF8;
extern unsigned int lbl_8055FEFC;
extern unsigned long long __div2i(unsigned long long, unsigned long long);
#pragma scheduling invalid_target
unsigned long long fn_802E2C9C(void) {
    unsigned long long now = OSGetTime();
    unsigned long long start = ((unsigned long long)(unsigned int)lbl_8055FEF8 << 32) | lbl_8055FEFC;
    unsigned long long elapsed = now - start;
    unsigned int busClock = *(volatile unsigned int *)0x800000F8;
    unsigned int scale = (busClock >> 2) / 125000;
    return __div2i(elapsed << 3, scale);
}
#pragma scheduling on
void fn_802E2CFC(void *arg0) {
    struct OSTimeCalendar calendar;
    OSTicksToCalendarTime(OSGetTime(), &calendar);
    *(short *)((char *)arg0 + 0xA) = (short)calendar.sec;
    *(short *)((char *)arg0 + 0x8) = (short)calendar.min;
    *(short *)((char *)arg0 + 0x6) = (short)calendar.hour;
    *(short *)((char *)arg0 + 0x4) = (short)calendar.mday;
    *(short *)((char *)arg0 + 0x2) = (short)(calendar.month + 1);
    *(short *)((char *)arg0 + 0x0) = (short)calendar.year;
    *(int *)((char *)arg0 + 0x10) = calendar.wday;
    *(int *)((char *)arg0 + 0xC) = calendar.msec;
}

#pragma scheduling invalid_target
u64 fn_802E2D74(int arg0) {
    long long limit = (long long)arg0 * 1000;
    u64 start = fn_802E2C9C();
    u64 now;
    do {
        now = fn_802E2C9C();
    } while ((long long)(now - start) < limit && (long long)now >= (long long)start);
    return now;
}
#pragma scheduling on
void fn_802E2E0C(int arg0, int arg1) {
    int index = lbl_8055FF00;
    lbl_8055FF00 = index + 1;
    lbl_804DB790[index] = arg0;
    lbl_804DB7D0[index] = arg1;
}
#pragma push
#pragma scheduling invalid_target
void fn_802E2E38(int arg0) {
    typedef int (*Callback)(int, int);
    extern char lbl_8034CCE0[];
    extern int lbl_804DB790[], lbl_804DB7D0[], lbl_8055FF00;
    extern int fn_80039840(void), fn_802D9BF0(void), fn_802D9C04(void), fn_8005EE7C(void);
    extern void fn_800527CC(int), fn_8005ED8C(void), OSReturnToMenu(void), OSShutdownSystem(void);
    Callback *cursor;
    char *text = lbl_8034CCE0;
    int i;
    int j;

    fn_802E30C8(text + 0xB8);
    cursor = (Callback *)lbl_804DB790;
    for (i = 0; i < lbl_8055FF00; i++, cursor++) {
        if ((*cursor)(0, arg0) == 1) {
            fn_802E30C8(text + 0xCC, lbl_804DB7D0[i]);
            return;
        }
    }
    fn_802E30C8(text + 0xE4);
    j = lbl_8055FF00 - 1;
    cursor = (Callback *)lbl_804DB790 + j;
    for (; j >= 0; j--, cursor--) {
        (*cursor)(1, arg0);
    }
    fn_802E30C8(text + 0xFC);
    if (fn_80039840()) fn_802E30C8(text + 0x118);
    fn_802E30C8(text + 0x12C, arg0);
    if (arg0 == 0) {
        if (fn_802D9BF0() == 0 || fn_802D9C04() != 0) {
            fn_802E30C8(text + 0x13C);
            fn_800527CC(0);
        } else {
            fn_802E30C8(text + 0x154);
            OSReturnToMenu();
        }
        return;
    }
    if (arg0 == 2) {
        fn_802E30C8(text + 0x184);
        fn_8005ED8C();
        fn_802E30C8(text + 0x1A0);
        while (fn_8005EE7C() == 4) {}
        fn_802E30C8(text + 0x1C8);
        OSShutdownSystem();
        return;
    }
    fn_802E30C8(text + 0x1E4);
    OSReturnToMenu();
}
#pragma pop

void fn_802E300C(int arg0) {
    ((void (*)(const char *, int))fn_802E317C)(lbl_8034CEE4, arg0);
}

extern unsigned int fn_802E176C(unsigned int);
extern void fn_802E1780(void *, unsigned int, int);
extern int fn_802E1804(void *, void *, int, int, int);
extern int fn_802E18D4(int, int, int, int, void *, int);
extern void DCFlushRange(void *, int);

extern void DCStoreRange(void *, int);
extern void fn_80127D58(void *);
extern void fn_802E29AC(void);
extern void fn_802EC7AC(void);
extern void fn_802CFBA8(void);
extern void fn_802EC038(void);
extern void fn_802E759C(void);
extern void fn_802E56F0(void);
extern void fn_80129864(void);
extern void fn_801275AC(void);
extern void fn_802E8D2C(void);
extern void fn_80127EF8(void);
extern void fn_802E46E4(void);
extern void fn_802E7330(void);
extern void fn_802E99A8(void);
extern void fn_801282A0(void);
extern void fn_802E3090(void);
extern void fn_801293C4(void);
extern void fn_802E34DC(void);
extern void fn_802E77AC(void);
extern int fn_80004D64(void *);
extern int fn_802E2A5C(void);
extern void fn_80004E20(void);
extern void OSPanic(const char *, int, const char *, ...);
extern char lbl_8034CD8C[];
extern char lbl_8055D174[];
extern void fn_802E2B34(void);

