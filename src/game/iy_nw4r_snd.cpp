#include <types.h>
#include <math.h>
#include <string.h>

/* Review carves for the REXE01 nw4hbm::snd cluster
 * (auto_03_800E252C_text / auto_03_800E9C38_text):
 *
 *   Pause__Q46nw4hbm3snd6detail7AxVoiceFb
 *   GetCurrentPlayingDspAddress__Q46nw4hbm3snd6detail7AxVoiceCFv
 *   SetBaseAddress__Q46nw4hbm3snd6detail7AxVoiceFiPCv
 *   SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf (x2)
 *   __dt__Q46nw4hbm3snd6detail14ChannelManagerFv
 *   Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal
 *   Release__Q46nw4hbm3snd6detail7ChannelFv
 *
 * Review-only; not configured.
 */

extern "C" u32 OSDisableInterrupts(void);
extern "C" u32 OSGetAlarmUserData(void*);
extern "C" void OSRestoreInterrupts(u32 level);
extern "C" void fn_80128668(void*);

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char* file, int line,
                                              const char* fmt, ...);
extern "C" void Insert_nw4hbm2(void*, void*, void*);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, u32);

#pragma push
#pragma small_data off
extern u8 lbl_80322790[];
extern u8 lbl_80322830[];
#pragma pop

/* ------------------------------------------------------------------ */
/* AxVoice::Pause(bool)                                               */
/* ------------------------------------------------------------------ */
extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void* this_, u32 flag) {
    u32 level;

    level = OSDisableInterrupts();

    if (((u8*)this_)[0x11F] != flag) {
        ((u8*)this_)[0x11F] = flag;
        ((u8*)this_)[0x123] |= 0x02;
    }

    OSRestoreInterrupts(level);
}

/* ------------------------------------------------------------------ */
/* AxVoice::GetCurrentPlayingDspAddress() const                        */
/* ------------------------------------------------------------------ */
extern "C" void* GetCurrentPlayingDspAddress__Q46nw4hbm3snd6detail7AxVoiceCFv(
    void* this_) {
    u32 level;
    void* pPb;
    u32 addr;

    level = OSDisableInterrupts();

    pPb = ((void**)this_)[0x0C / 4];
    if (pPb == NULL) {
        OSRestoreInterrupts(level);
        return NULL;
    }

    /* AXPB at +0x138, dspAddr hi/lo halfwords at +0x84/+0x86 */
    addr = (u32)(*(u16*)&((u8*)pPb)[0x84]) << 16 |
           (u32)*(u16*)&((u8*)pPb)[0x86];

    OSRestoreInterrupts(level);
    return (void*)addr;
}

/* ------------------------------------------------------------------ */
/* AxVoice::SetBaseAddress(int, const void*)                           */
/* ------------------------------------------------------------------ */
extern "C" void SetBaseAddress__Q46nw4hbm3snd6detail7AxVoiceFiPCv(
    void* this_, s32 idx, void* pBase) {
    u32 level;

    level = OSDisableInterrupts();
    *(void**)&((u8*)this_)[idx * 0x34 + 0x2C] = pBase;
    OSRestoreInterrupts(level);
}

/* ------------------------------------------------------------------ */
/* BasicSound::SetInitialVolume(float) (x2 clones)                     */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern f32 lbl_80560FB0; // validate range 1.0f
#pragma pop

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf(
    void* this_, f32 vol) {
    if (vol > 1.0f) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322790, 0x216,
                                     (const char*)lbl_80322830);
    }

    *(f32*)&((u8*)this_)[0x8C] = vol;
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800E9AAC(
    void* this_, f32 vol) {
    if (vol > 1.0f) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322790, 0x216,
                                     (const char*)lbl_80322830);
    }

    *(f32*)&((u8*)this_)[0x8C] = vol;
}

