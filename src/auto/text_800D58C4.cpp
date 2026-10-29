// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include "revolution/GX/GXTypes.h"
#include "revolution/GX/GXAttr.h"
#include "revolution/MTX/mtxtypes.h"
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
struct GetVtxPosResult { f32 x; f32 y; };
namespace nw4hbm { namespace lyt {
class ResourceAccessor;
class Layout {
public:
    s32 Build(const void *, ResourceAccessor *);
};
}}
extern "C" f32 lbl_80560EA8;
extern "C" char lbl_8032012C[];
extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" f32 CosFIdx__Q24nw4r4mathFf(f32);                   /* extern */
extern "C" void *GXGetTexObjHeight(s32 *);                     /* extern */
extern "C" s32 GXGetTexObjMipMap(s32 *, s32);                  /* extern */
extern "C" int GXInitTexObjTlut(s32 *, s32);               /* extern */
extern "C" int GXInitTlutObj(int *, s32, s32, u16);    /* extern */
extern "C" int GXLoadTexMtxImm(int *, s32, int);   /* extern */
extern "C" int GXLoadTexObj(s32 *, u32);                   /* extern */
extern "C" int GXLoadTlut(int *, s32);                 /* extern */
extern "C" int GXSetAlphaCompare(s32, u8, u8, s32, u8);    /* extern */
extern "C" int GXSetBlendMode(u8, u8, u8, u8, void *, s32); /* extern */
extern "C" int GXSetChanCtrl(int, int, int, u8, int, int, int); /* extern */
extern "C" int GXSetChanMatColor_Internal(int, u8 *, u8, u8, u8); /* extern */
extern "C" int GXSetIndTexCoordScale(u32, u8, u8);         /* extern */
extern "C" int GXSetIndTexOrder(u32, u8, u8);              /* extern */
extern "C" int GXSetNumChans(int);                     /* extern */
extern "C" int GXSetNumIndStages(s32);                     /* extern */
extern "C" int GXSetNumTevStages(u8);                      /* extern */
extern "C" int GXSetTevAlphaIn(u8, s32, s32, s32, s32);    /* extern */
extern "C" int GXSetTevAlphaOp(u8, s32, s32, s32, s32, s32); /* extern */
extern "C" int GXSetTevColorIn(u8, s32, s32, s32, s32);    /* extern */
extern "C" int GXSetTevColorOp(u8, s32, s32, s32, s32, s32); /* extern */
extern "C" int GXSetTevColorS10(int, u16 *, u16);      /* extern */
extern "C" int GXSetTevDirect(u8);                         /* extern */
extern "C" int GXSetTevIndirect(u8, u8, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
extern "C" int GXSetTevKAlphaSel(u8, s32);                 /* extern */
extern "C" int GXSetTevKColor(int, u8 *);              /* extern */
extern "C" int GXSetTevKColorSel(u8, s32);                 /* extern */
extern "C" int GXSetTevOrder(u8, u8, u8, u8);              /* extern */
extern "C" int GXSetTevSwapMode(u8, s32, s32);             /* extern */
extern "C" int GXSetTevSwapModeTable(s32, s32, s32, s32, s32); /* extern */
extern "C" f32 SinFIdx__Q24nw4r4mathFf(f32);                   /* extern */

extern "C" void fn_800D4F98(void *);
extern "C" f32 lbl_80560E8C;
extern "C" f32 lbl_80560E88;
extern "C" f32 lbl_80560E90;
extern "C" f32 lbl_80560E94;
extern "C" int lbl_80565230;
extern "C" s32 fn_80128668(void);
namespace nw4hbm { namespace lyt {
struct DrawInfo;
class Pane { public: void CalculateMtx(const DrawInfo &); };
struct PaneMtxDispatch {
    virtual void d0(); virtual void d1();
    virtual void Apply(const DrawInfo &);
};
}}
extern "C" void PSMTXConcat(const f32 *, const f32 *, f32 *);
extern "C" void PSMTXScale(f32 *, f32, f32, f32);
extern "C" u32 PSMTXInverse(f32 *, s32, f32);
extern "C" void PSMTXRotTrig(f32 *, void *, f32, f32, f32);
extern "C" f64 lbl_80560EB8;
extern "C" f32 lbl_80560EB4;
extern "C" f32 lbl_80560EAC;
extern "C" f32 lbl_80560EB0;



extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*, void**);
extern "C" void DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(void*, void*, void*);
extern "C" GetVtxPosResult GetVtxPos__Q34nw4r3lyt4PaneCFv(void*);

struct GroupNodeV { virtual ~GroupNodeV(); virtual void f(); };
struct GroupListNode { GroupListNode* next; };
struct GroupList { u32 count; GroupListNode* first; GroupListNode* last; };
struct GroupLayout { void* vtable; u32 unk4; u32 unk8; GroupList children; };
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
extern "C" void MEMFreeToAllocator(s32, void* = 0);
extern "C" s32 lbl_8055DDF0;
extern "C" const char lbl_8031F728[];
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" s32 fn_800D4428(void);
int strncmp(const char *, const char *, unsigned int);
extern "C" int strncmp(const char *, const char *, unsigned int);
struct AlphaColor { u8 r, g, b, a; };
struct ResBlockSetTmp { u32 a, b, c, d; };
struct AnimEnableVTable {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
};
struct AnimEnableObject : AnimEnableVTable {};
struct PaneAnimVTable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct PaneAnimObject : PaneAnimVTable {};
struct PaneAnimRet { virtual void f0(); virtual void f1(); virtual void f2(); virtual void* f3(); };
struct StateObject_800D6CA0 { virtual void v0(); virtual void v1(); virtual void* v2(); };
struct Dummy_800DB1E8 {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual void *call();
};
struct StateNode_800D6CA0 { StateNode_800D6CA0* next; };
extern "C" s32 lbl_8055DE08;
struct PaneAnimLink {
    PaneAnimLink* next;
    void* unk4;
    PaneAnimObject* animation;
    u16 index;
    u8 disabled;
};
extern "C" const char lbl_8031E8FC[];
extern "C" const char lbl_8031E8D8[];

extern "C" char lbl_8031F628[];
extern "C" const char lbl_8031F6C4[];
extern "C" const char lbl_8031F6E8[];
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" s32 fn_800D58C4(const char* a, const char* b) { return strncmp(a, b, 0x10) == 0; }

extern "C" int fn_800D58F0(const char *a, const char *b) { return strncmp(a, b, 0x14) == 0; }

extern "C" s32 fn_800D591C(void* arg0) {
    s32 result = 0;
    if (*(u16*)((u8*)arg0 + 4) == 0xFEFF &&
        *(u16*)((u8*)arg0 + 6) == 8) {
        result = 1;
    }
    return result;
}

#pragma dont_inline fn_800D5944
extern "C" s32 fn_800D5944(void* arg0, u32 arg1) {
    s32 result = 0;
    if (arg1 == *(u32*)arg0 &&
        *(u16*)((u8*)arg0 + 4) == 0xFEFF &&
        *(u16*)((u8*)arg0 + 6) == 8) {
        result = 1;
    }
    return result;
}

extern "C" void fn_800D5978(void* arg0) {
    *(u8*)((u8*)arg0) = 0;
    *((u8*)arg0 + 1) = 0;
    *(u32*)((u8*)arg0 + 4) = 0;
}

extern "C" void fn_800D598C(void* arg0) {
    if (*(s32*)((u8*)arg0 + 4)) {
        MEMFreeToAllocator(lbl_8055DDF0, *(void**)((u8*)arg0 + 4));
        *(u32*)((u8*)arg0 + 4) = 0;
        *(u8*)((u8*)arg0) = 0;
        *((u8*)arg0 + 1) = 0;
    }
}

extern "C" s32 MEMAllocFromAllocator(s32, s32);
extern "C" const char lbl_8031F5A8[];
extern "C" const char lbl_8031F5B8[];
extern "C" const char lbl_8031F5E8[];
extern "C" void Reserve__Q46nw4hbm3lyt6detail11TexCoordAryFUc(void *arg0, u8 arg1) {
    if (arg1 > 8)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F5A8, 0x5D, lbl_8031F5B8);
    if (*(u8*)arg0 < arg1) {
        void *p = *(void**)((u8*)arg0 + 4);
        if (p != 0) {
            MEMFreeToAllocator(lbl_8055DDF0, p);
            *(void**)((u8*)arg0 + 4) = 0;
            *(u8*)arg0 = 0;
            *((u8*)arg0 + 1) = 0;
        }
        s32 newp = MEMAllocFromAllocator(lbl_8055DDF0, arg1 << 5);
        *(s32*)((u8*)arg0 + 4) = newp;
        if (newp != 0)
            *(u8*)arg0 = arg1;
    }
}

extern "C" f32 lbl_80560E68;
extern "C" f32 lbl_80560E6C;
extern "C" signed char lbl_8055DDE8;
extern "C" f32 lbl_80407E40[8];
#pragma optimize_for_size on
#pragma unroll off
extern "C" void SetSize__Q46nw4hbm3lyt6detail11TexCoordAryFUc(void *self, u8 size) {
    if (*(void **)((u8 *)self + 4) == 0)
        return;
    if (size > *(u8 *)self)
        return;
    if (lbl_8055DDE8 == 0) {
        lbl_80407E40[0] = lbl_80560E68;
        lbl_80407E40[1] = lbl_80560E68;
        lbl_80407E40[2] = lbl_80560E6C;
        lbl_80407E40[3] = lbl_80560E68;
        lbl_80407E40[4] = lbl_80560E68;
        lbl_80407E40[5] = lbl_80560E6C;
        lbl_80407E40[6] = lbl_80560E6C;
        lbl_80407E40[7] = lbl_80560E6C;
        lbl_8055DDE8 = 1;
    }
    u8 oldSize = *((u8 *)self + 1);
    f32 v7, v6, v5, v4, v3, v2, v1, v0;
    v0 = lbl_80407E40[0];
    v1 = lbl_80407E40[1];
    v2 = lbl_80407E40[2];
    v3 = lbl_80407E40[3];
    v4 = lbl_80407E40[4];
    v5 = lbl_80407E40[5];
    v6 = lbl_80407E40[6];
    v7 = lbl_80407E40[7];
    for (register s32 i = oldSize; i < size; ++i) {
        register s32 offset = i << 5;
        void *base0 = *(void **)((u8 *)self + 4);
        *(f32 *)((u8 *)base0 + offset) = v0;
        ((f32 *)((u8 *)base0 + offset))[1] = v1;
        void *base1 = *(void **)((u8 *)self + 4);
        f32 *p2 = (f32 *)((u8 *)base1 + offset);
        p2[2] = v2;
        p2[3] = v3;
        void *base2 = *(void **)((u8 *)self + 4);
        f32 *p3 = (f32 *)((u8 *)base2 + offset);
        p3[4] = v4;
        p3[5] = v5;
        void *base3 = *(void **)((u8 *)self + 4);
        f32 *p4 = (f32 *)((u8 *)base3 + offset);
        p4[6] = v6;
        p4[7] = v7;
    }
    *((u8 *)self + 1) = size;
}
#pragma unroll reset
#pragma optimize_for_size reset
extern "C" void Copy__Q46nw4hbm3lyt6detail11TexCoordAryFPCvUc(void* self, const void* src, u8 count) {
    u8* p = (u8*)self;
    if (count > p[0])
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F5A8, 0xA1, lbl_8031F5E8);
    if (p[1] < count)
        p[1] = count;
    s32 offset = 0;
    s32 n = count;
    if (n > 0) {
        do {
            void* base0 = *(void**)(p + 4);
            f32* dst0 = (f32*)((u8*)base0 + offset);
            dst0[0] = ((const f32*)src)[0];
            dst0[1] = ((const f32*)src)[1];
            void* base1 = *(void**)(p + 4);
            f32* dst1 = (f32*)((u8*)base1 + offset);
            dst1[2] = ((const f32*)src)[2];
            dst1[3] = ((const f32*)src)[3];
            src = (const u8*)src + 0x20;
            void* base2 = *(void**)(p + 4);
            f32* dst2 = (f32*)((u8*)base2 + offset);
            dst2[4] = ((const f32*)src)[-4];
            dst2[5] = ((const f32*)src)[-3];
            void* base3 = *(void**)(p + 4);
            f32* dst3 = (f32*)((u8*)base3 + offset);
            offset += 0x20;
            dst3[6] = ((const f32*)src)[-2];
            dst3[7] = ((const f32*)src)[-1];
        } while (--n != 0);
    }
}

extern "C" int IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(unsigned int *color, unsigned char alpha) {
    if (alpha != 0xff) return 1;
    if (color == 0) goto no;
    if ((color[0] + 0x10000) != 0xffff) goto yes;
    if ((color[1] + 0x10000) != 0xffff) goto yes;
    if ((color[2] + 0x10000) != 0xffff) goto yes;
    if ((color[3] + 0x10000) == 0xffff) goto no;
yes:
    return 1;
no:
    return 0;
}

#pragma push
#pragma dont_inline on
extern "C" void MultipleAlpha__Q34nw4r3lyt6detailFQ34nw4r2ut5ColorUc(void* out,void* color,u8 alpha) {
 const u8* s=(const u8*)color; u8* d=(u8*)out;
 u8 a=s[0], b=s[1], c=s[2], v=s[3];
 d[0]=a; d[1]=b; d[2]=c; d[3]=v;
 if(alpha!=0xff) d[3]=(u8)((v*alpha)/255);
}
#pragma pop

extern "C" void SetVertexFormat__Q34nw4r3lyt6detailFbUc(bool hasColor, unsigned char texCoordCount) {
    GXClearVtxDesc();
    GXSetVtxDesc((GXAttr)9, (GXAttrType)1);
    if (hasColor) GXSetVtxDesc((GXAttr)0xB, (GXAttrType)1);
    for (int i = 0; i < texCoordCount; i++) GXSetVtxDesc((GXAttr)(i + 0xD), (GXAttrType)1);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)9, (GXCompCnt)0, (GXCompType)4, (u8)0);
    if (hasColor) GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)0xB, (GXCompCnt)1, (GXCompType)5, (u8)0);
    for (int i = 0; i < texCoordCount; i++) GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)(i + 0xD), (GXCompCnt)1, (GXCompType)4, (u8)0);
}

