#include <types.h>
extern void *fn_801E87A8(void);
extern s32 fn_801B87A0(s32, s32);
extern s32 fn_801769A8(void);
extern s32 fn_80005580(s32);
extern s32 fn_80005678(void);
extern s32 fn_80005694(void);

extern u8 lbl_802FB5F0[];
extern u8 lbl_802FB5D8[];
extern s32 fn_801B880C(void);
extern s32 fn_80006580();
extern s32 fn_801CB880(void);
extern void fn_800121A4(void);
extern void fn_80012158(void);
extern void fn_8027AA48(void);
extern void fn_80230E90(s32);
extern void fn_801B84C0(void *);
extern s32 fn_801769B8(void);
extern s32 fn_8000C630(s32, s32);

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
extern u8 lbl_8055D340[4];
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
extern s32 fn_80007554(s32, s32, s32);
#pragma scheduling invalid_target
void fn_800056C8(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)((u8 *)&lbl_8034EEB8 + (arg0 << 4));
    *(p + 4) = arg1;
}
#pragma scheduling on

#pragma push
#pragma dont_inline on
void fn_800056E0(s32 arg0) {
    s32 count = ((s32 *)lbl_8055D350)[5];
    s32 i = 0;
    for (; i < count; i++) {
        fn_800056C8(i, arg0);
    }
}

#pragma pop
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

#pragma push
#pragma dont_inline on
void fn_800057BC(void) {
    if (lbl_8055F024 == 0) {
        return;
    }
    fn_80230DA0();
}
#pragma pop

s32 fn_800057D0(void) {
    s32 *base;
    s32 *cursor;
    s32 count, i;
    if (fn_801769A8() & 0x4000) { fn_800056E0(lbl_8034EEB8[0]); return; }
    if (lbl_8034EEB8[1] != 0 &&
        ((s32 (*)(void))(*(void ***)lbl_8034EEB8[1])[14])() == 0) {
        fn_800056E0(lbl_8034EEB8[1]); return;
    }
    if (fn_80005694() != 0) { fn_800056E0(lbl_8034EEB8[3]); return; }
    if (fn_80005678() != 0) {
        if (lbl_8034EEB8[2] != 0 &&
            ((s32 (*)(void))(*(void ***)lbl_8034EEB8[2])[14])() == 0) {
            fn_800056E0(lbl_8034EEB8[2]); return;
        }
        fn_800056E0(lbl_8034EEB8[23]); return;
    }
    count = ((s32 *)lbl_8055D350)[5];
    base = lbl_8034EEB8;
    cursor = base;
    for (i = 0; i < count; i++, cursor += 4) {
        if (fn_80005580(i) != 0) {
            fn_800056C8(i, base[0x58 / 4]);
        } else {
            fn_800056C8(i, cursor[0x1C / 4]);
        }
    }
}

