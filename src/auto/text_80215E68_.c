extern void fn_8021889C(void);

#include <types.h>
static inline void fn_80216244_rotate(const f32 *m, f32 *out, const f32 *v) {
    if (out == v) {
        f32 x = v[2]*m[6] + (v[0]*m[0] + v[1]*m[3]);
        f32 y = v[2]*m[7] + (v[0]*m[1] + v[1]*m[4]);
        f32 z = v[2]*m[8] + (v[0]*m[2] + v[1]*m[5]);
        out[0] = x; out[1] = y; out[2] = z;
    } else {
        out[0] = v[2]*m[6] + (v[0]*m[0] + v[1]*m[3]);
        out[1] = v[2]*m[7] + (v[0]*m[1] + v[1]*m[4]);
        out[2] = v[2]*m[8] + (v[0]*m[2] + v[1]*m[5]);
    }
}

extern void *lbl_8055EF88;
extern s32 lbl_8055EF78;
extern u32 lbl_8055EF7C;
extern u32 lbl_8055EF8C;
extern void (*lbl_8055EF90)(void);
extern u8 lbl_8055EF70;
extern u8 lbl_8055F024;
extern u32 lbl_804908C8[16];
extern s32 fn_802C8530(void);
extern s32 fn_80216244(void);
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern void fn_802184D0(void);
extern void fn_80218574(void *);
extern void fn_80230B5C(void *);
extern void fn_8023108C(s32);
extern void fn_802C8638(void *);
extern void fn_802C86E8(u32);
extern void fn_802C87B4(s32, s32, s32, s32);
extern void fn_802C88BC(s32);
extern void fn_802C974C(f32, f32, f32);
extern s32 fn_802160AC(void);
extern s32 fn_80211F54(void);
extern s32 fn_80019BA8(void);
extern s32 fn_80230DA0(void);
extern s32 fn_802C855C(void);
extern s32 fn_802C2B48(void);
extern s32 fn_80211F64(void);
extern s32 fn_802164D8(void);
extern s32 fn_80129AFC(void);
extern s32 fn_802161CC(s32);
extern void fn_80218370(void *);
extern s32 fn_802E97B4(void);
extern void fn_802166B8(void);
extern char lbl_8033D690[];
extern s32 fn_80215EC4(s32, s32);
extern char lbl_80490710[];
extern void fn_8002F634(void *, void *, s32, s32);
extern f32 lbl_8055EF94;
extern s32 lbl_8055EF74;
extern s32 fn_80217270(s32);
extern s32 fn_802E317C(const char *, ...);
#pragma small_data off
extern char lbl_8033D7EC;
#pragma small_data on
extern s32 fn_80218464(void);
extern u32 lbl_8055EF98;
extern char lbl_8055EF99;
__declspec(section ".data") extern f32 lbl_80558DC4;
extern u32 lbl_8055EF80;
extern u32 lbl_8055EF84;


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80128668(void);
s32 fn_80215E68(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_80215EA8(void) {
    fn_8002F634(lbl_80490710, fn_80215EC4, 0x18, 0x10);
}
#pragma scheduling on
s32 fn_80215EC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_80215F04(void *arg0) {
    *(char **)arg0 = lbl_8033D690;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
}
#pragma scheduling on
s32 fn_80215F1C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80215F5C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern s32 fn_802C3034(s32);
extern s32 fn_802C3424(s32, s32, s32, s32, s32);
extern s32 lbl_8055FBDC;
extern s32 fn_802E4A10(void);
extern char lbl_8033D768[];
extern char lbl_8033D774[];
char *fn_80215F9C(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x10) != 0) return (char *)lbl_8033D774;
    return (char *)lbl_8033D768;
}

void fn_80215FBC(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x10) ^= 1;
}

void fn_80215FCC(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x10) ^= 1;
}

u32 fn_80215FDC(void) { return 1; }

u32 fn_80215FE4(void) { return 1; }

u8 fn_80215FEC(void *arg0) { return *(u8 *)((u8 *)arg0 + 8); }

u8 fn_80215FF4(u8 *arg0) { return *arg0; }

#pragma peephole off
#pragma scheduling invalid_target
s32 fn_80215FFC(void *arg0) {
    s32 result = 0;
    if (*(u8 *)arg0 != 0 && *(s32 *)((u8 *)arg0 + 4) == fn_802E4A10()) result = 1;
    return result;
}
#pragma scheduling on
#pragma peephole on
u32 fn_80216054(void) { return 1; }

void fn_8021605C(void *arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r3;
    fn_802C3034(arg1);
    temp_r4 = *(s32 *)((u8 *)arg0 + 8);
    temp_r3 = *(s32 *)((u8 *)arg0 + 4);
    fn_802C3424(temp_r3, temp_r4, temp_r3 + *(s32 *)((u8 *)arg0 + 0xC), temp_r4 + *(s32 *)((u8 *)arg0 + 0x10), lbl_8055FBDC);
}