extern "C" void DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(const void*, const void*, u8, const void*, const void*, u8);
extern "C" void MultipleAlpha__Q34nw4r3lyt6detailFQ34nw4r2ut5ColorUc(void*, void*, u8);
extern "C" void DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5Color(const void *, const void *, u8, const void *, const void *);
#pragma use_lmw_stmw off
extern "C" void DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5ColorUc(const void* pos, const void* size, u8 count, const void* texCoords, const void* colors, u8 alpha) {
    u32 adjusted[4];
    adjusted[0] = 0xffffffff;
    adjusted[1] = 0xffffffff;
    adjusted[2] = 0xffffffff;
    adjusted[3] = 0xffffffff;
    if (colors != 0) {
        int i = 0;
        const u8* src = (const u8*)colors;
        u8* dst = (u8*)adjusted;
        u8 result[4];
        u8 color[4];
        while (i < 4) {
            color[0] = src[0];
            color[1] = src[1];
            color[2] = src[2];
            color[3] = src[3];
            MultipleAlpha__Q34nw4r3lyt6detailFQ34nw4r2ut5ColorUc(result, color, alpha);
            dst[0] = result[0];
            dst[1] = result[1];
            dst[2] = result[2];
            dst[3] = result[3];
            src += 4;
            dst += 4;
            ++i;
        }
    }
    u32 mask = (u32)(-(u32)colors | (u32)colors);
    mask = (u32)((s32)mask >> 31);
    const void* out = (const void*)((u32)adjusted & mask);
    DrawQuad__Q34nw4r3lyt6detailFRCQ34nw4r4math4VEC2RCQ34nw4r3lyt4SizeUcPA4_CQ34nw4r4math4VEC2PCQ34nw4r2ut5Color(pos, size, count, texCoords, out);
}
#pragma use_lmw_stmw reset
extern "C" void* __ct__Q34nw4r3lyt8DrawInfoFv(void* arg0) {
    extern f32 lbl_80560E78;
    extern f32 lbl_80560E7C;
    extern char lbl_8031F618[];
    extern void memset(void*, int, unsigned int);
    extern void PSMTXIdentity(void*);
    u8* p = (u8*)arg0;
    f32 b = lbl_80560E7C;
    f32 a = lbl_80560E78;
    *(void**)p = lbl_8031F618;
    *(f32*)(p + 0x34) = a;
    *(f32*)(p + 0x38) = a;
    *(f32*)(p + 0x3C) = a;
    *(f32*)(p + 0x40) = a;
    *(f32*)(p + 0x44) = b;
    *(f32*)(p + 0x48) = b;
    *(f32*)(p + 0x4C) = b;
    memset(p + 0x50, 0, 1);
    PSMTXIdentity(p + 4);
    return arg0;
}

extern "C" s32 fn_800D67B8(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, s32);
extern "C" void* __dt__Q36nw4hbm3lyt5GroupFv(void* arg0, s32 arg1) {
    extern const char lbl_8031E764[];
    extern const char lbl_8031E740[];
    extern const char lbl_8031F718[];
    extern const char lbl_8031F6F4[];
    GroupLayout* group = (GroupLayout*)arg0;
    void* slot;
    register GroupListNode* current;
    register GroupListNode* node;
    register void* end;
    if (group != 0) {
        node = group->children.first;
        end = &group->children.first;
        group->vtable = lbl_8031F628;
        while (node != end) {
            current = node;
            node = node->next;
            slot = current;
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(&group->children, &slot);
            if (current == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E764, 0x23D, lbl_8031E740);
            if (current == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F718, 0x193, lbl_8031F6F4);
            MEMFreeToAllocator(lbl_8055DDF0, current);
        }
        if (&group->children != 0)
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(&group->children, 0);
        if (arg1 > 0)
            ((void (*)(void*))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void AppendGroup__Q36nw4hbm3lyt14GroupContainerFPQ36nw4hbm3lyt5Group(void* arg0, void* arg1) {
    extern const char lbl_8031F658[];
    extern const char lbl_8031F634[];
    register void* iterator = (u8*)arg0 + 4;
    void* slot;
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F658, 0x233, lbl_8031F634);
    slot = iterator;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(arg0, &slot, (u8*)arg1 + 4);
}

extern "C" void* FindGroupByName__Q36nw4hbm3lyt14GroupContainerFPCc(void* arg0, const char* arg1) {
    extern const char lbl_8031F6B8[];
    extern const char lbl_8031F694[];
    extern const char lbl_8031F688[];
    extern const char lbl_8031F664[];
    void* node = *(void**)((u8*)arg0 + 4);
    void* sentinel = (u8*)arg0 + 4;
    while (node != sentinel) {
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F6B8, 0x23D, lbl_8031F694);
        if (((int (*)(const char*, const char*))fn_800D58C4)((const char*)node + 0x14, arg1)) {
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F6B8, 0x23D, lbl_8031F694);
            void* group = (u8*)node - 4;
            if (group == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F688, 0x193, lbl_8031F664);
            return group;
        }
        node = *(void**)node;
    }
    return 0;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_800D6EEC(void* arg0) {
    extern float lbl_80560E80;
    extern char lbl_8031F868[];
    volatile u8* p = (volatile u8*)arg0;
    register u32 zero = 0;
    register void* list = (void*)(p + 8);
    f32 f = lbl_80560E80;
    void* vtable = lbl_8031F868;
    *(volatile u32*)(p + 8) = zero;
    *(volatile u32*)(p + 0xC) = zero;
    *(void* volatile*)p = vtable;
    *(volatile u32*)(p + 4) = zero;
    *(void* volatile*)(p + 8) = list;
    *(void* volatile*)(p + 0xC) = list;
    *(volatile u32*)(p + 0x10) = zero;
    *(volatile u32*)(p + 0x14) = zero;
    *(volatile f32*)(p + 0x18) = f;
    *(volatile f32*)(p + 0x1C) = f;
    *(volatile u8*)(p + 0x20) = zero;
}
#pragma pop
extern "C" void *BuildPaneObj__Q36nw4hbm3lyt6LayoutFlPCvRCQ36nw4hbm3lyt11ResBlockSet(u32, const void *, const ResBlockSetTmp *);
extern "C" void AppendChild__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt4Pane(void *, void *);
extern "C" void AppendGroup__Q36nw4hbm3lyt14GroupContainerFPQ36nw4hbm3lyt5Group(void *, void *);
extern "C" void *__ct__Q36nw4hbm3lyt5GroupFPCQ46nw4hbm3lyt3res5GroupPQ36nw4hbm3lyt4Pane(void *, const void *, void *);
#pragma push
#pragma dont_inline on
s32 nw4hbm::lyt::Layout::Build(const void *arg1, nw4hbm::lyt::ResourceAccessor *arg2) {
    ResBlockSetTmp blockSet;
    const char *msg = lbl_8031F728;
    s32 count;
    s32 depth;
    s32 groupCreated;
    void *currentParent, *lastPane, *pane, *container, *rootPane, *groupResult;
    const u8 *block;
    u16 size;
    u32 tag;
    if (lbl_8055DDF0 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(msg, 0xAB, msg + 0x10);
    if (arg1 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(msg, 0xAC, msg + 0x40);
    if (fn_800D5944((void *)arg1, 0x524C5954) == 0)
        return 0;
    size = *(const u16 *)((const u8 *)arg1 + 6);
    if (size != 8)
        Panic__Q26nw4hbm2dbFPCciPCce(msg, 0xBB, msg + 0x6C,
            (u8)(size >> 8), (u8)size, 0, 8);
    blockSet.a = 0;
    blockSet.b = 0;
    blockSet.c = 0;
    blockSet.d = (u32)arg2;
    count = 0;
    depth = 0;
    groupCreated = 0;
    currentParent = 0;
    lastPane = 0;
    block = (const u8 *)arg1 + *(const u16 *)((const u8 *)arg1 + 0xC);
    while (count < *(const u16 *)((const u8 *)arg1 + 0xE)) {
        tag = *(const u32 *)block;
        switch (tag) {
        case 0x6C797431:
            *(u8 *)((u8 *)this + 0x20) = (*(const u8 *)(block + 8) != 0);
            *(f32 *)((u8 *)this + 0x18) = *(const f32 *)(block + 0xC);
            *(f32 *)((u8 *)this + 0x1C) = *(const f32 *)(block + 0x10);
            break;
        case 0x74786C31: blockSet.a = (u32)block; break;
        case 0x666E6C31: blockSet.b = (u32)block; break;
        case 0x6D617431: blockSet.c = (u32)block; break;
        case 0x776E6431:
        case 0x74787431:
        case 0x70696331:
        case 0x70616E31:
        case 0x626E6431:
            pane = BuildPaneObj__Q36nw4hbm3lyt6LayoutFlPCvRCQ36nw4hbm3lyt11ResBlockSet(
                tag, block, &blockSet);
            if (pane != 0) {
                if (*(void **)((u8 *)this + 0x10) == 0)
                    *(void **)((u8 *)this + 0x10) = pane;
                if (currentParent != 0)
                    AppendChild__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt4Pane(currentParent, pane);
                lastPane = pane;
            }
            break;
        case 0x70617331:
            if (lastPane == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(msg, 0xF9, msg + 0x9C);
            currentParent = lastPane;
            break;
        case 0x70616531:
            lastPane = currentParent;
            currentParent = *(void **)((u8 *)currentParent + 0xC);
            break;
        case 0x67727031:
            if (groupCreated == 0) {
                groupCreated = 1;
                container = (void *)MEMAllocFromAllocator(lbl_8055DDF0, 0xC);
                if (container != 0) {
                    if (container != 0) {
                        *(void **)((u8 *)container + 4) = 0;
                        *(void **)((u8 *)container + 8) = 0;
                        *(void **)container = 0;
                        *(void **)((u8 *)container + 4) = (u8 *)container + 4;
                        *(void **)((u8 *)container + 8) = (u8 *)container + 4;
                    }
                } else {
                    Warning__Q26nw4hbm2dbFPCciPCce(msg, 0x2F, msg + 0xC8);
                    container = 0;
                }
                *(void **)((u8 *)this + 0x14) = container;
            } else if (*(void **)((u8 *)this + 0x14) != 0 && depth == 1) {
                rootPane = *(void **)((u8 *)this + 0x10);
                pane = (void *)MEMAllocFromAllocator(lbl_8055DDF0, 0x2C);
                if (pane != 0) {
                    groupResult = pane;
                    if (pane != 0) {
                        groupResult = __ct__Q36nw4hbm3lyt5GroupFPCQ46nw4hbm3lyt3res5GroupPQ36nw4hbm3lyt4Pane(
                            pane, block, rootPane);
                    }
                } else {
                    groupResult = 0;
                }
                if (groupResult != 0)
                    AppendGroup__Q36nw4hbm3lyt14GroupContainerFPQ36nw4hbm3lyt5Group(
                        *(void **)((u8 *)this + 0x14), groupResult);
            }
            break;
        case 0x67727331: depth += 1; break;
        case 0x67726531: depth -= 1; break;
        }
        ++count;
        block += *(const u32 *)(block + 4);
    }
    return 1;
}
#pragma pop
extern "C" void *CreateAnimTransform__Q36nw4hbm3lyt6LayoutFPCvPQ36nw4hbm3lyt16ResourceAccessor(void *self, const void *resource, void *accessor) {
    const char *msg=lbl_8031F728;
    int id=0x70616931;
    void *result=0;
    if (lbl_8055DDF0==0) Panic__Q26nw4hbm2dbFPCciPCce(msg,0x127,msg+0x10);
    if (resource==0) Panic__Q26nw4hbm2dbFPCciPCce(msg,0x128,msg+0xDC);
    if (fn_800D591C((void *)resource)==0) return 0;
    unsigned short count=*(unsigned short *)((char *)resource+6);
    if (count!=8) Panic__Q26nw4hbm2dbFPCciPCce(msg,0x137,msg+0x6C,count>>8,count&0xFF,0,8);
    char *block=(char *)resource+*(unsigned short *)((char *)resource+0xC);
    int i=0;
    do {
        if (*(int *)block==id) {
            int tag=*(int *)resource;
            switch(tag) {
            case 0x524C5450: case 0x524C4D43: case 0x524C414E: case 0x524C5041:
            case 0x524C5643: case 0x524C5453: case 0x524C5649: {
                void *obj=(void *)MEMAllocFromAllocator(lbl_8055DDF0,0x20);
                if (obj) obj=(void *)fn_800D4428();
                else { Warning__Q26nw4hbm2dbFPCciPCce(msg,0x2F,msg+0xC8); obj=0; }
                if (obj) {
                    ((void (*)(void *,void *,void *))(*(void ***)obj)[3])(obj,block,accessor);
                    result=obj;
                }
                break;
            }
            }
            if (result) {
                void *it=(char *)self+8;
                Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)self+4,(void **)&it,(char *)result+4);
            }
        }
        int size=*(int *)(block+4);
        block+=size;
        i++;
    } while(i<*(unsigned short *)((char *)resource+0xE));
    return result;
}
#pragma dont_inline reset
extern "C" void fn_800D7698(void *arg0, int arg1) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(int, int);
    };
    Obj* obj = *(Obj**)((char*)arg0 + 0x10);
    if (obj) obj->v15(arg1, 1);
}

extern "C" void fn_800D76BC(void *arg0, int arg1) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(int, int);
    };
    Obj* obj = *(Obj**)((char*)arg0 + 0x10);
    if (obj) obj->v16(arg1, 1);
}

extern "C" void fn_800D76E0(void *arg0) {
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(int); };
    ((Obj*)arg0)->v4(0);
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
        f32 h = *(f32*)&p[0x1C];
        f32 w = *(f32*)&p[0x18];
        f32 negH = -h;
        f32 negW = -w;
        f32 s = lbl_80560E84;
        *(f32*)&((u8*)pOut)[8] = w * s;
        *(f32*)&((u8*)pOut)[4] = h * s;
        *(f32*)&((u8*)pOut)[0] = negW * s;
        *(f32*)&((u8*)pOut)[0xC] = negH * s;
    } else {
        f32 z = lbl_80560E80;
        f32 w = *(f32*)&p[0x18];
        f32 h = *(f32*)&p[0x1C];
        *(f32*)&((u8*)pOut)[0] = z;
        *(f32*)&((u8*)pOut)[4] = z;
        *(f32*)&((u8*)pOut)[8] = w;
        *(f32*)&((u8*)pOut)[0xC] = h;
    }
}

