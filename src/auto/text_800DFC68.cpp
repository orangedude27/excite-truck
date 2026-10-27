#include <types.h>
#define M2C_FIELD(p, T, o) (*(T*)((u8*)(p) + (o)))
extern "C" s32 IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(void *, u8);
extern "C" void SetVertexFormat__Q34nw4r3lyt6detailFbUc(s32, u8);
extern "C" void DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(f32 *, f32 *, u8, f32 (*)[], s32, u8);
namespace nw4r {
namespace math { struct VEC2 { f32 x, y; }; }
namespace lyt {
    struct WindowFrameSize { f32 unk0, unk4, unk8, unkC; };
    struct Window {
        void DrawContent(const nw4r::math::VEC2 &, const WindowFrameSize &, u8);
    };
}
}
namespace nw4hbm { namespace lyt {
    struct Window {
        struct Link { Link* next; Link* prev; };
        u8 unk_0[0x14];
        Link children;
        u8 unk_20[0xC];
        void* material;
        u8 unk_2C[0xD0];
        void* materials;
        u8 materialCount;
        void* FindMaterialByName(const char*, bool);
    };
} }
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" unsigned int lbl_8055DE10;
extern void UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(void*, void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" const char lbl_803204F8[];
extern "C" const char lbl_803204BC[];
extern "C" const char lbl_80320C14[];
extern "C" const char lbl_80320C60[];
extern void* FindAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(void*, void*);
extern "C" const char lbl_8031E8FC[];
extern "C" const char lbl_8031E8D8[];
extern "C" int fn_800D58F0(const char*, const char*);
extern "C" int lbl_8055DDF0;
extern "C" const char lbl_80320CFC[];
extern "C" void MEMFreeToAllocator(int, void*);
extern "C" void fn_800D598C(void*);
extern "C" void fn_8002F634(void*, void*, int, int);
extern "C" void fn_800D2DD4(void);
extern "C" void __dt__Q36nw4hbm3lyt4PaneFv(void*, int);
extern "C" void fn_80128668(void*);
extern "C" void* __dt__Q36nw4hbm3lyt6WindowFv(void* arg0, int arg1) {
    int count, offset;
    int* entries;
    void* pane;
    void** vtable;
    if (arg0 != 0) {
        *(void**)arg0 = (void*)lbl_80320CFC;
        entries = *(int**)((char*)arg0 + 0xFC);
        if (entries != 0) {
            count = 0;
            offset = 0;
            while (count < *(unsigned char*)((char*)arg0 + 0x100)) {
                pane = *(void**)((char*)entries + offset + 4);
                vtable = *(void***)pane;
                ((void (*)(void*, int))vtable[2])(pane, -1);
                MEMFreeToAllocator(lbl_8055DDF0, pane);
                offset += 8;
                count++;
            }
            MEMFreeToAllocator(lbl_8055DDF0, entries);
        }
        pane = *(void**)((char*)arg0 + 0x28);
        if (pane != 0 && *((unsigned char*)pane + 0x54) == 0) {
            vtable = *(void***)pane;
            ((void (*)(void*, int))vtable[2])(pane, -1);
            MEMFreeToAllocator(lbl_8055DDF0, pane);
            *(void**)((char*)arg0 + 0x28) = 0;
        }
        fn_800D598C((char*)arg0 + 0xF4);
        if ((char*)arg0 + 0xE4 != 0)
            fn_8002F634((char*)arg0 + 0xE4, (void*)fn_800D2DD4, 4, 4);
        __dt__Q36nw4hbm3lyt4PaneFv(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma use_lmw_stmw off
void* nw4hbm::lyt::Window::FindMaterialByName(const char* name, bool searchChildren) {
    struct Pane {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual void* FindMaterialByName(const char*, bool);
    };
    int i;
    int offset;
    if (material != 0 && fn_800D58F0((char*)material + 4, name) != 0)
        return this->material;
    i = 0;
    offset = 0;
    while (i < materialCount) {
        void* candidate = *(void**)((char*)materials + offset + 4);
        if (fn_800D58F0((char*)candidate + 4, name) != 0)
            return *(void**)((char*)materials + i * 8 + 4);
        offset += 8;
        i++;
    }
    if (searchChildren) {
        Link* child = children.next;
        Link* sentinel = &children;
        while (child != sentinel) {
            if (child == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            void* value = ((Pane*)((char*)child - 4))->FindMaterialByName(name, true);
            if (value != 0)
                return value;
            child = child->next;
        }
    }
    return 0;
}

extern "C" void* FindAnimationLink__Q36nw4hbm3lyt6WindowFPQ36nw4hbm3lyt13AnimTransform(void* self, void* anim) {
    void* result = FindAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(self, anim);
    if (result != 0) return result;
    struct DummyPane {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual void* FindAnimationLink(void* anim);
    };
    int offset;
    int count;
    count = 0;
    offset = 0;
    while (count < *((unsigned char*)self + 0x100)) {
        DummyPane* pane = *(DummyPane**)(*(unsigned char**)((unsigned char*)self + 0xFC) + offset + 4);
        result = pane->FindAnimationLink(anim);
        if (result != 0) return result;
        offset += 8;
        count++;
    }
    return 0;
}

extern "C" void SetAnimationEnable__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformbb(void* self, void* anim, bool enable, bool recursive);
extern "C" void SetAnimationEnable__Q36nw4hbm3lyt6WindowFPQ36nw4hbm3lyt13AnimTransformbb(void* self, void* anim, bool enable, bool recursive) {
    struct DummyPane {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual void v6(); virtual void v7();
        virtual void SetAnimationEnable(void* anim, bool enable, bool recursive);
    };
    int offset;
    int count;
    count = 0;
    offset = 0;
    while (count < *((unsigned char*)self + 0x100)) {
        DummyPane* pane = *(DummyPane**)(*(unsigned char**)((unsigned char*)self + 0xFC) + offset + 4);
        pane->SetAnimationEnable(anim, enable, recursive);
        offset += 8;
        count++;
    }
    SetAnimationEnable__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformbb(self, anim, enable, recursive);
}

extern "C" void GetVtxColor__Q36nw4hbm3lyt7PictureCFUl_800E0238(unsigned char* out, const void* self, unsigned long idx) {
    if (idx >= 4) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320C14, 0x168, lbl_80320C60);
    const unsigned char* p = (const unsigned char*)((unsigned long)self + idx * 4 + 0xE4);
    out[0] = p[0]; out[1] = p[1]; out[2] = p[2]; out[3] = p[3];
}

extern "C" void SetVtxColor__Q36nw4hbm3lyt7PictureFUlQ36nw4hbm2ut5Color_800E02C4(void* self, unsigned long idx, const unsigned char* color) {
    if (idx >= 4) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320C14, 0x173, lbl_80320C60);
    unsigned char* p = (unsigned char*)((unsigned long)self + idx * 4 + 0xE4);
    p[0] = color[0]; p[1] = color[1]; p[2] = color[2]; p[3] = color[3];
}

extern "C" unsigned char GetVtxColorElement__Q36nw4hbm3lyt7PictureCFUl_800E0350(void* self, unsigned long idx) {
    if (idx >= 0x10) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803204F8, 0xC7, lbl_803204BC);
    unsigned long hi = idx & ~3UL;
    unsigned long lo = idx & 3;
    unsigned char* p = (unsigned char*)((unsigned long)self + hi);
    return p[lo + 0xE4];
}

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7PictureFUlUc_800E03BC(void* this_, unsigned long idx, unsigned char color) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    extern const char lbl_803204B0[];
    extern const char lbl_80320474[];
    if (idx >= 0x10) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803204B0, 0xD4, lbl_80320474);
    unsigned long hi = idx & ~3UL;
    unsigned long lo = idx & 3;
    unsigned char* p = (unsigned char*)((unsigned long)this_ + hi);
    p[lo + 0xE4] = color;
}

