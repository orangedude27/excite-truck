// Code of main that had no source file yet: decomp.wtf gave it this one.
 // split_file divides it into the game's real files (file_status shows its range).
 
 extern "C" char lbl_80327C88[];
 extern "C" char lbl_80327CAC[];
 extern "C" char lbl_8041D4C4[];
 extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);
 extern "C" void* Instance__15EmissionManagerFv(void);

extern "C" float lbl_80561124;
extern "C" char lbl_80327930[];
extern "C" char lbl_80327994[];
extern "C" char lbl_8032796C[];
extern "C" char lbl_80327944[];
extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...) __attribute__((noreturn));
extern "C" int fn_800FEC1C(void*, const void*);
extern "C" int ReadWaveParam__Q46nw4hbm3snd6detail14WaveFileReaderCFPQ46nw4hbm3snd6detail8WaveDataPCv(void*, void*, const void*);
extern "C" char lbl_80327AF4[];
extern "C" void fn_800EC890(void*);
extern "C" float lbl_80561120;
extern "C" void fn_800FFE94(void* arg0) {
    void* p = *(void**)arg0;
    if (p && *(void**)((char*)p + 0x1AC) == arg0)
        *(void**)((char*)p + 0x1AC) = 0;
    if (*(void**)arg0)
        *(void**)arg0 = 0;
}

extern "C" char lbl_803276F0[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv_800FFECC(void *arg0, const void *arg1) {
    register char *strings = lbl_803276F0;
    register const unsigned char *file = (const unsigned char *)arg1;
    register unsigned short version;
    *(unsigned int *)arg0 = 0;
    *(unsigned int *)((char *)arg0 + 4) = 0;
    *(unsigned int *)((char *)arg0 + 8) = 0;
    if (file == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(strings, 0x59, strings + 0xB4);
    if (*(const unsigned int *)file != 0x52575344)
        Panic__Q26nw4hbm2dbFPCciPCce(strings, 0x37, strings + 0x10);
    if (*(const unsigned int *)file != 0x52575344)
        return arg0;
    version = *(const unsigned short *)(file + 6);
    if (version < 0x100)
        Panic__Q26nw4hbm2dbFPCciPCce(strings, 0x3F, strings + 0x5C);
    version = *(const unsigned short *)(file + 6);
    if (version < 0x100)
        return arg0;
    if (version > 0x102)
        Panic__Q26nw4hbm2dbFPCciPCce(strings, 0x45, strings + 0x5C);
    if (version > 0x102)
        return arg0;
    *(const void **)arg0 = arg1;
    *(void **)((char *)arg0 + 4) = (void *)(file + *(const unsigned int *)(file + 0x10));
    if (**(const unsigned int **)((char *)arg0 + 4) != 0x44415441)
        Panic__Q26nw4hbm2dbFPCciPCce(strings, 0x62, strings + 0xE0);
    *(void **)((char *)arg0 + 8) = (void *)(file + *(const unsigned int *)(file + 0x18));
    if (**(const unsigned int **)((char *)arg0 + 8) != 0x57415645)
        Panic__Q26nw4hbm2dbFPCciPCce(strings, 0x66, strings + 0x138);
    return arg0;
}

extern "C" void* GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(unsigned char, unsigned int, const void*);
extern "C" float lbl_80561118;
extern "C" char lbl_803278D8[];
extern "C" char lbl_80327904[];
extern "C" char lbl_80559918[];
extern "C" char lbl_80559920[];
extern "C" int ReadWaveSoundInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail13WaveSoundInfoi(void* arg0, void* arg1, int arg2) {
    register unsigned char* base = (unsigned char*)*(void**)((char*)arg0 + 4);
    register unsigned char* data = base + 8;
    unsigned char* entry = base + arg2 * 8;
    unsigned char* ref;
    unsigned char* wave;
    if (entry[0xD] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80559918, 0x6F, lbl_803278D8);
    ref = (unsigned char*)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[0xC], *(unsigned int*)(entry + 0x10), data);
    if (ref[1] != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559920, 0x6F, lbl_80327904);
    wave = (unsigned char*)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0], *(unsigned int*)(ref + 4), data);
    if (*(unsigned short*)((char*)*(void**)arg0 + 6) == 0x102) {
        *(float*)arg1 = *(float*)wave;
        ((unsigned char*)arg1)[4] = wave[4]; ((unsigned char*)arg1)[5] = wave[5];
        ((unsigned char*)arg1)[6] = wave[6]; ((unsigned char*)arg1)[7] = wave[7];
        ((unsigned char*)arg1)[8] = wave[8]; ((unsigned char*)arg1)[9] = wave[9];
    } else if (*(unsigned short*)((char*)*(void**)arg0 + 6) == 0x101) {
        *(float*)arg1 = *(float*)wave;
        ((unsigned char*)arg1)[4] = wave[4]; ((unsigned char*)arg1)[5] = wave[5];
        ((unsigned char*)arg1)[6] = 0; ((unsigned char*)arg1)[7] = 0;
        ((unsigned char*)arg1)[8] = 0; ((unsigned char*)arg1)[9] = 0x7F;
    } else {
        *(float*)arg1 = lbl_80561118;
        ((unsigned char*)arg1)[4] = 0x40; ((unsigned char*)arg1)[5] = 0;
        ((unsigned char*)arg1)[6] = 0; ((unsigned char*)arg1)[7] = 0;
        ((unsigned char*)arg1)[8] = 0; ((unsigned char*)arg1)[9] = 0x7F;
    }
    return 1;
}

