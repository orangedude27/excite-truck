// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
extern f32 fn_801E8738(s32);
extern void fn_801EA28C(s32, f32);
extern void fn_801FC904(void);
extern void fn_801EBF00(void);
extern void fn_801FC908(s32);
extern void fn_802C990C(s32);
extern void fn_802C86E8(s32);
extern void fn_802C2B78(f32, f32, f32);
extern f32 lbl_8055AF68;
extern f32 lbl_80562E38;
extern f32 lbl_80562E3C;
extern f32 lbl_80562E40;
extern f32 lbl_80562E44;
extern f32 lbl_80562E48;
extern f32 lbl_80562E4C;
extern f32 fn_801E8874(void);
extern f32 fn_801E8894(s32);
extern int fn_802C974C(f32, f32, f32);
extern f32 lbl_80562E58;
extern f32 lbl_80562E5C;
extern u8 lbl_8055EB59;
extern u8 lbl_8055EB60[5];
extern char lbl_8055EB58;

#pragma dont_inline on
/* Convert the stored field-of-view angle (lbl_80562E38, 61.5 degrees) to radians and cache it in lbl_8055AF68 for the camera projection setup. */
void fn_801EA1FC(void) {
    float angleRadians = lbl_80562E38;
    angleRadians = lbl_80562E3C * angleRadians;
    lbl_8055AF68 = angleRadians;
}

#pragma dont_inline on
void fn_801EA28C(s32 playerIndex, f32 fov) {
    #pragma scheduling invalid_target
    /* Refresh the projection/view parameters from the player's stored near/far
     * planes (config +0x4C/+0x50) and the supplied FOV value. */
    f32 nearPlane = fn_801E8874();
    f32 farPlane = fn_801E8894(playerIndex);
    fn_802C974C(nearPlane, farPlane, fov);
}
#pragma dont_inline off

#pragma dont_inline reset
/* Recompute the derived scale, then refresh the projection/FOV view parameters with the fixed near/far/fov constants. */
void fn_801EA2E8(void) {
    fn_801EA1FC();
    fn_802C974C(lbl_80562E40, lbl_80562E48, lbl_80562E4C);
}
void fn_801EA318(void) {

}

extern s32 fn_80012954(s32);
extern void fn_8026A54C(f32);
extern f32 lbl_80562E50, lbl_80562E54;
#pragma push
#pragma processor 750
#pragma scheduling on
void fn_801EA31C(s32 *arg0) {
    f32 initial = lbl_80562E50;
    f32 f1, f2, f3;
    s32 result;
    *(f32 *)lbl_8055EB60 = initial;
    fn_8026A54C(initial);
    result = (unsigned int)__cntlzw(fn_80012954(*arg0) - 2) >> 5;
    f1 = lbl_80562E40;
    f2 = *(f32 *)lbl_8055EB60;
    f3 = lbl_80562E54;
    ((signed char *)lbl_8055EB60)[4] = (signed char)result;
    fn_802C974C(f1, f2, f3);
    lbl_8055EB58 = 0;
    lbl_8055EB59 = 1;
}
#pragma pop
void fn_801EA38C(void) {
    fn_801EBC2C();
}

void fn_801EA390(void) {
    fn_801EBC70();
}

void fn_801EA394(void) {
    /* Set the UI fill color: opaque black when the flag at lbl_8055EB60+4 is set, otherwise opaque light lavender (0xFFC9C9EA). */
    if (lbl_8055EB60[4] != 0)
        fn_802C86E8(0xFF000000);
    else
        fn_802C86E8(0xFFC9C9EA);
}

void fn_801EA3B8(void) {
    /* Set a UI draw color/alpha and scale, and clear the active flag. */
#define uiScaleZero lbl_80562E58
#define uiScaleDefault lbl_80562E5C
#define uiActive lbl_8055EB59
    fn_802C990C(0xC9C9EB);
    fn_802C86E8(0xFF000000);
    fn_802C2B78(uiScaleZero, uiScaleDefault, uiScaleZero);
    uiActive = 0;
#undef uiScaleZero
#undef uiScaleDefault
#undef uiActive
}

void fn_801EA400(void) {
    fn_801EBCAC();
}

void fn_801EA404(s32 arg0, s32 arg1) {
    /* Save the current entity's progress, reset/update scene state, then
       restore progress and advance the scene with the given parameter. */
    f32 savedProgress = fn_801E8738(-1);
    fn_801EA210(-1);
    fn_801FC904();
    fn_801EA28C(-1, savedProgress);
    fn_801EBF00();
    fn_801EA210(-1, savedProgress);
    fn_801FC908(arg1);
}

char fn_801EA470(void) {
    /* Returns the camera/scene mode flag byte lbl_8055EB58. When set, callers
     * pick the fixed projection constants and scene context [2] instead of the
     * player-driven FOV and scene context [1]; cleared by fn_801EA31C when the
     * view is reinitialized. */
    return lbl_8055EB58;
}

void fn_801EA478(s32 playerIndex) {
    /* Reads this player's current progress value (left in f1) and updates the scene state with it. */
    fn_801E8738(playerIndex);
    fn_801EA210(playerIndex);
}

