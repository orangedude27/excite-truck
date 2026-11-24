// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char* file, s32 line,
                                             const char* fmt, ...);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char* file, s32 line,
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

/* Assertion messages and strings passed to nw4hbm::db::Panic/Warning. */
#define sAssertFile_common lbl_803204B0 /* "common.h" */
#define sAssertIdxAnimTargetVtxColor lbl_80320474 /* "NW4HBM:Failed assertion idx < ANIMTARGET_VERTEXCOLOR_MAX" */
#define sAssertFile_animTarget lbl_803204F8 /* "common.h" */
#define sAssertIdxAnimTargetByte lbl_803204BC /* "NW4HBM:Failed assertion idx < ANIMTARGET_VERTEXCOLOR_MAX" */
#define sAssertFile_picture lbl_80320320 /* "lyt_picture.cpp" */
#define sAssertIdxVtxColorMax lbl_803203D8 /* "NW4HBM:Failed assertion idx < VERTEXCOLOR_MAX" */
#define sMsgNullPointer lbl_80320330 /* "NW4HBM:Pointer must not be NULL " */
#define sMsgTexNumTooLarge lbl_8032036C /* "mpMaterial->GetTextureNum(%d) is large..." */
#define sAssertTexCoordGen lbl_80320504 /* "NW4HBM:Failed assertion idx < mGXMemNum.texCoordGen" */
#define sAssertFile_material lbl_80320538 /* "material.h" */
#define sZeroFloat lbl_80560EC8 /* 0.0f, the shared float constant */

enum { VERTEXCOLOR_NUM = 4 }; /* corner colors a pane's vertex array carries */
/* the four corner colors seen as their 4x4 bytes, which is how an animation
 * target addresses a single channel of one */
enum { ANIMTARGET_VERTEXCOLOR_MAX = VERTEXCOLOR_NUM * 4 };

extern u32 lbl_8055DE00; /* sentinel that ends a layout's pane list */
#define sLayoutListEnd lbl_8055DE00

#include <nw4hbm_ut.h>
using nw4hbm::ut::Color;

extern "C" void InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(void*, void*, u32);
#pragma push
#pragma small_data off
extern u8 lbl_80320408[];
extern u8 fn_800D2DD4[];
extern u32 lbl_8055DDF0;
#pragma pop

/* vtable installed on a Picture, the layout allocator, and the deleting
 * destructor handed to the detail::TexCoordAry helpers. */
#define sPictureVTable lbl_80320408
#define sLayoutAllocator lbl_8055DDF0
#define sTexCoordDtor fn_800D2DD4

extern "C" void MEMFreeToAllocator(void*, void*);
extern "C" void fn_800D598C(void*);
struct PicDataVt {
    virtual void vf0(int);
    virtual void vf1();
    virtual void vf2(int);
};
extern "C" void __array_delete(void*, void*, s32, s32);
extern "C" void __dt__Q36nw4hbm3lyt4PaneFv(void*, s32);
extern "C" void fn_80128668(void*);

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
    /* Initialize the Pane base, install the Picture vtable, reserve/copy texcoords
     * and vertex colors from the resource, then attach a Material (panicking if
     * the block set has no material table). */
    u8* self = (u8*)this_;
    const u8* picture = (const u8*)res;
    u8 count;
    void* material;

    __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(this_, res);
    *(void**)self = sPictureVTable;
    fn_8002F53C(self + 0xD4, fn_800D7F6C, sTexCoordDtor, 4, 4);
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
    material = MEMAllocFromAllocator((void*)sLayoutAllocator, 0x5C);
    if (material != 0) {
        if (*(const u32*)((const u8*)blockSet + 8) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)sAssertFile_picture, 0x95, (const char*)sMsgNullPointer);
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

extern "C" void* __dt__Q36nw4hbm3lyt7PictureFv(void* this_, s32 deleteFlag) {
    /* Picture destructor: release the owned material, destroy the texcoord and
     * vertex-color arrays and the base Pane, then optionally free the storage. */
    register void* material;
    if (this_ != 0) {
        material = *(void**)((u8*)this_ + 0x28);
        *(void**)this_ = sPictureVTable;
        if (material != 0 && *((u8*)material + 0x54) == 0) {
            ((PicDataVt*)material)->vf0(-1);
            MEMFreeToAllocator((void*)sLayoutAllocator, *(void**)((u8*)this_ + 0x28));
            *(u32*)((u8*)this_ + 0x28) = 0;
        }
        fn_800D598C((u8*)this_ + 0xE4);
        __array_delete((u8*)this_ + 0xD4, sTexCoordDtor, 4, 4);
        __dt__Q36nw4hbm3lyt4PaneFv(this_, 0);
        if (deleteFlag > 0) fn_80128668(this_);
    }
    return this_;
}
extern "C" void fn_800DC918(void *picture, void *tplPalette) {
    /* Build a GX texture object from TPL image 0 and hand it to Picture::Set. */
    struct PictureVTable {
        virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
        virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
        virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void setTexture(void *texObj);
    };
    u8 texObj[0x20];
    InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(texObj, tplPalette, 0);
    ((PictureVTable *)picture)->setTexture(texObj);
}

