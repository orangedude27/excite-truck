struct Rec78 { long tag; unsigned char b04, b05, b06, b07, b08, b09, b0a, b0b, b0c, b0d, b0e, b0f, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b1a, b1b, b1c, b1d, b1e, b1f, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b2a, b2b, b2c, b2d, b2e, b2f, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b3a, b3b, b3c, b3d, b3e, b3f, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b4a, b4b, b4c, b4d, b4e, b4f, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b5a, b5b, b5c, b5d, b5e, b5f, b60, b61, b62, b63; long a64, a68, a6c; unsigned char c70; long a74; };
struct Loc78 { struct Rec78 r; long idx; };
struct Ctx68 { long w0, w1; unsigned char pad[0x60]; };
extern char lbl_80339BA0[], lbl_8055AF14[4], lbl_8055AF18[4];
extern unsigned long lbl_80487CE0[];
extern char lbl_8055EB08, lbl_8055EB10, lbl_8055EB12, lbl_8055EB20;
extern float *lbl_8055EB04;
extern long lbl_8055EB0C;
extern void *lbl_8055EB30;
extern float lbl_80562DA4;
extern void *memcpy(void *, const void *, unsigned long);
extern long fn_802E2C20(void);
extern long *fn_8012850C(long, void *);
extern void fn_8001255C(const char *, float);
extern void fn_8000D878(void);
extern void fn_802E30C8(const char *, ...);
extern void fn_802ECC18(long);
extern void fn_801E89FC(void);
extern void fn_801E9564(long);
extern void fn_802E2C9C(void);
extern void fn_802A4CA8(void);
extern void fn_802C276C(void);
extern long fn_801E866C(long);
extern void fn_80203E88(void *, long, long);
extern void fn_8001A1F0(void);
extern void fn_801EA394(void);
extern void fn_802C87B4(long, long, long, long);
extern void fn_802CC73C(int);
extern void fn_801E83D4(void);
extern void fn_801E8410(void);
extern int fn_801B89F8(void);
extern void fn_801E88B4(long *, long *, long *, long *, long);
extern void fn_8020625C(void);
extern void fn_8029227C(void);
extern void fn_802A4D08(void);
extern int fn_80019B54(void);
extern void fn_802DB2A4(void);
extern void fn_802DD754(void);
extern void fn_802A4D00(void);
extern void fn_80287978(void);
extern long lbl_8055EB1C;
extern void *lbl_8055EB2C;
extern long lbl_8055CFF0, lbl_8055CFF4;
extern unsigned char lbl_80487D00[];
extern void *lbl_80488648[];
extern float lbl_80562DB4, lbl_80562DD0;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern long fn_800167F4(void);
extern void fn_801E96D8(long);
extern float fn_80129DC4(long, float, float);
extern void PSVECNormalize(float *, float *);
extern float lbl_80562DBC, lbl_80562DC0, lbl_80562DD4, lbl_80562DD8;
extern float lbl_80562DDC, lbl_80562DE0;
extern float lbl_802F99F8[4];
struct FourLongs { long w0, w1, w2, w3; };
extern long lbl_8055AF10;
extern void fn_802C6CF8(long);
extern void fn_80127464(void);
extern void fn_801E8D48(void);
extern void fn_801E8DD4(void);
extern void fn_801E8E38(void);
extern void fn_801E8F10(long);
extern int fn_802E317C(const char *, ...);
extern unsigned char lbl_80339CC0[];
extern char lbl_80339CFC[];
extern void *memset(void *, int, unsigned long);
extern float lbl_804881D8[];
extern void fn_80297984(void);
extern void fn_802889F0(void);
extern void fn_80287914(void);
extern void fn_801FA1D4(void);
extern void fn_802C1A08(void);
extern void *lbl_8055EB24;
extern float lbl_80562DBC;
extern float lbl_8055EB18;
extern float lbl_8055EB14;
extern int fn_801284F8(int, void *, void *, float, float, float, float, float, float);
extern void fn_801F19FC(void *);
extern float lbl_80562DA0, lbl_80562DF4, lbl_80562DF8, lbl_80562DFC;
extern float lbl_80562DA8, lbl_80562DB0;
extern char lbl_80339CB4[];
extern float lbl_80562E00, lbl_80562E04, lbl_80562E08;
extern unsigned char lbl_8055AF24;
extern void fn_80206464();
extern void fn_8020646C(long, long);
extern void fn_801E7984();
extern char lbl_8055EB11;
extern long lbl_80487CF0[];
extern unsigned char lbl_80487DE0[];
extern long lbl_8055EB34;
extern long *lbl_8055EB3C;
extern long lbl_8055EB38;
extern long *lbl_8055EB40;
void fn_801E78D8(long arg0) {
 long count; long i; long j; unsigned char *entry;
 count=fn_800167F4(); fn_80206464();
 for(i=0;i<count;i++) fn_8020646C(i,-1);
 entry=(unsigned char *)arg0+0x20;
 for(j=0;j<*((long *)((unsigned char *)arg0+0x3E0)); entry+=0x78,j++) {
  if(*(long *)entry==0x50) fn_8020646C(*(entry+0x70)&3,j);
 }
}

#pragma dont_inline on
void fn_801E797C(void) { fn_80206464(0); }

