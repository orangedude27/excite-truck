// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include "revolution/GX/GXTypes.h"
#include "revolution/GX/GXAttr.h"
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
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
extern "C" int fn_800D7C54(int *, s32);                /* extern */
extern "C" f32 lbl_80560E8C;
extern "C" int lbl_80565230;



extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*, void**);
extern "C" void DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(void*, void*, void*);
extern "C" void* GetVtxPos__Q34nw4r3lyt4PaneCFv(void*);

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
extern "C" void MEMFreeToAllocator(s32);
extern "C" s32 lbl_8055DDF0;
int strncmp(const char *, const char *, unsigned int);
extern "C" int strncmp(const char *, const char *, unsigned int);
struct AlphaColor { u8 r, g, b, a; };

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
    if (*(s32*)((u8*)arg0 + 4) != 0) {
        MEMFreeToAllocator(lbl_8055DDF0);
        *(u32*)((u8*)arg0 + 4) = 0;
        *(u8*)((u8*)arg0) = 0;
        *((u8*)arg0 + 1) = 0;
    }
}

extern "C" s32 MEMAllocFromAllocator(s32, s32);
extern "C" const char lbl_8031F5A8[];
extern "C" const char lbl_8031F5B8[];
extern "C" void Reserve__Q46nw4hbm3lyt6detail11TexCoordAryFUc(void *arg0, u8 arg1) {
    if (arg1 > 8)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F5A8, 0x5D, lbl_8031F5B8);
    if (*(u8*)arg0 < arg1) {
        if (*(s32*)((u8*)arg0 + 4) != 0) {
            MEMFreeToAllocator(lbl_8055DDF0);
            *(s32*)((u8*)arg0 + 4) = 0;
            *(u8*)arg0 = 0;
            *((u8*)arg0 + 1) = 0;
        }
        s32 p = MEMAllocFromAllocator(lbl_8055DDF0, arg1 << 5);
        *(s32*)((u8*)arg0 + 4) = p;
        if (p != 0)
            *(u8*)arg0 = arg1;
    }
}

extern "C" int IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(unsigned int *color, unsigned char alpha) {
    if (alpha != 0xff) return 1;
    if (color == 0) return 0;
    if ((color[0] + 0x10000) != 0xffff) return 1;
    if ((color[1] + 0x10000) != 0xffff) return 1;
    if ((color[2] + 0x10000) != 0xffff) return 1;
    if ((color[3] + 0x10000) == 0xffff) return 0;
    return 1;
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
    register void* iterator = (u8*)arg0 + 4;
    void* slot;
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F658, 0x233, lbl_8031F634);
    slot = iterator;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(arg0, &slot, (u8*)arg1 + 4);
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
    s16 d = ((s16 *)arg1)[3];
    s16 c = ((s16 *)arg1)[2];
    s16 b = ((s16 *)arg1)[1];
    s16 a = ((s16 *)arg1)[0];
    ((s16 *)arg0)[0] = a;
    ((s16 *)arg0)[1] = b;
    ((s16 *)arg0)[2] = c;
    ((s16 *)arg0)[3] = d;
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

extern "C" void fn_800D8840(void *arg0, void *arg1) {
    s32 v3 = *(s32 *)((u8 *)arg1 + 0xC);
    s32 v4 = *(s32 *)((u8 *)arg1 + 0x10);
    f32 v2 = *(f32 *)((u8 *)arg1 + 8);
    s32 v1 = *(s32 *)((u8 *)arg1 + 4);
    s32 v0 = *(s32 *)arg1;
    *(s32 *)arg0 = v0;
    *(s32 *)((u8 *)arg0 + 4) = v1;
    *(f32 *)((u8 *)arg0 + 8) = v2;
    *(s32 *)((u8 *)arg0 + 0xC) = v3;
    *(s32 *)((u8 *)arg0 + 0x10) = v4;
}

