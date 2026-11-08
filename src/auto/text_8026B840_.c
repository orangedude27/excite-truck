#include "types.h"

extern s32 fn_8026A344(s32);
extern void *fn_8017960C(s32);
extern void fn_801BFD34(void *, void *, void *);
extern void fn_8012F57C(f32 *, f32 *, f32 *, f32);
extern f32 fn_801E9DDC(f32 *, f32, f32);
extern f64 fn_8002F234(f64);
extern void fn_802E317C(const char *, ...);

extern char lbl_80346A50[];
extern s32 lbl_8055F4F0;
extern s32 lbl_8055F508;
extern f32 lbl_8055F50C;
extern f32 lbl_8055F510;
extern s32 lbl_8055F514;
extern f32 lbl_80563D94;
extern f32 lbl_80563D98;
extern f32 lbl_80563DA0;
extern f32 lbl_80563DB0;
extern f32 lbl_80563DE8;
extern f32 lbl_80563DEC;
extern f32 lbl_80563DF0;
extern f32 lbl_80563DF4;
extern f32 lbl_80563DF8;
extern f32 lbl_80563DFC;
extern f32 lbl_80563E00;
extern f32 lbl_80563E04;
extern f32 lbl_80563E08;
extern f32 lbl_80563E0C;

extern void *lbl_8055F4E0;
extern void *lbl_8055F4E4;
extern void *lbl_8055F4E8;
extern f32 lbl_80563D78;
extern f32 lbl_80563D7C;
extern f32 lbl_80563D80;
extern f32 lbl_80563D84;
extern f32 lbl_8055F47C;
extern u32 lbl_80499050[];
extern void fn_80015B20(void *, void *, void *);
extern f32 lbl_80563D88;
extern f32 lbl_80563D8C;
extern f32 lbl_80563D9C;
extern s32 fn_802E2C20(void);
extern s32 fn_802E4A1C();
extern s32 fn_801298E8(f32 *, s32);
extern void fn_80015A20();
extern f32 lbl_80563D90;
extern f32 lbl_80563DA4;
extern f32 lbl_80563DA8;
extern f32 lbl_80563DAC;
extern f32 lbl_80563DB4;
extern f32 lbl_80563DB8;
extern f32 lbl_80563DBC;
extern f32 lbl_80563DC0;
extern f32 lbl_80563DC4;
extern f32 lbl_80563DC8;
extern f32 lbl_80563DCC;
extern f32 lbl_8055F4F4;
extern f32 lbl_8055F4F8;
extern s32 lbl_8055F4FC;
extern s32 lbl_8055CFF0;
extern s32 lbl_8055CFF4;
extern f32 fn_801EA0E8(f32, f32);
extern void fn_80127A84(s32 *, s32 *, s32 *);

/* v * 3x3 matrix m (rows of 3 floats); out may alias v */
static inline void Mtx3MultVec(f32 *m, f32 *v, f32 *out) {
    f32 x = v[0], y = v[1], z = v[2];
    if (out == v) {
        out[0] = z * m[6] + (x * m[0] + y * m[3]);
        out[1] = z * m[7] + (x * m[1] + y * m[4]);
        out[2] = z * m[8] + (x * m[2] + y * m[5]);
    } else {
        out[0] = z * m[6] + (x * m[0] + y * m[3]);
        out[1] = z * m[7] + (x * m[1] + y * m[4]);
        out[2] = z * m[8] + (x * m[2] + y * m[5]);
    }
}

typedef struct Words12 { u32 w[12]; } Words12;
void fn_8026B840(void) {}

f32 fn_8026B844(f32 f) {
 f32 c = lbl_80563D78;
 if (f > c) {
  f32 t = (f - lbl_80563D7C) / lbl_80563D80;
  c = c > t ? c : t;
  return c;
 }
 {
  f32 t = (lbl_80563D7C + f) / lbl_80563D84;
  c = c < t ? c : t;
 }
 return c;
}

BOOL fn_8026BFF0(s32 x) {
    switch (x) { case 3: case 4: return TRUE; default: return FALSE; }
}

