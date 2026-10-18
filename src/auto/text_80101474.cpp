// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80128668(void);
extern int Pause__Q46nw4hbm3snd6detail7AxVoiceFb(int, unsigned char);
extern int ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(int);
extern int fn_800EAD00(void *);
extern "C" const char lbl_80328178[];
extern "C" const char lbl_8032818C[];
typedef int s32;
extern int fn_801013B0(int);
extern int InvalidateData__Q46nw4hbm3snd6detail9WsdPlayerFPCvPCv(int);
extern int fn_800FFA6C(int);
extern int fn_800EC890(void *, int, int, int);
extern float lbl_80561128;
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *fn_80128668(void *);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80101474(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801014CC(s32 arg0) {
    fn_801013B0(arg0 - 8);
}

extern "C" void fn_801014D4(s32 arg0) {
    InvalidateData__Q46nw4hbm3snd6detail9WsdPlayerFPCvPCv(arg0 - 8);
}

extern "C" void fn_801014DC(s32 arg0) {
    fn_800FFA6C(arg0 - 8);
}

extern int fn_800EC890(void *, void *, int, int, int);
void Init__Q46nw4hbm3snd6detail8WsdTrackFPQ46nw4hbm3snd6detail9WsdPlayer(void *arg0, void *arg1) {
    *(void **)((char *)arg0 + 0x2C) = arg1;
    *(int *)((char *)arg0 + 0) = 0;
    *(int *)((char *)arg0 + 4) = -1;
    *(unsigned char *)((char *)arg0 + 0x1D) = 0x40;
    *(unsigned char *)((char *)arg0 + 0x1C) = 2;
    *(float *)((char *)arg0 + 0x20) = lbl_80561128;
    *(unsigned char *)((char *)arg0 + 0x24) = 0x40;
    *(unsigned char *)((char *)arg0 + 0x25) = 0;
    *(unsigned char *)((char *)arg0 + 0x26) = 0;
    *(unsigned char *)((char *)arg0 + 0x27) = 0;
    *(unsigned char *)((char *)arg0 + 0x28) = 0;
    *(unsigned char *)((char *)arg0 + 0x29) = 0x7F;
    fn_800EC890((char *)arg0 + 0xC, arg1, 2, 0x40, -1);
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 0x30) = 0;
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

extern "C" void UpdateChannel__Q46nw4hbm3snd6detail8WsdTrackFv(void *);
extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void *Instance__15EmissionManagerFv(void);
extern "C" void fn_800E402C(void *);
extern "C" void fn_800E4064(void *);
extern "C" void SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void Release__Q46nw4hbm3snd6detail7ChannelFv(void *);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(void *arg0, int arg1) {
    void *channel;
    int interrupts;
    UpdateChannel__Q46nw4hbm3snd6detail8WsdTrackFv(arg0);
    interrupts = OSDisableInterrupts();
    fn_800E402C(Instance__15EmissionManagerFv());
    channel = *(void **)((char *)arg0 + 0x30);
    while (channel != 0) {
        if (*(unsigned char *)((char *)channel + 0x3A) != 0) {
            if (arg1 >= 0) {
                if (arg1 > 0x7F) {
                    Panic__Q26nw4hbm2dbFPCciPCce("snd_WsdTrack.cpp", 0xA0, "release", arg1, 0, 0x7F);
                }
                SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, arg1);
            }
            Release__Q46nw4hbm3snd6detail7ChannelFv(channel);
        }
        channel = *(void **)((char *)channel + 0xE4);
    }
    fn_800E4064(Instance__15EmissionManagerFv());
    OSRestoreInterrupts(interrupts);
}

void PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(void *arg0, unsigned char arg1) {
    void *channel = *(void **)((char *)arg0 + 0x30);
    do {
        if (*(unsigned char *)((char *)channel + 0x3A) &&
            arg1 != (unsigned int)(*(unsigned char *)((char *)channel + 0x39) != 0)) {
            *(unsigned char *)((char *)channel + 0x39) = arg1;
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(int *)((char *)channel + 0xE0), arg1);
        }
        channel = *(void **)((char *)channel + 0xE4);
    } while (channel != 0);
}

extern "C" s32 fn_801033F0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" int GetFont__Q36nw4hbm2ut10CharWriterCFv(void *arg0) {
    unsigned int top = (unsigned int)arg0 & 0xFF000000U;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    if (top + 0x80000000U != 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0) r10 = 0;
    if (r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0) r9 = 0;
    if (r9 == 0 && top + 0x40000000U != 0) r8 = 0;
    if (r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0) r7 = 0;
    if (r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0) r6 = 0;
    if (r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x97, "this", arg0);
    return *(int *)((char *)arg0 + 0x48);
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv(void *arg0) {
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = 1; var_r6 = 1; var_r7 = 1; var_r8 = 1; var_r9 = 1; var_r10 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) != 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) != 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x20A, "this", arg0);
    return *(float *)((char *)arg0 + 0x24);
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(void *arg0) {
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) != 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) != 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x21A, "this", arg0);
    return *(float *)((char *)arg0 + 0x28);
}