extern s32 fn_8021832C(void);
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_802C5310(s32, s32, f32, f32, f32);
extern u32 lbl_8055EF80;
extern u32 lbl_8055EF84;
extern f32 lbl_80563458;
extern f64 lbl_80563460;
extern f32 lbl_80563468;
extern f32 lbl_8056346C;
extern f32 lbl_80563470;
extern f32 lbl_80563474;
extern f32 lbl_80563478;
#pragma push
#pragma scheduling invalid_target
#pragma fp_contract on
s32 fn_802160AC(void) {
    struct Scratch {
        u8 buffer[0x30];
        union {
            f64 value;
            struct {
                u32 high;
                u32 low;
            } words;
        } x;
        union {
            f64 value;
            struct {
                u32 high;
                u32 low;
            } words;
        } y;
    } scratch;
    s32 temp_r31;
    f32 a;
    f32 b;
    void *enabled = lbl_8055EF88;

    if (enabled != 0)
        temp_r31 = fn_8021832C();
    else
        temp_r31 = 0;
    if (temp_r31 == 0 && lbl_8055EF7C == 0)
        goto done;

    fn_802C974C(lbl_80563468, lbl_8056346C, lbl_80563470);
    fn_80230B5C(scratch.buffer);
    fn_802C8638(scratch.buffer);

    scratch.x.words.low = (u32)lbl_8055EF80 ^ 0x80000000;
    scratch.x.words.high = 0x43300000;
    a = scratch.x.value - lbl_80563460;
    a -= lbl_80563474;
    scratch.y.words.low = (u32)lbl_8055EF84 ^ 0x80000000;
    scratch.y.words.high = 0x43300000;
    b = scratch.y.value - lbl_80563460;
    b = lbl_80563478 - b;
    if (temp_r31 != 0)
        fn_802C5310(temp_r31, 0, a, b, lbl_80563458);
    else
        fn_802C5310(lbl_8055EF7C, 0, a, b, lbl_80563458);
done:
    ;
}
#pragma pop
void fn_80216194(void) {
    s32 i = 1;
    do {
        fn_802166B8();
    } while (i++ < 3);
}

