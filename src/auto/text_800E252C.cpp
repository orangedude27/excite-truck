typedef int s32;
struct LLTmp { int a; void* next; void* prev; };
struct ElemTmp { float f1; float f2; int i1; int i2; };
extern float lbl_80560F20;
static inline void FillTmp(ElemTmp* end, ElemTmp* q, float f) { if (q < end) { do { q->f1 = f; q->f2 = f; q->i1 = 0; q->i2 = 0; q++; } while (q < end); } }
typedef unsigned int u32;
typedef signed char s8;
typedef int M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void TRKProcessInput(void *, unsigned int);
namespace nw4r { namespace snd { namespace detail {
class Voice {
public:
    void TransformDpl2Pan(float *, float *, float, float);
};
} } }

namespace nw4hbm { namespace snd { namespace detail {
struct NoteOnInfo {
    int unk_0;
    int unk_4;
    int unk_8;
    int unk_C;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
};
class Bank {
public:
    void *NoteOn(const NoteOnInfo &) const;
};
} } }

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" int ReadInstInfo__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8InstInfoiii(void *, void *, int, int, int);
extern "C" void *ReadWaveParam__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8WaveDataiPCv(void *, void *, int, const void *);
extern "C" void *AllocChannel__Q46nw4hbm3snd6detail7ChannelFiiiPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(int, int, int, int, int);
extern "C" void SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(void *, const void *, int);
extern float lbl_80560F88, lbl_80560F8C, lbl_80560F90;
extern double lbl_80560F98, lbl_80560FA0;
extern "C" int IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(void *);
extern "C" void fn_800E6A44(void *, int, int, void *);
extern "C" void fn_80033AAC(void *, void *);
extern "C" void fn_80033538(unsigned short);
extern "C" void *AIRegisterDMACallback(void *);
extern "C" void AXRegisterAuxACallback(int, int);
extern "C" void AXRegisterAuxBCallback(int, int);
extern "C" void AXRegisterAuxCCallback(int, int);
extern "C" void fn_800E4364(void *, int);
extern "C" void Stop__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void *, void **);
extern int lbl_8055DE20;
extern void fn_80128668(void);

extern "C" unsigned int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(unsigned int);
extern "C" void AXSetVoiceState(void *, unsigned int);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" int AIGetDMAStatus(void);
extern "C" void AXGetAuxACallback(void *, void *);
extern "C" void AXGetAuxBCallback(void *, void *);
extern "C" void AXGetAuxCCallback(void *, void *);
extern "C" void DCFlushRange(void *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void fn_800E41EC(void);
extern const char lbl_80321F94[];
extern const char lbl_80322130[], lbl_80322154[];
extern unsigned char lbl_80407E60[];
namespace nw4hbm { namespace ut {
class LinkListNode;
namespace detail {
typedef nw4hbm::ut::LinkListNode LinkListNode;
class LinkListImpl {
public:
    struct Iterator { LinkListNode *node; };
    void Insert(Iterator, LinkListNode *);
};
}
}}
extern const char lbl_80322094[];
extern const char lbl_80322070[];
extern const char lbl_80321F80[];
extern const char lbl_80321FAC[];
extern const char lbl_80322790[];
extern const char lbl_80322830[];
extern const char lbl_80322858[];
extern const char lbl_80322708[];
extern const char lbl_80322734[];
extern "C" unsigned int GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(unsigned char, unsigned int, const void *);
extern const char lbl_80559820[];
extern const char lbl_80559828[];
extern float lbl_80560F38;
extern float lbl_80560F3C;
extern float lbl_80560F40;
extern float lbl_80560F58;
extern float lbl_80560F50;
extern float lbl_80560F54;
extern float lbl_80560F7C;
extern float lbl_80560F80;
extern "C" float CalcPanRatio__Q46nw4hbm3snd6detail4UtilFf(float);
extern "C" float CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(float);
extern "C" float CalcSurroundPanRatio__Q46nw4hbm3snd6detail4UtilFf(float);
extern "C" void fn_800339B0(void *, short *);
extern "C" void fn_80033A34(void *, float);
extern const char lbl_803227EC[];
extern "C" void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern "C" void detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern const char lbl_803221A8[];
extern const char lbl_803222F0[];
extern const char lbl_80322438[];
extern const char lbl_80322010[];
extern const char lbl_80322034[];
extern "C" float lbl_80560FB4;
extern double lbl_80560FB8;
// BasicSound::Pause: this object's vtable has the player accessor at 0x5C; its vf6(int) is at 0x14.
class PauseVt {
public:
    virtual ~PauseVt();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int);     // vtable 0x14
    virtual void vf5();
    virtual void vf6(int);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual PauseVt *vf22();   // vtable 0x5C
};
struct PauseFields {
    PauseVt *vt;
    unsigned char pad0[0x50];
    float start;     // 0x54
    float end;       // 0x58
    int total;       // 0x5C
    int elapsed;     // 0x60
    unsigned char pad1[0x3];
    unsigned char paused;   // 0x67
    unsigned char fading;   // 0x68
};
#pragma always_inline on
static inline float PauseRamp(PauseFields *s) {
    int total = s->total;
    int elapsed = s->elapsed;
    if (elapsed >= total) {
        return s->end;
    }
    return s->start + (float)elapsed * (s->end - s->start) / (float)total;
}
static inline void PauseSetRamp(PauseFields *s, float end, int n) {
    s->start = PauseRamp(s);
    s->end = end;
    s->total = n;
    s->elapsed = 0;
}
#pragma always_inline reset
#pragma always_inline on
static inline void AxVoiceSetAllStates(char *self, unsigned int state) {
    char *row = self;
    int i;
    for (i = 0; i < *(int *)(self + 0x104); row += 0x10, i++) {
        char *col = row;
        int j;
        for (j = 0; j < *(int *)(self + 0x108); col += 4, j++) {
            if (*(void **)(col + 0xC) != 0) AXSetVoiceState(*(void **)(col + 0xC), state);
        }
    }
}
#pragma always_inline reset
// Vtable dispatcher class for indirect virtual calls (MWCC ABI: 2 leading dtor slots).
class VfObj {
public:
    virtual ~VfObj();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();   // vtable 0x60 = 10th named method (0x18 + 9*4)
    virtual void vf17();   // vtable 0x64
    virtual void vf18();   // vtable 0x68
    virtual void vf19();   // vtable 0x6C
    virtual void vf20();   // vtable 0x70
    virtual void vf21();   // vtable 0x74
    virtual void vf22();   // vtable 0x78
    virtual VfObj *vf23();   // vtable 0x60
};
// fn_800E9B28 variant: vf23 returns VfObj* (vtable 0x5C), vf12 takes a float (0x40).
class VfObjF {
public:
    virtual ~VfObjF();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(float);   // vtable 0x40
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(float);   // vtable 0x40
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
      virtual VfObjF *vf22();   // vtable 0x5C
  virtual VfObjF *vf23();
};
class BasicSound;
class SoundPlayer;
// Virtual views of the objects BasicSound::Shutdown() calls through.  MWCC puts
// the first declared method at 0x08 (two leading destructor slots), so the
// numbered fillers stand for the slots this file never calls.
//
// The object BasicSound::GetPlayer() returns: the SeqPlayer/WavePlayer/StrmPlayer
// living inside the sound.  Its +0x04 is the player's copy of the sound's
// archive id, -1 while no sound is playing.
struct SoundPlayerVt {
    virtual void v08();
    virtual void v0C();
    virtual void Stop();             /* 0x10 */
    virtual void v14();
    virtual int IsValid();           /* 0x18 still playing something */
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void SetVolume(float);   /* 0x28 */
    int soundId;                     /* 0x04 */
};
//
// BasicSound's own vtable; the 0x50, 0x54 and 0x5C methods are pure in the base
// class and filled in by SeqSound, StrmSound and WaveSound.
struct BasicSoundVt {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual int HasResource();            /* 0x50 still holding the track it plays */
    virtual void ReleaseResource();       /* 0x54 hand that track back */
    virtual void v58();
    virtual SoundPlayerVt *GetPlayer();   /* 0x5C the player inside the sound */
};
//
// The hook stored at BasicSound+0x20, told when its sound shuts down.
struct ShutdownHookVt {
    virtual void v08();
    virtual void Notify(int id, void *sound); /* 0x0C */
};
namespace nw4hbm {
namespace snd {
namespace detail {
/* nw4hbm::snd::detail::BasicSound: one playable sound, attached to up to two
 * nw4r::snd::SoundHandles and played by a SoundPlayer.  Only the fields this
 * file touches are named. */
class BasicSound {
public:
    void *vtable;                    /* 0x00 */
    int fromPlayerHeap;              /* 0x04 its memory came from a player's heap */
    void *primaryHandle;             /* 0x08 nw4r::snd::SoundHandle attached to it */
    void *secondaryHandle;           /* 0x0C a second handle on the same sound */
    void *soundPlayer;               /* 0x10 nw4hbm::snd::SoundPlayer playing it */
    void *externalPlayer;            /* 0x14 nw4hbm::snd::detail::ExternalSoundPlayer */
    void *mixHook;                   /* 0x18 update hook, handed the mix below */
    void *updateHook;                /* 0x1C update hook, handed the id below */
    ShutdownHookVt *shutdownHook;    /* 0x20 told when the sound shuts down */
    int hookId;                      /* 0x24 id handed to those hooks */
    float mix[6];                    /* 0x28 volume and mix given to the mix hook */
    int pad_40;                      /* 0x40 */
    float fadeStart;                 /* 0x44 volume fade: volume it started from */
    float fadeEnd;                   /* 0x48 volume fade: volume it is going to */
    int fadeFrames;                  /* 0x4C volume fade: length */
    int fadeFrame;                   /* 0x50 volume fade: frames gone by */
    unsigned char pad_54[0x64 - 0x54]; /* 0x54 second ramp, same shape as 0x44 */
    unsigned char startRequested;    /* 0x64 asked to start; Update clears it */
    unsigned char started;           /* 0x65 the sound is up and running */
    unsigned char pad_66[0x69 - 0x66]; /* 0x66 pause flags and their counters */
    unsigned char stopWhenFaded;     /* 0x69 shut down once the volume fade is over */
    unsigned char pad_6A[0x74 - 0x6A];
    signed char playerPriority;      /* 0x74 priority inside the player, 0-0x7F */
    unsigned char pad_75[0x78 - 0x75];
    int soundId;                     /* 0x78 archive sound id, -1 once shut down */
    float current;                   /* 0x7C volume ramp: volume it started from */
    float target;                    /* 0x80 volume ramp: volume it is going to */
    int total;                       /* 0x84 volume ramp: length */
    int elapsed;                     /* 0x88 volume ramp: frames gone by */
    float initialVolume;             /* 0x8C volume a restarted sound starts from */
    void SetVolume(float, int);
    void SetInitialVolume(float);
    void Shutdown();
};
}
}
}
typedef unsigned char u8;
typedef unsigned short u16;
// BasicSound::Update helpers
class UpdPlayerVt {
public:
    virtual ~UpdPlayerVt();
    virtual int p0C();
    virtual void p10();
    virtual void p14(int);
    virtual int p18();
    virtual void p1C();
    virtual int p20();
    virtual int p24();
    virtual void p28(float);
    virtual void p2C(float);
    virtual void p30(float);
    virtual void p34(float);
    virtual void p38(float);
    virtual void p3C(float);
    virtual void p40();
    virtual void p44();
    virtual void p48();
    virtual void p4C();
    virtual void p50();
    virtual void p54();
    virtual void p58();
    virtual void p5C();
    virtual void p60(int);
    virtual void p64(float);
    virtual void p68();
    virtual void p6C();
    virtual void p70(int, float);
};
class UpdSelfVt {
public:
    virtual ~UpdSelfVt();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18(int);
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual UpdPlayerVt *s5C();
};
class UpdCbA { public: virtual void a08(int, void *); };
class UpdCbB { public: virtual void b08(void *, int, void *, int, int); };
extern const char lbl_803227A4[];
extern "C" float GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800F87F8(void *, int);
extern "C" int fn_800F87F0();
extern "C" int fn_800F87E8(void *);
#pragma always_inline on
static inline float UpdRamp(float start, float end, int total, int elapsed) {
    float r;
    if (elapsed >= total) {
        r = end;
    } else {
        r = start + (float)elapsed * (end - start) / (float)total;
    }
    return r;
}
struct UpdRampFields { float start; float end; int total; int elapsed; };
static inline float UpdRamp(UpdRampFields *s) {
    int total = s->total;
    int elapsed = s->elapsed;
    float r;
    if (elapsed >= total) {
        r = s->end;
    } else {
        r = s->start + (float)elapsed * (s->end - s->start) / (float)total;
    }
    return r;
}
#pragma always_inline reset
#define UF(T, off) (*(T *)((char *)self + (off)))
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *fn_80128668(void *);
extern "C" void *__register_global_object(void *, void *, void *);
extern "C" void *fn_800E279C(void *);
extern "C" unsigned char lbl_8055DE18;
#pragma push
#pragma small_data off
extern char lbl_80407F6C[];
extern char lbl_80407F60[];
#pragma pop
extern "C" void *fn_8002F634(void *, void *, int, int);
extern "C" void *__dt__Q46nw4hbm3snd6detail7AxVoiceFv(void *, int);
extern "C" void *fn_800E2D74(void *, int);
extern "C" void TRKGetFreeBuffer(void *);
extern "C" void fn_800E4764(void *);
#pragma push
#pragma small_data off
extern u8 lbl_80322498[];
extern const char lbl_803220C4[];
extern const char lbl_803220A0[];
#pragma pop
typedef float f32;
extern float lbl_80560F38;
extern float lbl_80560F3C;
#pragma push
#pragma small_data off
extern float lbl_80560FB0;
#pragma pop
extern float lbl_80560F00;
extern float lbl_80560F04;
typedef signed short s16;
#define TYPES_H
#include "revolution/OS/OSFastCast.h"
#undef TYPES_H
#pragma push
#pragma small_data off
extern float lbl_80320E38[];
#pragma pop
extern "C" f32 SinFIdx__Q24nw4r4mathFf(f32 angle) {
    f32 index = __fabsf(angle);
    while (index >= 65536.0f) index -= 65536.0f;
    u16 q = __OSf32tou16(index);
    f32 whole = __OSu16tof32(&q);
    u32 off = ((q * 0x10) & 0xFF0);
    f32 frac = index - whole;
    u8 *base = (u8 *)lbl_80320E38;
    f32 v0 = *(f32 *)(base + off);
    f32 v1 = *(f32 *)(base + off + 8);
    f32 value = v0 + frac * v1;
    if (angle < lbl_80560F04) value = -value;
    return value;
}

extern "C" f32 CosFIdx__Q24nw4r4mathFf(f32 angle) {
    f32 index = __fabsf(angle);
    while (index >= lbl_80560F00) index -= lbl_80560F00;
    u16 quantized = ((u16 *)&index)[0];
    f32 *entry = (f32 *)((char *)lbl_80320E38 + ((quantized * 0x10) & 0xFF0));
    f32 fraction = index;
    return entry[1] + fraction * entry[3];
}

#pragma push
#pragma small_data off
extern float lbl_80560F04, lbl_80560F08, lbl_80560F0C, lbl_80560F10, lbl_80560F14, lbl_80560F18;
extern float lbl_80321E48[];
#pragma pop
extern "C" float Atan2FIdx__Q24nw4r4mathFff(float y, float x) {
    float f1 = y;
    float f3;
    float f4 = lbl_80560F04;
    int mode;
    if (x == lbl_80560F04 && y == lbl_80560F04) return lbl_80560F04;
    if (x <= lbl_80560F04) {
        if (y <= lbl_80560F04) {
            if (x <= y) { f3 = x; mode = 0; }
            else { f3 = y; f4 = lbl_80560F0C; f1 = x; mode = 1; }
        } else {
            f1 = -y;
            if (x <= f1) { f3 = x; mode = 1; }
            else { f3 = f1; f4 = lbl_80560F10; f1 = x; mode = 0; }
        }
    } else {
        if (y <= lbl_80560F04) {
            float f0 = -x;
            if (f0 <= y) { f3 = f0; f4 = lbl_80560F14; mode = 1; }
            else { f3 = y; f4 = lbl_80560F0C; f1 = f0; mode = 0; }
        } else {
            float f0 = -x;
            f1 = -y;
            if (f0 <= f1) { f3 = f0; f4 = lbl_80560F18; mode = 0; }
            else { f3 = f1; f4 = lbl_80560F10; f1 = f0; mode = 1; }
        }
    }
    f1 = f1 / f3 * lbl_80560F08;
    if (mode) {
        u16 i = *(u16 *)&f1;
        float *e = (float *)((char *)lbl_80321E48 + i * 8);
        return f4 - (e[0] + (f1 - (float)i) * e[1]);
    } else {
        u16 i = *(u16 *)&f1;
        float *e = (float *)((char *)lbl_80321E48 + i * 8);
        return f4 + (e[0] + (f1 - (float)i) * e[1]);
    }
}

