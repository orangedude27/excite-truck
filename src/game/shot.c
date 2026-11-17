// shot — screenshot capture ("shot%02d.tga").
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
typedef struct { volatile u16 *ptr; s32 idx; } QueueScan;
#pragma dont_inline on
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
    u16 input;
    u32 code;
    u32 combo;
    char fileName[0x20];
    volatile u16 *history;
    u16 next1, next2, next3;
    fn_802E4A2C();
    input = lbl_8055FF50;
    code = (u32)input & 0xFFFF0FFF;
    lbl_8055FF5A = input;
    if (code != 0) {
        history = &lbl_8055FF50;
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
    if (lbl_8055FF60 != 0x112) goto done;
    sprintf(fileName, lbl_8034D1C0, lbl_8055FF64);
    fn_802D07E4(fileName, combo == 0x17B);
    combo = 0;
    lbl_8055FF64++;
done:
    if (combo != 0) lbl_8055FF60 = combo;
    return combo;
}
void* memset(void*, int, unsigned long);
extern u16 lbl_8055FF50;
void fn_802E4A2C(void); /* extern */
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
    return 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_802E4800(u16 arg0) {
    u16 *history;
    volatile u16 *p;
    s32 i;
    u16 a, b, c;

    if (fn_802ECC10() != 0) {
        return;
    }
    lbl_8055FF5C = fn_802E2C20();
    history = lbl_804FC418;
    p = &lbl_8055FF50;
    for (i = 0; i < 31; i++) {
        history[i] = history[i + 1];
    }
    history[31] = arg0 & 0xFFF;

    for (i = 0; (unsigned short)i < 4; i++) {
        if (*p == 0) {
            ((volatile u16 *)&lbl_8055FF50)[i] = arg0;
            return;
        }
        p++;
    }
    p = &lbl_8055FF50;
    a = p[1];
    b = p[2];
    c = p[3];
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = arg0;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
/* Check whether a 16-bit key sequence matches the end of the 32-entry input history (right-aligned by sequence length); 0xFFFF entries in the sequence act as wildcards. */
s32 fn_802E499C(u16 *sequence) {
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
    volatile u32 stack[65];
    volatile u32 *p;
    if ((s32)lbl_8055D1C0 < 0) return;
    p = &stack[1];
    do {
        *p = 0;
        p[1] = 0;
        p += 2;
    } while (p < &stack[65]);
}

extern unsigned char lbl_8055FF58;
extern unsigned char lbl_804FC3B0[];
/* Copies the saved state from lbl_804FC3B0 into dst when lbl_8055FF58 is set; returns 1 on copy, 0 otherwise. */
int fn_802E4A60(void *arg0) {
    unsigned char *dst = (unsigned char *)arg0;
    if (lbl_8055FF58 != 0) {
        volatile unsigned char *src = lbl_804FC3B0;
        unsigned char a, b;
        unsigned int wordA, wordB;

        *(float *)(dst + 0x00) = *(float *)(src + 0x00);
        *(float *)(dst + 0x04) = *(float *)(src + 0x04);
        *(float *)(dst + 0x08) = *(float *)(src + 0x08);
        *(float *)(dst + 0x0C) = *(float *)(src + 0x0C);
        *(float *)(dst + 0x10) = *(float *)(src + 0x10);
        *(float *)(dst + 0x14) = *(float *)(src + 0x14);
        *(float *)(dst + 0x18) = *(float *)(src + 0x18);
        *(float *)(dst + 0x1C) = *(float *)(src + 0x1C);
#define COPY_PAIR(o) b = src[(o)]; a = src[(o) + 1]; dst[(o)] = b; dst[(o) + 1] = a
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
        wordB = *(volatile unsigned int *)(src + 0x44);
        wordA = *(volatile unsigned int *)(src + 0x48);
        *(unsigned int *)(dst + 0x44) = wordB;
        *(unsigned int *)(dst + 0x48) = wordA;
        wordA = *(volatile unsigned int *)(src + 0x4C);
        wordB = *(volatile unsigned int *)(src + 0x50);
        *(unsigned int *)(dst + 0x4C) = wordA;
        *(unsigned int *)(dst + 0x50) = wordB;
        wordA = *(volatile unsigned int *)(src + 0x54);
        wordB = *(volatile unsigned int *)(src + 0x58);
        *(unsigned int *)(dst + 0x54) = wordA;
        *(unsigned int *)(dst + 0x58) = wordB;
        *(unsigned int *)(dst + 0x5C) = *(unsigned int *)(src + 0x5C);
        dst[0x60] = src[0x60];
        return 1;
    }
    return 0;
}