/* ------------------------------------------------------------------ */
/* ChannelManager dtor                                                 */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q46nw4hbm3snd6detail14ChannelManagerFv(void* this_,
                                                              s32 flag) {
    if (this_) {
        if ((u8*)this_ + 0x0C != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(&((u8*)this_)[0x0C], 0);
        }

        if (this_ != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* Channel::Start(const WaveData&, s32)                                */
/* ------------------------------------------------------------------ */
extern "C" void fn_800EC8B4(void* this_);
extern "C" void fn_800EB41C(void* this_);
extern "C" void Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(
    void* this_, void* pWaveData);
extern "C" void fn_800E519C(void* this_);

extern "C" void Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(
    void* this_, void* pWaveData, s32 offset) {
    void* pAxVoice;

    ((s32*)this_)[0xD4 / 4] = offset;
    fn_800EC8B4(&((u8*)this_)[0x20]);
    fn_800EB41C(&((u8*)this_)[0x08]);

    ((s32*)this_)[0xAC / 4] = 0;

    pAxVoice = ((void**)this_)[0xE0 / 4];
    Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(
        pAxVoice, pWaveData);
    fn_800E519C(((void**)this_)[0xE0 / 4]);

    ((u8*)this_)[0x3A] = 1;
}

/* ------------------------------------------------------------------ */
/* Channel::Release()                                                  */
/* ------------------------------------------------------------------ */
extern "C" void SetPriority__Q46nw4hbm3snd6detail7AxVoiceFi(void* this_,
                                                            s32 prio);

extern "C" void Release__Q46nw4hbm3snd6detail7ChannelFv(void* this_) {
    void* pAxVoice;

    if (((s32*)this_)[0x08 / 4] != 3) {
        pAxVoice = ((void**)this_)[0xE0 / 4];
        if (pAxVoice != NULL) {
            SetPriority__Q46nw4hbm3snd6detail7AxVoiceFi(pAxVoice, 1);
        }

        ((s32*)this_)[0x08 / 4] = 3;
    }

    ((u8*)this_)[0x39] = 0;
}
/* ------------------------------------------------------------------ */
/* DisposeCallbackManager dtor (clone at 0x800EAF54)                   */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* DisposeCallbackManager::UnregisterDisposeCallback                   */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80322B74[];
extern u8 lbl_80322B50[];
#pragma pop

extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(
    void* list, void* node);

extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
    void* this_, void* pCallback) {
    u32 level;

    level = OSDisableInterrupts();

    if (pCallback == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B74, 0x233,
                                     (const char*)lbl_80322B50);
    }

    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(
        this_, pCallback);

    OSRestoreInterrupts(level);
}

/* ------------------------------------------------------------------ */
/* EnvGenerator::SetSustain(int)                                       */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80322B80[];
extern u8 lbl_80322C90[];
#pragma pop

extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi(void* this_,
                                                               s32 sustain) {
    s32 ok;

    ok = (0 <= sustain && sustain <= 0x7F) ? 1 : 0;

    if (!ok) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B80, 0x116,
                                     (const char*)lbl_80322C90, sustain);
    }

    ((s32*)this_)[0x04 / 4] = sustain;
}

/* ------------------------------------------------------------------ */
/* ExternalSoundPlayer::InsertSoundList / RemoveSoundList              */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80322D24[];
extern u8 lbl_80322D00[];
#pragma pop

extern "C" void InsertSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(
    void* this_, void* pSound) {
    u8* list = (u8*)this_ + 0x04;
    u32 iter = (u32)&((u8*)this_)[0x04];

    if (pSound == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322D24, 0x233,
                                     (const char*)lbl_80322D00);
    }

    Insert_nw4hbm2(this_, &iter, &((u8*)pSound)[0x10]);
}

extern "C" void RemoveSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(
    void* this_, void* pSound) {
    u32 notInList;

    if (pSound == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322D24, 0x233,
                                     (const char*)lbl_80322D00);
    }

    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(
        this_, &((u8*)pSound)[0xD0]);

    ((s32*)pSound)[0x14 / 4] = 0;
}

