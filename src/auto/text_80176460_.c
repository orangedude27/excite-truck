// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern u8 lbl_804303C8[12];
extern char lbl_8055E3BD;
extern void *lbl_8055A2F0;
extern s32 lbl_8055E3D8;
extern f32 lbl_8055A3A0;
extern f32 lbl_80561B18;
extern char *strcpy(char *, const char *);
extern s32 fn_8012F31C(s32);
extern s32 fn_8012F3CC(void);
extern void fn_8012F43C(void);
extern void fn_801E1D20(void);
extern void fn_80178DD0(void);
extern void fn_8017EBE0(void);
extern void fn_801AE5A8(void);
extern void fn_801B6604(void);
extern void fn_801D0BE4(void);
extern void fn_80177790(void);
extern void *lbl_8055E3E8;
extern void __AXDSPInitCallback_801769E0(void);
extern u8 lbl_8055E3E4;
extern char lbl_803316B4[];
extern char lbl_8033189C[];
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
extern s32 fn_802E2C20();
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
extern f32 fn_8017970C(void);
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

#pragma dont_inline on
void fn_80176610(void) {
    fn_80176CC8();
}
#pragma dont_inline reset

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

extern char lbl_803315E8[];
extern s32 fn_80209110(s32 *);
void fn_801766C4(void) {
    s32 i = 0;
    lbl_8055E3F4 = 7;
    goto check_state;
loop:
    fn_80176CC8();
    i += 1;
    if (i >= 10)
        fn_802E317C(lbl_803315E8);
check_state:
    if (lbl_8055E3F4 != 8)
        goto loop;
    fn_80209110(&lbl_8055E3F0);
}

#pragma scheduling invalid_target
void fn_80176734(void) {
    if (fn_80176F9C() != 0) {
        fn_802E30C8(lbl_80331604);
    }
    lbl_804303D4[0] = 4;
    fn_80177048();
}
#pragma scheduling on
void fn_8017677C(void) {
}

