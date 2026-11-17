// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef signed int s32;
typedef float f32;


extern "C" char lbl_803228E8[];
extern "C" char lbl_803228F8[];
extern float lbl_80560FC8;
extern float lbl_80560FCC;
extern float lbl_80560FD0;

// nw4hbm::ut::LinkListNode: a link's next/prev, the first two words of anything put
// into a LinkListImpl (a Channel is its own node).
struct LinkListNode {
    void *next;    // +0x00
    void *prev;    // +0x04
};

// nw4hbm::ut::detail::LinkListImpl: doubly-linked list with the count in front of the
// sentinel node the links circle around when empty (head.next == head.prev == &head).
struct LinkListImpl {
    s32 size;          // +0x00
    LinkListNode head; // +0x04
};

// The global nw4hbm::snd::detail::ChannelManager singleton at lbl_80412778. Every
// Channel sits in one of its two lists: a new or stopped one in `idle`, a started one
// in `active`, which the per-frame update walks. The first Channel built it
// (lbl_8055DE28 says so) and queued its own destruction with __register_global_object.
struct ChannelManagerLayout {
    LinkListImpl idle;    // +0x00: channels not playing
    LinkListImpl active;  // +0x0C: channels being updated
};

namespace nw4hbm {
namespace snd {
namespace detail {
class Channel {
public:
    Channel();
    void Stop();
};
}
}
}

extern "C" void fn_800EB3AC(void *);
extern "C" void fn_800EC890(void *);
extern float lbl_80560FC0;
extern "C" unsigned char lbl_8055DE28;
extern "C" char lbl_80412778[];
extern "C" char lbl_8040EC78[];
extern "C" char lbl_80322B0C[];
extern "C" char lbl_80322AE4[];
extern "C" char lbl_80322AD8[];
extern "C" char lbl_80322AB4[];
extern "C" void __register_global_object(void *, void *, void *, void *, void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...) __attribute__((noreturn));
extern "C" int __dt__Q46nw4hbm3snd6detail14ChannelManagerFv(int, int);
extern "C" int SetPriority__Q46nw4hbm3snd6detail7AxVoiceFi(void *, int);
extern "C" int fn_800EC8B4(void *);
extern "C" int fn_800EB41C(void *);
extern "C" int Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(void *, const void *);
extern "C" int fn_800E519C(void *);
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, int);
extern "C" void *fn_80128668(void *);

/* Meaningful names for the globals the Channel constructor touches. */
#define sDefaultChannelVolume lbl_80560FC0
#define sChannelManagerInitialized lbl_8055DE28
#define sChannelManager lbl_80412778
#define sChannelManagerDtorRecord lbl_8040EC78
#define sInstanceManagerFile lbl_80322B0C
#define sNullObjMsg lbl_80322AE4
#define sLinkListFile lbl_80322AD8
#define sNullPtrMsg lbl_80322AB4

/* nw4hbm::snd::detail::Channel::Channel(): construct a new sound channel.
 * Zero its fields and subobjects and set the default volume, lazily build the
 * global ChannelManager singleton (queueing its destruction) on first use,
 * then insert this channel into the manager's idle list. */