extern "C" void GetFrameSize__Q36nw4hbm3lyt6WindowFUcPCQ46nw4hbm3lyt6Window5Frame(f64* out, void* self, u8 a, u32 b);
extern "C" void GetVtxPos__Q34nw4r3lyt4PaneCFv(void* self);
extern "C" void fn_800E0434(void* self) {
    u8* bytes = (u8*)self;
    void** vtable = *(void***)self;

    void (*fn0)(void*) = (void (*)(void*))vtable[0x60 / 4];
    fn0(self);

    f64 sp18;
    f64 sp20;
    f64 sp28;
    f64 sp30;
    f64 sp10;
    u32 spC;
    u32 sp8;

    GetFrameSize__Q36nw4hbm3lyt6WindowFUcPCQ46nw4hbm3lyt6Window5Frame(&sp18, self, bytes[0x100], *(u32*)(bytes + 0xFC));
    sp28 = sp18;
    sp30 = sp20;

    GetVtxPos__Q34nw4r3lyt4PaneCFv(self);
    spC = *(u32*)(bytes + 0xC);
    sp8 = *(u32*)(bytes + 0x8);
    sp10 = *(f64*)(bytes + 0x10);

    void (*fn1)(void*, f64*, f64*, u8) = (void (*)(void*, f64*, f64*, u8))vtable[0x6C / 4];
    fn1(self, &sp10, &sp28, bytes[0xCE]);

    switch (bytes[0x100]) {
    case 1: {
        void (*fn2)(void*, f64*, u32, f64*, u8) = (void (*)(void*, f64*, u32, f64*, u8))vtable[0x70 / 4];
        fn2(self, &sp10, *(u32*)(bytes + 0xFC), &sp28, bytes[0xCE]);
        break;
    }
    case 4: {
        void (*fn3)(void*, f64*, u32, f64*, u8) = (void (*)(void*, f64*, u32, f64*, u8))vtable[0x74 / 4];
        fn3(self, &sp10, *(u32*)(bytes + 0xFC), &sp28, bytes[0xCE]);
        break;
    }
    case 8: {
        void (*fn4)(void*, f64*, u32, f64*, u8) = (void (*)(void*, f64*, u32, f64*, u8))vtable[0x78 / 4];
        fn4(self, &sp10, *(u32*)(bytes + 0xFC), &sp28, bytes[0xCE]);
        break;
    }
    }
}

extern "C" void AnimateSelf__Q36nw4hbm3lyt6WindowFUl(void* self, unsigned long arg) {
    extern void AnimateSelf__Q36nw4hbm3lyt4PaneFUl(void*, unsigned long);
    AnimateSelf__Q36nw4hbm3lyt4PaneFUl(self, arg);
    if (!(*((unsigned char*)self + 0xCF) & 1) && !(arg & 1)) {
        int offset = 0;
        int count = 0;
        while (count < *((unsigned char*)self + 0x100)) {
            void* pane = *(void**)(*(unsigned char**)((unsigned char*)self + 0xFC) + offset + 4);
            void** vtable = *(void***)pane;
            void (*fn)(void*) = (void (*)(void*))vtable[7];
            fn(pane);
            offset += 8;
            count++;
        }
    }
}

extern "C" void UnbindAnimationSelf__Q36nw4hbm3lyt6WindowFPQ36nw4hbm3lyt13AnimTransform(void* self, void* anim) {
    int offset = 0, count = 0;
    while (count < *((unsigned char*)self + 0x100)) {
        struct Pane {
            virtual void v0(); virtual void v1(); virtual void v2();
            virtual void UnbindAnimationSelf(void* anim);
        };
        Pane* pane = *(Pane**)(*(unsigned char**)((unsigned char*)self + 0xFC) + offset + 4);
        pane->UnbindAnimationSelf(anim);
        offset += 8;
        count++;
    }
    UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(self, anim);
}

