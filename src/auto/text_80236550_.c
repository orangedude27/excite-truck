// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F0A0;
extern char lbl_8055BA00;
extern int lbl_8055F094;
extern int lbl_8055F09C;
extern float lbl_805636D0;
extern double lbl_805636D8;
extern char lbl_803408D8[];
int fn_802E2C20(void);
void fn_80236674(void);
void fn_802E30C8(const char *, ...);
void fn_802365D8(void);
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_80236550(void) {
    if (lbl_8055F09C - lbl_8055F094 > 0x989680) {
        fn_802E30C8(lbl_803408D8);
        fn_802365D8();
    }
}
#pragma scheduling on

#pragma dont_inline off
float fn_8023659C(void) {
    return (float)(lbl_8055F09C - lbl_8055F094) / lbl_805636D0;
}

void fn_802365D8(void) {
    lbl_8055F094 = fn_802E2C20();
    fn_80236674();
}

void fn_80236600(void) {
    lbl_8055F0A0 = 1;
}

/* Unpause/update the timer accumulator: when the paused flag is set, fold elapsed time since pause into the base and clamp it above 1, then refresh timing state. */
void fn_8023660C(void) {
#define timerActiveFlag lbl_8055BA00
#define timerPausedFlag lbl_8055F0A0
#define timeBase lbl_8055F094
#define pauseTime lbl_8055F09C
#define GetCurrentTimeMs fn_802E2C20
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
void fn_80236550(void);
extern int lbl_8055F094, lbl_8055F098, lbl_8055F09C;
void fn_80236674(void) {
    int time;

    if (lbl_8055F0A0 == 0) {
        fn_80236550();
        time = fn_802E2C20();
        if (fn_802ECC10() != 0) {
            lbl_8055F094 += time - lbl_8055F09C;
        }
        lbl_8055F098 = time;
        lbl_8055F09C = time;
    }
}