extern "C" void fn_800D886C(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

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

extern "C" s32 fn_800D93BC(void *arg0) {
    register u32 x = *(u32 *)((u8 *)arg0 + 0x4C);
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
    s32 a = (x >> 0x14) & 0x3C0;
    s32 b = (x >> 0x17) & 0x1E0;
    s32 c = (x >> 0x18) & 1;
    s32 d = (x >> 0x12) & 0x3C;
    s32 e = (x >> 5) & 4;
    s32 f = (x >> 6) & 4;
    return a + b + c + y + d + e + f + (((x >> 0x18) & 0xF) * 0x14);
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
    u32 x = *(u32*)((u8*)arg0 + 0x4C);
    s32 base = *(s32*)((u8*)arg0 + 0x58);
    u32 a = (x >> 4) & 0xF;
    u32 b = (x >> 2) & 4;
    u32 c = (x >> 6) & 4;
    u32 d = (x >> 12) & 4;
    u32 e = (x >> 5) & 4;
    u32 f = (x >> 4) & 4;
    u32 g = (x >> 14) & 0x3C;
    u32 h = (x >> 9) & 0x1E0;
    u32 i = (x >> 1) & 4;
    return (((a * 0x14) + (g + h)) + ((b + c) + (d + e) + f)) + (base + i);
}

extern "C" s32 GetIndTexSRTAry__Q36nw4hbm3lyt8MaterialFv(void* arg0) {
    u32 x = *(u32*)((u8*)arg0 + 0x4C);
    s32 base = *(s32*)((u8*)arg0 + 0x58);
    u32 a = (x >> 4) & 0xF;
    u32 b = (x >> 2) & 4;
    u32 c = (x >> 6) & 4;
    u32 d = (x >> 12) & 4;
    u32 e = (x >> 5) & 4;
    u32 f = (x >> 4) & 4;
    u32 g = (x >> 14) & 0x3C;
    u32 h = (x >> 9) & 0x1E0;
    u32 i = (x >> 13) & 0x1C;
    u32 j = (x >> 3) & 4;
    u32 k = (x >> 1) & 4;
    u32 l = (x >> 18) & 0x1C;
    return (((a * 0x14) + (g + h)) + ((b + c) + (d + e) + f)) + (base + ((i + j) + k) + l);
}

extern "C" s32 fn_800D9524(void* arg0) {
    u32 x = *(u32*)((u8*)arg0 + 0x4C);
    s32 base = *(s32*)((u8*)arg0 + 0x58);
    u32 a = (x >> 12) & 3;
    u32 b = (x >> 4) & 0xF;
    u32 c = (x >> 6) & 4;
    u32 d = (x >> 5) & 4;
    u32 e = (x >> 12) & 4;
    u32 f = (x >> 9) & 0x1E0;
    u32 g = (x >> 14) & 0x3C;
    u32 h = (x >> 4) & 4;
    u32 i = (x >> 3) & 4;
    u32 j = (x >> 1) & 4;
    u32 k = (x >> 18) & 0x1C;
    return (((a + b) * 0x14) + c) + ((d + e) + ((h + i) + j)) + (f + g) + (k + base);
}

extern "C" char* strncpy(char*, const char*, unsigned int);
extern "C" char* fn_800D9584(char* arg0, const char* arg1) {
    return strncpy(arg0 + 4, arg1, 0x14);
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

extern "C" s32 fn_800DA094(void *arg0, s32 arg1, s32 arg2) {
    const char *data = lbl_8031F990;
    float matrix[12];
    s32 texture[8];
    float indirectMatrix[6];
    u8 texMatrices[10];
    int palette[3];
    u16 tev1[4];
    u16 tev2[4];
    u16 tev3[4];
    u8 usedIndirect[3];
    u8 alphaColor[4];
    u8 channelColor[4];
    u8 constant0[4];
    u8 constant1[4];
    u8 constant2[4];
    u8 constant3[4];
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    s32 sp30;                                       /* compiler-managed */
    
    
    
    s32 sp28;
       
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    s32 spC;
    s32 sp8;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f30;
    f32 temp_f31;
    s32 *var_r21_3;
    s32 *var_r22_2;
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
    s32 var_r21;
    s32 var_r21_2;
    s32 var_r23_3;
    s32 var_r23_5;
    s32 var_r24;
    s32 var_r25;
    s32 var_r26;
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
    u32 var_r23_6;
    u32 var_r23_7;
    u32 var_r24_2;
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
    u8 var_r28_2;
    u32 temp_r0_11;
    u32 temp_r0_13;
    u32 temp_r22;
    u32 temp_r3_5;
    u32 temp_r6_2;
    u32 temp_r6_6;
    u32 temp_r6_7;
    u32 temp_r7_2;
    u32 var_r21_4;
    u32 var_r21_5;
    u32 var_r22;
    u32 var_r27;
    u32 var_r28;

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
        MultipleAlpha__Q34nw4r3lyt6detailFQ34nw4r2ut5ColorUc(&alphaColor[0], &sp28, arg2);
        ((u8 *)&sp30)[0] = alphaColor[0];
        ((u8 *)&sp30)[1] = alphaColor[1];
        ((u8 *)&sp30)[2] = alphaColor[2];
        ((u8 *)&sp30)[3] = alphaColor[3];
        channelColor[0] = alphaColor[0];
        channelColor[1] = alphaColor[1];
        channelColor[2] = alphaColor[2];
        channelColor[3] = alphaColor[3];
        GXSetChanMatColor_Internal(4, &channelColor[0], alphaColor[2], alphaColor[1], alphaColor[0]);
        temp_cr0_eq = var_r25 == 0;
        var_r25 = 0;
        if ((temp_cr0_eq == 0) || ((u32) ((u32) sp30 + 0x10000) != 0xFFFFU)) {
            var_r25 = 1;
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
        if (var_r23 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x14U) & 0xF)) {
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
            goto loop_30;
        }
    }
    if (var_r24 != 0) {
        var_r23_2 = 0;
        temp_r21 = M2C_FIELD(arg0, u32 *, 0x58) + (((u32) M2C_FIELD(arg0, u32 *, 0x4C) >> 0x17U) & 0x1E0);
loop_36:
        if (var_r23_2 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x18U) & 0xF)) {
            if ((s32) (&texMatrices[0])[var_r23_2] != 0) {
                fn_800D7C54((int *)matrix, temp_r21 + (var_r23_2 * 0x14));
                GXLoadTexMtxImm((int *)matrix, (((var_r23_2 * 4) & 0x3FC) - var_r23_2) + 0x1E, 1);
            }
            var_r23_2 += 1;
            goto loop_36;
        }
    }
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1CU) != 0) {
        var_r28 = M2C_FIELD(arg0, u32 *, 0x58);
        var_r23_3 = 0;
        var_r24_2 = 0U;
loop_43:
        if (var_r24_2 < (u32) ((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1CU)) {
            texture[0] = M2C_FIELD(var_r28, s32 *, 0);
            texture[1] = M2C_FIELD(var_r28, s32 *, 4);
            texture[2] = M2C_FIELD(var_r28, s32 *, 8);
            texture[3] = M2C_FIELD(var_r28, s32 *, 0xC);
            texture[4] = M2C_FIELD(var_r28, s32 *, 0x10);
            texture[5] = M2C_FIELD(var_r28, s32 *, 0x14);
            temp_r4 = M2C_FIELD(var_r28, s32 *, 0x18);
            texture[6] = temp_r4;
            texture[7] = M2C_FIELD(var_r28, s32 *, 0x1C);
            if ((u32) (GXGetTexObjMipMap(&texture[0], temp_r4) - 8) <= 1U) {
                temp_r3_5 = (u32)GXGetTexObjHeight(&texture[0]);
                if (temp_r3_5 != 0) {
                    GXInitTlutObj(&palette[0], M2C_FIELD(temp_r3_5, s32 *, 8), M2C_FIELD(temp_r3_5, s32 *, 4), M2C_FIELD(temp_r3_5, u16 *, 0));
                    GXLoadTlut(&palette[0], var_r23_3);
                    GXInitTexObjTlut(&texture[0], var_r23_3);
                    var_r23_3 += 1;
                }
            }
            GXLoadTexObj(&texture[0], var_r24_2);
            var_r28 += 0x20;
            var_r24_2 += 1;
            goto loop_43;
        }
    }
    tev1[0] = M2C_FIELD(arg0, u16 *, 0x24);
    tev1[1] = M2C_FIELD(arg0, u16 *, 0x26);
    temp_r5_2 = M2C_FIELD(arg0, u16 *, 0x28);
    tev1[2] = temp_r5_2;
    tev1[3] = M2C_FIELD(arg0, u16 *, 0x2A);
    GXSetTevColorS10(1, &tev1[0], temp_r5_2);
    tev2[0] = M2C_FIELD(arg0, u16 *, 0x2C);
    tev2[1] = M2C_FIELD(arg0, u16 *, 0x2E);
    temp_r5_3 = M2C_FIELD(arg0, u16 *, 0x30);
    tev2[2] = temp_r5_3;
    tev2[3] = M2C_FIELD(arg0, u16 *, 0x32);
    GXSetTevColorS10(2, &tev2[0], temp_r5_3);
    tev3[0] = M2C_FIELD(arg0, u16 *, 0x34);
    tev3[1] = M2C_FIELD(arg0, u16 *, 0x36);
    temp_r5_4 = M2C_FIELD(arg0, u16 *, 0x38);
    tev3[2] = temp_r5_4;
    tev3[3] = M2C_FIELD(arg0, u16 *, 0x3A);
    GXSetTevColorS10(3, &tev3[0], temp_r5_4);
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
        var_r21_2 = 0;
        var_r23_4 = (u8 *)((((temp_r8 >> 0x18U) & 0xF) * 0x14) + (((temp_r8 >> 0x12U) & 0x3C) + ((temp_r8 >> 0x17U) & 0x1E0)) + (M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r8 >> 5U) & 4) + ((temp_r8 >> 6U) & 4))));
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
        var_r22 = ((temp_r9 >> 0xDU) & 0x1C) + (((temp_r9 >> 3U) & 4) + (((temp_r9 >> 4U) & 4) + (((temp_r9 >> 5U) & 4) + ((temp_r9 >> 0xCU) & 4)))) + (M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r9 >> 0x17U) & 0x1E0) + ((temp_r9 >> 0x12U) & 0x3C) + (((((temp_r9 >> 0x12U) & 3) + ((temp_r9 >> 0x18U) & 0xF)) * 0x14) + ((temp_r9 >> 6U) & 4))));
