#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float fabsf(float);
extern void *lbl_8055D350;
extern f32 lbl_80560368, lbl_805603B4, lbl_80560360, lbl_8056039C, lbl_805603A0, lbl_805603A4, lbl_805603A8, lbl_805603AC, lbl_80562068;
extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[], lbl_802FCE88[];
extern u8 lbl_802FCD44[], lbl_802FCD78[];
extern u8 lbl_80558BA0;
extern void fn_80013EDC(void *, s32, void *, void *, f32, f32, f32);
extern void fn_801476C4(void);
extern u8 lbl_80558BBC[], lbl_802FCDB4[];
extern void fn_80015E30(void *, f32);
extern void fn_80015B20(void *, void *, void *);
extern f64 cos(void);
extern f64 sin(f32);
extern void *lbl_803577E0[];
extern u8 lbl_802FCBEC[], lbl_802FCBF8[], lbl_802FCBC8[];
extern s32 fn_802C9A58(void);
extern void fn_80013BD0(void *, s32, s32, s32);
typedef struct { void *vtable; s32 field4; } VtblObj;
extern f32 lbl_80560360, lbl_80560368, lbl_8056036C, lbl_80560370, lbl_80560374, lbl_80560398;
extern f32 fn_801E7E24(void);
extern f32 fn_801E7E24(void);
extern f32 lbl_80560360, lbl_80560364, lbl_80560398;
extern u8 lbl_802FCB98[];
extern u8 lbl_802FCE18[];
extern void fn_80130FCC(void *, s32, s32);
extern void fn_801473F8(void *, void *, ...);
extern char lbl_80558BA4; extern char lbl_80558BA8[], lbl_80558BAC[], lbl_80558BB4[];
extern f32 lbl_805603B8;
void fn_80014B9C(void *);
s32 fn_800151DC(void *);
void fn_800154B8(void);
void fn_80015658(void *);
s32 fn_80016214(void);
void fn_80015F30(void *);
void fn_80148134(f32 *, f32 *, s32, f32, f32);
#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80013BD0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(void *);
    };
    char first[20];
    char second[20];
    u8 *base = lbl_802FCB98;
    ((Obj *)arg0)->v3(base + 0);
    fn_801476C4();
    ((Obj *)arg0)->v3(base + 0xC);
    fn_801476C4();
    fn_80130FCC(first, 20, arg1);
    fn_801473F8(arg0, base + 0x1C, first);
    if (arg3) {
        fn_80130FCC(second, 20, arg2);
        fn_801473F8(arg0, base + 0x30, second);
    }
}
#pragma pop
void fn_80013C98(f32 *arg0) {
    f32 value;
    if (fn_801E7E24() > lbl_80560360) {
        value = fn_801E7E24() / lbl_80560364;
        value = *arg0 + value;
        value = value < lbl_80560368 ? value : lbl_80560368;
        *arg0 = value;
    }
}

void fn_80013CFC(f32 *arg0) {
    f32 value;
    if (fn_801E7E24() > lbl_80560360) {
        value = fn_801E7E24() / lbl_80560364;
        value = *arg0 - value;
        value = value > lbl_80560360 ? value : lbl_80560360;
        *arg0 = value;
    }
}

f32 fn_80013D60(f32 x) {
    f32 y;
    if (lbl_80560360 != x) {
        if (lbl_80560368 == x) {
            return x;
        }
        y = lbl_8056036C;
        if (x < y) {
        } else if (x > lbl_80560368) {
            y = lbl_80560368;
        } else if (x > lbl_80560360) {
            y = (x * (lbl_80560370 * x * x)) + (lbl_80560374 * x * x);
        } else {
            y = (x * (lbl_80560370 * x * x)) - (lbl_80560374 * x * x);
        }
        return y;
    }
    return x;
}

#pragma scheduling invalid_target
void fn_80013DF0(s32 arg0) {
    void *obj = *(void **)((u8 *)lbl_803577E0[arg0] + 0x50);
    register void **vtable = *(void ***)obj;
    register void *method = vtable[3];
    ((void (*)(void *, void *))method)(obj, lbl_802FCBEC);
}
#pragma push
#pragma cplusplus on
extern "C" void fn_80013E1C(s32 arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v3(void *);
    };
    if (fn_802C9A58()) {
        ((Obj *)*(void **)((u8 *)lbl_803577E0[arg0] + 0x50))->v3(lbl_802FCBF8);
    } else {
        ((Obj *)*(void **)((u8 *)lbl_803577E0[arg0] + 0x50))->v3(lbl_802FCBC8);
    }
}
#pragma pop
void fn_80013EAC(s32 arg0, s32 arg1, s32 arg2) {
    void *obj = *(void **)((u8 *)lbl_803577E0[arg0] + 0x50);
    s32 value = 1;
    if (arg1 >= 1) {
        value = arg1;
    }
    fn_80013BD0(obj, value, arg2, 0);
}
#pragma scheduling on
extern u8 lbl_80558B80;
extern void *fn_8023512C(void *);
extern void *fn_802CAC28(void *, s32);
extern void fn_801333E8(s32, void *, void *);
extern void *fn_80019C68(s32);
extern s32 fn_800167F4(void);
extern void *fn_80145E70(void *);
#pragma push
#pragma cplusplus on
extern "C" void *fn_80014524(void *arg0, s32 arg1) {
 class Obj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); };
 u8 *obj=(u8 *)arg0; u8 *base=lbl_802FCB98;
 *(void **)obj=lbl_802FCE18; lbl_803577E0[arg1]=arg0; obj[8]=0;
 *(void **)(obj+0x34)=fn_8023512C(base+0x130);
 *(void **)(obj+0x38)=fn_8023512C(base+0x140);
 *(void **)(obj+0x3C)=fn_8023512C(base+0x14C);
 *(void **)(obj+0x40)=fn_8023512C(base+0x158);
 *(void **)(obj+0x44)=fn_802CAC28(base+0x168,0);
 *(s32 *)(obj+4)=arg1; obj[0x4C]=0;
 fn_801333E8(5,&lbl_80558B80,obj+0x4C);
 *(void **)(obj+0x48)=fn_80019C68(arg1);
 if(fn_800167F4()==1) *(void **)(obj+0x50)=fn_80145E70(base+0x178);
 else *(void **)(obj+0x50)=fn_80145E70(base+0x184);
 ((Obj *)obj)->v5(); return arg0;
}
#pragma pop