extern "C" void __ct__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void fn_8002F53C(void *, void *, void *, s32, s32); /* extern */
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8(void *, int);
extern "C" void fn_800E2C98(void *);
extern f32 lbl_80560F20;
extern f32 lbl_80560F24;
#pragma push
#pragma processor 750
void *fn_800E279C(void *arg0) {
    unsigned char* p = (unsigned char*)arg0;
    void* l1 = (void*)(p + 8);
    void* l2 = (void*)(p + 0x14);
    void* l3 = (void*)(p + 0x20);
    *(volatile int*)(p + 0xC) = 0;
    *(volatile int*)(p + 0x10) = 0;
    *(volatile int*)(p + 0x18) = 0;
    *(volatile int*)(p + 0x1C) = 0;
    *(volatile int*)(p + 0x24) = 0;
    *(volatile int*)(p + 0x28) = 0;
    *(int*)(p + 0) = 0;
    *(int*)(p + 4) = 0;
    *(int*)(p + 8) = 0;
    *(int*)(p + 8 + 0) = 0; *(void**)(p + 8 + 4) = (void*)(p + 8 + 4); *(void**)(p + 8 + 8) = (void*)(p + 8 + 4);
    *(int*)(p + 0x14 + 0) = 0; *(void**)(p + 0x14 + 4) = (void*)(p + 0x14 + 4); *(void**)(p + 0x14 + 8) = (void*)(p + 0x14 + 4);
    *(int*)(p + 0x20 + 0) = 0; *(void**)(p + 0x20 + 4) = (void*)(p + 0x20 + 4); *(void**)(p + 0x20 + 8) = (void*)(p + 0x20 + 4);
    fn_8002F53C(p + 0x2C, &__ct__Q46nw4hbm3snd6detail7AxVoiceFv, &__dt__Q46nw4hbm3snd6detail7AxVoiceFv, 0x1B0, 0x40);
    float f = lbl_80560F20;
    p[0x6C30] = 0;
    p[0x6C31] = 1;
    p[0x6C32] = 0;
    p[0x6C33] = 0;
    *(float*)(p + 0x6C34) = f;
    *(float*)(p + 0x6C38) = f;
    *(int*)(p + 0x6C3C) = 0;
    *(int*)(p + 0x6C40) = 0;
    *(float*)(p + 0x6C44) = f;
    *(float*)(p + 0x6C48) = f;
    *(int*)(p + 0x6C4C) = 0;
    *(int*)(p + 0x6C50) = 0;
    *(float*)(p + 0x6C54) = f;
    *(float*)(p + 0x6C58) = f;
    *(int*)(p + 0x6C5C) = 0;
    *(int*)(p + 0x6C60) = 0;
    *(int*)(p + 0x6C64) = 0;
    *(int*)(p + 0x6C68) = -1;
    *(float*)(p + 0x6C6C) = f;
    *(float*)(p + 0x6C70) = f;
    *(int*)(p + 0x6C74) = 0;
    *(int*)(p + 0x6C78) = 0;
    FillTmp((ElemTmp*)(p + 0x6C9C), (ElemTmp*)(p + 0x6C7C), f);
    *(float*)(p + 0x6C9C) = f;
    *(float*)(p + 0x6CA0) = f;
    *(int*)(p + 0x6CA4) = 0;
    *(int*)(p + 0x6CA8) = 0;
    FillTmp((ElemTmp*)(p + 0x6CCC), (ElemTmp*)(p + 0x6CAC), f);
    fn_8002F53C(p + 0x6CCC, &fn_800E2C98, &__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8, 0xC, 3);
    {
        float g = lbl_80560F24;
        *(int*)(p + 0x6C3C) = 0;
        *(float*)(p + 0x6C34) = g;
        *(float*)(p + 0x6C38) = g;
        *(int*)(p + 0x6C40) = 0;
        *(float*)(p + 0x6C44) = g;
        *(float*)(p + 0x6C48) = g;
        *(int*)(p + 0x6C4C) = 0;
        *(int*)(p + 0x6C50) = 0;
        *(float*)(p + 0x6C54) = g;
        *(float*)(p + 0x6C58) = g;
        *(int*)(p + 0x6C5C) = 0;
        *(int*)(p + 0x6C60) = 0;
        *(float*)(p + 0x6C6C) = g;
        *(float*)(p + 0x6C70) = g;
        *(int*)(p + 0x6C74) = 0;
        *(int*)(p + 0x6C78) = 0;
        *(float*)(p + 0x6C9C) = g;
        *(float*)(p + 0x6CA0) = g;
        *(int*)(p + 0x6CA4) = 0;
        *(int*)(p + 0x6CA8) = 0;
        *(int*)(p + 0x6CF0) = 0;
        *(int*)(p + 0x6CFC) = 0;
        *(float*)(p + 0x6C7C) = g;
        *(float*)(p + 0x6C80) = g;
        *(int*)(p + 0x6C84) = 0;
        *(int*)(p + 0x6C88) = 0;
        *(float*)(p + 0x6CAC) = g;
        *(float*)(p + 0x6CB0) = g;
        *(int*)(p + 0x6CB4) = 0;
        *(int*)(p + 0x6CB8) = 0;
        *(int*)(p + 0x6CF4) = 0;
        *(int*)(p + 0x6D00) = 0;
        *(float*)(p + 0x6C8C) = g;
        *(float*)(p + 0x6C90) = g;
        *(int*)(p + 0x6C94) = 0;
        *(int*)(p + 0x6C98) = 0;
        *(float*)(p + 0x6CBC) = g;
        *(float*)(p + 0x6CC0) = g;
        *(int*)(p + 0x6CC4) = 0;
        *(int*)(p + 0x6CC8) = 0;
        *(int*)(p + 0x6CF8) = 0;
        *(int*)(p + 0x6D04) = 0;
    }
    return arg0;
}
#pragma pop
extern "C" void fn_800E2C98(void *arg0) {
    int *p = (int *)((char *)arg0 + 4);
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)arg0 = 0;
    *(int *)((char *)arg0 + 4) = (int)p;
    *(int *)((char *)arg0 + 8) = (int)p;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
extern "C" void *Instance__15EmissionManagerFv(void) {
    if ((signed char)lbl_8055DE18 == 0) {
        fn_800E279C(&lbl_80407F6C);
        __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
        lbl_8055DE18 = 1;
    }
    return &lbl_80407F6C;
}

/* EmissionManager deleting destructor: destroys embedded subobjects/arrays and optionally frees the object. */
extern "C" void *fn_800E2D74(void *self, int deleteFlag) {
    if (self != 0) {
        fn_8002F634((char *)self + 0x6ccc, (void *)__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8, 0xc, 3);
        fn_8002F634((char *)self + 0x2c, (void *)__dt__Q46nw4hbm3snd6detail7AxVoiceFv, 0x1b0, 0x40);
        if ((char *)self + 0x20 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)self + 0x20, 0);
        if ((char *)self + 0x14 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)self + 0x14, 0);
        if ((char *)self + 8 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)self + 8, 0);
        if (deleteFlag > 0) fn_80128668(self);
    }
    return self;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800E2E24(void *self) {
    if (*(unsigned char *)((char *)self + 0x6C30) == 0) {
        if (AIGetDMAStatus() == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x6E, lbl_80321F94);

        int i = 0;
        int offset = 0;
        nw4hbm::ut::detail::LinkListImpl::Iterator iterator;
        do {
            if ((char *)self + offset + 0x2C == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
            iterator.node = (nw4hbm::ut::detail::LinkListNode *)((char *)self + 0x24);
            ((nw4hbm::ut::detail::LinkListImpl *)((char *)self + 0x20))->Insert(
                iterator, (nw4hbm::ut::detail::LinkListNode *)((char *)self + offset + 0x1D4));
            i++;
            offset += 0x1B0;
        } while (i < 0x40);

        memset(lbl_80407E60, 0, 0x100);
        DCFlushRange(lbl_80407E60, 0x100);
        *(void **)((char *)self + 4) = lbl_80407E60;
        unsigned int irq = OSDisableInterrupts();
        AXGetAuxACallback((char *)self + 0x6CF0, (char *)self + 0x6CFC);
        AXGetAuxBCallback((char *)self + 0x6CF4, (char *)self + 0x6D00);
        AXGetAuxCCallback((char *)self + 0x6CF8, (char *)self + 0x6D04);
        AXRegisterAuxACallback(0, 0);
        AXRegisterAuxBCallback(0, 0);
        AXRegisterAuxCCallback(0, 0);
        *(void **)((char *)self + 0x6C2C) = AIRegisterDMACallback(fn_800E41EC);
        *(unsigned char *)((char *)self + 0x6C30) = 1;
        OSRestoreInterrupts(irq);
    }
}
#pragma pop

extern const char lbl_80322124[];
extern const char lbl_80322100[];
extern const char lbl_803220F4[];
extern const char lbl_803220D0[];
extern "C" void fn_800E2F84(void *self) {
    char *base = (char *)self;
    if (*(unsigned char *)(base + 0x6C30) != 0) {
        AIRegisterDMACallback(*(void **)(base + 0x6C2C));
        fn_800E4364(self, 0); fn_800E4364(self, 1); fn_800E4364(self, 2);
        AXRegisterAuxACallback(*(int *)(base + 0x6CF0), *(int *)(base + 0x6CFC));
        AXRegisterAuxBCallback(*(int *)(base + 0x6CF4), *(int *)(base + 0x6D00));
        AXRegisterAuxCCallback(*(int *)(base + 0x6CF8), *(int *)(base + 0x6D04));
        *(int *)(base + 0x6CF0) = 0; *(int *)(base + 0x6CFC) = 0;
        *(int *)(base + 0x6CF4) = 0; *(int *)(base + 0x6D00) = 0;
        *(int *)(base + 0x6CF8) = 0; *(int *)(base + 0x6D04) = 0;
        *(int *)(base + 4) = 0;
        while (*(int *)(base + 0x14) != 0) {
            if (*(int *)(base + 0x14) == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322124, 0x1F1, lbl_80322100);
            }
            void *node = *(void **)(base + 0x18);
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
            void *voice = (char *)node - 0x1A8;
            if (voice == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220F4, 0x193, lbl_803220D0);
            Stop__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
            Free__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
            void (*callback)(void *, int, void *) = *(void (**)(void *, int, void *))((char *)voice + 0x10C);
            if (callback != 0) callback(voice, 2, *(void **)((char *)voice + 0x110));
        }
        while (*(int *)(base + 0x20) != 0) {
            void *it = *(void **)(base + 0x24);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(base + 0x20, &it);
        }
        *(unsigned char *)(base + 0x6C30) = 0;
    }
}

#pragma push
#pragma small_data off
extern double lbl_80560F28;
#pragma pop
#pragma push
extern "C" f32 fn_800E310C(void *arg0) {
    int a = *(int *)((char *)arg0 + 0x6C50);
    int b = *(int *)((char *)arg0 + 0x6C4C);
    float x;
    if (a >= b) x = *(float *)((char *)arg0 + 0x6C48);
    else x = *(float *)((char *)arg0 + 0x6C44) +
        (float)a * (*(float *)((char *)arg0 + 0x6C48) - *(float *)((char *)arg0 + 0x6C44)) / (float)b;

    int c;
    int d;
    d = *(int *)((char *)arg0 + 0x6C5C);
    c = *(int *)((char *)arg0 + 0x6C60);
    float y;
    if (c >= d) y = *(float *)((char *)arg0 + 0x6C58);
    else y = *(float *)((char *)arg0 + 0x6C54) +
        (float)c * (*(float *)((char *)arg0 + 0x6C58) - *(float *)((char *)arg0 + 0x6C54)) / (float)d;
    float result = x * y;

    int e;
    int f;
    f = *(int *)((char *)arg0 + 0x6C3C);
    e = *(int *)((char *)arg0 + 0x6C40);
    float z;
    if (e >= f) z = *(float *)((char *)arg0 + 0x6C38);
    else z = *(float *)((char *)arg0 + 0x6C34) +
        (float)e * (*(float *)((char *)arg0 + 0x6C38) - *(float *)((char *)arg0 + 0x6C34)) / (float)f;
    return result * z;
}
#pragma pop

extern "C" int DVDGetDriveStatus(void);
extern "C" void fn_80031C8C(unsigned short);
extern "C" void fn_80031C94(unsigned short);
extern "C" void fn_80031C9C(unsigned short);
extern float lbl_80560F20, lbl_80560F24, lbl_80560F30;
extern "C" void fn_800E3228(void *arg0) {
    int status = DVDGetDriveStatus();
    if (status == 0) {
        if (*((unsigned char *)arg0 + 0x6C33) != 0) {
            unsigned char *node, *current, *sentinel;
            unsigned int interruptState;
            *((unsigned char *)arg0 + 0x6C33) = 0;
            interruptState = OSDisableInterrupts();
            current = *(unsigned char **)((unsigned char *)arg0 + 0x18);
            sentinel = (unsigned char *)arg0 + 0x18;
            while (current != sentinel) {
                node = current;
                current = *(unsigned char **)node;
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                if (*(unsigned char *)(node - 0x8C) != 0) {
                    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                    *(unsigned char *)(node - 0x85) |= 2;
                }
            }
            OSRestoreInterrupts(interruptState);
        }
    } else if (status != 1 && *((unsigned char *)arg0 + 0x6C33) == 0) {
        unsigned char *node, *current, *sentinel;
        unsigned int interruptState;
        *((unsigned char *)arg0 + 0x6C33) = 1;
        interruptState = OSDisableInterrupts();
        current = *(unsigned char **)((unsigned char *)arg0 + 0x18);
        sentinel = (unsigned char *)arg0 + 0x18;
        while (current != sentinel) {
            node = current;
            current = *(unsigned char **)node;
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
            if (*(unsigned char *)(node - 0x8C) != 0) {
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                *(unsigned char *)(node - 0x85) |= 2;
            }
        }
        OSRestoreInterrupts(interruptState);
    }
    {
        float scale, lower, upper;
        unsigned char *entry;
        int i;
        upper = lbl_80560F24;
        entry = (unsigned char *)arg0;
        lower = lbl_80560F20;
        i = 0;
        scale = lbl_80560F30;
        for (; i < 3; i++, entry += 0x10) {
            int changed = 0;
            int limit, value;
            volatile int *v = (volatile int *)(entry + 0x6CA8);
            value = *v; limit = *(volatile int *)(entry + 0x6CA4);
            if (value < limit) {
                value = *v; limit = *(volatile int *)(entry + 0x6CA4);
                if (value < limit) *v = value + 1;
                changed = 1;
            }
            v = (volatile int *)(entry + 0x6C78);
            value = *v; limit = *(volatile int *)(entry + 0x6C74);
            if (limit > value) {
                value = *v; limit = *(volatile int *)(entry + 0x6C74);
                if (value < limit) *v = value + 1;
                value = *v; limit = *(volatile int *)(entry + 0x6C74);
                if (limit <= value) fn_800E4364(arg0, i);
                changed = 1;
            }
            if (changed != 0) {
                float first, second, product;
                int count, total;
                count = *(volatile int *)(entry + 0x6CA8);
                total = *(volatile int *)(entry + 0x6CA4);
                product = lbl_80560F24;
                if (count >= total) first = *(float *)(entry + 0x6CA0);
                else {
                    float start = *(float *)(entry + 0x6C9C);
                    first = start + ((float)count * (*(float *)(entry + 0x6CA0) - start)) / (float)total;
                }
                if (first > upper) first = upper;
                else if (first < lower) first = lower;
                product *= first;
                count = *(volatile int *)(entry + 0x6C78);
                total = *(volatile int *)(entry + 0x6C74);
                if (count >= total) second = *(float *)(entry + 0x6C70);
                else {
                    float start = *(float *)(entry + 0x6C6C);
                    second = start + ((float)count * (*(float *)(entry + 0x6C70) - start)) / (float)total;
                }
                if (second > upper) second = upper;
                else if (second < lower) second = lower;
                product *= second;
                value = (int)(scale * product);
                switch (i) {
                case 0: fn_80031C8C((unsigned short)value); break;
                case 1: fn_80031C94((unsigned short)value); break;
                case 2: fn_80031C9C((unsigned short)value); break;
                }
            }
        }
    }
    {
        int changed = 0;
        volatile int *v;
        int value;
        v = (volatile int *)((unsigned char *)arg0 + 0x6C50);
        value = *v;
        if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C4C)) {
            value = *v;
            if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C4C)) *v = value + 1;
            changed = 1;
        }
        v = (volatile int *)((unsigned char *)arg0 + 0x6C60);
        value = *v;
        if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C5C)) {
            value = *v;
            if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C5C)) *v = value + 1;
            changed = 1;
        }
        v = (volatile int *)((unsigned char *)arg0 + 0x6C40);
        value = *v;
        if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C3C)) {
            value = *v;
            if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C3C)) *v = value + 1;
            changed = 1;
        }
        if (changed != 0) {
            unsigned char *node, *current;
            unsigned int interruptState = OSDisableInterrupts();
            node = *(unsigned char **)((unsigned char *)arg0 += 0x18);
            while (node != arg0) {
                current = node;
                node = *(unsigned char **)current;
                if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                if (*(unsigned char *)(current - 0x8C) != 0) {
                    if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                    *(unsigned char *)(current - 0x85) |= 0x10;
                }
            }
            OSRestoreInterrupts(interruptState);
        }
    }
}

extern "C" void *GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(void *self) {
    if (*(void **)((char *)self + 4) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x172, lbl_80321FAC);
    }
    return *(void **)((char *)self + 4);
}

extern "C" void RegisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNodePFv_v(void *self, void *node, void (*callback)(void)) {
    void *pThis = self;
    void *pNode = node;
    void (*pCallback)(void) = callback;
    unsigned int level = OSDisableInterrupts();
    if (pNode == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);
    }
    *(void (**)(void))((char *)pNode + 8) = pCallback;
    void *iterator = (char *)pThis + 12;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)pThis + 8, &iterator, pNode);
    OSRestoreInterrupts(level);
}

extern "C" void UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(void *self, void *node) {
    unsigned int level = OSDisableInterrupts();
    if (node == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)self + 8, node);
    OSRestoreInterrupts(level);
}

extern "C" void fn_80031C6C(int);
#pragma push
#pragma use_lmw_stmw off
extern "C" void SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(void *self, int mode) {
    if (*(int *)self == mode) return;
    *(int *)self = mode;
    switch (mode) {
    case 0: fn_80031C6C(0); break;
    case 1: fn_80031C6C(1); break;
    case 2: fn_80031C6C(2); break;
    case 3: fn_80031C6C(0); break;
    }
    unsigned int interrupts = OSDisableInterrupts();
    void *node;
    void *current;
    for (node = *(void **)((char *)self + 0x18); node != (char *)self + 0x18; ) {
        current = node;
        node = *(void **)node;
        if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
        if (*((unsigned char *)current - 0x8c) == 0) continue;
        if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
        *((unsigned char *)current - 0x85) |= 0x20;
    }
    OSRestoreInterrupts(interrupts);
}
#pragma pop

extern "C" int fn_800E394C(int *arg0) { return *arg0; }

extern "C" int Acquire__Q46nw4hbm3snd6detail7AxVoiceFiiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *, int, int, int, void (*)(void *, int, void *), void *);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern const char lbl_80321FC8[];
extern const char lbl_80322154[];
extern const char lbl_80322130[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_800E3954(char *self, int count, int columns, int priority, void (*callback)(void *, int, void *), void *callbackArg) {
    int stolen;
    register void *node;
    register void *voice;
    register void *oldVoice;
    unsigned int interruptState = OSDisableInterrupts();
    if (*(int *)((char *)self + 0x20) != 0) goto acquire_setup;
    stolen = 0;
    if (*(int *)((char *)self + 0x20) != 0) goto stolen_result;
    if (*(int *)((char *)self + 0x14) == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322124, 0x1F1, lbl_80322100);
    node = *(void **)((char *)self + 0x18);
    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, (unsigned short)0x23D, lbl_803220A0);
    oldVoice = (char *)node - 0x1A8;
    if (!oldVoice) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220F4, 0x193, lbl_803220D0);
    if (*(int *)((char *)oldVoice + 0x124) <= priority) goto steal_voice;
    stolen = 0;
    goto stolen_result;
steal_voice:
    stolen = *(int *)((char *)oldVoice + 0x104) * *(int *)((char *)oldVoice + 0x108);
    Stop__Q46nw4hbm3snd6detail7AxVoiceFv(oldVoice);
    Free__Q46nw4hbm3snd6detail7AxVoiceFv(oldVoice);
    {
        void (*done)(void *, int, void *) = *(void (**)(void *, int, void *))((char *)oldVoice + 0x10C);
        if (done != 0) done(oldVoice, 2, *(void **)((char *)oldVoice + 0x110));
    }
stolen_result:
    if (!stolen) {
        OSRestoreInterrupts(interruptState);
        return 0;
    }
acquire_setup:
    if (*(int *)((char *)self + 0x20) == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322124, 0x1F1, lbl_80322100);
    node = *(void **)((char *)self + 0x24);
    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
    voice = (char *)node - 0x1A8;
    if (voice == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220F4, 0x193, lbl_803220D0);
    if (!Acquire__Q46nw4hbm3snd6detail7AxVoiceFiiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(voice, count, columns, priority, callback, callbackArg)) {
        Warning__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x1F1, lbl_80321FC8);
        OSRestoreInterrupts(interruptState);
        return 0;
    }
    *(unsigned int *)((char *)voice + 0x124) = (unsigned char)priority;
    register long secondState = OSDisableInterrupts();
    if (!voice) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    register void *link = (char *)voice + 0x1A8;
    void *sentinel = (char *)self + 0x18;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)sentinel + 8, link);
    node = *(void **)((char *)self + 0x18);
    while (node != sentinel) {
        if (!node) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        if (*(int *)((char *)node - 0x84) > *(int *)((char *)voice + 0x124)) break;
        node = *(void **)node;
    }
    if (voice == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    void *iterator = node;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)self + 0x14, &iterator, link);
    OSRestoreInterrupts(secondState);
    if (*((unsigned char *)self + 0x6C31) != 0) {
        node = *(void **)(self += 0x18);
        while (node != (void *)self) {
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
            if (*(int *)((char *)node - 0x84) != 0xFF) {
                if (!node) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                void *entryVoice = (char *)node - 0x1A8;
                int row = 0;
                char *rowData = (char *)entryVoice;
                while (row < *(int *)((char *)entryVoice + 0x104)) {
                    char *buffer = rowData;
                    register int column = 0;
                    while (column < *(int *)((char *)entryVoice + 0x108)) {
                        void *input = *(void **)(buffer + 0xC);
                        if (input) TRKProcessInput(input, 0x10);
                        column += 1;
                        buffer += 4;
                    }
                    rowData += 0x10;
                    row++;
                }
            }
            node = *(void **)node;
        }
    }
    OSRestoreInterrupts(interruptState);
    return voice;
}

