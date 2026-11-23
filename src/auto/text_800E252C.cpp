typedef int s32;
struct LLTmp { int a; void* next; void* prev; };
struct ElemTmp { float f1; float f2; int i1; int i2; };
extern float lbl_80560F20;
extern float lbl_80560F24;
extern double lbl_80560F28;
extern float lbl_80560F30;
static inline void FillTmp(ElemTmp* end, ElemTmp* q, float f) { do { q->f1 = f; q->f2 = f; q->i1 = 0; q->i2 = 0; q++; } while (q < end); }
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
#pragma push
#pragma small_data on
extern const char lbl_80559820;
extern const char lbl_80559828;
#pragma pop
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
    virtual void Start();            /* 0x0C start playing what is loaded */
    virtual void Stop();             /* 0x10 */
    virtual void Pause(bool);        /* 0x14 */
    virtual int IsValid();           /* 0x18 still playing something */
    virtual int IsPrepared();        /* 0x1C its data is loaded and it can start */
    virtual void v20();
    virtual void v24();
    virtual void SetVolume(float);   /* 0x28 */
    int soundId;                     /* 0x04 */
};
//
// BasicSound's own vtable, lbl_80322880 (its slots are named below as the
// SeqSound / StrmSound / WaveSound copies of that table fill them in).  The
// 0x50, 0x54, 0x5C and 0x60 methods are pure in the base class and filled in
// by SeqSound, StrmSound and WaveSound; both 0x5C and 0x60 hand back the
// player embedded in the sound at +0xD8 (SeqPlayer, StrmPlayer, ...).
struct BasicSoundVt {
    virtual void v08();
    virtual void v0C();
    virtual void Update();                  /* 0x10 run one frame of the sound */
    virtual void v14();
    virtual void Stop(int fadeFrames);      /* 0x18 */
    virtual void Pause(bool pause, int frames); /* 0x1C */
    virtual void v20();
    virtual void FadeIn(int frames);        /* 0x24 */
    virtual void Shutdown();                /* 0x28 */
    virtual int IsPrepared();               /* 0x2C the player's data is loaded */
    virtual int IsPaused();                 /* 0x30 */
    virtual void SetInitialVolume(float);   /* 0x34 */
    virtual void SetVolume(float, int);     /* 0x38 */
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void SetPlayerPriority(int);    /* 0x4C */
    virtual int HasResource();            /* 0x50 still holding the track it plays */
    virtual void ReleaseResource();       /* 0x54 hand that track back */
    virtual void InitParam();             /* 0x58 back to the state a new sound has */
    virtual SoundPlayerVt *GetPlayer();      /* 0x5C the player inside the sound */
    virtual SoundPlayerVt *GetSoundPlayer(); /* 0x60 the same player, second accessor */
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
struct EmissionManagerAlloc { char pad0[0xC]; void *next; char pad1[0x6C2C-0x10]; void *callback; };
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
    /* nw4r math sine: wrap the absolute angle into one 65536-unit turn, quantize
     * it to the 256-entry sin/cos table, then linearly interpolate the table's
     * sine value with its slope; negate for negative angles (sine is odd). */
    struct SinEntry { f32 s, c, sd, cd; };
    f32 absAngle = __fabsf(angle);
    while (absAngle >= 65536.0f) absAngle -= 65536.0f;
    u16 quantized = __OSf32tou16(absAngle);
    f32 wholePart = __OSu16tof32(&quantized);
    u32 tableIndex = quantized & 0xFF;
    u32 byteOffset = tableIndex * 0x10;
    struct SinEntry *sineTable = (struct SinEntry *)lbl_80320E38;
    f32 sineValue;
    f32 sineSlope;
    f32 fraction = absAngle - wholePart;
    sineSlope = *(f32 *)((char *)lbl_80320E38 + byteOffset + 8);
    sineValue = sineTable[tableIndex].s;
    f32 result = sineValue + fraction * sineSlope;
    if (angle < lbl_80560F04) result = -result;
    return result;
}

extern "C" f32 CosFIdx__Q24nw4r4mathFf(f32 angle) {
    /* nw4r math cosine: wrap the absolute angle into one 65536-unit turn, quantize
     * it to the 256-entry sin/cos table, then interpolate the table's cosine value
     * with its slope (cosine is even, so negative angles need no sign fix-up). */
    struct TrigEntry { f32 s, c, sd, cd; };
    f32 absAngle = __fabsf(angle);
    while (absAngle >= 65536.0f) absAngle -= 65536.0f;
    u16 quantized = __OSf32tou16(absAngle);
    f32 wholePart = __OSu16tof32(&quantized);
    struct TrigEntry *entry = (struct TrigEntry *)((char *)lbl_80320E38 + ((quantized * 0x10) & 0xFF0));
    f32 fraction = absAngle - wholePart;
    return entry->c + fraction * entry->cd;
}

#pragma push
#pragma small_data off
extern float lbl_80560F04, lbl_80560F08, lbl_80560F0C, lbl_80560F10, lbl_80560F14, lbl_80560F18;
extern float lbl_80321E48[];
#pragma pop
extern "C" float Atan2FIdx__Q24nw4r4mathFff(float y, float x) {
    /* nw4r math atan2: fold (x,y) into the first octant, linearly interpolate
     * atan(|y|/divisor) from a value/slope table, then add the quadrant base angle;
     * returns an angle index in 1/256-turn units. */
    if (0.0f == x && 0.0f == y) return 0.0f;
    float divisor, angleOffset = lbl_80560F04, negX;
    int subtractOffset;
    if (x >= lbl_80560F04) {
        if (y >= lbl_80560F04) {
            if (x >= y) { divisor = x; subtractOffset = 0; }
            else { divisor = y; angleOffset = lbl_80560F0C; y = x; subtractOffset = 1; }
        } else {
            y = -y;
            if (x >= y) { divisor = x; subtractOffset = 1; }
            else { divisor = y; angleOffset = lbl_80560F10; y = x; subtractOffset = 0; }
        }
    } else {
        if (y >= lbl_80560F04) {
            negX = -x;
            if (negX >= y) { divisor = negX; angleOffset = lbl_80560F14; subtractOffset = 1; }
            else { divisor = y; angleOffset = lbl_80560F0C; y = negX; subtractOffset = 0; }
        } else {
            negX = -x;
            y = -y;
            if (negX >= y) { divisor = negX; angleOffset = lbl_80560F18; subtractOffset = 0; }
            else { divisor = y; angleOffset = lbl_80560F10; y = negX; subtractOffset = 1; }
        }
    }
    struct AtanEntry { f32 value, slope; };
    if (subtractOffset) {
        y = y / divisor;
        y = y * lbl_80560F08;
        u16 tableIndex = __OSf32tou16(y);
        f32 wholeIndex = __OSu16tof32(&tableIndex);
        u32 byteOffset = tableIndex * 8;
        struct AtanEntry *atanTable = (struct AtanEntry *)lbl_80321E48;
        return angleOffset - (atanTable[tableIndex].value + (y - wholeIndex) * *(f32 *)((char *)lbl_80321E48 + byteOffset + 4));
    } else {
        y = y / divisor;
        y = y * lbl_80560F08;
        u16 tableIndex = __OSf32tou16(y);
        f32 wholeIndex = __OSu16tof32(&tableIndex);
        u32 byteOffset = tableIndex * 8;
        struct AtanEntry *atanTable = (struct AtanEntry *)lbl_80321E48;
        return angleOffset + (atanTable[tableIndex].value + (y - wholeIndex) * *(f32 *)((char *)lbl_80321E48 + byteOffset + 4));
    }
}