extern "C" void *__ct__Q46nw4hbm3snd6detail7ChannelFv(void *arg0) {
    register void *channel asm("r29") = arg0;
    int zero = 0;
    ((int*)channel)[0] = zero;
    ((int*)channel)[1] = zero;
    fn_800EB3AC((char *)channel + 0x8);
    fn_800EC890((char *)channel + 0x20);
    float initialVolume = sDefaultChannelVolume;
    ((int*)channel)[12] = zero;
    ((float*)channel)[13] = initialVolume;
    ((unsigned char*)channel)[0x39] = zero;
    ((unsigned char*)channel)[0x3A] = zero;
    ((unsigned char*)channel)[0x3B] = zero;
    ((unsigned char*)channel)[0xC4] = zero;
    ((unsigned char*)channel)[0xC5] = zero;
    ((unsigned short*)channel)[0x63] = zero;
    ((unsigned short*)channel)[0x64] = zero;
    ((int*)channel)[56] = zero;
    if ((signed char)sChannelManagerInitialized == 0) {
        ChannelManagerLayout *globalManager = (ChannelManagerLayout *)sChannelManager;
        *(volatile int *)sChannelManager = zero;
        *(void * volatile *)((char *)globalManager + 0x4) = 0;
        void *idleSentinel = &globalManager->idle.head;
        void *activeSentinel = &globalManager->active.head;
        *(void * volatile *)((char *)globalManager + 0x8) = 0;
        *(void * volatile *)((char *)globalManager + 0x10) = 0;
        *(void * volatile *)((char *)globalManager + 0x14) = 0;
        *(void **)((char *)globalManager + 0x4) = idleSentinel;
        *(void **)((char *)globalManager + 0x8) = idleSentinel;
        *(int *)((char *)globalManager + 0xC) = zero;
        *(void **)((char *)globalManager + 0x10) = activeSentinel;
        *(void **)((char *)globalManager + 0x14) = activeSentinel;
        ((void (*)(void *, void *, void *, void *, void *))__register_global_object)(
            globalManager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv,
            sChannelManagerDtorRecord, activeSentinel, idleSentinel);
        sChannelManagerInitialized = 1;
    }
    void *idleSentinel;
    char *manager = sChannelManager;
    if (channel == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(sInstanceManagerFile, 0x43, sNullObjMsg);
    idleSentinel = manager + 4;
    if (channel == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(sLinkListFile, 0x233, sNullPtrMsg);
    void *insertPos = idleSentinel;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
        manager, &insertPos, channel);
    return channel;
}

// nw4hbm::snd::detail::ChannelManager::~ChannelManager(): destroy the `active`
// and `idle` LinkListImpl members (at +0xC and +0x0), then free the manager
// itself with the sound allocator when deleteFlag > 0.
extern "C" int __dt__Q46nw4hbm3snd6detail14ChannelManagerFv(int manager, int deleteFlag) {
    if (manager != 0) {
        if (manager != 0) {
            if (manager + 0xC != 0) {
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv((void *)(manager + 12), 0);
            }
            if (manager != 0) {
                __dt__Q46nw4hbm2ut6detail12LinkListImplFv((void *)manager, 0);
            }
        }
        if (deleteFlag > 0) {
            fn_80128668((void *)manager);
        }
    }
    return manager;
}

extern "C" void __register_global_object(void*, void*, void*, void*, void*, void*);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...) __attribute__((noreturn));
extern "C" unsigned char lbl_8055DE28;
extern "C" char lbl_80412778[];
extern "C" char lbl_8040EC78[];
extern "C" char lbl_80322A78[];
extern "C" char lbl_80322AA0[];
extern "C" char lbl_80322AB4[];
extern "C" char lbl_80322AD8[];
extern "C" int __dt__Q46nw4hbm3snd6detail7ChannelFv(void *channel, int deleteFlag) {
    // nw4hbm::snd::detail::Channel::~Channel() (the deleting destructor): take the
    // channel out of the global ChannelManager's idle list - building that singleton
    // and queueing its own destruction with __register_global_object the first time
    // one is used - and free the channel itself when the flag says "deleting".
    if (channel != 0) {
        if ((signed char)lbl_8055DE28 == 0) {  // ChannelManager not built yet
            ChannelManagerLayout *manager = (ChannelManagerLayout *)lbl_80412778;
            *(volatile void **)&manager->idle.head.next = 0;
            char *activeSentinel = (char *)manager + 0x10;
            char *idleSentinel = (char *)manager + 4;
            *(volatile void **)&manager->idle.head.prev = 0;
            *(volatile void **)&manager->active.head.next = 0;
            *(volatile void **)&manager->active.head.prev = 0;
            *(volatile int *)lbl_80412778 = 0;  // manager->idle.size
            manager->idle.head.next = idleSentinel;  // an empty list circles itself
            manager->idle.head.prev = idleSentinel;
            manager->active.size = 0;
            manager->active.head.next = activeSentinel;
            manager->active.head.prev = activeSentinel;
            ((void (*)(void *, void *, void *))__register_global_object)(manager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv, lbl_8040EC78);
            lbl_8055DE28 = 1;
        }
        ChannelManagerLayout *list = (ChannelManagerLayout *)lbl_80412778;
        if (channel == 0)  // NW4HBM_DB_ASSERT(obj, "InstanceManager.h", 0x54)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AA0, 0x54, lbl_80322A78);
        if (channel == 0)  // NW4HBM_DB_ASSERT(p, "LinkList.h", 0x233)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8, 0x233, lbl_80322AB4);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(list, channel);
        if (deleteFlag > 0)
            fn_80128668(channel);
    }
    return (int)channel;
}