loop_55:
        if (var_r24_3 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 9U) & 0x1F)) {
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
            goto loop_55;
        }
        var_r25 = 1;
    } else {
        temp_r0_10 = temp_r0_4 >> 0x1CU;
        var_r24_4 = 0;
        switch (temp_r0_10) {                       /* irregular */
        case 0:
            GXSetTevOrder(0U, 0xFFU, 0xFFU, 4U);
            GXSetTevColorIn(0U, 0xF, 4, 0xA, 0xF);
            GXSetTevAlphaIn(0U, 7, 2, 5, 7);
            var_r25 = 1;
            var_r24_4 = 1;
            break;
        case 1:
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
            break;
        case 2:
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
            if (((s16) M2C_FIELD(arg0, u16 *, 0x24) == (s16) M2C_FIELD(&lbl_80565230, s16 *, 0)) && ((s16) M2C_FIELD(arg0, u16 *, 0x26) == (s16) M2C_FIELD(&lbl_80565230, s16 *, 2)) && ((s16) M2C_FIELD(arg0, u16 *, 0x28) == (s16) M2C_FIELD(&lbl_80565230, s16 *, 4)) && ((s16) M2C_FIELD(arg0, u16 *, 0x2A) == (s16) M2C_FIELD(&lbl_80565230, s16 *, 6))) {
                var_r5 = 1;
            }
            if (var_r5 != 0) {
                var_r3_2 = 0;
                if (((s16) M2C_FIELD(arg0, u16 *, 0x2C) == 0xFF) && ((s16) M2C_FIELD(arg0, u16 *, 0x2E) == 0xFF) && ((s16) M2C_FIELD(arg0, u16 *, 0x30) == 0xFF) && ((s16) M2C_FIELD(arg0, u16 *, 0x32) == 0xFF)) {
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
        default:
            var_r21_3 = (s32 *)(data + 0x490);
            var_r22_2 = (s32 *)(data + 0x4B0);
            var_r28_2 = 0;
loop_69:
            if (var_r28_2 < (u32) ((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1CU)) {
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
                goto loop_69;
            }
            goto block_70;
        }
        var_r22_3 = 0;
loop_87:
        if (var_r22_3 < var_r24_4) {
            GXSetTevColorOp(var_r22_3, 0, 0, 0, 1, 0);
            GXSetTevAlphaOp(var_r22_3, 0, 0, 0, 1, 0);
            GXSetTevDirect(var_r22_3);
            GXSetTevSwapMode(var_r22_3, 0, 0);
            var_r22_3 += 1;
            goto loop_87;
        }
        GXSetNumTevStages(var_r24_4);
    }
    if (var_r23_5 != 0) {
        temp_r9_3 = M2C_FIELD(arg0, u32 *, 0x4C);
        var_r28_3 = &usedIndirect[0];
        var_r23_6 = 0U;
        temp_f30 = lbl_80560E8C;
        var_r21_4 = ((temp_r9_3 >> 0xCU) & 4) + ((temp_r9_3 >> 5U) & 4) + (((temp_r9_3 >> 4U) & 4) + ((temp_r9_3 >> 6U) & 4)) + ((((temp_r9_3 >> 0x18U) & 0xF) * 0x14) + (((temp_r9_3 >> 0x12U) & 0x3C) + ((temp_r9_3 >> 0x17U) & 0x1E0))) + (M2C_FIELD(arg0, u32 *, 0x58) + (((temp_r9_3 >> 0xDU) & 0x1C) + ((temp_r9_3 >> 3U) & 4)));
loop_94:
        if (var_r23_6 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x12U) & 3)) {
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
                fn_800D7D5C((void *)(var_r23_6 + 1), &indirectMatrix[0]);
            }
            var_r28_3 += 1;
            var_r21_4 += 0x14;
            var_r23_6 += 1;
            goto loop_94;
        }
    }
    GXSetNumIndStages(((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0xFU) & 7);
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0xFU) & 7) {
        temp_r9_4 = M2C_FIELD(arg0, u32 *, 0x4C);
        var_r23_7 = 0U;
        var_r21_5 = ((temp_r9_4 >> 3U) & 4) + (((temp_r9_4 >> 0xCU) & 4) + ((temp_r9_4 >> 5U) & 4) + (((temp_r9_4 >> 4U) & 4) + ((temp_r9_4 >> 6U) & 4))) + (M2C_FIELD(arg0, u32 *, 0x58) + ((((temp_r9_4 >> 0x18U) & 0xF) * 0x14) + (((temp_r9_4 >> 0x12U) & 0x3C) + ((temp_r9_4 >> 0x17U) & 0x1E0))));
loop_98:
        if (var_r23_7 < (u32) (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0xFU) & 7)) {
            GXSetIndTexOrder(var_r23_7, M2C_FIELD(var_r21_5, u8 *, 0), M2C_FIELD(var_r21_5, u8 *, 1));
            GXSetIndTexCoordScale(var_r23_7, M2C_FIELD(var_r21_5, u8 *, 2), M2C_FIELD(var_r21_5, u8 *, 3));
            var_r21_5 += 4;
            var_r23_7 += 1;
            goto loop_98;
        }
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
        GXSetBlendMode(*(u8 *)(temp_r3_9 + temp_r0_13), M2C_FIELD(temp_r6_7, u8 *, 1), M2C_FIELD(temp_r6_7, u8 *, 2), M2C_FIELD(temp_r6_7, u8 *, 3), (void *)temp_r7_2, temp_r8_2);
    } else {
        GXSetBlendMode(1U, 4U, 5U, 0xFU, 0, 0);
    }
    var_r3 = 0;
    if ((var_r25 != 0) && (var_r26 != 0)) {
        var_r3 = 1;
    }
    return var_r3;
}

