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
extern "C" void DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv(void*, unsigned long, void*);
extern "C" void Destroy__Q46nw4hbm3snd6detail9FrameHeapFv(void*);
extern "C" void* __dt__Q46nw4hbm3snd6detail9FrameHeapFv(void*, int);
extern "C" u8 lbl_80325C40[];
extern "C" void Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(void*, unsigned long, void*);
extern "C" void DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(void*, unsigned long, void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" s32 fn_800E9B88(void *);
extern "C" s32 fn_800E9B9C(void *);
extern "C" const char lbl_80325C00[];
extern "C" const char lbl_803263A8[];
extern "C" const char lbl_80326384[];
extern "C" const char lbl_80326378[];
extern "C" const char lbl_80326354[];
extern "C" const char lbl_80325C18[];
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
    if (p && *(void **)((char *)p + 0x1E0) == arg0)
        *(void **)((char *)p + 0x1E0) = 0;
    if (*arg0)
        *arg0 = 0;
}

extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi_800F0E9C(void *arg0, int arg1) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern const char lbl_80324390[];
    extern const char lbl_803243A4[];
    int valid = arg1 >= 0 && arg1 <= 0x10;
    if (!valid)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x25, lbl_803243A4, arg1, 0, 0x10);
    *((unsigned char *)arg0 + 4) = arg1;
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
extern "C" void fn_800F1080(void *arg0, int arg1, int arg2) {
    *(int *)((char *)arg0 + 0x50) = arg1;
    *(int *)((char *)arg0 + 0x54) = arg1 + arg2;
}

extern "C" void Close__Q46nw4hbm3snd6detail8SeqTrackFv(void *self) {
    ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(self, -1);
    u32 interruptState = OSDisableInterrupts();
    void *channel = *(void **)((u8 *)self + 0xB8);
    while (channel != 0) {
        fn_800EAD00(channel);
        channel = *(void **)((u8 *)channel + 0xE4);
    }
    *(void **)((u8 *)self + 0xB8) = 0;
    OSRestoreInterrupts(interruptState);
}