#pragma scheduling invalid_target
void fn_801E7984(long arg0) {
    /* Initialize the scene and its subsystems in the original call order. */
    register char *base;
    register char *strings;
    long start;
    unsigned sp8;
    long *p;
    strings = lbl_80339BA0; base = (char *)lbl_80487CE0;
    fn_801E78D8(arg0);
    start = fn_802E2C20();
    fn_8012E81C(strings);
    memcpy(base + 0x100, (void *)arg0, 0x3f8);
    lbl_8055EB12 = 1;
    lbl_8055EB30 = (void *)fn_800167F4();
    lbl_8055EB2C = (void *)-1;
    fn_8001255C(lbl_8055AF14, lbl_80562DA0);
    fn_80204460(); fn_80127464();
    lbl_8055EB0C = -1; lbl_8055EB04 = 0; lbl_8055EB1C = 0; lbl_8055EB20 = 0;
    memset(base, 0, 0x10);
    p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0;
    p = (long *)(base + 0x10);
    fn_801E89FC(); lbl_8055EB10 = 1;
    fn_80127464(); fn_801EA2E8();
    lbl_8055EB3C = fn_8012850C(0xb40, strings + 0x10);
    lbl_8055EB40 = fn_8012850C(0xb40, strings + 0x20);
    lbl_8055EB38 = 0; lbl_8055EB34 = 0; lbl_8055EB08 = 1;
    fn_8001255C(lbl_8055AF18, lbl_80562DA4);
    fn_801EEFC8(); memset(&sp8, 0, 4); sp8 = *(long *)(arg0 + 0x3e0);
    fn_80127464(); fn_80204BB8(); fn_80203C50(2); fn_801EFF4C(); fn_801EA4C4();
    fn_801AEF28(arg0); fn_80127464(); fn_80176460(arg0 + 0x3e4, arg0, &sp8);
    if ((unsigned char)lbl_8055EB11 == 0) fn_8000D7F0(arg0);
    fn_801EA1D8(); fn_80287780(arg0); fn_801F4CD8(); fn_801EA31C(arg0 + 0x3e4);
    fn_801EA394(); fn_801FFB6C(); fn_8000A868(); fn_801B826C(arg0);
    fn_80136764(); fn_8013477C(arg0); fn_801F9E04(arg0); fn_80265D8C(arg0);
    fn_8001255C(strings + 0x34, lbl_80562DA0); fn_801DCE0C(0);
    fn_801FC8DC(arg0); fn_8001285C(*(long *)(arg0 + 0x3e4)); fn_80139F5C(); fn_80127464();
    fn_801FA298(arg0); fn_801E96D8(arg0); fn_801EC11C(); fn_801E9564(arg0);
    fn_80127464(); fn_80287800(arg0); fn_80127464(); fn_80176614(); fn_80127464();
    fn_8027AA50(); fn_801FA9AC(); fn_80127464(); fn_801EEE38(); fn_802C6C30(); fn_80127464();
    fn_8001255C(strings + 0x40, lbl_80562DA8); fn_801EA38C(); fn_80127464();
    fn_802023D4(); fn_80127464(); fn_800125D4(strings + 0x4c, 1);
    fn_8000D878(); fn_802C2C60(1); fn_802C8218(0); fn_80203FEC(); fn_80127464();
    fn_802E30C8(strings + 0x60, fn_802E2C20() - start);
    fn_802ECC18(1); fn_80127464();
}
#pragma scheduling on

void fn_801E7C1C(long arg0) {
    lbl_8055EB11 = 0;
    fn_801E7984(arg0);
}

#pragma cplusplus on
#pragma scheduling invalid_target
#pragma push
#pragma opt_propagation off
extern "C" void fn_801E7C28(void *arg0) {
    class Dummy_801E7C28 {
    public:
        virtual void invoke(long);
    };
    extern void fn_802ECC18(long);
    extern void fn_80203FE8(void);
    extern void fn_802025D8(void);
    extern void fn_802C2C6C(void);
    extern void fn_800124DC(const char *, long, long, float);
    extern void fn_801EA390(void);
    extern void fn_8001255C(const char *, float);
    extern void fn_801766C4(void);
    extern void fn_802878A8(void);
    extern void fn_8013490C(void);
    extern void fn_80265D90(void);
    extern void fn_801F4D64(void);
    extern void fn_801E9BE4(void);
    extern void fn_801F9F08(void);
    extern void fn_801B832C(void);
    extern void fn_80128670(void *);
    extern void fn_801DCE10(void);
    extern void fn_801AF598(void);
    extern void fn_801EA56C(void);
    extern void fn_801EA3B8(void);
    extern void fn_801FFB70(void);
    extern void fn_801EFF70(void);
    extern void fn_80203DC8(void);
    extern void fn_802C7A00(void);
    extern void fn_801FC900(void);
    extern void fn_802877D0(void);
    extern void fn_8000D7F4(void *);
    extern void fn_80136768(void);
    extern void fn_801765B8(void);
    extern void fn_80205208(void);
    extern void fn_801EF184(void);
    extern void fn_801EA318(void);
    extern void fn_801EA1DC(void);
    extern void fn_8013A074(void);
    extern void fn_8020449C(void);
    extern void fn_802E3D00(void);
    extern void fn_8000D878(void);
    extern char lbl_80339BA0[];
    extern char lbl_8055AF1C;
    extern float lbl_80562DA0;
    extern float lbl_80562DAC;
    extern float lbl_80562DB0;
    extern float *lbl_8055EB04;
    extern char lbl_8055EB10;
    extern char lbl_8055EB12;
    extern char lbl_8055EB20;
    extern void *lbl_8055EB30;
    char *strings = lbl_80339BA0;
    long offset;
    long count;
    Dummy_801E7C28 *obj;

    fn_802ECC18(0);
    fn_801E797C();
    fn_80203FE8();
    fn_802025D8();
    fn_802C2C6C();
    fn_800124DC(strings + 0x7C, 1, 1, lbl_80562DAC);
    fn_801EA390();
    fn_8001255C(strings + 0x8C, lbl_80562DB0);
    fn_801766C4();
    fn_8001255C(&lbl_8055AF1C, lbl_80562DB0);
    fn_802878A8();
    fn_8013490C();
    fn_80265D90();
    fn_801F4D64();
    fn_801E9BE4();
    fn_801F9F08();
    fn_801B832C();
    for (count = 0, offset = 0; count < lbl_8055EB34; offset += 4, count++) {
        obj = (Dummy_801E7C28 *)*(long *)((char *)lbl_8055EB3C + offset);
        if (obj != 0)
            obj->invoke(1);
    }
    fn_80128670(lbl_8055EB3C);
    lbl_8055EB3C = 0;
    fn_8001255C(strings + 0x98, lbl_80562DB0);
    fn_80128670(lbl_8055EB40);
    lbl_8055EB40 = 0;
    fn_801DCE10();
    lbl_8055EB38 = 0;
    lbl_8055EB34 = 0;
    lbl_8055EB20 = 0;
    lbl_8055EB04 = 0;
    lbl_8055EB12 = 0;
    lbl_8055EB30 = 0;
    fn_8001255C(strings + 0xA4, lbl_80562DB0);
    fn_801AF598();
    fn_801EA56C();
    fn_801EA3B8();
    fn_801FFB70();
    fn_801EFF70();
    fn_80203DC8();
    fn_802C7A00();
    fn_801FC900();
    fn_802877D0();
    if ((unsigned char)lbl_8055EB11 == 0) {
        fn_8000D7F4(arg0);
        fn_80136768();
        fn_8001255C(strings + 0xB0, lbl_80562DB0);
        fn_801765B8();
        fn_80205208();
        fn_8001255C(strings + 0xC0, lbl_80562DA0);
        fn_801EF184();
        fn_801EA318();
        fn_801EA1DC();
        ((char *)&lbl_8055EB10)[0] = 0;
        fn_8013A074();
        fn_8020449C();
        fn_802E3D00();
        fn_8000D878();
    }
}
#pragma pop
#pragma scheduling on
#pragma cplusplus off

