// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void __GXSetDirtyState(void);
extern void __GXFlushTextureState(void);
extern void __GXSetVAT(void);
extern void __GXSetSUTexRegs(void);
extern void __GXUpdateBPMask(void);
extern void __GXSetProjection(void);
extern void __GXSetViewport(void);
extern void __GXSetMatrixIndex(s32);
extern void GXCPInterruptHandler(short, void *);
typedef void (*GXFifoIntrHandler)(short, void *);
extern void *OSGetCurrentThread(void);
extern void OSSleepThread(void *);
extern void memset(void *, int, unsigned int);
extern unsigned int lbl_8055D958;
extern void *lbl_8055D95C;
extern void *lbl_8055D94C;
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);
extern void OSResumeThread(void *);
extern void OSSuspendThread(void *);
#define GXD (*(unsigned int * volatile *)&__GXData)
extern unsigned char lbl_80558E80;
extern int __cntlzw(unsigned int);
extern unsigned int lbl_8055D954;
extern unsigned int lbl_8055D950;
extern unsigned char lbl_8055D948;
extern unsigned int * const __GXData;
typedef union { volatile unsigned char u8; volatile unsigned int u32; } GXCopyFifo;
#define GXCopyWGFifo (*(GXCopyFifo *)0xCC008000)
extern unsigned int lbl_8055D968;
extern unsigned int lbl_8055D930;
extern unsigned int lbl_8055D938;
extern unsigned int lbl_8055D93C;
extern unsigned int lbl_8055D940;
extern unsigned char lbl_8055D970;
extern unsigned short *__cpReg;
extern unsigned short *__peReg;
extern unsigned char lbl_8037C0C0[];
extern unsigned char lbl_8037C0E4[];
extern unsigned int *__piReg;
extern unsigned int *__memReg;
extern signed long long OSGetTime(void);
extern unsigned int GXSetBreakPtCallback(unsigned int);
extern unsigned int GXGetLightDir(unsigned int);
extern unsigned int GXLoadLightObjIndx(unsigned int);
extern void GXGetVtxAttrFmt(void);

typedef struct {
    void *base;
    void *top;
    int size;
    int hiWatermark;
    int loWatermark;
    void *rdPtr;
    void *wrPtr;
    int count;
    unsigned char wrap;
} GXFifoObjInternal;
extern unsigned int lbl_8055D974;
extern f32 lbl_80560B40;
extern f64 lbl_80560B48;
extern f32 lbl_80560B88;
extern u32 __cvt_fp2unsigned(f32);
  extern void GXGetVtxDesc(void);
  extern void __GXSaveFifo(void);
typedef struct {
    u8 r, g, b, a;
} GXColor;

#ifndef GX_BITSET
#define GX_BITSET(field, pos, size, value) \
    __rlwimi((field), (value), 31 - (pos) - (size) + 1, (pos), (pos) + (size) - 1)
#endif
#define GX_FOG_GET_PROJ(x) ((x) >> 3 & 1)
#define GX_FOG_GET_FSEL(x) ((x) & 7)
#define GX_BP_SET_OPCODE(cmd, opcode) (cmd) = GX_BITSET(cmd, 0, 8, (opcode))
#define GX_BP_SET_FOGPARAM0_A_MANT(reg, x) ((reg) = GX_BITSET((reg), 21, 11, x))
#define GX_BP_SET_FOGPARAM0_A_EXP(reg, x) ((reg) = GX_BITSET((reg), 13, 8, x))
#define GX_BP_SET_FOGPARAM0_A_SIGN(reg, x) ((reg) = GX_BITSET((reg), 12, 1, x))
#define GX_BP_SET_FOGPARAM1_B_MAG(reg, x) ((reg) = GX_BITSET((reg), 8, 24, x))
#define GX_BP_SET_FOGPARAM2_B_SHIFT(reg, x) ((reg) = GX_BITSET((reg), 27, 5, x))
#define GX_BP_SET_FOGPARAM3_C_MANT(reg, x) ((reg) = GX_BITSET((reg), 21, 11, x))
#define GX_BP_SET_FOGPARAM3_C_EXP(reg, x) ((reg) = GX_BITSET((reg), 13, 8, x))
#define GX_BP_SET_FOGPARAM3_C_SIGN(reg, x) ((reg) = GX_BITSET((reg), 12, 1, x))
#define GX_BP_SET_FOGPARAM3_PROJ(reg, x) ((reg) = GX_BITSET((reg), 11, 1, x))
#define GX_BP_SET_FOGPARAM3_FSEL(reg, x) ((reg) = GX_BITSET((reg), 8, 3, x))
#define GX_BP_SET_FOGCOLOR_RGB(reg, x) ((reg) = GX_BITSET((reg), 8, 24, x))
#define GX_BP_REG_FOGPARAM0 0xEE
#define GX_BP_REG_FOGPARAM1 0xEF
#define GX_BP_REG_FOGPARAM2 0xF0
#define GX_BP_REG_FOGPARAM3 0xF1
#define GX_BP_REG_FOGCOLOR  0xF2
static volatile union {
    char c;
    short s;
    int i;
    unsigned char uc;
    unsigned short us;
    unsigned int ui;
    float f;
} WGPIPE : 0xCC008000;
#define GX_FIFO_CMD_LOAD_BP_REG 0x61
#define GX_BP_LOAD_REG(data) \
    WGPIPE.c = GX_FIFO_CMD_LOAD_BP_REG; \
    WGPIPE.i = (data)

typedef struct {
    unsigned short unused0 : 11;
    unsigned short pointSize : 1;
    unsigned short unused1 : 4;
} GXPointSizeReg;

typedef struct {
    unsigned short unused0 : 12;
    unsigned short attenuationK : 1;
    unsigned short unused1 : 3;
} GXAttnKReg;

typedef struct {
    unsigned short unused0 : 13;
    unsigned short distanceAttn : 1;
    unsigned short unused1 : 2;
} GXDistAttnReg;

typedef struct {
    unsigned int unused0 : 23;
    unsigned int gamma : 2;
    unsigned int unused1 : 7;
} GXDispCopyGammaReg;

typedef struct {
    unsigned int unused : 28;
    unsigned int wrapT : 2;
    unsigned int wrapS : 2;
} GXTexWrapReg;

typedef struct {
    int attr;
    int compCnt;
    int compType;
    unsigned char shift;
} GXVtxAttrFmtList;

          static void __GXGetTexTileShift_8003DB9C(unsigned int fmt, unsigned int *rowTileS, unsigned int *colTileS) {
      switch (fmt) {
      case 0x0:
      case 0x8:
      case 0xE:
      case 0x20:
      case 0x30:
          *rowTileS = 3;
          *colTileS = 3;
          break;
      case 0x1:
      case 0x2:
      case 0x9:
      case 0x11:
      case 0x22:
      case 0x27:
      case 0x28:
      case 0x29:
      case 0x39:
      case 0x3A:
          *rowTileS = 3;
          *colTileS = 2;
          break;
      case 0x3:
      case 0x4:
      case 0x5:
      case 0x6:
      case 0xA:
      case 0x13:
      case 0x16:
      case 0x23:
      case 0x2B:
      case 0x2C:
      case 0x3C:
          *rowTileS = 2;
          *colTileS = 2;
          break;
      default:
          *rowTileS = *colTileS = 0;
          break;
      }
  }

typedef struct _GXLightObjImpl {
      char UNK_0x0[0xC];
      char UNK_0xC[0x4];
      f32 aa;
      f32 ab;
      f32 ac;
      f32 ka;
      f32 kb;
      f32 kc;
  } GXLightObjImpl;

  typedef enum _GXDistAttnFn {
      GX_DA_OFF,
      GX_DA_GENTLE,
      GX_DA_MEDIUM,
      GX_DA_STEEP
  } GXDistAttnFn;

  extern char lbl_8055D949;
  extern char lbl_8055D960;
  extern int OSDisableInterrupts(void);
  extern void OSRestoreInterrupts(void);
/*
 * Default texture region callback: selects a GXTexRegion based on mipmap
 * configuration for the given texture object and texmap.
 */
void *__GXDefaultTexRegionCallback(void *obj, unsigned int region) {
    int mipmap;
    int hasMipMap;
    unsigned int shifted;
    unsigned int carry;

    mipmap = GXGetTexObjMipMap(obj);
    hasMipMap = GXGetTexObjAll(obj);
    shifted = region << 29;
    carry = region >> 31;
    shifted -= carry;
    region = (unsigned int)((int)((shifted << 3) | (shifted >> 29)) - -(int)carry);

    switch (mipmap) {
    case 6:
        if ((unsigned char)hasMipMap != 0) {
            return (char *)__GXData + region * 16 + 0x358;
        }
        return (char *)__GXData + region * 16 + 0x2D8;
    case 8:
    case 9:
    case 10:
        return (char *)__GXData + region * 16 + 0x258;
    default:
        if ((unsigned char)hasMipMap != 0) {
            return (char *)__GXData + region * 16 + 0x2D8;
        }
        return (char *)__GXData + region * 16 + 0x258;
    }
}

s32 __GXDefaultTlutRegionCallback(unsigned int region) {
    if (region >= 0x14) {
        return 0;
    }
    return (s32)((char *)__GXData + region * 0x10 + 0x3D8);
}

int __GXShutdown(int shutdown) {
    signed long long now;
    unsigned int oldLow;
    unsigned int oldHigh;
    unsigned long long previous;
    unsigned int current;
    unsigned int low;
    unsigned int firstHigh;
    unsigned int high;
    volatile unsigned short *mem;

    if (shutdown == 0) {
        if (lbl_8055D940 == 0) {
            mem = (volatile unsigned short *)__memReg;
            high = mem[0x4E / 2];
            do {
                firstHigh = high;
                low = mem[0x50 / 2];
                high = mem[0x4E / 2];
            } while (high != firstHigh);
            lbl_8055D930 = (high << 16) | low;
            now = OSGetTime();
            lbl_8055D938 = (unsigned int)(now >> 32);
            lbl_8055D93C = (unsigned int)now;
            lbl_8055D940 = 1;
            return 0;
        }

        now = OSGetTime();
        mem = (volatile unsigned short *)__memReg;
        high = mem[0x4E / 2];
        do {
            firstHigh = high;
            low = mem[0x50 / 2];
            high = mem[0x4E / 2];
        } while (high != firstHigh);
        current = (high << 16) | low;
        oldLow = *(volatile unsigned int *)&lbl_8055D93C;
        oldHigh = *(volatile unsigned int *)&lbl_8055D938;
        previous = ((unsigned long long)oldHigh << 32) | oldLow;
        if ((signed long long)((unsigned long long)now - previous) < 10) {
            return 0;
        }
        if (current != lbl_8055D930) {
            lbl_8055D938 = (unsigned int)(now >> 32);
            lbl_8055D930 = current;
            lbl_8055D93C = (unsigned int)now;
            return 0;
        }
    }

    GXSetBreakPtCallback(0);
    GXGetLightDir(0);
    GXLoadLightObjIndx(0);
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    PPCSync();
    __cpReg[1] = 0;
    __cpReg[2] = 3;
    *((volatile unsigned char *)__GXData + 0x5FA) = 1;
    GXGetVtxAttrFmt();
    return 1;
}

void __GXInitRevisionBits(void) {
    volatile unsigned int *p = __GXData;
    unsigned int n = 0;
    volatile unsigned char *b = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *w = (volatile unsigned int *)0xCC008000;
    unsigned int i;
    unsigned int code;
    for (i = 0; i < 2; i++) {
        code = 0x80 | n++;
        p[7] |= 0x40000000;
        p[15] |= 0x80000000;
        *b = 8;
        *b = (unsigned char)code;
        code = 0x80 | n++;
        *w = p[15];
        p[8] |= 0x40000000;
        p[16] |= 0x80000000;
        *b = 8;
        *b = (unsigned char)code;
        code = 0x80 | n++;
        *w = p[16];
        p[9] |= 0x40000000;
        p[17] |= 0x80000000;
        *b = 8;
        *b = (unsigned char)code;
        code = 0x80 | n++;
        *w = p[17];
        p[10] |= 0x40000000;
        p[18] |= 0x80000000;
        *b = 8;
        *b = (unsigned char)code;
        *w = p[18];
        p += 4;
    }
    {
        unsigned int zero = 0;
        *b = 0x10;
        *w = 0x1000;
        *w = zero | 0x3F;
        *b = 0x10;
        *w = 0x1012;
        *w = zero | 1;
        *b = 0x61;
        *w = (0x58 << 24) | (zero | 0xF);
    }
}

void GXCPInterruptHandler(short intr, void *ctx) {
    unsigned char sp[0x2c8];
    unsigned int *gx = __GXData;
    unsigned int *p;
    gx[3] = *__cpReg;
    if (((gx[2] >> 3) & 1) && ((gx[3] >> 1) & 1)) {
        OSResumeThread(lbl_8055D95C);
        lbl_8055D958 = 0;
        p = GXD;
        p[4] |= 3;
        *(volatile unsigned short *)((char *)__cpReg + 4) = p[4];
        gx[2] = (gx[2] | 4) & ~8;
        *(volatile unsigned short *)((char *)__cpReg + 2) = gx[2];
    }
    if (((gx[2] >> 2) & 1) && (gx[3] & 1)) {
        lbl_8055D94C = (char *)lbl_8055D94C + 1;
        p = GXD;
        gx[2] &= ~4;
        gx[2] |= 8;
        *(volatile unsigned short *)((char *)__cpReg + 2) = gx[2];
        p[4] = (p[4] | 1) & ~2;
        *(volatile unsigned short *)((char *)__cpReg + 4) = p[4];
        lbl_8055D958 = 1;
        OSSuspendThread(lbl_8055D95C);
    }
    if (((gx[2] >> 5) & 1) && ((gx[3] >> 4) & 1)) {
        gx[2] &= ~0x20;
        *(volatile unsigned short *)((char *)__cpReg + 2) = gx[2];
        if (lbl_8055D954 != 0) {
            OSClearContext(sp);
            OSSetCurrentContext(sp);
            ((void (*)(void))lbl_8055D954)();
            OSClearContext(sp);
            OSSetCurrentContext(ctx);
        }
    }
}

void GXInitFifoBase(void *fifoObj, void *base, u32 size) {
    /* Initialize a GX FIFO object's base/top pointers, watermarks, and read/write state. */
    struct Fifo {
        u8 *base;
        u8 *top;
        u32 size;
        u32 hi;
        u32 lo;
        void *rd;
        void *wr;
        s32 count;
    };
    struct Fifo *fifo = (struct Fifo *)fifoObj;
    s32 hiWatermark = (s32)size - 0x4000;
    s32 topPtr = (s32)((u32)base + size) - 4;
    s32 loWatermark = (size >> 1) & 0x7FFFFFE0;
    s32 zero = 0;

    fifo->base = (u8 *)base;
    fifo->top = (u8 *)topPtr;
    fifo->size = size;
    fifo->count = zero;
    fifo->hi = hiWatermark;
    fifo->lo = loWatermark;
    OSDisableInterrupts();
    fifo->rd = base;
    fifo->wr = base;
    fifo->count = zero;
    if (fifo->count < 0) {
        fifo->count = fifo->size;
    }
    OSRestoreInterrupts();
}

extern unsigned char lbl_8037C0C0[0x24];
extern void OSReport(void *, ...);
extern char lbl_803036E0[];
extern char lbl_803036F8[];
int CPGPLinkCheck(void) {
    unsigned int first;
    unsigned int second;
    int diff1;
    int diff2;
    unsigned int error = 0;

    if (lbl_8055D948 == 0 || (unsigned char)lbl_8055D949 == 0) {
        return 0;
    }
    second = *(unsigned int *)lbl_8037C0C0;
    first = *(unsigned int *)lbl_8037C0E4;
    if (first == second) {
        error = 1;
    }
    second = *(unsigned int *)(lbl_8037C0C0 + 4);
    first = *(unsigned int *)(lbl_8037C0E4 + 4);
    if (first == second) {
        error++;
    }
    if (error == 2) {
        return 1;
    }
    diff1 = (int)*(unsigned int *)(lbl_8037C0E4 + 4) -
            (int)*(unsigned int *)lbl_8037C0C0;
    diff2 = (int)*(unsigned int *)(lbl_8037C0C0 + 4) -
            (int)*(unsigned int *)lbl_8037C0E4;
    error = 0;
    if ((diff1 > 0 && diff2 > 0) || (diff1 < 0 && diff2 < 0)) {
        error = 1;
    }
    if (error != 0) {
        OSReport(lbl_803036E0);
        OSReport(lbl_803036F8, *(unsigned int *)lbl_8037C0C0,
                 *(unsigned int *)(lbl_8037C0C0 + 4));
    }
    return 0;
}

#pragma use_lmw_stmw off
void GXSetCPUFifo(void *arg0) {
    union {
        unsigned int word;
        struct {
            unsigned int pad0 : 3;
            unsigned int payload : 24;
            unsigned int pad1 : 5;
        } bits;
    } piWord;
    GXFifoObjInternal *source;
    GXFifoObjInternal *fifo;
    GXFifoObjInternal *fifoElse;
    int intStatus;
    unsigned int *gd;
    unsigned int tmp;

    intStatus = OSDisableInterrupts();
    if (arg0 == 0) {
        lbl_8055D948 = 0;
        lbl_8055D960 = 0;
        ((unsigned char *)lbl_8037C0E4)[0x22] = 0;
        ((unsigned char *)lbl_8037C0E4)[0x21] = 0;
        ((void (*)(int))OSRestoreInterrupts)(intStatus);
        return;
    }

    source = (GXFifoObjInternal *)arg0;
    fifo = (GXFifoObjInternal *)lbl_8037C0E4;
    *fifo = *source;
    lbl_8055D948 = 1;
    ((unsigned char *)fifo)[0x21] = 1;

    if ((CPGPLinkCheck() & 0xFF) != 0) {
        lbl_8055D960 = 1;
        ((unsigned char *)fifo)[0x22] = 1;
        __piReg[3] = (*(unsigned int *)lbl_8037C0E4) & 0x3FFFFFFFu;
        __piReg[4] = (unsigned int)fifo->top & 0x3FFFFFFFu;
        piWord.word = 0;
        piWord.bits.payload = (unsigned int)fifo->wrPtr >> 5;
        __piReg[5] = piWord.word;

        gd = __GXData;
        tmp = gd[4] | 3u;
        gd[4] = tmp;
        __cpReg[2] = (unsigned short)tmp;
        tmp = (gd[2] | 4u) & 0xFFFFFFF7u;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
        tmp = gd[2] | 0x10u;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
    } else {
        ((unsigned char *)fifo)[0x22] = 0;
        if ((unsigned char)lbl_8055D960 != 0) {
            gd = __GXData;
            tmp = gd[2] & 0xFFFFFFEFu;
            gd[2] = tmp;
            __cpReg[1] = (unsigned short)tmp;
            lbl_8055D960 = 0;
        }
        gd = __GXData;
        tmp = gd[2] & 0xFFFFFFF3u;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;

        fifoElse = (GXFifoObjInternal *)lbl_8037C0E4;
        __piReg[3] = (*(unsigned int *)lbl_8037C0E4) & 0x3FFFFFFFu;
        __piReg[4] = (unsigned int)fifoElse->top & 0x3FFFFFFFu;
        piWord.word = 0;
        piWord.bits.payload = (unsigned int)fifoElse->wrPtr >> 5;
        __piReg[5] = piWord.word;
    }
    PPCSync();
    ((void (*)(int))OSRestoreInterrupts)(intStatus);
}
typedef struct GPFifoCopy {
    unsigned int w0, w1, w2, w3, w4, w5, w6, w7, w8;
} GPFifoCopy;
void GXSetGPFifo(unsigned int *fifo) {
    unsigned int *dst;
    unsigned int a, b;
    unsigned int tmp;
    int intStatus;

    intStatus = OSDisableInterrupts();

    tmp = __GXData[2];
    tmp = tmp & 0xFFFFFFFEu;
    __GXData[2] = tmp;
    __cpReg[1] = tmp;
    tmp = __GXData[2] & 0xFFFFFFF3u;
    __GXData[2] = tmp;
    __cpReg[1] = tmp;

    if (fifo == 0) {
        lbl_8055D949 = 0;
        lbl_8055D960 = 0;
        tmp = __GXData[2] & 0xFFFFFFEFu;
        __GXData[2] = tmp;
        __cpReg[1] = tmp;
        ((unsigned char *)lbl_8037C0C0)[0x21] = 0;
        ((unsigned char *)lbl_8037C0C0)[0x22] = 0;
        ((void (*)(int))OSRestoreInterrupts)(intStatus);
        return;
    }

    dst = (unsigned int *)lbl_8037C0C0;
    a = fifo[0];
    b = fifo[1];
    dst[0] = a;
    dst[1] = b;
    a = fifo[2];
    b = fifo[3];
    dst[2] = a;
    dst[3] = b;
    a = fifo[4];
    b = fifo[5];
    dst[4] = a;
    dst[5] = b;
    a = fifo[6];
    b = fifo[7];
    dst[6] = a;
    dst[7] = b;
    dst[8] = fifo[8];
    lbl_8055D949 = 1;
    ((unsigned char *)lbl_8037C0C0)[0x22] = 1;

    __cpReg[0x20 / 2] = ((unsigned int *)lbl_8037C0C0)[0];
    __cpReg[0x24 / 2] = ((unsigned int *)lbl_8037C0C0)[1];
    __cpReg[0x30 / 2] = ((unsigned int *)lbl_8037C0C0)[7];
    __cpReg[0x34 / 2] = ((unsigned int *)lbl_8037C0C0)[6];
    __cpReg[0x38 / 2] = ((unsigned int *)lbl_8037C0C0)[5];
    __cpReg[0x28 / 2] = ((unsigned int *)lbl_8037C0C0)[3];
    __cpReg[0x2C / 2] = ((unsigned int *)lbl_8037C0C0)[4];
    __cpReg[0x22 / 2] = (((unsigned int *)lbl_8037C0C0)[0] >> 16) & 0x3FFF;
    __cpReg[0x26 / 2] = (((unsigned int *)lbl_8037C0C0)[1] >> 16) & 0x3FFF;
    __cpReg[0x32 / 2] = ((int)((unsigned int *)lbl_8037C0C0)[7] >> 16);
    __cpReg[0x36 / 2] = (((unsigned int *)lbl_8037C0C0)[6] >> 16) & 0x3FFF;
    __cpReg[0x3A / 2] = (((unsigned int *)lbl_8037C0C0)[5] >> 16) & 0x3FFF;
    __cpReg[0x2A / 2] = ((unsigned int *)lbl_8037C0C0)[3] >> 16;
    __cpReg[0x2E / 2] = ((unsigned int *)lbl_8037C0C0)[4] >> 16;

    PPCSync();

    if ((CPGPLinkCheck() & 0xFF) != 0) {
        lbl_8055D960 = 1;
        ((unsigned char *)lbl_8037C0C0)[0x21] = 1;
        tmp = (__GXData[2] | 4u) & 0xFFFFFFF7u;
        __GXData[2] = tmp;
        __cpReg[1] = tmp;
        tmp = __GXData[2] | 0x10u;
        __GXData[2] = tmp;
        __cpReg[1] = tmp;
    } else {
        lbl_8055D960 = 0;
        ((unsigned char *)lbl_8037C0C0)[0x21] = 0;
        tmp = __GXData[2] & 0xFFFFFFF3u;
        __GXData[2] = tmp;
        __cpReg[1] = tmp;
        tmp = __GXData[2] & 0xFFFFFFEFu;
        __GXData[2] = tmp;
        __cpReg[1] = tmp;
    }

    tmp = __GXData[2] & 0xFFFFFFFDu;
    __cpReg[1] = tmp & 0xFFFFFFDFu;
    __cpReg[1] = __GXData[2];
    tmp = __GXData[4] | 3u;
    __GXData[4] = tmp;
    __cpReg[2] = tmp;
    tmp = __GXData[2] | 1u;
    __GXData[2] = tmp;
    __cpReg[1] = tmp;
    ((void (*)(int))OSRestoreInterrupts)(intStatus);
}

void __GXSaveFifo(void) {
    register u8 hasCPUFifo;
    int level;
    level = OSDisableInterrupts();
    hasCPUFifo = lbl_8055D948;
    if (hasCPUFifo != 0) {
        GXFifoObjInternal *fifo = (GXFifoObjInternal *)lbl_8037C0E4;
        u32 reg = __piReg[5];
        fifo->wrap = (u8)((reg >> 29) & 1);
        fifo->wrPtr = (void *)((reg & 0x1FFFFFE0) + 0x80000000);
    }
    if (*(u8 *)&lbl_8055D949 != 0) {
        GXFifoObjInternal *fifo = (GXFifoObjInternal *)lbl_8037C0C0;
        u16 *cp = (u16 *)__cpReg;
        fifo->rdPtr = (void *)((((u32)cp[0x3A / 2] << 16) | cp[0x38 / 2]) + 0x80000000);
        fifo->count = ((u32)cp[0x32 / 2] << 16) | cp[0x30 / 2];
    }
    if (*(u8 *)&lbl_8055D960 != 0) {
        (*(GXFifoObjInternal *)lbl_8037C0E4).rdPtr = (*(GXFifoObjInternal *)lbl_8037C0C0).rdPtr;
        (*(GXFifoObjInternal *)lbl_8037C0E4).count = (*(GXFifoObjInternal *)lbl_8037C0C0).count;
        (*(GXFifoObjInternal *)lbl_8037C0C0).wrPtr = (*(GXFifoObjInternal *)lbl_8037C0E4).wrPtr;
        (*(GXFifoObjInternal *)lbl_8037C0C0).wrap = (*(GXFifoObjInternal *)lbl_8037C0E4).wrap;
    } else if (hasCPUFifo != 0) {
        int count = (char *)(*(GXFifoObjInternal *)lbl_8037C0E4).wrPtr - (char *)(*(GXFifoObjInternal *)lbl_8037C0E4).rdPtr;
        (*(GXFifoObjInternal *)lbl_8037C0E4).count = count;
        if (0 > count) {
            (*(GXFifoObjInternal *)lbl_8037C0E4).count = count + (*(GXFifoObjInternal *)lbl_8037C0E4).size;
        }
    }
    ((void (*)(int))OSRestoreInterrupts)(level);
}

