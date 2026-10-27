extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void *, unsigned char);
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
namespace nw4hbm { namespace snd { class SoundArchivePlayer { public: u32 detail_ConvertLabelStringToSoundId(const char *); }; } }
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
#pragma cplusplus on
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
#pragma cplusplus reset
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))



extern "C" s32 fn_80128668(void);
extern "C" const char lbl_80324E88[];
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
extern "C" void* lbl_80325C40;
extern "C" void Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(void*, unsigned long, void*);
extern "C" void DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(void*, unsigned long, void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" s32 fn_800E9B88(void *);
extern "C" s32 fn_800E9B9C(void *);
extern "C" const char lbl_80325C00[];
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
  extern "C" u8 lbl_803263B8[];
  extern "C" u8 lbl_80326400[];
  extern "C" u8 lbl_8055DE60;
  extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
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
    #pragma pop
    extern u8 lbl_8055DE68;
    extern "C" void* __dt__10TitleSceneFv(void*, s32);
    extern "C" void __register_global_object(void*, void*, void*, void*);
    extern "C" void OSSendMessage(void*, void*, u32);
extern "C" void OSInitMutex(void*);
extern "C" const char lbl_80326768[];
extern "C" const char lbl_8032677C[];
extern "C" void InitParam__Q46nw4hbm3snd6detail10StrmPlayerFi(void *, s32);
extern "C" void NotifyStrmHeaderAsyncEndCallback__Q46nw4hbm3snd6detail10StrmPlayerFbPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeaderPv();
extern "C" const char lbl_80324B24[];
extern "C" const char lbl_80324B50[];
extern "C" const char lbl_80559858[];
extern "C" const char lbl_80559860[];
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
extern "C" void InitParam__Q46nw4hbm3snd6detail8SeqTrackFv(void *arg0) {
    u8 *p = (u8 *)arg0;
    f32 zero = lbl_8056107C;
    f32 one = lbl_80561078;
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
    p[0x88] = 0x40;
    *(u32 *)(p + 0x58) = 0;
    p[0x5C] = 0;
    p[0x5D] = 0;
    p[0x5E] = 0;
    p[0x5F] = 0;
    p[0x80] = 0x7F;
    p[0x81] = 0x7F;
    p[0x84] = 0;
    p[0x85] = 0;
    p[0x86] = 0;
    p[0x82] = 0;
    p[0x8B] = 0xFF;
    p[0x8C] = 0xFF;
    p[0x8D] = 0xFF;
    p[0x8E] = 0xFF;
    p[0x8F] = 0x7F;
    p[0x90] = 0;
    p[0x91] = 0;
    p[0x92] = 0;
    p[0x93] = 0x40;
    p[0x83] = 2;
    p[0x89] = 0x3C;
    p[0x8A] = 0;
    *(f32 *)(p + 0x7C) = zero;
    p[0x87] = 0;
    fn_800EC890(p + 0x68, 2, 0xFF, 0x7F, 0x40, one);
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

extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFb(void *arg0, u8 arg1) {
    u32 token = OSDisableInterrupts();
    u8 *track = (u8 *)arg0;
    void *channel = *(void **)(track + 0xB8);
    while (channel != 0) {
        u8 *p = (u8 *)channel;
        if (p[0x3A] != 0 && arg1 != (p[0x39] != 0)) {
            p[0x39] = arg1;
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(p + 0xE0), arg1);
        }
        channel = *(void **)(p + 0xE4);
    }
    OSRestoreInterrupts(token);
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

extern "C" void ChannelCallbackFunc__Q46nw4hbm3snd6detail8SeqTrackFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl(void *channel, s32 status, void *track, u32 arg3) {
    struct Callback { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44(void *); };
    if (channel == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x209, lbl_80324390 + 0xA0);
    if (track == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x20A, lbl_80324390 + 0xD0);
    if (status >= 0 && status < 3 && status != 1)
        fn_800EAD00(channel);
    void *callback = *(void **)((u8 *)track + 0xB4);
    if (callback != 0)
        ((Callback *)callback)->f44(channel);
    u32 token = OSDisableInterrupts();
    void *head = *(void **)((u8 *)track + 0xB8);
    if (head == channel) {
        *(void **)((u8 *)track + 0xB8) = *(void **)((u8 *)channel + 0xE4);
        OSRestoreInterrupts(token);
        return;
    }
    if (head == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x220, lbl_80324390 + 0xF8);
    void *node = head;
    for (;;) {
        void *next = *(void **)((u8 *)node + 0xE4);
        if (next == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x229, lbl_80324390 + 0x124);
            OSRestoreInterrupts(token);
            return;
        }
        if (next == channel) {
            *(void **)((u8 *)node + 0xE4) = *(void **)((u8 *)channel + 0xE4);
            OSRestoreInterrupts(token);
            return;
        }
        node = next;
    }
}

extern "C" void Stop__Q46nw4hbm3snd6detail7ChannelFv(void *);
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(void *, int);
extern "C" void SetMute__Q46nw4hbm3snd6detail8SeqTrackFQ36nw4hbm3snd7SeqMute(void *arg0, int arg1) {
    u32 token = OSDisableInterrupts();
    switch (arg1) {
    case 0:
        *(u8 *)((u8 *)arg0 + 0x5C) = 0;
        break;
    case 3: {
        u32 inner = OSDisableInterrupts();
        void *channel = *(void **)((u8 *)arg0 + 0xB8);
        while (channel) {
            fn_800EAD00(channel);
            Stop__Q46nw4hbm3snd6detail7ChannelFv(channel);
            channel = *(void **)((u8 *)channel + 0xE4);
        }
        *(void **)((u8 *)arg0 + 0xB8) = 0;
        OSRestoreInterrupts(inner);
        *(u8 *)((u8 *)arg0 + 0x5C) = 1;
        break;
    }
    case 2: {
        ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(arg0, -1);
        void *channel;
        u32 inner;
        inner = OSDisableInterrupts();
        channel = *(void **)((u8 *)arg0 + 0xB8);
        while (channel) {
            fn_800EAD00(channel);
            channel = *(void **)((u8 *)channel + 0xE4);
        }
        *(void **)((u8 *)arg0 + 0xB8) = 0;
        OSRestoreInterrupts(inner);
        *(u8 *)((u8 *)arg0 + 0x5C) = 1;
        break;
    }
    case 1:
        *(u8 *)((u8 *)arg0 + 0x5C) = 1;
        break;
    }
    OSRestoreInterrupts(token);
}

extern "C" const char lbl_80324690[];
extern "C" const char lbl_803246D4[];
extern "C" void SetSilence__Q46nw4hbm3snd6detail8SeqTrackFbi(void *self, bool silence, int ticks) {
    *(u8 *)((u8 *)self + 0x5d) = silence;
    u32 state = OSDisableInterrupts();
    int duration = (ticks + 2) / 3;
    void *channel = *(void **)((u8 *)self + 0xb8);
    while (channel) {
        if (duration < 0 || duration > 0xffff)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803246D4, 0x7c, lbl_80324690, duration, 0, 0xffff);
        u16 total = *(u16 *)((u8 *)channel + 0xc6);
        u16 elapsed = *(u16 *)((u8 *)channel + 0xc8);
        u8 from;
        if (elapsed >= total) from = *(u8 *)((u8 *)channel + 0xc5);
        else {
            u8 start = *(u8 *)((u8 *)channel + 0xc4);
            u8 end = *(u8 *)((u8 *)channel + 0xc5);
            from = start + (elapsed * (end - start)) / total;
        }
        *(u8 *)((u8 *)channel + 0xc4) = from;
        *(u8 *)((u8 *)channel + 0xc5) = silence ? 0 : 0xff;
        *(u16 *)((u8 *)channel + 0xc6) = duration;
        *(u16 *)((u8 *)channel + 0xc8) = 0;
        channel = *(void **)((u8 *)channel + 0xe4);
    }
    OSRestoreInterrupts(state);
}