extern void fn_801E7C28(void *);
void fn_801E7DEC(void *arg0) {
    fn_801E7C28(arg0);
}

long fn_801E7DF0(long arg0) {
    return lbl_80487CF0[arg0];
}

void fn_801E7E04(long arg0, long arg1) {
    lbl_80487CF0[arg0] = arg1;
}

float fn_801E7E18(void) {
    extern float *lbl_8055EB04;
    return *lbl_8055EB04;
}

float fn_801E7E24(void) { extern float lbl_8055EB14; return lbl_8055EB14; }

long fn_801E7E2C(void) {
    return -1;
}

extern float *lbl_8055EB04;
void* fn_801E7E34(void) {
    return lbl_8055EB04;
}

long fn_801E7E3C(void) {
    return (long)lbl_8055EB04 + 0x560;
}

extern void *fn_80176A70(void);
extern void fn_80176BA8(void);
extern void fn_80287974(void);
extern void fn_8028797C(void);
extern void fn_801EA400(void);
extern void fn_801EF0AC(void *);
extern void fn_801FA2C4(void);
extern void fn_801F4DC4(void);
extern void fn_80202924(void);
extern void fn_80134994(void);
extern void fn_8000D7FC(void);
extern void fn_80202AD4(long);
extern void fn_801EAB90(long, void *);
extern long fn_801EA994(void);
extern void fn_801EA9DC(long, void *);
extern void *fn_801E87A8(void);
extern void fn_801E8CE4(void);
extern void fn_801E8A84(void);
void fn_801E7E48(void) {
    extern float lbl_80562DB8;
    extern double lbl_80562DC8;
    extern float lbl_8055EB28;
    char *obj;
    long long t0;
    float f, g;
    long i, j;
    char *dst;
    char *src;
    t0 = ((long long (*)())fn_802E2C9C)();
    obj = (char *)fn_80176A70();
    f = *(float *)obj - lbl_8055EB18;
    g = lbl_80562DB4;
    if (g >= f) g = f;
    f = g;
    if (f <= lbl_80562DB8) f = lbl_80562DB8;
    g = f;
    if (g > lbl_80562DBC) g = lbl_80562DBC;
    lbl_8055EB14 = g;
    lbl_8055EB18 = *(float *)obj;
    lbl_8055EB04 = (float *)obj;
    if ((long)lbl_8055EB2C != *(long *)(obj + 0x394)) {
        fn_802C2C60(0);
        lbl_8055EB2C = (void *)*(long *)(obj + 0x394);
    }
    lbl_8055EB20 = 1;
    dst = (char *)lbl_80487D00;
    i = 0; j = 0;
    while (i < (long)lbl_8055EB2C) {
        src = (char *)lbl_8055EB04 + j;
        if (*(long *)((char *)fn_801E87A8() + 0x10) & 2) {
            *(float *)(src + 4) *= lbl_80562DC0;
            *(float *)(src + 8) *= lbl_80562DC0;
            *(float *)(src + 12) *= lbl_80562DC0;
        }
        j += 0xE0; i++;
        *(long *)(dst + 0) = *(long *)(src + 4);
        *(long *)(dst + 4) = *(long *)(src + 8);
        *(long *)(dst + 8) = *(long *)(src + 12);
        *(long *)(dst + 12) = *(long *)(src + 16);
        *(long *)(dst + 16) = *(long *)(src + 20);
        *(long *)(dst + 20) = *(long *)(src + 24);
        *(long *)(dst + 24) = *(long *)(src + 28);
        *(long *)(dst + 28) = *(long *)(src + 32);
        *(long *)(dst + 32) = *(long *)(src + 36);
        *(long *)(dst + 36) = *(long *)(src + 40);
        *(long *)(dst + 40) = *(long *)(src + 44);
        *(long *)(dst + 44) = *(long *)(src + 48);
        *(long *)(dst + 52) = *(long *)(dst + 48);
        *(long *)(dst + 48) = *(long *)(src + 108);
        dst += 0x38;
    }
    (void)t0;
}

void fn_801E8144(void) {

}

