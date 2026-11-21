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
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma cplusplus on
struct RegObjC {
    u32 data;
    u32 count;
    u32 capacity;
    inline void init();
};
inline void RegObjC::init() {
    data = (u32)((u8 *)this + 0xC);
    capacity = 0x10;
    count = 0;
}
extern "C" void fn_801D0AA0(void) {
    u8* base = lbl_804386A8;
    RegObjC *o;
    fn_8000D838(&lbl_8055E8C8);
    o = (RegObjC*)(base + 0x0C);
    o->init();
    __register_global_object(o, (void*)fn_801D0B8C, (void*)((u8*)o - 0x0C));
    o = (RegObjC*)(base + 0x64);
    o->init();
    __register_global_object(o, (void*)fn_801D0B34, base + 0x58);
}
#pragma cplusplus reset
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
