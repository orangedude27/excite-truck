// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int size_t;

// The one progress/loading message the game shows (its own name string is
// "ProgressUpdate", lbl_802FC600). fn_80012478/fn_80012628 clear it,
// fn_800124DC starts one, fn_8001255C advances it and fn_800125D4 drops it.
typedef struct {
    unsigned char active;     // +0x00: a message is set
    char message[0x80];       // +0x01: text, strncpy'd 0x7f chars with the last byte forced to NUL
    float progress;           // +0x84: accumulated progress (fn_8001255C adds to it)
    float target;             // +0x88: value the message was started with
    unsigned int startTime;   // +0x8C: ms (KERNEL_GetTimeMs) when the message was started
    unsigned int elapsed;     // +0x90: ms between the last update and startTime
} ProgressMessage;
extern char lbl_80351790[];   // the ProgressMessage record
extern char lbl_802FC600[];
extern float lbl_80560350;
extern float lbl_8056034C;
extern char lbl_8055D4EC;
extern char *strncpy(char *, const char *, size_t);
extern void *memset(void *, int, size_t);
extern int KERNEL_GetTimeMs(void);
      void fn_8001255C(const char *, float);
extern float lbl_80560348;
extern int screenWidthPx;
extern int screenHeightPx;
extern void fn_802C92D0(void);
extern void fn_802C92D8(void);
extern void fn_802C92DC(int, int, int, int, int);
extern void fn_80235380(void *);
extern void fn_80128668(void *);
#pragma scheduling invalid_target
/* Destructor-like cleanup: release the owned resource at offset 0x50, clear it, and optionally free the object when arg1 > 0. */
void *fn_80012384(void *object, int shouldFree) {
    if (object != 0) {
        void *resource = *(void **)((char *)object + 0x50);
        if (resource != 0) {
            fn_80235380(resource);
        }
        *(void **)((char *)object + 0x50) = 0;
        if (shouldFree > 0) fn_80128668(object);
    }
    return object;
}
#pragma push
#pragma processor 750
void fn_800123EC(float arg0) {
    float f;
    int value;
    int color;
    fn_802C92D0();
    f = lbl_80560348 * arg0;
    value = (int)f;
    color = 0;
    if (value > 0)
        color = (int)f;
    color = (color >= 0xff ? 0xff : color);
    fn_802C92DC(-0x14, -0x14, screenWidthPx + 0x14, screenHeightPx + 0x14, color << 24);
    fn_802C92D8();
}
#pragma pop

#pragma push
#pragma scheduling on
/* Reset the progress/update state block (lbl_80351790) to defaults and mark it active. */
void fn_80012478(void) {
    register char *progressState = lbl_80351790;
    register int zero = 0;
    progressState[0] = zero;
    memset(progressState + 1, zero, 0x80);
    *(int *)(progressState + 0x8c) = zero;
    *(float *)(progressState + 0x88) = lbl_8056034C;
    *(float *)(progressState + 0x84) = lbl_8056034C;
    lbl_8055D4EC = 1;
}

extern char lbl_80558AD0;
#pragma push
#pragma processor 750
/* Start a progress message: copy its text into the ProgressMessage record, reset its
 * accumulated progress, stamp the start time and mark it pending (lbl_80558AD0 = 1). */
void fn_800124DC(const char *text, float target) {
    register char *record = lbl_80351790;
    register int one = 1;
    register int zero = 0;
    lbl_80558AD0 = one;
    strncpy(record + 1, text, 0x7f);
    record[0x80] = zero;
    ((ProgressMessage *)record)->target = target;
    ((ProgressMessage *)record)->progress = lbl_8056034C;
    ((ProgressMessage *)record)->startTime = KERNEL_GetTimeMs();
    record[0] = one;
}
#pragma pop

#pragma push
#pragma processor 750
void fn_8001255C(const char *arg0, float farg0) {
    /* Update the progress message text and accumulated progress, and record time since it started. */
    register char *p = lbl_80351790;
    float f = *(float *)(p + 0x84) + farg0;
    strncpy(p + 1, arg0, 0x7f);
    *(float *)(p + 0x84) = f;
    p[0x80] = 0;
    *(int *)(p + 0x90) = KERNEL_GetTimeMs() - *(int *)(p + 0x8c);
}
#pragma pop

/* Advance the progress message: set its text to "ProgressUpdate" (lbl_802FC600)
   and add 100.0f (lbl_80560350) to its accumulated progress. */
void fn_800125C4(void) {
    ((void(*)(const char *, float))fn_8001255C)(lbl_802FC600, lbl_80560350);
}

/* Clear the active progress message and replace its text. */
void fn_800125D4(const char *message) {
    register char *dst = lbl_80351790 + 1;
    strncpy(dst, message, 0x7f);
    lbl_80351790[0x80] = 0;
    lbl_80351790[0] = 0;
}

extern void fn_800123EC(float);
/* Tail-call thunk: forwards the per-frame fade fraction (arriving in f1) straight to
 * the fade renderer (fn_800123EC), which clamps 255*opacity into an alpha and draws a
 * screen-filling quad. The void-function cast avoids argument setup so the call emits
 * a bare tail branch instead of a call/return pair. */
void fn_80012624(void) {
    ((void(*)(void))fn_800123EC)();
}

#pragma push
#pragma scheduling on
void fn_80012628(void) {
    /* Reset the progress state block to defaults and mark it inactive. */
    register char *progressState = lbl_80351790;
    register int zero = 0;
    progressState[0] = zero;
    memset(progressState + 1, zero, 0x80);
    *(int *)(progressState + 0x8c) = zero;
    *(float *)(progressState + 0x88) = lbl_8056034C;
    *(float *)(progressState + 0x84) = lbl_8056034C;
    lbl_8055D4EC = zero;
}
#pragma pop