extern "C" void UpdateChannelLength__Q46nw4hbm3snd6detail8SeqTrackFv(void *arg0) {
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
    {
        u32 irq = OSDisableInterrupts();
        void* channel = *(void**)((u8*)arg0 + 0xB8);
        fn_800E402C(Instance__15EmissionManagerFv());
        channel = *(void**)((u8*)arg0 + 0xB8);
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
    pan = 0.0078125f * pan;
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
    f21 += rawp * 0.015625f;
    f21 += M2C_FIELD(self, f32 *, 0x1C);
    f21 += SeqTrackPlayer(self)->g21();
    f32 f20 = 0.0f;
    f20 += (f32)M2C_FIELD(self, u8 *, 0x8F) / 127.0f - 1.0f;
    f20 += M2C_FIELD(self, f32 *, 0x20);
    f20 += SeqTrackPlayer(self)->g31();
    f32 sa[3];
    f32 sb[4];
    f32 sc[4];
    int i;
    f32 *pa = sa;
    u8 *q = (u8 *)self;
    for (i = 0; i < 3; i++) {
        *pa = 0.0f;
        *pa += (f32)M2C_FIELD(self, u8 *, 0x90 + i) / 127.0f;
        *pa += M2C_FIELD(q, f32 *, 0x24);
        *pa += SeqTrackPlayer(self)->g32(i);
        q += 4;
        pa++;
    }
    f32 *pb = sb;
    f32 *pc = sc;
    for (i = 0; i < 4; i++) {
        *pb = 0.0f;
        *pb += SeqTrackPlayer(self)->g34(i);
        *pc = 0.0f;
        *pc += SeqTrackPlayer(self)->g35(i);
        pb++;
        pc++;
    }
    u32 irq = OSDisableInterrupts();
    void *ch;
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
        for (j = 0; j < 4; j++) {
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
extern "C" void FreeAllChannel__Q46nw4hbm3snd6detail8SeqTrackFv(void *arg0) {
    u32 token = OSDisableInterrupts();
    void *channel = *(void **)((char *)arg0 + 0xB8);
    while (channel) {
        fn_800EAD00(channel);
        channel = *(void **)((char *)channel + 0xE4);
    }
    *(void **)((char *)arg0 + 0xB8) = 0;
    OSRestoreInterrupts(token);
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

extern "C" void fn_800F1E50(void *arg0, f32 value) {
    u32 token = OSDisableInterrupts();
    *(f32 *)((char *)arg0 + 8) = value;
    OSRestoreInterrupts(token);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800F1E90(void* self, float volume) {
    if (!(volume >= 0.0f)) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324390, 0x25b, (const char*)lbl_803244D4);
    unsigned int level = OSDisableInterrupts();
    *(float*)((unsigned char*)self + 0xC) = volume;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800F1F04(void* arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((char*)arg0 + 0x10) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F1F44(void* arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((char*)arg0 + 0x14) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" f32 lbl_8056107C;
extern "C" void fn_800F1F84(void* arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((char*)arg0 + 0x18) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F1FC4(void *arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32 *)((char *)arg0 + 0x1C) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F2004(void *arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x68) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F2044(void *arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x6C) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F2084(void* arg0, f32 farg0) {
    u32 level = OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x20) = farg0;
    OSRestoreInterrupts(level);
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
 if(!valid) Panic__Q26nw4hbm2dbFPCciPCce(file,0x30a,file+0x268,key,0,127);
 valid=0; if(vel>=0 && vel<=127) valid=1;
 if(!valid) Panic__Q26nw4hbm2dbFPCciPCce(file,0x30b,file+0x2a0,vel,0,127);
 void *owner = *(void**)(p+0xb4);
 c=0;
 if(reuse && (c=*(void**)(p+0xb8))) {
  *(u32*)((u8*)c+0xcc)=(u8)key;
  f32 x=((f32)vel)/lbl_80561080; *(f32*)((u8*)c+0xb4)=x*x;
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
 if(!p[0x8a]) { if(!arg3) Warning__Q26nw4hbm2dbFPCciPCce(file,0x358,file+0x2e4); fn_800EA8A0(c,arg3,0,pitch); }
 else { s32 n=p[0x8a]*p[0x8a]; f32 scale=pitch>=lbl_8056107C?pitch:-pitch; fn_800EA8A0(c,((s32)((f32)n*scale) >> 5)*5,1,pitch); }
 p[0x89]=(u8)key;
 u16 cur, total; total=*(u16*)((u8*)c+0xc6); cur=*(u16*)((u8*)c+0xc8); u32 enabled=p[0x5d]!=0; u8 val;
 if(cur>=total) val=*((u8*)c+0xc5); else {u8 st=*((u8*)c+0xc4); val=st+(cur*(*((u8*)c+0xc5)-st))/total;}
 *((u8*)c+0xc4)=val; *((u8*)c+0xc5)=enabled?0:255; *(u16*)((u8*)c+0xc6)=0; *(u16*)((u8*)c+0xc8)=0;
 return c;
}

extern "C" void fn_800F26D8(void *arg0) {
    extern char lbl_80324848[];
    *(s32 *)arg0 = (s32)lbl_80324848;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 8) = 0x2F;
    *(u8 *)((u8 *)arg0 + 9) = 0;
}

extern "C" s32 fn_800F26FC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F273C(void *arg0) __attribute__((noinline)) {
    s32 val = *(s32 *)((u8 *)arg0 + 4);
    s32 neg = -val;
    return (neg | val) >> 31 & 1;
}

extern "C" void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi_800F2750(void *arg0, s32 flag) {
    if (flag == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803247E0, 0x46, (const char *)lbl_803247F8);
    }
    *(s32 *)((u8 *)arg0 + 4) = flag;
}

extern "C" void fn_800F27AC(void *arg0) {
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 8) = 0x2F;
    *(u8 *)((u8 *)arg0 + 9) = 0;
}

extern "C" s32 fn_800F27C4(void *arg0) {
    return GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);
#pragma dont_inline on
extern "C" s32 fn_800F27CC(void *arg0) {
    return GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(*(s32*)((u8*)arg0 + 4));
}
#pragma dont_inline off

extern "C" s32 fn_800F27D4(void *arg0, s32 arg1) {
    void *r3 = *(void **)((u8 *)arg0 + 4);
    return ConvertLabelStringToId__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPCQ56nw4hbm3snd6detail16SoundArchiveFile10StringTreePCc(r3, *(void **)((u8 *)r3 + 0x34), arg1);
}

M2C_UNK GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(s32);
extern "C" s32 fn_800F27E4(void *arg0) {
    return GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(s32);
extern "C" s32 fn_800F27EC(void *arg0) {
    return ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(s32);
extern "C" s32 fn_800F27F4(void *arg0) {
    return ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(*(s32*)((u8*)arg0 + 4));
}

extern "C" s32 ReadStrmSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13StrmSoundInfo(void *, u32, void *);
extern "C" s32 fn_800F27FC(void *arg0) {
    typedef s32 (*ReadStrmSoundInfoThunk)(s32);
    return ((ReadStrmSoundInfoThunk)ReadStrmSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13StrmSoundInfo)(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(s32);
extern "C" s32 fn_800F2804(void *arg0) {
    return ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(*(s32*)((u8*)arg0 + 4));
}

extern "C" s32 ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo(void *, u32, void *);
extern "C" s32 fn_800F280C(void *arg0) {
    typedef s32 (*ReadPlayerInfoThunk)(s32);
    return ((ReadPlayerInfoThunk)ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo)(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(s32);
extern "C" s32 fn_800F2814(void *arg0) {
    return ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(*(s32*)((u8*)arg0 + 4));
}

extern "C" s32 ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(void *, u32, void *);
extern "C" s32 fn_800F281C(void *arg0, u32 index, void *out) {
    return ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(*(void **)((u8 *)arg0 + 4), index, out);
}

extern "C" s32 ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(void *, u32, void *);
#pragma dont_inline on
extern "C" s32 fn_800F2824(void *arg0, u32 group, void *out) {
    return ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(*(void **)((u8 *)arg0 + 4), group, out);
}
#pragma dont_inline reset

M2C_UNK ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(s32);
extern "C" s32 fn_800F282C(void *arg0) {
    return ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(s32);
extern "C" s32 fn_800F2834(void *arg0) {
    return ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(s32);
extern "C" s32 fn_800F283C(void *arg0) {
    return ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(*(s32*)((u8*)arg0 + 4));
}

extern "C" s32 ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(void *, u32, void *);
extern "C" s32 ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(void *, u32, u32, void *);
extern "C" s32 ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(void *, u32, u32, void *);
#pragma push
#pragma use_lmw_stmw off
#pragma opt_common_subs off
#pragma opt_dead_code off
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
        }
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
        }
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

extern "C" void fn_800F2D28(void *arg0) {
    *(s32*)((u8*)arg0 + 0x28) = 0;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *(s32*)((u8*)arg0 + 0x30) = 0;
    *(s32*)((u8*)arg0 + 0x34) = 0;
    *(s32*)((u8*)arg0 + 0x38) = 0;
    *(s32*)((u8*)arg0 + 0x3C) = 0;
    *(s32*)((u8*)arg0 + 0x40) = 0;
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
        const s32 *in = (const s32 *)src;
        s32 *out = (s32 *)dst;
        s32 a0 = in[0];
        s32 a1 = in[1];
        out[0] = a0;
        out[1] = a1;
        s32 a2 = in[2];
        s32 a3 = in[3];
        out[2] = a2;
        out[3] = a3;
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
#pragma push
#pragma use_lmw_stmw off
BOOL nw4hbm::snd::detail::SoundArchiveFileReader::ReadSoundInfo(u32 index, nw4hbm::snd::SoundArchive::SoundInfo *info) const {
    register void *archive = *(void **)((u8 *)this + 0x28);
    register u32 soundIndex = index;
    register void *outInfo = info;
    register u8 *base;
    register void *entry;
    if (*((u8 *)archive + 1) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    base = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)archive), *(u32 *)((u8 *)archive + 4), archive);
    if (base == 0) {
        entry = 0;
        goto finish;
    }
    if (soundIndex >= *(u32 *)base) {
        entry = 0;
        goto finish;
    }
    if (*(u16 *)((u8 *)this + 6) >= 0x101) {
        soundIndex <<= 3;
        archive = *(void **)((u8 *)this + 0x28);
        if (base[soundIndex + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
        entry = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(base[soundIndex + 4], *(u32 *)(base + soundIndex + 8), archive);
        goto finish;
    }
    {
        register u32 tmp = soundIndex << 3;
        archive = *(void **)((u8 *)this + 0x28);
        entry = (void *)((u8 *)archive + *(u32 *)(base + tmp + 8));
    }
finish:
    if (entry == 0)
        return 0;
    *(u32 *)outInfo = *(u32 *)((u8 *)entry + 4);
    *(u32 *)((u8 *)outInfo + 4) = *(u32 *)((u8 *)entry + 8);
    *(u32 *)((u8 *)outInfo + 8) = *((u8 *)entry + 0x15);
    *(u32 *)((u8 *)outInfo + 0xC) = *((u8 *)entry + 0x14);
    return 1;
}
#pragma pop
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
    s32 ret = 0;
    if (data != 0)
        ret = 1;
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

extern "C" s32 ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(void *self, u32 index, void *out) {
    extern char lbl_80559848;
    extern char lbl_805598C0;
    extern const char lbl_80559810;
    extern const char lbl_80324ACC[];
    extern const char lbl_80324D60[];
    extern const char lbl_80321F50[];
    register u32 grp = index;
    register void *archive = *(void **)((u8 *)self + 0x28);
    register const void *reader = self;
    register void *outInfo = out;
    register u8 *groupTable;

    if (*((u8 *)archive + 0x21) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_805598A0, 0x6F, lbl_80324CB0);
    groupTable = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        *((u8 *)archive + 0x20), *(u32 *)((u8 *)archive + 0x24), archive);
    if (groupTable == 0)
        grp = 0;
    else if (grp >= *(u32 *)groupTable)
        grp = 0;
    else {
        grp <<= 3;
        archive = *(void **)((u8 *)reader + 0x28);
        if (groupTable[grp + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559848, 0x6F, lbl_80324ACC);
        grp = (u32)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
            groupTable[grp + 4], *(u32 *)(groupTable + grp + 8), archive);
    }
    if (grp == 0)
        return 0;
    archive = *(void **)((u8 *)reader + 0x28);
    if (*((u8 *)grp + 0x21) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_805598C0, 0x6F, lbl_80324D60);
    groupTable = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        *((u8 *)grp + 0x20), *(u32 *)((u8 *)grp + 0x24), archive);
    if (groupTable == 0)
        return 0;
    archive = *(void **)((u8 *)reader + 0x28);
    if (*((u8 *)grp + 9) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559810, 0x6F, lbl_80321F50);
    *(u32 *)((u8 *)outInfo + 4) = (u32)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        *((u8 *)grp + 8), *(u32 *)((u8 *)grp + 0xC), archive);
    *(u32 *)((u8 *)outInfo + 8) = *(u32 *)((u8 *)grp + 0x10);
    *(u32 *)((u8 *)outInfo + 0xC) = *(u32 *)((u8 *)grp + 0x14);
    *(u32 *)((u8 *)outInfo + 0x10) = *(u32 *)((u8 *)grp + 0x18);
    *(u32 *)((u8 *)outInfo + 0x14) = *(u32 *)((u8 *)grp + 0x1C);
    *(u32 *)outInfo = *(u32 *)groupTable;
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
        u32 off = arg1 * 8;
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
        u32 off = arg2 * 8;
        ref = *(u8 **)((u8 *)arg0 + 0x28);
        if (*((u8 *)files + off + 5) != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598B8, 0x6F, lbl_80324D34);
        result = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)files + off + 4), *(u32 *)((u8 *)files + off + 8), ref);
    }
    if (result == 0) return 0;
    ((u32 *)arg3)[0] = result[0]; ((u32 *)arg3)[1] = result[1]; ((u32 *)arg3)[2] = result[2]; ((u32 *)arg3)[3] = result[3]; ((u32 *)arg3)[4] = result[4];
    return 1;
}
extern "C" s32 ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(void *arg0, void *arg1) {
    extern const char lbl_80324D08[];
    extern char lbl_805598B0;
    void *ref;
    void *out;
    void *data;
    ref = *(void **)((char *)arg0 + 0x28);
    out = arg1;
    if (*((u8 *)ref + 0x29) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598B0, 0x6f, lbl_80324D08);
    data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)ref + 0x28), *(u32 *)((char *)ref + 0x2c), ref);
    if (out == 0) return 0;
    *(u32 *)((char *)out + 0x00) = *(u16 *)((char *)data + 0x00);
    *(u32 *)((char *)out + 0x04) = *(u16 *)((char *)data + 0x02);
    *(u32 *)((char *)out + 0x08) = *(u16 *)((char *)data + 0x04);
    *(u32 *)((char *)out + 0x0c) = *(u16 *)((char *)data + 0x06);
    *(u32 *)((char *)out + 0x10) = *(u16 *)((char *)data + 0x08);
    *(u32 *)((char *)out + 0x14) = *(u16 *)((char *)data + 0x0a);
    *(u32 *)((char *)out + 0x18) = *(u16 *)((char *)data + 0x0c);
    return 1;
}

extern "C" const char lbl_80324CDC[];
extern "C" char lbl_805598A8;
extern "C" const char lbl_80324D08[];
extern "C" char lbl_805598B0;
extern "C" s32 GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(void *arg0) {
    void *data = *(void **)((char *)arg0 + 0x28);
    void *p;
    if (*((u8 *)data + 0x11) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A8, 0x6f, lbl_80324CDC);
    p = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)data + 0x10), *(u32 *)((char *)data + 0x14), data);
    if (p == 0)
        return 0;
    return *(s32 *)p;
}

extern "C" s32 GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(void *this_) {
 void *pData;
 void *p;
 pData = *(void**)((u8*)this_ + 0x28);
 if (((u8*)pData)[0x21] != 0) {
   Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A0, 0x6F, lbl_80324CB0);
 }
 p = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(((u8*)pData)[0x20], *(u32*)((u8*)pData + 0x24), pData);
 if (p == 0) return 0;
 return *(s32*)p - 1;
}

