#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_801B2EC0(void);
extern void *lbl_8055E678;
extern void *lbl_8055E680;
extern void *lbl_8055E684;
extern void *lbl_80435C30;
extern void *lbl_8055E694;

void fn_801B2C6C(void) {

}

void fn_801B2ED0(void) {
    fn_801B2EC0();
}

void* fn_801B2ED4(void) {
    return lbl_8055E680;
}

void fn_801B2EDC(s32 arg0, s32 arg1) {
    void *temp_r31;
    
    temp_r31 = (void *)((u8 *)lbl_8055E684 + (arg0 << 7));
    fn_801B179C(temp_r31, arg0, arg1);
}

void* fn_801B2F24(void) {
    return lbl_8055E678;
}

u8 fn_801B2F2C(s32 arg0) {
    return ((u8 *)lbl_8055E684)[(arg0 << 7) + 0x79];
}

s32 fn_801B2F40(s32 arg0) {
    return ((s32 *)lbl_80435C30)[arg0];
}

extern void *lbl_8055E694;
void* fn_801B307C(void) {
    return lbl_8055E694;
}

void fn_801B3284(void) {

}

void fn_801B3298(void) {

}

