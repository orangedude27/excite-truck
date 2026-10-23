// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern const char lbl_80558A70[];
extern s32 fn_80131234(s32);
extern void fn_801476C4(void);
extern void fn_80011A2C(void);

extern s32 lbl_8055D400;
extern u8 lbl_8055D404;
extern u8 lbl_8055D405;
extern u8 lbl_8055D406;
extern u8 lbl_8055D407;
extern s32 lbl_8055D408;
extern s32 lbl_8055D40C;
extern s32 lbl_8055D420;
extern void **lbl_8055D414;
extern void **lbl_8055D418;
extern void **lbl_8055D41C;
extern s32 lbl_8055D410;

void fn_802066C8(void*, u32);
void fn_80128668(void*);
s32 fn_8000CCB8(void);
void fn_80209110(s32);

// Externs for fn_8000CE60
extern u8 lbl_802FC058[];
extern s32 fn_802090D4(void*);
extern void fn_80209190(f32);
extern s32 fn_80145E70(void*);
extern s32 fn_80207848(void*, s32);
extern f32 lbl_80560218;

// Externs for fn_8000D070, fn_8000D100
extern f32 fn_80209028(void);
extern s32 fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206444(void);
extern void fn_80209190_s32_f32(s32, f32);
extern void fn_80230E90(s32);
extern f32 lbl_80560234;

// Externs for fn_8000D100
extern char lbl_802FC1CC[];
extern void fn_80206454(void);
extern void fn_802E30C8(const char*, ...);
extern void fn_801769EC(void);

// Externs for fn_8000CCB8
extern s32 fn_800075A0(s32);
extern u32 __AXGetStackHead_80137CFC(s32);
extern s32 fn_802E8504(void);
extern s32 fn_80137C74(void);

s32 fn_8000CFA8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802066C8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_8000D000(s32 arg0, s32 arg1, s32 arg2) {
    lbl_8055D408 = arg0;
    lbl_8055D404 = 1;
    lbl_8055D405 = 0;
    lbl_8055D406 = 0;
    lbl_8055D407 = 0;
    lbl_8055D40C = arg1;
    lbl_8055D400 = arg2;
    lbl_8055D420 = fn_8000CCB8();
}

void fn_8000D000(s32, s32, s32);
void fn_8000D048(void) {
    ((void (*)(void))fn_8000D000)();
    lbl_8055D407 = 1;
}

void fn_8000CE60(void) {
    volatile u8 *p404 = &lbl_8055D404;
    *p404 = 0;
    lbl_8055D405 = 0;
    lbl_8055D407 = 0;
    lbl_8055D400 = 0;
    lbl_8055D408 = 0;
    lbl_8055D40C = 0;
    lbl_8055D410 = fn_802090D4((void*)(lbl_802FC058 + 0x140));
    fn_80209190(lbl_80560218);
    lbl_8055D414 = (void**)fn_80145E70((void*)(lbl_802FC058 + 0x14C));
    lbl_8055D418 = (void**)fn_80207848((void*)(lbl_802FC058 + 0x158), 0);
    lbl_8055D41C = (void**)fn_80207848((void*)(lbl_802FC058 + 0x164), 0);
    lbl_8055D420 = -1;
}

void fn_8000D070(void) {
    u8 *base;
    if (lbl_8055D418 != NULL) {
        f32 val = fn_80209028();
        f32 *ptr = (f32*)((u8*)lbl_8055D418 + 8);
        if (val != *ptr) {
            *(u8*)((u8*)lbl_8055D418 + 0x4D) = 1;
            *ptr = val;
        }
        base = (u8*)lbl_8055D418;
        base[0x49] = 1;
        base[0x4B] = 0;
        base[0x4A] = 0;
    }
    if (fn_80265D64() == 0) __AXDSPInitCallback_801769E0();
    fn_80206444();
    lbl_8055D400 = 0;
    fn_80209190_s32_f32(lbl_8055D410, lbl_80560234);
    fn_80230E90(1);
}

void fn_8000D100(void) {
    u8 *base;
    if (lbl_8055D41C != NULL) {
        f32 val = fn_80209028();
        f32 *ptr = (f32*)((u8*)lbl_8055D41C + 8);
        if (val != *ptr) {
            *(u8*)((u8*)lbl_8055D41C + 0x4D) = 1;
            *ptr = val;
        }
        base = (u8*)lbl_8055D41C;
        base[0x49] = 1;
        base[0x4B] = 0;
        base[0x4A] = 0;
    }
    fn_80209190_s32_f32(lbl_8055D410, lbl_80560218);
    fn_80206454();
    if (lbl_8055D404 != 0) {
        fn_802E30C8((void*)0x802FC1CC);
        lbl_8055D404 = 0;
        return;
    }
    fn_801769EC();
}