extern "C" void __ct__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void fn_8002F53C(void *, void *, void *, s32, s32); /* extern */
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8(void *, int);
extern "C" void fn_800E2C98(void *);
#pragma push
#pragma processor 750
#pragma opt_propagation off
void *fn_800E279C(void *arg0)
{
  u8 *p = (u8 *) arg0;
  *((volatile int *) (p + 0xC)) = 0;
  *((volatile int *) (p + 0x10)) = 0;
  *((volatile int *) (p + 0x18)) = 0;
  *((volatile int *) (p + 0x1C)) = 0;
  *((volatile int *) (p + 0x24)) = 0;
  *((volatile int *) (p + 0x28)) = 0;
  *((int *) (p + 0)) = 0;
  *((int *) (p + 4)) = 0;
  *((int *) (p + 8)) = 0;
  ((LLTmp *) (p + 8))->a = 0;
  ((LLTmp *) (p + 8))->next = &((LLTmp *) (p + 8))->next;
  ((LLTmp *) (p + 8))->prev = &((LLTmp *) (p + 8))->next;
  ((LLTmp *) (p + 0x14))->a = 0;
  ((LLTmp *) (p + 0x14))->next = &((LLTmp *) (p + 0x14))->next;
  ((LLTmp *) (p + 0x14))->prev = &((LLTmp *) (p + 0x14))->next;
  ((LLTmp *) (p + 0x20))->a = 0;
  ((LLTmp *) (p + 0x20))->next = &((LLTmp *) (p + 0x20))->next;
  ((LLTmp *) (p + 0x20))->prev = &((LLTmp *) (p + 0x20))->next;
  fn_8002F53C(p + 0x2C, &__ct__Q46nw4hbm3snd6detail7AxVoiceFv, &__dt__Q46nw4hbm3snd6detail7AxVoiceFv, 0x1B0, 0x40);
  p[0x6C30] = 0;
  p[0x6C31] = 1;
  p[0x6C32] = 0;
  p[0x6C33] = 0;
  *((float *) (p + 0x6C34)) = 0.0f;
  *((float *) (p + 0x6C38)) = 0.0f;
  *((int *) (p + 0x6C3C)) = 0;
  *((int *) (p + 0x6C40)) = 0;
  *((float *) (p + 0x6C44)) = 0.0f;
  *((float *) (p + 0x6C48)) = 0.0f;
  *((int *) (p + 0x6C4C)) = 0;
  *((int *) (p + 0x6C50)) = 0;
  *((float *) (p + 0x6C54)) = 0.0f;
  *((float *) (p + 0x6C58)) = 0.0f;
  *((int *) (p + 0x6C5C)) = 0;
  *((int *) (p + 0x6C60)) = 0;
  *((int *) (p + 0x6C64)) = 0;
  *((int *) (p + 0x6C68)) = -1;
  *((float *) (p + 0x6C6C)) = 0.0f;
  *((float *) (p + 0x6C70)) = 0.0f;
  *((int *) (p + 0x6C74)) = 0;
  *((int *) (p + 0x6C78)) = 0;
  FillTmp((ElemTmp *) (p + 0x6C9C), (ElemTmp *) (p + 0x6C7C), 0.0f);
  *((float *) (p + 0x6C9C)) = 0.0f;
  *((float *) (p + 0x6CA0)) = 0.0f;
  *((int *) (p + 0x6CA4)) = 0;
  *((int *) (p + 0x6CA8)) = 0;
  FillTmp((ElemTmp *) (p + 0x6CCC), (ElemTmp *) (p + 0x6CAC), 0.0f);
  fn_8002F53C(p + 0x6CCC, &fn_800E2C98, &__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8, 0xC, 3);
  {
    *((int *) (p + 0x6C3C)) = 0;
    *((float *) (p + 0x6C34)) = 1.0f;
    *((float *) (p + 0x6C38)) = 1.0f;
    *((int *) (p + 0x6C40)) = 0;
    *((float *) (p + 0x6C44)) = 1.0f;
    *((float *) (p + 0x6C48)) = 1.0f;
    *((int *) (p + 0x6C4C)) = 0;
    *((int *) (p + 0x6C50)) = 0;
    *((float *) (p + 0x6C54)) = 1.0f;
    *((float *) (p + 0x6C58)) = 1.0f;
    *((int *) (p + 0x6C5C)) = 0x1B0 * 0;
    *((int *) (p + 0x6C60)) = 0;
    *((float *) (p + 0x6C6C)) = 1.0f;
    *((float *) (p + 0x6C70)) = 1.0f;
    *((int *) (p + 0x6C74)) = 0;
    *((int *) (p + 0x6C78)) = 0;
    *((float *) (p + 0x6C9C)) = 1.0f;
    *((float *) (p + 0x6CA0)) = 1.0f;
    *((int *) (p + 0x6CA4)) = 0;
    *((int *) (p + 0x6CA8)) = 0;
    *((int *) (p + 0x6CF0)) = 0;
    *((int *) (p + 0x6CFC)) = 0;
    *((float *) (p + 0x6C7C)) = 1.0f;
    *((float *) (p + 0x6C80)) = 1.0f;
    *((int *) (p + 0x6C84)) = 0;
    *((int *) (p + 0x6C88)) = 0;
    *((float *) (p + 0x6CAC)) = 1.0f;
    *((float *) (p + 0x6CB0)) = 1.0f;
    *((int *) (p + 0x6CB4)) = 0;
    *((int *) (p + 0x6CB8)) = 0;
    *((int *) (p + 0x6CF4)) = 0;
    *((int *) (p + 0x6D00)) = 0;
    *((float *) (p + 0x6C8C)) = 1.0f;
    *((float *) (p + 0x6C90)) = 1.0f;
    *((int *) (p + 0x6C94)) = 0;
    *((int *) (p + 0x6C98)) = 0;
    *((float *) (p + 0x6CBC)) = 1.0f;
    *((float *) (p + 0x6CC0)) = 1.0f;
    *((int *) (p + 0x6CC4)) = 0;
    *((int *) (p + 0x6CC8)) = 0;
    *((int *) (p + 0x6CF8)) = 0;
    *((int *) (p + 0x6D04)) = 0;
  }
  return arg0;
}
#pragma pop
extern "C" void fn_800E2C98(void *list) {
    /* Initialize an embedded nw4r::ut::LinkListImpl: clear the node count, then
     * make the sentinel link at +4 point to itself so the list starts empty. */
    int *sentinel = (int *)((char *)list + 4);
    *(int *)((char *)list + 4) = 0;
    *(int *)((char *)list + 8) = 0;
    *(int *)list = 0;
    *(int *)((char *)list + 4) = (int)sentinel;
    *(int *)((char *)list + 8) = (int)sentinel;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8(void *self, int shouldDelete) {
    /* nw4hbm::snd::MemorySoundArchive destructor: destroy base link list, then
     * free the object when requested (shouldDelete > 0). */
    if (self != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

#pragma dont_inline on
extern "C" void *Instance__15EmissionManagerFv(void) {
    /* Returns the singleton EmissionManager instance, constructing it once and
     * registering its global destructor. */
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
extern "C" void fn_800E2E24(void *self)
{
  if ((*((unsigned char *) (((char *) self) + 0x6C30))) == 0)
  {
    if (AIGetDMAStatus() == 0)
    {
      Panic__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x6E, lbl_80321F94);
    }
    unsigned int base = (unsigned int) self;
    nw4hbm::ut::detail::LinkListImpl::Iterator iterator;
    int offset = 0;
    int i = 0;
    do
    {
      if (((base + (offset & 0xFFu)) + 0x2C) == 0)
      {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
      }
      iterator.node = (nw4hbm::ut::detail::LinkListNode *) (base + 0x24);
      ((nw4hbm::ut::detail::LinkListImpl *) (base + 0x20))->Insert(iterator, (nw4hbm::ut::detail::LinkListNode *) ((base + offset) + 0x1D4));
      i++;
      offset = offset + 0x1B0;
    }
    while (i < 0x40);
    memset(lbl_80407E60, 0, 0x100);
    DCFlushRange(lbl_80407E60, 0x100);
    *((void **) (((char *) self) + 4)) = lbl_80407E60;
    unsigned int irq = OSDisableInterrupts();
    AXGetAuxACallback(((char *) self) + 0x6CF0, ((char *) self) + 0x6CFC);
    AXGetAuxBCallback(((char *) self) + 0x6CF4, ((char *) self) + 0x6D00);
    AXGetAuxCCallback(((char *) self) + 0x6CF8, ((char *) self) + 0x6D04);
    AXRegisterAuxACallback(0, 0);
    AXRegisterAuxBCallback(0, 0);
    AXRegisterAuxCCallback(0, 0);
    *((void **) (((char *) self) + 0x6C2C)) = AIRegisterDMACallback(fn_800E41EC);
    *((unsigned char *) (((char *) self) + 0x6C30)) = 1;
    OSRestoreInterrupts(irq);
  }
}
#pragma pop

extern const char lbl_80322124[];
extern const char lbl_80322100[];
extern const char lbl_803220F4[];
extern const char lbl_803220D0[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800E2F84(void *self)
{
  char *base = (char *) self;
  if ((*((unsigned char *) (base + 0x6C30))) != 0)
  {
    AIRegisterDMACallback(*((void **) (base + 0x6C2C)));
    fn_800E4364(self, 0);
    fn_800E4364(self, 1);
    fn_800E4364(self, 2);
    AXRegisterAuxACallback(*((int *) (base + 0x6CF0)), *((int *) (base + 0x6CFC)));
    AXRegisterAuxBCallback(*((int *) (base + 0x6CF4)), *((int *) (base + 0x6D00)));
    AXRegisterAuxCCallback(*((int *) (base + 0x6CF8)), *((int *) (base + 0x6D04)));
    *((int *) (base + 0x6CF0)) = 0;
    *((int *) (base + 0x6CFC)) = 0;
    *((int *) (base + 0x6CF4)) = 0;
    *((int *) (base + 0x6D00)) = 0;
    *((int *) (base + 0x6CF8)) = 0;
    *((int *) (base + 0x6D04)) = 0;
    *((int *) (base + 4)) = 0;
    while ((*((int *) (base + 0x14))) != 0)
    {
      if ((*((int *) (base + 0x14))) == 0)
      {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322124, 0x1F1, lbl_80322100);
      }
      void *node = *((void **) (base + 0x18));
      if (node == 0)
      {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
      }
      void *voice = ((char *) node) - 0x1A8;
      if (voice == 0)
      {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220F4, 0x193, lbl_803220D0);
      }
      Stop__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
      Free__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
      void (*callback)(void *, int, void *) = *((void (**)(void *, int, void *)) (((char *) voice) + 0x10C));
      if (callback != 0)
      {
        callback(voice, 2, *((void **) (((char *) voice) + 0x110)));
        base = (char *) self;
      }
    }

    while ((*((int *) (base + 0x20))) != 0)
    {
      void *it = *((void **) (base + 0x24));
      Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(base + 0x20, &it);
    }

    *((unsigned char *) (base + 0x6C30)) = 0;
  }
}
#pragma pop

#pragma scheduling on
/* Returns the EmissionManager's engine gain: the product of three time-based fades, each interpolating from a start to an end factor over a frame count. */
extern "C" f32 fn_800E310C(const void *emitter) {
    int b = *(int *)((const char *)emitter + 0x6C4C);
    int a = *(int *)((const char *)emitter + 0x6C50);
    float x;
    if (a >= b) x = *(float *)((const char *)emitter + 0x6C48);
    else x = *(float *)((const char *)emitter + 0x6C44) +
        (float)a * (*(float *)((const char *)emitter + 0x6C48) - *(float *)((const char *)emitter + 0x6C44)) / (float)b;

    int c;
    int d;
    d = *(int *)((const char *)emitter + 0x6C5C);
    c = *(int *)((const char *)emitter + 0x6C60);
    float y;
    if (c >= d) y = *(float *)((const char *)emitter + 0x6C58);
    else y = *(float *)((const char *)emitter + 0x6C54) +
        (float)c * (*(float *)((const char *)emitter + 0x6C58) - *(float *)((const char *)emitter + 0x6C54)) / (float)d;
    float result = x * y;

    int e;
    int f;
    f = *(int *)((const char *)emitter + 0x6C3C);
    e = *(int *)((const char *)emitter + 0x6C40);
    float z;
    if (e >= f) z = *(float *)((const char *)emitter + 0x6C38);
    else z = *(float *)((const char *)emitter + 0x6C34) +
        (float)e * (*(float *)((const char *)emitter + 0x6C38) - *(float *)((const char *)emitter + 0x6C34)) / (float)f;
    result *= z;
    return result;
}
#pragma scheduling reset

extern "C" int DVDGetDriveStatus(void);
extern "C" void fn_80031C8C(unsigned short);
extern "C" void fn_80031C94(unsigned short);
extern "C" void fn_80031C9C(unsigned short);
extern "C" void fn_800E3228(void *arg0)
{
  int status = DVDGetDriveStatus();
  if (status == 0)
  {
    if ((*(((unsigned char *) arg0) + 0x6C33)) != 0)
    {
      unsigned char *node;
      unsigned char *current;
      unsigned char *sentinel;
      unsigned int interruptState;
      *(((unsigned char *) arg0) + 0x6C33) = 0;
      interruptState = OSDisableInterrupts();
      current = *((unsigned char **) (((unsigned char *) arg0) + 0x18));
      sentinel = ((unsigned char *) arg0) + 0x18;
      while (current != sentinel)
      {
        node = current;
        current = *((unsigned char **) node);
        if (node == 0)
        {
          Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        }
        if ((*((unsigned char *) (node - 0x8C))) != 0)
        {
          if (node == 0)
          {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
          }
          *((unsigned char *) (node - 0x85)) |= 2;
        }
      }

      OSRestoreInterrupts(interruptState);
    }
  }
  else
    if ((status != 1) && ((*(((unsigned char *) arg0) + 0x6C33)) == 0))
  {
    unsigned char *node;
    unsigned char *current;
    unsigned char *sentinel;
    unsigned int interruptState;
    *(((unsigned char *) arg0) + 0x6C33) = 1;
    interruptState = OSDisableInterrupts();
    current = *((unsigned char **) (((unsigned char *) arg0) + 0x18));
    sentinel = ((unsigned char *) arg0) + 0x18;
    while (current != sentinel)
    {
      node = current;
      current = *((unsigned char **) node);
      if (node == 0)
      {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
      }
      if ((*((unsigned char *) (node - 0x8C))) != 0)
      {
        if (node == 0)
        {
          Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        }
        *((unsigned char *) (node - 0x85)) |= 2;
      }
    }

    OSRestoreInterrupts(interruptState);
  }
  {
    float scale;
    float lower;
    float upper;
    unsigned char *entry;
    int i;
    upper = lbl_80560F24;
    entry = (unsigned char *) arg0;
    lower = lbl_80560F20;
    i = 0;
    scale = lbl_80560F30;
    for (; i < 3; i++, entry += 0x10)
    {
      int changed = 0;
      int limit;
      int value;
      volatile int *v = (volatile int *) (entry + 0x6CA8);
      value = *v;
      limit = *((volatile int *) (entry + 0x6CA4));
      if (value < limit)
      {
        value = *v;
        limit = *((volatile int *) (entry + 0x6CA4));
        if (value < limit)
        {
          *v = value + 1;
        }
        changed = 1;
      }
      v = (volatile int *) (entry + 0x6C78);
      value = *v;
      limit = *((volatile int *) (entry + 0x6C74));
      if (limit > value)
      {
        value = *v;
        limit = *((volatile int *) (entry + 0x6C74));
        if (value < limit)
        {
          *v = value + 1;
        }
        value = *v;
        limit = *((volatile int *) (entry + 0x6C74));
        if (limit <= value)
        {
          fn_800E4364(arg0, i);
        }
        changed = 1;
      }
      if (changed != 0)
      {
        float first;
        float second;
        float product;
        int count;
        int total;
        count = *((volatile int *) (entry + 0x6CA8));
        total = *((volatile int *) (entry + 0x6CA4));
        product = lbl_80560F24;
        if (count >= total)
        {
          first = *((float *) (entry + 0x6CA0));
        }
        else
        {
          float start = *((float *) (entry + 0x6C9C));
          first = start + ((((float) count) * ((*((float *) (entry + 0x6CA0))) - start)) / ((float) total));
        }
        if (first > upper)
        {
          first = upper;
        }
        else
          if (first < lower)
        {
          first = lower;
        }
        product *= first;
        count = *((volatile int *) (entry + 0x6C78));
        total = *((volatile int *) (entry + 0x6C74));
        if (count >= total)
        {
          second = *((float *) (entry + 0x6C70));
        }
        else
        {
          float start = *((float *) (entry + 0x6C6C));
          second = start + ((((float) count) * ((*((float *) (entry + 0x6C70))) - start)) / ((float) total));
        }
        if (second > upper)
        {
          second = upper;
        }
        else
          if (second < lower)
        {
          second = lower;
        }
        product *= second;
        value = (int) (scale * product);
        switch (i)
        {
          case 0:
            fn_80031C8C((unsigned short) value);
            break;

          case 1:
            fn_80031C94((unsigned short) value);
            break;

          case 2:
            fn_80031C9C((unsigned short) value);
            break;

        }

      }
    }

  }
  {
    int changed = 0;
    volatile int *v;
    int value;
    v = (volatile int *) (((unsigned char *) arg0) + 0x6C50);
    value = *v;
    if (value < (*((volatile int *) (((unsigned char *) arg0) + 0x6C4C))))
    {
      value = *v;
      if (value < (*((volatile int *) (((unsigned char *) arg0) - -0x6C4C))))
      {
        *v = value + 1;
      }
      changed = 1;
    }
    v = (volatile int *) (((unsigned char *) arg0) + 0x6C60);
    value = *v;
    if (value < (*((volatile int *) (((unsigned char *) arg0) + (((((((((0x6C5C & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF)))))
    {
      value = *v;
      if (value < (*((volatile int *) (((unsigned char *) arg0) + 0x6C5C))))
      {
        *v = value + 1;
      }
      changed = 1;
    }
    v = (volatile int *) (((unsigned char *) arg0) + 0x6C40);
    value = *v;
    if (value < (*((volatile int *) (((unsigned char *) arg0) + 0x6C3C))))
    {
      value = *v;
      if (value < (*((volatile int *) (((unsigned char *) arg0) + 0x6C3C))))
      {
        *v = value + 1;
      }
      changed = 1;
    }
    if (changed != 0)
    {
      unsigned char *node;
      unsigned char *current;
      unsigned int interruptState = OSDisableInterrupts();
      node = *((unsigned char **) ((unsigned char *) arg0 += 0x18));
      while (node != arg0)
      {
        current = node;
        node = *((unsigned char **) current);
        if (current == 0)
        {
          Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        }
        if ((*((unsigned char *) (current - 0x8C))) != 0)
        {
          if (current == 0)
          {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
          }
          *((unsigned char *) (current - 0x85)) |= 0x10;
        }
      }

      OSRestoreInterrupts(interruptState);
    }
  }
}

/* nw4hbm::snd::detail::AxManager::GetZeroBufferAddress(): returns the address of the
 * zero-filled DSP buffer silent voices sample from, panicking if it was never created. */
extern "C" void *GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(void *self) {
    /* The part of nw4hbm::snd::detail::AxManager (snd_AxManager.cpp) this reads. */
    struct AxManager {
        int outputMode;   /* +0x00 nw4hbm::snd::OutputMode */
        void *zeroBuffer; /* +0x04 zero buffer, held as a DSP-mirror-relative address */
    };
#define sndAxManagerCpp lbl_80321F80     /* "snd_AxManager.cpp" */
#define zeroBufferNotCreated lbl_80321FAC /* "Zero buffer is not created." */
    AxManager *manager = (AxManager *)self;
    if (manager->zeroBuffer == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(sndAxManagerCpp, 0x172, zeroBufferNotCreated);
    }
    return manager->zeroBuffer;
#undef sndAxManagerCpp
#undef zeroBufferNotCreated
}

/* nw4hbm::snd::detail::AxManager::RegisterCallback(CallbackListNode*, void (*)()):
 * put a caller-supplied function on the mixer manager's callback list so it runs
 * once per mixer frame (the sound thread uses it to refill streaming buffers).
 * The list is walked from the mixer callback, so the node's function pointer and
 * the append both happen with the interrupts disabled. */
extern "C" void RegisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNodePFv_v(void *self, void *node, void (*callback)(void)) {
    void *manager = self;
    void *callbackNode = node;
    void (*callbackFunc)(void) = callback;
    unsigned int interruptLevel;
    void *listEnd;
    void *iterator;

    interruptLevel = OSDisableInterrupts();
    *(void (**)(void))((char *)callbackNode + 8) = callbackFunc;
    listEnd = (char *)manager + 12;    /* the callback list at +8 hands out its own node as end() */
    if (callbackNode == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);    /* "LinkList.h": "NW4HBM:Pointer must not be NULL (p)" */
    }
    iterator = listEnd;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)manager + 8, &iterator, callbackNode);
    OSRestoreInterrupts(interruptLevel);
}

/* nw4hbm::snd::detail::AxManager::UnregisterCallback: remove a callback node from mCallbackList (+0x8) with interrupts disabled. */
extern "C" void UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(void *self, void *callbackNode) {
    unsigned int interruptLevel = OSDisableInterrupts();
    if (callbackNode == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)self + 8, callbackNode);
    OSRestoreInterrupts(interruptLevel);
}

extern "C" void fn_80031C6C(int);
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
    void *end = (char *)self + 0x18;
    void *node = *(void **)((char *)self + 0x18);
    while (node != end) {
        void *current = node;
        node = *(void **)node;
        if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
        if (*((unsigned char *)current - 0x8c) != 0) {
            if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
            *((unsigned char *)current - 0x85) |= 0x20;
        }
    }
    OSRestoreInterrupts(interrupts);
}

/* Indirect int read: returns the value at the given address (used to fetch the EmissionManager mode from its instance). */
extern "C" int fn_800E394C(int *valuePtr) { return *valuePtr; }

extern "C" int Acquire__Q46nw4hbm3snd6detail7AxVoiceFiiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *, int, int, int, void (*)(void *, int, void *), void *);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern const char lbl_80321FC8[];
extern const char lbl_80322154[];
extern const char lbl_80322130[];
#pragma push
#pragma scheduling on
extern "C" void *fn_800E3954(char *self, int count, int columns, int priority, void (*callback)(void *, int, void *), void *callbackArg) {

    int stolen;
    void *node;
    void *voice;
    void *oldVoice;
    unsigned int interruptState;
    interruptState = OSDisableInterrupts();

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
    if (stolen == 0) {
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
    columns = (int)OSDisableInterrupts();
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
    OSRestoreInterrupts(columns);
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
#pragma pop
extern const char lbl_80321FE8[];
#pragma use_lmw_stmw off
extern "C" void FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(void *manager, void *voice)
{
  if (voice == 0)
  {
    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x21D, lbl_80321FE8);
  }
  unsigned int firstState = OSDisableInterrupts();
  unsigned int secondState = OSDisableInterrupts();
  if (voice == 0)
  {
    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
  }
  void *link = ((char *) voice) + 0x1A8;
  Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(((char *) manager) + 0x14, link);
  void *iterator = ((char *) manager) + 0x24;
  if (voice == 0)
  {
    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233 & 0xFFFFu, lbl_80322130);
  }
  Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(((char *) manager) + 0x20, &iterator, link);
  OSRestoreInterrupts(secondState);
  OSRestoreInterrupts(firstState);
}

#pragma opt_common_subs off
extern "C" void fn_800E3DDC(void *arg0, void *arg1) {
    struct Mgr { char pad0[0x14]; char activeList[0xC]; char freeList[0x4]; char pad1[8]; void *head; char pad2[0x6c31 - 0x1c]; unsigned char flag; };
    register unsigned int outerLevel;
    register unsigned int level;
    register void *it1;
    register void *it2;
    Mgr *m = (Mgr *)arg0;
    outerLevel = OSDisableInterrupts();
    level = OSDisableInterrupts();
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    void *link = (char *)arg1 + 0x1A8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(m->activeList, link);
    it1 = (char *)arg0 + 0x24;
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
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
    it2 = node;
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
extern "C" void fn_800E402C(void *manager) {
    /* Stop the sound emission manager: clear its active flag inside a critical
     * section so no emissions are processed while channels are being released. */
    struct EmissionManager {
        unsigned char pad[0x6C31];
        unsigned char active;
    };
    OSDisableInterrupts();
    ((struct EmissionManager *)manager)->active = 0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void TRKProcessInput(void *, unsigned int);
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800E4064(void *manager) {
    struct Manager {
        unsigned char pad0[0x18];
        void *head;
        unsigned char pad1[0x6c31 - 0x1c];
        unsigned char active;
    };
    /* Walk the emission manager's linked list with interrupts off; for each
     * enabled element, feed every non-null buffer in its row/column table to
     * TRKProcessInput, then restore interrupts. */
    struct Manager *mgr = (Manager *)manager;
    struct { unsigned int irq; } irqHolder;
    unsigned int &level = irqHolder.irq;
    struct { void *head; } cursor;
    void *&node = cursor.head;
    struct { void *end; } sentinelHolder;
    void *&sentinel = sentinelHolder.end;
    level = OSDisableInterrupts();
    node = mgr->head;
    mgr->active = 1;
    sentinel = &mgr->head;
    while (node != sentinel) {
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
        if (*(int *)((char *)node - 0x84) != 0xff) {
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
            int rowIndex;
            int column;
            char *block;
            char *row;
            char *entry;
            block = (char *)node - 0x1a8;
            rowIndex = 0;
            row = block;
            while (rowIndex < *(int *)(block + 0x104)) {
                entry = row;
                column = 0;
                while (column < *(int *)(block + 0x108)) {
                    void *input = *(void **)(entry + 0xC);
                    if (input != 0) TRKProcessInput(input, 0x10);
                    entry += 4;
                    column++;
                }
                row += 0x10;
                rowIndex++;
            }
        }
        node = *(void **)node;
    }
    OSRestoreInterrupts(level);
}
#pragma use_lmw_stmw off
/* Advance every voice on this AxManager's voice list once with interrupts off:
 * each LinkList node sits 0x1A8 into an AxVoice, the list sentinel is at +0x18
 * of the manager, and fn_800E4764 applies one voice's pending AX updates. */
extern "C" void UpdateAllVoices__Q46nw4hbm3snd6detail9AxManagerFv(void *manager) {
    struct { unsigned int irq; } irqState;
    unsigned int &level = irqState.irq;
    struct { void *node; } cursor;
    void *&link = cursor.node;
    struct { void *sentinel; } sentinelHolder;
    void *&end = sentinelHolder.sentinel;
    level = OSDisableInterrupts();
    link = *(void **)((char *)manager + 0x18);
    end = (char *)manager + 0x18;
    while (link != end) {
        void *voiceNode = link;
        link = *(void **)link;
        if (voiceNode == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803220C4, 0x23D, (const char *)lbl_803220A0);
        fn_800E4764((char *)voiceNode - 0x1A8);
    }
    OSRestoreInterrupts(level);
}
#pragma use_lmw_stmw reset
extern "C" void fn_800E41EC(void) {
    if ((signed char)lbl_8055DE18 == 0) {
        fn_800E279C(&lbl_80407F6C);
        __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
        lbl_8055DE18 = 1;
    }
    void *node = *(void **)(lbl_80407F6C + 0xC);
    char *base = lbl_80407F6C;
    do {
        void *current = node;
        node = *(void **)current;
        if (current == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322034, 0x23D, lbl_80322010);
        (*(void (**)())((char *)current + 8))();
        if ((signed char)lbl_8055DE18 == 0) {
            fn_800E279C(&lbl_80407F6C);
            __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
            lbl_8055DE18 = 1;
        }
    } while (node != (void *)(base + 0xC));
    if ((signed char)lbl_8055DE18 == 0) {
        fn_800E279C(base);
        __register_global_object(base, (void *)fn_800E2D74, &lbl_80407F60);
        lbl_8055DE18 = 1;
    }
    if (*(void **)((char *)&lbl_80407F6C + 0x6C2C) != 0) {
        if ((signed char)lbl_8055DE18 == 0) {
            fn_800E279C(&lbl_80407F6C);
            __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
            lbl_8055DE18 = 1;
        }
        void (*cb)(void *) = (void (*)(void *))*(void **)((char *)&lbl_80407F6C + 0x6C2C);
        cb(&lbl_80407F6C);
    }
}
#pragma pop

#pragma use_lmw_stmw reset
extern "C" void Clear__Q46nw4hbm2ut6detail12LinkListImplFv(void *);
extern "C" void AXRegisterAuxACallback(int, int);
extern "C" void AXRegisterAuxBCallback(int, int);
extern "C" void AXRegisterAuxCCallback(int, int);
#pragma push
#pragma optimization_level 3
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
extern "C" void __ct__Q46nw4hbm3snd6detail7AxVoiceFv(void *voice) {
    /* Initialize nw4hbm::snd::detail::AxVoice: clear fields and install the AxVoice vtable. */
    ((unsigned long *)voice)[0x00 / 4] = 0;
    ((unsigned long *)voice)[0x04 / 4] = 0;
    ((unsigned long *)voice)[0x08 / 4] = (unsigned long)&lbl_80322498;
    ((unsigned long *)voice)[0x10C / 4] = 0;
    ((u8 *)voice)[0x11C] = 0;
    ((u8 *)voice)[0x11D] = 0;
    ((u8 *)voice)[0x11E] = 0;
    ((u8 *)voice)[0x11F] = 0;
    ((u8 *)voice)[0x121] = 0;
    ((u8 *)voice)[0x122] = 0;
    ((u8 *)voice)[0x123] = 0;
    ((unsigned long *)voice)[0x1A8 / 4] = 0;
    ((unsigned long *)voice)[0x1AC / 4] = 0;
    ((unsigned long *)voice)[0x0C / 4] = 0;
    ((unsigned long *)voice)[0x10 / 4] = 0;
    ((unsigned long *)voice)[0x14 / 4] = 0;
    ((unsigned long *)voice)[0x18 / 4] = 0;
    ((unsigned long *)voice)[0x1C / 4] = 0;
    ((unsigned long *)voice)[0x20 / 4] = 0;
    ((unsigned long *)voice)[0x24 / 4] = 0;
    ((unsigned long *)voice)[0x28 / 4] = 0;
}

extern "C" int fn_800E4520(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
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
extern "C" void fn_800E4764(void *voice_) {
#define B(off) (*(unsigned char *)((char *)voice_ + (off)))
#define I(off) (*(int *)((char *)voice_ + (off)))
#define CHANNEL_COUNT I(0x104)
#define VOICE_OUT_COUNT I(0x108)
#define ACTIVE B(0x11C)
#define STARTED B(0x11D)
#define PLAYING B(0x11E)
#define PAUSE B(0x11F)
#define PAUSED B(0x120)
#define MUTE B(0x122)
#define UPDATE_FLAGS B(0x123)
#define AX_UPDATE_START 0x01
#define AX_UPDATE_PAUSE 0x02
#define AX_UPDATE_SRC 0x08
#define AX_UPDATE_VOLUME 0x10
#define AX_UPDATE_MIX 0x20
#define AX_UPDATE_LPF 0x40
    /* Applies one AxVoice's pending AX update requests - start, pause/mute,
       source rate, volume, mix and low-pass filter - to its AX voices, clearing
       each flag once applied; when playback has finished, reports it through the
       status callback and clears the active state. */
    int j, i;
    char *col;
    char *row;
    if (ACTIVE != 0) {
        if (PLAYING != 0 && IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(voice_) != 0) {
            void (*cb)(void *, int, int) = *(void (**)(void *, int, int))((char *)voice_ + 0x10C);
            if (cb != 0) {
                cb(voice_, 0, I(0x110));
            }
            PLAYING = 0;
            STARTED = 0;
        }
        if ((UPDATE_FLAGS & AX_UPDATE_START) && STARTED != 0 && PLAYING == 0) {
            UpdateAxSrc__Q46nw4hbm3snd6detail7AxVoiceFb(voice_, 1);
            row = (char *)voice_;
            for (i = 0; i < CHANNEL_COUNT; row += 0x10, i++) {
                col = row;
                for (j = 0; j < VOICE_OUT_COUNT; col += 4, j++) {
                    if (*(void **)(col + 0xC) != 0) AXSetVoiceState(*(void **)(col + 0xC), 1);
                }
            }
            PLAYING = 1;
            UPDATE_FLAGS = UPDATE_FLAGS & ~AX_UPDATE_START;
            UPDATE_FLAGS = UPDATE_FLAGS & ~AX_UPDATE_SRC;
        }
        if (PLAYING != 0) {
            if ((UPDATE_FLAGS & AX_UPDATE_PAUSE) && STARTED != 0) {
                char *row;
                char *col;
                int i, j;
                if (PAUSE != 0 || MUTE != 0 || *(unsigned char *)((char *)Instance__15EmissionManagerFv() + 0x6C33) != 0) {
                    row = (char *)voice_;
                    for (j = 0; j < CHANNEL_COUNT; row += 0x10, j++) {
                        col = row;
                        for (i = 0; i < VOICE_OUT_COUNT; col += 4, i++) {
                            if (*(void **)(col + 0xC) != 0) AXSetVoiceState(*(void **)(col + 0xC), 0);
                        }
                    }
                    PAUSED = 1;
                } else {
                    char *row;
                    char *col;
                    int i, j;
                    col = (char *)voice_;
                    for (j = 0; j < CHANNEL_COUNT; col += 0x10, j++) {
                        row = col;
                        for (i = 0; i < VOICE_OUT_COUNT; row += 4, i++) {
                            if (*(void **)(row + 0xC) != 0) AXSetVoiceState(*(void **)(row + 0xC), 1);
                        }
                    }
                    PAUSED = 0;
                }
                UPDATE_FLAGS = UPDATE_FLAGS & ~AX_UPDATE_PAUSE;
            }
            if (UPDATE_FLAGS & AX_UPDATE_SRC) {
                UpdateAxSrc__Q46nw4hbm3snd6detail7AxVoiceFb(voice_, 0);
                UPDATE_FLAGS = UPDATE_FLAGS & ~AX_UPDATE_SRC;
            }
            if ((UPDATE_FLAGS & AX_UPDATE_VOLUME) && fn_800E6B24(voice_) == 0) {
                UPDATE_FLAGS = UPDATE_FLAGS & ~AX_UPDATE_VOLUME;
            }
            if (UPDATE_FLAGS & AX_UPDATE_MIX) {
                UpdateAxMix__Q46nw4hbm3snd6detail7AxVoiceFv(voice_);
                UPDATE_FLAGS = UPDATE_FLAGS & ~AX_UPDATE_MIX;
            }
            if (UPDATE_FLAGS & AX_UPDATE_LPF) {
                UpdateAxLpf__Q46nw4hbm3snd6detail7AxVoiceFv((char *)voice_);
                UPDATE_FLAGS = UPDATE_FLAGS & ~AX_UPDATE_LPF;
            }
        }
    }
#undef B
#undef I
#undef CHANNEL_COUNT
#undef VOICE_OUT_COUNT
#undef ACTIVE
#undef STARTED
#undef PLAYING
#undef PAUSE
#undef PAUSED
#undef MUTE
#undef UPDATE_FLAGS
#undef AX_UPDATE_START
#undef AX_UPDATE_PAUSE
#undef AX_UPDATE_SRC
#undef AX_UPDATE_VOLUME
#undef AX_UPDATE_MIX
#undef AX_UPDATE_LPF
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
    int rows, ncols, made, result, remaining, i, j;
    unsigned int bufferSize, nextSize;
    int *bufferOut, *bufferIn;
    char *voice, *row, *manager, *node, *sentinel;
    int valid1, valid2;
    valid1 = 0;
    if (count >= 1) {
        if (count <= 2) valid1 = 1;
    }
    if (valid1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0, 0x124, fileName + 0x10, count, 1, 2);
    if (count > 2) rows = 2;
    else {
        rows = 1;
        if (count >= 1) rows = count;
    }
    valid2 = 0;
    if (columns >= 1) {
        if (columns <= 4) valid2 = 1;
    }
    if (valid2 == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0, 0x127, fileName + 0x5C, columns, 1, 4);
    if (columns > 4) ncols = 4;
    else {
        ncols = 1;
        if (columns >= 1) ncols = columns;
    }
    interruptState = OSDisableInterrupts();
    bufferSize = 0x10;
    if (priority == 0xFF) bufferSize = 0x1F;
    if (*((unsigned char *)self + 0x11C) != 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0, 0x12E, fileName + 0xA8);
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
        if (result == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0, 0x167, fileName + 0xD0);
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
/* AxVoice::Free() - release an active AX voice: with interrupts disabled, return
 * every DSP buffer in its buffer table (+0x104 rows x +0x108 columns, rows 0x10
 * bytes, buffer pointer at entry+0xC) to the free pool, clear the table, unregister
 * its dispose callback, free the voice from the AxManager and clear its active flag
 * (+0x11C). Does nothing if the voice is not active. */
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *voice) {
    int zero = 0;
    struct { unsigned int irq; } irqHolder;
    unsigned int &interruptState = irqHolder.irq;
    interruptState = OSDisableInterrupts();
    if (*((unsigned char *)voice + 0x11C) == zero) {
        OSRestoreInterrupts(interruptState);
        return;
    }
    char *row = (char *)voice;
    char *entry;
    int rowIndex = zero;
    while (rowIndex < *((int *)((char *)voice + 0x104))) {
        entry = row;
        int column = zero;
        while (column < *((int *)((char *)voice + 0x108))) {
            if (*((int *)(entry + 0xC)) != zero) {
                TRKGetFreeBuffer(*((void **)(entry + 0xC)));
                *((int *)(entry + 0xC)) = zero;
            }
            entry += 4;
            column++;
        }
        row += 0x10;
        rowIndex++;
    }
    *((int *)((char *)voice + 0x104)) = zero;
    UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
        GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), voice);
    FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(
        Instance__15EmissionManagerFv(), voice);
    *((unsigned char *)voice + 0x11C) = zero;
    OSRestoreInterrupts(interruptState);
}
#pragma pop
extern float lbl_80560F44;
extern const char lbl_803222A0[];
extern "C" void fn_800E5E74(void *, int, int, int, int, int, int);
extern "C" void fn_800E68EC(void *, int, volatile unsigned char, void *, int);
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

/* Bits of AxVoice::updateFlags (+0x123).  Setters ask for one thing to be pushed
 * to the AX voices; the update pass fn_800E4764, run over every live AxVoice by
 * AxManager::UpdateAllVoices, does it and clears the bit again. */
enum AxVoiceUpdateFlag {
    AX_UPDATE_START = 0x01,   /* start playing: apply the source rate, then set the AX voices playing */
    AX_UPDATE_PAUSE = 0x02,   /* re-apply the pause/mute state to the AX voices */
    AX_UPDATE_SRC = 0x08,     /* refresh the AX source rate */
    AX_UPDATE_VOLUME = 0x10,  /* ramp the AX volumes to their target (fn_800E6B24) */
    AX_UPDATE_MIX = 0x20,     /* refresh the mix levels (UpdateAxMix) */
    AX_UPDATE_LPF = 0x40      /* refresh the low-pass filter (UpdateAxLpf) */
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
    voice->updateFlags |= AX_UPDATE_VOLUME | AX_UPDATE_MIX | AX_UPDATE_LPF;   /* a full AX update */
}
/* RealName: Start__Q46nw4hbm3snd6detail7AxVoiceFv - asks this AxVoice to start
 * playing: marks it started (+0x11D), clears its pause flag (+0x11F) and sets the
 * start bit of the AX update flags (+0x123); the update pass fn_800E4764 then
 * applies the source rate and sets this voice's AX voices playing.  The three
 * writes are held under an interrupt lock, the same lock AxManager::UpdateAllVoices
 * takes while it walks the live voices, so the request is never seen half applied.
 * Callers reach it through the AxVoice they own: Channel::Start (channel+0xE0),
 * StrmPlayer::Start (self+0x438) and fn_800FF090 (self+0x18). */
extern "C" void fn_800E519C(void *arg0) {
    unsigned int level = OSDisableInterrupts();
    AxVoice *voice = (AxVoice *)arg0;
    voice->started = 1;
    voice->pause = 0;
    voice->updateFlags |= AX_UPDATE_START;
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
/* Pause or unpause this voice, marking its AX parameters dirty when the pause state changes. */
extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void *voice, u8 pauseFlag) {
    unsigned int interrupts = OSDisableInterrupts();
    if (*(u8 *)((char *)voice + 0x11F) == pauseFlag) {
        OSRestoreInterrupts(interrupts);
        return;
    }
    *(u8 *)((char *)voice + 0x11F) = pauseFlag;
    u8 syncFlags = *(u8 *)((char *)voice + 0x123);
    *(u8 *)((char *)voice + 0x123) = syncFlags | 2;
    OSRestoreInterrupts(interrupts);
}

extern "C" void fn_800E5338(void *voice, float volume) {
    /* Clamp volume to [0.0, 1.0], store at +0x188, and set dirty flag 0x10 at +0x123 when changed. */
    float clampedVolume;
    if (volume > lbl_80560F38) {
        clampedVolume = lbl_80560F38;
    } else if (volume < lbl_80560F3C) {
        clampedVolume = lbl_80560F3C;
    } else {
        clampedVolume = volume;
    }
    float *volumeField = (float *)((char *)voice + 0x188);
    if (clampedVolume != *volumeField) {
        unsigned char *updateFlags = (unsigned char *)voice + 0x123;
        *volumeField = clampedVolume;
        *updateFlags |= 0x10;
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

extern "C" void fn_800E5444(AxVoice *voice, float rate) {
    /* When the playback rate changes, store it and flag an AX source-rate refresh. */
    if (rate != voice->playbackRate) {
        voice->playbackRate = rate;
        voice->updateFlags |= AX_UPDATE_SRC;
    }
}

extern float lbl_80560F38;
extern float lbl_80560F50;
extern float lbl_80560F54;
extern float lbl_80560F3C;
extern "C" void fn_800E5464(void *arg0, float arg1) {
    /* Clamp pan to [-1,1] and store at +0x128, marking dirty flag 0x20 at +0x123. */
    #define kPanMax    lbl_80560F38
    #define kPanMin    lbl_80560F50
    #define panField   (*(float *)((char *)arg0 + 0x128))
    #define updateFlags (*(unsigned char *)((char *)arg0 + 0x123))

    float value;
    if (arg1 > kPanMax) {
        value = kPanMax;
    } else if (arg1 < kPanMin) {
        value = kPanMin;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x128);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }

    #undef kPanMax
    #undef kPanMin
    #undef panField
    #undef updateFlags
}

extern "C" void fn_800E54A8(void *obj, float value) {
    /* Clamp value to [0.0, 2.0], store at +0x12C if changed, and set the 0x20 flag. */
    float clamped;
    if (value > lbl_80560F54) {
        clamped = lbl_80560F54;
    } else if (value < lbl_80560F3C) {
        clamped = lbl_80560F3C;
    } else {
        clamped = value;
    }
    float *field = (float *)((char *)obj + 0x12C);
    if (clamped != *field) {
        unsigned char *flags = (unsigned char *)obj + 0x123;
        *field = clamped;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E54EC(void *voice, float value) {
    /* Set this voice's +0x130 float parameter when it changes, marking the voice dirty via flag 0x20 at +0x123. */
    if (value != *(float *)((char *)voice + 0x130)) {
        *(float *)((char *)voice + 0x130) = value;
        *(unsigned char *)((char *)voice + 0x123) |= 0x20;
    }
}

/* Clamps the input to [0.0, 2.0] and stores it at voice+0x134, setting dirty flag 0x20 at +0x123 if changed. */
extern "C" void fn_800E550C(void *voice, float value) {
    float clamped;
    if (value > lbl_80560F54) {
        clamped = lbl_80560F54;
    } else if (value < lbl_80560F3C) {
        clamped = lbl_80560F3C;
    } else {
        clamped = value;
    }
    float *field = (float *)((char *)voice + 0x134);
    if (clamped != *field) {
        unsigned char *flags = (unsigned char *)voice + 0x123;
        *field = clamped;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E5550(void *arg0, float arg1) {
    float clamped;
    if (arg1 > lbl_80560F38) {
        clamped = lbl_80560F38;
    } else if (arg1 < lbl_80560F3C) {
        clamped = lbl_80560F3C;
    } else {
        clamped = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x138);
    if (clamped != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = clamped;
        *flags |= 0x40;
    }
}

/* Set this AxVoice's +0x13C parameter when it changes, marking the voice dirty
 * for a mix refresh (AX_UPDATE_MIX) through its update flags. */
extern "C" void fn_800E5594(void *voice, int value) {
    int *field = (int *)((char *)voice + 0x13c);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)voice + 0x123;
        *field = value;
        *flags |= AX_UPDATE_MIX;
    }
}

extern "C" void fn_800E55B4(void *arg0, float arg1) {
    /* Clamp arg1 to [0.0, 1.0], update the float field at +0x140, and mark voice
     * parameter state dirty (flag 0x20 at +0x123) if it changed. */
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
/* Clamps (delta + 1.0) to [0.0, 1.0] and updates the field at offset 0x144, setting flag 0x20 at 0x123 if changed. */
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

/* Get the DSP's current sample address for this AX voice, or 0 if none. */
extern "C" int GetCurrentPlayingDspAddress__Q46nw4hbm3snd6detail7AxVoiceCFv(void *axVoice) {
    unsigned int enabled = OSDisableInterrupts();
    void *vpb = *(void **)((char *)axVoice + 0xc);
    void *pb = (char *)vpb + 0x138;
    if (pb == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    int address = (*(unsigned short *)((char *)pb + 0x84) << 16) +
                  *(unsigned short *)((char *)pb + 0x86);
    OSRestoreInterrupts(enabled);
    return address;
}

/* Voice-mix alias: forwards its four arguments unchanged to fn_800E6A44 via a tail call. */
extern "C" void fn_800E5A8C(void *arg0, int arg1, int arg2, void *arg3) {
    fn_800E6A44(arg0, arg1, arg2, arg3);
}

extern "C" void fn_80033538(unsigned short);
/* nw4hbm::snd::detail::AxVoice::SetBaseAddress(int, const void*): point one of
 * this voice's channels at new sample data.  Interrupts stay off across the
 * store so the AX mixers never read a half-updated address. */
extern "C" void SetBaseAddress__Q46nw4hbm3snd6detail7AxVoiceFiPCv(AxVoice *voice, int channelIndex, const void *address) {
    unsigned int level = OSDisableInterrupts();
    voice->channel[channelIndex].dataAddr = (void *)address;
    OSRestoreInterrupts(level);
}

/* AxVoice::IsPlayFinished(): true when the voice's DSP play position has
 * reached the silence (zero) buffer's end region for its sample format.  The
 * play position and the buffer end are read under an interrupt lock; the two
 * single-field structs keep those values in callee-saved registers. */
extern "C" int IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(void *self) {
    struct IrqWrap { unsigned int i; } irqState;
    struct StartWrap { unsigned int s; } playPos;
    struct EndWrap { unsigned int e; } zeroEnd;
    unsigned int posLimit, zeroBuffer;
    int format;
    irqState.i = OSDisableInterrupts();
    if (*(int *)((char *)self + 0x2c) == 0) { OSRestoreInterrupts(irqState.i); return 0; }
    unsigned int innerLevel = OSDisableInterrupts();
    posLimit = *(unsigned int *)((char *)self + 0xc) + 0x138;
    if (posLimit == 0) { OSRestoreInterrupts(innerLevel); playPos.s = 0; }
    else {
        unsigned short posHi = *(unsigned short *)(posLimit + 0x84);
        unsigned short posLo = *(unsigned short *)(posLimit + 0x86);
        playPos.s = ((unsigned int)posHi << 16) + posLo;
        OSRestoreInterrupts(innerLevel);
    }
    void *manager = Instance__15EmissionManagerFv();
    zeroBuffer = (unsigned int)GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(manager);
    format = *(int *)((char *)self + 0x118);
    if (zeroBuffer != 0) zeroBuffer += 0x80000000;
    zeroEnd.e = 0;
    switch (format) {
    case 0: zeroEnd.e = zeroBuffer * 2 + 2; break;
    case 25: zeroEnd.e = zeroBuffer; break;
    case 10: zeroEnd.e = zeroBuffer >> 1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438); break;
    }
    posLimit = zeroEnd.e;
    switch (*(int *)((char *)self + 0x118)) {
    case 0: posLimit = zeroEnd.e + 0x200; break;
    case 25: posLimit = zeroEnd.e + 0x100; break;
    case 10: posLimit = zeroEnd.e + 0x80; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x362, lbl_80322438); break;
    }
    if (zeroEnd.e <= playPos.s && playPos.s < posLimit) { OSRestoreInterrupts(irqState.i); return 1; }
    OSRestoreInterrupts(irqState.i);
    return 0;
}

#pragma use_lmw_stmw off
extern "C" int GetCurrentPlayingSample__Q46nw4hbm3snd6detail7AxVoiceCFv(void *self)
{
  struct Holder
  {
    int v;
  } h;
  int *size = &h.v;
  int level;
  int position;
  int format;
  unsigned int p;
  p = (unsigned int) self;
  level = OSDisableInterrupts();
  *size = *((int *) (p + 0x2C));
  if ((*size) == 0)
  {
    OSRestoreInterrupts(level);
    return 0;
  }
  if (IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv((void *) p))
  {
    int inner = OSDisableInterrupts();
    unsigned char *pos = (*((unsigned char **) (p + 0xC))) + 0x138;
    if (pos == 0)
    {
      OSRestoreInterrupts(inner);
      position = 0;
    }
    else
    {
      position = (((int) (*((unsigned short *) (pos + 0x80)))) << 16) + (*((unsigned short *) (pos + 0x82)));
      OSRestoreInterrupts(inner);
    }
    format = *((int *) (p + 0x118));
    if ((*size) != 0)
    {
      *size += (int) 0x80000000;
    }
    int result = 0;
    switch (format)
    {
      case 0:
      {
        unsigned int rem = position - ((*size) * 2);
        result = ((rem & 0xF) + ((rem >> 4) * 0xE)) - 2;
        break;
      }

      case 25:
        result = position - (*size);
        break;

      case 10:
        result = position - (((unsigned int) (*size)) >> 1);
        break;

      default:
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x583, lbl_80322438);
        break;

    }

    OSRestoreInterrupts(level);
    return result + 1;
  }
  else
  {
    int inner = OSDisableInterrupts();
    unsigned char *pos = (*((unsigned char **) (p + 0xC))) + 0x138;
    if (pos == 0)
    {
      OSRestoreInterrupts(inner);
      position = 0;
    }
    else
    {
      position = (((int) (*((unsigned short *) (pos + 0x84)))) << 16) + (*((unsigned short *) (pos + 0x86)));
      OSRestoreInterrupts(inner);
    }
    format = *((int *) (p + 0x118));
    if (0 != (*size))
    {
      *size += (int) 0x80000000;
    }
    int result = 0;
    switch (format)
    {
      case 0:
      {
        unsigned int rem = position - ((*size) * 2);
        result = ((rem & 0xF) + ((rem >> 4) * 0xE)) - 2;
        break;
      }

      case 25:
        result = position - (*size);
        break;

      case 10:
        result = position - (((unsigned int) (*size)) >> 1);
        break;

      default:
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x583, lbl_80322438);
        break;

    }

    OSRestoreInterrupts(level);
    return result;
  }
}
#pragma use_lmw_stmw reset
extern const char lbl_80322400[];
extern "C" void fn_8003381C(void *, void *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
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
        Panic__Q26nw4hbm2dbFPCciPCce(f, 0x396, f + 0x258);
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
        default: Panic__Q26nw4hbm2dbFPCciPCce(f, 0x561, f + 0x290); break;
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
        default: Panic__Q26nw4hbm2dbFPCciPCce(f, 0x561, f + 0x290); break;
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
        default: Panic__Q26nw4hbm2dbFPCciPCce(f, 0x561, f + 0x290); break;
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
        default: Panic__Q26nw4hbm2dbFPCciPCce(f, 0x561, f + 0x290); break;
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
#pragma pop

#pragma push
#pragma dont_inline off
namespace nw4hbm { namespace ut {
/* Scoped interrupt disable (nw4hbm::ut::AutoInterruptLock). */
class AutoInterruptLock {
public:
    AutoInterruptLock() { mOldState = OSDisableInterrupts(); }
    ~AutoInterruptLock() { OSRestoreInterrupts(mOldState); }
private:
    int mOldState;
};
}}
#pragma pop

namespace nw4hbm { namespace snd { namespace detail {
class AxVoice {
public:
    void SetLoopStart(int, const void *, unsigned long);
    void SetLoopEnd(int, const void *, unsigned long);
};
}}}
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline off
/* Queue the loop start of channel `channelIndex` at `sampleCount` samples into the
 * stream that starts at `address` (snd_AxVoice.cpp:561).
 * The address is first converted to the DSP-visible form, then to the unit the
 * voice's loop-address register counts in for the stream's format (+0x118):
 * 0 ADPCM - 4-bit units, a 14-sample frame being 16 of them plus a 2-unit header;
 * 25 - 8-bit samples, one unit each; 10 - 16-bit samples, one unit per two bytes.
 * Every AX voice of the channel gets the new loop start, split into its 16-bit
 * halves, and AX_PBSYNC_LOOP_ADDR (0x2000) is queued for the next __AXSyncPBs
 * unless the voice is already resyncing its address group (AX_PBSYNC_ADDR). */
extern "C" void SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *self, int channelIndex, const void *address, unsigned long sampleCount) {
    nw4hbm::ut::AutoInterruptLock lock;
    int format = *(int *)((char *)self + 0x118);
    unsigned int dspAddress = (unsigned int)address;
    unsigned int loopAddress;
    if (address != 0) dspAddress += 0x80000000;
    loopAddress = 0;
    switch (format) {
    case 0:
        loopAddress = sampleCount % 14 + dspAddress * 2 + (sampleCount / 14) * 16 + 2;
        break;
    case 25:
        loopAddress = dspAddress + sampleCount;
        break;
    case 10:
        loopAddress = (dspAddress >> 1) + sampleCount;
        break;
    default:
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438);
        break;
    }
    unsigned int *voice = (unsigned int *)((char *)self + channelIndex * 0x10);
    unsigned int ch;
    unsigned int loopHi = loopAddress >> 16;
    unsigned int loopLo = loopAddress & 0xFFFF;
    for (int i = 0; i < *(int *)((char *)self + 0x108); voice++, i++) {
        ch = voice[3];
        unsigned int inner = OSDisableInterrupts();
        *(unsigned short *)(ch + 0x1B4) = loopHi;
        *(unsigned short *)(ch + 0x1B6) = loopLo;
        if (!(*(unsigned int *)(ch + 0x1C) & 0x800)) *(unsigned int *)(ch + 0x1C) |= 0x2000;
        OSRestoreInterrupts(inner);
    }
}
#pragma pop

/* The AX voice parameter block (AXVPB) an AxVoice slot holds: only as far as
   the address setters reach.  Its +0x1C holds the sync bits __AXSyncPBs acts
   on, and the DSP block starts at +0x138, whose address group is at +0x78.
   revolution/AX/AXVPB.h has the whole layout; this TU has no SDK includes. */
struct AxVoicePB {
    char pad_00[0x1C];
    /* 0x1C */ unsigned int sync;
    char pad_20[0x1B0 - 0x20];
    struct {
        /* 0x1B0 */ unsigned short loopFlag;
        /* 0x1B2 */ unsigned short format;
        /* 0x1B4 */ unsigned short loopAddressHi;
        /* 0x1B6 */ unsigned short loopAddressLo;
        /* 0x1B8 */ unsigned short endAddressHi;
        /* 0x1BA */ unsigned short endAddressLo;
    } addr;
};

/* Bits of AxVoicePB::sync (the AX_PBSYNC_* enum of revolution/AX/AXVPB.h)
   that queue one of the address fields for the next __AXSyncPBs. */
enum {
    AX_PBSYNC_ADDR      = 0x800,  /* the address group as a whole */
    AX_PBSYNC_LOOP_FLAG = 0x1000,
    AX_PBSYNC_LOOP_ADDR = 0x2000,
    AX_PBSYNC_END_ADDR  = 0x4000
};

/* An AxVoice is a grid of AX voices: *(int*)this+0x104 rows of *(int*)this+0x108
   16-byte entries, each holding the AX voice (an AxVoicePB) at +0xC; the sample
   format of the stream they all play is at +0x118. */
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline off
/* Queue the loop end of channel `channelIndex` at `sampleCount` samples into the
 * stream that starts at `address` (snd_AxVoice.cpp:561).
 * The address is first taken in the form the DSP sees it, then converted to the
 * unit the voice's end-address register counts in for the stream's format
 * (+0x118): 0 ADPCM - 4-bit units, a 14-sample frame being 16 of them plus a
 * 2-unit header; 25 - 8-bit samples, one unit each; 10 - 16-bit samples, one
 * unit per two bytes.  Every AX voice of the channel gets the new end, split
 * into its 16-bit halves, and the AX_PBSYNC_END_ADDR bit queued so the next
 * __AXSyncPBs hands it to the DSP - unless the voice is already resyncing its
 * address group (AX_PBSYNC_ADDR), which would pick it up anyway. */
void nw4hbm::snd::detail::AxVoice::SetLoopEnd(int channelIndex, const void *address, unsigned long sampleCount) {
    nw4hbm::ut::AutoInterruptLock lock;
    int format = *(int *)((char *)this + 0x118);
    unsigned int dspAddress = (unsigned int)address;
    unsigned int endAddress;
    if (address != 0) dspAddress += 0x80000000;
    endAddress = 0;
    switch (format) {
    case 0:
        endAddress = (sampleCount - 1) % 14 + dspAddress * 2 + ((sampleCount - 1) / 14) * 16 + 2;
        break;
    case 25:
        endAddress = dspAddress + sampleCount - 1;
        break;
    case 10:
        endAddress = (dspAddress >> 1) + sampleCount - 1;
        break;
    default:
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438);
        break;
    }
    unsigned int *entry = (unsigned int *)((char *)this + channelIndex * 0x10);
    AxVoicePB *vpb;
    unsigned int endHi = endAddress >> 16;
    unsigned int endLo = endAddress & 0xFFFF;
    for (int i = 0; i < *(int *)((char *)this + 0x108); entry++, i++) {
        vpb = (AxVoicePB *)entry[3];
        unsigned int savedIrq = OSDisableInterrupts();
        vpb->addr.endAddressHi = endHi;
        vpb->addr.endAddressLo = endLo;
        if (!(vpb->sync & AX_PBSYNC_ADDR)) vpb->sync |= AX_PBSYNC_END_ADDR;
        OSRestoreInterrupts(savedIrq);
    }
}
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

#pragma dont_inline off
extern "C" void StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(AxVoice *self, int channelIndex, const void *address, unsigned long length) {
    /* Stop one channel's AX voices when they reach the end of the given
       sample range.  Their loop start is moved to the AxManager's zero
       buffer, so the voice runs into silence, their end address to the last
       sample of the range, and their loop flag is cleared, so the mixer stops
       them there instead of wrapping around.  The three fields are written
       one at a time with interrupts off, each queueing its own AX_PBSYNC bit
       for __AXSyncPBs -- unless the voice already has the whole address group
       queued, which then covers the write.  Positions are counted in the unit
       the PB address field uses for the wave's format: one sample per unit,
       an ADPCM frame carrying two units of header every 14 samples. */
    nw4hbm::ut::AutoInterruptLock lock;
#pragma dont_inline on
    void *axManager = Instance__15EmissionManagerFv();
    register unsigned int zeroBuffer = (unsigned int)GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(axManager);
    unsigned int format = self->format;
    if (zeroBuffer) zeroBuffer += 0x80000000;
    s32 silencePos = 0;
    switch (format) {
    case AX_FORMAT_ADPCM: silencePos = zeroBuffer * 2 + 2; break;
    case AX_FORMAT_PCM8: silencePos = zeroBuffer; break;
    case AX_FORMAT_PCM16: silencePos = zeroBuffer >> 1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438); break;
    }
    unsigned int stopAddr = (unsigned int)address;
    int stopFormat = self->format;
    if (stopAddr) stopAddr += 0x80000000;
    unsigned int stopPos = 0;
    switch (stopFormat) {
    case AX_FORMAT_ADPCM: {
        u32 last = length - 1;
        stopPos = (last % 14) + (stopAddr * 2) + ((last / 14) * 16) + 2;
        break;
    }
    case AX_FORMAT_PCM8: stopPos = stopAddr + length - 1; break;
    case AX_FORMAT_PCM16: stopPos = length + (stopAddr >> 1) - 1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438); break;
    }
    void **slot = (void **)((char *)self + channelIndex * 0x10);
    unsigned int startHi = (unsigned int)silencePos >> 16;
    unsigned int startLo = silencePos & 0xFFFF;
    unsigned int endHi = stopPos >> 16;
    unsigned int endLo = stopPos & 0xFFFF;
    for (int i = 0; i < self->voiceOutCount; slot++, i++) {
        AxVoicePB *vpb = (AxVoicePB *)slot[3]; /* a channel's voice slots start at +0xC of its row */
        if (vpb != 0) {
            unsigned int level = OSDisableInterrupts();
            vpb->addr.loopAddressHi = startHi;
            vpb->addr.loopAddressLo = startLo;
            if (!(vpb->sync & AX_PBSYNC_ADDR)) vpb->sync |= AX_PBSYNC_LOOP_ADDR;
            OSRestoreInterrupts(level);
            level = OSDisableInterrupts();
            vpb->addr.endAddressHi = endHi;
            vpb->addr.endAddressLo = endLo;
            if (!(vpb->sync & AX_PBSYNC_ADDR)) vpb->sync |= AX_PBSYNC_END_ADDR;
            OSRestoreInterrupts(level);
            level = OSDisableInterrupts();
            vpb->addr.loopFlag = 0;
            if (!(vpb->sync & AX_PBSYNC_ADDR)) vpb->sync |= AX_PBSYNC_LOOP_FLAG;
            OSRestoreInterrupts(level);
        }
    }
#pragma dont_inline off
}
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
extern "C" void UpdateAxSrc__Q46nw4hbm3snd6detail7AxVoiceFb(void *arg0, int arg1)
{
  struct V
  {
    unsigned char *src;
    int offset;
    unsigned char *channel;
    int i;
    int j;
    int mode;
    unsigned char *self;
  } v;
  float gain = lbl_80560F58;
  float min = lbl_80560F3C;
  float max = lbl_80560F38;
  float volume;
  float ratio;
  short values[7];
  v.self = (unsigned char *) arg0;
  v.mode = arg1;
  v.src = v.self;
  v.offset = 0;
  v.i = 0;
  {
    float scale = (float) (*((int *) (v.self + 0x114)));
    ratio = ((*((float *) (v.self + 0x184))) * scale) / lbl_80560F40;
  }
  while (v.i < (*((int *) (v.self + 0x108))))
  {
    volume = *((float *) (v.src + 0x98));
    if (volume > max)
    {
      volume = max;
    }
    else
      if (volume < min)
    {
      volume = min;
    }
    if (v.mode != 0)
    {
      float scaled = gain * ratio;
      unsigned int sample = (unsigned int) (scaled * volume);
      values[0] = (short) (sample >> 16);
      values[1] = (short) sample;
      values[2] = 0;
      values[3] = 0;
      values[4] = 0;
      values[5] = 0;
      values[6] = 0;
      v.channel = v.self + v.offset;
      for (v.j = 0; v.j < (*((int *) (v.self + 0x104))); v.j++)
      {
        fn_800339B0(*((void **) (v.channel + 0xc)), values);
        v.channel += 0x10;
      }

    }
    else
    {
      v.channel = v.self + v.offset;
      for (v.j = 0; v.j < (*((int *) (0x104 + v.self))); v.j++)
      {
        fn_80033A34(*((void **) (v.channel + 0xc)), ratio * volume);
        v.channel += 0x10;
      }

    }
    v.src += 0x1c;
    v.offset += 4;
    v.i++;
  }

}

extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void fn_80033918(void *, void *);
extern "C" void fn_800E68EC(void *arg0, int arg1, volatile unsigned char arg2, void *arg3, int arg4)
{
  const char *message = lbl_803221A8;
  void **entry;
  unsigned char sp8[0x28];
  int i;
  if (arg1 >= 2)
  {
    Panic__Q26nw4hbm2dbFPCciPCce(message, 0x434, message + 0x258);
  }
  switch (arg2)
  {
    case 0:
      if (arg3 == 0)
    {
      Panic__Q26nw4hbm2dbFPCciPCce(message, 0x439, message + 0x2A0);
    }
      memcpy(sp8, arg3, 0x20);
      *((u16 *) (sp8 + 0x20)) = *((u16 *) (((char *) arg3) + 0x20));
      *((u16 *) (sp8 + 0x22)) = *((u16 *) (((char *) arg3) + 0x22));
      *((u16 *) (sp8 + 0x24)) = *((u16 *) (((char *) arg3) + 0x24));
      *((u16 *) (sp8 + 0x26)) = *((u16 *) (((char *) arg3) + 0x26));
      break;

    case 10:
      memset(sp8, 0, 0x20);
      *((u16 *) (sp8 + 0x20)) = 0x800;
      *((u16 *) (sp8 + 0x22)) = 0;
      *((u16 *) (sp8 + 0x24)) = 0;
      *((u16 *) (sp8 + 0x26)) = 0;
      break;

    case 25:
      memset(sp8, 0, 0x20);
      *((u16 *) (sp8 + 0x20)) = 0x100;
      *((u16 *) (sp8 + 0x22)) = 0;
      *((u16 *) (sp8 + 0x24)) = 0;
      *((u16 *) (sp8 + 0x26)) = 0;
      break;

  }

  entry = (void **) (((char *) arg0) + (arg1 << 4));
  for (i = 0; 0 <= ((*((int *) (((char *) arg0) + 0x108))) - 1); i++)
  {
    fn_80033918(entry[3], sp8);
    entry = (void **) (((char *) entry) + 4);
  }

}

#pragma opt_lifetimes off
extern "C" void fn_800E6A44(void *arg0, int arg1, int arg2, void *arg3) {
    const char *file = lbl_803221A8;
    unsigned short mix[3];
    unsigned char *voice;
    int i;

    if (arg1 >= 2) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x458, file + 0x258);
    }
    if (arg2 == 0) {
        if (arg3 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x45C, file + 0x2A0);
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
    /* Update per-channel AX LPF settings from the voice's base and channel LPF frequencies. */
    struct ChannelParam {
        float lpfFreq;
        char pad[0x18];
    };
    struct AxVoiceView {
        char pad0[0xc];
        void *vpb[4][4];
        char pad4c[0xa8 - 0x4c];
        ChannelParam param[3];
        char padfc[0x104 - 0xfc];
        int voiceOutCount;
        int channelCount;
        char pad10c[0x138 - 0x10c];
        float lpfFreq;
    };
#define voice ((AxVoiceView *)self)
    unsigned short localCoefs[10];

    for (int channel = 0; channel < voice->channelCount; channel++) {
        unsigned short rate = CalcLpfFreq__Q46nw4hbm3snd6detail4UtilFf(voice->lpfFreq + voice->param[channel].lpfFreq);
        if (rate >= 0x3e80) {
            localCoefs[8] = 0;
            localCoefs[9] = 0;
            for (int outIdx = 0; outIdx < voice->voiceOutCount; outIdx++)
                fn_80033B0C(voice->vpb[outIdx][channel], (short *)&localCoefs[8]);
        } else if (*(unsigned short *)((char *)voice->vpb[0][0] + 0x1fc) == 1) {
            AXGetLpfCoefs(rate, &localCoefs[1], &localCoefs[0]);
            for (int outIdx = 0; outIdx < voice->voiceOutCount; outIdx++)
                fn_80033B74(voice->vpb[outIdx][channel], localCoefs[1], localCoefs[0]);
        } else {
            localCoefs[4] = 1;
            localCoefs[5] = 0;
            AXGetLpfCoefs(rate, &localCoefs[6], &localCoefs[7]);
            for (int outIdx = 0; outIdx < voice->voiceOutCount; outIdx++)
                fn_80033B0C(voice->vpb[outIdx][channel], (short *)&localCoefs[4]);
        }
    }
#undef voice
}

extern "C" unsigned int __mulhwu(unsigned int, unsigned int);
extern "C" int GetDspAddressBySample__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(const void* arg0, unsigned long arg1, int arg2) {
    unsigned long base = (unsigned long)arg0;
    if (base != 0) base += 0x80000000UL;
    int result = 0;
    switch (arg2) {
    case 0: {
        unsigned long sample = arg1;
        unsigned long doubled = base << 1;
        unsigned long q = __mulhwu(0x24924925U, (unsigned int)sample);
        unsigned long block = q + ((sample - q) >> 1);
        unsigned long rem = sample - ((block >> 3) * 14);
        result = (int)((block << 1) & 0xFFFFFFF0UL) + (int)(rem + doubled) + 2;
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

/* The blends TransformDpl2Pan maps a voice's 2D pan point through, all f32s
   this unit keeps in its small data section.  The generic ones next to them
   are lbl_80560F38 = 1.0, the height of the field's centre, lbl_80560F3C =
   0.0 and lbl_80560F54 = 2.0, the field's full depth. */
#define DPL2_Y_BIAS  lbl_80560F60 /* -0.12: depth before the centre is added back */
#define DPL2_Y_FRONT lbl_80560F64 /*  0.88: depth a step forward, or to the side, is worth */
#define DPL2_X_BACK  lbl_80560F68 /*  0.5: pan a point straight behind centre keeps */
#define DPL2_Y_BACK  lbl_80560F6C /*  1.12: depth a step behind centre, or to the side, is worth */
#define DPL2_X_SIDE  lbl_80560F70 /*  0.85: pan of a point straight to the side */
#define DPL2_X_FRONT lbl_80560F74 /*  0.15: pan a step forward adds to the side's */
#define DPL2_X_REAR  lbl_80560F78 /*  0.35: pan a step behind adds to the side's */

#pragma fp_contract_aggressive reset
#pragma fp_contract off
void nw4r::snd::detail::Voice::TransformDpl2Pan(float *outPan, float *outSurround, float x, float y) {
    /* Fold a voice's 2D DPL2 pan point into the two numbers the mixer blends
       its speaker levels from: *outPan is the left/right pan (what
       CalcPanRatio is called with) and *outSurround the front-to-back
       position on the 0 = front, 2 = back scale CalcSurroundPanRatio is called
       with.  The point (x, y) has the field's centre at (0, 1); the plane is
       cut by |x| against |y - 1| and by the two signs into four regions, each
       an affine blend of x and y through the DPL2_* constants, so the centre,
       the edges and the corners of the pan field land where the DPL2 decoder
       wants them -- moving to the side pushes the sound back, and a point
       straight behind centre keeps only half of its pan.  The depth comes
       back with the centre added on, so a dead-centre voice is (0, 0.88). */
    float back = y - lbl_80560F38;
    float absX = __fabsf(x);
    float absBack = __fabsf(back);
    if (absX <= absBack) {
        /* ahead of or behind the centre: the pan is the point's own */
        if (back <= lbl_80560F3C) {
            float p = DPL2_Y_FRONT * back;
            float depth = DPL2_Y_BIAS + p;
            *outPan = x;
            *outSurround = depth;
        } else {
            float q = DPL2_X_BACK * x;
            float depth = DPL2_Y_BIAS + DPL2_Y_BACK * back;
            *outPan = q;
            *outSurround = depth;
        }
    } else if (x >= lbl_80560F3C) {
        /* to the right of centre: the side's pan, nudged by how far forward
           or behind the point is, and a depth that grows with the pan */
        if (back <= lbl_80560F3C) {
            float ratio = -back / x;
            float scale = DPL2_X_SIDE + DPL2_X_FRONT * ratio;
            float depth = DPL2_Y_BIAS + (lbl_80560F54 * back + DPL2_Y_FRONT * x);
            scale *= absX;
            *outPan = scale;
            *outSurround = depth;
        } else {
            float ratio = -back / x;
            float depth, scale;
            scale = DPL2_X_SIDE + DPL2_X_REAR * ratio;
            depth = DPL2_Y_BIAS + DPL2_Y_BACK * x;
            *outPan = scale * absX;
            *outSurround = depth;
        }
    } else if (back <= lbl_80560F3C) {
        /* to the left of centre, the two above mirrored */
        float ratio = -back / x;
        float scale = DPL2_X_FRONT * ratio - DPL2_X_SIDE;
        float depth = DPL2_Y_BIAS + (lbl_80560F54 * back - DPL2_Y_BACK * x);
        scale *= absX;
        *outPan = scale;
        *outSurround = depth;
    } else {
        float ratio = -back / x;
        float scale = DPL2_X_REAR * ratio - DPL2_X_SIDE;
        float depth = DPL2_Y_BIAS + DPL2_Y_BACK * -x;
        *outPan = scale * absX;
        *outSurround = depth;
    }
    *outSurround += lbl_80560F38;
}
extern "C" void CalcAXPBMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP8_AXPBMIX(void *arg0, int arg1, int arg2, void *arg3) {
    double f27, f28, f29, f30, f31, f23;
    float f22;
    float f21, f20, f19, f18, f17;
    float spC, sp8;
    char *self = (char *)arg0;
    unsigned short *out = (unsigned short *)arg3;
    f22 = 1.0f;
    f21 = f22; f23 = f22; f20 = f22; f19 = f22; f31 = f22;
    f18 = f22; f17 = f22; f30 = f22; f29 = f22; f28 = f22; f27 = f22;
    int mode = fn_800E394C((int *)Instance__15EmissionManagerFv());
    switch (mode) {
    case 3:
    case 0:
        f23 = lbl_80560F3C; f31 = lbl_80560F3C; f30 = lbl_80560F3C; f27 = lbl_80560F3C;
        break;
    default: break;
    }
    float f24 = lbl_80560F38;
    if (*(int *)(self + 0x13c) & 1) f24 *= *(float *)(self + 0x140);
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
        float a = *(float *)(r6 + 0x9c) + (f24b + (*(float *)(self + 0x128) + *(float *)(self + 0x130)));
        float b = *(float *)(r6 + 0xa0) + (*(float *)(self + 0x12c) + *(float *)(self + 0x134));
        ((nw4r::snd::detail::Voice *)self)->TransformDpl2Pan(&spC, &sp8, a, b);
        break;
    }
    case 3: {
        float pan = lbl_80560F3C;
        spC = pan;
        sp8 = pan;
        break;
    }
    case 0:
    case 1:
    default: {
        char *r6 = self + arg2 * 0x1c;
        spC = *(float *)(r6 + 0x9c) + (f24b + (*(float *)(self + 0x128) + *(float *)(self + 0x130)));
        sp8 = *(float *)(r6 + 0xa0) + (*(float *)(self + 0x12c) + *(float *)(self + 0x134));
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
    if (tmp > v24) {
        // Keep the maximum.
    } else {
        v24 = lbl_80560F3C;
        if (!(tmp < v24)) v24 = tmp;
    }
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
    float scale = lbl_80560F80;
    unsigned int saturated;
    unsigned int value;
    saturated = (unsigned int)(scale * f22) < 0xffffU ? (unsigned int)(lbl_80560F80 * f22) : 0xffffU;
    scale = lbl_80560F80;
    out[0] = saturated;
    saturated = (unsigned int)(scale * f21) < 0xffffU ? (unsigned int)(lbl_80560F80 * f21) : 0xffffU;
    scale = lbl_80560F80;
    out[2] = saturated;
    value = (unsigned int)(scale * (float)f23);
    saturated = value < 0xffffU ? value : 0xffffU;
    scale = lbl_80560F80;
    out[16] = saturated;
    saturated = (unsigned int)(scale * f20) < 0xffffU ? (unsigned int)(lbl_80560F80 * f20) : 0xffffU;
    scale = lbl_80560F80;
    out[4] = saturated;
    saturated = (unsigned int)(scale * f19) < 0xffffU ? (unsigned int)(lbl_80560F80 * f19) : 0xffffU;
    scale = lbl_80560F80;
    out[6] = saturated;
    value = (unsigned int)(scale * (float)f31);
    saturated = value < 0xffffU ? value : 0xffffU;
    scale = lbl_80560F80;
    out[18] = saturated;
    saturated = (unsigned int)(scale * f18) < 0xffffU ? (unsigned int)(lbl_80560F80 * f18) : 0xffffU;
    scale = lbl_80560F80;
    out[8] = saturated;
    saturated = (unsigned int)(scale * f17) < 0xffffU ? (unsigned int)(lbl_80560F80 * f17) : 0xffffU;
    scale = lbl_80560F80;
    out[10] = saturated;
    value = (unsigned int)(scale * (float)f30);
    saturated = value < 0xffffU ? value : 0xffffU;
    scale = lbl_80560F80;
    out[20] = saturated;
    value = (unsigned int)(scale * (float)f29);
    saturated = value < 0xffffU ? value : 0xffffU;
    scale = lbl_80560F80;
    out[12] = saturated;
    value = (unsigned int)(scale * (float)f28);
    saturated = value < 0xffffU ? value : 0xffffU;
    scale = lbl_80560F80;
    out[14] = saturated;
    value = (unsigned int)(scale * (float)f27);
    saturated = value < 0xffffU ? value : 0xffffU;
    out[22] = saturated;
    out[1] = 0; out[3] = 0; out[0x11] = 0; out[5] = 0; out[7] = 0; out[0x13] = 0;
    out[9] = 0; out[0x0b] = 0; out[0x15] = 0; out[0x0d] = 0; out[0x0f] = 0; out[0x17] = 0;
}

extern float lbl_80560F3C, lbl_80560F80;
extern float lbl_80560F38, lbl_80560F3C, lbl_80560F80;
#pragma push
#pragma processor 750
extern "C" void CalcAXPBRMTMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP11_AXPBRMTMIX(void* self, int a, int b, void* out) {
    char* voice=(char*)self;
    float mainVol[4], auxVol[4];
    float f = 1.0f;
    /* Mix the voice's main and aux levels into the output sample buffer. */
    for (int i=0;i<4;i++) {
        mainVol[i]=f;
        auxVol[i]=f;
        float volume;
        if (*(volatile u32*)((char*)self+0x13c) & (2<<i))
            volume=f * *(float*)(voice+0x154);
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
    unsigned short* mix=(unsigned short*)out;
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
#pragma pop
/* If any loaded wave in this AxVoice overlaps [start, end], stops its active
 * AX voices and notifies the invalidation callback. */
extern "C" void InvalidateWaveData__Q46nw4hbm3snd6detail7AxVoiceFPCvPCv(void *self, const void *start, const void *end) {
    unsigned int irq;
    int remaining;
    char *voiceIter;
    int foundOverlap;
    void *waveAddress;
    unsigned int lockLevel;
    unsigned int innerLevel;
    void *voiceManager;
    int outer;
    int innerIndex;
    int isActive;
    unsigned char *row;
    unsigned char *slot;
    void *axVoice;
    void (*callback)(void *, int, void *);

    irq = OSDisableInterrupts();
    if (*((u8 *)self + 0x11C) != 0) {
        remaining = *(int *)((char *)self + 0x104);
        voiceIter = (char *)self;
        foundOverlap = 0;
        while (remaining > 0) {
            waveAddress = *(void **)(voiceIter + 0x2C);
            if (start <= waveAddress && waveAddress <= end) {
                foundOverlap = 1;
            }
            voiceIter += 0x34;
            remaining--;
        }
        if (foundOverlap != 0) {
            lockLevel = OSDisableInterrupts();
            if (*((u8 *)self + 0x11E) != 0) {
                innerLevel = OSDisableInterrupts();
                voiceManager = *(void **)((char *)self + 0xC);
                if (voiceManager == 0) {
                    OSRestoreInterrupts(innerLevel);
                    isActive = 0;
                } else {
                    isActive = (*(unsigned short *)((char *)voiceManager + 0x148) == 1);
                    OSRestoreInterrupts(innerLevel);
                }
                if (isActive != 0) {
                    row = (unsigned char *)self;
                    outer = 0;
                    while (outer < *(int *)((char *)self + 0x104)) {
                        slot = row;
                        innerIndex = 0;
                        while (innerIndex < *(int *)((char *)self + 0x108)) {
                            axVoice = *(void **)(slot + 0xC);
                            if (axVoice != 0) AXSetVoiceState(axVoice, 0);
                            slot += 4;
                            innerIndex++;
                        }
                        row += 0x10;
                        outer++;
                    }
                }
                *((u8 *)self + 0x11E) = 0;
            }
            *((u8 *)self + 0x120) = 0;
            *((u8 *)self + 0x11F) = 0;
            *((u8 *)self + 0x11D) = 0;
            OSRestoreInterrupts(lockLevel);
            callback = *(void (**)(void *, int, void *))((char *)self + 0x10C);
            if (callback != 0) callback(self, 1, *(void **)((char *)self + 0x110));
        }
    }
    OSRestoreInterrupts(irq);
}

/* Intentional no-op: an external-C entry point with an empty body (just returns). */
extern "C" void fn_800E80B4(void) {

}

extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *self, const void *bank);
extern "C" void *fn_800E80B8(void *reader, const void *bank) {
    /* Construct a scratch BankFileReader over the bank file and clear its wave-file address field at +0xC. */
    __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(reader, bank);
    *(int *)((char *)reader + 0xC) = 0;
    return reader;
}

extern "C" int fn_800E80F0(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

void *nw4hbm::snd::detail::Bank::NoteOn(const nw4hbm::snd::detail::NoteOnInfo &noteInfo) const {
    /* Play one note: look up its instrument and wave data, allocate a channel,
       then program its volume, envelope, and pan before starting playback. */
    unsigned char wave[0x98];
    unsigned char inst[0x10];
    void *bank = (void *)this;
    register void *channel;
    if (!ReadInstInfo__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8InstInfoiii(bank, inst,
        noteInfo.unk_0, noteInfo.unk_4, noteInfo.unk_8)) return 0;
    if (!ReadWaveParam__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8WaveDataiPCv(bank, wave,
        *(int *)inst, *(void **)((char *)bank + 0xC))) return 0;
    int voices = 2;
    int waveVoices = wave[2];
    if (waveVoices <= 2) voices = waveVoices;
    channel = AllocChannel__Q46nw4hbm3snd6detail7ChannelFiiiPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(
        voices, noteInfo.unk_18, noteInfo.unk_14, noteInfo.unk_1C, noteInfo.unk_20);
    if (!channel) return 0;
    *(int *)((char *)channel + 0xCC) = noteInfo.unk_4;
    *(int *)((char *)channel + 0xD0) = inst[8];
    float volume = (float)noteInfo.unk_8 / 127.0f;
    volume *= volume;
    volume *= (float)inst[0xA] / 127.0f;
    *(float *)((char *)channel + 0xB4) = volume;
    *(float *)((char *)channel + 0xC0) = *(float *)(inst + 0xC);
    SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, inst[4]);
    SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, inst[5]);
    SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, inst[6]);
    SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, inst[7]);
    float pan = (float)((int)inst[9] - 0x40) / 63.0f;
    pan += (float)noteInfo.unk_10 / 63.0f;
    *(float *)((char *)channel + 0xB8) = pan;
    *(float *)((char *)channel + 0xBC) = 0.0f;
    Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(channel, wave, noteInfo.unk_C);
    return channel;
}

extern const char lbl_803224F0[];
#pragma opt_peephole on
extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *arg0, const void *arg1) {
    register void *self = arg0;
    register const unsigned char *file = (const unsigned char *)arg1;
    const char *strings = lbl_803224F0;
    register unsigned short temp_r0;
    register unsigned int var_r0;
    *(unsigned int *)self = 0;
    *(unsigned int *)((char *)self + 4) = 0;
    *(unsigned int *)((char *)self + 8) = 0;
    if (file == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(strings + 0, 0x58, strings + 0xB8);
    if (*(const unsigned int *)file != 0x52424E4B)
        Panic__Q26nw4hbm2dbFPCciPCce(strings + 0, 0x36, strings + 0x14);
    if (*(const unsigned int *)file != 0x52424E4B) {
        var_r0 = 0;
    } else {
        if (*(const unsigned short *)(file + 6) < 0x100)
            Panic__Q26nw4hbm2dbFPCciPCce(strings + 0, 0x3E, strings + 0x60);
        temp_r0 = *(const unsigned short *)(file + 6);
        if (temp_r0 < 0x100) {
            var_r0 = 0;
        } else {
            if (temp_r0 > 0x101)
                Panic__Q26nw4hbm2dbFPCciPCce(strings + 0, 0x44, strings + 0x60);
            var_r0 = (*(const unsigned short *)(file + 6) <= 0x101);
        }
    }
    if ((int)var_r0 == 0)
        return self;
    *(const void **)self = (const void *)file;
    *(void **)((char *)self + 4) = (void *)(*(const unsigned int *)(file + 0x10) + (unsigned int)file);
    if (**(const unsigned int **)((char *)self + 4) != 0x44415441)
        Panic__Q26nw4hbm2dbFPCciPCce(strings + 0, 0x61, strings + 0xE4);
    {
        register const unsigned char *stored = (const unsigned char *)*(volatile void **)self;
        *(void **)((char *)self + 8) = (void *)(*(const unsigned int *)(stored + 0x18) + (unsigned int)stored);
    }
    if (**(const unsigned int **)((char *)self + 8) != 0x57415645)
        Panic__Q26nw4hbm2dbFPCciPCce(strings + 0, 0x65, strings + 0x13C);
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
    char *base = (char *)lbl_803224F0;
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
#pragma opt_peephole reset
extern "C" void *fn_800E8690(void *arg0, void *arg1, int arg2) {
    unsigned int type = *(unsigned char *)((char *)arg1 + 1);
    unsigned char *data;
    unsigned int base, address;
    int i;
    switch (type) {
    case 0:
        return 0;
    case 1:
        return arg1;
    case 2:
        base = *(unsigned int *)((char *)arg0 + 4) + 8;
        if (type != 2) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559820, 0x71, lbl_80322708);
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
            return (void *)((unsigned int)(data + i * 8) + off);
        }
        goto inc;
    case 3:
        base = *(unsigned int *)((char *)arg0 + 4) + 8;
        if (type != 3) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559828, 0x72, lbl_80322734);
        address = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*(unsigned char *)arg1, *(unsigned int *)((char *)arg1 + 4), (const void *)base);
        data = (unsigned char *)address;
        if (!data) return 0;
        if (arg2 < data[0] || arg2 > data[1]) return 0;
        return data + (arg2 - data[0]) * 8 + 4;
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

extern "C" void InitParam__Q44nw4r3snd6detail10BasicSoundFv(void *sound) {
    // Initialize BasicSound runtime parameters and fade/volume state to defaults.
    register int zero = 0;
    float base = 0.0f;
    float initialTarget = 1.0f;
    *((unsigned char *)sound + 0x67) = zero;
    *((unsigned char *)sound + 0x68) = zero;
    *((unsigned char *)sound + 0x64) = zero;
    *((unsigned char *)sound + 0x65) = zero;
    *((unsigned char *)sound + 0x66) = zero;
    *((unsigned char *)sound + 0x69) = zero;
    *(int *)((char *)sound + 0x6c) = zero;
    *(int *)((char *)sound + 0x70) = zero;
    *(float *)((char *)sound + 0x44) = base;
    *(float *)((char *)sound + 0x48) = base;
    *(int *)((char *)sound + 0x4c) = zero;
    *(int *)((char *)sound + 0x50) = zero;
    *(float *)((char *)sound + 0x54) = initialTarget;
    *(float *)((char *)sound + 0x58) = initialTarget;
    *(int *)((char *)sound + 0x5c) = zero;
    *(int *)((char *)sound + 0x60) = zero;
    int current = *(int *)((char *)sound + 0x50);
    int total = *(int *)((char *)sound + 0x4c);
    if (current >= total) {
        base = *(float *)((char *)sound + 0x44);
    } else {
        base += (float)current * (*(float *)((char *)sound + 0x48) - *(float *)((char *)sound + 0x44)) / (float)total;
    }
    float baseAgain;
    float finalTarget;
    int one;
    finalTarget = 1.0f;
    zero = 0;
    baseAgain = 0.0f;
    one = 1;
    *(float *)((char *)sound + 0x44) = base;
    *(float *)((char *)sound + 0x48) = finalTarget;
    *(int *)((char *)sound + 0x4c) = one;
    *(int *)((char *)sound + 0x50) = zero;
    *(float *)((char *)sound + 0x8c) = finalTarget;
    *(float *)((char *)sound + 0x98) = finalTarget;
    *(float *)((char *)sound + 0x90) = baseAgain;
    *(float *)((char *)sound + 0x94) = baseAgain;
    *(float *)((char *)sound + 0x7c) = finalTarget;
    *(float *)((char *)sound + 0x80) = finalTarget;
    *(int *)((char *)sound + 0x84) = zero;
    *(int *)((char *)sound + 0x88) = zero;
    *(int *)((char *)sound + 0xa0) = one;
    *((unsigned char *)sound + 0x9c) = zero;
    *(float *)((char *)sound + 0xa4) = finalTarget;
    *(float *)((char *)sound + 0xa8) = finalTarget;
    *(float *)((char *)sound + 0xac) = finalTarget;
    *(float *)((char *)sound + 0xb0) = finalTarget;
    *(float *)((char *)sound + 0xb4) = finalTarget;
    *(float *)((char *)sound + 0x28) = finalTarget;
    *(float *)((char *)sound + 0x2c) = finalTarget;
    *(float *)((char *)sound + 0x30) = baseAgain;
    *(float *)((char *)sound + 0x34) = baseAgain;
    *(float *)((char *)sound + 0x38) = baseAgain;
    *(float *)((char *)sound + 0x3c) = baseAgain;
    *(int *)((char *)sound + 0x40) = zero;
}

extern "C" void fn_800E8ADC(void *sound) {
    /* Request a start (startRequested, +0x64) for this BasicSound if it is not
       running yet (started, +0x65). */
    if (*(unsigned char *)((char *)sound + 0x65) == 0)
        *(unsigned char *)((char *)sound + 0x64) = 1;
}

extern "C" void Stop__Q44nw4r3snd6detail10BasicSoundFi(void *self, int target) {
    struct SoundObj {
        virtual ~SoundObj();
        virtual void x1(); virtual void x2(); virtual void x3();
        virtual void a(); virtual void b(); virtual void c(); virtual void d();
        virtual void stop();
        virtual void f(); virtual void g(); virtual void h(); virtual void i();
        virtual void j(); virtual void k(); virtual void l(); virtual void m();
        virtual void clear(int); virtual void o(); virtual void p(); virtual void q();
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
        virtual void m28(); virtual void m29();
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
    register Fields *fields = (Fields *)self;
    if (target == 0 || ((VoiceObj *)voice)->valid() == 0 ||
        ((VoiceObj *)voice)->isPlaying() == 0 || ((VoiceObj *)voice)->isReady() != 0) {
        sound->stop();
        return;
    }
    int elapsed, total;
    total = fields->total;
    elapsed = fields->elapsed;
    float current;
    if (elapsed >= total) current = fields->end;
    else current = fields->start + (float)elapsed * (fields->end - fields->start) / (float)total;
    int newTotal = (int)((float)target * current);
    if (elapsed >= total) current = fields->end;
    else current = fields->start + (float)elapsed * (fields->end - fields->start) / (float)total;
    fields->end = lbl_80560FB0;
    fields->start = current;
    fields->total = newTotal;
    fields->elapsed = 0;
    sound->clear(0);
    fields->flags[0] = 0; fields->flags[1] = 0;
    fields->flags[2] = 0; fields->flags[3] = 1;
}

#pragma dont_inline off
/* nw4hbm::snd::detail::BasicSound::Pause — fades the sound's volume to zero
   (pause) or back to full (resume) over a ramp proportional to the current
   fade position, so the total fade time is always roughly `frames` frames. */
extern "C" void Pause__Q46nw4hbm3snd6detail10BasicSoundFbi(void *self, bool pause, int frames) {
    PauseFields *s = (PauseFields *)self;
    PauseVt *player = ((PauseVt *)self)->vf22();
    if (pause) {
        int n = (int)((float)frames * PauseRamp(s));
        s->fading = 1;
        if (n <= 0) n = 1;
        PauseSetRamp(s, 0.0f, n);
    } else {
        int n;
        if ((s->paused != 0) != pause) {
            player->vf4(0);
        }
        n = (int)((float)frames * (1.0f - PauseRamp(s)));
        s->fading = 1;
        if (n <= 0) n = 1;
        PauseSetRamp(s, 1.0f, n);
    }
    s->paused = pause;
}
#pragma dont_inline on

extern "C" void fn_800E8F54(void *self, int value) {
    /* Store value at +0x6C and set the flag byte at +0x66 to 1 exactly when value > 0
       (the (-v & ~v) >> 31 sign trick). */
    *(int *)((char *)self + 0x6C) = value;
    *(unsigned char *)((char *)self + 0x66) = (unsigned int)((-value) & ~value) >> 31;
}

extern "C" float lbl_80560FB4;
extern double lbl_80560FB8;
extern "C" void FadeIn__Q44nw4r3snd6detail10BasicSoundFi(void* self, int frames) {
    // Restart the volume ramp toward full volume (1.0), unless a fade-to-stop is pending.
    struct BasicSoundFields {
        unsigned char pad0[0x44];
        float fadeStart;
        float fadeEnd;
        int fadeFrames;
        int fadeFrame;
        unsigned char pad1[0x15];
        unsigned char stopWhenFaded;
    };
    BasicSoundFields* sound = (BasicSoundFields*)self;
    if (0 == sound->stopWhenFaded) {
        int elapsed;
        int length;
        length = sound->fadeFrames;
        elapsed = sound->fadeFrame;
        float volume;
        if (elapsed >= length)
            volume = sound->fadeEnd;
        else
            volume = sound->fadeStart + (float)elapsed * (sound->fadeEnd - sound->fadeStart) / (float)length;
        int newFrames = (int)((float)frames * (lbl_80560FB4 - volume));
        float fullVolume;
        float currentVolume;
        if (elapsed >= length)
            currentVolume = sound->fadeEnd;
        else
            currentVolume = sound->fadeStart + (float)elapsed * (sound->fadeEnd - sound->fadeStart) / (float)length;
        fullVolume = lbl_80560FB4;
        sound->fadeStart = currentVolume;
        sound->fadeEnd = fullVolume;
        sound->fadeFrames = newFrames;
        sound->fadeFrame = 0;
    }
}

typedef void (*vfn0_t)(void*);
extern "C" int fn_800E9070(BasicSoundVt *sound) {
    /* BasicSound's vtable slot 0x2C: ask the player this sound plays through
     * whether its data is loaded, so the sound is ready to start. */
    SoundPlayerVt *player = sound->GetSoundPlayer();
    return player->IsPrepared();
}

extern "C" int fn_800E90AC(PauseFields *sound) {
    return sound->paused != 0;
}

#pragma dont_inline off
extern "C" void Update__Q46nw4hbm3snd6detail10BasicSoundFv(void *self) {
    struct UpdSound {
        char pad[0xA8];
        float aux[4];
    };
    UpdSelfVt *sv = (UpdSelfVt *)self;
    UpdPlayerVt *p = sv->s5C();
    int f30flag;
    float sends[4];
    float f31, f30, f29, f28, f27, f26, f25, f24;
    int voice, i, valid;
    char *pl;
    char *pl2;
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
    f31 = 1.0f;
    f31 *= UF(float, 0x8C);
    pl = UF(char *, 0x10);
    pl2 = UF(char *, 0x14);
    f31 *= *(float *)(pl + 0x28);
    if (pl2 != 0) f31 *= *(float *)(pl2 + 0x10);
    f31 *= UpdRamp((UpdRampFields *)((char *)self + 0x7C));
    f31 *= UpdRamp((UpdRampFields *)((char *)self + 0x44));
    f31 *= UpdRamp((UpdRampFields *)((char *)self + 0x54));
    f31 *= UF(float, 0x28);
    f28 = 0.0f;
    voice = 1;
    f27 = f28;
    f30 = 1.0f * *(float *)(pl + 0x34);
    f30 *= UF(float, 0xA4);
    f26 = f27;
    f25 = f26;
    f24 = 1.0f;
    f28 += UF(float, 0x90);
    f26 += UF(float, 0x30);
    f27 += UF(float, 0x94);
    f25 += UF(float, 0x34);
    f24 *= UF(float, 0x98);
    if (fn_800F87F0() != 0) voice = fn_800F87E8(UF(void *, 0x10));
    if (UF(unsigned char, 0x9C) != 0) voice = UF(int, 0xA0);
    f29 = 1.0f;
    for (i = 0; i < 4; i++) {
        sends[i] = f29;
        sends[i] *= GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800F87F8(UF(void *, 0x10), i);
        valid = 0;
        if (i >= 0 && i < 4) valid = 1;
        if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x377, lbl_803227A4, i, 0, 4);
        sends[i] = ((UpdSound *)self)->aux[i] * sends[i];
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

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf(void *sound, float volume) {
    /* Sets the initial volume at +0x8C, asserting that volume is non-negative. */
    if (!(volume >= 0.0f)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x216, lbl_80322830);
    }
    *(float *)((char *)sound + 0x8C) = volume;
}

#pragma scheduling on
/* Set the target volume, preserving the current interpolated volume as the fade starting point. */
extern "C" void SetVolume__Q46nw4hbm3snd6detail10BasicSoundFfi(void *this_, float volume, int fadeFrames) {
    struct SoundFields {
        char pad[0x7C];
        float currentVolume;
        float targetVolume;
        int fadeDuration;
        int fadeTime;
    };
    float currentVolume;

    if (!(volume >= 0.0f)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x225, lbl_80322830);
    }
    SoundFields *sound = (SoundFields *)this_;
    s32 fadeDuration = sound->fadeDuration;
    s32 fadeTime = sound->fadeTime;
    if (fadeTime >= fadeDuration) {
        currentVolume = sound->targetVolume;
    } else {
        currentVolume = sound->currentVolume +
                        ((float)fadeTime * (sound->targetVolume - sound->currentVolume)) /
                            (float)fadeDuration;
    }
    sound->currentVolume = currentVolume;
    sound->targetVolume = volume;
    sound->fadeDuration = fadeFrames;
    sound->fadeTime = 0;
}
extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800E9AAC(void *sound, float volume) {
    /* Sets the initial volume at +0x98, asserting that volume is non-negative. */
    if (!(volume >= 0.0f)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x234, lbl_80322858);
    }
    *(float *)((char *)sound + 0x98) = volume;
}