extern "C" void fn_800D6CA0(s32, s32);
extern "C" void fn_800D77DC(void* arg0, s32 arg1, void*) {
    void* pane = *(void**)((u8*)arg0 + 0x10);
    void* state = ((PaneAnimRet*)pane)->f3();
    while (state != 0 && state != &lbl_8055DE08) state = *(void**)state;
    if (state != 0) *(s32*)((u8*)pane + 0xF4) = arg1;
    void* list = (u8*)pane + 0x14;
    for (void* node = *(void**)list; node != list; node = *(void**)node) {
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
        void* child = (u8*)node - 4;
        void* childState = ((PaneAnimRet*)child)->f3();
        while (childState != 0 && childState != &lbl_8055DE08) childState = *(void**)childState;
        if (childState != 0) *(s32*)((u8*)child + 0xF4) = arg1;
        void* sublist = (u8*)child + 0x14;
        for (void* subnode = *(void**)sublist; subnode != sublist; subnode = *(void**)subnode) {
            if (subnode == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            void* subchild = (u8*)subnode - 4;
            void* substate = ((PaneAnimRet*)subchild)->f3();
            while (substate != 0 && substate != &lbl_8055DE08) substate = *(void**)substate;
            if (substate != 0) *(s32*)((u8*)subchild + 0xF4) = arg1;
            void* subsublist = (u8*)subchild + 0x14;
            for (void* subsubnode = *(void**)subsublist; subsubnode != subsublist; subsubnode = *(void**)subsubnode) {
                if (subsubnode == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
                void* subsubchild = (u8*)subsubnode - 4;
                void* subsubstate = ((PaneAnimRet*)subsubchild)->f3();
                while (subsubstate != 0 && subsubstate != &lbl_8055DE08) subsubstate = *(void**)subsubstate;
                if (subsubstate != 0) *(s32*)((u8*)subsubchild + 0xF4) = arg1;
                void* finalList = (u8*)subsubchild + 0x14;
                for (void* finalNode = *(void**)finalList; finalNode != finalList; finalNode = *(void**)finalNode) {
                    if (finalNode == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
                    void* item = (u8*)finalNode - 4;
                    void* itemState = ((PaneAnimRet*)item)->f3();
                    while (itemState != 0 && itemState != &lbl_8055DE08) itemState = *(void**)itemState;
                    if (itemState != 0) *(s32*)((u8*)item + 0xF4) = arg1;
                    fn_800D6CA0((s32)item, arg1);
                }
            }
        }
    }
}

extern "C" void* __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(void*, const void*);
extern "C" void* __ct__Q36nw4hbm3lyt7PictureFPCQ46nw4hbm3lyt3res7PictureRCQ36nw4hbm3lyt11ResBlockSet(void*, const void*, const void*);
extern "C" void* __ct__Q36nw4hbm3lyt7TextBoxFPCQ46nw4hbm3lyt3res7TextBoxRCQ36nw4hbm3lyt11ResBlockSet(void*, const void*, const void*);
extern "C" void* __ct__Q36nw4hbm3lyt6WindowFPCQ46nw4hbm3lyt3res6WindowRCQ36nw4hbm3lyt11ResBlockSet(void*, const void*, const void*);
extern "C" void* fn_800D57AC(void*, const void*, const void*);
extern "C" const char lbl_8031F728[];
extern "C" const char lbl_8031F854[];
extern "C" void* BuildPaneObj__Q36nw4hbm3lyt6LayoutFlPCvRCQ36nw4hbm3lyt11ResBlockSet(u32 kind, const void* pane, const ResBlockSetTmp* set) {
    void* obj;
    ResBlockSetTmp tmp;
    switch (kind) {
    case 0x70616E31:
        obj = (void*)MEMAllocFromAllocator(lbl_8055DDF0, 0xD4);
        if (!obj) return 0;
        return __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(obj, pane);
    case 0x70696331:
        tmp = *set;
        obj = (void*)MEMAllocFromAllocator(lbl_8055DDF0, 0xEC);
        if (!obj) return 0;
        return __ct__Q36nw4hbm3lyt7PictureFPCQ46nw4hbm3lyt3res7PictureRCQ36nw4hbm3lyt11ResBlockSet(obj, pane, &tmp);
    case 0x74787431:
        tmp = *set;
        obj = (void*)MEMAllocFromAllocator(lbl_8055DDF0, 0x100);
        if (!obj) return 0;
        return __ct__Q36nw4hbm3lyt7TextBoxFPCQ46nw4hbm3lyt3res7TextBoxRCQ36nw4hbm3lyt11ResBlockSet(obj, pane, &tmp);
    case 0x776E6431:
        tmp = *set;
        obj = (void*)MEMAllocFromAllocator(lbl_8055DDF0, 0x104);
        if (!obj) return 0;
        return __ct__Q36nw4hbm3lyt6WindowFPCQ46nw4hbm3lyt3res6WindowRCQ36nw4hbm3lyt11ResBlockSet(obj, pane, &tmp);
    case 0x626E6431:
        tmp = *set;
        obj = (void*)MEMAllocFromAllocator(lbl_8055DDF0, 0xD4);
        if (!obj) return 0;
        return fn_800D57AC(obj, pane, &tmp);
    default:
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F728, 0x1F7, lbl_8031F854);
        return 0;
    }
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_800D7C54(int *arg0, s32 arg1) {
    volatile f32 *in = (volatile f32 *)arg1;
    f32 angle = in[2];
    volatile f32 offsets[2];
    offsets[0] = lbl_80560E88;
    offsets[1] = lbl_80560E88;
    f32 c = CosFIdx__Q24nw4r4mathFf(lbl_80560E8C * angle);
    f32 angle2 = in[2];
    f32 s = SinFIdx__Q24nw4r4mathFf(lbl_80560E8C * angle2);
    f32 x = in[3];
    f32 negS = -s;
    f32 sinX = s * x;
    f32 zero = lbl_80560E90;
    f32 cosX = c * x;
    f32 z = in[4];
    f32 negOffsetX = -offsets[0];
    f32 negOffsetY = -offsets[1];
    f32 sinZ = negS * z;
    f32 tx = in[0];
    f32 cosZ = c * z;
    f32 ty = in[1];
    f32 tx0 = tx + offsets[0];
    f32 ty0 = ty + offsets[1];
    f32 tx1 = tx0 + cosX * negOffsetX;
    f32 ty1 = ty0 + sinX * negOffsetX;
    f32 tx2 = tx1 + sinZ * negOffsetY;
    f32 ty2 = ty1 + cosZ * negOffsetY;

    ((f32 *)arg0)[0] = cosX;
    ((f32 *)arg0)[1] = sinZ;
    ((f32 *)arg0)[2] = zero;
    ((f32 *)arg0)[4] = sinX;
    ((f32 *)arg0)[5] = cosZ;
    ((f32 *)arg0)[6] = zero;
    ((f32 *)arg0)[3] = tx2;
    ((f32 *)arg0)[7] = ty2;
    ((f32 *)arg0)[8] = zero;
    ((f32 *)arg0)[9] = zero;
    ((f32 *)arg0)[10] = lbl_80560E94;
    ((f32 *)arg0)[11] = zero;
}
#pragma pop

extern "C" void GXSetIndTexMtx(f32*, s8);
extern "C" f32 lbl_80560E88;
extern "C" f32 lbl_80560E94;
extern "C" f32 lbl_80560E98;
extern "C" void fn_800D7D5C(void* arg0, f32* m) {
    f32 a=m[0], b=m[1], c=m[2], d=m[3], e=m[4], f=m[5];
    f32 aa=__fabsf(a), bb=__fabsf(b), cc=__fabsf(c), dd=__fabsf(d), ee=__fabsf(e), ff=__fabsf(f);
    s8 scale=0;
    if (aa <= lbl_80560E94 && bb <= lbl_80560E94 && cc <= lbl_80560E94 && dd <= lbl_80560E94 && ee <= lbl_80560E94 && ff <= lbl_80560E94) {
        while (scale < 0x2E && aa <= lbl_80560E94 && bb <= lbl_80560E94 && cc <= lbl_80560E94 && dd <= lbl_80560E94 && ee <= lbl_80560E94 && ff <= lbl_80560E94) {
            aa *= lbl_80560E88; a *= lbl_80560E88; b *= lbl_80560E88;
            c *= lbl_80560E88; d *= lbl_80560E88; e *= lbl_80560E88; f *= lbl_80560E88;
            bb *= lbl_80560E88; cc *= lbl_80560E88; dd *= lbl_80560E88; ee *= lbl_80560E88; ff *= lbl_80560E88;
            scale++;
        }
    } else if (aa < lbl_80560E88 && bb < lbl_80560E88 && cc < lbl_80560E88 && dd < lbl_80560E88 && ee < lbl_80560E88 && ff < lbl_80560E88) {
        do {
            aa *= lbl_80560E98; scale--; a *= lbl_80560E98; b *= lbl_80560E98;
            c *= lbl_80560E98; d *= lbl_80560E98; e *= lbl_80560E98; f *= lbl_80560E98;
            bb *= lbl_80560E98; cc *= lbl_80560E98; dd *= lbl_80560E98; ee *= lbl_80560E98; ff *= lbl_80560E98;
        } while (aa < lbl_80560E88 && bb < lbl_80560E88 && cc < lbl_80560E88 && dd < lbl_80560E88 && ee < lbl_80560E88 && ff < lbl_80560E88 && scale > -0x11);
    }
    if (scale <= -0x11) GXSetIndTexMtx(&a, scale);
}

extern "C" f32 fn_800D7F58(f32 *arg0, const f32 *arg1) {
    f32 v0 = arg1[0];
    f32 v1 = arg1[1];
    arg0[0] = v0;
    arg0[1] = v1;
    return v0;
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
    volatile s16 *src = (volatile s16 *)arg1;
    v0 = src[0];
    v1 = src[1];
    v2 = src[2];
    v3 = src[3];
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

extern "C" int fn_800D87F8(void *arg0) {
    return (*(unsigned int*)((char*)arg0 + 0x4c) >> 7) & 1;
}

extern "C" void fn_800D8804(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" s32 fn_800D8828(void *arg0) {
    return (*(u32 *)((u8 *)arg0 + 0x4C) >> 14) & 1;
}

extern "C" void fn_800D8834(u8 *arg0, u8 *arg1) {
    *arg0 = *arg1;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_800D8840(void *arg0, void *arg1) {
    register s32 v3 = *(s32 *)((u8 *)arg1 + 0xC);
    register s32 v4 = *(s32 *)((u8 *)arg1 + 4);
    f32 v2 = *(f32 *)((u8 *)arg1 + 8);
    register s32 v1 = *(s32 *)arg1;
    register s32 v0 = *(s32 *)((u8 *)arg1 + 0x10);
    *(s32 *)arg0 = v1;
    *(s32 *)((u8 *)arg0 + 4) = v4;
    *(f32 *)((u8 *)arg0 + 8) = v2;
    *(s32 *)((u8 *)arg0 + 0xC) = v3;
    *(s32 *)((u8 *)arg0 + 0x10) = v0;
}
#pragma pop
extern "C" void fn_800D886C(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void __as__Q34nw4r3lyt8TevStageFRCQ34nw4r3lyt8TevStage(void *arg0, const void *arg1) {
    u8 *dst = (u8 *)arg0;
    const u8 *src = (const u8 *)arg1;
    dst[8] = src[8];
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[9] = src[9];
    dst[0xA] = src[0xA];
    dst[0xB] = src[0xB];
    dst[0xC] = src[0xC];
    dst[0xD] = src[0xD];
    dst[0xE] = src[0xE];
    dst[0xF] = src[0xF];
}
#pragma pop
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

extern "C" void Init__Q34nw4r3lyt8MaterialFv(void *arg0) {
    volatile short *defaults = (volatile short *)&lbl_80565230;
    short c0 = defaults[0];
    short c1 = defaults[1];
    short c2 = defaults[2];
    short c3 = defaults[3];
    unsigned int mask4c = *(unsigned int *)((char *)arg0 + 0x4c) & 0x1f;
    unsigned int mask50 = *(unsigned int *)((char *)arg0 + 0x50) & 0x1f;
    *(short *)((char *)arg0 + 0x24) = c0;
    *(short *)((char *)arg0 + 0x26) = c1;
    *(short *)((char *)arg0 + 0x28) = c2;
    *(short *)((char *)arg0 + 0x2a) = c3;
    *(short *)((char *)arg0 + 0x2c) = 0xff;
    *(short *)((char *)arg0 + 0x2e) = 0xff;
    *(short *)((char *)arg0 + 0x30) = 0xff;
    *(short *)((char *)arg0 + 0x32) = 0xff;
    *(short *)((char *)arg0 + 0x34) = 0xff;
    *(short *)((char *)arg0 + 0x36) = 0xff;
    *(short *)((char *)arg0 + 0x38) = 0xff;
    *(short *)((char *)arg0 + 0x3a) = 0xff;
    *(unsigned int *)((char *)arg0 + 0x4c) = mask4c;
    *(unsigned int *)((char *)arg0 + 0x50) = mask50;
    *(unsigned char *)((char *)arg0 + 0x54) = 0;
    *(unsigned int *)((char *)arg0 + 0x58) = 0;
}

extern "C" void fn_8002F634(void *, void *, s32, s32);
extern "C" void fn_800D2DD4(void);
extern "C" s32 fn_80128668(void);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, s32);
extern "C" void *__dt__Q34nw4r3lyt8MaterialFv(void *self, s32 shouldDelete) {
    extern char lbl_8031FF08[];
    struct Obj {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
    };
    register void *data;

    if (self != 0) {
        *(char **)self = lbl_8031FF08;
        ((Obj *)self)->d4();
        data = *(void **)((u8 *)self + 0x58);
        if (data != 0) {
            MEMFreeToAllocator(lbl_8055DDF0, data);
            *(void **)((u8 *)self + 0x58) = 0;
        }
        fn_8002F634((u8 *)self + 0x3C, (void *)fn_800D2DD4, 4, 4);
        if ((u8 *)self + 0x18 != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 0x18, 0);
        }
        if (shouldDelete > 0) {
            ((void (*)(void *))fn_80128668)(self);
        }
    }
    return self;
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
    u32 n = (x >> 0x18) & 0xF;
    u32 b = (x >> 0x17) & 0x1E0;
    return b + (y + n * 0x14);
}

extern "C" s32 fn_800D9364(void *arg0) {
    u32 x = *(u32 *)((u8 *)arg0 + 0x4C);
    u32 a = ((x >> 0x12) & 0x3C);
    u32 b = ((x >> 0x17) & 0x1E0);
    u32 c = ((x >> 0x18) & 0xF);
    s32 y = *(s32 *)((u8 *)arg0 + 0x58);
    return a + b + y + c * 0x14;
}

extern "C" s32 fn_800D938C(void* arg0) {
    s32 bits = *(s32*)((u8*)arg0 + 0x4C);
    s32 base = *(s32*)((u8*)arg0 + 0x58);
    s32 high = (bits >> 24) & 0xF;
    s32 mid = (bits >> 18) & 0x3C;
    s32 scaled = high * 0x14;
    s32 top = (bits >> 23) & 0x1E0;
    s32 low = (bits >> 6) & 4;
    mid += top;
    scaled += low;
    mid += base;
    return scaled + mid;
}

extern "C" s32 fn_800D93BC(void *arg0) {
    u32 x = *(u32 *)((u8 *)arg0 + 0x4C);
    s32 y = *(s32 *)((u8 *)arg0 + 0x58);
    s32 a = (x >> 5) & 4;
    s32 b = (x >> 6) & 4;
    s32 c = (x >> 0x12) & 0x3C;
    s32 d = (x >> 0x17) & 0x1E0;
    return (((x >> 0x18) & 0xF) * 0x14) + ((a + b) + c) + (d + y);
}

extern "C" s32 fn_800D93F4(void *arg0) {
    u32 x = *(u32 *)((u8 *)arg0 + 0x4C);
    s32 y = *(s32 *)((u8 *)arg0 + 0x58);
    return (((((x >> 12) & 4) + ((x >> 5) & 4) + ((x >> 6) & 4) + y)
             + (((x >> 24) & 0xF) * 0x14))
            + ((x >> 18) & 0x3C))
           + ((x >> 23) & 0x1E0);
}

extern "C" s32 fn_800D9434(void *arg0) {
    u32 x = *(u32 *)((u8 *)arg0 + 0x4C);
    s32 y = *(s32 *)((u8 *)arg0 + 0x58);
    s32 a = (x >> 0x14) & 0x3C0;
    s32 b = (x >> 0x17) & 0x1E0;
    s32 c = (x >> 0x18) & 1;
    s32 d = (x >> 0x18) & 0x10;
    s32 e = (x >> 0x12) & 0x3C;
    s32 f = (x >> 4) & 4;
    s32 g = (x >> 5) & 4;
    s32 h = (x >> 6) & 4;
    return a + b + c + d + y + e + f + g + h + (((x >> 0x18) & 0xF) * 0x14);
}

extern "C" s32 fn_800D947C(void* arg0) {
    register s32 x = *(s32*)((u8*)arg0 + 0x4C);
    register s32 base = *(s32*)((u8*)arg0 + 0x58);
    register s32 high = (x >> 24) & 0xF;
    register s32 low1 = (x >> 4) & 4;
    register s32 scaled = high * 0x14;
    register s32 low2 = (x >> 6) & 4;
    register s32 low3 = (x >> 12) & 4;
    register s32 low4 = (x >> 5) & 4;
    register s32 mid = (x >> 18) & 0x3C;
    register s32 top = (x >> 23) & 0x1E0;
    top = mid + top;
    low4 = low3 + low4;
    low1 = low1 + low2;
    register s32 low5 = (x >> 3) & 4;
    low4 = low4 + low1;
    top = scaled + top;
    low4 = low5 + low4;
    top = base + top;
    return low4 + top;
}

extern "C" s32 GetIndTexSRTAry__Q36nw4hbm3lyt8MaterialFv(void *arg0) {
    u32 temp_r9 = *(u32*)((u8*)arg0 + 0x4C);
    return ((temp_r9 >> 0xC) & 4) + ((temp_r9 >> 5U) & 4) +
           (((temp_r9 >> 4U) & 4) + ((temp_r9 >> 6U) & 4)) +
           ((((temp_r9 >> 0x18U) & 0xF) * 0x14) +
            (((temp_r9 >> 0x12U) & 0x3C) + ((temp_r9 >> 0x17U) & 0x1E0))) +
           (*(s32*)((u8*)arg0 + 0x58) +
            (((temp_r9 >> 0xD) & 0x1C) + ((temp_r9 >> 3U) & 4)));
}

#pragma push
#pragma scheduling invalid_target
extern "C" s32 fn_800D9524(void* arg0) {
    u32 x = *(u32*)((u8*)arg0 + 0x4C);
    s32 base = *(s32*)((u8*)arg0 + 0x58);
    u32 a = (x >> 18) & 3;
    u32 b = (x >> 24) & 0xF;
    u32 c = (x >> 6) & 4;
    u32 d = (x >> 5) & 4;
    u32 e = (x >> 12) & 4;
    u32 f = (x >> 23) & 0x1E0;
    u32 g = (x >> 18) & 0x3C;
    u32 h = (x >> 4) & 4;
    u32 i = (x >> 3) & 4;
    u32 j = (x >> 13) & 0x1C;
    return (((a + b) * 0x14) + c) +
           ((d + e) + ((h + i) + j)) +
           (base + (f + g));
}
#pragma pop
extern "C" char* strncpy(char*, const char*, unsigned int);
extern "C" char* fn_800D9584(char* arg0, const char* arg1) {
    return strncpy(arg0 + 4, arg1, 0x14);
}

extern "C" void SetTextureNum__Q36nw4hbm3lyt8MaterialFUc(void *arg0, u8 arg1) {
    extern const char lbl_8031F990[];
    extern void memset(void *, int, unsigned int);
    const char *data = lbl_8031F990;
    u32 capacity = *(u32 *)((u8 *)arg0 + 0x4C) >> 28;
    if ((u32)arg1 > capacity)
        Panic__Q26nw4hbm2dbFPCciPCce(&data[0], 0x38B, data + 0x330);
    if (arg1 == 0)
        return;
    if (*(u32 *)((u8 *)arg0 + 0x58) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&data[0], 0x38E, data + 0x360);
    u32 packed = *(u32 *)((u8 *)arg0 + 0x50);
    u8 *texture = (u8 *)*(void **)((u8 *)arg0 + 0x58) + ((packed >> 23) & 0x1E0);
    u32 index = packed >> 28;
    while (index < arg1) {
        memset(texture, 0, 0x20);
        texture += 0x20;
        index++;
    }
    struct TextureCountWord {
        u32 count : 4;
        u32 rest : 28;
    };
    ((TextureCountWord *)((u8 *)arg0 + 0x50))->count = arg1;
}

extern "C" const char lbl_8031F990[];
extern "C" void SetTexCoordGenNum__Q36nw4hbm3lyt8MaterialFUc(void* self, unsigned char count) {
    u32* p = (u32*)self;
    unsigned int max = (p[0x4C / 4] >> 20) & 15;
    if (count > max)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990, 0x39c, lbl_8031F990 + 0x38c);
    if (count != 0) {
        if (p[0x58 / 4] == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990, 0x39f, lbl_8031F990 + 0x360);
        u32 raw = p[0x4c / 4];
        u8* dst = (u8*)(p[0x58 / 4] + (((raw >> 23) & 0x1e0) + (((raw >> 24) & 15) * 20)));
        unsigned int old = (p[0x50 / 4] >> 20) & 15;
        if (old < count) {
            if (count - old > 8) {
                unsigned int limit = count - 8;
                while (old < limit) {
                    for (int j = 0; j < 8; j++) {
                        dst[old * 4 + j * 4] = 1;
                        dst[old * 4 + j * 4 + 1] = 4;
                        dst[old * 4 + j * 4 + 2] = 0x3c;
                        dst[old * 4 + j * 4 + 3] = 0;
                    }
                    old += 8;
                }
            }
            while (old < count) {
                dst[old * 4] = 1;
                dst[old * 4 + 1] = 4;
                dst[old * 4 + 2] = 0x3c;
                dst[old * 4 + 3] = 0;
                old++;
            }
        }
        p[0x50 / 4] = (p[0x50 / 4] & ~0x00f00000) | ((u32)count << 20);
    }
}

extern "C" void fn_800D9844(void* arg0, u32 arg1, s32 arg2) {
    u32 format = *(u32*)((u8*)arg0 + 0x4C);
    if (arg1 > ((format >> 9) & 0x1F))
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990, 0x3AD, lbl_8031F990 + 0x3C4);
    if (arg1 != 0) {
        if (*(void**)((u8*)arg0 + 0x58) == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990, 0x3B0, lbl_8031F990 + 0x360);
        u32 pitch = ((((format >> 18) & 3) + ((format >> 4) & 0xF)) * 0x14)
            + ((format >> 6) & 4) + ((format >> 22) & 0x3C)
            + ((format >> 20) & 4) + ((format >> 27) & 4)
            + ((format >> 29) & 4) + ((format >> 28) & 4)
            + ((format >> 26) & 4) + ((format >> 25) & 4)
            + ((format >> 3) & 4) + ((format >> 12) & 4);
        u32 count = (*(u32*)((u8*)arg0 + 0x50) >> 9) & 0x1F;
        u8* dst = (u8*)*(u8**)((u8*)arg0 + 0x58) + pitch + count * 0x10;
        if (count < arg1) {
            u8 pattern[16] = {0xFF,4,0xFF,0, 0xFF,0xAF,0,0x61,0x77,0x57,0,0x81,0,0,0,0};
            u32 remaining = arg1 - count;
            while (remaining--) {
                for (u32 i=0;i<16;i++) dst[i]=pattern[i];
                dst += 0x10;
            }
        }
        *(u32*)((u8*)arg0 + 0x50) = (*(u32*)((u8*)arg0 + 0x50) & ~0x3E00) | ((arg1 << 9) & 0x3E00);
    }
}

extern "C" void fn_800D9ACC(void* arg0, u32 arg1) {
    u8* p = (u8*)arg0;
    u32 fmt = *(u32*)(p + 0x4C);
    u32 count = (*(u32*)(p + 0x50) >> 15) & 7;
    if (arg1 > ((fmt >> 15) & 7))
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990, 0x3BE, lbl_8031F990 + 0x3F8);
    if (arg1 != 0) {
        if (*(void**)(p + 0x58) == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990, 0x3C1, lbl_8031F990 + 0x360);
        u32 width = (fmt >> 24) & 15;
        u8* base = (u8*)*(void**)(p + 0x58) + width * 0x14 + ((fmt >> 18) & 0x3C) + ((fmt >> 23) & 0x1E0);
        base += ((fmt >> 4) & 4) + ((fmt >> 6) & 4) + ((fmt >> 12) & 4) + ((fmt >> 5) & 4) + ((fmt >> 3) & 4);
        if (count < arg1) {
            u32 i = count;
            for (; i < arg1; i++)
                *(u32*)(base + i * 4) = 0;
        }
        *(u32*)(p + 0x50) = (*(u32*)(p + 0x50) & ~0x38000) | ((arg1 << 15) & 0x38000);
    }
}

extern "C" void InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(void*, void*, u32);
extern "C" void fn_800D9CBC(void* arg0, u32 arg1, void* arg2) {
    extern const char lbl_8031F990[];
    extern const char lbl_8031FDE8[];
    if (arg1 >= (*(u32*)((u8*)arg0 + 0x50) >> 28))
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990, 0x3f2, lbl_8031FDE8);
    InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl((u8*)*(void**)((u8*)arg0 + 0x58) + ((arg1 & 0xff) << 5), arg2, 0);
}