#pragma push
#pragma dont_inline on
s32 fn_80005930(void) {
    extern s32 fn_801E85A4(void);
    extern void fn_801E88B4(s32 *, s32 *, s32 *, s32 *, s32);
    extern s32 fn_801E89EC(void);
    extern s32 fn_802C86F0(void *, s32, s32, s32, s32);
    extern s32 fn_802C8750(void *, s32);
    extern s32 fn_8000D75C(void);
    extern s32 fn_80010EC8(void);
    extern s32 fn_8001123C(s32);
    extern s32 lbl_8055CFF0, lbl_8055CFF4;
    s32 sp28[4], sp18[4], count = fn_801E85A4(), i;
    s32 *entry = lbl_8034EEB8;
    for (i = 0; i < count; i++, entry += 4) {
        void *obj;
        fn_80005740(i); obj = *(void **)(entry + 4);
        if (obj != *(void **)(entry + 5)) {
            if (obj) (*(void (**)(void))((u8 *)*(void **)obj + 0x18))();
            obj = *(void **)(entry + 4);
            (*(void (**)(void *))((u8 *)*(void **)obj + 0x14))(obj);
            *(void **)(entry + 5) = obj;
        }
        fn_80010EC8();
        if ((*(s32 (**)(void *))((u8 *)*(void **)obj + 0x28))(obj)) {
            sp28[1] = 0; sp28[0] = 0; sp28[2] = lbl_8055CFF0; sp28[3] = lbl_8055CFF4;
        } else fn_801E88B4(&sp28[1], &sp28[0], &sp28[2], &sp28[3], i);
        fn_802C86F0(&sp28[0], sp28[1], sp28[0], sp28[2], sp28[3]);
        (*(void (**)(void *))((u8 *)*(void **)obj + 0x20))(obj);
        if (fn_801E89EC() != 3 && (fn_8000D75C(), (*(s32 (**)(void *))((u8 *)*(void **)obj + 0x28))(obj) != 0 || i == 0))
            (*(void (**)(void *))((u8 *)*(void **)obj + 0x24))(obj);
        fn_8001123C(*(s32 *)((u8 *)lbl_8055D350 + 0x1C)); fn_80011A2C(); fn_802C8750(&sp28[0], -1);
    }
    entry = lbl_8034EEB8;
    for (i = 0; i < count; i++, entry += 4) {
        void *obj;
        fn_80005740(i); obj = *(void **)(entry + 4); fn_80010EC8();
        fn_802C86F0(&sp18[0], 0, 0, lbl_8055CFF0, lbl_8055CFF4);
        (*(void (**)(void *))((u8 *)*(void **)obj + 0x20))(obj);
        if (fn_801E89EC() != 3) { fn_8000D75C(); (*(void (**)(void *, s32))((u8 *)*(void **)obj + 0x2C))(obj, i); }
        fn_8001123C(*(s32 *)((u8 *)lbl_8055D350 + 0x1C)); fn_80011A2C(); fn_802C8750(&sp18[0], -1);
    }
}
#pragma dont_inline reset
#pragma pop
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

#pragma push
#pragma dont_inline on
void fn_80005B6C(void) {
    return;
}
#pragma pop

void fn_80005B70(void) {
}

#pragma cplusplus on
#pragma push
#pragma dont_inline on
extern "C" void fn_80005B74(void) {
    class LfoValue {
    public:
        virtual void method0() = 0;
        virtual void method1() = 0;
        virtual void method2() = 0;
        virtual void method3() = 0;
        virtual void method4() = 0;
        virtual void method5() = 0;
        virtual void method6() = 0;
        virtual f32 getValue(const char *) = 0;
    };
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
        value = ((LfoValue *)object)->getValue((char *)base + 0x24);
        current = *(f32 *)((u8 *)lbl_8055D350 + 0x10);
        if (current > value) {
            if (current - value < lbl_80560120)
                fn_800105A0((char *)base + 0x38, 0);
        } else {
            sprintf(buffer, (char *)base + 0x4C, value - current);
            fn_800105A0(buffer, 0);
        }
    }
}

void fn_80005C20(void) {
    f32 temp_f0;
    f32 var_f3;
    s32 temp_r3;

    temp_r3 = fn_802E2C20();
    var_f3 = lbl_8056011C;
    temp_f0 = (f32)(temp_r3 - lbl_8055D348) / lbl_80560124;
    var_f3 = (var_f3 > temp_f0) ? var_f3 : temp_f0;
    lbl_8055D34C = var_f3;
    lbl_8055D348 = temp_r3;
}