extern const char lbl_80321FE8[];
#pragma use_lmw_stmw off
extern "C" void FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(void *manager, void *voice) {
    if (voice == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x21D, lbl_80321FE8);
    }
    unsigned int firstState = OSDisableInterrupts();
    unsigned int secondState = OSDisableInterrupts();
    if (voice == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    }
    void *link = (char *)voice + 0x1A8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)manager + 0x14, link);
    if (voice == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    }
    void *iterator = (char *)manager + 0x24;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)manager + 0x20, &iterator, link);
    OSRestoreInterrupts(secondState);
    OSRestoreInterrupts(firstState);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800E3DDC(void *arg0, void *arg1) {
    struct Mgr { char pad0[0x14]; char activeList[0xC]; char freeList[0x4]; char pad1[8]; void *head; char pad2[0x6c31 - 0x1c]; unsigned char flag; };
    Mgr *m = (Mgr *)arg0;
    unsigned int outerLevel = OSDisableInterrupts();
    unsigned int level = OSDisableInterrupts();
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    void *link = (char *)arg1 + 0x1A8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(m->activeList, link);
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    void *it1 = (char *)arg0 + 0x24;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)arg0 + 0x20, &it1, link);
    OSRestoreInterrupts(level);
    level = OSDisableInterrupts();
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)arg0 + 0x20, link);
    void *node = *(void **)((char *)arg0 + 0x18);
    while (node != (char *)arg0 + 0x18) {
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        if (*(int *)((char *)node - 0x84) > *(int *)((char *)arg1 + 0x124)) break;
        node = *(void **)node;
    }
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    void *it2 = node;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)arg0 + 0x14, &it2, link);
    OSRestoreInterrupts(level);
    if (*(unsigned char *)((char *)arg0 + 0x6C31) != 0) {
        void *n = *(void **)((char *)arg0 + 0x18);
        while (n != (char *)arg0 + 0x18) {
            if (n == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
            if (*(int *)((char *)n - 0x84) != 0xFF) {
                if (n == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                char *base = (char *)n - 0x1A8;
                char *row = base;
                int a;
                int b;
                for (a = 0; a < *(int *)(base + 0x104); a++) {
                    char *entry = row;
                    for (b = 0; b < *(int *)(base + 0x108); b++) {
                        void *input = *(void **)(entry + 0xC);
                        if (input != 0) TRKProcessInput(input, 0x10);
                        entry += 4;
                    }
                    row += 0x10;
                }
            }
            n = *(void **)n;
        }
    }
    OSRestoreInterrupts(outerLevel);
}
#pragma pop

#pragma use_lmw_stmw reset

#pragma pop
extern "C" void fn_800E402C(void *arg0) {
    OSDisableInterrupts();
    *(u8 *)((char *)arg0 + 0x6C31) = 0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void TRKProcessInput(void *, unsigned int);
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800E4064(void *arg0, void *arg1) {
    struct Owner {
        unsigned char pad0[0x18];
        void *head;
        unsigned char pad1[0x6c31 - 0x1c];
        unsigned char active;
    };
    struct Owner *owner = (Owner *)arg0;
    void *sentinel;
    unsigned int level;
    void *node;
    level = OSDisableInterrupts();
    node = owner->head;
    owner->active = 1;
    sentinel = &owner->head;
    while (node != sentinel) {
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
        if (*(int *)((char *)node - 0x84) != 0xff) {
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
            int outer;
            int inner;
            char *base;
            char *row;
            char *entry;
            base = (char *)node - 0x1a8;
            outer = 0;
            row = base;
            while (outer < *(int *)(base + 0x104)) {
                entry = row;
                inner = 0;
                while (inner < *(int *)(base + 0x108)) {
                    void *input = *(void **)(entry + 0xC);
                    if (input != 0) TRKProcessInput(input, 0x10);
                    entry += 4;
                    inner++;
                }
                row += 0x10;
                outer++;
            }
        }
        node = *(void **)node;
    }
    OSRestoreInterrupts(level);
}
#pragma use_lmw_stmw off
extern "C" void UpdateAllVoices__Q46nw4hbm3snd6detail9AxManagerFv(void *this_) {
    void *end = (char *)this_ + 0x18;
    unsigned int level = OSDisableInterrupts();
    void *iterator = *(void **)end;
    while (iterator != end) {
        void *node = iterator;
        iterator = *(void **)iterator;
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        fn_800E4764((char *)node - 0x1A8);
    }
    OSRestoreInterrupts(level);
}
#pragma use_lmw_stmw reset
extern "C" void fn_800E41EC(void) {
    int one = 1;
    if ((s8)lbl_8055DE18 == 0) {
        fn_800E279C(&lbl_80407F6C);
        __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
        lbl_8055DE18 = (s8)one;
    }
    void **sentinel = (void **)((char *)&lbl_80407F6C + 0xC);
    void *node = *sentinel;
    do {
        void *current = node;
        node = *(void **)node;
        if (current == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322034, 0x23D, lbl_80322010);
        (*(void (**)())((char *)current + 8))();
        if ((s8)lbl_8055DE18 == 0) {
            fn_800E279C(&lbl_80407F6C);
            __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
            lbl_8055DE18 = (s8)one;
        }
    } while (node != sentinel);
    if ((s8)lbl_8055DE18 == 0) {
        fn_800E279C(&lbl_80407F6C);
        __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
        lbl_8055DE18 = (s8)one;
    }
    if (*(void **)((char *)&lbl_80407F6C + 0x6C2C) != 0) {
        if ((s8)lbl_8055DE18 == 0) {
            fn_800E279C(&lbl_80407F6C);
            __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
            lbl_8055DE18 = (s8)one;
        }
        (*(void (**)(void *))(*(void **)((char *)&lbl_80407F6C + 0x6C2C)))(&lbl_80407F6C);
    }
}
#pragma pop

#pragma use_lmw_stmw reset
extern "C" void Clear__Q46nw4hbm2ut6detail12LinkListImplFv(void *);
extern "C" void AXRegisterAuxACallback(int, int);
extern "C" void AXRegisterAuxBCallback(int, int);
extern "C" void AXRegisterAuxCCallback(int, int);
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800E4364(void *arg0, int arg1) {
    struct Dummy {
        virtual void first();
        virtual void second();
        virtual void third();
    };
    extern const char lbl_80322198[];
    extern const char lbl_80322160[];
    extern const char lbl_80322064[];
    extern const char lbl_80322040[];
    unsigned int interrupt;
    int valid;
    void *sentinel;
    void *node;
    void *list;
    unsigned int base;

    interrupt = OSDisableInterrupts();
    valid = 0;
    if (arg1 >= 0 && arg1 < 3) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322198, 0xBD, lbl_80322160, arg1, 0, 3);
    base = (unsigned int)arg0 + arg1 * 0xC;
    int count = *(int *)(base + 0x6CCC);
    list = (void *)(base + 0x6CCC);
    if (count == 0) {
        OSRestoreInterrupts(interrupt);
        return;
    }
    node = *(void **)((char *)list + 4);
    sentinel = (char *)list + 4;
    while (node != sentinel) {
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322064, 0x23D, lbl_80322040);
        ((Dummy *)((char *)node - 4))->third();
        node = *(void **)node;
    }
    Clear__Q46nw4hbm2ut6detail12LinkListImplFv(list);
    switch (arg1) {
    case 0: AXRegisterAuxACallback(0, 0); break;
    case 1: AXRegisterAuxBCallback(0, 0); break;
    case 2: AXRegisterAuxCCallback(0, 0); break;
    }
    OSRestoreInterrupts(interrupt);
}
#pragma pop
extern "C" void __ct__Q46nw4hbm3snd6detail7AxVoiceFv(void *this_) {
    ((unsigned long *)this_)[0x00 / 4] = 0;
    ((unsigned long *)this_)[0x04 / 4] = 0;
    ((unsigned long *)this_)[0x08 / 4] = (unsigned long)&lbl_80322498;
    ((unsigned long *)this_)[0x10C / 4] = 0;
    ((u8 *)this_)[0x11C] = 0;
    ((u8 *)this_)[0x11D] = 0;
    ((u8 *)this_)[0x11E] = 0;
    ((u8 *)this_)[0x11F] = 0;
    ((u8 *)this_)[0x121] = 0;
    ((u8 *)this_)[0x122] = 0;
    ((u8 *)this_)[0x123] = 0;
    ((unsigned long *)this_)[0x1A8 / 4] = 0;
    ((unsigned long *)this_)[0x1AC / 4] = 0;
    ((unsigned long *)this_)[0x0C / 4] = 0;
    ((unsigned long *)this_)[0x10 / 4] = 0;
    ((unsigned long *)this_)[0x14 / 4] = 0;
    ((unsigned long *)this_)[0x18 / 4] = 0;
    ((unsigned long *)this_)[0x1C / 4] = 0;
    ((unsigned long *)this_)[0x20 / 4] = 0;
    ((unsigned long *)this_)[0x24 / 4] = 0;
    ((unsigned long *)this_)[0x28 / 4] = 0;
}

extern "C" int fn_800E4520(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma use_lmw_stmw off
extern "C" void *__dt__Q46nw4hbm3snd6detail7AxVoiceFv(void *this_, int deleteFlags) {
    // Destructor for nw4hbm::snd::detail::AxVoice: reset vtable, free 2x4 TRK buffers, optionally delete.
    if (this_ != 0) {
        *(void **)((char *)this_ + 8) = (void *)&lbl_80322498;

        unsigned char *groupBase;
        unsigned char *slotPtr;
        int groupIndex;
        int slotIndex;

        groupBase = (unsigned char *)this_;
        groupIndex = 0;
        while (groupIndex < 2) {
            slotPtr = groupBase;
            slotIndex = 0;
            while (slotIndex < 4) {
                void *buffer = *(void **)(slotPtr + 0xC);
                if (buffer != 0) {
                    TRKGetFreeBuffer(buffer);
                }
                slotPtr += 4;
                slotIndex++;
            }
            groupBase += 0x10;
            groupIndex++;
        }

        if (deleteFlags > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}
#pragma use_lmw_stmw reset
/* Initializes AxVoice parameters: clears per-voice slots, stores channel/callback settings, and sets default mix/volume/pan state (lbl_80560F38=1.0f, lbl_80560F3C=0.0f). */
extern "C" void InitParam__Q46nw4hbm3snd6detail7AxVoiceFiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *axVoice, int voiceCount, int channelCount, void (*callback)(void *, int, void *), void *callbackArg) {
    struct VoiceSlot { char pad[0x2C]; int value; char tail[4]; };
    VoiceSlot *voices = (VoiceSlot *)axVoice;
    for (int i = 0; i < voiceCount; i++) voices[i].value = 0;
    float zero;
    float one;
    one = lbl_80560F38;
    zero = lbl_80560F3C;
    *(int *)((char *)axVoice + 0x104) = voiceCount;
    *(int *)((char *)axVoice + 0x108) = channelCount;
    *(void (**)(void *, int, void *))((char *)axVoice + 0x10C) = callback;
    *(void **)((char *)axVoice + 0x110) = callbackArg;
    *((char *)axVoice + 0x123) = 0;
    *((char *)axVoice + 0x11F) = 0;
    *((char *)axVoice + 0x120) = 0;
    *((char *)axVoice + 0x11E) = 0;
    *((char *)axVoice + 0x121) = 1;
    *((char *)axVoice + 0x122) = 0;
    *(float *)((char *)axVoice + 0x188) = one;
    *(float *)((char *)axVoice + 0x18C) = one;
    *(float *)((char *)axVoice + 0x190) = one;
    *(float *)((char *)axVoice + 0x194) = one;
    *(float *)((char *)axVoice + 0x198) = one;
    *(float *)((char *)axVoice + 0x19C) = zero;
    *(float *)((char *)axVoice + 0x1A0) = one;
    *(short *)((char *)axVoice + 0x1A4) = 0;
    *(float *)((char *)axVoice + 0x138) = one;
    *(float *)((char *)axVoice + 0x128) = zero;
    *(float *)((char *)axVoice + 0x12C) = zero;
    *(float *)((char *)axVoice + 0x130) = zero;
    *(float *)((char *)axVoice + 0x134) = zero;
    *(int *)((char *)axVoice + 0x13C) = 1;
    *(float *)((char *)axVoice + 0x140) = one;
    *(float *)((char *)axVoice + 0x144) = one;
    *(float *)((char *)axVoice + 0x148) = zero;
    *(float *)((char *)axVoice + 0x14C) = zero;
    *(float *)((char *)axVoice + 0x150) = zero;
    *(float *)((char *)axVoice + 0x154) = one;
    *(float *)((char *)axVoice + 0x164) = one;
    *(float *)((char *)axVoice + 0x174) = zero;
    *(float *)((char *)axVoice + 0x158) = one;
    *(float *)((char *)axVoice + 0x168) = one;
    *(float *)((char *)axVoice + 0x178) = zero;
    *(float *)((char *)axVoice + 0x15C) = one;
    *(float *)((char *)axVoice + 0x16C) = one;
    *(float *)((char *)axVoice + 0x17C) = zero;
    *(float *)((char *)axVoice + 0x160) = one;
    *(float *)((char *)axVoice + 0x170) = one;
    *(float *)((char *)axVoice + 0x180) = zero;
    *(float *)((char *)axVoice + 0x184) = one;
}

extern "C" void UpdateAxSrc__Q46nw4hbm3snd6detail7AxVoiceFb(void *, int);
extern "C" void UpdateAxMix__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void UpdateAxLpf__Q46nw4hbm3snd6detail7AxVoiceFv(char *);
extern "C" int fn_800E6B24(void *);
#pragma use_lmw_stmw off
extern "C" void fn_800E4764(void *arg0) {
#define B(off) (*(unsigned char *)((char *)arg0 + (off)))
#define I(off) (*(int *)((char *)arg0 + (off)))
    char *row;
    char *col;
    int i, j;
    if (B(0x11C) != 0) {
        if (B(0x11E) != 0 && IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(arg0) != 0) {
            void (*cb)(void *, int, int) = *(void (**)(void *, int, int))((char *)arg0 + 0x10C);
            if (cb != 0) {
                cb(arg0, 0, I(0x110));
            }
            B(0x11E) = 0;
            B(0x11D) = 0;
        }
        if ((B(0x123) & 1) && B(0x11D) != 0 && B(0x11E) == 0) {
            UpdateAxSrc__Q46nw4hbm3snd6detail7AxVoiceFb(arg0, 1);
            row = (char *)arg0;
            for (i = 0; i < I(0x104); row += 0x10, i++) {
                col = row;
                for (j = 0; j < I(0x108); col += 4, j++) {
                    if (*(void **)(col + 0xC) != 0) AXSetVoiceState(*(void **)(col + 0xC), 1);
                }
            }
            B(0x11E) = 1;
            B(0x123) = B(0x123) & 0xFE;
            B(0x123) = B(0x123) & ~8;
        }
        if (B(0x11E) != 0) {
            if ((B(0x123) & 2) && B(0x11D) != 0) {
                if (B(0x11F) != 0 || B(0x122) != 0 || *(unsigned char *)((char *)Instance__15EmissionManagerFv() + 0x6C33) != 0) {
                    row = (char *)arg0;
                    for (j = 0; j < I(0x104); row += 0x10, j++) {
                        col = row;
                        for (i = 0; i < I(0x108); col += 4, i++) {
                            if (*(void **)(col + 0xC) != 0) AXSetVoiceState(*(void **)(col + 0xC), 0);
                        }
                    }
                    B(0x120) = 1;
                } else {
                    col = (char *)arg0;
                    for (j = 0; j < I(0x104); col += 0x10, j++) {
                        row = col;
                        for (i = 0; i < I(0x108); row += 4, i++) {
                            if (*(void **)(row + 0xC) != 0) AXSetVoiceState(*(void **)(row + 0xC), 1);
                        }
                    }
                    B(0x120) = 0;
                }
                B(0x123) = B(0x123) & ~2;
            }
            if (B(0x123) & 8) {
                UpdateAxSrc__Q46nw4hbm3snd6detail7AxVoiceFb(arg0, 0);
                B(0x123) = B(0x123) & ~8;
            }
            if ((B(0x123) & 0x10) && fn_800E6B24(arg0) == 0) {
                B(0x123) = B(0x123) & ~0x10;
            }
            if (B(0x123) & 0x20) {
                UpdateAxMix__Q46nw4hbm3snd6detail7AxVoiceFv(arg0);
                B(0x123) = B(0x123) & ~0x20;
            }
            if (B(0x123) & 0x40) {
                UpdateAxLpf__Q46nw4hbm3snd6detail7AxVoiceFv((char *)arg0);
                B(0x123) = B(0x123) & ~0x40;
            }
        }
    }
#undef B
#undef I
}
#pragma use_lmw_stmw reset
extern "C" int TRKInitializeMessageBuffers(unsigned int, void (*)(void *), void *);
extern "C" void VoiceCallback__Q46nw4hbm3snd6detail7AxVoiceFPv(void *);
extern "C" void RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *, void *);
extern "C" void InitParam__Q46nw4hbm3snd6detail7AxVoiceFiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *, int, int, void (*)(void *, int, void *), void *);
extern const char lbl_803224E4[];
extern const char lbl_803224C0[];
#pragma use_lmw_stmw off
extern "C" int Acquire__Q46nw4hbm3snd6detail7AxVoiceFiiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *self, int count, int columns, int priority, void (*callback)(void *, int, void *), void *callbackArg) {
    unsigned int interruptState;
    int total;
    const char *fileName = lbl_803221A8;
    int buffers[8];
    int valid, rows, ncols, made, result, remaining;
    int j, i;
    unsigned int bufferSize, nextSize;
    int *bufferOut, *bufferIn;
    char *voice, *row, *manager, *node, *sentinel;
    valid = 0;
    if (count >= 1) {
        if (count <= 2) valid = 1;
    }
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x124, fileName + 0x10, count, 1, 2);
    if (count > 2) rows = 2;
    else {
        rows = 1;
        if (count >= 1) rows = count;
    }
    valid = 0;
    if (columns >= 1) {
        if (columns <= 4) valid = 1;
    }
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x127, fileName + 0x5C, columns, 1, 4);
    if (columns > 4) ncols = 4;
    else {
        ncols = 1;
        if (columns >= 1) ncols = columns;
    }
    interruptState = OSDisableInterrupts();
    bufferSize = 0x10;
    if (priority == 0xFF) bufferSize = 0x1F;
    if (*((unsigned char *)self + 0x11C) != 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x12E, fileName + 0xA8);
    total = rows * ncols;
    bufferOut = buffers;
    made = 0;
    while (made < total) {
        result = TRKInitializeMessageBuffers(bufferSize, VoiceCallback__Q46nw4hbm3snd6detail7AxVoiceFPv, self);
        if (result == 0) {
            remaining = total - made;
            manager = (char *)Instance__15EmissionManagerFv();
            node = *(char **)(manager + 0x18);
            sentinel = manager + 0x18;
            while (node != sentinel) {
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803224E4, 0x242, lbl_803224C0);
                if (priority >= *(int *)(node - 0x84)) {
                    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803224E4, 0x242, lbl_803224C0);
                    remaining -= *(int *)(node - 0xA4) * *(int *)(node - 0xA0);
                    if (remaining > 0) { node = *(char **)node; continue; }
                }
                break;
            }
            if (remaining > 0) {
                bufferIn = buffers; i = 0;
                while (i < made) { TRKGetFreeBuffer((void *)(unsigned int)*bufferIn); bufferIn++; i++; }
                OSRestoreInterrupts(interruptState);
                return 0;
            }
            nextSize = bufferSize;
            if (bufferSize < 0x1F) nextSize = bufferSize + 1;
            result = TRKInitializeMessageBuffers(nextSize, VoiceCallback__Q46nw4hbm3snd6detail7AxVoiceFPv, self);
        }
        if (result == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x167, fileName + 0xD0);
        if (result == 0) {
            bufferIn = buffers; i = 0;
            while (i < made) { TRKGetFreeBuffer((void *)(unsigned int)*bufferIn); bufferIn++; i++; }
            OSRestoreInterrupts(interruptState);
            return 0;
        }
        *bufferOut = result; bufferOut++; made++;
    }
    voice = (char *)self; bufferIn = buffers; i = 0;
    while (i < rows) {
        row = voice; j = 0;
        while (j < ncols) {
            TRKProcessInput((void *)(unsigned int)*bufferIn, bufferSize);
            *(int *)(row + 0xC) = *bufferIn;
            bufferIn++; j++; row += 4;
        }
        voice += 0x10; i++;
    }
    InitParam__Q46nw4hbm3snd6detail7AxVoiceFiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(self, rows, ncols, callback, callbackArg);
    void *disposeManager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
    RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(disposeManager, self);
    *((unsigned char *)self + 0x11C) = 1;
    OSRestoreInterrupts(interruptState);
    return 1;
}
#pragma use_lmw_stmw reset
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *, void *);
extern "C" void FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(void *, void *);
#pragma push
#pragma use_lmw_stmw off
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *self) {
    int interruptState = OSDisableInterrupts();
    if (*((unsigned char *)self + 0x11C) == 0) {
        OSRestoreInterrupts(interruptState);
        return;
    }
    char *row = (char *)self;
    char *entry;
    int rowIndex = 0;
    while (rowIndex < *((int *)((char *)self + 0x104))) {
        entry = row;
        int column = 0;
        while (column < *((int *)((char *)self + 0x108))) {
            if (*((int *)(entry + 0xC)) != 0) {
                TRKGetFreeBuffer(*((void **)(entry + 0xC)));
                *((int *)(entry + 0xC)) = 0;
            }
            entry += 4;
            column++;
        }
        row += 0x10;
        rowIndex++;
    }
    *((int *)((char *)self + 0x104)) = 0;
    UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
        GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), self);
    FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(
        Instance__15EmissionManagerFv(), self);
    *((unsigned char *)self + 0x11C) = 0;
    OSRestoreInterrupts(interruptState);
}
#pragma pop
extern float lbl_80560F44;
extern const char lbl_803222A0[];
extern "C" void fn_800E5E74(void *, int, int, int, int, int, int);
extern "C" void fn_800E68EC(void *, int, int, void *, int);
extern "C" void fn_80033408(void *, int);
extern double lbl_80560F48;

