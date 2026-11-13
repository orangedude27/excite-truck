#include <types.h>
extern "C" void OSSetPeriodicAlarm(void*, u32, u32, u32, u32, u32, void*);
extern "C" void fn_800EEBA8(void*, u64, u64);
extern "C" void Close__Q46nw4hbm3snd6detail8SeqTrackFv(void *);
extern "C" void* __dt__Q46nw4hbm3snd6detail9FrameHeapFv(void*, s32);
extern u8 lbl_80323058[], lbl_80323070[];
extern "C" bool ParseNextTick__Q46nw4hbm3snd6detail9SeqPlayerFb(void *, bool);
extern "C" void InitParam__Q46nw4hbm3snd6detail9SeqPlayerFiPQ46nw4hbm3snd6detail14NoteOnCallback(void *, s32, void *);
extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi_800F0E9C(void *, s32);
extern "C" void UpdateChannelParam__Q46nw4hbm3snd6detail8SeqTrackFv(void *);
extern "C" void MEMFreeToFrmHeap(void *, u32);
extern "C" void MEMDestroyFrmHeap(void *);
extern "C" void *MEMAllocFromFrmHeapEx(void *, u32, s32);
extern "C" void *MEMCreateFrmHeapEx(void *, u32, u16);
#pragma push
#pragma small_data off
extern u8 lbl_80322D74[];
extern u8 lbl_80322D60[];
#pragma pop
extern u8 lbl_80322F38[], lbl_80322F5C[], lbl_80322F68[], lbl_80322F8C[];
extern u8 lbl_80322F98[], lbl_80322FBC[], lbl_80322FC8[], lbl_80322FEC[];
extern u8 lbl_80322FF8[], lbl_8032301C[];
extern "C" void DVDClose(void *);
extern "C" void fn_800F27AC(void *);
namespace nw4hbm { namespace snd { namespace detail {
class FrameHeap {
public:
    bool Create(void *, unsigned long);
    void *Alloc(unsigned long, void (*)(void *, unsigned long, void *), void *);
    void Destroy();
};
class EnvGenerator { public: void SetRelease(int); void SetDecay(int); void SetSustain(int); };
class PoolImpl { public: void DestroyImpl(void *, unsigned long); };
class RemoteSpeakerManager { public: void Setup(); };
   }}}
struct FrameHeapDestroyListView {
    u32 unknown;
    void *tail;
};
struct FrameHeapDestroyView {
    void *heap;
    u32 count;
    FrameHeapDestroyListView list;
};
namespace nw4r { namespace snd { namespace detail {
class PoolImpl { public: void *AllocImpl(); };
}}}
extern f32 lbl_80560FE8, lbl_80561008, lbl_8056100C, lbl_80561010, lbl_80561014;
#pragma push
#pragma small_data off
extern f64 lbl_80561000;
#pragma pop
extern u8 lbl_80322B80[], lbl_80322C50[], lbl_80322C90[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" s32 fn_800F1080(void*, const void*, s32);
#pragma push
#pragma small_data off
extern u8 lbl_80322D24[];
extern u8 lbl_80322D00[];
#pragma pop

#pragma push
#pragma small_data off
extern f32 lbl_80561018;
extern f32 lbl_8056101C;
extern f32 lbl_80561020;
extern f64 lbl_80561028;
#pragma pop

extern f32 lbl_8056106C;
extern u8 lbl_80323268[];
extern u8 lbl_80323B28[];
extern u8 lbl_80323B94[];
extern "C" u32 fn_800FEB9C(void);
extern u8 lbl_80323BEC[];
extern u8 lbl_80323C14[];
extern u8 lbl_80323C3C[];
extern u8 lbl_80324054[];
extern u8 lbl_80324030[];
#pragma push
#pragma small_data off
extern u8 lbl_80412A6C[];
#pragma pop

extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFb(void*, bool);
extern "C" void* Instance__15EmissionManagerFv(void);

#pragma push
#pragma small_data off
extern u8 lbl_80323840[];
extern u8 lbl_803238C0[];
#pragma pop
extern "C" u64 OSGetTime(void);
extern "C" void OSCancelAlarm(void *);
extern "C" void* OSGetAlarmUserData(void*);
extern "C" void* fn_800EE4F0(void*);
extern u8 lbl_804127A8[];
extern u8 lbl_8055DE40;
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void* OSGetAlarmUserData(void*);
extern "C" void* fn_800EE4F0(void*);
extern u8 lbl_804127A8[];
extern u8 lbl_8055DE40;
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);

namespace nw4hbm { namespace snd {
class MemorySoundArchive {
public:
    s32 detail_GetFileAddress(u32) const;
};
namespace detail {
class SeqFileReader {
public:
    void *GetBaseAddress() const;
};
class SeqPlayer {
public:
    void SetVolume(float);
};
class SeqTrack {
public:
    s16 field_0x94;
};
class SeqTrack2;
class MmlSeqTrack {
public:
    u8 pad0[0x54];
    const u8 *cur;
    s32 field_0x58;
    u8 field_0x5c;
    u8 pad5d;
    u8 field_0x5e;
    u8 pad5f[0x87 - 0x5f];
    s8 transpose;
    u8 pad88[0xb4 - 0x88];
    SeqPlayer *player;
    u8 padb8[0xc0 - 0xb8];
    u8 field_0xc0;
    u8 field_0xc1;
    u8 field_0xc2;
};
class MmlParser {
public:
    enum SeqArgType { ARG_BYTE = 0, ARG_WORD = 1, ARG_VLQ = 2, ARG_EXPR = 3, ARG_VAR = 4 };
    virtual void CommandProc(MmlSeqTrack *, u32, s32, s32) const;
    virtual void NoteOnCommandProc(MmlSeqTrack *, int, int, s32, u8) const;
    s32 ReadArg(const u8 **, SeqPlayer *, SeqTrack *, SeqArgType) const;
    int Parse(MmlSeqTrack *, bool) const;
};
}}}

extern u8 lbl_80323E98[];
extern u8 lbl_803239C0[];
extern u8 lbl_80323AF8[];

extern u8 lbl_803231D8[];
extern "C" s32 fn_800F283C(void *, u32, s32, s32 *);
extern "C" s32 fn_800F2824(void *, s32, void *);
extern "C" s32 fn_800F282C(void *, s32, s32, void *);
extern "C" void *memcpy(void *, const void *, u32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Forward declarations for DisposeCallbackManager cluster */
extern "C" void fn_8002F634(void* a, void* b, s32 c, s32 d);
extern "C" void* __dt__Q46nw4hbm3snd6detail7ChannelFv(void*, s32);
extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32 level);
extern "C" void __register_global_object(void* p, void* dtor, void* allocator);
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54(
    void* this_, s32 flag);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, u32);
extern "C" s32 fn_80128668(void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char* file, int line,
                                              const char* fmt, ...);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
    void*, void*, void*);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);

#pragma push
#pragma small_data off
extern u8 lbl_8040EC90[];
extern u8 lbl_80412790[];
extern u8 lbl_8041279C[];
extern u8 lbl_80322B74[];
extern u8 lbl_80322B50[];
#pragma pop

extern u8 lbl_8055DE30;
extern u32 lbl_8055DEA0;

extern s32 fn_80128668(void);
#define fn_80128668_noarg() ((s32 (*)(void))fn_80128668)()

extern "C" void fn_800EAEB0(void) {
    fn_8002F634(&lbl_8040EC90, &__dt__Q46nw4hbm3snd6detail7ChannelFv, 0xE8, 0x41);
}

extern "C" void* GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void) {
    u32 level;
    void* ptr;
    s8 tmp;
    
    level = OSDisableInterrupts();
    tmp = (s8)lbl_8055DE30;
    if (tmp != 0) {
        goto skip_init;
    }
    
    ptr = &lbl_8041279C[4];
    *(u32*)&lbl_8041279C[4] = 0;
    *(u32*)&lbl_8041279C[8] = 0;
    *(u32*)&lbl_8041279C[0] = 0;
    *(void**)&lbl_8041279C[4] = ptr;
    *(void**)&lbl_8041279C[8] = ptr;
    __register_global_object(&lbl_8041279C, (void*)&__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54, &lbl_80412790);
    lbl_8055DE30 = 1;
    
skip_init:
    OSRestoreInterrupts(level);
    return &lbl_8041279C;
}

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

extern "C" void RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
    void* this_, void* pCallback) {
    /* Register a dispose callback in the manager's callback list (interrupt-safe). */
    u32 savedInterruptState;
    void* callbackListNode;
    void* iterator;

    savedInterruptState = OSDisableInterrupts();
    callbackListNode = (void*)((u8*)this_ + 4);

    if (pCallback == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B74, 0x233,
                                     (const char*)lbl_80322B50);
    }

    iterator = callbackListNode;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
        this_, &iterator, pCallback);

    OSRestoreInterrupts(savedInterruptState);
}

extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
    void* this_, void* pCallback) {
    u32 level;
    void* pThis;
    void* pCb;

    pThis = this_;
    pCb = pCallback;
    level = OSDisableInterrupts();

    if (pCb == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B74, 0x233,
                                     (const char*)lbl_80322B50);
    }

    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(pThis, pCb);

    OSRestoreInterrupts(level);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(void* object, u32 size, void* user) {
    extern u8 lbl_80322B44[];
    extern u8 lbl_80322B20[];
    struct ListNode { void* next; void* previous; };
    struct Callback : ListNode {
        virtual void unused();
        virtual void dispose(void*, void*);
    };
    void* start = object;
    void* end = (u8*)start + size;
    unsigned long outerLevel = OSDisableInterrupts();
    unsigned long level = OSDisableInterrupts();
    if ((s8)lbl_8055DE30 == 0) {
        void* sentinel = lbl_8041279C + 4;
        *(u32*)(lbl_8041279C + 4) = 0;
        *(u32*)(lbl_8041279C + 8) = 0;
        *(u32*)lbl_8041279C = 0;
        *(void**)(lbl_8041279C + 4) = sentinel;
        *(void**)(lbl_8041279C + 8) = sentinel;
        __register_global_object(lbl_8041279C,
            (void*)__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54,
            lbl_80412790);
        lbl_8055DE30 = 1;
    }
    OSRestoreInterrupts(level);
    void* node = *(void**)(lbl_8041279C + 4);
    void* head = lbl_8041279C + 4;
    do {
        void* current = node;
        node = *(void**)node;
        if (!current)
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B44, 0x23D, (const char*)lbl_80322B20);
        ((Callback*)current)->dispose(start, end);
        level = OSDisableInterrupts();
        if ((s8)lbl_8055DE30 == 0) {
            void* sentinel = lbl_8041279C + 4;
            *(u32*)(lbl_8041279C + 4) = 0;
            void* value = lbl_8041279C;
            *(u32*)(lbl_8041279C + 8) = 0;
            *(u32*)lbl_8041279C = 0;
            *(void**)((short)lbl_8041279C + 4) = sentinel;
            *(void**)(lbl_8041279C + 8) = sentinel;
            __register_global_object(value,
                (void*)__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54,
                lbl_80412790);
            lbl_8055DE30 = 1;
        }
        OSRestoreInterrupts(level);
    } while (node != head);
    OSRestoreInterrupts(outerLevel);
}
#pragma pop
#pragma push
#pragma use_lmw_stmw off
extern "C" void DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(void* object, u32 size, void* user) {
    extern u8 lbl_80322B44[];
    extern u8 lbl_80322B20[];
    struct ListNode { void* next; void* previous; };
    struct Callback : ListNode {
        virtual void unused0();
        virtual void unused1();
        virtual void dispose(void*, void*);
    };
    void* start = object;
    void* end = (u8*)start + size;
    unsigned long outerLevel = OSDisableInterrupts();
    unsigned long level = OSDisableInterrupts();
    if ((s8)lbl_8055DE30 == 0) {
        void* sentinel = lbl_8041279C + 4;
        *(u32*)(lbl_8041279C + 4) = 0;
        *(u32*)(lbl_8041279C + 8) = 0;
        *(u32*)lbl_8041279C = 0;
        *(void**)(lbl_8041279C + 4) = sentinel;
        *(void**)(lbl_8041279C + 8) = sentinel;
        __register_global_object(lbl_8041279C,
            (void*)__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54,
            lbl_80412790);
        lbl_8055DE30 = 1;
    }
    OSRestoreInterrupts(level);
    void* node = *(void**)(lbl_8041279C + 4);
    void* head = lbl_8041279C + 4;
    do {
        void* current = node;
        node = *(void**)node;
        if (!current)
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B44, 0x23D, (const char*)lbl_80322B20);
        ((Callback*)current)->dispose(start, end);
        level = OSDisableInterrupts();
        if ((s8)lbl_8055DE30 == 0) {
            void* sentinel = lbl_8041279C + 4;
            *(u32*)(lbl_8041279C + 4) = 0;
            void* value = lbl_8041279C;
            *(u32*)(lbl_8041279C + 8) = 0;
            *(u32*)lbl_8041279C = 0;
            *(void**)((short)lbl_8041279C + 4) = sentinel;
            *(void**)(lbl_8041279C + 8) = sentinel;
            __register_global_object(value,
                (void*)__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_800EAF54,
                lbl_80412790);
            lbl_8055DE30 = 1;
        }
        OSRestoreInterrupts(level);
    } while (node != head);
    OSRestoreInterrupts(outerLevel);
}
#pragma pop

