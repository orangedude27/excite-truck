#include <types.h>

extern u8 lbl_802FB5F0[];
extern u8 lbl_802FB5D8[];
extern s32 fn_801B880C(void);
extern s32 fn_80006580(void);
extern void fn_801B84C0(void *);
extern s32 fn_801769B8(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80128668(void);
extern s32 fn_80005564(void);
extern void *fn_801B83A0(void);
extern void *lbl_8055D350;
extern f32 lbl_8056011C;
extern s32 fn_801E866C(void);
extern void *fn_801EA9A0(void);
extern s32 fn_801B84D8(s32, s32);
extern s32 fn_801B8570(s32);
extern u8 lbl_8034EEB8_arr[];
extern s32 fn_80011A5C(s32);
extern s32 fn_801B84A4(s32);
extern s32 fn_80230DA0(void);
extern void fn_80235380(s32);
extern u8 lbl_802FB478[];
extern u8 lbl_8034EE84[0x100];
extern u8 lbl_8055F024;

extern s32 lbl_8034EEB8[0x100];
extern void fn_800070DC(void);
extern s32 fn_802E2C20(void);
extern s32 lbl_8055D348;
extern f32 lbl_8055D34C;
extern void fn_80005C20(void);
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(f32, f32, f32);
extern f32 lbl_80560130;
extern f32 lbl_80560124;
extern f32 lbl_8056019C;
extern void fn_801E7E18(void *, void *);
extern void fn_80011A2C(void);
extern void fn_802C9904(void);
extern void fn_800066B4(void *);
extern s32 fn_80009C84(void);
extern u8 lbl_8055D340[];
extern s32 fn_801CB844(void);
extern s32 fn_801B8874(void);
extern void fn_80006B18(void *);
extern s32 fn_80010074(s32, s32, void *, void *, f32, f32, f32);
extern int sprintf(char *, const char *, ...);
extern u8 lbl_802FB2A0[];
extern s32 lbl_80558928;
extern u8 lbl_80558948[];
extern f32 lbl_80560134;
extern f32 lbl_80560190;
extern u8 lbl_802FB0C8[];
extern s32 lbl_8055D354;
void fn_800056C8(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)((u8 *)&lbl_8034EEB8 + (arg0 << 4));
    *(p + 4) = arg1;
}

void fn_800056E0(s32 arg0) {
    s32 r29 = arg0;
    s32 r30 = 0;
    s32 r31 = ((s32 *)lbl_8055D350)[4];
    while (1) {
        if (r30 >= r31) break;
        fn_800056C8(r30, r29);
        r30++;
    }
}

void fn_80005740(s32 arg0) {
    u32 *base;
    void *temp;
    s32 val_2c;
    
    base = (u32 *)lbl_8034EE84;
    base[0x1C / 4] = arg0;
    base[0x24 / 4] = (u32)fn_801E866C();
    temp = fn_801EA9A0();
    base[0x28 / 4] = (u32)temp;
    val_2c = ((s32 *)temp)[2];
    base[0x2C / 4] = val_2c;
    base[0x30 / 4] = (u32)((u8 *)temp + 0xC);
    base[0x20 / 4] = (u32)fn_801B84D8(arg0, val_2c);
    if (fn_80005564() != 0) {
        fn_801B8570((s32)base[0x24 / 4]);
    }
}

void fn_800057BC(void) {
    if (lbl_8055F024 == 0) {
        return;
    }
    fn_80230DA0();
}

void fn_80005B54(void) {
    return;
}

void fn_80005B58(void) {
    return;
}

void fn_80005B64(void) {
    return;
}

void fn_80005B68(void) {

}

void fn_80005B6C(void) {
    return;
}

void fn_80005B70(void) {
}