extern "C" const char lbl_80559898;
extern "C" const char lbl_80559888;
extern "C" const char lbl_80559890;
extern "C" const char lbl_80559810;
extern "C" const char lbl_80324C84[];
extern "C" const char lbl_80324C2C[];
extern "C" const char lbl_80324C58[];
extern "C" const char lbl_80321F50[];
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(void *arg0, u32 arg1, void *arg2) {
    register u8 *archive = *(u8 **)((u8 *)arg0 + 0x28);
    register void *self = arg0;
    register u32 idx = arg1;
    register void *out = arg2;
    register u8 *files;
    register u8 *detail;
    u8 *info;
    u8 *player;
    void *base;
    if (archive[0x19] != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559898, 0x6F, lbl_80324C84);
    files = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(archive[0x18], *(u32 *)(archive + 0x1C), archive);
    if (files == 0) return 0;
    if (idx >= *(u32 *)files) return 0;
    {
        u32 off = idx << 3;
        info = files + off;
    }
    base = *(void **)((u8 *)self + 0x28);
    if (info[5] != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559888, 0x6F, lbl_80324C2C);
    detail = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(info[4], *(u32 *)(info + 8), base);
    if (detail == 0) return 0;
    base = *(void **)((u8 *)self + 0x28);
    if (detail[0x15] != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559890, 0x6F, lbl_80324C58);
    player = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(detail[0x14], *(u32 *)(detail + 0x18), base);
    if (player == 0) return 0;
    *(u32 *)out = *(u32 *)detail;
    *(u32 *)((u8 *)out + 4) = *(u32 *)(detail + 4);
    base = *(void **)((u8 *)self + 0x28);
    if (detail[0xD] != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559810, 0x6F, lbl_80321F50);
    *(void **)((u8 *)out + 8) = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(detail[0xC], *(u32 *)(detail + 0x10), base);
    *(u32 *)((u8 *)out + 0xC) = *(u32 *)player;
    return 1;
}
#pragma use_lmw_stmw off
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
extern "C" u64 impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(void *self, unsigned long index) {
    u8 *ref = *(u8 **)((u8 *)self + 0x28);
    if (ref[1] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    u8 *base = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0], *(u32 *)(ref + 4), ref);
    if (base == 0)
        return lbl_8055DE50;
    if (index >= *(u32 *)base)
        return lbl_8055DE50;
    if (*(u16 *)((u8 *)self + 6) >= 0x101) {
        index <<= 3;
        ref = *(u8 **)((u8 *)self + 0x28);
        if (base[index + 5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
        u8 *entry = base + index;
        u8 *data = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[4], *(u32 *)(entry + 8), ref);
        if (data == 0)
            return lbl_8055DE50;
        return *(u64 *)(data + 0x18);
    }
    u8 *entry = base + index * 8;
    struct Result { u8 type; u8 ext; u16 pad; u32 offset; } result;
    result.type = entry[4];
    result.ext = entry[5];
    result.offset = *(u32 *)(entry + 8) + 0x1C;
    return *(u64 *)&result;
}
#pragma pop
extern "C" void *fn_800F41D0(void *arg0, s32 arg1) {
 *(s32*)((u8*)arg0 + 0x18) = arg1;
 *(s32*)((u8*)arg0 + 0x21C) = 0;
 OSInitMutex(arg0);
 return arg0;
}

extern "C" s32 fn_800F420C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
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
    typedef ArchiveStream Stream; /* the archive stream, described above */
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
    char *buf = (char *)((Allocator *)allocator)->Alloc(stream->GetSize());
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
        char *p = buf;
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
                p += blockSize;
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
        char *buf2 = (char *)((Allocator *)allocator)->Alloc(stream2->GetSize());
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
            char *p = buf2;
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
                    p += blockSize;
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

