// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <revolution/OS/OSMessage.h>

/* forward decls for helpers defined further down in this file */
extern "C" s32 fn_80128668(void *);
extern "C" void *fn_800FDE60(void);
extern "C" void fn_800FE1D0(void);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FDFA0(void *, s32);
extern u8 lbl_8055DE80;
#pragma push
#pragma small_data off
extern u8 lbl_8041B138[];
#pragma pop

extern u32 lbl_80559900;
#pragma push
#pragma small_data off
extern u8 lbl_803271B8[];
extern u8 lbl_803274C0[];
extern u8 lbl_8032749C[];
extern u8 lbl_80327460[];
extern u8 lbl_8041D4AC[];
#pragma pop
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern double __ieee754_pow(double, double);
extern "C" double fn_8002EFBC(double, double);

#pragma push
#pragma small_data off
extern u8 lbl_80327010[];
extern u8 lbl_80327020[];
extern f32 lbl_805610C8; // 1.0
extern f32 lbl_805610CC; // 2.0
extern f32 lbl_805610D0; // 0.5
extern f32 lbl_805610E4; // 256.0
extern f32 lbl_805610E8; // 0.0
extern double lbl_805610F0; // 32000.0
extern double lbl_805610F8; // 2.0
extern double lbl_80561100; // 10.0
extern double lbl_80561108; // 1.0
extern f32 lbl_802F6124[]; // pan table
#pragma pop

extern "C" void fn_8002F634(void*, void*, s32, s32);
extern "C" s32 ExecuteSingle__Q46nw4hbm3snd6detail11TaskManagerFv(void*);
extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32 level);
extern "C" void Stop__Q36nw4hbm3snd10WavePlayerFv(void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void Stop__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, u32);

#pragma push
#pragma small_data off
extern u8 lbl_80327334[];
extern u8 lbl_802F5210[];
#pragma pop

extern f32 lbl_805610D4; // 1.0
extern f32 lbl_805610D8; // 0.0
extern f32 lbl_805610DC; // 128.0
extern f32 lbl_805610E0; // 0.0

extern "C" u32 fn_800FEB9C(void);