/* ------------------------------------------------------------------ *
 * nw4hbm::snd::detail::WaveData - a wave as WaveFileReader::ReadWaveParam
 * reads it: a header followed by one parameter block per channel.
 * ------------------------------------------------------------------ */
struct WaveChannelParam {
    /* 0x00 */ void *dataAddr;    /* address of the channel's sample data */
    /* 0x04 */ u32 dataParam[4];  /* sample offsets read from the wave file */
    /* 0x14 */ u16 coef[24];      /* envelope (0x28 bytes), then the mix levels */
};

struct WaveData {
    /* 0x00 */ u8 waveForm;       /* 0 = 8-bit PCM, 1 = 16-bit PCM, other = DSP ADPCM */
    /* 0x01 */ u8 loop;           /* loop between loopStart and loopEnd */
    /* 0x02 */ u8 channelCount;
    /* 0x03 */ u8 sampleRateHi;   /* sampleRate = sampleRateHi << 16 | the file's 16-bit rate */
    /* 0x04 */ s32 sampleRate;
    /* 0x08 */ s32 loopStart;     /* sample index */
    /* 0x0C */ s32 loopEnd;       /* sample index */
    /* 0x10 */ WaveChannelParam channelParam[1];
};

/* AxVoice::Format - the sample format an AX voice is set to. */
enum AxVoiceFormat {
    AX_FORMAT_ADPCM = 0,    /* 14 samples per 16-byte block */
    AX_FORMAT_PCM16 = 10,   /* two bytes per sample */
    AX_FORMAT_PCM8 = 25     /* one byte per sample */
};

/* What an AxVoice keeps per channel: the wave it plays, stride 0x34 at +0x2C. */
struct AxVoiceChannel {
    /* 0x00 */ void *dataAddr;   /* the channel's sample data, copied from the wave */
    /* 0x04 */ u16 coef[24];     /* envelope (0x28 bytes), then the mix levels */
};

/* What an AxVoice keeps per voice output, stride 0x1C at +0x94. */
struct AxVoiceOut {
    /* 0x00 */ f32 volume;     /* volume this output plays at */
    /* 0x04 */ f32 rateScale;  /* scales the AX source rate of the output */
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 unk_18;
};

/* nw4hbm::snd::detail::AxVoice: one wave played through a grid of AX voices,
 * channelCount (1..2) channels of voiceOutCount (1..4) voices each. */
struct AxVoice {
    /* 0x00 */ u32 pad_00[3];
    /* 0x0C */ void *axVoice[2][4];   /* the grid: a voice is 4 bytes, a channel row 0x10 */
    /* 0x2C */ AxVoiceChannel channel[2];
    /* 0x94 */ AxVoiceOut out[4];
    /* 0x104 */ s32 channelCount;
    /* 0x108 */ s32 voiceOutCount;
    /* 0x10C */ void *callback;
    /* 0x110 */ void *callbackArg;
    /* 0x114 */ s32 sampleRate;
    /* 0x118 */ s32 format;           /* AxVoiceFormat */
    /* 0x11C */ u8 activeFlag;
    /* 0x11D */ u8 started;
    /* 0x11E */ u8 playing;
    /* 0x11F */ u8 pause;
    /* 0x120 */ u8 paused;
    /* 0x121 */ u8 unk_121;
    /* 0x122 */ u8 mute;
    /* 0x123 */ u8 updateFlags;       /* bits the AX update functions act on */
    /* 0x124 */ u8 pad_124[0x60];
    /* 0x184 */ f32 playbackRate;     /* how fast the wave is played, 1.0 = as recorded */
};

#pragma fp_contract_aggressive on
extern "C" void Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(void *arg0, const void *arg1) {
    /* Set this AxVoice up to play the given wave: pick the AX sample format from
     * the wave form, copy every channel's sample address and its envelope/mix
     * coefficients out of the wave, hand the playback addresses to the AX voices,
     * reset the per-output volumes and the AX voice types, choose the mix rate
     * class from the playback rate, and ask for a full AX update. */
    AxVoice *voice = (AxVoice *)arg0;
    unsigned char *row;               /* channel row of the AX voice grid, stride 0x10 */
    const unsigned char *inst;        /* the wave's parameter block of this channel, stride 0x44 */
    unsigned char *output;            /* where the channel's address + coefficients go, stride 0x34 */
    unsigned char *env;               /* &out->coef[0]: the channel's envelope parameters */
    unsigned char *mix;               /* &out->coef[20]: the channel's mix levels */
    int channel;
    const WaveData *wave = (const WaveData *)arg1;
    AxVoiceFormat format;
    if (wave->waveForm == 1) {
        format = AX_FORMAT_PCM16;
    } else {
        format = AX_FORMAT_ADPCM;
        if (wave->waveForm == 0) format = AX_FORMAT_PCM8;
    }
    voice->format = format;
    voice->sampleRate = wave->sampleRate;
    row = (unsigned char *)voice;
    inst = (const unsigned char *)wave;
    output = (unsigned char *)voice;
    env = (unsigned char *)voice + 0x30;
    mix = (unsigned char *)voice + 0x58;
    channel = 0;
    while (channel < voice->channelCount) {
        if (*(void **)(row + 0xC) != 0) {   /* the channel has an AX voice */
            const WaveChannelParam *param = (const WaveChannelParam *)(inst + 0x10);
            AxVoiceChannel *out = (AxVoiceChannel *)(output + 0x2C);
            if (param->dataAddr == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x1BC, lbl_803222A0);
            out->dataAddr = param->dataAddr;
            out->coef[0] = param->coef[0];
            out->coef[1] = param->coef[1];
            out->coef[2] = param->coef[2];
            out->coef[3] = param->coef[3];
            out->coef[4] = param->coef[4];
            out->coef[5] = param->coef[5];
            out->coef[6] = param->coef[6];
            out->coef[7] = param->coef[7];
            out->coef[8] = param->coef[8];
            out->coef[9] = param->coef[9];
            out->coef[10] = param->coef[10];
            out->coef[11] = param->coef[11];
            out->coef[12] = param->coef[12];
            out->coef[13] = param->coef[13];
            out->coef[14] = param->coef[14];
            out->coef[15] = param->coef[15];
            out->coef[16] = param->coef[16];
            out->coef[17] = param->coef[17];
            out->coef[18] = param->coef[18];
            out->coef[19] = param->coef[19];
            out->coef[20] = param->coef[20];
            out->coef[21] = param->coef[21];
            out->coef[22] = param->coef[22];
            out->coef[23] = param->coef[23];
            fn_800E5E74(arg0, channel, wave->loop != 0, voice->format, (int)param->dataAddr, wave->loopStart, wave->loopEnd);
            if (voice->format == AX_FORMAT_ADPCM) {   /* only ADPCM waves carry envelope and mix data */
                ((void (*)(void *, int, int, void *))fn_800E68EC)(arg0, channel, voice->format, env);
                ((void (*)(void *, int, int, void *))fn_800E6A44)(arg0, channel, voice->format, mix);
            }
        }
        row += 0x10; inst += 0x44; output += 0x34; env += 0x34; mix += 0x34; channel++;
    }
    f32 zero0;
    f32 zero1;
    zero1 = lbl_80560F38;             /* 1.0f */
    zero0 = lbl_80560F3C;             /* 0.0f */
    unsigned char *outRow = (unsigned char *)voice;
    int outIndex = 0;
    while (outIndex < voice->voiceOutCount) {
        AxVoiceOut *out = (AxVoiceOut *)(outRow + 0x94);
        out->volume = zero1;
        outIndex++;
        out->rateScale = zero1;
        out->unk_08 = zero0;
        out->unk_0C = zero0;
        out->unk_10 = zero0;
        out->unk_14 = zero0;
        out->unk_18 = 0;
        outRow += 0x1C;
    }
    {
        int channel2;
        int outIndex2;
        unsigned char *base;
        unsigned char *slot;
        base = (unsigned char *)voice; channel2 = 0;
        while (channel2 < voice->channelCount) {
            slot = base; outIndex2 = 0;
            while (outIndex2 < voice->voiceOutCount) {
                void *axVoice = *(void **)(slot + 0xC);
                if (axVoice != 0) ((void (*)(void *, int))fn_80033538)(axVoice, 0);   /* AX voice type 0 */
                slot += 4; outIndex2++;
            }
            base += 0x10; channel2++;
        }
    }
    {
        int mixMode;
        int channel2;
        int outIndex2;
        unsigned char *base;
        unsigned char *slot;
        /* how far the wave is played above its 32 kHz reference picks the mix rate class */
        f32 rate = voice->playbackRate * (f32)voice->sampleRate / lbl_80560F40;
        if (rate > lbl_80560F44) mixMode = 2;      /* more than 4/3 of the reference */
        else if (rate > lbl_80560F38) mixMode = 3; /* up to twice */
        else mixMode = 4;
        base = (unsigned char *)voice; channel2 = 0;
        while (channel2 < voice->channelCount) {
            slot = base; outIndex2 = 0;
            while (outIndex2 < voice->voiceOutCount) {
                void *axVoice = *(void **)(slot + 0xC);
                if (axVoice != 0) fn_80033408(axVoice, mixMode);
                slot += 4; outIndex2++;
            }
            base += 0x10; channel2++;
        }
    }
    voice->pause = 0;
    voice->paused = 0;
    voice->started = 0;
    voice->playing = 0;
    voice->updateFlags |= 0x70;   /* the AX voices need a full update */
}
extern "C" void fn_800E519C(void *arg0) {
    unsigned int level = OSDisableInterrupts();
    u8 *p = (u8 *)arg0;
    p[0x11D] = 1;
    p[0x11F] = 0;
    p[0x123] |= 1;
    OSRestoreInterrupts(level);
}

#pragma use_lmw_stmw off
extern "C" void Stop__Q46nw4hbm3snd6detail7AxVoiceFv(void *self) {
    /* Stops this AxVoice if it is active: halts all per-row/channel AX voices,
     * clears active/pause flags and resets running state under interrupt lock. */
    unsigned int level;
    unsigned int innerLevel;
    void *axVoice;
    int active;
    int innerIndex;
    int outer;
    unsigned char *row;
    unsigned char *voice;

    level = OSDisableInterrupts();
    if (*((unsigned char *)self + 0x11E) != 0) {
        innerLevel = OSDisableInterrupts();
        axVoice = *(void **)((unsigned char *)self + 0xC);
        if (axVoice == 0) {
            OSRestoreInterrupts(innerLevel);
            active = 0;
        } else {
            active = (*(unsigned short *)((unsigned char *)axVoice + 0x148) == 1);
            OSRestoreInterrupts(innerLevel);
        }
        if (active != 0) {
            row = (unsigned char *)self;
            outer = 0;
            while (outer < *(int *)((unsigned char *)self + 0x104)) {
                voice = row;
                innerIndex = 0;
                while (innerIndex < *(int *)((unsigned char *)self + 0x108)) {
                    axVoice = *(void **)(voice + 0xC);
                    if (axVoice != 0) AXSetVoiceState(axVoice, 0);
                    voice += 4;
                    innerIndex++;
                }
                row += 0x10;
                outer++;
            }
        }
        *((unsigned char *)self + 0x11E) = 0;
    }
    *((unsigned char *)self + 0x120) = 0;
    *((unsigned char *)self + 0x11F) = 0;
    *((unsigned char *)self + 0x11D) = 0;
    OSRestoreInterrupts(level);
}
#pragma use_lmw_stmw reset
extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void *this_, u8 paused) {
    unsigned int level = OSDisableInterrupts();
    if (*(u8 *)((char *)this_ + 0x11F) == paused) {
        OSRestoreInterrupts(level);
        return;
    }
    *(u8 *)((char *)this_ + 0x11F) = paused;
    u8 flags = *(u8 *)((char *)this_ + 0x123);
    *(u8 *)((char *)this_ + 0x123) = flags | 2;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800E5338(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x188);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x10;
    }
}

extern "C" void SetVeVolume__Q46nw4hbm3snd6detail7AxVoiceFff(void *self, float arg0, float arg1) {
    /* Set voice envelope/VE volume(s), clamped to [0,1]. If arg1 < 0 only update
     * the target volume (+0x1A0); otherwise update current (+0x19C) and target and
     * mark the VE/volume dirty flag in the status byte at +0x123. */
    float f0 = lbl_80560F3C;
    if (arg1 < f0) {
        float f2 = arg0 > lbl_80560F38
            ? lbl_80560F38
            : (arg0 < f0 ? f0 : arg0);
        if (f2 != *(float *)((char *)self + 0x1A0)) {
            *(float *)((char *)self + 0x1A0) = f2;
            *(unsigned char *)((char *)self + 0x123) |= 0x10;
        }
    } else {
        float f3 = arg0 > lbl_80560F38
            ? lbl_80560F38
            : (arg0 < f0 ? f0 : (f0 = arg0));
        float f1 = lbl_80560F38;
        f1 = arg1 > f1
            ? f1
            : (f1 = lbl_80560F3C, (arg1 < f1 ? f1 : arg1));
        if (f1 != *(float *)((char *)self + 0x19C) || f3 != *(float *)((char *)self + 0x1A0)) {
            *(float *)((char *)self + 0x19C) = f1;
            *(float *)((char *)self + 0x1A0) = f3;
            *(unsigned char *)((char *)self + 0x123) |= 0x10;
        }
    }
}

extern "C" void fn_800E5444(void *arg0, float farg0) {
    if (farg0 != *(float *)((char *)arg0 + 0x184)) {
        *(float *)((char *)arg0 + 0x184) = farg0;
        *(unsigned char *)((char *)arg0 + 0x123) |= 8;
    }
}

extern float lbl_80560F38;
extern float lbl_80560F50;
extern float lbl_80560F54;
extern float lbl_80560F3C;
extern "C" void fn_800E5464(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (arg1 < lbl_80560F50) {
        value = lbl_80560F50;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x128);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E54A8(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F54) {
        value = lbl_80560F54;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x12C);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E54EC(void *arg0, float farg0) {
    if (farg0 != *(float *)((char *)arg0 + 0x130)) {
        *(float *)((char *)arg0 + 0x130) = farg0;
        *(unsigned char *)((char *)arg0 + 0x123) |= 0x20;
    }
}

extern "C" void fn_800E550C(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F54) {
        value = lbl_80560F54;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x134);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E5550(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x138);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x40;
    }
}

extern "C" void fn_800E5594(void *arg0, int arg1) {
    int *field = (int *)((char *)arg0 + 0x13c);
    if (arg1 != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = arg1;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E55B4(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x140);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif(void *voice, int remoteIndex, f32 volume) {
    /* Set the clamped remote output volume for a remote channel on this AxVoice and mark params dirty when changed. */
    int isValidIndex = 0;
    if (remoteIndex >= 0 && remoteIndex < 4) isValidIndex = 1;
    if (isValidIndex == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x2C2, lbl_803222F0, remoteIndex, 0, 4);
    f32 clampedVolume;
    if (volume > lbl_80560F38) {
        clampedVolume = lbl_80560F38;
    } else if (volume < lbl_80560F3C) {
        clampedVolume = lbl_80560F3C;
    } else {
        clampedVolume = volume;
    }
    f32 *slot = (f32 *)((char *)voice + 0x154 + remoteIndex * 4);
    if (clampedVolume != *slot) {
        *slot = clampedVolume;
        *((u8 *)voice + 0x123) |= 0x20;
    }
}

extern const char lbl_803223BC[];
extern "C" void fn_800E56D0(void *arg0, float arg1) {
    float sum = arg1 + lbl_80560F38;
    float value;
    if (sum > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (sum < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = sum;
    }
    float *field = (float *)((char *)arg0 + 0x144);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern const char lbl_80322338[];
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E5718(void *voice, int channel, float volume) {
    // Set remote output volume for channel (clamped to [0.0, 1.0]).
    int valid = 0;
    if (channel >= 0 && channel < 3) {
        valid = 1;
    }
    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x2D9, lbl_80322338, channel, 0, 3);
    }

    float result;
    if (volume > lbl_80560F38) {
        result = lbl_80560F38;
    } else if (volume < lbl_80560F3C) {
        result = lbl_80560F3C;
    } else {
        result = volume;
    }

    float *slot = (float *)((unsigned char *)voice + 0x148 + channel * 4);
    if (result != *slot) {
        *slot = result;
        *((unsigned char *)voice + 0x123) |= 0x20;
    }
}

/* nw4hbm::snd::detail::AxVoice::SetRemoteSend(int, float) - one of the voice's
 * four remote sends (+0x164 + remoteIndex * 4).  The request comes in biased
 * by -1.0, so it is raised by 1.0 and clamped to [0.0, 1.0]; the slot is only
 * written when the value actually changes, and a change sets the "mix needs
 * pushing to the AX" flag bit 0x20 in the byte at +0x123. */
extern "C" void SetRemoteSend__Q46nw4hbm3snd6detail7AxVoiceFif(void *voice, int remoteIndex, f32 send) {
    int isValidIndex = 0;
    if (remoteIndex >= 0 && remoteIndex < 4) isValidIndex = 1;
    /* snd_AxVoice.cpp:0x2E5, "remoteIndex is out of bounds(%d)" */
    if (isValidIndex == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x2E5, lbl_803222F0, remoteIndex, 0, 4);
    send += lbl_80560F38;                          /* lbl_80560F38 = 1.0f */
    f32 clampedSend;
    if (send > lbl_80560F38) {                     /* upper bound 1.0f */
        clampedSend = lbl_80560F38;
    } else if (send < lbl_80560F3C) {              /* lbl_80560F3C = 0.0f */
        clampedSend = lbl_80560F3C;
    } else {
        clampedSend = send;
    }
    f32 *slot = (f32 *)((unsigned char *)voice + 0x164 + remoteIndex * 4);
    if (clampedSend != *slot) {
        *slot = clampedSend;
        *((unsigned char *)voice + 0x123) |= 0x20; /* remote mix dirty */
    }
}

extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E58CC(void *voice, int channel, float volume) {
    // Set remote output volume for channel (clamped to [0.0, 1.0]).
    int valid = 0;
    if (channel >= 0 && channel < 4) {
        valid = 1;
    }
    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x2F1, lbl_803222F0, channel, 0, 4);
    }

    float result;
    if (volume > lbl_80560F38) {
        result = lbl_80560F38;
    } else if (volume < lbl_80560F3C) {
        result = lbl_80560F3C;
    } else {
        result = volume;
    }

    float *slot = (float *)((unsigned char *)voice + 0x174 + channel * 4);
    if (result != *slot) {
        *slot = result;
        *((unsigned char *)voice + 0x123) |= 0x20;
    }
}

