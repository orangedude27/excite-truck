// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" float lbl_80561124;
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
extern "C" void StopAllPlayers__Q46nw4hbm3snd6detail9SeqPlayerFv_80101300(void) {
    char* end = lbl_8041D4C4 + 4;
    char* node = *(char**)(lbl_8041D4C4 + 4);
    while (node != end) {
        char* current = node;
        node = *(char**)node;
        if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327C7C, 0x23D, lbl_80327C58);
        void** vtable = *(void***)((char*)current - 0x14);
        (*(void (**)(void*))(vtable[4]))((char*)current - 0x14);
    }
    if (*(int*)lbl_8041D4C4 != 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327930, 0x24D, lbl_80327AC4);
}

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