extern float lbl_80560FC0;
extern float lbl_80560FC4;
extern "C" void fn_800EB3E4(void *);
extern void fn_800EC890(void *);
/* Initialize a nw4hbm sound Channel's parameters: install the completion callback and its user argument, clear counters/flags, and set the pitch, volume and mix floats to their neutral defaults. */
extern "C" void InitParam__Q46nw4hbm3snd6detail7ChannelFPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(void *channel, void (*callback)(void *, int, unsigned long), unsigned long callbackArg) {
    int zero = 0, one = 1, sixty = 0x3C;
    unsigned char ff = 0xFF;
    float zeroF = 0.0f, oneF = 1.0f;
    *(int *)((char *)channel + 0xE4) = zero;
    *(void (**)(void *, int, unsigned long))((char *)channel + 0xD8) = callback;
    *(unsigned long *)((char *)channel + 0xDC) = callbackArg;
    *((unsigned char *)channel + 0x39) = 0;
    *((unsigned char *)channel + 0x3C) = one;
    *(int *)((char *)channel + 0xD4) = zero;
    *(int *)((char *)channel + 0xCC) = sixty;
    *(int *)((char *)channel + 0xD0) = sixty;
    *(float *)((char *)channel + 0xB4) = oneF;
    *(float *)((char *)channel + 0xB8) = zeroF;
    *(float *)((char *)channel + 0xBC) = zeroF;
    *(float *)((char *)channel + 0xC0) = oneF;
    *(float *)((char *)channel + 0x40) = oneF;
    *(float *)((char *)channel + 0xA4) = zeroF;
    *(float *)((char *)channel + 0x44) = oneF;
    *(float *)((char *)channel + 0x48) = zeroF;
    *(float *)((char *)channel + 0x4C) = zeroF;
    *(float *)((char *)channel + 0x50) = zeroF;
    *(float *)((char *)channel + 0x54) = zeroF;
    *(float *)((char *)channel + 0x58) = zeroF;
    *(int *)((char *)channel + 0x5C) = one;
    *(float *)((char *)channel + 0x60) = oneF;
    *(float *)((char *)channel + 0x64) = zeroF;
    *(float *)((char *)channel + 0x68) = zeroF;
    *(float *)((char *)channel + 0x6C) = zeroF;
    *(float *)((char *)channel + 0x70) = zeroF;
    *(float *)((char *)channel + 0x74) = oneF;
    *(float *)((char *)channel + 0x84) = zeroF;
    *(float *)((char *)channel + 0x94) = zeroF;
    *(float *)((char *)channel + 0x78) = oneF;
    *(float *)((char *)channel + 0x88) = zeroF;
    *(float *)((char *)channel + 0x98) = zeroF;
    *(float *)((char *)channel + 0x7C) = oneF;
    *(float *)((char *)channel + 0x8C) = zeroF;
    *(float *)((char *)channel + 0x9C) = zeroF;
    *(float *)((char *)channel + 0x80) = oneF;
    *(float *)((char *)channel + 0x90) = zeroF;
    *(float *)((char *)channel + 0xA0) = zeroF;
    *((unsigned char *)channel + 0xC4) = ff;
    *((unsigned char *)channel + 0xC5) = ff;
    *(unsigned short *)((char *)channel + 0xC6) = zero;
    *(unsigned short *)((char *)channel + 0xC8) = zero;
    *(float *)((char *)channel + 0xA8) = zeroF;
    *(int *)((char *)channel + 0xB0) = zero;
    *(int *)((char *)channel + 0xAC) = zero;
    fn_800EB3E4((char *)channel + 8);
    fn_800EC890((char *)channel + 0x20);
    *((unsigned char *)channel + 0x38) = 0;
}

