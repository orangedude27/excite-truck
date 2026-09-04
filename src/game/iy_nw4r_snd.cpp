#include <types.h>
#include <math.h>
#include <string.h>

/* auto-generated missing externs for batch dtors */
extern u8 lbl_8032E448[];
extern u8 lbl_8032E46C[];
extern u8 lbl_80333728[];
extern u8 lbl_8033EFF4[];
extern u8 lbl_8034109C[];
extern u8 lbl_803410D8[];
extern u8 lbl_80341448[];
extern u8 lbl_80343780[];
extern u8 lbl_803453B8[];
extern u8 lbl_80345718[];
extern u8 lbl_80349AB0[];
extern u8 lbl_80349AD8[];
extern u8 lbl_80349B00[];
extern u8 lbl_80349B28[];
extern "C" void fn_801E323C(void* this_, u32 a);
extern "C" void fn_801E4A2C(void* this_, u32 a);
extern "C" void fn_801E7888(void* this_, u32 a);
extern "C" void fn_80235380(void* this_, u32 a);
extern "C" void fn_8028E398(void* this_, u32 a);
extern "C" void fn_802C6CF8(void* this_, u32 a);
extern "C" void fn_802C9D88(void* this_);


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
/* EnvGenerator::SetSustain clone (0x800F0E9C) â€” range 0..0x10         */
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
/* SeqPlayer::UpdateAllPlayers() â€” static global player list walk      */
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
    s32 type, u32 arg, void* pBase);

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

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clones (0x800F4F24 / 4F9C / 5014)           */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F24(
    void* this_, s32 flag) {
    if (this_) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F9C(
    void* this_, s32 flag) {
    if (this_) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F5014(
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
/* SoundArchivePlayer::GetRequiredStrmBufferSize(SoundArchive const&)  */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80324E88[];
extern u8 lbl_80324EA4[];
#pragma pop
extern "C" s32 fn_800F2814(void* pArchive, void* pOut);

extern "C" s32 GetRequiredStrmBufferSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(
    void* this_, void* pArchive) {
    s32 numStrm = 0;
    s32 out[4];

    if (pArchive == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324E88, 0x119,
                                     (const char*)lbl_80324EA4);
    }

    if (fn_800F2814(pArchive, out) != 0) {
        numStrm = out[0x18 / 4];
    }

    return numStrm * 0xFFFFA000;
}

/* ------------------------------------------------------------------ */
/* SoundArchivePlayer::GetSoundPlayer(u32)                             */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_803250C8[];
#pragma pop

extern "C" void* GetSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFUl(
    void* this_, u32 idx) {
    if (idx >= *(u32*)&((u8*)this_)[0x70]) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324E88, 0x2B2,
                                     (const char*)lbl_803250C8, idx,
                                     0);
    }

    return (void*)((u8*)this_ + 0x74 + idx * 0x48);
}

/* ------------------------------------------------------------------ */
/* SoundArchivePlayer::InvalidateData(const void*, const void*)        */
/* ------------------------------------------------------------------ */
extern "C" void InvalidateData__Q34nw4r3snd18SoundArchivePlayerFPCvPCv(
    void* this_, void* pStart, void* pEnd) {
    u32 i;
    u8* pArr;
    u8* pBase;

    if (*(u32*)&((u8*)this_)[0x14] == 0) {
        return;
    }

    pArr = *(u8**)&((u8*)this_)[0x14];

    for (i = 0; i < *(u32*)pArr; i++) {
        pBase = pArr + 0;
        pBase += i * 8;

        if ((void*)pBase[4] >= pStart && (void*)pBase[4] <= pEnd) {
            *(u32*)&pBase[4] = 0;   /* clear cached offset */
        }
    }
}

/* ------------------------------------------------------------------ */
/* SoundArchivePlayer::InvalidateData clone (0x800F6F18) â€” clears +0x8 */
/* ------------------------------------------------------------------ */
extern "C" void InvalidateData__Q34nw4r3snd18SoundArchivePlayerFPCvPCv_800F6F18(
    void* this_, void* pStart, void* pEnd) {
    u32 i;
    u8* pArr;

    if (*(u32*)&((u8*)this_)[0x14] == 0) {
        return;
    }

    pArr = *(u8**)&((u8*)this_)[0x14];

    for (i = 0; i < *(u32*)pArr; i++) {
        u8* pBase = pArr + i * 8;

        if (*(void**)&pBase[4] >= pStart && *(void**)&pBase[4] <= pEnd) {
            *(u32*)&pBase[4] = 0;   /* clear cached offset */
        }
    }
}

/* ------------------------------------------------------------------ */
/* SoundArchivePlayer::SeqLoadTask::Cancel()                           */
/* ------------------------------------------------------------------ */
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void*);

extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer11SeqLoadTaskFv(
    void* this_) {
    void* mutex = *(void**)&((u8*)this_)[0x2C];
    void* pLoader;

    OSLockMutex(mutex);

    pLoader = *(void**)&((u8*)this_)[0x10];
    if (pLoader != NULL) {
        Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(pLoader);
    }

    OSUnlockMutex(mutex);
}

/* ------------------------------------------------------------------ */
/* SoundArchivePlayer::detail_ConvertLabelStringToSoundId(const char*) */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80325BE8[];
extern u8 lbl_80325BB8[];
#pragma pop
extern "C" u32 fn_800F27D4(void* pLoader, const char* label);