extern "C" char lbl_80327880[], lbl_803278AC[], lbl_803278D8[], lbl_80559908[], lbl_80559910[], lbl_80559918[];
extern "C" int ReadWaveSoundNoteInfo__Q46nw4hbm3snd6detail13WsdFileReaderCFPQ46nw4hbm3snd6detail17WaveSoundNoteInfoii(void* arg0, void* arg1, int arg2, int arg3) {
    unsigned char* base = (unsigned char*)*(void**)((char*)arg0 + 4);
    unsigned char* data = base + 8;
    unsigned char* entry = base + arg2 * 8;
    unsigned char* ref;
    unsigned char* note;
    unsigned char* wave;
    unsigned char* voice;
    unsigned int index = arg3 * 8;
    if (entry[0xD] != 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559918, 0x6F, lbl_803278D8);
    ref = (unsigned char*)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(entry[0xC], *(unsigned int*)(entry + 0x10), data);
    if (ref[0x11] != 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559908, 0x6F, lbl_80327880);
    note = (unsigned char*)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(ref[0x10], *(unsigned int*)(ref + 0x14), data);
    if (note[index + 5] != 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559910, 0x6F, lbl_803278AC);
    voice = note + index;
    wave = (unsigned char*)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(voice[4], *(unsigned int*)(voice + 8), data);
    *(unsigned int*)arg1 = *(unsigned int*)wave;
    ((unsigned char*)arg1)[4]=wave[4]; ((unsigned char*)arg1)[5]=wave[5]; ((unsigned char*)arg1)[6]=wave[6]; ((unsigned char*)arg1)[7]=wave[7];
    ((unsigned char*)arg1)[8]=wave[0xC]; ((unsigned char*)arg1)[0xB]=wave[0xD];
    if (*(unsigned short*)((char*)*(void**)arg0+6) >= 0x101) {
        ((unsigned char*)arg1)[9]=wave[0xE]; ((unsigned char*)arg1)[0xA]=wave[0xF]; *(float*)((char*)arg1+0xC)=*(float*)(wave+0x10);
    } else {
        ((unsigned char*)arg1)[9]=0x40; ((unsigned char*)arg1)[0xA]=0; *(float*)((char*)arg1+0xC)=lbl_80561118;
    }
    return 1;
}

extern "C" int ReadWaveParam__Q46nw4hbm3snd6detail13WsdFileReaderCFiPQ46nw4hbm3snd6detail8WaveDataPCv(void* arg0, unsigned int arg1, void* arg2, const void* arg3) {
    unsigned char sp8[8];
    register void* header = *(void**)arg0;
    char* base;
    void* entry;
    if (*(unsigned short*)((char*)header + 6) == 0x100) {
        base = (char*)*(void**)((char*)arg0 + 8);
        unsigned int off = *(unsigned int*)(base + arg1 * 4 + 8);
        entry = (void*)((unsigned int)off + (unsigned int)base);
    } else {
        base = (char*)*(void**)((char*)arg0 + 8);
        if (arg1 >= *(unsigned int*)(base + 8))
            return 0;
        unsigned int off = *(unsigned int*)(base + arg1 * 4 + 0xC);
        entry = (void*)((unsigned int)off + (unsigned int)base);
    }
    fn_800FEC1C(sp8, entry);
    return ReadWaveParam__Q46nw4hbm3snd6detail14WaveFileReaderCFPQ46nw4hbm3snd6detail8WaveDataPCv(sp8, arg2, arg3);
}

