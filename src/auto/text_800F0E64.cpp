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
extern "C" const char lbl_80324E88[];
extern "C" const char lbl_803250C8[];
extern "C" const char lbl_80324EA4[];
extern "C" const char lbl_80325640[];
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *);
extern "C" void fn_800EBB88(void*);
extern "C" f32 lbl_805610B8;
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, u32);
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
extern "C" f32 lbl_8056107C;
extern "C" const char lbl_803244D4[];
  extern "C" u8 lbl_80325C50[];
  extern "C" s32 detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(s32);
  extern "C" u8 lbl_80325D48[];
  extern "C" u8 lbl_80325D6C[];
  extern "C" u8 lbl_80323834[];
  extern "C" u8 lbl_80323810[];
  extern "C" u8 lbl_803263B8[];
  extern "C" u8 lbl_80326400[];
  extern "C" u8 lbl_8055DE60;
  extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
  extern "C" void *GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv(void);
  extern "C" s32 Shutdown__Q46nw4hbm3snd6detail11SoundThreadFv(void);
  extern "C" void *fn_800FE648(void);
  extern "C" s32 Destroy__Q46nw4hbm3snd6detail10TaskThreadFv(void);
  extern "C" void *GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv(void);
  extern "C" void fn_800EEB64(void *);
  extern "C" void *Instance__15EmissionManagerFv(void);
    extern "C" void fn_800E2F84(void *);
    #pragma push
    #pragma small_data off
    extern u8 lbl_80412CC8[];
    extern u8 lbl_80412CB8[];
    #pragma pop
    extern u8 lbl_8055DE68;
    extern "C" void* __dt__10TitleSceneFv(void*, s32);
    extern "C" void __register_global_object(void*, void*, void*, void*);
    extern "C" void OSSendMessage(void*, void*, u32);
extern "C" void OSInitMutex(void*);
extern "C" u64 impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(void *, u32);
extern "C" void *GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(s32, u32, void*);
extern "C" const char lbl_80324CB0[];
extern "C" char lbl_805598A0;
extern "C" void fn_800FA6E8(void);
extern "C" void fn_800FA7E0(void*);
extern "C" void OSInitMessageQueue(void*, void*, s32);
extern "C" void RegisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNodePFv_v(void*, void*, void (*)(void));
extern "C" void UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(void*, void*);
extern "C" void memset(void*, s32, u32);
    extern "C" void ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" void detail_UpdateBufferAllPlayers__Q36nw4hbm3snd10WavePlayerFv(void);
    extern "C" void UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv(void);

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
extern "C" void fn_800F0E64(void **arg0) {
    void *p = *arg0;
    if (p && *(void **)((char *)p + 0x1E0) == arg0)
        *(void **)((char *)p + 0x1E0) = 0;
    if (*arg0)
        *arg0 = 0;
}

extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi_800F0E9C(void *arg0, int arg1) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern const char lbl_80324390[];
    extern const char lbl_803243A4[];
    int valid = arg1 >= 0 && arg1 <= 0x10;
    if (!valid)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x25, lbl_803243A4, arg1, 0, 0x10);
    *((unsigned char *)arg0 + 4) = arg1;
}

extern "C" void fn_800F1080(void *arg0, int arg1, int arg2) {
    *(int *)((char *)arg0 + 0x50) = arg1;
    *(int *)((char *)arg0 + 0x54) = arg1 + arg2;
}

extern "C" void UpdateChannelLength__Q46nw4hbm3snd6detail8SeqTrackFv(void *arg0) {
    extern void Release__Q46nw4hbm3snd6detail7ChannelFv(void *);
    extern void fn_800EA880(void *, int);
    void *channel = *(void **)((char *)arg0 + 0xB8);
    while (channel != 0) {
        int length = *(int *)((char *)channel + 0xD4);
        if (length > 0) {
            length--;
            *(int *)((char *)channel + 0xD4) = length;
            if (length == 0)
                Release__Q46nw4hbm3snd6detail7ChannelFv(channel);
        }
        if (*(unsigned char *)((char *)channel + 0x3C) == 0)
            fn_800EA880(channel, 1);
        channel = *(void **)((char *)channel + 0xE4);
    }
}

extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void *, u8);
extern "C" void fn_800EAD00(void *);
extern "C" void FreeAllChannel__Q46nw4hbm3snd6detail8SeqTrackFv(void *arg0) {
    u32 token = OSDisableInterrupts();
    void *channel = *(void **)((char *)arg0 + 0xB8);
    while (channel) {
        fn_800EAD00(channel);
        channel = *(void **)((char *)channel + 0xE4);
    }
    *(void **)((char *)arg0 + 0xB8) = 0;
    OSRestoreInterrupts(token);
}

extern "C" void Stop__Q46nw4hbm3snd6detail7ChannelFv(void *);
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(void *, int);
extern "C" void SetMute__Q46nw4hbm3snd6detail8SeqTrackFQ36nw4hbm3snd7SeqMute(void *arg0, int arg1) {
    u32 token = OSDisableInterrupts();
    switch (arg1) {
    case 0:
        *(u8 *)((u8 *)arg0 + 0x5C) = 0;
        break;
    case 3: {
        u32 inner = OSDisableInterrupts();
        void *channel = *(void **)((u8 *)arg0 + 0xB8);
        while (channel) { fn_800EAD00(channel); Stop__Q46nw4hbm3snd6detail7ChannelFv(channel); channel = *(void **)((u8 *)channel + 0xE4); }
        *(void **)((u8 *)arg0 + 0xB8) = 0; OSRestoreInterrupts(inner); *(u8 *)((u8 *)arg0 + 0x5C) = 1; break;
    }
    case 2: {
        ReleaseAllChannel__Q46nw4hbm3snd6detail8SeqTrackFi(arg0, -1);
        u32 inner = OSDisableInterrupts();
        u32 channel = (u32)*(void **)((u8 *)arg0 + 0xB8);
        while (channel) { fn_800EAD00((void *)channel); channel = (u32)*(void **)(channel + 0xE4); }
        *(void **)((u8 *)arg0 + 0xB8) = 0; OSRestoreInterrupts(inner); *(u8 *)((u8 *)arg0 + 0x5C) = 1; break;
    }
    case 1: *(u8 *)((u8 *)arg0 + 0x5C) = 1; break;
    }
    OSRestoreInterrupts(token);
}

