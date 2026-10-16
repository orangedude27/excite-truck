// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <revolution/MTX/vec.h>
#pragma opt_tail_call on
extern "C" f64 fn_8002F234(f32);

extern "C" void fn_8019EBC0(void);
extern "C" void fn_8019F3D0(void);
extern "C" void fn_801A49E8(void*);
extern "C" void fn_801A49FC(s32);
extern "C" void fn_801796EC(s32, s32*, s32);
extern "C" s32 fn_8012C4E4(void*, void*, s32);
extern "C" s32 fn_801CFF18(s32, s32);
extern "C" void fn_801D0650(void);
extern "C" void fn_801CFF14(void);
extern "C" s32 fn_801CF828(s32, s32, s32, s32, s32);
extern s32 lbl_8055E5A0;

class VTab19 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void slot0x4C();
};

class VTab13 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual void slot0x34(s32);
};

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801A4A10(s32, s32, s32);
extern "C" void fn_801A44D4(void*);
extern void* lbl_8055A508;
extern void* lbl_8055A510;

void fn_8019F1A4(void) __attribute__((noreturn));

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_8019A780(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

extern "C" s32 fn_8019BD4C(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" s32 fn_8019E834(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8019EBE0(void* self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 v1 = (s32)self;
    s32 v2 = a;
    s32 v3 = b;
    s32 v4 = c;
    s32 v5 = d;
    s32 v6 = e;
    s32 v7 = f;
    s32 obj = *(s32*)((u8*)self + 4);

    if (obj != 0) {
        fn_8017B5D4(obj, v1, v2, v3, v4, v5, v6);
        return;
    }

    obj = *(s32*)((u8*)self + 8);
    if (obj != 0) {
        fn_801A4A10(obj, v4, v7);
    }

    return (void)v1, (void)v2, (void)v3, (void)v5, (void)v6;
}

extern "C" void fn_8019EC84(void* this_) {
    VTab19* p = *(VTab19**)((u8*)this_ + 4);
    if (p == NULL) {
        return;
    }
    p->slot0x4C();
}

extern "C" void fn_8019ECA4(VTab13* this_, s32 arg1) {
    *(s32*)((u8*)this_ + 8) = arg1;
    this_->slot0x34(arg1 + 4);
}

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801A4A10(s32, s32, s32);
extern "C" void fn_8019ECBC(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0xC) = arg1;
}

extern "C" void fn_8019F3D0(void) {

}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_8019F3D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8019F560(void) {
    fn_8019F1A4();
}

extern "C" void fn_8019FF88(void) {
    fn_8019EBC0();
}

extern "C" s32 fn_801A010C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A1358(void *arg0, s32 arg1) { *(s32 *)((u8 *)arg0 + 0x1C) = arg1; }

extern "C" s32 fn_801A2434(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A2EC8(void) {

}

void fn_801A442C(void *arg0, void *arg1, void *arg2) {
    *(f32 *)((u8 *)arg1 + 0) = *(f32 *)((u8 *)arg0 + 0x28);
    *(f32 *)((u8 *)arg1 + 4) = *(f32 *)((u8 *)arg0 + 0x2C);
    *(f32 *)((u8 *)arg1 + 8) = *(f32 *)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg2 + 0) = *(f32 *)((u8 *)arg0 + 0x34);
    *(f32 *)((u8 *)arg2 + 4) = *(f32 *)((u8 *)arg0 + 0x38);
    *(f32 *)((u8 *)arg2 + 8) = *(f32 *)((u8 *)arg0 + 0x3C);
}

f32 fn_801A4460(void *arg0) {
    f32 first;
    f32 second;
    first = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x34), (const Vec *)((u8 *)arg0 + 0x34));
    second = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x28), (const Vec *)((u8 *)arg0 + 0x28));
    if (second > first) {
        first = second;
    }
    return (f32)fn_8002F234(first);
}

extern "C" void fn_801A44C4(void* arg0) {
    fn_801CFF18(*(s32*)((u8*)arg0 + 0x24), *(s32*)((u8*)arg0 + 0xC));
}

extern "C" void fn_801A44D4(void* arg0) {
    s32* r29;
    s32 r30;
    s32 r31;
    r29 = (s32*)arg0;
    r30 = 0;
    r31 = 0;
    goto check;
loop:
    {
        s32* arr = (s32*)r29[1];
        fn_801A49FC(*(s32*)((u8*)arr + r30));
        r30 += 4;
        r31++;
    }
check:
    {
        s32 limit = r29[0];
        if (r31 < limit) goto loop;
    }
}