extern "C" void fn_800F1E50(void *arg0, f32 value) {
    u32 token = OSDisableInterrupts();
    *(f32 *)((char *)arg0 + 8) = value;
    OSRestoreInterrupts(token);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800F1E90(void* arg0, f32 farg0) {
    if (!(farg0 >= *(volatile f32*)&lbl_8056107C)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x25B, lbl_803244D4);
    }
    OSDisableInterrupts();
    *(f32*)((char*)arg0 + 0xC) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
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

void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F20C4(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 3) {
        if (0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x295, lbl_803244FC, bus, 0, 3);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x24 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F2160(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 4) {
        if (0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x2A3, lbl_80324534, bus, 0, 4);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x30 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F21FC(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 4) {
        if (0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x2B0, lbl_80324534, bus, 0, 4);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x40 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" s32 GetVariablePtr__Q46nw4hbm3snd6detail8SeqTrackFi(void *self, s32 index) {
    s32 valid = 0;
    if (index >= 0 && index <= 0x10) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324390, 0x2EB, (const char *)lbl_803245B8, index, 0, 0x10);
    if (index < 0x10) return (s32)((u8 *)self + 0x94 + index * 2);
    return 0;
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
extern "C" s32 lbl_802F4DB8[];
extern "C" void fn_800F2330(void *a, s32 key, s32 vel, s32 arg3, s32 reuse) {
 u8 *p=(u8*)a; void *c=0;
 if(key<0||key>127) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390,0x30a,lbl_80324390+0x268,key,0,127);
 if(vel<0||vel>127) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390,0x30b,lbl_80324390+0x2a0,vel,0,127);
 if(reuse && (c=*(void**)(p+0xb8))) {
  *(u32*)((u8*)c+0xcc)=(u8)key;
  f32 x=((f32)vel)/lbl_80561080; *(f32*)((u8*)c+0xb4)=x*x;
 }
 if(!c) {
  s32 args[9]; int i; for(i=0;i<9;i++) args[i]=lbl_802F4DB8[i];
  args[0]=*(s32*)(p+0x64); args[1]=key; args[2]=vel; args[3]=reuse?-1:arg3;
  args[4]=(s8)p[0x85]; args[5]=*(u8*)(*(u8**)(p+0xb4)+0x91)+p[0x88];
  args[6]=*(s32*)(*(u8**)(p+0xb4)+0x8c); args[8]=(s32)p;
  c=fn_800F0728(*(void**)(p+0xb4),*(s32*)(p+0x60),args); if(!c)return;
  u32 t=OSDisableInterrupts(); *(void**)((u8*)c+0xe4)=*(void**)(p+0xb8); *(void**)(p+0xb8)=c; OSRestoreInterrupts(t);
 }
 if(p[0x8b]!=255) SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8b]);
 if(p[0x8c]!=255) SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8c]);
 if(p[0x8d]!=255) SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8d]);
 if(p[0x8e]!=255) SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8e]);
 f32 pitch=*(f32*)(p+0x7c); if(p[0x5f]) pitch+=(f32)((s32)p[0x89]-key);
 if(!p[0x8a]) { if(!arg3) Warning__Q26nw4hbm2dbFPCciPCce(lbl_80324390,0x358,lbl_80324390+0x2e4); fn_800EA8A0(c,arg3,0,pitch); }
 else { s32 n=p[0x8a]*p[0x8a]; f32 scale=pitch>lbl_8056107C?pitch:-pitch; fn_800EA8A0(c,(s32)((f32)n*scale)/32*5,1,pitch); }
 p[0x89]=(u8)key;
 u16 total=*(u16*)((u8*)c+0xc6), cur=*(u16*)((u8*)c+0xc8); u32 enabled=p[0x5d]!=0; u8 val;
 if(cur>=total) val=*((u8*)c+0xc5); else {u8 st=*((u8*)c+0xc4); val=st+(cur*(*((u8*)c+0xc5)-st))/total;}
 *((u8*)c+0xc4)=val; *((u8*)c+0xc5)=enabled?0:255; *(u16*)((u8*)c+0xc6)=0; *(u16*)((u8*)c+0xc8)=0;
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

extern "C" s32 fn_800F273C(void *arg0) {
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

extern "C" s32 ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo(s32);
extern "C" s32 fn_800F280C(void *arg0) {
    return ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(s32);
extern "C" s32 fn_800F2814(void *arg0) {
    return ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(s32);
extern "C" s32 fn_800F281C(void *arg0) {
    return ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(s32);
extern "C" s32 fn_800F2824(void *arg0) {
    return ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(*(s32*)((u8*)arg0 + 4));
}

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

extern "C" s32 ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(void *, u32, void *);
extern "C" unsigned long strlen(const char *);
extern "C" char *strncpy(char *, const char *, unsigned long);
extern "C" void fn_80028E2C(char *, const char *, s32);
extern "C" const char lbl_80324828[];
extern "C" s32 detail_OpenGroupWaveDataStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi_800F2BEC(void *self, u32 group, void *arg2, s32 arg3, void *arg4, s32 arg5, s32 arg6) {
    struct GroupInfo { u32 unk0, unk4; const char *path; u32 unkC, unk10, unk14, unk18, unk1C; } info;
    struct Archive { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual s32 f6(u32, void *, s32, const char *, s32, s32); virtual s32 f7(u32, void *, s32, s32, s32); };
    Archive *archive = (Archive *)self;
    if (!ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(*(void **)((u8 *)self + 4), group, &info))
        return 0;
    const char *path = info.path;
    if (path != 0) {
        if (*path != '/') {
            unsigned long pathLen = strlen(path);
            const char *prefix = (const char *)self + 8;
            unsigned long prefixLen = strlen(prefix);
            if (pathLen + prefixLen >= 0x100) {
                Warning__Q26nw4hbm2dbFPCciPCce(lbl_803247E0, 0x155, lbl_80324828, prefix, path);
                return 0;
            }
            char buf[0x100];
            strncpy(buf, prefix, prefixLen + 1);
            fn_80028E2C(buf, path, pathLen + 1);
            path = buf;
        }
        return archive->f6(group, arg2, arg3, path, info.unk18, info.unk1C);
    }
    return archive->f7(group, arg2, arg3, info.unk18, info.unk1C);
}

extern "C" void fn_800F2D28(void *arg0) {
    *(s32*)((u8*)arg0 + 0x28) = 0;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *(s32*)((u8*)arg0 + 0x30) = 0;
    *(s32*)((u8*)arg0 + 0x34) = 0;
    *(s32*)((u8*)arg0 + 0x38) = 0;
    *(s32*)((u8*)arg0 + 0x3C) = 0;
    *(s32*)((u8*)arg0 + 0x40) = 0;
}

extern "C" const char lbl_80324868[];
void fn_800F2EAC(void *self, void *arg) {
    const char *base = lbl_80324868;
    unsigned char *bytes = (unsigned char *)arg;
    unsigned char *table;
    int offset;
    if (arg == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x60, base + 0x104);
    if (*(unsigned int *)bytes != 0x53594D42) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x63, base + 0x138);
    table = bytes + 8;
    *(unsigned char **)((unsigned char *)self + 0x2C) = table;
    offset = *(int *)(bytes + 8);
    *(unsigned char **)((unsigned char *)self + 0x30) = offset ? table + offset : 0;
    offset = *(int *)(table + 4);
    *(unsigned char **)((unsigned char *)self + 0x34) = offset ? table + offset : 0;
    offset = *(int *)(table + 8);
    *(unsigned char **)((unsigned char *)self + 0x38) = offset ? table + offset : 0;
    offset = *(int *)(table + 0xC);
    *(unsigned char **)((unsigned char *)self + 0x3C) = offset ? table + offset : 0;
    offset = *(int *)(table + 0x10);
    *(unsigned char **)((unsigned char *)self + 0x40) = offset ? table + offset : 0;
}

extern "C" void SetInfoChunk__Q46nw4hbm3snd6detail22SoundArchiveFileReaderFPCvUl(void *self, const void *chunk, u32 size) {
    extern const char lbl_80324868[];
    const char *base = lbl_80324868;
    const u32 *data = (const u32 *)chunk;
    if (data == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(base + 0), 0x78, base + 0x198);
    if (data[0] != 0x494E464FU)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(base + 0), 0x7B, base + 0x1C4);
    *(const void **)((char *)self + 0x28) = (const u8 *)data + 8;
}

extern "C" s32 GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(void *arg0, u32 arg1) {
    u8 *reader = (u8 *)arg0;
    register u8 *ref = *(u8 **)(reader + 0x28);
    u8 type;
    u8 *info;
    u32 offset;
    extern const char lbl_80324DE4[];
    extern const char lbl_80324E10[];
    extern char lbl_805598C8;
    extern char lbl_805598D0;
    if (ref[1] != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    info = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0], *(u32 *)(ref + 4), ref);
    if (!info) return 0;
    if (arg1 >= *(u32 *)info) return 0;
    if (*(u16 *)(reader + 6) >= 0x101) {
        offset = arg1 * 8;
        ref = *(u8 **)(reader + 0x28);
        if (info[offset + 5] != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
        type = info[offset + 5];
        info = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(info[offset + 4], *(u32 *)(info + offset + 8), ref);
        if (!info) return 0;
        type = info[0x16];
    } else { offset = arg1 * 8; type = info[offset + 5]; }
    switch (type) { case 1: return 1; case 2: return 2; case 3: return 3; default: return 0; }
}

extern "C" const char lbl_80324DE4[];
extern "C" const char lbl_80324E10[];
extern "C" char lbl_805598C8;
extern "C" char lbl_805598D0;
extern "C" BOOL ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(void *self, u32 index, void *info) {
    u8 *ref = *(u8 **)((u8 *)self + 0x28);
    if (ref[1] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    void *base = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0], *(u32 *)(ref + 4), ref);
    void *entry = 0;
    if (base != 0 && index < *(u32 *)base) {
        if (*(u16 *)((u8 *)self + 6) >= 0x101) {
            u8 *item = (u8 *)base + index * 8;
            if (item[5] != 0)
                Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
            entry = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(item[4], *(u32 *)(item + 8), ref);
        } else {
            entry = (u8 *)base + index * 8 + *(u32 *)((u8 *)base + index * 8 + 8);
        }
    }
    if (entry == 0)
        return 0;
    *(u32 *)info = *(u32 *)((u8 *)entry + 4);
    *(u32 *)((u8 *)info + 4) = *(u32 *)((u8 *)entry + 8);
    *(u32 *)((u8 *)info + 8) = *((u8 *)entry + 0x15);
    *(u32 *)((u8 *)info + 0xC) = *((u8 *)entry + 0x14);
    return 1;
}

extern "C" s32 ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(void *self, u32 index, void *info) {
    extern const char lbl_80324BD4[];
    extern char lbl_80559878;
    u64 result = impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(self, index);
    u32 type = (u32)(result >> 32);
    u32 offset = (u32)result;
    void *base = *(void **)((char *)self + 0x28);
    if ((u8)type != 1)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559878, 0x70, lbl_80324BD4);
    void *data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(type, offset, base);
    if (!data)
        return 0;
    *(u32 *)((char *)info + 0) = *(u32 *)((char *)data + 0);
    *(u32 *)((char *)info + 4) = *(u32 *)((char *)data + 4);
    *(u32 *)((char *)info + 12) = *(u8 *)((char *)data + 12);
    *(u32 *)((char *)info + 8) = *(u32 *)((char *)data + 8);
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
    s32 entry = (s32)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(bytes[0], *(u32 *)(bytes + 4), base);
    if (entry == 0)
        return 0;
    return 1;
}

