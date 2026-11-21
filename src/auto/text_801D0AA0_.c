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
static inline void initFields(u32 *o) {
    o[2] = 0x10;
    o[1] = 0;
}
void fn_801D0AA0(void) {
    u8* base = lbl_804386A8;
    register u32* o;
    fn_8000D838(&lbl_8055E8C8);
    o = (u32*)(base + 0x0C);
    o[0] = (u32)(o + 3);
    initFields(o);
    __register_global_object(o, (void*)fn_801D0B8C, (void*)((u8*)o - 0x0C));
    o = (u32*)(base + 0x64);
    initFields(o);
    o[0] = (u32)(o + 3);
    __register_global_object(o, (void*)fn_801D0B34, base + 0x58);
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
