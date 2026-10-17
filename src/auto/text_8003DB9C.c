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

void __GXSetGenMode(void) {
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = __GXData[0x22C / 4];
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXGetCullMode(s32 arg0, s32 arg1) {
    unsigned int value = (arg1 & 0xFF000000) | (arg0 << 8);
    __peReg[3] = value;
}

void GXGetLineWidth(s32 arg0) {
    unsigned int value = 0;
    value = (value & ~3) | (arg0 & 3);
    value |= 4;
    __peReg[4] = value;
}

void GXGetPointSize(s32 arg0) {
    unsigned short value = __peReg[1];
    value = (value & ~0x10) | ((arg0 << 4) & 0x10);
    __peReg[1] = value;
}

void GXInitLightAttnA(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 type;
    s32 clz3;
    s32 clz2;
    unsigned short value;

    type = 0;
    if (arg0 == 1) {
        type = 1;
    } else if (arg0 == 3) {
        type = 1;
    }
    clz3 = __cntlzw(arg0 - 3);
    clz2 = __cntlzw(arg0 - 2);
    value = __peReg[1];
    value = (value & ~1) | type;
    value = (value & ~0x800) | ((clz3 << 6) & 0x800);
    value = (value & ~2) | ((clz2 >> 4) & 2);
    value = (value & ~0xF000) | ((arg3 << 12) & 0xF000);
    value = (value & ~0x700) | ((arg1 << 8) & 0x700);
    value = (value & ~0xE0) | ((arg2 << 5) & 0xE0);
    value = (value & ~0xFF000000) | 0x41000000;
    __peReg[1] = value;
}

void GXInitLightAttnK(s32 arg0) {
    unsigned short value = __peReg[1];
    value = (value & 0xFFF7) | ((arg0 & 1) << 3);
    __peReg[1] = value;
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

void GXSetCopyClear(unsigned char *color, s32 depth) {
    unsigned int first = 0;
    unsigned int second = 0;
    unsigned int third = 0;
    volatile unsigned int *fifo = (volatile unsigned int *)0xCC008000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    first |= color[0];
    first |= color[3] << 8;
    first |= 0x4F000000;
    *fifo = first;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    second |= color[2];
    second |= color[1] << 8;
    second |= 0x50000000;
    *fifo = second;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    third |= depth;
    third |= 0x51000000;
    *fifo = third;
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetDispCopyGamma(s32 arg0) {
    unsigned int *data = __GXData;
    data[0x23C/4] = (data[0x23C/4] & 0xFFFFFE7F) | (arg0 << 7);
}

void GXClearBoundingBox(void) {
    register volatile unsigned int *fifo = (volatile unsigned int *)0xCC008000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *fifo = 0x550003FF;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *fifo = 0x560003FF;
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXInitLightAttn(void *arg0, float farg0, float farg1, float farg2, float farg3, float farg4, float farg5) {
    float *p = (float *)((char *)arg0 + 0x10);
    p[0] = farg0;
    p[1] = farg1;
    p[2] = farg2;
    p[3] = farg3;
    p[4] = farg4;
    p[5] = farg5;
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

void GXInitTexObjWrapMode(int *obj, int wrap_s, int wrap_t) { *obj = (*obj & 0xFFFFFFFC) | wrap_s; *obj = (*obj & 0xFFFFFFF3) | (wrap_t << 2); }

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

int GXGetTexObjAll(void *obj) {
    return (*(unsigned char *)((char *)obj + 0x1F)) & 1;
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

void GXInitTexCacheRegion(void *obj, signed char arg1, unsigned int arg2, int arg3, unsigned int arg4, int arg5) {
    int size;
    int tmem_even;
    int tmem_odd;
    unsigned int value;

    if (arg3 == 0) size = 3;
    else if (arg3 == 1) size = 4;
    else if (arg3 == 2) size = 5;
    else size = arg3;

    value = 0;
    value |= (arg2 >> 5) & 0x7FFF;
    value |= (size << 15) & 0x38000;
    value |= (size << 18) & 0x1C0000;
    *(unsigned int *)obj = value;

    if (arg5 == 0) tmem_even = 3;
    else if (arg5 == 1) tmem_even = 4;
    else if (arg5 == 2) tmem_even = 5;
    else if (arg5 == 3) tmem_even = 0;
    else tmem_even = arg5;

    tmem_odd = tmem_even;
    *(unsigned char *)((char *)obj + 0xC) = arg1;
    *(unsigned char *)((char *)obj + 0xD) = 1;
    value = 0;
    value |= (arg4 >> 5) & 0x7FFF;
    value |= (tmem_odd << 15) & 0x38000;
    value |= (tmem_odd << 18) & 0x1C0000;
    *(unsigned int *)((char *)obj + 4) = value;
}

void GXInvalidateTexAll(void) {
    __GXFlushTextureState();
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = 0x66001000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = 0x66001100;
    __GXFlushTextureState();
}

void *GXSetTexRegionCallback(void *callback) {
    void *old = (void *)*((unsigned int *)((char *)__GXData + 0x518));
    *((unsigned int *)((char *)__GXData + 0x518)) = (unsigned int)callback;
    return old;
}

void *GXSetTlutRegionCallback(void *callback) {
    void *old = (void *)*((unsigned int *)((char *)__GXData + 0x51C));
    *((unsigned int *)((char *)__GXData + 0x51C)) = (unsigned int)callback;
    return old;
}

void __SetSURegs(s32 arg0, s32 arg1) {
    unsigned int *data = __GXData;
    unsigned int *tex = data + arg0;
    unsigned int *su = data + arg1;
    unsigned int value;
    unsigned int su1;
    unsigned int su2;
    unsigned int mode;
    value = tex[0x564 / 4];
    su1 = (su[0x108 / 4] & 0xFFFF0000) | (value & 0x3FF);
    su[0x108 / 4] = su1;
    su2 = (su[0x128 / 4] & 0xFFFF0000) | ((value >> 10) & 0x3FF);
    su[0x128 / 4] = su2;
    mode = tex[0x584 / 4];
    su1 = (su1 & 0xFFFEFFFF) | ((__cntlzw((mode & 3) - 1) << 11) & 0x10000);
    su[0x108 / 4] = su1;
    su2 = (su2 & 0xFFFEFFFF) | ((__cntlzw(((mode >> 2) & 3) - 1) << 11) & 0x10000);
    su[0x128 / 4] = su2;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = su[0x108 / 4];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = su[0x128 / 4];
    *((unsigned short *)((char *)data + 2)) = 0;
}

extern void GXSetTevIndirect(int, int, int, int, int, int, int, int);
void GXSetTevDirect(int arg0) {
    GXSetTevIndirect(arg0, 0, 0, 0, 0, 0, 0, 0);
}

void __GXUpdateBPMask(void) {}

void GXSetClipMode(s32 arg0) {
    register volatile unsigned char *fifo = (volatile unsigned char *)0xCC008000;
    *fifo = 0x10;
    *(volatile unsigned int *)fifo = 0x1005;
    *(volatile unsigned int *)fifo = arg0;
    *(unsigned short *)((char *)__GXData + 2) = 1;
}

void __GXSetMatrixIndex(s32 arg0) {
    unsigned int *data = __GXData;

    if (arg0 < 5) {
        *(volatile unsigned char *)0xCC008000 = 8;
        *(volatile unsigned char *)0xCC008000 = 0x30;
        *(volatile unsigned int *)0xCC008000 = data[0x80 / 4];
        *(volatile unsigned char *)0xCC008000 = 0x10;
        *(volatile unsigned int *)0xCC008000 = 0x1018;
        *(volatile unsigned int *)0xCC008000 = data[0x80 / 4];
    } else {
        *(volatile unsigned char *)0xCC008000 = 8;
        *(volatile unsigned char *)0xCC008000 = 0x40;
        *(volatile unsigned int *)0xCC008000 = data[0x84 / 4];
        *(volatile unsigned char *)0xCC008000 = 0x10;
        *(volatile unsigned int *)0xCC008000 = 0x1019;
        *(volatile unsigned int *)0xCC008000 = data[0x84 / 4];
    }
    *(unsigned short *)((char *)data + 2) = 1;
}

void GXClearGPMetric(void) {
    __cpReg[2] = 4;
}

void KPADSetBtnRepeat(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    volatile unsigned short *cp;
    unsigned int first, second, low;
    cp=__cpReg; first=cp[0x42/2]; second=first;
    do { low=cp[0x40/2]; second=cp[0x42/2]; } while (second != first);
    *arg2=(second<<16)|low;
    cp=__cpReg; first=cp[0x46/2]; second=first;
    do { low=cp[0x44/2]; second=cp[0x46/2]; } while (second != first);
    *arg3=(second<<16)|low;
    cp=__cpReg; first=cp[0x4A/2]; second=first;
    do { low=cp[0x48/2]; second=cp[0x4A/2]; } while (second != first);
    *arg0=(second<<16)|low;
    cp=__cpReg; first=cp[0x4E/2]; second=first;
    do { low=cp[0x4C/2]; second=cp[0x4E/2]; } while (second != first);
    *arg1=(second<<16)|low;
}

