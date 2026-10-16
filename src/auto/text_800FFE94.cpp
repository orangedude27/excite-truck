// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...) __attribute__((noreturn));
extern "C" void fn_80100BAC(void* arg0, int arg1) {
    int level = OSDisableInterrupts();
    *(int*)((char*)arg0 + 0x44) = arg1;
    OSRestoreInterrupts(level);
}

extern "C" int fn_80100BEC(void* arg0) {
    return *(int*)((char*)arg0 + 0x44);
}

extern "C" char lbl_80327930[];
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

void fn_801013B0(void) {
    return;
}

extern "C" float fn_801013D4(void* arg0) {
    return *(float*)((char*)arg0 + 0x28);
}

extern "C" float fn_801013DC(void* arg0) {
    return *(float*)((char*)arg0 + 0x3C);
}

extern "C" int fn_801013EC(void* arg0) {
    return *((unsigned char*)arg0 + 0x20) != 0;
}

extern "C" int fn_80101400(void* arg0) {
    return *((unsigned char*)arg0 + 0x1E) != 0;
}