extern "C" void fn_800FDE28(void *arg0) {
    void *p = *(void **)arg0;
    if (p && *(void **)((u8 *)p + 0x5F4) == arg0) {
        *(void **)((u8 *)p + 0x5F4) = NULL;
    }
    if (*(void **)arg0) {
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_800FDFF8(void *);
extern "C" void *fn_8002F53C(void *, void *, void *, s32, s32);
extern "C" void OSInitMutex(void *);
extern "C" void *MEMRecordStateForFrmHeap(void *, s32, s32, s32, s32);
extern "C" u32 MEMResizeForMBlockFrmHeap(void);
extern "C" void __register_global_object(void *, void *, void *);
extern "C" void *__dt__Q46nw4hbm3snd6detail11TaskManagerFv(void *, s32);
#pragma push
#pragma small_data off
extern u8 lbl_804190A0[];
#pragma pop
extern u8 lbl_8055DE78;
#pragma dont_inline on
extern "C" void *fn_800FDE60(void) {
    extern u8 lbl_80326E08[];
    extern u8 lbl_80326E20[];
    struct Manager {
        u8 pad[0x1C];
        volatile s32 unk_0x1C;
    };
    u8 *base = lbl_804190A0;
    if ((s8)lbl_8055DE78 == 0) {
        Manager *manager = (Manager *)(base + 0x2050);
        manager->unk_0x1C = 0;
        fn_8002F53C((u8 *)manager + 0x20, (void *)fn_800FDFF8,
                    (void *)__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FDFA0, 0xC, 3);
        OSInitMutex((void *)manager);
        *(void **)((u8 *)manager + 0x18) =
            MEMRecordStateForFrmHeap((void *)(base + 0), 0x2044, 0x40, 4, 0);
        if (MEMResizeForMBlockFrmHeap() < 0x80)
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326E08, 0x37,
                                        (const char *)lbl_80326E20);
        __register_global_object(base + 0x2050,
                                 (void *)__dt__Q46nw4hbm3snd6detail11TaskManagerFv,
                                 base + 0x2044);
        lbl_8055DE78 = 1;
    }
    return base + 0x2050;
}
#pragma dont_inline reset

extern "C" void *__dt__Q46nw4hbm3snd6detail11TaskManagerFv(void *this_, s32 flag) {
    if (this_) {
        fn_8002F634((u8 *)this_ + 0x20,
                    (void *)__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FDFA0,
                    0xC, 3);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FDFA0(
    void *this_, s32 flag) {
    if (this_) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(this_, 0);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void fn_800FDFF8(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

#pragma push
#pragma small_data off
extern u8 lbl_80326E08[];
#pragma pop
extern "C" s32 MEMFreeByStateToFrmHeap(s32);
#pragma push
#pragma small_data off
#pragma pop
extern "C" s32 Alloc__Q46nw4hbm3snd6detail11TaskManagerFv(void *arg0)
{
    u32 temp_r31;
    const char (*base)[0xC8] = (const char (*)[0xC8])lbl_80326E08;
    s32 var_r29;

    if (*(s32 *)((u8 *)arg0 + 0x18) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&(*base)[0], 0x45, &(*base)[0x68]);
    }
    temp_r31 = OSDisableInterrupts();
    var_r29 = MEMFreeByStateToFrmHeap(*(s32 *)((u8 *)arg0 + 0x18));
    while (var_r29 == 0) {
        if (ExecuteSingle__Q46nw4hbm3snd6detail11TaskManagerFv(arg0) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(&(*base)[0], 0x4C, &(*base)[0xA8]);
        }
        var_r29 = MEMFreeByStateToFrmHeap(*(s32 *)((u8 *)arg0 + 0x18));
    }
    OSRestoreInterrupts(temp_r31);
    return var_r29;
}
extern "C" s32 fn_800FE0DC(void *arg0) {
    void *p = *(void **)((u8 *)arg0 + 0x18);
    return *(s32 *)((u8 *)p + 0x40);
}

extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void *, void *);
#pragma push
#pragma small_data off
extern u8 lbl_80326ED0[];
extern u8 lbl_80326FA4[];
extern u8 lbl_80326FC8[];
#pragma push
#pragma small_data off
#pragma pop
namespace nw4hbm {
namespace snd {
namespace detail {
struct Task;
struct TaskManager {
    enum TaskPriority { TaskPriority0 = 0 };
    void AppendTask(Task *, TaskPriority);
};
}
}
}

void nw4hbm::snd::detail::TaskManager::AppendTask(
    nw4hbm::snd::detail::Task *task,
    nw4hbm::snd::detail::TaskManager::TaskPriority priority) {
    u32 level;
    void *list;
    void *it;
    s32 valid;

    valid = 0;
    if (priority >= 0 && priority < 3) valid = 1;
    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326E08, 0x7D, (const char *)lbl_80326ED0, priority, 0, 3);
    }
    level = OSDisableInterrupts();
    list = (u8 *)this + priority * 0xC + 0x20;
    it = (u8 *)list + 4;
    if (task == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326FC8, 0x233, (const char *)lbl_80326FA4);
    }
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(list, &it, (u8 *)task + 4);
    OSRestoreInterrupts(level);
}

#pragma dont_inline on
extern "C" void fn_800FE1D0(void) {
    do {
    } while (ExecuteSingle__Q46nw4hbm3snd6detail11TaskManagerFv((void *)0) != 0);
}
#pragma dont_inline reset

extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void *, void *);
extern "C" void *MEMAdjustFrmHeap(void *, void *);
extern "C" void OSRestoreInterrupts(u32);
extern u8 lbl_80326F38[], lbl_80326F14[], lbl_80326F68[], lbl_80326F44[], lbl_80326E08[], lbl_80326E70[];
extern "C" void CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl(void *arg0, u32 taskId) {
    struct Iterator { void *node; };
    u32 level = OSDisableInterrupts();
    s32 count;
    u8 *list = (u8 *)arg0 + 0x20;
    void *node;
    for (count = 0; count < 3; count++, list += 0xC) {
        void *current;
        void *sentinel = list + 4;
        node = *(void **)(list + 4);
        while (node != sentinel) {
            current = node;
            node = *(void **)node;
            if (!current) Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80326F38, 0x23d, (char *)lbl_80326F14);
            if (*(u32 *)((u8 *)current + 8) == taskId) {
                struct Iterator it;
                it.node = current;
                ((void (*)(void *, struct Iterator))Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator)(list, it);
                if (!current) Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80326F38, 0x23d, (char *)lbl_80326F14);
                if (!((u8 *)current - 4)) Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80326F68, 0x193, (char *)lbl_80326F44);
                if (!*(void **)((u8 *)arg0 + 0x18)) Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80326E08, 0x5d, (char *)lbl_80326E70);
                level = OSDisableInterrupts();
                MEMAdjustFrmHeap(*(void **)((u8 *)arg0 + 0x18), (u8 *)current - 4);
                OSRestoreInterrupts(level);
            }
        }
    }
    node = *(void **)((u8 *)arg0 + 0x1C);
    if (node && *(u32 *)((u8 *)node + 0xC) == taskId)
        ((void (*)(void *))(*(void ***)node)[4])(node);
    OSRestoreInterrupts(level);
}