extern "C" void *Instance__15EmissionManagerFv(void);
extern "C" void fn_800E3DDC(void *, void *);
extern "C" void SetPriority__Q46nw4hbm3snd6detail7AxVoiceFi(void *voice, int priority) {
    /* Set this AxVoice's priority (0-255), asserting on out-of-range values, then notify the emission manager. */
    int valid = 0;
    if (priority >= 0) {
        if (priority <= 0xFF) valid = 1;
    }
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x306, lbl_803223BC, priority, 0, 0xFF);
    }
    *(int *)((char *)voice + 0x124) = priority;
    fn_800E3DDC(Instance__15EmissionManagerFv(), voice);
}

extern "C" int GetCurrentPlayingDspAddress__Q46nw4hbm3snd6detail7AxVoiceCFv(void *self) {
    unsigned int level = OSDisableInterrupts();
    void *voice = *(void **)((char *)self + 0xc);
    void *dsp = (char *)voice + 0x138;
    if (dsp == 0) {
        OSRestoreInterrupts(level);
        return 0;
    }
    int address = (*(unsigned short *)((char *)dsp + 0x84) << 16) +
                  *(unsigned short *)((char *)dsp + 0x86);
    OSRestoreInterrupts(level);
    return address;
}

extern "C" void fn_800E5A8C(void) {
    ((void (*)(void))fn_800E6A44)();
}

extern "C" void fn_80033538(unsigned short);
extern "C" void SetBaseAddress__Q46nw4hbm3snd6detail7AxVoiceFiPCv(void *self, int index, const void *address) {
    unsigned int level = OSDisableInterrupts();
    *(const void **)((char *)self + index * 0x34 + 0x2C) = address;
    OSRestoreInterrupts(level);
}

extern "C" int IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(void *self) {
    unsigned int start, end, address, buffer;
    int fmt;
    void *mgr;
    unsigned int level;
    register unsigned int irq = OSDisableInterrupts();
    if (*(int *)((char *)self + 0x2c) == 0) { OSRestoreInterrupts(irq); return 0; }
    level = OSDisableInterrupts();
    address = *(unsigned int *)((char *)self + 0xc) + 0x138;
    if (address == 0) { OSRestoreInterrupts(level); start = 0; }
    else {
        unsigned short hi = *(unsigned short *)(address + 0x84);
        unsigned short lo = *(unsigned short *)(address + 0x86);
        start = ((unsigned int)hi << 16) + lo;
        OSRestoreInterrupts(level);
    }
    mgr = Instance__15EmissionManagerFv();
    buffer = (unsigned int)GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(mgr);
    fmt = *(int *)((char *)self + 0x118);
    if (buffer != 0) buffer += 0x80000000;
    end = 0;
    switch (fmt) {
    case 0: end = buffer * 2 + 2; break;
    case 25: end = buffer; break;
    case 10: end = buffer >> 1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438); break;
    }
    address = end;
    switch (*(int *)((char *)self + 0x118)) {
    case 0: address = end + 0x200; break;
    case 25: address = end + 0x100; break;
    case 10: address = end + 0x80; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x362, lbl_80322438); break;
    }
    if (end <= start && start < address) { OSRestoreInterrupts(irq); return 1; }
    OSRestoreInterrupts(irq);
    return 0;
}

#pragma use_lmw_stmw off
extern "C" int GetCurrentPlayingSample__Q46nw4hbm3snd6detail7AxVoiceCFv(void *self) {
    int level = OSDisableInterrupts();
    int size = *(int *)((char *)self + 0x2C);
    if (size == 0) {
        OSRestoreInterrupts(level);
        return 0;
    }
    if (IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(self)) {
        level = OSDisableInterrupts();
        unsigned char *pos = *(unsigned char **)((char *)self + 0xC) + 0x138;
        int position;
        if (pos == 0) {
            OSRestoreInterrupts(level);
            position = 0;
        } else {
            position = ((int)*(unsigned short *)(pos + 0x80) << 16) + *(unsigned short *)(pos + 0x82);
            OSRestoreInterrupts(level);
        }
        int format = *(int *)((char *)self + 0x118);
        if (size != 0) size += (int)0x80000000;
        int result = 0;
        switch (format) {
        case 0: {
            unsigned int rem = position - size * 2;
            result = ((rem & 0xF) + ((rem >> 4) * 0xE)) - 2;
            break;
        }
        case 25: result = position - size; break;
        case 10: result = position - ((unsigned int)size >> 1); break;
        default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x583, lbl_80322438); break;
        }
        level = OSDisableInterrupts();
        OSRestoreInterrupts(level);
        return result + 1;
    } else {
        level = OSDisableInterrupts();
        unsigned char *pos = *(unsigned char **)((char *)self + 0xC) + 0x138;
        int position;
        if (pos == 0) {
            OSRestoreInterrupts(level);
            position = 0;
        } else {
            position = ((int)*(unsigned short *)(pos + 0x84) << 16) + *(unsigned short *)(pos + 0x86);
            OSRestoreInterrupts(level);
        }
        int format = *(int *)((char *)self + 0x118);
        if (size != 0) size += (int)0x80000000;
        int result = 0;
        switch (format) {
        case 0: {
            unsigned int rem = position - size * 2;
            result = ((rem & 0xF) + ((rem >> 4) * 0xE)) - 2;
            break;
        }
        case 25: result = position - size; break;
        case 10: result = position - ((unsigned int)size >> 1); break;
        default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x583, lbl_80322438); break;
        }
        level = OSDisableInterrupts();
        OSRestoreInterrupts(level);
        return result;
    }
}
#pragma use_lmw_stmw reset
extern const char lbl_80322400[];
extern "C" void fn_8003381C(void *, void *);
#pragma use_lmw_stmw off
extern "C" void fn_800E5E74(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    const char *f = lbl_803221A8;
    char *self = (char *)arg0;
    unsigned int end;
    unsigned int cur;
    unsigned int start;
    unsigned int off;
    unsigned int off2;
    struct {
        short flag;
        short unk;
        unsigned short startHi, startLo;
        unsigned short endHi, endLo;
        unsigned short curHi, curLo;
    } rec;
    char *entry;
    int i;
    if (arg1 >= 2) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)((int)f + 0), 0x396, f + 0x258);
    }
    if (arg2 != 0) {
        int fmt = *(int *)(self + 0x118);
        off = arg4;
        if (off) off += 0x80000000;
        start = 0;
        switch (fmt) {
        case 0: start = ((unsigned int)arg5 % 14) + (off * 2) + (((unsigned int)arg5 / 14) * 16) + 2; break;
        case 25: start = off + arg5; break;
        case 10: start = (off >> 1) + arg5; break;
        default: Panic__Q26nw4hbm2dbFPCciPCce((const char *)((int)f + 0), 0x561, f + 0x290); break;
        }
    } else {
        unsigned int addr = (unsigned int)GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(Instance__15EmissionManagerFv());
        int fmt = *(int *)(self + 0x118);
        if (addr) addr += 0x80000000;
        start = 0;
        switch (fmt) {
        case 0: start = addr * 2 + 2; break;
        case 25: start = addr; break;
        case 10: start = addr >> 1; break;
        default: Panic__Q26nw4hbm2dbFPCciPCce((const char *)((int)f + 0), 0x561, f + 0x290); break;
        }
    }
    {
        int fmt = *(int *)(self + 0x118);
        off = arg4;
        if (off) off += 0x80000000;
        cur = 0;
        switch (fmt) {
        case 0: cur = off * 2 + 2; break;
        case 25: cur = off; break;
        case 10: cur = off >> 1; break;
        default: Panic__Q26nw4hbm2dbFPCciPCce((const char *)((int)f + 0), 0x561, f + 0x290); break;
        }
    }
    {
        int fmt = *(int *)(self + 0x118);
        off2 = arg4;
        if (off2) off2 += 0x80000000;
        end = 0;
        switch (fmt) {
        case 0: {
            unsigned int x = arg6 - 1;
            end = (x % 14) + (off2 * 2) + ((x / 14) * 16) + 2;
            break;
        }
        case 25: end = off2 + arg6 - 1; break;
        case 10: end = arg6 + (off2 >> 1) - 1; break;
        default: Panic__Q26nw4hbm2dbFPCciPCce((const char *)((int)f + 0), 0x561, f + 0x290); break;
        }
    }
    rec.flag = arg2;
    rec.unk = arg3;
    rec.startHi = start >> 16;
    rec.startLo = start;
    rec.endHi = end >> 16;
    rec.endLo = end;
    rec.curHi = cur >> 16;
    rec.curLo = cur;
    entry = self + arg1 * 0x10;
    for (i = 0; i < *(int *)(self + 0x108); entry += 4, i++) {
        fn_8003381C(*(void **)(entry + 0xC), &rec);
    }
}
#pragma use_lmw_stmw reset

namespace nw4hbm { namespace snd { namespace detail {
class AxVoice {
public:
    void SetLoopStart(int, const void *, unsigned long);
    void SetLoopEnd(int, const void *, unsigned long);
};
}}}
#pragma push
#pragma use_lmw_stmw off
extern "C" void SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *arg0, int arg1, const void *arg2, unsigned long arg3) {
    unsigned int interrupt = OSDisableInterrupts();
    int format = *(int *)((char *)arg0 + 0x118);
    unsigned int value = (unsigned int)arg2;
    unsigned int start;
    if (arg2 != 0) value += 0x80000000;
    start = 0;
    switch (format) {
    case 0:
        start = arg3 % 14 + value * 2 + (arg3 / 14) * 16 + 2;
        break;
    case 10:
        start = value + arg3;
        break;
    case 25:
        start = (value >> 1) + arg3;
        break;
    default:
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438);
        break;
    }
    unsigned int *voice = (unsigned int *)((char *)arg0 + arg1 * 0x10);
    unsigned int hi = start >> 16;
    unsigned int lo = start & 0xFFFF;
    for (int i = 0; i < *(int *)((char *)arg0 + 0x108); i++, voice++) {
        unsigned int ch = voice[3];
        unsigned int inner = OSDisableInterrupts();
        *(unsigned short *)(ch + 0x1B4) = hi;
        *(unsigned short *)(ch + 0x1B6) = lo;
        if (!(*(unsigned int *)(ch + 0x1C) & 0x800)) *(unsigned int *)(ch + 0x1C) |= 0x2000;
        OSRestoreInterrupts(inner);
    }
    OSRestoreInterrupts(interrupt);
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling reset
void nw4hbm::snd::detail::AxVoice::SetLoopEnd(int index, const void *address, unsigned long length) {
    unsigned int irq;
    unsigned int start;
    unsigned int loopEnd;
    unsigned int temp;
    unsigned int end;
    int mode;
    int offset;
    int i;
    unsigned int *voice;
    irq = OSDisableInterrupts();
    mode = *(int *)((char *)this + 0x118);
    start = (unsigned int)address;
    if (address != 0) start += 0x80000000;
    loopEnd = 0;
    switch (mode) {
    case 0:
        end = (unsigned int)length - 1;
        temp = end / 14;
        loopEnd = end % 14 + (start << 1) + (temp << 4) + 2;
        break;
    case 25:
        loopEnd = start + (unsigned int)length - 1;
        break;
    case 10:
        loopEnd = (unsigned int)length + (start >> 1) - 1;
        break;
    default:
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438);
        break;
    }
    offset = index * 0x10;
    start = loopEnd >> 16;
    end = loopEnd & 0xFFFF;
    voice = (unsigned int *)((char *)this + offset);
    for (i = 0; i < *(int *)((char *)this + 0x108); i++) {
        unsigned int *obj = (unsigned int *)*(unsigned int **)((char *)voice + 0xC);
        unsigned int inner = OSDisableInterrupts();
        *(unsigned short *)((char *)obj + 0x1B8) = (unsigned short)start;
        *(unsigned short *)((char *)obj + 0x1BA) = (unsigned short)end;
        temp = *(unsigned int *)((char *)obj + 0x1C);
        if ((temp & 0x800) == 0) *(unsigned int *)((char *)obj + 0x1C) = temp | 0x4000;
        OSRestoreInterrupts(inner);
        voice = (unsigned int *)((char *)voice + 4);
    }
    OSRestoreInterrupts(irq);
}
#pragma scheduling reset
#pragma pop

#pragma push
#pragma use_lmw_stmw off
extern "C" void SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(void *self, bool loopFlag) {
    /* Set or clear the loop flag on every AX voice in this AxVoice's voice grid, with interrupts disabled. */
    unsigned int savedIrq = OSDisableInterrupts();
    void *voice;
    char *groupPtr;
    char *entryPtr;
    int groupIndex;
    int voiceIndex;
    groupPtr = (char *)self;
    groupIndex = 0;
    for (; groupIndex < *(int *)((char *)self + 0x104); groupPtr += 0x10, ++groupIndex) {
        entryPtr = groupPtr;
        voiceIndex = 0;
        for (; voiceIndex < *(int *)((char *)self + 0x108); entryPtr += 4, ++voiceIndex) {
            voice = *(void **)(entryPtr + 0xC);
            unsigned int innerIrq = OSDisableInterrupts();
            *(unsigned short *)((char *)voice + 0x1B0) = loopFlag;
            unsigned int voiceFlags = *(unsigned int *)((char *)voice + 0x1C);
            if ((voiceFlags & 0x800) == 0) *(unsigned int *)((char *)voice + 0x1C) = voiceFlags | 0x1000;
            OSRestoreInterrupts(innerIrq);
        }
    }
    OSRestoreInterrupts(savedIrq);
}

#pragma dont_inline on
extern "C" void StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *arg0, int arg1, const void *arg2, unsigned long arg3) {
    unsigned long irq=OSDisableInterrupts();
    void *emission=Instance__15EmissionManagerFv();
    unsigned int address=(unsigned int)GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(emission);
    unsigned int format=*(int *)((char *)arg0+0x118);
    if(address) address+=0x80000000;
    s32 start=0;
    switch(format) {
    case 0: start=address*2+2; break;
    case 25: start=address; break;
    case 10: start=address>>1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8,0x561,lbl_80322438); break;
    }
    unsigned int offset=(unsigned int)arg2;
    int format2=*(int *)((char *)arg0+0x118);
    if(offset) offset+=0x80000000;
    unsigned int end=0;
    switch(format2) {
    case 0: {
        u32 x=arg3-1;
        end=(x%14) + (offset*2) + ((x/14)*16) + 2;
        break;
    }
    case 25: end=offset+arg3-1; break;
    case 10: end=arg3+(offset>>1)-1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8,0x561,lbl_80322438); break;
    }
    unsigned short sh=start>>16, sl=start;
    unsigned short eh=end>>16, el=end;
    long i;
    char *entry=(char *)arg0+arg1*0x10;
    for(i=0; i<*(int *)((char *)arg0+0x108); i++, entry+=4) {
        void *voice=*(void **)(entry+0xC);
        if(voice) {
            unsigned int *flags=(unsigned int *)((char *)voice+0x1C);
            int lv=OSDisableInterrupts();
            *(unsigned short *)((char *)voice+0x1B4)=sh;
            *(unsigned short *)((char *)voice+0x1B6)=sl;
            if(!(*flags&0x800))*flags|=0x2000;
            OSRestoreInterrupts(lv);
            lv=OSDisableInterrupts();
            *(unsigned short *)((char *)voice+0x1B8)=eh;
            *(unsigned short *)((char *)voice+0x1BA)=el;
            if(!(*flags&0x800))*flags|=0x4000;
            OSRestoreInterrupts(lv);
            lv=OSDisableInterrupts();
            *(unsigned short *)((char *)voice+0x1B0)=0;
            if(!(*flags&0x800))*flags|=0x1000;
            OSRestoreInterrupts(lv);
        }
    }
    OSRestoreInterrupts(irq);
}
#pragma use_lmw_stmw off
extern "C" void SetVoiceType__Q46nw4hbm3snd6detail7AxVoiceFQ56nw4hbm3snd6detail7AxVoice9VoiceType(void *self, unsigned int type) {
    {
        int channelIndex;
        int groupIndex;
        unsigned char *groupPtr;
        unsigned char *slotPtr;
        /* Set the voice type on every AX voice in the (rowCount@0x104, colCount@0x108) voice grid. */
        groupPtr = (unsigned char *)self;
        groupIndex = 0;
        while (groupIndex < *(int *)((unsigned char *)self + 0x104)) {
            slotPtr = groupPtr;
            channelIndex = 0;
            while (channelIndex < *(int *)((unsigned char *)self + 0x108)) {
                void *voice = *(void **)(slotPtr + 0xC);
                if (voice != 0)
                    ((void (*)(void *, int))fn_80033538)(voice, (unsigned short)type);
                slotPtr += 4;
                channelIndex++;
            }
            groupPtr += 0x10;
            groupIndex++;
        }
    }
}
#pragma use_lmw_stmw reset
extern "C" void UpdateAxSrc__Q46nw4hbm3snd6detail7AxVoiceFb(void *arg0, int arg1) {
    unsigned char *self = (unsigned char *)arg0;
    int mode = arg1;
    float scale = (float)(*(int *)(self + 0x114));
    float ratio = (*(float *)(self + 0x184) * scale) / lbl_80560F40;
    float gain = lbl_80560F58;
    float max = lbl_80560F38;
    float min = lbl_80560F3C;
    int i = 0;
    int offset = 0;
    int j;
    unsigned char *src = self;
    short values[7];
    while (i < *(int *)(self + 0x108)) {
        float volume = *(float *)(src + 0x98);
        if (volume > max) volume = max;
        else if (volume < min) volume = min;
        if (mode != 0) {
            unsigned int sample = (unsigned int)(gain * ratio * volume);
            values[0] = (short)(sample >> 16);
            values[1] = (short)sample;
            values[2] = 0;
            values[3] = 0;
            values[4] = 0;
            values[5] = 0;
            values[6] = 0;
            unsigned char *channel = self + offset;
            for (j = 0; j < *(int *)(self + 0x104); j++) {
                fn_800339B0(*(void **)(channel + 0xc), values);
                channel += 0x10;
            }
        } else {
            unsigned char *channel = self + offset;
            for (j = 0; j < *(int *)(self + 0x104); j++) {
                fn_80033A34(*(void **)(channel + 0xc), ratio * volume);
                channel += 0x10;
            }
        }
        src += 0x1c; offset += 4; i++;
    }
}

extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void fn_80033918(void *, void *);
extern "C" void fn_800E68EC(void *arg0, int arg1, int arg2, void *arg3, int arg4) {
    unsigned char sp8[0x28];
    unsigned int message = (unsigned int)lbl_803221A8;
    void **entry;
    int i;
    if (arg1 >= 2)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)message, 0x434, (const char *)(message + 0x258));
    switch (arg2) {
    case 0:
        if (arg3 == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)message, 0x439, (const char *)(message + 0x2A0));
        memcpy(sp8, arg3, 0x20);
        *(u16 *)(sp8 + 0x20) = *(u16 *)((char *)arg3 + 0x20);
        *(u16 *)(sp8 + 0x22) = *(u16 *)((char *)arg3 + 0x22);
        *(u16 *)(sp8 + 0x24) = *(u16 *)((char *)arg3 + 0x24);
        *(u16 *)(sp8 + 0x26) = *(u16 *)((char *)arg3 + 0x26);
        break;
    case 10:
        memset(sp8, 0, 0x20);
        *(u16 *)(sp8 + 0x20) = 0x800;
        *(u16 *)(sp8 + 0x22) = 0;
        *(u16 *)(sp8 + 0x24) = 0;
        *(u16 *)(sp8 + 0x26) = 0;
        break;
    case 25:
        memset(sp8, 0, 0x20);
        *(u16 *)(sp8 + 0x20) = 0x100;
        *(u16 *)(sp8 + 0x22) = 0;
        *(u16 *)(sp8 + 0x24) = 0;
        *(u16 *)(sp8 + 0x26) = 0;
        break;
    }
    entry = (void **)((char *)arg0 + (arg1 << 4));
    for (i = 0; i < *(int *)((char *)arg0 + 0x108); i++) {
        fn_80033918(entry[3], sp8);
        entry = (void **)((char *)entry + 4);
    }
}

extern "C" void fn_800E6A44(void *arg0, int arg1, int arg2, void *arg3) {
    struct FileBase { char c; };
    const struct FileBase *file = (const struct FileBase *)lbl_803221A8;
    unsigned short mix[3];
    unsigned char *voice;
    int i;
    if (arg1 >= 2) {
        Panic__Q26nw4hbm2dbFPCciPCce(&file->c, 0x458, &file->c + 0x258);
    }
    if (arg2 == 0) {
        if (arg3 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(&file->c, 0x45C, &file->c + 0x2A0);
        }
        mix[0] = ((unsigned short *)arg3)[0];
        mix[1] = ((unsigned short *)arg3)[1];
        mix[2] = ((unsigned short *)arg3)[2];
    } else {
        mix[0] = 0;
        mix[1] = 0;
        mix[2] = 0;
    }
    i = 0;
    voice = (unsigned char *)arg0 + (arg1 << 4);
    while (i < *(int *)((unsigned char *)arg0 + 0x108)) {
        fn_80033AAC(*(void **)(voice + 0xC), mix);
        voice += 4;
        i++;
    }
}

extern "C" void fn_800337C4(void *, unsigned short *);
extern float lbl_80560F5C;
/* Update the volumes of every AX voice of this AxVoice (nw4hbm::snd::detail::AxVoice);
   the 0x10 bit of the update flags at self[0x123] asks for it.  The volume a column
   wants is the main volume (self+0x188) times the EmissionManager's engine factor
   (fn_800E310C) times the column's own volume (self+0x94 + column*0x1C), forced to
   0.0 while self[0x122] mutes it, and scaled to the 16-bit AX range by 32767.  Each
   voice is handed its start volume and the delta that ramps it to the target in 96
   mix frames; the ramp starts from the column's previous volume (self+0x18C[]) once
   the first AX voice is playing, and from the stored start volume (self+0x19C)
   before that.  Returns 1 while any voice is still ramping, 0 when they all match. */
extern "C" int fn_800E6B24(void *self) {
    float *prevColumnVolume;
    unsigned char *columnVolume;
    int columnOffset;
    unsigned char *slot;
    int ramping, column, row, volume, targetVolume, voiceActive;
    unsigned char *base = (unsigned char *)self;
    unsigned short axVolume[2];
    float masterVolume, columnTarget, volumeScale;
    masterVolume = lbl_80560F38;                    /* 1.0f */
    masterVolume *= *(float *)(base + 0x188);       /* main volume */
    ramping = 0;
    masterVolume *= fn_800E310C(Instance__15EmissionManagerFv());
    if (base[0x122] != 0) masterVolume = lbl_80560F3C;  /* muted: 0.0f */
    volumeScale = lbl_80560F5C;                     /* 32767.0f */
    columnVolume = base;
    prevColumnVolume = (float *)(base + 0x18c);
    column = 0; columnOffset = 0;
    while (column < *(int *)(base + 0x108)) {       /* columns of voices */
        columnTarget = masterVolume * *(float *)(columnVolume + 0x94);
        slot = base + columnOffset;
        row = 0;
        while (row < *(int *)(base + 0x104)) {      /* voices per column */
            if (base[0x121] == 0) {
                /* Is the first AX voice already playing? */
                unsigned int interruptState = OSDisableInterrupts();
                void *axVoice = *(void **)(base + 0xC);
                if (axVoice == 0) {
                    OSRestoreInterrupts(interruptState);
                    voiceActive = 0;
                } else {
                    voiceActive = (*(unsigned short *)((unsigned char *)axVoice + 0x148) - 1) == 0;
                    OSRestoreInterrupts(interruptState);
                }
            } else {
                goto normal_volume;
            }
            if (!voiceActive) {
normal_volume:
                volume = (int)(volumeScale * (columnTarget * *(float *)(base + 0x19C)));
                targetVolume = (int)(volumeScale * (columnTarget * *(float *)(base + 0x1A0)));
            } else {
                /* Ramp from where this column's volume was last time. */
                volume = (int)(volumeScale * (*prevColumnVolume * *(float *)(base + 0x19C)));
                targetVolume = (int)(volumeScale * (columnTarget * *(float *)(base + 0x1A0)));
            }
            axVolume[0] = (unsigned short)volume;
            axVolume[1] = ((unsigned short)targetVolume - (unsigned short)volume) / 96;
            fn_800337C4(*(void **)(slot + 0xC), axVolume);  /* AXSetVoiceVolume */
            if ((unsigned short)targetVolume != (unsigned short)volume) ramping = 1;
            slot += 0x10; row++;
        }
        *prevColumnVolume = columnTarget; prevColumnVolume++; columnVolume += 0x1c; columnOffset += 4; column++;
    }
    if (base[0x121] == 0) {
        unsigned int interruptState = OSDisableInterrupts();
        void *axVoice = *(void **)(base + 0xC);
        if (axVoice == 0) {
            OSRestoreInterrupts(interruptState);
            voiceActive = 0;
        } else {
            voiceActive = (*(unsigned short *)((unsigned char *)axVoice + 0x148) - 1) == 0;
            OSRestoreInterrupts(interruptState);
        }
        if (voiceActive != 0) goto done;
    }
    base[0x121] = 0;    /* the first volume update has happened */
done:
    *(float *)(base + 0x19c) = *(float *)(base + 0x1a0);  /* ramp-from = ramp-to */
    return ramping;
}

extern "C" void CalcAXPBMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP8_AXPBMIX(void *, int, int, void *);
extern "C" void CalcAXPBRMTMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP11_AXPBRMTMIX(void *, int, int, void *);
extern "C" void fn_80033584(void *, void *);
extern "C" void fn_80033C8C(void *, int);
extern "C" void fn_80033CD8(void *, void *);
extern "C" void UpdateAxMix__Q46nw4hbm3snd6detail7AxVoiceFv(void *self) {
    char axMix[0x30];
    char axRmtMix[0x20];
    char *rowBase = (char *)self;
    char *slot;
    int rowIdx = 0;
    int slotIdx;
    /* Recalculate and apply main/aux DSP mix and (when enabled) remote mix for each AX voice slot. */
    while (rowIdx < *((int *)((char *)self + 0x104))) {
        slot = rowBase;
        slotIdx = 0;
        while (slotIdx < *((int *)((char *)self + 0x108))) {
            CalcAXPBMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP8_AXPBMIX(self, rowIdx, slotIdx, axMix);
            fn_80033584(*((void **)(slot + 0xC)), axMix);
            if (*((unsigned int *)((char *)self + 0x13C)) <= 1) {
                fn_80033C8C(*((void **)(slot + 0xC)), 0);
            } else {
                CalcAXPBRMTMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP11_AXPBRMTMIX(self, rowIdx, slotIdx, axRmtMix);
                fn_80033C8C(*((void **)(slot + 0xC)), 1);
                fn_80033CD8(*((void **)(slot + 0xC)), axRmtMix);
            }
            slot += 4;
            slotIdx++;
        }
        rowBase += 0x10;
        rowIdx++;
    }
}

extern "C" void AXGetLpfCoefs(unsigned short, unsigned short *, unsigned short *);
extern "C" unsigned short CalcLpfFreq__Q46nw4hbm3snd6detail4UtilFf(float);
extern "C" void fn_80033B0C(void *, short *);
extern "C" void fn_80033B74(void *, unsigned short, unsigned short);
extern "C" void UpdateAxLpf__Q46nw4hbm3snd6detail7AxVoiceFv(char *self) {
    char *channel = self;
    int channelIndex = 0;
    int channelOffset = 0;
    short zero = 0;
    short one = 1;
    int inner;
    char *entry;
    unsigned short localCoefs[10];
    unsigned short rate;

    while (channelIndex < *(int *)(self + 0x108)) {
        rate = CalcLpfFreq__Q46nw4hbm3snd6detail4UtilFf(
            *(float *)(self + 0x138) + *(float *)(channel + 0xa8));
        if (rate >= 0x3e80) {
            localCoefs[8] = zero;
            localCoefs[9] = zero;
            entry = (char *)((unsigned int)self + channelOffset);
            inner = 0;
            while (inner < *(int *)(self + 0x104)) {
                fn_80033B0C(*(void **)(entry + 0xc), (short *)&localCoefs[8]);
                entry += 0x10;
                inner++;
            }
        } else if (*(unsigned short *)(*(char **)(self + 0xc) + 0x1fc) == 1) {
            AXGetLpfCoefs(rate, &localCoefs[1], &localCoefs[0]);
            entry = (char *)((unsigned int)self + channelOffset);
            inner = 0;
            while (inner < *(int *)(self + 0x104)) {
                fn_80033B74(*(void **)(entry + 0xc), localCoefs[1], localCoefs[0]);
                entry += 0x10;
                inner++;
            }
        } else {
            localCoefs[4] = one;
            localCoefs[5] = zero;
            AXGetLpfCoefs(rate, &localCoefs[6], &localCoefs[7]);
            entry = (char *)((unsigned int)self + channelOffset);
            inner = 0;
            while (inner < *(int *)(self + 0x104)) {
                fn_80033B0C(*(void **)(entry + 0xc), (short *)&localCoefs[4]);
                entry += 0x10;
                inner++;
            }
        }
        channel += 0x1c;
        channelOffset += 4;
        channelIndex++;
    }
}

extern "C" unsigned int __mulhwu(unsigned int, unsigned int);
extern "C" int GetDspAddressBySample__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(const void* arg0, unsigned long arg1, int arg2) {
    register unsigned long base = (unsigned long)arg0;
    if (base != 0) base += 0x80000000UL;
    int result = 0;
    switch (arg2) {
    case 0: {
        register unsigned long sample = arg1;
        register unsigned long doubled = base << 1;
        register unsigned long q = __mulhwu(0x24924925U, (unsigned int)sample);
        register unsigned long block = q + ((sample - q) >> 1);
        unsigned long rem = sample - ((block >> 3) * 14U);
        result = (int)(rem + doubled);
        result += (int)((block << 1) & 0xFFFFFFF0UL);
        result += 2;
        break;
    }
    case 25: result = (int)(base + arg1); break;
    case 10: result = (int)((base >> 1) + arg1); break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438); break;
    }
    return result;
}

/* Convert a DSP buffer address to a sample count for the given AxVoice format (0=ADPCM, 10=16-bit PCM, 25=8-bit PCM). */
extern "C" int GetSampleByDspAddress__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(const void *dspAddress, unsigned int sampleAddress, int format) {
    unsigned int address = (unsigned int)dspAddress;
    if (address != 0) address += 0x80000000;
    int result = 0;
    switch (format) {
    case 0: { unsigned int delta = sampleAddress - address * 2; result = ((delta & 15) + ((delta >> 4) * 14)) - 2; break; }
    case 25: result = sampleAddress - address; break;
    case 10: result = sampleAddress - (address >> 1); break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x583, lbl_80322438); break;
    }
    return result;
}

extern "C" unsigned int GetSampleByByte__Q46nw4hbm3snd6detail7AxVoiceFUlQ56nw4hbm3snd6detail7AxVoice6Format(unsigned int byteCount, int format) {
    /* Convert a byte count to a sample count for an AxVoice format (0: ADPCM, 10: 16-bit, 25: 8-bit); panic on unknown format. */
    int sampleCount = 0;
    switch (format) {
    case 0:
        sampleCount = (byteCount >> 3) * 14;
        if ((byteCount & 7) != 0) sampleCount += (((int)(byteCount & 7) - 1) * 2);
        break;
    case 25: sampleCount = byteCount; break;
    case 10: sampleCount = byteCount >> 1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x5A4, lbl_80322438); break;
    }
    return sampleCount;
}

extern float lbl_80560F38, lbl_80560F3C, lbl_80560F54, lbl_80560F60, lbl_80560F64, lbl_80560F68, lbl_80560F6C, lbl_80560F70, lbl_80560F74, lbl_80560F78;
#pragma fp_contract off
void nw4r::snd::detail::Voice::TransformDpl2Pan(float *out0, float *out1, float a, float b) {
    float d = b - lbl_80560F38;
    float aa = __fabsf(a);
    float ad = __fabsf(d);
    if (aa <= ad) {
        if (d <= lbl_80560F3C) {
            *out0 = a; *out1 = lbl_80560F60 + lbl_80560F64 * d;
        } else { *out0 = lbl_80560F68 * a; *out1 = lbl_80560F60 + lbl_80560F6C * d; }
    } else if (a >= lbl_80560F3C) {
        if (d <= lbl_80560F3C) {
            *out0 = (lbl_80560F70 + lbl_80560F74 * (-d / a)) * aa;
            *out1 = lbl_80560F60 + lbl_80560F54 * d + lbl_80560F64 * a;
        } else {
            *out0 = (lbl_80560F70 + lbl_80560F78 * (-d / a)) * aa;
            *out1 = lbl_80560F60 + lbl_80560F6C * a;
        }
    } else if (d <= lbl_80560F3C) {
        *out0 = (lbl_80560F74 * (-d / a) - lbl_80560F70) * aa;
        *out1 = lbl_80560F60 + lbl_80560F54 * d - lbl_80560F6C * a;
    } else {
        *out0 = (lbl_80560F78 * (-d / a) - lbl_80560F70) * aa;
        *out1 = lbl_80560F60 + lbl_80560F6C * -a;
    }
    *out1 += lbl_80560F38;
}

extern "C" void CalcAXPBMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP8_AXPBMIX(void *arg0, int arg1, int arg2, void *arg3) {
    float f22 = lbl_80560F38;
    float f21 = f22;
    float f23 = f22;
    float f20 = f22;
    float f19 = f22;
    float f31 = f22;
    float f18 = f22;
    float f17 = f22;
    float f30 = f22;
    float f29 = f22;
    float f28 = f22;
    float f27 = f22;
    float spC, sp8;
    char *self = (char *)arg0;
    unsigned short *out = (unsigned short *)arg3;
    int mode = fn_800E394C((int *)Instance__15EmissionManagerFv());
    switch (mode) {
    case 3:
    case 0:
        f23 = lbl_80560F3C; f31 = lbl_80560F3C; f30 = lbl_80560F3C; f27 = lbl_80560F3C;
        break;
    default: break;
    }
    float f24;
    if ((*(int *)(self + 0x13c) & 1) != 0) f24 = lbl_80560F38 * *(float *)(self + 0x140);
    else f24 = lbl_80560F3C;
    mode = fn_800E394C((int *)Instance__15EmissionManagerFv());
    switch (mode) {
    case 3:
    case 0:
        f22 *= f24; f21 *= f24; f20 *= f24; f19 *= f24; f18 *= f24; f17 *= f24;
        f29 = (float)f29 * f24; f28 = (float)f28 * f24;
        break;
    case 1:
        f22 *= f24; f21 *= f24; f23 = (float)f23 * f24; f20 *= f24; f19 *= f24;
        f31 = (float)f31 * f24; f18 *= f24; f17 *= f24; f30 = (float)f30 * f24;
        f29 = (float)f29 * f24; f28 = (float)f28 * f24; f27 = (float)f27 * f24;
        break;
    case 2:
        f22 *= f24; f21 *= f24; f23 = (float)f23 * f24; f29 = (float)f29 * f24;
        f20 *= f24; f19 *= f24; f31 = (float)f31 * f24; f28 = (float)f28 * f24;
        f18 *= f24; f17 *= f24; f30 = (float)f30 * f24; f27 = (float)f27 * f24;
        break;
    default: break;
    }
    float f24b = lbl_80560F3C;
    if (*(int *)(self + 0x104) == 2) {
        if (arg1 == 0) f24b = lbl_80560F50;
        if (arg1 == 1) f24b = lbl_80560F38;
    }
    mode = fn_800E394C((int *)Instance__15EmissionManagerFv());
    switch (mode) {
    case 2: {
        char *r6 = self + arg2 * 0x1c;
        float a = f24b + (*(float *)(self + 0x128) + *(float *)(self + 0x130)) + *(float *)(r6 + 0x9c);
        float b = (*(float *)(self + 0x12c) + *(float *)(self + 0x134)) + *(float *)(r6 + 0xa0);
        ((nw4r::snd::detail::Voice *)self)->TransformDpl2Pan(&spC, &sp8, a, b);
        break;
    }
    case 3: spC = lbl_80560F3C; sp8 = lbl_80560F3C; break;
    default: {
        char *r6 = self + arg2 * 0x1c;
        spC = f24b + (*(float *)(self + 0x128) + *(float *)(self + 0x130)) + *(float *)(r6 + 0x9c);
        sp8 = (*(float *)(self + 0x12c) + *(float *)(self + 0x134)) + *(float *)(r6 + 0xa0);
        break;
    }
    }
    float t24 = CalcPanRatio__Q46nw4hbm3snd6detail4UtilFf(spC);
    float t26 = CalcPanRatio__Q46nw4hbm3snd6detail4UtilFf(-spC);
    float t25 = CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(lbl_80560F7C);
    mode = fn_800E394C((int *)Instance__15EmissionManagerFv());
    switch (mode) {
    case 3:
    case 0:
        f22 *= t24; f21 *= t26; f20 *= t24; f19 *= t26; f18 *= t24; f17 *= t26;
        f29 = (float)f29 * t24; f28 = (float)f28 * t26;
        break;
    case 1:
        f22 *= t24; f21 *= t26; f23 = (float)f23 * t25; f20 *= t24; f19 *= t26;
        f31 = (float)f31 * t25; f18 *= t24; f17 *= t26; f30 = (float)f30 * t25;
        f29 = (float)f29 * t24; f28 = (float)f28 * t26; f27 = (float)f27 * t25;
        break;
    case 2:
        f22 *= t24; f21 *= t26; f23 = (float)f23 * t24; f29 = (float)f29 * t26;
        f20 *= t24; f19 *= t26; f31 = (float)f31 * t24; f28 = (float)f28 * t26;
        f18 *= t24; f17 *= t26; f30 = (float)f30 * t24; f27 = (float)f27 * t26;
        break;
    default: break;
    }
    float s25 = CalcSurroundPanRatio__Q46nw4hbm3snd6detail4UtilFf(sp8);
    float s26 = CalcSurroundPanRatio__Q46nw4hbm3snd6detail4UtilFf(lbl_80560F54 - sp8);
    mode = fn_800E394C((int *)Instance__15EmissionManagerFv());
    switch (mode) {
    case 0: break;
    case 1:
        f22 *= s25; f21 *= s25; f23 = (float)f23 * s26; f20 *= s25; f19 *= s25;
        f31 = (float)f31 * s26; f18 *= s25; f17 *= s25; f30 = (float)f30 * s26;
        f29 = (float)f29 * s25; f28 = (float)f28 * s25; f27 = (float)f27 * s26;
        break;
    case 2:
        f22 *= s25; f21 *= s25; f23 = (float)f23 * s26; f29 = (float)f29 * s26;
        f20 *= s25; f19 *= s25; f31 = (float)f31 * s26; f28 = (float)f28 * s26;
        f18 *= s25; f17 *= s25; f30 = (float)f30 * s26; f27 = (float)f27 * s26;
        break;
    default: break;
    }
    float v24 = lbl_80560F38;
    float v25 = *(float *)(self + 0x144);
    float tmp = *(float *)(self + 0x148) + *(float *)(self + arg2 * 0x1c + 0xa4);
    if (tmp > v24) {} else { v24 = lbl_80560F3C; if (tmp >= v24) v24 = tmp; }
    float v26 = *(float *)(self + 0x14c);
    float v16 = *(float *)(self + 0x150);
    mode = fn_800E394C((int *)Instance__15EmissionManagerFv());
    switch (mode) {
    case 3:
    case 0:
        f22 *= v25; f21 *= v25; f20 *= v24; f19 *= v24; f18 *= v26; f17 *= v26;
        f29 = (float)f29 * v16; f28 = (float)f28 * v16;
        break;
    case 1:
        f22 *= v25; f21 *= v25; f23 = (float)f23 * v25; f20 *= v24; f19 *= v24;
        f31 = (float)f31 * v24; f18 *= v26; f17 *= v26; f30 = (float)f30 * v26;
        f29 = (float)f29 * v16; f28 = (float)f28 * v16; f27 = (float)f27 * v16;
        break;
    case 2:
        f22 *= v25; f21 *= v25; f23 = (float)f23 * v25; f29 = (float)f29 * v25;
        f20 *= v24; f19 *= v24; f31 = (float)f31 * v24; f28 = (float)f28 * v24;
        f18 *= v26; f17 *= v26; f30 = (float)f30 * v26; f27 = (float)f27 * v26;
        break;
    default: break;
    }
    unsigned int c;
    c = (unsigned int)(lbl_80560F80 * f22); out[0] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * f21); out[2] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * (float)f23); out[0x10] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * f20); out[4] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * f19); out[6] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * (float)f31); out[0x12] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * f18); out[8] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * f17); out[0x0a] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * (float)f30); out[0x14] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * (float)f29); out[0x0c] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * (float)f28); out[0x0e] = c >= 0xffff ? 0xffff : (unsigned short)c;
    c = (unsigned int)(lbl_80560F80 * (float)f27); out[0x16] = c >= 0xffff ? 0xffff : (unsigned short)c;
    out[1] = 0; out[3] = 0; out[0x11] = 0; out[5] = 0; out[7] = 0; out[0x13] = 0;
    out[9] = 0; out[0x0b] = 0; out[0x15] = 0; out[0x0d] = 0; out[0x0f] = 0; out[0x17] = 0;
}

