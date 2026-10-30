#include "revolution/GX/GXHardware.h"
extern void *lbl_8055FEB4;
extern unsigned char lbl_8055FEB0, lbl_8055FEB9, lbl_8055FEBB, lbl_8055FD24;
extern unsigned char lbl_804DB480[];
extern void fn_802D0610(int);
extern void fn_802D68C4(int, int, int, int);
extern void GXSetZMode(int, int, int);
extern void GXSetNumChans(int);
extern void GXSetChanCtrl(int, int, int, int, int, int, int);
extern unsigned char lbl_8055FEB8;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct { unsigned char r, g, b, a; } fn_802DCAE4_GXColor;
extern void GXSetTevKColor(int, fn_802DCAE4_GXColor);

extern unsigned char lbl_8055FEC0;
extern int lbl_8055FD30;
extern void fn_802D3360(void);
extern void GXSetTevKAlphaSel(int, int);
extern void GXSetBlendMode(int, int, int, int);
extern unsigned char lbl_8055FEBA, lbl_8055FEB8;
extern signed char lbl_8055FE9E;
extern int lbl_8055FEA0, lbl_8055FEA4;
#pragma push
#pragma small_data off
extern void *lbl_804DB468[];
#pragma pop
extern void *fn_802D94DC(void);
extern void *lbl_8055FEA8;
extern void *lbl_8055FEAC;
extern void GXLoadTexMtxImm(float *, unsigned int, unsigned char);
extern float lbl_8055D148;
extern unsigned char lbl_804DB068[];
extern unsigned char lbl_802FACF8[];
extern unsigned char lbl_802FACD8[];
extern unsigned char lbl_8055FEB0, lbl_8055FD24;
#pragma scheduling invalid_target
void fn_802DB2D4(void) {
    lbl_8055FEB0 = 0;
    lbl_8055FD24 = ((unsigned char *)lbl_804DB468[0])[0xE4];
    GXSetAlphaCompare(4, ((unsigned char *)lbl_804DB468[0])[0xE4], 1, 0, 0);
}

void fn_802DB304(void *arg0, int arg1) {
    void **dst = (void **)arg0;

    switch (arg1) {
    case 0:
        dst[0] = lbl_804DB468[0];
        return;
    case 2:
        dst[0] = lbl_804DB468[0];
        dst[1] = lbl_804DB468[1];
        return;
    case 1:
        dst[0] = lbl_804DB468[0];
        dst[1] = lbl_804DB468[1];
        dst[2] = lbl_804DB468[2];
        return;
    }
}

#pragma scheduling on
int fn_802DB378(int arg0, int arg1) { int result = 0xFF; if (arg0 == 2) { if (arg1 == 0) result = 4; } return result; }

void fn_802DB394(void) { volatile int mode = 3; GXSetTevOp(0, mode); GXSetTevOp(1, 3); GXSetTevAlphaOp(1, 0, 0, 0, 1, 0); GXSetTevAlphaIn(1, 0, 7, 7, 7); }