extern "C" f32 CalcPitchRatio__Q46nw4hbm3snd6detail4UtilFi(s32);
extern "C" f32 CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(f32);
extern "C" f32 GetValue__Q46nw4hbm3snd6detail3LfoCFv(void *);
extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif(s32, s32, f32);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E5718(s32, s32, f32);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E58CC(s32, s32, f32);
extern "C" void SetRemoteSend__Q46nw4hbm3snd6detail7AxVoiceFif(s32, s32, f32);
extern "C" void SetVeVolume__Q46nw4hbm3snd6detail7AxVoiceFff(s32, f32, f32);
extern "C" void Stop__Q46nw4hbm3snd6detail7ChannelFv(void *);
extern "C" void Update__Q44nw4r3snd6detail3LfoFi(void *, int);
extern "C" void Update__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void fn_800E5338(s32, f32);
extern "C" void fn_800E5444(s32, f32);
extern "C" void fn_800E5464(s32, f32);
extern "C" void fn_800E54A8(s32, f32);
extern "C" void fn_800E54EC(s32, f32);
extern "C" void fn_800E550C(s32, f32);
extern "C" void fn_800E5550(s32, f32);
extern "C" void fn_800E5594(s32, s32);
extern "C" void fn_800E55B4(s32, f32);
extern "C" void fn_800E56D0(s32, f32);
extern "C" f32 fn_800EB430(void *);
extern f32 lbl_80560FC0;
extern f32 lbl_80560FC4;
extern f32 lbl_80560FC8;
extern f32 lbl_80560FCC;
extern f32 lbl_80560FD0;
#pragma use_lmw_stmw on
#pragma push
#pragma opt_propagation off
#pragma opt_deadstores off
#pragma opt_common_subs off
#pragma opt_lifetimes off
extern "C" void Update__Q46nw4hbm3snd6detail7ChannelFb(void *arg0, s32 arg1) {
    f32 temp_f31;
    f32 var_f30;
    f32 temp_f29;
    f32 var_f28;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    f32 var_f19;
    f32 temp_f1, temp_f1_2, temp_f1_3, temp_f2;
    volatile f32 remoteOut[3], remoteVolume[4], remoteSend[4], remoteFx[4];
    volatile f32 *var_r28;
    volatile f32 *var_r28_2;
    volatile f32 *var_r29_2;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r31;
    s32 temp_r3_3;
    s32 temp_r4_2;
    s32 var_r27;
    s32 var_r29;
    s32 var_r31;
    unsigned short temp_r3;
    unsigned short temp_r3_2;
    unsigned short temp_r4;
    unsigned char temp_r5;
    unsigned char var_r0;

    var_r31 = arg1;
    if ((s32) *(unsigned char *)((char *)arg0 + 0x3A) != 0) {
        if ((s32) *(unsigned char *)((char *)arg0 + 0x39) != 0) {
            var_r31 = 0;
        }
        temp_f22 = GetValue__Q46nw4hbm3snd6detail3LfoCFv(((char *)arg0 + 0x20));
        temp_r3 = *(unsigned short *)((char *)arg0 + 0xC8);
        if (temp_r3 < (unsigned short) *(unsigned short *)((char *)arg0 + 0xC6)) {
            *(unsigned short *)((char *)arg0 + 0xC8) = (unsigned short) (temp_r3 + 1);
        }
        temp_f31 = lbl_80560FC4;
        temp_f31 *= *(f32 *)((char *)arg0 + 0xB4);
        temp_f31 *= *(f32 *)((char *)arg0 + 0x40);
        temp_r4 = *(unsigned short *)((char *)arg0 + 0xC6);
        temp_r3_2 = *(unsigned short *)((char *)arg0 + 0xC8);
        if (temp_r3_2 >= temp_r4) {
            var_r0 = *(unsigned char *)((char *)arg0 + 0xC5);
        } else {
            temp_r5 = *(unsigned char *)((char *)arg0 + 0xC4);
            var_r0 = temp_r5 + ((s32) (temp_r3_2 * (*(unsigned char *)((char *)arg0 + 0xC5) - temp_r5)) / (s32) temp_r4);
        }
        temp_f1 = (f32) var_r0;
        var_f30 = lbl_80560FC4;
        temp_f31 *= temp_f1 / lbl_80560FC8;
        var_f30 *= fn_800EB430(((char *)arg0 + 8));
        if ((unsigned char) *(unsigned char *)((char *)arg0 + 0x38) == 1) {
            var_f30 *= CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(lbl_80560FCC * temp_f22);
        }
        if (((s32) *(s32 *)((char *)((char *)arg0 + 8)) == 3) && (lbl_80560FC0 == (temp_f31 * var_f30))) {
            Stop__Q46nw4hbm3snd6detail7ChannelFv(arg0);
            return;
        }
        var_f19 = lbl_80560FC0;
        temp_f1_2 = *(f32 *)((char *)arg0 + 0xA8);
        temp_f20 = lbl_80560FC0;
        temp_f20 += (f32) (*(s32 *)((char *)arg0 + 0xCC) - *(s32 *)((char *)arg0 + 0xD0));
        if (var_f19 == temp_f1_2) {

        } else {
            temp_r0 = *(s32 *)((char *)arg0 + 0xAC);
            temp_r3_3 = *(s32 *)((char *)arg0 + 0xB0);
            if (temp_r0 >= temp_r3_3) {

            } else {
                var_f19 = temp_f1_2 * (f32) (temp_r3_3 - temp_r0);
                if (temp_r3_3 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_803228E8, 0x1B3, lbl_803228F8);
                }
                var_f19 /= (f32) *(s32 *)((char *)arg0 + 0xB0);
            }
        }
        temp_f20 += var_f19;
        temp_f20 += *(f32 *)((char *)arg0 + 0xA4);
        if ((s32) *(unsigned char *)((char *)arg0 + 0x38) == 0) {
            temp_f20 += temp_f22;
        }
        temp_f2 = *(f32 *)((char *)arg0 + 0xC0);
        temp_f1_3 = *(f32 *)((char *)arg0 + 0x44);
        var_f19 = lbl_80560FC4;
        var_f19 *= temp_f2;
        var_f19 *= temp_f1_3;
        temp_f29 = CalcPitchRatio__Q46nw4hbm3snd6detail4UtilFi((s32) (lbl_80560FD0 * temp_f20)) * var_f19;
        var_f28 = lbl_80560FC0;
        var_f28 += *(f32 *)((char *)arg0 + 0xB8);
        var_f28 += *(f32 *)((char *)arg0 + 0x48);
        if ((unsigned char) *(unsigned char *)((char *)arg0 + 0x38) == 2) {
            var_f28 += temp_f22;
        }
        remoteVolume[0] = lbl_80560FC4;
        temp_f27 = lbl_80560FC0;
        temp_f27 += *(f32 *)((char *)arg0 + 0xBC);
        temp_f27 += *(f32 *)((char *)arg0 + 0x4C);
        remoteOut[0] = lbl_80560FC0;
        remoteOut[1] = lbl_80560FC0;
        temp_f26 = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x50);
        remoteOut[2] = lbl_80560FC0;
        temp_f25 = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x54);
        temp_f24 = lbl_80560FC4 + *(f32 *)((char *)arg0 + 0x58);
        remoteSend[0] = lbl_80560FC0;
        temp_f23 = lbl_80560FC4 * *(f32 *)((char *)arg0 + 0x60);
        remoteFx[0] = lbl_80560FC0;
        temp_f22 = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x64);
        remoteOut[0] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x68);
        remoteOut[1] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x6C);
        remoteOut[2] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x70);
        remoteVolume[0] = lbl_80560FC4 * *(f32 *)((char *)arg0 + 0x74);
        remoteSend[0] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x84);
        remoteFx[0] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x94);
        remoteVolume[1] = lbl_80560FC4 * *(f32 *)((char *)arg0 + 0x78);
        remoteSend[1] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x88);
        remoteFx[1] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x98);
        remoteVolume[2] = lbl_80560FC4 * *(f32 *)((char *)arg0 + 0x7C);
        remoteSend[2] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x8C);
        remoteFx[2] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x9C);
        remoteVolume[3] = lbl_80560FC4 * *(f32 *)((char *)arg0 + 0x80);
        remoteSend[3] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0x90);
        remoteFx[3] = lbl_80560FC0 + *(f32 *)((char *)arg0 + 0xA0);
        if (var_r31 != 0) {
            if ((s32) *(unsigned char *)((char *)arg0 + 0x3C) != 0) {
                temp_r4_2 = *(s32 *)((char *)arg0 + 0xB0);
                temp_r0_2 = *(s32 *)((char *)arg0 + 0xAC) + 3;
                *(s32 *)((char *)arg0 + 0xAC) = temp_r0_2;
                if (temp_r0_2 > temp_r4_2) {
                    *(s32 *)((char *)arg0 + 0xAC) = temp_r4_2;
                }
            }
            Update__Q44nw4r3snd6detail3LfoFi(((char *)arg0 + 0x20), 3);
            Update__Q46nw4hbm3snd6detail12EnvGeneratorFi(((char *)arg0 + 8), 3);
        }
        temp_f21 = GetValue__Q46nw4hbm3snd6detail3LfoCFv(((char *)arg0 + 0x20));
        var_f19 = lbl_80560FC4;
        var_f19 = var_f19 * fn_800EB430(((char *)arg0 + 8));
        if ((unsigned char) *(unsigned char *)((char *)arg0 + 0x38) == 1) {
            var_f19 *= CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(lbl_80560FCC * temp_f21);
        }
        temp_r31 = OSDisableInterrupts();
        temp_r0_3 = *(s32 *)((char *)arg0 + 0xE0);
        if (temp_r0_3 != 0) {
            fn_800E5338(temp_r0_3, temp_f31);
            SetVeVolume__Q46nw4hbm3snd6detail7AxVoiceFff(*(s32 *)((char *)arg0 + 0xE0), var_f19, var_f30);
            fn_800E5444(*(s32 *)((char *)arg0 + 0xE0), temp_f29);
            fn_800E5464(*(s32 *)((char *)arg0 + 0xE0), var_f28);
            fn_800E54A8(*(s32 *)((char *)arg0 + 0xE0), temp_f27);
            fn_800E54EC(*(s32 *)((char *)arg0 + 0xE0), temp_f26);
            fn_800E550C(*(s32 *)((char *)arg0 + 0xE0), temp_f25);
            fn_800E5550(*(s32 *)((char *)arg0 + 0xE0), temp_f24);
            fn_800E5594(*(s32 *)((char *)arg0 + 0xE0), *(s32 *)((char *)arg0 + 0x5C));
            fn_800E55B4(*(s32 *)((char *)arg0 + 0xE0), temp_f23);
            fn_800E56D0(*(s32 *)((char *)arg0 + 0xE0), temp_f22);
            var_r28 = &remoteOut[0];
            var_r29 = 0;
            do {
                SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E5718(*(s32 *)((char *)arg0 + 0xE0), var_r29, *var_r28);
                var_r29 += 1;
                var_r28 += 1;
            } while (var_r29 < 3);
            var_r29_2 = &remoteVolume[0];
            var_r28_2 = &remoteSend[0];
            var_r27 = 0;
            do {
                SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif(*(s32 *)((char *)arg0 + 0xE0), var_r27, *var_r29_2);
                SetRemoteSend__Q46nw4hbm3snd6detail7AxVoiceFif(*(s32 *)((char *)arg0 + 0xE0), var_r27, *var_r28_2);
                SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E58CC(*(s32 *)((char *)arg0 + 0xE0), var_r27, *var_r28_2);
                var_r27 += 1;
                var_r28_2 += 1;
                var_r29_2 += 1;
            } while (var_r27 < 4);
        }
        OSRestoreInterrupts(temp_r31);
    }
}
#pragma pop
extern "C" void Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(void *channel, const void *waveData, long length) {
    /* Start playback of the given wave data on this channel. */
    *(long *)((char *)channel + 0xD4) = length;
    fn_800EC8B4((char *)channel + 0x20);
    fn_800EB41C((char *)channel + 8);
    *(int *)((char *)channel + 0xAC) = 0;
    Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(*(void **)((char *)channel + 0xE0), waveData);
    fn_800E519C(*(void **)((char *)channel + 0xE0));
    *(signed char *)((char *)channel + 0x3A) = 1;
}