extern "C" void fn_800EB36C(void *arg0) {
    DVDClose((u8 *)arg0 + 0x14C);
    *(volatile u8 *)((u8 *)arg0 + 0x188) = 0;
    fn_800F27AC(arg0);
}

extern f32 lbl_80560FE8;
extern f32 lbl_80560FEC;
extern f32 lbl_80560FF0;
extern f32 lbl_80560FF4;
extern u8 lbl_802F4B90[];
extern "C" void DVDClose(void*);
extern "C" f32 CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(f32);
extern "C" void fn_800EB3AC(void* arg0) {
    volatile u8* p = (volatile u8*)arg0;
    f32 c;
    f32 b;
    f32 a;
    a = lbl_80560FE8;
    c = lbl_80560FEC;
    b = *(f32*)(lbl_802F4B90 + 0x1FC);
    *(volatile f32*)(p + 8) = a;
    *(volatile f32*)(p + 0x10) = b;
    p[0x14] = 0x7F;
    *(volatile f32*)(p + 0xC) = a;
    *(volatile f32*)(p + 4) = c;
    *(volatile s32*)p = 0;
}

extern "C" void fn_800EB3E4(void* arg0) {
    volatile u8* p = (volatile u8*)arg0;
    f32 c;
    f32 b;
    f32 a;
    a = lbl_80560FE8;
    c = lbl_80560FEC;
    b = *(f32*)(lbl_802F4B90 + 0x1FC);
    *(volatile f32*)(p + 8) = a;
    *(volatile f32*)(p + 0x10) = b;
    p[0x14] = 0x7F;
    *(volatile f32*)(p + 0xC) = a;
    *(volatile f32*)(p + 4) = c;
    *(volatile s32*)p = 0;
}

extern "C" void fn_800EB41C(void* arg0) {
    f32 value = lbl_80560FEC;
    *(s32*)arg0 = 0;
    *(f32*)((u8*)arg0 + 4) = value;
}

extern "C" f32 fn_800EB430(void* arg0) {
    if (*(s32*)arg0 == 0 && lbl_80560FF0 == *(f32*)((u8*)arg0 + 0x10))
        return CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(lbl_80560FF0);
    return CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(*(f32*)((u8*)arg0 + 4) / lbl_80560FF4);
}

extern const f32 lbl_80560FF8;
extern const s16 lbl_802F4A90[];
extern u8 lbl_80322B98[];
extern "C" void Update__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *arg0, s32 arg1) {
    s32 step=arg1, state=*(s32 *)arg0, valid, idx;
    f32 value, target, reset=lbl_80560FF0, threshold=lbl_80560FF8;
    switch(state) {
    case 0:
        if(step>0) {
            do {
                value=*(f32 *)((u8 *)arg0+4)*(*(f32 *)((u8 *)arg0+0x10));
                *(f32 *)((u8 *)arg0+4)=value;
                if(value>threshold) { *(f32 *)((u8 *)arg0+4)=reset; *(s32 *)arg0=1; }
            } while(--step != 0);
            step=arg1-1;
        }
        if(*(s32 *)arg0!=1) return;
    case 1:
        idx=(s32)*((u8 *)arg0+0x14); valid=0;
        if(idx>=0 && idx<=0x7f) valid=1;
        if(valid==0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322B80,0x141,(const char *)lbl_80322B98,idx,0,0x7f);
        value=*(f32 *)((u8 *)arg0+4)-(*(f32 *)((u8 *)arg0+8)*(f32)step);
        target=(f32)lbl_802F4A90[idx];
        *(f32 *)((u8 *)arg0+4)=value;
        if(!(value>target)) { *(f32 *)((u8 *)arg0+4)=target; *(s32 *)arg0=2; return; }
        break;
    case 2: return;
    case 3:
        value=*(f32 *)((u8 *)arg0+4)-(*(f32 *)((u8 *)arg0+0xc)*(f32)arg1);
        *(f32 *)((u8 *)arg0+4)=value; break;
    }
}

extern u8 lbl_80322BD4[];
/* Set the envelope generator's attack time index (0-127), panicking if out of range. */
extern "C" void SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *env, int attack) {
    int valid = 0;
    if (attack >= 0 && attack <= 0x7F) {
        valid = 1;
    }
    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322B80,
                                     0xF5,
                                     (const char *)lbl_80322BD4,
                                     attack, 0, 0x7F);
    }
    *(f32 *)((u8 *)env + 0x10) =
        *(f32 *)(lbl_802F4B90 + (attack << 2));
}

#pragma push
#pragma schedule off
void nw4hbm::snd::detail::EnvGenerator::SetDecay(int decay) {
    const char* file = (const char*)lbl_80322B80;
    s32 value = decay;
    void* self = this;
    s32 valid = 0;
    if (value >= 0 && value <= 0x7F) valid = 1;
    if (valid == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x105, file + 0x94, value, 0, 0x7F);

    valid = 0;
    if (value >= 0 && value <= 0x7F) valid = 1;
    if (valid == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x132, file + 0xD0, value, 0, 0x7F);

    f32 result;
    if (value == 0x7F) result = lbl_80560FE8;
    else if (value == 0x7E) result = lbl_80561008;
    else if (value < 0x32) result = (f32)(value * 2 + 1) * lbl_8056100C / lbl_80561010;
    else result = lbl_80561014 / (f32)(0x7E - value) / lbl_80561010;
    *(f32*)((u8*)self + 8) = result;
}

#pragma push
#pragma scheduling on
extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *self, int sustain) {
    int valid = 0;
    if (sustain >= 0 && sustain <= 0x7F) {
        valid = 1;
    }
    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322B80, 0x116, (const char *)lbl_80322C90, sustain, 0, 0x7F);
    }
    *((u8 *)self + 0x14) = (u8)sustain;
}
#pragma pop

#pragma pop
void nw4hbm::snd::detail::EnvGenerator::SetRelease(int release) {
    f32 value;
    int valid = 0;
    register f32 factor;
    if (release >= 0 && release <= 0x7F) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B80, 0x127, (const char*)lbl_80322C50, release, 0, 0x7F);
    valid = 0;
    if (release >= 0 && release <= 0x7F) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B80, 0x132, (const char*)lbl_80322C50, release, 0, 0x7F);
    if (release == 0x7F) value = lbl_80560FE8;
    else if (release == 0x7E) value = lbl_80561008;
    else if (release < 0x32) {
        factor = (f32)((release * 2) + 1);
        value = factor * lbl_8056100C;
        value = value / lbl_80561010;
    } else {
        value = lbl_80561014 / (0x7E - release) / lbl_80561010;
    }
    *(f32*)((u8*)this + 0xC) = value;
}

extern "C" void InsertSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *self, void *sound) {
    void *head = (u8 *)self + 4;
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322D24, 0x233,
                                     (const char *)lbl_80322D00);
    }
    void *iterator = head;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
        self, &iterator, (u8 *)sound + 0xD0);
    *(void **)((u8 *)sound + 0x14) = self;
}

#pragma push
#pragma small_data off
extern u8 lbl_80322D24[];
extern u8 lbl_80322D00[];
#pragma pop
extern "C" void RemoveSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(
    void* this_, void* pSound) {
    if (pSound == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322D24, 0x233,
                                     (const char*)lbl_80322D00);
    }

    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(
        this_, &((u8*)pSound)[0xD0]);

    ((s32*)pSound)[0x14 / 4] = 0;
}

extern const char lbl_80322CD0[];
extern const char lbl_80322CF4[];
extern const char lbl_80322D30[];
extern const char lbl_80322D54[];
extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
#pragma push
#pragma use_lmw_stmw off
extern "C" void *GetLowestPrioritySound__Q46nw4hbm3snd6detail19ExternalSoundPlayerFv(void *self) {
    void *node = *(void **)((u8 *)self + 4);
    void *end = (u8 *)self + 4;
    int candidate;
    int priority = 0x80;
    void *result = 0;
    extern const char lbl_80322CD0[];
    extern const char lbl_80322CF4[];
    extern const char lbl_80322D30[];
    extern const char lbl_80322D54[];
    while (node != end) {
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322D54, 0x23d, lbl_80322D30);
        int value = *(u8 *)((u8 *)node - 0x5c) + *(int *)((u8 *)node - 0x90);
        if (value <= 0x7f) candidate = value & ~(value >> 31);
        else candidate = 0x7f;
        if (priority > candidate) {
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322D54, 0x23d, lbl_80322D30);
            result = (u8 *)node - 0xd0;
            if (result == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322CF4, 0x193, lbl_80322CD0);
            priority = candidate;
        }
        node = *(void **)node;
    }
    return result;
}
#pragma pop
extern "C" void fn_800EBB88(void *arg0) {
    volatile s32 *p = (volatile s32 *)arg0;
    s32 *q = (s32 *)((u8 *)arg0 + 8);
    p[2] = 0;
    p[3] = 0;
    p[0] = 0;
    p[1] = 0;
    p[2] = (s32)q;
    p[3] = (s32)q;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void *__dt__Q46nw4hbm3snd6detail9FrameHeapFv(void *self, s32 flag) {
    if (self != 0) {
        FrameHeapDestroyView *state = (FrameHeapDestroyView *)self;
        void *heap = state->heap;
        if (heap == 0) goto done;
        if (heap == 0) goto done;
        if (state->count != 0) {
            u8 *head = (u8 *)self + 8;
            goto loop_test;
loop_body:
            if (state->count == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_8032301C, 0x1FB, (const char *)lbl_80322FF8);
            }
            {
                void *listA = *(void **)(head + 4);
                void *list = listA;
                if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FBC, 0x23D, (const char *)lbl_80322F98);
                if (listA == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FEC, 0x193, (const char *)lbl_80322FC8);
                if (list != 0) {
                    void *node = (u8 *)listA + 0xC;
                    while (1) {
                        void (*callback)(void *, void *, void *);
                        node = *(void **)((u8 *)node + 4);
                        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F5C, 0x23D, (const char *)lbl_80322F38);
                        if (node != 0) {
                            callback = *(void (**)(void *, void *, void *))((u8 *)node + 0xC);
                            if (callback != 0) callback((u8 *)node + 0x20, *(void **)((u8 *)node + 8), *(void **)((u8 *)node + 0x10));
                        }
                        if (node == *(void **)((u8 *)list + 0xC)) break;
                    }
                    if ((u8 *)list + 8 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)list + 8, 0);
                }
                if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F8C, 0x233, (const char *)lbl_80322F68);
                Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)self + 4, list);
            }
loop_test:
            if (state->count != 0) goto loop_body;
        }
        MEMFreeToFrmHeap(state->heap, 3);
        MEMDestroyFrmHeap(state->heap);
        state->heap = 0;
done:
        if ((u8 *)self + 4 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 4, 0);
        if (flag > 0) fn_80128668(self);
    }
    return self;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
bool nw4hbm::snd::detail::FrameHeap::Create(void *buffer, unsigned long size) {
    FrameHeapDestroyView *state = (FrameHeapDestroyView *)this;
    void *head2;
    if (buffer == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322D60, 0x4B, (const char *)lbl_80322D74);
    }
    if (state->heap != 0) {
        if (state->heap != 0) {
            void *volatile_head;
            if (state->count == 0) goto free_heap;
            head2 = (u8 *)state + 8;
            goto loop_test;
        loop_body:
            if (state->count == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_8032301C, 0x1FB, (const char *)lbl_80322FF8);
            }
            {
                void *list = *(void **)((u8 *)head2 + 4);
                if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FBC, 0x23D, (const char *)lbl_80322F98);
                if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FEC, 0x193, (const char *)lbl_80322FC8);
                if (list != 0) {
                    register void *node = (u8 *)list + 0xC;
                    while (1) {
                        void (*callback)(void *, void *, void *);
                        node = *(void **)((u8 *)node + 4);
                        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F5C, 0x23D, (const char *)lbl_80322F38);
                        if (node != 0) {
                            callback = *(void (**)(void *, void *, void *))((u8 *)node + 0xC);
                            if (callback != 0) callback((u8 *)node + 0x20,
                                                         *(void **)((u8 *)node + 8),
                                                         *(void **)((u8 *)node + 0x10));
                        }
                        if (node == *(void **)((u8 *)list + 0xC)) break;
                    }
                    if ((u8 *)list + 8 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)list + 8, 0);
                }
                if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F8C, 0x233, (const char *)lbl_80322F68);
                Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(&state->count, list);
            }
        loop_test:
            if (state->count != 0) goto loop_body;
        free_heap:
            MEMFreeToFrmHeap(state->heap, 3);
            MEMDestroyFrmHeap(state->heap);
            state->heap = 0;
        }
    }
    {
        u32 start = ((u32)buffer + 3) & ~3UL;
        u32 end = (u32)buffer + size;
        if (start > end) return false;
        state->heap = MEMCreateFrmHeapEx((void *)start, end - start, 0);
        if (state->heap == 0) return false;
    }
    int ok;
    void *node = MEMAllocFromFrmHeapEx(state->heap, 0x14, 4);
    if (node == 0) {
        ok = 0;
    } else {
        if (node != 0) {
            void *t = (u8 *)node + 0xC;
            *(u32 *)node = 0;
            *((u32 *)node + 1) = 0;
            *((void **)node + 3) = 0;
            *((void **)node + 4) = 0;
            *((u32 *)node + 2) = 0;
            *((void **)node + 3) = t;
            *((void **)node + 4) = t;
        }
        head2 = (u8 *)state + 8;
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F8C, 0x233, (const char *)lbl_80322F68);
        }
        void *sp8 = head2;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8 *)state + 4, &sp8, node);
        ok = 1;
    }
    if (ok == 0) return false;
    return true;
}
#pragma pop