#pragma push
#pragma processor 750
void fn_802DB3FC(void) {
    GXSetTevOp(0, 3);
    GXSetTevOp(1, 4);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 4, 7, 7, 7);
    GXSetTevOp(2, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 0, 7, 7, 7);
    GXSetTevOp(3, 4);
    GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(3, 7, 0, 4, 7);
}
#pragma scheduling invalid_target
void fn_802DB4E4(void) {
    volatile int m[16];
    register float *q = (float *)lbl_804DB068;
    m[8] = 0;
    m[14] = 0;
    m[0] = 0;
    m[6] = 0;
    m[9] = 0;
    m[10] = 0;
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    m[15] = 0;
    *(volatile float *)&m[8] = q[3];
    *(volatile float *)&m[14] = q[4];
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 0;
    m[7] = 0;
    *(volatile float *)&m[0] = q[6];
    *(volatile float *)&m[6] = q[7];
    GXLoadTexMtxImm((float *)&m[8], 0x1e, 1);
    GXLoadTexMtxImm((float *)m, 0x21, 1);
}
#pragma scheduling on
void fn_802DB58C(void) {
    int m[8];
    int *p = (int *)lbl_802FACD8;
    float *q = (float *)lbl_804DB068;
    m[0] = p[0]; m[1] = p[1]; m[2] = p[2]; m[3] = p[3];
    m[4] = p[4]; m[5] = p[5]; m[6] = p[6]; m[7] = p[7];
    *(float *)&m[0] = q[3];
    *(float *)&m[6] = q[3];
    GXLoadTexMtxImm((float *)m, 0x1e, 1);
}
#pragma scheduling on
void fn_802DB620(void) {
    int m[8];
    int *p = (int *)lbl_802FACF8;
    m[0] = p[0]; m[1] = p[1]; m[2] = p[2]; m[3] = p[3];
    m[4] = p[4]; m[5] = p[5]; m[6] = p[6]; m[7] = p[7];
    *(float *)&m[0] = lbl_8055D148;
    *(float *)&m[6] = lbl_8055D148;
    GXLoadTexMtxImm((float *)m, 0x1e, 1);
}

#pragma dont_inline on
#pragma use_lmw_stmw off
int fn_802DB69C(void **arg0, int arg1) {
    extern int lbl_8055FEA4;
    extern void GXLoadTexObj(void *, int);
    extern void GXSetTevOrder(int, int, int, int);
    extern void GXSetNumTexGens(unsigned char);
    void **p = arg0;
    int stage = 0;
    int tex = 0;
    unsigned char *obj;
    int i = 0;
    while (i < lbl_8055FEA4) {
        int base;
        unsigned char *texture;
        obj = *p;
        base = tex;
        texture = obj + 0x24;
        tex = base + 1;
        GXLoadTexObj(texture, base);
        if (obj[0xCC]) {
            int extra = tex++;
            GXLoadTexObj(obj + 0x78, extra);
            GXSetTevOrder(stage++, i, extra, 0xFF);
        }
        {
            int current = stage++;
            GXSetTevOrder(current, i, base, fn_802DB378(arg1, i));
        }
        p++;
        i++;
    }
    GXSetNumTexGens((unsigned char)lbl_8055FEA4);
    return stage;
}

void fn_802DB9DC(int arg0) {
    if (lbl_8055FEBA != 0)
        return;
    if (arg0 != 0) {
        GXSetBlendMode(1, 4, 0, 5);
    } else {
        GXSetBlendMode(1, 4, 1, 5);
    }
}

#pragma dont_inline reset
#pragma use_lmw_stmw on

void fn_802DBBE4(int arg0, int arg1) {
    if ((void *)lbl_8055FEA8 != (void *)arg0) {
        lbl_8055FEA8 = (void *)arg0;
        lbl_8055FEAC = (void *)arg1;
        GXClearVtxDesc();
        GXSetVtxDesc(9, 3);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetArray(9, (void *)arg0, 0xC);
        DCFlushRange((void *)arg0, arg1 * 0xC);
    }
}

extern void fn_802DBC70(int,int);
void fn_802DBC70(int arg0, int arg1) {
    if ((void *)lbl_8055FEA8 != (void *)arg0) {
        lbl_8055FEA8 = (void *)arg0;
        lbl_8055FEAC = (void *)arg1;
        GXClearVtxDesc();
        GXSetVtxDesc(9, 3);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetArray(9, (void *)arg0, 0xC);
        DCFlushRange((void *)arg0, arg1 * 0xC);
    }
}

extern void fn_802DBCFC(int,int);
void fn_802DBCFC(int arg0, int arg1) {
    if ((void *)lbl_8055FEA8 != (void *)arg0) {
        lbl_8055FEA8 = (void *)arg0;
        lbl_8055FEAC = (void *)arg1;
        GXClearVtxDesc();
        GXSetVtxDesc(9, 3);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetArray(9, (void *)arg0, 0xC);
        DCFlushRange((void *)arg0, arg1 * 0xC);
    }
}