extern "C" void* __ct__Q46nw4hbm3snd6detail9WsdPlayerFv(void* arg0) {
    *(int*)((char*)arg0 + 4) = -1;
    *(int*)((char*)arg0 + 8) = 0;
    *(int*)((char*)arg0 + 0xC) = 0;
    *(void**)arg0 = lbl_80327AF4;
    *(void**)((char*)arg0 + 0x10) = lbl_80327AF4 + 0x98;
    *(int*)((char*)arg0 + 0x14) = 0;
    *(int*)((char*)arg0 + 0x18) = 0;
    *((char*)arg0 + 0x1D) = 0;
    fn_800EC890((char*)arg0 + 0xA8);
    *(int*)((char*)arg0 + 0xC8) = 0;
    return arg0;
}

extern "C" void InitParam__Q46nw4hbm3snd6detail9WsdPlayerFiPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl(void* arg0, int arg1, const void* arg2, unsigned long arg3) {
    float f0 = lbl_80561124;
    float f1 = lbl_80561120;
    *((char*)arg0 + 0x1E) = 0;
    *((char*)arg0 + 0x1F) = 0;
    *((char*)arg0 + 0x20) = 0;
    *((char*)arg0 + 0x21) = 0;
    *((char*)arg0 + 0x1C) = 0;
    *(float*)((char*)arg0 + 0x24) = f1;
    *(float*)((char*)arg0 + 0x3C) = f1;
    *(float*)((char*)arg0 + 0x28) = f0;
    *(float*)((char*)arg0 + 0x2C) = f0;
    *(float*)((char*)arg0 + 0x34) = f0;
    *(float*)((char*)arg0 + 0x38) = f0;
    *(float*)((char*)arg0 + 0x30) = f1;
    *(float*)((char*)arg0 + 0x40) = f0;
    *(int*)((char*)arg0 + 0x44) = 1;
    *(float*)((char*)arg0 + 0x48) = f1;
    *(float*)((char*)arg0 + 0x4C) = f0;
    *(float*)((char*)arg0 + 0x50) = f0;
    *(float*)((char*)arg0 + 0x54) = f0;
    *(float*)((char*)arg0 + 0x58) = f0;
    *(float*)((char*)arg0 + 0x6C) = f0;
    *(float*)((char*)arg0 + 0x7C) = f0;
    *(float*)((char*)arg0 + 0x70) = f0;
    *(float*)((char*)arg0 + 0x80) = f0;
    *(float*)((char*)arg0 + 0x74) = f0;
    *(float*)((char*)arg0 + 0x84) = f0;
    *(float*)((char*)arg0 + 0x78) = f0;
    *(float*)((char*)arg0 + 0x88) = f0;
    *(int*)((char*)arg0 + 0xD0) = 0;
    *(int*)((char*)arg0 + 0x8C) = arg1;
    *((char*)arg0 + 0x90) = 0x40;
    *(const void**)((char*)arg0 + 0x94) = arg2;
    *(unsigned long*)((char*)arg0 + 0x98) = arg3;
}

extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *, void *);
extern "C" void RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *, void *);
extern "C" void Close__Q46nw4hbm3snd6detail8WsdTrackFv(void *);
extern "C" void Init__Q46nw4hbm3snd6detail8WsdTrackFPQ46nw4hbm3snd6detail9WsdPlayer(void *, void *);
extern "C" void NWC24Data_SetDataP(void *, const void *, unsigned long);
#pragma push
#pragma use_lmw_stmw off
extern "C" int Prepare__Q46nw4hbm3snd6detail9WsdPlayerFPCviiPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl(void *arg0, const void *arg1, int arg2, int arg3, const void *arg4, unsigned long arg5) {
    int level1;
    int level2;
    level1 = OSDisableInterrupts();

    if (*(unsigned char *)((char *)arg0 + 0x1D) != 0) {
        level2 = OSDisableInterrupts();
        if (*(unsigned char *)((char *)arg0 + 0x1F) != 0) {
            if (arg0 == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327CAC, 0x233, lbl_80327C88);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(lbl_8041D4C4, (char *)arg0 + 0x14);
        }
        if (*(unsigned char *)((char *)arg0 + 0x1D) != 0) {
            void *node = arg0;
            if (arg0 != 0)
                node = (char *)arg0 + 8;
            UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
                GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), node);
        }
        OSRestoreInterrupts(level2);
        Close__Q46nw4hbm3snd6detail8WsdTrackFv((char *)arg0 + 0x9C);
        *(unsigned char *)((char *)arg0 + 0x1D) = 0;
    }

    InitParam__Q46nw4hbm3snd6detail9WsdPlayerFiPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl(arg0, arg3, arg4, arg5);
    Init__Q46nw4hbm3snd6detail8WsdTrackFPQ46nw4hbm3snd6detail9WsdPlayer((char *)arg0 + 0x9C, arg0);
    NWC24Data_SetDataP((void *)((unsigned int)arg0 + 0x9C), arg1, arg2);

    void *node = arg0;
    if (arg0 != 0)
        node = (char *)arg0 + 8;
    RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
        GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), node);
    *(unsigned char *)((char *)arg0 + 0x1D) = 1;
    *(unsigned char *)((char *)arg0 + 0x1E) = 1;
    OSRestoreInterrupts(level1);
    return 1;
}
#pragma pop
extern "C" int fn_80100654(void* arg0) {
    if (*((unsigned char*)arg0 + 0x1E) == 0)
        return 0;

    register char* iterator = lbl_8041D4C4 + 4;
    if (arg0 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327CAC, 0x233, lbl_80327C88);

    char* slot = iterator;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
        lbl_8041D4C4, (void**)&slot, (char*)arg0 + 0x14);
    *((unsigned char*)arg0 + 0x1C) =
        *((unsigned char*)Instance__15EmissionManagerFv() + 0x6C32);
    *((unsigned char*)arg0 + 0x1F) = 1;
    return 1;
}

extern "C" void Stop__Q46nw4hbm3snd6detail9WsdPlayerFv(void* arg0) {
    extern char lbl_80327C88[];
    extern char lbl_80327CAC[];
    extern char lbl_8041D4C4[];
    extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);
    extern void* GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
    extern void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void*, void*);
    extern void Close__Q46nw4hbm3snd6detail8WsdTrackFv(void*);
    int level;
    void* node;
    void* manager;
    if (*((unsigned char*)arg0 + 0x1D) == 0)
        return;
    level = OSDisableInterrupts();
    if (*((unsigned char*)arg0 + 0x1F) != 0) {
        if (arg0 == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327CAC, 0x233, lbl_80327C88);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(lbl_8041D4C4, (char*)arg0 + 0x14);
    }
    if (*((unsigned char*)arg0 + 0x1D) != 0) {
        node = arg0;
        if (arg0 != 0)
            node = (char*)arg0 + 8;
        manager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
        UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(manager, node);
    }
    OSRestoreInterrupts(level);
    Close__Q46nw4hbm3snd6detail8WsdTrackFv((char*)arg0 + 0x9C);
    *((unsigned char*)arg0 + 0x1D) = 0;
}

extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(void *, unsigned char);
extern "C" void Pause__Q46nw4hbm3snd6detail9WsdPlayerFb(void *arg0, unsigned char arg1) {
    int enabled = OSDisableInterrupts();
    *(unsigned char *)((char *)arg0 + 0x20) = arg1;
    PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb((char *)arg0 + 0x9C, arg1);
    OSRestoreInterrupts(enabled);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_80100820(register void *arg0, float value) {
    register void *self = arg0;
    float minimum = lbl_80561124;
    if (!(value >= minimum)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0xFA, lbl_80327944);
    }
    int enabled = OSDisableInterrupts();
    *(float *)((char *)self + 0x24) = value;
    OSRestoreInterrupts(enabled);
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail9SeqPlayerFf_80100894(void *self, float volume) {
    float minVolume = lbl_80561124;
    if (!(volume >= minVolume))
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x101, lbl_8032796C);
    int interruptState = OSDisableInterrupts();
    *(float *)((char *)self + 0x3C) = volume;
    OSRestoreInterrupts(interruptState);
}