extern "C" s32 ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(void *self, u32 index, void *info) {
    extern const char lbl_80324B7C[];
    extern char lbl_80559868;
    u64 result = impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(self, index);
    u32 type = (u32)(result >> 32);
    u32 offset = (u32)result;
    void *base = *(void **)((char *)self + 0x28);
    if ((u8)type != 3)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559868, 0x72, lbl_80324B7C);
    void *data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(type, offset, base);
    if (!data)
        return 0;
    *(u32 *)((char *)info + 0) = *(u32 *)((char *)data + 0);
    *(u32 *)((char *)info + 4) = *(u8 *)((char *)data + 8);
    return 1;
}

extern "C" s32 ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(void *self, u32 index, void *out) {
    register void *reader = self;
    register void *bankInfo = *(void **)((char *)reader + 0x28);
    register void *table;
    if (*((u8 *)bankInfo + 9) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559858, 0x6F, lbl_80324B24);
    table = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)bankInfo + 8), *(u32 *)((char *)bankInfo + 0xC), bankInfo);
    if (table == 0)
        return 0;
    if (index >= *(u32 *)table)
        return 0;
    index <<= 3;
    bankInfo = *(void **)((char *)reader + 0x28);
    u8 *entry = (u8 *)table + index;
    if (entry[5] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559860, 0x6F, lbl_80324B50);
    void *bank = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[4], *(u32 *)(entry + 8), bankInfo);
    if (bank == 0)
        return 0;
    *(u32 *)out = *(u32 *)((char *)bank + 4);
    return 1;
}

extern "C" const char lbl_80324ACC[];
extern "C" const char lbl_80324D34[];
extern "C" const char lbl_80324D60[];
extern "C" char lbl_80559848;
extern "C" char lbl_805598B8;
extern "C" char lbl_805598C0;
extern "C" char lbl_80559848, lbl_805598B8, lbl_805598C0;
extern "C" s32 ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(void *self, u32 arg1, u32 arg2, void *out) {
    register void *r30 = self;
    register u32 r27 = arg1;
    register u32 r26 = arg2;
    register void *r31 = out;
    register u8 *r28;
    register u8 *r29;
    u32 *p;
    u32 n;

    r28 = *(u8 **)((u8 *)r30 + 0x28);
    if (r28[0x21]) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A0, 0x6F, lbl_80324CB0);
    p = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(r28[0x20], *(u32 *)(r28 + 0x24), r28);
    if (p == 0) { r29 = 0; goto second; }
    n = *p;
    if (r27 >= n) { r29 = 0; goto second; }
    r27 <<= 3;
    r28 = *(u8 **)((u8 *)r30 + 0x28);
    if (*((u8 *)p + r27 + 5)) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559848, 0x6F, lbl_80324ACC);
    r29 = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)p + r27 + 4), *(u32 *)((u8 *)p + r27 + 8), r28);
second:
    if (r29 == 0) return 0;
    if (r29[0x21]) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C0, 0x6F, lbl_80324D60);
    r28 = *(u8 **)((u8 *)r30 + 0x28);
    p = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(r29[0x20], *(u32 *)(r29 + 0x24), r28);
    if (p == 0) return 0;
    if (r26 >= *p) return 0;
    r27 = r26 << 3;
    r28 = *(u8 **)((u8 *)r30 + 0x28);
    if (*((u8 *)p + r27 + 5)) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598B8, 0x6F, lbl_80324D34);
    p = (u32 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)p + r27 + 4), *(u32 *)((u8 *)p + r27 + 8), r28);
    if (p == 0) return 0;
    ((u32 *)r31)[0] = p[0]; ((u32 *)r31)[1] = p[1]; ((u32 *)r31)[2] = p[2]; ((u32 *)r31)[3] = p[3]; ((u32 *)r31)[4] = p[4];
    return 1;
}

extern "C" s32 ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(void *arg0, void *arg1) {
    extern const char lbl_80324D08[];
    extern char lbl_805598B0;
    register void *ref = *(void **)((char *)arg0 + 0x28);
    register void *out = arg1;
    void *data;
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

extern "C" const char lbl_80559898[];
extern "C" const char lbl_80559888[];
extern "C" const char lbl_80559890[];
extern "C" const char lbl_80559810[];
extern "C" const char lbl_80324C84[];
extern "C" const char lbl_80324C2C[];
extern "C" const char lbl_80324C58[];
extern "C" const char lbl_80321F50[];
extern "C" s32 ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(void *arg0, u32 arg1, void *arg2) {
    u8 *archive = *(u8 **)((u8 *)arg0 + 0x28);
    u8 *files;
    u8 *info;
    u8 *detail;
    u8 *player;
    void *base;
    if (archive[0x19] != 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559898, 0x6F, lbl_80324C84);
    files = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(archive[0x18], *(u32 *)(archive + 0x1C), archive);
    if (files == 0) return 0;
    if (arg1 >= *(u32 *)files) return 0;
    info = files + arg1 * 8;
    base = *(void **)((u8 *)arg0 + 0x28);
    if (info[5] != 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559888, 0x6F, lbl_80324C2C);
    detail = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(info[4], *(u32 *)(info + 8), base);
    if (detail == 0) return 0;
    base = *(void **)((u8 *)arg0 + 0x28);
    if (detail[0x15] != 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559890, 0x6F, lbl_80324C58);
    player = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(detail[0x14], *(u32 *)(detail + 0x18), base);
    if (player == 0) return 0;
    *(u32 *)arg2 = *(u32 *)detail;
    *(u32 *)((u8 *)arg2 + 4) = *(u32 *)(detail + 4);
    base = *(void **)((u8 *)arg0 + 0x28);
    if (detail[0xD] != 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559810, 0x6F, lbl_80321F50);
    *(void **)((u8 *)arg2 + 8) = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(detail[0xC], *(u32 *)(detail + 0x10), base);
    *(u32 *)((u8 *)arg2 + 0xC) = *(u32 *)player;
    return 1;
}

extern "C" void *GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(s32, u32, void *);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern "C" u64 lbl_8055DE50;
extern "C" u64 lbl_8055DE54;
extern "C" u64 impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(void *self, u32 index) {
    u8 *ref = *(u8 **)((u8 *)self + 0x28);
    if (ref[1] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    u8 *base = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0], *(u32 *)(ref + 4), ref);
    if (base == 0)
        return lbl_8055DE50;
    if (index >= *(u32 *)base)
        return lbl_8055DE50;
    if (*(u16 *)((u8 *)self + 6) >= 0x101) {
        u8 *item = base + index * 8;
        if (item[5] != 0)
            Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
        u8 *data = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(item[4], *(u32 *)(item + 8), ref);
        if (data == 0)
            return lbl_8055DE50;
        return *(u64 *)(data + 0x18);
    }
    u8 *item = base + index * 8;
    struct Result { u8 type; u8 ext; u16 pad; u32 offset; } result;
    result.type = item[4];
    result.ext = item[5];
    result.offset = *(u32 *)(item + 8) + 0x1C;
    return *(u64 *)&result;
}

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

extern "C" void OSLockMutex(void *);
extern "C" void OSUnlockMutex(void *);
extern "C" void *detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(void *, unsigned long, void *, int);
extern "C" long ReadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPvll(void *self, unsigned long fileId, void *buffer, long length, long offset) {
    void *stream;
    long result;
    OSLockMutex(self);
    stream = detail_OpenFileStream__Q36nw4hbm3snd12SoundArchiveCFUlPvi(*(void **)((char *)self + 0x18), fileId, (char *)self + 0x1c, 0x200);
    if (stream == 0) {
        ((void (*)(void *))(*(void ***)stream)[0x10 / 4])(stream);
        OSUnlockMutex(self);
        return -1;
    }
    if (((int (*)(void *))(*(void ***)stream)[0x50 / 4])(stream) == 0 ||
        ((int (*)(void *))(*(void ***)stream)[0x2c / 4])(stream) == 0) {
        if (stream != 0)
            ((void (*)(void *))(*(void ***)stream)[0x10 / 4])(stream);
        OSUnlockMutex(self);
        return -1;
    }
    ((void (*)(void *, long, int))(*(void ***)stream)[0x44 / 4])(stream, offset, 0);
    *(void **)((char *)self + 0x21c) = stream;
    result = ((int (*)(void *, void *, unsigned long))(*(void ***)stream)[0x14 / 4])(stream, buffer, ((length + 0x1f) & ~0x1f));
    *(void **)((char *)self + 0x21c) = 0;
    if (result == 0) {
        if (stream != 0)
            ((void (*)(void *))(*(void ***)stream)[0x10 / 4])(stream);
        OSUnlockMutex(self);
        return -1;
    }
    if (stream != 0)
        ((void (*)(void *))(*(void ***)stream)[0x10 / 4])(stream);
    OSUnlockMutex(self);
    return length;
}