extern "C" void MEMFreeToFrmHeap(void *, u32);
extern "C" void MEMDestroyFrmHeap(void *);
extern "C" void *MEMAllocFromFrmHeapEx(void *, u32, s32);
struct AssertFile { char name[1]; };
struct CallbackList { u32 unk[3]; void *head; };
#pragma push
#pragma small_data off
extern u8 lbl_80322D60[];
#pragma pop
extern u8 lbl_80322F38[], lbl_80322F5C[], lbl_80322F68[], lbl_80322F8C[];
extern u8 lbl_80322F98[], lbl_80322FBC[], lbl_80322FC8[], lbl_80322FEC[];
extern u8 lbl_80322FF8[], lbl_8032301C[];
#pragma push
#pragma use_lmw_stmw off
void nw4hbm::snd::detail::FrameHeap::Destroy() {
    FrameHeapDestroyView *state = (FrameHeapDestroyView *)this;
    if (state->heap == 0) return;
    if (state->count == 0) goto free_heap;
    register FrameHeapDestroyListView *head = &state->list;
    goto loop_test;
loop_body:
    if (state->count == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_8032301C, 0x1FB, (const char *)lbl_80322FF8);
    }
    {
        void *list = head->tail;
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FBC, 0x23D, (const char *)lbl_80322F98);
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FEC, 0x193, (const char *)lbl_80322FC8);
        if (list != 0) {
            register void *node = (u8 *)list + 0xC;
            while (1) {
                void (*callback)(void *, void *, void *);
                node = *(void **)((u8 *)node + 4);
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F5C, 0x23D, (const char *)lbl_80322F38);
                if (node != 0) {
                    callback = *(void (**)(void *, void *, void *))((u8 *)node + 0xC);
                    if (callback != 0) callback((u8 *)node + 0x20, *(void **)((u8 *)node + 8), *(void **)((u8 *)node + 0x10));
                }
                if (node == *(void **)((u8 *)list + 0xC)) break;
            }
            if ((u8 *)list + 8 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)list + 8, 0);
        }
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F8C, 0x233, (const char *)lbl_80322F68);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)head - 4, list);
    }
loop_test:
    if (state->count != 0) goto loop_body;
free_heap:
    MEMFreeToFrmHeap(state->heap, 3);
    MEMDestroyFrmHeap(state->heap);
    state->heap = 0;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800EC1A4(void *arg0) {
    FrameHeapDestroyView *state = (FrameHeapDestroyView *)arg0;
    register const char *file = (const char *)lbl_80322D60;
    if (state->heap == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x87, file + 0x44);
    }
    register void *head;
    if (state->count == 0) goto skip_loop;
    head = (u8 *)state + 8;
    goto loop_test;
loop_body:
    if (state->count == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_8032301C, 0x1FB, (const char *)lbl_80322FF8);
    }
    {
        void *list = *(void **)((u8 *)head + 4);
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FBC, 0x23D, (const char *)lbl_80322F98);
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FEC, 0x193, (const char *)lbl_80322FC8);
        if (list != 0) {
            register void *node = (u8 *)list + 0xC;
            while (node != *(void **)((u8 *)list + 12)) {
                void (*callback)(void *, void *, void *);
                node = *(void **)((u8 *)node + 4);
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F5C, 0x23D, (const char *)lbl_80322F38);
                if (node != 0) {
                    callback = *(void (**)(void *, void *, void *))((u8 *)node + 0xC);
                    if (callback != 0) callback((u8 *)node + 0x20, *(void **)((u8 *)node + 8), *(void **)((u8 *)node + 0x10));
                }
            }
            if ((u8 *)list + 8 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)list + 8, 0);
        }
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F8C, 0x233, (const char *)lbl_80322F68);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)head - 4, list);
    }
loop_test:
    if (state->count != 0) goto loop_body;
skip_loop:
    MEMFreeToFrmHeap(state->heap, 3);
    int var_r0;
    void *temp_r3_2 = MEMAllocFromFrmHeapEx(state->heap, 0x14, 4);
    if (temp_r3_2 == 0) {
        var_r0 = 0;
    } else {
        if (temp_r3_2 != 0) {
            void *temp_r4 = (u8 *)temp_r3_2 + 0xC;
            *(u32 *)temp_r3_2 = 0;
            *((u32 *)temp_r3_2 + 1) = 0;
            *((void **)temp_r3_2 + 3) = 0;
            *((void **)temp_r3_2 + 4) = 0;
            *((u32 *)temp_r3_2 + 2) = 0;
            *((void **)temp_r3_2 + 3) = temp_r4;
            *((void **)temp_r3_2 + 4) = temp_r4;
        }
        head = (u8 *)state + 8;
        if (temp_r3_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322F8C, 0x233, (const char *)lbl_80322F68);
        }
        void *sp8 = head;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8 *)state + 4, &sp8, temp_r3_2);
        var_r0 = 1;
    }
    if (var_r0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x91, file + 0x68);
    }
}
#pragma pop

#pragma pop

#pragma push
#pragma small_data off
extern u8 lbl_80322D60[], lbl_80322DA4[], lbl_8032301C[], lbl_80322FF8[], lbl_80322FBC[], lbl_80322F98[], lbl_80322FEC[], lbl_80322FC8[], lbl_8032304C[], lbl_80323028[];
#pragma pop
extern "C" void *MEMAllocFromFrmHeapEx(void *, u32, s32);
extern "C" u32 MEMGetAllocatableSizeForFrmHeapEx(void *, s32);
#pragma push
#pragma use_lmw_stmw off
void *nw4hbm::snd::detail::FrameHeap::Alloc(unsigned long size, void (*callback)(void *, unsigned long, void *), void *user) {
    register void *block;
    register void *list;
    register void *link;
    register const char *file = (const char *)lbl_80322D60;
    if (*(void **)this == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0xA2, file + 0x44);
    block = MEMAllocFromFrmHeapEx(*(void **)this, ((size + 0x1f) & 0xFFFFFFE0) + 0x20, 0x20);
    if (block == 0)
        return 0;
    *(u32 *)block = 0;
    *((u32 *)block + 1) = 0;
    *((u32 *)block + 2) = size;
    *((void **)block + 3) = (void *)callback;
    *((void **)block + 4) = user;
    if (*(void **)((u8 *)this + 4) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_8032301C, 0x1fb, (const char *)lbl_80322FF8);
    list = *(void **)((u8 *)this + 0xC);
    if (list == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FBC, 0x23d, (const char *)lbl_80322F98);
    if (list == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322FEC, 0x193, (const char *)lbl_80322FC8);
    link = (u8 *)list + 0xC;
    if (block == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_8032304C, 0x233, (const char *)lbl_80323028);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((u8 *)list + 8, &link, block);
    if (((u32)((u8 *)block + 0x20) & 0x1f) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0xae, file + 0x94);
    return (u8 *)block + 0x20;
}
#pragma pop
extern "C" u32 fn_800EC56C(void *arg0) {
    void **heap = (void **)arg0;
    u32 size;
    if (*heap == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80322D60, 0x127, (const char *)lbl_80322DA4);
    }
    size = MEMGetAllocatableSizeForFrmHeapEx(*heap, 0x20);
    if (size < 0x20) {
        return 0;
    }
    return (size - 0x20) & ~31;
}

extern "C" void CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl(void* headArg, void* buffer, u32 size, u32 blockSize) {
    extern u8 lbl_80323058[], lbl_80323070[];
    void** head = (void**)headArg;
    u32 addr = (u32)buffer;
    u32 start;
    u32 stride;
    u32 count;
    u32 irq;
    u32 previous;
    u32 node;
    u32 idx;
    if (buffer == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323058, 0x26, (const char*)lbl_80323070);
    irq = OSDisableInterrupts();
    start = (addr + 3) & ~3u;
    stride = (blockSize + 3) & ~3u;
    count = (size - (start - addr)) / stride;
    if (count != 0) {
        node = start;
        previous = (u32)*head;
        for (idx = 0; idx < count; idx++) {
            *(u32*)node = previous;
            *head = (void*)node;
            previous = node;
            node += stride;
        }
    }
    OSRestoreInterrupts(irq);
}

void nw4hbm::snd::detail::PoolImpl::DestroyImpl(void* buffer, unsigned long size) {
    /* Remove any free-list nodes whose addresses fall within [buffer, buffer + size). */
    if (buffer == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)::lbl_80323058, 0x44,
                                     (const char*)::lbl_80323070);
    }
    u32 savedInterruptLevel = OSDisableInterrupts();
    void** link = (void**)this;
    void* node = *link;
    while (node != 0) {
        if ((u32)buffer <= (u32)node &&
            (u32)node < (u32)buffer + (u32)size) {
            *link = *(void**)node;
        } else {
            link = (void**)node;
        }
        node = *(void**)node;
    }
    OSRestoreInterrupts(savedInterruptLevel);
}

void *nw4r::snd::detail::PoolImpl::AllocImpl() {
    void **head = (void **)this;
    void *node;
    u32 level = OSDisableInterrupts();
    node = *head;
    if (node == 0) {
        OSRestoreInterrupts(level);
        return 0;
    }
    *head = *(void **)node;
    OSRestoreInterrupts(level);
    return node;
}

extern "C" void fn_800EC848(void** head, void* node) {
    u32 level = OSDisableInterrupts();
    *(void**)node = *head;
    *head = node;
    OSRestoreInterrupts(level);
}

#pragma dont_inline on
#pragma push
#pragma small_data on
extern "C" void fn_800EC890(void *arg0) {
    f32 second;
    f32 first;
    first = lbl_80561018;
    second = lbl_8056101C;
    *(f32 *)arg0 = first;
    *(u8 *)((u8 *)arg0 + 0xC) = 1;
    *(f32 *)((u8 *)arg0 + 4) = second;
    *(s32 *)((u8 *)arg0 + 8) = 0;
}
#pragma pop
#pragma dont_inline reset

extern "C" void fn_800EC8B4(void* arg0) {
    f32 value = lbl_80561018;
    *(s32*)((u8*)arg0 + 0x10) = 0;
    *(f32*)((u8*)arg0 + 0x14) = value;
}

extern "C" void Update__Q44nw4r3snd6detail3LfoFi(void* lfo, s32 msec) {
    f32 newPhase; s32 remainingMsec; u32 nextDelayCount; u32 delayCount; u32 delayThreshold;
    /* Advance the LFO delay counter, then advance and wrap the phase by the
     * remaining milliseconds at the configured rate (per 1000 ms). */
    remainingMsec = msec; delayThreshold = *(u32*)((u8*)lfo + 8); delayCount = *(u32*)((u8*)lfo + 0x10);
    if (delayCount < delayThreshold) {
        nextDelayCount = delayCount + remainingMsec;
        if (nextDelayCount <= delayThreshold) { *(u32*)((u8*)lfo + 0x10) = nextDelayCount; return; }
        *(u32*)((u8*)lfo + 0x10) = delayThreshold; remainingMsec -= delayThreshold - delayCount;
    }
    newPhase = *(f32*)((u8*)lfo + 0x14) + ((*(f32*)((u8*)lfo + 4) * (f32)remainingMsec) / lbl_80561020);
    *(f32*)((u8*)lfo + 0x14) = newPhase;
    *(f32*)((u8*)lfo + 0x14) = (f32)(newPhase - (f32)(s32)newPhase);
}

extern const s8 lbl_802F4D90[];
extern const char lbl_803230A0[], lbl_803230AC[];
extern const f32 lbl_80561030, lbl_80561034, lbl_80561038;
extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern "C" f32 GetValue__Q46nw4hbm3snd6detail3LfoCFv(void *arg0) {
    s32 index;
    s32 valid;
    s8 tableValue;
    f32 angle;
    f32 value;
    f32 currentLevel;
    u8 level;
    if (lbl_80561018 == *(f32 *)arg0) return lbl_80561018;
    if (*(u32 *)((u8 *)arg0 + 0x10) < *(u32 *)((u8 *)arg0 + 8)) return lbl_80561018;
    valid = 0;
    angle = lbl_80561030 * (lbl_80561034 * *(f32 *)((u8 *)arg0 + 0x14));
    index = (s32)angle;
    if (index >= 0 && index < 0x80) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803230A0, 0x7b, lbl_803230AC, index, 0, 0x80);
    if (index < 0x20) tableValue = lbl_802F4D90[index];
    else if (index < 0x40) {
        s32 off = index - 0x20;
        tableValue = lbl_802F4D90[0x20 - off];
    } else if (index < 0x60) tableValue = -lbl_802F4D90[index - 0x40];
    else {
        s32 off = index - 0x60;
        tableValue = -lbl_802F4D90[0x20 - off];
    }
    value = (f32)tableValue / lbl_80561038;
    level = *(u8 *)((u8 *)arg0 + 0xC);
    currentLevel = *(f32 *)arg0;
    value *= currentLevel;
    value *= (f32)level;
    return value;
}

extern "C" void *fn_800ECAEC(void *arg0) {
    extern void fn_800F26D8(void *);
    extern void fn_800F2D28(void *, void *);
    extern u8 lbl_80323238[];
    fn_800F26D8(arg0);
    *(s32 *)((u8 *)arg0 + 0x108) = 0;
    *(u8 **)arg0 = lbl_80323238;
    fn_800F2D28((u8 *)arg0 + 0x10C, lbl_80323238);
    return arg0;
}