extern "C" u32 detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(
    void* this_, const char* label) {
    if (*(u32*)&((u8*)this_)[0x10] == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325BE8, 0x163,
                                     (const char*)lbl_80325BB8);
    }

    return fn_800F27D4(*(void**)&((u8*)this_)[0x10], label);
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clone (0x800F8114) â€” SoundHeap base          */
/* ------------------------------------------------------------------ */

extern "C" void* __dt__Q36nw4hbm3snd9SoundHeapFv(void*, s32);

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8114(
    void* this_, s32 flag) {
    if (this_) {
        __dt__Q36nw4hbm3snd9SoundHeapFv(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

/* ------------------------------------------------------------------ */
/* SoundHandle::detail_AttachSound(BasicSound*)                        */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80325C00[];
extern u8 lbl_80325C18[];
#pragma pop
extern "C" u32 fn_800E9B88(void* pSound);
extern "C" u32 fn_800E9B9C(void* pSound);

extern "C" void detail_AttachSound__Q36nw4hbm3snd11SoundHandleFPQ46nw4hbm3snd6detail10BasicSound(
    void* this_, void* pSound) {
    if (pSound == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325C00, 0x55,
                                     (const char*)lbl_80325C18);
    }

    *(void**)&((u8*)this_)[0x00] = pSound;

    if (fn_800E9B88(pSound)) {
        fn_800E9B9C(*(void**)&((u8*)this_)[0x00]);
    }
}

/* ------------------------------------------------------------------ */
/* SoundHandle::DetachSound()                                          */
/* ------------------------------------------------------------------ */
extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void* this_) {
    void* pSound = *(void**)&((u8*)this_)[0x00];

    if (pSound != NULL) {
        if (*(void**)&((u8*)pSound)[0x08] == this_) {
            *(void**)&((u8*)pSound)[0x08] = NULL;
        }

        if (*(void**)&((u8*)pSound)[0x0C] == this_) {
            *(void**)&((u8*)pSound)[0x0C] = NULL;
        }
    }

    if (*(void**)&((u8*)this_)[0x00] != NULL) {
        *(void**)&((u8*)this_)[0x00] = NULL;
    }
}

/* ------------------------------------------------------------------ */
/* SoundHeap dtor                                                      */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80325C40[]; // SoundHeap vtable
#pragma pop
extern "C" void Destroy__Q46nw4hbm3snd6detail9FrameHeapFv(void*);
extern "C" void __dt__Q46nw4hbm3snd6detail9FrameHeapFv(void*, s32);

extern "C" void* __dt__Q36nw4hbm3snd9SoundHeapFv(void* this_, s32 flag) {
    if (this_) {
        *(u32*)&((u8*)this_)[0x00] = (u32)&lbl_80325C40;
        Destroy__Q46nw4hbm3snd6detail9FrameHeapFv(&((u8*)this_)[0x1C]);
        __dt__Q46nw4hbm3snd6detail9FrameHeapFv(&((u8*)this_)[0x1C], -1);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* SoundHeap::DisposeCallbackFunc(void*, u32, void*)                   */
/* ------------------------------------------------------------------ */
extern "C" void Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(
    void* this_, void*, u32, void*);
extern "C" void DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(
    void* this_, void*, u32, void*);

extern "C" void DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv(
    void* this_, void* arg0, u32 arg1, void* arg2) {
    Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(this_, arg0,
                                                                 arg1, arg2);
    DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(
        this_, arg0, arg1, arg2);
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clone (0x800F8540)                          */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8540(
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
/* BasicSound::SetInitialVolume clone (0x800F877C) â€” +0x28 store       */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80325C50[];
extern u8 lbl_80325C64[];
extern f32 lbl_805610BC;
#pragma pop

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800F877C(
    void* this_, f32 vol) {
    if (vol > 1.0f) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325C50, 0x99,
                                     (const char*)lbl_80325C64);
    }

    *(f32*)&((u8*)this_)[0x28] = vol;
}

/* ------------------------------------------------------------------ */
/* SoundPlayer::detail_RemoveSoundList clone (0x800F8880)              */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_803262B8[];
extern u8 lbl_80326294[];
#pragma pop

extern "C" void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(
    void* this_, void* pSound) {
    if (pSound == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803262B8, 0x233,
                                     (const char*)lbl_80326294);
    }

    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(
        this_, &((u8*)pSound)[0xC0]);

    *(u32*)&((u8*)pSound)[0x10] = 0;
}

/* ------------------------------------------------------------------ */
/* SoundPlayer::detail_RemovePriorityList                              */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80326288[];
extern u8 lbl_80326264[];
#pragma pop

extern "C" void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(
    void* this_, void* pSound) {
    if (pSound == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326288, 0x233,
                                     (const char*)lbl_80326264);
    }

    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(
        &((u8*)this_)[0x0C], &((u8*)pSound)[0xC8]);
}

/* ------------------------------------------------------------------ */
/* SoundPlayer::detail_SetPlayableSoundLimit(int)                      */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80325D48[];
#pragma pop

extern "C" void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi(
    void* this_, s32 limit) {
    if (limit < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325C50, 0x227,
                                     (const char*)lbl_80325D48);
    }

    *(u16*)&((u8*)this_)[0x26] = (u16)limit;
}

/* ------------------------------------------------------------------ */
/* SoundStartable::detail_StartSound(handle,id,ambient,player,info)    */
/* ------------------------------------------------------------------ */
extern "C" void detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
    void* this_, void* pHandle, u32 id, void* pAmbient, void* pPlayer,
    void* pInfo) {
    void* pSound;
    void* (*fn)(void*, void*, u32, void*, void*, void*);

    fn = *(void* (**)(void*, void*, u32, void*, void*, void*))(*(u32*)this_ +
                                                                0x0C);
    pSound = fn(this_, pHandle, id, pAmbient, pPlayer, pInfo);

    if (pSound != NULL && *(void**)&((u8*)pSound)[0x00] == NULL) {
        /* secondary attach */
        void (*cb)(void*) = *(void (**)(void*))(*(u32*)pHandle + 0x14);
        cb(pHandle);
    }
}