void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void *arg0) {
    void **obj;
    obj = *(void ***)((u8 *)arg0 + 0x21c);
    if (obj && ((s32 (*)(void *))((void **)*(void **)obj)[0x54 / 4])(obj)) {
        obj = *(void ***)((u8 *)arg0 + 0x21c);
        if (((s32 (*)(void *))((void **)*(void **)obj)[0x28 / 4])(obj)) {
            obj = *(void ***)((u8 *)arg0 + 0x21c);
            ((s32 (*)(void *, s32, s32))((void **)*(void **)obj)[0x4c / 4])(obj, 0, 0);
        } else {
            obj = *(void ***)((u8 *)arg0 + 0x21c);
            ((s32 (*)(void *))((void **)*(void **)obj)[0x48 / 4])(obj);
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
extern "C" void Shutdown__Q36nw4hbm3snd18SoundArchivePlayerFv(void *self) {
    u8 *obj = (u8 *)self;
    u8 *players = (u8 *)*(void **)(obj + 0x74);
    for (u32 i = 0; i < *(u32 *)(obj + 0x70); i++)
        __dt__Q36nw4hbm3snd11SoundPlayerFv(players + i * 0x48, -1);
    *(u32 *)(obj + 0x70) = 0;
    *(void **)(obj + 0x74) = 0;
    fn_800FA9E8(obj + 0xA8);
    if (*(void **)(obj + 0xD0) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325B70, 0x4C, lbl_80325B44);
    DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(obj + 0x78, *(void **)(obj + 0xD0), *(u32 *)(obj + 0xD4));
    if (*(void **)(obj + 0xD0) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325B2C, 0x4C, lbl_80325B00);
    DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(obj + 0x88, *(void **)(obj + 0xD0), *(u32 *)(obj + 0xD4));
    if (*(void **)(obj + 0xD0) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325AE8, 0x4C, lbl_80325ABC);
    DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(obj + 0x98, *(void **)(obj + 0xD0), *(u32 *)(obj + 0xD4));
    fn_800EE434(obj + 0xC4, *(void **)(obj + 0xD0), *(u32 *)(obj + 0xD4));
    *(u32 *)(obj + 0xD0) = 0;
    *(u32 *)(obj + 0xD4) = 0;
}

extern "C" s32 GetRequiredMemSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(void *player, void *archive) {
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
            u32 count = group.count;
            while (count != 0) {
                if (group.size != 0)
                    total += bytes;
                count--;
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
#pragma push
#pragma scheduling reset
extern "C" s32 SetupMram__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePvUl(void *self, const void *archive, void *buffer, u32 size) {
    struct SoundInfo { u32 a; u32 b; u32 c; u32 d; u32 e; u32 f; };
    struct GroupList { u32 count; u32 items[1]; };
    const char *base = lbl_80324E88;
    u32 end;
    struct Local { void *ptr; SoundInfo info; } local;
    u32 i;
    u32 count;
    u32 bytes;
    u32 required;
    u32 aligned;
    u32 result;

    if (archive == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x139, base + 0x1C);
    }
    if (buffer == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x13A, base + 0x44);
    }
    if (((u32)buffer & 3) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x13B, base + 0xEC, buffer);
    }
    if (size < (u32)GetRequiredMemSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(self, (void *)archive)) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x13C, base + 0x138);
    }

    end = (u32)buffer + size;
    local.ptr = buffer;
    if (SetupSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchivePPvPv(self, (void *)archive, &local.ptr, (void *)end) == 0) {
        return 0;
    }

    count = fn_800F27CC((void *)archive);
    required = (u32)(((struct GroupList *)local.ptr)->items + count * 2);
    aligned = (required + 3) & ~3U;
    if (aligned > end) {
        result = 0;
    } else {
        *(void **)((u8 *)self + 0x14) = local.ptr;
        local.ptr = (void *)aligned;
        *(u32 *)*(void **)((u8 *)self + 0x14) = fn_800F27CC((void *)archive);
        i = 0;
        u32 offset = 0;
        do {
            *(u32 *)((u8 *)*(void **)((u8 *)self + 0x14) + offset + 4) = 0;
            *(u32 *)((u8 *)*(void **)((u8 *)self + 0x14) + offset + 8) = 0;
            i++;
            offset += 8;
        } while (i < *(u32 *)*(void **)((u8 *)self + 0x14));
        result = 1;
    }
    if (result == 0) {
        return 0;
    }

    if (((s32 (*)(void *, void *))fn_800F2814)((void *)archive, &local.info) != 0) {
        count = local.info.a;
        bytes = count * 0x1F4;
        required = bytes + (u32)local.ptr + 3;
        aligned = required & ~3U;
        if (aligned > end) {
            result = 0;
        } else {
            if (local.ptr == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325AA4, 0x3B, lbl_80325A78);
            }
            if (CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl((u8 *)self + 0x78, local.ptr, bytes, 0x1F4) != count) {
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x20C, base + 0x174);
            }
            local.ptr = (void *)aligned;
            result = 1;
        }
        if (result == 0) {
            return 0;
        }

        count = local.info.c;
        bytes = count * 0x614;
        required = bytes + (u32)local.ptr + 3;
        aligned = required & ~3U;
        if (aligned > end) {
            result = 0;
        } else {
            if (local.ptr == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325A1C, 0x3B, lbl_803259F0);
            }
            if (CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl((u8 *)self + 0x88, local.ptr, bytes, 0x614) != count) {
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x24C, base + 0x174);
            }
            local.ptr = (void *)aligned;
            result = 1;
        }
        if (result == 0) {
            return 0;
        }

        count = local.info.f;
        bytes = count * 0x1B4;
        required = bytes + (u32)local.ptr + 3;
        aligned = required & ~3U;
        if (aligned > end) {
            result = 0;
        } else {
            if (local.ptr == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325A60, 0x3B, lbl_80325A34);
            }
            if (CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl((u8 *)self + 0x98, local.ptr, bytes, 0x1B4) != count) {
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x22C, base + 0x174);
            }
            local.ptr = (void *)aligned;
            result = 1;
        }
        if (result == 0) {
            return 0;
        }

        count = local.info.b;
        bytes = count * 0xD4;
        required = bytes + (u32)local.ptr + 3;
        aligned = required & ~3U;
        if (aligned > end) {
            result = 0;
        } else {
            if (fn_800EE428((u8 *)self + 0xC4, local.ptr, bytes) != count) {
                Panic__Q26nw4hbm2dbFPCciPCce(base, 0x26C, base + 0x1A4);
            }
            local.ptr = (void *)aligned;
            result = 1;
        }
        if (result == 0) {
            return 0;
        }
    }

    if ((u32)local.ptr - (u32)buffer != (u32)GetRequiredMemSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(self, (void *)archive)) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x163, base + 0x1D4);
    }
    *(void **)((u8 *)self + 0x10) = (void *)archive;
    *(void **)((u8 *)self + 0xD0) = buffer;
    *(u32 *)((u8 *)self + 0xD4) = size;
    return 1;
}
#pragma pop
extern "C" s32 GetSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFUl(void *arg0, u32 arg1) {
    struct SoundArchivePlayer {
        u8 pad[0x70];
        u32 playerCount;
        void *players;
    };
    SoundArchivePlayer *self = (SoundArchivePlayer *)arg0;
    register u32 playerCount;

    playerCount = self->playerCount;
    if (arg1 >= playerCount) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x2B2, lbl_803250C8, arg1, 0);
    }
    return (s32)((u8 *)self->players + arg1 * 0x48);
}

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
#pragma dont_inline off
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

