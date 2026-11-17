#define Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListImpl8Iterator Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode
extern "C" const char lbl_80325834[],lbl_80325810[],lbl_80325804[],lbl_803257E0[],lbl_80325864[],lbl_80325840[],lbl_803257D4[],lbl_803257B0[],lbl_80325F10[],lbl_80325F38[],lbl_80325F50[],lbl_80325F94[];
extern "C" const char lbl_80324868[];
extern "C" void* __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(void*, void*);
extern "C" void* GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(void*);
extern "C" void *fn_800E80B8(void *);
extern "C" int fn_800E80F0(int, int);
extern "C" void *NoteOn__Q46nw4hbm3snd6detail4BankCFRCQ46nw4hbm3snd6detail10NoteOnInfo(void *, const void *);
extern "C" const char lbl_80325B88[];
extern "C" const char lbl_80325110[];
extern "C" int lbl_805598D8;
struct __StrmLoadCommandRef;
struct __StrmSoundArchiveRef;
struct __StrmMutexRef;
extern "C" void *__ct__Q46nw4hbm3snd18SoundArchivePlayer16StrmDataLoadTaskFPvUlliUllbRQ56nw4hbm3snd6detail10StrmPlayer11LoadCommandRCQ36nw4hbm3snd12SoundArchiveUlUlR7OSMutex(void *self, void *arg1, unsigned long arg2, long arg3, int arg4, unsigned long arg5, long arg6, bool arg7, __StrmLoadCommandRef &arg8, const __StrmSoundArchiveRef &arg9, unsigned long arg10, unsigned long arg11, __StrmMutexRef &arg12);
extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void *, unsigned char);
extern "C" void fn_800E519C(void *);
extern "C" const char lbl_80326C28[];
extern "C" const char lbl_803267AC[];
extern "C" const char lbl_80326C4C[];
extern "C" unsigned char lbl_8041506C[];
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
extern "C" int CheckPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFiPQ46nw4hbm3snd6detail19ExternalSoundPlayer(void *self, int priority, void *external);
extern "C" void* AllocImpl__Q44nw4r3snd6detail8PoolImplFv(void*);
extern "C" void* fn_800FFA10(void*, void*);
extern "C" void fn_800EC1A4(void*);
extern "C" void fn_800E9B74(void*, void*, s32, void*, s32);
// nw4hbm::snd ids.  A label string the archive does not know, or a sound the archive
// does not hold, is reported as InvalidSoundId; a string-tree leaf that ends a string
// which is not itself a label carries InvalidLabelId.
enum {
    InvalidSoundId = -1,
    InvalidLabelId = 0xFFFEFFFF
};
// One node of nw4hbm::snd::detail::SoundArchiveFile's label string trie.  An inner node
// tests bit `bitIndex' of the string being looked up (bit 0 is the top bit of the first
// byte) and walks to zeroChild or oneChild; flag bit 0 marks a leaf, which holds the
// label id reached and the sound id belonging to it.
struct StringTreeNodeLayout {
    u16 flags;
    u16 bitIndex;
    u32 zeroChild;
    u32 oneChild;
    u32 labelId;
    u32 soundId;
};
enum { StringTreeNodeIsLeaf = 1 };
// The trie itself; a search enters it at nodes[nodeCount], which must be a valid node.
struct StringTreeLayout {
    u32 nodeCount;
    u32 maxNodeCount;
    StringTreeNodeLayout nodes[1];
};
// nw4hbm's string table: an offset per label over the archive's string block, so label
// id n's string is stringBase + labelOffsets[n] (a 0 offset meaning "no string").
struct SoundArchiveLabelTableLayout {
    u32 count;
    u32 labelOffsets[1];
};
// The two fields of nw4hbm::snd::detail::SoundArchiveFileReader a label lookup reads.
struct SoundArchiveFileReaderLayout {
    u8 pad[0x2C];
    const char *stringBase;
    SoundArchiveLabelTableLayout *labelTable;
    StringTreeLayout *stringTree;
};
namespace nw4hbm { namespace snd { namespace detail { struct WaveSoundInfo; struct WaveSoundNoteInfo; struct WaveData; struct SeqPlayer; struct NoteOnInfo; } class SoundArchivePlayer { public: u32 detail_ConvertLabelStringToSoundId(const char *); class SeqNoteOnCallback { public: void *NoteOn(detail::SeqPlayer *, int, const detail::NoteOnInfo &); }; class WsdCallback { public: s32 GetWaveSoundData(detail::WaveSoundInfo *, detail::WaveSoundNoteInfo *, detail::WaveData *, const void *, s32, s32, u32) const; s32 GetWaveSoundData(detail::WaveSoundInfo *, detail::WaveSoundNoteInfo *, detail::WaveData *, const void *, int, int, u32) const; }; }; namespace detail { class StrmPlayer { public: struct StrmHeader; s32 Start(); void Pause(bool); void Setup(const StrmHeader *); }; class SoundThread { public: s32 Shutdown(); }; } } }
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(void *, int);
extern "C" void fn_800EAD00(void *);
extern "C" void StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(s32, s32, const void *, unsigned long);
extern "C" f32 lbl_805610C0;
extern "C" f32 lbl_805610C4;
extern "C" void fn_800E5338(s32, f32);
extern "C" void fn_800E5444(s32, f32);
extern "C" void fn_800E5464(s32, f32);
extern "C" void fn_800E54A8(s32, f32);
extern "C" void fn_800E54EC(s32, f32);
extern "C" void fn_800E550C(s32, f32);
extern "C" void fn_800E5550(s32, f32);
extern "C" void fn_800E5594(s32, s32);
extern "C" void fn_800E55B4(s32);
extern "C" void fn_800E56D0(s32, f32);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E5718(s32, s32, f32);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif(s32, s32);
extern "C" void SetRemoteSend__Q46nw4hbm3snd6detail7AxVoiceFif(s32, s32, f32);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E58CC(s32, s32, f32);
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
extern "C" unsigned long strlen(const char *);
extern "C" char *strncpy(char *, const char *, unsigned long);
extern "C" void fn_80028E2C(char *, const char *, s32);
extern "C" const char lbl_80324828[];
#pragma cplusplus on
struct DummySoundArchiveLookup2 { virtual s32 f0(u32); virtual s32 f1(); };
struct DummyAllocatable_LoadFile { virtual s32 f0(); virtual void *Alloc(s32 size); };
struct DummySoundArchiveLookup { virtual void f0(); virtual s32 f1(u32); virtual s32 f2(); };
struct DummyCheckPlayable { virtual ~DummyCheckPlayable(); virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); };
struct DummyStrmUpdate { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(s32); virtual void f34(); virtual void f35(s32); };
struct DummyStrmLoadStream {
    virtual void f0();
    virtual void f1();
    virtual void f4();
    virtual s32 f5(void *, u32);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual s32 f11();
    virtual void f12();
    virtual void f13(f32);
    virtual void f14();
    virtual void f15(f32);
    virtual void f16();
    virtual void f17(s32, s32);
    virtual void f18();
    virtual void f19();
    virtual s32 f20();
};
struct DummyStrmLoadCallback {
    virtual void *f2();
    virtual void f0();
    virtual void f1();
};
struct DummyStrmLoadTaskCallback {
    virtual void f2(s32);
    virtual void f0();
    virtual void f1();
};
struct DummySeqPlayerIface { u8 pad[0x24]; f32 volume; u8 pad2[0x90 - 0x2C]; u8 b90; virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual f32 g15(); virtual f32 g16(); virtual f32 g17(); virtual f32 g18(); virtual f32 g19(); virtual f32 g20(); virtual f32 g21(); virtual void g22(); virtual void g23(); virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual s32 g29(); virtual f32 g30(); virtual f32 g31(); virtual f32 g32(s32); virtual f32 g33(s32); virtual f32 g34(s32); virtual f32 g35(s32); };
struct DummySeqPlayerV { virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual f32 g15(); virtual f32 g16(); virtual f32 g17(); virtual f32 g18(); virtual f32 g19(); virtual f32 g20(); virtual f32 g21(); virtual void g22(); virtual void g23(); virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual s32 g29(); virtual f32 g30(); virtual f32 g31(); virtual f32 g32(s32); virtual f32 g33(s32); virtual f32 g34(s32); virtual f32 g35(s32); };
static inline DummySeqPlayerV *SeqTrackPlayer(void *t) { return *(DummySeqPlayerV **)((s8 *)t + 0xB4); }
struct DummyWorkerLink { void *next; void *prev; };
struct DummyWorkerCallbackC : DummyWorkerLink { virtual void f0(); virtual void Call(); };
struct DummyWorkerCallback10 : DummyWorkerLink { virtual void f0(); virtual void f1(); virtual void Call(); };
#pragma cplusplus reset
#pragma push
#pragma always_inline on
#pragma dont_inline off
static inline bool StrmLoadTypeMatches(void **type, const void *wanted) {
    while (type != 0) {
        if (type == wanted) return true;
        type = (void **)*type;
    }
    return false;
}
static inline void *StrmLoadDynamicCast(void *object, const void *wanted) {
    register const void *marker = wanted;
    if (StrmLoadTypeMatches((void **)((DummyStrmLoadCallback *)object)->f2(), marker)) return object;
    return 0;
}
#pragma pop
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))



extern "C" s32 fn_80128668(void);
extern "C" const char lbl_80324E88[];
extern "C" const char lbl_80325520[];
extern "C" u8 lbl_80412AA0[];
extern "C" u8 lbl_80412CA0[];
extern "C" u8 lbl_8055DE58;
extern "C" void OSInitMutex(void*);
extern "C" void NWC24Data_Init(void*);
extern "C" s32 fn_800FAB98(void*, void*);
extern "C" s32 fn_800FACC0(void*, void*, s32);
extern "C" s32 fn_800FAF10(void*, void*, unsigned long, s32);
struct ExecStream { virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual int v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual int v20(); };
extern "C" const char lbl_803251B0[];
extern "C" const char lbl_80325158[];
extern "C" const char lbl_803250C8[];
extern "C" const char lbl_80324EA4[];
extern "C" const char lbl_80325640[];
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *);
extern "C" void fn_800EBB88(void*);
extern "C" f32 lbl_805610B8;
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, u32);
typedef void (*DisposeCallback)(void*, unsigned long, void*);
extern "C" void* Create__Q46nw4hbm3snd6detail9FrameHeapFPvUl(void*);
extern "C" void* Alloc__Q46nw4hbm3snd6detail9FrameHeapFUlPFPvUlPv_vPv(void*, unsigned long, DisposeCallback, void*);
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
// SoundHeap's frame heap (at +0x1C) and the callback it registers on every allocation.
extern "C" void DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv(void* start,
                                                                    unsigned long size,
                                                                    void* user);
extern "C" void Destroy__Q46nw4hbm3snd6detail9FrameHeapFv(void*);
extern "C" void* __dt__Q46nw4hbm3snd6detail9FrameHeapFv(void*, int);
extern "C" u8 lbl_80325C40[];
// nw4hbm::snd::detail::DisposeCallbackManager: walks the registered callbacks over the
// memory range [start, start + size).  Dispose notifies them as objects, DisposeWave as
// wave data; both are static (no manager pointer -- the singleton is taken inside).
extern "C" void Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(void* start,
                                                                             unsigned long size,
                                                                             void* user);
extern "C" void DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(
    void* start, unsigned long size, void* user);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" s32 fn_800E9B88(void *);
extern "C" s32 fn_800E9B9C(void *);
extern "C" const char lbl_80325C00[];
extern "C" const char lbl_803263A8[];
extern "C" const char lbl_80326384[];
extern "C" const char lbl_80326378[];
extern "C" const char lbl_80326354[];
extern "C" const char lbl_80325C18[];
#define BasicSound_IsAttachedGeneralHandle fn_800E9B88
#define BasicSound_DetachGeneralHandle     fn_800E9B9C
#define SND_SOUNDHANDLE_CPP                lbl_80325C00 /* "snd_SoundHandle.cpp" */
#define SND_HANDLE_PTR_SOUND_MSG           lbl_80325C18 /* "NW4HBM:Pointer must not be NULL (sound)" */
// Prefix of nw4hbm::snd::detail::BasicSound accessed by nw4hbm::snd::SoundHandle.
struct SoundHandleBasicSoundLayout {
    void *vtable;             /* 0x00 */
    void *playerHeap;         /* 0x04 */
    void **generalHandle;     /* 0x08 attached general SoundHandle (mGeneralHandle) */
    void **tempGeneralHandle; /* 0x0C attached temporary SoundHandle (mTempGeneralHandle) */
};
extern "C" const char lbl_80325C64[];
extern "C" const char lbl_80325C8C[];
extern "C" f32 lbl_805610BC;
extern "C" f32 lbl_8056107C;
extern "C" const char lbl_803244D4[];
  extern "C" u8 lbl_80325C50[];
  extern "C" s32 detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(s32);
  extern "C" u8 lbl_80325D48[];
  extern "C" u8 lbl_80325D6C[];
  extern "C" u8 lbl_80323834[];
      extern "C" u8 lbl_80323810[];
    extern "C" u8 lbl_80325D98[];
  extern "C" u8 lbl_803263B8[];
  extern "C" u8 lbl_80326400[];
  extern "C" u8 lbl_8055DE60;
  extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void *, s32 *);
  extern "C" void *GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv(void);
  extern "C" s32 Shutdown__Q46nw4hbm3snd6detail11SoundThreadFv(void);
  extern "C" void *fn_800FE648(void);
  extern "C" s32 Destroy__Q46nw4hbm3snd6detail10TaskThreadFv(void);
  extern "C" void *GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv(void);
  extern "C" void fn_800EEB64(void *);
  extern "C" void *Instance__15EmissionManagerFv(void);
    extern "C" void fn_800E2F84(void *);
    #pragma push
    #pragma small_data off
    extern u8 lbl_80412CC8[];
    extern u8 lbl_80412CB8[];
    extern "C" s32 OSJoinThread(void *, s32);
    extern "C" const char lbl_80326450[];
    extern "C" const char lbl_80326488[];
    #pragma pop
    extern u8 lbl_8055DE68;
    extern "C" void* __dt__10TitleSceneFv(void*, s32);
    extern "C" void __register_global_object(void*, void*, void*, void*);
    extern "C" s32 OSSendMessage(void*, void*, u32);
extern "C" void OSInitMutex(void*);
extern "C" const char lbl_80326768[];
/* The snd_StrmPlayer.cpp string pool: the file string followed by its messages. */
struct StrmPlayerMsgPool {
    char file[0x238];
    char msg238[0x30];
    char msg268[0x30];
    char msg298[0x40];
};
extern "C" const char lbl_803269A0[];
extern "C" const char lbl_8032677C[];
extern "C" const char lbl_80326C1C[];
extern "C" const char lbl_80326BF8[];
extern "C" const char lbl_80326BBC[];
extern "C" const char lbl_80326B98[];
extern "C" const char lbl_80326BEC[];
extern "C" const char lbl_80326BC8[];
extern "C" const char lbl_80326838[];
extern "C" unsigned char lbl_80415080[];
extern "C" void InitParam__Q46nw4hbm3snd6detail10StrmPlayerFi(void *, s32);
extern "C" void NotifyStrmHeaderAsyncEndCallback__Q46nw4hbm3snd6detail10StrmPlayerFbPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeaderPv(bool, const void *, void *);
extern "C" const char lbl_80324B24[];
extern "C" const char lbl_80324B50[];
extern "C" char lbl_80559858;
extern "C" char lbl_80559860;
extern "C" const char lbl_80326348[];
extern "C" const char lbl_80326324[];
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" u64 impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(void *, u32);
extern "C" void *GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(s32, u32, void*);
extern "C" const char lbl_80324CB0[];
extern "C" char lbl_805598A0;
extern "C" void fn_800FA6E8(void);
extern "C" void fn_800FA7E0(void*);
extern "C" void OSInitMessageQueue(void*, void*, s32);
extern "C" void RegisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNodePFv_v(void*, void*, void (*)(void));
extern "C" void UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(void*, void*);
extern "C" void memset(void*, s32, u32);
    extern "C" void ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" void detail_UpdateBufferAllPlayers__Q36nw4hbm3snd10WavePlayerFv(void);
      extern "C" void UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv(void);
extern "C" s32 DVDGetDriveStatus(void);
extern "C" u32 GetCurrentPlayingSample__Q46nw4hbm3snd6detail7AxVoiceCFv(s32);
extern "C" void UpdatePlayingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" void UpdateLoadingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFQ66nw4hbm3snd6detail10StrmPlayer11LoadCommand6Status(void *, s32);

  M2C_UNK GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);

extern "C" s32 GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);
extern "C" s32 ConvertLabelStringToId__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPCQ56nw4hbm3snd6detail16SoundArchiveFile10StringTreePCc(void *, void *, s32);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" const char lbl_803247E0[];
extern "C" const char lbl_803247F8[];
extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32);
extern "C" const char lbl_80324390[];
extern "C" const char lbl_803244FC[];
extern "C" const char lbl_80324534[];
extern "C" const char lbl_803245B8[];
extern "C" const char lbl_80326A28[];
extern "C" const char lbl_80326C7C[];
extern "C" const char lbl_80326C58[];
extern "C" void fn_800FB358(void *);
extern "C" s32 fn_800FB374(s32, s32);
extern "C" void fn_800F0E64(void **arg0) {
    void *p = *arg0;
    /* Clear the sound's back-reference (if it still points here), then the handle. */
    if (p && *(void **)((char *)p + 0x1E0) == arg0)
        *(void **)((char *)p + 0x1E0) = 0;
    if (*arg0)
        *arg0 = 0;
}

/* Set envelope sustain level (valid range 0-16); panics on out-of-range value. */
extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi_800F0E9C(void *self, int sustainLevel) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern const char lbl_80324390[];
    extern const char lbl_803243A4[];
    int isValid = sustainLevel >= 0 && sustainLevel <= 0x10;
    if (!isValid)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x25, lbl_803243A4, sustainLevel, 0, 0x10);
    *((unsigned char *)self + 4) = sustainLevel;
}

extern "C" f32 lbl_80561078;
extern "C" void fn_800EC890(void *, int, int, int, int, f32);
#pragma push
#pragma scheduling on
extern "C" void InitParam__Q46nw4hbm3snd6detail8SeqTrackFv(void *arg0) {
    u8 *p = (u8 *)arg0;
    f32 zero = lbl_8056107C;
    f32 one = lbl_80561078;
    u8 v2 = 2;
    u8 vff = 0xFF;
    u8 v7f = 0x7F;
    u8 v40 = 0x40;
    u8 v3c = 0x3C;
    *(f32 *)(p + 0x08) = one;
    *(f32 *)(p + 0x0C) = one;
    *(f32 *)(p + 0x10) = zero;
    *(f32 *)(p + 0x14) = zero;
    *(f32 *)(p + 0x18) = one;
    *(f32 *)(p + 0x1C) = zero;
    *(f32 *)(p + 0x20) = zero;
    *(f32 *)(p + 0x24) = zero;
    *(f32 *)(p + 0x28) = zero;
    *(f32 *)(p + 0x2C) = zero;
    *(f32 *)(p + 0x30) = zero;
    *(f32 *)(p + 0x40) = zero;
    *(f32 *)(p + 0x34) = zero;
    *(f32 *)(p + 0x44) = zero;
    *(f32 *)(p + 0x38) = zero;
    *(f32 *)(p + 0x48) = zero;
    *(f32 *)(p + 0x3C) = zero;
    *(f32 *)(p + 0x4C) = zero;
    *(u32 *)(p + 0x50) = 0;
    *(u32 *)(p + 0x54) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x64) = 0;
    p[0x88] = v40;
    *(u32 *)(p + 0x58) = 0;
    p[0x5C] = 0;
    p[0x5D] = 0;
    p[0x5E] = 0;
    p[0x5F] = 0;
    p[0x80] = v7f;
    p[0x81] = v7f;
    p[0x84] = 0;
    p[0x85] = 0;
    p[0x86] = 0;
    p[0x82] = 0;
    p[0x8B] = vff;
    p[0x8C] = vff;
    p[0x8D] = vff;
    p[0x8E] = vff;
    p[0x8F] = v7f;
    p[0x90] = 0;
    p[0x91] = 0;
    p[0x92] = 0;
    p[0x93] = v40;
    p[0x83] = v2;
    p[0x89] = v3c;
    p[0x8A] = 0;
    *(f32 *)(p + 0x7C) = zero;
    p[0x87] = 0;
    fn_800EC890(p + 0x68, v2, vff, v7f, v40, one);
    p[0x78] = 0;
    *(u32 *)(p + 0xB8) = 0;
    *(u16 *)(p + 0x94) = 0xFFFF;
    *(u16 *)(p + 0x96) = 0xFFFF;
    *(u16 *)(p + 0x98) = 0xFFFF;
    *(u16 *)(p + 0x9A) = 0xFFFF;
    *(u16 *)(p + 0x9C) = 0xFFFF;
    *(u16 *)(p + 0x9E) = 0xFFFF;
    *(u16 *)(p + 0xA0) = 0xFFFF;
    *(u16 *)(p + 0xA2) = 0xFFFF;
    *(u16 *)(p + 0xA4) = 0xFFFF;
    *(u16 *)(p + 0xA6) = 0xFFFF;
    *(u16 *)(p + 0xA8) = 0xFFFF;
    *(u16 *)(p + 0xAA) = 0xFFFF;
    *(u16 *)(p + 0xAC) = 0xFFFF;
    *(u16 *)(p + 0xAE) = 0xFFFF;
    *(u16 *)(p + 0xB0) = 0xFFFF;
    *(u16 *)(p + 0xB2) = 0xFFFF;
}
#pragma pop
/* Set two adjacent 32-bit fields of the object: field 0x50 = base, field 0x54 = base + span. */
extern "C" void fn_800F1080(void *self, int base, int span) {
    *(int *)((char *)self + 0x50) = base;
    *(int *)((char *)self + 0x54) = base + span;
}

extern "C" void Close__Q46nw4hbm3snd6detail8SeqTrackFv(void *track) {
    /* Release all active channels and clear the track's channel list. */
    ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(track, -1);
    u32 interruptState = OSDisableInterrupts();
    void *channel = *(void **)((u8 *)track + 0xB8);
    while (channel != 0) {
        fn_800EAD00(channel);
        channel = *(void **)((u8 *)channel + 0xE4);
    }
    *(void **)((u8 *)track + 0xB8) = 0;
    OSRestoreInterrupts(interruptState);
}

extern "C" void UpdateChannelLength__Q46nw4hbm3snd6detail8SeqTrackFv(void *arg0) {
    /* Tick the length of each channel attached to this SeqTrack (list at +0xB8,
       next at +0xE4): decrement the note length at +0xD4 and release the channel
       when it reaches 0, and advance the channel timer (fn_800EA880, +1) while
       the flag at +0x3C is clear. */
    extern void Release__Q46nw4hbm3snd6detail7ChannelFv(void *);
    extern void fn_800EA880(void *, int);
    void *channel = *(void **)((char *)arg0 + 0xB8);
    while (channel != 0) {
        int length = *(int *)((char *)channel + 0xD4);
        if (length > 0) {
            length--;
            *(int *)((char *)channel + 0xD4) = length;
            if (length == 0)
                Release__Q46nw4hbm3snd6detail7ChannelFv(channel);
        }
        if (*(unsigned char *)((char *)channel + 0x3C) == 0)
            fn_800EA880(channel, 1);
        channel = *(void **)((char *)channel + 0xE4);
    }
}

/* Advances the sequence track by one tick, parsing commands until time passes or pause/end is reached. */
extern "C" s32 ParseNextTick__Q46nw4hbm3snd6detail8SeqTrackFb(void *arg0, u8 arg1) {
    class Obj { public: virtual void f0(); virtual s32 f1(u8); };
    Obj *obj = (Obj *)arg0;
    u8 *flag = (u8 *)arg0 + 0x5E;
    if (*flag) {
        if (*(void **)((u8 *)arg0 + 0xB8))
            return 0;
        *flag = 0;
    }
    s32 *ticks = (s32 *)((u8 *)arg0 + 0x58);
    if (*ticks > 0 && --*ticks > 0)
        return 0;
    if (*(s32 *)((u8 *)arg0 + 0x54) == 0)
        goto done;
    while (*ticks == 0 && *flag == 0) {
        if (obj->f1(arg1) == 1)
            return -1;
    }
done:
    if (*ticks == 0 && *flag != 0)
        return 0;
    return 0;
}

extern "C" void UpdateChannelParam__Q46nw4hbm3snd6detail8SeqTrackFv(void*);
extern "C" void fn_800E402C(void*);
extern "C" void fn_800E4064(void*);
extern "C" void SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi(void*, int);
extern "C" void Release__Q46nw4hbm3snd6detail7ChannelFv(void*);
extern "C" const char lbl_803243F0[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(void* arg0, int arg1) {
    UpdateChannelParam__Q46nw4hbm3snd6detail8SeqTrackFv(arg0);
    BOOL irq = OSDisableInterrupts();
    fn_800E402C(Instance__15EmissionManagerFv());
    void* channel = *(void**)((u8*)arg0 + 0xB8);
    while (channel != 0) {
        if (*((u8*)channel + 0x3A) != 0) {
            if (arg1 >= 0) {
                int valid = 0;
                if (arg1 >= 0 && arg1 <= 0x7F) {
                    valid = 1;
                }
                if (valid == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x10E,
                                                 lbl_803243F0, arg1, 0, 0x7F);
                }
                SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi(
                    (u8*)channel + 8, (u8)arg1);
            }
            Release__Q46nw4hbm3snd6detail7ChannelFv(channel);
        }
        channel = *(void**)((u8*)channel + 0xE4);
    }
    fn_800E4064(Instance__15EmissionManagerFv());
    OSRestoreInterrupts(irq);
}
#pragma pop
extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFb(void *arg0, u8 arg1) {
    /* Pause or unpause all active AxVoices on the track's channel list, with interrupts disabled. */
    u32 interrupts = OSDisableInterrupts();
    u8 *track = (u8 *)arg0;
    void *channel = *(void **)(track + 0xB8);

    while (channel != 0) {
        u8 *channelBytes = (u8 *)channel;
        if (channelBytes[0x3A] != 0 && arg1 != (channelBytes[0x39] != 0)) {
            channelBytes[0x39] = arg1;
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(channelBytes + 0xE0), arg1);
        }
        channel = *(void **)(channelBytes + 0xE4);
    }

    OSRestoreInterrupts(interrupts);
}

extern "C" const char lbl_80324728[];
extern "C" const char lbl_803246E0[];
extern "C" const char lbl_8032477C[];
extern "C" const char lbl_80324734[];
extern "C" const char lbl_803247D0[];
extern "C" const char lbl_80324788[];
extern "C" void UpdateChannelParam__Q46nw4hbm3snd6detail8SeqTrackFv(void *self) {
    void *ch;
    f32 sa[3];
    f32 sb[4];
    f32 sc[4];
    f32 a = (f32)M2C_FIELD(self, u8 *, 0x80) / 127.0f;
    f32 b = (f32)M2C_FIELD(self, u8 *, 0x81) / 127.0f;
    f32 c = (f32)M2C_FIELD(SeqTrackPlayer(self), u8 *, 0x90) / 127.0f;
    f32 vol = 1.0f;
    vol *= a * a;
    vol *= b * b;
    vol *= c * c;
    vol *= M2C_FIELD(self, f32 *, 8);
    vol *= SeqTrackPlayer(self)->g15();
    f32 pan = (f32)(s8)M2C_FIELD(self, u8 *, 0x82);
    pan = pan * 0.0078125f;
    f32 pan2 = pan * (f32)M2C_FIELD(self, u8 *, 0x83);
    f32 pitch = 1.0f;
    pitch *= SeqTrackPlayer(self)->g16();
    pitch *= M2C_FIELD(self, f32 *, 0xC);
    f32 f25 = 0.0f;
    f32 t = (f32)(s8)M2C_FIELD(self, u8 *, 0x84) / 63.0f;
    f32 tc;
    if (t > 1.0f) tc = 1.0f;
    else if (t < -1.0f) tc = -1.0f;
    else tc = t;
    f25 += tc;
    f25 *= M2C_FIELD(self, f32 *, 0x18);
    f25 *= M2C_FIELD(SeqTrackPlayer(self), f32 *, 0x28);
    f25 += M2C_FIELD(self, f32 *, 0x10);
    f25 += SeqTrackPlayer(self)->g17();
    f32 f24 = 0.0f;
    f32 t2 = (f32)(s8)M2C_FIELD(self, u8 *, 0x86) / 63.0f;
    f32 tc2;
    if (t2 > 2.0f) tc2 = 2.0f;
    else {
        if (t2 < 0.0f) t2 = 0.0f;
        tc2 = t2;
    }
    f24 += tc2;
    f24 += M2C_FIELD(self, f32 *, 0x14);
    f24 += SeqTrackPlayer(self)->g18();
    f32 f23 = 0.0f;
    f23 += SeqTrackPlayer(self)->g19();
    f32 f22 = 0.0f;
    f22 += SeqTrackPlayer(self)->g20();
    f32 f21 = 0.0f;
    f32 rawp = (f32)((s32)M2C_FIELD(self, u8 *, 0x93) - 0x40);
    f21 += 0.015625f * rawp;
    f21 += M2C_FIELD(self, f32 *, 0x1C);
    f21 += SeqTrackPlayer(self)->g21();
    f32 f20 = 0.0f;
    f20 += (f32)M2C_FIELD(self, u8 *, 0x8F) / 127.0f - 1.0f;
    f20 += M2C_FIELD(self, f32 *, 0x20);
    f20 += SeqTrackPlayer(self)->g31();
    int i;
    f32 *pa = sa;
    u8 *q = (u8 *)self;
    for (i = 0; i < 3; ++i) {
        *pa = 0.0f;
        *pa += (f32)M2C_FIELD(self, u8 *, 0x90 + i) / 127.0f;
        *pa += M2C_FIELD(q, f32 *, 0x24);
        *pa += SeqTrackPlayer(self)->g32(i);
        q += 4;
        pa++;
    }
    f32 *pb = sb;
    f32 *pc = sc;
    for (i = 0; i < 4; ++i) {
        *pb = 0.0f;
        *pb += SeqTrackPlayer(self)->g34(i);
        *pc = 0.0f;
        *pc += SeqTrackPlayer(self)->g35(i);
        pb++;
        pc++;
    }
    u32 irq = OSDisableInterrupts();
    for (ch = M2C_FIELD(self, void **, 0xB8); ch != 0; ch = M2C_FIELD(ch, void **, 0xE4)) {
        M2C_FIELD(ch, f32 *, 0x40) = vol;
        M2C_FIELD(ch, f32 *, 0xA4) = pan2;
        M2C_FIELD(ch, f32 *, 0x44) = pitch;
        M2C_FIELD(ch, f32 *, 0x48) = f25;
        M2C_FIELD(ch, f32 *, 0x4C) = f24;
        M2C_FIELD(ch, f32 *, 0x50) = f23;
        M2C_FIELD(ch, f32 *, 0x54) = f22;
        M2C_FIELD(ch, f32 *, 0x58) = f21;
        M2C_FIELD(ch, s32 *, 0x5C) = SeqTrackPlayer(self)->g29();
        M2C_FIELD(ch, f32 *, 0x60) = SeqTrackPlayer(self)->g30();
        M2C_FIELD(ch, f32 *, 0x64) = f20;
        M2C_FIELD(ch, f32 *, 0x68) = sa[0];
        M2C_FIELD(ch, f32 *, 0x6C) = sa[1];
        M2C_FIELD(ch, f32 *, 0x70) = sa[2];
        u8 *cp = (u8 *)ch;
        f32 *qb = sb;
        f32 *qc = sc;
        int j;
        for (j = 0; j < 4; ++j) {
            f32 v = SeqTrackPlayer(self)->g33(j);
            int ok = 0;
            if (j >= 0 && j < 4) ok = 1;
            if (!ok) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324728, 0xA5, lbl_803246E0, j, 0, 4);
            M2C_FIELD(cp, f32 *, 0x74) = v;
            v = *qb;
            ok = 0;
            if (j >= 0 && j < 4) ok = 1;
            if (!ok) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8032477C, 0xAA, lbl_80324734, j, 0, 4);
            M2C_FIELD(cp, f32 *, 0x84) = v;
            v = *qc;
            ok = 0;
            if (j >= 0 && j < 4) ok = 1;
            if (!ok) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803247D0, 0xAF, lbl_80324788, j, 0, 4);
            M2C_FIELD(cp, f32 *, 0x94) = v;
            cp += 4;
            qb++;
            qc++;
        }
        M2C_FIELD(ch, f32 *, 0x20) = M2C_FIELD(self, f32 *, 0x68);
        M2C_FIELD(ch, f32 *, 0x24) = M2C_FIELD(self, f32 *, 0x6C);
        M2C_FIELD(ch, s32 *, 0x28) = M2C_FIELD(self, s32 *, 0x70);
        M2C_FIELD(ch, u8 *, 0x2C) = M2C_FIELD(self, u8 *, 0x74);
        M2C_FIELD(ch, u8 *, 0x2D) = M2C_FIELD(self, u8 *, 0x75);
        M2C_FIELD(ch, u8 *, 0x2E) = M2C_FIELD(self, u8 *, 0x76);
        M2C_FIELD(ch, u8 *, 0x2F) = M2C_FIELD(self, u8 *, 0x77);
        M2C_FIELD(ch, u8 *, 0x38) = M2C_FIELD(self, u8 *, 0x78);
    }
    OSRestoreInterrupts(irq);
}

extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void *, u8);
extern "C" void fn_800EAD00(void *);
/* Free all channels attached to this sequence track. */
extern "C" void FreeAllChannel__Q46nw4hbm3snd6detail8SeqTrackFv(void *track) {
    u32 interruptState = OSDisableInterrupts();
    void *channel = *(void **)((char *)track + 0xB8);
    while (channel) {
        fn_800EAD00(channel);
        channel = *(void **)((char *)channel + 0xE4);
    }
    *(void **)((char *)track + 0xB8) = 0;
    OSRestoreInterrupts(interruptState);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void ChannelCallbackFunc__Q46nw4hbm3snd6detail8SeqTrackFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl(void *channel, s32 status, void *track, u32 arg3) {
    struct Callback {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
        virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
        virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
        virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(void *);
    };
    register u32 token;
    register const char *file = lbl_80324390;
    if (channel == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x209, file + 0xA0);
    if (track == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x20A, file + 0xD0);
    switch (status) {
    case 0:
    case 2:
        fn_800EAD00(channel);
        break;
    default:
        break;
    }
    {
        void *cb = *(void **)((u8 *)track + 0xB4);
        if (cb != 0)
            ((Callback *)cb)->f43(channel);
    }
    token = OSDisableInterrupts();
    void *node = *(void **)((u8 *)track + 0xB8);
    if (node == channel) {
        *(void **)((u8 *)track + 0xB8) = *(void **)((u8 *)channel + 0xE4);
        OSRestoreInterrupts(token);
        return;
    }
    if (node == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x220, file + 0xF8);
    u32 next = *(u32 *)((u8 *)node + 0xE4);
    while (next != 0) {
        if ((void *)next == channel) {
            *(u32 *)((u8 *)node + 0xE4) = *(u32 *)((u8 *)channel + 0xE4);
            OSRestoreInterrupts(token);
            return;
        }
        node = (void *)next;
        next = *(u32 *)((u8 *)node + 0xE4);
    }
    Panic__Q26nw4hbm2dbFPCciPCce(file, 0x229, file + 0x124);
    OSRestoreInterrupts(token);
}
#pragma pop

extern "C" void Stop__Q46nw4hbm3snd6detail7ChannelFv(void *);
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(void *, int);
extern "C" void SetMute__Q46nw4hbm3snd6detail8SeqTrackFQ36nw4hbm3snd7SeqMute(void *track, int muteMode) {
    u32 interruptState = OSDisableInterrupts();
    switch (muteMode) {
    case 0:
        *(u8 *)((u8 *)track + 0x5C) = 0;
        break;
    case 3: {
        u32 channelInterruptState = OSDisableInterrupts();
        void *channel = *(void **)((u8 *)track + 0xB8);
        while (channel) {
            fn_800EAD00(channel);
            Stop__Q46nw4hbm3snd6detail7ChannelFv(channel);
            channel = *(void **)((u8 *)channel + 0xE4);
        }
        *(void **)((u8 *)track + 0xB8) = 0;
        OSRestoreInterrupts(channelInterruptState);
        *(u8 *)((u8 *)track + 0x5C) = 1;
        break;
    }
    case 2: {
        ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(track, -1);
        void *channel;
        u32 channelInterruptState;
        channelInterruptState = OSDisableInterrupts();
        channel = *(void **)((u8 *)track + 0xB8);
        while (channel) {
            fn_800EAD00(channel);
            channel = *(void **)((u8 *)channel + 0xE4);
        }
        *(void **)((u8 *)track + 0xB8) = 0;
        OSRestoreInterrupts(channelInterruptState);
        *(u8 *)((u8 *)track + 0x5C) = 1;
        break;
    }
    case 1:
        *(u8 *)((u8 *)track + 0x5C) = 1;
        break;
    }
    OSRestoreInterrupts(interruptState);
}

extern "C" const char lbl_80324690[];
extern "C" const char lbl_803246D4[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void SetSilence__Q46nw4hbm3snd6detail8SeqTrackFbi(void *track, bool silence, int fadeTime) {
    /* Sets or clears the track's silence flag and applies a fade to all attached channels. */
    *(volatile u8 *)((u8 *)track + 0x5d) = silence;
    register int fadeFrames;
    register void *channel;
    register u32 savedIrqState;
    savedIrqState = OSDisableInterrupts();
    fadeFrames = (fadeTime + 2) / 3;
    channel = *(void **)((u8 *)track + 0xb8);
    while (channel != 0) {
        int inRange = 0;
        if (fadeFrames >= 0) {
            if (fadeFrames <= 0xffff)
                inRange = 1;
        }
        if (inRange == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803246D4, 0x7c, lbl_80324690, fadeFrames, 0, 0xffff);

        register u16 elapsed;
        register u16 total;
        total = *(u16 *)((u8 *)channel + 0xc6);
        elapsed = *(u16 *)((u8 *)channel + 0xc8);
        u8 startLevel;
        if (elapsed >= total) {
            startLevel = *(u8 *)((u8 *)channel + 0xc5);
        } else {
            u8 currentLevel = *(u8 *)((u8 *)channel + 0xc4);
            u8 targetLevel = *(u8 *)((u8 *)channel + 0xc5);
            startLevel = (u8)(currentLevel + (elapsed * (targetLevel - currentLevel)) / total);
        }
        *(u8 *)((u8 *)channel + 0xc4) = startLevel;
        ((u8 *)channel)[0xc5] = silence ? 0 : 0xff;
        *(u16 *)((u8 *)channel + 0xc6) = fadeFrames;
        *(u16 *)((u8 *)channel + 0xc8) = 0;
        channel = *(void **)((u8 *)channel + 0xe4);
    }
    OSRestoreInterrupts(savedIrqState);
}
#pragma pop

extern "C" void fn_800F1E50(void *object, f32 value) {
    /* Set the float field at offset 0x8 of object with interrupts disabled. */
    u32 level = OSDisableInterrupts();
    *(f32 *)((char *)object + 8) = value;
    OSRestoreInterrupts(level);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800F1E90(void *self, float volume) {
    /* Validate and store the sequence player volume at offset 0xC under interrupt disable. */
    if (!(volume >= 0.0f)) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324390, 0x25b, (const char *)lbl_803244D4);
    unsigned int interruptLevel = OSDisableInterrupts();
    *(float *)((unsigned char *)self + 0xC) = volume;
    OSRestoreInterrupts(interruptLevel);
}

extern "C" void fn_800F1F04(void* player, f32 value) {
    /* Set the SeqPlayer float field at offset 0x10 of player with interrupts disabled. */
    u32 level = OSDisableInterrupts();
    *(f32*)((char*)player + 0x10) = value;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800F1F44(void* object, f32 value) {
    /* Set the float field at offset 0x14 of object with interrupts disabled. */
    OSDisableInterrupts();
    *(f32*)((char*)object + 0x14) = value;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" f32 lbl_8056107C;
extern "C" void fn_800F1F84(void* object, f32 value) {
    /* Set the float field at offset 0x18 of object with interrupts disabled. */
    OSDisableInterrupts();
    *(f32*)((char*)object + 0x18) = value;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F1FC4(void *object, f32 value) {
    /* Set the float field at offset 0x1C of object with interrupts disabled. */
    OSDisableInterrupts();
    *(f32 *)((char *)object + 0x1C) = value;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F2004(void* object, f32 value) {
    /* Set the float field at offset 0x68 of object with interrupts disabled. */
    OSDisableInterrupts();
    *(f32*)((u8*)object + 0x68) = value;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F2044(void *object, f32 value) {
    /* Set the sound-track float parameter at offset 0x6C with interrupts disabled. */
    OSDisableInterrupts();
    *(f32*)((u8*)object + 0x6C) = value;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F2084(void* track, f32 value) {
    /* nw4hbm::snd::detail::SeqTrack parameter setter: stores the track's base
     * value (+0x20) of the parameter UpdateChannelParam__Q46nw4hbm3snd6detail8SeqTrackFv
     * sums with the track's byte at +0x8F scaled to [-1,1) and the owning
     * player's own value, and hands the result to every channel of the track at
     * Channel+0x64.  Interrupts stay off over the store so the sound update
     * cannot read the parameter half-written. */
    u32 irq = OSDisableInterrupts();
    *(f32*)((u8*)track + 0x20) = value;
    OSRestoreInterrupts(irq);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F20C4(void *self, int bus, float value) {
    /* Set this sequence player's FX send level for the given aux bus (0-2) at +0x24, with range check, under interrupt-disabled section. */
    int isValidBus = bus >= 0 && bus < 3;
    if (!isValidBus) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x295, lbl_803244FC, bus, 0, 3);
    int interruptLevel = OSDisableInterrupts();
    *(float *)((char *)self + bus * 4 + 0x24) = value;
    OSRestoreInterrupts(interruptLevel);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F2160(void *self, int bus, float value) {
    /* Set this sequence player's FX send level for an aux bus, with interrupt-safe update. */
    int valid = bus >= 0 && bus < 4;
    if (!valid) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x2A3, lbl_80324534, bus, 0, 4);
    int level = OSDisableInterrupts();
    *(float *)((char *)self + bus * 4 + 0x30) = value;
    OSRestoreInterrupts(level);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F21FC(void *self, int bus, float value) {
    /* Set this sequence player's FX send level for the given remote index (0-3) at +0x40, with range check, under interrupt-disabled section. */
    int isValidBus = bus >= 0 && bus < 4;
    if (!isValidBus) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x2B0, lbl_80324534, bus, 0, 4);
    int interruptLevel = OSDisableInterrupts();
    *(float *)((char *)self + bus * 4 + 0x40) = value;
    OSRestoreInterrupts(interruptLevel);
}

/* Return pointer to SeqTrack variable (0-15) or null for 16; panics if index is out of [0,16]. */
extern "C" s16* GetVariablePtr__Q46nw4hbm3snd6detail8SeqTrackFi(void *track, s32 varNo) {
    s32 isValid = 0;
    if (varNo >= 0 && varNo <= 0x10) isValid = 1;
    if (!isValid) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324390, 0x2EB, (const char *)lbl_803245B8, varNo, 0, 0x10);
    if (varNo < 0x10) return (s16*)((u8 *)track + 0x94 + varNo * 2);
    return (s16*)0;
}

extern "C" void *fn_800F0728(void *, s32, void *);
extern "C" void fn_800EA8A0(void *, s32, s32, f32);
extern "C" void SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern "C" f32 lbl_80561080;
extern "C" f64 lbl_805610A0;
extern "C" extern u32 OSDisableInterrupts(void);
struct Fn800F2330Args { s32 values[9]; };
extern "C" s32 lbl_802F4DB8[];
extern "C" void *fn_800F2330(void *a, s32 key, s32 vel, s32 arg3, s32 reuse) {
 const char *file=lbl_80324390;
 u8 *p=(u8*)a; void *c;
 s32 valid=0;
 if(key>=0 && key<=127) valid=1;
 if(!valid) Panic__Q26nw4hbm2dbFPCciPCce((const char*)((u32)file+0),0x30a,file+0x268,key,0,127);
 valid=0; if(vel>=0 && vel<=127) valid=1;
 if(!valid) Panic__Q26nw4hbm2dbFPCciPCce((const char*)((u32)file+0),0x30b,file+0x2a0,vel,0,127);
 void *owner = *(void**)(p+0xb4);
 c=0;
 if(reuse && (c=*(void**)(p+0xb8))) {
  f32 x=((f32)vel)/lbl_80561080; *(u32*)((u8*)c+0xcc)=(u8)key;
  *(f32*)((u8*)c+0xb4)=x*x;
 }
 if(!c) {
  Fn800F2330Args block = *(Fn800F2330Args*)lbl_802F4DB8;
  block.values[0]=*(s32*)(p+0x64); block.values[1]=key; block.values[2]=vel; s32 duration=-1; if(!reuse) duration=arg3; block.values[3]=duration;
  block.values[4]=(s8)p[0x85]; block.values[5]=*(u8*)((u8*)owner+0x91)+p[0x88];
  block.values[6]=*(s32*)((u8*)owner+0x8c); block.values[8]=(s32)p;
  c=fn_800F0728(*(void**)(p+0xb4),*(s32*)(p+0x60),block.values); if(!c)return 0;
  u32 t=OSDisableInterrupts(); *(void**)((u8*)c+0xe4)=*(void**)(p+0xb8); *(void**)(p+0xb8)=c; OSRestoreInterrupts(t);
 }
 if(p[0x8b]!=255) SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8b]);
 if(p[0x8c]!=255) SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8c]);
 if(p[0x8d]!=255) SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8d]);
 if(p[0x8e]!=255) SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8e]);
 f32 pitch=*(f32*)(p+0x7c); if(p[0x5f]) pitch+=(f32)((s32)p[0x89]-key);
 if(!p[0x8a]) { if(!arg3) Warning__Q26nw4hbm2dbFPCciPCce(file+0,0x358,file+0x2e4); fn_800EA8A0(c,arg3,0,pitch); }
 else { s32 n=p[0x8a]*p[0x8a]; f32 scale=pitch>=lbl_8056107C?pitch:-pitch; fn_800EA8A0(c,((s32)((f32)n*scale) >> 5)*5,1,pitch); }
 p[0x89]=(u8)key;
 u16 cur, total; total=*(u16*)((u8*)c+0xc6); cur=*(u16*)((u8*)c+0xc8); u32 enabled=p[0x5d]!=0; u8 val;
 if(cur>=total) val=*((u8*)c+0xc5); else {u8 st=*((u8*)c+0xc4); val=st+(cur*(*((u8*)c+0xc5)-st))/total;}
 *((u8*)c+0xc4)=val; *((u8*)c+0xc5)=enabled?0:255; *(u16*)((u8*)c+0xc6)=0; *(u16*)((u8*)c+0xc8)=0;
 return c;
}

/* Base sub-object constructor for a sound-archive: install the vtable at +0,
 * clear the pointer at +4, and set the two byte fields at +8 (0x2F) and +9 (0). */
extern "C" void fn_800F26D8(void *self) {
    extern char lbl_80324848[]; /* vtable for this base sub-object */
    *(s32 *)self = (s32)lbl_80324848;
    *(s32 *)((u8 *)self + 4) = 0;
    *(u8 *)((u8 *)self + 8) = 0x2F;
    *(u8 *)((u8 *)self + 9) = 0;
}

extern "C" s32 fn_800F26FC(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_800F273C(void *obj) __attribute__((noinline)) {
    /* Return nonzero when the object's 32-bit field at offset 4 is set. */
    s32 field = *(s32 *)((u8 *)obj + 4);
    s32 negField = -field;
    return (negField | field) >> 31 & 1;
}

extern "C" void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi_800F2750(void *arg0, s32 flag) {
    /* nw4hbm::snd::SoundPlayer::detail_SetPlayableSoundLimit(int): require a non-zero
     * playable sound count (panic if 0) and store it in the sound player's limit field (+4). */
    if (flag == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803247E0, 0x46, (const char *)lbl_803247F8);
    }
    *(s32 *)((u8 *)arg0 + 4) = flag;
}

extern "C" void fn_800F27AC(void *archive) {
    /* Reset a sound archive: clear the handle at +0x04 and set the byte pair at +0x08/+0x09 to 0x2F, 0. */
    *(s32 *)((u8 *)archive + 4) = 0;
    *(u8 *)((u8 *)archive + 8) = 0x2F;
    *(u8 *)((u8 *)archive + 9) = 0;
}

extern "C" s32 fn_800F27C4(void *arg0) {
    return GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);
#pragma dont_inline on
extern "C" s32 fn_800F27CC(void *archive) {
    /* Return the number of sound groups reported by this archive's file reader. */
    return GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(*(s32*)((u8*)archive + 4));
}
#pragma dont_inline off

/* Convert a sound label string to its sound ID through the archive's file-reader label tree. */
extern "C" s32 fn_800F27D4(void *archive, s32 labelString) {
    SoundArchiveFileReaderLayout *reader = (SoundArchiveFileReaderLayout *)*(void **)((u8 *)archive + 4);
    return ConvertLabelStringToId__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPCQ56nw4hbm3snd6detail16SoundArchiveFile10StringTreePCc(reader, reader->stringTree, labelString);
}

M2C_UNK GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(s32);
extern "C" s32 fn_800F27E4(void *archive) {
    /* Query this archive's file reader for a sound type. */
    return GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(*(s32*)((u8*)archive + 4));
}

M2C_UNK ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(s32);
extern "C" s32 fn_800F27EC(void *archive) {
    /* Read sound info from this archive's file reader. */
    return ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(*(s32*)((u8*)archive + 4));
}

M2C_UNK ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(s32);
extern "C" s32 fn_800F27F4(void *archive) {
    /* Read sequence sound info through this archive's file reader. */
    return ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(*(s32*)((u8*)archive + 4));
}

extern "C" s32 ReadStrmSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13StrmSoundInfo(void *, u32, void *);
extern "C" s32 fn_800F27FC(void *archive) {
    /* Read stream sound info through this archive's file reader. */
    typedef s32 (*ReadStrmSoundInfoThunk)(s32);
    return ((ReadStrmSoundInfoThunk)ReadStrmSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13StrmSoundInfo)(*(s32*)((u8*)archive + 4));
}

M2C_UNK ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(s32);
extern "C" s32 fn_800F2804(void *archive) {
    /* Read wave sound info from this archive's file reader. */
    return ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(*(s32*)((u8*)archive + 4));
}

extern "C" s32 ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo(void *, u32, void *);
extern "C" s32 fn_800F280C(void *archive) {
    typedef s32 (*ReadPlayerInfoThunk)(s32);
    /* Read player info through this archive's file reader. */
    return ((ReadPlayerInfoThunk)ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo)(*(s32*)((u8*)archive + 4));
}

M2C_UNK ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(s32);
extern "C" s32 fn_800F2814(void *archive) {
    /* Read the sound archive player info from this archive's file reader. */
    return ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(*(s32*)((u8*)archive + 4));
}

extern "C" s32 ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(void *, u32, void *);
extern "C" s32 fn_800F281C(void *archive, u32 bankIndex, void *bankInfo) {
    /* Read bank info for the given bank index from this sound archive's file reader. */
    return ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(*(void **)((u8 *)archive + 4), bankIndex, bankInfo);
}

extern "C" s32 ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(void *, u32, void *);
#pragma dont_inline on
extern "C" s32 fn_800F2824(void *archive, u32 groupIndex, void *groupInfo) {
    /* Read group info for the given group index from this sound archive's file reader. */
    return ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(*(void **)((u8 *)archive + 4), groupIndex, groupInfo);
}
#pragma dont_inline reset

M2C_UNK ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(s32);
extern "C" s32 fn_800F282C(void *archive) {
    /* Read group item info through this archive's file reader. */
    return ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(*(s32*)((u8*)archive + 4));
}

M2C_UNK ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(s32);
extern "C" s32 fn_800F2834(void *archive) {
    /* Read file info through this sound archive's file reader. */
    return ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(*(s32*)((u8*)archive + 4));
}

M2C_UNK ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(s32);
extern "C" s32 fn_800F283C(void *archive) {
    /* Read a file position through this archive's file reader. */
    return ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(*(s32*)((u8*)archive + 4));
}

extern "C" s32 ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(void *, u32, void *);
extern "C" s32 ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(void *, u32, u32, void *);
extern "C" s32 ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(void *, u32, u32, void *);
#pragma push
#pragma use_lmw_stmw off
#pragma opt_common_subs off
extern "C" void *detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(void *self, u32 file, void *buffer, int size) {
    struct FileInfo { u32 a, b; const char *path; u32 d; } info;
    struct FilePos { u32 group, item; } pos;
    struct GroupInfo { u32 a; const char *path; u32 offset, size, e, f; } group;
    struct ItemInfo { u32 a, offset, size, d, e, f; } item;
    struct Archive { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void *f4(void *, int, u32, u32); virtual void *f5(void *, int, const char *, u32, u32); };
    Archive *archive = (Archive *)self;
    if (!ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(*(void **)((u8 *)self + 4), file, &info)) return 0;
    const char *path = info.path;
    if (path != 0) {
        char buf[0x100];
        if (*path != '/') {
            unsigned long pathLen = strlen(path);
            unsigned long prefixLen = strlen((const char *)self + 8);
            if (pathLen + prefixLen >= 0x100) {
                Warning__Q26nw4hbm2dbFPCciPCce(lbl_803247E0, 0x155, lbl_80324828, (const char *)self + 8, path);
                return 0;
            }
            strncpy(buf, (const char *)self + 8, prefixLen + 1);
            fn_80028E2C(buf, path, pathLen + 1);
            path = buf;
            goto open_file;
        }
    open_file:
        return archive->f5(buffer, size, path, 0, 0);
    }
    if (!ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(*(void **)((u8 *)self + 4), file, 0, &pos)) return 0;
    if (!ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(*(void **)((u8 *)self + 4), pos.group, &group)) return 0;
    if (!ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(*(void **)((u8 *)self + 4), pos.group, pos.item, &item)) return 0;
    path = group.path;
    u32 offset = group.offset + item.offset;
    u32 length = item.size;
    if (path != 0) {
        char buf[0x100];
        if (*path != '/') {
            unsigned long pathLen = strlen(path);
            unsigned long prefixLen = strlen((const char *)self + 8);
            if (pathLen + prefixLen >= 0x100) {
                Warning__Q26nw4hbm2dbFPCciPCce(lbl_803247E0, 0x155, lbl_80324828, (const char *)self + 8, path);
                return 0;
            }
            strncpy(buf, (const char *)self + 8, prefixLen + 1);
            fn_80028E2C(buf, path, pathLen + 1);
            path = buf;
            goto open_group;
        }
    open_group:
        return archive->f5(buffer, size, path, offset, length);
    }
    return archive->f4(buffer, size, offset, length);
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 detail_OpenGroupStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(void *self, u32 group, void *arg2, s32 arg3) {
    struct GroupInfo { u32 unk0; const char *path; u32 unk8, unkC, unk10, unk14; } info;
    struct Archive { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual s32 f4(void *, s32, s32, s32); virtual s32 f5(void *, s32, const char *, s32, s32); };
    Archive *archive = (Archive *)self;
    if (!ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(*(void **)((u8 *)self + 4), group, &info))
        return 0;
    s32 meta10 = info.unk8;
    s32 meta14 = info.unkC;
    const char *path = info.path;
    if (path != 0) {
        if (*path == '/')
            goto open_stream;
        unsigned long pathLen = strlen(path);
        unsigned long prefixLen = strlen((const char *)self + 8);
        if (pathLen + prefixLen >= 0x100) {
            Warning__Q26nw4hbm2dbFPCciPCce(lbl_803247E0, 0x155, lbl_80324828, (const char *)self + 8, path);
            return 0;
        }
        char buf[0x100];
        strncpy(buf, (const char *)self + 8, prefixLen + 1);
        fn_80028E2C(buf, path, pathLen + 1);
        path = buf;
    open_stream:
        return archive->f5(arg2, arg3, path, meta10, meta14);
    }
    return archive->f4(arg2, arg3, meta10, meta14);
}
#pragma pop

extern "C" s32 ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(void *, u32, void *);
extern "C" unsigned long strlen(const char *);
extern "C" char *strncpy(char *, const char *, unsigned long);
extern "C" void fn_80028E2C(char *, const char *, s32);
extern "C" const char lbl_80324828[];
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 detail_OpenGroupWaveDataStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi_800F2BEC(void *self, u32 group, void *arg2, s32 arg3) {
    struct GroupInfo { u32 unk0; const char *path; u32 unk8, unkC, unk10, unk14; } info;
    struct Archive { virtual void f0(); virtual void f1(); virtual void f2(); virtual s32 f3(); virtual s32 f4(void *, s32, u32, u32); virtual s32 f5(void *, s32, const char *, u32, u32); };
    Archive *archive = (Archive *)self;
    if (!ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(*(void **)((u8 *)self + 4), group, &info))
        return 0;
    const char *path = info.path;
    if (path != 0) {
        u32 meta14 = info.unk14;
        u32 meta10 = info.unk10;
        if (*path == '/')
            goto open_stream;
        unsigned long pathLen = strlen(path);
        unsigned long prefixLen = strlen((const char *)self + 8);
        if (pathLen + prefixLen >= 0x100) {
            Warning__Q26nw4hbm2dbFPCciPCce(lbl_803247E0, 0x155, lbl_80324828, (const char *)self + 8, path);
            return 0;
        }
        char buf[0x100];
        strncpy(buf, (const char *)self + 8, prefixLen + 1);
        fn_80028E2C(buf, path, pathLen + 1);
        path = buf;
    open_stream:
        return archive->f5(arg2, arg3, path, meta10, meta14);
    }
    return archive->f4(arg2, arg3, info.unk10, info.unk14);
}
#pragma pop

/* Clear the seven consecutive 32-bit fields at +0x28..+0x40 of a sound
 * object (the embedded reader initialized during archive construction). */
extern "C" void fn_800F2D28(void *object) {
    *(s32*)((u8*)object + 0x28) = 0;
    *(s32*)((u8*)object + 0x2C) = 0;
    *(s32*)((u8*)object + 0x30) = 0;
    *(s32*)((u8*)object + 0x34) = 0;
    *(s32*)((u8*)object + 0x38) = 0;
    *(s32*)((u8*)object + 0x3C) = 0;
    *(s32*)((u8*)object + 0x40) = 0;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void Init__Q46nw4hbm3snd6detail22SoundArchiveFileReaderFPCv(void *self, const void *arg) {
    typedef void (*PanicCall)(const char *, s32, const char *, ...);
    const u8 *src = (const u8 *)arg;
    u8 *dst = (u8 *)self;
    register const char *base = lbl_80324868;
    u32 version;
    u32 valid;
    if (src == 0)
        ((PanicCall)Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x32, base + 0x1C);
    if (*(const u32 *)src - 0x52530000U != 0x4152U)
        ((PanicCall)Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x48, base + 0x50);
    if (*(const u32 *)src - 0x52530000U == 0x4152U)
        goto valid_magic;
    valid = 0;
    goto copy_if_valid;
valid_magic:
    version = *(const u16 *)(src + 6);
    if (version < 0x100)
        ((PanicCall)Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x50, base + 0xA4);
    version = *(const u16 *)(src + 6);
    if (version >= 0x100)
        goto valid_version_min;
    valid = 0;
    goto copy_if_valid;
valid_version_min:
    if (version > 0x101)
        ((PanicCall)Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x56, base + 0xA4);
    version = *(const u16 *)(src + 6);
    valid = (version <= 0x101);
copy_if_valid:
    if (valid != 0) {
        const u32 *in = (const u32 *)src;
        u32 *out = (u32 *)dst;
        u32 a1 = in[1];
        u32 a0 = in[0];
        out[1] = a1;
        out[0] = a0;
        u32 a3 = in[3];
        u32 a2 = in[2];
        out[3] = a3;
        out[2] = a2;
        out[4] = in[4];
        out[5] = in[5];
        out[6] = in[6];
        out[7] = in[7];
        out[8] = in[8];
        out[9] = in[9];
    }
}
#pragma pop

extern "C" const char lbl_80324868[];
extern "C" void fn_800F2EAC(void *self, void *arg) {
    u8 *object = (u8 *)self;
    const char *base = lbl_80324868;
    u8 *bytes = (u8 *)arg;
    u8 *table;
    u32 baseAddress;
    u8 *offsetPtr;
    u32 value;
    if (arg == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x60, base + 0x104);
    if ((*(u32 *)bytes - 0x53590000U) != 0x4d42U)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x63, base + 0x138);
    table = bytes + 8;
    *(u8 **)(object + 0x2c) = table;
    u32 offset = *(u32 *)(bytes + 8);
    if (offset == 0)
        value = 0;
    else
        value = offset + (u32)table;
    *(u32 *)(object + 0x30) = value;
    baseAddress = *(volatile u32 *)(object + 0x2c);
    offsetPtr = (u8 *)*(volatile u32 *)(table + 4);
    if (offsetPtr == 0)
        value = 0;
    else
        value = (u32)offsetPtr + baseAddress;
    *(u32 *)(object + 0x34) = value;
    baseAddress = *(volatile u32 *)(object + 0x2c);
    offsetPtr = (u8 *)*(volatile u32 *)(table + 8);
    if (offsetPtr == 0)
        value = 0;
    else
        value = (u32)offsetPtr + baseAddress;
    *(u32 *)(object + 0x38) = value;
    baseAddress = *(volatile u32 *)(object + 0x2c);
    offsetPtr = (u8 *)*(volatile u32 *)(table + 0xc);
    if (offsetPtr == 0)
        value = 0;
    else
        value = (u32)offsetPtr + baseAddress;
    *(u32 *)(object + 0x3c) = value;
    baseAddress = *(volatile u32 *)(object + 0x2c);
    offsetPtr = (u8 *)*(volatile u32 *)(table + 0x10);
    if (offsetPtr == 0)
        value = 0;
    else
        value = (u32)offsetPtr + baseAddress;
    *(u32 *)(object + 0x40) = value;
}

extern "C" void SetInfoChunk__Q46nw4hbm3snd6detail22SoundArchiveFileReaderFPCvUl(void *self, const void *chunk, u32 size) {
    typedef char Pool[4096];
    register const char *base = lbl_80324868;
    const u32 *data = (const u32 *)chunk;
    if (data == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)*(Pool*)base, 0x78, base + 0x198);
    if (data[0] != 0x494E464FU)
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)*(Pool*)base, 0x7B, base + 0x1C4);
    *(const void **)((char *)self + 0x28) = (const u8 *)data + 8;
}

namespace nw4hbm { namespace snd { namespace detail { class SoundArchiveFile { public: class StringTree; }; } class SoundArchive { public: class SoundInfo; struct BankInfo { u32 offset; }; typedef detail::SoundArchiveFile::StringTree StringTree; }; namespace detail { class SoundArchiveFileReader { public: s32 GetSoundType(u32) const; BOOL ReadSoundInfo(u32, SoundArchive::SoundInfo *) const; BOOL ReadBankInfo(u32, SoundArchive::BankInfo *) const; s32 ConvertLabelStringToId(const SoundArchive::StringTree *, const char *) const; }; } } }
extern "C" const char lbl_80324DE4[];
extern "C" const char lbl_80324E10[];
extern "C" char lbl_805598C8;
extern "C" char lbl_805598D0;
#pragma push
#pragma scheduling on
s32 nw4hbm::snd::detail::SoundArchiveFileReader::GetSoundType(u32 soundId) const {
    /* Returns the sound type for soundId from the sound archive info: 1, 2, or 3 on success, or 0 if the entry is missing/invalid. */
    register u8 *dataRef = *(u8 **)((u8 *)this + 0x28);
    u8 soundType;
    u8 *soundInfo;
    u32 entryOffset;
    if (dataRef[1] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    soundInfo = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(dataRef[0], *(u32 *)(dataRef + 4), dataRef);
    if (!soundInfo)
        return 0;
    if (soundId >= *(u32 *)soundInfo)
        return 0;
    if (*(u16 *)((u8 *)this + 6) >= 0x101) {
        entryOffset = soundId * 8;
        dataRef = *(u8 **)((u8 *)this + 0x28);
        if (soundInfo[entryOffset + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
        soundType = soundInfo[entryOffset + 5];
        soundInfo = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(soundInfo[entryOffset + 4], *(u32 *)(soundInfo + entryOffset + 8), dataRef);
        if (!soundInfo)
            return 0;
        soundType = soundInfo[0x16];
    } else {
        entryOffset = soundId * 8;
        soundType = soundInfo[entryOffset + 5];
    }
    switch (soundType) {
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    default: return 0;
    }
}
#pragma use_lmw_stmw off
BOOL nw4hbm::snd::detail::SoundArchiveFileReader::ReadSoundInfo(u32 index, nw4hbm::snd::SoundArchive::SoundInfo *info) const {
    register void *archive = *(void **)((u8 *)this + 0x28);
    register u32 soundIndex = index;
    register void *outInfo = info;
    register u8 *soundTable;
    register void *soundEntry;
    /* Look up the sound-info entry for an index and copy its ids into outInfo, handling both the
       current and legacy archive formats; returns FALSE when the table is absent or the index is out of range. */
    if (*((u8 *)archive + 1) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    soundTable = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)archive), *(u32 *)((u8 *)archive + 4), archive);
    if (soundTable == 0) { soundEntry = 0; goto finish; }
    if (soundIndex >= *(u32 *)soundTable) { soundEntry = 0; goto finish; }
    if (*(u16 *)((u8 *)this + 6) >= 0x101) {
        soundIndex <<= 3;
        archive = *(void **)((u8 *)this + 0x28);
        if (soundTable[soundIndex + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
        soundEntry = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(soundTable[soundIndex + 4], *(u32 *)(soundTable + soundIndex + 8), archive);
        goto finish;
    }
    {
        soundEntry = soundTable + (soundIndex << 3);
        archive = *(void **)((u8 *)this + 0x28);
        soundEntry = (void *)(*(u32 *)((u8 *)soundEntry + 8) + (u32)archive);
    }
finish:
    if (soundEntry == 0) return 0;
    *(u32 *)outInfo = *(u32 *)((u8 *)soundEntry + 4);
    *(u32 *)((u8 *)outInfo + 4) = *(u32 *)((u8 *)soundEntry + 8);
    *(u32 *)((u8 *)outInfo + 8) = *((u8 *)soundEntry + 0x15);
    *(u32 *)((u8 *)outInfo + 0xC) = *((u8 *)soundEntry + 0x14);
    return 1;
}
extern "C" s32 ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(void *reader, u32 soundId, void *seqSoundInfo) {
    extern const char lbl_80324BD4[]; /* "NW4HBM:Failed assertion ref.dataType == 1" */
    extern char lbl_80559878;        /* "Util.h" */
    /* Looks up the sequence sound entry for soundId and copies its SeqSoundInfo fields
       (data file id, start offset, alloc track, channel priority) into seqSoundInfo. */
    u64 soundRef = impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(reader, soundId);
    u8 *soundRefBytes = (u8 *)&soundRef;
    void *infoBase = *(void **)((u8 *)reader + 0x28);
    if (soundRefBytes[1] != 1)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559878, 0x70, lbl_80324BD4);
    void *soundData = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(soundRefBytes[0], *(u32 *)(soundRefBytes + 4), infoBase);
    if (!soundData)
        return 0;
    *(u32 *)seqSoundInfo = *(u32 *)soundData;
    *(u32 *)((u8 *)seqSoundInfo + 4) = *(u32 *)((u8 *)soundData + 4);
    *(u32 *)((u8 *)seqSoundInfo + 12) = *(u8 *)((u8 *)soundData + 12);
    *(u32 *)((u8 *)seqSoundInfo + 8) = *(u32 *)((u8 *)soundData + 8);
    return 1;
}

extern "C" const char lbl_80324BA8[];
extern "C" char lbl_80559870;
extern "C" s32 ReadStrmSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13StrmSoundInfo(void *self, u32 index, void *outInfo) {
    u64 refInfo = impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(self, index);
    void *base = *(void **)((u8 *)self + 0x28);
    u8 *bytes = (u8 *)&refInfo;
    if (bytes[1] != 2)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559870, 0x71, lbl_80324BA8);
    s32 data = (s32)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(bytes[0], *(u32 *)(bytes + 4), base);
    s32 ret;
    switch (data) {
        default: ret = 1; break;
        case 0: ret = 0; break;
    }
    return ret;
}

extern "C" s32 ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(void *reader, u32 soundId, void *waveSoundInfo) {
    extern const char lbl_80324B7C[];
    extern char lbl_80559868;
    /* Looks up the wave sound entry for soundId and copies its WaveSoundInfo
       fields (data file id and sub index) into waveSoundInfo. */
    u64 soundInfoRef = impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(reader, soundId);
    u8 *soundInfoRefBytes = (u8 *)&soundInfoRef;
    void *soundInfoBase = *(void **)((u8 *)reader + 0x28);
    if (soundInfoRefBytes[1] != 3)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559868, 0x72, lbl_80324B7C);
    void *soundInfoData = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(soundInfoRefBytes[0], *(u32 *)(soundInfoRefBytes + 4), soundInfoBase);
    if (!soundInfoData)
        return 0;
    *(u32 *)waveSoundInfo = *(u32 *)soundInfoData;
    *(u32 *)((u8 *)waveSoundInfo + 4) = *(u8 *)((u8 *)soundInfoData + 8);
    return 1;
}

#pragma push
#pragma use_lmw_stmw off
/* Reads bank table entry `index` out of the sound archive's INFO chunk: resolves the
   data reference the entry holds (asserting it is a plain one) and returns the bank
   block's offset in info->offset. Returns 0 when the archive has no bank table or
   `index` is past its end. */
BOOL nw4hbm::snd::detail::SoundArchiveFileReader::ReadBankInfo(u32 index, nw4hbm::snd::SoundArchive::BankInfo *info) const {
    register void *bankRef = *(void **)((u8 *)this + 0x28);
    register const void *reader = this;
    register u32 bankIndex = index;
    register nw4hbm::snd::SoundArchive::BankInfo *outInfo = info;
    register u8 *bankTable;
    void *bank;

    if (*((u8 *)bankRef + 9) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559858, 0x6F, lbl_80324B24);
    bankTable = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        *((u8 *)bankRef + 8), *(u32 *)((u8 *)bankRef + 0xC), bankRef);
    if (bankTable == 0)
        bank = 0;
    else if (bankIndex >= *(u32 *)bankTable)
        bank = 0;
    else {
        bankIndex <<= 3;
        bankRef = *(void **)((u8 *)reader + 0x28);
        if (bankTable[bankIndex + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559860, 0x6F, lbl_80324B50);
        bank = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
            bankTable[bankIndex + 4], *(u32 *)(bankTable + bankIndex + 8), bankRef);
    }
    if (bank == 0)
        return 0;
    outInfo->offset = *(u32 *)((u8 *)bank + 4);
    return 1;
}
extern "C" s32 ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo(void *self, u32 index, void *out) {
    extern char lbl_805598A8;
    extern const char lbl_80324CDC[];
    extern char lbl_80559850;
    extern const char lbl_80324AF8[];
    register void *archive = *(void **)((u8 *)self + 0x28);
    register const void *reader = self;
    register u32 playerIndex = index;
    register void *outInfo = out;
    register u8 *playerTable;
    void *player;

    /* Look up a player entry by index and copy its info (playable sound count and heap size) to out. */
    if (*((u8 *)archive + 0x11) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A8, 0x6f, lbl_80324CDC);
    playerTable = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        *((u8 *)archive + 0x10), *(u32 *)((u8 *)archive + 0x14), archive);
    if (playerTable == 0)
        player = 0;
    else if (playerIndex >= *(u32 *)playerTable)
        player = 0;
    else {
        playerIndex <<= 3;
        archive = *(void **)((u8 *)reader + 0x28);
        if (playerTable[playerIndex + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559850, 0x6f, lbl_80324AF8);
        player = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
            playerTable[playerIndex + 4], *(u32 *)(playerTable + playerIndex + 8), archive);
    }
    if (player == 0)
        return 0;
    *(u32 *)outInfo = *(u8 *)((u8 *)player + 4);
    *(u32 *)((u8 *)outInfo + 4) = *(u32 *)((u8 *)player + 8);
    return 1;
}

extern "C" s32 ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(void *self, u32 groupIndex, void *out) {
    extern char lbl_80559848;
    extern char lbl_805598C0;
    extern const char lbl_80559810;
    extern const char lbl_80324ACC[];
    extern const char lbl_80324D60[];
    extern const char lbl_80321F50[];
    /* Resolves the group entry at groupIndex, then fills out with its string table,
       resolved sound reference and the remaining SoundArchive::GroupInfo fields. */
    register u32 group = groupIndex;
    register void *archive = *(void **)((u8 *)self + 0x28);
    register const void *reader = self;
    register void *groupInfo = out;
    struct { u8 *value; } tableSlot;
    u8 *&refTable = tableSlot.value;

    if (*((u8 *)archive + 0x21) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_805598A0, 0x6F, lbl_80324CB0);
    refTable = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        *((u8 *)archive + 0x20), *(u32 *)((u8 *)archive + 0x24), archive);
    if (refTable == 0)
        group = 0;
    else if (group >= *(u32 *)refTable)
        group = 0;
    else {
        archive = (void *)(group << 3);
        group = *(u32 *)((u8 *)reader + 0x28);
        if (refTable[(u32)archive + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559848, 0x6F, lbl_80324ACC);
        group = (u32)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
            refTable[(u32)archive + 4], *(u32 *)(refTable + (u32)archive + 8), (void *)group);
    }
    if (group == 0)
        return 0;
    refTable = *(u8 **)((u8 *)reader + 0x28);
    if (*((u8 *)group + 0x21) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_805598C0, 0x6F, lbl_80324D60);
    refTable = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        *((u8 *)group + 0x20), *(u32 *)((u8 *)group + 0x24), refTable);
    if (refTable == 0)
        return 0;
    archive = *(void **)((u8 *)reader + 0x28);
    if (*((u8 *)group + 9) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559810, 0x6F, lbl_80321F50);
    *(u32 *)((u8 *)groupInfo + 4) = (u32)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        *((u8 *)group + 8), *(u32 *)((u8 *)group + 0xC), archive);
    *(u32 *)((u8 *)groupInfo + 8) = *(u32 *)((u8 *)group + 0x10);
    *(u32 *)((u8 *)groupInfo + 0xC) = *(u32 *)((u8 *)group + 0x14);
    *(u32 *)((u8 *)groupInfo + 0x10) = *(u32 *)((u8 *)group + 0x18);
    *(u32 *)((u8 *)groupInfo + 0x14) = *(u32 *)((u8 *)group + 0x1C);
    *(u32 *)groupInfo = *(u32 *)refTable;
    return 1;
}

#pragma pop
extern "C" const char lbl_80324ACC[];
extern "C" const char lbl_80324D34[];
extern "C" const char lbl_80324D60[];
extern "C" char lbl_80559848;
extern "C" char lbl_805598B8;
extern "C" char lbl_805598C0;
extern "C" char lbl_80559848, lbl_805598B8, lbl_805598C0;
#pragma use_lmw_stmw off
extern "C" s32 ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(void *arg0, u32 arg1, u32 arg2, void *arg3) {
    u8 *ref = *(u8 **)((u8 *)arg0 + 0x28);
    u32 *files;
    u8 *entry;
    u32 *result;
    if (ref[0x21] != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A0, 0x6F, lbl_80324CB0);
    files = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0x20], *(u32 *)(ref + 0x24), ref);
    if (files == 0) { entry = 0; goto second; }
    if (arg1 >= *files) { entry = 0; goto second; }
    {
        s32 off = (s32)arg1 * 8;
        ref = *(u8 **)((u8 *)arg0 + 0x28);
        if (*((u8 *)files + off + 5) != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559848, 0x6F, lbl_80324ACC);
        entry = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)files + off + 4), *(u32 *)((u8 *)files + off + 8), ref);
    }
second:
    if (entry == 0) return 0;
    ref = *(u8 **)((u8 *)arg0 + 0x28);
    if (entry[0x21] != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C0, 0x6F, lbl_80324D60);
    files = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[0x20], *(u32 *)(entry + 0x24), ref);
    if (files == 0) return 0;
    if (arg2 >= *files) return 0;
    {
        s32 off = (s32)arg2 * 8;
        ref = *(u8 **)((u8 *)arg0 + 0x28);
        if (*((u8 *)files + off + 5) != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598B8, 0x6F, lbl_80324D34);
        result = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)files + off + 4), *(u32 *)((u8 *)files + off + 8), ref);
    }
    if (result == 0) return 0;
    ((u32 *)arg3)[0] = result[0]; ((u32 *)arg3)[1] = result[1]; ((u32 *)arg3)[2] = result[2]; ((u32 *)arg3)[3] = result[3]; ((u32 *)arg3)[4] = result[4];
    return 1;
}
#pragma scheduling on
extern "C" s32 ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(void *arg0, void *arg1) {
    extern const char lbl_80324D08[];
    extern char lbl_805598B0;
    void *ref = *(void **)((char *)arg0 + 0x28);
    void *data;
    if (*((u8 *)ref + 0x29) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598B0, 0x6f, lbl_80324D08);
    data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)ref + 0x28), *(u32 *)((char *)ref + 0x2c), ref);
    if (arg1 == 0) return 0;
    *(u32 *)((char *)arg1 + 0x00) = *(u16 *)((char *)data + 0x00);
    *(u32 *)((char *)arg1 + 0x04) = *(u16 *)((char *)data + 0x02);
    *(u32 *)((char *)arg1 + 0x08) = *(u16 *)((char *)data + 0x04);
    *(u32 *)((char *)arg1 + 0x0c) = *(u16 *)((char *)data + 0x06);
    *(u32 *)((char *)arg1 + 0x10) = *(u16 *)((char *)data + 0x08);
    *(u32 *)((char *)arg1 + 0x14) = *(u16 *)((char *)data + 0x0a);
    *(u32 *)((char *)arg1 + 0x18) = *(u16 *)((char *)data + 0x0c);
    return 1;
}
extern "C" const char lbl_80324CDC[];
extern "C" char lbl_805598A8;
extern "C" const char lbl_80324D08[];
extern "C" char lbl_805598B0;
/* Returns the number of players described in the sound archive, or 0 if none. */
extern "C" s32 GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(void *reader) {
    void *fileInfo = *(void **)((char *)reader + 0x28);
    void *playerInfo;
    if (*((u8 *)fileInfo + 0x11) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A8, 0x6f, lbl_80324CDC);
    playerInfo = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)fileInfo + 0x10), *(u32 *)((char *)fileInfo + 0x14), fileInfo);
    if (playerInfo == 0)
        return 0;
    return *(s32 *)playerInfo;
}

/* Return the number of groups in the sound archive file (table count minus one). */
extern "C" s32 GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(void *reader) {
 void *archiveData;
 void *groupTable;
 archiveData = *(void**)((u8*)reader + 0x28);
 if (((u8*)archiveData)[0x21] != 0) {
   Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A0, 0x6F, lbl_80324CB0);
 }
 groupTable = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(((u8*)archiveData)[0x20], *(u32*)((u8*)archiveData + 0x24), archiveData);
 if (groupTable == 0) return 0;
 return *(s32*)groupTable - 1;
}

extern "C" const char lbl_80559898;
extern "C" const char lbl_80559888;
extern "C" const char lbl_80559890;
extern "C" const char lbl_80559810;
extern "C" const char lbl_80324C84[];
extern "C" const char lbl_80324C2C[];
extern "C" const char lbl_80324C58[];
extern "C" const char lbl_80321F50[];
#pragma opt_common_subs off
extern "C" s32 ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(void *self, u32 fileIndex, void *out) {
    register u32 file = fileIndex;
    register u8 *archive = *(u8 **)((u8 *)self + 0x28);
    register const void *reader = self;
    register void *fileInfo = out;
    u8 *files;
    u8 *detail;
    u8 *player;

    if (*((u8 *)archive + 0x19) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559898, 0x6F, lbl_80324C84);
    files = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)archive + 0x18), *(u32 *)((u8 *)archive + 0x1C), archive);
    if (files == 0) return 0;
    if (file >= *(u32 *)files) return 0;
    archive = (u8 *)(file << 3);
    file = *(u32 *)((u8 *)reader + 0x28);
    if (files[(u32)archive + 5] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559888, 0x6F, lbl_80324C2C);
    detail = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(files[(u32)archive + 4], *(u32 *)(files + (u32)archive + 8), (void *)file);
    if (detail == 0) return 0;
    file = *(u32 *)((u8 *)reader + 0x28);
    if (*((u8 *)detail + 0x15) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559890, 0x6F, lbl_80324C58);
    player = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)detail + 0x14), *(u32 *)((u8 *)detail + 0x18), (void *)file);
    if (player == 0) return 0;
    archive = *(u8 **)((u8 *)reader + 0x28);
    *(u32 *)fileInfo = *(u32 *)detail;
    *(u32 *)((u8 *)fileInfo + 4) = *(u32 *)((u8 *)detail + 4);
    if (*((u8 *)detail + 0xD) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559810, 0x6F, lbl_80321F50);
    *(void **)((u8 *)fileInfo + 8) = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)detail + 0xC), *(u32 *)((u8 *)detail + 0x10), archive);
    *(u32 *)((u8 *)fileInfo + 0xC) = *(u32 *)player;
    return 1;
}
#pragma opt_common_subs reset
extern "C" s32 ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(void *arg0, u32 arg1, u32 arg2, void *arg3) {
    extern const char lbl_80559898;
    extern const char lbl_80559880;
    extern const char lbl_80559888;
    extern const char lbl_80559890;
    extern const char lbl_80324C84[];
    extern const char lbl_80324C2C[];
    extern const char lbl_80324C58[];
    extern const char lbl_80324C00[];
    u8 *ref = *(u8 **)((u8 *)arg0 + 0x28);
    u32 *table;
    u8 *entry;
    u32 *group;
    if (ref[0x19] != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559898, 0x6F, lbl_80324C84);
    table = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0x18], *(u32 *)(ref + 0x1C), ref);
    if (table == 0) return 0;
    if (arg1 >= *table) return 0;
    {
        u32 off = arg1 * 8;
        ref = *(u8 **)((u8 *)arg0 + 0x28);
        if (*((u8 *)table + off + 5) != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559888, 0x6F, lbl_80324C2C);
        entry = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)table + off + 4), *(u32 *)((u8 *)table + off + 8), ref);
    }
    if (entry == 0) return 0;
    ref = *(u8 **)((u8 *)arg0 + 0x28);
    if (entry[0x15] != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559890, 0x6F, lbl_80324C58);
    group = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[0x14], *(u32 *)(entry + 0x18), ref);
    if (group == 0) return 0;
    if (arg2 >= *group) return 0;
    {
        u32 off = arg2 * 8;
        ref = *(u8 **)((u8 *)arg0 + 0x28);
        if (*((u8 *)group + off + 5) != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559880, 0x6F, lbl_80324C00);
        table = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)group + off + 4), *(u32 *)((u8 *)group + off + 8), ref);
    }
    if (table == 0) return 0;
    *(u32 *)arg3 = table[0];
    *(u32 *)((u8 *)arg3 + 4) = table[1];
    return 1;
}
extern "C" int strcmp(const char *, const char *);
extern "C" const char lbl_80324A8C[]; /* "NW4HBM:Failed assertion id < mStringTable->offsetTable.count" */
#pragma push
#pragma scheduling on
/* nw4hbm::snd::detail::SoundArchiveFileReader::ConvertLabelStringToId: looks a label
   string up in the archive's string trie and returns the sound id stored at the leaf it
   leads to, or InvalidSoundId when the archive holds no such sound -- the tree is
   missing, its root index is out of range, or the string the archive stores for the
   leaf's label id is not the one asked for.  The trie holds one node per bit of the
   labels it was built from: an inner node tests that bit of `labelString' and walks to
   the child for 0 or for 1. */
s32 nw4hbm::snd::detail::SoundArchiveFileReader::ConvertLabelStringToId(const nw4hbm::snd::SoundArchive::StringTree *stringTree, const char *labelString) const {
    const char *str = labelString;
    const StringTreeLayout *tree = (const StringTreeLayout *)stringTree;
    const SoundArchiveFileReaderLayout *reader = (const SoundArchiveFileReaderLayout *)this;
    const StringTreeNodeLayout *node;
    if (tree == 0) return InvalidSoundId;
    u32 rootIndex = tree->nodeCount;
    if (rootIndex >= tree->maxNodeCount) return InvalidSoundId;
    node = &tree->nodes[rootIndex];
    s32 length = strlen(str);
    while ((node->flags & StringTreeNodeIsLeaf) == 0) {
        s32 bitPos = node->bitIndex;
        s32 byteIndex = bitPos >> 3;
        s32 bitIndex = bitPos & 7;
        s32 child;
        if (byteIndex < length && (((s8)str[byteIndex] & (1 << (7 - bitIndex))) != 0))
            child = node->oneChild;
        else
            child = node->zeroChild;
        node = &tree->nodes[child];
    }
    /* The walk is over; `tree' now holds the leaf's label id, kept in the same variable.
       InvalidLabelId, and a label id past the string table's count (asserted below),
       mean the string is not a label of this archive. */
    tree = (const StringTreeLayout *)node->labelId;
    const char *label;
    u32 labelIdTest = (u32)tree + 0x10000; /* 0xFFFF for InvalidLabelId */
    if (labelIdTest == 0xFFFF) {
        label = 0;
    } else {
        SoundArchiveLabelTableLayout *table = reader->labelTable;
        if (table == 0) {
            label = 0;
        } else {
            /* NW4HBM_ASSERT(id < mStringTable->offsetTable.count) */
            if ((u32)tree >= table->count)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324868, 0x1BA, lbl_80324A8C);
            table = *(SoundArchiveLabelTableLayout * volatile *)((u8 *)reader + 0x30);
            const char *base = reader->stringBase;
            u32 offset = table->labelOffsets[(u32)tree];
            if (offset == 0) {
                label = 0; /* the label has no string */
            } else {
                label = (const char *)(offset + (u32)base);
            }
        }
    }
    if (strcmp(str, label) == 0)
        return node->soundId;
    return InvalidSoundId;
}
#pragma pop

extern "C" void *GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(s32, u32, void *);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern "C" u64 lbl_8055DE50;
extern "C" u64 lbl_8055DE54;
#pragma push
#pragma scheduling on
extern "C" u64 impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(void *self, unsigned long idx) {
    u8 *ref = *(u8 **)((u8 *)self + 0x28);
    if (ref[1] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    u8 *base = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0], *(u32 *)(ref + 4), ref);
    if (base == 0)
        return lbl_8055DE50;
    if (idx >= *(u32 *)base)
        return lbl_8055DE50;
    if (*(u16 *)((u8 *)self + 6) >= 0x101) {
        idx <<= 3;
        ref = *(u8 **)((u8 *)self + 0x28);
        if (base[idx + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
        u8 *entry = base + idx;
        u8 *data = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[4], *(u32 *)(entry + 8), ref);
        if (data == 0)
            return lbl_8055DE50;
        return *(u64 *)(data + 0x18);
    }
    u8 *entry = base + idx * 8;
    struct Result { u8 type; u8 ext; u16 pad; u32 offset; } result;
    result.type = entry[4];
    result.ext = entry[5];
    result.offset = *(u32 *)(entry + 8) + 0x1C;
    return *(u64 *)&result;
}
#pragma pop
// detail::SoundArchiveLoader::FileBuffer: a reusable 0x220-byte file-reading
// buffer with an embedded mutex, the id it was set up for and the stream it is
// currently reading (null while idle).
struct SoundFileBufferLayout {
    u8 mutexArea[0x18];    // 0x00 embedded OSMutex, initialised by OSInitMutex
    s32 setupId;           // 0x18 id this buffer is set up for
    u8 pad[0x21C - 0x1C];  // 0x1C
    s32 currentStream;     // 0x21C stream being read; null when idle
};

extern "C" void *fn_800F41D0(void *buffer, s32 setupId) {
    /* Set up a SoundArchiveLoader file buffer: record the id it was set up for,
       clear the current-stream pointer and initialise its embedded mutex. */
    ((SoundFileBufferLayout *)buffer)->setupId = setupId;
    ((SoundFileBufferLayout *)buffer)->currentStream = 0;
    OSInitMutex(buffer);
    return buffer;
}

/* Deleting-destructor helper: free `object` when `shouldDelete` is set, then return it. */
extern "C" s32 fn_800F420C(s32 object, s32 shouldDelete) {
#define MemFree fn_80128668
    if (object != 0 && shouldDelete > 0) {
        MemFree();
    }
    return object;
#undef MemFree
}

extern "C" const char lbl_80324E40[];
extern "C" const char lbl_80324E5C[];

// The stream a SoundArchive opens for the loader: detail::OpenFileStream,
// OpenGroupStream and OpenGroupWaveDataStream all return one.  The two leading
// destructor slots put the first declared method at 0x8, so the offsets in the
// comments are the vtable slots the loaders' calls use; only the slots they call
// are named.  A stream is usable once IsOpen() and IsReady() both say so, and
// the loader keeps the one it is reading in its own field 0x21C so Cancel() can
// stop it.
struct ArchiveStream {
    virtual void f0();                        // 0x08
    virtual void f1();                        // 0x0C
    virtual void Close();                     // 0x10
    virtual s32 Read(void *dst, u32 size);    // 0x14
    virtual void f4();                        // 0x18
    virtual void f5();                        // 0x1C
    virtual void f6();                        // 0x20
    virtual void f7();                        // 0x24
    virtual void f8();                        // 0x28
    virtual s32 IsOpen();                     // 0x2C
    virtual void f10();                       // 0x30
    virtual void f11();                       // 0x34
    virtual void f12();                       // 0x38
    virtual void f13();                       // 0x3C
    virtual u32 GetSize();                    // 0x40
    virtual void Seek(s32 offset, s32 origin);// 0x44
    virtual void f16();                       // 0x48
    virtual void f17();                       // 0x4C
    virtual s32 IsReady();                      // 0x50
};

#pragma push
#pragma use_lmw_stmw off
extern "C" void *LoadGroup__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatablePPvUl(void *self, u32 groupId, void *allocator, void **outWave, u32 blockSize) {
    class Stream {
    public:
        virtual void v0();
        virtual void v1();
        virtual void Close();
        virtual s32 Read(void *, u32);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual s32 IsOpen();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual u32 GetSize();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual s32 IsReady();
    };
    class Allocator {
    public:
        virtual void v0();
        virtual void *Alloc(u32);
    };
    struct { u32 pad[5]; s32 hasWave; } info;

    if (allocator == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E40, 0x53, lbl_80324E5C);
    }
    OSLockMutex(self);
    Stream *stream = (Stream *)detail_OpenGroupStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(*(void **)((char *)self + 0x18), groupId, (char *)self + 0x1c, 0x200);
    if (stream == 0) {
        if (stream != 0)
            stream->Close();
        OSUnlockMutex(self);
        return 0;
    }
    if (stream->IsReady() == 0 || stream->IsOpen() == 0) {
        if (stream != 0)
            stream->Close();
        OSUnlockMutex(self);
        return 0;
    }
    void *buf = ((Allocator *)allocator)->Alloc(stream->GetSize());
    if (buf == 0) {
        if (stream != 0)
            stream->Close();
        OSUnlockMutex(self);
        return 0;
    }
    *(Stream **)((char *)self + 0x21c) = stream;
    if (blockSize == 0) {
        if (stream->Read(buf, stream->GetSize()) == 0) {
            *(void **)((char *)self + 0x21c) = 0;
            if (stream != 0)
                stream->Close();
            OSUnlockMutex(self);
            return 0;
        }
    } else {
        void *p = buf;
        u32 remain = stream->GetSize();
        while (remain != 0) {
            if (stream->Read(p, blockSize > remain ? remain : blockSize) == 0) {
                *(void **)((char *)self + 0x21c) = 0;
                if (stream != 0)
                    stream->Close();
                OSUnlockMutex(self);
                return 0;
            }
            if (remain > blockSize) {
                remain -= blockSize;
                p = (char *)p + blockSize;
            } else {
                remain = 0;
            }
        }
    }
    *(void **)((char *)self + 0x21c) = 0;
    if (fn_800F2824(*(void **)((char *)self + 0x18), groupId, &info) == 0) {
        if (stream != 0)
            stream->Close();
        OSUnlockMutex(self);
        return 0;
    }
    if (info.hasWave != 0) {
        Stream *stream2 = (Stream *)detail_OpenGroupWaveDataStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi_800F2BEC(*(void **)((char *)self + 0x18), groupId, (void *)((u32)self + 0x1c), 0x200);
        if (stream2 == 0) {
            if (stream2 != 0)
                stream2->Close();
            if (stream != 0)
                stream->Close();
            OSUnlockMutex(self);
            return 0;
        }
        if (stream2->IsReady() == 0 || stream2->IsOpen() == 0) {
            if (stream2 != 0)
                stream2->Close();
            if (stream != 0)
                stream->Close();
            OSUnlockMutex(self);
            return 0;
        }
        void *buf2 = ((Allocator *)allocator)->Alloc(stream2->GetSize());
        if (buf2 == 0) {
            if (stream2 != 0)
                stream2->Close();
            if (stream != 0)
                stream->Close();
            OSUnlockMutex(self);
            return 0;
        }
        *(Stream **)((char *)self + 0x21c) = stream2;
        if (blockSize == 0) {
            if (stream2->Read(buf2, stream2->GetSize()) == 0) {
                *(void **)((char *)self + 0x21c) = 0;
                if (stream2 != 0)
                    stream2->Close();
                if (stream != 0)
                    stream->Close();
                OSUnlockMutex(self);
                return 0;
            }
        } else {
            void *p = buf2;
            u32 remain = stream2->GetSize();
            while (remain != 0) {
                if (stream2->Read(p, blockSize > remain ? remain : blockSize) == 0) {
                    *(void **)((char *)self + 0x21c) = 0;
                    if (stream2 != 0)
                        stream2->Close();
                    if (stream != 0)
                        stream->Close();
                    OSUnlockMutex(self);
                    return 0;
                }
                if (remain > blockSize) {
                    remain -= blockSize;
                    p = (char *)p + blockSize;
                } else {
                    remain = 0;
                }
            }
        }
        *(void **)((char *)self + 0x21c) = 0;
        if (outWave != 0)
            *outWave = buf2;
        if (stream2 != 0)
            stream2->Close();
    } else {
        if (outWave != 0)
            *outWave = 0;
    }
    if (stream != 0)
        stream->Close();
    OSUnlockMutex(self);
    return buf;
}
#pragma pop
extern "C" void OSLockMutex(void *);
extern "C" void OSUnlockMutex(void *);
extern "C" void *detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(void *, unsigned long, void *, int);
#pragma push
#pragma use_lmw_stmw off
/* Read one file of the archive this loader works on: open a stream on it, seek to
 * `offset' and read `length' rounded up to a 0x20 boundary into `buffer'.  The
 * loader's mutex is held over the whole read and the stream is published in the
 * loader while it runs so Cancel() can stop it.  Returns `length', or -1 when the
 * file cannot be opened, the stream is not usable or the read failed. */
extern "C" long ReadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPvll(void *self, unsigned long fileId, void *buffer, long length, long offset) {
    ArchiveStream *stream;
    long bytesRead;
    OSLockMutex(self);
    /* the archive at +0x18, the loader's stream setup at +0x1c and its 0x200 */
    stream = (ArchiveStream*)detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(*(void **)((char *)self + 0x18), fileId, (char *)self + 0x1c, 0x200);
    if (stream == 0) {
        /* every exit closes the stream; here that can only be the null check */
        if (stream != 0) stream->Close();
        OSUnlockMutex(self);
        return -1;
    }
    if (stream->IsReady() == 0 || stream->IsOpen() == 0) {
        if (stream != 0) stream->Close();
        OSUnlockMutex(self);
        return -1;
    }
    stream->Seek(offset, 0);
    *(void **)((char *)self + 0x21c) = stream;
    bytesRead = stream->Read(buffer, ((length + 0x1f) & ~0x1f));
    *(void **)((char *)self + 0x21c) = 0;
    if (bytesRead == 0) {
        if (stream != 0) stream->Close();
        OSUnlockMutex(self);
        return -1;
    }
    if (stream != 0) stream->Close();
    OSUnlockMutex(self);
    return length;
}
#pragma pop
extern "C" void DCStoreRange(void *, u32);
extern "C" void *LoadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatable(void *self, unsigned int fileId, void *allocator) {
    typedef s32 (*ReadFileInfoFn)(void *, unsigned int, long *);
    DummyAllocatable_LoadFile *alloc = (DummyAllocatable_LoadFile *)allocator;
    long fileInfo[4];

    /* Load a sound archive file into memory allocated via the provided allocator. */
    if (alloc == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E40, 0x12B, lbl_80324E5C);
    if (((ReadFileInfoFn)fn_800F2834)(*(void **)((u8 *)self + 0x18), fileId, fileInfo) == 0)
        return 0;

    long fileSize = fileInfo[0];
    if (fileSize == 0)
        return 0;

    void *buffer = alloc->Alloc(fileSize);
    if (buffer == 0)
        return 0;

    if ((unsigned long)fileSize != (unsigned long)ReadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPvll(self, fileId, buffer, fileSize, 0))
        return 0;

    DCStoreRange(buffer, fileSize);
    return buffer;
}

extern "C" void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void *loader) {
    /* Cancel the loader's current sound, if any: stop it when active, otherwise finalize it. */
    class Sound {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual s32 m8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void m16();
        virtual void m17(s32, s32);
        virtual void v18();
        virtual s32 Check();
    };

    Sound *sound = *(Sound **)((u8 *)loader + 0x21C);
    if (sound && sound->Check()) {
        sound = *(Sound **)((u8 *)loader + 0x21C);
        if (sound->m8()) {
            sound = *(Sound **)((u8 *)loader + 0x21C);
            sound->m17(0, 0);
        } else {
            sound = *(Sound **)((u8 *)loader + 0x21C);
            sound->m16();
        }
    }
}

extern "C" const char lbl_803256E8[];
extern "C" const char lbl_803256D8[];
extern "C" const char lbl_803256B0[];
extern "C" const char lbl_803256C0[];
extern "C" const char lbl_80323750[];
extern "C" const char lbl_803237B8[];
extern "C" void RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *, void *);
extern "C" void *__ct__Q36nw4hbm3snd18SoundArchivePlayerFv(void *self) {
    /* Constructs a SoundArchivePlayer, initializing embedded subobjects, lists, mutexes, and dispose callback. */
    *(s32 *)((u8 *)self + 0x00) = 0;
    *(s32 *)((u8 *)self + 0x04) = 0;
    *(void **)((u8 *)self + 0x08) = (void *)lbl_80325640;
    *(void **)((u8 *)self + 0x0C) = (void *)(lbl_80325640 + 0x14);
    *(s32 *)((u8 *)self + 0x10) = 0;
    *(s32 *)((u8 *)self + 0x14) = 0;
    *(void **)((u8 *)self + 0x18) = (void *)lbl_803256E8;
    *(void **)((u8 *)self + 0x1C) = self;
    OSInitMutex((u8 *)self + 0x20);
    *(void **)((u8 *)self + 0x3C) = self;
    *(void **)((u8 *)self + 0x38) = (void *)lbl_803256D8;
    *(void **)((u8 *)self + 0x40) = (void *)lbl_803256B0;
    *(void **)((u8 *)self + 0x44) = self;
    *(void **)((u8 *)self + 0x48) = (void *)lbl_803256C0;
    *(void **)((u8 *)self + 0x4C) = self;
    OSInitMutex((u8 *)self + 0x50);
    u32 tempC4 = (u32)self + 0xC4;
    u32 tempC0 = (u32)self + 0xC0;
    *(s32 *)((u8 *)self + 0x80) = 0;
    u32 temp80 = (u32)self + 0x80;
    u32 temp90 = (u32)self + 0x90;
    u32 tempA0 = (u32)self + 0xA0;
    *(s32 *)((u8 *)self + 0x84) = 0;
    *(s32 *)((u8 *)self + 0x90) = 0;
    *(s32 *)((u8 *)self + 0x94) = 0;
    *(s32 *)((u8 *)self + 0xA0) = 0;
    *(s32 *)((u8 *)self + 0xA4) = 0;
    *(void **)((u8 *)self + 0x68) = (void *)tempC4;
    *(s32 *)((u8 *)self + 0x6C) = 0;
    *(s32 *)((u8 *)self + 0x70) = 0;
    *(s32 *)((u8 *)self + 0x74) = 0;
    *(s32 *)((u8 *)self + 0x78) = 0;
    *(s32 *)((u8 *)self + 0x7C) = 0;
    *(void **)((u8 *)self + 0x80) = (void *)temp80;
    *(void **)((u8 *)self + 0x84) = (void *)temp80;
    *(s32 *)((u8 *)self + 0x88) = 0;
    *(s32 *)((u8 *)self + 0x8C) = 0;
    *(void **)((u8 *)self + 0x90) = (void *)temp90;
    *(void **)((u8 *)self + 0x94) = (void *)temp90;
    *(s32 *)((u8 *)self + 0x98) = 0;
    *(s32 *)((u8 *)self + 0x9C) = 0;
    *(void **)((u8 *)self + 0xA0) = (void *)tempA0;
    *(void **)((u8 *)self + 0xA4) = (void *)tempA0;
    *(void **)((u8 *)self + 0xC0) = (void *)lbl_80323750;
    *(void **)((u8 *)self + 0xC4) = (void *)lbl_803237B8;
    *(void **)((u8 *)self + 0xC8) = (void *)tempC0;
    *(s32 *)((u8 *)self + 0xCC) = 0;
    *(s32 *)((u8 *)self + 0xD0) = 0;
    *(s32 *)((u8 *)self + 0xD4) = 0;
    RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
        GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), self);
    return self;
}

void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv_old(void *self) {
    class Sound {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual s32 m8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void m16();
        virtual void m17(s32, s32);
        virtual void v18();
        virtual s32 Check();
    };

    Sound *sound = *(Sound **)((u8 *)self + 0x21C);
    if (sound && sound->Check()) {
        sound = *(Sound **)((u8 *)self + 0x21C);
        if (sound->m8()) {
            sound = *(Sound **)((u8 *)self + 0x21C);
            sound->m17(0, 0);
        } else {
            sound = *(Sound **)((u8 *)self + 0x21C);
            sound->m16();
        }
    }
}

extern "C" s32 fn_800F4CC4(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* CodeWarrior deleting-destructor helper: free the object with MemFree when
 * deleting (flag > 0), then return the object pointer. */
extern "C" s32 fn_800F4D04(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_800F4D44(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_800F4D84(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* CodeWarrior deleting-destructor helper: free the object with MemFree when
 * deleting (flag > 0), then return the object pointer. */
extern "C" s32 fn_800F4DC4(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Deleting-destructor helper: free `object` when `shouldDelete` is set, then return it. */
extern "C" s32 fn_800F4E04(s32 object, s32 shouldDelete) {
#define MemFree fn_80128668
    if (object != 0 && shouldDelete > 0) {
        MemFree();
    }
    return object;
#undef MemFree
}

extern "C" s32 fn_800F4E44(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

/* CodeWarrior deleting-destructor helper: free the object with MemFree when
 * deleting (flag > 0), then return the object pointer. */
extern "C" s32 fn_800F4E84(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* CodeWarrior deleting-destructor helper: free the object with MemFree when
 * deleting (flag > 0), then return the object pointer. */
extern "C" s32 fn_800F4EC4(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" void fn_800F4F04(void *list) {
    // Initialize an empty nw4r ut::LinkList: clear the element count at +0x00,
    // then make the sentinel node's next (+0x04) and prev (+0x08) point at itself.
    s32 *sentinel = (s32 *)((u8 *)list + 4);
    *(s32 *)((u8 *)list + 4) = 0;
    *(s32 *)((u8 *)list + 8) = 0;
    *(s32 *)list = 0;
    *(s32 *)((u8 *)list + 4) = (s32)sentinel;
    *(s32 *)((u8 *)list + 8) = (s32)sentinel;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F24(void *self, int shouldDelete) {
    /* Destroy an embedded LinkListImpl subobject and optionally delete storage. */
    if (self != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(self, 0);
        if (shouldDelete > 0) ((void (*)(void *))fn_80128668)(self);
    }
    return self;
}

extern "C" void fn_800F4F7C(void *list) {
    /* Initialize an embedded nw4r::ut::LinkListImpl: clear the node count, then
     * make the sentinel link at +4 point to itself so the list starts empty. */
    s32 *sentinel = (s32 *)((u8 *)list + 4);
    *(s32 *)((u8 *)list + 4) = 0;
    *(s32 *)((u8 *)list + 8) = 0;
    *(s32 *)list = 0;
    *(s32 *)((u8 *)list + 4) = (s32)sentinel;
    *(s32 *)((u8 *)list + 8) = (s32)sentinel;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F9C(void *self, int shouldDelete) {
    /* Destroy an embedded LinkListImpl subobject and optionally delete storage. */
    if (self != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(self, 0);
        if (shouldDelete > 0) ((void (*)(void *))fn_80128668)(self);
    }
    return self;
}

extern "C" void fn_800F4FF4(void *list) {
    /* Construct the embedded LinkListImpl: zero the node, then point the +4
     * sentinel link at itself so the list starts empty. */
    s32 *sentinel = (s32 *)((u8 *)list + 4);
    *(s32 *)((u8 *)list + 4) = 0;
    *(s32 *)((u8 *)list + 8) = 0;
    *(s32 *)list = 0;
    *(s32 *)((u8 *)list + 4) = (s32)sentinel;
    *(s32 *)((u8 *)list + 8) = (s32)sentinel;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F5014(void *self, int shouldDelete) {
    /* nw4hbm::snd::MemorySoundArchive destructor: destroy embedded LinkListImpl
     * subobject and, if requested, free this object's storage. */
    if (self != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(self, 0);
        if (shouldDelete > 0) ((void (*)(void *))fn_80128668)(self);
    }
    return self;
}

extern "C" void *__dt__Q36nw4hbm3snd18SoundArchivePlayerFv(void *self, s32 flag) {
    /* nw4hbm::snd::SoundArchivePlayer destructor: reset vtables, unregister dispose callback, destroy embedded lists, optionally delete. */
    if (self != 0) {
        *(void **)((u8 *)self + 8) = (void *)lbl_80325640;
        *(void **)((u8 *)self + 0xC) = (void *)(lbl_80325640 + 0x14);
        ((void (*)(void *, void *))UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase)(
            GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), self);
        if ((u8 *)self + 0x98 != 0) {
            if ((u8 *)self + 0x9C != 0)
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 0x9C, 0);
        }
        if ((u8 *)self + 0x88 != 0) {
            if ((u8 *)self + 0x8C != 0)
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 0x8C, 0);
        }
        if ((u8 *)self + 0x78 != 0) {
            if ((u8 *)self + 0x7C != 0)
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 0x7C, 0);
        }
        if (flag > 0)
            ((void (*)(void *))fn_80128668)(self);
    }
    return self;
}

extern "C" s32 SetupMram__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePvUl(void *self, const void *archive, void *buffer, u32 size);
extern "C" void Setup__Q46nw4hbm3snd6detail14StrmBufferPoolFPvUli(void *this_, void *buffer, u32 size, s32 count);
struct SetupStrings { char file; char _pad1[0x1B]; char m1C[0x28]; char m44[0x2C]; char m70[0x30]; char mA0[8]; };
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 Setup__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePvUlPvUl(void *self, const void *archive, void *buffer, u32 size, void *streamBuffer, u32 streamBufferSize) {
    struct PlayerInfo { u32 fields[7]; };
    const char *base = lbl_80324E88;
    PlayerInfo firstInfo;
    PlayerInfo secondInfo;
    PlayerInfo streamInfo;
    s32 firstCount;
    s32 secondCount;
    s32 thirdCount;
    s32 result;
    if (archive == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0xA2, base + 0x1C);
    if (buffer == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0xA3, base + 0x44);
    if (streamBuffer == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0xA4, base + 0x70);
    if (archive == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x119, base + 0x1C);
    firstCount = 0;
    if (((s32 (*)(const void *, void *))fn_800F2814)(archive, &firstInfo))
        firstCount = firstInfo.fields[4];
    if (streamBufferSize < (u32)firstCount * 0xA000)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0xA5, base + 0xA0);
    if (SetupMram__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePvUl(self, archive, buffer, size) == 0)
        return 0;
    if (archive == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x119, base + 0x1C);
    secondCount = 0;
    if (((s32 (*)(const void *, void *))fn_800F2814)(archive, &secondInfo))
        secondCount = secondInfo.fields[4];
    if (streamBufferSize < (u32)secondCount * 0xA000) {
        result = 0;
    } else {
        thirdCount = 0;
        if (((s32 (*)(const void *, void *))fn_800F2814)(archive, &streamInfo))
            thirdCount = streamInfo.fields[4];
        Setup__Q46nw4hbm3snd6detail14StrmBufferPoolFPvUli((u8 *)self + 0xA8, streamBuffer, streamBufferSize, thirdCount);
        result = 1;
    }
    if (result == 0)
        return 0;
    return 1;
}
#pragma pop
extern "C" void* __dt__Q36nw4hbm3snd11SoundPlayerFv(void*, s32);
extern "C" void fn_800FA9E8(void*);
extern "C" void DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(void*, void*, u32);
extern "C" void fn_800EE434(void*, void*, u32);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, s32, const char*, ...) __attribute__((noreturn));
extern "C" const char lbl_80325ABC[];
extern "C" const char lbl_80325AE8[];
extern "C" const char lbl_80325B00[];
extern "C" const char lbl_80325B2C[];
extern "C" const char lbl_80325B44[];
extern "C" const char lbl_80325B70[];


extern "C" s32 GetRequiredMemSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(void *player, void *archive) {
    /* Computes the total aligned memory required for sound archive player data (groups, tracks, and player info blocks) from archive metadata. */
    struct GroupInfo { s32 count; s32 size; };
    struct SoundInfo { s32 a; s32 b; s32 c; s32 d; s32 e; s32 f; };
    if (archive == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0xDC, lbl_80324EA4);
    s32 numGroups = ((s32 (*)(void *))fn_800F27C4)(archive);
    s32 total = (numGroups * 0x48 + 3) & ~3;
    for (u32 i = 0; i < (u32)numGroups; i++) {
        GroupInfo group;
        if (((s32 (*)(void *, u32, void *))fn_800F280C)(archive, i, &group)) {
            s32 bytes = (group.size + 0x3F) & ~3;
            s32 count = group.count;
            for (s32 j = 0; j < count; j++) {
                if (group.size != 0)
                    total += bytes;
            }
        }
    }
    total += (((s32 (*)(void *))fn_800F27CC)(archive) * 8 + 7) & ~3;
    SoundInfo info;
    if (((s32 (*)(void *, void *))fn_800F2814)(archive, &info)) {
        total += (info.a * 0x1F4 + 3) & ~3;
        total += (info.c * 0x614 + 3) & ~3;
        total += (info.f * 0x1B4 + 3) & ~3;
        total += (info.b * 0xD4 + 3) & ~3;
    }
    return total;
}

extern "C" s32 GetRequiredStrmBufferSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(void *self, void *archive) {
    /* Return required stream buffer size (info[4] * 0xA000) for the given sound archive, or 0 if unavailable. */
    s32 info[8];
    if (archive == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x119, lbl_80324EA4);
    s32 result = 0;
    if (((s32 (*)(void *, void *))fn_800F2814)(archive, info) != 0)
        result = info[4];
    return result * 0xA000;
}

extern "C" u32 CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl(void*, void*, u32, u32);
extern "C" u32 fn_800EE428(void*, void*, u32);
extern "C" s32 fn_800F2814(void*);
extern "C" s32 SetupSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePPvPv(void*, void*, void**, void*);
extern "C" const char lbl_80325AA4[];
extern "C" const char lbl_80325A78[];
extern "C" const char lbl_80325A1C[];
extern "C" const char lbl_803259F0[];
extern "C" const char lbl_80325A60[];
extern "C" const char lbl_80325A34[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" s32 SetupMram__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePvUl(void *self, const void *archive, void *buffer, u32 size) {
    struct GroupEntry { u32 a; u32 b; };
    struct GroupList { u32 count; GroupEntry entries[1]; };
    struct SoundInfo { u32 counts[7]; };
    struct Local { u32 cursor; struct SoundInfo info; } local;
    const char *base = lbl_80324E88;
    u32 aligned;
    u32 ptr;
    u32 end;
    u32 created;
    u32 i;
    long count;
    s32 result;

    if (archive == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x139, base + 0x1C);
    if ((unsigned)buffer == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x13A, base + 0x44);
    if (((u32)buffer & 3) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x13B, base + 0xEC, buffer);
    if (size < (u32)GetRequiredMemSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(self, (void *)archive))
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x13C, base + 0x138);

    end = (u32)buffer + size;
    local.cursor = (u32)buffer;
    if (SetupSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePPvPv(self, (void *)archive, (void **)&local.cursor, (void *)end) == 0)
        return 0;

    count = fn_800F27CC((void *)archive);
    aligned = ((u32)&((struct GroupList *)local.cursor)->entries[count] + 3) & ~3U;
    if ((s32)(aligned - end) > 0) {
        result = 0;
    } else {
        local.cursor = aligned;
        *(u32 *)((u8 *)self + 0x14) = local.cursor;
        ((struct GroupList *)*(void **)((u8 *)self + 0x14))->count = fn_800F27CC((void *)archive);
        for (i = 0; i < (*(struct GroupList **)((u8 *)self + 0x14))->count; i++) {
            (*(struct GroupList **)((u8 *)self + 0x14))->entries[i].a = 0;
            (*(struct GroupList **)((u8 *)self + 0x14))->entries[i].b = 0;
        }
        result = 1;
    }
    if (result == 0)
        return 0;

    if (((s32 (*)(const void *, void *))fn_800F2814)(archive, &local.info) != 0) {
        ptr = local.cursor;
        count = local.info.counts[0];
        aligned = (count * 0x1F4 + ptr + 3) & ~3U;
        if ((s32)(aligned - end) > 0) {
            result = 0;
        } else {
            if (ptr == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325AA4, 0x3B, lbl_80325A78);
            created = CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl((u8 *)self + 0x78, (void *)ptr, count * 0x1F4, 0x1F4);
            if (created != (u32)count)
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x20C, base + 0x174);
            local.cursor = aligned;
            result = 1;
        }
        if (result == 0)
            return 0;

        register ptr = local.cursor;
        count = local.info.counts[2];
        aligned = (count * 0x614 + ptr + 3) & ~3U;
        if ((s32)(aligned - end) > 0) {
            result = 0;
        } else {
            if (ptr == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325A1C, 0x3B, lbl_803259F0);
            created = CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl((u8 *)self + 0x88, (void *)ptr, count * 0x614, 0x614);
            if (created != count)
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x24C, base + 0x174);
            local.cursor = aligned;
            result = 1;
        }
        if (!result)
            return 0;

        ptr = local.cursor;
        count = local.info.counts[5];
        aligned = (count * 0x1B4 + ptr + 3) & ~3U;
        if ((s32)(aligned - end) > 0) {
            result = 0;
        } else {
            if (ptr == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325A60, 0x3B, lbl_80325A34);
            created = CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl((u8 *)self + 0x98, (void *)ptr, count * 0x1B4, 0x1B4);
            if (created != (u32)count)
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x22C, base + 0x174);
            local.cursor = aligned;
            result = 1;
        }
        if (result == 0)
            return 0;

        ptr = local.cursor;
        count = local.info.counts[1];
        aligned = (count * 0xD4 + ptr + 3) & ~3U;
        if ((s32)(aligned - end) > 0) {
            result = 0;
        } else {
            created = fn_800EE428((u8 *)self + 0xC4, (void *)ptr, count * 0xD4);
            if (created != (u32)count)
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x26C, base + 0x1A4);
            local.cursor = aligned;
            result = 1;
        }
        if (result == 0)
            return 0;
    }

    if (local.cursor - (u32)buffer != (u32)GetRequiredMemSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(self, (void *)archive))
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x163, base + 0x1D4);
    *(void **)((u8 *)self + 0x10) = (void *)archive;
    *(u32 *)((u8 *)self + 0xD0) = (u32)buffer;
    *(u32 *)((u8 *)self + 0xD4) = size;
    return 1;
}
#pragma pop
extern "C" void __ct__Q36nw4hbm3snd11SoundPlayerFv(void *);
extern "C" void SetPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFi(void *, s32);
extern "C" void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi(void *, s32);
extern "C" void *fn_800F8310(void *);
extern "C" void fn_800F83C8(void *);
extern "C" void detail_AppendPlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10PlayerHeap(void *, void *);
extern "C" unsigned char lbl_803257A0[];
#pragma use_lmw_stmw off
extern "C" s32 SetupSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePPvPv(void *self, void *archive, void **pBuf, void *end) {
    struct PlayerInfo { s32 count; s32 size; };
    s32 num = ((s32 (*)(void *))fn_800F27C4)(archive);
    u8 *base = *(u8 **)pBuf;
    u32 aligned = (((u32)base + (u32)(num * 0x48)) + 3) & ~3U;
    if ((s32)(aligned - (u32)end) > 0) {
        return 0;
    }
    *pBuf = (void *)aligned;
    *(u8 **)((u8 *)self + 0x74) = base;
    *(s32 *)((u8 *)self + 0x70) = num;
    {
        void *vtable = (void *)lbl_803257A0;
        u32 zero = 0;
        u8 *player = base;
        u32 i = 0;
        for (; i < (u32)num; i++, player += 0x48) {
            void *curPlayer = player;
            if (player != 0) {
                curPlayer = ((void *(*)(void *))__ct__Q36nw4hbm3snd11SoundPlayerFv)(player);
            }
            {
                struct PlayerInfo info;
                if (((s32 (*)(void *, u32, void *))fn_800F280C)(archive, i, &info) != 0) {
                    ((void (*)(void *, s32))SetPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFi)(curPlayer, info.count);
                    ((void (*)(void *, s32))detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi)(curPlayer, info.count);
                    if (info.size != 0) {
                        s32 j = 0;
                        for (; j < info.count; j++) {
                            u8 *heap = *(u8 **)pBuf;
                            u32 next = ((u32)heap + (u32)info.size + 0x3F) & ~3U;
                            u32 sz;
                            if ((s32)(next - (u32)end) > 0) {
                                return 0;
                            }
                            *(u8 **)pBuf = (u8 *)next;
                            sz = (u32)info.size;
                            if (heap != 0) {
                                ((void *(*)(void *))fn_800F8310)(heap);
                                *(void **)heap = vtable;
                                *(u32 *)(heap + 0x2C) = zero;
                                *(u32 *)(heap + 0x30) = zero;
                                *(u32 *)(heap + 0x34) = zero;
                                *(u32 *)(heap + 0x38) = zero;
                                if (((s32 (*)(void *, void *, u32))fn_800F83C8)(heap, heap + 0x3C, sz) == 0) {
                                    heap = 0;
                                }
                            }
                            if (heap == 0) {
                                return 0;
                            }
                            ((void (*)(void *, void *))detail_AppendPlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10PlayerHeap)(curPlayer, heap);
                        }
                    }
                }
            }
        }
    }
    return 1;
}
extern "C" void Update__Q36nw4hbm3snd18SoundArchivePlayerFv(void* arg0) {
    extern void* GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv(void);
    extern void OSLockMutex(void*);
    extern void OSUnlockMutex(void*);
    extern void Update__Q36nw4hbm3snd11SoundPlayerFv(void*);
    extern void* fn_8002F53C(void*, void (*)(void*), void* (*)(void*, int), s32, s32);
    extern void* fn_8002F634(void*, void* (*)(void*, int), s32, s32);
    extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*, void**);
    extern void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);
    extern void fn_800F4F04(void*);
    extern void fn_800F4F7C(void*);
    extern void fn_800F4FF4(void*);
    extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F24(void*, int);
    extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F9C(void*, int);
    extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F5014(void*, int);
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    extern const char lbl_80324E88[];
    extern const char lbl_803250C8[];
    extern const char lbl_803259E4[];
    extern const char lbl_803259C0[];
    extern const char lbl_80324314[];
    extern const char lbl_803242F0[];
    extern const char lbl_803259B4[];
    extern const char lbl_80325990[];
    extern const char lbl_80324344[];
    extern const char lbl_80324320[];
    extern const char lbl_80325924[];
    extern const char lbl_80325900[];
    extern const char lbl_803258C4[];
    extern const char lbl_803258A0[];
    extern const char lbl_803258F4[];
    extern const char lbl_803258D0[];
    extern const char lbl_80325894[];
    extern const char lbl_80325870[];
    extern const char lbl_80325864[];
    extern const char lbl_80325840[];
    extern const char lbl_80325804[];
    extern const char lbl_803257E0[];
    extern const char lbl_80325834[];
    extern const char lbl_80325810[];
    extern const char lbl_803257D4[];
    extern const char lbl_803257B0[];
    u8* self = (u8*)arg0;
    void *it_34, *it_30, *it_2C, *it_28, *it_24, *it_20, *it_1C, *it_18, *it_14, *it_10, *it_C, *it_8;
    u8 arrA[0x600];
    u8 arrB[0x600];
    u8 arrC[0x600];
    void* mutex = (u8*)GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv() + 0x2320;
    OSLockMutex(mutex);
    u32 index = 0;
    s32 offset = 0;
    while (index < *(u32*)(self + 0x70)) {
        if (index >= *(u32*)(self + 0x70)) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x2B2, lbl_803250C8, index, 0);
        }
        Update__Q36nw4hbm3snd11SoundPlayerFv((void*)(*(s32*)(self + 0x74) + offset));
        offset += 0x48;
        index += 1;
    }
    fn_8002F53C(arrA, fn_800F4F04, __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F24, 0xC, 0x80);
    while (*(s32*)(self + 0x7C) != 0) {
        if (*(s32*)(self + 0x7C) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803259E4, 0x1F1, lbl_803259C0);
        }
        {
            void* node = *(void**)(self + 0x80);
            if (node == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324314, 0x23D, lbl_803242F0);
            }
            u8* elt = (u8*)node - 0xB8;
            if (elt == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_803259B4, 0x193, lbl_80325990);
            }
            it_28 = *(void**)(self + 0x80);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(self + 0x7C, (void**)&it_28);
            s32 prio = *(u8*)(elt + 0x74) + *(s32*)(elt + 0x40);
            if (prio > 0x7F) {
                prio = 0x7F;
            } else {
                prio = prio & ~(prio >> 31);
            }
            u8* bucket = arrA + prio * 0xC;
            it_2C = (void*)(bucket + 4);
            if (elt == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
            }
            Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(bucket, (void**)&it_2C, elt + 0xB8);
        }
    }
    {
        u8* entry = arrA;
        int k = 0;
        do {
            if (*(void**)entry != 0) {
                void* temp;
                do {
                    temp = *(void**)entry;
                    if (temp != 0) {
                        if (temp == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803259E4, 0x1F1, lbl_803259C0);
                        }
                        void* next2 = *(void**)(entry + 4);
                        if (next2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324314, 0x23D, lbl_803242F0);
                        }
                        u8* elt2 = (u8*)next2 - 0xB8;
                        if (elt2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803259B4, 0x193, lbl_80325990);
                        }
                        it_30 = *(void**)(entry + 4);
                        Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(entry, (void**)&it_30);
                        if (elt2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
                        }
                        it_34 = (void*)(self + 0x80);
                        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(self + 0x7C, (void**)&it_34, elt2 + 0xB8);
                    }
                    temp = *(void**)entry;
                } while (temp != 0);
            }
            k += 1;
            entry += 0xC;
        } while (k < 0x80);
    }
    fn_8002F634(arrA, __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F24, 0xC, 0x80);
    fn_8002F53C(arrB, fn_800F4F7C, __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F9C, 0xC, 0x80);
    while (*(s32*)(self + 0x8C) != 0) {
        if (*(s32*)(self + 0x8C) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325924, 0x1F1, lbl_80325900);
        }
        {
            void* node = *(void**)(self + 0x90);
            if (node == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258C4, 0x23D, lbl_803258A0);
            }
            u8* elt = (u8*)node - 0xB8;
            if (elt == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258F4, 0x193, lbl_803258D0);
            }
            it_18 = *(void**)(self + 0x90);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(self + 0x8C, (void**)&it_18);
            s32 prio = *(u8*)(elt + 0x74) + *(s32*)(elt + 0x40);
            if (prio > 0x7F) {
                prio = 0x7F;
            } else {
                prio = prio & ~(prio >> 31);
            }
            u8* bucket = arrB + prio * 0xC;
            it_1C = (void*)(bucket + 4);
            if (elt == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
            }
            Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(bucket, (void**)&it_1C, elt + 0xB8);
        }
    }
    {
        u8* entry = arrB;
        int k = 0;
        do {
            if (*(void**)entry != 0) {
                void* temp;
                do {
                    temp = *(void**)entry;
                    if (temp != 0) {
                        if (temp == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325924, 0x1F1, lbl_80325900);
                        }
                        void* next2 = *(void**)(entry + 4);
                        if (next2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258C4, 0x23D, lbl_803258A0);
                        }
                        u8* elt2 = (u8*)next2 - 0xB8;
                        if (elt2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258F4, 0x193, lbl_803258D0);
                        }
                        it_20 = *(void**)(entry + 4);
                        Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(entry, (void**)&it_20);
                        if (elt2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
                        }
                        it_24 = (void*)(self + 0x90);
                        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(self + 0x8C, (void**)&it_24, elt2 + 0xB8);
                    }
                    temp = *(void**)entry;
                } while (temp != 0);
            }
            k += 1;
            entry += 0xC;
        } while (k < 0x80);
    }
    fn_8002F634(arrB, __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F9C, 0xC, 0x80);
    fn_8002F53C(arrC, fn_800F4FF4, __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F5014, 0xC, 0x80);
    while (*(s32*)(self + 0x9C) != 0) {
        if (*(s32*)(self + 0x9C) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325864, 0x1F1, lbl_80325840);
        }
        {
            void* node = *(void**)(self + 0xA0);
            if (node == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325804, 0x23D, lbl_803257E0);
            }
            u8* elt = (u8*)node - 0xB8;
            if (elt == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325834, 0x193, lbl_80325810);
            }
            it_8 = *(void**)(self + 0xA0);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(self + 0x9C, (void**)&it_8);
            s32 prio = *(u8*)(elt + 0x74) + *(s32*)(elt + 0x40);
            if (prio > 0x7F) {
                prio = 0x7F;
            } else {
                prio = prio & ~(prio >> 31);
            }
            u8* bucket = arrC + prio * 0xC;
            it_C = (void*)(bucket + 4);
            if (elt == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_803257D4, 0x233, lbl_803257B0);
            }
            Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(bucket, (void**)&it_C, elt + 0xB8);
        }
    }
    {
        u8* entry = arrC;
        int k = 0;
        do {
            if (*(void**)entry != 0) {
                void* temp;
                do {
                    temp = *(void**)entry;
                    if (temp != 0) {
                        if (temp == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325864, 0x1F1, lbl_80325840);
                        }
                        void* next2 = *(void**)(entry + 4);
                        if (next2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325804, 0x23D, lbl_803257E0);
                        }
                        u8* elt2 = (u8*)next2 - 0xB8;
                        if (elt2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325834, 0x193, lbl_80325810);
                        }
                        it_10 = *(void**)(entry + 4);
                        Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(entry, (void**)&it_10);
                        if (elt2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803257D4, 0x233, lbl_803257B0);
                        }
                        it_14 = (void*)(self + 0xA0);
                        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(self + 0x9C, (void**)&it_14, elt2 + 0xB8);
                    }
                    temp = *(void**)entry;
                } while (temp != 0);
            }
            k += 1;
            entry += 0xC;
        } while (k < 0x80);
    }
    fn_8002F634(arrC, __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F5014, 0xC, 0x80);
    OSUnlockMutex(mutex);
    return;
}

extern "C" s32 GetSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFUl(void *arg0, u32 arg1) {
    /* Returns the sound player at the given index, panicking if out of bounds. */
    struct SoundArchivePlayer {
        u8 pad[0x70];
        u32 playerCount;
        void *players;
    };
    SoundArchivePlayer *self = (SoundArchivePlayer *)arg0;
    if (arg1 >= self->playerCount) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x2B2, lbl_803250C8, arg1, 0, self->playerCount);
    }
    return (s32)((u8 *)self->players + arg1 * 0x48);
}

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 detail_GetFileAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl(void *self, u32 fileId) {
    u32 filePos[2];
    u32 wavePos[4];
    u32 fileInfo[4];
    /* Resolve the memory/file address for a sound archive file id. */
    u8 *player = (u8 *)self;
    s32 address = ((DummySoundArchiveLookup2 *)*(void **)(player + 0x10))->f1();
    if (address != 0)
        return address;

    void *altSource = *(void **)(player + 0x6C);
    if (altSource != 0) {
        address = ((DummySoundArchiveLookup2 *)altSource)->f0(fileId);
        if (address != 0)
            return address;
    }

    typedef s32 (*ReadFileInfoFn)(void *, u32, void *);
    typedef s32 (*ReadFilePosFn)(void *, u32, u32, void *);
    typedef s32 (*ReadGroupItemInfoFn)(void *, u32, u32, void *);
    if (((ReadFileInfoFn)fn_800F2834)(*(void **)(player + 0x10), fileId, fileInfo) == 0)
        return 0;

    u32 groupBase;
    u32 index = 0;
    while (index < fileInfo[3]) {
        if (((ReadFilePosFn)fn_800F283C)(*(void **)(player + 0x10), fileId, index, filePos) != 0) {
            u32 groupIndex = filePos[0];
            u32 *waveTable = *(u32 **)(player + 0x14);
            if (waveTable == 0) {
                if (waveTable == 0)
                    Warning__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x333, lbl_80325158);
                groupBase = 0;
            } else if (groupIndex >= waveTable[0]) {
                groupBase = 0;
            } else {
                groupBase = *(u32 *)((u8 *)waveTable + groupIndex * 8 + 4);
            }
            if (groupBase != 0 &&
                ((ReadGroupItemInfoFn)fn_800F282C)(*(void **)(player + 0x10), filePos[0], filePos[1], wavePos) != 0)
                return groupBase + wavePos[1];
        }
        index++;
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 detail_GetFileWaveDataAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl_800F6490(void *self, u32 fileId) {
    u32 filePos[2];
    u32 wavePos[4];
    u32 fileInfo[4];
    /* Resolve the wave-data address for a sound archive file id: try archive
       lookup (vtable f2) and optional alt source (f1) at +0x6C, read file info/
       positions, map group index through wave table at +0x14 (warn on missing
       table, lbl_80324E88/snd_SoundArchivePlayer.cpp:0x366 with
       lbl_803251B0 "Failed to SoundArchivePlayer::GetGroupWaveDataAddress..."),
       return group base (+8) + wave item offset (wavePos[3]). */
    u8 *obj = (u8 *)self;
    s32 result = ((DummySoundArchiveLookup *)*(void **)(obj + 0x10))->f2();
    if (result != 0)
        return result;

    void *source = *(void **)(obj + 0x6C);
    if (source != 0) {
        result = ((DummySoundArchiveLookup *)source)->f1(fileId);
        if (result != 0)
            return result;
    }

    typedef s32 (*ReadFileInfoFn)(void *, u32, void *);
    typedef s32 (*ReadFilePosFn)(void *, u32, u32, void *);
    typedef s32 (*ReadGroupItemInfoFn)(void *, u32, u32, void *);
    if (((ReadFileInfoFn)fn_800F2834)(*(void **)(obj + 0x10), fileId, fileInfo) == 0)
        return 0;

    u32 groupBase;
    u32 index = 0;
    while (index < fileInfo[3]) {
        if (((ReadFilePosFn)fn_800F283C)(*(void **)(obj + 0x10), fileId, index, filePos) != 0) {
            u32 groupIndex = filePos[0];
            u32 *waveTable = *(u32 **)(obj + 0x14);
            if (waveTable == 0) {
                if (waveTable == 0)
                    Warning__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x366, lbl_803251B0);
                groupBase = 0;
            } else if (groupIndex >= waveTable[0]) {
                groupBase = 0;
            } else {
                groupBase = *(u32 *)((u8 *)waveTable + groupIndex * 8 + 8);
            }
            if (groupBase != 0 &&
                ((ReadGroupItemInfoFn)fn_800F282C)(*(void **)(obj + 0x10), filePos[0], filePos[1], wavePos) != 0)
                return groupBase + wavePos[3];
        }
        index++;
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop

extern "C" void DetachSound__Q34nw4hbm3snd11SoundHandleFv(void **);
extern "C" void detail_AttachSound__Q36nw4hbm3snd11SoundHandleFPQ46nw4hbm3snd6detail10BasicSound(void **, void *);
extern "C" void fn_800E9BA4(void *, s32);
extern "C" void *fn_800F8CA4(s32, s32, s32, s32, s32, s32, void *);
extern "C" void *fn_800F9200(s32, s32, s32, s32, s32, s32, void *);
extern "C" void *fn_800F975C(s32, s32, s32, s32, s32, s32, void *);
extern "C" const char lbl_80325870[];
extern "C" const char lbl_80325894[];
extern "C" const char lbl_803258A0[];
extern "C" const char lbl_803258C4[];
extern "C" const char lbl_803258D0[];
extern "C" const char lbl_803258F4[];
extern "C" const char lbl_80325900[];
extern "C" const char lbl_80325924[];
extern "C" const char lbl_80325DC0[];
extern "C" const char lbl_80325DE4[];
extern "C" const char lbl_80325DF0[];
extern "C" const char lbl_80325E14[];
extern "C" const char lbl_80325E20[];
extern "C" const char lbl_80325E44[];
extern "C" const char lbl_8032606C[];
extern "C" const char lbl_80326094[];
extern "C" const char lbl_803260AC[];
extern "C" const char lbl_803260F0[];
extern "C" u8 lbl_80326264[];
extern "C" u8 lbl_80326288[];
extern "C" u8 lbl_80326294[];
extern "C" u8 lbl_803262B8[];
extern "C" void *AllocImpl__Q44nw4r3snd6detail8PoolImplFv(void *);
extern "C" void fn_800E9B74(void *, void *, s32, void *, s32);
extern "C" void fn_800EC1A4(void *);
extern "C" void *fn_800FDA20(void *, void *);
extern "C" void InsertSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListImpl8Iterator(void *, void **, void *);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void *, s32 *);
extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32);
extern "C" void OSLockMutex(void *);
extern "C" void OSUnlockMutex(void *);
extern "C" s32 PrepareSeqImpl__Q36nw4hbm3snd18SoundArchivePlayerFPQ46nw4hbm3snd6detail8SeqSoundPCQ46nw4hbm3snd12SoundArchive9SoundInfoPCQ46nw4hbm3snd12SoundArchive12SeqSoundInfoi(void *, void *, void *, void *, s32);
extern "C" s32 Prepare__Q46nw4hbm3snd6detail9StrmSoundFPQ46nw4hbm3snd6detail14StrmBufferPoolQ56nw4hbm3snd6detail10StrmPlayer15StartOffsetTypeliPQ56nw4hbm3snd6detail10StrmPlayer12StrmCallbackUl(void *, void *, s32, s32, s32, void *, u32);
extern "C" s32 Prepare__Q46nw4hbm3snd6detail9WaveSoundFPCvliPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl(void *, void *, s32, void *, u32);
extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail9WaveSoundFi_800FFC9C(void *, s32);
extern "C" s32 detail_GetFileAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl(void *, u32);
extern "C" f32 lbl_805610A8;
extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void **);
#pragma dont_inline on
extern "C" s32 fn_800F65F0(void *arg0, void **arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6, s32 arg7) {
    register const char *fileName = lbl_80324E88;

    union {
        struct {
            u8 strmInfo[0x30];
            u8 fileBuffer[0x200];
        } main;
        struct {
            u8 pad0[8];
            u8 waveInfo[8];
            u32 seqInfo[2];
            u8 pad1[8];
            u32 soundInfo[3];
        } local;
    } stack;
    register s32 startOffset;
    void *stream;
    void *sound;
    register s32 playerIndex;
    register s32 startPosition;
    register s32 soundCount;
    register u32 soundIndex;
    register s32 loop;
    register s32 result;
    register s32 soundType;
    register s32 priority;

    if (!arg1) {
        Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x39F, fileName + 0x480);
    }
    if (*(void **)((u8 *)arg0 + 0x10) == 0) {
        result = 0;
    } else {
        result = fn_800F273C(*(void **)((u8 *)arg0 + 0x10));
    }
    if (!result) {
        return 7;
    }
    if (*arg1 != 0) {
        DetachSound__Q34nw4r3snd11SoundHandleFv(arg1);
    }
    if (((s32 (*)(void *, u32, void *))fn_800F27EC)(*(void **)((u8 *)arg0 + 0x10), arg2, stack.local.soundInfo) == 0) {
        return 3;
    }
    soundIndex = stack.local.soundInfo[1];
    soundCount = stack.local.soundInfo[2];
    startPosition = 1;
    playerIndex = 0;
    startOffset = 1;
    if (arg6 != 0) {
        register u32 value = *(u32 *)((u8 *)arg6 + 8);
        if (value != -1U) {
            soundIndex = value;
        }
        result = *(s32 *)((u8 *)arg6 + 0xC);
        if (result >= 0) {
            soundCount = result;
        }
        startPosition = *(u32 *)((u8 *)arg6 + 0);
        playerIndex = *(s32 *)((u8 *)arg6 + 4);
        startOffset = *(s32 *)((u8 *)arg6 + 0x10);
    }
    loop = soundCount;
    if (arg5 != 0) {
        loop = soundCount - 1;
    }
    if (soundIndex >= *(u32 *)((u8 *)arg0 + 0x70)) {
        Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x2B2, fileName + 0x240, soundIndex, 0);
    }
    sound = (u8 *)*(void **)((u8 *)arg0 + 0x74) + soundIndex * 0x48;
    soundType = ((s32 (*)(void *, u32))fn_800F27E4)(*(void **)((u8 *)arg0 + 0x10), arg2);
    switch (soundType) {
    case 1:
        if (((s32 (*)(void *, u32, void *))fn_800F27F4)(*(void **)((u8 *)arg0 + 0x10), arg2, stack.local.seqInfo) == 0) {
            return 3;
        }
        sound = fn_800F8CA4((s32)sound, soundCount, loop, arg3, arg4, arg2, (u8 *)arg0 + 0x78);
        if (sound == 0) {
            return 1;
        }
        fn_800E9BA4(sound, arg2);
        register result = PrepareSeqImpl__Q36nw4hbm3snd18SoundArchivePlayerFPQ46nw4hbm3snd6detail8SeqSoundPCQ46nw4hbm3snd12SoundArchive9SoundInfoPCQ46nw4hbm3snd12SoundArchive12SeqSoundInfoi(arg0, sound, stack.local.soundInfo, stack.local.seqInfo, startOffset);
        if (result != 0) {
            ((DummyStrmLoadStream *)sound)->f10();
        } else {
            goto attach;
        }
        return result;
    case 2:
        if (((s32 (*)(void *, u32, void *))fn_800F27FC)(*(void **)((u8 *)arg0 + 0x10), arg2, stack.main.strmInfo) == 0) {
            return 3;
        }
        stream = detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(*(void **)((u8 *)arg0 + 0x10), stack.local.soundInfo[0], stack.main.fileBuffer, 0x200);
        if (stream == 0) {
            return 6;
        }
        ((DummyStrmLoadStream *)stream)->f4();
        sound = fn_800F9200((s32)sound, soundCount, loop, arg3, arg4, arg2, (u8 *)arg0 + 0x88);
        if (sound == 0) {
            return 1;
        }
        fn_800E9BA4(sound, arg2);
        s32 startFlag = 0;
        if (startPosition == 1) {
            startFlag = 1;
        }
        if (Prepare__Q46nw4hbm3snd6detail9StrmSoundFPQ46nw4hbm3snd6detail14StrmBufferPoolQ56nw4hbm3snd6detail10StrmPlayer15StartOffsetTypeliPQ56nw4hbm3snd6detail10StrmPlayer12StrmCallbackUl(sound, (u8 *)arg0 + 0xA8, startFlag, playerIndex, startOffset, (u8 *)arg0 + 0x48, stack.local.soundInfo[0]) == 0) {
            result = 0xFF;
        } else {
            ((DummyStrmLoadStream *)sound)->f13((f32)*(s32 *)(stack.main.strmInfo + 0x2C) / lbl_805610A8);
            result = 0;
        }
        if (result == 0) {
            goto attach;
        }
        ((DummyStrmLoadStream *)sound)->f10();
        return result;
    case 3:
        if (((s32 (*)(void *, u32, void *))fn_800F2804)(*(void **)((u8 *)arg0 + 0x10), arg2, stack.local.waveInfo) == 0) {
            return 3;
        }
        sound = fn_800F975C((s32)sound, soundCount, loop, arg3, arg4, arg2, (u8 *)arg0 + 0x98);
        if (!sound) {
            return 1;
        }
        fn_800E9BA4(sound, arg2);
        if ((void *)stack.local.waveInfo == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x4ED, fileName + 0x4AC);
        }
        void *fileAddress = (void *)detail_GetFileAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl(arg0, stack.local.soundInfo[0]);
        if (fileAddress == 0) {
            result = 4;
        } else if (((s32 (*)(void *, void *, void *, s32, void *, u32))Prepare__Q46nw4hbm3snd6detail9WaveSoundFPCvliPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl)(sound, fileAddress, (void *)(u32)*(u32 *)stack.local.waveInfo, startOffset, (u8 *)arg0 + 0x40, stack.local.soundInfo[0]) == 0) {
            result = 0xFF;
        } else {
            ((DummyStrmLoadStream *)sound)->f13((f32)*(s32 *)(stack.main.strmInfo + 0x2C) / lbl_805610A8);
            priority = *(s32 *)(stack.local.waveInfo + 4);
            SetChannelPriority__Q46nw4hbm3snd6detail9WaveSoundFi_800FFC9C(sound, priority);
            result = 0;
        }
        if (result == 0) {
            goto attach;
        }
        ((DummyStrmLoadStream *)sound)->f10();
        return result;
    default:
        return 3;
    }

attach:
    detail_AttachSound__Q36nw4hbm3snd11SoundHandleFPQ46nw4hbm3snd6detail10BasicSound(arg1, sound);
    return 0;
}

extern "C" u32 fn_800EC56C(void **);
extern "C" s32 Setup__Q46nw4hbm3snd6detail8SeqSoundFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback(void *, void *, unsigned long, int, void *);
extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail8SeqSoundFi(void *, int);
extern "C" void Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCvl(void *, const void *, s32);
extern "C" void Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCQ56nw4hbm3snd6detail8SeqSound15SeqLoadCallbackUl(void *, const void *, unsigned long);
extern "C" f64 lbl_805610B0;
extern "C" const char lbl_80325334[];
#pragma use_lmw_stmw off
extern "C" s32 PrepareSeqImpl__Q36nw4hbm3snd18SoundArchivePlayerFPQ46nw4hbm3snd6detail8SeqSoundPCQ46nw4hbm3snd12SoundArchive9SoundInfoPCQ46nw4hbm3snd12SoundArchive12SeqSoundInfoi(void *player, void *seqSound, void *soundInfo, void *seqSoundInfo, s32 offset) {
    struct StreamProxy {
        virtual void slot0() = 0;
        virtual void slot1() = 0;
        virtual void close() = 0;
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
        virtual u32 getSize() = 0;
    };
    struct SeqSoundProxy {
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
        virtual void setRate(f32) = 0;
    };
    union {
        u32 words[2];
        f64 value;
    } conversion;
    u8 streamBuffer[0x200];
    u8 reader[8];
    void *fileData;
    void *stream;
    void *memory;
    u32 fileSize;
    s32 status;
    u32 volume;
    f32 rate;
    void *base;

    if (seqSoundInfo == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x469, lbl_80325334);

    fileData = (void *)detail_GetFileAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl(player, *(u32 *)soundInfo);
    if (fileData == 0) {
        memory = *(void **)((u8 *)seqSound + 4);
        if (memory == 0)
            return 4;

        stream = detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(*(void **)((u8 *)player + 0x10), *(u32 *)soundInfo, streamBuffer, 0x200);
        OSLockMutex((u8 *)memory + 4);
        fileSize = fn_800EC56C((void **)((u8 *)memory + 0x1C));
        OSUnlockMutex((u8 *)memory + 4);

        if (fileSize < ((StreamProxy *)stream)->getSize()) {
            if (stream != 0)
                ((StreamProxy *)stream)->close();
            return 5;
        }
        if (stream != 0)
            ((StreamProxy *)stream)->close();
    }

    status = Setup__Q46nw4hbm3snd6detail8SeqSoundFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback(
        seqSound, *(void **)((u8 *)player + 0x68), *(u32 *)((u8 *)seqSoundInfo + 8), offset, (u8 *)player + 0x38);
    if (status != 0) {
        if (status == 1)
            return 8;
        return 0xFF;
    }

    volume = *(u32 *)((u8 *)soundInfo + 0xC);
    conversion.words[0] = 0x43300000;
    conversion.words[1] = volume ^ 0x80000000;
    rate = (f32)(conversion.value - lbl_805610B0);
    rate /= lbl_805610A8;
    ((SeqSoundProxy *)seqSound)->setRate(rate);
    SetChannelPriority__Q46nw4hbm3snd6detail8SeqSoundFi(seqSound, *(int *)((u8 *)seqSoundInfo + 0xC));

    if (fileData != 0) {
        __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(reader, fileData);
        base = GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(reader);
        Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCvl(seqSound, base, *(s32 *)seqSoundInfo);
    } else {
        Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCQ56nw4hbm3snd6detail8SeqSound15SeqLoadCallbackUl(seqSound, (const void *)((u8 *)player + 0x18), (unsigned long)seqSound);
    }
    return 0;
}
extern "C" void *LoadGroup__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatablePPvUl(void *, u32, void *, void **, u32);
#pragma push
#pragma use_lmw_stmw off
extern "C" BOOL fn_800F6C7C(void *arg0, u32 arg1, void *arg2, u32 arg3) {
    char *fileName = (char *)lbl_80324E88;
    void *waveDataAddress;
    u8 loader[0x220];
    u32 *table;
    if (*(void * volatile *)((u8 *)arg0 + 0x10) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(fileName+0, 0x518, fileName + 0x2A0);
    }
    if (arg3 & 0x1F) {
        Panic__Q26nw4hbm2dbFPCciPCce(fileName+0, 0x519, fileName + 0x4D4, arg3);
    }
    if ((*(void * volatile *)((u8 *)arg0 + 0x10) == 0 ? 0 : fn_800F273C(*(void * volatile *)((u8 *)arg0 + 0x10))) == 0) {
        return 0;
    }
    if (arg1 >= (u32)fn_800F27CC(*(void * volatile *)((u8 *)arg0 + 0x10))) {
        return 0;
    }
    table = *(u32 **)((u8 *)arg0 + 0x14);
    u32 loaded = 0;
    if (table == 0) {
        if (table == 0)
            Warning__Q26nw4hbm2dbFPCciPCce(fileName+0, 0x333, fileName + 0x2D0);
    } else if (arg1 >= table[0]) {
        loaded = 0;
    } else {
        loaded = *(u32 *)((u8 *)table + arg1 * 8 + 4);
    }
    if (loaded != 0) {
        return 1;
    }
    if (arg2 == 0) {
        return 0;
    }
    fn_800F41D0(loader, (s32)*(void * volatile *)((u8 *)arg0 + 0x10));
    arg3 = (u32)LoadGroup__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatablePPvUl(loader, arg1, arg2, &waveDataAddress, arg3);
    if (arg3 == 0) {
        fn_800F420C((s32)loader, -1);
        return 0;
    }
    table = *(u32 **)((u8 *)arg0 + 0x14);
    if (table == 0) {
        if (table == 0)
            Warning__Q26nw4hbm2dbFPCciPCce(fileName+0, 0x34D, fileName + 0x388);
    } else {
        if (arg1 >= table[0]) {
            Panic__Q26nw4hbm2dbFPCciPCce(fileName+0, 0x351, fileName + 0x3E0, arg1, 0);
        }
        table = *(u32 **)((u8 *)arg0 + 0x14);
        *(u32 *)((u8 *)table + arg1 * 8 + 4) = arg3;
    }
    arg3 = (u32)waveDataAddress;
    table = *(u32 **)((u8 *)arg0 + 0x14);
    if (table == 0) {
        if (table == 0)
            Warning__Q26nw4hbm2dbFPCciPCce(fileName+0, 0x380, fileName + 0x420);
    } else {
        if (arg1 >= table[0]) {
            Panic__Q26nw4hbm2dbFPCciPCce(fileName+0, 0x384, fileName + 0x3E0, arg1, 0);
        }
        table = *(u32 **)((u8 *)arg0 + 0x14);
        *(u32 *)((u8 *)table + arg1 * 8 + 8) = arg3;
    }
    fn_800F420C((s32)loader, -1);
    return 1;
}
#pragma pop
/* nw4r::snd::SoundArchivePlayer::InvalidateData(const void *start,
   const void *end) -- clears the loaded FILE DATA address of every sound group
   whose group data sits inside the address range [start, end] (inclusive), so
   those groups are read back from the archive the next time they play; used
   when a sound memory pool is handed back.  The sibling clone at 0x800F6F18
   clears the group's wave-data address instead.  The table's count word sits
   one word before the first record, so walking it in 8-byte steps from its base
   reaches each record four bytes later. */
extern "C" void InvalidateData__Q34nw4r3snd18SoundArchivePlayerFPCvPCv(void* self, u32 start, u32 end) {
    struct GroupLoadStatus { void* file_data_address; void* wave_data_address; };
    struct LoadStatusTable { u32 count; struct GroupLoadStatus entries[1]; };
    if (*(struct LoadStatusTable**)((u8*)self + 0x14) == 0) return;
    u32 offset;
    struct LoadStatusTable* table;
    u32 index;
    void* null_address;
    index = 0;
    offset = 0;
    null_address = 0;
    goto loop_check;
    do {
        struct GroupLoadStatus* entry = &((struct LoadStatusTable*)((u8*)table + offset))->entries[0];
        u32 value = (u32)entry->file_data_address;
        if (!(start > value) && !(value > end)) entry->file_data_address = null_address;
        offset += 8;
        ++index;
    loop_check:
        /* the table is read again every pass: the store above may alias it */
        table = *(struct LoadStatusTable**)((u8*)self + 0x14);
    } while (index < table->count);
}
/* nw4r::snd::SoundArchivePlayer::InvalidateData(const void *start,
   const void *end) -- variant that clears the loaded WAVE DATA address of every
   sound group whose wave data lies inside the address range [start, end]
   (inclusive), so those groups are read back from the archive the next time
   they play; used when a sound memory pool is handed back.  The sibling clone
   at 0x800F6EC4 clears the group's file-data address instead.  The table's
   count word sits one word before the first record, so walking it in 8-byte
   steps from its base reaches each record four bytes later. */
extern "C" void InvalidateData__Q34nw4r3snd18SoundArchivePlayerFPCvPCv_800F6F18(void* self, u32 start, u32 end) {
    struct GroupLoadStatus { void* file_data_address; void* wave_data_address; };
    struct LoadStatusTable { u32 count; struct GroupLoadStatus entries[1]; };
    if (*(struct LoadStatusTable**)((u8*)self + 0x14) == 0) return;
    u32 offset;
    struct LoadStatusTable* table;
    u32 index;
    void* null_address;
    index = 0;
    offset = 0;
    null_address = 0;
    goto loop_check;
    do {
        struct GroupLoadStatus* entry = &((struct LoadStatusTable*)((u8*)table + offset))->entries[0];
        u32 value = (u32)entry->wave_data_address;
        if (!(start > value) && !(value > end)) entry->wave_data_address = null_address;
        offset += 8;
        ++index;
    loop_check:
        /* the table is read again every pass: the store above may alias it */
        table = *(struct LoadStatusTable**)((u8*)self + 0x14);
    } while (index < table->count);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" const char lbl_80325698[];
extern "C" s32 fn_800F6F6C(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 sp18, sp8;
    void *freader = *(void**)((u8*)arg0 + 4);
    s32 v = *(s32*)((u8*)freader + 0x10);
    s32 has;
    if (v == 0) has = 0;
    else has = fn_800F273C(*(void**)((u8*)freader + 0x10));
    if (has == 0) return 1;
    return 3;
}
#pragma pop

extern "C" void *fn_800FDE60(void);
extern "C" void *Alloc__Q46nw4hbm3snd6detail11TaskManagerFv(void *manager);
extern "C" void AppendTask__Q46nw4hbm3snd6detail11TaskManagerFPQ46nw4hbm3snd6detail4TaskQ56nw4hbm3snd6detail11TaskManager12TaskPriority(void *manager, void *task, s32 priority);
extern "C" u32 fn_800FE0DC(void *manager);
extern "C" void *fn_800FE648(void);
extern "C" void fn_800FE804(void *arg0);
extern "C" char lbl_80325684[];
extern "C" void CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl(unsigned long);
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *);
extern "C" const char lbl_80325640[];
extern "C" const char lbl_80324E88[];
extern "C" const char lbl_80324EA4[];
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void detail_SortPriorityList__Q36nw4hbm3snd11SoundPlayerFv(void *);
extern "C" void Update__Q36nw4hbm3snd11SoundPlayerFv(void *);
extern "C" void StopAllSound__Q36nw4hbm3snd11SoundPlayerFi(void *, s32);
extern "C" void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(void *, void *);
#pragma push
#pragma small_data off
  extern u8 lbl_803262E8[];
  extern u8 lbl_803262C4[];
  extern u8 lbl_803262B8[];
  extern u8 lbl_80326294[];
  extern u8 lbl_80326288[];
  extern u8 lbl_80326264[];
#pragma pop
extern "C" void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void *);
extern "C" void fn_800F7110(void *self, unsigned long taskId) {
    /* Cancel a pending sound task by id through the global sound TaskManager. */
    unsigned long id = taskId;
    void *taskManager = ((void * (*)(void))fn_800FDE60)();
    ((void (*)(void *, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(taskManager, id);
}

/* Resolve bank and wave data for a sequence note-on and create the sound; returns the created sound or NULL. */
void *nw4hbm::snd::SoundArchivePlayer::SeqNoteOnCallback::NoteOn(
    nw4hbm::snd::detail::SeqPlayer *seqPlayer, int unused,
    const nw4hbm::snd::detail::NoteOnInfo &noteOnInfo) {
    struct Scratch {
        u8 bankInfo[8];
        u8 reader[16];
        u8 seqInfo[16];
    } scratch;

    void *fileReader =
        *(void **)(*(u8 **)((u8 *)this + 4) + 0x10);
    s32 hasReader;
    if (fileReader == 0) {
        hasReader = 0;
    } else {
        hasReader = fn_800F273C(fileReader);
    }
    if (hasReader == 0) {
        return 0;
    }

    void *soundArchive = *(void **)((u8 *)this + 4);
    if (*(s32 *)((u8 *)soundArchive + 0x10) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x2AC, lbl_80325110);
    }

    void *bankFileReader = *(void **)((u8 *)soundArchive + 0x10);
    u32 seqBankIndex = *(u32 *)((u8 *)seqPlayer + 4);
    if (((s32 (*)(void *, u32, void *))fn_800F27F4)(
            bankFileReader, seqBankIndex, scratch.seqInfo) == 0) {
        return 0;
    }

    if (((s32 (*)(void *, u32, void *))fn_800F281C)(
            bankFileReader, *(u32 *)(scratch.seqInfo + 4), scratch.bankInfo) == 0) {
        return 0;
    }

    s32 fileAddress =
        detail_GetFileAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl(
            *(void **)((u8 *)this + 4), *(u32 *)scratch.bankInfo);
    if (fileAddress == 0) {
        return 0;
    }

    ((void *(*)(void *, s32))fn_800E80B8)(scratch.reader, fileAddress);
    s32 waveAddress =
        detail_GetFileWaveDataAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl_800F6490(
            *(void **)((u8 *)this + 4), *(u32 *)scratch.bankInfo);
    if (waveAddress == 0) {
        ((int (*)(int, int))fn_800E80F0)((int)scratch.reader, -1);
        return 0;
    }
    if (waveAddress == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(
            (const char *)&lbl_805598D8, 0x2F, lbl_80325B88);
    }

    *(s32 *)(scratch.reader + 0xC) = waveAddress;
    void *sound =
        NoteOn__Q46nw4hbm3snd6detail4BankCFRCQ46nw4hbm3snd6detail10NoteOnInfo(
            scratch.reader, (const void *)&noteOnInfo);
    ((int (*)(int, int))fn_800E80F0)((int)scratch.reader, -1);
    return sound;
}

extern "C" s32 detail_GetFileWaveDataAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl_800F6490(void *, u32);
extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv_800FFECC(void *, const void *);
extern "C" s32 ReadWaveSoundInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail13WaveSoundInfoi(void *, void *, s32);
extern "C" s32 ReadWaveSoundNoteInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail17WaveSoundNoteInfoii(void *, void *, s32, s32);
extern "C" s32 ReadWaveParam__Q46nw4hbm3snd6detail13WsdFileReaderCFiPQ46nw4hbm3snd6detail8WaveDataPCv(void *, s32, void *, const void *);
extern "C" const char lbl_80325110[];
#pragma push
#pragma use_lmw_stmw off
s32 nw4hbm::snd::SoundArchivePlayer::WsdCallback::GetWaveSoundData(nw4hbm::snd::detail::WaveSoundInfo *info, nw4hbm::snd::detail::WaveSoundNoteInfo *noteInfo, nw4hbm::snd::detail::WaveData *waveData, const void *file, int index, int noteIndex, u32 waveIndex) const {
    struct BankReader { void *a; void *b; void *c; } reader;
    u32 waveAddress;
    if ((*(void **)(*(u8 **)((u8 *)this + 4) + 0x10) == 0 ? 0 : fn_800F273C(*(void **)(*(u8 **)((u8 *)this + 4) + 0x10))) == 0)
        return 0;
    if (*(u32 *)(*(u8 **)((u8 *)this + 4) + 0x10) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x2AC, lbl_80325110);
    waveAddress = detail_GetFileWaveDataAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl_800F6490(*(void **)((u8 *)this + 4), waveIndex);
    if (waveAddress == 0)
        return 0;
    __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv_800FFECC(&reader, file);
    if (ReadWaveSoundInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail13WaveSoundInfoi(&reader, info, index) == 0)
        return 0;
    if (ReadWaveSoundNoteInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail17WaveSoundNoteInfoii(&reader, noteInfo, index, noteIndex) == 0)
        return 0;
    return ReadWaveParam__Q46nw4hbm3snd6detail13WsdFileReaderCFiPQ46nw4hbm3snd6detail8WaveDataPCv(&reader, *(s32 *)noteInfo, waveData, (const void *)waveAddress);
}

extern "C" s32 fn_800F73E4(void *__restrict self, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register const char *base = lbl_80324E88;
    void *reader = *(void **)((u8 *)self + 4);
    void *fileInfo = *(void **)((u8 *)reader + 0x10);
    void *task;
    if (fileInfo == 0)
        return 0;
    if (fn_800F273C(fileInfo) == 0)
        return 1;
    task = Alloc__Q46nw4hbm3snd6detail11TaskManagerFv(fn_800FDE60());
    if (task == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x64C, base + 0x590);
    reader = *(void **)((u8 *)self + 4);
    if (*(volatile void **)((u8 *)reader + 0x10) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x2AC, base + 0x288);
    fileInfo = *(void **)((u8 *)reader + 0x10);
    if (fn_800FE0DC(fn_800FDE60()) < 0x28)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x650, base + 0x5B8);
    if (task != 0) {
        *(s32 *)((u8 *)task + 4) = 0;
        *(s32 *)((u8 *)task + 8) = 0;
        *(s32 *)((u8 *)task + 0xC) = arg3;
        *(void **)((u8 *)task + 0) = lbl_80325684;
        *(s32 *)((u8 *)task + 0x10) = 0;
        *(void **)((u8 *)task + 0x14) = fileInfo;
        *(s32 *)((u8 *)task + 0x18) = arg4;
        *(s32 *)((u8 *)task + 0x1C) = arg1;
        *(s32 *)((u8 *)task + 0x20) = arg2;
        *(void **)((u8 *)task + 0x24) = (u8 *)self + 8;
    }
    AppendTask__Q46nw4hbm3snd6detail11TaskManagerFPQ46nw4hbm3snd6detail4TaskQ56nw4hbm3snd6detail11TaskManager12TaskPriority(fn_800FDE60(), task, 1);
    fn_800FE804(fn_800FE648());
    return 3;
}

extern "C" s32 fn_800F7528(void *self, void *arg1, unsigned long arg2, long arg3, int arg4, unsigned long arg5, long arg6, bool arg7, __StrmLoadCommandRef &arg8, unsigned long arg9, unsigned long arg10, unsigned long arg11) {
    register const char *base = lbl_80324E88;
    register void *reader = *(void **)((u8 *)self + 4);
    void *fileInfo = *(void **)((u8 *)reader + 0x10);
    s32 result;
    if (fileInfo == 0)
        result = 0;
    else
        result = fn_800F273C(fileInfo);
    if (result == 0)
        return 1;
    reader = *(void **)((u8 *)self + 4);
    if (*(void **)((u8 *)reader + 0x10) == 0)
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x2AC, base + 0x288);
    reader = *(void **)((u8 *)reader + 0x10);
    void *task = Alloc__Q46nw4hbm3snd6detail11TaskManagerFv(fn_800FDE60());
    if (task == 0)
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x67B, base + 0x590);
    if (fn_800FE0DC(fn_800FDE60()) < 0x40)
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x67D, base + 0x628);
    if (task != 0) {
        task = __ct__Q46nw4hbm3snd18SoundArchivePlayer16StrmDataLoadTaskFPvUlliUllbRQ56nw4hbm3snd6detail10StrmPlayer11LoadCommandRCQ36nw4hbm3snd12SoundArchiveUlUlR7OSMutex(
            task, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
            arg8, *(const __StrmSoundArchiveRef *)reader,
            arg10, arg9, *(__StrmMutexRef *)((u8 *)self + 8));
    }
    AppendTask__Q46nw4hbm3snd6detail11TaskManagerFPQ46nw4hbm3snd6detail4TaskQ56nw4hbm3snd6detail11TaskManager12TaskPriority(fn_800FDE60(), task, 2);
    fn_800FE804(fn_800FE648());
    return 3;
}

#pragma pop

/* Cancel the nw4hbm sound task with the given id via the shared TaskManager. */
extern "C" void fn_800F768C(void *self, unsigned long taskId) {
    unsigned long savedTaskId = taskId;
    void *taskManager = ((void *(*)(void))fn_800FDE60)();
    ((void (*)(void *, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(taskManager, savedTaskId);
}

extern "C" s32 fn_800F76C0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" void* LoadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatable(void*, unsigned int, void*);
extern "C" void* __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(void*, void*);
extern "C" void* GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(void*);
/* Load a sequence file for the sound archive player: set up a file buffer and
 * publish it under the task mutex, load the file, then notify the completion
 * callback with the sequence's base address (or a null address on failure). */
extern "C" void Execute__Q46nw4hbm3snd18SoundArchivePlayer11SeqLoadTaskFv(void* task) {
    #define TASK_BUFFER_ID   0x10   /* file buffer currently published by the task */
    #define TASK_SETUP_ID    0x14   /* id used to initialise the file buffer */
    #define TASK_FILE_ID     0x18   /* file id passed to the loader */
    #define TASK_NOTIFY_ID   0x1C   /* file id passed to the callback */
    #define TASK_ALLOCATOR   0x20
    #define TASK_CALLBACK    0x24
    #define TASK_USER_ARG    0x28
    #define TASK_MUTEX       0x2C

    char fileBuffer[0x220];
    char seqReader[8];
    void* fileAddress;
    void* callback;
    void* seqBase;
    s32 fileId;

    fn_800F41D0(fileBuffer, *(s32*)((char*)task + TASK_SETUP_ID));
    {
        void* mutex = *(void**)((char*)task + TASK_MUTEX);
        OSLockMutex(mutex);
        *(void**)((char*)task + TASK_BUFFER_ID) = fileBuffer;
        OSUnlockMutex(mutex);
    }
    fileAddress = LoadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatable(fileBuffer, *(u32*)((char*)task + TASK_FILE_ID), *(void**)((char*)task + TASK_ALLOCATOR));
    {
        void* mutex = *(void**)((char*)task + TASK_MUTEX);
        OSLockMutex(mutex);
        *(void**)((char*)task + TASK_BUFFER_ID) = 0;
        OSUnlockMutex(mutex);
    }
    if (fileAddress == 0) {
        callback = *(void**)((char*)task + TASK_CALLBACK);
        if (callback) ((void (*)(s32, void*, s32, void*))callback)(0, 0, 0, *(void**)((char*)task + TASK_USER_ARG));
        fn_800F420C((s32)fileBuffer, -1);
        return;
    }
    __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(seqReader, fileAddress);
    seqBase = (void*)GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(seqReader);
    callback = *(void**)((char*)task + TASK_CALLBACK);
    fileId = *(s32*)((char*)task + TASK_NOTIFY_ID);
    if (callback) ((void (*)(s32, void*, s32, void*))callback)(1, seqBase, fileId, *(void**)((char*)task + TASK_USER_ARG));
    fn_800F420C((s32)fileBuffer, -1);

    #undef TASK_BUFFER_ID
    #undef TASK_SETUP_ID
    #undef TASK_FILE_ID
    #undef TASK_NOTIFY_ID
    #undef TASK_ALLOCATOR
    #undef TASK_CALLBACK
    #undef TASK_USER_ARG
    #undef TASK_MUTEX
}

extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer11SeqLoadTaskFv(void* self) {
    /* nw4hbm::snd::SoundArchivePlayer::SeqLoadTask::Cancel(): abort an in-flight
     * sequence-file load. Execute() keeps the loader it is working through at
     * +0x10 while it reads, under the task's mutex at +0x2c; if one is active,
     * ask it to cancel before the task is dropped. */
    struct SeqLoadTask { char pad[0x10]; void* loader; char pad14[0x18]; void* mutex; };
    SeqLoadTask* task = (SeqLoadTask*)self;

    void* mutex = task->mutex;
    OSLockMutex(mutex);
    void* loader = task->loader;
    if (loader)
        /* detail::SoundArchiveLoader::Cancel(), loader as the hidden `this` */
        ((void (*)(void*))((void (*)(void))Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv))(loader);
    OSUnlockMutex(mutex);
}
#pragma opt_strength_reduction off
extern "C" void Execute__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv(void* self) {
    struct Frame { void* stream; s32 valid; void* ref; u32 pad; u8 header[0x38]; u8 adpcm[8][0x30]; u8 fileBuf[0x200]; };
    Frame f;
    typedef void (*Cb_t)(s32, void*, u32);
    typedef s32 (*Faf_t)(void*, void*, u32);
    if (*(void**)((u8*)self + 0x10) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x6FD, lbl_80325520);
    }
    void* mutex = *(void**)((u8*)self + 0x24);
    OSLockMutex(mutex);
    *(void**)((u8*)self + 0x10) = detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(*(void**)((u8*)self + 0x14), *(u32*)((u8*)self + 0x18), f.fileBuf, 0x200);
    OSUnlockMutex(mutex);
    if (*(void**)((u8*)self + 0x10) == 0) {
        Cb_t cb = *(Cb_t*)((u8*)self + 0x1C);
        if (cb != 0) cb(0, 0, *(u32*)((u8*)self + 0x20));
        return;
    } else if (((ExecStream*)*(void**)((u8*)self + 0x10))->v20() == 0 || ((ExecStream*)*(void**)((u8*)self + 0x10))->v11() == 0) {
        ((ExecStream*)*(void**)((u8*)self + 0x10))->v4();
        Cb_t cb = *(Cb_t*)((u8*)self + 0x1C);
        *(void**)((u8*)self + 0x10) = 0;
        if (cb) cb(0, 0, *(u32*)((u8*)self + 0x20));
        return;
    } else {
        if (!lbl_8055DE58) {
            OSInitMutex(lbl_80412CA0);
            lbl_8055DE58 = 1;
        }
        u8* gm = lbl_80412CA0;
        OSLockMutex(gm);
        f.stream = *(void**)((u8*)self + 0x10);
        NWC24Data_Init(&f.valid);
        if (((Faf_t)fn_800FAF10)(&f.stream, lbl_80412AA0, 0x200) == 0) {
            ((ExecStream*)*(void**)((u8*)self + 0x10))->v4();
            *(void**)((u8*)self + 0x10) = 0;
            Cb_t cb = *(Cb_t*)((u8*)self + 0x1C);
            if (cb) cb(0, 0, *(u32*)((u8*)self + 0x20));
            OSUnlockMutex(gm);
            return;
        }
        void* m2 = *(void**)((u8*)self + 0x24);
        OSLockMutex(m2);
        ((ExecStream*)*(void**)((u8*)self + 0x10))->v4();
        *(void**)((u8*)self + 0x10) = 0;
        OSUnlockMutex(m2);
        if ((((u32)(-f.valid | f.valid) >> 31) == 0)) {} else fn_800FAB98(&f.valid, f.header);
        s32 off = 0;
        s32 i = 0;
        for (off = 0, i = 0; i < f.header[2]; i++, off += 0x30) {
            if ((((u32)(-f.valid | f.valid) >> 31) == 0)) {} else fn_800FACC0(&f.valid, (void*)((u8*)f.adpcm + (short)off), i);
        }
        Cb_t cb2 = *(Cb_t*)((u8*)self + 0x1C);
        if (cb2) cb2(1, f.header, *(u32*)((u8*)self + 0x20));
        OSUnlockMutex(gm);
    }
}
#pragma opt_strength_reduction reset
extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv(void* self) {
    /* Cancel this stream-header load task: clear its state and stop/pause the attached sound if still active. */
    class Sound {
    public:
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual s32 IsActive();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void Stop();
        virtual void Pause(s32, s32);
        virtual void v20();
        virtual s32 IsAttached();
    };
    void* mutex = *(void**)((u8*)self + 0x24);
    OSLockMutex(mutex);
    Sound* sound = *(Sound**)((u8*)self + 0x10);
    *(u32*)((u8*)self + 0x1c) = 0;
    if (sound != 0 && sound->IsAttached() != 0) {
        sound = *(Sound**)((u8*)self + 0x10);
        if (sound->IsActive() != 0) {
            sound = *(Sound**)((u8*)self + 0x10);
            sound->Pause(0, 0);
        } else {
            sound = *(Sound**)((u8*)self + 0x10);
            sound->Stop();
        }
    }
    OSUnlockMutex(mutex);
}

extern "C" const char lbl_80325670[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
struct __StrmLoadCommandRef;
struct __StrmSoundArchiveRef;
struct __StrmMutexRef;
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" void *__ct__Q46nw4hbm3snd18SoundArchivePlayer16StrmDataLoadTaskFPvUlliUllbRQ56nw4hbm3snd6detail10StrmPlayer11LoadCommandRCQ36nw4hbm3snd12SoundArchiveUlUlR7OSMutex(void *self, void *arg1, unsigned long arg2, long arg3, int arg4, unsigned long arg5, long arg6, bool arg7, __StrmLoadCommandRef &arg8, const __StrmSoundArchiveRef &arg9, unsigned long arg10, unsigned long arg11, __StrmMutexRef &arg12) {
    register const char *base = lbl_80324E88;

    *(u32 *)((u8 *)self + 0x04) = 0;
    *(u32 *)((u8 *)self + 0x08) = 0;
    *(void **)((u8 *)self + 0x0c) = (void *)arg11;
    *(void **)self = (void *)lbl_80325670;
    *(void **)((u8 *)self + 0x10) = (void *)&arg8;
    *(u32 *)((u8 *)self + 0x14) = 0;
    *(const void **)((u8 *)self + 0x18) = (const void *)&arg9;
    *(u32 *)((u8 *)self + 0x1c) = (u32)arg10;
    *(void **)((u8 *)self + 0x20) = arg1;
    *(u32 *)((u8 *)self + 0x24) = (u32)arg2;
    *(u32 *)((u8 *)self + 0x28) = (u32)arg3;
    *(u32 *)((u8 *)self + 0x2c) = (u32)arg4;
    *(u32 *)((u8 *)self + 0x30) = (u32)arg5;
    *(u32 *)((u8 *)self + 0x34) = (u32)arg6;
    *(u8 *)((u8 *)self + 0x38) = (u8)arg7;
    *(void **)((u8 *)self + 0x3c) = (void *)&arg12;

    if (((u32)arg1 & 31) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x762, base + 0x6c0, arg1);
    if (((u32)arg2 & 31) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x763, base + 0x708, (u32)arg2);
    if (((u32)arg3 & 3) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x764, base + 0x750, (u32)arg3);
    return self;
}

extern "C" void DCInvalidateRange(s32, u32);
extern "C" void DCFlushRange(s32, s32);
extern "C" void *memcpy(void *, const void *, u32);
extern "C" int fn_800FD810(void *, int);
extern "C" void SetAdpcmLoopContext__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFiPUs(void *, int, u16 *);
extern "C" u8 lbl_8055DE98;
extern "C" const char lbl_80325624[];
#pragma push
#pragma dont_inline off
#pragma always_inline on
/* Execute the stream data load task: open the stream file, validate/read data into the buffer, handle ADPCM loop context, and notify the load command callback. */
extern "C" void Execute__Q46nw4hbm3snd18SoundArchivePlayer16StrmDataLoadTaskFv(void *task) {
    register void *dynamicCastResult;
    register void *mutex;
    s16 adpcmLoopContext[1];
    u8 padding[6];
    u8 streamBuffer[0x200];
    s16 *adpcmContextOut;
    s32 channelBufferAddr;
    s32 blockSizeAligned;
    register s32 destAddr;
    register s32 bytesRead;
    register s32 bufferBase;
    register s32 tempCalc;
    u8 *bufferPtr;
    s32 zeroOffset;
    s32 channelIndex;
    void **stream;
    void **callbackForNotify;
    void **callbackOnOpenFail;
    void **streamForCanSeek;
    void **streamForCanRead;
    void **callbackOnValidateFail;
    void **streamForSeek;
    void **streamForRead;
    void **streamForClose;
    void **callbackOnReadFail;
    void **unusedVar;

    DCInvalidateRange(M2C_FIELD(task, s32 *, 0x20), M2C_FIELD(task, u32 *, 0x24));
    dynamicCastResult = (void *)M2C_FIELD(task, void **, 0x3C);
    OSLockMutex(dynamicCastResult);
    M2C_FIELD(task, void ***, 0x14) = (void **)detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi((void *)M2C_FIELD(task, s32 *, 0x18), (unsigned long)M2C_FIELD(task, s32 *, 0x1C), &streamBuffer, 0x200);
    OSUnlockMutex(dynamicCastResult);
    stream = M2C_FIELD(task, void ***, 0x14);
    if (stream == 0) {
        callbackOnOpenFail = M2C_FIELD(task, void ***, 0x10);
        if (callbackOnOpenFail != 0) {
            ((DummyStrmLoadTaskCallback *)callbackOnOpenFail)->f2(0);
        }
    } else {
        if (((DummyStrmLoadStream *)stream)->f20() == 0) {
            goto fail_6f1c;
        }
        streamForCanRead = M2C_FIELD(task, void ***, 0x14);
        if (((DummyStrmLoadStream *)streamForCanRead)->f11() != 0) {
            goto success_6f5c;
        }
fail_6f1c:
        streamForClose = M2C_FIELD(task, void ***, 0x14);
        ((DummyStrmLoadStream *)streamForClose)->f4();
        callbackOnValidateFail = M2C_FIELD(task, void ***, 0x10);
        M2C_FIELD(task, void ***, 0x14) = 0;
        if (callbackOnValidateFail != 0) {
            ((DummyStrmLoadTaskCallback *)callbackOnValidateFail)->f2(0);
        }
        goto done;
success_6f5c:
        dynamicCastResult = StrmLoadDynamicCast(M2C_FIELD(task, void ***, 0x14), &lbl_8055DE98);
        if (dynamicCastResult != 0) {
            M2C_FIELD(dynamicCastResult, s32 *, 0x68) = 1;
        }
        streamForSeek = M2C_FIELD(task, void ***, 0x14);
        ((DummyStrmLoadStream *)streamForSeek)->f17(M2C_FIELD(task, s32 *, 0x28), 0);
        streamForRead = M2C_FIELD(task, void ***, 0x14);
        bytesRead = ((DummyStrmLoadStream *)streamForRead)->f5((void *)M2C_FIELD(task, void **, 0x20), M2C_FIELD(task, u32 *, 0x24));
        mutex = (void *)M2C_FIELD(task, void **, 0x3C);
        OSLockMutex(mutex);
        streamForClose = M2C_FIELD(task, void ***, 0x14);
        ((DummyStrmLoadStream *)streamForClose)->f4();
        M2C_FIELD(task, void ***, 0x14) = 0;
        OSUnlockMutex(mutex);
        if (bytesRead != -3) {
            if ((u32)bytesRead != (u32)M2C_FIELD(task, u32 *, 0x24)) {
                if (bytesRead == 0) {
                    Warning__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80324E88, 0x79C, (const char *)&lbl_80325624);
                }
                stream = (void **)((void *(*)(void))fn_800FDE60)();
                ((void (*)(void *, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(stream, M2C_FIELD(task, u32 *, 0xC));
                callbackOnReadFail = M2C_FIELD(task, void ***, 0x10);
                if (callbackOnReadFail != 0) {
                    ((DummyStrmLoadTaskCallback *)callbackOnReadFail)->f2(0);
                }
            } else {
                bufferBase = M2C_FIELD(task, s32 *, 0x20);
                adpcmContextOut = &adpcmLoopContext[0];
                for (channelIndex = 0; channelIndex < (s32)M2C_FIELD(task, s32 *, 0x2C); channelIndex++) {
                    if ((s32)M2C_FIELD(task, u8 *, 0x38) != 0) {
                        *adpcmContextOut = *(u8 *)(channelIndex * ((M2C_FIELD(task, s32 *, 0x30) + 0x1F) & 0xFFFFFFE0) + (bufferBase + M2C_FIELD(task, s32 *, 0x34)));
                    }
                    if ((void **)M2C_FIELD(task, void ***, 0x10) != 0) {
                        tempCalc = M2C_FIELD(task, s32 *, 0x30) + 0x1F;
                        blockSizeAligned = tempCalc & 0xFFFFFFE0;
                        bufferPtr = (u8 *)M2C_FIELD(task, void **, 0x20);
                        zeroOffset = M2C_FIELD(task, s32 *, 0x34);
                        tempCalc = channelIndex * blockSizeAligned;
                        channelBufferAddr = (s32)(bufferPtr + zeroOffset + tempCalc);
                        destAddr = fn_800FD810(M2C_FIELD(task, void **, 0x10), channelIndex);
                        memcpy((void *)destAddr, (void *)channelBufferAddr, blockSizeAligned);
                        DCFlushRange(destAddr, blockSizeAligned);
                    }
                    adpcmContextOut += 1;
                }
                if (((s32)M2C_FIELD(task, u8 *, 0x38) != 0) && ((void **)M2C_FIELD(task, void ***, 0x10) != 0)) {
                    SetAdpcmLoopContext__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFiPUs(M2C_FIELD(task, void **, 0x10), M2C_FIELD(task, s32 *, 0x2C), (u16 *)&adpcmLoopContext[0]);
                }
                callbackForNotify = M2C_FIELD(task, void ***, 0x10);
                if (callbackForNotify != 0) {
                    ((DummyStrmLoadTaskCallback *)callbackForNotify)->f2(1);
                }
            }
        }
done:;
    }
}
#pragma pop

extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv_800F7FEC(void* task) {
    class BasicSound {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual s32 m8();
        virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
        virtual void v13(); virtual void v14(); virtual void v15(); virtual void m16();
        virtual void m17(s32, s32); virtual void v18(); virtual s32 Check();
    };

    /* Cancel this stream-header load task and stop its attached sound if still active. */
    void* mutex = *(void**)((u8*)task + 0x3c);
    OSLockMutex(mutex);
    *(u32*)((u8*)task + 0x10) = 0;
    BasicSound* sound = *(BasicSound**)((u8*)task + 0x14);
    if (sound && sound->Check()) {
        sound = *(BasicSound**)((u8*)task + 0x14);
        if (sound->m8()) {
            sound = *(BasicSound**)((u8*)task + 0x14);
            sound->m17(0, 0);
        } else {
            sound = *(BasicSound**)((u8*)task + 0x14);
            sound->m16();
        }
    }
    OSUnlockMutex(mutex);
}

#pragma push
#pragma small_data off
extern "C" u8 lbl_80325BE8[];
extern "C" u8 lbl_80325BB8[];
#pragma push
#pragma small_data off
#pragma push
#pragma dont_inline on
#pragma small_data off
u32 nw4hbm::snd::SoundArchivePlayer::detail_ConvertLabelStringToSoundId(const char *label) {
    /* Convert a sound label string to its sound ID via the attached sound archive loader. */
    if (*(u32 *)((u8 *)this + 0x10) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325BE8, 0x163, (const char *)lbl_80325BB8);
    }
    return (u32)fn_800F27D4(*(void **)((u8 *)this + 0x10), (s32)label);
}
#pragma pop
#pragma pop
extern "C" void *__dt__Q36nw4hbm3snd9SoundHeapFv(void*, int);
extern "C" void *__dt__Q36nw4hbm3snd9SoundHeapFv(void *, int);
/* Deleting destructor for nw4hbm::snd::MemorySoundArchive. */
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8114(void *self, int deleting) {
    if (self) {
        __dt__Q36nw4hbm3snd9SoundHeapFv(self, 0);
        if (deleting > 0) ((void (*)(void *))fn_80128668)(self);
    }
    return self;
}

extern "C" s32 fn_800F816C(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_800F81AC(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_800F81EC(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" void fn_800F822C(s32 arg0) {
    detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(arg0 - 0xC);
}

extern "C" s32 fn_800F65F0(void *, void **, u32, s32, s32, s32, void *, s32);
extern "C" void fn_800F8234(s32 thisAtOffsetC) {
    /* This-adjusting thunk for nw4r::snd::SoundArchivePlayer: subtract the 0xC subobject offset to recover `this`, then forward to the sound prepare/play routine (fn_800F65F0). */
    ((s32 (*)(s32))fn_800F65F0)(thisAtOffsetC - 0xC);
}

extern "C" void *__dt__Q36nw4hbm3snd18SoundArchivePlayerFv(void *, s32);
/* Deleting-destructor this-adjusting thunk for nw4h::bm::snd::SoundArchivePlayer: subtract the 0xC subobject offset to recover `this`, then forward the delete flag to its destructor. */
extern "C" void fn_800F823C(s32 subobjectThis, s32 deleteFlag) {
    __dt__Q36nw4hbm3snd18SoundArchivePlayerFv((void *)(subobjectThis - 0xC), deleteFlag);
}

/* nw4hbm::snd::SoundHandle::detail_AttachSound(detail::BasicSound*):
 * Attach a BasicSound to this SoundHandle, detaching any general handle
 * currently attached to the sound and linking this handle as its new general handle. */
extern "C" void detail_AttachSound__Q36nw4hbm3snd11SoundHandleFPQ46nw4hbm3snd6detail10BasicSound(void **handle, void *sound) {
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(SND_SOUNDHANDLE_CPP, 0x55, SND_HANDLE_PTR_SOUND_MSG);
    }
    *handle = sound;
    if (BasicSound_IsAttachedGeneralHandle(sound) != 0) {
        BasicSound_DetachGeneralHandle(*handle);
    }
    ((SoundHandleBasicSoundLayout *)*handle)->generalHandle = handle;
}

// Detaches this sound handle from the attached sound, clearing the sound's back-pointers to it.
void DetachSound__Q34nw4r3snd11SoundHandleFv(void **handle) {
    void *sound = *handle;
    if (sound) {
        if (*(u32 *)((u8 *)sound + 8) == (u32)handle)
            *(u32 *)((u8 *)sound + 8) = 0;
        sound = *handle;
        if (*(u32 *)((u8 *)sound + 0xc) == (u32)handle)
            *(u32 *)((u8 *)sound + 0xc) = 0;
    }
    if (*handle == 0)
        return;
    *handle = 0;
}

#pragma push
#pragma small_data off
/* Initializes a SoundHeap: sets its vtable, constructs the embedded frame heap, and initializes the mutex. */
extern "C" void *fn_800F8310(void *self) {
    *(void **)self = (void *)lbl_80325C40;
    fn_800EBB88((char *)self + 0x1C);
    OSInitMutex((char *)self + 4);
    return self;
}
#pragma push
#pragma small_data off
#pragma use_lmw_stmw off
extern "C" void* __dt__Q36nw4hbm3snd9SoundHeapFv(void* self, int flag) {
    if (self) {
        *(void**)self = lbl_80325C40;
        Destroy__Q46nw4hbm3snd6detail9FrameHeapFv((char*)self + 0x1C);
        __dt__Q46nw4hbm3snd6detail9FrameHeapFv((char*)self + 0x1C, -1);
        if (flag > 0)
            fn_80128668();
    }
    return self;
}
#pragma pop
/* nw4hbm::snd::SoundHeap::Create(): initialize the frame heap embedded at
 * +0x1C of this SoundHeap (paired with fn_800F83D0 / fn_800F83D8). */
extern "C" void fn_800F83C8(void* self) {
    Create__Q46nw4hbm3snd6detail9FrameHeapFPvUl((u8*)self + 0x1C);
}

/* Destroy the FrameHeap embedded at +0x1C of a SoundHeap (paired with fn_800F83C8). */
extern "C" void fn_800F83D0(void* soundHeap) {
    Destroy__Q46nw4hbm3snd6detail9FrameHeapFv((u8*)soundHeap + 0x1C);
}

extern "C" void* fn_800F83D8(void* arg0, unsigned long arg1) {
    /* Allocate `arg1` bytes from this SoundHeap's frame heap (at +0x1C) under
       the mutex (at +0x04), registering the SoundHeap dispose callback. */
    void* mutex = (u8*)arg0 + 4;
    OSLockMutex(mutex);
    void* result = Alloc__Q46nw4hbm3snd6detail9FrameHeapFUlPFPvUlPv_vPv(
        (u8*)arg0 + 0x1C, arg1, DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv, 0);
    OSUnlockMutex(mutex);
    return result;
}

/* nw4hbm::snd::SoundHeap::DisposeCallbackFunc(void*, u32, void*): the disposal callback
   handed to FrameHeap::Alloc for every block taken from a SoundHeap (fn_800F83D8).  The
   frame heap calls it with the block's data [start, start + size) as it drops the block;
   the two DisposeCallbackManager passes then tell every registered sound object that the
   range is going away -- once as a generic object, once as wave data. */
extern "C" void DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv(void* start,
                                                                    unsigned long size,
                                                                    void* user) {
    Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(start, size, user);
    DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(start, size,
                                                                              user);
}

extern "C" void __ct__Q36nw4hbm3snd11SoundPlayerFv(void* self) {
    u8* p = (u8*)self;
    register u32 zero = 0;
    register u32 one = 1;
    register f32 initialValue = lbl_805610B8;
    register u8* firstList = p + 4;
    register u8* secondList = p + 0x10;
    register u8* thirdList = p + 0x1c;
    *(volatile u32*)(p + 8) = zero;
    *(volatile u32*)(p + 4) = zero;
    *(volatile u32*)(p + 0x10) = zero;
    *(volatile u32*)(p + 0x14) = zero;
    *(volatile u32*)(p + 0x1c) = zero;
    *(volatile u32*)(p + 0x20) = zero;
    *(u32*)p = zero;
    *(u32*)(p + 4) = (u32)firstList;
    *(u32*)(p + 8) = (u32)firstList;
    *(u32*)(p + 0xc) = zero;
    *(u32*)(p + 0x10) = (u32)secondList;
    *(u32*)(p + 0x14) = (u32)secondList;
    *(u32*)(p + 0x18) = zero;
    *(u32*)(p + 0x1c) = (u32)thirdList;
    *(u32*)(p + 0x20) = (u32)thirdList;
    *(u16*)(p + 0x24) = one;
    *(u16*)(p + 0x26) = one;
    *(u8*)(p + 0x2d) = zero;
    *(f32*)(p + 0x28) = initialValue;
    *(u32*)(p + 0x30) = one;
    *(u8*)(p + 0x2c) = zero;
    *(f32*)(p + 0x34) = initialValue;
    *(f32*)(p + 0x38) = initialValue;
    *(f32*)(p + 0x3c) = initialValue;
    *(f32*)(p + 0x40) = initialValue;
    *(f32*)(p + 0x44) = initialValue;
}

extern "C" void fn_800F8520(void *list) {
    // Initialize an empty nw4r ut::LinkList: clear the element count at +0x00,
    // then make the sentinel node's next (+0x04) and prev (+0x08) point at itself.
    s32 *sentinel = (s32 *)((u8 *)list + 4);
    *(s32 *)((u8 *)list + 4) = 0;
    *(s32 *)((u8 *)list + 8) = 0;
    *(s32 *)list = 0;
    *(s32 *)((u8 *)list + 4) = (s32)sentinel;
    *(s32 *)((u8 *)list + 8) = (s32)sentinel;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8540(void* self, int shouldDelete) {
    if (self != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(self, 0);
        if (shouldDelete > 0) ((void (*)(void *))fn_80128668)(self);
    }
    return self;
}

#pragma use_lmw_stmw off
extern "C" void *__dt__Q36nw4hbm3snd11SoundPlayerFv(void *arg0, s32 arg1) {
    class Dummy {
    public:
        virtual void v0() {}
        virtual void v1() {}
        virtual void v2() {}
        virtual void v3() {}
        virtual void destroy(s32) {}
    };
    register void *it;
    register void *head;
    register void *node;
    if (arg0 != 0) {
        head = (char *)arg0 + 4;
        it = *(void **)head;
        for (; it != head; ) {
            node = it;
            it = *(void **)it;
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262E8, 0x23D, (const char *)lbl_803262C4);
            ((Dummy *)((char *)node - 0xC0))->destroy(0);
        }
        if ((char *)arg0 + 0x18)
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 0x18, 0);
        if ((char *)arg0 + 0xC)
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 0xC, 0);
        if (arg0)
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma use_lmw_stmw reset
#pragma opt_common_subs off
void Update__Q36nw4hbm3snd11SoundPlayerFv(void *player) {
    /* Advance every sound on this SoundPlayer's priority list once, then re-sort
     * the list by priority. The list is a nw4 LinkList with a sentinel at +4 of
     * the player; each node sits 0xC0 into its sound object, whose virtual
     * update() (vtable slot 4) does the per-frame work. */
    struct SoundNodeBase {
        virtual ~SoundNodeBase();
        virtual void unusedVirtual();
        virtual void update();
    };
    struct { void *head; } cursor;
    cursor.head = *(void **)((u8 *)player + 4);
    void *&head = cursor.head;
    struct { void *end; } sentinel;
    sentinel.end = (u8 *)player + 4;
    void *&end = sentinel.end;
    void *node;
    while (head != end) {
        node = head;
        head = *(void **)node;
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262E8, 0x23D, (const char *)lbl_803262C4);
        }
        ((SoundNodeBase *)((u8 *)node - 0xC0))->update();
    }
    detail_SortPriorityList__Q36nw4hbm3snd11SoundPlayerFv(player);
}
#pragma use_lmw_stmw off
#pragma opt_common_subs off
void StopAllSound__Q36nw4hbm3snd11SoundPlayerFi(void *player, s32 fadeTime) {
    /* Stop every sound on this SoundPlayer's priority list: walk the nw4
     * LinkList (sentinel at +4 of the player, each node 0xC0 into its sound
     * object) and call each sound's virtual stopAllSound (vtable slot 6). */
    struct StoppableSound {
        virtual ~StoppableSound();
        virtual void unusedVirtual0();
        virtual void unusedVirtual1();
        virtual void unusedVirtual2();
        virtual void stopAllSound(s32);
    };
    struct { void *head; } cursor;
    cursor.head = *(void **)((u8 *)player + 4);
    void *&head = cursor.head;
    struct { void *end; } sentinel;
    sentinel.end = (u8 *)player + 4;
    void *&end = sentinel.end;
    void *soundNode;
    while (head != end) {
        soundNode = head;
        head = *(void **)soundNode;
        if (soundNode == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262E8, 0x23D, (const char *)lbl_803262C4);
        }
        ((StoppableSound *)((u8 *)soundNode - 0xC0))->stopAllSound(fadeTime);
    }
}
#pragma opt_common_subs reset
extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800F877C(void *sound, f32 volume) {
    /* Sets the sound's initial volume (offset 0x28), asserting it is non-negative. */
    if (!(volume >= 0.0f)) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x99, lbl_80325C64);
    *(f32 *)((u8 *)sound + 0x28) = volume;
}
#pragma pop
extern "C" s32 fn_800F87E8(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x30); }

extern "C" u8 fn_800F87F0(void *arg0) { return *(u8 *)((u8 *)arg0 + 0x2C); }

/* Get the FX send level for an aux bus (0..3) on this sound player. */
extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800F87F8(s32 self, s32 auxBus) {
    s32 isValidBus = 0;
    if (auxBus >= 0 && auxBus < 4) isValidBus = 1;
    if (isValidBus == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x103, lbl_80325C8C, auxBus, 0, 4);
    return *(f32 *)((u8 *)(self + auxBus * 4) + 0x38);
}

/* Remove a BasicSound from the SoundPlayer's sound list and clear its owning player pointer. */
void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(void *player, void *sound) {
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262B8, 0x233, (const char *)lbl_80326294);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(player, (u8 *)sound + 0xC0);
    *(u32 *)((u8 *)sound + 0x10) = 0;
}

#pragma use_lmw_stmw off
extern "C" void detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *self, void *sound) {
    void *node = *(void **)((char *)self + 0x10);
    void *head = (char *)self + 0x10;
    while (node != head) {
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326348, 0x23D, (const char *)lbl_80326324);
        int raw = *(unsigned char *)((char *)node - 0x54) + *(int *)((char *)node - 0x88);
        int priority;
        if (raw > 127) {
            priority = 127;
        } else {
            priority = raw < 0 ? 0 : raw;
        }
        int rawSound = *(unsigned char *)((char *)sound + 0x74) + *(int *)((char *)sound + 0x40);
        int soundPriority;
        if (rawSound > 127) {
            soundPriority = 127;
        } else {
            soundPriority = rawSound < 0 ? 0 : rawSound;
        }
        if (soundPriority < priority)
            break;
        node = *(void **)node;
    }
    if (sound == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326288, 0x233, (const char *)lbl_80326264);
    void *iterator = node;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)self + 0xC, &iterator, (char *)sound + 0xC8);
}
extern "C" void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *soundPlayer, void *basicSound) {
    /* Remove a sound from the player's priority list (node at sound+0xC8, list at player+0xC). */
    if (basicSound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326288, 0x233, (const char *)lbl_80326264);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)soundPlayer + 0xC, (u8 *)basicSound + 0xC8);
}

#pragma use_lmw_stmw off
extern "C" void detail_SortPriorityList__Q36nw4hbm3snd11SoundPlayerFv(void* arg0) {
    extern void* fn_8002F53C(void*, void (*)(void*), void* (*)(void*, int), s32, s32);
    extern void* fn_8002F634(void*, void* (*)(void*, int), s32, s32);
    extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*, void**);
    extern void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);
    extern void fn_800F8520(void*);
    extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8540(void*, int);
    u8* self = (u8*)arg0;
    void *it_14, *it_10, *it_C, *it_8;
    u8 arr[0x600];
    fn_8002F53C(arr, fn_800F8520, __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8540, 0xC, 0x80);
    while (*(s32*)(self + 0xC) != 0) {
        if (*(s32*)(self + 0xC) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803263A8, 0x1F1, lbl_80326384);
        }
        {
            void* node = *(void**)(self + 0x10);
            if (node == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326348, 0x23D, lbl_80326324);
            }
            u8* elt = (u8*)node - 0xC8;
            if (elt == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326378, 0x193, lbl_80326354);
            }
            it_14 = *(void**)(self + 0x10);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(self + 0xC, (void**)&it_14);
            s32 prio = *(u8*)(elt + 0x74) + *(s32*)(elt + 0x40);
            prio = prio > 0x7F ? 0x7F : prio & ~(prio >> 31);
            u8* bucket = arr + prio * 0xC;
            it_10 = (void*)(bucket + 4);
            if (elt == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326288, 0x233, (const char*)lbl_80326264);
            }
            Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(bucket, (void**)&it_10, elt + 0xC8);
        }
    }
    {
        u8* entry = arr;
        u32 k = 0;
        do {
            if (*(void**)entry != 0) {
                void* temp;
                do {
                    temp = *(void**)entry;
                    if (temp != 0) {
                        if (temp == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803263A8, 0x1F1, lbl_80326384);
                        }
                        void* next2 = *(void**)(entry + 4);
                        if (next2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326348, 0x23D, lbl_80326324);
                        }
                        u8* elt2 = (u8*)next2 - 0xC8;
                        if (elt2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326378, 0x193, lbl_80326354);
                        }
                        it_C = *(void**)(entry + 4);
                        Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(entry, (void**)&it_C);
                        if (elt2 == 0) {
                            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326288, 0x233, (const char*)lbl_80326264);
                        }
                        it_8 = (void*)(self + 0x10);
                        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(self + 0xC, (void**)&it_8, elt2 + 0xC8);
                    }
                    temp = *(void**)entry;
                } while (temp != 0);
            }
            k += 1;
            entry += 0xC;
        } while (k < 0x80);
    }
    fn_8002F634(arr, __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8540, 0xC, 0x80);
}

extern "C" void* fn_800F07EC(void*, void*);
extern "C" void* fn_800F8CA4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void* arg6) {
    extern const char lbl_8032624C[];
    extern const char lbl_80326208[];
    extern const char lbl_803261F0[];
    extern const char lbl_803261C8[];
    extern const char lbl_803259E4[];
    extern const char lbl_803259C0[];
    extern const char lbl_80324314[];
    extern const char lbl_803242F0[];
    extern const char lbl_803259B4[];
    extern const char lbl_80325990[];
    extern const char lbl_80324344[];
    extern const char lbl_80324320[];
    unsigned char* pool = (unsigned char*)arg6;
    unsigned char* player = (unsigned char*)arg0;
    unsigned char* info = (unsigned char*)arg3;
    s32 tmpBuf[8];
    void* it;
    s32 v;
    s32 prio;
    s32 base;
    u32 save;
    void* snd;
    void* cur;
    void* end;
    void* node;
    if (pool == 0) return 0;
    base = 0;
    if (info != 0) {
        unsigned char* obj = *(unsigned char**)info;
        typedef s32 (*Fn)(void*, void*, s32, s32, s32, s32);
        Fn f = *(Fn*)(*(unsigned char**)obj + 8);
        f(obj, tmpBuf, (s32)arg5, 0, *(s32*)(info + 0xC), 8);
        base = tmpBuf[6];
    }
    v = (s32)arg2 - base;
    if (v > 0x7F) prio = 0x7F;
    else prio = v & ~(v >> 31);
    if (CheckPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFiPQ46nw4hbm3snd6detail19ExternalSoundPlayer((void*)arg0, (int)prio, (void*)arg4) == 0) return 0;
    if (!(prio >= 0 && prio <= 0x7F)) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8032624C, 0x5C, lbl_80326208, prio, 0, 0x7F);
    save = OSDisableInterrupts();
    snd = AllocImpl__Q44nw4r3snd6detail8PoolImplFv(pool);
    if (snd != 0) {
        snd = fn_800F07EC(snd, pool);
        goto alloc_done;
    }
    if (*(s32*)(pool + 4) == 0) {
        OSRestoreInterrupts(save);
        snd = 0;
    } else {
        cur = *(void**)(pool + 8);
        if (cur == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324314, 0x23D, lbl_803242F0);
        node = (unsigned char*)cur - 0xB8;
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803259B4, 0x193, lbl_80325990);
        if (node == 0) {
            OSRestoreInterrupts(save);
            snd = 0;
        } else {
            s32 q = *(unsigned char*)((unsigned char*)node + 0x74) + *(s32*)((unsigned char*)node + 0x40);
            s32 qc = (q > 0x7F) ? 0x7F : (q & ~(q >> 31));
            if (prio < qc) {
                OSRestoreInterrupts(save);
                snd = 0;
            } else {
                typedef void (*G)(void*, s32);
                G g = *(G*)(*(unsigned char**)node + 0x18);
                g(node, 0);
                snd = AllocImpl__Q44nw4r3snd6detail8PoolImplFv(pool);
                if (snd == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803261F0, 0x72, lbl_803261C8);
                if (snd != 0) snd = fn_800F07EC(snd, pool);
alloc_done:
                cur = *(void**)(pool + 8);
                end = pool + 8;
                while (cur != end) {
                    if (cur == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324314, 0x23D, lbl_803242F0);
                    s32 r = *(unsigned char*)((unsigned char*)cur - 0x44) + *(s32*)((unsigned char*)cur - 0x78);
                    s32 rc = (r > 0x7F) ? 0x7F : (r & ~(r >> 31));
                    if (prio < rc) break;
                    cur = *(void**)cur;
                }
                if (snd == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324344, 0x233, lbl_80324320);
                it = cur;
                Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(pool + 4, &it, (unsigned char*)snd + 0xB8);
                OSRestoreInterrupts(save);
            }
        }
    }
    if (snd == 0) return 0;
    if (*(s32*)(player + 0x18) != 0) {
        cur = *(void**)(player + 0x1C);
        if (cur == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325DE4, 0x23D, lbl_80325DC0);
        node = (unsigned char*)cur - 0x2C;
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325E14, 0x193, lbl_80325DF0);
        v = *(s32*)(player + 0x1C);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(player + 0x18, &v);
        *(void**)((unsigned char*)node + 0x34) = snd;
        *(void**)((unsigned char*)snd + 4) = node;
        OSLockMutex((unsigned char*)node + 4);
        fn_800EC1A4((unsigned char*)node + 0x1C);
        OSUnlockMutex((unsigned char*)node + 4);
    }
    if (info != 0) {
        unsigned char* a = *(unsigned char**)(info + 8);
        typedef s32 (*H)(void*, s32);
        H h = *(H*)(*(unsigned char**)a + 8);
        s32 hv = h(a, *(s32*)(info + 0x10));
        if (hv != 0) {
            memcpy((void*)(*(s32*)(info + 0xC)), (void*)(*(s32*)(info + 0x10)), (u32)hv);
            fn_800E9B74(snd, *(void**)info, *(s32*)(info + 4), *(void**)(info + 8), hv);
        }
    }
    *(unsigned char*)((unsigned char*)snd + 0x74) = (unsigned char)arg1;
    *(s32*)((unsigned char*)snd + 0x40) = base;
    if (snd == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803262B8, 0x233, (const char*)lbl_80326294);
    it = player + 4;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(player, &it, (unsigned char*)snd + 0xC0);
    *(void**)((unsigned char*)snd + 0x10) = player;
    if (arg4 != 0) InsertSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound((void*)arg4, snd);
    cur = *(void**)(player + 0x10);
    end = player + 0x10;
    while (cur != end) {
        if (cur == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326348, 0x23D, (const char*)lbl_80326324);
        s32 r2 = *(unsigned char*)((unsigned char*)cur - 0x54) + *(s32*)((unsigned char*)cur - 0x88);
        s32 c2 = (r2 > 0x7F) ? 0x7F : (r2 & ~(r2 >> 31));
        s32 s2 = *(unsigned char*)((unsigned char*)snd + 0x74) + *(s32*)((unsigned char*)snd + 0x40);
        s32 sc2 = (s2 > 0x7F) ? 0x7F : (s2 & ~(s2 >> 31));
        if (sc2 < c2) break;
        cur = *(void**)cur;
    }
    if (snd == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326288, 0x233, (const char*)lbl_80326264);
    it = cur;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListImpl8Iterator(player + 0xC, &it, (unsigned char*)snd + 0xC8);
    return snd;
}

/* SoundInstanceManager::Alloc(priority): take a free sound from the pool, or evict the
   lowest-priority active one (the list is sorted, front = lowest); inlined into fn_800F9200. */
#pragma push
#pragma always_inline on
/* Ambient priority from the optional ambient-arg info (arg3 of fn_800F9200): 0 when absent. */
/* The ambient-arg callbacks and the sound itself are called through real vtables
   (first virtual at +8, after the RTTI/offset header). */
struct AmbientParamUpdateCallback {
    virtual void detail_Update(void *param, s32 soundId, s32 unk, s32 arg, s32 flags);
};
struct AmbientArgAllocaterCallback {
    virtual void *detail_AllocAmbientArg(s32 size);
};
struct BasicSoundVirtuals {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Stop(s32 fadeFrames);
};

static inline s32 AmbientInfo_GetPriority(s32 ambientInfo, s32 soundId) {
    s32 priority = 0;
    if (ambientInfo != 0) {
        s32 info[7];
        (*(AmbientParamUpdateCallback **)ambientInfo)->detail_Update((void *)info, soundId, 0, *(s32 *)(ambientInfo + 0xC), 8);
        priority = info[6];
    }
    return priority;
}

/* ut::Clamp(x, low, high) */
static inline s32 ClampS32(s32 x, s32 low, s32 high) {
    return x > high ? high : (x < low ? low : x);
}

/* SoundInstanceManager: insert the sound into the pool's priority-sorted list (+0x4, node at sound+0xB8). */
static inline void SoundInstanceManager_InsertPriorityList(void *pool, void *sound, s32 priority) {
    void *it;
    struct { void *node; } iter;
    void *&pos = iter.node;
    pos = *(void **)((u8 *)pool + 8);
    while (pos != (void *)((u8 *)pool + 8)) {
        if (pos == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258C4, 0x23D, lbl_803258A0);
        }
        {
            s32 c = *(u8 *)((u8 *)pos - 0x44) + *(s32 *)((u8 *)pos - 0x78);
            s32 cc = c > 0x7F ? 0x7F : (c < 0 ? 0 : c);
            if (priority < cc) {
                break;
            }
        }
        pos = *(void **)pos;
    }
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    }
    it = pos;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListImpl8Iterator((u8 *)pool + 4, &it, (u8 *)sound + 0xB8);
}

/* ut::LinkList iterator (list = { size, node }): GetEndIter() is the list's own node. */
struct LinkListIter {
    void *node;
    bool operator!=(const LinkListIter &other) const { return node != other.node; }
    LinkListIter &operator++() { node = *(void **)node; return *this; }
};
/* End of the SoundInstanceManager's priority list (list at +0x4, its node at +0x8). */
static inline LinkListIter SoundInstanceManager_GetPriorityListEnd(void *pool) {
    LinkListIter iter;
    iter.node = (u8 *)pool + 8;
    return iter;
}

static inline void *SoundInstanceManager_Alloc(void *pool, s32 priority) {
    void *sound = 0;
    void *it;
    struct { u32 old; } lock;
    u32 &irq = lock.old;
    struct { void *node; } iter;
    void *&pos = iter.node;
    LinkListIter end_iter;
    {
        s32 ok = 0;
        if (priority >= 0 && priority <= 0x7F) {
            ok = 1;
        }
        if (ok == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803260F0, 0x5C, lbl_803260AC, priority, 0, 0x7F);
        }
    }
    lock.old = OSDisableInterrupts();
    void *mem = AllocImpl__Q44nw4r3snd6detail8PoolImplFv(pool);
    if (mem != 0) {
        sound = mem;
        if (mem != 0) {
            sound = fn_800FDA20(mem, pool);
        }
    } else {
        u8 *node;
        u8 *front;
        if (*(s32 *)((u8 *)pool + 4) == 0) {
            OSRestoreInterrupts(irq);
            return 0;
        }
        if (*(s32 *)((u8 *)pool + 4) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325924, 0x1F1, lbl_80325900);
        }
        node = *(u8 **)((u8 *)pool + 8);
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258C4, 0x23D, lbl_803258A0);
        }
        front = node - 0xB8;
        if (front == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258F4, 0x193, lbl_803258D0);
        }
        if (front == 0) {
            OSRestoreInterrupts(irq);
            return 0;
        }
        {
            s32 c = *(u8 *)(front + 0x74) + *(s32 *)(front + 0x40);
            s32 cc = c > 0x7F ? 0x7F : (c < 0 ? 0 : c);
            if (priority < cc) {
                OSRestoreInterrupts(irq);
                return 0;
            }
        }
        ((BasicSoundVirtuals *)front)->Stop(0);
        mem = AllocImpl__Q44nw4r3snd6detail8PoolImplFv(pool);
        sound = mem;
        if (mem == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326094, 0x72, lbl_8032606C);
        }
        if (sound != 0) {
            sound = fn_800FDA20(sound, pool);
        }
    }
    pos = *(void **)((u8 *)pool + 8);
    end_iter = SoundInstanceManager_GetPriorityListEnd(pool);
    while (pos != end_iter.node) {
        if (pos == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803258C4, 0x23D, lbl_803258A0);
        }
        if (priority < ClampS32(*(u8 *)((u8 *)pos - 0x44) + *(s32 *)((u8 *)pos - 0x78), 0, 0x7F)) {
            break;
        }
        pos = *(void **)pos;
    }
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325894, 0x233, lbl_80325870);
    }
    it = pos;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListImpl8Iterator((u8 *)pool + 4, &it, (u8 *)sound + 0xB8);
    OSRestoreInterrupts(irq);
    return sound;
}

/* SoundPlayer: hand the sound the first free player heap (list at +0x18, node at heap+0x2C). */
static inline void SoundPlayer_AttachPlayerHeap(s32 player, void *sound) {
    if (*(s32 *)(player + 0x18) != 0) {
        u8 *heap;
        s32 node;
        s32 it;
        if (*(s32 *)(player + 0x18) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325E44, 0x1F1, lbl_80325E20);
        }
        node = *(s32 *)(player + 0x1C);
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325DE4, 0x23D, lbl_80325DC0);
        }
        heap = (u8 *)(node - 0x2C);
        if (heap == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325E14, 0x193, lbl_80325DF0);
        }
        it = *(s32 *)((u8 *)(player + 0x18) + 4);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator((u8 *)(player + 0x18), &it);
        *(void **)(heap + 0x34) = sound;
        {
            u8 *mutex = heap + 4;
            *(void **)((u8 *)sound + 4) = (void *)heap;
            OSLockMutex((void *)mutex);
            fn_800EC1A4((void *)(heap + 0x1C));
            OSUnlockMutex((void *)mutex);
        }
    }
}

/* SoundPlayer: append the sound to the player's sound list (+0x0, node at sound+0xC0). */
static inline void SoundPlayer_PushSoundList(s32 player, void *sound) {
    void *it;
    void *end = (void *)(player + 4);
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262B8, 0x233, (const char *)lbl_80326294);
    }
    it = end;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListImpl8Iterator((void *)player, &it, (u8 *)sound + 0xC0);
}

/* SoundPlayer: insert the sound into the priority-sorted list (+0xC, node at sound+0xC8). */
static inline void SoundPlayer_InsertPriorityList(s32 player, void *sound) {
    void *it;
    struct { void *node; } iter;
    void *&pos = iter.node;
    pos = *(void **)(player + 0x10);
    while (pos != (void *)(player + 0x10)) {
        if (pos == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326348, 0x23D, lbl_80326324);
        }
        {
            s32 c = *(u8 *)((u8 *)pos - 0x54) + *(s32 *)((u8 *)pos - 0x88);
            s32 cc = c > 0x7F ? 0x7F : (c < 0 ? 0 : c);
            s32 d = *(u8 *)((u8 *)sound + 0x74) + *(s32 *)((u8 *)sound + 0x40);
            s32 dc = d > 0x7F ? 0x7F : (d < 0 ? 0 : d);
            if (dc < cc) {
                break;
            }
        }
        pos = *(void **)pos;
    }
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326288, 0x233, (const char *)lbl_80326264);
    }
    it = pos;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListImpl8Iterator((u8 *)(player + 0xC), &it, (u8 *)sound + 0xC8);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma auto_inline off
extern "C" void *fn_800F9200(s32 player, s32 priority, s32 requestedPriority, s32 ambientInfo, s32 externalPlayer, s32 soundId, void *manager) {
    /* detail::SoundInstanceManager::Alloc for streaming sounds.  Takes a free
     * StrmSound out of the instance pool; when the pool is full it takes the
     * sound with the lowest priority away from that list (stopping it first) if
     * the new sound outranks it, and gives up otherwise.  The new sound is then
     * built up: the player's first free frame heap, a copy of the ambient arg
     * with its update callback, its priority (+0x74) and ambient priority
     * offset (+0x40), and links into the manager's priority list (+0x4, node
     * +0xB8), the player's sound list (+0x00, node +0xC0), the player's
     * priority list (+0x0C, node +0xC8) and the external player's sound list.
     * Returns the sound, or 0 when it could not be started. */
#define PANIC Panic__Q26nw4hbm2dbFPCciPCce
#define LIST_INSERT Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode
#define LIST_ERASE Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator
#define POOL_ALLOC AllocImpl__Q44nw4r3snd6detail8PoolImplFv
#define NEW_STRM_SOUND fn_800FDA20            /* StrmSound::StrmSound() */
#define CHECK_PLAYABLE CheckPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFiPQ46nw4hbm3snd6detail19ExternalSoundPlayer
#define EXTERNAL_INSERT_SOUND InsertSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound
#define FRAME_HEAP_CLEAR fn_800EC1A4          /* FrameHeap::Clear() */
#define ATTACH_AMBIENT_ARG fn_800E9B74
    union { s32 request; u32 end; } scratch; /* one register the original reused
                                                for the requested priority and for
                                                the list ends and node pointers */
    s32 ambientPriority;
    s32 listPriority;
    void *sound;

    if (manager == 0) {
        return 0;
    }
    scratch.request = requestedPriority;
    /* The ambient arg's callback hands out this sound's ambient priority, which
     * the sound itself carries as its priority offset. */
    ambientPriority = AmbientInfo_GetPriority(ambientInfo, soundId);
    listPriority = ClampS32(scratch.request - ambientPriority, 0, 127);
    if (CHECK_PLAYABLE((void *)player, listPriority, (void *)externalPlayer) == 0) {
        return 0;
    }
    { /* SoundInstanceManager::Alloc(listPriority), inlined. */

    sound = 0;
    void *it;
    struct { u32 old; } lock;
    u32 &irq = lock.old;
    struct { void *node; } iter;
    void *&pos = iter.node;
    
    {
        s32 ok = 0;
        if (listPriority >= 0 && listPriority <= 0x7F) {
            ok = 1;
        }
        if (ok == 0) {
            PANIC(lbl_803260F0, 0x5C, lbl_803260AC, listPriority, 0, 0x7F);
        }
    }
    lock.old = OSDisableInterrupts();
    void *freeSound = POOL_ALLOC(manager);
    if (freeSound != 0) {
        sound = freeSound;
        if (freeSound != 0) {
            sound = NEW_STRM_SOUND(freeSound, manager);
        }
    } else {
        /* Pool empty: the priority list is sorted with the lowest priority in
         * front, so that is the only sound this one may take over. */
        u8 *node;
        u8 *lowest;
        if (*(s32 *)((u8 *)manager + 4) == 0) {
            OSRestoreInterrupts(irq);
            sound = 0;
            goto allocation_done;
        }
        if (*(s32 *)((u8 *)manager + 4) == 0) {
            PANIC(lbl_80325924, 0x1F1, lbl_80325900);
        }
        node = *(u8 **)((u8 *)manager + 8);
        if (node == 0) {
            PANIC(lbl_803258C4, 0x23D, lbl_803258A0);
        }
        lowest = node - 0xB8; /* the sound its manager node (+0xB8) belongs to */
        if (lowest == 0) {
            PANIC(lbl_803258F4, 0x193, lbl_803258D0);
        }
        if (lowest == 0) {
            OSRestoreInterrupts(irq);
            sound = 0;
            goto allocation_done;
        }
        {
            /* BasicSound::CalcPriority_(): own priority (+0x74) plus offset (+0x40). */
            s32 lowestPrio = *(u8 *)(lowest + 0x74) + *(s32 *)(lowest + 0x40);
            s32 clamped = lowestPrio > 0x7F ? 0x7F : (lowestPrio < 0 ? 0 : lowestPrio);
            if (listPriority < clamped) {
                OSRestoreInterrupts(irq);
                sound = 0;
                goto allocation_done;
            }
        }
        ((BasicSoundVirtuals *)lowest)->Stop(0);
        freeSound = POOL_ALLOC(manager);
        sound = freeSound;
        if (freeSound == 0) {
            PANIC(lbl_80326094, 0x72, lbl_8032606C);
        }
        if (sound != 0) {
            sound = NEW_STRM_SOUND(sound, manager);
        }
    }
    /* Insert into the manager's priority-sorted list, in front of the first
     * sound that outranks this one. */
    pos = *(void **)((u8 *)manager + 8);
    scratch.end = (u32)manager + 8;
    while ((u32)pos != scratch.end) {
        if (pos == 0) {
            PANIC(lbl_803258C4, 0x23D, lbl_803258A0);
        }
        if (listPriority < ClampS32(*(u8 *)((u8 *)pos - 0x44) + *(s32 *)((u8 *)pos - 0x78), 0, 0x7F)) {
            break;
        }
        pos = *(void **)pos;
    }
    if (sound == 0) {
        PANIC(lbl_80325894, 0x233, lbl_80325870);
    }
    it = pos;
    LIST_INSERT((u8 *)manager + 4, &it, (u8 *)sound + 0xB8);
    OSRestoreInterrupts(irq);

    }
allocation_done:
    if (sound == 0) {
        return 0;
    }
    { /* Give the sound the first frame heap still on the player's heap list. */

    if (*(s32 *)(player + 0x18) != 0) {
        u8 *frameHeap;

        s32 it;
        if (*(s32 *)(player + 0x18) == 0) {
            PANIC(lbl_80325E44, 0x1F1, lbl_80325E20);
        }
        scratch.end = *(s32 *)(player + 0x1C);
        if (scratch.end == 0) {
            PANIC(lbl_80325DE4, 0x23D, lbl_80325DC0);
        }
        frameHeap = (u8 *)(scratch.end - 0x2C); /* node of the heap's list entry */
        if (frameHeap == 0) {
            PANIC(lbl_80325E14, 0x193, lbl_80325DF0);
        }
        it = *(s32 *)((u8 *)(player + 0x18) + 4);
        LIST_ERASE((u8 *)(player + 0x18), &it);
        *(void **)(frameHeap + 0x34) = sound;
        {
            scratch.end = (u32)(frameHeap + 4); /* the heap's mutex */
            *(void **)((u8 *)sound + 4) = (void *)frameHeap;
            OSLockMutex((void *)scratch.end);
            FRAME_HEAP_CLEAR((void *)(frameHeap + 0x1C));
            OSUnlockMutex((void *)scratch.end);
        }
    }

}
    if (ambientInfo != 0) {
        if (ambientInfo != 0) {
            /* Copy the ambient arg out of the caller's block and let the sound
             * update it through the ambient callbacks. */
            void *arg = (*(AmbientArgAllocaterCallback **)(ambientInfo + 8))->detail_AllocAmbientArg(*(s32 *)(ambientInfo + 0x10));
            if (arg != 0) {
                memcpy(arg, (const void *)*(s32 *)(ambientInfo + 0xC), (u32)*(s32 *)(ambientInfo + 0x10));
                ATTACH_AMBIENT_ARG(sound, *(void ***)ambientInfo, *(s32 *)(ambientInfo + 4), *(void ***)(ambientInfo + 8), (s32)arg);
            }
        }
    }
    *(u8 *)((u8 *)sound + 0x74) = (u8)priority;
    *(s32 *)((u8 *)sound + 0x40) = ambientPriority;
    {
        /* Link the sound into the player's sound list (+0x00, node +0xC0). */
        void *it;
        scratch.end = player + 4;
        if (sound == 0) {
            PANIC((const char *)lbl_803262B8, 0x233, (const char *)lbl_80326294);
        }
        it = (void *)scratch.end;
        LIST_INSERT((void *)player, &it, (u8 *)sound + 0xC0);
    }
    *(s32 *)((u8 *)sound + 0x10) = player;
    if (externalPlayer != 0) {
        EXTERNAL_INSERT_SOUND((void *)externalPlayer, sound);
    }
    SoundPlayer_InsertPriorityList(player, sound);
#undef PANIC
#undef LIST_INSERT
#undef LIST_ERASE
#undef POOL_ALLOC
#undef NEW_STRM_SOUND
#undef CHECK_PLAYABLE
#undef EXTERNAL_INSERT_SOUND
#undef FRAME_HEAP_CLEAR
#undef ATTACH_AMBIENT_ARG
    return sound;
}
#pragma push
#pragma dont_inline off
#pragma auto_inline off
extern "C" const char lbl_80325F10[];
extern "C" const char lbl_80325F38[];
extern "C" const char lbl_80325F50[];
extern "C" const char lbl_80325F94[];
extern "C" void *fn_800F975C(s32 player, s32 priority, s32 requestedPriority, s32 ambientInfo, s32 externalPlayer, s32 soundId, void *manager) {
    /* detail::SoundInstanceManager::Alloc for wave sounds (SoundInstanceManager.h).
     * Takes a free WaveSound out of the instance pool; when the pool is full it
     * takes the sound with the lowest priority away from that list (stopping it
     * first) if the new sound outranks it, and gives up otherwise.  The new sound
     * is then built up: the player's first free frame heap, a copy of the ambient
     * arg with its update callback, its priority (+0x74) and ambient priority
     * offset (+0x40), and links into the manager's priority list (+0x4, node
     * +0xB8), the player's sound list (+0x00, node +0xC0), the player's priority
     * list (+0x0C, node +0xC8) and the external player's sound list.  Returns the
     * sound, or 0 when it could not be started.  fn_800F9200 does the same for
     * streaming sounds. */
#define PANIC Panic__Q26nw4hbm2dbFPCciPCce
#define LIST_INSERT Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListImpl8Iterator
#define LIST_ERASE Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator
#define POOL_ALLOC AllocImpl__Q44nw4r3snd6detail8PoolImplFv
#define NEW_WAVE_SOUND fn_800FFA10            /* WaveSound::WaveSound() */
#define CHECK_PLAYABLE CheckPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFiPQ46nw4hbm3snd6detail19ExternalSoundPlayer
#define EXTERNAL_INSERT_SOUND InsertSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound
#define FRAME_HEAP_CLEAR fn_800EC1A4          /* FrameHeap::Clear() */
#define ATTACH_AMBIENT_ARG fn_800E9B74
    union { s32 request; u32 end; } scratch; /* one register the original reused
                                                for the requested priority and for
                                                the list ends and node pointers */
    s32 ambientPriority;
    s32 listPriority;
    void *sound;

    if (manager == 0) {
        return 0;
    }
    scratch.request = requestedPriority;
    /* The ambient arg's callback hands out this sound's ambient priority, which
     * the sound itself carries as its priority offset. */
    ambientPriority = AmbientInfo_GetPriority(ambientInfo, soundId);
    listPriority = ClampS32(scratch.request - ambientPriority, 0, 127);
    if (CHECK_PLAYABLE((void *)player, listPriority, (void *)externalPlayer) == 0) {
        return 0;
    }
    { /* SoundInstanceManager::Alloc(listPriority), inlined. */

    sound = 0;
    void *it;
    struct { u32 old; } lock;
    u32 &irq = lock.old;
    struct { void *node; } iter;
    void *&pos = iter.node;

    {
        s32 ok = 0;
        if (listPriority >= 0 && listPriority <= 0x7F) {
            ok = 1;
        }
        if (ok == 0) {
            PANIC(lbl_80325F94, 0x5C, lbl_80325F50, listPriority, 0, 0x7F);
        }
    }
    lock.old = OSDisableInterrupts();
    void *freeSound = POOL_ALLOC(manager);
    if (freeSound != 0) {
        sound = freeSound;
        if (freeSound != 0) {
            sound = NEW_WAVE_SOUND(freeSound, manager);
        }
    } else {
        /* Pool empty: the priority list is sorted with the lowest priority in
         * front, so that is the only sound this one may take over. */
        u8 *node;
        u8 *lowest;
        if (*(s32 *)((u8 *)manager + 4) == 0) {
            OSRestoreInterrupts(irq);
            sound = 0;
            goto allocation_done;
        }
        if (*(s32 *)((u8 *)manager + 4) == 0) {
            PANIC(lbl_80325864, 0x1F1, lbl_80325840);
        }
        node = *(u8 **)((u8 *)manager + 8);
        if (node == 0) {
            PANIC(lbl_80325804, 0x23D, lbl_803257E0);
        }
        lowest = node - 0xB8; /* the sound its manager node (+0xB8) belongs to */
        if (lowest == 0) {
            PANIC(lbl_80325834, 0x193, lbl_80325810);
        }
        if (lowest == 0) {
            OSRestoreInterrupts(irq);
            sound = 0;
            goto allocation_done;
        }
        {
            /* BasicSound::CalcPriority_(): own priority (+0x74) plus offset (+0x40). */
            s32 lowestPrio = *(u8 *)(lowest + 0x74) + *(s32 *)(lowest + 0x40);
            s32 clamped = lowestPrio > 0x7F ? 0x7F : (lowestPrio < 0 ? 0 : lowestPrio);
            if (listPriority < clamped) {
                OSRestoreInterrupts(irq);
                sound = 0;
                goto allocation_done;
            }
        }
        ((BasicSoundVirtuals *)lowest)->Stop(0);
        freeSound = POOL_ALLOC(manager);
        sound = freeSound;
        if (freeSound == 0) {
            PANIC(lbl_80325F38, 0x72, lbl_80325F10);
        }
        if (sound != 0) {
            sound = NEW_WAVE_SOUND(sound, manager);
        }
    }
    /* Insert into the manager's priority-sorted list, in front of the first
     * sound that outranks this one. */
    pos = *(void **)((u8 *)manager + 8);
    scratch.end = (u32)manager + 8;
    while ((u32)pos != scratch.end) {
        if (pos == 0) {
            PANIC(lbl_80325804, 0x23D, lbl_803257E0);
        }
        if (listPriority < ClampS32(*(u8 *)((u8 *)pos - 0x44) + *(s32 *)((u8 *)pos - 0x78), 0, 0x7F)) {
            break;
        }
        pos = *(void **)pos;
    }
    if (sound == 0) {
        PANIC(lbl_803257D4, 0x233, lbl_803257B0);
    }
    it = pos;
    LIST_INSERT((u8 *)manager + 4, &it, (u8 *)sound + 0xB8);
    OSRestoreInterrupts(irq);

    }
allocation_done:
    if (sound == 0) {
        return 0;
    }
    { /* Give the sound the first frame heap still on the player's heap list. */

    if (*(s32 *)(player + 0x18) != 0) {
        u8 *frameHeap;

        s32 it;
        if (*(s32 *)(player + 0x18) == 0) {
            PANIC(lbl_80325E44, 0x1F1, lbl_80325E20);
        }
        scratch.end = *(s32 *)(player + 0x1C);
        if (scratch.end == 0) {
            PANIC(lbl_80325DE4, 0x23D, lbl_80325DC0);
        }
        frameHeap = (u8 *)(scratch.end - 0x2C); /* node of the heap's list entry */
        if (frameHeap == 0) {
            PANIC(lbl_80325E14, 0x193, lbl_80325DF0);
        }
        it = *(s32 *)((u8 *)(player + 0x18) + 4);
        LIST_ERASE((u8 *)(player + 0x18), &it);
        *(void **)(frameHeap + 0x34) = sound;
        {
            scratch.end = (u32)(frameHeap + 4); /* the heap's mutex */
            *(void **)((u8 *)sound + 4) = (void *)frameHeap;
            OSLockMutex((void *)scratch.end);
            FRAME_HEAP_CLEAR((void *)(frameHeap + 0x1C));
            OSUnlockMutex((void *)scratch.end);
        }
    }

}
    if (ambientInfo != 0) {
        if (ambientInfo != 0) {
            /* Copy the ambient arg out of the caller's block and let the sound
             * update it through the ambient callbacks. */
            void *arg = (*(AmbientArgAllocaterCallback **)(ambientInfo + 8))->detail_AllocAmbientArg(*(s32 *)(ambientInfo + 0x10));
            if (arg != 0) {
                memcpy(arg, (const void *)*(s32 *)(ambientInfo + 0xC), (u32)*(s32 *)(ambientInfo + 0x10));
                ATTACH_AMBIENT_ARG(sound, *(void ***)ambientInfo, *(s32 *)(ambientInfo + 4), *(void ***)(ambientInfo + 8), (s32)arg);
            }
        }
    }
    *(u8 *)((u8 *)sound + 0x74) = (u8)priority;
    *(s32 *)((u8 *)sound + 0x40) = ambientPriority;
    {
        /* Link the sound into the player's sound list (+0x00, node +0xC0). */
        void *it;
        scratch.end = player + 4;
        if (sound == 0) {
            PANIC((const char *)lbl_803262B8, 0x233, (const char *)lbl_80326294);
        }
        it = (void *)scratch.end;
        LIST_INSERT((void *)player, &it, (u8 *)sound + 0xC0);
    }
    *(s32 *)((u8 *)sound + 0x10) = player;
    if (externalPlayer != 0) {
        EXTERNAL_INSERT_SOUND((void *)externalPlayer, sound);
    }
    SoundPlayer_InsertPriorityList(player, sound);
#undef PANIC
#undef LIST_INSERT
#undef LIST_ERASE
#undef POOL_ALLOC
#undef NEW_WAVE_SOUND
#undef CHECK_PLAYABLE
#undef EXTERNAL_INSERT_SOUND
#undef FRAME_HEAP_CLEAR
#undef ATTACH_AMBIENT_ARG
    return sound;
}
#pragma pop
extern "C" void SetPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFi(void *self, s32 count) {
    struct SoundNode {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void Remove();
    };
    register u8 *message = lbl_80325C50;
    u8 *p = (u8 *)self;
    void *node;
    if (count < 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)message, 0x20F, (const char *)(message + 0x84));
    *(u16 *)(p + 0x24) = (u16)count;
    if (p[0x2D] != 0) {
        if ((u16)count > *(u16 *)(p + 0x26))
            Warning__Q26nw4hbm2dbFPCciPCce((const char *)message, 0x217, (const char *)(message + 0xA8));
        u16 current = *(u16 *)(p + 0x24);
        u16 maximum = *(u16 *)(p + 0x26);
        if (current > maximum)
            current = maximum;
        *(u16 *)(p + 0x24) = current;
    }
    while (*(s32 *)p > *(u16 *)(p + 0x24)) {
        if (*(void **)(p + 0x0C) == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803263A8, 0x1F1, lbl_80326384);
        node = *(void **)(p + 0x10);
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326348, 0x23D, lbl_80326324);
        node = (u8 *)node - 0xC8;
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326378, 0x193, lbl_80326354);
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)message, 0x220, (const char *)(message + 0xCC));
        ((SoundNode *)node)->Remove();
    }
}
#pragma pop
/* Sets the sound player's playable sound limit (stored as a u16 at offset 0x26), panicking if the limit is negative. */
extern "C" void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi(
    void* soundPlayer, s32 playableSoundLimit) {
    if (playableSoundLimit < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325C50, 0x227,
                                     (const char*)lbl_80325D48);
    }
    *(u16*)&((u8*)soundPlayer)[0x26] = (u16)playableSoundLimit;
}

extern "C" void *GetLowestPrioritySound__Q46nw4hbm3snd6detail19ExternalSoundPlayerFv(void *);
extern "C" const char lbl_803263A8[];
extern "C" const char lbl_80326384[];
extern "C" const char lbl_80326378[];
extern "C" const char lbl_80326354[];
#pragma use_lmw_stmw off
extern "C" int CheckPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFiPQ46nw4hbm3snd6detail19ExternalSoundPlayer(void *self, int priority, void *external) {
    int limit;
    if (*(u16 *)((u8 *)self + 0x24) == 0)
        return 0;
    while (*(s32 *)self >= *(u16 *)((u8 *)self + 0x24)) {
        u8 *sound;
        if (*(s32 *)((u8 *)self + 0xC) == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803263A8, 0x1F1, lbl_80326384);
        {
            u8 *first = *(u8 **)((u8 *)self + 0x10);
            u8 *obj;
            if (first == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326348, 0x23D, lbl_80326324);
            obj = first - 0xC8;
            if (obj == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326378, 0x193, lbl_80326354);
            sound = obj;
        }
        if (sound == 0)
            return 0;
        limit = sound[0x74] + *(s32 *)(sound + 0x40);
        limit = (limit > 0x7F) ? 0x7F : ((limit < 0) ? 0 : limit);
        if (priority < limit)
            return 0;
        ((DummyCheckPlayable *)sound)->f7();
    }
    if (external != 0) {
        if (*(u16 *)((u8 *)external + 0xC) == 0)
            return 0;
        while (*(s32 *)external >= *(u16 *)((u8 *)external + 0xC)) {
            u8 *sound = (u8 *)GetLowestPrioritySound__Q46nw4hbm3snd6detail19ExternalSoundPlayerFv(external);
            if (sound == 0)
                return 0;
            limit = sound[0x74] + *(s32 *)(sound + 0x40);
            limit = (limit > 0x7F) ? 0x7F : ((limit < 0) ? 0 : limit);
            if (priority < limit)
                return 0;
            ((DummyCheckPlayable *)sound)->f7();
        }
    }
    return 1;
}
extern "C" void detail_AppendPlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10PlayerHeap(void *player, void *heap) {
    /* Append a PlayerHeap to the SoundPlayer's heap list and mark the player
       as having a heap attached. */
    register void *insertIterator;
    void *iteratorSlot;

    if (!heap) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x256, (const char *)lbl_80325D6C);
    *(void **)((u8 *)heap + 0x38) = player;
    insertIterator = (char *)player + 0x1C;
    if (!heap) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80323834, 0x233, (const char *)lbl_80323810);
    iteratorSlot = insertIterator;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)player + 0x18, &iteratorSlot, (char *)heap + 0x2C);
    *(u8 *)((u8 *)player + 0x2D) = 1;
}

// nw4hbm::ut::LinkListNode: one node of the library's intrusive doubly linked
// list.  A LinkList's own head is the sentinel the real nodes hang on, so the
// first node is sentinel.next and the last sentinel.prev.
struct UtLinkListNode {
    UtLinkListNode *next; /* 0x00 towards the back of the list */
    UtLinkListNode *prev; /* 0x04 towards the front */
};
// nw4hbm::ut::LinkList: how many nodes are on the list, and that sentinel.
struct UtLinkList {
    u32 size;             /* 0x00 */
    UtLinkListNode sentinel; /* 0x04 */
};
// nw4hbm::snd::SoundPlayer, as far as the player-heap handling sees it.
struct SoundPlayerLayout {
    u8 pad_00[0x18];
    UtLinkList heapList; /* 0x18 the PlayerHeaps detail_AppendPlayerHeap added */
};
// nw4hbm::snd::detail::PlayerHeap: the block of memory a SoundPlayer hands out
// to the sounds it plays.  Only the fields the player-heap handling touches.
struct PlayerHeapLayout {
    u8 pad_00[0x2C];
    UtLinkListNode link; /* 0x2C its place in the player's heap list */
    void *holder;        /* 0x34 cleared when the heap goes back to that list */
    void *ownerPlayer;   /* 0x38 the player that appended the heap */
};
// nw4hbm::snd::detail::BasicSound, as far as the player-heap handling sees it.
struct BasicSoundLayout {
    void *vtable;                  /* 0x00 */
    PlayerHeapLayout *playerHeap;  /* 0x04 the heap its memory came from, if any */
};
// The file names and messages the NW4HBM_ASSERTs here and in the inlined
// nw4hbm::ut::LinkList::insert hand to nw4hbm::db::Panic.
#define SND_SOUNDPLAYER_CPP ((const char *)lbl_80325C50) /* "snd_SoundPlayer.cpp" */
#define SND_PTR_SOUND_MSG   ((const char *)lbl_80325D98) /* "NW4HBM:Pointer must not be NULL (sound)" */
#define UT_LINKLIST_H       ((const char *)lbl_80323834) /* "LinkList.h" */
#define UT_PTR_P_MSG        ((const char *)lbl_80323810) /* "NW4HBM:Pointer must not be NULL (p)" */
extern "C" void detail_FreePlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(SoundPlayerLayout *player, BasicSoundLayout *sound) {
    UtLinkListNode **iterator;
    PlayerHeapLayout *heap;
    void *slot;

    /* nw4hbm::snd::SoundPlayer::detail_FreePlayerHeap(BasicSound*): hand the
     * heap a sound was made on back to its player.  The heap goes on the front
     * of the player's heap list, is detached from whoever held it, and the
     * sound forgets about it. */
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(SND_SOUNDPLAYER_CPP, 0x280, SND_PTR_SOUND_MSG);
    }
    heap = sound->playerHeap;
    if (heap != 0) {
        /* nw4hbm::ut::LinkList::begin(), and the NW4HBM_ASSERT(p != NULL) of
         * the inlined nw4hbm::ut::LinkList::insert. */
        iterator = &player->heapList.sentinel.next;
        if (heap == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(UT_LINKLIST_H, 0x233, UT_PTR_P_MSG);
        }
        slot = iterator;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(&player->heapList, &slot, &heap->link);
    }
    if (heap != 0) {
        heap->holder = 0;
    }
    sound->playerHeap = 0;
}

extern "C" void* detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(void* startable, void* soundHandle, unsigned long soundId, void* ambientArgInfo, void* externalPlayer, void* startInfo) {
    /* Starts a sound via the startable; on failure, if the handle holds a sound, attaches it and returns null. */
    struct StartableVTable {
        virtual void d0();
        virtual void* Start(void*, unsigned long, void*, void*, int, void*);
    };
    struct SoundVTable {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void Attach();
    };
    void* startedSound = ((StartableVTable*)startable)->Start(soundHandle, soundId, ambientArgInfo, externalPlayer, 0, startInfo);
    if (startedSound) {
        return startedSound;
    }
    void* handleSound = *(void**)soundHandle;
    if (handleSound) {
        ((SoundVTable*)handleSound)->Attach();
    }
    return 0;
}

extern "C" void fn_800E2E24(void);
extern "C" s32 SCInit(void);
extern "C" u32 SCCheckStatus(void);
extern "C" u8 SCGetSoundMode(void);
extern "C" void SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(s32);
extern "C" void Setup__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv(void);
extern "C" s32 Create__Q46nw4hbm3snd6detail10TaskThreadFl(s32);
extern "C" s32 fn_800FA4C4(void *, s32);
extern "C" s32 OSCreateThread(void *, void *, void *, void *, u32, s32, u32);
extern "C" void OSInitThreadQueue(void *);
extern "C" void OSResumeThread(void *);
extern "C" s32 fn_800FA77C(s32);
extern "C" const char lbl_80326450[];
extern "C" const char lbl_80326464[];
extern "C" void InitSoundSystem__Q36nw4hbm3snd11SoundSystemFll(s32 arg0, s32 arg1) {
    register const char *labels = (const char *)lbl_803263B8;
    u32 status;
    u8 mode;
    if (lbl_8055DE60 != 0) return;
    lbl_8055DE60 = 1;
    Instance__15EmissionManagerFv();
    fn_800E2E24();
    SCInit();
    do { status = SCCheckStatus(); } while (status == 1);
    if (status != 0) Panic__Q26nw4hbm2dbFPCciPCce(labels, 0x4f, labels + 0x14);
    mode = SCGetSoundMode();
    switch (mode) {
    case 0: ((void (*)(void *, s32))SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode)(Instance__15EmissionManagerFv(), 3); break;
    case 1: ((void (*)(void *, s32))SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode)(Instance__15EmissionManagerFv(), 0); break;
    case 2: ((void (*)(void *, s32))SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode)(Instance__15EmissionManagerFv(), 2); break;
    default: ((void (*)(void *, s32))SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode)(Instance__15EmissionManagerFv(), 0); break;
    }
    GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
    Setup__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
    if (((s32 (*)(void *, s32))Create__Q46nw4hbm3snd6detail10TaskThreadFl)(fn_800FE648(), arg1) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(labels, 0x7e, labels + 0x48);
    if (fn_800FA4C4(GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv(), arg0) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(labels, 0x82, labels + 0x48);
}

extern "C" void fn_800FA350(void) {
    void *instance;

    /* Shut down nw4hbm sound system subsystems if initialized. */
    if (lbl_8055DE60 != 0) {
        GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv();
        if (Shutdown__Q46nw4hbm3snd6detail11SoundThreadFv() == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803263B8, 0x8D,
                                         (const char *)lbl_80326400);
        }

        fn_800FE648();
        if (Destroy__Q46nw4hbm3snd6detail10TaskThreadFv() == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803263B8, 0x91,
                                         (const char *)lbl_80326400);
        }

        instance = GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
        fn_800EEB64(instance);

        instance = Instance__15EmissionManagerFv();
        fn_800E2F84(instance);

        lbl_8055DE60 = 0;
    }
}

#pragma push
#pragma scheduling on
extern "C" void* GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv(void) {
    if ((s8)lbl_8055DE68 == 0) {
        volatile u32 *base = (volatile u32 *)lbl_80412CC8;
        base[0x2388 / 4] = 0;
        void *object = (void *)((u8 *)base + 0x2388);
        base[0x238c / 4] = 0;
        base[0x2378 / 4] = 0;
        base[0x237c / 4] = 0;
        base[0x2384 / 4] = 0;
        base[0x2388 / 4] = (u32)object;
        base[0x238c / 4] = (u32)object;
        ((volatile u8 *)base)[0x2394] = 0;
        __register_global_object((void *)base, (void *)&__dt__10TitleSceneFv,
                                 (void *)(u32)&lbl_80412CB8, object);
        lbl_8055DE68 = 1;
    }
    return (void *)lbl_80412CC8;
}
#pragma pop
// TitleScene destructor: destroys embedded nw4hbm::ut::detail::LinkListImpl at +0x2384,
// then frees this object when flag > 0 (operator delete).
extern "C" void* __dt__10TitleSceneFv(void* this_, s32 flag) {
    if (this_) {
        if ((u8*)this_ + 0x2384 != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8*)this_ + 0x2384, 0);
        }
        if (flag > 0) {
            ((s32 (*)(void*))fn_80128668)(this_);
        }
    }
    return this_;
}

#pragma processor 750
extern "C" s32 fn_800FA4C4(void *arg0, s32 arg1) {
    s32 result;
    u8 *thread = (u8 *)arg0;
    register const void *label;

    if (thread[0x2394] != 0) {
        return 1;
    }
    thread[0x2394] = 1;
    if (((u8 *)Instance__15EmissionManagerFv())[0x6c30] == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326450, 0x44, lbl_80326464);
    }
    OSInitThreadQueue(thread + 0x2318);
    OSInitMutex(thread + 0x2320);
    if ((s8)lbl_8055DE68 == 0) {
        volatile u32 *base = (volatile u32 *)lbl_80412CC8;
        register void *dtor = (void *)__dt__10TitleSceneFv;
        base[0x2388 / 4] = 0;
        register void *object = (void *)((u8 *)base + 0x2388);
        base[0x238c / 4] = 0;
        base[0x2378 / 4] = 0;
        base[0x237c / 4] = 0;
        base[0x2384 / 4] = 0;
        base[0x2388 / 4] = (u32)object;
        base[0x238c / 4] = (u32)object;
        ((volatile u8 *)base)[0x2394] = 0;
        label = (const void *)&lbl_80412CB8;
        __register_global_object((void *)base, dtor, (void *)label, object);
        lbl_8055DE68 = 1;
    }
    result = OSCreateThread(arg0, (void *)fn_800FA77C, (void *)lbl_80412CC8,
                            thread + 0x2318, 0x2000, arg1, 0);
    if (result != 0) {
        OSResumeThread(arg0);
    }
    return result != 0;
}
s32 nw4hbm::snd::detail::SoundThread::Shutdown() {
    u8 *thread = (u8 *)this;
    if (*(u8 *)(thread + 0x2394) == 0)
        return 0;
    if ((s8)lbl_8055DE68 == 0) {
        volatile u32 *base = (volatile u32 *)lbl_80412CC8;
        register void *dtor = (void *)__dt__10TitleSceneFv;
        base[0x2388 / 4] = 0;
        register void *object = (void *)((u8 *)base + 0x2388);
        base[0x238C / 4] = 0;
        base[0x2378 / 4] = 0;
        base[0x237C / 4] = 0;
        base[0x2384 / 4] = 0;
        base[0x2388 / 4] = (u32)object;
        base[0x238C / 4] = (u32)object;
        ((volatile u8 *)base)[0x2394] = 0;
        __register_global_object((void *)base, dtor, (void *)&lbl_80412CB8, object);
        lbl_8055DE68 = 1;
    }
    if (OSSendMessage((u8 *)lbl_80412CC8 + 0x2338, (void *)2, 0x0) == 0)
        return 0;
    if (OSJoinThread((void *)thread, 0) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326450, 0x70, lbl_80326488);
    *(u8 *)(thread + 0x2394) = 0;
    return 1;
}

#pragma pop
extern "C" s32 OSJoinThread(void *, s32);
extern "C" const char lbl_80326450[];
extern "C" const char lbl_80326488[];
extern "C" void Shutdown__Q36nw4hbm3snd18SoundArchivePlayerFv(void *self) {
    /* Shut down nw4hbm SoundArchivePlayer: clear archive/source pointers
       (+0x10,+0x14,+0x6C), destroy all SoundPlayer instances in array at
       (+0x74, count +0x70, stride 0x48) via __dt__Q36nw4hbm3snd11SoundPlayerFv,
       reset subobject at +0xA8 (fn_800FA9E8), destroy pool impls at +0x78/+0x88/
       +0x98 from buffer (+0xD0,size +0xD4) with Panic if null (SoundInstance-
       Manager.h "Pointer must not be NULL (buffer)"), tear down +0xC4 via
       fn_800EE434, and clear buffer/size. */
    u8 *obj = (u8 *)self;
    *(u32 *)(obj + 0x10) = 0;
    *(u32 *)(obj + 0x14) = 0;
    *(u32 *)(obj + 0x6C) = 0;
    u32 offset = 0;
    u32 count = 0;
    while (count < *(u32 *)(obj + 0x70)) {
        u8 *players = (u8 *)*(void **)(obj + 0x74);
        __dt__Q36nw4hbm3snd11SoundPlayerFv(players + offset, -1);
        offset += 0x48;
        count++;
    }
    *(u32 *)(obj + 0x70) = 0;
    *(void **)(obj + 0x74) = 0;
    fn_800FA9E8(obj + 0xA8);
    register u32 poolSize = *(volatile u32 *)(obj + 0xD4);
    register void *pool = *(void **)(obj + 0xD0);
    if (pool == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325B70, 0x4C, lbl_80325B44);
    DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(obj + 0x78, pool, poolSize);
    poolSize = *(volatile u32 *)(obj + 0xD4);
    pool = *(void **)(obj + 0xD0);
    if (pool == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325B2C, 0x4C, lbl_80325B00);
    DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(obj + 0x88, pool, poolSize);
    poolSize = *(volatile u32 *)(obj + 0xD4);
    pool = *(void **)(obj + 0xD0);
    if (pool == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325AE8, 0x4C, lbl_80325ABC);
    DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(obj + 0x98, pool, poolSize);
    fn_800EE434(obj + 0xC4, *(void **)(obj + 0xD0), *(u32 *)(obj + 0xD4));
    *(u32 *)(obj + 0xD0) = 0;
    *(u32 *)(obj + 0xD4) = 0;
}

extern "C" void fn_800FA6E8(void) {
    if ((s8)lbl_8055DE68 == 0) {
        volatile u32* base = (volatile u32*)lbl_80412CC8;
        u32* self = (u32*)&lbl_80412CC8[0x2388];
        base[0x2388 / 4] = 0;
        u32* ptr = (u32*)&base[0x2388 / 4];
        base[0x238c / 4] = 0;
        base[0x2378 / 4] = 0;
        base[0x237c / 4] = 0;
        base[0x2384 / 4] = 0;
        base[0x2388 / 4] = (u32)ptr;
        base[0x238c / 4] = (u32)ptr;
        ((volatile u8*)base)[0x2394] = 0;
        __register_global_object(self, (void*)&__dt__10TitleSceneFv,
                                 (void*)&lbl_80412CB8, self);
        lbl_8055DE68 = 1;
    }
    OSSendMessage((void*)&lbl_80412CC8[0x2338], (void*)1, 0);
    detail_UpdateBufferAllPlayers__Q36nw4hbm3snd10WavePlayerFv();
    UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv();
}

extern "C" s32 fn_800FA77C(s32 arg0) {
    /* Sound thread entry: set up message queue and AX callback, run thread loop, then clean up. */
    OSInitMessageQueue((void*)(arg0 + 0x2338), (void*)(arg0 + 0x2358), 8);
    void* manager = Instance__15EmissionManagerFv();
    RegisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNodePFv_v(
        manager, (void*)(arg0 + 0x2378), fn_800FA6E8);
    fn_800FA7E0((void*)arg0);
    manager = Instance__15EmissionManagerFv();
    UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(
        manager, (void*)(arg0 + 0x2378));
    return 0;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 OSReceiveMessage(void *, void *, s32);
extern "C" u32 OSGetTick(void);
extern "C" void fn_800E3228(void);
extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv(void);
extern "C" void fn_80101130(void);
extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC490(void);
extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FF824(void);
extern "C" void UpdateAllChannel__Q46nw4hbm3snd6detail7ChannelFv(void);
extern "C" u32 fn_800FEB9C(void);
extern "C" void UpdateAllVoices__Q46nw4hbm3snd6detail9AxManagerFv(void);
extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv(void);
extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_80101300(void);
extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC508(void);
extern "C" void detail_StopAllPlayers__Q36nw4hbm3snd10WavePlayerFv(void);
extern "C" const char lbl_803264AC[];
extern "C" const char lbl_803264D0[];
extern "C" void fn_800FA7E0(void *self) {
    unsigned long message;
    unsigned long state;
    u8 *p = (u8 *)self;
    for (;;) {
        OSReceiveMessage(p + 0x2338, &message, 1);
        if (message == 1) {
            void *mutex = p + 0x2320;
            OSLockMutex(mutex);
            unsigned long tick = OSGetTick();
            Instance__15EmissionManagerFv();
            fn_800E3228();
            UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv();
            fn_80101130();
            UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC490();
            UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FF824();
            {
                LinkListIter begin;
                begin.node = *(void **)(p + 0x2388);
                LinkListIter it = begin;
                while (it.node != (void *)(p + 0x2388)) {
                    DummyWorkerLink *node = (DummyWorkerLink *)it.node;
                    it.node = *(void **)it.node;
                    if (node == 0)
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803264D0, 0x23D, lbl_803264AC);
                    ((DummyWorkerCallbackC *)node)->Call();
                }
            }
            UpdateAllChannel__Q46nw4hbm3snd6detail7ChannelFv();
            fn_800FEB9C();
            state = OSDisableInterrupts();
            Instance__15EmissionManagerFv();
            UpdateAllVoices__Q46nw4hbm3snd6detail9AxManagerFv();
            OSRestoreInterrupts(state);
            *(u32 *)(p + 0x2390) = OSGetTick() - tick;
            {
                LinkListIter begin;
                begin.node = *(void **)(p + 0x2388);
                LinkListIter it = begin;
                while ((void *)(p + 0x2388) != it.node) {
                    DummyWorkerLink *node = (DummyWorkerLink *)it.node;
                    it.node = *(void **)it.node;
                    if (node == 0)
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803264D0, 0x23D, lbl_803264AC);
                    ((DummyWorkerCallback10 *)node)->Call();
                }
            }
            OSUnlockMutex(mutex);
        } else if (message == 2) {
            StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv();
            StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_80101300();
            StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC508();
            detail_StopAllPlayers__Q36nw4hbm3snd10WavePlayerFv();
            return;
        }
    }
}
#pragma pop

#pragma use_lmw_stmw off
/* Initialize a StrmBufferPool with a backing buffer split into `count` equal blocks.
 * Stores buffer, total size, block size, block count, alloc bitmap/index base, and
 * panics if count exceeds 32 (bitmap capacity). */
extern "C" void Setup__Q46nw4hbm3snd6detail14StrmBufferPoolFPvUli(void *this_, void *buffer, u32 size, s32 count) {
    if (count != 0) {
        u32 savedInterrupts = OSDisableInterrupts();
        *(void **)this_ = buffer;
        *(u32 *)((u8 *)this_ + 4) = size;
        *(u32 *)((u8 *)this_ + 8) = size / (u32)count;
        *(u32 *)((u8 *)this_ + 0xC) = (u32)count;
        *(u32 *)((u8 *)this_ + 0x10) = 0;
        memset((u8 *)this_ + 0x14, 0, 4);
        if (*(s32 *)((u8 *)this_ + 0xC) > 0x20) {
            extern const char lbl_803264E0[];
            extern const char lbl_803264F4[];
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803264E0, 0x2A, lbl_803264F4);
        }
        OSRestoreInterrupts(savedInterrupts);
    }
}
#pragma use_lmw_stmw reset
extern "C" void fn_800FA9E8(void* arg0) {
    /* RealName: ResetSoundSubobjectQueue (clears a 0x10-byte queue/state subobject under interrupt disable). */
    u32 interruptLevel = OSDisableInterrupts();
    *(s32*)arg0 = 0;
    *(s32*)((u8*)arg0 + 4) = 0;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    OSRestoreInterrupts(interruptLevel);
}

extern "C" void *Alloc__Q44nw4r3snd6detail14StrmBufferPoolFv(void *arg0) {
    struct StrmBufferPoolView {
        void *buffer;
        u32 bufferSize;
        u32 stride;
        s32 capacity;
        s32 used;
        u8 bits[32];
    };
    register StrmBufferPoolView *pool = (StrmBufferPoolView *)arg0;
    u32 interruptState = OSDisableInterrupts();
    s32 capacity = pool->capacity;
    s32 used = pool->used;
    u8 value;
    if (used >= capacity) {
        OSRestoreInterrupts(interruptState);
        return 0;
    }
    s32 numBytes = ((capacity + 7) & ~7) / 8;
    for (s32 i = 0; i < numBytes; ++i) {
        value = pool->bits[i];
        if (value != 0xFF) {
            u8 mask = 1;
            for (s32 bit = 0; bit < 8; ++bit) {
                if ((value & mask) == 0) {
                    pool->bits[i] |= mask;
                    pool->used++;
                    u32 offset = pool->stride * (bit + (i << 3));
                    void *result = (void *)((u32)pool->buffer + offset);
                    OSRestoreInterrupts(interruptState);
                    return result;
                }
                mask <<= 1;
            }
        }
    }
    OSRestoreInterrupts(interruptState);
    return 0;
}

extern "C" void Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(void *self, void *ptr) __attribute__((noinline)) {
    /* Return one stream buffer block to the pool's allocation bitmap. */
    u32 savedInterruptState = OSDisableInterrupts();
    u32 blockIndex = ((u8 *)ptr - (u8 *)*(void **)self) / *(u32 *)((u8 *)self + 8);
    u8 *bitmapByte = (u8 *)self + (blockIndex >> 3);
    *(u8 *)(bitmapByte + 0x14) &= ~(1 << (blockIndex & 7));
    *(s32 *)((u8 *)self + 0x10) -= 1;
    OSRestoreInterrupts(savedInterruptState);
}

extern "C" void NWC24Data_Init(void* data) {
    /* Clear a two-word header (valid flag and ref pointer) to zero. */
    *(int*)data = 0;
    *((int*)data + 1) = 0;
}

extern "C" const char lbl_80326518[];
extern "C" const char lbl_80326688[];
extern "C" const char lbl_80326738[];
extern "C" char lbl_805598F8;
#pragma scheduling on
extern "C" s32 fn_800FAB98(void *arg0, void *arg1) {
    void *base = arg0;
    void *ref;
    void *data;
    if (*(s32 *)base == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326518, 0x89, lbl_80326688);
    ref = *(void **)((u8 *)base + 4);
    ref = (u8 *)ref + 8;
    if (*((u8 *)ref + 1) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F8, 0x6F, lbl_80326738);
    data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*(u8 *)ref, *(u32 *)((u8 *)ref + 4), ref);
    *(u8 *)((u8 *)arg1 + 0) = *((u8 *)data + 0);
    *(u8 *)((u8 *)arg1 + 1) = *((u8 *)data + 1);
    *(u8 *)((u8 *)arg1 + 2) = *((u8 *)data + 2);
    *(u32 *)((u8 *)arg1 + 4) = ((u32)*((u8 *)data + 3) << 16) + *(u16 *)((u8 *)data + 4);
    *(u16 *)((u8 *)arg1 + 8) = *(u16 *)((u8 *)data + 6);
    *(u32 *)((u8 *)arg1 + 0xC) = *(u32 *)((u8 *)data + 8);
    *(u32 *)((u8 *)arg1 + 0x10) = *(u32 *)((u8 *)data + 0xC);
    *(u32 *)((u8 *)arg1 + 0x14) = *(u32 *)((u8 *)data + 0x10);
    *(u32 *)((u8 *)arg1 + 0x18) = *(u32 *)((u8 *)data + 0x14);
    *(u32 *)((u8 *)arg1 + 0x1C) = *(u32 *)((u8 *)data + 0x18);
    *(u32 *)((u8 *)arg1 + 0x20) = *(u32 *)((u8 *)data + 0x1C);
    *(u32 *)((u8 *)arg1 + 0x24) = *(u32 *)((u8 *)data + 0x20);
    *(u32 *)((u8 *)arg1 + 0x28) = *(u32 *)((u8 *)data + 0x24);
    *(u32 *)((u8 *)arg1 + 0x2C) = *(u32 *)((u8 *)data + 0x28);
    *(u32 *)((u8 *)arg1 + 0x30) = *(u32 *)((u8 *)data + 0x2C);
    *(u32 *)((u8 *)arg1 + 0x34) = *(u32 *)((u8 *)data + 0x30);
    return 1;
}
extern "C" const char lbl_803266B4[];
extern "C" const char lbl_803266E0[];
extern "C" const char lbl_8032670C[];
extern "C" char lbl_805598E0;
extern "C" char lbl_805598E8;
extern "C" char lbl_805598F0;
/* nw4hbm::snd::detail::Util::DataRef: how a sound file's blocks point at their
 * data.  The RefType byte says how the id is to be read; the library only ever
 * accepts dataType 0, a plain address (DBAssert(ref.dataType == 0)). */
struct DataRef {
    u8 type;
    u8 dataType;
    u8 pad[2];
    u32 refID;
};

/* nw4hbm::snd::detail::StrmFile, as this unit uses it: the header the file was
 * opened with (asserted to be there) and the HEAD block, whose DataRefs at
 * +0x08 (stream info) and +0x18 (ADPCM parameter table) reach its data. */
struct StrmFile {
    void *mHeader;
    void *mHeadBlock;
};

/* One stream's ADPCM parameters, the block copied out per stream. */
struct AdpcmParam {
    u16 data[24];
};

/* the stream-info block's codec byte: 2 is the ADPCM codec */
enum { STRM_CODEC_ADPCM = 2 };

#pragma use_lmw_stmw off

/* nw4hbm::snd::detail::StrmFile (snd_StrmFile.cpp): copy the 0x30-byte ADPCM
 * parameter block of stream `index` of an opened .strm file into `arg1`.  The
 * HEAD block reaches the stream-info byte and the table of per-stream
 * parameter refs through Util::DataRefs, which the library requires to be
 * plain addresses (the DBAssert(ref.dataType == 0) checks below).  Nothing is
 * copied, and 0 is returned, when the file's codec is not the ADPCM one or the
 * index is past the end of the table. */
extern "C" s32 fn_800FACC0(void *arg0, void *arg1, s32 index) {
    if (*(void **)arg0 == 0) /* DBAssert(mHeader != NULL) */
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326518, 0xAD, lbl_80326688);
    u8 *block = (u8 *)*((void **)arg0 + 1);
    u8 *refBase = block + 8;
    if (block[9] != 0) /* the stream-info ref has to be a plain address */
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F8, 0x6F, lbl_80326738);
    u8 *codec = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(refBase[0], *(u32 *)(refBase + 4), refBase);
    if (*codec != STRM_CODEC_ADPCM)
        return 0;
    u8 *block2 = (u8 *)*((void **)arg0 + 1);
    u8 *refBase2 = block2 + 8;
    if (block2[0x19] != 0) /* the parameter-table ref, likewise */
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598E0, 0x6F, lbl_803266B4);
    u8 *table = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(block2[0x18], *(u32 *)(block2 + 0x1C), refBase2);
    if (index >= *table) /* the table's first byte counts the streams */
        return 0;
    index *= 8; /* eight bytes per entry, holding a DataRef at +4 */
    block = (u8 *)*((void **)arg0 + 1);
    refBase = block + 8;
    if ((table + index)[5] != 0) /* the entry's ref, likewise */
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598E8, 0x6F, lbl_803266E0);
    u8 *entry = table + index;
    u8 *paramRef = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[4], *(u32 *)(entry + 8), refBase);
    block2 = (u8 *)*((void **)arg0 + 1);
    refBase2 = block2 + 8;
    if (paramRef[1] != 0) /* the parameter ref the entry refers to, likewise */
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F0, 0x6F, lbl_8032670C);
    void *param = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(paramRef[0], *(u32 *)(paramRef + 4), refBase2);
    AdpcmParam *dst = (AdpcmParam *)arg1;
    const AdpcmParam *src = (const AdpcmParam *)param;
    u16 w0, w1;
    w0 = src->data[0]; w1 = src->data[1]; dst->data[0] = w0; dst->data[1] = w1;
    w0 = src->data[2]; w1 = src->data[3]; dst->data[2] = w0; dst->data[3] = w1;
    w0 = src->data[4]; w1 = src->data[5]; dst->data[4] = w0; dst->data[5] = w1;
    w0 = src->data[6]; w1 = src->data[7]; dst->data[6] = w0; dst->data[7] = w1;
    w0 = src->data[8]; w1 = src->data[9]; dst->data[8] = w0; dst->data[9] = w1;
    w0 = src->data[10]; w1 = src->data[11]; dst->data[10] = w0; dst->data[11] = w1;
    w0 = src->data[12]; w1 = src->data[13]; dst->data[12] = w0; dst->data[13] = w1;
    w0 = src->data[14]; w1 = src->data[15]; dst->data[14] = w0; dst->data[15] = w1;
    w0 = src->data[16]; w1 = src->data[17]; dst->data[16] = w0; dst->data[17] = w1;
    w0 = src->data[18]; w1 = src->data[19]; dst->data[18] = w0; dst->data[19] = w1;
    w0 = src->data[20]; dst->data[20] = w0;
    w1 = src->data[21]; dst->data[21] = w1;
    w0 = src->data[22]; dst->data[22] = w0;
    w1 = src->data[23]; dst->data[23] = w1;
    return 1;
}
#pragma use_lmw_stmw reset
extern "C" s32 fn_800FAF10(void *arg0, void *arg1, u32 arg2, s32 arg3) {
    struct DummyStream {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual u32 f3(void *, u32);
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15(s32, s32, s32);
    };
    const char *file = lbl_80326518;
    u8 buf[0x5F];
    s32 *temp_r3_5;
    s32 *temp_r3_6;
    s32 temp_r30;
    s32 temp_r6;
    u16 temp_r0;
    u16 temp_r0_2;
    u32 temp_r4;
    u32 temp_r4_2;
    u32 temp_r29;
    u32 var_r0;
    u32 var_r0_2;
    u8 *temp_r27;
    (*(DummyStream **)arg0)->f15(0, 0, arg3);
    temp_r30 = (s32)(buf + 31) & 0xFFFFFFE0;
    if (0x40U != (*(DummyStream **)arg0)->f3((void *)temp_r30, 0x40)) {
        return 0;
    }
    if (temp_r30 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x2B, file + 0x14);
    }
    if (*(volatile u32 *)temp_r30 != 0x5253544DU) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x31, file + 0x40);
    }
    if (*(volatile u32 *)temp_r30 != 0x5253544DU) {
        var_r0 = 0;
    } else {
        if (*(volatile u16 *)(temp_r30 + 6) < 0x100U) {
            Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x39, file + 0x8C);
        }
        temp_r0 = *(volatile u16 *)(temp_r30 + 6);
        if (temp_r0 < 0x100U) {
            var_r0 = 0;
        } else {
            if (temp_r0 > 0x100U) {
                Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x3F, file + 0x8C);
            }
            temp_r4 = *(volatile u16 *)(temp_r30 + 6);
            var_r0 = (u32)(~(temp_r4 & ~0x100U) - ((0x100U - temp_r4) >> 1)) >> 0x1FU;
        }
    }
    if ((s32)var_r0 == 0) {
        return 0;
    }
    if (*(volatile u32 *)(temp_r30 + 0x18) > arg2) {
        return 0;
    }
    temp_r6 = *(s32 *)(temp_r30 + 0x10);
    temp_r29 = temp_r6 + *(s32 *)(temp_r30 + 0x14);
    (*(DummyStream **)arg0)->f15(0, 0, temp_r6);
    if ((*(DummyStream **)arg0)->f3(arg1, temp_r29) != temp_r29) {
        return 0;
    }
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x5F, file + 0x14);
    }
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x2B, file + 0x14);
    }
    if (*(volatile u32 *)arg1 != 0x5253544DU) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x31, file + 0x40);
    }
    if (*(volatile u32 *)arg1 != 0x5253544DU) {
        var_r0_2 = 0;
    } else {
        if (*(volatile u16 *)((char *)arg1 + 6) < 0x100U) {
            Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x39, file + 0x8C);
        }
        temp_r0_2 = *(volatile u16 *)((char *)arg1 + 6);
        if (temp_r0_2 < 0x100U) {
            var_r0_2 = 0;
        } else {
            if (temp_r0_2 > 0x100U) {
                Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x3F, file + 0x8C);
            }
            temp_r4_2 = *(volatile u16 *)((char *)arg1 + 6);
            var_r0_2 = (u32)(~(temp_r4_2 & ~0x100U) - ((0x100U - temp_r4_2) >> 1)) >> 0x1FU;
        }
    }
    if ((s32)var_r0_2 == 0) {
        return 0;
    }
    *(void **)((char *)arg0 + 4) = arg1;
    temp_r3_5 = (s32 *)((u8 *)arg1 + *(s32 *)((char *)arg1 + 0x10));
    *(s32 **)((char *)arg0 + 8) = temp_r3_5;
    if (*(volatile u32 *)temp_r3_5 != 0x48454144U) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x68, file + 0xE4);
    }
    temp_r3_6 = *(s32 **)((char *)arg0 + 8);
    temp_r27 = (u8 *)temp_r3_6 + 8;
    if (*(volatile u8 *)((char *)temp_r3_6 + 9) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F8, 0x6F, lbl_80326738);
    }
    if ((*(u32 *)((char *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*temp_r27, *(u32 *)(temp_r27 + 4), temp_r27) + 0x18) & 0x1F) == 0) {
        return 0;
    }
    Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x6C, file + 0x13C);
    return 1;
}

extern "C" void fn_8002F53C(void *, void *, void *, int, int);
#pragma push
#pragma use_lmw_stmw off
extern "C" void * __ct__Q46nw4hbm3snd6detail10StrmPlayerFv(void *arg0) {
    u8 *p = (u8 *)arg0;
    volatile u32 *vp = (volatile u32 *)p;
    u32 zero = 0;
    void *it;
    void *head0 = p + 0x98;
    void *tail = p + 0xa4;
    vp[0x98 / 4] = zero;
    vp[0x9c / 4] = zero;
    vp[0xa4 / 4] = zero;
    vp[0xa8 / 4] = zero;
    vp[1] = -1;
    vp[0] = (u32)lbl_80326A28;
    vp[2] = zero;
    vp[3] = zero;
    *(volatile u8 *)(p + 0x48) = 0;
    vp[0x94 / 4] = zero;
    *(void **)(p + 0x98) = head0;
    *(void **)(p + 0x9c) = head0;
    vp[0xa0 / 4] = zero;
    *(void **)(p + 0xa4) = tail;
    *(void **)(p + 0xa8) = tail;
    fn_8002F53C(p + 0xac, (void *)fn_800FB358, (void *)fn_800FB374, 0x1c, 0x20);
    vp[0x438 / 4] = zero;
    u32 offset, i;
    i = 0;
    offset = 0;
    do {
        u8 *node = p + 0xac + offset;
        *(void **)(node + 4) = arg0;
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
        it = p + 0x98;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(p + 0x94, (void **)&it, node + 0x14);
        ++i;
        offset += 0x1c;
    } while (i < 0x20);
    return arg0;
}
#pragma pop
extern "C" void fn_800FB358(void *arg0) {
    /* Constructor for a StrmPlayer::LoadCommand list node: install its vtable
       and clear the list link (+0x14) and status (+0x18). */
    struct LoadCommand {
        void *vtable;     /* +0x00 */
        u8 pad04[0x10];
        void *link;       /* +0x14 nw4hbm::ut::LinkListNode */
        u32 status;       /* +0x18 */
    };
    extern char lbl_80326AC0[]; /* StrmPlayer::LoadCommand vtable */
    LoadCommand *cmd = (LoadCommand *)arg0;
    cmd->link = 0;
    cmd->vtable = lbl_80326AC0;
    cmd->status = 0;
}

/* Deleting-destructor helper: free `object` when `shouldDelete` is set, then return it. */
extern "C" s32 fn_800FB374(s32 object, s32 shouldDelete) {
#define MemFree fn_80128668
    if (object != 0 && shouldDelete > 0) {
        MemFree();
    }
    return object;
#undef MemFree
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 Prepare__Q46nw4hbm3snd6detail10StrmPlayerFPQ46nw4hbm3snd6detail14StrmBufferPoolQ56nw4hbm3snd6detail10StrmPlayer15StartOffsetTypeliPQ56nw4hbm3snd6detail10StrmPlayer12StrmCallbackUl(void *self, void *pool, s32 offset, long length, s32 priority, void *callback, u32 arg6) {
    class Callback {
    public:
        virtual void f0() {}
        virtual s32 Start(void *, void *, void *, u32) { return 0; }
    };
    if (pool == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x5A, lbl_8032677C);
    if (*((u8 *)self + 0x48))
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
    InitParam__Q46nw4hbm3snd6detail10StrmPlayerFi(self, priority);
    *(s32 *)((char *)self + 0x8C) = offset;
    *(s32 *)((char *)self + 0x90) = (s32)length;
    *(void **)((char *)self + 0x430) = callback;
    *(u32 *)((char *)self + 0x434) = arg6;
    *(void **)((char *)self + 0x42C) = pool;
    s32 result = ((Callback *)callback)->Start((void *)NotifyStrmHeaderAsyncEndCallback__Q46nw4hbm3snd6detail10StrmPlayerFbPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeaderPv, self, self, arg6);
    if (result == 2) goto done;
    if (result >= 2) goto done;
    if (result == 0) goto done;
    if (result >= 0) goto doForce;
    else goto done;
doForce:
    ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
done:
    *((u8 *)self + 0x48) = 1;
    return 1;
}
#pragma pop
s32 nw4hbm::snd::detail::StrmPlayer::Start() {
    /* nw4hbm::snd::StrmPlayer::Start: when prepared (0x4A), start the AxVoice
     * at 0x438; on the first start apply the pending pause request under a
     * second interrupt lock and link this player (node at +8) into the global
     * StrmPlayer list.  Returns 1 if started, 0 if not prepared.
     * (lbl_/fn_ names kept: rename_symbol unavailable for game symbols.) */
    #define STRM_READY       0x4A
    #define STRM_ACTIVE      0x49
    #define STRM_PAUSE_REQ   0x4B
    #define STRM_PAUSED      0x4D
    #define STRM_FORCE_PAUSE 0x4E
    #define STRM_VOICE       0x438
    #define STRM_NODE        0x08
    #define STRM_PLAYER_LIST lbl_8041506C
    #define SND_STRM_CPP     lbl_80326768
    #define STRM_ASSERT_MSG  lbl_803267AC
    #define LINKLIST_CPP     lbl_80326C4C
    #define NULL_POINTER_MSG lbl_80326C28
    u8 *player = (u8 *)this;
    struct { u32 value; } outerIrqState;
    outerIrqState.value = OSDisableInterrupts();
    u32 &savedOuterIrq = outerIrqState.value;
    if (player[STRM_READY] == 0) {
        OSRestoreInterrupts(savedOuterIrq);
        return 0;
    }
    if (player[STRM_ACTIVE] == 0) {
        if (*(s32 *)(player + STRM_VOICE) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(SND_STRM_CPP, 0x97, STRM_ASSERT_MSG);
        }
        fn_800E519C(*(void **)(player + STRM_VOICE));
        u32 savedInnerIrq = OSDisableInterrupts();
        u8 shouldPause = 0;
        if (player[STRM_PAUSE_REQ] != 0) shouldPause = 1;
        if (player[STRM_FORCE_PAUSE] != 0) shouldPause = 1;
        if (shouldPause != player[STRM_PAUSED]) {
            if (*(s32 *)(player + STRM_VOICE) == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(SND_STRM_CPP, 0xD1, STRM_ASSERT_MSG);
            }
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(player + STRM_VOICE), shouldPause);
            player[STRM_PAUSED] = shouldPause;
        }
        OSRestoreInterrupts(savedInnerIrq);
        struct { void *node; } listCursor;
        listCursor.node = &STRM_PLAYER_LIST[4];
        void *&insertPosRef = listCursor.node;
        if (this == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(LINKLIST_CPP, 0x233, NULL_POINTER_MSG);
        }
        void *insertPos = insertPosRef;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
            STRM_PLAYER_LIST, &insertPos, player + STRM_NODE);
        player[STRM_ACTIVE] = 1;
    }
    OSRestoreInterrupts(savedOuterIrq);
    return 1;

    #undef STRM_READY
    #undef STRM_ACTIVE
    #undef STRM_PAUSE_REQ
    #undef STRM_PAUSED
    #undef STRM_FORCE_PAUSE
    #undef STRM_VOICE
    #undef STRM_NODE
    #undef STRM_PLAYER_LIST
    #undef SND_STRM_CPP
    #undef STRM_ASSERT_MSG
    #undef LINKLIST_CPP
    #undef NULL_POINTER_MSG
}
#pragma pop
extern "C" void ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
// Force-stops the StrmPlayer when its active flag (+0x48) is still set.
extern "C" void fn_800FB620(void *player) {
    if (*(u8 *)((u8 *)player + 0x48) != 0) {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(player);
    }
}

extern "C" const char lbl_803267AC[];
void nw4hbm::snd::detail::StrmPlayer::Pause(bool arg1) {
    /* Pauses or resumes stream playback, propagating the paused state to the underlying AxVoice when active. */
    u8* self = (u8*)this;
    self[0x4B] = arg1;
    if (arg1) {
        self[0x4E] = 1;
    }
    if (self[0x49] != 0) {
        u32 irq = OSDisableInterrupts();
        bool paused = false;
        if (self[0x4B] != 0) {
            paused = true;
        }
        if (self[0x4E] != 0) {
            paused = true;
        }
        if (paused != self[0x4D]) {
            if (*(s32*)(self + 0x438) == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0xD1,
                                             lbl_803267AC);
            }
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(
                *(void**)(self + 0x438), paused);
            self[0x4D] = paused;
        }
        OSRestoreInterrupts(irq);
    }
}

extern "C" void UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(void *arg0) {
    const char *label = lbl_80326768;
    s32 temp_r29;
    s32 temp_r29_2;
    s32 temp_r29_3;
    s32 temp_r29_4;
    s32 temp_r3;

    u8 var_r28;
    u8 var_r28_2;
    u8 var_r28_3;
    u8 var_r28_4;

    if (((s32) M2C_FIELD(arg0, u8 *, 0x49) != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x438) != 0)) {
        temp_r3 = DVDGetDriveStatus();
        if (temp_r3 == 0) {
            M2C_FIELD(arg0, s8 *, 0x4C) = 0;
            temp_r29 = OSDisableInterrupts();
            var_r28 = 0;
            if ((s32) M2C_FIELD(arg0, u8 *, 0x4B) != 0) {
                var_r28 = 1;
            }
            if ((s32) M2C_FIELD(arg0, u8 *, 0x4E) != 0) {
                var_r28 = 1;
            }
            if (var_r28 != (u8) M2C_FIELD(arg0, u8 *, 0x4D)) {
                if (*(void * volatile *)((u8 *)arg0 + 0x438) == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xD1, label + 0x44);
                }
                Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void * volatile *)((u8 *)arg0 + 0x438), var_r28);
                M2C_FIELD(arg0, u8 *, 0x4D) = var_r28;
            }
            OSRestoreInterrupts(temp_r29);
        } else if (temp_r3 != 1) {
            M2C_FIELD(arg0, s8 *, 0x4C) = 1;
            M2C_FIELD(arg0, u8 *, 0x4E) = 1U;
            temp_r29_2 = OSDisableInterrupts();
            var_r28_2 = 0;
            if ((s32) M2C_FIELD(arg0, u8 *, 0x4B) != 0) {
                var_r28_2 = 1;
            }
            if ((s32) M2C_FIELD(arg0, u8 *, 0x4E) != 0) {
                var_r28_2 = 1;
            }
            if (var_r28_2 != (u8) M2C_FIELD(arg0, u8 *, 0x4D)) {
                if (*(void * volatile *)((u8 *)arg0 + 0x438) == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xD1, label + 0x44);
                }
                Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void * volatile *)((u8 *)arg0 + 0x438), var_r28_2);
                M2C_FIELD(arg0, u8 *, 0x4D) = var_r28_2;
            }
            OSRestoreInterrupts(temp_r29_2);
        }
        if ((s32) M2C_FIELD(arg0, u8 *, 0x4E) == 0) {
            if ((u32) M2C_FIELD(arg0, u32 *, 0xA0) >= (u32) (M2C_FIELD(arg0, s32 *, 0x68) - 1)) {
                Warning__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xFD, label + 0x70);
                M2C_FIELD(arg0, u8 *, 0x4E) = 1U;
                temp_r29_3 = OSDisableInterrupts();
                var_r28_3 = 0;
                if ((s32) M2C_FIELD(arg0, u8 *, 0x4B) != 0) {
                    var_r28_3 = 1;
                }
                if ((s32) M2C_FIELD(arg0, u8 *, 0x4E) != 0) {
                    var_r28_3 = 1;
                }
                if (var_r28_3 != (u8) M2C_FIELD(arg0, u8 *, 0x4D)) {
                    if (*(void * volatile *)((u8 *)arg0 + 0x438) == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xD1, label + 0x44);
                    }
                    Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void * volatile *)((u8 *)arg0 + 0x438), var_r28_3);
                    M2C_FIELD(arg0, u8 *, 0x4D) = var_r28_3;
                }
                OSRestoreInterrupts(temp_r29_3);
            }
        } else if ((s32) M2C_FIELD(arg0, u32 *, 0xA0) == 0) {
            M2C_FIELD(arg0, u8 *, 0x4E) = 0U;
            temp_r29_4 = OSDisableInterrupts();
            var_r28_4 = 0;
            if ((s32) M2C_FIELD(arg0, u8 *, 0x4B) != 0) {
                var_r28_4 = 1;
            }
            if ((s32) M2C_FIELD(arg0, u8 *, 0x4E) != 0) {
                var_r28_4 = 1;
            }
            if (var_r28_4 != (u8) M2C_FIELD(arg0, u8 *, 0x4D)) {
                if (*(void * volatile *)((u8 *)arg0 + 0x438) == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xD1, label + 0x44);
                }
                Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void * volatile *)((u8 *)arg0 + 0x438), var_r28_4);
                M2C_FIELD(arg0, u8 *, 0x4D) = var_r28_4;
            }
            OSRestoreInterrupts(temp_r29_4);
        }
        if (((s32) M2C_FIELD(arg0, u8 *, 0x52) == 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x4F) == 0)) {
            if (*(void * volatile *)((u8 *)arg0 + 0x438) == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0x114, label + 0x44);
            }
            s32 temp_r28 = GetCurrentPlayingSample__Q46nw4hbm3snd6detail7AxVoiceCFv(M2C_FIELD(arg0, s32 *, 0x438)) / (u32) M2C_FIELD(arg0, u32 *, 0x30);
            goto loop_check;
loop_body:
            UpdatePlayingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFv(arg0);
            UpdateLoadingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFQ66nw4hbm3snd6detail10StrmPlayer11LoadCommand6Status(arg0, 1);
loop_check:
            if ((s32) M2C_FIELD(arg0, s32 *, 0x7C) != (s32) temp_r28) {
                goto loop_body;
            }
        }
    }
}

extern "C" void Update__Q46nw4hbm3snd6detail10StrmPlayerFv(void *arg0) {
    f32 slots[11];
    register u32 temp_r31;
    register s32 var_r28;
    register s32 var_r30;
    register f32 *var_r29;
    register f32 *var_r29_2;
    register f32 *var_r30_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    f32 temp_f10;
    f32 temp_f25;
    f32 temp_f26;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    if ((s32)M2C_FIELD(arg0, u8 *, 0x49) != 0) {
        if ((s32)M2C_FIELD(arg0, s32 *, 0x438) == 0) {
            ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(arg0);
            return;
        }
        temp_r31 = OSDisableInterrupts();
        temp_f8 = lbl_805610C4;
        temp_f7 = temp_f8 + M2C_FIELD(arg0, volatile f32 *, 0x464);
        temp_f6 = temp_f8 + M2C_FIELD(arg0, volatile f32 *, 0x468);
        temp_f30 = temp_f8;
        temp_f4 = temp_f8 + M2C_FIELD(arg0, volatile f32 *, 0x480);
        temp_f5 = temp_f8 + M2C_FIELD(arg0, volatile f32 *, 0x46C);
        temp_f3 = temp_f8 + M2C_FIELD(arg0, volatile f32 *, 0x484);
        temp_f2 = temp_f8 + M2C_FIELD(arg0, volatile f32 *, 0x488);
        temp_f1 = lbl_805610C0 * M2C_FIELD(arg0, volatile f32 *, 0x43C);
        slots[8] = temp_f30;
        temp_f30 += M2C_FIELD(arg0, volatile f32 *, 0x440);
        temp_f0 = temp_f8 + M2C_FIELD(arg0, volatile f32 *, 0x48C);
        temp_f29 = temp_f8;
        temp_f29 += M2C_FIELD(arg0, volatile f32 *, 0x444);
        temp_f28 = temp_f8;
        slots[9] = temp_f29;
        slots[10] = temp_f28;
        temp_f28 += M2C_FIELD(arg0, volatile f32 *, 0x448);
        temp_f31 = lbl_805610C0;
        slots[4] = temp_f28;
        slots[5] = temp_f8;
        slots[6] = temp_f8;
        slots[7] = temp_f8;
        temp_f10 = M2C_FIELD(arg0, volatile f32 *, 0x450);
        temp_f31 *= temp_f10;
        temp_f26 = lbl_805610C0;
        temp_f9 = M2C_FIELD(arg0, volatile f32 *, 0x454);
        temp_f26 += temp_f9;
        temp_f27 = temp_f8;
        temp_f27 += M2C_FIELD(arg0, volatile f32 *, 0x44C);
        temp_f25 = temp_f8;
        temp_f25 += M2C_FIELD(arg0, volatile f32 *, 0x460);
        slots[8] = temp_f7;
        slots[9] = temp_f6;
        slots[10] = temp_f5;
        slots[4] = temp_f4;
        slots[0] = temp_f4;
        slots[5] = temp_f3;
        slots[1] = temp_f3;
        slots[6] = temp_f2;
        slots[2] = temp_f2;
        slots[7] = temp_f0;
        slots[3] = temp_f0;
        fn_800E5338(M2C_FIELD(arg0, s32 *, 0x438), temp_f1);
        fn_800E5444(M2C_FIELD(arg0, s32 *, 0x438), temp_f31);
        fn_800E5464(M2C_FIELD(arg0, s32 *, 0x438), temp_f30);
        fn_800E54A8(M2C_FIELD(arg0, s32 *, 0x438), temp_f29);
        fn_800E54EC(M2C_FIELD(arg0, s32 *, 0x438), temp_f28);
        fn_800E550C(M2C_FIELD(arg0, s32 *, 0x438), temp_f27);
        fn_800E5550(M2C_FIELD(arg0, s32 *, 0x438), temp_f26);
        fn_800E5594(M2C_FIELD(arg0, s32 *, 0x438), M2C_FIELD(arg0, s32 *, 0x458));
        ((DummyStrmUpdate *)arg0)->f30();
        fn_800E55B4(M2C_FIELD(arg0, s32 *, 0x438));
        fn_800E56D0(M2C_FIELD(arg0, s32 *, 0x438), temp_f25);
        var_r29 = &slots[8];
        var_r30 = 0;
        do {
            SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E5718(M2C_FIELD(arg0, s32 *, 0x438), var_r30, *var_r29);
            var_r30 += 1;
            var_r29 += 1;
        } while (var_r30 < 3);
        var_r30_2 = &slots[4];
        var_r29_2 = &slots[0];
        var_r28 = 0;
        do {
            ((DummyStrmUpdate *)arg0)->f33(var_r28);
            SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif(M2C_FIELD(arg0, s32 *, 0x438), var_r28);
            SetRemoteSend__Q46nw4hbm3snd6detail7AxVoiceFif(M2C_FIELD(arg0, s32 *, 0x438), var_r28, *var_r30_2);
            SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E58CC(M2C_FIELD(arg0, s32 *, 0x438), var_r28, *var_r29_2);
            var_r28 += 1;
            var_r29_2 += 1;
            var_r30_2 += 1;
        } while (var_r28 < 4);
        OSRestoreInterrupts(temp_r31);
    }
}

extern "C" void SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *, s32, const void *, u32);
extern "C" void SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *, s32, const void *, u32);
extern "C" void SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(void *, BOOL);
extern "C" void SetVoiceType__Q46nw4hbm3snd6detail7AxVoiceFQ56nw4hbm3snd6detail7AxVoice9VoiceType(void *, s32);
extern "C" void fn_800E5A8C(void *, s32, u32, const void *);
#pragma push
#pragma use_lmw_stmw off
extern "C" void UpdatePlayingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFv(void *arg0) {
    struct PBox { u8 *v; } pb;
    u8 *&p = pb.v;
    const char *file = lbl_80326768;
    u8 *self = (u8 *)arg0;
    s32 value;
    value = *(s32 *)(self + 0x80) + 1;
    *(s32 *)(self + 0x80) = value;
    if (value > *(s32 *)(self + 0x88)) {
        if (self[0x11] != 0) {
            s32 block, i;
            u32 irq, loopEnd;
            block = *(s32 *)(self + 0x54);
            *(s32 *)(self + 0x80) = *(s32 *)(self + 0x84);
            if (block < 0x7FFFFFFF) *(s32 *)(self + 0x54) = block + 1;
            loopEnd = (u32)(*(s32 *)(self + 0x78) * *(s32 *)(self + 0x30));
            if (*(void **)(self + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x19E, file + 0x44);
            irq = OSDisableInterrupts();
            p = self;
            for (i = 0; i < *(s32 *)(self + 0x4A0); ++i) {
                SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), 0);
                SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), loopEnd);
                p += 0x38;
            }
            SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(self + 0x438), 1);
            OSRestoreInterrupts(irq);
        } else Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x1C6, file + 0x94);
    }
    value = *(s32 *)(self + 0x7C) + 1;
    *(s32 *)(self + 0x7C) = value;
    if (value >= *(s32 *)(self + 0x78)) {
        s32 block, i;
        u32 irq, loopEnd;
        block = *(s32 *)(self + 0x6C);
        loopEnd = (u32)(block * *(s32 *)(self + 0x30));
        *(s32 *)(self + 0x7C) = 0;
        *(s32 *)(self + 0x78) = block;
        if (*(void **)(self + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x19E, file + 0x44);
        irq = OSDisableInterrupts();
        p = self;
        for (i = 0; i < *(s32 *)(self + 0x4A0); ++i) {
            SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), 0);
            SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), loopEnd);
            p += 0x38;
        }
        SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(self + 0x438), 1);
        OSRestoreInterrupts(irq);
    }
    if (*(s32 *)(self + 0x7C) == *(s32 *)(self + 0x78) - 1 && *(u32 *)((u8 *)*(void **)(self + 0x438) + 0x118) == 0) {
        if (self[0x51] == 0) Warning__Q26nw4hbm2dbFPCciPCce(file + 0, 0x1DC, file + 0xB4);
        if (self[0x50] == 0 && self[0x51] != 0) {
            s32 i;
            u32 irq;
            u16 samples[3];
            irq = OSDisableInterrupts();
            p = self;
            for (i = 0; i < *(s32 *)(self + 0x4A0); ++i) {
                samples[0] = *(u16 *)(p + 0x518);
                samples[1] = 0;
                samples[2] = 0;
                fn_800E5A8C(*(void **)(self + 0x438), i, *(u32 *)((u8 *)*(void **)(self + 0x438) + 0x118), samples);
                p += 2;
            }
            SetVoiceType__Q46nw4hbm3snd6detail7AxVoiceFQ56nw4hbm3snd6detail7AxVoice9VoiceType(*(void **)(self + 0x438), 1);
            OSRestoreInterrupts(irq);
        }
        self[0x51] = 0;
        self[0x50] = 0;
    }
    if (*(s32 *)(self + 0x80) == *(s32 *)(self + 0x88) - 1) {
        s32 next = *(s32 *)(self + 0x7C) + 1;
        if (self[0x11] != 0) {
            s32 i, following, block;
            u32 irq, loopStart, loopEnd;
            following = next + 1;
            block = *(s32 *)(self + 0x78);
            if (following >= block) following -= block;
            irq = OSDisableInterrupts();
            loopEnd = (u32)(*(s32 *)(self + 0x38) + next * *(s32 *)(self + 0x30));
            loopStart = (u32)(following * *(s32 *)(self + 0x30));
            if (*(void **)(self + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x19E, file + 0x44);
            {
                u32 innerIrq = OSDisableInterrupts();
                p = self;
                for (i = 0; i < *(s32 *)(self + 0x4A0); ++i) {
                    SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), loopStart);
                    SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), loopEnd);
                    p += 0x38;
                }
                SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(self + 0x438), 1);
                OSRestoreInterrupts(innerIrq);
            }
            if (self[0x10] == 2) {
                if (*(u32 *)((u8 *)*(void **)(self + 0x438) + 0x118) == 0) {
                    SetVoiceType__Q46nw4hbm3snd6detail7AxVoiceFQ56nw4hbm3snd6detail7AxVoice9VoiceType(*(void **)(self + 0x438), 0);
                    s32 j;
                    p = self + 0x4D8;
                    for (j = 0; j < *(s32 *)(self + 0x4A0); ++j) {
                        fn_800E5A8C(*(void **)(self + 0x438), j, *(u32 *)((u8 *)*(void **)(self + 0x438) + 0x118), p);
                        p += 0x38;
                    }
                }
                if (next == *(s32 *)(self + 0x78) - 1) self[0x50] = 1;
            }
            OSRestoreInterrupts(irq);
            return;
        }
        s32 i;
        u32 irq;
        irq = OSDisableInterrupts();
        p = self;
        for (i = 0; i < *(s32 *)(self + 0x4A0); ++i) {
            StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl((s32)*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), (u32)(*(s32 *)(self + 0x38) + next * *(s32 *)(self + 0x30)));
            p += 0x38;
        }
        OSRestoreInterrupts(irq);
        self[0x52] = 1;
    }
}

extern "C" void UpdateLoadingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFQ66nw4hbm3snd6detail10StrmPlayer11LoadCommand6Status(void* arg0, s32 arg1) {
    s32 sp1C;
    void* sp18;
    s32 sp10;
    void* spC;
    void* sp8;
    s32 var_r10;
    if (*(unsigned char*)((unsigned char*)arg0 + 0x53) == 0) return;
    unsigned long irq = OSDisableInterrupts();
    if (*(s32*)((unsigned char*)arg0 + 0x94) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C1C, 0x1F1, lbl_80326BF8);
    }
    s32 tmp28 = *(s32*)((unsigned char*)arg0 + 0x98);
    if (tmp28 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326BBC, 0x23D, lbl_80326B98);
    }
    unsigned char* nd = (unsigned char*)(tmp28 - 0x14);
    if (nd == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326BEC, 0x193, lbl_80326BC8);
    }
    sp1C = *(s32*)((unsigned char*)arg0 + 0x98);
    Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator((unsigned char*)arg0 + 0x94, &sp1C);
    OSRestoreInterrupts(irq);
    *(s32*)(nd + 8) = arg1;
    *(s32*)(nd + 0x10) = *(s32*)((unsigned char*)arg0 + 0x70);
    *(s32*)(nd + 0xC) = *(s32*)((unsigned char*)arg0 + 0x74);
    s32 v30;
    if (*(s32*)((unsigned char*)arg0 + 0x74) < *(s32*)((unsigned char*)arg0 + 0x28) - 1) {
        v30 = *(s32*)((unsigned char*)arg0 + 0x2C);
    } else {
        v30 = *(s32*)((unsigned char*)arg0 + 0x3C);
    }
    unsigned short r6 = *(unsigned short*)((unsigned char*)arg0 + 0x18);
    unsigned r27 = r6 + (*(s32*)((unsigned char*)arg0 + 0x4A0) * ((v30 + 0x1F) & ~31u));
    s32 r26 = *(s32*)((unsigned char*)arg0 + 0x24) + (*(s32*)((unsigned char*)arg0 + 0x74) * (r6 + (*(s32*)((unsigned char*)arg0 + 0x2C) * *(unsigned char*)((unsigned char*)arg0 + 0x12))));
    if (r27 > 0x4020) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x265, lbl_80326838);
    }
    if (nd == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
    }
    sp18 = (unsigned char*)arg0 + 0xA4;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((unsigned char*)arg0 + 0xA0, &sp18, nd + 0x14);
    var_r10 = 0;
    if (*(s32*)((unsigned char*)arg0 + 0x70) == 0 && *(unsigned char*)((unsigned char*)arg0 + 0x10) == 2) {
        var_r10 = 1;
    }
    sp8 = nd;
    spC = arg0;
    sp10 = *(s32*)((unsigned char*)arg0 + 0x434);
    s32 res = ((s32(*)(void*, void*, unsigned, s32, s32, s32, unsigned short, s32))((void**)*(void***)((unsigned char*)arg0 + 0x430))[4])((void*)*(void**)((unsigned char*)arg0 + 0x430), lbl_80415080, r27, r26, *(s32*)((unsigned char*)arg0 + 0x4A0), v30, r6, var_r10);
    if (res == 1) {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(arg0);
    } else if (res == 0) {
        ((void(*)(void*, s32))((void**)*(void**)nd)[2])(nd, 1);
    }
    s32 t = *(s32*)((unsigned char*)arg0 + 0x74) + 1;
    *(s32*)((unsigned char*)arg0 + 0x74) = t;
    if (t <= *(s32*)((unsigned char*)arg0 + 0x88)) goto lab70;
    if (*(unsigned char*)((unsigned char*)arg0 + 0x11) != 0) {
        *(s32*)((unsigned char*)arg0 + 0x74) = *(s32*)((unsigned char*)arg0 + 0x84);
        goto lab70;
    }
    *(unsigned char*)((unsigned char*)arg0 + 0x53) = 1;
    return;
lab70:
    t = *(s32*)((unsigned char*)arg0 + 0x70) + 1;
    *(s32*)((unsigned char*)arg0 + 0x70) = t;
    if (t < *(s32*)((unsigned char*)arg0 + 0x6C)) return;
    s32 r5 = *(s32*)((unsigned char*)arg0 + 0x88);
    s32 r4 = *(s32*)((unsigned char*)arg0 + 0x68);
    *(s32*)((unsigned char*)arg0 + 0x70) = 0;
    s32 v5 = r4 + 1;
    s32 a = (r5 - *(s32*)((unsigned char*)arg0 + 0x74)) + 1;
    s32 b = (r5 - *(s32*)((unsigned char*)arg0 + 0x84)) + 1;
    if (((v5 - a) % b) != 0) {
        v5 = r4;
    }
    *(s32*)((unsigned char*)arg0 + 0x6C) = v5;
}

#pragma pop
extern "C" void UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" const char lbl_80326B68[];
extern "C" const char lbl_80326B8C[];
extern "C" const char lbl_80326768[];
extern "C" const char lbl_8032687C[];
#pragma push
#pragma small_data off
extern "C" u8 lbl_8041506C[];
#pragma push
#pragma use_lmw_stmw off
/* nw4hbm::snd::detail::StrmPlayer::UpdateBufferAllPlayers()
 *
 * Runs on the AX sound-mix callback (fn_800FA6E8), once per audio tick: walk the
 * game's global list of streaming players and give every one of them a single
 * streaming-buffer update.  The list is a nw4hbm::ut::LinkList laid out as
 * { u32 count; LinkListNode node; }, so its first node is at +0x04 and the walk
 * ends on the list's own node.  A node is the LinkListNode kept at +0x08 inside
 * its player, so the player is the eight bytes in front of it; holding an
 * iterator checks the node for NULL the way LinkList.h does (line 0x23D).
 */
extern "C" void UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv(void) {
#define strmPlayerList lbl_8041506C    /* nw4hbm::ut::LinkList of StrmPlayers */
#define linkListH lbl_80326B8C         /* "LinkList.h" */
#define nullPointerMsg lbl_80326B68    /* "NW4HBM:Pointer must not be NULL (p)" */

    LinkListIter begin;                        /* LinkList::GetBeginIter() */
    begin.node = *(void**)&strmPlayerList[0x04]; /* the list's first node */
    LinkListIter it = begin;

    while (it.node != (void*)&strmPlayerList[0x04]) { /* up to the list's own node */
        void* node = it.node;
        it.node = *(void**)it.node;                    /* ++it */
        if (node == 0) {                               /* *it */
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)linkListH, 0x23D,
                                         (const char*)nullPointerMsg);
        }
        UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(&((u8*)node)[-0x08]); /* that player */
    }
#undef strmPlayerList
#undef linkListH
#undef nullPointerMsg
}
/* One update tick for every streaming player: walk nw4hbm's global list of
 * StrmPlayers (lbl_8041506C, a nw4hbm::ut::LinkList { size, sentinel }) and call
 * StrmPlayer::Update on each. A node is the LinkListNode at +0x08 of its player,
 * so the player is the eight bytes in front of it; the list's own node ends the
 * walk, and dereferencing an iterator checks the node the way LinkList.h does.
 * (The game's map names this SeqPlayer::UpdateAllPlayers, but it is the
 * StrmPlayer-side twin of UpdateBufferAllPlayers just above.) */
extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC490(void) {
    LinkListIter begin;
    begin.node = *(void**)&lbl_8041506C[0x04]; /* the list's first node */
    LinkListIter it = begin;

    while (it.node != (void*)&lbl_8041506C[0x04]) { /* up to the list's own node */
        void* node = it.node;
        it.node = *(void**)it.node;
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326B8C /* "LinkList.h" */,
                                         0x23D,
                                         (const char*)lbl_80326B68 /* "NW4HBM:Pointer must not be NULL (p)" */);
        }
        Update__Q46nw4hbm3snd6detail10StrmPlayerFv(&((u8*)node)[-0x08]); /* its StrmPlayer */
    }
}
#pragma push
#pragma small_data off
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC508(void) {
    void* pHead = *(void**)&lbl_8041506C[0x04];
    void* pList = &lbl_8041506C[0x04];
    void* p;
    while (pHead != pList) {
        p = pHead;
        pHead = *(void**)pHead;
        if (p == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326B8C, 0x23D,
                                         (const char*)lbl_80326B68);
        }
        ((DummyStrmUpdate*)(&((u8*)p)[-0x08]))->f2();
    }
    if (*(u32*)lbl_8041506C != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326768, 0x2EE,
                                     (const char*)lbl_8032687C);
    }
}
#pragma cplusplus reset
#pragma pop
extern "C" void fn_800FC5B8(void *player, f32 value) {
    /* Set the sound player's float field at offset 0x45C with interrupts disabled. */
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)player + 0x45C) = value;
    OSRestoreInterrupts(token);
}

/* Return the sound player's float field at offset 0x45C (the value set by fn_800FC5B8). */
extern "C" f32 fn_800FC5F8(void *player) { return *(f32 *)((u8 *)player + 0x45C); }

extern "C" void fn_800FC600(void *object, f32 value) {
    /* Set the float field at offset 0x460 of object with interrupts disabled. */
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)object + 0x460) = value;
    OSRestoreInterrupts(token);
}

/* Return the sound player's float field at offset 0x460 (the value set by fn_800FC600). */
extern "C" f32 fn_800FC640(void *player) { return *(f32 *)((u8 *)player + 0x460); }

/* snd_StrmPlayer.cpp's assertion strings.  Each player there keeps one FX send
 * level per aux bus (nw4hbm::snd::AuxBus); the setters update the array with
 * interrupts off.  The library's own message still calls the bus "remoteIndex". */
#define SND_STRMPLAYER_CPP ((const char *)lbl_80326768) /* "snd_StrmPlayer.cpp" */
#define STR_REMOTE_OOB     ((const char *)lbl_803268E4) /* "remoteIndex is out of bounds(%d)\n%d <= remoteIndex < %d not satisfied" */
#define AUX_BUS_COUNT      4                            /* aux buses a player sends to */
#define STRM_FX_SEND(p, bus) (*(f32 *)((u8 *)(p) + 0x480 + (bus) * 4)) /* 0x480 FX send level of one aux bus */

extern "C" const char lbl_803268AC[];
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC648(void *self, s32 bus, f32 value) {
    /* Set the FX send amount for an aux bus (0 <= bus < 3) on this sequence
     * player, updating the stored send level with interrupts disabled. */
    int valid = 0;
    if (bus >= 0 && bus < 3) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x309, lbl_803268AC, bus, 0, 3);
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x464 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC6E4(void *self, s32 bus) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
    extern const char lbl_80326768[];
    extern const char lbl_803268AC[];
    s32 isBusValid = 0;
    /* Return the FX send level for aux bus 0-2 from this seq player (+0x464), panicking if the bus index is out of range. */
    if (bus >= 0 && bus < 3) isBusValid = 1;
    if (isBusValid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x310, lbl_803268AC, bus, 0, 3);
    return *(f32 *)((u8 *)self + 0x464 + bus * 4);
}

extern "C" void fn_800FC76C(void *player, s32 value) {
    /* Set the integer field at offset 0x458 of this sound player with interrupts disabled. */
    u32 irqState = OSDisableInterrupts();
    *(s32 *)((u8 *)player + 0x458) = value;
    OSRestoreInterrupts(irqState);
}

extern "C" s32 fn_800FC7AC(void *player) {
    /* Return this sound player's integer field at offset 0x458 (paired with fn_800FC76C, which sets it). */
    return *(s32 *)((u8 *)player + 0x458);
}

extern "C" const char lbl_803268E4[];
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC7B4(void *self, s32 bus, f32 value) {
    /* Set this sequence player's FX send level for an aux bus, with interrupt-safe update. */
    int valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x322, lbl_803268E4, bus, 0, 4);
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x470 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC850(s32 self, s32 auxBus) {
    /* Get this sequence player's FX send level for an aux bus (0..3). */
    s32 isValidBus = 0;
    if (auxBus >= 0 && auxBus < 4)
        isValidBus = 1;
    if (isValidBus == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x329, lbl_803268E4, auxBus, 0, 4);
    return *(f32 *)(self + auxBus * 4 + 0x470);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC8D8(void *self, s32 bus, f32 value) {
    /* Set this player's FX send level for one aux bus (snd_StrmPlayer.cpp:0x32f
     * checks the bus number first); interrupts are off so the sound update
     * cannot see a half-written level. */
    int valid = 0;
    if (bus >= 0 && bus < AUX_BUS_COUNT) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(SND_STRMPLAYER_CPP, 0x32f, STR_REMOTE_OOB, bus, 0, AUX_BUS_COUNT);
    u32 token = OSDisableInterrupts();
    STRM_FX_SEND(self, bus) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC974(void *self, s32 bus) {
    /* nw4hbm::snd::detail::SeqPlayer::GetFxSend(AuxBus) const: return FX send level for bus 0..3
       (stored at self+0x480), panicking if out of range. Strings: lbl_80326768="snd_SeqPlayer.cpp",
       lbl_803268E4="remoteIndex is out of bounds...". */
    s32 isValidBus = 0;
    if (bus >= 0 && bus < 4) {
        isValidBus = 1;
    }
    if (isValidBus == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x336, lbl_803268E4, bus, 0, 4);
    }
    return *(f32 *)((u8 *)self + 0x480 + bus * 4);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC9FC(void *player, s32 bus, f32 fxSend) {
    /* Sets this sequence player's FX send level for the given aux bus (interrupt-safe). */
    s32 isBusValid = 0;
    if (bus >= 0 && bus < 4) isBusValid = 1;
    if (isBusValid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x33C, STR_REMOTE_OOB, bus, 0, 4);
    u32 interrupts = OSDisableInterrupts();
    *(f32 *)((u8 *)player + 0x490 + bus * 4) = fxSend;
    OSRestoreInterrupts(interrupts);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FCA98(void *self, s32 bus) {
    /* Returns the FX send level for the given aux bus (0..AUX_BUS_COUNT-1). */
    s32 isValidBus = 0;
    if (bus >= 0 && bus < AUX_BUS_COUNT) isValidBus = 1;
    if (isValidBus == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(SND_STRMPLAYER_CPP, 0x343, STR_REMOTE_OOB, bus, 0, AUX_BUS_COUNT);
    }
    return *(f32 *)((u8 *)self + 0x490 + bus * 4);
}

/* Initialize StrmPlayer runtime parameters to defaults for the given priority. */
extern "C" void InitParam__Q46nw4hbm3snd6detail10StrmPlayerFi(void* player, s32 priority) {
    f32 zero = lbl_805610C4;
    f32 one = lbl_805610C0;
    *((u8*)player + 0x48) = 0;
    *((u8*)player + 0x49) = 0;
    *((u8*)player + 0x4A) = 0;
    *((u8*)player + 0x53) = 0;
    *((u8*)player + 0x4B) = 0;
    *((u8*)player + 0x4C) = 0;
    *((u8*)player + 0x4D) = 0;
    *((u8*)player + 0x4E) = 0;
    *((u8*)player + 0x4F) = 0;
    *((u8*)player + 0x52) = 0;
    *((u8*)player + 0x50) = 0;
    *((u8*)player + 0x51) = 0;
    *(s32*)((u8*)player + 0x4A0) = 0;
    *(s32*)((u8*)player + 0x54) = 0;
    *(f32*)((u8*)player + 0x43C) = one;
    *(f32*)((u8*)player + 0x450) = one;
    *(f32*)((u8*)player + 0x440) = zero;
    *(f32*)((u8*)player + 0x444) = zero;
    *(f32*)((u8*)player + 0x448) = zero;
    *(f32*)((u8*)player + 0x44C) = zero;
    *(f32*)((u8*)player + 0x454) = zero;
    *(s32*)((u8*)player + 0x458) = 1;
    *(f32*)((u8*)player + 0x45C) = one;
    *(f32*)((u8*)player + 0x460) = zero;
    *(f32*)((u8*)player + 0x464) = zero;
    *(f32*)((u8*)player + 0x468) = zero;
    *(f32*)((u8*)player + 0x46C) = zero;
    *(f32*)((u8*)player + 0x480) = zero;
    *(f32*)((u8*)player + 0x490) = zero;
    *(f32*)((u8*)player + 0x484) = zero;
    *(f32*)((u8*)player + 0x494) = zero;
    *(f32*)((u8*)player + 0x488) = zero;
    *(f32*)((u8*)player + 0x498) = zero;
    *(f32*)((u8*)player + 0x48C) = zero;
    *(f32*)((u8*)player + 0x49C) = zero;
    *(s32*)((u8*)player + 0x4A4) = priority;
    *(s32*)((u8*)player + 0x4A8) = 0;
    *(s32*)((u8*)player + 0x4AC) = 0;
    *(s32*)((u8*)player + 0x4E0) = 0;
    *(s32*)((u8*)player + 0x4E4) = 0;
}

/* nw4hbm::snd::detail::StrmPlayer fields Setup() uses.  The player holds one
 * STRM_CHANNEL_SIZE-byte record per channel, starting just past its channel count. */
#define STRM_BLOCK_COUNT(p)       (*(u32 *)((u8 *)(p) + 0x28))         /* 0x28 blocks in the stream */
#define STRM_LOOPING(p)           (*(u8 *)((u8 *)(p) + 0x11))          /* 0x11 stream restarts at its end */
#define STRM_SAMPLES_PER_BLOCK(p) (*(u32 *)((u8 *)(p) + 0x30))         /* 0x30 samples in one block */
#define STRM_START_SAMPLE(p)      (*(u32 *)((u8 *)(p) + 0x38))         /* 0x38 sample the stream starts from */
#define STRM_STOP_SCHEDULED(p)    (*(u8 *)((u8 *)(p) + 0x52))          /* 0x52 voice has an end point set */
#define STRM_AT_END(p)            (*(u8 *)((u8 *)(p) + 0x53))          /* 0x53 loading reached the last block */
#define STRM_LOAD_REQUESTS(p)     (*(s32 *)((u8 *)(p) + 0x58))         /* 0x58 block loads still in flight */
#define STRM_QUEUE_LIMIT(p)       (*(s32 *)((u8 *)(p) + 0x68))         /* 0x68 blocks to keep queued, less one */
#define STRM_AX_VOICE(p)          (*(s32 *)((u8 *)(p) + 0x438))        /* 0x438 AxVoice playing the stream */
#define STRM_CHANNEL_COUNT(p)     (*(s32 *)((u8 *)(p) + 0x4A0))        /* 0x4A0 channels of that voice */
#define STRM_CHANNEL_BUFFER(c)    (*(const void **)((u8 *)(c) + 0x4A8)) /* 0x4A8 one channel's stream buffer */
#define STRM_CHANNEL_SIZE         0x38                                 /* bytes of one channel's record */

extern "C" s32 SetupPlayer__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(void *, const void *);
extern "C" void UpdateLoadingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFQ66nw4hbm3snd6detail10StrmPlayer11LoadCommand6Status(void *, s32);
extern "C" void StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(s32, s32, const void *, unsigned long);
#pragma use_lmw_stmw off
extern "C" void Setup__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(void *player, const void *header) {
    register s32 irqState;
    register s32 lastBlock;
    register s32 channelIndex;
    register void *channel;
    register s32 queuedBlocks;
    if (SetupPlayer__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(player, header) == 0) {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(player);
    } else {
        STRM_LOAD_REQUESTS(player) = 0;
        queuedBlocks = 0;
        while (queuedBlocks < STRM_QUEUE_LIMIT(player)) {
            UpdateLoadingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFQ66nw4hbm3snd6detail10StrmPlayer11LoadCommand6Status(player, 0);
            ++STRM_LOAD_REQUESTS(player);
            if (STRM_AT_END(player) == 0)
                ++queuedBlocks;
            else
                break;
        }
        u32 blockCount = STRM_BLOCK_COUNT(player);
        if (blockCount <= 2 && STRM_LOOPING(player) == 0) {
            lastBlock = blockCount - 1;
            irqState = OSDisableInterrupts();
            channel = player;
            channelIndex = 0;
            while (channelIndex < STRM_CHANNEL_COUNT(player)) {
                StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(
                    STRM_AX_VOICE(player),
                    channelIndex,
                    STRM_CHANNEL_BUFFER(channel),
                    STRM_START_SAMPLE(player) + lastBlock * STRM_SAMPLES_PER_BLOCK(player));
                channel = (u8 *)channel + STRM_CHANNEL_SIZE;
                ++channelIndex;
            }
            OSRestoreInterrupts(irqState);
            STRM_STOP_SCHEDULED(player) = 1;
        }
    }
}
#pragma use_lmw_stmw reset
extern "C" s32 AllocChannels__Q46nw4hbm3snd6detail10StrmPlayerFii(void *, s32, s32);
extern "C" u32 GetSampleByByte__Q46nw4hbm3snd6detail7AxVoiceFUlQ56nw4hbm3snd6detail7AxVoice6Format(u32, u32);
extern "C" void Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(void *, const void *);
extern "C" s32 SetupPlayer__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(void *arg0, const void *arg1) {
    struct ChannelWave {
        u32 sample;
        u8 padding[0x10];
        u16 params[24];
    };
    struct WaveData {
        u8 format;
        u8 flag;
        u8 channels;
        u8 padding;
        u32 sampleLength;
        u32 zero;
        u32 sampleBytes;
        ChannelWave channelsData[2];
    };
    const char *base = lbl_80326768;
    if (*(volatile u32 *)((u8 *)arg0 + 0x42C) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768 + 0, 0x3E1, base + 0x1C4);

    register u32 field34, field30, field2C, field28, field24, field20;
    register u32 field1C, field18, field14, field10, fieldC;
    register u16 field8;
    register u32 field4;
    register s32 channels, mode;
    register u8 format;
    u32 rate;
    format = ((const u8 *)arg1)[0];
    rate = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 0x42C) + 8);
    mode = ((const u8 *)arg1)[1];
    channels = ((const u8 *)arg1)[2];
    field4 = *(u32 *)(((const u8 *)arg1) + 4);
    field8 = *(u16 *)(((const u8 *)arg1) + 8);
    fieldC = *(u32 *)(((const u8 *)arg1) + 0xC);
    field10 = *(u32 *)(((const u8 *)arg1) + 0x10);
    field14 = *(u32 *)(((const u8 *)arg1) + 0x14);
    field18 = *(u32 *)(((const u8 *)arg1) + 0x18);
    field1C = *(u32 *)(((const u8 *)arg1) + 0x1C);
    field20 = *(u32 *)(((const u8 *)arg1) + 0x20);
    field24 = *(u32 *)(((const u8 *)arg1) + 0x24);
    field28 = *(u32 *)(((const u8 *)arg1) + 0x28);
    field2C = *(u32 *)(((const u8 *)arg1) + 0x2C);
    field30 = *(u32 *)(((const u8 *)arg1) + 0x30);
    field34 = *(u32 *)(((const u8 *)arg1) + 0x34);

    ((u8 *)arg0)[0x10] = format;
    ((u8 *)arg0)[0x11] = mode;
    ((u8 *)arg0)[0x12] = channels;
    *(u32 *)(((u8 *)arg0) + 0x14) = field4;
    *(u16 *)(((u8 *)arg0) + 0x18) = field8;
    *(u32 *)(((u8 *)arg0) + 0x1C) = fieldC;
    *(u32 *)(((u8 *)arg0) + 0x20) = field10;
    *(u32 *)(((u8 *)arg0) + 0x24) = field14;
    *(u32 *)(((u8 *)arg0) + 0x28) = field18;
    *(u32 *)(((u8 *)arg0) + 0x2C) = field1C;
    *(u32 *)(((u8 *)arg0) + 0x30) = field20;
    *(u32 *)(((u8 *)arg0) + 0x34) = field24;
    *(u32 *)(((u8 *)arg0) + 0x38) = field28;
    *(u32 *)(((u8 *)arg0) + 0x3C) = field2C;
    *(u32 *)(((u8 *)arg0) + 0x40) = field30;
    *(u32 *)(((u8 *)arg0) + 0x44) = field34;

    if (format == 2) {
        const u16 *src = (const u16 *)arg1;
        u8 *dst = (u8 *)arg0;
        for (s32 i = 0; i < ((u8 *)arg0)[0x12]; ++i) {
                ((u16 *)(dst + 0x4B0))[0] = src[28];
                ((u16 *)(dst + 0x4B0))[1] = src[29];
                ((u16 *)(dst + 0x4B0))[2] = src[30];
                ((u16 *)(dst + 0x4B0))[3] = src[31];
                ((u16 *)(dst + 0x4B0))[4] = src[32];
                ((u16 *)(dst + 0x4B0))[5] = src[33];
                ((u16 *)(dst + 0x4B0))[6] = src[34];
                ((u16 *)(dst + 0x4B0))[7] = src[35];
                ((u16 *)(dst + 0x4B0))[8] = src[36];
                ((u16 *)(dst + 0x4B0))[9] = src[37];
                ((u16 *)(dst + 0x4B0))[10] = src[38];
                ((u16 *)(dst + 0x4B0))[11] = src[39];
                ((u16 *)(dst + 0x4B0))[12] = src[40];
                ((u16 *)(dst + 0x4B0))[13] = src[41];
                ((u16 *)(dst + 0x4B0))[14] = src[42];
                ((u16 *)(dst + 0x4B0))[15] = src[43];
                ((u16 *)(dst + 0x4B0))[16] = src[44];
                ((u16 *)(dst + 0x4B0))[17] = src[45];
                ((u16 *)(dst + 0x4B0))[18] = src[46];
                ((u16 *)(dst + 0x4B0))[19] = src[47];
                ((u16 *)(dst + 0x4B0))[20] = src[48];
                ((u16 *)(dst + 0x4B0))[21] = src[49];
                ((u16 *)(dst + 0x4B0))[22] = src[50];
                ((u16 *)(dst + 0x4B0))[23] = src[51];
            src = (const u16 *)((const u8 *)src + 0x30);
            dst += 0x38;
        }
    }

    s32 sampleSize = *(s32 *)(((u8 *)arg0) + 0x2C);
    *(s32 *)(((u8 *)arg0) + 0x60) = sampleSize;
    *(s32 *)(((u8 *)arg0) + 0x88) = *(s32 *)(((u8 *)arg0) + 0x28) - 1;
    *(u32 *)(((u8 *)arg0) + 0x84) = *(u32 *)(((u8 *)arg0) + 0x1C) / *(u32 *)(((u8 *)arg0) + 0x30);
    if (sampleSize > 0x2000) {
        Warning__Q26nw4hbm2dbFPCciPCce(lbl_80326768 + 0, 0x3F4, base + 0x1F4);
        return 0;
    }

    s32 frameCount = rate / sampleSize;
    *(s32 *)(((u8 *)arg0) + 0x64) = frameCount;
    if (frameCount < 4) {
        Warning__Q26nw4hbm2dbFPCciPCce(lbl_80326768 + 0, 0x3FA, base + 0x218);
        return 0;
    }
    if (frameCount > 0x20)
        *(s32 *)(((u8 *)arg0) + 0x64) = 0x20;

    s32 blockCount = *(s32 *)(((u8 *)arg0) + 0x64);
    s32 blockLast = blockCount - 1;
    *(s32 *)(((u8 *)arg0) + 0x68) = blockLast;
    *(s32 *)(((u8 *)arg0) + 0x5C) = blockLast;

    s32 samplesPerBlock = 0;
    u32 stride = *(u32 *)(((u8 *)arg0) + 0x30);
    if (stride != 0) {
        s32 mode2 = *(s32 *)(((u8 *)arg0) + 0x8C);
        if (mode2 == 0) {
            samplesPerBlock = *(s32 *)(((u8 *)arg0) + 0x90) / (s32)stride;
        } else if (mode2 == 1) {
            samplesPerBlock = ((*(s32 *)(((u8 *)arg0) + 0x14) * *(s32 *)(((u8 *)arg0) + 0x90)) / 1000) / (s32)stride;
        }
    }
    *(s32 *)(((u8 *)arg0) + 0x80) = samplesPerBlock;
    *(s32 *)(((u8 *)arg0) + 0x74) = samplesPerBlock;
    *(s32 *)(((u8 *)arg0) + 0x70) = 0;
    *(s32 *)(((u8 *)arg0) + 0x7C) = 0;

    if (((u8 *)arg0)[0x4F] != 0) {
        *(s32 *)(((u8 *)arg0) + 0x6C) = *(s32 *)(((u8 *)arg0) + 0x28);
    } else {
        s32 last = *(s32 *)(((u8 *)arg0) + 0x88);
        s32 block = *(s32 *)(((u8 *)arg0) + 0x68);
        s32 next = block + 1;
        s32 rem = (next - ((last - samplesPerBlock) + 1)) % ((last - (s32)*(u32 *)(((u8 *)arg0) + 0x84)) + 1);
        if (rem == 0)
            block = next;
        *(s32 *)(((u8 *)arg0) + 0x6C) = block;
    }
    *(s32 *)(((u8 *)arg0) + 0x78) = *(s32 *)(((u8 *)arg0) + 0x6C);

    u32 token = OSDisableInterrupts();
    s32 requestedChannels = ((u8 *)arg0)[0x12];
    s32 allocatedChannels = 2;
    if (requestedChannels <= 2)
        allocatedChannels = requestedChannels;
    *(s32 *)(((u8 *)arg0) + 0x4A0) = allocatedChannels;
    if (AllocChannels__Q46nw4hbm3snd6detail10StrmPlayerFii(arg0, *(s32 *)(((u8 *)arg0) + 0x4A0), *(s32 *)(((u8 *)arg0) + 0x4A4)) == 0) {
        OSRestoreInterrupts(token);
        return 0;
    }
    OSRestoreInterrupts(token);

    WaveData wave;
    u32 irq = OSDisableInterrupts();
    wave.format = ((u8 *)arg0)[0x10];
    wave.flag = 1;
    wave.channels = (u8)*(s32 *)(((u8 *)arg0) + 0x4A0);
    wave.sampleLength = *(u32 *)(((u8 *)arg0) + 0x14);
    wave.zero = 0;
    u32 sampleFormat = 0;
    if (((u8 *)arg0)[0x10] == 1)
        sampleFormat = 0xA;
    else if (((u8 *)arg0)[0x10] == 0)
        sampleFormat = 0x19;
    wave.sampleBytes = GetSampleByByte__Q46nw4hbm3snd6detail7AxVoiceFUlQ56nw4hbm3snd6detail7AxVoice6Format((u32)(*(s32 *)(((u8 *)arg0) + 0x60) * *(s32 *)(((u8 *)arg0) + 0x78)), sampleFormat);

    ChannelWave *out = wave.channelsData;
    u8 *playerChannel = (u8 *)arg0;
    for (s32 i = 0; i < *(s32 *)(((u8 *)arg0) + 0x4A0); ++i) {
        out->sample = *(u32 *)(playerChannel + 0x4A8);
            out->params[0] = *(u16 *)(playerChannel + 0x4B0 + 0);
            out->params[1] = *(u16 *)(playerChannel + 0x4B0 + 2);
            out->params[2] = *(u16 *)(playerChannel + 0x4B0 + 4);
            out->params[3] = *(u16 *)(playerChannel + 0x4B0 + 6);
            out->params[4] = *(u16 *)(playerChannel + 0x4B0 + 8);
            out->params[5] = *(u16 *)(playerChannel + 0x4B0 + 10);
            out->params[6] = *(u16 *)(playerChannel + 0x4B0 + 12);
            out->params[7] = *(u16 *)(playerChannel + 0x4B0 + 14);
            out->params[8] = *(u16 *)(playerChannel + 0x4B0 + 16);
            out->params[9] = *(u16 *)(playerChannel + 0x4B0 + 18);
            out->params[10] = *(u16 *)(playerChannel + 0x4B0 + 20);
            out->params[11] = *(u16 *)(playerChannel + 0x4B0 + 22);
            out->params[12] = *(u16 *)(playerChannel + 0x4B0 + 24);
            out->params[13] = *(u16 *)(playerChannel + 0x4B0 + 26);
            out->params[14] = *(u16 *)(playerChannel + 0x4B0 + 28);
            out->params[15] = *(u16 *)(playerChannel + 0x4B0 + 30);
            out->params[16] = *(u16 *)(playerChannel + 0x4B0 + 32);
            out->params[17] = *(u16 *)(playerChannel + 0x4B0 + 34);
            out->params[18] = *(u16 *)(playerChannel + 0x4B0 + 36);
            out->params[19] = *(u16 *)(playerChannel + 0x4B0 + 38);
            out->params[20] = *(u16 *)(playerChannel + 0x4B0 + 40);
            out->params[21] = *(u16 *)(playerChannel + 0x4B0 + 42);
            out->params[22] = *(u16 *)(playerChannel + 0x4B0 + 44);
            out->params[23] = *(u16 *)(playerChannel + 0x4B0 + 46);
        playerChannel += 0x38;
        ++out;
    }
    Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(*(void **)((u8 *)arg0 + 0x438), &wave);
    SetVoiceType__Q46nw4hbm3snd6detail7AxVoiceFQ56nw4hbm3snd6detail7AxVoice9VoiceType(*(void **)((u8 *)arg0 + 0x438), 1);
    OSRestoreInterrupts(irq);
    return 1;
}

extern "C" const char lbl_8032692C[];
extern "C" void *fn_800E3954(void *, s32, s32, s32, void (*)(void *, s32, void *), void *);
extern "C" void VoiceCallbackFunc__Q46nw4hbm3snd6detail10StrmPlayerFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv(void *, s32, void *);
extern "C" s32 AllocChannels__Q46nw4hbm3snd6detail10StrmPlayerFii(void *player, s32 channelCount, s32 channelParam) {
    // Allocate per-channel stream buffers and an AxVoice set for this StrmPlayer; frees partial allocations on failure.
    if (*(void **)((u8 *)player + 0x42C) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x45C, lbl_8032692C);

    u8 *channel = (u8 *)player;
    s32 allocated = 0;
    goto allocate_check;
    do {
        void *buffer = Alloc__Q44nw4r3snd6detail14StrmBufferPoolFv(*(void **)((u8 *)player + 0x42C));
        if (buffer == 0) {
            channel = (u8 *)player;
            s32 freed = 0;
            goto alloc_free_check;
            do {
                Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(*(void **)((u8 *)player + 0x42C), *(void **)(channel + 0x4A8));
                channel += 0x38;
                ++freed;
            alloc_free_check:
                ;
            } while (freed < allocated);
            return 0;
        }
        *(void **)(channel + 0x4A8) = buffer;
        ++allocated;
        *(u32 *)(channel + 0x4AC) = *(u32 *)((u8 *)(*(void **)((u8 *)player + 0x42C)) + 8);
        channel += 0x38;
    allocate_check:
        ;
    } while (allocated < channelCount);

    void *manager = Instance__15EmissionManagerFv();
    void *voice = ::fn_800E3954(manager, channelCount, channelParam, 0xFF,
                               VoiceCallbackFunc__Q46nw4hbm3snd6detail10StrmPlayerFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv,
                               player);
    if (voice == 0) {
        channel = (u8 *)player;
        s32 freed = 0;
        goto voice_free_check;
        do {
            Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(*(void **)((u8 *)player + 0x42C), *(void **)(channel + 0x4A8));
            channel += 0x38;
            ++freed;
        voice_free_check:
            ;
        } while (freed < channelCount);
        return 0;
    }
    *(void **)((u8 *)player + 0x438) = voice;
    return 1;
}

#pragma use_lmw_stmw off
#pragma dont_inline on
void FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(void *self) {
    BOOL irqState = OSDisableInterrupts();
    u8 *player = (u8 *)self;
    s32 index = 0;

    while (index < *(s32 *)((u8 *)self + 0x4A0)) {
        void *buffer = *(void **)(player + 0x4A8);
        if (buffer != 0) {
            Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(*(void **)((u8 *)self + 0x42C), buffer);
            *(void **)(player + 0x4A8) = 0;
            *(void **)(player + 0x4AC) = 0;
        }
        player += 0x38;
        index += 1;
    }

    *(s32 *)((u8 *)self + 0x4A0) = 0;
    if (*(void **)((u8 *)self + 0x438) != 0) {
        Free__Q46nw4hbm3snd6detail7AxVoiceFv(*(void **)((u8 *)self + 0x438));
        *(void **)((u8 *)self + 0x438) = 0;
    }
    OSRestoreInterrupts(irqState);
}
extern "C" void Stop__Q46nw4hbm3snd6detail7AxVoiceFv(void*);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*, s32*);
extern "C" const char lbl_80326C1C[];
extern "C" const char lbl_80326BF8[];
extern "C" const char lbl_80326BBC[];
extern "C" const char lbl_80326B98[];
extern "C" const char lbl_80326BEC[];
extern "C" const char lbl_80326BC8[];
extern "C" const char lbl_80326838[];
extern "C" u8 lbl_80415080[];
#pragma use_lmw_stmw reset
#pragma opt_common_subs off
extern "C" void ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(void* self) {
    class Manager {
    public:
        virtual void m0(); virtual void m1(); virtual void m2();
        virtual void m3(void*, u32); virtual void m4(); virtual void m5();
    };
    struct Player {
        char pad[0x94];
        u8 link94[4];
        void *node98;
        u32 tail9C;
        u32 activeHead;
        u32 iterator;
        char pad2[0x438 - 0xA8];
        u32 voice;
    };
    Player *p = (Player *)self;
    struct { u32 irq; } irqHolder;
    irqHolder.irq = OSDisableInterrupts();
    u32 &irq = irqHolder.irq;
    if (p->voice != 0) Stop__Q46nw4hbm3snd6detail7AxVoiceFv((void*)p->voice);
    if (*((u8*)self + 0x49) != 0) {
        if (self == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C4C, 0x233, lbl_80326C28);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(lbl_8041506C, (u8*)self + 8);
        *((u8*)self + 0x49) = 0;
        *((u8*)self + 0x4A) = 0;
    }
    OSRestoreInterrupts(irq);
    ((Manager*)*(void**)((u8*)self + 0x430))->m3(self, *(u32*)((u8*)self + 0x434));
    irq = OSDisableInterrupts();
    if (p->activeHead == 0) goto done;
    s32 iterator;
    s32 eraseValue;
    register void* node = &p->node98;
    goto check;
loop:
    if (p->activeHead == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C1C, 0x1F1, lbl_80326BF8);
    iterator = p->iterator;
    if (iterator == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326BBC, 0x23D, lbl_80326B98);
    s32 count = iterator - 0x14;
    if (count == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326BEC, 0x193, lbl_80326BC8);
    eraseValue = p->iterator;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(&p->activeHead, &eraseValue);
    if (count == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(&p->link94, (void**)&node, (void*)(count + 0x14));
check:
    if (p->activeHead != 0) goto loop;
done:
    OSRestoreInterrupts(irq);
    FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
    *((u8*)self + 0x48) = 0;
}
#pragma opt_common_subs reset
extern "C" void NotifyStrmHeaderAsyncEndCallback__Q46nw4hbm3snd6detail10StrmPlayerFbPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeaderPv(bool success, const void* header, void* player) {
    /* Async callback after reading a stream header: set up the player on success,
       otherwise force it to stop. */
    if (player == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x4E8, lbl_803269A0);
    }
    if (success != 0) {
        Setup__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(player, header);
    } else {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(player);
    }
}

extern "C" void VoiceCallbackFunc__Q46nw4hbm3snd6detail10StrmPlayerFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv(void *voice, s32 status, void *player) {
    const StrmPlayerMsgPool *pool = (const StrmPlayerMsgPool *)lbl_80326768;
    if (player == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(pool->file, 0x504, pool->msg238);
    if (*(void **)((char *)player + 0x438) != voice)
        Panic__Q26nw4hbm2dbFPCciPCce(pool->file, 0x506, pool->msg268);
    if (status < 2) {
        if (status < 0)
            goto invalid_status;
        goto free_voice;
    }
    if (status < 4)
        goto clear_voice;
    goto invalid_status;

free_voice:
    Free__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
    FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(player);
    goto done;

clear_voice:
    *(void **)((char *)player + 0x438) = 0;
    FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(player);
    goto done;

invalid_status:
    Panic__Q26nw4hbm2dbFPCciPCce(pool->file, 0x515, pool->msg298, status);

done:
    return;
}

extern "C" const char lbl_80326C7C[];
extern "C" const char lbl_80326C58[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void NotifyAsyncEnd__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFb(void *self, bool success) {
    u32 token;
    void *list1;
    void *node;
    void *list2;
    void *iterator;
    struct { u32 v; } successBox;
    u32 &successSave = successBox.v;
    successSave = success;
    token = OSDisableInterrupts();
    list1 = (u8 *)*(void **)((u8 *)self + 4) + 0xA0;
    if (self == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
    node = (u8 *)self + 0x14;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(list1, node);
    if (successSave != 0) {
        if (*(u32 *)((u8 *)self + 8) == 0) {
            if (--*(u32 *)((u8 *)*(void **)((u8 *)self + 4) + 0x58) == 0)
                *(u8 *)((u8 *)*(void **)((u8 *)self + 4) + 0x4A) = 1;
        }
    } else {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(*(void **)((u8 *)self + 4));
    }
    list2 = (u8 *)*(void **)((u8 *)self + 4) + 0x94;
    iterator = (u8 *)list2 + 4;
    if (self == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(list2, &iterator, node);
    OSRestoreInterrupts(token);
}
#pragma pop

extern "C" void SetAdpcmLoopContext__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFiPUs(void* self, int count, u16* values) {
    /* Copies up to two ADPCM loop-context samples into the stream and marks it set. */
    void* stream = *(void**)((u8*)self + 4);
    if (*((u8*)stream + 0x10) != 2) return;
    u16 value;
    int offset;
    int index;
    index = 0;
    offset = 0;
    goto loop_check;
loop_body:
    stream = *(void**)((u8*)self + 4);
    ++index;
    value = *values;
    ++values;
    u16* context = (u16*)((u8*)stream + 0x518 + offset);
    offset += 2;
    *context = value;
loop_check:
    if (index < count && index < 2) goto loop_body;
    stream = *(void**)((u8*)self + 4);
    *((u8*)stream + 0x51) = 1;
}

extern "C" int fn_800FD810(void* player, int channel) {
    /* Return the destination address for a channel's current stream block, or 0 if the channel index is out of range. */
    void* stream = *(void**)((char*)player + 4);
    if (channel >= *(int*)((char*)stream + 0x4A0)) {
        return 0;
    }
    return *(int*)((char*)stream + channel * 0x38 + 0x4A8) +
           *(int*)((char*)stream + 0x60) * *(int*)((char*)player + 0x10);
}

/* Return this sound player's float field at +0x454 (paired with setter fn_800FD880). */
extern "C" float fn_800FD848(void *player) { return *(float *)((char *)player + 0x454); }

/* Return this sound player's float field at +0x44C (paired with setter fn_800FD888). */
extern "C" float fn_800FD850(void *player) { return *(float *)((char *)player + 0x44C); }

/* Return this sound player's float field at +0x448 (paired with setter fn_800FD890). */
extern "C" float fn_800FD858(void *player) { return *(float *)((char *)player + 0x448); }

/* Return this sound player's float field at +0x444 (paired with setter fn_800FD898). */
extern "C" float fn_800FD860(void *player) { return *(float *)((char *)player + 0x444); }

/* Return this sound player's float field at +0x440 (paired with setter fn_800FD8A0). */
extern "C" f32 fn_800FD868(void *player) {
    return *(f32 *)((u8 *)player + 0x440);
}

/* Return this sound player's float field at +0x450 (paired with setter fn_800FD8A8). */
extern "C" f32 fn_800FD870(void *player) {
    return *(f32 *)((u8 *)player + 0x450);
}

/* Return this sound player's float field at +0x43C (paired with setter fn_800FD8B0). */
extern "C" f32 fn_800FD878(void *player) {
    return *(f32 *)((u8 *)player + 0x43C);
}

/* Set this sound player's float field at +0x454 (paired with getter fn_800FD848). */
extern "C" void fn_800FD880(void *player, f32 value) {
    *(f32 *)((u8 *)player + 0x454) = value;
}

/* Set this sound player's float field at +0x44C (paired with getter fn_800FD850). */
extern "C" void fn_800FD888(void *player, f32 value) {
    *(f32 *)((u8 *)player + 0x44C) = value;
}

/* Set this sound player's float field at +0x448 (paired with getter fn_800FD858). */
extern "C" void fn_800FD890(void *player, f32 value) {
    *(f32 *)((u8 *)player + 0x448) = value;
}

extern "C" void fn_800FD898(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x444) = arg1;
}

extern "C" void fn_800FD8A0(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x440) = arg1;
}

extern "C" void fn_800FD8A8(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x450) = farg0;
}

extern "C" void fn_800FD8B0(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x43C) = farg0;
}

/* Return nonzero when the sound stream player is paused (its flag at +0x4B). */
extern "C" int fn_800FD8B8(void *player) {
    return *(unsigned char *)((char *)player + 0x4B) != 0;
}

extern "C" int fn_800FD8CC(void *player) {
    /* Return nonzero if this StrmPlayer's active flag (offset 0x49) is set. */
    return *(u8 *)((u8 *)player + 0x49) != 0;
}

extern "C" int fn_800FD8E0(void *player) {
    // Return nonzero when the sound stream player is prepared/ready (its flag at +0x4A).
    return *((unsigned char *)player + 0x4A) != 0;
}

/* Return nonzero when the StrmPlayer has an active/prepared stream set up (its flag at +0x48). */
extern "C" int fn_800FD8F4(void* player) {
    return *((unsigned char*)player + 0x48) != 0;
}

extern "C" void* fn_8002F634(void*, void*, int, int);
extern "C" void* __dt__Q46nw4hbm3snd6detail10StrmPlayerFv(void* self, int shouldDelete) {
    /* Destroy a StrmPlayer: tear down embedded collections/lists and optionally delete. */
    void* list;
    void* list2;
    if (self != 0) {
        fn_8002F634((char*)self + 0xAC, (void*)fn_800FB374, 0x1C, 0x20);
        list = (char*)self + 0xA0;
        if (list != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv(list, 0);
        list2 = (char*)self + 0x94;
        if (list2 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv(list2, 0);
        if (shouldDelete > 0) ((void (*)(void*))fn_80128668)(self);
    }
    return self;
}
extern "C" void Setup__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(void *, const void *);
extern "C" void Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(void *, void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" f32 lbl_805610C0;
extern "C" f32 lbl_805610C4;
extern "C" const char lbl_80326768[];
extern "C" const char lbl_803269A0[];
