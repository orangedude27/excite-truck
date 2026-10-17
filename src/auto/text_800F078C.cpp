// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern "C" void __dt__Q46nw4hbm3snd6detail9SeqPlayerFv(s32 arg0 = 0);


extern "C" void fn_800F0E64(s32);
extern "C" u32 lbl_8055DE48;

extern "C" void fn_800F07E4(s32 arg0) {
    __dt__Q46nw4hbm3snd6detail9SeqPlayerFv(arg0 - 8);
}

extern "C" void InitParam__Q44nw4r3snd6detail10BasicSoundFv(void);
extern "C" void fn_800EEE8C(void*, const void*);
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void);
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, unsigned int);
extern "C" void fn_80128668(void*);
extern "C" void* lbl_8032428C;
extern "C" void* lbl_80324060;
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void Setup__Q46nw4hbm3snd6detail9SeqPlayerFPQ46nw4hbm3snd6detail17SeqTrackAllocatorUliPQ46nw4hbm3snd6detail14NoteOnCallback(void*, unsigned long, int, int, void*);
extern "C" void fn_800F0850(void *arg0) {
    InitParam__Q44nw4r3snd6detail10BasicSoundFv();
    *(s32*)((u8*)arg0 + 0x1EC) = 0;
    *(s32*)((u8*)arg0 + 0x1F0) = 0;
}

extern "C" s32 fn_800F0E24(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x1E0) != 0;
}

extern "C" void fn_800F0E38(void* arg0) {
    fn_800F0E64(*(s32*)((u8*)arg0 + 0x1E0));
}

extern "C" s32 fn_800F0E40(s32 arg0) {
    return arg0 + 0xD8;
}

extern "C" s32 fn_800F0E48(s32 arg0) {
    return arg0 + 0xD8;
}

extern "C" u32* fn_800F0E50(void) {
    return &lbl_8055DE48;
}