extern "C" s32 GXGetTexObjLODAll(void*);
extern "C" s32 GXGetTexObjWrap_Internal(void*);
extern "C" void GXInitTexObjWrapMode(void*,s32,s32);
extern "C" void InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(void*,void*,u32);
extern "C" void SetTextureNoWrap__Q36nw4hbm3lyt8MaterialFUcP10TPLPalette(void* self,u8 index,void* palette) {
 extern const char lbl_8031F990[]; extern const char lbl_8031FDE8[];
 u32 count=*(u32*)((char*)self+0x50)>>28;
 if(index>=count) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990,0x409,lbl_8031FDE8);
 void* dst=(u8*)*(void**)((char*)self+0x58)+((u32)index<<5);
 s32 lod=GXGetTexObjLODAll(dst);
 s32 wrap=GXGetTexObjWrap_Internal(dst);
 InitGXTexObjFromTPL__Q36nw4hbm3lyt6detailFP9_GXTexObjP10TPLPaletteUl(dst,palette,0);
 GXInitTexObjWrapMode(dst,lod,wrap);
}

extern "C" void GXGetTexObjWidth(void*, int, int);
extern "C" void SetTexture__Q36nw4hbm3lyt8MaterialFUcRC9_GXTexObj(void* self, u8 index, const void* tex) {
    extern const char lbl_8031F990[];
    extern const char lbl_8031FDE8[];
    u32 count = *(u32*)((char*)self + 0x50) >> 28;
    if (index >= count) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F990, 0x425, lbl_8031FDE8);
    void* dst = *(void**)((char*)self + 0x58);
    dst = (char*)dst + ((u32)index << 5);
    for (int i=0;i<8;i++) ((u32*)dst)[i] = ((const u32*)tex)[i];
    GXGetTexObjWidth(dst, 0, 0);
}

extern "C" void SetColorElement__Q36nw4hbm3lyt8MaterialFUls(void *arg0, s32 arg1, s16 arg2) {
    u32 flags;
    u32 info;
    u32 component;
    u32 index;
    u8 *base;
    if (arg1 < 0x10) {
        if (arg1 >= 4) {
            arg1 -= 4;
            component = arg1 & 3;
            index = (u32)arg1 >> 2;
            switch (component) {
            case 0: *(s16 *)((u8 *)arg0 + index * 8 + 0x24) = arg2; return;
            case 1: *(s16 *)((u8 *)arg0 + index * 8 + 0x26) = arg2; return;
            case 2: *(s16 *)((u8 *)arg0 + index * 8 + 0x28) = arg2; return;
            case 3: *(s16 *)((u8 *)arg0 + index * 8 + 0x2A) = arg2; return;
            }
        }
        if (arg1 < 0) return;
        flags = *(u32 *)((u8 *)arg0 + 0x50);
        if (((flags >> 7) & 1) < 1) return;
        info = *(u32 *)((u8 *)arg0 + 0x4C);
        base = (u8 *)*(s32 *)((u8 *)arg0 + 0x58)
            + ((info >> 6) & 4) + ((info >> 24) & 0xF) * 0x14
            + ((info >> 18) & 0x3C) + ((info >> 23) & 0x1E0);
        {
            s32 value = arg2 & ~(arg2 >> 31);
            s32 byte = 0xFF;
            if (value <= 0xFF) byte = value;
            byte &= 0xFF;
            switch (arg1 & 3) {
            case 0: base[0] = byte; return;
            case 1: base[1] = byte; return;
            case 2: base[2] = byte; return;
            case 3: base[3] = byte; return;
            }
        }
        return;
    }
    if (arg1 >= 0x20) return;
    {
        s32 value = arg2 & ~(arg2 >> 31);
        s32 byte = 0xFF;
        if (value <= 0xFF) byte = value;
        index = (arg1 - 0x10) >> 2;
        component = (arg1 - 0x10) & 3;
        switch (component) {
        case 0: *((u8 *)arg0 + index * 4 + 0x3C) = byte; return;
        case 1: *((u8 *)arg0 + index * 4 + 0x3D) = byte; return;
        case 2: *((u8 *)arg0 + index * 4 + 0x3E) = byte; return;
        case 3: *((u8 *)arg0 + index * 4 + 0x3F) = byte; return;
        }
    }
}