#pragma push
#pragma scheduling invalid_target
void fn_80176780(u32 arg0, u8 *arg1) {
    s32 flags;
    u32 masked;
    masked = arg0 & 0x1FF00;
    arg0 = (u8)arg0;
    flags = masked & ~(((s32)(-(s32)lbl_8055E3E4 | (s32)lbl_8055E3E4) >> 31) & 0x100);
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
#pragma scheduling on
#pragma pop
void fn_80176858(void) {
    fn_80177138();
}

#pragma push
#pragma scheduling invalid_target
void fn_8017685C(s32 arg0) {
    s32 i;

    if (arg0 != 3) {
        __AXDSPInitCallback_801769E0();
        lbl_8055E3F4 = 5;
        i = 0;
        goto first_test;
    first_body:
        fn_80176CC8();
        i += 1;
        if (i >= 10) {
            fn_802E317C(lbl_803316EC);
        }
    first_test:
        if (lbl_8055E3F4 == 5) {
            goto first_body;
        }
    }
    lbl_8055E3E8 = (void *)arg0;
    lbl_8055E3EC = 1;
    i = 0;
    goto second_test;
second_body:
    fn_80176CC8();
    i += 1;
    if (i >= 10) {
        fn_802E317C(lbl_8033170C);
    }
second_test:
    if (lbl_8055E3EC != 0) {
        goto second_body;
    }
}
#pragma scheduling on
#pragma pop
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

#pragma scheduling invalid_target
int fn_80176F9C(void) {
    s32 v = *(s32 *)(lbl_80430558 + 0xC);
    return v != 0 && v != 3;
}
#pragma scheduling on
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
#pragma push
#pragma opt_common_subs off
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
#pragma pop
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
#pragma dont_inline on
void* fn_80176A1C(void) {
    return lbl_8055A2F0;
}
#pragma dont_inline reset

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

void *fn_80176A70(void) {
    char *base;
    s32 snap;
    s32 startTime;
    s32 count;
    u64 start;
    u64 now;
    u64 elapsed;
    f32 scaled;
    void *p;

    base = lbl_803315A0;
    snap = lbl_8055E3C4;
    startTime = fn_802E2C20();
    count = 0;
    start = fn_802E2C9C();
    now = start;

loop:
    fn_80176610();
    if ((s32)fn_80176A1C() == 2 || (u8)lbl_8055E3BD != 0 ||
        snap != lbl_8055E3C4 || fn_802D3EBC() != 0) {
        goto done;
    }
    fn_802E2D74(0);
    if (fn_802E2C20() - startTime > 0x2710) {
        fn_802E30C8(base + 0x190, fn_8017970C());
        fn_802E317C(base + 0x1C8, 10);
    }
    count++;
    if ((u16)count == 0) {
        fn_802E30C8(base + 0x204, count);
    }
    now = fn_802E2C9C();
    goto loop;

done:
    elapsed = now - start;
    scaled = lbl_80561B30 * fn_8002FD54((u32)(elapsed >> 32), (u32)elapsed);
    lbl_8055E3D0 = scaled + lbl_80561B34 * (lbl_8055E3D0 - scaled);
    p = fn_80179824();
    ((s32 *)p)[0x36C] = fn_801773E4();
    fn_801C6AD0(&((s32 *)p)[0x36C]);
    return p;
}

void fn_80176BA8(void) {

}

void fn_80176BAC(void) {
    f32 now;
    f32 delta;
    f32 upper;
    f32 lower;
    now = lbl_8055E3C8;
    delta = now - lbl_8055E3FC;
    upper = lbl_80561B38;
    upper = (upper < delta) ? delta : upper;
    lower = *(volatile f32 *)&lbl_80561B3C;
    lower = (lower < upper) ? lower : upper;
    fn_8017ED00(lower);
    lbl_8055E3FC = now;
}

#pragma scheduling invalid_target
s32 *fn_80176C0C(s32 *arg0, s32 *arg1) {
    register s32 length = *arg1;
    register s32 *source = arg1 + 1;
    *arg0 = length;
    memcpy(arg0 + 1, source, length);
    return arg0;
}
#pragma scheduling on
#pragma dont_inline on
void fn_80176C4C(void) {
    if (*(volatile s32 *)lbl_804303D4 != 4) {
        ((s32 *)lbl_804303C8)[0] = *(s32 *)lbl_804303D4;
        ((s32 *)lbl_804303C8)[1] = ((s32 *)lbl_804303D4)[1];
        ((u8 *)lbl_804303C8)[8] = ((u8 *)lbl_804303D4)[8];
        *(s32 *)lbl_804303D4 = 4;
        ((s32 *)lbl_804303D4)[1] = 0;
        memset(lbl_804303D4 + 2, 0, 1);
    }
    fn_80179320();
    lbl_8055E3F4 = 3;
}

#pragma dont_inline fn_80176C4C
void fn_80176CC8(void) {
    fn_802E4C14(1);
    if (lbl_80430418 != 0) {
        u8 *data = (u8 *)&lbl_80430418;
        fn_80178CAC(*(u32 *)(data + 4), *(u32 *)(data + 8));
        lbl_80430418 = 0;
    }
    switch ((u32)lbl_8055E3F4) {
        case 0:
            ((void (*)(s32))fn_80178DD4)(lbl_8055E3DC);
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
        case 6:
        case 7:
        case 8:
        default:
            goto log_state;
    }
    goto check_flags;
log_state:
    fn_802E317C(lbl_80331810, *(volatile s32 *)&lbl_8055E3F4);
check_flags:
    if (*(u8 *)&lbl_8055E3D4 != 0) {
        fn_801B235C();
        lbl_8055E3D4 = 0;
    }
    if (lbl_8055E3EC != 0) {
        fn_80179140();
        lbl_8055E3EC = 0;
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
#pragma scheduling invalid_target
// fn_80176E4C matches with invalid_target scheduling for the address setup order.
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

void fn_80176EC0(void) {
    if (lbl_804303D4[0] != 4) {
        fn_801AED68();
        if (lbl_804303D4[1] & 0x200) {
            fn_801AED5C();
        }
    }
    if (fn_801CF050() == 0) {
        fn_80176A34(0);
    }
    fn_80176C4C();
}

#pragma scheduling on
void fn_80176F24(void) {
    fn_80176EC0();
}

void fn_80176F28(void) {
    fn_80176EC0();
    fn_801769EC();
    *(s32 *)(lbl_80430558 + 0xC) = 1;
    *(s32 *)(lbl_80430558 + 0x10) = 0;
    *(s32 *)(lbl_80430558 + 4) = ((s32 (*)(void))fn_802E2C20)() + 0x32;
    *(s32 *)lbl_80430558 = lbl_8055E3C4 + 3;
    *(s32 *)(lbl_80430558 + 8) = 0;
    *(u8 *)(lbl_80430558 + 0x14) = 0;
}

void fn_801775EC(void) {
    u8 *p = lbl_80430558;
    p[0x14] = 0xFF;
    *(s32 *)(p + 0xC) = 3;
}

#pragma cplusplus on
extern "C" void fn_80177608(void* obj) {
    struct Dummy {
        virtual void f0();
    };
    ((Dummy*)obj)->f0();
}

extern "C" void fn_80177618(int* obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
    };
    ((Dummy*)obj)->f1();
}

extern "C" void fn_80177628(void* obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
    };
    ((Dummy*)obj)->f2();
}
#pragma cplusplus on
extern "C" void fn_80177638(int* obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
    };
    ((Dummy*)obj)->f3();
}
#pragma cplusplus on
extern "C" void fn_80177648(int* obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
    };
    ((Dummy*)obj)->f4();
}
#pragma cplusplus off
extern s32 lbl_8055E400;
extern s32 lbl_80430570[];
void fn_80177658(void *arg0) {
    s32 i;
    for (i = 0; i < lbl_8055E400; i++) {
        ((void (*)(s32))arg0)(lbl_80430570[i]);
    }
}

extern char lbl_80331850[];
void fn_801776C4(u32 arg0) {
    s32 count = lbl_8055E400;
    u32 *entry = (u32 *)lbl_80430570;
    s32 i;
    for (i = count; i > 0; --i) {
        if (arg0 == *entry) {
            fn_802E317C(lbl_80331850);
            return;
        }
        entry++;
    }
    lbl_80430570[lbl_8055E400] = arg0;
    lbl_8055E400++;
}

void fn_80177720(u32 arg0) {
    s32 i;
    for (i = 0; i < lbl_8055E400; i++) {
        if (arg0 == (u32)lbl_80430570[i]) {
            lbl_8055E400--;
            memmove(&lbl_80430570[i], &lbl_80430570[i + 1],
                    (lbl_8055E400 - i) * sizeof(s32));
            return;
        }
    }
    fn_802E317C(lbl_8033189C);
}

extern void fn_80177658(void *);
extern void fn_80177608(void *);
extern void fn_80177618(int *);
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

void fn_801777CC(u32 arg0) {
    fn_801776C4(arg0);
}

extern char lbl_8033189C[];
void fn_801777D0(u32 arg0) {
    fn_80177720(arg0);
}


