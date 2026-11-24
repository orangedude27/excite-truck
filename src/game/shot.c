// shot — screenshot capture ("shot%02d.tga").
// Symbol guide (the project cannot rename game symbols yet): initShotHooks
// (fn_802E46AC), initShot (fn_802E46B0), invalidateSavedState (fn_802E46E4),
// checkScreenshotHotkey (fn_802E46F0), anyInputPending (fn_802E47B8),
// clearKeyHistory (fn_802E47E8), recordInput (fn_802E4800), matchKeySequence
// (MatchKeySequence), inputNibble (fn_802E4A10), keyPressed (fn_802E4A1C),
// pollInput (fn_802E4A2C), restoreSavedState (fn_802E4A60).
// Recovered TU window 0x802E46AC..0x802E4C0C (see docs/attribution_analysis.md).
// Static-init thunk fn_802E4C0C (+ .ctors slot 0x802ED5FC) remains in
// auto/text_802E4C0C_.c pending a promotion pass.
#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055D1C0;
extern u16 lbl_8055FF50;
void fn_802E4A2C(void);
extern s32 lbl_8055FF5C;
extern u16 lbl_8055FF5A;
extern u16 lbl_804FC418[];
extern s32 fn_802ECC10(void);
extern s32 fn_802E2C20(void);
extern void fn_802E47E8(void);
#pragma dont_inline on
/* No-op screenshot subsystem init hook, called once at boot by fn_802E46B0. */
void fn_802E46AC(void) {}
#pragma dont_inline off

#pragma dont_inline on
#pragma dont_inline off
void fn_802E46B0(void) {
    /* Boot-time init of the screenshot/key-history subsystem: reset the last-input
       timestamp, clear the recent-key history, invalidate the saved-state pointer
       (a negative value means "no state captured"), then run the init hook. */
    lbl_8055FF5C = 0;
    fn_802E47E8();
    lbl_8055D1C0 = (void *)-1;
    fn_802E46AC();
}
void fn_802E46E4(void) {
    /* Invalidate the saved-state pointer (a negative value means "no state captured"). */
#define gSavedStatePtr lbl_8055D1C0
    gSavedStatePtr = (void*)-1;
#undef gSavedStatePtr
}

extern int sprintf(char *, const char *, ...);
extern void fn_802D07E4(char *, s32);
extern u16 lbl_8055FF60;
extern u32 lbl_8055FF64;
extern const char lbl_8034D1C0[];
#pragma scheduling invalid_target
s32 fn_802E46F0(void) {
    /* Screenshot hotkey check: shift the recent-input history, and when the
       current combo (0x17A/0x17B) follows 0x112, save a numbered "shotNN.tga". */
#define s_keyHistory    lbl_8055FF50
#define lastInputWord   lbl_8055FF5A
#define previousCombo   lbl_8055FF60
#define screenshotCount lbl_8055FF64
#define shotNameFormat  lbl_8034D1C0
    u16 input;
    u32 code;
    u32 combo;
    char fileName[0x20];
    volatile u16 *history;
    u16 next1, next2, next3;
    fn_802E4A2C();
    input = s_keyHistory;
    code = (u32)input & 0xFFFF0FFF;
    lastInputWord = input;
    if (code != 0) {
        history = &s_keyHistory;
        next1 = history[1];
        next2 = history[2];
        next3 = history[3];
        history[0] = next1;
        history[1] = next2;
        history[2] = next3;
        history[3] = 0;
    }
    combo = (u16)code;
    if (combo == 0x17A) goto check;
    if (combo != 0x17B) goto done;
check:
    if (previousCombo != 0x112) goto done;
    sprintf(fileName, shotNameFormat, screenshotCount);
    fn_802D07E4(fileName, combo == 0x17B);
    combo = 0;
    screenshotCount++;
done:
    if (combo != 0) previousCombo = combo;
    return combo;
#undef s_keyHistory
#undef lastInputWord
#undef previousCombo
#undef screenshotCount
#undef shotNameFormat
}
void* memset(void*, int, unsigned long);
s32 fn_802E47B8(void) {
    /* Poll the screenshot input state, then report whether the current input
     * combo (lbl_8055FF50) is nonzero. */
    fn_802E4A2C();
    return lbl_8055FF50 != 0;
}

/* Clear the four-entry (8-byte) recent-key history used for screenshot combos. */
void fn_802E47E8(void) {
#define s_keyHistory lbl_8055FF50
    memset(&s_keyHistory, 0, 8);
#undef s_keyHistory
}