extern s32 fn_802D3EBC(void);
extern s32 __AXGetStackHead_80137CFC(s32);
extern s32 fn_801298E8(f32 *, s32);
extern u8 *__AXFXGetLfoSinTable_801297F4(void);
extern s32 lbl_8055F4EC;
extern u8 lbl_8055F500;
extern s32 fn_802E4A60(f32 *);
extern void fn_8026B8A0(void);
extern s32 fn_802E2C20(void);
extern u8 lbl_8055F501;
extern u8 lbl_8055F502;
extern s32 lbl_8055F504;
extern char lbl_8049A168[];
extern f32 lbl_80563D88;
extern f32 lbl_80563D8C;
extern f64 lbl_80563DD0;
extern s32 fn_802E4A1C();
extern f32 lbl_80563DD8;
extern f32 lbl_80563D9C;
extern f32 lbl_80563DDC;
extern f32 lbl_80563DE0;
extern f32 lbl_80563DE4;
extern u32 lbl_802FA768[4];
extern u32 lbl_802FA778[4];
extern void fn_80015A20();
extern void PSVECCrossProduct(f32 *, f32 *, f32 *);
extern void PSVECNormalize(f32 *, f32 *);
#pragma dont_inline on
void fn_8026C014(s32 arg0, void *arg1) {
    u8 localFrame[0x2F8];
    char *globalBase = lbl_8049A168;
    u8 temp_r5;
    u32 temp_r0_4;
    u32 temp_r0_3;
    s32 var_r7;
    s32 var_r4;
    s32 var_r3;
    s32 var_r28;
    s32 var_r0_2;
    s32 var_r0;
    s32 temp_r6;
    s32 temp_r5_3;
    s32 temp_r4_2;
    s32 temp_r3_7;
    s32 temp_r3_6;
    s32 temp_r3_10;
    s32 temp_r29;
    s32 temp_r27;
    s32 temp_r25;
    s32 temp_r24;
    s32 temp_r23;
    s32 temp_r0_2;
    s32 temp_r0;
    f32 var_f6;
    f32 var_f5;
    f32 var_f4_2;
    f32 var_f4;
    f32 var_f3_2;
    f32 var_f3;
    f32 var_f31;
    f32 var_f30;
    f32 var_f2_2;
    f32 var_f2;
    f32 var_f29;
    f32 var_f28;
    f32 var_f27;
    f32 var_f1_2;
    f32 var_f1;
    f32 var_f0;
    f32 temp_f9_3;
    f32 temp_f9_2;
    f32 temp_f9;
    f32 temp_f8_3;
    f32 temp_f8_2;
    f32 temp_f8;
    f32 temp_f7_8;
    f32 temp_f7_7;
    f32 temp_f7_6;
    f32 temp_f7_5;
    f32 temp_f7_4;
    f32 temp_f7_3;
    f32 temp_f7_2;
    f32 temp_f7;
    f32 temp_f6_7;
    f32 temp_f6_6;
    f32 temp_f6_5;
    f32 temp_f6_4;
    f32 temp_f6_3;
    f32 temp_f6_2;
    f32 temp_f6;
    f32 temp_f5_5;
    f32 temp_f5_4;
    f32 temp_f5_3;
    f32 temp_f5_2;
    f32 temp_f5;
    f32 temp_f4_5;
    f32 temp_f4_4;
    f32 temp_f4_3;
    f32 temp_f4_2;
    f32 temp_f4;
    f32 temp_f3_6;
    f32 temp_f3_5;
    f32 temp_f3_4;
    f32 temp_f3_3;
    f32 temp_f3_2;
    f32 temp_f3;
    f32 temp_f31_2;
    f32 temp_f31;
    f32 temp_f30_2;
    f32 temp_f30;
    f32 temp_f2_8;
    f32 temp_f2_7;
    f32 temp_f2_6;
    f32 temp_f2_5;
    f32 temp_f2_4;
    f32 temp_f2_3;
    f32 temp_f2_2;
    f32 temp_f2;
    f32 temp_f29;
    f32 temp_f28_4;
    f32 temp_f28_3;
    f32 temp_f28_2;
    f32 temp_f28;
    f32 temp_f1_9;
    f32 temp_f1_8;
    f32 temp_f1_7;
    f32 temp_f1_6;
    f32 temp_f1_5;
    f32 temp_f1_4;
    f32 temp_f1_3;
    f32 temp_f1_2;
    f32 temp_f1_12;
    f32 temp_f1_11;
    f32 temp_f1_10;
    f32 temp_f1;
    f32 temp_f11;
    f32 temp_f10;
    f32 temp_f0_9;
    f32 temp_f0_8;
    f32 temp_f0_7;
    f32 temp_f0_6;
    f32 temp_f0_5;
    f32 temp_f0_4;
    f32 temp_f0_3;
    f32 temp_f0_2;
    f32 temp_f0_15;
    f32 temp_f0_14;
    f32 temp_f0_13;
    f32 temp_f0_12;
    f32 temp_f0_11;
    f32 temp_f0_10;
    f32 temp_f0;
























































































































    f32 *temp_r28;
    f32 *temp_r3;
    f32 *temp_r3_2;
    f32 *temp_r3_3;
    f32 *temp_r3_4;
    f32 *temp_r3_5;
    f32 *temp_r4;
    f32 *temp_r5_2;
    void *temp_r22;
    void *temp_r26;
    void *temp_r28_2;
    void *temp_r28_3;
    void *temp_r3_8;
    void *temp_r3_9;






(void)arg1;
    if (fn_802D3EBC() == 0) {
        if (arg0 != 0) {
            var_r3 = __AXGetStackHead_80137CFC(0);
        } else {
            var_r3 = 0;
        }
        if (fn_801298E8(&(*(f32 *)(localFrame + (0x2a4 - 0x10))), var_r3) != 0) {
            temp_r0 = (*(s32 *)((u8 *)(__AXFXGetLfoSinTable_801297F4()) + (0x28)));
            if (temp_r0 >= 0) {
                temp_r5 = *((u8 *)(localFrame + 0x2b4) + temp_r0);
                if (((s32) temp_r5 != 0) && ((s32) lbl_8055F500 == 0)) {
                    lbl_8055F4EC = (lbl_8055F4EC + 1) % 3;
                }
                lbl_8055F500 = temp_r5;
            }
        }
        if (fn_802E4A60(&(*(f32 *)(localFrame + (0x240 - 0x10)))) != 0) {
            (*(f32 *)(localFrame + (0x2a4 - 0x10))) = (*(f32 *)(localFrame + (0x240 - 0x10)));
            (*(f32 *)(localFrame + (0x2a8 - 0x10))) = (*(f32 *)(localFrame + (0x244 - 0x10)));
            (*(f32 *)(localFrame + (0x2ac - 0x10))) = (*(f32 *)(localFrame + (0x248 - 0x10)));
            (*(f32 *)(localFrame + (0x2b0 - 0x10))) = (*(f32 *)(localFrame + (0x24c - 0x10)));
            (*(f32 *)(localFrame + (0x2b4 - 0x10))) = (*(f32 *)(localFrame + (0x250 - 0x10)));
            (*(f32 *)(localFrame + (0x2b8 - 0x10))) = (*(f32 *)(localFrame + (0x254 - 0x10)));
            (*(f32 *)(localFrame + (0x2bc - 0x10))) = (*(f32 *)(localFrame + (0x258 - 0x10)));
            (*(f32 *)(localFrame + (0x2c0 - 0x10))) = (*(f32 *)(localFrame + (0x25c - 0x10)));
            (*(s32 *)(localFrame + (0x2c4 - 0x10))) = (*(s32 *)(localFrame + (0x260 - 0x10)));
            (*(s32 *)(localFrame + (0x2c8 - 0x10))) = (*(s32 *)(localFrame + (0x264 - 0x10)));
            (*(s32 *)(localFrame + (0x2cc - 0x10))) = (*(s32 *)(localFrame + (0x268 - 0x10)));
            (*(s32 *)(localFrame + (0x2d0 - 0x10))) = (*(s32 *)(localFrame + (0x26c - 0x10)));
            (*(s32 *)(localFrame + (0x2d4 - 0x10))) = (*(s32 *)(localFrame + (0x270 - 0x10)));
            (*(s32 *)(localFrame + (0x2d8 - 0x10))) = (*(s32 *)(localFrame + (0x274 - 0x10)));
            (*(s32 *)(localFrame + (0x2dc - 0x10))) = (*(s32 *)(localFrame + (0x278 - 0x10)));
            (*(s32 *)(localFrame + (0x2e0 - 0x10))) = (*(s32 *)(localFrame + (0x27c - 0x10)));
            (*(s32 *)(localFrame + (0x2e4 - 0x10))) = (*(s32 *)(localFrame + (0x280 - 0x10)));
            (*(s32 *)(localFrame + (0x2e8 - 0x10))) = (*(s32 *)(localFrame + (0x284 - 0x10)));
            (*(s32 *)(localFrame + (0x2ec - 0x10))) = (*(s32 *)(localFrame + (0x288 - 0x10)));
            (*(s32 *)(localFrame + (0x2f0 - 0x10))) = (*(s32 *)(localFrame + (0x28c - 0x10)));
            (*(s32 *)(localFrame + (0x2f4 - 0x10))) = (*(s32 *)(localFrame + (0x290 - 0x10)));
            (*(s32 *)(localFrame + (0x2f8 - 0x10))) = (*(s32 *)(localFrame + (0x294 - 0x10)));
            (*(s32 *)(localFrame + (0x2fc - 0x10))) = (*(s32 *)(localFrame + (0x298 - 0x10)));
            (*(s32 *)(localFrame + (0x300 - 0x10))) = (*(s32 *)(localFrame + (0x29c - 0x10)));
            (*(u8 *)(localFrame + (0x304 - 0x10))) = (*(u8 *)(localFrame + (0x2a0 - 0x10)));
        }
        var_r4 = lbl_8055F4EC;
        if (var_r4 == 0) {
            var_r4 = (var_r4 + 1) % 3;
            lbl_8055F4EC = var_r4;
        }
        if (var_r4 == 2) {
            fn_8026B8A0();
            return;
        }
        if (var_r4 == 0) {
            (*(f32 *)(localFrame + (0x14c - 0x10))) = lbl_80563D78;
            (*(f32 *)(localFrame + (0x150 - 0x10))) = lbl_80563D78;
            (*(f32 *)(localFrame + (0x154 - 0x10))) = lbl_80563D78;
            (*(f32 *)(localFrame + (0x140 - 0x10))) = lbl_80563D78;
            (*(f32 *)(localFrame + (0x144 - 0x10))) = lbl_80563D78;
            (*(f32 *)(localFrame + (0x148 - 0x10))) = lbl_80563D78;
            if ((s8) lbl_8055F501 == 0) {
                temp_r3 = (f32 *)(globalBase + 0x88);
                (*(f32 *)((u8 *)(globalBase) + (0x88))) = (f32) lbl_80563D78;
                (*(f32 *)((u8 *)(temp_r3) + (4))) = (f32) lbl_80563D78;
                (*(f32 *)((u8 *)(temp_r3) + (8))) = (f32) lbl_80563D78;
                lbl_8055F501 = 1;
            }
            if ((s8) lbl_8055F502 == 0) {
                temp_r3_2 = (f32 *)(globalBase + 0x94);
                (*(f32 *)((u8 *)(globalBase) + (0x94))) = (f32) lbl_80563D78;
                (*(f32 *)((u8 *)(temp_r3_2) + (4))) = (f32) lbl_80563D78;
                (*(f32 *)((u8 *)(temp_r3_2) + (8))) = (f32) lbl_80563D78;
                lbl_8055F502 = 1;
            }
            var_f28 = (f32) (fn_802E2C20() - lbl_8055F504) / lbl_80563D88;
            if (var_f28 < lbl_80563D8C) {

            } else {
                var_f28 = lbl_80563D8C;
            }
            temp_r5_2 = (f32 *)(globalBase + 0x88);
            lbl_8055F504 = fn_802E2C20();
            temp_r4 = (f32 *)(globalBase + 0x94);
            temp_f5 = (*(f32 *)((u8 *)(globalBase) + (0x88))) * lbl_80563DD8;
            temp_f4 = (*(f32 *)((u8 *)(temp_r5_2) + (4))) * lbl_80563DD8;
            temp_f3 = (*(f32 *)((u8 *)(temp_r5_2) + (8))) * lbl_80563DD8;
            temp_f2 = (*(f32 *)((u8 *)(globalBase) + (0x94))) * lbl_80563DD8;
            (*(f32 *)((u8 *)(globalBase) + (0x88))) = temp_f5;
            temp_f1 = (*(f32 *)((u8 *)(temp_r4) + (4))) * lbl_80563DD8;
            (*(f32 *)((u8 *)(temp_r5_2) + (4))) = temp_f4;
            (*(f32 *)((u8 *)(temp_r5_2) + (8))) = temp_f3;
            (*(f32 *)((u8 *)(globalBase) + (0x94))) = temp_f2;
            (*(f32 *)((u8 *)(temp_r4) + (4))) = temp_f1;
            (*(f32 *)((u8 *)(temp_r4) + (8))) = (f32) ((*(f32 *)((u8 *)(temp_r4) + (8))) * lbl_80563DD8);
            temp_r29 = fn_802E4A1C(0xFD);
            var_r28 = 0;
            if ((fn_802E4A1C(0xFE) != 0) || (fn_802E4A1C(0x3A) != 0)) {
                var_r28 = 1;
            }
            temp_f1_2 = var_f28 / lbl_80563D8C;
            temp_r0_2 = (temp_r29 * 2) | var_r28;
            (*(f32 *)(localFrame + (0x130 - 0x10))) = (*(f32 *)((u8 *)(lbl_802FA768) + (0)));
            (*(s32 *)(localFrame + (0x134 - 0x10))) = (*(s32 *)((u8 *)(lbl_802FA768) + (4)));
            (*(f32 *)(localFrame + (0x138 - 0x10))) = (*(f32 *)((u8 *)(lbl_802FA768) + (8)));
            (*(f32 *)(localFrame + (0x13c - 0x10))) = (*(f32 *)((u8 *)(lbl_802FA768) + (0xC)));
            (*(f32 *)(localFrame + (0x120 - 0x10))) = (*(f32 *)((u8 *)(lbl_802FA778) + (0)));
            temp_f28 = temp_f1_2 * (&(*(f32 *)(localFrame + (0x130 - 0x10))))[temp_r0_2];
            (*(f32 *)(localFrame + (0x124 - 0x10))) = (*(f32 *)((u8 *)(lbl_802FA778) + (4)));
            (*(f32 *)(localFrame + (0x128 - 0x10))) = (*(f32 *)((u8 *)(lbl_802FA778) + (8)));
            (*(s32 *)(localFrame + (0x12c - 0x10))) = (*(s32 *)((u8 *)(lbl_802FA778) + (0xC)));
            temp_f31 = temp_f1_2 * (&(*(f32 *)(localFrame + (0x120 - 0x10))))[temp_r0_2];
            if (fn_802E4A1C(0x1E) != 0) {
                (*(f32 *)(localFrame + (0x154 - 0x10))) = temp_f28;
            } else if (fn_802E4A1C(0x2C) != 0) {
                (*(f32 *)(localFrame + (0x154 - 0x10))) = -temp_f28;
            }
            if (fn_802E4A1C(0x51) != 0) {
                (*(f32 *)(localFrame + (0x14c - 0x10))) = temp_f28;
            } else if (fn_802E4A1C(0x4F) != 0) {
                (*(f32 *)(localFrame + (0x14c - 0x10))) = -temp_f28;
            }
            if (fn_802E4A1C(0x53) != 0) {
                (*(f32 *)(localFrame + (0x150 - 0x10))) = temp_f28 * lbl_80563D9C;
            } else if (fn_802E4A1C(0x52) != 0) {
                (*(f32 *)(localFrame + (0x150 - 0x10))) = -temp_f28 * lbl_80563D9C;
            }
            if (fn_802E4A1C(0x4D) != 0) {
                if (fn_802E4A1C(0x4F) != 0) {
                    (*(f32 *)(localFrame + (0x144 - 0x10))) = temp_f31 * lbl_80563D9C;
                } else {
                    (*(f32 *)(localFrame + (0x144 - 0x10))) = temp_f31;
                }
            } else if (fn_802E4A1C(0x4B) != 0) {
                if (fn_802E4A1C(0x51) != 0) {
                    (*(f32 *)(localFrame + (0x144 - 0x10))) = -temp_f31 * lbl_80563D9C;
                } else {
                    (*(f32 *)(localFrame + (0x144 - 0x10))) = -temp_f31;
                }
            }
            if (fn_802E4A1C(0x48) != 0) {
                (*(f32 *)(localFrame + (0x140 - 0x10))) = temp_f31 * lbl_80563D9C;
            } else if (fn_802E4A1C(0x50) != 0) {
                (*(f32 *)(localFrame + (0x140 - 0x10))) = -temp_f31 * lbl_80563D9C;
            }
            if (fn_802E4A1C(0x47) != 0) {
                (*(f32 *)(localFrame + (0x148 - 0x10))) = temp_f31;
            } else if (fn_802E4A1C(0x49) != 0) {
                (*(f32 *)(localFrame + (0x148 - 0x10))) = -temp_f31;
            }
            temp_f28_2 = lbl_80563DDC;
            temp_f29 = lbl_80563DE0;
            var_f30 = lbl_80563DE4;
            if (fn_802E4A1C(0x37) != 0) {
                lbl_8055F47C += temp_f28_2;
            } else if (fn_802E4A1C(0xB5) != 0) {
                lbl_8055F47C -= temp_f28_2;
            }
            if (var_f30 < lbl_8055F47C) {

            } else {
                var_f30 = lbl_8055F47C;
            }
            if (var_f30 > temp_f29) {

            } else {
                var_f30 = temp_f29;
            }
            var_r0 = 0;
            lbl_8055F47C = var_f30;
            if ((lbl_80563D78 == (*(f32 *)(localFrame + (0x140 - 0x10)))) && (lbl_80563D78 == (*(f32 *)(localFrame + (0x144 - 0x10)))) && (lbl_80563D78 == (*(f32 *)(localFrame + (0x148 - 0x10))))) {
                var_r0 = 1;
            }
            if (var_r0 == 0) {
                temp_r3_3 = (f32 *)(globalBase + 0x94);
                (*(f32 *)((u8 *)(globalBase) + (0x94))) = (*(f32 *)(localFrame + (0x140 - 0x10)));
                (*(f32 *)((u8 *)(temp_r3_3) + (4))) = (*(f32 *)(localFrame + (0x144 - 0x10)));
                (*(f32 *)((u8 *)(temp_r3_3) + (8))) = (*(f32 *)(localFrame + (0x148 - 0x10)));
            }
            var_r0_2 = 0;
            if ((lbl_80563D78 == (*(f32 *)(localFrame + (0x14c - 0x10)))) && (lbl_80563D78 == (*(f32 *)(localFrame + (0x150 - 0x10)))) && (lbl_80563D78 == (*(f32 *)(localFrame + (0x154 - 0x10))))) {
                var_r0_2 = 1;
            }
            if (var_r0_2 == 0) {
                temp_r3_4 = (f32 *)(globalBase + 0x88);
                (*(f32 *)((u8 *)(globalBase) + (0x88))) = (*(f32 *)(localFrame + (0x14c - 0x10)));
                (*(f32 *)((u8 *)(temp_r3_4) + (4))) = (*(f32 *)(localFrame + (0x150 - 0x10)));
                (*(f32 *)((u8 *)(temp_r3_4) + (8))) = (*(f32 *)(localFrame + (0x154 - 0x10)));
            }
            temp_r3_5 = (f32 *)(globalBase + 0x88);
            if (&(*(f32 *)(localFrame + (0x68 - 0x10))) == temp_r3_5) {
                temp_f6 = (*(f32 *)((u8 *)(temp_r3_5) + (4)));
                temp_f7 = (*(f32 *)((u8 *)(temp_r3_5) + (8)));
                (*(f32 *)(localFrame + (0x68 - 0x10))) = (temp_f7 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + (((*(f32 *)((u8 *)(globalBase) + (0x88))) * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (temp_f6 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                (*(f32 *)(localFrame + (0x6c - 0x10))) = (temp_f7 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + (((*(f32 *)((u8 *)(globalBase) + (0x88))) * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (temp_f6 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                (*(f32 *)(localFrame + (0x70 - 0x10))) = (temp_f7 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + (((*(f32 *)((u8 *)(globalBase) + (0x88))) * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (temp_f6 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
            } else {
                temp_f6_2 = (*(f32 *)((u8 *)(temp_r3_5) + (4)));
                temp_f7_2 = (*(f32 *)((u8 *)(temp_r3_5) + (8)));
                (*(f32 *)(localFrame + (0x68 - 0x10))) = (temp_f7_2 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + (((*(f32 *)((u8 *)(globalBase) + (0x88))) * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (temp_f6_2 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                (*(f32 *)(localFrame + (0x6c - 0x10))) = (temp_f7_2 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + (((*(f32 *)((u8 *)(globalBase) + (0x88))) * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (temp_f6_2 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                (*(f32 *)(localFrame + (0x70 - 0x10))) = (temp_f7_2 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + (((*(f32 *)((u8 *)(globalBase) + (0x88))) * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (temp_f6_2 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
            }
            temp_f3_2 = (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) + (*(f32 *)(localFrame + (0x68 - 0x10)));
            temp_f2_2 = (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) + (*(f32 *)(localFrame + (0x6c - 0x10)));
            temp_f1_3 = (*(f32 *)((u8 *)(lbl_80499050) + (0x2C)));
            (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) = temp_f3_2;
            (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) = temp_f2_2;
            (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) = (f32) (temp_f1_3 + (*(f32 *)(localFrame + (0x70 - 0x10))));
            fn_80015A20(&(*(f32 *)(localFrame + (0x1e8 - 0x10))), (f32 *)(globalBase + 0x94));
            fn_80015B20(lbl_80499050, &(*(f32 *)(localFrame + (0x1e8 - 0x10))), (f32 *)lbl_80499050);
        } else if ((*(s32 *)(localFrame + (0x2f4 - 0x10))) & 0x10) {
            temp_r3_6 = fn_802E2C20();
            temp_r0_3 = temp_r3_6 - lbl_8055F508;
            var_f4 = lbl_80563DEC;
            lbl_8055F508 = temp_r3_6;
            if ((lbl_80563DE8 * (f32) temp_r0_3) > var_f4) {
                var_f4 = lbl_80563DE8 * (f32) temp_r0_3;
            }
            var_f31 = lbl_80563DF4 * (lbl_80563DF8 * (lbl_80563DFC * var_f4));
            var_f2 = lbl_80563DE4;
            if ((s32) (u8) (*(s32 *)(localFrame + (0x2c8 - 0x10))) != 0) {
                var_f31 = lbl_80563D78;
                var_f1 = var_f31;
                if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 1) {
                    var_f1 = lbl_80563D98;
                }
                if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 4) {
                    var_f1 = lbl_80563D94;
                }
                temp_f0 = lbl_8055F47C + (var_f1 * (var_f4 * lbl_80563E00));
                if (var_f2 < temp_f0) {

                } else {
                    var_f2 = temp_f0;
                }
                if (var_f2 > lbl_80563DE0) {

                } else {
                    var_f2 = lbl_80563DE0;
                }
                lbl_8055F47C = var_f2;
            } else if ((s32) (((u32)(*(s32 *)(localFrame + (0x2c8 - 0x10))) >> 16) & 0xFF) != 0) {
                var_f31 *= lbl_80563D7C;
            } else if ((s32) (((u32)(*(s32 *)(localFrame + (0x2c4 - 0x10))) >> 8) & 0xFF) != 0) {
                var_f31 *= lbl_80563DA0;
            }
            var_f3 = lbl_80563D78;
            if ((*(f32 *)(localFrame + (0x2a4 - 0x10))) > var_f3) {
                var_f3 = lbl_80563D94;
                temp_f0_2 = (lbl_80563D84 * (*(f32 *)(localFrame + (0x2a4 - 0x10)))) - lbl_80563D7C;
                if (var_f3 < temp_f0_2) {

                } else {
                    var_f3 = temp_f0_2;
                }
                if (var_f3 > lbl_80563D78) {

                } else {
                    var_f3 = lbl_80563D78;
                }
            } else {
                temp_f0_3 = lbl_80563D7C + (lbl_80563D84 * (*(f32 *)(localFrame + (0x2a4 - 0x10))));
                if (var_f3 < temp_f0_3) {

                } else {
                    var_f3 = temp_f0_3;
                }
                if (var_f3 > lbl_80563D98) {

                } else {
                    var_f3 = lbl_80563D98;
                }
            }
            temp_f4_2 = (*(f32 *)(localFrame + (0x2a8 - 0x10))) * lbl_80563DB0;
            temp_f30 = lbl_8055F50C + (var_f4 * lbl_80563DF0 * var_f3);
            temp_f3_3 = lbl_8055F510 - temp_f4_2;
            (*(f32 *)((u8 *)(lbl_80499050) + (0))) = lbl_80563D94;
            (*(f32 *)((u8 *)(lbl_80499050) + (4))) = (f32) lbl_80563D78;
            temp_f2_3 = temp_f4_2 + (lbl_80563E04 * temp_f3_3);
            (*(f32 *)((u8 *)(lbl_80499050) + (8))) = (f32) lbl_80563D78;
            (*(f32 *)((u8 *)(lbl_80499050) + (0xC))) = (f32) lbl_80563D78;
            lbl_8055F510 = temp_f2_3;
            (*(f32 *)((u8 *)(lbl_80499050) + (0x10))) = (f32) lbl_80563D94;
            (*(f32 *)((u8 *)(lbl_80499050) + (0x14))) = (f32) lbl_80563D78;
            (*(f32 *)((u8 *)(lbl_80499050) + (0x18))) = (f32) lbl_80563D78;
            (*(f32 *)((u8 *)(lbl_80499050) + (0x1C))) = (f32) lbl_80563D78;
            (*(f32 *)((u8 *)(lbl_80499050) + (0x20))) = (f32) lbl_80563D94;
            (*(f32 *)(localFrame + (0xe0 - 0x10))) = lbl_80563D78;
            (*(f32 *)(localFrame + (0xe4 - 0x10))) = temp_f30;
            (*(f32 *)(localFrame + (0xe8 - 0x10))) = lbl_80563D78;
            fn_80015A20(&(*(f32 *)(localFrame + (0x1c4 - 0x10))), &(*(f32 *)(localFrame + (0xe0 - 0x10))));
            fn_80015B20(lbl_80499050, &(*(f32 *)(localFrame + (0x1c4 - 0x10))), (f32 *)lbl_80499050);
            temp_f1_4 = -lbl_8055F510;
            (*(f32 *)(localFrame + (0xd8 - 0x10))) = lbl_80563D78;
            (*(f32 *)(localFrame + (0xd4 - 0x10))) = temp_f1_4;
            (*(f32 *)(localFrame + (0xdc - 0x10))) = lbl_80563D78;
            fn_80015A20(&(*(f32 *)(localFrame + (0x1a0 - 0x10))), &(*(f32 *)(localFrame + (0xd4 - 0x10))));
            fn_80015B20(lbl_80499050, &(*(f32 *)(localFrame + (0x1a0 - 0x10))), (f32 *)lbl_80499050);
            var_f0 = lbl_80563D78;
            var_f3_2 = var_f0;
            if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 1) {
                var_f3_2 = var_f31;
            } else if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 4) {
                var_f3_2 = -var_f31;
            }
            if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 8) {
                var_f0 = -var_f31;
            } else if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 2) {
                var_f0 = var_f31;
            }
            (*(f32 *)(localFrame + (0xc8 - 0x10))) = var_f0;
            (*(f32 *)(localFrame + (0xcc - 0x10))) = lbl_80563D78;
            (*(f32 *)(localFrame + (0xd0 - 0x10))) = var_f3_2;
            if (&(*(f32 *)(localFrame + (0x5c - 0x10))) == &(*(f32 *)(localFrame + (0xc8 - 0x10)))) {
                temp_f0_4 = (f32) var_f0;
                temp_f7_3 = (f32) var_f3_2;
                (*(f32 *)(localFrame + (0x5c - 0x10))) = (temp_f7_3 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + ((temp_f0_4 * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                (*(f32 *)(localFrame + (0x60 - 0x10))) = (temp_f7_3 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + ((temp_f0_4 * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                (*(f32 *)(localFrame + (0x64 - 0x10))) = (temp_f7_3 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + ((temp_f0_4 * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
            } else {
                temp_f0_5 = (f32) var_f0;
                temp_f7_4 = (f32) var_f3_2;
                (*(f32 *)(localFrame + (0x5c - 0x10))) = (temp_f7_4 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + ((temp_f0_5 * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                (*(f32 *)(localFrame + (0x60 - 0x10))) = (temp_f7_4 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + ((temp_f0_5 * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                (*(f32 *)(localFrame + (0x64 - 0x10))) = (temp_f7_4 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + ((temp_f0_5 * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
            }
            lbl_8055F50C = temp_f30;
            (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x24))) + (*(f32 *)(localFrame + (0x5c - 0x10))));
            (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x28))) + (*(f32 *)(localFrame + (0x60 - 0x10))));
            (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) + (*(f32 *)(localFrame + (0x64 - 0x10))));
        } else {
            temp_r3_7 = fn_802E2C20();
            temp_r0_4 = temp_r3_7 - lbl_8055F514;
            var_f5 = lbl_80563DEC;
            lbl_8055F514 = temp_r3_7;
            if ((lbl_80563DE8 * (f32) temp_r0_4) > var_f5) {
                var_f5 = lbl_80563DE8 * (f32) temp_r0_4;
            }
            temp_f0_6 = ((*(f32 *)(localFrame + (0x2c0 - 0x10))) - lbl_80563D98) * lbl_80563D9C;
            var_f6 = lbl_80563D94;
            temp_f30_2 = var_f5 * lbl_80563DF0;
            var_f4_2 = lbl_80563DE4;
            if (var_f6 < temp_f0_6) {

            } else {
                var_f6 = temp_f0_6;
            }
            if (var_f6 > lbl_80563D78) {

            } else {
                var_f6 = lbl_80563D78;
            }
            var_f1_2 = lbl_80563D94;
            temp_f0_7 = var_f1_2 + (var_f6 * lbl_80563DA0);
            if ((s32) (((u32)(*(s32 *)(localFrame + (0x2c8 - 0x10))) >> 8) & 0xFF) != 0) {
                var_f1_2 = lbl_80563DF4;
            }
            var_f27 = lbl_80563D78;
            temp_f31_2 = lbl_80563DF8 * (lbl_80563DFC * var_f5) * (var_f1_2 * temp_f0_7);
            if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 8) {
                var_f27 = temp_f31_2;
            } else if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 2) {
                var_f27 = lbl_80563D98 * temp_f31_2;
            }
            var_f29 = lbl_80563D78;
            if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 1) {
                var_f29 = temp_f31_2;
            }
            if ((*(s32 *)(localFrame + (0x2e4 - 0x10))) & 4) {
                var_f29 = lbl_80563D98 * temp_f31_2;
            }
            if ((s32) (((u32)(*(s32 *)(localFrame + (0x2c8 - 0x10))) >> 16) & 0xFF) != 0) {
                temp_f0_8 = lbl_8055F47C + ((*(f32 *)(localFrame + (0x2a8 - 0x10))) * (var_f5 * lbl_80563E00));
                if (var_f4_2 < temp_f0_8) {

                } else {
                    var_f4_2 = temp_f0_8;
                }
                if (var_f4_2 > lbl_80563DE0) {

                } else {
                    var_f4_2 = lbl_80563DE0;
                }
                lbl_8055F47C = var_f4_2;
            } else {
                switch ((s32) lbl_8055F4E0) {       /* switch 1; irregular */
                case 4:                             /* switch 1 */
                case 0:                             /* switch 1 */
                    temp_f28_3 = temp_f30_2 * fn_8026B844((*(f32 *)(localFrame + (0x2a4 - 0x10))));
                    temp_f1_5 = -fn_8026B844((*(f32 *)(localFrame + (0x2a8 - 0x10))));
                    (*(f32 *)(localFrame + (0xc0 - 0x10))) = temp_f28_3;
                    temp_f1_6 = temp_f30_2 * temp_f1_5;
                    (*(f32 *)(localFrame + (0xc4 - 0x10))) = var_f27 * temp_f30_2;
                    (*(f32 *)(localFrame + (0xbc - 0x10))) = temp_f1_6;
                    fn_80015A20(&(*(f32 *)(localFrame + (0x17c - 0x10))), &(*(f32 *)(localFrame + (0xbc - 0x10))));
                    fn_80015B20(lbl_80499050, &(*(f32 *)(localFrame + (0x17c - 0x10))), (f32 *)lbl_80499050);
                    temp_f6_3 = (*(f32 *)(localFrame + (0x2b0 - 0x10))) * temp_f31_2;
                    temp_f7_5 = -(*(f32 *)(localFrame + (0x2ac - 0x10))) * temp_f31_2;
                    temp_f0_9 = lbl_80563DEC * (var_f29 * temp_f31_2);
                    (*(f32 *)(localFrame + (0xb0 - 0x10))) = temp_f6_3;
                    (*(f32 *)(localFrame + (0xb4 - 0x10))) = temp_f0_9;
                    (*(f32 *)(localFrame + (0xb8 - 0x10))) = temp_f7_5;
                    if (&(*(f32 *)(localFrame + (0x50 - 0x10))) == &(*(f32 *)(localFrame + (0xb0 - 0x10)))) {
                        (*(f32 *)(localFrame + (0x50 - 0x10))) = (temp_f7_5 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + ((temp_f6_3 * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (temp_f0_9 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                        (*(f32 *)(localFrame + (0x54 - 0x10))) = (temp_f7_5 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + ((temp_f6_3 * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (temp_f0_9 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                        (*(f32 *)(localFrame + (0x58 - 0x10))) = (temp_f7_5 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + ((temp_f6_3 * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (temp_f0_9 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
                    } else {
                        (*(f32 *)(localFrame + (0x50 - 0x10))) = (temp_f7_5 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + ((temp_f6_3 * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (temp_f0_9 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                        (*(f32 *)(localFrame + (0x54 - 0x10))) = (temp_f7_5 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + ((temp_f6_3 * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (temp_f0_9 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                        (*(f32 *)(localFrame + (0x58 - 0x10))) = (temp_f7_5 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + ((temp_f6_3 * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (temp_f0_9 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
                    }
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x24))) + (*(f32 *)(localFrame + (0x50 - 0x10))));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x28))) + (*(f32 *)(localFrame + (0x54 - 0x10))));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) + (*(f32 *)(localFrame + (0x58 - 0x10))));
                    break;
                case 1:                             /* switch 1 */
                    temp_f0_10 = -fn_8026B844((*(f32 *)(localFrame + (0x2a8 - 0x10))));
                    (*(f32 *)(localFrame + (0xa4 - 0x10))) = lbl_80563D78;
                    temp_f0_11 = temp_f31_2 * temp_f0_10;
                    (*(f32 *)(localFrame + (0xac - 0x10))) = lbl_80563D78;
                    (*(f32 *)(localFrame + (0xa8 - 0x10))) = temp_f0_11;
                    if (&(*(f32 *)(localFrame + (0x44 - 0x10))) == &(*(f32 *)(localFrame + (0xa4 - 0x10)))) {
                        (*(f32 *)(localFrame + (0x44 - 0x10))) = (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + ((lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (temp_f0_11 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                        (*(f32 *)(localFrame + (0x48 - 0x10))) = (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + ((lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (temp_f0_11 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                        (*(f32 *)(localFrame + (0x4c - 0x10))) = (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + ((lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (temp_f0_11 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
                    } else {
                        (*(f32 *)(localFrame + (0x44 - 0x10))) = (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + ((lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (temp_f0_11 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                        (*(f32 *)(localFrame + (0x48 - 0x10))) = (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + ((lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (temp_f0_11 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                        (*(f32 *)(localFrame + (0x4c - 0x10))) = (lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + ((lbl_80563D78 * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (temp_f0_11 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
                    }
                    temp_f7_6 = (*(f32 *)(localFrame + (0x2b0 - 0x10))) * temp_f31_2;
                    temp_f0_12 = -(*(f32 *)(localFrame + (0x2ac - 0x10))) * temp_f31_2;
                    temp_f1_7 = lbl_80563DEC * (var_f29 * temp_f31_2);
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x28))) + (*(f32 *)(localFrame + (0x48 - 0x10))));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x24))) + (*(f32 *)(localFrame + (0x44 - 0x10))));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) + (*(f32 *)(localFrame + (0x4c - 0x10))));
                    (*(f32 *)(localFrame + (0x98 - 0x10))) = temp_f7_6;
                    (*(f32 *)(localFrame + (0x9c - 0x10))) = temp_f1_7;
                    (*(f32 *)(localFrame + (0xa0 - 0x10))) = temp_f0_12;
                    if (&(*(f32 *)(localFrame + (0x38 - 0x10))) == &(*(f32 *)(localFrame + (0x98 - 0x10)))) {
                        (*(f32 *)(localFrame + (0x38 - 0x10))) = (temp_f0_12 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + ((temp_f7_6 * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (temp_f1_7 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                        (*(f32 *)(localFrame + (0x3c - 0x10))) = (temp_f0_12 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + ((temp_f7_6 * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (temp_f1_7 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                        (*(f32 *)(localFrame + (0x40 - 0x10))) = (temp_f0_12 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + ((temp_f7_6 * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (temp_f1_7 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
                    } else {
                        (*(f32 *)(localFrame + (0x38 - 0x10))) = (temp_f0_12 * (*(f32 *)((u8 *)(lbl_80499050) + (0x18)))) + ((temp_f7_6 * (*(f32 *)((u8 *)(lbl_80499050) + (0)))) + (temp_f1_7 * (*(f32 *)((u8 *)(lbl_80499050) + (0xC)))));
                        (*(f32 *)(localFrame + (0x3c - 0x10))) = (temp_f0_12 * (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)))) + ((temp_f7_6 * (*(f32 *)((u8 *)(lbl_80499050) + (4)))) + (temp_f1_7 * (*(f32 *)((u8 *)(lbl_80499050) + (0x10)))));
                        (*(f32 *)(localFrame + (0x40 - 0x10))) = (temp_f0_12 * (*(f32 *)((u8 *)(lbl_80499050) + (0x20)))) + ((temp_f7_6 * (*(f32 *)((u8 *)(lbl_80499050) + (8)))) + (temp_f1_7 * (*(f32 *)((u8 *)(lbl_80499050) + (0x14)))));
                    }
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x24))) + (*(f32 *)(localFrame + (0x38 - 0x10))));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x28))) + (*(f32 *)(localFrame + (0x3c - 0x10))));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) + (*(f32 *)(localFrame + (0x40 - 0x10))));
                    break;
                case 3:                             /* switch 1 */
                    temp_r28 = (f32 *)(globalBase + 0x58);
                    temp_f8 = temp_f31_2 * fn_8026B844((*(f32 *)(localFrame + (0x2b0 - 0x10))));
                    temp_f7_7 = (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) + ((*(f32 *)((u8 *)(globalBase) + (0x58))) * temp_f8);
                    temp_f6_4 = (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) + ((*(f32 *)((u8 *)(temp_r28) + (4))) * temp_f8);
                    temp_f4_3 = lbl_80563DEC * (var_f29 * temp_f31_2);
                    temp_f5_2 = (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) + ((*(f32 *)((u8 *)(temp_r28) + (8))) * temp_f8);
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) = temp_f7_7;
                    temp_f3_4 = temp_f7_7 + ((*(f32 *)((u8 *)(temp_r28) + (0xC))) * temp_f4_3);
                    temp_f2_4 = temp_f6_4 + ((*(f32 *)((u8 *)(temp_r28) + (0x10))) * temp_f4_3);
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) = temp_f3_4;
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) = temp_f2_4;
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) = (f32) (temp_f5_2 + ((*(f32 *)((u8 *)(temp_r28) + (0x14))) * temp_f4_3));
                    temp_f6_5 = temp_f31_2 * -fn_8026B844((*(f32 *)(localFrame + (0x2ac - 0x10))));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x24))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x24))) + ((*(f32 *)((u8 *)(temp_r28) + (0x18))) * temp_f6_5));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x28))) + ((*(f32 *)((u8 *)(temp_r28) + (0x1C))) * temp_f6_5));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) = (f32) ((*(f32 *)((u8 *)(lbl_80499050) + (0x2C))) + ((*(f32 *)((u8 *)(temp_r28) + (0x20))) * temp_f6_5));
                    break;
                case 2:                             /* switch 1 */
                    temp_f28_4 = temp_f30_2 * fn_8026B844((*(f32 *)(localFrame + (0x2a4 - 0x10))));
                    temp_f1_8 = -fn_8026B844((*(f32 *)(localFrame + (0x2a8 - 0x10))));
                    (*(f32 *)(localFrame + (0x90 - 0x10))) = temp_f28_4;
                    temp_f1_9 = temp_f30_2 * temp_f1_8;
                    (*(f32 *)(localFrame + (0x94 - 0x10))) = var_f27 * temp_f30_2;
                    (*(f32 *)(localFrame + (0x8c - 0x10))) = temp_f1_9;
                    fn_80015A20(&(*(f32 *)(localFrame + (0x158 - 0x10))), &(*(f32 *)(localFrame + (0x8c - 0x10))));
                    fn_80015B20(globalBase, &(*(f32 *)(localFrame + (0x158 - 0x10))), globalBase);
                    temp_f6_6 = (*(f32 *)(localFrame + (0x2b0 - 0x10))) * temp_f31_2;
                    temp_f7_8 = -(*(f32 *)(localFrame + (0x2ac - 0x10))) * temp_f31_2;
                    temp_f0_13 = lbl_80563DEC * (var_f29 * temp_f31_2);
                    (*(f32 *)(localFrame + (0x80 - 0x10))) = temp_f6_6;
                    (*(f32 *)(localFrame + (0x84 - 0x10))) = temp_f0_13;
                    (*(f32 *)(localFrame + (0x88 - 0x10))) = temp_f7_8;
                    if (&(*(f32 *)(localFrame + (0x2c - 0x10))) == &(*(f32 *)(localFrame + (0x80 - 0x10)))) {
                        (*(f32 *)(localFrame + (0x2c - 0x10))) = (temp_f7_8 * (*(f32 *)((u8 *)(globalBase) + (0x18)))) + ((temp_f6_6 * (*(f32 *)((u8 *)(globalBase) + (0)))) + (temp_f0_13 * (*(f32 *)((u8 *)(globalBase) + (0xC)))));
                        (*(f32 *)(localFrame + (0x30 - 0x10))) = (temp_f7_8 * (*(f32 *)((u8 *)(globalBase) + (0x1C)))) + ((temp_f6_6 * (*(f32 *)((u8 *)(globalBase) + (4)))) + (temp_f0_13 * (*(f32 *)((u8 *)(globalBase) + (0x10)))));
                        (*(f32 *)(localFrame + (0x34 - 0x10))) = (temp_f7_8 * (*(f32 *)((u8 *)(globalBase) + (0x20)))) + ((temp_f6_6 * (*(f32 *)((u8 *)(globalBase) + (8)))) + (temp_f0_13 * (*(f32 *)((u8 *)(globalBase) + (0x14)))));
                    } else {
                        (*(f32 *)(localFrame + (0x2c - 0x10))) = (temp_f7_8 * (*(f32 *)((u8 *)(globalBase) + (0x18)))) + ((temp_f6_6 * (*(f32 *)((u8 *)(globalBase) + (0)))) + (temp_f0_13 * (*(f32 *)((u8 *)(globalBase) + (0xC)))));
                        (*(f32 *)(localFrame + (0x30 - 0x10))) = (temp_f7_8 * (*(f32 *)((u8 *)(globalBase) + (0x1C)))) + ((temp_f6_6 * (*(f32 *)((u8 *)(globalBase) + (4)))) + (temp_f0_13 * (*(f32 *)((u8 *)(globalBase) + (0x10)))));
                        (*(f32 *)(localFrame + (0x34 - 0x10))) = (temp_f7_8 * (*(f32 *)((u8 *)(globalBase) + (0x20)))) + ((temp_f6_6 * (*(f32 *)((u8 *)(globalBase) + (8)))) + (temp_f0_13 * (*(f32 *)((u8 *)(globalBase) + (0x14)))));
                    }
                    (*(f32 *)((u8 *)(globalBase) + (0x24))) = (f32) ((*(f32 *)((u8 *)(globalBase) + (0x24))) + (*(f32 *)(localFrame + (0x2c - 0x10))));
                    (*(f32 *)((u8 *)(globalBase) + (0x28))) = (f32) ((*(f32 *)((u8 *)(globalBase) + (0x28))) + (*(f32 *)(localFrame + (0x30 - 0x10))));
                    (*(f32 *)((u8 *)(globalBase) + (0x2C))) = (f32) ((*(f32 *)((u8 *)(globalBase) + (0x2C))) + (*(f32 *)(localFrame + (0x34 - 0x10))));
                    break;
                default:                            /* switch 1 */
                    fn_802E317C(lbl_80346A50);
                    break;
                }
            }
        }
        switch ((s32) lbl_8055F4E0) {               /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            if (arg0 != 0) {
                temp_r3_8 = fn_8017960C(fn_8026A344(0));
                if (temp_r3_8 != NULL) {
                    temp_f5_3 = (*(f32 *)((u8 *)(temp_r3_8) + (0x60))) - (*(f32 *)((u8 *)(lbl_80499050) + (0x24)));
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x18))) = temp_f5_3;
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x1C))) = (f32) ((*(f32 *)((u8 *)(temp_r3_8) + (0x64))) - (*(f32 *)((u8 *)(lbl_80499050) + (0x28))));
                    temp_f3_5 = (*(f32 *)((u8 *)(temp_r3_8) + (0x68))) - (*(f32 *)((u8 *)(lbl_80499050) + (0x2C)));
                    (*(f32 *)(localFrame + (0x114 - 0x10))) = lbl_80563D94;
                    (*(f32 *)(localFrame + (0x110 - 0x10))) = lbl_80563D78;
                    (*(f32 *)((u8 *)(lbl_80499050) + (0x20))) = temp_f3_5;
                    (*(f32 *)(localFrame + (0x118 - 0x10))) = lbl_80563D78;
                    if (((temp_f5_3 * temp_f5_3) + (temp_f3_5 * temp_f3_5)) > lbl_80563E08) {
                        PSVECCrossProduct(&(*(f32 *)(localFrame + (0x110 - 0x10))), (f32 *)((u8 *)lbl_80499050 + 0x18), (f32 *)lbl_80499050);
                        PSVECCrossProduct((f32 *)((u8 *)lbl_80499050 + 0x18), (f32 *)lbl_80499050, (f32 *)((u8 *)lbl_80499050 + 0xC));
                        (*(f32 *)(localFrame + (0x8 - 0x10))) = (*(f32 *)((u8 *)(lbl_80499050) + (0)));
                        (*(f32 *)(localFrame + (0xc - 0x10))) = (*(f32 *)((u8 *)(lbl_80499050) + (4)));
                        (*(f32 *)(localFrame + (0x10 - 0x10))) = (*(f32 *)((u8 *)(lbl_80499050) + (8)));
                        (*(f32 *)(localFrame + (0x20 - 0x10))) = (*(f32 *)((u8 *)(lbl_80499050) + (0x18)));
                        (*(f32 *)(localFrame + (0x24 - 0x10))) = (*(f32 *)((u8 *)(lbl_80499050) + (0x1C)));
                        (*(f32 *)(localFrame + (0x28 - 0x10))) = (*(f32 *)((u8 *)(lbl_80499050) + (0x20)));
                        PSVECCrossProduct(&(*(f32 *)(localFrame + (0x20 - 0x10))), &(*(f32 *)(localFrame + (0x8 - 0x10))), &(*(f32 *)(localFrame + (0x14 - 0x10))));
                        PSVECNormalize(&(*(f32 *)(localFrame + (0x8 - 0x10))), &(*(f32 *)(localFrame + (0x8 - 0x10))));
                        PSVECNormalize(&(*(f32 *)(localFrame + (0x14 - 0x10))), &(*(f32 *)(localFrame + (0x14 - 0x10))));
                        PSVECCrossProduct(&(*(f32 *)(localFrame + (0x8 - 0x10))), &(*(f32 *)(localFrame + (0x14 - 0x10))), &(*(f32 *)(localFrame + (0x20 - 0x10))));
                        (*(f32 *)((u8 *)(lbl_80499050) + (0))) = (*(f32 *)(localFrame + (0x8 - 0x10)));
                        (*(f32 *)((u8 *)(lbl_80499050) + (4))) = (*(f32 *)(localFrame + (0xc - 0x10)));
                        (*(f32 *)((u8 *)(lbl_80499050) + (8))) = (*(f32 *)(localFrame + (0x10 - 0x10)));
                        (*(f32 *)((u8 *)(lbl_80499050) + (0xC))) = (*(f32 *)(localFrame + (0x14 - 0x10)));
                        (*(f32 *)((u8 *)(lbl_80499050) + (0x10))) = (*(f32 *)(localFrame + (0x18 - 0x10)));
                        (*(f32 *)((u8 *)(lbl_80499050) + (0x14))) = (*(f32 *)(localFrame + (0x1c - 0x10)));
                        (*(f32 *)((u8 *)(lbl_80499050) + (0x18))) = (*(f32 *)(localFrame + (0x20 - 0x10)));
                        (*(f32 *)((u8 *)(lbl_80499050) + (0x1C))) = (*(f32 *)(localFrame + (0x24 - 0x10)));
                        (*(f32 *)((u8 *)(lbl_80499050) + (0x20))) = (*(f32 *)(localFrame + (0x28 - 0x10)));
                        return;
                    }
                }
            } else {
                switch ((s32) lbl_8055F4E0) {       /* switch 3; irregular */
                case 2:                             /* switch 3 */
                    if (arg0 != 0) {
                        temp_r27 = fn_8026A344(0);
                        temp_r3_9 = fn_8017960C(temp_r27);
                        if ((temp_r3_9 != NULL) && ((s32)lbl_8055F4E4 & 4)) {
                            (*(f32 *)(localFrame + (0x210 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x3C)));
                            (*(f32 *)(localFrame + (0x214 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x40)));
                            (*(f32 *)(localFrame + (0x218 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x44)));
                            (*(f32 *)(localFrame + (0x21c - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x48)));
                            (*(f32 *)(localFrame + (0x220 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x4C)));
                            (*(f32 *)(localFrame + (0x224 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x50)));
                            (*(f32 *)(localFrame + (0x228 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x54)));
                            (*(f32 *)(localFrame + (0x22c - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x58)));
                            (*(f32 *)(localFrame + (0x230 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x5C)));
                            (*(f32 *)(localFrame + (0x234 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x60)));
                            (*(f32 *)(localFrame + (0x238 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x64)));
                            (*(f32 *)(localFrame + (0x23c - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x68)));
                        } else if (temp_r3_9 != NULL) {
                            temp_r28_2 = (u8 *)temp_r3_9 + 0x3C;
                            temp_f1_10 = (*(f32 *)((u8 *)(temp_r3_9) + (0x5C))) + ((*(f32 *)((u8 *)(temp_r3_9) + (0x3C))) + (*(f32 *)((u8 *)(temp_r3_9) + (0x4C))));
                            if (temp_f1_10 > lbl_80563D78) {
                                temp_f1_11 = (f32) fn_8002F234(lbl_80563D94 + temp_f1_10);
                                temp_f2_5 = lbl_80563D9C / temp_f1_11;
                                (*(f32 *)(localFrame + (0x10c - 0x10))) = lbl_80563D9C * temp_f1_11;
                                (*(f32 *)(localFrame + (0x100 - 0x10))) = temp_f2_5 * ((*(f32 *)((u8 *)(temp_r28_2) + (0x14))) - (*(f32 *)((u8 *)(temp_r28_2) + (0x1C))));
                                (*(f32 *)(localFrame + (0x104 - 0x10))) = temp_f2_5 * ((*(f32 *)((u8 *)(temp_r28_2) + (0x18))) - (*(f32 *)((u8 *)(temp_r28_2) + (8))));
                                (*(f32 *)(localFrame + (0x108 - 0x10))) = temp_f2_5 * ((*(f32 *)((u8 *)(temp_r28_2) + (4))) - (*(f32 *)((u8 *)(temp_r28_2) + (0xC))));
                            } else {
                                var_r7 = 0;
                                if ((*(f32 *)((u8 *)(temp_r28_2) + (0x10))) > (*(f32 *)((u8 *)(temp_r3_9) + (0x3C)))) {
                                    var_r7 = 1;
                                }
                                if ((*(f32 *)((u8 *)(temp_r28_2) + (0x20))) > (*(f32 *)((u8 *)(u8 *)temp_r28_2 + (var_r7 * 0xC) + (var_r7 * 4)))) {
                                    var_r7 = 2;
                                }
                                temp_r6 = (var_r7 + 1) % 3;
                                temp_r5_3 = (temp_r6 + 1) % 3;
                                temp_r4_2 = temp_r5_3 * 0xC;
                                temp_r3_10 = temp_r6 * 0xC;
                                temp_r23 = temp_r5_3 * 4;
                                temp_r26 = (u8 *)temp_r28_2 + temp_r4_2;
                                temp_r22 = (u8 *)temp_r28_2 + temp_r3_10;
                                temp_r25 = temp_r6 * 4;
                                temp_r24 = var_r7 * 4;
                                temp_r28_3 = (u8 *)temp_r28_2 + (var_r7 * 0xC);
                                temp_f2_6 = (*(f32 *)((u8 *)temp_r22 + temp_r25)) + (*(f32 *)((u8 *)temp_r26 + temp_r23));
                                temp_f1_12 = (f32) fn_8002F234((*((f32 *)&(temp_r3_10))));
                                temp_f2_7 = lbl_80563D9C / temp_f1_12;
                                (&(*(f32 *)(localFrame + (0x100 - 0x10))))[var_r7] = lbl_80563D9C * temp_f1_12;
                                (*(f32 *)(localFrame + (0x10c - 0x10))) = temp_f2_7 * ((*(f32 *)((u8 *)temp_r22 + temp_r23)) - (*(f32 *)((u8 *)temp_r26 + temp_r25)));
                                (&(*(f32 *)(localFrame + (0x100 - 0x10))))[temp_r6] = temp_f2_7 * ((*(f32 *)((u8 *)temp_r28_3 + temp_r25)) + (*(f32 *)((u8 *)temp_r22 + temp_r24)));
                                (&(*(f32 *)(localFrame + (0x100 - 0x10))))[temp_r5_3] = temp_f2_7 * ((*(f32 *)((u8 *)temp_r28_3 + temp_r23)) + (*(f32 *)((u8 *)temp_r26 + temp_r24)));
                            }
                            if (temp_r27 == (s32) (*(s32 *)((u8 *)(globalBase) + (0x50)))) {
                                fn_8012F57C(&(*(f32 *)(localFrame + (0xf0 - 0x10))), (f32 *)(globalBase + 0x30), &(*(f32 *)(localFrame + (0x100 - 0x10))), lbl_80563E0C);
                                if (!((s32)lbl_8055F4E4 & 2)) {
                                    temp_f2_8 = 2.0f * (*(f32 *)(localFrame + (0xf0 - 0x10)));
                                    temp_f11 = 2.0f * (*(f32 *)(localFrame + (0xf4 - 0x10)));
                                    temp_f10 = 2.0f * (*(f32 *)(localFrame + (0xf8 - 0x10)));
                                    temp_f4_4 = (*(f32 *)(localFrame + (0xf0 - 0x10))) * temp_f2_8;
                                    temp_f3_6 = (*(f32 *)(localFrame + (0xf4 - 0x10))) * temp_f11;
                                    temp_f0_14 = (*(f32 *)(localFrame + (0xf8 - 0x10))) * temp_f10;
                                    temp_f9 = (*(f32 *)(localFrame + (0xfc - 0x10))) * temp_f2_8;
                                    temp_f8_2 = (*(f32 *)(localFrame + (0xf4 - 0x10))) * temp_f10;
                                    (*(f32 *)(localFrame + (0x210 - 0x10))) = lbl_80563D94 - (temp_f3_6 + temp_f0_14);
                                    temp_f9_2 = (*(f32 *)(localFrame + (0xfc - 0x10))) * temp_f11;
                                    temp_f5_4 = (*(f32 *)(localFrame + (0xf0 - 0x10))) * temp_f10;
                                    temp_f8_3 = (*(f32 *)(localFrame + (0xfc - 0x10))) * temp_f10;
                                    (*(f32 *)(localFrame + (0x220 - 0x10))) = lbl_80563D94 - (temp_f4_4 + temp_f0_14);
                                    temp_f6_7 = (*(f32 *)(localFrame + (0xf0 - 0x10))) * temp_f11;
                                    (*(f32 *)(localFrame + (0x22c - 0x10))) = temp_f8_2 - temp_f9;
                                    (*(f32 *)(localFrame + (0x228 - 0x10))) = temp_f5_4 + temp_f9_2;
                                    (*(f32 *)(localFrame + (0x21c - 0x10))) = temp_f6_7 - temp_f8_3;
                                    (*(f32 *)(localFrame + (0x214 - 0x10))) = temp_f6_7 + temp_f8_3;
                                    (*(f32 *)(localFrame + (0x218 - 0x10))) = temp_f5_4 - temp_f9_2;
                                    (*(f32 *)(localFrame + (0x224 - 0x10))) = temp_f8_2 + temp_f9;
                                    (*(f32 *)(localFrame + (0x230 - 0x10))) = lbl_80563D94 - (temp_f4_4 + temp_f3_6);
                                } else {
                                    (*(f32 *)(localFrame + (0x214 - 0x10))) = lbl_80563D78;
                                    (*(f32 *)(localFrame + (0x210 - 0x10))) = lbl_80563D94;
                                    (*(f32 *)(localFrame + (0x218 - 0x10))) = lbl_80563D78;
                                    (*(f32 *)(localFrame + (0x21c - 0x10))) = lbl_80563D78;
                                    (*(f32 *)(localFrame + (0x220 - 0x10))) = lbl_80563D94;
                                    (*(f32 *)(localFrame + (0x224 - 0x10))) = lbl_80563D78;
                                    (*(f32 *)(localFrame + (0x228 - 0x10))) = lbl_80563D78;
                                    (*(f32 *)(localFrame + (0x22c - 0x10))) = lbl_80563D78;
                                    (*(f32 *)(localFrame + (0x230 - 0x10))) = lbl_80563D94;
                                }
                                temp_f9_3 = (*(f32 *)((u8 *)(globalBase) + (0x48))) + (lbl_80563D9C * ((*(f32 *)((u8 *)(temp_r3_9) + (0x68))) - (*(f32 *)((u8 *)(globalBase) + (0x48)))));
                                (*(f32 *)((u8 *)(globalBase) + (0x30))) = (*(f32 *)(localFrame + (0xf0 - 0x10)));
                                temp_f5_5 = (*(f32 *)((u8 *)(globalBase) + (0x44))) + (lbl_80563D9C * ((*(f32 *)((u8 *)(temp_r3_9) + (0x64))) - (*(f32 *)((u8 *)(globalBase) + (0x44)))));
                                temp_f4_5 = (*(f32 *)((u8 *)(globalBase) + (0x40))) + (lbl_80563D9C * ((*(f32 *)((u8 *)(temp_r3_9) + (0x60))) - (*(f32 *)((u8 *)(globalBase) + (0x40)))));
                                (*(f32 *)(localFrame + (0x7c - 0x10))) = temp_f9_3;
                                (*(f32 *)(localFrame + (0x78 - 0x10))) = temp_f5_5;
                                (*(f32 *)(localFrame + (0x74 - 0x10))) = temp_f4_5;
                                (*(f32 *)(localFrame + (0x234 - 0x10))) = temp_f4_5;
                                (*(f32 *)(localFrame + (0x238 - 0x10))) = temp_f5_5;
                                (*(f32 *)(localFrame + (0x23c - 0x10))) = temp_f9_3;
                                (*(f32 *)((u8 *)(globalBase) + (0x34))) = (*(f32 *)(localFrame + (0xf4 - 0x10)));
                                (*(f32 *)((u8 *)(globalBase) + (0x38))) = (*(f32 *)(localFrame + (0xf8 - 0x10)));
                                (*(f32 *)((u8 *)(globalBase) + (0x3C))) = (*(f32 *)(localFrame + (0xfc - 0x10)));
                                (*(f32 *)((u8 *)(globalBase) + (0x40))) = temp_f4_5;
                                (*(f32 *)((u8 *)(globalBase) + (0x44))) = temp_f5_5;
                                (*(f32 *)((u8 *)(globalBase) + (0x48))) = temp_f9_3;
                            } else {
                                (*(f32 *)(localFrame + (0x210 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x3C)));
                                (*(f32 *)(localFrame + (0x214 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x40)));
                                (*(f32 *)(localFrame + (0x218 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x44)));
                                (*(f32 *)(localFrame + (0x21c - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x48)));
                                (*(f32 *)(localFrame + (0x220 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x4C)));
                                (*(f32 *)(localFrame + (0x224 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x50)));
                                (*(f32 *)(localFrame + (0x228 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x54)));
                                (*(f32 *)(localFrame + (0x22c - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x58)));
                                (*(f32 *)(localFrame + (0x230 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x5C)));
                                (*(f32 *)(localFrame + (0x234 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x60)));
                                (*(f32 *)(localFrame + (0x238 - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x64)));
                                (*(f32 *)(localFrame + (0x23c - 0x10))) = (*(f32 *)((u8 *)(temp_r3_9) + (0x68)));
                                (*(f32 *)((u8 *)(globalBase) + (0x30))) = (*(f32 *)(localFrame + (0x100 - 0x10)));
                                (*(f32 *)((u8 *)(globalBase) + (0x34))) = (*(f32 *)(localFrame + (0x104 - 0x10)));
                                (*(f32 *)((u8 *)(globalBase) + (0x38))) = (*(f32 *)(localFrame + (0x108 - 0x10)));
                                (*(f32 *)((u8 *)(globalBase) + (0x3C))) = (*(f32 *)(localFrame + (0x10c - 0x10)));
                                (*(f32 *)((u8 *)(globalBase) + (0x40))) = (f32) (*(f32 *)((u8 *)(temp_r3_9) + (0x60)));
                                (*(f32 *)((u8 *)(globalBase) + (0x44))) = (f32) (*(f32 *)((u8 *)(temp_r3_9) + (0x64)));
                                (*(f32 *)((u8 *)(globalBase) + (0x48))) = (f32) (*(f32 *)((u8 *)(temp_r3_9) + (0x68)));
                            }
                        } else {
                            (*(f32 *)(localFrame + (0x214 - 0x10))) = lbl_80563D78;
                            (*(f32 *)(localFrame + (0x210 - 0x10))) = lbl_80563D94;
                            (*(f32 *)(localFrame + (0x218 - 0x10))) = lbl_80563D78;
                            (*(f32 *)(localFrame + (0x21c - 0x10))) = lbl_80563D78;
                            (*(f32 *)(localFrame + (0x220 - 0x10))) = lbl_80563D94;
                            (*(f32 *)(localFrame + (0x224 - 0x10))) = lbl_80563D78;
                            (*(f32 *)(localFrame + (0x228 - 0x10))) = lbl_80563D78;
                            (*(f32 *)(localFrame + (0x22c - 0x10))) = lbl_80563D78;
                            (*(f32 *)(localFrame + (0x230 - 0x10))) = lbl_80563D94;
                            (*(f32 *)(localFrame + (0x234 - 0x10))) = lbl_80563D78;
                            (*(f32 *)(localFrame + (0x238 - 0x10))) = lbl_80563D78;
                            (*(f32 *)(localFrame + (0x23c - 0x10))) = lbl_80563D78;
                            (*(f32 *)((u8 *)(globalBase) + (0x30))) = (f32) lbl_80563D78;
                            (*(f32 *)((u8 *)(globalBase) + (0x34))) = (f32) lbl_80563D78;
                            (*(f32 *)((u8 *)(globalBase) + (0x38))) = (f32) lbl_80563D78;
                            (*(f32 *)((u8 *)(globalBase) + (0x3C))) = (f32) lbl_80563D94;
                            (*(f32 *)((u8 *)(globalBase) + (0x40))) = (f32) lbl_80563D78;
                            (*(f32 *)((u8 *)(globalBase) + (0x44))) = (f32) lbl_80563D78;
                            (*(f32 *)((u8 *)(globalBase) + (0x48))) = (f32) lbl_80563D78;
                        }
                        fn_801BFD34((f32 *)((u8 *)lbl_80499050 + 0x24), (f32 *)(globalBase + 0x24), &(*(f32 *)(localFrame + (0x210 - 0x10))));
                        fn_80015B20(lbl_80499050, globalBase, &(*(f32 *)(localFrame + (0x210 - 0x10))));
                        if ((s32)lbl_8055F4E4 & 1) {
                            var_f2_2 = (*(f32 *)((u8 *)(lbl_80499050) + (0x28)));
                            temp_f0_15 = lbl_80563D94 + fn_801E9DDC((f32 *)(globalBase + 0x4C), (*(f32 *)((u8 *)(lbl_80499050) + (0x24))), (*(f32 *)((u8 *)(lbl_80499050) + (0x2C))));
                            if (var_f2_2 > temp_f0_15) {

                            } else {
                                var_f2_2 = temp_f0_15;
                            }
                            (*(f32 *)((u8 *)(lbl_80499050) + (0x28))) = var_f2_2;
                        }
                        (*(s32 *)((u8 *)(globalBase) + (0x50))) = temp_r27;
                        return;
                    }
                    if (((s32) lbl_8055F4E0 == 3) && (arg0 != 0) && ((s32) lbl_8055F4F0 >= 0)) {
                        (*(s32 *)((u8 *)(globalBase) + (0x50))) = fn_8026A344(0);
                    }
                    break;
                }
            }
            break;
        }
    }
}
#pragma dont_inline off
extern u32 lbl_80499050[];
extern u32 lbl_8049A1C0[];
extern f32 lbl_8055F47C;
extern s32 lbl_8055F4F0;
extern f32 lbl_80563D94;
extern BOOL fn_8026BFF0(s32);
extern s32 fn_8026A344(s32);
extern void *fn_8017960C(s32);
extern void fn_801BFD34(void *, void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern void fn_8026E688(f32 *, f32 *, f32 *, f32 *);
#pragma dont_inline on
void fn_8026DAA8(void *arg0) {
    void *self = arg0;

    if (*(u8 *)((u8 *)self + 0x138) != 0 &&
        !fn_8026BFF0((s32)lbl_8055F4E0)) {
        u32 *p = (u32 *)((u8 *)self + 0x58);
        u32 *q = lbl_80499050;
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        q[4] = p[4];
        q[5] = p[5];
        q[6] = p[6];
        q[7] = p[7];
        q[8] = p[8];
        q[9] = p[9];
        q[10] = p[10];
        q[11] = p[11];
        lbl_8055F47C = *(f32 *)((u8 *)self + 0x194);
    }

    switch ((s32)lbl_8055F4E0) {
    case 3:
        if (lbl_8055F4F0 >= 0) {
            u32 local[12];
            f32 up[3];
            s32 id = fn_8026A344(0);
            u32 *source = (u32 *)((u8 *)fn_8017960C(lbl_8055F4F0) + 0x3C);
            f32 *other = (f32 *)((u8 *)fn_8017960C(id) + 0x60);
            f32 *target = (f32 *)&local[9];

            local[0] = source[0];
            local[1] = source[1];
            local[2] = source[2];
            local[3] = source[3];
            local[4] = source[4];
            local[5] = source[5];
            local[6] = source[6];
            local[7] = source[7];
            local[8] = source[8];
            local[9] = source[9];
            local[10] = source[10];
            local[11] = source[11];

            target[0] += ((f32 *)lbl_80499050)[9];
            target[1] += ((f32 *)lbl_80499050)[10];
            target[2] += ((f32 *)lbl_80499050)[11];

            up[0] = lbl_80563D78;
            up[1] = lbl_80563D94;
            up[2] = lbl_80563D78;
            fn_8026E688((f32 *)((u8 *)self + 0x58), target, other, up);
        } else {
            f32 *matrix = (f32 *)((u8 *)self + 0x58);
            matrix[0] = lbl_80563D94;
            matrix[1] = lbl_80563D78;
            matrix[2] = lbl_80563D78;
            matrix[3] = lbl_80563D78;
            matrix[4] = lbl_80563D94;
            matrix[5] = lbl_80563D78;
            matrix[6] = lbl_80563D78;
            matrix[7] = lbl_80563D78;
            matrix[8] = lbl_80563D94;
            matrix[9] = lbl_80563D78;
            matrix[10] = lbl_80563D78;
            matrix[11] = lbl_80563D78;
        }
        break;
    case 4: {
        s32 id = fn_8026A344(0);
        u8 *base = (u8 *)fn_8017960C(id) + 0x3C;
        fn_801BFD34((u8 *)self + 0x7C, (u8 *)lbl_80499050 + 0x24, base);
        fn_80015B20((u8 *)self + 0x58, lbl_80499050, base);
        break;
    }
    default: {
        u32 *q = lbl_80499050 - 1;
        u32 *matrix = (u32 *)((u8 *)self + 0x58);
        matrix[0] = *++q;
        matrix[1] = *++q;
        matrix[2] = *++q;
        matrix[3] = *++q;
        matrix[4] = *++q;
        matrix[5] = *++q;
        matrix[6] = *++q;
        matrix[7] = *++q;
        matrix[8] = *++q;
        matrix[9] = *++q;
        matrix[10] = *++q;
        matrix[11] = *++q;
        break;
    }
    }

    *(f32 *)((u8 *)self + 0xBC) = lbl_8055F47C;
    *(f32 *)((u8 *)self + 0x120) = lbl_80563D78;
    *(f32 *)((u8 *)self + 0x124) = lbl_80563D78;
    *(f32 *)((u8 *)self + 0x128) = lbl_80563D78;

    lbl_8049A1C0[0] = *(u32 *)((u8 *)self + 0x58);
    lbl_8049A1C0[1] = *(u32 *)((u8 *)self + 0x5C);
    lbl_8049A1C0[2] = *(u32 *)((u8 *)self + 0x60);
    lbl_8049A1C0[3] = *(u32 *)((u8 *)self + 0x64);
    lbl_8049A1C0[4] = *(u32 *)((u8 *)self + 0x68);
    lbl_8049A1C0[5] = *(u32 *)((u8 *)self + 0x6C);
    lbl_8049A1C0[6] = *(u32 *)((u8 *)self + 0x70);
    lbl_8049A1C0[7] = *(u32 *)((u8 *)self + 0x74);
    lbl_8049A1C0[8] = *(u32 *)((u8 *)self + 0x78);
    lbl_8049A1C0[9] = *(u32 *)((u8 *)self + 0x7C);
    lbl_8049A1C0[10] = *(u32 *)((u8 *)self + 0x80);
    lbl_8049A1C0[11] = *(u32 *)((u8 *)self + 0x84);
}
void* fn_8026DDD0(void) {
    return lbl_8055F4E0;
}

extern void fn_801E9DC4(void *);
extern char lbl_80346A70[];
extern f32 lbl_80563E18;
extern void fn_802E30C8(const char *, ...);
void fn_8026DDD8(s32 arg0) {
    if (arg0 == 3 || (s32)lbl_8055F4E0 == arg0) {
        s32 r23 = fn_8026A344(0);
        if (fn_8017960C(++lbl_8055F4F0) == 0) lbl_8055F4F0 = 0;
        if (lbl_8055F4F0 == r23) {
            if (fn_8017960C(++lbl_8055F4F0) == 0) lbl_8055F4F0 = 0;
        }
        fn_802E30C8(lbl_80346A70, lbl_8055F4F0, r23);
    }
    if ((s32)lbl_8055F4E0 != arg0) {
        if (arg0 == 2) {
            f32 *p;
            f32 *g = (f32 *)lbl_8049A168;
            g[9] = lbl_80563D78;
            g[10] = lbl_80563DA0;
            g[11] = lbl_80563E18;
            *(f32 *)lbl_8049A168 = lbl_80563D94;
            g[1] = lbl_80563D78;
            g[2] = lbl_80563D78;
            g[6] = lbl_80563D78 * lbl_80563D98;
            g[7] = lbl_80563DA0 * lbl_80563D98;
            g[8] = lbl_80563E18 * lbl_80563D98;
            PSVECNormalize(g + 6, g + 6);
            PSVECCrossProduct(g + 6, g, g + 3);
            *(s32 *)(lbl_8049A168 + 0x50) = fn_8026A344(0);
            p = (f32 *)((void *(*)(void))fn_8017960C)();
            if (p != 0) {
                f32 (*m)[3] = (f32 (*)[3])((char *)p + 0x3c);
                f32 t = m[0][0] + m[1][1];
                t = m[2][2] + t;
                if (t > lbl_80563D78) {
                    f32 s = (f32)fn_8002F234(lbl_80563D94 + t);
                    f32 inv = lbl_80563D9C / s;
                    g[15] = lbl_80563D9C * s;
                    g[12] = inv * (m[1][2] - m[2][1]);
                    g[13] = inv * (m[2][0] - m[0][2]);
                    g[14] = inv * (m[0][1] - m[1][0]);
                } else {
                    f32 *q = g + 12;
                    s32 i = 0, j, k;
                    f32 s, inv;
                    if (m[1][1] > m[0][0]) i = 1;
                    if (m[2][2] > m[i][i]) i = 2;
                    j = (i + 1) % 3;
                    k = (j + 1) % 3;
                    s = (f32)fn_8002F234(lbl_80563D94 + (m[i][i] - (m[j][j] + m[k][k])));
                    inv = lbl_80563D9C / s;
                    q[i] = lbl_80563D9C * s;
                    q[3] = inv * (m[j][k] - m[k][j]);
                    q[j] = inv * (m[i][j] + m[j][i]);
                    q[k] = inv * (m[i][k] + m[k][i]);
                }
                *(f32 *)(lbl_8049A168 + 0x40) = p[24];
                *(f32 *)(lbl_8049A168 + 0x44) = p[25];
                *(f32 *)(lbl_8049A168 + 0x48) = p[26];
            } else {
                g[12] = lbl_80563D78;
                g[13] = lbl_80563D78;
                g[14] = lbl_80563D78;
                g[15] = lbl_80563D94;
                g[16] = lbl_80563D78;
                g[17] = lbl_80563D78;
                g[18] = lbl_80563D78;
            }
        } else if (fn_8026BFF0(arg0) != 0 && fn_8026BFF0((s32)lbl_8055F4E0) == 0) {
            f32 *q = (f32 *)lbl_80499050;
            q[0] = lbl_80563D94;
            q[1] = lbl_80563D78;
            q[2] = lbl_80563D78;
            q[3] = lbl_80563D78;
            q[4] = lbl_80563D94;
            q[5] = lbl_80563D78;
            q[6] = lbl_80563D78;
            q[7] = lbl_80563D78;
            q[8] = lbl_80563D94;
            q[9] = lbl_80563D78;
            q[10] = lbl_80563D78;
            q[11] = lbl_80563D78;
        } else if (fn_8026BFF0(arg0) == 0 && fn_8026BFF0((s32)lbl_8055F4E0) != 0) {
            void *p;
            fn_8026A344(0);
            p = ((void *(*)(void))fn_8017960C)();
            if (p != 0) {
                *(Words12 *)lbl_80499050 = *(Words12 *)((char *)p + 0x3c);
            }
        }
        lbl_8055F4E0 = (void *)arg0;
        fn_801E9DC4(lbl_8049A168 + 0x4c);
    }
}

void fn_8026E204(void* hi) {
    lbl_8055F4E4 = hi;
}

extern void *lbl_8055F4E4;
void* fn_8026E20C(void) {
    return lbl_8055F4E4;
}

void* fn_8026E214(void* value) {
    void* old = lbl_8055F4E8;
    lbl_8055F4E8 = value;
    return old;
}

extern void *lbl_8055F4E8;
extern f32 lbl_80563D78;
extern f32 lbl_80563D7C;
extern f32 lbl_80563D80;
extern f32 lbl_80563D84;