void fn_80014638(void *arg0) {
    f32 zero;
    s32 a;
    f32 one;
    s32 six;
    zero = lbl_80560368;
    a = 0;
    one = lbl_80560398;
    six = 6;
    *(s32 *)((u8 *)arg0 + 0x14) = six;
    *(f32 *)((u8 *)arg0 + 0x1C) = one;
    *(u8 *)((u8 *)arg0 + 0x20) = a;
    *(f32 *)((u8 *)arg0 + 0x2C) = zero;
    *(f32 *)((u8 *)arg0 + 0x28) = zero;
    *(s32 *)((u8 *)arg0 + 0x24) = a;
}

extern u8 lbl_802FCE18[];
extern void fn_8001A04C(void *);
extern void fn_802CAC54(s32);
extern void fn_80235380(void *);
extern void fn_80128668(void *);
#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void *fn_80014664(void *arg0, s32 arg1) {
    class Obj {
    public:
        virtual void v0(int);
    };
    void *obj;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_802FCE18;
        lbl_803577E0[*(s32 *)((u8 *)arg0 + 4)] = 0;
        obj = *(void **)((u8 *)arg0 + 0x50);
        if (obj != 0) {
            ((Obj *)obj)->v0(1);
        }
        fn_8001A04C(*(void **)((u8 *)arg0 + 0x48));
        *(void **)((u8 *)arg0 + 0x48) = 0;
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x44));
        *(s32 *)((u8 *)arg0 + 0x44) = -2;
        fn_80235380(*(void **)((u8 *)arg0 + 0x40));
        *(void **)((u8 *)arg0 + 0x40) = 0;
        fn_80235380(*(void **)((u8 *)arg0 + 0x3C));
        *(void **)((u8 *)arg0 + 0x3C) = 0;
        fn_80235380(*(void **)((u8 *)arg0 + 0x34));
        *(void **)((u8 *)arg0 + 0x34) = 0;
        fn_80235380(*(void **)((u8 *)arg0 + 0x38));
        *(void **)((u8 *)arg0 + 0x38) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop

extern int __cntlzw(unsigned int);
void fn_80014750(void *arg0) {
    void *manager;
    void *state;
    void *input;
    f32 value;
    s32 result;
    s32 pressed;
    if (*(u8 *)((u8 *)arg0 + 8)) {
        manager = lbl_8055D350;
        state = *(void **)((u8 *)manager + 0xC);
        if (*(f32 *)((u8 *)manager + 0x10) - *(f32 *)((u8 *)state + 0xC) <
            lbl_80562068 - lbl_8056039C)
            fn_8000C630(0x17, -1);
    } else {
        manager = lbl_8055D350;
        state = *(void **)((u8 *)manager + 0xC);
        value = *(f32 *)((u8 *)state + 0x10);
        result = 0;
        if (value > lbl_8056039C) {
            if (value < lbl_805603A0)
                goto set_result;
        }
        if (value > lbl_805603A4) {
        set_result:
            result = 1;
        }
        input = *(void **)((u8 *)manager + 0x2C);
        pressed = (u32)__cntlzw(*(u32 *)((u8 *)input + 0x2C0) & 0x20) >> 5;
        result = result && pressed;
        if (result != 0)
            fn_8000C630(0x17, -1);
    }
}

void fn_8001480C(void *arg0) {
 *(f32 *)((u8 *)arg0+0x10)=*(f32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0x2C)+0x4C);
}