extern "C" void fn_800DAFA8(void* arg0, void* arg1) {
    void** vtable = *(void***)arg1;
    ((void (*)(void*, void*))vtable[5])(arg1, arg0);
}

extern "C" void fn_800DAFC4(void* arg0, u32 arg1) {
    extern const char lbl_8031F1FC[];
    extern const char lbl_8031F1D8[];
    void* end = (u8*)arg0 + 0x1C;
    void* node = *(void**)((u8*)arg0 + 0x1C);
    do {
        void* next = *(void**)node;
        if (arg1 == 0 || *(u32*)((u8*)node + 8) == arg1) {
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
            void* it = node;
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator((u8*)arg0 + 0x18, &it);
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
            *(u32*)((u8*)node + 8) = 0;
            *(u16*)((u8*)node + 0xC) = 0;
        }
        node = next;
    } while (node != end);
}

extern "C" void fn_800DB084(void* arg0) {
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(int); };
    ((Obj*)arg0)->v3(0);
}

extern "C" void AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink(void* arg0, void* arg1) {
    extern const char lbl_8031FF54[];
    extern const char lbl_8031FF30[];
    register void* iterator = (u8*)arg0 + 0x1C;
    void* slot;
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF54, 0x233, lbl_8031FF30);
    slot = iterator;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8*)arg0 + 0x18, &slot, arg1);
}

