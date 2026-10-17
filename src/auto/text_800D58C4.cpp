// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include "revolution/GX/GXTypes.h"

extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);

struct Obj_800D7738;
struct Vtbl_800D7738 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct Obj_800D7738 : Vtbl_800D7738 {};
struct Ptr_800D7738 { Obj_800D7738* v; };
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void* __ct__Q34nw4r3lyt8DrawInfoFv(void* arg0) {
    extern f32 lbl_80560E78;
    extern f32 lbl_80560E7C;
    extern void* lbl_8031F618;
    extern void memset(void*, int, unsigned int);
    extern void PSMTXIdentity(void*);
    u8* p = (u8*)arg0;
    *(void**)p = &lbl_8031F618;
    *(f32*)(p + 0x34) = lbl_80560E78;
    *(f32*)(p + 0x38) = lbl_80560E78;
    *(f32*)(p + 0x3C) = lbl_80560E78;
    *(f32*)(p + 0x40) = lbl_80560E78;
    *(f32*)(p + 0x44) = lbl_80560E7C;
    *(f32*)(p + 0x48) = lbl_80560E7C;
    *(f32*)(p + 0x4C) = lbl_80560E7C;
    memset(p + 0x50, 0, 1);
    PSMTXIdentity(p + 4);
    return arg0;
}

extern "C" s32 fn_800D67B8(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" void AppendGroup__Q36nw4hbm3lyt14GroupContainerFPQ36nw4hbm3lyt5Group(void* arg0, void* arg1) {
    extern const char lbl_8031F658[];
    extern const char lbl_8031F634[];
    void* sp8 = (u8*)arg0 + 4;
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F658, 0x233, lbl_8031F634);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(arg0, &sp8, (u8*)arg1 + 4);
}

extern "C" void fn_800D6EEC(void* arg0) {
    extern float lbl_80560E80;
    extern char lbl_8031F868[];
    volatile u8* p = (volatile u8*)arg0;
    f32 f = lbl_80560E80;
    *(volatile u32*)(p + 8) = 0;
    *(volatile u32*)(p + 0xC) = 0;
    *(void* volatile*)p = lbl_8031F868;
    *(volatile u32*)(p + 4) = 0;
    *(void* volatile*)(p + 8) = (void*)(p + 8);
    *(void* volatile*)(p + 0xC) = (void*)(p + 8);
    *(volatile u32*)(p + 0x10) = 0;
    *(volatile u32*)(p + 0x14) = 0;
    *(volatile f32*)(p + 0x18) = f;
    *(volatile f32*)(p + 0x1C) = f;
    *(volatile u8*)(p + 0x20) = 0;
}

extern "C" void fn_800D76F4(void *arg0, int arg1, int arg2) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual void v6(); virtual void v7(); virtual void v8();
        virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17();
        virtual void v18(); virtual void v19();
        virtual void v20(int, int, int);
    };
    Obj* obj = *(Obj**)((char*)arg0 + 0x10);
    if (obj) obj->v20(arg1, arg2, 1);
}

extern "C" void fn_800D7718(void *arg0) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
    };
    Obj* obj = *(Obj**)((char*)arg0 + 0x10);
    if (obj) obj->v2();
}

extern "C" void fn_800D7738(void* arg0) {
    Obj_800D7738* p = *(Obj_800D7738**)((char*)arg0 + 0x10);
    if (p != 0) p->v3();
}

extern "C" void fn_800D7758(void *arg0) {
    void **p = *(void ***)((char *)arg0 + 0x10);
    if (p != 0) {
        (*(void (**)(void))(*(char **)p + 0x1c))();
    }
}

extern "C" void GetLayoutRect__Q34nw4r3lyt6LayoutCFv(void* pOut, void* self) {
    u8* p = (u8*)self;
    extern f32 lbl_80560E84;
    extern f32 lbl_80560E80;
    if (p[0x20] == 1) {
        f32 w = *(f32*)&p[0x18];
        f32 h = *(f32*)&p[0x1C];
        f32 s = lbl_80560E84;
        *(f32*)&((u8*)pOut)[8] = w * s;
        *(f32*)&((u8*)pOut)[4] = h * s;
        *(f32*)&((u8*)pOut)[0] = -w * s;
        *(f32*)&((u8*)pOut)[0xC] = -h * s;
    } else {
        f32 z = lbl_80560E80;
        *(f32*)&((u8*)pOut)[0] = z;
        *(f32*)&((u8*)pOut)[4] = z;
        *(f32*)&((u8*)pOut)[8] = *(f32*)&p[0x18];
        *(f32*)&((u8*)pOut)[0xC] = *(f32*)&p[0x1C];
    }
}

extern "C" void fn_800D7F58(void *arg0, void *arg1) {
    f32 v1 = ((f32 *)arg1)[1];
    f32 v0 = ((f32 *)arg1)[0];
    ((f32 *)arg0)[0] = v0;
    ((f32 *)arg0)[1] = v1;
}

extern "C" void fn_800D7F6C(s32 *arg0) {
    *arg0 = -1;
}