extern "C" s32 fn_800F4CC4(s32 arg0, s32 arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" s32 fn_800F4D04(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4D44(s32 arg0, s32 arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" s32 fn_800F4D84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4DC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4E04(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4E44(s32 arg0, s32 arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" s32 fn_800F4E84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4EC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800F4F04(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F24(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void fn_800F4F7C(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F9C(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void fn_800F4FF4(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F5014(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
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
#pragma use_lmw_stmw off
extern "C" s32 SetupMram__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePvUl(void *self, const void *archive, void *buffer, u32 size) {
    struct GroupEntry { u32 a; u32 b; };
    struct GroupList { u32 count; GroupEntry entries[1]; };
    struct SoundInfo { u32 counts[7]; };
    struct Local { u32 cursor; struct SoundInfo info; } local;
    const char *base = lbl_80324E88;
    u32 end;
    u32 ptr;
    u32 aligned;
    u32 created;
    u32 i;
    s32 count;
    s32 result;

    if (archive == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x139, base + 0x1C);
    if (buffer == 0)
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
        *(u32 *)((u8 *)self + 0x14) = local.cursor;
        local.cursor = aligned;
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

        ptr = local.cursor;
        count = local.info.counts[2];
        aligned = (count * 0x614 + ptr + 3) & ~3U;
        if ((s32)(aligned - end) > 0) {
            result = 0;
        } else {
            if (ptr == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325A1C, 0x3B, lbl_803259F0);
            created = CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl((u8 *)self + 0x88, (void *)ptr, count * 0x614, 0x614);
            if (created != (u32)count)
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x24C, base + 0x174);
            local.cursor = aligned;
            result = 1;
        }
        if (result == 0)
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

#pragma use_lmw_stmw off
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
        u32 k = 0;
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
        u32 k = 0;
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
        u32 k = 0;
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
    void *sound;
    void *stream;
    register s32 startOffset;
    register s32 playerIndex;
    register s32 startPosition;
    register s32 soundCount;
    register u32 soundIndex;
    register s32 loop;
    register s32 result;
    register s32 soundType;
    register s32 priority;

    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x39F, fileName + 0x480);
    }
    if (*(void **)((u8 *)arg0 + 0x10) == 0) {
        result = 0;
    } else {
        result = fn_800F273C(*(void **)((u8 *)arg0 + 0x10));
    }
    if (result == 0) {
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
        result = PrepareSeqImpl__Q36nw4hbm3snd18SoundArchivePlayerFPQ46nw4hbm3snd6detail8SeqSoundPCQ46nw4hbm3snd12SoundArchive9SoundInfoPCQ46nw4hbm3snd12SoundArchive12SeqSoundInfoi(arg0, sound, stack.local.soundInfo, stack.local.seqInfo, startOffset);
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
        if (sound == 0) {
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
        virtual unsigned long getSize() = 0;
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
        virtual void setRate(float) = 0;
    };
    union { unsigned long words[2]; double value; } conversion;
    unsigned char streamBuffer[0x200];
    unsigned char reader[8];
    void *fileData;
    void *stream;
    void *memory;
    unsigned long fileSize;
    s32 status;
    unsigned long volume;
    float rate;
    void *base;
    if (seqSoundInfo == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x469, lbl_80325334);
    fileData = (void *)detail_GetFileAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl(player, *(unsigned long *)soundInfo);
    if (fileData == 0) {
        memory = *(void **)((unsigned char *)seqSound + 4);
        if (memory == 0)
            return 4;
        stream = detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(*(void **)((unsigned char *)player + 0x10), *(unsigned long *)soundInfo, streamBuffer, 0x200);
        OSLockMutex((unsigned char *)memory + 4);
        fileSize = fn_800EC56C((void **)((unsigned char *)memory + 0x1C));
        OSUnlockMutex((unsigned char *)memory + 4);
        if (fileSize < ((StreamProxy *)stream)->getSize()) {
            if (stream != 0)
                ((StreamProxy *)stream)->close();
            return 5;
        }
        if (stream != 0)
            ((StreamProxy *)stream)->close();
    }
    status = Setup__Q46nw4hbm3snd6detail8SeqSoundFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback(seqSound, *(void **)((unsigned char *)player + 0x68), *(unsigned long *)((unsigned char *)seqSoundInfo + 8), offset, (unsigned char *)player + 0x38);
    if (status != 0) {
        if (status == 1)
            return 8;
        return 0xFF;
    }
    volume = *(unsigned long *)((unsigned char *)soundInfo + 0xC);
    conversion.words[0] = 0x43300000;
    conversion.words[1] = volume ^ 0x80000000;
    rate = (float)(conversion.value - lbl_805610B0);
    rate /= lbl_805610A8;
    ((SeqSoundProxy *)seqSound)->setRate(rate);
    SetChannelPriority__Q46nw4hbm3snd6detail8SeqSoundFi(seqSound, *(int *)((unsigned char *)seqSoundInfo + 0xC));
    if (fileData != 0) {
        __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(reader, fileData);
        base = GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(reader);
        Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCvl(seqSound, base, *(s32 *)seqSoundInfo);
    } else {
        Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCQ56nw4hbm3snd6detail8SeqSound15SeqLoadCallbackUl(seqSound, (const void *)((unsigned char *)player + 0x18), (unsigned long)seqSound);
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
extern "C" void InvalidateData__Q34nw4r3snd18SoundArchivePlayerFPCvPCv(void* self, u32 start, u32 end) {
    if (*(u32**)((u8*)self + 0x14) == 0) return;
    u32 offset;
    u32* entries;
    u32 index;
    u32 zero;
    index = 0;
    offset = 0;
    zero = 0;
    goto loop_check;
    do {
        u32* entry = (u32*)((u8*)entries + offset);
        u32 value = entry[1];
        if (!(start > value) && !(value > end)) entry[1] = zero;
        offset += 8;
        ++index;
    loop_check:
        entries = *(u32**)((u8*)self + 0x14);
    } while (index < entries[0]);
}

extern "C" void InvalidateData__Q34nw4r3snd18SoundArchivePlayerFPCvPCv_800F6F18(void* self, u32 start, u32 end) {
    if (*(u32**)((u8*)self + 0x14) == 0) return;
    u32 offset;
    u32* entries;
    u32 index;
    u32 zero;
    index = 0;
    offset = 0;
    zero = 0;
    goto loop_check;
    do {
        u32* entry = (u32*)((u8*)entries + offset);
        u32 value = entry[2];
        if (!(start > value) && !(value > end)) entry[2] = zero;
        offset += 8;
        ++index;
    loop_check:
        entries = *(u32**)((u8*)self + 0x14);
    } while (index < entries[0]);
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
    unsigned long id = taskId;
    void* manager = ((void* (*)(void))fn_800FDE60)();
    ((void (*)(void*, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(manager, id);
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
extern "C" s32 GetWaveSoundData__Q46nw4hbm3snd18SoundArchivePlayer11WsdCallbackCFPQ46nw4hbm3snd6detail13WaveSoundInfoPQ46nw4hbm3snd6detail17WaveSoundNoteInfoPQ46nw4hbm3snd6detail8WaveDataPCviiUl(void *self, void *info, void *noteInfo, void *waveData, const void *file, int index, int noteIndex, unsigned long waveIndex) {
    struct BankReader { void *a; void *b; void *c; } reader;
    unsigned long waveAddress;
    if ((*(void **)(*(u8 **)((u8 *)self + 4) + 0x10) == 0 ? 0 : fn_800F273C(*(void **)(*(u8 **)((u8 *)self + 4) + 0x10))) == 0)
        return 0;
    if (*(unsigned long *)(*(u8 **)((u8 *)self + 4) + 0x10) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x2AC, lbl_80325110);
    waveAddress = detail_GetFileWaveDataAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl_800F6490(*(void **)((u8 *)self + 4), waveIndex);
    if (waveAddress == 0) return 0;
    __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv_800FFECC(&reader, file);
    if (ReadWaveSoundInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail13WaveSoundInfoi(&reader, info, index) == 0) return 0;
    if (ReadWaveSoundNoteInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail17WaveSoundNoteInfoii(&reader, noteInfo, index, noteIndex) == 0) return 0;
    return ReadWaveParam__Q46nw4hbm3snd6detail13WsdFileReaderCFiPQ46nw4hbm3snd6detail8WaveDataPCv(&reader, *(int *)noteInfo, waveData, (const void *)waveAddress);
}

extern "C" s32 fn_800F73E4(void *self, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register const char *base = lbl_80324E88;
    void *reader = *(void **)((u8 *)self + 4);
    void *fileInfo = *(void **)((u8 *)reader + 0x10);
    void *task = 0;
    if (fileInfo == 0)
        return 0;
    if (fn_800F273C(fileInfo) == 0)
        return 1;
    task = Alloc__Q46nw4hbm3snd6detail11TaskManagerFv(fn_800FDE60());
    if (task == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x64C, base + 0x590);
    reader = *(void **)((u8 *)self + 4);
    if (*(void **)((u8 *)reader + 0x10) == 0)
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
    register void *fileInfo = *(void **)((u8 *)reader + 0x10);
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
    fileInfo = *(void **)((u8 *)reader + 0x10);
    void *task = Alloc__Q46nw4hbm3snd6detail11TaskManagerFv(fn_800FDE60());
    if (task == 0)
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x67B, base + 0x590);
    if (fn_800FE0DC(fn_800FDE60()) < 0x40)
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0, 0x67D, base + 0x628);
    if (task != 0) {
        task = __ct__Q46nw4hbm3snd18SoundArchivePlayer16StrmDataLoadTaskFPvUlliUllbRQ56nw4hbm3snd6detail10StrmPlayer11LoadCommandRCQ36nw4hbm3snd12SoundArchiveUlUlR7OSMutex(
            task, arg1, arg2, arg3, arg4, arg5, arg6, arg7,
            arg8, *(const __StrmSoundArchiveRef *)fileInfo,
            arg10, arg9, *(__StrmMutexRef *)((u8 *)self + 8));
    }
    AppendTask__Q46nw4hbm3snd6detail11TaskManagerFPQ46nw4hbm3snd6detail4TaskQ56nw4hbm3snd6detail11TaskManager12TaskPriority(fn_800FDE60(), task, 2);
    fn_800FE804(fn_800FE648());
    return 3;
}

#pragma pop

extern "C" void fn_800F768C(void *self, unsigned long taskId) {
    unsigned long id = taskId;
    void* manager = ((void* (*)(void))fn_800FDE60)();
    ((void (*)(void*, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(manager, id);
}

extern "C" s32 fn_800F76C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void* LoadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatable(void*, unsigned int, void*);
extern "C" void* __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(void*, void*);
extern "C" void* GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(void*);
extern "C" void Execute__Q46nw4hbm3snd18SoundArchivePlayer11SeqLoadTaskFv(void* arg0) {
    char buffer[0x220];
    char reader[8];
    void* mutex;
    void* p;
    void* callback;
    void* base;

    fn_800F41D0(buffer, *(s32*)((char*)arg0 + 0x14));
    mutex = *(void**)((char*)arg0 + 0x2c);
    OSLockMutex(mutex);
    p = buffer;
    *(void**)((char*)arg0 + 0x10) = p;
    OSUnlockMutex(mutex);
    p = LoadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatable(p, *(u32*)((char*)arg0 + 0x18), *(void**)((char*)arg0 + 0x20));
    mutex = *(void**)((char*)arg0 + 0x2c);
    OSLockMutex(mutex);
    *(void**)((char*)arg0 + 0x10) = 0;
    OSUnlockMutex(mutex);
    if (p == 0) {
        callback = *(void**)((char*)arg0 + 0x24);
        if (callback) ((void (*)(s32, void*, s32, void*))callback)(0, 0, 0, *(void**)((char*)arg0 + 0x28));
        fn_800F420C((s32)buffer, -1);
        return;
    }
    __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(reader, p);
    base = (void*)GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(reader);
    callback = *(void**)((char*)arg0 + 0x24);
    if (callback) ((void (*)(s32, void*, s32, void*))callback)(1, base, *(s32*)((char*)arg0 + 0x1c), *(void**)((char*)arg0 + 0x28));
    fn_800F420C((s32)buffer, -1);
}

extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer11SeqLoadTaskFv(void* self) {
    void* mutex = *(void**)((char*)self + 0x2c);
    OSLockMutex(mutex);
    void* loader = *(void**)((char*)self + 0x10);
    if (loader)
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
        if (cb != 0) cb(0, 0, *(u32*)((u8*)self + 0x20));
        return;
    } else {
        if (lbl_8055DE58 == 0) {
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
            if (cb != 0) cb(0, 0, *(u32*)((u8*)self + 0x20));
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
            if ((((u32)(-f.valid | f.valid) >> 31) == 0)) {} else fn_800FACC0(&f.valid, (void*)((u8*)f.adpcm + off), i);
        }
        Cb_t cb2 = *(Cb_t*)((u8*)self + 0x1C);
        if (cb2 != 0) cb2(1, f.header, *(u32*)((u8*)self + 0x20));
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
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80324E88[0x6c0 - 0x6c0], 0x762, base + 0x6c0, arg1);
    if (((u32)arg2 & 31) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80324E88[0x708 - 0x708], 0x763, base + 0x708, (u32)arg2);
    if (((u32)arg3 & 3) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80324E88[0x750 - 0x750], 0x764, base + 0x750, (u32)arg3);
    return self;
}
#pragma pop

extern "C" void DCInvalidateRange(s32, u32);
extern "C" void DCFlushRange(s32, s32);
extern "C" void *memcpy(void *, const void *, u32);
extern "C" int fn_800FD810(void *, int);
extern "C" void SetAdpcmLoopContext__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFiPUs(void *, int, u16 *);
extern "C" u8 lbl_8055DE98;
extern "C" const char lbl_80325624[];
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" void Execute__Q46nw4hbm3snd18SoundArchivePlayer16StrmDataLoadTaskFv(void *arg0) {
    s16 sp8;
    u8 padding[6];
    u8 sp10[0x200];
    s16 *var_r31;
    s32 temp_r25;
    s32 temp_r26;
    register s32 temp_r27;
    register s32 temp_r29_2;
    register s32 temp_r30_2;
    register s32 temp_r5;
    u8 *temp_r6;
    s32 var_r0;
    s32 var_r29_2;
    void **temp_r3;
    void **temp_r3_10;
    void **temp_r3_2;
    void **temp_r3_3;
    void **temp_r3_4;
    void **temp_r3_5;
    void **temp_r3_6;
    void **temp_r3_7;
    void **temp_r3_8;
    void **temp_r3_9;
    void **var_r3;
    register u32 temp_r29;
    register void *temp_r30;

    DCInvalidateRange(M2C_FIELD(arg0, s32 *, 0x20), M2C_FIELD(arg0, u32 *, 0x24));
    temp_r29 = (u32)M2C_FIELD(arg0, void **, 0x3C);
    OSLockMutex((void *)temp_r29);
    M2C_FIELD(arg0, void ***, 0x14) = (void **)detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi((void *)M2C_FIELD(arg0, s32 *, 0x18), (unsigned long)M2C_FIELD(arg0, s32 *, 0x1C), &sp10, 0x200);
    OSUnlockMutex((void *)temp_r29);
    temp_r3 = M2C_FIELD(arg0, void ***, 0x14);
    if (temp_r3 == 0) {
        temp_r3_2 = M2C_FIELD(arg0, void ***, 0x10);
        if (temp_r3_2 != 0) {
            ((DummyStrmLoadTaskCallback *)temp_r3_2)->f2(0);
        }
    } else if ((((DummyStrmLoadStream *)temp_r3)->f20() == 0) || (temp_r3_3 = M2C_FIELD(arg0, void ***, 0x14), ((DummyStrmLoadStream *)temp_r3_3)->f11() == 0)) {
        temp_r3_4 = M2C_FIELD(arg0, void ***, 0x14);
        ((DummyStrmLoadStream *)temp_r3_4)->f4();
        temp_r3_5 = M2C_FIELD(arg0, void ***, 0x10);
        M2C_FIELD(arg0, void ***, 0x14) = 0;
        if (temp_r3_5 != 0) {
            ((DummyStrmLoadTaskCallback *)temp_r3_5)->f2(0);
        }
    } else {
        temp_r29 = (u32)M2C_FIELD(arg0, void ***, 0x14);
        temp_r30 = (void *)&lbl_8055DE98;
        var_r3 = (void **)((DummyStrmLoadCallback *)(void *)temp_r29)->f2();
        goto loop_11_check;
loop_11_check:
        if (var_r3 == (void **)temp_r30) {
            var_r0 = 1;
            goto loop_11_result;
        }
loop_11_body:
        var_r3 = (void **)*var_r3;
        if (var_r3 != 0) {
            goto loop_11_check;
        }
        var_r0 = 0;
loop_11_result:
        if (var_r0 == 0) {
            goto loop_11_no_clear;
        }
        goto loop_11_clear;
loop_11_no_clear:
        goto loop_11_done;
loop_11_clear:
        temp_r29 = 0;
loop_11_done:
        if (temp_r29 != 0) {
            M2C_FIELD((void *)temp_r29, s32 *, 0x68) = 1;
        }
        temp_r3_6 = M2C_FIELD(arg0, void ***, 0x14);
        ((DummyStrmLoadStream *)temp_r3_6)->f17(M2C_FIELD(arg0, s32 *, 0x28), 0);
        temp_r3_7 = M2C_FIELD(arg0, void ***, 0x14);
        temp_r29_2 = ((DummyStrmLoadStream *)temp_r3_7)->f5((void *)M2C_FIELD(arg0, void **, 0x20), M2C_FIELD(arg0, u32 *, 0x24));
        temp_r30 = (void *)M2C_FIELD(arg0, void **, 0x3C);
        OSLockMutex(temp_r30);
        temp_r3_8 = M2C_FIELD(arg0, void ***, 0x14);
        ((DummyStrmLoadStream *)temp_r3_8)->f4();
        M2C_FIELD(arg0, void ***, 0x14) = 0;
        OSUnlockMutex(temp_r30);
        if (temp_r29_2 != -3) {
            if ((u32)temp_r29_2 != (u32)M2C_FIELD(arg0, u32 *, 0x24)) {
                if (temp_r29_2 == 0) {
                    Warning__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80324E88, 0x79C, (const char *)&lbl_80325624);
                }
                temp_r3 = (void **)((void *(*)(void))fn_800FDE60)();
                ((void (*)(void *, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(temp_r3, M2C_FIELD(arg0, u32 *, 0xC));
                temp_r3_9 = M2C_FIELD(arg0, void ***, 0x10);
                if (temp_r3_9 != 0) {
                    ((DummyStrmLoadTaskCallback *)temp_r3_9)->f2(0);
                }
            } else {
                temp_r30_2 = M2C_FIELD(arg0, s32 *, 0x20);
                var_r31 = &sp8;
                for (var_r29_2 = 0; var_r29_2 < (s32)M2C_FIELD(arg0, s32 *, 0x2C); var_r29_2++) {
                    if ((s32)M2C_FIELD(arg0, u8 *, 0x38) != 0) {
                        *var_r31 = *(u8 *)(var_r29_2 * ((M2C_FIELD(arg0, s32 *, 0x30) + 0x1F) & 0xFFFFFFE0) + (temp_r30_2 + M2C_FIELD(arg0, s32 *, 0x34)));
                    }
                    if ((void **)M2C_FIELD(arg0, void ***, 0x10) != 0) {
                        temp_r5 = M2C_FIELD(arg0, s32 *, 0x30) + 0x1F;
                        temp_r26 = temp_r5 & 0xFFFFFFE0;
                        temp_r6 = (u8 *)M2C_FIELD(arg0, void **, 0x20);
                        var_r0 = M2C_FIELD(arg0, s32 *, 0x34);
                        temp_r5 = var_r29_2 * temp_r26;
                        temp_r25 = (s32)(temp_r6 + var_r0 + temp_r5);
                        temp_r27 = fn_800FD810(M2C_FIELD(arg0, void **, 0x10), var_r29_2);
                        memcpy((void *)temp_r27, (void *)temp_r25, temp_r26);
                        DCFlushRange(temp_r27, temp_r26);
                    }
                    var_r31 += 1;
                }
                if (((s32)M2C_FIELD(arg0, u8 *, 0x38) != 0) && ((void **)M2C_FIELD(arg0, void ***, 0x10) != 0)) {
                    SetAdpcmLoopContext__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFiPUs(M2C_FIELD(arg0, void **, 0x10), M2C_FIELD(arg0, s32 *, 0x2C), (u16 *)&sp8);
                }
                temp_r3_10 = M2C_FIELD(arg0, void ***, 0x10);
                if (temp_r3_10 != 0) {
                    ((DummyStrmLoadTaskCallback *)temp_r3_10)->f2(1);
                }
            }
        }
    }
}
#pragma scheduling on
#pragma use_lmw_stmw on
#pragma cplusplus reset

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
#pragma dont_inline on
#pragma small_data off
u32 nw4hbm::snd::SoundArchivePlayer::detail_ConvertLabelStringToSoundId(const char *label) {
    if (*(u32 *)((u8 *)this + 0x10) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325BE8, 0x163, (const char *)lbl_80325BB8);
    }
    return (u32)fn_800F27D4(*(void **)((u8 *)this + 0x10), (s32)label);
}
#pragma pop
extern "C" void *__dt__Q36nw4hbm3snd9SoundHeapFv(void*, int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8114(void *arg0, int arg1) {
 if(arg0) { __dt__Q36nw4hbm3snd9SoundHeapFv(arg0,0); if(arg1>0) ((void(*)(void*))fn_80128668)(arg0); }
 return arg0;
}

extern "C" s32 fn_800F816C(s32 arg0, s32 arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" s32 fn_800F81AC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F81EC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800F822C(s32 arg0) {
    detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(arg0 - 0xC);
}

extern "C" s32 fn_800F65F0(void *, void **, u32, s32, s32, s32, void *, s32);
extern "C" void fn_800F8234(s32 arg0) {
    ((s32 (*)(s32))fn_800F65F0)(arg0 - 0xC);
}

extern "C" void *__dt__Q36nw4hbm3snd18SoundArchivePlayerFv(void *, s32);
extern "C" void fn_800F823C(s32 arg0, s32 arg1) {
    __dt__Q36nw4hbm3snd18SoundArchivePlayerFv((void *)(arg0 - 0xC), arg1);
}

extern "C" void detail_AttachSound__Q36nw4hbm3snd11SoundHandleFPQ46nw4hbm3snd6detail10BasicSound(void **arg0, void *arg1) {
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325C00, 0x55, lbl_80325C18);
    }
    *arg0 = arg1;
    if (fn_800E9B88(arg1) != 0) {
        fn_800E9B9C(*arg0);
    }
    *(void **)((u8 *)*arg0 + 8) = arg0;
}

void DetachSound__Q34nw4r3snd11SoundHandleFv(void **arg0) {
 void *p=*arg0;
 if(p) {
  if(*(u32*)((u8*)p+8)==(u32)arg0) *(u32*)((u8*)p+8)=0;
  p=*arg0;
  if(*(u32*)((u8*)p+0xc)==(u32)arg0) *(u32*)((u8*)p+0xc)=0;
 }
 if(*arg0==0) return;
 *arg0=0;
}

#pragma push
#pragma small_data off
extern "C" void* fn_800F8310(void* self) {
    *(void**)self = (void*)lbl_80325C40;
    fn_800EBB88((char*)self + 0x1C);
    OSInitMutex((char*)self + 4);
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
extern "C" void fn_800F83C8(void* arg0) {
    Create__Q46nw4hbm3snd6detail9FrameHeapFPvUl((u8*)arg0 + 0x1C);
}

extern "C" void fn_800F83D0(void* arg0) {
    Destroy__Q46nw4hbm3snd6detail9FrameHeapFv((u8*)arg0 + 0x1C);
}

extern "C" void* fn_800F83D8(void* arg0, unsigned long arg1) {
    void* mutex = (u8*)arg0 + 4;
    OSLockMutex(mutex);
    void* result = Alloc__Q46nw4hbm3snd6detail9FrameHeapFUlPFPvUlPv_vPv(
        (u8*)arg0 + 0x1C, arg1, DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv, 0);
    OSUnlockMutex(mutex);
    return result;
}

extern "C" void DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv(void* arg0, unsigned long arg1, void* arg2) {
    Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(arg0, arg1, arg2);
    DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(arg0, arg1, arg2);
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

extern "C" void fn_800F8520(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8540(void* arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
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
        while (it != head) {
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
void Update__Q36nw4hbm3snd11SoundPlayerFv(void *self) {
    struct Dummy {
        virtual ~Dummy();
        virtual void f0();
        virtual void update();
    };
    void *end = (u8 *)self + 4;
    void *head = *(void **)((u8 *)self + 4);
    void *node;
    while (head != end) {
        node = head;
        head = *(void **)node;
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262E8, 0x23D, (const char *)lbl_803262C4);
        }
        ((Dummy *)((u8 *)node - 0xC0))->update();
    }
    detail_SortPriorityList__Q36nw4hbm3snd11SoundPlayerFv(self);
}
#pragma use_lmw_stmw off
void StopAllSound__Q36nw4hbm3snd11SoundPlayerFi(void *self, s32 arg1) {
    struct Dummy {
        virtual ~Dummy();
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void stopAllSound(s32);
    };

    void *end = (u8 *)self + 4;
    void *head = *(void **)((u8 *)self + 4);
    void *node;

    while (head != end) {
        node = head;
        head = *(void **)node;
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262E8, 0x23D, (const char *)lbl_803262C4);
        }
        ((Dummy *)((u8 *)node - 0xC0))->stopAllSound(arg1);
    }
}
#pragma use_lmw_stmw reset
extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800F877C(void *arg0, f32 farg0) {
    if (!(farg0 >= 0.0f)) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x99, lbl_80325C64);
    *(f32 *)((u8 *)arg0 + 0x28) = farg0;
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

void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(void *self, void *pSound) {
    if (pSound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262B8, 0x233, (const char *)lbl_80326294);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(self, (u8 *)pSound + 0xC0);
    *(u32 *)((u8 *)pSound + 0x10) = 0;
}

#pragma use_lmw_stmw off
extern "C" void detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *self, void *sound) {
    void *head = (char *)self + 0x10;
    void *node;
    for (node = *(void **)((char *)self + 0x10); node != head; node = *(void **)node) {
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326348, 0x23D, (const char *)lbl_80326324);
        int priority = *(unsigned char *)((char *)node - 0x54) + *(int *)((char *)node - 0x88);
        priority = priority > 127 ? 127 : (priority < 0 ? 0 : priority);
        int soundPriority = *(unsigned char *)((char *)sound + 0x74) + *(int *)((char *)sound + 0x40);
        soundPriority = soundPriority > 127 ? 127 : (soundPriority < 0 ? 0 : soundPriority);
        if (soundPriority < priority)
            break;
    }
    if (sound == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326288, 0x233, (const char *)lbl_80326264);
    void *iterator = node;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)self + 0xC, &iterator, (char *)sound + 0xC8);
}
#pragma use_lmw_stmw reset
extern "C" void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *self, void *pSound) {
    if (pSound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326288, 0x233, (const char *)lbl_80326264);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)self + 0xC, (u8 *)pSound + 0xC8);
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
extern "C" void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi(
    void* this_, s32 limit) {
    if (limit < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325C50, 0x227,
                                     (const char*)lbl_80325D48);
    }
    *(u16*)&((u8*)this_)[0x26] = (u16)limit;
}