extern "C" void fn_800F1E50(void *arg0, f32 value) {
    u32 token = OSDisableInterrupts();
    *(f32 *)((char *)arg0 + 8) = value;
    OSRestoreInterrupts(token);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_800F1E90(void* arg0, f32 farg0) {
    if (!(farg0 >= *(volatile f32*)&lbl_8056107C)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390, 0x25B, lbl_803244D4);
    }
    OSDisableInterrupts();
    *(f32*)((char*)arg0 + 0xC) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F1F04(void* arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((char*)arg0 + 0x10) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F1F44(void* arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((char*)arg0 + 0x14) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" f32 lbl_8056107C;
extern "C" void fn_800F1F84(void* arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((char*)arg0 + 0x18) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F1FC4(void *arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32 *)((char *)arg0 + 0x1C) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_800F2004(void *arg0, f32 farg0) {
    OSDisableInterrupts();
    *(f32*)((u8*)arg0 + 0x68) = farg0;
    ((void (*)(void))OSRestoreInterrupts)();
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

extern "C" s32 GetVariablePtr__Q46nw4hbm3snd6detail8SeqTrackFi(void *self, s32 index) {
    s32 valid = 0;
    if (index >= 0 && index <= 0x10) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80324390, 0x2EB, (const char *)lbl_803245B8, index, 0, 0x10);
    if (index < 0x10) return (s32)((u8 *)self + 0x94 + index * 2);
    return 0;
}

extern "C" void *fn_800F0728(void *, s32, void *);
extern "C" void fn_800EA8A0(void *, s32, s32, f32);
extern "C" void SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern "C" f32 lbl_80561080;
extern "C" f64 lbl_805610A0;
extern "C" extern u32 OSDisableInterrupts(void);
extern "C" s32 lbl_802F4DB8[];
extern "C" void fn_800F2330(void *a, s32 key, s32 vel, s32 arg3, s32 reuse) {
 u8 *p=(u8*)a; void *c=0;
 if(key<0||key>127) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390,0x30a,lbl_80324390+0x268,key,0,127);
 if(vel<0||vel>127) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324390,0x30b,lbl_80324390+0x2a0,vel,0,127);
 if(reuse && (c=*(void**)(p+0xb8))) {
  *(u32*)((u8*)c+0xcc)=(u8)key;
  f32 x=((f32)vel)/lbl_80561080; *(f32*)((u8*)c+0xb4)=x*x;
 }
 if(!c) {
  s32 args[9]; int i; for(i=0;i<9;i++) args[i]=lbl_802F4DB8[i];
  args[0]=*(s32*)(p+0x64); args[1]=key; args[2]=vel; args[3]=reuse?-1:arg3;
  args[4]=(s8)p[0x85]; args[5]=*(u8*)(*(u8**)(p+0xb4)+0x91)+p[0x88];
  args[6]=*(s32*)(*(u8**)(p+0xb4)+0x8c); args[8]=(s32)p;
  c=fn_800F0728(*(void**)(p+0xb4),*(s32*)(p+0x60),args); if(!c)return;
  u32 t=OSDisableInterrupts(); *(void**)((u8*)c+0xe4)=*(void**)(p+0xb8); *(void**)(p+0xb8)=c; OSRestoreInterrupts(t);
 }
 if(p[0x8b]!=255) SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8b]);
 if(p[0x8c]!=255) SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8c]);
 if(p[0x8d]!=255) SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8d]);
 if(p[0x8e]!=255) SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((u8*)c+8,p[0x8e]);
 f32 pitch=*(f32*)(p+0x7c); if(p[0x5f]) pitch+=(f32)((s32)p[0x89]-key);
 if(!p[0x8a]) { if(!arg3) Warning__Q26nw4hbm2dbFPCciPCce(lbl_80324390,0x358,lbl_80324390+0x2e4); fn_800EA8A0(c,arg3,0,pitch); }
 else { s32 n=p[0x8a]*p[0x8a]; f32 scale=pitch>lbl_8056107C?pitch:-pitch; fn_800EA8A0(c,(s32)((f32)n*scale)/32*5,1,pitch); }
 p[0x89]=(u8)key;
 u16 total=*(u16*)((u8*)c+0xc6), cur=*(u16*)((u8*)c+0xc8); u32 enabled=p[0x5d]!=0; u8 val;
 if(cur>=total) val=*((u8*)c+0xc5); else {u8 st=*((u8*)c+0xc4); val=st+(cur*(*((u8*)c+0xc5)-st))/total;}
 *((u8*)c+0xc4)=val; *((u8*)c+0xc5)=enabled?0:255; *(u16*)((u8*)c+0xc6)=0; *(u16*)((u8*)c+0xc8)=0;
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

extern "C" s32 fn_800F27D4(void *arg0, s32 arg1) {
    void *r3 = *(void **)((u8 *)arg0 + 4);
    return ConvertLabelStringToId__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPCQ56nw4hbm3snd6detail16SoundArchiveFile10StringTreePCc(r3, *(void **)((u8 *)r3 + 0x34), arg1);
}

