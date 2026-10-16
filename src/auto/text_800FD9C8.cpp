// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void* this_, u32 a);
extern "C" void fn_8002F634(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern "C" void fn_80128668(void* arg0);
extern "C" void fn_800FB374(void);
extern "C" void fn_800FDE28(void* arg0);
extern "C" u32 lbl_8055DE70;

extern "C" u32 lbl_8055DE70;
extern "C" void fn_800FDE28(void* arg0);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void* this_, u32 a);
extern "C" void fn_8002F634(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern "C" void fn_80128668(void* arg0);
extern "C" void fn_800FB374(void);
extern "C" void* __dt__Q46nw4hbm3snd6detail9StrmSoundFv(void* arg0, s32 arg1) {
    if (arg0 != NULL) {
        if ((u8*)arg0 + 0xD8 != NULL) {
            fn_8002F634((u8*)arg0 + 0x184, &fn_800FB374, 0x1C, 0x20);
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8*)arg0 + 0x178, 0);
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8*)arg0 + 0x16C, 0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_800FDE04(s8* arg0) {
    return (s32)(arg0 + 0xD8);
}