extern "C" void *GetLowestPrioritySound__Q46nw4hbm3snd6detail19ExternalSoundPlayerFv(void *);
extern "C" const char lbl_803263A8[];
extern "C" const char lbl_80326384[];
extern "C" const char lbl_80326378[];
extern "C" const char lbl_80326354[];
#pragma use_lmw_stmw off
extern "C" int CheckPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFiPQ46nw4hbm3snd6detail19ExternalSoundPlayer(void *self, int priority, void *external) {
    int limit;
    u8 *first;
    u8 *sound;
    if (*(u16 *)((u8 *)self + 0x24) == 0)
        return 0;
    while (*(s32 *)self >= *(u16 *)((u8 *)self + 0x24)) {
        if (*(s32 *)((u8 *)self + 0xC) == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803263A8, 0x1F1, lbl_80326384);
        first = *(u8 **)((u8 *)self + 0x10);
        if (first == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326348, 0x23D, lbl_80326324);
        sound = first - 0xC8;
        if (sound == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326378, 0x193, lbl_80326354);
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
        do {
            sound = (u8 *)GetLowestPrioritySound__Q46nw4hbm3snd6detail19ExternalSoundPlayerFv(external);
            if (sound == 0)
                return 0;
            limit = sound[0x74] + *(s32 *)(sound + 0x40);
            limit = (limit > 0x7F) ? 0x7F : ((limit < 0) ? 0 : limit);
            if (priority < limit)
                return 0;
            ((DummyCheckPlayable *)sound)->f7();
        } while (*(s32 *)external >= *(u16 *)((u8 *)external + 0xC));
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

extern "C" void* detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(void* this_, void* pHandle, unsigned long id, void* pAmbient, void* pPlayer, void* pInfo) {
    struct Base {
        virtual void d0();
        virtual void* Start(void*, unsigned long, void*, void*, int, void*);
    };
    struct Sound {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void Attach();
    };
    void* sound = ((Base*)this_)->Start(pHandle, id, pAmbient, pPlayer, 0, pInfo);
    if (sound) {
        return sound;
    }
    void* h = *(void**)pHandle;
    if (h) {
        ((Sound*)h)->Attach();
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
        volatile unsigned long *base = (volatile unsigned long *)lbl_80412CC8;
        void *object = (void *)((u8 *)base + 0x2388);
        base[0x2388 / 4] = 0;
        base[0x238c / 4] = 0;
        base[0x2378 / 4] = 0;
        base[0x237c / 4] = 0;
        base[0x2384 / 4] = 0;
        base[0x2388 / 4] = (unsigned long)object;
        base[0x238c / 4] = (unsigned long)object;
        ((volatile u8 *)base)[0x2394] = 0;
        __register_global_object((void *)base, (void *)&__dt__10TitleSceneFv, (void *)&lbl_80412CB8, object);
        lbl_8055DE68 = 1;
    }
    return (void *)lbl_80412CC8;
}
#pragma pop
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
    if (thread[0x2394] != 0) return 1;
    thread[0x2394] = 1;
    if (((u8 *)Instance__15EmissionManagerFv())[0x6c30] == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326450, 0x44, lbl_80326464);
    OSInitThreadQueue(thread + 0x2318);
    OSInitMutex(thread + 0x2320);
    if ((s8)lbl_8055DE68 == 0) {
        volatile u32 *base = (volatile u32 *)lbl_80412CC8;
        void *dtor = (void *)__dt__10TitleSceneFv;
        void *object = (void *)((u8 *)base + 0x2388);
        base[0x2388 / 4] = 0;
        base[0x238c / 4] = 0;
        base[0x2378 / 4] = 0;
        base[0x237c / 4] = 0;
        base[0x2384 / 4] = 0;
        base[0x2388 / 4] = (u32)object;
        base[0x238c / 4] = (u32)object;
        ((volatile u8 *)base)[0x2394] = 0;
        __register_global_object((void *)base, dtor, (void *)&lbl_80412CB8, object);
        lbl_8055DE68 = 1;
    }
    result = OSCreateThread(arg0, (void *)fn_800FA77C, (void *)lbl_80412CC8, thread + 0x2318, 0x2000, arg1, 0);
    if (result != 0) OSResumeThread(arg0);
    return result != 0;
}
s32 nw4hbm::snd::detail::SoundThread::Shutdown() {
    register u8 *thread = (u8 *)this;
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
    if (OSSendMessage((u8 *)lbl_80412CC8 + 0x2338, (void *)2, 0) == 0)
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
                DummyWorkerLink *end = (DummyWorkerLink *)(p + 0x2388);
                DummyWorkerLink *link = (DummyWorkerLink *)end->next;
                while (link != end) {
                    DummyWorkerLink *current = link;
                    link = (DummyWorkerLink *)link->next;
                    if (current == 0)
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803264D0, 0x23D, lbl_803264AC);
                    ((DummyWorkerCallbackC *)current)->Call();
                }
            }
            UpdateAllChannel__Q46nw4hbm3snd6detail7ChannelFv();
            fn_800FEB9C();
            {
                unsigned long state = OSDisableInterrupts();
                Instance__15EmissionManagerFv();
                UpdateAllVoices__Q46nw4hbm3snd6detail9AxManagerFv();
                OSRestoreInterrupts(state);
            }
            *(u32 *)(p + 0x2390) = OSGetTick() - tick;
            {
                DummyWorkerLink *end = (DummyWorkerLink *)(p + 0x2388);
                DummyWorkerLink *link = (DummyWorkerLink *)end->next;
                while (link != end) {
                    DummyWorkerLink *current = link;
                    link = (DummyWorkerLink *)link->next;
                    if (current == 0)
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803264D0, 0x23D, lbl_803264AC);
                    ((DummyWorkerCallback10 *)current)->Call();
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
    u32 level = OSDisableInterrupts();
    *(s32*)arg0 = 0;
    *(s32*)((u8*)arg0 + 4) = 0;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    OSRestoreInterrupts(level);
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
    u32 value;
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
                    s32 index = bit + (i << 3);
                    s32 stride = pool->stride;
                    s32 oldUsed = pool->used;
                    void *result = (u8 *)pool->buffer + stride * index;
                    pool->used = oldUsed + 1;
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
    u32 state = OSDisableInterrupts();
    u32 idx = ((u8 *)ptr - (u8 *)*(void **)self) / *(u32 *)((u8 *)self + 8);
    u8 *block = (u8 *)self + (idx >> 3);
    *(u8 *)(block + 0x14) &= ~(1 << (idx & 7));
    *(s32 *)((u8 *)self + 0x10) -= 1;
    OSRestoreInterrupts(state);
}

