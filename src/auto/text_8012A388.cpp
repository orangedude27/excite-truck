#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8012E498(void);
extern void fn_8012CC24(void);

extern "C" void fn_8012A46C(void) {

}

extern "C" void fn_8012AC28(s32, s32);
extern "C" void fn_8012AC98(s32 arg0) {
    fn_8012AC28(arg0, 0);
}

extern "C" void fn_8012B324(void) {

}

extern "C" void fn_8012B328(void) {

}

extern "C" void fn_8012DDA8(s32);
extern "C" void fn_8012E81C(s32);
extern "C" void fn_8012BEF0(s32 arg0) {
    fn_8012DDA8(arg0);
    fn_8012E81C(arg0);
}

extern "C" void fn_8012BF24(void) {
    fn_8012E498();
}

extern "C" void fn_8012CC20(void) {
    fn_8012CC24();
}

extern "C" void fn_8012D40C(s32);
extern "C" void fn_8012D1A8(s32);
extern "C" void fn_8012D3D8(s32 arg0) {
    fn_8012D40C(arg0);
    fn_8012D1A8(arg0);
}

extern "C" s32 fn_80128668(void *);
extern "C" s32 fn_8012DCC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

extern "C" void fn_80127E28(void *);
extern "C" u8 lbl_8032ACB0[];
extern "C" void **lbl_8055E014;
extern "C" s32 fn_8012CAA0(s32);
extern "C" void fn_8012DD00(void) {
    if (lbl_8055E014) {
        if (lbl_8055E014) {
            ((void (*)(void *, int))(*(void ***)lbl_8055E014)[2])(lbl_8055E014, 1);
        }
        lbl_8055E014 = 0;
    }
}

extern "C" void *__dt__Q34nw4r2ef6EffectFv(void *arg0, s32 arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_8032ACB0;
        fn_80127E28(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8012DFCC(void *arg0, void *arg1) {
    **(void ***)((u8 *)arg0 + 4) = arg1;
    *(void ***)((u8 *)arg0 + 4) = (void **)((u8 *)arg1 + 4);
    *(s32 *)((u8 *)arg1 + 4) = 0;
}

extern "C" void fn_8012DFE8(void *arg0, const char *arg1, s32 arg2) {
    char *dst = (char *)arg0 + 0xc;
    int count = 0x40;
    while ((*dst++ = *arg1++) != 0) {
        if (--count <= 0) {
            dst[-1] = 0;
            break;
        }
    }
    *(s32 *)((u8 *)arg0 + 0x4c) = fn_8012CAA0(arg2);
    *(s32 *)((u8 *)arg0 + 8) = 1;
}

extern "C" s32 fn_8012E490(s32 *arg0) {
    return *arg0;
}

extern "C" s32 fn_8012E674(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

extern "C" s32 fn_8012EE78(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

extern "C" s32 fn_8012BC50(void *arg0, void *arg1, s32 arg2);

extern "C" s32 fn_8012C4E4(void *arg0, void *arg1, s32 arg2) {
    return fn_8012BC50(arg0, arg1, arg2);
}