extern "C" void SetTextureNum__Q36nw4hbm3lyt8MaterialFUc(void*, u8);
extern "C" void SetTexture__Q36nw4hbm3lyt8MaterialFUcRC9_GXTexObj(void*, u8, const void*);
extern "C" void SetTexCoordGenNum__Q36nw4hbm3lyt8MaterialFUc(void*, u8);
extern "C" void* fn_800D9344(void*);
extern "C" void SetSize__Q46nw4hbm3lyt6detail11TexCoordAryFUc(void*, u8);
extern "C" void GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc(f32*, void*, u8);
extern "C" u8 lbl_8032036C[], lbl_80320504[], lbl_80320538[];
extern f32 lbl_80560EC8;
extern "C" void Append__Q36nw4hbm3lyt7PictureFRC9_GXTexObj(void *picture, const void *texObj) {
    u8 *self = (u8 *)picture;
    u32 texIndex;
    void *material = *(void **)(self + 0x28);
    u32 matCounts = *(volatile u32 *)((u8 *)material + 0x4C);
    texIndex = *(volatile u32 *)((u8 *)material + 0x50) >> 28;
    u32 packed;
    u8 coords[4];
    volatile f32 defaults[2];
    f32 size[2];

    /* Append a texture to the picture's material and ensure tex coord/size state. */
    if (texIndex >= (matCounts >> 28) || texIndex >= ((matCounts >> 20) & 15)) {
        Warning__Q26nw4hbm2dbFPCciPCce(
            (const char *)sAssertFile_picture, 0xC0, (const char *)sMsgTexNumTooLarge,
            texIndex, matCounts >> 28, (*(volatile u32 *)((u8 *)material + 0x4C) >> 20) & 15);
        return;
    }

    SetTextureNum__Q36nw4hbm3lyt8MaterialFUc(material, (u8)(texIndex + 1));
    SetTexture__Q36nw4hbm3lyt8MaterialFUcRC9_GXTexObj(
        *(void **)(self + 0x28), (u8)texIndex, texObj);
    SetTexCoordGenNum__Q36nw4hbm3lyt8MaterialFUc(
        *(void **)(self + 0x28),
        (u8)(*(u32 *)((u8 *)*(void **)(self + 0x28) + 0x50) >> 28));

    material = *(void **)(self + 0x28);
    coords[3] = 0;
    coords[0] = 1;
    coords[1] = 4;
    coords[2] = 0x3C;
    packed = *(u32 *)coords;
    if (texIndex >= ((*(u32 *)((u8 *)material + 0x50) >> 20) & 15)) {
        Panic__Q26nw4hbm2dbFPCciPCce(
            (const char *)sAssertFile_material, 0xB4, (const char *)sAssertTexCoordGen);
    }
    {
        u8 *tc = (u8 *)fn_800D9344(material) + (u8)texIndex * 4;
        tc[0] = ((u8 *)&packed)[0];
        tc[1] = ((u8 *)&packed)[1];
        tc[2] = ((u8 *)&packed)[2];
        tc[3] = ((u8 *)&packed)[3];
    }
    SetSize__Q46nw4hbm3lyt6detail11TexCoordAryFUc(
        self + 0xE4,
        (u8)(*(u32 *)((u8 *)*(void **)(self + 0x28) + 0x50) >> 28));

    defaults[0] = sZeroFloat;
    defaults[1] = sZeroFloat;
    int init = 0;
    if (*(f32 *)(self + 0x4C) == sZeroFloat &&
        *(f32 *)(self + 0x50) == sZeroFloat) {
        init = 1;
    }
    if (init != 0 &&
        ((*(u32 *)((u8 *)*(void **)(self + 0x28) + 0x50) >> 28) == 1)) {
        GetTextureSize__Q36nw4hbm3lyt6detailFPQ36nw4hbm3lyt8MaterialUc(
            size, *(void **)(self + 0x28), 0);
        *(f32 *)(self + 0x4C) = size[0];
        *(f32 *)(self + 0x50) = size[1];
    }
}

