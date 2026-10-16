#include <types.h>

extern "C" void OSCancelAlarm(void *);

namespace nw4hbm { namespace snd { namespace detail {
class SeqFileReader {
public:
    void *GetBaseAddress() const;
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
    void* node;
    void* pThis;
    void* pCb;
    u32 level;

    pThis = this_;
    pCb = pCallback;
    node = (void*)((u8*)pThis + 4);
    level = OSDisableInterrupts();

    if (pCb == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322B74, 0x233,
                                     (const char*)lbl_80322B50);
    }

    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
        pThis, &node, pCb);

    OSRestoreInterrupts(level);
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

extern f32 lbl_80560FE8;
extern f32 lbl_80560FEC;
extern f32 lbl_80560FF0;
extern f32 lbl_80560FF4;
extern u8 lbl_802F4B90[];
extern "C" void DVDClose(void*);
extern "C" f32 CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(f32);
extern "C" void fn_800EB3AC(void* arg0) {
    *(s32*)arg0 = 0;
    *(f32*)((u8*)arg0 + 4) = lbl_80560FEC;
    *(f32*)((u8*)arg0 + 8) = lbl_80560FE8;
    *(f32*)((u8*)arg0 + 0xC) = lbl_80560FE8;
    *(f32*)((u8*)arg0 + 0x10) = *(f32*)(lbl_802F4B90 + 0x1FC);
    *(u8*)((u8*)arg0 + 0x14) = 0x7F;
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

extern "C" void *fn_800F26FC(void *, unsigned int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800ECB38(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_800F26FC(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern u8 lbl_803231D8[];
extern "C" s32 fn_800F283C(void *, u32, s32, s32 *);
extern "C" s32 fn_800F2824(void *, s32, void *);
extern "C" s32 fn_800F282C(void *, s32, s32, void *);
extern "C" s32 detail_GetWaveDataFileAddress__Q36nw4hbm3snd18MemorySoundArchiveCFUl_800ECD14(void *this_, u32 id) {
 struct { s32 v[13]; } local;
 s32 *p=(s32 *)&local;
 if(!fn_800F283C(this_,id,0,p+0)) return 0;
 if(!fn_800F2824(this_,p[0],p+8)) return 0;
 if(!fn_800F282C(this_,p[0],p[1],p+2)) return 0;
 if(p[9]!=0) return 0;
 return *(u32 *)((u8 *)this_+0x108)+p[12]+p[7];
}

extern "C" void *OpenStream__Q34nw4r3snd18MemorySoundArchiveCFPviUlUl(void *this_, void *stream, u32 bufferSize, s32 offset, u32 length) {
    u32 base = *(u32 *)((u8 *)this_ + 0x108);
    if (base == 0) return 0;
    if (bufferSize < 0x20) return 0;
    if (stream == 0) return stream;
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
 u32 pos=*(u32 *)((u8 *)this_+0x1C); u32 remaining=*(u32 *)((u8 *)this_+0x18)-pos; u32 count=size;
 if(size>remaining) count=remaining;
 memcpy(dst,(u8 *)this_+*(u32 *)((u8 *)this_+0x14)+pos,count); return count;
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

extern "C" void fn_800ED058() {
    return;
}

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
s32 fn_800ED0BC(s32 arg0) {
    u8 val = ((u8 *)arg0)[0x16];
    s32 t = -(s32)val;
    return ((t | (s32)val) >> 31);
}
s32 fn_800ED0D0(s32 arg0) {
    return ((u8 *)arg0)[0x15] != 0;
}
#pragma push
#pragma small_data off
#pragma pop
extern "C" void fn_800ED0E4(s32 arg0) {
    arg0 -= 8;
    fn_800ED058();
}
s32 fn_800ED0F4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668_noarg();
    }
    return arg0;
}

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
    if (track == 0) return 0;
    track = __ct__Q46nw4hbm3snd6detail11MmlSeqTrackFv(track);
    if (track != 0) {
        *(void **)((u8 *)track + 0xB4) = arg1;
        *(void **)((u8 *)track + 0xBC) = *(void **)((u8 *)arg0 + 4);
    }
    return track;
}

extern "C" void DestroyImpl__Q46nw4hbm3snd6detail8PoolImplFPvUl(void*);
extern void CreateImpl__Q46nw4hbm3snd6detail8PoolImplFPvUlUl(void*, u32);
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

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800EF804(void* arg0, f32 farg0) {
    extern f32 lbl_8056106C;
    extern u8 lbl_80323B28[];
    extern u8 lbl_80323C14[];
    u32 level;
    if (farg0 > lbl_8056106C) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x164, (const char*)lbl_80323C14);
    }
    level = OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x34) = farg0;
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
    OSRestoreInterrupts(0);
}

extern "C" void fn_800EF978(void* arg0, f32 arg1) {
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x38) = arg1;
    OSRestoreInterrupts(0);
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
#pragma pop
extern "C" s32 fn_800EFBAC(void* arg0) {
    return *(s32*)&((u8*)arg0)[0x3C];
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800EFBB4(
    void* this_, s32 auxBus, f32 send) {
    s32 bus = auxBus;
    f32 value = send;
    BOOL valid = 0;

    if (bus >= 0 && bus < 4) {
        valid = 1;
    }

    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1C6,
                                     (const char*)lbl_80323C74, bus, 0, 4);
    }

    {
        u32 level = OSDisableInterrupts();
        ((f32*)((u8*)this_ + 0x54))[bus] = value;
        OSRestoreInterrupts(level);
    }
}
#pragma push
#pragma small_data off
#pragma pop
extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800EFC50(
    void* this_, s32 auxBus) {
    s32 bus = auxBus;
    BOOL valid = 0;

    if (bus >= 0 && bus < 4) {
        valid = 1;
    }

    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1CD,
                                     (const char*)lbl_80323C74, bus, 0, 4);
    }

    return ((f32*)((u8*)this_ + 0x54))[bus];
}
void fn_800F0750(void) {
    return;
}
extern u8 lbl_803231D8[];
extern "C" s32 fn_800F283C(void *, u32, s32, s32 *);
extern "C" s32 fn_800F2824(void *, s32, void *);
extern "C" s32 fn_800F282C(void *, s32, s32, void *);
extern "C" void *memcpy(void *, const void *, u32);
