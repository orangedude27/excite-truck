// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern f32 fn_801E8738(s32);
extern void fn_801FC904(void);
extern void drawWeatherLayer(void);
extern void fn_801FC908(s32);
extern void setModelColor(s32);
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
    f32 angleRadians = lbl_80562E38;
    angleRadians = lbl_80562E3C * angleRadians;
    lbl_8055AF68 = angleRadians;
}

#pragma processor 750
void fn_801EA210(s32 playerIndex, f32 fov) {
    #pragma scheduling invalid_target
    /* Refresh the projection/view parameters: when the camera/scene mode flag is
     * clear, use this player's stored near/far planes and the supplied FOV; when
     * set, fall back to the fixed near/far constants and the cached FOV. */
    f32 nearPlane;
    if ((u8)lbl_8055EB58 == 0) {
        nearPlane = fn_801E8874();
        fn_802C974C(nearPlane, fn_801E8894(playerIndex), fov);
        return;
    }
    fn_802C974C(lbl_80562E40, lbl_80562E44, lbl_8055AF68);
}
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
    /* Empty stub (returns immediately). */
}

extern s32 fn_80012954(s32);
extern void fn_8026A54C(f32);
extern f32 lbl_80562E54;
#pragma push
#pragma processor 750
#pragma scheduling on
void fn_801EA31C(s32 *idPtr) {
    /* Initialize the EB scene context when the view is reset: store the default
     * 2250.0 scale, derive a mode flag from the event-id query, configure the
     * projection (near/far/fov) and set the camera-mode/active flags. */
    f32 defaultScale = 2250.0f;
    f32 nearPlane, farPlane, fovAngle;
    s32 modeFlag;
    *(f32 *)lbl_8055EB60 = defaultScale;
    fn_8026A54C(defaultScale);
    modeFlag = (unsigned int)__cntlzw(fn_80012954(*idPtr) - 2) >> 5;
    nearPlane = lbl_80562E40;
    farPlane = *(f32 *)lbl_8055EB60;
    fovAngle = lbl_80562E54;
    ((signed char *)lbl_8055EB60)[4] = (signed char)modeFlag;
    fn_802C974C(nearPlane, farPlane, fovAngle);
    lbl_8055EB58 = 0;
    lbl_8055EB59 = 1;
}
#pragma pop
/* Prepare the EB context subordinate resource lists, or run the fallback cleanup. */
void fn_801EA38C(void) {
    fn_801EBC2C();
}

void fn_801EA390(void) {
    /* Tail-call thunk that clears the EB context material lists. */
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
    setModelColor(0xC9C9EB);
    fn_802C86E8(0xFF000000);
    fn_802C2B78(uiScaleZero, uiScaleDefault, uiScaleZero);
    uiActive = 0;
#undef uiScaleZero
#undef uiScaleDefault
#undef uiActive
}

/* Thunk: update all active scene objects in the context. */
void fn_801EA400(void) {
    fn_801EBCAC();
}

void fn_801EA404(s32 arg0, s32 arg1) {
    /* Save the current entity's progress, reset/update scene state, then
       restore progress and advance the scene with the given parameter. */
    f32 savedProgress = fn_801E8738(-1);
    fn_801EA210(-1, savedProgress);
    fn_801FC904();
    fn_801EA28C(-1, savedProgress);
    drawWeatherLayer();
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
    f32 progress = fn_801E8738(playerIndex);
    fn_801EA210(playerIndex, progress);
}