extern void fn_80287AF0(void *);
extern void fn_801FA550(void);
#pragma cplusplus on
extern "C" void fn_801E8148(void) {
    class Dummy_801E8148 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
    };
    long index;
    long i;
    Dummy_801E8148 *obj;

    index = 0;
    i = 0;
    while (i < lbl_8055EB34) {
        obj = (Dummy_801E8148 *)*(long *)((char *)lbl_8055EB3C + index);
        obj->m2();
        index += 4;
        i++;
    }
    fn_80287AF0(0);
    fn_801FA550();
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801E81B8(int arg0, void (*callback)(void)) {
    extern void *lbl_8055AF0C;
    extern float *lbl_8055EB04;
    unsigned long index;
    void *entry;
    long i;
    long values[4];
    float value;

    /* Per-frame/step update: advances frame state, runs per-player update passes, and
     * performs single/multi-player follow-up logic before invoking an optional callback. */
    (void)arg0;
    fn_802E2C9C();
    lbl_8055EB1C = lbl_8055EB1C + 1;
    fn_802A4CA8();
    fn_802C276C();
    index = (unsigned long)fn_801E866C(0);
    if (index < 8)
        entry = lbl_80488648[index];
    else
        entry = 0;
    fn_80203E88(lbl_80487D00, (long)((unsigned char *)entry + 0x28),
                ((long)lbl_8055EB2C - 1) == 0);
    fn_8001A1F0();
    fn_801EA394();
    fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802CC73C((int)((long)lbl_8055EB2C <= 2));
    i = 0;
    goto first_check;
first_loop:
    lbl_8055AF0C = (void *)i;
    fn_801E83D4();
    i++;
first_check:
    if (i < (long)lbl_8055EB2C) goto first_loop;
    i = 0;
    goto second_check;
second_loop:
    lbl_8055AF0C = (void *)i;
    fn_801E8410();
    i++;
second_check:
    if (i < (long)lbl_8055EB2C) goto second_loop;
    fn_802CC73C(1);
    lbl_8055AF0C = (void *)-1;
    if (fn_801B89F8() == 0 && (long)lbl_8055EB2C > 1) {
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_801E88B4(&values[3], &values[2], &values[1], &values[0], 1);
        fn_8020625C();
    }
    if ((long)lbl_8055EB2C == 1) {
        fn_8029227C();
        fn_802A4D08();
        if (fn_80019B54() != 0)
            value = lbl_80562DB4;
        else
            value = *(float *)((char *)lbl_8055EB04 + 0x58);
        if (value > lbl_80562DD0)
            fn_802DB2A4();
        fn_802DD754();
    }
    fn_802A4D00();
    fn_80287978();
    if (callback != 0)
        callback();
}
#pragma scheduling invalid_target
extern "C" void fn_801E837C(void) {
    extern void fn_802D6C54(long, void *, float);
    long offset = 0;
    long i = 0;
    do {
        fn_802D6C54(i, (char *)lbl_8055EB04 + offset,
                    *(float *)((char *)lbl_8055EB04 + offset + 0xDB4));
        i++;
        offset += 4;
    } while (i < 0x4B);
}
#pragma scheduling on
void fn_801E83D4(void) { extern int fn_801B89F8(void); extern void *lbl_8055AF0C; extern void fn_801EBD18(void *); if (fn_801B89F8() == 0 || lbl_8055AF0C == 0) fn_801EBD18(lbl_8055AF0C); }

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801E8410(void) {
    extern int fn_801B89F8(void);
    extern float fn_801E8854(long);
    extern void fn_801E88B4(long *, long *, long *, long *, long);
    extern void fn_801E8148(void);
    extern void fn_801E95DC(void);
    extern void fn_801EA404(void *, long);
    extern void fn_802C87B4(long, long, long, long);
    extern void fn_802C8638(void *);
    extern void fn_802C2C64(long);
    extern void fn_80203EC0(void);
    extern void fn_802C7A44(void);
    extern void fn_802C7A50(void);
    extern void fn_802C7AD4(void);
    extern void fn_801FA618(void);
    extern void fn_802BF508(void);
    extern void fn_802C2488(void);
    extern void fn_802B0254(void);
    extern void fn_802B0218(void);
    extern void fn_80203EF4(void);
    extern void fn_80203EC4(void);
    extern void fn_80287A6C(long);
    extern void *lbl_8055AF0C;
    extern long lbl_8055CFF0, lbl_8055CFF4, lbl_8055EB34;
    extern long *lbl_8055EB3C;
    extern unsigned char lbl_80487D00[];
    extern void *lbl_80488648[];
    struct Dispatch24 {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    };
    struct Dispatch14 {
        virtual void n0(); virtual void n1(); virtual void n2(); virtual void n3();
    };
    long a, b, c, d;
    long count;
    unsigned char *base;
    ((void (*)(void))fn_801E837C)();
    if (fn_801B89F8() != 0) {
        if (*(void * volatile *)&lbl_8055AF0C != 0) return;
        a = 0; b = 0; c = lbl_8055CFF0; d = lbl_8055CFF4;
        count = (long)(*(void * volatile *)&lbl_8055AF0C);
        count *= 0x38;
        base = lbl_80487D00 + count;
        if (((int (*)(long, long, void *, long))fn_801B89F8)(
                c, 0, lbl_80487D00, count) == 0) {
            fn_801E88B4(&a, &b, &c, &d,
                        (long)(*(void * volatile *)&lbl_8055AF0C));
        }
        fn_802C87B4(a, b, c, d); fn_802C8638(base); fn_801E8854(-1);
        fn_802C2C64((long)(*(void * volatile *)&lbl_8055AF0C));
        fn_801EA404(base, 0);
    }
    fn_80203EC0(); fn_802C7A44(); ((void (*)(void))fn_801E8148)();
    fn_802C7A50(); fn_802C7AD4(); fn_801FA618();
    {
        long index; long i; Dispatch24 *obj;
        index = (long)lbl_80488648; i = 0;
        do {
            obj = (unsigned long)i < 8 ? *(Dispatch24 **)index : 0;
            if (obj != 0) obj->m7();
            i++; index += 4;
        } while (i < 8);
    }
    fn_802BF508(); fn_802C2488(); fn_802B0254(); fn_802B0218();
    fn_80203EF4(); fn_80203EC4(); fn_80287A6C(0); fn_801E95DC();
    {
        long i; long index; Dispatch14 *obj2;
        i = 0; index = 0;
        while (i < lbl_8055EB34) {
            obj2 = (Dispatch14 *)*(long *)((char *)lbl_8055EB3C + index);
            obj2->n3(); index += 4; i++;
        }
    }
}
#pragma cplusplus off
#pragma scheduling on
void fn_801E85A0(void) {

}

extern void *lbl_8055EB2C;
void* fn_801E85A4(void) {
    return lbl_8055EB2C;
}

extern void *lbl_8055EB30;
void* fn_801E85AC(void) {
    return lbl_8055EB30;
}

extern void *lbl_8055AF0C;
void* fn_801E85B4(void) {
    return lbl_8055AF0C;
}

extern long fn_8026A298(long);
extern long fn_801E866C(long);
extern unsigned char *fn_801EA9A0(long);
extern long fn_8026A248(long, long);
extern long fn_8026A2C8(void);
extern unsigned long lbl_80487CE0[];
void fn_801E85BC(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    fn_8026A298(arg0);
}

extern long fn_8026A2B0(long);
void fn_801E85CC(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    fn_8026A2B0(arg0);
}

void fn_801E85DC(long arg0) {
    /* Select the next active car-manager entry from the given player's slot (defaulting to lbl_8055AF0C) and apply it. */
    long idx;
    long startIdx;
    long playerId;
    long count;
    playerId = arg0;
    if (arg0 < 0) playerId = (long)lbl_8055AF0C;
    idx = fn_801E866C(playerId);
    startIdx = idx;
loop:
    idx = idx + 1;
    count = fn_8026A2C8();
    idx = idx % count;
    if (*fn_801EA9A0(idx) == 0 && idx != startIdx) goto loop;
    fn_8026A248(idx, playerId);
}

