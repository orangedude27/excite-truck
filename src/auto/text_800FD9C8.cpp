// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);

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

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 Prepare__Q46nw4hbm3snd6detail9StrmSoundFPQ46nw4hbm3snd6detail14StrmBufferPoolQ56nw4hbm3snd6detail10StrmPlayer15StartOffsetTypeliPQ56nw4hbm3snd6detail10StrmPlayer12StrmCallbackUl(void* self, void* pool, s32 start, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct V { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o(); virtual void p(); virtual void q(); virtual void r(); virtual void s(); virtual void t(); virtual void u(); };
    const char* file = lbl_80326C88;
    if (*(s32*)((u8*)self + 0x10) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x42, file + 0x14);
    }
    if (pool == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x43, file + 0x48);
    }
    if (pool == 0) return 0;
    ((V*)self)->u();
    return Prepare__Q46nw4hbm3snd6detail10StrmPlayerFPQ46nw4hbm3snd6detail14StrmBufferPoolQ56nw4hbm3snd6detail10StrmPlayer15StartOffsetTypeliPQ56nw4hbm3snd6detail10StrmPlayer12StrmCallbackUl((u8*)self + 0xD8, pool, start, arg3, arg4, arg5, arg6);
}

extern "C" void Shutdown__Q46nw4hbm3snd6detail9StrmSoundFv(void *self) {
    extern void Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(void*);
    extern int OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(int);
    extern void fn_800EC848(void*, void*);
    extern char lbl_80326DF0[];
    extern char lbl_80326DC8[];
    extern char lbl_80325894[];
    extern char lbl_80325870[];
    extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);
    struct V { virtual void a(); virtual void b(int); };
    void *pool4;
    int save4;
    Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(self);
    pool4 = *(void **)((char *)self + 0x5F8);
    if (self == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326DF0, 0x86, lbl_80326DC8);
    save4 = OSDisableInterrupts();
    if (*(int *)((char *)pool4 + 4) == 0) {
        OSRestoreInterrupts(save4);
        return;
    }
    if (self == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)pool4 + 4, (char *)self + 0xB8);
    ((V *)self)->b(-1);
    fn_800EC848(pool4, self);
    OSRestoreInterrupts(save4);
}

#pragma pop
/* Destructor for nw4hbm::snd::detail::StrmSound: destroy embedded player/list members, then optionally free. */
extern "C" void* __dt__Q46nw4hbm3snd6detail9StrmSoundFv(void* self, s32 deleteFlag) {
    void* linkList1;
    void* linkList2;

    if (self != NULL) {
        if ((u8*)self + 0xD8 != NULL) {
            fn_8002F634((u8*)self + 0x184, &fn_800FB374, 0x1C, 0x20);
            linkList1 = (u8*)self + 0x178;
            if (linkList1 != NULL) {
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv(linkList1, 0);
            }
            linkList2 = (u8*)self + 0x16C;
            if (linkList2 != NULL) {
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv(linkList2, 0);
            }
        }
        if (deleteFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void*, int);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);
extern "C" char lbl_80325870[];
extern "C" char lbl_80325894[];
extern "C" char lbl_803258A0[];
extern "C" char lbl_803258C4[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail9StrmSoundFi_800FDCB8(void* arg0, int arg1) {
    struct LinkListImpl {
        void* unused;
        void* head;
    };
    struct PriorityList {
        void* unused;
        LinkListImpl list;
    };
    void* soundNode;
    int priority;
    PriorityList* list;
    void* end;
    void* cursor;
    int value;
    SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(arg0, arg1);
    value = *(u8*)((u8*)arg0 + 0x74) + *(s32*)((u8*)arg0 + 0x40);
    priority = (value <= 0x7f) ? (value & ~(value >> 31)) : 0x7f;
    list = *(PriorityList**)((u8*)arg0 + 0x5f8);
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    }
    soundNode = (u8*)arg0 + 0xb8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(&list->list, soundNode);
    end = &list->list.head;
    cursor = list->list.head;
    while (cursor != end) {
        if (cursor == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258C4, 0x23d, lbl_803258A0);
        }
        value = *(u8*)((u8*)cursor - 0x44) + *(s32*)((u8*)cursor - 0x78);
        value = (value <= 0x7f) ? (value & ~(value >> 31)) : 0x7f;
        if (priority < value) {
            break;
        }
        cursor = *(void**)cursor;
    }
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    }
    void* node = cursor;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(&list->list, &node, soundNode);
}
#pragma pop
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
extern "C" void Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(void *);
extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void fn_800EC848(void *, void *);
extern "C" char lbl_80326DF0[];
extern "C" char lbl_80326DC8[];
extern "C" char lbl_80325870[];
extern "C" char lbl_80325894[];

