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
    u8 tex[0x20];
    InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(tex, palette, 0);
    ((void (*)(void*, void*))(*(void***)this_)[0x68 / 4])(this_, tex);
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
    register void* pane = this_;
    register void* tex;
    register s32 modulate;
    register void* colors;
    register s32 size;
    register u8 color;
    register u8 format;
    register void* pos;
    tex = *(void**)((u8*)pane + 0x28);
    if (tex == 0) return;
    ((void (*)(void*))(*(void***)pane)[0x60 / 4])(pane);
    color = *((u8*)pane + 0xCE);
    modulate = IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc((u8*)pane + 0xD4, color);
    modulate = ((s32 (*)(void*, s32, u8))(*(void***)tex)[3])(tex, modulate, color);
    format = *((u8*)pane + 0xE5);
    SetVertexFormat__Q34nw4r3lyt6detailFbUc(modulate, format);
    colors = modulate ? (u8*)pane + 0xD4 : 0;
    size = *(s32*)((u8*)pane + 0xE8);
    format = *((u8*)pane + 0xE5);
    pos = GetVtxPos__Q34nw4r3lyt4PaneCFv(pane);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(&pos, (u8*)pane + 0x4C, format, size, colors, color);
}

extern "C" u32* fn_800DCDFC(void) {
    return &lbl_8055DE00;
}
