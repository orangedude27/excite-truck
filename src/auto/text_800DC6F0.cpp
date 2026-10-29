// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char* file, s32 line,
                                             const char* fmt, ...);

#pragma push
#pragma small_data off
extern u8 lbl_803204F8[];
extern u8 lbl_803204BC[];
extern u8 lbl_803204B0[];
extern u8 lbl_80320474[];
extern u8 lbl_80320320[];
extern u8 lbl_803203D8[];
#pragma pop

extern u32 lbl_8055DE00;

struct VEC2 { u32 x; u32 y; };

struct Color {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
};

extern "C" void InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(void*, void*, u32);
#pragma push
#pragma small_data off
extern u8 lbl_80320408[];
extern u8 fn_800D2DD4[];
extern u32 lbl_8055DDF0;
#pragma pop
extern "C" void MEMFreeToAllocator(void*, void*);
extern "C" void fn_800D598C(void*);
extern "C" void fn_8002F634(void*, void*, s32, s32);
extern "C" void __dt__Q36nw4hbm3lyt4PaneFv(void*, s32);
extern "C" void fn_80128668(void*);
#pragma push
#pragma small_data off
#pragma pop
extern "C" void* __ct__Q36nw4hbm3lyt7PictureFPCQ46nw4hbm3lyt3res7PictureRCQ36nw4hbm3lyt11ResBlockSet(void* this_, const void* res, const void* blockSet) {
    extern void* __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(void*, const void*);
    extern void* fn_8002F53C(void*, void*, void*, s32, s32);
    extern void fn_800D5978(void*);
    extern void Reserve__Q46nw4hbm3lyt6detail11TexCoordAryFUc(void*, u8);
    extern void Copy__Q46nw4hbm3lyt6detail11TexCoordAryFPCvUc(void*, const void*, u8);
    extern void* MEMAllocFromAllocator(void*, u32);
    extern void* __ct__Q36nw4hbm3lyt8MaterialFPCQ46nw4hbm3lyt3res8MaterialRCQ36nw4hbm3lyt11ResBlockSet(void*, const void*, const void*);
    extern u8 fn_800D7F6C[];
    extern u8 fn_800D2DD4[];
    extern u8 lbl_80320408[];
    extern u8 lbl_80320320[];
    extern u8 lbl_80320330[];
    extern u32 lbl_8055DDF0;
    u8* self = (u8*)this_;
    const u8* picture = (const u8*)res;
    u8 count;
    void* material;

    __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(this_, res);
    *(void**)self = lbl_80320408;
    fn_8002F53C(self + 0xD4, fn_800D7F6C, fn_800D2DD4, 4, 4);
    fn_800D5978(self + 0xE4);
    count = 8;
    if (picture[0x5E] <= 8) count = picture[0x5E];
    if (count != 0) Reserve__Q46nw4hbm3lyt6detail11TexCoordAryFUc(self + 0xE4, count);
    *(u32*)(self + 0xD4) = *(const u32*)(picture + 0x4C);
    *(u32*)(self + 0xD8) = *(const u32*)(picture + 0x50);
    *(u32*)(self + 0xDC) = *(const u32*)(picture + 0x54);
    *(u32*)(self + 0xE0) = *(const u32*)(picture + 0x58);
    if (count != 0 && self[0xE4] != 0) {
        Copy__Q46nw4hbm3lyt6detail11TexCoordAryFPCvUc(self + 0xE4, picture + 0x60, count);
    }
    material = MEMAllocFromAllocator((void*)lbl_8055DDF0, 0x5C);
    if (material != 0) {
        if (*(const u32*)((const u8*)blockSet + 8) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80320320, 0x95, (const char*)lbl_80320330);
        }
        u32 index = *(const volatile u16*)(picture + 0x5C);
        const u8* table = *(const u8**)((const u8*)blockSet + 8);
        const u8* entry = table + index * 4;
        const u8* materialRes = table + *(const u32*)(entry + 0xC);
        if (material != 0) {
            material = __ct__Q36nw4hbm3lyt8MaterialFPCQ46nw4hbm3lyt3res8MaterialRCQ36nw4hbm3lyt11ResBlockSet(material, materialRes, blockSet);
        }
        *(void**)(self + 0x28) = material;
    }
    return this_;
}