#pragma dont_inline on
char __GXIsGPFifoReady(void) {
    return lbl_8055D949;
}
#pragma dont_inline reset

void GXGetGPStatus(char *a, char *b, char *c, char *d, char *e) {
    unsigned int *data = __GXData;
    unsigned short *cp = __cpReg;
    unsigned int value = *cp;
    data[3] = value;
    *a = value & 1;
    *b = (data[3] >> 1) & 1;
    *c = (data[3] >> 2) & 1;
    *d = (data[3] >> 3) & 1;
    *e = (data[3] >> 4) & 1;
}

extern unsigned int lbl_8055D954;
extern unsigned short *__cpReg;
extern unsigned int lbl_8055D950;
extern unsigned char lbl_8055D948;
extern void GXGetVtxDesc(void);
extern void __GXSaveFifo(void);

// The texture filter and anisotropy codes of GXTypes.h; this unit carries no
// Revolution headers, so the two the texture-object setters take are spelled out.
typedef enum _GXTexFilter {
    GX_NEAR,
    GX_LINEAR,
    GX_NEAR_MIP_NEAR,
    GX_LIN_MIP_NEAR,
    GX_NEAR_MIP_LIN,
    GX_LIN_MIP_LIN
} GXTexFilter;

typedef enum _GXAnisotropy {
    GX_ANISO_1,
    GX_ANISO_2,
    GX_ANISO_4,
    GX_MAX_ANISOTROPY
} GXAnisotropy;

// The first two words of a GXTexObj: images of the BP texmode0/texmode1 registers,
// which the driver sends out when the texture is bound.
typedef struct { unsigned int mode0; unsigned int mode1; } __GXTexObjInt;

// Where the level-of-detail settings live in those two words (GX_BITSET positions,
// counted from the MSB; the BP bit number counted from the LSB is 31 - position).
#define TEXMODE0_LODBIAS_FIELD 15   // 8 bits: lod_bias * 32
#define TEXMODE0_BIASCLAMP_FIELD 10 // 1 bit:  keep the LOD bias in range
#define TEXMODE0_ANISO_FIELD 11     // 2 bits: GXAnisotropy
#define TEXMODE0_EDGELOD_FIELD 23   // 1 bit:  set when edge LOD is off
#define TEXMODE0_MINFILT_FIELD 24   // 3 bits: GX2HWFiltConv[min_filt]
#define TEXMODE0_MAGFILT_FIELD 27   // 1 bit:  set when mag_filt == GX_LINEAR
#define TEXMODE1_MINLOD_FIELD 24    // 8 bits: min_lod * 16
#define TEXMODE1_MAXLOD_FIELD 16    // 8 bits: max_lod * 16

static unsigned char GX2HWFiltConv[6] = { 0x00, 0x04, 0x01, 0x05, 0x02, 0x06 };
#pragma dont_inline on
/* Copy the current CPU FIFO object state into `fifo`; returns 0 if GX is not initialized. */
int GXGetCPUFifo(void *fifo) {
    struct Pair {
        unsigned int first;
        unsigned int second;
    };
    if (!lbl_8055D948) {
        return 0;
    }
    GXGetVtxDesc();
    __GXSaveFifo();
    {
        struct Pair *src = (struct Pair *)lbl_8037C0E4;
        struct Pair *dst = (struct Pair *)fifo;

        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        ((unsigned int *)dst)[8] = ((unsigned int *)src)[8];
    }
    return 1;
}
#pragma dont_inline reset

void GXGetFifoPtrs(const void *arg0, void **arg1, void **arg2) {
    const struct {
        char pad[0x14];
        void *rdPtr;
        void *wrPtr;
    } *realFifo = arg0;
    *arg1 = realFifo->rdPtr;
    *arg2 = realFifo->wrPtr;
}

int GXGetFifoBase(int *arg0) {
    return *arg0;
}

int GXGetFifoSize(void *arg0) {
    return ((int *)arg0)[2];
}

#pragma dont_inline on
int GXGetFifoCount(void *arg0) {
    return ((int *)arg0)[0x1C / 4];
}
#pragma dont_inline reset

#pragma dont_inline on
unsigned char GXGetFifoWrap(void *arg0) { return *(unsigned char *)((char *)arg0 + 0x20); }
#pragma dont_inline reset

unsigned int GXSetBreakPtCallback(unsigned int value) {
    extern void OSRestoreInterrupts(void);
    unsigned int old = lbl_8055D954;
    OSDisableInterrupts();
    lbl_8055D954 = value;
    OSRestoreInterrupts();
    return old;
}

// Enable breakpoint for trace capture at the given address
void GXEnableBreakPt(u32 address) {
    s32 interruptState = OSDisableInterrupts();
    s32 value;
    s32 cleared;
    u32 addressField;
    unsigned char *gxData;

    gxData = (unsigned char *)__GXData;
    addressField = (address >> 16) & 0x3FFF;
    value = *(u32 *)(gxData + 8);
    cleared = __rlwinm(value, 0, 0, 30);
    *(u32 *)(gxData + 8) = cleared;
    *(volatile s16 *)((u8 *)__cpReg + 2) = (s16)cleared;
    *(volatile s16 *)((u8 *)__cpReg + 0x3C) = (s16)address;
    *(volatile s16 *)((u8 *)__cpReg + 0x3E) = (s16)addressField;

    value = *(u32 *)(gxData + 8);
    value = __rlwinm(value, 0, 31, 29);
    cleared = __rlwinm(value, 0, 27, 25);
    *(u32 *)(gxData + 8) = cleared;
    *(volatile s16 *)((u8 *)__cpReg + 2) = (s16)cleared;

    value = *(u32 *)(gxData + 8) | 0x22;
    *(u32 *)(gxData + 8) = value;
    *(volatile s16 *)((u8 *)__cpReg + 2) = (s16)value;

    lbl_8055D950 = address;
    value = *(u32 *)(gxData + 8) | 1;
    *(u32 *)(gxData + 8) = value;
    *(volatile s16 *)((u8 *)__cpReg + 2) = (s16)value;

    ((void (*)(s32))OSRestoreInterrupts)(interruptState);
}

void GXDisableBreakPt(void) {
    int intStatus;
    unsigned int value;
    unsigned int cleared;
    unsigned int *data;
    intStatus = OSDisableInterrupts();
    data = __GXData;
    value = data[2];
    value = __rlwinm(value, 0, 31, 29);
    cleared = __rlwinm(value, 0, 27, 25);
    data[2] = cleared;
    *(unsigned short *)((char *)__cpReg + 2) = (unsigned short)cleared;
    lbl_8055D950 = 0;
    ((void (*)(int))OSRestoreInterrupts)(intStatus);
}

extern GXFifoIntrHandler __OSSetInterruptHandler(int, GXFifoIntrHandler);
extern unsigned int __OSUnmaskInterrupts(unsigned int);
void __GXFifoInit(void) {
    __OSSetInterruptHandler(0x11, (GXFifoIntrHandler)GXCPInterruptHandler);
    __OSUnmaskInterrupts(0x4000);
    lbl_8055D95C = OSGetCurrentThread();
    lbl_8055D958 = 0;
    memset(lbl_8037C0E4, 0, 0x24);
    memset(lbl_8037C0C0, 0, 0x24);
    lbl_8055D948 = 0;
    lbl_8055D949 = 0;
}

void __GXCleanGPFifo(void) {
    int zero = 0;
    unsigned int *gd;
    unsigned int *fifo;
    int intStatus;
    unsigned int tmp;
    if ((unsigned char)lbl_8055D949 == 0) {
        return;
    }
    intStatus = OSDisableInterrupts();
    gd = __GXData;
    fifo = (unsigned int *)lbl_8037C0C0;
    gd[2] &= ~1u;
    __cpReg[1] = (unsigned short)gd[2];
    gd[2] &= 0xFFFFFFF3u;
    __cpReg[1] = (unsigned short)gd[2];
    fifo[7] = zero;
    fifo[5] = fifo[6];
    __cpReg[0x30 / 2] = (unsigned short)zero;
    __cpReg[0x34 / 2] = (unsigned short)fifo[6];
    __cpReg[0x38 / 2] = (unsigned short)fifo[5];
    __cpReg[0x32 / 2] = (unsigned short)((int)fifo[7] >> 16);
    __cpReg[0x36 / 2] = (unsigned short)((fifo[6] >> 16) & 0x3FFF);
    __cpReg[0x3A / 2] = (unsigned short)((fifo[5] >> 16) & 0x3FFF);
    PPCSync();
    if ((unsigned char)lbl_8055D960 != 0) {
        unsigned int wrPtr = fifo[6];
        unsigned int *piFifo = (unsigned int *)lbl_8037C0E4;
        unsigned int rdPtr = fifo[5];
        unsigned int count = fifo[7];
        piFifo[5] = rdPtr;
        piFifo[6] = wrPtr;
        piFifo[7] = count;
        zero = (wrPtr & 0x1FFFFFE0u);
        __piReg[5] = zero;
        tmp = (gd[2] | 4u) & 0xFFFFFFF7u;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
        tmp = gd[2] | 0x10u;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
    }
    tmp = gd[2] & ~2u;
    tmp &= ~0x20u;
    gd[2] = tmp;
    __cpReg[1] = (unsigned short)tmp;
    lbl_8055D950 = 0;
    tmp = __GXData[4] | 3u;
    __GXData[4] = tmp;
    __cpReg[2] = (unsigned short)tmp;
    tmp = gd[2] | 1u;
    gd[2] = tmp;
    __cpReg[1] = (unsigned short)tmp;
    ((void (*)(int))OSRestoreInterrupts)(intStatus);
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

// GXAttr as this build of the GX library counts it: GX_VA_NBT still sits right
// after GX_VA_NRM here. include/revolution/GX/GXTypes.h documents the newer
// numbering, where NBT moved down next to GX_VA_MAX_ATTR - GXSetVtxDescv below
// was built with that one.
typedef enum _GXAttr {
    GX_VA_PNMTXIDX,   // position / normal matrix index
    GX_VA_TEX0MTXIDX, // GX_TEXCOORD0 matrix index
    GX_VA_TEX1MTXIDX,
    GX_VA_TEX2MTXIDX,
    GX_VA_TEX3MTXIDX,
    GX_VA_TEX4MTXIDX,
    GX_VA_TEX5MTXIDX,
    GX_VA_TEX6MTXIDX,
    GX_VA_TEX7MTXIDX,
    GX_VA_POS,        // 09 position
    GX_VA_NRM,        // 10 normal
    GX_VA_NBT,        // 11 normal, binormal and tangent
    GX_VA_CLR0,       // 12 color 0
    GX_VA_CLR1,       // 13 color 1
    GX_VA_TEX0,       // 14 texture coordinate 0
    GX_VA_TEX1,
    GX_VA_TEX2,
    GX_VA_TEX3,
    GX_VA_TEX4,
    GX_VA_TEX5,
    GX_VA_TEX6,
    GX_VA_TEX7,       // 21 texture coordinate 7
    GX_POS_MTX_ARRAY, // 22
    GX_NRM_MTX_ARRAY, // 23
    GX_TEX_MTX_ARRAY, // 24
    GX_LIGHT_ARRAY,   // 25

    GX_VA_NULL = 0xff
} GXAttr;

// How one attribute's data reaches the display list.
typedef enum _GXAttrType {
    GX_NONE,   // no data sent
    GX_DIRECT, // data sent directly to the FIFO
    GX_INDEX8, // 8-bit index sent to the FIFO
    GX_INDEX16 // 16-bit index sent to the FIFO
} GXAttrType;

// Where each attribute's GXAttrType lives (GX_BITSET position, counted from the
// MSB) in the vcdLo / vcdHi vertex descriptor words.
#define VCD_PNMTXIDX_FIELD 31
#define VCD_TEX0MTXIDX_FIELD 30
#define VCD_TEX1MTXIDX_FIELD 29
#define VCD_TEX2MTXIDX_FIELD 28
#define VCD_TEX3MTXIDX_FIELD 27
#define VCD_TEX4MTXIDX_FIELD 26
#define VCD_TEX5MTXIDX_FIELD 25
#define VCD_TEX6MTXIDX_FIELD 24
#define VCD_TEX7MTXIDX_FIELD 23
#define VCD_POS_FIELD 21
#define VCD_NRM_FIELD 19
#define VCD_CLR0_FIELD 17
#define VCD_CLR1_FIELD 15
#define VCD_TC0_FIELD 30
#define VCD_TC1_FIELD 28
#define VCD_TC2_FIELD 26
#define VCD_TC3_FIELD 24
#define VCD_TC4_FIELD 22
#define VCD_TC5_FIELD 20
#define VCD_TC6_FIELD 18
#define VCD_TC7_FIELD 16

#define DIRTY_VCD 0x8 // vertex descriptor changed; GX_DIRTY_VCD in GXTypes.h

// __GXData's vertex-descriptor part. The library grew __GXData_struct
// (include/revolution/GX/__gx.h) past the GameCube layout it describes, so the
// normal bookkeeping sits at 0x520 and the dirty flags at 0x5FC here.
typedef struct {
    u8 unused_000[0x14];
    u32 vcdLo;                    // 0x14 descriptor for attributes 0-13
    u32 vcdHi;                    // 0x18 descriptor for GX_VA_TEX0-7
    u8 unused_01C[0x520 - 0x1C];
    u32 normalType;               // 0x520 GXAttrType of the normal data
    u8 normal;                    // 0x524 GX_VA_NRM is enabled
    u8 binormal;                  // 0x525 GX_VA_NBT is enabled
    u8 unused_526[0x5FC - 0x526];
    u32 dirtyState;               // 0x5FC what __GXSetDirtyState has to resend
} GXVtxDescData;

// Written as a cast rather than a local pointer: every case reloads __GXData.
#define gxdata ((GXVtxDescData *)__GXData)

// __GXData's draw bookkeeping head, what GXBegin, __GXSendFlushPrim and
// __GXCalculateVLim work on. include/revolution/GX/GXInit.h spells the same
// block out but leaves 0x4 unnamed (SHORT_0x4): it is the channel count the
// driver flushes, and 0x6 is the vertex size __GXCalculateVLim derives from the
// vertex descriptor.
typedef struct {
    u16 unused_000;     // 0x00 primitive word GXBegin tests for "no primitive"
    u16 lastWriteWasXF; // 0x02 last FIFO command was an XF load, not a BP one
    u16 numChans;       // 0x04 color channels to send with the flush primitive
    u16 vLim;           // 0x06 attribute words per channel
} GXDrawData;

#define gxdraw ((GXDrawData *)__GXData)

// GXPrimitive of GXTypes.h: the strip that carries the flush data.
#define GX_TRIANGLESTRIP 0x98

// Sets how one vertex attribute reaches the geometry pipeline: its GXAttrType is
// written into the vcdLo/vcdHi vertex descriptor. attr is a GXAttr (the dispatch
// below is an unsigned compare, so it stays a plain u32). GX_VA_NRM and GX_VA_NBT
// are the two post-transform normal groups: enabling one only remembers its type
// and turns the other off, and the descriptor's normal field is rewritten from
// that at the end. Finally the descriptor is marked dirty so __GXSetDirtyState
// resends it before the next draw.
void GXSetVtxDesc(unsigned int attr, unsigned int type) {
    switch (attr) {
    case GX_VA_PNMTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_PNMTXIDX_FIELD, 1, type);
        break;
    case GX_VA_TEX0MTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_TEX0MTXIDX_FIELD, 1, type);
        break;
    case GX_VA_TEX1MTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_TEX1MTXIDX_FIELD, 1, type);
        break;
    case GX_VA_TEX2MTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_TEX2MTXIDX_FIELD, 1, type);
        break;
    case GX_VA_TEX3MTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_TEX3MTXIDX_FIELD, 1, type);
        break;
    case GX_VA_TEX4MTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_TEX4MTXIDX_FIELD, 1, type);
        break;
    case GX_VA_TEX5MTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_TEX5MTXIDX_FIELD, 1, type);
        break;
    case GX_VA_TEX6MTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_TEX6MTXIDX_FIELD, 1, type);
        break;
    case GX_VA_TEX7MTXIDX:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_TEX7MTXIDX_FIELD, 1, type);
        break;
    case GX_VA_POS:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_POS_FIELD, 2, type);
        break;
    case GX_VA_NRM:
        if (type != GX_NONE) {
            gxdata->normal = TRUE;
            // GX_VA_NRM and GX_VA_NBT should not be enabled at the same time
            gxdata->binormal = FALSE;
            gxdata->normalType = type;
        } else {
            gxdata->normal = FALSE;
        }
        break;
    case GX_VA_NBT:
        if (type != GX_NONE) {
            gxdata->binormal = TRUE;
            // GX_VA_NRM and GX_VA_NBT should not be enabled at the same time
            gxdata->normal = FALSE;
            gxdata->normalType = type;
        } else {
            gxdata->binormal = FALSE;
        }
        break;
    case GX_VA_CLR0:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_CLR0_FIELD, 2, type);
        break;
    case GX_VA_CLR1:
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_CLR1_FIELD, 2, type);
        break;
    case GX_VA_TEX0:
        gxdata->vcdHi = GX_BITSET(gxdata->vcdHi, VCD_TC0_FIELD, 2, type);
        break;
    case GX_VA_TEX1:
        gxdata->vcdHi = GX_BITSET(gxdata->vcdHi, VCD_TC1_FIELD, 2, type);
        break;
    case GX_VA_TEX2:
        gxdata->vcdHi = GX_BITSET(gxdata->vcdHi, VCD_TC2_FIELD, 2, type);
        break;
    case GX_VA_TEX3:
        gxdata->vcdHi = GX_BITSET(gxdata->vcdHi, VCD_TC3_FIELD, 2, type);
        break;
    case GX_VA_TEX4:
        gxdata->vcdHi = GX_BITSET(gxdata->vcdHi, VCD_TC4_FIELD, 2, type);
        break;
    case GX_VA_TEX5:
        gxdata->vcdHi = GX_BITSET(gxdata->vcdHi, VCD_TC5_FIELD, 2, type);
        break;
    case GX_VA_TEX6:
        gxdata->vcdHi = GX_BITSET(gxdata->vcdHi, VCD_TC6_FIELD, 2, type);
        break;
    case GX_VA_TEX7:
        gxdata->vcdHi = GX_BITSET(gxdata->vcdHi, VCD_TC7_FIELD, 2, type);
        break;
    case GX_LIGHT_ARRAY: // vertex light indices: nothing to describe
        break;
    }

    if (gxdata->normal || gxdata->binormal) {
        gxdata->vcdLo = GX_BITSET(gxdata->vcdLo, VCD_NRM_FIELD, 2, gxdata->normalType);
    } else {
        gxdata->vcdLo &= 0xFFFFE7FF; // clear the normal field
    }

    gxdata->dirtyState |= DIRTY_VCD;
}

/* Walk a GX_VA_NULL-terminated vertex descriptor list and update GX vtx-desc
 * (VCD lo/hi), normal/binormal flags, and direct/normal-type fields in __GXData.
 * Marks VCD dirty when done. */
void GXSetVtxDescv(unsigned int *list) {
    unsigned int *gxData = __GXData;
    while ((int)list[0] != 0xff) {
        unsigned int attr = *(volatile unsigned int *)list;
        unsigned int type = *(volatile unsigned int *)(list + 1);
        switch (attr) {
        case 0: gxData[5] = __rlwimi(gxData[5],type,0,31,31); break;
        case 1: gxData[5] = __rlwimi(gxData[5],type,1,30,30); break;
        case 2: gxData[5] = __rlwimi(gxData[5],type,2,29,29); break;
        case 3: gxData[5] = __rlwimi(gxData[5],type,3,28,28); break;
        case 4: gxData[5] = __rlwimi(gxData[5],type,4,27,27); break;
        case 5: gxData[5] = __rlwimi(gxData[5],type,5,26,26); break;
        case 6: gxData[5] = __rlwimi(gxData[5],type,6,25,25); break;
        case 7: gxData[5] = __rlwimi(gxData[5],type,7,24,24); break;
        case 8: gxData[5] = __rlwimi(gxData[5],type,8,23,23); break;
        case 9: gxData[5] = __rlwimi(gxData[5],type,9,21,22); break;
        case 10:
            if (type) { ((u8 *)gxData)[0x524]=1; ((u8 *)gxData)[0x525]=0; gxData[0x520/4]=type; }
            else ((u8 *)gxData)[0x524]=0;
            break;
        case 25:
            if (type) { ((u8 *)gxData)[0x525]=1; ((u8 *)gxData)[0x524]=0; gxData[0x520/4]=type; }
            else ((u8 *)gxData)[0x525]=0;
            break;
        case 11: gxData[5] = __rlwimi(gxData[5],type,13,17,18); break;
        case 12: gxData[5] = __rlwimi(gxData[5],type,15,15,16); break;
        case 13: gxData[6] = __rlwimi(gxData[6],type,0,30,31); break;
        case 14: gxData[6] = __rlwimi(gxData[6],type,2,28,29); break;
        case 15: gxData[6] = __rlwimi(gxData[6],type,4,26,27); break;
        case 16: gxData[6] = __rlwimi(gxData[6],type,6,24,25); break;
        case 17: gxData[6] = __rlwimi(gxData[6],type,8,22,23); break;
        case 18: gxData[6] = __rlwimi(gxData[6],type,10,20,21); break;
        case 19: gxData[6] = __rlwimi(gxData[6],type,12,18,19); break;
        case 20: gxData[6] = __rlwimi(gxData[6],type,14,16,17); break;
        }
        list += 2;
    }
    if (((u8 *)gxData)[0x524] || ((u8 *)gxData)[0x525])
        gxData[5] = __rlwimi(gxData[5], gxData[0x520/4], 11, 19, 20);
    else gxData[5] &= 0xffffe7ff;
    gxData[0x5fc/4] |= 8;
}

void __GXSetVCD(void) {
    unsigned int count;
    unsigned int value;
    unsigned int masked;
    unsigned int compCount;
    unsigned int vatPart;
    unsigned int vatCount;
    unsigned int sizeCount;
    unsigned int sizePart;
    unsigned int countPart;
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifo32 = (volatile unsigned int *)0xCC008000;
    unsigned int *data = __GXData;
    *fifo8 = 8;
    *fifo8 = 0x50;
    *fifo32 = data[0x14 / 4];
    *fifo8 = 8;
    *fifo8 = 0x60;
    *fifo32 = data[0x18 / 4];
    if (*((unsigned char *)data + 0x525) != 0) {
        count = 2;
    } else {
        unsigned int flag = *((unsigned char *)data + 0x524);
        count = (unsigned int)(-(int)flag | (int)flag) >> 31;
    }
    compCount = (data[0x14 / 4] >> 13) & 0xF;
    vatPart = __cntlzw(compCount);
    masked = data[0x18 / 4] & 0xFFFF;
    *fifo8 = 0x10;
    vatPart = 0x21u - vatPart;
    sizeCount = __cntlzw(masked);
    countPart = count << 2;
    sizeCount = 0x21u - sizeCount;
    vatCount = vatPart >> 1;
    sizePart = (sizeCount << 3) & 0xFFFFFFF0u;
    *fifo32 = 0x1008;
    value = (sizePart | vatCount) | countPart;
    *fifo32 = value;
    *(unsigned short *)((char *)data + 2) = 1;
}

extern unsigned char lbl_80558E38;
extern unsigned char lbl_80558E3C;
extern unsigned char lbl_80558E40;
void __GXCalculateVLim(void) {
    register unsigned int *gx = __GXData;
    register unsigned int flags;
    register int extra;
    register unsigned int vtx;
    register unsigned char *table;
    register int sum;
    int term;
    int tableValue;
    int mode;

    if (*(unsigned short *)((char *)gx + 4) == 0) return;

    flags = gx[0x14 / 4];
    table = &lbl_80558E40;
    extra = gx[0x1C / 4];

    sum = flags & 1;
    sum += (flags >> 1) & 1;
    sum += (flags >> 2) & 1;
    sum += (flags >> 3) & 1;
    sum += (flags >> 4) & 1;
    vtx = gx[0x18 / 4];
    sum += (flags >> 5) & 1;
    sum += (flags >> 6) & 1;
    sum += (flags >> 7) & 1;

    tableValue = table[(flags >> 11) & 3];
    term = (flags >> 8) & 1;
    mode = (extra >> 9) & 1;
    if (mode == 1) {
        term = tableValue * (mode + 2);
    }
    sum += term;
    sum += table[(flags >> 9) & 3];

    table = &lbl_80558E38;
    sum += table[(flags >> 13) & 3];
    sum += table[(flags >> 15) & 3];

    table = &lbl_80558E3C;
    sum += table[(vtx >> 0) & 3];
    sum += table[(vtx >> 2) & 3];
    sum += table[(vtx >> 4) & 3];
    sum += table[(vtx >> 6) & 3];
    sum += table[(vtx >> 8) & 3];
    sum += table[(vtx >> 10) & 3];
    sum += table[(vtx >> 12) & 3];
    sum += table[(vtx >> 14) & 3];

    *(unsigned short *)((char *)gx + 6) = sum;
}