/* ------------------------------------------------------------------ */
/* nw4r::snd::detail::PoolImpl::AllocImpl()                            */
/* ------------------------------------------------------------------ */
extern "C" void* AllocImpl__Q44nw4r3snd6detail8PoolImplFv(void* this_) {
    u32 level;
    void* pNode;
    void* pNext;

    level = OSDisableInterrupts();

    pNode = ((void**)this_)[0x00 / 4];
    if (pNode == NULL) {
        OSRestoreInterrupts(level);
        return NULL;
    }

    pNext = *(void**)pNode;
    ((void**)this_)[0x00 / 4] = pNext;

    OSRestoreInterrupts(level);

    return pNode;
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor (clone at 0x800ECB38)                       */
/* ------------------------------------------------------------------ */
extern "C" void fn_800F26FC(void* this_, u32 a);

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800ECB38(
    void* this_, s32 flag) {
    if (this_) {
        fn_800F26FC(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive::OpenStream(void*, int, u32, u32) const          */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_803231D8[]; // MemoryFileStream vtable
#pragma pop

extern "C" void* OpenStream__Q34nw4r3snd18MemorySoundArchiveCFPviUlUl(
    void* this_, void* pStream, s32 a, u32 offset, u32 size) {
    u32 base;

    base = *(u32*)&((u8*)this_)[0x108];
    if (base == 0) {
        return NULL;
    }

    if (offset >= 0x20 && pStream != NULL) {
        ((u8*)pStream)[0x04] = 0;
        ((s32*)pStream)[0x0C / 4] = 0;
        ((s32*)pStream)[0x10 / 4] = 0;
        *(u32*)&((u8*)pStream)[0x00] = (u32)&lbl_803231D8;
        ((s32*)pStream)[0x14 / 4] = offset + base;
        ((s32*)pStream)[0x18 / 4] = size;
        ((s32*)pStream)[0x1C / 4] = 0;
        return pStream;
    }

    return NULL;
}

/* ------------------------------------------------------------------ */
/* MemoryFileStream::Read(void*, u32)                                  */
/* ------------------------------------------------------------------ */
extern "C" void* Read__Q44nw4r3snd18MemorySoundArchive16MemoryFileStreamFPvUl(
    void* this_, void* pDst, u32 size) {
    u32 cur = *(u32*)&((u8*)this_)[0x1C];
    u32 len = *(u32*)&((u8*)this_)[0x18];
    u32 base = *(u32*)&((u8*)this_)[0x14];
    u32 n;

    n = (size <= (len - cur)) ? size : (len - cur);

    memcpy(pDst, (void*)(base + cur), n);

    return (void*)n;
}

/* ------------------------------------------------------------------ */
/* MmlSeqTrack ctor                                                    */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80323258[]; // MmlSeqTrack vtable
extern u8 lbl_80323760[]; // SeqTrack vtable
#pragma pop

extern "C" void fn_800EC890(void* this_);
extern "C" void InitParam__Q46nw4hbm3snd6detail8SeqTrackFv(void* this_);

extern "C" void* __ct__Q46nw4hbm3snd6detail11MmlSeqTrackFv(void* this_) {
    *(u32*)&((u8*)this_)[0x00] = (u32)&lbl_80323258;
    fn_800EC890(&((u8*)this_)[0x68]);

    ((u32*)this_)[0xB4 / 4] = 0;

    InitParam__Q46nw4hbm3snd6detail8SeqTrackFv(this_);

    ((u32*)this_)[0x00 / 4] = (u32)&lbl_80323760;
    ((u8*)this_)[0xC1] = 1;
    ((u8*)this_)[0xC2] = 0;
    ((u8*)this_)[0xC0] = 1;
    ((u8*)this_)[0xC6] = 0;

    return this_;
}

/* ------------------------------------------------------------------ */
/* MmlSeqTrackAllocator::AllocTrack(SeqPlayer*)                        */
/* ------------------------------------------------------------------ */
extern "C" void* AllocTrack__Q46nw4hbm3snd6detail20MmlSeqTrackAllocatorFPQ46nw4hbm3snd6detail9SeqPlayer(
    void* this_, void* pPlayer) {
    void* pTrack;

    pTrack = AllocImpl__Q44nw4r3snd6detail8PoolImplFv(&((u8*)this_)[0x08]);

    if (pTrack != NULL) {
        __ct__Q46nw4hbm3snd6detail11MmlSeqTrackFv(pTrack);
    }

    if (pTrack != NULL) {
        ((u32*)pTrack)[0xB4 / 4] = (u32)pPlayer;
        ((u32*)pTrack)[0xBC / 4] = *(u32*)&((u8*)this_)[0x04];
    }

    return pTrack;
}

/* ------------------------------------------------------------------ */
/* RemoteSpeaker::IntervalAlarmHandler(OSAlarm*, OSContext*)           */
/* ------------------------------------------------------------------ */
extern "C" void OSCancelAlarm(void* alarm);

extern "C" void IntervalAlarmHandler__Q34nw4r3snd13RemoteSpeakerFP7OSAlarmP9OSContext(
    void* alarm, void* ctx) {
    void* self;
    u32 level;

    level = OSDisableInterrupts();
    self = (void*)OSGetAlarmUserData(alarm);

    if (((u8*)self)[0x08]) {
        OSCancelAlarm(&((u8*)self)[0x38]);
        ((u8*)self)[0x06] = 0;
        ((u8*)self)[0x07] = 0;
        ((u8*)self)[0x08] = 0;
    }

    OSRestoreInterrupts(level);
    (void)ctx;
}

/* ------------------------------------------------------------------ */
/* SeqFileReader::GetBaseAddress() const                               */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_803239C0[];
extern u8 lbl_80323AF8[];
#pragma pop

extern "C" void* GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(
    void* this_) {
    void* pFile;

    if (*(u32*)&((u8*)this_)[0x00] == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803239C0, 0x5E,
                                     (const char*)lbl_80323AF8);
    }

    pFile = *(void**)&((u8*)this_)[0x04];

    return *(void**)&((u8*)pFile)[0x08];
}

/* ------------------------------------------------------------------ */
/* SeqPlayer::SetVolume(float)                                         */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80323B28[];
extern u8 lbl_80323BEC[];
extern f32 lbl_8056106C;
#pragma pop

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf(void* this_,
                                                            f32 vol) {
    if (vol > 1.0f) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x15D,
                                     (const char*)lbl_80323BEC);
    }

    {
        u32 level = OSDisableInterrupts();
        *(f32*)&((u8*)this_)[0x1C] = vol;
        OSRestoreInterrupts(level);
    }
}

/* ------------------------------------------------------------------ */
/* SeqPlayer::SetVolume clone (0x800EF804)                             */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80323C14[];
#pragma pop

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800EF804(
    void* this_, f32 vol) {
    if (vol > 1.0f) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x164,
                                     (const char*)lbl_80323C14);
    }

    {
        u32 level = OSDisableInterrupts();
        *(f32*)&((u8*)this_)[0x1C] = vol;
        OSRestoreInterrupts(level);
    }
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clone (0x800F078C)                          */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F078C(
    void* this_, s32 flag) {
    if (this_) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* SeqSound::Prepare(const void*, s32)                                 */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80324060[];
extern u8 lbl_803240D4[];
#pragma pop

extern "C" void SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl(void*, const void*, s32);
extern "C" void Prepare__Q46nw4hbm3snd6detail8SeqSoundFPCvl(void* this_,
                                                            const void* pSeq,
                                                            s32 offset) {
    if (pSeq == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324060, 0x70,
                                     (const char*)lbl_803240D4);
    }

    SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl(&((u8*)this_)[0xD8], pSeq, offset);
}