#pragma inline_max_size 10000
#pragma inline_max_total_size 10000
extern "C" s32 fn_800DA094(void *arg0, register s32 arg1, register u8 arg2) {
                          register const char *data = lbl_8031F990;
                          float matrix[3][4];
                          struct Fn800DA094TexObj { s32 fields[8]; };
                        Fn800DA094TexObj texture;
                          float indirectMatrix[6];
                          u8 texMatrices[10];
                          int palette[3];
                          u16 tev1[4];
                          u16 tev2[4];
                          u16 tev3[4];
                  s32 sp30;
                  u8 usedIndirect[3];
                  s32 sp28;
                          u8 alphaColor[4];
                          u8 channelColor[4];
                          u8 constant0[4];
                          u8 constant1[4];
                          u8 constant2[4];
                          u8 constant3[4];
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                             
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          s32 spC;
                          s32 sp8;
                          f32 temp_f1;
                          f32 temp_f2;
                          f32 temp_f30;
                          f32 temp_f31;
                          s32 *var_r21_3;
                          s32 *var_r22_2;
               register s32 var_r26;
               register s32 var_r21;
           register s32 var_r21_2;
                          s32 temp_cr0_eq;
                          s32 temp_r0;
                          s32 temp_r0_2;
                          s32 temp_r21;
                          s32 temp_r21_2;
                          s32 temp_r3_3;
                          s32 temp_r3_7;
                          s32 temp_r3_9;
                          s32 temp_r4;
                          s32 temp_r6;
                          s32 temp_r8_2;
                          register s32 var_r23_3;
                          s32 var_r23_5;
                          s32 var_r24;
                          register s32 var_r25;
                          s32 var_r27_2;
                          s32 var_r3;
                          s32 var_r3_2;
                          s32 var_r4;
                          s32 var_r5;
                          s32 var_r7;
                          u16 temp_r5_2;
                          u16 temp_r5_3;
                          u16 temp_r5_4;
                          u32 temp_r0_10;
                          u32 temp_r0_4;
                          u32 temp_r3;
                          u32 temp_r3_4;
                          u32 temp_r3_8;
                          u32 temp_r5;
                          u32 temp_r7;
                          u32 temp_r8;
                          u32 temp_r9;
                          u32 temp_r9_3;
                          u32 temp_r9_4;
                          u32 var_r23;
                          register u32 var_r23_6;
                          register u32 var_r23_7;
                          register u32 var_r24_2;
                          u8 *var_r23_4;
                          u8 *var_r28_3;
                          u8 temp_r0_12;
                          u8 temp_r0_3;
                          u8 temp_r0_5;
                          u8 temp_r0_6;
                          u8 temp_r0_7;
                          u8 temp_r0_8;
                          u8 temp_r0_9;
                          u8 temp_r10;
                          u8 temp_r28;
                          u8 temp_r3_2;
                          u8 temp_r3_6;
                          u8 temp_r5_5;
                          u8 temp_r5_6;
                          u8 temp_r6_3;
                          u8 temp_r6_4;
                          u8 temp_r6_5;
                          u8 temp_r9_2;
                          u8 var_r22_3;
                          u8 var_r23_2;
                          u8 var_r24_3;
                          u8 var_r24_4;
                          u32 var_r28_2;
                          u32 temp_r0_11;
                          u32 temp_r0_13;
                          u32 temp_r22;
                          u32 temp_r3_5;
                          u32 temp_r6_2;
                          u32 temp_r6_6;
                          u32 temp_r6_7;
                          u32 temp_r7_2;
                          register u8 *var_r21_4;
                          register u8 *var_r21_5;
                          register u8 *var_r22;
                          u32 var_r27;
          Fn800DA094TexObj *var_r28;
                      
                          var_r26 = 1;
                          var_r21 = 0;
                          GXSetNumChans(1);
                          temp_r3 = M2C_FIELD(arg0, u32 *, 0x4C);
                          if ((temp_r3 >> 8U) & 1) {
                              temp_r6 = ((temp_r3 >> 0x12U) & 0x3C) + ((temp_r3 >> 0x17U) & 0x1E0);
                              temp_r0 = M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r3 >> 0x18U) & 0xF) * 0x14);
                              temp_r22 = temp_r6 + temp_r0;
                              GXSetChanCtrl(0, 0, 0, *(u8 *)(temp_r6 + temp_r0), 0, 0, 2);
                              GXSetChanCtrl(2, 0, 0, M2C_FIELD(temp_r22, u8 *, 1), 0, 0, 2);
                              temp_r3_2 = M2C_FIELD(temp_r22, u8 *, 0);
                              var_r26 = 1;
                              if (((s32) temp_r3_2 != 1) && ((s32) M2C_FIELD(temp_r22, u8 *, 1) != 1)) {
                                  var_r26 = 0;
                              }
                              var_r21 = 0;
                              if (((s32) temp_r3_2 == 0) || ((s32) M2C_FIELD(temp_r22, u8 *, 1) == 0)) {
                                  var_r21 = 1;
                              }
                          } else {
                              GXSetChanCtrl(4, 0, 0, 1U, 0, 0, 2);
                          }
                          var_r25 = 0;
                          if (var_r26 != 0) {
                              var_r25 = 1;
                              if (arg1 == 0) {
                                  var_r25 = 0;
                              }
                          }
                          if (var_r21 != 0) {
                              temp_r5 = M2C_FIELD(arg0, u32 *, 0x4C);
                              sp30 = -1;
                              if ((temp_r5 >> 7U) & 1) {
                                  temp_r3_3 = ((temp_r5 >> 6U) & 4) + (((temp_r5 >> 0x18U) & 0xF) * 0x14);
                                  temp_r0_2 = M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r5 >> 0x12U) & 0x3C) + ((temp_r5 >> 0x17U) & 0x1E0));
                                  temp_r6_2 = temp_r3_3 + temp_r0_2;
                                  ((u8 *)&sp30)[0] = *(u8 *)(temp_r3_3 + temp_r0_2);
                                  ((u8 *)&sp30)[1] = M2C_FIELD(temp_r6_2, u8 *, 1);
                                  ((u8 *)&sp30)[2] = M2C_FIELD(temp_r6_2, u8 *, 2);
                                  ((u8 *)&sp30)[3] = M2C_FIELD(temp_r6_2, u8 *, 3);
                              }
                              sp28 = (s32) sp30;
                              ((void (*)(void *, void *, s32))MultipleAlpha__Q34nw4r3lyt6detailFQ34nw4r2ut5ColorUc)(&alphaColor[0], &sp28, arg2);
                              ((u8 *)&sp30)[0] = alphaColor[0];
                              ((u8 *)&sp30)[1] = alphaColor[1];
                              ((u8 *)&sp30)[2] = alphaColor[2];
                              ((u8 *)&sp30)[3] = alphaColor[3];
                              channelColor[0] = alphaColor[0];
                              channelColor[1] = alphaColor[1];
                              channelColor[2] = alphaColor[2];
                              channelColor[3] = alphaColor[3];
                              ((int (*)(int, u8 *))GXSetChanMatColor_Internal)(4, &channelColor[0]);
                            {
                                s32 wasEnabled = var_r25;
                                var_r25 = 0;
                                if (wasEnabled != 0) goto alpha_done;
                                if ((u32)((u32)sp30 + 0x10000) == 0xFFFFU) goto alpha_done;
                                var_r25 = 1;
                            alpha_done:;
                            }
                          }
                          var_r24 = 0;
                          texMatrices[0] = 0;
                          texMatrices[1] = 0;
                          texMatrices[2] = 0;
                          texMatrices[3] = 0;
                          texMatrices[4] = 0;
                          texMatrices[5] = 0;
                          texMatrices[6] = 0;
                          texMatrices[7] = 0;
                          texMatrices[8] = 0;
                          texMatrices[9] = 0;
                          GXSetNumTexGens(((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x14U) & 0xF);
                          if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x14U) & 0xF) {
                              temp_r3_4 = M2C_FIELD(arg0, u32 *, 0x4C);
                              var_r23 = 0U;
                              var_r27 = ((temp_r3_4 >> 0x17U) & 0x1E0) + (M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r3_4 >> 0x18U) & 0xF) * 0x14));
                      loop_30:
                  goto loop_30_test;
                  loop_30_body:
                                  if ((s32) M2C_FIELD(var_r27, u8 *, 0) == 0) {
                                      Panic__Q26nw4hbm2dbFPCciPCce(data, 0x508, data + 0x4D0);
                                  }
                                  temp_r28 = M2C_FIELD(var_r27, u8 *, 2);
                                  if ((s32) M2C_FIELD(var_r27, u8 *, 0) == 1) {
                                      var_r4 = 0;
                                      if ((temp_r28 == 0x3C) || ((u32) (((u32)temp_r28 - 0x1EU) / 3U) < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x18U) & 0xF))) {
                                          var_r4 = 1;
                                      }
                                      if (var_r4 == 0) {
                                          Panic__Q26nw4hbm2dbFPCciPCce(data, 0x50E, data + 0x518);
                                      }
                                      if (temp_r28 != 0x3C) {
                                          var_r24 = 1;
                                          (&texMatrices[0])[((u32)temp_r28 - 0x1EU) / 3U] = 1;
                                      }
                                  }
                                  GXSetTexCoordGen2((GXTexCoordID)var_r23, (GXTexGenType)M2C_FIELD(var_r27, u8 *, 0), (GXTexGenSrc)M2C_FIELD(var_r27, u8 *, 1), temp_r28, 0, 0x7D);
                                  var_r27 += 4;
                                  var_r23 += 1;
  
                              
                  loop_30_test:
                      if (var_r23 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x14U) & 0xF)) goto loop_30_body;
                          }
                          if (var_r24 != 0) {
                     var_r23_2 = 0;
                     temp_r21 = M2C_FIELD(arg0, u32 *, 0x58) + (((u32) M2C_FIELD(arg0, u32 *, 0x4C) >> 0x17U) & 0x1E0);
                     goto loop_36_check;
                 loop_36_body:
                     if ((s32) (&texMatrices[0])[(u8)var_r23_2] != 0) {
                         fn_800D7C54((int *)matrix, temp_r21 + (var_r23_2 * 0x14));
                         GXLoadTexMtxImm((int *)matrix, (((var_r23_2 * 4) & 0x3FC) - var_r23_2) + 0x1E, 1);
                     }
                     var_r23_2 += 1;
                 loop_36_check:
                     if (var_r23_2 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x18U) & 0xF)) {
                         goto loop_36_body;
                     }
                 }
                          if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1CU) != 0) {
                              var_r28 = (Fn800DA094TexObj *)M2C_FIELD(arg0, u32 *, 0x58);
                              var_r23_3 = 0;
                              var_r24_2 = 0U;
                      loop_43:
                goto loop_43_test;
                loop_43_body:
                                  texture = *(struct Fn800DA094TexObj *)var_r28;
                                  if ((u32) (((s32 (*)(s32 *))GXGetTexObjMipMap)(&texture.fields[0]) - 8) <= 1U) {
                                      temp_r3_5 = (u32)GXGetTexObjHeight(&texture.fields[0]);
                                      if (temp_r3_5 != 0) {
                                          GXInitTlutObj(&palette[0], M2C_FIELD(temp_r3_5, s32 *, 8), M2C_FIELD(temp_r3_5, s32 *, 4), M2C_FIELD(temp_r3_5, u16 *, 0));
                                          GXLoadTlut(&palette[0], var_r23_3);
                                          GXInitTexObjTlut(&texture.fields[0], var_r23_3);
                                          var_r23_3 += 1;
                                      }
                                  }
                                  GXLoadTexObj(&texture.fields[0], var_r24_2);
                                  var_r28 += 1;
                                  var_r24_2 += 1;

                              
                loop_43_test:
                    if (var_r24_2 < (u32) ((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1CU)) goto loop_43_body;
                          }
                          u16 color1a = M2C_FIELD(arg0, volatile u16 *, 0x24);
                          u16 color1b = M2C_FIELD(arg0, volatile u16 *, 0x26);
                          tev1[0] = color1a;
                          tev1[1] = color1b;
                          u16 color1c = M2C_FIELD(arg0, volatile u16 *, 0x28);
                          u16 color1d = M2C_FIELD(arg0, volatile u16 *, 0x2A);
                          tev1[2] = color1c;
                          tev1[3] = color1d;
                          ((int (*)(int, u16 *))GXSetTevColorS10)(1, (u16 *)&tev1[0]);
                          u16 color2a = M2C_FIELD(arg0, volatile u16 *, 0x2C);
                          u16 color2b = M2C_FIELD(arg0, volatile u16 *, 0x2E);
                          tev2[0] = color2a;
                          tev2[1] = color2b;
                          u16 color2c = M2C_FIELD(arg0, volatile u16 *, 0x30);
                          u16 color2d = M2C_FIELD(arg0, volatile u16 *, 0x32);
                          tev2[2] = color2c;
                          tev2[3] = color2d;
                          ((int (*)(int, u16 *))GXSetTevColorS10)(2, (u16 *)&tev2[0]);
                          u16 color3a = M2C_FIELD(arg0, volatile u16 *, 0x34);
                          u16 color3b = M2C_FIELD(arg0, volatile u16 *, 0x36);
                          tev3[0] = color3a;
                          tev3[1] = color3b;
                          u16 color3c = M2C_FIELD(arg0, volatile u16 *, 0x38);
                          u16 color3d = M2C_FIELD(arg0, volatile u16 *, 0x3A);
                          tev3[2] = color3c;
                          tev3[3] = color3d;
                          ((int (*)(int, u16 *))GXSetTevColorS10)(3, (u16 *)&tev3[0]);
                          constant0[0] = M2C_FIELD(arg0, u8 *, 0x3C);
                          constant0[1] = M2C_FIELD(arg0, u8 *, 0x3D);
                          constant0[2] = M2C_FIELD(arg0, u8 *, 0x3E);
                          constant0[3] = M2C_FIELD(arg0, u8 *, 0x3F);
                          GXSetTevKColor(0, &constant0[0]);
                          constant1[0] = M2C_FIELD(arg0, u8 *, 0x40);
                          constant1[1] = M2C_FIELD(arg0, u8 *, 0x41);
                          constant1[2] = M2C_FIELD(arg0, u8 *, 0x42);
                          constant1[3] = M2C_FIELD(arg0, u8 *, 0x43);
                          GXSetTevKColor(1, &constant1[0]);
                          constant2[0] = M2C_FIELD(arg0, u8 *, 0x44);
                          constant2[1] = M2C_FIELD(arg0, u8 *, 0x45);
                          constant2[2] = M2C_FIELD(arg0, u8 *, 0x46);
                          constant2[3] = M2C_FIELD(arg0, u8 *, 0x47);
                          GXSetTevKColor(2, &constant2[0]);
                          constant3[0] = M2C_FIELD(arg0, u8 *, 0x48);
                          constant3[1] = M2C_FIELD(arg0, u8 *, 0x49);
                          constant3[2] = M2C_FIELD(arg0, u8 *, 0x4A);
                          constant3[3] = M2C_FIELD(arg0, u8 *, 0x4B);
                          GXSetTevKColor(3, &constant3[0]);
                          temp_r8 = M2C_FIELD(arg0, u32 *, 0x4C);
                          if ((temp_r8 >> 0xEU) & 1) {
        {
                            u32 count = (temp_r8 >> 0x18U) & 0xF;
                            u32 offsetA = (temp_r8 >> 0x12U) & 0x3C;
                            u32 offsetB = (temp_r8 >> 0x17U) & 0x1E0;
                            u32 groupA = (temp_r8 >> 5U) & 4;
                            u32 groupB = (temp_r8 >> 6U) & 4;
                            u32 base = M2C_FIELD(arg0, u32 *, 0x58);
                            u32 left = count * 0x14 + (offsetA + offsetB);
                            u32 right = base + (groupA + groupB);
                            var_r21_2 = 0;
                            var_r23_4 = (u8 *)(left + right);
                        }
                              do {
                                  temp_r0_3 = *var_r23_4;
                                  GXSetTevSwapModeTable(var_r21_2, temp_r0_3 & 3, (temp_r0_3 >> 2U) & 3, (temp_r0_3 >> 4U) & 3, (temp_r0_3 >> 6U) & 3);
                                  var_r21_2 += 1;
                                  var_r23_4 += 1;
                              } while (var_r21_2 < 4);
                          } else {
                              GXSetTevSwapModeTable(0, 0, 1, 2, 3);
                              GXSetTevSwapModeTable(1, 0, 0, 0, 3);
                              GXSetTevSwapModeTable(2, 1, 1, 1, 3);
                              GXSetTevSwapModeTable(3, 2, 2, 2, 3);
                          }
                          temp_r0_4 = M2C_FIELD(arg0, u32 *, 0x50);
                          var_r23_5 = 0;
                          usedIndirect[0] = 0;
                          temp_r3_6 = (temp_r0_4 >> 9U) & 0x1F;
                          usedIndirect[1] = 0;
                          usedIndirect[2] = 0;
                          if (temp_r3_6 != 0) {
                              GXSetNumTevStages(temp_r3_6);
                              temp_r9 = M2C_FIELD(arg0, u32 *, 0x4C);
                              var_r24_3 = 0;
                              var_r22 = (u8 *)(((temp_r9 >> 0xDU) & 0x1C) + (((temp_r9 >> 3U) & 4) + (((temp_r9 >> 4U) & 4) + (((temp_r9 >> 5U) & 4) + ((temp_r9 >> 0xCU) & 4)))) + (M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r9 >> 0x17U) & 0x1E0) + ((temp_r9 >> 0x12U) & 0x3C) + (((((temp_r9 >> 0x12U) & 3) + ((temp_r9 >> 0x18U) & 0xF)) * 0x14) + ((temp_r9 >> 6U) & 4)))));
                      goto loop_55_test;
                      loop_55_body:
                                  GXSetTevOrder(var_r24_3, M2C_FIELD(var_r22, u8 *, 0), (M2C_FIELD(var_r22, u8 *, 2) & ~0x100) | ((M2C_FIELD(var_r22, u8 *, 3) << 8) & 0x100), M2C_FIELD(var_r22, u8 *, 1));
                                  temp_r0_5 = M2C_FIELD(var_r22, u8 *, 3);
                                  GXSetTevSwapMode(var_r24_3, (temp_r0_5 >> 1U) & 3, (temp_r0_5 >> 3U) & 3);
                                  temp_r0_6 = M2C_FIELD(var_r22, u8 *, 5);
                                  temp_r5_5 = M2C_FIELD(var_r22, u8 *, 4);
                                  GXSetTevColorIn(var_r24_3, temp_r5_5 & 0xF, (temp_r5_5 >> 4U) & 0xF, temp_r0_6 & 0xF, (temp_r0_6 >> 4U) & 0xF);
                                  temp_r6_3 = M2C_FIELD(var_r22, u8 *, 6);
                                  temp_r0_7 = M2C_FIELD(var_r22, u8 *, 7);
                                  GXSetTevColorOp(var_r24_3, temp_r6_3 & 0xF, (temp_r6_3 >> 4U) & 3, (temp_r6_3 >> 6U) & 3, temp_r0_7 & 1, (temp_r0_7 >> 1U) & 3);
                                  GXSetTevKColorSel(var_r24_3, ((u8) M2C_FIELD(var_r22, u8 *, 7) >> 3U) & 0x1F);
                                  temp_r0_8 = M2C_FIELD(var_r22, u8 *, 9);
                                  temp_r5_6 = M2C_FIELD(var_r22, u8 *, 8);
                                  GXSetTevAlphaIn(var_r24_3, temp_r5_6 & 0xF, (temp_r5_6 >> 4U) & 0xF, temp_r0_8 & 0xF, (temp_r0_8 >> 4U) & 0xF);
                                  temp_r6_4 = M2C_FIELD(var_r22, u8 *, 0xA);
                                  temp_r0_9 = M2C_FIELD(var_r22, u8 *, 0xB);
                                  GXSetTevAlphaOp(var_r24_3, temp_r6_4 & 0xF, (temp_r6_4 >> 4U) & 3, (temp_r6_4 >> 6U) & 3, temp_r0_9 & 1, (temp_r0_9 >> 1U) & 3);
                                  GXSetTevKAlphaSel(var_r24_3, ((u8) M2C_FIELD(var_r22, u8 *, 0xB) >> 3U) & 0x1F);
                                  temp_r10 = M2C_FIELD(var_r22, u8 *, 0xF);
                                  temp_r6_5 = M2C_FIELD(var_r22, u8 *, 0xD);
                                  temp_r9_2 = M2C_FIELD(var_r22, u8 *, 0xE);
                                  temp_r21_2 = (temp_r6_5 >> 3U) & 0xF;
                                  sp8 = (temp_r10 >> 3U) & 1;
                                  spC = (temp_r10 >> 4U) & 3;
                                  GXSetTevIndirect(var_r24_3, M2C_FIELD(var_r22, u8 *, 0xC), temp_r10 & 3, temp_r6_5 & 7, temp_r21_2, temp_r9_2 & 7, (temp_r9_2 >> 3U) & 7, (temp_r10 >> 2U) & 1, sp8, spC);
                                  if ((temp_r21_2 >= 1) && (temp_r21_2 <= 3)) {
                                      var_r23_5 = 1;
                                      M2C_FIELD(&(&usedIndirect[0])[temp_r21_2], s8 *, -1) = 1;
                                  }
                                  var_r22 += 0x10;
                                  var_r24_3 += 1;
                              loop_55_test:
                                  if (var_r24_3 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 9U) & 0x1F)) goto loop_55_body;
                              var_r25 = 1;
                          } else {
                              temp_r0_10 = temp_r0_4 >> 0x1CU;
                              var_r24_4 = 0;
                              if (temp_r0_10 == 0) {
                                  GXSetTevOrder(0U, 0xFFU, 0xFFU, 4U);
                                  GXSetTevColorIn(0U, 0xF, 4, 0xA, 0xF);
                                  GXSetTevAlphaIn(0U, 7, 2, 5, 7);
                                  var_r25 = 1;
                                  var_r24_4 = 1;
                                  
} else if (temp_r0_10 == 1) {
                                  GXSetTevOrder(0U, 0U, 0U, 0xFFU);
                                  GXSetTevColorIn(0U, 2, 4, 8, 0xF);
                                  GXSetTevAlphaIn(0U, 1, 2, 4, 7);
                                  var_r24_4 = 1;
                      block_83:
                                  if (var_r25 != 0) {
                                      GXSetTevOrder(var_r24_4, 0xFFU, 0xFFU, 4U);
                                      GXSetTevColorIn(var_r24_4, 0xF, 0, 0xA, 0xF);
                                      GXSetTevAlphaIn(var_r24_4, 7, 0, 5, 7);
                                      var_r24_4 += 1;
                                  }
                                  
} else if (temp_r0_10 == 2) {
                                  GXSetTevOrder(0U, 0U, 0U, 0xFFU);
                                  GXSetTevColorIn(0U, 0xF, 0xF, 0xF, 8);
                                  GXSetTevAlphaIn(0U, 7, 7, 7, 4);
                                  GXSetTevOrder(1U, 1U, 1U, 0xFFU);
                                  GXSetTevColorIn(1U, 8, 0, 0xE, 0xF);
                                  GXSetTevAlphaIn(1U, 4, 0, 6, 7);
                                  GXSetTevKColorSel(1U, M2C_FIELD(data, s32 *, 0x490));
                                  GXSetTevKAlphaSel(1U, M2C_FIELD(data, s32 *, 0x4B0));
                                  var_r24_4 = 2;
                      block_70:
                                  var_r5 = 0;
                                  if (((s16) M2C_FIELD(arg0, volatile u16 *, 0x24) == (s16) M2C_FIELD(&lbl_80565230, s16 *, 0)) && ((s16) M2C_FIELD(arg0, volatile u16 *, 0x26) == (s16) M2C_FIELD(&lbl_80565230, s16 *, 2)) && ((s16) M2C_FIELD(arg0, volatile u16 *, 0x28) == (s16) M2C_FIELD(&lbl_80565230, s16 *, 4)) && ((s16) M2C_FIELD(arg0, volatile u16 *, 0x2A) == (s16) M2C_FIELD(&lbl_80565230, s16 *, 6))) {
                                      var_r5 = 1;
                                  }
                                  if (var_r5 != 0) {
                                      var_r3_2 = 0;
                                      if (((s16) M2C_FIELD(arg0, volatile u16 *, 0x2C) == 0xFF) && ((s16) M2C_FIELD(arg0, volatile u16 *, 0x2E) == 0xFF) && ((s16) M2C_FIELD(arg0, volatile u16 *, 0x30) == 0xFF) && ((s16) M2C_FIELD(arg0, volatile u16 *, 0x32) == 0xFF)) {
                                          var_r3_2 = 1;
                                      }
                                      if (var_r3_2 == 0) {
                                          goto block_82;
                                      }
                                  } else {
                      block_82:
                                      GXSetTevOrder(var_r24_4, 0xFFU, 0xFFU, 0xFFU);
                                      GXSetTevColorIn(var_r24_4, 2, 4, 0, 0xF);
                                      GXSetTevAlphaIn(var_r24_4, 1, 2, 0, 7);
                                      var_r24_4 += 1;
                                  }
                                  goto block_83;
                              
} else {
                                  var_r21_3 = (s32 *)(data + 0x490);
                                  var_r22_2 = (s32 *)(data + 0x4B0);
                                  var_r28_2 = 0;
                      goto loop_69_test;
                        loop_69_body:
                                      GXSetTevOrder(var_r24_4, var_r28_2, var_r28_2, 0xFFU);
                                      var_r7 = 0;
                                      if ((s32) var_r28_2 == 0) {
                                          var_r7 = 0xF;
                                      }
                                      var_r27_2 = 0;
                                      if ((s32) var_r28_2 == 0) {
                                          var_r27_2 = 7;
                                      }
                                      GXSetTevColorIn(var_r24_4, 0xF, 8, 0xE, var_r7);
                                      GXSetTevAlphaIn(var_r24_4, 7, 4, 6, var_r27_2);
                                      GXSetTevKColorSel(var_r24_4, *var_r21_3);
                                      GXSetTevKAlphaSel(var_r24_4, *var_r22_2);
                                      var_r24_4 += 1;
                                      var_r21_3 += 1;
                                      var_r22_2 += 1;
                                      var_r28_2 += 1;
                              loop_69_test:
                                  if (var_r28_2 < (u32) ((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1CU)) goto loop_69_body;
                                  goto block_70;
                              
}
                              var_r22_3 = 0;
                      goto loop_87_test;
                        loop_87_body:
                                  GXSetTevColorOp(var_r22_3, 0, 0, 0, 1, 0);
                                  GXSetTevAlphaOp(var_r22_3, 0, 0, 0, 1, 0);
                                  GXSetTevDirect(var_r22_3);
                                  GXSetTevSwapMode(var_r22_3, 0, 0);
                                  var_r22_3 += 1;
                              loop_87_test:
                                  if (var_r22_3 < var_r24_4) goto loop_87_body;
                              GXSetNumTevStages(var_r24_4);
                          }
                          if (var_r23_5 != 0) {
                              temp_r9_3 = M2C_FIELD(arg0, u32 *, 0x4C);
                              var_r28_3 = &usedIndirect[0];
                              var_r23_6 = 0U;
                              temp_f30 = lbl_80560E8C;
                              var_r21_4 = (u8 *)(((temp_r9_3 >> 0xCU) & 4) + ((temp_r9_3 >> 5U) & 4) + (((temp_r9_3 >> 4U) & 4) + ((temp_r9_3 >> 6U) & 4)) + ((((temp_r9_3 >> 0x18U) & 0xF) * 0x14) + (((temp_r9_3 >> 0x12U) & 0x3C) + ((temp_r9_3 >> 0x17U) & 0x1E0))) + (M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r9_3 >> 0xDU) & 0x1C) + ((temp_r9_3 >> 3U) & 4))));
                      goto loop_94_test;
                        loop_94_body:
                                  if ((s32) *var_r28_3 != 0) {
                                      temp_f31 = CosFIdx__Q24nw4r4mathFf(temp_f30 * M2C_FIELD(var_r21_4, f32 *, 8));
                                      temp_f1 = SinFIdx__Q24nw4r4mathFf(temp_f30 * M2C_FIELD(var_r21_4, f32 *, 8));
                                      temp_f2 = -temp_f1;
                                      indirectMatrix[0] = temp_f31 * M2C_FIELD(var_r21_4, f32 *, 0xC);
                                      indirectMatrix[1] = temp_f2 * M2C_FIELD(var_r21_4, f32 *, 0x10);
                                      indirectMatrix[2] = M2C_FIELD(var_r21_4, f32 *, 0);
                                      indirectMatrix[3] = temp_f1 * M2C_FIELD(var_r21_4, f32 *, 0xC);
                                      indirectMatrix[4] = temp_f31 * M2C_FIELD(var_r21_4, f32 *, 0x10);
                                      indirectMatrix[5] = M2C_FIELD(var_r21_4, f32 *, 4);
                                      #pragma push
                     #pragma dont_inline on
                                 fn_800D7D5C((void *)(var_r23_6 + 1), &indirectMatrix[0]);
                     #pragma pop
                                  }
                                  var_r28_3 += 1;
                                  var_r21_4 += 0x14;
                                  var_r23_6 += 1;
                              loop_94_test:
                                  if (var_r23_6 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x12U) & 3)) goto loop_94_body;
                          }
                          GXSetNumIndStages(((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0xFU) & 7);
                          if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0xFU) & 7) {
                              temp_r9_4 = M2C_FIELD(arg0, u32 *, 0x4C);
                              var_r23_7 = 0U;
                              var_r21_5 = (u8 *)(((temp_r9_4 >> 3U) & 4) + (((temp_r9_4 >> 0xCU) & 4) + ((temp_r9_4 >> 5U) & 4) + (((temp_r9_4 >> 4U) & 4) + ((temp_r9_4 >> 6U) & 4))) + (M2C_FIELD(arg0, u32 *, 0x58) + ((((temp_r9_4 >> 0x18U) & 0xF) * 0x14) + (((temp_r9_4 >> 0x12U) & 0x3C) + ((temp_r9_4 >> 0x17U) & 0x1E0)))));
                      goto loop_98_test;
                        loop_98_body:
                                  GXSetIndTexOrder(var_r23_7, M2C_FIELD(var_r21_5, u8 *, 0), M2C_FIELD(var_r21_5, u8 *, 1));
                                  GXSetIndTexCoordScale(var_r23_7, M2C_FIELD(var_r21_5, u8 *, 2), M2C_FIELD(var_r21_5, u8 *, 3));
                                  var_r21_5 += 4;
                                  var_r23_7 += 1;
                              loop_98_test:
                                  if (var_r23_7 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0xFU) & 7)) goto loop_98_body;
                          }
                          temp_r7 = M2C_FIELD(arg0, u32 *, 0x4C);
                          if ((temp_r7 >> 6U) & 1) {
                              temp_r0_11 = M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r7 >> 6U) & 4) + (((temp_r7 >> 0xCU) & 4) + ((temp_r7 >> 5U) & 4)));
                              temp_r3_7 = (((temp_r7 >> 0x18U) & 0xF) * 0x14) + (((temp_r7 >> 0x12U) & 0x3C) + ((temp_r7 >> 0x17U) & 0x1E0));
                              temp_r6_6 = temp_r3_7 + temp_r0_11;
                              temp_r0_12 = *(u8 *)(temp_r3_7 + temp_r0_11);
                              GXSetAlphaCompare(temp_r0_12 & 0xF, M2C_FIELD(temp_r6_6, u8 *, 2), M2C_FIELD(temp_r6_6, u8 *, 1), (temp_r0_12 >> 4U) & 0xF, M2C_FIELD(temp_r6_6, u8 *, 3));
                          } else {
                              GXSetAlphaCompare(7, 0U, 0U, 7, 0U);
                          }
                          temp_r3_8 = M2C_FIELD(arg0, u32 *, 0x4C);
                          if ((temp_r3_8 >> 5U) & 1) {
                              temp_r8_2 = (temp_r3_8 >> 4U) & 4;
                              temp_r7_2 = M2C_FIELD(arg0, u32 *, 0x58);
                              temp_r0_13 = temp_r7_2 + (((temp_r3_8 >> 0xCU) & 4) + ((temp_r3_8 >> 5U) & 4) + (temp_r8_2 + ((temp_r3_8 >> 6U) & 4)));
                              temp_r3_9 = (((temp_r3_8 >> 0x18U) & 0xF) * 0x14) + (((temp_r3_8 >> 0x12U) & 0x3C) + ((temp_r3_8 >> 0x17U) & 0x1E0));
                              temp_r6_7 = temp_r3_9 + temp_r0_13;
                              ((void (*)(u32, u32, u32, u32))GXSetBlendMode)(*(u8 *)(temp_r3_9 + temp_r0_13), M2C_FIELD(temp_r6_7, u8 *, 1), M2C_FIELD(temp_r6_7, u8 *, 2), M2C_FIELD(temp_r6_7, u8 *, 3));
                          } else {
                              ((void (*)(u32, u32, u32, u32))GXSetBlendMode)(1U, 4U, 5U, 0xFU);
                          }
       return (var_r25 != 0) && (var_r26 != 0);
                      }
