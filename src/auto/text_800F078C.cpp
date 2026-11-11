// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

namespace nw4hbm { namespace snd { namespace detail {

/* nw4hbm::ut::LinkListNode: intrusive list node; it lives inside the object
 * on the list, so a sound is reached from its node at node - 0xB8. */
struct LinkNode {
    struct LinkNode *next; /* 0x00 */
    void *data;            /* 0x04 */
};

/* nw4hbm::ut::detail::LinkListImpl: list walked until the cursor equals
 * &tail, so an empty list is the one with head == NULL. */
struct LinkList {
    struct LinkNode *head; /* 0x00 */
    struct LinkNode *tail; /* 0x04 */
};

/* nw4hbm::snd::detail::SoundInstanceManager (SoundInstanceManager.h): the
 * fixed pool of sounds one player can play at a time. */
struct SoundInstanceManager {
    void *freeList;             /* 0x00 shut-down sounds, ready to be reused */
    struct LinkList activeList; /* 0x04 sounds now playing, best priority first */
};

/* nw4hbm::snd::detail::SeqSound::SeqLoadCallback: the SoundArchivePlayer's
 * hook that finishes an asynchronous sequence-data load.  Prepare() hands it
 * the sound and the completion function; a sound that goes away first uses
 * the 0x10 slot to drop its pending request. */
struct SeqLoadCallback {
    virtual void v0() = 0; /* 0x08 */
    virtual void Bind(void (*func)(int, const void *, unsigned long, void *),
                      void *sound, unsigned long arg) = 0;   /* 0x0C */
    virtual void Cancel(unsigned long arg) = 0;               /* 0x10 */
};

/* Virtual interface carried by every sound object; the two leading
 * destructor slots put the first method at 0x08. */
struct SoundInterface {
    virtual void v0() = 0;                                /* 0x08 */
    virtual void DetachFromPlayer(int playerIndex) = 0;   /* 0x0C */
};

/* nw4hbm::snd::detail::SeqSound: a sequence (BGM) sound playing through a
 * SeqPlayer (at 0xD8); only the fields this file touches are named. */
struct SeqSound {
    void *vtable;                                   /* 0x000 */
    u8 pad_004[0x0B8 - 0x004];
    struct LinkNode link;                           /* 0x0B8 node in activeList */
    u8 pad_0C0[0x1E4 - 0x0C0];
    struct SoundInstanceManager *instanceManager;   /* 0x1E4 owner's sound pool */
    u8 isAsyncLoading;                              /* 0x1E8 sequence data still being read */
    struct SeqLoadCallback *asyncCallback;          /* 0x1EC */
    unsigned long asyncCallbackArg;                 /* 0x1F0 argument for that callback */
    void Shutdown();
    void SetPlayerPriority(int);
};

}}}
namespace nw4hbm { namespace ut { struct LinkListNode; }}
namespace nw4hbm { namespace ut { namespace detail {
struct LinkListImpl { void Erase(nw4hbm::ut::LinkListNode*); };
}}}
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void);
extern "C" void fn_800EEE8C(void *, const void *);
extern "C" char lbl_8032428C[];
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

extern "C" void *fn_800F07EC(void *arg0, s32 arg1) {
    __ct__Q44nw4r3snd6detail10BasicSoundFv();
    *(void **)arg0 = lbl_8032428C;
    fn_800EEE8C((u8 *)arg0 + 0xD8, lbl_8032428C);
    *(s32 *)((u8 *)arg0 + 0x1E4) = arg1;
    *(s32 *)((u8 *)arg0 + 0x1E0) = 0;
    *(u8 *)((u8 *)arg0 + 0x1E8) = 0;
    *(s32 *)((u8 *)arg0 + 0x1EC) = 0;
    return arg0;
}

extern "C" void InitParam__Q44nw4r3snd6detail10BasicSoundFv(void);
extern "C" void fn_800EEE8C(void*, const void*);
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void);
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, unsigned int);
extern "C" void fn_80128668(void*);
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

#pragma push
#pragma use_lmw_stmw off
extern "C" void Setup__Q46nw4hbm3snd6detail8SeqSoundFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback(void *arg0, void *arg1, unsigned long arg2, int arg3, void *arg4) {
    struct VtableProxy {
        virtual void slot0() = 0;
        virtual void slot1() = 0;
        virtual void slot2() = 0;
        virtual void slot3() = 0;
        virtual void slot4() = 0;
        virtual void slot5() = 0;
        virtual void slot6() = 0;
        virtual void slot7() = 0;
        virtual void slot8() = 0;
        virtual void slot9() = 0;
        virtual void slot10() = 0;
        virtual void slot11() = 0;
        virtual void slot12() = 0;
        virtual void slot13() = 0;
        virtual void slot14() = 0;
        virtual void slot15() = 0;
        virtual void slot16() = 0;
        virtual void slot17() = 0;
        virtual void slot18() = 0;
        virtual void slot19() = 0;
        virtual void method() = 0;
    };
    struct PanicMsgs {
        char file;
        char pad[0x13];
        char msg57[0x2C];
        char msg58[4];
    };
    PanicMsgs *panicBase = (PanicMsgs *)lbl_80324060;
    if (arg4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(&panicBase->file, 0x57, panicBase->msg57);
    if (*(s32 *)((u8 *)arg0 + 0x10) == 0) Panic__Q26nw4hbm2dbFPCciPCce(&panicBase->file, 0x58, panicBase->msg58);
    ((VtableProxy *)arg0)->method();
    Setup__Q46nw4hbm3snd6detail9SeqPlayerFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback((u8 *)arg0 + 0xD8, (unsigned long)arg1, (int)arg2, arg3, arg4);
}
#pragma pop
extern "C" void SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl(void*, const void*, long);
#pragma small_data off
extern "C" u8 lbl_803240D4[];
extern "C" void SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl(void*, const void*, s32);
extern "C" void Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCvl(void* arg0, const void* arg1, s32 arg2) {
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324060, 0x70, (const char*)lbl_803240D4);
    SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl((u8*)arg0 + 0xD8, arg1, arg2);
}

