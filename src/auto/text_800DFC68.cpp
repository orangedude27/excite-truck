// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" unsigned int lbl_8055DE10;
extern void UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(void*, void*);
extern "C" void UnbindAnimationSelf__Q36nw4hbm3lyt6WindowFPQ36nw4hbm3lyt13AnimTransform(void* self, void* anim) {
    int offset = 0;
    int count = 0;
    while (count < *((unsigned char*)self + 0x100)) {
        void* pane = *(void**)(*(unsigned char**) ((unsigned char*)self + 0xFC) + offset + 4);
        (*(void (**)(void*, void*))(*(unsigned int**)pane + 5))(pane, anim);
        offset += 8;
        count++;
    }
    UnbindAnimationSelf__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimTransform(self, anim);
}

extern "C" unsigned int* fn_800E2518(void) { extern unsigned int lbl_8055DE10; return &lbl_8055DE10; }