extern "C" void fn_800D4F98(void*);
extern "C" void fn_800DB1E8(void* arg0, void* unused, s32 arg2) {
    void* temp = (*(void* (**)(void*))(*(u32*)arg0 + 0x20))(arg0);
    if (temp != 0) *(u8*)((u8*)temp + 0xE) = (u8)(arg2 == 0);
}

extern "C" s32 fn_80128668();
extern "C" void fn_800D4F98(void*);
extern "C" s32 fn_800DB398(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
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
void fn_800DB76C(f32* out, void* self, f32* arg2) {
    f32 c = lbl_80560EA8;
    f32* pos = (f32*)GetVtxPos__Q34nw4r3lyt4PaneCFv(self);
    f32 y = pos[14];
    f32 x = pos[0];
    f32 ny = y + arg2[1];
    f32 nx = x + arg2[0];
    out[0] = x;
    out[1] = y;
    out[2] = nx;
    out[3] = ny;
    if ((pos[16] - y) < c) {
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
#pragma pop
extern "C" void Draw__Q36nw4hbm3lyt4PaneFRCQ36nw4hbm3lyt8DrawInfo(void* self,void* info){ extern const char lbl_8031E8FC[]; extern const char lbl_8031E8D8[]; if(*((u8*)self+0xCF)&1){ struct Obj{virtual void a0();virtual void a1();virtual void a2();virtual void a3();virtual void a4();}; ((Obj*)self)->a4(); void* end=(u8*)self+0x14; void* node=*(void**)((u8*)self+0x14); do { if(!node)Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC,0x23D,lbl_8031E8D8); struct Child{virtual void a0();virtual void a1();virtual void a2();virtual void a3();virtual void Draw(void*);}; ((Child*)((u8*)node-4))->Draw(info); node=*(void**)node;}while(node!=end); } }

extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*, void**);
extern "C" void DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(void*, void*, void*);
extern "C" void* GetVtxPos__Q34nw4r3lyt4PaneCFv(void*);
extern "C" void DrawSelf__Q36nw4hbm3lyt4PaneFRCQ36nw4hbm3lyt8DrawInfo(void* self, void* info) {
    if (*(s32*)((u8*)self + 0xC) != 0 && ((*(u8*)((u8*)info + 0x50) >> 3) & 1)) {
        void (**vtable)(void) = *(void (***)(void))self;
        vtable[0x60 / 4]();
        u32 color = 0xFF00FF;
        void* pos = GetVtxPos__Q34nw4r3lyt4PaneCFv(self);
        void* args[2];
        args[0] = pos;
        args[1] = (u8*)self + 0x4C;
        DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(args, args[1], &color);
    }
}

extern "C" void Animate__Q36nw4hbm3lyt4PaneFUl(void* self, u32 flags) {
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); };
    ((Obj*)self)->v4();
    if ((*(u8*)((u8*)self + 0xCF) & 1) == 0 && (flags & 1) == 0) {
        void* end = (u8*)self + 0x14;
        void* node = *(void**)((u8*)self + 0x14);
        while (node != end) {
            extern const char lbl_8031E8FC[];
            extern const char lbl_8031E8D8[];
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
            void* obj = (u8*)node - 4;
            void (**vt)(void) = *(void (***)(void))obj;
            ((void (*)(void*, u32))vt[7])(obj, flags);
            node = *(void**)node;
        }
    }
}

