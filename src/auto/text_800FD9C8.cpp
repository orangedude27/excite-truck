// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);

extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void* this_, u32 a);
extern "C" void __array_delete(void* arg0, void* arg1, s32 arg2, s32 arg3);
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
extern "C" void __array_delete(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern "C" void fn_80128668(void* arg0);
extern "C" void fn_800FB374(void);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FD9C8(void *self, int shouldDelete) {
    /* Destroys a MemorySoundArchive instance and optionally deletes it. */
    if (self != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

/* Initializes a stream sound instance: constructs its BasicSound base and embedded StrmPlayer, installs the stream-sound vtable, and stores the owning pool with the active flag cleared. */
extern "C" void *fn_800FDA20(void *sound, void *pool) {
    __ct__Q44nw4r3snd6detail10BasicSoundFv(sound);
    *(void **)sound = lbl_80326D00;
    __ct__Q46nw4hbm3snd6detail10StrmPlayerFv((u8 *)sound + 0xD8, lbl_80326D00);
    *(void **)((u8 *)sound + 0x5F8) = pool;
    *(u32 *)((u8 *)sound + 0x5F4) = 0;
    return sound;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 Prepare__Q46nw4hbm3snd6detail9StrmSoundFPQ46nw4hbm3snd6detail14StrmBufferPoolQ56nw4hbm3snd6detail10StrmPlayer15StartOffsetTypeliPQ56nw4hbm3snd6detail10StrmPlayer12StrmCallbackUl(void* self, void* pool, s32 start, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct V { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o(); virtual void p(); virtual void q(); virtual void r(); virtual void s(); virtual void t(); virtual void u(); };
    char* file = lbl_80326C88;
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

    struct SoundList { void *head; void *tail; };
    struct StrmSoundPlayer { int unk0; struct SoundList activeList; };
    struct LinkNode { char pad[1]; };
    struct StrmSoundVTable {
        virtual void m0();
        virtual void DetachFromPlayer(int playerIndex);
    };
    struct StrmSoundObj { void *vtable; char pad[0xB8 - 4]; struct LinkNode link; };

    /* Shut down this streaming sound and remove it from its owning player's active sound list. */
    struct StrmSoundObj *sound = (struct StrmSoundObj *)self;
    int interrupts;
    struct StrmSoundPlayer *player;

    Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(self);
    player = *(struct StrmSoundPlayer **)((char *)self + 0x5F8);
    if (self == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326DF0, 0x86, lbl_80326DC8);
    interrupts = OSDisableInterrupts();
    if (player->activeList.head == 0) {
        OSRestoreInterrupts(interrupts);
        return;
    }
    if (self == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(&player->activeList, &sound->link);
    ((struct StrmSoundVTable *)self)->DetachFromPlayer(-1);
    fn_800EC848(player, self);
    OSRestoreInterrupts(interrupts);
}

#pragma pop
/* Destructor for nw4hbm::snd::detail::StrmSound: destroy embedded player/list members, then optionally free. */
extern "C" void* __dt__Q46nw4hbm3snd6detail9StrmSoundFv(void* self, s32 deleteFlag) {
    void* linkList1;
    void* linkList2;

    if (self != NULL) {
        if ((u8*)self + 0xD8 != NULL) {
            __array_delete((u8*)self + 0x184, &fn_800FB374, 0x1C, 0x20);
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
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail9StrmSoundFi_800FDCB8(void* sound, int requestedPriority) {
    /* StrmSound::SetPlayerPriority: forward the request to BasicSound, then remove
     * this sound from the player's priority-sorted list and reinsert it at the slot
     * matching its own priority clamped to 0..0x7F. */
    #pragma opt_common_subs off
    void* node;
    void* sentinel;
    void* priorityList;
    int soundPriority;
    void* listNode;

    SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(sound, requestedPriority);
    int rawPriority = *(unsigned char*)((unsigned char*)sound + 0x74) + *(int*)((unsigned char*)sound + 0x40);
    if (rawPriority > 0x7F) {
        soundPriority = 0x7F;
    } else {
        soundPriority = rawPriority < 0 ? 0 : rawPriority;
    }
    priorityList = *(void**)((unsigned char*)sound + 0x5f8);
    if (sound == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    listNode = (unsigned char*)sound + 0xb8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((unsigned char*)priorityList + 4, listNode);
    struct { u32 v; } nodeHolder;
    struct { u32 v; } sentinelHolder;
    nodeHolder.v = *(u32 *)((char *)priorityList + 8);
    sentinelHolder.v = (u32)((char *)priorityList + 8);
    u32 &cursor = nodeHolder.v;
    u32 &listEnd = sentinelHolder.v;
    while (cursor != listEnd) {
        int nodePriority;
        if (cursor == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258C4, 0x23d, lbl_803258A0);
        int rawNodePriority = *(unsigned char*)(cursor - 0x44) + *(int*)(cursor - 0x78);
        if (rawNodePriority > 0x7F) {
            nodePriority = 0x7F;
        } else {
            nodePriority = rawNodePriority < 0 ? 0 : rawNodePriority;
        }
        if (soundPriority < nodePriority) break;
        cursor = *(u32 *)cursor;
    }
    if (sound == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    void* insertPos = (void*)cursor;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((unsigned char*)priorityList + 4, &insertPos, listNode);
}
#pragma pop
extern "C" s32 fn_800FDDE8(void* sound) {
    /* Return nonzero when the stream sound's state word at offset 0x5F4 is set. */
    return *(s32*)((u8*)sound + 0x5F4) != 0;
}

/* Detach this stream sound from its SoundHandle: pass the handle stored at
 * +0x5F4 to SoundHandle::DetachSound (fn_800FDE28), which clears the handle
 * and the sound's back-reference to it. */
extern "C" void fn_800FDDFC(void* sound) {
    fn_800FDE28(*(void**)((u8*)sound + 0x5F4));
}

/* Return the address of the embedded StrmPlayer (at +0xD8 of the StrmSound object). */
extern "C" s32 fn_800FDE04(s8* sound) {
    return (s32)(sound + 0xD8);
}

/* Return the address of the embedded StrmPlayer (at +0xD8 of the StrmSound object). */
extern "C" s32 fn_800FDE0C(s8* sound) {
    return (s32)(sound + 0xD8);
}

extern "C" u32* fn_800FDE14(void) {
    /* Return the address of the sound-library pointer global initialized to the shared nw4r sound dummy value. */
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