#pragma pop
#pragma cplusplus off
extern void *fn_801284F8(s32, const char *);
extern void *fn_80014524(void *, s32);
extern void fn_80176780(s32, s32);
extern s32 fn_801B8914(void);
extern s32 fn_801B8900(void);
extern void *fn_80145E70(void *);
extern void *fn_8023512C(void *);
extern void *lbl_8055D344;
extern void *lbl_802FB4E8[];
extern void *lbl_802FB4B0[];
extern void *lbl_802FB358[];
extern void *lbl_802FB318[];
extern void *lbl_802FB408[];
extern void *lbl_802FB440[];
extern void *lbl_802FB520[];
extern void *lbl_802FB2DC[];
extern u8 lbl_802FB640[], lbl_802FB650[], lbl_802FB65C[];
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
extern "C" void fn_80005C88(void) {
    struct Dummy {
        virtual void v0() = 0; virtual void v1() = 0;
        virtual void v2() = 0; virtual void v3() = 0;
        virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0;
    };
    u32 *manager = (u32 *)lbl_8055D350;
    u8 *strings = lbl_802FB0C8;
    u32 *config = (u32 *)manager[2];
    s32 flag = (config[1] >> 9) & 1;
    u8 *state;
    u8 *entry;
    s32 count;
    s32 i;
    void *object;

    if (flag != 0) {
        object = fn_801284F8(4, (const char *)(strings + 0xB0));
        if (object != 0) {
            *(void **)object = lbl_802FB4E8;
            ((Dummy *)object)->v5();
        }
        *(void **)((u8 *)lbl_8034EEB8 + 0xC) = object;
    } else {
        object = fn_801284F8(4, (const char *)(strings + 0xC4));
        if (object != 0) *(void **)object = lbl_802FB4B0;
        *(void **)((u8 *)lbl_8034EEB8 + 0xC) = object;
    }

    object = fn_801284F8(4, (const char *)(strings + 0xD4));
    if (object != 0) *(void **)object = lbl_802FB358;
    *(void **)lbl_8034EEB8 = object;

    if (fn_801B8914() != 0) {
        object = fn_801284F8(8, (const char *)(strings + 0xE8));
        if (object != 0) {
            *(void **)object = lbl_802FB318;
            ((u8 *)object)[4] = 0;
            ((u8 *)object)[5] = 0;
            fn_80176780(0x1000, 0);
        }
        *(void **)((u8 *)lbl_8034EEB8 + 4) = object;
    } else {
        *(void **)((u8 *)lbl_8034EEB8 + 4) = 0;
    }

    if (flag != 0) {
        object = fn_801284F8(4, (const char *)(strings + 0xF8));
        if (object != 0) *(void **)object = lbl_802FB408;
    } else {
        object = 0;
    }
    *(void **)((u8 *)lbl_8034EEB8 + 0x50) = object;

    object = fn_801284F8(4, (const char *)(strings + 0x108));
    if (object != 0) *(void **)object = lbl_802FB440;
    state = (u8 *)lbl_8034EEB8;
    *(void **)(state + 0x54) = object;

    manager = (u32 *)lbl_8055D350;
    count = manager[5];
    entry = state;
    for (i = 0; (u32)i < 4U; i++, entry += 0x10) {
        *(s32 *)(entry + 0x10) = 0;
        *(s32 *)(entry + 0x14) = 0;
        if (i < count) {
            object = fn_801284F8(0x54, (const char *)(strings + 0x118));
            if (object != 0) object = fn_80014524(object, i);
            *(void **)(entry + 0x18) = object;
        } else {
            *(void **)(entry + 0x18) = 0;
        }
        if (flag != 0) object = *(void **)(state + 0x50);
        else object = *(void **)(entry + 0x18);
        *(void **)(entry + 0x1C) = object;
    }

    object = fn_801284F8(0x1C, (const char *)(strings + 0x128));
    if (object != 0) {
        *(void **)object = lbl_802FB520;
        ((Dummy *)object)->v5();
    }
    *(void **)((u8 *)lbl_8034EEB8 + 0x58) = object;

    if (fn_801B8900() != 0) {
        object = fn_801284F8(8, (const char *)(strings + 0x138));
        if (object != 0) {
            *(void **)object = lbl_802FB2DC;
            ((u8 *)object)[4] = 0;
        }
        *(void **)((u8 *)lbl_8034EEB8 + 8) = object;
    } else {
        *(void **)((u8 *)lbl_8034EEB8 + 8) = 0;
    }

    object = lbl_8055D344;
    if (object != 0) {
        ((Dummy *)object)->v1();
        *(void **)((u8 *)lbl_8034EEB8 + 0x5C) = lbl_8055D344;
    } else {
        object = fn_801284F8(0x20, (const char *)(strings + 0x148));
        if (object != 0) {
            *(void **)object = lbl_802FB478;
            *(void **)((u8 *)object + 0x14) = fn_8023512C(lbl_802FB65C);
            *(void **)((u8 *)object + 0x18) = fn_8023512C(lbl_802FB650);
            *(void **)((u8 *)object + 0x1C) = fn_80145E70(lbl_802FB640);
            ((Dummy *)object)->v5();
        }
        *(void **)((u8 *)lbl_8034EEB8 + 0x5C) = object;
    }
    *(s32 *)((u8 *)lbl_8034EEB8 + 0x60) = 0;
}
#pragma pop
#pragma scheduling on
#pragma cplusplus reset
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