#pragma push
#pragma small_data off
extern "C" u8 lbl_80324074[];
#pragma pop
extern "C" void NotifyLoadAsyncEndSeqData__Q46nw4hbm3snd6detail8SeqSoundFbPCvlPv(int, const void *, unsigned long, void *);
#pragma push
#pragma small_data off
#pragma pop
#pragma push
#pragma scheduling on
extern "C" void Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCQ56nw4hbm3snd6detail8SeqSound15SeqLoadCallbackUl(void *arg0, const void *arg1, unsigned long arg2) {
    struct SeqLoadCallback {
        virtual void v0();
        virtual void Invoke(void (*)(int, const void *, unsigned long, void *), void *, unsigned long) const;
    };
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324060, 0x80, (const char *)lbl_80324074);
    if (arg1 != 0) {
        ((const SeqLoadCallback *)arg1)->Invoke(NotifyLoadAsyncEndSeqData__Q46nw4hbm3snd6detail8SeqSoundFbPCvlPv, arg0, arg2);
    }
    *(void **)((u8 *)arg0 + 0x1EC) = (void *)arg1;
    *(unsigned long *)((u8 *)arg0 + 0x1F0) = arg2;
    *(volatile u8 *)((u8 *)arg0 + 0x1E8) = 1;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void NotifyLoadAsyncEndSeqData__Q46nw4hbm3snd6detail8SeqSoundFbPCvlPv(int arg0, const void *arg1, unsigned long arg2, void *arg3) {
    struct Vt {
        virtual void s0();
        virtual void s1();
        virtual void s2();
        virtual void s3();
        virtual void s4(int);
    };
    const char *f = (const char *)lbl_80324060;
    if (arg3 == 0) Panic__Q26nw4hbm2dbFPCciPCce(f + 0, 0x9A, f + 0xA0);
    *(u8 *)((u8 *)arg3 + 0x1E8) = 0;
    if (arg0 == 0) {
        ((Vt *)arg3)->s4(0);
        return;
    }
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(f + 0, 0x70, f + 0x74);
    SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl((u8 *)arg3 + 0xD8, arg1, (s32)arg2);
}
#pragma pop
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
void nw4hbm::snd::detail::SeqSound::Shutdown() {
    struct SoundList { void *head; void *tail; };
    struct SeqPlayer { int unk0; struct SoundList activeList; };
    struct LinkNode { char pad[0]; };
    struct SeqSoundVTable {
        virtual void m0();
        virtual void DetachFromPlayer(int playerIndex);
    };
    struct SeqSoundObj { void *vtable; char pad[0xB8 - 4]; struct LinkNode link; };
    struct SeqLoadCallback {
        virtual void unused0();
        virtual void unused1();
        virtual void Invoke(int);
    };

    struct SeqSoundObj *sound = (struct SeqSoundObj *)this;
    int interrupts;
    struct SeqPlayer *player;

    if (*(u8 *)((u8 *)this + 0x1E8) != 0) {
        void *cb = *(void **)((u8 *)this + 0x1EC);
        if (cb != 0) {
            ((struct SeqLoadCallback *)cb)->Invoke(*(int *)((u8 *)this + 0x1F0));
        }
    }
    Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(this);
    player = *(struct SeqPlayer **)((u8 *)this + 0x1E4);
    if (this == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324378, 0x86, lbl_80324350);
    interrupts = OSDisableInterrupts();
    if (player->activeList.head == 0) {
        OSRestoreInterrupts(interrupts);
        return;
    }
    if (this == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(&player->activeList, &sound->link);
    ((struct SeqSoundVTable *)this)->DetachFromPlayer(-1);
    fn_800EC848(player, this);
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

#pragma push
#pragma small_data off
extern "C" u8 lbl_80324154[];
#pragma pop
extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi(void *, int);
extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail8SeqSoundFi(void *arg0, int arg1) {
    int valid = 0;
    if (arg1 >= 0 && arg1 <= 0x7F) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324060, 0xE9, (const char *)lbl_80324154, arg1, 0, 0x7F);
    SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi((u8 *)arg0 + 0xD8, arg1);
}

extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void *, int);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" const char lbl_80324314[];
extern "C" const char lbl_803242F0[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail8SeqSoundFi(void *arg0, int arg1) {
    int priority;
    void *list;
    void *soundNode;
    void *node;
    void *sentinel;

    SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(arg0, arg1);
    priority = *(u8 *)((u8 *)arg0 + 0x74) + *(int *)((u8 *)arg0 + 0x40);
    if (priority > 0x7F)
        priority = 0x7F;
    else
        priority &= ~(priority >> 31);
    list = *(void **)((u8 *)arg0 + 0x1E4);
    if (arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
    soundNode = (u8 *)arg0 + 0xB8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)list + 4, soundNode);
    node = *(void **)((u8 *)list + 8);
    sentinel = (u8 *)list + 8;
    while (node != sentinel) {
        int nodePriority;
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324314, 0x23D, lbl_803242F0);
        nodePriority = *(u8 *)((u8 *)node - 0x44) + *(int *)((u8 *)node - 0x78);
        if (nodePriority > 0x7F)
            nodePriority = 0x7F;
        else
            nodePriority &= ~(nodePriority >> 31);
        if (priority < nodePriority) break;
        node = *(void **)node;
    }
    if (arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
    {
        void *iterator = node;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8 *)list + 4, &iterator, soundNode);
    }
}
#pragma pop
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