extern "C" void fn_800FDE60(void);
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
extern "C" void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void);
extern "C" void fn_800F7110(void *self, unsigned long taskId) {
    unsigned long id = taskId;
    void* manager = ((void* (*)(void))fn_800FDE60)();
    ((void (*)(void*, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(manager, id);
}

extern "C" s32 detail_GetFileWaveDataAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl_800F6490(void *, u32);
extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv_800FFECC(void *, const void *);
extern "C" s32 ReadWaveSoundInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail13WaveSoundInfoi(void *, void *, s32);
extern "C" s32 ReadWaveSoundNoteInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail17WaveSoundNoteInfoii(void *, void *, s32, s32);
extern "C" s32 ReadWaveParam__Q46nw4hbm3snd6detail13WsdFileReaderCFiPQ46nw4hbm3snd6detail8WaveDataPCv(void *, s32, void *, const void *);
extern "C" const char lbl_80325110[];
extern "C" s32 GetWaveSoundData__Q46nw4hbm3snd18SoundArchivePlayer11WsdCallbackCFPQ46nw4hbm3snd6detail13WaveSoundInfoPQ46nw4hbm3snd6detail17WaveSoundNoteInfoPQ46nw4hbm3snd6detail8WaveDataPCviiUl(void *self, void *info, void *noteInfo, void *waveData, const void *file, s32 index, s32 noteIndex, u32 waveIndex) {
    u8 reader[0x38];
    u8 *archive = *(u8 **)((u8 *)self + 4);
    s32 result;
    s32 waveAddress;
    if (*(u32 *)(archive + 0x10) == 0)
        result = 0;
    else
        result = fn_800F273C(self);
    if (result == 0)
        return 0;
    if (*(u32 *)(archive + 0x10) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x2AC, lbl_80325110);
    waveAddress = detail_GetFileWaveDataAddress__Q36nw4hbm3snd18SoundArchivePlayerCFUl_800F6490(archive, waveIndex);
    if (waveAddress == 0)
        return 0;
    __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv_800FFECC(reader, file);
    if (ReadWaveSoundInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail13WaveSoundInfoi(reader, info, index) == 0)
        return 0;
    if (ReadWaveSoundNoteInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail17WaveSoundNoteInfoii(reader, noteInfo, index, noteIndex) == 0)
        return 0;
    return ReadWaveParam__Q46nw4hbm3snd6detail13WsdFileReaderCFiPQ46nw4hbm3snd6detail8WaveDataPCv(reader, *(s32 *)noteInfo, waveData, (const void *)waveAddress);
}

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
    char buffer[0x230];
    char reader[8];
    void* callback;
    void* mutex;
    void* result;
    void* base;

    fn_800F41D0(buffer, *(s32*)((char*)arg0 + 0x14));
    mutex = *(void**)((char*)arg0 + 0x2c);
    OSLockMutex(mutex);
    *(void**)((char*)arg0 + 0x10) = buffer;
    OSUnlockMutex(mutex);
    result = LoadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatable(buffer, *(u32*)((char*)arg0 + 0x18), *(void**)((char*)arg0 + 0x20));
    mutex = *(void**)((char*)arg0 + 0x2c);
    OSLockMutex(mutex);
    *(void**)((char*)arg0 + 0x10) = 0;
    OSUnlockMutex(mutex);
    if (result == 0) {
        callback = *(void**)((char*)arg0 + 0x24);
        if (callback) ((void (*)(s32, void*, s32, void*))callback)(0, 0, 0, *(void**)((char*)arg0 + 0x28));
        fn_800F420C((s32)buffer, -1);
        return;
    }
    __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(reader, result);
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

extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv(void* self) {
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
        virtual s32 v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19(s32, s32);
        virtual void v20();
        virtual s32 v21();
    };
    void* mutex = *(void**)((u8*)self + 0x24);
    OSLockMutex(mutex);
    Sound* sound = *(Sound**)((u8*)self + 0x10);
    *(u32*)((u8*)self + 0x1c) = 0;
    if (sound != 0 && sound->v21() != 0) {
        sound = *(Sound**)((u8*)self + 0x10);
        if (sound->v10() != 0) {
            sound = *(Sound**)((u8*)self + 0x10);
            sound->v19(0, 0);
        } else {
            sound = *(Sound**)((u8*)self + 0x10);
            sound->v18();
        }
    }
    OSUnlockMutex(mutex);
}

extern "C" const char lbl_80325670[];
extern "C" void *__ct__Q46nw4hbm3snd18SoundArchivePlayer16StrmDataLoadTaskFPvUlliUllbRQ56nw4hbm3snd6detail10StrmPlayer11LoadCommandRCQ36nw4hbm3snd12SoundArchiveUlUlR7OSMutex(void *self, void *arg1, unsigned long arg2, long arg3, unsigned long arg4, long arg5, bool arg6, void *arg7, const void *arg8, unsigned long arg9, unsigned long arg10, void *arg11) {
    *(void **)((u8 *)self + 0x00) = (void *)lbl_80325670;
    *(u32 *)((u8 *)self + 0x04) = 0;
    *(u32 *)((u8 *)self + 0x08) = 0;
    *(u32 *)((u8 *)self + 0x0c) = (u32)arg9;
    *(u32 *)((u8 *)self + 0x10) = (u32)arg7;
    *(u32 *)((u8 *)self + 0x14) = 0;
    *(u32 *)((u8 *)self + 0x18) = (u32)arg8;
    *(u32 *)((u8 *)self + 0x1c) = (u32)arg10;
    *(void **)((u8 *)self + 0x20) = arg1;
    *(u32 *)((u8 *)self + 0x24) = (u32)arg2;
    *(u32 *)((u8 *)self + 0x28) = (u32)arg3;
    *(u32 *)((u8 *)self + 0x2c) = (u32)arg4;
    *(u32 *)((u8 *)self + 0x30) = (u32)arg5;
    *(u32 *)((u8 *)self + 0x34) = (u32)arg6;
    *(u8 *)((u8 *)self + 0x38) = (u8)arg7;
    *(void **)((u8 *)self + 0x3c) = arg11;
    if (((u32)arg1 & 31) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x762, lbl_80324E88 + 0x6c0, arg1);
    if (((u32)arg2 & 31) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x763, lbl_80324E88 + 0x708, arg2);
    if (((u32)arg3 & 3) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x764, lbl_80324E88 + 0x750, arg3);
    return self;
}

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

extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv_800F7FEC(void* self) {
    class Sound {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual s32 m8();
        virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
        virtual void v13(); virtual void v14(); virtual void v15(); virtual void m16();
        virtual void m17(s32, s32); virtual void v18(); virtual s32 Check();
    };
    void* mutex = *(void**)((u8*)self + 0x3c);
    OSLockMutex(mutex);
    *(u32*)((u8*)self + 0x10) = 0;
    Sound* sound = *(Sound**)((u8*)self + 0x14);
    if (sound && sound->Check()) {
        sound = *(Sound**)((u8*)self + 0x14);
        if (sound->m8()) {
            sound = *(Sound**)((u8*)self + 0x14);
            sound->m17(0, 0);
        } else {
            sound = *(Sound**)((u8*)self + 0x14);
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

extern "C" s32 __dt__Q36nw4hbm3snd18SoundArchivePlayerFv(s32);
extern "C" void fn_800F823C(s32 arg0) {
    __dt__Q36nw4hbm3snd18SoundArchivePlayerFv(arg0 - 0xC);
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
    *(void**)self = &lbl_80325C40;
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

    *(volatile u32*)(p + 4) = zero;
    *(volatile u32*)(p + 8) = zero;
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

extern "C" void *__dt__Q36nw4hbm3snd11SoundPlayerFv(void *arg0, s32 arg1) {
    class Dummy {
    public:
        virtual void v0() {}
        virtual void v1() {}
        virtual void v2() {}
        virtual void v3() {}
        virtual void destroy(s32) {}
    };
    register void *node;
    register void *next;
    if (arg0 != 0) {
        void *head = (char *)arg0 + 4;
        node = *(void **)head;
        while (node != head) {
            next = *(void **)node;
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262E8, 0x23D, (const char *)lbl_803262C4);
            ((Dummy *)((char *)node - 0xC0))->destroy(0);
            node = next;
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

#pragma use_lmw_stmw off
void Update__Q36nw4hbm3snd11SoundPlayerFv(void *self) {
    struct Dummy {
        virtual ~Dummy();
        virtual void f0();
        virtual void update();
    };

    void *head = *(void **)((u8 *)self + 4);
    void *end = (u8 *)self + 4;
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
#pragma use_lmw_stmw reset
void StopAllSound__Q36nw4hbm3snd11SoundPlayerFi(void *self, s32 arg1) {
    struct Dummy {
        virtual ~Dummy();
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void stopAllSound(s32);
    };

    register void *end = (u8 *)self + 4;
    register void *head = *(void **)((u8 *)self + 4);
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
    if (!(farg0 >= lbl_805610BC)) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x99, lbl_80325C64);
    *(f32 *)((u8 *)arg0 + 0x28) = farg0;
}
#pragma pop
extern "C" s32 fn_800F87E8(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x30); }

extern "C" u8 fn_800F87F0(void *arg0) { return *(u8 *)((u8 *)arg0 + 0x2C); }

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800F87F8(s32 arg0, s32 arg1) {
    s32 valid = 0;
    if (arg1 >= 0 && arg1 < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x103, lbl_80325C8C, arg1, 0, 4);
    return *(f32 *)((u8 *)(arg0 + arg1 * 4) + 0x38);
}

void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(void *self, void *pSound) {
    if (pSound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262B8, 0x233, (const char *)lbl_80326294);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(self, (u8 *)pSound + 0xC0);
    *(u32 *)((u8 *)pSound + 0x10) = 0;
}

extern "C" void detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *self, void *sound) {
    void *head = (char *)self + 0x10;
    void *node = *(void **)head;
    while (node != head) {
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326348, 0x23D, lbl_80326324);
        int priority = *(unsigned char *)((char *)node - 0x54) + *(int *)((char *)node - 0x88);
        int soundPriority = *(unsigned char *)((char *)sound + 0x74) + *(int *)((char *)sound + 0x40);
        priority &= ~(priority >> 31);
        if (priority > 0x7F) priority = 0x7F;
        soundPriority &= ~(soundPriority >> 31);
        if (soundPriority > 0x7F) soundPriority = 0x7F;
        if (soundPriority < priority)
            break;
        node = *(void **)node;
    }
    if (sound == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326288, 0x233, (const char *)lbl_80326264);
    void *iterator = node;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)self + 0xC, &iterator, (char *)sound + 0xC8);
}

extern "C" void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *self, void *pSound) {
    if (pSound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326288, 0x233, (const char *)lbl_80326264);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)self + 0xC, (u8 *)pSound + 0xC8);
}

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
extern "C" int CheckPlayableSoundCount__Q36nw4hbm3snd11SoundPlayerFiPQ46nw4hbm3snd6detail19ExternalSoundPlayer(void *self, int priority, void *external) {
    u8 *p = (u8 *)self;
    u8 *sound;
    int count;
    int limit;
    int value;
    void (**vtable)(void *);

    if (*(u16 *)(p + 0x24) == 0)
        return 0;

    for (;;) {
        if (*(s32 *)(p + 0) >= *(u16 *)(p + 0x24)) {
            if (*(s32 *)(p + 0xC) == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_803263A8, 0x1F1, lbl_80326384);
            sound = *(u8 **)(p + 0x10);
            if (sound == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326348, 0x23D, lbl_80326324);
            sound -= 0xC8;
            if (sound == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326378, 0x193, lbl_80326354);
            value = sound[0x74] + *(s32 *)(sound + 0x40);
            if (value > 0x7F)
                value = 0x7F;
            else if (value < 0)
                value = 0;
            if (priority < value)
                return 0;
            vtable = *(void (***)(void *))sound;
            vtable[5](sound);
            continue;
        }

        if (external == 0)
            return 1;
        p = (u8 *)external;
        if (*(u16 *)(p + 0xC) == 0)
            return 0;
        if (*(s32 *)p < *(u16 *)(p + 0xC))
            return 1;
        sound = (u8 *)GetLowestPrioritySound__Q46nw4hbm3snd6detail19ExternalSoundPlayerFv(external);
        if (sound == 0)
            return 0;
        value = sound[0x74] + *(s32 *)(sound + 0x40);
        if (value > 0x7F)
            value = 0x7F;
        else if (value < 0)
            value = 0;
        if (priority < value)
            return 0;
        vtable = *(void (***)(void *))sound;
        vtable[5](sound);
        if (*(s32 *)p < *(u16 *)(p + 0xC))
            return 1;
    }
}

