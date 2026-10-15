// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 lbl_8055D400;
extern u8 lbl_8055D404;
extern u8 lbl_8055D405;
extern u8 lbl_8055D406;
extern u8 lbl_8055D407;
extern s32 lbl_8055D408;
extern s32 lbl_8055D40C;
extern s32 lbl_8055D420;
extern void **lbl_8055D414;
extern void **lbl_8055D418;
extern void **lbl_8055D41C;
extern s32 lbl_8055D410;

void fn_802066C8(void*, u32);
void fn_80128668(void*);
s32 fn_8000CCB8(void);
void fn_80209110(s32);

// Externs for fn_8000CE60
extern void *lbl_802FC058;
extern s32 fn_802090D4(void*);
extern void fn_80209190(f32);
extern s32 fn_80145E70(void*);
extern s32 fn_80207848(void*, s32);
extern f32 lbl_80560218;

// Externs for fn_8000D070, fn_8000D100
extern s32 fn_80209028(void);
extern s32 fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206444(void);
extern void fn_80209190_s32_f32(s32, f32);
extern void fn_80230E90(s32);
extern f32 lbl_80560234;

// Externs for fn_8000D100
extern void *lbl_802FC1CC;
extern void fn_80206454(void);
extern void fn_802E30C8(void*);
extern void fn_801769EC(void);

// Externs for fn_8000CCB8
extern s32 fn_800075A0(s32);
extern u32 __AXGetStackHead_80137CFC(s32);
extern s32 fn_802E8504(void);
extern s32 fn_80137C74(void);

s32 fn_8000CFA8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802066C8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_8000CE60(void) {
    void *base = &lbl_802FC058;
    u8 zero = 0;
    lbl_8055D404 = zero;
    lbl_8055D405 = zero;
    lbl_8055D407 = zero;
    lbl_8055D400 = 0;
    lbl_8055D408 = 0;
    lbl_8055D40C = 0;
    lbl_8055D410 = fn_802090D4((void*)((u8*)base + 0x140));
    fn_80209190(lbl_80560218);
    lbl_8055D414 = (void**)fn_80145E70((void*)((u8*)base + 0x14C));
    lbl_8055D418 = (void**)fn_80207848((void*)((u8*)base + 0x158), 0);
    lbl_8055D41C = (void**)fn_80207848((void*)((u8*)base + 0x164), 0);
    lbl_8055D420 = -1;
}

void fn_8000D070(void) {
    if (lbl_8055D418 != NULL) {
        f32 val = fn_80209028();
        f32 *ptr = (f32*)((u8*)lbl_8055D418 + 8);
        if (*(u32*)&val != *(u32*)ptr) {
            *(u8*)((u8*)lbl_8055D418 + 0x4D) = 1;
            *ptr = val;
        }
        *(u8*)((u8*)lbl_8055D418 + 0x49) = 1;
        *(u8*)((u8*)lbl_8055D418 + 0x4B) = 0;
        *(u8*)((u8*)lbl_8055D418 + 0x4A) = 0;
    }
    if (fn_80265D64() == 0) {
        __AXDSPInitCallback_801769E0();
    }
    fn_80206444();
    lbl_8055D400 = 0;
    fn_80209190_s32_f32(lbl_8055D410, lbl_80560234);
    fn_80230E90(1);
}

void fn_8000D100(void) {
    if (lbl_8055D41C != NULL) {
        f32 val = fn_80209028();
        f32 *ptr = (f32*)((u8*)lbl_8055D41C + 8);
        if (*(u32*)&val != *(u32*)ptr) {
            *(u8*)((u8*)lbl_8055D41C + 0x4D) = 1;
            *ptr = val;
        }
        *(u8*)((u8*)lbl_8055D41C + 0x49) = 1;
        *(u8*)((u8*)lbl_8055D41C + 0x4B) = 0;
        *(u8*)((u8*)lbl_8055D41C + 0x4A) = 0;
    }
    fn_80209190_s32_f32(lbl_8055D410, lbl_80560218);
    fn_80206454();
    if (lbl_8055D404 != 0) {
        fn_802E30C8(&lbl_802FC1CC);
        lbl_8055D404 = 0;
        return;
    }
    fn_801769EC();
}

s32 fn_8000CCB8(void) {
    s32 i = 0;
    s32 limit;
    limit = fn_80137C74();
    if (i < limit) {
        goto loop_body;
    }
    return -1;
loop_body:
    if (fn_800075A0(i) != 0) {
        __AXGetStackHead_80137CFC(i);
        if (fn_802E8504() == 0) {
            return i;
        }
    }
    i++;
    limit = fn_80137C74();
    if (i < limit) {
        goto loop_body;
    }
    return -1;
}