long fn_801E866C(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(long *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x64);
}

#pragma scheduling invalid_target
long fn_801E868C(long arg0, unsigned long *arg1, unsigned long *arg2) {
    volatile unsigned long *entry;
    volatile unsigned long *cache;
    unsigned long id;

    entry = (volatile unsigned long *)((char *)lbl_8055EB04 + arg0 * 0xE0);
    cache = (volatile unsigned long *)lbl_80487CE0;
    id = entry[0x70 / 4];
    if (id != cache[arg0]) {
        cache[arg0] = id;
        *arg1 = entry[0x74 / 4] >> 16;
        if (arg2 != 0) {
            *arg2 = entry[0x74 / 4] & 0xFFFF;
        }
        return 1;
    }
    return 0;
}
#pragma scheduling on
void fn_801E86E8(long arg0, long arg1) {
    if (arg1 < 0) arg1 = (long)lbl_8055AF0C;
    fn_8026A248(arg0, arg1);
}

long fn_801E86F8(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(long *)((char *)lbl_8055EB04 + arg0 * 4 + 0x384);
}

extern unsigned char lbl_80487D00[];
void *fn_801E8718(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return lbl_80487D00 + arg0 * 0x38;
}

float fn_801E8738(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(float *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x34);
}

#pragma scheduling off
long fn_801E8758(long arg0) {
    long value;
    unsigned char *entry;
    long result;

    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    entry = (unsigned char *)lbl_80487D00 + arg0 * 0x38;
    value = *(long *)(entry + 0x30);
    result = 1;
    if ((value & 0x10) == 0) {
        if (((value ^ *(long *)(entry + 0x34)) & 0x20) == 0) result = 0;
    }
    return result;
}
#pragma scheduling on
void *fn_801E879C(void) {
    return lbl_80487DE0;
}

void *fn_801E87A8(void) {
    return lbl_80487DE0 + 0x3E4;
}

#pragma dont_inline on
void fn_801E87B8(long arg0) {
    lbl_8055EB3C[lbl_8055EB34++] = arg0;
}
void fn_801E87D4(long arg0) {
    long value2 = arg0;
    int index;
    long *base;
    fn_801E87B8(value2);
    index = (int)lbl_8055EB38;
    base = lbl_8055EB40;
    base[index] = value2;
    lbl_8055EB38 = index + 1;
}

extern void *lbl_8055EB24;
void fn_801E8818(void* hi) {
    lbl_8055EB24 = hi;
}

void fn_801E8820(void) {
    lbl_8055EB24 = 0;
}

extern char lbl_8055EB08;
void fn_801E882C(void) {
    lbl_8055EB08 = 1;
}

int fn_801E8838(void) {
    if (lbl_8055EB04 != 0) {
        return *(int *)((char *)lbl_8055EB04 + 0xDB0);
    }
    return 0xFF;
}

float fn_801E8854(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(float *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x54);
}

float fn_801E8874(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(float *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x4C);
}

float fn_801E8894(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return *(float *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x50);
}

void fn_801E88B4(long *arg0, long *arg1, long *arg2, long *arg3, long arg4) {
    long index = arg4;
    char *base;
    if (index < 0) index = (long)lbl_8055AF0C;
    base = (char *)lbl_8055EB04 + index * 0xE0;
    *arg0 = *(long *)(base + 0x3C);
    *arg1 = *(long *)(base + 0x40);
    *arg2 = *(long *)(base + 0x44);
    *arg3 = *(long *)(base + 0x48);
}

#pragma scheduling invalid_target
float fn_801E88F0(long arg0) {
    long index = arg0;
    long params[4];
    long which;
    char *base;
    if (index < 0) index = (long)lbl_8055AF0C;
    *(struct FourLongs *)params = *(struct FourLongs *)lbl_802F99F8;
    which = (long)lbl_8055EB2C - 1;
    base = (char *)lbl_8055EB04 + index * 0xE0;
    return *(float *)(base + 0x38) * ((float *)params)[which];
}
#pragma scheduling on
long fn_801E8954(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return (*(unsigned long *)(lbl_80487D00 + arg0 * 0x38 + 0x30)) & 1;
}

long fn_801E897C(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return (*(unsigned long *)(lbl_80487D00 + arg0 * 0x38 + 0x30) >> 1) & 1;
}

long fn_801E89A4(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return (*(unsigned long *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x6C) >> 2) & 1;
}

long fn_801E89C8(long arg0) {
    if (arg0 < 0) arg0 = (long)lbl_8055AF0C;
    return (*(unsigned long *)((char *)lbl_8055EB04 + arg0 * 0xE0 + 0x6C) >> 3) & 1;
}

extern void *lbl_8055AF08;
void* fn_801E89EC(void) {
    return lbl_8055AF08;
}

void fn_801E89F4(void *arg0) {
    lbl_8055AF08 = arg0;
}