void nw4r::lyt::Window::DrawContent(const nw4r::math::VEC2 &arg1, const nw4r::lyt::WindowFrameSize &arg2, u8 arg3) {
    struct MaterialVTable {
        virtual void v0();
        virtual s32 draw(s32, u8);
    };
    u8 *self = (u8 *)this;
    const f32 *pos = (const f32 *)&arg1;
    const f32 *frame = (const f32 *)&arg2;
    s32 modulate;
    s32 useVtxColor;
    void *vtxColor;
    volatile f32 quad[4];
    register f32 temp_f0;
    register f32 temp_f1;
    register f32 temp_f2;
    register f32 temp_f3;
    register f32 temp_f4;
    register f32 temp_f5;
    register f32 temp_f6;
    s32 texture;
    u8 format;

    modulate = IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(self + 0xE4, arg3);
    useVtxColor = ((MaterialVTable *)*(void **)(self + 0x28))->draw(modulate, arg3);
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(useVtxColor, self[0xF5]);
    if (useVtxColor != 0)
        vtxColor = self + 0xE4;
    else
        vtxColor = 0;

    temp_f1 = *(f32 *)(self + 0x50);
    temp_f6 = frame[2];
    temp_f3 = temp_f1 - temp_f6;
    temp_f0 = *(f32 *)(self + 0x4C);
    temp_f4 = frame[0];
    temp_f1 = temp_f0 - temp_f4;
    temp_f2 = *(f32 *)(self + 0xDC);
    temp_f0 = *(f32 *)(self + 0xD4);
    temp_f5 = temp_f2 + temp_f3;
    temp_f3 = frame[3];
    texture = *(s32 *)(self + 0xF8);
    temp_f2 = temp_f0 + temp_f1;
    temp_f1 = frame[1];
    temp_f5 = temp_f5 - temp_f3;
    temp_f3 = *(f32 *)(self + 0xE0);
    temp_f1 = temp_f2 - temp_f1;
    temp_f0 = *(f32 *)(self + 0xD8);
    temp_f3 = temp_f3 + temp_f5;
    format = self[0xF5];
    temp_f2 = temp_f0 + temp_f1;
    temp_f1 = pos[1];
    quad[1] = temp_f3;
    temp_f3 = temp_f1 + temp_f6;
    temp_f0 = pos[0];
    quad[0] = temp_f2;
    temp_f1 = temp_f0 + temp_f4;
    temp_f2 = *(f32 *)(self + 0xDC);
    temp_f0 = *(f32 *)(self + 0xD4);
    temp_f2 = temp_f3 - temp_f2;
    temp_f0 = temp_f1 - temp_f0;
    quad[3] = temp_f2;
    quad[2] = temp_f0;

    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(
        (f32 *)&quad[2], (f32 *)&quad[0], format,
        (f32 (*)[])texture, (s32)vtxColor, arg3);
}

