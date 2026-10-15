#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Forward declarations for DisposeCallbackManager cluster */
extern "C" void fn_8002F634(void* a, void* b, s32 c, s32 d);
extern "C" void* __dt__Q46nw4hbm3snd6detail7ChannelFv(void*, s32);
extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32 level);
extern "C" void __register_global_object(void* p, void* dtor, void* allocator);
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54(
    void* this_, s32 flag);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, u32);
extern "C" void fn_80128668(void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char* file, int line,
                                              const char* fmt, ...);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
    void*, void*, void*);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);

#pragma push
#pragma small_data off
extern u8 lbl_8040EC90[];
extern u8 lbl_80412790[];
extern u8 lbl_8041279C[];
extern u8 lbl_80322B74[];
extern u8 lbl_80322B50[];
#pragma pop

extern u8 lbl_8055DE30;

extern s32 fn_80128668(void);

extern "C" void fn_800EAEB0(void) {
    fn_8002F634(&lbl_8040EC90, &__dt__Q46nw4hbm3snd6detail7ChannelFv, 0xE8, 0x41);
}

extern "C" void* GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void) {
    u32 level;
    void* ptr;
    s8 tmp;
    
    level = OSDisableInterrupts();
    tmp = (s8)lbl_8055DE30;
    if (tmp != 0) {
        goto skip_init;
    }
    
    ptr = &lbl_8041279C[4];
    *(u32*)&lbl_8041279C[4] = 0;
    *(u32*)&lbl_8041279C[8] = 0;
    *(u32*)&lbl_8041279C[0] = 0;
    *(void**)&lbl_8041279C[4] = ptr;
    *(void**)&lbl_8041279C[8] = ptr;
    __register_global_object(&lbl_8041279C, (void*)&__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54, &lbl_80412790);
    lbl_8055DE30 = 1;
    
skip_init:
    OSRestoreInterrupts(level);
    return &lbl_8041279C;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
    void* this_, void* pCallback) {
    u32 level;
    void* pThis;
    void* pCb;
    void* node;

    pThis = this_;
    pCb = pCallback;
    node = (void*)((u8*)this_ + 4);
    level = OSDisableInterrupts();

    if (pCb == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B74, 0x233,
                                     (const char*)lbl_80322B50);
    }

    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
        pThis, &node, pCb);

    OSRestoreInterrupts(level);
}

extern "C" s32 fn_800ECE68(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_800ED058(void) {
    return;
}

extern "C" f32 fn_800ED064(void *arg0) {
    return ((f32 *)arg0)[0x30 / 4];
}

extern "C" f32 fn_800ED06C(void *arg0) {
    return ((f32 *)arg0)[0x2C / 4];
}

extern "C" f32 fn_800ED074(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" f32 fn_800ED07C(void *arg0) {
    return ((f32 *)arg0)[0x20 / 4];
}

#pragma push
#pragma small_data off
#pragma pop
s32 fn_800ED0BC(s32 arg0) {
    u8 val = ((u8 *)arg0)[0x16];
    s32 t = -(s32)val;
    return ((t | (s32)val) >> 31);
}
s32 fn_800ED0D0(s32 arg0) {
    return ((u8 *)arg0)[0x15] != 0;
}
#pragma push
#pragma small_data off
#pragma pop
void fn_800ED0E4(s32 arg0) {
    arg0 -= 8;
    fn_800ED058();
}
#pragma push
#pragma small_data off
#pragma pop
s32 fn_800ED0F4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}
void fn_800F0750(void) {
    return;
}

