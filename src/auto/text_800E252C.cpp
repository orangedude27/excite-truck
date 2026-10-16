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
extern const char lbl_803221A8[];
extern const char lbl_80322438[];
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
    virtual VfObj *vf23();   // vtable 0x60
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
    virtual void vf15(float);   // vtable 0x40
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
typedef unsigned short u16;
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *fn_80128668(void *);
extern "C" void *__register_global_object(void *, void *, void *);
extern "C" void *fn_800E279C(void *);
extern "C" unsigned char lbl_8055DE18;
#pragma push
#pragma small_data off
extern int lbl_80407F6C;
extern int lbl_80407F60;
#pragma pop
extern "C" void *fn_8002F634(void *, void *, int, int);
extern "C" void *__dt__Q46nw4hbm3snd6detail7AxVoiceFv(void *, int);
extern "C" void *fn_800E2D74(void *, int);
extern "C" void TRKGetFreeBuffer(void *);
extern "C" void fn_800E4764(void *);
#pragma push
#pragma small_data off
extern u8 lbl_80322498[];
extern const char lbl_803220C4[];
extern const char lbl_803220A0[];
#pragma pop
typedef float f32;
#pragma push
#pragma small_data off
extern float lbl_80560FB0;
#pragma pop
extern float lbl_80560F00;
extern float lbl_80560F04;
#pragma push
#pragma small_data off
extern float lbl_80320E38[];
#pragma pop
extern "C" f32 SinFIdx__Q24nw4r4mathFf(f32 angle) {
    f32 index = __fabsf(angle);
    while (index >= lbl_80560F00) index -= lbl_80560F00;
    u16 quantized = ((u16 *)&index)[0];
    f32 *entry = (f32 *)((char *)lbl_80320E38 + ((quantized * 0x10) & 0xFF0));
    f32 value = entry[0] + (index - index) * entry[2];
    if (angle < lbl_80560F04) value = -value;
    return value;
}

extern "C" f32 CosFIdx__Q24nw4r4mathFf(f32 angle) {
    f32 index = __fabsf(angle);
    while (index >= lbl_80560F00) index -= lbl_80560F00;
    u16 quantized = ((u16 *)&index)[0];
    f32 *entry = (f32 *)((char *)lbl_80320E38 + ((quantized * 0x10) & 0xFF0));
    f32 fraction = index;
    return entry[1] + fraction * entry[3];
}

extern "C" void fn_800E2C98(void *arg0) {
    int *p = (int *)((char *)arg0 + 4);
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)arg0 = 0;
    *(int *)((char *)arg0 + 4) = (int)p;
    *(int *)((char *)arg0 + 8) = (int)p;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *Instance__15EmissionManagerFv(void) {
    if ((signed char)lbl_8055DE18 == 0) {
        int *manager = &lbl_80407F6C;
        fn_800E279C(manager);
        __register_global_object(manager, (void *)fn_800E2D74, &lbl_80407F60);
        lbl_8055DE18 = 1;
    }
    return &lbl_80407F6C;
}

