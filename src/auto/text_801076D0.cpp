#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/gki/common/gki.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
namespace nw4hbm { namespace ut { struct List; void List_Init(List*, unsigned short); void* List_GetNth(const List*, unsigned short); void* List_GetNext(const List*, const void*); class CharWriter { public: void* pad[23]; void* font; void* GetFont() const; }; } }

extern "C" const char lbl_80328828[];
extern "C" const char lbl_80328834[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" u8 fn_8010A33C(void);
extern "C" s32 fn_80109040(s32, s32);
extern "C" s32 fn_80128668(void);
extern "C" void* fn_80108FFC(void*, const void*);
extern "C" const char lbl_803290E8[];
extern "C" const char lbl_803293A8[];
extern "C" const char lbl_80329400[];
extern "C" const char lbl_80329140[];
extern "C" void* Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void* arg0, void** arg1, void* arg2) {
    extern const char lbl_80328680[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    const char* file = lbl_80328680;
    void* node;
    void* prev;
    if (arg2 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x4A, file + 0x34);
    node = *arg1;
    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x4C, file + 0xFC);
    prev = *(void**)((char*)node + 4);
    if (prev == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x4F, file + 0x124);
    if (*(void**)arg2 != 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x51, file + 0x150);
    if (*(void**)((char*)arg2 + 4) != 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x52, file + 0x17C);
    *(void**)arg2 = node;
    *(void**)((char*)arg2 + 4) = prev;
    *(void**)((char*)node + 4) = arg2;
    *(void**)prev = arg2;
    ++*(int*)arg0;
    return arg2;
}

extern "C" void* Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(int* arg0, void* arg1) {
    extern const char lbl_80328680[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    const char* file = lbl_80328680;
    void* next;
    void* prev;
    if (*arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x60, file + 0x10);
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x61, file + 0x34);
    if (arg1 == (char*)arg0 + 4) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x62, file + 0x58);
    next = *(void**)arg1;
    prev = *(void**)((char*)arg1 + 4);
    if (next == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x65, file + 0x80);
    *(void**)((char*)next + 4) = prev;
    if (prev == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x67, file + 0xA8);
    *(void**)prev = next;
    --*arg0;
    *(void**)arg1 = 0;
    *(void**)((char*)arg1 + 4) = 0;
    return next;
}

void nw4hbm::ut::List_Init(nw4hbm::ut::List *list, unsigned short size) {
    if (list == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0x29, lbl_80328834);
    *(unsigned short *)((char *)list + 0xA) = size;
    *(int *)list = 0;
    *(int *)((char *)list + 4) = 0;
    *(unsigned short *)((char *)list + 8) = 0;
}

void* nw4hbm::ut::List_GetNext(const nw4hbm::ut::List* list, const void* item) {
    if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0xF5, lbl_80328834);
    if (item == 0) return *(void**)list;
    return *(void**)((char*)item + *(unsigned short*)((char*)list + 0xA) + 4);
}

extern "C" const char lbl_80328828[];
extern "C" const char lbl_80328834[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
void* nw4hbm::ut::List_GetNth(const nw4hbm::ut::List* list, unsigned short index) {
    unsigned int i = 0; void* node = 0;
    if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0x129, lbl_80328834);
    do {
        if (i == index) return node;
        i++;
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0xf5, lbl_80328834);
        if (node == 0) node = *(void**)list;
        else node = *(void**)((char*)node + *(unsigned short*)((char*)list + 0xa) + 4);
    } while (node != 0);
    return 0;
}

extern "C" void* fn_80107FE4(void* arg0, const void* arg1) {
    fn_80108FFC(arg0, arg1);
    *(const char**)arg0 = lbl_803290E8;
    return arg0;
}

extern "C" void* memcpy(void*, const void*, unsigned long);
#pragma push
#pragma scheduling off
extern "C" void* fn_80108FFC(void* arg0, const void* arg1) {
    struct Struct12 {
        u32 a, b, c;
    };
    *(const void* volatile*)arg0 = lbl_80329400;
    *(Struct12*)((char*)arg0 + 4) = *(const Struct12*)(const void*)lbl_80329140;
    *(const void**)arg0 = lbl_803293A8;
    *(u32*)((char*)arg0 + 0x10) = 0;
    *(u32*)((char*)arg0 + 0x14) = 0;
    return arg0;
}
#pragma pop
extern "C" s32 fn_80109040(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" u8 fn_8010A33C(void) {
    return 2;
}

extern "C" s8 fn_8010B2BC(void *arg0) {
    struct V { virtual u32 a0()=0; virtual u32 a1()=0; virtual u32 a2()=0; virtual u32 a3()=0; virtual u32 a4()=0; virtual u32 a5()=0; virtual u32 a6()=0; virtual u32 a7()=0; virtual u32 a8()=0; virtual u32 a9()=0; virtual u32 a10()=0; virtual u32 a11()=0; virtual u32 a12()=0; virtual u32 a13()=0; virtual u32 a14()=0; virtual u32 a15()=0; virtual u32 a16()=0; virtual u32 a17()=0; virtual u32 f()=0; };
    u32 value = ((V *)arg0)->f();
    volatile u8 a=(u8)(value>>24), b=(u8)(value>>16), c=(u8)(value>>8);
    return (s8)c;
}

extern "C" const char lbl_80329140[];
extern "C" u16 FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(void*, void*, u16);
u32 GetCharWidths__Q46nw4hbm2ut6detail11ResFontBaseCFUs(void *self, u16 code) {
    u8 *info, *map, *width, *entry;
    u16 glyph;
    if (!self) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x1E2,lbl_80329140+0xF0,self);
    info=*(u8**)((char*)self+0x14);
    if (!info) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x1E3,lbl_80329140+0x128);
    if (!self) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x1F6,lbl_80329140+0xF0,self);
    if (!info) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x1F7,lbl_80329140+0x128);
    map=*(u8**)(info+0x10);
    while(map && (code<*(u16*)map || code>*(u16*)(map+2))) map=*(u8**)(map+8);
    glyph=map ? FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(self,map,code) : 0xFFFF;
    if(glyph==0xFFFF) glyph=*(u16*)(info+2);
    if (!self) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x267,lbl_80329140+0xF0,self);
    if (!info) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x268,lbl_80329140+0x128);
    width=*(u8**)(info+0xC);
    while(width && (glyph<*(u16*)width || glyph>*(u16*)(width+2))) width=*(u8**)(width+4);
    if(width) entry=width+8+5*(glyph-*(u16*)width);
    else entry=info+4;
    return ((u32)*(u16*)(entry+4)<<16) | ((u32)entry[6]<<8);
}

#pragma push
#pragma use_lmw_stmw off
void GetGlyphFromIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPQ36nw4hbm2ut5GlyphUs(void *self, void *glyph, u16 index) {
 u32 ptr=(u32)self, idx=index, width,height,x,y; u8 *info,*font,*map,*entry; u32 r4,r5,r6,r7,r8,r9,r10;
 r5=r6=r7=r8=r9=r10=1;
 if((u32)((ptr&0xFF000000)+0x80000000)!=0&&(u32)((ptr&0xFF800000)+0x7F000000)!=0)r10=0;
 if(r10==0&&(u32)((ptr&0xF8000000)+0x70000000)!=0)r9=0;
 if(r9==0&&(u32)((ptr&0xFF000000)+0x40000000)!=0)r8=0;
 if(r8==0&&(u32)((ptr&0xFF800000)+0x3F000000)!=0)r7=0;
 if(r7==0&&(u32)((ptr&0xF8000000)+0x30000000)!=0)r6=0;
 if(r6==0&&(u32)((ptr&0xFFFFC000)+0x20000000)!=0)r5=0;
 if(r5==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x29F,lbl_80329140+0xF0,self);
 info=*(u8**)((char*)self+0x14); ptr=(u32)info; r4=r5=r7=r8=r9=r10=1;
 if((u32)((ptr&0xFF000000)+0x80000000)!=0&&(u32)((ptr&0xFF800000)+0x7F000000)!=0)r10=0;
 if(r10==0&&(u32)((ptr&0xF8000000)+0x70000000)!=0)r9=0;
 if(r9==0&&(u32)((ptr&0xFF000000)+0x40000000)!=0)r8=0;
 if(r8==0&&(u32)((ptr&0xFF800000)+0x3F000000)!=0)r7=0;
 if(r7==0&&(u32)((ptr&0xF8000000)+0x30000000)!=0)r5=0;
 if(r5==0&&(u32)((ptr&0xFFFFC000)+0x20000000)!=0)r4=0;
 if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x2A0,lbl_80329140+0x128);
 font=*(u8**)(info+8); width=*(u16*)(font+0xC); height=*(u16*)(font+0xE);
 x=*(u8*)font+1; y=font[1]+1;
 *(u32*)glyph=*(u32*)(font+0x14)+(idx/(width*height)) * *(u32*)(font+4);
 x=((idx%(width*height))%width)*x; y=((idx%(width*height))/width)*y;
 ptr=(u32)self;
 if((u32)((ptr&0xFF000000)+0x80000000)==0||(u32)((ptr&0xFF800000)+0x7F000000)==0||(u32)((ptr&0xF8000000)+0x70000000)==0||(u32)((ptr&0xFF000000)+0x40000000)==0||(u32)((ptr&0xFF800000)+0x3F000000)==0||(u32)((ptr&0xF8000000)+0x30000000)==0||(u32)((ptr&0xFFFFC000)+0x20000000)==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x267,lbl_80329140+0xF0,self);
 info=*(u8**)((char*)self+0x14); ptr=(u32)info; r4=r5=r7=r8=r9=r10=1;
 if((u32)((ptr&0xFF000000)+0x80000000)!=0&&(u32)((ptr&0xFF800000)+0x7F000000)!=0)r10=0;
 if(r10==0&&(u32)((ptr&0xF8000000)+0x70000000)!=0)r9=0;
 if(r9==0&&(u32)((ptr&0xFF000000)+0x40000000)!=0)r8=0;
 if(r8==0&&(u32)((ptr&0xFF800000)+0x3F000000)!=0)r7=0;
 if(r7==0&&(u32)((ptr&0xF8000000)+0x30000000)!=0)r5=0;
 if(r5==0&&(u32)((ptr&0xFFFFC000)+0x20000000)!=0)r4=0;
 if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x268,lbl_80329140+0x128);
 map=*(u8**)(info+0xC); while(map&&(index<*(u16*)map||index>*(u16*)(map+2)))map=*(u8**)(map+4);
 if(map){entry=map+8+5*(index-*(u16*)map);ptr=(u32)map;r4=r5=r6=r7=r8=r9=1;
 if((u32)((ptr&0xFF000000)+0x80000000)!=0&&(u32)((ptr&0xFF800000)+0x7F000000)!=0)r9=0;
 if(r9==0&&(u32)((ptr&0xF8000000)+0x70000000)!=0)r8=0;
 if(r8==0&&(u32)((ptr&0xFF000000)+0x40000000)!=0)r7=0;
 if(r7==0&&(u32)((ptr&0xFF800000)+0x3F000000)!=0)r6=0;
 if(r6==0&&(u32)((ptr&0xF8000000)+0x30000000)!=0)r5=0;
 if(r5==0&&(u32)((ptr&0xFFFFC000)+0x20000000)!=0)r4=0;
 if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x28B,lbl_80329140+0x1E4,map);
 }else entry=info+4;
 ((u8*)glyph)[4]=entry[0];((u8*)glyph)[5]=entry[1];((u8*)glyph)[6]=entry[2];((u8*)glyph)[7]=font[1];
 *(u32*)((char*)glyph+8)=*(u16*)(font+0xA);*(u16*)((char*)glyph+0xC)=*(u16*)(font+0x10);*(u16*)((char*)glyph+0xE)=*(u16*)(font+0x12);
 *(u16*)((char*)glyph+0x10)=x+1;*(u16*)((char*)glyph+0x12)=y+1;
}
#pragma pop
extern "C" void lbl_8032951C(void);
extern "C" void fn_8010C7DC(void **arg0) {
    *arg0 = (void *)&lbl_8032951C;
}

extern "C" s32 fn_8010C7EC(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" s32 fn_8010C82C(s32 arg0, s32 arg1, void *arg2) {
 extern const char lbl_80329458[]; extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*,int,const char*,...);
 extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(s32), fn_8010D9E4(s32);
 extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(s32), IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
 extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32); extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
 s32 p=(s32)arg2, hi=p&0xFF000000, r4,r5,r6,r7,r8,r9;
 if(arg1>=32) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x55,lbl_80329458+0x18);
 r4=r5=r6=r7=r8=r9=1;
 if ((u32)(hi+0x80000000)<1U && (u32)((p&0xFF800000)+0x7F000000)<1U) r4=0;
 if(r4==0 && (u32)((p&0xF8000000)+0x70000000)<1U) r5=0;
 if(r5==0 && (u32)(hi+0x40000000)<1U) r6=0;
 if(r6==0 && (u32)((p&0xFF800000)+0x3F000000)<1U) r7=0;
 if(r7==0 && (u32)((p&0xF8000000)+0x30000000)<1U) r8=0;
 if(r8==0 && (u32)((p&0xFFFFC000)+0x20000000)<1U) r9=0;
 if(r9==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x56,lbl_80329458+0x40,arg2);
 if(arg1==10) {
 r5=0;
 if((u32)(hi+0x80000000)<1U || (u32)((p&0xFF800000)+0x7F000000)<1U || (u32)((p&0xF8000000)+0x70000000)<1U || (u32)(hi+0x40000000)<1U || (u32)((p&0xFF800000)+0x3F000000)<1U || (u32)((p&0xF8000000)+0x30000000)<1U || (u32)((p&0xFFFFC000)+0x20000000)<1U) r5=1;
 if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xC3,lbl_80329458+0x40,arg2);
 s32 obj=*(s32*)p; f32 y=*(f32*)(p+8), w=fn_8010D9E4(obj);
 SetCursor__Q36nw4hbm2ut10CharWriterFff(obj,y,GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj)+w); return 3;
 }
 if(arg1==9) {
 r5=0;
 if((u32)(hi+0x80000000)<1U || (u32)((p&0xFF800000)+0x7F000000)<1U || (u32)((p&0xF8000000)+0x70000000)<1U || (u32)(hi+0x40000000)<1U || (u32)((p&0xFF800000)+0x3F000000)<1U || (u32)((p&0xF8000000)+0x30000000)<1U || (u32)((p&0xFFFFC000)+0x20000000)<1U) r5=1;
 if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xD3,lbl_80329458+0x40,arg2);
 s32 obj=*(s32*)p, font=GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(obj);
 if(font>0) { f32 fw=IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(obj)?GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(obj):GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(obj);
 f32 y=*(f32*)(p+8), step=(f32)font*fw, width=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj)-y;
 s32 n=(s32)(width/step); SetCursorX__Q36nw4hbm2ut10CharWriterFf(obj,y+step*(f32)(n+1)); } return 1;
 } return 0;
}