/* ------------------------------------------------------------------ */
/* SoundThread::GetInstance()                                          */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80412CC8[]; // singleton storage
extern u8 lbl_80412CB8[];
#pragma pop
extern u8 lbl_8055DE68;   // init flag

extern "C" void* __dt__10TitleSceneFv(void*, s32);
extern "C" void fn_800FA4B0(void*);
extern "C" void __register_global_object2(void*, void*, void*);
extern "C" void* GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv(void) {
    if (lbl_8055DE68 == 0) {
        ((u32*)&lbl_80412CC8[0x2384])[0x01] = 0; /* head */
        fn_800FA4B0(&lbl_80412CC8[0x2388]);
        __register_global_object2(&lbl_80412CC8[0x2388], (void*)&__dt__10TitleSceneFv,
                                  (void*)&lbl_80412CB8);
        lbl_8055DE68 = 1;
    }

    return &lbl_80412CC8[0x2388];
}
/* ------------------------------------------------------------------ */
/* TitleScene dtor (SoundThread storage)                               */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__10TitleSceneFv(void* this_, s32 flag) {
    if (this_) {
        if ((u8*)this_ + 0x2384 != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(&((u8*)this_)[0x2384], 0);
        }
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

/* ------------------------------------------------------------------ */
/* StrmBufferPool::Free(void*)                                         */
/* ------------------------------------------------------------------ */
extern "C" void Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(void* this_,
                                                            void* pBuf) {
    u32 level;
    u32 idx;
    void* pBase;
    u32 stride;

    level = OSDisableInterrupts();

    pBase = *(void**)&((u8*)this_)[0x00];
    stride = *(u32*)&((u8*)this_)[0x08];

    idx = ((u32)((u8*)pBuf - (u8*)pBase)) / stride;

    ((u8*)this_)[0x14 + (idx >> 3)] &= ~(1u << (idx & 7));

    *(u32*)&((u8*)this_)[0x10] -= 1;

    OSRestoreInterrupts(level);
}

/* ------------------------------------------------------------------ */
/* StrmPlayer::UpdateBufferAllPlayers() â€” static player list           */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_8041506C[]; // player list head
extern u8 lbl_80326B8C[];
extern u8 lbl_80326B68[];
#pragma pop
extern "C" void UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(void* this_);

extern "C" void UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv(
    void) {
    void* pHead = *(void**)&lbl_8041506C[0x04];
    void* pList = &lbl_8041506C[0x04];
    void* p;

    while (pHead != pList) {
        p = pHead;
        pHead = *(void**)pHead;

        if (p == NULL) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326B8C, 0x23D,
                                         (const char*)lbl_80326B68);
        }

        UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(&((u8*)p)[0x08]);
    }
}

/* ------------------------------------------------------------------ */
/* SeqPlayer::UpdateAllPlayers clone (0x800FC490) â€” strm players list  */
/* ------------------------------------------------------------------ */
extern "C" void UpdateStrm__Q46nw4hbm3snd6detail10StrmPlayerFv(void*);

extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC490(
    void) {
    void* pHead = *(void**)&lbl_8041506C[0x04];
    void* pList = &lbl_8041506C[0x04];
    void* p;

    while (pHead != pList) {
        p = pHead;
        pHead = *(void**)pHead;

        if (p == NULL) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326B8C, 0x23D,
                                         (const char*)lbl_80326B68);
        }

        UpdateStrm__Q46nw4hbm3snd6detail10StrmPlayerFv(&((u8*)p)[0x08]);
    }
}