extern "C" void *fn_800E2D74(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8002F634((char *)arg0 + 0x6ccc, (void *)__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8, 0xc, 3);
        fn_8002F634((char *)arg0 + 0x2c, (void *)__dt__Q46nw4hbm3snd6detail7AxVoiceFv, 0x1b0, 0x40);
        if ((char *)arg0 + 0x20 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 0x20, 0);
        if ((char *)arg0 + 0x14 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 0x14, 0);
        if ((char *)arg0 + 8 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 8, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

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

extern "C" void fn_800E402C(void *arg0) {
    OSDisableInterrupts();
    *(u8 *)((char *)arg0 + 0x6C31) = 0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void UpdateAllVoices__Q46nw4hbm3snd6detail9AxManagerFv(void *this_) {
    unsigned int level = OSDisableInterrupts();
    void *end = (char *)this_ + 0x18;
    void **iterator = *(void ***)end;
    while (iterator != end) {
        void *node = *iterator;
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        }
        fn_800E4764((char *)node - 0x1A8);
        iterator = *(void ***)node;
    }
    OSRestoreInterrupts(level);
}

extern "C" void __ct__Q46nw4hbm3snd6detail7AxVoiceFv(void *this_) {
    ((unsigned long *)this_)[0x00 / 4] = 0;
    ((unsigned long *)this_)[0x04 / 4] = 0;
    ((unsigned long *)this_)[0x08 / 4] = (unsigned long)&lbl_80322498;
    ((unsigned long *)this_)[0x10C / 4] = 0;
    ((u8 *)this_)[0x11C] = 0;
    ((u8 *)this_)[0x11D] = 0;
    ((u8 *)this_)[0x11E] = 0;
    ((u8 *)this_)[0x11F] = 0;
    ((u8 *)this_)[0x121] = 0;
    ((u8 *)this_)[0x122] = 0;
    ((u8 *)this_)[0x123] = 0;
    ((unsigned long *)this_)[0x1A8 / 4] = 0;
    ((unsigned long *)this_)[0x1AC / 4] = 0;
    ((unsigned long *)this_)[0x0C / 4] = 0;
    ((unsigned long *)this_)[0x10 / 4] = 0;
    ((unsigned long *)this_)[0x14 / 4] = 0;
    ((unsigned long *)this_)[0x18 / 4] = 0;
    ((unsigned long *)this_)[0x1C / 4] = 0;
    ((unsigned long *)this_)[0x20 / 4] = 0;
    ((unsigned long *)this_)[0x24 / 4] = 0;
    ((unsigned long *)this_)[0x28 / 4] = 0;
}

extern "C" int fn_800E4520(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void *__dt__Q46nw4hbm3snd6detail7AxVoiceFv(void *this_, int arg1) {
    if (this_ != 0) {
        *(void **)((char *)this_ + 8) = (void *)&lbl_80322498;
        int *base = (int *)this_;
        for (int i = 0; i < 2; i++) {
            int *p = base + 1;
            for (int j = 0; j < 4; j++) {
                if (*p != 0) {
                    TRKGetFreeBuffer(p);
                }
                p++;
            }
            base += 4;
        }
        if (arg1 > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void fn_800E519C(void *arg0) {
    unsigned int level = OSDisableInterrupts();
    u8 *p = (u8 *)arg0;
    p[0x11D] = 1;
    p[0x11F] = 0;
    p[0x123] |= 1;
    OSRestoreInterrupts(level);
}

extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void *this_, u8 paused) {
    unsigned int level = OSDisableInterrupts();
    if (*(u8 *)((char *)this_ + 0x11F) == paused) {
        OSRestoreInterrupts(level);
        return;
    }
    *(u8 *)((char *)this_ + 0x11F) = paused;
    u8 flags = *(u8 *)((char *)this_ + 0x123);
    *(u8 *)((char *)this_ + 0x123) = flags | 2;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800E5A8C(void) {
    fn_800E6A44();
}

extern "C" int GetSampleByDspAddress__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(const void *arg0, unsigned int arg1, int arg2) {
    unsigned int address = (unsigned int)arg0;
    int result = 0;
    if (address != 0) address += 0x80000000;
    switch (arg2) {
    case 0: { unsigned int delta = arg1 - address * 2; result = ((delta & 15) + ((delta >> 4) * 14)) - 2; break; }
    case 25: result = arg1 - address; break;
    case 10: result = arg1 - (address >> 1); break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x583, lbl_80322438); break;
    }
    return result;
}

extern "C" unsigned int GetSampleByByte__Q46nw4hbm3snd6detail7AxVoiceFUlQ56nw4hbm3snd6detail7AxVoice6Format(unsigned int arg0, int arg1) {
    int result = 0;
    switch (arg1) {
    case 0: { int rem = arg0 & 7; result = (arg0 >> 3) * 14; if (rem != 0) result += (rem - 1) * 2; break; }
    case 25: result = arg0; break;
    case 10: result = arg0 >> 1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x5A4, lbl_80322438); break;
    }
    return result;
}

void fn_800E80B4(void) {

}

extern "C" int fn_800E80F0(int arg0, int arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern void __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *);
extern void *lbl_80322880;
void __ct__Q44nw4r3snd6detail10BasicSoundFv(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(void **)arg0 = &lbl_80322880;
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(int *)((char *)arg0 + 0x18) = 0;
    *(int *)((char *)arg0 + 0x1C) = 0;
    *(int *)((char *)arg0 + 0x20) = 0;
    *(int *)((char *)arg0 + 0x24) = 0;
    *(float *)((char *)arg0 + 0x44) = lbl_80560FB0;
    *(float *)((char *)arg0 + 0x48) = lbl_80560FB0;
    *(int *)((char *)arg0 + 0x4C) = 0;
    *(int *)((char *)arg0 + 0x50) = 0;
    *(float *)((char *)arg0 + 0x54) = lbl_80560FB0;
    *(float *)((char *)arg0 + 0x58) = lbl_80560FB0;
    *(int *)((char *)arg0 + 0x5C) = 0;
    *(int *)((char *)arg0 + 0x60) = 0;
    *(int *)((char *)arg0 + 0x78) = -1;
    *(float *)((char *)arg0 + 0x7C) = lbl_80560FB0;
    *(float *)((char *)arg0 + 0x80) = lbl_80560FB0;
    *(int *)((char *)arg0 + 0x84) = 0;
    *(int *)((char *)arg0 + 0x88) = 0;
    *(int *)((char *)arg0 + 0xB8) = 0;
    *(int *)((char *)arg0 + 0xBC) = 0;
    *(int *)((char *)arg0 + 0xC0) = 0;
    *(int *)((char *)arg0 + 0xC4) = 0;
    *(int *)((char *)arg0 + 0xC8) = 0;
    *(int *)((char *)arg0 + 0xCC) = 0;
    *(int *)((char *)arg0 + 0xD0) = 0;
    *(int *)((char *)arg0 + 0xD4) = 0;
}

void fn_800E8ADC(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x65) == 0)
        *(unsigned char *)((char *)arg0 + 0x64) = 1;
}

extern "C" void fn_800E8F54(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x6C) = arg1;
    *(unsigned char *)((char *)arg0 + 0x66) = (unsigned int)((-arg1) & ~arg1) >> 31;
}

typedef void (*vfn0_t)(void*);
extern "C" void fn_800E9070(VfObj *this_) {
    VfObj *first = this_->vf23();
    first->vf6();
}

extern "C" int fn_800E90AC(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x67) != 0;
}

extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void *this_, int priority) {
    int valid = priority >= 0 && priority <= 0x7F;
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x202, lbl_803227EC, priority, 0, 0x7F);
    }

    *(char *)((char *)this_ + 0x74) = priority;
    void *player = *(void **)((char *)this_ + 0x10);
    if (player != 0) {
        detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(player, this_);
        detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(player, this_);
    }
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf(void *this_, float vol) {
    BasicSound *sound = (BasicSound *)this_;
    if (!(vol >= lbl_80560FB0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x216, lbl_80322830);
    }
    *(f32*)&((u8*)sound)[0x8C] = vol;
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800E9AAC(void *this_, float vol) {
    BasicSound *sound = (BasicSound *)this_;
    if (!(vol >= lbl_80560FB0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x234, lbl_80322858);
    }
    *(f32*)&((u8*)sound)[0x98] = vol;
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
    VfObjF *obj = (VfObjF *)arg0;
    VfObjF *result = obj->vf23();
    result->vf15(arg1);
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
extern const char lbl_803221A8[];
extern const char lbl_80322438[];
