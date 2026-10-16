typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

extern "C" s32 fn_80128668(void);
typedef void (*DisposeCallback)(void*, unsigned long, void*);
extern "C" void* Create__Q46nw4hbm3snd6detail9FrameHeapFPvUl(void*);
extern "C" void* Alloc__Q46nw4hbm3snd6detail9FrameHeapFUlPFPvUlPv_vPv(void*, unsigned long, DisposeCallback, void*);
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv(void*, unsigned long, void*);
extern "C" void Destroy__Q46nw4hbm3snd6detail9FrameHeapFv(void*);
extern "C" void* __dt__Q46nw4hbm3snd6detail9FrameHeapFv(void*, int);
extern "C" void* lbl_80325C40;
extern "C" void Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(void*, unsigned long, void*);
extern "C" void DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(void*, unsigned long, void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" s32 fn_800E9B88(void *);
extern "C" s32 fn_800E9B9C(void *);
extern "C" const char lbl_80325C00[];
extern "C" const char lbl_80325C18[];
extern "C" const char lbl_80325C64[];
extern "C" const char lbl_80325C8C[];
extern "C" f32 lbl_805610BC;
extern "C" u8 lbl_80325C50[];
extern "C" s32 detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(s32);

M2C_UNK GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);

extern "C" s32 GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);
extern "C" s32 ConvertLabelStringToId__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPCQ56nw4hbm3snd6detail16SoundArchiveFile10StringTreePCc(void *, void *, s32);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" const char lbl_803247E0[];
extern "C" const char lbl_803247F8[];
extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32);
extern "C" const char lbl_80324390[];
extern "C" const char lbl_803244FC[];
extern "C" const char lbl_80324534[];
extern "C" const char lbl_803245B8[];
extern "C" void fn_800F2004(void *arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x68) = farg0;
    OSRestoreInterrupts((u32)arg0);
}

extern "C" void fn_800F2044(void *arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x6C) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F2084(void* arg0, f32 farg0) {
    u32 level = OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x20) = farg0;
    OSRestoreInterrupts(level);
}

void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F20C4(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 3) {
        if (0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x295, lbl_803244FC, bus, 0, 3);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x24 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F2160(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 4) {
        if (0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x2A3, lbl_80324534, bus, 0, 4);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x30 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800F21FC(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 4) {
        if (0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x2B0, lbl_80324534, bus, 0, 4);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x40 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

s32 GetVariablePtr__Q46nw4hbm3snd6detail8SeqTrackFi(void *self, s32 index) {
    if (index < 0 || index > 0x10) {
        if (0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x2EB, lbl_803245B8, index, 0, 0x10);
    }
    if (index < 0x10) return (s32)((u8 *)self + 0x94 + index * 2);
    return 0;
}

extern "C" void fn_800F26D8(void *arg0) {
    extern s32 lbl_80324848;
    *(s32 *)arg0 = (s32)&lbl_80324848;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 8) = 0x2F;
    *(u8 *)((u8 *)arg0 + 9) = 0;
}

extern "C" s32 fn_800F26FC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F273C(void *arg0) {
    s32 val = *(s32 *)((u8 *)arg0 + 4);
    s32 neg = -val;
    return (neg | val) >> 31 & 1;
}

void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi_800F2750(void *arg0, s32 flag) {
    if (flag == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803247E0, 0x46, lbl_803247F8);
    }
    *(s32 *)((u8 *)arg0 + 4) = flag;
}

void fn_800F27AC(void *arg0) {
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 8) = 0x2F;
    *(u8 *)((u8 *)arg0 + 9) = 0;
}

extern "C" s32 fn_800F27C4(void *arg0) {
    return GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);
extern "C" s32 fn_800F27CC(void *arg0) {
    return GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(*(s32*)((u8*)arg0 + 4));
}

void fn_800F27D4(void *arg0, s32 arg1) {
    void *r3 = *(void**)((u8*)arg0 + 4);
    s32 r4 = *(s32*)((u8*)r3 + 0x34);
    ConvertLabelStringToId__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPCQ56nw4hbm3snd6detail16SoundArchiveFile10StringTreePCc(r3, (void*)r4, arg1);
}