#pragma push
#pragma small_data off
extern float lbl_80560FB0;
#pragma pop
extern "C" void fn_800E9B18(void *sound, float value) {
    /* Set the BasicSound's float parameter at +0x90: the first of the
       +0x90/+0x94 pair (fn_800E9B20 sets +0x94). The per-frame update reads
       it and forwards it to the voice through its p30 setter. */
    *(float *)((char *)sound + 0x90) = value;
}

extern "C" void fn_800E9B20(void *sound, float value) {
    /* Set the BasicSound's float parameter at +0x94: the second of the
       +0x90/+0x94 pair (fn_800E9B18 sets +0x90). The per-frame update reads
       it and forwards it to the voice through its p34 setter. */
    *(float *)((char *)sound + 0x94) = value;
}

extern "C" void fn_800E9B28(void *arg0, float arg1) {
    /* Get an owned object from the source and forward the float value to it. */
    VfObjF *owner = (VfObjF *)arg0;
    VfObjF *target = owner->vf22();
    target->vf15(arg1);
}

extern "C" void fn_800E9B74(void *sound, int argInfo, int argValue, int argCallback, int argSize) {
    /* Copy the four words of a sound's ambient argument (info, value, callback, byte size) into the BasicSound at +0x18. */
    *(int *)((char *)sound + 0x18) = argInfo;
    *(int *)((char *)sound + 0x1C) = argValue;
    *(int *)((char *)sound + 0x20) = argCallback;
    *(int *)((char *)sound + 0x24) = argSize;
}

/* Return nonzero if a general SoundHandle is attached to this BasicSound (its +0x08 mGeneralHandle). */
extern "C" int fn_800E9B88(void *sound) {
    return *(int *)((char *)sound + 8) != 0;
}

extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void *);
/* Detach the general SoundHandle (mGeneralHandle, +0x08) from this BasicSound. */
extern "C" void fn_800E9B9C(void *sound) {
    DetachSound__Q34nw4r3snd11SoundHandleFv(*(void **)((char *)sound + 8));
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" void fn_800E9BA4(void *sound, int soundId) {
    /* Store the archive sound id on the sound and on the player that plays it. */
    ((nw4hbm::snd::detail::BasicSound *)sound)->soundId = soundId;
    sound = ((BasicSoundVt *)sound)->GetPlayer();
    ((SoundPlayerVt *)sound)->soundId = soundId;
}
extern int lbl_8055DE20;
/* The nw4r sound library's shared dummy value, used as a default target by
   several sound-library pointers. */
#define s_sndDummy lbl_8055DE20
extern void fn_80128668(void);
extern "C" int fn_800E9BE4(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Return the address of the nw4r sound library's shared dummy value. */
extern "C" int *fn_800E9C24(void) {
    return &s_sndDummy;
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
