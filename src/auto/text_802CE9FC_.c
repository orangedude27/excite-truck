extern unsigned char lbl_8055FD91;
extern unsigned char lbl_8055D0FF;
extern char lbl_8055D100;
  extern void fn_802CEC04(void);
  extern void fn_802E2E0C(void (*)(void), void *);
  extern void fn_802D6C68(void);
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
  extern float lbl_80558DC4;
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

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FD3C;
void fn_802CEC44(void) {
    lbl_8055FD3C = 1;
}

void fn_802CECF4(unsigned int arg0) {
    extern unsigned short lbl_8055D0F6;
    extern int fn_802CEC50(unsigned short);
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

void fn_802CF048(int arg0) {
    if (arg0 != 0) {
        GXSetGPMetric(0x23, 0x16);
        *(volatile unsigned char *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = 0x2402C004;
        *(volatile unsigned char *)0xCC008000 = 0x61;
        *(volatile unsigned int *)0xCC008000 = 0x23000020;
        *(volatile unsigned char *)0xCC008000 = 0x10;
        *(volatile unsigned short *)0xCC008000 = 0;
        *(volatile unsigned short *)0xCC008000 = 0x1006;
        *(volatile unsigned int *)0xCC008000 = 0x84400;
        return;
    }
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = 0x24000000;
    *(volatile unsigned char *)0xCC008000 = 0x61;
    *(volatile unsigned int *)0xCC008000 = 0x23000000;
    *(volatile unsigned char *)0xCC008000 = 0x10;
    *(volatile unsigned short *)0xCC008000 = 0;
    *(volatile unsigned short *)0xCC008000 = 0x1006;
    *(volatile unsigned int *)0xCC008000 = 0;
}

void fn_802CF104(void) {
    fn_802CF048(1);
}

void fn_802CF5A8(void) {
    if (lbl_8055D0FF == 0) return;
    lbl_8055D0FF = 0;
    fn_802E2E0C(fn_802CEC04, &lbl_8055D100);
}

void fn_802CF5D0(void) {}

void fn_802CF5D4(void) {
    lbl_8055FD24 = 0;
    lbl_8055FD91 = 0;
    GXSetAlphaCompare(4, 0, 1, 0, 0);
}

void fn_802CF5F8(void) {}

void fn_802CF5FC(void) {
}

void fn_802CF830(void) {
}

int fn_802CFCA0(void* alarm) {
    int sp10;
    int spC;
    int sp8;

    fn_802D6C68();
    lbl_8055FE39 = 1;
    lbl_8055FDA4 = lbl_8055FD94;
    lbl_8055FD9C = 0;
    lbl_804C5700[0] = 1;
    lbl_8055FD8C = -1;
    fn_802DA52C();
    GXSetDrawSync();
    GXGetVtxDesc();
    GXGetCPUFifo(&sp10);
    GXGetFifoPtrs(&sp10, &spC, &sp8);
    GXEnableBreakPt(sp8);
    GXGetVtxDesc();
    GXInvalidateVtxCache();
    GXMiscInit(1);
    lbl_8055FD30 += 1;
    if (lbl_804C97B0[0] == 0) {
        if (__fabsf(((float *)lbl_804C97B0)[4]) != lbl_80558DC4) {
            lbl_804C97B0[0] = 1;
            lbl_804C97B0[0x1C] = 1;
        }
    }
    return 0;
}

extern int GXGetFifoBase(void *);
extern int GXGetFifoSize(void *);
extern void GXGetVtxAttrFmtv(void);
extern int GXInit(int, int);
extern int VIConfigure(void *);
extern void fn_802CF850(void);
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

extern int fn_802CFCA0(void*);
void fn_802CFEEC(void* alarm) {
    fn_802CFDE0(fn_802CFCA0(alarm));
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
void fn_802CFF50(void) {
    lbl_8055FD20 = (void*)-1;
}

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

void fn_802CFFA4(unsigned short arg0) {
    lbl_8055FD86 = arg0;
}

void fn_802D0014(float a, float b, float c) {
    extern unsigned char lbl_804C97B0[];
    extern float lbl_80558DC4;
    float d = c < 0.0f ? -c : c;
    ((float *)lbl_804C97B0)[2] = b;
    if (d > lbl_80558DC4) {
        lbl_804C97B0[0] = 1;
        ((float *)lbl_804C97B0)[3] = a + ((b - a) / c);
    } else {
        ((float *)lbl_804C97B0)[3] = b;
        lbl_804C97B0[0] = 0;
    }
    ((float *)lbl_804C97B0)[4] = c;
    lbl_804C97B0[0x1C] = 1;
}

void fn_802D0160(unsigned char a, unsigned char b, unsigned char c) {
    extern char lbl_804C97D0;
    unsigned char *p = (unsigned char *)&lbl_804C97D0;
    p[4] = a; p[5] = b; p[6] = c; p[7] = 0xFF; p[0x5C] = 1;
}

void fn_802D0188(unsigned char a, unsigned char b, unsigned char c) {
    extern char lbl_804C97D0;
    unsigned char *p = (unsigned char *)&lbl_804C97D0;
    p[0] = a; p[1] = b; p[2] = c; p[3] = 0; p[0x5C] = 1;
}

void fn_802D01B0(float *p, float v) {
    extern char lbl_804C97D0;
    float *out = (float *)((unsigned char *)&lbl_804C97D0 + 0xC);
    out[0] = p[0]; out[1] = p[1]; out[2] = p[2]; out[3] = v;
    *((unsigned char *)&lbl_804C97D0 + 0x5C) = 1;
}

void fn_802D02F8(signed char arg1) {
    extern unsigned char lbl_804C9778[];
    extern unsigned char fn_802CEA1C(void);
    unsigned int value;
    unsigned char high, mid;
    lbl_804C9778[0x2d] = arg1;
    lbl_804C9778[0x2c] = 1;
    value = fn_802CEA1C();
    lbl_804C9778[0x31] = value;
    high = (unsigned char)(value >> 24);
    lbl_804C9778[0x2e] = high;
    mid = (unsigned char)(value >> 16);
    lbl_804C9778[0x2f] = mid;
    high = (unsigned char)(value >> 8);
    lbl_804C9778[0x30] = high;
    *(unsigned char *)((unsigned char *)&value + 3) = (unsigned char)value;
    *(unsigned char *)((unsigned char *)&value + 2) = high;
}

void fn_802D0368(float arg0, float arg1, float arg2, float arg3) {
    extern float lbl_80564F94;
    extern unsigned char lbl_804C9778[];
    extern unsigned char lbl_804C97B0[];
    extern double fn_8002EF30(void *, float);
    float result;
    *(float *)(lbl_804C9778 + 4) = arg0;
    lbl_804C9778[0] = 1;
    *(float *)(lbl_804C9778 + 8) = arg1;
    *(float *)(lbl_804C9778 + 0xc) = arg2;
    *(float *)(lbl_804C9778 + 0x14) = arg3;
    result = (float)fn_8002EF30(lbl_804C9778, arg2 * lbl_80564F94);
    *(float *)(lbl_804C97B0 + 0x14) = arg0;
    *(float *)(lbl_804C9778 + 0x10) = result;
    *(float *)(lbl_804C97B0 + 0x18) = arg1;
    lbl_804C97B0[0x1c] = 1;
}

extern void *lbl_8055FD54;
extern void* fn_802D30F0(void);
extern void fn_802D307C(void);
void fn_802D050C(void* hi) {
    lbl_8055FD54 = hi;
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

void fn_802D0910(void) {
}

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
    unsigned char *p;
    unsigned short x;
    p = (unsigned char *)lbl_8055FD64;
    if (p[0x18]) {
        VIGetNextField();
        x = *(unsigned short *)(p + 4);
        GXSetViewportJitter(x, lbl_80564F88, lbl_80564F88, (float)x, (float)*(unsigned short *)(p + 6), lbl_80564F88, lbl_80564F8C);
    } else {
        x = *(unsigned short *)(p + 4);
        GXSetViewport(x, lbl_80564F88, lbl_80564F88, (float)x, (float)*(unsigned short *)(p + 6), lbl_80564F88, lbl_80564F8C);
    }
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
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

void fn_802D1B58(void) {
    float m[8];
    float f = lbl_80564F94;
    float *t = (float *)lbl_804C5690;
    float a = -t[1];
    float b = -t[4];
    float c = -t[7];
    int *p = (int *)lbl_802FAC70;

    *(int *)&m[0] = p[0];
    *(int *)&m[1] = p[1];
    *(int *)&m[2] = p[2];
    *(int *)&m[3] = p[3];
    *(int *)&m[4] = p[4];
    *(int *)&m[5] = p[5];
    *(int *)&m[6] = p[6];
    *(int *)&m[7] = p[7];
    m[0] = f * a;
    m[1] = f * b;
    m[2] = f * c;
    GXLoadTexMtxImm(m, 0x21, 1);
}

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

void fn_802D2AC4(void) {
    GXSetNumChans(1);
    GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
    fn_802DFAF4();
}

extern char lbl_804C97D0;
void* fn_802D2D04(void) {
    return &lbl_804C97D0 + 0xC;
}

extern void *lbl_8055FD64;
void* fn_802D2D14(void) {
    return lbl_8055FD64;
}

void fn_802D2F70(int arg0) {
    fn_802D2ED8(arg0, 0);
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
void* fn_802D3104(void) {
    struct { char pad[0x24]; char m; } *p;
    fn_802D307C();
    p = lbl_8055FD5C;
    return &p->m;
}

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

extern unsigned char lbl_8055FD84;
extern void fn_802CF5D4(void);
extern void fn_802D2640(void);
extern void fn_802D92B0(void);
extern void GXSetTexCoordGen2(int, int, int, int, int, int);
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
    int i;
    unsigned char *p;
    p = lbl_804C9984;
    for (i = 0; i < 4; i++) {
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
    }
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
    unsigned char *slot;
    unsigned char *base;
    int count;
    void *light;
    unsigned long result;
    base = lbl_804C9984;
    slot = base;
    count = 0;
    do {
        light = *(void **)(slot + 0x600);
        GXInitLightDir(*(unsigned long *)light, *(unsigned long *)((char *)light + 4), &result);
        *(unsigned char *)((char *)light + 0xD) =
            ((result ^ *(unsigned long *)((char *)light + 8)) != 0);
        slot += 4;
        count++;
    } while (count < *(int *)(base + 0x700));
    *(int *)(base + 0x700) = 0;
}

extern char lbl_8034C1E4[];
extern float lbl_80564F88;
void *fn_802D39A4(float value) {
    unsigned char *p;
    int i;
    unsigned char *found;
    p = lbl_804C9984;
    i = 0;
    found = 0;
    do {
        if (p[0xC] == 0) {
            found = lbl_804C9984 + i * 0x18;
            break;
        }
        p += 0x18;
        i++;
    } while (i < 0x40);
    if (found == 0) fn_802E317C(lbl_8034C1E4);
    found[0xC] = 1;
    found[0xD] = 0;
    *(float *)(found + 0x10) = value;
    *(float *)(found + 0x14) = lbl_80564F88;
    return found;
}

void fn_802D3A50(void *arg0) { ((unsigned char *)arg0)[0xC] = 0; }

void fn_802D3BB0(void) {}

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

void fn_802D3DAC(void) {
    if ((lbl_8055FDD0 & 0x3F) == 0) {
        OSReport(lbl_8034C204);
    }
    GXInitVtxDescList(lbl_8055FDD0++);
    GXDisableBreakPt();
}

void fn_802D3DF8(int arg0, signed char arg1, float farg0, float farg1) {
    float mtx[2][3];

    lbl_804C5700[13] = 1;
    GXLoadTexObj((char *)arg0 + 0x24, 2, lbl_804C5700);
    *(int *)&mtx[0][1] = 0;
    *(int *)&mtx[1][1] = 0;
    *(int *)&mtx[0][2] = 0;
    *(int *)&mtx[1][2] = 0;
    mtx[0][0] = farg0;
    mtx[1][0] = farg1;
    GXSetIndTexMtx(1, mtx, arg1);
}

extern unsigned long lbl_8055D0B8;
extern unsigned char lbl_804C5710[4];
extern int lbl_8055FD4C;
extern unsigned char lbl_8055FD50;
extern unsigned char lbl_804C5700[12];
void fn_802D3E88(void) {
    unsigned char *p = &lbl_804C5700[0xD];
    *p = 0;
}

extern int lbl_804C5710_int;
void fn_802D3E9C(unsigned char arg0) {
    lbl_8055FD50 = arg0;
    lbl_8055FD4C = 0;
    ((unsigned char *)&lbl_804C5710_int)[1] = 0;
    ((unsigned char *)&lbl_804C5710_int)[0] = 0;
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
extern unsigned long fn_802CE9FC(unsigned long);
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
extern void fn_802CEC04(void);
extern void fn_802E2E0C(void (*)(void), void *);
extern int lbl_804C9760[];
