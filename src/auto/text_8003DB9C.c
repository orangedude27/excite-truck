// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void __GXSetDirtyState(void);
extern void __GXFlushTextureState(void);
extern void GXCPInterruptHandler(short, void *);
typedef void (*GXFifoIntrHandler)(short, void *);
extern void *OSGetCurrentThread(void);
extern void OSSleepThread(void *);
extern void memset(void *, int, unsigned int);
extern unsigned int lbl_8055D958;
extern void *lbl_8055D95C;
extern unsigned char lbl_80558E80;
extern int __cntlzw(unsigned int);
extern unsigned int lbl_8055D954;
extern unsigned int lbl_8055D950;
extern unsigned char lbl_8055D948;
extern unsigned int * const __GXData;
extern unsigned int lbl_8055D968;
extern unsigned char lbl_8055D970;
extern unsigned short *__cpReg;
extern unsigned short *__peReg;
extern unsigned char lbl_8037C0C0[];
extern unsigned char lbl_8037C0E4[];
extern unsigned int *__piReg;

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
extern u32 __cvt_fp2unsigned(f32);
  extern void GXGetVtxDesc(void);
  extern void __GXSaveFifo(void);

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
void *__GXDefaultTexRegionCallback(void *obj, unsigned int region) {
    int mipmap;
    int isMipMap;
    unsigned int shifted;
    unsigned int carry;

    mipmap = GXGetTexObjMipMap(obj);
    isMipMap = GXGetTexObjAll(obj);
    shifted = region << 29;
    carry = region >> 31;
    shifted -= carry;
    region = (unsigned int)((int)((shifted << 3) | (shifted >> 29)) - -(int)carry);

    switch (mipmap) {
    case 6:
        if ((unsigned char)isMipMap != 0) {
            return (char *)__GXData + region * 16 + 0x358;
        }
        return (char *)__GXData + region * 16 + 0x2D8;
    case 8:
    case 9:
    case 10:
        return (char *)__GXData + region * 16 + 0x258;
    default:
        if ((unsigned char)isMipMap != 0) {
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

void __GXInitRevisionBits(void) {
    unsigned int *p = __GXData;
    volatile unsigned char *b = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *w = (volatile unsigned int *)0xCC008000;
    unsigned int v;
    *p = *p;
    v = p[7] | 0x40000000; p[7] = v;
    v = p[15] | 0x80000000; p[15] = v; *b = 8; *b = 0x80; *w = v;
    v = p[8] | 0x40000000; p[8] = v;
    v = p[16] | 0x80000000; p[16] = v; *b = 8; *b = 0x81; *w = v;
    v = p[9] | 0x40000000; p[9] = v;
    v = p[17] | 0x80000000; p[17] = v; *b = 8; *b = 0x82; *w = v;
    v = p[10] | 0x40000000; p[10] = v;
    v = p[18] | 0x80000000; p[18] = v; *b = 8; *b = 0x83;
    *w = v;
    *b = 0x10; *w = 0x1000; *w = 0x3F;
    *b = 0x10; *w = 0x1012; *w = 1; *b = 0x61; *w = 0x5800000F;
}

void GXInitFifoBase(void *arg0, void *arg1, u32 arg2) {
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
    struct Fifo *fifo = (struct Fifo *)arg0;
    s32 temp_r6 = (s32)arg2 - 0x4000;
    s32 temp_r7 = (s32)((u32)arg1 + arg2) - 4;
    s32 temp_r0 = (arg2 >> 1) & 0x7FFFFFE0;
    s32 zero = 0;

    fifo->base = (u8 *)arg1;
    fifo->top = (u8 *)temp_r7;
    fifo->size = arg2;
    fifo->count = zero;
    fifo->hi = temp_r6;
    fifo->lo = temp_r0;
    OSDisableInterrupts();
    fifo->rd = arg1;
    fifo->wr = arg1;
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
    int error = 0;
    unsigned int first;
    unsigned int second;
    int diff1;
    int diff2;

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
    if ((unsigned int)error == 2) {
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

void GXSetGPFifo(unsigned int *fifo) {
    int intStatus;
    unsigned int tmp;
    unsigned int *gx = (unsigned int *)lbl_8037C0C0;
    unsigned int *gd = __GXData;

    intStatus = OSDisableInterrupts();

    tmp = gd[2] & ~1u;
    gd[2] = tmp;
    __cpReg[1] = (unsigned short)tmp;
    tmp = gd[2] & 0xFFFFFFF3u;
    gd[2] = tmp;
    __cpReg[1] = (unsigned short)tmp;

    if (fifo == 0) {
        lbl_8055D949 = 0;
        lbl_8055D960 = 0;
        tmp = gd[2] & 0xFFFFFFEFu;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
        *((unsigned char *)gx + 0x21) = 0;
        *((unsigned char *)gx + 0x22) = 0;
        ((void (*)(int))OSRestoreInterrupts)(intStatus);
        return;
    }

    gx[0] = fifo[0];
    gx[1] = fifo[1];
    gx[2] = fifo[2];
    gx[3] = fifo[3];
    gx[4] = fifo[4];
    gx[5] = fifo[5];
    gx[6] = fifo[6];
    gx[7] = fifo[7];
    gx[8] = fifo[8];
    lbl_8055D949 = 1;
    *((unsigned char *)gx + 0x22) = 1;

    __cpReg[0x20 / 2] = (unsigned short)gx[0];
    __cpReg[0x24 / 2] = (unsigned short)gx[1];
    __cpReg[0x30 / 2] = (unsigned short)gx[7];
    __cpReg[0x34 / 2] = (unsigned short)gx[6];
    __cpReg[0x38 / 2] = (unsigned short)gx[5];
    __cpReg[0x28 / 2] = (unsigned short)gx[3];
    __cpReg[0x2C / 2] = (unsigned short)gx[4];
    __cpReg[0x22 / 2] = (unsigned short)((gx[0] >> 16) & 0x3FFF);
    __cpReg[0x26 / 2] = (unsigned short)((gx[1] >> 16) & 0x3FFF);
    __cpReg[0x32 / 2] = (unsigned short)((int)gx[7] >> 16);
    __cpReg[0x36 / 2] = (unsigned short)((gx[6] >> 16) & 0x3FFF);
    __cpReg[0x3A / 2] = (unsigned short)((gx[5] >> 16) & 0x3FFF);
    __cpReg[0x2A / 2] = (unsigned short)(gx[3] >> 16);
    __cpReg[0x2E / 2] = (unsigned short)(gx[4] >> 16);

    PPCSync();

    if ((CPGPLinkCheck() & 0xFF) != 0) {
        lbl_8055D960 = 1;
        *((unsigned char *)gx + 0x21) = 1;
        tmp = (gd[2] | 4u) & 0xFFFFFFF7u;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
        tmp = gd[2] | 0x10u;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
    } else {
        lbl_8055D960 = 0;
        *((unsigned char *)gx + 0x21) = 0;
        tmp = gd[2] & 0xFFFFFFF3u;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
        tmp = gd[2] & 0xFFFFFFEFu;
        gd[2] = tmp;
        __cpReg[1] = (unsigned short)tmp;
    }

    __cpReg[1] = (unsigned short)(gd[2] & 0xFFFFFFFDu & 0xFFFFFFDFu);
    __cpReg[1] = (unsigned short)gd[2];
    tmp = gd[4] | 3u;
    gd[4] = tmp;
    __cpReg[2] = (unsigned short)tmp;
    tmp = gd[2] | 1u;
    gd[2] = tmp;
    __cpReg[1] = (unsigned short)tmp;
    ((void (*)(int))OSRestoreInterrupts)(intStatus);
}

void __GXSaveFifo(void) {
    s32 level;
    unsigned char hasCPUFifo;

    level = OSDisableInterrupts();
    hasCPUFifo = lbl_8055D948;
    if (hasCPUFifo) {
        GXFifoObjInternal *fifo = (GXFifoObjInternal *)lbl_8037C0E4;
        u32 reg = __piReg[5];
        fifo->wrPtr = (void *)((reg & 0x1FFFFFE0) + 0x80000000);
        fifo->wrap = (reg >> 29) & 1;
    }
    if (*(unsigned char *)&lbl_8055D949 != 0) {
        GXFifoObjInternal *fifo = (GXFifoObjInternal *)lbl_8037C0C0;
        unsigned short *cp = __cpReg;
        fifo->rdPtr = (void *)((((unsigned int)cp[0x3A / 2] << 16) | cp[0x38 / 2]) + 0x80000000);
        fifo->count = ((unsigned int)cp[0x32 / 2] << 16) | cp[0x30 / 2];
    }
    if (*(unsigned char *)&lbl_8055D960 != 0) {
        (*(GXFifoObjInternal *)lbl_8037C0E4).rdPtr = (*(GXFifoObjInternal *)lbl_8037C0C0).rdPtr;
        (*(GXFifoObjInternal *)lbl_8037C0E4).count = (*(GXFifoObjInternal *)lbl_8037C0C0).count;
        (*(GXFifoObjInternal *)lbl_8037C0C0).wrPtr = (*(GXFifoObjInternal *)lbl_8037C0E4).wrPtr;
        (*(GXFifoObjInternal *)lbl_8037C0C0).wrap = (*(GXFifoObjInternal *)lbl_8037C0E4).wrap;
    } else if (hasCPUFifo) {
        int count = (char *)(*(GXFifoObjInternal *)lbl_8037C0E4).wrPtr - (char *)(*(GXFifoObjInternal *)lbl_8037C0E4).rdPtr;
        (*(GXFifoObjInternal *)lbl_8037C0E4).count = count;
        if (count < 0) {
            (*(GXFifoObjInternal *)lbl_8037C0E4).count = count + (*(GXFifoObjInternal *)lbl_8037C0E4).size;
        }
    }
    ((void (*)(s32))OSRestoreInterrupts)(level);
}

char __GXIsGPFifoReady(void) {
    return lbl_8055D949;
}

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

typedef struct { unsigned int mode0; unsigned int mode1; } __GXTexObjInt;
static unsigned char GX2HWFiltConv[6] = { 0x00, 0x04, 0x01, 0x05, 0x02, 0x06 };
#pragma dont_inline on
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

void GXEnableBreakPt(u32 address) {
    s32 interruptState = OSDisableInterrupts();
    s32 value;
    s32 cleared;
    u32 addressField;
    unsigned char *data;

    data = (unsigned char *)__GXData;
    addressField = (address >> 16) & 0x3FFF;
    value = *(u32 *)(data + 8);
    cleared = __rlwinm(value, 0, 0, 30);
    *(u32 *)(data + 8) = cleared;
    *(volatile s16 *)((u8 *)__cpReg + 2) = (s16)cleared;
    *(volatile s16 *)((u8 *)__cpReg + 0x3C) = (s16)address;
    *(volatile s16 *)((u8 *)__cpReg + 0x3E) = (s16)addressField;

    value = *(u32 *)(data + 8);
    value = __rlwinm(value, 0, 31, 29);
    cleared = __rlwinm(value, 0, 27, 25);
    *(u32 *)(data + 8) = cleared;
    *(volatile s16 *)((u8 *)__cpReg + 2) = (s16)cleared;

    value = *(u32 *)(data + 8) | 0x22;
    *(u32 *)(data + 8) = value;
    *(volatile s16 *)((u8 *)__cpReg + 2) = (s16)value;

    lbl_8055D950 = address;
    value = *(u32 *)(data + 8) | 1;
    *(u32 *)(data + 8) = value;
    *(volatile s16 *)((u8 *)__cpReg + 2) = (s16)value;

    ((void (*)(s32))OSRestoreInterrupts)(interruptState);
}

void GXDisableBreakPt(void) {
    unsigned char *data;
    unsigned int value;
    unsigned int cleared;
    OSDisableInterrupts();
    data = (unsigned char *)__GXData;
    value = *(unsigned int *)(data + 8);
    value = __rlwinm(value, 0, 31, 29);
    cleared = __rlwinm(value, 0, 27, 25);
    *(unsigned int *)(data + 8) = cleared;
    *(unsigned short *)((char *)__cpReg + 2) = (unsigned short)cleared;
    lbl_8055D950 = 0;
    OSRestoreInterrupts();
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

void GXSetVtxDesc(unsigned int attr, unsigned int type) {
    unsigned int *data;
    data = __GXData;
    switch (attr) {
    case 0: data[5] = (data[5] & 0x7fffffff) | (type & 1) << 31; break;
    case 1: data[5] = (data[5] & 0xbfffffff) | (type & 1) << 30; break;
    case 2: data[5] = (data[5] & 0xdfffffff) | (type & 1) << 29; break;
    case 3: data[5] = (data[5] & 0xefffffff) | (type & 1) << 28; break;
    case 4: data[5] = (data[5] & 0xf7ffffff) | (type & 1) << 27; break;
    case 5: data[5] = (data[5] & 0xfbffffff) | (type & 1) << 26; break;
    case 6: data[5] = (data[5] & 0xfdffffff) | (type & 1) << 25; break;
    case 7: data[5] = (data[5] & 0xfeffffff) | (type & 1) << 24; break;
    case 8: data[5] = (data[5] & 0xff7fffff) | (type & 1) << 23; break;
    case 9: data[5] = (data[5] & 0xff9fffff) | (type & 3) << 21; break;
    case 10:
        if (type) { ((unsigned char *)data)[0x524] = 1; ((unsigned char *)data)[0x525] = 0; data[0x520 / 4] = type; }
        else ((unsigned char *)data)[0x524] = 0;
        break;
    case 11:
        if (type) { ((unsigned char *)data)[0x525] = 1; ((unsigned char *)data)[0x524] = 0; data[0x520 / 4] = type; }
        else ((unsigned char *)data)[0x525] = 0;
        break;
    case 12: data[5] = (data[5] & 0xfff9ffff) | (type & 3) << 17; break;
    case 13: data[5] = (data[5] & 0xfffe7fff) | (type & 3) << 15; break;
    case 14: data[6] = (data[6] & 0x3fffffff) | (type & 3) << 30; break;
    case 15: data[6] = (data[6] & 0xcfffffff) | (type & 3) << 28; break;
    case 16: data[6] = (data[6] & 0xf3ffffff) | (type & 3) << 26; break;
    case 17: data[6] = (data[6] & 0xfcffffff) | (type & 3) << 24; break;
    case 18: data[6] = (data[6] & 0xff3fffff) | (type & 3) << 22; break;
    case 19: data[6] = (data[6] & 0xffcfffff) | (type & 3) << 20; break;
    case 20: data[6] = (data[6] & 0xfff3ffff) | (type & 3) << 18; break;
    case 21: data[6] = (data[6] & 0xfffcffff) | (type & 3) << 16; break;
    case 22: data[6] = (data[6] & 0xfff3ffff) | (type & 3) << 14; break;
    case 23: data[6] = (data[6] & 0xfffcffff) | (type & 3) << 12; break;
    case 24: data[6] = (data[6] & 0xfff3ffff) | (type & 3) << 10; break;
    case 25: data[6] = (data[6] & 0xfffcffff) | (type & 3) << 8; break;
    }
    if (((unsigned char *)data)[0x524] == 0 && ((unsigned char *)data)[0x525] != 0) {
        data[5] = (data[5] & 0xfff1ffff) | (data[0x520 / 4] & 3) << 11;
    } else if (((unsigned char *)data)[0x524] == 0) {
        data[5] &= 0xfff1ffff;
    }
    data[0x5fc / 4] |= 8;
}

void GXSetVtxDescv(unsigned int *desc) {
    unsigned int *data = __GXData;
    unsigned int attr;
    unsigned int type;
    for (;;) {
        attr = desc[0]; type = desc[1];
        if (attr == 0xff) break;
        switch (attr) {
        case 0: data[5] = (data[5] & 0x7fffffff) | (type & 1) << 31; break;
        case 1: data[5] = (data[5] & 0xbfffffff) | (type & 1) << 30; break;
        case 2: data[5] = (data[5] & 0xdfffffff) | (type & 1) << 29; break;
        case 3: data[5] = (data[5] & 0xefffffff) | (type & 1) << 28; break;
        case 4: data[5] = (data[5] & 0xf7ffffff) | (type & 1) << 27; break;
        case 5: data[5] = (data[5] & 0xfbffffff) | (type & 1) << 26; break;
        case 6: data[5] = (data[5] & 0xfdffffff) | (type & 1) << 25; break;
        case 7: data[5] = (data[5] & 0xfeffffff) | (type & 1) << 24; break;
        case 8: data[5] = (data[5] & 0xff7fffff) | (type & 1) << 23; break;
        case 9: data[5] = (data[5] & 0xff9fffff) | (type & 3) << 21; break;
        case 10: if (type) { ((unsigned char *)data)[0x524]=1; ((unsigned char *)data)[0x525]=0; data[0x520/4]=type; } else ((unsigned char *)data)[0x524]=0; break;
        case 11: if (type) { ((unsigned char *)data)[0x525]=1; ((unsigned char *)data)[0x524]=0; data[0x520/4]=type; } else ((unsigned char *)data)[0x525]=0; break;
        case 12: data[5] = (data[5] & 0xfff9ffff) | (type & 3) << 17; break;
        case 13: data[5] = (data[5] & 0xfffe7fff) | (type & 3) << 15; break;
        case 14: data[6] = (data[6] & 0x3fffffff) | (type & 3) << 30; break;
        case 15: data[6] = (data[6] & 0xcfffffff) | (type & 3) << 28; break;
        case 16: data[6] = (data[6] & 0xf3ffffff) | (type & 3) << 26; break;
        case 17: data[6] = (data[6] & 0xfcffffff) | (type & 3) << 24; break;
        case 18: data[6] = (data[6] & 0xff3fffff) | (type & 3) << 22; break;
        case 19: data[6] = (data[6] & 0xffcfffff) | (type & 3) << 20; break;
        case 20: data[6] = (data[6] & 0xfff3ffff) | (type & 3) << 18; break;
        case 21: data[6] = (data[6] & 0xfffcffff) | (type & 3) << 16; break;
        }
        desc += 2;
    }
    if (!((unsigned char *)data)[0x524] && !((unsigned char *)data)[0x525]) data[5] &= 0xffffe7ff;
    else data[5] = (data[5] & 0xffffe7ff) | ((data[0x520/4] & 3) << 11);
    data[0x5fc/4] |= 8;
}

void __GXSetVCD(void) {
    unsigned int *data = __GXData;
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifo32 = (volatile unsigned int *)0xCC008000;
    unsigned int count;
    unsigned int value;
    unsigned int compCount;
    unsigned int vatCount;
    unsigned int sizeCount;

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

    compCount = (data[0x14 / 4] >> 15) & 0xF;
    vatCount = (0x21 - __cntlzw(compCount)) >> 1;
    sizeCount = 0x21 - __cntlzw(data[0x18 / 4] & 0xFFFF);
    value = vatCount | (count << 2) | ((sizeCount << 3) & 0xFFFFFFF0);

    *fifo8 = 0x10;
    *fifo32 = 0x1008;
    *fifo32 = value;
    *(unsigned short *)((char *)data + 2) = 1;
}

extern unsigned char lbl_80558E38;
extern unsigned char lbl_80558E3C;
extern unsigned char lbl_80558E40;
void __GXCalculateVLim(void) {
    unsigned int *gx = __GXData;
    unsigned int flags;
    unsigned int vtx;
    unsigned char *table;
    int sum;
    int term;

    if (*(unsigned short *)((char *)gx + 4) == 0) return;

    flags = gx[0x14 / 4];
    sum = flags & 1;
    sum += (flags >> 1) & 1;
    sum += (flags >> 2) & 1;
    sum += (flags >> 3) & 1;
    sum += (flags >> 4) & 1;
    sum += (flags >> 5) & 1;
    sum += (flags >> 6) & 1;
    sum += (flags >> 7) & 1;

    term = (flags >> 8) & 1;
    if (((gx[0x1C / 4] >> 9) & 1) == 1) {
        table = &lbl_80558E40;
        term = table[(flags >> 11) & 3] * 3;
    }
    sum += term;

    table = &lbl_80558E40;
    sum += table[(flags >> 9) & 3];
    table = &lbl_80558E38;
    sum += table[(flags >> 13) & 3];
    sum += table[(flags >> 15) & 3];

    vtx = gx[0x18 / 4];
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

void GXSetVtxAttrFmt(unsigned int fmt, unsigned int attr, unsigned int compCnt,
                     unsigned int compType, unsigned int shift)
{
    unsigned int *base = &__GXData[fmt << 2];
    unsigned int *vatA = &base[0x1C / 4];
    unsigned int *vatB = &base[0x3C / 4];
    unsigned int *vatC = &base[0x5C / 4];

    if (fmt <= 0x10) {
        switch (attr) {
        case 0x8: // GX_VA_POS
            *vatA = __rlwimi(*vatA, compCnt, 0, 31, 31);
            *vatA = __rlwimi(*vatA, compType, 1, 28, 30);
            *vatA = __rlwimi(*vatA, shift, 4, 23, 27);
            break;
        case 0x9: // GX_VA_NRM
        case 0x1C: // GX_VA_NBT
            *vatA = __rlwimi(*vatA, compType, 10, 19, 21);
            if (compCnt == 2) {
                *vatA = __rlwimi(*vatA, 1, 9, 22, 22);
                *vatA = __rlwimi(*vatA, 1, 31, 0, 0);
            } else {
                *vatA = __rlwimi(*vatA, compCnt, 9, 22, 22);
                *vatA = __rlwimi(*vatA, 0, 31, 0, 0);
            }
            break;
        case 0xA: // GX_VA_CLR0
            *vatA = __rlwimi(*vatA, compCnt, 13, 18, 18);
            *vatA = __rlwimi(*vatA, compType, 14, 15, 17);
            break;
        case 0xB: // GX_VA_CLR1
            *vatA = __rlwimi(*vatA, compCnt, 17, 14, 14);
            *vatA = __rlwimi(*vatA, compType, 18, 11, 13);
            break;
        case 0xC: // GX_VA_TEX0
            *vatA = __rlwimi(*vatA, compCnt, 21, 10, 10);
            *vatA = __rlwimi(*vatA, compType, 22, 7, 9);
            *vatA = __rlwimi(*vatA, shift, 25, 2, 6);
            break;
        case 0xD: // GX_VA_TEX1
            *vatB = __rlwimi(*vatB, compCnt, 0, 31, 31);
            *vatB = __rlwimi(*vatB, compType, 1, 28, 30);
            *vatB = __rlwimi(*vatB, shift, 4, 23, 27);
            break;
        case 0xE: // GX_VA_TEX2
            *vatB = __rlwimi(*vatB, compCnt, 9, 22, 22);
            *vatB = __rlwimi(*vatB, compType, 10, 19, 21);
            *vatB = __rlwimi(*vatB, shift, 13, 14, 18);
            break;
        case 0xF: // GX_VA_TEX3
            *vatB = __rlwimi(*vatB, compCnt, 18, 13, 13);
            *vatB = __rlwimi(*vatB, compType, 19, 10, 12);
            *vatB = __rlwimi(*vatB, shift, 22, 5, 9);
            break;
        case 0x10: // GX_VA_TEX4
            *vatB = __rlwimi(*vatB, compCnt, 27, 4, 4);
            *vatB = __rlwimi(*vatB, compType, 28, 1, 3);
            *vatC = __rlwimi(*vatC, shift, 0, 27, 31);
            break;
        case 0x11: // GX_VA_TEX5
            *vatC = __rlwimi(*vatC, compCnt, 5, 26, 26);
            *vatC = __rlwimi(*vatC, compType, 6, 23, 25);
            *vatC = __rlwimi(*vatC, shift, 9, 18, 22);
            break;
        case 0x12: // GX_VA_TEX6
            *vatC = __rlwimi(*vatC, compCnt, 14, 17, 17);
            *vatC = __rlwimi(*vatC, compType, 15, 14, 16);
            *vatC = __rlwimi(*vatC, shift, 18, 9, 13);
            break;
        case 0x13: // GX_VA_TEX7
            *vatC = __rlwimi(*vatC, compCnt, 23, 8, 8);
            *vatC = __rlwimi(*vatC, compType, 24, 5, 7);
            *vatC = __rlwimi(*vatC, shift, 27, 0, 4);
            break;
        }
    }

    __GXData[0x5FC / 4] |= 0x10;
    *((unsigned char *)__GXData + 0x5FB) |= (unsigned char)(1 << (fmt & 0x1F));
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

void GXSetTexCoordGen2(unsigned int coord, int func, unsigned int line, unsigned int nrm, unsigned int normalize, int postmtx) {
    extern unsigned int jumptable_80303884[];
    extern unsigned int jumptable_80303868[];
    unsigned int *data = __GXData;
    unsigned int type = 0;
    unsigned int source = 5;
    unsigned int normalizeFlag = 0;
    unsigned int value;
    unsigned int mask;
    unsigned int shift;

    if (line <= 0x14) {
        void (*dispatch)(void) = (void (*)(void))jumptable_80303884[line];
        dispatch();
        return;
    }

    if (func == 1) {
        source = 5; normalizeFlag = 0;
    } else if (func <= 0) {
        if (func == 0) { source = 5; normalizeFlag = 1; }
    } else if (func == 10) {
        source = (line == 0x13) ? 2 : 3;
        type = 1;
    } else if (func < 10) {
        source = 1;
        normalizeFlag = 1;
        type = (unsigned int)(func - 2);
    }

    value = source << 7;
    value |= normalizeFlag << 2;
    value |= (line - 0xC) << 12;
    value |= (func - 2) << 15;
    if (func == 1) value = 0x280;
    else if (func == 0) value = 0x282;
    else if (func == 10) value = (line == 0x13) ? 0x120 : 0x130;
    *(unsigned int *)((char *)data + coord * 4 + 0xC8) = value;

    mask = 0x10000 << coord;
    data[0x5FC / 4] |= mask;
    *(unsigned int *)((char *)data + coord * 4 + 0xE8) = ((normalize & 1) << 8) | ((postmtx - 0x40) & 0x3F);

    if (coord > 6) {
        data[0x84 / 4] = (data[0x84 / 4] & 0xFF03FFFF) | ((nrm & 0x3F) << 18);
        data[0x5FC / 4] |= 0x4000000;
        return;
    }
    value = jumptable_80303868[coord];
    (void)value;
    shift = coord * 6;
    if (coord < 4) {
        data[0x80 / 4] = (data[0x80 / 4] & ~(0x3Fu << (26 - shift))) | ((nrm & 0x3F) << (26 - shift));
    } else {
        shift = (coord - 4) * 6;
        data[0x84 / 4] = (data[0x84 / 4] & ~(0x3Fu << (26 - shift))) | ((nrm & 0x3F) << (26 - shift));
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
    volatile unsigned int *fifo = (volatile unsigned int *)0xCC008000;
    if (__GXData[0x5FC / 4] != 0) {
        __GXSetDirtyState();
    }
    fifo[0] = 0;
    fifo[0] = 0;
    fifo[0] = 0;
    fifo[0] = 0;
    fifo[0] = 0;
    fifo[0] = 0;
    fifo[0] = 0;
    fifo[0] = 0;
    PPCSync(0xCC010000);
}

void GXGetVtxDescv(void) {
    while (PPCMfwpar() & 1) {
    }
    PPCMtwpar(0x0C008000);
}

extern unsigned int *__memReg;
extern char __GXIsGPFifoReady(void);
extern unsigned long long OSGetTime(void);
void GXGetVtxAttrFmt(void) {
    unsigned int old, value;
    unsigned long long start;
    if (*(unsigned char *)((char *)__GXData + 0x5FA) && __GXIsGPFifoReady()) {
        do {
            old = ((unsigned int)*(unsigned short *)((char *)__memReg + 0x4E) << 16) |
                   *(unsigned short *)((char *)__memReg + 0x50);
            start = OSGetTime();
            while (OSGetTime() - start < 8) {}
            value = ((unsigned int)*(unsigned short *)((char *)__memReg + 0x4E) << 16) |
                    *(unsigned short *)((char *)__memReg + 0x50);
        } while (value != old);
    }
    *(volatile unsigned int *)0xCC003018 = 1;
    start = OSGetTime();
    while (OSGetTime() - start < 50) {}
    *(volatile unsigned int *)0xCC003018 = 0;
    start = OSGetTime();
    while (OSGetTime() - start < 5) {}
}

void GXGetVtxAttrFmtv(void) {
    unsigned int old;
    unsigned int value;
    unsigned long long start;
    unsigned int *data = __GXData;

    if (*(unsigned char *)((char *)data + 0x5FA) && __GXIsGPFifoReady()) {
        do {
            old = ((unsigned int)*(unsigned short *)((char *)__memReg + 0x4E) << 16) |
                  *(unsigned short *)((char *)__memReg + 0x50);
            start = OSGetTime();
            while (OSGetTime() - start < 8) {}
            value = ((unsigned int)*(unsigned short *)((char *)__memReg + 0x4E) << 16) |
                    *(unsigned short *)((char *)__memReg + 0x50);
        } while (value != old);
    }
    *(volatile unsigned int *)0xCC003018 = 1;
    start = OSGetTime();
    while (OSGetTime() - start < 50) {}
    *(volatile unsigned int *)0xCC003018 = 0;
    start = OSGetTime();
    while (OSGetTime() - start < 5) {}
    if (__GXIsGPFifoReady()) {
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

void GXMiscInit(s32 arg0) {
    union {
        unsigned int value;
        struct {
            unsigned int top : 8;
            unsigned int middle : 8;
            unsigned int low : 16;
        } fields;
    } command;
    s32 interruptState;
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifo = (volatile unsigned int *)0xCC008000;

    interruptState = OSDisableInterrupts();
    command.value = (unsigned int)arg0 | 0x48000000;
    *fifo8 = 0x61;
    *fifo = command.value;
    command.fields.low = (unsigned int)arg0;
    command.fields.top = 0x47;
    *fifo8 = 0x61;
    *fifo = command.value;

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
    ((void (*)(s32))OSRestoreInterrupts)(interruptState);
    *(unsigned short *)((unsigned char *)__GXData + 2) = 0;
}

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
    interruptState = OSDisableInterrupts();
    while (lbl_8055D970 == 0) {
        OSSleepThread(&lbl_8055D968);
    }
    ((void (*)(s32))OSRestoreInterrupts)(interruptState);
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
    union {
        u32 reg;
        struct {
            unsigned int high : 8;
            unsigned int unused : 8;
            unsigned int attenB : 4;
            unsigned int distA : 1;
            unsigned int attenA : 3;
            unsigned int attenC : 3;
            unsigned int unused2 : 3;
            unsigned int distB : 1;
            unsigned int type : 1;
        } fields;
    } value;

    s32 type = 0;
    value.reg = __peReg[1];
    if (arg0 != 1) {
        if (arg0 == 3) {
            type = 1;
        }
    }
    value.fields.type = type;
    value.fields.distA = __cntlzw(arg0 - 3);
    value.fields.distB = __cntlzw(arg0 - 2);
    value.fields.attenB = arg3;
    value.fields.attenA = arg1;
    value.fields.attenC = arg2;
    value.fields.high = 0x41;
    __peReg[1] = value.reg;
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
extern "C" void GXInitSpecularDir(unsigned int arg0, void *ctx) {
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
#pragma cplusplus off
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

void GXBegin(unsigned char prim, unsigned char vtxfmt, unsigned short nverts) {
    unsigned int *data = __GXData;
    unsigned int count;
    unsigned int remaining;
    unsigned int written = 0;
    unsigned int blocks;
    unsigned int i;
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned short *fifo16 = (volatile unsigned short *)0xCC008000;
    volatile unsigned int *fifo32 = (volatile unsigned int *)0xCC008000;

    if (data[0x5FC / 4] != 0)
        __GXSetDirtyState();
    if (data[0] == 0) {
        *fifo8 = 0x98;
        count = (unsigned int)*(unsigned short *)((char *)data + 4) *
                *(unsigned short *)((char *)data + 6);
        *fifo16 = *(unsigned short *)((char *)data + 4);
        if (count != 0) {
            remaining = count - 0x20;
            if (((count + 3) >> 2) > 8) {
                if ((count + 3) >= 3 && count <= count + 3) {
                    blocks = (remaining + 0x1F) >> 5;
                    if (remaining > 0) {
                        do {
                            *fifo32 = 0; *fifo32 = 0; *fifo32 = 0; *fifo32 = 0;
                            *fifo32 = 0; *fifo32 = 0; *fifo32 = 0; *fifo32 = 0;
                            written += 0x20;
                        } while (--blocks != 0);
                    }
                }
            }
            blocks = ((count + 3) - written) >> 2;
            if (written < count) {
                do {
                    *fifo32 = 0;
                } while (--blocks != 0);
            }
        }
        *(unsigned short *)((char *)data + 2) = 1;
    }
    *fifo8 = prim | vtxfmt;
    *fifo16 = nverts;
}

void __GXSendFlushPrim(void) {
    volatile u8 *fifo8 = (volatile u8 *)0xCC008000;
    volatile u16 *fifo16 = (volatile u16 *)0xCC008000;
    volatile u32 *fifo32 = (volatile u32 *)0xCC008000;
    register u16 *gx = (u16 *)__GXData;
    u32 written;
    u32 size;
    u32 end;
    u32 tail;
    u32 count;
    u32 valid;
    u16 height;
    u16 width;

    written = 0;
    width = gx[2];
    height = gx[3];
    *fifo8 = 0x98;
    size = width * height;
    *fifo16 = gx[2];
    if (size != 0) {
        end = size + 3;
        tail = size - 0x20;
        if ((end >> 2) > 8) {
            valid = 0;
            if (end >= 3 && size <= end)
                valid = 1;
            if (valid != 0) {
                count = (tail + 0x1F) >> 5;
                if (tail <= 0) {
                } else {
                    do {
                        *fifo32 = 0;
                        written += 0x20;
                        *fifo32 = 0;
                        *fifo32 = 0;
                        *fifo32 = 0;
                        *fifo32 = 0;
                        *fifo32 = 0;
                        *fifo32 = 0;
                        *fifo32 = 0;
                    } while (--count != 0);
                }
            }
        }
        count = (size + 3 - written) >> 2;
        if (written < size) {
            do {
                *fifo32 = 0;
            } while (--count != 0);
        }
    }
    gx[1] = 1;
}

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

void GXEnableTexOffsets(s32 texMap, int line, int point) {
    unsigned int *data = __GXData + texMap;
    unsigned int value = data[0x108 / 4];
    value = (value & ~0xC0000) | ((line << 18) & 0x40000) | ((point << 19) & 0x80000);
    data[0x108 / 4] = value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x108 / 4];
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetCullMode(unsigned int mode) {
    unsigned int field = (mode >> 1) & 1;
    union {
        unsigned int reg;
        struct {
            unsigned int pad : 16;
            unsigned int cull : 2;
            unsigned int rest : 14;
        } fields;
    } data;

    field = (field & ~2U) | ((mode << 1) & 2);
    data.reg = __GXData[0x254 / 4];
    data.fields.cull = field;
    __GXData[0x254 / 4] = data.reg;
    __GXData[0x5FC / 4] |= 4;
}

void GXSetCoPlanar(s32 enable) {
    unsigned int *data = __GXData;
    data[0x254 / 4] = (data[0x254 / 4] & 0xFFF7FFFF) | ((enable & 1) << 19);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = 0xFE080000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x254 / 4];
}

void GXDrawCylinder(void *src, void *dst, int x, int y) {
    unsigned int dx = (x << 1) & 0xFFFE;
    unsigned int dy = (y << 1) & 0xFFFE;
    unsigned int a, b, mode;
    unsigned short radius;
    if (src != dst) {
        b = *(unsigned int *)((char *)src + 0x00); a = *(unsigned int *)((char *)src + 0x04);
        *(unsigned int *)((char *)dst + 0x00) = b; *(unsigned int *)((char *)dst + 0x04) = a;
        b = *(unsigned int *)((char *)src + 0x08); a = *(unsigned int *)((char *)src + 0x0C);
        *(unsigned int *)((char *)dst + 0x08) = b; *(unsigned int *)((char *)dst + 0x0C) = a;
        b = *(unsigned int *)((char *)src + 0x10); a = *(unsigned int *)((char *)src + 0x14);
        *(unsigned int *)((char *)dst + 0x10) = b; *(unsigned int *)((char *)dst + 0x14) = a;
        b = *(unsigned int *)((char *)src + 0x18); a = *(unsigned int *)((char *)src + 0x1C);
        *(unsigned int *)((char *)dst + 0x18) = b; *(unsigned int *)((char *)dst + 0x1C) = a;
        b = *(unsigned int *)((char *)src + 0x20); a = *(unsigned int *)((char *)src + 0x24);
        *(unsigned int *)((char *)dst + 0x20) = b; *(unsigned int *)((char *)dst + 0x24) = a;
        b = *(unsigned int *)((char *)src + 0x28); a = *(unsigned int *)((char *)src + 0x2C);
        *(unsigned int *)((char *)dst + 0x28) = b; *(unsigned int *)((char *)dst + 0x2C) = a;
        b = *(unsigned int *)((char *)src + 0x30); a = *(unsigned int *)((char *)src + 0x34);
        *(unsigned int *)((char *)dst + 0x30) = b; *(unsigned int *)((char *)dst + 0x34) = a;
        a = *(unsigned int *)((char *)src + 0x38);
        *(unsigned int *)((char *)dst + 0x38) = a;
    }
    *(unsigned short *)((char *)dst + 4) = *(unsigned short *)((char *)src + 4) - dx;
    mode = *(volatile unsigned int *)src & 3;
    radius = *(unsigned short *)((char *)src + 6);
    *(unsigned short *)((char *)dst + 6) = radius - ((dy * radius) / *(unsigned short *)((char *)src + 8));
    if (*(int *)((char *)src + 0x14) == 0 && mode == 0)
        *(unsigned short *)((char *)dst + 8) = *(unsigned short *)((char *)src + 8) - ((dy >> 1) & 0x7FFF);
    else
        *(unsigned short *)((char *)dst + 8) = *(unsigned short *)((char *)src + 8) - dy;
    *(unsigned short *)((char *)dst + 0xE) = *(unsigned short *)((char *)src + 0xE) - dx;
    if (mode == 1)
        *(unsigned short *)((char *)dst + 0x10) = *(unsigned short *)((char *)src + 0x10) - ((dy << 1) & 0x1FFFE);
    else
        *(unsigned short *)((char *)dst + 0x10) = *(unsigned short *)((char *)src + 0x10) - dy;
    *(unsigned short *)((char *)dst + 0xA) = *(unsigned short *)((char *)src + 0xA) + x;
    *(unsigned short *)((char *)dst + 0xC) = *(unsigned short *)((char *)src + 0xC) + y;
}

void GXSetDispCopySrc(s32 left, s32 top, s32 width, s32 height) {
    unsigned int *data = __GXData;
    unsigned int src = 0;
    unsigned int size = 0;
    src |= left & 0x3FF;
    src |= (top << 10) & 0xFFC00;
    src |= 0x49000000;
    size |= (width - 1) & 0x3FF;
    size |= ((height - 1) << 10) & 0xFFC00;
    size |= 0x4A000000;
    data[0x230 / 4] = src;
    data[0x234 / 4] = size;
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
    register unsigned int *gx = __GXData;
    union {
        u32 reg;
        struct {
            u32 constant : 8;
            u32 pad : 14;
            u32 arg : 10;
        } fields;
    } data = {0};

    data.fields.arg = ((value << 1) & 0xFFFE) >> 5;
    data.fields.constant = 0x4D;
    gx[0x238 / 4] = data.reg;
}

void __GetImageTileCount(unsigned int, int, int, int *, int *, int *);
void GXSetTexCopyDst(int width, int height, int format, int depth) {
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
    int tilesX;
    int tilesY;
    int compressed;
    register int fmt;
    register unsigned int *gx;
    CopyControlReg *reg;

    gx = __GXData;
    fmt = format & 0xF;
    if (format == 0x13)
        fmt = 0xB;
    *((u8 *)gx + 0x250) = 0;
    if (format == 0x26 || (format < 4 && format >= 0))
        ((CopyControlReg *)((u8 *)gx + 0x24C))->copyMode = 3;
    else
        ((CopyControlReg *)((u8 *)gx + 0x24C))->copyMode = 2;
    reg = (CopyControlReg *)((u8 *)gx + 0x24C);
    *((u8 *)gx + 0x250) = (format >> 4) & 1;
    reg->formatHigh = (fmt >> 3) & 1;
    __GetImageTileCount(format, width, height, &tilesX, &tilesY, &compressed);
    __GXData[0x248 / 4] = 0;
    __GXData[0x248 / 4] = (tilesX * compressed & 0x3FF) | 0x4D000000;
    reg->depthBit = depth;
    reg->formatLow = fmt;
}

void GXSetDispCopyFrame2Field(s32 value) {
    unsigned int *data = __GXData;
    data[0x23C / 4] = (data[0x23C / 4] & ~(3U << 12)) | ((value & 3) << 12);
    data[0x24C / 4] = data[0x24C / 4] & ~(3U << 12);
}

void GXSetCopyClamp(s32 value) {
    union {
        unsigned int reg;
        struct {
            unsigned int pad : 30;
            unsigned int bit1 : 1;
            unsigned int bit0 : 1;
        } fields;
    } data;
    unsigned int *gx = __GXData;

    data.reg = gx[0x23C / 4];
    data.fields.bit0 = value;
    data.fields.bit1 = value;
    gx[0x23C / 4] = data.reg;
    data.reg = gx[0x24C / 4];
    data.fields.bit0 = value;
    data.fields.bit1 = value;
    gx[0x24C / 4] = data.reg;
}

f32 GXGetYScaleFactor(u32 arg0, u32 arg1) {
 f32 ratio, previous, c0, c1;
 u32 numerator, height, scale, factor;
 ratio=(f32)arg1/(f32)arg0; height=arg1;
 factor=(u32)(lbl_80560B40/ratio)&0x1FF;
 numerator=(arg0-1)<<8; scale=numerator/factor+1;
 if(factor>0x80&&factor<0x100){while(!(factor&1))factor>>=1;if(arg0%factor==0)scale++;}
 if(scale>0x400)scale=0x400;
 while(scale>arg1){height--;ratio=(f32)height/(f32)arg0;factor=(u32)(lbl_80560B40/ratio)&0x1FF;scale=numerator/factor+1;
 if(factor>0x80&&factor<0x100){while(!(factor&1))factor>>=1;if(arg0%factor==0)scale++;}
 if(scale>0x400)scale=0x400;}
 previous=ratio;
 while(scale<arg1){height++;previous=ratio;ratio=(f32)height/(f32)arg0;factor=(u32)(lbl_80560B40/ratio)&0x1FF;scale=numerator/factor+1;
 if(factor>0x80&&factor<0x100){while(!(factor&1))factor>>=1;if(arg0%factor==0)scale++;}
 if(scale>0x400)scale=0x400;}
 return previous;
}

extern f32 lbl_80560B40;
unsigned int GXSetDispCopyYScale(f32 yScale) {
    unsigned int scale = (unsigned int)(lbl_80560B40 / yScale);
    unsigned int height = scale & 0x1FF;
    unsigned int small = height <= 0x80;
    unsigned int width;
    unsigned int result;
    unsigned int value;
    unsigned int tmp;
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
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC008000;
    volatile unsigned int *fifo = (volatile unsigned int *)0xCC008000;

    *fifo8 = 0x61;
    packet.value = 0;
    packet.fields.scale = scale;
    packet.fields.tag = 0x4E;
    *fifo = packet.value;
    ((volatile unsigned short *)__GXData)[1] = 0;
    tmp = (0x100 - height) | (height - 0x100);
    copyState.value = __GXData[0x23C / 4];
    copyState.fields.flag = tmp >> 31;
    __GXData[0x23C / 4] = copyState.value;
    width = (__GXData[0x234 / 4] >> 10) & 0x3FF;
    value = width + 1;
    result = (((value - 1) << 8) / height) + 1;
    if (!small && height < 0x100) {
        do {
            height >>= 1;
        } while ((height & 1) == 0);
        if (value % height == 0) result++;
    }
    if (result > 0x400) result = 0x400;
    return result;
}

void GXSetCopyClear(unsigned char *color, s32 depth) {
    union ColorWord {
        unsigned int value;
        struct {
            unsigned int command : 8;
            unsigned int pad : 8;
            unsigned int channel : 8;
            unsigned int low : 8;
        } bits;
    } first, second;
    union DepthWord {
        unsigned int value;
        struct {
            unsigned int command : 8;
            unsigned int depth : 24;
        } bits;
    } third;
    unsigned int red;
    unsigned int blue;
    unsigned int green;
    unsigned int *data;

    red = color[0];
    green = color[3];
    first.value = 0;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    first.bits.low = red;
    first.bits.channel = green;
    blue = color[2];
    first.bits.command = 0x4F;
    *(volatile unsigned int *)0xCC008000 = first.value;

    second.value = 0;
    second.bits.low = blue;
    green = color[1];
    second.bits.command = 0x50;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    second.bits.channel = green;
    data = __GXData;
    *(volatile unsigned int *)0xCC008000 = second.value;

    third.value = 0;
    third.bits.depth = depth;
    third.bits.command = 0x51;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = third.value;
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetCopyFilter(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    u32 a, b, c, d;
    u32 e, f;
    volatile u8 *bp = (volatile u8 *)0xCC008000;
    volatile u32 *wp = (volatile u32 *)0xCC008000;

    if (arg0) {
        a = ((u32)(arg1[0] & 15) | ((u32)(arg1[1] & 15) << 4) | ((u32)(arg1[2] & 15) << 8) |
             ((u32)(arg1[3] & 15) << 12) | ((u32)(arg1[4] & 15) << 16) | ((u32)(arg1[5] & 15) << 20) | 0x01000000);
        b = ((u32)(arg1[6] & 15) | ((u32)(arg1[7] & 15) << 4) | ((u32)(arg1[8] & 15) << 8) |
             ((u32)(arg1[9] & 15) << 12) | ((u32)(arg1[10] & 15) << 16) | ((u32)(arg1[11] & 15) << 20) | 0x02000000);
        c = ((u32)(arg1[12] & 15) | ((u32)(arg1[13] & 15) << 4) | ((u32)(arg1[14] & 15) << 8) |
             ((u32)(arg1[15] & 15) << 12) | ((u32)(arg1[16] & 15) << 16) | ((u32)(arg1[17] & 15) << 20) | 0x03000000);
        d = ((u32)(arg1[18] & 15) | ((u32)(arg1[19] & 15) << 4) | ((u32)(arg1[20] & 15) << 8) |
             ((u32)(arg1[21] & 15) << 12) | ((u32)(arg1[22] & 15) << 16) | ((u32)(arg1[23] & 15) << 20) | 0x04000000);
    } else {
        a = 0x01666666; b = 0x02666666; c = 0x03666666; d = 0x04666666;
    }
    *bp = 0x61; *wp = a;
    e = 0x53000000;
    *bp = 0x61;
    f = 0x54000000;
    *wp = b; *bp = 0x61; *wp = c; *bp = 0x61; *wp = d;

    if (arg2) {
        e |= (arg3[0] & 63) | ((u32)(arg3[1] & 63) << 6) | ((u32)(arg3[2] & 63) << 12) | ((u32)(arg3[3] & 63) << 18);
        f |= (arg3[4] & 63) | ((u32)(arg3[5] & 63) << 6) | ((u32)(arg3[6] & 63) << 12);
    } else {
        e |= 0x00595000;
        f = (f & 0xFFFC003F) | 0x15;
    }
    *bp = 0x61; *wp = e; *bp = 0x61; *wp = f;
    __GXData[0] = (__GXData[0] & 0xFFFF0000) | (__GXData[0] & 0xFFFF);
    *(volatile u16 *)((u8 *)__GXData + 2) = 0;
}

void GXSetDispCopyGamma(s32 arg0) {
    ((GXDispCopyGammaReg *)&__GXData[0x23c / 4])->gamma = arg0;
}

void GXCopyDisp(unsigned int source, int clear) {
    unsigned int *gx = __GXData;
    volatile unsigned char *fifo8 = (volatile unsigned char *)0xCC010000;
    volatile unsigned int *fifo32 = (volatile unsigned int *)0xCC010000;
    unsigned int *reg = gx + 0x22C / 4;
    unsigned int val;
    int changed = 0;

    if (clear != 0) {
        *fifo8 = 0x61; *fifo32 = gx[0x228 / 4] | 0xF;
        *fifo8 = 0x61; *fifo32 = gx[0x220 / 4] & ~3u;
    }
    if (clear == 0 && ((*reg & 7) == 3) && ((*reg & 0x40) != 0)) {
        *fifo8 = 0x61;
        val = *reg & ~0x40u;
        *fifo32 = val;
        changed = 1;
    }
    *fifo8 = 0x61; *fifo32 = gx[0x230 / 4];
    *fifo8 = 0x61; *fifo32 = gx[0x234 / 4];
    *fifo8 = 0x61; *fifo32 = gx[0x238 / 4];
    *fifo8 = 0x61; *fifo32 = ((source << 3) & 0xFFFFFF00) | 0x4B;
    val = gx[0x23C / 4];
    val = (val & ~0x800u) | ((clear << 11) & 0x800) | 0x4000 | 0x52000000;
    gx[0x23C / 4] = val;
    *fifo8 = 0x61; *fifo32 = val;
    if (clear != 0) {
        *fifo8 = 0x61; *fifo32 = gx[0x228 / 4];
        *fifo8 = 0x61; *fifo32 = gx[0x220 / 4];
    }
    if (changed) {
        *fifo8 = 0x61; *fifo32 = *reg;
    }
    *(unsigned short *)((char *)gx + 2) = 0;
}

void GXCopyTex(u32 width, s32 clear) {
    s32 changed;
    u32 value;
    if (clear != 0) {
        value = __GXData[0x228 / 4];
        *(volatile unsigned char *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = value | 0xF;
        value = __GXData[0x220 / 4];
        *(volatile unsigned char *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = value & 0xFFFFFFFC;
    }
    changed = 0;
    value = __GXData[0x22C / 4];
    if (*((unsigned char *)__GXData + 0x250) != 0 && (value & 7) != 3) {
        changed = 1;
        value = (value & ~7) | 3;
    }
    if (clear == 0 && (value & 7) == 3 && ((value >> 6) & 1) == 1) {
        changed = 1;
        value &= 0xFFFFFFBF;
    }
    if (changed != 0) {
        *(volatile unsigned char *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = value;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = __GXData[0x240 / 4];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = __GXData[0x244 / 4];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = __GXData[0x248 / 4];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = (width << 27) | 0x4B000000;
    value = __GXData[0x24C / 4];
    value |= (clear << 11) & 0x800;
    value &= 0xFFFFBFFF;
    value |= 0x52000000;
    __GXData[0x24C / 4] = value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    if (clear != 0) {
        *(volatile unsigned char *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = __GXData[0x228 / 4];
        *(volatile unsigned char *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = __GXData[0x220 / 4];
    }
    if (changed != 0) {
        *(volatile unsigned char *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = __GXData[0x22C / 4];
    }
    *(unsigned short *)((char *)__GXData + 2) = 0;
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

void GXSetNumChans(s32 num) {
    unsigned int *data = __GXData;
    data[0x254 / 4] = (data[0x254 / 4] & ~(7 << 4)) | ((num & 7) << 4);
    data[0x5FC / 4] |= 0x01000004;
}

void GXSetChanCtrl(s32 chan, s32 enable, s32 matColor, s32 ambColor, s32 lightMask, s32 diffFn, s32 attnFn) {
    union {
        unsigned int value;
        struct {
            unsigned int pad0 : 17;
            unsigned int lightHigh : 4;
            unsigned int attnHigh : 1;
            unsigned int attnLow : 1;
            unsigned int diff : 2;
            unsigned int mat : 1;
            unsigned int lightLow : 4;
            unsigned int enable : 1;
            unsigned int amb : 1;
        } f;
    } u;
    unsigned int *base;
    unsigned int *data;
    unsigned int idx = chan & 3;
    unsigned int attn = diffFn;
    u.value = 0;
    u.f.enable = enable;
    u.f.amb = ambColor;
    u.f.mat = matColor;
    if (attnFn == 0) attn = 0;
    u.f.diff = attn;
    u.f.attnLow = (2 - attnFn) | (attnFn - 2);
    u.f.attnHigh = -attnFn | attnFn;
    u.f.lightLow = lightMask;
    u.f.lightHigh = ((unsigned int)lightMask) >> 4;
    base = __GXData;
    data = base + idx;
    data[0xB8 / 4] = u.value;
    base[0x5FC / 4] |= 0x1000 << idx;
    if (chan == 4) {
        base[0xC0 / 4] = u.value;
        base[0x5FC / 4] |= 0x5000;
        return;
    }
    if (chan == 5) {
        base[0xC4 / 4] = u.value;
        base[0x5FC / 4] |= 0xA000;
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

void __GetImageTileCount(unsigned int format, int width, int height, int *tiles_x, int *tiles_y, int *compressed) {
    int shift_x;
    int shift_y;

    switch (format) {
    case 0x0:
    case 0x8:
    case 0xE:
    case 0x20:
    case 0x30:
        shift_x = 3;
        shift_y = 3;
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
        shift_x = 3;
        shift_y = 2;
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
        shift_x = 2;
        shift_y = 2;
        break;
    default:
        shift_y = 0;
        shift_x = 0;
        break;
    }

    if (width == 0)
        width = 1;
    if (height == 0)
        height = 1;

    *tiles_x = (width + (1 << shift_x) - 1) >> shift_x;
    *tiles_y = (height + (1 << shift_y) - 1) >> shift_y;
    *compressed = ((int)format == 6 || (int)format == 0x16) ? 2 : 1;
}

void GXInitTexObj(void *obj, void *image, unsigned short width, unsigned short height, int format, int wrapS, int wrapT, int mipmap) {
    unsigned int *p = (unsigned int *)obj;
    unsigned int v;
    unsigned int rowShift, colShift;
    unsigned int fmt;
    unsigned int value;
    unsigned int level;
    memset(obj, 0, 0x20);
    v = p[0];
    v = (v & 0xfffffff0) | ((unsigned int)format & 3) | (((unsigned int)wrapS & 3) << 2) | 0x10;
    p[0] = v;
    if (mipmap) {
        ((unsigned char *)obj)[0x1f] |= 1;
        v = (v & 0xffffff1f) | ((wrapT >= 8 && wrapT <= 10 ? 5 : 6) << 5);
        p[0] = v;
        level = width > height ? __cntlzw(width) : __cntlzw(height);
        level = 31 - level;
        value = (unsigned int)(31.0f * ((double)level - 4503601774854144.0));
        p[1] = (p[1] & 0xffff00ff) | ((value & 0xff) << 8);
    } else {
        p[0] = (v & 0xffffff1f) | (4 << 5);
    }
    p[5] = wrapT;
    p[3] = (p[3] & 0xff000000) | ((unsigned int)image >> 5 & 0xffffff);
    p[2] = (p[2] & 0xff000000) | ((width - 1) & 0x3ff) | (((height - 1) & 0x3ff) << 10) | (((unsigned int)wrapT & 0xf) << 20);
    fmt = (unsigned int)wrapT & 0xf;
    if (fmt > 0xe) {
        ((unsigned char *)obj)[0x1e] = 2;
        ((unsigned char *)obj)[0x1f] |= 2;
        *(unsigned short *)((char *)obj + 0x1c) = (((width + 3) >> 2) * ((height + 3) >> 2)) & 0x7fff;
        return;
    }
    switch (fmt) {
    case 0: ((unsigned char *)obj)[0x1e]=1; rowShift=3; colShift=3; break;
    case 1: ((unsigned char *)obj)[0x1e]=2; rowShift=3; colShift=2; break;
    case 2: ((unsigned char *)obj)[0x1e]=2; rowShift=2; colShift=2; break;
    case 3: ((unsigned char *)obj)[0x1e]=3; rowShift=2; colShift=2; break;
    case 4: ((unsigned char *)obj)[0x1e]=0; rowShift=3; colShift=3; break;
    case 5: ((unsigned char *)obj)[0x1e]=2; rowShift=2; colShift=2; break;
    default: rowShift=0; colShift=0; break;
    }
    ((unsigned char *)obj)[0x1f] |= 2;
    *(unsigned short *)((char *)obj + 0x1c) = ((((width + (1 << rowShift)) - 1) >> rowShift) * (((height + (1 << colShift)) - 1) >> colShift)) & 0x7fff;
}

extern void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, int);
void GXInitTexObjCI(void *obj, void *image, unsigned short width, unsigned short height, int format, int wrap_s, int wrap_t, int mipmap, int tlut_name) {
    GXInitTexObj(obj, image, width, height, format, wrap_s, wrap_t, mipmap);
    *(int *)((char *)obj + 0x18) = tlut_name;
    *(unsigned char *)((char *)obj + 0x1F) &= ~2;
}

void GXInitTexObjLOD(void *obj, s32 min_filt, s32 mag_filt, f32 min_lod, f32 max_lod, f32 lod_bias, u8 bias_clamp, u8 do_edge_lod, s32 max_aniso) {
    u32 *t = (u32 *)obj;
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
    mode0 = t[0];
    mode0 = __rlwimi(mode0, lbias, 9, 15, 22);
    mode0 = __rlwimi(mode0, __cntlzw(mag_filt - 1), 31, 27, 27);
    t[0] = mode0;
    mode0 = __rlwimi(mode0, GX2HWFiltConv[min_filt], 5, 24, 26);
    mode0 = __rlwimi(mode0, __cntlzw(do_edge_lod), 3, 23, 23);
    mode1 = mode0 & 0xFFF9FFFF;
    mode1 = __rlwimi(mode1, max_aniso, 19, 11, 12);
    mode1 = __rlwimi(mode1, bias_clamp, 21, 10, 10);
    t[0] = mode1;

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
    mode1 = t[1];
    mode1 = __rlwimi(mode1, lmin, 0, 24, 31);
    mode1 = __rlwimi(mode1, lmax, 8, 16, 23);
    t[1] = mode1;
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

extern unsigned char lbl_80558E48[], lbl_80558E50[], lbl_80558E58[];
extern unsigned char lbl_80558E60[], lbl_80558E68[], lbl_80558E70[], lbl_80558E78[];
void GXLoadTexObjPreLoaded(void *obj, void *region, int map) {
    unsigned int v0, v1, v2, v3, v4, v5;
    unsigned int *a = (unsigned int *)obj;
    unsigned int *b = (unsigned int *)region;
    unsigned int *data;
    unsigned int *dst;
    unsigned char opcode = 0x61;

    v0 = (a[0] & 0x00FFFFFF) | ((unsigned int)lbl_80558E48[map] << 24);
    v1 = (a[1] & 0x00FFFFFF) | ((unsigned int)lbl_80558E50[map] << 24);
    v2 = (a[2] & 0x00FFFFFF) | ((unsigned int)lbl_80558E58[map] << 24);
    v3 = (b[0] & 0x00FFFFFF) | ((unsigned int)lbl_80558E60[map] << 24);
    v4 = (b[1] & 0x00FFFFFF) | ((unsigned int)lbl_80558E68[map] << 24);
    v5 = (a[3] & 0x00FFFFFF) | ((unsigned int)lbl_80558E70[map] << 24);
    *(volatile unsigned char *)0xCC008000 = opcode; *(volatile unsigned int *)0xCC008000 = v0;
    *(volatile unsigned char *)0xCC008000 = opcode; *(volatile unsigned int *)0xCC008000 = v1;
    *(volatile unsigned char *)0xCC008000 = opcode; *(volatile unsigned int *)0xCC008000 = v2;
    *(volatile unsigned char *)0xCC008000 = opcode; *(volatile unsigned int *)0xCC008000 = v3;
    *(volatile unsigned char *)0xCC008000 = opcode; *(volatile unsigned int *)0xCC008000 = v4;
    *(volatile unsigned char *)0xCC008000 = opcode; *(volatile unsigned int *)0xCC008000 = v5;
    a[0]=v0; a[1]=v1; a[2]=v2; b[0]=v3; b[1]=v4; a[3]=v5;
    if ((*(unsigned char *)((char *)obj + 0x1F) & 2) == 0) {
        data = __GXData;
        dst = ((unsigned int *(*)(unsigned int))data[0x51C / 4])(*(unsigned int *)((char *)obj + 0x18));
        dst[1] = (dst[1] & 0x00FFFFFF) | ((unsigned int)lbl_80558E78[map] << 24);
        *(volatile unsigned char *)0xCC008000 = opcode;
        *(volatile unsigned int *)0xCC008000 = dst[1];
    }
    data = __GXData;
    dst = (unsigned int *)((char *)data + map * 4);
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
    unsigned int *src = (unsigned int *)arg0;
    unsigned int *dst = ((unsigned int *(*)(int))__GXData[0x51C / 4])(arg1);
    unsigned int v;
    __GXFlushTextureState();
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = src[1];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = dst[0];
    __GXFlushTextureState();
    v = dst[0];
    v = src[0] | (v & 0x3FF);
    dst[1] = v;
    dst[2] = src[1];
    dst[3] = src[2];
    src[0] = v;
}

void GXInitTexCacheRegion(void *obj, signed char arg1, unsigned int arg2, int arg3, unsigned int arg4, int arg5) {
    union { unsigned int word; struct { unsigned int pad:11; unsigned int c:3; unsigned int b:3; unsigned int a:15; } f; } v;
    int size = arg3;
    switch (size) { case 0: size=3; break; case 1: size=4; break; case 2: size=5; break; }
    v.word = 0;
    v.f.a = arg2 >> 5;
    v.f.b = size;
    v.f.c = size;
    *(unsigned int *)obj = v.word;
    switch (arg5) { case 0: size=3; break; case 1: size=4; break; case 2: size=5; break; case 3: size=0; break; }
    v.word = 0;
    v.f.a = arg4 >> 5;
    v.f.b = size;
    v.f.c = size;
    *(unsigned char *)((char *)obj+0xC) = arg1;
    *((unsigned char *)obj+0xD) = 1;
    *(unsigned int *)((char *)obj+4) = v.word;
}

void GXInitTlutRegion(unsigned int *region, int tmem_addr, int tlut_name) {
    struct {
        unsigned int type : 8;
        unsigned int unused : 3;
        unsigned int name : 11;
        unsigned int addr : 10;
    } value = {0, 0, 0, 0};
    value.addr = tmem_addr - 0x80000;
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
    u32 *gx = (u32 *)(void *)__GXData;
    u32 mode = gx[0x5E4 / 4];
    u32 cfg, count, limit, i, word, texmap, coord;
    if (mode == 0xFF) return;
    cfg = gx[0x254 / 4];
    count = (cfg >> 16) & 7;
    limit = ((cfg >> 10) & 0xF) + 1;
    for (i = 0; i < count; i++) {
        word = gx[0x170 / 4];
        switch (i) {
        case 0: texmap = word & 7; coord = (word >> 3) & 7; break;
        case 1: texmap = (word >> 6) & 7; coord = (word >> 9) & 7; break;
        case 2: texmap = (word >> 12) & 7; coord = (word >> 15) & 7; break;
        default: texmap = (word >> 18) & 7; coord = (word >> 21) & 7; break;
        }
        if ((mode & (1 << coord)) == 0) __SetSURegs(texmap, coord);
    }
    for (i = 0; i < limit; i++) {
        u32 mapreg = gx[(0x5A4 / 4) + i];
        u32 field = (mapreg & 0xFF000000) >> 24;
        u32 tex;
        if (i & 1) tex = (gx[(0x150 / 4) + i] >> 15) & 7;
        else tex = (gx[(0x150 / 4) + i] >> 3) & 7;
        if (field != 0xFF && (mode & (1 << tex)) == 0 && (gx[0x5E8 / 4] & (1 << i)) != 0)
            __SetSURegs(field, tex);
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
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8C0D8000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x900DC000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8D0D8800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x910DC800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8E0D9000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x920DD000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8F0D9800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x930DD800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAC0DA000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB00DC400;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAD0DA800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB10DCC00;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAE0DB000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB20DD400;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAF0DB800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB30DDC00;
    goto done;
case1:
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8C0D8000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x900DC000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8D0D8800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x910DC800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8E0D9000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x920DD000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8F0D9800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x930DD800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAC0DA000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB00DE000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAD0DA800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB10DE800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAE0DB000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB20DF000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAF0DB800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB30DF800;
    goto done;
default_case:
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8C0D8000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x900DC000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8D0D8400;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x910DC400;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8E0D8800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x920DC800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x8F0D8C00;
    *fifo8 = (u8)0x61;
    *fifo32 = 0x930DCC00;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAC0D9000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB00DD000;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAD0D9400;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB10DD400;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAE0D9800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB20DD800;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xAF0D9C00;
    *fifo8 = (u8)0x61;
    *fifo32 = 0xB30DDC00;
done:
    ;
}

#pragma dont_inline GXSetTevIndirect
void GXSetTevIndirect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8, s32 arg9) {
    union {
        u32 value;
        struct {
            unsigned int opcode : 8;
            unsigned int unused : 3;
            unsigned int indirectPrev : 1;
            unsigned int utcLod : 1;
            unsigned int stage : 3;
            unsigned int wrapT : 3;
            unsigned int matrix : 4;
            unsigned int bias : 2;
            unsigned int format : 3;
            unsigned int texStage : 2;
            unsigned int tevStage : 2;
        } fields;
    } reg;
    unsigned int *data;

    reg.value = 0;
    reg.fields.tevStage = arg1;
    reg.fields.texStage = arg2;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    reg.fields.format = arg3;
    reg.fields.utcLod = arg8 & 1;
    reg.fields.bias = arg9;
    data = __GXData;
    reg.fields.matrix = arg4;
    reg.fields.wrapT = arg5;
    reg.fields.stage = arg6;
    reg.fields.indirectPrev = arg7;
    reg.fields.opcode = arg0 + 0x10;
    *(volatile unsigned int *)0xCC008000 = reg.value;
    *(unsigned short *)((char *)data + 2) = 0;
}
void GXSetIndTexCoordScale(s32 stage, s32 scaleS, s32 scaleT) {
    u32 reg;

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
void __GXFlushTextureState(void) {
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = __GXData[0x174 / 4];
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

extern unsigned int lbl_80303C30[];
void GXSetTevOp(int stage, int mode) {
    unsigned int *base = lbl_80303C30;
    unsigned int *data;
    unsigned int *tev;
    unsigned int *color;
    unsigned int *alpha;
    unsigned int inputValue;
    unsigned int oldValue;
    unsigned int value;

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

void GXSetTevColorIn(int stage, int a, int b, int c, int d) {
    unsigned int *data = __GXData;
    unsigned int *tev = data + stage;
    unsigned int value = tev[0x180 / 4];
    value = __rlwimi(value, a, 12, 16, 19);
    value = __rlwimi(value, b, 8, 20, 23);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = __rlwimi(value, c, 4, 24, 27);
    value = __rlwimi(value, d, 0, 28, 31);
    *(volatile unsigned int *)0xCC008000 = value;
    tev[0x180 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevAlphaIn(s32 stage, s32 a, s32 b, s32 c, s32 d) {
    unsigned int *data = __GXData;
    unsigned int *tev = data + stage;
    unsigned int value = tev[0x1C0 / 4];
    value = __rlwimi(value, a, 13, 16, 18);
    value = __rlwimi(value, b, 10, 19, 21);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = __rlwimi(value, c, 7, 22, 24);
    value = __rlwimi(value, d, 4, 25, 27);
    *(volatile unsigned int *)0xCC008000 = value;
    tev[0x1C0 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevColorOp(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    union TevColorOpReg {
        unsigned int value;
        struct {
            unsigned int pad0 : 8;
            unsigned int konst : 2;
            unsigned int scale : 2;
            unsigned int arg4 : 1;
            unsigned int clamp : 1;
            unsigned int bias : 2;
            unsigned int pad1 : 16;
        } bits;
    };
    unsigned int *data = __GXData + arg0;
    union TevColorOpReg reg;

    reg.value = data[0x180 / 4];
    reg.bits.clamp = arg1;
    if (arg1 <= 1) {
        reg.bits.scale = arg3;
        reg.bits.bias = arg2;
    } else {
        reg.bits.scale = ((unsigned int)arg1) >> 1;
        reg.bits.bias = 3;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    reg.bits.arg4 = arg4;
    reg.bits.konst = arg5;
    *(volatile unsigned int *)0xCC008000 = reg.value;
    data[0x180 / 4] = reg.value;
    *(volatile unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetTevAlphaOp(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    union TevAlphaOpReg {
        unsigned int value;
        struct {
            unsigned int pad0 : 8;
            unsigned int konst : 2;
            unsigned int scale : 2;
            unsigned int arg4 : 1;
            unsigned int clamp : 1;
            unsigned int bias : 2;
            unsigned int pad1 : 16;
        } bits;
    };
    register union TevAlphaOpReg reg;
    register unsigned int *base = __GXData;
    register unsigned int *data = base + arg0;

    reg.value = data[0x1C0 / 4];
    reg.bits.clamp = arg1;
    if (arg1 <= 1) {
        reg.bits.scale = arg3;
        reg.bits.bias = arg2;
    } else {
        reg.bits.scale = ((unsigned int)arg1) >> 1;
        reg.bits.bias = 3;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    reg.bits.arg4 = arg4;
    reg.bits.konst = arg5;
    *(volatile unsigned int *)0xCC008000 = reg.value;
    data[0x1C0 / 4] = reg.value;
    *(volatile unsigned short *)((char *)base + 2) = 0;
}

void GXSetTevColor(s32 arg0, unsigned int *arg1) {
    unsigned int value = *arg1;
    unsigned int *fifo = (unsigned int *)0xCC008000;
    s32 reg = arg0 * 2 + 0xE0;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *fifo = (reg << 24) | (value >> 24) | ((value << 12) & 0xFF000);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *fifo = ((reg + 1) << 24) | ((value >> 8) & 0xFF) | ((value >> 4) & 0xFF000);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *fifo = ((reg + 1) << 24) | ((value >> 8) & 0xFF) | ((value >> 4) & 0xFF000);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *fifo = ((reg + 1) << 24) | ((value >> 8) & 0xFF) | ((value >> 4) & 0xFF000);
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetTevColorS10(s32 tevReg, void *color) {
    unsigned int r = ((unsigned int *)color)[0];
    unsigned int g = ((unsigned int *)color)[1];
    unsigned int *data = __GXData;
    s32 index = tevReg << 1;
    unsigned int value = ((index + 0xE0) << 24) | ((r >> 16) & 0x7FF) | ((g << 12) & 0x7FF000);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    value = ((index + 0xE1) << 24) | ((g >> 16) & 0x7FF) | ((r << 12) & 0x7FF000);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevKColor(s32 tevReg, unsigned int *color) {
    unsigned int index = tevReg << 1;
    unsigned int value = *color;
    unsigned int first = __rlwimi(__rlwimi(__rlwimi((index + 0xE0) << 24, value, 8, 24, 31), value, 12, 12, 19), 8, 20, 8, 11);
    unsigned int second = __rlwimi(__rlwimi(__rlwimi((index + 0xE1) << 24, value, 24, 24, 31), value, 28, 12, 19), 8, 20, 8, 11);
    unsigned int *data = __GXData;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = first;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = second;
    *(unsigned short *)((char *)data + 2) = 0;
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
    unsigned char *base = (unsigned char *)__GXData;
    unsigned int *entry = (unsigned int *)(base + arg0 * 4);
    unsigned int value = entry[0x1C0 / 4];
    value = __rlwimi(value, arg1, 0, 30, 31);
    value = __rlwimi(value, arg2, 2, 28, 29);
    entry[0x1C0 / 4] = value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = entry[0x1C0 / 4];
    *(unsigned short *)(base + 2) = 0;
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
    u32 offset1;
    u32 offset0;
    u32 index2;
    unsigned int *table;
    unsigned int *data;

    offset0 = (u32)index << 3;
    index2 = (u32)index << 1;
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
        u32 value;
        struct {
            u32 top : 8;
            u32 bias : 24;
        } bits;
    } first;
    union {
        u32 value;
        struct {
            u32 top : 8;
            u32 reserved : 20;
            u32 op : 2;
            u32 mode : 2;
        } bits;
    } second;
    s32 zmode;

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

    *(volatile unsigned char *)0xCC008000 = 0x61;
    second.value = 0;
    second.bits.mode = zmode;
    *(volatile unsigned int *)0xCC008000 = first.value;
    second.bits.op = op;
    second.bits.top = 0xF5;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = second.value;
    *(volatile unsigned short *)((char *)__GXData + 2) = 0;
}

extern unsigned int lbl_80303C80[];
void GXSetTevOrder(unsigned int stage, int texCoord, int texMap, int color) {
    unsigned int *data = __GXData;
    unsigned int *bp = (unsigned int *)((char *)data + 0x150 + ((stage + (stage >> 31)) & ~1) * 4);
    unsigned int tev;
    int coord = texCoord;
    unsigned int map = texMap;
    unsigned int colorSel = color;
    data[0x5a4 / 4 + stage] = texMap;
    if (coord >= 8) {
        coord = 0;
        data[0x5e8 / 4] &= ~(1 << stage);
    } else {
        data[0x5e8 / 4] |= 1 << stage;
    }
    if (stage & 1) {
        tev = bp[0] & ~0x7000;
        tev |= (map & 0xFF) << 12;
        tev = (tev & ~0x38000) | (coord << 15);
        bp[0] = tev;
        tev = (tev & ~0x380000) | ((colorSel == 0xFF ? 7 : lbl_80303C80[colorSel]) << 19);
        bp[0] = tev;
        tev = (tev & ~0x40000) | ((map != 0xFF && !(map & 0x100)) << 18);
        bp[0] = tev;
    } else {
        tev = bp[0] & ~7;
        tev |= (map & 0xFF);
        tev = (tev & ~0x38) | (coord << 3);
        bp[0] = tev;
        tev = (tev & ~0x380) | ((colorSel == 0xFF ? 7 : lbl_80303C80[colorSel]) << 7);
        bp[0] = tev;
        tev = (tev & ~0x40) | ((map != 0xFF && !(map & 0x100)) << 6);
        bp[0] = tev;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = bp[0];
    *(volatile unsigned short *)((char *)data + 2) = 0;
    data[0x5fc / 4] |= 1;
}

void GXSetNumTevStages(s32 count) {
    struct {
        unsigned int pad : 18;
        signed int stages : 4;
        unsigned int rest : 10;
    } *fields = (void *)&__GXData[0x254 / 4];

    fields->stages = count - 1;
    __GXData[0x5FC / 4] |= 4;
}

void GXSetFogRangeAdj(int enable, u16 center, const u16 *table) {
    u32 fogRangeReg;
    u32 fogRangeRegK;
    s32 i;

    if (enable) {
        for (i = 0; i < 10; i += 2) {
            fogRangeRegK = 0;
            fogRangeRegK = __rlwimi(fogRangeRegK, table[i], 0, 20, 31);
            fogRangeRegK = __rlwimi(fogRangeRegK, table[i + 1], 12, 8, 19);
            fogRangeRegK = __rlwimi(fogRangeRegK, 0xE9 + (i / 2), 24, 0, 7);
            *(volatile u8 *)0xCC008000 = 0x61;
            *(volatile u32 *)0xCC008000 = fogRangeRegK;
        }
    }
    fogRangeReg = 0;
    fogRangeReg = __rlwimi(fogRangeReg, center + 342, 0, 22, 31);
    fogRangeReg = __rlwimi(fogRangeReg, enable, 10, 21, 21);
    fogRangeReg = __rlwimi(fogRangeReg, 0xE8, 24, 0, 7);
    *(volatile u8 *)0xCC008000 = 0x61;
    *(volatile u32 *)0xCC008000 = fogRangeReg;
    *(volatile u16 *)((u8 *)__GXData + 2) = 0;
}

void GXSetBlendMode(s32 type, s32 src, s32 dst, s32 op) {
    unsigned int *data = __GXData;
    unsigned int value;
    value = data[0x220 / 4];
    value = (value & ~0x800) | ((__cntlzw(type - 3) << 6) & 0x800);
    value = (value & ~1) | (type & 1);
    value = (value & ~2) | (((unsigned int)__cntlzw(type - 2) >> 4) & 2);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = (value & ~0xF000) | ((op << 12) & 0xF000);
    value = (value & ~0x700) | ((src << 8) & 0x700);
    value = (value & ~0xE0) | ((dst << 5) & 0xE0);
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x220 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
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
    unsigned int *data = __GXData;
    unsigned int value;
    value = data[0x220 / 4];
    value = (value & 0xFFFFFFEF) | ((enable & 1) << 4);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x220 / 4] = value;
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
    unsigned int * const gx = __GXData;
    unsigned int * const table = (unsigned int *)lbl_80303CA8;
    unsigned int offset = pixelFmt * 4;
    unsigned int old = gx[0x22C / 4];
    unsigned int value = old;
    value = __rlwimi(value, table[pixelFmt], 0, 29, 31);
    value = __rlwimi(value, zFmt, 3, 26, 28);
    gx[0x22C / 4] = value;
    if (old != value) {
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = gx[0x22C / 4];
        gx[0x254 / 4] = __rlwimi(gx[0x254 / 4], __cntlzw(pixelFmt - 2), 4, 22, 22);
        gx[0x5FC / 4] |= 4;
    }
    if (table[pixelFmt] == 4) {
        unsigned int dstAlpha = gx[0x224 / 4];
        dstAlpha = __rlwimi(dstAlpha, pixelFmt - 4, 9, 21, 22);
        dstAlpha = __rlwimi(dstAlpha, 0x42, 24, 0, 7);
        gx[0x224 / 4] = dstAlpha;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = gx[0x224 / 4];
    }
    *(volatile u16 *)((u8 *)gx + 2) = 0;
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
    unsigned int *data;
    unsigned int value = 0;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = __rlwimi(value, odd, 0, 31, 31);
    value = __rlwimi(value, even, 1, 30, 30);
    data = __GXData;
    value = __rlwimi(value, 0x44, 24, 0, 7);
    *(volatile unsigned int *)0xCC008000 = value;
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetFieldMode(s32 mode, s32 field) {
    unsigned int *data = __GXData;
    unsigned int value = data[0x7C / 4];
    value = (value & ~0x400000) | ((field << 22) & 0x400000);
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
    struct DisplayListStorage {
        unsigned char display[0x28];
        unsigned char padding[0x58];
        unsigned char savedGXData[0x600];
        unsigned char oldFifo[0x28];
    };
    struct DisplayListStorage *fifo = (struct DisplayListStorage *)lbl_8037C108;
    u8 wrap;
    void *data;
    void *data2;
    int interruptState;
    unsigned int saved;
    GXGetCPUFifo(fifo->display);
    wrap = GXGetFifoWrap(fifo->display);
    GXSetCPUFifo(fifo->oldFifo);
    data = __GXData;
    if (*((u8 *)data + 0x5F9) != 0) {
        interruptState = OSDisableInterrupts();
        data2 = *(unsigned int * volatile *)&__GXData;
        saved = *(unsigned int *)((u8 *)data2 + 8);
        memcpy(data2, fifo->savedGXData, 0x600);
        *(unsigned int *)((u8 *)data2 + 8) = saved;
        ((void (*)(int))OSRestoreInterrupts)(interruptState);
    }
    *((u8 *)data + 0x5F8) = 0;
    if (wrap == 0) {
        return GXGetFifoCount(fifo->display);
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
    f64 *src = (f64 *)((u8 *)__GXData + 0x52C);
    volatile f64 *fifo = (volatile f64 *)0xCC008000;
    volatile u8 *fifo8 = (volatile u8 *)fifo;
    volatile u32 *fifo32 = (volatile u32 *)fifo;

    fifo8[0] = 0x10;
    fifo32[0] = 0x61020;
    *fifo = *(src + 0);
    *fifo = *(src + 1);
    *fifo = *(src + 2);
    fifo32[0] = *(u32 *)((u8 *)__GXData + 0x528);
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
    f64 pairs[6];
    volatile f64 *fifo = (volatile f64 *)0xCC008000;
    pairs[0] = *(const f64 *)&mtx[0][0];
    pairs[1] = *(const f64 *)&mtx[0][2];
    pairs[2] = *(const f64 *)&mtx[1][0];
    pairs[3] = *(const f64 *)&mtx[1][2];
    pairs[4] = *(const f64 *)&mtx[2][0];
    pairs[5] = *(const f64 *)&mtx[2][2];
    *(volatile u8 *)0xCC008000 = 0x10;
    *(volatile u32 *)0xCC008000 = (id << 2) | 0xB0000;
    *fifo = pairs[0];
    *fifo = pairs[1];
    *fifo = pairs[2];
    *fifo = pairs[3];
    *fifo = pairs[4];
    *fifo = pairs[5];
}

#pragma push
#pragma paired_single on
#pragma paired on
void GXLoadNrmMtxImm(const f32 mtx[3][4], u32 id) {
    f64 row0, row1, row2;
    f32 tail0, tail1, tail2;
    u32 address;
    address = id * 3 + 0x400;
    *(volatile u8 *)0xCC008000 = 0x10;
    *(volatile u32 *)0xCC008000 = address | 0x80000;
    row0 = *(const volatile f64 *)&mtx[0][0];
    tail0 = *(const volatile f32 *)&mtx[0][2];
    row1 = *(const volatile f64 *)&mtx[1][0];
    tail1 = *(const volatile f32 *)&mtx[1][2];
    row2 = *(const volatile f64 *)&mtx[2][0];
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
    volatile const f64 *src = (volatile const f64 *)mtx;
    volatile f64 *fifo = (volatile f64 *)0xCC008000;

    addr = id >= 0x40 ? (id - 0x40) * sizeof(f32) + 0x500 : id * 4 + (u64)0;
    num = type == 1 ? (u64)(2 * 4) : 3 * 4;
    *(volatile unsigned char *)0xCC008000 = 0x10;
    *(volatile unsigned int *)0xCC008000 = ((num - 1) << 16) | addr;

    if (type == 0) {
        f64 f0 = src[5];
        f64 f1 = src[4];
        f64 f2 = src[3];
        f64 f3 = src[2];
        f64 f4 = src[1];
        f64 f5 = src[0];
        fifo[0] = f5;
        fifo[0] = f4;
        fifo[0] = f3;
        fifo[0] = f2;
        fifo[0] = f1;
        fifo[0] = f0;
    } else {
        f64 f0 = src[3];
        f64 f1 = src[2];
        f64 f2 = src[1];
        f64 f3 = src[0];
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
    union ScissorReg {
        unsigned int value;
        struct {
            unsigned int pad0 : 9;
            unsigned int x : 11;
            unsigned int pad1 : 1;
            unsigned int y : 11;
        } bits;
    } topLeft, bottomRight;
    unsigned int *data = __GXData;
    s32 left = arg0 + 0x156;
    s32 top = arg1 + 0x156;
    s32 right;
    s32 bottom;

    topLeft.value = data[0x148 / 4];
    topLeft.bits.y = top;
    topLeft.bits.x = left;
    data[0x148 / 4] = topLeft.value;

    right = left + arg2;
    bottom = top + arg3;
    right -= 1;
    bottom -= 1;
    bottomRight.value = data[0x14C / 4];
    bottomRight.bits.y = bottom;
    bottomRight.bits.x = right;
    data[0x14C / 4] = bottomRight.value;

    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x148 / 4];
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x14C / 4];
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetScissorBoxOffset(s32 x, s32 y) {
    register u32 yAdjusted;
    union {
        u32 value;
        struct {
            unsigned int tag : 8;
            unsigned int reserved : 4;
            unsigned int y : 10;
            unsigned int x : 10;
        } bits;
    } reg;

    reg.value = 0;
    reg.bits.x = ((u32)(x + 0x156)) >> 1;
    *(volatile u8 *)0xCC008000 = 0x61;
    yAdjusted = (u32)(y + 0x156);
    reg.bits.y = yAdjusted >> 1;
    reg.bits.tag = 0x59;
    *(volatile u32 *)0xCC008000 = reg.value;
    *(volatile u16 *)((u8 *)__GXData + 2) = 0;
}

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

void GXClearGPMetric(void) {
    __cpReg[2] = 4;
}

void KPADSetBtnRepeat(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    volatile unsigned short *cp;
    unsigned int first, second, low;
    cp=__cpReg; first=cp[0x42/2]; second=first;
    for (;;) { low=cp[0x40/2]; second=cp[0x42/2]; if (second==first) break; }
    *arg2=(second<<16)|low;
    cp=__cpReg; first=cp[0x46/2]; second=first;
    for (;;) { low=cp[0x44/2]; second=cp[0x46/2]; if (second==first) break; }
    *arg3=(second<<16)|low;
    cp=__cpReg; first=cp[0x4A/2]; second=first;
    for (;;) { low=cp[0x48/2]; second=cp[0x4A/2]; if (second==first) break; }
    *arg0=(second<<16)|low;
    cp=__cpReg; first=cp[0x4E/2]; second=first;
    for (;;) { low=cp[0x4C/2]; second=cp[0x4E/2]; if (second==first) break; }
    *arg1=(second<<16)|low;
}
typedef struct { unsigned int unk[9]; unsigned char unk24[3]; } GXSetCPUFifoObj;
