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
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(void *, s32, void *);
extern "C" s32 fn_800E9B88(void *);
extern "C" s32 fn_800E9B9C(void *);
extern "C" void *lbl_80325C00;
extern "C" void *lbl_80325C18;
extern "C" s32 detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(s32);

M2C_UNK GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);

extern "C" s32 GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);
extern "C" s32 ConvertLabelStringToId__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPCQ56nw4hbm3snd6detail16SoundArchiveFile10StringTreePCc(void *, void *, s32);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(void *, s32, void *);
extern "C" void *lbl_803247E0;
extern "C" void *lbl_803247F8;
extern "C" s32 fn_800F26FC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800F273C(void *arg0) {
    s32 val = *(s32*)((u8*)arg0 + 4);
    s32 neg = -val;
    s32 combined = neg | val;
    return (combined >> 31) & 1;
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

void fn_800F27C4(void *arg0) {
    GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(*(s32*)((u8*)arg0 + 4));
}

void fn_800F27D4(void *arg0, s32 arg1) {
    void *r3 = *(void**)((u8*)arg0 + 4);
    s32 r4 = *(s32*)((u8*)r3 + 0x34);
    ConvertLabelStringToId__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFPCQ56nw4hbm3snd6detail16SoundArchiveFile10StringTreePCc(r3, (void*)r4, arg1);
}

extern "C" s32 fn_800F420C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4D04(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F4D84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800F81AC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern s32 detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(s32);
extern s32 fn_800E9B88(void *);
extern s32 fn_800E9B9C(void *);
extern void *lbl_80325C00;
extern void *lbl_80325C18;
extern s32 fn_80128668(void);
extern "C" s32 fn_800F81EC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800F822C(s32 arg0) {
    detail_ConvertLabelStringToSoundId__Q36nw4hbm3snd18SoundArchivePlayerFPCc(arg0 - 0xC);
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