extern "C" void *fn_800FE648(void) {
    s8 initialized = (s8)lbl_8055DE80;
    if (initialized != 0) {
    } else {
        lbl_8041B138[0x2360] = 0;
        lbl_8055DE80 = 1;
    }
    return lbl_8041B138;
}

extern "C" s32 fn_800FE814(s32);
extern "C" s32 Create__Q46nw4hbm3snd6detail10TaskThreadFl(OSThread *arg0, s32 arg1) {
    s32 result;
    u8 *self = (u8 *)arg0;
    if (self[0x2360]) return 1;
    self[0x2360] = 1;
    OSInitThreadQueue((OSThreadQueue *)(self + 0x2318));
    if ((s8)lbl_8055DE80 == 0) {
        lbl_8055DE80 = 1;
        lbl_8041B138[0x2360] = 0;
    }
    result = OSCreateThread(arg0, (OSThreadFunc)fn_800FE814, lbl_8041B138,
             (OSThreadQueue *)(self + 0x2318), 0x2000, arg1, 0);
    if (result) OSResumeThread(arg0);
    return result != 0;
}

#pragma push
#pragma small_data off
extern u8 lbl_80326FD8[];
extern u8 lbl_80326FEC[];
#pragma pop
extern "C" s32 Destroy__Q46nw4hbm3snd6detail10TaskThreadFv(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x2360) == 0) return 0;
    if ((s8)lbl_8055DE80 == 0) {
        lbl_8041B138[0x2360] = 0;
        lbl_8055DE80 = 1;
    }
    if (OSSendMessage((OSMessageQueue *)(lbl_8041B138 + 0x2320), (OSMessage)2, 0) == 0) return 0;
    if (OSJoinThread((OSThread *)arg0, 0) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326FD8, 0x62, (const char *)lbl_80326FEC);
    *(u8 *)((u8 *)arg0 + 0x2360) = 0;
    return 1;
}

extern "C" void fn_800FE804(void *arg0) {
    OSSendMessage((OSMessageQueue *)((u8 *)arg0 + 0x2320), (OSMessage)0x1, 0);
}

extern "C" s32 fn_800FE814(s32 arg0) {
    u32 msg;

    OSInitMessageQueue((OSMessageQueue *)(arg0 + 0x2320), (OSMessage *)(arg0 + 0x2340), 8);
    for (;;) {
        OSReceiveMessage((OSMessageQueue *)(arg0 + 0x2320), (OSMessage *)&msg, 1);
        if (msg == 1) {
            fn_800FDE60();
            fn_800FE1D0();
            continue;
        }
        if (msg != 2) {
            continue;
        }
        return 0;
    }
}