extern "C" void fn_800DAFA8(void *arg0, void *arg1) {
    struct Obj {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3(void *);
    };
    ((Obj *)arg1)->f3(arg0);
}

extern "C" void fn_800DAFC4(void* arg0, u32 arg1) {
    extern const char lbl_8031F1FC[];
    extern const char lbl_8031F1D8[];
    register void* pane = arg0;
    register u32 key = arg1;
    void* node;
    void* end;
    void* current;
    node = *(void**)((char*)pane + 0x1C);
    end = (char*)pane + 0x1C;
    while (node != end) {
        current = node;
        node = *(void**)node;
        if (key != 0) {
            if (current == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
            if (*(u32*)((char*)current + 8) != key)
                continue;
        }
        {
            void* slot = current;
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator((char*)pane + 0x18, &slot);
        }
        if (current == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
        *(u32*)((char*)current + 8) = 0;
        *(u16*)((char*)current + 0xC) = 0;
    }
}

extern "C" const char lbl_8031F1FC[];
extern "C" const char lbl_8031F1D8[];

extern "C" void fn_800DB084(void* arg0) {
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(int); };
    ((Obj*)arg0)->v3(0);
}

static inline void AssertNode(void* node) {
    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800DB098(void* arg0, void* arg1) {
    struct AnimTarget {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void Animate(u16, void*);
    };
    register void* node = *(void**)((u8*)arg0 + 0x1C);
    register void* end = (u8*)arg0 + 0x1C;
    while (node != end) {
        AssertNode(node);
        if (*(u8*)((u8*)node + 0xE) == 0) {
            AssertNode(node);
            AnimTarget* obj = *(AnimTarget**)((u8*)node + 8);
            AssertNode(node);
            obj->Animate(*(u16*)((u8*)node + 0xC), arg0);
        }
        node = *(void**)node;
    }
}
#pragma pop
extern "C" void AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink(void* arg0, void* arg1) {
    extern const char lbl_8031FF54[];
    extern const char lbl_8031FF30[];
    register void* iterator = (u8*)arg0 + 0x1C;
    void* slot;
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF54, 0x233, lbl_8031FF30);
    slot = iterator;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8*)arg0 + 0x18, &slot, arg1);
}

