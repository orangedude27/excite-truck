// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_802C6CF8(s32);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void fn_801EAB2C(void*);
extern void fn_801EAB80(void*, s32);
extern u8 lbl_80339E3C[];

extern int fn_80176948(int, int, int);
extern float lbl_80562E60;
extern float lbl_80562E64;
extern short lbl_80562E28;
extern int lbl_80339E60;
void fn_801EAB2C(void *arg0) {
    float a = lbl_80562E60;
    float b = lbl_80562E64;
    float *p = (float *)arg0;
    *(int *)arg0 = (int)&lbl_80339E60;
    p[1] = a;
    p[2] = b;
    p[3] = b;
    p[4] = b;
    p[5] = a;
    p[6] = b;
    p[7] = b;
    p[8] = b;
    p[9] = a;
    p[10] = b;
    p[11] = b;
    p[12] = b;
    *(short *)((char *)arg0 + 0x38) = lbl_80562E28;
}

void fn_801EAB80(void *arg0, long arg1) {
    fn_80176948(arg1, (long)arg0 + 0x34, (long)arg0);
}

void fn_801EAB90(void *arg0, int arg1) {
    int offset = *(int *)((char *)arg0 + 0x34);
    void **vtable = *(void ***)arg0;
    ((void (*)(void *, int))vtable[8])(arg0, arg1 + offset);
}

s16 fn_801EAC3C(void* arg0) {
    return *(s16*)((u8*)arg0 + 0x38);
}

void* fn_801EAC44(void* this_, s32 arg1, s32 arg2) {
    fn_801EAB2C(this_);
    *(u32*)this_ = (u32)lbl_80339E3C;
    *(s32*)((u8*)this_ + 0x3C) = fn_802C6FC0(arg2, 0, 0);
    fn_801EAB80(this_, arg1);
    return this_;
}

s32 fn_801EACB8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void* __dt__Q28PSSystem7SeqHeapFv_801EACF8(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_80339E3C;
        fn_802C6CF8(*(s32*)((u8*)this_ + 0x3C));

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

void fn_801EAD5C(void* arg0) {
    fn_802C744C(*(s32*)((u8*)arg0 + 0x3C), (u8*)arg0 + 4);
}

s32 fn_801EAF20(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801EAF60(void) {

}
extern void *fn_802C86DC(void);
extern float PSVECDotProduct(float *, float *, float);
extern void fn_801EABA8(void);
extern void fn_802DAC54(void);
extern int fn_802C7A40(int, void *, int, int, void *, int);
extern void fn_802C70AC(int, void *, int, int);
extern int lbl_80488228;
extern int fn_80128668(void);
extern void fn_802C6CF8(s32);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void fn_801EAB2C(void*);
extern void fn_801EAB80(void*, s32);
extern u8 lbl_80339E3C[];