extern "C" s32 fn_8010CBAC(void *self, void *arg0, s32 arg1, void *arg2) {
 extern const char lbl_80329458[];
 extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*,int,const char*,...);
 extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(s32), fn_8010D9E4(s32);
 extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(s32), IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
 extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32); extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
 s32 p=(s32)arg0, hi=p&0xFF000000, r4,r5,r6,r7,r8,r9,r10;
 r5=r6=r7=r8=r9=r10=1;
 if((u32)(hi+0x80000000)!=0 && (u32)((p&0xFF800000)+0x7F000000)!=0) r10=0;
 if(r10==0 && (u32)((p&0xF8000000)+0x70000000)!=0) r9=0;
 if(r9==0 && (u32)(hi+0x40000000)!=0) r8=0;
 if(r8==0 && (u32)((p&0xFF800000)+0x3F000000)!=0) r7=0;
 if(r7==0 && (u32)((p&0xF8000000)+0x30000000)!=0) r6=0;
 if(r6==0 && (u32)((p&0xFFFFC000)+0x20000000)!=0) r5=0;
 if(r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x84,lbl_80329458+0x78,arg0);
 if(arg1>=32) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x85,lbl_80329458+0x18);
 p=(s32)arg2; hi=p&0xFF000000; r4=r5=r6=r7=r8=r9=1;
 if((u32)(hi+0x80000000)!=0 && (u32)((p&0xFF800000)+0x7F000000)!=0) r9=0;
 if(r9==0 && (u32)((p&0xF8000000)+0x70000000)!=0) r8=0;
 if(r8==0 && (u32)(hi+0x40000000)!=0) r7=0;
 if(r7==0 && (u32)((p&0xFF800000)+0x3F000000)!=0) r6=0;
 if(r6==0 && (u32)((p&0xF8000000)+0x30000000)!=0) r5=0;
 if(r5==0 && (u32)((p&0xFFFFC000)+0x20000000)!=0) r4=0;
 if(r4==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x86,lbl_80329458+0x40,arg2);
 s32 obj=*(s32*)p;
 if(arg1==10) {
  *(f32*)((char*)arg0+8)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj);
  *(f32*)((char*)arg0+4)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj);
  r5=0; if((u32)(hi+0x80000000)==0 || (u32)((p&0xFF800000)+0x7F000000)==0 || (u32)((p&0xF8000000)+0x70000000)==0 || (u32)(hi+0x40000000)==0 || (u32)((p&0xFF800000)+0x3F000000)==0 || (u32)((p&0xF8000000)+0x30000000)==0 || (u32)((p&0xFFFFC000)+0x20000000)==0) r5=1;
  if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xC3,lbl_80329458+0x40,arg2);
  s32 o=*(s32*)p; f32 y=*(f32*)(p+8), w=fn_8010D9E4(o); SetCursor__Q36nw4hbm2ut10CharWriterFff(o,y,GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(o)+w);
  f32 left=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj);
  *(f32*)arg0=left; f32 right=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj)+GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(*(s32*)p);
  f32 t=*(f32*)((char*)arg0+4), b=*(f32*)((char*)arg0+8), x=right-t, z=b-left;
  *(f32*)((char*)arg0+4)=x>=0?t:right; *(f32*)arg0=z>=0?left:b; *(f32*)((char*)arg0+8)=z>=0?b:left; *(f32*)((char*)arg0+12)=x>=0?right:t; return 3;
 }
 if(arg1==9) {
  r5=0; if((u32)(hi+0x80000000)==0 || (u32)((p&0xFF800000)+0x7F000000)==0 || (u32)((p&0xF8000000)+0x70000000)==0 || (u32)(hi+0x40000000)==0 || (u32)((p&0xFF800000)+0x3F000000)==0 || (u32)((p&0xF8000000)+0x30000000)==0 || (u32)((p&0xFFFFC000)+0x20000000)==0) r5=1;
  if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xD3,lbl_80329458+0x40,arg2);
  s32 font=GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(obj);
  if(font>0) { f32 fw=IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(obj)?GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(obj):GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(obj); f32 y=*(f32*)(p+8), step=(f32)font*fw, width=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj)-y; s32 n=(s32)(width/step); SetCursorX__Q36nw4hbm2ut10CharWriterFf(obj,y+step*(f32)(n+1)); }
  *(f32*)((char*)arg0+8)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj); *(f32*)((char*)arg0+4)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj);
  f32 t=*(f32*)((char*)arg0+4), left=*(f32*)arg0, right=t+GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(obj), b=*(f32*)((char*)arg0+8), y=right-t, x=b-left;
  *(f32*)arg0=x>=0?left:b; *(f32*)((char*)arg0+8)=x>=0?b:left; *(f32*)((char*)arg0+4)=y>=0?t:right; *(f32*)((char*)arg0+12)=y>=0?right:t; return 1;
 }
 return 0;
}

extern "C" void lbl_80329508(void);
extern "C" void fn_8010D0E0(void **arg0) {
    *arg0 = (void *)&lbl_80329508;
}

extern "C" s32 fn_8010D0F0(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" s32 fn_8010D4B0(void *self, void *arg0, s32 arg1, void *arg2) {
 extern const char lbl_80329458[];
 extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*,int,const char*,...);
 extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(s32), fn_80111C10(s32);
 extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_801120E8(s32), IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
 extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32); extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
 s32 p=(s32)arg2, hi=p&0xFF000000, r4,r5,r6,r7,r8,r9,r10;
 r5=r6=r7=r8=r9=r10=1;
 if((u32)(hi+0x80000000)!=0 && (u32)((p&0xFF800000)+0x7F000000)!=0) r10=0;
 if(r10==0 && (u32)((p&0xF8000000)+0x70000000)!=0) r9=0;
 if(r9==0 && (u32)(hi+0x40000000)!=0) r8=0;
 if(r8==0 && (u32)((p&0xFF800000)+0x3F000000)!=0) r7=0;
 if(r7==0 && (u32)((p&0xF8000000)+0x30000000)!=0) r6=0;
 if(r6==0 && (u32)((p&0xFFFFC000)+0x20000000)!=0) r5=0;
 if(r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x84,lbl_80329458+0x78,arg0);
 if(arg1>=32) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x85,lbl_80329458+0x18);
 p=(s32)arg2; hi=p&0xFF000000; r4=r5=r6=r7=r8=r9=1;
 if((u32)(hi+0x80000000)!=0 && (u32)((p&0xFF800000)+0x7F000000)!=0) r9=0;
 if(r9==0 && (u32)((p&0xF8000000)+0x70000000)!=0) r8=0;
 if(r8==0 && (u32)(hi+0x40000000)!=0) r7=0;
 if(r7==0 && (u32)((p&0xFF800000)+0x3F000000)!=0) r6=0;
 if(r6==0 && (u32)((p&0xF8000000)+0x30000000)!=0) r5=0;
 if(r5==0 && (u32)((p&0xFFFFC000)+0x20000000)!=0) r4=0;
 if(r4==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x86,lbl_80329458+0x40,arg2);
 s32 obj=*(s32*)p;
 if(arg1==10) {
  *(f32*)((char*)arg0+8)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj);
  *(f32*)((char*)arg0+4)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj);
  r5=0; if((u32)(hi+0x80000000)==0 || (u32)((p&0xFF800000)+0x7F000000)==0 || (u32)((p&0xF8000000)+0x70000000)==0 || (u32)(hi+0x40000000)==0 || (u32)((p&0xFF800000)+0x3F000000)==0 || (u32)((p&0xF8000000)+0x30000000)==0 || (u32)((p&0xFFFFC000)+0x20000000)==0) r5=1;
  if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xC3,lbl_80329458+0x40,arg2);
  s32 o=*(s32*)p; f32 y=*(f32*)(p+8), w=fn_80111C10(o); SetCursor__Q36nw4hbm2ut10CharWriterFff(o,y,GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(o)+w);
  f32 left=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj);
  *(f32*)arg0=left; f32 right=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj)+GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(*(s32*)p);
  f32 t=*(f32*)((char*)arg0+4), b=*(f32*)((char*)arg0+8), x=right-t, z=b-left;
  *(f32*)((char*)arg0+4)=x>=0?t:right; *(f32*)arg0=z>=0?left:b; *(f32*)((char*)arg0+8)=z>=0?b:left; *(f32*)((char*)arg0+12)=x>=0?right:t; return 3;
 }
 if(arg1==9) {
  r5=0; if((u32)(hi+0x80000000)==0 || (u32)((p&0xFF800000)+0x7F000000)==0 || (u32)((p&0xF8000000)+0x70000000)==0 || (u32)(hi+0x40000000)==0 || (u32)((p&0xFF800000)+0x3F000000)==0 || (u32)((p&0xF8000000)+0x30000000)==0 || (u32)((p&0xFFFFC000)+0x20000000)==0) r5=1;
  if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xD3,lbl_80329458+0x40,arg2);
  s32 font=GetFont__Q36nw4hbm2ut10CharWriterCFv_801120E8(obj);
  if(font>0) { f32 fw=IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(obj)?GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(obj):GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(obj); f32 y=*(f32*)(p+8), step=(f32)font*fw, width=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj)-y; s32 n=(s32)(width/step); SetCursorX__Q36nw4hbm2ut10CharWriterFf(obj,y+step*(f32)(n+1)); }
  *(f32*)((char*)arg0+8)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj); *(f32*)((char*)arg0+4)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj);
  f32 t=*(f32*)((char*)arg0+4), left=*(f32*)arg0, right=t+GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(obj), b=*(f32*)((char*)arg0+8), y=right-t, x=b-left;
  *(f32*)arg0=x>=0?left:b; *(f32*)((char*)arg0+8)=x>=0?b:left; *(f32*)((char*)arg0+4)=y>=0?t:right; *(f32*)((char*)arg0+12)=y>=0?right:t; return 1;
 }
 return 0;
}

extern "C" f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32);
extern "C" s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern "C" f32 fn_8010D9E4(s32 arg0) {
 extern const char lbl_80329560[]; extern const char lbl_80329578[];
 extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
 extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
 extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32);
 struct V { virtual u32 a0()=0; virtual u32 a1()=0; virtual u32 a2()=0; virtual u32 a3()=0; virtual u32 a4()=0; virtual u32 a5()=0; virtual u32 a6()=0; virtual u32 a7()=0; virtual u32 a8()=0; virtual u32 a9()=0; virtual u32 a10()=0; virtual u32 f()=0; };
 s32 var_r5=1,var_r6=1,var_r7=1,var_r8=1,var_r9=1,var_r10=1;
 s32 temp_r11=arg0&0xFF000000;
 s32 var_r30;
 if (((u32)(temp_r11+0x80000000)<1)&&((u32)((arg0&0xFF800000)+0x7F000000)<1)) var_r10=0;
 if ((var_r10==0)&&((u32)((arg0&0xF8000000)+0x70000000)<1)) var_r9=0;
 if ((var_r9==0)&&((u32)(temp_r11+0x40000000)<1)) var_r8=0;
 if ((var_r8==0)&&((u32)((arg0&0xFF800000)+0x3F000000)<1)) var_r7=0;
 if ((var_r7==0)&&((u32)((arg0&0xF8000000)+0x30000000)<1)) var_r6=0;
 if ((var_r6==0)&&((u32)((arg0&0xFFFFC000)+0x20000000)<1)) var_r5=0;
 if(var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0xF1,lbl_80329578,arg0);
 V *p=(V*)GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
 var_r30=p?p->f():0;
 return *(f32*)(arg0+0x50)+(f32)var_r30*GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0);
}

