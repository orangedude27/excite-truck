#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802B4E44(int);
extern float fn_80203FF0(void);
extern float fn_802C8FEC(void);
extern float fn_802C973C(void);
extern double fn_8002EF30(double);
extern double atan(double);
extern double sin(double);
extern double fabs(double);
extern void *fn_802BE844();
extern void fn_802AFE64(int *, short, short, short, short, int, int, int, float, int);
extern void fn_802AFEA4(int *, short);
extern int fn_802AFEC0(int);
extern int fn_802AFF54(void *);
extern int fn_802AFF5C(int *, int);
extern void fn_802AFF6C(void *);
extern void fn_802AFF80(void *, short);
extern void fn_802B0024(void *, short);
extern unsigned short fn_802B0070(int);
extern void fn_802B009C(void *, int, int, int);
extern void fn_802B0114(void);
extern s32 fn_802B0118(void *);
extern s32 fn_802B0124(void *);
extern s32 fn_802B0130(void *);
extern float fn_801DCF48(int, float, float);
extern void fn_802DBE4C(void);
extern void fn_802BDD58(void);
extern void fn_802DBECC(void);
extern void fn_802B2D94(int);
extern void fn_802B4E30(void);
extern char lbl_8055F980;
extern char lbl_8055F984[4];
extern int lbl_8055F988;
extern float lbl_80564B38;
extern int lbl_804BDFF0[8];
extern int lbl_8055CD7C;
extern int fn_8012850C(int, void *);
extern double fn_8002F234(float, float, float);
extern void *lbl_8055CD78;
extern void fn_80128668(void*);
extern char lbl_8055F981;
extern int lbl_8055F97C;
extern float lbl_80564AF0;
extern float lbl_80564B6C;
extern float lbl_80564B84;
extern float lbl_80564BB0;
extern float fn_801EA0E8(float, float);
extern unsigned int fn_802BBD38(short, short, float);
  extern char lbl_8034A020[];