extern "C" unsigned char IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(void *arg0) {
    unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    int var_r10=1, var_r5=1, var_r6=1, var_r7=1, var_r8=1, var_r9=1;
    if ((temp_r11+0x80000000U)!=0U && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0U) var_r10=0;
    if (var_r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0U) var_r9=0;
    if (var_r9==0 && (temp_r11+0x40000000U)!=0U) var_r8=0;
    if (var_r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0U) var_r7=0;
    if (var_r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0U) var_r6=0;
    if (var_r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0U) var_r5=0;
    if (var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x2E2, "this", arg0);
    return *(unsigned char *)((char *)arg0+0x43);
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(void *arg0) {
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = 1; var_r6 = 1; var_r7 = 1; var_r8 = 1; var_r9 = 1; var_r10 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) != 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) != 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x301, lbl_8032818C, arg0);
    return *(float *)((char *)arg0 + 0x44);
}

extern "C" const char lbl_80328178[];
extern "C" const char lbl_8032818C[];
extern "C" void SetCursor__Q36nw4hbm2ut10CharWriterFff(void *arg0, float x, float y) {
    unsigned int top = (unsigned int)arg0 & 0xFF000000;
    int r10 = 1, r9 = 1, r8 = 1, r7 = 1, r6 = 1, r5 = 1;
    if (top + 0x80000000U != 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0) r10 = 0;
    if (r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0) r9 = 0;
    if (r9 == 0 && top + 0x40000000U != 0) r8 = 0;
    if (r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0) r7 = 0;
    if (r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0) r6 = 0;
    if (r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x36F, "this", arg0);
    *(float *)((char *)arg0 + 0x2C) = x;
    *(float *)((char *)arg0 + 0x30) = y;
}

extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf(void *arg0, float farg0) {
    unsigned int temp_r11;
    int var_r10, var_r5, var_r6, var_r7, var_r8, var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = var_r6 = var_r7 = var_r8 = var_r9 = var_r10 = 1;
    if ((temp_r11 + 0x80000000U >= 1U) && (((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U >= 1U)) var_r10 = 0;
    if (var_r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U >= 1U)) var_r9 = 0;
    if (var_r9 == 0 && temp_r11 + 0x40000000U >= 1U) var_r8 = 0;
    if (var_r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U >= 1U)) var_r7 = 0;
    if (var_r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U >= 1U)) var_r6 = 0;
    if (var_r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U >= 1U) ) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x3C5, "this", arg0);
    *(float *)((char *)arg0 + 0x2C) = farg0;
}

extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(void *arg0, float farg0) {
 int var_r5=1; int var_r6=1; int var_r7=1; int var_r8=1; int var_r9=1; int var_r10=1;
 unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
 if ((temp_r11+0x80000000U)>=1U && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)>=1U) var_r10=0;
 if (var_r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)>=1U) var_r9=0;
 if (var_r9==0 && (temp_r11+0x40000000U)>=1U) var_r8=0;
 if (var_r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)>=1U) var_r7=0;
 if (var_r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)>=1U) var_r6=0;
 if (var_r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)>=1U) var_r5=0;
 if(var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x3D5,lbl_8032818C,arg0);
 *(float*)((char*)arg0+0x30)=farg0;
}

extern "C" void MoveCursorX__Q36nw4hbm2ut10CharWriterFf(void *arg0, float dx) {
    unsigned int top = (unsigned int)arg0 & 0xFF000000;
    int r10=1,r9=1,r8=1,r7=1,r6=1,r5=1;
    if (top+0x80000000U != 0 && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0) r10=0;
    if (r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0) r9=0;
    if (r9==0 && top+0x40000000U!=0) r8=0;
    if (r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0) r7=0;
    if (r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0) r6=0;
    if (r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0) r5=0;
    if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp",0x3F5,"this",arg0);
    *(float *)((char *)arg0+0x2C) += dx;
}

extern "C" void MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(void *arg0, float dx) {
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r10 = 1;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) != 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) != 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x405, lbl_8032818C, arg0);
    *(float *)((char *)arg0 + 0x30) += dx;
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(void *arg0) {
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = 1; var_r6 = 1; var_r7 = 1; var_r8 = 1; var_r9 = 1; var_r10 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) > 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) > 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) > 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) > 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) > 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) > 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) > 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x425, lbl_8032818C, arg0);
    return *(float *)((char *)arg0 + 0x2C);
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(int arg0) {
 unsigned int temp_r11=(unsigned int)arg0&0xFF000000U;
 int var_r10=1;
 int var_r9=1;
 int var_r8=1;
 int var_r7=1;
 int var_r6=1;
 int var_r5=1;
 if ((temp_r11+0x80000000U)!=0U && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0U) var_r10=0;
 if (var_r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0U) var_r9=0;
 if (var_r9==0 && temp_r11+0x40000000U!=0U) var_r8=0;
 if (var_r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0U) var_r7=0;
 if (var_r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0U) var_r6=0;
 if (var_r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0U) var_r5=0;
 if (var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x435,lbl_8032818C,arg0);
 return *(float*)((char*)arg0+0x30);
}