extern "C" void fn_800D7F78(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void fn_800D86F0(void *arg0, void *arg1) {
    s16 v0, v1, v2, v3;
    v0 = ((s16 *)arg1)[0];
    v1 = ((s16 *)arg1)[1];
    v2 = ((s16 *)arg1)[2];
    v3 = ((s16 *)arg1)[3];
    ((s16 *)arg0)[0] = v0;
    ((s16 *)arg0)[1] = v1;
    ((s16 *)arg0)[2] = v2;
    ((s16 *)arg0)[3] = v3;
}

extern "C" void GXInitLightColor_800D8714(u32 *arg0, u32 *arg1) {
    *arg0 = *arg1;
}

extern "C" s32 fn_800D8720(s32 *arg0) {
    return *arg0 & 0xF;
}

extern "C" s32 fn_800D872C(u32 *arg0) {
    return (*arg0 >> 4) & 0xF;
}

extern "C" s32 fn_800D8738(u32 *arg0) {
    return (*arg0 >> 8) & 0xF;
}

extern "C" s32 fn_800D8744(u32 *arg0) {
    return (*arg0 >> 25) & 1;
}

extern "C" u32 fn_800D8750(u32 *arg0) {
    return (*arg0 >> 27) & 1;
}

extern "C" u32 fn_800D875C(u32 *arg0) {
    return (*arg0 >> 12) & 1;
}

extern "C" s32 fn_800D8768(u32* arg0) {
    return ((u32)*arg0 >> 0x17U) & 1;
}

extern "C" s32 fn_800D8774(u32* arg0) {
    return ((u32)*arg0 >> 0x18U) & 1;
}

extern "C" s32 fn_800D8780(u32 *arg0) {
    return (*arg0 >> 13U) & 3;
}

extern "C" s32 fn_800D878C(u32 *arg0) {
    return (*arg0 >> 15U) & 7;
}

extern "C" s32 fn_800D8798(u32 *arg0) {
    return (*arg0 >> 18U) & 0x1F;
}

extern "C" void fn_800D87A4(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" int fn_800D87C8(void *arg0) {
    return (*(unsigned int*)((char*)arg0 + 0x4c) >> 8) & 1;
}

extern "C" void fn_800D87D4(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" void fn_800D8804(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" void fn_800D886C(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" s32 fn_800D893C(void *arg0) {
    return ((u32)*(u32*)((u8*)arg0 + 0x4C) >> 6U) & 1;
}

extern "C" void fn_800D8948(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" s32 fn_800D896C(void *arg0) {
    return ((u32)*(u32*)((u8*)arg0 + 0x4C) >> 5U) & 1;
}

extern "C" void fn_800D8978(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" s32 fn_800D899C(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89A4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89AC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89B4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89BC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89C4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89CC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89D4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89DC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" u32 fn_800D89E4(u32 arg0, u32 arg1) {
    if (arg0 > arg1) {
        return arg1;
    }
    return arg0;
}

extern "C" s32 fn_800D89F4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89FC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D8A04(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D9328(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x58);
}

extern "C" s32 fn_800D9330(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x58) + ((*(u32 *)((u8 *)arg0 + 0x4C) >> 0x17) & 0x1E0);
}

extern "C" s32 fn_800D9344(void *arg0) {
    volatile u32 *p = (volatile u32 *)((u8 *)arg0 + 0x4C);
    u32 x = *p;
    s32 y = *(volatile s32 *)((u8 *)arg0 + 0x58);
    return (((x >> 0x17) & 0x1E0) + y) + (((x >> 0x18) & 0xF) * 0x14);
}

extern "C" s32 fn_800D9364(void *arg0) {
    volatile u32 *p = (volatile u32 *)((u8 *)arg0 + 0x4C);
    u32 x = *p;
    s32 y = *(volatile s32 *)((u8 *)arg0 + 0x58);
    return ((x >> 0x12) & 0x3C) + ((x >> 0x17) & 0x1E0) + y + (((x >> 0x18) & 0xF) * 0x14);
}

extern "C" void fn_800DB084(void* arg0) {
    void* vtable = *(void**)arg0;
    (*(void (**)(void*, int))((u8*)vtable + 0x14))(arg0, 0);
}

extern "C" void AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink(void* arg0, void* arg1) {
    extern const char lbl_8031FF54[];
    extern const char lbl_8031FF30[];
    void* sp8 = (u8*)arg0 + 0x1C;
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF54, 0x233, lbl_8031FF30);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8*)arg0 + 0x18, &sp8, arg1);
}

extern "C" void fn_800DB1E8(void* arg0, void* unused, s32 arg2) {
    void* temp = (*(void* (**)(void*))(*(u32*)arg0 + 0x20))(arg0);
    if (temp != 0) *(u8*)((u8*)temp + 0xE) = (u8)!arg2;
}

extern "C" s32 fn_80128668();
extern "C" void fn_800D4F98(void*);
extern "C" s32 fn_800DB398(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" void fn_800DB830(s32 *arg0) {
    *arg0 = -1;
}

extern "C" void fn_800DB83C(void) {

}

extern "C" void fn_800DB960(void) {

}

extern "C" s32 fn_800DC6DC(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

