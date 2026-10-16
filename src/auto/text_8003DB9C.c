// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern unsigned int lbl_8055D954;
extern unsigned int lbl_8055D950;
extern unsigned char lbl_8055D948;
extern unsigned int *__GXData;
extern unsigned short *__cpReg;
extern unsigned short *__peReg;
extern unsigned int lbl_8037C0E4;
extern unsigned int lbl_8055D974;
extern void GXGetVtxDesc(void);
extern void __GXSaveFifo(void);

extern char lbl_8055D949;
char __GXIsGPFifoReady(void) {
    return lbl_8055D949;
}

void GXGetGPStatus(char *a, char *b, char *c, char *d, char *e) {
    unsigned int value = *__cpReg;
    __GXData[3] = value;
    *a = value & 1;
    *b = (__GXData[3] >> 1) & 1;
    *c = (__GXData[3] >> 2) & 1;
    *d = (__GXData[3] >> 3) & 1;
    *e = (__GXData[3] >> 4) & 1;
}

extern unsigned int lbl_8055D954;
extern unsigned int *__GXData;
extern unsigned short *__cpReg;
extern unsigned int lbl_8055D950;
extern unsigned char lbl_8055D948;
extern void GXGetVtxDesc(void);
extern void __GXSaveFifo(void);
extern unsigned int lbl_8037C0E4;
int GXGetCPUFifo(void *fifo) {
    unsigned int *src = &lbl_8037C0E4;
    unsigned int *dst = fifo;
    if (!lbl_8055D948) {
        return 0;
    }
    GXGetVtxDesc();
    __GXSaveFifo();
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];
    return 1;
}

void GXGetFifoPtrs(void *arg0, int *arg1, int *arg2) {
    int value1 = ((int *)arg0)[0x14 / 4];
    int value2 = ((int *)arg0)[0x18 / 4];
    *arg1 = value1;
    *arg2 = value2;
}

int GXGetFifoBase(int *arg0) {
    return *arg0;
}

int GXGetFifoSize(void *arg0) {
    return ((int *)arg0)[2];
}

int GXGetFifoCount(void *arg0) {
    return ((int *)arg0)[0x1C / 4];
}

unsigned char GXGetFifoWrap(void *arg0) { return *(unsigned char *)((char *)arg0 + 0x20); }

extern void *lbl_8055D94C;
void* GXGetCurrentGXThread(void) {
    return lbl_8055D94C;
}

void *GXInitVtxDescList(void) {
    void *temp = lbl_8055D94C;
    lbl_8055D94C = 0;
    return temp;
}

void GXInitLightDistAttn(unsigned int arg0) {
    unsigned short reg = __peReg[1];

    reg = (reg & ~0x4) | ((arg0 << 2) & 0x4);
    __peReg[1] = reg;
}

void GXGetLightPos(unsigned int x, unsigned int y, unsigned int z) {
    extern unsigned short *__peReg;
    *__peReg = (unsigned short)((x & 1) | ((y & 7) << 1) | ((z & 1) << 4));
}

void GXInitLightDir(unsigned int x, unsigned int y, unsigned int *arg2) {
    unsigned int addr = 0xC8000000;
    addr |= x << 2;
    addr |= y << 12;
    addr |= 1 << 22;
    *arg2 = *(unsigned int *)addr;
}

unsigned int GXGetLightDir(unsigned int value) {
    extern unsigned int lbl_8055D978;
    extern void OSRestoreInterrupts(void);
    unsigned int old = lbl_8055D978;
    OSDisableInterrupts();
    lbl_8055D978 = value;
    OSRestoreInterrupts();
    return old;
}

extern unsigned short *__peReg;
extern unsigned int lbl_8055D978;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);
extern unsigned int lbl_8055D968;
extern unsigned char lbl_8055D970;

typedef struct { char pad[0x2C8]; } OSContext;

#define SET_REG_FIELD(line, reg, size, shift, val) \
    ((reg) = ((unsigned int)(reg) & ~(((1 << (size)) - 1) << (shift))) | ((unsigned int)(val) << (shift)))

typedef void (*GXPEIntrHandler)(short, void *);

typedef void (*GXPEIntrHandler)(short, void *);
extern GXPEIntrHandler __OSSetInterruptHandler(int type, GXPEIntrHandler handler);
extern unsigned int __OSUnmaskInterrupts(unsigned int userMask);
extern void OSWakeupThread(void *);
extern void OSInitThreadQueue(void *);
extern void (*lbl_8055D978_callback)(unsigned short);
void GXInitSpecularDir(unsigned int arg0, void *ctx) {
    extern unsigned int lbl_8055D978;
    extern unsigned short *__peReg;
    extern void OSClearContext(void *);
    extern void OSSetCurrentContext(void *);
    char local[0x2D0];
    unsigned short value = __peReg[7];
    if (lbl_8055D978 != 0) {
        OSClearContext(local + 8);
        OSSetCurrentContext(local + 8);
        ((void (*)(unsigned short))lbl_8055D978)(value);
        OSClearContext(local + 8);
        OSSetCurrentContext(ctx);
    }
    __peReg[5] |= 4;
}

unsigned int GXLoadLightObjIndx(unsigned int value) {
    unsigned int old = lbl_8055D974;

    OSDisableInterrupts();
    lbl_8055D974 = value;
    OSRestoreInterrupts();
    return old;
}

void GXSetChanAmbColor(void *ctx) {
    extern unsigned short *__peReg;
    extern unsigned int lbl_8055D974;
    extern unsigned int lbl_8055D968;
    extern unsigned char lbl_8055D970;
    extern void OSClearContext(void *);
    extern void OSSetCurrentContext(void *);
    extern void OSWakeupThread(void *);
    char local[0x2D0];

    __peReg[5] |= 8;
    lbl_8055D970 = 1;
    if (lbl_8055D974 != 0) {
        OSClearContext(local + 8);
        OSSetCurrentContext(local + 8);
        ((void (*)(void))lbl_8055D974)();
        OSClearContext(local + 8);
        OSSetCurrentContext(ctx);
    }
    OSWakeupThread(&lbl_8055D968);
}

void __GXPEInit(void) {
    __OSSetInterruptHandler(0x12, (GXPEIntrHandler)GXInitSpecularDir);
    __OSSetInterruptHandler(0x13, (GXPEIntrHandler)GXSetChanAmbColor);
    OSInitThreadQueue(&lbl_8055D968);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);

    __peReg[5] |= 0xF;
}

void GXInitTexObjTlut(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

int GXGetTexObjHeight(void *arg0) {
    return ((int *)arg0)[4];
}

unsigned short GXGetTexObjWrapT(void *arg0) {
    return (unsigned short)(((*(unsigned int *)((char *)arg0 + 8)) >> 10) & 0x3ff) + 1;
}

int GXGetTexObjMipMap(void *arg0) {
    return *(int *)((char *)arg0 + 0x14);
}

int GXGetTexObjLODAll(int *arg0) {
    return *arg0 & 3;
}

int GXGetTexObjWrap_Internal(unsigned int *arg0) {
    return (*arg0 >> 2) & 3;
}