#pragma push
#pragma opt_pointer_aliasing on
#pragma dont_inline on
void fn_80005B74(void) {
    extern s32 fn_80019B54(void);
    extern s32 *__AXFXGetLfoSinTable_801769CC(void);
    extern void *fn_8001285C(s32);
    extern void fn_800105A0(const char *, s32);
    extern f32 lbl_80560120;
    char buffer[0x20];
    f32 value, current;
    void *object;
    u8 *base = lbl_802FB0C8;
    if (fn_80019B54() != 0) {
        object = *(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
        value = (*(f32 (**)(void *, const char *))((u8 *)*(void **)object + 0x24))(object, (char *)base + 0x24);
        current = *(f32 *)((u8 *)lbl_8055D350 + 0x10);
        if (current > value) {
            if (current - value < lbl_80560120) {
                fn_800105A0((char *)base + 0x38, 0);
            }
        } else {
            sprintf(buffer, (char *)base + 0x4C, value - current);
            fn_800105A0(buffer, 0);
        }
    }
}
#pragma pop
s32 fn_80005FE0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80006020(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80006060(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_800060B4(void) {
    return;
}

void fn_800060DC(void) {
}

void fn_800060E0(u8 arg0, u8 arg1) {
    lbl_8055D340[0] = arg0;
    lbl_8055D340[2] = arg1;
    __AXDSPInitCallback_801769E0();
    fn_8017691C();
}

s32 ARCClose(void) {
    return 0;
}

s32 fn_80006244(void) {
    return 0;
}

s32 fn_8000624C(void) {
    return 0;
}

void fn_80006254(s32 arg0, s32 arg1) {
    f32 f2;
    s32 r0;
    s32 r12;

    r0 = 0;
    r12 = ((s32 *)lbl_8055D350)[7];
    f2 = ((f32 *)((s8 *)arg0 + r12 * 4))[1];
    if (f2 >= lbl_8056011C) {
        f32 f0 = ((f32 *)lbl_8055D350)[4] - f2;
        if (f0 > lbl_8056011C) {
            r0 = 1;
        }
    }
    if (r0 && fn_80005564()) {
        void *obj = fn_801B83A0();
        r12 = ((s32 *)obj)[0];
        r12 = ((s32 *)r12)[0x60 / 4];
        ((void (*)(s32))r12)(arg1);
    }
}

void fn_800062E4(void) {
    return;
}

void fn_800062E8(void) {
    if (fn_801B885C(((s32 *)lbl_8055D350)[7]) == 0 &&
        ((s32 *)lbl_8055D350)[6] == ((s32 *)lbl_8055D350)[5]) {
        fn_8000FBE4();
    }
}

extern s32 fn_80011A5C(s32);
extern s32 fn_801B84A4(s32);
void fn_80006378(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)(lbl_8034EEB8_arr + (arg1 << 4));
    void (*fn)(void) = (void (*)(void))((s32 *)p[7])[12];
    fn();
}

s32 fn_8000639C(void) {
    return 0;
}

void fn_800063A4(void) {
    fn_801C6B70();
}

void fn_800064A8(void *arg0) {
    volatile s32 *p8 = (volatile s32 *)((u8 *)arg0 + 8);
    volatile s32 *p4 = (volatile s32 *)((u8 *)arg0 + 4);
    s32 oldValue = *p8;
    s32 newValue = *p4;
    s32 var_r3;
    if (oldValue != newValue) {
        *p8 = newValue;
        if (fn_80009C84() != 0) var_r3 = lbl_8055D348;
        else var_r3 = fn_802E2C20();
        *(s32 *)((u8 *)arg0 + 0xC) = var_r3;
    }
    fn_80011A2C();
    switch (*(s32 *)((u8 *)arg0 + 4)) {
    case 3: fn_800066B4(arg0); return;
    case 2: fn_801CB844(); return;
    case 1: if (fn_801B8874() == 0) fn_80006B18(arg0); return;
    }
}

void fn_80006550(void *arg0, s32 arg1) {
    s32 temp_r0;
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x10) + arg1;
    *(s32 *)((u8 *)arg0 + 0x10) = temp_r0;
    if (temp_r0 < 0) *(s32 *)((u8 *)arg0 + 0x10) = 0;
    if (*(s32 *)((u8 *)arg0 + 0x10) >= 3) *(s32 *)((u8 *)arg0 + 0x10) = 2;
}

void fn_80006D30(void) {
    char sp8[0x48];
    if (((s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x2C) + 0x2C0))[0] & 0x10) {
        sprintf(sp8, (const char *)lbl_802FB2A0, lbl_80558928);
        fn_80010074(-1, 0x14, lbl_80558948, sp8, lbl_80560134, lbl_8056011C, lbl_80560190);
    }
}

