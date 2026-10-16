// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_800E6A44(void);
extern int lbl_8055DE20;
extern void fn_80128668(void);

extern "C" unsigned int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(unsigned int);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern const char lbl_80322094[];
extern const char lbl_80322070[];
extern const char lbl_80321F80[];
extern const char lbl_80321FAC[];
extern "C" void *GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(void *self) {
    if (*(void **)((char *)self + 4) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x172, lbl_80321FAC);
    }
    return *(void **)((char *)self + 4);
}

extern "C" void RegisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNodePFv_v(void *self, void *node, void (*callback)(void)) {
    void *pThis = self;
    void *pNode = node;
    void (*pCallback)(void) = callback;
    unsigned int level = OSDisableInterrupts();
    if (pNode == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);
    }
    *(void (**)(void))((char *)pNode + 8) = pCallback;
    void *iterator = (char *)pThis + 12;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)pThis + 8, &iterator, pNode);
    OSRestoreInterrupts(level);
}

extern "C" void UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(void *self, void *node) {
    unsigned int level = OSDisableInterrupts();
    if (node == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)self + 8, node);
    OSRestoreInterrupts(level);
}

extern "C" int fn_800E394C(int *arg0) { return *arg0; }

extern "C" void fn_800E5A8C(void) {
    fn_800E6A44();
}

void fn_800E80B4(void) {

}

extern "C" void fn_800E9B20(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x94) = arg1;
}

extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void *);
extern "C" void fn_800E9B9C(void *arg0) {
    DetachSound__Q34nw4r3snd11SoundHandleFv(*(void **)((char *)arg0 + 8));
}

extern int lbl_8055DE20;
extern void fn_80128668(void);
extern "C" int fn_800E9BE4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" int *fn_800E9C24(void) {
    return &lbl_8055DE20;
}

