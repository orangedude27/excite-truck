#include <types.h>
#include <string.h>

/* Review carves for REXE01 nw4hbm/nw4r lyout + homebutton cluster.
 * Review-only; not configured.
 */

extern "C" void fn_80128668(void*);

/* ---- homebutton::RemoteSpk::Connect(long) ---- */
extern "C" u32 fn_80060CC0(void* p, u32 a, u32 b);
extern "C" void fn_800D1B1C(void);

extern "C" void Connect__Q210homebutton9RemoteSpkFl(void* self, s32 soundId) {
    if (((u8*)self)[0x1EC]) {
        fn_80060CC0((void*)soundId, 1, (u32)&fn_800D1B1C);

        memset(&((u8*)self)[soundId * 0x68 + 0x30], 0, 0x20);

        ((u8*)self)[soundId * 0x68 + 0x5C] = 1;
        ((u8*)self)[soundId * 0x68 + 0x62] = 0;
    }
}

/* ---- nw4hbm::lyt::ArcResourceAccessor ctor/dtor ---- */
extern "C" void fn_800DCE50(void* this_);
extern "C" void fn_800DCE10(void* this_, s32 f);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void* this_, u32 a);

#pragma push
#pragma small_data off
extern u8 lbl_8031F43C[];
extern u8 lbl_8031F618[];
#pragma pop

extern "C" void __ct__Q36nw4hbm3lyt19ArcResourceAccessorFv(void* this_) {
    fn_800DCE50(this_);

    ((u32*)this_)[0x28 >> 2] = 0;
    ((u32*)this_)[0x2C >> 2] = 0;
    ((u32*)this_)[0x00 >> 2] = (u32)&lbl_8031F43C;
    ((u32*)this_)[0x20 >> 2] = 0;
    ((u32*)this_)[0x24 >> 2] = 0;
    ((u32*)this_)[0x28 >> 2] = (u32)&((u8*)this_)[0x28];
    ((u32*)this_)[0x2C >> 2] = (u32)&((u8*)this_)[0x28];
}

extern "C" void* __dt__Q36nw4hbm3lyt19ArcResourceAccessorFv(void* this_,
                                                            s32 flag) {
    if (this_) {
        if ((u8*)this_ + 0x24 != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(&((u8*)this_)[0x24], 0);
        }
        fn_800DCE10(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ---- nw4hbm::lyt::Bounding dtor / DrawSelf ---- */
extern "C" void __dt__Q36nw4hbm3lyt4PaneFv(void* this_, s32 flag);

extern "C" void* __dt__Q36nw4hbm3lyt8BoundingFv(void* this_, s32 flag) {
    if (this_) {
        __dt__Q36nw4hbm3lyt4PaneFv(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ---- nw4r::lyt::DrawInfo ctor ---- */
extern "C" void PSMTXIdentity(void*);

#pragma push
#pragma small_data off
extern f32 lbl_80560E78;
extern f32 lbl_80560E7C;
#pragma pop

extern "C" void* __ct__Q34nw4r3lyt8DrawInfoFv(void* this_) {
    f32 f1 = lbl_80560E78;
    f32 f0 = lbl_80560E7C;

    ((u32*)this_)[0x0] = (u32)&lbl_8031F618;
    ((f32*)this_)[0x34 >> 2] = f1;
    ((f32*)this_)[0x38 >> 2] = f1;
    ((f32*)this_)[0x3C >> 2] = f1;
    ((f32*)this_)[0x40 >> 2] = f1;
    ((f32*)this_)[0x44 >> 2] = f0;
    ((f32*)this_)[0x48 >> 2] = f0;
    ((f32*)this_)[0x4C >> 2] = f0;

    memset(&((u8*)this_)[0x50], 0, 1);

    PSMTXIdentity(&((u8*)this_)[0x04]);

    return this_;
}

/* ---- nw4hbm::lyt::GroupContainer::AppendGroup ---- */
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(void);
extern "C" void Insert_nw4hbm(void*, void*, void*);
#pragma push
#pragma small_data off
extern u8 lbl_8031F658[];
extern u8 lbl_8031F634[];
#pragma pop

extern "C" void AppendGroup__Q36nw4hbm3lyt14GroupContainerFPQ36nw4hbm3lyt5Group(
    void* this_, void* group) {
    u8* node = (u8*)this_ + 0x4;
    void* iter;

    if (group == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce();
    }

    iter = (u8*)node + 48;
    Insert_nw4hbm(this_, iter, &((u8*)group)[0x4]);
}

/* ---- nw4r::lyt::Layout::GetLayoutRect ---- */
extern "C" void GetLayoutRect__Q34nw4r3lyt6LayoutCFv(void* pOut, void* self) {
    u8* p = (u8*)self;
    f32 f0, f1, f2, f3;

    if (p[0x20] == 1) {
        /* centered rect from m_rect (w @0x18, h @0x1C) scaled by 0.5 */
        extern f32 lbl_80560E84;
        f32 w = *(f32*)&p[0x18];
        f32 h = *(f32*)&p[0x1C];
        f32 s = lbl_80560E84;

        *(f32*)&((u8*)pOut)[0x08] = w * s;
        *(f32*)&((u8*)pOut)[0x04] = h * s;
        *(f32*)&((u8*)pOut)[0x00] = -w * s;
        *(f32*)&((u8*)pOut)[0x0C] = -h * s;
    } else {
        extern f32 lbl_80560E80;
        f32 z = lbl_80560E80;

        *(f32*)&((u8*)pOut)[0x00] = z;
        *(f32*)&((u8*)pOut)[0x04] = z;
        *(f32*)&((u8*)pOut)[0x08] = *(f32*)&p[0x18];
        *(f32*)&((u8*)pOut)[0x0C] = *(f32*)&p[0x1C];
    }
}