#pragma scheduling invalid_target
void fn_801E89FC(void) {
    extern float fn_80129DC4(long, float, float);
    extern float lbl_804881D8[];
    extern float lbl_80562DBC, lbl_80562DC0, lbl_80562DD4, lbl_80562DD8;
    extern float lbl_80562DDC, lbl_80562DE0;
    extern void PSVECNormalize(float *, float *);
    lbl_804881D8[0] = fn_80129DC4(0, lbl_80562DC0, lbl_80562DD4);
    lbl_804881D8[1] = fn_80129DC4(0, lbl_80562DD8, lbl_80562DDC);
    lbl_804881D8[2] = fn_80129DC4(0, lbl_80562DC0, lbl_80562DD4);
    PSVECNormalize(lbl_804881D8, lbl_804881D8);
    lbl_804881D8[3] = fn_80129DC4(0, lbl_80562DBC, lbl_80562DE0);
}
void fn_801E8A84(void) {
    extern float lbl_80562DE4, lbl_80562DE8;
    extern float lbl_80562DEC, lbl_80562DF0;
    float value;
    float scale;
    lbl_804881D8[0] += fn_80129DC4(0, lbl_80562DE4, lbl_80562DE8);
    lbl_804881D8[1] += fn_80129DC4(0, lbl_80562DE4, lbl_80562DE8);
    lbl_804881D8[2] += fn_80129DC4(0, lbl_80562DE4, lbl_80562DE8);
    if (lbl_804881D8[1] > lbl_80562DDC) {
        scale = (lbl_804881D8[1] - lbl_80562DDC) * lbl_80562DB4;
        if (lbl_804881D8[0] > lbl_80562DBC)
            value = lbl_80562DD4;
        else
            value = lbl_80562DC0;
        lbl_804881D8[0] = lbl_804881D8[0] + scale * value;
        lbl_804881D8[1] = lbl_80562DDC;
        if (lbl_804881D8[2] > lbl_80562DBC)
            value = lbl_80562DD4;
        else
            value = lbl_80562DC0;
        lbl_804881D8[2] = lbl_804881D8[2] + scale * value;
    } else if (lbl_804881D8[1] < lbl_80562DD8) {
        scale = (lbl_80562DD8 - lbl_804881D8[1]) * lbl_80562DB4;
        if (lbl_804881D8[0] > lbl_80562DBC)
            value = lbl_80562DD4;
        else
            value = lbl_80562DC0;
        lbl_804881D8[0] = lbl_804881D8[0] + scale * value;
        lbl_804881D8[1] = lbl_80562DD8;
        if (lbl_804881D8[2] > lbl_80562DBC)
            value = lbl_80562DD4;
        else
            value = lbl_80562DC0;
        lbl_804881D8[2] = lbl_804881D8[2] + scale * value;
    }
    PSVECNormalize(lbl_804881D8, lbl_804881D8);
    value = lbl_804881D8[3] + fn_80129DC4(0, lbl_80562DEC, lbl_80562DF0);
    value = (value < lbl_80562DE0) ? lbl_80562DE0 : value;
    value = (value > lbl_80562DBC) ? lbl_80562DBC : value;
    lbl_804881D8[3] = value;
}
#pragma scheduling on
void fn_801E8C84(float *arg0) {
    float scale = lbl_804881D8[3];
    arg0[0] = lbl_804881D8[0] * scale;
    arg0[1] = lbl_804881D8[1] * scale;
    arg0[2] = lbl_804881D8[2] * scale;
}

void fn_801E8CB8(float *arg0, float *arg1) {
    arg0[0] = lbl_804881D8[0];
    arg0[1] = lbl_804881D8[1];
    arg0[2] = lbl_804881D8[2];
    arg1[0] = lbl_804881D8[3];
}

#pragma scheduling off
void fn_801E8CE4(void) {
    fn_80297984(); fn_802889F0();
    if (lbl_8055EB24 != 0) ((void (*)(void))lbl_8055EB24)();
    fn_80287914(); fn_801FA1D4(); fn_802C1A08();
    memset(lbl_80487CE0, 0, 0x10);
    lbl_8055EB18 = lbl_80562DBC;
    lbl_8055EB14 = lbl_80562DBC;
}
#pragma scheduling on
void fn_801E8D48(void) {
    struct Init { void *name; int size; float a,b,c,d,e,f,g,h; } init;
    int status;

    init.c = lbl_80562DFC;
    init.d = lbl_80562DFC;
    init.name = (void *)0x57484C50;
    init.a = lbl_80562DF4;
    init.b = lbl_80562DF8;
    init.size = 0x28;
    init.e = lbl_80562E00;
    init.f = lbl_80562DA0;
    init.g = lbl_80562E04;
    init.h = lbl_80562E08;
    status = ((int (*)(int, void *))fn_801284F8)(0x84, &lbl_8055AF24);
    if (status != 0) {
        ((void (*)(int, void *))fn_801F19FC)(status, &init);
    }
    ((void (*)(void))fn_801E87D4)();
}

#pragma scheduling invalid_target
void fn_801E8DD4(void) {
    long data[2];
    void *object;
    memset(data, 0, 8);
    data[0] = 0x50616E6C;
    data[1] = 8;
    object = ((void *(*)(int, void *))fn_801284F8)(0x7C, &lbl_80339CB4);
    if (object != 0) fn_801EAD6C(object, (long)data);
    ((void (*)(void))fn_801E87D4)();
}
#pragma scheduling invalid_target
void fn_801E8E38(void) {
    struct InitData { long tag; long size; float a; float b; float c; float d; } data;
    void *object;

    data.tag = 0x4D555450;
    data.size = 0x18;
    data.a = lbl_80562DB0;
    data.d = lbl_80562DA8;
    data.c = lbl_80562DA8;
    data.b = lbl_80562DA8;
    object = ((void *(*)(int, void *))fn_801284F8)(0x7C, &lbl_80339CB4);
    if (object != 0) fn_801EAD6C(object, (long)&data);
    ((void (*)(void))fn_801E87D4)();
}
#pragma scheduling invalid_target
void *fn_801E8EA4(long arg0) {
    unsigned char *entry;
    long sentinel;
    entry = lbl_80339CC0;
    goto check_key;
check_key:
    if (*(long *)(entry + 4) == arg0) goto done;
    entry = (unsigned char *)((long)entry + 0xC);
    sentinel = *(long *)entry;
    if (sentinel != 0) goto check_key;
done:
    if (sentinel == 0) {
        fn_802E317C(lbl_80339CFC, arg0);
    }
    return entry;
}

extern int sprintf(char *, const char *, ...);
extern char lbl_804881E8[];
extern void fn_801E9DC4(void *);
extern void fn_801EEEB0(void *, void *);
extern void fn_801EC750(void *, void *);
void fn_801E8F10(long arg0) {
    long *e;
    struct Ctx68 ctx;
    struct Loc78 loc;
    struct Rec78 *p;
    long i;
    long cnt;
    fn_8012E81C(lbl_80339BA0 + 0x178);
    fn_8012E81C(lbl_80339BA0 + 0x188);
    cnt = arg0 + 0x20;
    fn_802E30C8(lbl_80339BA0 + 0x194, *(long *)(cnt + 0x3C0));
    p = (struct Rec78 *)cnt;
    for (i = 0; i < *(long *)(cnt + 0x3C0); i++, p++) {
        sprintf(lbl_804881E8, lbl_80339BA0 + 0x1B0, i);
        fn_80127464();
        fn_8001255C(lbl_804881E8, lbl_80562DA0);
        loc.r = *p;
        loc.idx = i;
        e = (long *)fn_801E8EA4(loc.r.tag);
        ctx.w0 = e[0];
        ctx.w1 = e[2];
        memset(ctx.pad, 0, 0x50);
        fn_801E9DC4((char *)&ctx + 0x58);
        if (p->tag == 0x53) {
            if (((int (*)(int, void *))fn_801284F8)(0x4E4, lbl_80339BA0 + 0x1C0)) fn_801EEEB0(&ctx, p);
        } else {
            if (((int (*)(int, void *))fn_801284F8)(0x4E4, lbl_80339BA0 + 0x1D0)) fn_801EC750(&ctx, p);
        }
        ((void (*)(void))fn_801E87D4)();
    }
}

