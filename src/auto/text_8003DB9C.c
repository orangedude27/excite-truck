// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
  typedef signed long s32;
  typedef float f32;
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
s32 __GXDefaultTlutRegionCallback(unsigned int region) {
    if (region >= 0x14) {
        return 0;
    }
    return (s32)((char *)__GXData + region * 0x10 + 0x3D8);
}

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

typedef struct { unsigned int mode0; unsigned int mode1; } __GXTexObjInt;
static unsigned char GX2HWFiltConv[6] = { 0x00, 0x04, 0x01, 0x05, 0x02, 0x06 };
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

void GXSetVtxAttrFmtv(int fmt, const GXVtxAttrFmtList *list) {
    unsigned int *vatA = (unsigned int *)((char *)__GXData + 0x1C) + fmt;
    unsigned int *vatB = (unsigned int *)((char *)__GXData + 0x3C) + fmt;
    unsigned int *vatC = (unsigned int *)((char *)__GXData + 0x5C) + fmt;

    for (; list->attr != 0xFF; list++) {
        switch (list->attr) {
        case 9:
            *vatA = __rlwimi(*vatA, list->compCnt, 0, 31, 31);
            *vatA = __rlwimi(*vatA, list->compType, 1, 28, 30);
            *vatA = __rlwimi(*vatA, list->shift, 4, 23, 27);
            break;
        case 10:
        case 25:
            *vatA = __rlwimi(*vatA, list->compType, 10, 19, 21);
            if (list->compCnt == 2) {
                *vatA = __rlwimi(*vatA, 1, 9, 22, 22);
                *vatA = __rlwimi(*vatA, 1, 31, 0, 0);
            } else {
                *vatA = __rlwimi(*vatA, list->compCnt, 9, 22, 22);
                *vatA = __rlwimi(*vatA, 0, 31, 0, 0);
            }
            break;
        case 11:
            *vatA = __rlwimi(*vatA, list->compCnt, 13, 18, 18);
            *vatA = __rlwimi(*vatA, list->compType, 14, 15, 17);
            break;
        case 12:
            *vatA = __rlwimi(*vatA, list->compCnt, 17, 14, 14);
            *vatA = __rlwimi(*vatA, list->compType, 18, 11, 13);
            break;
        case 13:
            *vatA = __rlwimi(*vatA, list->compCnt, 21, 10, 10);
            *vatA = __rlwimi(*vatA, list->compType, 22, 7, 9);
            *vatA = __rlwimi(*vatA, list->shift, 25, 2, 6);
            break;
        case 14:
            *vatB = __rlwimi(*vatB, list->compCnt, 0, 31, 31);
            *vatB = __rlwimi(*vatB, list->compType, 1, 28, 30);
            *vatB = __rlwimi(*vatB, list->shift, 4, 23, 27);
            break;
        case 15:
            *vatB = __rlwimi(*vatB, list->compCnt, 9, 22, 22);
            *vatB = __rlwimi(*vatB, list->compType, 10, 19, 21);
            *vatB = __rlwimi(*vatB, list->shift, 13, 14, 18);
            break;
        case 16:
            *vatB = __rlwimi(*vatB, list->compCnt, 18, 13, 13);
            *vatB = __rlwimi(*vatB, list->compType, 19, 10, 12);
            *vatB = __rlwimi(*vatB, list->shift, 22, 5, 9);
            break;
        case 17:
            *vatB = __rlwimi(*vatB, list->compCnt, 27, 4, 4);
            *vatB = __rlwimi(*vatB, list->compType, 28, 1, 3);
            *vatC = __rlwimi(*vatC, list->shift, 0, 27, 31);
            break;
        case 18:
            *vatC = __rlwimi(*vatC, list->compCnt, 5, 26, 26);
            *vatC = __rlwimi(*vatC, list->compType, 6, 23, 25);
            *vatC = __rlwimi(*vatC, list->shift, 9, 18, 22);
            break;
        case 19:
            *vatC = __rlwimi(*vatC, list->compCnt, 14, 17, 17);
            *vatC = __rlwimi(*vatC, list->compType, 15, 14, 16);
            *vatC = __rlwimi(*vatC, list->shift, 18, 9, 13);
            break;
        case 20:
            *vatC = __rlwimi(*vatC, list->compCnt, 23, 8, 8);
            *vatC = __rlwimi(*vatC, list->compType, 24, 5, 7);
            *vatC = __rlwimi(*vatC, list->shift, 27, 0, 4);
            break;
        }
    }

    __GXData[0x5FC / 4] |= 0x10;
    *((unsigned char *)__GXData + 0x5FB) |= (unsigned char)(1 << (unsigned char)fmt);
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
    unsigned int *data = __GXData;
    data[0x254 / 4] = (data[0x254 / 4] & 0x0FFFFFFF) | (value & 0xF0000000);
    data[0x5FC / 4] |= 0x200;
    data[0x5FC / 4] |= 4;
}