M2C_UNK GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(s32);
extern "C" s32 fn_800F27E4(void *arg0) {
    return GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(s32);
extern "C" s32 fn_800F27EC(void *arg0) {
    return ReadSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9SoundInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(s32);
extern "C" s32 fn_800F27F4(void *arg0) {
    return ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(*(s32*)((u8*)arg0 + 4));
}

extern "C" s32 ReadStrmSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13StrmSoundInfo(s32);
extern "C" s32 fn_800F27FC(void *arg0) {
    return ReadStrmSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13StrmSoundInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(s32);
extern "C" s32 fn_800F2804(void *arg0) {
    return ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(*(s32*)((u8*)arg0 + 4));
}

extern "C" s32 ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo(s32);
extern "C" s32 fn_800F280C(void *arg0) {
    return ReadPlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive10PlayerInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(s32);
extern "C" s32 fn_800F2814(void *arg0) {
    return ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(s32);
extern "C" s32 fn_800F281C(void *arg0) {
    return ReadBankInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8BankInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(s32);
extern "C" s32 fn_800F2824(void *arg0) {
    return ReadGroupInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive9GroupInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(s32);
extern "C" s32 fn_800F282C(void *arg0) {
    return ReadGroupItemInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive13GroupItemInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(s32);
extern "C" s32 fn_800F2834(void *arg0) {
    return ReadFileInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive8FileInfo(*(s32*)((u8*)arg0 + 4));
}

M2C_UNK ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(s32);
extern "C" s32 fn_800F283C(void *arg0) {
    return ReadFilePos__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlUlPQ46nw4hbm3snd12SoundArchive7FilePos(*(s32*)((u8*)arg0 + 4));
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

extern "C" void SetInfoChunk__Q46nw4hbm3snd6detail22SoundArchiveFileReaderFPCvUl(void *self, const void *chunk, u32 size) {
    extern const char lbl_80324868[];
    const char *base = lbl_80324868;
    const u32 *data = (const u32 *)chunk;
    if (data == 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(base + 0), 0x78, base + 0x198);
    if (data[0] != 0x494E464FU)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)(base + 0), 0x7B, base + 0x1C4);
    *(const void **)((char *)self + 0x28) = (const u8 *)data + 8;
}

extern "C" s32 GetSoundType__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(void *arg0, u32 arg1) {
    u8 *reader = (u8 *)arg0;
    register u8 *ref = *(u8 **)(reader + 0x28);
    u8 type;
    u8 *info;
    u32 offset;
    extern const char lbl_80324DE4[];
    extern const char lbl_80324E10[];
    extern char lbl_805598C8;
    extern char lbl_805598D0;
    if (ref[1] != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598C8, 0x6F, lbl_80324DE4);
    info = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0], *(u32 *)(ref + 4), ref);
    if (!info) return 0;
    if (arg1 >= *(u32 *)info) return 0;
    if (*(u16 *)(reader + 6) >= 0x101) {
        offset = arg1 * 8;
        ref = *(u8 **)(reader + 0x28);
        if (info[offset + 5] != 0) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598D0, 0x6F, lbl_80324E10);
        type = info[offset + 5];
        info = (u8 *)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(info[offset + 4], *(u32 *)(info + offset + 8), ref);
        if (!info) return 0;
        type = info[0x16];
    } else { offset = arg1 * 8; type = info[offset + 5]; }
    switch (type) { case 1: return 1; case 2: return 2; case 3: return 3; default: return 0; }
}

extern "C" s32 ReadSeqSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive12SeqSoundInfo(void *self, u32 index, void *info) {
    extern const char lbl_80324BD4[];
    extern char lbl_80559878;
    u64 result = impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(self, index);
    u32 type = (u32)(result >> 32);
    u32 offset = (u32)result;
    void *base = *(void **)((char *)self + 0x28);
    if ((u8)type != 1)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559878, 0x70, lbl_80324BD4);
    void *data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(type, offset, base);
    if (!data)
        return 0;
    *(u32 *)((char *)info + 0) = *(u32 *)((char *)data + 0);
    *(u32 *)((char *)info + 4) = *(u32 *)((char *)data + 4);
    *(u32 *)((char *)info + 12) = *(u8 *)((char *)data + 12);
    *(u32 *)((char *)info + 8) = *(u32 *)((char *)data + 8);
    return 1;
}

extern "C" s32 ReadWaveSoundInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUlPQ46nw4hbm3snd12SoundArchive13WaveSoundInfo(void *self, u32 index, void *info) {
    extern const char lbl_80324B7C[];
    extern char lbl_80559868;
    u64 result = impl_GetSoundInfoOffset__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFUl(self, index);
    u32 type = (u32)(result >> 32);
    u32 offset = (u32)result;
    void *base = *(void **)((char *)self + 0x28);
    if ((u8)type != 3)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559868, 0x72, lbl_80324B7C);
    void *data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(type, offset, base);
    if (!data)
        return 0;
    *(u32 *)((char *)info + 0) = *(u32 *)((char *)data + 0);
    *(u32 *)((char *)info + 4) = *(u8 *)((char *)data + 8);
    return 1;
}

extern "C" s32 ReadSoundArchivePlayerInfo__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPQ46nw4hbm3snd12SoundArchive22SoundArchivePlayerInfo(void *arg0, void *arg1) {
    extern const char lbl_80324D08[];
    extern char lbl_805598B0;
    register void *ref = *(void **)((char *)arg0 + 0x28);
    register void *out = arg1;
    void *data;
    if (*((u8 *)ref + 0x29) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598B0, 0x6f, lbl_80324D08);
    data = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)ref + 0x28), *(u32 *)((char *)ref + 0x2c), ref);
    if (out == 0) return 0;
    *(u32 *)((char *)out + 0x00) = *(u16 *)((char *)data + 0x00);
    *(u32 *)((char *)out + 0x04) = *(u16 *)((char *)data + 0x02);
    *(u32 *)((char *)out + 0x08) = *(u16 *)((char *)data + 0x04);
    *(u32 *)((char *)out + 0x0c) = *(u16 *)((char *)data + 0x06);
    *(u32 *)((char *)out + 0x10) = *(u16 *)((char *)data + 0x08);
    *(u32 *)((char *)out + 0x14) = *(u16 *)((char *)data + 0x0a);
    *(u32 *)((char *)out + 0x18) = *(u16 *)((char *)data + 0x0c);
    return 1;
}

