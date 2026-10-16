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

extern "C" s32 fn_8010C7EC(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" s32 fn_8010D0F0(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" void* fn_80111B64(void* arg0) {
    extern void __ct__Q36nw4hbm2ut10CharWriterFv(void*);
    extern f32 lbl_80561178;
    extern s32 lbl_8055DEB8;
    __ct__Q36nw4hbm2ut10CharWriterFv(arg0);
    *(f32*)((char*)arg0 + 0x4C) = lbl_80561178;
    *(f32*)((char*)arg0 + 0x50) = lbl_80561178;
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

