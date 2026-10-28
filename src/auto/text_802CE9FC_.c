#pragma dont_inline fn_802D1678
#pragma dont_inline fn_802CFF50
#pragma dont_inline fn_802D2ED8
#pragma dont_inline fn_802CFD74
extern int lbl_804C9760[];
#pragma small_data off
extern unsigned int lbl_804C9940;
#pragma small_data on
extern void OSReport(const char *, ...);
extern int DCFlushRange(void *, unsigned long);
extern void GXDisableBreakPt(void);
extern void fn_802CED78(void);
extern void fn_802D6C78(void);
extern unsigned char lbl_804C5710[];
extern unsigned char lbl_8055D0F0;
extern void *lbl_8055FD64;
extern void *fn_8012850C(void *, void *);
extern void *memset(void *, int, unsigned long);
extern int lbl_804C5650[];
extern int lbl_804CA2D8[];
extern int fn_801BFD34(void *, void *, void *);
extern int fn_80015B20(void *, void *, void *);
extern int fn_802D0DD4(void *, void *);
extern char lbl_8055FD70;
extern float lbl_80564F8C, lbl_80564FCC, lbl_80564FDC;
extern int lbl_8055FE24;
extern unsigned char lbl_804C9778[];
extern double lbl_80564FB0;
extern float lbl_80564FB8, lbl_80564FBC;
extern int GXLoadPosMtxImm(void *, int);
extern int GXSetDstAlpha(int, int);
extern void C_MTXOrtho(void *, float, float, float, float, float, float);
extern void GXSetProjection(void *, int);
extern void GXSetAlphaUpdate(unsigned char);
extern void GXSetFog(int, unsigned char *, unsigned char, unsigned char, void *, float, float, float, float);
extern void GXSetNumTevStages(int);
extern void GXSetTevOrder(int, int, int, int);
extern void GXSetTevOp(int, int);
extern void GXSetTevAlphaIn(int, int, int, int, int);
extern void GXSetTevAlphaOp(int, int, int, int, int, int);
extern void GXClearVtxDesc(void);
extern void GXSetVtxDesc(int, int);
extern void GXSetVtxAttrFmt(int, int, int, int, int);
extern void GXBegin(int, int, int);
extern void fn_802D1678();
extern void fn_802D14D8(void);
extern unsigned char lbl_8055FD91;
extern unsigned char lbl_8055D0FF;
extern char lbl_8055D100;
  extern int fn_802CEC04(int);
  extern void fn_802E2E0C(void (*)(void), void *);
  extern void fn_802D6C68();
  extern void fn_802DA52C(void);
  extern void GXSetDrawSync(void);
  extern void GXGetVtxDesc(void);
  extern void GXGetCPUFifo(void *);
  extern void GXGetFifoPtrs(void *, int *, int *);
  extern void GXEnableBreakPt(int);
  extern void GXInvalidateVtxCache(void);
  extern void GXMiscInit(int);
  extern unsigned long lbl_8055FD94;
extern unsigned long lbl_8055FDA0;
    extern unsigned char lbl_8055FE39;
  extern int lbl_8055FD8C;
  extern int lbl_8055FD9C;
  extern int lbl_8055FDA4;
  extern unsigned int lbl_8055FD30;
      extern float fabsf(float);
    extern unsigned char lbl_804C97B0[];
    extern unsigned short lbl_8055FD86;
extern unsigned char lbl_8055FD60;
extern float lbl_80564F94;
extern unsigned char lbl_804C5690[];
extern unsigned char lbl_802FAC70[];
extern unsigned char lbl_8055FD24;
extern void GXSetAlphaCompare(int, unsigned char, int, int, int);
extern void GXSetZMode(int, int, int);
extern int lbl_802FACB0[6];
extern void *lbl_8055FE1C;
extern unsigned char lbl_804C9984[];
extern char lbl_8034C1C4[];
extern void fn_802D2ED8(int, int);
extern unsigned char lbl_804C5700[12];
extern int fn_802E317C(const char *, ...);
extern int GXInitLightDir(unsigned short, unsigned short, unsigned long *);
extern float lbl_80564FAC, lbl_80564FA8, lbl_80564F88;
#pragma small_data off
extern char lbl_804C97D0;
#pragma small_data on
extern void GXSetTevColor(int, ...);
extern unsigned long fn_802CE9FC(int, int, int, int);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FD3C;
#pragma dont_inline on
unsigned long fn_802CE9FC(int arg0, int arg1, int arg2, int arg3) {
    unsigned char bytes[4];
    bytes[0] = (unsigned char)arg0;
    bytes[1] = (unsigned char)arg1;
    bytes[2] = (unsigned char)arg2;
    bytes[3] = (unsigned char)arg3;
    return *(unsigned long *)bytes;
}

unsigned char fn_802CEA1C(unsigned int arg0) {
    return ((unsigned char (*)(unsigned char, unsigned char, unsigned char, unsigned char))fn_802CE9FC)(
        (unsigned char)(arg0 >> 16),
        (unsigned char)(arg0 >> 8),
        (unsigned char)arg0,
        (unsigned char)(arg0 >> 24));
}

void fn_802CEA34(void) {
    unsigned char *display = (unsigned char *)lbl_8055FD64;
    unsigned short width = *(unsigned short *)(display + 4);
    unsigned short height = *(unsigned short *)(display + 8);
    int rowBytes = (width + 0xF) & 0xFFF0;
    int size = rowBytes * height;
    void *buffer;

    lbl_804C9760[2] = width;
    lbl_804C9760[3] = *(unsigned short *)(display + 8);
    lbl_804C9760[4] = 2;
    buffer = ((void *(*)(int, void *, int, unsigned short, void *))fn_8012850C)(
        size * 2, &lbl_8055D0F0, size, width, display);
    lbl_804C9760[0] = (int)buffer;
    memset(buffer, 0, size * 2);
    lbl_804C9760[1] = lbl_804C9760[0];
}

#pragma dont_inline reset

void fn_802CEAC4(void) {
    extern int VIGetTvFormat(void), fn_802E9A1C(void), fn_8005AD9C(void);
    extern void fn_802E30C8(const char *, ...);
    extern void GXDrawCylinder(void *, void *, int, int);
    extern char lbl_8034BD18[], lbl_803038D8[], lbl_80303914[], lbl_80303950[], lbl_8030398C[], lbl_803039C8[];
    extern void *lbl_8055FD64;
    extern unsigned char lbl_804C9724[];
    char *base = lbl_8034BD18;
    int format = VIGetTvFormat();
    switch (format) {
    case 0:
        if (fn_802E9A1C() == 0 || fn_8005AD9C() == 0) {
            fn_802E30C8(base + 0xA0); lbl_8055FD64 = lbl_803038D8;
        } else {
            fn_802E30C8(base + 0xB0); lbl_8055FD64 = lbl_80303914;
        } break;
    case 1: fn_802E30C8(base + 0xC0); lbl_8055FD64 = lbl_8030398C; break;
    case 5: fn_802E30C8(base + 0xCC); lbl_8055FD64 = lbl_803039C8; break;
    case 2: fn_802E30C8(base + 0xE0); lbl_8055FD64 = lbl_80303950; break;
    default: fn_802E317C(base + 0xF0); break;
    }
    GXDrawCylinder(lbl_8055FD64, lbl_804C9724, 0, 0x10);
    lbl_8055FD64 = lbl_804C9724;
    *(unsigned short *)(lbl_804C9724 + 0xE) += 0xA;
    *(unsigned short *)(lbl_804C9724 + 0xA) -= 5;
}

extern void fn_802D9C4C(void);
int fn_802CEC04(int arg0) {
    if (arg0 == 1) {
        fn_802D9C4C();
        GXSetDrawSyncCallback();
        VISetBlack(1);
        VIFlush();
        VIWaitForRetrace();
    }
    return 0;
}

void fn_802CEC44(void) {
    lbl_8055FD3C = 1;
}

void fn_802CEC50(int arg0) {
    extern unsigned long long fn_802E2C9C(void);
    extern float fn_8002FD54(unsigned int, unsigned int);
    extern void fn_802D3900(void);
    extern char lbl_8034BE20[];
    extern float lbl_8055D0B0, lbl_8055D0B4;
    extern unsigned int lbl_8055FD10, lbl_8055FD14;
    extern char lbl_8055FD3C;
    extern float lbl_80564F80, lbl_80564F84;
    unsigned long long now;
    unsigned long long delta;
    unsigned int oldLow;
    unsigned int oldHigh;
    float value;
    float previous;
    float difference;

    switch (arg0) {
    case 1:
        now = fn_802E2C9C();
        lbl_8055FD14 = (unsigned int)now;
        lbl_8055FD10 = (unsigned int)(now >> 32);
        lbl_8055FD3C = 0;
        break;
    case 2:
        now = fn_802E2C9C();
        oldLow = lbl_8055FD14;
        oldHigh = lbl_8055FD10;
        delta = now - (((unsigned long long)oldHigh << 32) | oldLow);
        value = fn_8002FD54((unsigned int)(delta >> 32), (unsigned int)delta);
        previous = lbl_8055D0B4;
        value = lbl_80564F80 * value;
        difference = previous - value;
        lbl_8055D0B0 = value;
        lbl_8055D0B4 = value + lbl_80564F84 * difference;
        fn_802D3900();
        break;
    default:
        fn_802E317C(lbl_8034BE20, arg0);
        break;
    }
}

void fn_802CECF4(unsigned int arg0) {
    extern unsigned short lbl_8055D0F6;
    extern void fn_802CEC50(int);
    unsigned int value;
    do {
        value = lbl_8055D0F6 + 1;
        lbl_8055D0F6 = value;
        if ((unsigned short)value > 2) {
            value = 1;
            lbl_8055D0F6 = 1;
        }
        fn_802CEC50((unsigned short)value);
    } while ((unsigned short)lbl_8055D0F6 != arg0);
}

void fn_802CED50(int arg0, int arg1, int arg2, int arg3) {
    volatile unsigned char *state = lbl_804C5710;
    *(volatile int *)(state + 4) = arg0;
    *(volatile int *)(state + 8) = arg1;
    *(volatile int *)(state + 0xC) = arg2;
    *(volatile int *)(state + 0x10) = arg3;
    state[0] = 1;
    state[1] = 1;
}