M2C_UNK GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(s32);
extern "C" s32 fn_800F27E4(void *arg0) {
    return GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(s32);
extern "C" s32 fn_800F27EC(void *arg0) {
    return ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(*(s32*)((u8*)arg0 + 4));
}

extern "C" void fn_800F2D28(void *arg0) {
    *(s32*)((u8*)arg0 + 0x28) = 0;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *(s32*)((u8*)arg0 + 0x30) = 0;
    *(s32*)((u8*)arg0 + 0x34) = 0;
    *(s32*)((u8*)arg0 + 0x38) = 0;
    *(s32*)((u8*)arg0 + 0x3C) = 0;
    *(s32*)((u8*)arg0 + 0x40) = 0;
}

extern "C" s32 fn_800F420C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void *arg0) {
 void **obj;
 obj=*(void ***)((u8*)arg0+0x21c);
 if(obj && ((s32(*)(void*))((void**)*(void**)obj)[0x54/4])(obj)) {
 obj=*(void***)((u8*)arg0+0x21c);
 if(((s32(*)(void*))((void**)*(void**)obj)[0x28/4])(obj)) {
 obj=*(void***)((u8*)arg0+0x21c);
 ((s32(*)(void*,s32,s32))((void**)*(void**)obj)[0x4c/4])(obj,0,0);
 } else {
 obj=*(void***)((u8*)arg0+0x21c);
 ((s32(*)(void*))((void**)*(void**)obj)[0x48/4])(obj);
 }
 }
}