extern "C" void detail_AppendPlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10PlayerHeap(void* this_, void* pHeap) {
    void* heap = pHeap;
    void* self = this_;
    if (heap == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325C50, 0x256, (const char*)lbl_80325D6C);
    }
    *(void**)((u8*)heap + 0x38) = self;
    void* node = (u8*)self + 0x1C;
    if (self == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323834, 0x233, (const char*)lbl_80323810);
    }
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((void*)((u8*)self + 0x18), &node, (void*)((u8*)heap + 0x2C));
    *(u8*)((u8*)self + 0x2D) = 1;
}

extern "C" void detail_FreePlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *player, void *sound) {
    extern u8 lbl_80325D98[];
    extern u8 lbl_80323834[];
    extern u8 lbl_80323810[];
    void *heap;
    void *iterator;
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x280, (const char *)lbl_80325D98);
    }
    heap = *(void **)((char *)sound + 4);
    if (heap != 0) {
        iterator = (char *)player + 0x1C;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)player + 0x18, &iterator, (char *)heap + 0x2C);
    }
    if (heap != 0)
        *(void **)((char *)heap + 0x34) = 0;
    *(void **)((char *)sound + 4) = 0;
}

extern "C" void detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(void* this_, void* pHandle, u32 id, void* pAmbient, void* pPlayer, void* pInfo) {
    struct Base {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void* Start(void*, u32, void*, void*, void*);
    };
    struct Sound { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void Attach(); };
    void* sound = ((Base*)this_)->Start(pHandle, id, pAmbient, pPlayer, pInfo);
    if (sound == 0) {
        if (*(void**)pHandle != 0) {
            ((Sound*)sound)->Attach();
        }
    }
}

extern "C" void fn_800E2E24(void);
extern "C" s32 SCInit(void);
extern "C" u32 SCCheckStatus(void);
extern "C" u8 SCGetSoundMode(void);
extern "C" void SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(s32);
extern "C" void Setup__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv(void);
extern "C" s32 Create__Q46nw4hbm3snd6detail10TaskThreadFl(s32);
extern "C" s32 fn_800FA4C4(s32);
extern "C" void InitSoundSystem__Q36nw4hbm3snd11SoundSystemFll(s32 arg0, s32 arg1) {
    u32 status;
    u8 mode;
    if (lbl_8055DE60 != 0) return;
    lbl_8055DE60 = 1;
    Instance__15EmissionManagerFv();
    fn_800E2E24();
    SCInit();
    do { status = SCCheckStatus(); } while (status == 1);
    if (status != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803263B8, 0x4f, (const char *)(lbl_803263B8 + 0x14));
    mode = SCGetSoundMode();
    switch (mode) {
    case 0: Instance__15EmissionManagerFv(); SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(3); break;
    case 1: Instance__15EmissionManagerFv(); SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(0); break;
    case 2: Instance__15EmissionManagerFv(); SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(2); break;
    default: Instance__15EmissionManagerFv(); SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(0); break;
    }
    GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
    Setup__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
    fn_800FE648();
    if (Create__Q46nw4hbm3snd6detail10TaskThreadFl(arg1) == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803263B8, 0x7e, (const char *)(lbl_803263B8 + 0x48));
    GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv();
    if (fn_800FA4C4(arg0) == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803263B8, 0x82, (const char *)(lbl_803263B8 + 0x48));
}

extern "C" void fn_800FA350(void) {
    void *v;
    if (lbl_8055DE60 != 0) {
        GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv();
        if (Shutdown__Q46nw4hbm3snd6detail11SoundThreadFv() == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803263B8, 0x8D,
                                         (const char*)lbl_80326400);
        }
        fn_800FE648();
        if (Destroy__Q46nw4hbm3snd6detail10TaskThreadFv() == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803263B8, 0x91,
                                         (const char*)lbl_80326400);
        }
        v = GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
        fn_800EEB64(v);
        v = Instance__15EmissionManagerFv();
        fn_800E2F84(v);
        lbl_8055DE60 = 0;
    }
}

#pragma push
#pragma scheduling on
extern "C" void* GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv(void) {
    if ((s8)lbl_8055DE68 == 0) {
        volatile u32 *base = (volatile u32 *)lbl_80412CC8;
        base[0x2388 / 4] = 0;
        register void *object = (void *)((u8 *)base + 0x2388);
        base[0x238c / 4] = 0;
        base[0x2378 / 4] = 0;
        base[0x237c / 4] = 0;
        base[0x2384 / 4] = 0;
        base[0x2388 / 4] = (u32)object;
        base[0x238c / 4] = (u32)object;
        ((volatile u8 *)base)[0x2394] = 0;
        register const void *label = (const void *)&lbl_80412CB8;
        __register_global_object((void *)base, (void *)&__dt__10TitleSceneFv,
                                 (void *)label, object);
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

extern "C" void Setup__Q46nw4hbm3snd6detail14StrmBufferPoolFPvUli(void* this_, u32 size, s32 count) {
    if (count != 0) {
        u32 level = OSDisableInterrupts();
        *(u32*)this_ = size;
        *(u32*)((u8*)this_ + 4) = count;
        *(u32*)((u8*)this_ + 8) = count / count;
        *(u32*)((u8*)this_ + 0xC) = count;
        *(u32*)((u8*)this_ + 0x10) = 0;
        memset((void*)((u8*)this_ + 0x14), 0, 4);
        if (*(s32*)((u8*)this_ + 0xC) > 0x20) {
            extern const char lbl_803264E0[];
            extern const char lbl_803264F4[];
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803264E0, 0x2A, lbl_803264F4);
        }
        OSRestoreInterrupts(level);
    }
}

extern "C" void fn_800FA9E8(void* arg0) {
    u32 level = OSDisableInterrupts();
    *(s32*)arg0 = 0;
    *(s32*)((u8*)arg0 + 4) = 0;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    OSRestoreInterrupts(level);
}

extern "C" void *Alloc__Q44nw4r3snd6detail14StrmBufferPoolFv(void *arg0) {
    register void *base = arg0;
    OSDisableInterrupts();
    int used = *(int *)((char *)base + 0x10);
    int count = *(int *)((char *)base + 0xC);
    if (used >= count) {
        OSRestoreInterrupts(0);
        return 0;
    }
    int limit = (count + 7) >> 3;
    for (int i = 0; i < limit; i++) {
        unsigned char *bits = (unsigned char *)base + 0x14 + i;
        unsigned char value = *bits;
        if (value != 0xFF) {
            unsigned int mask = 1;
            int j = 0;
            for (; j < 8; j++) {
                if ((value & mask) == 0) {
                    *bits = value | mask;
                    int index = j + (i << 3);
                    int stride = *(int *)((char *)base + 8);
                    void *result = (char *)(*(void **)base) + stride * index;
                    *(int *)((char *)base + 0x10) = used + 1;
                    OSRestoreInterrupts(0);
                    return result;
                }
                mask <<= 1;
            }
        }
    }
    OSRestoreInterrupts(0);
    return 0;
}

extern "C" void Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(void *self, void *ptr) {
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
extern "C" s32 fn_800FACC0(void *arg0, u16 *arg1, s32 arg2, s32 arg3) {
    u8 *sound = (u8 *)*((u8 **)arg0 + 1);
    u8 *ref;
    u8 *data;
    s32 i;
    if (*(s32 *)arg0 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326518, 0xAD, lbl_80326688);
    if (sound[9] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F8, 0x6F, lbl_80326738);
    ref = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(sound[8], *(u32 *)(sound + 0xC), sound + 8);
    if (*ref != 2)
        return 0;
    if (sound[0x19] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598E0, 0x6F, lbl_803266B4);
    ref = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(sound[0x18], *(u32 *)(sound + 0x1C), sound + 8);
    if (arg2 >= *ref)
        return 0;
    ref += arg2 * 8;
    if (ref[5] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598E8, 0x6F, lbl_803266E0);
    data = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[4], *(u32 *)(ref + 8), sound + 8);
    if (data[1] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598F0, 0x6F, lbl_8032670C);
    data = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(data[0], *(u32 *)(data + 4), sound + 8);
    for (i = 0; i < 0x30; i += 2)
        *(u16 *)((u8 *)arg1 + i) = *(u16 *)(data + i);
    return 1;
}

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
    s32 sp27;
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
    DummyStream *stream;

    stream = (DummyStream *)M2C_FIELD(arg0, void **, 0);
    stream->f15(0, 0, arg3);
    temp_r30 = (s32)&sp27 & 0xFFFFFFE0;
    if (stream->f3((void *)temp_r30, 0x40) != 0x40U) {
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
    stream->f15(0, 0, temp_r6);
    if (stream->f3(arg1, temp_r29) != temp_r29) {
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
    switch (result) {
    case 0:
    case 2:
        break;
    case 1:
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
        break;
    default:
        break;
    }
    *((u8 *)self + 0x48) = 1;
    return 1;
}

extern "C" void ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" void fn_800FB620(void *self) {
    if (*(u8 *)((u8 *)self + 0x48) != 0) {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
    }
}

extern "C" void UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(void *arg0) {
    const u8 *label = (const u8 *)lbl_80326768;
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
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xD1, (const char *)(label + 0x44));
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
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xD1, (const char *)(label + 0x44));
                }
                Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void * volatile *)((u8 *)arg0 + 0x438), var_r28_2);
                M2C_FIELD(arg0, u8 *, 0x4D) = var_r28_2;
            }
            OSRestoreInterrupts(temp_r29_2);
        }
        if ((s32) M2C_FIELD(arg0, u8 *, 0x4E) == 0) {
            if ((u32) M2C_FIELD(arg0, u32 *, 0xA0) >= (u32) (M2C_FIELD(arg0, s32 *, 0x68) - 1)) {
                Warning__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xFD, (const char *)(label + 0x70));
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
                        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xD1, (const char *)(label + 0x44));
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
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0xD1, (const char *)(label + 0x44));
                }
                Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void * volatile *)((u8 *)arg0 + 0x438), var_r28_4);
                M2C_FIELD(arg0, u8 *, 0x4D) = var_r28_4;
            }
            OSRestoreInterrupts(temp_r29_4);
        }
        if (((s32) M2C_FIELD(arg0, u8 *, 0x52) == 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x4F) == 0)) {
            if (*(void * volatile *)((u8 *)arg0 + 0x438) == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80326768, 0x114, (const char *)(label + 0x44));
            }
            s32 temp_r28 = GetCurrentPlayingSample__Q46nw4hbm3snd6detail7AxVoiceCFv(M2C_FIELD(arg0, s32 *, 0x438)) / (u32) M2C_FIELD(arg0, u32 *, 0x30);
            goto loop_check;