extern "C" void *fn_800F26FC(void *, unsigned int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800ECB38(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_800F26FC(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma opt_common_subs off
extern "C" s32 fn_800ECB90(void *arg0, s32 arg1) {
    extern u8 lbl_803230E8[];
    extern void Init__Q46nw4hbm3snd6detail22SoundArchiveFileReaderFPCv(void *, const void *);
    extern void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi_800F2750(void *, s32);
    extern void SetInfoChunk__Q46nw4hbm3snd6detail22SoundArchiveFileReaderFPCvUl(void *, const void *, u32);
    extern void fn_800F2EAC(void *, const void *, u32);
    const char *file = (const char *)lbl_803230E8;
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x43, file + 0x1C);
    }
    if (((u32)arg1 & 3) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x44, file + 0x50, arg1);
    }
    Init__Q46nw4hbm3snd6detail22SoundArchiveFileReaderFPCv((u8 *)arg0 + 0x10C, (const void *)arg1);
    detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi_800F2750(arg0, (s32)((u8 *)arg0 + 0x10C));
    SetInfoChunk__Q46nw4hbm3snd6detail22SoundArchiveFileReaderFPCvUl((u8 *)arg0 + 0x10C, (const void *)(*(u32 *)((u8 *)arg0 + 0x124) + (u32)arg1), *(u32 *)((u8 *)arg0 + 0x128));
    fn_800F2EAC((u8 *)arg0 + 0x10C, (const void *)(*(u32 *)((u8 *)arg0 + 0x11C) + (u32)arg1), *(u32 *)((u8 *)arg0 + 0x120));
    *(s32 *)((u8 *)arg0 + 0x108) = arg1;
    return 1;
}
#pragma pop
extern "C" void fn_800F27AC(void *);
extern "C" void fn_800ECC58(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x108) = 0;
    ((void (*)(void))fn_800F27AC)();
}

/* Resolve the absolute file address for a sound archive item id, or 0 if unavailable. */
s32 nw4hbm::snd::MemorySoundArchive::detail_GetFileAddress(u32 soundId) const {
    struct { s32 v[13]; } fileInfo;
    if (!fn_800F283C((void *)this, soundId, 0, &fileInfo.v[0])) return 0;
    if (!fn_800F2824((void *)this, fileInfo.v[0], &fileInfo.v[8])) return 0;
    if (!fn_800F282C((void *)this, fileInfo.v[0], fileInfo.v[1], &fileInfo.v[2])) return 0;
    if (fileInfo.v[9] != 0) return 0;
    return (fileInfo.v[3] + *(u32 *)((u8 *)this + 0x108)) + fileInfo.v[10];
}

extern u8 lbl_803231D8[];
extern "C" s32 fn_800F283C(void *, u32, s32, s32 *);
extern "C" s32 fn_800F2824(void *, s32, void *);
extern "C" s32 fn_800F282C(void *, s32, s32, void *);
extern "C" s32 detail_GetWaveDataFileAddress__Q36nw4hbm3snd18MemorySoundArchiveCFUl_800ECD14(void *archive, u32 id) {
    /* Resolves the absolute wave data file address for a sound archive item id.
       Returns 0 if lookup fails or the group/item is unavailable. */
    struct { s32 v[13]; } info;

    if (!fn_800F283C(archive, id, 0, &info.v[0])) return 0;
    if (!fn_800F2824(archive, info.v[0], &info.v[8])) return 0;
    if (!fn_800F282C(archive, info.v[0], info.v[1], &info.v[2])) return 0;
    if (info.v[9] != 0) return 0;
    return (info.v[5] + *(u32 *)((u8 *)archive + 0x108)) + info.v[12];
}

extern "C" void *OpenStream__Q34nw4r3snd18MemorySoundArchiveCFPviUlUl(void *this_, void *stream, u32 bufferSize, s32 offset, u32 length) {
    u32 base = *(u32 *)((u8 *)this_ + 0x108);
    if (base == 0) return 0;
    if (bufferSize < 0x20) return 0;
    if (!stream) return stream;
    *(u8 *)((u8 *)stream + 4) = 0;
    *(u32 *)((u8 *)stream + 0xC) = 0;
    *(u32 *)((u8 *)stream + 0x10) = 0;
    *(u8 **)stream = lbl_803231D8;
    *(u32 *)((u8 *)stream + 0x14) = offset + base;
    *(u32 *)((u8 *)stream + 0x18) = length;
    *(u32 *)((u8 *)stream + 0x1C) = 0;
    return stream;
}

extern u8 lbl_803230E8[];
extern u8 lbl_8032318C[];
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char* file, int line, const char* fmt, ...);
extern "C" s32 fn_800ECE24(void) {
    Warning__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803230E8, 0xBD, (const char*)lbl_8032318C);
    return 0;
}

extern "C" s32 fn_800ECE60(void) {
    return 0x20;
}

extern "C" s32 fn_800ECE68(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668_noarg();
    }
    return arg0;
}

extern "C" s32 fn_800ECEA8(void* arg0, s32 arg1) {
    if (arg0 != NULL && arg1 > 0) {
        fn_80128668_noarg();
    }
    return (s32)arg0;
}

extern "C" void fn_800ECEE8(void* arg0) {
    *(s32*)((u8*)arg0 + 0x14) = 0;
    *(s32*)((u8*)arg0 + 0x18) = 0;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
}

extern "C" u32 Read__Q44nw4r3snd18MemorySoundArchive16MemoryFileStreamFPvUl(void *this_, void *dst, u32 size) {
    u32 pos = *(u32 *)((u8 *)this_ + 0x1C);
    u32 remaining = *(u32 *)((u8 *)this_ + 0x18) - pos;
    u32 count = size;
    if (size > remaining)
        count = remaining;
    memcpy(dst, (void *)(pos + *(u32 *)((u8 *)this_ + 0x14)), count);
    return count;
}

extern u8 lbl_803231C0[];
extern "C" void fn_800ECF54(void *arg0, s32 arg1, s32 arg2) {
    switch (arg2) {
    case 0:
        *(s32 *)((u8 *)arg0 + 0x1C) = arg1;
        break;
    case 1:
        *(s32 *)((u8 *)arg0 + 0x1C) += arg1;
        break;
    case 2:
        *(s32 *)((u8 *)arg0 + 0x1C) =
            *(s32 *)((u8 *)arg0 + 0x18) - arg1;
        break;
    default:
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803230E8, 0xEC,
                                     (const char *)lbl_803231C0);
    }
}

extern "C" u32 fn_800ECFC0(void) { return 1; }

extern "C" u32 fn_800ECFC8(void) { return 1; }

extern "C" u32 fn_800ECFD0(void) { return 1; }

extern "C" u32* fn_800ECFD8(void) {
    return &lbl_8055DEA0;
}

extern "C" s32 fn_800ECFE0(void *arg0) {
    return ((s32 *)arg0)[0x18 / 4];
}

extern u32 lbl_8055DEA0;
extern "C" s32 fn_800ECFE8(void *arg0) {
    return ((s32 *)arg0)[0x1C / 4];
}

extern "C" s32 fn_800ECFF0(void) {
    return 0;
}

extern "C" u32 fn_800ECFF8(void) { return 1; }

extern "C" s32 fn_800ED000(void) { return 0; }

extern "C" u32 fn_800ED008(void) { return 1; }

extern "C" u32 fn_800ED010(void) { return 1; }

extern "C" s32 fn_800ED018(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668_noarg();
    }
    return arg0;
}

#pragma dont_inline on
extern "C" void fn_800ED058(s32 arg0 = 0) {
    return;
}
#pragma dont_inline off

extern "C" f32 fn_800ED05C(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x38); }

extern "C" f32 fn_800ED064(void *arg0) {
    return ((f32 *)arg0)[0x30 / 4];
}

extern "C" f32 fn_800ED06C(void *arg0) {
    return ((f32 *)arg0)[0x2C / 4];
}

extern "C" f32 fn_800ED074(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" f32 fn_800ED07C(void *arg0) {
    return ((f32 *)arg0)[0x20 / 4];
}

extern "C" f32 fn_800ED084(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 0x34);
}

extern "C" f32 fn_800ED08C(void *arg0) {
    return ((f32 *)arg0)[0x1C / 4];
}

extern "C" s32 fn_800ED094(s32 arg0) {
    u8 val = ((u8 *)arg0)[0x18];
    s32 t = -(s32)val;
    return (s32)((u32)(t | (s32)val) >> 31);
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" s32 fn_800ED0A8(s32 arg0) {
    u8 val = ((u8 *)arg0)[0x17];
    s32 t = -(s32)val;
    return (s32)((u32)(t | (s32)val) >> 31);
}
extern "C" s32 fn_800ED0BC(void *arg0) {
    return ((u8 *)arg0)[0x16] != 0;
}
extern "C" s32 fn_800ED0D0(void *arg0) {
    return ((u8 *)arg0)[0x15] != 0;
}
#pragma push
#pragma small_data off
#pragma pop
extern "C" void fn_800ED0E4(s32 arg0) {
    fn_800ED058(arg0 - 8);
}

extern "C" void InvalidateData__Q46nw4hbm3snd6detail9SeqPlayerFPCvPCv(void* this_, const void* arg1, const void* arg2);
extern "C" void fn_800ED0EC(void* player, const void* arg1, const void* arg2) {
    InvalidateData__Q46nw4hbm3snd6detail9SeqPlayerFPCvPCv((u8*)player - 8, arg1, arg2);
}

extern "C" s32 fn_800ED0F4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668_noarg();
    return arg0;
}

using namespace nw4hbm::snd::detail;
#pragma use_lmw_stmw off
int MmlParser::Parse(MmlSeqTrack *track, bool doNoteOn) const {
    const char *str = (const char *)lbl_80323268;
    SeqPlayer *player;
    SeqArgType argType;
    bool enabled;
    bool useArg;
    u8 cmd;
    s32 a;
    s32 b;
    s32 v;

    if (track == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(str, 0x31, str + 0x18);
    }
    player = track->player;
    if (player == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(str, 0x33, str + 0x40);
    }
    useArg = false;
    enabled = true;
    cmd = *track->cur++;
    if (cmd == 0xa2) {
        cmd = *track->cur++;
        enabled = track->field_0xc0 != 0;
    }
    if (cmd == 0xa0) {
        argType = ARG_EXPR;
        useArg = true;
        cmd = *track->cur++;
    }
    if (cmd == 0xa1) {
        argType = ARG_VAR;
        useArg = true;
        cmd = *track->cur++;
    }
    if (!(cmd & 0x80)) {
        u8 vel = *track->cur++;
        s32 key;
        a = ReadArg(&track->cur, player, (SeqTrack *)track, useArg ? argType : ARG_VLQ);
        key = cmd + track->transpose;
        if (!enabled) {
            return 0;
        }
        key = key > 127 ? 127 : (key < 0 ? 0 : key);
        if (track->field_0x5c == 0 && doNoteOn) {
            NoteOnCommandProc(track, key, vel, a > 0 ? a : -1, track->field_0xc2);
        }
        if (track->field_0xc1 != 0) {
            track->field_0x58 = a;
            if (a == 0) {
                track->field_0x5e = 1;
            }
        }
    } else {
        a = 0;
        b = 0;
        switch (cmd & 0xf0) {
        case 0x80:
            switch (cmd) {
            case 0x80:
                v = ReadArg(&track->cur, player, (SeqTrack *)track, useArg ? argType : ARG_VLQ);
                if (enabled) {
                    track->field_0x58 = v;
                }
                break;
            case 0x81:
                v = ReadArg(&track->cur, player, (SeqTrack *)track, useArg ? argType : ARG_VLQ);
                if (enabled) {
                    CommandProc(track, cmd, v, 0);
                }
                break;
            case 0x88: {
                u32 b0 = *track->cur++;
                u32 w = *track->cur++ << 8;
                w |= *track->cur++;
                u32 b3 = *track->cur++;
                if (enabled) {
                    CommandProc(track, cmd, b0, (w << 8) | b3);
                }
                break;
            }
            case 0x89: {
                u32 w = *track->cur++ << 8;
                w |= *track->cur++;
                u32 b2 = *track->cur++;
                if (enabled) {
                    CommandProc(track, cmd, (w << 8) | b2, 0);
                }
                break;
            }
            case 0x8a: {
                u32 w = *track->cur++ << 8;
                w |= *track->cur++;
                u32 b2 = *track->cur++;
                if (enabled) {
                    CommandProc(track, cmd, (w << 8) | b2, 0);
                }
                break;
            }
            }
            break;
        case 0xc0:
        case 0xd0:
            v = ReadArg(&track->cur, player, (SeqTrack *)track, useArg ? argType : ARG_BYTE);
            if (enabled) {
                s32 w;
                if ((s32)cmd >= 0xc5) {
                    w = (u8)v;
                } else if ((s32)cmd >= 0xc3) {
                    w = (s8)(u8)v;
                } else {
                    w = (u8)v;
                }
                CommandProc(track, cmd, w, 0);
            }
            break;
        case 0x90:
        case 0xb0:
            if (enabled) {
                CommandProc(track, cmd, 0, 0);
            }
            break;
        case 0xe0:
            v = (s16)ReadArg(&track->cur, player, (SeqTrack *)track, useArg ? argType : ARG_WORD);
            if (enabled) {
                CommandProc(track, cmd, v, 0);
            }
            break;
        case 0xf0:
            switch (cmd) {
            case 0xfe:
                Panic__Q26nw4hbm2dbFPCciPCce(str, 0x105, str + 0x6c);
                break;
            case 0xff:
                return 1;
            case 0xf0: {
                u8 sub = *track->cur++;
                switch (sub & 0xf0) {
                case 0xe0:
                    a = (s16)ReadArg(&track->cur, player, (SeqTrack *)track, useArg ? argType : ARG_WORD);
                    if (enabled) {
                        CommandProc(track, (cmd << 8) + sub, a, 0);
                    }
                    break;
                case 0x80:
                case 0x90:
                    a = *track->cur++;
                    b = (s16)ReadArg(&track->cur, player, (SeqTrack *)track, useArg ? argType : ARG_WORD);
                    if (enabled) {
                        CommandProc(track, (cmd << 8) + sub, a, b);
                    }
                    break;
                }
            }
            default:
                if (enabled) {
                    CommandProc(track, cmd, a, b);
                }
                break;
            }
            break;
        }
    }
    return 0;
}