extern "C" void Release__Q46nw4hbm3snd6detail7ChannelFv(void *channel) {
    /* Move a non-released channel to the released state (lowering its voice
     * priority) and clear its active flag. */
    struct ChannelState {
        unsigned char pad[8];
        int state;            /* +0x08 */
        unsigned char pad0C[0x39 - 0x0C];
        unsigned char active; /* +0x39 */
        unsigned char pad3A[0xE0 - 0x3A];
        void *voice;          /* +0xE0 */
    };
    ChannelState *ch = (ChannelState *)channel;

    if (ch->state != 3) {
        if (ch->voice != (void *)0)
            SetPriority__Q46nw4hbm3snd6detail7AxVoiceFi(ch->voice, 1);
        ch->state = 3;
    }
    ch->active = 0;
}

extern "C" char lbl_803228E8[];
extern "C" char lbl_80322924[];
extern "C" char lbl_80322A3C[];
extern "C" char lbl_80322A64[];
extern "C" void Stop__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" void Stop__Q46nw4hbm3snd6detail7ChannelFv(void *arg0) {
    int enabled;
    void *iterator;
    char *manager;
    void *voice, *callback;
    void *head, *tail;
    void *channel = arg0;
    enabled = OSDisableInterrupts();
    voice = *(void **)((char *)channel + 0xE0);
    if (!voice) { OSRestoreInterrupts(enabled); return; }
    Stop__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
    Free__Q46nw4hbm3snd6detail7AxVoiceFv(*(void **)((char *)channel + 0xE0));

    int active = *(unsigned char *)((char *)channel + 0x3B);
    int zero = 0;
    *(int *)((char *)channel + 0xE0) = zero;
    *(unsigned char *)((char *)channel + 0x39) = zero;
    *(unsigned char *)((char *)channel + 0x3A) = zero;
    if (active) {
        *(unsigned char *)((char *)channel + 0x3B) = zero;
        if ((signed char)lbl_8055DE28 == 0) {
            manager = lbl_80412778;
            *(volatile int *)manager = zero;
            head = manager + 4;
            tail = manager + 0x10;
            *(void * volatile *)(manager + 4) = 0;
            *(void * volatile *)(manager + 8) = 0;
            *(void * volatile *)(manager + 0x10) = 0;
            *(void * volatile *)(manager + 0x14) = 0;
            *(void * volatile *)(manager + 4) = head;
            *(void * volatile *)(manager + 8) = head;
            *(volatile int *)(manager + 0xC) = zero;
            *(void * volatile *)(manager + 0x10) = tail;
            *(void * volatile *)(manager + 0x14) = tail;
            __register_global_object(manager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv, lbl_8040EC78, tail, (void *)zero, head);
            lbl_8055DE28 = 1;
        }
        manager = lbl_80412778;
        if (!channel) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322A64,0x77,lbl_80322A3C);
        if (*(int *)(manager + 0xC)) {
            if (!channel) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8,0x233,lbl_80322AB4);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(manager+0xC,channel);
            if (!channel) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8,0x233,lbl_80322AB4);
            iterator = manager + 4;
            Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(manager,&iterator,channel);
        }
    }
    callback = *(void **)((char *)channel+0xD8);
    if (callback) ((void (*)(void *,int,unsigned long))callback)(channel,0,*(unsigned long *)((char *)channel+0xDC));
    OSRestoreInterrupts(enabled);
}

