// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed long s32;
extern unsigned char lbl_80558E80[];
extern int __cntlzw(unsigned int);
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

unsigned int GXSetBreakPtCallback(unsigned int value) {
    extern void OSRestoreInterrupts(void);
    unsigned int old = lbl_8055D954;
    OSDisableInterrupts();
    lbl_8055D954 = value;
    OSRestoreInterrupts();
    return old;
}

extern void *lbl_8055D94C;
void* GXGetCurrentGXThread(void) {
    return lbl_8055D94C;
}

void *GXInitVtxDescList(void) {
    void *temp = lbl_8055D94C;
    lbl_8055D94C = 0;
    return temp;
}

void __GXSetVCD(void) {
    unsigned int *data = __GXData;
    unsigned int value;
    unsigned int count;

    *(volatile unsigned char *)0xCC008000 = 8;
    *(volatile unsigned char *)0xCC008000 = 0x50;
    *(volatile unsigned int *)0xCC008000 = data[0x14 / 4];
    *(volatile unsigned char *)0xCC008000 = 8;
    *(volatile unsigned char *)0xCC008000 = 0x60;
    *(volatile unsigned int *)0xCC008000 = data[0x18 / 4];
    if (*(unsigned char *)((char *)data + 0x525)) {
        count = 2;
    } else {
        count = *(unsigned char *)((char *)data + 0x524) != 0;
    }
    value = (data[0x14 / 4] & 0x78000) >> 15;
    value = (0x21 - __builtin_clz(value)) >> 1;
    count = count * 4;
    value |= count;
    count = 0x21 - __builtin_clz(data[0x18 / 4] & 0xFFFF);
    value |= count << 28;
    *(volatile unsigned char *)0xCC008000 = 0x10;
    *(volatile unsigned int *)0xCC008000 = 0x1008;
    *(volatile unsigned int *)0xCC008000 = value;
    *(unsigned short *)((char *)data + 2) = 1;
}

void GXClearVtxDesc(void) {
    unsigned int *data = __GXData;
    unsigned int zero = 0;
    unsigned int value = 1;
    data[0x14 / 4] = (zero & ~0x600) | ((value << 9) & 0x600);
    data[0x18 / 4] = zero;
    *((unsigned char *)data + 0x524) = zero;
    *((unsigned char *)data + 0x525) = zero;
    data[0x5FC / 4] |= 8;
}

void __GXSetVAT(void) {
    unsigned int *data = __GXData;
    unsigned int *ptr = data;
    unsigned int i = 0;
    unsigned int mask = *(unsigned char *)((char *)data + 0x5FB);
    do {
        if (mask & 1) {
            *(volatile unsigned char *)0xCC008000 = 8;
            *(volatile unsigned char *)0xCC008000 = i | 0x70;
            *(volatile unsigned int *)0xCC008000 = ptr[0x1C / 4];
            *(volatile unsigned char *)0xCC008000 = 8;
            *(volatile unsigned char *)0xCC008000 = i | 0x80;
            *(volatile unsigned int *)0xCC008000 = ptr[0x3C / 4];
            *(volatile unsigned char *)0xCC008000 = 8;
            *(volatile unsigned char *)0xCC008000 = i | 0x90;
            *(volatile unsigned int *)0xCC008000 = ptr[0x5C / 4];
        }
        mask >>= 1;
        ptr++;
        i++;
    } while (mask);
    *(volatile unsigned char *)0xCC008000 = 0;
    *(unsigned char *)((char *)data + 0x5FB) = 0;
}

void GXSetArray(s32 arg0, unsigned int arg1, unsigned int arg2) {
    s32 size;
    s32 base;
    size = arg0;
    if (size == 0x19) {
        size = 0xA;
    }
    base = size - 0x9;
    *(volatile unsigned char *)0xCC008000 = 8;
    *(volatile unsigned char *)0xCC008000 = base | 0xA0;
    *(volatile unsigned int *)0xCC008000 = arg1 & 0x3FFFFFFF;
    *(volatile unsigned char *)0xCC008000 = 8;
    *(volatile unsigned char *)0xCC008000 = base | 0xB0;
    *(volatile unsigned int *)0xCC008000 = arg2;
}

void GXInvalidateVtxCache(void) {
    *(volatile unsigned char *)0xCC008000 = 0x48;
}

void GXSetNumTexGens(unsigned int value) {
    unsigned int *data = __GXData;
    data[0x254 / 4] = (data[0x254 / 4] & 0x0FFFFFFF) | (value & 0xF0000000);
    data[0x5FC / 4] |= 0x200;
    data[0x5FC / 4] |= 4;
}