#pragma dont_inline on
s32 fn_802161CC(s32 arg0) {
    s32 i;
    for (i = 0; i < 16; i++) {
        u32 value = lbl_804908C8[i];
        if (value != 0 && (arg0 != 0 || value != (u32)lbl_8055EF88)) {
            fn_80218464();
        }
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline reset
s32 fn_80216244(void) {
    s32 i;
    u32 *p;
    u8 *obj;
    f32 matrix[12];
    f32 vec[3], pos[3];
    f32 x, y;
    register f32 z;
    f64 d;
    u32 raw;
    void (*callback)(void);

    p = lbl_804908C8;
    for (i = 0; i < 16; i++, p++) if (*p != 0) ((void (*)(void *))fn_802184D0)((void *)*p);
    callback = (void (*)(void))lbl_8055EF8C;
    if (callback != 0) callback();
    fn_802C86E8(0xFF0000FF);
    fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802C88BC(2);
    p = lbl_804908C8;
    z = lbl_80563458;
    for (i = 0; i < 16; i++, p++) {
        obj = (u8 *)*p;
        if (obj != 0) {
            fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
            fn_80230B5C(matrix);
            fn_802C974C(lbl_80563468, lbl_8056346C, lbl_80563470);
            raw = *(u32 *)(obj + 0x454);
            x = -(f32)(s32)raw;
            raw = *(u32 *)(obj + 0x458);
            y = (f32)(s32)raw;
            vec[0] = x; vec[1] = y; vec[2] = z;
            fn_80216244_rotate(matrix, pos, vec);
            matrix[9] += pos[0];
            matrix[10] += pos[1];
            matrix[11] += pos[2];
            fn_802C8638(matrix);
            fn_8023108C(obj == lbl_8055EF88);
            fn_80218574(obj);
        }
    }
    fn_8023108C(1);
}
#pragma pop
extern s32 fn_80127A50(void *);
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern f32 lbl_8056347C, lbl_80563480;
extern void fn_80217590(void *,s32,s32), fn_802176D4(void *,s32,s32), fn_8021749C(void *,s32,s32), fn_802175F0(void *,s32,s32), fn_80217734(void *,s32,s32);
extern void fn_80217834(void *), fn_80217854(void *);
extern s32 fn_802E47B8(void), fn_802E46F0(void);
extern void fn_80217874(void *,u16);
s32 fn_802164D8(void) {
    s32 event[6];
    if (fn_80127A50(event)) {
        s32 x = (s32)((lbl_8056347C * (f32)event[1]) / (f32)lbl_8055CFF0);
        s32 y = (s32)((lbl_80563480 * (f32)event[2]) / (f32)lbl_8055CFF4);
        lbl_8055EF80 = x;
        lbl_8055EF84 = y;
        if (lbl_8055EF88) {
            switch (event[0]) {
            case 0: fn_80217590(lbl_8055EF88, x, y); break;
            case 1: fn_802176D4(lbl_8055EF88, x, y); break;
            case 2: fn_8021749C(lbl_8055EF88, x, y); break;
            case 3: fn_802175F0(lbl_8055EF88, x, y); break;
            case 4: fn_80217734(lbl_8055EF88, x, y); break;
            case 7: fn_80217834(lbl_8055EF88); break;
            case 8: fn_80217854(lbl_8055EF88); break;
            }
        }
    }
    if (fn_802E47B8()) {
        s32 key = fn_802E46F0();
        if (lbl_8055EF88) fn_80217874(lbl_8055EF88, key);
    }
}

#pragma dont_inline reset

void fn_8021662C(void) {
    s32 temp_r31;
    temp_r31 = lbl_8055EF78;
    fn_80211F64();
    if (lbl_8055EF90 != NULL) lbl_8055EF90();
    fn_802164D8();
    if (lbl_8055EF88 != 0) fn_80129AFC();
    fn_802161CC(0);
    if (lbl_8055EF88 != 0) {
        fn_80218370(lbl_8055EF88);
    }
    if (temp_r31 == (s32)lbl_8055EF78) {
        if ((s32)lbl_8055EF70 == 0) fn_802166B8();
        fn_802E97B4();
    }
}

void fn_802166B8(void) {
    fn_802C8530();
    fn_80216244();
    fn_802160AC();
    if (fn_80211F54() == 0) {
        fn_80019BA8();
    }
    if (lbl_8055F024 != 0) {
        fn_80230DA0();
    }
    fn_802C855C();
    fn_802C2B48();
}

extern u32 lbl_8055EF98;
u32 *fn_80216708(void) {
    return &lbl_8055EF98;
}

#pragma scheduling invalid_target
void fn_80216710(void) {
    int i;
    lbl_8055EF88 = 0;
    for (i = 0; i < 16; i++) {
        lbl_804908C8[i] = 0;
    }
    lbl_8055EF7C = 0;
    lbl_8055EF8C = 0;
    lbl_8055EF90 = 0;
}
#pragma scheduling on
void fn_8021676C(void) {

}

extern char lbl_8033D7A4[];
extern char lbl_8033D7B4[];
extern void *fn_801284F8(s32, const char *);
extern void *fn_80216D40(void *, s32, s32, s32, s32, s32, s32);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void *fn_80216770(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    const char *name = (const char *)lbl_8033D7A4;
    void *result = fn_801284F8(0xDE8, name);
    s32 i;
    if (result != 0)
        result = fn_80216D40(result, arg0, arg1, arg2, arg3, arg4, arg5);
    for (i = 0; i < 16; i++) {
        if (lbl_804908C8[i] == 0) {
            lbl_804908C8[i] = (u32)result;
            return result;
        }
    }
    fn_802E317C((const char *)&lbl_8033D7B4);
    return 0;
}
#pragma small_data off
void fn_8021683C(u32 arg0) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (arg0 == lbl_804908C8[i]) {
            ((void (*)(u32, s32))fn_80217270)(arg0, 1);
            lbl_804908C8[i] = 0;
            return;
        }
    }
    fn_802E317C(&lbl_8033D7EC);
}
#pragma small_data on
void fn_802168BC(s32 arg0) {
    lbl_8055EF74 = arg0;
    lbl_8055EF70 = 1;
}

void fn_802168CC(void) {
    fn_8021889C();
}

void fn_802168D0(void) {
    fn_80218968();
}

void fn_802168D4(void) {
    fn_8021885C();
}

void fn_802168D8(void) {
    fn_80218A34();
}

void fn_802168DC(void) {
    fn_80218ADC();
}

void fn_802168E0(void) {
    fn_80218B88();
}

extern void *lbl_8055EF88;
void* fn_802168E4(void) {
    return lbl_8055EF88;
}

void fn_802168EC(void) {
    fn_80218C98();
}