extern "C" void fn_800EA880(void *channel, int delta) {
    /* Advance a channel's frame counter (+0xAC) by delta, clamping it to its limit (+0xB0). */
    int counter = *(int *)((char *)channel + 0xAC) + delta;
    int limit = *(int *)((char *)channel + 0xB0);
    *(int *)((char *)channel + 0xAC) = counter;
    if (counter > limit) {
        *(int *)((char *)channel + 0xAC) = limit;
    }
}

extern "C" void fn_800EA8A0(void *channel, int frameLimit, signed char slideFlag, float pitch) {
    /* Set up a channel's note: store its pitch (+0xA8) and frame limit (+0xB0),
     * write the slide-enable byte (+0x3C), and reset the frame counter at +0xAC. */
    *(float *)((char *)channel + 0xA8) = pitch;
    *(int *)((char *)channel + 0xB0) = frameLimit;
    *(signed char *)((char *)channel + 0x3C) = slideFlag;
    *(int *)((char *)channel + 0xAC) = 0;
}

extern "C" void VoiceCallback__Q46nw4hbm3snd6detail7ChannelFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv(void *arg0, int arg1, void *arg2) {
    int zero = 0;
    char *channel = (char *)arg2;
    char *manager;
    void (*callback)(void *, int, unsigned long);
    if (channel == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803228E8, 0x1C4, lbl_80322924);
    switch (arg1) {
    case 0: arg1 = 2; Free__Q46nw4hbm3snd6detail7AxVoiceFv(arg0); break;
    case 1: arg1 = 3; Free__Q46nw4hbm3snd6detail7AxVoiceFv(arg0); break;
    case 2:
    case 3: arg1 = 1; break;
    default: break;
    }
    callback = *(void (**)(void *, int, unsigned long))(channel + 0xD8);
    if (callback) callback(channel, arg1, *(unsigned long *)(channel + 0xDC));
    *(int *)(channel + 0xE0) = zero;
    channel[0x39] = zero;
    channel[0x3A] = zero;
    channel[0x3B] = zero;
    if ((signed char)lbl_8055DE28 == 0) {
        ChannelManagerLayout *globalManager = (ChannelManagerLayout *)lbl_80412778;
        *(volatile int *)lbl_80412778 = zero;
        *(void * volatile *)((char *)globalManager + 0x4) = 0;
        void *idleSentinel = &globalManager->idle.head;
        void *activeSentinel = &globalManager->active.head;
        *(void * volatile *)((char *)globalManager + 0x8) = 0;
        *(void * volatile *)((char *)globalManager + 0x10) = 0;
        *(void * volatile *)((char *)globalManager + 0x14) = 0;
        *(void **)((char *)globalManager + 0x4) = idleSentinel;
        *(void **)((char *)globalManager + 0x8) = idleSentinel;
        *(int *)((char *)globalManager + 0xC) = zero;
        *(void **)((char *)globalManager + 0x10) = activeSentinel;
        *(void **)((char *)globalManager + 0x14) = activeSentinel;
        ((void (*)(void *, void *, void *, void *, void *))__register_global_object)(
            globalManager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv,
            lbl_8040EC78, activeSentinel, idleSentinel);
        lbl_8055DE28 = 1;
    }
    manager = lbl_80412778;
    if (channel == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322A64, 0x77, lbl_80322A3C);
    if (*(int *)(manager + 0xC)) {
        void *head;
        if (channel == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8, 0x233, lbl_80322AB4);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(manager + 0xC, channel);
        if (channel == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8, 0x233, lbl_80322AB4);
        head = manager + 4;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(manager, &head, channel);
    }
}

