// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern u8 lbl_8055E3E4;
extern char lbl_803316B4[];
int fn_80176F9C(void);
void fn_80176F24(void);
void fn_80176FC4(void);
void fn_801775EC(void);
void fn_80177048(void);

extern void fn_80179308(void);
extern u8 lbl_80430558[];
extern s32 lbl_804303D4[];
extern void fn_801AED68(void);
extern void fn_801AED5C(void);
extern s32 fn_801CF050(void);
extern void fn_80176A34(s32);
extern void fn_80176C4C(void);
extern s32 fn_802E2C20(void *);
extern void fn_80176F28(void);
extern void fn_80176DD4(void);
extern f32 lbl_8055A2F4;
extern s32 lbl_8055E3C4;
extern f32 lbl_8055E3C8;
extern f32 lbl_80561B20;
extern f32 lbl_8055E460;
extern f32 lbl_80561B1C;
extern s32 lbl_8055E3C0;
void fn_8013A208(void);
extern s32 lbl_8055E3CC;
extern u32 lbl_8055E3F8;
extern s32 lbl_8055E3E0;
extern s32 lbl_8055E3F4;
extern u8 lbl_8055E3EC;
extern char lbl_80331604[];
extern void fn_802E30C8(const char *, ...);
extern char lbl_803316EC[];
extern char lbl_8033170C[];
extern f32 lbl_8055E3FC;
extern f32 lbl_80561B38;
extern f32 lbl_80561B3C;
s32 fn_8012F458(s32, s32);
s32 fn_8012F4AC(s32, void *, s32);
s32 fn_80179658(s32);
__declspec(section ".data") extern u8 lbl_80430418;
extern u32 jumptable_8033182C[];
extern const char lbl_80331810[];
extern char lbl_8055E3D4;
extern void fn_802E4C14(s32);
extern void fn_80178CAC(u32, u32);
extern void fn_80178DD4(void);
extern void fn_8017952C(void);
extern void fn_80179110(void);
extern void fn_801791A8(void);
extern void fn_80179140(void);
extern void fn_801B235C(void);
void fn_80176CC8(void);
void fn_802E317C(const char *, ...);
s32 fn_8017ED00(f32);
void fn_80177138(void);
extern void fn_80176E4C(void);
extern s32 fn_8012F450(s32);
extern s32 fn_8012F384(s32);
extern s32 fn_8012F418(s32);
extern void fn_801D0BF4(void);
extern void fn_801B6614(void);
extern void fn_801AE5AC(void);
extern void fn_8017EC30(void);
extern void fn_801E1D2C(void);
extern void fn_801777C0(void);
extern void fn_8017779C(void);
extern void fn_80176DE0(void);
extern s32 fn_802090D4(s32);
extern s32 lbl_8055E3DC;
extern s32 lbl_8055E3F0;
extern s32 lbl_8055A2F8;
extern char lbl_803315A0[];
extern char lbl_803315C8[];
extern u8 lbl_8055E3BC;
extern u64 fn_802E2C9C(void);
extern void fn_802E2D74(s32);
extern void fn_8017970C(void);
extern f32 fn_8002FD54(u32, u32);
extern void *fn_80179824(void);
extern s32 fn_801773E4(void);
extern void fn_801C6AD0(s32 *);
extern f32 lbl_8055E3D0;
extern f32 lbl_80561B30;
extern f32 lbl_80561B34;

void fn_801765B8(void) {
    fn_801777C0();
    lbl_8055E3F4 = 0;
    fn_801D0BF4();
    fn_801B6614();
    fn_801AE5AC();
    fn_8017EC30();
    fn_8012F418(lbl_8055E3E0);
    fn_8012F384(lbl_8055E3DC);
    fn_801E1D2C();
    lbl_8055E3BC = 0;
}

void fn_80176610(void) {
    fn_80176CC8();
}