extern "C" void fn_800DB1E0(char* arg0) {
    fn_800D4F98(arg0 + 0x18);
}

extern "C" void fn_800DB1E8(void* arg0, void* unused, s32 arg2) {
    void* temp = ((Dummy_800DB1E8 *)arg0)->call();
    if (temp != 0) {
        u32 count = __cntlzw((u32)arg2);
        s32 result = count / 0x20;
        *(s8*)((u8*)temp + 0xE) = (s8)result;
    }
}

extern "C" s32 fn_80128668();
extern "C" void fn_800D4F98(void*);
extern "C" s32 fn_800DB398(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void *__ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(void *dst, const void *src) {
    u32 zero = 0;
    void *vtable = lbl_8032012C;
    void *list14 = (u8 *)dst + 0x14;
    f32 defaultValue = lbl_80560EA8;
    void *list20 = (u8 *)dst + 0x20;
    *(volatile u32 *)((u8 *)dst + 0x14) = zero;
    *(volatile u32 *)((u8 *)dst + 0x18) = zero;
    *(volatile u32 *)((u8 *)dst + 0x20) = zero;
    *(volatile u32 *)((u8 *)dst + 0x24) = zero;
    u8 type = *((const u8 *)src + 9);
    *(volatile u32 *)((u8 *)dst + 4) = zero;
    *(volatile u32 *)((u8 *)dst + 8) = zero;
    *(void **)dst = vtable;
    *(u32 *)((u8 *)dst + 0x10) = zero;
    *(void **)((u8 *)dst + 0x14) = list14;
    *(void **)((u8 *)dst + 0x18) = list14;
    *(u32 *)((u8 *)dst + 0x1C) = zero;
    *(void **)((u8 *)dst + 0x20) = list20;
    *(void **)((u8 *)dst + 0x24) = list20;
    *(f32 *)((u8 *)dst + 0x4C) = defaultValue;
    *(f32 *)((u8 *)dst + 0x50) = defaultValue;
    *(u32 *)((u8 *)dst + 0xC) = zero;
    *(u32 *)((u8 *)dst + 0x28) = zero;
    *((u8 *)dst + 0xD0) = (u8)zero;
    *((u8 *)dst + 0xCC) = type;
    strncpy((char *)dst + 0xB4, (const char *)src + 0xC, 0x10);
    strncpy((char *)dst + 0xC4, (const char *)src + 0x1C, 8);
    *(f32 *)((u8 *)dst + 0x2C) = *(const f32 *)((const u8 *)src + 0x24);
    *(f32 *)((u8 *)dst + 0x30) = *(const f32 *)((const u8 *)src + 0x28);
    *(f32 *)((u8 *)dst + 0x34) = *(const f32 *)((const u8 *)src + 0x2C);
    *(f32 *)((u8 *)dst + 0x38) = *(const f32 *)((const u8 *)src + 0x30);
    *(f32 *)((u8 *)dst + 0x3C) = *(const f32 *)((const u8 *)src + 0x34);
    *(f32 *)((u8 *)dst + 0x40) = *(const f32 *)((const u8 *)src + 0x38);
    *(f32 *)((u8 *)dst + 0x44) = *(const f32 *)((const u8 *)src + 0x3C);
    *(f32 *)((u8 *)dst + 0x48) = *(const f32 *)((const u8 *)src + 0x40);
    *(f32 *)((u8 *)dst + 0x4C) = *(const f32 *)((const u8 *)src + 0x44);
    *(f32 *)((u8 *)dst + 0x50) = *(const f32 *)((const u8 *)src + 0x48);
    *((u8 *)dst + 0xCD) = *((const u8 *)src + 0xA);
    *((u8 *)dst + 0xCE) = *((const u8 *)src + 0xA);
    *((u8 *)dst + 0xCF) = *((const u8 *)src + 8);
    return dst;
}

extern "C" const char lbl_8031FF90[];
extern "C" const char lbl_80320250[];
extern "C" const char lbl_8032022C[];
extern "C" void AppendChild__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt4Pane(void* arg0, void* arg1) {
    register void* iterator = (u8*)arg0 + 0x14;
    register const char* messages = &lbl_8031FF90[0];
    register void* child = arg1;
    register void* parent = arg0;
    void* slot;
    if (child == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&messages[0], 0xFD, messages + 0x10);
    if (*(void**)((u8*)child + 0xC) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&messages[0], 0xFE, messages + 0x3C);
    if (child == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320250, 0x233, lbl_8032022C);
    slot = iterator;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8*)parent + 0x10, &slot, (u8*)child + 4);
    *(void**)((u8*)child + 0xC) = parent;
}

extern "C" f32 lbl_80560EA8;
extern "C" void fn_800DB76C(f32 *out, void *self, f32 *arg2) {
    struct Vec2Result {
        f32 x;
        f32 y;
    };
    f32 c = lbl_80560EA8;
    out[0] = c;
    out[1] = c;
    out[2] = c;
    out[3] = c;
    Vec2Result returned = ((Vec2Result (*)(void *))GetVtxPos__Q34nw4r3lyt4PaneCFv)(self);
    Vec2Result pos;
    *(volatile f64 *)&pos = *(volatile f64 *)&returned;
    f32 diff = arg2[0x10] - arg2[0xE];
    f32 x = pos.x;
    f32 y = pos.y;
    f32 nx = x + *(f32 *)((u8 *)self + 0x4C);
    f32 ny = y + *(f32 *)((u8 *)self + 0x50);
    out[0] = x;
    out[1] = y;
    out[2] = nx;
    out[3] = ny;
    if (diff < lbl_80560EA8) {
        out[1] = -y;
        out[3] = -ny;
    }
}

extern "C" void fn_800DB830(s32 *arg0) {
    *arg0 = -1;
}

extern "C" void fn_800DB83C(void) {

}

extern "C" u8 GetColorElement__Q36nw4hbm3lyt4PaneCFUl(void* self, u32 index) {
    extern const char lbl_8031FF90[];
    extern const char lbl_80320090[];
    if (index >= 0x11) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF90, 0x13F, lbl_80320090);
    if ((s32)index == 0x10) return *((u8*)self + 0xCD);
    struct Obj {
        virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
        virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
        virtual void a8(); virtual void a9(); virtual void a10();
        virtual u8 v11(u32);
    };
    return ((Obj*)self)->v11(index);
}

extern "C" void SetColorElement__Q36nw4hbm3lyt4PaneFUlUc(void* self, u32 index, u8 color) {
    extern const char lbl_8031FF90[];
    extern const char lbl_80320090[];
    if (index >= 0x11) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF90, 0x14E, lbl_80320090);
    if ((s32)index == 0x10) {
        *((u8*)self + 0xCD) = color;
    } else {
        struct Obj {
            virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
            virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
            virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
            virtual void a12(); virtual void a13(); virtual void v14(u32, u8);
        };
        ((Obj*)self)->v14(index, color);
    }
}

extern "C" s32 fn_800DB958(void) { return 0xFF; }

extern "C" void fn_800DB960(void) {

}

#pragma push
#pragma use_lmw_stmw off
extern "C" void* FindPaneByName__Q36nw4hbm3lyt4PaneFPCcb(void* self, const char* name, bool recursive) {
    extern s32 fn_800D58C4(void*);
    extern const char lbl_8031E8FC[];
    extern const char lbl_8031E8D8[];
    if (fn_800D58C4((u8*)self + 0xB4))
        return self;
    if (recursive) {
        void* end = (u8*)self + 0x14;
        void* node;
        node = *(void**)((u8*)self + 0x14);
        do {
            if (!node)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            struct Obj { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12();  virtual void* find(const char*, bool); };
            void* found = ((Obj*)((u8*)node - 4))->find(name, true);
            if (found)
                return found;
            node = *(void**)node;
        } while(node != end);
    }
    return 0;
}

extern "C" int fn_800D58F0(const char*, const char*);
extern "C" const char lbl_8031E8FC[];
extern "C" const char lbl_8031E8D8[];
extern "C" const char lbl_8031F1D8[];
extern "C" const char lbl_8031F1FC[];
extern "C" int FindMaterialByName__Q36nw4hbm3lyt4PaneFPCcb(void* self, const char* name, bool recursive) {
    struct V {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13();
        virtual int find(const char*, bool);
    };
    void* data = *(void**)((char*)self + 0x28);
    if (data != 0 && ((int (*)(const char*, const char*))fn_800D58F0)((const char*)data + 4, name))
        return (int)*(void**)((char*)self + 0x28);
    if (recursive) {
        void* node = *(void**)((char*)self + 0x14);
        void* end = (char*)self + 0x14;
        while (node != end) {
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            V* object = (V*)((char*)node - 4);
            int result = object->find(name, true);
            if (result != 0)
                return result;
            node = *(void**)node;
        }
    }
    return 0;
}