extern "C" s32 IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(void *, u8);
extern "C" void GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc(f32 *, void *, u8);
extern "C" void SetVertexFormat__Q34nw4r3lyt6detailFbUc(s32, u8);
extern "C" void DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(f32 *, f32 *, u8, f32 (*)[], s32, u8);
extern "C" const char lbl_80320BD8[];
extern "C" f32 lbl_80560EE8;
#pragma push
#pragma scheduling on
extern "C" void DrawFrame8__Q36nw4hbm3lyt6WindowFRCQ36nw4hbm4math4VEC2PCQ46nw4hbm3lyt6Window5FrameRCQ36nw4hbm3lyt15WindowFrameSizeUc(
    void *arg0,
    f32 *arg1,
    void *arg2,
    void *arg3,
    u8 arg4
) {
    struct MaterialVTable {
        virtual void fn0();
        virtual s32 fn1(s32, u8);
    };
    const u8 *frameTable;
    s32 sp13C;
    s32 sp138;
    s32 sp108[4];
    volatile f32 sp104;
    volatile f32 sp100;
    volatile f32 spFC;
    volatile f32 spF8;
    volatile f32 spF4;
    volatile f32 spF0;
    volatile f32 spE4;
    volatile f32 spEC;
    volatile f32 spE8;
    volatile f32 spE0;
    volatile f32 spCC, spB4, sp9C, sp84, sp6C, sp54;
    volatile f32 spDC;
    volatile f32 spD8;
    volatile f32 spD4;
    volatile f32 spD0;
    volatile f32 spC8;
    volatile f32 spC4;
    volatile f32 spC0;
    volatile f32 spBC;
    volatile f32 spB8;
    volatile f32 spB0;
    volatile f32 spAC;
    volatile f32 spA8;
    volatile f32 spA4;
    volatile f32 spA0;
    volatile f32 sp98;
    volatile f32 sp94;
    volatile f32 sp90;
    volatile f32 sp8C;
    volatile f32 sp88;
    volatile f32 sp80;
    volatile f32 sp7C;
    volatile f32 sp78;
    volatile f32 sp74;
    volatile f32 sp70;
    volatile f32 sp68;
    volatile f32 sp64;
    volatile f32 sp60;
    volatile f32 sp5C;
    volatile f32 sp58;
    volatile f32 sp50;
    volatile f32 sp4C;
    volatile f32 sp48;
    volatile f32 sp44;
    volatile f32 sp40;
    volatile f32 sp3C;
    volatile f32 sp38;
    volatile f32 sp34;
    volatile f32 sp30;
    volatile f32 sp2C;
    volatile f32 sp28;
    volatile f32 sp24;
    volatile f32 sp20;
    volatile f32 sp1C;
    volatile f32 sp18;
    volatile f32 sp14;
    volatile f32 sp10;
    volatile f32 spC;
    volatile f32 sp8;
    f32 spBuffer[8];
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_15;
    f32 temp_f0_16;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_12;
    f32 temp_f1_13;
    f32 temp_f1_14;
    f32 temp_f1_15;
    f32 temp_f1_16;
    f32 temp_f1_17;
    f32 temp_f1_18;
    f32 temp_f1_19;
    f32 temp_f1_20;
    f32 temp_f1_21;
    f32 temp_f1_22;
    f32 temp_f1_23;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f2;
    f32 temp_f2_10;
    f32 temp_f2_11;
    f32 temp_f2_12;
    f32 temp_f2_13;
    f32 temp_f2_14;
    f32 temp_f2_15;
    f32 temp_f2_16;
    f32 temp_f2_17;
    f32 temp_f2_18;
    f32 temp_f2_19;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f2_8;
    f32 temp_f2_9;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f4_5;
    f32 temp_f4_6;
    f32 temp_f4_7;
    f32 temp_f4_8;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f6_4;
    f32 temp_f6_5;
    f32 temp_f6_6;
    f32 temp_f6_7;
    f32 temp_f6_8;
    f32 temp_f7;
    f32 temp_f7_2;
    f32 temp_f7_3;
    f32 temp_f7_4;
    f32 temp_f7_5;
    f32 temp_f7_6;
    f32 temp_f7_7;
    f32 temp_f7_8;
    s32 temp_r3;
    s32 temp_r23;
    s32 temp_r23_2;
    s32 temp_r23_3;
    s32 temp_r23_4;
    s32 temp_r23_5;
    s32 temp_r23_6;
    s32 temp_r23_7;
    s32 temp_r23_8;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 temp_r0_4;
    u8 temp_r0_5;
    u8 temp_r0_6;
    u8 temp_r10;
    u8 temp_r10_2;
    u8 temp_r10_4;
    u8 temp_r10_6;
    u8 temp_r11;
    u8 temp_r11_2;
    u8 temp_r11_3;
    u8 temp_r11_4;
    u8 temp_r24;
    register s32 temp_r26;
    register s32 temp_r26_2;
    register s32 temp_r26_3;
    register s32 temp_r26_4;
    register s32 temp_r26_5;
    register s32 temp_r26_6;
    register s32 temp_r26_7;
    u8 temp_r3_3;
    u8 temp_r3_5;
    u8 temp_r4_3;
    u8 temp_r4_4;
    u8 temp_r4_5;
    u8 temp_r4_6;
    u8 temp_r4_7;
    u8 temp_r4_8;
    u8 temp_r5_3;
    u8 temp_r5_4;
    u8 temp_r7;
    u8 temp_r7_2;
    u8 temp_r7_3;
    u8 temp_r7_4;
    u8 temp_r8;
    u8 temp_r8_2;
    u8 temp_r8_7;
    u8 temp_r8_8;
    void *temp_r3_11;
    void *temp_r3_14;
    void *temp_r3_16;
    void *temp_r3_2;
    void *temp_r3_4;
    void *temp_r3_6;
    void *temp_r3_7;
    void *temp_r3_8;
    const u8 *temp_r10_3;
    const u8 *temp_r10_5;
    const u8 *temp_r3_10;
    const u8 *temp_r3_12;
    const u8 *temp_r3_13;
    const u8 *temp_r3_15;
    const u8 *temp_r3_17;
    const u8 *temp_r3_9;
    const u8 *temp_r4;
    const u8 *temp_r4_2;
    const u8 *temp_r5;
    const u8 *temp_r5_2;
    const u8 *temp_r8_3;
    const u8 *temp_r8_4;
    const u8 *temp_r8_5;
    const u8 *temp_r8_6;

    sp138 = 0x43300000;
    sp108[0] = -1;
    sp108[1] = -1;
    sp108[2] = -1;
    sp108[3] = -1;
    sp100 = lbl_80560EE8;
    sp104 = lbl_80560EE8;
    frameTable = (const u8 *)lbl_80320BD8;
    temp_r3 = IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(0, arg4);
    temp_r3_2 = M2C_FIELD(arg2, void *, 4);
    temp_r23 = ((MaterialVTable *)temp_r3_2)->fn1(temp_r3, arg4);
    temp_f1 = M2C_FIELD(arg3, f32, 8);
    temp_f0 = M2C_FIELD(arg3, f32, 0);
    spFC = temp_f1;
    temp_r26 = M2C_FIELD(arg2, u8, 0);
    spF8 = temp_f0;
    sp100 = temp_f0;
    sp104 = temp_f1;
    GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc((f32 *)&spF0, M2C_FIELD(arg2, void *, 4), 0);
    if (temp_r26 >= 6U) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(frameTable + 0x3C), 0x32, (const char *)(frameTable + 0xB8));
    }
    temp_r4 = frameTable + (temp_r26 * 0xA);
    sp40 = spF0;
    temp_r0 = *(const volatile u8 *)(temp_r4 + 9);
    temp_r3_3 = *(const volatile u8 *)(temp_r4 + 8);
    temp_r8 = *(temp_r4 + temp_r0);
    temp_r10 = *(temp_r4 + temp_r3_3);
    temp_f6 = (f32) temp_r8;
    sp44 = spF4;
    temp_f4 = sp100 / ((f32) (M2C_FIELD((temp_r4 + temp_r3_3), u8, 2) - temp_r10) * (&sp40)[temp_r3_3]);
    sp13C = (s32) temp_r10;
    sp13C = (s32) temp_r8;
    temp_f7 = (f32) temp_r10;
    ((spBuffer + 4))[temp_r3_3] = temp_f7;
    ((spBuffer + 0))[temp_r3_3] = temp_f7;
    ((spBuffer + 2))[temp_r0] = temp_f6;
    ((spBuffer + 0))[temp_r0] = temp_f6;
    temp_f2 = (f32) temp_r10 + temp_f4;
    temp_f1_2 = (f32) temp_r8;
    ((spBuffer + 2))[temp_r3_3] = temp_f2;
    temp_f0_2 = temp_f1_2 + (sp104 / ((f32) (M2C_FIELD((temp_r4 + temp_r0), u8, 4) - temp_r8) * (&sp40)[temp_r0]));
    ((spBuffer + 6))[temp_r3_3] = temp_f2;
    ((spBuffer + 4))[temp_r0] = temp_f0_2;
    ((spBuffer + 6))[temp_r0] = temp_f0_2;
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(temp_r23, 1);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(arg1, (f32 *)&sp100, 1, (f32 (*)[]) (spBuffer + 0), (s32) sp108 & ((s32) (-temp_r23 | temp_r23) >> 0x1F), arg4);
    temp_r3_4 = M2C_FIELD(arg2, void *, 0x34);
    temp_r23_2 = ((MaterialVTable *)temp_r3_4)->fn1(temp_r3, arg4);
    temp_f2_2 = M2C_FIELD(arg3, f32, 8);
    temp_f1_3 = M2C_FIELD(arg0, f32, 0x4C) - M2C_FIELD(arg3, f32, 0);
    spEC = temp_f2_2;
    temp_r26_2 = M2C_FIELD(arg2, u8, 0x30);
    temp_f0_3 = temp_f1_3 - M2C_FIELD(arg3, f32, 4);
    sp104 = temp_f2_2;
    spE8 = temp_f0_3;
    sp100 = temp_f0_3;
    GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc((f32 *)&spE0, M2C_FIELD(arg2, void *, 0x34), 0);
    if (temp_r26_2 >= 6U) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(frameTable + 0x3C), 0x32, (const char *)(frameTable + 0xB8));
    }
    temp_r4_2 = frameTable + (temp_r26_2 * 0xA);
    sp38 = spE0;
    temp_r0_2 = *(const volatile u8 *)(temp_r4_2 + 9);
    temp_r3_5 = *(const volatile u8 *)(temp_r4_2 + 8);
    temp_r8_2 = *(temp_r4_2 + temp_r0_2);
    temp_r10_2 = *(temp_r4_2 + temp_r3_5);
    temp_f6_2 = (f32) temp_r8_2;
    sp3C = spE4;
    temp_f4_2 = sp100 / ((f32) (M2C_FIELD((temp_r4_2 + temp_r3_5), u8, 2) - temp_r10_2) * (&sp38)[temp_r3_5]);
    sp13C = (s32) temp_r10_2;
    sp13C = (s32) temp_r8_2;
    temp_f7_2 = (f32) temp_r10_2;
    ((spBuffer + 4))[temp_r3_5] = temp_f7_2;
    ((spBuffer + 0))[temp_r3_5] = temp_f7_2;
    ((spBuffer + 2))[temp_r0_2] = temp_f6_2;
    ((spBuffer + 0))[temp_r0_2] = temp_f6_2;
    temp_f2_3 = (f32) temp_r10_2 + temp_f4_2;
    temp_f1_4 = (f32) temp_r8_2;
    ((spBuffer + 2))[temp_r3_5] = temp_f2_3;
    temp_f0_4 = temp_f1_4 + (sp104 / ((f32) (M2C_FIELD((temp_r4_2 + temp_r0_2), u8, 4) - temp_r8_2) * (&sp38)[temp_r0_2]));
    ((spBuffer + 6))[temp_r3_5] = temp_f2_3;
    ((spBuffer + 4))[temp_r0_2] = temp_f0_4;
    ((spBuffer + 6))[temp_r0_2] = temp_f0_4;
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(temp_r23_2, 1);
    temp_f1_5 = M2C_FIELD(arg1, f32, 0);
    temp_f2_4 = M2C_FIELD(arg1, f32, 4);
    spDC = temp_f2_4;
    spD8 = temp_f1_5 + M2C_FIELD(arg3, f32, 0);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc((f32 *)&spD8, (f32 *)&sp100, 1, (f32 (*)[]) (spBuffer + 0), (s32) &sp108 & ((s32) (-temp_r23_2 | temp_r23_2) >> 0x1F), arg4);
    temp_r3_6 = M2C_FIELD(arg2, void *, 0xC);
    temp_f1_6 = M2C_FIELD(arg3, f32, 8);
    temp_r23_3 = ((MaterialVTable *)temp_r3_6)->fn1(temp_r3, arg4);
    temp_f0_5 = M2C_FIELD(arg3, f32, 4);
    spD4 = temp_f1_6;
    temp_r26_3 = M2C_FIELD(arg2, u8, 8);
    spD0 = temp_f0_5;
    sp100 = temp_f0_5;
    sp104 = temp_f1_6;
    GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc((f32 *)&spC8, M2C_FIELD(arg2, void *, 0xC), 0);
    if (temp_r26_3 >= 6U) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(frameTable + 0x3C), 0x32, (const char *)(frameTable + 0xB8));
    }
    temp_r5 = frameTable + (temp_r26_3 * 0xA);
    sp30 = spC8;
    temp_r0_3 = *(const volatile u8 *)(temp_r5 + 9);
    temp_r4_3 = *(const volatile u8 *)(temp_r5 + 8);
    temp_r8_3 = temp_r5 + temp_r0_3;
    temp_r7 = M2C_FIELD(temp_r8_3, u8, 2);
    temp_r11 = M2C_FIELD((temp_r5 + temp_r4_3), u8, 2);
    temp_f6_3 = (f32) temp_r7;
    sp34 = spCC;
    temp_f4_3 = sp100 / ((f32) (*(temp_r5 + temp_r4_3) - temp_r11) * (&sp30)[temp_r4_3]);
    sp13C = (s32) temp_r11;
    sp13C = (s32) temp_r7;
    temp_f7_3 = (f32) temp_r11;
    ((spBuffer + 6))[temp_r4_3] = temp_f7_3;
    ((spBuffer + 2))[temp_r4_3] = temp_f7_3;
    ((spBuffer + 0))[temp_r0_3] = temp_f6_3;
    ((spBuffer + 2))[temp_r0_3] = temp_f6_3;
    temp_f2_5 = (f32) temp_r11 + temp_f4_3;
    temp_f1_7 = (f32) temp_r7;
    ((spBuffer + 0))[temp_r4_3] = temp_f2_5;
    temp_f0_6 = temp_f1_7 + (sp104 / ((f32) (M2C_FIELD(temp_r8_3, u8, 6) - temp_r7) * (&sp30)[temp_r0_3]));
    ((spBuffer + 4))[temp_r4_3] = temp_f2_5;
    ((spBuffer + 6))[temp_r0_3] = temp_f0_6;
    ((spBuffer + 4))[temp_r0_3] = temp_f0_6;
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(temp_r23_3, 1);
    temp_f2_6 = M2C_FIELD(arg1, f32, 4);
    temp_f1_8 = M2C_FIELD(arg1, f32, 0) + M2C_FIELD(arg0, f32, 0x4C);
    spC4 = temp_f2_6;
    spC0 = temp_f1_8 - M2C_FIELD(arg3, f32, 4);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc((f32 *)&spC0, (f32 *)&sp100, 1, (f32 (*)[]) (spBuffer + 0), (s32) &sp108 & ((s32) (-temp_r23_3 | temp_r23_3) >> 0x1F), arg4);
    temp_r3_7 = M2C_FIELD(arg2, void *, 0x2C);
    temp_r23_4 = ((MaterialVTable *)temp_r3_7)->fn1(temp_r3, arg4);
    temp_f2_7 = M2C_FIELD(arg3, f32, 4);
    temp_f1_9 = M2C_FIELD(arg0, f32, 0x50) - M2C_FIELD(arg3, f32, 8);
    spB8 = temp_f2_7;
    temp_r26_4 = M2C_FIELD(arg2, u8, 0x28);
    temp_f0_7 = temp_f1_9 - M2C_FIELD(arg3, f32, 0xC);
    sp100 = temp_f2_7;
    spBC = temp_f0_7;
    sp104 = temp_f0_7;
    GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc((f32 *)&spB0, M2C_FIELD(arg2, void *, 0x2C), 0);
    if (temp_r26_4 >= 6U) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(frameTable + 0x3C), 0x32, (const char *)(frameTable + 0xB8));
    }
    temp_r5_2 = frameTable + (temp_r26_4 * 0xA);
    sp28 = spB0;
    temp_r0_4 = *(const volatile u8 *)(temp_r5_2 + 9);
    temp_r4_4 = *(const volatile u8 *)(temp_r5_2 + 8);
    temp_r8_4 = temp_r5_2 + temp_r0_4;
    temp_r7_2 = M2C_FIELD(temp_r8_4, u8, 2);
    temp_r11_2 = M2C_FIELD((temp_r5_2 + temp_r4_4), u8, 2);
    temp_f6_4 = (f32) temp_r7_2;
    sp2C = spB4;
    temp_f4_4 = sp100 / ((f32) (*(temp_r5_2 + temp_r4_4) - temp_r11_2) * (&sp28)[temp_r4_4]);
    sp13C = (s32) temp_r11_2;
    sp13C = (s32) temp_r7_2;
    temp_f7_4 = (f32) temp_r11_2;
    ((spBuffer + 6))[temp_r4_4] = temp_f7_4;
    ((spBuffer + 2))[temp_r4_4] = temp_f7_4;
    ((spBuffer + 0))[temp_r0_4] = temp_f6_4;
    ((spBuffer + 2))[temp_r0_4] = temp_f6_4;
    temp_f2_8 = (f32) temp_r11_2 + temp_f4_4;
    temp_f1_10 = (f32) temp_r7_2;
    ((spBuffer + 0))[temp_r4_4] = temp_f2_8;
    temp_f0_8 = temp_f1_10 + (sp104 / ((f32) (M2C_FIELD(temp_r8_4, u8, 6) - temp_r7_2) * (&sp28)[temp_r0_4]));
    ((spBuffer + 4))[temp_r4_4] = temp_f2_8;
    ((spBuffer + 6))[temp_r0_4] = temp_f0_8;
    ((spBuffer + 4))[temp_r0_4] = temp_f0_8;
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(temp_r23_4, 1);
    temp_f3 = M2C_FIELD(arg1, f32, 4);
    temp_f1_11 = M2C_FIELD(arg1, f32, 0) + M2C_FIELD(arg0, f32, 0x4C);
    temp_f2_9 = temp_f3 + M2C_FIELD(arg3, f32, 8);
    spAC = temp_f2_9;
    spA8 = temp_f1_11 - M2C_FIELD(arg3, f32, 4);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc((f32 *)&spA8, (f32 *)&sp100, 1, (f32 (*)[]) (spBuffer + 0), (s32) &sp108 & ((s32) (-temp_r23_4 | temp_r23_4) >> 0x1F), arg4);
    temp_r3_8 = M2C_FIELD(arg2, void *, 0x1C);
    temp_f1_12 = M2C_FIELD(arg3, f32, 0xC);
    temp_r23_5 = ((MaterialVTable *)temp_r3_8)->fn1(temp_r3, arg4);
    temp_f0_9 = M2C_FIELD(arg3, f32, 4);
    spA4 = temp_f1_12;
    temp_r26_5 = M2C_FIELD(arg2, u8, 0x18);
    spA0 = temp_f0_9;
    sp100 = temp_f0_9;
    sp104 = temp_f1_12;
    GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc((f32 *)&sp98, M2C_FIELD(arg2, void *, 0x1C), 0);
    if (temp_r26_5 >= 6U) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(frameTable + 0x3C), 0x32, (const char *)(frameTable + 0xB8));
    }
    temp_r3_9 = frameTable + (temp_r26_5 * 0xA);
    sp20 = sp98;
    temp_r0_5 = *(const volatile u8 *)(temp_r3_9 + 9);
    temp_r4_5 = *(const volatile u8 *)(temp_r3_9 + 8);
    temp_r8_5 = temp_r3_9 + temp_r0_5;
    temp_r3_10 = temp_r3_9 + temp_r4_5;
    temp_r7_3 = M2C_FIELD(temp_r8_5, u8, 6);
    temp_r11_3 = M2C_FIELD(temp_r3_10, u8, 6);
    temp_f6_5 = (f32) temp_r7_3;
    sp24 = sp9C;
    temp_f4_5 = sp100 / ((f32) (M2C_FIELD(temp_r3_10, u8, 4) - temp_r11_3) * (&sp20)[temp_r4_5]);
    sp13C = (s32) temp_r11_3;
    sp13C = (s32) temp_r7_3;
    temp_f7_5 = (f32) temp_r11_3;
    ((spBuffer + 2))[temp_r4_5] = temp_f7_5;
    ((spBuffer + 6))[temp_r4_5] = temp_f7_5;
    ((spBuffer + 4))[temp_r0_5] = temp_f6_5;
    ((spBuffer + 6))[temp_r0_5] = temp_f6_5;
    temp_f2_10 = (f32) temp_r11_3 + temp_f4_5;
    temp_f1_13 = (f32) temp_r7_3;
    ((spBuffer + 4))[temp_r4_5] = temp_f2_10;
    temp_f0_10 = temp_f1_13 + (sp104 / ((f32) (M2C_FIELD(temp_r8_5, u8, 2) - temp_r7_3) * (&sp20)[temp_r0_5]));
    ((spBuffer + 0))[temp_r4_5] = temp_f2_10;
    ((spBuffer + 2))[temp_r0_5] = temp_f0_10;
    ((spBuffer + 0))[temp_r0_5] = temp_f0_10;
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(temp_r23_5, 1);
    temp_f3_2 = M2C_FIELD(arg1, f32, 4) + M2C_FIELD(arg0, f32, 0x50);
    temp_f1_14 = M2C_FIELD(arg1, f32, 0) + M2C_FIELD(arg0, f32, 0x4C);
    temp_f2_11 = temp_f3_2 - M2C_FIELD(arg3, f32, 0xC);
    sp94 = temp_f2_11;
    sp90 = temp_f1_14 - M2C_FIELD(arg3, f32, 4);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc((f32 *)&sp90, (f32 *)&sp100, 1, (f32 (*)[]) (spBuffer + 0), (s32) &sp108 & ((s32) (-temp_r23_5 | temp_r23_5) >> 0x1F), arg4);
    temp_r3_11 = M2C_FIELD(arg2, void *, 0x3C);
    temp_r23_6 = ((MaterialVTable *)temp_r3_11)->fn1(temp_r3, arg4);
    temp_f2_12 = M2C_FIELD(arg3, f32, 0xC);
    temp_f1_15 = M2C_FIELD(arg0, f32, 0x4C) - M2C_FIELD(arg3, f32, 0);
    sp8C = temp_f2_12;
    temp_r26_6 = M2C_FIELD(arg2, u8, 0x38);
    temp_f0_11 = temp_f1_15 - M2C_FIELD(arg3, f32, 4);
    sp104 = temp_f2_12;
    sp88 = temp_f0_11;
    sp100 = temp_f0_11;
    GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc((f32 *)&sp80, M2C_FIELD(arg2, void *, 0x3C), 0);
    if (temp_r26_6 >= 6U) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(frameTable + 0x3C), 0x32, (const char *)(frameTable + 0xB8));
    }
    temp_r3_12 = frameTable + (temp_r26_6 * 0xA);
    sp18 = sp80;
    temp_r0_6 = *(const volatile u8 *)(temp_r3_12 + 9);
    temp_r4_6 = *(const volatile u8 *)(temp_r3_12 + 8);
    temp_r8_6 = temp_r3_12 + temp_r0_6;
    temp_r3_13 = temp_r3_12 + temp_r4_6;
    temp_r7_4 = M2C_FIELD(temp_r8_6, u8, 6);
    temp_r11_4 = M2C_FIELD(temp_r3_13, u8, 6);
    temp_f6_6 = (f32) temp_r7_4;
    sp1C = sp84;
    temp_f4_6 = sp100 / ((f32) (M2C_FIELD(temp_r3_13, u8, 4) - temp_r11_4) * (&sp18)[temp_r4_6]);
    sp13C = (s32) temp_r11_4;
    sp13C = (s32) temp_r7_4;
    temp_f7_6 = (f32) temp_r11_4;
    ((spBuffer + 2))[temp_r4_6] = temp_f7_6;
    ((spBuffer + 6))[temp_r4_6] = temp_f7_6;
    ((spBuffer + 4))[temp_r0_6] = temp_f6_6;
    ((spBuffer + 6))[temp_r0_6] = temp_f6_6;
    temp_f2_13 = (f32) temp_r11_4 + temp_f4_6;
    temp_f1_16 = (f32) temp_r7_4;
    ((spBuffer + 4))[temp_r4_6] = temp_f2_13;
    temp_f0_12 = temp_f1_16 + (sp104 / ((f32) (M2C_FIELD(temp_r8_6, u8, 2) - temp_r7_4) * (&sp18)[temp_r0_6]));
    ((spBuffer + 0))[temp_r4_6] = temp_f2_13;
    ((spBuffer + 2))[temp_r0_6] = temp_f0_12;
    ((spBuffer + 0))[temp_r0_6] = temp_f0_12;
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(temp_r23_6, 1);
    temp_f3_3 = M2C_FIELD(arg1, f32, 4) + M2C_FIELD(arg0, f32, 0x50);
    temp_f1_17 = M2C_FIELD(arg1, f32, 0);
    temp_f2_14 = temp_f3_3 - M2C_FIELD(arg3, f32, 0xC);
    sp78 = temp_f1_17 + M2C_FIELD(arg3, f32, 0);
    sp7C = temp_f2_14;
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc((f32 *)&sp78, (f32 *)&sp100, 1, (f32 (*)[]) (spBuffer + 0), (s32) &sp108 & ((s32) (-temp_r23_6 | temp_r23_6) >> 0x1F), arg4);
    temp_r3_14 = M2C_FIELD(arg2, void *, 0x14);
    temp_f1_18 = M2C_FIELD(arg3, f32, 0xC);
    temp_r23_7 = ((MaterialVTable *)temp_r3_14)->fn1(temp_r3, arg4);
    temp_f0_13 = M2C_FIELD(arg3, f32, 0);
    sp74 = temp_f1_18;
    temp_r26_7 = M2C_FIELD(arg2, u8, 0x10);
    sp70 = temp_f0_13;
    sp100 = temp_f0_13;
    sp104 = temp_f1_18;
    GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc((f32 *)&sp68, M2C_FIELD(arg2, void *, 0x14), 0);
    if (temp_r26_7 >= 6U) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(frameTable + 0x3C), 0x32, (const char *)(frameTable + 0xB8));
    }
    temp_r10_3 = frameTable + (temp_r26_7 * 0xA);
    sp14 = sp6C;
    temp_r4_7 = *(const volatile u8 *)(temp_r10_3 + 9);
    temp_r5_3 = *(const volatile u8 *)(temp_r10_3 + 8);
    temp_r8_7 = M2C_FIELD((temp_r10_3 + temp_r4_7), u8, 4);
    temp_r3_15 = temp_r10_3 + temp_r5_3;
    temp_r10_4 = M2C_FIELD(temp_r3_15, u8, 4);
    temp_f6_7 = (f32) temp_r8_7;
    sp10 = sp68;
    temp_f7_7 = (f32) temp_r10_4;
    ((spBuffer + 0))[temp_r5_3] = temp_f7_7;
    temp_f3_4 = sp100 / ((f32) (M2C_FIELD(temp_r3_15, u8, 6) - temp_r10_4) * (&sp10)[temp_r5_3]);
    ((spBuffer + 4))[temp_r5_3] = temp_f7_7;
    ((spBuffer + 6))[temp_r4_7] = temp_f6_7;
    temp_f4_7 = (f32) temp_r10_4;
    ((spBuffer + 4))[temp_r4_7] = temp_f6_7;
    temp_f2_15 = (f32) temp_r8_7;
    temp_f1_19 = temp_f4_7 + temp_f3_4;
    temp_f0_14 = temp_f2_15 + (sp104 / ((f32) (*(temp_r10_3 + temp_r4_7) - temp_r8_7) * (&sp10)[temp_r4_7]));
    ((spBuffer + 6))[temp_r5_3] = temp_f1_19;
    ((spBuffer + 2))[temp_r5_3] = temp_f1_19;
    ((spBuffer + 0))[temp_r4_7] = temp_f0_14;
    ((spBuffer + 2))[temp_r4_7] = temp_f0_14;
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(temp_r23_7, 1);
    temp_f2_16 = M2C_FIELD(arg1, f32, 0);
    temp_f1_20 = M2C_FIELD(arg1, f32, 4) + M2C_FIELD(arg0, f32, 0x50);
    sp60 = temp_f2_16;
    sp64 = temp_f1_20 - M2C_FIELD(arg3, f32, 0xC);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc((f32 *)&sp60, (f32 *)&sp100, 1, (f32 (*)[]) (spBuffer + 0), (s32) &sp108 & ((s32) (-temp_r23_7 | temp_r23_7) >> 0x1F), arg4);
    temp_r3_16 = M2C_FIELD(arg2, void *, 0x24);
    temp_r23_8 = ((MaterialVTable *)temp_r3_16)->fn1(temp_r3, arg4);
    temp_f2_17 = M2C_FIELD(arg3, f32, 0);
    temp_f1_21 = M2C_FIELD(arg0, f32, 0x50) - M2C_FIELD(arg3, f32, 8);
    sp58 = temp_f2_17;
    temp_r24 = M2C_FIELD(arg2, u8, 0x20);
    temp_f0_15 = temp_f1_21 - M2C_FIELD(arg3, f32, 0xC);
    sp100 = temp_f2_17;
    sp5C = temp_f0_15;
    sp104 = temp_f0_15;
    GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc((f32 *)&sp50, M2C_FIELD(arg2, void *, 0x24), 0);
    if (temp_r24 >= 6U) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(frameTable + 0x3C), 0x32, (const char *)(frameTable + 0xB8));
    }
    temp_r10_5 = frameTable + (temp_r24 * 0xA);
    spC = sp54;
    temp_r4_8 = *(const volatile u8 *)(temp_r10_5 + 9);
    temp_r5_4 = *(const volatile u8 *)(temp_r10_5 + 8);
    temp_r8_8 = M2C_FIELD((temp_r10_5 + temp_r4_8), u8, 4);
    temp_r3_17 = temp_r10_5 + temp_r5_4;
    temp_r10_6 = M2C_FIELD(temp_r3_17, u8, 4);
    temp_f6_8 = (f32) temp_r8_8;
    sp8 = sp50;
    temp_f7_8 = (f32) temp_r10_6;
    ((spBuffer + 0))[temp_r5_4] = temp_f7_8;
    temp_f3_5 = sp100 / ((f32) (M2C_FIELD(temp_r3_17, u8, 6) - temp_r10_6) * (&sp8)[temp_r5_4]);
    ((spBuffer + 4))[temp_r5_4] = temp_f7_8;
    ((spBuffer + 6))[temp_r4_8] = temp_f6_8;
    temp_f4_8 = (f32) temp_r10_6;
    ((spBuffer + 4))[temp_r4_8] = temp_f6_8;
    temp_f2_18 = (f32) temp_r8_8;
    temp_f1_22 = temp_f4_8 + temp_f3_5;
    temp_f0_16 = temp_f2_18 + (sp104 / ((f32) (*(temp_r10_5 + temp_r4_8) - temp_r8_8) * (&sp8)[temp_r4_8]));
    ((spBuffer + 6))[temp_r5_4] = temp_f1_22;
    ((spBuffer + 2))[temp_r5_4] = temp_f1_22;
    ((spBuffer + 0))[temp_r4_8] = temp_f0_16;
    ((spBuffer + 2))[temp_r4_8] = temp_f0_16;
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(temp_r23_8, 1);
    temp_f1_23 = M2C_FIELD(arg1, f32, 4);
    temp_f2_19 = M2C_FIELD(arg1, f32, 0);
    sp48 = temp_f2_19;
    sp4C = temp_f1_23 + M2C_FIELD(arg3, f32, 8);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc((f32 *)&sp48, (f32 *)&sp100, 1, (f32 (*)[]) (spBuffer + 0), (s32) &sp108 & ((s32) (-temp_r23_8 | temp_r23_8) >> 0x1F), arg4);
}