extern "C" s32 fn_800F4CC4(s32 arg0, s32 arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" s32 fn_800F4D04(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4D44(s32 arg0, s32 arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" s32 fn_800F4D84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4DC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4E04(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4E44(s32 arg0, s32 arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" s32 fn_800F4E84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4EC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800F4F04(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void fn_800F4F7C(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void fn_800F4FF4(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

void InvalidateData__Q34nw4r3snd18SoundArchivePlayerFPCvPCv(void* self, unsigned long start, unsigned long end) {
    unsigned long* entries = *(unsigned long**)((char*)self + 0x14);
    unsigned long i = 0, offset = 0;
    if (!entries) return;
    do {
        unsigned long* entry = (unsigned long*)((char*)entries + offset);
        unsigned long value = entry[1];
        if (value >= start && value <= end) entry[1] = 0;
        offset += 8; ++i;
    } while (i < entries[0]);
}

void InvalidateData__Q34nw4r3snd18SoundArchivePlayerFPCvPCv_800F6F18(void* self, unsigned long start, unsigned long end) {
    unsigned long* entries = *(unsigned long**)((char*)self + 0x14);
    unsigned long i = 0, offset = 0;
    if (!entries) return;
    do {
        unsigned long* entry = (unsigned long*)((char*)entries + offset);
        unsigned long value = entry[2];
        if (value >= start && value <= end) entry[2] = 0;
        offset += 8; ++i;
    } while (i < entries[0]);
}

extern "C" void fn_800FDE60(void);
extern "C" void CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl(unsigned long);
extern "C" void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void);
void fn_800F7110(void* self, unsigned long taskId) {
    fn_800FDE60();
    CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl(taskId);
}

extern "C" s32 fn_800F76C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void Cancel__Q46nw4hbm3snd18SoundArchivePlayer11SeqLoadTaskFv(void* self) {
    void* mutex = *(void**)((char*)self + 0x2c);
    OSLockMutex(mutex);
    if (*(void**)((char*)self + 0x10) != 0)
        Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv();
    OSUnlockMutex(mutex);
}

void Cancel__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv(void* self) {
    void* mutex = *(void**)((u8*)self + 0x24);
    void* sound = *(void**)((u8*)self + 0x10);
    OSLockMutex(mutex);
    *(u32*)((u8*)self + 0x1c) = 0;
    if (sound != 0 && ((s32 (*)(void*))(*(u32*)(*(u32*)sound + 0x54)))(sound) != 0) {
        if (((s32 (*)(void*))(*(u32*)(*(u32*)sound + 0x28)))(sound) != 0) {
            ((void (*)(void*, s32, s32))(*(u32*)(*(u32*)sound + 0x4c)))(sound, 0, 0);
        } else {
            ((void (*)(void*))(*(u32*)(*(u32*)sound + 0x48)))(sound);
        }
    }
    OSUnlockMutex(mutex);
}

void Cancel__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv_800F7FEC(void* self) {
    void* mutex = *(void**)((u8*)self + 0x3c);
    void* sound = *(void**)((u8*)self + 0x14);
    OSLockMutex(mutex);
    *(u32*)((u8*)self + 0x10) = 0;
    if (sound != 0 && ((s32 (*)(void*))(*(u32*)(*(u32*)sound + 0x54)))(sound) != 0) {
        if (((s32 (*)(void*))(*(u32*)(*(u32*)sound + 0x28)))(sound) != 0) {
            ((void (*)(void*, s32, s32))(*(u32*)(*(u32*)sound + 0x4c)))(sound, 0, 0);
        } else {
            ((void (*)(void*))(*(u32*)(*(u32*)sound + 0x48)))(sound);
        }
    }
    OSUnlockMutex(mutex);
}

extern "C" void *__dt__Q36nw4hbm3snd9SoundHeapFv(void*, int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8114(void *arg0, int arg1) {
 if(arg0) { __dt__Q36nw4hbm3snd9SoundHeapFv(arg0,0); if(arg1>0) ((void(*)(void*))fn_80128668)(arg0); }
 return arg0;
}

extern "C" s32 fn_800F816C(s32 arg0, s32 arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" s32 fn_800F81AC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F81EC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800F822C(s32 arg0) {
    detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(arg0 - 0xC);
}

extern "C" s32 fn_800F65F0(s32);
extern "C" void fn_800F8234(s32 arg0) {
    fn_800F65F0(arg0 - 0xC);
}

extern "C" s32 __dt__Q36nw4hbm3snd18SoundArchivePlayerFv(s32);
extern "C" void fn_800F823C(s32 arg0) {
    __dt__Q36nw4hbm3snd18SoundArchivePlayerFv(arg0 - 0xC);
}

extern "C" void detail_AttachSound__Q36nw4hbm3snd11SoundHandleFPQ46nw4hbm3snd6detail10BasicSound(void **arg0, void *arg1) {
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325C00, 0x55, lbl_80325C18);
    }
    *arg0 = arg1;
    if (fn_800E9B88(arg1) != 0) {
        fn_800E9B9C(*arg0);
    }
    *(void **)((u8 *)*arg0 + 8) = arg0;
}

void DetachSound__Q34nw4r3snd11SoundHandleFv(void **arg0) {
 void *p=*arg0;
 if(p) {
  if(*(u32*)((u8*)p+8)==(u32)arg0) *(u32*)((u8*)p+8)=0;
  p=*arg0;
  if(*(u32*)((u8*)p+0xc)==(u32)arg0) *(u32*)((u8*)p+0xc)=0;
 }
 if(*arg0==0) return;
 *arg0=0;
}

extern "C" void* __dt__Q36nw4hbm3snd9SoundHeapFv(void* arg0, int arg1) {
    void* this_ = arg0;
    int flag = arg1;
    if (this_ != 0) {
        *(void**)this_ = (void*)lbl_80325C40;
        Destroy__Q46nw4hbm3snd6detail9FrameHeapFv((u8*)this_ + 0x1C);
        __dt__Q46nw4hbm3snd6detail9FrameHeapFv((u8*)this_ + 0x1C, -1);
        if (flag > 0) {
            ((void (*)(void*))fn_80128668)(this_);
        }
    }
    return this_;
}

extern "C" void fn_800F83C8(void* arg0) {
    Create__Q46nw4hbm3snd6detail9FrameHeapFPvUl((u8*)arg0 + 0x1C);
}

extern "C" void fn_800F83D0(void* arg0) {
    Destroy__Q46nw4hbm3snd6detail9FrameHeapFv((u8*)arg0 + 0x1C);
}

extern "C" void* fn_800F83D8(void* arg0, unsigned long arg1) {
    void* mutex = (u8*)arg0 + 4;
    OSLockMutex(mutex);
    void* result = Alloc__Q46nw4hbm3snd6detail9FrameHeapFUlPFPvUlPv_vPv(
        (u8*)arg0 + 0x1C, arg1, DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv, 0);
    OSUnlockMutex(mutex);
    return result;
}

extern "C" void DisposeCallbackFunc__Q36nw4hbm3snd9SoundHeapFPvUlPv(void* arg0, unsigned long arg1, void* arg2) {
    Dispose__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv(arg0, arg1, arg2);
    DisposeWave__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPvUlPv_800EB214(arg0, arg1, arg2);
}

extern "C" void fn_800F8520(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800F877C(void *this_, f32 farg0) {
    if (!(farg0 >= lbl_805610BC)) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x99, lbl_80325C64);
    *(f32 *)&((u8 *)this_)[0x28] = farg0;
}

extern "C" s32 fn_800F87E8(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x30); }

