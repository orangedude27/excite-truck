// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef float f32;
typedef int BOOL;
extern s32 fn_8023905C(void);
extern s32 fn_80128668(void);
extern s32 fn_802E2C20(void);
extern void fn_80238FCC(u32);
s32 fn_8023964C(s32 arg0) {
    fn_8023905C();
    return arg0;
}

void fn_8023976C(void *arg0) {
    if (*(u32 **)((u8 *)arg0 + 0x14) != 0) {
        fn_80238FCC(*(u32 *)((u8 *)arg0 + 8));
    }
}