extern "C" void* __dt__Q36nw4hbm3lyt7PictureFv(void* this_, s32 arg1) {
    void* data;
    if (this_ != 0) {
        data = *(void**)((u8*)this_ + 0x28);
        *(void**)this_ = lbl_80320408;
        if (data != 0 && *((u8*)data + 0x54) == 0) {
            ((void (*)(void*, s32))(*(void (***)(void*, s32))data)[2])(data, -1);
            MEMFreeToAllocator((void*)lbl_8055DDF0, *(void**)((u8*)this_ + 0x28));
            *(u32*)((u8*)this_ + 0x28) = 0;
        }
        fn_800D598C((u8*)this_ + 0xE4);
        fn_8002F634((u8*)this_ + 0xD4, fn_800D2DD4, 4, 4);
        __dt__Q36nw4hbm3lyt4PaneFv(this_, 0);
        if (arg1 > 0) fn_80128668(this_);
    }
    return this_;
}
extern "C" void fn_800DC918(void* this_, void* palette) {
    struct Picture {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
        virtual void Set(void*);
    };
    u8 tex[0x20];
    InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(tex, palette, 0);
    ((Picture*)this_)->Set(tex);
}

extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char*, s32, const char*, ...);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, s32, const char*, ...);
extern "C" void SetTextureNum__Q36nw4hbm3lyt8MaterialFUc(void*, u8);
extern "C" void SetTexture__Q36nw4hbm3lyt8MaterialFUcRC9_GXTexObj(void*, u8, const void*);
extern "C" void SetTexCoordGenNum__Q36nw4hbm3lyt8MaterialFUc(void*, u8);
extern "C" void* fn_800D9344(void*);
extern "C" void SetSize__Q46nw4hbm3lyt6detail11TexCoordAryFUc(void*, u8);
extern "C" void GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc(f32*, void*, u8);
extern "C" u8 lbl_8032036C[], lbl_80320504[], lbl_80320538[];
extern f32 lbl_80560EC8;
extern "C" void Append__Q36nw4hbm3lyt7PictureFRC9_GXTexObj(void* this_, const void* texObj) {
    u8* self = (u8*)this_;
    u32 n;
    void* mat = *(void**)(self + 0x28);
    u32 count = *(volatile u32*)((u8*)mat + 0x4C);
    n = *(volatile u32*)((u8*)mat + 0x50) >> 28;
    u32 packed;
    u8 coords[4];
    volatile f32 defaults[2];
    f32 size[2];

    if (n >= (count >> 28) || n >= ((count >> 20) & 15)) {
        Warning__Q26nw4hbm2dbFPCciPCce(
            (const char*)lbl_80320320, 0xC0, (const char*)lbl_8032036C,
            n, count >> 28, (*(volatile u32*)((u8*)mat + 0x4C) >> 20) & 15);
        return;
    }

    SetTextureNum__Q36nw4hbm3lyt8MaterialFUc(mat, (u8)(n + 1));
    SetTexture__Q36nw4hbm3lyt8MaterialFUcRC9_GXTexObj(
        *(void**)(self + 0x28), (u8)n, texObj);
    SetTexCoordGenNum__Q36nw4hbm3lyt8MaterialFUc(
        *(void**)(self + 0x28),
        (u8)(*(u32*)((u8*)*(void**)(self + 0x28) + 0x50) >> 28));

    mat = *(void**)(self + 0x28);
    coords[3] = 0;
    coords[0] = 1;
    coords[1] = 4;
    coords[2] = 0x3C;
    packed = *(u32*)coords;
    if (n >= ((*(u32*)((u8*)mat + 0x50) >> 20) & 15)) {
        Panic__Q26nw4hbm2dbFPCciPCce(
            (const char*)lbl_80320538, 0xB4, (const char*)lbl_80320504);
    }
    {
        u8* tc = (u8*)fn_800D9344(mat) + (u8)n * 4;
        tc[0] = ((u8*)&packed)[0];
        tc[1] = ((u8*)&packed)[1];
        tc[2] = ((u8*)&packed)[2];
        tc[3] = ((u8*)&packed)[3];
    }
    SetSize__Q46nw4hbm3lyt6detail11TexCoordAryFUc(
        self + 0xE4,
        (u8)(*(u32*)((u8*)*(void**)(self + 0x28) + 0x50) >> 28));

    defaults[0] = lbl_80560EC8;
    defaults[1] = lbl_80560EC8;
    int init = 0;
    if (*(f32*)(self + 0x4C) == lbl_80560EC8 &&
        *(f32*)(self + 0x50) == lbl_80560EC8) {
        init = 1;
    }
    if (init != 0 &&
        ((*(u32*)((u8*)*(void**)(self + 0x28) + 0x50) >> 28) == 1)) {
        GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc(
            size, *(void**)(self + 0x28), 0);
        *(f32*)(self + 0x4C) = size[0];
        *(f32*)(self + 0x50) = size[1];
    }
}

