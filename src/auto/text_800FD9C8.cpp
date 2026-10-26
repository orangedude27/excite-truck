// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void* this_, u32 a);
extern "C" void fn_8002F634(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern "C" void fn_80128668(void* arg0);
extern "C" void fn_800FB374(void);
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void*);
extern "C" void __ct__Q46nw4hbm3snd6detail10StrmPlayerFv(void*, void*);
extern "C" u8 lbl_80326D00[16];
extern "C" void fn_800FDE28(void* arg0);
extern "C" u32 lbl_8055DE70;

extern "C" u32 lbl_8055DE70;
extern "C" char lbl_80326C88[];
extern "C" s32 Prepare__Q46nw4hbm3snd6detail10StrmPlayerFPQ46nw4hbm3snd6detail14StrmBufferPoolQ56nw4hbm3snd6detail10StrmPlayer15StartOffsetTypeliPQ56nw4hbm3snd6detail10StrmPlayer12StrmCallbackUl(void*, void*, s32, s32, s32, s32, s32);
extern "C" void fn_800FDE28(void* arg0);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void* this_, u32 a);
extern "C" void fn_8002F634(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern "C" void fn_80128668(void* arg0);
extern "C" void fn_800FB374(void);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FD9C8(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *fn_800FDA20(void *arg0, void *arg1) {
    __ct__Q44nw4r3snd6detail10BasicSoundFv(arg0);
    *(void **)arg0 = lbl_80326D00;
    __ct__Q46nw4hbm3snd6detail10StrmPlayerFv((u8 *)arg0 + 0xD8, lbl_80326D00);
    *(void **)((u8 *)arg0 + 0x5F8) = arg1;
    *(u32 *)((u8 *)arg0 + 0x5F4) = 0;
    return arg0;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail9StrmSoundFv(void* arg0, s32 arg1) {
    void* temp_r3;
    void* temp_r3_2;

    if (arg0 != NULL) {
        if ((u8*)arg0 + 0xD8 != NULL) {
            fn_8002F634((u8*)arg0 + 0x184, &fn_800FB374, 0x1C, 0x20);
            temp_r3 = (u8*)arg0 + 0x178;
            if (temp_r3 != NULL) {
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv(temp_r3, 0);
            }
            temp_r3_2 = (u8*)arg0 + 0x16C;
            if (temp_r3_2 != NULL) {
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv(temp_r3_2, 0);
            }
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void*, int);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" char lbl_80325870[];
extern "C" char lbl_80325894[];
extern "C" char lbl_803258A0[];
extern "C" char lbl_803258C4[];
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail9StrmSoundFi_800FDCB8(void* arg0, int arg1) {
    int priority;
    void* list;
    void* node;
    void* end;
    void* soundNode;
    void* iterator;
    int otherPriority;

    SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(arg0, arg1);
    priority = *(u8*)((u8*)arg0 + 0x74) + *(int*)((u8*)arg0 + 0x40);
    if (priority > 0x7f) {
        priority = 0x7f;
    } else if (priority < 0) {
        priority = 0;
    }
    list = *(void**)((u8*)arg0 + 0x5f8);
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    }
    soundNode = (u8*)arg0 + 0xb8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8*)list + 4, soundNode);
    end = (u8*)list + 8;
    node = *(void**)end;
    iterator = end;
    while (node != iterator) {
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258C4, 0x23d, lbl_803258A0);
        }
        otherPriority = *(u8*)((u8*)node - 0x44) + *(int*)((u8*)node - 0x78);
        if (otherPriority > 0x7f) {
            otherPriority = 0x7f;
        } else if (otherPriority < 0) {
            otherPriority = 0;
        }
        if (priority < otherPriority) {
            break;
        }
        node = *(void**)node;
    }
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    }
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8*)list + 4, &node, soundNode);
}

extern "C" s32 fn_800FDDE8(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x5F4) != 0;
}

extern "C" void fn_800FDDFC(void* arg0) {
    fn_800FDE28(*(void**)((u8*)arg0 + 0x5F4));
}

extern "C" s32 fn_800FDE04(s8* arg0) {
    return (s32)(arg0 + 0xD8);
}

extern "C" s32 fn_800FDE0C(s8* arg0) {
    return (s32)(arg0 + 0xD8);
}

extern "C" u32* fn_800FDE14(void) {
    return &lbl_8055DE70;
}

