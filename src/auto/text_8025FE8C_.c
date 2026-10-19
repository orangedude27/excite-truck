// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void fn_80214A9C(s32);
extern void fn_80214AF0(s32);
extern void fn_80230E90(s32);
extern void fn_80236914(void);
extern u8 lbl_8055F3E9;
extern u8 lbl_8055F3EA;
extern u8 lbl_8055F3EB;
extern u8 lbl_8055F420[];
extern u8 lbl_8055BAC0;
extern u8 lbl_8055BAB8;
extern s32 lbl_802FA6A8[];
extern u8 lbl_8055B860;
#pragma push
#pragma small_data off
extern u8 lbl_80345EA0;
extern u8 lbl_80345E28;
#pragma pop
extern u8 lbl_8055F3EC;
s32 fn_8025FE8C(void) {
    void *temp_r4;
    if ((s32)lbl_8055F3E9 != 0 && (s32)lbl_8055F3EC == 0) {
        temp_r4 = *(void **)(lbl_8055F420 + 0x14);
        *(u8 *)((u8 *)temp_r4 + 0x49) = 1;
        *(u8 *)((u8 *)temp_r4 + 0x4B) = 0;
        *(u8 *)((u8 *)temp_r4 + 0x4A) = 0;
        lbl_8055F3EC = 1;
    }
    return 0;
}

void fn_802607C4(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 1;
}

void fn_802607D0(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1E) = 1;
}

void fn_802607DC(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1E) = 0;
    *(u8 *)((u8 *)arg0 + 0x1C) = 0;
}

void fn_802607EC(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 0;
}

void fn_802607F8(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1C) == 0) {
        *(u8 *)((u8 *)arg0 + 0x1C) = 1;
        *(u8 *)((u8 *)arg0 + 0x1F) = 1;
    }
}

void fn_80260814(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 0;
}

void fn_80260820(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1C) == 0) {
        *(u8 *)((u8 *)arg0 + 0x1E) = 1;
        *(u8 *)((u8 *)arg0 + 0x1C) = 1;
    }
}

void fn_8026083C(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1C) = 0;
}

void fn_80260848(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 1;
}

#pragma push
#pragma small_data off
void *fn_80260854(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80345E28;
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x24), (s32 *)&lbl_80345E28);
        *(s32 *)((u8 *)arg0 + 0x24) = 0;
        fn_802328D4(*(s32 *)((u8 *)arg0 + 0x28));
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop
extern s32 fn_80128668(void);
extern s32 fn_802328D4(s32);
extern s32 fn_80235380(s32, s32 *);
extern u8 lbl_80345EA0;
extern u8 lbl_80345E28;
#pragma push
#pragma small_data off
void *fn_802608D4(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = (void *)(u32)&lbl_80345EA0;
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x20), (s32 *)(u32)&lbl_80345EA0);
        *(s32 *)((u8 *)arg0 + 0x20) = 0;
        fn_802328D4(*(s32 *)((u8 *)arg0 + 0x24));
        *(s32 *)((u8 *)arg0 + 0x24) = 0;
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma pop
s32 fn_80260DC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80260E04(s32 *arg0, s32 *arg1) {
    s32 e;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    d = arg1[3];
    e = arg1[4];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
    arg0[4] = e;
}

s32 fn_802610C8(void) {
    s32 result = 0;
    u32 *base;
    void *object;
    void **vtable;
    if (lbl_8055F3EB != 0) {
        lbl_8055F3EA = 1;
        fn_80214A9C(30);
        base = (u32 *)lbl_8055F420;
        object = *(void **)(base + base[0] + 0x18);
        vtable = *(void ***)object;
        result = ((s32 (*)(void *))vtable[9])(object);
        base = (u32 *)lbl_8055F420;
        object = *(void **)(base + base[0] + 0x18);
        vtable = *(void ***)object;
        ((void (*)(void *, u32 *))vtable[8])(object, base);
        fn_8025C204(result);
        fn_80214AF0(30);
        fn_80230E90(0);
        lbl_8055F3EA = 0;
    }
    return 0;
}

