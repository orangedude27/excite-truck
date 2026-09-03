#include <types.h>
#include <string.h>

/* Review carves for the REXE01 nw4hbm/nw4r lyout Pane/Picture/TextBox
 * cluster (auto_03_800D58C4_text / auto_03_800DC6F0_text /
 * auto_03_800DCE10_text):
 *
 *   DrawSelf__Q36nw4hbm3lyt4PaneFRCQ36nw4hbm3lyt8DrawInfo
 *   BindAnimation__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformb
 *   FindAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform
 *   GetVtxColorElement__Q36nw4hbm3lyt7PictureCFUl
 *   SetVtxColorElement__Q36nw4hbm3lyt7PictureFUlUc
 *   GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl
 *
 * Review-only; not configured.
 */

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char* file, int line,
                                              const char* fmt, ...);
#pragma push
#pragma small_data off
extern u8 lbl_8031FF90[];
extern u8 lbl_803200C8[];
extern u8 lbl_803204F8[];
extern u8 lbl_803204BC[];
extern u8 lbl_803204B0[];
extern u8 lbl_80320474[];
extern u8 lbl_80320570[];
extern u8 lbl_80320688[];
#pragma pop
extern "C" void* fn_800D4F98(void* pList, void* pTransform);

extern "C" void GetVtxPos__Q34nw4r3lyt4PaneCFv(void* this_);
extern "C" void DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(
    void*, void*, u32);

/* ------------------------------------------------------------------ */
/* Pane::DrawSelf(DrawInfo const&)                                    */
/* ------------------------------------------------------------------ */
extern "C" void DrawSelf__Q36nw4hbm3lyt4PaneFRCQ36nw4hbm3lyt8DrawInfo(
    void* this_, void* pDrawInfo) {
    if (((u32*)this_)[0x0C / 4] != 0 && ((((u8*)pDrawInfo)[0x50] >> 3) & 1)) {
        /* virtual (vtable+0x60) */
        {
            void (*fn)(void*) = *(void (**)(void*))((*(u32*)this_) + 0x60);
            fn(this_);
        }

        GetVtxPos__Q34nw4r3lyt4PaneCFv(this_);

        {
            u32 color = 0xFFFFFFFF;
            DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(
                &((u8*)this_)[0x4C], &color, color);
        }
    }
}

/* ------------------------------------------------------------------ */
/* Pane::BindAnimation(AnimTransform*, bool)                           */
/* ------------------------------------------------------------------ */
extern "C" void BindAnimation__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformb(
    void* this_, void* pAnimTrans, u32 enable) {
    if (pAnimTrans == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_8031FF90, 0x254,
                                     (const char*)lbl_803200C8);
    }

    /* virtual (vtable+0x10) — pAnimTrans dispatch */
    {
        void (*fn)(void*, void*, u32) =
            *(void (**)(void*, void*, u32))((*(u32*)pAnimTrans) + 0x10);
        fn(pAnimTrans, this_, enable);
    }
}

/* ------------------------------------------------------------------ */
/* Pane::FindAnimationLink(AnimTransform*)                             */
/* ------------------------------------------------------------------ */
extern "C" void* FindAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(
    void* this_, void* pAnimTrans) {
    void* result;
    void* pBind;

    result = fn_800D4F98(&((u8*)this_)[0x1C], pAnimTrans);
    if (result != NULL) {
        return result;
    }

    pBind = ((void**)this_)[0x28 / 4];
    if (pBind == NULL) {
        return NULL;
    }

    /* virtual (vtable+0x20) */
    {
        void* (*fn)(void*, void*) = *(void* (**)(void*, void*))(*(u32*)pBind + 0x20);
        return fn(pBind, pAnimTrans);
    }
}

/* ------------------------------------------------------------------ */
/* Picture::Get/SetVtxColorElement(unsigned long, u8)                  */
/* ------------------------------------------------------------------ */
extern "C" u8 GetVtxColorElement__Q36nw4hbm3lyt7PictureCFUl(void* this_,
                                                             u32 idx) {
    if (idx >= 0x10) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803204F8, 0xC7,
                                     (const char*)lbl_803204BC);
    }

    return ((u8*)this_)[0xD4 + (idx & ~3) + (idx & 3)];
}

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7PictureFUlUc(void* this_,
                                                                u32 idx,
                                                                u8 color) {
    if (idx >= 0x10) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803204B0, 0xD4,
                                     (const char*)lbl_80320474);
    }

    ((u8*)this_)[0xD4 + (idx & ~3) + (idx & 3)] = color;
}