extern "C" void GetFrameSize__Q36nw4hbm3lyt6WindowFUcPCQ46nw4hbm3lyt6Window5Frame(f64* out, void* self, u8 a, u32 b) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp1C;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp20 = 0.0f;
    sp24 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    switch (a) {
    case 1:
        GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc(&sp18, (void*)(*(u32*)((u8*)b + 4)), 0);
        sp20 = sp18;
        sp28 = sp1C;
        sp24 = sp18;
        sp2C = sp1C;
        break;
    case 4:
    case 8:
        GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc(&sp10, (void*)(*(u32*)((u8*)b + 4)), 0);
        sp20 = sp10;
        sp28 = sp14;
        GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc(&sp8, (void*)(*(u32*)((u8*)b + 0x1C)), 0);
        sp10 = sp8;
        sp14 = spC;
        sp24 = sp8;
        sp2C = spC;
        break;
    }
    *(f32*)out = sp20;
    *(f32*)(out + 1) = sp24;
    *(f32*)(out + 2) = sp28;
    *(f32*)(out + 3) = sp2C;
}

#pragma pop
extern "C" int GetFrameMaterial__Q36nw4hbm3lyt6WindowCFUl(void* self, unsigned int index) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    extern const char lbl_80320C14[];
    extern const char lbl_80320CC8[];
    if (index >= 8) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320C14, 0x292, lbl_80320CC8);
    if (index >= *((unsigned char*)self + 0x100)) return 0;
    return *(int*)(*(unsigned char**)((unsigned char*)self + 0xFC) + index * 8 + 4);
}

extern "C" void fn_800E2508(void* self) {
    struct VTable23 {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual void d20(); virtual void dispatch();
    };
    ((VTable23*)self)->dispatch();
}

extern "C" unsigned int* fn_800E2518(void) { extern unsigned int lbl_8055DE10; return &lbl_8055DE10; }
struct DrawContentMaterial { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(void*, int, u8); };