void GXSetMisc(s32 which, unsigned short value) {
    if (which == 2) {
        *((unsigned char *)__GXData + 0x5F9) = value != 0;
        return;
    }
    if (which < 2) {
        if (which == 0) {
            return;
        }
        if (which < 0) {
            return;
        }
    } else if (which >= 4) {
        return;
    }
    if (which == 1) {
        unsigned int *data = __GXData;
        data[1] = value;
        *(unsigned short *)data = (unsigned short)__cntlzw(value & 0xFFFF) >> 5;
        *(unsigned short *)((char *)data + 2) = 1;
        if (value != 0) {
            data[0x5FC / 4] |= 8;
        }
        return;
    }
    *((unsigned char *)__GXData + 0x5FA) = value != 0;
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
        OSClearContext(local);
        OSSetCurrentContext(local);
        ((void (*)(unsigned short))lbl_8055D978)(value);
        OSClearContext(local);
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

void GXSetLineWidth(s32 width, s32 format) {
    unsigned int *data = __GXData;
    data[0x7C / 4] = (data[0x7C / 4] & ~0x700FF) | (width & 0xFF) | ((format << 16) & 0x70000);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x7C / 4];
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetPointSize(unsigned char size, unsigned char format) {
    unsigned int *data = __GXData;
    unsigned int value = data[0x7C / 4];
    value = (value & ~0x38FF00) | (size << 8) | (format << 19);
    data[0x7C / 4] = value;
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
    unsigned int *data = __GXData;
    unsigned int field = ((mode >> 1) & 1) | ((mode << 1) & 2);
    data[0x254 / 4] = (data[0x254 / 4] & ~0xC000) | (field << 14);
    data[0x5FC / 4] |= 4;
}

void GXSetCoPlanar(s32 enable) {
    unsigned int *data = __GXData;
    data[0x254 / 4] = (data[0x254 / 4] & 0xFFF7FFFF) | ((enable & 1) << 19);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = 0xFE080000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = data[0x254 / 4];
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
    unsigned int *data = __GXData;
    data[0x240 / 4] = 0x49000000 | ((x & 0x3FF) << 0) | ((y & 0x3FF) << 10);
    data[0x244 / 4] = 0x4A000000 | (((width - 1) & 0x3FF) << 0) | (((height - 1) & 0x3FF) << 10);
}

void GXSetDispCopyDst(s32 value) {
    unsigned int result = 0;
    result = (value << 1) & 0xFFFE;
    result >>= 5;
    __GXData[0x238 / 4] = result | 0x4D000000;
}

void GXSetDispCopyFrame2Field(s32 value) {
    unsigned int *data = __GXData;
    data[0x23C / 4] = (data[0x23C / 4] & ~(3U << 12)) | ((value & 3) << 12);
    data[0x24C / 4] = data[0x24C / 4] & ~(3U << 12);
}

void GXSetCopyClamp(s32 value) {
    unsigned int *data = __GXData;
    unsigned int a, b;
    a = data[0x23C / 4];
    a = (a & ~1) | (value & 1);
    a = (a & ~2) | (value & 2);
    data[0x23C / 4] = a;
    b = data[0x24C / 4];
    b = (b & ~1) | (value & 1);
    b = (b & ~2) | (value & 2);
    data[0x24C / 4] = b;
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

void GXSetNumChans(s32 num) {
    unsigned int *data = __GXData;
    data[0x254 / 4] = (data[0x254 / 4] & ~(7 << 4)) | ((num & 7) << 4);
    data[0x5FC / 4] |= 0x01000004;
}

void GXSetChanCtrl(s32 chan, s32 enable, s32 matColor, s32 ambColor, s32 lightMask, s32 diffFn, s32 attnFn) {
    unsigned int *data;
    unsigned int value = 0;
    unsigned int idx = chan & 3;
    unsigned int attn = diffFn;
    value |= (enable << 1);
    value |= ambColor;
    value |= matColor << 6;
    if (attnFn == 0) attn = 0;
    value |= attn << 7;
    value |= ((2 - attnFn) | (attnFn - 2)) << 10;
    value |= (-attnFn | attnFn) << 11;
    value |= lightMask << 2;
    value |= lightMask << 7;
    data = __GXData;
    data[(0xB8 / 4) + idx] = value;
    data[0x5FC / 4] |= 0x1000 << idx;
    if (chan == 4) {
        data[0xC0 / 4] = value;
        data[0x5FC / 4] |= 0x5000;
        return;
    }
    if (chan == 5) {
        data[0xC4 / 4] = value;
        data[0x5FC / 4] |= 0xA000;
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
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
    case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23:
    case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
    case 32: case 33: case 34: case 35: case 36: case 37: case 38: case 39:
    case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47:
    case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
    case 56: case 57: case 58: case 59: case 60:
        shift_x = 3; shift_y = 3; break;
    default:
        shift_x = 0; shift_y = 0; break;
    }
    if (width == 0) width = 1;
    if (height == 0) height = 1;
    *tiles_x = (width + (1 << shift_x) - 1) >> shift_x;
    *tiles_y = (height + (1 << shift_y) - 1) >> shift_y;
    *compressed = (format == 6) || (format == 0x16);
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

void GXInitTexObjLOD(void *obj, s32 min_filt, s32 mag_filt, f32 min_lod, f32 max_lod, f32 lod_bias, s32 bias_clamp, s32 do_edge_lod, s32 max_aniso) {
    s32 *t = (s32 *)obj;
    s32 lbias;
    s32 lmin;
    s32 lmax;

    if (lod_bias < -4.0f) {
        lod_bias = -4.0f;
    } else if (lod_bias >= 4.0f) {
        lod_bias = 3.99f;
    }
    lbias = 32.0f * lod_bias;
    t[0] = (t[0] & ~0x1FE00) | ((lbias << 9) & 0x1FE00);
    t[0] = (t[0] & ~0x10) | (((unsigned int)__cntlzw(mag_filt - 1) >> 1) & 0x10);
    t[0] = (t[0] & ~0xE0) | ((GX2HWFiltConv[min_filt] << 5) & 0xE0);
    t[0] = (t[0] & ~0x100) | ((__cntlzw(max_aniso) << 3) & 0x100);
    t[0] = (t[0] & 0xFFF9FFFF) | ((max_aniso << 0x13) & 0x180000);
    t[0] = (t[0] & ~0x200000) | ((bias_clamp << 0x15) & 0x200000);
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
    t[1] = (t[1] & ~0xFF) | (lmin & 0xFF);
    t[1] = (t[1] & ~0xFF00) | ((lmax << 8) & 0xFF00);
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
    unsigned int *data = *(unsigned int * volatile *)&__GXData;
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
    unsigned int value = 0;
    value = (value & ~0x3FF) | (((tmem_addr - 0x80000) << 23) & 0x3FF);
    value = (value & ~0x1FFC00) | ((tlut_name << 10) & 0x1FFC00);
    value = (value & ~0xFF000000) | 0x65000000;
    *region = value;
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

void GXSetNumIndStages(unsigned int value) {
    unsigned int *data = __GXData;
    unsigned int old = data[0x254 / 4];
    old = (old & ~0x70000) | ((value << 16) & 0x70000);
    data[0x254 / 4] = old;
    data[0x5FC / 4] |= 6;
}

extern void GXSetTevIndirect(int, int, int, int, int, int, int, int);
void GXSetTevDirect(int arg0) {
    GXSetTevIndirect(arg0, 0, 0, 0, 0, 0, 0, 0);
}

void __GXUpdateBPMask(void) {}

extern unsigned int lbl_80303C30;
void GXSetTevOp(int stage, int mode) {
    unsigned int *color;
    unsigned int *alpha;
    unsigned int *base = &lbl_80303C30;
    unsigned int *data = __GXData;
    unsigned int *tev;
    unsigned int value;
    if (stage == 0) { color = base + mode; alpha = base + 10 + mode; }
    else { color = base + 5 + mode; alpha = base + 15 + mode; }
    tev = data + stage;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = (tev[0x180 / 4] & 0xFF000000) | (*color & 0xFFFFFF);
    *(volatile unsigned int *)0xCC008000 = value;
    tev[0x180 / 4] = value;
    value = (tev[0x1C0 / 4] & 0xF000000F) | (*alpha & 0x0FFFFFF0);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    tev[0x1C0 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevColorIn(int stage, int a, int b, int c, int d) {
    unsigned int *data = __GXData;
    unsigned int *tev = data + stage;
    unsigned int value = tev[0x180 / 4];
    value = (value & ~0xF000) | ((a << 12) & 0xF000);
    value = (value & ~0xF00) | ((b << 8) & 0xF00);
    value = (value & ~0xF0) | ((c << 4) & 0xF0);
    value = (value & ~0xF) | (d & 0xF);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    tev[0x180 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevAlphaIn(int stage, int a, int b, int c, int d) {
    unsigned int *data = __GXData;
    unsigned int *tev = data + stage;
    unsigned int value = tev[0x1C0 / 4];
    value = (value & ~0xE000) | ((a << 13) & 0xE000);
    value = (value & ~0x1C00) | ((b << 10) & 0x1C00);
    value = (value & ~0x380) | ((c << 7) & 0x380);
    value = (value & ~0x70) | ((d << 4) & 0x70);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    tev[0x1C0 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevColorOp(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    unsigned int *data = __GXData + arg0;
    unsigned int value = data[0x180 / 4];
    value = (value & ~0x40000) | ((arg1 << 18) & 0x40000);
    if (arg1 <= 1) {
        value = (value & ~0x300000) | ((arg3 << 20) & 0x300000);
        value = (value & ~0x30000) | ((arg2 << 16) & 0x30000);
    } else {
        value = (value & ~0x300000) | ((arg1 << 19) & 0x300000) | 0x30000;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = (value & ~0x80000) | ((arg4 << 19) & 0x80000);
    value = (value & ~0xC00000) | ((arg5 << 22) & 0xC00000);
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x180 / 4] = value;
    *(unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetTevAlphaOp(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    unsigned int *data = __GXData + arg0;
    unsigned int value = data[0x1C0 / 4];
    value = (value & ~0x40000) | ((arg1 << 18) & 0x40000);
    if (arg1 <= 1) {
        value = (value & ~0x300000) | ((arg3 << 20) & 0x300000);
        value = (value & ~0x30000) | ((arg2 << 16) & 0x30000);
    } else {
        value = (value & ~0x300000) | ((arg1 << 19) & 0x300000) | 0x30000;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = (value & ~0x80000) | ((arg4 << 19) & 0x80000);
    value = (value & ~0xC00000) | ((arg5 << 22) & 0xC00000);
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x1C0 / 4] = value;
    *(unsigned short *)((char *)__GXData + 2) = 0;
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
    unsigned int value = *color;
    unsigned int *data = __GXData;
    s32 index = tevReg << 1;
    unsigned int first = (index + 0xE0) << 24;
    unsigned int second = (index + 0xE1) << 24;
    first |= value >> 24;
    first |= value << 8;
    first |= value << 12;
    first |= 0x00800000;
    second |= value >> 8;
    second |= value << 12;
    second |= value << 28;
    second |= 0x00800000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = first;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = second;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetTevKColorSel(s32 arg0, s32 arg1) {
    register unsigned int *base = __GXData;
    register unsigned int *entry = (unsigned int *)((char *)base + ((arg0 * 2) & ~3));
    if (arg0 & 1) {
        entry[0x200 / 4] = (entry[0x200 / 4] & 0xFFFC1FFF) | (arg1 << 14);
    } else {
        entry[0x200 / 4] = (entry[0x200 / 4] & 0xFFFFFE0F) | (arg1 << 4);
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = entry[0x200 / 4];
    *(unsigned short *)((char *)base + 2) = 0;
}

void GXSetTevKAlphaSel(s32 arg0, s32 arg1) {
    register unsigned int *base = __GXData;
    register unsigned int *entry = (unsigned int *)((char *)base + ((arg0 * 2) & ~3));
    if (arg0 & 1) {
        entry[0x200 / 4] = (entry[0x200 / 4] & 0xFF07FFFF) | (arg1 << 19);
    } else {
        entry[0x200 / 4] = (entry[0x200 / 4] & 0xFFFFC1FF) | (arg1 << 9);
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = entry[0x200 / 4];
    *(unsigned short *)((char *)base + 2) = 0;
}

void GXSetTevSwapMode(s32 arg0, s32 arg1, s32 arg2) {
    unsigned int *base = __GXData;
    register unsigned int *entry = base + arg0;
    register unsigned int value = entry[0x1C0 / 4];
    value = (value & ~3) | (arg1 & 3);
    value = (value & ~0xC) | ((arg2 << 2) & 0xC);
    entry[0x1C0 / 4] = value;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = entry[0x1C0 / 4];
    *(unsigned short *)((char *)base + 2) = 0;
}

void GXSetTevSwapModeTable(s32 index, s32 rasSel, s32 texSel, s32 rasSel2, s32 texSel2) {
    unsigned int *data = __GXData;
    unsigned int *table = (unsigned int *)((char *)data + 0x200);
    unsigned int offset0 = index * 8;
    unsigned int offset1 = (index * 2 + 1) * 4;
    table[offset0 / 4] = (table[offset0 / 4] & ~0xF) | (rasSel & 3) | ((texSel << 2) & 0xC);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = table[offset0 / 4];
    table[offset1 / 4] = (table[offset1 / 4] & ~0xF) | (rasSel2 & 3) | ((texSel2 << 2) & 0xC);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = table[offset1 / 4];
    *(volatile unsigned short *)((char *)data + 2) = 0;
}

void GXSetAlphaCompare(s32 comp0, s32 ref0, s32 op, s32 comp1, s32 ref1) {
    unsigned int value = 0xF3000000;
    value |= ref0;
    value |= ref1 << 8;
    value |= comp0 << 16;
    value |= comp1 << 19;
    value |= op << 22;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    *(volatile unsigned short *)((char *)__GXData + 2) = 0;
}

void GXSetZTexture(s32 op, s32 format, s32 bias) {
    s32 zmode;
    unsigned int value;

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
    value = (bias & 0x00FFFFFF) | 0xF4000000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    value = (zmode & 3) | ((op << 2) & 0xC) | 0xF5000000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
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
    unsigned int *data = __GXData;
    data[0x254 / 4] = (data[0x254 / 4] & ~0x3C00) | ((count - 1) << 10);
    data[0x5FC / 4] |= 4;
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
    unsigned int *data = __GXData;
    unsigned int value;
    value = data[0x220 / 4];
    value = (value & ~8) | ((enable << 3) & 8);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x220 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetAlphaUpdate(s32 enable) {
    unsigned int *data = __GXData;
    unsigned int value;
    value = data[0x220 / 4];
    value = (value & ~0x10) | ((enable << 4) & 0x10);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x220 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetZMode(s32 enable, s32 func, s32 update) {
    unsigned int *data = __GXData;
    unsigned int value;
    value = data[0x228 / 4];
    value = (value & ~1) | (enable & 1);
    value = (value & ~0xE) | ((func << 1) & 0xE);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    value = (value & ~0x10) | ((update << 4) & 0x10);
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x228 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetDither(s32 enable) {
    unsigned int *data = __GXData;
    unsigned int value = data[0x220 / 4];
    value = (value & ~4) | (enable << 2);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x220 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetDstAlpha(s32 enable, s32 alpha) {
    unsigned int *data = __GXData;
    unsigned int value = data[0x224 / 4];
    value = (value & ~0xFF) | alpha;
    value = (value & ~0x100) | (enable << 8);
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    data[0x224 / 4] = value;
    *(unsigned short *)((char *)data + 2) = 0;
}

void GXSetFieldMask(s32 even, s32 odd) {
    unsigned int *data = __GXData;
    unsigned int value = (odd & 1) | ((even << 1) & 2) | 0x44000000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = value;
    *(unsigned short *)((char *)data + 2) = 0;
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
void __GXSetProjection(void) { volatile unsigned char *p=(volatile unsigned char*)0xCC008000; volatile unsigned int *q=(volatile unsigned int*)0xCC008000; p[0]=16; q[0]=0x61020; q[0]=__GXData[0x528/4]; }

void GXSetProjection(float *arg0, int arg1) {
    unsigned int *data = __GXData;
    data[0x528 / 4] = arg1;
    *(float *)((char *)data + 0x52C) = arg0[0];
    *(float *)((char *)data + 0x534) = arg0[5];
    *(float *)((char *)data + 0x53C) = arg0[10];
    *(float *)((char *)data + 0x540) = arg0[11];
    if (arg1 == 1) {
        *(float *)((char *)data + 0x530) = arg0[3];
        *(float *)((char *)data + 0x538) = arg0[7];
    } else {
        *(float *)((char *)data + 0x530) = arg0[2];
        *(float *)((char *)data + 0x538) = arg0[6];
    }
    data[0x5FC / 4] |= 0x08000000;
}

void GXSetProjectionv(float *arg0) {
 unsigned int *d=__GXData; int value;
 if(lbl_80560BC8 != arg0[0]) value=1; else value=0;
 d[0x528/4]=value;
 *(float*)((char*)d+0x52c)=arg0[1];
 *(float*)((char*)d+0x534)=arg0[2];
 *(float*)((char*)d+0x53c)=arg0[4];
 d[0x5fc/4]|=0x08000000;
}

void __GXSetViewport(void) {
 unsigned int *d=__GXData;
 float f2,f3,f0,f4,f5,f8,f9,f6,f1;
 f2=*(float*)((char*)d+0x550); f3=*(float*)((char*)d+0x54c);
 f0=*(float*)((char*)d+0x544); f4=*(float*)((char*)d+0x548);
 f5=f2*lbl_80560BCC; f8=-f2*lbl_80560BCC;
 f9=*(float*)((char*)d+0x558)* *(float*)((char*)d+0x560);
 f3=f3*lbl_80560BCC;
 f6=f0+f3; f1=f4+f5;
 *(volatile unsigned char*)0xCC008000=16;
 *(volatile unsigned int*)0xCC008000=0x5101a;
 *(volatile float*)0xCC008000=f3;
 *(volatile float*)0xCC008000=f8;
 *(volatile float*)0xCC008000=f9-(*(float*)((char*)d+0x554)* *(float*)((char*)d+0x560));
 *(volatile float*)0xCC008000=lbl_80560BD0+f6;
 *(volatile float*)0xCC008000=lbl_80560BD0+f1;
 *(volatile float*)0xCC008000=f9+*(float*)((char*)d+0x55c);
}

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

