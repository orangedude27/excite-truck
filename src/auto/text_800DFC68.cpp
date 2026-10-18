#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" unsigned int lbl_8055DE10;
extern void UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(void*, void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" const char lbl_803204F8[];
extern "C" const char lbl_803204BC[];
extern "C" const char lbl_80320C14[];
extern "C" const char lbl_80320C60[];
extern void* FindAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(void*, void*);
extern "C" void* FindAnimationLink__Q36nw4hbm3lyt6WindowFPQ36nw4hbm3lyt13AnimTransform(void* self, void* anim) {
    void* result = FindAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(self, anim);
    if (result != 0) return result;
    int offset;
    int count;
    count = 0;
    offset = 0;
    while (count < *((unsigned char*)self + 0x100)) {
        void* pane = *(void**)(*(unsigned char**)((unsigned char*)self + 0xFC) + offset + 4);
        void** vtable = *(void***)pane;
        void* (*fn)(void*, void*) = (void* (*)(void*, void*))vtable[8];
        result = fn(pane, anim);
        if (result != 0) return result;
        offset += 8;
        count++;
    }
    return 0;
}

extern "C" void GetVtxColor__Q36nw4hbm3lyt7PictureCFUl_800E0238(unsigned char* out, const void* self, unsigned long idx) {
    if (idx >= 4) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320C14, 0x168, lbl_80320C60);
    const unsigned char* p = (const unsigned char*)((unsigned long)self + idx * 4 + 0xE4);
    out[0] = p[0]; out[1] = p[1]; out[2] = p[2]; out[3] = p[3];
}

extern "C" void SetVtxColor__Q36nw4hbm3lyt7PictureFUlQ36nw4hbm2ut5Color_800E02C4(void* self, unsigned long idx, const unsigned char* color) {
    if (idx >= 4) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320C14, 0x173, lbl_80320C60);
    unsigned char* p = (unsigned char*)((unsigned long)self + idx * 4 + 0xE4);
    p[0] = color[0]; p[1] = color[1]; p[2] = color[2]; p[3] = color[3];
}

extern "C" unsigned char GetVtxColorElement__Q36nw4hbm3lyt7PictureCFUl_800E0350(void* self, unsigned long idx) {
    if (idx >= 0x10) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803204F8, 0xC7, lbl_803204BC);
    unsigned long hi = idx & ~3UL;
    unsigned long lo = idx & 3;
    unsigned char* p = (unsigned char*)((unsigned long)self + hi);
    return p[lo + 0xE4];
}

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7PictureFUlUc_800E03BC(void* this_, unsigned long idx, unsigned char color) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    extern const char lbl_803204B0[];
    extern const char lbl_80320474[];
    if (idx >= 0x10) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803204B0, 0xD4, lbl_80320474);
    unsigned long hi = idx & ~3UL;
    unsigned long lo = idx & 3;
    unsigned char* p = (unsigned char*)((unsigned long)this_ + hi);
    p[lo + 0xE4] = color;
}

extern "C" void AnimateSelf__Q36nw4hbm3lyt6WindowFUl(void* self, unsigned long arg) {
    extern void AnimateSelf__Q36nw4hbm3lyt4PaneFUl(void*, unsigned long);
    AnimateSelf__Q36nw4hbm3lyt4PaneFUl(self, arg);
    if (!(*((unsigned char*)self + 0xCF) & 1) && (arg & 1)) {
        int count = 0;
        int offset = 0;
        while (count < *((unsigned char*)self + 0x100)) {
            void* pane = *(void**)(*(unsigned char**)((unsigned char*)self + 0xFC) + offset + 4);
            void** vtable = *(void***)pane;
            void (*fn)(void*, unsigned long) = (void (*)(void*, unsigned long))vtable[7];
            fn(pane, arg);
            offset += 8;
            count++;
        }
    }
}

extern "C" void UnbindAnimationSelf__Q36nw4hbm3lyt6WindowFPQ36nw4hbm3lyt13AnimTransform(void* self, void* anim) {
    int offset = 0, count = 0;
    while (count < *((unsigned char*)self + 0x100)) {
        void* pane = *(void**)(*(unsigned char**)((unsigned char*)self + 0xFC) + offset + 4);
        struct VTable { void* pad[5]; void (*call)(void*, void*); };
        VTable* vtable = *(VTable**)pane;
        vtable->call(pane, anim);
        offset += 8;
        count++;
    }
    UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(self, anim);
}

extern "C" int GetFrameMaterial__Q36nw4hbm3lyt6WindowCFUl(void* self, unsigned int index) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    extern const char lbl_80320C14[];
    extern const char lbl_80320CC8[];
    if (index >= 8) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320C14, 0x292, lbl_80320CC8);
    if (index >= *((unsigned char*)self + 0x100)) return 0;
    return *(int*)(*(unsigned char**)((unsigned char*)self + 0xFC) + index * 8 + 4);
}

extern "C" void fn_800E2508(void* self) {
    struct VTable23 {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual void d20(); virtual void dispatch();
    };
    ((VTable23*)self)->dispatch();
}

extern "C" unsigned int* fn_800E2518(void) { extern unsigned int lbl_8055DE10; return &lbl_8055DE10; }