s32 fn_802E47F8(void) {
    /* Screenshot/key-history subsystem stub: always reports 0. */
    return 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_802E4800(u16 inputWord) {
    // Record one input word into the screenshot key-history subsystem (skipped while the
    // Wii Home menu is open): refresh the last-input timestamp, shift the 32-entry
    // 12-bit input history and append the key code, then store the full word in the
    // four-entry recent-key ring (first empty slot, else rotate the oldest out).
#define s_keyHistory lbl_8055FF50
#define inputHistoryBuffer lbl_804FC418
#define lastInputTime lbl_8055FF5C
    volatile u16 *recentKeys;
    u32 idx;
    u16 slot1, slot2, slot3;

    if (fn_802ECC10() != 0) {
        return;
    }
    lastInputTime = fn_802E2C20();
    for (idx = 0; idx < 31; idx++) {
        inputHistoryBuffer[idx] = inputHistoryBuffer[idx + 1];
    }
    inputHistoryBuffer[31] = inputWord & 0xFFF;

    for (idx = 0; idx < 4; idx++) {
        if ((&s_keyHistory)[idx] == 0) {
            (&s_keyHistory)[idx] = inputWord;
            return;
        }
    }
    recentKeys = &s_keyHistory;
    slot1 = recentKeys[1];
    slot2 = recentKeys[2];
    slot3 = recentKeys[3];
    recentKeys[0] = slot1;
    recentKeys[1] = slot2;
    recentKeys[2] = slot3;
    recentKeys[3] = inputWord;
#undef s_keyHistory
#undef inputHistoryBuffer
#undef lastInputTime
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
/* Return 1 when `sequence` (0-terminated, 0xFFFF entries are wildcards) matches the
 * tail of the 32-entry input history, 0 otherwise. */
s32 MatchKeySequence(u16 *sequence) {
#define inputHistoryBuffer lbl_804FC418
    s32 length;
    u16 *scan;
    u16 *history;
    u16 sequenceValue;
    u16 historyValue;
    length = 0;
    scan = sequence;
    while (*scan != 0) { length++; scan++; }
    history = inputHistoryBuffer + (0x20 - length);
    while (length > 0) {
        sequenceValue = *sequence;
        historyValue = *history;
        if (historyValue != sequenceValue && sequenceValue != 0xFFFF) return 0;
        sequence++;
        history++;
        length--;
    }
    return 1;
#undef inputHistoryBuffer
}
#pragma pop
/* Return the high nibble (bits 12-15) of the cached current-input word. */
s32 fn_802E4A10(void) { return (lbl_8055FF5A >> 12) & 0xF; }

extern u8 lbl_804FC458[];
u8 fn_802E4A1C(s32 keyCode) {
    /* Current pressed state of keyboard scan code keyCode (256-entry key-state table). */
#define gKeyStateTable lbl_804FC458
    return gKeyStateTable[keyCode];
#undef gKeyStateTable
}

void fn_802E4A2C(void) {
    /* When a saved state exists, zero a 64-word stack scratch area (the clearing
       itself is the only effect of this routine). */
#define gSavedStatePtr lbl_8055D1C0
    if ((s32)gSavedStatePtr >= 0) {
        u32 scratch[64] = {0};
    }
#undef gSavedStatePtr
}

extern unsigned char lbl_8055FF58;
extern unsigned char lbl_804FC3B0[];
/* Restores a saved 0x61-byte input/telemetry snapshot into out when one is available:
 * copies the record from the saved-state buffer and returns 1, or returns 0 if none is saved. */
int fn_802E4A60(void *out) {
#define hasSavedState lbl_8055FF58
#define savedStateBuffer lbl_804FC3B0
    unsigned char *dst = (unsigned char *)out;
    if (hasSavedState != 0) {
        volatile unsigned char *src = savedStateBuffer;
        unsigned char firstByte, secondByte;
        unsigned int word0, word1;

        *(float *)(dst + 0x00) = *(float *)(src + 0x00);
        *(float *)(dst + 0x04) = *(float *)(src + 0x04);
        *(float *)(dst + 0x08) = *(float *)(src + 0x08);
        *(float *)(dst + 0x0C) = *(float *)(src + 0x0C);
        *(float *)(dst + 0x10) = *(float *)(src + 0x10);
        *(float *)(dst + 0x14) = *(float *)(src + 0x14);
        *(float *)(dst + 0x18) = *(float *)(src + 0x18);
        *(float *)(dst + 0x1C) = *(float *)(src + 0x1C);
#define COPY_PAIR(o) firstByte = src[(o)]; secondByte = src[(o) + 1]; dst[(o)] = firstByte; dst[(o) + 1] = secondByte
        COPY_PAIR(0x20);
        COPY_PAIR(0x22);
        COPY_PAIR(0x24);
        COPY_PAIR(0x26);
        COPY_PAIR(0x28);
        COPY_PAIR(0x2A);
        COPY_PAIR(0x2C);
        COPY_PAIR(0x2E);
        COPY_PAIR(0x30);
        COPY_PAIR(0x32);
        COPY_PAIR(0x34);
        COPY_PAIR(0x36);
        COPY_PAIR(0x38);
        COPY_PAIR(0x3A);
        COPY_PAIR(0x3C);
        COPY_PAIR(0x3E);
#undef COPY_PAIR
        *(unsigned int *)(dst + 0x40) = *(unsigned int *)(src + 0x40);
        word1 = *(volatile unsigned int *)(src + 0x44);
        word0 = *(volatile unsigned int *)(src + 0x48);
        *(unsigned int *)(dst + 0x44) = word1;
        *(unsigned int *)(dst + 0x48) = word0;
        word0 = *(volatile unsigned int *)(src + 0x4C);
        word1 = *(volatile unsigned int *)(src + 0x50);
        *(unsigned int *)(dst + 0x4C) = word0;
        *(unsigned int *)(dst + 0x50) = word1;
        word0 = *(volatile unsigned int *)(src + 0x54);
        word1 = *(volatile unsigned int *)(src + 0x58);
        *(unsigned int *)(dst + 0x54) = word0;
        *(unsigned int *)(dst + 0x58) = word1;
        *(unsigned int *)(dst + 0x5C) = *(unsigned int *)(src + 0x5C);
        dst[0x60] = src[0x60];
        return 1;
    }
    return 0;
#undef hasSavedState
#undef savedStateBuffer
}

