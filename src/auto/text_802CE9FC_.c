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

void fn_802CF104(void) {
    fn_802CF048(1);
}

void fn_802CF5D0(void) {}

void fn_802CF5F8(void) {}

void fn_802CFEEC(void* alarm) {
    fn_802CFDE0(fn_802CFCA0(alarm));
}

extern void *lbl_8055FD20;
void fn_802CFF50(void) {
    lbl_8055FD20 = (void*)-1;
}

extern void *lbl_8055FD1C;
void fn_802CFF5C(void* hi) {
    lbl_8055FD1C = hi;
}

void fn_802CFFA4(unsigned short arg0) {
    lbl_8055FD86 = arg0;
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
extern unsigned char lbl_8055FDA0[];
extern unsigned char lbl_804C97B0[];
extern unsigned long fn_802CE9FC(unsigned long);
extern void fn_802CFF64(void);
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