/* ------------------------------------------------------------------ */
/* TextBox::GetVtxColor(unsigned long)                                 */
/* ------------------------------------------------------------------ */
extern "C" u32 GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(void* this_, u32 idx);

extern "C" u32 GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(void* this_, u32 idx,
                                                      u32 gradIdx) {
    if (gradIdx >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80320570, 0x1D3,
                                     (const char*)lbl_80320688);
    }

    return GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(this_, (idx << 1) | (gradIdx >> 1));
}
/* ------------------------------------------------------------------ */
/* TextBox::Get/SetVtxColorElement — vtx color table at +0xD8,         */
/* index = ((idx >> 2) << 1) | (idx & 3).                             */
/* ------------------------------------------------------------------ */
extern "C" u8 GetVtxColorElement__Q36nw4hbm3lyt7TextBoxCFUl(void* this_,
                                                             u32 idx) {
    if (idx >= 0x10) {
        extern u8 lbl_803206B8[];
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80320570, 0x1E6,
                                     (const char*)lbl_803206B8);
    }

    return ((u8*)this_)[0xD8 + (idx >> 1) + (idx & 3)];
}

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7TextBoxFUlUc(void* this_,
                                                                u32 idx,
                                                                u8 color) {
    if (idx >= 0x10) {
        extern u8 lbl_803206B8[];
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80320570, 0x1EE,
                                     (const char*)lbl_803206B8);
    }

    ((u8*)this_)[0xD8 + (idx >> 1) + (idx & 3)] = color;
}

/* ------------------------------------------------------------------ */
/* TextBox::AllocStringBuffer(u16)                                     */
/* ------------------------------------------------------------------ */
extern "C" void* MEMAllocFromAllocator(void* allocator, u32 size);
extern u32 lbl_8055DDF0;

extern "C" void AllocStringBuffer__Q36nw4hbm3lyt7TextBoxFUs(void* this_,
                                                            u16 len) {
    if (len != 0) {
        u16 bytes = (u16)((len + 1) * 2);

        if (bytes > *(u16*)&((u8*)this_)[0xF8]) {
            /* vtable+0x68 (allocator query; result unused) */
            {
                void (*fn)(void*) = *(void (**)(void*))(*(u32*)this_ + 0x68);
                fn(this_);
            }

            ((void**)this_)[0xD4 / 4] =
                MEMAllocFromAllocator((void*)lbl_8055DDF0, bytes);

            if (((void**)this_)[0xD4 / 4] != NULL) {
                *(u16*)&((u8*)this_)[0xF8] = bytes;
            }
        }
    }
}

/* ------------------------------------------------------------------ */
/* TextBox::SetString(const wchar_t*, u16)                             */
/* ------------------------------------------------------------------ */
extern "C" u32 fn_8002AEE8(const u16* s); /* wcslen */

extern "C" void SetString__Q36nw4hbm3lyt7TextBoxFPCwUs(void* this_,
                                                       const u16* str,
                                                       u16 len) {
    u32 wlen = fn_8002AEE8(str);
    void (*fn)(void*, const u16*, u32) =
        *(void (**)(void*, const u16*, u32))(*(u32*)this_ + 0x70);
    fn(this_, str, (u32)(u16)wlen);
}

/* ------------------------------------------------------------------ */
/* Picture clones at 0x800E0350 / 0x800E03BC (same Panic/offsets).    */
/* ------------------------------------------------------------------ */
extern "C" u8 GetVtxColorElement__Q36nw4hbm3lyt7PictureCFUl_800E0350(
    void* this_, u32 idx) {
    if (idx >= 0x10) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803204F8, 0xC7,
                                     (const char*)lbl_803204BC);
    }

    return ((u8*)this_)[0xE4 + (idx & ~3) + (idx & 3)];
}

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7PictureFUlUc_800E03BC(
    void* this_, u32 idx, u8 color) {
    if (idx >= 0x10) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803204B0, 0xD4,
                                     (const char*)lbl_80320474);
    }

    ((u8*)this_)[0xE4 + (idx & ~3) + (idx & 3)] = color;
}