extern "C" void GXSetFog(int, void *, unsigned char, unsigned char, float, float, float, float);
extern "C" void GXSetTevSwapModeTable(int, int, int, int, int);
extern "C" void GXSetZTexture(int, int, int);
extern "C" void GXSetNumChans(int);
extern "C" void GXSetChanCtrl(int, int, int, int, int, int, int);
extern "C" void GXSetNumTexGens(int);
extern "C" void GXSetTexCoordGen2(int, int, int, int, int, int);
extern "C" void GXSetNumIndStages(int);
extern "C" void GXSetBlendMode(int, int, int, int);
extern "C" void GXSetNumTevStages(int);
extern "C" void GXSetTevDirect(int);
extern "C" void GXSetTevSwapMode(int, int, int);
extern "C" void GXSetTevOrder(int, int, int, int);
extern "C" void GXSetTevColor(int, void *, int, int, int);
extern "C" void GXSetTevColorIn(int, int, int, int, int);
extern "C" void GXSetTevAlphaIn(int, int, int, int, int);
extern "C" void GXSetTevColorOp(int, int, int, int, int, int);
extern "C" void GXSetTevAlphaOp(int, int, int, int, int, int);
extern "C" void GXSetVtxAttrFmt(int, int, int, int, int);
extern "C" void GXClearVtxDesc(void);
extern "C" void GXSetVtxDesc(int, int);
extern "C" void __register_global_object(void *, void *, void *);
extern "C" void fn_800D2DD4(void);
extern "C" unsigned char lbl_8055DE90;
extern "C" unsigned char lbl_8055DE94, lbl_8055DE95, lbl_8055DE96, lbl_8055DE97;
extern "C" float lbl_80561150;
extern "C" unsigned char lbl_8041D4D0;
extern "C" void SetupGXWithColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color(unsigned int arg0, unsigned int arg1) {
    unsigned char sp8[4], spc[4], sp10[4];
    unsigned char r, g, b;
    if ((signed char)lbl_8055DE90 == 0) {
        lbl_8055DE94 = 0;
        __register_global_object(&lbl_8055DE94, fn_800D2DD4, (void *)0x8041D4D0);
        lbl_8055DE90 = 1;
    }
    sp8[0]=lbl_8055DE94; sp8[1]=lbl_8055DE95; sp8[2]=lbl_8055DE96; sp8[3]=lbl_8055DE97;
    GXSetFog(0, sp8, lbl_8055DE96, lbl_8055DE95, lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
    GXSetTevSwapModeTable(0,0,1,2,3); GXSetZTexture(0,0x11,0); GXSetNumChans(1);
    GXSetChanCtrl(4,0,0,1,0,0,2); GXSetChanCtrl(5,0,0,0,0,0,2);
    GXSetNumTexGens(1); GXSetTexCoordGen2(0,1,4,0x3c,0,0x7d); GXSetNumIndStages(0);
    GXSetBlendMode(1,4,5,0xf); GXSetNumTevStages(2); GXSetTevDirect(0); GXSetTevDirect(1);
    GXSetTevSwapMode(0,0,0); GXSetTevSwapMode(1,0,0); GXSetTevOrder(0,0,0,0xff);
    r=((unsigned char *)&arg0)[0]; g=((unsigned char *)&arg0)[1]; b=((unsigned char *)&arg0)[2];
    sp10[0]=r; sp10[1]=g; sp10[2]=b; sp10[3]=((unsigned char *)&arg0)[3]; GXSetTevColor(1,sp10,b,g,r);
    r=((unsigned char *)&arg1)[0]; g=((unsigned char *)&arg1)[1]; b=((unsigned char *)&arg1)[2];
    spc[0]=r; spc[1]=g; spc[2]=b; spc[3]=((unsigned char *)&arg1)[3]; GXSetTevColor(2,spc,b,g,r);
    GXSetTevColorIn(0,2,4,8,0xf); GXSetTevAlphaIn(0,1,2,4,7);
    GXSetTevColorOp(0,0,0,0,1,0); GXSetTevAlphaOp(0,0,0,0,1,0);
    GXSetTevOrder(1,0xff,0xff,4); GXSetTevColorIn(1,0xf,0,0xa,0xf); GXSetTevAlphaIn(1,7,0,5,7);
    GXSetTevColorOp(1,0,0,0,1,0); GXSetTevAlphaOp(1,0,0,0,1,0);
    GXSetVtxAttrFmt(0,9,1,4,0); GXSetVtxAttrFmt(0,0xb,1,5,0); GXSetVtxAttrFmt(0,0xd,1,2,0xf);
    GXClearVtxDesc(); GXSetVtxDesc(9,1); GXSetVtxDesc(0xb,1); GXSetVtxDesc(0xd,1);
}
namespace nw4hbm { namespace ut { struct Glyph { unsigned char pad[0x14]; unsigned short x; unsigned char pad16[2]; unsigned char y; unsigned char pad19[7]; unsigned short width; unsigned short height; unsigned char pad20[0x20]; }; class CharWriter { public: void PrintGlyph(float, float, float, const Glyph&); }; }}