extern "C" void GetVtxColor__Q36nw4hbm3lyt7PictureCFUl(Color* out, const void* this_, u32 idx) {
    /* Gets one of the picture's four vertex colors, asserting the index is in range. */
    if (idx >= VERTEXCOLOR_NUM) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)sAssertFile_picture, 0xFB, (const char*)sAssertIdxVtxColorMax);
    }
    const u8* p = (const u8*)this_ + idx * 4 + 0xD4;
    out->b0 = p[0];
    out->b1 = p[1];
    out->b2 = p[2];
    out->b3 = p[3];
}

extern "C" void SetVtxColor__Q36nw4hbm3lyt7PictureFUlQ36nw4hbm2ut5Color(
    void* this_, u32 idx, const Color* color) {
    /* Sets one of the picture's four vertex colors, asserting the index is in range. */
    if (idx >= VERTEXCOLOR_NUM) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)sAssertFile_picture, 0x106,
                                     (const char*)sAssertIdxVtxColorMax);
    }

    ((u8*)this_)[(idx * 4) + 0xD4 + 0] = color->b0;
    ((u8*)this_)[(idx * 4) + 0xD4 + 1] = color->b1;
    ((u8*)this_)[(idx * 4) + 0xD4 + 2] = color->b2;
    ((u8*)this_)[(idx * 4) + 0xD4 + 3] = color->b3;
}

extern "C" u8 GetVtxColorElement__Q36nw4hbm3lyt7PictureCFUl(void* this_,
                                                             u32 idx) {
    /* Return one byte of the picture's four vertex colors (the 16-byte
     * animation-target view at +0xD4), asserting the index is in range. */
    if (idx >= ANIMTARGET_VERTEXCOLOR_MAX) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)sAssertFile_animTarget, 0xC7,
                                     (const char*)sAssertIdxAnimTargetByte);
    }

    u32 hi = idx & ~3;
    u32 lo = idx & 3;
    u8* p = (u8*)((u32)this_ + hi);
    return p[lo + 0xD4];
}

namespace nw4hbm { namespace lyt {
    /* Picture pane: the last of its members are the four corner colors of the
     * quad it draws, indexed by the vertex-color accessors below. */
    struct Picture {
        u8 unk_0[0xD4];
        Color vtxColor[VERTEXCOLOR_NUM]; /* 0xD4 */
    };
} }

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7PictureFUlUc(
    nw4hbm::lyt::Picture* this_, u32 idx, u8 color) {
    /* Store one channel of a picture corner color -- the four Colors at 0xD4
     * seen as the 16 bytes an animation target indexes by -- with a range check. */
    if (idx >= ANIMTARGET_VERTEXCOLOR_MAX) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)sAssertFile_common, 0xD4,
                                     (const char*)sAssertIdxAnimTargetVtxColor);
    }

    u32 hi = idx & ~3;
    u32 lo = idx & 3;
    u8* p = (u8*)((u32)this_ + hi);
    p[lo + 0xD4] = color;
}

extern "C" s32 IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(void*, u8);
extern "C" void SetVertexFormat__Q34nw4r3lyt6detailFbUc(s32, u8);
extern "C" u64 GetVtxPos__Q34nw4r3lyt4PaneCFv(void*);
extern "C" void DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(void*, void*, u8, s32, void*, u8);
struct PicVTable {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15();
    virtual void prep();
};
struct TexVTable {
    virtual void v0();
    virtual s32 mod(s32, u8);
};
/* Draws this picture pane as a textured quad using its current material and vertex colors. */
extern "C" void DrawSelf__Q36nw4hbm3lyt7PictureFRCQ36nw4hbm3lyt8DrawInfo(void *this_)
{
  u8 *self = (u8 *) this_;
  void *material = *((void **) (self + 0x28));
  u8 texCoordCount;
  s32 texCoordArray;
  s32 vertexAlpha;
  void *vtxColors;
  u64 vtxPos;
  if (material == 0)
  {
    return;
  }
  ((PicVTable *) this_)->prep();
  vertexAlpha = self[0xCE];
  texCoordArray = IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(self + 0xD4, (u8) vertexAlpha);
  material = *((void **) (self + 0x28));
  texCoordArray = ((TexVTable *) material)->mod(texCoordArray, (u8) vertexAlpha);
  SetVertexFormat__Q34nw4r3lyt6detailFbUc(texCoordArray, self[0xE5]);
  vtxColors = (texCoordArray) ? (self + 0xD4) : (0);
  texCoordArray = *((s32 *) (self + 0xE8));
  texCoordCount = self[0xE5] ^ 0;
  vtxPos = GetVtxPos__Q34nw4r3lyt4PaneCFv(this_);
  DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(&vtxPos, self + 0x4C, texCoordCount, texCoordArray, vtxColors, self[0xCE]);
}

extern "C" u32* fn_800DCDFC(void) {
    /* Return the address of the global sentinel tag that ends a layout node list. */
    return &sLayoutListEnd;
}
