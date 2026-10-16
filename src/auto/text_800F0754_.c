// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void __register_global_object(void* p, void* dtor, void* allocator);
extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F078C(void*, s32);
#pragma push
#pragma small_data off
extern u8 lbl_80412A60[];
extern u8 lbl_80412A6C[];
#pragma pop

void fn_800F0754(void) {
    void* ptr = &lbl_80412A6C[4];
    *(void**)&lbl_80412A6C[4] = 0;
    *(void**)&lbl_80412A6C[8] = 0;
    *(void**)&lbl_80412A6C[0] = 0;
    *(void**)&lbl_80412A6C[4] = ptr;
    *(void**)&lbl_80412A6C[8] = ptr;
    __register_global_object(&lbl_80412A6C,
                             (void*)&__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F078C,
                             &lbl_80412A60);
}
