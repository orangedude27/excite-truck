// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804DB780[];
extern char lbl_8034CD48[];
extern char lbl_8034CD30[];
extern void fn_802E317C(const char *, ...);
extern void fn_802E30C8(const char *, int, int);
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

unsigned int fn_802E176C(unsigned int arg0) {
    return 1U << (32 - __cntlzw(arg0));
}

void fn_802E1780(void *arg0, unsigned int arg1, int arg2) {
    int x;
    int y;
    int row;

    x = 0;
    y = 0;
    for (row = 0; row < 4; row++) {
        int i;
        for (i = 0; i < (arg1 >> 3); i++) {
            unsigned char *p = (unsigned char *)arg0 + (i + row * arg2) * 2;
            p[0] = (unsigned char)(x - i + 0x80);
            y++;
            p[1] = (unsigned char)(y - row - 1 + 0x80);
            if (y == 4) {
                y = 0;
                x++;
            }
        }
    }
}

int fn_802E1954(int arg0) { return (arg0 + 0x7F) & 0xFFFFFF80; }

void fn_802E1A38(void *arg0, int arg1) {
    int result;
    result = fn_802E1980(arg1, (char *)arg0 + 0x190, (char *)arg0 + 0x180, (char *)arg0 + 0x184, *(int *)((char *)arg0 + 0x104));
    fn_802E1980(arg1 + result, (char *)arg0 + 0x1b0, (char *)arg0 + 0x188, (char *)arg0 + 0x18c, *(int *)((char *)arg0 + 0x10c));
}

void fn_802E27B8(void *arg0) {
    int index = *(int *)((char *)arg0 + 0x114) + 1;
    if (index >= *(int *)((char *)arg0 + 0x100))
        index = 0;
    if (*(int *)((char *)arg0 + 0x1D0 + index * 4))
        *(int *)((char *)arg0 + 0x1D0 + index * 4) = 0;
}

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
    int *p = &local[1];
    int i;
    for (i = 0; i < 0x20; i++) {
        p[0] = 0;
        p[1] = 0;
        p += 2;
    }
    if (fn_80004D64(&local[2]) != 0) {
        if (fn_802E2A5C() != 0) {
            fn_80004E20();
            fn_802E2B34();
        }
    }
    OSPanic(lbl_8034CD8C, 0xD2, lbl_8055D174);
    return 0;
}

extern int lbl_8055FEF8;
extern unsigned int lbl_8055FEFC;
extern unsigned long long __div2i(unsigned long long, unsigned long long);
unsigned long long fn_802E2C9C(void) {
    unsigned long long now = OSGetTime();
    unsigned int lo = (unsigned int)now - lbl_8055FEFC;
    unsigned int hi = (unsigned int)(now >> 32) - (unsigned int)lbl_8055FEF8 - ((unsigned int)now < lbl_8055FEFC);
    unsigned int ticks = *(volatile unsigned int *)0x800000F8;
    unsigned int factor = (unsigned int)(((unsigned long long)(ticks >> 2) * 0x431bde83U) >> 32) >> 15;
    return __div2i(((unsigned long long)hi << 32 | lo) << 3, factor);
}

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

u64 fn_802E2D74(int arg0) {
    long long limit = (long long)arg0 * 1000;
    u64 start = fn_802E2C9C();
    u64 now;
    do { now = fn_802E2C9C(); } while ((long long)(now - start) < limit);
    return now - start;
}

void fn_802E2E0C(int arg0, int arg1) {
    int index = lbl_8055FF00;
    *(volatile int *)&lbl_8055FF00 = index + 1;
    lbl_804DB790[index] = arg0;
    lbl_804DB7D0[index] = arg1;
}

void fn_802E300C(int arg0) {
    ((void (*)(const char *, int))fn_802E317C)(lbl_8034CEE4, arg0);
}

extern unsigned int fn_802E176C(unsigned int);
extern void fn_802E1780(void *, unsigned int, int);
extern int fn_802E1804(void *, void *, int, int, int);
extern int fn_802E18D4(int, int, int, int, void *, void *);
extern void DCFlushRange(void *, int);
typedef struct { char data[0x20]; } GXTexObj;
extern void GXInitTexObj(GXTexObj *, void *, unsigned short, unsigned short, int, int, int, int);
extern void GXInitTexObjLOD(GXTexObj *, int, int, int, int, int, float, float, float);
extern float lbl_805650F0;
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

