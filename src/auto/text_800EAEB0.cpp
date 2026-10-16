#include <types.h>

#pragma push
#pragma small_data off
extern f32 lbl_80561018;
extern f32 lbl_8056101C;
extern f32 lbl_80561020;
extern f64 lbl_80561028;
#pragma pop

extern f32 lbl_8056106C;
extern u8 lbl_80323B28[];
extern u8 lbl_80323BEC[];
extern u8 lbl_80323C14[];
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
    volatile u8* p = (volatile u8*)arg0;
    f32 a = lbl_80560FE8;
    f32 b = *(f32*)(lbl_802F4B90 + 0x1FC);
    f32 c = lbl_80560FEC;
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

void fn_800EBB88(void* arg0) {
    u32* p = (u32*)arg0;
    u32* q = (u32*)((u8*)arg0 + 8);
    p[2] = 0; p[3] = 0; p[0] = 0; p[1] = 0;
    p[2] = (u32)q; p[3] = (u32)q;
}

extern "C" void fn_800EC848(void** head, void* node) {
    u32 level = OSDisableInterrupts();
    *(void**)node = *head;
    *head = node;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800EC8B4(void* arg0) {
    f32 value = lbl_80561018;
    *(s32*)((u8*)arg0 + 0x10) = 0;
    *(f32*)((u8*)arg0 + 0x14) = value;
}

extern "C" void Update__Q44nw4r3snd6detail3LfoFi(void* arg0, s32 arg1) {
    f32 temp_f1; s32 var_r4; u32 temp_r0; u32 temp_r5; u32 temp_r6;
    var_r4 = arg1; temp_r6 = *(u32*)((u8*)arg0 + 8); temp_r5 = *(u32*)((u8*)arg0 + 0x10);
    if (temp_r5 < temp_r6) {
        temp_r0 = temp_r5 + var_r4;
        if (temp_r0 <= temp_r6) { *(u32*)((u8*)arg0 + 0x10) = temp_r0; return; }
        *(u32*)((u8*)arg0 + 0x10) = temp_r6; var_r4 -= temp_r6 - temp_r5;
    }
    temp_f1 = *(f32*)((u8*)arg0 + 0x14) + ((*(f32*)((u8*)arg0 + 4) * (f32)var_r4) / lbl_80561020);
    *(f32*)((u8*)arg0 + 0x14) = temp_f1;
    *(f32*)((u8*)arg0 + 0x14) = (f32)(temp_f1 - (f32)(s32)temp_f1);
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

extern "C" void fn_800F27AC(void *);
extern "C" void fn_800ECC58(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x108) = 0;
    ((void (*)(void))fn_800F27AC)();
}

s32 nw4hbm::snd::MemorySoundArchive::detail_GetFileAddress(u32 id) const {
    struct { s32 v[13]; } local;
    if (!fn_800F283C((void *)this, id, 0, &local.v[0])) return 0;
    if (!fn_800F2824((void *)this, local.v[0], &local.v[8])) return 0;
    if (!fn_800F282C((void *)this, local.v[0], local.v[1], &local.v[2])) return 0;
    if (local.v[9] != 0) return 0;
    return local.v[10] + local.v[3] + *(u32 *)((u8 *)this + 0x108);
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
extern "C" s32 fn_800ED0F4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668_noarg();
    return arg0;
}

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

extern "C" void OSCreateAlarm(void*);
extern "C" void OSSetAlarmUserData(void*, void*);
extern "C" void* memset(void*, int, u32);
extern u8 lbl_80323770[];
extern u8 lbl_80323790[];
extern "C" void FreeTrack__Q46nw4hbm3snd6detail20MmlSeqTrackAllocatorFPQ46nw4hbm3snd6detail8SeqTrack(void* arg0, void* arg1) {
    if (arg1 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323770, 0x3B, (const char*)lbl_80323790);
    *(u32*)((u8*)arg1 + 0xB4) = 0;
    if (arg1 != 0) {
        (*(void (**)(void*, s32))(*(u32*)arg1 + 8))(arg1, -1);
        fn_800EC848((void**)((u8*)arg0 + 8), arg1);
    }
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

extern "C" void OSCreateAlarm(void*);
extern "C" void OSSetAlarmUserData(void*, void*);
extern "C" void* memset(void*, int, u32);
extern u8 lbl_80323770[];
extern u8 lbl_80323790[];
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

extern "C" void fn_800EE910(void* alarm) {
    void* alarmTemp = alarm;
    u32 level = OSDisableInterrupts();
    u8* data = (u8*)OSGetAlarmUserData(alarmTemp);
    Warning__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323840, 0x224,
                                    (const char*)lbl_803238C0,
                                    *(s32*)(data + 0x2C));
    data[6] = 1;
    data[7] = 0;
    OSRestoreInterrupts(level);
}

extern "C" void IntervalAlarmHandler__Q34nw4r3snd13RemoteSpeakerFP7OSAlarmP9OSContext(
    void* alarm, void* context) {
    void* alarmTemp = alarm;
    u32 level = OSDisableInterrupts();
    u8* data = (u8*)OSGetAlarmUserData(alarmTemp);
    if (data[8] != 0) {
        OSCancelAlarm(data + 0x38);
        data[6] = 0;
        data[7] = 0;
    }
    data[8] = 0;
    OSRestoreInterrupts(level);
}

extern "C" void* OSGetAlarmUserData(void*);
extern "C" void OSCancelAlarm(void*);
extern "C" void* fn_800EE4F0(void*);
#pragma push
#pragma small_data off
extern u8 lbl_804127A8[];
#pragma pop
extern u8 lbl_8055DE40;
extern "C" void* GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv(void) {
    u8* base = lbl_804127A8;
    if ((s8)lbl_8055DE40 == 0) {
        base[0] = 0;
        u8* p = base + 0x38;
        u8* end = base + 0x2B8;
        do {
            fn_800EE4F0(p);
            p += 0xA0;
        } while (p < end);
        *(s32*)(base + 0x64) = 0;
        *(s32*)(base + 0x104) = 1;
        *(s32*)(base + 0x1A4) = 2;
        *(s32*)(base + 0x244) = 3;
        lbl_8055DE40 = 1;
    }
    return base;
}

extern "C" void fn_800EEB64(u8 *arg0) {
    if (arg0[0] != 0) {
        OSCancelAlarm(arg0 + 8);
        arg0[0] = 0;
    }
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

extern "C" s32 fn_800EF500(void* self) {
    void* iterator;
    if (*(u8*)((u8*)self + 0x16) == 0) return 0;
    iterator = lbl_80412A6C + 4;
    if (self == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80324054, 0x233, (const char*)lbl_80324030);
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(lbl_80412A6C, &iterator, (u8*)self + 0x100);
    *(u8*)((u8*)self + 0x14) = *((u8*)Instance__15EmissionManagerFv() + 0x6c32);
    *(u8*)((u8*)self + 0x17) = 1;
    return 1;
}

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
extern "C" void Pause__Q46nw4hbm3snd6detail9SeqPlayerFb(bool pause, void* self) {
    u32 level;
    void* track;
    int i;
    level = OSDisableInterrupts();
    *(u8*)((u8*)self + 0x18) = pause;
    for (i = 0; i < 16; i++) {
        track = *(void**)((u8*)self + 0x9c + i * 4);
        if (track) PauseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFb(track, pause);
    }
    OSRestoreInterrupts(level);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf(void* self, f32 volume) {
    if (!(volume <= lbl_8056106C)) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x15d, (const char*)lbl_80323BEC);
    u32 level = OSDisableInterrupts();
    *(f32*)((u8*)self + 0x1c) = volume;
    OSRestoreInterrupts(level);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800EF804(void* arg0, f32 farg0) {
    extern f32 lbl_8056106C;
    extern u8 lbl_80323B28[];
    extern u8 lbl_80323C14[];
    if (farg0 != lbl_8056106C) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x164, (const char*)lbl_80323C14);
    }
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x34) = farg0;
    OSRestoreInterrupts(0);
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

extern "C" s32 fn_800F1080(void*, const void*, s32);
extern u8 lbl_80323B94[];
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800EFCD8(void* self, s32 bus, f32 send) {
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

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800EFDFC(void* self, s32 bus, f32 send) {
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323B28, 0x1e0, (const char*)lbl_80323C74, bus, 0, 4);
    u32 level = OSDisableInterrupts();
    *(f32*)((u8*)self + 0x74 + bus * 4) = send;
    OSRestoreInterrupts(level);
}

void fn_800F0750(void) {
    return;
}
extern u8 lbl_803231D8[];
extern "C" s32 fn_800F283C(void *, u32, s32, s32 *);
extern "C" s32 fn_800F2824(void *, s32, void *);
extern "C" s32 fn_800F282C(void *, s32, s32, void *);
extern "C" void *memcpy(void *, const void *, u32);