void MmlParser::CommandProc(MmlSeqTrack *track, u32 command, s32 arg, s32 arg2) const { (void)track; (void)command; (void)arg; (void)arg2; }

#pragma use_lmw_stmw reset

#pragma push
#pragma small_data off
extern f32 lbl_80561018;
extern f32 lbl_8056101C;
extern f32 lbl_80561020;
extern f64 lbl_80561028;
#pragma pop
extern "C" void fn_800F2330(s32, s32, s32, s32, s32);
#pragma push
#pragma small_data off
extern "C" void fn_800EE060(void* this_, s32 a, s32 b, s32 c, s32 d, s32 e) {
    fn_800F2330(a, b, c, d, e);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s16* GetVariablePtr__Q46nw4hbm3snd6detail9SeqPlayerFi(void*, s32);
extern "C" s16* GetVariablePtr__Q46nw4hbm3snd6detail8SeqTrackFi(void*, s32);
#pragma push
#pragma use_lmw_stmw off
s32 nw4hbm::snd::detail::MmlParser::ReadArg(const u8 **pp, SeqPlayer *player, SeqTrack *track, SeqArgType type) const {
    register const u8 **rpp = pp;
    register SeqPlayer *rplayer = player;
    register SeqTrack *rtrack = track;
    register const char *rbase = (const char*)::lbl_80323268;
    s32 res;
    if (type == (SeqArgType)2) {
        s32 count = 0;
        res = 0;
        for (;;) {
            const u8 *p;
            u8 b;
            if (count >= 4) {
                Panic__Q26nw4hbm2dbFPCciPCce(rbase, 0x326, rbase + 0x4C4);
            }
            p = *rpp;
            res <<= 7;
            *rpp = p + 1;
            b = *p;
            res |= (b & 0x7F);
            if ((b & 0x80) == 0) break;
            count++;
        }
    } else if (type == (SeqArgType)0) {
        const u8 *p = *rpp;
        *rpp = p + 1;
        res = *p;
    } else if (type == (SeqArgType)1) {
        const u8 *p = *rpp;
        u8 b0 = *p;
        *rpp = p + 1;
        u8 b1 = *(p + 1);
        *rpp = p + 2;
        res = (b0 << 8) | b1;
    } else if (type == (SeqArgType)4) {
        const u8 *p = *rpp;
        u8 v = *p;
        s16 *ptr;
        *rpp = p + 1;
        if (v > 0x30) {
            Panic__Q26nw4hbm2dbFPCciPCce(rbase, 0x370, rbase + 0xC8, v, 0, 0x30);
        }
        if (v < 0x20) {
            ptr = GetVariablePtr__Q46nw4hbm3snd6detail9SeqPlayerFi((void*)rplayer, v);
        } else if (v < 0x30) {
            ptr = GetVariablePtr__Q46nw4hbm3snd6detail8SeqTrackFi((void*)rtrack, v - 0x20);
        } else {
            ptr = 0;
        }
        if (ptr == 0) return 0;
        res = *ptr;
    } else if (type == (SeqArgType)3) {
        const u8 *p = *rpp;
        u8 b0 = *p;
        *rpp = p + 1;
        u8 b1 = *(p + 1);
        *rpp = p + 2;
        s16 first = (s16)((b0 << 8) | b1);
        u8 b2 = *(p + 2);
        *rpp = p + 3;
        u8 b3 = *(p + 3);
        *rpp = p + 4;
        s16 second = (s16)((b2 << 8) | b3);
        u32 rnd = fn_800FEB9C();
        u32 low = rnd & 0xFFFF;
        s32 diff = (s32)second - (s32)first;
        s32 range = diff + 1;
        s32 scaled = (s32)(low * (u32)range) >> 16;
        res = (s32)first + scaled;
    } else {
        res = 0;
    }
    return res;
}
#pragma pop

#pragma push
#pragma dont_inline on
extern "C" void * __ct__Q46nw4hbm3snd6detail11MmlSeqTrackFv(void *arg0) {
    extern u8 lbl_80323258[];
    extern u8 lbl_80323760[];
    extern void fn_800EC890(void *);
    extern void InitParam__Q46nw4hbm3snd6detail8SeqTrackFv(void *);
    *(u8 **)arg0 = lbl_80323258;
    fn_800EC890((u8 *)arg0 + 0x68);
    *(s32 *)((u8 *)arg0 + 0xB4) = 0;
    InitParam__Q46nw4hbm3snd6detail8SeqTrackFv(arg0);
    *((u8 *)arg0 + 0xC1) = 1;
    *(u8 **)arg0 = lbl_80323760;
    *((u8 *)arg0 + 0xC2) = 0;
    *((u8 *)arg0 + 0xC0) = 1;
    *((u8 *)arg0 + 0xC6) = 0;
    return arg0;
}
#pragma pop

extern "C" void fn_800EE2E0(void *arg0, s32 arg1) {
    extern s32 Parse__Q46nw4hbm3snd6detail9MmlParserCFPQ46nw4hbm3snd6detail11MmlSeqTrackb(void *, void *, s32);
    Parse__Q46nw4hbm3snd6detail9MmlParserCFPQ46nw4hbm3snd6detail11MmlSeqTrackb(*(void **)((u8 *)arg0 + 0xBC), arg0, arg1);
}

extern "C" s32 fn_800EE2F4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668_noarg();
    }
    return arg0;
}

extern "C" void * __ct__Q46nw4hbm3snd6detail11MmlSeqTrackFv(void *);
extern "C" void *AllocTrack__Q46nw4hbm3snd6detail20MmlSeqTrackAllocatorFPQ46nw4hbm3snd6detail9SeqPlayer(void *arg0, void *arg1) {
    extern void *AllocImpl__Q44nw4r3snd6detail8PoolImplFv(void *);
    void *track = AllocImpl__Q44nw4r3snd6detail8PoolImplFv((u8 *)arg0 + 8);
    if (track == 0) {
        track = 0;
    } else if (track != 0) {
        track = __ct__Q46nw4hbm3snd6detail11MmlSeqTrackFv(track);
    }
    if (track != 0) {
        *(void **)((u8 *)track + 0xB4) = arg1;
        *(void **)((u8 *)track + 0xBC) = *(void **)((u8 *)arg0 + 4);
    }
    return track;
}

extern "C" void OSCreateAlarm(void*);
extern "C" void OSSetAlarmUserData(void*, void*);
extern "C" void* memset(void*, int, u32);
extern u8 lbl_80323770[];
extern u8 lbl_80323790[];
#pragma push
#pragma dont_inline on
extern "C" void FreeTrack__Q46nw4hbm3snd6detail20MmlSeqTrackAllocatorFPQ46nw4hbm3snd6detail8SeqTrack(void* allocator, void* track) {
    /* Free a sequence track: clear its owner/player field, run its destructor-like vfunc, and return it to the allocator pool. */
    struct SeqTrackVTable {
        virtual void destroy(s32);
    };
    if (track == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323770, 0x3B, (const char*)lbl_80323790);
    *(u32*)((u8*)track + 0xB4) = 0;
    if (track != 0) {
        ((SeqTrackVTable*)track)->destroy(-1);
        fn_800EC848((void**)((u8*)allocator + 8), track);
    }
}
#pragma pop
extern "C" void CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl(void*, void*, u32, u32);
extern "C" void fn_800EE428(void* arg0, void* arg1, u32 arg2) {
    CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl((u8*)arg0 + 8, arg1, arg2, 0xD4);
}

extern "C" void DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(void*);
extern "C" s32 NANDClose(void*);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void fn_800F27AC(void*);
#pragma push
#pragma small_data off
extern u8 lbl_803237D0[];
extern u8 lbl_803237EC[];
#pragma pop
extern "C" void fn_800EE434(void* arg0) {
    DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl((u8*)arg0 + 8);
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" s32 fn_800EE43C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668_noarg();
    }
    return arg0;
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" void fn_800EE47C(void* arg0) {
    s32 result;
    if (((u8*)arg0)[0x1D8] != 0) {
        result = NANDClose((u8*)arg0 + 0x14C);
        if (result != 0) {
            Warning__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803237D0, 0x8D,
                                          (const char*)lbl_803237EC, result);
        }
        ((u8*)arg0)[0x1D8] = 0;
    }
    fn_800F27AC(arg0);
}

extern "C" void OSCreateAlarm(void*);
extern "C" void OSSetAlarmUserData(void*, void*);
extern "C" void* memset(void*, int, u32);
extern u8 lbl_80323770[];
extern u8 lbl_80323790[];
#pragma dont_inline on
extern "C" void* fn_800EE4F0(void* arg0) {

    u8* p = (u8*)arg0;
    p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0; p[6] = 0;
    *(u32*)(p + 0x30) = 0;
    OSCreateAlarm(p + 0x38);
    OSSetAlarmUserData(p + 0x38, arg0);
    OSCreateAlarm(p + 0x68);
    OSSetAlarmUserData(p + 0x68, arg0);
    return arg0;
}

extern "C" void fn_800EE568(void* arg0) {
    u8* p = (u8*)arg0;
    p[2] = 0; p[3] = 0;
    OSCancelAlarm(p + 0x38);
    p[7] = 0;
    OSCancelAlarm(p + 0x68);
    p[8] = 0; p[2] = 0; p[3] = 1;
    memset(p + 9, 0, 0x20);
    p[6] = 0; p[7] = 0; p[8] = 0; p[5] = 0;
}