void fn_800060A0(void *arg0) {
    lbl_8055D340[1] = 0;
    ((s32 *)arg0)[2] = 0;
}

void fn_800060B4(void) {
    return;
}

extern f32 lbl_80560138;
void fn_800060B8(void *arg0) {
    float value = lbl_80560138;
    *(u8 *)((u8 *)arg0 + 0x14) = 0;
    *(float *)((u8 *)arg0 + 4) = value;
    *(float *)((u8 *)arg0 + 8) = value;
    *(float *)((u8 *)arg0 + 0xC) = value;
    *(float *)((u8 *)arg0 + 0x10) = value;
    *(float *)((u8 *)arg0 + 0x18) = value;
}

void fn_800060DC(void) {
}

void fn_800060E0(u8 arg0, u8 arg1) {
    register u8 *p = lbl_8055D340;
    p[0] = arg0;
    p[2] = arg1;
    __AXDSPInitCallback_801769E0();
    fn_8017691C();
}

void fn_80006110(void *arg0) {
    extern void fn_8001071C(s32);
    extern void *lbl_802FB69C;
    s32 flag = 0;
    f32 threshold = lbl_8056011C;
    f32 f2 = *(f32 *)((s8 *)arg0 + ((s32 *)lbl_8055D350)[7] * 4 + 4);
    if (f2 >= threshold) {
        f32 f0 = ((f32 *)lbl_8055D350)[4] - f2;
        if (f0 > threshold) flag = 1;
    }
    if (flag == 0) {
        if (fn_80005564() == 0) {
            s32 *p = (s32 *)lbl_8034EEB8 + ((s32 *)lbl_8055D350)[7] * 4;
            void *obj = *(void **)(p + 7);
            void *vtable = *(void **)obj;
            void (*call)(void *, s32 *) = *(void (**)(void *, s32 *))((char *)vtable + 0x24);
            call(obj, p);
        }
    } else {
        s32 *p;
        if (fn_80005564() != 0) {
            void *obj = fn_801B83A0();
            if (obj != 0) {
                void *vtable = *(void **)obj;
                void (*call)(void *) = *(void (**)(void *))((char *)vtable + 0x60);
                call(obj);
                if (fn_801B83A0() != 0) {
                    void *obj2 = fn_801B83A0();
                    void *vtable2 = *(void **)obj2;
                    s32 (*call2)(void *, s32) = *(s32 (**)(void *, s32))((char *)vtable2 + 0x58);
                    s32 result = call2(obj2, ((s32 *)lbl_8055D350)[7]);
                    *(s8 *)((s8 *)arg0 + 0x14) = (s8)(result == 0);
                    return;
                }
            }
        }
        *(s8 *)((s8 *)arg0 + 0x14) = 1;
        p = 0;
        if (*(s8 *)((s8 *)*(void **)((s8 *)lbl_8055D350 + 0x30) + 0x28) != 0) {
            p = (s32 *)lbl_802FB69C;
        }
        if (p != 0) {
            fn_8001071C((s32)p);
        }
    }
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
    f32 threshold = lbl_8056011C;
    s32 flag = 0;
    f32 f2 = *(f32 *)((s8 *)arg0 + ((s32 *)lbl_8055D350)[7] * 4 + 4);
    if (f2 >= threshold) {
        f32 f0 = ((f32 *)lbl_8055D350)[4] - f2;
        if (f0 > threshold) flag = 1;
    }
    if (flag && fn_80005564()) {
        void *obj = fn_801B83A0();
        void *vtable = *(void **)obj;
        void (*call)(void *, s32) = *(void (**)(void *, s32))((char *)vtable + 0x60);
        call(obj, arg1);
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

void fn_80006330(void) {
    u32 *flags = (u32 *)lbl_8034EE84;
    register s32 *entry;
    register void *object;
    register void **vtable;
    flags[8] &= 0xFFFFFF78;
    flags[8] &= 0xFFFFF9FF;
    entry = lbl_8034EEB8 + (((s32 *)lbl_8055D350)[7] << 2);
    object = (void *)entry[7];
    vtable = *(void ***)object;
    ((void (*)(void))vtable[9])();
}

extern s32 fn_80011A5C(s32);
extern s32 fn_801B84A4(s32);
#pragma scheduling invalid_target
void fn_80006378(s32 arg0, s32 arg1) {
    s32 *p;
    void *object;
    void **vtable;
    p = lbl_8034EEB8;
    p = (s32 *)((u8 *)p + (arg1 << 4));
    object = (void *)p[7];
    vtable = *(void ***)object;
    ((void (*)(void))vtable[12])();
}
#pragma scheduling on
s32 fn_8000639C(void) {
    return 0;
}

void fn_800063A4(void) {
    fn_801C6B70();
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_800063A8(void) {
    s32 *state = (s32 *)lbl_8055D350;
    s32 index = state[7];
    s32 *entry;
    void *object;
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
    };

    fn_80011A5C(state[5]);
    entry = (s32 *)&lbl_8034EEB8;
    entry += index * 4;
    object = (void *)entry[6];
    ((Dummy *)object)->v7();
    fn_801B84A4(index);
}

s32 fn_80006408(s32 arg0, s32 arg1, s32 arg2) {
    void *obj;

    if (((s32 *)lbl_8055D350)[8] & 4) {
        obj = *(void **)(lbl_8034EEB8_arr + (arg0 << 4) + 0x18);
        if ((*(s32 (**)(void *))((u8 *)obj + 0x30))(obj) != 0) {
            return 1;
        }
    }
    if ((u32)arg1 == 0x3e8) {
        return fn_801B87A0(arg0, (u32)arg2 & 0xFFFF);
    }
    return 0;
}

#pragma cplusplus reset
#pragma scheduling on
void fn_800064A8(void *arg0) {
    s32 *p = (s32 *)arg0;
    if (p[2] != p[1]) {
        p[1] = p[2];
        p[3] = fn_80009C84() != 0 ? lbl_8055D348 : fn_802E2C20();
    }
    fn_80011A2C();
    switch (p[1]) {
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

extern void fn_8027AA48(void);
extern void fn_80011E70(void);
extern void fn_80011E90(void);
extern void fn_800109E4(s32, f32, f32, f32, f32);
extern void fn_8014784C(void *, void *, s32);
extern f32 sin(f32);
extern f32 lbl_80560128, lbl_8056011C, lbl_80560130, lbl_8056013C;
extern f32 lbl_80560140, lbl_80560144, lbl_80560148, lbl_8056014C;
extern f32 lbl_80560150, lbl_80560154, lbl_80560158, lbl_8056015C;
extern f32 lbl_80560160, lbl_80560164, lbl_80560168, lbl_8056016C;
extern u32 lbl_802ED6A8[];
extern void fn_80230E90(s32);
extern void fn_80230F78(u8 *, f32 *, u32 *, s32);
extern void fn_80147940(void *, void *, void *, s32, ...);
extern void fn_801476C4(void *);
extern void fn_8001DFCC(void);
void fn_800066B4(void *arg0) {
    u8 *base = lbl_802FB0C8;
    void *obj;
    u32 table[12];
    f32 f;
    f32 t0, t1, t2;
    s32 now;
    s32 i;
    u8 alpha;
    void *(*get)(void *, s32);
    void *(*get2)(void *, s32, s32);
    fn_8027AA48();
    fn_80011E70();
    fn_80011E90();
    fn_800109E4(0x7F000000, lbl_80560140, lbl_80560144, lbl_80560148, lbl_8056014C);
    obj = *(void **)((u8 *)arg0 + 0x1C);
    if (obj != 0) fn_8014784C(base + 0x1B4, base + 0x1C0, 0);
    f = (f32)fn_802E2C20();
    sin(lbl_80560150 * (lbl_80560154 * f));
    if (*(void **)((u8 *)arg0 + 0x1C) == 0) return;
    if (fn_80009C84()) now = lbl_8055D348;
    else now = fn_802E2C20();
    f = lbl_80560154 * (f32)(now - *(s32 *)((u8 *)arg0 + 0xC));
    if (f < lbl_8056015C) fn_80230E90(1);
    for (i = 0; i < 12; i++) table[i] = lbl_802ED6A8[i];
    t0 = (f - lbl_8056011C) / lbl_80560158;
    if (t0 > lbl_80560130) t0 = lbl_80560130;
    if (t0 < lbl_8056011C) t0 = lbl_8056011C;
    *(f32 *)&table[1] = lbl_80560160 + t0 * lbl_80560164;
    t1 = (f - lbl_80560168) / lbl_80560158;
    if (t1 > lbl_80560130) t1 = lbl_80560130;
    if (t1 < lbl_8056011C) t1 = lbl_8056011C;
    *(f32 *)&table[5] = lbl_80560160 + t1 * lbl_80560164;
    t2 = (f - lbl_8056016C) / lbl_80560158;
    if (t2 > lbl_80560130) t2 = lbl_80560130;
    if (t2 < lbl_8056011C) t2 = lbl_8056011C;
    *(f32 *)&table[9] = lbl_80560160 + t2 * lbl_80560164;
    for (i = 0; i < 3; i++) {
        u32 *entry = table + i * 4;
        u32 item[8];
        if (entry[0] == 2) fn_8027AA48();
        obj = *(void **)((u8 *)arg0 + 0x1C);
        get = *(void *(**)(void *, s32))(*(u32 *)obj + 0xC);
        obj = get(obj, entry[2]);
        for (now = 0; now < 8; now++) item[now] = ((u32 *)obj)[now];
        *(f32 *)&item[1] += *(f32 *)&entry[1];
        alpha = 0xFF;
        {
            s32 selected = *(s32 *)((u8 *)arg0 + 0x10) == (s32)entry[0];
            f32 val = lbl_8056011C;
            if (selected) fn_80230F78(&alpha, &val, &item[6], 1);
            obj = *(void **)((u8 *)arg0 + 0x1C);
            get2 = *(void *(**)(void *, s32, s32))(*(u32 *)obj + 0x14);
            obj = get2(obj, entry[3], selected ? -1 : 0);
            {
                u32 out[7];
                f32 a = ((f32 *)obj)[1];
                f32 b = ((f32 *)obj)[5];
                for (now = 0; now < 7; now++) out[now] = ((u32 *)obj)[now];
                *(f32 *)&out[1] += *(f32 *)&entry[1];
                fn_80147940(*(void **)((u8 *)arg0 + 0x1C), out, base + 0x1CC, selected ? 3 : 2, a, b);
                if (selected) {
                    f32 h = ((f32 *)obj)[4];
                    f32 w = ((f32 *)obj)[5];
                    f32 q = *(f32 *)&out[3] - lbl_8056013C * h * val;
                    f32 r = *(f32 *)&out[2] - lbl_8056013C * w * val;
                    *(f32 *)&out[4] = h * (lbl_80560130 + val);
                    *(f32 *)&out[5] = w * (lbl_80560130 + val);
                    *(f32 *)&out[1] = q;
                    *(f32 *)&out[2] = r;
                    out[6] = (out[6] & 0x00FFFF00) | ((u32)alpha << 24) | (out[6] & 0xFFFF);
                    fn_80147940(*(void **)((u8 *)arg0 + 0x1C), out, base + 0x1CC, 1, a,b,h,w,q,r,val,((f32 *)obj)[4]);
                }
            }
        }
        fn_801476C4(item);
    }
    fn_8001DFCC();
}

void fn_80006D30(void) {
    char sp8[0x48];
    if (((s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x2C) + 0x2C0))[0] & 0x10) {
        sprintf(sp8, (const char *)lbl_802FB2A0, lbl_80558928);
        fn_80010074(-1, 0x14, lbl_80558948, sp8, lbl_80560134, lbl_8056011C, lbl_80560190);
    }
}

extern void fn_800201F0(void);
extern void fn_801A7F8C(void);
extern void fn_800054E0(void);
extern void fn_8000F0E4(void *);
extern void fn_8000F884(void);
extern void fn_80011F64(void);
extern s32 fn_80137C74(void);
extern s32 fn_802090D4(void *);
extern void fn_801331C4(s32, void *, s32 *);
extern void fn_80005464(void);
extern void fn_8001DB54(void);
extern s32 lbl_8055892C;
#pragma push
#pragma cplusplus on
#pragma dont_inline on
void fn_80006D9C(void) {
    u8 *resource = lbl_802FB0C8;
    u8 *state;
    void *object;
    fn_800201F0();
    fn_801A7F8C();
    fn_800054E0();
    fn_8000F0E4(resource + 0x1EC);
    fn_8000F884();
    fn_80011F64();
    state = lbl_8034EE84;
    *(void **)(state + 8) = fn_801E87A8();
    *(s32 *)(state + 0x14) = fn_80137C74();
    lbl_8055D354 = fn_802090D4(resource + 0x1F8);
    fn_801331C4(4, resource + 0x204, &lbl_8055892C);
    fn_80005464();
    fn_80005C88();
    fn_80011A5C(((s32 *)lbl_8055D350)[5]);
    fn_8001DB54();
    object = fn_801B83A0();
    ((void (*)(void *))(*(void **)((u8 *)*(void **)object + 0xF8)))(object);
    fn_800070DC();
}
#pragma pop

void fn_80006E50(void) {
}

void fn_800070D4(void) {
    return;
}

void fn_800070D8(void) {
}

#pragma cplusplus on
extern "C" void fn_80209190(s32, f32);
extern "C" void fn_8001DEA8(void);
extern "C" void fn_80011A50(void);
extern "C" void fn_80005464(void);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_800070DC(void) {
    class Item {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void dispatch();
    };
    s32 *base;
    Item *item;
    void *obj;
    u8 *cursor;
    s32 i;
    s32 zero;
    register f32 factor = lbl_80560130;

    fn_80209190(lbl_8055D354, factor);
    base = lbl_8034EEB8;
    ((Item *)base[3])->dispatch();
    ((Item *)*(void **)((u8 *)base + 0x5C))->dispatch();
    ((Item *)*(void **)((u8 *)base + 0x58))->dispatch();
    if (base[20] != 0) {
        ((Item *)base[20])->dispatch();
    }
    if (lbl_8034EEB8[2] != 0) {
        ((Item *)lbl_8034EEB8[2])->dispatch();
    }
    if (lbl_8034EEB8[1] != 0) {
        ((Item *)lbl_8034EEB8[1])->dispatch();
    }

    cursor = (u8 *)lbl_8034EEB8;
    i = 0;
    zero = 0;
    while (i < ((s32 *)lbl_8055D350)[5]) {
        obj = *(void **)(cursor + 0x18);
        item = (Item *)obj;
        item->dispatch();
        *(s32 *)(cursor + 0x10) = zero;
        cursor += 0x10;
        i++;
    }

    fn_8001DEA8();
    fn_80011A50();
    fn_80005464();
}
#pragma cplusplus reset
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
#pragma dont_inline fn_800057BC
void fn_80007238(void) {
    char stack[0x28];
    f32 f3;
    f32 f0;
    s32 mode;
    ((s32 *)lbl_8034EE84)[3] = ((s32 (*)(void))fn_801E7E3C)();
    ((f32 *)lbl_8034EE84)[4] = ((f32 (*)(void))fn_801E7E18)();
    ((s32 *)lbl_8034EE84)[6] = ((s32 (*)(void))fn_801E85A4)();
    fn_80230B5C(stack);
    fn_802C8638(stack);
    mode = ((s32 *)lbl_8034EE84)[6];
    f0 = lbl_80560194;
    f3 = lbl_80560198;
    f3 = (mode > 2) ? f3 : f0;
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
#pragma cplusplus on
extern "C" void fn_80007318(void) {
    class Dummy {
    public:
        virtual void v0(void);
        virtual void v1(void);
        virtual void v2(void);
        virtual void v3(void);
        virtual void v4(void);
        virtual void v5(void);
        virtual void v6(void);
        virtual void v7(void);
    };
    char stack[0x28];
    u32 *base;
    u32 **manager;
    fn_80005C20();
    fn_80230B5C(stack);
    fn_802C8638(stack);
    fn_802C974C(lbl_80560130, lbl_80560124, lbl_8056019C);
    base = (u32 *)lbl_8034EE84;
    base[0x1C / 4] = 0;
    base[0x24 / 4] = ((s32 (*)(s32))fn_801E866C)(0);
    ((u32 *)lbl_8034EE84)[0x28 / 4] = (u32)((void *(*)(void *))fn_801EA9A0)(*(void **)((u8 *)lbl_8055D350 + 0x24));
    manager = (u32 **)lbl_8055D350;
    base[0x2C / 4] = *(u32 *)((u8 *)manager[0x28 / 4] + 8);
    base[0x30 / 4] = (u32)((u8 *)manager[0x28 / 4] + 0xC);
    *(f32 *)&base[0x10 / 4] = ((f32 (*)(void))fn_801E7E18)();
    ((Dummy *)*(void **)((u8 *)lbl_8034EEB8 + 0x54))->v7();
    fn_800057BC();
    fn_80011A2C();
    fn_802C9904();
}
#pragma cplusplus reset
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
    s32 result = 0;
    if (lbl_8055D340[1] != 0) {
        if (lbl_8055D340[0] != 0) result = 1;
    }
    return result;
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

#pragma scheduling invalid_target
s32 fn_80007554(s32 arg0, s32 arg1, s32 arg2) {
    s32 *obj = *(s32 **)((s32 *)lbl_8034EEB8 + arg0 * 4 + 4);
    if (obj != 0) {
        return (*(s32 (**)(s32 *, s32, s32, s32))(*(s32 **)obj + 12))(obj, arg0, arg1, arg2);
    }
    return 0;
}
#pragma scheduling on
s32 fn_800075A0(s32 arg0) {
    u32 p = *(u32 *)((u8 *)&lbl_8034EEB8 + arg0 * 0x10 + 0x10);
    s32 result = 0;
    if (p != *(u32 *)((u8 *)&lbl_8034EEB8 + 0x58)) {
        if (p != *(u32 *)((u8 *)&lbl_8034EEB8 + 8)) {
            if (p != *(u32 *)((u8 *)&lbl_8034EEB8 + 0x5c)) {
                result = 1;
            }
        }
    }
    return result;
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
#pragma scheduling invalid_target
void fn_800077E4(void *arg0) {
    void *base = lbl_8055D350;
    void *p = (u8 *)arg0 + ((s32 *)base)[7] * 4;
    *(f32 *)((u8 *)p + 4) = ((f32 *)base)[4];
    if (fn_8000561C(p, base) != 0) {
        *(f32 *)((u8 *)arg0 + 0x18) = ((f32 *)lbl_8055D350)[4];
        fn_80276DC8(((s32 *)lbl_8055D350)[7]);
    }
}
#pragma scheduling on
void fn_80007848(void) {
    void *base = lbl_8055D350;
    void *object = *(void **)((u8 *)base + 0x2C);
    if ((*(u32 *)((u8 *)object + 0x2C0) & 0x20) != 0) {
        return;
    }
    fn_8000C630(0x20, *(s32 *)((u8 *)base + 0x1C));
}

s32 fn_8000786C(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg1 != 0) {
        return 0;
    }
    if ((u32)arg2 == 0x3E8) {
        return fn_801B87A0((s32)arg1, (s32)((u32)arg3 & 0xFFFF));
    }
    return 0;
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
    void *field;
    if (arg0 != 0) {
        field = *(void **)((u8 *)arg0 + 0x1C);
        *(void **)arg0 = (void *)lbl_802FB478;
        if (field != 0) {
            if (field != 0) {
                ((void (*)(void *, s32))((void **) *(void **)field)[2])(field, 1);
            }
        }
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x18));
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x14));
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

s32 fn_80007A84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_80007AC4(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    s32 temp_r3;
    u32 temp_r0;
    ((Obj *)arg0)->v5();
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
#pragma cplusplus off
u32 fn_80007B84(void) { return 1; }

s32 fn_80007B8C(void) {
    return fn_8000C630(0x20, -1);
}

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

extern int __cntlzw(unsigned int);
void fn_80007C10(void *arg0) {
    s32 value = fn_801769B8();
    s32 normalized = (u32)__cntlzw(value) >> 5;
    normalized = (u32)__cntlzw(normalized) >> 5;
    ((s8 *)arg0)[4] = (s8)normalized;
    ((s8 *)arg0)[5] = 0;
}

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