/* ------------------------------------------------------------------ */
/* shdStateMachine dtor (Shockwave lib)                                */
/* ------------------------------------------------------------------ */
extern "C" void __dt__Q46nw4hbm3snd6detail9SeqPlayerFv(void*, s32);

extern "C" void* __dt__15shdStateMachineFv(void* this_, s32 flag) {
    if (this_) {
        __dt__Q46nw4hbm3snd6detail9SeqPlayerFv(&((u8*)this_)[0xD8], -1);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* EnvGenerator::SetSustain clone (0x800F0E9C) — range 0..0x10         */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80324390[];
#pragma pop

extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi_800F0E9C(
    void* this_, s32 sustain) {
    s32 ok;

    ok = (0 <= sustain && sustain <= 0x10) ? 1 : 0;

    if (!ok) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324390, 0x25,
                                     (const char*)lbl_80322C90, sustain);
    }

    ((s32*)this_)[0x04 / 4] = sustain;
}

/* ------------------------------------------------------------------ */
/* SeqTrack::Close()                                                   */
/* ------------------------------------------------------------------ */
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(
    void* this_, s32);
extern "C" void fn_800EAD00(void* pChannel);

extern "C" void Close__Q46nw4hbm3snd6detail8SeqTrackFv(void* this_) {
    void* pCh;
    u32 level;

    ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(this_, -1);
    level = OSDisableInterrupts();

    pCh = *(void**)&((u8*)this_)[0xB8];
    while (pCh != NULL) {
        void* pNext = *(void**)&((u8*)pCh)[0xE4];
        fn_800EAD00(pCh);
        pCh = pNext;
    }

    OSRestoreInterrupts(level);
}