extern "C" s32 WPADCanSendStreamData(s32);
extern "C" s32 WENCGetEncodeData(void*, u32, const s16*, s32, void*);
extern "C" s32 fn_80062278(s32, void*, s32);
extern "C" void OSSetAlarm(void*, u32, u32, u32, void (*)(void));
extern "C" void fn_800EE910(void*);
extern "C" void IntervalAlarmHandler__Q34nw4r3snd13RemoteSpeakerFP7OSAlarmP9OSContext(void*, void*);
#pragma push
#pragma use_lmw_stmw off
extern "C" void* fn_800EE5E8(void* arg0, void* arg1) {
    u8 first = ((volatile u8*)arg0)[1];
    u8* file = lbl_80323840;
    u8* state;
    const s16* pcm;
    u32 outerLevel;
    s32 active, startAlarm, repeatAlarm, encoded;
    u32 mode;
    u8 encodedBuffer[0x18];
    pcm = (const s16*)arg1;
    state = (u8*)arg0;
    if (first == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)file, 0x101,
                                     (const char*)file + 0x38);
    if (state[1] != 0) {
        outerLevel = OSDisableInterrupts();
        if (WPADCanSendStreamData(*(s32*)(state + 0x2C)) == 0) {
            OSRestoreInterrupts(outerLevel);
        } else {
            active = 1;
            {
                s32 allZero;
                if (state[3] != 0) {
                    u32* words = (u32*)pcm;
                    allZero = 1;
                    {
                        u32 i;
                        for (i = 1; i <= 10; i += 9) {
                            if (words[0] != 0) { allZero = 0; goto scanDone; }
                            if (words[1] != 0) { allZero = 0; goto scanDone; }
                            if (words[2] != 0) { allZero = 0; goto scanDone; }
                            if (words[3] != 0) { allZero = 0; goto scanDone; }
                            if (words[4] != 0) { allZero = 0; goto scanDone; }
                            if (words[5] != 0) { allZero = 0; goto scanDone; }
                            if (words[6] != 0) { allZero = 0; goto scanDone; }
                            if (words[7] != 0) { allZero = 0; goto scanDone; }
                            if (words[8] != 0) { allZero = 0; goto scanDone; }
                            if (words[9] != 0) { allZero = 0; goto scanDone; }
                            words += 10;
                        }
                    }
                } else {
                    allZero = 1;
                }
scanDone:
                if (allZero != 0 || state[6] != 0) active = 0;
            }
            startAlarm = 0;
            repeatAlarm = 0;
            if (state[2] != 0) {
                if (active != 0) {
                    mode = 1;
                } else {
                    mode = 1;
                    repeatAlarm = 1;
                }
            } else if (active != 0) {
                startAlarm = 1;
                mode = state[5] == 0 ? 1 : 0;
                state[5] = 0;
            } else mode = -1;
            if ((mode + 0x10000U) != 0xFFFFU) {
                WENCGetEncodeData(state + 9, (u32)mode, pcm,
                                  mode == 2 ? 0x20 : 0x28, encodedBuffer);
                if ((encoded = fn_80062278(
                         *(s32*)(state + 0x2C), encodedBuffer, 0x14)) != 0)
                    Warning__Q26nw4hbm2dbFPCciPCce(
                        (const char*)file, 0x154,
                        (const char*)file + 0x60, encoded);
            }
            if (startAlarm != 0) {
                u32 level = OSDisableInterrupts();
                if (state[7] == 0) {
                    u32 ticks = *(volatile u32*)0x800000F8 >> 2;
                    u64 scaled = (u64)ticks * 0x1E0;
                    ((void (*)(void*, u32, u64, void (*)(void)))OSSetAlarm)(
                        state + 0x38, (u32)0, scaled,
                        (void (*)(void))fn_800EE910);
                    {
                        u64 time = OSGetTime();
                        *(u32*)(state + 0x9C) = (u32)time;
                        *(u32*)(state + 0x98) = (u32)(time >> 32);
                    }
                    state[7] = 1;
                }
                OSCancelAlarm(state + 0x68);
                state[8] = 0;
                OSRestoreInterrupts(level);
            }
            if (repeatAlarm != 0) {
                u32 level = OSDisableInterrupts();
                state[8] = 1;
                OSCancelAlarm(state + 0x68);
                ((void (*)(void*, u32, u64, void (*)(void)))OSSetAlarm)(
                    state + 0x68, (u32)0,
                    (u64)(*(volatile u32*)0x800000F8 >> 2),
                    (void (*)(void))IntervalAlarmHandler__Q34nw4r3snd13RemoteSpeakerFP7OSAlarmP9OSContext);
                OSRestoreInterrupts(level);
            }
            state[2] = (u8)active;
            OSRestoreInterrupts(outerLevel);
        }
    }
}
#pragma pop
extern "C" void fn_800EE910(void* alarm) {
    s32 level = (s32)OSDisableInterrupts();
    u8* data = (u8*)OSGetAlarmUserData(alarm);
    Warning__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323840, 0x224, (const char*)lbl_803238C0, *(s32*)(data + 0x2C));
    data[6] = 1;
    data[7] = 0;
    OSRestoreInterrupts((u32)level);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void IntervalAlarmHandler__Q34nw4r3snd13RemoteSpeakerFP7OSAlarmP9OSContext(void* alarm, void* context) {
    register void* savedAlarm = alarm;
    register u32 level;
    register u8* data;
    level = OSDisableInterrupts();
    data = (u8*)OSGetAlarmUserData(savedAlarm);
    if (data[8] != 0) {
        OSCancelAlarm(data + 0x38);
        data[6] = 0;
        data[7] = 0;
    }
    data[8] = 0;
    OSRestoreInterrupts(level);
}
#pragma pop
extern "C" void* OSGetAlarmUserData(void*);
extern "C" void OSCancelAlarm(void*);
extern "C" void* fn_800EE4F0(void*);
#pragma push
#pragma small_data off
extern u8 lbl_804127A8[];
#pragma pop
extern u8 lbl_8055DE40;
#pragma dont_inline fn_800EE4F0
extern "C" void* GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv(void) {
    if ((s8)lbl_8055DE40 == 0) {
        /* Lazily initialize singleton RemoteSpeakerManager and its speaker slots. */
        u8* end;
        u8* instance;
        u8* speaker;

        instance = lbl_804127A8;
        instance[0] = 0;
        speaker = instance + 0x38;
        end = instance + 0x2B8;
        do {
            fn_800EE4F0(speaker);
            speaker += 0xA0;
        } while (speaker < end);

        *(s32*)(instance + 0x64) = 0;
        *(s32*)(instance + 0x104) = 1;
        *(s32*)(instance + 0x1A4) = 2;
        *(s32*)(instance + 0x244) = 3;
        lbl_8055DE40 = 1;
    }
    return lbl_804127A8;
}

#pragma push
#pragma use_lmw_stmw off
void nw4hbm::snd::detail::RemoteSpeakerManager::Setup() {
    u8 *p;
    s32 i;
    if (((u8 *)this)[0] == 0) {
        p = (u8 *)this + 0x38;
        i = 0;
        do {
            fn_800EE568(p);
            i++;
            p += 0xA0;
        } while (i < 4);
        OSCreateAlarm((void *)((u8 *)this + 8));
        u64 time = OSGetTime();
        u32 ticks = *(volatile u32 *)0x800000F8;
        u32 q = (ticks >> 2) / 125000;
        u32 period = q * 0x0065B9AB;
        u32 interval = period / 8000;
        OSSetPeriodicAlarm((void *)((u8 *)this + 8), q, (u32)(time >> 32), (u32)time, 0, interval, (void *)&fn_800EEBA8);
        ((u8 *)this)[0] = 1;
    }
}
#pragma pop

extern "C" u64 OSGetTime(void);
extern "C" void OSSetPeriodicAlarm(void*, u32, u32, u32, u32, u32, void*);
extern "C" void fn_800EE568(void*);
extern "C" void fn_800EEBA8(void*, u64, u64);
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv
extern "C" int Setup__Q46nw4hbm3snd6detail9SeqPlayerFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback(void *self, void *allocator, u32 mask, s32 param, void *callback) {
    struct Allocator {
        virtual void unused0();
        virtual void *AllocTrack(void *);
        virtual void FreeTrack(void *);
    };
    void *player = self;
    const char *file = (const char *)lbl_80323B28;
    u32 level = OSDisableInterrupts();
    if (*(u8 *)((u8 *)player + 0x15) != 0) {
        s32 state;
        u32 temp = OSDisableInterrupts();
        if (*(u8 *)((u8 *)player + 0x17) != 0) {
            if (player == 0)
                Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324054, 0x233, (const char *)lbl_80324030);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((void *)lbl_80412A6C, (u8 *)player + 0x100);
        }
        if (*(u8 *)((u8 *)player + 0x15) != 0) {
            state = (s32)player;
            if (player != 0) state += 8;
            void *manager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
            UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(manager, (void *)state);
        }
        OSRestoreInterrupts(temp);
        u8 *entry = (u8 *)player;
        state = 0;
        temp = 0;
        s32 valid;
        void *seq;
        do {
            valid = 0;
            if (state >= 0 && state < 16) valid = 1;
            if (valid == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(file, 0x2FD, file + 0x14, state, 0, 16);
            seq = state > 15 ? (void *)temp : *(void **)(entry + 0x9C);
            if (seq != 0) {
                Close__Q46nw4hbm3snd6detail8SeqTrackFv(seq);
                void *manager = *(void **)((u8 *)player + 0x98);
                ((Allocator *)manager)->FreeTrack(*(void **)(entry + 0x9C));
                *(void **)(entry + 0x9C) = (void *)temp;
            }
            ++state;
            entry += 4;
        } while (state < 16);
        *(u8 *)((u8 *)player + 0x15) = 0;
    }
    InitParam__Q46nw4hbm3snd6detail9SeqPlayerFiPQ46nw4hbm3snd6detail14NoteOnCallback(player, param, callback);
    {
        u32 bits = mask;
        u8 *entry = (u8 *)player;
        s32 ok = 1;
        s32 idx = 0;
        while (bits != 0) {
            if (bits & 1) {
                void *track = ((Allocator *)allocator)->AllocTrack(player);
                if (track == 0) {
                    ok = 0;
                    break;
                }
                if (idx <= 15) {
                    *(void **)(entry + 0x9C) = track;
                    SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi_800F0E9C(track, idx);
                }
            }
            bits >>= 1;
            entry += 4;
            idx++;
        }
        if (ok == 0) {
            idx = 0;
            while (mask != 0) {
                if (mask & 1) {
                    void *track = idx > 15 ? (void *)0 : *(void **)((u8 *)player + 0x9C);
                    if (track != 0) ((Allocator *)allocator)->FreeTrack(track);
                }
                mask >>= 1;
                player = (u8 *)player + 4;
                idx++;
            }
            Warning__Q26nw4hbm2dbFPCciPCce(file, 0xC6, file + 0x54);
            OSRestoreInterrupts(level);
            return 1;
        }
    }
    {
        s32 reg = (s32)player;
        if (player != 0) reg += 8;
        void *manager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
        RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(manager, (void *)reg);
    }
    *(void **)((u8 *)player + 0x98) = allocator;
    *(u8 *)((u8 *)player + 0x15) = 1;
    OSRestoreInterrupts(level);
    return 0;
}
#pragma pop
extern "C" void fn_800EEB64(u8 *arg0) {
    if (arg0[0] != 0) {
        OSCancelAlarm(arg0 + 8);
        arg0[0] = 0;
    }
}

extern "C" s32 AXRmtGetSamplesLeft(void);
extern "C" s32 AXRmtGetSamples(s32, void*, s32);
extern "C" void AXRmtAdvancePtr(s32);
extern "C" void* fn_800EE5E8(void*, void*);
#pragma push
#pragma scheduling on
#pragma use_lmw_stmw off
extern "C" void fn_800EEBA8(void* arg0, u64 unused1, u64 unused2) {
    extern u8 lbl_803238F8[];
    const char* message = (const char*)lbl_803238F8;
    u8 sampleBuffer[0x48];
    u8* state;
    u8* end;
    u8* channel;
    s32 i;

    if ((s8)lbl_8055DE40 == 0) {
        state = lbl_804127A8;
        state[0] = 0;
        channel = state + 0x38;
        end = state + 0x2B8;
        do { fn_800EE4F0(channel); channel += 0xA0; } while (channel < end);
        *(s32*)(state + 0x64) = 0;
        *(s32*)(state + 0x104) = 1;
        *(s32*)(state + 0x1A4) = 2;
        *(s32*)(state + 0x244) = 3;
        lbl_8055DE40 = 1;
    }
    state = lbl_804127A8;
    if (state + 8 != (u8*)arg0)
        Panic__Q26nw4hbm2dbFPCciPCce(message, 0x8D, message + 0x6C);
    if (AXRmtGetSamplesLeft() >= 0x28) {
        channel = state + 0x38;
        i = 0;
        do {
            if (state[0x39] != 0) {
                if (AXRmtGetSamples(i, sampleBuffer, 0x28) != 0x28)
                    Warning__Q26nw4hbm2dbFPCciPCce(message, 0x9D, message + 0xAC);
                fn_800EE5E8(channel, sampleBuffer);
            }
            ++i;
            channel += 0xA0;
            state += 0xA0;
        } while (i < 4);
        AXRmtAdvancePtr(0x28);
    }
}
#pragma pop
extern "C" void* __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(void* self, const void* data) {
    const u8* bytes = (const u8*)data;
    const u8* file = (const u8*)lbl_803239C0;
    volatile const u16* sizeField;
    u32 magic;
    u32 size;
    u32 valid;
    *(void**)self = 0;
    *(void**)((u8*)self + 4) = 0;
    if (data == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)file, 0x47, (const char*)(file + 0xB4));
    magic = *(const u32*)bytes;
    if (magic != 0x52534551) Panic__Q26nw4hbm2dbFPCciPCce((const char*)file, 0x26, (const char*)(file + 0x10));
    magic = *(const u32*)bytes;
    if (magic != 0x52534551) {
        valid = 0;
        goto check_valid;
    }
    sizeField = (volatile const u16*)(bytes + 6);
    size = *sizeField;
    if (size < 0x100) Panic__Q26nw4hbm2dbFPCciPCce((const char*)file, 0x2E, (const char*)(file + 0x5C));
    size = *sizeField;
    if (size < 0x100) {
        valid = 0;
        goto check_valid;
    }
    if (size > 0x100) Panic__Q26nw4hbm2dbFPCciPCce((const char*)file, 0x34, (const char*)(file + 0x5C));
    size = *sizeField;
    valid = (~(size & ~0x100u) - ((0x100u - size) >> 1)) >> 31;
check_valid:
    if (valid == 0) return self;
    *(void**)self = (void*)data;
    *(void**)((u8*)self + 4) = (void*)(*(const u32*)(bytes + 0x10) + (u32)bytes);
    if (*(const u32*)*(void**)((u8*)self + 4) != 0x44415441) Panic__Q26nw4hbm2dbFPCciPCce((const char*)file, 0x50, (const char*)(file + 0xE0));
    return self;
}

void *nw4hbm::snd::detail::SeqFileReader::GetBaseAddress() const {
    const u8 *self = (const u8 *)this;
    if (*(u32 *)self == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803239C0, 0x5E,
                                     (const char *)lbl_80323AF8);
    }
    u8 *file = *(u8 **)(self + 4);
    return (void *)(*(u32 *)(file + 8) + (u32)file);
}

extern "C" void OSCancelAlarm(void *);
extern "C" void fn_800EEE8C(void *arg0) {
    u8 *p = (u8 *)arg0;
    *(s32 *)(p + 4) = -1;
    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 0xC) = 0;
    *(u8 **)p = lbl_80323E98;
    *(u8 **)(p + 0x10) = lbl_80323E98 + 0x98;
    p[0x15] = 0;
    *(s32 *)(p + 0x100) = 0;
    *(s32 *)(p + 0x104) = 0;
}