extern "C" void BindAnimation__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformb(void* self, void* transform, bool flag) {
    extern const char lbl_8031FF90[];
    extern const char lbl_803200C8[];
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(void*, bool); };
    if (!transform) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031FF90, 0x254, lbl_803200C8);
    ((Obj*)transform)->v2(self, flag);
}

extern "C" void UnbindAnimation__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransformb(void* self, void* transform, bool flag) {
    struct Node { Node* next; Node* prev; };
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); };
    extern const char lbl_8031E8FC[];
    extern const char lbl_8031E8D8[];
    ((Obj*)self)->v18();
    if (flag) {
        Node* end=(Node*)((char*)self+0x14); Node* node=*(Node**)((char*)self+0x14);
        while(node!=end) { if(!node) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC,0x23d,lbl_8031E8D8);
        (*(void (**)(void*,void*,bool))(*(char**)node-4+0x48))((char*)node-4,transform,flag); node=node->next; }
    }
}

extern "C" void fn_800DC204(void* self, void* arg) {
    struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(int, void*); };
    ((Obj*)self)->v16(0, arg);
}

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

extern "C" int fcmpgt(f32, f32);
extern "C" void PSMTXConcat(const f32*, const f32*, f32*);
extern "C" void PSMTXCopy(const f32*, f32*);
extern "C" void GXLoadPosMtxImm(const f32*, u32);
extern "C" void GXSetCurrentMtx(u32);
extern "C" void LoadMtx__Q34nw4r3lyt4PaneFRCQ34nw4r3lyt8DrawInfo(void* self, void* info) {
    extern f32 lbl_80560EA8;
    f32 mtx[12];
    u8* ip = (u8*)info;
    u8* sp = (u8*)self;
    if ((ip[0x50] >> 7) & 1) {
        PSMTXConcat((f32*)(ip + 4), (f32*)(sp + 0x84), mtx);
        if (fcmpgt((*(f32*)(ip + 0x40) - *(f32*)(ip + 0x38)), lbl_80560EA8)) {
            mtx[3] = -mtx[3];
            mtx[7] = -mtx[7];
            mtx[11] = -mtx[11];
        }
        GXLoadPosMtxImm(mtx, 0);
    } else {
        if (fcmpgt((*(f32*)(ip + 0x40) - *(f32*)(ip + 0x38)), lbl_80560EA8)) {
            PSMTXCopy((f32*)(sp + 0x84), mtx);
            mtx[3] = -mtx[3];
            mtx[7] = -mtx[7];
            mtx[11] = -mtx[11];
            GXLoadPosMtxImm(mtx, 0);
        } else {
            GXLoadPosMtxImm((f32*)(sp + 0x84), 0);
        }
    }
    GXSetCurrentMtx(0);
}

extern "C" f32 lbl_80560EC0;
extern "C" void* GetVtxPos__Q34nw4r3lyt4PaneCFv(void* self) {
    f32 x = lbl_80560EA8;
    f32 y = lbl_80560EA8;
    s32 n = *(s8*)((u8*)self + 0xCC);
    s32 r = n % 3;
    switch (r) {
    case 1:
        x = -*(f32*)((u8*)self + 0x4C) * lbl_80560EC0;
        break;
    case 2:
        x = -*(f32*)((u8*)self + 0x4C);
        break;
    }
    switch (n / 3) {
    case 1:
        y = -*(f32*)((u8*)self + 0x50) * lbl_80560EC0;
        break;
    case 2:
        y = -*(f32*)((u8*)self + 0x50);
        break;
    }
    return &x;
}

extern "C" s32 fn_800DC6DC(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