extern "C" void fn_801A4538(void* arg0) {
    fn_8012C4E4(arg0, &fn_801A44D4, 0);
}

#pragma opt_tail_call on
void fn_801A4768(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}
#pragma opt_tail_call on
void fn_801A47C8(void* arg0) {
    s32 limit = *(s32*)arg0;
    s32** ptrs = *(s32***)((u8*)arg0 + 4);
    for (s32 i = 0; i < limit; i++) {
        ((u8*)ptrs[i])[0x40] = 1;
    }
}

#pragma opt_tail_call on
void fn_801A47FC(void* arg0) {
    if (arg0) {
        s32 limit = *(s32*)arg0;
        s32** ptrs = *(s32***)((u8*)arg0 + 4);
        for (s32 i = 0; i < limit; i++) {
            fn_801A49E8((void*)ptrs[i]);
        }
    }
}

#pragma opt_tail_call on
void fn_801A4868(void* arg0, u8 arg1) {
    if (*(u8*)((u8*)arg0 + 0x40) != arg1) {
        s32 local38;
        u8 localC;
        local38 = *(s32*)((u8*)arg0 + 0x38);
        localC = arg1;
        fn_801796EC(12, &local38, 8);
        *(u8*)((u8*)arg0 + 0x40) = arg1;
    }
}

void fn_801A48C8(void* arg0) {
    void* ptr = *(void**)((u8*)arg0 + 0x48);
    ((void(*)(void*, void*, void**))(*(void***)((u8*)ptr + 0x18)))(ptr, &lbl_8055A508, &lbl_8055A510);
}

void fn_801A49E8(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x48) != 0) {
        fn_801D0650();
    }
}

extern "C" void fn_801D06C4(void);
void fn_801A49FC(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x48) != 0) fn_801D06C4();
}

void fn_801A4E54(void) {
    if (lbl_8055E5A0 != 0) {
        fn_801CFF14();
        lbl_8055E5A0 = 0;
    }
}

extern "C" void fn_801D0650(void);
extern s32 lbl_8055E5A0;
extern void fn_801CFF14(void);
extern s32 fn_801CF828(s32, s32, s32, s32, s32);
extern "C" s32 fn_801A4E88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32* arg4) {
    s32 a = arg0;
    s32 b = arg1;
    s32 c = arg2;
    s32 d = arg3;
    s32* out = arg4;
    if (lbl_8055E5A0 != 0 && fn_801CF828(lbl_8055E5A0, a, b, c, d) != 0) {
        *out = 0x6E;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801A4F00(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F40(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F80(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4FC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5000(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5040(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5080(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A50C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" f32 fn_801A5100(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" void fn_801A5108(void* arg0) {
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

extern "C" f32 fn_801A5114(void *arg0) {
    return ((f32 *)arg0)[0x30 / 4];
}

extern "C" f32 fn_801A511C(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" float fn_801A5124(void* arg0) {
    return *(float*)((char*)arg0 + 0x28);
}

extern "C" s32 fn_801A512C(void) {
    return 0;
}

extern "C" s32 fn_801A5134(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5174(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x48);
}

extern "C" s32 fn_801A517C(s32 arg0) {
    return arg0 + 0x28;
}

u8 fn_801A5184(void* arg0) { return *(u8*)((u8*)arg0 + 0x40); }

extern "C" void fn_801A4868(void);

extern "C" void fn_801A4868(void);
extern "C" void fn_801A4868(void*, u8);

extern "C" void fn_801A518C(void) {
    fn_801A4868();
}

extern "C" void fn_801A5190(void* arg0) {
    VTab19* p = *(VTab19**)((u8*)arg0 + 0x3C);
    if (p == NULL) {
        return;
    }
    p->v14();
}

extern "C" s32 fn_801A51B0(void* arg0) {
    void* obj = *(void**)((u8*)arg0 + 0x3C);
    if (obj != NULL) {
        return *(s32*)((u8*)obj + 0x20);
    }
    return -1;
}

extern "C" s32 fn_801A51CC(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x34);
}

extern "C" void fn_801A51D4(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0x34) = arg1;
}

