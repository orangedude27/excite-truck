// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_80128668(void *);
extern void fn_801E9DC4(void *);
extern s32 lbl_80331C70[16];
extern f32 lbl_80561B78;
extern f32 lbl_80561B7C;
extern void fn_8017A580(void *);

void* fn_80179D08(void *arg0) {
    f32 a = lbl_80561B7C;
    f32 b = lbl_80561B78;
    *(s32 *)arg0 = (s32)&lbl_80331C70;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(f32 *)((u8 *)arg0 + 0x3C) = b;
    *(f32 *)((u8 *)arg0 + 0x40) = a;
    *(f32 *)((u8 *)arg0 + 0x44) = a;
    *(f32 *)((u8 *)arg0 + 0x48) = a;
    *(f32 *)((u8 *)arg0 + 0x4C) = b;
    *(f32 *)((u8 *)arg0 + 0x50) = a;
    *(f32 *)((u8 *)arg0 + 0x54) = a;
    *(f32 *)((u8 *)arg0 + 0x58) = a;
    *(f32 *)((u8 *)arg0 + 0x5C) = b;
    *(f32 *)((u8 *)arg0 + 0x60) = a;
    *(f32 *)((u8 *)arg0 + 0x64) = a;
    *(f32 *)((u8 *)arg0 + 0x68) = a;
    fn_8017A580(arg0);
    fn_801E9DC4((u8 *)arg0 + 0x6C);
    return arg0;
}

void fn_80179D8C(void *arg0, s32 arg1) {
    ((s32 *)arg0)[2] = arg1;
}

void fn_80179D94(void *arg0, void *arg1) {
    f32 a = lbl_80561B7C;
    f32 b = lbl_80561B78;
    *(s32 *)((u8 *)arg0 + 0xC) = (s32)arg1;
    *(f32 *)((u8 *)arg0 + 0x30) = a;
    *(f32 *)((u8 *)arg0 + 0x34) = a;
    *(f32 *)((u8 *)arg0 + 0x38) = a;
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    *(f32 *)((u8 *)arg0 + 0x2C) = a;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)arg1;
    *(s32 *)((u8 *)arg0 + 0x4) = 0;
    *(f32 *)((u8 *)arg0 + 0x3C) = b;
    *(f32 *)((u8 *)arg0 + 0x40) = a;
    *(f32 *)((u8 *)arg0 + 0x44) = a;
    *(f32 *)((u8 *)arg0 + 0x48) = a;
    *(f32 *)((u8 *)arg0 + 0x4C) = b;
    *(f32 *)((u8 *)arg0 + 0x50) = a;
    *(f32 *)((u8 *)arg0 + 0x54) = a;
    *(f32 *)((u8 *)arg0 + 0x58) = a;
    *(f32 *)((u8 *)arg0 + 0x5C) = b;
    *(f32 *)((u8 *)arg0 + 0x60) = a;
    *(f32 *)((u8 *)arg0 + 0x64) = a;
    *(f32 *)((u8 *)arg0 + 0x68) = a;
    fn_801E9DC4((u8 *)arg0 + 0x6C);
}

void fn_80179EE4(void) {

}

void fn_8017A004(void) {

}

void fn_8017A008(unsigned char *dst, unsigned char *src, int count) {
    while (1) {
        *dst++ = *src++;
        if (--count < 0) break;
    }
}

void fn_8017A578(void *arg0) {
    fn_8017A580(arg0);
}

void fn_8017A57C(void) {

}

void fn_8017A800(void) {

}

void fn_80179EE8(void*, s32);
void fn_80128668(void*);
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017B038(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80179EE8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_8017B090(void) {

}

int fn_8017B094(void) {
    return 0x14;
}

void fn_8017B09C(void* arg0, signed char* arg1) {
    *arg1 = 0;
}
extern int lbl_80331C28[64];

void** fn_8017ACCC(void** arg0) {
    fn_80179D08((void*)arg0);
    *arg0 = &lbl_80331C28;
    return arg0;
}