/* ------------------------------------------------------------------ */
/* StrmPlayer::LoadCommand::SetAdpcmLoopContext(int, u16*)             */
/* ------------------------------------------------------------------ */
extern "C" void SetAdpcmLoopContext__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFiPUs(
    void* this_, s32 n, u16* pUs) {
    u8* pLoad;
    u32 idx;
    u32 i;

    pLoad = *(u8**)&((u8*)this_)[0x04];
    if (((u8*)pLoad)[0x10] != 2) {
        return;
    }

    for (idx = 0; idx < n && idx < 2; idx++) {
        u32 base = *(u32*)&((u8*)this_)[0x04];
        *(u16*)&((u8*)base)[idx * 2 + 0x518] = *pUs++;
    }
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clone (0x800FD9C8)                          */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FD9C8(
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
/* TaskManager dtor â€” destructs 3 elements @0xC stride                 */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80326C28[];
#pragma pop
extern "C" void fn_800FDFF8(void*);
extern "C" void* __dt__Q46nw4hbm3snd6detail11TaskManagerFv(void* this_,
                                                         s32 flag) {
    void* pBase;

    if (this_) {
        pBase = this_;

        /* for each of 3 elements: clear back-pointer, then call dtor */
        fn_800FDFF8(pBase);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clone (0x800FDFA0)                          */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FDFA0(
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
/* snd::detail::Util clamp+table helpers                                */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern f32 lbl_805610C8; // 1.0
extern f32 lbl_805610CC; // 2.0
extern f32 lbl_805610D0; // 0.5
extern f32 lbl_805610D4; // 6.0
extern f32 lbl_805610D8; // -90.4
extern f32 lbl_805610DC; // 10.0
extern f32 lbl_805610E0; // -1.0
extern f32 lbl_805610E4; // 256.0
extern f32 lbl_805610E8; // 0.0
extern f32 lbl_802F5210[]; // volume dB table
extern f32 lbl_802F6124[]; // pan table
#pragma pop

extern "C" f32 CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(f32 volume) {
    f32 v;

    if (volume > lbl_805610D4) {
        v = lbl_805610D4;
    } else if (volume < lbl_805610D8) {
        v = lbl_805610D8;
    } else {
        v = volume;
    }

    return lbl_802F5210[(s32)(lbl_805610DC * v) + 0x388];
}

extern "C" f32 CalcPanRatio__Q46nw4hbm3snd6detail4UtilFf(f32 pan) {
    f32 v;

    if (pan > lbl_805610C8) {
        v = lbl_805610C8;
    } else if (pan < lbl_805610E0) {
        v = lbl_805610E0;
    } else {
        v = pan;
    }

    return lbl_802F6124[(s32)(lbl_805610D0 +
                             lbl_805610E4 * ((lbl_805610C8 + v) * lbl_805610D0))];
}

extern "C" f32 CalcSurroundPanRatio__Q46nw4hbm3snd6detail4UtilFf(f32 pan) {
    f32 v;

    if (pan > lbl_805610CC) {
        v = lbl_805610CC;
    } else if (pan < lbl_805610E8) {
        v = lbl_805610E8;
    } else {
        v = pan;
    }

    return lbl_802F6124[(s32)(lbl_805610D0 +
                             lbl_805610E4 * (v * lbl_805610D0))];
}

/* ------------------------------------------------------------------ */
/* CalcLpfFreq â€” LPF cutoff: 32000 * 10^(2*(clamp-1))                  */
/* ------------------------------------------------------------------ */
extern double __ieee754_pow(double, double);

#pragma push
#pragma small_data off
extern double lbl_805610F0; // 32000.0
extern double lbl_805610F8; // 2.0
extern double lbl_80561100; // 10.0
extern double lbl_80561108; // 1.0
#pragma pop

extern "C" f32 CalcLpfFreq__Q46nw4hbm3snd6detail4UtilFf(f32 value) {
    f32 v;
    double x;

    if (value > lbl_805610C8) {
        v = lbl_805610C8;
    } else if (value < lbl_805610E8) {
        v = lbl_805610E8;
    } else {
        v = value;
    }

    x = lbl_80561100 * ((double)v - lbl_80561108);

    return (f32)(lbl_805610F0 * __ieee754_pow(x, lbl_805610F8));
}

/* ------------------------------------------------------------------ */
/* Util::GetDataRefAddressImpl(RefType, u32, const void*)              */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80327010[];
extern u8 lbl_80327020[];
#pragma pop

extern "C" void* GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
    s32 type, u32 arg, void* pBase) {
    if (type == 1) {
        return (void*)(arg + (u32)pBase);
    }

    if (type == 0) {
        return (void*)arg;
    }

    Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80327010, 0x1F6,
                                 (const char*)lbl_80327020);
    return NULL;
}

/* ------------------------------------------------------------------ */
/* SeqPlayer::UpdateAllPlayers clone (0x800FF824)                      */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_8041D4AC[]; // player list head
extern u8 lbl_80327370[];
extern u8 lbl_8032734C[];
#pragma pop

extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FF824(
    void) {
    void* pHead = *(void**)&lbl_8041D4AC[0x04];
    void* pList = &lbl_8041D4AC[0x04];
    void* p;

    while (pHead != pList) {
        p = pHead;
        pHead = *(void**)pHead;

        if (p == NULL) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80327370, 0x23D,
                                         (const char*)lbl_8032734C);
        }

        Update__Q46nw4hbm3snd6detail9SeqPlayerFv(&((u8*)p)[0x08]);
    }
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clone (0x800FF9B8)                          */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FF9B8(
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
/* WsdPlayer ctor â€” vtable+0x98 sub-vtable, seq/heap storage           */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80327AF4[]; // WsdPlayer vtable
#pragma pop

extern "C" void* __ct__Q46nw4hbm3snd6detail9WsdPlayerFv(void* this_) {
    (void)this_;
    ((u32*)this_)[0x00 / 4] = (u32)&lbl_80327AF4;
    ((u32*)this_)[0x04 / 4] = (u32)-1;
    ((u32*)this_)[0x08 / 4] = 0;
    ((u32*)this_)[0x0C / 4] = 0;
    ((u32*)this_)[0x10 / 4] = (u32)(&lbl_80327AF4[0x98]);
    ((u32*)this_)[0x14 / 4] = 0;
    ((u32*)this_)[0x18 / 4] = 0;
    ((u8*)this_)[0x1D] = 0;
    fn_800EC890(&((u8*)this_)[0xA8]);
    ((u32*)this_)[0xC8 / 4] = 0;
    return this_;
}

/* ------------------------------------------------------------------ */
/* WsdPlayer::Pause(bool)                                              */
/* ------------------------------------------------------------------ */
extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(void*,
                                                                 u32);

extern "C" void Pause__Q46nw4hbm3snd6detail9WsdPlayerFb(void* this_,
                                                        u32 flag) {
    u32 level;

    level = OSDisableInterrupts();
    ((u8*)this_)[0x20] = flag;
    PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(&((u8*)this_)[0x9C],
                                                     flag);
    OSRestoreInterrupts(level);
}

/* ------------------------------------------------------------------ */
/* SeqPlayer::SetVolume clones (0x80100820 @+0x24, 0x80100894 @+0x3C)  */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern f32 lbl_80561124;   // 1.0
extern u8 lbl_80327930[];
extern u8 lbl_80327944[];
extern u8 lbl_8032796C[];
#pragma pop

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_80100820(
    void* this_, f32 vol) {
    if (vol > lbl_80561124) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80327930, 0xFA,
                                     (const char*)lbl_80327944);
    }

    {
        u32 level = OSDisableInterrupts();
        *(f32*)&((u8*)this_)[0x24] = vol;
        OSRestoreInterrupts(level);
    }
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_80100894(
    void* this_, f32 vol) {
    if (vol > lbl_80561124) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80327930, 0x101,
                                     (const char*)lbl_8032796C);
    }

    {
        u32 level = OSDisableInterrupts();
        *(f32*)&((u8*)this_)[0x3C] = vol;
        OSRestoreInterrupts(level);
    }
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clone (0x80101474)                          */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80101474(
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
/* WsdTrack::Close()                                                   */
/* ------------------------------------------------------------------ */
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(
    void* this_, s32);

extern "C" void Close__Q46nw4hbm3snd6detail8WsdTrackFv(void* this_) {
    void* pCh;
    u32 level;

    ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(this_, -1);

    pCh = *(void**)&((u8*)this_)[0x30];
    while (pCh != NULL) {
        void* pNext = *(void**)&((u8*)pCh)[0xE4];
        fn_800EAD00(pCh);
        pCh = pNext;
    }

    *(void**)&((u8*)this_)[0x30] = NULL;
}

/* ------------------------------------------------------------------ */
/* WsdTrack::PauseAllChannel(bool)                                     */
/* ------------------------------------------------------------------ */
extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void*, u32);

extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(
    void* this_, u32 flag) {
    void* pCh;

    pCh = *(void**)&((u8*)this_)[0x30];
    while (pCh != NULL) {
        if (((u8*)pCh)[0x3A] != 0 && flag != (((u8*)pCh)[0x39] != 0)) {
            ((u8*)pCh)[0x39] = flag;
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(void**)&((u8*)pCh)[0xE0],
                                                  flag);
        }

        pCh = *(void**)&((u8*)pCh)[0xE4];
    }
}