extern "C" const char lbl_80324CDC[];
extern "C" char lbl_805598A8;
extern "C" const char lbl_80324D08[];
extern "C" char lbl_805598B0;
extern "C" s32 GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(void *arg0) {
    void *data = *(void **)((char *)arg0 + 0x28);
    void *p;
    if (*((u8 *)data + 0x11) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A8, 0x6f, lbl_80324CDC);
    p = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*((u8 *)data + 0x10), *(u32 *)((char *)data + 0x14), data);
    if (p == 0)
        return 0;
    return *(s32 *)p;
}

extern "C" s32 GetGroupCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(void *this_) {
 void *pData;
 void *p;
 pData = *(void**)((u8*)this_ + 0x28);
 if (((u8*)pData)[0x21] != 0) {
   Panic__Q26nw4hbm2dbFPCciPCce(&lbl_805598A0, 0x6F, lbl_80324CB0);
 }
 p = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(((u8*)pData)[0x20], *(u32*)((u8*)pData + 0x24), pData);
 if (p == 0) return 0;
 return *(s32*)p - 1;
}

extern "C" void *fn_800F41D0(void *arg0, s32 arg1) {
 *(s32*)((u8*)arg0 + 0x18) = arg1;
 *(s32*)((u8*)arg0 + 0x21C) = 0;
 OSInitMutex(arg0);
 return arg0;
}