extern "C" void GetVtxColor__Q36nw4hbm3lyt7PictureCFUl(Color* out, const void* this_, u32 idx) {
    if (idx >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80320320, 0xFB, (const char*)lbl_803203D8);
    }
    const u8* p = (const u8*)this_ + idx * 4 + 0xD4;
    out->b0 = p[0];
    out->b1 = p[1];
    out->b2 = p[2];
    out->b3 = p[3];
}

extern "C" void SetVtxColor__Q36nw4hbm3lyt7PictureFUlQ36nw4hbm2ut5Color(
    void* this_, u32 idx, const Color* color) {
    if (idx >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80320320, 0x106,
                                     (const char*)lbl_803203D8);
    }

    ((u8*)this_)[(idx * 4) + 0xD4 + 0] = color->b0;
    ((u8*)this_)[(idx * 4) + 0xD4 + 1] = color->b1;
    ((u8*)this_)[(idx * 4) + 0xD4 + 2] = color->b2;
    ((u8*)this_)[(idx * 4) + 0xD4 + 3] = color->b3;
}

extern "C" u8 GetVtxColorElement__Q36nw4hbm3lyt7PictureCFUl(void* this_,
                                                            u32 idx) {
    if (idx >= 0x10) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803204F8, 0xC7,
                                     (const char*)lbl_803204BC);
    }

    u32 hi = idx & ~3;
    u32 lo = idx & 3;
    u8* p = (u8*)((u32)this_ + hi);
    return p[lo + 0xD4];
}

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7PictureFUlUc(void* this_,
                                                               u32 idx,
                                                               u8 color) {
    if (idx >= 0x10) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803204B0, 0xD4,
                                     (const char*)lbl_80320474);
    }

    u32 hi = idx & ~3;
    u32 lo = idx & 3;
    u8* p = (u8*)((u32)this_ + hi);
    p[lo + 0xD4] = color;
}

extern "C" s32 IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(void*, u8);
extern "C" void SetVertexFormat__Q34nw4r3lyt6detailFbUc(s32, u8);
extern "C" void* GetVtxPos__Q34nw4r3lyt4PaneCFv(void*);
extern "C" void DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(void*, void*, u8, s32, void*, u8);
extern "C" void DrawSelf__Q36nw4hbm3lyt7PictureFRCQ36nw4hbm3lyt8DrawInfo(void* this_) {
    u8* self = (u8*)this_;
    void* tex;
    u8 color;
    u8 format;
    s32 modulate;
    void* colors;
    void* pos;
    s32 size;

    tex = *(void**)(self + 0x28);
    if (tex == 0) return;
    ((void (*)(void*))(*(void***)this_)[0x60 / 4])(this_);
    color = self[0xCE];
    modulate = IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(self + 0xD4, color);
    tex = *(void**)(self + 0x28);
    modulate = ((s32 (*)(void*, s32, u8))(*(void***)tex)[0x0C / 4])(tex, modulate, color);
    format = self[0xE5];
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(modulate, format);
    colors = modulate ? self + 0xD4 : 0;
    size = *(s32*)(self + 0xE8);
    format = self[0xE5];
    pos = GetVtxPos__Q34nw4r3lyt4PaneCFv(this_);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(&pos, self + 0x4C, format, size, colors, color);
}

extern "C" u32* fn_800DCDFC(void) {
    return &lbl_8055DE00;
}
