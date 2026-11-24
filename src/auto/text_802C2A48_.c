// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055CFF0, lbl_8055CFF4, lbl_8055FB98, lbl_8055FB9C, lbl_8055FBA0, lbl_8055FBA4;
extern unsigned char lbl_8055CFF8;
extern float lbl_80564ED8;
extern float lbl_80564EDC;
extern unsigned char lbl_8055FBA8;
void *Vid_GetVideoModeInfo(int);
void fn_802C2A48(int);
void fn_802CF5F8(int);
void fn_802CA0E4(void);
void fn_801E2F00(void);
void fn_802C83CC(void);
void fn_802C990C(int);
unsigned char fn_802C2C00(int);
void fn_801E6978(void);

/* View scale range state block: +0 start (f32), +4 end (f32), +8 steps/rate (f32), +0xC scroll enabled (u8). */
extern unsigned char lbl_804C1328[];
void fn_802C2B78(float, float, float);
#pragma dont_inline on
void fn_802C2A48(int videoModeId) {
    /* Cache the selected video mode's dimensions/format and set the default viewport size. */
    unsigned int *videoMode;
    lbl_8055FBA4 = videoModeId;
    videoMode = Vid_GetVideoModeInfo(videoModeId);
    lbl_8055CFF0 = videoMode[0];
    lbl_8055CFF4 = videoMode[1];
    lbl_8055CFF8 = *(unsigned char *)(videoMode + 3);
    lbl_8055FB98 = (videoMode[2] >> 3) * videoMode[0];
    lbl_8055FB9C = 0x280;
    lbl_8055FBA0 = 0x1E0;
}
#pragma dont_inline reset

void fn_802C2AA8(void) {
#define MenuVideoSelectMode fn_802C2A48
#define GetVideoModeInfo Vid_GetVideoModeInfo
#define SetVideoParam fn_802CF5F8
#define InitTextureState fn_802CA0E4
#define gMenuSceneFlag lbl_8055FBA8
#define InitSomeStateA fn_801E2F00
#define InitSomeStateB fn_802C83CC
#define SetDrawColor fn_802C990C
#define SetViewFloats fn_802C2B78
#define gZeroFloat lbl_80564ED8
#define gOneFloat lbl_80564EDC
#define SetViewEnable fn_802C2C00
#define FinalizeSceneInit fn_801E6978
    /* Initialize menu/scene video mode 2 and reset related render/state flags. */
    MenuVideoSelectMode(2);
    SetVideoParam(*(int *)((char *)GetVideoModeInfo(2) + 0x10));
    InitTextureState();
    gMenuSceneFlag = 0;
    InitSomeStateA();
    InitSomeStateB();
    SetDrawColor(0xFF00FF00);
    SetViewFloats(gZeroFloat, gOneFloat, gZeroFloat);
    SetViewEnable(1);
    FinalizeSceneInit();
#undef MenuVideoSelectMode
#undef GetVideoModeInfo
#undef SetVideoParam
#undef InitTextureState
#undef gMenuSceneFlag
#undef InitSomeStateA
#undef InitSomeStateB
#undef SetDrawColor
#undef SetViewFloats
#undef gZeroFloat
#undef gOneFloat
#undef SetViewEnable
#undef FinalizeSceneInit
}

/* Tears down the animation streaming buffers, drawlists, joint pool and texture
 * system during global shutdown (paired with the init sequence in fn_802C2AA8). */
void fn_802C2B18(void) {
    fn_801E69EC();
    fn_802C84EC();
    fn_801E2F68();
    fn_802CA1E0();
    fn_802CF5FC();
}

void HomeMenu_endFrame(void);
void fn_80127468(void);
void fn_801279B8(void);
void fn_802E4C18(int);
void fn_802C2B48(void) {
#define ResetGxState HomeMenu_endFrame
#define ResumeWaitingThread fn_80127468
#define TickFrameCounter fn_801279B8
#define VmemHook fn_802E4C18
    /* End-of-frame flush: reset GX globals, wake a waiting thread, tick the
     * wraparound counter, then run the vmem hook. */
    ResetGxState();
    ResumeWaitingThread();
    TickFrameCounter();
    VmemHook(0);
#undef ResetGxState
#undef ResumeWaitingThread
#undef TickFrameCounter
#undef VmemHook
}

void fn_802C2B78(float startValue, float endValue, float steps) {
#define gViewScaleRange lbl_804C1328
#define gZeroFloat lbl_80564ED8
#define SetupFloatInterpolation fn_802D0014
    /* Stores the view scale range (start, end, steps) and starts interpolating from start to end over that many steps when range scrolling is enabled, otherwise snapping straight to end. */
    float delta;
    double stepsDouble;
    *(float *)gViewScaleRange = startValue;
    *(float *)(gViewScaleRange + 4) = endValue;
    *(float *)(gViewScaleRange + 8) = steps;
    if (gViewScaleRange[0xC] != 0) {
        stepsDouble = steps;
        delta = stepsDouble;
    } else {
        delta = gZeroFloat;
    }
    SetupFloatInterpolation(*(float *)gViewScaleRange, *(float *)(gViewScaleRange + 4), delta);
#undef SetupFloatInterpolation
#undef gZeroFloat
#undef gViewScaleRange
}

/* Gets the stored view scale range values (start, end, rate). */
void fn_802C2BB8(float *outStart, float *outEnd, float *outRate) {
    if (outStart != 0) {
        *outStart = *(float *)lbl_804C1328;
    }
    if (outEnd != 0) {
        *outEnd = *(float *)(lbl_804C1328 + 4);
    }
    if (outRate != 0) {
        *outRate = *(float *)(lbl_804C1328 + 8);
    }
}

/* Sets the stored view-range enabled flag and reapplies the current range values, returning the previous flag. */
unsigned char fn_802C2C00(int enableFlag) {
    unsigned char previousFlag = lbl_804C1328[0xC];
    float zValue;
    lbl_804C1328[0xC] = enableFlag;
    if ((enableFlag & 0xFF) != 0) {
        zValue = *(float *)(lbl_804C1328 + 8);
    } else {
        zValue = lbl_80564ED8;
    }
    fn_802D0014(*(float *)lbl_804C1328, *(float *)(lbl_804C1328 + 4), zValue);
    return previousFlag;
}

void fn_802DD63C(void);
void fn_802DD738(void);
void fn_802DD750(void);
void fn_802DE774(void);
/* Thunk: initialize the split-screen view-region coefficient table for the
 * given region/player count (fn_802DD63C). */
void fn_802C2C60(void) { fn_802DD63C(); }

/* Tail-call wrapper: forwards the region index (r3) and float value (f1) left
   by the caller to fn_802DD738, which stores it in the texture-copy cache
   table at lbl_804DB6A0. */
void fn_802C2C64(void) { fn_802DD738(); }

/* No-op tail-call wrapper: forwards to the empty fn_802DD750, so the arguments
   callers pass are ignored and nothing is changed. */
void fn_802C2C68(void) { fn_802DD750(); }

/* Thunk: reset the split-screen view-region table by clearing its entry count
 * (fn_802DE774). */
void fn_802C2C6C(void) { fn_802DE774(); }