extern s32 fn_8012742C(void);
extern void fn_80214D50(s32);
extern void fn_8023660C(void);
extern void fn_802D3E9C(s32);
extern void fn_80127A84(void *, void *, void *);
extern void fn_801282E8(void);
extern void fn_80236780(void);
extern void fn_8021734C(void *);
extern void fn_8021747C(void *, s32, f32 *, f32);
extern void fn_80236674(void);
extern void fn_80230E90(s32);
extern f32 fn_80214D48(void);
extern void fn_80236900(void);
extern void fn_802368D0(void);
extern void fn_802173F8(void *);
extern void fn_80217478(void *);
extern void fn_80236848(void);
extern void fn_80236600(void);
extern f32 lbl_80563484, lbl_80563488;
extern f32 lbl_80558DC4;
extern double __fabs(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
s32 fn_802168F0(void *arg0) {
    f32 sp[2];
    s32 sp8;
    void *prev;
    f32 f29, f30, f31, f28, f2;
    s32 flag;
    s32 gt;
    s32 old = lbl_8055EF78;
    lbl_8055EF78 = old + 1;
    if (fn_8012742C() != 0) return -1;
    if (*(u8 *)((u8 *)arg0 + 0xDE4) != 0) fn_80214D50(5);
    else fn_8023660C();
    fn_802D3E9C(0);
    *(u8 *)&lbl_8055EF98 = 1;
    fn_80127A84(&lbl_8055EF80, &lbl_8055EF84, &sp8);
    prev = lbl_8055EF88;
    sp[0] = lbl_80563458;
    lbl_8055EF88 = arg0;
    sp[1] = lbl_80563458;
    fn_80236780();
    fn_8021734C(arg0);
    fn_8021747C(arg0, 0, sp, lbl_80563458);
    fn_801282E8();
    lbl_8055EF70 = 0;
    if (prev != 0) lbl_8055EF74 = 0;
    fn_80217734(lbl_8055EF88, lbl_8055EF80, lbl_8055EF84);
    fn_80211F64();
    fn_80211F64();
    f2 = sp[0] > lbl_80563484 ? sp[0] : lbl_80563484;
    f28 = lbl_80563468;
    f29 = f28 / f2;
    f28 = (f32)__fabs(sp[0]) <= lbl_80558DC4 ? f28 : lbl_80563458;
    f30 = lbl_80563468;
    flag = 0;
    lbl_8055EF94 = f28;
    f31 = lbl_80563488;
    while (lbl_8055EF70 == 0) {
        fn_80236674();
        if (lbl_8055EF88 != 0) {
            void (*cb)(void *) = *(void (**)(void *))((u8 *)lbl_8055EF88 + 0x434);
            if (cb != 0) cb(lbl_8055EF88);
            if (f28 < f30) {
                fn_8021747C(lbl_8055EF88, 1, sp, f28);
            } else {
                if (flag == 0) {
                    flag = 1;
                    fn_80230E90(0);
                }
                fn_8021747C(lbl_8055EF88, 2, sp, lbl_80563468);
            }
        }
        if (f28 < f31) {
            while (fn_802E47B8() != 0) fn_802E46F0();
        }
        fn_8021662C();
        f28 += f29 * fn_80214D48();
        lbl_8055EF94 = f28 < f30 ? f28 : f30;
        if (fn_8012742C() != 0) {
            lbl_8055EF74 = -1;
            break;
        }
    }
    fn_8012742C();
    if (lbl_8055EF74 == -1) fn_80236900();
    else fn_802368D0();
    fn_8021747C(arg0, 0, sp, lbl_80563458);
    f2 = sp[1] > lbl_80563484 ? sp[1] : lbl_80563484;
    f30 = lbl_80563468;
    f28 = f30 / f2;
    if ((f32)__fabs(sp[1]) <= lbl_80558DC4) f30 = lbl_80563458;
    lbl_8055EF94 = f30;
    if (*(u8 *)&lbl_8055EF99 == 0) fn_80214D50(4);
    else *(u8 *)&lbl_8055EF99 = 0;
    f31 = lbl_80563458;
    for (;;) {
        gt = f31 > f30;
        f30 = gt ? f31 : f30;
        lbl_8055EF94 = f30;
        if (fn_8012742C() != 0) {
            lbl_8055EF74 = -1;
            break;
        }
        if (sp[1] > f31) {
            fn_80236674();
            if (lbl_8055EF88 != 0) fn_8021747C(lbl_8055EF88, 3, sp, f30);
        }
        fn_802161CC(1);
        fn_802166B8();
        if (f31 == f30) break;
        f30 -= f28 * fn_80214D48();
        fn_80211F64();
    }
    fn_80216194();
    lbl_8055EF70 = 0;
    fn_802173F8(arg0);
    lbl_8055EF88 = prev;
    if (prev != 0) {
        fn_80217734(prev, lbl_8055EF80, lbl_8055EF84);
        if (*(u8 *)((u8 *)arg0 + 0xDE4) == 0) fn_80217478(lbl_8055EF88);
    }
    fn_80236848();
    if (*(u8 *)((u8 *)arg0 + 0xDE4) == 0) fn_80236600();
    return lbl_8055EF74;
}
#pragma pop

extern char lbl_8055EF99;
void fn_80216CA8(void) {
    lbl_8055EF99 = 1;
}

f32 fn_80216CB4(void) { return lbl_8055EF94; }

