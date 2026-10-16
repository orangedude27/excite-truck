// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <MSL/extras.h>

extern void fn_80128668(void*);
extern void fn_802C6CF8(void*);
extern struct {
    char* unk_0x0;
    s32 unk_0x4;
    u8 unk_0x8[4];
} lbl_80430340;

void fn_8016A0AC(void) {
}

void fn_8016A68C(void* arg0) {
    fn_8016B634(fn_8016B598(arg0));
}

s32 fn_8016A878(const char* arg0) {
    s32 count = 0;
    s32 i = 0;
    s32 offset = 0;
    for (; i < lbl_80430340.unk_0x4; i++) {
        if (stricmp(lbl_80430340.unk_0x0 + offset + 1, arg0) == 0) count++;
        offset += 0x2C;
    }
    return count;
}

void fn_8016AC18(u8* arg0) { *arg0 = 0; }

void* fn_8016AC24(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (*(u8*)arg0 != 0) {
            fn_802C6CF8(*(void**)((u8*)arg0 + 0x20));
            *(u8*)arg0 = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8016B4F0(u8* arg0) { *arg0 = 0; }

void fn_8016B544(u8* arg0) { *arg0 = 0; }