void fn_80006E50(void) {
}

void fn_800070D4(void) {
    return;
}

void fn_800070D8(void) {
}

void fn_80007210(void) {
    fn_800070DC();
    lbl_8055D348 = fn_802E2C20();
}

extern s32 fn_801E7E3C(void);
extern s32 fn_801E85A4(void);
extern f32 lbl_80560194;
extern f32 lbl_80560198;
extern s32 fn_800057D0(void);
extern s32 fn_80161C18(void);
extern s32 fn_80021258(void);
extern s32 fn_801DF110(void);
extern s32 fn_80161A70(void);
extern s32 fn_80005930(void);
extern s32 fn_8000545C(void);
extern s32 fn_80005460(void);
extern s32 fn_8023D6FC(void);
extern s32 fn_800053CC(void);
extern s32 fn_800217E4(void);
#pragma dont_inline fn_80005B74
#pragma dont_inline fn_80005930
void fn_80007238(void) {
    s32 sp8;
    f32 f0;
    f32 f3;
    s32 mode;
    ((s32 *)lbl_8034EE84)[3] = ((s32 (*)(void))fn_801E7E3C)();
    ((f32 *)lbl_8034EE84)[4] = ((f32 (*)(void))fn_801E7E18)();
    ((s32 *)lbl_8034EE84)[6] = ((s32 (*)(void))fn_801E85A4)();
    fn_80230B5C(&sp8);
    fn_802C8638(&sp8);
    mode = ((s32 *)lbl_8034EE84)[6];
    f0 = lbl_80560194;
    f3 = lbl_80560198;
    if (mode <= 2) goto use_f0;
    goto use_f3;
use_f0:
    f3 = f0;
use_f3:
    fn_802C974C(lbl_80560130, lbl_80560124, f3);
    fn_800057D0();
    fn_80161C18();
    if (fn_80021258() != 0) goto done;
    if (fn_801DF110() != 0) goto done;
    if (fn_80161A70() != 0) goto done;
    fn_80005930();
done:
    fn_80005B6C();
    ((void (*)(s32))fn_80005B70)(0);
    fn_8000545C();
    fn_80005460();
    if (fn_8023D6FC() == 3) fn_800053CC();
    fn_80005B74();
    fn_80011A2C();
    fn_800057BC();
    fn_800217E4();
}
void fn_80007318(void) {
    u8 sp8[0x10];
    u32 *base = (u32 *)lbl_8034EE84;
    void *obj;
    fn_80005C20();
    fn_80230B5C(sp8);
    fn_802C8638(sp8);
    fn_802C974C(lbl_80560130, lbl_80560124, lbl_8056019C);
    base[0x1C / 4] = 0;
    base[0x24 / 4] = fn_801E866C();
    obj = fn_801EA9A0();
    base[0x28 / 4] = (u32)obj;
    base[0x2C / 4] = ((u32 *)obj)[2];
    base[0x30 / 4] = (u32)((u8 *)obj + 0xC);
    *(f32 *)&base[0x10 / 4] = fn_80005FE0(0, 0);
    fn_800057BC();
    fn_80011A2C();
    fn_802C9904();
}

void fn_800073D8(s32 arg0) {
    s32 *p;
    s32 value;
    fn_80005C20();
    p = (s32 *)*(u32 *)((u8 *)lbl_8034EEB8 + 0x5C);
    if (p[2] != 3) {
        p[2] = 3;
        if (fn_80009C84() != 0) {
            value = lbl_8055D348;
        } else {
            value = fn_802E2C20();
        }
        p[3] = value;
    }
    switch (arg0) {
    case 0: p[4] = 0; break;
    case 1: p[4] = 1; break;
    case 2: p[4] = 2; break;
    }
    fn_800066B4(p);
    fn_80011A2C();
}

