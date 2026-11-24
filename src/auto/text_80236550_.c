// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F0A0;
extern char lbl_8055BA00;
extern int lbl_8055F094;
extern int lbl_8055F09C;
extern float lbl_805636D0;
extern double lbl_805636D8;
extern char lbl_803408D8[];
int KERNEL_GetTimeMs(void);
void fn_80236674(void);
void fn_802E30C8(const char *, ...);
void fn_802365D8(void);
#pragma dont_inline on
#pragma scheduling invalid_target
/* Warn and auto-reset the game timer once its millisecond clock (current sample minus accumulated base) exceeds 1e7, before gTime's float representation loses precision. */ void CheckGTimeFloatPrecision(void) {
    if (lbl_8055F09C - lbl_8055F094 > 0x989680) {
        fn_802E30C8(lbl_803408D8);
        fn_802365D8();
    }
}
#pragma scheduling on

#pragma dont_inline off
float fn_8023659C(void) {
#define timeBase lbl_8055F094
#define pauseTime lbl_8055F09C
#define msPerSecond lbl_805636D0
    /* Return the accumulated active time in seconds; the timer counts milliseconds. */
    return (float)(pauseTime - timeBase) / msPerSecond;
#undef timeBase
#undef pauseTime
#undef msPerSecond
}

/* Timer auto-reset: rebase the accumulated time base to the current millisecond
 * count and refresh timing state (called when float precision is running out). */
void fn_802365D8(void) {
#define GetCurrentTimeMs KERNEL_GetTimeMs
#define timeBase lbl_8055F094
#define UpdateTimerState fn_80236674
    timeBase = GetCurrentTimeMs();
    UpdateTimerState();
#undef GetCurrentTimeMs
#undef timeBase
#undef UpdateTimerState
}

/* Pause the timer: set the paused flag so elapsed time stops accumulating. */
void fn_80236600(void) {
#define timerPausedFlag lbl_8055F0A0
    timerPausedFlag = 1;
#undef timerPausedFlag
}

/* Unpause/update the timer accumulator: when the paused flag is set, fold elapsed time since pause into the base and clamp it above 1, then refresh timing state. */
void fn_8023660C(void) {
#define timerActiveFlag lbl_8055BA00
#define timerPausedFlag lbl_8055F0A0
#define timeBase lbl_8055F094
#define pauseTime lbl_8055F09C
#define GetCurrentTimeMs KERNEL_GetTimeMs
#define UpdateTimerState fn_80236674
    int adjustedTime;

    timerActiveFlag = 0;
    if (timerPausedFlag != 0) {
        adjustedTime = 1;
        adjustedTime = GetCurrentTimeMs() - pauseTime;
        adjustedTime += timeBase;
        adjustedTime -= 0x10;
        if (adjustedTime > 1) timeBase = adjustedTime; else timeBase = 1;
        timerPausedFlag = 0;
    }
    UpdateTimerState();
#undef timerActiveFlag
#undef timerPausedFlag
#undef timeBase
#undef pauseTime
#undef GetCurrentTimeMs
#undef UpdateTimerState
}

int fn_802ECC10(void);
void CheckGTimeFloatPrecision(void);
extern int lbl_8055F094, lbl_8055F098, lbl_8055F09C;
/* Updates timer state while unpaused: clamps overflow, samples current time,
 * advances the base by elapsed time when timing is active, and stores the sample. */
void fn_80236674(void) {
    int currentTime;

    if (lbl_8055F0A0 == 0) {
        CheckGTimeFloatPrecision();
        currentTime = KERNEL_GetTimeMs();
        if (fn_802ECC10() != 0) {
            lbl_8055F094 += currentTime - lbl_8055F09C;
        }
        lbl_8055F098 = currentTime;
        lbl_8055F09C = currentTime;
    }
}