void nw4hbm::lyt::Pane::CalculateMtx(const nw4hbm::lyt::DrawInfo &arg1) {
    struct Local {
        f32 mtx10[12];
        f32 mtx40[12];
        f32 mtx70[12];
    } frame;
    u8 *pane = (u8 *)this;
    u8 *info = (u8 *)&arg1;
    volatile const u8 *flagInfo = (volatile const u8 *)info;
    u32 scaleX;
    u32 scaleY;
    f32 *sx = (f32 *)&scaleX;
    f32 *sy = (f32 *)&scaleY;
    register s32 flags = pane[0xCF];
    u32 scaleFlag;
    u32 bitsX;
    u32 bitsY;
    u8 scaleByte;
    union { struct { u32 hi, lo; } words; f64 number; } alphaBits;
    f32 opacity;
    s32 saveBit;
    s32 changeOpacity;
    register u8 *node;

    if ((flags & 1) == 0 && ((flagInfo[0x50] >> 4) & 1) != 0) {
        scaleByte = flagInfo[0x50];
        bitsX = *(volatile u32 *)(pane + 0x44);
        scaleFlag = (scaleByte >> 5) & 1;
        bitsY = *(volatile u32 *)(pane + 0x48);
        scaleX = bitsX;
        scaleY = bitsY;
        if (scaleFlag != 0) {
            if ((flags & 4) != 0) {
                *sx *= *(const f32 *)(info + 0x44);
                *sy *= *(const f32 *)(info + 0x48);
            }
        }
        PSMTXScale(frame.mtx40, *sx, *sy, lbl_80560EAC);
        PSMTXInverse(frame.mtx10, 0x78, lbl_80560EB0 * *(f32 *)(pane + 0x38));
        PSMTXConcat(frame.mtx10, frame.mtx40, frame.mtx70);
        PSMTXInverse(frame.mtx10, 0x79, lbl_80560EB0 * *(f32 *)(pane + 0x3C));
        PSMTXConcat(frame.mtx10, frame.mtx70, frame.mtx40);
        PSMTXInverse(frame.mtx10, 0x7A, lbl_80560EB0 * *(f32 *)(pane + 0x40));
        PSMTXConcat(frame.mtx10, frame.mtx40, frame.mtx70);
        PSMTXRotTrig(frame.mtx70, pane + 0x54, *(f32 *)(pane + 0x2C), *(f32 *)(pane + 0x30), *(f32 *)(pane + 0x34));

        if (*(u8 **)(pane + 0xC) != 0) {
            PSMTXConcat((f32 *)(*(u8 **)(pane + 0xC) + 0x84), (f32 *)(pane + 0x54), (f32 *)(pane + 0x84));
        } else if (((flagInfo[0x50] >> 7) & 1) != 0) {
            *(u32 *)(pane + 0x84) = *(u32 *)(pane + 0x54);
            *(u32 *)(pane + 0x88) = *(u32 *)(pane + 0x58);
            *(u32 *)(pane + 0x8C) = *(u32 *)(pane + 0x5C);
            *(u32 *)(pane + 0x90) = *(u32 *)(pane + 0x60);
            *(u32 *)(pane + 0x94) = *(u32 *)(pane + 0x64);
            *(u32 *)(pane + 0x98) = *(u32 *)(pane + 0x68);
            *(u32 *)(pane + 0x9C) = *(u32 *)(pane + 0x6C);
            *(u32 *)(pane + 0xA0) = *(u32 *)(pane + 0x70);
            *(u32 *)(pane + 0xA4) = *(u32 *)(pane + 0x74);
            *(u32 *)(pane + 0xA8) = *(u32 *)(pane + 0x78);
            *(u32 *)(pane + 0xAC) = *(u32 *)(pane + 0x7C);
            *(u32 *)(pane + 0xB0) = *(u32 *)(pane + 0x80);
        } else {
            PSMTXConcat((f32 *)(info + 4), (f32 *)(pane + 0x54), (f32 *)(pane + 0x84));
        }

        if (((flagInfo[0x50] >> 6) & 1) != 0 && *(u8 **)(pane + 0xC) != 0) {
            alphaBits.words.hi = 0x43300000;
            alphaBits.words.lo = pane[0xCD];
            pane[0xCE] = (u8)((f32)(alphaBits.number - lbl_80560EB8) * *(const f32 *)(info + 0x4C));
        } else {
            pane[0xCE] = pane[0xCD];
        }

        changeOpacity = 0;
        opacity = *(const f32 *)(info + 0x4C);
        {
            u32 bit = (flagInfo[0x50] >> 6) & 1;
            saveBit = (bit | -bit) >> 31;
        }
        if ((pane[0xCF] & 2) != 0 && pane[0xCD] != 0xFF)
            changeOpacity = 1;
        if (changeOpacity != 0) {
            info[0x50] |= 0x40;
            alphaBits.words.hi = 0x43300000;
            alphaBits.words.lo = pane[0xCD];
            *(f32 *)(info + 0x4C) = lbl_80560EB4 * (opacity * (f32)(alphaBits.number - lbl_80560EB8));
        }
        node = *(u8 **)(pane + 0x14);
        while (node != pane + 0x14) {
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            ((nw4hbm::lyt::PaneMtxDispatch *)(node - 4))->Apply(arg1);
            node = *(u8 **)node;
        }
        if (changeOpacity != 0) {
            *(f32 *)(info + 0x4C) = opacity;
            info[0x50] = (u8)((info[0x50] & ~0x40) | ((saveBit << 6) & 0x40));
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void Draw__Q36nw4hbm3lyt4PaneFRCQ36nw4hbm3lyt8DrawInfo(void* self, void* info) {
    extern const char lbl_8031E8FC[];
    extern const char lbl_8031E8D8[];
    if (*((u8*)self + 0xCF) & 1) {
        struct Obj {
            virtual void a0();
            virtual void a1();
            virtual void a2();
            virtual void a3();
            virtual void a4();
        };
        ((Obj*)self)->a4();
        register void *node = *(void**)((u8*)self + 0x14);
        register void *end = (u8*)self + 0x14;
        while (node != end) {
            if (!node)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            struct Child {
                virtual void a0();
                virtual void a1();
                virtual void a2();
                virtual void Draw(void*);
            };
            ((Child*)((u8*)node - 4))->Draw(info);
            node = *(void**)node;
        }
    }
}
#pragma pop
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*, void**);
extern "C" void DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(void*, void*, void*);
extern "C" GetVtxPosResult GetVtxPos__Q34nw4r3lyt4PaneCFv(void*);
extern "C" void DrawSelf__Q36nw4hbm3lyt4PaneFRCQ36nw4hbm3lyt8DrawInfo(void* self, void* info) {
    if (*(s32*)((u8*)self + 0xC) != 0 && ((*(u8*)((u8*)info + 0x50) >> 3) & 1)) {
        void (**vtable)(void) = *(void (***)(void))self;
        vtable[0x60 / 4]();
        u32 color = 0xFF00FF;
        GetVtxPosResult pos = GetVtxPos__Q34nw4r3lyt4PaneCFv(self);
        void* args[2];
        args[0] = &pos;
        args[1] = (u8*)self + 0x4C;
        DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(args, args[1], &color);
    }
}

extern "C" void Animate__Q36nw4hbm3lyt4PaneFUl(void *self, u32 flags) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
    };
    ((Obj *)self)->v6();
    if ((*(u8 *)((u8 *)self + 0xCF) & 1) == 0 && (flags & 1) == 0) {
        void *node = *(void * volatile *)((u8 *)self + 0x14);
        void *end = (u8 *)self + 0x14;
        while (node != end) {
            extern const char lbl_8031E8FC[];
            extern const char lbl_8031E8D8[];
            if (node == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            }
            void *obj = (u8 *)node - 4;
            void (**vt)(void) = *(void (***)(void))obj;
            ((void (*)(void *, u32))vt[7])(obj, flags);
            node = *(void **)node;
        }
    }
}

extern "C" void AnimateSelf__Q36nw4hbm3lyt4PaneFUl(void* self, unsigned long flags) {
    struct AnimCallback {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void call(u16, void*);
    };
    struct UpdateCallback {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
        virtual void call();
    };
    PaneAnimLink* head = (PaneAnimLink*)((u8*)self + 0x20);
    PaneAnimLink* link = *(PaneAnimLink**)((u8*)self + 0x20);
    while (link != head) {
        if (!link) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
        if (!link->disabled) {
            if (!link) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
            AnimCallback* anim = (AnimCallback*)link->animation;
            if (!link) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
            anim->call(link->index, self);
        }
        link = link->next;
    }
    if ((*(u8*)((u8*)self + 0xCF) & 1) == 0 && (flags & 1)) return;
    UpdateCallback* obj = (UpdateCallback*)*(void**)((u8*)self + 0x28);
    if (obj) obj->call();
}

extern "C" void BindAnimation__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformb(void* self, void* transform, bool flag) {
    extern const char lbl_8031FF90[];
    extern const char lbl_803200C8[];
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(void*, bool); };
    if (!transform) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF90, 0x254, lbl_803200C8);
    ((Obj*)transform)->v2(self, flag);
}

struct PaneLinkNode {
    PaneLinkNode* next;
    PaneLinkNode* prev;
};
struct PaneObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void UnbindAnimation(void* transform, bool flag);
    virtual void v17();
    virtual void UnbindAnimationSelf(void* transform);

    char pad[0x10];
    PaneLinkNode mChildList;
};

extern "C" void UnbindAnimation__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformb(void* self, void* transform, bool flag) {
    struct LinkNode {
        LinkNode* next;
        LinkNode* prev;
    };
    struct PaneObj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void UnbindAnimation(void* transform, bool flag);
        virtual void v17();
        virtual void UnbindAnimationSelf(void* transform);

        char pad[0x10];
        LinkNode mChildList;
    };
    PaneObj* pane = (PaneObj*)self;
    pane->UnbindAnimationSelf(transform);
    if (flag) {
        LinkNode* node = pane->mChildList.next;
        LinkNode* end = &pane->mChildList;
        while (node != end) {
            if (!node) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23d, lbl_8031E8D8);
            }
            ((PaneObj*)((char*)node - 4))->UnbindAnimation(transform, flag);
            node = node->next;
        }
    }
}

extern "C" void fn_800DC204(void* self, void* arg) {
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(int, void*); };
    ((Obj*)self)->v16(0, arg);
}

#pragma push
#pragma opt_propagation off
extern "C" void UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(void* pane_arg, void* anim_arg) {
    extern const char lbl_8031F1FC[];
    extern const char lbl_8031F1D8[];
    extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*, void**);
    register void* pane = pane_arg;
    register void* anim = anim_arg;
    void* node;
    void* end;
    void* current;
    void* animation = *(void**)((char*)pane + 0x28);
    if (animation != 0) {
        struct V { virtual void a(); virtual void b(); virtual void c(); virtual void d(); };
        ((V*)animation)->d();
    }
    node = *(void**)((char*)pane + 0x20);
    end = (char*)pane + 0x20;
    while (node != end) {
        current = node;
        node = *(void**)node;
        if (anim != 0) {
            if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23d, lbl_8031F1D8);
            if (*(void**)((char*)current + 8) != anim) continue;
        }
        {
          void* slot = current;
          Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator((char*)pane + 0x1c, &slot);
        }
        if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23d, lbl_8031F1D8);
        *(void**)((char*)current + 8) = 0;
        *(u16*)((char*)current + 0xc) = 0;
    }
}
#pragma pop
extern "C" void AddAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimationLink(void* self, void* link) {
    extern const char lbl_8031FF90[];
    extern const char lbl_803200F8[];
    extern const char lbl_8031FF54[];
    extern const char lbl_8031FF30[];
    void* iterator;
    if (!link) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF90, 0x289, lbl_803200F8);
    iterator = (char*)self + 0x20;
    if (!link) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF54, 0x233, lbl_8031FF30);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char*)self + 0x1c, &iterator, link);
}

extern "C" void SetAnimationEnable__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformbb(void *self, void *anim, u32 enable, u32 recursive) {
    struct AnimEnableDispatch {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6();
        virtual void setEnable(void *, u32);
        virtual void d8();
        virtual void d9();
        virtual void d10();
        virtual void d11();
        virtual void d12();
        virtual void d13();
        virtual void d14();
        virtual void d15();
        virtual void d16();
        virtual void d17();
        virtual void d18();
        virtual void d19();
        virtual void setRecursive(void *, u32, u32);
    };
    void *p = ((void *(*)(void *))fn_800D4F98)((u8 *)self + 0x1C);
    if (p != 0)
        *(u8 *)((u8 *)p + 0xE) = !enable;
    AnimEnableDispatch *obj = (AnimEnableDispatch *)*(void **)((u8 *)self + 0x28);
    if (obj != 0)
        obj->setEnable(anim, enable);
    if (recursive) {
        void *end = (u8 *)self + 0x14;
        void *node = *(void **)((u8 *)self + 0x14);
        while (node != end) {
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            AnimEnableDispatch *item = (AnimEnableDispatch *)((u8 *)node - 4);
            item->setRecursive(anim, enable, recursive);
            node = *(void **)node;
        }
    }
}

extern "C" int fcmpgt(f32, f32);
extern "C" void PSMTXConcat(const f32*, const f32*, f32*);
extern "C" void PSMTXCopy(const f32*, f32*);
extern "C" void GXLoadPosMtxImm(const f32*, u32);
extern "C" void GXSetCurrentMtx(u32);
extern "C" void LoadMtx__Q34nw4r3lyt4PaneFRCQ34nw4r3lyt8DrawInfo(void* self, void* info) {
    extern f32 lbl_80560EA8;
    Mtx mtx;
    f32* result;
    if ((((u8*)info)[0x50] >> 7) & 1) {
        PSMTXConcat((f32*)((u8*)info + 4), (f32*)((u8*)self + 0x84), &mtx[0][0]);
        BOOL flip = (*(f32*)((u8*)info + 0x40) - *(f32*)((u8*)info + 0x38)) < lbl_80560EA8;
        if (flip) {
            mtx[0][3] = -mtx[0][3];
            mtx[1][3] = -mtx[1][3];
            mtx[2][3] = -mtx[2][3];
        }
        result = &mtx[0][0];
    } else {
        BOOL flip = (*(f32*)((u8*)info + 0x40) - *(f32*)((u8*)info + 0x38)) < lbl_80560EA8;
        if (flip) {
            PSMTXCopy((f32*)((u8*)self + 0x84), &mtx[0][0]);
            mtx[0][3] = -mtx[0][3];
            mtx[1][3] = -mtx[1][3];
            mtx[2][3] = -mtx[2][3];
            result = &mtx[0][0];
        } else {
            result = (f32*)((u8*)self + 0x84);
        }
    }
    GXLoadPosMtxImm(result, 0);
    GXSetCurrentMtx(0);
}

extern "C" f32 lbl_80560EC0;
#pragma scheduling invalid_target
extern "C" GetVtxPosResult GetVtxPos__Q34nw4r3lyt4PaneCFv(void* self) {
    u8 n = *(u8*)((u8*)self + 0xCC);
    s32 r = n % 3;
    GetVtxPosResult result;
    result.x = lbl_80560EA8;
    result.y = lbl_80560EA8;
    switch (r) {
    default:
        result.x = lbl_80560EA8;
        break;
    case 1:
        result.x = -*(f32*)((u8*)self + 0x4C) * lbl_80560EC0;
        break;
    case 2:
        result.x = -*(f32*)((u8*)self + 0x4C);
        break;
    }
    s32 q = n / 3;
    switch (q) {
    default:
        result.y = lbl_80560EA8;
        break;
    case 1:
        result.y = -*(f32*)((u8*)self + 0x50) * lbl_80560EC0;
        break;
    case 2:
        result.y = -*(f32*)((u8*)self + 0x50);
        break;
    }
    return result;
}
#pragma scheduling on
extern "C" s32 fn_800DC6DC(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}
struct GetTextureSizeMaterial { u8 pad[0x50]; u32 textureCount; u8 pad54[4]; void* textureObjects; };