extern "C" const char lbl_80329560[];
extern "C" const char lbl_80329578[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(s32 arg0) {
    s32 var_r5 = 1;
    s32 var_r6 = 1;
    s32 var_r7 = 1;
    s32 var_r8 = 1;
    s32 var_r9 = 1;
    s32 var_r10 = 1;
    u32 temp_r11 = (u32)arg0 & 0xFF000000U;
    if ((((u32)(temp_r11 + 0x80000000U)) >= 1U) && (((u32)((arg0 & 0xFF800000) + 0x7F000000)) >= 1U)) var_r10 = 0;
    if ((var_r10 == 0) && (((u32)((arg0 & 0xF8000000) + 0x70000000)) >= 1U)) var_r9 = 0;
    if ((var_r9 == 0) && (((u32)(temp_r11 + 0x40000000U)) >= 1U)) var_r8 = 0;
    if ((var_r8 == 0) && (((u32)((arg0 & 0xFF800000) + 0x3F000000)) >= 1U)) var_r7 = 0;
    if ((var_r7 == 0) && (((u32)((arg0 & 0xF8000000) + 0x30000000)) >= 1U)) var_r6 = 0;
    if ((var_r6 == 0) && (((u32)((arg0 & 0xFFFFC000) + 0x20000000)) >= 1U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560, 0x15A, lbl_80329578, arg0);
    return *(s32 *)(arg0 + 0x54);
}

extern "C" s32 fn_8010E3BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,s32);
extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32);
extern s32 IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
extern s32 fn_8002F72C(void*,const void*);
extern u16 fn_8002F768(s32*);
extern f32 lbl_80561178;
extern const char lbl_80329530[],lbl_80329938[],lbl_80329900[],lbl_803298EC[],lbl_803298B4[],lbl_803298A0[],lbl_80329824[],lbl_80320AFC[],lbl_80320AC4[],lbl_80320B48[],lbl_80320B10[];
class Reader { public: s32 cursor; u16 (Reader::*next)(); };
Reader reader;
struct Context { s32 writer,str; f32 x,y; s32 flags; } context;
f32 rect[4];
class Font { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual s32 ascent(); virtual void x0(); virtual void x1(); virtual void x2(); virtual void x3(); virtual s32 width(u16); };
class Processor { public: virtual void d0(); virtual void d1(); virtual s32 rectCall(f32*,u16,Context*); };

    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f28;
    f32 temp_f29;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    f32 var_f31;
    s32 temp_r10;
    s32 temp_r11;
    s32 temp_r14;
    s32 temp_r20;
    s32 temp_r21;
    s32 temp_r22;
    s32 temp_r23;
    s32 temp_r24;
    s32 temp_r25;
    s32 temp_r26;
    s32 temp_r29;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r4_5;
    s32 temp_r5;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r14;
    s32 var_r19;
    s32 var_r20;
    s32 var_r20_2;
    s32 var_r30;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r5_8;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r6_7;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r8_7;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    u16 var_r27;
    u32 temp_r31;
    void **temp_r3_8;

    const char* base = lbl_80329530;
    temp_r24 = arg0 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32) (temp_r24) != 0x80000000U) && ((u32) ((arg0 & 0xFF800000)) != 0x81000000U)) {
        var_r10 = 0;
    }
    if ((var_r10 == 0) && ((u32) ((arg0 & 0xF8000000)) != 0x90000000U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((u32) (temp_r24) != 0xC0000000U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((u32) ((arg0 & 0xFF800000)) != 0xC1000000U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((u32) ((arg0 & 0xF8000000)) != 0xD0000000U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((u32) ((arg0 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37D, base + 0x48, arg0);
    }
    temp_r10 = arg1 & 0xFF000000;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    var_r9_2 = 1;
    if (((u32) (temp_r10) != 0x80000000U) && ((u32) ((arg1 & 0xFF800000)) != 0x81000000U)) {
        var_r9_2 = 0;
    }
    if ((var_r9_2 == 0) && ((u32) ((arg1 & 0xF8000000)) != 0x90000000U)) {
        var_r8_2 = 0;
    }
    if ((var_r8_2 == 0) && ((u32) (temp_r10) != 0xC0000000U)) {
        var_r7_2 = 0;
    }
    if ((var_r7_2 == 0) && ((u32) ((arg1 & 0xFF800000)) != 0xC1000000U)) {
        var_r6_2 = 0;
    }
    if ((var_r6_2 == 0) && ((u32) ((arg1 & 0xF8000000)) != 0xD0000000U)) {
        var_r5_2 = 0;
    }
    if ((var_r5_2 == 0) && ((u32) ((arg1 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4 = 0;
    }
    if (var_r4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37E, base + 0xF8, arg1);
    }
    temp_r14 = arg2 & 0xFF000000;
    var_r4_2 = 1;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32) (temp_r14) != 0x80000000U) && ((u32) ((arg2 & 0xFF800000)) != 0x81000000U)) {
        var_r9_3 = 0;
    }
    if ((var_r9_3 == 0) && ((u32) ((arg2 & 0xF8000000)) != 0x90000000U)) {
        var_r8_3 = 0;
    }
    if ((var_r8_3 == 0) && ((u32) (temp_r14) != 0xC0000000U)) {
        var_r7_3 = 0;
    }
    if ((var_r7_3 == 0) && ((u32) ((arg2 & 0xFF800000)) != 0xC1000000U)) {
        var_r6_3 = 0;
    }
    if ((var_r6_3 == 0) && ((u32) ((arg2 & 0xF8000000)) != 0xD0000000U)) {
        var_r5_3 = 0;
    }
    if ((var_r5_3 == 0) && ((u32) ((arg2 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_2 = 0;
    }
    if (var_r4_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37F, base + 0x130, arg2);
    }
    if (arg3 < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x380, base + 0x168, arg3, 0);
    }
    context.writer = arg0;
    context.x = 0;
    context.y = 0;
    context.flags = 0;
    context.str = arg2;
    temp_r3 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    temp_r11 = temp_r3 & 0xFF000000;
    var_f31 = lbl_80561178;
    var_r19 = 0;
    var_r5_4 = 1;
    var_r6_4 = 1;
    var_r7_4 = 1;
    var_r8_4 = 1;
    var_r9_4 = 1;
    var_r10_2 = 1;
    if (((u32) (temp_r11) != 0x80000000U) && ((u32) ((temp_r3 & 0xFF800000)) != 0x81000000U)) {
        var_r10_2 = 0;
    }
    if ((var_r10_2 == 0) && ((u32) ((temp_r3 & 0xF8000000)) != 0x90000000U)) {
        var_r9_4 = 0;
    }
    if ((var_r9_4 == 0) && ((u32) (temp_r11) != 0xC0000000U)) {
        var_r8_4 = 0;
    }
    if ((var_r8_4 == 0) && ((u32) ((temp_r3 & 0xFF800000)) != 0xC1000000U)) {
        var_r7_4 = 0;
    }
    if ((var_r7_4 == 0) && ((u32) ((temp_r3 & 0xF8000000)) != 0xD0000000U)) {
        var_r6_4 = 0;
    }
    if ((var_r6_4 == 0) && ((u32) ((temp_r3 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r5_4 = 0;
    }
    if (var_r5_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x386, base + 0x20C, temp_r3);
    }
    GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, temp_r3);
    var_r5_5 = 0;
    *(f32*)(arg1 + 0) = (f32) lbl_80561178;
    *(f32*)(arg1 + 8) = (f32) lbl_80561178;
    if (((u32) (temp_r24) == 0x80000000U) || (temp_r4 = arg0 & 0xFF800000, (((u32) (temp_r4) == 0x81000000U) != 0)) || (temp_r3_2 = arg0 & 0xF8000000, (((u32) (temp_r3_2) == 0x90000000U) != 0)) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r4) == 0xC1000000U) || ((u32) (temp_r3_2) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_5 = 1;
    }
    if (var_r5_5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0xF1, base + 0x48, arg0);
    }
    temp_r3_3 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (temp_r3_3 != 0) {
        var_r20 = ((Font*)temp_r3_3)->ascent();
    } else {
        var_r20 = 0;
    }
    var_f1 = *(f32*)(arg0 + 0x50) + ((f32) var_r20 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0));
    if (lbl_80561178 > var_f1) {

    } else {
        var_f1 = lbl_80561178;
    }
    *(f32*)(arg1 + 4) = var_f1;
    var_r5_6 = 0;
    if (((u32) (temp_r24) == 0x80000000U) || (temp_r4_2 = arg0 & 0xFF800000, (((u32) (temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_4 = arg0 & 0xF8000000, (((u32) (temp_r3_4) == 0x90000000U) != 0)) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r4_2) == 0xC1000000U) || ((u32) (temp_r3_4) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_6 = 1;
    }
    if (var_r5_6 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0xF1, base + 0x48, arg0);
    }
    temp_r3_5 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (temp_r3_5 != 0) {
        var_r20_2 = ((Font*)temp_r3_5)->ascent();
    } else {
        var_r20_2 = 0;
    }
    var_f1_2 = *(f32*)(arg0 + 0x50) + ((f32) var_r20_2 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0));
    if (lbl_80561178 < var_f1_2) {

    } else {
        var_f1_2 = lbl_80561178;
    }
    *(f32*)(arg1 + 0xC) = var_f1_2;
    temp_r23 = (s32) &reader.cursor & 0xFF000000;
    var_r4_3 = 1;
    var_r5_7 = 1;
    var_r6_5 = 1;
    var_r7_5 = 1;
    var_r8_5 = 1;
    var_r9_5 = 1;
    if (((u32) (temp_r23) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0x81000000U)) {
        var_r9_5 = 0;
    }
    if ((var_r9_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0x90000000U)) {
        var_r8_5 = 0;
    }
    if ((var_r8_5 == 0) && ((u32) (temp_r23) != 0xC0000000U)) {
        var_r7_5 = 0;
    }
    if ((var_r7_5 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0xC1000000U)) {
        var_r6_5 = 0;
    }
    if ((var_r6_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0xD0000000U)) {
        var_r5_7 = 0;
    }
    if ((var_r5_7 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_3 = 0;
    }
    if (var_r4_3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329938, 0x31, lbl_80329900, (s32) &reader.cursor);
    }
    var_r5_8 = 0;
    if (((u32) (temp_r14) == 0x80000000U) || (temp_r4_3 = arg2 & 0xFF800000, (((u32) (temp_r4_3) == 0x81000000U) != 0)) || (temp_r3_6 = arg2 & 0xF8000000, (((u32) (temp_r3_6) == 0x90000000U) != 0)) || ((u32) (temp_r14) == 0xC0000000U) || ((u32) (temp_r4_3) == 0xC1000000U) || ((u32) (temp_r3_6) == 0xD0000000U) || ((u32) ((arg2 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_8 = 1;
    }
    if (var_r5_8 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298EC, 0x32, lbl_803298B4, arg2);
    }
    var_r14 = 0;
    if ((fn_8002F72C(&reader.next, base + 0xC) != 0) && (fn_8002F72C(&reader.next, base + 0x18) != 0) && (fn_8002F72C(&reader.next, base + 0x24) != 0)) {
        var_r14 = 1;
    }
    if (var_r14 != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298A0, 0x35, lbl_80329824);
    }
    reader.cursor = arg2;
    var_r6_6 = 0;
    if (((u32) (temp_r23) == 0x80000000U) || (temp_r4_4 = (s32) &reader.cursor & 0xFF800000, (((u32) (temp_r4_4) == 0x81000000U) != 0)) || (temp_r3_7 = (s32) &reader.cursor & 0xF8000000, (((u32) (temp_r3_7) == 0x90000000U) != 0)) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r4_4) == 0xC1000000U) || ((u32) (temp_r3_7) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000)) == 0xE0000000U)) {
        var_r6_6 = 1;
    }
    if (var_r6_6 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
    }
    temp_f28 = lbl_80561178;
    var_r27 = fn_8002F768(&reader.cursor);
    temp_r22 = (s32) &reader.cursor & 0xFF800000;
    temp_r21 = (s32) &reader.cursor & 0xF8000000;
    temp_r20 = (s32) &reader.cursor & 0xFFFFC000;
    temp_r26 = arg0 & 0xFF800000;
    temp_r25 = arg0 & 0xF8000000;
    temp_r31 = temp_r23 + 0x80000000;
loop_279:
    var_r3 = 0;
    if ((temp_r31 == 0U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    if ((s32) (reader.cursor - arg2) > arg3) {
        goto block_290;
    }
    if ((s32) var_r27 < 0x20) {
        rect[0] = var_f31;
        var_r3_2 = 0;
        rect[1] = temp_f28;
        rect[2] = temp_f28;
        rect[3] = temp_f28;
        if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_2 = 1;
        }
        if (var_r3_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
        }
        context.str = reader.cursor;
        context.flags = var_r19 == 0;
        SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, var_f31);
        temp_r3_8 = *(void***)(arg0+0x5C);
        temp_r29 = ((Processor*)temp_r3_8)->rectCall(rect,var_r27,&context);
        var_r0 = 1;
        var_r3_3 = 1;
        temp_r5 = context.str & 0xFF000000;
        var_r4_4 = 1;
        var_r8_6 = 1;
        var_r9_6 = 1;
        var_r10_3 = 1;
        if (((u32) (temp_r5) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r10_3 = 0;
        }
        if ((var_r10_3 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r9_6 = 0;
        }
        if ((var_r9_6 == 0) && ((u32) (temp_r5) != 0xC0000000U)) {
            var_r8_6 = 0;
        }
        if ((var_r8_6 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r4_4 = 0;
        }
        if ((var_r4_4 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_3 = 0;
        }
        if ((var_r3_3 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0 = 0;
        }
        if (var_r0 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3A8, base + 0x244);
        }
        var_r3_4 = 0;
        if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_4 = 1;
        }
        if (var_r3_4 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329938, 0x31, lbl_80329900, (s32) &reader.cursor);
        }
        temp_r4_5 = context.str & 0xFF000000;
        var_r0_2 = 1;
        var_r3_5 = 1;
        var_r6_7 = 1;
        var_r7_6 = 1;
        var_r8_7 = 1;
        var_r9_7 = 1;
        if (((u32) (temp_r4_5) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r9_7 = 0;
        }
        if ((var_r9_7 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r8_7 = 0;
        }
        if ((var_r8_7 == 0) && ((u32) (temp_r4_5) != 0xC0000000U)) {
            var_r7_6 = 0;
        }
        if ((var_r7_6 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r6_7 = 0;
        }
        if ((var_r6_7 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_5 = 0;
        }
        if ((var_r3_5 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0_2 = 0;
        }
        if (var_r0_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298EC, 0x32, lbl_803298B4, context.str);
        }
        var_r30 = 0;
        if ((fn_8002F72C(&reader.next, base + 0xC) != 0) && (fn_8002F72C(&reader.next, base + 0x18) != 0) && (fn_8002F72C(&reader.next, base + 0x24) != 0)) {
            var_r30 = 1;
        }
        if (var_r30 != 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298A0, 0x35, lbl_80329824);
        }
        reader.cursor = context.str;
        var_f1_3 = rect[0];
        temp_f0 = *(f32*)(arg1 + 0);
        if (temp_f0 > var_f1_3) {

        } else {
            var_f1_3 = temp_f0;
        }
        *(f32*)(arg1 + 0) = var_f1_3;
        temp_f0_2 = *(f32*)(arg1 + 4);
        var_f1_4 = rect[1];
        if (temp_f0_2 > var_f1_4) {

        } else {
            var_f1_4 = temp_f0_2;
        }
        *(f32*)(arg1 + 4) = var_f1_4;
        temp_f0_3 = *(f32*)(arg1 + 8);
        var_f1_5 = rect[2];
        if (temp_f0_3 < var_f1_5) {

        } else {
            var_f1_5 = temp_f0_3;
        }
        *(f32*)(arg1 + 8) = var_f1_5;
        temp_f0_4 = *(f32*)(arg1 + 0xC);
        var_f1_6 = rect[3];
        if (temp_f0_4 < var_f1_6) {

        } else {
            var_f1_6 = temp_f0_4;
        }
        *(f32*)(arg1 + 0xC) = var_f1_6;
        var_f31 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
        switch (temp_r29) {                         /* irregular */
        case 4:
            return arg3;
        case 1:
            var_r19 = 0;
            goto block_268;
        case 2:
            var_r19 = 1;
            goto block_268;
        case 3:
block_290:
            var_r3_6 = 0;
            if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
                var_r3_6 = 1;
            }
            if (var_r3_6 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
            }
            return reader.cursor - arg2;
        }
    } else {
        if (var_r19 != 0) {
            var_r3_7 = 0;
            if (((u32) (temp_r24) == 0x80000000U) || ((u32) (temp_r26) == 0x81000000U) || ((u32) (temp_r25) == 0x90000000U) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r26) == 0xC1000000U) || ((u32) (temp_r25) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
                var_r3_7 = 1;
            }
            if (var_r3_7 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x138, base + 0x48, arg0);
            }
            var_f31 += *(f32*)(arg0 + 0x4C);
        }
        var_r19 = 1;
        if (IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(arg0) != 0) {
            var_f31 += GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(arg0);
        } else {
            temp_f29 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv(arg0);
            var_f31 += (f32) ((Font*)GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0))->width(var_r27) * temp_f29;
        }
        var_f0 = *(f32*)(arg1 + 0);
        if (var_f0 > var_f31) {
            var_f0 = var_f31;
        }
        var_f1_7 = *(f32*)(arg1 + 8);
        *(f32*)(arg1 + 0) = var_f0;
        if (var_f1_7 < var_f31) {
            var_f1_7 = var_f31;
        }
        *(f32*)(arg1 + 8) = var_f1_7;
block_268:
        var_r3_8 = 0;
        if ((temp_r31 == 0U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_8 = 1;
        }
        if (var_r3_8 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
        }
        var_r27 = fn_8002F768(&reader.cursor);
        goto loop_279;
    }
}

extern "C" f32 fn_8010F81C(void *writer, s32 arg1, s32 arg2) {
extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,s32);
extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32);
extern void MoveCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32),MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(s32,f32),Print__Q36nw4hbm2ut10CharWriterFUs(s32,u16),SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32),SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(s32,f32),SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32);
extern s32 fn_8002F72C(void*,const void*);
extern u16 fn_8002F768(s32*);
extern void fn_801033F0(void*,unsigned int);
extern void fn_8010E3BC(void*,f32*,s32,s32);
extern f32 fn_80110D68(s32,f32*,f32*,s32,s32);
extern f32 lbl_80561178,lbl_80561188;
extern const char lbl_80320980[],lbl_803209B8[],lbl_803209CC[],lbl_80320A04[],lbl_80320A18[],lbl_80320A64[],lbl_80320A78[],lbl_80320AB0[],lbl_80320AC4[],lbl_80320AFC[],lbl_80320B10[],lbl_80320B48[],lbl_80329530[];
 extern const char lbl_80329938[],lbl_80329900[],lbl_803298EC[],lbl_803298B4[],lbl_803298A0[],lbl_80329824[];
 class TagProcessor { public: virtual void dummy(); virtual s32 process(u16,s32*); };
 class FontMetrics { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual s32 ascent(); };
 nw4hbm::ut::CharWriter copyRight;
 nw4hbm::ut::CharWriter copyCenter;
 class Reader { public: s32 cursor; u16 (Reader::*next)(); };
 Reader reader;
 struct { s32 writer, str; f32 x, y; s32 flags; } context;
 f32 rectRight[4], rectCenter[4];
 s32 arg0=(s32)writer;

    void **sp114;
    void **spB4;
    f32 spC;
    f32 sp8;
    f32 temp_f25;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f31;
    f32 var_f0;
    f32 var_f29;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f24;
    s32 temp_r18;
    s32 temp_r18_2;
    s32 temp_r19;
    s32 temp_r19_2;
    s32 temp_r21;
    s32 temp_r22;
    s32 temp_r23;
    s32 temp_r24;
    s32 temp_r25;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r28;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_5;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_5;
    s32 temp_r4_7;
    s32 temp_r4_8;
    s32 temp_r5;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r14;
    s32 var_r20;
    s32 var_r3;
    s32 var_r3_10;
    s32 var_r3_11;
    s32 var_r3_12;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r3_9;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r6_7;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r7_7;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r8_7;
    s32 var_r8_8;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    s32 var_r9_8;
    u16 var_r19;
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r31;
    u32 temp_r3_3;
    u32 temp_r4_4;
    u32 temp_r4_6;
    void **temp_r3_4;

    temp_r22 = arg0 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32)(temp_r22) != 0x80000000U) && ((u32)(arg0 & 0xFF800000) != 0x81000000U)) {
        var_r10 = 0;
    }
    if ((var_r10 == 0) && ((u32)(arg0 & 0xF8000000) != 0x90000000U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((u32)(temp_r22) != 0xC0000000U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((u32)(arg0 & 0xFF800000) != 0xC1000000U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((u32)(arg0 & 0xF8000000) != 0xD0000000U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((u32)(arg0 & 0xFFFFC000) != 0xE0000000U)) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x41F, lbl_80329530 + 0x48, arg0);
    }
    temp_r18 = arg1 & 0xFF000000;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    var_r9_2 = 1;
    if (((u32)(temp_r18) != 0x80000000U) && ((u32)(arg1 & 0xFF800000) != 0x81000000U)) {
        var_r9_2 = 0;
    }
    if ((var_r9_2 == 0) && ((u32)(arg1 & 0xF8000000) != 0x90000000U)) {
        var_r8_2 = 0;
    }
    if ((var_r8_2 == 0) && ((u32)(temp_r18) != 0xC0000000U)) {
        var_r7_2 = 0;
    }
    if ((var_r7_2 == 0) && ((u32)(arg1 & 0xFF800000) != 0xC1000000U)) {
        var_r6_2 = 0;
    }
    if ((var_r6_2 == 0) && ((u32)(arg1 & 0xF8000000) != 0xD0000000U)) {
        var_r5_2 = 0;
    }
    if ((var_r5_2 == 0) && ((u32)(arg1 & 0xFFFFC000) != 0xE0000000U)) {
        var_r4 = 0;
    }
    if (var_r4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x420, lbl_80329530 + 0x130, arg1);
    }
    var_r14 = 0;
    if (((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF000000) + 0x80000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF800000) + 0x7F000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xF8000000) + 0x70000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF000000) + 0x40000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF800000) + 0x3F000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xF8000000) + 0x30000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFFFFC000) + 0x20000000) == 0U)) {
        var_r14 = 1;
    }
    if (var_r14 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x421, lbl_80329530 + 0x280, GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0));
    }
    if (arg2 < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x422, lbl_80329530 + 0x168, arg2, 0);
    }
    spC = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
    temp_f1 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
    temp_f28 = (f32) temp_f1;
    sp8 = (f32) temp_f1;
    var_r20 = 0;
    var_f29 = fn_80110D68(arg0, &spC, &sp8, arg1, arg2);
    GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
    temp_f1_2 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
    context.x = 0.0f;
    context.y = 0.0f;
    context.flags = 0;
    context.writer = arg0;
    context.str = arg1;
    context.x = spC;
    context.y = sp8;
    GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0));
    var_r4_2 = 1;
    temp_r21 = (s32) &reader.cursor & 0xFF000000;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32)(temp_r21) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000) + 0x7F000000) != 0U)) {
        var_r9_3 = 0;
    }
    if ((var_r9_3 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000) + 0x70000000) != 0U)) {
        var_r8_3 = 0;
    }
    if ((var_r8_3 == 0) && ((u32)(temp_r21) != 0xC0000000U)) {
        var_r7_3 = 0;
    }
    if ((var_r7_3 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000) + 0x3F000000) != 0U)) {
        var_r6_3 = 0;
    }
    if ((var_r6_3 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000) + 0x30000000) != 0U)) {
        var_r5_3 = 0;
    }
    if ((var_r5_3 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000) + 0x20000000) != 0U)) {
        var_r4_2 = 0;
    }
    if (var_r4_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329938, 0x31, lbl_80329900, (s32) &reader.cursor);
    }

    var_r5_4 = 0;
    if (((u32)(temp_r18) == 0x80000000U) || (temp_r4 = arg1 & 0xFF800000, (((u32)(temp_r4) == 0x81000000U) != 0)) || (temp_r3 = arg1 & 0xF8000000, (((u32)(temp_r3) == 0x90000000U) != 0)) || ((u32)(temp_r18) == 0xC0000000U) || ((u32)(temp_r4) == 0xC1000000U) || ((u32)(temp_r3) == 0xD0000000U) || ((u32)(arg1 & 0xFFFFC000) == 0xE0000000U)) {
        var_r5_4 = 1;
    }
    if (var_r5_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298EC, 0x32, lbl_803298B4, arg1);
    }
    if (fn_8002F72C(&reader.next, lbl_80329530 + 0xC) != 0 && fn_8002F72C(&reader.next, lbl_80329530 + 0x18) != 0 && fn_8002F72C(&reader.next, lbl_80329530 + 0x24) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298A0, 0x35, lbl_80329824);
    }
    reader.cursor = arg1;
    var_r6_4 = 0;
    if (((u32)(temp_r21) == 0x80000000U) || (temp_r4_2 = (s32) &reader.cursor & 0xFF800000, (((u32)(temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_2 = (s32) &reader.cursor & 0xF8000000, (((u32)(temp_r3_2) == 0x90000000U) != 0)) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r4_2) == 0xC1000000U) || ((u32)(temp_r3_2) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000) + 0x20000000) == 0U)) {
        var_r6_4 = 1;
    }
    if (var_r6_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
    }
    temp_f31 = lbl_80561178;
    temp_f25 = lbl_80561188;
    var_r19 = (reader.*reader.next)();
    temp_r28 = (s32) &reader.cursor & 0xFF800000;
    temp_r27 = (s32) &reader.cursor & 0xF8000000;
    temp_r26 = (s32) &reader.cursor & 0xFFFFC000;
    temp_r25 = arg0 & 0xFF800000;
    temp_r24 = arg0 & 0xF8000000;
    temp_r23 = arg0 & 0xFFFFC000;
    temp_r31 = temp_r21 + 0x80000000;
