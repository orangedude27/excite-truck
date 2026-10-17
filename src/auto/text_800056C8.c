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

void fn_80006E50(void) {
}

void fn_800070D4(void) {
    return;
}

void fn_800070D8(void) {
}

void fn_80007498(void) {
    fn_80011A50();
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
    *(u8 *)((u8 *)arg0 + 4) = (fn_801769B8() != 0);
    *(u8 *)((u8 *)arg0 + 5) = 0;
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

