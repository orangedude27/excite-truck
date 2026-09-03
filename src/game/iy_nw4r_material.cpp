#include <types.h>
#include <string.h>

/* Review carves for the REXE01 nw4hbm/nw4r lyout Material + Bounding
 * cluster (auto_03_800D58C4_text):
 *
 *   Init__Q34nw4r3lyt8MaterialFv
 *   GetIndTexSRTAry__Q36nw4hbm3lyt8MaterialFv
 *   AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink
 *   DrawSelf__Q36nw4hbm3lyt8BoundingFRCQ36nw4hbm3lyt8DrawInfo
 *
 * Review-only; not configured.
 */

/* ------------------------------------------------------------------ */
/* nw4hbm::lyt::Material                                              */
/* ------------------------------------------------------------------ */
extern s16 lbl_80565230[4];   // default material color quad (sdata2)

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(void);
extern "C" void Insert_nw4hbmList(void*, void*, void*);

extern "C" void Init__Q34nw4r3lyt8MaterialFv(void* this_) {
    ((s16*)this_)[0x24 / 2] = lbl_80565230[0];
    ((s16*)this_)[0x26 / 2] = lbl_80565230[1];
    ((s16*)this_)[0x28 / 2] = lbl_80565230[2];
    ((s16*)this_)[0x2A / 2] = lbl_80565230[3];

    ((s16*)this_)[0x2C / 2] = 0xFF;
    ((s16*)this_)[0x2E / 2] = 0xFF;
    ((s16*)this_)[0x30 / 2] = 0xFF;
    ((s16*)this_)[0x32 / 2] = 0xFF;
    ((s16*)this_)[0x34 / 2] = 0xFF;
    ((s16*)this_)[0x36 / 2] = 0xFF;
    ((s16*)this_)[0x38 / 2] = 0xFF;
    ((s16*)this_)[0x3A / 2] = 0xFF;

    ((u32*)this_)[0x4C / 4] = ((u32*)this_)[0x4C / 4] & 0x1F;
    ((u32*)this_)[0x50 / 4] = ((u32*)this_)[0x50 / 4] & 0x1F;

    ((u8*)this_)[0x54] = 0;
    ((u32*)this_)[0x58 / 4] = 0;
}

/* Material::GetIndTexSRTAry — bitfield-counted GX-mem slice offset.
 * From the packed mGXMemCap word at +0x4C: texSrt occupies bits 7..4 and
 * is the only element with 0x14-byte stride; the remaining packed counts
 * (bits 3,1,2,9, 15..12, 17..14, 10..8, 0) are summed as raw offsets. */
extern "C" void* GetIndTexSRTAry__Q36nw4hbm3lyt8MaterialFv(void* this_) {
    u32 cap = ((u32*)this_)[0x4C / 4];
    u32 base = ((u32*)this_)[0x58 / 4];
    u32 sum;

    sum = ((cap >> 1) & 1) + ((cap >> 3) & 1) + ((cap >> 9) & 1) +
          ((cap >> 2) & 1) + ((cap >> 12) & 0xF) + ((cap >> 14) & 0xF) +
          ((cap >> 8) & 7) + (cap & 1);

    return (void*)(base + ((cap >> 4) & 0xF) * 0x14 + sum);
}

/* Material::AddAnimationLink — null-check + LinkList<AnimationLink>
 * mAnimList.Insert(mAnimList.End(), pAnimLink). */
extern "C" void AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink(
    void* this_, void* pAnimLink) {
    u8* list = (u8*)this_ + 0x18;     /* mAnimList (LinkList head) */
    u32 iter = (u32)&((u8*)this_)[0x1C]; /* end sentinel address */

    if (pAnimLink == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce();
    }

    Insert_nw4hbmList(list, &iter - 1 + 1, pAnimLink);
}

/* ------------------------------------------------------------------ */
/* nw4hbm::lyt::Bounding::DrawSelf                                    */
/* ------------------------------------------------------------------ */
extern "C" void GetVtxPos__Q34nw4r3lyt4PaneCFv(void* this_);
extern "C" void DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(
    void*, void*, u32);

extern "C" void DrawSelf__Q36nw4hbm3lyt8BoundingFRCQ36nw4hbm3lyt8DrawInfo(
    void* this_, void* pDrawInfo) {
    u32 vtx[2];

    if (((((u8*)pDrawInfo)[0x50] >> 3) & 1) != 0) {
        /* call virtual (vtable+0x60) GetVtxPos */
        {
            void (*fn)(void*) = *(void (**)(void*))((*(u32*)this_) + 0x60);
            fn(this_);
        }

        vtx[1] = 0xFFFFFFFF;
        GetVtxPos__Q34nw4r3lyt4PaneCFv(this_);
        vtx[0] = 0xFFFFFFFF;

        DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(
            &vtx[0], &((u8*)this_)[0x4C], vtx[1]);
    }
}