void fn_80007498(void) {
    fn_80011A50();
}

s32 fn_8000749C(void) {
    if (lbl_8055D340[1] == 0) return 0;
    if (lbl_8055D340[0] == 0) return 0;
    return 1;
}

s32 fn_800074C4(void) {
    s32 result = 0;
    if (lbl_8055D340[1] == 0) return result;
    if (lbl_8055D340[2] == 0) return result;
    result = 1;
    return result;
}

s32 fn_800074EC(s32 arg0) {
    s32 result;
    if (fn_800213DC() != 0) {
        result = 1;
    } else if (fn_801DF238(arg0) != 0) {
        result = 1;
    } else {
        fn_802E4A10();
        result = fn_80137C98();
        return fn_80007554(result, 0x3e8, arg0);
    }
    return result;
}

s32 fn_800075A0(s32 arg0) {
    u32 p = *(u32 *)((u8 *)&lbl_8034EEB8 + arg0 * 0x10 + 0x10);
    if (p == *(u32 *)((u8 *)&lbl_8034EEB8 + 0x58)) return 0;
    if (p == *(u32 *)((u8 *)&lbl_8034EEB8 + 8)) return 0;
    if (p == *(u32 *)((u8 *)&lbl_8034EEB8 + 0x5c)) return 0;
    return 1;
}