loop_286:
    var_r3 = 0;
    if ((temp_r31 == 0U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    temp_r3_3 = reader.cursor - arg1;
    if ((s32)temp_r3_3 <= arg2) {
        if ((s32) var_r19 < 0x20) {
            var_r3_2 = 0;
            if (((u32)(temp_r21) == 0x80000000U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                var_r3_2 = 1;
            }
            if (var_r3_2 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
            }
            context.str = reader.cursor;
            context.flags = var_r20 == 0;
            temp_r3_4 = *(void ***)(arg0 + 0x5C);
            temp_r3_5 = ((TagProcessor*)temp_r3_4)->process(var_r19, &context.writer);
            switch (temp_r3_5) {                    /* irregular */
            case 4:
                break;
            case 3:
                var_r0 = 1;
                var_r3_3 = 1;
                var_r7_4 = 1;
                temp_r4_3 = context.str & 0xFF000000;
                var_r8_4 = 1;
                var_r9_4 = 1;
                var_r10_2 = 1;
                if (((u32)(temp_r4_3) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r10_2 = 0;
                }
                if ((var_r10_2 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r9_4 = 0;
                }
                if ((var_r9_4 == 0) && ((u32)(temp_r4_3) != 0xC0000000U)) {
                    var_r8_4 = 0;
                }
                if ((var_r8_4 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r7_4 = 0;
                }
                if ((var_r7_4 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_3 = 0;
                }
                if ((var_r3_3 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0 = 0;
                }
                if (var_r0 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x449, lbl_80329530 + 0x244);
                }
                temp_r0 = *(s32 *)(arg0 + 0x58) & 3;
                if (temp_r0 == 1) {
                    var_r3_4 = 0;
                    temp_r4_4 = context.str - arg1;
                    temp_r19 = arg2 - temp_r4_4;
                    if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                        var_r3_4 = 1;
                    }
                    if (var_r3_4 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35D, lbl_80329530 + 0x48, arg0);
                    }
                    temp_r4_5 = context.str & 0xFF000000;
                    var_r0_2 = 1;
                    var_r3_5 = 1;
                    var_r6_5 = 1;
                    var_r7_5 = 1;
                    var_r8_5 = 1;
                    var_r9_5 = 1;
                    if (((u32)(temp_r4_5) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                        var_r9_5 = 0;
                    }
                    if ((var_r9_5 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                        var_r8_5 = 0;
                    }
                    if ((var_r8_5 == 0) && ((u32)(temp_r4_5) != 0xC0000000U)) {
                        var_r7_5 = 0;
                    }
                    if ((var_r7_5 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                        var_r6_5 = 0;
                    }
                    if ((var_r6_5 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                        var_r3_5 = 0;
                    }
                    if ((var_r3_5 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                        var_r0_2 = 0;
                    }
                    if (var_r0_2 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35E, lbl_80329530 + 0x130, context.str);
                    }
                    if (temp_r19 < 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35F, lbl_80329530 + 0x168, temp_r19, 0);
                    }
                    rectRight[0] = temp_f31;
                    rectRight[1] = temp_f31;
                    rectRight[2] = temp_f31;
                    rectRight[3] = temp_f31;
                    *(u8 *)((u8*)&copyRight+0) = *(u8 *)(arg0 + 0);
                    *(u8 *)((u8*)&copyRight+1) = *(u8 *)(arg0 + 1);
                    *(u8 *)((u8*)&copyRight+2) = *(u8 *)(arg0 + 2);
                    *(u8 *)((u8*)&copyRight+3) = *(u8 *)(arg0 + 3);
                    *(u8 *)((u8*)&copyRight+4) = *(u8 *)(arg0 + 4);
                    *(u8 *)((u8*)&copyRight+5) = *(u8 *)(arg0 + 5);
                    *(u8 *)((u8*)&copyRight+6) = *(u8 *)(arg0 + 6);
                    *(u8 *)((u8*)&copyRight+7) = *(u8 *)(arg0 + 7);
                    *(u8 *)((u8*)&copyRight+8) = *(u8 *)(arg0 + 8);
                    *(u8 *)((u8*)&copyRight+9) = *(u8 *)(arg0 + 9);
                    *(u8 *)((u8*)&copyRight+10) = *(u8 *)(arg0 + 0xA);
                    *(u8 *)((u8*)&copyRight+11) = *(u8 *)(arg0 + 0xB);
                    *(u8 *)((u8*)&copyRight+12) = *(u8 *)(arg0 + 0xC);
                    *(u8 *)((u8*)&copyRight+13) = *(u8 *)(arg0 + 0xD);
                    *(u8 *)((u8*)&copyRight+14) = *(u8 *)(arg0 + 0xE);
                    *(u8 *)((u8*)&copyRight+15) = *(u8 *)(arg0 + 0xF);
                    *(u8 *)((u8*)&copyRight+16) = *(u8 *)(arg0 + 0x10);
                    *(u8 *)((u8*)&copyRight+17) = *(u8 *)(arg0 + 0x11);
                    *(u8 *)((u8*)&copyRight+18) = *(u8 *)(arg0 + 0x12);
                    *(u8 *)((u8*)&copyRight+19) = *(u8 *)(arg0 + 0x13);
                    *(u8 *)((u8*)&copyRight+20) = *(u8 *)(arg0 + 0x14);
                    *(u8 *)((u8*)&copyRight+21) = *(u8 *)(arg0 + 0x15);
                    *(u8 *)((u8*)&copyRight+22) = *(u8 *)(arg0 + 0x16);
                    *(u8 *)((u8*)&copyRight+23) = *(u8 *)(arg0 + 0x17);
                    *(u8 *)((u8*)&copyRight+24) = *(u8 *)(arg0 + 0x18);
                    *(u8 *)((u8*)&copyRight+25) = *(u8 *)(arg0 + 0x19);
                    *(u8 *)((u8*)&copyRight+26) = *(u8 *)(arg0 + 0x1A);
                    *(u8 *)((u8*)&copyRight+27) = *(u8 *)(arg0 + 0x1B);
                    *(u8 *)((u8*)&copyRight+28) = *(u8 *)(arg0 + 0x1C);
                    *(u8 *)((u8*)&copyRight+29) = *(u8 *)(arg0 + 0x1D);
                    *(u8 *)((u8*)&copyRight+30) = *(u8 *)(arg0 + 0x1E);
                    *(u8 *)((u8*)&copyRight+31) = *(u8 *)(arg0 + 0x1F);
                    *(s32 *)((u8*)&copyRight+32) = *(s32 *)(arg0 + 0x20);
                    *(s32 *)((u8*)&copyRight+36) = *(s32 *)(arg0 + 0x24);
                    *(s32 *)((u8*)&copyRight+40) = *(s32 *)(arg0 + 0x28);
                    *(s32 *)((u8*)&copyRight+44) = *(s32 *)(arg0 + 0x2C);
                    *(s32 *)((u8*)&copyRight+48) = *(s32 *)(arg0 + 0x30);
                    *(s32 *)((u8*)&copyRight+52) = *(s32 *)(arg0 + 0x34);
                    *(s32 *)((u8*)&copyRight+56) = *(s32 *)(arg0 + 0x38);
                    *(s32 *)((u8*)&copyRight+60) = *(s32 *)(arg0 + 0x3C);
                    *(u8 *)((u8*)&copyRight+64) = *(u8 *)(arg0 + 0x40);
                    *(u8 *)((u8*)&copyRight+65) = *(u8 *)(arg0 + 0x41);
                    *(u8 *)((u8*)&copyRight+66) = *(u8 *)(arg0 + 0x42);
                    *(u8 *)((u8*)&copyRight+67) = *(u8 *)(arg0 + 0x43);
                    *(f32 *)((u8*)&copyRight+68) = *(f32 *)(arg0 + 0x44);
                    *(s32 *)((u8*)&copyRight+72) = *(s32 *)(arg0 + 0x48);
                    *(f32 *)((u8*)&copyRight+76) = *(f32 *)(arg0 + 0x4C);
                    *(f32 *)((u8*)&copyRight+80) = *(f32 *)(arg0 + 0x50);
                    *(s32 *)((u8*)&copyRight+84) = *(s32 *)(arg0 + 0x54);
                    *(s32 *)((u8*)&copyRight+88) = *(s32 *)(arg0 + 0x58);
                    *(void ***)((u8*)&copyRight+92) = *(void ***)(arg0 + 0x5C);
                    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyRight, temp_f31, temp_f31);
                    fn_8010E3BC((u8*)&copyRight, &rectRight[0], context.str, temp_r19);
                    fn_801033F0((u8*)&copyRight, 0);
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x + ((var_f29 - (rectRight[2] - rectRight[0])) * temp_f25));
                } else if (temp_r0 == 2) {
                    var_r3_6 = 0;
                    temp_r4_6 = context.str - arg1;
                    temp_r19_2 = arg2 - temp_r4_6;
                    if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                        var_r3_6 = 1;
                    }
                    if (var_r3_6 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35D, lbl_80329530 + 0x48, arg0);
                    }
                    temp_r4_7 = context.str & 0xFF000000;
                    var_r0_3 = 1;
                    var_r3_7 = 1;
                    var_r6_6 = 1;
                    var_r7_6 = 1;
                    var_r8_6 = 1;
                    var_r9_6 = 1;
                    if (((u32)(temp_r4_7) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                        var_r9_6 = 0;
                    }
                    if ((var_r9_6 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                        var_r8_6 = 0;
                    }
                    if ((var_r8_6 == 0) && ((u32)(temp_r4_7) != 0xC0000000U)) {
                        var_r7_6 = 0;
                    }
                    if ((var_r7_6 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                        var_r6_6 = 0;
                    }
                    if ((var_r6_6 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                        var_r3_7 = 0;
                    }
                    if ((var_r3_7 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                        var_r0_3 = 0;
                    }
                    if (var_r0_3 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35E, lbl_80329530 + 0x130, context.str);
                    }
                    if (temp_r19_2 < 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35F, lbl_80329530 + 0x168, temp_r19_2, 0);
                    }
                    rectCenter[0] = temp_f31;
                    rectCenter[1] = temp_f31;
                    rectCenter[2] = temp_f31;
                    rectCenter[3] = temp_f31;
                    *(u8 *)((u8*)&copyCenter+0) = *(u8 *)(arg0 + 0);
                    *(u8 *)((u8*)&copyCenter+1) = *(u8 *)(arg0 + 1);
                    *(u8 *)((u8*)&copyCenter+2) = *(u8 *)(arg0 + 2);
                    *(u8 *)((u8*)&copyCenter+3) = *(u8 *)(arg0 + 3);
                    *(u8 *)((u8*)&copyCenter+4) = *(u8 *)(arg0 + 4);
                    *(u8 *)((u8*)&copyCenter+5) = *(u8 *)(arg0 + 5);
                    *(u8 *)((u8*)&copyCenter+6) = *(u8 *)(arg0 + 6);
                    *(u8 *)((u8*)&copyCenter+7) = *(u8 *)(arg0 + 7);
                    *(u8 *)((u8*)&copyCenter+8) = *(u8 *)(arg0 + 8);
                    *(u8 *)((u8*)&copyCenter+9) = *(u8 *)(arg0 + 9);
                    *(u8 *)((u8*)&copyCenter+10) = *(u8 *)(arg0 + 0xA);
                    *(u8 *)((u8*)&copyCenter+11) = *(u8 *)(arg0 + 0xB);
                    *(u8 *)((u8*)&copyCenter+12) = *(u8 *)(arg0 + 0xC);
                    *(u8 *)((u8*)&copyCenter+13) = *(u8 *)(arg0 + 0xD);
                    *(u8 *)((u8*)&copyCenter+14) = *(u8 *)(arg0 + 0xE);
                    *(u8 *)((u8*)&copyCenter+15) = *(u8 *)(arg0 + 0xF);
                    *(u8 *)((u8*)&copyCenter+16) = *(u8 *)(arg0 + 0x10);
                    *(u8 *)((u8*)&copyCenter+17) = *(u8 *)(arg0 + 0x11);
                    *(u8 *)((u8*)&copyCenter+18) = *(u8 *)(arg0 + 0x12);
                    *(u8 *)((u8*)&copyCenter+19) = *(u8 *)(arg0 + 0x13);
                    *(u8 *)((u8*)&copyCenter+20) = *(u8 *)(arg0 + 0x14);
                    *(u8 *)((u8*)&copyCenter+21) = *(u8 *)(arg0 + 0x15);
                    *(u8 *)((u8*)&copyCenter+22) = *(u8 *)(arg0 + 0x16);
                    *(u8 *)((u8*)&copyCenter+23) = *(u8 *)(arg0 + 0x17);
                    *(u8 *)((u8*)&copyCenter+24) = *(u8 *)(arg0 + 0x18);
                    *(u8 *)((u8*)&copyCenter+25) = *(u8 *)(arg0 + 0x19);
                    *(u8 *)((u8*)&copyCenter+26) = *(u8 *)(arg0 + 0x1A);
                    *(u8 *)((u8*)&copyCenter+27) = *(u8 *)(arg0 + 0x1B);
                    *(u8 *)((u8*)&copyCenter+28) = *(u8 *)(arg0 + 0x1C);
                    *(u8 *)((u8*)&copyCenter+29) = *(u8 *)(arg0 + 0x1D);
                    *(u8 *)((u8*)&copyCenter+30) = *(u8 *)(arg0 + 0x1E);
                    *(u8 *)((u8*)&copyCenter+31) = *(u8 *)(arg0 + 0x1F);
                    *(s32 *)((u8*)&copyCenter+32) = *(s32 *)(arg0 + 0x20);
                    *(s32 *)((u8*)&copyCenter+36) = *(s32 *)(arg0 + 0x24);
                    *(s32 *)((u8*)&copyCenter+40) = *(s32 *)(arg0 + 0x28);
                    *(s32 *)((u8*)&copyCenter+44) = *(s32 *)(arg0 + 0x2C);
                    *(s32 *)((u8*)&copyCenter+48) = *(s32 *)(arg0 + 0x30);
                    *(s32 *)((u8*)&copyCenter+52) = *(s32 *)(arg0 + 0x34);
                    *(s32 *)((u8*)&copyCenter+56) = *(s32 *)(arg0 + 0x38);
                    *(s32 *)((u8*)&copyCenter+60) = *(s32 *)(arg0 + 0x3C);
                    *(u8 *)((u8*)&copyCenter+64) = *(u8 *)(arg0 + 0x40);
                    *(u8 *)((u8*)&copyCenter+65) = *(u8 *)(arg0 + 0x41);
                    *(u8 *)((u8*)&copyCenter+66) = *(u8 *)(arg0 + 0x42);
                    *(u8 *)((u8*)&copyCenter+67) = *(u8 *)(arg0 + 0x43);
                    *(f32 *)((u8*)&copyCenter+68) = *(f32 *)(arg0 + 0x44);
                    *(s32 *)((u8*)&copyCenter+72) = *(s32 *)(arg0 + 0x48);
                    *(f32 *)((u8*)&copyCenter+76) = *(f32 *)(arg0 + 0x4C);
                    *(f32 *)((u8*)&copyCenter+80) = *(f32 *)(arg0 + 0x50);
                    *(s32 *)((u8*)&copyCenter+84) = *(s32 *)(arg0 + 0x54);
                    *(s32 *)((u8*)&copyCenter+88) = *(s32 *)(arg0 + 0x58);
                    *(void ***)((u8*)&copyCenter+92) = *(void ***)(arg0 + 0x5C);
                    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyCenter, temp_f31, temp_f31);
                    fn_8010E3BC((u8*)&copyCenter, &rectCenter[0], context.str, temp_r19_2);
                    fn_801033F0((u8*)&copyCenter, 0);
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x + (var_f29 - (rectCenter[2] - rectCenter[0])));
                } else {
                    var_f0 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0) - context.x;
                    if (var_f29 < var_f0) {

                    } else {
                        var_f0 = var_f29;
                    }
                    var_f29 = var_f0;
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x);
                }
                var_r20 = 0;
            default:
block_207:
                var_r0_4 = 1;
                var_r3_8 = 1;
                var_r4_3 = 1;
                temp_r5 = context.str & 0xFF000000;
                var_r8_7 = 1;
                var_r9_7 = 1;
                var_r10_3 = 1;
                if (((u32)(temp_r5) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r10_3 = 0;
                }
                if ((var_r10_3 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r9_7 = 0;
                }
                if ((var_r9_7 == 0) && ((u32)(temp_r5) != 0xC0000000U)) {
                    var_r8_7 = 0;
                }
                if ((var_r8_7 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r4_3 = 0;
                }
                if ((var_r4_3 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_8 = 0;
                }
                if ((var_r3_8 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0_4 = 0;
                }
                if (var_r0_4 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x471, lbl_80329530 + 0x244);
                }
                var_r3_9 = 0;
                if (((u32)(temp_r21) == 0x80000000U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                    var_r3_9 = 1;
                }
                if (var_r3_9 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329938, 0x31, lbl_80329900, (s32) &reader.cursor);
                }

                temp_r4_8 = context.str & 0xFF000000;
                var_r0_5 = 1;
                var_r3_10 = 1;
                var_r6_7 = 1;
                var_r7_7 = 1;
                var_r8_8 = 1;
                var_r9_8 = 1;
                if (((u32)(temp_r4_8) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r9_8 = 0;
                }
                if ((var_r9_8 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r8_8 = 0;
                }
                if ((var_r8_8 == 0) && ((u32)(temp_r4_8) != 0xC0000000U)) {
                    var_r7_7 = 0;
                }
                if ((var_r7_7 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r6_7 = 0;
                }
                if ((var_r6_7 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_10 = 0;
                }
                if ((var_r3_10 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0_5 = 0;
                }
                if (var_r0_5 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298EC, 0x32, lbl_803298B4, context.str);
                }
                if (fn_8002F72C(&reader.next, lbl_80329530 + 0xC) != 0 && fn_8002F72C(&reader.next, lbl_80329530 + 0x18) != 0 && fn_8002F72C(&reader.next, lbl_80329530 + 0x24) != 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298A0, 0x35, lbl_80329824);
                }
                reader.cursor = context.str;
                goto block_275;
            case 1:
                var_r20 = 0;
                goto block_207;
            case 2:
                var_r20 = 1;
                goto block_207;
            }
        } else {
            temp_f24 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
            if (var_r20 != 0) {
                var_r3_11 = 0;
                if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                    var_r3_11 = 1;
                }
                if (var_r3_11 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x138, lbl_80329530 + 0x48, arg0);
                }
                MoveCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *(f32 *)(arg0 + 0x4C));
            }
            var_r20 = 1;
            temp_r18_2 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
            temp_f26 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0);
            MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(arg0, (f32) -((FontMetrics*)temp_r18_2)->ascent() * temp_f26);
            Print__Q36nw4hbm2ut10CharWriterFUs(arg0, var_r19);
            SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, temp_f24);
block_275:
            var_r3_12 = 0;
            if ((temp_r31 == 0U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                var_r3_12 = 1;
            }
            if (var_r3_12 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
            }
            var_r19 = (reader.*reader.next)();
            goto loop_286;
        }
    }
    temp_r0_2 = *(s32 *)(arg0 + 0x58) & 0x300;
    if ((temp_r0_2 == 0x100) || (temp_r0_2 == 0x200)) {
        SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, (f64) temp_f28);
    } else {
        MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(arg0, temp_f28 - (f32) temp_f1_2);
    }
    return var_f29;
}

extern "C" void* fn_80111B64(void* arg0) {
    extern void __ct__Q36nw4hbm2ut10CharWriterFv(void*);
    extern f32 lbl_80561178;
    extern s32 lbl_8055DEB8;
    f32 value;
    __ct__Q36nw4hbm2ut10CharWriterFv(arg0);
    value = lbl_80561178;
    *(f32*)((char*)arg0 + 0x4C) = value;
    *(f32*)((char*)arg0 + 0x50) = value;
    *(s32*)((char*)arg0 + 0x54) = 4;
    *(s32*)((char*)arg0 + 0x58) = 0;
    *(s32*)((char*)arg0 + 0x5C) = (s32)&lbl_8055DEB8;
    return arg0;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80111BB8(void* arg0, int arg1) {
    extern void fn_801033F0(void*, unsigned int);
    extern void fn_80128668(void*);
    if (arg0 != 0) {
        fn_801033F0(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" f32 fn_80111C10(s32 arg0) {
    s32 temp_r11;
    s32 var_r5 = 1, var_r6 = 1, var_r7 = 1, var_r8 = 1, var_r9 = 1, var_r10 = 1;
    s32 var_r30, font;
    temp_r11 = arg0 & 0xFF000000;
    if ((u32)(temp_r11 + 0x80000000) < 1U && (u32)((arg0 & 0xFF800000) + 0x7F000000) < 1U) var_r10 = 0;
    if (var_r10 == 0 && (u32)((arg0 & 0xF8000000) + 0x70000000) < 1U) var_r9 = 0;
    if (var_r9 == 0 && (u32)(temp_r11 + 0x40000000) < 1U) var_r8 = 0;
    if (var_r8 == 0 && (u32)((arg0 & 0xFF800000) + 0x3F000000) < 1U) var_r7 = 0;
    if (var_r7 == 0 && (u32)((arg0 & 0xF8000000) + 0x30000000) < 1U) var_r6 = 0;
    if (var_r6 == 0 && (u32)((arg0 & 0xFFFFC000) + 0x20000000) < 1U) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560, 0xF1, lbl_80329578, arg0);
    font = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (font) {
        struct V { virtual int a0()=0; virtual int a1()=0; virtual int a2()=0; virtual int a3()=0; virtual int a4()=0; virtual int a5()=0; virtual int a6()=0; virtual int a7()=0; virtual int a8()=0; virtual int a9()=0; virtual int a10()=0; virtual int a11()=0; virtual int a12()=0; };
        var_r30 = ((V*)font)->a12();
    } else var_r30 = 0;
    return *(f32*)(arg0 + 0x50) + (f32)var_r30 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0);
}

extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_80111D88(void *arg0, float farg0) {
 int var_r5=1; int var_r6=1; int var_r7=1; int var_r8=1; int var_r9=1; int var_r10=1;
 unsigned int temp_r11=(unsigned int)arg0&0xFF000000U;
 if ((unsigned int)(temp_r11+0x80000000U)<1U && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x7F000000U)<1U) var_r10=0;
 if (var_r10==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x70000000U)<1U) var_r9=0;
 if (var_r9==0 && (unsigned int)(temp_r11+0x40000000U)<1U) var_r8=0;
 if (var_r8==0 && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x3F000000U)<1U) var_r7=0;
 if (var_r7==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x30000000U)<1U) var_r6=0;
 if (var_r6==0 && (unsigned int)(((unsigned int)arg0&0xFFFFC000U)+0x20000000U)<1U) var_r5=0;
 if(var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x105,lbl_80329578,arg0);
 *(float*)((char*)arg0+0x50)=farg0;
}

extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_80111EAC(void *arg0, float farg0) {
 int var_r5=1; int var_r6=1; int var_r7=1; int var_r8=1; int var_r9=1; int var_r10=1;
 unsigned int temp_r11=(unsigned int)arg0&0xFF000000U;
 if ((unsigned int)(temp_r11+0x80000000U)<1U && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x7F000000U)<1U) var_r10=0;
 if (var_r10==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x70000000U)<1U) var_r9=0;
 if (var_r9==0 && (unsigned int)(temp_r11+0x40000000U)<1U) var_r8=0;
 if (var_r8==0 && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x3F000000U)<1U) var_r7=0;
 if (var_r7==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x30000000U)<1U) var_r6=0;
 if (var_r6==0 && (unsigned int)(((unsigned int)arg0&0xFFFFC000U)+0x20000000U)<1U) var_r5=0;
 if(var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x116,lbl_80329578,arg0);
 *(float*)((char*)arg0+0x4C)=farg0;
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80111FD0(int arg0) {
 unsigned int temp_r11=(unsigned int)arg0&0xFF000000U;
 int var_r5=1,var_r6=1,var_r7=1,var_r8=1,var_r9=1,var_r10=1;
 if ((temp_r11+0x80000000U)>=1U && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)>=1U) var_r10=0;
 if (var_r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)>=1U) var_r9=0;
 if (var_r9==0 && temp_r11+0x40000000U>=1U) var_r8=0;
 if (var_r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)>=1U) var_r7=0;
 if (var_r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)>=1U) var_r6=0;
 if (var_r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)>=1U) var_r5=0;
 if (var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x138,lbl_80329578,arg0);
 return *(float*)((char*)arg0+0x4C);
}