void fn_802CEF90(void) {
    extern void GXGetGPStatus(char *, char *, char *, char *, char *);
    extern void *GXGetCurrentGXThread(void);
    extern void OSReport(const char *, ...);
    extern void OSPanic(const char *, int, const char *, ...);
    extern void fn_802CED78(void);
    extern char lbl_8034BF34[];
    extern char lbl_8034BF70[];
    extern char lbl_8055D0F8[];
    extern unsigned char lbl_8055FD34;
    extern int lbl_8055FD38;
    extern unsigned int lbl_8055FDB8;
    extern unsigned int lbl_8055FDBC;
    unsigned char status;
    unsigned char dummy;
    unsigned int thread;

    if (lbl_8055FD34 != 0) {
        lbl_8055FD38++;
    }
    GXGetGPStatus((char *)&status, (char *)&dummy, (char *)&dummy, (char *)&dummy, (char *)&dummy);
    thread = (unsigned int)GXGetCurrentGXThread();
    if (status != 0 && thread == lbl_8055FDBC) {
        lbl_8055FDB8++;
        if (lbl_8055FDB8 >= 10) {
            OSReport(lbl_8034BF34);
            fn_802CED78();
            OSPanic(lbl_8055D0F8, 0x201, lbl_8034BF70);
        }
    } else {
        lbl_8055FDBC = thread;
        lbl_8055FDB8 = 0;
    }
}

void fn_802CF048(int arg0) {
    extern void GXSetGPMetric(int, int);
    volatile unsigned int *fifo = (volatile unsigned int *)0xCC010000;

    if (arg0 != 0) {
        GXSetGPMetric(0x23, 0x16);
        *(volatile unsigned char *)((volatile unsigned char *)fifo - 0x8000) = 0x61;
        *(volatile unsigned int *)(fifo - 0x2000) = 0x2402C004;
        *(volatile unsigned char *)((volatile unsigned char *)fifo - 0x8000) = 0x61;
        *(volatile unsigned int *)(fifo - 0x2000) = 0x23000020;
        *(volatile unsigned char *)((volatile unsigned char *)fifo - 0x8000) = 0x10;
        *(volatile unsigned short *)((volatile unsigned char *)fifo - 0x8000) = 0;
        *(volatile unsigned short *)((volatile unsigned char *)fifo - 0x8000) = 0x1006;
        *(volatile unsigned int *)(fifo - 0x2000) = 0x84400;
        return;
    }
    *(volatile unsigned char *)((volatile unsigned char *)fifo - 0x8000) = 0x61;
    *(volatile unsigned int *)(fifo - 0x2000) = 0x24000000;
    *(volatile unsigned char *)((volatile unsigned char *)fifo - 0x8000) = 0x61;
    *(volatile unsigned int *)(fifo - 0x2000) = 0x23000000;
    *(volatile unsigned char *)((volatile unsigned char *)fifo - 0x8000) = 0x10;
    *(volatile unsigned short *)((volatile unsigned char *)fifo - 0x8000) = 0;
    *(volatile unsigned short *)((volatile unsigned char *)fifo - 0x8000) = 0x1006;
    *(volatile unsigned int *)(fifo - 0x2000) = 0;
}

#pragma dont_inline on
void fn_802CF104(void) {
    fn_802CF048(1);
}
#pragma dont_inline reset

void fn_802CF5A8(void) {
    if (lbl_8055D0FF == 0) return;
    lbl_8055D0FF = 0;
    fn_802E2E0C((void (*)(void))fn_802CEC04, &lbl_8055D100);
}

void fn_802CF5D0(void) {}

#pragma scheduling invalid_target
void fn_802CF5D4(void) {
    lbl_8055FD24 = 0;
    lbl_8055FD91 = 0;
    GXSetAlphaCompare(4, 0, 1, 0, 0);
}
#pragma scheduling on

void fn_802CF5F8(void) {}

void fn_802CF5FC(void) {
}

void fn_802CF830(void) {
}

int fn_802CF834(void) {
    return lbl_804C9760[1] != 0;
}