#pragma push
#pragma small_data off
void fn_802DBD88(void) {
    void *value;
    void **slot;
    lbl_8055FEA8 = 0;
    lbl_8055FEAC = 0;
    lbl_8055FE9E = 1;
    lbl_8055FEA0 = -1;
    value = fn_802D94DC();
    lbl_8055FEA4 = 1;
    slot = (void **)&lbl_804DB468;
    *slot = value;
}
#pragma pop
void fn_802DBDD8(void) {
    lbl_8055FEA8 = 0;
    lbl_8055FEAC = 0;
}

#pragma scheduling off
void fn_802DBDE8(int arg0, void *arg1) {
    int count;
    void **entry;

    if (arg1 != 0) {
        int oldCount = *(int *)((char *)arg1 + 0xF0);
        int value = lbl_8055FD30;
        *(int *)((char *)arg1 + 0xEC) = value;
        *(int *)((char *)arg1 + 0xF0) = oldCount + 1;
        entry = lbl_804DB468;
        entry[arg0] = arg1;
        count = 0;
        lbl_8055FEA4 = count;
        goto loop_body;
    }

    entry = lbl_804DB468;
    count = 0;
    goto loop_check;

loop_body:
    count++;
    lbl_8055FEA4 = count;
    entry++;

loop_check:
    if (count < 3 && entry[0] != 0)
        goto loop_body;
    lbl_8055FE9E = 1;
}
#pragma scheduling on
void fn_802DBECC(void) {
    fn_802D3360();
    GXSetTevKAlphaSel(0, 0);
    lbl_8055FEB8 = 0;
}

#pragma dont_inline on
void fn_802DBF00(signed char arg0) {
    fn_802DBD88();
    lbl_8055FEBA = arg0;
}
#pragma dont_inline reset
typedef unsigned char u8;
extern void fn_802DBDD8(void);
extern void fn_802DEE1C(void);
extern void fn_802DBD88(void);
extern void fn_802D3360(void);
extern void GXSetTevKAlphaSel(int, int);
extern void fn_802D0610(int);
extern void fn_802D68C4(int, int, int, int);
extern void GXSetZMode(int, int, int);
extern void GXSetNumChans(int);
extern void GXSetChanCtrl(int, int, int, int, int, int, int);
extern u8 lbl_8055FEBA;
extern u8 lbl_8055FEB8;
extern int lbl_8055FD30, lbl_8055FEA4;
extern signed char lbl_8055FE9E;
extern int lbl_8055FEA0;
extern void *lbl_8055FEA8, *lbl_8055FEAC;
extern void *fn_802D94DC(void);
extern void fn_802DBA1C(unsigned char);
extern void fn_802DB9DC(int);
extern void fn_802DBBE4(int,int);
extern void fn_802DBF54(int,int);
extern void GXSetColorUpdate(int);
extern void GXSetZMode(int,int,int);
extern unsigned char lbl_8055FEBA;
#pragma dont_inline on
void fn_802DBF30(void) {
    fn_802DBDD8();
    fn_802DEE1C();
}

extern void GXBegin(int, int, unsigned short);
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802DBF54(int verts, int count) {
    int n;
    int i;
    volatile unsigned short *fifo = (volatile unsigned short *)0xCC008000;
    while (count > 0) {
        n = *(unsigned short *)verts;
        verts += 2;
        GXBegin(0xA0, 0, n);
        count -= n + 1;
        #pragma unroll 8
        for (i = 0; i < n; i++, verts += 2) {
            *fifo = *(unsigned short *)verts;
        }
    }
}
#pragma push
#pragma use_lmw_stmw off
void fn_802DC078(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    fn_802DBA1C(lbl_8055FEBA);
    fn_802DB9DC(arg4);
    fn_802DBBE4(arg0, arg1);
    fn_802DBF54(arg2, arg3);
    if (lbl_8055FEBA != 0) {
        GXSetZMode(1, 3, 1);
        GXSetAlphaCompare(7, 0, 1, 7, 0);
        GXSetColorUpdate(0);
        fn_802DBF54(arg2, arg3);
        GXSetColorUpdate(1);
    }
}
#pragma pop
extern void GXSetBlendMode(int, int, int, int);
void fn_802DC130(void) {
    fn_802DBD88();
}