extern "C" s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_801120E8(void *arg0) {
 extern const char lbl_80329560[]; extern const char lbl_80329578[];
 extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
 u32 p=(u32)arg0; u32 hi=p&0xFF000000;
 s32 r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
 if ((u32)(hi+0x80000000)<1U && (u32)((p&0xFF800000)+0x7F000000)<1U) r10=0;
 if (r10==0 && (u32)((p&0xF8000000)+0x70000000)<1U) r9=0;
 if (r9==0 && (u32)(hi+0x40000000)<1U) r8=0;
 if (r8==0 && (u32)((p&0xFF800000)+0x3F000000)<1U) r7=0;
 if (r7==0 && (u32)((p&0xF8000000)+0x30000000)<1U) r6=0;
 if (r6==0 && (u32)((p&0xFFFFC000)+0x20000000)<1U) r5=0;
 if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x15A,lbl_80329578,arg0);
 return *(s32*)((char*)arg0+0x54);
}

void* nw4hbm::ut::CharWriter::GetFont() const {
    const unsigned int p = (unsigned int)this;
    unsigned int r5=1, r6=1, r7=1, r8=1, r9=1, r10=1;
    unsigned int r11=p&0xFF000000;
    if ((r11+0x80000000U)!=0 && ((p&0xFF800000)+0x7F000000U)!=0) r10=0;
    if (r10==0 && ((p&0xF8000000)+0x70000000U)!=0) r9=0;
    if (r9==0 && (r11+0x40000000U)!=0) r8=0;
    if (r8==0 && ((p&0xFF800000)+0x3F000000U)!=0) r7=0;
    if (r7==0 && ((p&0xF8000000)+0x30000000U)!=0) r6=0;
    if (r6==0 && ((p&0xFFFFC000)+0x20000000U)!=0) r5=0;
    if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x97,lbl_80329578,this);
    return font;
}