extern void GXSetCopyClear(unsigned char *, int);
extern void GXSetScissor(unsigned int, unsigned int, unsigned int, unsigned int);
extern void GXSetPixelFmt(int, int);
extern void GXSetDispCopyGamma(int);
extern void GXSetDither(int);
extern void GXSetNumChans(int);
extern void GXSetNumTexGens(int);
extern void GXSetBlendMode(int, int, int, int);
extern void GXSetTevColorIn(int, int, int, int, int);
extern void GXSetTevColorOp(int, int, int, int, int, int);
extern void GXSetZCompLoc(int);
extern void fn_802D01E0(int, int, int, int);
extern void fn_802D03F4(float *, float);
extern void fn_802D0610(int);
extern void fn_802D9230(void);
extern void fn_802D92B8(void);
extern unsigned int lbl_8055CFF0;
extern unsigned int lbl_8055CFF4;
extern unsigned short lbl_8055FD0A;
extern char lbl_8055FD25;
extern unsigned char lbl_8055FD85;
extern char lbl_8055FDB4;
extern int lbl_8055FE20;
extern float lbl_80564F90;
extern float lbl_80564F98;
extern float lbl_80564F9C;
void fn_802CF850(void) {
    extern int lbl_804C5650[];
    extern void *lbl_8055FD64;
    extern void GXSetViewport(unsigned short, float, float, float, float, float, float);
    extern void GXSetScissor(unsigned int, unsigned int, unsigned int, unsigned int);
    extern void GXSetPixelFmt(int, int);
    extern void GXSetDispCopyGamma(int);
    extern void GXSetDither(int);
    extern void GXSetNumChans(int);
    extern void GXSetNumTexGens(int);
    extern void GXSetBlendMode(int, int, int, int);
    extern void GXSetTevOrder(int, int, int, int);
    extern void GXSetTevOp(int, int);
    extern void GXSetTevColorIn(int, int, int, int, int);
    extern void GXSetTevColorOp(int, int, int, int, int, int);
    extern void GXSetZCompLoc(int);
    extern void GXSetCopyClear(unsigned char *, int);
    extern unsigned long fn_802CE9FC();
    extern void fn_802D0188(unsigned char, unsigned char, unsigned char);
    extern void fn_802D0160(unsigned char, unsigned char, unsigned char);
    extern void fn_802D007C(float);
    extern void fn_802D01B0(float *, float);
    extern void fn_802D01E0(int, int, int, int);
    extern void fn_802D0368(float, float, float, float);
    extern void fn_802D03F4(float *, float);
    extern void fn_802D0610(int);
    extern void fn_802CFF5C(void *);
    extern void fn_802CFF50(void);
    extern void fn_802CFFA4(unsigned short);
    extern void fn_802D9230(void);
    extern void fn_802D92B8(void);
    extern int VISetNextFrameBuffer(void *);
    extern int VIFlush(void);
    extern int VIWaitForRetrace(void);
    extern unsigned int lbl_8055CFF0;
    extern unsigned int lbl_8055CFF4;
    extern unsigned short lbl_8055FD0A;
    extern char lbl_8055FD25;
    extern char lbl_8055FD70;
    extern unsigned char lbl_8055FD84;
    extern unsigned char lbl_8055FD85;
    extern char lbl_8055FDB4;
    extern int lbl_8055FE20;
    extern float lbl_80564F8C;
    extern float lbl_80564F90;
    extern float lbl_80564F98;
    extern float lbl_80564F9C;
    register unsigned char *base = (unsigned char *)lbl_804C5650;
    float spC[3];
    float sp18[12];
    volatile unsigned char spB, spA, sp9;
    volatile signed char sp8;
    unsigned int clearWord;
    unsigned short width, height;
    register volatile float *m70, *m40, *mA0;

    fn_802CF104();
    width = *(unsigned short *)((unsigned char *)lbl_8055FD64 + 4);
    height = *(unsigned short *)((unsigned char *)lbl_8055FD64 + 6);
    ((void (*)(float, float, float, float, float, float))GXSetViewport)(
        0.0f, 0.0f, (float)width, (float)height, 0.0f, 1.0f);
    GXSetScissor(0, 0, *(unsigned short *)((unsigned char *)lbl_8055FD64 + 4), *(unsigned short *)((unsigned char *)lbl_8055FD64 + 6));
    GXSetPixelFmt(1, 0);
    GXSetDispCopyGamma(0);
    clearWord = ((unsigned int (*)(unsigned int, unsigned int, unsigned int, unsigned int))fn_802CE9FC)(0, 0, 0, 0);
    spB = (unsigned char)clearWord;
    sp8 = (signed char)(clearWord >> 24);
    sp9 = (unsigned char)(clearWord >> 16);
    spA = (unsigned char)(clearWord >> 8);
    GXSetCopyClear((unsigned char *)(void *)&sp8, 0xFFFFFF);
    GXSetDither(1);
    VIWaitForRetrace();
    VISetNextFrameBuffer(*(void **)(base + 0x4110));
    *(void **)((void **)(base + 0x4110) + 1) = *(void **)(base + 0x4110);
    VIFlush();

    if ((*(unsigned int *)lbl_8055FD64 & 1) != 0) {
        VIWaitForRetrace();
    }
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOp(0, 0);
    GXSetBlendMode(1, 4, 5, 5);
    GXSetTevOrder(1, 0, 1, 4);
    GXSetTevOp(1, 2);
    GXSetTevColorIn(1, 0, 0, 0xF, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    fn_802CF5D4();
    GXSetZCompLoc(0);

    m70 = (float *)(base + 0x70);
    m40 = (float *)(base + 0x40);
    mA0 = (float *)(base + 0xA0);
    m70[0] = lbl_80564F8C; m70[1] = lbl_80564F88; m70[2] = lbl_80564F88; m70[3] = lbl_80564F88;
    m70[4] = lbl_80564F8C; m70[5] = lbl_80564F88; m70[6] = lbl_80564F88; m70[7] = lbl_80564F88;
    m70[8] = lbl_80564F8C; m70[9] = lbl_80564F88; m70[10] = lbl_80564F88; m70[11] = lbl_80564F88;
    m40[0] = lbl_80564F8C; m40[1] = lbl_80564F88; m40[2] = lbl_80564F88; m40[3] = lbl_80564F88;
    m40[4] = lbl_80564F8C; m40[5] = lbl_80564F88; m40[6] = lbl_80564F88; m40[7] = lbl_80564F88;
    m40[8] = lbl_80564F8C; m40[9] = lbl_80564F88; m40[10] = lbl_80564F88; m40[11] = lbl_80564F88;
    mA0[0] = lbl_80564F8C; mA0[1] = lbl_80564F88; mA0[2] = lbl_80564F88;
    lbl_8055FD70 = 1;
    base[0xB0] = 1;
    ((void (*)(unsigned char, unsigned char, unsigned char, void *, void *, void *, float))fn_802D0188)(
        0xFF, 0xFF, 0xFF, (void *)mA0, (void *)m70, (void *)m40, lbl_80564F8C);

    fn_802D0160(0x20, 0x20, 0x20);
    fn_802D007C(lbl_80564F8C);
    spC[0] = lbl_80564F88;
    spC[1] = lbl_80564F90;
    spC[2] = lbl_80564F88;
    fn_802D01B0(spC, lbl_80564F8C);
    fn_802D01E0(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802D0368(lbl_80564F94, lbl_80564F98, lbl_80564F9C, lbl_80564F8C);

    sp18[0] = lbl_80564F8C; sp18[1] = lbl_80564F88; sp18[2] = lbl_80564F88; sp18[3] = lbl_80564F88;
    sp18[4] = lbl_80564F8C; sp18[5] = lbl_80564F88; sp18[6] = lbl_80564F88; sp18[7] = lbl_80564F88;
    sp18[8] = lbl_80564F8C; sp18[9] = lbl_80564F88; sp18[10] = lbl_80564F88; sp18[11] = lbl_80564F88;
    fn_802D03F4(sp18, lbl_80564F8C);
    fn_802D0610(0);
    lbl_8055FD85 = 1;
    lbl_8055FD25 = 0;
    lbl_8055FD84 = 1;
    fn_802CFF5C((void *)0x17);
    fn_802CFF50();
    fn_802CFFA4(lbl_8055FD0A);
    if (lbl_8055FE1C != 0) fn_802D9230();
    if (lbl_8055FE20 != 0) fn_802D92B8();
    lbl_8055FDB4 = 0;
}

void fn_802CFBA8(void) {
    extern void fn_802D9A50(void);
    extern void fn_80127D58(void (*)(void));
    extern void fn_800591AC(int);
    extern void fn_802E30C8(const char *, ...);
    extern void fn_802DD5F4(void);
    extern void fn_802D3894(void);
    extern void fn_802D6860(void);
    extern void *lbl_8055FD68;
    extern unsigned int lbl_8055FD98;
    extern void *lbl_8055FDB0;
    extern void fn_80128670();
    extern void fn_802DA4C4(void);
    extern void fn_802D0C98(void);
    extern void fn_802DAE18(void);
    extern void fn_802D8DA0(void);
    extern char lbl_8034C038[];

    fn_80127D58(fn_802D9A50);
    fn_802D9C4C();
    fn_800591AC(0);
    fn_802E30C8(lbl_8034C038, lbl_8055FD98);
    fn_802DD5F4();
    fn_802D3894();
    fn_802D6860();
#pragma small_data off
    fn_80128670(lbl_804C9940);
    lbl_804C9940 = 0;
#pragma small_data on
    fn_802DA4C4();
    fn_802D0C98();
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    GXGetVtxDesc();
    GXSetDrawSyncCallback();
    VIFlush();
    VIWaitForRetrace();
    fn_802DAE18();
    fn_80128670(lbl_8055FD68);
    lbl_8055FD68 = 0;
    fn_80128670(lbl_804C9760[0]);
    lbl_804C9760[0] = 0;
    fn_802D8DA0();
    if (lbl_8055FDB0 != 0) {
        fn_80128670((char *)lbl_8055FDB0 - 0x10);
    }
    lbl_8055FDB0 = 0;
    lbl_804C9760[1] = 0;
    fn_80128670(lbl_8055FDA0, lbl_804C9760);
    lbl_8055FDA0 = 0;
}

extern double __fabs(double);
#pragma scheduling invalid_target
void fn_802CFCA0(void* alarm) {
    extern char lbl_80558DC4[];
    char fifo[0x80];
    int spC;
    int sp8;
    float value;
    fn_802D6C68();
    *(volatile unsigned char *)&lbl_8055FE39 = 1;
    lbl_8055FDA4 = lbl_8055FD94;
    lbl_8055FD9C = 0;
    lbl_804C5700[0] = 1;
    lbl_8055FD8C = -1;
    fn_802DA52C();
    GXSetDrawSync();
    GXGetVtxDesc();
    GXGetCPUFifo(fifo);
    GXGetFifoPtrs(fifo, &spC, &sp8);
    GXEnableBreakPt(sp8);
    GXGetVtxDesc();
    GXInvalidateVtxCache();
    GXMiscInit(1);
    lbl_8055FD30 += 1;
    if (lbl_804C97B0[0] == 0) {
        value = *(volatile float *)((unsigned char *)lbl_804C97B0 + 0x10);
        if (!((float)__fabs((double)value) <= *(volatile float *)lbl_80558DC4)) {
            lbl_804C97B0[0] = 1;
            lbl_804C97B0[0x1C] = 1;
        }
    }
}
#pragma scheduling on
extern int GXGetFifoBase(void *);
extern int GXGetFifoSize(void *);
extern void GXGetVtxAttrFmtv(void);
extern int GXInit(int, int);
extern int VIConfigure(void *);
extern void fn_802CF850(void);
#pragma push
#pragma dont_inline on
void fn_802CFD74(void) {
    extern int lbl_8055FD6C;
    extern void *lbl_8055FD64;
    char sp8[0x80];
    int temp_r31;
    int temp_r30;
    GXGetCPUFifo(sp8);
    temp_r31 = GXGetFifoBase(sp8);
    temp_r30 = GXGetFifoSize(sp8);
    GXGetVtxAttrFmtv();
    lbl_8055FD6C = GXInit(temp_r31, temp_r30);
    fn_802CF850();
    VIConfigure(lbl_8055FD64);
}

#pragma scheduling invalid_target
int fn_802CFDE0(void) {
    extern unsigned int lbl_8055FD98;
    extern unsigned int lbl_8055FDA8;
    extern int lbl_8055FD2C;
    extern int lbl_8055FD38;
    extern unsigned char lbl_8055FD34;
    extern int lbl_8055FD40;
    extern char lbl_8034C058[];
    extern void fn_802ECA48(void);
    extern int fn_802E2C20(void);
    register int temp_r0;
    register int var_r4;
    int end;
    int start;

    fn_802ECA48();
    temp_r0 = (int)lbl_8055FD94 + lbl_8055FD9C;
    var_r4 = (int)lbl_8055FD98;
    if (temp_r0 > var_r4) {
        var_r4 = temp_r0;
        lbl_8055FD98 = (unsigned int)var_r4;
    }
    fn_802D6C78();
    GXGetVtxDesc();
    GXMiscInit(2);
    end = (int)lbl_8055FD94;
    start = lbl_8055FDA4;
    lbl_8055FDA8 = (unsigned int)end;
    if (start < end) {
        DCFlushRange((void *)(lbl_8055FDA0 + start), (unsigned long)(end - start));
    } else {
        DCFlushRange((void *)(lbl_8055FDA0 + start), (unsigned long)(0x177000 - start));
    }
    DCFlushRange((void *)lbl_8055FDA0, (unsigned long)lbl_8055FDA8);
    lbl_8055FD38 = 0;
    lbl_8055FD34 = 1;
    for (;;) {
        if (*(volatile int *)&lbl_8055FD38 > 10) {
            OSReport(lbl_8034C058);
            fn_802CED78();
            fn_802CFD74();
            fn_802CF048(1);
            lbl_8055FD40 = fn_802E2C20();
        }
        if ((unsigned char)lbl_8055FD3C != 0) break;
    }
    lbl_8055FD34 = 0;
    lbl_8055FD2C = (int)lbl_8055FD30 - 1;
    GXDisableBreakPt();
}
#pragma scheduling on

#pragma pop

extern void fn_802CFCA0(void*);
void fn_802CFEEC(void* alarm) {
    fn_802CFCA0(alarm);
    fn_802CFDE0();
}

extern unsigned long lbl_8055FD44;
extern unsigned long lbl_8055FDAC;
extern void fn_802D0C98(void);
extern void fn_802D0BD8(void);
#pragma push
#pragma use_lmw_stmw off
void fn_802CFF10(void) {
    int zero;
    zero = 0;
    lbl_8055FD44 = zero;
    fn_802CF5D0();
    fn_802D0C98();
    fn_802D0BD8();
    lbl_8055FDAC = zero;
    lbl_8055FE39 = zero;
}
#pragma pop
extern void *lbl_8055FD20;
#pragma push
#pragma dont_inline on
void fn_802CFF50(void) {
    lbl_8055FD20 = (void*)-1;
}
#pragma pop

extern void *lbl_8055FD1C;
void fn_802CFF5C(void* hi) {
    lbl_8055FD1C = hi;
}

int fn_802CFF64(int arg0) {
    int aligned = (arg0 + 0x1F) & ~0x1F;
    int old = lbl_8055FD94;
    int next = old + aligned;
    if (next <= 0x177000) {
        lbl_8055FD94 = next;
        return lbl_8055FDA0 + old;
    }
    lbl_8055FD94 = aligned;
    return lbl_8055FDA0;
}

#pragma dont_inline on
int fn_802CFFA0(int arg0) {
    return fn_802CFF64(arg0);
}
#pragma dont_inline reset

void fn_802CFFA4(unsigned short arg0) {
    lbl_8055FD86 = arg0;
}

#pragma scheduling invalid_target
void fn_802CFFAC(int arg0, int arg1, int arg2) {
    unsigned long packed;
    volatile unsigned char spB;
    volatile unsigned char spA;
    volatile unsigned char sp9;
    volatile unsigned char sp8;

    packed = fn_802CE9FC(arg0, arg1, arg2, 0);
    spB = (unsigned char)packed;
    sp8 = (unsigned char)(packed >> 24);
    sp9 = (unsigned char)(packed >> 16);
    lbl_804C97B0[1] = sp8;
    lbl_804C97B0[2] = sp9;
    lbl_804C97B0[3] = (unsigned char)(packed >> 8);
    lbl_804C97B0[4] = (unsigned char)packed;
    lbl_804C97B0[0x1C] = 1;
    spA = (unsigned char)(packed >> 8);
}
#pragma scheduling on
void fn_802D0014(float a, float b, float c) {
    extern unsigned char lbl_804C97B0[];
    extern char lbl_80558DC4[];
    float magnitude = (float)__fabs((double)c);
    ((float *)lbl_804C97B0)[2] = a;
    if (!(magnitude <= *(float *)lbl_80558DC4)) {
        lbl_804C97B0[0] = 1;
        ((float *)lbl_804C97B0)[3] = a + ((b - a) / c);
    } else {
        ((float *)lbl_804C97B0)[3] = b;
        lbl_804C97B0[0] = 0;
    }
    ((float *)lbl_804C97B0)[4] = c;
    lbl_804C97B0[0x1C] = 1;
}
#pragma push
#pragma small_data off
extern __declspec(section ".data") char lbl_804C97D0;
void fn_802D007C(float arg0) {
    extern float lbl_80564FAC;
    extern float lbl_80564FA8;
    extern float lbl_80564F88;
    extern char lbl_804C97D0;
    extern unsigned char lbl_804C5700[];
    float temp_f0;
    float var_f3;
    unsigned char temp_r6;
    volatile unsigned char scratch[4];
    int color;

    temp_f0 = lbl_80564FAC * arg0;
    var_f3 = lbl_80564FA8;
    if (var_f3 >= (float)(int)temp_f0) {
        var_f3 = (float)(int)temp_f0;
    }
    if (var_f3 <= lbl_80564F88) {
        var_f3 = lbl_80564F88;
    }
    scratch[2] = 0xFF;
    scratch[1] = 0xFF;
    scratch[0] = 0xFF;
    temp_r6 = (unsigned char)var_f3;
    scratch[3] = temp_r6;
    color = *(int *)scratch;
    ((unsigned char *)&lbl_804C97D0)[8] = temp_r6;
    ((unsigned char *)&lbl_804C97D0)[0x5C] = 1;
    GXSetTevColor(1, &color);
    lbl_804C5700[0] = 1;
}
#pragma pop
void fn_802D0160(unsigned char a, unsigned char b, unsigned char c) {
    extern char lbl_804C97D0;
    unsigned char *p = (unsigned char *)&lbl_804C97D0;
    p[4] = a;
    p[5] = b;
    p[6] = c;
    p[7] = 0xFF;
    p[0x5C] = 1;
}
#pragma small_data on
void fn_802D0188(unsigned char a, unsigned char b, unsigned char c) {
    extern char lbl_804C97D0;
    unsigned char *p = (unsigned char *)&lbl_804C97D0;
    p[0] = a; p[1] = b; p[2] = c; p[3] = 0; p[0x5C] = 1;
}

#pragma scheduling off
void fn_802D01B0(float *p, float v) {
    extern char lbl_804C97D0;
    float z, y, x;
    float *out;
    x = p[0];
    y = p[1];
    z = p[2];
    out = (float *)((unsigned char *)&lbl_804C97D0 + 0xC);
    out[0] = x;
    out[1] = y;
    out[2] = z;
    out[3] = v;
    *((unsigned char *)&lbl_804C97D0 + 0x5C) = 1;
}

#pragma push
#pragma scheduling invalid_target
void fn_802D2218(void);
#pragma push
#pragma paired off
#pragma paired_single off
#pragma scheduling invalid_target
void fn_802D01E0(int arg0, int arg1, int arg2, int arg3) {
    int var_r31;
    int var_r29;

    var_r29 = arg1;
    var_r31 = arg3;
    if (lbl_8055FE24 == 0) {
        var_r29 = (int)(lbl_80564F94 + ((lbl_80564FB8 * (float)arg1) / lbl_80564FBC));
        var_r31 = (int)(lbl_80564F94 + ((lbl_80564FB8 * (float)arg3) / lbl_80564FBC));
    }
    fn_802D2218();
    *(int *)(lbl_804C9778 + 0x1C) = arg0;
    *(int *)(lbl_804C9778 + 0x20) = var_r29;
    *(int *)(lbl_804C9778 + 0x24) = arg2;
    *(int *)(lbl_804C9778 + 0x28) = var_r31;
    lbl_804C9778[1] = 1;
    lbl_804C9778[0] = 1;
    *(float *)(lbl_804C9778 + 0x18) = (float)arg2 / (float)var_r31;
}
#pragma scheduling on
#pragma paired_single reset
#pragma paired reset
#pragma pop

#pragma scheduling on
void fn_802D02F8(int arg0, signed char arg1) {
    extern unsigned char lbl_804C9778[];
    volatile unsigned char scratch[4];
    unsigned int value;
    lbl_804C9778[0x2d] = arg1;
    lbl_804C9778[0x2c] = 1;
    value = ((unsigned int (*)(unsigned int))fn_802CEA1C)((unsigned int)arg0);
    lbl_804C9778[0x31] = value;
    scratch[0] = (unsigned char)(value >> 24);
    scratch[1] = (unsigned char)(value >> 16);
    lbl_804C9778[0x2e] = scratch[0];
    lbl_804C9778[0x2f] = scratch[1];
    lbl_804C9778[0x30] = (unsigned char)(value >> 8);
    scratch[3] = (unsigned char)value;
    scratch[2] = (unsigned char)(value >> 8);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802D0368(float arg0, float arg1, float arg2, float arg3) {
    extern float lbl_80564F94;
    extern unsigned char lbl_804C9778[];
    extern unsigned char lbl_804C97B0[];
    extern double fn_8002EF30(double);
    float result;

    *(float *)(lbl_804C9778 + 4) = arg0;
    lbl_804C9778[0] = 1;
    *(float *)(lbl_804C9778 + 8) = arg1;
    *(float *)(lbl_804C9778 + 0xc) = arg2;
    *(float *)(lbl_804C9778 + 0x14) = arg3;

    result = fn_8002EF30(arg2 * lbl_80564F94);

    *(float *)(lbl_804C97B0 + 0x14) = arg0;
    *(float *)(lbl_804C9778 + 0x10) = result;
    *(float *)(lbl_804C97B0 + 0x18) = arg1;
    lbl_804C97B0[0x1c] = 1;
}

extern unsigned long lbl_804C56C0[];
extern float lbl_804C56F0[3];
extern float lbl_80564FC0;
extern void PSVECCrossProduct(float *, float *, float *);
extern float PSVECMag();
#pragma use_lmw_stmw off
void fn_802D03F4(register float *arg0, float arg1) {
    volatile unsigned long *src = (volatile unsigned long *)arg0;
    unsigned long *dst = lbl_804C56C0;
    unsigned long t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    float sp[3];
    float mag;
    float scale;

    fn_802D6C78();
    t0 = src[0];
    t1 = src[1];
    dst[0] = t0;
    t2 = src[2]; t3 = src[3]; t4 = src[4]; t5 = src[5];
    t6 = src[6]; t7 = src[7]; t8 = src[8]; t9 = src[9];
    t10 = src[10]; t11 = src[11];
    dst[1] = t1; dst[2] = t2; dst[3] = t3;
    dst[4] = t4; dst[5] = t5; dst[6] = t6; dst[7] = t7;
    dst[8] = t8; dst[9] = t9; dst[10] = t10; dst[11] = t11;
    sp[0] = lbl_80564F88; sp[1] = lbl_80564F8C; sp[2] = lbl_80564F88;
    PSVECCrossProduct(sp, arg0 + 6, lbl_804C56F0);
    mag = PSVECMag(lbl_804C56F0);
    mag = mag > lbl_80564FC0 ? mag : lbl_80564FC0;
    scale = lbl_80564F8C / mag;
    lbl_8055FD70 = 1;
    lbl_804C56F0[0] = lbl_804C56F0[0] * scale;
    lbl_804C56F0[1] = lbl_804C56F0[1] * scale;
    lbl_804C56F0[2] = lbl_804C56F0[2] * scale;
}
#pragma use_lmw_stmw reset

#pragma pop
extern void *lbl_8055FD54;
extern void* fn_802D30F0(void);
extern void fn_802D307C(void);
void fn_802D050C(void* hi) {
    lbl_8055FD54 = hi;
}

int fn_802D0514(void *source) {
    extern unsigned long lbl_8055FDAC;
    extern void *lbl_8055FDB0;
    int index;
    unsigned long next;
    unsigned int *src;
    unsigned char *dst;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned char *aux;
    index = (int)lbl_8055FDAC;
    if (index >= 0x800) return 0;
    src = (unsigned int *)source;
    dst = (unsigned char *)lbl_8055FDB0 + index * 0x4C;
    a = src[0];
    b = src[1];
    next = index + 1;
    lbl_8055FDAC = next;
    *(unsigned int *)(dst + 0) = a;
    c = src[2];
    *(unsigned int *)(dst + 4) = b;
    a = src[3];
    *(unsigned int *)(dst + 8) = c;
    b = src[4];
    *(unsigned int *)(dst + 12) = a;
    c = src[5];
    *(unsigned int *)(dst + 16) = b;
    a = src[6];
    *(unsigned int *)(dst + 20) = c;
    b = src[7];
    *(unsigned int *)(dst + 24) = a;
    c = src[8];
    *(unsigned int *)(dst + 28) = b;
    a = src[9];
    *(unsigned int *)(dst + 32) = c;
    b = src[10];
    *(unsigned int *)(dst + 36) = a;
    c = src[11];
    *(unsigned int *)(dst + 40) = b;
    *(unsigned int *)(dst + 44) = c;
    aux = (unsigned char *)&lbl_804C97D0 - 1;
    dst[0x30] = *++aux;
    dst[0x31] = aux[1];
    dst[0x32] = aux[2];
    dst[0x33] = aux[3];
    dst[0x34] = aux[4];
    dst[0x35] = aux[5];
    dst[0x36] = aux[6];
    dst[0x37] = aux[7];
    dst[0x38] = aux[8];
    *(unsigned int *)(dst + 0x3C) = *(unsigned int *)(aux + 12);
    *(unsigned int *)(dst + 0x40) = *(unsigned int *)(aux + 16);
    *(unsigned int *)(dst + 0x44) = *(unsigned int *)(aux + 20);
    *(float *)(dst + 0x48) = *(float *)(aux + 24);
    return next;
}

void fn_802D07E4(char* arg0, int arg1) {
    extern unsigned long lbl_8055D0B8;
    extern int lbl_8055D0BC, lbl_8055D0C0;
    extern signed char lbl_8055FD90;
    extern unsigned char lbl_804C9830[];
    extern int lbl_804C9760[];
    extern char lbl_8034C0EC[], lbl_8034C108[];
    extern void fn_802E30C8(const char*, ...);
    register char c;
    register unsigned char* out;
    if ((int)lbl_8055D0B8 >= 0) {
        fn_802E30C8(lbl_8034C0EC);
        lbl_8055D0B8 = lbl_8055D0BC * lbl_8055D0C0;
        return;
    }
    lbl_8055FD90 = 1;
    out = lbl_804C9830;
    out[-1] = 0;
    do {
        c = *arg0++;
        *out++ = c;
    } while (c != 0);
    if (arg1 != 0) {
        fn_802E30C8(lbl_8034C108, lbl_8055D0BC * lbl_804C9760[2], lbl_8055D0C0 * lbl_804C9760[3], lbl_804C9760, lbl_8055D0BC);
        lbl_8055D0B8 = 0;
    }
}

extern unsigned char lbl_8055FD78;
extern int GXSetCullMode(int);
extern void GXLoadTexMtxImm(void *, unsigned int, unsigned char);
extern int lbl_8055D0BC;
extern int lbl_8055D0C0;
extern unsigned char lbl_8055FD18;
void fn_802D08B4(int arg0, int arg1, unsigned char arg2) {
    lbl_8055FD18 = arg2;
    lbl_8055D0BC = arg0;
    lbl_8055D0C0 = arg1;
}

void fn_802D08C4(unsigned char arg0) {
    lbl_8055FD78 = arg0;
}

void fn_802D08CC(int arg0) {
    int mode;
    switch (arg0) {
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 0:
        mode = 0;
        break;
    default:
        mode = 0;
        break;
    }
    GXSetCullMode(mode);
}

void fn_802D0910(int, int, int, int, int, int) {
}

#pragma scheduling invalid_target
void fn_802D0914(int arg0, short arg1, short arg2) {
    extern int fn_802E3A64(int, unsigned char *, int, int, int, int, int, int);
    register int first = arg0;
    register short second = arg1;
    register short third = arg2;
    unsigned char buffer[0x12];
    unsigned char b8;
    unsigned char b9;
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;

    memset(buffer, 0, 0x12);
    *(unsigned short *)(buffer + 8) = 0;
    *(unsigned short *)(buffer + 10) = 0;
    *(unsigned short *)(buffer + 12) = second;
    *(unsigned short *)(buffer + 14) = third;
    b8 = buffer[8];
    b9 = buffer[9];
    b10 = buffer[10];
    b11 = buffer[11];
    b12 = buffer[12];
    b13 = buffer[13];
    b14 = buffer[14];
    b15 = buffer[15];
    buffer[0] = 0;
    buffer[1] = 0;
    buffer[2] = 2;
    buffer[8] = b9;
    buffer[9] = b8;
    buffer[10] = b11;
    buffer[11] = b10;
    buffer[12] = b13;
    buffer[13] = b12;
    buffer[14] = b15;
    buffer[15] = b14;
    buffer[16] = 0x18;
    buffer[17] = 0;
    fn_802E3A64(first, buffer, 0x12, b13, b11, b9, 0x18, 2);
}
#pragma scheduling on
void fn_802D09E4(void) {
}

void fn_802D0BD8(void) {
    extern void *lbl_8055FD64;
    extern float lbl_80564F88;
    extern float lbl_80564F8C;
    extern double lbl_80564FA0;
    extern void VIGetNextField(void);
    extern void GXSetViewportJitter(unsigned short, float, float, float, float, float, float);
    extern void GXSetViewport(unsigned short, float, float, float, float, float, float);
    extern void GXInvalidateVtxCache(void);
    extern void GXInvalidateTexAll(void);
    unsigned char *p = (unsigned char *)lbl_8055FD64;
    unsigned short x;
    unsigned short y;
    if (p[0x18]) {
        VIGetNextField();
        x = *(unsigned short *)(p + 4);
        y = *(unsigned short *)(p + 6);
        GXSetViewportJitter(x, lbl_80564F88, lbl_80564F88, (float)x, (float)y, lbl_80564F88, lbl_80564F8C);
    } else {
        x = *(unsigned short *)(p + 4);
        y = *(unsigned short *)(p + 6);
        GXSetViewport(x, lbl_80564F88, lbl_80564F88, (float)x, (float)y, lbl_80564F88, lbl_80564F8C);
    }
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
}

extern void GXSetColorUpdate(unsigned char);
extern float GXGetYScaleFactor(unsigned short, unsigned short);
extern unsigned int GXSetDispCopyYScale(float);
extern void GXSetDispCopySrc(unsigned short, unsigned short, unsigned short, unsigned short);
extern void GXSetDispCopyDst(unsigned short, unsigned short);
extern void GXSetCopyFilter(unsigned char, unsigned char *, unsigned char, unsigned char *);
extern void GXCopyDisp(void *, int);
extern void fn_802D09E8(void);
extern void fn_802CFF50(void);
void fn_802D0C98(void) {
    extern int lbl_8055FD48, lbl_8055FD4C;
    extern unsigned int lbl_8055FD74;
    extern unsigned char lbl_8055D0C4;
    extern void *lbl_8055FD64;
    extern int lbl_804C9760[];
    unsigned short temp_r31;
    int temp_r30 = 0;
    unsigned char *display;

    lbl_8055FD4C = temp_r30;
    GXSetZMode(1, 3, 1);
    GXSetColorUpdate(1);
    fn_802D09E8();
    GXSetColorUpdate(lbl_8055D0C4);
    lbl_8055FD74 |= 1;
    GXSetZMode(1, 7, 1);
    lbl_8055FD74 = (lbl_8055FD74 | 2) & ~4U;
    temp_r31 = (unsigned short)GXSetDispCopyYScale(
        GXGetYScaleFactor(*(unsigned short *)((unsigned char *)lbl_8055FD64 + 6),
                          *(unsigned short *)((unsigned char *)lbl_8055FD64 + 8)));
    display = (unsigned char *)lbl_8055FD64;
    GXSetDispCopySrc(0, 0, *(unsigned short *)(display + 4), *(unsigned short *)(display + 6));
    GXSetDispCopyDst(*(unsigned short *)((unsigned char *)lbl_8055FD64 + 4), temp_r31);
    GXSetCopyFilter(*((unsigned char *)lbl_8055FD64 + 0x19),
                    (unsigned char *)lbl_8055FD64 + 0x1A, 1,
                    (unsigned char *)lbl_8055FD64 + 0x32);
    GXCopyDisp((void *)lbl_804C9760[1], 1);
    VISetNextFrameBuffer((void *)lbl_804C9760[1]);
    if (lbl_8055FD48 > 0) {
        lbl_8055FD48 -= 1;
        VISetBlack(1);
    } else {
        lbl_8055FD48 = temp_r30;
        VISetBlack(0);
    }
    VIFlush();
    lbl_804C9760[1] = lbl_804C9760[0];
    fn_802CFF50();
}

int fn_802D0DD4(void *dst, void *src) {
    float a,b,c,d,e,f,g,h,i,j,k,l;
    a = *(float *)((unsigned char *)src + 8);
    b = *(float *)((unsigned char *)src + 0x14);
    c = *(float *)((unsigned char *)src + 0x20);
    d = *(float *)((unsigned char *)src + 0x2c);
    e = *(float *)((unsigned char *)src + 0);
    f = *(float *)((unsigned char *)src + 4);
    g = *(float *)((unsigned char *)src + 0xc);
    h = *(float *)((unsigned char *)src + 0x10);
    i = *(float *)((unsigned char *)src + 0x18);
    j = *(float *)((unsigned char *)src + 0x1c);
    k = *(float *)((unsigned char *)src + 0x24);
    l = *(float *)((unsigned char *)src + 0x28);
    *(float *)((unsigned char *)dst + 0) = e;
    *(float *)((unsigned char *)dst + 0x10) = f;
    *(float *)((unsigned char *)dst + 0x20) = -a;
    *(float *)((unsigned char *)dst + 4) = g;
    *(float *)((unsigned char *)dst + 0x14) = h;
    *(float *)((unsigned char *)dst + 0x24) = -b;
    *(float *)((unsigned char *)dst + 8) = i;
    *(float *)((unsigned char *)dst + 0x18) = j;
    *(float *)((unsigned char *)dst + 0x28) = -c;
    *(float *)((unsigned char *)dst + 0xc) = k;
    *(float *)((unsigned char *)dst + 0x1c) = l;
    *(float *)((unsigned char *)dst + 0x2c) = -d;
}

extern float lbl_80564F94;
extern unsigned char lbl_804C5690[];
extern unsigned char lbl_802FAC70[];
extern void GXSetAlphaCompare(int, unsigned char, int, int, int);
extern void GXSetZMode(int, int, int);
extern unsigned char lbl_8055FD24;
void fn_802D0E48(int arg0) {
    if (arg0 == 0) {
        GXSetAlphaCompare(3, lbl_8055FD24, 1, 0, 0);
        GXSetZMode(1, 3, 0);
    } else if (arg0 == 1) {
        GXSetAlphaCompare(4, lbl_8055FD24, 1, 0, 0);
        GXSetZMode(1, 3, 1);
    }
}

int fn_802D0EC8(int arg0) {
    switch (arg0) {
    case 8:
        return 2;
    case 9:
        return 3;
    default:
        return arg0;
    }
}

extern void GXInitLightColor(void *, unsigned char *);
extern void GXGetLightDir_Internal(void *, float, float, float, float, float, float);
extern void GXInitLightAttn(void *, float, float, float, float, float, float);
extern float PSVECMag(float *);
extern float lbl_80564F80, lbl_80564F88, lbl_80564F8C, lbl_80564F90, lbl_80564F94;
#pragma push
#pragma paired off
#pragma paired_single off
#pragma scheduling invalid_target
void fn_802D17BC(void *light, float *a, float *b, unsigned char *color, float scale) {
    unsigned char c2, c0, c3;
    unsigned char rgba[4];
    float vec[3];
    float x, y, z, mag, k;
    c0=color[0]; c2=color[2]; c3=color[3];
    rgba[1]=color[1]; rgba[0]=c0; rgba[2]=c2; rgba[3]=c3;
    GXInitLightColor(light, rgba);
    x=a[0]+b[0];
    y=a[1]+b[1];
    z=a[2]+b[2];
    vec[0]=x; vec[1]=y; vec[2]=z;
    mag=PSVECMag(vec);
    mag = mag > lbl_80564F80 ? mag : lbl_80564F80;
    k=lbl_80564F90/mag;
    x=vec[0]*k; y=vec[1]*k; z=vec[2]*k;
    vec[0]=x; vec[1]=y; vec[2]=z;
    GXGetLightDir_Internal(light,b[0],b[1],-b[2],x,y,-z);
    {
        float v=scale*lbl_80564F94;
        GXInitLightAttn(light,lbl_80564F88,lbl_80564F88,lbl_80564F8C,v,lbl_80564F88,lbl_80564F8C-v);
    }
}
#pragma scheduling on
#pragma paired_single reset
#pragma paired reset
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_802D1B58(void) {
    int m[8];
    float *t = (float *)lbl_804C5690;
    int *p = (int *)lbl_802FAC70;
    m[0] = p[0];
    m[1] = p[1];
    m[2] = p[2];
    m[3] = p[3];
    m[4] = p[4];
    m[5] = p[5];
    m[6] = p[6];
    m[7] = p[7];
    *(float *)&m[0] = 0.5f * -t[1];
    *(float *)&m[1] = 0.5f * -t[4];
    *(float *)&m[2] = 0.5f * -t[7];
    GXLoadTexMtxImm((float *)m, 0x21, 1);
}
#pragma pop
extern float lbl_80564FCC;
extern float lbl_80564FDC;
#pragma push
#pragma paired off
#pragma paired_single off
#pragma scheduling invalid_target
#pragma dont_inline fn_802CFF50
void fn_802D2218(void) {
    float sp90[12];
    float sp60[12];
    float sp20[16];
    volatile float sp18;
    volatile float sp14;
    volatile float sp10;
    unsigned char fogColor[4];
    unsigned char tevColor[4];
    float temp_f1;
    float temp_f1_2;
    register float vertexZ;
    register volatile float *fifo;
    register float temp_f30;
    register float temp_f31;
    int screenWidth;
    int screenHeight;
    int var_ctr;
    int var_r0;
    int var_r0_2;
    int var_r0_3;
    int var_r0_4;
    int var_r4;
    unsigned char temp_r5;
    unsigned char temp_r5_2;
    unsigned char temp_r6;
    unsigned char temp_r6_2;
    unsigned char temp_r7_2;
    register unsigned char *temp_r30;
    unsigned char *temp_r3;
    unsigned char *temp_r3_2;
    unsigned char *temp_r3_3;
    unsigned char *temp_r4_2;
    unsigned char *temp_r7;

    temp_r3 = (unsigned char *)lbl_804C5650 + 0x4128;
    if ((temp_r3[0x2D] != 0) || (temp_r3[0x2C] != 0)) {
        fn_802D1678();
        sp90[0] = lbl_80564F8C;
        sp90[1] = lbl_80564F88;
        sp90[2] = lbl_80564F88;
        sp90[3] = lbl_80564F88;
        sp90[4] = lbl_80564F8C;
        sp90[5] = lbl_80564F88;
        sp90[6] = lbl_80564F88;
        sp90[7] = lbl_80564F88;
        sp90[8] = lbl_80564F8C;
        sp90[9] = lbl_80564F88;
        sp90[10] = lbl_80564F88;
        sp90[11] = lbl_80564F88;
        fn_802D0DD4(sp60, sp90);
        GXLoadPosMtxImm(sp60, 0);
        temp_r30 = (unsigned char *)lbl_804C5650 + 0x4128;
        screenWidth = *(int *)((unsigned char *)temp_r30 + 0x24);
        screenHeight = *(int *)((unsigned char *)temp_r30 + 0x28);
        temp_f31 = lbl_80564F94 * (float)screenWidth;
        temp_f30 = lbl_80564F94 * (float)screenHeight;
        C_MTXOrtho(sp20, temp_f30, -temp_f30, -temp_f31, temp_f31, lbl_80564F8C, lbl_80564FCC);
        GXSetProjection(sp20, 1);
        GXSetDstAlpha(0, 0);
        GXSetBlendMode(0, 1, 0, 5);
        GXSetColorUpdate(temp_r30[0x2D]);
        GXSetAlphaUpdate(temp_r30[0x2D]);
        GXSetZMode(1, 7, temp_r30[0x2C]);
        temp_r7 = (unsigned char *)temp_r30 + 0x38;
        fogColor[0] = temp_r7[1];
        temp_r6 = temp_r7[2];
        fogColor[1] = temp_r6;
        temp_r5 = temp_r7[3];
        fogColor[2] = temp_r5;
        fogColor[3] = temp_r7[4];
        GXSetFog(0, fogColor, temp_r5, temp_r6, temp_r7, lbl_80564F88, lbl_80564F88, lbl_80564F88, lbl_80564F88);
        GXSetNumTevStages(1);
        GXSetNumTexGens(0);
        temp_r7_2 = temp_r30[0x2E];
        temp_r6_2 = temp_r30[0x2F];
        temp_r5_2 = temp_r30[0x30];
        tevColor[0] = temp_r7_2;
        tevColor[1] = temp_r6_2;
        tevColor[2] = temp_r5_2;
        tevColor[3] = temp_r30[0x31];
        ((void (*)(int, unsigned char *, unsigned char, unsigned char, unsigned char))GXSetTevColor)(1, tevColor, temp_r5_2, temp_r6_2, temp_r7_2);
        GXSetTevOrder(0, 0xFF, 0xFF, 0xFF);
        GXSetTevColorIn(0, 0xF, 0xF, 0xF, 2);
        GXSetTevColorOp(0, 0, 0, 0, 0, 0);
        GXSetTevAlphaIn(0, 7, 7, 7, 1);
        GXSetTevAlphaOp(0, 0, 0, 0, 0, 0);
        GXSetCullMode(0);
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXBegin(0x98, 0, 4);
        fifo = (volatile float *)0xCC010000;
        var_r4 = 0;
        vertexZ = lbl_80564FDC;
        for (var_ctr = 0; var_ctr != 2; var_ctr++) {
            var_r0 = 1;
            if (var_r4 & 1) {
                var_r0 = -1;
            }
            var_r0_2 = 1;
            sp10 = temp_f31 * (float)var_r0;
            if (var_r4 & 2) {
                var_r0_2 = -1;
            }
            fifo[-0x2000] = sp10;
            sp18 = vertexZ;
            temp_f1 = temp_f30 * (float)var_r0_2;
            fifo[-0x2000] = temp_f1;
            sp14 = temp_f1;
            fifo[-0x2000] = vertexZ;
            var_r4++;
            var_r0_3 = 1;
            if (var_r4 & 1) {
                var_r0_3 = -1;
            }
            var_r0_4 = 1;
            sp10 = temp_f31 * (float)var_r0_3;
            if (var_r4 & 2) {
                var_r0_4 = -1;
            }
            fifo[-0x2000] = sp10;
            sp18 = vertexZ;
            temp_f1_2 = temp_f30 * (float)var_r0_4;
            fifo[-0x2000] = temp_f1_2;
            sp14 = temp_f1_2;
            fifo[-0x2000] = vertexZ;
            var_r4++;
        }
        GXSetNumTexGens(1);
        GXSetTevOrder(0, 0, 0, 4);
        GXSetTevOp(0, 0);
        GXSetDstAlpha(1, lbl_8055FD60);
        temp_r3_2 = (unsigned char *)temp_r30;
        temp_r3_2[0x2C] = 0;
        temp_r3_2[0x2D] = 0;
        fn_802CFF50();
        temp_r3_2[0] = 1;
        fn_802D14D8();
        temp_r4_2 = (unsigned char *)temp_r30 + 0x58;
        ((unsigned char *)lbl_804C5650)[0xB0] = 1;
        temp_r3_3 = (unsigned char *)temp_r30 + 0x38;
        lbl_8055FD70 = 1;
        temp_r4_2[0x5C] = 1;
        temp_r3_3[0x1C] = 1;
        fn_802D6C68();
    }
}
#pragma scheduling on
#pragma paired_single reset
#pragma paired reset
#pragma pop
void fn_802D2614(void) {
    fn_802D14D8();
    fn_802D1678();
    fn_802D2218();
    fn_802D0EEC();
}

void fn_802D2640(void) {
    int i;
    GXSetNumIndStages(0);
    i = 0;
    do {
        GXSetTevDirect(i);
        i++;
    } while (i < 4);
}

extern void (*lbl_8055FD80)(void);
#pragma scheduling invalid_target
void fn_802D2684(void) {
    unsigned int tevFlag;
    unsigned char texFlag;
    unsigned char tevFlag2;
    unsigned char indirectFlag;
    int coordType;
    int tevStage;
    int texGen;
    int coordCount;
    int coordMap[2];
    int arg8;
    int argC;

    tevFlag = ((unsigned long)lbl_8055FD1C >> 6) & 1;
    tevFlag2 = (unsigned char)lbl_804C5700[9];
    tevStage = 0;
    texFlag = (unsigned char)lbl_804C5700[8];
    texGen = 0;
    indirectFlag = (unsigned char)lbl_804C5700[10];
    coordType = lbl_804C5700[12] != 0 ? 0x1E : 0x3C;

    GXSetTexCoordGen2(0, 1, 4, coordType, 0, 0x7D);
    GXSetTevOrder(0, 0, 0, 4);
    if (tevFlag != 0) {
        GXSetTevOp(0, 3);
    } else if (tevFlag2 != 0) {
        GXSetTevOp(0, 3);
        texGen = 1;
        GXSetTexCoordGen2(1, 1, 5, 0x3C, 0, 0x7D);
        tevStage = 1;
        GXSetTevOrder(1, 1, 3, 4);
        GXSetTevOp(1, 0);
    } else {
        GXSetTevColorOp(0, 0, 0, 0, 1, 0);
        GXSetTevColorIn(0, 0xF, 8, 0xA, 0xF);
        coordCount = 0;
        if (((unsigned long)lbl_8055FD1C & 0x100) != 0) {
            coordMap[0] = 4;
            coordCount = 1;
        }
        if (((unsigned char *)&lbl_804C97D0)[8] < 0xFF) {
            coordMap[coordCount] = 1;
            coordCount++;
        }
        if (((unsigned char *)&lbl_8055FD25)[0] == 0 && coordCount < 2) {
            coordMap[coordCount] = 5;
            coordCount++;
        }
        if (coordCount < 2) {
            coordMap[coordCount] = 6;
            if (coordCount == 0)
                coordMap[coordCount + 1] = 6;
        }
        GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(0, 7, coordMap[0], coordMap[1], 7);
    }

    if (texFlag != 0) {
        tevStage++;
        GXSetTevOrder(tevStage, 0, 1, 4);
        GXSetTevColorOp(tevStage, 0, 0, 0, 1, 0);
        GXSetTevColorIn(tevStage, 0, 0xF, 0xF, 0xF);
        GXSetTevAlphaOp(tevStage, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(tevStage, 7, 0, 4, 7);
    }
    if (indirectFlag != 0) {
        texGen++;
        GXSetTexCoordGen2(texGen, 1, 0, 0x2D, 0, 0x7D);
        tevStage++;
        GXSetTevOrder(tevStage, texGen, 5, 0xFF);
        GXSetTevColorIn(tevStage, 0, 8, 9, 0xF);
        GXSetTevColorOp(tevStage, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(tevStage, 0, 7, 7, 7);
        GXSetTevAlphaOp(tevStage, 0, 0, 0, 1, 0);
    }
    GXSetNumTevStages((unsigned char)(tevStage + 1));
    GXSetNumTexGens((unsigned char)(texGen + 1));
    if (lbl_804C5700[13] != 0) {
        GXSetBlendMode(1, 4, 5, 5);
        GXSetNumIndStages(1);
        arg8 = 0;
        argC = 0;
        GXSetTevIndirect(0, 0, 0, 3, 1, 0, 0, 0, arg8, argC);
        GXSetIndTexOrder(0, 1, 2);
        GXSetNumTexGens(2);
        GXSetTexCoordGen2(1, 1, 0, 0x21, 0, 0x7D);
        lbl_8055FD80 = fn_802D2640;
    }
}
#pragma scheduling on
void fn_802D2AC4(void) {
    GXSetNumChans(1);
    GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
    fn_802DFAF4();
}

#pragma small_data off
extern char lbl_804C97D0;
#pragma small_data off
__declspec(section ".rodata") extern char lbl_804C97D0;
void *fn_802D2D04(void) {
    return &lbl_804C97D0 + 0xC;
}
#pragma small_data on
extern void *lbl_8055FD64;
void* fn_802D2D14(void) {
    return lbl_8055FD64;
}

#pragma dont_inline on
void fn_802D2ED8(int arg0, int arg1) {
    float matrix[12];
    int *base;

    if (arg1 == 0) {
        lbl_8055FD70 = 1;
        lbl_8055FD8C = -1;
    }
    base = lbl_804CA2D8;
    fn_801BFD34((unsigned char *)matrix + 0x24, (unsigned char *)arg0 + 0x24, base);
    fn_80015B20(matrix, (void *)arg0, base);
    fn_802D0DD4(lbl_804C5650, matrix);
    GXLoadPosMtxImm(lbl_804C5650, (arg1 * 4) - arg1);
}
#pragma dont_inline off

void fn_802D2F70(int arg0) {
    fn_802D2ED8(arg0, 0);
}

int fn_802D2F78(int *arg0, int *arg1) {
    int *data;
    int value;
    GXSetDrawSyncCallback();
    VIFlush();
    data = lbl_804C9760;
    value = data[2];
    *((unsigned char *)data + 0x14) = 1;
    *arg0 = value;
    *arg1 = data[3];
    return data[1];
}

void fn_802D2FD8(void) {
    ((unsigned char *)lbl_804C9760)[0x14] = 0;
    DCFlushRange((void *)lbl_804C9760[1],
        (unsigned long)(lbl_804C9760[4] * (lbl_804C9760[2] * lbl_804C9760[3])));
    VISetNextFrameBuffer((void *)lbl_804C9760[1]);
    VIFlush();
    VIWaitForRetrace();
    VISetBlack(0);
    lbl_804C9760[1] = lbl_804C9760[0];
}

void fn_802D3050(int arg0) {
    unsigned long value;

    value = (unsigned long)lbl_8055FD1C & 0xFFFFFFEF;
    if (arg0 != 0) {
        value = (unsigned long)lbl_8055FD1C | 0x10;
    }
    lbl_8055FD1C = (void *)value;
}

void fn_802D306C(unsigned char arg0) {
    lbl_8055FD60 = arg0;
    GXSetDstAlpha(1, arg0);
}

void fn_802D307C(void) {
    int mtx[6];
    mtx[0] = lbl_802FACB0[0];
    mtx[1] = lbl_802FACB0[1];
    mtx[2] = lbl_802FACB0[2];
    mtx[3] = lbl_802FACB0[3];
    mtx[4] = lbl_802FACB0[4];
    mtx[5] = lbl_802FACB0[5];
    GXSetIndTexMtx(1, mtx, 1, lbl_802FACB0[4], lbl_802FACB0[3], lbl_802FACB0[2], lbl_802FACB0[1], lbl_802FACB0[0]);
}

extern void *lbl_8055FD5C;
void fn_802D30DC(void* hi) {
    lbl_8055FD5C = hi;
}

void* fn_802D30E4(void) {
    return (char*)lbl_8055FD54 + 0x24;
}

#pragma dont_inline on
void* fn_802D30F0(void) {
    return (char*)lbl_8055FE1C + 0x24;
}
#pragma dont_inline off

void fn_802D30FC(void) {
    fn_802D30F0();
}

void fn_802D3100(void) {
    fn_802D30F0();
}

extern void fn_802D307C(void);
#pragma dont_inline on
void* fn_802D3104(void) {
    struct { char pad[0x24]; char m; } *p;
    fn_802D307C();
    p = lbl_8055FD5C;
    return &p->m;
}
#pragma dont_inline off

void* fn_802D312C(void) {
    return fn_802D3104();
}

void* fn_802D3130(void) {
    return fn_802D3104();
}

void fn_802D3134(void) {
    fn_802D3104();
}

extern void *lbl_8055FD58;
void* fn_802D3138(void) {
    return (char*)lbl_8055FD58 + 0x24;
}

void fn_802D3304(void) {
    lbl_804C5700[0] = 1;
    fn_802CFF50();
    lbl_8055FDB4 = 0;
    GXSetCullMode(0);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOp(0, 0);
}

extern unsigned char lbl_8055FD84;
extern void fn_802CF5D4(void);
extern void fn_802D2640(void);
extern void fn_802D92B0(void);

extern void GXSetTevOrder(int, int, int, int);
extern void GXSetTevOp(int, int);
extern void GXSetCurrentMtx(int);
#pragma dont_inline on
void fn_802D3360(void) {
    int var_r31;
    fn_802CF5D4();
    lbl_8055FD84 = 1;
    lbl_804C5700[0] = 1;
    fn_802CFF50();
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    var_r31 = 0;
    do {
        GXSetTexCoordGen2(var_r31, 1, 4, 0x3C, 0, 0x7D);
        var_r31 += 1;
    } while (var_r31 < 4);
    fn_802D2640();
    if (lbl_8055FE1C != 0) fn_802D92B0();
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOp(0, 0);
    GXSetCurrentMtx(0);
}
#pragma dont_inline reset
void fn_802D37E4(void) {
    int i = 4;
    unsigned char *p = (unsigned char *)lbl_804C9984;
    do {
        p[0xC] = 0; p[0xD] = 0;
        p[0x24] = 0; p[0x25] = 0;
        p[0x3C] = 0; p[0x3D] = 0;
        p[0x54] = 0; p[0x55] = 0;
        p[0x6C] = 0; p[0x6D] = 0;
        p[0x84] = 0; p[0x85] = 0;
        p[0x9C] = 0; p[0x9D] = 0;
        p[0xB4] = 0; p[0xB5] = 0;
        p[0xCC] = 0; p[0xCD] = 0;
        p[0xE4] = 0; p[0xE5] = 0;
        p[0xFC] = 0; p[0xFD] = 0;
        p[0x114] = 0; p[0x115] = 0;
        p[0x12C] = 0; p[0x12D] = 0;
        p[0x144] = 0; p[0x145] = 0;
        p[0x15C] = 0; p[0x15D] = 0;
        p[0x174] = 0; p[0x175] = 0;
        p += 0x180;
    } while (--i);
    *(int *)(lbl_804C9984 + 0x700) = 0;
}

void fn_802D3894(void) {
    unsigned char *p;
    int i;
    p = lbl_804C9984;
    i = 0;
    do {
        if (p[0xC] == 0) break;
        fn_802E317C((const char *)lbl_8034C1C4);
        i++;
        if (i >= 0x40) break;
        p += 0x18;
    } while (1);
}

void fn_802D3900(void) {
    unsigned char *base;
    unsigned char *slot;
    int count = 0;
    void *light;
    unsigned long result;
    slot = lbl_804C9984;
    base = slot;
    while (count < *(int *)(base + 0x700)) {
        light = *(void **)(slot + 0x600);
        GXInitLightDir(*(unsigned long *)light, *(unsigned long *)((char *)light + 4), &result);
        *(unsigned char *)((char *)light + 0xD) =
            *(unsigned long *)((char *)light + 8) < result;
        slot += 4;
        count++;
    }
    *(int *)(base + 0x700) = 0;
}

extern char lbl_8034C1E4[];
extern float lbl_80564F88;
#pragma processor 7400
void *fn_802D39A4(float value) {
    unsigned char *p;
    int index = 0;
    unsigned char *found = 0;
    int count;
    int active;
    float initialValue;

    p = (unsigned char *)lbl_804C9984;
    for (count = 0; count < 0x40; ++count) {
        if (p[0xC] == 0) {
            found = (unsigned char *)lbl_804C9984 + index * 0x18;
            break;
        }
        p += 0x18;
        index++;
    }
    if (found == 0)
        fn_802E317C(lbl_8034C1E4);
#pragma scheduling off
    active = 1;
    initialValue = lbl_80564F88;
    found[0xC] = active;
    found[0xD] = 0;
    *(float *)(found + 0x10) = value;
    *(float *)(found + 0x14) = initialValue;
#pragma scheduling on
    return found;
}
#pragma processor gekko
void fn_802D3A50(void *arg0) { ((unsigned char *)arg0)[0xC] = 0; }

extern float lbl_80564F88, lbl_80564F8C, lbl_80564FB8, lbl_80564FBC, lbl_80564FE8, lbl_80564FEC;
#pragma push
#pragma paired off
#pragma paired_single off
#pragma scheduling on
int fn_802D3A5C(void *arg0, float *arg1) {
    extern unsigned char lbl_804C9778[];
    int x = (int)arg1[0];
    int y = (int)(lbl_80564FB8 * arg1[1] / lbl_80564FBC);
    float target;

    if (*((unsigned char *)arg0 + 0xD))
        target = lbl_80564F8C;
    else
        target = lbl_80564F88;

    if (x >= 0 && x < 640 && y >= 0 && y < 448) {
        float z, delta, nearZ, farZ, a, b;

        *(int *)arg0 = x;
        z = -arg1[2];
        *((int *)arg0 + 1) = y;
        nearZ = *(float *)(lbl_804C9778 + 4);
        farZ = *(float *)(lbl_804C9778 + 8);
        delta = farZ - nearZ;
        a = -nearZ / delta;
        b = farZ * nearZ / delta;
        *((unsigned int *)arg0 + 2) = (unsigned int)(lbl_80564FE8 + lbl_80564FE8 * ((z * a - b) / -z));
        if (*(int *)(lbl_804C9984 + 0x700) < 64) {
            *(void **)(lbl_804C9984 + 0x600 + *(int *)(lbl_804C9984 + 0x700) * 4) = arg0;
            ++*(int *)(lbl_804C9984 + 0x700);
        }
    } else {
        *((unsigned char *)arg0 + 0xD) = 0;
    }

    {
        float old = *(float *)((char *)arg0 + 0x14);
        float value = old + *(float *)((char *)arg0 + 0x10) * (target - old);
        *(float *)((char *)arg0 + 0x14) = value;
        return value >= lbl_80564FEC;
    }
}
#pragma pop

void fn_802D3BB0(void) {}

extern float lbl_80564F88, lbl_80564F8C;
extern unsigned short lbl_802FACC8[];
extern void fn_802D68C4(float *, int, unsigned short *, int, unsigned short, unsigned short, unsigned short, unsigned short *, float, float, float, float, float, float, float, float, float, float, float, float, float);
void fn_802D3BB4(float *arg0, float *arg1, float *arg2, float *arg3, unsigned int arg4, float scale, unsigned int arg_sp0) {
    float result[24];
    unsigned short colors[6];
    float neg = -scale;
    float a0=arg2[0],a1=arg2[1],a2=arg2[2],b0=arg3[0],b1=arg3[1],b2=arg3[2];
    float p0=arg1[0],p1=arg1[1],p2=arg1[2];
    unsigned int alpha = (unsigned int)(arg0[5] * (float)(arg4 >> 24)) << 24 | (arg4 & 0xFFFFFF);
    colors[0]=lbl_802FACC8[0]; colors[1]=lbl_802FACC8[2]; colors[2]=lbl_802FACC8[4];
    colors[3]=lbl_802FACC8[6]; colors[4]=lbl_802FACC8[8]; colors[5]=lbl_802FACC8[5];
    result[0]=p0+a0*scale; result[1]=p1+a1*scale; result[2]=p2+b2*scale;
    result[3]=p0+b0*scale; result[4]=p1+b1*scale; result[5]=p2+b2*scale;
    result[6]=p0+b0*neg; result[7]=p1+b1*neg; result[8]=p2+b2*neg;
    result[9]=p0+a0*neg; result[10]=p1+a1*neg; result[11]=p2+a2*neg;
    result[12]=p0+b0*neg; result[13]=p1+b1*neg; result[14]=p2+b2*neg;
    result[15]=p0+a0*scale; result[16]=p1+a1*scale; result[17]=p2+b2*scale;
    result[18]=p0+a0*neg; result[19]=p1+a1*neg; result[20]=p2+a2*neg;
    result[21]=p0+b0*scale; result[22]=p1+b1*scale; result[23]=p2+b2*scale;
    fn_802D68C4(result,4,colors,6,colors[5],colors[4],colors[0],lbl_802FACC8,result[20],lbl_80564F88,result[13],result[18],result[14],result[10],result[6],result[8],result[2],result[4],result[3],result[0],p2);
}

void fn_802D3D50(void) {
    lbl_804C97B0[0] = 0;
    lbl_804C97B0[0x1C] = 1;
}

extern void OSReport(const char *, ...);
extern void GXInitVtxDescList(int);
extern void GXDisableBreakPt(void);
extern void GXLoadTexObj(void *, int, void *);
extern volatile int lbl_8055FDD0;
extern char lbl_8034C204[];
void fn_802D3D6C(void) {
    lbl_804C5700[12] = 1;
}

void fn_802D3D80(void) {
    lbl_804C5700[12] = 0;
}

extern void GXLoadTexMtxImm(void *, unsigned int, unsigned char);
void fn_802D3D94(void *arg1, int arg0) {
    unsigned int id;
    GXLoadTexMtxImm(arg1, arg0 * 30, 1);
}

#pragma scheduling invalid_target
void fn_802D3DAC(void) {
    int id;

    if ((lbl_8055FDD0 & 0x3F) == 0) {
        OSReport(lbl_8034C204);
    }
    id = lbl_8055FDD0;
    lbl_8055FDD0 = id + 1;
    GXInitVtxDescList(id);
    GXDisableBreakPt();
}
#pragma scheduling on
void fn_802D3DF8(int arg0, signed char arg1, float farg0, float farg1) {
    float mtx[2][3];
    lbl_804C5700[13] = 1;
    GXLoadTexObj((char *)arg0 + 0x24, 2, lbl_804C5700);
    *(int *)&mtx[0][0] = 0;
    *(int *)&mtx[1][1] = 0;
    *(int *)&mtx[0][1] = 0;
    *(int *)&mtx[0][2] = 0;
    *(int *)&mtx[1][0] = 0;
    *(int *)&mtx[1][2] = 0;
    mtx[0][0] = farg0;
    mtx[1][1] = farg1;
    GXSetIndTexMtx(1, mtx, arg1);
}

extern unsigned long lbl_8055D0B8;
__declspec(section ".data") extern unsigned char lbl_804C5710[4];
extern int lbl_8055FD4C;
extern unsigned char lbl_8055FD50;
extern unsigned char lbl_804C5700[12];
void fn_802D3E88(void) {
    unsigned char *p = &lbl_804C5700[0xD];
    *p = 0;
}

extern int lbl_804C5710_int;
void fn_802D3E9C(unsigned char arg0) {
    unsigned char *p;
    p = lbl_804C5710;
    lbl_8055FD50 = arg0;
    lbl_8055FD4C = 0;
    p[1] = 0;
    p[0] = 0;
}

int fn_802D3EBC(void) {
    return (lbl_8055D0B8 >> 0x1FU) ^ 1;
}

extern unsigned short lbl_8055FD86;
void fn_802D3ECC(unsigned short arg0) {
    lbl_8055FD86 = arg0;
}

extern unsigned long lbl_8055FD94;
extern unsigned long lbl_8055FDA0;
extern unsigned char lbl_804C97B0[];
extern unsigned long fn_802CE9FC();
extern int fn_802CFF64(int);
extern unsigned char lbl_8055FD78;
extern int lbl_8055D0BC;
extern int lbl_8055D0C0;
extern unsigned char lbl_8055FD18;
extern int GXSetCullMode(int);
extern int GXSetDrawSyncCallback(void);
extern int VIFlush(void);
extern int lbl_804C9760[];
extern int DCFlushRange(void *, unsigned long);
extern int VISetNextFrameBuffer(void *);
extern int VIWaitForRetrace(void);
extern int VISetBlack(int);
extern char lbl_8055FD70;
extern int lbl_8055FD8C;
extern int lbl_804CA2D8[];
extern int lbl_804C5650[];
extern int fn_801BFD34(void *, void *, void *);
extern int fn_80015B20(void *, void *, void *);
extern int fn_802D0DD4(void *, void *);
extern int GXLoadPosMtxImm(void *, int);
extern void fn_802D2ED8(int, int);
extern unsigned long lbl_8055D0B8;
extern unsigned char lbl_804C5710[4];
extern int lbl_8055FD4C;
extern unsigned char lbl_8055FD50;
extern unsigned char lbl_804C5700[12];
extern unsigned char lbl_8055FD60;
extern int GXSetDstAlpha(int, int);
extern unsigned long lbl_8055D0B8;
extern unsigned char lbl_804C5710[4];
extern int lbl_8055FD4C;
extern unsigned char lbl_8055FD50;
extern unsigned char lbl_804C5700[12];
extern unsigned char lbl_8055FD91;
extern unsigned char lbl_8055D0FF;
extern char lbl_8055D100;
  extern void fn_802E2E0C(void (*)(void), void *);
  extern int lbl_804C9760[];
