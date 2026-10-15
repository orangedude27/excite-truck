// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern "C" s32 fn_80128668(void*);
extern "C" void fn_801CB750(s32);
extern void* lbl_8032F0E8;
extern f32 lbl_80561754;
extern f32 lbl_8056177C;

void fn_80158F34(void) {

}

extern "C" void fn_80159724(void) {
}

extern "C" void fn_8015CD0C(void) {

}

extern "C" void fn_8015CDD8(void) {
}

extern "C" void fn_8015E0FC(void) {
}

extern "C" s32 fn_80159338(void) {
    return 3;
}

extern "C" void* fn_80159340(void* arg0, s32 arg1) {
    if (arg0 != NULL) {
        void* field_278 = *(void**)((u8*)arg0 + 0x278);
        *(void**)((u8*)arg0 + 0) = &lbl_8032F0E8;
        if (field_278 != NULL) {
            void* obj = *(void**)field_278;
            void (*method)(void*, s32) = *(void (**)(void*, s32))*((u8**)obj + 2);
            method(field_278, 1);
        }
        if (arg0 != NULL && ((u8*)arg0 + 8) != NULL) {
            *(u32*)((u8*)arg0 + 8) = 0;
            *(u32*)((u8*)arg0 + 0xC) = 0;
            *(u32*)((u8*)arg0 + 0x10) = 0;
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_801593F0(void* arg0) {
    void* vtable = *(void**)arg0;
    ((void (*)())((u8**)vtable)[0x21])();
    
    f32 var_260 = *(f32*)((u8*)arg0 + 0x260);
    f32 var_24c = *(f32*)((u8*)arg0 + 0x24c);
    *(f32*)((u8*)arg0 + 0x25c) = 1.0f;
    
    if (var_260 > var_24c) {
        if (*(s32*)((u8*)arg0 + 0x268) != 0) {
            fn_801CB750(*(s32*)((u8*)arg0 + 4));
        }
        *(f32*)((u8*)arg0 + 0x260) = 1.0f;
    }
    
    void* field_278 = *(void**)((u8*)arg0 + 0x278);
    *(f32*)((u8*)arg0 + 0x264) = 1.0f;
    *(f32*)((u8*)arg0 + 0x258) = 0.5f;
    
    if (field_278 != NULL) {
        *(u8*)((u8*)field_278 + 0x4A) = 1;
        *(u8*)((u8*)field_278 + 0x4C) = 0;
    }
}

