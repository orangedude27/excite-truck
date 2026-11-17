// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

namespace nw4hbm { namespace snd { namespace detail {
struct WsdTrack { struct WsdCallback; };
class WaveSound {
public:
    virtual void unk_00() = 0;
    virtual void unk_04() = 0;
    virtual void unk_08() = 0;
    virtual void unk_0c() = 0;
    virtual void unk_10() = 0;
    virtual void unk_14() = 0;
    virtual void unk_18() = 0;
    virtual void unk_1c() = 0;
    virtual void unk_20() = 0;
    virtual void unk_24() = 0;
    virtual void unk_28() = 0;
    virtual void unk_2c() = 0;
    virtual void unk_30() = 0;
    virtual void unk_34() = 0;
    virtual void unk_38() = 0;
    virtual void unk_3c() = 0;
    virtual void unk_40() = 0;
    virtual void unk_44() = 0;
    virtual void unk_48() = 0;
    virtual void unk_4c() = 0;
    virtual void unk_0x58() = 0;
    void Prepare(const void *, long, int, const WsdTrack::WsdCallback *, unsigned long);
};
}}}

typedef unsigned int u32;
extern "C" u32 lbl_8055DE88;
extern "C" void fn_800FFE94(int);
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *fn_80128668(void *);
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void *);
extern "C" void __ct__Q46nw4hbm3snd6detail9WsdPlayerFv(void *, void *);
extern "C" char lbl_803275EC[];
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FF9B8(void *self, int shouldDelete) {
    /* Scalar deleting destructor: destroy the base link-list impl, then free this object when requested. */
    if (self != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

/* Construct a WaveSound: initialize its BasicSound base, set vtable lbl_803275EC,
 * construct the embedded WsdPlayer at +0xD8, store the owner/player pointer at +0x1B0,
 * and clear the field at +0x1AC. */
extern "C" void *fn_800FFA10(void *sound, int owner) {
    __ct__Q44nw4r3snd6detail10BasicSoundFv(sound);
    *(void **)sound = lbl_803275EC;
    __ct__Q46nw4hbm3snd6detail9WsdPlayerFv((char *)sound + 0xD8, lbl_803275EC);
    *(int *)((char *)sound + 0x1B0) = owner;
    *(int *)((char *)sound + 0x1AC) = 0;
    return sound;
}

extern "C" int fn_800FFA6C(int ptr, int count) {
    extern void fn_80128668(void);
    /* Free ptr via the mode-3 pool allocator when it is non-null and count is positive; return ptr unchanged. */
    if (ptr != 0 && count > 0) fn_80128668();
    return ptr;
}

extern "C" const char lbl_80327500[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Prepare__Q46nw4hbm3snd6detail9WsdPlayerFPCviiPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl(void *, const void *, long, int, const nw4hbm::snd::detail::WsdTrack::WsdCallback *, unsigned long);
#pragma use_lmw_stmw off
void nw4hbm::snd::detail::WaveSound::Prepare(const void *arg1, long arg2, int arg3, const nw4hbm::snd::detail::WsdTrack::WsdCallback *arg4, unsigned long arg5) {
    register const char *base = lbl_80327500;
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327500, 0x43, base + 0x18);
    if (arg4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327500, 0x44, base + 0x48);
    if (*(int *)((char *)this + 0x10) == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327500, 0x45, base + 0x74);
    this->unk_0x58();
    Prepare__Q46nw4hbm3snd6detail9WsdPlayerFPCviiPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl((char *)this + 0xD8, arg1, arg2, arg3, arg4, arg5);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void Shutdown__Q46nw4hbm3snd6detail9WaveSoundFv_800FFB80(void *self) {
    extern void Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(void*);
    extern int OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(int);
    extern void fn_800EC848(void*, void*);
    extern const char lbl_803276D8[];
    extern const char lbl_803276B0[];
    extern const char lbl_803257D4[];
    extern const char lbl_803257B0[];
    extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);

    struct SoundList { void *head; void *tail; };
    struct WaveSoundPlayer { int unk0; struct SoundList activeList; };
    struct LinkNode { char pad[0]; };
    struct WaveSoundVTable {
        virtual void m0();
        virtual void DetachFromPlayer(int playerIndex);
    };
    struct WaveSoundObj { void *vtable; char pad[0xB8 - 4]; struct LinkNode link; };

    struct WaveSoundObj *sound = (struct WaveSoundObj *)self;
    int interrupts;
    struct WaveSoundPlayer *player;

    /* Shut down this wave sound and remove it from its owning player's active sound list. */
    Shutdown__Q46nw4hbm3snd6detail10BasicSoundFv(self);
    player = *(struct WaveSoundPlayer **)((char *)self + 0x1B0);
    if (self == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803276D8, 0x86, lbl_803276B0);
    interrupts = OSDisableInterrupts();
    if (player->activeList.head == 0) {
        OSRestoreInterrupts(interrupts);
        return;
    }
    if (self == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803257D4, 0x233, lbl_803257B0);
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(&player->activeList, &sound->link);
    ((struct WaveSoundVTable *)self)->DetachFromPlayer(-1);
    fn_800EC848(player, self);
    OSRestoreInterrupts(interrupts);
}
#pragma pop

#pragma use_lmw_stmw reset
extern "C" int fn_800FFC5C(int object, int deleteFlag) {
    extern void fn_80128668(void);
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

/* Set the channel priority on this wave sound (0..127) and forward to its sequence player. */
extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail9WaveSoundFi_800FFC9C(int self, int priority) {
    extern const char lbl_80327500[];
    extern const char lbl_803275A8[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern void SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi_80100FA8(int, int);
    int isValid = 0;
    if (priority >= 0 && priority <= 0x7F) isValid = 1;
    if (isValid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327500, 0x85, lbl_803275A8, priority, 0, 0x7F);
    SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi_80100FA8(self + 0xD8, priority);
}

extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void *, int);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" const char lbl_803257D4[];
extern "C" const char lbl_803257B0[];
extern "C" const char lbl_80325804[];
extern "C" const char lbl_803257E0[];
#pragma use_lmw_stmw off
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail9WaveSoundFi_800FFD24(void* arg0, int arg1) {
    struct LinkListImpl {
        void* unused;
        void* head;
    };
    struct PriorityList {
        void* unused;
        LinkListImpl list;
    };
    register void* soundNode;
    register int priority;
    register PriorityList* list;
    register void* end;
    register void* cursor;
    register int value;

    SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(arg0, arg1);
    value = *(unsigned char*)((unsigned char*)arg0 + 0x74) + *(int*)((unsigned char*)arg0 + 0x40);
    if (value > 0x7f) {
        priority = 0x7f;
    } else {
        priority = value & ~(value >> 31);
    }
    list = *(PriorityList**)((unsigned char*)arg0 + 0x1b0);
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803257D4, 0x233, lbl_803257B0);
    }
    soundNode = (unsigned char*)arg0 + 0xb8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(&list->list, soundNode);
    end = &list->list.head;
    cursor = list->list.head;
    while (cursor != end) {
        if (cursor == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325804, 0x23d, lbl_803257E0);
        }
        value = *(unsigned char*)((unsigned char*)cursor - 0x44) + *(int*)((unsigned char*)cursor - 0x78);
        if (value > 0x7f) {
            value = 0x7f;
        } else {
            value &= ~(value >> 31);
        }
        if (priority < value) {
            break;
        }
        cursor = *(void**)cursor;
    }
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803257D4, 0x233, lbl_803257B0);
    }
    void* node = cursor;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(&list->list, &node, soundNode);
}
/* Return non-zero when this WaveSound's +0x1AC field is set (the value passed
 * to fn_800FFE68, cleared by the constructor fn_800FFA10). */
extern "C" int fn_800FFE54(void *sound) {
    return *(int *)((char *)sound + 0x1AC) != 0;
}

/* Detach this wave sound from its SoundHandle: pass the handle stored at
 * +0x1AC to SoundHandle::DetachSound (fn_800FFE94), which clears the handle
 * and the sound's back-reference to it. */
extern "C" void fn_800FFE68(void *sound) {
    fn_800FFE94(*(int *)((char *)sound + 0x1AC));
}

/* Return the address of the embedded WsdPlayer (at +0xD8 of the WaveSound object). */
extern "C" int fn_800FFE70(int sound) {
    return sound + 0xD8;
}

extern "C" int fn_800FFE78(int arg0) { return arg0 + 0xD8; }

extern "C" u32 *fn_800FFE80(void) {
    return &lbl_8055DE88;
}
#pragma use_lmw_stmw off