extern "C" s32 fn_800F420C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void *arg0) {
    void **obj;
    obj = *(void ***)((u8 *)arg0 + 0x21c);
    if (obj && ((s32 (*)(void *))((void **)*(void **)obj)[0x54 / 4])(obj)) {
        obj = *(void ***)((u8 *)arg0 + 0x21c);
        if (((s32 (*)(void *))((void **)*(void **)obj)[0x28 / 4])(obj)) {
            obj = *(void ***)((u8 *)arg0 + 0x21c);
            ((s32 (*)(void *, s32, s32))((void **)*(void **)obj)[0x4c / 4])(obj, 0, 0);
        } else {
            obj = *(void ***)((u8 *)arg0 + 0x21c);
            ((s32 (*)(void *))((void **)*(void **)obj)[0x48 / 4])(obj);
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

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F24(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void fn_800F4F7C(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F4F9C(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void fn_800F4FF4(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F5014(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" s32 GetRequiredStrmBufferSize__Q36nw4hbm3snd18SoundArchivePlayerFPCQ36nw4hbm3snd12SoundArchive(void *self, void *archive) {
    s32 info[8];
    if (archive == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x119, lbl_80324EA4);
    s32 result = 0;
    if (((s32 (*)(void *, void *))fn_800F2814)(archive, info) != 0)
        result = info[4];
    return result * 0xA000;
}

extern "C" s32 GetSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFUl(void *arg0, u32 arg1) {
    struct SoundArchivePlayer {
        u8 pad[0x70];
        u32 playerCount;
        void *players;
    };
    SoundArchivePlayer *self = (SoundArchivePlayer *)arg0;
    if (arg1 >= self->playerCount) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324E88, 0x2B2, lbl_803250C8, arg1, 0);
    }
    return (s32)((u8 *)self->players + arg1 * 0x48);
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
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *);
extern "C" const char lbl_80325640[];
extern "C" const char lbl_80324E88[];
extern "C" const char lbl_80324EA4[];
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void detail_SortPriorityList__Q36nw4hbm3snd11SoundPlayerFv(void *);
extern "C" void Update__Q36nw4hbm3snd11SoundPlayerFv(void *);
extern "C" void StopAllSound__Q36nw4hbm3snd11SoundPlayerFi(void *, s32);
extern "C" void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(void *, void *);
#pragma push
#pragma small_data off
  extern u8 lbl_803262E8[];
  extern u8 lbl_803262C4[];
  extern u8 lbl_803262B8[];
  extern u8 lbl_80326294[];
  extern u8 lbl_80326288[];
  extern u8 lbl_80326264[];
#pragma pop
extern "C" void Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv(void);
extern "C" void fn_800F7110(void *self, unsigned long taskId) {
    unsigned long id = taskId;
    void* manager = ((void* (*)(void))fn_800FDE60)();
    ((void (*)(void*, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(manager, id);
}

extern "C" void fn_800F768C(void *self, unsigned long taskId) {
    unsigned long id = taskId;
    void* manager = ((void* (*)(void))fn_800FDE60)();
    ((void (*)(void*, unsigned long))CancelByTaskId__Q46nw4hbm3snd6detail11TaskManagerFUl)(manager, id);
}

extern "C" s32 fn_800F76C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void* LoadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatable(void*, unsigned int, void*);
extern "C" void* __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(void*, void*);
extern "C" void* GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(void*);
extern "C" void Execute__Q46nw4hbm3snd18SoundArchivePlayer11SeqLoadTaskFv(void* arg0) {
    char buffer[0x230];
    char reader[8];
    void* callback;
    void* mutex;
    void* result;
    void* base;

    fn_800F41D0(buffer, *(s32*)((char*)arg0 + 0x14));
    mutex = *(void**)((char*)arg0 + 0x2c);
    OSLockMutex(mutex);
    *(void**)((char*)arg0 + 0x10) = buffer;
    OSUnlockMutex(mutex);
    result = LoadFile__Q46nw4hbm3snd6detail18SoundArchiveLoaderFUlPQ36nw4hbm3snd22SoundMemoryAllocatable(buffer, *(u32*)((char*)arg0 + 0x18), *(void**)((char*)arg0 + 0x20));
    mutex = *(void**)((char*)arg0 + 0x2c);
    OSLockMutex(mutex);
    *(void**)((char*)arg0 + 0x10) = 0;
    OSUnlockMutex(mutex);
    if (result == 0) {
        callback = *(void**)((char*)arg0 + 0x24);
        if (callback) ((void (*)(s32, void*, s32, void*))callback)(0, 0, 0, *(void**)((char*)arg0 + 0x28));
        fn_800F420C((s32)buffer, -1);
        return;
    }
    __ct__Q46nw4hbm3snd6detail13SeqFileReaderFPCv(reader, result);
    base = (void*)GetBaseAddress__Q46nw4hbm3snd6detail13SeqFileReaderCFv(reader);
    callback = *(void**)((char*)arg0 + 0x24);
    if (callback) ((void (*)(s32, void*, s32, void*))callback)(1, base, *(s32*)((char*)arg0 + 0x1c), *(void**)((char*)arg0 + 0x28));
    fn_800F420C((s32)buffer, -1);
}

extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer11SeqLoadTaskFv(void* self) {
    void* mutex = *(void**)((char*)self + 0x2c);
    OSLockMutex(mutex);
    if (*(int*)((char*)self + 0x10))
        Cancel__Q46nw4hbm3snd6detail18SoundArchiveLoaderFv();
    OSUnlockMutex(mutex);
}

void Cancel__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv(void *arg0) {
    class SoundLike {
    public:
        virtual void v0() {} virtual void v1() {} virtual void v2() {} virtual void v3() {} virtual void v4() {} virtual void v5() {} virtual void v6() {} virtual void v7() {} virtual void v8() {} virtual void v9() {} virtual int v10() {} virtual void v11() {} virtual void v12() {} virtual void v13() {} virtual void v14() {} virtual void v15() {} virtual void v16() {} virtual void v17() {} virtual void v18() {} virtual void v19() {} virtual void v20() {} virtual int v21() {} };
    void *mutex = *(void **)((char *)arg0 + 0x24);
    SoundLike *sound;
    OSLockMutex(mutex);
    sound = (SoundLike *)*(void **)((char *)arg0 + 0x10);
    *(int *)((char *)arg0 + 0x1c) = 0;
    if (sound != 0 && sound->v21() != 0) {
        sound = (SoundLike *)*(void **)((char *)arg0 + 0x10);
        if (sound->v10() != 0) {
            sound = (SoundLike *)*(void **)((char *)arg0 + 0x10);
            ((void (*)(SoundLike *, int, int))((void **)*(void **)sound)[19])(sound, 0, 0);
        } else {
            sound = (SoundLike *)*(void **)((char *)arg0 + 0x10);
            ((void (*)(SoundLike *))((void **)*(void **)sound)[18])(sound);
        }
    }
    OSUnlockMutex(mutex);
}

extern "C" void Cancel__Q46nw4hbm3snd18SoundArchivePlayer18StrmHeaderLoadTaskFv_800F7FEC(void* self) {
    class Sound {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual s32 m8();
        virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
        virtual void v13(); virtual void v14(); virtual void v15(); virtual void m16();
        virtual void m17(s32, s32); virtual void v18(); virtual s32 Check();
    };
    void* mutex = *(void**)((u8*)self + 0x3c);
    OSLockMutex(mutex);
    *(u32*)((u8*)self + 0x10) = 0;
    Sound* sound = *(Sound**)((u8*)self + 0x14);
    if (sound && sound->Check()) {
        sound = *(Sound**)((u8*)self + 0x14);
        if (sound->m8()) {
            sound = *(Sound**)((u8*)self + 0x14);
            sound->m17(0, 0);
        } else {
            sound = *(Sound**)((u8*)self + 0x14);
            sound->m16();
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

#pragma push
#pragma small_data off
extern "C" void* fn_800F8310(void* self) {
    *(void**)self = &lbl_80325C40;
    fn_800EBB88((char*)self + 0x1C);
    OSInitMutex((char*)self + 4);
    return self;
}
#pragma push
#pragma small_data off
#pragma use_lmw_stmw off
extern "C" void* __dt__Q36nw4hbm3snd9SoundHeapFv(void* self, int flag) {
    if (self) {
        *(void**)self = lbl_80325C40;
        Destroy__Q46nw4hbm3snd6detail9FrameHeapFv((char*)self + 0x1C);
        __dt__Q46nw4hbm3snd6detail9FrameHeapFv((char*)self + 0x1C, -1);
        if (flag > 0)
            fn_80128668();
    }
    return self;
}
#pragma pop
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

void __ct__Q36nw4hbm3snd11SoundPlayerFv(void* self) {
    u8* p = (u8*)self;
    *(void**)(p + 4) = 0; *(void**)(p + 8) = 0;
    *(void**)(p + 0x10) = 0; *(void**)(p + 0x14) = 0;
    *(void**)(p + 0x1c) = 0; *(void**)(p + 0x20) = 0;
    *(void**)p = 0;
    *(void**)(p + 4) = p + 4; *(void**)(p + 8) = p + 4;
    *(u32*)(p + 0xc) = 0;
    *(void**)(p + 0x10) = p + 0x10; *(void**)(p + 0x14) = p + 0x10;
    *(u32*)(p + 0x18) = 0;
    *(void**)(p + 0x1c) = p + 0x1c; *(void**)(p + 0x20) = p + 0x1c;
    *(u16*)(p + 0x24) = 1; *(u16*)(p + 0x26) = 1;
    *(u8*)(p + 0x2d) = 0; *(f32*)(p + 0x28) = lbl_805610B8;
    *(u32*)(p + 0x30) = 1; *(u8*)(p + 0x2c) = 0;
    *(f32*)(p + 0x34) = lbl_805610B8;
    *(f32*)(p + 0x38) = lbl_805610B8;
    *(f32*)(p + 0x3c) = lbl_805610B8;
    *(f32*)(p + 0x40) = lbl_805610B8;
    *(f32*)(p + 0x44) = lbl_805610B8;
}

extern "C" void fn_800F8520(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F8540(void* arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

void Update__Q36nw4hbm3snd11SoundPlayerFv(void *self) {
    void *pHead = *(void **)((u8 *)self + 4);
    void *pEnd = (u8 *)self + 4;
    void *pPlayer;
    while (pHead != pEnd) {
        pPlayer = pHead;
        if (pPlayer == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262E8, 0x23D, (const char *)lbl_803262C4);
        }
        pHead = *(void **)pPlayer;
        Update__Q36nw4hbm3snd11SoundPlayerFv((u8 *)pPlayer - 0xC0);
    }
    detail_SortPriorityList__Q36nw4hbm3snd11SoundPlayerFv(self);
}

void StopAllSound__Q36nw4hbm3snd11SoundPlayerFi(void *self, s32 arg1) {
    void *pHead = *(void **)((u8 *)self + 4);
    void *pEnd = (u8 *)self + 4;
    void *pPlayer;
    while (pHead != pEnd) {
        pPlayer = pHead;
        if (pPlayer == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262E8, 0x23D, (const char *)lbl_803262C4);
        }
        pHead = *(void **)pPlayer;
        StopAllSound__Q36nw4hbm3snd11SoundPlayerFi((u8 *)pPlayer - 0xC0, arg1);
    }
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

void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(void *self, void *pSound) {
    if (pSound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803262B8, 0x233, (const char *)lbl_80326294);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(self, (u8 *)pSound + 0xC0);
    *(u32 *)((u8 *)pSound + 0x10) = 0;
}

void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *self, void *pSound) {
    if (pSound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80326288, 0x233, (const char *)lbl_80326264);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((u8 *)self + 0xC, (u8 *)pSound + 0xC8);
}

extern "C" void detail_SetPlayableSoundLimit__Q36nw4hbm3snd11SoundPlayerFi(
    void* this_, s32 limit) {
    if (limit < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325C50, 0x227,
                                     (const char*)lbl_80325D48);
    }
    *(u16*)&((u8*)this_)[0x26] = (u16)limit;
}

extern "C" void detail_AppendPlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10PlayerHeap(void* this_, void* pHeap) {
    void* heap = pHeap;
    void* self = this_;
    if (heap == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80325C50, 0x256, (const char*)lbl_80325D6C);
    }
    *(void**)((u8*)heap + 0x38) = self;
    void* node = (u8*)self + 0x1C;
    if (self == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80323834, 0x233, (const char*)lbl_80323810);
    }
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((void*)((u8*)self + 0x18), &node, (void*)((u8*)heap + 0x2C));
    *(u8*)((u8*)self + 0x2D) = 1;
}

extern "C" void detail_FreePlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *player, void *sound) {
    extern u8 lbl_80325D98[];
    extern u8 lbl_80323834[];
    extern u8 lbl_80323810[];
    void *heap;
    void *iterator;
    if (sound == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80325C50, 0x280, (const char *)lbl_80325D98);
    }
    heap = *(void **)((char *)sound + 4);
    if (heap != 0) {
        iterator = (char *)player + 0x1C;
        Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)player + 0x18, &iterator, (char *)heap + 0x2C);
    }
    if (heap != 0)
        *(void **)((char *)heap + 0x34) = 0;
    *(void **)((char *)sound + 4) = 0;
}

extern "C" void detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(void* this_, void* pHandle, u32 id, void* pAmbient, void* pPlayer, void* pInfo) {
    struct Base {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void* Start(void*, u32, void*, void*, void*);
    };
    struct Sound { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void Attach(); };
    void* sound = ((Base*)this_)->Start(pHandle, id, pAmbient, pPlayer, pInfo);
    if (sound == 0) {
        if (*(void**)pHandle != 0) {
            ((Sound*)sound)->Attach();
        }
    }
}

extern "C" void fn_800E2E24(void);
extern "C" s32 SCInit(void);
extern "C" u32 SCCheckStatus(void);
extern "C" u8 SCGetSoundMode(void);
extern "C" void SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(s32);
extern "C" void Setup__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv(void);
extern "C" s32 Create__Q46nw4hbm3snd6detail10TaskThreadFl(s32);
extern "C" s32 fn_800FA4C4(s32);
extern "C" void InitSoundSystem__Q36nw4hbm3snd11SoundSystemFll(s32 arg0, s32 arg1) {
    u32 status;
    u8 mode;
    if (lbl_8055DE60 != 0) return;
    lbl_8055DE60 = 1;
    Instance__15EmissionManagerFv();
    fn_800E2E24();
    SCInit();
    do { status = SCCheckStatus(); } while (status == 1);
    if (status != 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803263B8, 0x4f, (const char *)(lbl_803263B8 + 0x14));
    mode = SCGetSoundMode();
    switch (mode) {
    case 0: Instance__15EmissionManagerFv(); SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(3); break;
    case 1: Instance__15EmissionManagerFv(); SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(0); break;
    case 2: Instance__15EmissionManagerFv(); SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(2); break;
    default: Instance__15EmissionManagerFv(); SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(0); break;
    }
    GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
    Setup__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
    fn_800FE648();
    if (Create__Q46nw4hbm3snd6detail10TaskThreadFl(arg1) == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803263B8, 0x7e, (const char *)(lbl_803263B8 + 0x48));
    GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv();
    if (fn_800FA4C4(arg0) == 0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_803263B8, 0x82, (const char *)(lbl_803263B8 + 0x48));
}

extern "C" void fn_800FA350(void) {
    void *v;
    if (lbl_8055DE60 != 0) {
        GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv();
        if (Shutdown__Q46nw4hbm3snd6detail11SoundThreadFv() == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803263B8, 0x8D,
                                         (const char*)lbl_80326400);
        }
        fn_800FE648();
        if (Destroy__Q46nw4hbm3snd6detail10TaskThreadFv() == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803263B8, 0x91,
                                         (const char*)lbl_80326400);
        }
        v = GetInstance__Q46nw4hbm3snd6detail20RemoteSpeakerManagerFv();
        fn_800EEB64(v);
        v = Instance__15EmissionManagerFv();
        fn_800E2F84(v);
        lbl_8055DE60 = 0;
    }
}

extern "C" void* GetInstance__Q46nw4hbm3snd6detail11SoundThreadFv(void) {
    if ((s8)lbl_8055DE68 == 0) {
        u32* p = (u32*)&lbl_80412CC8[0x2384];
        p[1] = 0;
        p[2] = 0;
        p[0] = 0;
        p[1] = 0;
        p[3] = 0;
        *(void**)p[1] = (void*)p;
        *(void**)p[2] = (void*)p;
        ((u8*)p)[0x10] = 0;
        __register_global_object((void*)&lbl_80412CC8[0x2388], (void*)&__dt__10TitleSceneFv,
                                 (void*)&lbl_80412CB8, (void*)&lbl_80412CC8[0x2388]);
        lbl_8055DE68 = 1;
    }
    return &lbl_80412CC8[0x2388];
}

extern "C" void* __dt__10TitleSceneFv(void* this_, s32 flag) {
    if (this_) {
        if ((u8*)this_ + 0x2384 != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8*)this_ + 0x2384, 0);
        }
        if (flag > 0) {
            ((s32 (*)(void*))fn_80128668)(this_);
        }
    }
    return this_;
}