extern "C" u8 fn_800F87F0(void *arg0) { return *(u8 *)((u8 *)arg0 + 0x2C); }

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800F87F8(s32 arg0, s32 arg1) {
    s32 valid = 0;
    if (arg1 >= 0 && arg1 < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x103, lbl_80325C8C, arg1, 0, 4);
    return *(f32 *)((u8 *)(arg0 + arg1 * 4) + 0x38);
}

extern "C" void NWC24Data_Init(void* arg0) {
    *(int*)arg0 = 0;
    *((int*)arg0 + 1) = 0;
}

extern "C" s32 fn_800FB374(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" const char lbl_80326B68[];
extern "C" const char lbl_80326B8C[];
extern "C" const char lbl_80326768[];
extern "C" const char lbl_8032687C[];
extern "C" s32 lbl_8041506C;
extern "C" void UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv(void) {
    void **end = (void **)((u8 *)&lbl_8041506C + 4);
    void *node = *end;
    while (node != end) {
        void *player = node;
        node = *(void **)node;
        if (player == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326B8C, 0x23D, lbl_80326B68);
        UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv((u8 *)player - 8);
    }
}

extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_800FC508(void) {
    void *node = *(void **)((u8 *)&lbl_8041506C + 4); void *end = (u8 *)&lbl_8041506C + 4;
    while (node != end) { void *player = node; node = *(void **)node; if (!player) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326B8C, 0x23D, lbl_80326B68); void **vt = *(void ***)((u8 *)player - 8); ((void (*)(void *))*(void **)((u8 *)vt + 0x10))((u8 *)player - 8); }
    if (lbl_8041506C) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x2EE, lbl_8032687C);
}

extern "C" void fn_800FC5B8(void *arg0, f32 value) {
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)arg0 + 0x45C) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 fn_800FC5F8(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x45C); }

extern "C" void fn_800FC600(void *arg0, f32 value) { u32 token = OSDisableInterrupts(); *(f32 *)((u8 *)arg0 + 0x460) = value; OSRestoreInterrupts(token); }

extern "C" f32 fn_800FC640(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x460); }

extern "C" const char lbl_803268AC[];
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC648(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 3) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x309, lbl_803268AC, bus, 0, 3);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x464 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC6E4(void *self, s32 bus) {
    if (bus < 0 || bus >= 3) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x310, lbl_803268AC, bus, 0, 3);
    }
    return *(f32 *)((u8 *)self + 0x464 + bus * 4);
}

extern "C" void fn_800FC76C(void *self, s32 value) {
    u32 token = OSDisableInterrupts();
    *(s32 *)((u8 *)self + 0x458) = value;
    OSRestoreInterrupts(token);
}

