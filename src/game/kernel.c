// kernel.cpp — engine kernel: stack check, PlatExitProcess, video/canvas init.
// Recovered TU window 0x802E1728..0x802E3028 (see docs/attribution_analysis.md):
// assert string "kernel.cpp". Static-init thunk fn_802E3020 (+ .ctors slot
// 0x802ED5E8) remains in auto/text_802E3020_.c pending a promotion pass.

typedef struct { char data[0x20]; } GXTexObj;
extern void GXInitTexObj(GXTexObj *, void *, unsigned short, unsigned short, int, int, int, int);
extern void GXInitTexObjLOD(GXTexObj *, int, int, int, int, int, float, float, float);
extern float lbl_805650F0;
extern int lbl_804DB780[];
extern void DCStoreRange(void *, int);
extern void DCFlushRange(void *, int);
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
/* The Revolution OS calendar (OSCalendarTime) OSTicksToCalendarTime() fills;
 * months count from 0 and the microsecond field is not read here. */
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
    register int row;
    for (row = 0; row < 4; row++) {
        int rowOffset = row * arg2;
        int i;
        for (i = 0; i < (int)count; i++) {
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
int fn_802E18D4(int width, int height, int format, int wrapMode, void *texObj, int imagePtr) {
    /* Initialize a GX texture object and set all LOD parameters to zero. */
    GXInitTexObj((GXTexObj *)texObj, (void *)imagePtr, (unsigned short)width, (unsigned short)height,
                 format, wrapMode, wrapMode, 0);
    GXInitTexObjLOD((GXTexObj *)texObj, 0, 0, 0, 0, 0,
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

#pragma use_lmw_stmw off
/* Builds a 4-row IA8 lookup texture (width rounded up to a power of two for size),
   tiles and flushes its image data into imagePtr, initializes texObj, and returns
   the 128-byte-aligned byte size. */
int fn_802E1980(int imagePtr, void *texObj, void *outWidth, void *outHeight, unsigned int size) {
    unsigned char linearBuf[0x800];
    int width;
    int alignedBytes;

    width = fn_802E1960(size);
    *(int *)outWidth = width;
    *(int *)outHeight = 4;
    alignedBytes = fn_802E1954(width << 3);
    fn_802E1780(linearBuf, size, width);
    fn_802E1804((void *)imagePtr, linearBuf, width, 4, 2);
    DCFlushRange((void *)imagePtr, alignedBytes);
    fn_802E18D4(width, 4, 3, 1, texObj, imagePtr);
    return alignedBytes;
}
#pragma use_lmw_stmw reset
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
/* Computes aligned layout sizes/offsets for a texture/image block descriptor.
 * Selects width/height factors from descriptor flags, rounds dimensions via
 * fn_802E1954/fn_802E1960, and outputs combined byte spans and factor flags. */
void fn_802E1A9C(void *desc, int *outCombinedWidth, int *outCombinedPlusHeight, int *outAlignedWidthA, int *outCombinedPlusDoubleHeight, int *outTotalAlignedBytes, int *outWidthFactorMask, int *outHeightFactor, int unused) {
    int alignedWidthA, alignedWidthB, alignedHeight, alignedDimC;
    int baseWidth, baseHeight;
    int widthFactorA, widthFactorB, heightFactor;
    int combinedWidth, totalAlignedBytes;
    widthFactorA = *(int *)((char *)desc + 0x18) ? *(int *)((char *)desc + 4) : 0;
    widthFactorB = *(int *)((char *)desc + 0x3C) ? *(int *)((char *)desc + 4) : 0;
    heightFactor = *(int *)((char *)desc + 0x24) ? *(int *)((char *)desc + 0xC) : 0;
    baseWidth = *(int *)((char *)desc + 8);
    baseHeight = *(int *)((char *)desc + 0x10);
    alignedWidthA = fn_802E1954(widthFactorA * baseWidth);
    alignedWidthB = fn_802E1954(widthFactorB * baseWidth);
    alignedHeight = fn_802E1954(heightFactor * baseHeight);
    alignedDimC = fn_802E1954(fn_802E1960(*(int *)((char *)desc + 0xC)) << 3);
    totalAlignedBytes = fn_802E1954(fn_802E1960(*(int *)((char *)desc + 4)) << 3);
    totalAlignedBytes += alignedDimC;
    *outTotalAlignedBytes = totalAlignedBytes;
    combinedWidth = alignedWidthA + alignedWidthB;
    *outAlignedWidthA = alignedWidthA;
    *outCombinedWidth = combinedWidth;
    *outCombinedPlusHeight = alignedHeight + combinedWidth;
    *outCombinedPlusDoubleHeight = combinedWidth + (alignedHeight << 1);
    *outWidthFactorMask = widthFactorA | widthFactorB;
    *outHeightFactor = heightFactor;
}
#pragma use_lmw_stmw reset
#pragma optimization_level reset
#pragma push
#pragma scheduling invalid_target
int fn_802E1BB4(void *arg0, int arg1) {
    typedef void (*Calc)(void *, int *, int *, int *, int *, int *, int *, int *);
    int sp20, sp1C, sp18, sp14, sp10, spC, sp8;
    int temp;
    int i;
    char *slot;
    char *dest;
    unsigned char *p;
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

void fn_802E1DA4(void *arg0, unsigned int arg1, unsigned int arg2, float f0, float f1, float f2, float f3, float f4) {
    (void)arg1; (void)arg2; (void)f0; (void)f1; (void)f2; (void)f3;
    if (f4 == lbl_805650F0) {
        *(int *)arg0 = 1;
    } else {
        *(int *)arg0 = 0;
    }
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
    int n;

    lbl_804DB780[0] = 0x7400;
    heap[1] = local;
    size = lbl_804DB780[0];
    fn_802E30C8(lbl_8034CD00, size / 1024, local);
    count = lbl_804DB780[0] / 4;
    n = count;
    for (i = 0; i < n; i++) {
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
    int n = count / 4;
    for (i = n - 1; i >= 0; --i) {
        if (array[-i] != 0x53ffeedd) {
            fn_802E30C8(lbl_8034CD30, (i * 4) / 1024, count / 1024);
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

/* The halfword-packed calendar fn_802E2CFC writes (struct OSTimeCalendar above
 * compressed into the 0x18 bytes the start-up log prints from). */
struct StartupCalendar {
    unsigned short year;     /* 0x00 */
    unsigned short month;    /* 0x02, 1-12 */
    unsigned short day;      /* 0x04 */
    unsigned short hour;     /* 0x06 */
    unsigned short minute;   /* 0x08 */
    unsigned short second;   /* 0x0A */
    int msec;                /* 0x0C */
    int weekDay;             /* 0x10 */
    unsigned short pad14[2]; /* 0x14 */
};

/* The strings of this file's block at lbl_8034CCE0 that start-up logs with. */
#define KERNEL_DATE_FORMAT (base + 0x78) /* "date: %d/%d/%d (%d)" */
#define KERNEL_TIME_FORMAT (base + 0x8C) /* "time: %d:%02d:%02d" */
#define KERNEL_STACK_CHECK_NAME (base + 0xA0) /* "check_stack" */

#pragma scheduling on
/* Start-up: bring up the OS and every engine subsystem in order, log the date and time
 * the game started, then arm the stack watermark check - fn_802E27F0 fills the guard
 * area with 0x53FFEEDD and fn_802E2A1C, registered under the name "check_stack",
 * reports "STACK OVERRUN!" once that marker is gone.  Returning 1 is main()'s cue to
 * run the matching shutdown (fn_802E2B34) and panic. */
int fn_802E2A5C(void) {
    struct StartupCalendar now;
    char * const base = lbl_8034CCE0;
    OSInit();
    fn_8005954C();
    LCEnable();
    fn_802E77A8();
    fn_802E3498();
    fn_801293B4();
    fn_802E302C();
    fn_802E2A54();
    fn_8012820C(0x02000000);
    fn_802E98D0();
    fn_802E7318();
    fn_802E46B0();
    fn_80127C8C();
    fn_802E8CA8();
    fn_80127538();
    fn_80129790();
    fn_802E5478();
    fn_802E7578();
    fn_802EBE2C();
    fn_802CF600();
    fn_802EC614();
    fn_802E2CFC(&now);
    fn_802E30C8(KERNEL_DATE_FORMAT, now.month, now.day, now.year, now.weekDay);
    fn_802E30C8(KERNEL_TIME_FORMAT, now.hour, now.minute, now.second);
    fn_802E27F0();
    fn_80127C90(fn_802E2A1C, KERNEL_STACK_CHECK_NAME);
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
void fn_802E2B34(void) {
    fn_80127D58((void *)fn_802E2A1C);
    fn_802E29AC();
    fn_802EC7AC();
    fn_802CFBA8();
    fn_802EC038();
    fn_802E759C();
    fn_802E56F0();
    fn_80129864();
    fn_801275AC();
    fn_802E8D2C();
    fn_80127EF8();
    fn_802E46E4();
    fn_802E7330();
    fn_802E99A8();
    fn_801282A0();
    fn_802E2A58();
    fn_802E3090();
    fn_801293C4();
    fn_802E34DC();
    fn_802E77AC();
}
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
    unsigned int baseHigh;
    unsigned int baseLow;
    unsigned int ticks;
    unsigned int factor;
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
    unsigned long long elapsed = now - *(unsigned long long *)&lbl_8055FEF8;
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
    for (;;) {
        now = fn_802E2C9C();
        if ((long long)(now - start) >= limit || (long long)now < (long long)start) {
            break;
        }
    }
    return now;
}
#pragma scheduling on
void fn_802E2E0C(int arg0, int arg1) {
    int index = lbl_8055FF00;
    lbl_8055FF00 = index + 1;
    lbl_804DB790[index] = arg0;
    lbl_804DB7D0[index] = arg1;
}
/* Reset / power-down.
 * A subsystem that has to wind down before the console leaves the game
 * registers with fn_802E2E0C(callback, name):
 *   lbl_804DB790[]  the registered callbacks
 *   lbl_804DB7D0[]  the name a callback logs under when it cancels a reset
 *   lbl_8055FF00    how many are registered
 * fn_802E2E38 runs the table, then resets. */
typedef int (*ResetCallback)(int request, int mode);

/* First argument handed to a reset callback. */
#define KERNEL_RESET_ASK 0 /* may we reset?  answer 1 to cancel it */
#define KERNEL_RESET_NOTIFY 1 /* the reset is on: save, close, stop */

/* The mode fn_802E2E38 is asked for (the Home Menu hands back its own). */
#define KERNEL_MODE_RESTART 0 /* hot-reset the console */
#define KERNEL_MODE_MENU 1 /* back to the Wii Menu */
#define KERNEL_MODE_STANDBY 2 /* power the console off */

/* WPAD keeps reporting this while the controllers are still powering down. */
#define KERNEL_WPAD_SHUTTING_DOWN 4

/* The strings of this file's block at lbl_8034CCE0 that the reset path logs with. */
#define KERNEL_LOG_RESET_BEGIN (base + 0xB8) /* "resetting system..." */
#define KERNEL_LOG_CANCELLED (base + 0xCC) /* " reset cancelled by %s" */
#define KERNEL_LOG_RESET_OKAY (base + 0xE4) /* "kernel: reset is okay" */
#define KERNEL_LOG_CANCEL_DVD (base + 0xFC) /* "kernel: cancelling DVD..." */
#define KERNEL_LOG_DVD_FAIL (base + 0x118) /* "DVDCancelAll fails" */
#define KERNEL_LOG_RESET_MODE (base + 0x12C) /* "doing reset %d" */
#define KERNEL_LOG_RESTART (base + 0x13C) /* "kernel: doing restart" */
#define KERNEL_LOG_DISC_ERROR (base + 0x154) /* "kernel: restart during disk error (go to menu)" */
#define KERNEL_LOG_POWER_DOWN (base + 0x184) /* "kernel: doing power down" */
#define KERNEL_LOG_WAIT_WPAD (base + 0x1A0) /* "kernel: waiting for WPAD to shut down" */
#define KERNEL_LOG_WPAD_DOWN (base + 0x1C8) /* "kernel: WPAD has shut down" */
#define KERNEL_LOG_MENU (base + 0x1E4) /* "kernel: doing return to menu" */

extern int fn_80039840(void); /* DVDCancelAll: non-zero when the cancel failed */
extern int fn_802D9BF0(void); /* the disc/drive error state is set */
extern int fn_802D9C04(void); /* that state is 1: the reset button, not a bad disc */
extern int fn_8005EE7C(void); /* WPAD shutdown status */
extern void fn_800527CC(int); /* OSReset: hot-reset the console */
extern void fn_8005ED8C(void); /* WPADiClose: start the controllers powering down */
extern void OSReturnToMenu(void);
extern void OSShutdownSystem(void);

#pragma push
#pragma scheduling invalid_target
/* Leave the game and hand the console back, in `mode`: KERNEL_MODE_RESTART
 * hot-resets, KERNEL_MODE_STANDBY powers off and anything else returns to the
 * Wii Menu.  Every subsystem registered a reset callback with fn_802E2E0C;
 * each is first asked whether the reset may go ahead - the first one to answer
 * 1 cancels the whole thing and is named in the log - and otherwise told, last
 * registered first, that it is happening.  The DVD drive's queued requests are
 * cancelled next, and a restart falls back to the Wii Menu when the disc is
 * misbehaving rather than the reset button having been held. */
void fn_802E2E38(int mode) {
    char *base = lbl_8034CCE0;
    ResetCallback *callback;
    ResetCallback *last;
    int i;
    int n;

    /* Ask every subsystem whether the reset may go ahead. */
    fn_802E30C8(KERNEL_LOG_RESET_BEGIN);
    callback = (ResetCallback *)lbl_804DB790;
    for (i = 0; i < lbl_8055FF00; callback++, i++) {
        if ((*callback)(KERNEL_RESET_ASK, mode) == 1) {
            fn_802E30C8(KERNEL_LOG_CANCELLED, (const char *)lbl_804DB7D0[i]);
            return;
        }
    }
    /* Nobody objected: tell them all, last registered first. */
    fn_802E30C8(KERNEL_LOG_RESET_OKAY);
    n = lbl_8055FF00 - 1;
    last = (ResetCallback *)lbl_804DB790 + n;
    for (; n >= 0; last--, n--) {
        (*last)(KERNEL_RESET_NOTIFY, mode);
    }
    fn_802E30C8(KERNEL_LOG_CANCEL_DVD);
    if (fn_80039840()) fn_802E30C8(KERNEL_LOG_DVD_FAIL);
    fn_802E30C8(KERNEL_LOG_RESET_MODE, mode);
    if (mode == KERNEL_MODE_RESTART) {
        if (fn_802D9BF0() == 0 || fn_802D9C04() != 0) {
            fn_802E30C8(KERNEL_LOG_RESTART);
            fn_800527CC(0);
        } else {
            fn_802E30C8(KERNEL_LOG_DISC_ERROR);
            OSReturnToMenu();
        }
        return;
    }
    if (mode == KERNEL_MODE_STANDBY) {
        fn_802E30C8(KERNEL_LOG_POWER_DOWN);
        fn_8005ED8C();
        fn_802E30C8(KERNEL_LOG_WAIT_WPAD);
        while (fn_8005EE7C() == KERNEL_WPAD_SHUTTING_DOWN) {}
        fn_802E30C8(KERNEL_LOG_WPAD_DOWN);
        OSShutdownSystem();
        return;
    }
    fn_802E30C8(KERNEL_LOG_MENU);
    OSReturnToMenu();
}
#pragma pop

#pragma scheduling invalid_target
void fn_802E300C(int arg0) {
    fn_802E317C(lbl_8034CEE4, arg0);
}
#pragma scheduling on
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