#pragma scheduling on
long fn_801E952C(long arg0) {
    memset((void *)arg0, 0, 0x3F8);
    return arg0;
}
#pragma scheduling on
// Builds the scene's physics objects and registers each one (fn_801E87D4): the truck's
// five wheels, one object per record in the track data, then the track's panels and
// mutable parts, all created through the game's tagged MemAlloc pools.
void fn_801E9564(long sceneData) {
    long i;

    for (i = 0; i < 5; i++) fn_801E8D48();    // 'WHLP' wheel objects, "wheel" pool
    fn_80127464();                            // finish pending work, run queued callbacks
    fn_801E8F10(sceneData);                   // the objects placed by the track's records
    for (i = 0; i < 0xC; i++) fn_801E8DD4();  // 'Panl' objects, "MutableWob" pool
    for (i = 0; i < 0x40; i++) fn_801E8E38(); // 'MUTP' objects, "MutableWob" pool
}
#pragma push
#pragma processor 750
void fn_801E95DC(void) {
    extern double fn_8002EFB4(double, double);
    extern float fn_80203FE0(void);
    extern void fn_802C7D54(long, float *, long, float, float, float);
    extern void *lbl_80488648[];
    extern double lbl_80562E10;
    extern float lbl_80562E18;
    float matrix[12];
    float x, y;
    float time;
    long flags;
    unsigned long index;
    char *entry;
    long mode;
    if (lbl_8055AF10 != -1) {
        matrix[1] = lbl_80562DBC;
        matrix[0] = lbl_80562DD4;
        matrix[2] = lbl_80562DBC;
        matrix[3] = lbl_80562DBC;
        matrix[4] = lbl_80562DD4;
        matrix[5] = lbl_80562DBC;
        matrix[6] = lbl_80562DBC;
        matrix[7] = lbl_80562DBC;
        matrix[8] = lbl_80562DD4;
        matrix[9] = lbl_80562DBC;
        matrix[10] = lbl_80562DBC;
        matrix[11] = lbl_80562DBC;
        time = ((float (*)(float))fn_801E7E18)(lbl_80562DD4);
        x = lbl_80562DD4 - (float)fn_8002EFB4(time, lbl_80562E10);
        y = lbl_80562DBC;
        index = fn_801E866C((long)lbl_8055AF0C);
        if (index < 8) entry = lbl_80488648[index];
        else entry = 0;
        matrix[10] = *(float *)(entry + 0x2c);
        y = y - matrix[10] / fn_80203FE0();
        flags = *(long *)((char *)fn_801E87A8() + 0x10);
        mode = 2;
        if (flags & 2) mode = 1;
        fn_802C7D54(lbl_8055AF10, matrix, mode, x, y, lbl_80562E18);
    }
}
#pragma pop
extern void *fn_80131808(void);
extern void fn_80131818(void *);
extern int fn_8002B1D8(const char *, const char *, int);
extern float fn_801DCF48(long, float, float);
extern double fn_8002F234(float);
extern void fn_801FA8E0(void *, void *, long);
extern long fn_802C6FC0(void *, long, long);
extern int strcmp(const char *, const char *);
extern char *strstr(const char *, const char *);
extern float PSVECMag(float *);
extern void PSVECCrossProduct(float *, float *, float *);
extern void fn_801345D8(void *, long, const char *, ...);
extern char lbl_803338C0[];
extern char lbl_8055AF2C[];
extern char lbl_8055AF34[];
extern char lbl_8055AF3C[];
extern char lbl_8055AF44[];
extern char lbl_8055AF4C[];
extern char lbl_8055AF58[];
extern char lbl_8055AF60[];
extern float lbl_80562DB4;
extern float lbl_80562DF0;
extern float lbl_80562E1C;
extern float lbl_80562E20;
void fn_801E96D8(long arg0) {
    float sp94, sp90, sp8C, sp88, sp84, sp80, sp7C, sp78, sp74, sp70, sp6C, sp68;
    float sp60, sp5C, sp58;
    unsigned char sp48[16];
    float sp44, sp40, sp3C, sp38, sp34, sp30;
    double sp28;
    float sp24, sp20;
    long sp1C, sp18, sp14, sp10, spC, sp8;
    float temp_f24, temp_f25, temp_f26, temp_f27, temp_f28, temp_f29, temp_f30, temp_f31;
    long temp_ret;
    long temp_r20, temp_r21;
    long var_r17, var_r18, var_r19, var_r23, var_r25;
    long zero, hundred, magic;
    long tailres;
    void *temp_r3_4;
    void **temp_r3_3;
    void **var_r22;
    void *temp;
    void *r31base;
    char *sbase;
    temp = (void *)fn_8001285C(*(long *)(arg0 + 0x3E4));
    sbase = lbl_80339BA0;
    if ((((long (*)(void *, void *, long))(*(void ***)(*(void **)((char *)temp + 0x20)))[6])((*(void **)((char *)temp + 0x20)), sbase + 0x1DC, 0)) != 0) {
        temp_r3_3 = fn_80131808();
        var_r23 = 0;
        var_r22 = ((void **(*)(void *, long))(*(void ***)temp_r3_3)[3])(temp_r3_3, 0);
        r31base = lbl_803338C0;
        temp_f27 = lbl_80562DBC;
        temp_f28 = lbl_80562DB4;
        temp_f29 = lbl_80562DD4;
        temp_f31 = lbl_80562DC0;
        temp_f30 = lbl_80562E1C;
        zero = 0;
        temp_f24 = lbl_80562DF0;
        magic = 0x424F0000;
        temp_f25 = lbl_80562E20;
        hundred = 100;
        while (var_r22 != 0) {
            temp_r21 = fn_8002B1D8(((char *(*)(void *))(*(void ***)var_r22)[2])(var_r22), lbl_8055AF2C, 5) == 0;
            fn_8002B1D8(((char *(*)(void *))(*(void ***)var_r22)[2])(var_r22), lbl_8055AF34, 4);
            temp_r20 = strstr(((char *(*)(void *))(*(void ***)var_r22)[2])(var_r22), lbl_8055AF3C) != 0;
            if (strcmp(((char *(*)(void *))(*(void ***)var_r22)[2])(var_r22), lbl_8055AF44) != 0 && ((long (*)(void *, void *))(*(void ***)var_r22)[3])(var_r22, lbl_8055AF4C) != 0) {
                long temp_ret_2, temp_ret_3;
                var_r19 = 0;
                var_r18 = 1;
                var_r17 = 0;
                temp_ret = ((long (*)(void *, void *))(*(void ***)var_r22)[15])(var_r22, lbl_8055AF4C);
                sp18 = temp_ret;
                sp1C = (long)lbl_8055AF4C;
                sp5C = temp_f27;
                sp28 = *(double *)&sp18;
                sp58 = ((float *)&sp28)[0];
                sp60 = ((float *)&sp28)[1];
                sp5C = fn_801DCF48(0, ((float *)&sp28)[0], ((float *)&sp28)[1]);
                do {
                    fn_801345D8(sp48, 16, lbl_8055AF58, var_r18);
                    var_r25 = 1;
                    if (((long (*)(void *, void *))(*(void ***)var_r22)[3])(var_r22, sp48) != 0) {
                        temp_ret_2 = ((long (*)(void *, void *))(*(void ***)var_r22)[15])(var_r22, sp48);
                        sp14 = (long)sp48;
                        sp10 = temp_ret_2;
                        sp24 = *(float *)&sp14;
                        sp20 = *(float *)&sp10;
                    } else {
                        if (temp_r20 == 0) {
                            temp_ret_3 = ((long (*)(void *, void *))(*(void ***)var_r22)[15])(var_r22, lbl_8055AF4C);
                            spC = (long)lbl_8055AF4C;
                            sp8 = temp_ret_3;
                            sp24 = *(float *)&spC;
                            sp20 = *(float *)&sp8;
                        } else {
                            var_r25 = 0;
                        }
                        var_r19 = 1;
                    }
                    if (var_r25 != 0) {
                        float temp_f1, temp_f2, temp_f3, temp_f4, temp_f7;
                        sp3C = sp20;
                        sp40 = temp_f27;
                        sp44 = sp24;
                        temp_f1 = fn_801DCF48(0, sp20, sp24);
                        temp_f7 = (float)temp_f1;
                        sp40 = (float)temp_f1;
                        temp_f2 = sp58 - sp3C;
                        sp88 = sp44 - sp60;
                        sp34 = temp_f28 * (sp60 - sp44);
                        temp_f4 = temp_f7 + temp_f28 * (sp5C - temp_f7);
                        sp38 = sp44 + temp_f4;
                        temp_f3 = sp3C + temp_f28 * temp_f2;
                        sp30 = temp_f3;
                        sp8C = temp_f3;
                        sp90 = temp_f4;
                        sp94 = sp38;
                        sp80 = sp3C - sp58;
                        sp84 = temp_f27;
                        temp_f26 = PSVECMag(&sp80) * temp_f28;
                        PSVECNormalize(&sp80, &sp80);
                        sp74 = temp_f27;
                        sp78 = temp_f29;
                        sp7C = temp_f27;
                        PSVECCrossProduct(&sp74, &sp80, &sp68);
                        sp90 = sp90 + temp_f30;
                        if (temp_r21 != 0) {
                            sp68 = sp68 * temp_f31;
                            sp6C = sp6C * temp_f31;
                            sp70 = sp70 * temp_f31;
                            sp80 = sp80 * temp_f31;
                            sp84 = sp84 * temp_f31;
                            sp88 = sp88 * temp_f31;
                        }
                        temp_r3_4 = ((void *(*)(int, void *))fn_801284F8)(0x38, lbl_8055AF60);
                        if (temp_r3_4 != 0) {
                            *(long *)((char *)temp_r3_4 + 0xC) = zero;
                            *(long *)((char *)temp_r3_4 + 0x4) = zero;
                            *(long *)((char *)temp_r3_4 + 0x8) = zero;
                            *(long *)((char *)temp_r3_4 + 0x18) = magic + 0x5820;
                            *(float *)((char *)temp_r3_4 + 0x10) = temp_f27;
                            *(float *)((char *)temp_r3_4 + 0x14) = temp_f27;
                            *(long *)((char *)temp_r3_4 + 0x20) = hundred;
                            *(long *)((char *)temp_r3_4 + 0x1C) = zero;
                            *(void **)temp_r3_4 = r31base;
                            *(float *)((char *)temp_r3_4 + 0x24) = temp_f24;
                            *(float *)((char *)temp_r3_4 + 0x28) = temp_f25;
                            *(float *)((char *)temp_r3_4 + 0x2C) = temp_f26;
                            *(long *)((char *)temp_r3_4 + 0x34) = zero;
                            *(float *)((char *)temp_r3_4 + 0x30) = temp_f24 + (float)fn_8002F234(temp_f26 * temp_f26 + (temp_f24 * temp_f24 + temp_f25 * temp_f25));
                        }
                        ((void (*)(void *, long))(*(void ***)temp_r3_4)[16])(temp_r3_4, 0x3EA);
                        fn_801FA8E0(temp_r3_4, &sp68, -1);
                        var_r18 += 1;
                        var_r17 += 1;
                        sp58 = sp3C;
                        sp5C = sp40;
                        sp60 = sp44;
                    }
                    fn_80127464();
                } while (var_r19 == 0);
                fn_802E30C8(sbase + 0x1E8, var_r17, ((char *(*)(void *))(*(void ***)var_r22)[2])(var_r22));
            }
            var_r23 += 1;
            var_r22 = ((void **(*)(void *, long))(*(void ***)temp_r3_3)[3])(temp_r3_3, var_r23);
        }
        fn_80131818(temp_r3_3);
    }
    tailres = (((long (*)(void *, void *, long))(*(void ***)(*(void **)((char *)temp + 0x20)))[6])((*(void **)((char *)temp + 0x20)), sbase + 0x204, 0));
    if (tailres != 0) {
        lbl_8055AF10 = fn_802C6FC0((void *)tailres, 0, 0);
    }
}

#pragma pop
void fn_801E9BE4(void) {
    long value = lbl_8055AF10;
    if (value != -1) fn_802C6CF8(value);
    lbl_8055AF10 = -1;
}

extern unsigned char lbl_80487D00[];