#pragma dont_inline on
extern float __fabsf(float);
extern double __fabs(double);
#pragma scheduling invalid_target
void fn_80014820(void *arg0) {
    void *data;
    f32 current;
    f32 divisor;
    f32 value34;
    f32 scale;
    f32 factor;
    f32 target;
    f32 delta;
    f32 amount;
    f32 cap;
    data = lbl_8055D350;
    current = *(f32 *)((u8 *)arg0 + 0x10);
    data = *(void **)((u8 *)data + 0x2C);
    divisor = lbl_805603A0;
    value34 = *(f32 *)((u8 *)data + 0x34);
    scale = lbl_805603A8;
    *(f32 *)((u8 *)arg0 + 0xC) = value34;
    factor = lbl_80560368;
    data = *(void **)((u8 *)lbl_8055D350 + 0x2C);
    target = *(f32 *)((u8 *)data + 0x4C);
    delta = current - target;
    amount = scale * ((f32)__fabs((f64)delta) / divisor);
    if (factor < amount) {
        factor = amount;
    } else {
        factor = factor;
    }
    cap = lbl_805603AC;
    if (factor > cap) {
        factor = cap;
    } else {
        factor = factor;
    }
    *(f32 *)((u8 *)arg0 + 0x10) =
        *(f32 *)((u8 *)arg0 + 0x10) +
        factor * (*(f32 *)((u8 *)data + 0x4C) -
                  *(f32 *)((u8 *)arg0 + 0x10));
}
#pragma scheduling on

void fn_80014A98(void *arg0) {
    void *p;
    f32 selected;
    p = *(void **)((u8 *)lbl_8055D350 + 0x30);
    if (*(s32 *)((u8 *)p + 0x24) == 3)
        selected = *(f32 *)((u8 *)p + 0x1C);
    else
        selected = *(f32 *)((u8 *)p + 0x14);
    ((void (*)(void *, void *, s32, void *, void *, f32, f32, f32))fn_80013EDC)(
        arg0, lbl_802FCD44, 0, lbl_802FCD78, &lbl_80558BA0,
        *(f32 *)((u8 *)arg0 + 0x2C), selected, lbl_80560360);
}

s32 fn_80014ADC(void) { return 0; }

s32 fn_80014AE4(void) {
 s32 var_r6=0,var_r7=0,var_r8=1,var_r9=1;
 void *temp_r11;
 if (*(s32 *)((u8 *)lbl_8055D350+4)==1 && *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0x30)+0x10)>0) var_r6=1;
 temp_r11=*(void **)((u8 *)lbl_8055D350+0x30);
 if (!(*(f32 *)((u8 *)temp_r11+0x1C)>lbl_80560368) &&
     *(s32 *)((u8 *)temp_r11+0x10)!=*(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0xC)+8)) var_r9=0;
 if (var_r9==0 && var_r6==0) var_r8=0;
 if (var_r8!=0 && *(f32 *)((u8 *)temp_r11+0x14)<lbl_805603B4) var_r7=1;
 if (var_r7!=0) return 1;
 if (*(s32 *)((u8 *)temp_r11+0x10)<=*(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0xC)+8)) return 0;
 return 1;
}

extern void fn_80013C98(f32 *);
extern void fn_80013CFC(f32 *);
extern void fn_800148A0(void *);
extern void fn_80014A98(void *);
extern s32 fn_80014ADC(void);
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_80014B9C(void *arg0) {
    struct Obj {
        u8 pad0[0x24];
        s32 state;
        u8 pad28[4];
        f32 value;
    };
    struct Obj *obj = (struct Obj *)arg0;
    s32 state, reverse, result;

    reverse = fn_80014ADC();
    result = ((s32 (*)(void *))fn_80014AE4)(obj);
    state = obj->state;
    if (state == 0) {
        if (reverse != 0 || result != 0) {
            s32 newState;
            fn_80013CFC(&obj->value);
            if (reverse != 0) fn_80014A98(obj);
            else fn_800148A0(obj);
            if (lbl_80560360 == obj->value) {
                newState = 1;
                if (reverse != 0) newState = 2;
                obj->state = newState;
            }
        } else {
            obj->value = lbl_80560368;
        }
    } else if (state == 2) {
        if (reverse != 0) {
            if (obj->value > lbl_80560360) fn_80013CFC(&obj->value);
            fn_80014A98(obj);
        } else {
            fn_80013C98(&obj->value);
            fn_80014A98(obj);
            if (lbl_80560368 == obj->value) obj->state = 0;
        }
    } else {
        if (result != 0) {
            if (obj->value > lbl_80560360) fn_80013CFC(&obj->value);
            fn_800148A0(obj);
        } else {
            fn_80013C98(&obj->value);
            fn_800148A0(obj);
            if (lbl_80560368 == obj->value) obj->state = 0;
        }
    }
}
#pragma pop