void fn_80176614(void) {
    s32 i;
    lbl_8055E3F4 = 1;
    fn_8012F458(lbl_8055E3E0, -1);
    fn_802E30C8(lbl_803315A0, fn_8012F450(lbl_8055E3E0), 0x10000);
    i = 0;
    goto loop_test;
loop_body:
    fn_80176CC8();
    i++;
    if (i >= 10) fn_802E317C(lbl_803315C8);
loop_test:
    if (lbl_8055E3F4 == 1) goto loop_body;
    lbl_8055E3F4 = 3;
    fn_80176DE0();
    lbl_8055E3F0 = fn_802090D4((s32)&lbl_8055A2F8);
    fn_8017779C();
}

void fn_8017677C(void) {
}

void fn_80176780(u32 arg0, u8 *arg1) {
    s32 flags;
    u32 masked;
    masked = arg0 & 0x1FF00;
    arg0 = (u8)arg0;
    flags = masked & ~(-(lbl_8055E3E4 != 0) & 0x100);
    ((void (*)(u32, u32, u32, u32))fn_8017677C)(arg0, flags, lbl_8055E3E4, masked);
    if (fn_80176F9C()) fn_802E30C8(lbl_803316B4);
    lbl_804303D4[0] = arg0;
    lbl_804303D4[1] = flags;
    if (arg1) *((u8 *)lbl_804303D4 + 8) = *arg1;
    if (flags & 0x1000) fn_80176F24();
    else if (flags & 0x8000) fn_80176FC4();
    else if (flags & 0x10000) { fn_801775EC(); fn_80177048(); }
    else fn_80177048();
}

void fn_80176858(void) {
    fn_80177138();
}

int fn_80176F9C(void);
void fn_801770C8(void);
void fn_80177048(void);
void fn_8017691C(void) {
    if (fn_80176F9C() == 0) {
        fn_801770C8();
    }
}

void fn_80176948(void *arg0, s32 *arg1) {
    s32 value = lbl_8055E3CC;
    *arg1 = value;
    fn_8012F458(lbl_8055E3E0, value);
    fn_8012F4AC(lbl_8055E3E0, arg0, *(s32 *)((char *)arg0 + 4));
    lbl_8055E3CC += fn_80179658(*(s32 *)arg0);
}

s32 fn_801769A8(void);
extern u8 lbl_804303C8[12];
s32 fn_801769A8(void) {
    return ((s32*)lbl_804303C8)[1];
}

void *fn_801769B8(void) { return *(void **)&lbl_804303C8; }

extern void *lbl_8055E3E8;
void* fn_801769C4(void) {
    return lbl_8055E3E8;
}

extern u8 lbl_804303E0[];
void *__AXFXGetLfoSinTable_801769CC(void) {
    return lbl_804303E0;
}

u32 *fn_801769D8(void) { return &lbl_8055E3F8; }

extern void __AXDSPInitCallback_801769E0(void);
extern void fn_801769EC(void);

int fn_80176F9C(void) {
    s32 v = *(s32 *)(lbl_80430558 + 0xC);
    if (v == 0 || v == 3)
        return 0;
    return 1;
}

void fn_80176FC4(void) {
    if (*(s32 *)(lbl_80430558 + 0xC) == 3) {
        fn_80176F28();
    } else {
        *(volatile void **)(lbl_80430558 + 0x10) = (void *)fn_80176F28;
        *(volatile s32 *)(lbl_80430558 + 0xC) = 2;
        *(s32 *)(lbl_80430558 + 4) = fn_802E2C20((void *)fn_80176F28);
        *(s32 *)lbl_80430558 = lbl_8055E3C4;
        *(s32 *)(lbl_80430558 + 8) = 7;
        *(u8 *)(lbl_80430558 + 0x14) = 0;
        __AXDSPInitCallback_801769E0();
    }
    fn_801769EC();
}

void fn_80177048(void) {
    if (*(s32 *)(lbl_80430558 + 0xC) == 3) {
        fn_80176F28();
        return;
    }
    *(void **)(lbl_80430558 + 0x10) = (void *)fn_80176F28;
    *(s32 *)(lbl_80430558 + 0xC) = 2;
    *(s32 *)(lbl_80430558 + 4) = fn_802E2C20((void *)fn_80176F28);
    *(s32 *)lbl_80430558 = lbl_8055E3C4;
    *(s32 *)(lbl_80430558 + 8) = 7;
    *(u8 *)(lbl_80430558 + 0x14) = 0;
    __AXDSPInitCallback_801769E0();
}

