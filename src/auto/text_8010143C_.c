// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void __register_global_object(void* p, void* dtor, void* allocator);
extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80101474(void*, s32);
#pragma push
#pragma small_data off
extern u8 lbl_8041D4B8[];
extern u8 lbl_8041D4C4[];
#pragma pop
void fn_8010143C(void) {
    void* ptr = &lbl_8041D4C4[4];
    *(void**)&lbl_8041D4C4[4] = 0;
    *(void**)&lbl_8041D4C4[8] = 0;
    *(void**)&lbl_8041D4C4[0] = 0;
    *(void**)&lbl_8041D4C4[4] = ptr;
    *(void**)&lbl_8041D4C4[8] = ptr;
    __register_global_object(&lbl_8041D4C4,
                             (void*)&__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80101474,
                             &lbl_8041D4B8);
}