void fn_8000D19C(void) {
    if (lbl_8055D407 != 0) {
        lbl_8055D420 = fn_8000CCB8();
        if (lbl_8055D420 == -1) {
            lbl_8055D407 = 0;
        }
    }
}

u8 fn_8000D75C(void) {
    return lbl_8055D404;
}

s32 fn_8000D764(void) {
    if (lbl_8055D404 != 0) {
        return -1;
    }
    return fn_8000CCB8();
}

extern s32 fn_80019BA8(void);
s32 fn_8000C7CC(void) {
    return fn_80019BA8() == 0;
}

#pragma dont_inline on
#pragma scheduling off
u32 fn_8000C7F4(s32 arg0) {
    if (fn_8000C7CC() == 0) {
        return 1;
    }
    return (u32)((2 - arg0) | (arg0 - 2)) >> 31;
}
#pragma scheduling on
#pragma dont_inline off
s32 fn_8000C840(void) {
    return 1;
}

s32 fn_8000C848(s32 arg0) {
    switch (arg0) {
    case 0x126:
        if (lbl_8055D406 == 0) { lbl_8055D406 = 1; fn_80230E90(1); }
        goto done;
    case 0x128:
        if (lbl_8055D406 != 0) { lbl_8055D406 = 0; fn_80230E90(1); }
        goto done;
    case 0x1B:
    case 0x53:
        lbl_8055D406 = 0;
    case 0x58:
    case 0xD:
        if (lbl_8055D406 != 0) {
            if (((s32 (*)(s32))fn_8000C840)(lbl_8055D400) != 0) {
                lbl_8055D404 = 0;
                if (((s32 (*)(s32))lbl_8055D408)(lbl_8055D400) == 0) lbl_8055D404 = 1;
            }
        } else lbl_8055D405 = 0;
        goto done;
    default:
        return 0;
    }
done:
    fn_80012158();
    return 1;
}

s32 fn_8000CCB8(void) {
    s32 i = 0;
    goto compare;
body:
    if (fn_800075A0(i) != 0) {
        __AXGetStackHead_80137CFC(i);
        if (fn_802E8504() == 0) {
            return i;
        }
    }
    i++;
compare:
    if (i < fn_80137C74()) {
        goto body;
    }
    return -1;
}

extern void fn_80148070(void *, s32, s32);
extern void fn_80148134(f32 *, f32 *, s32, f32, f32);
extern s32 fn_80131234(s32);
extern void fn_801476C4(void);
extern void fn_800103B8(s32, s32, const char *, s32, f32, f32, f32, f32);
extern void fn_80011A2C(void);
extern f32 lbl_80560248;
extern s32 lbl_80560240;
extern s32 lbl_80560244;
extern const char lbl_80558A70[];
void fn_8000CD24(void) {
    u8 *base = lbl_802FC058;
    void *object;
    void *temp;
    f32 out0;
    f32 out1;
    s32 names[2];
    if (lbl_8055D414 == 0) return;
    object = ((void *(*)(void *, const char *))(*(void ***)lbl_8055D414)[5])(lbl_8055D414, (const char *)base + 0xFC);
    if (object != 0) {
        temp = ((void *(*)(void *, const char *))(*(void ***)lbl_8055D414)[6])(lbl_8055D414, (const char *)base + 0x108);
        fn_80148070(object, 0x96FFFFFF, (s32)temp);
    }
    ((void (*)(void *, const char *))(*(void ***)lbl_8055D414)[3])(lbl_8055D414, (const char *)base + 0x118);
    fn_801476C4();
    temp = ((void *(*)(void *, const char *))(*(void ***)lbl_8055D414)[3])(lbl_8055D414, (const char *)base + 0x12C);
    if (temp == 0) return;
    names[0] = lbl_80560240;
    names[1] = lbl_80560244;
    out0 = *(f32 *)((u8 *)temp + 4);
    out1 = *(f32 *)((u8 *)temp + 8);
    fn_80148134(&out0, &out1, *(s32 *)((u8 *)temp + 0xC), out0, out1);
    fn_800103B8(*(s32 *)((u8 *)temp + 0x18), *(s32 *)((u8 *)temp + 0x14), lbl_80558A70, fn_80131234(names[lbl_8055D420]), *(f32 *)((u8 *)temp + 0x10), out0, out1, *(f32 *)((u8 *)object + 0x10) - lbl_80560248);
    fn_80011A2C();
}

