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

struct Color {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
};

extern "C" void InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(void*, void*, u32);
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

extern "C" u32* fn_800DCDFC(void) {
    return &lbl_8055DE00;
}