extern f32 lbl_802F4DE0[];
extern f32 lbl_802F4E10[];
extern "C" f32 CalcPitchRatio__Q46nw4hbm3snd6detail4UtilFi(s32 pitch) {
    u32 count = (u32)(0xBFF - pitch) / 0xC00;
    f32 ratio = lbl_805610C8;
    s32 octave = 0;

    if (pitch < 0) {
        u32 chunks = count >> 3;
        s32 adjustment = count * 0xC00;
        if (chunks != 0) {
            do {
                octave -= 8;
            } while (--chunks != 0);
        }
        count &= 7;
        if (count != 0) {
            do {
                octave -= 1;
            } while (--count != 0);
        }
        pitch += adjustment;
    }

    if (pitch >= 0xC00) {
        count = (u32)pitch / 0xC00;
        u32 chunks = count >> 3;
        s32 adjustment = count * -0xC00;
        if (chunks != 0) {
            do {
                octave += 8;
            } while (--chunks != 0);
        }
        count &= 7;
        if (count != 0) {
            do {
                octave += 1;
            } while (--count != 0);
        }
        pitch += adjustment;
    }

    f32 factor = lbl_805610CC;
    if (octave > 0) {
        u32 chunks = (u32)octave >> 3;
        s32 negate = -octave;
        if (chunks != 0) {
            do {
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
            } while (--chunks != 0);
        }
        count = (u32)octave & 7;
        if (count != 0) {
            do {
                ratio *= factor;
            } while (--count != 0);
        }
        octave += negate;
    }

    factor = lbl_805610D0;
    if (octave < 0) {
        count = (u32)(-octave);
        u32 chunks = count >> 3;
        if (chunks != 0) {
            do {
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
                ratio *= factor;
            } while (--chunks != 0);
        }
        count &= 7;
        if (count != 0) {
            do {
                ratio *= factor;
            } while (--count != 0);
        }
    }

    s32 semitone = (pitch >> 8) + 1;
    s32 fraction = pitch & 0xFF;
    if (semitone != 0) ratio *= lbl_802F4DE0[semitone];
    if (fraction != 0) ratio *= lbl_802F4E10[fraction];
    return ratio;
}

#pragma push
#pragma scheduling on
extern "C" f32 CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(f32 value) {
    f32 v;
    s32 index;
    u8 *table;

    if (value > lbl_805610D4) {
        v = lbl_805610D4;
    } else if (value < lbl_805610D8) {
        v = lbl_805610D8;
    } else {
        v = value;
    }

    index = (s32)(lbl_805610DC * v);
    table = lbl_802F5210;
    return *(f32 *)(table + (index + 0x388) * 4);
}
#pragma push
#pragma scheduling invalid_target
extern "C" f32 CalcPanRatio__Q46nw4hbm3snd6detail4UtilFf(f32 pan) {
    register f32 upper = lbl_805610C8;
    register f32 v;
    f32 t;

    if (pan > upper) {
        v = upper;
    } else if (pan < lbl_805610E0) {
        v = lbl_805610E0;
    } else {
        v = pan;
    }

    t = lbl_805610C8 + v;
    return lbl_802F6124[(s32)(lbl_805610D0 +
                              lbl_805610E4 * (t * lbl_805610D0))];
}
#pragma pop
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

extern "C" s32 CalcLpfFreq__Q46nw4hbm3snd6detail4UtilFf(f32 value) {
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
    x = fn_8002EFBC(x, lbl_805610F8);
    return (s32)(lbl_805610F0 * x);
}

u32 fn_800FEB9C(void) {
    u32 val = lbl_80559900 * 0x19660D;
    val += 0x3C6F0000;
    u32 out = val;
    out -= 0x0CA1;
    lbl_80559900 = out;
    return out >> 16;
}

extern "C" void *GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
    s32 type, u32 arg, void *pBase) {
    if (type == 1) {
        return (void *)(arg + (u32)pBase);
    }

    if (type == 0) {
        return (void *)arg;
    }

    Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80327010, 0x1F6,
                                 (const char *)lbl_80327020);
    return NULL;
}

extern "C" void fn_800FEC1C(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
}