/* ------------------------------------------------------------------ */
/* nw4hbm::ut::IOStream virtual wrappers (Seek/Read families)          */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80328458[];
extern u8 lbl_8032846C[];
extern u8 lbl_80328490[];
extern u8 lbl_803285B8[];
extern u8 lbl_803285C8[];
extern u8 lbl_803285EC[];
extern u8 lbl_80328614[];
#pragma pop

/* vtable+0x50 Seek (0x8010718C) */
extern "C" u32 Seek__Q36nw4hbm2ut10FileStreamFlUl(void* this_, s32 off,
                                                  u32 origin) {
    u32 result = ((u32(*)(void*, s32, u32))((*(void***)this_)[0x50 / 4]))(
        this_, off, origin);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80328458, 0x2C,
                                     (const char*)lbl_8032846C);
    }
    return result;
}

/* vtable+0x54 Seek (0x801071DC) */
extern "C" u32 Seek__Q36nw4hbm2ut10FileStreamFlUl_801071DC(void* this_,
                                                           s32 off,
                                                           u32 origin) {
    u32 result = ((u32(*)(void*, s32, u32))((*(void***)this_)[0x54 / 4]))(
        this_, off, origin);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80328458, 0x3C,
                                     (const char*)lbl_80328490);
    }
    return result;
}

/* vtable+0x2C Read (0x80107494) */
extern "C" u32 Read__Q36nw4hbm2ut8IOStreamFPvUl(void* this_, void* buf,
                                                u32 size) {
    u32 result = ((u32(*)(void*, void*, u32))((*(void***)this_)[0x2C / 4]))(
        this_, buf, size);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803285B8, 0x29,
                                     (const char*)lbl_803285C8);
    }
    return result;
}

/* vtable+0x30 Seek (0x80107580) */
extern "C" u32 Seek__Q36nw4hbm2ut10FileStreamFlUl_80107580(void* this_,
                                                           s32 off,
                                                           u32 origin) {
    u32 result = ((u32(*)(void*, s32, u32))((*(void***)this_)[0x30 / 4]))(
        this_, off, origin);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803285B8, 0x52,
                                     (const char*)lbl_80328614);
    }
    return result;
}

/* vtable+0x28 Read (0x80107668) */
extern "C" u32 Read__Q36nw4hbm2ut8IOStreamFPvUl_80107668(void* this_,
                                                         void* buf,
                                                         u32 size) {
    u32 result = ((u32(*)(void*, void*, u32))((*(void***)this_)[0x28 / 4]))(
        this_, buf, size);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803285B8, 0x8E,
                                     (const char*)lbl_803285EC);
    }
    return result;
}

/* ------------------------------------------------------------------ */
/* nw4hbm::ut::List init/get-next                                      */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80328828[];
extern u8 lbl_80328834[];
#pragma pop

typedef struct utList {
    void* head;    // at 0x0
    void* tail;    // at 0x4
    u16 count;     // at 0x8
    u16 offset;    // at 0xA
} utList;

extern "C" void List_Init__Q26nw4hbm2utFPQ36nw4hbm2ut4ListUs(utList* list,
                                                              u16 offset) {
    if (list == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80328828, 0x29,
                                     (const char*)lbl_80328834);
    }

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    list->offset = offset;
}