extern s32 lbl_802FA6A8[];
extern u8 lbl_8055B860;
void fn_80261688(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 value;
    *(s32 *)((u8 *)arg0 + 8) = arg3;
    value = (s32)&lbl_8055B860;
    *(s32 *)((u8 *)arg0 + 4) = 6;
    *(s32 *)arg0 = value;
    *(s32 *)((u8 *)arg0 + 0xC) = arg2;
    *(s32 *)((u8 *)arg0 + 0x10) = arg1;
}

s32 fn_80261948(s32 *arg0) {
    s32 *p = lbl_802FA6A8;
    s32 values[3];
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p;
    return values[*arg0];
}

void fn_80261980(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 zero;
    *(s32 *)arg0 = arg1;
    zero = 0;
    *(s32 *)((u8 *)arg0 + 4) = 3;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0xC) = arg3;
    *(s32 *)((u8 *)arg0 + 0x10) = zero;
}

extern s32 lbl_802FA6B4[];
s32 fn_802619A0(s32 *arg0) {
    s32 *p = lbl_802FA6B4;
    s32 values[3];
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p;
    return values[*arg0];
}

s32 fn_802619D8(s32 *arg0, s32 arg1) {
    return *arg0 + arg1 * 4;
}

void fn_802619E8(void *arg0, s32 arg1, s32 arg2) {
    s32 zero = 0;
    *(s32 *)arg0 = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 5;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0xC) = zero;
    *(s32 *)((u8 *)arg0 + 0x10) = zero;
}

s32 fn_80261A08(s32 *arg0, s32 arg1) {
    return *arg0 + arg1 * 4;
}

void fn_80261A18(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 8;
    *(void **)((u8 *)arg0) = &lbl_8055BAB8;
    *(s32 *)((u8 *)arg0 + 0xC) = 2;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_80261A40(s32 arg0) {
    fn_80236914();
    lbl_8055F3E9 = (u32)__cntlzw(arg0 - 2) >> 5;
}

void fn_80261A7C(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 8;
    *(void **)((u8 *)arg0) = &lbl_8055BAC0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_80261AA0(void) {
    s32 i = 0;
    do {
        fn_80214A9C(i + 10);
        i++;
    } while (i < *(s32 *)(lbl_8055F420 + 0xC));
}

void fn_80261AE8(s32 *arg0, s32 arg1) { *arg0 = arg1; }

void fn_80262120(void *arg0) {
    s32 zero;
    *(s32 *)arg0 = (s32)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)arg0 + 8) = 3;
    zero = 0;
    *(s32 *)((u8 *)arg0 + 4) = zero;
}

#pragma scheduling invalid_target
void fn_8026213C(void *arg0) {
    *(s32 *)arg0 = (s32)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)arg0 + 8) = 6;
    *(s32 *)((u8 *)arg0 + 4) = 0;
}
#pragma scheduling on
void fn_80262158(void) {
}

void fn_8026215C(void) {
}

s32 fn_80262160(void) {
    return 0;
}

void fn_80262168(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1E) && lbl_8055F3E9 && !lbl_8055F3EA) {
        fn_80230E90(0);
        *(u8 *)((u8 *)arg0 + 0x1E) = 0;
    }
    if (lbl_8055F3EB && !lbl_8055F3EA) {
        fn_80214AF0(0x1E);
        return;
    }
    fn_80214A9C(0x1E);
}

void fn_80262574(void) {
}

void fn_80262578(void) {
}

s32 fn_8026257C(void) {
    return 0;
}

void fn_80262584(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1F) && lbl_8055F3E9) {
        fn_80230E90(0);
        *(u8 *)((u8 *)arg0 + 0x1F) = 0;
    }
}

