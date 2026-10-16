// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80128668(void);
extern int Pause__Q46nw4hbm3snd6detail7AxVoiceFb(int, unsigned char);
extern int ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(int);
extern int fn_800EAD00(void *);
typedef int s32;
extern int fn_801013B0(int);
extern int InvalidateData__Q46nw4hbm3snd6detail9WsdPlayerFPCvPCv(int);
extern int fn_800FFA6C(int);
extern int fn_800EC890(void *, int, int, int);
extern float lbl_80561128;
extern "C" void fn_801014CC(s32 arg0) {
    fn_801013B0(arg0 - 8);
}

extern "C" void fn_801014D4(s32 arg0) {
    InvalidateData__Q46nw4hbm3snd6detail9WsdPlayerFPCvPCv(arg0 - 8);
}

extern "C" void fn_801014DC(s32 arg0) {
    fn_800FFA6C(arg0 - 8);
}

void NWC24Data_SetDataP(void *arg0, int arg1, int arg2) {
    *(int *)arg0 = arg1;
    *((int *)arg0 + 1) = arg2;
}

void Close__Q46nw4hbm3snd6detail8WsdTrackFv(void *arg0) {
    void *var_r31;
    ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(-1);
    var_r31 = *(void **)((char *)arg0 + 0x30);
loop_2:
    if (var_r31 != 0) {
        fn_800EAD00(var_r31);
        var_r31 = *(void **)((char *)var_r31 + 0xE4);
        goto loop_2;
    }
    *(void **)((char *)arg0 + 0x30) = 0;
}

void PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(void *arg0, unsigned char arg1) {
    void *var_r31 = *(void **)((char *)arg0 + 0x30);
loop_5:
    if (var_r31 != 0) {
        if (*(unsigned char *)((char *)var_r31 + 0x3A) != 0 &&
            arg1 != (unsigned int)(*(unsigned char *)((char *)var_r31 + 0x39) != 0)) {
            *(unsigned char *)((char *)var_r31 + 0x39) = arg1;
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(int *)((char *)var_r31 + 0xE0), arg1);
        }
        var_r31 = *(void **)((char *)var_r31 + 0xE4);
        goto loop_5;
    }
}

extern "C" s32 fn_801033F0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}
