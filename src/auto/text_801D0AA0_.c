// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_8000D838(void*);
extern void __register_global_object(void*, void*, void*);
#pragma push
#pragma small_data off
extern u8 lbl_804386A8[];
#pragma pop
extern u8 lbl_8055E8C8;
extern void fn_801D0B8C(void);
extern void fn_801D0B34(void);
void fn_801D0AA0(void) {
    u8 *base = lbl_804386A8;
    u8 *p;
    fn_8000D838(&lbl_8055E8C8);
    p = base + 0xC;
    *(void **)(base + 0xC) = p + 0xC;
    *(u32 *)(p + 8) = 0x10;
    *(u32 *)(p + 4) = 0;
    __register_global_object(p, (void *)fn_801D0B8C, base);
    p = base + 0x64;
    *(u32 *)(p + 8) = 0x10;
    *(void **)(base + 0x64) = p + 0xC;
    *(u32 *)(p + 4) = 0;
    __register_global_object(p, (void *)fn_801D0B34, base + 0x58);
}