extern "C" void NWC24Data_Init(void* arg0) {
    *(int*)arg0 = 0;
    *((int*)arg0 + 1) = 0;
}

extern "C" const char lbl_80326518[];
extern "C" const char lbl_80326688[];
extern "C" const char lbl_80326738[];
extern "C" char lbl_805598F8;
#pragma push
#pragma processor 750
#pragma scheduling on
extern "C" s32 fn_800FAB98(void *arg0, void *arg1) {
    s32 valid;
    void *ref;
    void *data;
    valid = *(s32 *)arg0;
    if (valid == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326518, 0x89, lbl_80326688);
    ref = *(void **)((u8 *)arg0 + 4);
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
#pragma pop
extern "C" const char lbl_803266B4[];
extern "C" const char lbl_803266E0[];
extern "C" const char lbl_8032670C[];
extern "C" char lbl_805598E0;
extern "C" char lbl_805598E8;
extern "C" char lbl_805598F0;
struct AdpcmParam {
    u16 data[24];
};
#pragma use_lmw_stmw off
struct fn_800FACC0_Data { u16 v[24]; };

extern "C" s32 fn_800FACC0(void *arg0, void *arg1, s32 arg2) {
    if (*(s32 *)arg0 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326518, 0xAD, lbl_80326688);

    u8 *head = (u8 *)*((void **)arg0 + 1);
    u8 *base = head + 8;
    if (head[9] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F8, 0x6F, lbl_80326738);

    u8 *codec = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(base[0], *(u32 *)(base + 4), base);
    if (*codec != 2)
        return 0;

    u8 *head2 = (u8 *)*((void **)arg0 + 1);
    u8 *base2 = head2 + 8;
    if (head2[0x19] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598E0, 0x6F, lbl_803266B4);

    u8 *table = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(head2[0x18], *(u32 *)(head2 + 0x1C), base2);
    if (arg2 >= *table)
        return 0;

    arg2 *= 8;
    head = (u8 *)*((void **)arg0 + 1);
    base = head + 8;
    if ((table + arg2)[5] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598E8, 0x6F, lbl_803266E0);

    u8 *entry = table + arg2;
    u8 *ref2 = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[4], *(u32 *)(entry + 8), base);

    head2 = (u8 *)*((void **)arg0 + 1);
    base2 = head2 + 8;
    if (ref2[1] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F0, 0x6F, lbl_8032670C);

    void *data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref2[0], *(u32 *)(ref2 + 4), base2);

    u16 *dst = (u16 *)arg1;
    const u16 *src = (const u16 *)data;
    u16 a, b;
    a = src[0]; b = src[1]; dst[0] = a; dst[1] = b;
    a = src[2]; b = src[3]; dst[2] = a; dst[3] = b;
    a = src[4]; b = src[5]; dst[4] = a; dst[5] = b;
    a = src[6]; b = src[7]; dst[6] = a; dst[7] = b;
    a = src[8]; b = src[9]; dst[8] = a; dst[9] = b;
    a = src[10]; b = src[11]; dst[10] = a; dst[11] = b;
    a = src[12]; b = src[13]; dst[12] = a; dst[13] = b;
    a = src[14]; b = src[15]; dst[14] = a; dst[15] = b;
    a = src[16]; b = src[17]; dst[17] = b; dst[16] = a;
    a = src[18]; b = src[19]; dst[19] = b; dst[18] = a;
    dst[20] = src[20];
    dst[21] = src[21];
    dst[22] = src[22];
    dst[23] = src[23];
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
    u8 buf[0x5F];
    s32 *temp_r3_5;
    s32 *temp_r3_6;
    s32 temp_r30;
    s32 temp_r6;
    u16 temp_r0;
    u16 temp_r0_2;
    u16 temp_r4;
    u16 temp_r4_2;
    u32 temp_r29;
    u32 var_r0;
    u32 var_r0_2;
    u8 *temp_r27;
    const char *file = lbl_80326518;

    (*(DummyStream **)arg0)->f15(0, 0, arg3);
    temp_r30 = (s32)(buf + 31) & 0xFFFFFFE0;
    if ((*(DummyStream **)arg0)->f3((void *)temp_r30, 0x40) != 0x40U) {
        return 0;
    }
    if (temp_r30 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x2B, file + 0x14);
    }
    if ((u32)(M2C_FIELD(temp_r30, s32 *, 0) + 0xADAD0000) != 0x544DU) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x31, file + 0x40);
    }
    if ((u32)(M2C_FIELD(temp_r30, s32 *, 0) + 0xADAD0000) != 0x544DU) {
        var_r0 = 0;
    } else {
        if ((u16)M2C_FIELD(temp_r30, u16 *, 6) < 0x100U) {
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x39, file + 0x8C);
        }
        temp_r0 = M2C_FIELD(temp_r30, u16 *, 6);
        if (temp_r0 < 0x100U) {
            var_r0 = 0;
        } else {
            if (temp_r0 > 0x100U) {
                Panic__Q26nw4hbm2dbFPCciPCce(file, 0x3F, file + 0x8C);
            }
            temp_r4 = M2C_FIELD(temp_r30, u16 *, 6);
            var_r0 = (u32)((0x100 | ~temp_r4) - ((u32)(0x100 - temp_r4) >> 1U)) >> 0x1FU;
        }
    }
    if ((s32)var_r0 == 0) {
        return 0;
    }
    if ((u32)M2C_FIELD(temp_r30, u32 *, 0x18) > arg2) {
        return 0;
    }

    temp_r6 = M2C_FIELD(temp_r30, s32 *, 0x10);
    temp_r29 = temp_r6 + M2C_FIELD(temp_r30, s32 *, 0x14);
    (*(DummyStream **)arg0)->f15(0, 0, temp_r6);
    if ((*(DummyStream **)arg0)->f3(arg1, temp_r29) != temp_r29) {
        return 0;
    }
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x5F, file + 0x14);
    }
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x2B, file + 0x14);
    }
    if ((u32)(M2C_FIELD(arg1, s32 *, 0) + 0xADAD0000) != 0x544DU) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x31, file + 0x40);
    }
    if ((u32)(M2C_FIELD(arg1, s32 *, 0) + 0xADAD0000) != 0x544DU) {
        var_r0_2 = 0;
    } else {
        if ((u16)M2C_FIELD(arg1, u16 *, 6) < 0x100U) {
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x39, file + 0x8C);
        }
        temp_r0_2 = M2C_FIELD(arg1, u16 *, 6);
        if (temp_r0_2 < 0x100U) {
            var_r0_2 = 0;
        } else {
            if (temp_r0_2 > 0x100U) {
                Panic__Q26nw4hbm2dbFPCciPCce(file, 0x3F, file + 0x8C);
            }
            temp_r4_2 = M2C_FIELD(arg1, u16 *, 6);
            var_r0_2 = (u32)((0x100 | ~temp_r4_2) - ((u32)(0x100 - temp_r4_2) >> 1U)) >> 0x1FU;
        }
    }
    if ((s32)var_r0_2 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = arg1;
    temp_r3_5 = (s32 *)((u8 *)arg1 + M2C_FIELD(arg1, s32 *, 0x10));
    M2C_FIELD(arg0, s32 **, 8) = temp_r3_5;
    if ((u32)(M2C_FIELD(temp_r3_5, s32 *, 0) + 0xB7BB0000) != 0x4144U) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x68, file + 0xE4);
    }
    temp_r3_6 = M2C_FIELD(arg0, s32 **, 8);
    temp_r27 = (u8 *)temp_r3_6 + 8;
    if ((s32)M2C_FIELD(temp_r3_6, u8 *, 9) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F8, 0x6F, lbl_80326738);
    }
    if ((M2C_FIELD(GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(M2C_FIELD(temp_r27, u8 *, 0), M2C_FIELD(temp_r27, u32 *, 4), temp_r27), u32 *, 0x18) & 0x1F) == 0) {
        return 0;
    }
    Panic__Q26nw4hbm2dbFPCciPCce(file, 0x6C, file + 0x13C);
    return 1;
}

