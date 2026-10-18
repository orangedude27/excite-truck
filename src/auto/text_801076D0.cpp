#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/gki/common/gki.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" u8 fn_8010A33C(void);
extern "C" void* fn_80108FFC(void*, const void*);
extern "C" const char lbl_803290E8[];
extern "C" void* fn_80107FE4(void* arg0, const void* arg1) {
    fn_80108FFC(arg0, arg1);
    *(const char**)arg0 = lbl_803290E8;
    return arg0;
}

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
namespace nw4hbm { namespace ut { struct List { unsigned char data[0xA]; unsigned short stride; }; } }