extern float lbl_80560F3C, lbl_80560F80;
extern "C" void CalcAXPBRMTMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP11_AXPBRMTMIX(void* self, int a, int b, void* out) {
    unsigned short* mix=(unsigned short*)out;
    float mainVol[4], auxVol[4];
    char* voice=(char*)self;
    for (int i=0;i<4;i++) {
        mainVol[i]=lbl_80560F38;
        auxVol[i]=lbl_80560F38;
        float volume;
        if (*(volatile u32*)((char*)self+0x13c) & (2<<i))
            volume=lbl_80560F38 * *(float*)(voice+0x154);
        else
            volume=lbl_80560F3C;
        mainVol[i]*=volume;
        auxVol[i]*=volume;
        float left=*(float*)(voice+0x164);
        float right=*(float*)(voice+0x174);
        mainVol[i]*=left;
        auxVol[i]*=right;
        voice+=4;
    }
    mix[0] = (u32)(32768.0f*mainVol[0]) < 0xffff ? (u32)(32768.0f*mainVol[0]) : 0xffff;
    mix[2] = 0;
    u32 v=(u32)(32768.0f*mainVol[1]);
    mix[4] = v < 0xffff ? v : 0xffff;
    mix[6] = 0;
    v=(u32)(32768.0f*mainVol[2]);
    mix[8] = v < 0xffff ? v : 0xffff;
    mix[10] = 0;
    v=(u32)(32768.0f*mainVol[3]);
    mix[12] = v < 0xffff ? v : 0xffff;
    mix[14] = 0;
    mix[1]=0; mix[3]=0; mix[5]=0; mix[7]=0;
    mix[9]=0; mix[11]=0; mix[13]=0; mix[15]=0;
}

extern "C" void InvalidateWaveData__Q46nw4hbm3snd6detail7AxVoiceFPCvPCv(void *self, const void *start, const void *end) {
    unsigned int irq = OSDisableInterrupts();
    if (*((u8 *)self + 0x11C) != 0) {
        char *voice = (char *)self;
        int found = 0;
        int count = *(int *)((char *)self + 0x104);
        int i;
        for (i = count; i > 0; --i) {
            void *address = *(void **)(voice + 0x2C);
            if (start > address || address > end) break;
            found = 1;
            voice += 0x34;
        }
        if (found != 0) {
            unsigned int lock = OSDisableInterrupts();
            if (*((u8 *)self + 0x11E) != 0) {
                unsigned int nested = OSDisableInterrupts();
                void *manager = *(void **)((char *)self + 0xC);
                int active;
                if (manager == 0) {
                    OSRestoreInterrupts(nested);
                    active = 0;
                } else {
                    unsigned short voices = *(unsigned short *)((char *)manager + 0x148);
                    active = (voices == 1);
                    OSRestoreInterrupts(nested);
                }
                if (active != 0) {
                    char *row = (char *)self;
                    int outer;
                    for (outer = 0; outer < *(int *)((char *)self + 0x104); outer++) {
                        char *slot = row;
                        int inner;
                        for (inner = 0; inner < *(int *)((char *)self + 0x108); inner++) {
                            void *item = *(void **)(slot + 0xC);
                            if (item != 0) AXSetVoiceState(item, 0);
                            slot += 4;
                        }
                        row += 0x10;
                    }
                }
                *((u8 *)self + 0x11E) = 0;
            }
            *((u8 *)self + 0x120) = 0;
            *((u8 *)self + 0x11F) = 0;
            *((u8 *)self + 0x11D) = 0;
            OSRestoreInterrupts(lock);
            void (*callback)(void *, int, void *) = *(void (**)(void *, int, void *))((char *)self + 0x10C);
            if (callback != 0) callback(self, 1, *(void **)((char *)self + 0x110));
        }
    }
    OSRestoreInterrupts(irq);
}

extern "C" void fn_800E80B4(void) {

}

extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *self, const void *bank);
extern "C" void *fn_800E80B8(void *arg0, const void *arg1) {
    __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(arg0, arg1);
    *(int *)((char *)arg0 + 0xC) = 0;
    return arg0;
}

extern "C" int fn_800E80F0(int arg0, int arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

void *nw4hbm::snd::detail::Bank::NoteOn(const nw4hbm::snd::detail::NoteOnInfo &noteInfo) const {
    unsigned char inst[0x10];
    unsigned char wave[0x90];
    void *bank = (void *)this;
    void *channel;
    if (!ReadInstInfo__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8InstInfoiii(bank, inst,
        noteInfo.unk_0, noteInfo.unk_4, noteInfo.unk_8)) return 0;
    if (!ReadWaveParam__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8WaveDataiPCv(bank, wave,
        *(int *)inst, *(void **)((char *)bank + 0xC))) return 0;
    int voices = 2;
    int waveVoices = wave[2];
    if (waveVoices <= 2) voices = waveVoices;
    channel = AllocChannel__Q46nw4hbm3snd6detail7ChannelFiiiPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(
        voices, noteInfo.unk_18, noteInfo.unk_14, noteInfo.unk_1C, noteInfo.unk_20);
    if (channel == 0) return 0;
    *(int *)((char *)channel + 0xCC) = noteInfo.unk_4;
    *(int *)((char *)channel + 0xD0) = inst[8];
    float level = (float)noteInfo.unk_8 / lbl_80560F88;
    float levelSquared = level * level;
    float multiplier = (float)inst[0xA] / lbl_80560F88;
    *(float *)((char *)channel + 0xB4) = levelSquared * multiplier;
    *(float *)((char *)channel + 0xC0) = *(float *)(inst + 0xC);
    SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, inst[4]);
    SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, inst[5]);
    SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, inst[6]);
    SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, inst[7]);
    *(float *)((char *)channel + 0xB8) =
        ((float)((int)inst[9] - 0x40) / lbl_80560F8C) +
        ((float)noteInfo.unk_10 / lbl_80560F8C);
    *(float *)((char *)channel + 0xBC) = lbl_80560F90;
    Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(channel, wave, noteInfo.unk_C);
    return channel;
}

extern const char lbl_803224F0[];
extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *self, const void *bank) {
    register const char *messages = lbl_803224F0;
    *(void **)self = 0;
    *(void **)((char *)self + 4) = 0;
    *(void **)((char *)self + 8) = 0;
    if (bank == 0) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x58, messages + 0xB8);
    unsigned int magic = *(unsigned int *)bank;
    if (magic != 0x52424E4B) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x36, messages + 0x14);
    magic = *(unsigned int *)bank;
    if (magic != 0x52424E4B) return self;
    unsigned short version = *(unsigned short *)((char *)bank + 6);
    if (version < 0x100) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x3E, messages + 0x60);
    version = *(unsigned short *)((char *)bank + 6);
    if (version < 0x100) return self;
    if (version > 0x101) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x44, messages + 0x60);
    version = *(unsigned short *)((char *)bank + 6);
    if (version < 0x100 || version > 0x101) return self;
    *(const void **)self = bank;
    const char *data = (const char *)bank + *(unsigned int *)((char *)bank + 0x10);
    *(const char **)((char *)self + 4) = data;
    if (*(unsigned int *)data != 0x44415441) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x61, messages + 0xE4);
    const char *wave = (const char *)bank + *(unsigned int *)((char *)bank + 0x18);
    *(const char **)((char *)self + 8) = wave;
    if (*(unsigned int *)wave != 0x57415645) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x65, messages + 0x13C);
    return self;
}

extern "C" int ReadInstInfo__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8InstInfoiii(void *arg0, void *arg1, int arg2, int arg3, int arg4) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern void *fn_800E8690(void *, void *, int);
    extern unsigned int GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(unsigned char, unsigned int, const void *);
    extern const char lbl_803224F0[];
    extern const char lbl_80322760[];
    extern const char lbl_80559830;
    extern float lbl_80560FA8;
    const char *base = lbl_803224F0;
    char *ref;
    char *entry;
    unsigned int address;

    if (arg1 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x7B, base + 0x194);
    if (*(void **)arg0 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x7C, base + 0x1C0);
    if (*(void **)arg0 == 0)
        return 0;
    if (arg2 < 0 || arg2 >= *(int *)(*(char **)((char *)arg0 + 4) + 8))
        return 0;
    entry = *(char **)((char *)arg0 + 4) + arg2 * 8;
    ref = entry + 0xC;
    if ((unsigned char)entry[0xD] == 4)
        return 0;
    if ((unsigned char)entry[0xD] != 1) {
        ref = (char *)fn_800E8690(arg0, ref, arg3);
        if (ref == 0)
            return 0;
    }
    if ((unsigned char)ref[1] == 4)
        return 0;
    if ((unsigned char)ref[1] != 1) {
        ref = (char *)fn_800E8690(arg0, ref, arg4);
        if (ref == 0)
            return 0;
    }
    if ((unsigned char)ref[1] != 1)
        return 0;
    base = *(char **)((char *)arg0 + 4) + 8;
    if ((unsigned char)ref[1] != 1)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559830, 0x70, lbl_80322760);
    address = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv((unsigned char)ref[0], *(unsigned int *)(ref + 4), base);
    if (address == 0)
        return 0;
    if (*(int *)address < 0)
        return 0;
    *(int *)arg1 = *(int *)address;
    char *hdr = *(char **)arg0;
    ((char *)arg1)[4] = ((char *)address)[4];
    ((char *)arg1)[5] = ((char *)address)[5];
    ((char *)arg1)[6] = ((char *)address)[6];
    ((char *)arg1)[7] = ((char *)address)[7];
    ((char *)arg1)[8] = ((char *)address)[0xC];
    ((char *)arg1)[9] = ((char *)address)[0xE];
    if (*(unsigned short *)(hdr + 6) == 0x101) {
        ((char *)arg1)[0xA] = ((char *)address)[0xD];
        *(float *)((char *)arg1 + 0xC) = *(float *)((char *)address + 0x10);
    } else {
        float f = lbl_80560FA8;
        ((char *)arg1)[0xA] = 0x7F;
        *(float *)((char *)arg1 + 0xC) = f;
    }
    return 1;
}

extern "C" void *fn_800E8690(void *arg0, void *arg1, int arg2) {
    int type = *((unsigned char *)arg1 + 1);
    unsigned char *data;
    unsigned int address;
    int i;
    switch (type) {
    case 0:
        return 0;
    case 1:
        return arg1;
    case 2: {
        unsigned int base = *(unsigned int *)((char *)arg0 + 4) + 8;
        if (type != 2) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559820, 0x71, lbl_80322708);
        address = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*(unsigned char *)arg1, *(unsigned int *)((char *)arg1 + 4), (const void *)base);
        data = (unsigned char *)address;
        if (!data) return 0;
        i = 0;
        goto body;
    inc:
        i++;
        if (i < data[0]) goto body;
        return 0;
    body:
        if (arg2 <= data[i + 1]) {
            unsigned int off = (data[0] + 4) & ~3;
            return (void *)(off + (unsigned int)(data + i * 8));
        }
        goto inc;
    }
    case 3: {
        unsigned int base = *(unsigned int *)((char *)arg0 + 4) + 8;
        if (type != 3) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559828, 0x72, lbl_80322734);
        address = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*(unsigned char *)arg1, *(unsigned int *)((char *)arg1 + 4), (const void *)base);
        data = (unsigned char *)address;
        if (!data) return 0;
        if (arg2 < data[0] || arg2 > data[1]) return 0;
        return data + (arg2 - data[0]) * 8 + 4;
    }
    default:
        return 0;
    }
}

extern "C" unsigned int GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(unsigned char, unsigned int, const void *);
extern "C" void fn_800FEC1C(void *, void *);
extern "C" void ReadWaveParam__Q46nw4hbm3snd6detail14WaveFileReaderCFPQ46nw4hbm3snd6detail8WaveDataPCv(void *, void *, const void *);
extern "C" const char lbl_803224F0[], lbl_803226B0[], lbl_803226DC[];
extern "C" char lbl_80559818;
namespace nw4hbm { namespace snd { namespace detail {
class WaveData;
class BankFileReader {
public:
    void *ReadWaveParam(WaveData *, int, const void *) const;
};
}}}
#pragma push
// Reads a wave parameter entry from the bank file by index into waveData, resolving the
// referenced wave data and delegating the read to a temporary WaveFileReader.
void *nw4hbm::snd::detail::BankFileReader::ReadWaveParam(WaveData *waveData, int waveIndex, const void *waveFile) const {
    unsigned int count;
    void *bank;
    void *entry;
    void *base;
    unsigned int data;
    unsigned char type;
    char pad[8];
    if (*(void **)this == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803224F0, 0x107, lbl_803226B0);
    if (*(void **)this == 0) return 0;
    bank = *(void **)((char *)this + 8);
    if (bank == 0) return 0;
    count = *(unsigned int *)((char *)bank + 8);
    base = (char *)bank + 8;
    if ((unsigned int)waveIndex >= count) return 0;
    entry = (char *)bank + (waveIndex << 3);
    if (*((unsigned char *)entry + 0xd)) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559818, 0x6f, lbl_803226DC);
    type = *((unsigned char *)entry + 0xc);
    data = *(unsigned int *)((char *)entry + 0x10);
    bank = (void *)(unsigned int)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(type, data, base);
    if (bank == 0) return 0;
    fn_800FEC1C(pad, bank);
    return ((void *(*)(void *, void *, const void *))ReadWaveParam__Q46nw4hbm3snd6detail14WaveFileReaderCFPQ46nw4hbm3snd6detail8WaveDataPCv)(pad, waveData, waveFile);
}
#pragma pop

extern void __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *);
extern char lbl_80322880[];
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void *arg0) {
    /* Construct BasicSound: set vtable and initialize runtime fields to defaults. */
    float zeroFloat = lbl_80560FB0;
    void *vtable = &lbl_80322880;
    int zero = 0;
    int minusOne = -1;

    *(void **)arg0 = vtable;
    *(int *)((char *)arg0 + 4) = zero;
    *(int *)((char *)arg0 + 8) = zero;
    *(int *)((char *)arg0 + 0xC) = zero;
    *(int *)((char *)arg0 + 0x10) = zero;
    *(int *)((char *)arg0 + 0x14) = zero;
    *(int *)((char *)arg0 + 0x18) = zero;
    *(int *)((char *)arg0 + 0x1C) = zero;
    *(int *)((char *)arg0 + 0x20) = zero;
    *(int *)((char *)arg0 + 0x24) = zero;
    *(float *)((char *)arg0 + 0x44) = zeroFloat;
    *(float *)((char *)arg0 + 0x48) = zeroFloat;
    *(int *)((char *)arg0 + 0x4C) = zero;
    *(int *)((char *)arg0 + 0x50) = zero;
    *(float *)((char *)arg0 + 0x54) = zeroFloat;
    *(float *)((char *)arg0 + 0x58) = zeroFloat;
    *(int *)((char *)arg0 + 0x5C) = zero;
    *(int *)((char *)arg0 + 0x60) = zero;
    *(int *)((char *)arg0 + 0x78) = minusOne;
    *(float *)((char *)arg0 + 0x7C) = zeroFloat;
    *(float *)((char *)arg0 + 0x80) = zeroFloat;
    *(int *)((char *)arg0 + 0x84) = zero;
    *(int *)((char *)arg0 + 0x88) = zero;
    *(int *)((char *)arg0 + 0xB8) = zero;
    *(int *)((char *)arg0 + 0xBC) = zero;
    *(int *)((char *)arg0 + 0xC0) = zero;
    *(int *)((char *)arg0 + 0xC4) = zero;
    *(int *)((char *)arg0 + 0xC8) = zero;
    *(int *)((char *)arg0 + 0xCC) = zero;
    *(int *)((char *)arg0 + 0xD0) = zero;
    *(int *)((char *)arg0 + 0xD4) = zero;
}