extern "C" void fn_8002F53C(void *, void *, void *, int, int);
#pragma push
#pragma use_lmw_stmw off
extern "C" void * __ct__Q46nw4hbm3snd6detail10StrmPlayerFv(void *arg0) {
    u8 *p = (u8 *)arg0;
    volatile u32 *vp = (volatile u32 *)p;
    u32 zero = 0;
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
    u32 offset = 0;
    u32 i = 0;
    do {
        u8 *node = p + 0xac + offset;
        *(void **)(node + 4) = arg0;
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
        void *it = p + 0x98;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(p + 0x94, (void **)&it, node + 0x14);
        ++i;
        offset += 0x1c;
    } while (i < 0x20);
    return arg0;
}
#pragma pop
extern "C" void fn_800FB358(void *arg0) {
    extern char lbl_80326AC0[];
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(void **)((u8 *)arg0 + 0) = lbl_80326AC0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
}

extern "C" s32 fn_800FB374(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
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
    goto done;
doForce:
    ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
    goto done;
done:
    *((u8 *)self + 0x48) = 1;
    return 1;
}
#pragma pop
s32 nw4hbm::snd::detail::StrmPlayer::Start() {
    u8 *self = (u8 *)this;
    register u32 outerIrq = OSDisableInterrupts();
    if (self[0x4A] == 0) {
        OSRestoreInterrupts(outerIrq);
        return 0;
    }
    if (self[0x49] == 0) {
        if (*(s32 *)(self + 0x438) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x97, lbl_803267AC);
        }
        fn_800E519C(*(void **)(self + 0x438));
        register u32 innerIrq = OSDisableInterrupts();
        u8 paused = 0;
        if (self[0x4B] != 0) {
            paused = 1;
        }
        if (self[0x4E] != 0) {
            paused = 1;
        }
        if (paused != self[0x4D]) {
            if (*(s32 *)(self + 0x438) == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0xD1, lbl_803267AC);
            }
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(self + 0x438), paused);
            self[0x4D] = paused;
        }
        OSRestoreInterrupts(innerIrq);
        register u32 iteratorValue = (u32)&lbl_8041506C[4];
        if (this == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C4C, 0x233, lbl_80326C28);
        }
        void *iterator = (void *)iteratorValue;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
            lbl_8041506C, &iterator, self + 8);
        self[0x49] = 1;
    }
    OSRestoreInterrupts(outerIrq);
    return 1;
}
#pragma pop
extern "C" void ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" void fn_800FB620(void *self) {
    if (*(u8 *)((u8 *)self + 0x48) != 0) {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
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
    const char *file = lbl_80326768;
    u8 *self = (u8 *)arg0;
    u8 *p;
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
            
            if (*(void **)(self + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x19E, file + 0x44);
            irq = OSDisableInterrupts();
            p = self;
            for (i = 0; i < *(s32 *)(self + 0x4A0); ++i) {
                SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), 0);
                SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(self + 0x438), i, *(void **)(p + 0x4A8), loopEnd);
                p += 0x38;
            }
            SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(self + 0x438), 1);
            OSRestoreInterrupts(irq);
        } else Panic__Q26nw4hbm2dbFPCciPCce(file, 0x1C6, file + 0x94);
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
        
        if (*(void **)(self + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x19E, file + 0x44);
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
        if (self[0x51] == 0) Warning__Q26nw4hbm2dbFPCciPCce(file, 0x1DC, file + 0xB4);
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
        self[0x51] = self[0x50] = 0;
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
            
            if (*(void **)(self + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x19E, file + 0x44);
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
extern "C" void UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv(void) {
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
        UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(&((u8*)p)[-0x08]);
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
extern "C" void fn_800FC5B8(void *arg0, f32 value) {
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)arg0 + 0x45C) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 fn_800FC5F8(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x45C); }

extern "C" void fn_800FC600(void *arg0, f32 value) { u32 token = OSDisableInterrupts(); *(f32 *)((u8 *)arg0 + 0x460) = value; OSRestoreInterrupts(token); }

extern "C" f32 fn_800FC640(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x460); }

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

