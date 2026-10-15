// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#pragma opt_tail_call on

extern "C" void fn_8019EBC0(void);
extern "C" void fn_8019F3D0(void);
extern "C" void fn_801A49E8(void*);
extern "C" void fn_801796EC(s32, s32*, s32);

void fn_8019F1A4(void) __attribute__((noreturn));

extern "C" void fn_8019F3D0(void) {

}

void fn_8019F560(void) {
    fn_8019F1A4();
}

extern "C" void fn_8019FF88(void) {
    fn_8019EBC0();
}

extern "C" void fn_801A2EC8(void) {

}

void fn_801A4768(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_801A47C8(void* arg0) {
    s32 count = 0;
    s32* ptr = *(s32**)((u8*)arg0 + 4);
    s32 limit = *(s32*)((u8*)arg0);
    for (s32 i = 0; i < limit; i++) {
        ((u8*)ptr)[0x40] = 1;
        ptr++;
    }
}

extern "C" void fn_801A4868(void);

extern "C" void fn_801A518C(void) {
    fn_801A4868();
}