extern "C" s32 fn_800EEEC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv
extern "C" void *__dt__Q46nw4hbm3snd6detail9SeqPlayerFv(void *self, s32 flag) {
    extern u8 lbl_80323B28[];
    extern u8 lbl_80323B3C[];
    struct Manager {
        virtual void method0();
        virtual void method1();
        virtual void RemoveTrack(void *);
    };
    register void *player = self;
    register int index;
    register u32 temp;
    if (player != 0) {
        u8 initialized = *((u8 *)player + 0x15);
        register void *vtable = lbl_80323E98;
        register void *vtable2 = (u8 *)vtable + 0x98;
        *(void **)player = vtable;
        *(void **)((u8 *)player + 0x10) = vtable2;
        if (initialized != 0) {
            temp = OSDisableInterrupts();
            if (*((u8 *)player + 0x17) != 0) {
                if (player == 0)
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324054, 0x233, (const char *)lbl_80324030);
                Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((void *)lbl_80412A6C, (u8 *)player + 0x100);
            }
            if (*((u8 *)player + 0x15) != 0) {
                index = (s32)player;
                if (index != 0)
                    index += 8;
                void *manager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
                UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(manager, (void *)index);
            }
            OSRestoreInterrupts(temp);
            register void *entry = player;
            index = 0;
            temp = 0;
            do {
                int valid = 0;
                if (index >= 0 && index < 16)
                    valid = 1;
                if (valid == 0)
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80323B28, 0x2FD, (const char *)lbl_80323B3C, index, 0, 16);
                void *track;
                if (index > 15)
                    track = (void *)temp;
                else
                    track = *(void **)((u8 *)entry + 0x9C);
                if (track != 0) {
                    Close__Q46nw4hbm3snd6detail8SeqTrackFv(track);
                    void *manager = *(void **)((u8 *)player + 0x98);
                    ((Manager *)manager)->RemoveTrack(*(void **)((u8 *)entry + 0x9C));
                    *(void **)((u8 *)entry + 0x9C) = (void *)temp;
                }
                ++index;
                entry = (u8 *)entry + 4;
            } while (index < 16);
            *((u8 *)player + 0x15) = 0;
        }
        if (flag > 0)
            fn_80128668(player);
    }
    return player;
}
#pragma dont_inline reset
#pragma pop

extern f32 lbl_80561068;
extern "C" void InitParam__Q46nw4hbm3snd6detail9SeqPlayerFiPQ46nw4hbm3snd6detail14NoteOnCallback(void *self, s32 arg, void *callback) {
    register f32 zeroValue = lbl_8056106C;
    register f32 baseValue = lbl_80561068;
    u8 *p = (u8 *)self;
    int i;
    p[0x16] = 0; p[0x17] = 0;
    p[0x18] = 0; p[0x19] = 0;
    p[0x14] = 0;
    *(f32 *)(p + 0x84) = baseValue;
    *(u16 *)(p + 0x88) = 0x1A0;
    *(f32 *)(p + 0x1C) = baseValue; *(f32 *)(p + 0x34) = baseValue;
    *(f32 *)(p + 0x20) = zeroValue; *(f32 *)(p + 0x24) = zeroValue;
    *(f32 *)(p + 0x2C) = zeroValue; *(f32 *)(p + 0x30) = zeroValue;
    *(f32 *)(p + 0x28) = baseValue;
    *(f32 *)(p + 0x38) = zeroValue; *(u32 *)(p + 0x3C) = 1;
    *(f32 *)(p + 0x44) = zeroValue; *(f32 *)(p + 0x40) = baseValue;
    *(f32 *)(p + 0x48) = zeroValue; *(f32 *)(p + 0x4C) = zeroValue;
    *(f32 *)(p + 0x50) = zeroValue; *(f32 *)(p + 0x64) = zeroValue;
    *(f32 *)(p + 0x74) = zeroValue; *(f32 *)(p + 0x68) = zeroValue;
    *(f32 *)(p + 0x78) = zeroValue; *(f32 *)(p + 0x6C) = zeroValue;
    *(f32 *)(p + 0x7C) = zeroValue; *(f32 *)(p + 0x70) = zeroValue;
    *(f32 *)(p + 0x80) = zeroValue;
    *(u32 *)(p + 0xFC) = 0;
    *(s32 *)(p + 0x8C) = arg;
    *(u16 *)(p + 0x92) = 0x78;
    p[0x90] = 0x7F; p[0x91] = 0x40;
    *(void **)(p + 0x94) = callback;
    for (i = 0; i < 16; ++i)
        *(s16 *)(p + 0xDC + i * 2) = -1;
    for (i = 0; i < 16; ++i)
        *(u32 *)(p + 0x9C + i * 4) = 0;
}

extern "C" void SetSeqData__Q46nw4hbm3snd6detail9SeqPlayerFPCvl(void *player, const void *seqData, s32 seqDataSize) {
    /* Set the sequence data buffer for this player's first track. Panics if the track is missing. */
    void *track = *(void **)((u8 *)player + 0x9C);

    if (track == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80323B28, 0xE0, (const char *)lbl_80323B94);
    }

    if (seqData != NULL) {
        fn_800F1080(track, seqData, seqDataSize);
    }

    *(u8 *)((u8 *)player + 0x16) = 1;
}

extern "C" int fn_800EF500(void* player) {
    /* Start this seq player if prepared (+0x16): insert its list node (+0x100)
     * at the front of the seq player list (lbl_80412A6C), snapshot the
     * EmissionManager tick (+0x6C32) to +0x14, and mark the player started
     * (+0x17). Returns 1 on success, 0 if not prepared. */
    if (*((unsigned char*)player + 0x16) == 0)
        return 0;
    register char* iterator = (char*)lbl_80412A6C + 4;
    if (player == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324054, 0x233, (const char*)lbl_80324030);
    char* slot = iterator;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(lbl_80412A6C, (void**)&slot, (char*)player + 0x100);
    *((unsigned char*)player + 0x14) = *((unsigned char*)Instance__15EmissionManagerFv() + 0x6C32);
    *((unsigned char*)player + 0x17) = 1;
    return 1;
}

extern "C" void Close__Q46nw4hbm3snd6detail8SeqTrackFv(void*);
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv
extern "C" void Stop__Q46nw4hbm3snd6detail9SeqPlayerFv(void* self) {
    extern u8 lbl_80323B28[], lbl_80323B3C[];
    struct Manager {
        virtual void unused0();
        virtual void unused1();
        virtual void RemoveTrack(void*);
    };
    void* player = self;
    s32 state;
    u32 level;
    if (*(u8*)((u8*)player + 0x15) == 0) return;
    level = OSDisableInterrupts();
    if (*(u8*)((u8*)player + 0x17) != 0) {
        if (player == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324054, 0x233, (const char*)lbl_80324030);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((void*)lbl_80412A6C, (u8*)player + 0x100);
    }
    if (*(u8*)((u8*)player + 0x15) != 0) {
        state = (s32)player;
        if (state != 0) state += 8;
        void* manager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
        UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(manager, (void*)state);
    }
    OSRestoreInterrupts(level);
    state = 0;
    u8* entry = (u8*)player;
    s32 zero = 0;
    s32 valid;
    void* seq;
    do {
        valid = 0;
        if (state >= 0 && state < 16) valid = 1;
        if (valid == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x2FD, (const char*)lbl_80323B3C, state, 0, 16);
        seq = state > 15 ? (void*)zero : *(void**)(entry + 0x9C);
        if (seq != 0) {
            Close__Q46nw4hbm3snd6detail8SeqTrackFv(seq);
            void* manager = *(void**)((u8*)player + 0x98);
            ((Manager*)manager)->RemoveTrack(*(void**)(entry + 0x9C));
            *(void**)(entry + 0x9C) = (void*)zero;
        }
        ++state;
        entry += 4;
    } while (state < 16);
    *(u8*)((u8*)player + 0x15) = 0;
}
#pragma pop
extern u8 lbl_80323B28[], lbl_80323C14[], lbl_80323BEC[];
extern u8 lbl_80324054[], lbl_80324030[];
#pragma push
#pragma small_data off
extern u8 lbl_80412A6C[];
#pragma pop
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void OSRestoreInterrupts(u32);
extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFb(void*, bool);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void*, void*);
extern "C" void* Instance__15EmissionManagerFv(void);
extern "C" void Pause__Q46nw4hbm3snd6detail9SeqPlayerFb(void* self, bool pause) {
    /* Pause or unpause the sequence player: store the pause flag and pause all 16 track slots. */
    u32 level;
    int i;
    level = OSDisableInterrupts();
    *(u8*)((u8*)self + 0x18) = pause;
    for (i = 0; i < 16; i++, self = (char*)self + 4) {
        void* track;
        if (i > 15) {
            track = 0;
        } else {
            track = *(void**)((char*)self + 0x9c);
        }
        if (track != 0) {
            PauseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFb(track, pause);
        }
    }
    OSRestoreInterrupts(level);
}

void nw4hbm::snd::detail::SeqPlayer::SetVolume(float volume) {
    float limit = lbl_8056106C;
    if (!(volume >= limit)) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x15d, (const char*)lbl_80323BEC);
    u32 level = OSDisableInterrupts();
    *(float*)((unsigned char*)this + 0x1c) = volume;
    OSRestoreInterrupts(level);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800EF804(void* self, float volume) {
    if (!(volume >= 0.0f)) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x164, (const char*)lbl_80323C14);
    unsigned int level = OSDisableInterrupts();
    *(float*)((unsigned char*)self + 0x34) = volume;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800EF878(void* arg0, f32 farg0) {
    u32 level = OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x20) = farg0;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800EF8B8(void* arg0, f32 farg0) {
    u32 level = OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x24) = farg0;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800EF8F8(void* arg0, f32 farg0) {
    u32 level = OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x2C) = farg0;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800EF938(void* arg0, f32 arg1) {
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x30) = arg1;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800EF978(void* arg0, f32 arg1) {
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x38) = arg1;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800EF9B8(void* arg0, f32 arg1) {
    u32 level;
    level = OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x40) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" f32 fn_800EF9F8(void* arg0) {
    return *(f32*)((u8*)arg0 + 0x40);
}

extern "C" void fn_800EFA00(void* arg0, f32 arg1) {
    u32 level;
    level = OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x44) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" f32 fn_800EFA40(void* arg0) {
    return *(f32*)((u8*)arg0 + 0x44);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf(void* self, s32 bus, f32 send) {
    /* Set this sequence player's FX send level for the given aux bus (0-2), with range check, under interrupt-disabled section. */
    s32 isValidBus = 0;
    if (bus >= 0 && bus < 3) isValidBus = 1;
    if (isValidBus == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1ad, (const char*)lbl_80323C3C, bus, 0, 3);
    u32 interruptLevel = OSDisableInterrupts();
    *(f32*)((u8*)self + 0x48 + bus * 4) = send;
    OSRestoreInterrupts(interruptLevel);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus(void* self, s32 bus) {
    s32 valid = 0;
    if (bus >= 0 && bus < 3) {
        valid = 1;
    }
    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1B4, (const char*)lbl_80323C3C, bus, 0, 3);
    }
    return *(f32*)((u8*)self + (bus * 4) + 0x48);
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" void fn_800EFB6C(void* this_, s32 arg1) {
    u32 level = OSDisableInterrupts();
    *(s32*)&((u8*)this_)[0x3C] = arg1;
    OSRestoreInterrupts(level);
}

#pragma push
#pragma small_data off
extern u8 lbl_80323B28[];
extern u8 lbl_80323C74[];
extern u8 lbl_80323C3C[];
extern u8 lbl_80323B28[];
#pragma pop
extern "C" s32 fn_800EFBAC(void* arg0) {
    return *(s32*)&((u8*)arg0)[0x3C];
}

#pragma push
#pragma small_data off
#pragma pop
/* Set an FX send value for an aux bus on the sequence player (index 0-3). */
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800EFBB4(
    void* seqPlayer, s32 auxBus, f32 send) {
    s32 bus = auxBus;
    f32 value = send;
    BOOL isValidBus = 0;

    if (bus >= 0 && bus < 4) {
        isValidBus = 1;
    }

    if (isValidBus == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1C6,
                                     (const char*)lbl_80323C74, bus, 0, 4);
    }

    {
        u32 interruptLevel = OSDisableInterrupts();
        ((f32*)((u8*)seqPlayer + 0x54))[bus] = value;
        OSRestoreInterrupts(interruptLevel);
    }
}
#pragma push
#pragma small_data off
#pragma pop
extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800EFC50(
    void* self, s32 bus) {
    /* nw4hbm::snd::detail::SeqPlayer::GetFxSend(AuxBus) const: return FX send level for bus 0..3
       (stored at self+0x54), panicking if out of range. Strings: lbl_80323B28="snd_SeqPlayer.cpp",
       lbl_80323C74="remoteIndex is out of bounds...". */
    s32 auxBusIndex = bus;
    BOOL isValidBus = 0;

    if (auxBusIndex >= 0 && auxBusIndex < 4) {
        isValidBus = 1;
    }

    if (isValidBus == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1CD,
                                     (const char*)lbl_80323C74, auxBusIndex, 0, 4);
    }

    return ((f32*)((u8*)self + 0x54))[auxBusIndex];
}

extern "C" s32 fn_800F1080(void*, const void*, s32);
extern u8 lbl_80323B94[];
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800EFCD8(void* self, s32 bus, f32 send) {
    /* Set this sequence player's FX send level for an aux bus, with interrupt-safe update. */
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1d3, (const char*)lbl_80323C74, bus, 0, 4);
    u32 level = OSDisableInterrupts();
    *(f32*)((u8*)self + 0x64 + bus * 4) = send;
    OSRestoreInterrupts(level);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800EFD74(const void* self, s32 bus) {
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1da, (const char*)lbl_80323C74, bus, 0, 4);
    return *(f32*)((const u8*)self + 0x64 + bus * 4);
}