extern float lbl_804BE090[];
extern float lbl_80564B40;
extern float lbl_80564B44;
extern float lbl_80564B68;
extern float lbl_80564B48;
extern float lbl_80564B4C;
extern float lbl_80564B50;
extern float lbl_80564B54;
extern float lbl_80564B58;
extern float lbl_80564B5C;
extern float lbl_80564B60;
extern float lbl_80564B64;
extern float lbl_80564B6C;
extern double lbl_80564B70;
extern unsigned char fn_8012C33C(void *);
struct ETConfigName {
    char text[0xC];
};
struct ETConfigPaths {
    struct ETConfigName name;
    char lookupKey[0xC];
    char statusKey[8];
};
extern void fn_802BE7F8(void);
extern void fn_802B40F8(void);
extern void fn_802B0914(void);
extern void fn_802C26F0(void);
extern void fn_802B1E28(void);
extern void fn_802B57B8(void);
extern void fn_802BBBC8(void);
extern void fn_802C2138(void);
extern void fn_802B9B68(void);
extern void fn_802BDBA8(void);
extern void fn_802C2298(void);
extern void fn_802BF350(void);
extern void fn_802B58E0(void);
extern void *fn_802B59CC(void);
extern void fn_802BEAB0(void);
#pragma cplusplus on
class ETConfigAccess {
public:
    virtual void unused00() = 0;
    virtual void unused04() = 0;
    virtual void unused08() = 0;
    virtual void unused0C() = 0;
    virtual void unused10() = 0;
    virtual void unused14() = 0;
    virtual void *lookup(char *, int) = 0;
    virtual void unused24() = 0;
    virtual void unused28() = 0;
    virtual void unused2C() = 0;
    virtual char status(char *, int) = 0;
};
#pragma cplusplus reset
void* fn_802AE588(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_802AE5E0(int arg0) {
    register int *ptr = &lbl_804BDFF0[1];
    register int total = 0;
    register int i = 2;
loop:
    *ptr = total;
    total += (i + 1) * 4;
    i *= 2;
    ptr++;
    if (i <= arg0)
        goto loop;
    *(int *)lbl_8055F984 = fn_8012850C(total * 2, &lbl_8055CD7C);
}
#pragma scheduling on
extern void fn_802AE64C(void *);
extern void fn_802C9950(int);
extern void fn_802C9994(int);
extern void fn_802C10C4(void);
extern char fn_802B05E4(void);
extern void fn_802BF40C(void);
extern void fn_802C2410(void);
extern void fn_802BDC60(void);
extern void fn_802B9D08(void);
extern void fn_802C2A34(void);
extern void fn_802B5808(void);
extern void fn_802C217C(void);
extern void fn_802B1FD4(void);
extern void fn_802C2874(void);
extern void fn_802B0954(void);
extern void fn_802B4BDC(void);
extern void fn_802BBCC4(void);
extern void fn_802BE840(void);
extern void fn_802C10B8(void);
extern int fn_802E2C20();
extern void fn_802BEB70(void);
extern int fn_802E30C8(char *, char *, ...);
extern void fn_802AE774(void);
extern int lbl_8055F970;
extern char lbl_8034A048[];
extern char lbl_8034A064[];
void fn_802AE644(void) { fn_802AE64C(lbl_8055F984); }

void fn_802AE64C(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

void fn_802AE690(void *arg0) {
    float y = *(float *)((char *)arg0 + 0x18);
    int result;
    if (y * *(float *)((char *)arg0 + 0x20) > lbl_80564B38) {
        if (y > lbl_80564B38) result = 3;
        else result = 0;
        lbl_8055F988 = result;
        return;
    }
    if (y > lbl_80564B38) result = 1;
    else result = 2;
    lbl_8055F988 = result;
}

#pragma scheduling invalid_target
float fn_802AE6E0(void *arg0, void *arg1) {
    float y0 = *(volatile float *)((char *)arg0 + 8);
    float y1 = *(volatile float *)((char *)arg1 + 8);
    float x0 = *(volatile float *)arg0;
    float x1 = *(volatile float *)arg1;
    float dy = y0 - y1;
    float dx = x0 - x1;
    float dy2 = dy * dy;
    float dx2 = dx * dx;
    return (float)fn_8002F234(dx2 + dy2, dy, y0);
}

extern void fn_802C7A44(void);
extern float lbl_80564B3C;
extern void fn_802C9648(float);
extern void fn_80287A34(int);
extern void fn_802C967C(void);
extern void fn_802879E4(int);
extern void fn_801FA6B8(void);
extern void fn_802C7A50(void);
extern void fn_802C9904(void);
extern void fn_801FA738(void);
void fn_802AE728(void) {
    fn_802C7A44();
    fn_802C9648(lbl_80564B3C);
    fn_80287A34(0);
    fn_802C967C();
    fn_802879E4(0);
    fn_801FA6B8();
    fn_802C7A50();
    fn_802C9904();
    fn_801FA738();
}

#pragma scheduling on
void fn_802BA004(void);
void fn_802BA348(void);
void fn_802C29A0(void);
void fn_802BAE50(void);
#pragma scheduling invalid_target
void fn_802AE774(void) {
    fn_802BA004();
    if (((int (*)(void))fn_802B05E4)() != 0)
        return;
    fn_802BA348();
    fn_802C29A0();
    fn_802BAE50();
}
#pragma scheduling on
int fn_802AE7AC(void) {
    int val = *(int *)lbl_8055F984;
    unsigned int tmp = (unsigned int)(-val) | (unsigned int)val;
    return (int)(tmp >> 31);
}
#pragma dont_inline reset

void fn_802AE7C0(void) {
    fn_802C9950(0x555766);
    fn_802C9994(0xFFF5D9);
}

#pragma dont_inline on
#pragma cplusplus on
#pragma push
#pragma processor 750
extern "C" void fn_802AE7F4(void) {
    struct ETConfigName {
        char text[0xC];
    };
    struct ETConfigPaths {
        struct ETConfigName name;
        char lookupKey[0xC];
        char statusKey[8];
    };
    float values[8];
    float total;
    register ETConfigPaths *base = (ETConfigPaths *)lbl_8034A020;
    int i;

          lbl_8055F980 = fn_8012C33C((void *)(&base->name));
    fn_802AE5E0(0x400);
    fn_802BE7F8();
    fn_802B40F8();
    fn_802B0914();
    fn_802C26F0();
    fn_802B1E28();
    fn_802B57B8();
    fn_802BBBC8();
    fn_802C2138();
    fn_802B9B68();
    fn_802BDBA8();
    fn_802C2298();
    if ((unsigned char)lbl_8055F980 == 0)
        fn_802BF350();
    fn_802B58E0();

    {
        ETConfigAccess *obj = (ETConfigAccess *)fn_802B59CC();
        lbl_8055CD78 = obj->lookup(base->lookupKey, -1);
    }
    {
        ETConfigAccess *obj = (ETConfigAccess *)fn_802B59CC();
        lbl_8055F981 = obj->status(base->statusKey, 0);
    }

    values[0] = lbl_80564B40 * (lbl_80564B44 * lbl_80564AF0);
    total = values[0];
    values[1] = lbl_80564B48 * (lbl_80564B48 * lbl_80564AF0);
    values[2] = lbl_80564B48 * (lbl_80564B4C * lbl_80564AF0);
    values[3] = lbl_80564B40 * (lbl_80564B50 * lbl_80564AF0);
    values[4] = lbl_80564B48 * (lbl_80564B54 * lbl_80564AF0);
    values[5] = lbl_80564B58 * (lbl_80564B5C * lbl_80564AF0);
    values[6] = lbl_80564B44 * (lbl_80564B60 * lbl_80564AF0);
    values[7] = lbl_80564B64 * lbl_80564AF0;
    {
        int step = 2;
        float *dst = &lbl_804BE090[1];
        float *val = &values[1];
        for (i = 0; i < 7; i++) {
            float v = *val;
            float next = (lbl_80564B68 * (lbl_80564B6C * lbl_80564AF0)) *
                         (float)((step << 1) + step);
            *dst = total;
            total += (next > v) ? next : v;
            step *= 2;
            dst++;
            val++;
        }
    }
    fn_802BEAB0();
    lbl_8055F97C = 0xFA;
}
#pragma pop
#pragma cplusplus reset

#pragma scheduling invalid_target
void fn_802AE9D0(void) {
    lbl_8055CD78 = (void *)-1;
    fn_802C10C4();
    if (((int (*)(void))fn_802B05E4)() != 0)
        goto done;
    fn_802BF40C();
    fn_802C2410();
    fn_802BDC60();
    fn_802B9D08();
    fn_802C2A34();
    fn_802B5808();
    fn_802C217C();
    fn_802B1FD4();
    fn_802C2874();
    fn_802B0954();
    fn_802B4BDC();
    fn_802BBCC4();
    fn_802BE840();
    ((void (*)(void))fn_802AE644)();
done:
    lbl_8055F970 = 0;
}
#pragma scheduling on
void fn_802AEA44(void) {
    volatile int start;
    volatile char *buffer;
    fn_802C10B8();
    buffer = lbl_8034A048;
    start = fn_802E2C20((char *)buffer);
    fn_802BEB70();
    if (fn_802E2C20() - start > 0x1F4) {
        fn_802E30C8(lbl_8034A064, (char *)buffer);
    }
    fn_802AE774();
}

extern void fn_802BDC3C(void);
extern void fn_802B59A4(int);
extern void fn_802B0288();
extern void fn_802BB674(int, int);
extern void fn_802C10CC(int);
extern int lbl_8055F974;
extern int lbl_8055F978;
void fn_802AEAA8(void) { fn_802BDC3C(); }

#pragma dont_inline fn_802AEAAC
void fn_802AEAAC(void) {
    int offset, i;
    if (lbl_8055F970 == 0) {
        fn_802B59A4(0);
        fn_802B0288();
    }
    i = 0;
    offset = 0;
    lbl_8055F974 = *(int *)(lbl_8055F970 + 4);
    lbl_8055F978 = *(int *)(lbl_8055F970 + 8);
    do {
        fn_802BB674(*(int *)((char *)lbl_8055F970 + offset + 0xC), i);
        i++;
        if (i >= 4) break;
        offset += 8;
    } while (1);
    fn_802C10CC(*(int *)(lbl_8055F970 + 0x2C));
}

extern char lbl_804BD8E8[];
extern float lbl_8055F98C;
extern u16 lbl_80564AF8;
extern u16 lbl_80564AFA;
extern u16 lbl_80564AFC;
extern u16 lbl_80564AFE;
extern u16 lbl_80564B00;
extern u16 lbl_80564B02;
extern u16 lbl_80564B04;
extern u16 lbl_80564B06;
extern u16 lbl_80564B08;
extern u16 lbl_80564B0A;
extern u16 lbl_80564B0C;
extern u16 lbl_80564B0E;
extern u16 lbl_80564B10;
extern u16 lbl_80564B12;
extern u16 lbl_80564B14;
extern u16 lbl_80564B16;
extern u16 lbl_80564B18;
extern u16 lbl_80564B1A;
extern u16 lbl_80564B1C;
extern u16 lbl_80564B1E;
extern u16 lbl_80564B20;
extern u16 lbl_80564B22;
extern u16 lbl_80564B24;
extern u16 lbl_80564B26;
extern u16 lbl_80564B28;
extern u16 lbl_80564B2A;
extern u16 lbl_80564B2C;
extern u16 lbl_80564B2E;
extern u16 lbl_80564B30;
extern u16 lbl_80564B32;
extern u16 lbl_80564B34;
extern u16 lbl_80564B36;
extern float lbl_80564B44;
extern float lbl_80564B68;
extern float lbl_80564B78;
extern float lbl_80564B7C;
extern float lbl_80564B80;
extern float lbl_80564B88;
extern float lbl_80564B8C;
extern float lbl_80564B90;
extern float lbl_80564B94;
extern float lbl_80564B98;
extern float lbl_80564B9C;
extern float lbl_80564BA0;
#pragma scheduling on
#pragma dont_inline on
void fn_802AEB3C(volatile u8 *arg0) {
    s16 sp148;
    u8 *sp144;
    u8 *sp140;
    s32 sp120;
    s32 sp114;
    s32 sp108;
    s32 spFC;
    s32 spF0;
    u16 *spEC;
    u16 *spE8;
    u16 *spE4;
    u16 *spE0;
    f32 spDC;
    s16 spDA;
    s16 spD8;
    s16 spD6;
    s16 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    s32 spB0;
    s32 spA4;
    s32 sp98;
    s32 sp8C;
    s32 sp80;
    s32 sp74;
    s32 sp68;
    u16 sp66;
    u16 sp64;
    u16 sp62;
    u16 sp60;
    u16 sp5E;
    u16 sp5C;
    u16 sp5A;
    u16 sp58;
    u16 sp56;
    u16 sp54;
    u16 sp52;
    u16 sp50;
    u16 sp4E;
    u16 sp4C;
    u16 sp4A;
    u16 sp48;
    u16 sp46;
    u16 sp44;
    u16 sp42;
    u16 sp40;
    u16 sp3E;
    u16 sp3C;
    u16 sp3A;
    u16 sp38;
    u16 sp36;
    u16 sp34;
    u16 sp32;
    u16 sp30;
    u16 sp2E;
    u16 sp2C;
    u16 sp2A;
    u16 sp28;
    s32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    u16 *sp8;
    s32 *var_r20;
    s32 *var_r21;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f18;
    f32 temp_f18_2;
    f32 temp_f19;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f31;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f4;
    s32 temp_r4;
    s32 temp_r5;
    f32 var_f0;
    register f32 var_f17;
    f32 var_f17_2;
    register f32 var_f18;
    f32 var_f18_2;
    f32 var_f1;
    s16 temp_r0_2;
    s16 temp_r10_2;
    s16 temp_r14_10;
    s16 temp_r14_3;
    s16 temp_r14_5;
    s16 temp_r14_7;
    s16 temp_r14_8;
    s16 temp_r14_9;
    s16 temp_r21;
    s16 temp_r21_2;
    s16 temp_r21_3;
    s16 temp_r22;
    s16 temp_r22_2;
    s16 temp_r23;
    s16 temp_r24;
    s16 temp_r25;
    s16 temp_r25_2;
    s16 temp_r25_3;
    s16 temp_r27;
    s16 temp_r27_2;
    s16 temp_r30;
    s16 temp_r3_6;
    s16 temp_r3_7;
    s16 temp_r4_10;
    s16 temp_r4_5;
    s16 temp_r4_6;
    s16 temp_r4_7;
    s16 temp_r4_8;
    s16 temp_r4_9;
    s16 temp_r5_4;
    s16 temp_r5_5;
    s16 temp_r5_6;
    s16 temp_r6_4;
    s16 temp_r7_3;
    s16 temp_r7_4;
    s16 temp_r8_2;
    s16 temp_r9_2;
    s16 var_r0_4;
    s16 var_r14;
    s32 temp_r0;
    s32 temp_r10;
    s32 input0;
    s32 input4;
    s32 input8;
    s32 inputC;
    s32 input2C;
    s32 temp_r14_2;
    s32 temp_r14_4;
    s32 temp_r14_6;
    s32 temp_r15;
    s32 temp_r16;
    s32 temp_r31;
    s32 temp_r3_4;
    s32 temp_r3_8;
    s32 temp_r4_14;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r5_2;
    s32 temp_r5_8;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r6_6;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r9;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r15_3;
    s32 var_r25_2;
    s32 var_r27;
    s32 var_r28;
    u16 *temp_r16_2;
    u16 *temp_r17_2;
    u16 *temp_r18;
    u16 *temp_r19;
    u16 *temp_r3_12;
    u16 *temp_r4_13;
    u16 *temp_r5_7;
    u16 *temp_r6_5;
    u16 *temp_r7_5;
    u16 *var_r15;
    u16 *var_r15_2;
    u16 *var_r16;
    u16 *var_r17;
    u16 *var_r18;
    u16 *var_r19;
    u16 *var_r22;
    u16 *var_r23;
    u16 *var_r24;
    u16 *var_r25;
    u16 temp_r4_11;
    u16 temp_r4_12;
    u16 var_r0_5;
    u16 var_r0_6;
    u16 var_r4;
    register u8 *temp_r14;
    u8 *temp_r17;
    register u8 *temp_r26;
    u8 *temp_r3;
    u8 *temp_r3_10;
    u8 *temp_r3_11;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_5;
    u8 *temp_r3_9;
    u8 *temp_r4_4;
    u8 *temp_r5_3;
    u8 *temp_r6_3;
    u8 *temp_r7_2;

    u8 *workspace = (u8 *)lbl_804BD8E8;
    fn_802AEAAC();
    fn_802B11BC(lbl_8055F974);
    fn_802B2D24(lbl_8055F978);
    temp_r14 = workspace + 0x7C8;
    input0 = *(volatile s32 *)arg0;
    input4 = *(volatile s32 *)((volatile u8 *)arg0 + 4);
    input8 = *(volatile s32 *)((volatile u8 *)arg0 + 8);
    inputC = *(volatile s32 *)((volatile u8 *)arg0 + 0xC);
    input2C = *(volatile s32 *)((volatile u8 *)arg0 + 0x2C);
    temp_r10 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x10));
    temp_r9 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x14));
    temp_r8 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x18));
    temp_r7 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x1C));
    temp_r6 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x20));
    temp_r5 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x24));
    temp_r4 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x28));
    *(volatile s32 *)((u8 *)(workspace) + (0x7C8)) = input0;
    *(volatile s32 *)((u8 *)(temp_r14) + (4)) = input4;
    *(volatile s32 *)((u8 *)(temp_r14) + (8)) = input8;
    *(volatile s32 *)((u8 *)(temp_r14) + (0xC)) = inputC;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x10)) = temp_r10;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x14)) = temp_r9;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x18)) = temp_r8;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x1C)) = temp_r7;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x20)) = temp_r6;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x24)) = temp_r5;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x28)) = temp_r4;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x2C)) = input2C;
    fn_802AE690(temp_r14);
    var_f17 = lbl_80564B38;
    temp_f0 = (lbl_80564B78 + *(f32 *)((u8 *)(temp_r14) + (0x28))) - fn_801EA0E8(*(f32 *)((u8 *)(temp_r14) + (0x24)), *(f32 *)((u8 *)(temp_r14) + (0x2C)));
    if (var_f17 <= temp_f0) {
        var_f17 = temp_f0;
    }
    lbl_8055F98C = fn_80203FF0() + var_f17;
    temp_f18 = fn_802C8FEC();
    temp_f1 = fn_802C973C();
    temp_f2 = (f32) atan((f32) fn_8002EF30(temp_f1 * lbl_80564B6C) / temp_f18);
    temp_f18_2 = lbl_80564B44 * temp_f2;
    temp_f3 = (f32) fn_8002EF30(temp_f1 * lbl_80564B6C);
    temp_r3 = workspace + 0x7C8;
    *(f32 *)((u8 *)(temp_r3) + (0x30)) = temp_f3;
    temp_r3_2 = workspace + 0x7C8;
    temp_f2_2 = lbl_80564B80 / (f32) sin(lbl_80564B7C - (temp_f1 * lbl_80564B6C));
    *(f32 *)((u8 *)(temp_r3_2) + (0x34)) = temp_f2_2;
    temp_f3_2 = (f32) fn_8002EF30(temp_f18_2 * lbl_80564B6C);
    temp_r3_3 = workspace + 0x7C8;
    *(f32 *)((u8 *)(temp_r3_3) + (0x38)) = temp_f3_2;
    temp_f1_2 = (f32) sin(lbl_80564B7C - (temp_f18_2 * lbl_80564B6C));
    temp_r7_2 = workspace + 0x7C8;
    *(f32 *)((u8 *)(temp_r7_2) + (0x3C)) = (f32) (lbl_80564B80 / temp_f1_2);
    fn_802C98DC(&sp1C, workspace + 0x7C8 + 0x40, workspace + 0x7C8 + 0x44, &sp1C, temp_r7_2, temp_f1_2);
    sp18 = lbl_80564B84;
    temp_r6_2 = (*(u32 *)&(sp18) >> 0x17U) & 0x7F;
    temp_r14_2 = *(s32 *)lbl_8055F984 + (*(s32 *)(workspace + 0x708 + ((temp_r6_2 + 1) * 4)) * 2);
    memset((u8 *)temp_r14_2, -1, 0x2008);
    temp_f22 = lbl_80564B80;
    temp_r3_4 = *(s32 *)((u8 *)(workspace) + (0)) * 0x1C;
    temp_f27 = lbl_80564B38;
    temp_f31 = lbl_80564AF0;
    *(s32 *)((u8 *)(workspace) + (0)) = (s32) (*(s32 *)((u8 *)(workspace) + (0)) + 1);
    temp_r6_3 = workspace + temp_r3_4;
    *(s16 *)((u8 *)(temp_r6_3) + (4)) = 0;
    temp_f24 = lbl_80564B8C;
    *(s16 *)((u8 *)(temp_r6_3) + (6)) = 0;
    temp_f25 = lbl_80564B90;
    *(s16 *)((u8 *)(temp_r6_3) + (8)) = 0x400;
    temp_f19 = lbl_80564B94;
    *(s16 *)((u8 *)(temp_r6_3) + (0xA)) = 0;
    temp_f20 = lbl_80564B98;
    *(f32 *)((u8 *)(temp_r6_3) + (0xC)) = temp_f22;
    temp_f28 = lbl_80564B6C;
    *(s32 *)((u8 *)(temp_r6_3) + (0x10)) = temp_r14_2;
    temp_f29 = lbl_80564B68;
    *(s32 *)((u8 *)(temp_r6_3) + (0x14)) = (s32) (temp_r14_2 + 0x802);
    *(s32 *)((u8 *)(temp_r6_3) + (0x18)) = (s32) (temp_r14_2 + 0x1806);
    sp140 = NULL;
    *(s32 *)((u8 *)(temp_r6_3) + (0x1C)) = (s32) (temp_r14_2 + 0x1004);
    do {
        temp_r0 = *(s32 *)((u8 *)(workspace) + (0)) - 1;
        *(s32 *)((u8 *)(workspace) + (0)) = temp_r0;
        temp_r3_5 = workspace + (temp_r0 * 0x1C);
        temp_r26 = temp_r3_5 + 4;
        temp_r3_6 = *(s16 *)((u8 *)(temp_r3_5) + (8));
        if (temp_r3_6 >= 0) {
            temp_r5_2 = (s32) (((u32) temp_r3_6 >> 0x1FU) + temp_r3_6) >> 1;
            if ((temp_r5_2 >= 4) && (temp_r5_2 <= 0x40)) {
                sp140 = fn_802BE844(*(s16 *)((u8 *)temp_r3_5 + 4), *(s16 *)((u8 *)temp_r26 + 2));
            }
            temp_r3_7 = *(s16 *)((u8 *)(temp_r26) + (4));
            var_f17_2 = lbl_80564B38;
            temp_r4_2 = ((u32) temp_r3_7 >> 0x1FU) + temp_r3_7;
            temp_r3_8 = temp_r4_2 >> 1;
            if (temp_r3_8 > 0x40) {
                temp_f1_3 = (f32) *(s16 *)((u8 *)(temp_r3_5) + (4)) * temp_f31;
                temp_f2_3 = (f32) *(s16 *)((u8 *)(temp_r26) + (2)) * temp_f31;
                spC8 = temp_f1_3;
                spD0 = temp_f2_3;
                spCC = fn_801DCF48(0, temp_f1_3, temp_f2_3);
                var_f18 = lbl_80564B88;
            } else {
                temp_r4_3 = temp_r4_2 >> 1;
                spC8 = (f32) *(s16 *)((u8 *)(temp_r3_5) + (4)) * temp_f31;
                spD0 = (f32) *(s16 *)((u8 *)(temp_r26) + (2)) * temp_f31;
                spCC = temp_f24 + (f32) (((u32) *(u32 *)((u8 *)(sp140) + (8)) >> 0xEU) & 0x1FF);
                var_f18 = (f32) ((((u32) *(u32 *)((u8 *)(sp140) + (8)) >> 0xAU) & 0xF) + 1) * temp_f25;
                if (temp_r4_3 < 4) {
                    var_f18 *= (f32) (4 / temp_r4_3);
                }
            }
            temp_r4_4 = workspace + 0x7C8;
            temp_r5_3 = workspace + 0x7C8;
            temp_f4 = spC8 - *(f32 *)((u8 *)(temp_r4_4) + (0x24));
            temp_f2_4 = spCC - *(f32 *)((u8 *)(temp_r5_3) + (0x28));
            spBC = temp_f4;
            spC0 = temp_f2_4;
            spC4 = spD0 - *(f32 *)((u8 *)(temp_r5_3) + (0x2C));
            temp_f1_4 = PSVECDotProduct(&spBC, temp_r4_4 + 0x18, temp_r5_3, spD0, temp_f2_4, spCC, temp_f4);
            temp_f3_3 = temp_f31 * (f32) temp_r3_8 * var_f18;
            temp_r3_9 = workspace + 0x7C8;
            if (((temp_f1_4 + temp_f3_3) < *(f32 *)((u8 *)(temp_r3_9) + (0x40))) || ((temp_f1_4 - temp_f3_3) > *(f32 *)((u8 *)(temp_r3_9) + (0x44)))) {
                var_r0 = 0;
            } else {
                temp_f2_5 = (f32) fabs(PSVECDotProduct(&spBC, temp_r3_9));
                temp_f3 = temp_f1_4 * *(f32 *)((u8 *)((workspace + 0x7C8)) + (0x30));
                if (temp_f27 > temp_f3) temp_f3 = temp_f27;
                temp_f0 = temp_f3 + ((temp_f20 + temp_f21 * var_f18) * *(f32 *)((u8 *)((workspace + 0x7C8)) + (0x34)));
                var_r0 = (temp_f2_5 <= temp_f0);
                if (var_r0 != 0) {
                    temp_f2_6 = (f32) fabs(PSVECDotProduct(&spBC, workspace + 0x7C8 + 0xC));
                    temp_f3 = temp_f1_4 * *(f32 *)((u8 *)((workspace + 0x7C8)) + (0x38));
                    if (temp_f27 > temp_f3) temp_f3 = temp_f27;
                    temp_f0 = temp_f3 + ((temp_f19 + temp_f21 * var_f18) * *(f32 *)((u8 *)((workspace + 0x7C8)) + (0x3C)));
                    var_r0 = (temp_f2_6 <= temp_f0);
                    if (var_r0 != 0) {
                        var_f17_2 = fn_802AE6E0(&spC8, workspace + 0x7C8 + 0x24);
                        var_r0 = 1;
                    } else {
                        goto block_22;
                    }
                } else {
block_22:
                    var_r0 = 0;
                }
            }
            if (var_r0 != 0) {
                temp_r4_5 = *(s16 *)((u8 *)(temp_r26) + (4));
                var_f18_2 = lbl_80564B9C;
                if (temp_r4_5 > 0x80) {
                    var_f18_2 = lbl_80564B80;
                    var_r0_2 = 0;
                } else {
                    var_f1 = lbl_8055F98C + (var_f17_2 - (temp_f29 * ((f32) temp_r4_5 * temp_f31 * temp_f28)));
                    if (temp_f27 > var_f1) {
                        var_f1 = temp_f27;
                    }
                    if (temp_r4_5 >= 2) {
                        sp14 = (f32) temp_r4_5;
                        var_r0_3 = ((*(u32 *)&(sp14) >> 0x17U) & 0x7F) + 1;
                    } else {
                        var_r0_3 = 0;
                    }
                    temp_r3_10 = workspace + 0x7A8 + (var_r0_3 * 4);
                    temp_f0_2 = *(f32 *)((u8 *)(temp_r3_10) + (-4));
                    var_r0_3 = (var_f1 >= temp_f0_2);
                    if (var_r0_3 == 0) {
                        var_f0 = (var_f1 - temp_f0_2) / (*(f32 *)((u8 *)(temp_r3_10) + (-8)) - temp_f0_2);
                        if (temp_f22 < var_f0) {
                            var_f0 = temp_f22;
                            if (var_f0 > temp_f27) {
                            } else {
                                var_f0 = temp_f27;
                            }
                            var_f18_2 = temp_f27 + (var_f0 * temp_f22);
                        }
                    }
                }
                if (var_r0_2 != 0) {
                    if (fn_802B12E0(lbl_8055F974, &sp20, sp140, fn_802B0130(temp_r26)) != 0) {
                        sp28 = lbl_80564AF8;
                        sp2A = lbl_80564AFA;
                        sp2C = lbl_80564AFC;
                        sp2E = lbl_80564AFE;
                        sp30 = lbl_80564B00;
                        sp32 = lbl_80564B02;
                        sp34 = lbl_80564B04;
                        sp36 = lbl_80564B06;
                        sp38 = lbl_80564B08;
                        sp3A = lbl_80564B0A;
                        sp3C = lbl_80564B0C;
                        sp3E = lbl_80564B0E;
                        sp40 = lbl_80564B10;
                        sp42 = lbl_80564B12;
                        sp44 = lbl_80564B14;
                        sp46 = lbl_80564B16;
                        sp48 = lbl_80564B18;
                        sp4A = lbl_80564B1A;
                        sp4C = lbl_80564B1C;
                        sp4E = lbl_80564B1E;
                        sp50 = lbl_80564B20;
                        sp52 = lbl_80564B22;
                        sp54 = lbl_80564B24;
                        sp56 = lbl_80564B26;
                        temp_r30 = fn_802B0130(temp_r26);
                        if (fn_802B0130(temp_r26) >= 4) {
                            fn_802BDFBC(sp140, fn_802B0130(temp_r26), *(f32 *)((u8 *)(temp_r26) + (8)));
                        }
                        sp10 = 0;
                        var_r27 = 0;
                        if (fn_802B0124(sp140) == 0) {
                            temp_r4_6 = *(s16 *)((u8 *)(temp_r3_5) + (4)) - temp_r30;
                            temp_r14_3 = *(s16 *)((u8 *)(temp_r26) + (2)) - temp_r30;
                            var_r27 = fn_802B4F10(&sp10, temp_r4_6, temp_r14_3, (s16) (temp_r30 * 2), fn_802B0118(sp140));
                        }
                        temp_f21 = fn_8014C8B4(lbl_80564B38, lbl_80564BA0, lbl_80564B38, lbl_80564B80, *(f32 *)((u8 *)(temp_r26) + (8)));
                        fn_802B0114();
                        fn_802B0114();
                        fn_802B0114();
                        fn_802B0114();
                        fn_802B0114();
                        temp_r14_4 = (s32) &sp120 & ((s32) (-var_r27 | var_r27) >> 0x1F);
                        fn_8001BA68(&sp68);
                        fn_802B009C(&sp68, 0, (int)*(s16 *)((u8 *)(temp_r3_5) + 4), (int)*(s16 *)((u8 *)(temp_r26) + 2));
                        if (temp_r14_4 != 0) {
                            fn_80144DAC(temp_r14_4, &sp68);
                        }
                        if (temp_f22 != temp_f21) {
                            fn_8001BA68(&sp74);
                            temp_r4_7 = *(s16 *)((u8 *)(temp_r26) + (6));
                            if (temp_r4_7 < 2) {
                                var_r0_4 = 0;
                            } else {
                                var_r0_4 = *(s16 *)((u8 *)(temp_r26) + (4));
                            }
                            if ((u16) *(u16 *)((u8 *)(*(s32 *)((u8 *)(temp_r26 + (temp_r4_7 * 4)) + 0xC)) + ((var_r0_4 * 2) & 0x1FFFE)) > -3U) {
                                sp58 = lbl_80564B28;
                                sp5A = lbl_80564B2A;
                                sp5C = lbl_80564B2C;
                                sp5E = lbl_80564B2E;
                                sp60 = lbl_80564B30;
                                sp62 = lbl_80564B32;
                                sp64 = lbl_80564B34;
                                sp66 = lbl_80564B36;
                                temp_r4_8 = *(s16 *)((u8 *)(temp_r26) + (6));
                                temp_r4_9 = (s16) (&sp58)[temp_r4_8];
                                temp_r14_5 = *(s16 *)((u8 *)(temp_r3_5) + (4)) + (temp_r4_9 * fn_802B0130(temp_r26));
                                temp_r6_4 = *(s16 *)((u8 *)(temp_r26) + (6));
                                fn_802B009C(&sp74, 0, temp_r14_5, (s16) (*(s16 *)((u8 *)(temp_r26) + (2)) + ((s16) (&sp60)[temp_r6_4] * fn_802B0130(temp_r26))));
                            } else {
                                fn_802B1BF0(lbl_8055F974, &sp74);
                            }
                            fn_8025AD3C(&sp80, &sp74, &sp68, temp_f21);
                            var_r0_5 = fn_802B0070((int)&sp80);
                        } else {
                            var_r0_5 = fn_802B0070((int)&sp68);
                        }
                        fn_802B0024(&sp20, var_r0_5);
                        var_r21 = &spF0;
                        sp144 = temp_r26;
                        var_r20 = var_r21;
                        var_r4 = **(u16 **)((u8 *)(temp_r26) + (0x18));
                        var_r23 = &sp30;
                        var_r22 = &sp28;
                        var_r19 = &sp38;
                        var_r18 = &sp40;
                        var_r17 = &sp50;
                        var_r16 = &sp48;
                        var_r28 = 0;
                        do {
                            var_r15 = *(u16 **)((u8 *)(sp144) + (0xC));
                            if (var_r28 < 2) {
                                var_r25 = var_r15;
                            } else {
                                var_r25 = var_r15 + (*(s16 *)((u8 *)(temp_r26) + (4)) * 2);
                            }
                            if (var_r28 >= 2) {
                                var_r24 = var_r15;
                            } else {
                                var_r24 = var_r15 + (*(s16 *)((u8 *)(temp_r26) + (4)) * 2);
                            }
                            temp_r5_4 = *(s16 *)((u8 *)(temp_r26) + (4));
                            temp_r31 = (((u32) temp_r5_4 >> 0x1FU) + temp_r5_4) & 0xFFFFFFFE;
                            if ((u16) *var_r25 == -1U) {
                                if (var_r4 < -3U) {
                                    *var_r25 = var_r4;
                                } else {
                                    temp_r5_5 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                                    *var_r25 = fn_802AFFA8((s16) (temp_r5_5 + (temp_r30 * (s16) *var_r22)), (s16) (*(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r23)), temp_r5_5);
                                }
                            }
                            if (var_r27 != 0) {
                                if ((u16) *var_r25 == -2U) {
                                    var_r27 = 0;
                                } else {
                                    fn_802B1BF0(lbl_8055F974, var_r21);
                                    temp_r7_3 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                                    temp_f1_5 = temp_f31 * (f32) (temp_r7_3 + (temp_r30 * (s16) *var_r22));
                                    *(f32 *)((u8 *)(var_r21) + (0)) = temp_f1_5;
                                    *(f32 *)((u8 *)(var_r21) + (8)) = (f32) (temp_f31 * (f32) (*(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r23)));
                                    fn_801C0E60(var_r21, var_r20, &sp120, temp_r30, temp_r7_3, temp_f1_5);
                                }
                            }
                            if ((u16) *(var_r15 + temp_r31) == -1U) {
                                temp_r0_2 = *(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r18);
                                temp_r4_10 = *(s16 *)((u8 *)(temp_r3_5) + (4)) + (temp_r30 * (s16) *var_r19);
                                sp148 = temp_r0_2;
                                if (temp_f22 == temp_f21) {
                                    *(var_r15 + temp_r31) = fn_802AFFA8(temp_r4_10, temp_r0_2);
                                } else {
                                    fn_8001BA68(&sp8C);
                                    if ((u16) *var_r25 > -3U) {
                                        fn_802B1BF0(lbl_8055F974, &sp8C);
                                    } else {
                                        temp_r7_4 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                                        fn_802B009C(&sp8C, 0, (s16) (temp_r7_4 + (temp_r30 * (s16) *var_r22)), (s16) (*(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r23)));
                                    }
                                    fn_8001BA68(&sp98);
                                    fn_802B009C(&sp98, 0, temp_r4_10, sp148);
                                    fn_8025AD3C(&spA4, &sp8C, &sp98, temp_f21);
                                    *(var_r15 + temp_r31) = fn_802B0070((int)&spA4);
                                }
                            }
                            if ((u16) *var_r24 == -1U) {
                                var_r0_6 = 0;
                                switch (var_r28) {  /* switch 1; irregular */
                                case 0:             /* switch 1 */
                                    var_r0_6 = **(u16 **)((u8 *)(temp_r26) + (0x10));
                                    break;
                                case 1:             /* switch 1 */
                                    var_r0_6 = *(*(u16 **)((u8 *)(temp_r26) + (0x14)) + (*(s16 *)((u8 *)(temp_r26) + (4)) * 2));
                                    break;
                                case 2:             /* switch 1 */
                                    var_r0_6 = *(*(u16 **)((u8 *)(temp_r26) + (0x18)) + (*(s16 *)((u8 *)(temp_r26) + (4)) * 2));
                                    break;
                                case 3:             /* switch 1 */
                                    var_r0_6 = **(u16 **)((u8 *)(temp_r26) + (0xC));
                                    break;
                                }
                                if (var_r0_6 < -3U) {
                                    *var_r24 = var_r0_6;
                                } else {
                                    temp_r5_6 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                                    *var_r24 = fn_802AFFA8((s16) (temp_r5_6 + (temp_r30 * (s16) *var_r16)), (s16) (*(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r17)), temp_r5_6);
                                }
                            }
                            if (var_r28 < 2) {
                                var_r25_2 = 0;
loop_99:
                                if (var_r25_2 < (s16) *(s16 *)((u8 *)(temp_r26) + (4))) {
                                    temp_r4_11 = *var_r15;
                                    if (temp_r4_11 == -1U) {
                                        *var_r15 = 0xFFFE;
                                    } else if (temp_r4_11 != -2U) {
                                        fn_802AFF80(&sp20, (short)temp_r4_11);
                                    }
                                    var_r15 += 2;
                                    var_r25_2 += 1;
                                    goto loop_99;
                                }
                            } else {
                                var_r14 = *(s16 *)((u8 *)(temp_r26) + (4));
                                var_r15_2 = var_r15 + (var_r14 * 2);
loop_107:
                                if (var_r14 > 0) {
                                    temp_r4_12 = *var_r15_2;
                                    if (temp_r4_12 == -1U) {
                                        *var_r15_2 = 0xFFFE;
                                    } else if (temp_r4_12 != -2U) {
                                        fn_802AFF80(&sp20, (short)temp_r4_12);
                                    }
                                    var_r15_2 -= 2;
                                    var_r14 -= 1;
                                    goto loop_107;
                                }
                            }
                            var_r28 += 1;
                            var_r4 = *var_r24;
                            sp144 += 4;
                            var_r23 += 2;
                            var_r22 += 2;
                            var_r21 += 0xC;
                            var_r20 += 0xC;
                            var_r19 += 2;
                            var_r18 += 2;
                            var_r17 += 2;
                            var_r16 += 2;
                        } while (var_r28 < 4);
                        fn_802AFF80(&sp20, 0);
                        fn_802AFF6C(&sp20);
                        fn_802B13F8(lbl_8055F974, sp140, &sp20, fn_802B0130(temp_r26), temp_f21);
                        if ((var_r27 != 0) && ((fn_802B0130(temp_r26) < 8) || ((fn_802B0130(temp_r26) == 8) && (*(f32 *)((u8 *)(temp_r26) + (8)) > temp_f28)))) {
                            temp_r16 = fn_802B0118(sp140) * 4;
                            var_r15_3 = 0;
loop_119:
                            if (var_r15_3 < fn_802AFF54((void *)var_r27)) {
                                temp_r3_11 = (u8 *)fn_802AFF5C((int *)var_r27, var_r15_3);
                                temp_r17 = temp_r16 + temp_r3_11;
                                if ((s32) *(s32 *)((u8 *)(temp_r17) + (0xC)) != 0) {
                                    fn_8001BA68(&spB0);
                                    fn_801C2B9C(&spB0, &sp120, &spF0 + (*(u16 *)((u8 *)(temp_r3_11) + (0xA)) * 0xC), *(f32 *)((u8 *)(temp_r3_11) + (0)));
                                    fn_801C2B9C(&spB0, &spB0, &spF0 + (((*(u16 *)((u8 *)(temp_r3_11) + (0xA)) + 1) & 3) * 0xC), *(f32 *)((u8 *)(temp_r3_11) + (4)));
                                    if (var_r15_3 < sp10) {
                                        fn_802B3E00(*(s32 *)((u8 *)(temp_r17) + (0xC)), &spB0, *(u16 *)((u8 *)(temp_r3_11) + (8)), lbl_80564B80);
                                    } else {
                                        fn_802B3E00(*(s32 *)((u8 *)(temp_r17) + (0xC)), &spB0, *(u16 *)((u8 *)(temp_r3_11) + (8)), temp_f21);
                                    }
                                }
                                var_r15_3 += 1;
                                goto loop_119;
                            }
                        }
                    }
                } else {
                    if ((s32) ((s32) (((u32) temp_r4_5 >> 0x1FU) + temp_r4_5) >> 1) == 4) {
                        fn_802BDFBC(sp140, *(s16 *)&(*(f32 *)((u8 *)(temp_r26) + (8))));
                    }
                    temp_r9_2 = *(s16 *)((u8 *)(temp_r26) + (4));
                    temp_r10_2 = *(s16 *)((u8 *)(temp_r26) + (2));
                    temp_r8_2 = *(s16 *)((u8 *)(temp_r26) + (6));
                    temp_r15 = (s32) (((u32) temp_r9_2 >> 0x1FU) + temp_r9_2) >> 1;
                    temp_r7_5 = *(u16 **)((u8 *)(temp_r26) + (0xC));
                    temp_r6_5 = *(u16 **)((u8 *)(temp_r26) + (0x10));
                    temp_r5_7 = *(u16 **)((u8 *)(temp_r26) + (0x14));
                    temp_r4_13 = *(u16 **)((u8 *)(temp_r26) + (0x18));
                    temp_r14_6 = (s32) (((u32) temp_r15 >> 0x1FU) + temp_r15) >> 1;
                    spD4 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                    spD6 = temp_r10_2;
                    spD8 = temp_r9_2;
                    spDA = temp_r8_2;
                    spDC = *(f32 *)((u8 *)(temp_r26) + (8));
                    spE0 = temp_r7_5;
                    spE4 = temp_r6_5;
                    spE8 = temp_r5_7;
                    spEC = temp_r4_13;
                    temp_r3_12 = (u16 *)fn_802AFEC0(temp_r15);
                    temp_r4_14 = temp_r15 + 1;
                    temp_r5_8 = temp_r4_14 * 4;
                    temp_r6_6 = temp_r4_14 * 2;
                    temp_r19 = temp_r3_12 + ((temp_r5_8 - temp_r4_14) * 2);
                    temp_r16_2 = temp_r3_12;
                    temp_r17_2 = temp_r3_12 + temp_r6_6;
                    temp_r18 = temp_r3_12 + temp_r5_8;
                    fn_802AFEA4((int *)&sp10, (s16) -temp_r15);
                    switch ((s32) lbl_8055F988) {   /* switch 2; irregular */
                    case 3:                         /* switch 2 */
                        temp_r25 = spD4 - temp_r14_6;
                        temp_r23 = spD6 - temp_r14_6;
                        sp8 = &spE8[temp_r15];
                        fn_802AFE64((int *)&sp10, temp_r25, temp_r23, temp_r15, 2, (int)(temp_r19), (int)(&spE4[temp_r15]), (int)(temp_r17_2), var_f18_2, (int)sp8);
                        temp_r27 = spD4 + temp_r14_6;
                        sp8 = spE8;
                        fn_802AFE64((int *)&sp10, temp_r27, temp_r23, temp_r15, 3, (int)(temp_r18), (int)(temp_r17_2), (int)(&spEC[temp_r15]), var_f18_2, (int)sp8);
                        temp_r14_7 = spD6 + temp_r14_6;
                        sp8 = temp_r19;
                        fn_802AFE64((int *)&sp10, temp_r25, temp_r14_7, temp_r15, 1, (int)(&spE0[temp_r15]), (int)(spE4), (int)(temp_r16_2), var_f18_2, (int)sp8);
                        sp8 = temp_r18;
                        fn_802AFE64((int *)&sp10, temp_r27, temp_r14_7, temp_r15, 0, (int)(spE0), (int)(temp_r16_2), (int)(spEC), var_f18_2, (int)sp8);
                        break;
                    case 2:                         /* switch 2 */
                        temp_r25_2 = spD6 - temp_r14_6;
                        sp8 = spE8;
                        temp_r22 = spD4 + temp_r14_6;
                        fn_802AFE64((int *)&sp10, temp_r22, temp_r25_2, temp_r15, 3, (int)(temp_r18), (int)(temp_r17_2), (int)(&spEC[temp_r15]), var_f18_2, (int)sp8);
                        temp_r21 = spD6 + temp_r14_6;
                        sp8 = temp_r18;
                        fn_802AFE64((int *)&sp10, temp_r22, temp_r21, temp_r15, 0, (int)(spE0), (int)(temp_r16_2), (int)(spEC), var_f18_2, (int)sp8);
                        temp_r14_8 = spD4 - temp_r14_6;
                        sp8 = &spE8[temp_r15];
                        fn_802AFE64((int *)&sp10, temp_r14_8, temp_r25_2, temp_r15, 2, (int)(temp_r19), (int)(&spE4[temp_r15]), (int)(temp_r17_2), var_f18_2, (int)sp8);
                        sp8 = temp_r19;
                        fn_802AFE64((int *)&sp10, temp_r14_8, temp_r21, temp_r15, 1, (int)(&spE0[temp_r15]), (int)(spE4), (int)(temp_r16_2), var_f18_2, (int)sp8);
                        break;
                    case 1:                         /* switch 2 */
                        temp_r24 = spD6 + temp_r14_6;
                        sp8 = temp_r19;
                        temp_r27_2 = spD4 - temp_r14_6;
                        fn_802AFE64((int *)&sp10, temp_r27_2, temp_r24, temp_r15, 1, (int)(&spE0[temp_r15]), (int)(spE4), (int)(temp_r16_2), var_f18_2, (int)sp8);
                        temp_r21_2 = spD4 + temp_r14_6;
                        sp8 = temp_r18;
                        fn_802AFE64((int *)&sp10, temp_r21_2, temp_r24, temp_r15, 0, (int)(spE0), (int)(temp_r16_2), (int)(spEC), var_f18_2, (int)sp8);
                        temp_r14_9 = spD6 - temp_r14_6;
                        sp8 = &spE8[temp_r15];
                        fn_802AFE64((int *)&sp10, temp_r27_2, temp_r14_9, temp_r15, 2, (int)(temp_r19), (int)(&spE4[temp_r15]), (int)(temp_r17_2), var_f18_2, (int)sp8);
                        sp8 = spE8;
                        fn_802AFE64((int *)&sp10, temp_r21_2, temp_r14_9, temp_r15, 3, (int)(temp_r18), (int)(temp_r17_2), (int)(&spEC[temp_r15]), var_f18_2, (int)sp8);
                        break;
                    case 0:                         /* switch 2 */
                        temp_r25_3 = spD6 + temp_r14_6;
                        sp8 = temp_r18;
                        temp_r22_2 = spD4 + temp_r14_6;
                        fn_802AFE64((int *)&sp10, temp_r22_2, temp_r25_3, temp_r15, 0, (int)(spE0), (int)(temp_r16_2), (int)(spEC), var_f18_2, (int)sp8);
                        temp_r21_3 = spD6 - temp_r14_6;
                        sp8 = spE8;
                        fn_802AFE64((int *)&sp10, temp_r22_2, temp_r21_3, temp_r15, 3, (int)(temp_r18), (int)(temp_r17_2), (int)(&spEC[temp_r15]), var_f18_2, (int)sp8);
                        temp_r14_10 = spD4 - temp_r14_6;
                        sp8 = temp_r19;
                        fn_802AFE64((int *)&sp10, temp_r14_10, temp_r25_3, temp_r15, 1, (int)(&spE0[temp_r15]), (int)(spE4), (int)(temp_r16_2), var_f18_2, (int)sp8);
                        sp8 = &spE8[temp_r15];
                        fn_802AFE64((int *)&sp10, temp_r14_10, temp_r21_3, temp_r15, 2, (int)(temp_r19), (int)(&spE4[temp_r15]), (int)(temp_r17_2), var_f18_2, (int)sp8);
                        break;
                    }
                }
            }
        }
    } while (*(s32 *)((u8 *)(workspace) + (0)) != 0);
}
#pragma scheduling on
#pragma dont_inline reset
void fn_802AFE64(int *arg0, short a, short b, short c, short d, int e, int f, int g, float h, int j) {
    int index = *arg0;
    char *p;
    *arg0 = index + 1;
    p = (char *)arg0 + index * 0x1C;
    *(short *)(p + 4) = a;
    *(short *)(p + 6) = b;
    *(short *)(p + 8) = c;
    *(short *)(p + 10) = d;
    *(float *)(p + 12) = h;
    *(int *)(p + 16) = e;
    *(int *)(p + 20) = f;
    *(int *)(p + 24) = j;
    *(int *)(p + 28) = g;
}