extern "C" f32 fn_80112960(u8 *arg0, u8 *arg1) {
    extern s32 fn_8002AEE8(s32);
    extern f32 fn_801142F8(void *, s32, s32);
    extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(void *);
    extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(void *);
    extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(void *, f32, f32);
    extern void fn_801033F0(void *, s32);
    u8 writer[0x60];
    s32 width = fn_8002AEE8((s32)arg1);
    f32 result = fn_801142F8(writer, (s32)arg1, width);
    f32 scale = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(writer);
    GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(writer);
    SetCursor__Q36nw4hbm2ut10CharWriterFff(arg0, 0.0f, scale);
    fn_801033F0(writer, 0);
    return result;
}

extern "C" s32 fn_80112EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,s32);
extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32);
extern s32 IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
extern s32 fn_8002F72C(void*,const void*);
extern u16 fn_8002F768(s32*);
extern f32 lbl_80561178;
extern const char lbl_80320980[],lbl_803209B8[],lbl_803209CC[],lbl_80320A04[],lbl_80320A18[],lbl_80320A64[],lbl_80320A78[],lbl_80320AB0[],lbl_80329530[],lbl_80329938[],lbl_80329900[],lbl_803298EC[],lbl_803298B4[],lbl_803298A0[],lbl_80329824[],lbl_80320AFC[],lbl_80320AC4[],lbl_80320B48[],lbl_80320B10[];
class Reader { public: s32 cursor; u16 (Reader::*next)(); };
Reader reader;
struct Context { s32 writer,str; f32 x,y; s32 flags; } context;
f32 rect[4];
class Font { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual s32 ascent(); virtual void x0(); virtual void x1(); virtual void x2(); virtual void x3(); virtual s32 width(u16); };
class Processor { public: virtual void d0(); virtual void d1(); virtual s32 rectCall(f32*,u16,Context*); };

    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f28;
    f32 temp_f29;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    f32 var_f31;
    s32 temp_r10;
    s32 temp_r11;
    s32 temp_r14;
    s32 temp_r20;
    s32 temp_r21;
    s32 temp_r22;
    s32 temp_r23;
    s32 temp_r24;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r30;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r5;
    s32 temp_r7;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r19;
    s32 var_r20;
    s32 var_r20_2;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r4_5;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r5_8;
    s32 var_r5_9;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    u16 var_r28;
    u32 temp_r31;
    u32 temp_r3;
    u32 temp_r3_9;
    void **temp_r3_10;

    const char* base = lbl_80329530;
    temp_r24 = arg0 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32) (temp_r24) != 0x80000000U) && ((u32) ((arg0 & 0xFF800000)) != 0x81000000U)) {
        var_r10 = 0;
    }
    if ((var_r10 == 0) && ((u32) ((arg0 & 0xF8000000)) != 0x90000000U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((u32) (temp_r24) != 0xC0000000U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((u32) ((arg0 & 0xFF800000)) != 0xC1000000U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((u32) ((arg0 & 0xF8000000)) != 0xD0000000U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((u32) ((arg0 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37D, base + 0x48, arg0);
    }
    temp_r10 = arg1 & 0xFF000000;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    var_r9_2 = 1;
    if (((u32) (temp_r10) != 0x80000000U) && ((u32) ((arg1 & 0xFF800000)) != 0x81000000U)) {
        var_r9_2 = 0;
    }
    if ((var_r9_2 == 0) && ((u32) ((arg1 & 0xF8000000)) != 0x90000000U)) {
        var_r8_2 = 0;
    }
    if ((var_r8_2 == 0) && ((u32) (temp_r10) != 0xC0000000U)) {
        var_r7_2 = 0;
    }
    if ((var_r7_2 == 0) && ((u32) ((arg1 & 0xFF800000)) != 0xC1000000U)) {
        var_r6_2 = 0;
    }
    if ((var_r6_2 == 0) && ((u32) ((arg1 & 0xF8000000)) != 0xD0000000U)) {
        var_r5_2 = 0;
    }
    if ((var_r5_2 == 0) && ((u32) ((arg1 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4 = 0;
    }
    if (var_r4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37E, base + 0xF8, arg1);
    }
    temp_r14 = arg2 & 0xFF000000;
    var_r4_2 = 1;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32) (temp_r14) != 0x80000000U) && ((u32) ((arg2 & 0xFF800000)) != 0x81000000U)) {
        var_r9_3 = 0;
    }
    if ((var_r9_3 == 0) && ((u32) ((arg2 & 0xF8000000)) != 0x90000000U)) {
        var_r8_3 = 0;
    }
    if ((var_r8_3 == 0) && ((u32) (temp_r14) != 0xC0000000U)) {
        var_r7_3 = 0;
    }
    if ((var_r7_3 == 0) && ((u32) ((arg2 & 0xFF800000)) != 0xC1000000U)) {
        var_r6_3 = 0;
    }
    if ((var_r6_3 == 0) && ((u32) ((arg2 & 0xF8000000)) != 0xD0000000U)) {
        var_r5_3 = 0;
    }
    if ((var_r5_3 == 0) && ((u32) ((arg2 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_2 = 0;
    }
    if (var_r4_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37F, base + 0x130, arg2);
    }
    if (arg3 < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x380, base + 0x168, arg3, 0);
    }
    context.writer = arg0;
    context.x = 0;
    context.y = 0;
    context.flags = 0;
    context.str = arg2;
    temp_r3_2 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    temp_r11 = temp_r3_2 & 0xFF000000;
    var_f31 = lbl_80561178;
    var_r19 = 0;
    var_r5_4 = 1;
    var_r6_4 = 1;
    var_r7_4 = 1;
    var_r8_4 = 1;
    var_r9_4 = 1;
    var_r10_2 = 1;
    if (((u32) (temp_r11) != 0x80000000U) && ((u32) ((temp_r3_2 & 0xFF800000)) != 0x81000000U)) {
        var_r10_2 = 0;
    }
    if ((var_r10_2 == 0) && ((u32) ((temp_r3_2 & 0xF8000000)) != 0x90000000U)) {
        var_r9_4 = 0;
    }
    if ((var_r9_4 == 0) && ((u32) (temp_r11) != 0xC0000000U)) {
        var_r8_4 = 0;
    }
    if ((var_r8_4 == 0) && ((u32) ((temp_r3_2 & 0xFF800000)) != 0xC1000000U)) {
        var_r7_4 = 0;
    }
    if ((var_r7_4 == 0) && ((u32) ((temp_r3_2 & 0xF8000000)) != 0xD0000000U)) {
        var_r6_4 = 0;
    }
    if ((var_r6_4 == 0) && ((u32) ((temp_r3_2 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r5_4 = 0;
    }
    if (var_r5_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x386, base + 0x20C, temp_r3_2);
    }
    GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, temp_r3_2);
    var_r5_5 = 0;
    *(f32*)(arg1 + 0) = (f32) lbl_80561178;
    *(f32*)(arg1 + 8) = (f32) lbl_80561178;
    if (((u32) (temp_r24) == 0x80000000U) || (temp_r4 = arg0 & 0xFF800000, (((u32) (temp_r4) == 0x81000000U) != 0)) || (temp_r3_3 = arg0 & 0xF8000000, (((u32) (temp_r3_3) == 0x90000000U) != 0)) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r4) == 0xC1000000U) || ((u32) (temp_r3_3) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_5 = 1;
    }
    if (var_r5_5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0xF1, base + 0x48, arg0);
    }
    temp_r3_4 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (temp_r3_4 != 0) {
        var_r20 = ((Font*)temp_r3_4)->ascent();
    } else {
        var_r20 = 0;
    }
    var_f1 = *(f32*)(arg0 + 0x50) + ((f32) var_r20 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0));
    if (lbl_80561178 > var_f1) {

    } else {
        var_f1 = lbl_80561178;
    }
    *(f32*)(arg1 + 4) = var_f1;
    var_r5_6 = 0;
    if (((u32) (temp_r24) == 0x80000000U) || (temp_r4_2 = arg0 & 0xFF800000, (((u32) (temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_5 = arg0 & 0xF8000000, (((u32) (temp_r3_5) == 0x90000000U) != 0)) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r4_2) == 0xC1000000U) || ((u32) (temp_r3_5) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_6 = 1;
    }
    if (var_r5_6 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0xF1, base + 0x48, arg0);
    }
    temp_r3_6 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (temp_r3_6 != 0) {
        var_r20_2 = ((Font*)temp_r3_6)->ascent();
    } else {
        var_r20_2 = 0;
    }
    var_f1_2 = *(f32*)(arg0 + 0x50) + ((f32) var_r20_2 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0));
    if (lbl_80561178 < var_f1_2) {

    } else {
        var_f1_2 = lbl_80561178;
    }
    *(f32*)(arg1 + 0xC) = var_f1_2;
    temp_r23 = (s32) &reader.cursor & 0xFF000000;
    var_r4_3 = 1;
    var_r5_7 = 1;
    var_r6_5 = 1;
    var_r7_5 = 1;
    var_r8_5 = 1;
    var_r9_5 = 1;
    if (((u32) (temp_r23) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0x81000000U)) {
        var_r9_5 = 0;
    }
    if ((var_r9_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0x90000000U)) {
        var_r8_5 = 0;
    }
    if ((var_r8_5 == 0) && ((u32) (temp_r23) != 0xC0000000U)) {
        var_r7_5 = 0;
    }
    if ((var_r7_5 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0xC1000000U)) {
        var_r6_5 = 0;
    }
    if ((var_r6_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0xD0000000U)) {
        var_r5_7 = 0;
    }
    if ((var_r5_7 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_3 = 0;
    }
    if (var_r4_3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
    }
    if (arg2 & 1) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A64, 0x3C, lbl_80320A18, arg2);
    }
    var_r5_8 = 0;
    if (((u32) (temp_r14) == 0x80000000U) || (temp_r4_3 = arg2 & 0xFF800000, (((u32) (temp_r4_3) == 0x81000000U) != 0)) || (temp_r3_7 = arg2 & 0xF8000000, (((u32) (temp_r3_7) == 0x90000000U) != 0)) || ((u32) (temp_r14) == 0xC0000000U) || ((u32) (temp_r4_3) == 0xC1000000U) || ((u32) (temp_r3_7) == 0xD0000000U) || ((u32) ((arg2 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_8 = 1;
    }
    if (var_r5_8 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A04, 0x3D, lbl_803209CC, arg2);
    }
    if (fn_8002F72C(&reader.next, lbl_80329530) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803209B8, 0x3E, lbl_80320980);
    }
    reader.cursor = arg2;
    var_r6_6 = 0;
    if (((u32) (temp_r23) == 0x80000000U) || (temp_r4_4 = (s32) &reader.cursor & 0xFF800000, (((u32) (temp_r4_4) == 0x81000000U) != 0)) || (temp_r3_8 = (s32) &reader.cursor & 0xF8000000, (((u32) (temp_r3_8) == 0x90000000U) != 0)) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r4_4) == 0xC1000000U) || ((u32) (temp_r3_8) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000)) == 0xE0000000U)) {
        var_r6_6 = 1;
    }
    if (var_r6_6 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
    }
    temp_f28 = lbl_80561178;
    var_r28 = fn_8002F768(&reader.cursor);
    temp_r22 = (s32) &reader.cursor & 0xFF800000;
    temp_r21 = (s32) &reader.cursor & 0xF8000000;
    temp_r20 = (s32) &reader.cursor & 0xFFFFC000;
    temp_r27 = arg0 & 0xFF800000;
    temp_r26 = arg0 & 0xF8000000;
    temp_r31 = temp_r23 + 0x80000000;