extern "C" void fn_800FC76C(void *self, s32 value) {
    u32 token = OSDisableInterrupts();
    *(s32 *)((u8 *)self + 0x458) = value;
    OSRestoreInterrupts(token);
}

extern "C" s32 fn_800FC7AC(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x458);
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

#pragma dont_inline on
#pragma use_lmw_stmw off
void FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(void *self) {
    register BOOL irqState = OSDisableInterrupts();
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
#pragma scheduling on
extern "C" void ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(void* self) {
    class Manager {
    public:
        virtual void m0(); virtual void m1(); virtual void m2();
        virtual void m3(void*, u32); virtual void m4(); virtual void m5();
    };
    register u32 irq = OSDisableInterrupts();
    s32 voice = *(s32*)((u8*)self + 0x438);
    if (voice != 0) Stop__Q46nw4hbm3snd6detail7AxVoiceFv((void*)voice);
    if (*((u8*)self + 0x49) != 0) {
        if (self == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C4C, 0x233, lbl_80326C28);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(lbl_8041506C, (u8*)self + 8);
        *((u8*)self + 0x49) = 0;
        *((u8*)self + 0x4A) = 0;
    }
    OSRestoreInterrupts(irq);
    ((Manager*)*(void**)((u8*)self + 0x430))->m3(self, *(u32*)((u8*)self + 0x434));
    irq = OSDisableInterrupts();
    if (*(u32*)((u8*)self + 0xA0) == 0) goto done;
    s32 iterator;
    s32 eraseValue;
    void* node = (u8*)self + 0x98;
    goto check;
loop:
    if (*(u32*)((u8*)self + 0xA0) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C1C, 0x1F1, lbl_80326BF8);
    iterator = *(s32*)((u8*)self + 0xA4);
    if (iterator == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326BBC, 0x23D, lbl_80326B98);
    s32 count = iterator - 0x14;
    if (count == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326BEC, 0x193, lbl_80326BC8);
    eraseValue = *(s32*)((u8*)self + 0xA4);
    Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator((u8*)self + 0xA0, &eraseValue);
    if (count == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8*)self + 0x94, (void**)&node, (void*)(count + 0x14));
check:
    if (*(u32*)((u8*)self + 0xA0) != 0) goto loop;
done:
    OSRestoreInterrupts(irq);
    FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
    *((u8*)self + 0x48) = 0;
}

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
    const char *base = lbl_80326768;
    if (player == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x504, base + 0x238);
    if (*(void **)((char *)player + 0x438) != voice)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x506, base + 0x268);
    if (status < 2) {
        if (status >= 0)
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
    Panic__Q26nw4hbm2dbFPCciPCce(base, 0x515, base + 0x298, status);

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
    u32 successSave;
    void *node;
    void *list2;
    void *iterator;
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

extern "C" void SetAdpcmLoopContext__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFiPUs(void* self, int n, u16* p) {
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
    value = *p;
    ++p;
    u16* context = (u16*)((u8*)stream + 0x518 + offset);
    offset += 2;
    *context = value;
loop_check:
    if (index < n && index < 2) goto loop_body;
    stream = *(void**)((u8*)self + 4);
    *((u8*)stream + 0x51) = 1;
}

extern "C" int fn_800FD810(void* arg0, int arg1) {
    void* temp_r6 = *(void**)((char*)arg0 + 4);
    if (arg1 >= *(int*)((char*)temp_r6 + 0x4A0)) {
        return 0;
    }
    return *(int*)((char*)temp_r6 + arg1 * 0x38 + 0x4A8) +
           *(int*)((char*)temp_r6 + 0x60) * *(int*)((char*)arg0 + 0x10);
}

extern "C" float fn_800FD848(void *arg0) { return *(float *)((char *)arg0 + 0x454); }

extern "C" float fn_800FD850(void *arg0) { return *(float *)((char *)arg0 + 0x44C); }

extern "C" float fn_800FD858(void *arg0) { return *(float *)((char *)arg0 + 0x448); }

extern "C" float fn_800FD860(void *arg0) { return *(float *)((char *)arg0 + 0x444); }

extern "C" f32 fn_800FD868(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 0x440);
}

extern "C" f32 fn_800FD870(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 0x450);
}

extern "C" f32 fn_800FD878(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 0x43C);
}

extern "C" void fn_800FD880(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x454) = arg1;
}

extern "C" void fn_800FD888(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x44C) = arg1;
}

extern "C" void fn_800FD890(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x448) = arg1;
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

extern "C" int fn_800FD8B8(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x4B) != 0;
}

extern "C" int fn_800FD8CC(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x49) != 0;
}

extern "C" int fn_800FD8E0(void* arg0) {
    return *((unsigned char*)arg0 + 0x4A) != 0;
}

extern "C" int fn_800FD8F4(void* arg0) {
    return *((unsigned char*)arg0 + 0x48) != 0;
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
