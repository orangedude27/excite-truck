// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" unsigned int lbl_8055DE10;
extern void UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(void*, void*);
extern "C" void UnbindAnimationSelf__Q36nw4hbm3lyt6WindowFPQ36nw4hbm3lyt13AnimTransform(void* self, void* anim) {
    int offset = 0, count = 0;
    while (count < *((unsigned char*)self + 0x100)) {
        void* pane = *(void**)(*(unsigned char**)((unsigned char*)self + 0xFC) + offset + 4);
        (*(void (**)(void*, void*))(*(unsigned int**)pane + 5))(pane, anim);
        offset += 8; count++;
    }
    extern void UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(void*, void*);
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

extern "C" void fn_800E2508(void* self) { register unsigned int* vtable = *(unsigned int**)self; register unsigned int target = vtable[0x17]; ((void (*)(void))target)(); }

extern "C" unsigned int* fn_800E2518(void) { extern unsigned int lbl_8055DE10; return &lbl_8055DE10; }