extern "C" void* __dt__Q36nw4hbm3snd10WavePlayerFv(void *this_, s32 arg1, u32 arg2) {
    if (this_ != NULL) {
        *(void **)this_ = lbl_80327334;
        u32 level = OSDisableInterrupts();
        Stop__Q36nw4hbm3snd10WavePlayerFv(this_);
        if (*(void **)((u8 *)this_ + 0x18) != NULL) {
            Free__Q46nw4hbm3snd6detail7AxVoiceFv(*(void **)((u8 *)this_ + 0x18));
        }
        *(void **)((u8 *)this_ + 0x18) = NULL;
        *(void **)((u8 *)this_ + 0x10) = NULL;
        OSRestoreInterrupts(level);
        void *list = (void *)((u8 *)this_ + 4);
        if (list != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(list, 0);
        }
        if (arg1 > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" u32 GetCurrentPlayingDspAddress__Q46nw4hbm3snd6detail7AxVoiceCFv(void *);
extern "C" u32 GetDspAddressBySample__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(const void *, u32, u32);
extern "C" u32 GetSampleByByte__Q46nw4hbm3snd6detail7AxVoiceFUlQ56nw4hbm3snd6detail7AxVoice6Format(u32, u32);
extern "C" s32 IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(void *);
extern u8 lbl_8032737C[], lbl_803273A0[], lbl_803273AC[], lbl_803273D0[], lbl_803273DC[], lbl_80327400[];
#pragma use_lmw_stmw off
extern "C" s32 IsNextWavePacket__Q36nw4hbm3snd10WavePlayerCFv(void *arg0) {
    void *rawWave;
    void *wave;
    u32 current, format, start, end;
    s32 sample;
    if (!*(void **)((u8 *)arg0 + 0x18)) return 0;
    if (IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(*(void **)((u8 *)arg0 + 0x18))) return 0;
    if (*(s32 *)((u8 *)arg0 + 4) == 0) return 0;
    if (*(s32 *)((u8 *)arg0 + 4) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80327400, 0x1f6, (const char *)lbl_803273DC);
    rawWave = *(void **)((u8 *)arg0 + 8);
    if (!rawWave) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803273A0, 0x242, (const char *)lbl_8032737C);
    wave = (u8 *)rawWave - 0x18;
    if (!wave) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803273D0, 0x1bf, (const char *)lbl_803273AC);
    current = GetCurrentPlayingDspAddress__Q46nw4hbm3snd6detail7AxVoiceCFv(*(void **)((u8 *)arg0 + 0x18));
    format = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 0x18) + 0x118);
    sample = GetSampleByByte__Q46nw4hbm3snd6detail7AxVoiceFUlQ56nw4hbm3snd6detail7AxVoice6Format(*(u32 *)((u8 *)wave + 0x10), format);
    start = GetDspAddressBySample__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(*(void **)((u8 *)wave + 8), 0, format);
    end = GetDspAddressBySample__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(*(void **)((u8 *)wave + 8), sample, format);
    if (current < start) goto yes;
    if (end > current) goto no;
yes:
    return 1;
no:
    return 0;
}
#pragma use_lmw_stmw reset
extern "C" s32 IsNextWavePacket__Q36nw4hbm3snd10WavePlayerCFv(void *);
extern "C" void UpdateWavePacket__Q36nw4hbm3snd10WavePlayerFv(void *);
extern "C" void SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(void *, BOOL);
extern "C" void SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *, s32, const void *, u32);
extern "C" void fn_800FF090(void *);
extern u8 lbl_8032734C[], lbl_80327370[], lbl_8032746C[], lbl_80327490[];
#pragma use_lmw_stmw off
extern "C" void detail_UpdateBufferAllPlayers__Q36nw4hbm3snd10WavePlayerFv(void *arg0) {
    extern u8 lbl_8041D4AC[];
    void **end = (void **)(lbl_8041D4AC + 4);
    void **node = (void **)*end;
    void *entry, *player, *wave;
    s32 i, offset;
    goto check_player;
player_loop:
    entry = node;
    node = (void **)*node;
    if (!entry) Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80327370, 0x23d, (char *)lbl_8032734C);
    player = (u8 *)entry - 0x94;
    if (*((u8 *)entry - 0x77)) {
        if (IsNextWavePacket__Q36nw4hbm3snd10WavePlayerCFv(player)) UpdateWavePacket__Q36nw4hbm3snd10WavePlayerFv(player);
        if (!*((u8 *)player + 0x1e) && *(u32 *)((u8 *)player + 4) >= 2) {
            i = 0;
            wave = *(void **)((u8 *)player + 8);
            void *list = *(void **)wave;
            if (*(s32 *)((u8 *)player + 0x10) > 0) {
                void *base = (u8 *)list - 0x18;
                offset = 0;
                for (i = 0; i < *(s32 *)((u8 *)player + 0x10); i++) {
                    if (!list) Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80327490, 0x23d, (char *)lbl_8032746C);
                    SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(*(void **)((u8 *)player + 0x18), i, *(void **)((u8 *)base + offset + 8), 0);
                    offset += 4;
                }
            }
            SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(*(void **)((u8 *)player + 0x18), 1);
            *((u8 *)player + 0x1e) = 1;
        }
    } else if (*(s32 *)((u8 *)player + 4)) fn_800FF090(player);