void GXClearVtxDesc(void) {
    unsigned int *data = __GXData;
    unsigned int zero = 0;
    unsigned int value = 1;
    unsigned int field = __rlwimi(0, value, 9, 21, 22);
    data[0x14 / 4] = field;
    data[0x18 / 4] = zero;
    *((unsigned char *)data + 0x524) = zero;
    *((unsigned char *)data + 0x525) = zero;
    data[0x5FC / 4] |= 8;
}

static inline void SETVAT(unsigned int *vatA, unsigned int *vatB, unsigned int *vatC,
                          int attr, int compCnt, int compType, unsigned char shift) {
    switch (attr) {
    case 9:
        *vatA = __rlwimi(*vatA, compCnt, 0, 31, 31);
        *vatA = __rlwimi(*vatA, compType, 1, 28, 30);
        *vatA = __rlwimi(*vatA, shift, 4, 23, 27);
        break;
    case 10:
    case 25:
        *vatA = __rlwimi(*vatA, compType, 10, 19, 21);
        if (compCnt == 2) {
            *vatA = __rlwimi(*vatA, 1, 9, 22, 22);
            *vatA = __rlwimi(*vatA, 1, 31, 0, 0);
        } else {
            *vatA = __rlwimi(*vatA, compCnt, 9, 22, 22);
            *vatA = __rlwimi(*vatA, 0, 31, 0, 0);
        }
        break;
    case 11:
        *vatA = __rlwimi(*vatA, compCnt, 13, 18, 18);
        *vatA = __rlwimi(*vatA, compType, 14, 15, 17);
        break;
    case 12:
        *vatA = __rlwimi(*vatA, compCnt, 17, 14, 14);
        *vatA = __rlwimi(*vatA, compType, 18, 11, 13);
        break;
    case 13:
        *vatA = __rlwimi(*vatA, compCnt, 21, 10, 10);
        *vatA = __rlwimi(*vatA, compType, 22, 7, 9);
        *vatA = __rlwimi(*vatA, shift, 25, 2, 6);
        break;
    case 14:
        *vatB = __rlwimi(*vatB, compCnt, 0, 31, 31);
        *vatB = __rlwimi(*vatB, compType, 1, 28, 30);
        *vatB = __rlwimi(*vatB, shift, 4, 23, 27);
        break;
    case 15:
        *vatB = __rlwimi(*vatB, compCnt, 9, 22, 22);
        *vatB = __rlwimi(*vatB, compType, 10, 19, 21);
        *vatB = __rlwimi(*vatB, shift, 13, 14, 18);
        break;
    case 16:
        *vatB = __rlwimi(*vatB, compCnt, 18, 13, 13);
        *vatB = __rlwimi(*vatB, compType, 19, 10, 12);
        *vatB = __rlwimi(*vatB, shift, 22, 5, 9);
        break;
    case 17:
        *vatB = __rlwimi(*vatB, compCnt, 27, 4, 4);
        *vatB = __rlwimi(*vatB, compType, 28, 1, 3);
        *vatC = __rlwimi(*vatC, shift, 0, 27, 31);
        break;
    case 18:
        *vatC = __rlwimi(*vatC, compCnt, 5, 26, 26);
        *vatC = __rlwimi(*vatC, compType, 6, 23, 25);
        *vatC = __rlwimi(*vatC, shift, 9, 18, 22);
        break;
    case 19:
        *vatC = __rlwimi(*vatC, compCnt, 14, 17, 17);
        *vatC = __rlwimi(*vatC, compType, 15, 14, 16);
        *vatC = __rlwimi(*vatC, shift, 18, 9, 13);
        break;
    case 20:
        *vatC = __rlwimi(*vatC, compCnt, 23, 8, 8);
        *vatC = __rlwimi(*vatC, compType, 24, 5, 7);
        *vatC = __rlwimi(*vatC, shift, 27, 0, 4);
        break;
    }
}

/* Configure a vertex attribute format entry (VAT A/B/C) for the given GX vertex format and mark it dirty. */
void GXSetVtxAttrFmt(unsigned int vtxfmt, unsigned int attr, int compCnt,
                     unsigned int compType, unsigned int frac)
{
    unsigned int *vatBase = (unsigned int *)((unsigned char *)__GXData + (vtxfmt << 2));
    unsigned int *vatA = &vatBase[0x1C / 4];
    unsigned int *vatB = &vatBase[0x3C / 4];
    unsigned int *vatC = &vatBase[0x5C / 4];

    switch (attr) {
    case 9:
        *vatA = __rlwimi(*vatA, compCnt, 0, 31, 31);
        *vatA = __rlwimi(*vatA, compType, 1, 28, 30);
        *vatA = __rlwimi(*vatA, frac, 4, 23, 27);
        break;
    case 10:
    case 25:
        *vatA = __rlwimi(*vatA, compType, 10, 19, 21);
        if (compCnt == 2) {
            *vatA = __rlwimi(*vatA, 1, 9, 22, 22);
            *vatA = __rlwimi(*vatA, 1, 31, 0, 0);
        } else {
            *vatA = __rlwimi(*vatA, compCnt, 9, 22, 22);
            *vatA = __rlwimi(*vatA, 0, 31, 0, 0);
        }
        break;
    case 11:
        *vatA = __rlwimi(*vatA, compCnt, 13, 18, 18);
        *vatA = __rlwimi(*vatA, compType, 14, 15, 17);
        break;
    case 12:
        *vatA = __rlwimi(*vatA, compCnt, 17, 14, 14);
        *vatA = __rlwimi(*vatA, compType, 18, 11, 13);
        break;
    case 13:
        *vatA = __rlwimi(*vatA, compCnt, 21, 10, 10);
        *vatA = __rlwimi(*vatA, compType, 22, 7, 9);
        *vatA = __rlwimi(*vatA, frac, 25, 2, 6);
        break;
    case 14:
        *vatB = __rlwimi(*vatB, compCnt, 0, 31, 31);
        *vatB = __rlwimi(*vatB, compType, 1, 28, 30);
        *vatB = __rlwimi(*vatB, frac, 4, 23, 27);
        break;
    case 15:
        *vatB = __rlwimi(*vatB, compCnt, 9, 22, 22);
        *vatB = __rlwimi(*vatB, compType, 10, 19, 21);
        *vatB = __rlwimi(*vatB, frac, 13, 14, 18);
        break;
    case 16:
        *vatB = __rlwimi(*vatB, compCnt, 18, 13, 13);
        *vatB = __rlwimi(*vatB, compType, 19, 10, 12);
        *vatB = __rlwimi(*vatB, frac, 22, 5, 9);
        break;
    case 17:
        *vatB = __rlwimi(*vatB, compCnt, 27, 4, 4);
        *vatB = __rlwimi(*vatB, compType, 28, 1, 3);
        *vatC = __rlwimi(*vatC, frac, 0, 27, 31);
        break;
    case 18:
        *vatC = __rlwimi(*vatC, compCnt, 5, 26, 26);
        *vatC = __rlwimi(*vatC, compType, 6, 23, 25);
        *vatC = __rlwimi(*vatC, frac, 9, 18, 22);
        break;
    case 19:
        *vatC = __rlwimi(*vatC, compCnt, 14, 17, 17);
        *vatC = __rlwimi(*vatC, compType, 15, 14, 16);
        *vatC = __rlwimi(*vatC, frac, 18, 9, 13);
        break;
    case 20:
        *vatC = __rlwimi(*vatC, compCnt, 23, 8, 8);
        *vatC = __rlwimi(*vatC, compType, 24, 5, 7);
        *vatC = __rlwimi(*vatC, frac, 27, 0, 4);
        break;
    }

    __GXData[0x5FC / 4] |= 0x10;
    *((unsigned char *)__GXData + 0x5FB) |= (unsigned char)(1 << (vtxfmt & 0xFF));
}

static inline void SETVAT_LIST(unsigned int *vatA, unsigned int *vatB, unsigned int *vatC,
                               const GXVtxAttrFmtList *list) {
    int attr = list->attr;
    unsigned char shift = list->shift;
    int compType = list->compType;
    int compCnt = list->compCnt;

    switch (attr) {
    case 9:
        *vatA = __rlwimi(*vatA, compCnt, 0, 31, 31);
        *vatA = __rlwimi(*vatA, compType, 1, 28, 30);
        *vatA = __rlwimi(*vatA, shift, 4, 23, 27);
        break;
    case 10:
    case 25:
        *vatA = __rlwimi(*vatA, compType, 10, 19, 21);
        if (compCnt == 2) {
            *vatA = __rlwimi(*vatA, 1, 9, 22, 22);
            *vatA = __rlwimi(*vatA, 1, 31, 0, 0);
        } else {
            *vatA = __rlwimi(*vatA, compCnt, 9, 22, 22);
            *vatA = __rlwimi(*vatA, 0, 31, 0, 0);
        }
        break;
    case 11:
        *vatA = __rlwimi(*vatA, compCnt, 13, 18, 18);
        *vatA = __rlwimi(*vatA, compType, 14, 15, 17);
        break;
    case 12:
        *vatA = __rlwimi(*vatA, compCnt, 17, 14, 14);
        *vatA = __rlwimi(*vatA, compType, 18, 11, 13);
        break;
    case 13:
        *vatA = __rlwimi(*vatA, compCnt, 21, 10, 10);
        *vatA = __rlwimi(*vatA, compType, 22, 7, 9);
        *vatA = __rlwimi(*vatA, shift, 25, 2, 6);
        break;
    case 14:
        *vatB = __rlwimi(*vatB, compCnt, 0, 31, 31);
        *vatB = __rlwimi(*vatB, compType, 1, 28, 30);
        *vatB = __rlwimi(*vatB, shift, 4, 23, 27);
        break;
    case 15:
        *vatB = __rlwimi(*vatB, compCnt, 9, 22, 22);
        *vatB = __rlwimi(*vatB, compType, 10, 19, 21);
        *vatB = __rlwimi(*vatB, shift, 13, 14, 18);
        break;
    case 16:
        *vatB = __rlwimi(*vatB, compCnt, 18, 13, 13);
        *vatB = __rlwimi(*vatB, compType, 19, 10, 12);
        *vatB = __rlwimi(*vatB, shift, 22, 5, 9);
        break;
    case 17:
        *vatB = __rlwimi(*vatB, compCnt, 27, 4, 4);
        *vatB = __rlwimi(*vatB, compType, 28, 1, 3);
        *vatC = __rlwimi(*vatC, shift, 0, 27, 31);
        break;
    case 18:
        *vatC = __rlwimi(*vatC, compCnt, 5, 26, 26);
        *vatC = __rlwimi(*vatC, compType, 6, 23, 25);
        *vatC = __rlwimi(*vatC, shift, 9, 18, 22);
        break;
    case 19:
        *vatC = __rlwimi(*vatC, compCnt, 14, 17, 17);
        *vatC = __rlwimi(*vatC, compType, 15, 14, 16);
        *vatC = __rlwimi(*vatC, shift, 18, 9, 13);
        break;
    case 20:
        *vatC = __rlwimi(*vatC, compCnt, 23, 8, 8);
        *vatC = __rlwimi(*vatC, compType, 24, 5, 7);
        *vatC = __rlwimi(*vatC, shift, 27, 0, 4);
        break;
    }
}