extern "C" void *AllocChannel__Q46nw4hbm3snd6detail7ChannelFiiiPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(int arg0, int arg1, int arg2, void (*arg3)(void *, int, unsigned long), unsigned long arg4) {
    int irq;
    void *chan;
    int r;
    irq = OSDisableInterrupts();
    if (arg2 < 0 || arg2 > 0xFF) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803228E8, 0x1F9, lbl_803228E8 + 0x64, arg2, 0, 0xFF);
    }
    chan = 0;
    OSRestoreInterrupts(irq);
    return chan;
}

extern "C" void fn_800EAD00(void *channel) {
    if (channel != 0) {
        *(int *)((char *)channel + 0xD8) = 0;
        *(int *)((char *)channel + 0xDC) = 0;
    }
}

extern "C" char lbl_803229AC[];
extern "C" char lbl_803229D0[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...) __attribute__((noreturn));
extern "C" void Update__Q46nw4hbm3snd6detail7ChannelFb(void *, int);


#pragma use_lmw_stmw off
extern "C" void UpdateAllChannel__Q46nw4hbm3snd6detail7ChannelFv(void) {
    struct PtrBox { void *v; } nodeBox, endBox;
    void *&node = nodeBox.v;
    void *&end = endBox.v;
    char *manager;
    register int zero = 0;
    int one = 1;
    void *head;
    void *current;
    if ((signed char)lbl_8055DE28 == 0) {
        manager = lbl_80412778;
        head = manager + 0x10;
        *(void **)(manager + 4) = (void *)zero;
        void *initTail = manager + 4;
        *(void **)(manager + 8) = (void *)zero;
        *(void **)(manager + 0x10) = (void *)zero;
        *(void **)(manager + 0x14) = (void *)zero;
        *(int *)lbl_80412778 = zero;
        *(void **)(manager + 4) = initTail;
        *(void **)(manager + 8) = initTail;
        *(int *)(manager + 0xC) = zero;
        *(void **)(manager + 0x10) = head;
        *(void **)(manager + 0x14) = head;
        ((void (*)(void *, void *, void *))__register_global_object)(manager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv, lbl_8040EC78);
        lbl_8055DE28 = one;
    }
    manager = lbl_80412778;
    end = manager + 0x10;
    node = *(void **)(manager + 0x10);
    do {
        current = node;
        node = *(void **)node;
        if (current == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803229D0, 0x23D, lbl_803229AC);
        Update__Q46nw4hbm3snd6detail7ChannelFb(current, 1);
        if ((signed char)lbl_8055DE28 == 0) {
            head = manager + 4;
            *(void **)(manager + 4) = (void *)zero;
            void *initTail = manager + 0x10;
            *(void **)(manager + 8) = (void *)zero;
            *(void **)(manager + 0x10) = (void *)zero;
            *(void **)((unsigned short)manager + 0x14) = (void *)zero;
            *(int *)lbl_80412778 = zero;
            *(void **)(manager + 4) = head;
            *(void **)(manager + 8) = head;
            *(int *)(manager + 0xC) = zero;
            *(void **)(manager + 0x10) = initTail;
            *(void **)(manager + 0x14) = initTail;
            ((void (*)(void *, void *, void *, void *, void *))__register_global_object)(manager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv, lbl_8040EC78, initTail, head);
            lbl_8055DE28 = one;
        }
    } while (end != node);
}
extern void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, int);
extern void *fn_80128668(void *);
extern "C" {
extern char lbl_803228E8[];
extern char lbl_803229AC[];
extern char lbl_803229D0[];
extern char lbl_803229DC[];
extern char lbl_80322A00[];
extern char lbl_80322A0C[];
extern char lbl_80322A30[];
extern char lbl_80322AB4[];
extern char lbl_80322AD8[];
extern char lbl_8040EC78[];
extern char lbl_80412778[];
extern unsigned char lbl_8055DE28;
extern void __register_global_object(void*,void*,void*,void*,void*,void*);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*,void**);
extern void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*,void**,void*);
extern void InitParam__Q46nw4hbm3snd6detail7ChannelFPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(void*,void(*)(void*,int,unsigned long),unsigned long);
extern int __dt__Q46nw4hbm3snd6detail14ChannelManagerFv(int,int);
extern char lbl_803229AC[];
extern char lbl_803229D0[];
extern char lbl_803229DC[];
extern char lbl_80322A00[];
extern char lbl_80322A0C[];
extern char lbl_80322A30[];
extern char lbl_80322AB4[];
extern char lbl_80322AD8[];
extern char lbl_8040EC78[];
extern void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern void *Instance__15EmissionManagerFv(void);
extern int fn_800E3954(int,int,int,void*,void*);
extern void VoiceCallback__Q46nw4hbm3snd6detail7ChannelFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv(void*,int,void*);
}