void fn_801770C8(void) {
    *(void **)(lbl_80430558 + 0x10) = fn_80176DD4;
    *(s32 *)(lbl_80430558 + 0xC) = 2;
    *(s32 *)(lbl_80430558 + 4) = fn_802E2C20((void *)fn_80176DD4);
    *(s32 *)lbl_80430558 = lbl_8055E3C4;
    *(s32 *)(lbl_80430558 + 8) = 7;
    *(u8 *)(lbl_80430558 + 0x14) = 0;
    __AXDSPInitCallback_801769E0();
    fn_801769EC();
}

void fn_80177138(void) {
    *(void **)(lbl_80430558 + 0x10) = fn_80176E4C;
    *(s32 *)(lbl_80430558 + 0xC) = 2;
    *(s32 *)(lbl_80430558 + 4) = fn_802E2C20((void *)fn_80176E4C);
    *(s32 *)lbl_80430558 = lbl_8055E3C4;
    *(s32 *)(lbl_80430558 + 8) = 7;
    *(u8 *)(lbl_80430558 + 0x14) = 0;
    __AXDSPInitCallback_801769E0();
    fn_801769EC();
}

void __AXDSPInitCallback_801769E0(void) {
    lbl_8055E3C0 = 1;
}

void fn_801769EC(void) {
    lbl_8055E3C0 = 2;
    fn_8013A208();
}

extern char lbl_8055E3BD;
char fn_801769F8(void) {
    return lbl_8055E3BD;
}

extern void* lbl_8055A2F0;
void fn_80176A00(s32 arg0) {
    *(volatile s32*)&lbl_8055A2F0 = arg0;
    if (*(volatile s32*)&lbl_8055A2F0 == 1) {
        lbl_8055E460 = lbl_80561B1C;
    }
}

extern void *lbl_8055A2F0;
void* fn_80176A1C(void) {
    return lbl_8055A2F0;
}

void fn_80176A24(f32 arg0) {
    lbl_8055A2F4 = arg0;
}

extern f32 fn_80176A2C(void);
f32 fn_80176A2C(void) {
    return lbl_8055A2F4;
}

void fn_80176A34(s32 arg0) {
    lbl_8055E3C4 = arg0;
    lbl_8055E3C8 = lbl_80561B20 * (f32)arg0;
}

void fn_80176A6C(void) {
    fn_801771A8();
}

void fn_80176BA8(void) {

}

void fn_80176BAC(void) {
    f32 now = lbl_8055E3C8;
    f32 delta = now - lbl_8055E3FC;
    f32 value = delta;
    if (value > lbl_80561B38)
        value = lbl_80561B38;
    if (value < lbl_80561B3C)
        value = lbl_80561B3C;
    fn_8017ED00(value);
    lbl_8055E3FC = now;
}

s32 *fn_80176C0C(s32 *arg0, s32 *arg1) {
    s32 length = *arg1;
    *arg0 = length;
    memcpy((u8 *)arg0 + 4, (u8 *)arg1 + 4, length);
    return arg0;
}

void fn_80176C4C(void) {
    if (*(s32 *)lbl_804303D4 != 4) {
        ((s32 *)lbl_804303C8)[0] = *(s32 *)lbl_804303D4;
        ((s32 *)lbl_804303C8)[1] = ((s32 *)lbl_804303D4)[1];
        lbl_804303C8[8] = lbl_804303D4[2];
        *(s32 *)lbl_804303D4 = 4;
        ((s32 *)lbl_804303D4)[1] = 0;
        memset(lbl_804303D4 + 2, 0, 4);
    }
    fn_80179320();
    lbl_8055E3F4 = 3;
}

