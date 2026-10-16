// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void __register_global_object(void* p, void* dtor, void* allocator);
#include <types.h>
extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FF9B8(void*, s32);
extern unsigned char lbl_8041D4A0[];
extern unsigned char lbl_8041D4AC[];
void fn_800FF980(void) {
    void* ptr = &lbl_8041D4AC[4];
    *(void**)&lbl_8041D4AC[4] = 0;
    *(void**)&lbl_8041D4AC[8] = 0;
    *(void**)&lbl_8041D4AC[0] = 0;
    *(void**)&lbl_8041D4AC[4] = ptr;
    *(void**)&lbl_8041D4AC[8] = ptr;
    __register_global_object(&lbl_8041D4AC,
                             (void*)&__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FF9B8,
                             &lbl_8041D4A0);
}