loop_body:
            UpdatePlayingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFv(arg0);
            UpdateLoadingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFQ66nw4hbm3snd6detail10StrmPlayer11LoadCommand6Status(arg0, 1);
loop_check:
            if (M2C_FIELD(arg0, s32 *, 0x7C) != temp_r28) {
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
    register f32 temp_f8;
    f32 temp_f9;
    f32 temp_f10;
    register f32 temp_f25;
    register f32 temp_f26;
    register f32 temp_f27;
    register f32 temp_f28;
    register f32 temp_f29;
    register f32 temp_f30;
    register f32 temp_f31;

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
    s32 player = (s32)arg0;
    u8 *p;
    s32 value;

    value = *(s32 *)(((u8 *)player) + 0x80) + 1;
    *(s32 *)(((u8 *)player) + 0x80) = value;
    if (value > *(s32 *)(((u8 *)player) + 0x88)) {
        if (((u8 *)player)[0x11] != 0) {
            s32 block, i;
            u32 irq, loopEnd;
            block = *(s32 *)(((u8 *)player) + 0x54);
            *(s32 *)(((u8 *)player) + 0x80) = *(s32 *)(((u8 *)player) + 0x84);
            if (block < 0x7FFFFFFF) *(s32 *)(((u8 *)player) + 0x54) = block + 1;
            loopEnd = (u32)(*(s32 *)(((u8 *)player) + 0x78) * *(s32 *)(((u8 *)player) + 0x30));
            
            if (*(void **)(((u8 *)player) + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x19E, file + 0x44);
            irq = OSDisableInterrupts();
            p = ((u8 *)player);
            for (i = 0; i < *(s32 *)(((u8 *)player) + 0x4A0); ++i) {
                SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(((u8 *)player) + 0x438), i, *(void **)(p + 0x4A8), 0);
                SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(((u8 *)player) + 0x438), i, *(void **)(p + 0x4A8), loopEnd);
                p += 0x38;
            }
            SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(((u8 *)player) + 0x438), 1);
            OSRestoreInterrupts(irq);
        } else Panic__Q26nw4hbm2dbFPCciPCce(file, 0x1C6, file + 0x94);
    }

    value = *(s32 *)(((u8 *)player) + 0x7C) + 1;
    *(s32 *)(((u8 *)player) + 0x7C) = value;
    if (value >= *(s32 *)(((u8 *)player) + 0x78)) {
        s32 block, i;
        u32 irq, loopEnd;
        block = *(s32 *)(((u8 *)player) + 0x6C);
        loopEnd = (u32)(block * *(s32 *)(((u8 *)player) + 0x30));
        *(s32 *)(((u8 *)player) + 0x7C) = 0;
        *(s32 *)(((u8 *)player) + 0x78) = block;
        
        if (*(void **)(((u8 *)player) + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x19E, file + 0x44);
        irq = OSDisableInterrupts();
        p = ((u8 *)player);
        for (i = 0; i < *(s32 *)(((u8 *)player) + 0x4A0); ++i) {
            SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(((u8 *)player) + 0x438), i, *(void **)(p + 0x4A8), 0);
            SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(((u8 *)player) + 0x438), i, *(void **)(p + 0x4A8), loopEnd);
            p += 0x38;
        }
        SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(((u8 *)player) + 0x438), 1);
        OSRestoreInterrupts(irq);
    }

    if (*(s32 *)(((u8 *)player) + 0x7C) == *(s32 *)(((u8 *)player) + 0x78) - 1 && *(u32 *)((u8 *)*(void **)(((u8 *)player) + 0x438) + 0x118) == 0) {
        if (((u8 *)player)[0x51] == 0) Warning__Q26nw4hbm2dbFPCciPCce(file, 0x1DC, file + 0xB4);
        if (((u8 *)player)[0x50] == 0 && ((u8 *)player)[0x51] != 0) {
            s32 i;
            u32 irq;
            u16 samples[3];
            irq = OSDisableInterrupts();
            p = ((u8 *)player);
            for (i = 0; i < *(s32 *)(((u8 *)player) + 0x4A0); ++i) {
                samples[0] = *(u16 *)(p + 0x518);
                samples[1] = 0;
                samples[2] = 0;
                fn_800E5A8C(*(void **)(((u8 *)player) + 0x438), i, *(u32 *)((u8 *)*(void **)(((u8 *)player) + 0x438) + 0x118), samples);
                p += 2;
            }
            SetVoiceType__Q46nw4hbm3snd6detail7AxVoiceFQ56nw4hbm3snd6detail7AxVoice9VoiceType(*(void **)(((u8 *)player) + 0x438), 1);
            OSRestoreInterrupts(irq);
        }
        ((u8 *)player)[0x51] = ((u8 *)player)[0x50] = 0;
    }

    if (*(s32 *)(((u8 *)player) + 0x80) == *(s32 *)(((u8 *)player) + 0x88) - 1) {
        s32 next = *(s32 *)(((u8 *)player) + 0x7C) + 1;
        if (((u8 *)player)[0x11] != 0) {
            s32 i, following, block;
            u32 irq, loopStart, loopEnd;
            following = next + 1;
            block = *(s32 *)(((u8 *)player) + 0x78);
            if (following >= block) following -= block;
            irq = OSDisableInterrupts();
            loopEnd = (u32)(*(s32 *)(((u8 *)player) + 0x38) + next * *(s32 *)(((u8 *)player) + 0x30));
            loopStart = (u32)(following * *(s32 *)(((u8 *)player) + 0x30));
            
            if (*(void **)(((u8 *)player) + 0x438) == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x19E, file + 0x44);
            {
                u32 innerIrq = OSDisableInterrupts();
                p = ((u8 *)player);
                for (i = 0; i < *(s32 *)(((u8 *)player) + 0x4A0); ++i) {
                    SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(((u8 *)player) + 0x438), i, *(void **)(p + 0x4A8), loopStart);
                    SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)(((u8 *)player) + 0x438), i, *(void **)(p + 0x4A8), loopEnd);
                    p += 0x38;
                }
                SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)(((u8 *)player) + 0x438), 1);
                OSRestoreInterrupts(innerIrq);
            }
            if (((u8 *)player)[0x10] == 2) {
                if (*(u32 *)((u8 *)*(void **)(((u8 *)player) + 0x438) + 0x118) == 0) {
                    SetVoiceType__Q46nw4hbm3snd6detail7AxVoiceFQ56nw4hbm3snd6detail7AxVoice9VoiceType(*(void **)(((u8 *)player) + 0x438), 0);
                    s32 j;
                    p = ((u8 *)player) + 0x4D8;
                    for (j = 0; j < *(s32 *)(((u8 *)player) + 0x4A0); ++j) {
                        fn_800E5A8C(*(void **)(((u8 *)player) + 0x438), j, *(u32 *)((u8 *)*(void **)(((u8 *)player) + 0x438) + 0x118), p);
                        p += 0x38;
                    }
                }
                if (next == *(s32 *)(((u8 *)player) + 0x78) - 1) ((u8 *)player)[0x50] = 1;
            }
            OSRestoreInterrupts(irq);
            return;
        }
        s32 i;
        u32 irq;
        irq = OSDisableInterrupts();
        p = ((u8 *)player);
        for (i = 0; i < *(s32 *)(((u8 *)player) + 0x4A0); ++i) {
            
            StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl((s32)*(void **)(((u8 *)player) + 0x438), i, *(void **)(p + 0x4A8), (u32)(*(s32 *)(((u8 *)player) + 0x38) + next * *(s32 *)(((u8 *)player) + 0x30)));
            p += 0x38;
        }
        OSRestoreInterrupts(irq);
        ((u8 *)player)[0x52] = 1;
    }
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
#pragma pop
extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC508(void) {
    void *node = *(void **)((u8 *)&lbl_8041506C + 4); void *end = (u8 *)&lbl_8041506C + 4;
    while (node != end) { void *player = node; node = *(void **)node; if (!player) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326B8C, 0x23D, lbl_80326B68); void **vt = *(void ***)((u8 *)player - 8); ((void (*)(void *))*(void **)((u8 *)vt + 0x10))((u8 *)player - 8); }
    if (lbl_8041506C) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x2EE, lbl_8032687C);
}