void GXInitLightSpot(s32 arg0, s32 arg1) {
    unsigned int reg = 0;

    reg = (reg & 0xFFFFFE00) | (arg1 & 0xFF) | ((arg0 & 1) << 8);
    __peReg[2] = reg;
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

void GXSetChanAmbColor(short intr, void *ctx) {
    char local[0x2D0];

    __peReg[5] |= 8;
    lbl_8055D970 = 1;
    if (lbl_8055D974 != 0) {
        OSClearContext(local);
        OSSetCurrentContext(local);
        ((void (*)(void))lbl_8055D974)();
        OSClearContext(local);
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

void GXInitLightPos(void *arg0, float farg0, float farg1, float farg2) {
    *(float *)((char *)arg0 + 0x28) = farg0;
    *(float *)((char *)arg0 + 0x2C) = farg1;
    *(float *)((char *)arg0 + 0x30) = farg2;
}

void GXGetLightDir_Internal(void *arg0, float farg0, float farg1, float farg2, float farg3, float farg4, float farg5) {
 extern float lbl_80560B5C;
 float a, b, c;
 *(volatile float *)((char *)arg0 + 0x34) = farg3;
 a = lbl_80560B5C * farg0;
 b = lbl_80560B5C * farg1;
 *(volatile float *)((char *)arg0 + 0x38) = farg4;
 c = lbl_80560B5C * farg2;
 *(volatile float *)((char *)arg0 + 0x3C) = farg5;
 *(volatile float *)((char *)arg0 + 0x28) = a;
 *(volatile float *)((char *)arg0 + 0x2C) = b;
 *(volatile float *)((char *)arg0 + 0x30) = c;
}

void GXInitLightColor(void *arg0, s32 *arg1) { *(s32 *)((char *)arg0 + 0xC) = *arg1; }

void GXLoadLightObjImm(void *arg0, s32 arg1) {
    unsigned int i;
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifo32 = (volatile unsigned int *)0xCC008000;
    float *src = (float *)((char *)arg0 + 0x10);
    fifo8[0] = 0x10;
    fifo32[0] = ((0x1F - __cntlzw(arg1)) << 4) + 0xF0600;
    fifo32[0] = *(unsigned int *)((char *)arg0 + 0xC);
    fifo32[0] = 0;
    fifo32[0] = 0;
    for (i = 0; i < 6; i++) fifo32[0] = ((unsigned int *)src)[i * 2];
    *__GXData; 
}

extern void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, int);
void GXInitTexObjCI(void *obj, void *image, unsigned short width, unsigned short height, int format, int wrap_s, int wrap_t, int mipmap, int tlut_name) {
    GXInitTexObj(obj, image, width, height, format, wrap_s, wrap_t, mipmap);
    *(int *)((char *)obj + 0x18) = tlut_name;
    *(unsigned char *)((char *)obj + 0x1F) &= ~2;
}

void GXInitTexObjTlut(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

extern unsigned char lbl_80558E80[];
void GXInitTexObjFilter(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp = *arg0;
    temp = (temp & ~0x10) | (((unsigned int)__cntlzw(arg2 - 1) >> 1) & 0x10);
    *arg0 = temp;
    *arg0 = (temp & ~0xE0) | ((lbl_80558E80[arg1] << 5) & 0xE0);
}

void GXGetTexObjWidth(void *arg0, s32 arg1) {
    *(s32 *)((char *)arg0 + 0x10) = arg1;
}

int GXGetTexObjHeight(void *arg0) {
    return ((int *)arg0)[4];
}

s32 GXGetTexObjFmt(void *arg0) {
    return (*(s32 *)((char *)arg0 + 0xC) << 5) & 0x1FFFFFE0;
}

unsigned short GXGetTexObjWrapS(void *arg0) {
    return (unsigned short)(((*(unsigned int *)((char *)arg0 + 8)) & 0x3FF) + 1);
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

void GXLoadTexObj(void *arg0, unsigned int arg1) {
    unsigned int *data = __GXData;
    void *result;
    result = ((void *(*)(void *))data[0x518 / 4])(arg0);
    GXLoadTexObjPreLoaded(arg0, result, arg1);
}

void GXInitTlutObj(void *arg0, unsigned int arg1, int arg2, short arg3) {
    unsigned int value = *(unsigned int *)((char *)arg0 + 4);
    unsigned int size = 0;
    value = (arg1 << 27) | (value & 0xFF);
    size |= arg2 << 10;
    *(short *)((char *)arg0 + 8) = arg3;
    value |= 0x64000000;
    *(unsigned int *)arg0 = size;
    *(unsigned int *)((char *)arg0 + 4) = value;
}

unsigned short GXGetTexObjTlut(void *arg0) {
    return *(unsigned short *)((char *)arg0 + 8);
}

void GXLoadTlut(void *arg0, int arg1) {
    void *obj;
    unsigned int value;
    obj = ((void *(*)(int))__GXData[0x51C / 4])(arg1);
    __GXFlushTextureState();
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = *(unsigned int *)((char *)arg0 + 4);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = *(unsigned int *)obj;
    __GXFlushTextureState();
    value = *(unsigned int *)arg0;
    value = (value & 0xFFFFFC00) | (*(unsigned int *)obj & 0x3FF);
    *(unsigned int *)((char *)obj + 4) = value;
    *(unsigned int *)((char *)obj + 8) = *(unsigned int *)((char *)arg0 + 4);
    *(unsigned int *)((char *)obj + 0xC) = *(unsigned int *)((char *)arg0 + 8);
    *(unsigned int *)arg0 = value;
}

extern void GXSetTevIndirect(int, int, int, int, int, int, int, int);
void GXSetTevDirect(int arg0) {
    GXSetTevIndirect(arg0, 0, 0, 0, 0, 0, 0, 0);
}

void __GXUpdateBPMask(void) {}