loop_275:
    var_r3 = 0;
    if ((temp_r31 == 0U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    temp_r3_9 = reader.cursor - arg2;
    if (((s32)temp_r3_9 / 2) > arg3) {
        goto block_286;
    }
    if ((s32) var_r28 < 0x20) {
        rect[0] = var_f31;
        var_r3_2 = 0;
        rect[1] = temp_f28;
        rect[2] = temp_f28;
        rect[3] = temp_f28;
        if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_2 = 1;
        }
        if (var_r3_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
        }
        context.str = reader.cursor;
        context.flags = var_r19 == 0;
        SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, var_f31);
        temp_r3_10 = *(void***)(arg0+0x5C);
        temp_r30 = ((Processor*)temp_r3_10)->rectCall(rect,var_r28,&context);
        var_r0 = 1;
        var_r3_3 = 1;
        temp_r7 = context.str & 0xFF000000;
        var_r4_4 = 1;
        var_r5_9 = 1;
        var_r9_6 = 1;
        var_r10_3 = 1;
        if (((u32) (temp_r7) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r10_3 = 0;
        }
        if ((var_r10_3 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r9_6 = 0;
        }
        if ((var_r9_6 == 0) && ((u32) (temp_r7) != 0xC0000000U)) {
            var_r5_9 = 0;
        }
        if ((var_r5_9 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r4_4 = 0;
        }
        if ((var_r4_4 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_3 = 0;
        }
        if ((var_r3_3 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0 = 0;
        }
        if (var_r0 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3A8, base + 0x244);
        }
        var_r3_4 = 0;
        if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_4 = 1;
        }
        if (var_r3_4 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
        }
        if (context.str & 1) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A64, 0x3C, lbl_80320A18, context.str);
        }
        temp_r5 = context.str & 0xFF000000;
        var_r0_2 = 1;
        var_r3_5 = 1;
        var_r7_6 = 1;
        var_r4_5 = 1;
        var_r8_6 = 1;
        var_r9_7 = 1;
        if (((u32) (temp_r5) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r9_7 = 0;
        }
        if ((var_r9_7 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r8_6 = 0;
        }
        if ((var_r8_6 == 0) && ((u32) (temp_r5) != 0xC0000000U)) {
            var_r7_6 = 0;
        }
        if ((var_r7_6 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r4_5 = 0;
        }
        if ((var_r4_5 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_5 = 0;
        }
        if ((var_r3_5 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0_2 = 0;
        }
        if (var_r0_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A04, 0x3D, lbl_803209CC, context.str);
        }
        if (fn_8002F72C(&reader.next, lbl_80329530) != 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803209B8, 0x3E, lbl_80320980);
        }
        reader.cursor = context.str;
        var_f1_3 = rect[0];
        temp_f0 = *(f32*)(arg1 + 0);
        if (temp_f0 > var_f1_3) {

        } else {
            var_f1_3 = temp_f0;
        }
        *(f32*)(arg1 + 0) = var_f1_3;
        temp_f0_2 = *(f32*)(arg1 + 4);
        var_f1_4 = rect[1];
        if (temp_f0_2 > var_f1_4) {

        } else {
            var_f1_4 = temp_f0_2;
        }
        *(f32*)(arg1 + 4) = var_f1_4;
        temp_f0_3 = *(f32*)(arg1 + 8);
        var_f1_5 = rect[2];
        if (temp_f0_3 < var_f1_5) {

        } else {
            var_f1_5 = temp_f0_3;
        }
        *(f32*)(arg1 + 8) = var_f1_5;
        temp_f0_4 = *(f32*)(arg1 + 0xC);
        var_f1_6 = rect[3];
        if (temp_f0_4 < var_f1_6) {

        } else {
            var_f1_6 = temp_f0_4;
        }
        *(f32*)(arg1 + 0xC) = var_f1_6;
        var_f31 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
        switch (temp_r30) {                         /* irregular */
        case 4:
            return arg3;
        case 1:
            var_r19 = 0;
            goto block_264;
        case 2:
            var_r19 = 1;
            goto block_264;
        case 3:
block_286:
            var_r3_6 = 0;
            if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
                var_r3_6 = 1;
            }
            if (var_r3_6 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
            }
            temp_r3 = reader.cursor - arg2;
            return (s32)temp_r3 / 2;
        }
    } else {
        if (var_r19 != 0) {
            var_r3_7 = 0;
            if (((u32) (temp_r24) == 0x80000000U) || ((u32) (temp_r27) == 0x81000000U) || ((u32) (temp_r26) == 0x90000000U) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r27) == 0xC1000000U) || ((u32) (temp_r26) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
                var_r3_7 = 1;
            }
            if (var_r3_7 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x138, base + 0x48, arg0);
            }
            var_f31 += *(f32*)(arg0 + 0x4C);
        }
        var_r19 = 1;
        if (IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(arg0) != 0) {
            var_f31 += GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(arg0);
        } else {
            temp_f29 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv(arg0);
            var_f31 += (f32) ((Font*)GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0))->width(var_r28) * temp_f29;
        }
        var_f0 = *(f32*)(arg1 + 0);
        if (var_f0 > var_f31) {
            var_f0 = var_f31;
        }
        var_f1_7 = *(f32*)(arg1 + 8);
        *(f32*)(arg1 + 0) = var_f0;
        if (var_f1_7 < var_f31) {
            var_f1_7 = var_f31;
        }
        *(f32*)(arg1 + 8) = var_f1_7;
block_264:
        var_r3_8 = 0;
        if ((temp_r31 == 0U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_8 = 1;
        }
        if (var_r3_8 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
        }
        var_r28 = fn_8002F768(&reader.cursor);
        goto loop_275;
    }
}

extern "C" f32 fn_801142F8(void *writer, s32 arg1, s32 arg2) {
extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,s32);
extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32);
extern void MoveCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32),MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(s32,f32),Print__Q36nw4hbm2ut10CharWriterFUs(s32,u16),SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32),SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(s32,f32),SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32);
extern s32 fn_8002F72C(void*,const void*);
extern u16 fn_8002F768(s32*);
extern void fn_801033F0(void*,unsigned int);
extern void fn_80112EA0(void*,f32*,s32,s32);
extern f32 fn_80115848(s32,f32*,f32*,s32,s32);
extern f32 lbl_80561178,lbl_80561188;
extern const char lbl_80320980[],lbl_803209B8[],lbl_803209CC[],lbl_80320A04[],lbl_80320A18[],lbl_80320A64[],lbl_80320A78[],lbl_80320AB0[],lbl_80320AC4[],lbl_80320AFC[],lbl_80320B10[],lbl_80320B48[],lbl_80329530[];
 nw4hbm::ut::CharWriter copyRight;
 nw4hbm::ut::CharWriter copyCenter;
 class Reader { public: s32 cursor; u16 (Reader::*next)(); };
 Reader reader;
 struct { s32 writer, str; f32 x, y; s32 flags; } context;
 f32 rectRight[4], rectCenter[4];
 s32 arg0=(s32)writer;

    void **sp114;
    void **spB4;
    f32 spC;
    f32 sp8;
    f32 temp_f25;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f31;
    f32 var_f0;
    f32 var_f29;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f24;
    s32 temp_r18;
    s32 temp_r18_2;
    s32 temp_r19;
    s32 temp_r19_2;
    s32 temp_r21;
    s32 temp_r22;
    s32 temp_r23;
    s32 temp_r24;
    s32 temp_r25;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r28;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_5;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_5;
    s32 temp_r4_7;
    s32 temp_r4_8;
    s32 temp_r5;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r14;
    s32 var_r20;
    s32 var_r3;
    s32 var_r3_10;
    s32 var_r3_11;
    s32 var_r3_12;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r3_9;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r6_7;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r7_7;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r8_7;
    s32 var_r8_8;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    s32 var_r9_8;
    u16 var_r19;
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r31;
    u32 temp_r3_3;
    u32 temp_r4_4;
    u32 temp_r4_6;
    void **temp_r3_4;

    temp_r22 = arg0 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32)(temp_r22) != 0x80000000U) && ((u32)(arg0 & 0xFF800000) != 0x81000000U)) {
        var_r10 = 0;
    }
    if ((var_r10 == 0) && ((u32)(arg0 & 0xF8000000) != 0x90000000U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((u32)(temp_r22) != 0xC0000000U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((u32)(arg0 & 0xFF800000) != 0xC1000000U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((u32)(arg0 & 0xF8000000) != 0xD0000000U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((u32)(arg0 & 0xFFFFC000) != 0xE0000000U)) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x41F, lbl_80329530 + 0x48, arg0);
    }
    temp_r18 = arg1 & 0xFF000000;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    var_r9_2 = 1;
    if (((u32)(temp_r18) != 0x80000000U) && ((u32)(arg1 & 0xFF800000) != 0x81000000U)) {
        var_r9_2 = 0;
    }
    if ((var_r9_2 == 0) && ((u32)(arg1 & 0xF8000000) != 0x90000000U)) {
        var_r8_2 = 0;
    }
    if ((var_r8_2 == 0) && ((u32)(temp_r18) != 0xC0000000U)) {
        var_r7_2 = 0;
    }
    if ((var_r7_2 == 0) && ((u32)(arg1 & 0xFF800000) != 0xC1000000U)) {
        var_r6_2 = 0;
    }
    if ((var_r6_2 == 0) && ((u32)(arg1 & 0xF8000000) != 0xD0000000U)) {
        var_r5_2 = 0;
    }
    if ((var_r5_2 == 0) && ((u32)(arg1 & 0xFFFFC000) != 0xE0000000U)) {
        var_r4 = 0;
    }
    if (var_r4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x420, lbl_80329530 + 0x130, arg1);
    }
    var_r14 = 0;
    if (((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF000000) + 0x80000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF800000) + 0x7F000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xF8000000) + 0x70000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF000000) + 0x40000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF800000) + 0x3F000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xF8000000) + 0x30000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFFFFC000) + 0x20000000) == 0U)) {
        var_r14 = 1;
    }
    if (var_r14 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x421, lbl_80329530 + 0x280, GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0));
    }
    if (arg2 < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x422, lbl_80329530 + 0x168, arg2, 0);
    }
    spC = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
    temp_f1 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
    temp_f28 = (f32) temp_f1;
    sp8 = (f32) temp_f1;
    var_r20 = 0;
    var_f29 = fn_80115848(arg0, &spC, &sp8, arg1, arg2);
    GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
    temp_f1_2 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
    context.x = 0.0f;
    context.y = 0.0f;
    context.flags = 0;
    context.writer = arg0;
    context.str = arg1;
    context.x = spC;
    context.y = sp8;
    GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0));
    var_r4_2 = 1;
    temp_r21 = (s32) &reader.cursor & 0xFF000000;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32)(temp_r21) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000) + 0x7F000000) != 0U)) {
        var_r9_3 = 0;
    }
    if ((var_r9_3 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000) + 0x70000000) != 0U)) {
        var_r8_3 = 0;
    }
    if ((var_r8_3 == 0) && ((u32)(temp_r21) != 0xC0000000U)) {
        var_r7_3 = 0;
    }
    if ((var_r7_3 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000) + 0x3F000000) != 0U)) {
        var_r6_3 = 0;
    }
    if ((var_r6_3 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000) + 0x30000000) != 0U)) {
        var_r5_3 = 0;
    }
    if ((var_r5_3 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000) + 0x20000000) != 0U)) {
        var_r4_2 = 0;
    }
    if (var_r4_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
    }
    if (arg1 & 1) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A64, 0x3C, lbl_80320A18, arg1);
    }
    var_r5_4 = 0;
    if (((u32)(temp_r18) == 0x80000000U) || (temp_r4 = arg1 & 0xFF800000, (((u32)(temp_r4) == 0x81000000U) != 0)) || (temp_r3 = arg1 & 0xF8000000, (((u32)(temp_r3) == 0x90000000U) != 0)) || ((u32)(temp_r18) == 0xC0000000U) || ((u32)(temp_r4) == 0xC1000000U) || ((u32)(temp_r3) == 0xD0000000U) || ((u32)(arg1 & 0xFFFFC000) == 0xE0000000U)) {
        var_r5_4 = 1;
    }
    if (var_r5_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A04, 0x3D, lbl_803209CC, arg1);
    }
    if (fn_8002F72C(&reader.next, lbl_80329530) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803209B8, 0x3E, lbl_80320980);
    }
    reader.cursor = arg1;
    var_r6_4 = 0;
    if (((u32)(temp_r21) == 0x80000000U) || (temp_r4_2 = (s32) &reader.cursor & 0xFF800000, (((u32)(temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_2 = (s32) &reader.cursor & 0xF8000000, (((u32)(temp_r3_2) == 0x90000000U) != 0)) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r4_2) == 0xC1000000U) || ((u32)(temp_r3_2) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000) + 0x20000000) == 0U)) {
        var_r6_4 = 1;
    }
    if (var_r6_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
    }
    temp_f31 = lbl_80561178;
    temp_f25 = lbl_80561188;
    var_r19 = (reader.*reader.next)();
    temp_r28 = (s32) &reader.cursor & 0xFF800000;
    temp_r27 = (s32) &reader.cursor & 0xF8000000;
    temp_r26 = (s32) &reader.cursor & 0xFFFFC000;
    temp_r25 = arg0 & 0xFF800000;
    temp_r24 = arg0 & 0xF8000000;
    temp_r23 = arg0 & 0xFFFFC000;
    temp_r31 = temp_r21 + 0x80000000;