extern "C" void fn_80100908(void* arg0, float arg1) {
    int level = OSDisableInterrupts();
    *(float*)((char*)arg0 + 0x28) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" void fn_80100948(void* arg0, float arg1) {
    OSDisableInterrupts();
    *(float*)((char*)arg0 + 0x2C) = arg1;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_80100988(void* arg0, float arg1) {
    int level = OSDisableInterrupts();
    *(float*)((char*)arg0 + 0x34) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" void fn_801009C8(void* arg0, float arg1) {
    OSDisableInterrupts();
    *(float*)((char*)arg0 + 0x38) = arg1;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void fn_80100A08(void* arg0, float arg1) {
    int level = OSDisableInterrupts();
    *(float*)((char*)arg0 + 0x40) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" void fn_80100A48(void* arg0, float arg1) {
    int level = OSDisableInterrupts();
    *(float*)((char*)arg0 + 0x4C) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" float fn_80100A88(void* arg0) { return *(float*)((char*)arg0 + 0x4C); }

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9WsdPlayerFQ36nw4hbm3snd6AuxBusf(void* arg0, int arg1, float arg2) {
    extern char lbl_80327930[];
    extern char lbl_80327994[];
    int valid = arg1 >= 0 && arg1 < 3;
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x13F, lbl_80327994, arg1, 0, 3);
    }
    *(float*)((char*)arg0 + arg1 * 4 + 0x50) = arg2;
}

extern "C" float GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_80100B24(void* arg0, int arg1) {
    int valid = arg1 >= 0 && arg1 < 3;
    if (!valid)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x145, lbl_80327994, arg1, 0, 3);
    return *(float*)((char*)arg0 + arg1 * 4 + 0x50);
}

extern "C" void fn_80100BAC(void* arg0, int arg1) {
    int level = OSDisableInterrupts();
    *(int*)((char*)arg0 + 0x44) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" int fn_80100BEC(void* arg0) {
    return *(int*)((char*)arg0 + 0x44);
}

extern "C" char lbl_80327930[];
extern "C" char lbl_80327944[];
extern "C" char lbl_8032796C[];
extern "C" float lbl_80561124;
extern "C" char lbl_80327994[];
extern "C" char lbl_803279CC[];
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_80100BF4(void* arg0, int arg1, float arg2) {
    int valid = arg1 >= 0 && arg1 < 4;
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x157, lbl_803279CC, arg1, 0, 4);
    }
    int level = OSDisableInterrupts();
    *(float*)((char*)arg0 + (arg1 * 4) + 0x5C) = arg2;
    OSRestoreInterrupts(level);
}

extern "C" float GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_80100C90(void* arg0, int arg1) {
    int valid = arg1 >= 0 && arg1 < 4;
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x15E, lbl_803279CC, arg1, 0, 4);
    }
    return *(float*)((char*)arg0 + (arg1 * 4) + 0x5C);
}

extern "C" char lbl_80327994[];
extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_80100D18(void* arg0, int arg1, float arg2) {
    int valid = arg1 >= 0 && arg1 < 4;
    if (!valid) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x164, lbl_803279CC, arg1, 0, 4);
    int level = OSDisableInterrupts();
    *(float*)((char*)arg0 + arg1 * 4 + 0x6C) = arg2;
    OSRestoreInterrupts(level);
}

extern "C" float GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_80100DB4(void* arg0, int arg1) {
    int valid = arg1 >= 0 && arg1 < 4;
    if (!valid) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x16B, lbl_803279CC, arg1, 0, 4);
    return *(float*)((char*)arg0 + arg1 * 4 + 0x6C);
}

extern "C" void SetFxSend__Q46nw4hbm3snd6detail9SeqPlayerFQ36nw4hbm3snd6AuxBusf_80100E3C(void* arg0, int arg1, float arg2) {
    int valid = arg1 >= 0 && arg1 < 4;
    if (!valid) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x171, lbl_803279CC, arg1, 0, 4);
    int level = OSDisableInterrupts();
    *(float*)((char*)arg0 + arg1 * 4 + 0x7C) = arg2;
    OSRestoreInterrupts(level);
}

extern "C" float GetFxSend__Q46nw4hbm3snd6detail9SeqPlayerCFQ36nw4hbm3snd6AuxBus_80100ED8(void* arg0, int arg1) {
    int valid = arg1 >= 0 && arg1 < 4;
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x178, lbl_803279CC, arg1, 0, 4);
    }
    return *(float*)((char*)arg0 + (arg1 * 4) + 0x7C);
}

extern "C" void fn_80100F60(void* arg0, float arg1) {
    int level = OSDisableInterrupts();
    *(float*)((char*)arg0 + 0x48) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" float fn_80100FA0(void* arg0) {
    return *(float*)((char*)arg0 + 0x48);
}

extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi_80100FA8(void* arg0, int arg1) {
    int valid = arg1 >= 0 && arg1 <= 0x7F;
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x18A, "channel priority %d out of range [%d, %d]", arg1, 0, 0x7F);
    }
    int level = OSDisableInterrupts();
    *((char*)arg0 + 0x90) = arg1;
    OSRestoreInterrupts(level);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void InvalidateData__Q46nw4hbm3snd6detail9WsdPlayerFPCvPCv(void* arg0, const void* arg1, const void* arg2) {
    extern char lbl_80327C88[];
    extern char lbl_80327CAC[];
    extern char lbl_8041D4C4[];
    extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);
    extern void* GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
    extern void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void*, void*);
    extern void Close__Q46nw4hbm3snd6detail8WsdTrackFv(void*);
    int level2;
    int level1;
    level1 = OSDisableInterrupts();
    if (*((unsigned char*)arg0 + 0x1D) != 0 &&
        (unsigned int)arg1 <= *(unsigned int*)((char*)arg0 + 0x9C) &&
        *(unsigned int*)((char*)arg0 + 0x9C) <= (unsigned int)arg2) {
        level2 = OSDisableInterrupts();
        if (*((unsigned char*)arg0 + 0x1F) != 0) {
            if (arg0 == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327CAC, 0x233, lbl_80327C88);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(lbl_8041D4C4, (char*)arg0 + 0x14);
        }
        if (*((unsigned char*)arg0 + 0x1D) != 0) {
            void* callback = arg0;
            if (arg0 != 0)
                callback = (char*)arg0 + 8;
            UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), callback);
        }
        OSRestoreInterrupts(level2);
        Close__Q46nw4hbm3snd6detail8WsdTrackFv((char*)arg0 + 0x9C);
        *((unsigned char*)arg0 + 0x1D) = 0;
    }
    OSRestoreInterrupts(level1);
}
#pragma pop
extern "C" char lbl_80327C58[];
extern "C" char lbl_80327C7C[];
extern "C" char lbl_80327AC4[];
extern "C" char lbl_80327CAC[];
extern "C" char lbl_80327C88[];
extern "C" void* Instance__15EmissionManagerFv(void);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*, void**, void*);
extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(void*, unsigned char);
extern "C" char lbl_8041D4C4[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_80101300(void) {
    class PlayerVTable {
    public:
        virtual void Dummy0();
        virtual void Dummy1();
        virtual void Stop();
    };
    void** pList = (void**)(lbl_8041D4C4 + 0x04);
    void** pHead = (void**)*pList;
    void** pPlayer;

    while (pHead != pList) {
        pPlayer = pHead;
        pHead = (void**)*pPlayer;
        if (pPlayer == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80327C7C, 0x23D,
                                         (const char*)lbl_80327C58);
        }
        ((PlayerVTable*)((char*)pPlayer - 0x14))->Stop();
    }

    if (*(int*)lbl_8041D4C4 != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80327930, 0x24D,
                                     (const char*)lbl_80327AC4);
    }
}
#pragma pop
extern "C" void fn_801013B0(void) {
    return;
}

extern "C" float fn_801013B4(void* arg0) {
    return *(float*)((char*)arg0 + 0x40);
}

extern "C" float fn_801013BC(void* arg0) {
    return *(float*)((char*)arg0 + 0x38);
}

extern "C" float fn_801013C4(void* arg0) { return *(float*)((char*)arg0 + 0x34); }

extern "C" float fn_801013CC(void* arg0) {
    return *(float*)((char*)arg0 + 0x2C);
}

extern "C" float fn_801013D4(void* arg0) {
    return *(float*)((char*)arg0 + 0x28);
}

extern "C" float fn_801013DC(void* arg0) {
    return *(float*)((char*)arg0 + 0x3C);
}

extern "C" float fn_801013E4(void* arg0) {
    return *(float*)((char*)arg0 + 0x24);
}

extern "C" int fn_801013EC(void* arg0) {
    return *((unsigned char*)arg0 + 0x20) != 0;
}

extern "C" int fn_80101400(void* arg0) {
    return *((unsigned char*)arg0 + 0x1E) != 0;
}

extern "C" int fn_80101414(void* arg0) {
    return *((unsigned char*)arg0 + 0x1F) != 0;
}

extern "C" int fn_80101428(void* arg0) {
    return *((unsigned char*)arg0 + 0x1D) != 0;
}
extern "C" int fn_800FEC1C(void*, const void*);
extern "C" int ReadWaveParam__Q46nw4hbm3snd6detail14WaveFileReaderCFPQ46nw4hbm3snd6detail8WaveDataPCv(void*, void*, const void*);
extern "C" char lbl_80327AF4[];
extern "C" void fn_800EC890(void*);
extern "C" float lbl_80561120;
#pragma push
#pragma use_lmw_stmw off
