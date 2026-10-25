// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, unsigned int);
extern "C" void fn_80128668(void*);

extern "C" void __dt__Q46nw4hbm3snd6detail9SeqPlayerFv(s32 arg0 = 0);


extern "C" void fn_800F0E64(s32);
extern "C" u32 lbl_8055DE48;

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F078C(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_800F07E4(s32 arg0) {
    __dt__Q46nw4hbm3snd6detail9SeqPlayerFv(arg0 - 8);
}

extern "C" void InitParam__Q44nw4r3snd6detail10BasicSoundFv(void);
extern "C" void fn_800EEE8C(void*, const void*);
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void);
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, unsigned int);
extern "C" void fn_80128668(void*);
extern "C" void* lbl_8032428C;
#pragma push
#pragma small_data off
extern "C" u8 lbl_80324060[];
extern "C" u8 lbl_803240D4[];
#pragma pop
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void Setup__Q46nw4hbm3snd6detail9SeqPlayerFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback(void*, unsigned long, int, int, void*);
extern "C" void fn_800F0850(void *arg0) {
    InitParam__Q44nw4r3snd6detail10BasicSoundFv();
    *(s32*)((u8*)arg0 + 0x1EC) = 0;
    *(s32*)((u8*)arg0 + 0x1F0) = 0;
}

extern "C" void Setup__Q46nw4hbm3snd6detail8SeqSoundFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback(void *arg0, void *arg1, unsigned long arg2, int arg3, void *arg4) {
    if (arg4 == 0) Panic__Q26nw4hbm2dbFPCciPCce((char*)&lbl_80324060, 0x57, (char*)&lbl_80324060 + 0x14);
    if (*(s32*)((u8*)arg0 + 0x10) == 0) Panic__Q26nw4hbm2dbFPCciPCce((char*)&lbl_80324060, 0x58, (char*)&lbl_80324060 + 0x40);
    void (**vt)(void*) = *(void (***)(void*))arg0;
    vt[0x58/4](arg0);
    Setup__Q46nw4hbm3snd6detail9SeqPlayerFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback((u8*)arg0 + 0xD8, (unsigned long)arg1, (int)arg2, arg3, arg4);
}

extern "C" void SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl(void*, const void*, long);
#pragma small_data off
extern "C" u8 lbl_803240D4[];
extern "C" void SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl(void*, const void*, s32);
extern "C" void Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCvl(void* arg0, const void* arg1, s32 arg2) {
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324060, 0x70, (const char*)lbl_803240D4);
    SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl((u8*)arg0 + 0xD8, arg1, arg2);
}

extern "C" void Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(void *);
extern "C" s32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(s32);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void fn_800EC848(void *, void *);
extern "C" const char lbl_80324378[];
extern "C" const char lbl_80324350[];
extern "C" const char lbl_80324344[];
extern "C" const char lbl_80324320[];
extern "C" void Shutdown__Q46nw4hbm3snd6detail8SeqSoundFv(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1E8) != 0) {
        void *ptr = *(void **)((u8 *)arg0 + 0x1EC);
        if (ptr != 0) {
            void **vtable = *(void ***)ptr;
            ((void (*)(void *, s32))vtable[4])(ptr, *(s32 *)((u8 *)arg0 + 0x1F0));
        }
    }
    Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(arg0);
    void *list = *(void **)((u8 *)arg0 + 0x1E4);
    if (arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324378, 0x86, lbl_80324350);
    s32 interrupts = OSDisableInterrupts();
    if (*(s32 *)((u8 *)list + 4) == 0) {
        OSRestoreInterrupts(interrupts);
        return;
    }
    if (arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)list + 4, (u8 *)arg0 + 0xB8);
    void **vtable = *(void ***)arg0;
    ((void (*)(void *, s32))vtable[3])(arg0, -1);
    fn_800EC848(list, arg0);
    OSRestoreInterrupts(interrupts);
}

extern "C" s32 __dt__15shdStateMachineFv(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        ((void (*)(s32, s32))__dt__Q46nw4hbm3snd6detail9SeqPlayerFv)(arg0 + 0xD8, -1);
        if (arg1 > 0) {
            fn_80128668((void *)arg0);
        }
    }
    return arg0;
}

extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void *, int);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" const char lbl_80324314[];
extern "C" const char lbl_803242F0[];
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail8SeqSoundFi(void *arg0, int arg1) {
    int priority;
    void *list;
    void *node;
    void *sentinel;
    void *soundNode;

    SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(arg0, arg1);
    priority = *(u8 *)((u8 *)arg0 + 0x74) + *(s32 *)((u8 *)arg0 + 0x40);
    if (priority <= 0x7F) priority &= ~(priority >> 31);
    else priority = 0x7F;
    list = *(void **)((u8 *)arg0 + 0x1E4);
    if (arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
    soundNode = (u8 *)arg0 + 0xB8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)list + 4, soundNode);
    node = *(void **)((u8 *)list + 8);
    sentinel = (u8 *)list + 8;
    while (node != sentinel) {
        int nodePriority;
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324314, 0x23D, lbl_803242F0);
        nodePriority = *(u8 *)((u8 *)node - 0x44) + *(s32 *)((u8 *)node - 0x78);
        if (nodePriority <= 0x7F) nodePriority &= ~(nodePriority >> 31);
        else nodePriority = 0x7F;
        if (priority < nodePriority) break;
        node = *(void **)node;
    }
    if (arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
    {
        void *iterator = node;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8 *)list + 4, &iterator, soundNode);
    }
}

#pragma small_data on
extern "C" s32 fn_800F0E24(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x1E0) != 0;
}

extern "C" void fn_800F0E38(void* arg0) {
    fn_800F0E64(*(s32*)((u8*)arg0 + 0x1E0));
}

extern "C" s32 fn_800F0E40(s32 arg0) {
    return arg0 + 0xD8;
}

extern "C" s32 fn_800F0E48(s32 arg0) {
    return arg0 + 0xD8;
}

extern "C" u32* fn_800F0E50(void) {
    return &lbl_8055DE48;
}