extern s32 fn_8000D75C(void);
extern void fn_8000FBE4(void);
extern void fn_80010F38(void *, s32, s32, s32, f32);
extern void fn_800111A4(void *, s32, s32, s32, s32, f32);
extern void fn_80014820(void *);
extern void fn_80015364(void *);
extern void fn_8001A1F4(s32, f32, f32, f32, f32);
extern void fn_8001DF84(s32);
extern s32 fn_80130FE0(s32);
extern s32 fn_80144F2C(void);
extern void *fn_801B83A0(void);
extern void fn_801D490C(void);
extern void fn_801DF93C(s32);
extern s32 fn_801E7E34(void);
extern s32 fn_801E866C(s32);
extern void fn_801E87A8(void);
extern s32 fn_801E89C8(s32);
extern s32 fn_801E89EC(void);
extern s32 fn_8026B0C0(s32);
extern s32 fn_8027AA48(void *, f32, f32);
#pragma push
#pragma use_lmw_stmw off
void fn_80014D04(void *arg0) {
    u8 *base = lbl_802FCB98;
    s32 flag;
    f32 spC, sp8;
    void *obj;
    if (*(s32 *)((u8 *)lbl_8055D350 + 0x20) != 0) {
        if (*(s32 *)((u8 *)lbl_8055D350 + 0x24) != *(s32 *)((u8 *)arg0 + 0x18)) {
            ((void (*)(void *))(*(void ***)arg0)[5])(arg0);
        }
        *(s32 *)((u8 *)arg0 + 0x18) = *(s32 *)((u8 *)lbl_8055D350 + 0x24);
        if (fn_8026B0C0(*(s32 *)((u8 *)lbl_8055D350 + 0x1C)) != 0) {
            obj = fn_801B83A0();
            if (((s32 (*)(void *))(*(void ***)obj)[22])(obj) != 0) {
                fn_801DF93C(*(s32 *)((u8 *)lbl_8055D350 + 0x1C));
            }
        } else {
            s32 x, y, z;
            if (*(s32 *)((u8 *)lbl_8055D350 + 0x1C) == 0) {
                fn_8000FBE4();
            }
            flag = 0;
            if (*(s32 *)((u8 *)lbl_8055D350 + 0x24) == fn_801E866C(*(s32 *)((u8 *)lbl_8055D350 + 0x1C))) {
                if (fn_801E89C8(*(s32 *)((u8 *)lbl_8055D350 + 0x1C)) != 0) {
                    flag = 1;
                }
            }
            fn_801E87A8();
            if (flag == 0 && (*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 8)) {
                if (fn_8000D75C() == 0) {
                    fn_80014820(arg0);
                }
                if (*(u32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x8) + 0x4) & 0x80000) {
                    fn_80015F30(arg0);
                    fn_8001DF84(*(s32 *)((u8 *)lbl_8055D350 + 0x24));
                }
            }
            if (*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 2) {
                fn_801473F8(*(void **)((u8 *)arg0 + 0x50), base + 0x1F0, &lbl_80558BA4,
                           *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x30) + 0x4));
                fn_801473F8(*(void **)((u8 *)arg0 + 0x50), base + 0x200, lbl_80558BA8,
                           fn_80130FE0(*(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x30) + 0x4)));
            }
            if (*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 1) {
                s32 a = 1;
                s32 b;
                s32 t = *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x30) + 0x10);
                if (t > 1) a = t;
                b = *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0xC) + 0x8);
                if (a >= b) b = a;
                fn_80013BD0(*(void **)((u8 *)arg0 + 0x50), b, 1, 0);
            }
            if (*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 0x10) {
                obj = *(void **)((u8 *)lbl_8055D350 + 0x2C);
                x = (s32)(lbl_805603B8 * (lbl_80560368 - *(f32 *)((u8 *)obj + 0x28C)));
                y = (s32)(lbl_805603B8 * (lbl_80560368 - *(f32 *)((u8 *)obj + 0x290)));
                z = (s32)(lbl_805603B8 * (lbl_80560368 - *(f32 *)((u8 *)obj + 0x294)));
                if (fn_8027AA48(obj, lbl_805603B8, lbl_80560368) != 0) {
                    fn_800111A4(lbl_80558BAC, x, y, z, 7, lbl_80560368);
                } else {
                    fn_80010F38(lbl_80558BAC, x, y, 6, lbl_80560368);
                }
            }
            if (*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 0x20) {
                u8 *p;
                s32 i;
                f32 f30 = lbl_80560368;
                f32 f31 = lbl_805603B8;
                i = 0;
                p = (u8 *)(fn_801E7E34() + *(s32 *)((u8 *)lbl_8055D350 + 0x1C) * 0xE0) + 0x78;
                do {
                    if (*(s32 *)p >= 0) {
                        s32 v = *(s32 *)(p + 0x14);
                        if (v > 9 && v < 0xD) {
                            fn_80010F38(lbl_80558BB4, (s32)(f31 * (f30 - *(f32 *)(p + 8))),
                                        (s32)(f31 * (f30 - *(f32 *)(p + 0xC))), 8, f30);
                        } else {
                            fn_80010F38(lbl_80558BAC, (s32)(f31 * (f30 - *(f32 *)(p + 8))),
                                        (s32)(f31 * (f30 - *(f32 *)(p + 0xC))), 8, f30);
                        }
                    }
                    i += 1;
                    p += 0x18;
                } while (i < 4);
            }
            if ((*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 0x40) && *(s32 *)((u8 *)lbl_8055D350 + 0x18) < 3) {
                fn_80014B9C(arg0);
            }
            flag = 0;
            if ((*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 0x600) && fn_800151DC(arg0) != 0) {
                flag = 1;
            }
            if (fn_801E89EC() == 1 && flag == 0) {
                fn_80016214();
            }
            if ((*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 0x2000) && *(s32 *)((u8 *)lbl_8055D350 + 0x18) == 1) {
                fn_800154B8();
            }
            if ((*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 0x4000) && fn_80144F2C() != 0) {
                fn_80015658(arg0);
            }
            if (*(u32 *)((u8 *)lbl_8055D350 + 0x20) & 0x1000) {
                if (*(s32 *)((u8 *)arg0 + 0x48) != 0) {
                    obj = *(void **)((u8 *)arg0 + 0x50);
                    obj = ((void *(*)(void *, void *))(*(void ***)obj)[5])(obj, base + 0x210);
                    if (obj != 0) {
                        fn_80148134(&spC, &sp8, *(s32 *)((u8 *)obj + 0xC),
                                    *(f32 *)((u8 *)obj + 4), *(f32 *)((u8 *)obj + 8));
                        fn_8001A1F4(*(s32 *)((u8 *)arg0 + 0x48), spC, sp8,
                                    *(f32 *)((u8 *)obj + 0x10), *(f32 *)((u8 *)obj + 0x14));
                    }
                } else if (*(s32 *)((u8 *)lbl_8055D350 + 0x1C) == 0) {
                    fn_80015364(arg0);
                }
            }
            fn_801D490C();
        }
    }
}
#pragma pop