#pragma push
#pragma opt_propagation off
void GXSetVtxAttrFmtv(s16 fmt, const GXVtxAttrFmtList *list) {
    unsigned int *vatA = (unsigned int *)((char *)__GXData + 0x1C) + fmt;
    unsigned int *vatB = (unsigned int *)((char *)__GXData + 0x3C) + fmt;
    unsigned int *vatC = (unsigned int *)((char *)__GXData + 0x5C) + fmt;

    for (; list->attr != 0xFF; list++) {
        SETVAT(vatA, vatB, vatC, list->attr, list->compCnt, list->compType, list->shift);
    }

    *(unsigned int *)((char *)__GXData + 0x5FC) |= 0x10;
    *((unsigned char *)__GXData + 0x5FB) |= (unsigned char)(1 << (unsigned char)fmt);
}
#pragma pop
void __GXSetVAT(void) {
    unsigned int *ptr;
    unsigned int *data;
    unsigned int i;
    unsigned int mask;

    data = __GXData;
    ptr = data;
    i = 0;
    mask = *(unsigned char *)((char *)data + 0x5FB);
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

void GXSetTexCoordGen2(unsigned int coord, int func, unsigned int line, unsigned int nrm, unsigned int normalize, int postmtx) {
    unsigned int *data = __GXData;
    unsigned int type = 0;
    unsigned int source = 5;
    unsigned int normalizeFlag = 0;
    switch (line) {
        case 0: source = 0; normalizeFlag = 1; break;
        case 1: source = 1; normalizeFlag = 1; break;
        case 2: source = 3; normalizeFlag = 1; break;
        case 3: source = 4; normalizeFlag = 1; break;
        case 4: source = 2; break;
        case 5: source = 2; break;
        case 6: source = 5; break;
        case 7: source = 6; break;
        case 8: source = 7; break;
        case 9: source = 8; break;
        case 10: source = 9; break;
        case 11: source = 10; break;
        case 12: source = 11; break;
        case 13: source = 12; break;
        case 14: source = 12; break;
        case 15: source = 12; break;
        case 16: source = 12; break;
        case 17: source = 12; break;
        case 18: source = 12; break;
        case 19: source = 12; break;
        case 20: source = 12; break;
        default: break;
    }
    {
        unsigned int value;
        unsigned int mask;
        if (func == 1) {
            type = 0; source = 5; normalizeFlag = 0;
        } else if (func == 0) {
            type = 0; source = 5; normalizeFlag = 1;
        } else if (func == 10) {
            type = 1;
            source = (line == 0x13) ? 2 : 3;
        } else if (func < 10 && func > 1) {
            type = (unsigned int)(func - 2);
            source = 1; normalizeFlag = 1;
        }
        if (func == 1) value = 0x280;
        else if (func == 0) value = 0x282;
        else if (func == 10) value = (line == 0x13) ? 0x120 : 0x130;
        else {
            value = 0;
            value |= source << 7;
            value |= normalizeFlag << 2;
            value |= (line - 0xC) << 12;
            value |= (unsigned int)(func - 2) << 15;
            value |= type << 4;
        }
        *(unsigned int *)((char *)data + coord * 4 + 0xC8) = value;
        mask = 0x10000 << coord;
        data[0x5FC / 4] |= mask;
        *(unsigned int *)((char *)data + coord * 4 + 0xE8) = ((normalize & 1) << 8) | ((postmtx - 0x40) & 0x3F);
    }
    switch (coord) {
        case 0: data[0x80/4] = (data[0x80/4] & 0xFC000000) | ((nrm & 0x3F) << 26); break;
        case 1: data[0x80/4] = (data[0x80/4] & 0x03FFFFFF) | ((nrm & 0x3F) << 20); break;
        case 2: data[0x80/4] = (data[0x80/4] & 0xFFFFC000) | ((nrm & 0x3F) << 14); break;
        case 3: data[0x80/4] = (data[0x80/4] & 0xFFFFFF00) | ((nrm & 0x3F) << 8); break;
        case 4: data[0x84/4] = (data[0x84/4] & 0xFC000000) | ((nrm & 0x3F) << 26); break;
        case 5: data[0x84/4] = (data[0x84/4] & 0x03FFFFFF) | ((nrm & 0x3F) << 20); break;
        case 6: data[0x84/4] = (data[0x84/4] & 0xFFFFC000) | ((nrm & 0x3F) << 14); break;
        case 7: data[0x84/4] = (data[0x84/4] & 0xFFFFFF00) | ((nrm & 0x3F) << 8); break;
        default: data[0x84/4] = (data[0x84/4] & 0xFF03FFFF) | ((nrm & 0x3F) << 18); break;
    }
    data[0x5FC / 4] |= 0x4000000;
}

void GXSetNumTexGens(unsigned int value) {
    union {
        unsigned int reg;
        struct {
            unsigned int pad : 28;
            unsigned int texGens : 4;
        } fields;
    } tex;

    union {
        unsigned int reg;
        struct {
            unsigned int pad0 : 6;
            unsigned int upper : 1;
            unsigned int pad1 : 22;
            unsigned int lower : 1;
            unsigned int pad2 : 2;
        } fields;
    } flags;

    tex.reg = __GXData[0x254 / 4];
    tex.fields.texGens = value;
    __GXData[0x254 / 4] = tex.reg;

    flags.reg = __GXData[0x5FC / 4];
    flags.fields.upper = 1;
    flags.fields.lower = 1;
    __GXData[0x5FC / 4] = flags.reg;
}

void GXSetMisc(s32 which, u32 value) {
    switch (which) {
    case 2:
        goto set_2;
    case 0:
        goto out;
    case 1:
        goto set_1;
    case 3:
        goto set_3;
    default:
        goto out;
    }

set_1:
    {
        u32 flag;
        u32 leading;
        unsigned int *data;
        flag = value & 0xFFFF;
        data = __GXData;
        *(u16 *)((u8 *)data + 4) = (u16)value;
        leading = __cntlzw((unsigned int)flag);
        *(u16 *)data = (u16)(leading >> 5);
        *(u16 *)((u8 *)data + 2) = 1;
        if (flag == 0) return;
        data[0x5FC / 4] |= 8;
        return;
    }

set_2:
    *((u8 *)__GXData + 0x5F9) = value != 0;
    return;

set_3:
    *((u8 *)__GXData + 0x5FA) = value != 0;
    return;

out:
    return;
}

void GXGetVtxDesc(void) {
    if (__GXData[0x5FC / 4] != 0) {
        __GXSetDirtyState();
    }
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    PPCSync();
}

void GXGetVtxDescv(void) {
    while (PPCMfwpar() & 1) {
    }
    PPCMtwpar(0x0C008000);
}

extern unsigned int *__memReg;
extern char __GXIsGPFifoReady(void);
extern signed long long OSGetTime(void);
#pragma dont_inline on
#pragma use_lmw_stmw off
void GXGetVtxAttrFmt(void) {
    unsigned int old;
    unsigned int value;
    unsigned long long start;

    if (*(unsigned char *)((char *)__GXData + 0x5FA) &&
        (((unsigned int)__GXIsGPFifoReady() & 0xFF) != 0)) {
        unsigned int high;
        unsigned int firstHigh;
        unsigned int low;
        unsigned int shiftedHigh;

        do {
            high = *(volatile unsigned short *)((char *)__memReg + 0x4E);
            firstHigh = high;
            low = *(volatile unsigned short *)((char *)__memReg + 0x50);
            high = *(volatile unsigned short *)((char *)__memReg + 0x4E);
        } while (high != firstHigh);
        shiftedHigh = high << 16;
        old = shiftedHigh | low;

        for (;;) {
            start = OSGetTime();
            while (OSGetTime() - start < 8) {}
            do {
                high = *(volatile unsigned short *)((char *)__memReg + 0x4E);
                firstHigh = high;
                low = *(volatile unsigned short *)((char *)__memReg + 0x50);
                high = *(volatile unsigned short *)((char *)__memReg + 0x4E);
            } while (high != firstHigh);
            shiftedHigh = high << 16;
            value = shiftedHigh | low;
            {
                unsigned int previous = old;
                old = value;
                if (value != previous)
                    continue;
            }
            break;
        }
    }

    *(volatile unsigned int *)0xCC003018 = 1;
    start = OSGetTime();
    while (OSGetTime() - start < 50) {}
    *(volatile unsigned int *)0xCC003018 = 0;
    start = OSGetTime();
    while (OSGetTime() - start < 5) {}
}
#pragma dont_inline reset
#pragma use_lmw_stmw off
extern char __GXIsGPFifoReady(void) __attribute__((noinline));
void GXGetVtxAttrFmtv(void) {
    unsigned int value, old;
    signed long long start, now;
    unsigned int *data = __GXData;
    if (*(unsigned char *)((char *)data + 0x5FA) &&
        (((unsigned int)__GXIsGPFifoReady() & 0xFF) != 0)) {
        unsigned int firstHigh, high, low;
        volatile unsigned short *reg = (volatile unsigned short *)__memReg;
        high = reg[0x4E / 2];
        do {
            firstHigh = high;
            low = reg[0x50 / 2];
            high = reg[0x4E / 2];
        } while (high != firstHigh);
        old = (high << 16) | low;
        for (;;) {
            unsigned int firstHigh2, low2, high2;
            start = OSGetTime();
            do {
                now = OSGetTime();
            } while (now - start <= 8);
            {
                volatile unsigned short *reg2 = (volatile unsigned short *)__memReg;
                high2 = reg2[0x4E / 2];
                do {
                    firstHigh2 = high2;
                    low2 = reg2[0x50 / 2];
                    high2 = reg2[0x4E / 2];
                } while (high2 != firstHigh2);
            }
            value = (high2 << 16) | low2;
            {
                unsigned int previous = old;
                old = value;
                if (value != previous)
                    continue;
            }
            break;
        }
    }
    *(volatile unsigned int *)0xCC003018 = 1;
    start = OSGetTime();
    do {
        now = OSGetTime();
    } while (now - start <= 50);
    *(volatile unsigned int *)0xCC003018 = 0;
    start = OSGetTime();
    do {
        now = OSGetTime();
    } while (now - start <= 5);
    if (((unsigned int)__GXIsGPFifoReady() & 0xFF) != 0) {
        __GXCleanGPFifo();
        __GXInitRevisionBits();
        data[0x5FC / 4] = 0;
    } else {
        __GXSetDirtyState();
    }
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    *(volatile unsigned int *)0xCC008000 = 0;
    PPCSync();
}
#pragma use_lmw_stmw reset

// __GXData is the GX data block (the SDK's `gx`). The game's copy is bigger than
// struct __GXData_struct in <revolution/GX/__gx.h> -- its dirtyState sits at
// 0x5FC, not 0x4F0 -- so only the head fields this file uses are named here.
typedef struct {
    /* 0x000 */ unsigned short vNum;
    /* 0x002 */ unsigned short bpSent;
    /* 0x004 */ char pad_004[0x5F8];
    /* 0x5FC */ unsigned int dirtyState;
} GXDataHead;
#define GX_DATA ((GXDataHead *)__GXData)

// RAS command word that pushes a 16-bit draw token to the BP: token in bits
// 0-15, BP register address (0 here) in bits 16-23, opcode in bits 24-31. The
// SDK's GXSetDrawSync sends its token twice, once with each opcode.
#define GX_RAS_TOKEN_OPCODE_FIRST 0x48
#define GX_RAS_TOKEN_OPCODE_LAST 0x47

// This unit declares OSRestoreInterrupts as taking no argument, so the saved
// mask has to be passed through a pointer of the right type.
typedef void (*GXRestoreInterruptsFn)(s32);

/* Pushes a 16-bit draw token to the BP as a pair of RAS commands (the FIFO byte
 * GX_FIFO_CMD_LOAD_BP_REG hands the next word to the BP as a command), re-sends
 * the BP state if it went dirty, flushes the write-gather pipe with 32 bytes of
 * zero and clears gx->bpSent so the next draw pushes the BP state again.
 * Interrupts stay off so no other thread can interleave a FIFO write. */
void GXMiscInit(s32 token) {
    union {
        unsigned int value;
        struct {
            unsigned int top : 8;
            unsigned int middle : 8;
            unsigned int low : 16;
        } fields;
    } command;
    s32 interruptMask;
    volatile unsigned char *fifoByte = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifoWord = (volatile unsigned int *)0xCC008000;

    interruptMask = OSDisableInterrupts();
    command.value = (unsigned int)token | (GX_RAS_TOKEN_OPCODE_FIRST << 24);
    *fifoByte = GX_FIFO_CMD_LOAD_BP_REG;
    *fifoWord = command.value;
    command.fields.low = (unsigned int)token;
    command.fields.top = GX_RAS_TOKEN_OPCODE_LAST;
    *fifoByte = GX_FIFO_CMD_LOAD_BP_REG;
    *fifoWord = command.value;

    if (GX_DATA->dirtyState != 0) {
        __GXSetDirtyState();
    }

    *fifoWord = 0;
    *fifoWord = 0;
    *fifoWord = 0;
    *fifoWord = 0;
    *fifoWord = 0;
    *fifoWord = 0;
    *fifoWord = 0;
    *fifoWord = 0;
    PPCSync();
    ((GXRestoreInterruptsFn)OSRestoreInterrupts)(interruptMask);
    GX_DATA->bpSent = 0;
}

/* Issue a GX draw-sync (token 0) command, flush dirty state, sync, and clear the draw-done flag. */
void GXSetDrawSync(void) {
    s32 interruptState = OSDisableInterrupts();
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifo = (volatile unsigned int *)0xCC008000;

    *fifo8 = 0x61;
    *fifo = 0x45000002;
    if (__GXData[0x5FC / 4] != 0) {
        __GXSetDirtyState();
    }
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    PPCSync();
    lbl_8055D970 = 0;
    ((void (*)(s32))OSRestoreInterrupts)(interruptState);
}

void GXSetDrawSyncCallback(void) {
    s32 state1 = OSDisableInterrupts();
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifo = (volatile unsigned int *)0xCC008000;

    /* Issue a draw-sync command/token sequence to the GX FIFO, flush dirty state, then wait for completion. */
    *fifo8 = 0x61;
    *fifo = 0x45000002;
    if (__GXData[0x5FC / 4] != 0) {
        __GXSetDirtyState();
    }
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    PPCSync();
    lbl_8055D970 = 0;
    ((void (*)(s32))OSRestoreInterrupts)(state1);
    {
        s32 state2 = OSDisableInterrupts();
        while (lbl_8055D970 == 0) {
            OSSleepThread(&lbl_8055D968);
        }
        ((void (*)(s32))OSRestoreInterrupts)(state2);
    }
}

void __GXSetGenMode(void) {
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = __GXData[0x22C / 4];
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXGetCullMode(s32 arg0, u8 arg1) {
    __peReg[3] = (arg0 << 8) | arg1;
}

/* The 16-bit bitfield places width in the low bits and matches the target rlwimi. */
void GXGetLineWidth(s32 arg0) {
    struct {
        unsigned short unused : 14;
        unsigned short width : 2;
    } value = {0, 0};
    value.width = arg0;
    __peReg[4] = *(unsigned short *)&value | 4;
}

void GXGetPointSize(s32 arg0) {
    ((GXPointSizeReg *)&__peReg[1])->pointSize = arg0;
}

void GXInitLightAttnA(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    int type = 0;
    int a;
    unsigned int value = __peReg[1];
    if (arg0 != 1) {
        if (arg0 == 3) {
            type = 1;
        }
    }
    value = __rlwimi(value, type, 0, 31, 31);
    a = __cntlzw(arg0 - 3);
    value = __rlwimi(value, a, 6, 20, 20);
    value = __rlwimi(value, __cntlzw(arg0 - 2), 28, 30, 30);
    value = __rlwimi(value, arg3, 12, 16, 19);
    value = __rlwimi(value, arg1, 8, 21, 23);
    value = __rlwimi(value, arg2, 5, 24, 26);
    value = __rlwimi(value, 0x41, 24, 0, 7);
    __peReg[1] = value;
}

void GXInitLightAttnK(s32 arg0) {
    ((GXAttnKReg *)&__peReg[1])->attenuationK = arg0;
}

void GXInitLightSpot(s32 arg0, s32 arg1) {
    union {
        unsigned int reg;
        struct {
            unsigned int pad : 23;
            unsigned int bit : 1;
            unsigned int value : 8;
        } fields;
    } data = {0};

    data.fields.value = arg1;
    data.fields.bit = arg0;
    __peReg[2] = data.reg;
}

void GXInitLightDistAttn(unsigned int arg0) {
    ((GXDistAttnReg *)&__peReg[1])->distanceAttn = arg0;
}

void GXGetLightPos(unsigned int x, unsigned int y, unsigned int z) {
    union {
        unsigned int reg;
        struct {
            unsigned int pad : 27;
            unsigned int zBit : 1;
            unsigned int yBits : 3;
            unsigned int xBit : 1;
        } fields;
    } data = {0};

    data.fields.xBit = x;
    data.fields.yBits = y;
    data.fields.zBit = z;
    *__peReg = (unsigned short)data.reg;
}

void GXInitLightDir(unsigned int x, unsigned int y, unsigned int *arg2) {
    union {
        unsigned int addr;
        struct {
            unsigned int prefix : 8;
            unsigned int flag : 2;
            unsigned int yBits : 10;
            unsigned int xBits : 10;
            unsigned int low : 2;
        } fields;
    } address;

    address.addr = 0xC8000000;
    address.fields.xBits = x;
    address.fields.yBits = y;
    address.fields.flag = 1;
    *arg2 = *(unsigned int *)address.addr;
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
extern GXPEIntrHandler __OSSetInterruptHandler(int type, GXPEIntrHandler handler);
extern void __GXFifoInit(void);
extern unsigned int __OSUnmaskInterrupts(unsigned int userMask);
extern void OSWakeupThread(void *);
extern void OSSleepThread(void *);
extern void OSInitThreadQueue(void *);
extern void (*lbl_8055D978_callback)(unsigned short);
#pragma cplusplus on
#pragma scheduling 750
void GXInitSpecularDir(unsigned int arg0, void *ctx) {
    extern unsigned int lbl_8055D978;
    extern unsigned short *__peReg;
    extern void OSClearContext(void *);
    extern void OSSetCurrentContext(void *);
    char local[0x2D0];
    unsigned short value = __peReg[7];
    if (lbl_8055D978 != 0) {
        OSClearContext(local);
        OSSetCurrentContext(local);
        ((void (*)(unsigned short))lbl_8055D978)(value);
        OSClearContext(local);
        OSSetCurrentContext(ctx);
    }
    __peReg[5] |= 4;
}
#pragma scheduling reset
#pragma cplusplus reset
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

void __GXSetDirtyState(void) {
    unsigned int *data = __GXData;
    unsigned int dirty = data[0x5FC / 4];
    unsigned int r4;
    u8 *ptr1;
    unsigned int count1;
    unsigned int reg;
    u8 *ptr2;
    unsigned int count2;

    if (dirty & 1) {
        __GXSetSUTexRegs();
    }
    if (dirty & 2) {
        __GXUpdateBPMask();
    }
    if (dirty & 4) {
        WGPIPE.c = 0x61;
        WGPIPE.i = __GXData[0x254 / 4];
        *(unsigned short *)((char *)__GXData + 2) = 0;
    }
    if (dirty & 8) {
        __GXSetVCD();
    }
    if (dirty & 0x10) {
        __GXSetVAT();
    }
    if (dirty & 0x18) {
        __GXCalculateVLim();
    }
    dirty &= ~0xFF;
    if (dirty) {
        r4 = dirty & 0xF00;
        if (r4) {
            if (r4 & 0x100) {
                WGPIPE.c = 0x10;
                WGPIPE.i = 0x100A;
                WGPIPE.i = data[0xA8 / 4];
            }
            if (r4 & 0x200) {
                WGPIPE.c = 0x10;
                WGPIPE.i = 0x100B;
                WGPIPE.i = data[0xAC / 4];
            }
            if (r4 & 0x400) {
                WGPIPE.c = 0x10;
                WGPIPE.i = 0x100C;
                WGPIPE.i = data[0xB0 / 4];
            }
            if (r4 & 0x800) {
                WGPIPE.c = 0x10;
                WGPIPE.i = 0x100D;
                WGPIPE.i = data[0xB4 / 4];
            }
        }
        count1 = dirty & 0x0100F000;
        if (count1) {
            reg = 0x100E;
            if (count1 & 0x01000000) {
                unsigned int val = (data[0x254 / 4] >> 4) & 7;
                WGPIPE.c = 0x10;
                WGPIPE.i = 0x1009;
                WGPIPE.i = val;
            }
            ptr1 = (u8*)data;
            count1 = (count1 >> 12) & 0xF;
            while (count1) {
                if (count1 & 1) {
                    WGPIPE.c = 0x10;
                    WGPIPE.i = reg;
                    WGPIPE.i = *(u32*)(ptr1 + 0xB8);
                }
                ptr1 += 4;
                count1 >>= 1;
                reg += 1;
            }
        }
        count2 = dirty & 0x02FF0000;
        if (count2) {
            reg = 0x1040;
            if (count2 & 0x02000000) {
                unsigned int val = data[0x254 / 4] & 0xF;
                WGPIPE.c = 0x10;
                WGPIPE.i = 0x103F;
                WGPIPE.i = val;
            }
            ptr2 = (u8*)data;
            count2 = (count2 >> 16) & 0xFF;
            while (count2 != 0) {
                unsigned int reg2 = reg + 0x10;
                if (count2 & 1) {
                    WGPIPE.c = 0x10;
                    WGPIPE.i = reg;
                    WGPIPE.i = *(u32*)(ptr2 + 0xC8);
                    WGPIPE.c = 0x10;
                    WGPIPE.i = reg2;
                    WGPIPE.i = *(u32*)(ptr2 + 0xE8);
                }
                count2 >>= 1;
                reg++;
                ptr2 += 4;
            }
        }
        if (dirty & 0x04000000) {
            __GXSetMatrixIndex(0);
            __GXSetMatrixIndex(5);
        }
        if (dirty & 0x10000000) {
            __GXSetViewport();
        }
        if (dirty & 0x08000000) {
            __GXSetProjection();
        }
        *(unsigned short *)((char *)data + 2) = 1;
    }
    data[0x5FC / 4] = 0;
}

void GXBegin(unsigned char prim, unsigned char vtxfmt, unsigned short nverts) {
    unsigned int *data = __GXData;
    unsigned int *dim;
    unsigned int count;
    unsigned int rounded;
    unsigned int remaining;
    unsigned int written;
    unsigned int blocks;
    unsigned short width;
    unsigned short height;
    unsigned int zero;

    if (data[0x5FC / 4] != 0)
        __GXSetDirtyState();
    if (data[0] == 0) {
        dim = *(unsigned int * volatile *)&__GXData;
        written = 0;
        width = *(unsigned short *)((char *)dim + 4);
        height = *(unsigned short *)((char *)dim + 6);
        *(volatile unsigned char *)0xCC008000 = 0x98;
        count = (unsigned int)width * height;
        *(volatile unsigned short *)0xCC008000 = *(volatile unsigned short *)((char *)dim + 4);
        if (count != 0) {
            rounded = count + 3;
            remaining = count - 0x20;
            if ((rounded >> 2) > 8) {
                int valid = 0;
                if (rounded >= 3) {
                    if (count <= rounded)
                        valid = 1;
                }
                if (valid) {
                    blocks = (remaining + 0x1F) >> 5;
                    zero = 0;
                    if (remaining <= 0)
                        goto end_large_clear;
                    do {
                        *(volatile unsigned int *)0xCC008000 = zero;
                        *(volatile unsigned int *)0xCC008000 = zero;
                        *(volatile unsigned int *)0xCC008000 = zero;
                        *(volatile unsigned int *)0xCC008000 = zero;
                        *(volatile unsigned int *)0xCC008000 = zero;
                        *(volatile unsigned int *)0xCC008000 = zero;
                        *(volatile unsigned int *)0xCC008000 = zero;
                        *(volatile unsigned int *)0xCC008000 = zero;
                        written += 0x20;
                    } while (--blocks != 0);
                }
            }
        end_large_clear:
            blocks = (count + 3 - written) >> 2;
            if (written < count) {
                zero = 0;
                do {
                    *(volatile unsigned int *)0xCC008000 = zero;
                } while (--blocks != 0);
            }
        }
        *(unsigned short *)((char *)data + 2) = 1;
    }
    *(volatile unsigned char *)0xCC008000 = vtxfmt | prim;
    *(volatile unsigned short *)0xCC008000 = nverts;
}

#pragma dont_inline on
void __GXSendFlushPrim(void) {
    u32 i;
    u32 sz = gxdraw->numChans * gxdraw->vLim;

    WGPIPE.uc = GX_TRIANGLESTRIP;
    WGPIPE.us = gxdraw->numChans;

    for (i = 0; i < sz; i += 4) {
        WGPIPE.i = 0;
    }

    gxdraw->lastWriteWasXF = TRUE;
}
#pragma dont_inline reset
void GXSetLineWidth(s32 width, s32 format) {
    union {
        unsigned int value;
        struct {
            unsigned int unused0 : 13;
            unsigned int format : 3;
            unsigned int unused1 : 8;
            unsigned int width : 8;
        } bits;
    } reg;
    unsigned int *data = __GXData;

    reg.value = data[0x7C / 4];
    reg.bits.width = width;
    reg.bits.format = format;
    data[0x7C / 4] = reg.value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x7C / 4];
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetPointSize(s32 size, s32 format) {
    union {
        unsigned int value;
        struct {
            unsigned int unused0 : 10;
            unsigned int format : 3;
            unsigned int unused1 : 3;
            unsigned int size : 8;
            unsigned int unused2 : 8;
        } bits;
    } reg;
    unsigned int *data = __GXData;

    reg.value = data[0x7C / 4];
    reg.bits.size = size;
    reg.bits.format = format;
    data[0x7C / 4] = reg.value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x7C / 4];
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXEnableTexOffsets(s32 texMap, s32 line, s32 point) {
    union {
        unsigned int value;
        struct {
            unsigned int unused0 : 12;
            unsigned int point_bit : 1;
            unsigned int line_bit : 1;
            unsigned int unused1 : 18;
        } bits;
    } reg;
    unsigned int *data = __GXData;
    reg.value = data[texMap + 0x108 / 4];
    reg.bits.line_bit = line;
    reg.bits.point_bit = point;
    data[texMap + 0x108 / 4] = reg.value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[texMap + 0x108 / 4];
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetCullMode(unsigned int mode) { unsigned int field; union { unsigned int reg; struct { unsigned int pad : 16; unsigned int cull : 2; unsigned int rest : 14; } fields; } data; field = ((mode << 1) & 2); field |= (mode >> 1) & 1; data.reg = __GXData[0x254 / 4]; data.fields.cull = field; __GXData[0x254 / 4] = data.reg; __GXData[0x5FC / 4] |= 4; }

void GXSetCoPlanar(s32 enable) { union { unsigned int reg; struct { unsigned int pad0 : 12; unsigned int coplanar : 1; unsigned int pad1 : 19; } fields; } u; u.reg = __GXData[0x254 / 4]; u.fields.coplanar = enable; __GXData[0x254 / 4] = u.reg; *(volatile unsigned char *)0xCC008000 = 0x61; *(volatile unsigned int *)0xCC008000 = 0xFE080000; *(volatile unsigned char *)0xCC008000 = 0x61; *(volatile unsigned int *)0xCC008000 = __GXData[0x254 / 4]; }

/* GXDrawCylinder(from, to, insetX, insetY)
 *
 * Copies the 0x3C-byte VI/render-mode record `from` over `to` (unless they are
 * the same record) and re-fits its screen rectangle for a border of insetX
 * pixels and insetY lines left around the picture.  This is the record the
 * game keeps in lbl_8055FD64 - the five modes at lbl_803038D8..lbl_803039C8
 * and the working copy lbl_804C9724 that fn_802CEAC4 builds - and the fields
 * are the ones the GX setup calls read: +0x04/+0x06/+0x08 are the frame-buffer
 * width, efb height and xfb height GXSetScissor, GXSetDispCopySrc and
 * GXGetYScaleFactor take, and +0x0A/+0x0C is a rectangle origin with its size
 * at +0x0E/+0x10.  Each size loses twice the inset (dx and dy below) while the
 * origin moves in by (insetX, insetY), so the rectangle shrinks on all four
 * sides; +0x06 is scaled by efbHeight/xfbHeight, +0x08 only loses half the
 * vertical inset when the mode (low two bits of word 0) is 0 and the flag at
 * +0x14 is clear, and +0x10 loses twice dy when the mode is 1.  The name is
 * the game's own symbol; nothing here draws a cylinder.
 */
void GXDrawCylinder(void *srcMode, void *dstMode, int insetX, int insetY) {
    unsigned int dx = (insetX << 1) & 0xFFFE; /* what every width loses */
    unsigned int dy = (insetY << 1) & 0xFFFE; /* what every height loses */
    unsigned int word0, word1, mode;
    unsigned short value;
    if (srcMode != dstMode) {
        word1 = *(unsigned int *)((char *)srcMode + 0x00); word0 = *(unsigned int *)((char *)srcMode + 0x04);
        *(unsigned int *)((char *)dstMode + 0x00) = word1; *(unsigned int *)((char *)dstMode + 0x04) = word0;
        word0 = *(unsigned int *)((char *)srcMode + 0x08); word1 = *(unsigned int *)((char *)srcMode + 0x0C);
        *(unsigned int *)((char *)dstMode + 0x08) = word0; *(unsigned int *)((char *)dstMode + 0x0C) = word1;
        word0 = *(unsigned int *)((char *)srcMode + 0x10); word1 = *(unsigned int *)((char *)srcMode + 0x14);
        *(unsigned int *)((char *)dstMode + 0x10) = word0; *(unsigned int *)((char *)dstMode + 0x14) = word1;
        word0 = *(unsigned int *)((char *)srcMode + 0x18); word1 = *(unsigned int *)((char *)srcMode + 0x1C);
        *(unsigned int *)((char *)dstMode + 0x18) = word0; *(unsigned int *)((char *)dstMode + 0x1C) = word1;
        word0 = *(unsigned int *)((char *)srcMode + 0x20); word1 = *(unsigned int *)((char *)srcMode + 0x24);
        *(unsigned int *)((char *)dstMode + 0x20) = word0; *(unsigned int *)((char *)dstMode + 0x24) = word1;
        word0 = *(volatile unsigned int *)((char *)srcMode + 0x28);
        word1 = *(volatile unsigned int *)((char *)srcMode + 0x2C);
        *(unsigned int *)((char *)dstMode + 0x28) = word0; *(unsigned int *)((char *)dstMode + 0x2C) = word1;
        word0 = *(volatile unsigned int *)((char *)srcMode + 0x30);
        word1 = *(volatile unsigned int *)((char *)srcMode + 0x34);
        *(unsigned int *)((char *)dstMode + 0x30) = word0; *(unsigned int *)((char *)dstMode + 0x34) = word1;
        word0 = *(unsigned int *)((char *)srcMode + 0x38);
        *(unsigned int *)((char *)dstMode + 0x38) = word0;
    }
    value = *(volatile unsigned short *)((char *)srcMode + 4);
    mode = *(volatile unsigned int *)srcMode & 3;
    *(unsigned short *)((char *)dstMode + 4) = value - dx;
    value = *(volatile unsigned short *)((char *)srcMode + 6);
    *(unsigned short *)((char *)dstMode + 6) = value - ((dy * value) / *(volatile unsigned short *)((char *)srcMode + 8));
    if (*(int *)((char *)srcMode + 0x14) == 0 && mode == 0)
        *(unsigned short *)((char *)dstMode + 8) = *(volatile unsigned short *)((char *)srcMode + 8) - ((dy >> 1) & 0x7FFF);
    else
        *(unsigned short *)((char *)dstMode + 8) = *(volatile unsigned short *)((char *)srcMode + 8) - dy;
    *(unsigned short *)((char *)dstMode + 0xE) = *(unsigned short *)((char *)srcMode + 0xE) - dx;
    if (mode == 1)
        *(unsigned short *)((char *)dstMode + 0x10) = *(unsigned short *)((char *)srcMode + 0x10) - ((dy << 1) & 0x1FFFE);
    else
        *(unsigned short *)((char *)dstMode + 0x10) = *(unsigned short *)((char *)srcMode + 0x10) - dy;
    *(unsigned short *)((char *)dstMode + 0xA) = *(unsigned short *)((char *)srcMode + 0xA) + insetX;
    *(unsigned short *)((char *)dstMode + 0xC) = *(unsigned short *)((char *)srcMode + 0xC) + insetY;
}

void GXSetDispCopySrc(s32 left, s32 top, s32 width, s32 height) {
    union {
        u32 value;
        struct {
            unsigned int tag : 8;
            unsigned int reserved : 4;
            unsigned int y : 10;
            unsigned int x : 10;
        } bits;
    } src, dst;
    unsigned int *data = __GXData;

    src.value = 0;
    dst.value = 0;
    src.bits.x = left;
    src.bits.y = top;
    src.bits.tag = 0x49;
    dst.bits.x = width - 1;
    dst.bits.y = height - 1;
    dst.bits.tag = 0x4A;
    data[0x230 / 4] = src.value;
    data[0x234 / 4] = dst.value;
}

void GXSetTexCopySrc(s32 x, s32 y, s32 width, s32 height) {
    union {
        u32 value;
        struct {
            unsigned int tag : 8;
            unsigned int reserved : 4;
            unsigned int y : 10;
            unsigned int x : 10;
        } bits;
    } src, dst;
    unsigned int *data = __GXData;

    src.value = 0;
    dst.value = 0;
    src.bits.x = x;
    src.bits.y = y;
    src.bits.tag = 0x49;
    dst.bits.x = width - 1;
    dst.bits.y = height - 1;
    dst.bits.tag = 0x4A;
    data[0x240 / 4] = src.value;
    data[0x244 / 4] = dst.value;
}

void GXSetDispCopyDst(s32 value) {
    unsigned int *gx = __GXData;
    unsigned int arg = (unsigned int)(((value << 1) & 0xFFFE) >> 5);
    unsigned int reg = 0;
    reg = __rlwimi(reg, arg, 0, 22, 31);
    reg = __rlwimi(reg, 0x4D, 24, 0, 7);
    gx[0x238 / 4] = reg;
}

void __GetImageTileCount(unsigned int, int, int, int *, int *, int *);
void GXSetTexCopyDst(u16 width, u16 height, int format, int depth) {
    typedef struct {
        u32 unusedTop : 15;
        u32 copyMode : 2;
        u32 unusedMiddle : 5;
        u32 depthBit : 1;
        u32 unusedLowMiddle : 2;
        u32 formatLow : 3;
        u32 formatHigh : 1;
        u32 unusedLow : 3;
    } CopyControlReg;
    union {
        u32 reg;
        struct {
            u32 constant : 8;
            u32 pad : 14;
            u32 stride : 10;
        } f;
    } data;
    int tilesX;
    int tilesY;
    int compressed;
    int fmt;
    unsigned int *gx = __GXData;
    unsigned int *gx2;
    CopyControlReg *reg;

    *((u8 *)gx + 0x250) = 0;
    fmt = format & 0xF;
    if (format == 0x13)
        fmt = 0xB;
    switch (format) {
    case 0x0:
    case 0x1:
    case 0x2:
    case 0x3:
    case 0x26:
        reg = (CopyControlReg *)((u8 *)gx + 0x24C);
        reg->copyMode = 3;
        break;
    default:
        reg = (CopyControlReg *)((u8 *)gx + 0x24C);
        reg->copyMode = 2;
        break;
    }
    *((u8 *)gx + 0x250) = (format >> 4) & 1;
    reg->formatHigh = (fmt >> 3) & 1;
    gx2 = *(unsigned int *volatile *)&__GXData;
    __GetImageTileCount(format, width, height, &tilesX, &tilesY, &compressed);
    gx2[0x248 / 4] = 0;
    data.reg = 0;
    data.f.stride = tilesX * compressed;
    data.f.constant = 0x4D;
    gx2[0x248 / 4] = data.reg;
    reg->depthBit = depth;
    reg->formatLow = fmt;
}

void GXSetDispCopyFrame2Field(s32 value) {
    union {
        unsigned int reg;
        struct {
            unsigned int pad : 18;
            unsigned int field : 2;
            unsigned int rest : 12;
        } fields;
    } data;
    unsigned int *gx = __GXData;
    data.reg = gx[0x23C / 4];
    data.fields.field = value;
    gx[0x23C / 4] = data.reg;
    gx[0x24C / 4] &= 0xFFFFCFFF;
}

void GXSetCopyClamp(s32 value) {
    u32 reg;
    reg = __GXData[0x23C / 4];
    reg = __rlwimi(reg, value, 0, 31, 31);
    reg = __rlwimi(reg, value, 0, 30, 30);
    __GXData[0x23C / 4] = reg;
    reg = __GXData[0x24C / 4];
    reg = __rlwimi(reg, value, 0, 31, 31);
    reg = __rlwimi(reg, value, 0, 30, 30);
    __GXData[0x24C / 4] = reg;
}

/* Display-copy Y scale (BP register 0x4D) is a 9-bit 8.8 fixed-point value:
 * GX_YSCALE_ONE is 1:1, only GX_YSCALE_MASK+1 values exist, and a copy never
 * produces more than GX_XFB_MAX_LINES XFB lines. */
#define GX_YSCALE_ONE   256.0f
#define GX_YSCALE_MASK  0x1FF
#define GX_XFB_MAX_LINES 0x400

f32 GXGetYScaleFactor(u32 efbHeight, u32 xfbHeight) {
    f32 prevScale;
    f32 yScale;
    u32 lineSpan, xfbLines, numXfbLines, yScaleBits;

    /* Pick the display-copy Y scale that turns an EFB of efbHeight lines into
     * xfbHeight XFB lines (GXRenderModeObj's efbHeight/xfbHeight at the call
     * site).  The BP Y-Scale field is 9 bits of 8.8 fixed point, so the code
     * walks a trial XFB line count down and then back up, each time working
     * out - with the calculation GXGetNumXfbLines() does, which the SDK's
     * -inline auto folded in here - how many XFB lines that scale would
     * really copy, and stops once it can reach xfbHeight.  Returns the
     * xfbLines/efbHeight ratio to hand to GXSetDispCopyYScale(); it is the
     * last one that did not copy more than xfbHeight lines.
     * (GXFrameBuf.h declares the two parameters as u16; this build's code
     * converts them to f32 as unsigned 32-bit values.) */
    yScale = (f32)xfbHeight / (f32)efbHeight;
    xfbLines = xfbHeight;
    yScaleBits = (u32)(GX_YSCALE_ONE / yScale) & GX_YSCALE_MASK;
    lineSpan = (efbHeight - 1) << 8;
    numXfbLines = lineSpan / yScaleBits + 1;

    /* between 1:1 and 2:1, a scale that divides efbHeight exactly copies one
     * line more than the integer division says */
    if (yScaleBits > 0x80 && yScaleBits < 0x100) {
        while (!(yScaleBits & 1))
            yScaleBits >>= 1;
        if (efbHeight % yScaleBits == 0)
            numXfbLines++;
    }

    if (numXfbLines > GX_XFB_MAX_LINES)
        numXfbLines = GX_XFB_MAX_LINES;

    while (numXfbLines > xfbHeight) {
        xfbLines--;
        yScale = (f32)xfbLines / (f32)efbHeight;
        yScaleBits = (u32)(GX_YSCALE_ONE / yScale) & GX_YSCALE_MASK;
        numXfbLines = lineSpan / yScaleBits + 1;
        if (yScaleBits > 0x80 && yScaleBits < 0x100) {
            while (!(yScaleBits & 1))
                yScaleBits >>= 1;
            if (efbHeight % yScaleBits == 0)
                numXfbLines++;
        }
        if (numXfbLines > GX_XFB_MAX_LINES)
            numXfbLines = GX_XFB_MAX_LINES;
    }

    prevScale = yScale;

    while (numXfbLines < xfbHeight) {
        xfbLines++;
        prevScale = yScale;
        yScale = (f32)xfbLines / (f32)efbHeight;
        yScaleBits = (u32)(GX_YSCALE_ONE / yScale) & GX_YSCALE_MASK;
        numXfbLines = lineSpan / yScaleBits + 1;
        if (yScaleBits > 0x80 && yScaleBits < 0x100) {
            while (!(yScaleBits & 1))
                yScaleBits >>= 1;
            if (efbHeight % yScaleBits == 0)
                numXfbLines++;
        }
        if (numXfbLines > GX_XFB_MAX_LINES)
            numXfbLines = GX_XFB_MAX_LINES;
    }

    return prevScale;
}

extern f32 lbl_80560B40;
unsigned int GXSetDispCopyYScale(f32 yScale) {
    unsigned int scale = (unsigned int)(lbl_80560B40 / yScale);
    unsigned int width;
    unsigned int result;
    unsigned int value;
    unsigned int tmp;
    unsigned int height;
    union {
        unsigned int value;
        struct {
            unsigned int tag : 8;
            unsigned int reserved : 15;
            unsigned int scale : 9;
        } fields;
    } packet;
    union {
        unsigned int value;
        struct {
            unsigned int reserved : 21;
            unsigned int flag : 1;
            unsigned int other : 10;
        } fields;
    } copyState;
    height = scale & 0x1FF;

    *(volatile unsigned char *)0xCC008000 = 0x61;
    packet.value = 0;
    packet.fields.scale = scale;
    packet.fields.tag = 0x4E;
    *(volatile unsigned int *)0xCC008000 = packet.value;
    ((volatile unsigned short *)__GXData)[1] = 0;
    tmp = (0x100 - height) | (height - 0x100);
    copyState.value = __GXData[0x23C / 4];
    copyState.fields.flag = tmp >> 31;
    __GXData[0x23C / 4] = copyState.value;
    width = (__GXData[0x234 / 4] >> 10) & 0x3FF;
    value = width + 1;
    result = (((value - 1) << 8) / height) + 1;
    if (height > 0x80 && height < 0x100) {
        while ((height & 1) == 0) {
            height >>= 1;
        }
        if (value % height == 0) result++;
    }
    if (result > 0x400) result = 0x400;
    return result;
}

void GXSetCopyClear(unsigned char *color, unsigned int depth) {
    unsigned int first = 0;
    unsigned int second = 0;
    unsigned int third = 0;
    unsigned int *data;
    first = __rlwimi(first, color[0], 0, 24, 31);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    first = __rlwimi(first, color[3], 8, 16, 23);
    first = __rlwimi(first, 0x4F, 24, 0, 7);
    *(volatile unsigned int *)0xCC008000 = first;
    second = __rlwimi(second, color[2], 0, 24, 31);
    second = __rlwimi(second, color[1], 8, 16, 23);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    second = __rlwimi(second, 0x50, 24, 0, 7);
    data = __GXData;
    *(volatile unsigned int *)0xCC008000 = second;
    third = __rlwimi(third, depth, 0, 8, 31);
    third = __rlwimi(third, 0x51, 24, 0, 7);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = third;
    *(unsigned short *)((char *)data + 2) = 0;
}

#pragma use_lmw_stmw off
void GXSetCopyFilter(int arg0, unsigned char *arg1, int arg2, unsigned char *arg3) {
    union MSLoc {
        unsigned int word;
        struct {
            unsigned int tag : 8;
            unsigned int n5 : 4;
            unsigned int n4 : 4;
            unsigned int n3 : 4;
            unsigned int n2 : 4;
            unsigned int n1 : 4;
            unsigned int n0 : 4;
        } bits;
    };
    union Coeff {
        unsigned int word;
        struct {
            unsigned int tag : 8;
            unsigned int f3 : 6;
            unsigned int f2 : 6;
            unsigned int f1 : 6;
            unsigned int f0 : 6;
        } bits;
    };
    union MSLoc a,b,c,d;
    union Coeff coeff0,coeff1;
    if (arg0 != 0) {
        a.word = 0;
        b.word = 0;
        c.word = 0;
        d.word = 0;
        d.bits.n0 = arg1[18];
        c.bits.n0 = arg1[12];
        b.bits.n0 = arg1[6];
        a.bits.n0 = arg1[0];
        d.bits.n1 = arg1[19];
        c.bits.n1 = arg1[13];
        b.bits.n1 = arg1[7];
        a.bits.n1 = arg1[1];
        d.bits.n2 = arg1[20];
        c.bits.n2 = arg1[14];
        b.bits.n2 = arg1[8];
        a.bits.n2 = arg1[2];
        d.bits.n3 = arg1[21];
        c.bits.n3 = arg1[15];
        b.bits.n3 = arg1[9];
        a.bits.n3 = arg1[3];
        d.bits.n4 = arg1[22];
        c.bits.n4 = arg1[16];
        b.bits.n4 = arg1[10];
        a.bits.n4 = arg1[4];
        d.bits.n5 = arg1[23];
        c.bits.n5 = arg1[17];
        b.bits.n5 = arg1[11];
        a.bits.n5 = arg1[5];
        d.bits.tag = 4;
        c.bits.tag = 3;
        b.bits.tag = 2;
        a.bits.tag = 1;
    } else {
        a.word = 0x01666666u;
        b.word = 0x02666666u;
        c.word = 0x03666666u;
        d.word = 0x04666666u;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = a.word;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = b.word;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = c.word;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = d.word;
    coeff0.word = 0;
    coeff0.bits.tag = 0x53;
    coeff1.word = 0;
    coeff1.bits.tag = 0x54;
    if (arg2 != 0) {
        coeff0.bits.f0 = arg3[0];
        coeff0.bits.f1 = arg3[1];
        coeff0.bits.f2 = arg3[2];
        coeff0.bits.f3 = arg3[3];
        coeff1.bits.f0 = arg3[4];
        coeff1.bits.f1 = arg3[5];
        coeff1.bits.f2 = arg3[6];
    } else {
        coeff0.bits.f0 = 0;
        coeff0.bits.f1 = 0;
        coeff0.bits.f2 = 21;
        coeff0.bits.f3 = 22;
        coeff1.bits.f0 = 21;
        coeff1.bits.f1 = 0;
        coeff1.bits.f2 = 0;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = coeff0.word;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = coeff1.word;
    *(volatile unsigned short *)((unsigned char *)__GXData + 2) = 0;
}
void GXSetDispCopyGamma(s32 arg0) {
    ((GXDispCopyGammaReg *)&__GXData[0x23c / 4])->gamma = arg0;
}

void GXCopyDisp(unsigned int source, int clear) {
    volatile unsigned int *gx;
    volatile unsigned int *reg;
    unsigned int value;
    unsigned int sourceValue;
    int changed;

    if (clear != 0) {
        gx = __GXData;
        value = gx[0x228 / 4];
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = value | 0xF;
        value = gx[0x220 / 4];
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = value & ~3u;
    }

    changed = 0;
    if (clear == 0) {
        gx = (volatile unsigned int *)*(unsigned int * volatile *)(void *)&__GXData;
        value = gx[0x22C / 4];
        reg = (volatile unsigned int *)((volatile unsigned char *)gx + 0x22C);
        if ((value & 7) == 3) {
            gx = (volatile unsigned int *)*(unsigned int * volatile *)(void *)&__GXData;
            value = gx[0x22C / 4];
            reg = (volatile unsigned int *)((volatile unsigned char *)gx + 0x22C);
            if (((value >> 6) & 1) == 1) {
                GXCopyWGFifo.u8 = 0x61;
                value &= ~0x40u;
                GXCopyWGFifo.u32 = value;
                changed = 1;
            }
        }
    }

    gx = __GXData;
    GXCopyWGFifo.u8 = 0x61;
    GXCopyWGFifo.u32 = gx[0x230 / 4];
    GXCopyWGFifo.u8 = 0x61;
    GXCopyWGFifo.u32 = gx[0x234 / 4];
    GXCopyWGFifo.u8 = 0x61;
    GXCopyWGFifo.u32 = gx[0x238 / 4];

    sourceValue = __rlwimi(0, source, 27, 8, 31);
    sourceValue = __rlwimi(sourceValue, 0x4B, 24, 0, 7);
    GXCopyWGFifo.u8 = 0x61;
    GXCopyWGFifo.u32 = sourceValue;

    value = gx[0x23C / 4];
    value = __rlwimi(value, clear, 11, 20, 20);
    value |= 0x4000;
    value = __rlwimi(value, 0x52, 24, 0, 7);
    gx[0x23C / 4] = value;
    GXCopyWGFifo.u8 = 0x61;
    value = gx[0x23C / 4];
    GXCopyWGFifo.u32 = value;

    if (clear != 0) {
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = gx[0x228 / 4];
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = gx[0x220 / 4];
    }
    if (changed != 0) {
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = *reg;
    }
    *(volatile unsigned short *)((volatile unsigned char *)gx + 2) = 0;
}

/* The GX data block (__GXData) holds every BP register GX has set so that it can
 * re-send them; this build of GX keeps them 0x50 above the release SDK's
 * layout, and only the fields the texture copy needs are named here. */
typedef struct {
    unsigned char pad_000[0x002];
    unsigned short bpSent;                 /* 0x002 BP state the CP is not told about */
    unsigned char pad_004[0x220 - 0x004];
    unsigned int cmode0;                   /* 0x220 colour and alpha compare modes */
    unsigned char pad_224[4];
    unsigned int zmode;                    /* 0x228 depth test and write modes */
    unsigned int peCtrl;                   /* 0x22C pixel type and z-update control */
    unsigned char pad_230[0x240 - 0x230];
    unsigned int cpTexSrc;                 /* 0x240 copy source: format and address */
    unsigned int cpTexSize;                /* 0x244 copy width and height */
    unsigned int cpTexStride;              /* 0x248 copy stride */
    unsigned int cpTex;                    /* 0x24C copy control: clear bit and destination */
    unsigned char cpTexZ;                  /* 0x250 the copy covers the depth buffer too */
} GXTexCopyData;
#define GXRegs (*(GXTexCopyData *)__GXData)

/* Copy the texture the TEV pipeline produced into the frame-buffer target at
 * dest: re-send the depth, colour and pixel-engine registers the copy needs,
 * then the copy source, size, stride, destination and control registers.  With
 * clear the depth buffer is cleared along with the image, so the depth test is
 * forced on and colour writes turned off first, and both registers are re-sent
 * once the copy has been queued. */
void GXCopyTex(void *dest, s32 clear) {
    s32 changePeCtrl;
    u32 reg;
    if (clear != 0) {
        u32 marker = 0x61;   /* GP_RAS_REG: write one BP register */
        u32 zmode;
        zmode = GXRegs.zmode | 0xF;             /* depth test and write always on */
        GXCopyWGFifo.u8 = marker;
        GXCopyWGFifo.u32 = zmode;
        reg = GXRegs.cmode0;
        GXCopyWGFifo.u8 = marker;
        GXCopyWGFifo.u32 = reg & 0xFFFFFFFC;    /* colour and alpha compare off */
    }
    changePeCtrl = 0;
    reg = GXRegs.peCtrl;
    if (GXRegs.cpTexZ != 0 && (reg & 7) != 3) { /* a depth copy needs the Z pixel type */
        changePeCtrl = 1;
        reg = __rlwimi(reg, 3, 0, 29, 31);
    }
    if ((clear != 0 || (reg & 7) == 3) && ((reg >> 6) & 1) == 1) {
        changePeCtrl = 1;
        reg &= 0xFFFFFFBF;                      /* let the copy write the depth */
    }
    if (changePeCtrl != 0) {
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = reg;
    }
    GXCopyWGFifo.u8 = 0x61;
    GXCopyWGFifo.u32 = GXRegs.cpTexSrc;
    GXCopyWGFifo.u8 = 0x61;
    GXCopyWGFifo.u32 = GXRegs.cpTexSize;
    GXCopyWGFifo.u8 = 0x61;
    GXCopyWGFifo.u32 = GXRegs.cpTexStride;
    reg = __rlwimi(0, (u32)dest, 27, 8, 31);    /* destination, in 32-byte units */
    reg = __rlwimi(reg, 0x4B, 24, 0, 7);        /* CP_TEX_COPY_DEST */
    GXCopyWGFifo.u8 = 0x61;
    GXCopyWGFifo.u32 = reg;
    reg = GXRegs.cpTex;
    reg = __rlwimi(reg, clear, 11, 20, 20);     /* the clear-image bit */
    reg &= 0xFFFFBFFF;                          /* a texture copy, not a display copy */
    reg = __rlwimi(reg, 0x52, 24, 0, 7);        /* CP_TEX_COPY */
    GXRegs.cpTex = reg;
    GXCopyWGFifo.u8 = 0x61;
    reg = *(volatile unsigned int *)((char *)__GXData + 0x24C); /* reload what gets queued */
    GXCopyWGFifo.u32 = reg;
    if (clear != 0) {
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = GXRegs.zmode;
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = GXRegs.cmode0;
    }
    if (changePeCtrl != 0) {
        GXCopyWGFifo.u8 = 0x61;
        GXCopyWGFifo.u32 = GXRegs.peCtrl;
    }
    GXRegs.bpSent = 0;
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

/* Computes distance attenuation coefficients (ka, kb, kc) for a light from distance and brightness. */
void GXInitLightDistAttn_Internal(GXLightObjImpl* light, f32 distance, f32 brightness,
                                  GXDistAttnFn fn) {
    f32 a, b, c;

    if (distance < 0.0f) {
        fn = GX_DA_OFF;
    }

    if (brightness <= 0.0f || brightness >= 1.0f) {
        fn = GX_DA_OFF;
    }

    switch (fn) {
    case GX_DA_GENTLE:
        a = 1.0f;
        b = (1.0f - brightness) / (brightness * distance);
        c = 0.0f;
        break;
    case GX_DA_MEDIUM:
        a = 1.0f;
        b = (0.5f * (1.0f - brightness)) / (brightness * distance);
        c = (0.5f * (1.0f - brightness)) / (distance * (brightness * distance));
        break;
    case GX_DA_STEEP:
        a = 1.0f;
        b = 0.0f;
        c = (1.0f - brightness) / (distance * (brightness * distance));
        break;
    case GX_DA_OFF:
    default:
        a = 1.0f;
        b = 0.0f;
        c = 0.0f;
        break;
    }

    light->ka = a;
    light->kb = b;
    light->kc = c;
}

void GXInitLightPos(void *arg0, float farg0, float farg1, float farg2) {
    *(float *)((char *)arg0 + 0x28) = farg0;
    *(float *)((char *)arg0 + 0x2C) = farg1;
    *(float *)((char *)arg0 + 0x30) = farg2;
}

void GXGetLightDir_Internal(void *arg0, float farg0, float farg1, float farg2, float farg3, float farg4, float farg5) {
 extern const float lbl_80560B5C;
 float c, b, a;
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
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifo32 = (volatile unsigned int *)0xCC008000;
    volatile double *fifo64 = (volatile double *)0xCC008000;
    const double *src = (const double *)((char *)arg0 + 0x10);
    unsigned int count = 31 - __cntlzw(arg1);
    *fifo8 = 0x10;
    fifo32[0] = (((count & 7) << 4) + 0x600) | 0xF0000;
    fifo32[0] = *(unsigned int *)((char *)arg0 + 0xC);
    fifo32[0] = 0;
    fifo32[0] = 0;
    fifo64[0] = src[0];
    fifo64[0] = src[1];
    fifo64[0] = src[2];
    fifo64[0] = src[3];
    fifo64[0] = src[4];
    fifo64[0] = src[5];
    ((volatile unsigned short *)__GXData)[1] = 1;
}

void GXSetChanAmbColor_Internal(s32 type, void *color) {
    /* Update a GX channel ambient color register (RGB, alpha, or full word) for channel 0/1 and mark it dirty. */
    unsigned int value;
    register unsigned int which;
    unsigned int colorValue;
    unsigned char alpha;
    union {
        unsigned int value;
        struct {
            unsigned int high : 24;
            unsigned int low : 8;
        } fields;
    } merged;

    switch (type) {
    case 0:
        which = 0;
        colorValue = *(unsigned int *)color;
        merged.value = __GXData[0xA8 / 4];
        merged.fields.high = colorValue >> 8;
        value = merged.value;
        break;
    case 1:
        which = 1;
        colorValue = *(unsigned int *)color;
        merged.value = __GXData[0xAC / 4];
        merged.fields.high = colorValue >> 8;
        value = merged.value;
        break;
    case 2:
        which = 0;
        alpha = ((unsigned char *)color)[3];
        merged.value = __GXData[0xA8 / 4];
        merged.fields.low = alpha;
        value = merged.value;
        break;
    case 3:
        which = 1;
        alpha = ((unsigned char *)color)[3];
        merged.value = __GXData[0xAC / 4];
        merged.fields.low = alpha;
        value = merged.value;
        break;
    case 4:
        which = 0;
        value = *(unsigned int *)color;
        break;
    case 5:
        which = 1;
        value = *(unsigned int *)color;
        break;
    default:
        return;
    }
    __GXData[0x5FC / 4] |= 0x100 << which;
    *(unsigned int *)((unsigned char *)__GXData + 0xA8 + (which << 2)) = value;
}

void GXSetChanMatColor_Internal(s32 type, void *color) {
    /* Update a GX channel material color register (RGB, alpha, or full word) for channel 0/1 and mark it dirty. */
    unsigned int value;
    register unsigned int which;
    unsigned int colorValue;
    unsigned char alpha;
    union {
        unsigned int value;
        struct {
            unsigned int high : 24;
            unsigned int low : 8;
        } fields;
    } merged;

    switch (type) {
    case 0:
        which = 0;
        colorValue = *(unsigned int *)color;
        merged.value = __GXData[0xB0 / 4];
        merged.fields.high = colorValue >> 8;
        value = merged.value;
        break;
    case 1:
        which = 1;
        colorValue = *(unsigned int *)color;
        merged.value = __GXData[0xB4 / 4];
        merged.fields.high = colorValue >> 8;
        value = merged.value;
        break;
    case 2:
        which = 0;
        alpha = ((unsigned char *)color)[3];
        merged.value = __GXData[0xB0 / 4];
        merged.fields.low = alpha;
        value = merged.value;
        break;
    case 3:
        which = 1;
        alpha = ((unsigned char *)color)[3];
        merged.value = __GXData[0xB4 / 4];
        merged.fields.low = alpha;
        value = merged.value;
        break;
    case 4:
        which = 0;
        value = *(unsigned int *)color;
        break;
    case 5:
        which = 1;
        value = *(unsigned int *)color;
        break;
    default:
        return;
    }
    __GXData[0x5FC / 4] |= 0x400 << which;
    *(unsigned int *)((unsigned char *)__GXData + 0xB0 + (which << 2)) = value;
}

void GXSetNumChans(s32 num) { union { unsigned int reg; struct { unsigned int pad0 : 25; unsigned int chans : 3; unsigned int pad1 : 4; } fields; } u; u.reg = __GXData[0x254 / 4]; u.fields.chans = num; __GXData[0x254 / 4] = u.reg; __GXData[0x5FC / 4] |= 0x01000004; }

// The argument types of GXSetChanCtrl, from include/revolution/GX/GXTypes.h.
typedef enum _GXChannelID {
    GX_COLOR0,   // 0 color channel 0
    GX_COLOR1,   // 1 color channel 1
    GX_ALPHA0,   // 2 alpha channel 0
    GX_ALPHA1,   // 3 alpha channel 1
    GX_COLOR0A0, // 4 color 0 and its alpha: ALPHA0CNTRL follows it
    GX_COLOR1A1, // 5 color 1 and its alpha: ALPHA1CNTRL follows it

    GX_COLOR_NULL = 255
} GXChannelID;

// GXBool of include/revolution/GX/GXTypes.h.
typedef unsigned char GXBool;

// Where a channel's color comes from: the XF register or the vertex.
typedef enum _GXColorSrc { GX_SRC_REG, GX_SRC_VTX } GXColorSrc;

typedef enum _GXLightID {
    GX_LIGHT0 = (1 << 0),
    GX_LIGHT1 = (1 << 1),
    GX_LIGHT2 = (1 << 2),
    GX_LIGHT3 = (1 << 3), // the four low ones go to LMASKLO,
    GX_LIGHT4 = (1 << 4), // the four high ones to LMASKHI
    GX_LIGHT5 = (1 << 5),
    GX_LIGHT6 = (1 << 6),
    GX_LIGHT7 = (1 << 7),

    GX_MAX_LIGHT = (1 << 8),
    GX_LIGHT_NULL = 0
} GXLightID;

typedef enum _GXDiffuseFn { GX_DF_NONE, GX_DF_SIGN, GX_DF_CLAMP } GXDiffuseFn;

// Counted the other way round from the names: specular is 0, "no attenuation"
// is the last of the three.
typedef enum _GXAttnFn { GX_AF_SPEC, GX_AF_SPOT, GX_AF_NONE } GXAttnFn;

// __GXData's channel part; GXVtxDescData above names 0x5FC the same way.
#define XF_COLOR0CNTRL 0xB8 // COLOR0CNTRL..COLOR3CNTRL, one word per channel
#define XF_ALPHA0CNTRL 0xC0 // ALPHA0CNTRL
#define XF_ALPHA1CNTRL 0xC4 // ALPHA1CNTRL
#define XF_DIRTY_STATE 0x5FC

// The dirty bits of GXDirtyFlag (GXTypes.h) for the four channel words.
#define DIRTY_CHAN_COLOR0 0x1000 // 1 << 12
#define DIRTY_CHAN_COLOR1 0x2000 // 1 << 13
#define DIRTY_CHAN_ALPHA0 0x4000 // 1 << 14
#define DIRTY_CHAN_ALPHA1 0x8000 // 1 << 15

// One XF COLORnCNTRL / ALPHAnCNTRL word. The bit numbers are the hardware's,
// counted from the MSB; see COLOR0CNTRL in
// include/revolution/GX/GXHardwareXF.h.
typedef union _GXChanCtrl {
    u32 value;
    struct {
        u32 pad0 : 17;       // 00-16
        u32 lightMaskHi : 4; // 17-20 GX_LIGHT4..GX_LIGHT7
        u32 attnSelect : 1;  // 21    0: specular, 1: spot attenuation
        u32 attnEnable : 1;  // 22    attenuation used at all
        u32 diffuse : 2;     // 23-24 GXDiffuseFn
        u32 ambSrc : 1;      // 25    ambient: GXColorSrc
        u32 lightMaskLo : 4; // 26-29 GX_LIGHT0..GX_LIGHT3
        u32 light : 1;       // 30    the channel is lit
        u32 matSrc : 1;      // 31    material: GXColorSrc
    } f;
} GXChanCtrl;

/* Writes the XF COLORnCNTRL word of one color or alpha channel: whether it is
   lit, where its ambient and material colors come from, which lights reach it
   and how its diffuse/attenuation term is computed. GX_COLOR0A0 and GX_COLOR1A1
   copy the word into ALPHA0CNTRL/ALPHA1CNTRL too. The channel's dirty bit makes
   __GXSetDirtyState resend the words to the XF before the next draw. */
void GXSetChanCtrl(GXChannelID chan, GXBool enable, GXColorSrc ambSrc, GXColorSrc matSrc,
                   GXLightID lightMask, GXDiffuseFn diffFn, GXAttnFn attnFn) {
    GXChanCtrl u;
    unsigned int *gxData;
    unsigned int *chanCtrl;
    unsigned int regIdx = chan & 3;
    unsigned int diffuse = diffFn;

    u.value = 0;
    u.f.light = enable;
    u.f.matSrc = matSrc;
    u.f.ambSrc = ambSrc;
    /* specular light has no distance attenuation to speak of */
    if (attnFn == GX_AF_SPEC) {
        diffuse = GX_DF_NONE;
    }
    u.f.diffuse = diffuse;
    u.f.attnEnable = (attnFn != GX_AF_NONE);
    u.f.attnSelect = (attnFn != GX_AF_SPEC);
    u.f.lightMaskLo = lightMask;
    u.f.lightMaskHi = ((unsigned int)lightMask) >> 4;
    gxData = __GXData;
    chanCtrl = gxData + regIdx;
    chanCtrl[XF_COLOR0CNTRL / 4] = u.value;
    gxData[XF_DIRTY_STATE / 4] |= DIRTY_CHAN_COLOR0 << regIdx;
    if (chan == GX_COLOR0A0) {
        gxData[XF_ALPHA0CNTRL / 4] = u.value;
        gxData[XF_DIRTY_STATE / 4] |= DIRTY_CHAN_COLOR0 | DIRTY_CHAN_ALPHA0;
        return;
    }
    if (chan == GX_COLOR1A1) {
        gxData[XF_ALPHA1CNTRL / 4] = u.value;
        gxData[XF_DIRTY_STATE / 4] |= DIRTY_CHAN_COLOR1 | DIRTY_CHAN_ALPHA1;
    }
}

unsigned int GXGetTexBufferSize(unsigned short width, unsigned short height, unsigned int format, unsigned int mipmap, unsigned int max_lod)
{
    unsigned int tileShiftX;
    unsigned int tileShiftY;
    unsigned int tileBytes;
    unsigned int bufferSize;
    unsigned int nx;
    unsigned int ny;
    unsigned int level;

    /* Computes the GX texture buffer size in bytes for a format, dimensions, and mip levels. */
    __GXGetTexTileShift_8003DB9C(format, &tileShiftX, &tileShiftY);
    if (format == 0x6 || format == 0x16) {
        tileBytes = 64;
    } else {
        tileBytes = 32;
    }
    if (mipmap == 1) {
        nx = 1 << (31 - __cntlzw(width));
        ny = 1 << (31 - __cntlzw(height));

        bufferSize = 0;
        for (level = 0; level < max_lod; level++) {
            nx = (width + (1 << tileShiftX) - 1) >> tileShiftX;
            ny = (height + (1 << tileShiftY) - 1) >> tileShiftY;
            bufferSize += tileBytes * (nx * ny);
            if (width == 1 && height == 1) {
                break;
            }
            width = (width > 1) ? (width >> 1) : 1;
            height = (height > 1) ? (height >> 1) : 1;
        }
    } else {
        nx = (width + (1 << tileShiftX) - 1) >> tileShiftX;
        ny = (height + (1 << tileShiftY) - 1) >> tileShiftY;
        bufferSize = nx * ny * tileBytes;
    }
    return bufferSize;
}

void __GetImageTileCount(unsigned int format, int width, int height, int *tilesX, int *tilesY, int *tileBlocks) {
    /* Compute tile counts and block compression factor for a GX texture/copy format. */
    int tileWidthShift;
    int tileHeightShift;

    switch (format) {
    case 0x0:
    case 0x8:
    case 0xE:
    case 0x20:
    case 0x30:
        tileWidthShift = 3;
        tileHeightShift = 3;
        break;
    case 0x1:
    case 0x2:
    case 0x9:
    case 0x11:
    case 0x22:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x39:
    case 0x3A:
        tileWidthShift = 3;
        tileHeightShift = 2;
        break;
    case 0x3:
    case 0x4:
    case 0x5:
    case 0x6:
    case 0xA:
    case 0x13:
    case 0x16:
    case 0x23:
    case 0x2B:
    case 0x2C:
    case 0x3C:
        tileWidthShift = 2;
        tileHeightShift = 2;
        break;
    default:
        tileHeightShift = 0;
        tileWidthShift = 0;
        break;
    }

    if (width == 0)
        width = 1;
    if (height == 0)
        height = 1;

    *tilesX = (width + (1 << tileWidthShift) - 1) >> tileWidthShift;
    *tilesY = (height + (1 << tileHeightShift) - 1) >> tileHeightShift;
    *tileBlocks = ((int)format == 6 || (int)format == 0x16) ? 2 : 1;
}

void GXInitTexObj(void *obj, void *image, unsigned short width, unsigned short height, int format, int wrapS, int wrapT, int mipmap) {
    u32 mode, image0, image3;
    u32 level;
    int rowShift, colShift;
    u32 *p = (u32 *)obj;
    u8 *b = (u8 *)obj;
    u32 fmt = format;
    memset(obj, 0, 0x20);
    mode = p[0];
    mode = __rlwimi(mode, wrapS, 0, 30, 31);
    mode = __rlwimi(mode, wrapT, 2, 28, 29);
    mode |= 0x10;
    p[0] = mode;
    if (mipmap) {
        b[0x1f] |= 1;
        if (fmt - 8 <= 2) {
            mode = __rlwimi(mode, 5, 5, 24, 26); p[0] = mode;
        } else {
            mode = __rlwimi(mode, 6, 5, 24, 26); p[0] = mode;
        }
        if (width > height) level = 31 - __cntlzw(width);
        else level = 31 - __cntlzw(height);
        p[1] = __rlwimi(p[1], (u8)(16.0f * (f32)level), 8, 16, 23);
    } else {
        mode = __rlwimi(mode, 4, 5, 24, 26);
        p[0] = mode;
    }
    image0 = p[2];
    image0 = __rlwimi(image0, width - 1, 0, 22, 31);
    image0 = __rlwimi(image0, height - 1, 10, 12, 21);
    p[5] = fmt;
    image3 = p[3];
    image3 = __rlwimi(image3, (u32)image, 27, 8, 31);
    image0 = __rlwimi(image0, fmt, 20, 8, 11);
    p[3] = image3;
    p[2] = image0;
    switch (fmt & 15) {
    case 0: case 8:
        b[0x1e] = 1; rowShift = 3; colShift = 3; break;
    case 1: case 2: case 9:
        b[0x1e] = 2; rowShift = 3; colShift = 2; break;
    case 3: case 4: case 5: case 10:
        b[0x1e] = 2; rowShift = 2; colShift = 2; break;
    case 6:
        b[0x1e] = 3; rowShift = 2; colShift = 2; break;
    case 14:
        b[0x1e] = 0; rowShift = 3; colShift = 3; break;
    default:
        b[0x1e] = 2; rowShift = 2; colShift = 2; break;
    }
    b[0x1f] |= 2;
    *(u16 *)(b + 0x1c) = (((width + (1 << rowShift) - 1) >> rowShift) * ((height + (1 << colShift) - 1) >> colShift)) & 0x7fff;
}

extern void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, int);
void GXInitTexObjCI(void *obj, void *image, unsigned short width, unsigned short height, int format, int wrap_s, int wrap_t, int mipmap, int tlut_name) {
    GXInitTexObj(obj, image, width, height, format, wrap_s, wrap_t, mipmap);
    *(int *)((char *)obj + 0x18) = tlut_name;
    *(unsigned char *)((char *)obj + 0x1F) &= ~2;
}

// Level-of-detail half of a texture object: packs the min and mag filters, the LOD
// bias, the min and max LODs, the anisotropy and the edge-LOD flag into the
// object's two mode words. The bias is a x32 fixed-point number clamped to
// [-4.0, 3.99] and the LODs are x16 fixed-point clamped to [0.0, 10.0], which is
// all each field can hold.
void GXInitTexObjLOD(void *obj, GXTexFilter min_filt, GXTexFilter mag_filt, f32 min_lod, f32 max_lod, f32 lod_bias, u8 bias_clamp, u8 do_edge_lod, GXAnisotropy max_aniso) {
    __GXTexObjInt *t = (__GXTexObjInt *)obj;
    u32 mode0;
    u32 mode1;
    u8 lbias;
    u8 lmin;
    u8 lmax;

    if (lod_bias < -4.0f) {
        lod_bias = -4.0f;
    } else if (lod_bias >= 4.0f) {
        lod_bias = 3.99f;
    }
    lbias = 32.0f * lod_bias;
    mode0 = t->mode0;
    mode0 = GX_BITSET(mode0, TEXMODE0_LODBIAS_FIELD, 8, lbias);
    // __cntlzw has bit 5 set only when its argument was zero, so these two insert
    // the 1-bit tests without a branch; the rotate amount picks that bit out.
    mode0 = __rlwimi(mode0, __cntlzw(mag_filt - GX_LINEAR), 31, TEXMODE0_MAGFILT_FIELD, TEXMODE0_MAGFILT_FIELD);
    t->mode0 = mode0;
    mode0 = GX_BITSET(mode0, TEXMODE0_MINFILT_FIELD, 3, GX2HWFiltConv[min_filt]);
    mode0 = __rlwimi(mode0, __cntlzw(do_edge_lod), 3, TEXMODE0_EDGELOD_FIELD, TEXMODE0_EDGELOD_FIELD);
    mode1 = mode0 & ~0x00060000; // the two bits below the anisotropy go with it
    mode1 = GX_BITSET(mode1, TEXMODE0_ANISO_FIELD, 2, max_aniso);
    mode1 = GX_BITSET(mode1, TEXMODE0_BIASCLAMP_FIELD, 1, bias_clamp);
    t->mode0 = mode1;

    if (min_lod < 0.0f) {
        min_lod = 0.0f;
    } else if (min_lod > 10.0f) {
        min_lod = 10.0f;
    }
    lmin = 16.0f * min_lod;
    if (max_lod < 0.0f) {
        max_lod = 0.0f;
    } else if (max_lod > 10.0f) {
        max_lod = 10.0f;
    }
    lmax = 16.0f * max_lod;
    mode1 = t->mode1;
    mode1 = GX_BITSET(mode1, TEXMODE1_MINLOD_FIELD, 8, lmin);
    mode1 = GX_BITSET(mode1, TEXMODE1_MAXLOD_FIELD, 8, lmax);
    t->mode1 = mode1;
}

void GXInitTexObjWrapMode(int *obj, int wrap_s, int wrap_t) {
    ((GXTexWrapReg *)obj)->wrapS = wrap_s;
    ((GXTexWrapReg *)obj)->wrapT = wrap_t;
}

void GXInitTexObjTlut(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

void GXInitTexObjFilter(s32 *arg0, s32 arg1, s32 arg2) {
    union {
        s32 value;
        struct {
            unsigned int high : 24;
            unsigned int filter : 3;
            unsigned int mip : 1;
            unsigned int low : 4;
        } fields;
    } data;

    data.value = *arg0;
    data.fields.mip = ((unsigned int)__cntlzw(arg2 - 1) >> 5);
    *arg0 = data.value;
    data.fields.filter = ((unsigned char *)&lbl_80558E80)[arg1];
    *arg0 = data.value;
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

extern unsigned char lbl_80558E48, lbl_80558E50, lbl_80558E58;
extern unsigned char lbl_80558E60, lbl_80558E68, lbl_80558E70, lbl_80558E78;
void GXLoadTexObjPreLoaded(void *obj, void *region, int map) {
    unsigned int *a = (unsigned int *)obj;
    unsigned int *b = (unsigned int *)region;
    unsigned int *data;
    unsigned int *dst;
    unsigned char opcode = 0x61;

    a[0] = __rlwimi(a[0], (&lbl_80558E48)[map], 24, 0, 7);
    a[1] = __rlwimi(a[1], (&lbl_80558E50)[map], 24, 0, 7);
    a[2] = __rlwimi(a[2], (&lbl_80558E58)[map], 24, 0, 7);
    b[0] = __rlwimi(b[0], (&lbl_80558E60)[map], 24, 0, 7);
    b[1] = __rlwimi(b[1], (&lbl_80558E68)[map], 24, 0, 7);
    a[3] = __rlwimi(a[3], (&lbl_80558E70)[map], 24, 0, 7);
    *(volatile unsigned char *)0xCC008000 = opcode;
    *(volatile unsigned int *)0xCC008000 = a[0];
    *(volatile unsigned char *)0xCC008000 = opcode;
    *(volatile unsigned int *)0xCC008000 = a[1];
    *(volatile unsigned char *)0xCC008000 = opcode;
    *(volatile unsigned int *)0xCC008000 = a[2];
    *(volatile unsigned char *)0xCC008000 = opcode;
    *(volatile unsigned int *)0xCC008000 = b[0];
    *(volatile unsigned char *)0xCC008000 = opcode;
    *(volatile unsigned int *)0xCC008000 = b[1];
    *(volatile unsigned char *)0xCC008000 = opcode;
    *(volatile unsigned int *)0xCC008000 = a[3];
    if ((*(unsigned char *)((char *)obj + 0x1F) & 2) == 0) {
        data = __GXData;
        dst = ((unsigned int *(*)(unsigned int))data[0x51C / 4])(*(unsigned int *)((char *)obj + 0x18));
        dst[1] = __rlwimi(dst[1], (&lbl_80558E78)[map], 24, 0, 7);
        *(volatile unsigned char *)0xCC008000 = opcode;
        *(volatile unsigned int *)0xCC008000 = dst[1];
    }
    data = __GXData;
    dst = data + map;
    dst[0x564 / 4] = a[2];
    dst[0x584 / 4] = a[0];
    data[0x5FC / 4] |= 1;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXLoadTexObj(void *arg0, unsigned int arg1) {
    unsigned int *data = *(unsigned int * volatile *)&__GXData;
    void *result;
    result = ((void *(*)(void *))data[0x518 / 4])(arg0);
    GXLoadTexObjPreLoaded(arg0, result, arg1);
}

void GXInitTlutObj(void *arg0, unsigned int arg1, int arg2, short arg3) {
    union {
        unsigned int reg;
        struct {
            unsigned int type : 8;
            unsigned int format : 24;
        } fields;
    } value;
    union {
        unsigned int reg;
        struct {
            unsigned int pad : 20;
            unsigned int size : 2;
            unsigned int rest : 10;
        } fields;
    } size = {0};

    value.reg = *(unsigned int *)((char *)arg0 + 4);
    value.fields.format = arg1 >> 5;
    size.fields.size = arg2;
    *(short *)((char *)arg0 + 8) = arg3;
    value.fields.type = 0x64;
    *(unsigned int *)arg0 = size.reg;
    *(unsigned int *)((char *)arg0 + 4) = value.reg;
}

unsigned short GXGetTexObjTlut(void *arg0) {
    return *(unsigned short *)((char *)arg0 + 8);
}

void GXLoadTlut(void *arg0, int arg1) {
    union Low10 {
        unsigned int v;
        struct { unsigned int hi : 22; unsigned int lo : 10; } f;
    };
    union Low10 v;
    unsigned int * __restrict src = (unsigned int *)arg0;
    unsigned int * __restrict dst = ((unsigned int *(*)(int))__GXData[0x51C / 4])(arg1);
    __GXFlushTextureState();
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = src[1];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = dst[0];
    __GXFlushTextureState();
    v.v = src[0];
    v.f.lo = dst[0];
    dst[1] = v.v;
    dst[2] = src[1];
    dst[3] = src[2];
    src[0] = v.v;
}

/* Initialize a texture cache region's even/odd TMEM blocks and mipmap/cache flags. */
void GXInitTexCacheRegion(void *region, signed char is32bMipmap, unsigned int tmemEven, int sizeEven, unsigned int tmemOdd, int sizeOdd) {
    union {
        unsigned int word;
        struct {
            unsigned int pad : 11;
            unsigned int imageCount : 3;
            unsigned int size : 3;
            unsigned int tmem : 15;
        } fields;
    } reg;
    int widthExp = sizeEven;

    switch (widthExp) {
    case 0:
        widthExp = 3;
        break;
    case 1:
        widthExp = 4;
        break;
    case 2:
        widthExp = 5;
        break;
    }

    reg.word = 0;
    reg.fields.tmem = tmemEven >> 5;
    reg.fields.size = widthExp;
    reg.fields.imageCount = widthExp;
    *(unsigned int *)region = reg.word;

    switch (sizeOdd) {
    case 0:
        widthExp = 3;
        break;
    case 1:
        widthExp = 4;
        break;
    case 2:
        widthExp = 5;
        break;
    case 3:
        widthExp = 0;
        break;
    }

    reg.word = 0;
    reg.fields.tmem = tmemOdd >> 5;
    reg.fields.size = widthExp;
    reg.fields.imageCount = widthExp;
    *(unsigned char *)((char *)region + 0xC) = is32bMipmap;
    *((unsigned char *)region + 0xD) = 1;
    *(unsigned int *)((char *)region + 4) = reg.word;
}

void GXInitTlutRegion(unsigned int *region, int tmem_addr, int tlut_name) {
    struct {
        unsigned int type : 8;
        unsigned int unused : 3;
        unsigned int name : 11;
        unsigned int addr : 10;
    } value = {0, 0, 0, 0};
    value.addr = (unsigned int)(tmem_addr - 0x80000) >> 9;
    value.name = tlut_name;
    value.type = 0x65;
    *region = *(unsigned int *)&value;
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

void __GXSetSUTexRegs(void) {
    unsigned int *gx = __GXData;
    unsigned int *g2;
    char *tr;
    unsigned int count, i, limit, map, coord, word, off;
    if (gx[0x5E4 / 4] != 0xFF) {
        word = gx[0x254 / 4];
        count = (word >> 16) & 7;
        limit = ((word >> 10) & 0xF) + 1;
        for (i = 0; i < count; i++) {
            switch (i) {
            case 0:
                word = gx[0x170 / 4]; map = word & 7; coord = (word >> 3) & 7; break;
            case 1:
                word = gx[0x170 / 4]; map = (word >> 6) & 7; coord = (word >> 9) & 7; break;
            case 2:
                word = gx[0x170 / 4]; map = (word >> 12) & 7; coord = (word >> 15) & 7; break;
            case 3:
                word = gx[0x170 / 4]; map = (word >> 18) & 7; coord = (word >> 21) & 7; break;
            }
            if ((gx[0x5E4 / 4] & (1 << coord)) == 0) __SetSURegs(map, coord);
        }
        g2 = GXD;
        tr = (char *)g2 + 0x150;
        for (i = 0; i < limit; i++) {
            off = (i & ~1) << 1;
            map = g2[0x5A4 / 4 + i] & ~0x100;
            if (i & 1) coord = (*(unsigned int *)(tr + off) >> 15) & 7;
            else coord = (*(unsigned int *)(tr + off) >> 3) & 7;
            if (map != 0xFF && (gx[0x5E4 / 4] & (1 << coord)) == 0 && (g2[0x5E8 / 4] & (1 << i)) != 0)
                __SetSURegs(map, coord);
        }
    }
}

void __GXSetTmemConfig(s32 arg0) {
    volatile u8 *fifo8 = (volatile u8 *)0xCC008000;
    volatile u32 *fifo32 = (volatile u32 *)0xCC008000;
    if (arg0 == 1) goto case1;
    if (arg0 >= 1) goto compare3;
    goto default_case;
compare3:
    if (arg0 >= 3) goto default_case;
    *fifo8 = 0x61;
    *fifo32 = 0x8C0D8000;
    *fifo8 = 0x61;
    *fifo32 = 0x900DC000;
    *fifo8 = 0x61;
    *fifo32 = 0x8D0D8800;
    *fifo8 = 0x61;
    *fifo32 = 0x910DC800;
    *fifo8 = 0x61;
    *fifo32 = 0x8E0D9000;
    *fifo8 = 0x61;
    *fifo32 = 0x920DD000;
    *fifo8 = 0x61;
    *fifo32 = 0x8F0D9800;
    *fifo8 = 0x61;
    *fifo32 = 0x930DD800;
    *fifo8 = 0x61;
    *fifo32 = 0xAC0DA000;
    *fifo8 = 0x61;
    *fifo32 = 0xB00DC400;
    *fifo8 = 0x61;
    *fifo32 = 0xAD0DA800;
    *fifo8 = 0x61;
    *fifo32 = 0xB10DCC00;
    *fifo8 = 0x61;
    *fifo32 = 0xAE0DB000;
    *fifo8 = 0x61;
    *fifo32 = 0xB20DD400;
    *fifo8 = 0x61;
    *fifo32 = 0xAF0DB800;
    *fifo8 = 0x61;
    *fifo32 = 0xB30DDC00;
    goto done;
case1:
    *fifo8 = 0x61;
    *fifo32 = 0x8C0D8000;
    *fifo8 = 0x61;
    *fifo32 = 0x900DC000;
    *fifo8 = 0x61;
    *fifo32 = 0x8D0D8800;
    *fifo8 = 0x61;
    *fifo32 = 0x910DC800;
    *fifo8 = 0x61;
    *fifo32 = 0x8E0D9000;
    *fifo8 = 0x61;
    *fifo32 = 0x920DD000;
    *fifo8 = 0x61;
    *fifo32 = 0x8F0D9800;
    *fifo8 = 0x61;
    *fifo32 = 0x930DD800;
    *fifo8 = 0x61;
    *fifo32 = 0xAC0DA000;
    *fifo8 = 0x61;
    *fifo32 = 0xB00DE000;
    *fifo8 = 0x61;
    *fifo32 = 0xAD0DA800;
    *fifo8 = 0x61;
    *fifo32 = 0xB10DE800;
    *fifo8 = 0x61;
    *fifo32 = 0xAE0DB000;
    *fifo8 = 0x61;
    *fifo32 = 0xB20DF000;
    *fifo8 = 0x61;
    *fifo32 = 0xAF0DB800;
    *fifo8 = 0x61;
    *fifo32 = 0xB30DF800;
    goto done;
default_case:
    *fifo8 = 0x61;
    *fifo32 = 0x8C0D8000;
    *fifo8 = 0x61;
    *fifo32 = 0x900DC000;
    *fifo8 = 0x61;
    *fifo32 = 0x8D0D8400;
    *fifo8 = 0x61;
    *fifo32 = 0x910DC400;
    *fifo8 = 0x61;
    *fifo32 = 0x8E0D8800;
    *fifo8 = 0x61;
    *fifo32 = 0x920DC800;
    *fifo8 = 0x61;
    *fifo32 = 0x8F0D8C00;
    *fifo8 = 0x61;
    *fifo32 = 0x930DCC00;
    *fifo8 = 0x61;
    *fifo32 = 0xAC0D9000;
    *fifo8 = 0x61;
    *fifo32 = 0xB00DD000;
    *fifo8 = 0x61;
    *fifo32 = 0xAD0D9400;
    *fifo8 = 0x61;
    *fifo32 = 0xB10DD400;
    *fifo8 = 0x61;
    *fifo32 = 0xAE0D9800;
    *fifo8 = 0x61;
    *fifo32 = 0xB20DD800;
    *fifo8 = 0x61;
    *fifo32 = 0xAF0D9C00;
    *fifo8 = 0x61;
    *fifo32 = 0xB30DDC00;
done:
    ;
}

#pragma dont_inline GXSetTevIndirect
void GXSetTevIndirect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8, s32 arg9) {
    u32 cmd = 0;
    u32 opcode = arg0 + 0x10;
    unsigned int *data;
    cmd = __rlwimi(cmd, arg1, 0, 30, 31);
    cmd = __rlwimi(cmd, arg2, 2, 28, 29);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    cmd = __rlwimi(cmd, arg3, 4, 25, 27);
    cmd = __rlwimi(cmd, arg9, 7, 23, 24);
    data = __GXData;
    cmd = __rlwimi(cmd, arg4, 9, 19, 22);
    cmd = __rlwimi(cmd, arg5, 13, 16, 18);
    cmd = __rlwimi(cmd, arg6, 16, 13, 15);
    cmd = __rlwimi(cmd, arg8, 19, 12, 12);
    cmd = __rlwimi(cmd, arg7, 20, 11, 11);
    cmd = __rlwimi(cmd, opcode, 24, 0, 7);
    *(volatile unsigned int *)0xCC008000 = cmd;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetIndTexMtx(s32 type, f32 *matrix, s32 scale) {
    register s32 index3;
    register s32 scaleField;
    register u32 first;
    register u32 second;
    register u32 third;
    volatile u8 *fifo8 = (volatile u8 *)0xCC010000;
    volatile u32 *fifo32 = (volatile u32 *)0xCC010000;
    switch (type) {
    case 1: case 2: case 3:
        type -= 1;
        break;
    case 5: case 6: case 7:
        type -= 5;
        break;
    case 9: case 10: case 11:
        type -= 9;
        break;
    default:
        type = 0;
        break;
    }
    index3 = (type << 2) - type;
    scaleField = scale + 0x11;
    first = __rlwimi(0, (s32)(lbl_80560B88 * matrix[0]), 0, 21, 31);
    first = __rlwimi(first, (s32)(lbl_80560B88 * matrix[3]), 11, 10, 20);
    first = __rlwimi(first, scaleField, 22, 8, 9);
    first = __rlwimi(first, index3 + 6, 24, 0, 7);
    second = __rlwimi(0, (s32)(lbl_80560B88 * matrix[1]), 0, 21, 31);
    second = __rlwimi(second, (s32)(lbl_80560B88 * matrix[4]), 11, 10, 20);
    second = __rlwimi(second, scaleField, 20, 8, 9);
    second = __rlwimi(second, index3 + 7, 24, 0, 7);
    third = __rlwimi(0, (s32)(lbl_80560B88 * matrix[2]), 0, 21, 31);
    third = __rlwimi(third, (s32)(lbl_80560B88 * matrix[5]), 11, 10, 20);
    third = __rlwimi(third, scaleField, 18, 8, 9);
    third = __rlwimi(third, index3 + 8, 24, 0, 7);
    fifo8[-0x8000] = 0x61;
    fifo32[-0x8000 / 4] = first;
    fifo8[-0x8000] = 0x61;
    fifo32[-0x8000 / 4] = second;
    fifo8[-0x8000] = 0x61;
    fifo32[-0x8000 / 4] = third;
    *(volatile u16 *)((u8 *)__GXData + 2) = 0;
}

void GXSetIndTexCoordScale(s32 stage, s32 scaleS, s32 scaleT) {
    u32 reg;

    /* Configure indirect texture coordinate S/T scale for the given stage and write the register to the GX FIFO. */
    switch (stage) {
    case 0:
        reg = __GXData[0x178 / 4];
        reg = __rlwimi(reg, scaleS, 0, 28, 31);
        reg = __rlwimi(reg, scaleT, 4, 24, 27);
        reg = __rlwimi(reg, 0x25, 24, 0, 7);
        __GXData[0x178 / 4] = reg;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile u32 *)0xCC008000 = __GXData[0x178 / 4];
        break;
    case 1:
        reg = __GXData[0x178 / 4];
        reg = __rlwimi(reg, scaleS, 8, 20, 23);
        reg = __rlwimi(reg, scaleT, 12, 16, 19);
        reg = __rlwimi(reg, 0x25, 24, 0, 7);
        __GXData[0x178 / 4] = reg;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile u32 *)0xCC008000 = __GXData[0x178 / 4];
        break;
    case 2:
        reg = __GXData[0x17C / 4];
        reg = __rlwimi(reg, scaleS, 0, 28, 31);
        reg = __rlwimi(reg, scaleT, 4, 24, 27);
        reg = __rlwimi(reg, 0x26, 24, 0, 7);
        __GXData[0x17C / 4] = reg;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile u32 *)0xCC008000 = __GXData[0x17C / 4];
        break;
    case 3:
        reg = __GXData[0x17C / 4];
        reg = __rlwimi(reg, scaleS, 8, 20, 23);
        reg = __rlwimi(reg, scaleT, 12, 16, 19);
        reg = __rlwimi(reg, 0x26, 24, 0, 7);
        __GXData[0x17C / 4] = reg;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile u32 *)0xCC008000 = __GXData[0x17C / 4];
        break;
    }
    *(volatile u16 *)((u8 *)__GXData + 2) = 0;
}

/* Set indirect texture stage order: bind tex map/coord (0xFF -> 0) and write BP reg. */
void GXSetIndTexOrder(s32 arg0, s32 arg1, s32 arg2) {
    s32 r4 = arg1;
    s32 r5 = arg2;
    union {
        unsigned int value;
        struct {
            unsigned int unused : 8;
            unsigned int coord3 : 3;
            unsigned int map3 : 3;
            unsigned int coord2 : 3;
            unsigned int map2 : 3;
            unsigned int coord1 : 3;
            unsigned int map1 : 3;
            unsigned int coord0 : 3;
            unsigned int map0 : 3;
        } fields;
    } reg;

    if (r5 == 0xFF) {
        r5 = 0;
    }
    if (r4 == 0xFF) {
        r4 = 0;
    }

    switch (arg0) {
    case 0:
        reg.value = __GXData[0x170 / 4];
        reg.fields.map0 = r5;
        reg.fields.coord0 = r4;
        __GXData[0x170 / 4] = reg.value;
        break;
    case 1:
        reg.value = __GXData[0x170 / 4];
        reg.fields.map1 = r5;
        reg.fields.coord1 = r4;
        __GXData[0x170 / 4] = reg.value;
        break;
    case 2:
        reg.value = __GXData[0x170 / 4];
        reg.fields.map2 = r5;
        reg.fields.coord2 = r4;
        __GXData[0x170 / 4] = reg.value;
        break;
    case 3:
        reg.value = __GXData[0x170 / 4];
        reg.fields.map3 = r5;
        reg.fields.coord3 = r4;
        __GXData[0x170 / 4] = reg.value;
        break;
    }

    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = __GXData[0x170 / 4];
    __GXData[0x5FC / 4] |= 3;
    *(volatile unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetNumIndStages(unsigned int value) {
    union {
        unsigned int reg;
        struct {
            unsigned int pad : 13;
            unsigned int stages : 3;
            unsigned int rest : 16;
        } fields;
    } data;

    data.reg = __GXData[0x254 / 4];
    data.fields.stages = value;
    __GXData[0x254 / 4] = data.reg;
    __GXData[0x5FC / 4] |= 6;
}

extern void GXSetTevIndirect(s32, s32, s32, s32, s32, s32, s32, s32, u8, s32);
void GXSetTevDirect(int arg0) {
    GXSetTevIndirect(arg0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void __GXUpdateBPMask(void) {}

void __GXSetIndirectMask(s32 mask) {
    union {
        unsigned int value;
        struct {
            unsigned int unused0 : 24;
            unsigned int indirectMask : 8;
        } bits;
    } reg;
    unsigned int *data = __GXData;
    reg.value = data[0x174 / 4];
    reg.bits.indirectMask = mask;
    data[0x174 / 4] = reg.value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x174 / 4];
    *(unsigned short *)((char *)data + 2) = 0;
}

/* Use volatile byte and word FIFO stores, then clear the GXData halfword. */
#pragma dont_inline on
void __GXFlushTextureState(void) {
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = __GXData[0x174 / 4];
    *(unsigned short *)((char *)__GXData + 2) = 0;
}
#pragma dont_inline reset

extern unsigned int lbl_80303C30[];
void GXSetTevOp(int stage, int mode) {
    unsigned int *base = lbl_80303C30;
    unsigned int *data;
    unsigned int *tev;
    unsigned int *color;
    unsigned int *alpha;
    unsigned int value;
    unsigned int oldValue;
    unsigned int inputValue;

    if (stage == 0) {
        color = base;
        alpha = base + 10;
        color += mode;
        alpha += mode;
    } else {
        color = base + 5;
        alpha = base + 15;
        color += mode;
        alpha += mode;
    }
    data = __GXData;
    tev = data + stage;
    inputValue = *color;
    oldValue = tev[0x180 / 4];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = oldValue & 0xFF000000;
    value = __rlwimi(value, inputValue, 0, 8, 31);
    *(volatile unsigned int *)0xCC008000 = value;
    tev[0x180 / 4] = value;
    oldValue = tev[0x1C0 / 4];
    inputValue = *alpha;
    value = oldValue & 0xFF00000F;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = __rlwimi(value, inputValue, 0, 8, 27);
    *(volatile unsigned int *)0xCC008000 = value;
    tev[0x1C0 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevColorIn(s32 stage, s32 a, s32 b, s32 c, s32 d) { unsigned int *tev; unsigned int *base = __GXData; tev = (unsigned int *)((unsigned char *)base + stage * 4); { unsigned int value = tev[0x180 / 4]; value = __rlwimi(value, a, 12, 16, 19); value = __rlwimi(value, b, 8, 20, 23); *(volatile unsigned char *)0xCC008000 = 0x61; value = __rlwimi(value, c, 4, 24, 27); value = __rlwimi(value, d, 0, 28, 31); *(volatile unsigned int *)0xCC008000 = value; tev[0x180 / 4] = value; } *(unsigned short *)((unsigned char *)base + 2) = 0; }

void GXSetTevAlphaIn(s32 stage, s32 a, s32 b, s32 c, s32 d) {
    unsigned int *tev;
    unsigned int *base = __GXData;
    tev = (unsigned int *)((unsigned char *)base + stage * 4);
    {
        unsigned int value = tev[0x1C0 / 4];
        value = __rlwimi(value, a, 13, 16, 18);
        value = __rlwimi(value, b, 10, 19, 21);
        *(volatile unsigned char *)0xCC008000 = 0x61;
        value = __rlwimi(value, c, 7, 22, 24);
        value = __rlwimi(value, d, 4, 25, 27);
        *(volatile unsigned int *)0xCC008000 = value;
        tev[0x1C0 / 4] = value;
    }
    *(unsigned short *)((unsigned char *)base + 2) = 0;
}

void GXSetTevColorOp(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    unsigned int *base = __GXData;
    unsigned int *data;
    unsigned int v;
    data = (unsigned int *)((unsigned char *)base + arg0 * 4);
    v = data[0x180 / 4];
    v = __rlwimi(v, arg1, 18, 13, 13);
    if (arg1 <= 1) {
        v = __rlwimi(v, arg3, 20, 10, 11);
        v = __rlwimi(v, arg2, 16, 14, 15);
    } else {
        v = __rlwimi(v, arg1, 19, 10, 11);
        v |= 0x30000;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    v = __rlwimi(v, arg4, 19, 12, 12);
    v = __rlwimi(v, arg5, 22, 8, 9);
    *(volatile unsigned int *)0xCC008000 = v;
    data[0x180 / 4] = v;
    *(volatile unsigned short *)((unsigned char *)base + 2) = 0;
}

void GXSetTevAlphaOp(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    unsigned int *base = __GXData;
    int v;
    unsigned int *data;
    data = (unsigned int *)((unsigned char *)base + arg0 * 4);
    v = data[0x1C0 / 4];
    v = __rlwimi(v, arg1, 18, 13, 13);
    if (arg1 <= 1) {
        v = __rlwimi(v, arg3, 20, 10, 11);
        v = __rlwimi(v, arg2, 16, 14, 15);
    } else {
        v = __rlwimi(v, arg1, 19, 10, 11);
        v |= 0x30000;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    v = __rlwimi(v, arg4, 19, 12, 12);
    v = __rlwimi(v, arg5, 22, 8, 9);
    *(volatile unsigned int *)0xCC008000 = v;
    data[0x1C0 / 4] = v;
    *(volatile unsigned short *)((unsigned char *)base + 2) = 0;
}

void GXSetTevColor(s32 arg0, unsigned int *arg1) {
    s32 index = arg0 * 2;
    unsigned int value = *arg1;
    unsigned int first = (unsigned int)((index + 0xE0) << 24);
    unsigned int second;
    first = __rlwimi(first, value, 8, 24, 31);
    WGPIPE.c = 0x61;
    first = __rlwimi(first, value, 12, 12, 19);
    second = (unsigned int)((index + 0xE1) << 24);
    WGPIPE.i = first;
    second = __rlwimi(second, value, 24, 24, 31);
    WGPIPE.c = 0x61;
    second = __rlwimi(second, value, 28, 12, 19);
    WGPIPE.i = second;
    WGPIPE.c = 0x61;
    WGPIPE.i = second;
    WGPIPE.c = 0x61;
    WGPIPE.i = second;
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetTevColorS10(s32 tevReg, void *color) {
    s32 index;
    unsigned int c0, c1, regRA, regBG;
    unsigned int *data;
    index = tevReg << 1;
    c0 = *(unsigned int *)color;
    regRA = (index + 0xE0) << 24;
    c1 = *((unsigned int *)color + 1);
    data = __GXData;
    regRA = __rlwimi(regRA, c0, 16, 21, 31);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    regRA = __rlwimi(regRA, c1, 12, 9, 19);
    regBG = (index + 0xE1) << 24;
    *(volatile unsigned int *)0xCC008000 = regRA;
    regBG = __rlwimi(__rlwimi(regBG, c1, 16, 21, 31), c0, 12, 9, 19);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = regBG;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = regBG;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = regBG;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevKColor(s32 tevReg, unsigned int *color) {
    unsigned int index = tevReg << 1;
    unsigned int idx0 = index + 0xE0;
    unsigned int idx1 = index + 0xE1;
    unsigned int value = *color;
    unsigned int first = __rlwimi(__rlwimi(__rlwimi(idx0 << 24, value, 8, 24, 31), value, 12, 12, 19), 8, 20, 8, 11);
    unsigned int second = __rlwimi(__rlwimi(__rlwimi(idx1 << 24, value, 24, 24, 31), value, 28, 12, 19), 8, 20, 8, 11);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = first;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = second;
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetTevKColorSel(s32 arg0, s32 arg1) {
    struct OddField {
        unsigned int unused0 : 13;
        unsigned int selector : 5;
        unsigned int unused1 : 14;
    };
    struct EvenField {
        unsigned int unused0 : 23;
        unsigned int selector : 5;
        unsigned int unused1 : 4;
    };
    unsigned int *base = __GXData;
    unsigned int odd = arg0 & 1;
    unsigned int *entry = (unsigned int *)((u8 *)base + (((unsigned int)arg0 << 1) & ~3));
    if (odd) {
        ((struct OddField *)(entry + 0x80))->selector = arg1;
    } else {
        ((struct EvenField *)(entry + 0x80))->selector = arg1;
    }
    *(volatile u8 *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = entry[0x80];
    *(unsigned short *)((u8 *)base + 2) = 0;
}

void GXSetTevKAlphaSel(s32 arg0, s32 arg1) {
    union TevKAlphaReg {
        u32 value;
        struct { u32 pad0 : 8; u32 selector : 5; u32 pad1 : 19; } odd;
        struct { u32 pad0 : 18; u32 selector : 5; u32 pad1 : 9; } even;
    } *entry = (union TevKAlphaReg *)((char *)__GXData + ((arg0 * 2) & ~3) + 0x200);

    if (arg0 & 1) {
        entry->odd.selector = arg1;
    } else {
        entry->even.selector = arg1;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = entry->value;
    *(volatile unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetTevSwapMode(s32 arg0, s32 arg1, s32 arg2) {
    unsigned int *entry;
    unsigned int *base = __GXData;
    entry = (unsigned int *)((unsigned char *)base + arg0 * 4);
    {
        unsigned int value = entry[0x1C0 / 4];
        value = __rlwimi(value, arg1, 0, 30, 31);
        value = __rlwimi(value, arg2, 2, 28, 29);
        entry[0x1C0 / 4] = value;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = entry[0x1C0 / 4];
    *(unsigned short *)((unsigned char *)base + 2) = 0;
}

void GXSetTevSwapModeTable(s32 index, s32 rasSel, s32 texSel, s32 rasSel2, s32 texSel2) {
    union {
        u32 value;
        struct {
            unsigned int unused : 28;
            unsigned int texSel : 2;
            unsigned int rasSel : 2;
        } fields;
    } word;
    int offset0;
    int index2;
    int offset1;
    unsigned int *table;
    unsigned int *data;
    offset0 = index << 3;
    index2 = index << 1;
    offset1 = index2 + 1;
    data = __GXData;
    table = (unsigned int *)((char *)data + 0x200);
    word.value = *(u32 *)((char *)table + offset0);
    word.fields.rasSel = rasSel;
    word.fields.texSel = texSel;
    *(u32 *)((char *)table + offset0) = word.value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = *(u32 *)((char *)table + offset0);
    offset1 <<= 2;
    word.value = *(u32 *)((char *)table + offset1);
    word.fields.rasSel = rasSel2;
    word.fields.texSel = texSel2;
    *(u32 *)((char *)table + offset1) = word.value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = *(u32 *)((char *)table + offset1);
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetAlphaCompare(s32 comp0, s32 ref0, s32 op, s32 comp1, s32 ref1) {
    union {
        u32 value;
        struct {
            unsigned int reserved : 8;
            unsigned int op : 2;
            unsigned int comp1 : 3;
            unsigned int comp0 : 3;
            unsigned int ref1 : 8;
            unsigned int ref0 : 8;
        } bits;
    } reg;

    reg.value = 0xF3000000;
    reg.bits.ref0 = ref0;
    *(volatile u8 *)0xCC008000 = 0x61;
    reg.bits.ref1 = ref1;
    reg.bits.comp0 = comp0;
    reg.bits.comp1 = comp1;
    reg.bits.op = op;
    *(volatile u32 *)0xCC008000 = reg.value;
    *(volatile u16 *)((u8 *)__GXData + 2) = 0;
}

void GXSetZTexture(s32 op, s32 format, s32 bias) {
    union {
        unsigned int value;
        struct {
            unsigned int top : 8;
            unsigned int bias : 24;
        } bits;
    } first;
    union {
        unsigned int value;
        struct {
            unsigned int top : 8;
            unsigned int reserved : 20;
            unsigned int op : 2;
            unsigned int mode : 2;
        } bits;
    } second;
    unsigned int zmode;
    first.value = 0;
    first.bits.bias = bias;
    first.bits.top = 0xF4;
    switch (format) {
    case 0x11:
        zmode = 0;
        break;
    case 0x13:
        zmode = 1;
        break;
    case 0x16:
        zmode = 2;
        break;
    default:
        zmode = 2;
        break;
    }
    second.value = 0;
    second.bits.mode = zmode;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    second.bits.op = op;
    *(volatile unsigned int *)0xCC008000 = first.value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    second.bits.top = 0xF5;
    *(volatile unsigned int *)0xCC008000 = second.value;
    *(volatile unsigned short *)((char *)__GXData + 2) = 0;
}

extern unsigned int lbl_80303C80[];
void GXSetTevOrder(int stage, int texCoord, int texMap, int color) {
    extern unsigned int lbl_80303C80[];
    unsigned int map = (unsigned int)texMap & ~0x100u;
    unsigned int *data = __GXData;
    int stageAdj = stage + ((unsigned int)stage >> 31);
    unsigned int *bp = (unsigned int *)((char *)data + 0x150 + ((stageAdj << 1) & ~3));
    unsigned int *stageData = data + stage;
    unsigned int mapSel = (map >= 8) ? 0 : map;
    int colorSel;
    int texEnable;
    union {
        unsigned int value;
        struct {
            unsigned int unused2 : 10;
            unsigned int color1 : 3;
            unsigned int enable1 : 1;
            unsigned int coord1 : 3;
            unsigned int map1 : 3;
            unsigned int unused0 : 2;
            unsigned int color0 : 3;
            unsigned int enable0 : 1;
            unsigned int coord0 : 3;
            unsigned int map0 : 3;
        } fields;
    } tev;
    stageData[0x5a4 / 4] = texMap;
    if (texCoord >= 8) {
        texCoord = 0;
        data[0x5e8 / 4] &= ~(1 << stage);
    } else {
        data[0x5e8 / 4] |= 1 << stage;
    }
    if (stage & 1) {
        tev.value = bp[0];
        tev.fields.map1 = mapSel;
        tev.fields.coord1 = texCoord;
        bp[0] = tev.value;
        if (color == 0xFF) {
            colorSel = 7;
        } else {
            colorSel = lbl_80303C80[color];
        }
        tev.fields.color1 = colorSel;
        bp[0] = tev.value;
        texEnable = 0;
        if (texMap != 0xFF && !(texMap & 0x100)) {
            texEnable = 1;
        }
        tev.fields.enable1 = texEnable;
        bp[0] = tev.value;
    } else {
        tev.value = bp[0];
        tev.fields.map0 = mapSel;
        tev.fields.coord0 = texCoord;
        bp[0] = tev.value;
        if (color == 0xFF) {
            colorSel = 7;
        } else {
            colorSel = lbl_80303C80[color];
        }
        tev.fields.color0 = colorSel;
        bp[0] = tev.value;
        texEnable = 0;
        if (texMap != 0xFF && !(texMap & 0x100)) {
            texEnable = 1;
        }
        tev.fields.enable0 = texEnable;
        bp[0] = tev.value;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = bp[0];
    *(volatile unsigned short *)((char *)__GXData + 2) = 0;
    __GXData[0x5fc / 4] |= 1;
}

void GXSetNumTevStages(u8 count) {
    unsigned int dec = count - 1;
    unsigned int reg = __GXData[0x254 / 4];
    reg = __rlwimi(reg, dec, 10, 18, 21);
    __GXData[0x254 / 4] = reg;
    __GXData[0x5FC / 4] |= 4;
}

typedef u32 GXFogType;
void GXSetFog(int type, GXColor color, f32 start, f32 end, f32 near, f32 far) {
    f32 a, c;
    u32 a_bits, c_bits;

    u32 fogColorReg = 0;
    u32 fogParamReg0 = 0;
    u32 fogParamReg1 = 0;
    register u32 fogParamReg2 = 0;
    u32 fogParamReg3 = 0;

    u32 fsel = GX_FOG_GET_FSEL(type);
    int ortho = GX_FOG_GET_PROJ(type);

    if (ortho) {
        if (far == near || end == start) {
            a = 0.0f;
            c = 0.0f;
        } else {
            a = (1.0f / (end - start)) * (far - near);
            c = (1.0f / (end - start)) * (start - near);
        }
    } else {
        f32 f28, f25, f24;
        u32 expB, magB, shiftB;

        if (far == near || end == start) {
            f28 = 0.0f;
            f25 = 0.5f;
            f24 = 0.0f;
        } else {
            f28 = (far * near) / ((far - near) * (end - start));
            f25 = far / (far - near);
            f24 = start / (end - start);
        }

        expB = 0;
        while (f25 > 1.0l) {
            f25 /= 2.0f;
            ++expB;
        }
        while (f25 > 0.0f && f25 < 0.5l) {
            f25 *= 2.0f;
            expB--;
        }

        a = f28 / (1 << (u32)expB + 1);
        magB = 8388638.0f * f25;
        shiftB = expB + 1;
        c = f24;

        GX_BP_SET_FOGPARAM1_B_MAG(fogParamReg1, magB);
        GX_BP_SET_OPCODE(fogParamReg1, GX_BP_REG_FOGPARAM1);
        GX_BP_SET_FOGPARAM2_B_SHIFT(fogParamReg2, shiftB);
        GX_BP_SET_OPCODE(fogParamReg2, GX_BP_REG_FOGPARAM2);
    }

    a_bits = *(u32*)&a;
    c_bits = *(u32*)&c;

    GX_BP_SET_FOGPARAM0_A_MANT(fogParamReg0, a_bits >> 12 & 0x7FF);
    GX_BP_SET_FOGPARAM0_A_EXP(fogParamReg0, a_bits >> 23 & 0xFF);
    GX_BP_SET_FOGPARAM0_A_SIGN(fogParamReg0, a_bits >> 31);
    GX_BP_SET_OPCODE(fogParamReg0, GX_BP_REG_FOGPARAM0);

    GX_BP_SET_FOGPARAM3_C_MANT(fogParamReg3, c_bits >> 12 & 0x7FF);
    GX_BP_SET_FOGPARAM3_C_EXP(fogParamReg3, c_bits >> 23 & 0xFF);
    GX_BP_SET_FOGPARAM3_C_SIGN(fogParamReg3, c_bits >> 31);
    GX_BP_SET_FOGPARAM3_PROJ(fogParamReg3, ortho);
    GX_BP_SET_FOGPARAM3_FSEL(fogParamReg3, fsel);
    GX_BP_SET_OPCODE(fogParamReg3, GX_BP_REG_FOGPARAM3);

    GX_BP_SET_OPCODE(fogColorReg, GX_BP_REG_FOGCOLOR);
    GX_BP_SET_FOGCOLOR_RGB(fogColorReg, *(u32*)&color >> 8);

    GX_BP_LOAD_REG(fogParamReg0);
    GX_BP_LOAD_REG(fogParamReg1);
    GX_BP_LOAD_REG(fogParamReg2);
    GX_BP_LOAD_REG(fogParamReg3);
    GX_BP_LOAD_REG(fogColorReg);

    *(volatile u16 *)((u8 *)__GXData + 2) = 0;
}

void GXSetFogRangeAdj(int adjEnable, u16 center, const u16 *rangeAdjTable) {
    u32 fogRangeReg;
    u32 fogRangeKReg;
    s32 i;

    /* Set fog range adjustment table (BP 0xE9-0xED) and center/enable (BP 0xE8). */
    if (adjEnable) {
        for (i = 0; i < 10; i += 2) {
            fogRangeKReg = 0;
            fogRangeKReg = __rlwimi(fogRangeKReg, rangeAdjTable[i], 0, 20, 31);
            fogRangeKReg = __rlwimi(fogRangeKReg, rangeAdjTable[i + 1], 12, 8, 19);
            fogRangeKReg = __rlwimi(fogRangeKReg, 0xE9 + (i / 2), 24, 0, 7);
            *(volatile u8 *)0xCC008000 = 0x61;
            *(volatile u32 *)0xCC008000 = fogRangeKReg;
        }
    }
    fogRangeReg = 0;
    fogRangeReg = __rlwimi(fogRangeReg, center + 342, 0, 22, 31);
    fogRangeReg = __rlwimi(fogRangeReg, adjEnable, 10, 21, 21);
    fogRangeReg = __rlwimi(fogRangeReg, 0xE8, 24, 0, 7);
    *(volatile u8 *)0xCC008000 = 0x61;
    *(volatile u32 *)0xCC008000 = fogRangeReg;
    *(volatile u16 *)((u8 *)__GXData + 2) = 0;
}

void GXSetBlendMode(s32 type, s32 src, s32 dst, s32 op) {
    unsigned int *data = __GXData;
    unsigned int value = data[0x220 / 4];
    int b;
    value = __rlwimi(value, __cntlzw(type - 3), 6, 20, 20);
    b = __cntlzw(type - 2);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = __rlwimi(value, type, 0, 31, 31);
    value = __rlwimi(value, b, 28, 30, 30);
    value = __rlwimi(value, op, 12, 16, 19);
    value = __rlwimi(value, src, 8, 21, 23);
    value = __rlwimi(value, dst, 5, 24, 26);
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x220 / 4] = value;
    *(volatile unsigned short *)((unsigned char *)data + 2) = 0;
}

void GXSetColorUpdate(s32 enable) {
    union {
        unsigned int value;
        struct {
            unsigned int unused0 : 28;
            unsigned int colorUpdate : 1;
            unsigned int unused1 : 3;
        } bits;
    } reg;
    unsigned int *data = __GXData;
    reg.value = data[0x220 / 4];
    reg.bits.colorUpdate = enable;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = reg.value;
    data[0x220 / 4] = reg.value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetAlphaUpdate(s32 enable) {
    union {
        unsigned int value;
        struct {
            unsigned int unused0 : 27;
            unsigned int alphaUpdate : 1;
            unsigned int unused1 : 4;
        } bits;
    } reg;
    unsigned int *data = __GXData;
    reg.value = data[0x220 / 4];
    reg.bits.alphaUpdate = enable;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = reg.value;
    data[0x220 / 4] = reg.value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetZMode(s32 enable, s32 func, s32 update) {
    union {
        unsigned int value;
        struct {
            unsigned int unused : 27;
            unsigned int update : 1;
            unsigned int func : 3;
            unsigned int enable : 1;
        } bits;
    } reg;
    unsigned int *data = __GXData;

    reg.value = data[0x228 / 4];
    reg.bits.enable = enable;
    reg.bits.func = func;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    reg.bits.update = update;
    *(volatile unsigned int *)0xCC008000 = reg.value;
    data[0x228 / 4] = reg.value;
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetZCompLoc(s32 enable) {
    union {
        unsigned int value;
        struct {
            unsigned int unused0 : 25;
            unsigned int zCompLoc : 1;
            unsigned int unused1 : 6;
        } bits;
    } reg;
    unsigned int *data = __GXData;
    reg.value = data[0x22C / 4];
    reg.bits.zCompLoc = enable;
    data[0x22C / 4] = reg.value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x22C / 4];
    *(unsigned short *)((char *)data + 2) = 0;
}

extern u32 lbl_80303CA8[];
void GXSetPixelFmt(s32 pixelFmt, s32 zFmt) {
    /* Set the pixel format and Z format in GX state (PE control registers),
       update dirty state when changed, and configure destination alpha for
       formats whose mapped pixel-format table entry is 4. */
    unsigned int oldZControl;
    unsigned int zControlReg;
    unsigned int offset;
    unsigned int *gxRegs;
    unsigned int *pixelFormatTable;
    gxRegs = __GXData;
    pixelFormatTable = (unsigned int *)lbl_80303CA8;
    offset = (unsigned int)pixelFmt * 4;
    oldZControl = gxRegs[0x22C / 4];
    zControlReg = oldZControl;
    zControlReg = __rlwimi(zControlReg, pixelFormatTable[pixelFmt], 0, 29, 31);
    zControlReg = __rlwimi(zControlReg, zFmt, 3, 26, 28);
    gxRegs[0x22C / 4] = zControlReg;
    if (oldZControl != zControlReg) {
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = gxRegs[0x22C / 4];
        gxRegs[0x254 / 4] = __rlwimi(gxRegs[0x254 / 4], __cntlzw(pixelFmt - 2), 4, 22, 22);
        gxRegs[0x5FC / 4] |= 4;
    }
    if (pixelFormatTable[pixelFmt] == 4) {
        unsigned int dstAlpha = gxRegs[0x224 / 4];
        dstAlpha = __rlwimi(dstAlpha, pixelFmt - 4, 9, 21, 22);
        dstAlpha = __rlwimi(dstAlpha, 0x42, 24, 0, 7);
        gxRegs[0x224 / 4] = dstAlpha;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = gxRegs[0x224 / 4];
    }
    *(volatile u16 *)((u8 *)gxRegs + 2) = 0;
}

void GXSetDither(s32 enable) {
    union {
        unsigned int value;
        struct {
            unsigned int unused0 : 29;
            unsigned int dither : 1;
            unsigned int unused1 : 2;
        } bits;
    } reg;
    unsigned int *data = __GXData;
    reg.value = data[0x220 / 4];
    reg.bits.dither = enable;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = reg.value;
    data[0x220 / 4] = reg.value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetDstAlpha(s32 enable, s32 alpha) {
    union {
        unsigned int value;
        struct {
            unsigned int unused : 23;
            unsigned int enable : 1;
            unsigned int alpha : 8;
        } bits;
    } reg;
    unsigned int *data = __GXData;

    reg.value = data[0x224 / 4];
    reg.bits.alpha = alpha;
    reg.bits.enable = enable;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = reg.value;
    data[0x224 / 4] = reg.value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetFieldMask(s32 even, s32 odd) {
    unsigned int *data = __GXData;
    unsigned int value = 0;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = __rlwimi(value, odd, 0, 31, 31);
    value = __rlwimi(value, even, 1, 30, 30);
    value = __rlwimi(value, 0x44, 24, 0, 7);
    *(volatile unsigned int *)0xCC008000 = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetFieldMode(s32 mode, s32 field) {
    unsigned int *data = __GXData;
    unsigned int value = data[0x7C / 4];
    value = __rlwimi(value, field, 22, 9, 9);
    data[0x7C / 4] = value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x7C / 4];
    __GXFlushTextureState();
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = mode | 0x68000000;
    __GXFlushTextureState();
}

#pragma dont_inline on
#pragma use_lmw_stmw off
void GXBeginDisplayList(void *list, u32 size) {
    extern char lbl_8037C108[];
    extern void GXSetCPUFifo(void *);
    register unsigned char *base = (unsigned char *)lbl_8037C108;
    register unsigned char *fifo = base;
    register unsigned int *data = __GXData;
    register unsigned char *saveArea = base + 0x80;
    unsigned char *end;
    if (data[0x5FC / 4] != 0) {
        __GXSetDirtyState();
    }
    if (*(unsigned char *)((unsigned char *)data + 0x5F9) != 0) {
        memcpy(saveArea, data, 0x600);
    }
    end = (unsigned char *)list + size - 4;
    *(void **)(fifo + 0x0) = list;
    *(void **)(fifo + 0x4) = end;
    *(u32 *)(fifo + 0x8) = size;
    *(u32 *)(fifo + 0x1C) = 0;
    *(void **)(fifo + 0x14) = list;
    *(void **)(fifo + 0x18) = list;
    *((unsigned char *)data + 0x5F8) = 1;
    GXGetCPUFifo(base + 0x680);
    GXSetCPUFifo(fifo);
    GXGetVtxDescv();
}
#pragma use_lmw_stmw reset
#pragma dont_inline reset
extern void GXSetCPUFifo(void *);
extern char lbl_8037C108[];
#pragma optimize_for_size off
u32 GXEndDisplayList(void) {
    void *fifo = lbl_8037C108;
    u8 wrap;
    void *data;
    void *data2;
    int interruptState;
    unsigned int saved;
    GXGetCPUFifo((u8 *)fifo + 0);
    wrap = GXGetFifoWrap((u8 *)fifo + 0);
    GXSetCPUFifo((u8 *)fifo + 0x680);
    data = __GXData;
    if (*((u8 *)data + 0x5F9) != 0) {
        interruptState = OSDisableInterrupts();
        data2 = *(unsigned int * volatile *)&__GXData;
        saved = *(unsigned int *)((u8 *)data2 + 8);
        memcpy(data2, (u8 *)fifo + 0x80, 0x600);
        *(unsigned int *)((u8 *)data2 + 8) = saved;
        ((void (*)(int))OSRestoreInterrupts)(interruptState);
    }
    *((u8 *)data + 0x5F8) = 0;
    if (wrap == 0) {
        return GXGetFifoCount((u8 *)fifo + 0);
    }
    return 0;
}
#pragma optimize_for_size reset
void GXCallDisplayList(unsigned int arg0, unsigned int arg1) {
    volatile unsigned int *data = __GXData;
    unsigned int saved0 = arg0;
    unsigned int saved1 = arg1;
    if (data[0x5FC / 4] != 0) {
        __GXSetDirtyState();
    }
    if (data[0] == 0) {
        __GXSendFlushPrim();
    }
    *(volatile unsigned char *)0xCC008000 = 0x40;
    *(volatile unsigned int *)0xCC008000 = saved0;
    *(volatile unsigned int *)0xCC008000 = saved1;
}

extern float lbl_80560BC8;
extern float lbl_80560BCC;
extern float lbl_80560BD0;
#pragma push
#pragma paired on
#pragma paired_single on
void __GXSetProjection(void) {
    double *src = (double *)((u8 *)__GXData + 0x52C);
    volatile double *fifo = (volatile double *)0xCC008000;
    *(volatile u8 *)0xCC008000 = 0x10;
    *(volatile u32 *)0xCC008000 = 0x61020;
    fifo[0] = src[0];
    fifo[0] = src[1];
    fifo[0] = src[2];
    *(volatile u32 *)0xCC008000 = *(u32 *)((u8 *)__GXData + 0x528);
}
#pragma pop
void GXSetProjection(float *arg0, int arg1) {
    unsigned int *data = __GXData;
    register float fourth, third, second, first;
    register float perspectiveB, perspectiveA, orthographicB, orthographicA;

    first = arg0[0];
    data[0x528 / 4] = arg1;
    second = arg0[5];
    *(float *)((char *)data + 0x52C) = first;
    third = arg0[10];
    *(float *)((char *)data + 0x534) = second;
    fourth = arg0[11];
    *(float *)((char *)data + 0x53C) = third;
    *(float *)((char *)data + 0x540) = fourth;
    if (arg1 == 1) {
        perspectiveA = arg0[3];
        perspectiveB = arg0[7];
        *(float *)((char *)data + 0x530) = perspectiveA;
        *(float *)((char *)data + 0x538) = perspectiveB;
    } else {
        orthographicA = arg0[2];
        orthographicB = arg0[6];
        *(float *)((char *)data + 0x530) = orthographicA;
        *(float *)((char *)data + 0x538) = orthographicB;
    }
    data[0x5FC / 4] |= 0x08000000;
}

void GXSetProjectionv(float *arg0) {
    unsigned int *data = __GXData;
    int value = (lbl_80560BC8 != arg0[0]);
    data[0x528 / 4] = value;
    *(float *)((char *)data + 0x52C) = arg0[1];
    *(float *)((char *)data + 0x534) = arg0[2];
    *(float *)((char *)data + 0x53C) = arg0[4];
    data[0x5FC / 4] |= 0x08000000;
}

void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id) {
    volatile u8 *fifo8 = (volatile u8 *)0xCC008000;
    volatile u32 *fifo32 = (volatile u32 *)0xCC008000;
    volatile f64 *fifo64 = (volatile f64 *)0xCC008000;
    f64 p0 = *(const f64 *)&mtx[0][0];
    f64 p1 = *(const f64 *)&mtx[0][2];
    f64 p2 = *(const f64 *)&mtx[1][0];
    f64 p3 = *(const f64 *)&mtx[1][2];
    f64 p4 = *(const f64 *)&mtx[2][0];
    f64 p5 = *(const f64 *)&mtx[2][2];
    *fifo8 = 0x10;
    *fifo32 = (id << 2) | 0xB0000;
    *fifo64 = p0;
    *fifo64 = p1;
    *fifo64 = p2;
    *fifo64 = p3;
    *fifo64 = p4;
    *fifo64 = p5;
}

#pragma push
#pragma paired_single on
#pragma paired on
void GXLoadNrmMtxImm(const f32 mtx[3][4], u32 id) {
    f64 row0, row1, row2;
    f32 tail0, tail1, tail2;
    u32 cmd = 0;
    cmd |= (id << 2) - id + 0x400;
    cmd |= 8 << 16;
    *(volatile u8 *)0xCC008000 = 0x10;
    *(volatile u32 *)0xCC008000 = cmd;
    row0 = *(const volatile f64 *)&mtx[0][1];
    tail0 = *(const volatile f32 *)&mtx[0][2];
    row1 = *(const volatile f64 *)&mtx[1][1];
    tail1 = *(const volatile f32 *)&mtx[1][2];
    row2 = *(const volatile f64 *)&mtx[2][1];
    tail2 = *(const volatile f32 *)&mtx[2][2];
    *(volatile f64 *)0xCC008000 = row0;
    *(volatile f32 *)0xCC008000 = tail0;
    *(volatile f64 *)0xCC008000 = row1;
    *(volatile f32 *)0xCC008000 = tail1;
    *(volatile f64 *)0xCC008000 = row2;
    *(volatile f32 *)0xCC008000 = tail2;
}
#pragma pop

/* Assign through the register's low-six-bit field to match rlwimi directly. */
void GXSetCurrentMtx(s32 arg0) {
    struct {
        unsigned int unused : 26;
        unsigned int matrix : 6;
    } *reg = (void *)&__GXData[0x20];
    reg->matrix = arg0;
    __GXData[0x17F] |= 0x04000000;
}

void GXLoadTexMtxImm(const f32 *mtx, u32 id, s32 type) {
    u32 addr;
    u32 num;
    const f64 *src = (const f64 *)mtx;
    volatile f64 *fifo = (volatile f64 *)0xCC008000;

    addr = id >= 0x40 ? (id - 0x40) * sizeof(f32) + 0x500 : id * 4 + (u64)0;
    num = type == 1 ? (u64)(2 * 4) : 3 * 4;
    *(volatile unsigned char *)0xCC008000 = 0x10;
    *(volatile unsigned int *)0xCC008000 = ((num - 1) << 16) | addr;

    if (type == 0) {
        f64 f5 = src[0];
        f64 f4 = src[1];
        f64 f3 = src[2];
        f64 f2 = src[3];
        f64 f1 = src[4];
        f64 f0 = src[5];
        fifo[0] = f5;
        fifo[0] = f4;
        fifo[0] = f3;
        fifo[0] = f2;
        fifo[0] = f1;
        fifo[0] = f0;
    } else {
        f64 f3 = src[0];
        f64 f2 = src[1];
        f64 f1 = src[2];
        f64 f0 = src[3];
        fifo[0] = f3;
        fifo[0] = f2;
        fifo[0] = f1;
        fifo[0] = f0;
    }
}

void __GXSetViewport(void) {
    unsigned int *d = __GXData;
    register f32 f9, f8, f5, f4, f7, f0, f1, f3, f2, f6;
    volatile u8 *bp8 = (volatile u8 *)0xCC008000;
    volatile u32 *bp32 = (volatile u32 *)0xCC008000;
    volatile f32 *bpf = (volatile f32 *)0xCC008000;

    f6 = lbl_80560BCC;
    f2 = *(f32 *)((u8 *)d + 0x550);
    f3 = *(f32 *)((u8 *)d + 0x54C);
    f1 = -f2;
    f0 = *(f32 *)((u8 *)d + 0x544);
    f7 = f3 * f6;
    f4 = *(f32 *)((u8 *)d + 0x548);
    f5 = f2 * f6;
    f3 = *(f32 *)((u8 *)d + 0x554);
    f8 = f1 * f6;
    f2 = *(f32 *)((u8 *)d + 0x560);
    f1 = *(f32 *)((u8 *)d + 0x558);
    f6 = f0 + f7;
    f0 = *(f32 *)((u8 *)d + 0x55C);
    f3 = f3 * f2;
    f9 = f1 * f2;
    *bp8 = 16;
    f2 = lbl_80560BD0;
    f1 = f4 + f5;
    *bp32 = 0x5101A;
    f3 = f9 - f3;
    *bpf = f7;
    f4 = f2 + f6;
    f1 = f2 + f1;
    *bpf = f8;
    f0 = f9 + f0;
    *bpf = f3;
    *bpf = f4;
    *bpf = f1;
    *bpf = f0;
}

void GXSetViewportJitter(s32 arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    extern f32 lbl_80560BCC;
    if (arg0 == 0) {
        farg1 -= lbl_80560BCC;
    }
    ((f32 *)__GXData)[0x544 / 4] = farg0;
    ((f32 *)__GXData)[0x548 / 4] = farg1;
    ((f32 *)__GXData)[0x54C / 4] = farg2;
    ((f32 *)__GXData)[0x550 / 4] = farg3;
    ((f32 *)__GXData)[0x554 / 4] = farg4;
    ((f32 *)__GXData)[0x558 / 4] = farg5;
    __GXData[0x5FC / 4] |= 0x10000000;
}

void GXSetViewport(f32 xOrig, f32 yOrig, f32 width, f32 height, f32 nearZ, f32 farZ) {
    ((f32 *)__GXData)[0x544 / 4] = xOrig;
    ((f32 *)__GXData)[0x548 / 4] = yOrig;
    ((f32 *)__GXData)[0x54C / 4] = width;
    ((f32 *)__GXData)[0x550 / 4] = height;
    ((f32 *)__GXData)[0x554 / 4] = nearZ;
    ((f32 *)__GXData)[0x558 / 4] = farZ;
    __GXData[0x5FC / 4] |= 0x10000000;
}

void GXSetScissor(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    unsigned int *data = __GXData;
    s32 left = arg0 + 0x156;
    s32 top = arg1 + 0x156;
    s32 tmpBottom = top + arg3;
    s32 tmpRight = left + arg2;
    s32 bottom = tmpBottom - 1;
    s32 right = tmpRight - 1;
    unsigned int tl;
    unsigned int br;
    tl = data[0x148 / 4];
    tl = __rlwimi(tl, top, 0, 21, 31);
    tl = __rlwimi(tl, left, 12, 9, 19);
    data[0x148 / 4] = tl;
    br = data[0x14C / 4];
    br = __rlwimi(br, bottom, 0, 21, 31);
    br = __rlwimi(br, right, 12, 9, 19);
    data[0x14C / 4] = br;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x148 / 4];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x14C / 4];
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetScissorBoxOffset(s32 x, s32 y) { union { u32 value; struct { unsigned int tag : 8; unsigned int reserved : 4; unsigned int y : 10; unsigned int x : 10; } bits; } reg; reg.value = 0; reg.bits.x = ((u32)(x + 0x156)) >> 1; *(volatile u8 *)0xCC008000 = 0x61; reg.bits.y = ((u32)(y + 0x156)) >> 1; reg.bits.tag = 0x59; *(volatile u32 *)0xCC008000 = reg.value; *(volatile u16 *)((u8 *)__GXData + 2) = 0; }

void GXSetClipMode(s32 arg0) {
    register volatile unsigned char *fifo = (volatile unsigned char *)0xCC008000;
    *fifo = 0x10;
    *(volatile unsigned int *)fifo = 0x1005;
    *(volatile unsigned int *)fifo = arg0;
    *(unsigned short *)((char *)__GXData + 2) = 1;
}

void __GXSetMatrixIndex(s32 arg0) {
    unsigned int *data;
    if (arg0 < 5) {
        *(volatile unsigned char *)0xCC008000 = 8;
        *(volatile unsigned char *)0xCC008000 = 0x30;
        data = __GXData;
        *(volatile unsigned int *)0xCC008000 = data[0x80 / 4];
        *(volatile unsigned char *)0xCC008000 = 0x10;
        *(volatile unsigned int *)0xCC008000 = 0x1018;
        *(volatile unsigned int *)0xCC008000 = data[0x80 / 4];
    } else {
        *(volatile unsigned char *)0xCC008000 = 8;
        *(volatile unsigned char *)0xCC008000 = 0x40;
        data = __GXData;
        *(volatile unsigned int *)0xCC008000 = data[0x84 / 4];
        *(volatile unsigned char *)0xCC008000 = 0x10;
        *(volatile unsigned int *)0xCC008000 = 0x1019;
        *(volatile unsigned int *)0xCC008000 = data[0x84 / 4];
    }
    *(unsigned short *)((char *)data + 2) = 1;
}

void GXSetGPMetric(unsigned int metric1, unsigned int metric2) {
    unsigned int *data = __GXData;
    int old1 = data[0x5EC / 4];
    if (old1 == 0x22) goto doA;
    if (old1 >= 0x22) goto end1;
    if (old1 >= 0xB) goto checkB1;
    if (old1 >= 0) goto doA;
    goto end1;
checkB1:
    if (old1 >= 0x1B) goto doB2;
    goto doB1;
doA:
    WGPIPE.c = 0x10;
    WGPIPE.i = 0x1006;
    WGPIPE.i = 0;
    goto end1;
doB1:
    WGPIPE.c = 0x61;
    WGPIPE.i = 0x23000000;
    goto end1;
doB2:
    WGPIPE.c = 0x61;
    WGPIPE.i = 0x24000000;
end1:;
    {
        int old2 = data[0x5F0 / 4];
        if (old2 == 0x15) goto doC;
        if (old2 >= 0x15) goto end2;
        if (old2 >= 9) goto checkD;
        if (old2 >= 0) goto doC;
        goto end2;
checkD:
        if (old2 >= 0x11) goto doCP;
        goto doD;
doC:
        WGPIPE.c = 0x61;
        WGPIPE.i = 0x67000000;
        goto end2;
doD:
        data[0x5F4 / 4] &= 0xFFFFFF0F;
        WGPIPE.c = 8;
        WGPIPE.c = 0x20;
        WGPIPE.i = data[0x5F4 / 4];
        goto end2;
doCP:
        __cpReg[3] = 0;
end2:;
    }
    data[0x5EC / 4] = metric1;
    switch (metric1) {
    case 0:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x273; break;
    case 1:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x14A; break;
    case 2:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x16B; break;
    case 3:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x84; break;
    case 4:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0xC6; break;
    case 5:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x210; break;
    case 6:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x252; break;
    case 7:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x231; break;
    case 8:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x1AD; break;
    case 9:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x1CE; break;
    case 34:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x21; break;
    case 10:
        WGPIPE.c = 0x10; WGPIPE.i = 0x1006; WGPIPE.i = 0x153; break;
    case 11:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300AE7F; break;
    case 12:
        WGPIPE.c = 0x61; WGPIPE.i = 0x23008E7F; break;
    case 13:
        WGPIPE.c = 0x61; WGPIPE.i = 0x23009E7F; break;
    case 14:
        WGPIPE.c = 0x61; WGPIPE.i = 0x23001E7F; break;
    case 15:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300AC3F; break;
    case 16:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300AC7F; break;
    case 17:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300ACBF; break;
    case 18:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300ACFF; break;
    case 19:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300AD3F; break;
    case 20:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300AD7F; break;
    case 21:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300ADBF; break;
    case 22:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300ADFF; break;
    case 23:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300AE3F; break;
    case 24:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300A27F; break;
    case 25:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300A67F; break;
    case 26:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2300AA7F; break;
    case 27:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2402C0C6; break;
    case 28:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2402C16B; break;
    case 29:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2402C0E7; break;
    case 30:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2402C108; break;
    case 31:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2402C129; break;
    case 32:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2402C14A; break;
    case 33:
        WGPIPE.c = 0x61; WGPIPE.i = 0x2402C1AD; break;
    case 35:
        break;
    }
    data[0x5F0 / 4] = metric2;
    switch (metric2) {
    case 0:
        WGPIPE.c = 0x61; WGPIPE.i = 0x67000042; break;
    case 1:
        WGPIPE.c = 0x61; WGPIPE.i = 0x67000084; break;
    case 2:
        WGPIPE.c = 0x61; WGPIPE.i = 0x67000063; break;
    case 3:
        WGPIPE.c = 0x61; WGPIPE.i = 0x67000129; break;
    case 8:
        WGPIPE.c = 0x61; WGPIPE.i = 0x67000252; break;
    case 21:
        WGPIPE.c = 0x61; WGPIPE.i = 0x67000021; break;
    case 4:
        WGPIPE.c = 0x61; WGPIPE.i = 0x6700014B; break;
    case 5:
        WGPIPE.c = 0x61; WGPIPE.i = 0x6700018D; break;
    case 6:
        WGPIPE.c = 0x61; WGPIPE.i = 0x670001CF; break;
    case 7:
        WGPIPE.c = 0x61; WGPIPE.i = 0x67000211; break;
    case 9:
        data[0x5F4 / 4] = GX_BITSET(data[0x5F4 / 4], 24, 4, 2); WGPIPE.c = 8; WGPIPE.c = 0x20; WGPIPE.i = data[0x5F4 / 4]; break;
    case 10:
        data[0x5F4 / 4] = GX_BITSET(data[0x5F4 / 4], 24, 4, 3); WGPIPE.c = 8; WGPIPE.c = 0x20; WGPIPE.i = data[0x5F4 / 4]; break;
    case 11:
        data[0x5F4 / 4] = GX_BITSET(data[0x5F4 / 4], 24, 4, 4); WGPIPE.c = 8; WGPIPE.c = 0x20; WGPIPE.i = data[0x5F4 / 4]; break;
    case 12:
        data[0x5F4 / 4] = GX_BITSET(data[0x5F4 / 4], 24, 4, 5); WGPIPE.c = 8; WGPIPE.c = 0x20; WGPIPE.i = data[0x5F4 / 4]; break;
    case 13:
        data[0x5F4 / 4] = GX_BITSET(data[0x5F4 / 4], 24, 4, 6); WGPIPE.c = 8; WGPIPE.c = 0x20; WGPIPE.i = data[0x5F4 / 4]; break;
    case 14:
        data[0x5F4 / 4] = GX_BITSET(data[0x5F4 / 4], 24, 4, 7); WGPIPE.c = 8; WGPIPE.c = 0x20; WGPIPE.i = data[0x5F4 / 4]; break;
    case 15:
        data[0x5F4 / 4] = GX_BITSET(data[0x5F4 / 4], 24, 4, 9); WGPIPE.c = 8; WGPIPE.c = 0x20; WGPIPE.i = data[0x5F4 / 4]; break;
    case 16:
        data[0x5F4 / 4] = GX_BITSET(data[0x5F4 / 4], 24, 4, 8); WGPIPE.c = 8; WGPIPE.c = 0x20; WGPIPE.i = data[0x5F4 / 4]; break;
    case 17:
        __cpReg[3] = 2; break;
    case 18:
        __cpReg[3] = 3; break;
    case 19:
        __cpReg[3] = 4; break;
    case 20:
        __cpReg[3] = 5; break;
    case 22:
        break;
    }
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXClearGPMetric(void) {
    __cpReg[2] = 4;
}

/* CP (GX command processor) registers: the four GP metric counters that
 * GXClearGPMetric() clears above. Each counter is 32 bits held in a low and a
 * high 16-bit register. */
#define CP_GP_COUNT0_LO (0x40 / 2)
#define CP_GP_COUNT0_HI (0x42 / 2)
#define CP_GP_COUNT1_LO (0x44 / 2)
#define CP_GP_COUNT1_HI (0x46 / 2)
#define CP_GP_COUNT2_LO (0x48 / 2)
#define CP_GP_COUNT2_HI (0x4A / 2)
#define CP_GP_COUNT3_LO (0x4C / 2)
#define CP_GP_COUNT3_HI (0x4E / 2)

/* Reads the four GX GP metric counters out of the CP registers. Each counter is
 * a 32-bit count held in two 16-bit registers, so the high half is read again
 * after the low half and the pair is only taken once two reads of the high
 * half agree - the count cannot be torn by a carry between the two reads.
 * The counters come back rotated: count0/count1 get CP counters 2 and 3,
 * count2/count3 get CP counters 0 and 1.
 * REXE01's symbol table names this KPADSetBtnRepeat, but it is GX code: the
 * neighbour above, GXClearGPMetric, is what clears these counters. */
void KPADSetBtnRepeat(u32 *count0, u32 *count1, u32 *count2, u32 *count3) {
    {
        unsigned int low, previous, high;
        volatile unsigned short *cp = __cpReg;
        high = cp[CP_GP_COUNT0_HI];
        for (;;) {
            previous = high;
            low = cp[CP_GP_COUNT0_LO];
            high = cp[CP_GP_COUNT0_HI];
            if (high == previous) break;
        }
        *count2 = (high << 16) | low;
    }
    {
        unsigned int low, previous, high;
        volatile unsigned short *cp = __cpReg;
        high = cp[CP_GP_COUNT1_HI];
        for (;;) {
            previous = high;
            low = cp[CP_GP_COUNT1_LO];
            high = cp[CP_GP_COUNT1_HI];
            if (high == previous) break;
        }
        *count3 = (high << 16) | low;
    }
    {
        unsigned int low, previous, high;
        volatile unsigned short *cp = __cpReg;
        high = cp[CP_GP_COUNT2_HI];
        for (;;) {
            previous = high;
            low = cp[CP_GP_COUNT2_LO];
            high = cp[CP_GP_COUNT2_HI];
            if (high == previous) break;
        }
        *count0 = (high << 16) | low;
    }
    {
        unsigned int low, previous, high;
        volatile unsigned short *cp = __cpReg;
        high = cp[CP_GP_COUNT3_HI];
        for (;;) {
            previous = high;
            low = cp[CP_GP_COUNT3_LO];
            high = cp[CP_GP_COUNT3_HI];
            if (high == previous) break;
        }
        *count1 = (high << 16) | low;
    }
}
typedef struct { unsigned int unk[9]; unsigned char unk24[3]; } GXSetCPUFifoObj;
