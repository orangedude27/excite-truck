// gx — gx draw core ("gx: unhandled draw sync token", screenshots, visibility).
// Recovered TU window 0x802CE9FC..0x802D3ED4+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802D3ED4 (+ .ctors slot 0x802ED5C0) remains in
// auto/text_802D3ED4_.c pending a promotion pass.
#include <revolution/GX/GXTypes.h>
#include "revolution/GX/GXHardware.h"
typedef int M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
extern void GXLoadTexObj(void *, int);

#pragma dont_inline fn_802D1678
#pragma dont_inline fn_802CFF50
#pragma dont_inline fn_802CF104
#pragma dont_inline fn_802CF5D4
extern char lbl_8034BF80[];
extern void DCInvalidateRange(void *, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern unsigned long lbl_8055FD44;
extern int lbl_8055FD4C;
extern unsigned char lbl_8055FD50;
#pragma dont_inline fn_802D2ED8
#pragma dont_inline fn_802CFD74
#pragma dont_inline fn_802D1B58
extern int lbl_804C9760[];
#pragma small_data off
extern __declspec(section ".data") unsigned int lbl_804C9940;
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
  extern float lbl_80564F8C, lbl_80564F94, lbl_80564FCC, lbl_80564FDC;
  extern void *lbl_8055FDB0;
extern int lbl_8055FE24;
extern unsigned char lbl_804C9778[];
extern double lbl_80564FB0;
extern double fn_8002EF30(double);
extern unsigned long lbl_8055D0B8;
extern int lbl_8055D0BC;
extern int lbl_8055D0C0;
extern float lbl_80564F94, lbl_80564F9C, lbl_80564FC8, lbl_80564FD0;
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
// Render request block (0x804C5700, 16 bytes). The scene sets a field and marks
// the request pending; fn_802D2B0C compares it with the applied copy at
// 0x804C9930 and rebuilds the GX pipeline for the new mode.
//   +0x00 u8  request pending (cleared once applied)
//   +0x04 s32 pipeline mode (0 = scene default, see fn_802D2B0C)
//   +0x08 u8  add a second, modulated texture stage (GX_TEXMAP1)
//   +0x09 u8  detail pass: base texture * texture 3, raster color ignored
//   +0x0A u8  add the indirect (bump) texture stage
//   +0x0C u8  texcoord0 through GX_TEXMTX0 instead of GX_IDENTITY
//   +0x0D u8  alpha blend + indirect stage (fn_802D2684's bump pass)
extern unsigned char lbl_804C5700[12];
extern int fn_802E317C(const char *, ...);
extern int GXInitLightDir(unsigned short, unsigned short, unsigned long *);
extern float lbl_80564FAC, lbl_80564FA8, lbl_80564F88;
#pragma small_data off
extern char lbl_804C97D0;
extern char lbl_804C97D1;
extern char lbl_804C97D2;
extern char lbl_804C97D3;
extern char lbl_804C97D4;
extern char lbl_804C97D5;
extern char lbl_804C97D6;
extern char lbl_804C97D7;
extern char lbl_804C97D8;
#pragma small_data on
extern void GXSetTevColor(int, ...);
extern unsigned long fn_802CE9FC(int, int, int, int);
typedef struct { float x, y, z; } Vec_802D1C04;
// 3x3 matrix times vector (MTXMultVecSR shape); src/dst may alias.
static inline void mulVecSR_802D1C04(const float *m, const float *src, float *dst) {
    if (dst == src) {
        float x = src[2] * m[2] + (src[0] * m[0] + src[1] * m[1]);
        float y = src[2] * m[5] + (src[0] * m[3] + src[1] * m[4]);
        float z = src[2] * m[8] + (src[0] * m[6] + src[1] * m[7]);
        dst[0] = x;
        dst[1] = y;
        dst[2] = z;
    } else {
        float x = src[2] * m[2] + (src[0] * m[0] + src[1] * m[1]);
        float y = src[2] * m[5] + (src[0] * m[3] + src[1] * m[4]);
        float z = src[2] * m[8] + (src[0] * m[6] + src[1] * m[7]);
        dst[0] = x;
        dst[1] = y;
        dst[2] = z;
    }
}
extern float lbl_80564F90;
// 3x3 rotation followed by a translation.
typedef struct { float m[9]; } Mtx33_802D1C04;
typedef struct { Mtx33_802D1C04 r; Vec_802D1C04 t; } Xform_802D1C04;
typedef struct { float m[2][4]; } Mtx24_802D1C04;
static inline void mtx33Transpose_802D1C04(float *m) {
    float t;
    t = m[1]; m[1] = m[3]; m[3] = t;
    t = m[2]; m[2] = m[6]; m[6] = t;
    t = m[5]; m[5] = m[7]; m[7] = t;
}
// Inverse of a rigid transform: transposed rotation, negated rotated translation.
static inline void xformInverse_802D1C04(Xform_802D1C04 *dst, const Xform_802D1C04 *src) {
    dst->r = src->r;
    mtx33Transpose_802D1C04(dst->r.m);
    if (&dst->t == &src->t) {
        float x = src->t.z * src->r.m[2] + (src->t.x * src->r.m[0] + src->t.y * src->r.m[1]);
        float y = src->t.z * src->r.m[5] + (src->t.x * src->r.m[3] + src->t.y * src->r.m[4]);
        float z = src->t.z * src->r.m[8] + (src->t.x * src->r.m[6] + src->t.y * src->r.m[7]);
        dst->t.x = x;
        dst->t.y = y;
        dst->t.z = z;
    } else {
        float x = src->t.z * src->r.m[2] + (src->t.x * src->r.m[0] + src->t.y * src->r.m[1]);
        float y = src->t.z * src->r.m[5] + (src->t.x * src->r.m[3] + src->t.y * src->r.m[4]);
        float z = src->t.z * src->r.m[8] + (src->t.x * src->r.m[6] + src->t.y * src->r.m[7]);
        dst->t.x = x;
        dst->t.y = y;
        dst->t.z = z;
    }
    dst->t.x *= lbl_80564F90;
    dst->t.y *= lbl_80564F90;
    dst->t.z *= lbl_80564F90;
}

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FD3C;
#pragma dont_inline on
unsigned long fn_802CE9FC(int r, int g, int b, int a) {
    /* Pack four byte color components into a 32-bit GXColor word (r in the high byte). */
    unsigned char bytes[4];
    bytes[0] = (unsigned char)r;
    bytes[1] = (unsigned char)g;
    bytes[2] = (unsigned char)b;
    bytes[3] = (unsigned char)a;
    return *(unsigned long *)bytes;
}

unsigned char fn_802CEA1C(unsigned int argbColor) {
    /* Convert a packed ARGB color word to GX's RGBA byte order: split out its four
       bytes and repack them (rotated by one byte) through fn_802CE9FC. */
    return ((unsigned char (*)(unsigned char, unsigned char, unsigned char, unsigned char))fn_802CE9FC)(
        (unsigned char)(argbColor >> 16),
        (unsigned char)(argbColor >> 8),
        (unsigned char)argbColor,
        (unsigned char)(argbColor >> 24));
}

/* Allocate and clear the EFB copy buffer based on the current render mode dimensions. */
void fn_802CEA34(void) {
    unsigned char *renderMode = (unsigned char *)lbl_8055FD64;
    unsigned short fbWidth = *(unsigned short *)(renderMode + 4);
    unsigned short efbHeight = *(unsigned short *)(renderMode + 8);
    int rowBytes = (fbWidth + 0xF) & 0xFFF0;
    int bufferSize = rowBytes * efbHeight;
    void *copyBuffer;

    lbl_804C9760[2] = fbWidth;
    lbl_804C9760[3] = *(unsigned short *)(renderMode + 8);
    lbl_804C9760[4] = 2;
    copyBuffer = ((void *(*)(int, void *, int, unsigned short, void *))fn_8012850C)(
        bufferSize * 2, &lbl_8055D0F0, bufferSize, fbWidth, renderMode);
    lbl_804C9760[0] = (int)copyBuffer;
    memset(copyBuffer, 0, bufferSize * 2);
    lbl_804C9760[1] = lbl_804C9760[0];
}

#pragma dont_inline reset

/* Draws the Clip Clocks indicator depending on TV format and connection status. */
void fn_802CEAC4(void) {
    extern int VIGetTvFormat(void), fn_802E9A1C(void), fn_8005AD9C(void);
    extern void fn_802E30C8(const char *, ...);
    extern void GXDrawCylinder(void *, void *, int, int);
    extern char lbl_8034BD18[], lbl_803038D8[], lbl_80303914[], lbl_80303950[], lbl_8030398C[], lbl_803039C8[];
    extern void *lbl_8055FD64;
    extern unsigned char lbl_804C9724[];
    char *strBase = lbl_8034BD18;
    int tvFormat = VIGetTvFormat();
    switch (tvFormat) {
    case 0:
        if (fn_802E9A1C() == 0 || fn_8005AD9C() == 0) {
            fn_802E30C8(strBase + 0xA0);
            lbl_8055FD64 = lbl_803038D8;
        } else {
            fn_802E30C8(strBase + 0xB0);
            lbl_8055FD64 = lbl_80303914;
        }
        break;
    case 1:
        fn_802E30C8(strBase + 0xC0);
        lbl_8055FD64 = lbl_8030398C;
        break;
    case 5:
        fn_802E30C8(strBase + 0xCC);
        lbl_8055FD64 = lbl_803039C8;
        break;
    case 2:
        fn_802E30C8(strBase + 0xE0);
        lbl_8055FD64 = lbl_80303950;
        break;
    default:
        fn_802E317C(strBase + 0xF0);
        break;
    }
    GXDrawCylinder(lbl_8055FD64, lbl_804C9724, 0, 0x10);
    lbl_8055FD64 = lbl_804C9724;
    *(unsigned short *)(lbl_804C9724 + 0xE) += 0xA;
    *(unsigned short *)(lbl_804C9724 + 0xA) -= 5;
}

extern void fn_802D9C4C(void);
/* GX draw-sync callback (RealName: GX_BlankOnShutdown): when reason is 1,
   unregister the audio DMA and draw-sync callbacks, blank the screen and wait
   for the retrace, then return 0. */
int fn_802CEC04(int reason) {
    if (reason == 1) {
        fn_802D9C4C();
        GXSetDrawSyncCallback();
        VISetBlack(1);
        VIFlush();
        VIWaitForRetrace();
    }
    return 0;
}

/* Signal completion of the GX operation: set the flag that fn_802CFDE0
   busy-waits on (cleared to 0 by fn_802CEC50 case 1). */
void fn_802CEC44(void) {
#define sGxSyncDone lbl_8055FD3C
    sGxSyncDone = 1;
#undef sGxSyncDone
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
    float value;
    switch (arg0) {
    case 1:
        now = fn_802E2C9C();
        lbl_8055FD14 = (unsigned int)now;
        lbl_8055FD10 = (unsigned int)(now >> 32);
        lbl_8055FD3C = 0;
        break;
    case 2:
        now = fn_802E2C9C();
        delta = now - (lbl_8055FD14 | ((unsigned long long)lbl_8055FD10 << 32));
        value = lbl_80564F80 * fn_8002FD54((unsigned int)(delta >> 32), (unsigned int)delta);
        lbl_8055D0B0 = value;
        lbl_8055D0B4 = value + lbl_80564F84 * (lbl_8055D0B4 - value);
        fn_802D3900();
        break;
    default:
        fn_802E317C(lbl_8034BE20, arg0);
        break;
    }
}

/* Cycles lbl_8055D0F6 through values 1..2 until it equals targetIndex, calling
 * fn_802CEC50 for each step. */
void fn_802CECF4(unsigned int targetIndex) {
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
    } while ((unsigned short)lbl_8055D0F6 != targetIndex);
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

extern void KPADSetBtnRepeat(int *, int *, int *, int *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* Reports the GX GP status flags and whether the GP metric counters
 * (KPADSetBtnRepeat is the misnamed CP counter read) changed between two
 * samples, via OSReport. */
void fn_802CED78(void) {
    extern char lbl_8034BD18[];
    extern void GXGetGPStatus(char *, char *, char *, char *, char *);
    int a1, a0, a3, a2, b1, b0, b3, b2;
    unsigned char status2, status3, status0, status1, status4;
    char *base = lbl_8034BD18;
    int changed2, changed3, same1, same0;
    int c0, c1, c2, c3, c4;
    KPADSetBtnRepeat(&a0, &a1, &a2, &a3);
    KPADSetBtnRepeat(&b0, &b1, &b2, &b3);
    same1 = a1 == b1;
    same0 = a0 == b0;
    changed3 = (b3 - a3) != 0;
    changed2 = (b2 - a2) != 0;
    GXGetGPStatus((char *)&status0, (char *)&status1, (char *)&status2, (char *)&status3, (char *)&status4);
    c4 = status4 ? 'B' : '-';
    c3 = status3 ? '-' : 'C';
    c2 = status2 ? '-' : 'R';
    c1 = status1 ? 'U' : '-';
    c0 = status0 ? 'O' : '-';
    OSReport(base + 0x12C, c0, c1, c2, c3, c4, same1, same0, changed3, changed2);
    if (!same0 && changed3) {
        OSReport(base + 0x15C);
    } else if (!same1 && same0 && changed3) {
        OSReport(base + 0x180);
    } else if (!status3 && same1 && same0 && changed3) {
        OSReport(base + 0x1A8);
    } else if (status2 && status3 && same1 && same0 && changed3 && changed2) {
        OSReport(base + 0x1D0);
    } else {
        OSReport(base + 0x200);
    }
}
#pragma scheduling invalid_target
void fn_802CEF90(void) {
    extern void GXGetGPStatus(char *, char *, char *, char *, char *);
    extern void *GXGetCurrentGXThread(void);
    extern void OSReport(const char *, ...);
    extern void OSPanic(const char *, int, const char *, ...);
    extern void fn_802CED78(void);
    extern char lbl_8034BF34[];
    extern char lbl_8034BF70[];
    extern char lbl_8055D0F8[7];
    extern unsigned char lbl_8055FD34;
    extern int lbl_8055FD38;
    extern unsigned int lbl_8055FDB8;
    extern unsigned int lbl_8055FDBC;
    unsigned char gpStatus;
    unsigned char dummy;
    unsigned int gxThread;

    if (lbl_8055FD34 != 0) {
        lbl_8055FD38++;
    }
    GXGetGPStatus((char *)&gpStatus, (char *)&dummy, (char *)&dummy, (char *)&dummy, (char *)&dummy);
    gxThread = (unsigned int)GXGetCurrentGXThread();
    if (gpStatus != 0 && gxThread == lbl_8055FDBC) {
        lbl_8055FDB8++;
        if (lbl_8055FDB8 >= 10) {
            OSReport(lbl_8034BF34);
            fn_802CED78();
            OSPanic(lbl_8055D0F8, 0x201, lbl_8034BF70);
        }
    } else {
        lbl_8055FDBC = gxThread;
        lbl_8055FDB8 = 0;
    }
}
/* Emit GX FIFO commands that set up performance-metric state: when enable is
 * set, program GP metrics and load nonzero BP/XF register values; otherwise
 * load the same registers with their zero (idle) values. */
void fn_802CF048(int enable) {
    if (enable != 0) {
        GXSetGPMetric(0x23, 0x16);
        WGPIPE.c = GX_FIFO_CMD_LOAD_BP_REG;
        WGPIPE.i = 0x2402C004;
        WGPIPE.c = GX_FIFO_CMD_LOAD_BP_REG;
        WGPIPE.i = 0x23000020;
        WGPIPE.c = GX_FIFO_CMD_LOAD_XF_REG;
        WGPIPE.us = 0;
        WGPIPE.us = 0x1006;
        WGPIPE.i = 0x84400;
        return;
    }
    WGPIPE.c = GX_FIFO_CMD_LOAD_BP_REG;
    WGPIPE.i = 0x24000000;
    WGPIPE.c = GX_FIFO_CMD_LOAD_BP_REG;
    WGPIPE.i = 0x23000000;
    WGPIPE.c = GX_FIFO_CMD_LOAD_XF_REG;
    WGPIPE.us = 0;
    WGPIPE.us = 0x1006;
    WGPIPE.i = 0;
}

#pragma dont_inline on
/* Enable GX performance metrics and emit their FIFO setup commands by calling fn_802CF048 with its enable flag set. */
void fn_802CF104(void) {
    fn_802CF048(1);
}

void fn_802CF10C(void) {
    unsigned char* st = lbl_804C5710;
    int* fb = lbl_804C9760;
    int i;
    int j;
    fn_802CEF90();
    if ((int)lbl_8055FD44 == 0xFA0) {
        OSReport(lbl_8034BF80);
    }
    lbl_8055FD4C++;
    lbl_8055FD44++;
    if (lbl_8055FD4C < 5) {
        return;
    }
    if (lbl_8055FD50 == 0 && st[1] == 0) {
        return;
    }
    if (st[0] != 0) {
        int* sti = (int*)st;
        int fb1;
        st[0] = 0;
        DCInvalidateRange((void*)fb[1], fb[2] * fb[3] * 2);
        fb1 = fb[1];
        for (i = 0; i < sti[4]; i++) {
            memcpy(st + 0x14 + i * sti[3] * 2, (unsigned char*)fb1 + (sti[1] + fb[2] * (i + sti[2])) * 2, sti[3] * 2);
        }
    }
    if (st[1] != 0) {
        if (lbl_8055FD4C % 60 != 0 && lbl_8055FD4C % 60 != 45) {
            return;
        }
    } else if (lbl_8055FD4C != 0) {
        return;
    }
    DCInvalidateRange((void*)fb[1], fb[2] * fb[3] * 2);
    if (lbl_8055FD50 != 0) {
        int r5 = ((unsigned)lbl_8055FD4C >> 2) & 1;
        for (; r5 < fb[3]; r5 += 2) {
            int r6;
            for (r6 = 0; r6 < fb[2]; r6++) {
                unsigned short* ptr = (unsigned short*)((unsigned char*)fb[1] + (r6 + r5 * fb[2]) * 2);
                unsigned short v = *ptr;
                if ((v & 0xFF) > (v - 0x400)) {
                    *ptr = v & 0xFF;
                }
            }
        }
    }
    if (st[1] != 0) {
        int* sti = (int*)st;
        if (lbl_8055FD4C % 60 < 30) {
            int off = 0;
            for (i = 0; i < sti[4]; i++) {
                unsigned short* src = (unsigned short*)(st + 0x14 + off * 2);
                unsigned short* dst = (unsigned short*)((unsigned char*)fb[1] + (sti[1] + fb[2] * (sti[2] + i)) * 2);
                for (j = 0; j < sti[3]; j++) {
                    dst[j] = src[j];
                }
                off += sti[3];
            }
        } else {
            unsigned short fill = *(unsigned short*)(st + 0x14);
            for (i = 0; i < sti[4]; i++) {
                unsigned short* dst = (unsigned short*)((unsigned char*)fb[1] + (sti[1] + fb[2] * (sti[2] + i)) * 2);
                for (j = 0; j < sti[3]; j++) {
                    dst[j] = fill;
                }
            }
        }
    }
    DCFlushRange((void*)fb[1], fb[4] * (fb[2] * fb[3]));
}

#pragma dont_inline reset

void fn_802CF5A8(void) {
#define sGxResetRegistered lbl_8055D0FF
#define sGxResetName lbl_8055D100
#define GxResetCallback fn_802CEC04
#define RegisterResetCallback fn_802E2E0C
    /* Register the GX reset callback with its "GX" log name, once on first init. */
    if (sGxResetRegistered == 0) return;
    sGxResetRegistered = 0;
    RegisterResetCallback((void (*)(void))GxResetCallback, &sGxResetName);
#undef sGxResetRegistered
#undef sGxResetName
#undef GxResetCallback
#undef RegisterResetCallback
}

#pragma push
#pragma dont_inline on
void fn_802CF5D0(void) {}
#pragma pop

#define alphaCompareRef lbl_8055FD24        /* cached alpha-reference byte (GXSetAlphaCompare ref0) */
#define alphaCompareAppliedRef lbl_8055FD91 /* last alpha reference programmed into the GX registers */

#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802CF5D4(void) {
    /* Reset alpha comparison to "alpha > 0" and clear the cached/applied reference values. */
    alphaCompareRef = 0;
    alphaCompareAppliedRef = 0;
    GXSetAlphaCompare(4, 0, 1, 0, 0);
}
#pragma dont_inline reset
#pragma scheduling on

void fn_802CF5F8(void) {}

void fn_802CF5FC(void) {
}

#pragma push
#pragma opt_lifetimes off
#pragma dont_inline on
void fn_802CF600(void) {
    extern char lbl_8034BD18[], lbl_8055D104;
    extern int lbl_8055FD7C, lbl_8055FD48, lbl_8055FD4C, lbl_8055FD2C, lbl_8055FD6C, lbl_8055FD40;
    extern unsigned char lbl_8055FD50;
    extern unsigned short lbl_8055FD0A;
    extern void *lbl_8055FD68, *lbl_8055FD20;
    extern unsigned long lbl_8055FDAC;
    extern void fn_802CF830(void), fn_802CF10C(void), fn_802D9A50(void), fn_802CEC44(void);
    extern void fn_80127468(void), fn_8005954C(void), fn_801282EC(int), fn_801282F4(void);
    extern void fn_802D8D1C(void), fn_802D6810(void), fn_802CF850(void), fn_802D0BD8(void);
    extern void fn_802CFF10(void), fn_802DACD4(void), fn_802D9C18(void), fn_802DA2F4(void);
    extern void fn_802CFF5C(void *), fn_802CFFA4(unsigned short), fn_802D37E4(void), fn_802DD4FC(void), fn_802DB168(void);
    extern void *fn_8002F37C(void *, void (*)(void), void *, int, int);
    extern int GXInit(int, int), GXGetTexBufferSize(int, int, int, int, int);
    extern void GXInitTexObj(void *, void *, int, int, int, int, int, int);
    extern void fn_800591AC(int), fn_80127C90(void (*)(void), void *);
    extern void GXGetLightDir(void (*)(unsigned int)), GXLoadLightObjIndx(void (*)(void));
    extern int VIConfigure(void *), VISetBlack(int), VIFlush(void);
    extern void fn_802E30C8(const char *, ...);
    struct { char *p; } baseBox;
    int zero = 0;
    int negative;
    void *buffer;
    int size;
    baseBox.p = lbl_8034BD18;
    lbl_8055FD7C = 0;
    lbl_8055FD48 = 3;
    lbl_8055FD4C = 0;
    lbl_8055FD50 = 0;
    lbl_8055FD2C = -0x259;
    lbl_8055FD30 = -0x258;
    lbl_8055FD64 = 0;
    lbl_8055FE24 = 0;
    fn_80127468();
    fn_8005954C();
    fn_802CEAC4();
    fn_80127468();
    VIConfigure(lbl_8055FD64);
    fn_802CEA34();
    fn_80127468();
    fn_801282EC(0x20);
    fn_801282F4();
    lbl_8055FDA0 = (unsigned long)fn_8012850C((void *)0x177000, baseBox.p + 0x2A4);
    lbl_8055FD94 = 0;
    buffer = fn_8012850C((void *)0x26010, baseBox.p + 0x2B0);
    lbl_8055FDB0 = fn_8002F37C(buffer, fn_802CF830, 0, 0x4C, 0x800);
    lbl_8055FDAC = 0;
    fn_802D8D1C();
    fn_80127468();
    lbl_8055FD68 = fn_8012850C((void *)0x300000, baseBox.p + 0x2BC);
    lbl_8055FD6C = GXInit((int)lbl_8055FD68, 0x300000);
    fn_802D6810();
    fn_802CF850();
    fn_80127468();
    fn_802E30C8(baseBox.p + 0x2C8);
    fn_802D0BD8();
    fn_802E30C8(baseBox.p + 0x2E0);
    fn_80127468();
    fn_802CFF10();
    fn_802E30C8(baseBox.p + 0x2FC);
    fn_80127468();
    fn_802CF5A8();
    fn_802DACD4();
    fn_802D9C18();
    fn_800591AC((int)fn_802CF10C);
    fn_80127468();
    fn_802DA2F4();
    fn_802CFF5C((void *)0x17);
    fn_802CFFA4(lbl_8055FD0A);
    negative = -1;
    lbl_8055FD20 = (void *)negative;
    size = GXGetTexBufferSize(0x280, 0x1C0, 1, 0, 0);
    fn_801282EC(0x20);
    buffer = fn_8012850C((void *)size, baseBox.p + 0x30C);
#pragma small_data off
    lbl_804C9940 = (unsigned long)buffer;
    GXInitTexObj(&lbl_804C9940 + 1, buffer, 0x280, 0x1C0, 1, 0, 0, 0);
#pragma small_data on
    GXGetLightDir(fn_802CECF4);
    GXLoadLightObjIndx(fn_802CEC44);
    fn_802D37E4();
    fn_802DD4FC();
    lbl_8055FD40 = negative;
    fn_80127468();
    fn_80127C90(fn_802D9A50, &lbl_8055D104);
    fn_802DB168();
    lbl_8055FD48 = zero;
    VISetBlack(zero);
    VIFlush();
}
#pragma pop
void fn_802CF830(void) {
}

int fn_802CF834(void) {
    /* Return nonzero when an external frame buffer is currently set: entry [1] of the GX_XFB block holds the buffer being drawn into and shown. */
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
#pragma dont_inline fn_802CF5D4
#pragma dont_inline fn_802CF104
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

/* Reading names for the buffers the graphics shutdown below releases; every
 * one of them is allocated by fn_802CF600 (graphics init).
 *   GX_XFB_BLOCK          frame-buffer block: [0] XFB base, [1] the buffer
 *                         currently being displayed (flipped on copy),
 *                         [2] width, [3] height, [4] buffers per frame (2)
 *   GX_SCREEN_TEX_BUFFER  640x440 copy of the EFB used as a texture
 *                         (GXCopyTex/GXLoadTexObj); its GXTexObj sits at +4
 *   GX_WORK_MEMORY        3 MiB of work memory handed to GXInit
 *   GX_RECORD_TABLE       0x800 records of 0x4C bytes; the allocator's
 *                         0x10-byte header sits before the table, so that is
 *                         the address that gets freed
 *   GX_DYNAMIC_DATA       0x177000-byte GX dynamic-data (display list) buffer
 *                         the frame is flushed out of, see fn_802CFDE0
 *   GX_DYNAMIC_HIGH_WATER high-water mark of GX_DYNAMIC_DATA, reported here */
#define GX_XFB_BLOCK lbl_804C9760
#define GX_SCREEN_TEX_BUFFER lbl_804C9940
#define GX_WORK_MEMORY lbl_8055FD68
#define GX_RECORD_TABLE lbl_8055FDB0
#define GX_DYNAMIC_DATA lbl_8055FDA0
#define GX_DYNAMIC_OFFSET lbl_8055FD94 /* current bump offset into GX_DYNAMIC_DATA */
#define GX_DYNAMIC_HIGH_WATER lbl_8055FD98

/* fn_802CFBA8 - shuts the graphics subsystem down.  Called from the engine's
 * exit sequence (fn_802E2B34) after that sequence has dropped its own alarm:
 * drops the draw-sync alarm fn_802D9A50, the AI DMA callback and the VI
 * retrace callback, reports the GX dynamic-data high-water mark and any
 * visibility tests still in use, blanks the screen over two retraces while
 * clearing the draw-sync callback, then frees every buffer fn_802CF600
 * allocated and empties the frame-buffer block. */
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
    extern void fn_80128670();
    extern void fn_802DA4C4(void);
    extern void fn_802D0C98(void);
    extern void fn_802DAE18(void);
    extern void fn_802D8DA0(void);
    extern char lbl_8034C038[];
    fn_80127D58(fn_802D9A50);          /* drop the draw-sync alarm */
    fn_802D9C4C();                     /* AIRegisterDMACallback(0) */
    fn_800591AC(0);                    /* VISetRetraceCallback(0) */
    fn_802E30C8(lbl_8034C038, GX_DYNAMIC_HIGH_WATER);
    fn_802DD5F4();
    fn_802D3894();                     /* report visibility tests still in use */
    fn_802D6860();
    fn_80128670(GX_SCREEN_TEX_BUFFER);
    GX_SCREEN_TEX_BUFFER = 0;
    fn_802DA4C4();
    fn_802D0C98();
    VISetBlack(1);                     /* blank the screen and wait for it */
    VIFlush();
    VIWaitForRetrace();
    GXGetVtxDesc();
    GXSetDrawSyncCallback();           /* clears it; r3 is the retrace count */
    VIFlush();
    VIWaitForRetrace();
    fn_802DAE18();
    fn_80128670(GX_WORK_MEMORY);       /* the 3 MiB GXInit work memory */
    GX_WORK_MEMORY = 0;
    fn_80128670(GX_XFB_BLOCK[0]);      /* the frame buffers */
    GX_XFB_BLOCK[0] = 0;
    fn_802D8DA0();
    if (GX_RECORD_TABLE != 0) {
        fn_80128670((char *)GX_RECORD_TABLE - 0x10);  /* free from the header */
    }
    GX_RECORD_TABLE = 0;
    GX_XFB_BLOCK[1] = 0;
    fn_80128670(GX_DYNAMIC_DATA, GX_XFB_BLOCK);       /* 2nd arg: r4 left over */
    GX_DYNAMIC_DATA = 0;
}

extern double __fabs(double);
#pragma scheduling invalid_target
void fn_802CFCA0(void *alarm) {
    extern char lbl_80558DC4[];
    char fifoBuffer[0x80];
    int fifoReadPtr;
    int fifoWritePtr;
    float sampleValue;

    /* GX draw-sync callback: reset per-frame state, set FIFO break point, and flag threshold exceed. */
    fn_802D6C68();
    *(volatile unsigned char *)&lbl_8055FE39 = 1;
    lbl_8055FDA4 = lbl_8055FD94;
    lbl_8055FD9C = 0;
    lbl_804C5700[0] = 1;
    lbl_8055FD8C = -1;
    fn_802DA52C();
    GXSetDrawSync();
    GXGetVtxDesc();
    GXGetCPUFifo(fifoBuffer);
    GXGetFifoPtrs(fifoBuffer, &fifoReadPtr, &fifoWritePtr);
    GXEnableBreakPt(fifoWritePtr);
    GXGetVtxDesc();
    GXInvalidateVtxCache();
    GXMiscInit(1);
    lbl_8055FD30 += 1;
    if (lbl_804C97B0[0] == 0) {
        sampleValue = *(volatile float *)((unsigned char *)lbl_804C97B0 + 0x10);
        if (!((float)__fabs((double)sampleValue) <= *(volatile float *)lbl_80558DC4)) {
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
    /* (Re)initialize the GX FIFO from the CPU FIFO and reconfigure video/GX state. */
    extern int lbl_8055FD6C;
    extern void *lbl_8055FD64;
    char fifoInfo[0x80];
    int fifoBase;
    int fifoSize;
    GXGetCPUFifo(fifoInfo);
    fifoBase = GXGetFifoBase(fifoInfo);
    fifoSize = GXGetFifoSize(fifoInfo);
    GXGetVtxAttrFmtv();
    lbl_8055FD6C = GXInit(fifoBase, fifoSize);
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
    int tmp;
    int end;
    int start;
    fn_802ECA48();
    tmp = (int)lbl_8055FD94;
    tmp += lbl_8055FD9C;
    if (tmp > (int)lbl_8055FD98) {
        lbl_8055FD98 = (unsigned int)tmp;
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
    while (*(volatile unsigned char *)&lbl_8055FD3C == 0) {
        if (*(volatile int *)&lbl_8055FD38 > 10) {
            OSReport(lbl_8034C058);
            fn_802CED78();
            fn_802CFD74();
            fn_802CF048(1);
            lbl_8055FD40 = fn_802E2C20();
            break;
        }
    }
    lbl_8055FD34 = 0;
    lbl_8055FD2C = (int)lbl_8055FD30 - 1;
    GXDisableBreakPt();
}
#pragma scheduling on

#pragma pop

extern void fn_802CFCA0(void*);
/* GX draw-sync alarm callback: begin a fresh frame by resetting per-frame state
   and arming the FIFO break point (fn_802CFCA0), then flush the just-finished
   frame's dynamic-data buffer and disarm the break point (fn_802CFDE0). */
void fn_802CFEEC(void *alarm) {
    fn_802CFCA0(alarm);
    fn_802CFDE0();
}

extern unsigned long lbl_8055FD44;
extern unsigned long lbl_8055FDAC;
extern void fn_802D0C98(void);
extern void fn_802D0BD8(void);
#pragma scheduling invalid_target
void fn_802CFF10(void) {
    int zero = 0;
    lbl_8055FD44 = zero;
    fn_802CF5D0();
    fn_802D0C98();
    fn_802D0BD8();
    lbl_8055FDAC = zero;
    lbl_8055FE39 = zero;
}
extern void *lbl_8055FD20;
#pragma push
#pragma dont_inline on
void fn_802CFF50(void) {
    /* Reset the GX state-change mask to "everything needs updating" (-1). */
    lbl_8055FD20 = (void*)-1;
}
#pragma pop

extern void *lbl_8055FD1C;
/* Set the cached GX render-state flags bitmask (depth test, colour/alpha
   updates, etc.); the dirty-state code compares it with lbl_8055FD74. */
void fn_802CFF5C(void* flags) {
    lbl_8055FD1C = flags;
}

/* Bump-allocates size bytes (rounded up to 32) from the GX dynamic-data display-list buffer, wrapping to its start when full. */
int fn_802CFF64(int size) {
    int newOffset;
    int oldOffset = GX_DYNAMIC_OFFSET;
    int alignedSize = (size + 0x1F) & ~0x1F;
    newOffset = oldOffset + alignedSize;
    if (newOffset <= 0x177000) {
        GX_DYNAMIC_OFFSET = newOffset;
        return GX_DYNAMIC_DATA + oldOffset;
    }
    GX_DYNAMIC_OFFSET = alignedSize;
    return GX_DYNAMIC_DATA;
}

#pragma dont_inline on
int fn_802CFFA0(int arg0) {
    return fn_802CFF64(arg0);
}
#pragma dont_inline reset

void fn_802CFFA4(unsigned short blendMode) {
    /* Store the requested 16-bit GX blend mode (high byte = src factor, low byte = dst factor).
       The pipeline rebuild (fn_802D3144) compares this with the applied copy lbl_8055FD88. */
    lbl_8055FD86 = blendMode;
}

#pragma scheduling on
void fn_802CFFAC(int arg0, int arg1, int arg2) {
    volatile unsigned char spB;
    volatile unsigned char spA;
    volatile unsigned char sp9;
    volatile unsigned char sp8;
    register unsigned long packed;

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
void fn_802D0014(float startValue, float endValue, float delta) {
    /* Sets up a float interpolation in the GX state block: stores start/end-step values and marks it active when |delta| exceeds the threshold. */
    extern unsigned char lbl_804C97B0[];
    extern char lbl_80558DC4[];
    float magnitude = (float)__fabs((double)delta);
    ((float *)lbl_804C97B0)[2] = startValue;
    if (!(magnitude <= *(float *)lbl_80558DC4)) {
        lbl_804C97B0[0] = 1;
        ((float *)lbl_804C97B0)[3] = startValue + ((endValue - startValue) / delta);
    } else {
        ((float *)lbl_804C97B0)[3] = endValue;
        lbl_804C97B0[0] = 0;
    }
    ((float *)lbl_804C97B0)[4] = delta;
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
#pragma push
#pragma small_data off
void fn_802D0188(unsigned char a, unsigned char b, unsigned char c) {
    extern char lbl_804C97D0;
    volatile unsigned char *p = (volatile unsigned char *)&lbl_804C97D0;
    lbl_804C97D0 = a;
    p[1] = b;
    p[2] = c;
    p[3] = 0;
    p[0x5C] = 1;
}
#pragma pop
void fn_802D01B0(float *p, float v) {
    extern char lbl_804C97D0;
    float z, y, x;
    float *out;
    x = p[0];
    out = (float *)((unsigned char *)&lbl_804C97D0 + 0xC);
    y = *(volatile float *)((float *)p + 1);
    z = p[2];
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
/* Sets the GX viewport/scissor rectangle (x, y, width, height), adjusting vertical position and height for the non-widescreen aspect when the widescreen flag is clear. */
void fn_802D01E0(int viewportX, int viewportY, int viewportWidth, int viewportHeight) {
    if (lbl_8055FE24 == 0) {
        viewportY = (int)(lbl_80564F94 + ((lbl_80564FB8 * (float)viewportY) / lbl_80564FBC));
        viewportHeight = (int)(lbl_80564F94 + ((lbl_80564FB8 * (float)viewportHeight) / lbl_80564FBC));
    }
    fn_802D2218();
    *(int *)(lbl_804C9778 + 0x1C) = viewportX;
    *(int *)(lbl_804C9778 + 0x20) = viewportY;
    *(int *)(lbl_804C9778 + 0x24) = viewportWidth;
    *(int *)(lbl_804C9778 + 0x28) = viewportHeight;
    lbl_804C9778[1] = 1;
    lbl_804C9778[0] = 1;
    *(float *)(lbl_804C9778 + 0x18) = (float)viewportWidth / (float)viewportHeight;
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
    register unsigned char *p = lbl_804C9778;
    register int one = 1;
    float result;

    *(float *)(p + 4) = arg0;
    lbl_804C9778[0] = one;
    *(float *)(p + 8) = arg1;
    *(float *)(p + 0xc) = arg2;
    *(float *)(p + 0x14) = arg3;

    result = fn_8002EF30(arg2 * lbl_80564F94);

    *(float *)(lbl_804C97B0 + 0x14) = arg0;
    *(float *)(p + 0x10) = result;
    *(float *)(lbl_804C97B0 + 0x18) = arg1;
    lbl_804C97B0[0x1c] = one;
}

extern unsigned long lbl_804C56C0[];
extern float lbl_804C56F0[3];
extern float lbl_80564FC0;
extern void PSVECCrossProduct(float *, float *, float *);
extern float PSVECMag();
#pragma use_lmw_stmw off
void fn_802D03F4(register float *arg0, float arg1) {
    unsigned long *src = (unsigned long *)arg0;
    unsigned long t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    float sp[3];
    float mag;
    float scale;

    fn_802D6C78();
    t0 = src[0];
    t1 = src[1];
    lbl_804C56C0[0] = t0;
    t2 = src[2]; t3 = src[3]; t4 = src[4]; t5 = src[5];
    t6 = src[6]; t7 = src[7]; t8 = src[8]; t9 = src[9];
    t10 = src[10]; t11 = src[11];
    lbl_804C56C0[1] = t1; lbl_804C56C0[2] = t2; lbl_804C56C0[3] = t3;
    lbl_804C56C0[4] = t4; lbl_804C56C0[5] = t5; lbl_804C56C0[6] = t6; lbl_804C56C0[7] = t7;
    lbl_804C56C0[8] = t8; lbl_804C56C0[9] = t9; lbl_804C56C0[10] = t10; lbl_804C56C0[11] = t11;
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
/* Set the global GX state block pointer (holds a GXTexObj at +0x24, read by fn_802D30E4); 0 clears it. */
void fn_802D050C(void* stateBlock) {
    lbl_8055FD54 = stateBlock;
}

int fn_802D0514(void *source) {
    extern unsigned long lbl_8055FDAC;
    int index;
    unsigned char *aux;
    unsigned long next;
    unsigned int *src;
    unsigned char *dst;
    unsigned int a;
    unsigned int b;
    unsigned int c;
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

void fn_802D0610(int arg0) {
    int *dst32 = (int *)lbl_804C5690;
    int *rec32;
    unsigned char *dst8;
    unsigned char *rec8;
    unsigned char *aux = (unsigned char *)&lbl_804C97D0;
    int i;
    float tmp[12];

    if (arg0 == lbl_8055FD8C) {
        return;
    }
    if (arg0 != 0) {
        rec32 = (int *)((char *)lbl_8055FDB0 + (arg0 - 1) * 0x4C);
        dst8 = (unsigned char *)lbl_804C5690;
        rec8 = (unsigned char *)rec32;
        dst32[0] = rec32[0];
        dst32[1] = rec32[1];
        dst32[2] = rec32[2];
        dst32[3] = rec32[3];
        dst32[4] = rec32[4];
        dst32[5] = rec32[5];
        dst32[6] = rec32[6];
        dst32[7] = rec32[7];
        dst32[8] = rec32[8];
        dst32[9] = rec32[9];
        dst32[10] = rec32[10];
        dst32[11] = rec32[11];
        lbl_8055FD70 = 1;
        aux[0] = rec8[0x30];
        aux[1] = rec8[0x31];
        aux[2] = rec8[0x32];
        aux[3] = rec8[0x33];
        aux[4] = rec8[0x34];
        aux[5] = rec8[0x35];
        aux[6] = rec8[0x36];
        aux[7] = rec8[0x37];
        aux[8] = rec8[0x38];
        aux[9] = dst8[0x30];
        aux[10] = dst8[0x31];
        aux[11] = dst8[0x32];
        aux[12] = rec8[0x0C];
        aux[13] = rec8[0x0D];
        aux[14] = rec8[0x0E];
        aux[15] = rec8[0x0F];
        aux[16] = rec8[0x10];
        aux[17] = rec8[0x11];
        aux[18] = rec8[0x12];
        aux[19] = rec8[0x13];
        aux[20] = rec8[0x14];
        *(int *)(aux + 12) = *(int *)(rec8 + 12);
        *(int *)(aux + 16) = *(int *)(rec8 + 16);
        *(int *)(aux + 20) = *(int *)(rec8 + 20);
        *(float *)(aux + 24) = *(float *)(rec8 + 24);
        aux[92] = 1;
    } else {
        tmp[0] = lbl_80564F8C;
        tmp[1] = lbl_80564F88;
        tmp[2] = lbl_80564F88;
        tmp[3] = lbl_80564F88;
        tmp[4] = lbl_80564F8C;
        tmp[5] = lbl_80564F88;
        tmp[6] = lbl_80564F88;
        tmp[7] = lbl_80564F88;
        tmp[8] = lbl_80564F8C;
        tmp[9] = lbl_80564F88;
        tmp[10] = lbl_80564F88;
        tmp[11] = lbl_80564F88;
        for (i = 0; i < 12; i++) {
            dst32[i] = ((int *)tmp)[i];
        }
        lbl_8055FD70 = 1;
    }
    lbl_8055FD8C = arg0;
}

#pragma push
#pragma optimize_for_size on
void fn_802D07E4(char* arg0, int arg1) {
    extern unsigned long lbl_8055D0B8;
    extern int lbl_8055D0BC;
    extern int lbl_8055D0C0;
    extern signed char lbl_8055FD90;
    extern unsigned char lbl_804C9830[];
    extern int lbl_804C9760[];
    extern char lbl_8034C0EC[];
    extern const char lbl_8034C108[];
    extern void fn_802E30C8(const char*, ...);
    unsigned char *src = (unsigned char *)arg0;
    register unsigned char c;
    register int count;
    register unsigned char *dst;
    if ((int)lbl_8055D0B8 >= 0) {
        fn_802E30C8(lbl_8034C0EC);
        lbl_8055D0B8 = lbl_8055D0BC * lbl_8055D0C0;
        return;
    }
    lbl_8055FD90 = 1;
    dst = lbl_804C9830;
    count = 0x100;
    goto copy;
dec:
    count -= 1;
    if (count > 0) {
        goto copy;
    }
    dst[-1] = 0;
    goto done;
copy:
    c = *src;
    src += 1;
    *dst = c;
    dst += 1;
    if ((signed char)c != 0) {
        goto dec;
    }
done:
    if (arg1 != 0) {
        fn_802E30C8(lbl_8034C108, lbl_8055D0BC * lbl_804C9760[2], lbl_8055D0C0 * lbl_804C9760[3], lbl_804C9760, lbl_8055D0BC);
        lbl_8055D0B8 = 0;
    }
}
#pragma pop
extern unsigned char lbl_8055FD78;
extern int GXSetCullMode(int);
extern void GXLoadTexMtxImm(void *, unsigned int, unsigned char);
extern int lbl_8055D0BC;
extern int lbl_8055D0C0;
extern signed char lbl_8055FD90;
extern unsigned char lbl_8055FD18;
extern int lbl_8055D10C;
extern int lbl_8055FDC0;
extern int lbl_8055FDC4;
extern float lbl_80564F80;
extern char lbl_8034BD18[];
extern int lbl_804C9760[];
extern unsigned char lbl_804C9830[];
void fn_802D0914(int, short, short);
void fn_802D09E4(void);
int fn_802E2C20(void);
void fn_802E30C8(const char *, ...);
void fn_802E3734(int *);
int fn_802E3D68(unsigned char *);
/* Configure the tiled offscreen-render grid: set its column count, row count and mode flag. */
void fn_802D08B4(int columns, int rows, unsigned char mode) {
#define tileGridWidth lbl_8055D0BC
#define tileGridHeight lbl_8055D0C0
#define tileModeFlag lbl_8055FD18
    tileModeFlag = mode;
    tileGridWidth = (unsigned long)columns;
    tileGridHeight = (unsigned long)rows;
#undef tileGridWidth
#undef tileGridHeight
#undef tileModeFlag
}

/* GX render-enable flag: cleared just before the end-of-frame flush (fn_802C2B48) and set again after. */
void fn_802D08C4(unsigned char enabled) {
#define renderEnabled lbl_8055FD78
    renderEnabled = enabled;
#undef renderEnabled
}

/* Sets the GX cull mode from a small app-specific mode selector. */
void fn_802D08CC(int cullMode) {
    int gxCullMode;
    switch (cullMode) {
    case 1:
        gxCullMode = GX_CULL_FRONT;
        break;
    case 2:
        gxCullMode = GX_CULL_BACK;
        break;
    case 0:
        gxCullMode = GX_CULL_NONE;
        break;
    default:
        gxCullMode = GX_CULL_NONE;
        break;
    }
    GXSetCullMode(gxCullMode);
}

void fn_802D0910(int, int, int, int, int, int) {
}

#pragma scheduling invalid_target
void fn_802D0914(int arg0, short arg1, short arg2) {
    extern int fn_802E3A64(int, unsigned char *, int, int, int, int, int, int);
    unsigned char buffer[0x12];
    unsigned char b8, b9, b10, b11, b12, b13, b14, b15;
    memset(buffer, 0, 0x12);
    *(unsigned short *)(buffer + 12) = arg1;
    *(unsigned short *)(buffer + 8) = 0;
    *(unsigned short *)(buffer + 10) = 0;
    *(unsigned short *)(buffer + 14) = arg2;
    buffer[0] = 0;
    buffer[1] = 0;
    buffer[2] = 2;
    buffer[16] = 24;
    buffer[17] = 0;
    b12 = buffer[12];
    b13 = buffer[13];
    b8 = buffer[8];
    b9 = buffer[9];
    b10 = buffer[10];
    b11 = buffer[11];
    b14 = buffer[14];
    b15 = buffer[15];
    buffer[8] = b9;
    buffer[9] = b8;
    buffer[10] = b11;
    buffer[11] = b10;
    buffer[12] = b13;
    buffer[13] = b12;
    buffer[14] = b15;
    buffer[15] = b14;
    fn_802E3A64(arg0, buffer, 0x12, b13, b11, b9, 24, 2);
}
#pragma pop
void fn_802D09E4(void) {
}

void fn_802D09E8(void) {
    unsigned long frameCounter = lbl_8055D0B8;
    signed char flag = lbl_8055FD90;
    int temp_r0;

    if (flag == 0) {
        return;
    }

    if ((long) frameCounter < 0) {
        lbl_8055FD90 = 0;
        fn_802D09E4();
        return;
    }

    temp_r0 = lbl_8055FDC0 + 1;
    lbl_8055FDC0 = temp_r0;

    if (temp_r0 > 2) {
        lbl_8055FDC0 = 0;

        if (temp_r0 == 2) {
            int temp_r3 = fn_802E3D68(lbl_804C9830);
            lbl_8055D10C = temp_r3;

            if (temp_r3 == -1) {
                fn_802E30C8(lbl_8034BD18 + 0x428, lbl_804C9830);
                lbl_8055FD90 = 0;
                lbl_8055D0B8 = -1;
                return;
            }

            lbl_8055FDC4 = fn_802E2C20();
            fn_802E30C8(lbl_8034BD18 + 0x43C, lbl_804C9830);

            if (lbl_8055FD18 == 0) {
                fn_802D0914(lbl_8055D10C, (short) lbl_804C9760[2], (short) lbl_804C9760[3]);
            }
        }

        if ((long) frameCounter < (long) (lbl_8055D0BC * lbl_8055D0C0)) {
            int div = frameCounter / lbl_8055D0BC;
            int rem = frameCounter % lbl_8055D0BC;

            fn_802E30C8(lbl_8034BD18 + 0x458, (char *) (frameCounter + 1));
            fn_802D0910(lbl_8055D10C, lbl_804C9760[2] * rem, lbl_804C9760[3] * div,
                        lbl_804C9760[2] * lbl_8055D0BC, lbl_804C9760[3] * lbl_8055D0C0, lbl_804C9760[2]);
        }

        if ((long) frameCounter >= (long) (lbl_8055D0BC * lbl_8055D0C0)) {
            lbl_8055FD90 = 0;
            lbl_8055D0B8 = -1;
            fn_802E3734(&lbl_8055D10C);
            lbl_8055D10C = -1;
            fn_802E2C20();
            fn_802E30C8(lbl_8034BD18 + 0x468, lbl_804C9830, lbl_8055FDC4,
                        lbl_80564F80 * (float) (0x43300000 - (unsigned long) lbl_8055FDC4));
        }
    }
}

void fn_802D0BD8(void) {
    /* Set the GX viewport from the current render target (jittered on next field when enabled) and invalidate vertex/texture caches. */
    extern void *lbl_8055FD64;
    extern float lbl_80564F88;
    extern float lbl_80564F8C;
    extern double lbl_80564FA0;
    extern unsigned long VIGetNextField(void);
    extern void GXSetViewportJitter(unsigned short, float, float, float, float, float, float);
    extern void GXSetViewport(unsigned short, float, float, float, float, float, float);
    extern void GXInvalidateVtxCache(void);
    extern void GXInvalidateTexAll(void);
    unsigned char *renderTarget = (unsigned char *)lbl_8055FD64;
    unsigned short width;
    unsigned short height;
    unsigned long field;

    if (renderTarget[0x18]) {
        field = VIGetNextField();
        width = *(unsigned short *)(renderTarget + 4);
        height = *(unsigned short *)(renderTarget + 6);
        ((void (*)(unsigned long, float, float, float, float, float, float))GXSetViewportJitter)(field, lbl_80564F88, lbl_80564F88, (float)width, (float)height, lbl_80564F88, lbl_80564F8C);
    } else {
        width = *(unsigned short *)(renderTarget + 4);
        height = *(unsigned short *)(renderTarget + 6);
        ((void (*)(float, float, float, float, float, float))GXSetViewport)(lbl_80564F88, lbl_80564F88, (float)width, (float)height, lbl_80564F88, lbl_80564F8C);
    }
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
}

extern void GXSetColorUpdate(unsigned char);
extern float GXGetYScaleFactor(unsigned short, unsigned short);
extern unsigned int GXSetDispCopyYScale(float);
extern void GXSetDispCopySrc(int, int, int, int);
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
    {
        unsigned short *disp = (unsigned short *)lbl_8055FD64;
        GXSetDispCopySrc(0, 0, disp[2], disp[3]);
    }
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

#pragma scheduling off
/* Convert a transform's 4x3 matrix (stored as four (x,y,z) rows) into a GX 3x4
 * matrix: transpose it and negate the z row for the GX coordinate convention. */
int fn_802D0DD4(void *dst, void *src) {
    float negZ3, y3, x3, negZ2, y2, x2, negZ1, y1, x1, negZ0, y0, x0;
    float z0, z3, z2, z1;
    z0 = *(float *)((unsigned char *)src + 8);
    z1 = *(float *)((unsigned char *)src + 0x14);
    negZ0 = -z0;
    z2 = *(float *)((unsigned char *)src + 0x20);
    z3 = *(float *)((unsigned char *)src + 0x2c);
    negZ1 = -z1;
    negZ2 = -z2;
    negZ3 = -z3;
    x0 = *(float *)((unsigned char *)src + 0);
    y0 = *(float *)((unsigned char *)src + 4);
    x1 = *(float *)((unsigned char *)src + 0xc);
    y1 = *(float *)((unsigned char *)src + 0x10);
    x2 = *(float *)((unsigned char *)src + 0x18);
    y2 = *(float *)((unsigned char *)src + 0x1c);
    x3 = *(float *)((unsigned char *)src + 0x24);
    y3 = *(float *)((unsigned char *)src + 0x28);
    *(float *)((unsigned char *)dst + 0) = x0;
    *(float *)((unsigned char *)dst + 0x10) = y0;
    *(float *)((unsigned char *)dst + 0x20) = negZ0;
    *(float *)((unsigned char *)dst + 4) = x1;
    *(float *)((unsigned char *)dst + 0x14) = y1;
    *(float *)((unsigned char *)dst + 0x24) = negZ1;
    *(float *)((unsigned char *)dst + 8) = x2;
    *(float *)((unsigned char *)dst + 0x18) = y2;
    *(float *)((unsigned char *)dst + 0x28) = negZ2;
    *(float *)((unsigned char *)dst + 0xc) = x3;
    *(float *)((unsigned char *)dst + 0x1c) = y3;
    *(float *)((unsigned char *)dst + 0x2c) = negZ3;
}
#pragma scheduling on

extern float lbl_80564F94;
extern unsigned char lbl_804C5690[];
extern unsigned char lbl_802FAC70[];
extern void GXSetAlphaCompare(int, unsigned char, int, int, int);
extern void GXSetZMode(int, int, int);
extern unsigned char lbl_8055FD24;
/* Configure alpha compare and Z mode for transparent (mode 0) or opaque (mode 1) drawing. */
void fn_802D0E48(int mode) {
    if (mode == 0) {
        GXSetAlphaCompare(3, lbl_8055FD24, 1, 0, 0);
        GXSetZMode(1, 3, 0);
    } else if (mode == 1) {
        GXSetAlphaCompare(4, lbl_8055FD24, 1, 0, 0);
        GXSetZMode(1, 3, 1);
    }
}

#pragma dont_inline fn_802D0EC8
int fn_802D0EC8(int blendFactor) {
    /* Remap unsupported destination-color blend codes (8/9) to the equivalent source-color codes (2/3); other factors pass through. */
    switch (blendFactor) {
    case 8:
        return 2;
    case 9:
        return 3;
    default:
        return blendFactor;
    }
}

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
typedef struct {
    unsigned char c0, c1, c2, c3;
    unsigned char c4, c5, c6, c7, c8;
    unsigned char pad09[3];
    float p0, p1, p2, scale;
    unsigned char obj[0x40];
    unsigned char enabled;
} LightRec802D0EEC;
typedef struct {
    unsigned char c0, c1, c2, c3, c4;
    unsigned char pad05[3];
    float p0, p1, pad10, p2, p3;
    unsigned char enabled;
    unsigned char pad1D[3];
} FogRec802D0EEC;
typedef struct {
    unsigned char raw[0x4160];
    FogRec802D0EEC fog;
    LightRec802D0EEC light;
} GXState802D0EEC;

void fn_802D0EEC(void) {
    extern unsigned int lbl_8055FD74;
    extern unsigned int lbl_8055FD28;
    extern unsigned char lbl_8055FE58;
    extern int lbl_804DB458[];
    extern float lbl_80564FC4;
    extern unsigned short lbl_8055FD08;
    extern unsigned short lbl_8055FD88;
    extern unsigned char lbl_8055FD84;
    extern void GXInitLightPos(void *, float, float, float);
    extern void GXInitLightColor(void *, unsigned char *);
    extern void GXInitLightDistAttn_Internal(void *, float, float, int);
    extern void GXLoadLightObjImm(void *, unsigned int);
    extern void GXSetChanMatColor_Internal(int, void *);
    extern void GXSetChanAmbColor_Internal(int, void *);
    extern void GXSetChanCtrl(int, int, int, int, unsigned int, int, int);
    typedef struct {
        unsigned char raw[0x4160];
        FogRec802D0EEC fog;
        LightRec802D0EEC light[1];
    } State;

    float lightPos[3];
    volatile unsigned char whiteColor[4];
    volatile unsigned char blackColor[4];
    int tevWord;
    volatile unsigned char tevColor[4];
    volatile unsigned char fogColor[4];
    int lightColorWord;
    int matColor0;
    volatile unsigned char matColor2[4];
    volatile unsigned char ambColor0[4];
    int ambient2Color;
    volatile unsigned char lightColor[4];
    unsigned int diff;
    register State *s = (State *)lbl_804C5650;
    unsigned char *pB0;
    int lo, hi;
    int fogType;
    float scale;
    unsigned int packed;

    if ((unsigned char)lbl_8055FDB4 != 0)
        return;

    diff = (unsigned int)lbl_8055FD20 | ((unsigned int)lbl_8055FD1C ^ lbl_8055FD74);
    lbl_8055FD20 = 0;
    if (diff != 0) {
        if (diff & 6) {
            if ((unsigned int)lbl_8055FD1C & 6) {
                int zsrc = ((unsigned int)lbl_8055FD1C >> 1) & 1;
                GXSetZMode(1, ((unsigned int)lbl_8055FD1C & 4) ? 3 : 7, zsrc);
            } else {
                GXSetZMode(0, 7, 0);
            }
        }
        if (diff & 1)
            GXSetColorUpdate((unsigned char)((unsigned int)lbl_8055FD1C & 1));
        if (diff & 0x10)
            GXSetAlphaUpdate((unsigned char)(((unsigned int)lbl_8055FD1C >> 4) & 1));
        if (diff & 0x20) {
            tevWord = (int)lbl_8055FD28;
            ((void (*)(int, void *))GXSetTevColor)(2, &tevWord);
        }
        if (diff & 0x40) {
            if ((unsigned int)lbl_8055FD1C & 0x40) {
                GXSetDstAlpha(0, 0);
                GXSetAlphaCompare(7, 0, 1, 0, 0);
            } else {
                GXSetDstAlpha(1, lbl_8055FD60);
                fn_802CF5D4();
            }
            s->raw[0xB0] = 1;
        }
        if (diff & 0x80) {
            if (lbl_8055FD86 == lbl_8055FD08) {
                GXSetBlendMode(0, 0, 0, 5);
            } else {
                hi = (int)lbl_8055FD86 >> 8;
                lo = fn_802D0EC8((int)lbl_8055FD86 & 0xFF);
                GXSetBlendMode(1, fn_802D0EC8(hi), lo, 5);
            }
            lbl_8055FD88 = lbl_8055FD86;
            s->raw[0xB0] = 1;
        }
        if (diff & 0x100)
            s->raw[0xB0] = 1;
        lbl_8055FD74 = (unsigned int)lbl_8055FD1C;
    }

    if (lbl_8055FD24 != lbl_8055FD91) {
        GXSetAlphaCompare(4, lbl_8055FD24, 1, 0, 0);
        lbl_8055FD91 = lbl_8055FD24;
    }

    if (lbl_8055FD86 != lbl_8055FD88) {
        if (lbl_8055FD86 == lbl_8055FD08) {
            GXSetBlendMode(0, 0, 0, 5);
        } else {
            int hi2 = (int)lbl_8055FD86 >> 8;
            diff = fn_802D0EC8((int)lbl_8055FD86 & 0xFF);
            GXSetBlendMode(1, fn_802D0EC8(hi2), diff, 5);
        }
        lbl_8055FD88 = lbl_8055FD86;
        s->raw[0xB0] = 1;
    }

    if (lbl_8055FE58 != 0) {
        packed = ((unsigned int (*)(unsigned int))fn_802CEA1C)(lbl_804DB458[1]);
        tevColor[3] = packed;
        tevColor[0] = packed >> 24;
        tevColor[1] = packed >> 16;
        tevColor[2] = packed >> 8;
        ((void (*)(int, void *))GXSetTevColor)(3, (void *)tevColor);
        lbl_8055FE58 = 0;
    }

    if (s->fog.enabled != 0) {
        fogType = 0;
        s->fog.enabled = 0;
        fogColor[0] = s->fog.c1;
        fogColor[1] = s->fog.c2;
        fogColor[2] = s->fog.c3;
        fogColor[3] = s->fog.c4;
        if (s->raw[0x4160] != 0)
            fogType = 2;
        ((void (*)(int, unsigned char *, void *, float, float, float, float))GXSetFog)(
            fogType, (unsigned char *)fogColor, &s->fog, s->fog.p0, s->fog.p1,
            s->fog.p2, s->fog.p3);
    }

    if (s->light[0].enabled != 0) {
        s->light[0].enabled = 0;
        packed = fn_802CE9FC(0xFF, 0xFF, 0xFF, 0xFF);
        whiteColor[3] = packed;
        whiteColor[0] = packed >> 24;
        whiteColor[1] = packed >> 16;
        whiteColor[2] = packed >> 8;
        packed = fn_802CE9FC(0, 0, 0, 0xFF);
        lightPos[0] = s->light[0].p0 * lbl_80564FC4;
        lightPos[1] = s->light[0].p1 * lbl_80564FC4;
        lightPos[2] = s->light[0].p2 * lbl_80564FC4;
        blackColor[0] = packed >> 24;
        blackColor[3] = packed;
        blackColor[1] = packed >> 16;
        blackColor[2] = packed >> 8;
        GXInitLightPos(s->light[0].obj, lightPos[0], lightPos[1], -lightPos[2]);
        scale = s->light[0].scale;
        lightColor[3] = s->light[0].c3;
        lightColor[0] = (unsigned char)(int)(scale * (float)s->light[0].c0);
        lightColor[1] = (unsigned char)(int)(scale * (float)s->light[0].c1);
        lightColor[2] = (unsigned char)(int)(scale * (float)s->light[0].c2);
        lightColorWord = *(int *)lightColor;
        GXInitLightColor(s->light[0].obj, (unsigned char *)&lightColorWord);
        ((void (*)(void *, float, float, int))GXInitLightDistAttn_Internal)(
            s->light[0].obj, lbl_80564F8C, lbl_80564F8C, 0);
        GXLoadLightObjImm(s->light[0].obj, 1);
        matColor0 = *(int *)whiteColor;
        GXSetChanMatColor_Internal(0, &matColor0);
        packed = fn_802CE9FC(0, 0, 0, s->light[0].c8);
        matColor2[3] = packed;
        matColor2[0] = packed >> 24;
        matColor2[1] = packed >> 16;
        matColor2[2] = packed >> 8;
        GXSetChanMatColor_Internal(2, (void *)matColor2);
        ambColor0[0] = s->light[0].c4;
        ambColor0[1] = s->light[0].c5;
        ambColor0[2] = s->light[0].c6;
        ambColor0[3] = s->light[0].c7;
        GXSetChanAmbColor_Internal(0, (void *)ambColor0);
        ambient2Color = *(int *)blackColor;
        GXSetChanAmbColor_Internal(2, &ambient2Color);
    }

    if ((unsigned int)(unsigned char)lbl_8055FD25 != (unsigned int)lbl_8055FD85 ||
        lbl_8055FD84 != 0) {
        pB0 = s->raw + 0xB0;
        lbl_8055FD85 = lbl_8055FD25;
        lbl_8055FD84 = 0;
        if (*(int *)(pB0 + 4) == 0)
            *pB0 = 1;
        GXSetNumChans(1);
        if ((unsigned char)lbl_8055FD25 != 0) {
            GXSetChanCtrl(0, 1, 0, 0, 1, 2, 2);
            GXSetChanCtrl(2, 0, 0, 0, 0, 0, 2);
        } else {
            GXSetChanCtrl(0, 0, 1, 1, 0, 0, 2);
            GXSetChanCtrl(2, 0, 1, 1, 0, 0, 2);
        }
    }
}
#pragma pop
extern unsigned short lbl_8055FD08;
extern unsigned short lbl_8055FD88;

#pragma push
#pragma processor 750
extern void C_MTXPerspective(void *, float, float, float, float);
extern double atan(double);
#pragma push
#pragma processor 750
/* Rebuild and upload the GX perspective projection matrix from the camera
   settings in lbl_804C9778 (+0 is a one-shot request flag): compute the vertical
   FOV and aspect, then optionally scale/offset the matrix for one tile of a
   grid of viewports before calling GXSetProjection. */
void fn_802D14D8(void) {
    float mtx[4][4];
    float aspectScale;
    float halfAngle;
    float aspect;
    float fovRad;
    double tanHalf;
    register unsigned char *params;
    float fovDegrees;
    float aspectArg;

    if (lbl_804C9778[0] == 0) {
        return;
    }
    lbl_804C9778[0] = 0;
    if (lbl_8055FE24 != 0) {
        aspectScale = lbl_80564F8C;
    } else {
        aspectScale = lbl_80564FC8;
    }
    params = lbl_804C9778;
    aspect = aspectScale / *(float *)(params + 0x14);
    aspect = *(float *)(params + 0x18) * aspect;
    halfAngle = lbl_80564F94 * *(float *)(params + 0x0C);
    tanHalf = fn_8002EF30((double)halfAngle);
    fovRad = (float)atan((float)tanHalf / aspect);
    fovDegrees = (lbl_80564FCC * fovRad) / lbl_80564FD0;
    aspectArg = aspect;
    C_MTXPerspective(mtx, fovDegrees, aspectArg, *(float *)(params + 4), *(float *)(params + 8));
    if ((lbl_8055FE24 == 0) && ((int)lbl_8055D0B8 >= 0) && ((int)lbl_8055D0B8 < lbl_8055D0BC * lbl_8055D0C0)) {
        int gridHeight = lbl_8055D0C0;
        int gridWidth = lbl_8055D0BC;
        int tileIndex = (int)lbl_8055D0B8;
        float tileScaleX = lbl_80564F8C / (float)gridWidth;
        float tileScaleY = lbl_80564F8C / (float)gridHeight;
        mtx[0][0] /= tileScaleX;
        mtx[1][1] /= tileScaleY;
        mtx[0][2] += (float)(((tileIndex % gridWidth) * 2 - gridWidth) + 1);
        mtx[1][2] -= (float)(((tileIndex / gridWidth) * 2 - gridHeight) + 1);
    }
    GXSetProjection(mtx, 0);
}
#pragma pop
extern void GXInitLightColor(void *, unsigned char *);
extern void GXGetLightDir_Internal(void *, float, float, float, float, float, float);
extern void GXInitLightAttn(void *, float, float, float, float, float, float);
extern float PSVECMag(float *);
extern float lbl_80564F80, lbl_80564F88, lbl_80564F8C, lbl_80564F90, lbl_80564F94;
extern double lbl_80564FA0;
#pragma push
#pragma processor 750
void fn_802D17BC(void *light, float *a, float *b, unsigned char *color, float scale) {
    unsigned char rgba[4];
    float vec[3];
    float x, y, z, mag, k;
    rgba[0]=color[0]; rgba[1]=color[1]; rgba[2]=color[2]; rgba[3]=color[3];
    GXInitLightColor(light, rgba);
    x=a[0]+b[0];
    y=a[1]+b[1];
    z=a[2]+b[2];
    vec[0]=x; vec[1]=y; vec[2]=z;
    mag=PSVECMag(vec);
    mag = mag > lbl_80564F80 ? mag : lbl_80564F80;
    k=lbl_80564F90/mag;
    x=vec[0]*k; y=vec[1]*k; z=vec[2]*k;
    GXGetLightDir_Internal(light,b[0],b[1],-b[2],x,y,-z);
    {
        float v=scale*lbl_80564F94;
        GXInitLightAttn(light,lbl_80564F88,lbl_80564F88,lbl_80564F8C,v,lbl_80564F88,lbl_80564F8C-v);
    }
}

/* One entry of the scene light table (0x14 bytes): where the light sits, its
 * colour and how wide its cone is; fn_802D17BC turns it into a GX light object. */
typedef struct SceneLight_802D18E8 {
    /* 0x00 */ float pos[3];
    /* 0x0C */ unsigned char color[4];
    /* 0x10 */ float scale;
} SceneLight_802D18E8;
/* The fallback light used when the scene table is empty: colour first, then the
 * position and the strength the colour is scaled by. */
typedef struct DefaultLight_802D18E8 {
    /* 0x00 */ unsigned char c[4];
    /* 0x04 */ unsigned char pad[8];
    /* 0x0C */ float pos[3];
    /* 0x18 */ float strength;
} DefaultLight_802D18E8;
extern int lbl_8055FDC8;   /* scene light table: entries in it */
extern int lbl_8055FDCC;   /* light objects loaded into GX light channels */
extern float lbl_80564FD4; /* 64.0f: cone scale of the fallback light */
extern void GXLoadLightObjImm(void *, unsigned int);
extern void GXSetChanCtrl(int, int, int, int, unsigned int, int, int);
#pragma pop

/* Experiment: the TU's own .bss laid out as separate variables (lbl_804C5650 + offset). */
static unsigned char sBssHead_802D18E8[0x40];    /* lbl_804C5650 */
static float sViewFrom_802D18E8[12];             /* lbl_804C5690: view matrix; [9..11] is its translation */
static float sViewTo_802D18E8[0x4110 / 4];       /* lbl_804C56C0: the point looked at, same shape */
static DefaultLight_802D18E8 sDefaultLight_802D18E8; /* lbl_804C97D0 */
static unsigned char sBssGap_802D18E8[0x4A38 - 0x4180 - sizeof(DefaultLight_802D18E8)];
static unsigned char sLightEntries_802D18E8[0x90];  /* lbl_804CA088: SceneLight_802D18E8[], 0x14 each */
static unsigned char sLightObjs_802D18E8[8][0x40];  /* lbl_804CA118: GXLightObj[8] */
/* mwcc lays the pooled .bss out in order of first use by generated code; until the
   earlier functions of this file use these variables, this unused function fixes the order. */
static void BssOrder_802D18E8(void) {
    sBssHead_802D18E8[0] = 0;
    sViewFrom_802D18E8[0] = 0.0f;
    sViewTo_802D18E8[0] = 0.0f;
    sDefaultLight_802D18E8.c[0] = 0;
    sBssGap_802D18E8[0] = 0;
    sLightEntries_802D18E8[0] = 0;
    sLightObjs_802D18E8[0][0] = 0;
}
#pragma push
#pragma use_lmw_stmw off
/* Sets up the frame's lighting. The light direction is the view direction
 * (sViewFrom's translation column minus sViewTo's) normalised to length 1.0;
 * every entry of the scene light table is turned into a GX light object - or
 * the fallback light is, when the table is empty - those objects are loaded
 * into the GX light channels starting at GX_LIGHT1, and GX_COLOR1 is lit by
 * the channels they went into. */
void fn_802D18E8(void) {
    unsigned char color[4];
    float direction[3];
    float mag;
    float scale;
    SceneLight_802D18E8 *entry;
    unsigned char *lightObj;
    int count;
    int lightBit;
    int lightMask;
    int i;

    direction[0] = sViewFrom_802D18E8[9] - sViewTo_802D18E8[9];
    direction[1] = sViewFrom_802D18E8[10] - sViewTo_802D18E8[10];
    direction[2] = sViewFrom_802D18E8[11] - sViewTo_802D18E8[11];
    mag = PSVECMag(direction);
    mag = mag > lbl_80564F80 ? mag : lbl_80564F80; /* lbl_80564F80 = 0.001f */
    scale = lbl_80564F8C / mag;                    /* lbl_80564F8C = 1.0f */
    lbl_8055FDCC = 0;
    direction[0] *= scale;
    direction[1] *= scale;
    direction[2] *= scale;

    if (lbl_8055FDC8 > 0) {
        entry = (SceneLight_802D18E8 *)sLightEntries_802D18E8;
        lightObj = sLightObjs_802D18E8[0];
        count = 0;
        goto loop_test;
    loop_body:
        color[0] = entry->color[0];
        color[1] = entry->color[1];
        color[2] = entry->color[2];
        color[3] = entry->color[3];
        fn_802D17BC(lightObj, direction, entry->pos, color, entry->scale);
        entry++;
        lightObj += 0x40;
        count++;
    loop_test:
        if (count < lbl_8055FDC8) goto loop_body;
        lbl_8055FDCC = lbl_8055FDC8;
    } else {
        /* Nothing to light the scene: one light from the fallback entry, whose
         * colour is scaled by its strength and whose cone is 64.0 wide. */
        unsigned int packed;
        unsigned char rgba[4];
        float strength = sDefaultLight_802D18E8.strength;
        rgba[0] = (unsigned char)(int)(strength * (float)sDefaultLight_802D18E8.c[0]);
        rgba[1] = (unsigned char)(int)(strength * (float)sDefaultLight_802D18E8.c[1]);
        rgba[2] = (unsigned char)(int)(strength * (float)sDefaultLight_802D18E8.c[2]);
        rgba[3] = sDefaultLight_802D18E8.c[3];
        packed = *(unsigned int *)rgba;
        fn_802D17BC(sLightObjs_802D18E8[0], direction, sDefaultLight_802D18E8.pos, (unsigned char *)&packed, lbl_80564FD4);
        lbl_8055FDCC++;
    }

    lightObj = sLightObjs_802D18E8[0];
    lightMask = 0;
    i = 0;
    lightBit = GX_LIGHT1;
    goto light_test;
light_body:
    {
        int bits = lightBit << i;
        GXLoadLightObjImm(lightObj, bits);
        lightMask |= bits;
        lightObj += 0x40;
        i++;
    }
light_test:
    if (i < lbl_8055FDCC) goto light_body;
    GXSetNumChans(2);
    GXSetChanCtrl(GX_COLOR1, GX_ENABLE, GX_SRC_REG, GX_SRC_REG, lightMask, GX_DF_NONE, GX_AF_SPEC);
    GXSetChanCtrl(GX_ALPHA1, GX_DISABLE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
/* Loads a texture matrix (GX_TEXMTX0) using the negated Y-column components from lbl_804C5690. */
void fn_802D1B58(void) {
    int texMtx[8];
    float *srcMtx = (float *)lbl_804C5690;
    int *baseMtx = (int *)lbl_802FAC70;
    texMtx[0] = baseMtx[0];
    texMtx[1] = baseMtx[1];
    texMtx[2] = baseMtx[2];
    texMtx[3] = baseMtx[3];
    texMtx[4] = baseMtx[4];
    texMtx[5] = baseMtx[5];
    texMtx[6] = baseMtx[6];
    texMtx[7] = baseMtx[7];
    *(float *)&texMtx[0] = 0.5f * -srcMtx[1];
    *(float *)&texMtx[1] = 0.5f * -srcMtx[4];
    *(float *)&texMtx[2] = 0.5f * -srcMtx[7];
    GXLoadTexMtxImm((float *)texMtx, 0x21, 1);
}

extern int PSMTXTranspose(void *, void *);
extern int PSMTXScale(void *, float, float, float);
extern int PSMTXRotRad(void *, float, float, float);
extern int PSMTXConcat(void *, void *, void *);
extern int GXSetCurrentMtx(int);
extern int GXLoadNrmMtxImm(void *, int);
extern int fn_802C8588(void *, void *, void *);
extern float lbl_80564F90, lbl_80564FD8;
extern unsigned char lbl_8055FD19;
extern Mtx24_802D1C04 lbl_802FAC90;
extern float lbl_80564F90, lbl_80564FD8, lbl_80564F88;
#pragma push
#pragma dont_inline on
void fn_802D1C04(void) {
    unsigned char *base = (unsigned char *)lbl_804C5650;
    if (*(unsigned char *)&lbl_8055FD70 != 0) {
        Xform_802D1C04 inv;
        Xform_802D1C04 comb;
        float texMtx[12];
        Xform_802D1C04 rel;
        Xform_802D1C04 relInv;
        Xform_802D1C04 view;
        float viewMtx[12];
        float trans[12];
        float scale[12];
        float proj[12];
        Mtx33_802D1C04 rot;
        float nrm[12];
        Mtx24_802D1C04 tex;
        Xform_802D1C04 *src = (Xform_802D1C04 *)(base + 0x70);
        Xform_802D1C04 *b;
        float t;
        float k;
        inv.r = src->r;
        lbl_8055FD70 = 0;
        t = inv.r.m[1]; inv.r.m[1] = inv.r.m[3]; inv.r.m[3] = t;
        t = inv.r.m[2]; inv.r.m[2] = inv.r.m[6]; inv.r.m[6] = t;
        t = inv.r.m[5]; inv.r.m[5] = inv.r.m[7]; inv.r.m[7] = t;
        if (&inv.t == &src->t) {
            float x = src->t.z * src->r.m[2] + (src->t.x * src->r.m[0] + src->t.y * src->r.m[1]);
            float y = src->t.z * src->r.m[5] + (src->t.x * src->r.m[3] + src->t.y * src->r.m[4]);
            float z = src->t.z * src->r.m[8] + (src->t.x * src->r.m[6] + src->t.y * src->r.m[7]);
            inv.t.x = x; inv.t.y = y; inv.t.z = z;
        } else {
            float x = src->t.z * src->r.m[2] + (src->t.x * src->r.m[0] + src->t.y * src->r.m[1]);
            float y = src->t.z * src->r.m[5] + (src->t.x * src->r.m[3] + src->t.y * src->r.m[4]);
            float z = src->t.z * src->r.m[8] + (src->t.x * src->r.m[6] + src->t.y * src->r.m[7]);
            inv.t.x = x; inv.t.y = y; inv.t.z = z;
        }
        inv.t.x *= lbl_80564F90;
        inv.t.y *= lbl_80564F90;
        inv.t.z *= lbl_80564F90;
        b = (Xform_802D1C04 *)(base + 0x40);
        fn_801BFD34(&comb.t, &b->t, &inv);
        fn_80015B20(&comb, b, &inv);
        fn_802D0DD4(base, &comb);
        GXLoadPosMtxImm(base, 0);
        if (lbl_8055FD19 != 0) {
            lbl_8055FD19 = 0;
            GXSetCurrentMtx(0);
        }
        switch (*(int *)(base + 0xB4)) {
        case 2:
        case 3:
            fn_802C8588(&rel, &((Xform_802D1C04 *)(base + 0x70))->t, &((Xform_802D1C04 *)(base + 0x40))->t);
            relInv.r = rel.r;
            t = relInv.r.m[1]; relInv.r.m[1] = relInv.r.m[3]; relInv.r.m[3] = t;
            t = relInv.r.m[2]; relInv.r.m[2] = relInv.r.m[6]; relInv.r.m[6] = t;
            t = relInv.r.m[5]; relInv.r.m[5] = relInv.r.m[7]; relInv.r.m[7] = t;
            if (&relInv.t == &rel.t) {
                float x = rel.t.z * rel.r.m[2] + (rel.t.x * rel.r.m[0] + rel.t.y * rel.r.m[1]);
                float y = rel.t.z * rel.r.m[5] + (rel.t.x * rel.r.m[3] + rel.t.y * rel.r.m[4]);
                float z = rel.t.z * rel.r.m[8] + (rel.t.x * rel.r.m[6] + rel.t.y * rel.r.m[7]);
                relInv.t.x = x; relInv.t.y = y; relInv.t.z = z;
            } else {
                float x = rel.t.z * rel.r.m[2] + (rel.t.x * rel.r.m[0] + rel.t.y * rel.r.m[1]);
                float y = rel.t.z * rel.r.m[5] + (rel.t.x * rel.r.m[3] + rel.t.y * rel.r.m[4]);
                float z = rel.t.z * rel.r.m[8] + (rel.t.x * rel.r.m[6] + rel.t.y * rel.r.m[7]);
                relInv.t.x = x; relInv.t.y = y; relInv.t.z = z;
            }
            relInv.t.x *= lbl_80564F90;
            relInv.t.y *= lbl_80564F90;
            relInv.t.z *= lbl_80564F90;
            b = (Xform_802D1C04 *)(base + 0x40);
            fn_801BFD34(&view.t, &b->t, &relInv);
            fn_80015B20(&view, b, &relInv);
            fn_802D0DD4(viewMtx, &view);
            PSMTXTranspose(viewMtx, texMtx);
            PSMTXScale(scale, lbl_80564F94, lbl_80564FD8, lbl_80564F88);
            PSMTXRotRad(trans, lbl_80564F94, lbl_80564F94, lbl_80564F8C);
            PSMTXConcat(trans, scale, proj);
            GXLoadTexMtxImm(texMtx, 0x2A, 0);
            GXLoadTexMtxImm(proj, 0x4C, 0);
            break;
        case 1:
        case 5:
            rot = ((Xform_802D1C04 *)(base + 0x40))->r;
            tex = lbl_802FAC90;
            t = rot.m[1]; rot.m[1] = rot.m[3]; rot.m[3] = t;
            t = rot.m[2]; rot.m[2] = rot.m[6]; rot.m[6] = t;
            t = rot.m[5]; rot.m[5] = rot.m[7]; rot.m[7] = t;
            k = lbl_80564F94;
            tex.m[0][0] = k * rot.m[0];
            tex.m[0][1] = k * rot.m[1];
            tex.m[0][2] = k * rot.m[2];
            tex.m[1][0] = k * rot.m[3];
            tex.m[1][1] = k * rot.m[4];
            tex.m[1][2] = k * rot.m[5];
            GXLoadTexMtxImm(&tex, 0x2A, 1);
            break;
        case 4:
            fn_802D18E8();
            break;
        }
        fn_802D0DD4(nrm, base + 0x40);
        nrm[3] = nrm[7] = nrm[11] = lbl_80564F88;
        GXLoadNrmMtxImm(nrm, 0);
        if (*(int *)(base + 0xB4) == 2) fn_802D1B58();
    }
}
#pragma pop
extern float lbl_80564FCC;
extern float lbl_80564FDC;
#pragma push
#pragma processor 750
#pragma opt_propagation off
void fn_802D2218(void) {
    typedef struct GxState {
        char pad0[0x24];
        int width;
        int height;
        unsigned char b2c, b2d, b2e, b2f, b30, b31;
    } GxState;
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
    float vertexZ;
    register volatile float *fifo;
    float temp_f30;
    float temp_f31;
    int temp_r4;
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
    register unsigned char *base;
    register GxState *state;
    unsigned char *temp_r3_2;
    unsigned char *temp_r3_3;
    unsigned char *temp_r4_2;
    unsigned char *temp_r7;
    base = (unsigned char *)lbl_804C5650;
    state = (GxState *)(base + 0x4128);
    if ((state->b2d != 0) || (state->b2c != 0)) {
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
        screenWidth = state->width;
        screenHeight = state->height;
        temp_f31 = lbl_80564F94 * (float)screenWidth;
        temp_f30 = lbl_80564F94 * (float)screenHeight;
        C_MTXOrtho(sp20, temp_f30, -temp_f30, -temp_f31, temp_f31, lbl_80564F8C, lbl_80564FCC);
        GXSetProjection(sp20, 1);
        GXSetDstAlpha(0, 0);
        GXSetBlendMode(0, 1, 0, 5);
        GXSetColorUpdate(state->b2d);
        GXSetAlphaUpdate(state->b2d);
        GXSetZMode(1, 7, state->b2c);
        temp_r7 = base + 0x4160;
        temp_r6 = temp_r7[2];
        temp_r5 = temp_r7[3];
        fogColor[0] = temp_r7[1];
        fogColor[1] = temp_r6;
        fogColor[2] = temp_r5;
        fogColor[3] = temp_r7[4];
        GXSetFog(0, fogColor, temp_r5, temp_r6, temp_r7, lbl_80564F88, lbl_80564F88, lbl_80564F88, lbl_80564F88);
        GXSetNumTevStages(1);
        GXSetNumTexGens(0);
        temp_r7_2 = state->b2e;
        temp_r6_2 = state->b2f;
        temp_r5_2 = state->b30;
        tevColor[0] = temp_r7_2;
        tevColor[1] = temp_r6_2;
        tevColor[2] = temp_r5_2;
        tevColor[3] = state->b31;
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
        vertexZ = lbl_80564FDC;
        fifo = (volatile float *)0xCC010000;
        var_r4 = 0;
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
        temp_r3_2 = base + 0x4128;
        temp_r3_2[0x2C] = 0;
        temp_r3_2[0x2D] = 0;
        fn_802CFF50();
        temp_r3_2[0] = 1;
        fn_802D14D8();
        temp_r4_2 = base + 0x4180;
        base[0xB0] = 1;
        temp_r3_3 = base + 0x4160;
        lbl_8055FD70 = 1;
        temp_r4_2[0x5C] = 1;
        temp_r3_3[0x1C] = 1;
        fn_802D6C68();
    }
}
#pragma pop
/* Refresh the GX pipeline for the frame: rebuild the perspective projection,
 * set the viewport/scissor, set up the 2D overlay pass, and flush pending
 * render-state changes (blend mode, fog, lights, TEV colors). */
void fn_802D2614(void) {
    fn_802D14D8();
    fn_802D1678();
    fn_802D2218();
    fn_802D0EEC();
}

/* Disable indirect texturing and set TEV stages 0-3 to sample their textures directly. */
void fn_802D2640(void) {
    int stage;

    GXSetNumIndStages(0);
    stage = 0;
    do {
        GXSetTevDirect(stage);
        stage++;
    } while (stage < 4);
}

extern void (*lbl_8055FD80)(void);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
// Builds the GX TEV pipeline for the scene's default draw mode (mode 0 of the
// render request block lbl_804C5700, applied by fn_802D2B0C): a base texture
// pass, plus optional detail, second-texture and indirect (bump) stages.
void fn_802D2684(void) {
    unsigned int passThroughFlag; // GX state flag 0x40: TEV0 passes the texture through
    unsigned char secondTexFlag;  // request +0x08: extra modulated texture stage
    unsigned char detailTexFlag;  // request +0x09: base * detail pass
    unsigned char indirectFlag;   // request +0x0A: indirect (bump) texture stage
    int tevStage;
    int texGen;
    int alphaCount;
    int alphaSrc[4];
    int utcLod;
    int alphaSel;

    detailTexFlag = (unsigned char)lbl_804C5700[9];
    passThroughFlag = ((unsigned long)lbl_8055FD1C >> 6) & 1;
    tevStage = 0;
    secondTexFlag = (unsigned char)lbl_804C5700[8];
    texGen = 0;
    indirectFlag = (unsigned char)lbl_804C5700[10];

    // Texcoord 0 from texture 0, either through the texture matrix or untouched.
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0,
                      lbl_804C5700[12] != 0 ? GX_TEXMTX0 : GX_IDENTITY, FALSE, GX_PTIDENTITY);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    if (passThroughFlag != 0) {
        GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    } else if (detailTexFlag != 0) {
        GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
        texGen = 1;
        GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX1, GX_IDENTITY, FALSE, GX_PTIDENTITY);
        tevStage = 1;
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP3, GX_COLOR0A0);
        GXSetTevOp(GX_TEVSTAGE1, GX_MODULATE);
    } else {
        // Color = raster color, alpha = the two sources the material asks for.
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
        alphaCount = 0;
        if (((unsigned long)lbl_8055FD1C & 0x100) != 0) {
            alphaSrc[0] = GX_CA_TEXA;
            alphaCount = 1;
        }
        if (((unsigned char *)&lbl_804C97D0)[8] < 0xFF) {
            alphaSrc[alphaCount] = GX_CA_A0;
            alphaCount++;
        }
        if (((unsigned char *)&lbl_8055FD25)[0] == 0 && alphaCount < 2) {
            alphaSrc[alphaCount] = GX_CA_RASA;
            alphaCount++;
        }
        while (alphaCount < 2)
            alphaSrc[alphaCount++] = GX_CA_KONST;
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_AOP_AND, GX_AOP_AND, GX_AOP_AND, TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, alphaSrc[0], alphaSrc[1], GX_CA_ZERO);
    }

    if (secondTexFlag != 0) {
        tevStage++;
        GXSetTevOrder(tevStage, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR0A0);
        GXSetTevColorOp(tevStage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
        GXSetTevColorIn(tevStage, GX_CC_CPREV, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
        GXSetTevAlphaOp(tevStage, GX_AOP_AND, GX_AOP_AND, GX_AOP_AND, TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(tevStage, GX_CA_ZERO, GX_CA_APREV, GX_CA_TEXA, GX_CA_ZERO);
    }
    if (indirectFlag != 0) {
        texGen++;
        GXSetTexCoordGen2(texGen, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX5, FALSE, GX_PTIDENTITY);
        tevStage++;
        GXSetTevOrder(tevStage, texGen, GX_TEXMAP5, GX_COLOR_NULL);
        GXSetTevColorIn(tevStage, GX_CC_CPREV, GX_CC_TEXC, GX_CC_TEXA, GX_CC_ZERO);
        GXSetTevColorOp(tevStage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(tevStage, GX_CA_APREV, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
        GXSetTevAlphaOp(tevStage, GX_AOP_AND, GX_AOP_AND, GX_AOP_AND, TRUE, GX_TEVPREV);
    }
    GXSetNumTevStages((unsigned char)(tevStage + 1));
    GXSetNumTexGens((unsigned char)(texGen + 1));
    if (lbl_804C5700[13] != 0) {
        // Alpha blend the bump-modulated result and read the bump map through
        // indirect stage 0; the stages are reset again before the next pass.
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_BL_INVSRCALPHA);
        GXSetNumIndStages(1);
        utcLod = 0;
        alphaSel = 0;
        GXSetTevIndirect(GX_TEVSTAGE0, GX_INDTEXSTAGE0, GX_ITF_8, GX_ITB_ST, GX_ITM_0, GX_ITW_OFF,
                         GX_ITW_OFF, FALSE, utcLod, alphaSel);
        GXSetIndTexOrder(GX_INDTEXSTAGE0, GX_TEXCOORD1, GX_TEXMAP2);
        GXSetNumTexGens(2);
        GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX1, FALSE, GX_PTIDENTITY);
        lbl_8055FD80 = fn_802D2640;
    }
}
#pragma pop
#pragma scheduling on
void fn_802D2AC4(void) {
#define ResetTevSwapModes fn_802DFAF4
    /* Configure one color channel with no lighting and reset TEV swap modes. */
    GXSetNumChans(1);
    GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
    ResetTevSwapModes();
#undef ResetTevSwapModes
}

extern unsigned char lbl_804C9930[];
static inline void SetAppliedFlags_802D2B0C(unsigned char f8, unsigned char f9, unsigned char fA,
                                            unsigned char fB, unsigned char fC, unsigned char fD) {
    lbl_804C9930[8] = f8;
    lbl_804C9930[9] = f9;
    lbl_804C9930[0xA] = fA;
    lbl_804C9930[0xB] = fB;
    lbl_804C9930[0xC] = fC;
    lbl_804C9930[0xD] = fD;
}
void fn_802D2B0C(void) {
    extern unsigned char lbl_804C9930[];
    extern unsigned short lbl_8055FD0C;
    extern int memcmp(const void *, const void *, unsigned long);
    extern void fn_802DF21C(void);
    extern void fn_802DF2F0(void);
    extern void fn_802E09EC(void);
    extern void fn_802E0B68(void);
    extern void fn_802DF300(void);
    extern void fn_802DF46C(void);
    extern void fn_802DEFA0(void);
    extern void fn_802DF1B4(void);
    extern void fn_802D18E8(void);
    extern void fn_802DF994(void);
    extern void fn_802D2AC4(void);
    extern void fn_802DF6D0(void);
    extern void fn_802DF938(void);
    extern void fn_802DF4A8(void);
    extern void fn_802DF684(void);
    extern void fn_802D1C04(void);
    int diff;
    register int zero = 0;
    int t4;
    unsigned char t8, t9, tA, tB, tC, tD;
    if (*(unsigned char *)&lbl_8055FDB4 == 0) {
        diff = memcmp(lbl_804C9930, lbl_804C5700, 0x10);
        if (((unsigned int)(unsigned int)(0 - diff | diff) >> 31) != 0) {
            if (lbl_8055FD80 != 0) {
                lbl_8055FD80();
                lbl_8055FD80 = 0;
            }
            switch (*(int *)(lbl_804C5700 + 4)) {
            case 1:
                lbl_8055FD70 = 1;
                fn_802DF21C();
                lbl_8055FD80 = fn_802DF2F0;
                break;
            case 5:
                lbl_8055FD70 = 1;
                fn_802E09EC();
                lbl_8055FD80 = fn_802E0B68;
                break;
            case 2:
                lbl_8055FD70 = 1;
                if (lbl_804C5700[0xA] != 0) {
                    fn_802DF300();
                    lbl_8055FD80 = fn_802DF46C;
                } else {
                    fn_802DEFA0();
                    lbl_8055FD80 = fn_802DF1B4;
                }
                break;
            case 4:
                fn_802D18E8();
                fn_802DF994();
                lbl_8055FD80 = fn_802D2AC4;
                lbl_8055FD70 = 1;
                break;
            case 3:
                if (lbl_8055FD86 == lbl_8055FD0C) {
                    fn_802D2684();
                } else {
                    if (lbl_804C5700[8] != 0) {
                        fn_802DF6D0();
                        lbl_8055FD80 = fn_802DF938;
                    } else {
                        fn_802DF4A8();
                        lbl_8055FD80 = fn_802DF684;
                    }
                    lbl_8055FD70 = 1;
                }
                break;
            case 0:
                fn_802D2684();
                break;
            default:
                break;
            }
            t4 = *(int *)(lbl_804C5700 + 4);
            t8 = lbl_804C5700[8];
            t9 = lbl_804C5700[9];
            tA = lbl_804C5700[0xA];
            tB = lbl_804C5700[0xB];
            tC = lbl_804C5700[0xC];
            tD = lbl_804C5700[0xD];
            lbl_804C5700[0] = (unsigned char)zero;
            lbl_804C9930[0] = (unsigned char)zero;
            *(int *)(lbl_804C9930 + 4) = t4;
            lbl_804C9930[8] = t8;
            lbl_804C9930[9] = t9;
            lbl_804C9930[0xA] = tA;
            lbl_804C9930[0xB] = tB;
            lbl_804C9930[0xC] = tC;
            lbl_804C9930[0xD] = tD;
        }
    }
    fn_802D1C04();
}

#pragma small_data off
extern char lbl_804C97D0;
#pragma small_data off
__declspec(section ".rodata") extern char lbl_804C97D0;
void *fn_802D2D04(void) {
#define sDefaultLight lbl_804C97D0
    /* Return a pointer to the default light's float direction vector (offset 0xC). */
    return &sDefaultLight + 0xC;
#undef sDefaultLight
}
#pragma small_data on
extern void *lbl_8055FD64;
void* fn_802D2D14(void) {
#define renderMode lbl_8055FD64
    /* Get the current video render mode (the active VI/render config block). */
    return renderMode;
#undef renderMode
}

/* Lighting transform state used by fn_802D2ED8 (driven by the CPU-light pass in
 * cpulight.c).  A light record is a 3x3 rotation matrix at +0x00 followed by its
 * world position at +0x24; records are 0x34 bytes apart.
 *   GX_LIGHT_XF_MTX   3x4 matrix lights are transformed by (the current view
 *                     transform, rebuilt by fn_802D2D1C from the camera at
 *                     lbl_804C56C0); the light rotation and position are
 *                     multiplied by it.
 *   GX_POSMTX_SCRATCH scratch 3x4 matrix: the transformed light, transposed with
 *                     its third row negated, is written here and handed to
 *                     GXLoadPosMtxImm.
 *   GX_XF_DIRTY       set whenever the XF/transform state changes; cleared when
 *                     fn_802D1C04 next recomputes it.
 *   GX_XF_INDEX       transform preset currently applied (-1 = none). */
#define GX_LIGHT_XF_MTX   lbl_804CA2D8
#define GX_POSMTX_SCRATCH lbl_804C5650
#define GX_XF_DIRTY       lbl_8055FD70
#define GX_XF_INDEX       lbl_8055FD8C

#pragma dont_inline on
void fn_802D2ED8(int light, int index) {
    /* Transform one point light into the current view space and load it into GX
     * position-matrix slot index*3.  `light` points at a light record (3x3
     * rotation at +0x00, world position at +0x24).  Its position is transformed
     * by GX_LIGHT_XF_MTX into matrix+0x24, its rotation multiplied by the same
     * matrix into matrix, the result transposed (third row negated) into
     * GX_POSMTX_SCRATCH, and that loaded as the light's position matrix.  Light 0
     * also marks the XF state dirty and drops the applied-preset cache. */
    float matrix[12];
    int *base;

    if (index == 0) {
        GX_XF_DIRTY = 1;
        GX_XF_INDEX = -1;
    }
    base = GX_LIGHT_XF_MTX;
    fn_801BFD34((unsigned char *)matrix + 0x24, (unsigned char *)light + 0x24, base);
    fn_80015B20(matrix, (void *)light, base);
    fn_802D0DD4(GX_POSMTX_SCRATCH, matrix);
    GXLoadPosMtxImm(GX_POSMTX_SCRATCH, (index * 4) - index);
}
#pragma dont_inline off

/* Load the primary (slot 0) point light: forwards the light record to
 * fn_802D2ED8 with index 0, which also marks the XF state dirty. */
void fn_802D2F70(int light) {
    fn_802D2ED8(light, 0);
}

int fn_802D2F78(int *outWidth, int *outHeight) {
    /* Prepare/framebuffer handoff helper: disable draw-sync callback state, flush VI, mark buffer in-use, and return stored buffer pointer with its dimensions. */
    int *data;
    int value;
    GXSetDrawSyncCallback();
    VIFlush();
    data = lbl_804C9760;
    value = data[2];
    *((unsigned char *)data + 0x14) = 1;
    *outWidth = value;
    *outHeight = data[3];
    return data[1];
}

/* Show the frame the game just drew into the EFB copy buffer: mark the buffer
 * free again, push it out of the cache, hand it to the video interface and
 * wait one retrace for it to appear.  Pairs with fn_802D2F78, which hands out
 * that buffer (and sets the in-use flag this clears) so the on-screen message
 * box can be drawn straight into it.
 *
 * The block GX_XFB_BLOCK (lbl_804C9760) holds:
 *   [0] base of the allocated buffer   [3] height in rows
 *   [1] buffer drawn into and shown    [4] bytes per pixel (2)
 *   [2] width in pixels                [0x14] in-use flag, as a byte */
void fn_802D2FD8(void) {
    ((unsigned char *)GX_XFB_BLOCK)[0x14] = 0;
    DCFlushRange((void *)GX_XFB_BLOCK[1],
        (unsigned long)(GX_XFB_BLOCK[4] * (GX_XFB_BLOCK[2] * GX_XFB_BLOCK[3])));
    VISetNextFrameBuffer((void *)GX_XFB_BLOCK[1]);
    VIFlush();
    VIWaitForRetrace();
    VISetBlack(0);
    GX_XFB_BLOCK[1] = GX_XFB_BLOCK[0];
}

/* Enable or disable alpha updates by toggling bit 4 (0x10) of the global render-state word. */
void fn_802D3050(int enable) {
    unsigned long value;

    value = (unsigned long)lbl_8055FD1C & 0xFFFFFFEF;
    if (enable != 0) {
        value = (unsigned long)lbl_8055FD1C | 0x10;
    }
    lbl_8055FD1C = (void *)value;
}

/* Enable destination alpha and cache the value for later GXSetDstAlpha calls. */
void fn_802D306C(unsigned char alpha) {
#define gDstAlpha lbl_8055FD60
    gDstAlpha = alpha;
    GXSetDstAlpha(1, alpha);
#undef gDstAlpha
}

extern void GXSetIndTexMtx(int, void *, int);
/* Loads the default indirect-texture scale matrix into indirect texture matrix 1. */
void fn_802D307C(void) {
    int indTexMtx[6];
    int *src = (int *)lbl_802FACB0;
    indTexMtx[0] = src[0]; indTexMtx[1] = src[1]; indTexMtx[2] = src[2]; indTexMtx[3] = src[3]; indTexMtx[4] = src[4]; indTexMtx[5] = src[5];
    GXSetIndTexMtx(1, indTexMtx, 1);
}

extern void *lbl_8055FD5C;
/* Set the global graphics-state object pointer (read by fn_802D3104 et al.
   for the GXTexObj/indirect-texture state at +0x24). */
void fn_802D30DC(void* state) {
    lbl_8055FD5C = state;
}

/* Return the GXTexObj at +0x24 of the global GX state block; the caller loads it
 * as the indirect texture (GXLoadTexObj, map 7). */
void* fn_802D30E4(void) {
    struct { char pad[0x24]; char texObj; } *state;
    state = lbl_8055FD54;
    return &state->texObj;
}

#pragma dont_inline on
/* Return the GXTexObj at +0x24 of the global GX state block held in lbl_8055FE1C;
 * the caller loads it as the indirect texture (GXLoadTexObj, map 6). */
void* fn_802D30F0(void) {
    struct { char pad[0x24]; char texObj; } *state;
    state = lbl_8055FE1C;
    return &state->texObj;
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
    /* Load the default indirect-texture matrix, then return the address of the
       +0x24 field of the global graphics-state object held in lbl_8055FD5C. */
    struct { char pad[0x24]; char m; } *state;
    fn_802D307C();
    state = lbl_8055FD5C;
    return &state->m;
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
    /* Return the GXTexObj at +0x24 of the global GX state block in lbl_8055FD58;
       the caller loads it as the indirect texture (GXLoadTexObj, map 7). */
    struct { char pad[0x24]; char texObj; } *state;
    state = lbl_8055FD58;
    return &state->texObj;
}

#pragma dont_inline on
void fn_802D3144(void) {
    register unsigned short ref = lbl_8055FD08;
    if (lbl_8055FD86 == ref) {
        GXSetBlendMode(0, 0, 0, 5);
    } else {
        int lowMapped;
        int high;
        int low;
        high = lbl_8055FD86 >> 8;
        low = lbl_8055FD86 & 0xFF;
        lowMapped = fn_802D0EC8(low);
        GXSetBlendMode(1, fn_802D0EC8(high), lowMapped, 5);
    }
    lbl_8055FD88 = lbl_8055FD86;
    lbl_804C5700[0] = 1;
}

int fn_802D31D8(void)
{
  unsigned long new_var;
  volatile unsigned char col[4];
  unsigned long c;
  lbl_8055FDB4 = 1;
  GXSetColorUpdate(0);
  GXSetAlphaUpdate(1);
  GXSetDstAlpha(0, 0);
  new_var = c;
  fn_802CF5D4();
  lbl_8055FD1C = (void *) (((unsigned long) lbl_8055FD1C) & 0xFFFFFFF7);
  GXSetNumTevStages(1);
  GXSetNumTexGens(0);
  c = 7;
  GXSetZMode(1, 6, 0);
  GXSetTevOrder(0, 0xFF, 0xFF, 4);
  GXSetTevAlphaIn(0, c, c, c, 1);
  GXSetTevAlphaOp(0, 0, 0, 0, 0, 0);
  GXSetTevColorOp(0, 0, 0, 0, 1, 0);
  GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xF);
  c = fn_802CE9FC(0, 0, 0, 4);
  col[3] = c;
  col[0] = c >> 24;
  col[1] = new_var >> 16;
  col[2] = new_var >> 8;
  ((void (*)(int, volatile unsigned char *)) GXSetTevColor)(1, col);
  return 1;
}

#pragma dont_inline reset

/* Reset GX render state to a simple default (no cull, TEV stage 0 pass-through). */
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
#pragma dont_inline on
void fn_802D3360(void) {
    /* Initialize GX/TEV state for this render path: reset helpers, enable pending render flags, set texcoord generators, configure stages, and select matrix 0. */
    int texCoord;

    fn_802CF5D4();
    lbl_8055FD84 = 1;
    lbl_804C5700[0] = 1;
    fn_802CFF50();
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    texCoord = 0;
    do {
        GXSetTexCoordGen2(texCoord, 1, 4, 0x3C, 0, 0x7D);
        texCoord += 1;
    } while (texCoord < 4);
    fn_802D2640();
    if (lbl_8055FE1C != 0) fn_802D92B0();
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOp(0, 0);
    GXSetCurrentMtx(0);
}

extern float lbl_80564FE0, lbl_80564FE4;
#pragma push
#pragma processor 750
void fn_802D3420(void) {
    float ident[3][4], mtx[3][4], proj[4][4];
    float width, height, zero = lbl_80564F88, one = lbl_80564F8C;
    volatile float *fifo = (volatile float *)0xCC008000;
    ident[0][1] = zero;
    ident[0][0] = one;
    ident[0][2] = zero;
    ident[0][3] = zero;
    ident[1][0] = one;
    ident[1][1] = zero;
    ident[1][2] = zero;
    ident[1][3] = zero;
    ident[2][0] = one;
    ident[2][1] = zero;
    ident[2][2] = zero;
    ident[2][3] = zero;
    fn_802D0DD4(mtx, ident);
    GXLoadPosMtxImm(mtx, 0);
    C_MTXOrtho(proj, lbl_80564F88, lbl_80564FBC, lbl_80564F88, lbl_80564FE0, lbl_80564F8C, lbl_80564FCC);
    GXSetProjection(proj, 1);
    GXSetCullMode(0);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(13, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 13, 1, 4, 0);
    width = (float)*(int *)(lbl_804C9778 + 0x24) / lbl_80564FE0;
    height = width * (float)*(int *)(lbl_804C9778 + 0x28) / lbl_80564FB8;
    GXBegin(0x80, 0, 4);
    *fifo = lbl_80564F88; *fifo = lbl_80564F88; *fifo = lbl_80564FE4; *fifo = lbl_80564F88; *fifo = lbl_80564F88;
    *fifo = lbl_80564FE0; *fifo = lbl_80564F88; *fifo = lbl_80564FE4; *fifo = width; *fifo = lbl_80564F88;
    *fifo = lbl_80564FE0; *fifo = lbl_80564FBC; *fifo = lbl_80564FE4; *fifo = width; *fifo = height;
    *fifo = lbl_80564F88; *fifo = lbl_80564FBC; *fifo = lbl_80564FE4; *fifo = lbl_80564F88; *fifo = height;
    fn_802D6C68();
    lbl_804C9778[0] = 1;
    lbl_8055FD70 = 1;
}

void fn_802D362C(s32 arg0) {
    unsigned char color[4];
    unsigned int packed;

    GXSetTexCopySrc((u16)*(int *)(lbl_804C9778 + 0x1C), (u16)*(int *)(lbl_804C9778 + 0x20), (u16)*(int *)(lbl_804C9778 + 0x24), (u16)*(int *)(lbl_804C9778 + 0x28));
    GXSetTexCopyDst((u16)*(int *)(lbl_804C9778 + 0x24), (u16)*(int *)(lbl_804C9778 + 0x28), 0x27, 0);
    GXCopyTex((void *)lbl_804C9940, 0);
    __GXSetGenMode();
    GXSetColorUpdate(1);
    GXSetAlphaUpdate(0);
    GXSetDstAlpha(0, 0);
    GXSetNumTevStages(1);
    GXSetNumTexGens(1);
    GXLoadTexObj((char *)&lbl_804C9940 + 4, 0);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(0, 0xF, 0xF, 0xF, 2);
    GXSetTevAlphaOp(0, 0xE, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 4, 7, 1, 7);
    GXSetBlendMode(1, 4, 5, 3);
    GXSetZMode(0, 3, 0);
    GXSetTexCoordGen2(0, 1, 0xC, 0x3C, 0, 0x7D);
    packed = ((unsigned int (*)(unsigned int))fn_802CEA1C)((unsigned int)arg0);
    color[0] = (unsigned char)(packed >> 24);
    color[1] = (unsigned char)(packed >> 16);
    color[2] = (unsigned char)(packed >> 8);
    color[3] = (unsigned char)packed;
    GXSetTevColor(1, color);
    fn_802D3420();
}

#pragma pop

// Depth queries, pool at 0x804C9984 (lbl_804C9984). fn_802D39A4 takes a free
// query, fn_802D3A5C projects a world point into it (pixel x/y + its 24-bit
// fixed point depth) and queues it for a depth read, and fn_802D3900 reads the
// depth back for every queued query. fn_802D37E4 releases them all.
typedef struct {
    int x;                 // +0x00 screen pixel column of the point
    int y;                 // +0x04 screen pixel row of the point
    unsigned int z;        // +0x08 point depth, 24-bit fixed point
    unsigned char used;    // +0x0C query is taken from the pool
    unsigned char visible; // +0x0D point is nearer than the depth at its pixel
    float step;            // +0x10 fade step toward the read visibility
    float fade;            // +0x14 faded visibility, 0..1
} ZQuery;

typedef struct {
    ZQuery query[64];      // +0x000 the pool
    ZQuery *pending[64];   // +0x600 queries waiting for their depth read
    int pendingCount;      // +0x700 entries in pending
} ZQueryPool;

#pragma dont_inline reset
/* Release every depth query in the pool: mark all 64 unused/invisible and empty the pending queue. */
void fn_802D37E4(void) {
    ZQueryPool *pool = (ZQueryPool *)lbl_804C9984;
    int queryIndex;
    for (queryIndex = 0; queryIndex < 64; queryIndex++) {
        pool->query[queryIndex].used = 0;
        pool->query[queryIndex].visible = 0;
    }
    *(int *)((char *)lbl_804C9984 + 0x700) = 0;
}

void fn_802D3894(void) {
    ZQuery *query = (ZQuery *)lbl_804C9984;
    int i;
    /* Panic if any visibility-test depth query is still checked out of the pool. */
    for (i = 0; i < 0x40; i++, query++) {
        if (query->used != 0) {
            fn_802E317C((const char *)lbl_8034C1C4);
        }
    }
}

// Reads back the depth of every query fn_802D3A5C queued this frame and marks
// the query visible when its own depth is nearer than the depth read at its
// pixel, then empties the queue. GXInitLightDir (the draft's name for the GX
// read helper in auto/text_8003DB9C.c) reads one word out of the GX read
// window: *(volatile u32 *)(0xC8000000 + (1 << 22) + (row << 12) + (col << 2)).
void fn_802D3900(void) {
    ZQueryPool *pool;
    ZQuery **slot;
    int count = 0;
    ZQuery *query;
    unsigned long depth;
    slot = (ZQuery **)lbl_804C9984;
    pool = (ZQueryPool *)slot;
    while (count < pool->pendingCount) {
        query = slot[0x600 / sizeof(ZQuery *)];
        GXInitLightDir(query->x, query->y, &depth);
        query->visible = query->z < depth;
        slot++;
        count++;
    }
    pool->pendingCount = 0;
}

extern char lbl_8034C1E4[];
extern float lbl_80564F88;
#pragma processor 7400
void *fn_802D39A4(float value) {
    unsigned char *p;
    int index = 0;
    unsigned char *found = 0;
    int count;
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
    initialValue = lbl_80564F88;
    found[0xC] = 1;
    found[0xD] = 0;
    *(float *)(found + 0x10) = value;
    *(float *)(found + 0x14) = initialValue;
    return found;
}
#pragma processor gekko
/* Free a GX effect/light pool entry by clearing its in-use flag at offset 0xC
   (entries are allocated by fn_802D39A4). */
void fn_802D3A50(void *effect) { ((unsigned char *)effect)[0xC] = 0; }

extern float lbl_80564F88, lbl_80564F8C, lbl_80564FB8, lbl_80564FBC, lbl_80564FE8, lbl_80564FEC;
#pragma push
#pragma processor 7400
#pragma paired off
#pragma paired_single off
#pragma scheduling invalid_target
int fn_802D3A5C(void *arg0, float *arg1) {
    extern unsigned char lbl_804C9778[];
    float scaledY = lbl_80564FB8 * arg1[1];
    float xValue = arg1[0];
    float yValue = scaledY / lbl_80564FBC;
    int x = (int)xValue;
    int y = (int)yValue;
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
typedef struct { float x, y, z; } FifoVec3;
typedef struct { FifoVec3 pos; unsigned int color; float u, v; } FifoVtx;
extern void fn_802D68C4(FifoVtx *, int, unsigned short *, int);
#pragma push
#pragma processor 750
void fn_802D3BB4(float *arg0, float *arg1, float *arg2, float *arg3, unsigned int arg4, float scale, unsigned int arg_sp0) {
    FifoVtx verts[4];
    unsigned short indices[6];
    float p0 = arg1[0], p1 = arg1[1], p2 = arg1[2];
    float a0 = arg2[0], a1 = arg2[1], a2 = arg2[2];
    float b0 = arg3[0], b1 = arg3[1], b2 = arg3[2];
    unsigned int alpha = (arg4 & 0xFFFFFF) | ((unsigned int)(int)(arg0[5] * (float)(arg4 >> 24)) << 24);
    float neg = -scale;

    indices[0] = lbl_802FACC8[0];
    indices[1] = lbl_802FACC8[1];
    indices[2] = lbl_802FACC8[2];
    indices[3] = lbl_802FACC8[3];
    indices[4] = lbl_802FACC8[4];
    indices[5] = lbl_802FACC8[5];

    verts[0].pos.x = p0 + a0 * scale;
    verts[0].pos.y = p1 + a1 * scale;
    verts[0].pos.z = p2 + a2 * scale;
    verts[1].pos.x = p0 + b0 * scale;
    verts[1].pos.y = p1 + b1 * scale;
    verts[1].pos.z = p2 + b2 * scale;
    verts[2].pos.x = p0 + b0 * neg;
    verts[2].pos.y = p1 + b1 * neg;
    verts[2].pos.z = p2 + b2 * neg;
    verts[3].pos.x = p0 + a0 * neg;
    verts[3].pos.y = p1 + a1 * neg;
    verts[3].pos.z = p2 + a2 * neg;

    verts[3].color = alpha;
    verts[2].color = alpha;
    verts[1].color = alpha;
    verts[0].color = alpha;

    verts[2].u = lbl_80564F88;
    verts[0].u = lbl_80564F88;
    verts[3].u = lbl_80564F8C;
    verts[1].u = lbl_80564F8C;
    verts[1].v = lbl_80564F88;
    verts[0].v = lbl_80564F88;
    verts[3].v = lbl_80564F8C;
    verts[2].v = lbl_80564F8C;

    fn_802D68C4(verts, 4, indices, 6);
}
#pragma pop

void fn_802D3D50(void) {
    /* Disable the GX state block (active flag at +0x0) and mark it for update (+0x1C). */
    lbl_804C97B0[0] = 0;
    lbl_804C97B0[0x1C] = 1;
}

extern void OSReport(const char *, ...);
extern void GXInitVtxDescList(int);
extern void GXDisableBreakPt(void);
extern void GXLoadTexObj(void *, int);
extern volatile int lbl_8055FDD0;
extern char lbl_8034C204[];
void fn_802D3D6C(void) {
    /* Enable texture-matrix 0 for texcoord 0 in the shared render request block
       (request +0xC selects GX_TEXMTX0 instead of GX_IDENTITY in fn_802D2684). */
#define texCoordMtxFlag lbl_804C5700[12]
    texCoordMtxFlag = 1;
#undef texCoordMtxFlag
}

void fn_802D3D80(void) {
    /* Disable texture-matrix 0 for texcoord 0 in the shared render request block
       (request +0xC selects GX_IDENTITY instead of GX_TEXMTX0 in fn_802D2684). */
    lbl_804C5700[12] = 0;
}

extern void GXLoadTexMtxImm(void *, unsigned int, unsigned char);
void fn_802D3D94(int texMtxIndex, void *mtx) {
    /* Load a 2x4 texture matrix into GX texture-matrix slot texMtxIndex
       (matrix id 30 + 3*index). */
    GXLoadTexMtxImm(mtx, texMtxIndex * 3 + 30, 1);
}

#pragma opt_propagation off
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
#pragma opt_propagation reset
void fn_802D3DF8(int texObjBase, signed char scaleExp, float scaleS, float scaleT) {
    /* Set indirect texture matrix 1 from scale factors and load tex object (+0x24) into map 2. */
    float indMtx[2][3];

    lbl_804C5700[13] = 1;
    ((void (*)(void *, int, void *))GXLoadTexObj)((char *)texObjBase + 0x24, 2, lbl_804C5700);
    *(int *)&indMtx[0][0] = 0;
    *(int *)&indMtx[1][1] = 0;
    *(int *)&indMtx[0][1] = 0;
    *(int *)&indMtx[0][2] = 0;
    *(int *)&indMtx[1][0] = 0;
    *(int *)&indMtx[1][2] = 0;
    indMtx[0][0] = scaleS;
    indMtx[1][1] = scaleT;
    GXSetIndTexMtx(1, indMtx, scaleExp);
}

extern unsigned long lbl_8055D0B8;
__declspec(section ".data") extern unsigned char lbl_804C5710[4];
extern int lbl_8055FD4C;
extern unsigned char lbl_8055FD50;
extern unsigned char lbl_804C5700[12];
extern float lbl_80564F90;
void fn_802D3E88(void) {
    /* Disable the alpha-blend / indirect (bump) stage of the shared render request block. */
    unsigned char *alphaBlendFlag = &lbl_804C5700[0xD];
    *alphaBlendFlag = 0;
}

extern int lbl_804C5710_int;
/* Reset the GX framebuffer copy/fade state: set the fade mode (arg0), zero the
   frame counter, and clear both pending-copy flags in the state block. */
void fn_802D3E9C(unsigned char fadeMode) {
    unsigned char *state;
    state = lbl_804C5710;
    lbl_8055FD50 = fadeMode;
    lbl_8055FD4C = 0;
    state[1] = 0;
    state[0] = 0;
}

/* Returns 1 while the frame counter is non-negative (sign bit clear), 0 once
   it has been invalidated to -1 (sign bit set). */
int fn_802D3EBC(void) {
    return (lbl_8055D0B8 >> 0x1FU) ^ 1;
}

extern unsigned short lbl_8055FD86;
/* Store the requested 16-bit GX blend mode (high byte = src factor, low byte = dst factor).
   The pipeline rebuild (fn_802D3144) compares this with the applied copy lbl_8055FD88. */
void fn_802D3ECC(unsigned short blendMode) {
    lbl_8055FD86 = blendMode;
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
extern float lbl_80564F90;
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

  void fn_802D2D1C(void) {
      float *src = (float *)lbl_804C56C0;
      float *dst = (float *)lbl_804CA2D8;
      dst[0] = src[0];
      dst[1] = src[1];
      dst[2] = src[2];
      dst[3] = src[3];
      dst[4] = src[4];
      dst[5] = src[5];
      dst[6] = src[6];
      dst[7] = src[7];
      dst[8] = src[8];
      dst[9] = src[9];
      dst[10] = src[10];
      dst[11] = src[11];
      GXSetCurrentMtx(0);
  }
