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

#pragma push
#pragma small_data off
extern float lbl_80560FB0;
#pragma pop
extern "C" void fn_800E9B18(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x90) = farg0;
}

extern "C" void fn_800E9B20(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x94) = arg1;
}

extern "C" void fn_800E9B28(void **arg0, float arg1) {
    void **vtable = (void **)*arg0;
    void *(*get)(void);
    void *result;
    void **resultVtable;
    void (*set)(float);
    get = (void *(*)(void))vtable[23];
    result = get();
    resultVtable = (void **)*(void **)result;
    set = (void (*)(float))resultVtable[16];
    set(arg1);
}

extern "C" void fn_800E9B74(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    *(int *)((char *)arg0 + 0x18) = arg1;
    *(int *)((char *)arg0 + 0x1C) = arg2;
    *(int *)((char *)arg0 + 0x20) = arg3;
    *(int *)((char *)arg0 + 0x24) = arg4;
}

extern "C" int fn_800E9B88(void *arg0) {
    return *(int *)((char *)arg0 + 8) != 0;
}

extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void *);
extern "C" void fn_800E9B9C(void *arg0) {
    DetachSound__Q34nw4r3snd11SoundHandleFv(*(void **)((char *)arg0 + 8));
}

extern "C" void fn_800E9BA4(void *arg0, int arg1) {
    int var_r31;
    void *vtable;

    var_r31 = arg1;
    *(int *)((char *)arg0 + 0x78) = var_r31;
    vtable = *(void **)arg0;
    (*(void *(**)(void *))((char *)vtable + 0x5C))(vtable);
    *(int *)((char *)arg0 + 0x4) = var_r31;
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