extern "C" void fn_800FA6E8(void) {
    if ((s8)lbl_8055DE68 == 0) {
        volatile u32* base = (volatile u32*)lbl_80412CC8;
        u32* self = (u32*)&lbl_80412CC8[0x2388];
        base[0x2388 / 4] = 0;
        u32* ptr = (u32*)&base[0x2388 / 4];
        base[0x238c / 4] = 0;
        base[0x2378 / 4] = 0;
        base[0x237c / 4] = 0;
        base[0x2384 / 4] = 0;
        base[0x2388 / 4] = (u32)ptr;
        base[0x238c / 4] = (u32)ptr;
        ((volatile u8*)base)[0x2394] = 0;
        __register_global_object(self, (void*)&__dt__10TitleSceneFv,
                                 (void*)&lbl_80412CB8, self);
        lbl_8055DE68 = 1;
    }
    OSSendMessage((void*)&lbl_80412CC8[0x2338], (void*)1, 0);
    detail_UpdateBufferAllPlayers__Q36nw4hbm3snd10WavePlayerFv();
    UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv();
}

extern "C" s32 fn_800FA77C(s32 arg0) {
    OSInitMessageQueue((void*)(arg0 + 0x2338), (void*)(arg0 + 0x2358), 8);
    void* manager = Instance__15EmissionManagerFv();
    RegisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNodePFv_v(
        manager, (void*)(arg0 + 0x2378), fn_800FA6E8);
    fn_800FA7E0((void*)arg0);
    manager = Instance__15EmissionManagerFv();
    UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(
        manager, (void*)(arg0 + 0x2378));
    return 0;
}