extern "C" void fn_800FC5B8(void *arg0, f32 value) {
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)arg0 + 0x45C) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 fn_800FC5F8(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x45C); }

extern "C" void fn_800FC600(void *arg0, f32 value) { u32 token = OSDisableInterrupts(); *(f32 *)((u8 *)arg0 + 0x460) = value; OSRestoreInterrupts(token); }

extern "C" f32 fn_800FC640(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x460); }

extern "C" const char lbl_803268AC[];
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC648(void *self, s32 bus, f32 value) {
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
    s32 valid = 0;
    if (bus >= 0 && bus < 3) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x310, lbl_803268AC, bus, 0, 3);
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
void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC7B4(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x322, lbl_803268E4, bus, 0, 4);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x470 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC850(s32 arg0, s32 arg1) {
    s32 valid = 0;
    if (arg1 >= 0 && arg1 < 4)
        valid = 1;
    if (valid == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x329, lbl_803268E4, arg1, 0, 4);
    return *(f32 *)(arg0 + arg1 * 4 + 0x470);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC8D8(void *arg0, s32 arg1, f32 value) {
    int valid = 0;
    if (arg1 >= 0 && arg1 < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x32f, lbl_803268E4, arg1, 0, 4);
    u32 token = OSDisableInterrupts();
    *(f32 *)((char *)arg0 + 0x480 + arg1 * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC974(void *self, s32 bus) {
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x336, lbl_803268E4, bus, 0, 4);
    return *(f32 *)((u8 *)self + 0x480 + bus * 4);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC9FC(void *self, s32 bus, f32 value) {
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x33C, lbl_803268E4, bus, 0, 4);
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x490 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FCA98(void *self, s32 bus) {
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x343, lbl_803268E4, bus, 0, 4);
    return *(f32 *)((u8 *)self + 0x490 + bus * 4);
}

extern "C" s32 SetupPlayer__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(void *, const void *);
extern "C" void UpdateLoadingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFQ66nw4hbm3snd6detail10StrmPlayer11LoadCommand6Status(void *, s32);
extern "C" void StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(s32, s32, const void *, unsigned long);
extern "C" void Setup__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(void *player, const void *header) {
    register s32 index;
    register s32 stride;
    register s32 token;
    register void *voice;
    if (SetupPlayer__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(player, header) == 0) {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(player);
    } else {
        index = 0;
        *(s32 *)((u8 *)player + 0x58) = 0;
        while (index < *(s32 *)((u8 *)player + 0x68)) {
            UpdateLoadingBlockIndex__Q46nw4hbm3snd6detail10StrmPlayerFQ66nw4hbm3snd6detail10StrmPlayer11LoadCommand6Status(player, 0);
            ++*(s32 *)((u8 *)player + 0x58);
            if (*(u8 *)((u8 *)player + 0x53) == 0)
                ++index;
            else
                break;
        }
        if (*(u32 *)((u8 *)player + 0x28) <= 2 && *(u8 *)((u8 *)player + 0x11) == 0) {
            stride = (*(s32 *)((u8 *)player + 0x28) - 1) * *(s32 *)((u8 *)player + 0x30);
            token = OSDisableInterrupts();
            voice = player;
            index = 0;
            do {
                StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(s32 *)((u8 *)player + 0x438), index, *(const void **)((u8 *)voice + 0x4A8), *(unsigned long *)((u8 *)player + 0x38) + stride);
                voice = (u8 *)voice + 0x38;
                ++index;
            } while (index < *(s32 *)((u8 *)player + 0x4A0));
            OSRestoreInterrupts(token);
            *(u8 *)((u8 *)player + 0x52) = 1;
        }
    }
}

extern "C" s32 AllocChannels__Q46nw4hbm3snd6detail10StrmPlayerFii(void *, s32);
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
    if (AllocChannels__Q46nw4hbm3snd6detail10StrmPlayerFii(arg0, *(s32 *)(((u8 *)arg0) + 0x4A4)) == 0) {
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

#pragma dont_inline on
#pragma use_lmw_stmw off
void FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(void *self) {
    u32 irqState = OSDisableInterrupts();
    u8 *player = (u8 *)self;
    s32 index = 0;
    s32 zero = 0;

    while (index < *(s32 *)((u8 *)self + 0x4A0)) {
        void *buffer = *(void **)(player + 0x4A8);
        if (buffer != 0) {
            Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(*(void **)((u8 *)self + 0x42C), buffer);
            *(s32 *)(player + 0x4A8) = zero;
            *(s32 *)(player + 0x4AC) = zero;
        }
        player += 0x38;
        index += 1;
    }

    *(s32 *)((u8 *)self + 0x4A0) = zero;
    if (*(void **)((u8 *)self + 0x438) != 0) {
        Free__Q46nw4hbm3snd6detail7AxVoiceFv(*(void **)((u8 *)self + 0x438));
        *(s32 *)((u8 *)self + 0x438) = zero;
    }
    OSRestoreInterrupts(irqState);
}
#pragma use_lmw_stmw reset
#pragma dont_inline off

extern "C" void VoiceCallbackFunc__Q46nw4hbm3snd6detail10StrmPlayerFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv(void *voice, s32 status, void *player) {
    const char *base = lbl_80326768;
    if (player == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x504, base + 0x238);
    if (*(void **)((char *)player + 0x438) != voice)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x506, base + 0x268);
    if (status < 2) {
        if (status >= 0) {
            Free__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
            FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(player);
            return;
        }
    } else if (status < 4) {
        *(void **)((char *)player + 0x438) = 0;
        FreeChannels__Q46nw4hbm3snd6detail10StrmPlayerFv(player);
        return;
    }
    Panic__Q26nw4hbm2dbFPCciPCce(base, 0x515, base + 0x298, status);
}

extern "C" const char lbl_80326C7C[];
extern "C" const char lbl_80326C58[];
extern "C" void NotifyAsyncEnd__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFb(void *self, bool success) {
    u32 token;
    void *list;
    void *node;
    void *iterator;
    token = OSDisableInterrupts();
    list = (u8 *)*(void **)((u8 *)self + 4) + 0xA0;
    if (self == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
    node = (u8 *)self + 0x14;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(list, node);
    if (success) {
        if (*(u32 *)((u8 *)self + 8) == 0) {
            if (--*(u32 *)((u8 *)*(void **)((u8 *)self + 4) + 0x58) == 0)
                *(u8 *)((u8 *)*(void **)((u8 *)self + 4) + 0x4A) = 1;
        }
    } else ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(*(void **)((u8 *)self + 4));
    list = (u8 *)*(void **)((u8 *)self + 4) + 0x94;
    iterator = (u8 *)list + 4;
    if (self == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326C7C, 0x233, lbl_80326C58);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(list, &iterator, node);
    OSRestoreInterrupts(token);
}

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
extern "C" void* __dt__Q46nw4hbm3snd6detail10StrmPlayerFv(void* arg0, int arg1) {
    void* temp_r3;
    void* temp_r3_2;
    if (arg0 != 0) {
        fn_8002F634((char*)arg0 + 0xAC, (void*)fn_800FB374, 0x1C, 0x20);
        temp_r3 = (char*)arg0 + 0xA0;
        if (temp_r3 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv(temp_r3, 0);
        temp_r3_2 = (char*)arg0 + 0x94;
        if (temp_r3_2 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv(temp_r3_2, 0);
        if (arg1 > 0) ((void (*)(void*))fn_80128668)(arg0);
    }
    return arg0;
}
extern "C" void Setup__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(void *, const void *);
extern "C" void Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(void *, void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" f32 lbl_805610C0;
extern "C" f32 lbl_805610C4;
extern "C" const char lbl_80326768[];
extern "C" const char lbl_803269A0[];
