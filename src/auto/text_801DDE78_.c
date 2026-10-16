// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;
typedef unsigned long u32;
typedef float f32;
typedef s32 (*UnkFunc)(s32);
extern void* lbl_8055E9C0;
extern void* lbl_8055E9BC;
extern void* lbl_8055E9C4;
extern void* lbl_8055E9C8;
extern void* lbl_8055E9CC;
extern s32 lbl_80339478;
s32 fn_80145E70(s32*);
s32 fn_802E2C20(void);
void fn_801DE0A4(void) {
    lbl_8055E9BC = 0;
    lbl_8055E9C8 = 0;
    lbl_8055E9C4 = 0;
    lbl_8055E9C0 = (void*)fn_80145E70(&lbl_80339478);
    lbl_8055E9CC = (void*)fn_802E2C20();
}

void fn_801DE12C(void) {
    lbl_8055E9CC = (void*)fn_802E2C20();
}

void fn_801DE150(void) {

}