void fn_802DC134(void) {
    fn_802DBDD8();
}

void fn_802DC138(int verts, int count, unsigned short *list, int size) {
    int n;
    int i;
    unsigned short val;
    volatile unsigned short *fifo = (volatile unsigned short *)0xCC008000;
    fn_802DB778(0);
    fn_802DBCFC(verts, count);
    while (size > 0) {
        n = *list;
        list++;
        GXBegin(0xA0, 0, n);
        size -= n + 1;
        for (i = 0; i < n; i++) {
            val = *list;
            list++;
            *fifo = val;
        }
    }
}

void fn_802DC278(void) { fn_802DBD88(); }

void fn_802DC27C(void) { fn_802DBDD8(); }

#pragma push
#pragma use_lmw_stmw off
void fn_802DC280(int verts, int count, unsigned short *list, int size) {
    int n;
    int i;
    unsigned short val;
    volatile unsigned short *fifo = (volatile unsigned short *)0xCC008000;
    fn_802DB778(1);
    fn_802DBC70(verts, count);
    while (size > 0) {
        n = *list++;
        GXBegin(0xA0, 0, n);
        size -= n + 1;
        #pragma unroll 8
        for (i = 0; i < n; i++) {
            val = *list;
            list++;
            *fifo = val;
        }
    }
}
#pragma pop

extern void fn_802DFCC0(void);
extern int GXGetTexObjMipMap(void *);
extern unsigned short GXGetTexObjWrapS(void *);
extern int GXGetTexObjFmt(void *);
extern void fn_802E317C(const char *);
extern char lbl_8034CB00[];
extern char lbl_8034CB24[];
extern unsigned int lbl_8055FEBC;
  
void fn_802DC440(void) { ((void (*)(void))fn_802DBDD8)(); fn_802DFCC0(); }

void fn_802DC628(void) {}

#pragma push
#pragma small_data off
void fn_802DC62C(void) {
    volatile unsigned char *p = (volatile unsigned char *)*(void **)&lbl_804DB468;
    if (GXGetTexObjMipMap((void *)(p + 0x24)) != 6)
        fn_802E317C(lbl_8034CB00);
    if (GXGetTexObjWrapS((void *)(p + 0x24)) != 0x200)
        fn_802E317C(lbl_8034CB24);
    lbl_8055FEBC = GXGetTexObjFmt((void *)(p + 0x24)) + 0x80000000;
}
#pragma pop
extern int GXGetTexObjMipMap(void *);
extern unsigned short GXGetTexObjWrapS(void *);
extern int GXGetTexObjFmt(void *);
extern void fn_802E317C(const char *);
extern char lbl_8034CB00[];
extern char lbl_8034CB24[];
extern unsigned int lbl_8055FEBC;
extern unsigned int lbl_8055FEBC;
int fn_802DC6AC(int a, unsigned int b) {
    int row = a / 4;
    int col = (int)b / 4;
    int x = a % 4;
    int y = (int)b % 4;
    int index = ((x + (y << 2)) << 4) / 8;
    char *tile = (char *)lbl_8055FEBC + (row + (col << 7)) * 64;
    tile += index;
    return *(unsigned short *)(tile + 32) |
           ((unsigned int)*(unsigned short *)tile << 16);
}

