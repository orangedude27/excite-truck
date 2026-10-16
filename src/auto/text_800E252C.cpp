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
extern const char lbl_80322790[];
extern const char lbl_80322830[];
extern const char lbl_80322858[];
extern const char lbl_803227EC[];
extern "C" void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern "C" void detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
// Vtable dispatcher class for indirect virtual calls (MWCC ABI: 2 leading dtor slots).
class VfObj {
public:
    virtual ~VfObj();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();   // vtable 0x60 = 10th named method (0x18 + 9*4)
    virtual void vf17();   // vtable 0x64
    virtual void vf18();   // vtable 0x68
    virtual void vf19();   // vtable 0x6C
    virtual void vf20();   // vtable 0x70
    virtual void vf21();   // vtable 0x74
    virtual void vf22();   // vtable 0x78
    virtual void vf23();   // vtable 0x7C
};
// fn_800E9B28 variant: vf23 returns VfObj* (vtable 0x5C), vf12 takes a float (0x40).
class VfObjF {
public:
    virtual ~VfObjF();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(float);   // vtable 0x40
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual VfObjF *vf23();   // vtable 0x5C
};
// Minimal shapes matching the target's use of BasicSound/SoundPlayer (0x10 player
// field, byte field at 0x74, and Remove/Insert calls taking the raw pointers).
class BasicSound;
class SoundPlayer;
typedef unsigned char u8;
typedef float f32;
#pragma push
#pragma small_data off
extern float lbl_80560FB0;
#pragma pop
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

typedef void (*vfn0_t)(void*);
extern "C" void fn_800E9070(void *arg0) {
    VfObj *obj = (VfObj *)arg0;
    obj->vf16();
    obj->vf17();
}

extern "C" int fn_800E90AC(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x67) != 0;
}

extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void *this_, int priority) {
    int priority_ = priority;
    BasicSound *sound = (BasicSound *)this_;
    if (!(priority_ >= 0 && priority_ <= 0x7F)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x202, lbl_803227EC, priority_, 0, 0x7F);
    }
    *(u8 *)((char *)this_ + 0x74) = priority_;
    SoundPlayer *player = (SoundPlayer *)*(void **)((char *)this_ + 0x10);
    if (player != 0) {
        detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(player, this_);
        detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(player, this_);
    }
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf(void *this_, float vol) {
    if (!(vol >= lbl_80560FB0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x216, lbl_80322830);
    }
    *(f32 *)&((u8 *)this_)[0x8C] = vol;
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800E9AAC(void *this_, float vol) {
    if (!(vol >= lbl_80560FB0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x234, lbl_80322858);
    }
    *(f32 *)&((u8 *)this_)[0x98] = vol;
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

extern "C" void fn_800E9B28(void *arg0, float arg1) {
    float f = arg1;
    void *obj = arg0;
    void *result = ((void *(*)(void *))(*(void ***)obj)[0x5c / 4])(obj);
    ((void (*)(void *, float))(*(void ***)result)[0x40 / 4])(result, f);
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

#pragma push
#pragma small_data off
#pragma pop
extern "C" void fn_800E9BA4(void *this_, int vol) {
    int v = vol;

    *(int *)((char *)this_ + 0x78) = v;
    void *vtable = *(void **)this_;
    (*(void (**)(void *))((char *)vtable + 0x5C))(vtable);
    *(int *)((char *)this_ + 0x4) = v;
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

