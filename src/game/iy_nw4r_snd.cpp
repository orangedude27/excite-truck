#include <types.h>
#include <math.h>

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