check_player:
    if (node != end) goto player_loop;
}
#pragma use_lmw_stmw reset
extern "C" void fn_800E5338(s32, f32);
extern "C" void fn_800E5444(s32, f32);
extern "C" void fn_800E5464(s32, f32);
extern "C" void fn_800E54A8(s32, f32);
extern "C" void fn_800E5550(s32, f32);
extern "C" void fn_800E5594(s32, s32);
extern "C" void fn_800E55B4(s32, f32);
extern "C" void fn_800E56D0(s32, f32);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E5718(s32, s32, f32);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif(s32, s32, f32);
extern "C" void SetRemoteSend__Q46nw4hbm3snd6detail7AxVoiceFif(s32, s32, f32);
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E58CC(s32, s32, f32);
extern f32 lbl_80561110;
extern "C" void fn_800FF708(void *arg0) {
    s32 i;
    u8 *ptr;
    if (*(s32 *)((u8 *)arg0 + 0x18) == 0) return;
    fn_800E5338(*(s32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x30));
    fn_800E5444(*(s32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x3C));
    fn_800E5464(*(s32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x34));
    fn_800E54A8(*(s32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x38));
    fn_800E5550(*(s32 *)((u8 *)arg0 + 0x18), lbl_80561110 + *(f32 *)((u8 *)arg0 + 0x40));
    fn_800E5594(*(s32 *)((u8 *)arg0 + 0x18), *(s32 *)((u8 *)arg0 + 0x44));
    fn_800E55B4(*(s32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x48));
    fn_800E56D0(*(s32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x5C));
    ptr = (u8 *)arg0;
    for (i = 0; i < 3; i++, ptr += 4) {
        SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E5718(*(s32 *)((u8 *)arg0 + 0x18), i, *(f32 *)(ptr + 0x60));
    }
    ptr = (u8 *)arg0;
    for (i = 0; i < 4; i++, ptr += 4) {
        SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif(*(s32 *)((u8 *)arg0 + 0x18), i, *(f32 *)(ptr + 0x4C));
        SetRemoteSend__Q46nw4hbm3snd6detail7AxVoiceFif(*(s32 *)((u8 *)arg0 + 0x18), i, *(f32 *)(ptr + 0x6C));
        SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E58CC(*(s32 *)((u8 *)arg0 + 0x18), i, *(f32 *)(ptr + 0x6C));
    }
}

#pragma push
#pragma small_data off
extern u8 lbl_8032734C[];
extern u8 lbl_80327370[];
extern u8 lbl_80327040[];
extern u8 lbl_80327304[];
extern u8 lbl_8041D4AC[];
#pragma pop
extern "C" void fn_800FF708(void *);
#pragma push
#pragma small_data off
#pragma pop
extern "C" void UpdateAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FF824(void) {
    void *cur = *(void **)(lbl_8041D4AC + 4);
    void *end = lbl_8041D4AC + 4;
    do {
        void *item = cur;
        cur = *(void **)cur;
        if (item == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80327370, 0x23D, (char *)lbl_8032734C);
        fn_800FF708((u8 *)item - 0x94);
    } while (cur != end);
}
#pragma push
#pragma small_data off
#pragma pop
extern "C" void detail_StopAllPlayers__Q36nw4hbm3snd10WavePlayerFv(void) {
    void *cur = *(void **)(lbl_8041D4AC + 4);
    void *end = (u8 *)lbl_8041D4AC + 4;
    while (cur != end) {
        void *item = cur;
        cur = *(void **)cur;
        if (item == 0)
            Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80327370, 0x23D, (char *)lbl_8032734C);
        Stop__Q36nw4hbm3snd10WavePlayerFv((u8 *)item - 0x94);
    }
    if (*(u32 *)lbl_8041D4AC != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((char *)lbl_80327040, 0x319, (char *)lbl_80327304);
}
extern "C" s32 fn_80128668(void *);

#pragma push
#pragma small_data off
extern u8 lbl_8041B138[];
#pragma pop
extern u8 lbl_8055DE80;
extern "C" s32 fn_800FF940(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        ((s32 (*)(void))fn_80128668)();
    }
    return arg0;
}