extern "C" void* List_GetNext__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListPCv(
    const utList* list, const void* node) {
    if (list == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80328828, 0xF5,
                                     (const char*)lbl_80328834);
    }

    if (node == NULL) {
        return list->head;
    }

    return *(void**)((u8*)node + list->offset + 4);
}

/* ------------------------------------------------------------------ */
/* nw4hbm::ut::ResFont dtor                                            */
/* ------------------------------------------------------------------ */
extern "C" void fn_80109040(void* this_, u32 a);

extern "C" void* __dt__Q36nw4hbm2ut7ResFontFv(void* this_, s32 flag) {
    if (this_) {
        fn_80109040(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor clone (0x80111BB8)                          */
/* ------------------------------------------------------------------ */
extern "C" void fn_801033F0(void* this_, u32 a);

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80111BB8(
    void* this_, s32 flag) {
    if (this_) {
        fn_801033F0(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

/* ------------------------------------------------------------------ */
/* SeqHeap dtor (PSSystem::SeqHeap::~SeqHeap)                         */
/* Vtable-write pattern + sub-dtor on this_+4, then optional free.    */
/* ------------------------------------------------------------------ */
extern u8 lbl_8032E46C[0x74];  /* vtable (size 0x74 = 29 vtable slots) */
extern u8 lbl_8032E448[0x74];  /* vtable (variant) */
extern u8 lbl_80333728[0x74];  /* vtable (SeqHeap 801A3FB8) */
extern "C" void fn_80138AD8(void* this_, u32 a);
extern "C" void fn_801CFF14(void* this_);
extern "C" void fn_80179EE8(void* this_, u32 a);
extern "C" void fn_802066C8(void* this_, u32 a);
extern "C" void fn_80206C70(void* this_);
extern "C" void fn_801D1008(void* this_, u32 a);
extern "C" void fn_801EC9CC(void* this_, u32 a);
extern "C" void fn_8012A260(void* this_, u32 a);
extern "C" void fn_801CBD04(void* this_);
extern "C" void fn_801D0DFC(void* this_);
extern "C" void fn_80127E28(void* this_);
extern "C" void fn_8027AF94(void* this_);
extern "C" void fn_802916E4(void* this_);
extern "C" void fn_8021915C(void* this_, u32 a);
extern "C" void fn_802223C4(void* this_, u32 a);
extern "C" void fn_80128670(void* this_, u32 a);
extern "C" void fn_802CAC54(void* this_, u32 a);
extern "C" void fn_802C4C80(void* this_, u32 a);
extern "C" void fn_8022A8E4(void* this_);
extern "C" void fn_802328D4(void* this_, u32 a);
extern "C" void fn_802C519C(void* this_, u32 a);
extern "C" void* __dt__Q34Game10MemoryCard8ResourceFv(void* this_, s32 flag);  /* forward */
extern "C" void fn_80223208(void* this_, u32 a);
extern "C" void fn_80128668(void*);

/* ------------------------------------------------------------------ */
/* nw4r2ef::Effect dtors (vtable +0/+4, sub-dtor with no vtable arg) */
/* ------------------------------------------------------------------ */
extern u8 lbl_80338038[];  /* nw4r2ef::Effect vtable (size 0x70) */
extern u8 lbl_803381C0[];  /* nw4r2ef::Effect vtable (variant) */
extern u8 lbl_8032ACB0[];  /* nw4r2ef::Effect vtable (variant) */
extern u8 lbl_80347CF8[];  /* nw4r2ef::Effect vtable (variant) */
extern u8 lbl_803490D4[];  /* nw4r2ef::Effect vtable (variant) */

extern "C" void* __dt__Q34nw4r2ef6EffectFv_801CBCA4(void* this_, s32 flag) {
    if (this_) {
        *(u32*)((u8*)this_ + 4) = (u32)lbl_80338038;
        fn_801CBD04(this_);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q34nw4r2ef6EffectFv_801D0D7C(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_803381C0;
        fn_801D0DFC(this_);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q34nw4r2ef6EffectFv(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032ACB0;
        fn_80127E28(this_);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q34nw4r2ef6EffectFv_8027D434(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_80347CF8;
        fn_8027AF94(this_);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q34nw4r2ef6EffectFv_8028F5A8(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_803490D4;
        fn_802916E4(this_);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}
typedef void (*dtor1arg_t)(void*, u32);

extern "C" void deleteThreads__6SystemFv(void* this_) {
    void* thread = *(void**)this_;

    if (thread != NULL) {
        dtor1arg_t fn = ((dtor1arg_t*)(*(void***)thread))[2];
        fn(thread, 1);
        *(u32*)this_ = 0;
    }
}

extern "C" void deleteThreads__6SystemFv_80173A2C(void* this_) {
    void* thread = *(void**)this_;

    if (thread) {
        dtor1arg_t fn = ((dtor1arg_t*)(*(void***)thread))[2];
        fn(thread, 1);
        *(u32*)this_ = 0;
    }
}

/* ------------------------------------------------------------------ */
/* TBlackPlane::updateAfterCamera                                     */
/* Calls vtable[5] (0x14) on this->field_0x8 and this->field_0x4.   */
/* ------------------------------------------------------------------ */
typedef void (*vfn0_t)(void*);

extern "C" void updateAfterCamera__Q33ebi5title11TBlackPlaneFv(void* this_) {
    void* a = *(void**)((u8*)this_ + 0x8);
    void* b = *(void**)((u8*)this_ + 0x4);
    vfn0_t fn = ((vfn0_t*)(*(void***)a))[5];
    fn(a);
    fn = ((vfn0_t*)(*(void***)b))[5];
    fn(b);
}

/* ------------------------------------------------------------------ */
/* JStudio_JAudio::TAdaptor_sound::endSound_fadeOut                   */
/* if (this->field_0x248) { fn = vtable[0x24/4](this->field_0x248); this->field_0x248 = 0; } */
/* ------------------------------------------------------------------ */
extern "C" void endSound_fadeOut___Q214JStudio_JAudio14TAdaptor_soundFUl(
    void* this_, u32 arg) {
    void* target = *(void**)((u8*)this_ + 0x248);

    if (target) {
        vfn0_t fn = ((vfn0_t*)(*(void***)target))[9];
        fn(target);
        *(u32*)((u8*)this_ + 0x248) = 0;
    }
}

extern "C" void* __dt__Q28PSSystem7SeqHeapFv_80156A4C(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032E46C;
        fn_80138AD8((u8*)this_ + 4, (u32)lbl_8032E46C);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q28PSSystem7SeqHeapFv_80156AC4(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032E448;
        fn_80138AD8((u8*)this_ + 4, (u32)lbl_8032E448);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* SeqHeap 0x801A3FB8: sub-dtor takes this->field_0x24 (a vtable pointer)
 * rather than this+4; vtable at +0 is the new class's vtable. */
extern "C" void* __dt__Q28PSSystem7SeqHeapFv_801A3FB8(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_80333728;
        fn_801CFF14(*(void**)((u8*)this_ + 0x24));

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtors (no vtable write, r4=0 sub-dtor flag)    */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017831C(
    void* this_, s32 flag) {
    if (this_) {
        fn_80179EE8(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017B038(
    void* this_, s32 flag) {
    if (this_) {
        fn_80179EE8(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017DA34(
    void* this_, s32 flag) {
    if (this_) {
        fn_802066C8(this_, 0);

        if (flag > 0) {
            fn_80206C70(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801D130C(
    void* this_, s32 flag) {
    if (this_) {
        fn_801D1008(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801D1AB4(
    void* this_, s32 flag) {
    if (this_) {
        fn_801D1008(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801EEEEC(
    void* this_, s32 flag) {
    if (this_) {
        fn_801EC9CC(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802152F0(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80215348(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80219900(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802199D0(
    void* this_, s32 flag) {
    if (this_) {
        fn_802223C4(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021A650(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021AF9C(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021E884(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* DisposeCallbackManager dtors                                       */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801A973C(
    void* this_, s32 flag) {
    if (this_) {
        fn_80179EE8(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801AFD70(
    void* this_, s32 flag) {
    if (this_) {
        fn_80179EE8(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80207748(
    void* this_, s32 flag) {
    if (this_) {
        fn_802066C8(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8021B404(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* CollisionSpace dtors                                               */
/* vtable-write pattern: vtable at +0, then this->field_0x4 -> sub  */
/* ------------------------------------------------------------------ */
extern u8 lbl_80339288[];  /* CollisionSpace vtable */
extern u8 lbl_803392B0[];  /* CollisionSpace vtable (variant) */
extern u8 lbl_80343000[];  /* CollisionSpace vtable (variant) */
extern u8 lbl_80343040[];  /* CollisionSpace vtable (variant) */
extern u8 lbl_80343080[];  /* CollisionSpace vtable (variant) */
extern u8 lbl_8033EB14[];  /* Game::MemoryCard::Resource vtable (0x70) */
extern u8 lbl_8033E7F4[];  /* Game::MemoryCard::Resource vtable (variant) */
extern u8 lbl_8033EAC0[];  /* Game::MemoryCard::Resource vtable (variant) */
extern u8 lbl_8033EB50[];  /* Game::MemoryCard::Resource vtable (variant) */
extern u8 lbl_8033EB8C[];  /* Game::MemoryCard::Resource vtable (variant) */

extern "C" void* __dt__14CollisionSpaceFv_801DAB70(void* this_, s32 flag) {
    void* vtable;
    void* field_0x4;

    if (this_) {
        vtable = (void*)lbl_80339288;
        *(u32*)this_ = (u32)vtable;
        field_0x4 = *(void**)((u8*)this_ + 4);
        fn_80128670(field_0x4, (u32)vtable);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__14CollisionSpaceFv_801F2E24(void* this_, s32 flag) {
    void* vtable;
    void* field_0x4;

    if (this_) {
        vtable = (void*)lbl_803392B0;
        *(u32*)this_ = (u32)vtable;
        field_0x4 = *(void**)((u8*)this_ + 4);
        fn_802CAC54(field_0x4, (u32)vtable);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__14CollisionSpaceFv_802155B4(void* this_, s32 flag) {
    void* vtable;
    void* field_0x4;

    if (this_) {
        vtable = (void*)lbl_80343000;
        *(u32*)this_ = (u32)vtable;
        field_0x4 = *(void**)((u8*)this_ + 4);
        fn_802C4C80(field_0x4, (u32)vtable);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__14CollisionSpaceFv_80222584(void* this_, s32 flag) {
    void* vtable;
    void* field_0x4;

    if (this_) {
        vtable = (void*)lbl_80343040;
        *(u32*)this_ = (u32)vtable;
        field_0x4 = *(void**)((u8*)this_ + 4);
        fn_802328D4(field_0x4, (u32)vtable);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* Game::MemoryCard::Resource dtors (recursive self-dtor pattern)    */
/* vtable +0; field_0x2c4 -> sub; recursive __dt__(self, 0); free    */
/* ------------------------------------------------------------------ */
extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802266B0(
    void* this_, s32 flag) {
    if (this_) {
        fn_802223C4(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228F4C(
    void* this_, s32 flag) {
    if (this_) {
        fn_80223208(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228FA4(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228FFC(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802292D8(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80229330(
    void* this_, s32 flag) {
    if (this_) {
        fn_802223C4(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80229388(
    void* this_, s32 flag) {
    if (this_) {
        fn_802223C4(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802295AC(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q34Game10MemoryCard8ResourceFv(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_8033EB14;
        void* field_0x2c4;
        *(u32*)this_ = (u32)vtable;
        field_0x2c4 = *(void**)((u8*)this_ + 0x2c4);
        fn_8022A8E4(field_0x2c4);
        __dt__Q34Game10MemoryCard8ResourceFv(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q34Game10MemoryCard8ResourceFv_8022003C(void* this_, s32 flag) {
    if (this_) {
        void* vtable;
        void* field_0x254;
        vtable = (void*)lbl_8033E7F4;
        *(u32*)this_ = (u32)vtable;
        field_0x254 = *(void**)((u8*)this_ + 0x254);
        fn_802C519C(field_0x254, 0);
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q34Game10MemoryCard8ResourceFv_80222C8C(void* this_, s32 flag) {
    if (this_) {
        void* vtable;
        void* field_0x254;
        vtable = (void*)lbl_8033EAC0;
        *(u32*)this_ = (u32)vtable;
        field_0x254 = *(void**)((u8*)this_ + 0x254);
        fn_802328D4(field_0x254, 0);
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8022A0CC(
    void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229054(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802290B0(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022910C(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229168(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802291C4(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229220(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022927C(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802293E0(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022943C(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229498(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802294F4(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229550(void* this_, s32 flag) {
    if (this_) {
        fn_802223C4(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229D64(void* this_, s32 flag) {
    if (this_) {
        fn_8021915C(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__12PhysicsWorldFv_801E7730(void* this_, s32 flag) {
    if (this_) {
        fn_80128670(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__14CollisionSpaceFv_802A3370(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_80349B28;
        void* field_0x4;
        *(u32*)this_ = (u32)vtable;
        field_0x4 = *(void**)((u8*)this_ + 0x4);
        fn_8028E398(field_0x4, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__14CollisionSpaceFv_802A366C(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_80349B00;
        void* field_0x4;
        *(u32*)this_ = (u32)vtable;
        field_0x4 = *(void**)((u8*)this_ + 0x4);
        fn_8028E398(field_0x4, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__14CollisionSpaceFv_802A392C(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_80349AD8;
        void* field_0x4;
        *(u32*)this_ = (u32)vtable;
        field_0x4 = *(void**)((u8*)this_ + 0x4);
        fn_8028E398(field_0x4, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__14CollisionSpaceFv_802A3D98(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_80349AB0;
        void* field_0x4;
        *(u32*)this_ = (u32)vtable;
        field_0x4 = *(void**)((u8*)this_ + 0x4);
        fn_8028E398(field_0x4, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448(void* this_, s32 flag) {
    if (this_) {
        fn_801E323C(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q210JASDrumSet5TPercFv(void* this_, s32 flag) {
    if (this_) {
        fn_802CAC54(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(void* this_, s32 flag) {
    if (this_) {
        fn_80128670(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_802C9E3C(void* this_, s32 flag) {
    if (this_) {
        fn_801E7888(this_, 0);

        if (flag > 0) {
            fn_802C9D88(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q28PSSystem7SeqHeapFv_8023A774(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_8034109C;
        void* field_0x10;
        *(u32*)((u8*)this_ + 0xc) = (u32)vtable;
        field_0x10 = *(void**)((u8*)this_ + 0x10);
        fn_80128670(field_0x10, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q28PSSystem7SeqHeapFv_8023A7D8(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_803410D8;
        void* field_0x10;
        *(u32*)((u8*)this_ + 0xc) = (u32)vtable;
        field_0x10 = *(void**)((u8*)this_ + 0x10);
        fn_80128670(field_0x10, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q28PSSystem7SeqHeapFv_8023C79C(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_80341448;
        void* field_0x10;
        *(u32*)((u8*)this_ + 0xc) = (u32)vtable;
        field_0x10 = *(void**)((u8*)this_ + 0x10);
        fn_80128670(field_0x10, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q28PSSystem7SeqHeapFv_80246C48(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_80343780;
        void* field_0x18;
        *(u32*)this_ = (u32)vtable;
        field_0x18 = *(void**)((u8*)this_ + 0x18);
        fn_80235380(field_0x18, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q28PSSystem7SeqHeapFv_8025CC14(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_803453B8;
        void* field_0x28;
        *(u32*)this_ = (u32)vtable;
        field_0x28 = *(void**)((u8*)this_ + 0x28);
        fn_80235380(field_0x28, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q28PSSystem7SeqHeapFv_8025DA88(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_80345718;
        void* field_0x28;
        *(u32*)this_ = (u32)vtable;
        field_0x28 = *(void**)((u8*)this_ + 0x28);
        fn_80235380(field_0x28, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* __dt__Q34Game10MemoryCard8ResourceFv_80229B78(void* this_, s32 flag) {
    if (this_) {
        void* vtable = (void*)lbl_8033EFF4;
        void* field_0x348;
        *(u32*)this_ = (u32)vtable;
        field_0x348 = *(void**)((u8*)this_ + 0x348);
        fn_801E4A2C(field_0x348, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

extern "C" void* clear__Q211J2DBloSaver19CTextureNameConnectFv(void* this_, s32 flag) {
    if (this_) {
        fn_802C6CF8(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}