void fn_802AFEA4(int *arg0, short arg1) {
    int index = *arg0;
    *arg0 = index + 1;
    *(short *)((char *)arg0 + index * 0x1C + 8) = arg1;
}

int fn_802AFEC0(int arg0) {
    float converted;
    int index;
    int result;
    if (arg0 >= 2) {
        converted = (float)arg0;
        index = (((*(unsigned int *)&converted) >> 23) & 0x7F) + 1;
    } else {
        index = 0;
    }
    result = *(int *)lbl_8055F984 + lbl_804BDFF0[index] * 2;
    memset((void *)result, -1, (arg0 + 1) * 8);
    return result;
}

int fn_802AFF54(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_802AFF5C(int *arg0, int arg1) {
    return *arg0 + arg1 * 0x24;
}

void fn_802AFF6C(void *arg0) {
    *(unsigned short *)*(void **)arg0 = *(unsigned short *)((char *)arg0 + 4) - 1;
}

void fn_802AFF80(void *arg0, short arg1) {
    unsigned int index = *(unsigned short *)((char *)arg0 + 4);
    unsigned int limit = *(unsigned short *)((char *)arg0 + 6);
    if (index < limit) {
        short *data = *(short **)arg0;
        unsigned int offset = index << 1;
        index = index + 1;
        data[offset >> 1] = arg1;
        *(unsigned short *)((char *)arg0 + 4) = index;
    }
}

void fn_802B0024(void *arg0, short arg1) {
    unsigned short count = 0;
    unsigned short limit = *(unsigned short *)((char *)arg0 + 6);
    *(unsigned short *)((char *)arg0 + 4) = count;
    if (count >= limit) return;
    *(unsigned short *)*(void **)arg0 = count;
    count = 1;
    *(unsigned short *)((char *)arg0 + 4) = count;
    count = *(unsigned short *)((char *)arg0 + 4);
    limit = *(unsigned short *)((char *)arg0 + 6);
    if (count < limit) {
        *(short *)((char *)*(void **)arg0 + count * 2) = arg1;
        *(unsigned short *)((char *)arg0 + 4) = count + 1;
    }
}

extern int fn_802B127C(int, int);
extern float fn_801DCF48(int, float, float);
extern float lbl_80564AF0;
extern double lbl_80564B70;
unsigned short fn_802B0070(int arg0) {
    return fn_802B127C(lbl_8055F974, arg0);
}

#pragma scheduling invalid_target
void fn_802B009C(void *arg0, int arg1, int arg2, int arg3) {
    float *out = (float *)arg0;
    float x = (float)arg2 * lbl_80564AF0;
    float z = (float)arg3 * lbl_80564AF0;
    out[0] = x;
    out[2] = z;
    out[1] = fn_801DCF48(arg1, x, z);
}
#pragma scheduling on
void fn_802B0114(void) {
}

s32 fn_802B0118(void *arg0) {
    return (*(u32 *)((u8 *)arg0 + 8) >> 6) & 7;
}

s32 fn_802B0124(void *arg0) {
    return (*(u32 *)((u8 *)arg0 + 8) >> 23) & 1;
}

s32 fn_802B0130(void *arg0) {
    s16 value = *(s16 *)((u8 *)arg0 + 4);
    return (s32)(((u32)value >> 31) + value) >> 1;
}

extern int fn_801E8718(int);
extern void fn_802AEB3C();
void fn_802B0144(void) {
    fn_801E8718(-1);
    fn_802AEB3C();
}

void fn_802B016C(void) {
    fn_802DBE4C();
    fn_802B14B4(lbl_8055F974);
    fn_802BDD54();
    fn_802B2D94(lbl_8055F978);
    fn_802B4E30();
    fn_802DBECC();
}

#pragma dont_inline on
void fn_802B01A8(void) {
    long temp;
    long value;
    fn_802DBE4C();
    value = *(unsigned long *)((char *)fn_801E87A8() + 0x10);
    temp = 1;
    if ((value >> 1) & 1)
        temp = 2;
    temp = fn_802C9C58(temp);
    fn_802B14B4(lbl_8055F974);
    fn_802C9C58(temp);
    fn_802DBECC();
    fn_802AE728();
    fn_80202718();
    fn_8029790C(0);
    fn_802AE7C0();
}
#pragma dont_inline on
void fn_802B0218(void) {
    if (fn_802AE7AC() != 0) {
        fn_802DBE4C();
        fn_802B2D94(lbl_8055F978);
        fn_802B4E30();
        fn_802DBECC();
    }
}
#pragma dont_inline reset
void fn_802B0254(void) {
    if (fn_802AE7AC() != 0) {
        fn_802DBE4C();
        fn_802BDD58();
        fn_802DBECC();
    }
}
#pragma dont_inline reset
void fn_802B0288(void *arg0) {
    if ((void *)lbl_8055F970 != arg0)
        fn_802B4E44(*(int *)((char *)arg0 + 8));
    lbl_8055F970 = (int)arg0;
}

extern int fn_802AE7AC(void);
extern void *fn_802BE844();
extern float lbl_80564B6C;
extern float lbl_80564B84;
#pragma dont_inline on
extern int __cntlzw(unsigned int);
#pragma scheduling invalid_target
s32 fn_802B02C8(void *arg0) {
    f32 temp_f2_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f0_2;
    f32 temp_f2;
    s32 var_r0;
    s32 scaled_x;
    s32 scaled_z;
    s16 coord_x;
    s16 coord_z;
    u32 flags;

    if (fn_802AE7AC() != 0) {
        var_r0 = 0;
        temp_f2_2 = lbl_80564B84 * lbl_80564AF0;
        temp_f2_2 = temp_f2_2 * lbl_80564B6C;
        temp_f0 = *(f32 *)arg0;
        temp_f1 = -temp_f2_2;
        if ((temp_f0 > temp_f1) && (temp_f2_2 > temp_f0)) {
            temp_f0_2 = *(f32 *)((u8 *)arg0 + 8);
            if ((temp_f0_2 > temp_f1) && (temp_f2_2 > temp_f0_2))
                var_r0 = 1;
        }
        if (var_r0 != 0) {
            temp_f0 = *(f32 *)arg0;
            temp_f2 = temp_f0 / lbl_80564AF0;
            scaled_x = (s32)temp_f2;
            coord_x = (s16)((s16)(scaled_x & 0xFFFFFFF8) + 4);
            temp_f0_2 = *(f32 *)((u8 *)arg0 + 8);
            temp_f2 = temp_f0_2 / lbl_80564AF0;
            scaled_z = (s32)temp_f2;
            coord_z = (s16)((s16)(scaled_z & 0xFFFFFFF8) + 4);
            flags = *(u32 *)((u8 *)fn_802BE844(coord_x, coord_z, 4, temp_f0_2) + 8);
            return (u32)__cntlzw(flags & 0x01000000) >> 5;
        }
        return 1;
    }
    return 0;
}
#pragma scheduling on
s32 fn_802B03C0(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    s32 var_r0;
    s32 var_r31;
    u32 temp_r4;
    var_r31 = 0;
    if ((fn_802AE7AC() != 0) && (lbl_8055F970 != 0)) {
        var_r0 = 0;
        temp_f0 = *(f32 *)arg0;
        temp_f2 = lbl_80564B84 * lbl_80564AF0 * lbl_80564B6C;
        temp_f1 = -temp_f2;
        if ((temp_f0 > temp_f1) && (temp_f0 < temp_f2)) {
            temp_f0_2 = *(f32 *)((char *)arg0 + 8);
            if ((temp_f0_2 > temp_f1) && (temp_f0_2 < temp_f2))
                var_r0 = 1;
        }
        if (var_r0 != 0) {
            temp_f2_2 = *(f32 *)((char *)arg0 + 8);
            temp_r4 = *(u32 *)((char *)fn_802BE844(
                (s16)((s16)((s32)(*(f32 *)arg0 / lbl_80564AF0) & 0xFFFFFFF8) + 4),
                (s16)((s16)((s32)(temp_f2_2 / lbl_80564AF0) & 0xFFFFFFF8) + 4),
                4, temp_f2_2) + 8);
            var_r31 = fn_802B1C50(*(void **)((char *)lbl_8055F970 + 4),
                                  (temp_r4 >> 6) & 7,
                                  ((temp_r4 >> 24) & 1) ^ 1);
        }
    }
    return var_r31;
}
#pragma dont_inline reset
s32 fn_802B04D4(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f2;
    s32 var_r0;
    if ((u8)lbl_8055F981 != 0)
        return fn_801EA0E8(*(f32 *)arg0, *(f32 *)((char *)arg0 + 8)) < lbl_80564BB0;
    if ((s32)lbl_8055CD78 < 0)
        return 0;
    var_r0 = 0;
    temp_f2 = lbl_80564B84;
    temp_f0 = lbl_80564AF0;
    temp_f1 = lbl_80564B6C;
    temp_f2 = temp_f2 * temp_f0;
    temp_f0 = *(f32 *)arg0;
    temp_f2 = temp_f2 * temp_f1;
    temp_f1 = -temp_f2;
    if ((temp_f0 > temp_f1) && (temp_f0 < temp_f2)) {
        temp_f0_2 = *(f32 *)((char *)arg0 + 8);
        if ((temp_f0_2 > temp_f1) && (temp_f0_2 < temp_f2))
            var_r0 = 1;
    }
    if (var_r0 != 0) {
        temp_f1 = *(f32 *)arg0;
        temp_f2 = lbl_80564AF0;
        temp_f0 = *(f32 *)((char *)arg0 + 8);
        return (u8)lbl_8055F97C < fn_802BBD38((s16)(temp_f1 / temp_f2), (s16)(temp_f0 / temp_f2), lbl_80564AF0);
    }
    return 1;
}

extern void fn_802C10C8(void);
void fn_802B05D8(void) { fn_802C10C8(); }

void* fn_802B05DC(void) {
    return lbl_8055CD78;
}

char fn_802B05E4(void) {
    return lbl_8055F980;
}

extern char lbl_8055F981;
char fn_802B05EC(void) {
    return lbl_8055F981;
}