extern "C" void Setup__Q46nw4hbm3snd6detail14StrmBufferPoolFPvUli(void* this_, u32 size, s32 count) {
    if (count != 0) {
        u32 level = OSDisableInterrupts();
        *(u32*)this_ = size;
        *(u32*)((u8*)this_ + 4) = count;
        *(u32*)((u8*)this_ + 8) = count / count;
        *(u32*)((u8*)this_ + 0xC) = count;
        *(u32*)((u8*)this_ + 0x10) = 0;
        memset((void*)((u8*)this_ + 0x14), 0, 4);
        if (*(s32*)((u8*)this_ + 0xC) > 0x20) {
            extern const char lbl_803264E0[];
            extern const char lbl_803264F4[];
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803264E0, 0x2A, lbl_803264F4);
        }
        OSRestoreInterrupts(level);
    }
}

extern "C" void fn_800FA9E8(void* arg0) {
    OSDisableInterrupts();
    *(s32*)arg0 = 0;
    *(s32*)((u8*)arg0 + 4) = 0;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    OSRestoreInterrupts(0);
}

extern "C" void Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(void *self, void *ptr) {
    u32 state = OSDisableInterrupts();
    u32 idx = ((u8 *)ptr - (u8 *)*(void **)self) / *(u32 *)((u8 *)self + 8);
    u8 *block = (u8 *)self + (idx >> 3);
    *(u8 *)(block + 0x14) &= ~(1 << (idx & 7));
    *(s32 *)((u8 *)self + 0x10) -= 1;
    OSRestoreInterrupts(state);
}

extern "C" void NWC24Data_Init(void* arg0) {
    *(int*)arg0 = 0;
    *((int*)arg0 + 1) = 0;
}

extern "C" void fn_800FB358(void *arg0) {
    extern char lbl_80326AC0[];
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(void **)((u8 *)arg0 + 0) = lbl_80326AC0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
}

extern "C" s32 fn_800FB374(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" void fn_800FB620(void *self) {
    if (*(u8 *)((u8 *)self + 0x48) != 0) {
        ForceStop__Q46nw4hbm3snd6detail10StrmPlayerFv(self);
    }
}

extern "C" void UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(void *);
extern "C" const char lbl_80326B68[];
extern "C" const char lbl_80326B8C[];
extern "C" const char lbl_80326768[];
extern "C" const char lbl_8032687C[];
#pragma push
#pragma small_data off
extern "C" u8 lbl_8041506C[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void UpdateBufferAllPlayers__Q46nw4hbm3snd6detail10StrmPlayerFv(void) {
    void* base = &lbl_8041506C[0x04];
    void* pHead = *(void**)base;
    void* p;

    while (pHead != base) {
        p = pHead;
        pHead = *(void**)pHead;
        if (p == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80326B8C, 0x23D,
                                         (const char*)lbl_80326B68);
        }
        UpdateBuffer__Q46nw4hbm3snd6detail10StrmPlayerFv(&((u8*)p)[-0x08]);
    }
}
#pragma pop
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
    int valid = 0;
    if (bus >= 0 && bus < 3) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x309, lbl_803268AC, bus, 0, 3);
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x464 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC6E4(void *self, s32 bus) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
    extern const char lbl_80326768[];
    extern const char lbl_803268AC[];
    s32 valid = 0;
    if (bus >= 0 && bus < 3) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x310, lbl_803268AC, bus, 0, 3);
    return *(f32 *)((u8 *)self + 0x464 + bus * 4);
}