s32 fn_800075E4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007624(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007664(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800076A4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800076E4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007724(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007764(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800077A4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern s32 fn_8000561C(void *, void *);
extern void fn_80276DC8(s32);
extern void *fn_801E87A8(void);
extern s32 fn_801CB8FC(void);
extern u8 lbl_8055D340[];
void fn_800077E4(void *arg0) {
    void **base = (void **)lbl_8055D350;
    void *p = (u8 *)arg0 + ((s32 *)base)[7] * 4;
    *(f32 *)((u8 *)p + 4) = ((f32 *)base)[4];
    if (fn_8000561C(p, base)) {
        *(f32 *)((u8 *)arg0 + 0x18) = ((f32 *)base)[4];
        fn_80276DC8(((s32 *)base)[7]);
    }
}

extern f32 fn_80011E44(void);
extern f32 fn_80011E60(void);
extern void fn_8000FBE8(f32, f32, f32);
extern void fn_8000FF88(s32, s32, void *, f32, f32, f32);
extern f32 lbl_805601A0, lbl_805601A4, lbl_805601A8, lbl_805601AC;
extern u8 lbl_802FB6B4[];
#pragma push
#pragma processor 750
void fn_80007898(void *arg0) {
    f32 temp_f30;
    f32 temp_f31;
    if ((((s32 (*)(void))((u32 **)*(u32 *)fn_801B83A0())[0x64 / 4])() != 0) &&
        (((s32 (*)(void))((u32 **)*(u32 *)fn_801B83A0())[0x68 / 4])() != 0) &&
        (((s32 (*)(void *))((u32 **)*(u32 *)arg0)[0x38 / 4])(arg0) == 0)) {
        temp_f30 = fn_80011E44() - lbl_805601A0;
        temp_f31 = lbl_805601A4 + fn_80011E60();
        fn_8000FBE8(temp_f30 - lbl_805601A8, temp_f31, lbl_80560130);
        fn_8000FF88(-1, 0x11, lbl_802FB6B4, lbl_805601AC, temp_f30, temp_f31);
    }
}
#pragma pop
u32 fn_80007974(void) { return 1; }

u8 fn_8000797C(void *arg0) { return *((u8 *)arg0 + 0x14); }

extern u8 lbl_802FB6C0[];
void *fn_80007984(void) {
    return lbl_802FB6C0;
}

s32 fn_80007990(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

u32 fn_800079D0(void) { return 1; }

extern u8 lbl_802FB688[];
void *fn_800079D8(void) {
    return lbl_802FB688;
}

extern u8 lbl_802FB678[];
void *fn_800079E4(void) {
    return lbl_802FB678;
}

void *fn_800079F0(void *arg0, s32 arg1) {
    void **obj;
    if (arg0 != 0) {
        obj = *(void ***)((u8 *)arg0 + 0x1C);
        *(void ***)arg0 = (void **)lbl_802FB478;
        if (obj != 0) {
            if (obj != 0) {
                ((void (*)(void *, s32))(*(void ***)obj)[2])(obj, 1);
            }
        }
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x18));
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x14));
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

s32 fn_80007A84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80007AC4(void *arg0) {
    s32 temp_r3;
    u32 temp_r0;
    ((void (*)(void *))(*(void ***)arg0)[7])(arg0);
    temp_r3 = ((s32 *)fn_801E87A8())[1];
    if (((s32 *)lbl_8055D350)[5] > 1) ((s32 *)arg0)[1] = 3;
    else {
        temp_r0 = temp_r3 + 0xFFE80000;
        if (temp_r0 == 0x302 || temp_r0 == 0x303 || temp_r0 == 0x304 || temp_r0 == 0x201) ((s32 *)arg0)[1] = 2;
        else ((s32 *)arg0)[1] = 1;
    }
    ((s32 *)arg0)[2] = 0;
    ((s32 *)arg0)[4] = 0;
    if (fn_801CB8FC() == 0) ((s32 *)arg0)[4] = 1;
    lbl_8055D340[1] = 1;
}

u32 fn_80007B84(void) { return 1; }

s32 fn_80007B98(s32 arg0, s32 arg1) {
    if (arg1 != 0) return 0;
    return fn_80006580();
}

extern u8 lbl_802FB668[];
void *fn_80007BB0(void) {
    return lbl_802FB668;
}

void fn_80007BBC(void) {
    void **base = (void **)lbl_8055D350;
    if ((*(u32 *)((u8 *)base[2] + 4) & 0x200) == 0) return;
    fn_801B84C0(*(void **)((u8 *)base + 0x1C));
}

extern u8 lbl_802FB630[];
void *fn_80007BDC(void) {
    return lbl_802FB630;
}

void fn_80007BE8(void) {
    return;
}

extern u8 lbl_802FB618[];
void *fn_80007BEC(void) {
    return lbl_802FB618;
}

extern u8 lbl_802FB6D0[];
void *fn_80007BF8(void) {
    return lbl_802FB6D0;
}

extern u8 lbl_802FB604[];
void *fn_80007C04(void) {
    return lbl_802FB604;
}

void fn_80007C10(void *arg0) {
    u8 value = !!fn_801769B8();
    ((u8 *)arg0)[4] = value;
    ((u8 *)arg0)[5] = 0;
}

extern s32 fn_8000C630(s32, s32);
extern s32 fn_801B8848(void);
extern s32 fn_801B87A0(s32, s32);
s32 fn_80007C58(void) {
    return fn_8000C630(0xb, -1);
}

u8 fn_80007C64(void *arg0) {
    return ((u8 *)arg0)[4];
}

void fn_80007C6C(void *arg0) {
    if (fn_801B8848() == 0) {
        ((u8 *)arg0)[5] = 1;
    }
}

s32 fn_80007CA8(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if ((u32)arg2 == 0x3e8) {
        u32 val = (u32)arg3;
        s32 high = val & 0xFFFF;
        return fn_801B87A0((s32)arg1, high);
    }
    return 0;
}

void *fn_80007CC4(void) {
    return lbl_802FB5F0;
}

void fn_80007CD0(void *arg0) {
    ((u8 *)arg0)[4] = 0;
}

u8 fn_80007CDC(void *arg0) {
    return ((u8 *)arg0)[4];
}

s32 fn_80007CE4(void) {
    return fn_8000C630(0xb, -1);
}

void fn_80007CF0(void *arg0) {
    if (fn_801B880C() == 0) {
        ((u8 *)arg0)[4] = 1;
    }
}

s32 fn_80007D2C(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if ((u32)arg2 == 0x3e8) {
        u32 val = (u32)arg3;
        s32 high = val & 0xFFFF;
        return fn_801B87A0((s32)arg1, high);
    }
    return 0;
}

void *fn_80007D48(void) {
    return lbl_802FB5D8;
}