/* Set the third FX send value for an aux bus on the sequence player (index 0-3). */
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800EFDFC(void* seqPlayer, s32 auxBus, f32 send) {
    s32 isValidBus = 0;
    if (auxBus >= 0 && auxBus < 4) isValidBus = 1;
    if (isValidBus == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1e0, (const char*)lbl_80323C74, auxBus, 0, 4);
    u32 interruptLevel = OSDisableInterrupts();
    *(f32*)((u8*)seqPlayer + 0x74 + auxBus * 4) = send;
    OSRestoreInterrupts(interruptLevel);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800EFE98(void* self, s32 bus) {
    /* nw4hbm::snd::detail::SeqPlayer::GetFxSend(AuxBus) const: return FX send level for bus 0..3
       (stored at self+0x74), panicking if out of range. Strings: lbl_80323B28="snd_SeqPlayer.cpp",
       lbl_80323C74="remoteIndex is out of bounds...". */
    s32 isValidBus = 0;
    if (bus >= 0 && bus < 4) {
        isValidBus = 1;
    }
    if (isValidBus == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1E7, (const char*)lbl_80323C74, bus, 0, 4);
    }
    return *(f32*)((u8*)self + (bus * 4) + 0x74);
}

extern u8 lbl_80323CBC[];
extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi(void *self, int priority) {
    int valid = 0;
    if (priority >= 0 && priority <= 0x7F) {
        valid = 1;
    }
    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80323B28,
                                     0x1EE,
                                     (const char *)lbl_80323CBC,
                                     priority, 0, 0x7F);
    }
    u32 level = OSDisableInterrupts();
    *((u8 *)self + 0x91) = priority;
    OSRestoreInterrupts(level);
}

extern "C" void InvalidateData__Q46nw4hbm3snd6detail9SeqPlayerFPCvPCv(void *player, const void *arg1, const void *arg2) {
    extern u8 lbl_80323B28[], lbl_80323B3C[];
    extern u8 lbl_80324054[], lbl_80324030[];
    extern u8 lbl_80412A6C[];
    extern void Close__Q46nw4hbm3snd6detail8SeqTrackFv(void *);
    extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
    extern void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
    extern void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *, void *);
    extern u32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(u32);
    struct Manager {
        virtual void unused0();
        virtual void unused1();
        virtual void RemoveTrack(void *);
    };
    u32 level = OSDisableInterrupts();
    if (*(u8*)((u8*)player + 0x15) == 0) {
        OSRestoreInterrupts(level);
        return;
    }
    if (*(u8*)((u8*)player + 0x17) != 0) {
        if (player == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324054, 0x233, (const char*)lbl_80324030);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((void*)lbl_80412A6C, (u8*)player + 0x100);
    }
    if (*(u8*)((u8*)player + 0x15) != 0) {
        void *callbackObj = player;
        if (player != 0) callbackObj = (u8*)player + 8;
        void *manager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
        UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(manager, callbackObj);
    }
    OSRestoreInterrupts(level);
    int i = 0;
    u8 *entry = (u8*)player;
    void *seq;
    do {
        if (i >= 0 && i < 16) {
            seq = *(void**)(entry + 0x9C);
            if (seq != 0) {
                void **trackInfo = (void**)((u8*)seq + 0x50);
                if (((const u8*)arg1 <= (u8*)trackInfo[0]) && ((u8*)trackInfo[0] < (u8*)arg2)) {
                    level = OSDisableInterrupts();
                    if (*(u8*)((u8*)player + 0x17) != 0) {
                        if (player == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324054, 0x233, (const char*)lbl_80324030);
                        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((void*)lbl_80412A6C, (u8*)player + 0x100);
                    }
                    if (*(u8*)((u8*)player + 0x15) != 0) {
                        void *callbackObj2 = player;
                        if (player != 0) callbackObj2 = (u8*)player + 8;
                        void *manager2 = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
                        UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(manager2, callbackObj2);
                    }
                    OSRestoreInterrupts(level);
                    Close__Q46nw4hbm3snd6detail8SeqTrackFv(seq);
                    void *manager = *(void**)((u8*)player + 0x98);
                    ((Manager*)manager)->RemoveTrack(*(void**)(entry + 0x9C));
                    *(void**)(entry + 0x9C) = 0;
                }
            }
        }
        i++;
        entry += 4;
    } while (i < 16);
    *(u8*)((u8*)player + 0x15) = 0;
}

extern "C" s32 fn_800F016C(s32 array, s32 index) {
    if (index > 0xF) {
        return 0;
    }
    return *(s32 *)(array + index * 4 + 0x9C);
}

extern "C" void UpdateChannelLength__Q46nw4hbm3snd6detail8SeqTrackFv(void *);
extern "C" bool ParseNextTick__Q46nw4hbm3snd6detail8SeqTrackFb(void *, bool);
extern "C" void Close__Q46nw4hbm3snd6detail8SeqTrackFv(void *);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
#pragma use_lmw_stmw off
extern "C" bool ParseNextTick__Q46nw4hbm3snd6detail9SeqPlayerFb(void *self, bool arg) {
    // Advance each of the player's 16 sequencer tracks by one tick. If a track
    // reports it is finished, close it and ask the manager to remove it from the
    // slot. Returns false if any track parse fails.
    extern u8 lbl_80323B28[], lbl_80323B3C[]; // "snd_SeqPlayer.cpp", trackNo bounds message
    struct Manager {
        virtual void method0();
        virtual void method1();
        virtual void RemoveTrack(void *);
    };
    register void *player = self;
    register void *track;
    register char *slotPtr = (char *)player;
    register int parseFailed = 0;
    register int trackIndex = 0;
    register int zero = 0;
    int trackIndexValid;

    do {
        if (trackIndex > 15)
            track = (void *)zero;
        else
            track = *(void **)(slotPtr + 0x9C);
        if (track != 0) {
            UpdateChannelLength__Q46nw4hbm3snd6detail8SeqTrackFv(track);
            if (!ParseNextTick__Q46nw4hbm3snd6detail8SeqTrackFb(track, arg)) {
                parseFailed = 1;
            } else {
                trackIndexValid = 0;
                if (trackIndex >= 0 && trackIndex < 16)
                    trackIndexValid = 1;
                if (trackIndexValid == 0)
                    Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80323B28, 0x2FD, (const char *)lbl_80323B3C, trackIndex, 0, 16);
                if (trackIndex > 15)
                    track = (void *)zero;
                else
                    track = *(void **)(slotPtr + 0x9C);
                if (track != 0) {
                    Close__Q46nw4hbm3snd6detail8SeqTrackFv(track);
                    void *manager = *(void **)((char *)player + 0x98);
                    ((Manager *)manager)->RemoveTrack(*(void **)(slotPtr + 0x9C));
                    *(void **)(slotPtr + 0x9C) = (void *)zero;
                }
            }
        }
        ++trackIndex;
        slotPtr += 4;
    } while (trackIndex < 16);
    return parseFailed == 0;
}
#pragma use_lmw_stmw reset

extern "C" u8 lbl_80323DDC[];
extern "C" u8 lbl_80324024[];
extern "C" u8 lbl_80324000[];
extern "C" u8 lbl_80323E64[];
extern "C" s16 lbl_80412A78[];
extern "C" void fn_800F0360(void*);
extern "C" void Stop__Q46nw4hbm3snd6detail9SeqPlayerFv(void*);
/* Return pointer to a sequence player variable: local vars 0-15, global vars 16-31, else NULL. */
extern "C" s16* GetVariablePtr__Q46nw4hbm3snd6detail9SeqPlayerFi(void* this_, s32 varNo) {
    s32 index = varNo;
    s32 valid = 0;

    if (index >= 0 && index <= 0x20) {
        valid = 1;
    }

    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x380,
                                     (const char*)lbl_80323DDC, index, 0, 0x20);
    }

    if (index < 0x10) {
        return (s16*)((u8*)this_ + 0xDC + index * 2);
    }
    if (index < 0x20) {
        return &lbl_80412A78[index - 0x10];
    }
    return NULL;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv
extern "C" void fn_800F0360(void *self) {
    struct Manager {
        virtual void unused0();
        virtual void unused1();
        virtual void RemoveTrack(void *);
    };
    register void *player = self;
    register const char *file = (const char *)lbl_80323B28;
    register s32 i;
    if (*(u8 *)((u8 *)player + 0x15) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x398, file + 0x2F0);
    if (*(u8 *)((u8 *)player + 0x17) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x399, file + 0x314);
    if (*(u8 *)((u8 *)player + 0x15) != 0 && *(u8 *)((u8 *)player + 0x17) != 0) {
        if (*(u8 *)((u8 *)player + 0x18) == 0 && *(u8 *)((u8 *)player + 0x19) == 0 &&
            (*(u8 *)((u8 *)player + 0x14) != 0 || *((u8 *)Instance__15EmissionManagerFv() + 0x6C32) == 0)) {
            register s32 ticks = 0;
            while (*(u16 *)((u8 *)player + 0x88) >= 0x1A0) {
                ticks++;
                *(u16 *)((u8 *)player + 0x88) -= 0x1A0;
            }
            *(u16 *)((u8 *)player + 0x88) += (s32)((f32)*(u16 *)((u8 *)player + 0x92) * *(f32 *)((u8 *)player + 0x84));
            while (ticks > 0) {
                if (ParseNextTick__Q46nw4hbm3snd6detail9SeqPlayerFb(player, true)) {
                    register s32 state;
                    register u32 temp = OSDisableInterrupts();
                    if (*(u8 *)((u8 *)player + 0x17) != 0) {
                        if (player == 0)
                            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324054, 0x233, (const char *)lbl_80324030);
                        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((void *)lbl_80412A6C, (u8 *)player + 0x100);
                    }
                    if (*(u8 *)((u8 *)player + 0x15) != 0) {
                        state = (s32)player;
                        if (player != 0) state += 8;
                        void *manager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
                        UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(manager, (void *)state);
                    }
                    OSRestoreInterrupts(temp);
                    register u8 *entry = (u8 *)player;
                    state = 0;
                    temp = 0;
                    s32 valid;
                    void *seq;
                    do {
                        valid = 0;
                        if (state >= 0 && state < 16) valid = 1;
                        if (valid == 0)
                            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x2FD, file + 0x14, state, 0, 16);
                        seq = state > 15 ? (void *)temp : *(void **)(entry + 0x9C);
                        if (seq != 0) {
                            Close__Q46nw4hbm3snd6detail8SeqTrackFv(seq);
                            void *manager = *(void **)((u8 *)player + 0x98);
                            ((Manager *)manager)->RemoveTrack(*(void **)(entry + 0x9C));
                            *(void **)(entry + 0x9C) = (void *)temp;
                        }
                        ++state;
                        entry += 4;
                    } while (state < 16);
                    *(u8 *)((u8 *)player + 0x15) = 0;
                    break;
                }
                ticks--;
                *(s32 *)((u8 *)player + 0xFC) += 1;
            }
        }
        i = 0;
        do {
            void *seq = i > 15 ? (void *)0 : *(void **)((u8 *)player + 0x9C);
            if (seq != 0) UpdateChannelParam__Q46nw4hbm3snd6detail8SeqTrackFv(seq);
            i++;
            player = (u8 *)player + 4;
        } while (i < 16);
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv(void) {
    void *pHead;
    void *pList = &lbl_80412A6C[4];
    void *pPlayer;
    for (pHead = *(void **)pList; pHead != pList;) {
        pPlayer = pHead;
        pHead = *(void **)pHead;
        if (pPlayer == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324024, 0x23D,
                                         (const char *)lbl_80324000);
        }
        fn_800F0360((u8 *)pPlayer - 0x100);
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv(void) {
    class PlayerVTable {
    public:
        virtual void Dummy0();
        virtual void Dummy1();
        virtual void Stop();
    };
    struct Iter { void *p; };
    struct Iter it;
    void *pList = &lbl_80412A6C[4];
    void *pPlayer;
    for (it.p = *(void **)pList; it.p != pList;) {
        pPlayer = it.p;
        it.p = *(void **)pPlayer;
        if (pPlayer == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324024, 0x23D,
                                         (const char *)lbl_80324000);
        }
        ((PlayerVTable *)((u8 *)pPlayer - 0x100))->Stop();
    }
    if (*(s32 *)&lbl_80412A6C[0] != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80323B28, 0x3D7,
                                     (const char *)lbl_80323E64);
    }
}
#pragma pop
extern "C" void fn_800F0728(void *this_, s32 a1, s32 a2) {
    class Dispatch {
    public:
        virtual void f0();
        virtual void invoke(void *, s32, s32);
    };
    Dispatch *object = *(Dispatch **)((u8 *)this_ + 0x94);
    object->invoke(this_, a1, a2);
}

extern "C" void fn_800F0750(void) {
          return;
  }

  extern "C" s16* GetVariablePtr__Q46nw4hbm3snd6detail8SeqTrackFi(void* this_, s32 index);

  extern u8 lbl_803231D8[];
extern "C" s32 fn_800F283C(void *, u32, s32, s32 *);
extern "C" s32 fn_800F2824(void *, s32, void *);
extern "C" s32 fn_800F282C(void *, s32, s32, void *);
extern "C" void *memcpy(void *, const void *, u32);
