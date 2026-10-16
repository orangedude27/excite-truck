// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
extern f32 fn_801E8738(s32);
extern void fn_801EA210();
extern void fn_801EA28C(s32, f32);
extern void fn_801FC904(void);
extern void fn_801EBF00(void);
extern void fn_801FC908(s32);
extern void fn_802C990C(s32);
extern void fn_802C86E8(s32);
extern void fn_802C2B78(f32, f32, f32);
extern f32 lbl_80562E58;
extern f32 lbl_80562E5C;
extern u8 lbl_8055EB59;
extern u8 lbl_8055EB60[5];

void fn_801EA318(void) {

}

void fn_801EA38C(void) {
    fn_801EBC2C();
}

void fn_801EA390(void) {
    fn_801EBC70();
}

void fn_801EA394(void) {
    if (lbl_8055EB60[4] != 0)
        fn_802C86E8(0xFF000000);
    else
        fn_802C86E8(0xFFC9C9EA);
}

void fn_801EA3B8(void) {
    fn_802C990C(0xC9C9EB);
    fn_802C86E8(0xFF000000);
    fn_802C2B78(lbl_80562E58, lbl_80562E5C, lbl_80562E58);
    lbl_8055EB59 = 0;
}

void fn_801EA400(void) {
    fn_801EBCAC();
}

void fn_801EA404(s32 arg0, s32 arg1) {
    f32 temp_f31 = fn_801E8738(-1);
    fn_801EA210(-1);
    fn_801FC904();
    fn_801EA28C(-1, temp_f31);
    fn_801EBF00();
    fn_801EA210(-1, temp_f31);
    fn_801FC908(arg1);
}

extern char lbl_8055EB58;
char fn_801EA470(void) {
    return lbl_8055EB58;
}

void fn_801EA478(s32 arg0) {
    fn_801E8738(arg0);
    fn_801EA210(arg0);
}