extern "C" void fn_800FC76C(void *self, s32 value) {
    u32 token = OSDisableInterrupts();
    *(s32 *)((u8 *)self + 0x458) = value;
    OSRestoreInterrupts(token);
}

extern "C" s32 fn_800FC7AC(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x458);
}

extern "C" const char lbl_803268E4[];
void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC7B4(void *self, s32 bus, f32 value) {
    if (bus < 0 || bus >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x322, lbl_803268E4, bus, 0, 4);
    }
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x470 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC850(s32 arg0, s32 arg1) {
    s32 valid = 0;
    if (arg1 >= 0 && arg1 < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x329, lbl_803268E4, arg1, 0, 4);
    return *(f32 *)(arg0 + arg1 * 4 + 0x470);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC8D8(void *arg0, s32 arg1, f32 value) {
    int valid = 0;
    if (arg1 >= 0 && arg1 < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x32f, lbl_803268E4, arg1, 0, 4);
    u32 token = OSDisableInterrupts();
    *(f32 *)((char *)arg0 + 0x480 + arg1 * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FC974(void *self, s32 bus) {
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x336, lbl_803268E4, bus, 0, 4);
    return *(f32 *)((u8 *)self + 0x480 + bus * 4);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_800FC9FC(void *self, s32 bus, f32 value) {
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x33C, lbl_803268E4, bus, 0, 4);
    u32 token = OSDisableInterrupts();
    *(f32 *)((u8 *)self + 0x490 + bus * 4) = value;
    OSRestoreInterrupts(token);
}

extern "C" f32 GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_800FCA98(void *self, s32 bus) {
    s32 valid = 0;
    if (bus >= 0 && bus < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80326768, 0x343, lbl_803268E4, bus, 0, 4);
    return *(f32 *)((u8 *)self + 0x490 + bus * 4);
}

extern "C" void SetAdpcmLoopContext__Q56nw4hbm3snd6detail10StrmPlayer11LoadCommandFiPUs(void *a,int n,u16 *p){void *x=*(void **)((u8*)a+4);if(*((u8*)x+16)!=2)return;int i=0,o=0;do{x=*(void **)((u8*)a+4);*(u16*)((u8*)x+0x518+o)=*p++;i++;o+=2;}while(i<n&&i<2);*((u8*)x+0x51)=1;}

extern "C" int fn_800FD810(void* arg0, int arg1) {
    void* temp_r6 = *(void**)((char*)arg0 + 4);
    if (arg1 >= *(int*)((char*)temp_r6 + 0x4A0)) {
        return 0;
    }
    return *(int*)((char*)temp_r6 + arg1 * 0x38 + 0x4A8) +
           *(int*)((char*)temp_r6 + 0x60) * *(int*)((char*)arg0 + 0x10);
}

extern "C" float fn_800FD848(void *arg0) { return *(float *)((char *)arg0 + 0x454); }

extern "C" float fn_800FD850(void *arg0) { return *(float *)((char *)arg0 + 0x44C); }

extern "C" float fn_800FD858(void *arg0) { return *(float *)((char *)arg0 + 0x448); }

extern "C" float fn_800FD860(void *arg0) { return *(float *)((char *)arg0 + 0x444); }

extern "C" f32 fn_800FD868(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 0x440);
}

extern "C" f32 fn_800FD870(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 0x450);
}

extern "C" f32 fn_800FD878(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 0x43C);
}

extern "C" void fn_800FD880(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x454) = arg1;
}

extern "C" void fn_800FD888(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x44C) = arg1;
}

extern "C" void fn_800FD890(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x448) = arg1;
}

extern "C" void fn_800FD898(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x444) = arg1;
}

extern "C" void fn_800FD8A0(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0x440) = arg1;
}

extern "C" void fn_800FD8A8(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x450) = farg0;
}

extern "C" void fn_800FD8B0(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x43C) = farg0;
}

extern "C" int fn_800FD8B8(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x4B) != 0;
}

extern "C" int fn_800FD8CC(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x49) != 0;
}

extern "C" int fn_800FD8E0(void* arg0) {
    return *((unsigned char*)arg0 + 0x4A) != 0;
}

extern "C" int fn_800FD8F4(void* arg0) {
    return *((unsigned char*)arg0 + 0x48) != 0;
}

extern "C" void* fn_8002F634(void*, void*, int, int);
extern "C" void* __dt__Q46nw4hbm3snd6detail10StrmPlayerFv(void* arg0, int arg1) {
    void* temp_r3;
    void* temp_r3_2;
    if (arg0 != 0) {
        fn_8002F634((char*)arg0 + 0xAC, (void*)fn_800FB374, 0x1C, 0x20);
        temp_r3 = (char*)arg0 + 0xA0;
        if (temp_r3 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv(temp_r3, 0);
        temp_r3_2 = (char*)arg0 + 0x94;
        if (temp_r3_2 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv(temp_r3_2, 0);
        if (arg1 > 0) ((void (*)(void*))fn_80128668)(arg0);
    }
    return arg0;
}
extern "C" void Setup__Q46nw4hbm3snd6detail10StrmPlayerFPCQ56nw4hbm3snd6detail10StrmPlayer10StrmHeader(void *, const void *);
extern "C" void Free__Q44nw4r3snd6detail14StrmBufferPoolFPv(void *, void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" f32 lbl_805610C0;
extern "C" f32 lbl_805610C4;
extern "C" const char lbl_80326768[];
extern "C" const char lbl_803269A0[];