void fn_80176CC8(void) {
    fn_802E4C14(1);
    if (lbl_80430418 != 0) {
        fn_80178CAC(lbl_80430418, 0);
        lbl_80430418 = 0;
    }
    if (lbl_8055E3F4 < 8) {
        switch (lbl_8055E3F4) {
            case 0:
                fn_80178DD4();
                lbl_8055E3F4 = 2;
                break;
            case 1:
                fn_8017952C();
                break;
            case 2:
                fn_80176C4C();
                break;
            case 3:
                fn_80179110();
                fn_8017952C();
                lbl_8055E3F4 = 6;
                break;
            case 4:
                fn_8017952C();
                break;
            case 5:
                fn_801791A8();
                lbl_8055E3F4 = 8;
                break;
        }
    } else {
        fn_802E317C(lbl_80331810);
        if (lbl_8055E3D4 != 0) {
            fn_801B235C();
            lbl_8055E3D4 = 0;
        }
        if (lbl_8055E3EC != 0) {
            fn_80179140();
            lbl_8055E3EC = 0;
        }
    }
}

extern char lbl_8055E3D4;
void fn_80176DD4(void) {
    lbl_8055E3D4 = 1;
}

void fn_80176DE0(void) {
    *(s32 *)(lbl_80430558 + 0xC) = 1;
    *(s32 *)(lbl_80430558 + 0x10) = 0;
    *(s32 *)(lbl_80430558 + 4) = ((s32 (*)(void))fn_802E2C20)() + 0x32;
    *(s32 *)lbl_80430558 = lbl_8055E3C4 + 3;
    *(s32 *)(lbl_80430558 + 8) = 0;
    *(u8 *)(lbl_80430558 + 0x14) = 0;
}

#pragma dont_inline on
void fn_80176E4C(void) {
    fn_80179308();
    fn_801769EC();
    *(s32 *)(lbl_80430558 + 0xC) = 1;
    *(s32 *)(lbl_80430558 + 0x10) = 0;
    *(s32 *)(lbl_80430558 + 4) = ((s32 (*)(void))fn_802E2C20)() + 0x32;
    *(s32 *)lbl_80430558 = lbl_8055E3C4 + 3;
    *(s32 *)(lbl_80430558 + 8) = 0;
    *(u8 *)(lbl_80430558 + 0x14) = 0;
}
void fn_80176F24(void) {
    fn_80176EC0();
}

void fn_801775EC(void) {
    u8 *p = lbl_80430558;
    p[0x14] = 0xFF;
    *(s32 *)(p + 0xC) = 3;
}

void fn_80177618(int *arg0)
{
    int *vtable = *(int **)arg0;
    volatile void (*fn)(void) = *(volatile void (**)(void))(vtable + 3);
    fn();
}

void fn_80177628(int* param_1)
{
    struct T { int a; int b; int c; int d; void (*fn)(void); };
    ((struct T*)*param_1)->fn();
}

void fn_80177638(int *arg0) { void (**v)(void) = (void (**)(void))*(void **)arg0; (v + 5)[0](); }

void fn_80177648(int *arg0) { void (**fn)(void) = *(void (***)(void))arg0 + 6; (*fn)(); }

extern s32 lbl_8055E400;
extern s32 lbl_80430570[];
void fn_80177658(void *arg0) {
    s32 i;
    for (i = 0; i < lbl_8055E400; i++) {
        ((void (*)(s32))arg0)(lbl_80430570[i]);
    }
}

extern void fn_80177658(void *);
extern void fn_80177608(void);
extern void fn_80177618(int *);
extern void fn_80177628(int *);
extern void fn_80177638(int *);
void fn_80177790(void) { fn_80177658((void *)fn_80177608); }

#pragma push
#pragma small_data off
void fn_8017779C(void) { fn_80177658((void *)fn_80177618); }
void fn_801777A8(void) { fn_80177658(&fn_80177628); }

void fn_801777B4(void) { fn_80177658(&fn_80177638); }

extern void fn_80177648(int *);
void fn_801777C0(void) {
    fn_80177658(fn_80177648);
}

void fn_801777CC(void) {
    fn_801776C4();
}

void fn_801777D0(void) {
    fn_80177720();
}