/* ------------------------------------------------------------------ */
/* SeqTrack::UpdateChannelLength()                                     */
/* ------------------------------------------------------------------ */
extern "C" void UpdateChannelLength__Q46nw4hbm3snd6detail8SeqTrackFv(
    void* this_) {
    void* pCh;

    pCh = *(void**)&((u8*)this_)[0xB8];
    while (pCh != NULL) {
        s32 len = *(s32*)&((u8*)pCh)[0xD4];

        if (len > 0) {
            len--;
            *(s32*)&((u8*)pCh)[0xD4] = len;
            if (len == 0) {
                Release__Q46nw4hbm3snd6detail7ChannelFv(pCh);
            }
        }

        pCh = *(void**)&((u8*)pCh)[0xE4];
    }
}

/* ------------------------------------------------------------------ */
/* SeqPlayer::UpdateAllPlayers() — static global player list walk      */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80412A6C[]; // player list head
extern u8 lbl_80324024[];
extern u8 lbl_80324000[];
#pragma pop

extern "C" void Update__Q46nw4hbm3snd6detail9SeqPlayerFv(void*);
extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv(void) {
    void* pHead = *(void**)&lbl_80412A6C[0x04];
    void* pList = &lbl_80412A6C[0x04];
    void* pPlayer;

    while (pHead != NULL) {
        pPlayer = pHead;
        pHead = *(void**)pHead;

        if (pPlayer == NULL) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324024, 0x233,
                                         (const char*)lbl_80324000);
        }

        Update__Q46nw4hbm3snd6detail9SeqPlayerFv(&((u8*)pPlayer)[0x04]);
        (void)pList;
    }
}

/* ------------------------------------------------------------------ */
/* SeqTrack::FreeAllChannel()                                          */
/* ------------------------------------------------------------------ */
extern "C" void FreeAllChannel__Q46nw4hbm3snd6detail8SeqTrackFv(void* this_) {
    void* pCh;
    u32 level;

    level = OSDisableInterrupts();

    pCh = *(void**)&((u8*)this_)[0xB8];
    while (pCh != NULL) {
        void* pNext = *(void**)&((u8*)pCh)[0xE4];
        fn_800EAD00(pCh);
        pCh = pNext;
    }

    *(void**)&((u8*)this_)[0xB8] = NULL;

    OSRestoreInterrupts(level);
}

/* ------------------------------------------------------------------ */
/* SeqPlayer::SetVolume clone (0x800F1E90)                             */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_803244D4[];
#pragma pop

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800F1E90(
    void* this_, f32 vol) {
    if (vol > 1.0f) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324390, 0x165,
                                     (const char*)lbl_803244D4);
    }

    {
        u32 level = OSDisableInterrupts();
        *(f32*)&((u8*)this_)[0x1C] = vol;
        OSRestoreInterrupts(level);
    }
}

/* ------------------------------------------------------------------ */
/* SoundPlayer::detail_SetPlayableSoundLimit(int) clone                */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_803247E0[];
extern u8 lbl_803247F8[];
extern u8 lbl_80324CDC[];
extern u8 lbl_805598A8[];
extern u8 lbl_805598A0[];
extern u8 lbl_80324CB0[];
#pragma pop

extern "C" void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi_800F2750(
    void* this_, s32 limit) {
    if (limit == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803247E0, 0x46,
                                     (const char*)lbl_803247F8);
    }

    ((s32*)this_)[0x04 / 4] = limit;
}

/* ------------------------------------------------------------------ */
/* SoundArchiveFileReader: GetPlayerCount / GetGroupCount              */
/* ------------------------------------------------------------------ */
extern "C" void* GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
    u32 type, u32 arg, void* pBase);

extern "C" u32 GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(
    void* this_) {
    void* pData;
    void* p;

    pData = *(void**)&((u8*)this_)[0x28];
    if (((u8*)pData)[0x11] != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_805598A8, 0x6F,
                                     (const char*)lbl_80324CDC);
    }

    p = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        ((u8*)pData)[0x10], *(u32*)&((u8*)pData)[0x14], pData);

    if (p == NULL) {
        return 0;
    }

    return *(u32*)p;
}

#pragma push
#pragma small_data off
extern u8 lbl_80324CB0[];
#pragma pop

extern "C" u32 GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(
    void* this_) {
    void* pData;
    void* p;

    pData = *(void**)&((u8*)this_)[0x28];
    if (((u8*)pData)[0x21] != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_805598A0, 0x6F,
                                     (const char*)lbl_80324CB0);
    }

    p = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
        ((u8*)pData)[0x20], *(u32*)&((u8*)pData)[0x24], pData);

    if (p == NULL) {
        return 0;
    }

    return *(u32*)p - 1;
}