loop_286:
    var_r3 = 0;
    if ((temp_r31 == 0U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    temp_r3_3 = reader.cursor - arg1;
    if ((s32) ((s32) ((temp_r3_3 >> 0x1FU) + temp_r3_3) >> 1) <= arg2) {
        if ((s32) var_r19 < 0x20) {
            var_r3_2 = 0;
            if (((u32)(temp_r21) == 0x80000000U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                var_r3_2 = 1;
            }
            if (var_r3_2 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
            }
            context.str = reader.cursor;
            context.flags = var_r20 == 0;
            temp_r3_4 = *(void ***)(arg0 + 0x5C);
            temp_r3_5 = (*(s32 (**)(void **, u16, s32 *))((char*)*temp_r3_4+0xC))(temp_r3_4, var_r19, &context.writer);
            switch (temp_r3_5) {                    /* irregular */
            case 4:
                break;
            case 3:
                var_r0 = 1;
                var_r3_3 = 1;
                var_r7_4 = 1;
                temp_r4_3 = context.str & 0xFF000000;
                var_r8_4 = 1;
                var_r9_4 = 1;
                var_r10_2 = 1;
                if (((u32)(temp_r4_3) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r10_2 = 0;
                }
                if ((var_r10_2 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r9_4 = 0;
                }
                if ((var_r9_4 == 0) && ((u32)(temp_r4_3) != 0xC0000000U)) {
                    var_r8_4 = 0;
                }
                if ((var_r8_4 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r7_4 = 0;
                }
                if ((var_r7_4 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_3 = 0;
                }
                if ((var_r3_3 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0 = 0;
                }
                if (var_r0 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x449, lbl_80329530 + 0x244);
                }
                temp_r0 = *(s32 *)(arg0 + 0x58) & 3;
                if (temp_r0 == 1) {
                    var_r3_4 = 0;
                    temp_r4_4 = context.str - arg1;
                    temp_r19 = arg2 - ((s32) ((temp_r4_4 >> 0x1FU) + temp_r4_4) >> 1);
                    if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                        var_r3_4 = 1;
                    }
                    if (var_r3_4 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35D, lbl_80329530 + 0x48, arg0);
                    }
                    temp_r4_5 = context.str & 0xFF000000;
                    var_r0_2 = 1;
                    var_r3_5 = 1;
                    var_r6_5 = 1;
                    var_r7_5 = 1;
                    var_r8_5 = 1;
                    var_r9_5 = 1;
                    if (((u32)(temp_r4_5) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                        var_r9_5 = 0;
                    }
                    if ((var_r9_5 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                        var_r8_5 = 0;
                    }
                    if ((var_r8_5 == 0) && ((u32)(temp_r4_5) != 0xC0000000U)) {
                        var_r7_5 = 0;
                    }
                    if ((var_r7_5 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                        var_r6_5 = 0;
                    }
                    if ((var_r6_5 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                        var_r3_5 = 0;
                    }
                    if ((var_r3_5 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                        var_r0_2 = 0;
                    }
                    if (var_r0_2 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35E, lbl_80329530 + 0x130, context.str);
                    }
                    if (temp_r19 < 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35F, lbl_80329530 + 0x168, temp_r19, 0);
                    }
                    rectRight[0] = temp_f31;
                    rectRight[1] = temp_f31;
                    rectRight[2] = temp_f31;
                    rectRight[3] = temp_f31;
                    *(u8 *)((u8*)&copyRight+0) = *(u8 *)(arg0 + 0);
                    *(u8 *)((u8*)&copyRight+1) = *(u8 *)(arg0 + 1);
                    *(u8 *)((u8*)&copyRight+2) = *(u8 *)(arg0 + 2);
                    *(u8 *)((u8*)&copyRight+3) = *(u8 *)(arg0 + 3);
                    *(u8 *)((u8*)&copyRight+4) = *(u8 *)(arg0 + 4);
                    *(u8 *)((u8*)&copyRight+5) = *(u8 *)(arg0 + 5);
                    *(u8 *)((u8*)&copyRight+6) = *(u8 *)(arg0 + 6);
                    *(u8 *)((u8*)&copyRight+7) = *(u8 *)(arg0 + 7);
                    *(u8 *)((u8*)&copyRight+8) = *(u8 *)(arg0 + 8);
                    *(u8 *)((u8*)&copyRight+9) = *(u8 *)(arg0 + 9);
                    *(u8 *)((u8*)&copyRight+10) = *(u8 *)(arg0 + 0xA);
                    *(u8 *)((u8*)&copyRight+11) = *(u8 *)(arg0 + 0xB);
                    *(u8 *)((u8*)&copyRight+12) = *(u8 *)(arg0 + 0xC);
                    *(u8 *)((u8*)&copyRight+13) = *(u8 *)(arg0 + 0xD);
                    *(u8 *)((u8*)&copyRight+14) = *(u8 *)(arg0 + 0xE);
                    *(u8 *)((u8*)&copyRight+15) = *(u8 *)(arg0 + 0xF);
                    *(u8 *)((u8*)&copyRight+16) = *(u8 *)(arg0 + 0x10);
                    *(u8 *)((u8*)&copyRight+17) = *(u8 *)(arg0 + 0x11);
                    *(u8 *)((u8*)&copyRight+18) = *(u8 *)(arg0 + 0x12);
                    *(u8 *)((u8*)&copyRight+19) = *(u8 *)(arg0 + 0x13);
                    *(u8 *)((u8*)&copyRight+20) = *(u8 *)(arg0 + 0x14);
                    *(u8 *)((u8*)&copyRight+21) = *(u8 *)(arg0 + 0x15);
                    *(u8 *)((u8*)&copyRight+22) = *(u8 *)(arg0 + 0x16);
                    *(u8 *)((u8*)&copyRight+23) = *(u8 *)(arg0 + 0x17);
                    *(u8 *)((u8*)&copyRight+24) = *(u8 *)(arg0 + 0x18);
                    *(u8 *)((u8*)&copyRight+25) = *(u8 *)(arg0 + 0x19);
                    *(u8 *)((u8*)&copyRight+26) = *(u8 *)(arg0 + 0x1A);
                    *(u8 *)((u8*)&copyRight+27) = *(u8 *)(arg0 + 0x1B);
                    *(u8 *)((u8*)&copyRight+28) = *(u8 *)(arg0 + 0x1C);
                    *(u8 *)((u8*)&copyRight+29) = *(u8 *)(arg0 + 0x1D);
                    *(u8 *)((u8*)&copyRight+30) = *(u8 *)(arg0 + 0x1E);
                    *(u8 *)((u8*)&copyRight+31) = *(u8 *)(arg0 + 0x1F);
                    *(s32 *)((u8*)&copyRight+32) = *(s32 *)(arg0 + 0x20);
                    *(s32 *)((u8*)&copyRight+36) = *(s32 *)(arg0 + 0x24);
                    *(s32 *)((u8*)&copyRight+40) = *(s32 *)(arg0 + 0x28);
                    *(s32 *)((u8*)&copyRight+44) = *(s32 *)(arg0 + 0x2C);
                    *(s32 *)((u8*)&copyRight+48) = *(s32 *)(arg0 + 0x30);
                    *(s32 *)((u8*)&copyRight+52) = *(s32 *)(arg0 + 0x34);
                    *(s32 *)((u8*)&copyRight+56) = *(s32 *)(arg0 + 0x38);
                    *(s32 *)((u8*)&copyRight+60) = *(s32 *)(arg0 + 0x3C);
                    *(u8 *)((u8*)&copyRight+64) = *(u8 *)(arg0 + 0x40);
                    *(u8 *)((u8*)&copyRight+65) = *(u8 *)(arg0 + 0x41);
                    *(u8 *)((u8*)&copyRight+66) = *(u8 *)(arg0 + 0x42);
                    *(u8 *)((u8*)&copyRight+67) = *(u8 *)(arg0 + 0x43);
                    *(f32 *)((u8*)&copyRight+68) = *(f32 *)(arg0 + 0x44);
                    *(s32 *)((u8*)&copyRight+72) = *(s32 *)(arg0 + 0x48);
                    *(f32 *)((u8*)&copyRight+76) = *(f32 *)(arg0 + 0x4C);
                    *(f32 *)((u8*)&copyRight+80) = *(f32 *)(arg0 + 0x50);
                    *(s32 *)((u8*)&copyRight+84) = *(s32 *)(arg0 + 0x54);
                    *(s32 *)((u8*)&copyRight+88) = *(s32 *)(arg0 + 0x58);
                    *(void ***)((u8*)&copyRight+92) = *(void ***)(arg0 + 0x5C);
                    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyRight, temp_f31, temp_f31);
                    fn_80112EA0((u8*)&copyRight, &rectRight[0], context.str, temp_r19);
                    fn_801033F0((u8*)&copyRight, 0);
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x + ((var_f29 - (rectRight[2] - rectRight[0])) * temp_f25));
                } else if (temp_r0 == 2) {
                    var_r3_6 = 0;
                    temp_r4_6 = context.str - arg1;
                    temp_r19_2 = arg2 - ((s32) ((temp_r4_6 >> 0x1FU) + temp_r4_6) >> 1);
                    if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                        var_r3_6 = 1;
                    }
                    if (var_r3_6 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35D, lbl_80329530 + 0x48, arg0);
                    }
                    temp_r4_7 = context.str & 0xFF000000;
                    var_r0_3 = 1;
                    var_r3_7 = 1;
                    var_r6_6 = 1;
                    var_r7_6 = 1;
                    var_r8_6 = 1;
                    var_r9_6 = 1;
                    if (((u32)(temp_r4_7) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                        var_r9_6 = 0;
                    }
                    if ((var_r9_6 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                        var_r8_6 = 0;
                    }
                    if ((var_r8_6 == 0) && ((u32)(temp_r4_7) != 0xC0000000U)) {
                        var_r7_6 = 0;
                    }
                    if ((var_r7_6 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                        var_r6_6 = 0;
                    }
                    if ((var_r6_6 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                        var_r3_7 = 0;
                    }
                    if ((var_r3_7 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                        var_r0_3 = 0;
                    }
                    if (var_r0_3 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35E, lbl_80329530 + 0x130, context.str);
                    }
                    if (temp_r19_2 < 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x35F, lbl_80329530 + 0x168, temp_r19_2, 0);
                    }
                    rectCenter[0] = temp_f31;
                    rectCenter[1] = temp_f31;
                    rectCenter[2] = temp_f31;
                    rectCenter[3] = temp_f31;
                    *(u8 *)((u8*)&copyCenter+0) = *(u8 *)(arg0 + 0);
                    *(u8 *)((u8*)&copyCenter+1) = *(u8 *)(arg0 + 1);
                    *(u8 *)((u8*)&copyCenter+2) = *(u8 *)(arg0 + 2);
                    *(u8 *)((u8*)&copyCenter+3) = *(u8 *)(arg0 + 3);
                    *(u8 *)((u8*)&copyCenter+4) = *(u8 *)(arg0 + 4);
                    *(u8 *)((u8*)&copyCenter+5) = *(u8 *)(arg0 + 5);
                    *(u8 *)((u8*)&copyCenter+6) = *(u8 *)(arg0 + 6);
                    *(u8 *)((u8*)&copyCenter+7) = *(u8 *)(arg0 + 7);
                    *(u8 *)((u8*)&copyCenter+8) = *(u8 *)(arg0 + 8);
                    *(u8 *)((u8*)&copyCenter+9) = *(u8 *)(arg0 + 9);
                    *(u8 *)((u8*)&copyCenter+10) = *(u8 *)(arg0 + 0xA);
                    *(u8 *)((u8*)&copyCenter+11) = *(u8 *)(arg0 + 0xB);
                    *(u8 *)((u8*)&copyCenter+12) = *(u8 *)(arg0 + 0xC);
                    *(u8 *)((u8*)&copyCenter+13) = *(u8 *)(arg0 + 0xD);
                    *(u8 *)((u8*)&copyCenter+14) = *(u8 *)(arg0 + 0xE);
                    *(u8 *)((u8*)&copyCenter+15) = *(u8 *)(arg0 + 0xF);
                    *(u8 *)((u8*)&copyCenter+16) = *(u8 *)(arg0 + 0x10);
                    *(u8 *)((u8*)&copyCenter+17) = *(u8 *)(arg0 + 0x11);
                    *(u8 *)((u8*)&copyCenter+18) = *(u8 *)(arg0 + 0x12);
                    *(u8 *)((u8*)&copyCenter+19) = *(u8 *)(arg0 + 0x13);
                    *(u8 *)((u8*)&copyCenter+20) = *(u8 *)(arg0 + 0x14);
                    *(u8 *)((u8*)&copyCenter+21) = *(u8 *)(arg0 + 0x15);
                    *(u8 *)((u8*)&copyCenter+22) = *(u8 *)(arg0 + 0x16);
                    *(u8 *)((u8*)&copyCenter+23) = *(u8 *)(arg0 + 0x17);
                    *(u8 *)((u8*)&copyCenter+24) = *(u8 *)(arg0 + 0x18);
                    *(u8 *)((u8*)&copyCenter+25) = *(u8 *)(arg0 + 0x19);
                    *(u8 *)((u8*)&copyCenter+26) = *(u8 *)(arg0 + 0x1A);
                    *(u8 *)((u8*)&copyCenter+27) = *(u8 *)(arg0 + 0x1B);
                    *(u8 *)((u8*)&copyCenter+28) = *(u8 *)(arg0 + 0x1C);
                    *(u8 *)((u8*)&copyCenter+29) = *(u8 *)(arg0 + 0x1D);
                    *(u8 *)((u8*)&copyCenter+30) = *(u8 *)(arg0 + 0x1E);
                    *(u8 *)((u8*)&copyCenter+31) = *(u8 *)(arg0 + 0x1F);
                    *(s32 *)((u8*)&copyCenter+32) = *(s32 *)(arg0 + 0x20);
                    *(s32 *)((u8*)&copyCenter+36) = *(s32 *)(arg0 + 0x24);
                    *(s32 *)((u8*)&copyCenter+40) = *(s32 *)(arg0 + 0x28);
                    *(s32 *)((u8*)&copyCenter+44) = *(s32 *)(arg0 + 0x2C);
                    *(s32 *)((u8*)&copyCenter+48) = *(s32 *)(arg0 + 0x30);
                    *(s32 *)((u8*)&copyCenter+52) = *(s32 *)(arg0 + 0x34);
                    *(s32 *)((u8*)&copyCenter+56) = *(s32 *)(arg0 + 0x38);
                    *(s32 *)((u8*)&copyCenter+60) = *(s32 *)(arg0 + 0x3C);
                    *(u8 *)((u8*)&copyCenter+64) = *(u8 *)(arg0 + 0x40);
                    *(u8 *)((u8*)&copyCenter+65) = *(u8 *)(arg0 + 0x41);
                    *(u8 *)((u8*)&copyCenter+66) = *(u8 *)(arg0 + 0x42);
                    *(u8 *)((u8*)&copyCenter+67) = *(u8 *)(arg0 + 0x43);
                    *(f32 *)((u8*)&copyCenter+68) = *(f32 *)(arg0 + 0x44);
                    *(s32 *)((u8*)&copyCenter+72) = *(s32 *)(arg0 + 0x48);
                    *(f32 *)((u8*)&copyCenter+76) = *(f32 *)(arg0 + 0x4C);
                    *(f32 *)((u8*)&copyCenter+80) = *(f32 *)(arg0 + 0x50);
                    *(s32 *)((u8*)&copyCenter+84) = *(s32 *)(arg0 + 0x54);
                    *(s32 *)((u8*)&copyCenter+88) = *(s32 *)(arg0 + 0x58);
                    *(void ***)((u8*)&copyCenter+92) = *(void ***)(arg0 + 0x5C);
                    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyCenter, temp_f31, temp_f31);
                    fn_80112EA0((u8*)&copyCenter, &rectCenter[0], context.str, temp_r19_2);
                    fn_801033F0((u8*)&copyCenter, 0);
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x + (var_f29 - (rectCenter[2] - rectCenter[0])));
                } else {
                    var_f0 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0) - context.x;
                    if (var_f29 < var_f0) {

                    } else {
                        var_f0 = var_f29;
                    }
                    var_f29 = var_f0;
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x);
                }
                var_r20 = 0;
            default:
block_207:
                var_r0_4 = 1;
                var_r3_8 = 1;
                var_r4_3 = 1;
                temp_r5 = context.str & 0xFF000000;
                var_r8_7 = 1;
                var_r9_7 = 1;
                var_r10_3 = 1;
                if (((u32)(temp_r5) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r10_3 = 0;
                }
                if ((var_r10_3 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r9_7 = 0;
                }
                if ((var_r9_7 == 0) && ((u32)(temp_r5) != 0xC0000000U)) {
                    var_r8_7 = 0;
                }
                if ((var_r8_7 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r4_3 = 0;
                }
                if ((var_r4_3 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_8 = 0;
                }
                if ((var_r3_8 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0_4 = 0;
                }
                if (var_r0_4 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x471, lbl_80329530 + 0x244);
                }
                var_r3_9 = 0;
                if (((u32)(temp_r21) == 0x80000000U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                    var_r3_9 = 1;
                }
                if (var_r3_9 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
                }
                if (context.str & 1) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A64, 0x3C, lbl_80320A18, context.str);
                }
                temp_r4_8 = context.str & 0xFF000000;
                var_r0_5 = 1;
                var_r3_10 = 1;
                var_r6_7 = 1;
                var_r7_7 = 1;
                var_r8_8 = 1;
                var_r9_8 = 1;
                if (((u32)(temp_r4_8) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r9_8 = 0;
                }
                if ((var_r9_8 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r8_8 = 0;
                }
                if ((var_r8_8 == 0) && ((u32)(temp_r4_8) != 0xC0000000U)) {
                    var_r7_7 = 0;
                }
                if ((var_r7_7 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r6_7 = 0;
                }
                if ((var_r6_7 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_10 = 0;
                }
                if ((var_r3_10 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0_5 = 0;
                }
                if (var_r0_5 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A04, 0x3D, lbl_803209CC, context.str);
                }
                if (fn_8002F72C(&reader.next, lbl_80329530) != 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_803209B8, 0x3E, lbl_80320980);
                }
                reader.cursor = context.str;
                goto block_275;
            case 1:
                var_r20 = 0;
                goto block_207;
            case 2:
                var_r20 = 1;
                goto block_207;
            }
        } else {
            temp_f24 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
            if (var_r20 != 0) {
                var_r3_11 = 0;
                if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                    var_r3_11 = 1;
                }
                if (var_r3_11 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329530 + 0x30, 0x138, lbl_80329530 + 0x48, arg0);
                }
                MoveCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *(f32 *)(arg0 + 0x4C));
            }
            var_r20 = 1;
            temp_r18_2 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
            temp_f26 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0);
            MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(arg0, (f32) -(*(s32 (**)(s32))(*(s32*)temp_r18_2+0x1C))(temp_r18_2) * temp_f26);
            Print__Q36nw4hbm2ut10CharWriterFUs(arg0, var_r19);
            SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, temp_f24);
block_275:
            var_r3_12 = 0;
            if ((temp_r31 == 0U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                var_r3_12 = 1;
            }
            if (var_r3_12 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
            }
            var_r19 = (reader.*reader.next)();
            goto loop_286;
        }
    }
    temp_r0_2 = *(s32 *)(arg0 + 0x58) & 0x300;
    if ((temp_r0_2 == 0x100) || (temp_r0_2 == 0x200)) {
        SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, (f64) temp_f28);
    } else {
        MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(arg0, temp_f28 - (f32) temp_f1_2);
    }
    return var_f29;
}

namespace nw4hbm { namespace ut { struct List { unsigned char data[0xA]; unsigned short stride; }; } }
struct List_Remove_Link { List_Remove_Link *prev; List_Remove_Link *next; };
struct List_Remove_List { void *head; void *tail; u16 count; u16 offset; };