s32 fn_800151D4(void) { return 1; }

s32 fn_800151DC(void *arg0) {
    s32 result;
    void *manager = lbl_8055D350;
    void *obj;
    if ((*(u32 *)((u8 *)manager + 0x20) & 0x400) &&
        (*(u32 *)((u8 *)*(void **)((u8 *)manager + 0x2C) + 0x2C0) & 0x10)) {
        obj = *(void **)((u8 *)arg0 + 0x50);
        (*(void (**)(void *, void *))((u8 *)*(void ***)obj + 0xC))(obj, lbl_80558BBC);
        fn_801476C4();
    }
    manager = lbl_8055D350;
    result = 0;
    if ((*(u32 *)((u8 *)*(void **)((u8 *)manager + 0x30)) & 4) && (*(u32 *)((u8 *)manager + 0x20) & 0x200)) result = 1;
    if (result) {
        obj = *(void **)((u8 *)arg0 + 0x50);
        (*(void (**)(void *, void *))((u8 *)*(void ***)obj + 0xC))(obj, lbl_802FCDB4);
        fn_801476C4();
    }
    return result;
}

extern f32 fn_80235EF0(void *, s32);
extern f32 fn_80235F64(void *, s32);
extern void fn_80010E94(void *, s32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_8001529C(void *arg0, u32 arg1, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 width, height, half, left, y, bottom, x;
    s32 negative;
    s32 positive = (arg1 >> 31) ^ 1;
    width = fn_80235EF0(*(void **)((u8 *)arg0 + 0x38), 0);
    height = fn_80235F64(*(void **)((u8 *)arg0 + 0x38), 0);
    negative = positive == 0;
    half = width * lbl_805603BC;
    left = b - half;
    bottom = c - e;
    x = left + a * (((b + d) - half) - left);
    y = c + height;
    fn_80010E94(*(void **)((u8 *)arg0 + 0x38), negative,
        x, positive ? y : bottom, lbl_80560360, lbl_80560360);
}

#pragma dont_inline on
#pragma use_lmw_stmw off
extern void fn_80010B80(s32, f32, f32, f32, f32);
extern f32 fn_80011E60(void);
extern f32 fn_8013672C(void);
extern void *fn_801E7E3C(void);
extern s32 fn_801EA994();
extern void *fn_801EA9A0(s32);
extern f32 lbl_805603C0, lbl_805603C4, lbl_805603C8;
extern f64 lbl_80560390;
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_80015364(void *arg0) {
    f32 selected;
    f32 delta;
    f32 total;
    s32 frameCount;
    s32 activeCount;
    s32 index;
    s32 value;
    s32 resultIndex;
    void *entry;
    void *record;
    f32 amount;
    if (*(s32 *)((u8 *)lbl_8055D350 + 0x18) == 1) {
        selected = lbl_805603C0;
    } else {
        selected = fn_80011E60();
    }
    activeCount = 0;
    fn_80010B80(0xC80000C8, lbl_805603C4, selected, lbl_805603C8, lbl_805603B4);
    delta = fn_8013672C();
    frameCount = *(s32 *)((u8 *)fn_801E7E3C() + 8);
    index = 0;
    total = delta * (f32)frameCount;
    while (index < fn_801EA994()) {
        record = fn_801EA9A0(index);
        entry = *(void **)((u8 *)record + 8);
        amount = lbl_80560360;
        record = fn_801EA9A0(index);
        value = *(s32 *)((u8 *)record + 0x1C);
        if (value > 0) {
            amount = (*(f32 *)((u8 *)entry + 0x2C8) +
                      (f32)(value - 1) * delta) / total;
        }
        record = fn_801EA9A0(index);
        if (*(u8 *)record != 0) {
            resultIndex = activeCount;
            activeCount++;
        } else {
            resultIndex = -1;
        }
        fn_8001529C(arg0, (u32)resultIndex, amount, lbl_805603C4,
                    selected, lbl_805603C8, lbl_805603B4);
        index++;
    }
}
extern s32 fn_801EA994(void);
extern s32 fn_801EA9B0(s32);
extern void fn_8000FF88(s32, s32, void *, s32, s32, f32, f32, f32, ...);
extern f32 lbl_80560368, lbl_80560384, lbl_805603CC, lbl_805603D0;
extern char lbl_80558BC4;
void fn_800154B8(void) {
    /* Fix note: retain the object pointer through edge-count setup, then keep the masked right count in r31. */
    s32 current;
    register s32 *base;
    s32 first, left, right, i;
    f32 y, step;
    current = fn_801EA994();
    base = *(s32 **)((char *)lbl_8055D350 + 0x30);
    left = 2;
    right = 2;
    first = base[1];
    if (first <= 2) {
        left = first - 1;
        right = 2 - left;
        right = right + 2;
    } else if (first > current - 2) {
        left = first - (current - 2);
        left = left + 2;
        right = current - first;
    }
    y = lbl_805603CC;
    i = 1;
    if (first - (left & ~(left >> 31)) >= 1)
        i = first - (left & ~(left >> 31));
    right = right & ~(right >> 31);
    step = lbl_80560384;
    for (; i < *(s32 *)(*(u8 **)((u8 *)lbl_8055D350 + 0x30) + 4); ++i) {
        fn_8000FF88(-1, 9, &lbl_80558BC4, i, fn_801EA9B0(i - 1) + 0x48, lbl_80560368, lbl_805603D0, y);
        y -= step;
    }
    fn_8000FF88(-0x100, 9, &lbl_80558BC4, 0,
                *(s32 *)((u8 *)lbl_8055D350 + 0x28) + 0x48,
                lbl_80560368, lbl_805603D0, y);
    step = lbl_80560384;
    y -= step;
    i = *(s32 *)(*(u8 **)((u8 *)lbl_8055D350 + 0x30) + 4) + 1;
    do {
        fn_8000FF88(-1, 9, &lbl_80558BC4, i, fn_801EA9B0(i - 1) + 0x48, lbl_80560368, lbl_805603D0, y);
        y -= step;
        ++i;
    } while (i <= *(s32 *)(*(u8 **)((u8 *)lbl_8055D350 + 0x30) + 4) + right &&
             i <= fn_801EA994());
}

extern s32 fn_80144F34(void *, s32, void *);
extern f32 fn_80011DEC(void *);
extern f32 fn_80011DC0(void *);
extern void fn_802354A0(void *, s32, s32, f32, f32, f32, f32, f32);
extern f32 lbl_805603D4, lbl_805603D8, lbl_805603DC, lbl_805603E0, lbl_805603E4;
extern f32 lbl_80560360, lbl_805603A0;
#pragma push
#pragma use_lmw_stmw on
void fn_80015658(void *arg0) {
    char sp9;
    char sp8;
    f32 temp_f31;
    f32 temp_f30;
    s32 temp_r31;
    s32 temp_r30;

    temp_r31 = fn_80144F34(*(void **)((u8 *)lbl_8055D350 + 0x24), 0, &sp9);
    temp_r30 = fn_80144F34(*(void **)((u8 *)lbl_8055D350 + 0x24), 1, &sp8);
    temp_f31 = fn_80011DEC(*(void **)((u8 *)lbl_8055D350 + 0x1C)) - lbl_805603D4;
    temp_f30 = fn_80011DC0(*(void **)((u8 *)lbl_8055D350 + 0x1C)) - lbl_805603D8;
    fn_802354A0(*(void **)((u8 *)arg0 + 0x3C), 3, -1, temp_f31, temp_f30, lbl_80560360, lbl_805603D4, lbl_805603DC);
    ((void (*)(s32, s32, void *, s32, ...))fn_8000FF88)(-0x100, 0xA, &lbl_80558BA4, temp_r31, lbl_805603E0, temp_f31 - lbl_805603A0, temp_f30);
    ((void (*)(s32, s32, void *, s32, ...))fn_8000FF88)(-0x100, 0xA, &lbl_80558BA4, temp_r30, lbl_805603E0, temp_f31 - lbl_805603A0, temp_f30 - lbl_805603E4);
}

void fn_80015AA0(void *, f32);
void fn_80015EB0(void *, f32);
#pragma push
#pragma scheduling invalid_target
void fn_80015A20(void *arg0, volatile f32 *arg1) {
    f32 matrix[9];
    f32 angle1 = arg1[1];
    f32 angle0 = arg1[0];
    f32 angle2 = arg1[2];
    fn_80015EB0(arg0, angle1);
    fn_80015E30(matrix, angle0);
    fn_80015B20(arg0, matrix, arg0);
    fn_80015AA0(matrix, angle2);
    fn_80015B20(arg0, matrix, arg0);
}
#pragma pop
extern void fn_801476C4(void);
extern u8 lbl_80558BBC[];
extern u8 lbl_802FCDB4[];
extern void fn_80015E30(void *, f32);
extern void fn_80015B20(void *, void *, void *);
extern f64 cos(void);
extern f64 sin(f32);
#pragma scheduling invalid_target
void fn_80015AA0(void *arg0, f32 angle) {
    f32 c;
    f32 s;
    f32 zero;
    f32 neg;
    f32 *m;
    c = (f32)cos();
    s = (f32)sin(angle);
    zero = lbl_80560360;
    m = (f32 *)arg0;
    m[0] = c;
    neg = -s;
    m[1] = s;
    m[2] = zero;
    m[3] = neg;
    m[4] = c;
    m[5] = zero;
    m[6] = zero;
    m[7] = zero;
    m[8] = lbl_80560368;
}
#pragma scheduling on
void fn_80015B20(void *arg0, void *arg1, void *arg2) {
    f32 *out = (f32 *)arg0;
    f32 *a = (f32 *)arg1;
    f32 *b = (f32 *)arg2;

    if ((arg0 == arg1) || (arg0 == arg2)) {
        register f32 temp_f10, temp_f1, temp_f19, temp_f12, temp_f3, temp_f9, temp_f0, temp_f20;
        register f32 temp_f11, temp_f18, temp_f7, temp_f6, temp_f1_2, temp_f0_2, temp_f2;
        register f32 temp_f4, temp_f5, temp_f8;

        temp_f10 = a[1]; temp_f1 = b[3]; temp_f19 = a[4]; temp_f12 = b[4];
        temp_f3 = a[7]; temp_f9 = a[0]; temp_f0 = b[0]; temp_f20 = a[3];
        temp_f11 = b[1]; temp_f18 = a[6]; temp_f7 = b[5]; temp_f6 = b[2];
        temp_f1_2 = a[2]; temp_f0_2 = b[6]; temp_f2 = a[5]; temp_f4 = a[8];
        temp_f5 = b[7]; temp_f8 = b[8];

        out[0] = (temp_f0_2 * temp_f1_2) + ((temp_f0 * temp_f9) + (temp_f1 * temp_f10));
        out[3] = (temp_f0_2 * temp_f2) + ((temp_f0 * temp_f20) + (temp_f1 * temp_f19));
        out[6] = (temp_f0_2 * temp_f4) + ((temp_f0 * temp_f18) + (temp_f1 * temp_f3));
        out[1] = (temp_f5 * temp_f1_2) + ((temp_f11 * temp_f9) + (temp_f12 * temp_f10));
        out[4] = (temp_f5 * temp_f2) + ((temp_f11 * temp_f20) + (temp_f12 * temp_f19));
        out[7] = (temp_f5 * temp_f4) + ((temp_f11 * temp_f18) + (temp_f12 * temp_f3));
        out[2] = (temp_f8 * temp_f1_2) + ((temp_f6 * temp_f9) + (temp_f7 * temp_f10));
        out[5] = (temp_f8 * temp_f2) + ((temp_f6 * temp_f20) + (temp_f7 * temp_f19));
        out[8] = (temp_f8 * temp_f4) + ((temp_f6 * temp_f18) + (temp_f7 * temp_f3));
    } else {
        out[0] = (b[6] * a[2]) + ((b[0] * a[0]) + (b[3] * a[1]));
        out[3] = (b[7] * a[2]) + ((b[1] * a[0]) + (b[4] * a[1]));
        out[6] = (b[8] * a[2]) + ((b[2] * a[0]) + (b[5] * a[1]));
        out[1] = (b[6] * a[5]) + ((b[0] * a[3]) + (b[3] * a[4]));
        out[4] = (b[7] * a[5]) + ((b[1] * a[3]) + (b[4] * a[4]));
        out[7] = (b[8] * a[5]) + ((b[2] * a[3]) + (b[5] * a[4]));
        out[2] = (b[6] * a[8]) + ((b[0] * a[6]) + (b[3] * a[7]));
        out[5] = (b[7] * a[8]) + ((b[1] * a[6]) + (b[3] * a[7]));
        out[8] = (b[8] * a[8]) + ((b[2] * a[6]) + (b[5] * a[7]));
    }
}
#pragma push
#pragma scheduling invalid_target
void fn_80015E30(void *arg0, f32 angle) {
    f32 negative;
    f32 zero;
    f32 one;
    f32 sine;
    f32 cosine;
    cosine = (f32)cos();
    sine = (f32)sin(angle);
    zero = lbl_80560360;
    one = lbl_80560368;
    *(f32 *)((u8 *)arg0 + 4) = zero;
    negative = -sine;
    *(f32 *)((u8 *)arg0 + 0) = one;
    *(f32 *)((u8 *)arg0 + 8) = zero;
    *(f32 *)((u8 *)arg0 + 0xC) = zero;
    *(f32 *)((u8 *)arg0 + 0x10) = cosine;
    *(f32 *)((u8 *)arg0 + 0x14) = sine;
    *(f32 *)((u8 *)arg0 + 0x18) = zero;
    *(f32 *)((u8 *)arg0 + 0x1C) = negative;
    *(f32 *)((u8 *)arg0 + 0x20) = cosine;
}
#pragma pop
void fn_80015EB0(void *arg0, f32 angle) {
    f32 c;
    f32 s;
    f32 zero;
    f32 neg;
    f32 *m;
    c = (f32)cos();
    s = (f32)sin(angle);
    zero = lbl_80560360;
    m = (f32 *)arg0;
    m[0] = c;
    neg = -s;
    m[1] = zero;
    m[2] = neg;
    m[3] = zero;
    m[4] = lbl_80560368;
    m[5] = zero;
    m[6] = s;
    m[7] = zero;
    m[8] = c;
}

extern f32 lbl_805603F8,lbl_805603FC,lbl_80560408,lbl_8056040C,lbl_80560410,lbl_80560414;
extern void fn_801478E0(void*,void*,s32,s32);
extern void fn_80147F30(s32,s32,s32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void fn_80148134(f32*,f32*,s32,f32,f32);
extern void fn_80015770(void*,f32,f32,f32,f32,f32);
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_80015F30(void* arg0) {
 struct Desc { s32 a; f32 x,y; s32 d; f32 w,h; s32 g,k; };
 class Obj { public:
 virtual void v0(); virtual Desc* get(void*); virtual void v2(); virtual Desc* find(void*);
 };
 struct Desc copy;
 f32 x,y;
 f32 value;
 f32 low;
 f32 high;
 f64 period=lbl_80560400;
 u8* base=lbl_802FCB98;
 low=lbl_805603F8;
 high=lbl_805603FC;
 value=*(f32*)((u8*)*(void**)((u8*)lbl_8055D350+0x2c)+0x2a8);
 s32 positive=(f32)((f64(*)(void*,f32,f64))fn_8002EFB4)(*(void**)((u8*)lbl_8055D350+0x2c),*(f32*)((u8*)lbl_8055D350+0x10),period)>lbl_805603BC;
 s32 flag=0;
 void* obj;
 struct Desc* desc;
 if(value>lbl_80560408 && positive) flag=1;
 fn_801478E0(*(void**)((u8*)arg0+0x50),base+0x228,*(s32*)((u8*)arg0+0x40),3);
 obj=*(void**)((u8*)arg0+0x50);
 desc=((Obj*)obj)->find(base+0x234);
 if(desc) {
  if(flag || *(f32*)((u8*)*(void**)((u8*)lbl_8055D350+0x2c)+0x2c4)>lbl_80560360) {
   f32 a=lbl_8056040C*value;
   f32 b;
   if(a<lbl_80560360) b=a-lbl_805603BC; else b=lbl_805603BC+a;
   f32 scale=(high-low)/lbl_8056040C;
   ((void(*)(f32,f32,f32,f32,s32,s32,s32,f32,f32,f32,f32,f32,f32))fn_80147F30)(desc->x,desc->y,desc->w,desc->h,desc->g,(s32)b,*(s32*)((u8*)arg0+0x44),low,scale,lbl_805603BC,lbl_80560360,lbl_80560410,lbl_80560414);
  } else {
   f32 a=lbl_8056040C*value;
   f32 b;
   if(a<lbl_80560360) b=a-lbl_805603BC; else b=lbl_805603BC+a;
   f32 scale=(high-low)/lbl_8056040C;
   ((void(*)(f32,f32,f32,f32,s32,s32,s32,f32,f32,f32,f32,f32,f32))fn_80147F30)(desc->x,desc->y,desc->w,desc->h,desc->g,(s32)b,*(s32*)((u8*)arg0+0x44),low,scale,lbl_80560360,lbl_80560360,lbl_80560414,lbl_80560414);
  }
 }
 fn_801478E0(*(void**)((u8*)arg0+0x50),base+0x240,*(s32*)((u8*)arg0+0x40),0);
 obj=*(void**)((u8*)arg0+0x50);
 desc=((Obj*)obj)->find(base+0x24c);
 if(desc) {
  high=low+value*(high-low);
  fn_80148134(&x,&y,desc->d,desc->x,desc->y);
  fn_80015770(arg0,x,y,desc->w,desc->h,high);
 }
 obj=*(void**)((u8*)arg0+0x50);
 desc=((Obj*)obj)->get(base+0x258);
 if(desc) {
 copy=*desc;
 if(flag) copy.g=0x80FFFF00;
 ((void(*)(void*))fn_801476C4)(&copy);
 }
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling invalid_target
s32 fn_80016214(void) {
    register f64 scale = lbl_80560400;
    register void *manager = lbl_8055D350;
    f32 speed = *(f32 *)((u8 *)manager + 0x10);
    f32 value = (f32)((f64 (*)(void *, f32, f64))fn_8002EFB4)(manager, speed, scale);
    s32 greater = value > lbl_805603BC;
    if (greater != 0 && lbl_8055E520 != 0) {
        fn_80011E04(0);
        fn_80010FDC(lbl_802FCE04, 0xC);
        return 1;
    }
    return 0;
}
#pragma scheduling on
s32 fn_80016288(void) { return 0; }

extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[];
extern u8 lbl_802FCE88[];
void *__AXFXGetLfoSinTable(void) {
    return lbl_802FCE88;
}
extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[], lbl_802FCE88[];