extern "C" void InitParam__Q44nw4r3snd6detail10BasicSoundFv(void *self) {
    extern float lbl_80560FB4;
    float base = lbl_80560FB0;
    float initialTarget = lbl_80560FB4;
    int zero = 0;
    int current;
    int total;
    float baseAgain = 0;
    float finalTarget = 0;
    int one = 0;
    *((unsigned char *)self + 0x67) = zero;
    *((unsigned char *)self + 0x68) = zero;
    *((unsigned char *)self + 0x64) = zero;
    *((unsigned char *)self + 0x65) = zero;
    *((unsigned char *)self + 0x66) = zero;
    *((unsigned char *)self + 0x69) = zero;
    *(int *)((char *)self + 0x6c) = zero;
    *(int *)((char *)self + 0x70) = zero;
    *(float *)((char *)self + 0x44) = base;
    *(float *)((char *)self + 0x48) = base;
    *(int *)((char *)self + 0x4c) = zero;
    *(int *)((char *)self + 0x50) = zero;
    *(float *)((char *)self + 0x54) = initialTarget;
    *(float *)((char *)self + 0x58) = initialTarget;
    *(int *)((char *)self + 0x5c) = zero;
    *(int *)((char *)self + 0x60) = zero;
    current = *(int *)((char *)self + 0x50);
    total = *(int *)((char *)self + 0x4c);
    if (current >= total) {
        base = *(float *)((char *)self + 0x44);
    } else {
        base += (float)current * (*(float *)((char *)self + 0x48) - *(float *)((char *)self + 0x44)) / (float)total;
    }
    finalTarget = lbl_80560FB4;
    zero = 0;
    baseAgain = lbl_80560FB0;
    one = 1;
    *(float *)((char *)self + 0x44) = base;
    *(float *)((char *)self + 0x48) = finalTarget;
    *(int *)((char *)self + 0x4c) = one;
    *(int *)((char *)self + 0x50) = zero;
    *(float *)((char *)self + 0x8c) = finalTarget;
    *(float *)((char *)self + 0x98) = finalTarget;
    *(float *)((char *)self + 0x90) = baseAgain;
    *(float *)((char *)self + 0x94) = baseAgain;
    *(float *)((char *)self + 0x7c) = finalTarget;
    *(float *)((char *)self + 0x80) = finalTarget;
    *(int *)((char *)self + 0x84) = zero;
    *(int *)((char *)self + 0x88) = zero;
    *(int *)((char *)self + 0xa0) = one;
    *((unsigned char *)self + 0x9c) = zero;
    *(float *)((char *)self + 0xa4) = finalTarget;
    *(float *)((char *)self + 0xa8) = finalTarget;
    *(float *)((char *)self + 0xac) = finalTarget;
    *(float *)((char *)self + 0xb0) = finalTarget;
    *(float *)((char *)self + 0xb4) = finalTarget;
    *(float *)((char *)self + 0x28) = finalTarget;
    *(float *)((char *)self + 0x2c) = finalTarget;
    *(float *)((char *)self + 0x30) = baseAgain;
    *(float *)((char *)self + 0x34) = baseAgain;
    *(float *)((char *)self + 0x38) = baseAgain;
    *(float *)((char *)self + 0x3c) = baseAgain;
    *(int *)((char *)self + 0x40) = zero;
}

extern "C" void fn_800E8ADC(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x65) == 0)
        *(unsigned char *)((char *)arg0 + 0x64) = 1;
}

extern "C" void Stop__Q44nw4r3snd6detail10BasicSoundFi(void *self, int target) {
    struct SoundObj {
        virtual ~SoundObj();
        virtual void x1(); virtual void x2(); virtual void x3();
        virtual void a(); virtual void b(); virtual void c(); virtual void d();
        virtual void stop();
        virtual void f(); virtual void g(); virtual void h(); virtual void i();
        virtual void j(); virtual void k(); virtual void l(); virtual void m();
        virtual void n(); virtual void o(); virtual void p(); virtual void q();
        virtual SoundObj *get();
        virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6();
        virtual void m7(); virtual void m8(); virtual void m9();
        virtual void m10(); virtual void m11(); virtual void m12();
        virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18();
        virtual void m19(); virtual void m20(); virtual void m21();
        virtual void m22(); virtual void m23(); virtual void m24();
        virtual void m25(); virtual void m26(); virtual void m27();
        virtual void m28(); virtual void m29(); virtual void clear(int);
    };
    struct VoiceObj {
        virtual ~VoiceObj();
        virtual void x1(); virtual void x2(); virtual void x3();
        virtual int valid();
        virtual void a();
        virtual int isPlaying();
        virtual int isReady();
    };
    struct Fields {
        unsigned char pad[0x44];
        float start; float end;
        int total; int elapsed;
        unsigned char pad2[0x12];
        unsigned char flags[4];
    };
    SoundObj *sound = (SoundObj *)self;
    SoundObj *voice = sound->get();
    Fields *fields = (Fields *)self;
    if (target == 0 || ((VoiceObj *)voice)->valid() == 0 ||
        ((VoiceObj *)voice)->isPlaying() == 0 || ((VoiceObj *)voice)->isReady() != 0) {
        sound->stop();
        return;
    }
    int elapsed = fields->elapsed;
    int total = fields->total;
    float start = fields->start;
    float end = fields->end;
    float current;
    if (total > elapsed) current = start + (float)elapsed * (end - start) / (float)total;
    else current = end;
    fields->start = current;
    fields->end = lbl_80560FB0;
    fields->total = (int)((float)target * current);
    fields->elapsed = 0;
    sound->clear(0);
    fields->flags[0] = 0; fields->flags[1] = 0;
    fields->flags[2] = 0; fields->flags[3] = 1;
}

#pragma dont_inline off
extern "C" void Pause__Q46nw4hbm3snd6detail10BasicSoundFbi(void *self, bool pause, int frames) {
    PauseFields *s = (PauseFields *)self;
    PauseVt *player = ((PauseVt *)self)->vf22();
    int n;
    float v;
    if (pause) {
        n = (int)((float)frames * PauseRamp(s));
        s->fading = 1;
        if (n <= 0) n = 1;
        v = PauseRamp(s);
        s->end = lbl_80560FB0;
        s->start = v;
        s->total = n;
        s->elapsed = 0;
    } else {
        if ((s->paused != 0) != pause) {
            player->vf4(0);
        }
        n = (int)((float)frames * (lbl_80560FB4 - PauseRamp(s)));
        s->fading = 1;
        if (n <= 0) n = 1;
        v = PauseRamp(s);
        s->end = lbl_80560FB4;
        s->start = v;
        s->total = n;
        s->elapsed = 0;
    }
    s->paused = pause;
}
#pragma dont_inline on

extern "C" void fn_800E8F54(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x6C) = arg1;
    *(unsigned char *)((char *)arg0 + 0x66) = (unsigned int)((-arg1) & ~arg1) >> 31;
}

extern "C" float lbl_80560FB4;
extern double lbl_80560FB8;
extern "C" void FadeIn__Q44nw4r3snd6detail10BasicSoundFi(void* self, int duration) {
    struct BasicSoundFields {
        unsigned char pad0[0x44];
        float start;
        float end;
        int total;
        int current;
        unsigned char pad1[0x15];
        unsigned char active;
    };
    BasicSoundFields* sound = (BasicSoundFields*)self;
    if (0 == sound->active) {
        int current;
        int total;
        total = sound->total;
        current = sound->current;
        float volume;
        if (current >= total)
            volume = sound->end;
        else
            volume = sound->start + (float)current * (sound->end - sound->start) / (float)total;
        int newDuration = (int)((float)duration * (lbl_80560FB4 - volume));
        float finalVolume;
        if (current >= total)
            finalVolume = sound->end;
        else
            finalVolume = sound->start + (float)current * (sound->end - sound->start) / (float)total;
        sound->end = lbl_80560FB4;
        sound->start = finalVolume;
        sound->total = newDuration;
        sound->current = 0;
    }
}

typedef void (*vfn0_t)(void*);
extern "C" void fn_800E9070(VfObj *this_) {
    VfObj *first = this_->vf23();
    first->vf6();
}

extern "C" int fn_800E90AC(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x67) != 0;
}

#pragma dont_inline off
extern "C" void Update__Q46nw4hbm3snd6detail10BasicSoundFv(void *self) {
    UpdSelfVt *sv = (UpdSelfVt *)self;
    UpdPlayerVt *p = sv->s5C();
    int f30flag;
    float sends[4];
    float f31, f30, f28, f27, f26, f25, f24, f29;
    int voice, i, valid;
    float *aux;
    char *pl2;
    char *pl;
    if (UF(unsigned char, 0x66) != 0 && p->p18() != 0) {
        int c = UF(int, 0x6C);
        if (c == 0) {
            sv->s18(0);
            return;
        }
        UF(int, 0x6C) = c - 1;
    }
    f30flag = 0;
    if (UF(unsigned char, 0x65) == 0) {
        if (UF(unsigned char, 0x64) == 0) return;
        f30flag = 1;
    }
    if (p->p20() != 0) {
        unsigned int c = UF(unsigned int, 0x70);
        if (c < 0xFFFFFFFF) UF(unsigned int, 0x70) = c + 1;
    }
    if (p->p18() == 0) {
        sv->s28();
        return;
    }
    if (p->p24() != 0) return;
    if (UF(unsigned char, 0x68) != 0) {
        int c = UF(int, 0x60);
        if (c < UF(int, 0x5C)) UF(int, 0x60) = c + 1;
    } else {
        int c = UF(int, 0x50);
        if (c < UF(int, 0x4C)) UF(int, 0x50) = c + 1;
        c = UF(int, 0x88);
        if (c < UF(int, 0x84)) UF(int, 0x88) = c + 1;
    }
    if (UF(UpdCbA *, 0x1C) != 0) UF(UpdCbA *, 0x1C)->a08(UF(int, 0x24), self);
    if (UF(UpdCbB *, 0x18) != 0) UF(UpdCbB *, 0x18)->b08((char *)self + 0x28, UF(int, 0x78), self, UF(int, 0x24), -1);
    f31 = lbl_80560FB4;
    f31 *= UF(float, 0x8C);
    pl = UF(char *, 0x10);
    pl2 = UF(char *, 0x14);
    f31 *= *(float *)(pl + 0x28);
    if (pl2 != 0) f31 *= *(float *)(pl2 + 0x10);
    f31 *= UpdRamp((UpdRampFields *)((char *)self + 0x7C));
    f31 *= UpdRamp((UpdRampFields *)((char *)self + 0x44));
    f31 *= UpdRamp((UpdRampFields *)((char *)self + 0x54));
    f31 *= UF(float, 0x28);
    f28 = lbl_80560FB0;
    voice = 1;
    f27 = f28;
    f30 = lbl_80560FB4 * *(float *)(pl + 0x34) * UF(float, 0xA4);
    f28 = f28 + UF(float, 0x90);
    f26 = f27;
    f25 = f26;
    f24 = lbl_80560FB4;
    f26 = f26 + UF(float, 0x30);
    f27 = f27 + UF(float, 0x94);
    f25 = f25 + UF(float, 0x34);
    f24 = f24 * UF(float, 0x98);
    if (fn_800F87F0() != 0) voice = fn_800F87E8(UF(void *, 0x10));
    if (UF(unsigned char, 0x9C) != 0) voice = UF(int, 0xA0);
    f29 = lbl_80560FB4;
    aux = (float *)((char *)self + 0xA8);
    for (i = 0; i < 4; i++) {
        sends[i] = f29;
        sends[i] *= GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800F87F8(UF(void *, 0x10), i);
        valid = 0;
        if (i >= 0 && i < 4) valid = 1;
        if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x377, lbl_803227A4, i, 0, 4);
        sends[i] *= aux[i];
    }
    p->p28(f31);
    p->p30(f28);
    p->p34(f27);
    p->p38(f26);
    p->p3C(f25);
    p->p2C(f24);
    p->p60(voice);
    p->p64(f30);
    for (i = 0; i < 4; i++) p->p70(i, sends[i]);
    if (UF(unsigned char, 0x69) != 0 && UF(int, 0x50) >= UF(int, 0x4C)) {
        UF(unsigned char, 0x69) = 0;
        sv->s28();
        return;
    }
    if (UF(unsigned char, 0x68) != 0 && UF(int, 0x60) >= UF(int, 0x5C)) {
        unsigned char t = UF(unsigned char, 0x67);
        UF(unsigned char, 0x68) = 0;
        if (t != 0) p->p14(t != 0);
    }
    if (f30flag != 0 && p->p0C() != 0) {
        UF(unsigned char, 0x65) = 1;
        UF(unsigned char, 0x64) = 0;
    }
}

// Declared here because the file's other copies of these prototypes sit further
// down; they have to be at file scope, where extern "C" is allowed.
extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void *);
extern "C" void detail_FreePlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern "C" void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(void *, void *);
extern "C" void RemoveSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
/* Shut the sound down for good: stop the player it plays through, drop the
 * handles attached to it, hand back the track it was holding, take it off its
 * players' lists and tell the shutdown hook that its sound is gone. */
void nw4hbm::snd::detail::BasicSound::Shutdown() {
    BasicSoundVt *sound = (BasicSoundVt *)this;
    SoundPlayerVt *player = sound->GetPlayer();
    if (player->IsValid() != 0) {
        if (stopWhenFaded != 0) {
            player->SetVolume(lbl_80560FB0);
        }
        player->Stop();
    }
    soundId = -1;
    sound->GetPlayer()->soundId = -1;
    if (primaryHandle != 0) {
        DetachSound__Q34nw4r3snd11SoundHandleFv(primaryHandle);
    }
    if (secondaryHandle != 0) {
        DetachSound__Q34nw4r3snd11SoundHandleFv(secondaryHandle);
    }
    if (sound->HasResource() != 0) {
        sound->ReleaseResource();
    }
    if (fromPlayerHeap != 0) {
        detail_FreePlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(soundPlayer, this);
    }
    detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(soundPlayer, this);
    detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(soundPlayer, this);
    if (externalPlayer != 0) {
        RemoveSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(externalPlayer, this);
    }
    ShutdownHookVt *hook = shutdownHook;
    if (hook != 0) {
        hook->Notify(hookId, this);
        hookId = 0;
    }
    started = 0;
    stopWhenFaded = 0;
}

#pragma dont_inline on
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void *this_, int priority) {
    int valid = 0;
    /* Set this sound's player priority (0-127), reordering it in the sound player's priority list. */
    if (priority >= 0) {
        if (priority <= 0x7F) valid = 1;
    }
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x202, lbl_803227EC, priority, 0, 0x7F);
    }
    *(char *)((char *)this_ + 0x74) = priority;
    void *player = *(void **)((char *)this_ + 0x10);
    if (player != 0) {
        detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(player, this_);
        player = *(void **)((char *)this_ + 0x10);
        detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(player, this_);
    }
}

void nw4hbm::snd::detail::BasicSound::SetInitialVolume(float vol) {
    float thresh = lbl_80560FB0;
    if (!(vol >= thresh)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x216, lbl_80322830);
    }
    initialVolume = vol;
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail10BasicSoundFfi(void *this_, float volume, int arg2) {
    struct SoundFields {
        char pad[0x7C];
        float current;
        float target;
        int total;
        int elapsed;
    };
    float current;

    if (!(volume >= lbl_80560FB0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x225, lbl_80322830);
    }
    SoundFields *sound = (SoundFields *)this_;
    if (sound->elapsed >= sound->total) {
        current = sound->target;
    } else {
        current = sound->current +
                  ((float)sound->elapsed * (sound->target - sound->current)) /
                      (float)sound->total;
    }
    sound->current = current;
    sound->target = volume;
    sound->total = arg2;
    sound->elapsed = 0;
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800E9AAC(void *this_, float vol) {
    if (!(vol >= 0.0f)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x234, lbl_80322858);
    }
    *(float *)((char *)this_ + 0x98) = vol;
}

#pragma push
#pragma small_data off
extern float lbl_80560FB0;
#pragma pop
extern "C" void fn_800E9B18(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x90) = farg0;
}

extern "C" void fn_800E9B20(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x94) = arg1;
}

extern "C" void fn_800E9B28(void *arg0, float arg1) {
    VfObjF *obj = (VfObjF *)arg0;
    VfObjF *result = obj->vf22();
    result->vf15(arg1);
}

extern "C" void fn_800E9B74(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    *(int *)((char *)arg0 + 0x18) = arg1;
    *(int *)((char *)arg0 + 0x1C) = arg2;
    *(int *)((char *)arg0 + 0x20) = arg3;
    *(int *)((char *)arg0 + 0x24) = arg4;
}

extern "C" int fn_800E9B88(void *arg0) {
    return *(int *)((char *)arg0 + 8) != 0;
}

extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void *);
extern "C" void fn_800E9B9C(void *arg0) {
    DetachSound__Q34nw4r3snd11SoundHandleFv(*(void **)((char *)arg0 + 8));
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" void fn_800E9BA4(void *this_, int vol) {
    class Dispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual void d20(); virtual Dispatch *call();
    };
    *(int *)((char *)this_ + 0x78) = vol;
    this_ = ((Dispatch *)this_)->call();
    *(int *)((char *)this_ + 4) = vol;
}
extern int lbl_8055DE20;
extern void fn_80128668(void);
extern "C" int fn_800E9BE4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" int *fn_800E9C24(void) {
    return &lbl_8055DE20;
}
extern const char lbl_803221A8[];
extern const char lbl_80322438[];
extern float lbl_80560F38;
extern float lbl_80560F3C;
class ShutdownA { public: virtual ~ShutdownA(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual ShutdownA *get(); };
class ShutdownB { public: virtual ~ShutdownB(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual int check(); };
class ShutdownC { public: virtual ~ShutdownC(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void c10(float); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15(); virtual void c16(); virtual void c17(); virtual void c18(); virtual void c19(); virtual void c20(); virtual void c21(); virtual void c22(); virtual ShutdownC *get(); };
#pragma push
#pragma small_data off
extern const char lbl_80322034[];
extern const char lbl_80322010[];
extern const char lbl_80322470[];
#pragma pop

extern "C" void VoiceCallback__Q46nw4hbm3snd6detail7AxVoiceFPv(void *arg0) {
    /* AX voice callback: notify the voice owner, release attached non-self buffers, unregister/free the voice, and clear its state. */
    char *callbackContext = (char *)arg0;
    unsigned int savedInterrupts = OSDisableInterrupts();
    char *row;
    char *entry;
    char *voice = (char *)*(void **)(callbackContext + 0x14);
    int rowIndex;
    int column;
    int zero = 0;

    if (voice == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x51F, lbl_80322470);
    }

    void (*ownerCallback)(void *, int, void *) = (void (*)(void *, int, void *))(*(void ***)(voice + 0x10C));
    if (ownerCallback != 0) {
        ownerCallback(voice, 3, *(void **)(voice + 0x110));
    }

    row = voice;
    rowIndex = 0;
    while (rowIndex < *(int *)(voice + 0x104)) {
        entry = row;
        column = 0;
        while (column < *(int *)(voice + 0x108)) {
            unsigned int buffer = *(unsigned int *)(entry + 0xC);
            if (buffer != 0 && buffer != (unsigned int)callbackContext) {
                TRKGetFreeBuffer((void *)buffer);
            }
            entry += 4;
            column++;
        }
        row += 0x10;
        rowIndex++;
    }

    UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
        GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), voice);
    FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(
        Instance__15EmissionManagerFv(), voice);
    *(unsigned char *)(voice + 0x11F) = zero;
    *(unsigned char *)(voice + 0x11D) = zero;
    *(int *)(voice + 0x104) = zero;
    *(unsigned char *)(voice + 0x11C) = zero;
    OSRestoreInterrupts(savedInterrupts);
}
