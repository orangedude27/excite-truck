// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...) __attribute__((noreturn));
extern "C" float fn_80100A88(void* arg0) { return *(float*)((char*)arg0 + 0x4C); }

extern "C" void fn_80100BAC(void* arg0, int arg1) {
    int level = OSDisableInterrupts();
    *(int*)((char*)arg0 + 0x44) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" int fn_80100BEC(void* arg0) {
    return *(int*)((char*)arg0 + 0x44);
}

extern "C" char lbl_80327930[];
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

extern "C" char lbl_80327C58[];
extern "C" char lbl_80327C7C[];
extern "C" char lbl_80327AC4[];
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

void fn_801013B0(void) {
    return;
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