extern void GXLoadPosMtxImm(float (*)[4], unsigned int);
extern void GXCallDisplayList(void *, unsigned int);
extern void PSMTXScale(float (*)[4], float, float, float);
extern int fn_802CFF64();
extern void fn_802D0E48(int);
extern void fn_802D2ED8(int, int);
extern void fn_802D2F70(int);
extern void fn_802D3D94(void *, int);
extern void fn_802D6B54(void *);
extern void fn_802D6B78(void *);
extern void fn_802D6B7C(void *);
extern unsigned char lbl_8055FEB0, lbl_8055FEB9, lbl_8055FEBB;
extern void *lbl_8055FEB4;
extern float lbl_80565040, lbl_80565044, lbl_80565048, lbl_8056504C;
#pragma push
#pragma small_data off
extern unsigned char lbl_804DB480[];
#pragma push
#pragma processor 750
void fn_802DCAE4(void *arg0, void *arg1, float farg0) {
     void *input;
     void *state;
     float alpha;
     unsigned char *g;
     input = arg1;
     state = arg0;
     alpha = farg0;
     if (lbl_8055FEBB != 0) {
         unsigned int first;
         unsigned int *records;
         int count;
         unsigned int *dest;
         g = lbl_804DB480;
         first = *(unsigned int *)input;
         records = (unsigned int *)*(void **)g;
         count = *(int *)(g + 4);
         dest = records + count * 13;
         *(void **)(g + 0x214) = state;
         *(int *)(g + 4) = count + 1;
         dest[0] = first;
         dest[1] = *(unsigned int *)((unsigned char *)input + 0x04);
         dest[2] = *(unsigned int *)((unsigned char *)input + 0x08);
         dest[3] = *(unsigned int *)((unsigned char *)input + 0x0C);
         dest[4] = *(unsigned int *)((unsigned char *)input + 0x10);
         dest[5] = *(unsigned int *)((unsigned char *)input + 0x14);
         dest[6] = *(unsigned int *)((unsigned char *)input + 0x18);
         dest[7] = *(unsigned int *)((unsigned char *)input + 0x1C);
         dest[8] = *(unsigned int *)((unsigned char *)input + 0x20);
         dest[9] = *(unsigned int *)((unsigned char *)input + 0x24);
         dest[10] = *(unsigned int *)((unsigned char *)input + 0x28);
         dest[11] = *(unsigned int *)((unsigned char *)input + 0x2C);
         *(float *)&dest[12] = alpha;
         if (*(int *)(g + 4) + 1 > *(int *)(g + 8)) {
             unsigned char *colors = (unsigned char *)fn_802CFF64(0x28);
             unsigned char *coords = (unsigned char *)fn_802CFF64(0x50);
             if (colors != 0 && coords != 0) {
                 void *data;
                 int n = *(int *)(g + 4);
                 int i = 0;
                 int byteOffset = 0;
                 unsigned char *colorOut = colors;
                 unsigned char *coordOut = coords;
                 float temp_f29;
                 float temp_f30;
                 float temp_f31;
                 if (*(unsigned char *)(g + 0x218) != 0)
                     fn_802D6B54(*(void **)(g + 0x214));
                 data = ((void *(*)(void *))fn_802DC628)(*(void **)(g + 0x214));
                 temp_f31 = lbl_80565040;
                 temp_f30 = lbl_8056504C;
                 temp_f29 = lbl_80565044;
                 while (i < n) {
                     unsigned char *r = *(unsigned char **)g + byteOffset;
                     int v = (int)(temp_f31 * *(float *)(r + 0x30));
                     int c;
                     v = (unsigned char)v;
                     v = v & ((-v & ~v) >> 31);
                     c = 0xFF;
                     if (v < 0xFF) c = v;
                     *(unsigned int *)colorOut = 0xFFFFFF00U | (unsigned char)c;
                     *(float *)coordOut = temp_f29 + *(float *)(r + 0x24) / temp_f30;
                     *(float *)(coordOut + 4) = temp_f29 + *(float *)(r + 0x2C) / temp_f30;
                     fn_802D2ED8((int)r, i);
                     byteOffset += 0x34;
                     colorOut += 4;
                     coordOut += 8;
                     i++;
                 }
                 if (i < 10) {
                     float matrix[3][4];
                     PSMTXScale(matrix, lbl_80565048, lbl_80565048, lbl_80565048);
                     byteOffset = i * 3;
                     while (i < 10) {
                         GXLoadPosMtxImm(matrix, byteOffset);
                         byteOffset += 3;
                         i++;
                     }
                 }
                 if (*(unsigned char *)(g + 0x218) != 0) {
                     GXSetArray(9, *(void **)((unsigned char *)data + 0x20), 0xC);
                     GXSetArray(0xD, *(void **)((unsigned char *)data + 0x28), 4);
                 }
                 GXSetArray(0xB, colors, 4);
                 GXSetArray(0xE, coords, 8);
                 GXCallDisplayList(*(void **)((unsigned char *)data + 0x30), *(unsigned int *)((unsigned char *)data + 0x2C));
                 *(unsigned char *)(g + 0x218) = 0;
             }
             *(int *)(g + 4) = 0;
             *(void **)(g + 0x214) = 0;
         }
     } else {
         if (lbl_8055FEB9 != 0) {
             fn_802DCAE4_GXColor col;
             float t = lbl_80565040 * alpha;
             float rounded;
             int a; unsigned int pixel;
             if (t < lbl_80565048)
                 rounded = t - lbl_80565044;
             else
                 rounded = lbl_80565044 + t;
             a = (int)rounded;
             a = a & ((-a & ~a) >> 31);
             if (a >= 0xFF) a = 0xFF;
             pixel = fn_802DC6AC(((int)*(float *)((unsigned char *)input + 0x24) / 4) + 0x100,
                                 ((int)*(float *)((unsigned char *)input + 0x2C) / 4) + 0x100);
             col.r = (unsigned char)(pixel >> 16);
             col.g = (unsigned char)(pixel >> 8);
             col.b = (unsigned char)pixel;
             col.a = a;
             GXSetTevKColor(1, col);
         } else {
             float matrix[2][4];
             float x = *(float *)((unsigned char *)input + 0x24);
             float scale = lbl_8056504C;
             float y = *(float *)((unsigned char *)input + 0x2C);
             matrix[0][0] = lbl_80565048;
             matrix[0][1] = lbl_80565048;
             matrix[0][2] = lbl_80565048;
             matrix[1][0] = lbl_80565048;
             matrix[1][1] = lbl_80565048;
             matrix[1][2] = lbl_80565048;
             matrix[0][3] = lbl_80565044 + x / scale;
             matrix[1][3] = lbl_80565044 + y / scale;
             fn_802D3D94(0, (int)matrix);
             {
                 fn_802DCAE4_GXColor col;
                 float t = lbl_80565040 * alpha;
                 float rounded;
                 int a;
                 if (t < lbl_80565048)
                     rounded = t - lbl_80565044;
                 else
                     rounded = lbl_80565044 + t;
                 a = (int)rounded;
                 a = a & ((-a & ~a) >> 31);
                 if (a >= 0xFF) a = 0xFF;
                 if (a != lbl_8055FEA0) {
                     fn_802DCAE4_GXColor color;
                     color.r = 0xFF; color.g = 0xFF; color.b = 0xFF; color.a = a;
                     GXSetTevKColor(1, color);
                 }
             }
         }
         fn_802D2F70((int)input);
         if (lbl_8055FEB4 != state) {
             lbl_8055FEB4 = state;
             if (lbl_8055FEB0 != 0) {
                 fn_802D6B7C(state);
                 return;
             }
             fn_802D6B78(state);
             return;
         }
         if (lbl_8055FEB0 != 0) {
             fn_802D0E48(0);
             GXCallDisplayList(*(void **)((unsigned char *)state + 0x30), *(unsigned int *)((unsigned char *)state + 0x2C));
             fn_802D0E48(1);
             GXCallDisplayList(*(void **)((unsigned char *)state + 0x30), *(unsigned int *)((unsigned char *)state + 0x2C));
         } else {
             GXCallDisplayList(*(void **)((unsigned char *)state + 0x30), *(unsigned int *)((unsigned char *)state + 0x2C));
         }
     }
 }
#pragma pop
void fn_802DD228(void) { if (lbl_8055FEC0 != 0) { fn_802D3E88(); lbl_8055FEC0 = 0; } fn_802DBDD8(); fn_802CADD0(-1, 1); GXSetNumIndStages(0); GXSetTevDirect(0); }

void fn_802DD42C(void) { fn_802CFF64(); }

